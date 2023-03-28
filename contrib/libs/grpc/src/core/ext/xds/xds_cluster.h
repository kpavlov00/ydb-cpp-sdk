//
// Copyright 2018 gRPC authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef GRPC_CORE_EXT_XDS_XDS_CLUSTER_H
#define GRPC_CORE_EXT_XDS_XDS_CLUSTER_H

#include <grpc/support/port_platform.h>

#include <util/generic/string.h>
#include <util/string/cast.h>
#include <vector>

#include "y_absl/types/optional.h"
#include "envoy/config/cluster/v3/cluster.upbdefs.h"
#include "envoy/extensions/clusters/aggregate/v3/cluster.upbdefs.h"
#include "envoy/extensions/transport_sockets/tls/v3/tls.upbdefs.h"

#include "src/core/ext/xds/xds_client.h"
#include "src/core/ext/xds/xds_common_types.h"
#include "src/core/ext/xds/xds_resource_type_impl.h"

namespace grpc_core {

struct XdsClusterResource {
  enum ClusterType { EDS, LOGICAL_DNS, AGGREGATE };
  ClusterType cluster_type;
  // For cluster type EDS.
  // The name to use in the EDS request.
  // If empty, the cluster name will be used.
  TString eds_service_name;
  // For cluster type LOGICAL_DNS.
  // The hostname to lookup in DNS.
  TString dns_hostname;
  // For cluster type AGGREGATE.
  // The prioritized list of cluster names.
  std::vector<TString> prioritized_cluster_names;

  // Tls Context used by clients
  CommonTlsContext common_tls_context;

  // The LRS server to use for load reporting.
  // If not set, load reporting will be disabled.
  y_absl::optional<XdsBootstrap::XdsServer> lrs_load_reporting_server;

  // The LB policy to use (e.g., "ROUND_ROBIN" or "RING_HASH").
  TString lb_policy;
  // Used for RING_HASH LB policy only.
  uint64_t min_ring_size = 1024;
  uint64_t max_ring_size = 8388608;
  // Maximum number of outstanding requests can be made to the upstream
  // cluster.
  uint32_t max_concurrent_requests = 1024;

  bool operator==(const XdsClusterResource& other) const {
    return cluster_type == other.cluster_type &&
           eds_service_name == other.eds_service_name &&
           dns_hostname == other.dns_hostname &&
           prioritized_cluster_names == other.prioritized_cluster_names &&
           common_tls_context == other.common_tls_context &&
           lrs_load_reporting_server == other.lrs_load_reporting_server &&
           lb_policy == other.lb_policy &&
           min_ring_size == other.min_ring_size &&
           max_ring_size == other.max_ring_size &&
           max_concurrent_requests == other.max_concurrent_requests;
  }

  TString ToString() const;
};

class XdsClusterResourceType
    : public XdsResourceTypeImpl<XdsClusterResourceType, XdsClusterResource> {
 public:
  y_absl::string_view type_url() const override {
    return "envoy.config.cluster.v3.Cluster";
  }
  y_absl::string_view v2_type_url() const override {
    return "envoy.api.v2.Cluster";
  }

  y_absl::StatusOr<DecodeResult> Decode(const XdsEncodingContext& context,
                                      y_absl::string_view serialized_resource,
                                      bool is_v2) const override;

  bool AllResourcesRequiredInSotW() const override { return true; }

  void InitUpbSymtab(upb_DefPool* symtab) const override {
    envoy_config_cluster_v3_Cluster_getmsgdef(symtab);
    envoy_extensions_clusters_aggregate_v3_ClusterConfig_getmsgdef(symtab);
    envoy_extensions_transport_sockets_tls_v3_UpstreamTlsContext_getmsgdef(
        symtab);
  }
};

}  // namespace grpc_core

#endif  // GRPC_CORE_EXT_XDS_XDS_CLUSTER_H
