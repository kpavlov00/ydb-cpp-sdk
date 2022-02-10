# Generated by devtools/yamaker.

LIBRARY()

OWNER(
    somov
    g:cpp-contrib
)

LICENSE(Apache-2.0)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/restricted/abseil-cpp-tstring/y_absl/base/internal/raw_logging
    contrib/restricted/abseil-cpp-tstring/y_absl/base/internal/spinlock_wait
    contrib/restricted/abseil-cpp-tstring/y_absl/base/log_severity
)

ADDINCL( 
    GLOBAL contrib/restricted/abseil-cpp-tstring 
) 

NO_COMPILER_WARNINGS()

SRCS(
    internal/cycleclock.cc
    internal/spinlock.cc
    internal/sysinfo.cc
    internal/thread_identity.cc
    internal/unscaledcycleclock.cc
)

END()
