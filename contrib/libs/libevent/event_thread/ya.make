# Generated by devtools/yamaker.

LIBRARY()

WITHOUT_LICENSE_TEXTS()

OWNER(
    dldmitry
    efmv
    kikht
    g:cpp-contrib
)

LICENSE(BSD-3-Clause) 
 
PEERDIR(
    contrib/libs/libc_compat
)

ADDINCL(
    contrib/libs/libevent
    contrib/libs/libevent/include
)

NO_COMPILER_WARNINGS()

NO_RUNTIME()

CFLAGS(
    -DHAVE_CONFIG_H
    -DEVENT__HAVE_STRLCPY=1
)

SRCDIR(contrib/libs/libevent)

IF (OS_WINDOWS)
    SRCS(
        evthread_win32.c
    )
ELSE()
    SRCS(
        evthread_pthread.c
    )
ENDIF()

END()
