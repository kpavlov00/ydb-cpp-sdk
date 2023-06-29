# Generated by devtools/yamaker.

LIBRARY()

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/llvm14
    contrib/libs/llvm14/lib/Bitstream/Reader
    contrib/libs/llvm14/lib/Support
)

ADDINCL(
    contrib/libs/llvm14/lib/Remarks
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    BitstreamRemarkParser.cpp
    BitstreamRemarkSerializer.cpp
    Remark.cpp
    RemarkFormat.cpp
    RemarkLinker.cpp
    RemarkParser.cpp
    RemarkSerializer.cpp
    RemarkStreamer.cpp
    RemarkStringTable.cpp
    YAMLRemarkParser.cpp
    YAMLRemarkSerializer.cpp
)

END()
