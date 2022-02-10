#include "events.h"
#include "actorsystem.h"

namespace NActors {
    TString TEvents::TEvUndelivered::ToStringHeader() const {
        return "TSystem::Undelivered";
    }

    bool TEvents::TEvUndelivered::SerializeToArcadiaStream(TChunkSerializer *serializer) const { 
        Y_VERIFY(!Unsure); // these are local-only events generated by Interconnect
        return serializer->WriteString(&Data);
    }

    void TEvents::TEvUndelivered::Out(IOutputStream& o, EReason x) {
        switch (x) {
        case ReasonActorUnknown:
            o << "ActorUnknown";
            break;
        case Disconnected:
            o << "Disconnected";
            break;
        default:
            o << "Undefined";
            break;
        }
    }

    bool TEvents::TEvUndelivered::IsSerializable() const {
        return true;
    }

    IEventBase* TEvents::TEvUndelivered::Load(TEventSerializedData* bufs) {
        TString str = bufs->GetString();
        Y_VERIFY(str.size() == (sizeof(ui32) + sizeof(ui32)));
        const char* p = str.data();
        const ui64 sourceType = ReadUnaligned<ui32>(p + 0);
        const ui64 reason = ReadUnaligned<ui32>(p + 4);
        return new TEvUndelivered(sourceType, reason);
    }

    TAutoPtr<IEventHandle> IEventHandle::ForwardOnNondelivery(ui32 reason, bool unsure) {
        if (Flags & FlagForwardOnNondelivery) {
            const ui32 updatedFlags = Flags & ~(FlagForwardOnNondelivery | FlagSubscribeOnSession);
            const TActorId recp = OnNondeliveryHolder ? OnNondeliveryHolder->Recipient : TActorId();

            if (Event)
                return new IEventHandle(recp, Sender, Event.Release(), updatedFlags, Cookie, &Recipient, TraceId.Clone());
            else
                return new IEventHandle(Type, updatedFlags, recp, Sender, Buffer, Cookie, &Recipient, TraceId.Clone());
        }

        if (Flags & FlagTrackDelivery) {
            const ui32 updatedFlags = Flags & ~(FlagTrackDelivery | FlagSubscribeOnSession | FlagGenerateUnsureUndelivered);
            return new IEventHandle(Sender, Recipient, new TEvents::TEvUndelivered(Type, reason, unsure), updatedFlags,
                Cookie, nullptr, TraceId.Clone());
        }

        return nullptr;
    }
}
