#pragma once
#include <src/api/grpc/draft/ydb_persqueue_v1.grpc.pb.h>
#include <ydb-cpp-sdk/client/driver/driver.h>
#include <ydb-cpp-sdk/client/types/exceptions/exceptions.h>

#include <ydb-cpp-sdk/library/monlib/dynamic_counters/counters.h>
#include <ydb-cpp-sdk/library/logger/log.h>
#include <ydb-cpp-sdk/library/retry/retry_policy.h>
#include <ydb-cpp-sdk/util/string/builder.h>

#include <ydb-cpp-sdk/util/datetime/base.h>
#include <src/util/generic/hash.h>
#include <ydb-cpp-sdk/util/generic/ptr.h>
#include <ydb-cpp-sdk/util/generic/size_literals.h>
#include <ydb-cpp-sdk/util/string/builder.h>
#include <ydb-cpp-sdk/util/thread/pool.h>

#include <exception>
#include <variant>

namespace NYdb {
    class TProtoAccessor;
}

namespace NYdb::NPersQueue {

enum class EFormat {
    BASE = 1,
};

enum class ECodec {
    RAW = 1,
    GZIP = 2,
    LZOP = 3,
    ZSTD = 4,
};

struct TCredentials {
    enum class EMode {
        NOT_SET = 1,
        OAUTH_TOKEN = 2,
        JWT_PARAMS = 3,
        IAM = 4,
    };

    TCredentials() = default;
    TCredentials(const Ydb::PersQueue::V1::Credentials& credentials);
    EMode GetMode() const;
    std::string GetOauthToken() const;
    std::string GetJwtParams() const;

    std::string GetIamServiceAccountKey() const;
    std::string GetIamEndpoint() const;

private:
    EMode Mode_;
    Ydb::PersQueue::V1::Credentials Credentials_;
};


// Result for describe resource request.
struct TDescribeTopicResult : public TStatus {
    friend class NYdb::TProtoAccessor;

    struct TTopicSettings {
        TTopicSettings(const Ydb::PersQueue::V1::TopicSettings&);

        #define GETTER(TYPE, NAME) TYPE NAME() const { return NAME##_; }

        struct TReadRule {
            TReadRule(const Ydb::PersQueue::V1::TopicSettings::ReadRule&);

            GETTER(std::string, ConsumerName);
            GETTER(bool, Important);
            GETTER(TInstant, StartingMessageTimestamp);
            GETTER(EFormat, SupportedFormat);
            const std::vector<ECodec>& SupportedCodecs() const {
                return SupportedCodecs_;
            }
            GETTER(ui32, Version);
            GETTER(std::string, ServiceType);

        private:
            std::string ConsumerName_;
            bool Important_;
            TInstant StartingMessageTimestamp_;
            EFormat SupportedFormat_;
            std::vector<ECodec> SupportedCodecs_;
            ui32 Version_;
            std::string ServiceType_;
        };

        struct TRemoteMirrorRule {
            TRemoteMirrorRule(const Ydb::PersQueue::V1::TopicSettings::RemoteMirrorRule&);
            GETTER(std::string, Endpoint);
            GETTER(std::string, TopicPath);
            GETTER(std::string, ConsumerName);
            GETTER(TInstant, StartingMessageTimestamp);
            GETTER(TCredentials, Credentials);
            GETTER(std::string, Database);

        private:
            std::string Endpoint_;
            std::string TopicPath_;
            std::string ConsumerName_;
            TInstant StartingMessageTimestamp_;
            TCredentials Credentials_;
            std::string Database_;
        };

        GETTER(ui32, PartitionsCount);
        GETTER(TDuration, RetentionPeriod);
        GETTER(EFormat, SupportedFormat);
        const std::vector<ECodec>& SupportedCodecs() const {
            return SupportedCodecs_;
        }
        GETTER(ui64, MaxPartitionStorageSize);
        GETTER(ui64, MaxPartitionWriteSpeed);
        GETTER(ui64, MaxPartitionWriteBurst);
        GETTER(bool, ClientWriteDisabled);

        // attributes
        GETTER(bool, AllowUnauthenticatedWrite);
        GETTER(bool, AllowUnauthenticatedRead);
        GETTER(std::optional<ui32>, PartitionsPerTablet);
        GETTER(std::optional<ui32>, AbcId);
        GETTER(std::optional<std::string>, AbcSlug);
        GETTER(std::optional<std::string>, FederationAccount);

        const std::vector<TReadRule>& ReadRules() const {
            return ReadRules_;
        }
        GETTER(std::optional<TRemoteMirrorRule>, RemoteMirrorRule);


#undef GETTER

    private:
        ui32 PartitionsCount_;
        TDuration RetentionPeriod_;
        EFormat SupportedFormat_;
        std::vector<ECodec> SupportedCodecs_;
        ui64 MaxPartitionStorageSize_;
        ui64 MaxPartitionWriteSpeed_;
        ui64 MaxPartitionWriteBurst_;
        bool ClientWriteDisabled_;
        std::vector<TReadRule> ReadRules_;
        std::optional<TRemoteMirrorRule> RemoteMirrorRule_;
        // attributes
        bool AllowUnauthenticatedRead_;
        bool AllowUnauthenticatedWrite_;
        std::optional<ui32> PartitionsPerTablet_;
        std::optional<ui32> AbcId_;
        std::optional<std::string> AbcSlug_;
        std::string FederationAccount_;
    };

    TDescribeTopicResult(TStatus status, const Ydb::PersQueue::V1::DescribeTopicResult& result);

    const TTopicSettings& TopicSettings() const {
        return TopicSettings_;
    }

private:
    TTopicSettings TopicSettings_;
    [[nodiscard]] const Ydb::PersQueue::V1::DescribeTopicResult& GetProto() const {
        return Proto_;
    }
    const Ydb::PersQueue::V1::DescribeTopicResult Proto_;
};

using TAsyncDescribeTopicResult = NThreading::TFuture<TDescribeTopicResult>;



const std::vector<ECodec>& GetDefaultCodecs();

struct TReadRuleSettings {
    TReadRuleSettings() {}
    using TSelf = TReadRuleSettings;
    FLUENT_SETTING(std::string, ConsumerName);
    FLUENT_SETTING_DEFAULT(bool, Important, false);
    FLUENT_SETTING_DEFAULT(TInstant, StartingMessageTimestamp, TInstant::Zero());
    FLUENT_SETTING_DEFAULT(EFormat, SupportedFormat, EFormat::BASE)
    FLUENT_SETTING_DEFAULT(std::vector<ECodec>, SupportedCodecs, GetDefaultCodecs());

    FLUENT_SETTING_DEFAULT(ui32, Version, 0);
    FLUENT_SETTING(std::string, ServiceType);

    TReadRuleSettings& SetSettings(const TDescribeTopicResult::TTopicSettings::TReadRule& settings) {
        ConsumerName_ = settings.ConsumerName();
        Important_ = settings.Important();
        StartingMessageTimestamp_ = settings.StartingMessageTimestamp();
        SupportedFormat_ = settings.SupportedFormat();
        SupportedCodecs_.clear();
        for (const auto& codec : settings.SupportedCodecs()) {
            SupportedCodecs_.push_back(codec);
        }
        Version_ = settings.Version();
        ServiceType_ = settings.ServiceType();
        return *this;
    }

};

// Settings for topic.
template <class TDerived>
struct TTopicSettings : public TOperationRequestSettings<TDerived> {

