#pragma once

#include <fstream>

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

		Context() : inside_function2(false) {}
	};
};