# Generated by devtools/yamaker.

PROGRAM(clang-apply-replacements)

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/clang14
    contrib/libs/clang14/include
    contrib/libs/clang14/lib/AST
    contrib/libs/clang14/lib/ASTMatchers
    contrib/libs/clang14/lib/Analysis
    contrib/libs/clang14/lib/Basic
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
    contrib/libs/clang14/lib/Tooling/Core
    contrib/libs/clang14/lib/Tooling/Inclusions
    contrib/libs/clang14/lib/Tooling/Refactoring
    contrib/libs/clang14/tools/extra/clang-apply-replacements/lib/Tooling
    contrib/libs/llvm14
    contrib/libs/llvm14/lib/Support
)

ADDINCL(
    contrib/libs/clang14/tools/extra/clang-apply-replacements
    contrib/libs/clang14/tools/extra/clang-apply-replacements/include
    contrib/libs/clang14/tools/extra/clang-apply-replacements/tool
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    ClangApplyReplacementsMain.cpp
)

END()
