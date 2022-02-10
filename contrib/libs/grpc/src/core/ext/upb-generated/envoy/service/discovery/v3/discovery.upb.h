/* This file was generated by upbc (the upb compiler) from the input 
 * file: 
 * 
 *     envoy/service/discovery/v3/discovery.proto 
 * 
 * Do not edit -- your changes will be discarded when the file is 
 * regenerated. */ 
 
#ifndef ENVOY_SERVICE_DISCOVERY_V3_DISCOVERY_PROTO_UPB_H_ 
#define ENVOY_SERVICE_DISCOVERY_V3_DISCOVERY_PROTO_UPB_H_ 
 
#include "upb/msg.h" 
#include "upb/decode.h" 
#include "upb/encode.h" 
 
#include "upb/port_def.inc" 
 
#ifdef __cplusplus 
extern "C" { 
#endif 
 
struct envoy_service_discovery_v3_DiscoveryRequest; 
struct envoy_service_discovery_v3_DiscoveryResponse; 
struct envoy_service_discovery_v3_DeltaDiscoveryRequest; 
struct envoy_service_discovery_v3_DeltaDiscoveryRequest_InitialResourceVersionsEntry; 
struct envoy_service_discovery_v3_DeltaDiscoveryResponse; 
struct envoy_service_discovery_v3_Resource; 
typedef struct envoy_service_discovery_v3_DiscoveryRequest envoy_service_discovery_v3_DiscoveryRequest; 
typedef struct envoy_service_discovery_v3_DiscoveryResponse envoy_service_discovery_v3_DiscoveryResponse; 
typedef struct envoy_service_discovery_v3_DeltaDiscoveryRequest envoy_service_discovery_v3_DeltaDiscoveryRequest; 
typedef struct envoy_service_discovery_v3_DeltaDiscoveryRequest_InitialResourceVersionsEntry envoy_service_discovery_v3_DeltaDiscoveryRequest_InitialResourceVersionsEntry; 
typedef struct envoy_service_discovery_v3_DeltaDiscoveryResponse envoy_service_discovery_v3_DeltaDiscoveryResponse; 
typedef struct envoy_service_discovery_v3_Resource envoy_service_discovery_v3_Resource; 
extern const upb_msglayout envoy_service_discovery_v3_DiscoveryRequest_msginit; 
extern const upb_msglayout envoy_service_discovery_v3_DiscoveryResponse_msginit; 
extern const upb_msglayout envoy_service_discovery_v3_DeltaDiscoveryRequest_msginit; 
extern const upb_msglayout envoy_service_discovery_v3_DeltaDiscoveryRequest_InitialResourceVersionsEntry_msginit; 
extern const upb_msglayout envoy_service_discovery_v3_DeltaDiscoveryResponse_msginit; 
extern const upb_msglayout envoy_service_discovery_v3_Resource_msginit; 
struct envoy_config_core_v3_ControlPlane; 
struct envoy_config_core_v3_Node; 
struct google_protobuf_Any; 
struct google_rpc_Status; 
struct udpa_core_v1_ResourceLocator; 
struct udpa_core_v1_ResourceName; 
extern const upb_msglayout envoy_config_core_v3_ControlPlane_msginit; 
extern const upb_msglayout envoy_config_core_v3_Node_msginit; 
extern const upb_msglayout google_protobuf_Any_msginit; 
extern const upb_msglayout google_rpc_Status_msginit; 
extern const upb_msglayout udpa_core_v1_ResourceLocator_msginit; 
extern const upb_msglayout udpa_core_v1_ResourceName_msginit; 
 
 
/* envoy.service.discovery.v3.DiscoveryRequest */ 
 
UPB_INLINE envoy_service_discovery_v3_DiscoveryRequest *envoy_service_discovery_v3_DiscoveryRequest_new(upb_arena *arena) { 
  return (envoy_service_discovery_v3_DiscoveryRequest *)_upb_msg_new(&envoy_service_discovery_v3_DiscoveryRequest_msginit, arena); 
} 
UPB_INLINE envoy_service_discovery_v3_DiscoveryRequest *envoy_service_discovery_v3_DiscoveryRequest_parse(const char *buf, size_t size, 
                        upb_arena *arena) { 
  envoy_service_discovery_v3_DiscoveryRequest *ret = envoy_service_discovery_v3_DiscoveryRequest_new(arena); 
  return (ret && upb_decode(buf, size, ret, &envoy_service_discovery_v3_DiscoveryRequest_msginit, arena)) ? ret : NULL; 
} 
UPB_INLINE char *envoy_service_discovery_v3_DiscoveryRequest_serialize(const envoy_service_discovery_v3_DiscoveryRequest *msg, upb_arena *arena, size_t *len) { 
  return upb_encode(msg, &envoy_service_discovery_v3_DiscoveryRequest_msginit, arena, len); 
} 
 
UPB_INLINE upb_strview envoy_service_discovery_v3_DiscoveryRequest_version_info(const envoy_service_discovery_v3_DiscoveryRequest *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_strview); } 
UPB_INLINE bool envoy_service_discovery_v3_DiscoveryRequest_has_node(const envoy_service_discovery_v3_DiscoveryRequest *msg) { return _upb_has_submsg_nohasbit(msg, UPB_SIZE(24, 48)); } 
UPB_INLINE const struct envoy_config_core_v3_Node* envoy_service_discovery_v3_DiscoveryRequest_node(const envoy_service_discovery_v3_DiscoveryRequest *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(24, 48), const struct envoy_config_core_v3_Node*); } 
UPB_INLINE upb_strview const* envoy_service_discovery_v3_DiscoveryRequest_resource_names(const envoy_service_discovery_v3_DiscoveryRequest *msg, size_t *len) { return (upb_strview const*)_upb_array_accessor(msg, UPB_SIZE(32, 64), len); } 
UPB_INLINE upb_strview envoy_service_discovery_v3_DiscoveryRequest_type_url(const envoy_service_discovery_v3_DiscoveryRequest *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(8, 16), upb_strview); } 
UPB_INLINE upb_strview envoy_service_discovery_v3_DiscoveryRequest_response_nonce(const envoy_service_discovery_v3_DiscoveryRequest *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(16, 32), upb_strview); } 
UPB_INLINE bool envoy_service_discovery_v3_DiscoveryRequest_has_error_detail(const envoy_service_discovery_v3_DiscoveryRequest *msg) { return _upb_has_submsg_nohasbit(msg, UPB_SIZE(28, 56)); } 
UPB_INLINE const struct google_rpc_Status* envoy_service_discovery_v3_DiscoveryRequest_error_detail(const envoy_service_discovery_v3_DiscoveryRequest *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(28, 56), const struct google_rpc_Status*); } 
 
