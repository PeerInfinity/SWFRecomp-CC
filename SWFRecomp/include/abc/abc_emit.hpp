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
	// Try-helper emission mode (Config::try_helper / SWF_TRY_HELPER env var).
	// Call once before emitting. OFF by default, and at OFF every byte of the
	// emitted C is what it was before the option existed. ON, a method body
	// with an active exception table is emitted as an outer frame + a lifted
	// `<fn>_body` function driven by avm2_try_run (the runtime owns the
	// setjmp and the try frame's storage), so generated code never holds a
	// jmp_buf — required by the in-browser guest toolchain, whose jmp_buf is
	// a different size from the host's (assessment §3.1/§4.1).
	void setTryHelper(bool on);

	// TU-split emission (Config::tu_split / SWF_TU_SPLIT env var), in bytes
	// of C text per body chunk; 0 = off. Call once before emitting. At OFF
	// every byte of the emitted C is what it was before the option existed.
	// ON, abc<tag>_methods.c is emitted as N body chunks
	// (abc<tag>_methods_<k>.c, split at method boundaries, ~target bytes
	// each) plus the original file holding only the Avm2AbcMethodData table,
	// the signature arrays and extern declarations for the chunked symbols.
	// The in-browser clang's compile time grows super-linearly with TU size,
	// so this is what makes the biggest titles compile at all (assessment
	// §1.1/§1.3). A tag whose bodies fit in one chunk keeps today's file set.
	void setTuSplit(size_t target_bytes);

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
		// `symbol_frames` is parallel to `symbol_bindings` and `abc_frames` is
		// parallel to the emitted tag list; both may be short/empty, in which
		// case the missing entries emit frame 0 / eager (today's behaviour).
		void finalize(const std::vector<std::pair<u16, std::string>>& symbol_bindings,
		              u8 swf_version,
		              const std::vector<u32>& symbol_frames = {},
		              const std::vector<std::pair<u32, u8>>& abc_frames = {});

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
