#pragma once

#include "defs.h"

namespace NYql {
namespace NUdf {

inline ui8* CompressAsSparseBitmap(const ui8* src, size_t srcOffset, const ui8* sparseBitmap, ui8* dst, size_t count) {
    while (count--) {
        ui8 inputBit = (src[srcOffset >> 3] >> (srcOffset & 7)) & 1;
        *dst = inputBit;
        ++srcOffset;
        dst += *sparseBitmap++;
    }
    return dst;
}

template<bool Negate>
inline void CompressSparseImpl(ui8* dst, const ui8* srcSparse, size_t len) {
    while (len >= 8) {
        ui8 result = 0;
        result |= (*srcSparse++ & 1u) << 0;
        result |= (*srcSparse++ & 1u) << 1;
        result |= (*srcSparse++ & 1u) << 2;
        result |= (*srcSparse++ & 1u) << 3;
        result |= (*srcSparse++ & 1u) << 4;
        result |= (*srcSparse++ & 1u) << 5;
        result |= (*srcSparse++ & 1u) << 6;
        result |= (*srcSparse++ & 1u) << 7;
        if constexpr (Negate) {
            *dst++ = ~result;
        } else {
            *dst++ = result;
        }
        len -= 8;
    }
    if (len) {
        ui8 result = 0;
        for (ui8 i = 0; i < len; ++i) {
            result |= (*srcSparse++ & 1u) << i;
        }
        if constexpr (Negate) {
            *dst++ = ~result;
        } else {
            *dst++ = result;
        }
    }
}

inline void CompressSparseBitmap(ui8* dst, const ui8* srcSparse, size_t len) {
    return CompressSparseImpl<false>(dst, srcSparse, len);
}

inline void CompressSparseBitmapNegate(ui8* dst, const ui8* srcSparse, size_t len) {
    return CompressSparseImpl<true>(dst, srcSparse, len);
}

template<typename T>
inline T* CompressArray(const T* src, const ui8* sparseBitmap, T* dst, size_t count) {
    while (count--) {
        *dst = *src++;
        dst += *sparseBitmap++;
    }
    return dst;
}

}
}