UPB_INLINE void envoy_service_discovery_v3_DiscoveryRequest_set_version_info(envoy_service_discovery_v3_DiscoveryRequest *msg, upb_strview value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_strview) = value; 
} 
UPB_INLINE void envoy_service_discovery_v3_DiscoveryRequest_set_node(envoy_service_discovery_v3_DiscoveryRequest *msg, struct envoy_config_core_v3_Node* value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(24, 48), struct envoy_config_core_v3_Node*) = value; 
} 
UPB_INLINE struct envoy_config_core_v3_Node* envoy_service_discovery_v3_DiscoveryRequest_mutable_node(envoy_service_discovery_v3_DiscoveryRequest *msg, upb_arena *arena) { 
  struct envoy_config_core_v3_Node* sub = (struct envoy_config_core_v3_Node*)envoy_service_discovery_v3_DiscoveryRequest_node(msg); 
  if (sub == NULL) { 
    sub = (struct envoy_config_core_v3_Node*)_upb_msg_new(&envoy_config_core_v3_Node_msginit, arena); 
    if (!sub) return NULL; 
    envoy_service_discovery_v3_DiscoveryRequest_set_node(msg, sub); 
  } 
  return sub; 
} 
UPB_INLINE upb_strview* envoy_service_discovery_v3_DiscoveryRequest_mutable_resource_names(envoy_service_discovery_v3_DiscoveryRequest *msg, size_t *len) { 
  return (upb_strview*)_upb_array_mutable_accessor(msg, UPB_SIZE(32, 64), len); 
} 
UPB_INLINE upb_strview* envoy_service_discovery_v3_DiscoveryRequest_resize_resource_names(envoy_service_discovery_v3_DiscoveryRequest *msg, size_t len, upb_arena *arena) { 
  return (upb_strview*)_upb_array_resize_accessor(msg, UPB_SIZE(32, 64), len, UPB_TYPE_STRING, arena); 
} 
UPB_INLINE bool envoy_service_discovery_v3_DiscoveryRequest_add_resource_names(envoy_service_discovery_v3_DiscoveryRequest *msg, upb_strview val, upb_arena *arena) { 
  return _upb_array_append_accessor(msg, UPB_SIZE(32, 64), UPB_SIZE(8, 16), UPB_TYPE_STRING, &val, 
      arena); 
} 
UPB_INLINE void envoy_service_discovery_v3_DiscoveryRequest_set_type_url(envoy_service_discovery_v3_DiscoveryRequest *msg, upb_strview value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(8, 16), upb_strview) = value; 
} 
UPB_INLINE void envoy_service_discovery_v3_DiscoveryRequest_set_response_nonce(envoy_service_discovery_v3_DiscoveryRequest *msg, upb_strview value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(16, 32), upb_strview) = value; 
} 
UPB_INLINE void envoy_service_discovery_v3_DiscoveryRequest_set_error_detail(envoy_service_discovery_v3_DiscoveryRequest *msg, struct google_rpc_Status* value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(28, 56), struct google_rpc_Status*) = value; 
} 
UPB_INLINE struct google_rpc_Status* envoy_service_discovery_v3_DiscoveryRequest_mutable_error_detail(envoy_service_discovery_v3_DiscoveryRequest *msg, upb_arena *arena) { 
  struct google_rpc_Status* sub = (struct google_rpc_Status*)envoy_service_discovery_v3_DiscoveryRequest_error_detail(msg); 
  if (sub == NULL) { 
    sub = (struct google_rpc_Status*)_upb_msg_new(&google_rpc_Status_msginit, arena); 
    if (!sub) return NULL; 
    envoy_service_discovery_v3_DiscoveryRequest_set_error_detail(msg, sub); 
  } 
  return sub; 
} 
 
/* envoy.service.discovery.v3.DiscoveryResponse */ 
 
UPB_INLINE envoy_service_discovery_v3_DiscoveryResponse *envoy_service_discovery_v3_DiscoveryResponse_new(upb_arena *arena) { 
  return (envoy_service_discovery_v3_DiscoveryResponse *)_upb_msg_new(&envoy_service_discovery_v3_DiscoveryResponse_msginit, arena); 
} 
UPB_INLINE envoy_service_discovery_v3_DiscoveryResponse *envoy_service_discovery_v3_DiscoveryResponse_parse(const char *buf, size_t size, 
                        upb_arena *arena) { 
  envoy_service_discovery_v3_DiscoveryResponse *ret = envoy_service_discovery_v3_DiscoveryResponse_new(arena); 
  return (ret && upb_decode(buf, size, ret, &envoy_service_discovery_v3_DiscoveryResponse_msginit, arena)) ? ret : NULL; 
} 
UPB_INLINE char *envoy_service_discovery_v3_DiscoveryResponse_serialize(const envoy_service_discovery_v3_DiscoveryResponse *msg, upb_arena *arena, size_t *len) { 
  return upb_encode(msg, &envoy_service_discovery_v3_DiscoveryResponse_msginit, arena, len); 
} 
 
