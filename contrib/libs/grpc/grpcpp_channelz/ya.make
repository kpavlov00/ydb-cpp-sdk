# Generated by devtools/yamaker.

LIBRARY()

WITHOUT_LICENSE_TEXTS()

OWNER(g:cpp-contrib) 

LICENSE(Apache-2.0)

PEERDIR(
    contrib/libs/grpc/grpc
    contrib/libs/grpc/grpc++
    contrib/libs/grpc/src/core/lib
    contrib/libs/grpc/src/proto/grpc/channelz
    contrib/libs/grpc/third_party/address_sorting
    contrib/libs/grpc/third_party/upb
    contrib/libs/protobuf 
)

ADDINCL(
    GLOBAL contrib/libs/grpc/include
    ${ARCADIA_BUILD_ROOT}/contrib/libs/grpc
    contrib/libs/grpc
)

NO_COMPILER_WARNINGS()

SRCDIR(contrib/libs/grpc/src)

IF (OS_LINUX OR OS_DARWIN)
    CFLAGS(
        -DGRPC_POSIX_FORK_ALLOW_PTHREAD_ATFORK=1
    )
ENDIF()

SRCS(
    cpp/server/channelz/channelz_service.cc
    cpp/server/channelz/channelz_service_plugin.cc
)

END()
