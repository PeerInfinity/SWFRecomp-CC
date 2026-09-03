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
		// Set by whoever recompiles a SWF that another SWF loads at runtime.
		// Absent = this is the movie the binary starts in.
		child_movie = tbl["input"]["child_movie"].value_or(false);
		try_helper = tbl["input"]["try_helper"].value_or(false);
		// Env override so CI / verify_output.py can force the mode on for a
		// whole corpus run without rewriting every test's config.toml.
		if (const char* e = getenv("SWF_TRY_HELPER"))
		{
			if (e[0] != '\0' && e[0] != '0') try_helper = true;
		}

		tu_split = (uint32_t) tbl["input"]["tu_split"].value_or(0);
		// Same env override, but the value carries the chunk target: CI forces
		// a deliberately tiny target so that even a small corpus test really
		// splits (at 1.5 MB nothing in the Ruffle corpus would).
		if (const char* e = getenv("SWF_TU_SPLIT"))
		{
			if (e[0] != '\0') tu_split = (uint32_t) strtoul(e, NULL, 10);
		}

		skip_avm1_payload = tbl["input"]["skip_avm1_payload"].value_or(false);
		// Same env override as try_helper: CI / verify_output.py force the
		// mode on for a whole corpus run without rewriting every config.toml.
		if (const char* e = getenv("SWF_SKIP_AVM1_PAYLOAD"))
		{
			if (e[0] != '\0' && e[0] != '0') skip_avm1_payload = true;
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