    struct TRemoteMirrorRuleSettings {
        TRemoteMirrorRuleSettings() {}
        using TSelf = TRemoteMirrorRuleSettings;
        FLUENT_SETTING(std::string, Endpoint);
        FLUENT_SETTING(std::string, TopicPath);
        FLUENT_SETTING(std::string, ConsumerName);
        FLUENT_SETTING_DEFAULT(TInstant, StartingMessageTimestamp, TInstant::Zero());
        FLUENT_SETTING(TCredentials, Credentials);
        FLUENT_SETTING(std::string, Database);

        TRemoteMirrorRuleSettings& SetSettings(const TDescribeTopicResult::TTopicSettings::TRemoteMirrorRule& settings) {
            Endpoint_ = settings.Endpoint();
            TopicPath_ = settings.TopicPath();
            ConsumerName_ = settings.ConsumerName();
            StartingMessageTimestamp_ = settings.StartingMessageTimestamp();
            Credentials_ = settings.Credentials();
            Database_ = settings.Database();
            return *this;
        }

    };

    using TSelf = TDerived;

    FLUENT_SETTING_DEFAULT(ui32, PartitionsCount, 1);
    FLUENT_SETTING_DEFAULT(TDuration, RetentionPeriod, TDuration::Hours(18));
    FLUENT_SETTING_DEFAULT(EFormat, SupportedFormat, EFormat::BASE)
    FLUENT_SETTING_DEFAULT(std::vector<ECodec>, SupportedCodecs, GetDefaultCodecs());

    FLUENT_SETTING_DEFAULT(ui64, MaxPartitionStorageSize, 0);
    FLUENT_SETTING_DEFAULT(ui64, MaxPartitionWriteSpeed, 2_MB);
    FLUENT_SETTING_DEFAULT(ui64, MaxPartitionWriteBurst, 2_MB);

    FLUENT_SETTING_DEFAULT(bool, ClientWriteDisabled, false);
    FLUENT_SETTING_DEFAULT(bool, AllowUnauthenticatedWrite, false);
    FLUENT_SETTING_DEFAULT(bool, AllowUnauthenticatedRead, false);

    FLUENT_SETTING_OPTIONAL(ui32, PartitionsPerTablet);

    FLUENT_SETTING_OPTIONAL(ui32, AbcId);
    FLUENT_SETTING_OPTIONAL(std::string, AbcSlug);
    FLUENT_SETTING_OPTIONAL(std::string, FederationAccount);

    //TODO: FLUENT_SETTING_VECTOR
    FLUENT_SETTING_DEFAULT(std::vector<TReadRuleSettings>, ReadRules, {});
    FLUENT_SETTING_OPTIONAL(TRemoteMirrorRuleSettings, RemoteMirrorRule);

    TSelf& SetSettings(const TDescribeTopicResult::TTopicSettings& settings) {

        PartitionsCount_ = settings.PartitionsCount();
        RetentionPeriod_ = settings.RetentionPeriod();
        SupportedFormat_ = settings.SupportedFormat();
        SupportedCodecs_.clear();
        for (const auto& codec : settings.SupportedCodecs()) {
            SupportedCodecs_.push_back(codec);
        }
        MaxPartitionStorageSize_ = settings.MaxPartitionStorageSize();
        MaxPartitionWriteSpeed_ = settings.MaxPartitionWriteSpeed();
        MaxPartitionWriteBurst_ = settings.MaxPartitionWriteBurst();
        ClientWriteDisabled_ = settings.ClientWriteDisabled();
        AllowUnauthenticatedRead_ = settings.AllowUnauthenticatedRead();
        AllowUnauthenticatedWrite_ = settings.AllowUnauthenticatedWrite();
        PartitionsPerTablet_ = settings.PartitionsPerTablet();
        AbcId_ = settings.AbcId();
        AbcSlug_ = settings.AbcSlug();
        FederationAccount_ = settings.FederationAccount();
        ReadRules_.clear();
        for (const auto& readRule : settings.ReadRules()) {
            ReadRules_.push_back({});
            ReadRules_.back().SetSettings(readRule);
        }
        if (settings.RemoteMirrorRule()) {
            RemoteMirrorRule_ = TRemoteMirrorRuleSettings().SetSettings(settings.RemoteMirrorRule().value());
        }
        return static_cast<TDerived&>(*this);
    }

};


// Settings for create resource request.
struct TCreateTopicSettings : public TTopicSettings<TCreateTopicSettings> {
};

// Settings for alter resource request.
struct TAlterTopicSettings : public TTopicSettings<TAlterTopicSettings> {
};

// Settings for drop resource request.
struct TDropTopicSettings : public TOperationRequestSettings<TDropTopicSettings> {};

// Settings for describe resource request.
struct TDescribeTopicSettings : public TOperationRequestSettings<TDescribeTopicSettings> {};

// Settings for add read rule request
struct TAddReadRuleSettings : public TTopicSettings<TAddReadRuleSettings> {
    FLUENT_SETTING(TReadRuleSettings, ReadRule);
};

// Settings for remove read rule request
struct TRemoveReadRuleSettings : public TOperationRequestSettings<TRemoveReadRuleSettings> {
    FLUENT_SETTING(std::string, ConsumerName);
};


//! Session metainformation.
struct TWriteSessionMeta : public TThrRefBase {
    using TPtr = TIntrusivePtr<TWriteSessionMeta>;

    //! User defined fields.
    THashMap<std::string, std::string> Fields;
};

//! Message levelmetainformation.
struct TMessageMeta : public TThrRefBase {
    using TPtr = TIntrusivePtr<TWriteSessionMeta>;

    //! User defined fields.
    std::vector<std::pair<std::string, std::string>> Fields;
};

//! Event that is sent to client during session destruction.
struct TSessionClosedEvent : public TStatus {
    using TStatus::TStatus;

    std::string DebugString() const;
};

struct TWriteStat : public TThrRefBase {
    TDuration WriteTime;
    TDuration TotalTimeInPartitionQueue;
    TDuration PartitionQuotedTime;
    TDuration TopicQuotedTime;
    using TPtr = TIntrusivePtr<TWriteStat>;
};

//enum class ECodec {
//    EWC_RAW,
//    EWC_GZIP,
//    EWC_LZOP,
//    EWC_ZSTD
//};


enum class EClusterDiscoveryMode {
    Auto = 0, // enables cluster discovery only for hostname "logbroker.yandex.net" and "logbroker-prestable.yandex.net"
    On,
    Off
};

class TContinuationToken : public TNonCopyable {
    friend class TContinuationTokenIssuer;

    bool Valid = true;

public:
    TContinuationToken& operator=(TContinuationToken&& other) {
        if (!other.Valid) {
            ythrow TContractViolation("Cannot move invalid token");
        }
        Valid = std::exchange(other.Valid, false);
        return *this;
    }

    TContinuationToken(TContinuationToken&& other) {
        *this = std::move(other);
    }

private:
    TContinuationToken() = default;
};

class TContinuationTokenIssuer {
protected:
    static auto IssueContinuationToken() {
        return TContinuationToken{};
    }
};

struct TWriterCounters : public TThrRefBase {
    using TSelf = TWriterCounters;
    using TPtr = TIntrusivePtr<TSelf>;

