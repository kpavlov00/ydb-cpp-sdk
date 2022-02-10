# Generated by devtools/yamaker.

LIBRARY()

OWNER(g:cpp-contrib)

LICENSE(BSD-3-Clause)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt) 
 
ADDINCL(
    ${ARCADIA_BUILD_ROOT}/contrib/libs/grpc 
    contrib/libs/grpc
    contrib/libs/grpc/third_party/address_sorting/include
)

NO_COMPILER_WARNINGS()

NO_RUNTIME()

IF (OS_LINUX OR OS_DARWIN)
    CFLAGS( 
        -DGRPC_POSIX_FORK_ALLOW_PTHREAD_ATFORK=1 
    ) 
ENDIF()

SRCS(
    address_sorting.c
    address_sorting_posix.c
    address_sorting_windows.c
)

END()
