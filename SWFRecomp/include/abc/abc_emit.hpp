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
		// symbol_prefix: prepended to every emitted FILE name and every
		//   EXPORTED symbol, so a child movie's ABC can link alongside the
		//   parent's (loader-arc tranche 6). Empty = main movie, and the
		//   output is then byte-identical to the pre-tranche-6 emitter.
		// char_id_base: added to the SymbolClass char ids in the registry,
		//   matching the same offset applied to the timeline tables.
		explicit AbcEmitter(std::string output_folder = "RecompiledABC",
		                    std::string symbol_prefix = "",
		                    u32 char_id_base = 0);

		// Emits abc<i>_tables.c + abc<i>_methods.c for one DoABC tag.
		// `bodies` is parallel to abc.method_bodies.
		void emitAbcTag(const AbcFile& abc, const std::vector<EmitBody>& bodies);

		// Emits a one-script stub tag whose script initializer throws
		// `message` as a VerifyError at load. Used when the ABC cannot be
		// parsed or validated AT ALL: avmplus reports such a file with a
		// catchable VerifyError, so dropping the DoABC (the old behaviour)
		// silently swallowed an error the SWF grades.
		void emitAbcLoadError(const std::string& message);

		// Writes abc_gen.h + abc_registry.c. Call once, after all tags.
		void finalize(const std::vector<std::pair<u16, std::string>>& symbol_bindings,
		              u8 swf_version);

		int tagCount() const { return next_tag_index_; }

	private:
		std::string folder_;
		std::string prefix_;
		u32 char_id_base_ = 0;
		bool dir_created_ = false;
		int next_tag_index_ = 0;

		void ensureDir();
	};
}
}
