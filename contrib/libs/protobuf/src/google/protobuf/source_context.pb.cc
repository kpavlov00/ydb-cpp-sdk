// Generated by the protocol buffer compiler.  DO NOT EDIT! 
// source: google/protobuf/source_context.proto 
 
#include <google/protobuf/source_context.pb.h>
 
#include <algorithm> 
 
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes) 
#include <google/protobuf/port_def.inc>
 
PROTOBUF_PRAGMA_INIT_SEG
PROTOBUF_NAMESPACE_OPEN
constexpr SourceContext::SourceContext(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : file_name_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct SourceContextDefaultTypeInternal {
  constexpr SourceContextDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~SourceContextDefaultTypeInternal() {}
  union {
    SourceContext _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT SourceContextDefaultTypeInternal _SourceContext_default_instance_;
PROTOBUF_NAMESPACE_CLOSE
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_google_2fprotobuf_2fsource_5fcontext_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_google_2fprotobuf_2fsource_5fcontext_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_google_2fprotobuf_2fsource_5fcontext_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_google_2fprotobuf_2fsource_5fcontext_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(PROTOBUF_NAMESPACE_ID::SourceContext, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(PROTOBUF_NAMESPACE_ID::SourceContext, file_name_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(PROTOBUF_NAMESPACE_ID::SourceContext)},
};
 
static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&PROTOBUF_NAMESPACE_ID::_SourceContext_default_instance_),
};

const char descriptor_table_protodef_google_2fprotobuf_2fsource_5fcontext_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n$google/protobuf/source_context.proto\022\017"
  "google.protobuf\"\"\n\rSourceContext\022\021\n\tfile"
  "_name\030\001 \001(\tB\212\001\n\023com.google.protobufB\022Sou"
  "rceContextProtoP\001Z6google.golang.org/pro"
  "tobuf/types/known/sourcecontextpb\242\002\003GPB\252"
  "\002\036Google.Protobuf.WellKnownTypesb\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_google_2fprotobuf_2fsource_5fcontext_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_google_2fprotobuf_2fsource_5fcontext_2eproto = {
  false, false, 240, descriptor_table_protodef_google_2fprotobuf_2fsource_5fcontext_2eproto, "google/protobuf/source_context.proto", 
  &descriptor_table_google_2fprotobuf_2fsource_5fcontext_2eproto_once, nullptr, 0, 1,
  schemas, file_default_instances, TableStruct_google_2fprotobuf_2fsource_5fcontext_2eproto::offsets,
  file_level_metadata_google_2fprotobuf_2fsource_5fcontext_2eproto, file_level_enum_descriptors_google_2fprotobuf_2fsource_5fcontext_2eproto, file_level_service_descriptors_google_2fprotobuf_2fsource_5fcontext_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_google_2fprotobuf_2fsource_5fcontext_2eproto_getter() {
  return &descriptor_table_google_2fprotobuf_2fsource_5fcontext_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_google_2fprotobuf_2fsource_5fcontext_2eproto(&descriptor_table_google_2fprotobuf_2fsource_5fcontext_2eproto);
PROTOBUF_NAMESPACE_OPEN
 
// =================================================================== 
 
class SourceContext::_Internal {
 public:
};
 
SourceContext::SourceContext(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(); 
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:google.protobuf.SourceContext)
} 
SourceContext::SourceContext(const SourceContext& from) 
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  file_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_file_name().empty()) {
    file_name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_file_name(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:google.protobuf.SourceContext) 
} 
 
void SourceContext::SharedCtor() { 
file_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
} 
 
SourceContext::~SourceContext() { 
  // @@protoc_insertion_point(destructor:google.protobuf.SourceContext) 
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor(); 
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
} 
 
inline void SourceContext::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  file_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
} 
 
void SourceContext::ArenaDtor(void* object) {
  SourceContext* _this = reinterpret_cast< SourceContext* >(object);
  (void)_this;
} 
void SourceContext::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
} 
void SourceContext::SetCachedSize(int size) const {
  _cached_size_.Set(size);
} 
 
void SourceContext::Clear() { 
// @@protoc_insertion_point(message_clear_start:google.protobuf.SourceContext) 
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  file_name_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
} 
 
const char* SourceContext::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string file_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_file_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "google.protobuf.SourceContext.file_name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: { 
      handle_unusual: 
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success; 
        } 
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      } 
    }  // switch
  }  // while
success: 
  return ptr;
failure: 
  ptr = nullptr;
  goto success;
#undef CHK_
} 
 
::PROTOBUF_NAMESPACE_ID::uint8* SourceContext::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:google.protobuf.SourceContext) 
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string file_name = 1;
  if (!this->_internal_file_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_file_name().data(), static_cast<int>(this->_internal_file_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "google.protobuf.SourceContext.file_name"); 
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_file_name(), target);
  } 
 
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:google.protobuf.SourceContext) 
  return target; 
} 
 
size_t SourceContext::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:google.protobuf.SourceContext) 
  size_t total_size = 0;
 
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string file_name = 1;
  if (!this->_internal_file_name().empty()) {
    total_size += 1 + 
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_file_name());
  } 
 
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size; 
} 
 
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData SourceContext::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    SourceContext::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*SourceContext::GetClassData() const { return &_class_data_; }

void SourceContext::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<SourceContext *>(to)->MergeFrom(
      static_cast<const SourceContext &>(from));
} 
 

void SourceContext::MergeFrom(const SourceContext& from) { 
// @@protoc_insertion_point(class_specific_merge_from_start:google.protobuf.SourceContext) 
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_file_name().empty()) {
    _internal_set_file_name(from._internal_file_name());
  } 
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
} 
 
void SourceContext::CopyFrom(const SourceContext& from) { 
// @@protoc_insertion_point(class_specific_copy_from_start:google.protobuf.SourceContext) 
  if (&from == this) return; 
  Clear(); 
  MergeFrom(from);
} 
 
bool SourceContext::IsInitialized() const { 
  return true; 
} 
 
void SourceContext::InternalSwap(SourceContext* other) { 
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &file_name_, GetArenaForAllocation(),
      &other->file_name_, other->GetArenaForAllocation()
  );
} 
 
::PROTOBUF_NAMESPACE_ID::Metadata SourceContext::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_google_2fprotobuf_2fsource_5fcontext_2eproto_getter, &descriptor_table_google_2fprotobuf_2fsource_5fcontext_2eproto_once,
      file_level_metadata_google_2fprotobuf_2fsource_5fcontext_2eproto[0]);
} 
 
// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_CLOSE
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE PROTOBUF_NAMESPACE_ID::SourceContext* Arena::CreateMaybeMessage< PROTOBUF_NAMESPACE_ID::SourceContext >(Arena* arena) {
  return Arena::CreateMessageInternal< PROTOBUF_NAMESPACE_ID::SourceContext >(arena);
} 
PROTOBUF_NAMESPACE_CLOSE
 
// @@protoc_insertion_point(global_scope) 
#include <google/protobuf/port_undef.inc>
