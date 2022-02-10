# Generated by devtools/yamaker from nixpkgs 21.11.

LIBRARY()

OWNER(
    somov
    g:cpp-contrib
)

VERSION(20211102.0)

LICENSE(Apache-2.0)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/restricted/abseil-cpp-tstring/y_absl/algorithm
    contrib/restricted/abseil-cpp-tstring/y_absl/base
    contrib/restricted/abseil-cpp-tstring/y_absl/base/internal/low_level_alloc
    contrib/restricted/abseil-cpp-tstring/y_absl/base/internal/raw_logging
    contrib/restricted/abseil-cpp-tstring/y_absl/base/internal/scoped_set_env
    contrib/restricted/abseil-cpp-tstring/y_absl/base/internal/spinlock_wait
    contrib/restricted/abseil-cpp-tstring/y_absl/base/internal/strerror
    contrib/restricted/abseil-cpp-tstring/y_absl/base/internal/throw_delegate
    contrib/restricted/abseil-cpp-tstring/y_absl/base/log_severity
    contrib/restricted/abseil-cpp-tstring/y_absl/city
    contrib/restricted/abseil-cpp-tstring/y_absl/container
    contrib/restricted/abseil-cpp-tstring/y_absl/container/internal/absl_hashtablez_sampler
    contrib/restricted/abseil-cpp-tstring/y_absl/container/internal/raw_hash_set
    contrib/restricted/abseil-cpp-tstring/y_absl/debugging
    contrib/restricted/abseil-cpp-tstring/y_absl/debugging/failure_signal_handler
    contrib/restricted/abseil-cpp-tstring/y_absl/debugging/internal
    contrib/restricted/abseil-cpp-tstring/y_absl/debugging/leak_check
    contrib/restricted/abseil-cpp-tstring/y_absl/debugging/leak_check_disable
    contrib/restricted/abseil-cpp-tstring/y_absl/debugging/stacktrace
    contrib/restricted/abseil-cpp-tstring/y_absl/debugging/symbolize
    contrib/restricted/abseil-cpp-tstring/y_absl/demangle
    contrib/restricted/abseil-cpp-tstring/y_absl/flags
    contrib/restricted/abseil-cpp-tstring/y_absl/flags/commandlineflag
    contrib/restricted/abseil-cpp-tstring/y_absl/flags/internal/commandlineflag
    contrib/restricted/abseil-cpp-tstring/y_absl/flags/internal/flag
    contrib/restricted/abseil-cpp-tstring/y_absl/flags/internal/private_handle_accessor
    contrib/restricted/abseil-cpp-tstring/y_absl/flags/internal/program_name
    contrib/restricted/abseil-cpp-tstring/y_absl/flags/internal/usage
    contrib/restricted/abseil-cpp-tstring/y_absl/flags/marshalling
    contrib/restricted/abseil-cpp-tstring/y_absl/flags/parse
    contrib/restricted/abseil-cpp-tstring/y_absl/flags/reflection
    contrib/restricted/abseil-cpp-tstring/y_absl/flags/usage
    contrib/restricted/abseil-cpp-tstring/y_absl/flags/usage_config
    contrib/restricted/abseil-cpp-tstring/y_absl/functional
    contrib/restricted/abseil-cpp-tstring/y_absl/hash
    contrib/restricted/abseil-cpp-tstring/y_absl/hash/internal
    contrib/restricted/abseil-cpp-tstring/y_absl/memory
    contrib/restricted/abseil-cpp-tstring/y_absl/meta
    contrib/restricted/abseil-cpp-tstring/y_absl/numeric
    contrib/restricted/abseil-cpp-tstring/y_absl/profiling/internal/exponential_biased
    contrib/restricted/abseil-cpp-tstring/y_absl/profiling/internal/periodic_sampler
    contrib/restricted/abseil-cpp-tstring/y_absl/random/absl_random_distributions
    contrib/restricted/abseil-cpp-tstring/y_absl/random/internal/absl_random_internal_distribution_test_util
    contrib/restricted/abseil-cpp-tstring/y_absl/random/internal/pool_urbg
    contrib/restricted/abseil-cpp-tstring/y_absl/random/internal/randen
    contrib/restricted/abseil-cpp-tstring/y_absl/random/internal/randen_detect
    contrib/restricted/abseil-cpp-tstring/y_absl/random/internal/randen_hwaes
    contrib/restricted/abseil-cpp-tstring/y_absl/random/internal/randen_round_keys
    contrib/restricted/abseil-cpp-tstring/y_absl/random/internal/randen_slow
    contrib/restricted/abseil-cpp-tstring/y_absl/random/internal/seed_material
    contrib/restricted/abseil-cpp-tstring/y_absl/random/seed_gen_exception
    contrib/restricted/abseil-cpp-tstring/y_absl/random/seed_sequences
    contrib/restricted/abseil-cpp-tstring/y_absl/status 
    contrib/restricted/abseil-cpp-tstring/y_absl/status/statusor
    contrib/restricted/abseil-cpp-tstring/y_absl/strings
    contrib/restricted/abseil-cpp-tstring/y_absl/strings/cord
    contrib/restricted/abseil-cpp-tstring/y_absl/strings/internal/absl_cord_internal
    contrib/restricted/abseil-cpp-tstring/y_absl/strings/internal/absl_strings_internal
    contrib/restricted/abseil-cpp-tstring/y_absl/strings/internal/cordz_functions
    contrib/restricted/abseil-cpp-tstring/y_absl/strings/internal/cordz_handle
    contrib/restricted/abseil-cpp-tstring/y_absl/strings/internal/cordz_info
    contrib/restricted/abseil-cpp-tstring/y_absl/strings/internal/cordz_sample_token
    contrib/restricted/abseil-cpp-tstring/y_absl/strings/internal/str_format
    contrib/restricted/abseil-cpp-tstring/y_absl/synchronization
    contrib/restricted/abseil-cpp-tstring/y_absl/synchronization/internal
    contrib/restricted/abseil-cpp-tstring/y_absl/time
    contrib/restricted/abseil-cpp-tstring/y_absl/time/civil_time
    contrib/restricted/abseil-cpp-tstring/y_absl/time/time_zone
    contrib/restricted/abseil-cpp-tstring/y_absl/types
    contrib/restricted/abseil-cpp-tstring/y_absl/types/bad_any_cast
    contrib/restricted/abseil-cpp-tstring/y_absl/types/bad_optional_access
    contrib/restricted/abseil-cpp-tstring/y_absl/types/bad_variant_access
    contrib/restricted/abseil-cpp-tstring/y_absl/types/internal
    contrib/restricted/abseil-cpp-tstring/y_absl/utility
)

