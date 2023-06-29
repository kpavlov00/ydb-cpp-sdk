#pragma once

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

//===- EndianStream.h - Stream ops with endian specific data ----*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines utilities for operating on streams that have endian
// specific data.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_SUPPORT_ENDIANSTREAM_H
#define LLVM_SUPPORT_ENDIANSTREAM_H

#include "llvm/ADT/ArrayRef.h"
#include "llvm/Support/Endian.h"
#include "llvm/Support/MathExtras.h"
#include "llvm/Support/raw_ostream.h"

namespace llvm {
namespace support {

namespace endian {

template <typename value_type>
inline void write(raw_ostream &os, value_type value, endianness endian) {
  value = byte_swap<value_type>(value, endian);
  os.write((const char *)&value, sizeof(value_type));
}

template <>
inline void write<float>(raw_ostream &os, float value, endianness endian) {
  write(os, FloatToBits(value), endian);
}

template <>
inline void write<double>(raw_ostream &os, double value,
                          endianness endian) {
  write(os, DoubleToBits(value), endian);
}

template <typename value_type>
inline void write(raw_ostream &os, ArrayRef<value_type> vals,
                  endianness endian) {
  for (value_type v : vals)
    write(os, v, endian);
}

/// Adapter to write values to a stream in a particular byte order.
struct Writer {
  raw_ostream &OS;
  endianness Endian;
  Writer(raw_ostream &OS, endianness Endian) : OS(OS), Endian(Endian) {}
  template <typename value_type> void write(ArrayRef<value_type> Val) {
    endian::write(OS, Val, Endian);
  }
  template <typename value_type> void write(value_type Val) {
    endian::write(OS, Val, Endian);
  }
};

} // end namespace endian

} // end namespace support
} // end namespace llvm

#endif

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
