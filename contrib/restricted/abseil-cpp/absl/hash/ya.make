# Generated by devtools/yamaker.

LIBRARY()

LICENSE(Apache-2.0)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/restricted/abseil-cpp/absl/base
    contrib/restricted/abseil-cpp/absl/numeric
    contrib/restricted/abseil-cpp/absl/strings
    contrib/restricted/abseil-cpp/absl/types
)

ADDINCL(
    GLOBAL contrib/restricted/abseil-cpp
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    internal/city.cc
    internal/hash.cc
    internal/low_level_hash.cc
)

END()