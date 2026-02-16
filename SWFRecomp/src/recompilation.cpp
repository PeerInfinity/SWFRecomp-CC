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
		
		context.tag_main = ofstream(string("") + context.output_tags_folder + "tagMain.c", ios_base::out);
		
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

		context.tag_main.close();
		context.constants.close();
		context.constants_header.close();
		context.out_draws.close();
		context.out_draws_header.close();
	}
};