/*
 *
 * Copyright 2017 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef GRPC_CORE_LIB_GPRPP_MAP_H
#define GRPC_CORE_LIB_GPRPP_MAP_H

#include <grpc/support/port_platform.h>

#include <string.h>

#include <map>

#include "y_absl/strings/string_view.h"

#include "src/core/lib/gprpp/memory.h"

namespace grpc_core {

struct StringLess {
  bool operator()(const char* a, const char* b) const {
    return strcmp(a, b) < 0;
  }
  bool operator()(const grpc_core::UniquePtr<char>& a,
                  const grpc_core::UniquePtr<char>& b) const {
    return strcmp(a.get(), b.get()) < 0;
  }
  bool operator()(const y_absl::string_view& a,
                  const y_absl::string_view& b) const {
    const size_t min_size = std::min(a.size(), b.size());
    int c = strncmp(a.data(), b.data(), min_size);
    if (c != 0) return c < 0;
    return a.size() < b.size();
  }
};

}  // namespace grpc_core

#endif /* GRPC_CORE_LIB_GPRPP_MAP_H */
