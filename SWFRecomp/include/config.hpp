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
		//     making ids globally unique across movies (the AVM1 pipeline's
		//     movie_id * 1000 trick). Char ids are u16 in the runtime tables,
		//     so keep base + max_child_char_id under 65536.
		std::string symbol_prefix;
		uint32_t char_id_base = 0;
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

		Config();
		void parseFile(std::string path);
		std::string_view parseStringView(std::string key);
	};
};