NO_RUNTIME()
 
END()

RECURSE(
    y_absl/algorithm
    y_absl/base
    y_absl/base/internal/low_level_alloc
    y_absl/base/internal/raw_logging
    y_absl/base/internal/scoped_set_env
    y_absl/base/internal/spinlock_wait
    y_absl/base/internal/strerror
    y_absl/base/internal/throw_delegate
    y_absl/base/log_severity
    y_absl/city
    y_absl/container
    y_absl/container/internal/absl_hashtablez_sampler
    y_absl/container/internal/raw_hash_set
    y_absl/debugging
    y_absl/debugging/failure_signal_handler
    y_absl/debugging/internal
    y_absl/debugging/leak_check
    y_absl/debugging/leak_check_disable
    y_absl/debugging/stacktrace
    y_absl/debugging/symbolize
    y_absl/demangle
    y_absl/flags
    y_absl/flags/commandlineflag
    y_absl/flags/internal/commandlineflag
    y_absl/flags/internal/flag
    y_absl/flags/internal/private_handle_accessor
    y_absl/flags/internal/program_name
    y_absl/flags/internal/usage
    y_absl/flags/marshalling
    y_absl/flags/parse
    y_absl/flags/reflection
    y_absl/flags/usage
    y_absl/flags/usage_config
    y_absl/functional
    y_absl/hash
    y_absl/hash/internal
    y_absl/memory
    y_absl/meta
    y_absl/numeric
    y_absl/profiling/internal/exponential_biased
    y_absl/profiling/internal/periodic_sampler
    y_absl/random/absl_random_distributions
    y_absl/random/internal/absl_random_internal_distribution_test_util
    y_absl/random/internal/pool_urbg
    y_absl/random/internal/randen
    y_absl/random/internal/randen_detect
    y_absl/random/internal/randen_hwaes
    y_absl/random/internal/randen_round_keys
    y_absl/random/internal/randen_slow
    y_absl/random/internal/seed_material
    y_absl/random/seed_gen_exception
    y_absl/random/seed_sequences
    y_absl/status 
    y_absl/status/statusor
    y_absl/strings
    y_absl/strings/cord
    y_absl/strings/internal/absl_cord_internal
    y_absl/strings/internal/absl_strings_internal
    y_absl/strings/internal/cordz_functions
    y_absl/strings/internal/cordz_handle
    y_absl/strings/internal/cordz_info
    y_absl/strings/internal/cordz_sample_token
    y_absl/strings/internal/str_format
    y_absl/synchronization
    y_absl/synchronization/internal
    y_absl/time
    y_absl/time/civil_time
    y_absl/time/time_zone
    y_absl/types
    y_absl/types/bad_any_cast
    y_absl/types/bad_optional_access
    y_absl/types/bad_variant_access
    y_absl/types/internal
    y_absl/utility
)
