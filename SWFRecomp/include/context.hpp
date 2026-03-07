#pragma once

#include <fstream>
#include <cstdint>
#include <sstream>

using std::string;
using std::ofstream;
using std::ostream;

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

		// RegisterCount of the current DefineFunction2 (registers >= this bleed through to caller)
		int function2_register_count;

		// Track if we're inside any function body (for halt check return type)
		bool in_function_body;

		// SWF version (needed for string encoding: SWF<6 uses Latin-1/Win-1252)
		uint8_t swf_version;

		Context() : inside_function2(false), function2_register_count(0), in_function_body(false), swf_version(0) {}
	};
};