UPB_INLINE upb_strview envoy_service_discovery_v3_DiscoveryResponse_version_info(const envoy_service_discovery_v3_DiscoveryResponse *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(4, 8), upb_strview); } 
UPB_INLINE bool envoy_service_discovery_v3_DiscoveryResponse_has_resources(const envoy_service_discovery_v3_DiscoveryResponse *msg) { return _upb_has_submsg_nohasbit(msg, UPB_SIZE(32, 64)); } 
UPB_INLINE const struct google_protobuf_Any* const* envoy_service_discovery_v3_DiscoveryResponse_resources(const envoy_service_discovery_v3_DiscoveryResponse *msg, size_t *len) { return (const struct google_protobuf_Any* const*)_upb_array_accessor(msg, UPB_SIZE(32, 64), len); } 
UPB_INLINE bool envoy_service_discovery_v3_DiscoveryResponse_canary(const envoy_service_discovery_v3_DiscoveryResponse *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), bool); } 
UPB_INLINE upb_strview envoy_service_discovery_v3_DiscoveryResponse_type_url(const envoy_service_discovery_v3_DiscoveryResponse *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(12, 24), upb_strview); } 
UPB_INLINE upb_strview envoy_service_discovery_v3_DiscoveryResponse_nonce(const envoy_service_discovery_v3_DiscoveryResponse *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(20, 40), upb_strview); } 
UPB_INLINE bool envoy_service_discovery_v3_DiscoveryResponse_has_control_plane(const envoy_service_discovery_v3_DiscoveryResponse *msg) { return _upb_has_submsg_nohasbit(msg, UPB_SIZE(28, 56)); } 
UPB_INLINE const struct envoy_config_core_v3_ControlPlane* envoy_service_discovery_v3_DiscoveryResponse_control_plane(const envoy_service_discovery_v3_DiscoveryResponse *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(28, 56), const struct envoy_config_core_v3_ControlPlane*); } 
 
UPB_INLINE void envoy_service_discovery_v3_DiscoveryResponse_set_version_info(envoy_service_discovery_v3_DiscoveryResponse *msg, upb_strview value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(4, 8), upb_strview) = value; 
} 
UPB_INLINE struct google_protobuf_Any** envoy_service_discovery_v3_DiscoveryResponse_mutable_resources(envoy_service_discovery_v3_DiscoveryResponse *msg, size_t *len) { 
  return (struct google_protobuf_Any**)_upb_array_mutable_accessor(msg, UPB_SIZE(32, 64), len); 
} 
UPB_INLINE struct google_protobuf_Any** envoy_service_discovery_v3_DiscoveryResponse_resize_resources(envoy_service_discovery_v3_DiscoveryResponse *msg, size_t len, upb_arena *arena) { 
  return (struct google_protobuf_Any**)_upb_array_resize_accessor(msg, UPB_SIZE(32, 64), len, UPB_TYPE_MESSAGE, arena); 
} 
UPB_INLINE struct google_protobuf_Any* envoy_service_discovery_v3_DiscoveryResponse_add_resources(envoy_service_discovery_v3_DiscoveryResponse *msg, upb_arena *arena) { 
  struct google_protobuf_Any* sub = (struct google_protobuf_Any*)_upb_msg_new(&google_protobuf_Any_msginit, arena); 
  bool ok = _upb_array_append_accessor( 
      msg, UPB_SIZE(32, 64), UPB_SIZE(4, 8), UPB_TYPE_MESSAGE, &sub, arena); 
  if (!ok) return NULL; 
  return sub; 
} 
UPB_INLINE void envoy_service_discovery_v3_DiscoveryResponse_set_canary(envoy_service_discovery_v3_DiscoveryResponse *msg, bool value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(0, 0), bool) = value; 
} 
UPB_INLINE void envoy_service_discovery_v3_DiscoveryResponse_set_type_url(envoy_service_discovery_v3_DiscoveryResponse *msg, upb_strview value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(12, 24), upb_strview) = value; 
} 
UPB_INLINE void envoy_service_discovery_v3_DiscoveryResponse_set_nonce(envoy_service_discovery_v3_DiscoveryResponse *msg, upb_strview value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(20, 40), upb_strview) = value; 
} 
UPB_INLINE void envoy_service_discovery_v3_DiscoveryResponse_set_control_plane(envoy_service_discovery_v3_DiscoveryResponse *msg, struct envoy_config_core_v3_ControlPlane* value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(28, 56), struct envoy_config_core_v3_ControlPlane*) = value; 
} 
UPB_INLINE struct envoy_config_core_v3_ControlPlane* envoy_service_discovery_v3_DiscoveryResponse_mutable_control_plane(envoy_service_discovery_v3_DiscoveryResponse *msg, upb_arena *arena) { 
  struct envoy_config_core_v3_ControlPlane* sub = (struct envoy_config_core_v3_ControlPlane*)envoy_service_discovery_v3_DiscoveryResponse_control_plane(msg); 
  if (sub == NULL) { 
    sub = (struct envoy_config_core_v3_ControlPlane*)_upb_msg_new(&envoy_config_core_v3_ControlPlane_msginit, arena); 
    if (!sub) return NULL; 
    envoy_service_discovery_v3_DiscoveryResponse_set_control_plane(msg, sub); 
  } 
  return sub; 
} 
 
/* envoy.service.discovery.v3.DeltaDiscoveryRequest */ 
 
UPB_INLINE envoy_service_discovery_v3_DeltaDiscoveryRequest *envoy_service_discovery_v3_DeltaDiscoveryRequest_new(upb_arena *arena) { 
  return (envoy_service_discovery_v3_DeltaDiscoveryRequest *)_upb_msg_new(&envoy_service_discovery_v3_DeltaDiscoveryRequest_msginit, arena); 
} 
UPB_INLINE envoy_service_discovery_v3_DeltaDiscoveryRequest *envoy_service_discovery_v3_DeltaDiscoveryRequest_parse(const char *buf, size_t size, 
                        upb_arena *arena) { 
  envoy_service_discovery_v3_DeltaDiscoveryRequest *ret = envoy_service_discovery_v3_DeltaDiscoveryRequest_new(arena); 
  return (ret && upb_decode(buf, size, ret, &envoy_service_discovery_v3_DeltaDiscoveryRequest_msginit, arena)) ? ret : NULL; 
} 
UPB_INLINE char *envoy_service_discovery_v3_DeltaDiscoveryRequest_serialize(const envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, upb_arena *arena, size_t *len) { 
  return upb_encode(msg, &envoy_service_discovery_v3_DeltaDiscoveryRequest_msginit, arena, len); 
} 
 
