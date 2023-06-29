# Generated by devtools/yamaker.

PROGRAM(clang-tidy)

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/clang14/lib
    contrib/libs/clang14/lib/AST
    contrib/libs/clang14/lib/ASTMatchers
    contrib/libs/clang14/lib/Analysis
    contrib/libs/clang14/lib/Basic
    contrib/libs/clang14/lib/CrossTU
    contrib/libs/clang14/lib/Driver
    contrib/libs/clang14/lib/Edit
    contrib/libs/clang14/lib/Format
    contrib/libs/clang14/lib/Frontend
    contrib/libs/clang14/lib/Index
    contrib/libs/clang14/lib/Lex
    contrib/libs/clang14/lib/Parse
    contrib/libs/clang14/lib/Rewrite
    contrib/libs/clang14/lib/Sema
    contrib/libs/clang14/lib/Serialization
    contrib/libs/clang14/lib/StaticAnalyzer/Checkers
    contrib/libs/clang14/lib/StaticAnalyzer/Core
    contrib/libs/clang14/lib/StaticAnalyzer/Frontend
    contrib/libs/clang14/lib/Tooling
    contrib/libs/clang14/lib/Tooling/Core
    contrib/libs/clang14/lib/Tooling/Inclusions
    contrib/libs/clang14/lib/Tooling/Refactoring
    contrib/libs/clang14/lib/Tooling/Transformer
    contrib/libs/clang14/tools/extra/clang-tidy
    contrib/libs/clang14/tools/extra/clang-tidy/abseil
    contrib/libs/clang14/tools/extra/clang-tidy/altera
    contrib/libs/clang14/tools/extra/clang-tidy/android
    contrib/libs/clang14/tools/extra/clang-tidy/boost
    contrib/libs/clang14/tools/extra/clang-tidy/bugprone
    contrib/libs/clang14/tools/extra/clang-tidy/cert
    contrib/libs/clang14/tools/extra/clang-tidy/concurrency
    contrib/libs/clang14/tools/extra/clang-tidy/cppcoreguidelines
    contrib/libs/clang14/tools/extra/clang-tidy/darwin
    contrib/libs/clang14/tools/extra/clang-tidy/fuchsia
    contrib/libs/clang14/tools/extra/clang-tidy/google
    contrib/libs/clang14/tools/extra/clang-tidy/hicpp
    contrib/libs/clang14/tools/extra/clang-tidy/linuxkernel
    contrib/libs/clang14/tools/extra/clang-tidy/llvm
    contrib/libs/clang14/tools/extra/clang-tidy/llvmlibc
    contrib/libs/clang14/tools/extra/clang-tidy/misc
    contrib/libs/clang14/tools/extra/clang-tidy/modernize
    contrib/libs/clang14/tools/extra/clang-tidy/mpi
    contrib/libs/clang14/tools/extra/clang-tidy/objc
    contrib/libs/clang14/tools/extra/clang-tidy/openmp
    contrib/libs/clang14/tools/extra/clang-tidy/performance
    contrib/libs/clang14/tools/extra/clang-tidy/portability
    contrib/libs/clang14/tools/extra/clang-tidy/readability
    contrib/libs/clang14/tools/extra/clang-tidy/utils
    contrib/libs/clang14/tools/extra/clang-tidy/zircon
    library/cpp/clang_tidy/arcadia_checks
)

ADDINCL(
    contrib/libs/clang14/tools/extra/clang-tidy/tool
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    ClangTidyToolMain.cpp
)

END()
