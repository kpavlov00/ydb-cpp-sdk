# Generated by devtools/yamaker.

LIBRARY()

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/llvm14
    contrib/libs/llvm14/include
    contrib/libs/llvm14/lib/Analysis
    contrib/libs/llvm14/lib/CodeGen
    contrib/libs/llvm14/lib/CodeGen/GlobalISel
    contrib/libs/llvm14/lib/ExecutionEngine
    contrib/libs/llvm14/lib/ExecutionEngine/MCJIT
    contrib/libs/llvm14/lib/ExecutionEngine/RuntimeDyld
    contrib/libs/llvm14/lib/IR
    contrib/libs/llvm14/lib/MC
    contrib/libs/llvm14/lib/MC/MCDisassembler
    contrib/libs/llvm14/lib/MC/MCParser
    contrib/libs/llvm14/lib/Object
    contrib/libs/llvm14/lib/ObjectYAML
    contrib/libs/llvm14/lib/Support
)

ADDINCL(
    contrib/libs/llvm14/tools/llvm-exegesis/lib
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    Analysis.cpp
    Assembler.cpp
    BenchmarkResult.cpp
    BenchmarkRunner.cpp
    Clustering.cpp
    CodeTemplate.cpp
    Error.cpp
    LatencyBenchmarkRunner.cpp
    LlvmState.cpp
    MCInstrDescView.cpp
    ParallelSnippetGenerator.cpp
    PerfHelper.cpp
    RegisterAliasing.cpp
    RegisterValue.cpp
    SchedClassResolution.cpp
    SerialSnippetGenerator.cpp
    SnippetFile.cpp
    SnippetGenerator.cpp
    SnippetRepetitor.cpp
    Target.cpp
    UopsBenchmarkRunner.cpp
)

END()
