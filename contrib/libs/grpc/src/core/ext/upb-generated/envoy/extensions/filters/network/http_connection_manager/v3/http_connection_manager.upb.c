/* This file was generated by upbc (the upb compiler) from the input 
 * file: 
 * 
 *     envoy/extensions/filters/network/http_connection_manager/v3/http_connection_manager.proto 
 * 
 * Do not edit -- your changes will be discarded when the file is 
 * regenerated. */ 
 
#include <stddef.h> 
#include "upb/msg.h" 
#include "envoy/extensions/filters/network/http_connection_manager/v3/http_connection_manager.upb.h" 
#include "envoy/config/accesslog/v3/accesslog.upb.h" 
#include "envoy/config/core/v3/base.upb.h" 
#include "envoy/config/core/v3/config_source.upb.h" 
#include "envoy/config/core/v3/extension.upb.h" 
#include "envoy/config/core/v3/protocol.upb.h" 
#include "envoy/config/core/v3/substitution_format_string.upb.h" 
#include "envoy/config/route/v3/route.upb.h" 
#include "envoy/config/route/v3/scoped_route.upb.h" 
#include "envoy/config/trace/v3/http_tracer.upb.h" 
#include "envoy/type/tracing/v3/custom_tag.upb.h" 
#include "envoy/type/v3/percent.upb.h" 
#include "google/protobuf/any.upb.h" 
#include "google/protobuf/duration.upb.h" 
#include "google/protobuf/struct.upb.h" 
#include "google/protobuf/wrappers.upb.h" 
#include "udpa/core/v1/resource_locator.upb.h" 
#include "envoy/annotations/deprecation.upb.h" 
#include "udpa/annotations/migrate.upb.h" 
#include "udpa/annotations/security.upb.h" 
#include "udpa/annotations/status.upb.h" 
#include "udpa/annotations/versioning.upb.h" 
#include "validate/validate.upb.h" 
 
#include "upb/port_def.inc" 
 
static const upb_msglayout *const envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_submsgs[24] = { 
  &envoy_config_accesslog_v3_AccessLog_msginit, 
  &envoy_config_core_v3_Http1ProtocolOptions_msginit, 
  &envoy_config_core_v3_Http2ProtocolOptions_msginit, 
  &envoy_config_core_v3_HttpProtocolOptions_msginit, 
  &envoy_config_route_v3_RouteConfiguration_msginit, 
  &envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_InternalAddressConfig_msginit, 
  &envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_SetCurrentClientCertDetails_msginit, 
  &envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_Tracing_msginit, 
  &envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_UpgradeConfig_msginit, 
  &envoy_extensions_filters_network_http_connection_manager_v3_HttpFilter_msginit, 
  &envoy_extensions_filters_network_http_connection_manager_v3_LocalReplyConfig_msginit, 
  &envoy_extensions_filters_network_http_connection_manager_v3_Rds_msginit, 
  &envoy_extensions_filters_network_http_connection_manager_v3_RequestIDExtension_msginit, 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_msginit, 
  &google_protobuf_BoolValue_msginit, 
  &google_protobuf_Duration_msginit, 
  &google_protobuf_UInt32Value_msginit, 
}; 
 
