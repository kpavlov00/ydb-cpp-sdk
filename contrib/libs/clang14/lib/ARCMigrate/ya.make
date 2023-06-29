# Generated by devtools/yamaker.

LIBRARY()

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/clang14
    contrib/libs/clang14/include
    contrib/libs/clang14/lib/AST
    contrib/libs/clang14/lib/Analysis
    contrib/libs/clang14/lib/Basic
    contrib/libs/clang14/lib/Edit
    contrib/libs/clang14/lib/Frontend
    contrib/libs/clang14/lib/Lex
    contrib/libs/clang14/lib/Rewrite
    contrib/libs/clang14/lib/Sema
    contrib/libs/clang14/lib/Serialization
    contrib/libs/llvm14
    contrib/libs/llvm14/lib/Support
)

ADDINCL(
    contrib/libs/clang14/lib/ARCMigrate
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    ARCMT.cpp
    ARCMTActions.cpp
    FileRemapper.cpp
    ObjCMT.cpp
    PlistReporter.cpp
    TransAPIUses.cpp
    TransARCAssign.cpp
    TransAutoreleasePool.cpp
    TransBlockObjCVariable.cpp
    TransEmptyStatementsAndDealloc.cpp
    TransGCAttrs.cpp
    TransGCCalls.cpp
    TransProperties.cpp
    TransProtectedScope.cpp
    TransRetainReleaseDealloc.cpp
    TransUnbridgedCasts.cpp
    TransUnusedInitDelegate.cpp
    TransZeroOutPropsInDealloc.cpp
    TransformActions.cpp
    Transforms.cpp
)

END()
