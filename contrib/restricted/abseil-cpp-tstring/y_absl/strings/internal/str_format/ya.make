# Generated by devtools/yamaker.

LIBRARY()

OWNER(
    somov
    g:cpp-contrib
)

LICENSE(Apache-2.0)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/restricted/abseil-cpp-tstring/y_absl/base
    contrib/restricted/abseil-cpp-tstring/y_absl/base/internal/raw_logging
    contrib/restricted/abseil-cpp-tstring/y_absl/base/internal/spinlock_wait
    contrib/restricted/abseil-cpp-tstring/y_absl/base/internal/throw_delegate
    contrib/restricted/abseil-cpp-tstring/y_absl/base/log_severity
    contrib/restricted/abseil-cpp-tstring/y_absl/numeric
    contrib/restricted/abseil-cpp-tstring/y_absl/strings
    contrib/restricted/abseil-cpp-tstring/y_absl/strings/internal/absl_strings_internal
)

ADDINCL( 
    GLOBAL contrib/restricted/abseil-cpp-tstring 
) 

NO_COMPILER_WARNINGS()

SRCS(
    arg.cc
    bind.cc
    extension.cc
    float_conversion.cc
    output.cc
    parser.cc
)

END()