    explicit TWriterCounters(const TIntrusivePtr<::NMonitoring::TDynamicCounters>& counters);

    ::NMonitoring::TDynamicCounters::TCounterPtr Errors;
    ::NMonitoring::TDynamicCounters::TCounterPtr CurrentSessionLifetimeMs;

    ::NMonitoring::TDynamicCounters::TCounterPtr BytesWritten;
    ::NMonitoring::TDynamicCounters::TCounterPtr MessagesWritten;
    ::NMonitoring::TDynamicCounters::TCounterPtr BytesWrittenCompressed;

    ::NMonitoring::TDynamicCounters::TCounterPtr BytesInflightUncompressed;
    ::NMonitoring::TDynamicCounters::TCounterPtr BytesInflightCompressed;
    ::NMonitoring::TDynamicCounters::TCounterPtr BytesInflightTotal;
    ::NMonitoring::TDynamicCounters::TCounterPtr MessagesInflight;

    //! Histograms reporting % usage of memory limit in time.
    //! Provides a histogram looking like: 10% : 100ms, 20%: 300ms, ... 50%: 200ms, ... 100%: 50ms
    //! Which means that < 10% memory usage was observed for 100ms during the period and 50% usage was observed for 200ms
    //! Used to monitor if the writer successfully deals with data flow provided. Larger values in higher buckets
    //! mean that writer is close to overflow (or being overflown) for major periods of time
    //! 3 histograms stand for:
    //! Total memory usage:
    ::NMonitoring::THistogramPtr TotalBytesInflightUsageByTime;
    //! Memory usage by messages waiting for comression:
    ::NMonitoring::THistogramPtr UncompressedBytesInflightUsageByTime;
    //! Memory usage by compressed messages pending for write:
    ::NMonitoring::THistogramPtr CompressedBytesInflightUsageByTime;
};

struct TReaderCounters : public TThrRefBase {
    using TSelf = TReaderCounters;
    using TPtr = TIntrusivePtr<TSelf>;

    TReaderCounters() = default;
    explicit TReaderCounters(const TIntrusivePtr<::NMonitoring::TDynamicCounters>& counters);

    ::NMonitoring::TDynamicCounters::TCounterPtr Errors;
    ::NMonitoring::TDynamicCounters::TCounterPtr CurrentSessionLifetimeMs;

    ::NMonitoring::TDynamicCounters::TCounterPtr BytesRead;
    ::NMonitoring::TDynamicCounters::TCounterPtr MessagesRead;
    ::NMonitoring::TDynamicCounters::TCounterPtr BytesReadCompressed;

    ::NMonitoring::TDynamicCounters::TCounterPtr BytesInflightUncompressed;
    ::NMonitoring::TDynamicCounters::TCounterPtr BytesInflightCompressed;
    ::NMonitoring::TDynamicCounters::TCounterPtr BytesInflightTotal;
    ::NMonitoring::TDynamicCounters::TCounterPtr MessagesInflight;

    //! Histograms reporting % usage of memory limit in time.
    //! Provides a histogram looking like: 10% : 100ms, 20%: 300ms, ... 50%: 200ms, ... 100%: 50ms
    //! Which means that < 10% memory usage was observed for 100ms during the period and 50% usage was observed for 200ms
    //! Used to monitor if the read session successfully deals with data flow provided. Larger values in higher buckets
    //! mean that read session is close to overflow (or being overflown) for major periods of time.
    //!
    //! Total memory usage.
    ::NMonitoring::THistogramPtr TotalBytesInflightUsageByTime;
    //! Memory usage by messages waiting that are ready to be received by user.
    ::NMonitoring::THistogramPtr UncompressedBytesInflightUsageByTime;
    //! Memory usage by compressed messages pending for decompression.
    ::NMonitoring::THistogramPtr CompressedBytesInflightUsageByTime;
};

//! Partition stream.
struct TPartitionStream : public TThrRefBase {
    using TPtr = TIntrusivePtr<TPartitionStream>;


public:

    //! Temporary stop receiving data from this partition stream.
    // virtual void StopReading() = 0; // Not implemented yet.

    //! Resume receiving data from this partition stream after StopReading() call.
    // virtual void ResumeReading() = 0; // Not implemented yet.

    //! Request partition stream status.
    //! Result will come to TPartitionStreamStatusEvent.
    virtual void RequestStatus() = 0;

    //!
    //! Properties.
    //!

    //! Unique identifier of partition stream inside session.
    //! It is unique inside one read session.
    ui64 GetPartitionStreamId() const {
        return PartitionStreamId;
    }

    //! Topic path.
    const std::string& GetTopicPath() const {
        return TopicPath;
    }

    //! Cluster name.
    const std::string& GetCluster() const {
        return Cluster;
    }

    //! Partition group id.
    ui64 GetPartitionGroupId() const {
        return PartitionGroupId;
    }

    //! Partition id.
    ui64 GetPartitionId() const {
        return PartitionId;
    }

protected:
    ui64 PartitionStreamId;
    std::string TopicPath;
    std::string Cluster;
    ui64 PartitionGroupId;
    ui64 PartitionId;
};


//! Events for read session.
struct TReadSessionEvent {

    //! Event with new data.
    //! Contains batch of messages from single partition stream.
    struct TDataReceivedEvent {

        struct TMessageInformation {
            TMessageInformation(ui64 offset,
                                std::string messageGroupId,
                                ui64 seqNo,
                                TInstant createTime,
                                TInstant writeTime,
                                std::string ip,
                                TWriteSessionMeta::TPtr meta,
                                ui64 uncompressedSize);
            ui64 Offset;
            std::string MessageGroupId;
            ui64 SeqNo;
            TInstant CreateTime;
            TInstant WriteTime;
            std::string Ip;
            TWriteSessionMeta::TPtr Meta;
            ui64 UncompressedSize;
        };

        class IMessage {
        public:
            virtual const std::string& GetData() const;

            //! Partition stream. Same as in batch.
            const TPartitionStream::TPtr& GetPartitionStream() const;

            const std::string& GetPartitionKey() const;

            const std::string GetExplicitHash() const;

            virtual void Commit() = 0;

            std::string DebugString(bool printData = false) const;
            virtual void DebugString(TStringBuilder& ret, bool printData = false) const = 0;

            IMessage(const std::string& data,
                     TPartitionStream::TPtr partitionStream,
                     const std::string& partitionKey,
                     const std::string& explicitHash);

            virtual ~IMessage() = default;
        protected:
            std::string Data;

            TPartitionStream::TPtr PartitionStream;
            std::string PartitionKey;
            std::string ExplicitHash;
        };

        //! Single message.
        struct TMessage : public IMessage {
            //! User data.
            //! Throws decompressor exception if decompression failed.
            const std::string& GetData() const override;

            bool HasException() const;

            //! Message offset.
            ui64 GetOffset() const;

            //! Message group id.
            const std::string& GetMessageGroupId() const;

            //! Sequence number.
            ui64 GetSeqNo() const;

            //! Message creation timestamp.
            TInstant GetCreateTime() const;

            //! Message write timestamp.
            TInstant GetWriteTime() const;

            //! Ip address of message source host.
            const std::string& GetIp() const;

            //! Metainfo.
            const TWriteSessionMeta::TPtr& GetMeta() const;

