#include <ydb/library/yql/minikql/mkql_node.h>
#include <ydb/library/yql/minikql/mkql_node_cast.h>
#include <ydb/library/yql/minikql/mkql_program_builder.h>
#include <ydb/library/yql/minikql/mkql_function_registry.h>
#include <ydb/library/yql/minikql/computation/mkql_computation_node.h>
#include <ydb/library/yql/minikql/computation/mkql_computation_node_holders.h>
#include <ydb/library/yql/minikql/computation/mkql_computation_node_graph_saveload.h>
#include <ydb/library/yql/minikql/invoke_builtins/mkql_builtins.h>
#include <ydb/library/yql/minikql/comp_nodes/mkql_factories.h>

#include <library/cpp/testing/unittest/registar.h>

namespace NKikimr {
namespace NMiniKQL {

namespace {
    struct TInputItem {
        ui32 Key = 0;
        i64 Time = 0;
        ui32 Val = 0;
    };

    struct TOutputItem {
        ui32 Key = 0;
        ui32 Val = 0;
        ui64 Time = 0;

        constexpr bool operator==(const TOutputItem& rhs) const
        {
            return this->Key == rhs.Key && this->Val == rhs.Val && this->Time == rhs.Time;
        }
    };

    struct TOutputGroup {
        TOutputGroup(std::initializer_list<TOutputItem> items) : Items(items) {}

        std::vector<TOutputItem> Items;
    };

    std::vector<TOutputItem> Ordered(std::vector<TOutputItem> vec) {
        auto res = vec;
        std::sort(res.begin(), res.end(), [](auto l, auto r) {
            return std::make_tuple(l.Key, l.Val, l.Time) < std::make_tuple(r.Key, r.Val, r.Time);
        });
        return res;
    }

    IOutputStream &operator<<(IOutputStream &output, std::vector<TOutputItem> items) {
        output << "[";
        for (ui32 i = 0; i < items.size(); ++i) {
            output << "(" << items.at(i).Key << ";" << items.at(i).Val << ";" << items.at(i).Time << ")";
            if (i != items.size() - 1)
                output << ",";
        }
        output << "]";
        return output;
    }

    TIntrusivePtr<IRandomProvider> CreateRandomProvider() {
        return CreateDeterministicRandomProvider(1);
    }

    TIntrusivePtr<ITimeProvider> CreateTimeProvider() {
        return CreateDeterministicTimeProvider(10000000);
    }

    TComputationNodeFactory GetAuxCallableFactory() {
        return [](TCallable& callable, const TComputationNodeFactoryContext& ctx) -> IComputationNode* {
            if (callable.GetType()->GetName() == "MyStream") {
                return new TExternalComputationNode(ctx.Mutables);
            }

            return GetBuiltinFactory()(callable, ctx);
        };
    }

    struct TSetup {
        TSetup(TScopedAlloc& alloc)
            : Alloc(alloc)
        {
            FunctionRegistry = CreateFunctionRegistry(CreateBuiltinRegistry());
            RandomProvider = CreateRandomProvider();
            TimeProvider = CreateTimeProvider();

            Env.Reset(new TTypeEnvironment(Alloc));
            PgmBuilder.Reset(new TProgramBuilder(*Env, *FunctionRegistry));
        }

        THolder<IComputationGraph> BuildGraph(TRuntimeNode pgm, const std::vector<TNode*>& entryPoints = std::vector<TNode*>()) {
            Explorer.Walk(pgm.GetNode(), *Env);
            TComputationPatternOpts opts(Alloc.Ref(), *Env, GetAuxCallableFactory(),
                FunctionRegistry.Get(),
                NUdf::EValidateMode::None, NUdf::EValidatePolicy::Fail, "OFF", EGraphPerProcess::Multi);
            Pattern = MakeComputationPattern(Explorer, pgm, entryPoints, opts);
            TComputationOptsFull compOpts = opts.ToComputationOptions(*RandomProvider, *TimeProvider);
            return Pattern->Clone(compOpts);
        }

        TIntrusivePtr<IFunctionRegistry> FunctionRegistry;
        TIntrusivePtr<IRandomProvider> RandomProvider;
        TIntrusivePtr<ITimeProvider> TimeProvider;

        TScopedAlloc& Alloc;
        THolder<TTypeEnvironment> Env;
        THolder<TProgramBuilder> PgmBuilder;

        TExploringNodeVisitor Explorer;
        IComputationPattern::TPtr Pattern;
    };

    struct TStream : public NUdf::TBoxedValue {
        TStream(const TUnboxedValueVector& items, std::function<void()> fetchCallback)
            : Items(items)
            , FetchCallback(fetchCallback) {}

