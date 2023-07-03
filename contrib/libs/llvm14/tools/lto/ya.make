# Generated by devtools/yamaker.

LIBRARY()

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/llvm14
    contrib/libs/llvm14/include
    contrib/libs/llvm14/lib/Bitcode/Reader
    contrib/libs/llvm14/lib/CodeGen
    contrib/libs/llvm14/lib/IR
    contrib/libs/llvm14/lib/LTO
    contrib/libs/llvm14/lib/MC
    contrib/libs/llvm14/lib/MC/MCDisassembler
    contrib/libs/llvm14/lib/Support
    contrib/libs/llvm14/lib/Target
    contrib/libs/llvm14/lib/Target/AArch64
    contrib/libs/llvm14/lib/Target/AArch64/AsmParser
    contrib/libs/llvm14/lib/Target/AArch64/Disassembler
    contrib/libs/llvm14/lib/Target/AArch64/MCTargetDesc
    contrib/libs/llvm14/lib/Target/AArch64/TargetInfo
    contrib/libs/llvm14/lib/Target/ARM
    contrib/libs/llvm14/lib/Target/ARM/AsmParser
    contrib/libs/llvm14/lib/Target/ARM/Disassembler
    contrib/libs/llvm14/lib/Target/ARM/MCTargetDesc
    contrib/libs/llvm14/lib/Target/ARM/TargetInfo
    contrib/libs/llvm14/lib/Target/BPF
    contrib/libs/llvm14/lib/Target/BPF/AsmParser
    contrib/libs/llvm14/lib/Target/BPF/Disassembler
    contrib/libs/llvm14/lib/Target/BPF/MCTargetDesc
    contrib/libs/llvm14/lib/Target/BPF/TargetInfo
    contrib/libs/llvm14/lib/Target/NVPTX
    contrib/libs/llvm14/lib/Target/NVPTX/MCTargetDesc
    contrib/libs/llvm14/lib/Target/NVPTX/TargetInfo
    contrib/libs/llvm14/lib/Target/PowerPC
    contrib/libs/llvm14/lib/Target/PowerPC/AsmParser
    contrib/libs/llvm14/lib/Target/PowerPC/Disassembler
    contrib/libs/llvm14/lib/Target/PowerPC/MCTargetDesc
    contrib/libs/llvm14/lib/Target/PowerPC/TargetInfo
    contrib/libs/llvm14/lib/Target/X86
    contrib/libs/llvm14/lib/Target/X86/AsmParser
    contrib/libs/llvm14/lib/Target/X86/Disassembler
    contrib/libs/llvm14/lib/Target/X86/MCTargetDesc
    contrib/libs/llvm14/lib/Target/X86/TargetInfo
)

ADDINCL(
    contrib/libs/llvm14/tools/lto
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    LTODisassembler.cpp
    lto.cpp
)

END()