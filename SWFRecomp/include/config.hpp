#pragma once

#include <toml++/toml.hpp>

#include <common.h>

namespace SWFRecomp
{
	class Config
	{
	public:
		toml::table tbl;
		std::string swf_path;
		std::string output_tags_folder;
		std::string output_scripts_folder;
		// Optional multi-SWF keys (loader-arc tranche 6). Both default to the
		// empty/zero value, and at those defaults the emitted output is
		// byte-identical to what it was before they existed — a child SWF
		// recompiled alongside a parent sets them, the main movie never does.
		//   symbol_prefix: prepended to every EXPORTED symbol and to every
		//     emitted file name in RecompiledABC/, so a child's tables can be
		//     linked into the same binary as the parent's.
		//   char_id_base:  added to every character id in the emitted tables,
		//     making ids globally unique across movies. ONE stride does both
		//     halves: the ABC/AVM2 emissions (SymbolClass registry + timeline
		//     tables) and, through swf.cpp's charId(), every character id the
		//     TAG pipeline writes. Character id 0 is never re-based — it is
		//     the "no character" sentinel, see charId().
		//     The caller picks the stride; the harness uses movie_id * 1000.
		//     Two ceilings bound how high it may go:
		//       - char ids are u16 in the runtime tables, so keep
		//         base + max_child_char_id under 65536;
		//       - the AVM1 dictionary is INITIAL_DICTIONARY_CAPACITY (8192)
		//         entries, and several bounds checks compare against that
		//         CONSTANT rather than the growable `dictionary_capacity`
		//         (tag_stubs.c:414/883/1511, action.c's button-MC probes),
		//         so a tag-side id at or above 8192 silently reads as "no
		//         such character" — in NO_GRAPHICS it is worse than silent,
		//         since swf_core.c never grows the array at all.
		std::string symbol_prefix;
		uint32_t char_id_base = 0;
		// True when this recompile is a CHILD movie of another SWF (loaded at
		// runtime by the parent), rather than the movie the binary starts in.
		// Nothing about the emitted C changes with it directly; it is the one
		// thing the recompiler cannot infer from the SWF itself, and the
		// dead-payload skip needs it (see skip_avm1_payload below). The caller
		// that recompiles a child sets `[input] child_movie = true`.
		bool child_movie = false;
		// Try-helper emission mode (assessment §4.1). OFF by default: at false
		// every emitter's output is byte-for-bit what it was before this
		// existed. On, every method / script region with an exception table is
		// emitted as a lifted body function driven by a runtime helper that
		// owns the setjmp, so generated code never holds a jmp_buf (needed by
		// the in-browser guest toolchain, whose jmp_buf is not the host's).
		// The SWF_TRY_HELPER env var forces it on regardless of the toml.
		bool try_helper = false;
		// TU-split emission (assessment §1.3), in bytes of C text per
		// abc<tag>_methods_<k>.c body chunk. 0 (the default) = off, and the
		// emitted C is then byte-for-bit what it was before this existed.
		// The SWF_TU_SPLIT env var overrides the toml (0 also turns it off).
		uint32_t tu_split = 0;
		// Dead-payload skip (assessment §2.2, "cheap extra win"). OFF by
		// default: at false the emitted C is byte-for-bit what it was before
		// this existed, for AVM1 and AS3 SWFs alike. On, an AS3 (is_as3) SWF
		// omits the AVM1-only byte payloads from RecompiledTags/draws.c —
		// bitmap_data, sound_data and video_data — which only tagInit's
		// defineBitmap / tagDefineSound and tagMain's tagVideoFrame read, and
		// runSWF_avm2 calls neither. AVM2 carries its own copies of those
		// bytes in RecompiledABC/abc_timeline.c. An AVM1 SWF is untouched at
		// any setting. The SWF_SKIP_AVM1_PAYLOAD env var forces it on.
		// ALSO gated on this recompile not being a child movie: `is_as3` means
		// "this SWF's code is AVM2", not "this SWF's tagInit never runs", and
		// an AS3 SWF loaded as a child by an AVM1 parent has its tagInit
		// called by the AVM1 loader (regression/avm1_parent_as3_child_payload).
		bool skip_avm1_payload = false;

		Config();
		void parseFile(std::string path);
		std::string_view parseStringView(std::string key);
	};
};