    private:
        TUnboxedValueVector Items;
        ui32 Index;
        std::function<void()> FetchCallback;

        NUdf::EFetchStatus Fetch(NUdf::TUnboxedValue& result) final {
            FetchCallback();
            if (Index >= Items.size()) {
                return NUdf::EFetchStatus::Finish;
            }
            result = Items[Index++];
            return NUdf::EFetchStatus::Ok;
        }
    };

    THolder<IComputationGraph> BuildGraph(
        TSetup& setup,
        const std::vector<TInputItem> items,
        std::function<void()> fetchCallback,
        bool dataWatermarks,
        ui64 hop = 10,
        ui64 interval = 30,
        ui64 delay = 20)
    {
        TProgramBuilder& pgmBuilder = *setup.PgmBuilder;

        auto structType = pgmBuilder.NewEmptyStructType();
        structType = pgmBuilder.NewStructType(structType, "key",
            pgmBuilder.NewDataType(NUdf::TDataType<ui32>::Id));
        structType = pgmBuilder.NewStructType(structType, "time",
            pgmBuilder.NewDataType(NUdf::TDataType<NUdf::TTimestamp>::Id));
        structType = pgmBuilder.NewStructType(structType, "sum",
            pgmBuilder.NewDataType(NUdf::TDataType<ui32>::Id));
        auto keyIndex = AS_TYPE(TStructType, structType)->GetMemberIndex("key");
        auto timeIndex = AS_TYPE(TStructType, structType)->GetMemberIndex("time");
        auto sumIndex = AS_TYPE(TStructType, structType)->GetMemberIndex("sum");

        auto inStreamType = pgmBuilder.NewStreamType(structType);

        TCallableBuilder inStream(pgmBuilder.GetTypeEnvironment(), "MyStream", inStreamType);
        auto streamNode = inStream.Build();

        auto pgmReturn = pgmBuilder.MultiHoppingCore(
            TRuntimeNode(streamNode, false),
            [&](TRuntimeNode item) { // keyExtractor
                return pgmBuilder.Member(item, "key");
            },
            [&](TRuntimeNode item) { // timeExtractor
                return pgmBuilder.Member(item, "time");
            },
            [&](TRuntimeNode item) { // init
                std::vector<std::pair<std::string_view, TRuntimeNode>> members;
                members.emplace_back("sum", pgmBuilder.Member(item, "sum"));
                return pgmBuilder.NewStruct(members);
            },
            [&](TRuntimeNode item, TRuntimeNode state) { // update
                auto add = pgmBuilder.AggrAdd(
                    pgmBuilder.Member(item, "sum"),
                    pgmBuilder.Member(state, "sum"));
                std::vector<std::pair<std::string_view, TRuntimeNode>> members;
                members.emplace_back("sum", add);
                return pgmBuilder.NewStruct(members);
            },
            [&](TRuntimeNode state) { // save
                return pgmBuilder.Member(state, "sum");
            },
            [&](TRuntimeNode savedState) { // load
                std::vector<std::pair<std::string_view, TRuntimeNode>> members;
                members.emplace_back("sum", savedState);
                return pgmBuilder.NewStruct(members);
            },
            [&](TRuntimeNode state1, TRuntimeNode state2) { // merge
                auto add = pgmBuilder.AggrAdd(
                    pgmBuilder.Member(state1, "sum"),
                    pgmBuilder.Member(state2, "sum"));
                std::vector<std::pair<std::string_view, TRuntimeNode>> members;
                members.emplace_back("sum", add);
                return pgmBuilder.NewStruct(members);
            },
            [&](TRuntimeNode key, TRuntimeNode state, TRuntimeNode time) { // finish
                std::vector<std::pair<std::string_view, TRuntimeNode>> members;
                members.emplace_back("key", key);
                members.emplace_back("sum", pgmBuilder.Member(state, "sum"));
                members.emplace_back("time", time);
                return pgmBuilder.NewStruct(members);
            },
            pgmBuilder.NewDataLiteral<NUdf::EDataSlot::Interval>(NUdf::TStringRef((const char*)&hop, sizeof(hop))), // hop
            pgmBuilder.NewDataLiteral<NUdf::EDataSlot::Interval>(NUdf::TStringRef((const char*)&interval, sizeof(interval))), // interval
            pgmBuilder.NewDataLiteral<NUdf::EDataSlot::Interval>(NUdf::TStringRef((const char*)&delay, sizeof(delay))),  // delay
            pgmBuilder.NewDataLiteral<bool>(dataWatermarks)  // dataWatermarks
        );

        auto graph = setup.BuildGraph(pgmReturn, {streamNode});

        TUnboxedValueVector streamItems;
        for (size_t i = 0; i < items.size(); ++i) {
            NUdf::TUnboxedValue* itemsPtr;
            auto structValues = graph->GetHolderFactory().CreateDirectArrayHolder(3, itemsPtr);
            itemsPtr[keyIndex] = NUdf::TUnboxedValuePod(items.at(i).Key);
            itemsPtr[timeIndex] = NUdf::TUnboxedValuePod(items.at(i).Time);
            itemsPtr[sumIndex] = NUdf::TUnboxedValuePod(items.at(i).Val);
            streamItems.push_back(std::move(structValues));
        }

        auto streamValue = NUdf::TUnboxedValuePod(new TStream(streamItems, fetchCallback));
        graph->GetEntryPoint(0, true)->SetValue(graph->GetContext(), std::move(streamValue));
        return graph;
    }
}

Y_UNIT_TEST_SUITE(TMiniKQLMultiHoppingTest) {
    void TestImpl(
        const std::vector<TInputItem> input,
        const std::vector<TOutputGroup> expected,
        bool dataWatermarks,
        ui64 hop = 10,
        ui64 interval = 30,
        ui64 delay = 20)
    {
        TScopedAlloc alloc;
        TSetup setup1(alloc);

        ui32 curGroupId = 0;
        std::vector<TOutputItem> curResult;

        auto check = [&curResult, &curGroupId, &expected]() {
            auto expectedItems = Ordered(expected.at(curGroupId).Items);
            curResult = Ordered(curResult);
            UNIT_ASSERT_EQUAL_C(curResult, expectedItems, "curGroup: " << curGroupId << " actual: " << curResult << " expected: " << expectedItems);
            curGroupId++;
            curResult.clear();
        };

        auto graph1 = BuildGraph(setup1, input, check, dataWatermarks, hop, interval, delay);

        auto root1 = graph1->GetValue();

        NUdf::EFetchStatus status = NUdf::EFetchStatus::Ok;
        while (status == NUdf::EFetchStatus::Ok) {
            NUdf::TUnboxedValue val;
            status = root1.Fetch(val);
            if (status == NUdf::EFetchStatus::Ok) {
                curResult.emplace_back(TOutputItem{val.GetElement(0).Get<ui32>(), val.GetElement(1).Get<ui32>(), val.GetElement(2).Get<ui64>()});
            } 
        }

        check();
        // TODO: some problem with parallel run
        //UNIT_ASSERT_EQUAL_C(curGroupId, expected.size(), "1: " << curGroupId << " 2: "  << expected.size());
    }

    Y_UNIT_TEST(TestDataWatermarks) {
        const std::vector<TInputItem> input = {
            // Group; Time; Value
            {1, 101, 2},
            {2, 101, 2},
            {1, 111, 3},
            {2, 140, 5},
            {2, 160, 1}
        };
        const std::vector<TOutputGroup> expected = {
            TOutputGroup({}),
            TOutputGroup({}),
            TOutputGroup({}),
            TOutputGroup({}),
            TOutputGroup({{1, 2, 110}, {1, 5, 120}, {2, 2, 110}, {2, 2, 120}}),
            TOutputGroup({{2, 2, 130}, {1, 5, 130}, {1, 3, 140}}),
            TOutputGroup({{2, 5, 150}, {2, 5, 160}, {2, 6, 170}, {2, 1, 180}, {2, 1, 190}}),
        };
        TestImpl(input, expected, true);
    }
 
    Y_UNIT_TEST(TestValidness1) {
        const std::vector<TInputItem> input1 = {
            // Group; Time; Value
            {1, 101, 2},
            {2, 101, 2},
            {1, 111, 3},
            {2, 140, 5},
            {2, 160, 1}
        };

        const std::vector<TOutputGroup> expected = {
            TOutputGroup({}),
            TOutputGroup({}),
            TOutputGroup({}),
            TOutputGroup({}),
            TOutputGroup({{2, 2, 110}, {2, 2, 120}}),
            TOutputGroup({{2, 2, 130}}),
            TOutputGroup({{1, 2, 110}, {1, 5, 120}, {1, 5, 130}, {1, 3, 140}, {2, 5, 150},
                          {2, 5, 160}, {2, 6, 170}, {2, 1, 190}, {2, 1, 180}}),
        };
        TestImpl(input1, expected, false);
    }

    Y_UNIT_TEST(TestValidness2) {
        const std::vector<TInputItem> input = {
            // Group; Time; Value
            {2, 101, 2}, {1, 101, 2}, {2, 102, 3}, {1, 102, 3}, {2, 115, 4},
            {1, 115, 4}, {2, 123, 6}, {1, 123, 6}, {2, 124, 5}, {1, 124, 5},
            {2, 125, 7}, {1, 125, 7}, {2, 140, 2}, {1, 140, 2}, {2, 147, 1},
            {1, 147, 1}, {2, 151, 6}, {1, 151, 6}, {2, 159, 2}, {1, 159, 2},
            {2, 185, 8}, {1, 185, 8}
        };
        const std::vector<TOutputGroup> expected = {
            TOutputGroup({}),
            TOutputGroup({}), TOutputGroup({}), TOutputGroup({}), TOutputGroup({}),
            TOutputGroup({}), TOutputGroup({}), TOutputGroup({}), TOutputGroup({}),
            TOutputGroup({}), TOutputGroup({}), TOutputGroup({}), TOutputGroup({}),
            TOutputGroup({{1, 5, 110}, {1, 9, 120}, {2, 5, 110}, {2, 9, 120}}),
            TOutputGroup({}),
            TOutputGroup({}), TOutputGroup({}),
            TOutputGroup({{2, 27, 130}, {1, 27, 130}}),
            TOutputGroup({}), TOutputGroup({}), TOutputGroup({}),
            TOutputGroup({{2, 22, 140}, {2, 21, 150},  {2, 11, 160}, {1, 22, 140}, {1, 21, 150}, {1, 11, 160}}),
            TOutputGroup({}),
            TOutputGroup({{1, 11, 170}, {1, 8, 180}, {1, 8, 190}, {1, 8, 200}, {1, 8, 210}, {2, 11, 170},
                          {2, 8, 180}, {2, 8, 190}, {2, 8, 200}, {2, 8, 210}}),
        };

        TestImpl(input, expected, true);
    }

    Y_UNIT_TEST(TestValidness3) {
        const std::vector<TInputItem> input = {
            // Group; Time; Value
            {1, 105, 1}, {1, 107, 4}, {2, 106, 3}, {1, 111, 7}, {1, 117, 3},
            {2, 110, 2}, {1, 108, 9}, {1, 121, 4}, {2, 107, 2}, {2, 141, 5},
            {1, 141, 10}
        };
        const std::vector<TOutputGroup> expected = {
            TOutputGroup({}),
            TOutputGroup({}), TOutputGroup({}), TOutputGroup({}), TOutputGroup({}),
            TOutputGroup({}), TOutputGroup({}), TOutputGroup({}),
            TOutputGroup({{1, 14, 110}, {2, 3, 110}}),
            TOutputGroup({}),
            TOutputGroup({{2, 7, 115}, {2, 2, 120}, {1, 21, 115}, {1, 10, 120}, {1, 7, 125}, {1, 4, 130}}),
            TOutputGroup({}),
            TOutputGroup({{1, 10, 145}, {1, 10, 150}, {2, 5, 145}, {2, 5, 150}})
        };

        TestImpl(input, expected, true, 5, 10, 10);
    } 
 
    Y_UNIT_TEST(TestDelay) {
        const std::vector<TInputItem> input = {
            // Group; Time; Value
            {1, 101, 3}, {1, 111, 5}, {1, 120, 7}, {1, 80, 9}, {1, 79, 11}
        };
        const std::vector<TOutputGroup> expected = {
            TOutputGroup({}),
            TOutputGroup({}), TOutputGroup({}), TOutputGroup({}),
            TOutputGroup({}), TOutputGroup({}),
            TOutputGroup({{1, 12, 110}, {1, 8, 120}, {1, 15, 130}, {1, 12, 140}, {1, 7, 150}})
        };

        TestImpl(input, expected, false);
    } 

    Y_UNIT_TEST(TestWindowsBeforeFirstElement) {
        const std::vector<TInputItem> input = {
            // Group; Time; Value
            {1, 101, 2}, {1, 111, 3}
        };
        const std::vector<TOutputGroup> expected = {
            TOutputGroup({}),
            TOutputGroup({}),
            TOutputGroup({}),
            TOutputGroup({{1, 2, 110}, {1, 5, 120}, {1, 5, 130}, {1, 3, 140}})
        };

        TestImpl(input, expected, false);
    }

    Y_UNIT_TEST(TestSubzeroValues) {
        const std::vector<TInputItem> input = {
            // Group; Time; Value
            {1, 1, 2}
        };
        const std::vector<TOutputGroup> expected = {
            TOutputGroup({}),
            TOutputGroup({}),
            TOutputGroup({{1, 2, 30}}),
        };

        TestImpl(input, expected, false);
    }
}

} // namespace NMiniKQL
} // namespace NKikimr
