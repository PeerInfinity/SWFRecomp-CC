#pragma once

// AVM2 C emitter (avm2-support-plan §4.1 final stage): consumes the parsed
// AbcFile + per-body verified IR and emits static C data + one C function
// per method body into RecompiledABC/, against the runtime contract in
// SWFModernRuntime/include/avm2/avm2_abc.h.
//
// Stage-2 opcode surface: exactly hello_world's 21 ops. Every other op
// emits a runtime abort (avm2_unimplemented_op) so unsupported avm2 tests
// fail honestly; since no branch op is in the supported set, control flow
// is strictly linear until the first unsupported op, and the remainder of
// such a body is safely omitted.

#include <string>
#include <utility>
#include <vector>

#include <abc/abc_ir.hpp>
#include <abc/abc_types.hpp>

namespace SWFRecomp
{
namespace abc
{
	// Per-body emit input: the verified IR, or the verify error if
	// verification failed (the emitted function then aborts at call time).
	struct EmitBody
	{
		bool verified = false;
		IrMethod ir;
		std::string verify_error;
	};

	class AbcEmitter
	{
	public:
		// output_folder: "RecompiledABC" (created lazily on first tag).
		explicit AbcEmitter(std::string output_folder = "RecompiledABC");

		// Emits abc<i>_tables.c + abc<i>_methods.c for one DoABC tag.
		// `bodies` is parallel to abc.method_bodies.
		void emitAbcTag(const AbcFile& abc, const std::vector<EmitBody>& bodies);

		// Writes abc_gen.h + abc_registry.c. Call once, after all tags.
		void finalize(const std::vector<std::pair<u16, std::string>>& symbol_bindings);

		int tagCount() const { return next_tag_index_; }

	private:
		std::string folder_;
		bool dir_created_ = false;
		int next_tag_index_ = 0;

		void ensureDir();
	};
}
}