static const upb_msglayout_field envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager__fields[38] = { 
  {1, UPB_SIZE(0, 0), 0, 0, 14, 1}, 
  {2, UPB_SIZE(36, 40), 0, 0, 9, 1}, 
  {3, UPB_SIZE(144, 256), UPB_SIZE(-149, -265), 11, 11, 1}, 
  {4, UPB_SIZE(144, 256), UPB_SIZE(-149, -265), 4, 11, 1}, 
  {5, UPB_SIZE(132, 232), 0, 9, 11, 3}, 
  {6, UPB_SIZE(60, 88), 0, 14, 11, 1}, 
  {7, UPB_SIZE(64, 96), 0, 7, 11, 1}, 
  {8, UPB_SIZE(68, 104), 0, 1, 11, 1}, 
  {9, UPB_SIZE(72, 112), 0, 2, 11, 1}, 
  {10, UPB_SIZE(44, 56), 0, 0, 9, 1}, 
  {12, UPB_SIZE(76, 120), 0, 15, 11, 1}, 
  {13, UPB_SIZE(136, 240), 0, 0, 11, 3}, 
  {14, UPB_SIZE(80, 128), 0, 14, 11, 1}, 
  {15, UPB_SIZE(84, 136), 0, 14, 11, 1}, 
  {16, UPB_SIZE(8, 8), 0, 0, 14, 1}, 
  {17, UPB_SIZE(88, 144), 0, 6, 11, 1}, 
  {18, UPB_SIZE(28, 28), 0, 0, 8, 1}, 
  {19, UPB_SIZE(24, 24), 0, 0, 13, 1}, 
  {20, UPB_SIZE(29, 29), 0, 0, 8, 1}, 
  {21, UPB_SIZE(30, 30), 0, 0, 8, 1}, 
  {22, UPB_SIZE(52, 72), 0, 0, 9, 1}, 
  {23, UPB_SIZE(140, 248), 0, 8, 11, 3}, 
  {24, UPB_SIZE(92, 152), 0, 15, 11, 1}, 
  {25, UPB_SIZE(96, 160), 0, 5, 11, 1}, 
  {26, UPB_SIZE(100, 168), 0, 15, 11, 1}, 
  {28, UPB_SIZE(104, 176), 0, 15, 11, 1}, 
  {29, UPB_SIZE(108, 184), 0, 16, 11, 1}, 
  {30, UPB_SIZE(112, 192), 0, 14, 11, 1}, 
  {31, UPB_SIZE(144, 256), UPB_SIZE(-149, -265), 13, 11, 1}, 
  {32, UPB_SIZE(31, 31), 0, 0, 8, 1}, 
  {33, UPB_SIZE(32, 32), 0, 0, 8, 1}, 
  {34, UPB_SIZE(16, 16), 0, 0, 14, 1}, 
  {35, UPB_SIZE(116, 200), 0, 3, 11, 1}, 
  {36, UPB_SIZE(120, 208), 0, 12, 11, 1}, 
  {37, UPB_SIZE(33, 33), 0, 0, 8, 1}, 
  {38, UPB_SIZE(124, 216), 0, 10, 11, 1}, 
  {39, UPB_SIZE(34, 34), 0, 0, 8, 1}, 
  {40, UPB_SIZE(128, 224), 0, 14, 11, 1}, 
}; 
 
const upb_msglayout envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_msginit = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_submsgs[0], 
  &envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager__fields[0], 
  UPB_SIZE(152, 272), 38, false, 
}; 
 
static const upb_msglayout *const envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_Tracing_submsgs[6] = { 
  &envoy_config_trace_v3_Tracing_Http_msginit, 
  &envoy_type_tracing_v3_CustomTag_msginit, 
  &envoy_type_v3_Percent_msginit, 
  &google_protobuf_UInt32Value_msginit, 
}; 
 
static const upb_msglayout_field envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_Tracing__fields[7] = { 
  {3, UPB_SIZE(4, 8), 0, 2, 11, 1}, 
  {4, UPB_SIZE(8, 16), 0, 2, 11, 1}, 
  {5, UPB_SIZE(12, 24), 0, 2, 11, 1}, 
  {6, UPB_SIZE(0, 0), 0, 0, 8, 1}, 
  {7, UPB_SIZE(16, 32), 0, 3, 11, 1}, 
  {8, UPB_SIZE(24, 48), 0, 1, 11, 3}, 
  {9, UPB_SIZE(20, 40), 0, 0, 11, 1}, 
}; 
 
const upb_msglayout envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_Tracing_msginit = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_Tracing_submsgs[0], 
  &envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_Tracing__fields[0], 
  UPB_SIZE(28, 56), 7, false, 
}; 
 
static const upb_msglayout_field envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_InternalAddressConfig__fields[1] = { 
  {1, UPB_SIZE(0, 0), 0, 0, 8, 1}, 
}; 
 
const upb_msglayout envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_InternalAddressConfig_msginit = { 
  NULL, 
  &envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_InternalAddressConfig__fields[0], 
  UPB_SIZE(1, 1), 1, false, 
}; 
 
