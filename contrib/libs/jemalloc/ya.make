# Generated by devtools/yamaker from nixpkgs 21.11.

LIBRARY()
 
OWNER(
    g:contrib
    g:cpp-contrib
)
 
VERSION(5.2.1)

ORIGINAL_SOURCE(https://github.com/jemalloc/jemalloc/releases/download/5.2.1/jemalloc-5.2.1.tar.bz2)

LICENSE(
    BSD-2-Clause AND
    Public-Domain
)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

ADDINCL(
    contrib/libs/jemalloc/include
    contrib/libs/libunwind/include
)

IF (OS_WINDOWS)
    ADDINCL(
        contrib/libs/jemalloc/include/msvc_compat
    )
ELSE()
    CFLAGS(
        -funroll-loops
    )
    IF (OS_DARWIN OR OS_IOS)
        SRCS(
            GLOBAL reg_zone.cpp
            src/zone.c
        )
    ELSE()
        PEERDIR(
            contrib/libs/libunwind
        )
        CFLAGS(
            -fvisibility=hidden
        )
    ENDIF()
ENDIF()

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    hack.cpp
    src/arena.c
    src/background_thread.c
    src/base.c
    src/bin.c
    src/bitmap.c
    src/ckh.c
    src/ctl.c
    src/div.c
    src/extent.c
    src/extent_dss.c
    src/extent_mmap.c
    src/hash.c
    src/hook.c
    src/jemalloc.c
    src/jemalloc_cpp.cpp
    src/large.c
    src/log.c
    src/malloc_io.c
    src/mutex.c
    src/mutex_pool.c
    src/nstime.c
    src/pages.c
    src/prng.c
    src/prof.c
    src/rtree.c
    src/safety_check.c
    src/sc.c
    src/stats.c
    src/sz.c
    src/tcache.c
    src/test_hooks.c
    src/ticker.c
    src/tsd.c
    src/witness.c
)

END()
