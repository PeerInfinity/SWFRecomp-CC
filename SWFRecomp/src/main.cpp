#include <iostream>
#include <cstring>
#include <exception>

#include <common.h>
#include <config.hpp>
#include <recompilation.hpp>
#include <abc/abc_tool.hpp>

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("Not enough arguments.\n"
		       "usage: %s <config-file>\n"
		       "       %s --dump-abc <file.swf>\n"
		       "       %s --check-abc <file.swf>...\n",
		       argv[0], argv[0], argv[0]);
		return -1;
	}

	if (strcmp(argv[1], "--dump-abc") == 0 || strcmp(argv[1], "--check-abc") == 0)
	{
		if (argc < 3)
		{
			printf("Not enough arguments.\nusage: %s %s <file.swf>...\n", argv[0], argv[1]);
			return -1;
		}
		return SWFRecomp::abc::abcToolMain(argc, argv);
	}

	SWFRecomp::Config config;
	config.parseFile(argv[1]);
	
	SWFRecomp::Context context;
	context.swf_path = config.swf_path;
	context.output_tags_folder = "RecompiledTags";
	context.output_scripts_folder = "RecompiledScripts";
	context.avm2_symbol_prefix = config.symbol_prefix;
	context.avm2_char_id_base = config.char_id_base;
	
	try
	{
		SWFRecomp::recompile(context);
	}
	catch (const std::exception& e)
	{
		// An escaping exception would otherwise surface as a bare abort (native)
		// or an opaque thrown pointer (Emscripten/in-browser recompiler).
		fflush(stdout);
		fprintf(stderr, "SWFRecomp: fatal: %s\n", e.what());
		return 2;
	}
	
	fflush(stdout);
	
	return 0;
}