UPB_INLINE bool envoy_service_discovery_v3_DeltaDiscoveryRequest_has_node(const envoy_service_discovery_v3_DeltaDiscoveryRequest *msg) { return _upb_has_submsg_nohasbit(msg, UPB_SIZE(16, 32)); } 
UPB_INLINE const struct envoy_config_core_v3_Node* envoy_service_discovery_v3_DeltaDiscoveryRequest_node(const envoy_service_discovery_v3_DeltaDiscoveryRequest *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(16, 32), const struct envoy_config_core_v3_Node*); } 
UPB_INLINE upb_strview envoy_service_discovery_v3_DeltaDiscoveryRequest_type_url(const envoy_service_discovery_v3_DeltaDiscoveryRequest *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_strview); } 
UPB_INLINE upb_strview const* envoy_service_discovery_v3_DeltaDiscoveryRequest_resource_names_subscribe(const envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, size_t *len) { return (upb_strview const*)_upb_array_accessor(msg, UPB_SIZE(24, 48), len); } 
UPB_INLINE upb_strview const* envoy_service_discovery_v3_DeltaDiscoveryRequest_resource_names_unsubscribe(const envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, size_t *len) { return (upb_strview const*)_upb_array_accessor(msg, UPB_SIZE(28, 56), len); } 
UPB_INLINE bool envoy_service_discovery_v3_DeltaDiscoveryRequest_has_initial_resource_versions(const envoy_service_discovery_v3_DeltaDiscoveryRequest *msg) { return _upb_has_submsg_nohasbit(msg, UPB_SIZE(32, 64)); } 
UPB_INLINE size_t envoy_service_discovery_v3_DeltaDiscoveryRequest_initial_resource_versions_size(const envoy_service_discovery_v3_DeltaDiscoveryRequest *msg) {return _upb_msg_map_size(msg, UPB_SIZE(32, 64)); } 
UPB_INLINE bool envoy_service_discovery_v3_DeltaDiscoveryRequest_initial_resource_versions_get(const envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, upb_strview key, upb_strview *val) { return _upb_msg_map_get(msg, UPB_SIZE(32, 64), &key, 0, val, 0); } 
UPB_INLINE const envoy_service_discovery_v3_DeltaDiscoveryRequest_InitialResourceVersionsEntry* envoy_service_discovery_v3_DeltaDiscoveryRequest_initial_resource_versions_next(const envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, size_t* iter) { return (const envoy_service_discovery_v3_DeltaDiscoveryRequest_InitialResourceVersionsEntry*)_upb_msg_map_next(msg, UPB_SIZE(32, 64), iter); } 
UPB_INLINE upb_strview envoy_service_discovery_v3_DeltaDiscoveryRequest_response_nonce(const envoy_service_discovery_v3_DeltaDiscoveryRequest *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(8, 16), upb_strview); } 
UPB_INLINE bool envoy_service_discovery_v3_DeltaDiscoveryRequest_has_error_detail(const envoy_service_discovery_v3_DeltaDiscoveryRequest *msg) { return _upb_has_submsg_nohasbit(msg, UPB_SIZE(20, 40)); } 
UPB_INLINE const struct google_rpc_Status* envoy_service_discovery_v3_DeltaDiscoveryRequest_error_detail(const envoy_service_discovery_v3_DeltaDiscoveryRequest *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(20, 40), const struct google_rpc_Status*); } 
UPB_INLINE bool envoy_service_discovery_v3_DeltaDiscoveryRequest_has_udpa_resources_subscribe(const envoy_service_discovery_v3_DeltaDiscoveryRequest *msg) { return _upb_has_submsg_nohasbit(msg, UPB_SIZE(36, 72)); } 
UPB_INLINE const struct udpa_core_v1_ResourceLocator* const* envoy_service_discovery_v3_DeltaDiscoveryRequest_udpa_resources_subscribe(const envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, size_t *len) { return (const struct udpa_core_v1_ResourceLocator* const*)_upb_array_accessor(msg, UPB_SIZE(36, 72), len); } 
UPB_INLINE bool envoy_service_discovery_v3_DeltaDiscoveryRequest_has_udpa_resources_unsubscribe(const envoy_service_discovery_v3_DeltaDiscoveryRequest *msg) { return _upb_has_submsg_nohasbit(msg, UPB_SIZE(40, 80)); } 
UPB_INLINE const struct udpa_core_v1_ResourceLocator* const* envoy_service_discovery_v3_DeltaDiscoveryRequest_udpa_resources_unsubscribe(const envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, size_t *len) { return (const struct udpa_core_v1_ResourceLocator* const*)_upb_array_accessor(msg, UPB_SIZE(40, 80), len); } 
 
