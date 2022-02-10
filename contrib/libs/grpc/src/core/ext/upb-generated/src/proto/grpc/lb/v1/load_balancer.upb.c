/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     src/proto/grpc/lb/v1/load_balancer.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg.h"
#include "src/proto/grpc/lb/v1/load_balancer.upb.h"
#include "google/protobuf/duration.upb.h"
#include "google/protobuf/timestamp.upb.h"

#include "upb/port_def.inc"

static const upb_msglayout *const grpc_lb_v1_LoadBalanceRequest_submsgs[2] = {
  &grpc_lb_v1_ClientStats_msginit,
  &grpc_lb_v1_InitialLoadBalanceRequest_msginit,
};

static const upb_msglayout_field grpc_lb_v1_LoadBalanceRequest__fields[2] = {
  {1, UPB_SIZE(0, 0), UPB_SIZE(-5, -9), 1, 11, 1},
  {2, UPB_SIZE(0, 0), UPB_SIZE(-5, -9), 0, 11, 1},
};

const upb_msglayout grpc_lb_v1_LoadBalanceRequest_msginit = {
  &grpc_lb_v1_LoadBalanceRequest_submsgs[0],
  &grpc_lb_v1_LoadBalanceRequest__fields[0],
  UPB_SIZE(8, 16), 2, false,
};

static const upb_msglayout_field grpc_lb_v1_InitialLoadBalanceRequest__fields[1] = {
  {1, UPB_SIZE(0, 0), 0, 0, 9, 1},
};

const upb_msglayout grpc_lb_v1_InitialLoadBalanceRequest_msginit = {
  NULL,
  &grpc_lb_v1_InitialLoadBalanceRequest__fields[0],
  UPB_SIZE(8, 16), 1, false,
};

static const upb_msglayout_field grpc_lb_v1_ClientStatsPerToken__fields[2] = {
  {1, UPB_SIZE(8, 8), 0, 0, 9, 1},
  {2, UPB_SIZE(0, 0), 0, 0, 3, 1},
};

const upb_msglayout grpc_lb_v1_ClientStatsPerToken_msginit = {
  NULL,
  &grpc_lb_v1_ClientStatsPerToken__fields[0],
  UPB_SIZE(16, 32), 2, false,
};

static const upb_msglayout *const grpc_lb_v1_ClientStats_submsgs[2] = {
  &google_protobuf_Timestamp_msginit,
  &grpc_lb_v1_ClientStatsPerToken_msginit,
};

static const upb_msglayout_field grpc_lb_v1_ClientStats__fields[6] = {
  {1, UPB_SIZE(32, 32), 0, 0, 11, 1},
  {2, UPB_SIZE(0, 0), 0, 0, 3, 1},
  {3, UPB_SIZE(8, 8), 0, 0, 3, 1},
  {6, UPB_SIZE(16, 16), 0, 0, 3, 1},
  {7, UPB_SIZE(24, 24), 0, 0, 3, 1},
  {8, UPB_SIZE(36, 40), 0, 1, 11, 3},
};

const upb_msglayout grpc_lb_v1_ClientStats_msginit = {
  &grpc_lb_v1_ClientStats_submsgs[0],
  &grpc_lb_v1_ClientStats__fields[0],
  UPB_SIZE(40, 48), 6, false,
};

static const upb_msglayout *const grpc_lb_v1_LoadBalanceResponse_submsgs[3] = { 
  &grpc_lb_v1_FallbackResponse_msginit, 
  &grpc_lb_v1_InitialLoadBalanceResponse_msginit,
  &grpc_lb_v1_ServerList_msginit,
};

static const upb_msglayout_field grpc_lb_v1_LoadBalanceResponse__fields[3] = { 
  {1, UPB_SIZE(0, 0), UPB_SIZE(-5, -9), 1, 11, 1}, 
  {2, UPB_SIZE(0, 0), UPB_SIZE(-5, -9), 2, 11, 1}, 
  {3, UPB_SIZE(0, 0), UPB_SIZE(-5, -9), 0, 11, 1}, 
};

const upb_msglayout grpc_lb_v1_LoadBalanceResponse_msginit = {
  &grpc_lb_v1_LoadBalanceResponse_submsgs[0],
  &grpc_lb_v1_LoadBalanceResponse__fields[0],
  UPB_SIZE(8, 16), 3, false, 
};

static const upb_msglayout *const grpc_lb_v1_InitialLoadBalanceResponse_submsgs[1] = {
  &google_protobuf_Duration_msginit,
};

static const upb_msglayout_field grpc_lb_v1_InitialLoadBalanceResponse__fields[2] = {
  {1, UPB_SIZE(0, 0), 0, 0, 9, 1},
  {2, UPB_SIZE(8, 16), 0, 0, 11, 1},
};

const upb_msglayout grpc_lb_v1_InitialLoadBalanceResponse_msginit = {
  &grpc_lb_v1_InitialLoadBalanceResponse_submsgs[0],
  &grpc_lb_v1_InitialLoadBalanceResponse__fields[0],
  UPB_SIZE(16, 32), 2, false,
};

static const upb_msglayout *const grpc_lb_v1_ServerList_submsgs[1] = {
  &grpc_lb_v1_Server_msginit,
};

static const upb_msglayout_field grpc_lb_v1_ServerList__fields[1] = {
  {1, UPB_SIZE(0, 0), 0, 0, 11, 3},
};

const upb_msglayout grpc_lb_v1_ServerList_msginit = {
  &grpc_lb_v1_ServerList_submsgs[0],
  &grpc_lb_v1_ServerList__fields[0],
  UPB_SIZE(4, 8), 1, false,
};

static const upb_msglayout_field grpc_lb_v1_Server__fields[4] = {
  {1, UPB_SIZE(8, 8), 0, 0, 12, 1},
  {2, UPB_SIZE(0, 0), 0, 0, 5, 1},
  {3, UPB_SIZE(16, 24), 0, 0, 9, 1},
  {4, UPB_SIZE(4, 4), 0, 0, 8, 1},
};

const upb_msglayout grpc_lb_v1_Server_msginit = {
  NULL,
  &grpc_lb_v1_Server__fields[0],
  UPB_SIZE(24, 48), 4, false,
};

const upb_msglayout grpc_lb_v1_FallbackResponse_msginit = { 
  NULL, 
  NULL, 
  UPB_SIZE(0, 0), 0, false, 
}; 
 
#include "upb/port_undef.inc"

