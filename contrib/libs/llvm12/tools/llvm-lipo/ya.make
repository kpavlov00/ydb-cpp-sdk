# Generated by devtools/yamaker.

PROGRAM()

OWNER( 
    orivej 
    g:cpp-contrib 
) 

LICENSE(Apache-2.0 WITH LLVM-exception) 

LICENSE_TEXTS(.yandex_meta/licenses.list.txt) 
 
PEERDIR(
    contrib/libs/llvm12
    contrib/libs/llvm12/include
    contrib/libs/llvm12/lib/BinaryFormat
    contrib/libs/llvm12/lib/Bitcode/Reader
    contrib/libs/llvm12/lib/Bitstream/Reader
    contrib/libs/llvm12/lib/Demangle
    contrib/libs/llvm12/lib/IR
    contrib/libs/llvm12/lib/MC
    contrib/libs/llvm12/lib/MC/MCParser
    contrib/libs/llvm12/lib/Object
    contrib/libs/llvm12/lib/Option
    contrib/libs/llvm12/lib/Remarks
    contrib/libs/llvm12/lib/Support
    contrib/libs/llvm12/lib/Target/AArch64
    contrib/libs/llvm12/lib/Target/AArch64/AsmParser
    contrib/libs/llvm12/lib/Target/AArch64/Disassembler
    contrib/libs/llvm12/lib/Target/AArch64/MCTargetDesc
    contrib/libs/llvm12/lib/Target/AArch64/TargetInfo
    contrib/libs/llvm12/lib/Target/AArch64/Utils
    contrib/libs/llvm12/lib/Target/ARM
    contrib/libs/llvm12/lib/Target/ARM/AsmParser
    contrib/libs/llvm12/lib/Target/ARM/Disassembler
    contrib/libs/llvm12/lib/Target/ARM/MCTargetDesc
    contrib/libs/llvm12/lib/Target/ARM/TargetInfo
    contrib/libs/llvm12/lib/Target/ARM/Utils
    contrib/libs/llvm12/lib/Target/BPF
    contrib/libs/llvm12/lib/Target/BPF/AsmParser
    contrib/libs/llvm12/lib/Target/BPF/Disassembler
    contrib/libs/llvm12/lib/Target/BPF/MCTargetDesc
    contrib/libs/llvm12/lib/Target/BPF/TargetInfo
    contrib/libs/llvm12/lib/Target/NVPTX
    contrib/libs/llvm12/lib/Target/NVPTX/MCTargetDesc
    contrib/libs/llvm12/lib/Target/NVPTX/TargetInfo
    contrib/libs/llvm12/lib/Target/PowerPC
    contrib/libs/llvm12/lib/Target/PowerPC/AsmParser
    contrib/libs/llvm12/lib/Target/PowerPC/Disassembler
    contrib/libs/llvm12/lib/Target/PowerPC/MCTargetDesc
    contrib/libs/llvm12/lib/Target/PowerPC/TargetInfo
    contrib/libs/llvm12/lib/Target/X86
    contrib/libs/llvm12/lib/Target/X86/AsmParser
    contrib/libs/llvm12/lib/Target/X86/Disassembler
    contrib/libs/llvm12/lib/Target/X86/MCTargetDesc
    contrib/libs/llvm12/lib/Target/X86/TargetInfo
    contrib/libs/llvm12/lib/TextAPI/MachO
)

ADDINCL(
    ${ARCADIA_BUILD_ROOT}/contrib/libs/llvm12/tools/llvm-lipo
    contrib/libs/llvm12/tools/llvm-lipo
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    llvm-lipo.cpp
)

END()