            TMessage(const std::string& data,
                     std::exception_ptr decompressionException,
                     const TMessageInformation& information,
                     TPartitionStream::TPtr partitionStream,
                     const std::string& partitionKey,
                     const std::string& explicitHash);

            //! Commits single message.
            void Commit() override;

            using IMessage::DebugString;
            void DebugString(TStringBuilder& ret, bool printData = false) const override;

        private:
            std::exception_ptr DecompressionException;
            TMessageInformation Information;
        };

        struct TCompressedMessage : public IMessage {
            //! Messages count in compressed data
            ui64 GetBlocksCount() const;

            //! Message codec
            ECodec GetCodec() const;

            //! Message offset.
            ui64 GetOffset(ui64 index) const;

            //! Message group id.
            const std::string& GetMessageGroupId(ui64 index) const;

            //! Sequence number.
            ui64 GetSeqNo(ui64 index) const;

            //! Message creation timestamp.
            TInstant GetCreateTime(ui64 index) const;

            //! Message write timestamp.
            TInstant GetWriteTime(ui64 index) const;

            //! Ip address of message source host.
            const std::string& GetIp(ui64 index) const;

            //! Metainfo.
            const TWriteSessionMeta::TPtr& GetMeta(ui64 index) const;

            //! Uncompressed block size.
            ui64 GetUncompressedSize(ui64 index) const;

            virtual ~TCompressedMessage() {}
            TCompressedMessage(ECodec codec,
                               const std::string& data,
                               const std::vector<TMessageInformation>& information,
                               TPartitionStream::TPtr partitionStream,
                               const std::string& partitionKey,
                               const std::string& explicitHash);

            //! Commits all offsets in compressed message.
            void Commit() override;

            using IMessage::DebugString;
            void DebugString(TStringBuilder& ret, bool printData = false) const override;

        private:
            ECodec Codec;
            std::vector<TMessageInformation> Information;
        };

        //! Partition stream.
        const TPartitionStream::TPtr& GetPartitionStream() const {
            return PartitionStream;
        }

        bool IsCompressedMessages() const {
            return !CompressedMessages.empty();
        }

        size_t GetMessagesCount() const {
            return Messages.size() + CompressedMessages.size();
        }

        //! Get messages.
        std::vector<TMessage>& GetMessages() {
            CheckMessagesFilled(false);
            return Messages;
        }

        const std::vector<TMessage>& GetMessages() const {
            CheckMessagesFilled(false);
            return Messages;
        }

        //! Get compressed messages.
        std::vector<TCompressedMessage>& GetCompressedMessages() {
            CheckMessagesFilled(true);
            return CompressedMessages;
        }

        const std::vector<TCompressedMessage>& GetCompressedMessages() const {
            CheckMessagesFilled(true);
            return CompressedMessages;
        }

        //! Commits all messages in batch.
        void Commit();

        std::string DebugString(bool printData = false) const;

        TDataReceivedEvent(std::vector<TMessage> messages,
                           std::vector<TCompressedMessage> compressedMessages,
                           TPartitionStream::TPtr partitionStream);

    private:
        void CheckMessagesFilled(bool compressed) const {
            Y_ABORT_UNLESS(!Messages.empty() || !CompressedMessages.empty());
            if (compressed && CompressedMessages.empty()) {
                ythrow yexception() << "cannot get compressed messages, parameter decompress=true for read session";
            }
            if (!compressed && Messages.empty()) {
                ythrow yexception() << "cannot get decompressed messages, parameter decompress=false for read session";
            }
        }

    private:
        std::vector<TMessage> Messages;
        std::vector<TCompressedMessage> CompressedMessages;
        TPartitionStream::TPtr PartitionStream;
        std::vector<std::pair<ui64, ui64>> OffsetRanges;
    };

    //! Acknowledgement for commit request.
    struct TCommitAcknowledgementEvent {
        //! Partition stream.
        const TPartitionStream::TPtr& GetPartitionStream() const {
            return PartitionStream;
        }

        //! Committed offset.
        //! This means that from now the first available
        //! message offset in current partition
        //! for current consumer is this offset.
        //! All messages before are committed and futher never be available.
        ui64 GetCommittedOffset() const {
            return CommittedOffset;
        }

        std::string DebugString() const;

        TCommitAcknowledgementEvent(TPartitionStream::TPtr partitionStream, ui64 committedOffset);

    private:
        TPartitionStream::TPtr PartitionStream;
        ui64 CommittedOffset;
    };

    //! Server request for creating partition stream.
    struct TCreatePartitionStreamEvent {
        TCreatePartitionStreamEvent(TPartitionStream::TPtr, ui64 committedOffset, ui64 endOffset);

        const TPartitionStream::TPtr& GetPartitionStream() const {
            return PartitionStream;
        }

        //! Current committed offset in partition stream.
        ui64 GetCommittedOffset() const {
            return CommittedOffset;
        }

        //! Offset of first not existing message in partition stream.
        ui64 GetEndOffset() const {
            return EndOffset;
        }

        //! Confirm partition stream creation.
        //! This signals that user is ready to receive data from this partition stream.
        //! If maybe is empty then no rewinding
        void Confirm(std::optional<ui64> readOffset = std::nullopt, std::optional<ui64> commitOffset = std::nullopt);

        std::string DebugString() const;

    private:
        TPartitionStream::TPtr PartitionStream;
        ui64 CommittedOffset;
        ui64 EndOffset;
    };

    //! Server request for destroying partition stream.
    //! Server can destroy partition stream gracefully
    //! for rebalancing among all topic clients.
    struct TDestroyPartitionStreamEvent {
        const TPartitionStream::TPtr& GetPartitionStream() const {
            return PartitionStream;
        }

        //! Last offset of the partition stream that was committed.
        ui64 GetCommittedOffset() const {
            return CommittedOffset;
        }

        //! Confirm partition stream destruction.
        //! Confirm has no effect if TPartitionStreamClosedEvent for same partition stream with is received.
        void Confirm();

        std::string DebugString() const;

        TDestroyPartitionStreamEvent(TPartitionStream::TPtr partitionStream, bool committedOffset);

    private:
        TPartitionStream::TPtr PartitionStream;
        ui64 CommittedOffset;
    };

    //! Status for partition stream requested via TPartitionStream::RequestStatus()
    struct TPartitionStreamStatusEvent {
        const TPartitionStream::TPtr& GetPartitionStream() const {
            return PartitionStream;
        }

        //! Committed offset.
        ui64 GetCommittedOffset() const {
            return CommittedOffset;
        }

        //! Offset of next message (that is not yet read by session).
        ui64 GetReadOffset() const {
            return ReadOffset;
        }

        //! Offset of first not existing message in partition.
        ui64 GetEndOffset() const {
            return EndOffset;
        }

        //! Write watermark.
        //! The last written timestamp of message in this partition stream.
        TInstant GetWriteWatermark() const {
            return WriteWatermark;
        }

        std::string DebugString() const;

        TPartitionStreamStatusEvent(TPartitionStream::TPtr partitionStream, ui64 committedOffset, ui64 readOffset, ui64 endOffset, TInstant writeWatermark);

    private:
        TPartitionStream::TPtr PartitionStream;
        ui64 CommittedOffset = 0;
        ui64 ReadOffset = 0;
        ui64 EndOffset = 0;
        TInstant WriteWatermark;
    };