UPB_INLINE void envoy_service_discovery_v3_DeltaDiscoveryRequest_set_node(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, struct envoy_config_core_v3_Node* value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(16, 32), struct envoy_config_core_v3_Node*) = value; 
} 
UPB_INLINE struct envoy_config_core_v3_Node* envoy_service_discovery_v3_DeltaDiscoveryRequest_mutable_node(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, upb_arena *arena) { 
  struct envoy_config_core_v3_Node* sub = (struct envoy_config_core_v3_Node*)envoy_service_discovery_v3_DeltaDiscoveryRequest_node(msg); 
  if (sub == NULL) { 
    sub = (struct envoy_config_core_v3_Node*)_upb_msg_new(&envoy_config_core_v3_Node_msginit, arena); 
    if (!sub) return NULL; 
    envoy_service_discovery_v3_DeltaDiscoveryRequest_set_node(msg, sub); 
  } 
  return sub; 
} 
UPB_INLINE void envoy_service_discovery_v3_DeltaDiscoveryRequest_set_type_url(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, upb_strview value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_strview) = value; 
} 
UPB_INLINE upb_strview* envoy_service_discovery_v3_DeltaDiscoveryRequest_mutable_resource_names_subscribe(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, size_t *len) { 
  return (upb_strview*)_upb_array_mutable_accessor(msg, UPB_SIZE(24, 48), len); 
} 
UPB_INLINE upb_strview* envoy_service_discovery_v3_DeltaDiscoveryRequest_resize_resource_names_subscribe(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, size_t len, upb_arena *arena) { 
  return (upb_strview*)_upb_array_resize_accessor(msg, UPB_SIZE(24, 48), len, UPB_TYPE_STRING, arena); 
} 
UPB_INLINE bool envoy_service_discovery_v3_DeltaDiscoveryRequest_add_resource_names_subscribe(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, upb_strview val, upb_arena *arena) { 
  return _upb_array_append_accessor(msg, UPB_SIZE(24, 48), UPB_SIZE(8, 16), UPB_TYPE_STRING, &val, 
      arena); 
} 
UPB_INLINE upb_strview* envoy_service_discovery_v3_DeltaDiscoveryRequest_mutable_resource_names_unsubscribe(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, size_t *len) { 
  return (upb_strview*)_upb_array_mutable_accessor(msg, UPB_SIZE(28, 56), len); 
} 
UPB_INLINE upb_strview* envoy_service_discovery_v3_DeltaDiscoveryRequest_resize_resource_names_unsubscribe(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, size_t len, upb_arena *arena) { 
  return (upb_strview*)_upb_array_resize_accessor(msg, UPB_SIZE(28, 56), len, UPB_TYPE_STRING, arena); 
} 
UPB_INLINE bool envoy_service_discovery_v3_DeltaDiscoveryRequest_add_resource_names_unsubscribe(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, upb_strview val, upb_arena *arena) { 
  return _upb_array_append_accessor(msg, UPB_SIZE(28, 56), UPB_SIZE(8, 16), UPB_TYPE_STRING, &val, 
      arena); 
} 
UPB_INLINE void envoy_service_discovery_v3_DeltaDiscoveryRequest_initial_resource_versions_clear(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg) { _upb_msg_map_clear(msg, UPB_SIZE(32, 64)); } 
UPB_INLINE bool envoy_service_discovery_v3_DeltaDiscoveryRequest_initial_resource_versions_set(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, upb_strview key, upb_strview val, upb_arena *a) { return _upb_msg_map_set(msg, UPB_SIZE(32, 64), &key, 0, &val, 0, a); } 
UPB_INLINE bool envoy_service_discovery_v3_DeltaDiscoveryRequest_initial_resource_versions_delete(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, upb_strview key) { return _upb_msg_map_delete(msg, UPB_SIZE(32, 64), &key, 0); } 
UPB_INLINE envoy_service_discovery_v3_DeltaDiscoveryRequest_InitialResourceVersionsEntry* envoy_service_discovery_v3_DeltaDiscoveryRequest_initial_resource_versions_nextmutable(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, size_t* iter) { return (envoy_service_discovery_v3_DeltaDiscoveryRequest_InitialResourceVersionsEntry*)_upb_msg_map_next(msg, UPB_SIZE(32, 64), iter); } 
UPB_INLINE void envoy_service_discovery_v3_DeltaDiscoveryRequest_set_response_nonce(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, upb_strview value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(8, 16), upb_strview) = value; 
} 
UPB_INLINE void envoy_service_discovery_v3_DeltaDiscoveryRequest_set_error_detail(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, struct google_rpc_Status* value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(20, 40), struct google_rpc_Status*) = value; 
} 
UPB_INLINE struct google_rpc_Status* envoy_service_discovery_v3_DeltaDiscoveryRequest_mutable_error_detail(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, upb_arena *arena) { 
  struct google_rpc_Status* sub = (struct google_rpc_Status*)envoy_service_discovery_v3_DeltaDiscoveryRequest_error_detail(msg); 
  if (sub == NULL) { 
    sub = (struct google_rpc_Status*)_upb_msg_new(&google_rpc_Status_msginit, arena); 
    if (!sub) return NULL; 
    envoy_service_discovery_v3_DeltaDiscoveryRequest_set_error_detail(msg, sub); 
  } 
  return sub; 
} 
UPB_INLINE struct udpa_core_v1_ResourceLocator** envoy_service_discovery_v3_DeltaDiscoveryRequest_mutable_udpa_resources_subscribe(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, size_t *len) { 
  return (struct udpa_core_v1_ResourceLocator**)_upb_array_mutable_accessor(msg, UPB_SIZE(36, 72), len); 
} 
UPB_INLINE struct udpa_core_v1_ResourceLocator** envoy_service_discovery_v3_DeltaDiscoveryRequest_resize_udpa_resources_subscribe(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, size_t len, upb_arena *arena) { 
  return (struct udpa_core_v1_ResourceLocator**)_upb_array_resize_accessor(msg, UPB_SIZE(36, 72), len, UPB_TYPE_MESSAGE, arena); 
} 
UPB_INLINE struct udpa_core_v1_ResourceLocator* envoy_service_discovery_v3_DeltaDiscoveryRequest_add_udpa_resources_subscribe(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, upb_arena *arena) { 
  struct udpa_core_v1_ResourceLocator* sub = (struct udpa_core_v1_ResourceLocator*)_upb_msg_new(&udpa_core_v1_ResourceLocator_msginit, arena); 
  bool ok = _upb_array_append_accessor( 
      msg, UPB_SIZE(36, 72), UPB_SIZE(4, 8), UPB_TYPE_MESSAGE, &sub, arena); 
  if (!ok) return NULL; 
  return sub; 
} 
UPB_INLINE struct udpa_core_v1_ResourceLocator** envoy_service_discovery_v3_DeltaDiscoveryRequest_mutable_udpa_resources_unsubscribe(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, size_t *len) { 
  return (struct udpa_core_v1_ResourceLocator**)_upb_array_mutable_accessor(msg, UPB_SIZE(40, 80), len); 
} 
UPB_INLINE struct udpa_core_v1_ResourceLocator** envoy_service_discovery_v3_DeltaDiscoveryRequest_resize_udpa_resources_unsubscribe(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, size_t len, upb_arena *arena) { 
  return (struct udpa_core_v1_ResourceLocator**)_upb_array_resize_accessor(msg, UPB_SIZE(40, 80), len, UPB_TYPE_MESSAGE, arena); 
} 
UPB_INLINE struct udpa_core_v1_ResourceLocator* envoy_service_discovery_v3_DeltaDiscoveryRequest_add_udpa_resources_unsubscribe(envoy_service_discovery_v3_DeltaDiscoveryRequest *msg, upb_arena *arena) { 
  struct udpa_core_v1_ResourceLocator* sub = (struct udpa_core_v1_ResourceLocator*)_upb_msg_new(&udpa_core_v1_ResourceLocator_msginit, arena); 
  bool ok = _upb_array_append_accessor( 
      msg, UPB_SIZE(40, 80), UPB_SIZE(4, 8), UPB_TYPE_MESSAGE, &sub, arena); 
  if (!ok) return NULL; 
  return sub; 
} 
 
