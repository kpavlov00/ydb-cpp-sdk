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
    contrib/libs/llvm12/include
    contrib/libs/llvm12/lib/Analysis
    contrib/libs/llvm12/lib/CodeGen
    contrib/libs/llvm12/lib/CodeGen/AsmPrinter
    contrib/libs/llvm12/lib/CodeGen/SelectionDAG
    contrib/libs/llvm12/lib/IR
    contrib/libs/llvm12/lib/MC
    contrib/libs/llvm12/lib/Support
    contrib/libs/llvm12/lib/Target
    contrib/libs/llvm12/lib/Target/BPF/MCTargetDesc
    contrib/libs/llvm12/lib/Target/BPF/TargetInfo
    contrib/libs/llvm12/lib/Transforms/IPO
    contrib/libs/llvm12/lib/Transforms/Scalar
    contrib/libs/llvm12/lib/Transforms/Utils
) 
 
ADDINCL( 
    ${ARCADIA_BUILD_ROOT}/contrib/libs/llvm12/lib/Target/BPF
    contrib/libs/llvm12/lib/Target/BPF
) 
 
NO_COMPILER_WARNINGS() 
 
NO_UTIL() 
 
SRCS( 
    BPFAbstractMemberAccess.cpp 
    BPFAdjustOpt.cpp
    BPFAsmPrinter.cpp 
    BPFCheckAndAdjustIR.cpp
    BPFFrameLowering.cpp 
    BPFISelDAGToDAG.cpp 
    BPFISelLowering.cpp 
    BPFInstrInfo.cpp 
    BPFMCInstLower.cpp 
    BPFMIChecking.cpp 
    BPFMIPeephole.cpp 
    BPFMISimplifyPatchable.cpp 
    BPFPreserveDIType.cpp 
    BPFRegisterInfo.cpp 
    BPFSelectionDAGInfo.cpp 
    BPFSubtarget.cpp 
    BPFTargetMachine.cpp 
    BTFDebug.cpp 
) 
 
END() 