    //! Event that signals user about
    //! partition stream death.
    //! This could be after graceful destruction of
    //! partition stream or when connection with partition was lost.
    struct TPartitionStreamClosedEvent {
        enum class EReason {
            DestroyConfirmedByUser,
            Lost,
            ConnectionLost,
        };

        const TPartitionStream::TPtr& GetPartitionStream() const {
            return PartitionStream;
        }

        EReason GetReason() const {
            return Reason;
        }

        std::string DebugString() const;

        TPartitionStreamClosedEvent(TPartitionStream::TPtr partitionStream, EReason reason);

    private:
        TPartitionStream::TPtr PartitionStream;
        EReason Reason;
    };

    using TEvent = std::variant<TDataReceivedEvent,
                                TCommitAcknowledgementEvent,
                                TCreatePartitionStreamEvent,
                                TDestroyPartitionStreamEvent,
                                TPartitionStreamStatusEvent,
                                TPartitionStreamClosedEvent,
                                TSessionClosedEvent>;
};

//! Set of offsets to commit.
//! Class that could store offsets in order to commit them later.
//! This class is not thread safe.
class TDeferredCommit {
public:
    //! Add message to set.
    void Add(const TReadSessionEvent::TDataReceivedEvent::TMessage& message);

    //! Add all messages from dataReceivedEvent to set.
    void Add(const TReadSessionEvent::TDataReceivedEvent& dataReceivedEvent);

    //! Add offsets range to set.
    void Add(const TPartitionStream::TPtr& partitionStream, ui64 startOffset, ui64 endOffset);

    //! Add offset to set.
    void Add(const TPartitionStream::TPtr& partitionStream, ui64 offset);

    //! Commit all added offsets.
    void Commit();

    TDeferredCommit();
    TDeferredCommit(const TDeferredCommit&) = delete;
    TDeferredCommit(TDeferredCommit&&);
    TDeferredCommit& operator=(const TDeferredCommit&) = delete;
    TDeferredCommit& operator=(TDeferredCommit&&);

    ~TDeferredCommit();

private:
    class TImpl;
    THolder<TImpl> Impl;
};

//! Event debug string.
std::string DebugString(const TReadSessionEvent::TEvent& event);


//! Retry policy.
//! Calculates delay before next retry.
//! Has several default implementations:
//! - exponential backoff policy;
//! - retries with fixed interval;
//! - no retries.

struct IRetryPolicy : ::IRetryPolicy<EStatus> {
    //!
    //! Default implementations.
    //!

    static TPtr GetDefaultPolicy(); // Exponential backoff with infinite retry attempts.
    static TPtr GetNoRetryPolicy(); // Denies all kind of retries.

    //! Randomized exponential backoff policy.
    static TPtr GetExponentialBackoffPolicy(TDuration minDelay = TDuration::MilliSeconds(10),
                                            // Delay for statuses that require waiting before retry (such as OVERLOADED).
                                            TDuration minLongRetryDelay = TDuration::MilliSeconds(200),
                                            TDuration maxDelay = TDuration::Seconds(30),
                                            size_t maxRetries = std::numeric_limits<size_t>::max(),
                                            TDuration maxTime = TDuration::Max(),
                                            double scaleFactor = 2.0,
                                            std::function<ERetryErrorClass(EStatus)> customRetryClassFunction = {});

    //! Randomized fixed interval policy.
    static TPtr GetFixedIntervalPolicy(TDuration delay = TDuration::MilliSeconds(100),
                                       // Delay for statuses that require waiting before retry (such as OVERLOADED).
                                       TDuration longRetryDelay = TDuration::MilliSeconds(300),
                                       size_t maxRetries = std::numeric_limits<size_t>::max(),
                                       TDuration maxTime = TDuration::Max(),
                                       std::function<ERetryErrorClass(EStatus)> customRetryClassFunction = {});
};

class IExecutor : public TThrRefBase {
public:
    using TPtr = TIntrusivePtr<IExecutor>;
    using TFunction = std::function<void()>;

    // Is executor asynchronous.
    virtual bool IsAsync() const = 0;

    // Post function to execute.
    virtual void Post(TFunction&& f) = 0;

    // Start method.
    // This method is idempotent.
    // It can be called many times. Only the first one has effect.
    void Start() {
        std::lock_guard guard(StartLock);
        if (!Started) {
            DoStart();
            Started = true;
        }
    }

private:
    virtual void DoStart() = 0;

private:
    bool Started = false;
    TAdaptiveLock StartLock;
};

IExecutor::TPtr CreateThreadPoolExecutorAdapter(std::shared_ptr<IThreadPool> threadPool); // Thread pool is expected to have been started.
IExecutor::TPtr CreateThreadPoolExecutor(size_t threads);

IExecutor::TPtr CreateSyncExecutor();

//! Events for write session.
struct TWriteSessionEvent {

    //! Event with acknowledge for written messages.
    struct TWriteAck {
        //! Write result.
        enum EEventState {
            EES_WRITTEN, //! Successfully written.
            EES_ALREADY_WRITTEN, //! Skipped on SeqNo deduplication.
            EES_DISCARDED //! In case of destruction of writer or retry policy discarded future retries in this writer.
        };
        //! Details of successfully written message.
        struct TWrittenMessageDetails {
            ui64 Offset;
            ui64 PartitionId;
        };
        //! Same SeqNo as provided on write.
        ui64 SeqNo;
        EEventState State;
        //! Filled only for EES_WRITTEN. Empty for ALREADY and DISCARDED.
        std::optional<TWrittenMessageDetails> Details;
        //! Write stats from server. See TWriteStat. nullptr for DISCARDED event.
        TWriteStat::TPtr Stat;

    };

    struct TAcksEvent {
        //! Acks could be batched from several WriteBatch/Write requests.
        //! Acks for messages from one WriteBatch request could be emitted as several TAcksEvents -
        //! they are provided to client as soon as possible.
        std::vector<TWriteAck> Acks;

        std::string DebugString() const;

    };

    //! Indicates that a writer is ready to accept new message(s).
    //! Continuation token should be kept and then used in write methods.
    struct TReadyToAcceptEvent {
        mutable TContinuationToken ContinuationToken;

        TReadyToAcceptEvent() = delete;
        TReadyToAcceptEvent(TContinuationToken&& t) : ContinuationToken(std::move(t)) {
        }
        TReadyToAcceptEvent(TReadyToAcceptEvent&&) = default;
        TReadyToAcceptEvent(const TReadyToAcceptEvent& other) : ContinuationToken(std::move(other.ContinuationToken)) {
        }
        TReadyToAcceptEvent& operator=(TReadyToAcceptEvent&&) = default;
        TReadyToAcceptEvent& operator=(const TReadyToAcceptEvent& other) {
            ContinuationToken = std::move(other.ContinuationToken);
            return *this;
        }

        std::string DebugString() const;
    };

    using TEvent = std::variant<TAcksEvent, TReadyToAcceptEvent, TSessionClosedEvent>;
};

//! Event debug string.
std::string DebugString(const TWriteSessionEvent::TEvent& event);

using TSessionClosedHandler = std::function<void(const TSessionClosedEvent&)>;

//! Settings for write session.
struct TWriteSessionSettings : public TRequestSettings<TWriteSessionSettings> {
    using TSelf = TWriteSessionSettings;

