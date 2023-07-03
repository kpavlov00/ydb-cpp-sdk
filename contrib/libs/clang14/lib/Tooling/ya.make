# Generated by devtools/yamaker.

LIBRARY()

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/clang14
    contrib/libs/clang14/include
    contrib/libs/clang14/lib/AST
    contrib/libs/clang14/lib/ASTMatchers
    contrib/libs/clang14/lib/Basic
    contrib/libs/clang14/lib/Driver
    contrib/libs/clang14/lib/Format
    contrib/libs/clang14/lib/Frontend
    contrib/libs/clang14/lib/Lex
    contrib/libs/clang14/lib/Rewrite
    contrib/libs/clang14/lib/Serialization
    contrib/libs/clang14/lib/Tooling/Core
    contrib/libs/llvm14
    contrib/libs/llvm14/lib/Frontend/OpenMP
    contrib/libs/llvm14/lib/Option
    contrib/libs/llvm14/lib/Support
)

ADDINCL(
    contrib/libs/clang14/lib/Tooling
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    AllTUsExecution.cpp
    ArgumentsAdjusters.cpp
    CommonOptionsParser.cpp
    CompilationDatabase.cpp
    Execution.cpp
    ExpandResponseFilesCompilationDatabase.cpp
    FileMatchTrie.cpp
    FixIt.cpp
    GuessTargetAndModeCompilationDatabase.cpp
    InterpolatingCompilationDatabase.cpp
    JSONCompilationDatabase.cpp
    NodeIntrospection.cpp
    Refactoring.cpp
    RefactoringCallbacks.cpp
    StandaloneExecution.cpp
    Tooling.cpp
)

END()