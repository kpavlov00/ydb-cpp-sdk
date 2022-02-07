# Generated by devtools/yamaker.

LIBRARY()

OWNER(
    orivej
    g:cpp-contrib
)

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/llvm12
    contrib/libs/llvm12/include
    contrib/libs/llvm12/lib/Analysis
    contrib/libs/llvm12/lib/IR
    contrib/libs/llvm12/lib/Support
)

ADDINCL(
    contrib/libs/llvm12/lib/Transforms/Utils
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    AMDGPUEmitPrintf.cpp
    ASanStackFrameLayout.cpp
    AddDiscriminators.cpp
    AssumeBundleBuilder.cpp
    BasicBlockUtils.cpp
    BreakCriticalEdges.cpp
    BuildLibCalls.cpp
    BypassSlowDivision.cpp
    CallGraphUpdater.cpp
    CallPromotionUtils.cpp
    CanonicalizeAliases.cpp
    CanonicalizeFreezeInLoops.cpp
    CloneFunction.cpp
    CloneModule.cpp
    CodeExtractor.cpp
    CodeMoverUtils.cpp
    CtorUtils.cpp
    Debugify.cpp
    DemoteRegToStack.cpp
    EntryExitInstrumenter.cpp
    EscapeEnumerator.cpp
    Evaluator.cpp
    FixIrreducible.cpp
    FlattenCFG.cpp
    FunctionComparator.cpp
    FunctionImportUtils.cpp
    GlobalStatus.cpp
    GuardUtils.cpp
    InjectTLIMappings.cpp
    InlineFunction.cpp
    InstructionNamer.cpp
    IntegerDivision.cpp
    LCSSA.cpp
    LibCallsShrinkWrap.cpp
    Local.cpp
    LoopPeel.cpp
    LoopRotationUtils.cpp
    LoopSimplify.cpp
    LoopUnroll.cpp
    LoopUnrollAndJam.cpp
    LoopUnrollRuntime.cpp
    LoopUtils.cpp
    LoopVersioning.cpp
    LowerInvoke.cpp
    LowerMemIntrinsics.cpp
    LowerSwitch.cpp
    MatrixUtils.cpp
    Mem2Reg.cpp
    MetaRenamer.cpp
    ModuleUtils.cpp
    NameAnonGlobals.cpp
    PredicateInfo.cpp
    PromoteMemoryToRegister.cpp
    SSAUpdater.cpp
    SSAUpdaterBulk.cpp
    SanitizerStats.cpp
    ScalarEvolutionExpander.cpp
    SimplifyCFG.cpp
    SimplifyIndVar.cpp
    SimplifyLibCalls.cpp
    SizeOpts.cpp
    SplitModule.cpp
    StripGCRelocates.cpp
    StripNonLineTableDebugInfo.cpp
    SymbolRewriter.cpp
    UnifyFunctionExitNodes.cpp
    UnifyLoopExits.cpp
    UniqueInternalLinkageNames.cpp
    Utils.cpp
    VNCoercion.cpp
    ValueMapper.cpp
)

END()
