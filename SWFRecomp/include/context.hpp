#pragma once

#include <fstream>
#include <cstdint>

using std::string;
using std::ofstream;

namespace SWFRecomp
{
	struct Context
	{
		string swf_path;
		string output_tags_folder;
		string output_scripts_folder;

		ofstream tag_main;
		ofstream constants;
		ofstream constants_header;
		ofstream out_script_header;
		ofstream out_script_defs;
		ofstream out_script_decls;
		ofstream out_draws;
		ofstream out_draws_header;

		// Track if we're inside a DefineFunction2 (for local register handling)
		bool inside_function2;

		// SWF version (needed for string encoding: SWF<6 uses Latin-1/Win-1252)
		uint8_t swf_version;

		Context() : inside_function2(false), swf_version(0) {}
	};
};