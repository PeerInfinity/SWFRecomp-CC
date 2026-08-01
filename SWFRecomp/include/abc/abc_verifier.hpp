#pragma once

// Verifier / IR translation, modeled on Ruffle's core/src/avm2/verify.rs:
// a reachability-driven walk over the raw bytecode that translates each op
// into the resolved IR (abc_ir.hpp), rewrites branch offsets to op indices,
// resolves exception tables to op-index ranges, and then runs a static
// stack/scope-depth check (max_stack / max_scope_depth validation) that
// Ruffle leaves to avmplus semantics.
//
// A static operand TYPE pass runs after the depth pass (see the long comment
// above runTypeLattice in abc_verifier.cpp): a linear walk with a four-value
// lattice — Unknown / Any / Class(C) / ClassOf(C) — that resets everything to
// Unknown at every branch, switch and exception target, and raises avmplus's
// #1058 / #1051 / #1026 ONLY on affirmatively-known-wrong operands. Scoped in
// SWFRecompDocs/plans/abc-verifier-type-lattice-arc.md. Ruffle's full
// early-binding optimizer (optimizer/type_aware.rs) is still NOT here: this
// pass raises errors, it never changes which object a name resolves to.

#include <string>

#include <abc/abc_ir.hpp>
#include <abc/abc_parser.hpp>

namespace SWFRecomp
{
namespace abc
{
	// Cross-reference validation of a parsed AbcFile: every pool-internal
	// index (multiname -> ns/ns-set/string, ns -> string, ns-set -> ns) and
	// every table reference (traits -> methods/classes/metadata, instances ->
	// init methods, scripts, bodies) must be in range. Returns false and
	// fills `err` on the first violation. Runs once per file, so the
	// verifier can trust pool-internal references.
	bool validateAbcFile(const AbcFile& abc, VerifyError& err);

	// Verifies one method body and translates it to IR.
	// Returns false and fills `err` on verification failure.
	bool verifyMethodBody(const AbcFile& abc, u32 body_index, IrMethod& out, VerifyError& err);

	// Drops the type pass's cached per-AbcFile AbcTypeModel. validateAbcFile
	// already calls this; callers that verify bodies without validating first
	// must call it themselves.
	void resetVerifierTypeModel();

	// Names the SWF in the SWF_VERIFY_TYPES=<csv> audit report's first column.
	// No effect unless that env var is set.
	void setVerifierSourceLabel(const std::string& label);
}
}