    TWriteSessionSettings() = default;
    TWriteSessionSettings(const TWriteSessionSettings&) = default;
    TWriteSessionSettings(TWriteSessionSettings&&) = default;
    TWriteSessionSettings(const std::string& path, const std::string& messageGroupId) {
        Path(path);
        MessageGroupId(messageGroupId);
    }

    TWriteSessionSettings& operator=(const TWriteSessionSettings&) = default;
    TWriteSessionSettings& operator=(TWriteSessionSettings&&) = default;

    //! Path of topic to write.
    FLUENT_SETTING(std::string, Path);

    //! MessageGroupId (aka SourceId) to use.
    FLUENT_SETTING(std::string, MessageGroupId);

    //! Write to an exact partition group. Generally server assigns partition group automatically.
    //! Using this option is not recommended unless you know for sure why you need it.
    FLUENT_SETTING_OPTIONAL(ui32, PartitionGroupId);

    //! Preferred LB cluster. Used for multi-cluster installation.
    //! If specified cluster is unavailable, session will write to other cluster.
    FLUENT_SETTING_OPTIONAL(std::string, PreferredCluster);

    //! Write to other clusters if there are problems with connection
    //! to the first one.
    FLUENT_SETTING_DEFAULT(bool, AllowFallbackToOtherClusters, true);

    //! codec and level to use for data compression prior to write.
    FLUENT_SETTING_DEFAULT(ECodec, Codec, ECodec::GZIP);
    FLUENT_SETTING_DEFAULT(i32, CompressionLevel, 4);

    //! Writer will not accept new messages if memory usage exceeds this limit.
    //! Memory usage consists of raw data pending compression and compressed messages being sent.
    FLUENT_SETTING_DEFAULT(ui64, MaxMemoryUsage, 20_MB);

    //! Maximum messages accepted by writer but not written (with confirmation from server).
    //! Writer will not accept new messages after reaching the limit.
    FLUENT_SETTING_DEFAULT(ui32, MaxInflightCount, 100000);

    //! Retry policy enables automatic retries for non-fatal errors.
    //! IRetryPolicy::GetDefaultPolicy() if null (not set).
    FLUENT_SETTING(IRetryPolicy::TPtr, RetryPolicy);

    //! User metadata that may be attached to write session.
    TWriteSessionSettings& AppendSessionMeta(const std::string& key, const std::string& value) {
        Meta_.Fields[key] = value;
        return *this;
    };

    NYdb::NPersQueue::TWriteSessionMeta Meta_;

    //! Writer will accumulate messages until reaching up to BatchFlushSize bytes
    //! but for no longer than BatchFlushInterval.
    //! Upon reaching FlushInterval or FlushSize limit, all messages will be written with one batch.
    //! Greatly increases performance for small messages.
    //! Setting either value to zero means immediate write with no batching. (Unrecommended, especially for clients
    //! sending small messages at high rate).
    FLUENT_SETTING_OPTIONAL(TDuration, BatchFlushInterval);
    FLUENT_SETTING_OPTIONAL(ui64, BatchFlushSizeBytes);

    FLUENT_SETTING_DEFAULT(TDuration, ConnectTimeout, TDuration::Seconds(30));

    FLUENT_SETTING_OPTIONAL(TWriterCounters::TPtr, Counters);

    //! Executor for compression tasks.
    //! If not set, default executor will be used.
    FLUENT_SETTING(IExecutor::TPtr, CompressionExecutor);

    struct TEventHandlers {
        using TSelf = TEventHandlers;
        using TWriteAckHandler = std::function<void(TWriteSessionEvent::TAcksEvent&)>;
        using TReadyToAcceptHandler = std::function<void(TWriteSessionEvent::TReadyToAcceptEvent&)>;

        //! Function to handle Acks events.
        //! If this handler is set, write ack events will be handled by handler,
        //! otherwise sent to TWriteSession::GetEvent().
        FLUENT_SETTING(TWriteAckHandler, AcksHandler);

        //! Function to handle ReadyToAccept event.
        //! If this handler is set, write these events will be handled by handler,
        //! otherwise sent to TWriteSession::GetEvent().
        FLUENT_SETTING(TReadyToAcceptHandler, ReadyToAcceptHandler);
        TSelf& ReadyToAcceptHander(const TReadyToAcceptHandler& value) {
            return ReadyToAcceptHandler(value);
        }

        //! Function to handle close session events.
        //! If this handler is set, close session events will be handled by handler
        //! and then sent to TWriteSession::GetEvent().
        FLUENT_SETTING(TSessionClosedHandler, SessionClosedHandler);

        //! Function to handle all event types.
        //! If event with current type has no handler for this type of event,
        //! this handler (if specified) will be used.
        //! If this handler is not specified, event can be received with TWriteSession::GetEvent() method.
        FLUENT_SETTING(std::function<void(TWriteSessionEvent::TEvent&)>, CommonHandler);

        //! Executor for handlers.
        //! If not set, default single threaded executor will be used.
        FLUENT_SETTING(IExecutor::TPtr, HandlersExecutor);
    };

    //! Event handlers.
    FLUENT_SETTING(TEventHandlers, EventHandlers);

    //! Enables validation of SeqNo. If enabled, then writer will check writing with seqNo and without it and throws exception.
    FLUENT_SETTING_DEFAULT(bool, ValidateSeqNo, true);

    //! Manages cluster discovery mode.
    FLUENT_SETTING_DEFAULT(EClusterDiscoveryMode, ClusterDiscoveryMode, EClusterDiscoveryMode::Auto);
};

//! Read settings for single topic.
struct TTopicReadSettings {
    using TSelf = TTopicReadSettings;

    TTopicReadSettings() = default;
    TTopicReadSettings(const TTopicReadSettings&) = default;
    TTopicReadSettings(TTopicReadSettings&&) = default;
    TTopicReadSettings(const std::string& path) {
        Path(path);
    }

    TTopicReadSettings& operator=(const TTopicReadSettings&) = default;
    TTopicReadSettings& operator=(TTopicReadSettings&&) = default;

    //! Path of topic to read.
    FLUENT_SETTING(std::string, Path);

    //! Start reading from this timestamp.
    FLUENT_SETTING_OPTIONAL(TInstant, StartingMessageTimestamp);

    //! Partition groups to read.
    //! 1-based.
    FLUENT_SETTING_VECTOR(ui64, PartitionGroupIds);
};

//! Settings for read session.
struct TReadSessionSettings : public TRequestSettings<TReadSessionSettings> {
    using TSelf = TReadSessionSettings;

    struct TEventHandlers {
        using TSelf = TEventHandlers;

        //! Set simple handler with data processing and also
        //! set other handlers with default behaviour.
        //! They automatically commit data after processing
        //! and confirm partition stream events.
        //!
        //! Sets the following handlers:
        //! DataReceivedHandler: sets DataReceivedHandler to handler that calls dataHandler and (if commitDataAfterProcessing is set) then calls Commit().
        //! CommitAcknowledgementHandler to handler that does nothing.
        //! CreatePartitionStreamHandler to handler that confirms event.
        //! DestroyPartitionStreamHandler to handler that confirms event.
        //! PartitionStreamStatusHandler to handler that does nothing.
        //! PartitionStreamClosedHandler to handler that does nothing.
        //!
        //! dataHandler: handler of data event.
        //! commitDataAfterProcessing: automatically commit data after calling of dataHandler.
        //! gracefulReleaseAfterCommit: wait for commit acknowledgements for all inflight data before confirming partition stream destroy.
        TSelf& SimpleDataHandlers(std::function<void(TReadSessionEvent::TDataReceivedEvent&)> dataHandler, bool commitDataAfterProcessing = false, bool gracefulReleaseAfterCommit = true);

