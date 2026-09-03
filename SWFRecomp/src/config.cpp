#include <cstdlib>
#include <iostream>

#include <config.hpp>

using std::string;
using std::string_view;

using namespace std::string_view_literals;

namespace SWFRecomp
{
	Config::Config()
	{
		
	}
	
	void Config::parseFile(string path)
	{
		tbl = toml::parse_file(path);
		
		string_view swf_path_view = parseStringView("path_to_swf");
		string_view output_tags_folder_view = parseStringView("output_tags_folder");
		string_view output_scripts_folder_view = parseStringView("output_scripts_folder");
		
		swf_path = string(swf_path_view);
		output_tags_folder = string(output_tags_folder_view);
		output_scripts_folder = string(output_scripts_folder_view);

		// Optional; absent means "this is the main movie" and every emitter
		// keeps its pre-tranche-6 output exactly.
		symbol_prefix = string(tbl["input"]["symbol_prefix"].value_or(""sv));
		char_id_base = (uint32_t) tbl["input"]["char_id_base"].value_or(0);
		try_helper = tbl["input"]["try_helper"].value_or(false);
		// Env override so CI / verify_output.py can force the mode on for a
		// whole corpus run without rewriting every test's config.toml.
		if (const char* e = getenv("SWF_TRY_HELPER"))
		{
			if (e[0] != '\0' && e[0] != '0') try_helper = true;
		}
	}
	
	string_view Config::parseStringView(string key)
	{
		string_view view = tbl["input"][key].value_or(""sv);
		
		if (view == "")
		{
			EXC_ARG("Error: field %s in toml must be present and non-empty\n", key.c_str());
		}
		
		return view;
	}
}