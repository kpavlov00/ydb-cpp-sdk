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
    contrib/libs/llvm12/lib/CodeGen
    contrib/libs/llvm12/lib/DebugInfo/DWARF
    contrib/libs/llvm12/lib/ExecutionEngine
    contrib/libs/llvm12/lib/ExecutionEngine/RuntimeDyld
    contrib/libs/llvm12/lib/IR
    contrib/libs/llvm12/lib/Object
    contrib/libs/llvm12/lib/Support
)

ADDINCL( 
    contrib/libs/llvm12/lib/ExecutionEngine/PerfJITEvents 
) 

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    PerfJITEventListener.cpp
)

END()