        //! Data size limit for the DataReceivedHandler handler.
        //! The data size may exceed this limit.
        FLUENT_SETTING_DEFAULT(size_t, MaxMessagesBytes, Max<size_t>());

        //! Function to handle data events.
        //! If this handler is set, data events will be handled by handler,
        //! otherwise sent to TReadSession::GetEvent().
        //! Default value is empty function (not set).
        FLUENT_SETTING(std::function<void(TReadSessionEvent::TDataReceivedEvent&)>, DataReceivedHandler);

        //! Function to handle commit ack events.
        //! If this handler is set, commit ack events will be handled by handler,
        //! otherwise sent to TReadSession::GetEvent().
        //! Default value is empty function (not set).
        FLUENT_SETTING(std::function<void(TReadSessionEvent::TCommitAcknowledgementEvent&)>, CommitAcknowledgementHandler);

        //! Function to handle create partition stream events.
        //! If this handler is set, create partition stream events will be handled by handler,
        //! otherwise sent to TReadSession::GetEvent().
        //! Default value is empty function (not set).
        FLUENT_SETTING(std::function<void(TReadSessionEvent::TCreatePartitionStreamEvent&)>, CreatePartitionStreamHandler);

        //! Function to handle destroy partition stream events.
        //! If this handler is set, destroy partition stream events will be handled by handler,
        //! otherwise sent to TReadSession::GetEvent().
        //! Default value is empty function (not set).
        FLUENT_SETTING(std::function<void(TReadSessionEvent::TDestroyPartitionStreamEvent&)>, DestroyPartitionStreamHandler);

        //! Function to handle partition stream status events.
        //! If this handler is set, partition stream status events will be handled by handler,
        //! otherwise sent to TReadSession::GetEvent().
        //! Default value is empty function (not set).
        FLUENT_SETTING(std::function<void(TReadSessionEvent::TPartitionStreamStatusEvent&)>, PartitionStreamStatusHandler);

        //! Function to handle partition stream closed events.
        //! If this handler is set, partition stream closed events will be handled by handler,
        //! otherwise sent to TReadSession::GetEvent().
        //! Default value is empty function (not set).
        FLUENT_SETTING(std::function<void(TReadSessionEvent::TPartitionStreamClosedEvent&)>, PartitionStreamClosedHandler);

        //! Function to handle session closed events.
        //! If this handler is set, close session events will be handled by handler
        //! and then sent to TReadSession::GetEvent().
        //! Default value is empty function (not set).
        FLUENT_SETTING(TSessionClosedHandler, SessionClosedHandler);

        //! Function to handle all event types.
        //! If event with current type has no handler for this type of event,
        //! this handler (if specified) will be used.
        //! If this handler is not specified, event can be received with TReadSession::GetEvent() method.
        FLUENT_SETTING(std::function<void(TReadSessionEvent::TEvent&)>, CommonHandler);

        //! Executor for handlers.
        //! If not set, default single threaded executor will be used.
        FLUENT_SETTING(IExecutor::TPtr, HandlersExecutor);
    };

    //! Consumer.
    FLUENT_SETTING(std::string, ConsumerName);

    //! Topics.
    FLUENT_SETTING_VECTOR(TTopicReadSettings, Topics);

    //! Default variant.
    //! Read topic instance specified in "Topics" from all clusters.
    TSelf& ReadAll() {
        Clusters_.clear();
        return ReadOnlyOriginal(true);
    }

    //! Read original topic instances specified in "Topics" from several clusters.
    TSelf& ReadOriginal(std::vector<std::string> clusters) {
        Clusters_ = std::move(clusters);
        return ReadOnlyOriginal(true);
    }

    //! Read mirrored topics specified in "Topics" from one cluster.
    TSelf& ReadMirrored(const std::string& cluster) {
        Clusters_ = { cluster };
        return ReadOnlyOriginal(false);
    }

    //! Disable Clusters discovery. ReadMirrored/ReadOriginal/ReadAll will not have any effect
    //! if this option is true.
    FLUENT_SETTING_DEFAULT(bool, DisableClusterDiscovery, false);

    //! Maximum memory usage for read session.
    FLUENT_SETTING_DEFAULT(size_t, MaxMemoryUsageBytes, 100_MB);

    //! Max message time lag. All messages older that now - MaxTimeLag will be ignored.
    FLUENT_SETTING_OPTIONAL(TDuration, MaxTimeLag);

    //! Start reading from this timestamp.
    FLUENT_SETTING_OPTIONAL(TInstant, StartingMessageTimestamp);

    //! Policy for reconnections.
    //! IRetryPolicy::GetDefaultPolicy() if null (not set).
    FLUENT_SETTING(IRetryPolicy::TPtr, RetryPolicy);

    //! Event handlers.
    //! See description in TEventHandlers class.
    FLUENT_SETTING(TEventHandlers, EventHandlers);

    //! Decompress messages
    FLUENT_SETTING_DEFAULT(bool, Decompress, true);

    //! Executor for decompression tasks.
    //! If not set, default executor will be used.
    FLUENT_SETTING(IExecutor::TPtr, DecompressionExecutor);

    //! Counters.
    //! If counters are not provided explicitly,
    //! they will be created inside session (without link with parent counters).
    FLUENT_SETTING(TReaderCounters::TPtr, Counters);

    //! Read only original topic instance, don't read mirrored.
    //!
    //! It's better to control this setting via ReadAll()/ReadMirrored()/ReadOriginal() helpers.
    FLUENT_SETTING_DEFAULT(bool, ReadOnlyOriginal, true);

    //! Read topics from specified clusters.
    //!
    //! It's better to control this setting via ReadAll()/ReadMirrored()/ReadOriginal() helpers.
    //!
    //! 1. If ReadOnlyOriginal is true and Clusters are empty read will be done from all topic instances from all clusters.
    //! Use ReadAll() function for this variant.
    //! 2. If ReadOnlyOriginal is true and Clusters are not empty read will be done from specified clusters.
    //! Use ReadOriginal() function for this variant.
    //! 3. If ReadOnlyOriginal is false and one cluster is specified read will be done from all topic instances (mirrored and original) in one cluster.
    //! Use ReadMirrored() function for this variant.
    FLUENT_SETTING_VECTOR(std::string, Clusters);

    FLUENT_SETTING_DEFAULT(TDuration, ConnectTimeout, TDuration::Seconds(30));

    //! Experimental option
    FLUENT_SETTING_OPTIONAL(bool, RangesMode);

    //! Log.
    FLUENT_SETTING_OPTIONAL(TLog, Log);
};

//! Simple write session. Does not need event handlers. Does not provide Events, ContinuationTokens, write Acks.
class ISimpleBlockingWriteSession : public TThrRefBase {
public:
    //! Write single message. Blocks for up to blockTimeout if inflight is full or memoryUsage is exceeded;
    //! return - true if write succeeded, false if message was not enqueued for write within blockTimeout.
    //! no Ack is provided.
    virtual bool Write(std::string_view data, std::optional<ui64> seqNo = std::nullopt, std::optional<TInstant> createTimestamp = std::nullopt,
                       const TDuration& blockTimeout = TDuration::Max()) = 0;

