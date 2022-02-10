# Generated by devtools/yamaker.

LIBRARY()

WITHOUT_LICENSE_TEXTS()

OWNER(g:cpp-contrib)

LICENSE(Apache-2.0) 
 
PEERDIR(
    contrib/libs/grpc/grpc
    contrib/libs/grpc/src/core/lib
    contrib/libs/grpc/third_party/address_sorting
    contrib/libs/grpc/third_party/upb
    contrib/libs/openssl
    contrib/restricted/abseil-cpp-tstring/y_absl/strings
)

ADDINCL(
    GLOBAL contrib/libs/grpc/include
    ${ARCADIA_BUILD_ROOT}/contrib/libs/grpc
    contrib/libs/grpc
    contrib/libs/grpc/src/core/ext/upb-generated
    contrib/libs/grpc/third_party/upb
)

NO_COMPILER_WARNINGS()

SRCDIR(contrib/libs/grpc/src/cpp)

IF (OS_LINUX OR OS_DARWIN)
    CFLAGS(
        -DGRPC_POSIX_FORK_ALLOW_PTHREAD_ATFORK=1
    )
ENDIF()

SRCS(
    client/channel_cc.cc
    client/client_callback.cc
    client/client_context.cc
    client/client_interceptor.cc
    client/create_channel.cc
    client/create_channel_internal.cc
    client/create_channel_posix.cc
    client/credentials_cc.cc
    client/insecure_credentials.cc
    client/secure_credentials.cc
    codegen/codegen_init.cc
    common/alarm.cc
    common/auth_property_iterator.cc
    common/channel_arguments.cc
    common/channel_filter.cc
    common/completion_queue_cc.cc
    common/core_codegen.cc
    common/resource_quota_cc.cc
    common/rpc_method.cc
    common/secure_auth_context.cc
    common/secure_channel_arguments.cc
    common/secure_create_auth_context.cc
    common/tls_credentials_options.cc
    common/tls_credentials_options_util.cc
    common/validate_service_config.cc
    common/version_cc.cc
    server/async_generic_service.cc
    server/channel_argument_option.cc
    server/create_default_thread_pool.cc
    server/dynamic_thread_pool.cc
    server/external_connection_acceptor_impl.cc
    server/health/default_health_check_service.cc
    server/health/health_check_service.cc
    server/health/health_check_service_server_builder_option.cc
    server/insecure_server_credentials.cc
    server/load_reporter/get_cpu_stats_linux.cc
    server/load_reporter/get_cpu_stats_macos.cc
    server/load_reporter/get_cpu_stats_unsupported.cc
    server/load_reporter/get_cpu_stats_windows.cc
    server/load_reporter/load_data_store.cc
    server/load_reporter/util.cc
    server/secure_server_credentials.cc
    server/server_builder.cc
    server/server_callback.cc
    server/server_cc.cc
    server/server_context.cc
    server/server_credentials.cc
    server/server_posix.cc
    thread_manager/thread_manager.cc
    util/byte_buffer_cc.cc
    util/status.cc
    util/string_ref.cc
    util/time_cc.cc
)

END()
