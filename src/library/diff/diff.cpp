#include "diff.h"

#include <src/util/generic/hash.h>
#include <src/util/digest/fnv.h>

#include <iterator>

template <typename T>
struct TCollectionImpl {
    std::vector<std::span<const T>> Words;
    std::vector<ui64> Keys;

    inline bool Consume(const T* b, const T* e, const T*) {
        if (b < e) {
            Words.push_back(std::span<const T>(b, e));
            Keys.push_back(FnvHash<ui64>((const char*)b, (e - b) * sizeof(T)));
        }
        return true;
    }

    std::span<const T> Remap(const std::span<const ui64>& keys) const {
        if (keys.empty()) {
            return std::span<const T>();
        }
        auto firstWordPos = std::distance(Keys.data(), keys.data());
        auto lastWordPos = std::distance(Keys.data(), keys.data() + keys.size()) - 1;
        Y_ASSERT(firstWordPos >= 0);
        Y_ASSERT(lastWordPos >= firstWordPos);
        Y_ASSERT(static_cast<size_t>(lastWordPos) < Words.size());

        return std::span<const T>(Words[firstWordPos].begin(), Words[lastWordPos].end());
    }

    std::span<const ui64> GetKeys() const {
        return std::span<const ui64>(Keys);
    }
};

template <typename T>
struct TCollection {
};

template <>
struct TCollection<char>: public TCollectionImpl<char> {
    TCollection(const std::string_view& str, const std::string& delims) {
        TSetDelimiter<const char> set(delims.data());
        TKeepDelimiters<TCollection<char>> c(this);
        SplitString(str.begin(), str.end(), set, c);
    }
};

template <>
struct TCollection<wchar16>: public TCollectionImpl<wchar16> {
    TCollection(const std::u16string_view& str, const std::u16string& delims) {
        TSetDelimiter<const wchar16> set(delims.data());
        TKeepDelimiters<TCollection<wchar16>> c(this);
        SplitString(str.begin(), str.end(), set, c);
    }
};

size_t NDiff::InlineDiff(std::vector<TChunk<char>>& chunks, const std::string_view& left, const std::string_view& right, const std::string& delims) {
    if (delims.empty()) {
        return InlineDiff<char>(chunks, std::span<const char>(left.data(), left.size()), std::span<const char>(right.data(), right.size()));
    }
    TCollection<char> c1(left, delims);
    TCollection<char> c2(right, delims);
    std::vector<TChunk<ui64>> diff;
    const size_t dist = InlineDiff<ui64>(diff, c1.GetKeys(), c2.GetKeys());
    for (const auto& it : diff) {
        chunks.push_back(TChunk<char>(c1.Remap(it.Left), c2.Remap(it.Right), c1.Remap(it.Common)));
    }
    return dist;
}

size_t NDiff::InlineDiff(std::vector<TChunk<wchar16>>& chunks, const std::u16string_view& left, const std::u16string_view& right, const std::u16string& delims) {
    if (delims.empty()) {
        return InlineDiff<wchar16>(chunks, std::span<const wchar16>(left.data(), left.size()), std::span<const wchar16>(right.data(), right.size()));
    }
    TCollection<wchar16> c1(left, delims);
    TCollection<wchar16> c2(right, delims);
    std::vector<TChunk<ui64>> diff;
    const size_t dist = InlineDiff<ui64>(diff, c1.GetKeys(), c2.GetKeys());
    for (const auto& it : diff) {
        chunks.push_back(TChunk<wchar16>(c1.Remap(it.Left), c2.Remap(it.Right), c1.Remap(it.Common)));
    }
    return dist;
}
