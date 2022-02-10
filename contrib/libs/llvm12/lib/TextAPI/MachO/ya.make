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
    contrib/libs/llvm12/lib/BinaryFormat
    contrib/libs/llvm12/lib/Support
)

ADDINCL( 
    contrib/libs/llvm12/lib/TextAPI 
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
