#pragma once

#include <ydb/library/yql/public/udf/udf_value.h>
#include <util/digest/numeric.h>

#include <arrow/compute/kernel.h>

namespace NKikimr {

namespace NMiniKQL {

using TFunctionPtr = NUdf::TUnboxedValuePod (*)(const NUdf::TUnboxedValuePod* args);

struct TFunctionParamMetadata {
    enum EFlags : ui16 {
        FlagIsNullable = 0x01,
    };

    TFunctionParamMetadata() = default;

    TFunctionParamMetadata(NUdf::TDataTypeId schemeType, ui32 flags)
        : SchemeType(schemeType)
        , Flags(flags)
    {}

    bool IsNullable() const {
        return Flags & FlagIsNullable;
    }

    NUdf::TDataTypeId SchemeType = 0;
    ui16 Flags = 0;
};

struct TFunctionDescriptor {
    TFunctionDescriptor() = default;

    TFunctionDescriptor(const TFunctionParamMetadata* resultAndArgs, TFunctionPtr function, void* generator = nullptr)
        : ResultAndArgs(resultAndArgs)
        , Function(function)
        , Generator(generator)
    {}

    const TFunctionParamMetadata* ResultAndArgs = nullptr; // ends with SchemeType zero
    TFunctionPtr Function = nullptr;
    void *Generator = nullptr;
};

using TFunctionParamMetadataList = std::vector<TFunctionParamMetadata>;
using TArgType = std::pair<NUdf::TDataTypeId, bool>; // type with optional flag
using TDescriptionList = std::vector<TFunctionDescriptor>;
using TFunctionsMap = std::unordered_map<TString, TDescriptionList>;

class TKernel;

class TKernelFamily {
public:
    enum ENullMode {
        Default,
        AlwaysNull,
        AlwaysNotNull
    };

    const ENullMode NullMode;
    const arrow::compute::FunctionOptions* FunctionOptions;

    TKernelFamily(ENullMode nullMode = ENullMode::Default, const arrow::compute::FunctionOptions* functionOptions = nullptr)
        : NullMode(nullMode)
        , FunctionOptions(functionOptions)
    {}

    virtual ~TKernelFamily() = default;
    virtual const TKernel* FindKernel(const NUdf::TDataTypeId* argTypes, size_t argTypesCount) const = 0;
};

class TKernel {
public:
    const TKernelFamily& Family;
    const std::vector<NUdf::TDataTypeId> ArgTypes;
    const NUdf::TDataTypeId ReturnType;

    TKernel(const TKernelFamily& family, const std::vector<NUdf::TDataTypeId>& argTypes, NUdf::TDataTypeId returnType)
        : Family(family)
        , ArgTypes(argTypes)
        , ReturnType(returnType)
    {
    }

    virtual const arrow::compute::ScalarKernel& GetArrowKernel() const = 0;

    virtual ~TKernel() = default;
};

struct TTypeHasher {
    std::size_t operator()(const std::vector<NUdf::TDataTypeId>& s) const noexcept {
        size_t r = 0;
        for (const auto& x : s) {
            r = CombineHashes<size_t>(r, x);
        }

        return r;
    }
};

using TKernelMap = std::unordered_map<std::vector<NUdf::TDataTypeId>, std::unique_ptr<TKernel>, TTypeHasher>;

using TKernelFamilyMap = std::unordered_map<TString, std::unique_ptr<TKernelFamily>>;

class TKernelFamilyBase : public TKernelFamily
{
public:
    TKernelFamilyBase(ENullMode nullMode = ENullMode::Default, const arrow::compute::FunctionOptions* functionOptions = nullptr)
        : TKernelFamily(nullMode, functionOptions)
    {}

    const TKernel* FindKernel(const NUdf::TDataTypeId* argTypes, size_t argTypesCount) const final {
        std::vector<NUdf::TDataTypeId> key(argTypes, argTypes + argTypesCount);
        auto it = KernelMap.find(key);
        if (it == KernelMap.end()) {
            return nullptr;
        }

        return it->second.get();
    }

    TKernelMap KernelMap;
};

class IBuiltinFunctionRegistry: public TThrRefBase, private TNonCopyable
{
public:
    typedef TIntrusivePtr<IBuiltinFunctionRegistry> TPtr;

    virtual ui64 GetMetadataEtag() const = 0;

    virtual void PrintInfoTo(IOutputStream& out) const = 0;

    virtual void Register(const std::string_view& name, const TFunctionDescriptor& description) = 0;

    virtual bool HasBuiltin(const std::string_view& name) const = 0;

    virtual void RegisterAll(TFunctionsMap&& functions, TFunctionParamMetadataList&& arguments) = 0;

    virtual const TFunctionsMap& GetFunctions() const = 0;

    virtual TFunctionDescriptor GetBuiltin(const std::string_view& name, const std::pair<NUdf::TDataTypeId, bool>* argTypes, size_t argTypesCount) const = 0;

    virtual const TKernel* FindKernel(const std::string_view& name, const NUdf::TDataTypeId* argTypes, size_t argTypesCount) const = 0;

    virtual void RegisterKernelFamily(const std::string_view& name, std::unique_ptr<TKernelFamily>&& family) = 0;
};

}
}
