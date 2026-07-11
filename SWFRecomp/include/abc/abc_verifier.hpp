#pragma once

// Verifier / IR translation, modeled on Ruffle's core/src/avm2/verify.rs:
// a reachability-driven walk over the raw bytecode that translates each op
// into the resolved IR (abc_ir.hpp), rewrites branch offsets to op indices,
// resolves exception tables to op-index ranges, and then runs a static
// stack/scope-depth check (max_stack / max_scope_depth validation) that
// Ruffle leaves to avmplus semantics.
//
// The type-lattice optimizer (Ruffle's optimizer/) is deliberately NOT here;
// that is a later stage per SWFRecompDocs/plans/avm2-support-plan.md §4.1.

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
}
}
