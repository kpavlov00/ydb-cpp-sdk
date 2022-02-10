LIBRARY()

LICENSE(Apache-2.0)
 
LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

OWNER(
    ayles
    prime
    g:cpp-contrib
)

# https://github.com/google/tcmalloc
VERSION(2021-10-04-45c59ccbc062ac96d83710205033c656e490d376)

SRCS(
    # Options
    tcmalloc/want_hpaa.cc
)

INCLUDE(common.inc)

CFLAGS(
    -DTCMALLOC_256K_PAGES
)

END()

IF (NOT DLL_FOR)
    RECURSE(
        default
        dynamic
        malloc_extension
        numa_256k
        numa_large_pages
        slow_but_small
    )
ENDIF()
