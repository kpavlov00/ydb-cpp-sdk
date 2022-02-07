/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/config/core/v3/socket_option.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef ENVOY_CONFIG_CORE_V3_SOCKET_OPTION_PROTO_UPB_H_
#define ENVOY_CONFIG_CORE_V3_SOCKET_OPTION_PROTO_UPB_H_

#include "upb/msg.h"
#include "upb/decode.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct envoy_config_core_v3_SocketOption;
typedef struct envoy_config_core_v3_SocketOption envoy_config_core_v3_SocketOption;
extern const upb_msglayout envoy_config_core_v3_SocketOption_msginit;

typedef enum {
  envoy_config_core_v3_SocketOption_STATE_PREBIND = 0,
  envoy_config_core_v3_SocketOption_STATE_BOUND = 1,
  envoy_config_core_v3_SocketOption_STATE_LISTENING = 2
} envoy_config_core_v3_SocketOption_SocketState;


/* envoy.config.core.v3.SocketOption */

UPB_INLINE envoy_config_core_v3_SocketOption *envoy_config_core_v3_SocketOption_new(upb_arena *arena) {
  return (envoy_config_core_v3_SocketOption *)_upb_msg_new(&envoy_config_core_v3_SocketOption_msginit, arena);
}
UPB_INLINE envoy_config_core_v3_SocketOption *envoy_config_core_v3_SocketOption_parse(const char *buf, size_t size,
                        upb_arena *arena) {
  envoy_config_core_v3_SocketOption *ret = envoy_config_core_v3_SocketOption_new(arena);
  return (ret && upb_decode(buf, size, ret, &envoy_config_core_v3_SocketOption_msginit, arena)) ? ret : NULL;
}
UPB_INLINE char *envoy_config_core_v3_SocketOption_serialize(const envoy_config_core_v3_SocketOption *msg, upb_arena *arena, size_t *len) {
  return upb_encode(msg, &envoy_config_core_v3_SocketOption_msginit, arena, len);
}

typedef enum {
  envoy_config_core_v3_SocketOption_value_int_value = 4,
  envoy_config_core_v3_SocketOption_value_buf_value = 5,
  envoy_config_core_v3_SocketOption_value_NOT_SET = 0
} envoy_config_core_v3_SocketOption_value_oneofcases;
UPB_INLINE envoy_config_core_v3_SocketOption_value_oneofcases envoy_config_core_v3_SocketOption_value_case(const envoy_config_core_v3_SocketOption* msg) { return (envoy_config_core_v3_SocketOption_value_oneofcases)*UPB_PTR_AT(msg, UPB_SIZE(40, 56), int32_t); }

UPB_INLINE upb_strview envoy_config_core_v3_SocketOption_description(const envoy_config_core_v3_SocketOption *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(24, 24), upb_strview); }
UPB_INLINE int64_t envoy_config_core_v3_SocketOption_level(const envoy_config_core_v3_SocketOption *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), int64_t); }
UPB_INLINE int64_t envoy_config_core_v3_SocketOption_name(const envoy_config_core_v3_SocketOption *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(8, 8), int64_t); }
UPB_INLINE bool envoy_config_core_v3_SocketOption_has_int_value(const envoy_config_core_v3_SocketOption *msg) { return _upb_getoneofcase(msg, UPB_SIZE(40, 56)) == 4; }
UPB_INLINE int64_t envoy_config_core_v3_SocketOption_int_value(const envoy_config_core_v3_SocketOption *msg) { return UPB_READ_ONEOF(msg, int64_t, UPB_SIZE(32, 40), UPB_SIZE(40, 56), 4, 0); }
UPB_INLINE bool envoy_config_core_v3_SocketOption_has_buf_value(const envoy_config_core_v3_SocketOption *msg) { return _upb_getoneofcase(msg, UPB_SIZE(40, 56)) == 5; }
UPB_INLINE upb_strview envoy_config_core_v3_SocketOption_buf_value(const envoy_config_core_v3_SocketOption *msg) { return UPB_READ_ONEOF(msg, upb_strview, UPB_SIZE(32, 40), UPB_SIZE(40, 56), 5, upb_strview_make("", strlen(""))); }
UPB_INLINE int32_t envoy_config_core_v3_SocketOption_state(const envoy_config_core_v3_SocketOption *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(16, 16), int32_t); }

UPB_INLINE void envoy_config_core_v3_SocketOption_set_description(envoy_config_core_v3_SocketOption *msg, upb_strview value) {
  *UPB_PTR_AT(msg, UPB_SIZE(24, 24), upb_strview) = value;
}
UPB_INLINE void envoy_config_core_v3_SocketOption_set_level(envoy_config_core_v3_SocketOption *msg, int64_t value) {
  *UPB_PTR_AT(msg, UPB_SIZE(0, 0), int64_t) = value;
}
UPB_INLINE void envoy_config_core_v3_SocketOption_set_name(envoy_config_core_v3_SocketOption *msg, int64_t value) {
  *UPB_PTR_AT(msg, UPB_SIZE(8, 8), int64_t) = value;
}
UPB_INLINE void envoy_config_core_v3_SocketOption_set_int_value(envoy_config_core_v3_SocketOption *msg, int64_t value) {
  UPB_WRITE_ONEOF(msg, int64_t, UPB_SIZE(32, 40), value, UPB_SIZE(40, 56), 4);
}
UPB_INLINE void envoy_config_core_v3_SocketOption_set_buf_value(envoy_config_core_v3_SocketOption *msg, upb_strview value) {
  UPB_WRITE_ONEOF(msg, upb_strview, UPB_SIZE(32, 40), value, UPB_SIZE(40, 56), 5);
}
UPB_INLINE void envoy_config_core_v3_SocketOption_set_state(envoy_config_core_v3_SocketOption *msg, int32_t value) {
  *UPB_PTR_AT(msg, UPB_SIZE(16, 16), int32_t) = value;
}

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* ENVOY_CONFIG_CORE_V3_SOCKET_OPTION_PROTO_UPB_H_ */
