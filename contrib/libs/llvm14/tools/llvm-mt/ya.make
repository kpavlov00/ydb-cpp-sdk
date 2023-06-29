# Generated by devtools/yamaker.

PROGRAM()

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/llvm14
    contrib/libs/llvm14/include
    contrib/libs/llvm14/lib/Demangle
    contrib/libs/llvm14/lib/Option
    contrib/libs/llvm14/lib/Support
    contrib/libs/llvm14/lib/WindowsManifest
)

ADDINCL(
    ${ARCADIA_BUILD_ROOT}/contrib/libs/llvm14/tools/llvm-mt
    contrib/libs/llvm14/tools/llvm-mt
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    llvm-mt.cpp
)

END()