static const upb_msglayout *const envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_SetCurrentClientCertDetails_submsgs[1] = { 
  &google_protobuf_BoolValue_msginit, 
}; 
 
static const upb_msglayout_field envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_SetCurrentClientCertDetails__fields[5] = { 
  {1, UPB_SIZE(4, 8), 0, 0, 11, 1}, 
  {3, UPB_SIZE(0, 0), 0, 0, 8, 1}, 
  {4, UPB_SIZE(1, 1), 0, 0, 8, 1}, 
  {5, UPB_SIZE(2, 2), 0, 0, 8, 1}, 
  {6, UPB_SIZE(3, 3), 0, 0, 8, 1}, 
}; 
 
const upb_msglayout envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_SetCurrentClientCertDetails_msginit = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_SetCurrentClientCertDetails_submsgs[0], 
  &envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_SetCurrentClientCertDetails__fields[0], 
  UPB_SIZE(8, 16), 5, false, 
}; 
 
static const upb_msglayout *const envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_UpgradeConfig_submsgs[2] = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_HttpFilter_msginit, 
  &google_protobuf_BoolValue_msginit, 
}; 
 
static const upb_msglayout_field envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_UpgradeConfig__fields[3] = { 
  {1, UPB_SIZE(0, 0), 0, 0, 9, 1}, 
  {2, UPB_SIZE(12, 24), 0, 0, 11, 3}, 
  {3, UPB_SIZE(8, 16), 0, 1, 11, 1}, 
}; 
 
const upb_msglayout envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_UpgradeConfig_msginit = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_UpgradeConfig_submsgs[0], 
  &envoy_extensions_filters_network_http_connection_manager_v3_HttpConnectionManager_UpgradeConfig__fields[0], 
  UPB_SIZE(16, 32), 3, false, 
}; 
 
static const upb_msglayout *const envoy_extensions_filters_network_http_connection_manager_v3_LocalReplyConfig_submsgs[2] = { 
  &envoy_config_core_v3_SubstitutionFormatString_msginit, 
  &envoy_extensions_filters_network_http_connection_manager_v3_ResponseMapper_msginit, 
}; 
 
static const upb_msglayout_field envoy_extensions_filters_network_http_connection_manager_v3_LocalReplyConfig__fields[2] = { 
  {1, UPB_SIZE(4, 8), 0, 1, 11, 3}, 
  {2, UPB_SIZE(0, 0), 0, 0, 11, 1}, 
}; 
 
const upb_msglayout envoy_extensions_filters_network_http_connection_manager_v3_LocalReplyConfig_msginit = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_LocalReplyConfig_submsgs[0], 
  &envoy_extensions_filters_network_http_connection_manager_v3_LocalReplyConfig__fields[0], 
  UPB_SIZE(8, 16), 2, false, 
}; 
 
static const upb_msglayout *const envoy_extensions_filters_network_http_connection_manager_v3_ResponseMapper_submsgs[5] = { 
  &envoy_config_accesslog_v3_AccessLogFilter_msginit, 
  &envoy_config_core_v3_DataSource_msginit, 
  &envoy_config_core_v3_HeaderValueOption_msginit, 
  &envoy_config_core_v3_SubstitutionFormatString_msginit, 
  &google_protobuf_UInt32Value_msginit, 
}; 
 
static const upb_msglayout_field envoy_extensions_filters_network_http_connection_manager_v3_ResponseMapper__fields[5] = { 
  {1, UPB_SIZE(0, 0), 0, 0, 11, 1}, 
  {2, UPB_SIZE(4, 8), 0, 4, 11, 1}, 
  {3, UPB_SIZE(8, 16), 0, 1, 11, 1}, 
  {4, UPB_SIZE(12, 24), 0, 3, 11, 1}, 
  {5, UPB_SIZE(16, 32), 0, 2, 11, 3}, 
}; 
 
const upb_msglayout envoy_extensions_filters_network_http_connection_manager_v3_ResponseMapper_msginit = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_ResponseMapper_submsgs[0], 
  &envoy_extensions_filters_network_http_connection_manager_v3_ResponseMapper__fields[0], 
  UPB_SIZE(20, 40), 5, false, 
}; 
 