/* envoy.service.discovery.v3.DeltaDiscoveryRequest.InitialResourceVersionsEntry */ 
 
UPB_INLINE upb_strview envoy_service_discovery_v3_DeltaDiscoveryRequest_InitialResourceVersionsEntry_key(const envoy_service_discovery_v3_DeltaDiscoveryRequest_InitialResourceVersionsEntry *msg) { 
  upb_strview ret; 
  _upb_msg_map_key(msg, &ret, 0); 
  return ret; 
} 
UPB_INLINE upb_strview envoy_service_discovery_v3_DeltaDiscoveryRequest_InitialResourceVersionsEntry_value(const envoy_service_discovery_v3_DeltaDiscoveryRequest_InitialResourceVersionsEntry *msg) { 
  upb_strview ret; 
  _upb_msg_map_value(msg, &ret, 0); 
  return ret; 
} 
 
UPB_INLINE void envoy_service_discovery_v3_DeltaDiscoveryRequest_InitialResourceVersionsEntry_set_value(envoy_service_discovery_v3_DeltaDiscoveryRequest_InitialResourceVersionsEntry *msg, upb_strview value) { 
  _upb_msg_map_set_value(msg, &value, 0); 
} 
 
/* envoy.service.discovery.v3.DeltaDiscoveryResponse */ 
 
UPB_INLINE envoy_service_discovery_v3_DeltaDiscoveryResponse *envoy_service_discovery_v3_DeltaDiscoveryResponse_new(upb_arena *arena) { 
  return (envoy_service_discovery_v3_DeltaDiscoveryResponse *)_upb_msg_new(&envoy_service_discovery_v3_DeltaDiscoveryResponse_msginit, arena); 
} 
UPB_INLINE envoy_service_discovery_v3_DeltaDiscoveryResponse *envoy_service_discovery_v3_DeltaDiscoveryResponse_parse(const char *buf, size_t size, 
                        upb_arena *arena) { 
  envoy_service_discovery_v3_DeltaDiscoveryResponse *ret = envoy_service_discovery_v3_DeltaDiscoveryResponse_new(arena); 
  return (ret && upb_decode(buf, size, ret, &envoy_service_discovery_v3_DeltaDiscoveryResponse_msginit, arena)) ? ret : NULL; 
} 
UPB_INLINE char *envoy_service_discovery_v3_DeltaDiscoveryResponse_serialize(const envoy_service_discovery_v3_DeltaDiscoveryResponse *msg, upb_arena *arena, size_t *len) { 
  return upb_encode(msg, &envoy_service_discovery_v3_DeltaDiscoveryResponse_msginit, arena, len); 
} 
 
UPB_INLINE upb_strview envoy_service_discovery_v3_DeltaDiscoveryResponse_system_version_info(const envoy_service_discovery_v3_DeltaDiscoveryResponse *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_strview); } 
UPB_INLINE bool envoy_service_discovery_v3_DeltaDiscoveryResponse_has_resources(const envoy_service_discovery_v3_DeltaDiscoveryResponse *msg) { return _upb_has_submsg_nohasbit(msg, UPB_SIZE(24, 48)); } 
UPB_INLINE const envoy_service_discovery_v3_Resource* const* envoy_service_discovery_v3_DeltaDiscoveryResponse_resources(const envoy_service_discovery_v3_DeltaDiscoveryResponse *msg, size_t *len) { return (const envoy_service_discovery_v3_Resource* const*)_upb_array_accessor(msg, UPB_SIZE(24, 48), len); } 
UPB_INLINE upb_strview envoy_service_discovery_v3_DeltaDiscoveryResponse_type_url(const envoy_service_discovery_v3_DeltaDiscoveryResponse *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(8, 16), upb_strview); } 
UPB_INLINE upb_strview envoy_service_discovery_v3_DeltaDiscoveryResponse_nonce(const envoy_service_discovery_v3_DeltaDiscoveryResponse *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(16, 32), upb_strview); } 
UPB_INLINE upb_strview const* envoy_service_discovery_v3_DeltaDiscoveryResponse_removed_resources(const envoy_service_discovery_v3_DeltaDiscoveryResponse *msg, size_t *len) { return (upb_strview const*)_upb_array_accessor(msg, UPB_SIZE(28, 56), len); } 
UPB_INLINE bool envoy_service_discovery_v3_DeltaDiscoveryResponse_has_udpa_removed_resources(const envoy_service_discovery_v3_DeltaDiscoveryResponse *msg) { return _upb_has_submsg_nohasbit(msg, UPB_SIZE(32, 64)); } 
UPB_INLINE const struct udpa_core_v1_ResourceName* const* envoy_service_discovery_v3_DeltaDiscoveryResponse_udpa_removed_resources(const envoy_service_discovery_v3_DeltaDiscoveryResponse *msg, size_t *len) { return (const struct udpa_core_v1_ResourceName* const*)_upb_array_accessor(msg, UPB_SIZE(32, 64), len); } 
 
