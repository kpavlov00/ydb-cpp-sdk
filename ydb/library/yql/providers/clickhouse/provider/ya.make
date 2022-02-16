LIBRARY()

OWNER(g:yql)

SRCS(
    yql_clickhouse_datasink.cpp
    yql_clickhouse_datasink_execution.cpp
    yql_clickhouse_datasink_type_ann.cpp
    yql_clickhouse_datasource.cpp
    yql_clickhouse_datasource_type_ann.cpp
    yql_clickhouse_dq_integration.cpp
    yql_clickhouse_io_discovery.cpp
    yql_clickhouse_load_meta.cpp
    yql_clickhouse_logical_opt.cpp
    yql_clickhouse_mkql_compiler.cpp
    yql_clickhouse_physical_opt.cpp
    yql_clickhouse_provider.cpp
    yql_clickhouse_provider.h
    yql_clickhouse_provider_impl.h
    yql_clickhouse_settings.cpp
    yql_clickhouse_settings.h
    yql_clickhouse_util.cpp
    yql_clickhouse_util.h
)

YQL_LAST_ABI_VERSION()

PEERDIR(
    library/cpp/json
    library/cpp/random_provider
    library/cpp/time_provider
    ydb/library/yql/ast
    ydb/library/yql/minikql
    ydb/library/yql/minikql/comp_nodes
    ydb/library/yql/minikql/computation
    ydb/library/yql/core
    ydb/library/yql/core/type_ann
    ydb/library/yql/dq/expr_nodes
    ydb/library/yql/providers/common/db_id_async_resolver
    ydb/library/yql/providers/clickhouse/expr_nodes
    ydb/library/yql/providers/clickhouse/proto
    ydb/library/yql/providers/common/config
    ydb/library/yql/providers/common/dq
    ydb/library/yql/providers/common/http_gateway
    ydb/library/yql/providers/common/mkql
    ydb/library/yql/providers/common/proto
    ydb/library/yql/providers/common/provider
    ydb/library/yql/providers/common/transform
    ydb/library/yql/providers/dq/common
    ydb/library/yql/providers/dq/expr_nodes
    ydb/library/yql/providers/dq/interface
)

END()
