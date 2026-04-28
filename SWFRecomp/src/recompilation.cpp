#include <string>
#include <fstream>
#include <sys/stat.h>

#include <common.h>
#include <swf.hpp>

using std::string;
using std::to_string;

using std::ofstream;
using std::ios_base;
using std::endl;

namespace SWFRecomp
{
	void recompile(Context& context)
	{
		printf("\n");

		mkdir(context.output_tags_folder.c_str(), 0755);
		mkdir(context.output_scripts_folder.c_str(), 0755);

		context.output_tags_folder += '/';
		context.output_scripts_folder += '/';
		
		// tag_main is an in-memory stringstream during parsing so the
		// per-frame init prologue placeholder can be replaced on the fly.
		// It is flushed to tagMain.c at the end of recompile().
		context.tag_main.str("");
		context.tag_main.clear();

		context.constants = ofstream(string("") + context.output_tags_folder + "constants.c", ios_base::out);
		
		context.constants_header = ofstream(string("") + context.output_tags_folder + "constants.h", ios_base::out);
		context.constants_header << "#pragma once" << endl << endl;
		
		context.out_draws = ofstream(string("") + context.output_tags_folder + "draws.c", ios_base::out);
		context.out_draws << "#include \"recomp.h\"" << endl
						  << "#include \"draws.h\"";
		
		context.out_draws_header = ofstream(string("") + context.output_tags_folder + "draws.h", ios_base::out);
		context.out_draws_header << "#pragma once" << endl;
		
		SWF swf = SWF(context);

		try
		{
			swf.parseAllTags(context);
		}
		catch (const std::exception& e)
		{
			fprintf(stderr, "Caught exception in parseAllTags: %s\n", e.what());
		}
		catch (...)
		{
			fprintf(stderr, "Caught unknown exception in parseAllTags\n");
		}

		// Flush the accumulated tag_main buffer to tagMain.c.
		{
			ofstream tag_main_file(string("") + context.output_tags_folder + "tagMain.c", ios_base::out);
			tag_main_file << context.tag_main.str();
			tag_main_file.close();
		}
		context.constants.close();
		context.constants_header.close();
		context.out_draws.close();
		context.out_draws_header.close();
	}
};