UPB_INLINE void envoy_service_discovery_v3_DeltaDiscoveryResponse_set_system_version_info(envoy_service_discovery_v3_DeltaDiscoveryResponse *msg, upb_strview value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_strview) = value; 
} 
UPB_INLINE envoy_service_discovery_v3_Resource** envoy_service_discovery_v3_DeltaDiscoveryResponse_mutable_resources(envoy_service_discovery_v3_DeltaDiscoveryResponse *msg, size_t *len) { 
  return (envoy_service_discovery_v3_Resource**)_upb_array_mutable_accessor(msg, UPB_SIZE(24, 48), len); 
} 
UPB_INLINE envoy_service_discovery_v3_Resource** envoy_service_discovery_v3_DeltaDiscoveryResponse_resize_resources(envoy_service_discovery_v3_DeltaDiscoveryResponse *msg, size_t len, upb_arena *arena) { 
  return (envoy_service_discovery_v3_Resource**)_upb_array_resize_accessor(msg, UPB_SIZE(24, 48), len, UPB_TYPE_MESSAGE, arena); 
} 
UPB_INLINE struct envoy_service_discovery_v3_Resource* envoy_service_discovery_v3_DeltaDiscoveryResponse_add_resources(envoy_service_discovery_v3_DeltaDiscoveryResponse *msg, upb_arena *arena) { 
  struct envoy_service_discovery_v3_Resource* sub = (struct envoy_service_discovery_v3_Resource*)_upb_msg_new(&envoy_service_discovery_v3_Resource_msginit, arena); 
  bool ok = _upb_array_append_accessor( 
      msg, UPB_SIZE(24, 48), UPB_SIZE(4, 8), UPB_TYPE_MESSAGE, &sub, arena); 
  if (!ok) return NULL; 
  return sub; 
} 
UPB_INLINE void envoy_service_discovery_v3_DeltaDiscoveryResponse_set_type_url(envoy_service_discovery_v3_DeltaDiscoveryResponse *msg, upb_strview value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(8, 16), upb_strview) = value; 
} 
UPB_INLINE void envoy_service_discovery_v3_DeltaDiscoveryResponse_set_nonce(envoy_service_discovery_v3_DeltaDiscoveryResponse *msg, upb_strview value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(16, 32), upb_strview) = value; 
} 
UPB_INLINE upb_strview* envoy_service_discovery_v3_DeltaDiscoveryResponse_mutable_removed_resources(envoy_service_discovery_v3_DeltaDiscoveryResponse *msg, size_t *len) { 
  return (upb_strview*)_upb_array_mutable_accessor(msg, UPB_SIZE(28, 56), len); 
} 
UPB_INLINE upb_strview* envoy_service_discovery_v3_DeltaDiscoveryResponse_resize_removed_resources(envoy_service_discovery_v3_DeltaDiscoveryResponse *msg, size_t len, upb_arena *arena) { 
  return (upb_strview*)_upb_array_resize_accessor(msg, UPB_SIZE(28, 56), len, UPB_TYPE_STRING, arena); 
} 
UPB_INLINE bool envoy_service_discovery_v3_DeltaDiscoveryResponse_add_removed_resources(envoy_service_discovery_v3_DeltaDiscoveryResponse *msg, upb_strview val, upb_arena *arena) { 
  return _upb_array_append_accessor(msg, UPB_SIZE(28, 56), UPB_SIZE(8, 16), UPB_TYPE_STRING, &val, 
      arena); 
} 
UPB_INLINE struct udpa_core_v1_ResourceName** envoy_service_discovery_v3_DeltaDiscoveryResponse_mutable_udpa_removed_resources(envoy_service_discovery_v3_DeltaDiscoveryResponse *msg, size_t *len) { 
  return (struct udpa_core_v1_ResourceName**)_upb_array_mutable_accessor(msg, UPB_SIZE(32, 64), len); 
} 
UPB_INLINE struct udpa_core_v1_ResourceName** envoy_service_discovery_v3_DeltaDiscoveryResponse_resize_udpa_removed_resources(envoy_service_discovery_v3_DeltaDiscoveryResponse *msg, size_t len, upb_arena *arena) { 
  return (struct udpa_core_v1_ResourceName**)_upb_array_resize_accessor(msg, UPB_SIZE(32, 64), len, UPB_TYPE_MESSAGE, arena); 
} 
UPB_INLINE struct udpa_core_v1_ResourceName* envoy_service_discovery_v3_DeltaDiscoveryResponse_add_udpa_removed_resources(envoy_service_discovery_v3_DeltaDiscoveryResponse *msg, upb_arena *arena) { 
  struct udpa_core_v1_ResourceName* sub = (struct udpa_core_v1_ResourceName*)_upb_msg_new(&udpa_core_v1_ResourceName_msginit, arena); 
  bool ok = _upb_array_append_accessor( 
      msg, UPB_SIZE(32, 64), UPB_SIZE(4, 8), UPB_TYPE_MESSAGE, &sub, arena); 
  if (!ok) return NULL; 
  return sub; 
} 
 
/* envoy.service.discovery.v3.Resource */ 
 