static const upb_msglayout *const envoy_extensions_filters_network_http_connection_manager_v3_Rds_submsgs[2] = { 
  &envoy_config_core_v3_ConfigSource_msginit, 
  &udpa_core_v1_ResourceLocator_msginit, 
}; 
 
static const upb_msglayout_field envoy_extensions_filters_network_http_connection_manager_v3_Rds__fields[3] = { 
  {1, UPB_SIZE(8, 16), 0, 0, 11, 1}, 
  {2, UPB_SIZE(0, 0), 0, 0, 9, 1}, 
  {3, UPB_SIZE(12, 24), 0, 1, 11, 1}, 
}; 
 
const upb_msglayout envoy_extensions_filters_network_http_connection_manager_v3_Rds_msginit = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_Rds_submsgs[0], 
  &envoy_extensions_filters_network_http_connection_manager_v3_Rds__fields[0], 
  UPB_SIZE(16, 32), 3, false, 
}; 
 
static const upb_msglayout *const envoy_extensions_filters_network_http_connection_manager_v3_ScopedRouteConfigurationsList_submsgs[1] = { 
  &envoy_config_route_v3_ScopedRouteConfiguration_msginit, 
}; 
 
static const upb_msglayout_field envoy_extensions_filters_network_http_connection_manager_v3_ScopedRouteConfigurationsList__fields[1] = { 
  {1, UPB_SIZE(0, 0), 0, 0, 11, 3}, 
}; 
 
const upb_msglayout envoy_extensions_filters_network_http_connection_manager_v3_ScopedRouteConfigurationsList_msginit = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRouteConfigurationsList_submsgs[0], 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRouteConfigurationsList__fields[0], 
  UPB_SIZE(4, 8), 1, false, 
}; 
 
static const upb_msglayout *const envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_submsgs[4] = { 
  &envoy_config_core_v3_ConfigSource_msginit, 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRds_msginit, 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRouteConfigurationsList_msginit, 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_msginit, 
}; 
 
static const upb_msglayout_field envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes__fields[5] = { 
  {1, UPB_SIZE(0, 0), 0, 0, 9, 1}, 
  {2, UPB_SIZE(8, 16), 0, 3, 11, 1}, 
  {3, UPB_SIZE(12, 24), 0, 0, 11, 1}, 
  {4, UPB_SIZE(16, 32), UPB_SIZE(-21, -41), 2, 11, 1}, 
  {5, UPB_SIZE(16, 32), UPB_SIZE(-21, -41), 1, 11, 1}, 
}; 
 
const upb_msglayout envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_msginit = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_submsgs[0], 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes__fields[0], 
  UPB_SIZE(24, 48), 5, false, 
}; 
 
static const upb_msglayout *const envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_submsgs[1] = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_FragmentBuilder_msginit, 
}; 
 
static const upb_msglayout_field envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder__fields[1] = { 
  {1, UPB_SIZE(0, 0), 0, 0, 11, 3}, 
}; 
 
const upb_msglayout envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_msginit = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_submsgs[0], 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder__fields[0], 
  UPB_SIZE(4, 8), 1, false, 
}; 
 
static const upb_msglayout *const envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_FragmentBuilder_submsgs[1] = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_FragmentBuilder_HeaderValueExtractor_msginit, 
}; 
 
static const upb_msglayout_field envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_FragmentBuilder__fields[1] = { 
  {1, UPB_SIZE(0, 0), UPB_SIZE(-5, -9), 0, 11, 1}, 
}; 
 
const upb_msglayout envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_FragmentBuilder_msginit = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_FragmentBuilder_submsgs[0], 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_FragmentBuilder__fields[0], 
  UPB_SIZE(8, 16), 1, false, 
}; 
 
static const upb_msglayout *const envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_FragmentBuilder_HeaderValueExtractor_submsgs[1] = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_FragmentBuilder_HeaderValueExtractor_KvElement_msginit, 
}; 
 
