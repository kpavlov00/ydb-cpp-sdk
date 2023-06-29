# Generated by devtools/yamaker.

LIBRARY()

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/llvm16
    contrib/libs/llvm16/lib/BinaryFormat
    contrib/libs/llvm16/lib/Support
    contrib/libs/llvm16/lib/TargetParser
)

ADDINCL(
    contrib/libs/llvm16/lib/TextAPI
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    Architecture.cpp
    ArchitectureSet.cpp
    InterfaceFile.cpp
    PackedVersion.cpp
    Platform.cpp
    Symbol.cpp
    Target.cpp
    TextStub.cpp
    TextStubCommon.cpp
)

END()