UPB_INLINE envoy_service_discovery_v3_Resource *envoy_service_discovery_v3_Resource_new(upb_arena *arena) { 
  return (envoy_service_discovery_v3_Resource *)_upb_msg_new(&envoy_service_discovery_v3_Resource_msginit, arena); 
} 
UPB_INLINE envoy_service_discovery_v3_Resource *envoy_service_discovery_v3_Resource_parse(const char *buf, size_t size, 
                        upb_arena *arena) { 
  envoy_service_discovery_v3_Resource *ret = envoy_service_discovery_v3_Resource_new(arena); 
  return (ret && upb_decode(buf, size, ret, &envoy_service_discovery_v3_Resource_msginit, arena)) ? ret : NULL; 
} 
UPB_INLINE char *envoy_service_discovery_v3_Resource_serialize(const envoy_service_discovery_v3_Resource *msg, upb_arena *arena, size_t *len) { 
  return upb_encode(msg, &envoy_service_discovery_v3_Resource_msginit, arena, len); 
} 
 
UPB_INLINE upb_strview envoy_service_discovery_v3_Resource_version(const envoy_service_discovery_v3_Resource *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_strview); } 
UPB_INLINE bool envoy_service_discovery_v3_Resource_has_resource(const envoy_service_discovery_v3_Resource *msg) { return _upb_has_submsg_nohasbit(msg, UPB_SIZE(16, 32)); } 
UPB_INLINE const struct google_protobuf_Any* envoy_service_discovery_v3_Resource_resource(const envoy_service_discovery_v3_Resource *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(16, 32), const struct google_protobuf_Any*); } 
UPB_INLINE upb_strview envoy_service_discovery_v3_Resource_name(const envoy_service_discovery_v3_Resource *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(8, 16), upb_strview); } 
UPB_INLINE upb_strview const* envoy_service_discovery_v3_Resource_aliases(const envoy_service_discovery_v3_Resource *msg, size_t *len) { return (upb_strview const*)_upb_array_accessor(msg, UPB_SIZE(24, 48), len); } 
UPB_INLINE bool envoy_service_discovery_v3_Resource_has_udpa_resource_name(const envoy_service_discovery_v3_Resource *msg) { return _upb_has_submsg_nohasbit(msg, UPB_SIZE(20, 40)); } 
UPB_INLINE const struct udpa_core_v1_ResourceName* envoy_service_discovery_v3_Resource_udpa_resource_name(const envoy_service_discovery_v3_Resource *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(20, 40), const struct udpa_core_v1_ResourceName*); } 
 
UPB_INLINE void envoy_service_discovery_v3_Resource_set_version(envoy_service_discovery_v3_Resource *msg, upb_strview value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_strview) = value; 
} 
UPB_INLINE void envoy_service_discovery_v3_Resource_set_resource(envoy_service_discovery_v3_Resource *msg, struct google_protobuf_Any* value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(16, 32), struct google_protobuf_Any*) = value; 
} 
UPB_INLINE struct google_protobuf_Any* envoy_service_discovery_v3_Resource_mutable_resource(envoy_service_discovery_v3_Resource *msg, upb_arena *arena) { 
  struct google_protobuf_Any* sub = (struct google_protobuf_Any*)envoy_service_discovery_v3_Resource_resource(msg); 
  if (sub == NULL) { 
    sub = (struct google_protobuf_Any*)_upb_msg_new(&google_protobuf_Any_msginit, arena); 
    if (!sub) return NULL; 
    envoy_service_discovery_v3_Resource_set_resource(msg, sub); 
  } 
  return sub; 
} 
UPB_INLINE void envoy_service_discovery_v3_Resource_set_name(envoy_service_discovery_v3_Resource *msg, upb_strview value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(8, 16), upb_strview) = value; 
} 
UPB_INLINE upb_strview* envoy_service_discovery_v3_Resource_mutable_aliases(envoy_service_discovery_v3_Resource *msg, size_t *len) { 
  return (upb_strview*)_upb_array_mutable_accessor(msg, UPB_SIZE(24, 48), len); 
} 
UPB_INLINE upb_strview* envoy_service_discovery_v3_Resource_resize_aliases(envoy_service_discovery_v3_Resource *msg, size_t len, upb_arena *arena) { 
  return (upb_strview*)_upb_array_resize_accessor(msg, UPB_SIZE(24, 48), len, UPB_TYPE_STRING, arena); 
} 
UPB_INLINE bool envoy_service_discovery_v3_Resource_add_aliases(envoy_service_discovery_v3_Resource *msg, upb_strview val, upb_arena *arena) { 
  return _upb_array_append_accessor(msg, UPB_SIZE(24, 48), UPB_SIZE(8, 16), UPB_TYPE_STRING, &val, 
      arena); 
} 
UPB_INLINE void envoy_service_discovery_v3_Resource_set_udpa_resource_name(envoy_service_discovery_v3_Resource *msg, struct udpa_core_v1_ResourceName* value) { 
  *UPB_PTR_AT(msg, UPB_SIZE(20, 40), struct udpa_core_v1_ResourceName*) = value; 
} 
UPB_INLINE struct udpa_core_v1_ResourceName* envoy_service_discovery_v3_Resource_mutable_udpa_resource_name(envoy_service_discovery_v3_Resource *msg, upb_arena *arena) { 
  struct udpa_core_v1_ResourceName* sub = (struct udpa_core_v1_ResourceName*)envoy_service_discovery_v3_Resource_udpa_resource_name(msg); 
  if (sub == NULL) { 
    sub = (struct udpa_core_v1_ResourceName*)_upb_msg_new(&udpa_core_v1_ResourceName_msginit, arena); 
    if (!sub) return NULL; 
    envoy_service_discovery_v3_Resource_set_udpa_resource_name(msg, sub); 
  } 
  return sub; 
} 
 
#ifdef __cplusplus 
}  /* extern "C" */ 
#endif 
 
#include "upb/port_undef.inc" 
 
#endif  /* ENVOY_SERVICE_DISCOVERY_V3_DISCOVERY_PROTO_UPB_H_ */ 