static const upb_msglayout_field envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_FragmentBuilder_HeaderValueExtractor__fields[4] = { 
  {1, UPB_SIZE(0, 0), 0, 0, 9, 1}, 
  {2, UPB_SIZE(8, 16), 0, 0, 9, 1}, 
  {3, UPB_SIZE(16, 32), UPB_SIZE(-21, -41), 0, 13, 1}, 
  {4, UPB_SIZE(16, 32), UPB_SIZE(-21, -41), 0, 11, 1}, 
}; 
 
const upb_msglayout envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_FragmentBuilder_HeaderValueExtractor_msginit = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_FragmentBuilder_HeaderValueExtractor_submsgs[0], 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_FragmentBuilder_HeaderValueExtractor__fields[0], 
  UPB_SIZE(24, 48), 4, false, 
}; 
 
static const upb_msglayout_field envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_FragmentBuilder_HeaderValueExtractor_KvElement__fields[2] = { 
  {1, UPB_SIZE(0, 0), 0, 0, 9, 1}, 
  {2, UPB_SIZE(8, 16), 0, 0, 9, 1}, 
}; 
 
const upb_msglayout envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_FragmentBuilder_HeaderValueExtractor_KvElement_msginit = { 
  NULL, 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRoutes_ScopeKeyBuilder_FragmentBuilder_HeaderValueExtractor_KvElement__fields[0], 
  UPB_SIZE(16, 32), 2, false, 
}; 
 
static const upb_msglayout *const envoy_extensions_filters_network_http_connection_manager_v3_ScopedRds_submsgs[1] = { 
  &envoy_config_core_v3_ConfigSource_msginit, 
}; 
 
static const upb_msglayout_field envoy_extensions_filters_network_http_connection_manager_v3_ScopedRds__fields[1] = { 
  {1, UPB_SIZE(0, 0), 0, 0, 11, 1}, 
}; 
 
const upb_msglayout envoy_extensions_filters_network_http_connection_manager_v3_ScopedRds_msginit = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRds_submsgs[0], 
  &envoy_extensions_filters_network_http_connection_manager_v3_ScopedRds__fields[0], 
  UPB_SIZE(4, 8), 1, false, 
}; 
 
static const upb_msglayout *const envoy_extensions_filters_network_http_connection_manager_v3_HttpFilter_submsgs[2] = { 
  &envoy_config_core_v3_ExtensionConfigSource_msginit, 
  &google_protobuf_Any_msginit, 
}; 
 
static const upb_msglayout_field envoy_extensions_filters_network_http_connection_manager_v3_HttpFilter__fields[3] = { 
  {1, UPB_SIZE(0, 0), 0, 0, 9, 1}, 
  {4, UPB_SIZE(8, 16), UPB_SIZE(-13, -25), 1, 11, 1}, 
  {5, UPB_SIZE(8, 16), UPB_SIZE(-13, -25), 0, 11, 1}, 
}; 
 
const upb_msglayout envoy_extensions_filters_network_http_connection_manager_v3_HttpFilter_msginit = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_HttpFilter_submsgs[0], 
  &envoy_extensions_filters_network_http_connection_manager_v3_HttpFilter__fields[0], 
  UPB_SIZE(16, 32), 3, false, 
}; 
 
static const upb_msglayout *const envoy_extensions_filters_network_http_connection_manager_v3_RequestIDExtension_submsgs[1] = { 
  &google_protobuf_Any_msginit, 
}; 
 
static const upb_msglayout_field envoy_extensions_filters_network_http_connection_manager_v3_RequestIDExtension__fields[1] = { 
  {1, UPB_SIZE(0, 0), 0, 0, 11, 1}, 
}; 
 
const upb_msglayout envoy_extensions_filters_network_http_connection_manager_v3_RequestIDExtension_msginit = { 
  &envoy_extensions_filters_network_http_connection_manager_v3_RequestIDExtension_submsgs[0], 
  &envoy_extensions_filters_network_http_connection_manager_v3_RequestIDExtension__fields[0], 
  UPB_SIZE(4, 8), 1, false, 
}; 
 
#include "upb/port_undef.inc" 
 
