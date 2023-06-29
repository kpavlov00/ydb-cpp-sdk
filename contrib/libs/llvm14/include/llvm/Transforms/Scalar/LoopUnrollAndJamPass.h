#pragma once

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

//===- LoopUnrollAndJamPass.h -----------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TRANSFORMS_SCALAR_LOOPUNROLLANDJAMPASS_H
#define LLVM_TRANSFORMS_SCALAR_LOOPUNROLLANDJAMPASS_H

#include "llvm/IR/PassManager.h"
#include "llvm/Transforms/Scalar/LoopPassManager.h"

namespace llvm {

/// A simple loop rotation transformation.
class LoopUnrollAndJamPass : public PassInfoMixin<LoopUnrollAndJamPass> {
  const int OptLevel;

public:
  explicit LoopUnrollAndJamPass(int OptLevel = 2) : OptLevel(OptLevel) {}
  PreservedAnalyses run(LoopNest &L, LoopAnalysisManager &AM,
                        LoopStandardAnalysisResults &AR, LPMUpdater &U);
};

} // end namespace llvm

#endif // LLVM_TRANSFORMS_SCALAR_LOOPUNROLLANDJAMPASS_H

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
