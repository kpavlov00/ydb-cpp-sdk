/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/config/core/v3/protocol.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg_internal.h"
#include "envoy/config/core/v3/protocol.upb.h"
#include "envoy/config/core/v3/extension.upb.h"
#include "envoy/type/v3/percent.upb.h"
#include "google/protobuf/duration.upb.h"
#include "google/protobuf/wrappers.upb.h"
#include "xds/annotations/v3/status.upb.h"
#include "envoy/annotations/deprecation.upb.h"
#include "udpa/annotations/status.upb.h"
#include "udpa/annotations/versioning.upb.h"
#include "validate/validate.upb.h"

#include "upb/port_def.inc"

const upb_MiniTable envoy_config_core_v3_TcpProtocolOptions_msginit = {
  NULL,
  NULL,
  UPB_SIZE(0, 0), 0, upb_ExtMode_NonExtendable, 0, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_core_v3_QuicKeepAliveSettings_submsgs[1] = {
  {.submsg = &google_protobuf_Duration_msginit},
};

static const upb_MiniTable_Field envoy_config_core_v3_QuicKeepAliveSettings__fields[2] = {
  {1, UPB_SIZE(4, 8), 1, 0, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {2, UPB_SIZE(8, 16), 2, 0, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_core_v3_QuicKeepAliveSettings_msginit = {
  &envoy_config_core_v3_QuicKeepAliveSettings_submsgs[0],
  &envoy_config_core_v3_QuicKeepAliveSettings__fields[0],
  UPB_SIZE(16, 24), 2, upb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_core_v3_QuicProtocolOptions_submsgs[2] = {
  {.submsg = &envoy_config_core_v3_QuicKeepAliveSettings_msginit},
  {.submsg = &google_protobuf_UInt32Value_msginit},
};

static const upb_MiniTable_Field envoy_config_core_v3_QuicProtocolOptions__fields[5] = {
  {1, UPB_SIZE(4, 8), 1, 1, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {2, UPB_SIZE(8, 16), 2, 1, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {3, UPB_SIZE(12, 24), 3, 1, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {4, UPB_SIZE(16, 32), 4, 1, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {5, UPB_SIZE(20, 40), 5, 0, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_core_v3_QuicProtocolOptions_msginit = {
  &envoy_config_core_v3_QuicProtocolOptions_submsgs[0],
  &envoy_config_core_v3_QuicProtocolOptions__fields[0],
  UPB_SIZE(24, 48), 5, upb_ExtMode_NonExtendable, 5, 255, 0,
};

static const upb_MiniTable_Field envoy_config_core_v3_UpstreamHttpProtocolOptions__fields[3] = {
  {1, UPB_SIZE(0, 0), 0, 0, 8, kUpb_FieldMode_Scalar | (upb_FieldRep_1Byte << upb_FieldRep_Shift)},
  {2, UPB_SIZE(1, 1), 0, 0, 8, kUpb_FieldMode_Scalar | (upb_FieldRep_1Byte << upb_FieldRep_Shift)},
  {3, UPB_SIZE(4, 8), 0, 0, 9, kUpb_FieldMode_Scalar | (upb_FieldRep_StringView << upb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_core_v3_UpstreamHttpProtocolOptions_msginit = {
  NULL,
  &envoy_config_core_v3_UpstreamHttpProtocolOptions__fields[0],
  UPB_SIZE(16, 32), 3, upb_ExtMode_NonExtendable, 3, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_core_v3_AlternateProtocolsCacheOptions_submsgs[3] = {
  {.submsg = &envoy_config_core_v3_AlternateProtocolsCacheOptions_AlternateProtocolsCacheEntry_msginit},
  {.submsg = &envoy_config_core_v3_TypedExtensionConfig_msginit},
  {.submsg = &google_protobuf_UInt32Value_msginit},
};

static const upb_MiniTable_Field envoy_config_core_v3_AlternateProtocolsCacheOptions__fields[4] = {
  {1, UPB_SIZE(4, 8), 0, 0, 9, kUpb_FieldMode_Scalar | (upb_FieldRep_StringView << upb_FieldRep_Shift)},
  {2, UPB_SIZE(12, 24), 1, 2, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {3, UPB_SIZE(16, 32), 2, 1, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {4, UPB_SIZE(20, 40), 0, 0, 11, kUpb_FieldMode_Array | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_core_v3_AlternateProtocolsCacheOptions_msginit = {
  &envoy_config_core_v3_AlternateProtocolsCacheOptions_submsgs[0],
  &envoy_config_core_v3_AlternateProtocolsCacheOptions__fields[0],
  UPB_SIZE(24, 48), 4, upb_ExtMode_NonExtendable, 4, 255, 0,
};

static const upb_MiniTable_Field envoy_config_core_v3_AlternateProtocolsCacheOptions_AlternateProtocolsCacheEntry__fields[2] = {
  {1, UPB_SIZE(4, 8), 0, 0, 9, kUpb_FieldMode_Scalar | (upb_FieldRep_StringView << upb_FieldRep_Shift)},
  {2, UPB_SIZE(0, 0), 0, 0, 13, kUpb_FieldMode_Scalar | (upb_FieldRep_4Byte << upb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_core_v3_AlternateProtocolsCacheOptions_AlternateProtocolsCacheEntry_msginit = {
  NULL,
  &envoy_config_core_v3_AlternateProtocolsCacheOptions_AlternateProtocolsCacheEntry__fields[0],
  UPB_SIZE(16, 32), 2, upb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_core_v3_HttpProtocolOptions_submsgs[2] = {
  {.submsg = &google_protobuf_Duration_msginit},
  {.submsg = &google_protobuf_UInt32Value_msginit},
};

static const upb_MiniTable_Field envoy_config_core_v3_HttpProtocolOptions__fields[6] = {
  {1, UPB_SIZE(8, 8), 1, 0, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {2, UPB_SIZE(12, 16), 2, 1, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {3, UPB_SIZE(16, 24), 3, 0, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {4, UPB_SIZE(20, 32), 4, 0, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {5, UPB_SIZE(4, 4), 0, 0, 5, kUpb_FieldMode_Scalar | (upb_FieldRep_4Byte << upb_FieldRep_Shift)},
  {6, UPB_SIZE(24, 40), 5, 1, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_core_v3_HttpProtocolOptions_msginit = {
  &envoy_config_core_v3_HttpProtocolOptions_submsgs[0],
  &envoy_config_core_v3_HttpProtocolOptions__fields[0],
  UPB_SIZE(32, 48), 6, upb_ExtMode_NonExtendable, 6, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_core_v3_Http1ProtocolOptions_submsgs[2] = {
  {.submsg = &envoy_config_core_v3_Http1ProtocolOptions_HeaderKeyFormat_msginit},
  {.submsg = &google_protobuf_BoolValue_msginit},
};

static const upb_MiniTable_Field envoy_config_core_v3_Http1ProtocolOptions__fields[7] = {
  {1, UPB_SIZE(12, 24), 1, 1, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {2, UPB_SIZE(1, 1), 0, 0, 8, kUpb_FieldMode_Scalar | (upb_FieldRep_1Byte << upb_FieldRep_Shift)},
  {3, UPB_SIZE(4, 8), 0, 0, 9, kUpb_FieldMode_Scalar | (upb_FieldRep_StringView << upb_FieldRep_Shift)},
  {4, UPB_SIZE(16, 32), 2, 0, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {5, UPB_SIZE(2, 2), 0, 0, 8, kUpb_FieldMode_Scalar | (upb_FieldRep_1Byte << upb_FieldRep_Shift)},
  {6, UPB_SIZE(3, 3), 0, 0, 8, kUpb_FieldMode_Scalar | (upb_FieldRep_1Byte << upb_FieldRep_Shift)},
  {7, UPB_SIZE(20, 40), 3, 1, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_core_v3_Http1ProtocolOptions_msginit = {
  &envoy_config_core_v3_Http1ProtocolOptions_submsgs[0],
  &envoy_config_core_v3_Http1ProtocolOptions__fields[0],
  UPB_SIZE(24, 48), 7, upb_ExtMode_NonExtendable, 7, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_core_v3_Http1ProtocolOptions_HeaderKeyFormat_submsgs[2] = {
  {.submsg = &envoy_config_core_v3_Http1ProtocolOptions_HeaderKeyFormat_ProperCaseWords_msginit},
  {.submsg = &envoy_config_core_v3_TypedExtensionConfig_msginit},
};

static const upb_MiniTable_Field envoy_config_core_v3_Http1ProtocolOptions_HeaderKeyFormat__fields[2] = {
  {1, UPB_SIZE(0, 0), UPB_SIZE(-5, -9), 0, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {8, UPB_SIZE(0, 0), UPB_SIZE(-5, -9), 1, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_core_v3_Http1ProtocolOptions_HeaderKeyFormat_msginit = {
  &envoy_config_core_v3_Http1ProtocolOptions_HeaderKeyFormat_submsgs[0],
  &envoy_config_core_v3_Http1ProtocolOptions_HeaderKeyFormat__fields[0],
  UPB_SIZE(8, 16), 2, upb_ExtMode_NonExtendable, 1, 255, 0,
};

const upb_MiniTable envoy_config_core_v3_Http1ProtocolOptions_HeaderKeyFormat_ProperCaseWords_msginit = {
  NULL,
  NULL,
  UPB_SIZE(0, 0), 0, upb_ExtMode_NonExtendable, 0, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_core_v3_KeepaliveSettings_submsgs[2] = {
  {.submsg = &envoy_type_v3_Percent_msginit},
  {.submsg = &google_protobuf_Duration_msginit},
};

static const upb_MiniTable_Field envoy_config_core_v3_KeepaliveSettings__fields[4] = {
  {1, UPB_SIZE(4, 8), 1, 1, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {2, UPB_SIZE(8, 16), 2, 1, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {3, UPB_SIZE(12, 24), 3, 0, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {4, UPB_SIZE(16, 32), 4, 1, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_core_v3_KeepaliveSettings_msginit = {
  &envoy_config_core_v3_KeepaliveSettings_submsgs[0],
  &envoy_config_core_v3_KeepaliveSettings__fields[0],
  UPB_SIZE(24, 40), 4, upb_ExtMode_NonExtendable, 4, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_core_v3_Http2ProtocolOptions_submsgs[4] = {
  {.submsg = &envoy_config_core_v3_Http2ProtocolOptions_SettingsParameter_msginit},
  {.submsg = &envoy_config_core_v3_KeepaliveSettings_msginit},
  {.submsg = &google_protobuf_BoolValue_msginit},
  {.submsg = &google_protobuf_UInt32Value_msginit},
};

static const upb_MiniTable_Field envoy_config_core_v3_Http2ProtocolOptions__fields[15] = {
  {1, UPB_SIZE(8, 8), 1, 3, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {2, UPB_SIZE(12, 16), 2, 3, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {3, UPB_SIZE(16, 24), 3, 3, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {4, UPB_SIZE(20, 32), 4, 3, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {5, UPB_SIZE(2, 2), 0, 0, 8, kUpb_FieldMode_Scalar | (upb_FieldRep_1Byte << upb_FieldRep_Shift)},
  {6, UPB_SIZE(3, 3), 0, 0, 8, kUpb_FieldMode_Scalar | (upb_FieldRep_1Byte << upb_FieldRep_Shift)},
  {7, UPB_SIZE(24, 40), 5, 3, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {8, UPB_SIZE(28, 48), 6, 3, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {9, UPB_SIZE(32, 56), 7, 3, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {10, UPB_SIZE(36, 64), 8, 3, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {11, UPB_SIZE(40, 72), 9, 3, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {12, UPB_SIZE(4, 4), 0, 0, 8, kUpb_FieldMode_Scalar | (upb_FieldRep_1Byte << upb_FieldRep_Shift)},
  {13, UPB_SIZE(52, 96), 0, 0, 11, kUpb_FieldMode_Array | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {14, UPB_SIZE(44, 80), 10, 2, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {15, UPB_SIZE(48, 88), 11, 1, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_core_v3_Http2ProtocolOptions_msginit = {
  &envoy_config_core_v3_Http2ProtocolOptions_submsgs[0],
  &envoy_config_core_v3_Http2ProtocolOptions__fields[0],
  UPB_SIZE(56, 104), 15, upb_ExtMode_NonExtendable, 15, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_core_v3_Http2ProtocolOptions_SettingsParameter_submsgs[1] = {
  {.submsg = &google_protobuf_UInt32Value_msginit},
};

static const upb_MiniTable_Field envoy_config_core_v3_Http2ProtocolOptions_SettingsParameter__fields[2] = {
  {1, UPB_SIZE(4, 8), 1, 0, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {2, UPB_SIZE(8, 16), 2, 0, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_core_v3_Http2ProtocolOptions_SettingsParameter_msginit = {
  &envoy_config_core_v3_Http2ProtocolOptions_SettingsParameter_submsgs[0],
  &envoy_config_core_v3_Http2ProtocolOptions_SettingsParameter__fields[0],
  UPB_SIZE(16, 24), 2, upb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_core_v3_GrpcProtocolOptions_submsgs[1] = {
  {.submsg = &envoy_config_core_v3_Http2ProtocolOptions_msginit},
};

static const upb_MiniTable_Field envoy_config_core_v3_GrpcProtocolOptions__fields[1] = {
  {1, UPB_SIZE(4, 8), 1, 0, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_core_v3_GrpcProtocolOptions_msginit = {
  &envoy_config_core_v3_GrpcProtocolOptions_submsgs[0],
  &envoy_config_core_v3_GrpcProtocolOptions__fields[0],
  UPB_SIZE(8, 16), 1, upb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_core_v3_Http3ProtocolOptions_submsgs[2] = {
  {.submsg = &envoy_config_core_v3_QuicProtocolOptions_msginit},
  {.submsg = &google_protobuf_BoolValue_msginit},
};

static const upb_MiniTable_Field envoy_config_core_v3_Http3ProtocolOptions__fields[3] = {
  {1, UPB_SIZE(4, 8), 1, 0, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {2, UPB_SIZE(8, 16), 2, 1, 11, kUpb_FieldMode_Scalar | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
  {5, UPB_SIZE(1, 1), 0, 0, 8, kUpb_FieldMode_Scalar | (upb_FieldRep_1Byte << upb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_core_v3_Http3ProtocolOptions_msginit = {
  &envoy_config_core_v3_Http3ProtocolOptions_submsgs[0],
  &envoy_config_core_v3_Http3ProtocolOptions__fields[0],
  UPB_SIZE(16, 24), 3, upb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Field envoy_config_core_v3_SchemeHeaderTransformation__fields[1] = {
  {1, UPB_SIZE(0, 0), UPB_SIZE(-9, -17), 0, 9, kUpb_FieldMode_Scalar | (upb_FieldRep_StringView << upb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_core_v3_SchemeHeaderTransformation_msginit = {
  NULL,
  &envoy_config_core_v3_SchemeHeaderTransformation__fields[0],
  UPB_SIZE(16, 32), 1, upb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable *messages_layout[16] = {
  &envoy_config_core_v3_TcpProtocolOptions_msginit,
  &envoy_config_core_v3_QuicKeepAliveSettings_msginit,
  &envoy_config_core_v3_QuicProtocolOptions_msginit,
  &envoy_config_core_v3_UpstreamHttpProtocolOptions_msginit,
  &envoy_config_core_v3_AlternateProtocolsCacheOptions_msginit,
  &envoy_config_core_v3_AlternateProtocolsCacheOptions_AlternateProtocolsCacheEntry_msginit,
  &envoy_config_core_v3_HttpProtocolOptions_msginit,
  &envoy_config_core_v3_Http1ProtocolOptions_msginit,
  &envoy_config_core_v3_Http1ProtocolOptions_HeaderKeyFormat_msginit,
  &envoy_config_core_v3_Http1ProtocolOptions_HeaderKeyFormat_ProperCaseWords_msginit,
  &envoy_config_core_v3_KeepaliveSettings_msginit,
  &envoy_config_core_v3_Http2ProtocolOptions_msginit,
  &envoy_config_core_v3_Http2ProtocolOptions_SettingsParameter_msginit,
  &envoy_config_core_v3_GrpcProtocolOptions_msginit,
  &envoy_config_core_v3_Http3ProtocolOptions_msginit,
  &envoy_config_core_v3_SchemeHeaderTransformation_msginit,
};

const upb_MiniTable_File envoy_config_core_v3_protocol_proto_upb_file_layout = {
  messages_layout,
  NULL,
  NULL,
  16,
  0,
  0,
};

#include "upb/port_undef.inc"

