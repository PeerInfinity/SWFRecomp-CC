#include <string>
#include <fstream>
#include <sstream>
#include <sys/stat.h>

#include <common.h>
#include <abc/abc_emit.hpp>
#include <abc/abc_devicefont.hpp>
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

		// Try-helper emission mode (config `try_helper` / SWF_TRY_HELPER).
		abc::setTryHelper(context.try_helper);
		// TU-split emission (config `tu_split` / SWF_TU_SPLIT).
		abc::setTuSplit(context.tu_split);

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

		// AVM2: write the RecompiledABC registry (no-op for AVM1 SWFs).
		swf.finalizeAbcEmit();

		// AVM1 main movie: the test.toml [fonts.*] device-font registry (the
		// ABC path emits its own in abc_timeline.c). Player-level state, so a
		// child movie never emits it. No file at all without named faces.
		if (!swf.is_as3 && !swf.isChildRecompile())
		{
			std::ostringstream dev;
			if (abc::emitAvm1DeviceFonts(dev))
			{
				ofstream dev_file(string("") + context.output_tags_folder + "device_fonts.c", ios_base::out);
				dev_file << dev.str();
			}
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