// The code in this file is based on original ClickHouse source code
// which is licensed under Apache license v2.0
// See: https://github.com/ClickHouse/ClickHouse/

#pragma once
#include "arrow_clickhouse_types.h"

#include <AggregateFunctions/IAggregateFunction.h>
#include <AggregateFunctions/AggregateFunctionWrapper.h>
#include <Columns/ColumnsCommon.h>

#include <array>

namespace CH
{


struct AggregateFunctionCountData
{
    UInt64 count = 0;
    bool has_value = false;

    bool has() const
    {
        return has_value;
    }

    void inc()
    {
        has_value = true;
        ++count;
    }

    void add(UInt64 value)
    {
        has_value = true;
        count += value;
    }
};


/// Simply count number of calls.
class AggregateFunctionCount final : public IAggregateFunctionDataHelper<AggregateFunctionCountData, AggregateFunctionCount>
{
public:
    AggregateFunctionCount(const DataTypes & argument_types_)
        : IAggregateFunctionDataHelper(argument_types_, {})
    {}

    DataTypePtr getReturnType() const override
    {
        return std::make_shared<DataTypeUInt64>();
    }

    bool allocatesMemoryInArena() const override { return false; }

    void add(AggregateDataPtr __restrict place, const IColumn **, size_t, Arena *) const override
    {
        data(place).inc();
    }

    void addBatchSinglePlace(
        size_t row_begin,
        size_t row_end,
        AggregateDataPtr __restrict place,
        const IColumn ** columns,
        Arena *) const override
    {
        const auto & column = *columns[0];
        if (auto * flags = column.null_bitmap_data())
        {
            auto * condition_map = flags + column.offset();
            auto length = row_end - row_begin;
            data(place).add(arrow::internal::CountSetBits(condition_map, row_begin, length));
        }
        else
        {
            data(place).add(row_end - row_begin);
        }
    }

    void merge(AggregateDataPtr __restrict place, ConstAggregateDataPtr rhs, Arena *) const override
    {
        data(place).add(data(rhs).count);
    }

    void insertResultInto(AggregateDataPtr __restrict place, MutableColumn & to, Arena *) const override
    {
        if (data(place).has())
            assert_cast<MutableColumnUInt64 &>(to).Append(data(place).count).ok();
        else
            assert_cast<MutableColumnUInt64 &>(to).AppendNull().ok();
    }
};

class WrappedCount final : public ArrowAggregateFunctionWrapper
{
public:
    WrappedCount(std::string name)
        : ArrowAggregateFunctionWrapper(std::move(name))
    {}

    AggregateFunctionPtr getHouseFunction(const DataTypes & argument_types) const override
    {
        return std::make_shared<AggregateFunctionCount>(argument_types);
    }
};

}