    //! Blocks till SeqNo is discovered from server. Returns 0 in case of failure on init.
    virtual ui64 GetInitSeqNo() = 0;

    //! Complete all active writes, wait for ack from server and close.
    //! closeTimeout - max time to wait. Empty Maybe means infinity.
    //! return - true if all writes were completed and acked. false if timeout was reached and some writes were aborted.

    virtual bool Close(TDuration closeTimeout = TDuration::Max()) = 0;

    //! Returns true if write session is alive and acitve. False if session was closed.
    virtual bool IsAlive() const = 0;

    virtual TWriterCounters::TPtr GetCounters() = 0;

    //! Close immediately and destroy, don't wait for anything.
    virtual ~ISimpleBlockingWriteSession() = default;
};

//! Generic write session with all capabilities.
class IWriteSession {
public:
    //! Future that is set when next event is available.
    virtual NThreading::TFuture<void> WaitEvent() = 0;

    //! Wait and return next event. Use WaitEvent() for non-blocking wait.
    virtual std::optional<TWriteSessionEvent::TEvent> GetEvent(bool block = false) = 0;

    //! Get several events in one call.
    //! If blocking = false, instantly returns up to maxEventsCount available events.
    //! If blocking = true, blocks till maxEventsCount events are available.
    //! If maxEventsCount is unset, write session decides the count to return itself.
    virtual std::vector<TWriteSessionEvent::TEvent> GetEvents(bool block = false, std::optional<size_t> maxEventsCount = std::nullopt) = 0;

    //! Future that is set when initial SeqNo is available.
    virtual NThreading::TFuture<ui64> GetInitSeqNo() = 0;

    //! Write single message.
    //! continuationToken - a token earlier provided to client with ReadyToAccept event.
    virtual void Write(TContinuationToken&& continuationToken, std::string_view data, std::optional<ui64> seqNo = std::nullopt, std::optional<TInstant> createTimestamp = std::nullopt) = 0;

    //! Write single message that is already coded by codec. Codec from settings does not apply to this message.
    //! continuationToken - a token earlier provided to client with ReadyToAccept event.
    //! originalSize - size of unpacked message
    virtual void WriteEncoded(TContinuationToken&& continuationToken, std::string_view data, ECodec codec, ui32 originalSize, std::optional<ui64> seqNo = std::nullopt, std::optional<TInstant> createTimestamp = std::nullopt) = 0;


    //! Wait for all writes to complete (no more that closeTimeout()), than close. Empty maybe - means infinite timeout.
    //! return - true if all writes were completed and acked. false if timeout was reached and some writes were aborted.
    virtual bool Close(TDuration closeTimeout = TDuration::Max()) = 0;

    //! Writer counters with different stats (see TWriterConuters).
    virtual TWriterCounters::TPtr GetCounters() = 0;

    //! Close() with timeout = 0 and destroy everything instantly.
    virtual ~IWriteSession() = default;
};

class IReadSession {
public:
    //! Main reader loop.
    //! Wait for next reader event.
    virtual NThreading::TFuture<void> WaitEvent() = 0;

    //! Main reader loop.
    //! Get read session events.
    //! Blocks until event occurs if "block" is set.
    //!
    //! maxEventsCount: maximum events count in batch.
    //! maxByteSize: total size limit of data messages in batch.
    //! block: block until event occurs.
    //!
    //! If maxEventsCount is not specified,
    //! read session chooses event batch size automatically.
    virtual std::vector<TReadSessionEvent::TEvent> GetEvents(bool block = false, std::optional<size_t> maxEventsCount = std::nullopt, size_t maxByteSize = std::numeric_limits<size_t>::max()) = 0;

    //! Get single event.
    virtual std::optional<TReadSessionEvent::TEvent> GetEvent(bool block = false, size_t maxByteSize = std::numeric_limits<size_t>::max()) = 0;

    //! Add topic to session, in other words, start reading new topic.
    // virtual void AddTopic(const TTopicReadSettings& topicReadSettings) = 0; // Not implemented yet.

    //! Remove topic from session.
    // virtual void RemoveTopic(const std::string& path) = 0; // Not implemented yet.

    //! Remove partition groups of topic from session.
    // virtual void RemoveTopic(const std::string& path, const std::vector<ui64>& partitionGruops) = 0; // Not implemented yet.

    //! Stop reading data and process only control events.
    //! You might need this function if a receiving side
    //! is not ready to process data.
    virtual void StopReadingData() = 0;

    //! Resume reading data.
    virtual void ResumeReadingData() = 0;

    //! Close read session.
    //! Waits for all commit acknowledgments to arrive.
    //! Force close after timeout.
    //! This method is blocking.
    //! When session is closed,
    //! TSessionClosedEvent arrives.
    virtual bool Close(TDuration timeout = TDuration::Max()) = 0;

    //! Reader counters with different stats (see TReaderConuters).
    virtual TReaderCounters::TPtr GetCounters() const = 0;

    //! Get unique identifier of read session.
    virtual std::string GetSessionId() const = 0;

    virtual ~IReadSession() = default;
};

struct TPersQueueClientSettings : public TCommonClientSettingsBase<TPersQueueClientSettings> {
    using TSelf = TPersQueueClientSettings;

    //! Default executor for compression tasks.
    FLUENT_SETTING_DEFAULT(IExecutor::TPtr, DefaultCompressionExecutor, CreateThreadPoolExecutor(2));

    //! Default executor for callbacks.
    FLUENT_SETTING_DEFAULT(IExecutor::TPtr, DefaultHandlersExecutor, CreateThreadPoolExecutor(1));

    //! Manages cluster discovery mode.
    FLUENT_SETTING_DEFAULT(EClusterDiscoveryMode, ClusterDiscoveryMode, EClusterDiscoveryMode::Auto);
};

// PersQueue client.
class TPersQueueClient {
public:
    class TImpl;

    TPersQueueClient(const TDriver& driver, const TPersQueueClientSettings& settings = TPersQueueClientSettings());

    // Create a new topic.
    TAsyncStatus CreateTopic(const std::string& path, const TCreateTopicSettings& = {});

    // Update a topic.
    TAsyncStatus AlterTopic(const std::string& path, const TAlterTopicSettings& = {});

    // Delete a topic.
    TAsyncStatus DropTopic(const std::string& path, const TDropTopicSettings& = {});

    // Add topic read rule
    TAsyncStatus AddReadRule(const std::string& path, const TAddReadRuleSettings& = {});

    // Remove topic read rule
    TAsyncStatus RemoveReadRule(const std::string& path, const TRemoveReadRuleSettings& = {});

    // Describe settings of topic.
    TAsyncDescribeTopicResult DescribeTopic(const std::string& path, const TDescribeTopicSettings& = {});

    //! Create read session.
    std::shared_ptr<IReadSession> CreateReadSession(const TReadSessionSettings& settings);

    //! Create write session.
    std::shared_ptr<ISimpleBlockingWriteSession> CreateSimpleBlockingWriteSession(const TWriteSessionSettings& settings);
    std::shared_ptr<IWriteSession> CreateWriteSession(const TWriteSessionSettings& settings);

private:
    std::shared_ptr<TImpl> Impl_;
};

} // namespace NYdb::NPersQueue
