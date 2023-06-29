# Generated by devtools/yamaker.

LIBRARY()

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/llvm14
    contrib/libs/llvm14/lib/DebugInfo/DWARF
    contrib/libs/llvm14/lib/DebugInfo/PDB
    contrib/libs/llvm14/lib/Demangle
    contrib/libs/llvm14/lib/Object
    contrib/libs/llvm14/lib/Support
)

ADDINCL(
    contrib/libs/llvm14/lib/DebugInfo/Symbolize
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    DIFetcher.cpp
    DIPrinter.cpp
    SymbolizableObjectFile.cpp
    Symbolize.cpp
)

END()
