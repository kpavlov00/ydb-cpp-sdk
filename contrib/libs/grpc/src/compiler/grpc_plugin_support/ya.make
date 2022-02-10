# Generated by devtools/yamaker.

LIBRARY()

WITHOUT_LICENSE_TEXTS()

OWNER(g:cpp-contrib) 

LICENSE(Apache-2.0)

PEERDIR(
    contrib/libs/protobuf 
    contrib/libs/protoc 
)

ADDINCL(
    GLOBAL contrib/libs/grpc/include
    ${ARCADIA_BUILD_ROOT}/contrib/libs/grpc
    contrib/libs/grpc
)

NO_COMPILER_WARNINGS()

SRCDIR(contrib/libs/grpc/src/compiler)

IF (OS_LINUX OR OS_DARWIN)
    CFLAGS(
        -DGRPC_POSIX_FORK_ALLOW_PTHREAD_ATFORK=1
    )
ENDIF()

SRCS(
    cpp_generator.cc
    python_generator.cc
)

END()
