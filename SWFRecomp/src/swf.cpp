#define _USE_MATH_DEFINES
#include <algorithm>
#include <array>
#include <cmath>
#include <iomanip>
#include <sstream>

#include <zlib.h>
#include <lzma.h>
#include <earcut.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#define STB_TRUETYPE_IMPLEMENTATION
#include <stb_truetype.h>

#include <swf.hpp>

#define MIN(x, y) ((x < y) ? x : y)
#define MAX(x, y) ((x > y) ? x : y)

#define VAL(type, x) (*((type*) x))

#define CROSS(v1, v2) (v1.x*v2.y - v2.x*v1.y)

// ---------------------------------------------------------------------------
// Device font (Noto Sans) for headless glyph rendering
// ---------------------------------------------------------------------------
static stbtt_fontinfo g_device_font;
static bool g_device_font_loaded = false;
static bool g_device_font_ok = false;
static unsigned char* g_device_font_data = NULL;

static std::string g_device_font_path; // set from argv[0] or explicit path

// Allows enabling the synthesized-glyph fallback via
// SWFRECOMP_DEVICE_FONT_FALLBACK=1. Default is disabled: SWF glyphs with
// empty outlines stay empty, and the runtime renderer keeps the advance
// but draws nothing — matching how Ruffle treats embedded fonts with
// deliberately-empty glyph slots.
static bool deviceFontFallbackEnabled()
{
	static int cached = -1;
	if (cached == -1) {
		const char* v = getenv("SWFRECOMP_DEVICE_FONT_FALLBACK");
		cached = (v && (v[0] == '1' || (v[0] == 't' && v[1] == 'r') ||
			(v[0] == 'T' && v[1] == 'R') || (v[0] == 'y' && v[1] == 'e') ||
			(v[0] == 'Y' && v[1] == 'E') || (v[0] == 'o' && v[1] == 'n') ||
			(v[0] == 'O' && v[1] == 'N'))) ? 1 : 0;
	}
	return cached != 0;
}

static bool loadDeviceFont()
{
	if (g_device_font_loaded) return g_device_font_ok;
	g_device_font_loaded = true;

	// Try explicit path first, then paths relative to the binary
	std::vector<std::string> paths;
	if (!g_device_font_path.empty()) paths.push_back(g_device_font_path);
	paths.push_back("assets/NotoSans.ttf");
	paths.push_back("../assets/NotoSans.ttf");
	paths.push_back("SWFRecomp/assets/NotoSans.ttf");
	paths.push_back("../SWFRecomp/assets/NotoSans.ttf");
	// Also try relative to /proc/self/exe on Linux
	{
		char exe_path[4096];
		ssize_t len = readlink("/proc/self/exe", exe_path, sizeof(exe_path) - 1);
		if (len > 0) {
			exe_path[len] = '\0';
			std::string exe_dir(exe_path);
			size_t slash = exe_dir.rfind('/');
			if (slash != std::string::npos) {
				exe_dir = exe_dir.substr(0, slash);
				paths.push_back(exe_dir + "/../assets/NotoSans.ttf");
				paths.push_back(exe_dir + "/assets/NotoSans.ttf");
			}
		}
	}

	FILE* f = NULL;
	for (auto& p : paths) {
		f = fopen(p.c_str(), "rb");
		if (f) break;
	}
	if (!f) return false;
	fseek(f, 0, SEEK_END);
	long sz = ftell(f);
	fseek(f, 0, SEEK_SET);
	g_device_font_data = (unsigned char*)malloc(sz);
	if (fread(g_device_font_data, 1, sz, f) != (size_t)sz) {
		free(g_device_font_data);
		g_device_font_data = NULL;
		fclose(f);
		return false;
	}
	fclose(f);
	g_device_font_ok = stbtt_InitFont(&g_device_font, g_device_font_data,
		stbtt_GetFontOffsetForIndex(g_device_font_data, 0)) != 0;
	return g_device_font_ok;
}

#define NOT_SHARED_LINKS(path1, path2) (std::find(path1.next_neighbors_forward.begin(), path1.next_neighbors_forward.end(), &path2) == path1.next_neighbors_forward.end() && \
										std::find(path2.next_neighbors_forward.begin(), path2.next_neighbors_forward.end(), &path1) == path2.next_neighbors_forward.end() && \
										std::find(path1.next_neighbors_backward.begin(), path1.next_neighbors_backward.end(), &path2) == path1.next_neighbors_backward.end() && \
										std::find(path2.next_neighbors_backward.begin(), path2.next_neighbors_backward.end(), &path1) == path2.next_neighbors_backward.end())

#define FRAME_WIDTH (header.frame_size.xmax - header.frame_size.xmin)
#define FRAME_HEIGHT (header.frame_size.ymax - header.frame_size.ymin)

using std::to_string;

using std::ifstream;
using std::ios_base;
using std::endl;

using Coord = s32;

using N = size_t;

using Point = std::array<Coord, 2>;

namespace SWFRecomp
{
	SWFHeader::SWFHeader()
	{
		
	}
	
	SWFHeader::SWFHeader(char* swf_buffer)
	{
		// Get the initial data (SWF is always little-endian)
		memcpy(this, swf_buffer, 8);
	}
	
	void SWFHeader::loadOtherData(char*& swf_buffer)
	{
		SWFTag rect;
		
		rect.setFieldCount(5);
		
		rect.configureNextField(SWF_FIELD_UB, 5, true);
		rect.configureNextField(SWF_FIELD_SB, 0);
		rect.configureNextField(SWF_FIELD_SB, 0);
		rect.configureNextField(SWF_FIELD_SB, 0);
		rect.configureNextField(SWF_FIELD_SB, 0);
		
		rect.parseFields(swf_buffer);
		
		frame_size.nbits = (u8) rect.fields[0].value;
		frame_size.xmin = (s32) rect.fields[1].value;
		frame_size.xmax = (s32) rect.fields[2].value;
		frame_size.ymin = (s32) rect.fields[3].value;
		frame_size.ymax = (s32) rect.fields[4].value;
		
		framerate = *((u16*) swf_buffer);
		swf_buffer += 2;
		
		frame_count = *((u16*) swf_buffer);
		swf_buffer += 2;
		
		printf("\n");
		
		printf("SWF version: %d\n", version);
		printf("Decompressed file length: %d\n", file_length);
		
		printf("\n");
		
		printf("Window dimensions:\n");
		printf("xmin: %d twips\n", frame_size.xmin);
		printf("xmax: %d twips\n", frame_size.xmax);
		printf("ymin: %d twips\n", frame_size.ymin);
		printf("ymax: %d twips\n", frame_size.ymax);
		
		printf("\n");
		
		printf("Which means resolution is %dx%d\n", (frame_size.xmax - frame_size.xmin)/20, (frame_size.ymax - frame_size.ymin)/20);
		
		printf("\n");
		
		printf("FPS: %d\n", framerate >> 8);
		printf("SWF frame count: %d\n", frame_count);
	}
	
	
	
	SWF::SWF()
	{
		
	}
	
	SWF::SWF(Context& context) : num_finished_tags(0),
								 next_frame_i(0),
								 another_frame(false),
								 next_script_i(0),
								 last_queued_script(0),
								 current_tri(0),
								 current_transform(0),
								 current_color(0),
								 current_uninv(0),
								 current_gradient(0),
								 current_bitmap_pixel(0),
								 current_bitmap(0),
								 current_glyph(0),
								 current_text(0),
								 current_cxform(0),
								 current_path_entry(0),
								 current_morph_end_vertex(0),
								 current_morph_end_color(0),
								 jpeg_tables(nullptr),
								 current_sound_byte(0),
								 current_sound_id(0),
								 has_streaming_sound(false),
								 current_video_byte(0),
							 shape_has_alpha(false),
							 shape_is_v4(false),
							 shape_is_morph2(false),
							 use_network(false)
	{
		// Configure reusable struct records
		//
		// Using a SWFTag without parsing the header
		// behaves exactly like a SWF struct record
		RGB.setFieldCount(3);
		RGB.configureNextField(SWF_FIELD_UI8);  // Red
		RGB.configureNextField(SWF_FIELD_UI8);  // Green
		RGB.configureNextField(SWF_FIELD_UI8);  // Blue

		RGBA.setFieldCount(4);
		RGBA.configureNextField(SWF_FIELD_UI8);  // Red
		RGBA.configureNextField(SWF_FIELD_UI8);  // Green
		RGBA.configureNextField(SWF_FIELD_UI8);  // Blue
		RGBA.configureNextField(SWF_FIELD_UI8);  // Alpha
		
		printf("Reading %s...\n", context.swf_path.c_str());
		
		ifstream swf_file(context.swf_path, ios_base::in | ios_base::binary);
		if (!swf_file.good())
		{
			EXC_ARG("SWF file `%s' not found\n", context.swf_path.c_str());
		}
		
		swf_file.seekg(0, ios_base::end);
		size_t swf_size = swf_file.tellg();
		swf_file.seekg(0, ios_base::beg);
		
		swf_buffer = new char[swf_size];
		swf_file.read(swf_buffer, swf_size);
		swf_file.close();
		
		header = SWFHeader(swf_buffer);
		
		switch (header.compression)
		{
			case 'F':
			{
				// uncompressed
				
				printf("SWF is uncompressed.\n");
				
				break;
			}
			
			case 'C':
			{
				// zlib
				
				printf("SWF is compressed with zlib. Decompressing...\n");
				
				char* swf_buffer_uncompressed = new char[header.file_length];
				memcpy(swf_buffer_uncompressed, swf_buffer, 8);
				long unsigned int swf_length_no_8 = header.file_length - 8;
				uncompress((u8*) &swf_buffer_uncompressed[8], &swf_length_no_8, const_cast<const u8*>((u8*) &swf_buffer[8]), (uLong) (swf_size - 8));
				
				delete[] swf_buffer;
				swf_buffer = swf_buffer_uncompressed;
				
				break;
			}
			
			case 'Z':
			{
				// lzma
				// Yeah, Adobe definitely screwed the format up on this one.
				// I'm not sure if they just didn't get it, or what...
				// Whatever this mangled garbage is, it's NOT REAL LZMA.
				
				printf("SWF is compressed with LZMA. Decompressing...\n");
				
				char* swf_buffer_uncompressed = new char[header.file_length];
				memcpy(swf_buffer_uncompressed, swf_buffer, 8);
				
				lzma_stream swf_lzma_stream = LZMA_STREAM_INIT;
				if (lzma_alone_decoder(&swf_lzma_stream, UINT64_MAX) != LZMA_OK)
				{
					EXC("Couldn't initialize LZMA decoding stream\n");
				}
				
				char lzma_header_swf[13];
				memcpy(&lzma_header_swf, &swf_buffer[12], 5);
				*((u64*) &lzma_header_swf[5]) = (u64) (header.file_length - 8);
				
				swf_lzma_stream.next_in = const_cast<const u8*>((u8*) lzma_header_swf);
				swf_lzma_stream.avail_in = 13;
				swf_lzma_stream.next_out = (u8*) &swf_buffer_uncompressed[8];
				swf_lzma_stream.avail_out = header.file_length - 8;
				
				lzma_ret ret = lzma_code(&swf_lzma_stream, LZMA_RUN);
				if (ret != LZMA_OK)
				{
					EXC_ARG("Couldn't successfully decode LZMA header, returned %d\n", ret);
				}
				
				swf_lzma_stream.next_in = const_cast<const u8*>((u8*) &swf_buffer[8 + 4 + 5]);
				swf_lzma_stream.avail_in = swf_size - 8 - 4 - 5;
				
				ret = lzma_code(&swf_lzma_stream, LZMA_FINISH);
				
				lzma_end(&swf_lzma_stream);
				
				delete[] swf_buffer;
				swf_buffer = swf_buffer_uncompressed;
				
				break;
			}
			
			default:
			{
				EXC("Invalid SWF compression format\n");
			}
		}
		
		cur_pos = swf_buffer + 8;
		
		header.loadOtherData(cur_pos);
		
		std::string width = to_string(FRAME_WIDTH/20);
		std::string height = to_string(FRAME_HEIGHT/20);
		std::string width_twips = to_string(FRAME_WIDTH);
		std::string height_twips = to_string(FRAME_HEIGHT);
		std::string swf_frame_count = to_string(header.frame_count);
		std::string frame_xmin_twips = to_string(header.frame_size.xmin);
		std::string frame_ymin_twips = to_string(header.frame_size.ymin);
		context.swf_version = header.version;

		context.constants_header << "#define FRAME_WIDTH " << width << endl
								 << "#define FRAME_HEIGHT " << height << endl
								 << "#define FRAME_WIDTH_TWIPS " << width_twips << endl
								 << "#define FRAME_HEIGHT_TWIPS " << height_twips << endl
								 << "#define FRAME_X_MIN_TWIPS " << frame_xmin_twips << endl
								 << "#define FRAME_Y_MIN_TWIPS " << frame_ymin_twips << endl
								 << "#define SWF_FRAME_COUNT " << swf_frame_count << endl
								 << "#define SWF_VERSION " << to_string((int)header.version) << endl << endl
								 << "extern const float stage_to_ndc[16];";
		
		context.constants << "#include \"constants.h\"" << endl << endl
						  << "const float stage_to_ndc[16] =" << endl
						  << "{" << endl
						  << "\t" << "1.0f/(FRAME_WIDTH_TWIPS/2.0f)," << endl
						  << "\t" << "0.0f," << endl
						  << "\t" << "0.0f," << endl
						  << "\t" << "0.0f," << endl
						  << "\t" << "0.0f," << endl
						  << "\t" << "-1.0f/(FRAME_HEIGHT_TWIPS/2.0f)," << endl
						  << "\t" << "0.0f," << endl
						  << "\t" << "0.0f," << endl
						  << "\t" << "0.0f," << endl
						  << "\t" << "0.0f," << endl
						  << "\t" << "1.0f," << endl
						  << "\t" << "0.0f," << endl
						  << "\t" << "-1.0f - (float)FRAME_X_MIN_TWIPS/(FRAME_WIDTH_TWIPS/2.0f)," << endl
						  << "\t" << "1.0f + (float)FRAME_Y_MIN_TWIPS/(FRAME_HEIGHT_TWIPS/2.0f)," << endl
						  << "\t" << "0.0f," << endl
						  << "\t" << "1.0f," << endl
						  << "};" << endl;
	}
	
	void SWF::parseMatrix(MATRIX& matrix_out)
	{
		u32 cur_byte_bits_left = 8;
		
		SWFTag matrix_tag;
		
		matrix_tag.clearFields();
		matrix_tag.setFieldCount(1);
		
		matrix_tag.configureNextField(SWF_FIELD_UB, 1);
		
		matrix_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);
		
		bool has_scale = matrix_tag.fields[0].value & 1;
		
		matrix_out.scale_x = 1;
		matrix_out.scale_y = 1;
		
		if (has_scale)
		{
			matrix_tag.clearFields();
			matrix_tag.setFieldCount(3);
			
			matrix_tag.configureNextField(SWF_FIELD_UB, 5, true);
			matrix_tag.configureNextField(SWF_FIELD_FB, 0);
			matrix_tag.configureNextField(SWF_FIELD_FB, 0);
			
			matrix_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);
			
			matrix_out.scale_x = VAL(float, &matrix_tag.fields[1].value);
			matrix_out.scale_y = VAL(float, &matrix_tag.fields[2].value);
		}
		
		matrix_tag.clearFields();
		matrix_tag.setFieldCount(1);
		
		matrix_tag.configureNextField(SWF_FIELD_UB, 1);
		
		matrix_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);
		
		bool has_rotate = matrix_tag.fields[0].value & 1;
		
		matrix_out.rotateskew_0 = 0;
		matrix_out.rotateskew_1 = 0;
		
		if (has_rotate)
		{
			matrix_tag.clearFields();
			matrix_tag.setFieldCount(3);
			
			matrix_tag.configureNextField(SWF_FIELD_UB, 5, true);
			matrix_tag.configureNextField(SWF_FIELD_FB, 0);
			matrix_tag.configureNextField(SWF_FIELD_FB, 0);
			
			matrix_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);
			
			matrix_out.rotateskew_0 = VAL(float, &matrix_tag.fields[1].value);
			matrix_out.rotateskew_1 = VAL(float, &matrix_tag.fields[2].value);
		}
		
		matrix_tag.clearFields();
		matrix_tag.setFieldCount(3);
		
		matrix_tag.configureNextField(SWF_FIELD_UB, 5, true);
		matrix_tag.configureNextField(SWF_FIELD_SB, 0);
		matrix_tag.configureNextField(SWF_FIELD_SB, 0);
		
		matrix_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);
		
		matrix_out.translate_x = (s32) matrix_tag.fields[1].value;
		matrix_out.translate_y = (s32) matrix_tag.fields[2].value;
		
		if (cur_byte_bits_left != 8)
		{
			cur_pos += 1;
		}
	}
	
	void SWF::writeFrameInitMarker(Context& context)
	{
		// Emit a unique placeholder marker that flushFrameInitPrologue
		// will later replace with the buffered DoInitAction / ImportAssets
		// calls for this frame. The id increments per-frame so different
		// frames' markers don't collide in tag_main's accumulating string.
		context.tag_main << "/*__SWFRECOMP_PROLOGUE_" << current_frame_marker_id << "__*/" << endl;
		frame_init_emitted = false;
	}

	void SWF::flushFrameInitPrologue(Context& context)
	{
		// Replace the most recently written placeholder marker in
		// context.tag_main with the accumulated init prologue body. If no
		// marker is found (e.g. helper called twice for the same frame),
		// silently no-op. Resets the buffer and bumps the marker id so
		// subsequent frames get a unique placeholder.
		if (frame_init_emitted) {
			return;
		}
		std::string s = context.tag_main.str();
		std::string marker = "/*__SWFRECOMP_PROLOGUE_" + to_string(current_frame_marker_id) + "__*/";
		size_t pos = s.find(marker);
		if (pos != std::string::npos) {
			std::string replacement = current_frame_init_actions.str();
			s.replace(pos, marker.length(), replacement);
			context.tag_main.str(s);
			context.tag_main.seekp(0, std::ios::end);
		}
		current_frame_init_actions.str("");
		current_frame_init_actions.clear();
		frame_init_emitted = true;
		current_frame_marker_id += 1;
	}

	void SWF::parseAllTags(Context& context)
	{
		SWFTag tag;

		context.tag_main << "#include <recomp.h>" << endl << endl
				 << "#include <out.h>" << endl
				 << "#include <sprite_frame_scripts.h>" << endl
				 << "#include \"draws.h\"" << endl
				 << "#include \"script_decls.h\"" << endl << endl
				 << "void frame_" << to_string(next_frame_i) << "(SWFAppContext* app_context)" << endl
				 << "{" << endl;
		writeFrameInitMarker(context);
		next_frame_i += 1;
		
		context.out_script_header = ofstream(context.output_scripts_folder + "out.h", ios_base::out);
		context.out_script_header << "#pragma once" << endl;
		
		context.out_script_defs = ofstream(context.output_scripts_folder + "script_defs.c", ios_base::out);
		context.out_script_defs << "#include <recomp.h>" << endl;
		context.out_script_defs << "#include \"script_decls.h\"" << endl;
		context.out_script_defs << "#include <string.h>" << endl;  // For memset
		
		context.out_script_decls = ofstream(context.output_scripts_folder + "script_decls.h", ios_base::out);
		context.out_script_decls << "#pragma once" << endl << endl
								 << "#include <stackvalue.h>" << endl
								 << "#include <variables.h>" << endl
								 << "#include <actionmodern/action.h>" << endl;
		
		// output identity matrix at transform id 0
		transform_data << "\t" << "1.0f," << endl
					   << "\t" << "0.0f," << endl
					   << "\t" << "0.0f," << endl
					   << "\t" << "0.0f," << endl
					   
					   << "\t" << "0.0f," << endl
					   << "\t" << "1.0f," << endl
					   << "\t" << "0.0f," << endl
					   << "\t" << "0.0f," << endl
					   
					   << "\t" << "0.0f," << endl
					   << "\t" << "0.0f," << endl
					   << "\t" << "1.0f," << endl
					   << "\t" << "0.0f," << endl
					   
					   << "\t" << "0.0f," << endl
					   << "\t" << "0.0f," << endl
					   << "\t" << "0.0f," << endl
					   << "\t" << "1.0f," << endl;
		
		current_transform += 1;

		// output identity cxform at id 0
		cxform_data << "\t" << "1.0f," << endl
					<< "\t" << "0.0f," << endl
					<< "\t" << "0.0f," << endl
					<< "\t" << "0.0f," << endl

					<< "\t" << "0.0f," << endl
					<< "\t" << "1.0f," << endl
					<< "\t" << "0.0f," << endl
					<< "\t" << "0.0f," << endl

					<< "\t" << "0.0f," << endl
					<< "\t" << "0.0f," << endl
					<< "\t" << "1.0f," << endl
					<< "\t" << "0.0f," << endl

					<< "\t" << "0.0f," << endl
					<< "\t" << "0.0f," << endl
					<< "\t" << "0.0f," << endl
					<< "\t" << "1.0f," << endl

					<< "\t" << "0.0f," << endl
					<< "\t" << "0.0f," << endl
					<< "\t" << "0.0f," << endl
					<< "\t" << "0.0f," << endl;

		current_cxform += 1;

		// prime the loop
		tag.code = (TagType) 1;
		
		char* swf_end = swf_buffer + header.file_length;
		while (tag.code != 0)
		{
			if (cur_pos >= swf_end)
			{
				fprintf(stderr, "Warning: cur_pos past end of SWF buffer, stopping tag parse\n");
				break;
			}
			char* tag_start = cur_pos;
			tag.parseHeader(cur_pos);
			char* tag_data_end = cur_pos + tag.length;
			try
			{
				interpretTag(context, tag);
			}
			catch (const std::exception& e)
			{
				fprintf(stderr, "Warning: tag %d failed: %s\n", tag.code, e.what());
			}
			// Always advance cur_pos to the end of the tag data,
			// even if the tag handler didn't consume all bytes
			cur_pos = tag_data_end;
			tag.clearFields();
		}
		

		// If we exited the tag loop early (cur_pos past end), close the current frame function
		if (tag.code != 0)
		{
			// Flush the per-frame init prologue placeholder before any
			// trailing frame-body emissions, so a frame whose tag stream
			// was truncated still gets its DoInitActions emitted in
			// the right place.
			flushFrameInitPrologue(context);
			// Flush pending ENTER_FRAME dispatch (after RemoveObject, before DoAction)
			context.tag_main << "\t" << "tagFlushPendingEnterFrame(app_context);" << endl;
			// Phase 6: drain queued root DoAction scripts. Kind-filtered so
			// Phase 4/5 CLIP_INIT/CONSTRUCT/REGISTER_CTOR entries stay on their
			// original drain timeline (outermost tagPlaceObject2 / tagShowFrame
			// safety drain).
			// Drain DoAction scripts AND queued unload handlers together in
			// FIFO order. The interleaved order matches Flash's ActionQueue
			// model: a tag-stream-order RemoveObject2 followed by DoAction
			// fires unload first; a DoAction followed by RemoveObject2 fires
			// the script first. (See DEFERRED_CLIP_UNLOAD_PLAN.)
			context.tag_main << "\t" << "if (!catch_up_mode || g_tag_skip_mode) actionDrainAllInPriorityOrder(app_context);" << endl;
			last_queued_script = next_script_i;

			// See END_TAG handler below for rationale: a frame opened by trailing
			// tags after the last ShowFrame (`another_frame == false`) should not
			// loop, otherwise its DoActions re-fire on each iteration.
			if (next_frame_i == 1 || !another_frame)
			{
				context.tag_main << "\t" << "quit_swf = 1;" << endl;
			}
			else
			{
				context.tag_main << "\t" << "if (!manual_next_frame && is_playing && !g_tag_skip_mode)" << endl
								 << "\t" << "{" << endl
								 << "\t\t" << "next_frame = 0;" << endl
								 << "\t\t" << "manual_next_frame = 1;" << endl
								 << "\t" << "}" << endl;
			}
			context.tag_main << "}" << endl;
		}

		// Emit sprite frame function definitions (before main frame_funcs array)
		if (!sprite_definitions.str().empty())
		{
			context.tag_main << endl << sprite_definitions.str();
		}

		// frame_func typedef is already defined in swf.h, no need to redefine
		context.tag_main << endl << endl
						 << "frame_func frame_funcs[] =" << endl
						 << "{" << endl;
		
		for (size_t i = 0; i < next_frame_i; ++i)
		{
			context.tag_main << "\t" << "frame_" << to_string(i) << "," << endl;
		}
		
		if (current_bitmap_pixel)
		{
			tag_init << endl << "\tfinalizeBitmaps();";
		}

		context.tag_main << "};" << endl
						 << endl;

		// Generate frame label data (FrameLabelEntry typedef is in tag.h)
		context.tag_main << "// Frame labels (label -> frame number)" << endl;

		if (frame_labels.empty())
		{
			// No frame labels - create empty array
			context.tag_main << "FrameLabelEntry frame_label_data[] = { { NULL, 0 } };" << endl
							 << "size_t frame_label_count = 0;" << endl
							 << endl;
		}
		else
		{
			context.tag_main << "FrameLabelEntry frame_label_data[] =" << endl
							 << "{" << endl;

			for (const auto& pair : frame_labels)
			{
				context.tag_main << "\t{ \"" << pair.first << "\", " << to_string(pair.second) << " }," << endl;
			}

			context.tag_main << "\t{ NULL, 0 }" << endl  // Sentinel
							 << "};" << endl
							 << endl
							 << "size_t frame_label_count = " << to_string(frame_labels.size()) << ";" << endl
							 << endl;
		}

		// Phase A of GOTO_FIFO_UNIFICATION incremental plan: emit the
		// (sprite_char_id, frame_idx) → script_func* side table. Dead
		// until later phases consume it via actionGetSpriteFrameScript().
		// Sentinel-terminated; the count is also stored explicitly so the
		// runtime accessor can iterate without scanning for the sentinel.
		if (sprite_frame_scripts_count > 0)
		{
			context.tag_main << "SpriteFrameScriptEntry sprite_frame_scripts_data[] =" << endl
							 << "{" << endl
							 << sprite_frame_scripts_table.str()
							 << "\t{ 0, 0, NULL }" << endl
							 << "};" << endl
							 << "size_t sprite_frame_scripts_data_count = "
							 << to_string(sprite_frame_scripts_count) << ";" << endl
							 << endl;
		}
		else
		{
			context.tag_main << "SpriteFrameScriptEntry sprite_frame_scripts_data[] = { { 0, 0, NULL } };" << endl
							 << "size_t sprite_frame_scripts_data_count = 0;" << endl
							 << endl;
		}

		context.tag_main << "void tagInit(SWFAppContext* app_context)" << endl
						 << "{";
		// Phase A of GOTO_FIFO_UNIFICATION incremental plan: register the
		// side table with the runtime so actionGetSpriteFrameScript() can
		// look up scripts. Done first so any later tagInit-time code can
		// rely on the accessor.
		context.tag_main << endl << "\ttagInitSpriteFrameScripts(sprite_frame_scripts_data, sprite_frame_scripts_data_count);";
		// Emit tag definitions (sprites, exports, bitmaps, etc.)
		context.tag_main << tag_init.str();
		// Initialize variable array.
		// Top-level DoInitAction / ImportAssets are now emitted into the
		// per-frame init prologue (frame_N body), not tagInit, so
		// tag_init_scripts is unused for those. The buffer remains in the
		// SWF class as a no-op slot; if a future caller routes script
		// calls through it, they'll still land here.
		if (action.next_str_i > 0)
		{
			context.tag_main << endl << "\tinitVarArray(MAX_STRING_ID);";
		}
		context.tag_main << tag_init_scripts.str() << endl
						 << "}";
		
		context.out_draws << endl << endl;
		
		// Build text_data from deferred glyph entries
		// text_data stores global glyph indices (into glyph_data), NOT character codes.
		// The renderer does: glyph_data[2 * text_data[j]] to get shape offset/size.
		// text_char_codes stores the Unicode code point for each glyph (for TextSnapshot).
		for (auto& entry : text_glyph_entries) {
			u16 fid = entry.first;
			u32 glyph_index = entry.second;
			// Convert per-font glyph index to global glyph index
			auto base_it = font_glyph_bases.find(fid);
			u32 global_index = glyph_index;
			if (base_it != font_glyph_bases.end()) {
				global_index = (u32)base_it->second + glyph_index;
			}
			text_data << "\t" << to_string(global_index) << "," << endl;
			// Look up Unicode code point from font's code table
			u16 char_code = 0;
			auto ct_it = font_code_tables.find(fid);
			if (ct_it != font_code_tables.end() && glyph_index < ct_it->second.size()) {
				char_code = ct_it->second[glyph_index];
			}
			text_char_codes << "\t" << to_string(char_code) << "," << endl;
		}

		context.out_draws << "u32 shape_data[" << to_string(current_tri ? 3*current_tri : 1) << "][4] =" << endl
						  << "{" << endl
						  << (current_tri ? shape_data.str() : "\t0\n")
						  << "};" << endl
						  << endl
						  << "float transform_data[" << to_string(current_transform ? current_transform : 1) << "][16] =" << endl
						  << "{" << endl
						  << (current_transform ? transform_data.str() : "\t0\n")
						  << "};" << endl
						  << endl
						  << "float color_data[" << to_string(current_color ? current_color : 1) << "][4] =" << endl
						  << "{" << endl
						  << (current_color ? color_data.str() : "\t0\n")
						  << "};" << endl
						  << endl
						  << "float uninv_mat_data[" << to_string(current_uninv ? 16*current_uninv : 1) << "] =" << endl
						  << "{" << endl
						  << (current_uninv ? uninv_mat_data.str() : "\t0\n")
						  << "};" << endl
						  << endl
						  << "u8 gradient_data[" << to_string(current_gradient ? 256*current_gradient : 1) << "][4] =" << endl
						  << "{" << endl
						  << (current_gradient ? gradient_data.str() : "\t0\n")
						  << "};" << endl
						  << endl
						  << "u8 bitmap_data[" << to_string(current_bitmap_pixel ? 4*current_bitmap_pixel : 1) << "] =" << endl
						  << "{" << endl
						  << (current_bitmap_pixel ? bitmap_data.str() : "\t0\n")
						  << "};" << endl
						  << endl
						  << "u32 glyph_data[" << to_string(current_glyph ? 4*current_glyph : 1) << "][1] =" << endl
						  << "{" << endl
						  << (current_glyph ? glyph_data.str() : "\t0\n")
						  << "};" << endl
						  << endl
						  << "u32 text_data[" << to_string(current_text ? current_text : 1) << "] =" << endl
						  << "{" << endl
						  << (current_text ? text_data.str() : "\t0\n")
						  << "};" << endl
						  << endl
						  << "u16 text_char_codes[" << to_string(current_text ? current_text : 1) << "] =" << endl
						  << "{" << endl
						  << (current_text ? text_char_codes.str() : "\t0\n")
						  << "};" << endl
						  << endl
						  << "float cxform_data[" << to_string(current_cxform ? 20*current_cxform : 1) << "] =" << endl
						  << "{" << endl
						  << (current_cxform ? cxform_data.str() : "\t0\n")
						  << "};" << endl
						  << endl
						  << "float morph_end_shape_data[" << to_string(current_morph_end_vertex ? current_morph_end_vertex : 1) << "][2] =" << endl
						  << "{" << endl
						  << (current_morph_end_vertex ? morph_end_shape_data.str() : "\t0\n")
						  << "};" << endl
						  << endl
						  << "float morph_end_color_data[" << to_string(current_morph_end_color ? current_morph_end_color : 1) << "][4] =" << endl
						  << "{" << endl
						  << (current_morph_end_color ? morph_end_color_data.str() : "\t0\n")
						  << "};" << endl
						  << endl
						  << "u8 sound_data[" << to_string(current_sound_byte ? current_sound_byte : 1) << "] =" << endl
						  << "{" << endl
						  << (current_sound_byte ? sound_data.str() : "\t0\n")
						  << "};" << endl
						  << endl
						  << "u8 video_data[" << to_string(current_video_byte ? current_video_byte : 1) << "] =" << endl
						  << "{" << endl
						  << (current_video_byte ? video_data.str() : "\t0\n")
						  << "};" << endl
						  << endl
						  << "float path_data[" << to_string(current_path_entry ? current_path_entry : 1) << "][3] =" << endl
						  << "{" << endl
						  << (current_path_entry ? path_data.str() : "\t{0}\n")
						  << "};" << endl;

		context.out_draws_header << endl
								 << "extern u32 shape_data[" << to_string(current_tri ? 3*current_tri : 1) << "][4];" << endl
								 << "extern float transform_data[" << to_string(current_transform ? current_transform : 1) << "][16];" << endl
								 << "extern float color_data[" << to_string(current_color ? current_color : 1) << "][4];" << endl
								 << "extern float uninv_mat_data[" << to_string(current_uninv ? 16*current_uninv : 1) << "];" << endl
								 << "extern u8 gradient_data[" << to_string(current_gradient ? 256*current_gradient : 1) << "][4];" << endl
								 << "extern u8 bitmap_data[" << to_string(current_bitmap_pixel ? 4*current_bitmap_pixel : 1) << "];" << endl
								 << "extern u32 glyph_data[" << to_string(current_glyph ? 4*current_glyph : 1) << "][1];" << endl
								 << "extern u32 text_data[" << to_string(current_text ? current_text : 1) << "];" << endl
								 << "extern u16 text_char_codes[" << to_string(current_text ? current_text : 1) << "];" << endl
								 << "extern float cxform_data[" << to_string(current_cxform ? 20*current_cxform : 1) << "];" << endl
								 << "extern float morph_end_shape_data[" << to_string(current_morph_end_vertex ? current_morph_end_vertex : 1) << "][2];" << endl
								 << "extern float morph_end_color_data[" << to_string(current_morph_end_color ? current_morph_end_color : 1) << "][4];" << endl
								 << "extern u8 sound_data[" << to_string(current_sound_byte ? current_sound_byte : 1) << "];" << endl
								 << "extern u8 video_data[" << to_string(current_video_byte ? current_video_byte : 1) << "];" << endl
								 << "extern float path_data[" << to_string(current_path_entry ? current_path_entry : 1) << "][3];" << endl;

		// Emit sprite forward declarations (frame_func arrays)
		if (!sprite_forward_decls.str().empty())
		{
			context.out_draws_header << endl << "// Sprite frame function forward declarations" << endl
									 << sprite_forward_decls.str();
		}
		
		size_t highest_w = 0;
		size_t highest_h = 0;
		
		for (const Vertex& v : bitmap_sizes)
		{
			if (v.x > highest_w)
			{
				highest_w = v.x;
			}
			
			if (v.y > highest_h)
			{
				highest_h = v.y;
			}
		}
		
		context.constants_header << endl << endl
								 << "#define BITMAP_COUNT " << to_string(current_bitmap) << endl
								 << "#define BITMAP_HIGHEST_W " << to_string(highest_w) << endl
								 << "#define BITMAP_HIGHEST_H " << to_string(highest_h) << endl
								 << "#define SWF_USE_NETWORK " << (use_network ? "1" : "0");

		// Add FRAME_COUNT to out.h for ActionCall opcode
		context.out_script_header << endl << endl
								  << "#define FRAME_COUNT " << to_string(next_frame_i);

		// Add FRAME_RATE to out.h for runtime frame timing
		context.out_script_header << endl << endl
								  << "#define FRAME_RATE " << to_string(header.framerate >> 8);

		context.out_script_header.close();
		context.out_script_defs.close();
		context.out_script_decls.close();
	}
	
	void SWF::interpretTag(Context& context, SWFTag& tag)
	{
		if (another_frame && tag.code != SWF_TAG_END_TAG)
		{
			// Replace the previous frame's prologue placeholder with its
			// accumulated DoInitAction / ImportAssets calls before
			// closing the frame, then drop a fresh placeholder for the
			// new frame.
			flushFrameInitPrologue(context);
			context.tag_main << "}" << endl << endl
							 << "void frame_" << to_string(next_frame_i) << "(SWFAppContext* app_context)" << endl
							 << "{" << endl;
			writeFrameInitMarker(context);
			next_frame_i += 1;

			another_frame = false;
		}

		switch (tag.code)
		{
			case SWF_TAG_END_TAG:
			{
				// Flush the per-frame init prologue placeholder before any
				// of the END_TAG epilogue body emissions so the
				// DoInitActions land at the top of the final frame.
				flushFrameInitPrologue(context);
				// Flush pending ENTER_FRAME dispatch (after RemoveObject, before DoAction)
				context.tag_main << "\t" << "tagFlushPendingEnterFrame(app_context);" << endl;
				// Phase 6: drain queued root DoAction scripts before the frame
				// footer (quit_swf / next_frame scheduling). Kind-filtered so
				// Phase 4/5 entries remain owned by their own drain sites.
				// Drain DoAction scripts AND queued unload handlers together in
			// FIFO order. The interleaved order matches Flash's ActionQueue
			// model: a tag-stream-order RemoveObject2 followed by DoAction
			// fires unload first; a DoAction followed by RemoveObject2 fires
			// the script first. (See DEFERRED_CLIP_UNLOAD_PLAN.)
			context.tag_main << "\t" << "if (!catch_up_mode || g_tag_skip_mode) actionDrainAllInPriorityOrder(app_context);" << endl;
				last_queued_script = next_script_i;

				// `another_frame == false` at END_TAG means the SWF has trailing
				// tags after the last ShowFrame: the recompiler opened frame_N to
				// hold them but no ShowFrame ever closed it. Treat this dangling
				// frame as one-shot — run it once and stop, so the trailing tags
				// don't re-execute on each loop back. Mirrors Flash/Ruffle, which
				// run trailing tags only on initial play.
				if (next_frame_i == 1 || !another_frame)
				{
					context.tag_main << "\t" << "quit_swf = 1;" << endl;
				}

				else
				{
					context.tag_main << "\t" << "if (!manual_next_frame && is_playing && !g_tag_skip_mode)" << endl
									 << "\t" << "{" << endl
									 << "\t\t" << "next_frame = 0;" << endl
									 << "\t\t" << "manual_next_frame = 1;" << endl
									 << "\t" << "}" << endl;
				}

				context.tag_main << "}";

				break;
			}

			case SWF_TAG_FRAME_LABEL:
			{
				// Parse null-terminated label string
				const char* label_str = cur_pos;
				std::string label(label_str);
				// next_frame_i has already been incremented when the frame function was opened,
				// so the current frame being built is next_frame_i - 1
				// Use insert to keep first occurrence (Flash uses first label for navigation)
				frame_labels.insert({label, next_frame_i - 1});
				cur_pos += tag.length;

				break;
			}

			case SWF_TAG_SHOW_FRAME:
			{
				// Flush any buffered RemoveObject2 calls that weren't consumed
				// by a subsequent PlaceObject2 at the same depth.
				for (u16 rd : buffered_removes)
				{
					context.tag_main << "\t" << "tagRemoveObject2(app_context, " << to_string(rd) << ");" << endl;
					depth_clip_actions.erase(rd);
				}
				buffered_removes.clear();

				// Flush pending ENTER_FRAME dispatch (after RemoveObject, before DoAction)
				context.tag_main << "\t" << "tagFlushPendingEnterFrame(app_context);" << endl;
				// Phase 6: drain queued root DoAction scripts at the ShowFrame
				// boundary. Kind-filtered (AQ_KIND_SCRIPT only) so Phase 4/5
				// CLIP_INIT / CONSTRUCT / REGISTER_CTOR entries continue to
				// drain at the outermost tagPlaceObject2 / tagShowFrame safety
				// drain — preserving the Phase 5 ordering contract.
				// Drain DoAction scripts AND queued unload handlers together in
			// FIFO order. The interleaved order matches Flash's ActionQueue
			// model: a tag-stream-order RemoveObject2 followed by DoAction
			// fires unload first; a DoAction followed by RemoveObject2 fires
			// the script first. (See DEFERRED_CLIP_UNLOAD_PLAN.)
			context.tag_main << "\t" << "if (!catch_up_mode || g_tag_skip_mode) actionDrainAllInPriorityOrder(app_context);" << endl;
				last_queued_script = next_script_i;

				context.tag_main << "\t" << "tagShowFrame(app_context);" << endl;

				another_frame = true;

				break;
			}
			
			case SWF_TAG_DEFINE_BITS:
			{
				if (jpeg_tables == nullptr)
				{
					EXC("JPEG bitmap tag encountered before JPEGTables!\n");
				}
				
				size_t new_length = tag.length;
				
				tag.clearFields();
				tag.setFieldCount(1);
				
				tag.configureNextField(SWF_FIELD_UI16);
				
				tag.parseFields(cur_pos);
				
				u16 char_id = (u16) tag.fields[0].value;
				new_length -= 2;

				// Register bitmap char_id for place-before-define tracking.
				defined_chars.insert(char_id);

				// stupid swf edge cases are stupid
				if ((u8) cur_pos[0] == 0xFF &&
					(u8) cur_pos[1] == 0xD9 &&
					(u8) cur_pos[2] == 0xFF &&
					(u8) cur_pos[3] == 0xD8)
				{
					cur_pos += 4;
					new_length -= 4;
				}
				
				else if ((u8) cur_pos[0] == 0xFF &&
						 (u8) cur_pos[1] == 0xD8)
				{
					cur_pos += 2;
					new_length -= 2;
				}
				
				size_t jpeg_data_size = new_length + jpeg_tables_size;
				u8* jpeg_data = new u8[jpeg_data_size];
				
				for (size_t i = 0; i < jpeg_tables_size; ++i)
				{
					jpeg_data[i] = jpeg_tables[i];
				}
				
				for (size_t i = jpeg_tables_size; i < jpeg_data_size; ++i)
				{
					jpeg_data[i] = cur_pos[i - jpeg_tables_size];
				}
				
				int w;
				int h;
				int comp;
				u8* decompressed = stbi_load_from_memory(jpeg_data, (int) jpeg_data_size, &w, &h, &comp, 3);
				
				if (decompressed == nullptr)
				{
					EXC("JPEG data returned NULL.\n");
				}
				
				Vertex v;
				v.x = w;
				v.y = h;
				
				bitmap_sizes.push_back(v);
				
				size_t bitmap_start = current_bitmap_pixel;
				
				for (size_t i = 0; i < 3*w*h; i += 3)
				{
					bitmap_data << std::hex << std::uppercase << std::setw(2)
								<< "\t0x" << (u32) decompressed[i] << "," << endl
								<< "\t0x" << (u32) decompressed[i + 1] << "," << endl
								<< "\t0x" << (u32) decompressed[i + 2] << "," << endl
								<< "\t0xFF," << endl;
					
					current_bitmap_pixel += 1;
				}
				
				char_id_to_bitmap_id[char_id] = current_bitmap;
				
				tag_init << endl
						 << "\tdefineBitmap("
						 << to_string(4*bitmap_start) << ", "
						 << to_string(4*(current_bitmap_pixel - bitmap_start)) << ", "
						 << to_string(w) << ", "
						 << to_string(h) << ", "
						 << to_string(char_id)
						 << ");";
				
				current_bitmap += 1;
				
				cur_pos += new_length;
				
				break;
			}
			
			case SWF_TAG_DEFINE_BITS_JPEG2:
			{
				size_t new_length = tag.length;

				tag.clearFields();
				tag.setFieldCount(1);

				tag.configureNextField(SWF_FIELD_UI16);

				tag.parseFields(cur_pos);

				u16 char_id = (u16) tag.fields[0].value;
				new_length -= 2;

				// Register bitmap char_id for place-before-define tracking.
				defined_chars.insert(char_id);

				// Strip erroneous EOI+SOI marker (FF D9 FF D8) if present
				// Tag 21 is self-contained, so a leading FF D8 alone is the valid SOI
				if ((u8) cur_pos[0] == 0xFF &&
					(u8) cur_pos[1] == 0xD9 &&
					(u8) cur_pos[2] == 0xFF &&
					(u8) cur_pos[3] == 0xD8)
				{
					cur_pos += 4;
					new_length -= 4;
				}

				int w;
				int h;
				int comp;
				u8* decompressed = stbi_load_from_memory((u8*) cur_pos, (int) new_length, &w, &h, &comp, 3);

				if (decompressed == nullptr)
				{
					EXC("JPEG2 data returned NULL.\n");
				}

				Vertex v;
				v.x = w;
				v.y = h;

				bitmap_sizes.push_back(v);

				size_t bitmap_start = current_bitmap_pixel;

				for (size_t i = 0; i < 3*w*h; i += 3)
				{
					bitmap_data << std::hex << std::uppercase << std::setw(2)
								<< "\t0x" << (u32) decompressed[i] << "," << endl
								<< "\t0x" << (u32) decompressed[i + 1] << "," << endl
								<< "\t0x" << (u32) decompressed[i + 2] << "," << endl
								<< "\t0xFF," << endl;

					current_bitmap_pixel += 1;
				}

				char_id_to_bitmap_id[char_id] = current_bitmap;

				tag_init << endl
						 << "\tdefineBitmap("
						 << to_string(4*bitmap_start) << ", "
						 << to_string(4*(current_bitmap_pixel - bitmap_start)) << ", "
						 << to_string(w) << ", "
						 << to_string(h) << ", "
						 << to_string(char_id)
						 << ");";

				current_bitmap += 1;

				stbi_image_free(decompressed);

				cur_pos += new_length;

				break;
			}

			case SWF_TAG_DEFINE_BITS_JPEG3:
			case SWF_TAG_DEFINE_BITS_JPEG4:
			{
				bool is_jpeg4 = (tag.code == SWF_TAG_DEFINE_BITS_JPEG4);
				size_t new_length = tag.length;

				tag.clearFields();
				tag.setFieldCount(1);

				tag.configureNextField(SWF_FIELD_UI16);

				tag.parseFields(cur_pos);

				u16 char_id = (u16) tag.fields[0].value;
				new_length -= 2;

				// Register bitmap char_id for place-before-define tracking.
				defined_chars.insert(char_id);

				tag.clearFields();
				tag.setFieldCount(1);

				tag.configureNextField(SWF_FIELD_UI32);

				tag.parseFields(cur_pos);

				u32 alpha_data_offset = (u32) tag.fields[0].value;
				new_length -= 4;

				// JPEG4 has an extra UI16 deblocking filter parameter (ignored)
				if (is_jpeg4)
				{
					tag.clearFields();
					tag.setFieldCount(1);
					tag.configureNextField(SWF_FIELD_UI16);
					tag.parseFields(cur_pos);
					// deblockParam (FIXED8) - parsed and discarded
					new_length -= 2;
				}

				// JPEG data is alpha_data_offset bytes, alpha data follows
				char* jpeg_start = cur_pos;
				size_t jpeg_len = alpha_data_offset;

				// Strip erroneous EOI+SOI marker (FF D9 FF D8) if present
				if (jpeg_len >= 4 &&
					(u8) jpeg_start[0] == 0xFF &&
					(u8) jpeg_start[1] == 0xD9 &&
					(u8) jpeg_start[2] == 0xFF &&
					(u8) jpeg_start[3] == 0xD8)
				{
					jpeg_start += 4;
					jpeg_len -= 4;
				}

				int w;
				int h;
				int comp;
				u8* decompressed = stbi_load_from_memory((u8*) jpeg_start, (int) jpeg_len, &w, &h, &comp, 3);

				if (decompressed == nullptr)
				{
					EXC("JPEG3 data returned NULL.\n");
				}

				// Decompress zlib alpha data
				char* alpha_compressed = cur_pos + alpha_data_offset;
				size_t alpha_compressed_len = new_length - alpha_data_offset;

				uLongf alpha_size = (uLongf)(w * h);
				u8* alpha_data = new u8[alpha_size];

				int zresult = uncompress(alpha_data, &alpha_size,
				                         (const Bytef*) alpha_compressed, (uLong) alpha_compressed_len);

				if (zresult != Z_OK)
				{
					stbi_image_free(decompressed);
					delete[] alpha_data;
					EXC_ARG("JPEG3: ZLIB alpha decompression failed (code %d).\n", zresult);
				}

				Vertex v;
				v.x = w;
				v.y = h;

				bitmap_sizes.push_back(v);

				size_t bitmap_start = current_bitmap_pixel;

				for (size_t i = 0; i < (size_t)(w * h); i++)
				{
					bitmap_data << std::hex << std::uppercase << std::setw(2)
								<< "\t0x" << (u32) decompressed[3*i] << "," << endl
								<< "\t0x" << (u32) decompressed[3*i + 1] << "," << endl
								<< "\t0x" << (u32) decompressed[3*i + 2] << "," << endl
								<< "\t0x" << (u32) alpha_data[i] << "," << endl;

					current_bitmap_pixel += 1;
				}

				char_id_to_bitmap_id[char_id] = current_bitmap;

				tag_init << endl
						 << "\tdefineBitmap("
						 << to_string(4*bitmap_start) << ", "
						 << to_string(4*(current_bitmap_pixel - bitmap_start)) << ", "
						 << to_string(w) << ", "
						 << to_string(h) << ", "
						 << to_string(char_id)
						 << ");";

				current_bitmap += 1;

				stbi_image_free(decompressed);
				delete[] alpha_data;

				cur_pos += new_length;

				break;
			}

			case SWF_TAG_JPEG_TABLES:
			{
				if (jpeg_tables != nullptr)
				{
					EXC("More than one JPEGTables tag detected.\n");
				}
				
				size_t new_length = tag.length;
				
				if ((u8) cur_pos[0] == 0xFF &&
					(u8) cur_pos[1] == 0xD9 &&
					(u8) cur_pos[2] == 0xFF &&
					(u8) cur_pos[3] == 0xD8)
				{
					cur_pos += 2;
					new_length -= 2;
				}
				
				jpeg_tables = new u8[new_length - 2];
				jpeg_tables_size = new_length - 2;
				
				for (size_t i = 0; i < new_length - 2; ++i)
				{
					jpeg_tables[i] = cur_pos[i];
				}
				
				cur_pos += new_length;
				
				break;
			}
			
			case SWF_TAG_DEFINE_BITS_LOSSLESS:
			{
				size_t tag_start_remaining = tag.length;

				tag.clearFields();
				tag.setFieldCount(1);

				tag.configureNextField(SWF_FIELD_UI16);

				tag.parseFields(cur_pos);

				u16 char_id = (u16) tag.fields[0].value;
				tag_start_remaining -= 2;

				// Register lossless bitmap char_id for place-before-define tracking.
				defined_chars.insert(char_id);

				tag.clearFields();
				tag.setFieldCount(3);

				tag.configureNextField(SWF_FIELD_UI8);
				tag.configureNextField(SWF_FIELD_UI16);
				tag.configureNextField(SWF_FIELD_UI16);

				tag.parseFields(cur_pos);

				u8 bitmap_format = (u8) tag.fields[0].value;
				u16 w = (u16) tag.fields[1].value;
				u16 h = (u16) tag.fields[2].value;
				tag_start_remaining -= 5;

				if (w > 8192 || h > 8192)
				{
					fprintf(stderr, "DefineBitsLossless dimensions too large (%dx%d, max 8192x8192).\n", w, h);
					throw std::exception();
				}

				if (bitmap_format != 5)
				{
					EXC_ARG("DefineBitsLossless format %d not yet supported (only format 5).\n", bitmap_format);
				}

				// Remaining data is ZLIB-compressed pixel data
				uLongf uncompressed_size = (uLongf)(w * h * 4);
				u8* uncompressed = new u8[uncompressed_size];

				int zresult = uncompress(uncompressed, &uncompressed_size,
				                         (const Bytef*) cur_pos, (uLong) tag_start_remaining);

				if (zresult != Z_OK)
				{
					delete[] uncompressed;
					EXC_ARG("DefineBitsLossless: ZLIB decompression failed (code %d).\n", zresult);
				}

				Vertex v;
				v.x = w;
				v.y = h;

				bitmap_sizes.push_back(v);

				size_t bitmap_start = current_bitmap_pixel;

				// Format 5: PIX24 = [0x00_padding, R, G, B] per pixel
				for (size_t i = 0; i < (size_t)(w * h * 4); i += 4)
				{
					bitmap_data << std::hex << std::uppercase << std::setw(2)
								<< "\t0x" << (u32) uncompressed[i + 1] << "," << endl
								<< "\t0x" << (u32) uncompressed[i + 2] << "," << endl
								<< "\t0x" << (u32) uncompressed[i + 3] << "," << endl
								<< "\t0xFF," << endl;

					current_bitmap_pixel += 1;
				}

				delete[] uncompressed;

				char_id_to_bitmap_id[char_id] = current_bitmap;

				tag_init << endl
						 << "\tdefineBitmap("
						 << to_string(4*bitmap_start) << ", "
						 << to_string(4*(current_bitmap_pixel - bitmap_start)) << ", "
						 << to_string(w) << ", "
						 << to_string(h) << ", "
						 << to_string(char_id)
						 << ");";

				current_bitmap += 1;

				cur_pos += tag_start_remaining;

				break;
			}

			case SWF_TAG_DEFINE_BITS_LOSSLESS2:
			{
				size_t tag_start_remaining = tag.length;

				tag.clearFields();
				tag.setFieldCount(1);

				tag.configureNextField(SWF_FIELD_UI16);

				tag.parseFields(cur_pos);

				u16 char_id = (u16) tag.fields[0].value;
				tag_start_remaining -= 2;

				// Register lossless bitmap char_id for place-before-define tracking.
				defined_chars.insert(char_id);

				tag.clearFields();
				tag.setFieldCount(3);

				tag.configureNextField(SWF_FIELD_UI8);
				tag.configureNextField(SWF_FIELD_UI16);
				tag.configureNextField(SWF_FIELD_UI16);

				tag.parseFields(cur_pos);

				u8 bitmap_format = (u8) tag.fields[0].value;
				u16 w = (u16) tag.fields[1].value;
				u16 h = (u16) tag.fields[2].value;
				tag_start_remaining -= 5;

				if (w > 8192 || h > 8192)
				{
					fprintf(stderr, "DefineBitsLossless2 dimensions too large (%dx%d, max 8192x8192).\n", w, h);
					throw std::exception();
				}

				if (bitmap_format != 5)
				{
					EXC_ARG("DefineBitsLossless2 format %d not yet supported (only format 5).\n", bitmap_format);
				}

				// Remaining data is ZLIB-compressed pixel data
				uLongf uncompressed_size = (uLongf)(w * h * 4);
				u8* uncompressed = new u8[uncompressed_size];

				int zresult = uncompress(uncompressed, &uncompressed_size,
				                         (const Bytef*) cur_pos, (uLong) tag_start_remaining);

				if (zresult != Z_OK)
				{
					delete[] uncompressed;
					EXC_ARG("DefineBitsLossless2: ZLIB decompression failed (code %d).\n", zresult);
				}

				Vertex v;
				v.x = w;
				v.y = h;

				bitmap_sizes.push_back(v);

				size_t bitmap_start = current_bitmap_pixel;

				// Format 5: ALPHACOLORMAPDATA/ALPHARGB = [A, R, G, B] per pixel
				for (size_t i = 0; i < (size_t)(w * h * 4); i += 4)
				{
					bitmap_data << std::hex << std::uppercase << std::setw(2)
								<< "\t0x" << (u32) uncompressed[i + 1] << "," << endl
								<< "\t0x" << (u32) uncompressed[i + 2] << "," << endl
								<< "\t0x" << (u32) uncompressed[i + 3] << "," << endl
								<< "\t0x" << (u32) uncompressed[i + 0] << "," << endl;

					current_bitmap_pixel += 1;
				}

				delete[] uncompressed;

				char_id_to_bitmap_id[char_id] = current_bitmap;

				tag_init << endl
						 << "\tdefineBitmap("
						 << to_string(4*bitmap_start) << ", "
						 << to_string(4*(current_bitmap_pixel - bitmap_start)) << ", "
						 << to_string(w) << ", "
						 << to_string(h) << ", "
						 << to_string(char_id)
						 << ");";

				current_bitmap += 1;

				cur_pos += tag_start_remaining;

				break;
			}

			case SWF_TAG_DEFINE_SOUND:
			{
				// DefineSound: SoundId(UI16), Flags(UI8), SampleCount(UI32), SoundData(bytes)
				tag.setFieldCount(3);
				tag.configureNextField(SWF_FIELD_UI16);
				tag.configureNextField(SWF_FIELD_UI8);
				tag.configureNextField(SWF_FIELD_UI32, 32);
				tag.parseFields(cur_pos);

				u16 sound_id = (u16) tag.fields[0].value;
				u8 flags = (u8) tag.fields[1].value;
				u32 sample_count = (u32) tag.fields[2].value;

				// Register sound char_id for place-before-define tracking.
				defined_chars.insert(sound_id);

				u8 format = (flags >> 4) & 0x0F;
				u8 rate = (flags >> 2) & 0x03;
				u8 sample_size = (flags >> 1) & 0x01;
				u8 stereo = flags & 0x01;

				size_t sound_header_size = 2 + 1 + 4;
				size_t data_size = tag.length - sound_header_size;
				size_t data_offset = current_sound_byte;

				for (size_t i = 0; i < data_size; ++i)
				{
					sound_data << "\t0x" << std::hex << std::uppercase << std::setw(2) << std::setfill('0')
							   << (u32)(u8)cur_pos[i] << "," << std::dec << endl;
				}
				current_sound_byte += data_size;
				cur_pos += data_size;

				tag_init << endl << "\ttagDefineSound(app_context, "
						 << to_string(sound_id) << ", "
						 << to_string(format) << ", "
						 << to_string(rate) << ", "
						 << to_string(sample_size) << ", "
						 << to_string(stereo) << ", "
						 << to_string(sample_count) << ", "
						 << "sound_data + " << to_string(data_offset) << ", "
						 << to_string(data_size) << ");";

				break;
			}

			case SWF_TAG_START_SOUND:
			{
				tag.setFieldCount(1);
				tag.configureNextField(SWF_FIELD_UI16);
				tag.parseFields(cur_pos);

				u16 sound_id = (u16) tag.fields[0].value;

				tag.clearFields();
				tag.setFieldCount(1);
				tag.configureNextField(SWF_FIELD_UI8);
				tag.parseFields(cur_pos);

				u8 si_flags = (u8) tag.fields[0].value;
				bool sync_stop = (si_flags & 0x20) != 0;
				bool has_envelope = (si_flags & 0x08) != 0;
				bool has_loops = (si_flags & 0x04) != 0;
				bool has_out_point = (si_flags & 0x02) != 0;
				bool has_in_point = (si_flags & 0x01) != 0;

				u32 in_point = 0, out_point = 0, loop_count = 0;

				if (has_in_point)
				{
					tag.clearFields();
					tag.setFieldCount(1);
					tag.configureNextField(SWF_FIELD_UI32, 32);
					tag.parseFields(cur_pos);
					in_point = (u32) tag.fields[0].value;
				}
				if (has_out_point)
				{
					tag.clearFields();
					tag.setFieldCount(1);
					tag.configureNextField(SWF_FIELD_UI32, 32);
					tag.parseFields(cur_pos);
					out_point = (u32) tag.fields[0].value;
				}
				if (has_loops)
				{
					tag.clearFields();
					tag.setFieldCount(1);
					tag.configureNextField(SWF_FIELD_UI16);
					tag.parseFields(cur_pos);
					loop_count = (u32)(u16) tag.fields[0].value;
				}
				if (has_envelope)
				{
					tag.clearFields();
					tag.setFieldCount(1);
					tag.configureNextField(SWF_FIELD_UI8);
					tag.parseFields(cur_pos);
					u8 env_count = (u8) tag.fields[0].value;
					cur_pos += env_count * 8;
				}

				context.tag_main << "\t" << "tagStartSound(app_context, "
								 << to_string(sound_id) << ", "
								 << (sync_stop ? "1" : "0") << ", "
								 << to_string(loop_count) << ", "
								 << to_string(in_point) << ", "
								 << to_string(out_point) << ");" << endl;

				break;
			}

			case SWF_TAG_SOUND_STREAM_HEAD:
			case SWF_TAG_SOUND_STREAM_HEAD_2:
			{
				tag.setFieldCount(3);
				tag.configureNextField(SWF_FIELD_UI8);
				tag.configureNextField(SWF_FIELD_UI8);
				tag.configureNextField(SWF_FIELD_UI16);
				tag.parseFields(cur_pos);

				u8 stream_flags = (u8) tag.fields[1].value;
				u16 avg_sample_count = (u16) tag.fields[2].value;

				u8 format = (stream_flags >> 4) & 0x0F;
				u8 rate = (stream_flags >> 2) & 0x03;
				u8 sample_size = (stream_flags >> 1) & 0x01;
				u8 stereo_flag = stream_flags & 0x01;

				if (format == 2 && tag.length > 4)
					cur_pos += 2;

				has_streaming_sound = true;

				tag_init << endl << "\ttagSoundStreamHead(app_context, "
						 << to_string(format) << ", "
						 << to_string(rate) << ", "
						 << to_string(sample_size) << ", "
						 << to_string(stereo_flag) << ", "
						 << to_string(avg_sample_count) << ");";

				break;
			}

			case SWF_TAG_SOUND_STREAM_BLOCK:
			{
				size_t data_size = tag.length;
				size_t data_offset = current_sound_byte;

				for (size_t i = 0; i < data_size; ++i)
				{
					sound_data << "\t0x" << std::hex << std::uppercase << std::setw(2) << std::setfill('0')
							   << (u32)(u8)cur_pos[i] << "," << std::dec << endl;
				}
				current_sound_byte += data_size;
				cur_pos += data_size;

				context.tag_main << "\t" << "tagSoundStreamBlock(app_context, "
								 << "sound_data + " << to_string(data_offset) << ", "
								 << to_string(data_size) << ");" << endl;

				break;
			}

			case SWF_TAG_DEFINE_SHAPE:
			case SWF_TAG_DEFINE_SHAPE_2:
			case SWF_TAG_DEFINE_SHAPE_3:
			case SWF_TAG_DEFINE_SHAPE_4:
			case SWF_TAG_DEFINE_MORPH_SHAPE:
			case SWF_TAG_DEFINE_MORPH_SHAPE_2:
			{
				interpretShape(context, tag);

				break;
			}

			case SWF_TAG_SET_BACKGROUND_COLOR:
			{
				RGB.parseFields(cur_pos);
				
				context.tag_main << "\t" << "tagSetBackgroundColor("
								 << to_string((u8) RGB.fields[0].value) << ", "
								 << to_string((u8) RGB.fields[1].value) << ", "
								 << to_string((u8) RGB.fields[2].value) << ");" << endl;
				
				break;
			}
			
			case SWF_TAG_DEFINE_FONT:
			case SWF_TAG_DEFINE_FONT_2:
			case SWF_TAG_DEFINE_FONT_3:
			{
				char* font_tag_start = cur_pos;
				size_t font_tag_length = tag.length;

				tag.clearFields();
				tag.setFieldCount(1);

				tag.configureNextField(SWF_FIELD_UI16);

				tag.parseFields(cur_pos);

				u16 font_id = (u16) tag.fields[0].value;

				// Register font char_id for place-before-define tracking.
				defined_chars.insert(font_id);

				font_em_square[font_id] = (tag.code == SWF_TAG_DEFINE_FONT_3) ? 20480.0f : 1024.0f;

				u16 num_entries;
				char* offset_table;
				std::vector<u16> entry_offsets;
				bool wide_codes = false;
				bool has_layout = false;

				if (tag.code == SWF_TAG_DEFINE_FONT_2 || tag.code == SWF_TAG_DEFINE_FONT_3)
				{
					// DefineFont2 header: Flags(UI8), LanguageCode(UI8), FontNameLen(UI8), FontName(bytes), NumGlyphs(UI16)
					tag.clearFields();
					tag.setFieldCount(2);
					tag.configureNextField(SWF_FIELD_UI8);  // Flags
					tag.configureNextField(SWF_FIELD_UI8);  // LanguageCode
					tag.parseFields(cur_pos);

					u8 flags = (u8) tag.fields[0].value;
					has_layout = (flags & 0x80) != 0;
					bool wide_offsets = (flags & 0x08) != 0;
					wide_codes = (flags & 0x04) != 0;

					// Store bold/italic flags
					font_bold_flags[font_id] = (flags & 0x01) != 0;
					font_italic_flags[font_id] = (flags & 0x02) != 0;

					// FontName
					tag.clearFields();
					tag.setFieldCount(1);
					tag.configureNextField(SWF_FIELD_UI8);  // FontNameLen
					tag.parseFields(cur_pos);

					u8 font_name_len = (u8) tag.fields[0].value;
					// Store font name
					font_names[font_id] = std::string(cur_pos, font_name_len);
					// Remove any trailing null bytes from the name
					while (!font_names[font_id].empty() && font_names[font_id].back() == '\0')
						font_names[font_id].pop_back();
					cur_pos += font_name_len;  // skip font name bytes

					// NumGlyphs
					tag.clearFields();
					tag.setFieldCount(1);
					tag.configureNextField(SWF_FIELD_UI16);
					tag.parseFields(cur_pos);

					num_entries = (u16) tag.fields[0].value;

					// Offset table starts here (NumGlyphs offsets + CodeTableOffset)
					offset_table = cur_pos;

					if (num_entries > 0)
					{
						u16 num_offsets = num_entries + 1;  // glyph offsets + CodeTableOffset

						if (wide_offsets)
						{
							tag.clearFields();
							tag.setFieldCount(num_offsets);
							for (u16 i = 0; i < num_offsets; ++i)
								tag.configureNextField(SWF_FIELD_UI32);
							tag.parseFields(cur_pos);

							for (u16 i = 0; i < num_offsets; ++i)
								entry_offsets.push_back((u16) tag.fields[i].value);
						}
						else
						{
							tag.clearFields();
							tag.setFieldCount(num_offsets);
							for (u16 i = 0; i < num_offsets; ++i)
								tag.configureNextField(SWF_FIELD_UI16);
							tag.parseFields(cur_pos);

							for (u16 i = 0; i < num_offsets; ++i)
								entry_offsets.push_back((u16) tag.fields[i].value);
						}
					}
				}
				else
				{
					// DefineFont: derive num_entries from first offset
					offset_table = cur_pos;

					tag.clearFields();
					tag.setFieldCount(1);
					tag.configureNextField(SWF_FIELD_UI16);
					tag.parseFields(cur_pos);

					entry_offsets.push_back((u16) tag.fields[0].value);
					num_entries = entry_offsets.back()/2;

					tag.clearFields();
					tag.setFieldCount(num_entries - 1);
					for (u16 i = 0; i < num_entries - 1; ++i)
						tag.configureNextField(SWF_FIELD_UI16);
					tag.parseFields(cur_pos);

					for (u16 i = 0; i < num_entries - 1; ++i)
						entry_offsets.push_back((u16) tag.fields[i].value);
				}

				// Record this font's base index in global glyph_data
				font_glyph_bases[font_id] = current_glyph;

				// Collect glyph entries — device font fallback may patch empty ones later
				std::vector<std::pair<size_t, size_t>> font_glyph_entries;
				std::vector<std::pair<size_t, size_t>> font_glyph_path_entries;
				for (u16 i = 0; i < num_entries; ++i)
				{
					size_t glyph_start = 3*current_tri;

					cur_pos = offset_table + entry_offsets[i];
					interpretShape(context, tag);

					size_t glyph_size = 3*current_tri - glyph_start;
					font_glyph_entries.push_back({glyph_start, glyph_size});
					font_glyph_path_entries.push_back({0, 0}); // filled by device font fallback
				}

				// Read code table for DefineFont2/3
				if ((tag.code == SWF_TAG_DEFINE_FONT_2 || tag.code == SWF_TAG_DEFINE_FONT_3) && num_entries > 0)
				{
					cur_pos = offset_table + entry_offsets[num_entries];  // jump to code table
					font_code_tables[font_id].resize(num_entries);
					for (u16 i = 0; i < num_entries; ++i)
					{
						tag.clearFields();
						tag.setFieldCount(1);
						if (wide_codes)
						{
							tag.configureNextField(SWF_FIELD_UI16);
						}
						else
						{
							tag.configureNextField(SWF_FIELD_UI8);
						}
						tag.parseFields(cur_pos);
						font_code_tables[font_id][i] = (u16) tag.fields[0].value;
					}

					// Read layout section if present
					if (has_layout && num_entries > 0)
					{
						// FontAscent(SI16), FontDescent(SI16), FontLeading(SI16)
						tag.clearFields();
						tag.setFieldCount(3);
						tag.configureNextField(SWF_FIELD_SI16);
						tag.configureNextField(SWF_FIELD_SI16);
						tag.configureNextField(SWF_FIELD_SI16);
						tag.parseFields(cur_pos);
						font_ascent[font_id] = (s16) tag.fields[0].value;
						font_descent[font_id] = (s16) tag.fields[1].value;
						font_leading[font_id] = (s16) tag.fields[2].value;

						// Advance table: num_entries SI16 values
						font_advance_tables[font_id].resize(num_entries);
						for (u16 i = 0; i < num_entries; ++i)
						{
							tag.clearFields();
							tag.setFieldCount(1);
							tag.configureNextField(SWF_FIELD_SI16);
							tag.parseFields(cur_pos);
							font_advance_tables[font_id][i] = (s16) tag.fields[0].value;
						}
					}

					// Skip any remaining data (bounds table, kerning, etc.)
					cur_pos = font_tag_start + font_tag_length;
				}

				// Device font fallback: if glyph shapes are empty, tessellate from Noto Sans TTF.
				// Gated by SWFRECOMP_DEVICE_FONT_FALLBACK env var (default off); enable with =1
				// to restore the synthesized-glyph behaviour. With it off, deliberately-empty
				// embedded glyphs render as nothing (advance kept), matching Ruffle.
				if (font_code_tables.count(font_id) && deviceFontFallbackEnabled() && loadDeviceFont())
				{
					float swf_em = font_em_square.count(font_id) ? font_em_square[font_id] : 1024.0f;
					float ttf_scale = swf_em / 1000.0f; // Noto Sans EM = 1000

					for (u16 i = 0; i < num_entries; i++) {
						if (i >= font_code_tables[font_id].size()) continue;
						int needs_triangles = (font_glyph_entries[i].second == 0);

						u16 codepoint = font_code_tables[font_id][i];
						int ttf_glyph = stbtt_FindGlyphIndex(&g_device_font, codepoint);
						if (ttf_glyph <= 0) continue;

						stbtt_vertex* verts = NULL;
						int num_verts = stbtt_GetGlyphShape(&g_device_font, ttf_glyph, &verts);
						if (num_verts <= 0) continue;

						// Build polygon contours from TTF outline AND emit path commands
						std::vector<std::vector<std::array<Coord, 2>>> polygon;
						std::vector<std::array<Coord, 2>> contour;

						// Emit glyph path header: fill1=1, non-zero winding (font glyphs)
						size_t glyph_path_start = current_path_entry;
						auto emitGP = [&](float cmd, float a, float b) {
							path_data << "\t{" << std::fixed << std::setprecision(1)
							          << cmd << "f, " << a << "f, " << b << "f},\n";
							current_path_entry++;
						};
						emitGP(1.0f, 0.0f, 1.0f);  // fill0=0, fill1=1
						emitGP(1.5f, 0.0f, 0.0f);  // no line style

						for (int v = 0; v < num_verts; v++) {
							if (verts[v].type == STBTT_vmove) {
								if (!contour.empty()) {
									polygon.push_back(contour);
									contour.clear();
								}
								// Emit MoveTo for path data
								emitGP(5.0f, verts[v].x * ttf_scale, -verts[v].y * ttf_scale);
							} else if (verts[v].type == STBTT_vline) {
								float lx = verts[v].x * ttf_scale;
								float ly = -verts[v].y * ttf_scale;
								contour.push_back({(Coord)lx, (Coord)ly});
								emitGP(2.0f, lx, ly);
							} else if (verts[v].type == STBTT_vcurve) {
								// Quadratic bezier: emit raw curve for path, subdivide for triangles
								float x0, y0;
								if (!contour.empty()) {
									x0 = (float)contour.back()[0];
									y0 = (float)contour.back()[1];
								} else { x0 = 0; y0 = 0; }
								float cx = verts[v].cx * ttf_scale;
								float cy = -verts[v].cy * ttf_scale;
								float x1 = verts[v].x * ttf_scale;
								float y1 = -verts[v].y * ttf_scale;
								// Path: raw quadratic curve
								emitGP(3.0f, cx, cy);
								emitGP(4.0f, x1, y1);
								// Triangulation: subdivide into 6 segments
								for (int s = 1; s <= 6; s++) {
									float t = (float)s / 6.0f;
									float it = 1.0f - t;
									contour.push_back({
										(Coord)(it*it*x0 + 2*it*t*cx + t*t*x1),
										(Coord)(it*it*y0 + 2*it*t*cy + t*t*y1)
									});
								}
							} else if (verts[v].type == STBTT_vcubic) {
								// Cubic bezier: decompose to quadratics for path, subdivide for triangles
								float x0, y0;
								if (!contour.empty()) {
									x0 = (float)contour.back()[0];
									y0 = (float)contour.back()[1];
								} else { x0 = 0; y0 = 0; }
								float cx1 = verts[v].cx * ttf_scale;
								float cy1 = -verts[v].cy * ttf_scale;
								float cx2 = verts[v].cx1 * ttf_scale;
								float cy2 = -verts[v].cy1 * ttf_scale;
								float x1 = verts[v].x * ttf_scale;
								float y1 = -verts[v].y * ttf_scale;
								// Path: approximate cubic with 2 quadratics (midpoint split)
								float mx = (cx1 + cx2) * 0.5f;
								float my = (cy1 + cy2) * 0.5f;
								float q1cx = (x0 + cx1) * 0.5f + (cx1 - x0) * 0.25f;
								float q1cy = (y0 + cy1) * 0.5f + (cy1 - y0) * 0.25f;
								// Simpler: split at t=0.5 using de Casteljau
								float h1x = (x0 + cx1) * 0.5f, h1y = (y0 + cy1) * 0.5f;
								float h2x = (cx1 + cx2) * 0.5f, h2y = (cy1 + cy2) * 0.5f;
								float h3x = (cx2 + x1) * 0.5f, h3y = (cy2 + y1) * 0.5f;
								float h12x = (h1x + h2x) * 0.5f, h12y = (h1y + h2y) * 0.5f;
								float h23x = (h2x + h3x) * 0.5f, h23y = (h2y + h3y) * 0.5f;
								float midx = (h12x + h23x) * 0.5f, midy = (h12y + h23y) * 0.5f;
								// First half: quadratic (x0,y0) ctrl(h1x,h1y) anchor(midx,midy)
								// — but quadratic can't exactly represent cubic half; use ctrl≈h12
								emitGP(3.0f, h12x, h12y);
								emitGP(4.0f, midx, midy);
								// Second half: quadratic (midx,midy) ctrl(h23x,h23y) anchor(x1,y1)
								emitGP(3.0f, h23x, h23y);
								emitGP(4.0f, x1, y1);
								// Triangulation: subdivide cubic into 8 segments
								for (int s = 1; s <= 8; s++) {
									float t = (float)s / 8.0f;
									float it = 1.0f - t;
									contour.push_back({
										(Coord)(it*it*it*x0 + 3*it*it*t*cx1 + 3*it*t*t*cx2 + t*t*t*x1),
										(Coord)(it*it*it*y0 + 3*it*it*t*cy1 + 3*it*t*t*cy2 + t*t*t*y1)
									});
								}
							}
						}
						if (!contour.empty()) polygon.push_back(contour);
						stbtt_FreeShape(&g_device_font, verts);

						// Always emit glyph path end marker (path data for hit testing)
						emitGP(0.0f, 0.0f, 0.0f);
						if (current_path_entry > glyph_path_start + 3)  // has actual commands beyond header
							font_glyph_path_entries[i] = {glyph_path_start, current_path_entry - glyph_path_start};

						if (polygon.empty() || polygon[0].size() < 3) continue;

						std::vector<N> indices = mapbox::earcut<N>(polygon);
						if (indices.size() < 3) continue;

						// Flatten polygon for index lookup
						std::vector<std::array<Coord, 2>> all_pts;
						for (auto& ring : polygon)
							for (auto& pt : ring)
								all_pts.push_back(pt);

						// Only emit triangles if the SWF didn't already provide glyph shapes
						if (needs_triangles) {
							font_glyph_entries[i].first = 3 * current_tri;
							font_glyph_entries[i].second = indices.size();

							for (size_t idx = 0; idx < indices.size(); idx++) {
								float x_f = (float)all_pts[indices[idx]][0];
								float y_f = (float)all_pts[indices[idx]][1];
								shape_data << "\t{ "
									<< std::hex << std::uppercase
									<< "0x" << VAL(u32, &x_f) << ", "
									<< "0x" << VAL(u32, &y_f) << ", "
									<< "0x00, 0x00 }," << std::dec << endl;
							}
							current_tri += indices.size() / 3;
						}
					}
				}

				// Write glyph_data entries for this font (4 values per glyph:
				// tri_offset, tri_size, path_offset, path_size)
				for (u16 i = 0; i < num_entries; i++) {
					glyph_data << "\t" << to_string(font_glyph_entries[i].first) << "," << endl
							   << "\t" << to_string(font_glyph_entries[i].second) << "," << endl
							   << "\t" << to_string(font_glyph_path_entries.size() > i ? font_glyph_path_entries[i].first : 0) << "," << endl
							   << "\t" << to_string(font_glyph_path_entries.size() > i ? font_glyph_path_entries[i].second : 0) << "," << endl;
					current_glyph += 1;
				}

				// Always skip to end of font tag data (handles 0-glyph fonts,
				// remaining bounds/kerning tables, etc.)
				cur_pos = font_tag_start + font_tag_length;

				// Emit tagDefineFontInfo for NO_GRAPHICS runtime
				if (font_names.find(font_id) != font_names.end()) {
					auto escape_for_c = [](const std::string& s) {
						std::string out;
						for (char c : s) {
							if (c == '\\') out += "\\\\";
							else if (c == '"') out += "\\\"";
							else if (c == '\n') out += "\\n";
							else if (c == '\r') out += "\\r";
							else if (c == '\t') out += "\\t";
							else out += c;
						}
						return out;
					};
					bool is_bold = font_bold_flags.count(font_id) ? font_bold_flags[font_id] : false;
					bool is_italic = font_italic_flags.count(font_id) ? font_italic_flags[font_id] : false;
					tag_init << endl
							 << "\t" << "tagDefineFontInfo("
							 << "app_context, "
							 << to_string(font_id) << ", "
							 << "\"" << escape_for_c(font_names[font_id]) << "\", "
							 << (is_bold ? "1" : "0") << ", "
							 << (is_italic ? "1" : "0")
							 << ");";

					// Emit font metrics (advance table + ascent/descent/leading) if available
					if (font_advance_tables.count(font_id) && font_advance_tables[font_id].size() > 0 &&
						font_code_tables.count(font_id)) {
						auto& advances = font_advance_tables[font_id];
						auto& codes = font_code_tables[font_id];
						s16 ascent = font_ascent.count(font_id) ? font_ascent[font_id] : 0;
						s16 descent = font_descent.count(font_id) ? font_descent[font_id] : 0;
						s16 leading = font_leading.count(font_id) ? font_leading[font_id] : 0;
						float em_sq = font_em_square.count(font_id) ? font_em_square[font_id] : 1024.0f;

						// Emit static arrays for code table and advance table
						tag_init << endl
								 << "\t" << "{" << endl
								 << "\t\t" << "static const u16 font_" << font_id << "_codes[] = {";
						for (size_t i = 0; i < codes.size(); i++) {
							if (i > 0) tag_init << ",";
							tag_init << (u16)codes[i];
						}
						tag_init << "};" << endl
								 << "\t\t" << "static const s16 font_" << font_id << "_advances[] = {";
						for (size_t i = 0; i < advances.size(); i++) {
							if (i > 0) tag_init << ",";
							tag_init << advances[i];
						}
						tag_init << "};" << endl
								 << "\t\t" << "tagDefineFontMetrics("
								 << "app_context, "
								 << to_string(font_id) << ", "
								 << to_string(ascent) << ", "
								 << to_string(descent) << ", "
								 << to_string(leading) << ", "
								 << to_string((int)em_sq) << ", "
								 << "font_" << font_id << "_codes, "
								 << "font_" << font_id << "_advances, "
								 << to_string(codes.size())
								 << ");" << endl
								 << "\t" << "}" << endl;
						// Emit glyph base index for runtime glyph rendering
						auto gb_it = font_glyph_bases.find(font_id);
						if (gb_it != font_glyph_bases.end()) {
							context.tag_main << "\t" << "tagDefineFontGlyphBase("
								 << to_string(font_id) << ", "
								 << to_string(gb_it->second) << ");";
						}
					}
				}

				break;
			}

			case SWF_TAG_DEFINE_TEXT:
			case SWF_TAG_DEFINE_TEXT_2:
			{
				bool text_has_alpha = (tag.code == SWF_TAG_DEFINE_TEXT_2);

				tag.clearFields();
				tag.setFieldCount(1);

				tag.configureNextField(SWF_FIELD_UI16);

				tag.parseFields(cur_pos);

				u16 char_id = (u16) tag.fields[0].value;

				// Register text char_id for place-before-define tracking.
				defined_chars.insert(char_id);

				tag.clearFields();
				tag.setFieldCount(5);

				tag.configureNextField(SWF_FIELD_UB, 5, true);
				tag.configureNextField(SWF_FIELD_SB, 0);
				tag.configureNextField(SWF_FIELD_SB, 0);
				tag.configureNextField(SWF_FIELD_SB, 0);
				tag.configureNextField(SWF_FIELD_SB, 0);

				tag.parseFields(cur_pos);

				s32 text_bounds_xmin = (s32) tag.fields[1].value;
				s32 text_bounds_xmax = (s32) tag.fields[2].value;
				s32 text_bounds_ymin = (s32) tag.fields[3].value;
				s32 text_bounds_ymax = (s32) tag.fields[4].value;

				MATRIX matrix;
				parseMatrix(matrix);

				tag.clearFields();
				tag.setFieldCount(2);

				tag.configureNextField(SWF_FIELD_UI8);
				tag.configureNextField(SWF_FIELD_UI8);

				tag.parseFields(cur_pos);

				u8 glyph_bits = (u8) tag.fields[0].value;
				u8 advance_bits = (u8) tag.fields[1].value;

				size_t text_record_count = 0;
				while (true)
				{
					if (++text_record_count > 10000)
					{
						fprintf(stderr, "Warning: text record parsing exceeded 10000 iterations, skipping rest\n");
						break;
					}

					tag.clearFields();
					tag.setFieldCount(1);

					tag.configureNextField(SWF_FIELD_UI8);

					tag.parseFields(cur_pos);

					u8 flags = (u8) tag.fields[0].value;

					if (flags == 0)
					{
						break;
					}

					bool has_font = (flags & 0b1000);
					bool has_color = (flags & 0b0100);
					bool has_x_offset = (flags & 0b0010);
					bool has_y_offset = (flags & 0b0001);

					u32 color_fields = text_has_alpha ? 4 : 3;
					u32 field_count = 2*has_font + color_fields*has_color + has_x_offset + has_y_offset + 1;

					tag.clearFields();
					tag.setFieldCount(field_count);

					if (has_font)
					{
						tag.configureNextField(SWF_FIELD_UI16);
					}

					if (has_color)
					{
						tag.configureNextField(SWF_FIELD_UI8);
						tag.configureNextField(SWF_FIELD_UI8);
						tag.configureNextField(SWF_FIELD_UI8);
						if (text_has_alpha)
						{
							tag.configureNextField(SWF_FIELD_UI8);
						}
					}

					if (has_x_offset)
					{
						tag.configureNextField(SWF_FIELD_SI16);
					}

					if (has_y_offset)
					{
						tag.configureNextField(SWF_FIELD_SI16);
					}

					if (has_font)
					{
						tag.configureNextField(SWF_FIELD_UI16);
					}

					tag.configureNextField(SWF_FIELD_UI8);

					tag.parseFields(cur_pos);

					size_t current_field = 0;

					MATRIX temp_matrix = matrix;

					u16 font_id;
					u8 r;
					u8 g;
					u8 b;
					s16 x_offset;
					s16 y_offset;
					u16 text_height;

					u32 cxform_id = 0;

					if (has_font)
					{
						font_id = (u16) tag.fields[current_field++].value;
					}

					if (has_color)
					{
						r = (u8) tag.fields[current_field++].value;
						g = (u8) tag.fields[current_field++].value;
						b = (u8) tag.fields[current_field++].value;

						u8 a = 255;
						if (text_has_alpha)
						{
							a = (u8) tag.fields[current_field++].value;
						}

						cxform_id = (u32) current_cxform;

						cxform_data << "\t" << "0.0f," << endl
									<< "\t" << "0.0f," << endl
									<< "\t" << "0.0f," << endl
									<< "\t" << "0.0f," << endl

									<< "\t" << "0.0f," << endl
									<< "\t" << "0.0f," << endl
									<< "\t" << "0.0f," << endl
									<< "\t" << "0.0f," << endl

									<< "\t" << "0.0f," << endl
									<< "\t" << "0.0f," << endl
									<< "\t" << "0.0f," << endl
									<< "\t" << "0.0f," << endl

									<< "\t" << "0.0f," << endl
									<< "\t" << "0.0f," << endl
									<< "\t" << "0.0f," << endl
									<< "\t" << (a == 255 ? "1.0f" : "0.0f") << "," << endl

									<< "\t" << to_string(r) << "/255.0f," << endl
									<< "\t" << to_string(g) << "/255.0f," << endl
									<< "\t" << to_string(b) << "/255.0f," << endl
									<< "\t" << (a == 255 ? "0.0f" : to_string(a) + "/255.0f") << "," << endl;

						current_cxform += 1;
					}

					if (has_x_offset)
					{
						x_offset = (s16) tag.fields[current_field++].value;
					}

					if (has_y_offset)
					{
						y_offset = (s16) tag.fields[current_field++].value;
					}

					if (has_font)
					{
						text_height = (u16) tag.fields[current_field++].value;
						float em = 1024.0f;
						auto it = font_em_square.find(font_id);
						if (it != font_em_square.end()) em = it->second;
						temp_matrix.scale_x = ((float) text_height) / em;
						temp_matrix.scale_y = ((float) text_height) / em;
					}

					u8 glyph_count = (u8) tag.fields[current_field++].value;

					if (has_x_offset)
					{
						temp_matrix.translate_x += x_offset;
					}
					if (has_y_offset)
					{
						temp_matrix.translate_y += y_offset;
					}

					size_t text_start = current_text;
					size_t transform_start = current_transform;

					u32 cur_byte_bits_left = 8;

					recompileMatrix(temp_matrix, transform_data);
					current_transform += 1;

					for (u8 i = 0; i < glyph_count; ++i)
					{
						tag.clearFields();
						tag.setFieldCount(2);

						tag.configureNextField(SWF_FIELD_UB, glyph_bits);
						tag.configureNextField(SWF_FIELD_SB, advance_bits);

						tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);

						u32 glyph_index = (u32) tag.fields[0].value;
						u32 advance = (u32) tag.fields[1].value;

						// Store for deferred char code lookup (font may not be parsed yet)
						text_glyph_entries.push_back({font_id, glyph_index});

						temp_matrix.translate_x += advance;
						recompileMatrix(temp_matrix, transform_data);
						current_transform += 1;

						current_text += 1;
					}

					if (cur_byte_bits_left != 8)
					{
						cur_pos += 1;
					}

					size_t text_size = current_text - text_start;
					tag_init << endl
							 << "\t" << "tagDefineText("
							 << "app_context, "
							 << to_string(char_id) << ", "
							 << to_string(text_start) << ", "
							 << to_string(text_size) << ", "
							 << to_string(transform_start) << ", "
							 << to_string(cxform_id) << ", "
							 << to_string(text_bounds_xmin) << ", "
							 << to_string(text_bounds_xmax) << ", "
							 << to_string(text_bounds_ymin) << ", "
							 << to_string(text_bounds_ymax)
							 << ");";
				}

				break;
			}

			case SWF_TAG_DEFINE_EDIT_TEXT:
			{
				tag.clearFields();
				tag.setFieldCount(1);
				tag.configureNextField(SWF_FIELD_UI16);
				tag.parseFields(cur_pos);

				u16 char_id = (u16) tag.fields[0].value;

				// Register edit text char_id for place-before-define tracking.
				defined_chars.insert(char_id);

				// Bounds RECT
				tag.clearFields();
				tag.setFieldCount(5);
				tag.configureNextField(SWF_FIELD_UB, 5, true);
				tag.configureNextField(SWF_FIELD_SB, 0);
				tag.configureNextField(SWF_FIELD_SB, 0);
				tag.configureNextField(SWF_FIELD_SB, 0);
				tag.configureNextField(SWF_FIELD_SB, 0);
				tag.parseFields(cur_pos);

				s32 bounds_xmin = (s32) tag.fields[1].value;
				s32 bounds_xmax = (s32) tag.fields[2].value;
				s32 bounds_ymin = (s32) tag.fields[3].value;
				s32 bounds_ymax = (s32) tag.fields[4].value;

				// Flags (UI16, but stored as two UI8s: low byte first)
				tag.clearFields();
				tag.setFieldCount(2);
				tag.configureNextField(SWF_FIELD_UI8);
				tag.configureNextField(SWF_FIELD_UI8);
				tag.parseFields(cur_pos);

				u8 flags_lo = (u8) tag.fields[0].value;
				u8 flags_hi = (u8) tag.fields[1].value;

				bool has_text = (flags_lo & 0x80) != 0;
				bool has_text_color = (flags_lo & 0x04) != 0;
				bool has_max_length = (flags_lo & 0x02) != 0;
				bool has_font = (flags_lo & 0x01) != 0;
				bool has_layout = (flags_hi & 0x20) != 0;

				u16 font_id = 0;
				u16 font_height = 0;
				u8 r = 0, g = 0, b = 0, a = 255;
				s16 max_length = -1;
				u8 align = 0;
				u16 left_margin = 0, right_margin = 0;
				s16 indent = 0;
				s16 leading = 0;

				if (has_font)
				{
					tag.clearFields();
					tag.setFieldCount(2);
					tag.configureNextField(SWF_FIELD_UI16);  // FontID
					tag.configureNextField(SWF_FIELD_UI16);  // FontHeight
					tag.parseFields(cur_pos);
					font_id = (u16) tag.fields[0].value;
					font_height = (u16) tag.fields[1].value;
				}

				if (has_text_color)
				{
					tag.clearFields();
					tag.setFieldCount(4);
					tag.configureNextField(SWF_FIELD_UI8);  // R
					tag.configureNextField(SWF_FIELD_UI8);  // G
					tag.configureNextField(SWF_FIELD_UI8);  // B
					tag.configureNextField(SWF_FIELD_UI8);  // A
					tag.parseFields(cur_pos);
					r = (u8) tag.fields[0].value;
					g = (u8) tag.fields[1].value;
					b = (u8) tag.fields[2].value;
					a = (u8) tag.fields[3].value;
				}

				if (has_max_length)
				{
					tag.clearFields();
					tag.setFieldCount(1);
					tag.configureNextField(SWF_FIELD_UI16);
					tag.parseFields(cur_pos);
					max_length = (s16) tag.fields[0].value;
				}

				if (has_layout)
				{
					tag.clearFields();
					tag.setFieldCount(5);
					tag.configureNextField(SWF_FIELD_UI8);   // Align
					tag.configureNextField(SWF_FIELD_UI16);  // LeftMargin
					tag.configureNextField(SWF_FIELD_UI16);  // RightMargin
					tag.configureNextField(SWF_FIELD_UI16);  // Indent
					tag.configureNextField(SWF_FIELD_SI16);  // Leading
					tag.parseFields(cur_pos);
					align = (u8) tag.fields[0].value;
					left_margin = (u16) tag.fields[1].value;
					right_margin = (u16) tag.fields[2].value;
					indent = (s16) tag.fields[3].value;
					leading = (s16) tag.fields[4].value;
				}

				// VariableName (null-terminated STRING)
				std::string variable_name(cur_pos);
				while (*cur_pos != '\0') cur_pos++;
				cur_pos++;  // skip null terminator

				// InitialText (null-terminated STRING, if HasText)
				std::string initial_text;
				if (has_text)
				{
					initial_text = std::string(cur_pos);
					cur_pos += initial_text.size() + 1;  // skip string + null
				}

				// Only emit if we have font, text, and a code table
				if (has_font && has_text && !initial_text.empty() &&
					font_code_tables.find(font_id) != font_code_tables.end())
				{
					// Build reverse code table: character code → glyph index
					const auto& code_table = font_code_tables[font_id];
					std::unordered_map<u16, u16> char_to_glyph;
					for (u16 i = 0; i < code_table.size(); ++i)
					{
						char_to_glyph[code_table[i]] = i;
					}

					// Build cxform for text color
					u32 cxform_id = (u32) current_cxform;

					cxform_data << "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl

								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl

								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl

								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << (a == 255 ? "1.0f" : "0.0f") << "," << endl

								<< "\t" << to_string(r) << "/255.0f," << endl
								<< "\t" << to_string(g) << "/255.0f," << endl
								<< "\t" << to_string(b) << "/255.0f," << endl
								<< "\t" << (a == 255 ? "0.0f" : to_string(a) + "/255.0f") << "," << endl;

					current_cxform += 1;

					// Build matrix for text rendering
					MATRIX temp_matrix;
					float em = 1024.0f;
					auto it = font_em_square.find(font_id);
					if (it != font_em_square.end()) em = it->second;
					temp_matrix.scale_x = ((float) font_height) / em;
					temp_matrix.scale_y = ((float) font_height) / em;
					temp_matrix.rotateskew_0 = 0.0f;
					temp_matrix.rotateskew_1 = 0.0f;
					temp_matrix.translate_x = 0;
					temp_matrix.translate_y = 0;

					size_t text_start = current_text;
					size_t transform_start = current_transform;

					recompileMatrix(temp_matrix, transform_data);
					current_transform += 1;

					// Emit glyph indices for each character in InitialText
					for (size_t i = 0; i < initial_text.size(); ++i)
					{
						u16 char_code = (u16)(unsigned char) initial_text[i];
						auto git = char_to_glyph.find(char_code);
						if (git == char_to_glyph.end()) continue;

						u32 glyph_index = git->second;

						// Store for deferred char code lookup
						text_glyph_entries.push_back({font_id, glyph_index});

						// Advance by per-glyph width if available, otherwise full EM
						s32 advance = (s32) em;
						auto ait = font_advance_tables.find(font_id);
						if (ait != font_advance_tables.end() && glyph_index < ait->second.size())
							advance = (s32) ait->second[glyph_index];
						temp_matrix.translate_x += advance;
						recompileMatrix(temp_matrix, transform_data);
						current_transform += 1;

						current_text += 1;
					}

					size_t text_size = current_text - text_start;
					tag_init << endl
							 << "\t" << "tagDefineText("
							 << "app_context, "
							 << to_string(char_id) << ", "
							 << to_string(text_start) << ", "
							 << to_string(text_size) << ", "
							 << to_string(transform_start) << ", "
							 << to_string(cxform_id) << ", "
							 << to_string(bounds_xmin) << ", "
							 << to_string(bounds_xmax) << ", "
							 << to_string(bounds_ymin) << ", "
							 << to_string(bounds_ymax)
							 << ");";
				}

				// Emit tagDefineEditTextProps for NO_GRAPHICS runtime
				{
					auto escape_for_c = [](const std::string& s) {
						std::string out;
						for (char c : s) {
							if (c == '\\') out += "\\\\";
							else if (c == '"') out += "\\\"";
							else if (c == '\n') out += "\\n";
							else if (c == '\r') out += "\\r";
							else if (c == '\t') out += "\\t";
							else out += c;
						}
						return out;
					};
					// Strip HTML tags to get plain text
					std::string plain_text;
					bool in_tag = false;
					for (char c : initial_text) {
						if (c == '<') { in_tag = true; continue; }
						if (c == '>') { in_tag = false; continue; }
						if (!in_tag) plain_text += c;
					}
					// Pack text color as 0xRRGGBB
					u32 text_color = ((u32)r << 16) | ((u32)g << 8) | (u32)b;
					// Pack flags: WordWrap|Multiline|Password|ReadOnly|NoSelect|Border|HTML|UseOutlines|AutoSize
					u16 packed_flags = 0;
					if (flags_lo & 0x40) packed_flags |= 0x0001;  // WordWrap
					if (flags_lo & 0x20) packed_flags |= 0x0002;  // Multiline
					if (flags_lo & 0x10) packed_flags |= 0x0004;  // Password
					if (flags_lo & 0x08) packed_flags |= 0x0008;  // ReadOnly
					if (flags_hi & 0x10) packed_flags |= 0x0010;  // NoSelect
					if (flags_hi & 0x08) packed_flags |= 0x0020;  // Border
					if (flags_hi & 0x02) packed_flags |= 0x0040;  // HTML
					if (flags_hi & 0x01) packed_flags |= 0x0080;  // UseOutlines
					if (flags_hi & 0x40) packed_flags |= 0x0100;  // AutoSize
					tag_init << endl
							 << "\t" << "tagDefineEditTextProps("
							 << "app_context, "
							 << to_string(char_id) << ", "
							 << "\"" << escape_for_c(plain_text) << "\", "
							 << "\"" << escape_for_c(initial_text) << "\", "
							 << to_string(text_color) << ", "
							 << to_string(font_id) << ", "
							 << to_string(font_height) << ", "
							 << to_string(max_length) << ", "
							 << to_string(align) << ", "
							 << to_string(left_margin) << ", "
							 << to_string(right_margin) << ", "
							 << to_string(indent) << ", "
							 << to_string(leading) << ", "
							 << "\"" << escape_for_c(variable_name) << "\", "
							 << to_string(packed_flags) << ", "
							 << to_string(bounds_xmin) << ", "
							 << to_string(bounds_xmax) << ", "
							 << to_string(bounds_ymin) << ", "
							 << to_string(bounds_ymax)
							 << ");";
				}

				break;
			}

			case SWF_TAG_DO_ACTION:
			{
				context.out_script_header << endl << "void script_" << to_string(next_script_i) << "(SWFAppContext* app_context);";

				ofstream out_script(context.output_scripts_folder + "script_" + to_string(next_script_i) + ".c", ios_base::out);
				out_script << "#include <recomp.h>" << endl
						   << "#include <setjmp.h>" << endl
						   << "#include \"script_decls.h\"" << endl << endl
						   << "void script_" << next_script_i << "(SWFAppContext* app_context)" << endl
						   << "{" << endl;
				out_script << "\t" << "char str_buffer[17];" << endl << endl;
				out_script << "\t" << "actionResetRegisters();" << endl << endl;

				size_t root_script_id = next_script_i;
				next_script_i += 1;

				// Parse actions using a bounded temp buffer to prevent overrun
				// when the DoAction tag body omits the trailing END_OF_ACTIONS byte
				{
					char* tag_body_start = cur_pos;
					u32 body_len = tag.length;
					char* temp_buffer = (char*)malloc(body_len + 1);
					memcpy(temp_buffer, tag_body_start, body_len);
					temp_buffer[body_len] = 0x00; // Ensure END_OF_ACTIONS marker
					char* temp_ptr = temp_buffer;
					// Wire up cross-DoAction backward-jump support: a BranchAlways/If
					// with a negative offset that crosses this DoAction's body
					// boundary lands at an absolute SWF position. If that position
					// matches the body-start of an earlier DoAction we've already
					// compiled, emit `script_N(); return;` instead of plain return.
					action.abs_swf_buffer_start_ptr = tag_body_start;
					action.doaction_script_map_ptr = &doaction_script_map;
					action.parseActions(context, temp_ptr, out_script);
					action.abs_swf_buffer_start_ptr = nullptr;
					action.doaction_script_map_ptr = nullptr;
					// Register this DoAction's body→script mapping AFTER parsing,
					// so a self-referential backward jump within this DoAction
					// keeps using the in-buffer goto path (handled by labels).
					doaction_script_map[tag_body_start] = "script_" + to_string(root_script_id);
					free(temp_buffer);
					cur_pos = tag_body_start + body_len;
				}

				out_script << "}";

				// Phase 6: queue the root DoAction inline at this tag's
				// position. The drain at ShowFrame/EndTag pops in FIFO order,
				// fixing the DoAction-A → PlaceObject → DoAction-B ordering.
				// Gate: skip during catch-up replay, but queue during the
				// target-frame scripts-only replay (g_tag_skip_mode=1).
				context.tag_main << "\t" << "if (!catch_up_mode || g_tag_skip_mode) actionQueueScript(app_context, script_"
								 << to_string(root_script_id) << ");" << endl;

				break;
			}
			
			case SWF_TAG_DO_INIT_ACTION:
			{
				// SpriteId (UI16) — identifies which sprite this init action belongs to
				tag.setFieldCount(1);
				tag.configureNextField(SWF_FIELD_UI16);
				tag.parseFields(cur_pos);
				u16 init_sprite_id = (u16) tag.fields[0].value;

				std::string func_name = "script_" + to_string(next_script_i);

				context.out_script_header << endl << "void " << func_name << "(SWFAppContext* app_context);";

				ofstream out_script(context.output_scripts_folder + func_name + ".c", ios_base::out);
				out_script << "#include <recomp.h>" << endl
						   << "#include <setjmp.h>" << endl
						   << "#include \"script_decls.h\"" << endl << endl
						   << "void " << func_name << "(SWFAppContext* app_context)" << endl
						   << "{" << endl;
				out_script << "\t" << "char str_buffer[17];" << endl << endl;
				out_script << "\t" << "actionResetRegisters();" << endl << endl;

				next_script_i += 1;

				action.parseActions(context, cur_pos, out_script);

				out_script << "}";

				// Buffer the call into the current-frame prologue so it
				// emits at the top of frame_N's body, before any same-frame
				// PlaceObject2/DoAction. Mirrors Ruffle's preload pass.
				// Gated on (!catch_up_mode || g_tag_skip_mode) and dispatched
				// via tagDoInitActionGuarded so the per-character once-only
				// guard short-circuits during script-only target replay.
				current_frame_init_actions
					<< "\tif (!catch_up_mode || g_tag_skip_mode) "
					<< "tagDoInitActionGuarded(app_context, "
					<< to_string(init_sprite_id) << ", " << func_name << ");"
					<< endl;



				break;
			}

			case SWF_TAG_DEFINE_FONT_INFO:
			{
				cur_pos += tag.length;

				break;
			}

			case SWF_TAG_PLACE_OBJECT:
			{
				// PlaceObject (tag 4): CharacterId(UI16), Depth(UI16), Matrix, optional CXFORM (RGB only)
				char* tag_end = cur_pos + tag.length;

				tag.setFieldCount(2);
				tag.configureNextField(SWF_FIELD_UI16);
				tag.configureNextField(SWF_FIELD_UI16);
				tag.parseFields(cur_pos);

				u16 char_id = (u16) tag.fields[0].value;
				u16 depth = (u16) tag.fields[1].value;

				// Place-before-define: PlaceObject (tag 4) referencing a char_id
				// that has not yet been registered by an earlier DefineSprite.
				// Flash treats this as a failed placement. Degrade to char_id=0
				// so the runtime takes the "modify" path, which is a benign no-op
				// when the depth has no prior placement (the typical fuzz case).
				if (char_id != 0 && !defined_chars.count(char_id))
				{
					char_id = 0;
				}

				size_t transform_id = current_transform;
				MATRIX matrix;
				parseMatrix(matrix);
				recompileMatrix(matrix, transform_data);
				current_transform += 1;

				u32 cxform_id = 0;

				// Optional CXFORM (RGB only — 3 channels, no alpha)
				if (cur_pos < tag_end)
				{
					u32 cur_byte_bits_left = 8;
					SWFTag cxform_tag;

					cxform_tag.clearFields();
					cxform_tag.setFieldCount(3);
					cxform_tag.configureNextField(SWF_FIELD_UB, 1);
					cxform_tag.configureNextField(SWF_FIELD_UB, 1);
					cxform_tag.configureNextField(SWF_FIELD_UB, 4);
					cxform_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);

					bool has_add = cxform_tag.fields[0].value & 1;
					bool has_mult = cxform_tag.fields[1].value & 1;
					u32 nbits = (u32) cxform_tag.fields[2].value;

					// Defaults: multiply = 256 (1.0), add = 0; alpha = identity
					s32 mult_r = 256, mult_g = 256, mult_b = 256, mult_a = 256;
					s32 add_r = 0, add_g = 0, add_b = 0, add_a = 0;

					if (has_mult)
					{
						cxform_tag.clearFields();
						cxform_tag.setFieldCount(3);
						cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
						cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
						cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
						cxform_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);

						mult_r = (s32) cxform_tag.fields[0].value;
						mult_g = (s32) cxform_tag.fields[1].value;
						mult_b = (s32) cxform_tag.fields[2].value;
					}

					if (has_add)
					{
						cxform_tag.clearFields();
						cxform_tag.setFieldCount(3);
						cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
						cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
						cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
						cxform_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);

						add_r = (s32) cxform_tag.fields[0].value;
						add_g = (s32) cxform_tag.fields[1].value;
						add_b = (s32) cxform_tag.fields[2].value;
					}

					if (cur_byte_bits_left != 8)
					{
						cur_pos += 1;
					}

					cxform_id = (u32) current_cxform;

					cxform_data << "\t" << to_string(mult_r) << "/256.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << to_string(mult_g) << "/256.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << to_string(mult_b) << "/256.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << to_string(mult_a) << "/256.0f," << endl
								<< "\t" << to_string(add_r) << "/255.0f," << endl
								<< "\t" << to_string(add_g) << "/255.0f," << endl
								<< "\t" << to_string(add_b) << "/255.0f," << endl
								<< "\t" << to_string(add_a) << "/255.0f," << endl;

					current_cxform += 1;
				}

				context.tag_main << "\t" << "tagPlaceObject2(app_context, " << to_string(depth) << ", " << to_string(char_id) << ", " << to_string(transform_id) << ", " << to_string(cxform_id) << ", 0);" << endl;

				break;
			}

			case SWF_TAG_PLACE_OBJECT_3:
			case SWF_TAG_PLACE_OBJECT_2:
			{
				bool is_po3 = (tag.code == SWF_TAG_PLACE_OBJECT_3);

				// PlaceObject3 extra flags byte
				bool has_filter_list = false;
				bool has_blend_mode = false;
				bool has_cache_as_bitmap = false;
				bool has_visible = false;
				bool has_opaque_background = false;
				bool has_class_name = false;
				bool has_image = false;

				// PO2: flags(UI8) + depth(UI16)
				// PO3: flags(UI8) + flags2(UI8) + depth(UI16)
				tag.setFieldCount(1);
				tag.configureNextField(SWF_FIELD_UI8);
				tag.parseFields(cur_pos);
				u8 flags = (u8) tag.fields[0].value;

				if (is_po3)
				{
					tag.clearFields();
					tag.setFieldCount(1);
					tag.configureNextField(SWF_FIELD_UI8);
					tag.parseFields(cur_pos);
					u8 flags2 = (u8) tag.fields[0].value;

					// PlaceObject3 flags2 bit layout (per SWF spec / Ruffle):
					// bit 0: HasFilterList
					// bit 1: HasBlendMode
					// bit 2: HasCacheAsBitmap
					// bit 3: HasClassName
					// bit 4: HasImage
					// bit 5: HasVisible
					// bit 6: OpaqueBackground
					has_filter_list = (flags2 & 0b00000001) != 0;
					has_blend_mode = (flags2 & 0b00000010) != 0;
					has_cache_as_bitmap = (flags2 & 0b00000100) != 0;
					has_class_name = (flags2 & 0b00001000) != 0;
					has_image = (flags2 & 0b00010000) != 0;
					has_visible = (flags2 & 0b00100000) != 0;
					has_opaque_background = (flags2 & 0b01000000) != 0;
				}

				tag.clearFields();
				tag.setFieldCount(1);
				tag.configureNextField(SWF_FIELD_UI16);
				tag.parseFields(cur_pos);
				u16 depth = (u16) tag.fields[0].value;

				bool has_clip_actions = (flags & 0b10000000) != 0;
				bool has_clip_depth = (flags & 0b01000000) != 0;
				bool has_name = (flags & 0b00100000) != 0;
				bool has_ratio = (flags & 0b00010000) != 0;
				bool has_color = (flags & 0b00001000) != 0;
				bool has_matrix = (flags & 0b00000100) != 0;
				bool has_character = (flags & 0b00000010) != 0;
				bool move = (flags & 0b00000001) != 0;

				// Skip ClassName (if HasClassName or (HasImage && HasCharacter))
				if (is_po3 && (has_class_name || (has_image && has_character)))
				{
					while (*cur_pos != '\0') cur_pos++;
					cur_pos++;
				}
				
				u16 char_id = 0;

				if (has_character)
				{
					tag.clearFields();
					tag.setFieldCount(1);

					tag.configureNextField(SWF_FIELD_UI16);

					tag.parseFields(cur_pos);

					char_id = (u16) tag.fields[0].value;
				}

				// Place-before-define: PO2/3 referencing a char_id whose
				// DefineSprite has not been encountered yet in tag-stream order.
				// Flash treats this as a failed placement (no character placed,
				// no sprite frame scripts run). Degrade to a "modify" by clearing
				// has_character and char_id; the runtime no-ops modify when the
				// depth was previously empty, which is the fuzz pattern of
				// place-then-define-later. Anything Ruffle eagerly placed in this
				// situation is a Ruffle behavior we are intentionally not
				// matching — see RUFFLE_VS_FLASH_DIFFERENCES.md.
				if (has_character && char_id != 0 && !defined_chars.count(char_id))
				{
					has_character = false;
					char_id = 0;
				}

				std::string transform_name = "transform_" + to_string(num_finished_tags);
				
				size_t transform_id = current_transform;
				
				if (has_matrix)
				{
					MATRIX matrix;
					parseMatrix(matrix);

					recompileMatrix(matrix, transform_data);
					current_transform += 1;
				}

				else
				{
					transform_id = 0;
				}

				u32 cxform_id = 0;

				if (has_color)
				{
					// Parse CXFORMWITHALPHA
					u32 cur_byte_bits_left = 8;
					SWFTag cxform_tag;

					// Read HasAddTerms (1 bit), HasMultTerms (1 bit), Nbits (4 bits)
					cxform_tag.clearFields();
					cxform_tag.setFieldCount(3);
					cxform_tag.configureNextField(SWF_FIELD_UB, 1);
					cxform_tag.configureNextField(SWF_FIELD_UB, 1);
					cxform_tag.configureNextField(SWF_FIELD_UB, 4);
					cxform_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);

					bool has_add = cxform_tag.fields[0].value & 1;
					bool has_mult = cxform_tag.fields[1].value & 1;
					u32 nbits = (u32) cxform_tag.fields[2].value;

					// Default multiply = 256 (1.0 in 8.8 fixed-point), default add = 0
					s32 mult_r = 256, mult_g = 256, mult_b = 256, mult_a = 256;
					s32 add_r = 0, add_g = 0, add_b = 0, add_a = 0;

					if (has_mult)
					{
						cxform_tag.clearFields();
						cxform_tag.setFieldCount(4);
						cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
						cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
						cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
						cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
						cxform_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);

						mult_r = (s32) cxform_tag.fields[0].value;
						mult_g = (s32) cxform_tag.fields[1].value;
						mult_b = (s32) cxform_tag.fields[2].value;
						mult_a = (s32) cxform_tag.fields[3].value;
					}

					if (has_add)
					{
						cxform_tag.clearFields();
						cxform_tag.setFieldCount(4);
						cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
						cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
						cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
						cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
						cxform_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);

						add_r = (s32) cxform_tag.fields[0].value;
						add_g = (s32) cxform_tag.fields[1].value;
						add_b = (s32) cxform_tag.fields[2].value;
						add_a = (s32) cxform_tag.fields[3].value;
					}

					if (cur_byte_bits_left != 8)
					{
						cur_pos += 1;
					}

					cxform_id = (u32) current_cxform;

					// Write 20-float cxform matrix: 4x4 diagonal multiply + 4 additive
					// Row 0: R multiply
					cxform_data << "\t" << to_string(mult_r) << "/256.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
					// Row 1: G multiply
								<< "\t" << "0.0f," << endl
								<< "\t" << to_string(mult_g) << "/256.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
					// Row 2: B multiply
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << to_string(mult_b) << "/256.0f," << endl
								<< "\t" << "0.0f," << endl
					// Row 3: A multiply
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << "0.0f," << endl
								<< "\t" << to_string(mult_a) << "/256.0f," << endl
					// Row 4: Additive (RGBA)
								<< "\t" << to_string(add_r) << "/255.0f," << endl
								<< "\t" << to_string(add_g) << "/255.0f," << endl
								<< "\t" << to_string(add_b) << "/255.0f," << endl
								<< "\t" << to_string(add_a) << "/255.0f," << endl;

					current_cxform += 1;
				}

				// Parse remaining optional fields
				u16 ratio_val = 0;
				if (has_ratio)
				{
					tag.clearFields();
					tag.setFieldCount(1);
					tag.configureNextField(SWF_FIELD_UI16);
					tag.parseFields(cur_pos);
					ratio_val = (u16) tag.fields[0].value;
				}
				std::string instance_name_str;
				if (has_name)
				{
					// Capture instance name (null-terminated string)
					char* name_start = cur_pos;
					while (*cur_pos != '\0') cur_pos++;
					instance_name_str = std::string(name_start, cur_pos - name_start);
					cur_pos++; // skip null terminator
				}

				u16 clip_depth_val = 0;
				if (has_clip_depth)
				{
					tag.clearFields();
					tag.setFieldCount(1);
					tag.configureNextField(SWF_FIELD_UI16);
					tag.parseFields(cur_pos);
					clip_depth_val = (u16) tag.fields[0].value;
				}

				// PlaceObject3 extra fields: FilterList, BlendMode, BitmapCache, Visible, OpaqueBackground
				u8 blend_mode_val = 0;
				u32 color_matrix_cxform_id = 0;
				bool has_color_matrix = false;

				// Filter data (first visual filter wins)
				u8 parsed_filter_type = 0;
				double parsed_blur_x = 0, parsed_blur_y = 0;
				u8 parsed_filter_quality = 1;
				u8 parsed_filter_flags = 0;
				double parsed_filter_r = 0, parsed_filter_g = 0, parsed_filter_b = 0, parsed_filter_a = 0;
				double parsed_filter_strength = 1.0;
				double parsed_filter_angle = 0, parsed_filter_distance = 0;
				double parsed_highlight_r = 0, parsed_highlight_g = 0, parsed_highlight_b = 0, parsed_highlight_a = 0;
				// Extended filter data for mc.filters getter
				u8 ext_filter_type = 0; // 5=conv, 6=cm, 7=gradglow, 8=gradbevel
				float ext_cm_matrix[20] = {0};
				u8 ext_conv_mx = 0, ext_conv_my = 0;
				float ext_conv_matrix[25] = {0};
				float ext_conv_divisor = 1, ext_conv_bias = 0;
				u8 ext_conv_preserve_alpha = 1, ext_conv_clamp = 1;
				u8 ext_conv_color_r = 0, ext_conv_color_g = 0, ext_conv_color_b = 0, ext_conv_color_a = 0;
				u8 ext_grad_count = 0;
				u32 ext_grad_colors[16] = {0};
				float ext_grad_alphas[16] = {0};
				u8 ext_grad_ratios[16] = {0};

				// Multi-filter collection for tagBeginFilterList/tagAdd*/tagEndFilterList
				struct CollectedFilter {
					u8 type; // 1=blur, 2=DS, 3=glow, 4=bevel, 5=conv, 6=cm, 7=gradglow, 8=gradbevel
					double blur_x, blur_y;
					u8 quality, flags;
					double r, g, b, a;
					double strength, angle, distance;
					double hr, hg, hb, ha;
					float cm_matrix[20];
					u8 conv_mx, conv_my;
					float conv_matrix[25];
					float conv_divisor, conv_bias;
					u8 conv_preserve_alpha, conv_clamp;
					u8 conv_color_r, conv_color_g, conv_color_b, conv_color_a;
					u8 grad_count;
					u32 grad_colors[16];
					float grad_alphas[16];
					u8 grad_ratios[16];
				};
				CollectedFilter all_filters[16];
				u8 all_filter_count = 0;

				if (is_po3 && has_filter_list)
				{
					u8 num_filters = *(u8*) cur_pos; cur_pos += 1;
					for (u8 f = 0; f < num_filters; f++)
					{
						u8 filter_id = *(u8*) cur_pos; cur_pos += 1;
						switch (filter_id)
						{
							case 0: // DropShadowFilter (23 bytes)
							{
								u8 ds_r = *(u8*)cur_pos; u8 ds_g = *(u8*)(cur_pos+1);
								u8 ds_b = *(u8*)(cur_pos+2); u8 ds_a = *(u8*)(cur_pos+3);
								cur_pos += 4;
								u32 ds_blur_x_raw; memcpy(&ds_blur_x_raw, cur_pos, 4); cur_pos += 4;
								u32 ds_blur_y_raw; memcpy(&ds_blur_y_raw, cur_pos, 4); cur_pos += 4;
								u32 ds_angle_raw; memcpy(&ds_angle_raw, cur_pos, 4); cur_pos += 4;
								u32 ds_dist_raw; memcpy(&ds_dist_raw, cur_pos, 4); cur_pos += 4;
								u16 ds_strength_raw; memcpy(&ds_strength_raw, cur_pos, 2); cur_pos += 2;
								u8 ds_flags_byte = *(u8*)cur_pos; cur_pos += 1;
								if (parsed_filter_type == 0) {
									parsed_filter_type = 2;
									parsed_filter_r = ds_r / 255.0;
									parsed_filter_g = ds_g / 255.0;
									parsed_filter_b = ds_b / 255.0;
									parsed_filter_a = ds_a / 255.0;
									parsed_blur_x = (double)(s32)ds_blur_x_raw / 65536.0;
									parsed_blur_y = (double)(s32)ds_blur_y_raw / 65536.0;
									parsed_filter_angle = (double)(s32)ds_angle_raw / 65536.0;
									parsed_filter_distance = (double)(s32)ds_dist_raw / 65536.0;
									parsed_filter_strength = (double)ds_strength_raw / 256.0;
									parsed_filter_quality = ds_flags_byte & 0x1F;  // bits 0-4
									if (parsed_filter_quality == 0) parsed_filter_quality = 1;
									parsed_filter_flags = (ds_flags_byte >> 5) & 0x07;  // bits 5-7
								}
								if (all_filter_count < 16) {
									auto& cf = all_filters[all_filter_count++];
									memset(&cf, 0, sizeof(cf));
									cf.type = 2; // DropShadow
									cf.r = ds_r / 255.0; cf.g = ds_g / 255.0; cf.b = ds_b / 255.0; cf.a = ds_a / 255.0;
									cf.blur_x = (double)(s32)ds_blur_x_raw / 65536.0;
									cf.blur_y = (double)(s32)ds_blur_y_raw / 65536.0;
									cf.angle = (double)(s32)ds_angle_raw / 65536.0;
									cf.distance = (double)(s32)ds_dist_raw / 65536.0;
									cf.strength = (double)ds_strength_raw / 256.0;
									cf.quality = ds_flags_byte & 0x1F;
									if (cf.quality == 0) cf.quality = 1;
									cf.flags = (ds_flags_byte >> 5) & 0x07;
								}
								break;
							}
							case 1: // BlurFilter (9 bytes)
							{
								u32 bl_x_raw; memcpy(&bl_x_raw, cur_pos, 4); cur_pos += 4;
								u32 bl_y_raw; memcpy(&bl_y_raw, cur_pos, 4); cur_pos += 4;
								u8 bl_flags = *(u8*)cur_pos; cur_pos += 1;
								if (parsed_filter_type == 0) {
									parsed_filter_type = 1;
									parsed_blur_x = (double)(s32)bl_x_raw / 65536.0;
									parsed_blur_y = (double)(s32)bl_y_raw / 65536.0;
									parsed_filter_quality = (bl_flags >> 3) & 0x1F;  // UB[5] = bits 7-3 (MSB first)
									if (parsed_filter_quality == 0) parsed_filter_quality = 1;
								}
								if (all_filter_count < 16) {
									auto& cf = all_filters[all_filter_count++];
									memset(&cf, 0, sizeof(cf));
									cf.type = 1; // Blur
									cf.blur_x = (double)(s32)bl_x_raw / 65536.0;
									cf.blur_y = (double)(s32)bl_y_raw / 65536.0;
									cf.quality = (bl_flags >> 3) & 0x1F;
									if (cf.quality == 0) cf.quality = 1;
								}
								break;
							}
							case 2: // GlowFilter (15 bytes)
							{
								u8 gl_r = *(u8*)cur_pos; u8 gl_g = *(u8*)(cur_pos+1);
								u8 gl_b = *(u8*)(cur_pos+2); u8 gl_a = *(u8*)(cur_pos+3);
								cur_pos += 4;
								u32 gl_blur_x_raw; memcpy(&gl_blur_x_raw, cur_pos, 4); cur_pos += 4;
								u32 gl_blur_y_raw; memcpy(&gl_blur_y_raw, cur_pos, 4); cur_pos += 4;
								u16 gl_strength_raw; memcpy(&gl_strength_raw, cur_pos, 2); cur_pos += 2;
								u8 gl_flags = *(u8*)cur_pos; cur_pos += 1;
								if (parsed_filter_type == 0) {
									parsed_filter_type = 3;
									parsed_filter_r = gl_r / 255.0;
									parsed_filter_g = gl_g / 255.0;
									parsed_filter_b = gl_b / 255.0;
									parsed_filter_a = gl_a / 255.0;
									parsed_blur_x = (double)(s32)gl_blur_x_raw / 65536.0;
									parsed_blur_y = (double)(s32)gl_blur_y_raw / 65536.0;
									parsed_filter_strength = (double)gl_strength_raw / 256.0;
									parsed_filter_quality = gl_flags & 0x1F;  // bits 0-4
									if (parsed_filter_quality == 0) parsed_filter_quality = 1;
									parsed_filter_flags = (gl_flags >> 5) & 0x07;  // bits 5-7
								}
								if (all_filter_count < 16) {
									auto& cf = all_filters[all_filter_count++];
									memset(&cf, 0, sizeof(cf));
									cf.type = 3; // Glow
									cf.r = gl_r / 255.0; cf.g = gl_g / 255.0; cf.b = gl_b / 255.0; cf.a = gl_a / 255.0;
									cf.blur_x = (double)(s32)gl_blur_x_raw / 65536.0;
									cf.blur_y = (double)(s32)gl_blur_y_raw / 65536.0;
									cf.strength = (double)gl_strength_raw / 256.0;
									cf.quality = gl_flags & 0x1F;
									if (cf.quality == 0) cf.quality = 1;
									cf.flags = (gl_flags >> 5) & 0x07;
								}
								break;
							}
							case 3: // BevelFilter (27 bytes)
							{
								// SWF stores HIGHLIGHT first, SHADOW second (spec text is wrong per Ruffle)
								u8 bv_hr = *(u8*)cur_pos; u8 bv_hg = *(u8*)(cur_pos+1);
								u8 bv_hb = *(u8*)(cur_pos+2); u8 bv_ha = *(u8*)(cur_pos+3);
								cur_pos += 4;
								u8 bv_sr = *(u8*)cur_pos; u8 bv_sg = *(u8*)(cur_pos+1);
								u8 bv_sb = *(u8*)(cur_pos+2); u8 bv_sa = *(u8*)(cur_pos+3);
								cur_pos += 4;
								u32 bv_blur_x_raw; memcpy(&bv_blur_x_raw, cur_pos, 4); cur_pos += 4;
								u32 bv_blur_y_raw; memcpy(&bv_blur_y_raw, cur_pos, 4); cur_pos += 4;
								u32 bv_angle_raw; memcpy(&bv_angle_raw, cur_pos, 4); cur_pos += 4;
								u32 bv_dist_raw; memcpy(&bv_dist_raw, cur_pos, 4); cur_pos += 4;
								u16 bv_strength_raw; memcpy(&bv_strength_raw, cur_pos, 2); cur_pos += 2;
								u8 bv_flags_byte = *(u8*)cur_pos; cur_pos += 1;
								if (parsed_filter_type == 0) {
									parsed_filter_type = 4; // bevel
									parsed_filter_r = bv_sr / 255.0;
									parsed_filter_g = bv_sg / 255.0;
									parsed_filter_b = bv_sb / 255.0;
									parsed_filter_a = bv_sa / 255.0;
									parsed_highlight_r = bv_hr / 255.0;
									parsed_highlight_g = bv_hg / 255.0;
									parsed_highlight_b = bv_hb / 255.0;
									parsed_highlight_a = bv_ha / 255.0;
									parsed_blur_x = (double)(s32)bv_blur_x_raw / 65536.0;
									parsed_blur_y = (double)(s32)bv_blur_y_raw / 65536.0;
									parsed_filter_angle = (double)(s32)bv_angle_raw / 65536.0;
									parsed_filter_distance = (double)(s32)bv_dist_raw / 65536.0;
									parsed_filter_strength = (double)bv_strength_raw / 256.0;
									parsed_filter_quality = bv_flags_byte & 0x0F;  // bits 0-3
									if (parsed_filter_quality == 0) parsed_filter_quality = 1;
									parsed_filter_flags = (bv_flags_byte >> 4) & 0x0F;  // bits 4-7
								}
								if (all_filter_count < 16) {
									auto& cf = all_filters[all_filter_count++];
									memset(&cf, 0, sizeof(cf));
									cf.type = 4; // Bevel
									cf.r = bv_sr / 255.0; cf.g = bv_sg / 255.0; cf.b = bv_sb / 255.0; cf.a = bv_sa / 255.0;
									cf.hr = bv_hr / 255.0; cf.hg = bv_hg / 255.0; cf.hb = bv_hb / 255.0; cf.ha = bv_ha / 255.0;
									cf.blur_x = (double)(s32)bv_blur_x_raw / 65536.0;
									cf.blur_y = (double)(s32)bv_blur_y_raw / 65536.0;
									cf.angle = (double)(s32)bv_angle_raw / 65536.0;
									cf.distance = (double)(s32)bv_dist_raw / 65536.0;
									cf.strength = (double)bv_strength_raw / 256.0;
									cf.quality = bv_flags_byte & 0x0F;
									if (cf.quality == 0) cf.quality = 1;
									cf.flags = (bv_flags_byte >> 4) & 0x0F;
								}
								break;
							}
							case 4: // GradientGlowFilter
							{
								u8 nc = *(u8*) cur_pos; cur_pos += 1;
								// Colors: RGBA[nc] then Ratios: UI8[nc]
								u8* color_start = (u8*)cur_pos;
								u8 last_r = 0, last_g = 0, last_b = 0, last_a = 255;
								for (u8 ci = 0; ci < nc; ci++) {
									last_r = *(u8*)(cur_pos + ci*4);
									last_g = *(u8*)(cur_pos + ci*4 + 1);
									last_b = *(u8*)(cur_pos + ci*4 + 2);
									last_a = *(u8*)(cur_pos + ci*4 + 3);
								}
								cur_pos += nc * 4; // colors
								u8* ratio_start = (u8*)cur_pos;
								cur_pos += nc;     // ratios
								u32 gg_bx; memcpy(&gg_bx, cur_pos, 4); cur_pos += 4;
								u32 gg_by; memcpy(&gg_by, cur_pos, 4); cur_pos += 4;
								u32 gg_ang; memcpy(&gg_ang, cur_pos, 4); cur_pos += 4;
								u32 gg_dist; memcpy(&gg_dist, cur_pos, 4); cur_pos += 4;
								u16 gg_str; memcpy(&gg_str, cur_pos, 2); cur_pos += 2;
								u8 gg_fl = *(u8*)cur_pos; cur_pos += 1;
								if (parsed_filter_type == 0) {
									parsed_filter_type = 3; // approximate as glow for rendering
									parsed_filter_r = last_r / 255.0;
									parsed_filter_g = last_g / 255.0;
									parsed_filter_b = last_b / 255.0;
									parsed_filter_a = last_a / 255.0;
									parsed_blur_x = (float)(s32)gg_bx / 65536.0f;
									parsed_blur_y = (float)(s32)gg_by / 65536.0f;
									parsed_filter_angle = (float)(s32)gg_ang / 65536.0f;
									parsed_filter_distance = (float)(s32)gg_dist / 65536.0f;
									parsed_filter_strength = (float)gg_str / 256.0f;
									// GradientGlow/Bevel flags: InnerShadow(7) Knockout(6) CompositeSource(5) OnTop(4) Passes(3-0)
									parsed_filter_quality = gg_fl & 0x0F;
									if (parsed_filter_quality == 0) parsed_filter_quality = 1;
									// Pack inner/knockout/onTop into 3-bit flags for ext filter data
									u8 inner = (gg_fl >> 7) & 1;
									u8 knockout = (gg_fl >> 6) & 1;
									u8 on_top = (gg_fl >> 4) & 1;
									parsed_filter_flags = (inner << 2) | (knockout << 1) | on_top;
									// Store full gradient data for mc.filters
									ext_filter_type = 7; // GradientGlow
									ext_grad_count = nc < 16 ? nc : 16;
									for (u8 ci = 0; ci < ext_grad_count; ci++) {
										u8 cr = color_start[ci*4], cg = color_start[ci*4+1];
										u8 cb = color_start[ci*4+2], ca = color_start[ci*4+3];
										ext_grad_colors[ci] = ((u32)cr << 16) | ((u32)cg << 8) | cb;
										ext_grad_alphas[ci] = ca / 255.0f;
										ext_grad_ratios[ci] = ratio_start[ci];
									}
								}
								if (all_filter_count < 16) {
									auto& cf = all_filters[all_filter_count++];
									memset(&cf, 0, sizeof(cf));
									cf.type = 7; // GradientGlow
									cf.blur_x = (double)(s32)gg_bx / 65536.0;
									cf.blur_y = (double)(s32)gg_by / 65536.0;
									cf.angle = (double)(s32)gg_ang / 65536.0;
									cf.distance = (double)(s32)gg_dist / 65536.0;
									cf.strength = (double)gg_str / 256.0;
									cf.quality = gg_fl & 0x0F;
									if (cf.quality == 0) cf.quality = 1;
									u8 gg_inner = (gg_fl >> 7) & 1;
									u8 gg_knockout = (gg_fl >> 6) & 1;
									u8 gg_on_top = (gg_fl >> 4) & 1;
									cf.flags = (gg_inner << 2) | (gg_knockout << 1) | gg_on_top;
									cf.grad_count = nc < 16 ? nc : 16;
									for (u8 ci = 0; ci < cf.grad_count; ci++) {
										u8 cr = color_start[ci*4], cg = color_start[ci*4+1];
										u8 cb = color_start[ci*4+2], ca = color_start[ci*4+3];
										cf.grad_colors[ci] = ((u32)cr << 16) | ((u32)cg << 8) | cb;
										cf.grad_alphas[ci] = ca / 255.0f;
										cf.grad_ratios[ci] = ratio_start[ci];
									}
								}
								break;
							}
							case 5: // ConvolutionFilter
							{
								u8 mx = *(u8*) cur_pos; cur_pos += 1;
								u8 my = *(u8*) cur_pos; cur_pos += 1;
								float cv_divisor; memcpy(&cv_divisor, cur_pos, 4); cur_pos += 4;
								float cv_bias; memcpy(&cv_bias, cur_pos, 4); cur_pos += 4;
								u8* matrix_start = (u8*)cur_pos;
								int matrix_count = mx * my;
								cur_pos += matrix_count * 4; // matrix FLOAT[mx*my]
								u8 cv_def_r = *(u8*)cur_pos; u8 cv_def_g = *(u8*)(cur_pos+1);
								u8 cv_def_b = *(u8*)(cur_pos+2); u8 cv_def_a = *(u8*)(cur_pos+3);
								cur_pos += 4; // default color RGBA
								u8 cv_fl = *(u8*)cur_pos; cur_pos += 1;
								if (parsed_filter_type == 0) {
									parsed_filter_type = 1; // approximate as blur for rendering
									parsed_blur_x = (float)mx;
									parsed_blur_y = (float)my;
									parsed_filter_quality = 1;
									parsed_filter_strength = 1.0f;
									// Store full convolution data for mc.filters
									ext_filter_type = 5; // Convolution
									ext_conv_mx = mx;
									ext_conv_my = my;
									ext_conv_divisor = cv_divisor;
									ext_conv_bias = cv_bias;
									int n = matrix_count < 25 ? matrix_count : 25;
									for (int ci = 0; ci < n; ci++)
										memcpy(&ext_conv_matrix[ci], matrix_start + ci*4, 4);
									ext_conv_clamp = (cv_fl >> 1) & 1;
									ext_conv_preserve_alpha = cv_fl & 1;
									ext_conv_color_r = cv_def_r;
									ext_conv_color_g = cv_def_g;
									ext_conv_color_b = cv_def_b;
									ext_conv_color_a = cv_def_a;
								}
								if (all_filter_count < 16) {
									auto& cf = all_filters[all_filter_count++];
									memset(&cf, 0, sizeof(cf));
									cf.type = 5; // Convolution
									cf.conv_mx = mx; cf.conv_my = my;
									cf.conv_divisor = cv_divisor; cf.conv_bias = cv_bias;
									int cn = matrix_count < 25 ? matrix_count : 25;
									for (int ci = 0; ci < cn; ci++)
										memcpy(&cf.conv_matrix[ci], matrix_start + ci*4, 4);
									cf.conv_clamp = (cv_fl >> 1) & 1;
									cf.conv_preserve_alpha = cv_fl & 1;
									cf.conv_color_r = cv_def_r; cf.conv_color_g = cv_def_g;
									cf.conv_color_b = cv_def_b; cf.conv_color_a = cv_def_a;
								}
								break;
							}
							case 6: // ColorMatrixFilter — 20 FLOAT values (80 bytes)
							{
								// Read 20 floats (row-major 4x5: rows=R,G,B,A, cols=R,G,B,A,bias)
								float cm[20];
								memcpy(cm, cur_pos, 80);
								cur_pos += 80;

								// Store raw matrix for mc.filters getter
								if (ext_filter_type == 0) {
									ext_filter_type = 6; // ColorMatrix
									memcpy(ext_cm_matrix, cm, 80);
								}

								// Convert to our cxform format:
								// 4x4 column-major multiply matrix + 4 additive values
								// SWF ColorMatrix row i: [mult_R, mult_G, mult_B, mult_A, bias]
								// Our cxform is stored as 20 floats: 4x4 column-major + 4 additive
								has_color_matrix = true;
								color_matrix_cxform_id = (u32) current_cxform;

								// Column-major: col j, row i = cm[i*5 + j]
								// Col 0 (R mult): cm[0], cm[5], cm[10], cm[15]
								cxform_data << std::fixed
											<< "\t" << cm[0] << "f," << endl
											<< "\t" << cm[5] << "f," << endl
											<< "\t" << cm[10] << "f," << endl
											<< "\t" << cm[15] << "f," << endl;
								// Col 1 (G mult): cm[1], cm[6], cm[11], cm[16]
								cxform_data << "\t" << cm[1] << "f," << endl
											<< "\t" << cm[6] << "f," << endl
											<< "\t" << cm[11] << "f," << endl
											<< "\t" << cm[16] << "f," << endl;
								// Col 2 (B mult): cm[2], cm[7], cm[12], cm[17]
								cxform_data << "\t" << cm[2] << "f," << endl
											<< "\t" << cm[7] << "f," << endl
											<< "\t" << cm[12] << "f," << endl
											<< "\t" << cm[17] << "f," << endl;
								// Col 3 (A mult): cm[3], cm[8], cm[13], cm[18]
								cxform_data << "\t" << cm[3] << "f," << endl
											<< "\t" << cm[8] << "f," << endl
											<< "\t" << cm[13] << "f," << endl
											<< "\t" << cm[18] << "f," << endl;
								// Additive (RGBA bias / 255): cm[4], cm[9], cm[14], cm[19]
								cxform_data << "\t" << cm[4] << "f/255.0f," << endl
											<< "\t" << cm[9] << "f/255.0f," << endl
											<< "\t" << cm[14] << "f/255.0f," << endl
											<< "\t" << cm[19] << "f/255.0f," << endl
											<< std::defaultfloat;

								current_cxform += 1;
								if (all_filter_count < 16) {
									auto& cf = all_filters[all_filter_count++];
									memset(&cf, 0, sizeof(cf));
									cf.type = 6; // ColorMatrix
									memcpy(cf.cm_matrix, cm, 80);
								}
								break;
							}
							case 7: // GradientBevelFilter
							{
								u8 nc = *(u8*) cur_pos; cur_pos += 1;
								// Colors: RGBA[nc] then Ratios: UI8[nc]
								u8* color_start = (u8*)cur_pos;
								// Use first non-transparent color as shadow, last as highlight
								u8 gb_sr = 0, gb_sg = 0, gb_sb = 0, gb_sa = 255;
								u8 gb_hr = 255, gb_hg = 255, gb_hb = 255, gb_ha = 255;
								if (nc >= 2) {
									gb_sr = *(u8*)(cur_pos); gb_sg = *(u8*)(cur_pos+1);
									gb_sb = *(u8*)(cur_pos+2); gb_sa = *(u8*)(cur_pos+3);
									u8 li = nc - 1;
									gb_hr = *(u8*)(cur_pos + li*4); gb_hg = *(u8*)(cur_pos + li*4+1);
									gb_hb = *(u8*)(cur_pos + li*4+2); gb_ha = *(u8*)(cur_pos + li*4+3);
								} else if (nc == 1) {
									gb_sr = *(u8*)cur_pos; gb_sg = *(u8*)(cur_pos+1);
									gb_sb = *(u8*)(cur_pos+2); gb_sa = *(u8*)(cur_pos+3);
								}
								cur_pos += nc * 4; // colors
								u8* ratio_start = (u8*)cur_pos;
								cur_pos += nc;     // ratios
								u32 gb_bx; memcpy(&gb_bx, cur_pos, 4); cur_pos += 4;
								u32 gb_by; memcpy(&gb_by, cur_pos, 4); cur_pos += 4;
								u32 gb_ang; memcpy(&gb_ang, cur_pos, 4); cur_pos += 4;
								u32 gb_dist; memcpy(&gb_dist, cur_pos, 4); cur_pos += 4;
								u16 gb_str; memcpy(&gb_str, cur_pos, 2); cur_pos += 2;
								u8 gb_fl = *(u8*)cur_pos; cur_pos += 1;
								if (parsed_filter_type == 0) {
									parsed_filter_type = 4; // approximate as bevel for rendering
									parsed_filter_r = gb_sr / 255.0;
									parsed_filter_g = gb_sg / 255.0;
									parsed_filter_b = gb_sb / 255.0;
									parsed_filter_a = gb_sa / 255.0;
									parsed_highlight_r = gb_hr / 255.0;
									parsed_highlight_g = gb_hg / 255.0;
									parsed_highlight_b = gb_hb / 255.0;
									parsed_highlight_a = gb_ha / 255.0;
									parsed_blur_x = (float)(s32)gb_bx / 65536.0f;
									parsed_blur_y = (float)(s32)gb_by / 65536.0f;
									parsed_filter_angle = (float)(s32)gb_ang / 65536.0f;
									parsed_filter_distance = (float)(s32)gb_dist / 65536.0f;
									parsed_filter_strength = (float)gb_str / 256.0f;
									// GradientBevel flags: InnerShadow(7) Knockout(6) CompositeSource(5) OnTop(4) Passes(3-0)
									parsed_filter_quality = gb_fl & 0x0F;
									if (parsed_filter_quality == 0) parsed_filter_quality = 1;
									u8 gb_inner = (gb_fl >> 7) & 1;
									u8 gb_knockout = (gb_fl >> 6) & 1;
									u8 gb_on_top = (gb_fl >> 4) & 1;
									parsed_filter_flags = (gb_inner << 2) | (gb_knockout << 1) | gb_on_top;
									// Store full gradient data for mc.filters
									ext_filter_type = 8; // GradientBevel
									ext_grad_count = nc < 16 ? nc : 16;
									for (u8 ci = 0; ci < ext_grad_count; ci++) {
										u8 cr = color_start[ci*4], cg = color_start[ci*4+1];
										u8 cb = color_start[ci*4+2], ca = color_start[ci*4+3];
										ext_grad_colors[ci] = ((u32)cr << 16) | ((u32)cg << 8) | cb;
										ext_grad_alphas[ci] = ca / 255.0f;
										ext_grad_ratios[ci] = ratio_start[ci];
									}
								}
								if (all_filter_count < 16) {
									auto& cf = all_filters[all_filter_count++];
									memset(&cf, 0, sizeof(cf));
									cf.type = 8; // GradientBevel
									cf.blur_x = (double)(s32)gb_bx / 65536.0;
									cf.blur_y = (double)(s32)gb_by / 65536.0;
									cf.angle = (double)(s32)gb_ang / 65536.0;
									cf.distance = (double)(s32)gb_dist / 65536.0;
									cf.strength = (double)gb_str / 256.0;
									cf.quality = gb_fl & 0x0F;
									if (cf.quality == 0) cf.quality = 1;
									u8 gbi = (gb_fl >> 7) & 1;
									u8 gbk = (gb_fl >> 6) & 1;
									u8 gbt = (gb_fl >> 4) & 1;
									cf.flags = (gbi << 2) | (gbk << 1) | gbt;
									cf.grad_count = nc < 16 ? nc : 16;
									for (u8 ci = 0; ci < cf.grad_count; ci++) {
										u8 cr = color_start[ci*4], cg = color_start[ci*4+1];
										u8 cb = color_start[ci*4+2], ca = color_start[ci*4+3];
										cf.grad_colors[ci] = ((u32)cr << 16) | ((u32)cg << 8) | cb;
										cf.grad_alphas[ci] = ca / 255.0f;
										cf.grad_ratios[ci] = ratio_start[ci];
									}
								}
								break;
							}
						}
					}
				}

				if (is_po3 && has_blend_mode)
				{
					blend_mode_val = *(u8*) cur_pos; cur_pos += 1;
				}

				if (is_po3 && has_cache_as_bitmap)
				{
					cur_pos += 1; // skip BitmapCache UI8
				}

				if (is_po3 && has_visible)
				{
					cur_pos += 1; // skip Visible UI8
				}

				if (is_po3 && has_opaque_background)
				{
					cur_pos += 4; // skip BackgroundColor RGBA
				}

				// If ColorMatrixFilter provided a cxform, use it (compose with existing if any)
				if (has_color_matrix)
				{
					cxform_id = color_matrix_cxform_id;
				}

				// Parse clip actions if present
				std::string clip_actions_var;
				size_t clip_action_count = 0;

				if (has_clip_actions)
				{
					// CLIPACTIONS: Reserved(UI16), AllEventFlags(UI16 or UI32)
					tag.clearFields();
					tag.setFieldCount(1);
					tag.configureNextField(SWF_FIELD_UI16);
					tag.parseFields(cur_pos);
					// Reserved = 0, ignore

					u32 all_event_flags;
					if (header.version >= 6)
					{
						tag.clearFields();
						tag.setFieldCount(1);
						tag.configureNextField(SWF_FIELD_UI32, 32);
						tag.parseFields(cur_pos);
						all_event_flags = (u32) tag.fields[0].value;
					}
					else
					{
						tag.clearFields();
						tag.setFieldCount(1);
						tag.configureNextField(SWF_FIELD_UI16);
						tag.parseFields(cur_pos);
						all_event_flags = (u32)(u16) tag.fields[0].value;
					}

					// Parse CLIPACTIONRECORD entries
					struct ClipActionEntry { u32 event_flags; std::string func_name; };
					std::vector<ClipActionEntry> clip_entries;

					size_t clip_action_iter = 0;
					while (all_event_flags != 0)
					{
						if (++clip_action_iter > 1000)
						{
							fprintf(stderr, "Warning: clip action parsing exceeded 1000 entries, skipping rest\n");
							break;
						}

						// EventFlags (UI16 or UI32)
						u32 event_flags;
						if (header.version >= 6)
						{
							tag.clearFields();
							tag.setFieldCount(1);
							tag.configureNextField(SWF_FIELD_UI32, 32);
							tag.parseFields(cur_pos);
							event_flags = (u32) tag.fields[0].value;
						}
						else
						{
							tag.clearFields();
							tag.setFieldCount(1);
							tag.configureNextField(SWF_FIELD_UI16);
							tag.parseFields(cur_pos);
							event_flags = (u32)(u16) tag.fields[0].value;
						}

						if (event_flags == 0)
							break; // ClipActionEndFlag

						// ActionRecordSize (UI32)
						tag.clearFields();
						tag.setFieldCount(1);
						tag.configureNextField(SWF_FIELD_UI32, 32);
						tag.parseFields(cur_pos);
						u32 action_size = (u32) tag.fields[0].value;

						// Optional KeyCode (UI8) if ClipEventKeyPress is set
						if (event_flags & 0x20000) // ClipEventKeyPress
						{
							cur_pos += 1; // skip KeyCode
							action_size -= 1;
						}

						// Generate script function for this clip action
						std::string func_name = "clip_action_" + to_string(next_script_i);
						context.out_script_header << endl << "void " << func_name << "(SWFAppContext* app_context);";

						ofstream out_script(context.output_scripts_folder + "script_" + to_string(next_script_i) + ".c", ios_base::out);
						out_script << "#include <recomp.h>" << endl
								   << "#include <setjmp.h>" << endl
								   << "#include \"script_decls.h\"" << endl << endl
								   << "void " << func_name << "(SWFAppContext* app_context)" << endl
								   << "{" << endl;
						out_script << "\t" << "char str_buffer[17];" << endl << endl;
						out_script << "\t" << "actionResetRegisters();" << endl << endl;
						next_script_i += 1;

						action.parseActions(context, cur_pos, out_script);
						out_script << "}";

						clip_entries.push_back({ event_flags, func_name });
					}

					if (!clip_entries.empty())
					{
						clip_actions_var = "clip_actions_" + to_string(num_finished_tags);

						sprite_forward_decls << "extern ClipAction " << clip_actions_var << "[];" << endl;
						sprite_definitions << "ClipAction " << clip_actions_var << "[] =" << endl
										   << "{" << endl;
						for (auto& ca : clip_entries)
						{
							sprite_definitions << "\t" << "{ 0x" << std::hex << ca.event_flags << std::dec
											   << ", " << ca.func_name << " }," << endl;
						}
						sprite_definitions << "};" << endl << endl;

						clip_action_count = clip_entries.size();
					}
				}

				// Check for buffered RemoveObject2 at this depth (remove+replace pattern).
				// If the old placement had clip_actions and the new one also has clip_actions,
				// emit tagReplaceObject2RatioWithClipActions to accumulate old clip actions
				// instead of firing them prematurely.
				bool is_replace = false;
				std::string old_ca_var;
				size_t old_ca_count = 0;
				if (buffered_removes.count((u16)depth) && depth_clip_actions.count((u16)depth))
				{
					old_ca_var = depth_clip_actions[(u16)depth].var_name;
					old_ca_count = depth_clip_actions[(u16)depth].count;
					buffered_removes.erase((u16)depth);
					depth_clip_actions.erase((u16)depth);
					is_replace = true;
				}
				else if (buffered_removes.count((u16)depth))
				{
					// Depth was removed but had no old clip_actions — flush the remove
					context.tag_main << "\t" << "tagRemoveObject2(app_context, " << to_string(depth) << ");" << endl;
					buffered_removes.erase((u16)depth);
				}

				// Emit instance name BEFORE placement so g_pending_instance_name prevents
				// auto-naming and counter increment. For clip-action cases, the name is
				// already emitted before placement below (guarded by clip_action_count > 0).
				// Use `has_name` so an explicit empty name ("") is still propagated — Ming's
				// instanceNameTest distinguishes `setName("")` (target "/") from "no name"
				// (auto-named "/instanceN").
				if (has_name && clip_action_count == 0)
				{
					std::string escaped_name = "";
					for (char c : instance_name_str) {
						if (c == '"' || c == '\\') escaped_name += '\\';
						escaped_name += c;
					}
					context.tag_main << "\t" << "tagSetInstanceName(app_context, " << to_string(depth) << ", \"" << escaped_name << "\");" << endl;
				}

				// Emit the place call
				if (blend_mode_val > 1)
				{
					context.tag_main << "\t" << "tagPlaceObject3(app_context, " << to_string(depth) << ", " << to_string(char_id) << ", " << to_string(transform_id) << ", " << to_string(cxform_id) << ", " << to_string(clip_depth_val) << ", " << to_string(blend_mode_val) << ");" << endl;
				}
				else if (is_replace && clip_action_count > 0)
				{
					// Remove+replace at same depth with clip_actions on both old and new.
					// Emit tagReplaceObject2RatioWithClipActions to accumulate old clip
					// actions instead of firing them during the remove.
					if (has_name)
					{
						std::string escaped_name = "";
						for (char c : instance_name_str) {
							if (c == '"' || c == '\\') escaped_name += '\\';
							escaped_name += c;
						}
						context.tag_main << "\t" << "tagSetInstanceName(app_context, " << to_string(depth) << ", \"" << escaped_name << "\");" << endl;
					}
					context.tag_main << "\t" << "tagReplaceObject2RatioWithClipActions(app_context, "
						<< to_string(depth) << ", " << to_string(char_id) << ", "
						<< to_string(transform_id) << ", " << to_string(cxform_id) << ", "
						<< to_string(clip_depth_val) << ", " << to_string(ratio_val) << ", "
						<< old_ca_var << ", " << to_string(old_ca_count) << ", "
						<< clip_actions_var << ", " << to_string(clip_action_count) << ");" << endl;
				}
				else if (has_ratio && clip_action_count > 0)
				{
					// When clip actions are present, emit instance name BEFORE placement
					if (has_name)
					{
						std::string escaped_name = "";
						for (char c : instance_name_str) {
							if (c == '"' || c == '\\') escaped_name += '\\';
							escaped_name += c;
						}
						context.tag_main << "\t" << "tagSetInstanceName(app_context, " << to_string(depth) << ", \"" << escaped_name << "\");" << endl;
					}
					context.tag_main << "\t" << "tagPlaceObject2RatioWithClipActions(app_context, " << to_string(depth) << ", " << to_string(char_id) << ", " << to_string(transform_id) << ", " << to_string(cxform_id) << ", " << to_string(clip_depth_val) << ", " << to_string(ratio_val) << ", " << clip_actions_var << ", " << to_string(clip_action_count) << ");" << endl;
				}
				else if (has_ratio)
				{
					context.tag_main << "\t" << "tagPlaceObject2Ratio(app_context, " << to_string(depth) << ", " << to_string(char_id) << ", " << to_string(transform_id) << ", " << to_string(cxform_id) << ", " << to_string(clip_depth_val) << ", " << to_string(ratio_val) << ");" << endl;
					// Also attach clip actions if both ratio and clip actions are present
					if (clip_action_count > 0)
					{
						context.tag_main << "\t" << "tagSetClipActions(app_context, " << to_string(depth) << ", " << clip_actions_var << ", " << to_string(clip_action_count) << ");" << endl;
					}
				}
				else if (clip_action_count > 0)
				{
					// When clip actions are present, emit instance name BEFORE placement
					// so CLIP_EVENT_CONSTRUCT fires with the correct name (not auto "instanceN").
					if (has_name)
					{
						std::string escaped_name = "";
						for (char c : instance_name_str) {
							if (c == '"' || c == '\\') escaped_name += '\\';
							escaped_name += c;
						}
						context.tag_main << "\t" << "tagSetInstanceName(app_context, " << to_string(depth) << ", \"" << escaped_name << "\");" << endl;
					}
					context.tag_main << "\t" << "tagPlaceObject2WithClipActions(app_context, " << to_string(depth) << ", " << to_string(char_id) << ", " << to_string(transform_id) << ", " << to_string(cxform_id) << ", " << to_string(clip_depth_val) << ", " << clip_actions_var << ", " << to_string(clip_action_count) << ");" << endl;
				}
				else
				{
					context.tag_main << "\t" << "tagPlaceObject2(app_context, " << to_string(depth) << ", " << to_string(char_id) << ", " << to_string(transform_id) << ", " << to_string(cxform_id) << ", " << to_string(clip_depth_val) << ");" << endl;
				}

				// Track clip_actions per depth for future remove+replace detection
				if (clip_action_count > 0)
				{
					depth_clip_actions[(u16)depth] = { clip_actions_var, clip_action_count };
				}
				else
				{
					depth_clip_actions.erase((u16)depth);
				}

				// Instance name already emitted before the placement call above.

				// Emit filter if parsed
				if (parsed_filter_type != 0)
				{
					context.tag_main << std::setprecision(15)
						<< "\t" << "tagSetFilter(app_context, " << to_string(depth) << ", "
						<< to_string(parsed_filter_type) << ", "
						<< parsed_blur_x << ", "
						<< parsed_blur_y << ", "
						<< to_string(parsed_filter_quality) << ", "
						<< to_string(parsed_filter_flags) << ", "
						<< parsed_filter_r << ", "
						<< parsed_filter_g << ", "
						<< parsed_filter_b << ", "
						<< parsed_filter_a << ", "
						<< parsed_filter_strength << ", "
						<< parsed_filter_angle << ", "
						<< parsed_filter_distance << ");"
						<< std::defaultfloat << endl;

					// Emit highlight color for bevel filters
					if (parsed_filter_type == 4)
					{
						context.tag_main << std::setprecision(15)
							<< "\t" << "tagSetFilterHighlight(app_context, " << to_string(depth) << ", "
							<< parsed_highlight_r << ", "
							<< parsed_highlight_g << ", "
							<< parsed_highlight_b << ", "
							<< parsed_highlight_a << ");"
							<< std::defaultfloat << endl;
					}
				}

				// Emit multi-filter list for mc.filters getter
				if (all_filter_count > 0)
				{
					// Helper: format float as C literal with guaranteed decimal point + "f" suffix
					auto flit = [](float v) -> std::string {
						std::ostringstream oss;
						oss << std::setprecision(9) << v;
						std::string s = oss.str();
						if (s.find('.') == std::string::npos && s.find('e') == std::string::npos)
							s += ".0";
						s += "f";
						return s;
					};

					context.tag_main << "\ttagBeginFilterList(app_context, "
						<< to_string(depth) << ", " << to_string(all_filter_count) << ");" << endl;

					for (u8 fi = 0; fi < all_filter_count; fi++)
					{
						auto& cf = all_filters[fi];
						if (cf.type >= 1 && cf.type <= 4) {
							// Simple filter
							context.tag_main << std::setprecision(15)
								<< "\ttagAddSimpleFilter(app_context, " << to_string(depth) << ", "
								<< to_string(cf.type) << ", "
								<< cf.blur_x << ", " << cf.blur_y << ", "
								<< to_string(cf.quality) << ", " << to_string(cf.flags) << ", "
								<< cf.r << ", " << cf.g << ", " << cf.b << ", " << cf.a << ", "
								<< cf.strength << ", " << cf.angle << ", " << cf.distance << ");"
								<< std::defaultfloat << endl;
							if (cf.type == 4) {
								context.tag_main << std::setprecision(15)
									<< "\ttagAddSimpleFilterHighlight(app_context, " << to_string(depth) << ", "
									<< cf.hr << ", " << cf.hg << ", " << cf.hb << ", " << cf.ha << ");"
									<< std::defaultfloat << endl;
							}
						}
						else if (cf.type == 6) {
							// ColorMatrixFilter
							context.tag_main << "\t{ float _cm[] = {";
							for (int i = 0; i < 20; i++) {
								if (i > 0) context.tag_main << ",";
								context.tag_main << flit(cf.cm_matrix[i]);
							}
							context.tag_main << "}; tagAddColorMatrixFilter(app_context, "
								<< to_string(depth) << ", _cm); }" << endl;
						}
						else if (cf.type == 5) {
							// ConvolutionFilter
							int n = cf.conv_mx * cf.conv_my;
							if (n > 25) n = 25;
							context.tag_main << "\t{ float _m[] = {";
							for (int i = 0; i < n; i++) {
								if (i > 0) context.tag_main << ",";
								context.tag_main << flit(cf.conv_matrix[i]);
							}
							context.tag_main << "}; tagAddConvolutionFilter(app_context, "
								<< to_string(depth) << ", "
								<< to_string(cf.conv_mx) << ", " << to_string(cf.conv_my) << ", _m, "
								<< flit(cf.conv_divisor) << ", " << flit(cf.conv_bias) << ", "
								<< to_string(cf.conv_preserve_alpha) << ", " << to_string(cf.conv_clamp) << ", "
								<< to_string(cf.conv_color_r) << ", " << to_string(cf.conv_color_g) << ", "
								<< to_string(cf.conv_color_b) << ", " << to_string(cf.conv_color_a) << "); }" << endl;
						}
						else if (cf.type == 7 || cf.type == 8) {
							// GradientGlow/GradientBevel
							context.tag_main << "\t{ u32 _c[] = {";
							for (int i = 0; i < cf.grad_count; i++) {
								if (i > 0) context.tag_main << ",";
								context.tag_main << cf.grad_colors[i];
							}
							context.tag_main << "}; float _a[] = {";
							for (int i = 0; i < cf.grad_count; i++) {
								if (i > 0) context.tag_main << ",";
								context.tag_main << flit(cf.grad_alphas[i]);
							}
							context.tag_main << "}; u8 _r[] = {";
							for (int i = 0; i < cf.grad_count; i++) {
								if (i > 0) context.tag_main << ",";
								context.tag_main << to_string(cf.grad_ratios[i]);
							}
							context.tag_main << "}; tagAddGradientFilter(app_context, "
								<< to_string(depth) << ", "
								<< to_string(cf.type) << ", "
								<< to_string(cf.grad_count) << ", _c, _a, _r, "
								<< flit((float)cf.blur_x) << ", " << flit((float)cf.blur_y) << ", "
								<< flit((float)cf.angle) << ", " << flit((float)cf.distance) << ", "
								<< flit((float)cf.strength) << ", "
								<< to_string(cf.quality) << ", " << to_string(cf.flags) << "); }" << endl;
						}
					}

					context.tag_main << "\ttagEndFilterList(app_context, " << to_string(depth) << ");" << endl;
				}

				break;
			}

			case SWF_TAG_REMOVE_OBJECT:
			{
				tag.setFieldCount(2);
				tag.configureNextField(SWF_FIELD_UI16);
				tag.configureNextField(SWF_FIELD_UI16);
				tag.parseFields(cur_pos);

				u16 char_id = (u16) tag.fields[0].value;
				u16 depth = (u16) tag.fields[1].value;

				context.tag_main << "\t" << "tagRemoveObject(app_context, " << to_string(depth) << ");" << endl;

				break;
			}

			case SWF_TAG_REMOVE_OBJECT_2:
			{
				tag.setFieldCount(1);
				tag.configureNextField(SWF_FIELD_UI16);
				tag.parseFields(cur_pos);

				u16 depth = (u16) tag.fields[0].value;

				// If this depth had clip_actions from a prior placement AND the
				// next tag is a same-depth PlaceObject2 (replace pattern), buffer
				// so tagReplaceObject2RatioWithClipActions can accumulate old
				// clip actions. Otherwise emit inline so the runtime queues the
				// UNLOAD at the correct tag-stream position (drain in queue-time
				// FIFO order matches Flash's ActionQueue model — DEFERRED_CLIP_UNLOAD_PLAN).
				bool should_buffer = false;
				if (depth_clip_actions.count(depth)) {
					// Peek next tag header. After parseFields, cur_pos points to the next
					// tag's header start (assuming this tag had no extra bytes — UI16 fields).
					char* peek_pos = cur_pos;
					u16 next_code_and_len = *((u16*)peek_pos);
					TagType next_code = (TagType)((next_code_and_len >> 6) & 0x3FF);
					if (next_code == SWF_TAG_PLACE_OBJECT_2 || next_code == SWF_TAG_PLACE_OBJECT_3) {
						u32 next_len_short = next_code_and_len & 0b111111;
						char* next_data = peek_pos + 2;
						if (next_len_short == 0x3F) {
							next_data += 4;
						}
						// PlaceObject2/3: 1 byte flags, then 2 bytes depth (LE).
						// Read just to compare depth — no broader parsing.
						u16 next_depth = *((u16*)(next_data + 1));
						if (next_depth == depth) should_buffer = true;
					}
				}

				if (should_buffer) {
					buffered_removes.insert(depth);
				} else {
					context.tag_main << "\t" << "tagRemoveObject2(app_context, " << to_string(depth) << ");" << endl;
				}

				break;
			}

			case SWF_TAG_ENABLE_DEBUGGER:
			{
				cur_pos += tag.length;

				break;
			}

			case SWF_TAG_ENABLE_DEBUGGER_2:
			{
				cur_pos += tag.length;
				
				break;
			}
			
			case SWF_TAG_SCRIPT_LIMITS:
			{
				tag.setFieldCount(2);
				tag.configureNextField(SWF_FIELD_UI16);
				tag.configureNextField(SWF_FIELD_UI16);
				
				tag.parseFields(cur_pos);
				
				context.tag_main << "\t" << "tagScriptLimits("
								 << to_string((u16) tag.fields[0].value) << ", "
								 << to_string((u16) tag.fields[1].value) << ");" << endl;
				
				break;
			}
			
			case SWF_TAG_FILE_ATTRIBUTES:
			{
				tag.setFieldCount(4);
				
				tag.configureNextField(SWF_FIELD_UI8);
				tag.configureNextField(SWF_FIELD_UI8);
				tag.configureNextField(SWF_FIELD_UI8);
				tag.configureNextField(SWF_FIELD_UI8);
				
				tag.parseFields(cur_pos);
				
				u8 flags = (u8) tag.fields[0].value;

				if ((flags & 0b00001000) != 0)
				{
					//EXC("ActionScript 3 SWFs not implemented.\n");
				}

				// Bit 0: UseNetwork
				if ((flags & 0b00000001) != 0)
				{
					use_network = true;
				}

				break;
			}
			
			case SWF_TAG_SYMBOL_CLASS:
			{
				cur_pos += tag.length;
				
				break;
			}
			
			case SWF_TAG_METADATA:
			case SWF_TAG_DEBUG_ID:
			{
				cur_pos += tag.length;
				break;
			}

			case SWF_TAG_EXPORT_ASSETS:
			{
				// DoExportAssets: Count(UI16), then Count * [Tag(UI16) + Name(STRING)]
				char* export_start = cur_pos;
				u16 export_count = (u8)cur_pos[0] | ((u8)cur_pos[1] << 8);
				cur_pos += 2;
				for (u16 ei = 0; ei < export_count; ei++)
				{
					u16 export_char_id = (u8)cur_pos[0] | ((u8)cur_pos[1] << 8);
					cur_pos += 2;
					// Name is null-terminated string
					std::string export_name(cur_pos);
					cur_pos += export_name.length() + 1;  // +1 for null terminator
					// Emit registration call in tagInit
					tag_init << endl << "\ttagRegisterExport(app_context, \"" << export_name << "\", " << to_string(export_char_id) << ");";
				}
				break;
			}

			case SWF_TAG_IMPORT_ASSETS:
			case SWF_TAG_IMPORT_ASSETS_2:
			{
				// ImportAssets / ImportAssets2: imports symbols from another SWF.
				// At runtime, the imported SWF's init function (DoInitAction scripts)
				// must be executed in the current context, and the imported character
				// definitions must be remapped to the parent's char_ids.
				// Format: URL(string) + [reserved(2) for ImportAssets2] + Count(UI16) + entries
				char* import_start = cur_pos;
				std::string import_url(cur_pos);
				cur_pos += import_url.length() + 1;  // +1 for null terminator
				if (tag.code == SWF_TAG_IMPORT_ASSETS_2) {
					cur_pos += 2;  // Skip reserved bytes
				}
				u16 import_count = (u8)cur_pos[0] | ((u8)cur_pos[1] << 8);
				cur_pos += 2;
				// Collect import entries: (local_char_id, export_name)
				struct ImportEntry { u16 char_id; std::string name; };
				std::vector<ImportEntry> imports;
				for (int i = 0; i < import_count; i++) {
					u16 char_id = (u8)cur_pos[0] | ((u8)cur_pos[1] << 8);
					cur_pos += 2;
					std::string name(cur_pos);
					cur_pos += name.length() + 1;
					imports.push_back({char_id, name});

					// ImportAssets makes char_id available in the local
					// dictionary at runtime (via tagImportCharacter). Treat
					// it as a Define for place-before-define tracking so
					// later root PlaceObject* tags referencing the imported
					// char_id aren't degraded.
					defined_chars.insert(char_id);
				}
				// Buffer into the current-frame prologue so imports
				// resolve at the top of frame_N's body, in stream order
				// with DoInitAction (required by do_init_action_child).
				// Gated on (!catch_up_mode || g_tag_skip_mode); the
				// runtime side is responsible for idempotency under
				// script-only replay.
				current_frame_init_actions
					<< "\tif (!catch_up_mode || g_tag_skip_mode) "
					<< "actionImportAssets(app_context, \"" << import_url << "\");"
					<< endl;
				for (auto& imp : imports) {
					current_frame_init_actions
						<< "\tif (!catch_up_mode || g_tag_skip_mode) "
						<< "tagImportCharacter(app_context, "
						<< imp.char_id << ", \"" << imp.name << "\");"
						<< endl;
				}
				break;
			}

			case SWF_TAG_CSM_TEXT_SETTINGS:
			{
				// Parse CSMTextSettings: TextID(UI16), UseFlashType(UB[2]), GridFit(UB[3]), Reserved(UB[3]), Thickness(F32), Sharpness(F32), Reserved(UI8)
				char* csm_start = cur_pos;
				// TextID (UI16, little-endian)
				u16 csm_text_id = (u8)cur_pos[0] | ((u8)cur_pos[1] << 8);
				cur_pos += 2;
				// Read packed byte: UseFlashType(2 bits MSB) | GridFit(3 bits) | Reserved(3 bits LSB)
				u8 packed = (u8)*cur_pos;
				cur_pos += 1;
				int use_flash_type = (packed >> 6) & 0x03; // top 2 bits
				int grid_fit = (packed >> 3) & 0x07; // next 3 bits
				// Thickness (F32, little-endian)
				float thickness;
				memcpy(&thickness, cur_pos, 4);
				cur_pos += 4;
				// Sharpness (F32, little-endian)
				float sharpness;
				memcpy(&sharpness, cur_pos, 4);
				cur_pos += 4;

				const char* aat = (use_flash_type == 1) ? "advanced" : "normal";
				const char* gft = "none";
				if (grid_fit == 1) gft = "pixel";
				else if (grid_fit == 2) gft = "subpixel";

				// Emit runtime call
				tag_init << "\ttagCSMTextSettings(" << csm_text_id << ", \"" << aat << "\", \"" << gft << "\", ";
				tag_init << std::fixed << thickness << "f, " << std::fixed << sharpness << "f);\n";
				tag_init << std::defaultfloat;

				// Ensure cursor is at end
				cur_pos = csm_start + tag.length;
				break;
			}

			case SWF_TAG_DEFINE_FONT_ALIGN_ZONES:
			case SWF_TAG_DEFINE_FONT_NAME:
			case SWF_TAG_FREE_CHARACTER:
			{
				cur_pos += tag.length;

				break;
			}

			case SWF_TAG_VIDEO_FRAME:
			{
				// VideoFrame layout: StreamID (UI16) + FrameNum (UI16) +
				// raw codec payload (rest of tag). Bake payload bytes into
				// video_data[] and emit a tagVideoFrame call inline at this
				// tag's place in the surrounding frame function so the
				// runtime decoder sees frame N's payload as part of frame
				// N's timeline execution.
				if (tag.length < 4) {
					cur_pos += tag.length;
					break;
				}
				char* tmp = cur_pos;
				tag.clearFields();
				tag.setFieldCount(2);
				tag.configureNextField(SWF_FIELD_UI16); // StreamID
				tag.configureNextField(SWF_FIELD_UI16); // FrameNum
				tag.parseFields(tmp);

				u16 vf_stream_id = (u16) tag.fields[0].value;
				u16 vf_frame_num = (u16) tag.fields[1].value;

				size_t payload_size = tag.length - 4;
				size_t payload_offset = current_video_byte;
				const unsigned char* payload_bytes = (const unsigned char*)(cur_pos + 4);
				for (size_t i = 0; i < payload_size; ++i) {
					video_data << "\t0x" << std::hex << std::uppercase << std::setw(2) << std::setfill('0')
					           << (u32)payload_bytes[i] << "," << std::dec << endl;
				}
				current_video_byte += payload_size;

				context.tag_main << "\t" << "tagVideoFrame(app_context, "
				                 << to_string(vf_stream_id) << ", "
				                 << to_string(vf_frame_num) << ", "
				                 << "video_data + " << to_string(payload_offset) << ", "
				                 << to_string(payload_size) << ");" << endl;

				cur_pos += tag.length;
				break;
			}

			case SWF_TAG_DEFINE_VIDEO_STREAM:
			{
				// DefineVideoStream layout: CharacterID (UI16), NumFrames (UI16),
				// Width (UI16, pixels), Height (UI16, pixels), then a flags byte
				// (4 bits reserved + 3 bits deblocking + 1 bit smoothing), then
				// CodecID (UI8). Codec id is mandatory for the runtime to pick
				// the right decoder for VideoFrame payloads.
				if (tag.length < 10) {
					cur_pos += tag.length;
					break;
				}
				char* tmp = cur_pos;
				tag.clearFields();
				tag.setFieldCount(4);
				tag.configureNextField(SWF_FIELD_UI16); // CharacterID
				tag.configureNextField(SWF_FIELD_UI16); // NumFrames
				tag.configureNextField(SWF_FIELD_UI16); // Width
				tag.configureNextField(SWF_FIELD_UI16); // Height
				tag.parseFields(tmp); // advances tmp, not cur_pos

				u16 video_char_id = (u16) tag.fields[0].value;
				u16 video_width   = (u16) tag.fields[2].value;
				u16 video_height  = (u16) tag.fields[3].value;
				u8 video_codec_id = (u8) cur_pos[9]; // byte after the 4 UI16s + flags byte

				// Register video char_id for place-before-define tracking.
				defined_chars.insert(video_char_id);

				tag_init << endl << "\ttagDefineVideoStream(app_context, "
				         << to_string(video_char_id) << ", "
				         << to_string(video_width) << ", "
				         << to_string(video_height) << ", "
				         << to_string((u32)video_codec_id) << ");";

				cur_pos += tag.length;
				break;
			}

			case SWF_TAG_DEFINE_SPRITE:
			{
				// Save content boundary before reading any content
				char* sprite_content_end = cur_pos + tag.length;

				tag.clearFields();
				tag.setFieldCount(2);
				tag.configureNextField(SWF_FIELD_UI16); // spriteId
				tag.configureNextField(SWF_FIELD_UI16); // frameCount
				tag.parseFields(cur_pos);

				u16 sprite_id = (u16) tag.fields[0].value;
				u16 sprite_frame_count_declared = (u16) tag.fields[1].value;

				// Mark this sprite_id as defined so any subsequent PlaceObject*
				// referencing it succeeds. PlaceObject* tags that came earlier in
				// the tag stream were already degraded to no-op modifies above.
				defined_chars.insert(sprite_id);

				std::string sp = "sprite_" + to_string(sprite_id);

				// Forward declare the sprite frame_funcs array (written to draws.h)
				sprite_forward_decls << "extern frame_func " << sp << "_frame_funcs[];" << endl;

				// Save main timeline script queue state before processing sprite sub-tags
				// (sprite sub-tags create scripts with shared indices that should NOT
				// be emitted in the main timeline frame function at ShowFrame time)
				size_t saved_last_queued = last_queued_script;

				// Emit tagDefineSprite call in tagInit (before any scripts)
				// so that DoInitAction scripts can reference the sprite dictionary
				tag_init << endl << "\t" << "tagDefineSprite(app_context, "
								 << to_string(sprite_id) << ", "
								 << sp << "_frame_funcs, "
								 << to_string(sprite_frame_count_declared) << ", "
								 << to_string(tag.length >= 4 ? tag.length - 4 : 0) << ");";

				// Parse sprite sub-tags and generate sprite frame functions.
				// Phase 7b: sprite DoAction is emitted INLINE at its actual SWF
				// tag position (via actionQueueScript) — no more end-of-frame
				// buffered flush. The inline position is critical: the
				// SWF-tag-order queue position determines FIFO drain order, and
				// some SWFs (e.g. clip_events) put DoAction BEFORE nested
				// PlaceObject, which must show up as SCRIPT queued BEFORE
				// nested sprite's LOAD.
				size_t sprite_frame_i = 0;
				std::unordered_map<std::string, size_t> sprite_labels;
				bool sprite_another_frame = false;

				// Per-frame placement metadata for SPRITE_REWIND_IDENTITY.
				// Each entry tracks a PlaceObject2/3, PlaceObject, or RemoveObject
				// inside this sprite's frame body. Indexed by frame_idx; emitted
				// as a flat FramePlacement[] + frame_starts[] cumulative offsets
				// after sprite tag walk completes.
				struct LocalFramePlacement {
					u16 depth;
					u16 char_id;
					u16 ratio;
					u8 is_remove;
					u8 has_clip_actions;
				};
				std::vector<std::vector<LocalFramePlacement>> sprite_placements_per_frame;

				sprite_definitions << "void " << sp << "_frame_" << to_string(sprite_frame_i)
								   << "(SWFAppContext* app_context)" << endl
								   << "{" << endl;
				sprite_frame_i += 1;

				SWFTag sub_tag;
				sub_tag.code = (TagType) 1;

				while (sub_tag.code != SWF_TAG_END_TAG)
				{
					// Check boundary to avoid reading past DefineSprite content
					if (cur_pos >= sprite_content_end)
						break;

					sub_tag.parseHeader(cur_pos);


					// Open new frame function if previous was closed by ShowFrame
					if (sprite_another_frame && sub_tag.code != SWF_TAG_END_TAG)
					{
						sprite_definitions << "void " << sp << "_frame_" << to_string(sprite_frame_i)
										   << "(SWFAppContext* app_context)" << endl
										   << "{" << endl;
						sprite_frame_i += 1;
						sprite_another_frame = false;
					}

					switch (sub_tag.code)
					{
						case SWF_TAG_SHOW_FRAME:
						{
							sprite_definitions << "}" << endl << endl;
							sprite_another_frame = true;
							break;
						}

						case SWF_TAG_PLACE_OBJECT:
						{
							// PlaceObject (tag 4) inside sprite: CharacterId(UI16), Depth(UI16), Matrix, optional CXFORM (RGB only)
							char* sub_tag_end = cur_pos + sub_tag.length;

							sub_tag.setFieldCount(2);
							sub_tag.configureNextField(SWF_FIELD_UI16);
							sub_tag.configureNextField(SWF_FIELD_UI16);
							sub_tag.parseFields(cur_pos);

							u16 char_id = (u16) sub_tag.fields[0].value;
							u16 depth = (u16) sub_tag.fields[1].value;

							// Note: place-before-define is intentionally NOT
							// applied to sprite-internal PlaceObjects. Sprite
							// placement happens at runtime, by which point
							// any Define* tag later in the outer stream is
							// already in the dictionary. Applying the check
							// here regresses tests where a parent sprite is
							// defined first and references siblings/children
							// declared after it (e.g. AVM1
							// `placeobject_occupied_depth`,
							// `textsnapshot_available_text`, and Gnash
							// Dejagnu-driven tests where the sprite places
							// imported chars).

							size_t transform_id = current_transform;
							MATRIX matrix;
							parseMatrix(matrix);
							recompileMatrix(matrix, transform_data);
							current_transform += 1;

							u32 cxform_id = 0;

							if (cur_pos < sub_tag_end)
							{
								u32 cur_byte_bits_left = 8;
								SWFTag cxform_tag;

								cxform_tag.clearFields();
								cxform_tag.setFieldCount(3);
								cxform_tag.configureNextField(SWF_FIELD_UB, 1);
								cxform_tag.configureNextField(SWF_FIELD_UB, 1);
								cxform_tag.configureNextField(SWF_FIELD_UB, 4);
								cxform_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);

								bool has_add = cxform_tag.fields[0].value & 1;
								bool has_mult = cxform_tag.fields[1].value & 1;
								u32 nbits = (u32) cxform_tag.fields[2].value;

								s32 mult_r = 256, mult_g = 256, mult_b = 256, mult_a = 256;
								s32 add_r = 0, add_g = 0, add_b = 0, add_a = 0;

								if (has_mult)
								{
									cxform_tag.clearFields();
									cxform_tag.setFieldCount(3);
									cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
									cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
									cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
									cxform_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);

									mult_r = (s32) cxform_tag.fields[0].value;
									mult_g = (s32) cxform_tag.fields[1].value;
									mult_b = (s32) cxform_tag.fields[2].value;
								}

								if (has_add)
								{
									cxform_tag.clearFields();
									cxform_tag.setFieldCount(3);
									cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
									cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
									cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
									cxform_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);

									add_r = (s32) cxform_tag.fields[0].value;
									add_g = (s32) cxform_tag.fields[1].value;
									add_b = (s32) cxform_tag.fields[2].value;
								}

								if (cur_byte_bits_left != 8)
								{
									cur_pos += 1;
								}

								cxform_id = (u32) current_cxform;

								cxform_data << "\t" << to_string(mult_r) << "/256.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << to_string(mult_g) << "/256.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << to_string(mult_b) << "/256.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << to_string(mult_a) << "/256.0f," << endl
											<< "\t" << to_string(add_r) << "/255.0f," << endl
											<< "\t" << to_string(add_g) << "/255.0f," << endl
											<< "\t" << to_string(add_b) << "/255.0f," << endl
											<< "\t" << to_string(add_a) << "/255.0f," << endl;

								current_cxform += 1;
							}

							sprite_definitions << "\t" << "tagPlaceObject2(app_context, "
											   << to_string(depth) << ", "
											   << to_string(char_id) << ", "
											   << to_string(transform_id) << ", "
											   << to_string(cxform_id) << ", 0);" << endl;

							{
								size_t fi = sprite_frame_i - 1;
								while (sprite_placements_per_frame.size() <= fi)
									sprite_placements_per_frame.push_back({});
								sprite_placements_per_frame[fi].push_back({depth, char_id, (u16)0, (u8)0, (u8)0});
							}

							break;
						}

					case SWF_TAG_PLACE_OBJECT_3:
					case SWF_TAG_PLACE_OBJECT_2:
						{
							bool is_sprite_po3 = (sub_tag.code == SWF_TAG_PLACE_OBJECT_3);

							// PO2: flags(UI8) + depth(UI16)
							// PO3: flags(UI8) + flags2(UI8) + depth(UI16)
							sub_tag.setFieldCount(1);
							sub_tag.configureNextField(SWF_FIELD_UI8);
							sub_tag.parseFields(cur_pos);
							u8 flags = (u8) sub_tag.fields[0].value;

							// PlaceObject3 extra flags
							bool sp_has_filter_list = false;
							bool sp_has_blend_mode = false;
							bool sp_has_cache_as_bitmap = false;
							bool sp_has_visible = false;
							bool sp_has_opaque_background = false;
							bool sp_has_class_name = false;
							bool sp_has_image = false;

							if (is_sprite_po3)
							{
								sub_tag.clearFields();
								sub_tag.setFieldCount(1);
								sub_tag.configureNextField(SWF_FIELD_UI8);
								sub_tag.parseFields(cur_pos);
								u8 flags2 = (u8) sub_tag.fields[0].value;

								// PlaceObject3 flags2 bit layout (per SWF spec / Ruffle)
								sp_has_filter_list = (flags2 & 0b00000001) != 0;
								sp_has_blend_mode = (flags2 & 0b00000010) != 0;
								sp_has_cache_as_bitmap = (flags2 & 0b00000100) != 0;
								sp_has_class_name = (flags2 & 0b00001000) != 0;
								sp_has_image = (flags2 & 0b00010000) != 0;
								sp_has_visible = (flags2 & 0b00100000) != 0;
								sp_has_opaque_background = (flags2 & 0b01000000) != 0;
							}

							// Now read depth
							sub_tag.clearFields();
							sub_tag.setFieldCount(1);
							sub_tag.configureNextField(SWF_FIELD_UI16);
							sub_tag.parseFields(cur_pos);
							u16 depth = (u16) sub_tag.fields[0].value;

							bool has_clip_actions = (flags & 0b10000000) != 0;
							bool has_clip_depth = (flags & 0b01000000) != 0;
							bool has_name = (flags & 0b00100000) != 0;
							bool has_ratio = (flags & 0b00010000) != 0;
							bool has_color = (flags & 0b00001000) != 0;
							bool has_matrix = (flags & 0b00000100) != 0;
							bool has_character = (flags & 0b00000010) != 0;

							// Skip ClassName
							if (is_sprite_po3 && (sp_has_class_name || (sp_has_image && has_character)))
							{
								while (*cur_pos != '\0') cur_pos++;
								cur_pos++;
							}

							u16 char_id = 0;
							if (has_character)
							{
								sub_tag.clearFields();
								sub_tag.setFieldCount(1);
								sub_tag.configureNextField(SWF_FIELD_UI16);
								sub_tag.parseFields(cur_pos);
								char_id = (u16) sub_tag.fields[0].value;
							}

							// Note: place-before-define is intentionally NOT
							// applied to sprite-internal PO2/3. See the
							// SWF_TAG_PLACE_OBJECT branch above for the
							// rationale (sprite placement runs at instantiation
							// time, after the full root dictionary is built).

							size_t transform_id = current_transform;
							if (has_matrix)
							{
								MATRIX matrix;
								parseMatrix(matrix);
								recompileMatrix(matrix, transform_data);
								current_transform += 1;
							}
							else
							{
								transform_id = 0;
							}

							u32 cxform_id = 0;
							if (has_color)
							{
								// Parse CXFORMWITHALPHA
								u32 cur_byte_bits_left = 8;
								SWFTag cxform_tag;

								cxform_tag.clearFields();
								cxform_tag.setFieldCount(3);
								cxform_tag.configureNextField(SWF_FIELD_UB, 1);
								cxform_tag.configureNextField(SWF_FIELD_UB, 1);
								cxform_tag.configureNextField(SWF_FIELD_UB, 4);
								cxform_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);

								bool has_add = cxform_tag.fields[0].value & 1;
								bool has_mult = cxform_tag.fields[1].value & 1;
								u32 nbits = (u32) cxform_tag.fields[2].value;

								s32 mult_r = 256, mult_g = 256, mult_b = 256, mult_a = 256;
								s32 add_r = 0, add_g = 0, add_b = 0, add_a = 0;

								if (has_mult)
								{
									cxform_tag.clearFields();
									cxform_tag.setFieldCount(4);
									cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
									cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
									cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
									cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
									cxform_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);

									mult_r = (s32) cxform_tag.fields[0].value;
									mult_g = (s32) cxform_tag.fields[1].value;
									mult_b = (s32) cxform_tag.fields[2].value;
									mult_a = (s32) cxform_tag.fields[3].value;
								}

								if (has_add)
								{
									cxform_tag.clearFields();
									cxform_tag.setFieldCount(4);
									cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
									cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
									cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
									cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
									cxform_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);

									add_r = (s32) cxform_tag.fields[0].value;
									add_g = (s32) cxform_tag.fields[1].value;
									add_b = (s32) cxform_tag.fields[2].value;
									add_a = (s32) cxform_tag.fields[3].value;
								}

								if (cur_byte_bits_left != 8)
								{
									cur_pos += 1;
								}

								cxform_id = (u32) current_cxform;

								cxform_data << "\t" << to_string(mult_r) << "/256.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << to_string(mult_g) << "/256.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << to_string(mult_b) << "/256.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << "0.0f," << endl
											<< "\t" << to_string(mult_a) << "/256.0f," << endl
											<< "\t" << to_string(add_r) << "/255.0f," << endl
											<< "\t" << to_string(add_g) << "/255.0f," << endl
											<< "\t" << to_string(add_b) << "/255.0f," << endl
											<< "\t" << to_string(add_a) << "/255.0f," << endl;

								current_cxform += 1;
							}

							// Parse remaining optional fields
							u16 ratio_val = 0;
							if (has_ratio)
							{
								sub_tag.clearFields();
								sub_tag.setFieldCount(1);
								sub_tag.configureNextField(SWF_FIELD_UI16);
								sub_tag.parseFields(cur_pos);
								ratio_val = (u16) sub_tag.fields[0].value;
							}
							std::string sp_instance_name;
							if (has_name)
							{
								char* name_start = cur_pos;
								while (*cur_pos != '\0') cur_pos++;
								sp_instance_name = std::string(name_start, cur_pos - name_start);
								cur_pos++; // skip null terminator
							}

							u16 clip_depth_val = 0;
							if (has_clip_depth)
							{
								sub_tag.clearFields();
								sub_tag.setFieldCount(1);
								sub_tag.configureNextField(SWF_FIELD_UI16);
								sub_tag.parseFields(cur_pos);
								clip_depth_val = (u16) sub_tag.fields[0].value;
							}

							// PO3 extra fields in sprite context
							u8 sp_blend_mode_val = 0;
							u8 sp_filter_type = 0;
							float sp_blur_x = 0, sp_blur_y = 0;
							u8 sp_filter_quality = 1, sp_filter_flags = 0;
							float sp_filter_r = 0, sp_filter_g = 0, sp_filter_b = 0, sp_filter_a = 0;
							float sp_filter_strength = 1.0f, sp_filter_angle = 0, sp_filter_distance = 0;
							float sp_highlight_r = 0, sp_highlight_g = 0, sp_highlight_b = 0, sp_highlight_a = 0;

							if (is_sprite_po3 && sp_has_filter_list)
							{
								u8 num_filters = *(u8*) cur_pos; cur_pos += 1;
								for (u8 f = 0; f < num_filters; f++)
								{
									u8 filter_id = *(u8*) cur_pos; cur_pos += 1;
									switch (filter_id)
									{
										case 0: // DropShadowFilter
										{
											u8 ds_r = *(u8*)cur_pos; u8 ds_g = *(u8*)(cur_pos+1);
											u8 ds_b = *(u8*)(cur_pos+2); u8 ds_a = *(u8*)(cur_pos+3);
											cur_pos += 4;
											u32 ds_bx; memcpy(&ds_bx, cur_pos, 4); cur_pos += 4;
											u32 ds_by; memcpy(&ds_by, cur_pos, 4); cur_pos += 4;
											u32 ds_ang; memcpy(&ds_ang, cur_pos, 4); cur_pos += 4;
											u32 ds_dist; memcpy(&ds_dist, cur_pos, 4); cur_pos += 4;
											u16 ds_str; memcpy(&ds_str, cur_pos, 2); cur_pos += 2;
											u8 ds_fl = *(u8*)cur_pos; cur_pos += 1;
											if (sp_filter_type == 0) {
												sp_filter_type = 2; sp_filter_r = ds_r/255.0f; sp_filter_g = ds_g/255.0f;
												sp_filter_b = ds_b/255.0f; sp_filter_a = ds_a/255.0f;
												sp_blur_x = (float)(s32)ds_bx/65536.0f; sp_blur_y = (float)(s32)ds_by/65536.0f;
												sp_filter_angle = (float)(s32)ds_ang/65536.0f; sp_filter_distance = (float)(s32)ds_dist/65536.0f;
												sp_filter_strength = (float)ds_str/256.0f;
												sp_filter_quality = ds_fl & 0x1F; if (!sp_filter_quality) sp_filter_quality = 1;
												sp_filter_flags = (ds_fl >> 5) & 0x07;
											}
											break;
										}
										case 1: // BlurFilter
										{
											u32 bl_x; memcpy(&bl_x, cur_pos, 4); cur_pos += 4;
											u32 bl_y; memcpy(&bl_y, cur_pos, 4); cur_pos += 4;
											u8 bl_fl = *(u8*)cur_pos; cur_pos += 1;
											if (sp_filter_type == 0) {
												sp_filter_type = 1; sp_blur_x = (float)(s32)bl_x/65536.0f; sp_blur_y = (float)(s32)bl_y/65536.0f;
												sp_filter_quality = (bl_fl >> 3) & 0x1F; if (!sp_filter_quality) sp_filter_quality = 1;
											}
											break;
										}
										case 2: // GlowFilter
										{
											u8 gl_r = *(u8*)cur_pos; u8 gl_g = *(u8*)(cur_pos+1);
											u8 gl_b = *(u8*)(cur_pos+2); u8 gl_a = *(u8*)(cur_pos+3);
											cur_pos += 4;
											u32 gl_bx; memcpy(&gl_bx, cur_pos, 4); cur_pos += 4;
											u32 gl_by; memcpy(&gl_by, cur_pos, 4); cur_pos += 4;
											u16 gl_str; memcpy(&gl_str, cur_pos, 2); cur_pos += 2;
											u8 gl_fl = *(u8*)cur_pos; cur_pos += 1;
											if (sp_filter_type == 0) {
												sp_filter_type = 3; sp_filter_r = gl_r/255.0f; sp_filter_g = gl_g/255.0f;
												sp_filter_b = gl_b/255.0f; sp_filter_a = gl_a/255.0f;
												sp_blur_x = (float)(s32)gl_bx/65536.0f; sp_blur_y = (float)(s32)gl_by/65536.0f;
												sp_filter_strength = (float)gl_str/256.0f;
												sp_filter_quality = gl_fl & 0x1F; if (!sp_filter_quality) sp_filter_quality = 1;
												sp_filter_flags = (gl_fl >> 5) & 0x07;
											}
											break;
										}
										case 3: // BevelFilter (27 bytes)
										{
											u8 bv_sr = *(u8*)cur_pos; u8 bv_sg = *(u8*)(cur_pos+1);
											u8 bv_sb = *(u8*)(cur_pos+2); u8 bv_sa = *(u8*)(cur_pos+3);
											cur_pos += 4;
											u8 bv_hr = *(u8*)cur_pos; u8 bv_hg = *(u8*)(cur_pos+1);
											u8 bv_hb = *(u8*)(cur_pos+2); u8 bv_ha = *(u8*)(cur_pos+3);
											cur_pos += 4;
											u32 bv_bx; memcpy(&bv_bx, cur_pos, 4); cur_pos += 4;
											u32 bv_by; memcpy(&bv_by, cur_pos, 4); cur_pos += 4;
											u32 bv_ang; memcpy(&bv_ang, cur_pos, 4); cur_pos += 4;
											u32 bv_dist; memcpy(&bv_dist, cur_pos, 4); cur_pos += 4;
											u16 bv_str; memcpy(&bv_str, cur_pos, 2); cur_pos += 2;
											u8 bv_fl = *(u8*)cur_pos; cur_pos += 1;
											if (sp_filter_type == 0) {
												sp_filter_type = 4;
												sp_filter_r = bv_sr/255.0f; sp_filter_g = bv_sg/255.0f;
												sp_filter_b = bv_sb/255.0f; sp_filter_a = bv_sa/255.0f;
												sp_highlight_r = bv_hr/255.0f; sp_highlight_g = bv_hg/255.0f;
												sp_highlight_b = bv_hb/255.0f; sp_highlight_a = bv_ha/255.0f;
												sp_blur_x = (float)(s32)bv_bx/65536.0f; sp_blur_y = (float)(s32)bv_by/65536.0f;
												sp_filter_angle = (float)(s32)bv_ang/65536.0f; sp_filter_distance = (float)(s32)bv_dist/65536.0f;
												sp_filter_strength = (float)bv_str/256.0f;
												sp_filter_quality = bv_fl & 0x0F; if (!sp_filter_quality) sp_filter_quality = 1;
												sp_filter_flags = (bv_fl >> 4) & 0x0F;
											}
											break;
										}
										case 4: // GradientGlowFilter
										{
											u8 nc = *(u8*) cur_pos; cur_pos += 1;
											u8 lr = 0, lg = 0, lb = 0, la = 255;
											for (u8 ci = 0; ci < nc; ci++) {
												lr = *(u8*)(cur_pos+ci*4); lg = *(u8*)(cur_pos+ci*4+1);
												lb = *(u8*)(cur_pos+ci*4+2); la = *(u8*)(cur_pos+ci*4+3);
											}
											cur_pos += nc * 4 + nc;
											u32 gg_bx; memcpy(&gg_bx, cur_pos, 4); cur_pos += 4;
											u32 gg_by; memcpy(&gg_by, cur_pos, 4); cur_pos += 4;
											u32 gg_ang; memcpy(&gg_ang, cur_pos, 4); cur_pos += 4;
											u32 gg_dist; memcpy(&gg_dist, cur_pos, 4); cur_pos += 4;
											u16 gg_str; memcpy(&gg_str, cur_pos, 2); cur_pos += 2;
											u8 gg_fl = *(u8*)cur_pos; cur_pos += 1;
											if (sp_filter_type == 0) {
												sp_filter_type = 3;
												sp_filter_r = lr/255.0f; sp_filter_g = lg/255.0f;
												sp_filter_b = lb/255.0f; sp_filter_a = la/255.0f;
												sp_blur_x = (float)(s32)gg_bx/65536.0f; sp_blur_y = (float)(s32)gg_by/65536.0f;
												sp_filter_angle = (float)(s32)gg_ang/65536.0f; sp_filter_distance = (float)(s32)gg_dist/65536.0f;
												sp_filter_strength = (float)gg_str/256.0f;
												sp_filter_quality = gg_fl & 0x1F; if (!sp_filter_quality) sp_filter_quality = 1;
												sp_filter_flags = (gg_fl >> 5) & 0x07;
											}
											break;
										}
										case 5: // ConvolutionFilter
										{
											u8 mx = *(u8*) cur_pos; cur_pos += 1;
											u8 my = *(u8*) cur_pos; cur_pos += 1;
											cur_pos += 8 + mx * my * 4 + 5;
											if (sp_filter_type == 0) {
												sp_filter_type = 1;
												sp_blur_x = (float)mx; sp_blur_y = (float)my;
												sp_filter_quality = 1; sp_filter_strength = 1.0f;
											}
											break;
										}
										case 6: cur_pos += 80; break;
										case 7: // GradientBevelFilter
										{
											u8 nc = *(u8*) cur_pos; cur_pos += 1;
											u8 gb_sr = 0, gb_sg = 0, gb_sb = 0, gb_sa = 255;
											u8 gb_hr = 255, gb_hg = 255, gb_hb = 255, gb_ha = 255;
											if (nc >= 2) {
												gb_sr = *(u8*)cur_pos; gb_sg = *(u8*)(cur_pos+1);
												gb_sb = *(u8*)(cur_pos+2); gb_sa = *(u8*)(cur_pos+3);
												u8 li = nc - 1;
												gb_hr = *(u8*)(cur_pos+li*4); gb_hg = *(u8*)(cur_pos+li*4+1);
												gb_hb = *(u8*)(cur_pos+li*4+2); gb_ha = *(u8*)(cur_pos+li*4+3);
											} else if (nc == 1) {
												gb_sr = *(u8*)cur_pos; gb_sg = *(u8*)(cur_pos+1);
												gb_sb = *(u8*)(cur_pos+2); gb_sa = *(u8*)(cur_pos+3);
											}
											cur_pos += nc * 4 + nc;
											u32 gb_bx; memcpy(&gb_bx, cur_pos, 4); cur_pos += 4;
											u32 gb_by; memcpy(&gb_by, cur_pos, 4); cur_pos += 4;
											u32 gb_ang; memcpy(&gb_ang, cur_pos, 4); cur_pos += 4;
											u32 gb_dist; memcpy(&gb_dist, cur_pos, 4); cur_pos += 4;
											u16 gb_str; memcpy(&gb_str, cur_pos, 2); cur_pos += 2;
											u8 gb_fl = *(u8*)cur_pos; cur_pos += 1;
											if (sp_filter_type == 0) {
												sp_filter_type = 4;
												sp_filter_r = gb_sr/255.0f; sp_filter_g = gb_sg/255.0f;
												sp_filter_b = gb_sb/255.0f; sp_filter_a = gb_sa/255.0f;
												sp_highlight_r = gb_hr/255.0f; sp_highlight_g = gb_hg/255.0f;
												sp_highlight_b = gb_hb/255.0f; sp_highlight_a = gb_ha/255.0f;
												sp_blur_x = (float)(s32)gb_bx/65536.0f; sp_blur_y = (float)(s32)gb_by/65536.0f;
												sp_filter_angle = (float)(s32)gb_ang/65536.0f; sp_filter_distance = (float)(s32)gb_dist/65536.0f;
												sp_filter_strength = (float)gb_str/256.0f;
												sp_filter_quality = gb_fl & 0x1F; if (!sp_filter_quality) sp_filter_quality = 1;
												sp_filter_flags = (gb_fl >> 5) & 0x07;
											}
											break;
										}
									}
								}
							}

							if (is_sprite_po3 && sp_has_blend_mode)
							{
								sp_blend_mode_val = *(u8*) cur_pos; cur_pos += 1;
							}

							if (is_sprite_po3 && sp_has_cache_as_bitmap) cur_pos += 1;
							if (is_sprite_po3 && sp_has_visible) cur_pos += 1;
							if (is_sprite_po3 && sp_has_opaque_background) cur_pos += 4;

							// Parse clip actions if present
							std::string clip_actions_var;
							size_t clip_action_count = 0;

							if (has_clip_actions)
							{
								sub_tag.clearFields();
								sub_tag.setFieldCount(1);
								sub_tag.configureNextField(SWF_FIELD_UI16);
								sub_tag.parseFields(cur_pos);

								u32 all_event_flags;
								if (header.version >= 6)
								{
									sub_tag.clearFields();
									sub_tag.setFieldCount(1);
									sub_tag.configureNextField(SWF_FIELD_UI32, 32);
									sub_tag.parseFields(cur_pos);
									all_event_flags = (u32) sub_tag.fields[0].value;
								}
								else
								{
									sub_tag.clearFields();
									sub_tag.setFieldCount(1);
									sub_tag.configureNextField(SWF_FIELD_UI16);
									sub_tag.parseFields(cur_pos);
									all_event_flags = (u32)(u16) sub_tag.fields[0].value;
								}

								struct ClipActionEntry { u32 event_flags; std::string func_name; };
								std::vector<ClipActionEntry> clip_entries;
								size_t sprite_clip_action_count = 0;

								while (all_event_flags != 0)
								{
									if (++sprite_clip_action_count > 1000)
									{
										fprintf(stderr, "Warning: sprite clip action parsing exceeded 1000 entries, skipping rest\n");
										break;
									}

									u32 event_flags;
									if (header.version >= 6)
									{
										sub_tag.clearFields();
										sub_tag.setFieldCount(1);
										sub_tag.configureNextField(SWF_FIELD_UI32, 32);
										sub_tag.parseFields(cur_pos);
										event_flags = (u32) sub_tag.fields[0].value;
									}
									else
									{
										sub_tag.clearFields();
										sub_tag.setFieldCount(1);
										sub_tag.configureNextField(SWF_FIELD_UI16);
										sub_tag.parseFields(cur_pos);
										event_flags = (u32)(u16) sub_tag.fields[0].value;
									}

									if (event_flags == 0)
										break;

									sub_tag.clearFields();
									sub_tag.setFieldCount(1);
									sub_tag.configureNextField(SWF_FIELD_UI32, 32);
									sub_tag.parseFields(cur_pos);
									u32 action_size = (u32) sub_tag.fields[0].value;

									if (event_flags & 0x20000)
									{
										cur_pos += 1;
										action_size -= 1;
									}

									std::string func_name = "clip_action_" + to_string(next_script_i);
									context.out_script_header << endl << "void " << func_name << "(SWFAppContext* app_context);";

									ofstream out_script(context.output_scripts_folder + "script_" + to_string(next_script_i) + ".c", ios_base::out);
									out_script << "#include <recomp.h>" << endl
											   << "#include <setjmp.h>" << endl
											   << "#include \"script_decls.h\"" << endl << endl
											   << "void " << func_name << "(SWFAppContext* app_context)" << endl
											   << "{" << endl;
									out_script << "\t" << "char str_buffer[17];" << endl << endl;
									next_script_i += 1;

									action.parseActions(context, cur_pos, out_script);
									out_script << "}";

									clip_entries.push_back({ event_flags, func_name });
								}

								if (!clip_entries.empty())
								{
									clip_actions_var = "clip_actions_" + to_string(num_finished_tags);

									// Use static local so the pointer survives after the frame function returns.
									// No extern forward decl needed — static locals have internal linkage.
									sprite_definitions << "static ClipAction " << clip_actions_var << "[] =" << endl
													   << "{" << endl;
									for (auto& ca : clip_entries)
									{
										sprite_definitions << "\t" << "{ 0x" << std::hex << ca.event_flags << std::dec
														   << ", " << ca.func_name << " }," << endl;
									}
									sprite_definitions << "};" << endl;

									clip_action_count = clip_entries.size();
								}
							}

							// Emit instance name BEFORE placement so g_pending_instance_name
							// prevents auto-naming. Clip-action cases also emit before placement.
							// Use `has_name` so an explicit empty name ("") propagates.
							if (has_name && clip_action_count == 0)
							{
								std::string escaped = "";
								for (char c : sp_instance_name) {
									if (c == '"' || c == '\\') escaped += '\\';
									escaped += c;
								}
								sprite_definitions << "\t" << "tagSetInstanceName(app_context, " << to_string(depth) << ", \"" << escaped << "\");" << endl;
							}

							// Emit the place call
							if (sp_blend_mode_val > 1)
							{
								sprite_definitions << "\t" << "tagPlaceObject3(app_context, "
												   << to_string(depth) << ", "
												   << to_string(char_id) << ", "
												   << to_string(transform_id) << ", "
												   << to_string(cxform_id) << ", "
												   << to_string(clip_depth_val) << ", "
												   << to_string(sp_blend_mode_val) << ");" << endl;
							}
							else if (has_ratio && clip_action_count > 0)
							{
								// When clip actions are present, emit instance name BEFORE placement
								if (has_name)
								{
									std::string escaped = "";
									for (char c : sp_instance_name) {
										if (c == '"' || c == '\\') escaped += '\\';
										escaped += c;
									}
									sprite_definitions << "\t" << "tagSetInstanceName(app_context, " << to_string(depth) << ", \"" << escaped << "\");" << endl;
								}
								sprite_definitions << "\t" << "tagPlaceObject2RatioWithClipActions(app_context, "
												   << to_string(depth) << ", "
												   << to_string(char_id) << ", "
												   << to_string(transform_id) << ", "
												   << to_string(cxform_id) << ", "
												   << to_string(clip_depth_val) << ", "
												   << to_string(ratio_val) << ", "
												   << clip_actions_var << ", "
												   << to_string(clip_action_count) << ");" << endl;
							}
							else if (has_ratio)
							{
								sprite_definitions << "\t" << "tagPlaceObject2Ratio(app_context, "
												   << to_string(depth) << ", "
												   << to_string(char_id) << ", "
												   << to_string(transform_id) << ", "
												   << to_string(cxform_id) << ", "
												   << to_string(clip_depth_val) << ", "
												   << to_string(ratio_val) << ");" << endl;
								// Also attach clip actions if both ratio and clip actions are present
								if (clip_action_count > 0)
								{
									sprite_definitions << "\t" << "tagSetClipActions(app_context, "
													   << to_string(depth) << ", "
													   << clip_actions_var << ", "
													   << to_string(clip_action_count) << ");" << endl;
								}
							}
							else if (clip_action_count > 0)
							{
								// When clip actions are present, emit instance name BEFORE placement
								if (has_name)
								{
									std::string escaped = "";
									for (char c : sp_instance_name) {
										if (c == '"' || c == '\\') escaped += '\\';
										escaped += c;
									}
									sprite_definitions << "\t" << "tagSetInstanceName(app_context, " << to_string(depth) << ", \"" << escaped << "\");" << endl;
								}
								sprite_definitions << "\t" << "tagPlaceObject2WithClipActions(app_context, "
												   << to_string(depth) << ", "
												   << to_string(char_id) << ", "
												   << to_string(transform_id) << ", "
												   << to_string(cxform_id) << ", "
												   << to_string(clip_depth_val) << ", "
												   << clip_actions_var << ", "
												   << to_string(clip_action_count) << ");" << endl;
							}
							else
							{
								sprite_definitions << "\t" << "tagPlaceObject2(app_context, "
												   << to_string(depth) << ", "
												   << to_string(char_id) << ", "
												   << to_string(transform_id) << ", "
												   << to_string(cxform_id) << ", "
												   << to_string(clip_depth_val) << ");" << endl;
							}

							// Instance name already emitted before the placement call above.

							// Emit filter if parsed
							if (sp_filter_type != 0)
							{
								sprite_definitions << std::fixed
									<< "\t" << "tagSetFilter(app_context, " << to_string(depth) << ", "
									<< to_string(sp_filter_type) << ", "
									<< sp_blur_x << "f, "
									<< sp_blur_y << "f, "
									<< to_string(sp_filter_quality) << ", "
									<< to_string(sp_filter_flags) << ", "
									<< sp_filter_r << "f, "
									<< sp_filter_g << "f, "
									<< sp_filter_b << "f, "
									<< sp_filter_a << "f, "
									<< sp_filter_strength << "f, "
									<< sp_filter_angle << "f, "
									<< sp_filter_distance << "f);"
									<< std::defaultfloat << endl;

								if (sp_filter_type == 4)
								{
									sprite_definitions << std::fixed
										<< "\t" << "tagSetFilterHighlight(app_context, " << to_string(depth) << ", "
										<< sp_highlight_r << "f, "
										<< sp_highlight_g << "f, "
										<< sp_highlight_b << "f, "
										<< sp_highlight_a << "f);"
										<< std::defaultfloat << endl;
								}
							}

							{
								size_t fi = sprite_frame_i - 1;
								while (sprite_placements_per_frame.size() <= fi)
									sprite_placements_per_frame.push_back({});
								// has_character==0 emits char_id=0 (treated as "Modify"); ratio_val==0 if !has_ratio.
								sprite_placements_per_frame[fi].push_back({
									depth,
									has_character ? char_id : (u16)0,
									has_ratio ? ratio_val : (u16)0,
									(u8)0,
									(u8)(clip_action_count > 0 ? 1 : 0)
								});
							}

							break;
						}

						case SWF_TAG_REMOVE_OBJECT:
						{
							sub_tag.setFieldCount(2);
							sub_tag.configureNextField(SWF_FIELD_UI16);
							sub_tag.configureNextField(SWF_FIELD_UI16);
							sub_tag.parseFields(cur_pos);

							u16 char_id = (u16) sub_tag.fields[0].value;
							u16 depth = (u16) sub_tag.fields[1].value;

							sprite_definitions << "\t" << "tagRemoveObject(app_context, " << to_string(depth) << ");" << endl;

							{
								size_t fi = sprite_frame_i - 1;
								while (sprite_placements_per_frame.size() <= fi)
									sprite_placements_per_frame.push_back({});
								sprite_placements_per_frame[fi].push_back({depth, (u16)0, (u16)0, (u8)1, (u8)0});
								(void)char_id;
							}

							break;
						}

						case SWF_TAG_REMOVE_OBJECT_2:
						{
							sub_tag.setFieldCount(1);
							sub_tag.configureNextField(SWF_FIELD_UI16);
							sub_tag.parseFields(cur_pos);

							u16 depth = (u16) sub_tag.fields[0].value;

							sprite_definitions << "\t" << "tagRemoveObject2(app_context, " << to_string(depth) << ");" << endl;

							{
								size_t fi = sprite_frame_i - 1;
								while (sprite_placements_per_frame.size() <= fi)
									sprite_placements_per_frame.push_back({});
								sprite_placements_per_frame[fi].push_back({depth, (u16)0, (u16)0, (u8)1, (u8)0});
							}

							break;
						}

						case SWF_TAG_END_TAG:
						{
							if (!sprite_another_frame)
							{
								// Close the last frame function if ShowFrame didn't close it
								sprite_definitions << "}" << endl << endl;
							}
							break;
						}

						case SWF_TAG_FRAME_LABEL:
						{
							// Parse sprite frame label
							const char* label_str = cur_pos;
							std::string label(label_str);
							// sprite_frame_i has already been incremented after opening the frame function,
							// so the current frame being built is sprite_frame_i - 1
							sprite_labels.insert({label, sprite_frame_i - 1});
							cur_pos += sub_tag.length;
							break;
						}

						case SWF_TAG_DO_ACTION:
						{
							// DoAction inside sprite — create script file and emit
							// inline actionQueueScript at this tag's SWF position.
							// Phase 7b: the SWF-tag-order queue position is
							// observable — clip_events relies on sprite DoAction
							// queueing BEFORE nested PlaceObject's LOAD entries.
							std::string script_name = "script_" + to_string(next_script_i);
							context.out_script_header << endl << "void " << script_name << "(SWFAppContext* app_context);";

							ofstream sprite_out_script(context.output_scripts_folder + script_name + ".c", ios_base::out);
							sprite_out_script << "#include <recomp.h>" << endl
											  << "#include <setjmp.h>" << endl
											  << "#include \"script_decls.h\"" << endl << endl
											  << "void " << script_name << "(SWFAppContext* app_context)" << endl
											  << "{" << endl;
							sprite_out_script << "\t" << "char str_buffer[17];" << endl << endl;
							sprite_out_script << "\t" << "actionResetRegisters();" << endl << endl;

							next_script_i += 1;

							// Cross-DoAction backward-jump support (see main DoAction
							// case for explanation). cur_pos is already the absolute
							// SWF body-start pointer for this DoAction, so it doubles
							// as action_buffer_start.
							char* sprite_doaction_body_start = cur_pos;
							action.abs_swf_buffer_start_ptr = sprite_doaction_body_start;
							action.doaction_script_map_ptr = &doaction_script_map;
							action.parseActions(context, cur_pos, sprite_out_script);
							action.abs_swf_buffer_start_ptr = nullptr;
							action.doaction_script_map_ptr = nullptr;
							doaction_script_map[sprite_doaction_body_start] = script_name;

							sprite_out_script << "}";

							// Phase 7b: sprite DoAction dispatch has two paths:
							//   (a) Queue: normal frame processing, target-frame
							//       scripts-only replay (g_tag_skip_mode=1), or
							//       Phase 1 eager init from tagPlaceObject2 /
							//       runtime-attach paths — EXCEPT during goto
							//       catch-up (actionGotoCatchupActive) where
							//       queueing would put sprite scripts ahead of
							//       the target frame's root DoAction in FIFO.
							//       Suppressed via scriptOnly (Phase 2 re-run)
							//       so already-queued scripts don't re-queue.
							//   (b) Synchronous fire: Phase 2 re-run of the
							//       goto-deferred sprite init path, where Phase 1
							//       didn't queue (catch-up suppressed it) so we
							//       fire inline now, after the target frame's
							//       root DoAction already drained.
							// actionQueueSpriteScript (not actionQueueScript)
							// binds the sprite's MC context at queue time so
							// drains in root context still run scripts in the
							// sprite's context.
							// Phase F (GOTO_FIFO_UNIFICATION_INCREMENTAL): unify
							// sprite-script queuing under one path. Queue when:
							//   - normal flow (!catch_up_mode), or
							//   - target-frame scripts-only replay (g_tag_skip_mode), or
							//   - Phase 1 eager init outside goto catch-up
							//     (actionEagerInitActive() && !actionGotoCatchupActive()), or
							//   - goto Phase 2 deferred re-run for a sprite that was
							//     eager-initialized under goto catch-up
							//     (actionScriptOnlyMode() && actionDeferredSpriteInitActive()
							//     && !actionAttachInitActive()).
							// The goto Phase 2 case used to sync-fire script_N
							// directly via an ELSE branch, but that ran scripts
							// before the calling drain could interleave the target
							// frame's root DoAction. Queuing lets the outer FIFO
							// drain preserve "root target then sprite eager-init"
							// ordering.
							//
							// Sync-fire is preserved for the runtime-attach Phase 2
							// re-run path (actionAttachInitActive — see
							// tag_stubs.c's aq_dispatch_pending_attach_init). attach
							// init's own ordering is set by the PAI dispatcher and
							// must not be perturbed by FIFO; default_names,
							// attach_movie, and removed_target_clip_scope rely on
							// sync-fire here.
							sprite_definitions
								<< "\t" << "if (!actionAttachInitActive() && (!catch_up_mode || g_tag_skip_mode || "
								<< "(actionEagerInitActive() && !actionGotoCatchupActive()) || "
								<< "(actionScriptOnlyMode() && actionDeferredSpriteInitActive()))) "
								<< "actionQueueSpriteScript(app_context, " << script_name << ");" << endl;
							sprite_definitions
								<< "\t" << "else if (!catch_up_mode && actionAttachInitActive() && actionScriptOnlyMode() && actionDeferredSpriteInitActive()) "
								<< script_name << "(app_context);" << endl;

							// Phase A of GOTO_FIFO_UNIFICATION incremental
							// plan: record (sprite_char_id, frame_idx) →
							// script_func mapping into a side table. Dead
							// until later phases consume it via
							// actionGetSpriteFrameScript(). sprite_frame_i
							// has been incremented past the current frame
							// at the open-frame-func site, so the current
							// frame is sprite_frame_i - 1.
							sprite_frame_scripts_table
								<< "\t{ " << to_string(sprite_id) << ", "
								<< to_string(sprite_frame_i - 1) << ", "
								<< script_name << " }," << endl;
							sprite_frame_scripts_count += 1;

							break;
						}

						case SWF_TAG_DO_INIT_ACTION:
						{
							// DoInitAction inside DefineSprite — parse SpriteId and emit
							// guarded call inline at this tag's SWF position.
							// Phase 7b: DoInitAction continues to fire synchronously
							// (not queued) via tagDoInitActionGuarded — it must run
							// before the sprite is constructed, not at SHOW_FRAME
							// drain time. The "prepend-to-buffer" pattern is now
							// implicit in SWF tag ordering (DoInitAction precedes
							// other DoAction tags in the stream).
							sub_tag.clearFields();
							sub_tag.setFieldCount(1);
							sub_tag.configureNextField(SWF_FIELD_UI16);
							sub_tag.parseFields(cur_pos);
							u16 init_sprite_id = (u16) sub_tag.fields[0].value;

							std::string script_name = "script_" + to_string(next_script_i);
							context.out_script_header << endl << "void " << script_name << "(SWFAppContext* app_context);";

							ofstream sprite_init_script(context.output_scripts_folder + script_name + ".c", ios_base::out);
							sprite_init_script << "#include <recomp.h>" << endl
											   << "#include <setjmp.h>" << endl
											   << "#include \"script_decls.h\"" << endl << endl
											   << "void " << script_name << "(SWFAppContext* app_context)" << endl
											   << "{" << endl;
							sprite_init_script << "\t" << "char str_buffer[17];" << endl << endl;
							sprite_init_script << "\t" << "actionResetRegisters();" << endl << endl;

							next_script_i += 1;

							action.parseActions(context, cur_pos, sprite_init_script);

							sprite_init_script << "}";

							sprite_definitions << "\t" << "tagDoInitActionGuarded(app_context, " << init_sprite_id << ", " << script_name << ");" << endl;

							break;
						}

						default:
						{
							// Skip unsupported sprite sub-tags
							cur_pos += sub_tag.length;
							break;
						}
					}

					sub_tag.clearFields();
					num_finished_tags += 1;
				}

				// If loop exited by boundary (no EndTag found), close last frame function
				if (sub_tag.code != SWF_TAG_END_TAG && !sprite_another_frame)
				{
					sprite_definitions << "}" << endl << endl;
				}

				// Ensure cur_pos is past the DefineSprite content for the main loop
				cur_pos = sprite_content_end;

				// Generate sprite frame_funcs array
				sprite_definitions << "frame_func " << sp << "_frame_funcs[] =" << endl
								   << "{" << endl;
				for (size_t i = 0; i < sprite_frame_i; ++i)
				{
					sprite_definitions << "\t" << sp << "_frame_" << to_string(i) << "," << endl;
				}
				sprite_definitions << "};" << endl << endl;

				// SPRITE_REWIND_IDENTITY Phase 1: emit per-sprite per-frame
				// placement metadata (FramePlacement[] flat + frame_starts[]
				// cumulative offsets). The runtime uses this at sprite
				// loop-back to compute survives_rewind for each existing
				// display_list entry, mirroring Ruffle's run_goto. Pad
				// per-frame vector to sprite_frame_i so frame_starts has
				// length sprite_frame_i + 1 (sentinel = total count).
				while (sprite_placements_per_frame.size() < sprite_frame_i)
					sprite_placements_per_frame.push_back({});

				size_t total_placements = 0;
				for (auto& v : sprite_placements_per_frame) total_placements += v.size();

				// Use file-scope static linkage so parent + child SWFs in the
				// same compile unit (multi-SWF tests) don't collide on
				// sprite_<id>_placements / _frame_starts. tagSetSpritePlacements
				// captures the array pointers at tagInit time so internal
				// linkage is fine.
				if (total_placements > 0)
				{
					sprite_definitions << "static FramePlacement " << sp << "_placements[] =" << endl
									   << "{" << endl;
					for (size_t fi = 0; fi < sprite_frame_i; ++fi)
					{
						for (auto& p : sprite_placements_per_frame[fi])
						{
							sprite_definitions << "\t{ "
								<< to_string(p.depth) << ", "
								<< to_string(p.char_id) << ", "
								<< to_string(p.ratio) << ", "
								<< to_string((u32)p.is_remove) << ", "
								<< to_string((u32)p.has_clip_actions) << " }, // frame "
								<< to_string(fi) << endl;
						}
					}
					sprite_definitions << "};" << endl;
				}
				else
				{
					// Empty sentinel so the symbol always exists.
					sprite_definitions << "static FramePlacement " << sp << "_placements[1] = { { 0, 0, 0, 0, 0 } };" << endl;
				}

				sprite_definitions << "static u16 " << sp << "_frame_starts[] = {" << endl;
				size_t cumulative = 0;
				for (size_t fi = 0; fi < sprite_frame_i; ++fi)
				{
					sprite_definitions << "\t" << to_string(cumulative) << "," << endl;
					cumulative += sprite_placements_per_frame[fi].size();
				}
				sprite_definitions << "\t" << to_string(cumulative) << endl;  // sentinel = total
				sprite_definitions << "};" << endl << endl;

				tag_init << endl << "\ttagSetSpritePlacements("
						 << to_string(sprite_id) << ", "
						 << sp << "_placements, "
						 << sp << "_frame_starts, "
						 << to_string(sprite_frame_i) << ");";

				// Generate per-sprite frame label table and registration call
				if (!sprite_labels.empty())
				{
					sprite_definitions << "FrameLabelEntry " << sp << "_frame_labels[] =" << endl
									   << "{" << endl;
					for (const auto& pair : sprite_labels)
					{
						sprite_definitions << "\t{ \"" << pair.first << "\", " << to_string(pair.second) << " }," << endl;
					}
					sprite_definitions << "\t{ NULL, 0 }" << endl
									   << "};" << endl << endl;

					// Register sprite labels in tagInit (after tagDefineSprite)
					tag_init << endl << "\t" << "tagSetSpriteLabels("
							 << to_string(sprite_id) << ", "
							 << sp << "_frame_labels, "
							 << to_string(sprite_labels.size()) << ");";
				}

				// Restore main timeline script queue — sprite-created scripts are
				// called from sprite frame functions, not from main timeline frames.
				last_queued_script = saved_last_queued;

				break;
			}

			//~ case SWF_TAG_DO_ABC:
			//~ {
				//~ cur_pos += tag.length;
				
				//~ break;
			//~ }
			
			case SWF_TAG_DEFINE_BUTTON:
			case SWF_TAG_DEFINE_BUTTON_2:
			{
				bool is_button2 = (tag.code == SWF_TAG_DEFINE_BUTTON_2);
				char* tag_body_start = cur_pos;
				u32 button_tag_length = tag.length;

				tag.clearFields();
				tag.setFieldCount(1);
				tag.configureNextField(SWF_FIELD_UI16); // ButtonId
				tag.parseFields(cur_pos);

				u16 button_id = (u16) tag.fields[0].value;

				// Register button char_id for place-before-define tracking.
				defined_chars.insert(button_id);

				std::string bp = "button_" + to_string(button_id);

				u16 action_offset = 0;
				char* action_offset_pos = nullptr;

				if (is_button2)
				{
					// TrackAsMenu (UI8) — skip for now
					tag.clearFields();
					tag.setFieldCount(1);
					tag.configureNextField(SWF_FIELD_UI8);
					tag.parseFields(cur_pos);

					// ActionOffset (UI16) — byte offset from this field to first BUTTONCONDACTION
					action_offset_pos = cur_pos;
					tag.clearFields();
					tag.setFieldCount(1);
					tag.configureNextField(SWF_FIELD_UI16);
					tag.parseFields(cur_pos);
					action_offset = (u16) tag.fields[0].value;
				}

				// Collect button records by state
				struct ButtonRecord { u16 char_id; u16 depth; MATRIX matrix; u32 cxform_id; };
				std::vector<ButtonRecord> up_records, over_records, down_records;
				int hit_char_id = -1;
				MATRIX hit_matrix;

				while (true)
				{
					tag.clearFields();
					tag.setFieldCount(1);
					tag.configureNextField(SWF_FIELD_UI8); // flags
					tag.parseFields(cur_pos);

					u8 flags = (u8) tag.fields[0].value;
					if (flags == 0)
						break;

					bool has_blend_mode = is_button2 && (flags & 0x20);
					bool has_filter_list = is_button2 && (flags & 0x10);

					tag.clearFields();
					tag.setFieldCount(2);
					tag.configureNextField(SWF_FIELD_UI16); // CharacterId
					tag.configureNextField(SWF_FIELD_UI16); // PlaceDepth
					tag.parseFields(cur_pos);

					u16 char_id = (u16) tag.fields[0].value;
					u16 depth = (u16) tag.fields[1].value;

					MATRIX matrix;
					parseMatrix(matrix);

					u32 rec_cxform_id = 0;

					if (is_button2)
					{
						// Parse CXFORMWITHALPHA
						u32 cur_byte_bits_left = 8;
						SWFTag cxform_tag;

						cxform_tag.clearFields();
						cxform_tag.setFieldCount(3);
						cxform_tag.configureNextField(SWF_FIELD_UB, 1);
						cxform_tag.configureNextField(SWF_FIELD_UB, 1);
						cxform_tag.configureNextField(SWF_FIELD_UB, 4);
						cxform_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);

						bool has_add = cxform_tag.fields[0].value & 1;
						bool has_mult = cxform_tag.fields[1].value & 1;
						u32 nbits = (u32) cxform_tag.fields[2].value;

						s32 mult_r = 256, mult_g = 256, mult_b = 256, mult_a = 256;
						s32 add_r = 0, add_g = 0, add_b = 0, add_a = 0;

						if (has_mult)
						{
							cxform_tag.clearFields();
							cxform_tag.setFieldCount(4);
							cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
							cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
							cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
							cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
							cxform_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);

							mult_r = (s32) cxform_tag.fields[0].value;
							mult_g = (s32) cxform_tag.fields[1].value;
							mult_b = (s32) cxform_tag.fields[2].value;
							mult_a = (s32) cxform_tag.fields[3].value;
						}

						if (has_add)
						{
							cxform_tag.clearFields();
							cxform_tag.setFieldCount(4);
							cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
							cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
							cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
							cxform_tag.configureNextField(SWF_FIELD_SB, nbits);
							cxform_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);

							add_r = (s32) cxform_tag.fields[0].value;
							add_g = (s32) cxform_tag.fields[1].value;
							add_b = (s32) cxform_tag.fields[2].value;
							add_a = (s32) cxform_tag.fields[3].value;
						}

						if (cur_byte_bits_left != 8)
						{
							cur_pos += 1;
						}

						// Check if cxform is non-identity
						bool is_identity = (mult_r == 256 && mult_g == 256 && mult_b == 256 && mult_a == 256 &&
											add_r == 0 && add_g == 0 && add_b == 0 && add_a == 0);

						if (!is_identity)
						{
							rec_cxform_id = (u32) current_cxform;

							cxform_data << "\t" << to_string(mult_r) << "/256.0f," << endl
										<< "\t" << "0.0f," << endl
										<< "\t" << "0.0f," << endl
										<< "\t" << "0.0f," << endl
										<< "\t" << "0.0f," << endl
										<< "\t" << to_string(mult_g) << "/256.0f," << endl
										<< "\t" << "0.0f," << endl
										<< "\t" << "0.0f," << endl
										<< "\t" << "0.0f," << endl
										<< "\t" << "0.0f," << endl
										<< "\t" << to_string(mult_b) << "/256.0f," << endl
										<< "\t" << "0.0f," << endl
										<< "\t" << "0.0f," << endl
										<< "\t" << "0.0f," << endl
										<< "\t" << "0.0f," << endl
										<< "\t" << to_string(mult_a) << "/256.0f," << endl
										<< "\t" << to_string(add_r) << "/255.0f," << endl
										<< "\t" << to_string(add_g) << "/255.0f," << endl
										<< "\t" << to_string(add_b) << "/255.0f," << endl
										<< "\t" << to_string(add_a) << "/255.0f," << endl;

							current_cxform += 1;
						}

						// Skip FilterList if present
						if (has_filter_list)
						{
							u8 num_filters = *(u8*) cur_pos; cur_pos += 1;
							for (u8 f = 0; f < num_filters; f++)
							{
								u8 filter_id = *(u8*) cur_pos; cur_pos += 1;
								switch (filter_id)
								{
									case 0: cur_pos += 23; break; // DropShadowFilter
									case 1: cur_pos += 9; break;  // BlurFilter
									case 2: cur_pos += 15; break; // GlowFilter
									case 3: cur_pos += 27; break; // BevelFilter
									case 4: // GradientGlowFilter
									{
										u8 nc = *(u8*) cur_pos; cur_pos += 1;
										cur_pos += nc * 5 + 19;
										break;
									}
									case 5: // ConvolutionFilter
									{
										u8 mx = *(u8*) cur_pos; cur_pos += 1;
										u8 my = *(u8*) cur_pos; cur_pos += 1;
										cur_pos += 8 + mx * my * 4 + 5;
										break;
									}
									case 6: cur_pos += 80; break; // ColorMatrixFilter
									case 7: // GradientBevelFilter
									{
										u8 nc = *(u8*) cur_pos; cur_pos += 1;
										cur_pos += nc * 5 + 19;
										break;
									}
								}
							}
						}

						// Skip BlendMode if present
						if (has_blend_mode)
						{
							cur_pos += 1;
						}
					}

					ButtonRecord rec = { char_id, depth, matrix, rec_cxform_id };
					if (flags & 0x01) up_records.push_back(rec);
					if (flags & 0x02) over_records.push_back(rec);
					if (flags & 0x04) down_records.push_back(rec);
					if (flags & 0x08) {
						// Prefer SHAPE/MORPH_SHAPE hit records over sprite/button
						// records — only update hit_char_id if this char is a
						// known shape, OR if we haven't seen any shape yet.
						bool is_shape = context.shape_char_ids.count(char_id) > 0;
						bool prev_is_shape = (hit_char_id >= 0 &&
							context.shape_char_ids.count((u16)hit_char_id) > 0);
						if (is_shape || !prev_is_shape) {
							hit_char_id = char_id;
							hit_matrix = matrix;
						}
					}
				}

				// Fallback: empty states fall back to up
				if (over_records.empty()) over_records = up_records;
				if (down_records.empty()) down_records = over_records;

				// Generate per-state frame functions
				const char* state_names[] = { "up", "over", "down" };
				std::vector<ButtonRecord>* state_records[] = { &up_records, &over_records, &down_records };

				for (int s = 0; s < 3; s++)
				{
					sprite_definitions << "void " << bp << "_frame_" << state_names[s]
									   << "(SWFAppContext* app_context)" << endl
									   << "{" << endl;

					for (auto& rec : *state_records[s])
					{
						size_t transform_id = current_transform;
						recompileMatrix(rec.matrix, transform_data);
						current_transform += 1;

						sprite_definitions << "\t" << "tagPlaceObject2(app_context, "
										   << to_string(rec.depth) << ", "
										   << to_string(rec.char_id) << ", "
										   << to_string(transform_id) << ", "
										   << to_string(rec.cxform_id) << ", 0);" << endl;
					}

					sprite_definitions << "}" << endl << endl;
				}

				// Generate state_funcs array: [up, over, down]
				sprite_forward_decls << "extern frame_func " << bp << "_state_funcs[];" << endl;

				sprite_definitions << "frame_func " << bp << "_state_funcs[] =" << endl
								   << "{" << endl
								   << "\t" << bp << "_frame_up," << endl
								   << "\t" << bp << "_frame_over," << endl
								   << "\t" << bp << "_frame_down," << endl
								   << "};" << endl << endl;

				// Emit hit-test shape transform
				u32 hit_transform_id = 0;
				if (hit_char_id >= 0)
				{
					hit_transform_id = (u32) current_transform;
					recompileMatrix(hit_matrix, transform_data);
					current_transform += 1;
				}

				// Parse button actions
				struct BtnAction { u16 condition; std::string func_name; };
				std::vector<BtnAction> btn_actions;

				if (!is_button2)
				{
					// DefineButton: remaining bytes are a simple ActionRecord sequence
					// firing on OverDownToOverUp (condition bit 4 = 0x0010)
					char* action_end = tag_body_start + button_tag_length;
					if (cur_pos < action_end && *(u8*)cur_pos != 0x00)
					{
						std::string func_name = bp + "_action_" + to_string(next_script_i);
						context.out_script_header << endl << "void " << func_name << "(SWFAppContext* app_context);";

						ofstream out_script(context.output_scripts_folder + "script_" + to_string(next_script_i) + ".c", ios_base::out);
						out_script << "#include <recomp.h>" << endl
								   << "#include <setjmp.h>" << endl
								   << "#include \"script_decls.h\"" << endl << endl
								   << "void " << func_name << "(SWFAppContext* app_context)" << endl
								   << "{" << endl;
						out_script << "\t" << "char str_buffer[17];" << endl << endl;
						out_script << "\t" << "actionResetRegisters();" << endl << endl;
						next_script_i += 1;

						action.parseActions(context, cur_pos, out_script);
						out_script << "}";

						btn_actions.push_back({ 0x0008, func_name }); // OverDownToOverUp
					}
				}
				else if (action_offset > 0 && action_offset_pos != nullptr)
				{
					// DefineButton2: parse BUTTONCONDACTION chain
					char* action_ptr = action_offset_pos + action_offset;

					while (true)
					{
						u16 cond_action_size = *(u16*) action_ptr; action_ptr += 2;
						u16 condition = *(u16*) action_ptr; action_ptr += 2;

						std::string func_name = bp + "_action_" + to_string(next_script_i);
						context.out_script_header << endl << "void " << func_name << "(SWFAppContext* app_context);";

						ofstream out_script(context.output_scripts_folder + "script_" + to_string(next_script_i) + ".c", ios_base::out);
						out_script << "#include <recomp.h>" << endl
								   << "#include <setjmp.h>" << endl
								   << "#include \"script_decls.h\"" << endl << endl
								   << "void " << func_name << "(SWFAppContext* app_context)" << endl
								   << "{" << endl;
						out_script << "\t" << "char str_buffer[17];" << endl << endl;
						out_script << "\t" << "actionResetRegisters();" << endl << endl;
						next_script_i += 1;

						action.parseActions(context, action_ptr, out_script);
						out_script << "}";

						btn_actions.push_back({ condition, func_name });

						if (cond_action_size == 0)
							break; // Last block
					}
				}
				// Generate ButtonAction array (or NULL if no actions)
				if (!btn_actions.empty())
				{
					sprite_forward_decls << "extern ButtonAction " << bp << "_actions[];" << endl;

					sprite_definitions << "ButtonAction " << bp << "_actions[] =" << endl
									   << "{" << endl;
					for (auto& ba : btn_actions)
					{
						sprite_definitions << "\t" << "{ 0x" << std::hex << ba.condition << std::dec
										   << ", " << ba.func_name << " }," << endl;
					}
					sprite_definitions << "};" << endl << endl;
				}

				// Emit tagDefineButton call
				context.tag_main << "\t" << "tagDefineButton(app_context, "
								 << to_string(button_id) << ", "
								 << bp << "_state_funcs, "
								 << to_string(hit_char_id >= 0 ? hit_char_id : 0) << ", "
								 << to_string(hit_transform_id) << ", "
								 << (btn_actions.empty() ? "NULL" : bp + "_actions") << ", "
								 << to_string(btn_actions.size()) << ");" << endl;

				// Skip any remaining bytes
				cur_pos = tag_body_start + button_tag_length;

				break;
			}

			default:
			{
				fprintf(stderr, "Tag type %d not implemented.\n", tag.code);
				break;
			}
		}
		
		num_finished_tags += 1;
	}
	
	u8 rgbLerp(u8 start, u8 end, float t)
	{
		int diff = end - start;
		return (u8) (start + t*diff);
	}

	// sRGB <-> linear conversion for linearRGB gradient interpolation mode
	static float srgbToLinear(float c)
	{
		if (c <= 0.04045f)
			return c / 12.92f;
		return powf((c + 0.055f) / 1.055f, 2.4f);
	}

	static float linearToSrgb(float c)
	{
		if (c <= 0.0031308f)
			return c * 12.92f;
		return 1.055f * powf(c, 1.0f / 2.4f) - 0.055f;
	}

	static u8 linearRgbLerp(u8 start, u8 end, float t)
	{
		float s = srgbToLinear(start / 255.0);
		float e = srgbToLinear(end / 255.0);
		float result = s + t * (e - s);
		return (u8)(linearToSrgb(result) * 255.0f + 0.5f);
	}
	
	void SWF::recompileMatrix(MATRIX matrix, std::stringstream& out)
	{
		out << std::fixed << std::setprecision(15)
			<< "\t" << matrix.scale_x << "f," << endl
			<< "\t" << matrix.rotateskew_0 << "f," << endl
			<< "\t" << "0.0f," << endl
			<< "\t" << "0.0f," << endl

			<< "\t" << matrix.rotateskew_1 << "f," << endl
			<< "\t" << matrix.scale_y << "f," << endl
			<< "\t" << "0.0f," << endl
			<< "\t" << "0.0f," << endl

			<< "\t" << "0.0f," << endl
			<< "\t" << "0.0f," << endl
			<< "\t" << "1.0f," << endl
			<< "\t" << "0.0f," << endl

			<< "\t" << (float) matrix.translate_x << "f," << endl
			<< "\t" << (float) matrix.translate_y << "f," << endl
			<< "\t" << "0.0f," << endl
			<< "\t" << "1.0f," << endl;
	}

	// Emit a SWF gradient MATRIX as a 4x4 forward matrix that maps normalized
	// gradient UVs in [0,1] (not SWF's native [-16384,+16384]) to shape coords.
	// The runtime's vertex shader uses the (compute-shader-inverted) matrix to
	// compute `linear_t = apply_spread(inv_pos.x, ...)` and `apply_spread` for
	// pad mode clamps to [0,1], so an un-normalized matrix collapses the entire
	// shape to the two gradient endpoints. (See render_webgpu.c
	// "normalization baked into inverse matrix" for the matching dynamic path.)
	// Bakes M_new = M_old * N^-1 where N^-1 = diag(32768,32768,1,1) with
	// translate column (-16384,-16384,0,1), equivalent to substituting
	// grad_coord = uv * 32768 - 16384 into the old forward matrix.
	void SWF::recompileGradientMatrix(MATRIX matrix, std::stringstream& out)
	{
		float new_scale_x       = 32768.0f * matrix.scale_x;
		float new_rotateskew_0  = 32768.0f * matrix.rotateskew_0;
		float new_rotateskew_1  = 32768.0f * matrix.rotateskew_1;
		float new_scale_y       = 32768.0f * matrix.scale_y;
		float new_translate_x   = -16384.0f * matrix.scale_x
		                          - 16384.0f * matrix.rotateskew_1
		                          + (float) matrix.translate_x;
		float new_translate_y   = -16384.0f * matrix.rotateskew_0
		                          - 16384.0f * matrix.scale_y
		                          + (float) matrix.translate_y;
		out << std::fixed << std::setprecision(15)
			<< "\t" << new_scale_x       << "f," << endl
			<< "\t" << new_rotateskew_0  << "f," << endl
			<< "\t" << "0.0f," << endl
			<< "\t" << "0.0f," << endl

			<< "\t" << new_rotateskew_1  << "f," << endl
			<< "\t" << new_scale_y       << "f," << endl
			<< "\t" << "0.0f," << endl
			<< "\t" << "0.0f," << endl

			<< "\t" << "0.0f," << endl
			<< "\t" << "0.0f," << endl
			<< "\t" << "1.0f," << endl
			<< "\t" << "0.0f," << endl

			<< "\t" << new_translate_x   << "f," << endl
			<< "\t" << new_translate_y   << "f," << endl
			<< "\t" << "0.0f," << endl
			<< "\t" << "1.0f," << endl;
	}
	
	FillStyle* SWF::parseFillStyles(u16 fill_style_count)
	{
		SWFTag fill_data;
		
		FillStyle* fill_styles = new FillStyle[fill_style_count];
		
		for (u16 i = 0; i < fill_style_count; ++i)
		{
			fill_data.clearFields();
			fill_data.setFieldCount(1);
			
			fill_data.configureNextField(SWF_FIELD_UI8, 8);
			
			fill_data.parseFields(cur_pos);
			
			fill_styles[i].type = (u8) fill_data.fields[0].value;
			
			switch (fill_styles[i].type)
			{
				case FILL_SOLID:
				{
					if (shape_has_alpha)
					{
						RGBA.parseFields(cur_pos);

						fill_styles[i].r = (u8) RGBA.fields[0].value;
						fill_styles[i].g = (u8) RGBA.fields[1].value;
						fill_styles[i].b = (u8) RGBA.fields[2].value;
						fill_styles[i].a = (u8) RGBA.fields[3].value;
					}
					else
					{
						RGB.parseFields(cur_pos);

						fill_styles[i].r = (u8) RGB.fields[0].value;
						fill_styles[i].g = (u8) RGB.fields[1].value;
						fill_styles[i].b = (u8) RGB.fields[2].value;
						fill_styles[i].a = 255;
					}

					fill_styles[i].index = current_color;

					color_data << "\t" << "{ "
							   << to_string(fill_styles[i].r) << "/255.0f, "
							   << to_string(fill_styles[i].g) << "/255.0f, "
							   << to_string(fill_styles[i].b) << "/255.0f, "
							   << to_string(fill_styles[i].a) << "/255.0f }," << endl;

					current_color += 1;

					break;
				}
				
				case FILL_GRAD_LINEAR:
				case FILL_GRAD_RADIAL:
				case FILL_GRAD_FOCAL:
				{
					MATRIX matrix;
					parseMatrix(matrix);

					recompileGradientMatrix(matrix, uninv_mat_data);
					current_uninv += 1;

					fill_data.clearFields();
					fill_data.setFieldCount(1);

					fill_data.configureNextField(SWF_FIELD_UI8);

					fill_data.parseFields(cur_pos);

					fill_styles[i].gradient.spread_mode = (u8) ((fill_data.fields[0].value & 0b11000000) >> 6);
					fill_styles[i].gradient.interpolation_mode = (u8) ((fill_data.fields[0].value & 0b00110000) >> 4);
					fill_styles[i].gradient.num_grads = (u8) (fill_data.fields[0].value & 0b00001111);

					bool use_linear_rgb = (fill_styles[i].gradient.interpolation_mode == 1);

					for (int j = 0; j < fill_styles[i].gradient.num_grads; ++j)
					{
						fill_data.clearFields();
						fill_data.setFieldCount(1);

						fill_data.configureNextField(SWF_FIELD_UI8);

						fill_data.parseFields(cur_pos);

						fill_styles[i].gradient.records[j].ratio = (u8) fill_data.fields[0].value;

						if (shape_has_alpha)
						{
							RGBA.parseFields(cur_pos);

							fill_styles[i].gradient.records[j].r = (u8) RGBA.fields[0].value;
							fill_styles[i].gradient.records[j].g = (u8) RGBA.fields[1].value;
							fill_styles[i].gradient.records[j].b = (u8) RGBA.fields[2].value;
							fill_styles[i].gradient.records[j].a = (u8) RGBA.fields[3].value;
						}
						else
						{
							RGB.parseFields(cur_pos);

							fill_styles[i].gradient.records[j].r = (u8) RGB.fields[0].value;
							fill_styles[i].gradient.records[j].g = (u8) RGB.fields[1].value;
							fill_styles[i].gradient.records[j].b = (u8) RGB.fields[2].value;
							fill_styles[i].gradient.records[j].a = 255;
						}

						if (j == 0)
						{
							continue;
						}

						GradientRecord& last_grad = fill_styles[i].gradient.records[j - 1];
						GradientRecord& grad = fill_styles[i].gradient.records[j];

						for (u8 ratio = last_grad.ratio; ratio < grad.ratio; ++ratio)
						{
							float ratio_diff = (float) (grad.ratio - last_grad.ratio);
							float t = (ratio - last_grad.ratio)/ratio_diff;

							u8 r = use_linear_rgb ? linearRgbLerp(last_grad.r, grad.r, t) : rgbLerp(last_grad.r, grad.r, t);
							u8 g = use_linear_rgb ? linearRgbLerp(last_grad.g, grad.g, t) : rgbLerp(last_grad.g, grad.g, t);
							u8 b = use_linear_rgb ? linearRgbLerp(last_grad.b, grad.b, t) : rgbLerp(last_grad.b, grad.b, t);
							u8 a = rgbLerp(last_grad.a, grad.a, t);

							gradient_data << "\t" << "{ "
										  << to_string(r) << ", "
										  << to_string(g) << ", "
										  << to_string(b) << ", "
										  << to_string(a) << " },"
										  << endl;
						}

						if (grad.ratio == 255)
						{
							float ratio_diff = (float) (grad.ratio - last_grad.ratio);
							float t = (255 - last_grad.ratio)/ratio_diff;

							u8 r = use_linear_rgb ? linearRgbLerp(last_grad.r, grad.r, t) : rgbLerp(last_grad.r, grad.r, t);
							u8 g = use_linear_rgb ? linearRgbLerp(last_grad.g, grad.g, t) : rgbLerp(last_grad.g, grad.g, t);
							u8 b = use_linear_rgb ? linearRgbLerp(last_grad.b, grad.b, t) : rgbLerp(last_grad.b, grad.b, t);
							u8 a = rgbLerp(last_grad.a, grad.a, t);

							gradient_data << "\t" << "{ "
										  << to_string(r) << ", "
										  << to_string(g) << ", "
										  << to_string(b) << ", "
										  << to_string(a) << " },"
										  << endl;
						}
					}

					fill_styles[i].index = current_gradient;

					// Parse focal point for FOCALGRADIENT (fill type 0x13)
					if (fill_styles[i].type == FILL_GRAD_FOCAL)
					{
						fill_data.clearFields();
						fill_data.setFieldCount(1);

						fill_data.configureNextField(SWF_FIELD_UI16);

						fill_data.parseFields(cur_pos);

						// FIXED8: signed 8.8 fixed-point, value / 256.0
						s16 focal_fixed8 = (s16) fill_data.fields[0].value;
						float focal_point = (float) focal_fixed8 / 256.0f;

						// Encode focal point in upper 16 bits of index
						// Shader decodes: focal = (style_upper - 32768) / 16384.0
						u16 focal_encoded = (u16) (focal_point * 16384.0f + 32768.0f);
						fill_styles[i].index |= ((size_t) focal_encoded << 16);
					}

					current_gradient += 1;

					break;
				}

				case FILL_BITMAP_REPEAT:
				case FILL_BITMAP_CLIPPED:
				case FILL_BITMAP_REPEAT_NONSMOOTH:
				case FILL_BITMAP_CLIPPED_NONSMOOTH:
				{
					fill_data.clearFields();
					fill_data.setFieldCount(1);
					
					fill_data.configureNextField(SWF_FIELD_UI16);
					
					fill_data.parseFields(cur_pos);
					
					u16 char_id = (u16) fill_data.fields[0].value;
					
					fill_styles[i].index = ((current_uninv & 0xFFFF) << 16) | char_id_to_bitmap_id[char_id];
					
					MATRIX matrix;
					parseMatrix(matrix);
					
					recompileMatrix(matrix, uninv_mat_data);
					current_uninv += 1;
					
					break;
				}
			}
		}
		
		return fill_styles;
	}
	
	LineStyle* SWF::parseLineStyles(u16 line_style_count)
	{
		SWFTag line_data;

		LineStyle* line_styles = new LineStyle[line_style_count];

		for (u16 i = 0; i < line_style_count; ++i)
		{
			if (shape_is_v4)
			{
				// LINESTYLE2 format
				// Width: UI16
				line_data.clearFields();
				line_data.setFieldCount(1);

				line_data.configureNextField(SWF_FIELD_UI16, 16);

				line_data.parseFields(cur_pos);

				line_styles[i].width = (u16) line_data.fields[0].value;

				// StartCapStyle(UB2), JoinStyle(UB2), HasFillFlag(UB1),
				// NoHScaleFlag(UB1), NoVScaleFlag(UB1), PixelHintingFlag(UB1)
				line_data.clearFields();
				line_data.setFieldCount(1);

				line_data.configureNextField(SWF_FIELD_UI8, 8);

				line_data.parseFields(cur_pos);

				u8 flags1 = (u8) line_data.fields[0].value;
				u8 join_style = (flags1 >> 4) & 0x03;
				bool has_fill = (flags1 >> 3) & 0x01;

				// Reserved(UB5), NoClose(UB1), EndCapStyle(UB2)
				line_data.clearFields();
				line_data.setFieldCount(1);

				line_data.configureNextField(SWF_FIELD_UI8, 8);

				line_data.parseFields(cur_pos);

				// MiterLimitFactor: FIXED8 (only if JoinStyle == 2)
				if (join_style == 2)
				{
					line_data.clearFields();
					line_data.setFieldCount(1);

					line_data.configureNextField(SWF_FIELD_UI16, 16);

					line_data.parseFields(cur_pos);

					// Miter limit parsed and ignored for now
				}

				if (!has_fill)
				{
					// Color: RGBA
					RGBA.parseFields(cur_pos);

					line_styles[i].r = (u8) RGBA.fields[0].value;
					line_styles[i].g = (u8) RGBA.fields[1].value;
					line_styles[i].b = (u8) RGBA.fields[2].value;
					line_styles[i].a = (u8) RGBA.fields[3].value;
				}
				else
				{
					// FillType: FILLSTYLE - parse and extract color for basic rendering
					// For now, skip the fill style and use a default color
					FillStyle* fill = parseFillStyles(1);

					line_styles[i].r = fill[0].r;
					line_styles[i].g = fill[0].g;
					line_styles[i].b = fill[0].b;
					line_styles[i].a = fill[0].a;

					delete[] fill;
				}
			}
			else if (shape_has_alpha)
			{
				line_data.clearFields();
				line_data.setFieldCount(5);

				line_data.configureNextField(SWF_FIELD_UI16, 16);
				line_data.configureNextField(SWF_FIELD_UI8, 8);
				line_data.configureNextField(SWF_FIELD_UI8, 8);
				line_data.configureNextField(SWF_FIELD_UI8, 8);
				line_data.configureNextField(SWF_FIELD_UI8, 8);

				line_data.parseFields(cur_pos);

				line_styles[i].width = (u16) line_data.fields[0].value;
				line_styles[i].r = (u8) line_data.fields[1].value;
				line_styles[i].g = (u8) line_data.fields[2].value;
				line_styles[i].b = (u8) line_data.fields[3].value;
				line_styles[i].a = (u8) line_data.fields[4].value;
			}
			else
			{
				line_data.clearFields();
				line_data.setFieldCount(4);

				line_data.configureNextField(SWF_FIELD_UI16, 16);
				line_data.configureNextField(SWF_FIELD_UI8, 8);
				line_data.configureNextField(SWF_FIELD_UI8, 8);
				line_data.configureNextField(SWF_FIELD_UI8, 8);

				line_data.parseFields(cur_pos);

				line_styles[i].width = (u16) line_data.fields[0].value;
				line_styles[i].r = (u8) line_data.fields[1].value;
				line_styles[i].g = (u8) line_data.fields[2].value;
				line_styles[i].b = (u8) line_data.fields[3].value;
				line_styles[i].a = 255;
			}

			line_styles[i].index = current_color;

			color_data << "\t" << "{ "
					   << to_string(line_styles[i].r) << "/255.0f, "
					   << to_string(line_styles[i].g) << "/255.0f, "
					   << to_string(line_styles[i].b) << "/255.0f, "
					   << to_string(line_styles[i].a) << "/255.0f }," << endl;

			current_color += 1;
		}

		return line_styles;
	}

	FillStyle* SWF::parseMorphFillStyles(u16 fill_style_count)
	{
		SWFTag fill_data;

		FillStyle* fill_styles = new FillStyle[fill_style_count];

		for (u16 i = 0; i < fill_style_count; ++i)
		{
			fill_data.clearFields();
			fill_data.setFieldCount(1);

			fill_data.configureNextField(SWF_FIELD_UI8, 8);

			fill_data.parseFields(cur_pos);

			fill_styles[i].type = (u8) fill_data.fields[0].value;

			switch (fill_styles[i].type)
			{
				case FILL_SOLID:
				{
					// StartColor (RGBA)
					RGBA.parseFields(cur_pos);

					fill_styles[i].r = (u8) RGBA.fields[0].value;
					fill_styles[i].g = (u8) RGBA.fields[1].value;
					fill_styles[i].b = (u8) RGBA.fields[2].value;
					fill_styles[i].a = (u8) RGBA.fields[3].value;

					// EndColor (RGBA)
					RGBA.parseFields(cur_pos);

					u8 end_r = (u8) RGBA.fields[0].value;
					u8 end_g = (u8) RGBA.fields[1].value;
					u8 end_b = (u8) RGBA.fields[2].value;
					u8 end_a = (u8) RGBA.fields[3].value;

					fill_styles[i].index = current_color;

					color_data << "\t" << "{ "
							   << to_string(fill_styles[i].r) << "/255.0f, "
							   << to_string(fill_styles[i].g) << "/255.0f, "
							   << to_string(fill_styles[i].b) << "/255.0f, "
							   << to_string(fill_styles[i].a) << "/255.0f }," << endl;

					current_color += 1;

					morph_end_color_data << "\t" << "{ "
							   << to_string(end_r) << "/255.0f, "
							   << to_string(end_g) << "/255.0f, "
							   << to_string(end_b) << "/255.0f, "
							   << to_string(end_a) << "/255.0f }," << endl;

					current_morph_end_color += 1;

					break;
				}

				case FILL_GRAD_LINEAR:
				case FILL_GRAD_RADIAL:
				case FILL_GRAD_FOCAL:
				{
					// StartGradientMatrix
					MATRIX matrix;
					parseMatrix(matrix);

					recompileGradientMatrix(matrix, uninv_mat_data);
					current_uninv += 1;

					// Skip EndGradientMatrix
					MATRIX end_matrix;
					parseMatrix(end_matrix);

					// Morph gradient count is a plain UI8 (no spread/interp mode bits)
					fill_data.clearFields();
					fill_data.setFieldCount(1);

					fill_data.configureNextField(SWF_FIELD_UI8);

					fill_data.parseFields(cur_pos);

					fill_styles[i].gradient.spread_mode = 0;
					fill_styles[i].gradient.interpolation_mode = 0;
					fill_styles[i].gradient.num_grads = (u8) fill_data.fields[0].value;

					for (int j = 0; j < fill_styles[i].gradient.num_grads; ++j)
					{
						// StartRatio (UI8)
						fill_data.clearFields();
						fill_data.setFieldCount(1);

						fill_data.configureNextField(SWF_FIELD_UI8);

						fill_data.parseFields(cur_pos);

						fill_styles[i].gradient.records[j].ratio = (u8) fill_data.fields[0].value;

						// StartColor (RGBA)
						RGBA.parseFields(cur_pos);

						fill_styles[i].gradient.records[j].r = (u8) RGBA.fields[0].value;
						fill_styles[i].gradient.records[j].g = (u8) RGBA.fields[1].value;
						fill_styles[i].gradient.records[j].b = (u8) RGBA.fields[2].value;
						fill_styles[i].gradient.records[j].a = (u8) RGBA.fields[3].value;

						// Skip EndRatio (1 byte) + EndColor (4 bytes) = 5 bytes
						cur_pos += 5;

						if (j == 0)
						{
							continue;
						}

						GradientRecord& last_grad = fill_styles[i].gradient.records[j - 1];
						GradientRecord& grad = fill_styles[i].gradient.records[j];

						for (u8 ratio = last_grad.ratio; ratio < grad.ratio; ++ratio)
						{
							float ratio_diff = (float) (grad.ratio - last_grad.ratio);
							float t = (ratio - last_grad.ratio)/ratio_diff;

							u8 r = rgbLerp(last_grad.r, grad.r, t);
							u8 g = rgbLerp(last_grad.g, grad.g, t);
							u8 b = rgbLerp(last_grad.b, grad.b, t);
							u8 a = rgbLerp(last_grad.a, grad.a, t);

							gradient_data << "\t" << "{ "
										  << to_string(r) << ", "
										  << to_string(g) << ", "
										  << to_string(b) << ", "
										  << to_string(a) << " },"
										  << endl;
						}

						if (grad.ratio == 255)
						{
							float ratio_diff = (float) (grad.ratio - last_grad.ratio);
							float t = (255 - last_grad.ratio)/ratio_diff;

							u8 r = rgbLerp(last_grad.r, grad.r, t);
							u8 g = rgbLerp(last_grad.g, grad.g, t);
							u8 b = rgbLerp(last_grad.b, grad.b, t);
							u8 a = rgbLerp(last_grad.a, grad.a, t);

							gradient_data << "\t" << "{ "
										  << to_string(r) << ", "
										  << to_string(g) << ", "
										  << to_string(b) << ", "
										  << to_string(a) << " },"
										  << endl;
						}
					}

					fill_styles[i].index = current_gradient;

					if (fill_styles[i].type == FILL_GRAD_FOCAL)
					{
						fill_data.clearFields();
						fill_data.setFieldCount(1);

						fill_data.configureNextField(SWF_FIELD_UI16);

						fill_data.parseFields(cur_pos);

						s16 focal_fixed8 = (s16) fill_data.fields[0].value;
						float focal_point = (float) focal_fixed8 / 256.0f;

						u16 focal_encoded = (u16) (focal_point * 16384.0f + 32768.0f);
						fill_styles[i].index |= ((size_t) focal_encoded << 16);
					}

					current_gradient += 1;

					break;
				}

				case FILL_BITMAP_REPEAT:
				case FILL_BITMAP_CLIPPED:
				case FILL_BITMAP_REPEAT_NONSMOOTH:
				case FILL_BITMAP_CLIPPED_NONSMOOTH:
				{
					fill_data.clearFields();
					fill_data.setFieldCount(1);

					fill_data.configureNextField(SWF_FIELD_UI16);

					fill_data.parseFields(cur_pos);

					u16 char_id = (u16) fill_data.fields[0].value;

					fill_styles[i].index = ((current_uninv & 0xFFFF) << 16) | char_id_to_bitmap_id[char_id];

					// StartBitmapMatrix
					MATRIX matrix;
					parseMatrix(matrix);

					recompileMatrix(matrix, uninv_mat_data);
					current_uninv += 1;

					// Skip EndBitmapMatrix
					MATRIX end_matrix;
					parseMatrix(end_matrix);

					break;
				}
			}
		}

		return fill_styles;
	}

	LineStyle* SWF::parseMorphLineStyles(u16 line_style_count)
	{
		SWFTag line_data;

		LineStyle* line_styles = new LineStyle[line_style_count];

		for (u16 i = 0; i < line_style_count; ++i)
		{
			// StartWidth (UI16)
			line_data.clearFields();
			line_data.setFieldCount(1);

			line_data.configureNextField(SWF_FIELD_UI16, 16);

			line_data.parseFields(cur_pos);

			line_styles[i].width = (u16) line_data.fields[0].value;

			// EndWidth (UI16)
			line_data.clearFields();
			line_data.setFieldCount(1);
			line_data.configureNextField(SWF_FIELD_UI16, 16);
			line_data.parseFields(cur_pos);
			line_styles[i].end_width = (u16) line_data.fields[0].value;

			if (shape_is_morph2)
			{
				// MorphLineStyle2: caps, joins, flags
				// StartCapStyle(UB2), JoinStyle(UB2), HasFillFlag(UB1),
				// NoHScaleFlag(UB1), NoVScaleFlag(UB1), PixelHintingFlag(UB1)
				line_data.clearFields();
				line_data.setFieldCount(1);
				line_data.configureNextField(SWF_FIELD_UI8, 8);
				line_data.parseFields(cur_pos);

				u8 flags1 = (u8) line_data.fields[0].value;
				u8 join_style = (flags1 >> 4) & 0x03;
				bool has_fill = (flags1 >> 3) & 0x01;

				// Reserved(UB5), NoClose(UB1), EndCapStyle(UB2)
				line_data.clearFields();
				line_data.setFieldCount(1);
				line_data.configureNextField(SWF_FIELD_UI8, 8);
				line_data.parseFields(cur_pos);

				// MiterLimitFactor: FIXED8 (only if JoinStyle == 2)
				if (join_style == 2)
				{
					line_data.clearFields();
					line_data.setFieldCount(1);
					line_data.configureNextField(SWF_FIELD_UI16, 16);
					line_data.parseFields(cur_pos);
				}

				if (has_fill)
				{
					// StartFillType — parse as a single fill style (reuse parseFillStyles for 1 entry)
					// For simplicity, skip it — extract solid color equivalent
					// FillStyleType (UI8) + color/gradient/bitmap data
					line_data.clearFields();
					line_data.setFieldCount(1);
					line_data.configureNextField(SWF_FIELD_UI8, 8);
					line_data.parseFields(cur_pos);

					u8 fill_type = (u8) line_data.fields[0].value;
					if (fill_type == 0x00)
					{
						// Solid fill: StartColor (RGBA)
						RGBA.parseFields(cur_pos);
						line_styles[i].r = (u8) RGBA.fields[0].value;
						line_styles[i].g = (u8) RGBA.fields[1].value;
						line_styles[i].b = (u8) RGBA.fields[2].value;
						line_styles[i].a = (u8) RGBA.fields[3].value;

						// EndFillType: same structure — skip EndColor (RGBA)
						line_data.clearFields();
						line_data.setFieldCount(1);
						line_data.configureNextField(SWF_FIELD_UI8, 8);
						line_data.parseFields(cur_pos);
						cur_pos += 4; // skip EndColor RGBA
					}
					else
					{
						// Non-solid fill in morph line — not commonly used, fall back to black
						line_styles[i].r = 0;
						line_styles[i].g = 0;
						line_styles[i].b = 0;
						line_styles[i].a = 255;
						// Skip remaining fill data — advance to next line style is imprecise
						// This should be handled more thoroughly if needed
					}
				}
				else
				{
					// StartColor (RGBA)
					RGBA.parseFields(cur_pos);
					line_styles[i].r = (u8) RGBA.fields[0].value;
					line_styles[i].g = (u8) RGBA.fields[1].value;
					line_styles[i].b = (u8) RGBA.fields[2].value;
					line_styles[i].a = (u8) RGBA.fields[3].value;

					// EndColor (RGBA) — skip
					cur_pos += 4;
				}
			}
			else
			{
				// MorphLineStyle1: StartColor (RGBA)
				RGBA.parseFields(cur_pos);
				line_styles[i].r = (u8) RGBA.fields[0].value;
				line_styles[i].g = (u8) RGBA.fields[1].value;
				line_styles[i].b = (u8) RGBA.fields[2].value;
				line_styles[i].a = (u8) RGBA.fields[3].value;

				// Skip EndColor (RGBA = 4 bytes)
				cur_pos += 4;
			}

			line_styles[i].index = current_color;

			color_data << "\t" << "{ "
					   << to_string(line_styles[i].r) << "/255.0f, "
					   << to_string(line_styles[i].g) << "/255.0f, "
					   << to_string(line_styles[i].b) << "/255.0f, "
					   << to_string(line_styles[i].a) << "/255.0f }," << endl;

			current_color += 1;
		}

		return line_styles;
	}

	void SWF::interpretShape(Context& context, SWFTag& shape_tag)
	{
		bool is_font = (shape_tag.code == SWF_TAG_DEFINE_FONT || shape_tag.code == SWF_TAG_DEFINE_FONT_2 || shape_tag.code == SWF_TAG_DEFINE_FONT_3);
		bool is_morph = (shape_tag.code == SWF_TAG_DEFINE_MORPH_SHAPE || shape_tag.code == SWF_TAG_DEFINE_MORPH_SHAPE_2);
		bool is_morph2 = (shape_tag.code == SWF_TAG_DEFINE_MORPH_SHAPE_2);
		shape_has_alpha = (shape_tag.code == SWF_TAG_DEFINE_SHAPE_3 || shape_tag.code == SWF_TAG_DEFINE_SHAPE_4 || is_morph);
		shape_is_v4 = (shape_tag.code == SWF_TAG_DEFINE_SHAPE_4);
		shape_is_morph2 = is_morph2;

		switch (shape_tag.code)
		{
			case SWF_TAG_DEFINE_SHAPE:
			case SWF_TAG_DEFINE_SHAPE_2:
			case SWF_TAG_DEFINE_SHAPE_3:
			case SWF_TAG_DEFINE_SHAPE_4:
			case SWF_TAG_DEFINE_MORPH_SHAPE:
			case SWF_TAG_DEFINE_MORPH_SHAPE_2:
			case SWF_TAG_DEFINE_FONT:
			case SWF_TAG_DEFINE_FONT_2:
			case SWF_TAG_DEFINE_FONT_3:
			{
				u16 shape_id;
				u16 fill_style_count;
				std::vector<FillStyle*> all_fill_styles;
				std::vector<u16> all_fill_style_counts;
				u16 line_style_count;
				std::vector<LineStyle*> all_line_styles;
				size_t morph_color_start_saved = current_color;
				size_t morph_end_color_before = current_morph_end_color;
				s32 shape_bounds_xmin = 0, shape_bounds_xmax = 0;
				s32 shape_bounds_ymin = 0, shape_bounds_ymax = 0;
				s32 morph_end_bounds_xmin = 0, morph_end_bounds_xmax = 0;
				s32 morph_end_bounds_ymin = 0, morph_end_bounds_ymax = 0;
				
				// Save position at start of tag body for morph EndEdges skip
				char* morph_tag_start = cur_pos;

				if (!is_font)
				{
					shape_tag.clearFields();
					shape_tag.setFieldCount(6);

					shape_tag.configureNextField(SWF_FIELD_UI16, 16);
					shape_tag.configureNextField(SWF_FIELD_UB, 5, true);
					shape_tag.configureNextField(SWF_FIELD_SB, 0);
					shape_tag.configureNextField(SWF_FIELD_SB, 0);
					shape_tag.configureNextField(SWF_FIELD_SB, 0);
					shape_tag.configureNextField(SWF_FIELD_SB, 0);

					shape_tag.parseFields(cur_pos);

					shape_id = (u16) shape_tag.fields[0].value;
					shape_bounds_xmin = (s32) shape_tag.fields[2].value;
					shape_bounds_xmax = (s32) shape_tag.fields[3].value;
					shape_bounds_ymin = (s32) shape_tag.fields[4].value;
					shape_bounds_ymax = (s32) shape_tag.fields[5].value;

					// Track this char_id as a shape (SHAPE or MORPH_SHAPE) so
					// DefineButton2 can prefer shape hit records over sprite ones.
					context.shape_char_ids.insert(shape_id);

					// Register shape/morph/font char_id for place-before-define tracking.
					defined_chars.insert(shape_id);

					if (shape_is_v4)
					{
						// DefineShape4 has an additional EdgeBounds RECT after ShapeBounds
						shape_tag.clearFields();
						shape_tag.setFieldCount(5);

						shape_tag.configureNextField(SWF_FIELD_UB, 5, true);
						shape_tag.configureNextField(SWF_FIELD_SB, 0);
						shape_tag.configureNextField(SWF_FIELD_SB, 0);
						shape_tag.configureNextField(SWF_FIELD_SB, 0);
						shape_tag.configureNextField(SWF_FIELD_SB, 0);

						shape_tag.parseFields(cur_pos);

						// EdgeBounds parsed and ignored (used for player optimization only)

						// Flags byte: Reserved(UB5) + UsesFillWindingRule(UB1) + UsesNonScalingStrokes(UB1) + UsesScalingStrokes(UB1)
						shape_tag.clearFields();
						shape_tag.setFieldCount(1);

						shape_tag.configureNextField(SWF_FIELD_UI8, 8);

						shape_tag.parseFields(cur_pos);

						// Extract UsesFillWindingRule flag (bit 2)
						int uses_fill_winding_rule = ((int)shape_tag.fields[0].value >> 2) & 1;
						if (uses_fill_winding_rule)
						{
							context.tag_main << "\t" << "ng_record_char_winding(" << to_string(shape_id) << ");" << endl;
						}
					}

					if (is_morph)
					{
						// DefineMorphShape: parse EndBounds RECT
						shape_tag.clearFields();
						shape_tag.setFieldCount(5);

						shape_tag.configureNextField(SWF_FIELD_UB, 5, true);
						shape_tag.configureNextField(SWF_FIELD_SB, 0);
						shape_tag.configureNextField(SWF_FIELD_SB, 0);
						shape_tag.configureNextField(SWF_FIELD_SB, 0);
						shape_tag.configureNextField(SWF_FIELD_SB, 0);

						shape_tag.parseFields(cur_pos);

						// Extract end bounds for morph interpolation
						morph_end_bounds_xmin = (s32) shape_tag.fields[1].value;
						morph_end_bounds_xmax = (s32) shape_tag.fields[2].value;
						morph_end_bounds_ymin = (s32) shape_tag.fields[3].value;
						morph_end_bounds_ymax = (s32) shape_tag.fields[4].value;

						if (is_morph2)
						{
							// DefineMorphShape2 extra fields (before Offset per SWF spec):
							// StartEdgeBounds RECT (parse and ignore)
							shape_tag.clearFields();
							shape_tag.setFieldCount(5);
							shape_tag.configureNextField(SWF_FIELD_UB, 5, true);
							shape_tag.configureNextField(SWF_FIELD_SB, 0);
							shape_tag.configureNextField(SWF_FIELD_SB, 0);
							shape_tag.configureNextField(SWF_FIELD_SB, 0);
							shape_tag.configureNextField(SWF_FIELD_SB, 0);
							shape_tag.parseFields(cur_pos);

							// EndEdgeBounds RECT (parse and ignore)
							shape_tag.clearFields();
							shape_tag.setFieldCount(5);
							shape_tag.configureNextField(SWF_FIELD_UB, 5, true);
							shape_tag.configureNextField(SWF_FIELD_SB, 0);
							shape_tag.configureNextField(SWF_FIELD_SB, 0);
							shape_tag.configureNextField(SWF_FIELD_SB, 0);
							shape_tag.configureNextField(SWF_FIELD_SB, 0);
							shape_tag.parseFields(cur_pos);

							// Flags byte: Reserved(UB6) + UsesNonScalingStrokes(UB1) + UsesScalingStrokes(UB1)
							shape_tag.clearFields();
							shape_tag.setFieldCount(1);
							shape_tag.configureNextField(SWF_FIELD_UI8, 8);
							shape_tag.parseFields(cur_pos);
							// Flags parsed and ignored
						}

						// Offset (UI32) - distance from end of Offset to EndEdges
						shape_tag.clearFields();
						shape_tag.setFieldCount(1);

						shape_tag.configureNextField(SWF_FIELD_UI32, 32);

						shape_tag.parseFields(cur_pos);

						// Offset parsed and ignored (we skip EndEdges using tag length)
					}

					// FILLSTYLEARRAY
					shape_tag.clearFields();
					shape_tag.setFieldCount(1);

					shape_tag.configureNextField(SWF_FIELD_UI8, 8);

					shape_tag.parseFields(cur_pos);

					fill_style_count = (u8) shape_tag.fields[0].value;

					if (fill_style_count == 0xFF)
					{
						shape_tag.clearFields();

						shape_tag.configureNextField(SWF_FIELD_UI16, 16);

						shape_tag.parseFields(cur_pos);

						fill_style_count = (u16) shape_tag.fields[0].value;
					}

					if (is_morph)
					{
						all_fill_styles.push_back(parseMorphFillStyles(fill_style_count));
					}
					else
					{
						all_fill_styles.push_back(parseFillStyles(fill_style_count));
					}
					all_fill_style_counts.push_back(fill_style_count);

					// LINESTYLEARRAY
					shape_tag.clearFields();
					shape_tag.setFieldCount(1);

					shape_tag.configureNextField(SWF_FIELD_UI8, 8);

					shape_tag.parseFields(cur_pos);

					line_style_count = (u8) shape_tag.fields[0].value;
					
					if (line_style_count == 0xFF)
					{
						shape_tag.clearFields();
						
						shape_tag.configureNextField(SWF_FIELD_UI16, 16);
						
						shape_tag.parseFields(cur_pos);
						
						line_style_count = (u16) shape_tag.fields[0].value;
					}
					
					if (is_morph)
					{
						all_line_styles.push_back(parseMorphLineStyles(line_style_count));
					}
					else
					{
						all_line_styles.push_back(parseLineStyles(line_style_count));
					}
				}

				else
				{
					fill_style_count = 1;
					line_style_count = 0;
					
					FillStyle* fill_style = new FillStyle[fill_style_count];

					all_fill_styles.push_back(fill_style);
					all_fill_style_counts.push_back(fill_style_count);

					fill_style->r = 0xFF;
					fill_style->g = 0xFF;
					fill_style->b = 0xFF;
					
					fill_style->type = 0x00;
					fill_style->index = current_color;
					
					color_data << "\t" << "{ "
							   << to_string(fill_style->r) << "/255.0f, "
							   << to_string(fill_style->g) << "/255.0f, "
							   << to_string(fill_style->b) << "/255.0f, "
							   << "255/255.0f }," << endl;
					
					current_color += 1;
				}
				
				shape_tag.clearFields();
				shape_tag.setFieldCount(2);
				
				shape_tag.configureNextField(SWF_FIELD_UB, 4);
				shape_tag.configureNextField(SWF_FIELD_UB, 4);
				
				shape_tag.parseFields(cur_pos);
				
				u8 fill_bits = (u8) shape_tag.fields[0].value;
				u8 line_bits = (u8) shape_tag.fields[1].value;
				
				u32 current_fill_style_list = 0;
				u32 current_line_style_list = 0;

				u32 last_fill_style_0 = 0;
				u32 last_fill_style_1 = 0;

				u32 last_line_style = 0;

				std::vector<Path> paths;
				paths.reserve(512);

				Path* current_path = nullptr;

				s32 last_x = 0;
				s32 last_y = FRAME_HEIGHT;

				u32 cur_byte_bits_left = 8;

				// Path data recording: capture raw edge commands for vector-path hit testing.
				// Format: float path_data[][3] = {cmd, param1, param2}
				// Commands:
				//   {1, fill0_idx, fill1_idx}  — StyleChange (fill styles)
				//   {1.5, line_idx, line_width} — StyleChange (line style, width in local twips)
				//   {2, x, y}                   — LineTo
				//   {3, ctrl_x, ctrl_y}         — CurveTo control (followed by anchor)
				//   {4, anchor_x, anchor_y}     — CurveTo anchor
				//   {5, x, y}                   — MoveTo
				//   {0, 0, 0}                   — End of paths for this character
				bool path_recording = !is_font;
				size_t path_start = current_path_entry;

				// For morph shapes, buffer path commands for deferred interleaved emission
				std::vector<std::array<float, 3>> morph_start_buf;
				std::vector<float> morph_end_widths_buf;
				std::vector<std::array<float, 3>> morph_end_geo_buf;

				auto emitPath = [&](float cmd, float a, float b) {
					if (!path_recording) return;
					if (is_morph) {
						morph_start_buf.push_back({cmd, a, b});
					} else {
						path_data << "\t{" << std::fixed << std::setprecision(1)
						          << cmd << "f, " << a << "f, " << b << "f},\n";
						current_path_entry++;
					}
				};

				s32 morph_vertex_counter = 0;
				size_t edge_iterations = 0;
				const size_t max_edge_iterations = 1000000;

				while (true)
				{
					if (++edge_iterations > max_edge_iterations)
					{
						fprintf(stderr, "Warning: shape edge parsing exceeded %zu iterations, skipping rest of shape\n", max_edge_iterations);
						break;
					}

					shape_tag.clearFields();
					shape_tag.setFieldCount(2);

					shape_tag.configureNextField(SWF_FIELD_UB, 1);
					shape_tag.configureNextField(SWF_FIELD_UB, 5);

					shape_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);

					bool is_edge_record = (u8) shape_tag.fields[0].value;
					u8 state_flags = (u8) shape_tag.fields[1].value;

					if (is_edge_record)
					{
						// Ensure a path exists (some shapes emit edges before any StyleChangeRecord)
						if (current_path == nullptr)
						{
							paths.push_back(Path());
							current_path = &paths.back();
							current_path->verts.reserve(512);
							current_path->fill_style_list = current_fill_style_list;
							current_path->line_style_list = current_line_style_list;
							current_path->fill_styles[0] = last_fill_style_0;
							current_path->fill_styles[1] = last_fill_style_1;
							current_path->line_style = last_line_style;
							current_path->self_closed = false;

							Vertex v;
							v.x = last_x;
							v.y = last_y;
							if (is_morph) v.morph_index = morph_vertex_counter++;
							current_path->verts.push_back(v);
						}

						bool is_straight_edge = (state_flags & 0b10000) != 0;
						u8 num_bits = (u8) state_flags & 0xF;
						
						if (is_straight_edge)
						{
							// StraightEdgeRecord
							
							shape_tag.clearFields();
							shape_tag.setFieldCount(1);
							
							shape_tag.configureNextField(SWF_FIELD_UB, 1);
							
							shape_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);
							
							bool is_general_line = (shape_tag.fields[0].value & 1) != 0;
							
							if (is_general_line)
							{
								shape_tag.clearFields();
								shape_tag.setFieldCount(2);
								
								shape_tag.configureNextField(SWF_FIELD_SB, num_bits + 2);
								shape_tag.configureNextField(SWF_FIELD_SB, num_bits + 2);
								
								shape_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);
								
								s16 delta_x = (s16) shape_tag.fields[0].value;
								s16 delta_y = (s16) shape_tag.fields[1].value;

								Vertex v;
								v.x = last_x + (s32) delta_x;
								v.y = last_y - (s32) delta_y;
								if (is_morph) v.morph_index = morph_vertex_counter++;

								current_path->verts.push_back(v);

								// Emit LineTo path command
								emitPath(2.0f, (float)v.x, (float)(FRAME_HEIGHT - v.y));

								last_x = v.x;
								last_y = v.y;

								continue;
							}

							shape_tag.clearFields();
							shape_tag.setFieldCount(2);

							shape_tag.configureNextField(SWF_FIELD_UB, 1);
							shape_tag.configureNextField(SWF_FIELD_SB, num_bits + 2);
							
							shape_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);
							
							bool is_vertical_line = (shape_tag.fields[0].value & 1) != 0;
							s16 delta = (s16) shape_tag.fields[1].value;

							Vertex v;

							v.x = last_x;
							v.y = last_y;

							if (is_vertical_line)
							{
								v.y -= (s32) delta;
							}

							else
							{
								v.x += (s32) delta;
							}

							if (is_morph) v.morph_index = morph_vertex_counter++;

							current_path->verts.push_back(v);

							// Emit LineTo path command
							emitPath(2.0f, (float)v.x, (float)(FRAME_HEIGHT - v.y));

							last_x = v.x;
							last_y = v.y;

							continue;
						}

						// CurvedEdgeRecord
						
						shape_tag.clearFields();
						shape_tag.setFieldCount(4);
						
						shape_tag.configureNextField(SWF_FIELD_SB, num_bits + 2);
						shape_tag.configureNextField(SWF_FIELD_SB, num_bits + 2);
						shape_tag.configureNextField(SWF_FIELD_SB, num_bits + 2);
						shape_tag.configureNextField(SWF_FIELD_SB, num_bits + 2);
						
						shape_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);
						
						s16 control_delta_x = (s16) shape_tag.fields[0].value;
						s16 control_delta_y = (s16) shape_tag.fields[1].value;
						s16 anchor_delta_x = (s16) shape_tag.fields[2].value;
						s16 anchor_delta_y = (s16) shape_tag.fields[3].value;
						
						Vertex current;
						current.x = last_x;
						current.y = last_y;
						
						Vertex control;
						control.x = last_x + control_delta_x;
						control.y = last_y - control_delta_y;
						
						Vertex anchor;
						anchor.x = control.x + anchor_delta_x;
						anchor.y = control.y - anchor_delta_y;
						
						u32 num_passes = 6;

						// Emit CurveTo path command (control + anchor, before subdivision)
						emitPath(3.0f, (float)control.x, (float)(FRAME_HEIGHT - control.y));
						emitPath(4.0f, (float)anchor.x, (float)(FRAME_HEIGHT - anchor.y));

						addCurvedEdge(current_path, current, control, anchor, num_passes, is_morph ? &morph_vertex_counter : nullptr);

						last_x = anchor.x;
						last_y = anchor.y;

						continue;
					}
					
					if (state_flags == 0)
					{
						// EndShapeRecord
						emitPath(0.0f, 0.0f, 0.0f);  // End marker for path data
						break;
					}
					
					// StyleChangeRecord
					
					// StateNewStyles is only used by DefineShape2, DefineShape3, and DefineShape4
					bool state_new_styles = (state_flags & 0b10000) != 0;
					bool state_line_style = !is_font && (state_flags & 0b01000) != 0;
					bool state_fill_style_1 = (state_flags & 0b00100) != 0;
					bool state_fill_style_0 = (state_flags & 0b00010) != 0;
					bool state_move_to = (state_flags & 0b00001) != 0;
					
					shape_tag.clearFields();
					shape_tag.setFieldCount(3*state_move_to + state_fill_style_0 + state_fill_style_1 + state_line_style);
					
					if (state_move_to)
					{
						shape_tag.configureNextField(SWF_FIELD_UB, 5, true);
						shape_tag.configureNextField(SWF_FIELD_SB, 0);
						shape_tag.configureNextField(SWF_FIELD_SB, 0);
					}
					
					if (state_fill_style_0)
					{
						shape_tag.configureNextField(SWF_FIELD_UB, fill_bits);
					}
					
					if (state_fill_style_1)
					{
						shape_tag.configureNextField(SWF_FIELD_UB, fill_bits);
					}
					
					if (state_line_style)
					{
						shape_tag.configureNextField(SWF_FIELD_UB, line_bits);
					}
					
					shape_tag.parseFieldsContinue(cur_pos, cur_byte_bits_left);
					
					u8 move_bits;
					u32 move_delta_x;
					u32 move_delta_y;
					
					u32 fill_style_0 = last_fill_style_0;
					u32 fill_style_1 = last_fill_style_1;
					
					u32 line_style = last_line_style;
					
					bool fill_style_0_change = false;
					bool fill_style_1_change = false;
					
					bool line_style_change = false;
					
					size_t current_field = 0;
					
					if (state_move_to)
					{
						move_bits = (u8) shape_tag.fields[current_field++].value;
						move_delta_x = (u32) shape_tag.fields[current_field++].value;
						move_delta_y = (u32) shape_tag.fields[current_field++].value;
						
						last_x = move_delta_x;
						last_y = FRAME_HEIGHT - move_delta_y;
					}
					
					if (state_fill_style_0)
					{
						fill_style_0 = (u32) shape_tag.fields[current_field++].value;
						
						fill_style_0_change = fill_style_0 != last_fill_style_0;
					}
					
					if (state_fill_style_1)
					{
						fill_style_1 = (u32) shape_tag.fields[current_field++].value;
						
						fill_style_1_change = fill_style_1 != last_fill_style_1;
					}
					
					if (state_line_style)
					{
						line_style = (u32) shape_tag.fields[current_field++].value;
						
						line_style_change = line_style != last_line_style;
					}
					
					if (state_new_styles)
					{
						if (cur_byte_bits_left != 8)
						{
							cur_pos += 1;
							cur_byte_bits_left = 8;
						}
						
						// FILLSTYLEARRAY
						shape_tag.clearFields();
						shape_tag.setFieldCount(1);
						
						shape_tag.configureNextField(SWF_FIELD_UI8, 8);
						
						shape_tag.parseFields(cur_pos);
						
						u16 fill_style_count = (u8) shape_tag.fields[0].value;
						
						if (fill_style_count == 0xFF)
						{
							shape_tag.clearFields();
							
							shape_tag.configureNextField(SWF_FIELD_UI16, 16);
							
							shape_tag.parseFields(cur_pos);
							
							fill_style_count = (u16) shape_tag.fields[0].value;
						}
						
						all_fill_styles.push_back(parseFillStyles(fill_style_count));
						all_fill_style_counts.push_back(fill_style_count);

						current_fill_style_list += 1;
						
						// LINESTYLEARRAY
						shape_tag.clearFields();
						shape_tag.setFieldCount(1);
						
						shape_tag.configureNextField(SWF_FIELD_UI8, 8);
						
						shape_tag.parseFields(cur_pos);
						
						u16 line_style_count = (u8) shape_tag.fields[0].value;
						
						if (line_style_count == 0xFF)
						{
							shape_tag.clearFields();
							
							shape_tag.configureNextField(SWF_FIELD_UI16, 16);
							
							shape_tag.parseFields(cur_pos);
							
							line_style_count = (u16) shape_tag.fields[0].value;
						}
						
						all_line_styles.push_back(parseLineStyles(line_style_count));
						
						current_line_style_list += 1;
						
						shape_tag.clearFields();
						shape_tag.setFieldCount(2);
						
						shape_tag.configureNextField(SWF_FIELD_UB, 4);
						shape_tag.configureNextField(SWF_FIELD_UB, 4);
						
						shape_tag.parseFields(cur_pos);
						
						fill_bits = (u8) shape_tag.fields[0].value;
						line_bits = (u8) shape_tag.fields[1].value;
					}
					
					if (state_new_styles || state_move_to || fill_style_0_change || fill_style_1_change || line_style_change)
					{
						if (paths.size() > 0 && paths.back().verts.size() == 1)
						{
							paths.pop_back();
						}

						paths.push_back(Path());
						current_path = &paths.back();

						current_path->verts.reserve(512);
						current_path->fill_style_list = current_fill_style_list;
						current_path->line_style_list = current_line_style_list;
						current_path->fill_styles[0] = fill_style_0;
						current_path->fill_styles[1] = fill_style_1;
						current_path->line_style = line_style;
						current_path->self_closed = false;

						Vertex v;
						v.x = last_x;
						v.y = last_y;
						if (is_morph) v.morph_index = morph_vertex_counter++;

						current_path->verts.push_back(v);

						// Emit path style change + moveto
						if (path_recording && (fill_style_0_change || fill_style_1_change || state_new_styles || state_move_to))
						{
							emitPath(1.0f, (float)fill_style_0, (float)fill_style_1);
							// Line style with width
							float line_width = 0.0f;
							float end_line_width = 0.0f;
							if (line_style != 0 && current_line_style_list < all_line_styles.size()) {
								LineStyle* ls = all_line_styles[current_line_style_list];
								if (line_style - 1 < line_style_count) {
									line_width = (float)ls[line_style - 1].width;
									if (is_morph) end_line_width = (float)ls[line_style - 1].end_width;
								}
							}
							emitPath(1.5f, (float)line_style, line_width);
							if (is_morph) morph_end_widths_buf.push_back(end_line_width);
							// MoveTo
							float mx = (float)last_x;
							float my = (float)(FRAME_HEIGHT - last_y);
							emitPath(5.0f, mx, my);
						}
					}

					last_fill_style_0 = fill_style_0;
					last_fill_style_1 = fill_style_1;

					last_line_style = line_style;
				}
				
				if (cur_byte_bits_left != 8)
				{
					cur_pos += 1;
				}

				// Parse end edges for morph shapes
				std::vector<Vertex> morph_end_positions;
				if (is_morph)
				{
					// End edges header: NumFillBits(4) + NumLineBits(4) = 1 byte, both 0
					shape_tag.clearFields();
					shape_tag.setFieldCount(2);
					shape_tag.configureNextField(SWF_FIELD_UB, 4);
					shape_tag.configureNextField(SWF_FIELD_UB, 4);
					shape_tag.parseFields(cur_pos);

					s32 end_last_x = 0;
					s32 end_last_y = FRAME_HEIGHT;
					u32 end_bits_left = 8;
					size_t end_edge_iterations = 0;

					while (true)
					{
						if (++end_edge_iterations > max_edge_iterations)
						{
							fprintf(stderr, "Warning: morph end-edge parsing exceeded %zu iterations, skipping rest\n", max_edge_iterations);
							break;
						}

						shape_tag.clearFields();
						shape_tag.setFieldCount(2);
						shape_tag.configureNextField(SWF_FIELD_UB, 1);
						shape_tag.configureNextField(SWF_FIELD_UB, 5);
						shape_tag.parseFieldsContinue(cur_pos, end_bits_left);

						bool end_is_edge = (u8) shape_tag.fields[0].value;
						u8 end_flags = (u8) shape_tag.fields[1].value;

						if (end_is_edge)
						{
							bool end_is_straight = (end_flags & 0b10000) != 0;
							u8 end_num_bits = end_flags & 0xF;

							if (end_is_straight)
							{
								shape_tag.clearFields();
								shape_tag.setFieldCount(1);
								shape_tag.configureNextField(SWF_FIELD_UB, 1);
								shape_tag.parseFieldsContinue(cur_pos, end_bits_left);

								bool end_general = (shape_tag.fields[0].value & 1) != 0;

								if (end_general)
								{
									shape_tag.clearFields();
									shape_tag.setFieldCount(2);
									shape_tag.configureNextField(SWF_FIELD_SB, end_num_bits + 2);
									shape_tag.configureNextField(SWF_FIELD_SB, end_num_bits + 2);
									shape_tag.parseFieldsContinue(cur_pos, end_bits_left);

									s16 dx = (s16) shape_tag.fields[0].value;
									s16 dy = (s16) shape_tag.fields[1].value;

									Vertex ev;
									ev.x = end_last_x + (s32) dx;
									ev.y = end_last_y - (s32) dy;
									morph_end_positions.push_back(ev);
									if (path_recording) morph_end_geo_buf.push_back({2.0f, (float)ev.x, (float)(FRAME_HEIGHT - ev.y)});

									end_last_x = ev.x;
									end_last_y = ev.y;
								}
								else
								{
									shape_tag.clearFields();
									shape_tag.setFieldCount(2);
									shape_tag.configureNextField(SWF_FIELD_UB, 1);
									shape_tag.configureNextField(SWF_FIELD_SB, end_num_bits + 2);
									shape_tag.parseFieldsContinue(cur_pos, end_bits_left);

									bool end_vert = (shape_tag.fields[0].value & 1) != 0;
									s16 delta = (s16) shape_tag.fields[1].value;

									Vertex ev;
									ev.x = end_last_x;
									ev.y = end_last_y;
									if (end_vert)
										ev.y -= (s32) delta;
									else
										ev.x += (s32) delta;
									morph_end_positions.push_back(ev);
									if (path_recording) morph_end_geo_buf.push_back({2.0f, (float)ev.x, (float)(FRAME_HEIGHT - ev.y)});

									end_last_x = ev.x;
									end_last_y = ev.y;
								}
							}
							else
							{
								// CurvedEdge in end shape
								shape_tag.clearFields();
								shape_tag.setFieldCount(4);
								shape_tag.configureNextField(SWF_FIELD_SB, end_num_bits + 2);
								shape_tag.configureNextField(SWF_FIELD_SB, end_num_bits + 2);
								shape_tag.configureNextField(SWF_FIELD_SB, end_num_bits + 2);
								shape_tag.configureNextField(SWF_FIELD_SB, end_num_bits + 2);
								shape_tag.parseFieldsContinue(cur_pos, end_bits_left);

								s16 cdx = (s16) shape_tag.fields[0].value;
								s16 cdy = (s16) shape_tag.fields[1].value;
								s16 adx = (s16) shape_tag.fields[2].value;
								s16 ady = (s16) shape_tag.fields[3].value;

								Vertex cur_v;
								cur_v.x = end_last_x;
								cur_v.y = end_last_y;

								Vertex ctrl;
								ctrl.x = end_last_x + cdx;
								ctrl.y = end_last_y - cdy;

								Vertex anch;
								anch.x = ctrl.x + adx;
								anch.y = ctrl.y - ady;

								// Capture raw curve for morph path hit testing
								if (path_recording) {
									morph_end_geo_buf.push_back({3.0f, (float)ctrl.x, (float)(FRAME_HEIGHT - ctrl.y)});
									morph_end_geo_buf.push_back({4.0f, (float)anch.x, (float)(FRAME_HEIGHT - anch.y)});
								}

								u32 passes = 6;
								for (u32 p = 1; p <= passes; ++p)
								{
									float ft = (float) p / passes;
									float fu = 1.0f - ft;
									Vertex ev;
									ev.x = (s32)(fu*fu*cur_v.x + 2*fu*ft*ctrl.x + ft*ft*anch.x);
									ev.y = (s32)(fu*fu*cur_v.y + 2*fu*ft*ctrl.y + ft*ft*anch.y);
									morph_end_positions.push_back(ev);
								}

								end_last_x = anch.x;
								end_last_y = anch.y;
							}

							continue;
						}

						if (end_flags == 0)
						{
							// EndShapeRecord
							break;
						}

						// StyleChangeRecord in end shape (only MoveTo)
						bool end_move = (end_flags & 0b00001) != 0;
						if (end_move)
						{
							shape_tag.clearFields();
							shape_tag.setFieldCount(3);
							shape_tag.configureNextField(SWF_FIELD_UB, 5, true);
							shape_tag.configureNextField(SWF_FIELD_SB, 0);
							shape_tag.configureNextField(SWF_FIELD_SB, 0);
							shape_tag.parseFieldsContinue(cur_pos, end_bits_left);

							end_last_x = (s32) shape_tag.fields[1].value;
							end_last_y = FRAME_HEIGHT - (s32) shape_tag.fields[2].value;

							Vertex ev;
							ev.x = end_last_x;
							ev.y = end_last_y;
							morph_end_positions.push_back(ev);
							if (path_recording) morph_end_geo_buf.push_back({5.0f, (float)end_last_x, (float)(FRAME_HEIGHT - end_last_y)});
						}
					}

					if (end_bits_left != 8)
					{
						cur_pos += 1;
					}
				}

				if (current_path == nullptr)
				{
					return;
				}
				
				std::vector<Shape> shapes;
				
				std::vector<Node> nodes;
				
				constructEdges(paths, nodes);

				for (size_t i = 0; i < paths.size(); ++i)
				{
					// Phase 1: auto-close an open path with a one-sided fill so it can
					// emit fill triangles. earcut implicitly closes the contour, and
					// processShape's signed_area wraps from last vert to verts[0]. We
					// build the Shape from the open path's verts directly — paths[i].verts
					// stays unchanged so the stroke pass below still emits the polyline
					// without a synthetic closing edge. Gate on >=3 verts to skip
					// degenerate cases (R1.1).
					bool has_fill = (paths[i].fill_styles[0] != 0 || paths[i].fill_styles[1] != 0);
					bool fill_open_path = (!paths[i].self_closed && has_fill && paths[i].verts.size() >= 3);

					if (!(paths[i].self_closed || fill_open_path))
					{
						continue;
					}

					std::vector<Vertex> initial_verts;
					for (size_t k = 0; k < paths[i].verts.size(); ++k)
					{
						if (!initial_verts.empty() &&
							initial_verts.back().x == paths[i].verts[k].x &&
							initial_verts.back().y == paths[i].verts[k].y)
						{
							continue;
						}

						initial_verts.push_back(paths[i].verts[k]);
					}

					// Phase 2: split self-touching closed polygons at touch points.
					// earcut handles a single contour as if it had no self-intersections;
					// fed a figure-8 / pinched polygon it triangulates the merged shape
					// (one diagonal across the pinch + naive fan), not the SWF even-odd
					// fill of two sub-loops. Splitting at each non-consecutive vertex
					// repeat yields independent contours; the existing Phase B
					// containment pass decides hole vs fill spatially.
					//
					// Natural-closure (k=0, m=N-1) is skipped — that's just verts[0]
					// equalling the closing wrap target, not a self-touch. Both sub-loops
					// must end with >=3 verts so neither becomes a degenerate triangle.
					std::vector<std::vector<Vertex>> sub_loops;
					sub_loops.push_back(std::move(initial_verts));

					for (size_t s = 0; s < sub_loops.size(); ++s)
					{
						// Edge-edge intersection pre-pass: convert interior edge
						// crossings into vertex touches by inserting the crossing
						// point as a new vertex on both edges. The vertex-touch split
						// below then handles them. Without this, sub-loops produced
						// by the touch-vertex split can still be self-intersecting
						// (e.g. shape_test's "P-shape" sub-loop has its closing edge
						// (20,30)→(20,10) crossing (10,20)→(30,20) at (20,20)),
						// which earcut triangulates incorrectly.
						//
						// Open paths (Phase 1's case): close them with V[0] so the
						// implicit wrap-around edge participates in intersection
						// detection. earcut and processShape are agnostic to whether
						// V[N-1] equals V[0].
						{
							std::vector<Vertex>& V = sub_loops[s];
							if (!V.empty() &&
								(V.back().x != V.front().x || V.back().y != V.front().y))
							{
								V.push_back(V.front());
							}
							size_t M = V.size();
							if (M >= 4)
							{
								struct EdgeIntersection
								{
									size_t edge;
									double t;
									Vertex point;
								};
								std::vector<EdgeIntersection> intersections;
								size_t num_edges = M - 1;

								for (size_t ei = 0; ei + 2 < num_edges; ++ei)
								{
									for (size_t ej = ei + 2; ej < num_edges; ++ej)
									{
										const Vertex& a1 = V[ei];
										const Vertex& a2 = V[ei + 1];
										const Vertex& b1 = V[ej];
										const Vertex& b2 = V[ej + 1];

										s64 dx1 = (s64) a2.x - a1.x;
										s64 dy1 = (s64) a2.y - a1.y;
										s64 dx2 = (s64) b2.x - b1.x;
										s64 dy2 = (s64) b2.y - b1.y;

										s64 denom = dx1 * dy2 - dy1 * dx2;
										if (denom == 0)
										{
											continue;
										}

										s64 num_t = ((s64) b1.x - a1.x) * dy2 - ((s64) b1.y - a1.y) * dx2;
										s64 num_s = ((s64) b1.x - a1.x) * dy1 - ((s64) b1.y - a1.y) * dx1;

										// Strict interior: 0 < t < 1 and 0 < s < 1.
										// (denominator sign is folded into the comparison.)
										bool t_in = (denom > 0) ? (num_t > 0 && num_t < denom)
										                        : (num_t < 0 && num_t > denom);
										bool s_in = (denom > 0) ? (num_s > 0 && num_s < denom)
										                        : (num_s < 0 && num_s > denom);

										if (!t_in || !s_in)
										{
											continue;
										}

										double t = (double) num_t / (double) denom;
										double s_param = (double) num_s / (double) denom;

										Vertex p;
										p.x = (s32) std::lround((double) a1.x + t * (double) dx1);
										p.y = (s32) std::lround((double) a1.y + t * (double) dy1);
										p.morph_index = -1;

										intersections.push_back({ ei, t, p });
										intersections.push_back({ ej, s_param, p });
									}
								}

								if (!intersections.empty())
								{
									std::sort(intersections.begin(), intersections.end(),
										[](const EdgeIntersection& a, const EdgeIntersection& b)
										{
											if (a.edge != b.edge) return a.edge < b.edge;
											return a.t < b.t;
										});

									std::vector<Vertex> new_verts;
									new_verts.reserve(M + intersections.size());
									size_t isect_idx = 0;
									for (size_t v = 0; v < num_edges; ++v)
									{
										new_verts.push_back(V[v]);
										while (isect_idx < intersections.size() && intersections[isect_idx].edge == v)
										{
											const Vertex& p = intersections[isect_idx].point;
											if (new_verts.back().x != p.x || new_verts.back().y != p.y)
											{
												new_verts.push_back(p);
											}
											isect_idx++;
										}
									}
									new_verts.push_back(V[num_edges]);

									sub_loops[s] = std::move(new_verts);
								}
							}
						}

						while (true)
						{
							std::vector<Vertex>& V = sub_loops[s];
							size_t N = V.size();
							if (N < 6)
							{
								break;
							}

							bool found = false;
							size_t found_k = 0;
							size_t found_m = 0;
							for (size_t k = 0; k + 2 < N && !found; ++k)
							{
								for (size_t m = k + 2; m < N; ++m)
								{
									if (V[k].x != V[m].x || V[k].y != V[m].y)
									{
										continue;
									}
									if (k == 0 && m == N - 1)
									{
										continue;
									}
									size_t inner_count = m - k;
									size_t outer_count = N - (m - k);
									if (inner_count < 3 || outer_count < 3)
									{
										continue;
									}
									found_k = k;
									found_m = m;
									found = true;
									break;
								}
							}

							if (!found)
							{
								break;
							}

							std::vector<Vertex> inner(V.begin() + found_k, V.begin() + found_m + 1);
							std::vector<Vertex> outer(V.begin(), V.begin() + found_k + 1);
							outer.insert(outer.end(), V.begin() + found_m + 1, V.end());

							// `V` becomes invalid once we push (vector may reallocate);
							// finish all reads of `V` before this point.
							sub_loops[s] = std::move(outer);
							sub_loops.push_back(std::move(inner));
						}
					}

					for (auto& V : sub_loops)
					{
						shapes.push_back(Shape());
						shapes.back().closed = true;
						shapes.back().hole = false;
						shapes.back().invalid = false;
						shapes.back().nesting_depth = 0;
						shapes.back().verts = std::move(V);

						processShape(shapes.back(), paths[i].fill_styles);

						shapes.back().fill_style_list = paths[i].fill_style_list;

						if (paths[i].fill_styles[shapes.back().fill_right] == 0 && paths[i].fill_styles[!shapes.back().fill_right] != 0)
						{
							// Phase A: defer outer/hole decision to the containment pass.
							// Always flip to the non-zero fill side; the containment pass
							// below decides whether this shape is a positive fill or a hole
							// based on spatial containment + same-fill parent matching.
							shapes.back().fill_right = !shapes.back().fill_right;
							shapes.back().inner_fill = paths[i].fill_styles[shapes.back().fill_right];
						}
					}
				}
				
				std::vector<Path> path_stack;
				std::unordered_map<Node*, bool> blocked;
				std::unordered_map<Node*, std::vector<Node*>> blocked_map;
				std::vector<std::vector<Path>> closed_paths;
				
				johnson(nodes, path_stack, blocked, blocked_map, closed_paths);
				
				size_t shape_cycles_start = shapes.size();
				
				for (auto cycle : closed_paths)
				{
					shapes.push_back(Shape());
					shapes.back().closed = true;
					shapes.back().hole = false;
					shapes.back().invalid = false;
					shapes.back().nesting_depth = 0;
					
					for (size_t j = 0; j < cycle.size(); ++j)
					{
						size_t start = (cycle[j].backward) ? cycle[j].verts.size() - 2 : 1;
						size_t offset = (cycle[j].backward) ? -1 : 1;
						
						for (size_t k = start; k < cycle[j].verts.size(); k += offset)
						{
							if (shapes.back().verts.size() > 0 &&
								shapes.back().verts.back().x == cycle[j].verts[k].x &&
								shapes.back().verts.back().y == cycle[j].verts[k].y)
							{
								continue;
							}
							
							shapes.back().verts.push_back(cycle[j].verts[k]);
						}
					}
					
					processShape(shapes.back(), cycle[0].fill_styles);
					
					shapes.back().fill_style_list = cycle[0].fill_style_list;
				}
				
				for (size_t i = 0; i < closed_paths.size(); ++i)
				{
					Shape& shape = shapes[shape_cycles_start + i];
					std::vector<Path>& cycle = closed_paths[i];
					
					u32 last_fill_style = fill_style_count + 1;
					
					for (size_t j = 0; j < cycle.size(); ++j)
					{
						Path& p = cycle[j];
						if (last_fill_style == fill_style_count + 1)
						{
							last_fill_style = p.fill_styles[shape.fill_right];
							continue;
						}
						
						if (last_fill_style != p.fill_styles[shape.fill_right ^ p.backward])
						{
							shape.invalid = true;
							break;
						}
					}
					
					// TODO: look for holes here too?
				}
				
				for (size_t i = 0; i < shapes.size(); ++i)
				{
					if (shapes[i].verts.size() < 3)
					{
						shapes[i].invalid = true;
					}
				}
				
				auto compareArea = [](const Shape& a, const Shape& b)
				{
					u64 width = a.max.x - a.min.x;
					u64 height = a.max.y - a.min.y;
					
					u64 area_a = width*height;
					
					width = b.max.x - b.min.x;
					height = b.max.y - b.min.y;
					
					u64 area_b = width*height;
					
					return area_a > area_b;
				};
				
				auto compareAreaPtr = [](const Shape* a, const Shape* b)
				{
					u64 width = a->max.x - a->min.x;
					u64 height = a->max.y - a->min.y;
					
					u64 area_a = width*height;
					
					width = b->max.x - b->min.x;
					height = b->max.y - b->min.y;
					
					u64 area_b = width*height;
					
					return area_a > area_b;
				};
				
				// Sort shapes by area of bounding box
				std::sort(shapes.begin(), shapes.end(), compareArea);
				
				// Phase B: even-odd nesting parity. Process shapes largest-first
				// (the sort above is by area descending). For each shape, find
				// its smallest spatial parent. If that parent has the same
				// inner_fill, this shape sits inside a same-color ring, so its
				// nesting depth is parent->depth + 1. Under the even-odd fill
				// rule (SWF default), odd-depth shapes become holes of their
				// immediate parent; even-depth shapes stay as positive fills
				// that may in turn carry their own holes (depth+1 children).
				//
				// Different-color spatial containment breaks the same-fill chain
				// and resets depth to 0 — the inner shape is a smaller filled
				// region painted on top, not a hole of the outer.
				//
				// Non-zero winding rule (DefineShape4 + UsesFillWindingRule) is
				// not implemented here; we'd need to aggregate per-path signed
				// crossings along the parent chain. Defer until a driver test
				// exercises it.
				for (size_t i = 0; i < shapes.size(); ++i)
				{
					if (shapes[i].invalid || shapes[i].hole || shapes[i].inner_fill == 0)
					{
						continue;
					}

					Shape& candidate = shapes[i];

					std::vector<Shape*> outer_candidates;

					for (size_t j = 0; j < shapes.size(); ++j)
					{
						if (i == j || shapes[j].invalid || shapes[j].inner_fill == 0)
						{
							continue;
						}

						Shape& test_shape = shapes[j];

						if (test_shape.min.x < candidate.min.x && test_shape.max.x > candidate.max.x &&
							test_shape.min.y < candidate.min.y && test_shape.max.y > candidate.max.y)
						{
							outer_candidates.push_back(&test_shape);
						}
					}

					std::vector<Shape*> final_outer_candidates;

					for (Shape* c : outer_candidates)
					{
						bool v_in_c = true;

						for (const Vertex& v : candidate.verts)
						{
							if (!isInShape(v, c))
							{
								v_in_c = false;
								break;
							}
						}

						if (v_in_c)
						{
							final_outer_candidates.push_back(c);
						}
					}

					std::sort(final_outer_candidates.begin(), final_outer_candidates.end(), compareAreaPtr);

					if (!final_outer_candidates.empty())
					{
						Shape* parent = final_outer_candidates.back();
						if (parent->inner_fill == candidate.inner_fill)
						{
							candidate.nesting_depth = parent->nesting_depth + 1;
							if (candidate.nesting_depth & 1u)
							{
								candidate.hole = true;
								parent->holes.push_back(&candidate);
							}
						}
					}
				}
				
				size_t tris_size = 0;
				size_t morph_end_start_vertex = current_morph_end_vertex;

				for (size_t i = 0; i < shapes.size(); ++i)
				{
					if (!shapes[i].invalid && shapes[i].closed && shapes[i].inner_fill != 0 && !shapes[i].hole)
					{
						// Bounds check: ensure fill_style_list and inner_fill index are valid
						if (shapes[i].fill_style_list >= all_fill_styles.size() ||
							shapes[i].inner_fill > all_fill_style_counts[shapes[i].fill_style_list])
						{
							continue;
						}

						std::vector<Tri> tris;

						fillShape(shapes[i], tris);

						tris_size += tris.size();

						for (Tri t : tris)
						{
							for (int j = 0; j < 3; ++j)
							{
								float x_f = (float) t.verts[j].x;
								float y_f = (float) (FRAME_HEIGHT - t.verts[j].y);

								FillStyle& fs = all_fill_styles[shapes[i].fill_style_list][shapes[i].inner_fill - 1];
								// Encode spread_mode in bits 8-9 of the style type for gradients
								u32 style_type_packed = (u32) fs.type;
								if (fs.type == FILL_GRAD_LINEAR || fs.type == FILL_GRAD_RADIAL || fs.type == FILL_GRAD_FOCAL)
								{
									style_type_packed |= ((u32) fs.gradient.spread_mode << 8);
								}

								shape_data << "\t" << "{ "
										   << std::hex << std::uppercase
										   << "0x" << VAL(u32, &x_f) << ", "
										   << "0x" << VAL(u32, &y_f) << ", "
										   << "0x" << style_type_packed << ", "
										   << "0x" << (u32) fs.index
										   << " }," << endl;

								if (is_morph && t.verts[j].morph_index >= 0 && (size_t)t.verts[j].morph_index < morph_end_positions.size())
								{
									Vertex& end_v = morph_end_positions[t.verts[j].morph_index];
									float end_x_f = (float) end_v.x;
									float end_y_f = (float) (FRAME_HEIGHT - end_v.y);
									morph_end_shape_data << "\t" << "{ "
														 << std::dec << std::fixed << std::setprecision(1)
														 << end_x_f << "f, "
														 << end_y_f << "f"
														 << " }," << endl;
								}
								else if (is_morph)
								{
									// Fallback: use start position
									morph_end_shape_data << "\t" << "{ "
														 << std::dec << std::fixed << std::setprecision(1)
														 << x_f << "f, "
														 << y_f << "f"
														 << " }," << endl;
								}

								if (is_morph)
								{
									current_morph_end_vertex += 1;
								}
							}
						}
					}
				}

				for (size_t i = 0; i < paths.size(); ++i)
				{
					u8 line_style_i = paths[i].line_style;

					if (line_style_i != 0)
					{
						LineStyle line_style = all_line_styles[paths[i].line_style_list][line_style_i - 1];

						std::vector<Tri> tris;

						drawLines(paths[i], line_style.width, tris);

						tris_size += tris.size();

						for (Tri t : tris)
						{
							for (int j = 0; j < 3; ++j)
							{
								float x_f = (float) t.verts[j].x;
								float y_f = (float) (FRAME_HEIGHT - t.verts[j].y);

								shape_data << "\t" << "{ "
										   << std::hex << std::uppercase
										   << "0x" << VAL(u32, &x_f) << ", "
										   << "0x" << VAL(u32, &y_f) << ", "
										   << "0x80000000, "
										   << "0x" << (u32) line_style.index
										   << " }," << endl;
							}
						}
					}
				}

				if (!is_font)
				{
					if (is_morph)
					{
						size_t morph_color_count = current_morph_end_color - morph_end_color_before;
						context.tag_main << "\t" << "tagDefineMorphShape(app_context, "
										 << std::dec
										 << to_string(shape_id) << ", "
										 << to_string(3*current_tri) << ", "
										 << to_string(3*tris_size) << ", "
										 << to_string(morph_end_start_vertex) << ", "
										 << to_string(morph_color_start_saved) << ", "
										 << to_string(morph_color_count) << ", "
										 << to_string(shape_bounds_xmin) << ", "
										 << to_string(shape_bounds_xmax) << ", "
										 << to_string(shape_bounds_ymin) << ", "
										 << to_string(shape_bounds_ymax) << ", "
										 << to_string(morph_end_bounds_xmin) << ", "
										 << to_string(morph_end_bounds_xmax) << ", "
										 << to_string(morph_end_bounds_ymin) << ", "
										 << to_string(morph_end_bounds_ymax) << ");" << endl;
					}
					else
					{
						context.tag_main << "\t" << "tagDefineShape(app_context, CHAR_TYPE_SHAPE, " << to_string(shape_id) << ", " << to_string(3*current_tri) << ", " << to_string(3*tris_size) << ", " << std::dec << to_string(shape_bounds_xmin) << ", " << to_string(shape_bounds_xmax) << ", " << to_string(shape_bounds_ymin) << ", " << to_string(shape_bounds_ymax) << ");" << endl;
					}

					// Emit interleaved morph path data (deferred from edge parsing)
					if (is_morph && path_recording && !morph_start_buf.empty()) {
						size_t end_geo_idx = 0;
						size_t end_width_idx = 0;
						for (auto& entry : morph_start_buf) {
							float cmd = entry[0];
							path_data << "\t{" << std::fixed << std::setprecision(1)
							          << cmd << "f, " << entry[1] << "f, " << entry[2] << "f},\n";
							current_path_entry++;

							// For STYLE_LINE (1.5), emit morph end line width
							if (cmd == 1.5f) {
								float ew = (end_width_idx < morph_end_widths_buf.size())
								         ? morph_end_widths_buf[end_width_idx++] : entry[2];
								path_data << "\t{9.0f, 0.0f, " << ew << "f},\n";
								current_path_entry++;
							}
							// For geometric entries, emit morph end coordinates
							if (cmd == 5.0f || cmd == 2.0f || cmd == 3.0f || cmd == 4.0f) {
								if (end_geo_idx < morph_end_geo_buf.size()) {
									auto& e = morph_end_geo_buf[end_geo_idx++];
									path_data << "\t{9.0f, " << e[1] << "f, " << e[2] << "f},\n";
									current_path_entry++;
								}
							}
						}
					}

					// Record path data offset/size for vector-path hit testing
					if (path_recording && current_path_entry > path_start) {
						if (is_morph) {
							context.tag_main << "\t" << "ng_record_morph_path("
							                 << to_string(shape_id) << ", "
							                 << to_string(path_start) << ", "
							                 << to_string(current_path_entry - path_start) << ");" << endl;
						} else {
							context.tag_main << "\t" << "ng_record_char_path("
							                 << to_string(shape_id) << ", "
							                 << to_string(path_start) << ", "
							                 << to_string(current_path_entry - path_start) << ");" << endl;
						}
					}
				}

				current_tri += tris_size;

				break;
			}
		}
	}

	s32 pointOrientation(const Vertex& v0, const Vertex& v1, const Vertex& point)
	{
		return (v1.x - v0.x)*(point.y - v0.y) - (point.x - v0.x)*(v1.y - v0.y);
	}
	
	bool SWF::isInShape(const Vertex& v, const Shape* shape)
	{
		const Vertex* last_outer_v = nullptr;
		
		int windingNumber = 0;
		
		for (const Vertex& outer_v : shape->verts)
		{
			if (last_outer_v == nullptr)
			{
				last_outer_v = &outer_v;
				continue;
			}
			
			if (last_outer_v->y <= v.y)
			{
				if (outer_v.y > v.y && pointOrientation(*last_outer_v, outer_v, v) > 0)
				{
					windingNumber += 1;
				}
			}
			
			else
			{
				if (outer_v.y <= v.y && pointOrientation(*last_outer_v, outer_v, v) < 0)
				{
					windingNumber -= 1;
				}
			}
			
			last_outer_v = &outer_v;
		}
		
		return windingNumber != 0;
	}
	
	void SWF::addCurvedEdge(Path* path, Vertex current, Vertex control, Vertex anchor, u32 passes, s32* morph_counter)
	{
		std::vector<Vertex> left_points;
		std::vector<Vertex> right_points;

		for (u32 i = 1; i <= passes; ++i)
		{
			float t = (float) i / passes;
			float u = 1.0f - t;

			s32 x = (s32) (u*u*current.x + 2*u*t*control.x + t*t*anchor.x);
			s32 y = (s32) (u*u*current.y + 2*u*t*control.y + t*t*anchor.y);

			Vertex v;
			v.x = x;
			v.y = y;
			if (morph_counter != nullptr)
			{
				v.morph_index = (*morph_counter)++;
			}

			path->verts.push_back(v);
		}
	}
	
	void SWF::processShape(Shape& shape, u32* fill_styles)
	{
		s64 signed_area = 0;
		
		Vertex last_point;
		last_point.x = shape.verts[0].x;
		last_point.y = shape.verts[0].y;
		
		shape.min.x = shape.verts[0].x;
		shape.min.y = shape.verts[0].y;
		shape.max.x = shape.verts[0].x;
		shape.max.y = shape.verts[0].y;
		
		Vertex point;
		
		for (size_t k = 1; k < shape.verts.size(); ++k)
		{
			point.x = shape.verts[k].x;
			point.y = shape.verts[k].y;
			
			signed_area += CROSS(last_point, point);
			
			last_point.x = point.x;
			last_point.y = point.y;
			
			if (shape.verts[k].x < shape.min.x)
			{
				shape.min.x = shape.verts[k].x;
			}
			
			if (shape.verts[k].y < shape.min.y)
			{
				shape.min.y = shape.verts[k].y;
			}
			
			if (shape.verts[k].x > shape.max.x)
			{
				shape.max.x = shape.verts[k].x;
			}
			
			if (shape.verts[k].y > shape.max.y)
			{
				shape.max.y = shape.verts[k].y;
			}
		}
		
		point.x = shape.verts[0].x;
		point.y = shape.verts[0].y;
		
		signed_area += CROSS(last_point, point);
		
		shape.fill_right = signed_area < 0;
		
		shape.inner_fill = fill_styles[signed_area < 0];
		
		shape.got_min_max = true;
	}
	
	void SWF::constructEdges(std::vector<Path>& paths, std::vector<Node>& nodes)
	{
		nodes.reserve(2*paths.size());
		
		for (size_t i = 0; i < nodes.capacity(); ++i)
		{
			nodes.push_back(Node());
			nodes.back().used = false;
		}
		
		for (size_t i = 0; i < paths.size(); ++i)
		{
			Node* front = &nodes[2*i];
			Node* back = &nodes[2*i + 1];
			
			front->path = &paths[i];
			back->path = &paths[i];
			
			paths[i].front = front;
			paths[i].back = back;
		}
		
		for (size_t i = 0; i < paths.size(); ++i)
		{
			if (paths[i].fill_styles[0] != 0 || paths[i].fill_styles[1] != 0)
			{
				Vertex path_start;
				path_start.x = paths[i].verts[0].x;
				path_start.y = paths[i].verts[0].y;
				
				Vertex path_end;
				path_end.x = paths[i].verts.back().x;
				path_end.y = paths[i].verts.back().y;
				
				if (path_start.x == path_end.x &&
					path_start.y == path_end.y)
				{
					paths[i].self_closed = true;
					continue;
				}
				
				Node* front = paths[i].front;
				Node* back = paths[i].back;
				
				for (size_t j = 0; j < paths.size(); ++j)
				{
					if (i == j)
					{
						continue;
					}
					
					Vertex this_path_start;
					this_path_start.x = paths[j].verts[0].x;
					this_path_start.y = paths[j].verts[0].y;
					
					if (path_end.x == this_path_start.x &&
						path_end.y == this_path_start.y)
					{
						back->neighbors.push_back(paths[j].back);
					}
					
					if (path_start.x == this_path_start.x &&
						path_start.y == this_path_start.y)
					{
						front->neighbors.push_back(paths[j].back);
					}
					
					Vertex this_path_end;
					this_path_end.x = paths[j].verts.back().x;
					this_path_end.y = paths[j].verts.back().y;
					
					if (path_end.x == this_path_end.x &&
						path_end.y == this_path_end.y)
					{
						back->neighbors.push_back(paths[j].front);
					}
					
					if (path_start.x == this_path_end.x &&
						path_start.y == this_path_end.y)
					{
						front->neighbors.push_back(paths[j].front);
					}
				}
			}
		}
	}
	
	void blockInMap(Node* node, std::unordered_map<Node*, std::vector<Node*>>& blocked_map)
	{
		for (Node* neighbor : node->neighbors)
		{
			auto& blist = blocked_map[neighbor];
			if (std::find(blist.begin(), blist.end(), node) == blist.end())
			{
				blist.push_back(node);
			}
		}
	}
	
	void unblock(Node* node, std::unordered_map<Node*, bool>& blocked, std::unordered_map<Node*, std::vector<Node*>>& blocked_map)
	{
		std::vector<Node*> stack;
		stack.push_back(node);

		while (!stack.empty())
		{
			Node* current = stack.back();
			stack.pop_back();

			if (!blocked[current]) continue;
			blocked[current] = false;

			for (Node* n : blocked_map[current])
			{
				if (blocked[n])
				{
					stack.push_back(n);
				}
			}
			blocked_map[current].clear();
		}
	}
	
	bool traverseIteration(Node* path, std::vector<Path>& path_stack, std::unordered_map<Node*, bool>& blocked, std::unordered_map<Node*, std::vector<Node*>>& blocked_map, std::vector<std::vector<Path>>& closed_paths, size_t& iterations, size_t max_iterations);

	bool detectCycle(Node* node, std::vector<Path>& path_stack, std::unordered_map<Node*, bool>& blocked, std::unordered_map<Node*, std::vector<Node*>>& blocked_map, std::vector<std::vector<Path>>& closed_paths, size_t& iterations, size_t max_iterations)
	{
		if (iterations >= max_iterations) return false;

		if (node == path_stack[0].front || node == path_stack[0].back)
		{
			std::vector<Path> cycle;

			for (size_t i = 0; i < path_stack.size(); ++i)
			{
				cycle.push_back(path_stack[i]);
			}

			closed_paths.push_back(cycle);

			return true;
		}

		if (blocked[node])
		{
			return false;
		}

		return traverseIteration(node, path_stack, blocked, blocked_map, closed_paths, iterations, max_iterations);
	}

	bool traverseIteration(Node* node, std::vector<Path>& path_stack, std::unordered_map<Node*, bool>& blocked, std::unordered_map<Node*, std::vector<Node*>>& blocked_map, std::vector<std::vector<Path>>& closed_paths, size_t& iterations, size_t max_iterations)
	{
		++iterations;
		if (iterations >= max_iterations) return false;

		path_stack.push_back(*node->path);

		path_stack.back().backward = node == node->path->front;

		blocked[node] = true;

		bool cycle_found = false;

		for (Node* neighbor : node->neighbors)
		{
			if (neighbor->used)
			{
				continue;
			}

			cycle_found |= detectCycle(neighbor, path_stack, blocked, blocked_map, closed_paths, iterations, max_iterations);

			if (iterations >= max_iterations) break;
		}

		path_stack.pop_back();

		if (cycle_found)
		{
			unblock(node, blocked, blocked_map);
			return true;
		}

		blockInMap(node, blocked_map);

		return false;
	}

	void SWF::johnson(std::vector<Node>& nodes, std::vector<Path>& path_stack, std::unordered_map<Node*, bool>& blocked, std::unordered_map<Node*, std::vector<Node*>>& blocked_map, std::vector<std::vector<Path>>& closed_paths, size_t max_iterations)
	{
		size_t iterations = 0;

		for (Node& n : nodes)
		{
			if (iterations >= max_iterations)
			{
				fprintf(stderr, "Warning: johnson cycle detection exceeded %zu iterations, skipping remaining nodes\n", max_iterations);
				break;
			}

			blocked.clear();
			blocked_map.clear();

			traverseIteration(&n, path_stack, blocked, blocked_map, closed_paths, iterations, max_iterations);
			n.used = true;
		}
	}
	
	void SWF::fillShape(Shape& shape, std::vector<Tri>& tris)
	{
		std::vector<std::vector<std::array<Coord, 2>>> polygon;
		std::vector<std::array<Coord, 2>> shape_array;
		std::array<Coord, 2> array;

		std::vector<std::array<Coord, 2>> all_points;
		std::vector<s32> all_morph_indices;

		for (const Vertex& v : shape.verts)
		{
			array[0] = v.x;
			array[1] = v.y;

			shape_array.push_back(array);

			all_points.push_back(array);
			all_morph_indices.push_back(v.morph_index);
		}

		polygon.push_back(shape_array);

		for (const Shape* h : shape.holes)
		{
			shape_array.clear();

			for (const Vertex& v : h->verts)
			{
				array[0] = v.x;
				array[1] = v.y;

				shape_array.push_back(array);

				all_points.push_back(array);
				all_morph_indices.push_back(v.morph_index);
			}

			polygon.push_back(shape_array);
		}

		std::vector<N> indices = mapbox::earcut<N>(polygon);

		Tri t;

		for (size_t i = 0; i < indices.size(); ++i)
		{
			size_t tri_index = i % 3;

			t.verts[tri_index].x = all_points[indices[i]][0];
			t.verts[tri_index].y = all_points[indices[i]][1];
			t.verts[tri_index].morph_index = all_morph_indices[indices[i]];

			if (tri_index == 2)
			{
				tris.push_back(t);
			}
		}
	}
	
	void drawLineJoin(const Vertex& a, const Vertex& b, const Vertex& c, u16 halfwidth, std::vector<Tri>& tris)
	{
		Vertex vec_a_b;
		vec_a_b.x = b.x - a.x;
		vec_a_b.y = b.y - a.y;
		
		Vertex vec_b_c;
		vec_b_c.x = c.x - b.x;
		vec_b_c.y = c.y - b.y;
		
		s32 cross = CROSS(vec_a_b, vec_b_c);
		
		double offset = (cross < 0) ? M_PI/2 : -M_PI/2;
		
		double angle_a_b = atan2(vec_a_b.y, vec_a_b.x) + offset;
		double angle_b_c = atan2(vec_b_c.y, vec_b_c.x) + offset;
		
		int num_midpoints = 5;
		
		double start_angle = (angle_a_b < angle_b_c) ? angle_a_b : angle_b_c;
		double end_angle = (angle_a_b < angle_b_c) ? angle_b_c : angle_a_b;
		
		double angle_delta = (end_angle - start_angle)/num_midpoints;
		
		Vertex last_point;
		last_point.x = (s32) std::round(b.x + halfwidth*cos(start_angle));
		last_point.y = (s32) std::round(b.y + halfwidth*sin(start_angle));
		
		Tri t;
		t.verts[0] = b;
		
		for (double current_angle = start_angle + angle_delta; current_angle < end_angle; current_angle += angle_delta)
		{
			t.verts[1] = last_point;
			
			t.verts[2].x = (s32) std::round(b.x + halfwidth*cos(current_angle));
			t.verts[2].y = (s32) std::round(b.y + halfwidth*sin(current_angle));
			
			tris.push_back(t);
			
			last_point = t.verts[2];
		}
		
		t.verts[1] = last_point;
		
		t.verts[2].x = (s32) std::round(b.x + halfwidth*cos(end_angle));
		t.verts[2].y = (s32) std::round(b.y + halfwidth*sin(end_angle));
		
		tris.push_back(t);
	}
	
	void drawLineCap(const Vertex& a, const Vertex& b, u16 halfwidth, std::vector<Tri>& tris)
	{
		Vertex vec_a_b;
		vec_a_b.x = b.x - a.x;
		vec_a_b.y = b.y - a.y;
		
		double angle_a_b = atan2(vec_a_b.y, vec_a_b.x);
		
		int num_midpoints = 5;
		
		double start_angle = angle_a_b + M_PI/2.0;
		double end_angle = start_angle + M_PI;
		
		double angle_delta = (end_angle - start_angle)/num_midpoints;
		
		Vertex last_point;
		last_point.x = (s32) std::round(a.x + halfwidth*cos(start_angle));
		last_point.y = (s32) std::round(a.y + halfwidth*sin(start_angle));
		
		Tri t;
		t.verts[0] = a;
		
		for (double current_angle = start_angle + angle_delta; current_angle < end_angle; current_angle += angle_delta)
		{
			t.verts[1] = last_point;
			
			t.verts[2].x = (s32) std::round(a.x + halfwidth*cos(current_angle));
			t.verts[2].y = (s32) std::round(a.y + halfwidth*sin(current_angle));
			
			tris.push_back(t);
			
			last_point = t.verts[2];
		}
		
		t.verts[1] = last_point;
		
		t.verts[2].x = (s32) std::round(a.x + halfwidth*cos(end_angle));
		t.verts[2].y = (s32) std::round(a.y + halfwidth*sin(end_angle));
		
		tris.push_back(t);
	}
	
	void SWF::drawLines(const Path& path, u16 width, std::vector<Tri>& tris)
	{
		if (width != 0 && width < 20)
		{
			width = 20;
		}
		
		else if (width == 0)
		{
			return;
		}
		
		u16 halfwidth = width/2;
		
		Vertex last_v = path.verts[0];
		
		for (size_t i = 1; i < path.verts.size(); ++i)
		{
			const Vertex& v = path.verts[i];
			
			Tri t;
			
			double angle = atan2(v.y - last_v.y, v.x - last_v.x) - M_PI/2.0;
			
			if (i > 1)
			{
				const Vertex& last_last_v = path.verts[i - 2];
				
				drawLineJoin(last_last_v, last_v, v, halfwidth, tris);
			}
			
			t.verts[0].x = (s32) std::round(last_v.x + halfwidth*cos(angle));
			t.verts[0].y = (s32) std::round(last_v.y + halfwidth*sin(angle));
			
			t.verts[2].x = (s32) std::round(v.x + halfwidth*cos(angle));
			t.verts[2].y = (s32) std::round(v.y + halfwidth*sin(angle));
			
			angle += M_PI;
			
			t.verts[1].x = (s32) std::round(last_v.x + halfwidth*cos(angle));
			t.verts[1].y = (s32) std::round(last_v.y + halfwidth*sin(angle));
			
			tris.push_back(t);
			
			t.verts[0].x = (s32) std::round(v.x + halfwidth*cos(angle));
			t.verts[0].y = (s32) std::round(v.y + halfwidth*sin(angle));
			
			tris.push_back(t);
			
			last_v = v;
		}
		
		if (path.verts.size() > 2 &&
			path.verts.back().x == path.verts[0].x &&
			path.verts.back().y == path.verts[0].y)
		{
			const Vertex& a = path.verts[path.verts.size() - 2];
			const Vertex& b = path.verts[0];
			const Vertex& c = path.verts[1];
			
			drawLineJoin(a, b, c, halfwidth, tris);
		}
		
		else
		{
			drawLineCap(path.verts[0], path.verts[1], halfwidth, tris);
			drawLineCap(path.verts.back(), path.verts[path.verts.size() - 2], halfwidth, tris);
		}
	}
};