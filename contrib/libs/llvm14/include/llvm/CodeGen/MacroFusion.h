#pragma once

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

//===- MacroFusion.h - Macro Fusion -----------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
/// \file This file contains the definition of the DAG scheduling mutation to
/// pair instructions back to back.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CODEGEN_MACROFUSION_H
#define LLVM_CODEGEN_MACROFUSION_H

#include <functional>
#include <memory>

namespace llvm {

class MachineInstr;
class ScheduleDAGMutation;
class TargetInstrInfo;
class TargetSubtargetInfo;
class ScheduleDAGInstrs;
class SUnit;

/// Check if the instr pair, FirstMI and SecondMI, should be fused
/// together. Given SecondMI, when FirstMI is unspecified, then check if
/// SecondMI may be part of a fused pair at all.
using ShouldSchedulePredTy = std::function<bool(const TargetInstrInfo &TII,
                                                const TargetSubtargetInfo &TSI,
                                                const MachineInstr *FirstMI,
                                                const MachineInstr &SecondMI)>;

/// Checks if the number of cluster edges between SU and its predecessors is
/// less than FuseLimit
bool hasLessThanNumFused(const SUnit &SU, unsigned FuseLimit);

/// Create an artificial edge between FirstSU and SecondSU.
/// Make data dependencies from the FirstSU also dependent on the SecondSU to
/// prevent them from being scheduled between the FirstSU and the SecondSU
/// and vice-versa.
/// Fusing more than 2 instructions is not currently supported.
bool fuseInstructionPair(ScheduleDAGInstrs &DAG, SUnit &FirstSU,
                         SUnit &SecondSU);

/// Create a DAG scheduling mutation to pair instructions back to back
/// for instructions that benefit according to the target-specific
/// shouldScheduleAdjacent predicate function.
std::unique_ptr<ScheduleDAGMutation>
createMacroFusionDAGMutation(ShouldSchedulePredTy shouldScheduleAdjacent);

/// Create a DAG scheduling mutation to pair branch instructions with one
/// of their predecessors back to back for instructions that benefit according
/// to the target-specific shouldScheduleAdjacent predicate function.
std::unique_ptr<ScheduleDAGMutation>
createBranchMacroFusionDAGMutation(ShouldSchedulePredTy shouldScheduleAdjacent);

} // end namespace llvm

#endif // LLVM_CODEGEN_MACROFUSION_H

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
