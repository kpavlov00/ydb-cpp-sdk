# Generated by devtools/yamaker.

PROGRAM()

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/llvm14
    contrib/libs/llvm14/lib/Demangle
    contrib/libs/llvm14/lib/IR
    contrib/libs/llvm14/lib/Support
)

ADDINCL(
    contrib/libs/llvm14/tools/llvm-cxxmap
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    llvm-cxxmap.cpp
)

END()
