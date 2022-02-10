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
    contrib/libs/llvm12/lib/MC
    contrib/libs/llvm12/lib/Support
) 
 
ADDINCL(
    contrib/libs/llvm12/lib/MC/MCDisassembler
)
 
NO_COMPILER_WARNINGS() 
 
NO_UTIL() 
 
SRCS( 
    Disassembler.cpp 
    MCDisassembler.cpp 
    MCExternalSymbolizer.cpp 
    MCRelocationInfo.cpp 
    MCSymbolizer.cpp 
) 
 
END() 
