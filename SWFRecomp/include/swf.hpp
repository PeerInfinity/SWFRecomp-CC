#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>

#include <common.h>
#include <tag.hpp>
#include <action.hpp>

namespace SWFRecomp
{
	struct RECT
	{
		u8 nbits;
		s32 xmin;
		s32 xmax;
		s32 ymin;
		s32 ymax;
	};
	
	struct MATRIX
	{
		float scale_x;
		float scale_y;
		float rotateskew_0;
		float rotateskew_1;
		s32 translate_x;
		s32 translate_y;
	};
	
	struct Vertex
	{
		s32 x;
		s32 y;
		s32 morph_index = -1;
	};
	
	struct Tri
	{
		Vertex verts[3];
	};
	
	struct Node;
	
	struct Path
	{
		std::vector<Vertex> verts;
		u32 fill_style_list;
		u32 line_style_list;
		u32 fill_styles[2];
		u32 line_style;
		bool self_closed;
		bool backward;
		Node* front;
		Node* back;
	};
	
	struct Node
	{
		Path* path;
		std::vector<Node*> neighbors;
		bool used;
	};
	
	struct Shape
	{
		std::vector<Vertex> verts;
		std::vector<Shape*> holes;
		Vertex min;
		Vertex max;
		bool got_min_max;
		u32 fill_style_list;
		u32 line_style_list;
		u32 inner_fill;
		u32 nesting_depth;
		bool fill_right;
		bool closed;
		bool hole;
		bool invalid;
	};
	
	struct GradientRecord
	{
		u8 ratio;
		u8 r;
		u8 g;
		u8 b;
		u8 a;
	};
	
	struct Gradient
	{
		u8 spread_mode;
		u8 interpolation_mode;
		u8 num_grads;
		GradientRecord records[15];
	};
	
	enum FillType
	{
		FILL_SOLID = 0x00,
		FILL_GRAD_LINEAR = 0x10,
		FILL_GRAD_RADIAL = 0x12,
		FILL_GRAD_FOCAL = 0x13,
		FILL_BITMAP_REPEAT = 0x40,
		FILL_BITMAP_CLIPPED = 0x41,
		FILL_BITMAP_REPEAT_NONSMOOTH = 0x42,
		FILL_BITMAP_CLIPPED_NONSMOOTH = 0x43,
	};
	
	struct FillStyle
	{
		u8 type;
		size_t index;
		u8 r;
		u8 g;
		u8 b;
		u8 a;
		Gradient gradient;
	};
	
	struct LineStyle
	{
		u16 width;
		u16 end_width = 0; // morph end width (0 for non-morph)
		size_t index;
		u8 r;
		u8 g;
		u8 b;
		u8 a;
	};
	
	class SWFHeader
	{
	public:
		u8 compression;
		u8 w;  // If not 'W', invalid SWF
		u8 s;  // If not 'S', invalid SWF
		
		u8 version;
		u32 file_length;
		RECT frame_size;
		u16 framerate;
		u16 frame_count;
		
		SWFHeader();
		SWFHeader(char* swf_buffer);
		
		void loadOtherData(char*& swf_buffer);
	};
	
	class SWF
	{
	public:
		SWFHeader header;
		char* swf_buffer;
		char* cur_pos;
		size_t num_finished_tags;
		size_t next_frame_i;
		bool another_frame;
		size_t next_script_i;
		size_t last_queued_script;

		std::stringstream tag_init;
		std::stringstream tag_init_scripts;  // DoInitAction calls (emitted after initVarArray)

		// Per-frame init prologue buffer: top-level DoInitAction /
		// ImportAssets calls accumulated for the current frame, replacing a
		// placeholder marker at frame open. This places them at the top of
		// frame_N's body (before that frame's PlaceObject*/RemoveObject*/
		// DoAction emissions), matching Ruffle's preload pass timing.
		// See _investigation/DOINITACTION_PER_FRAME_PROLOGUE_PLAN.md.
		std::stringstream current_frame_init_actions;
		size_t current_frame_marker_id = 0;
		bool frame_init_emitted = false;

		std::stringstream shape_data;
		size_t current_tri;
		std::stringstream transform_data;
		size_t current_transform;
		std::stringstream color_data;
		size_t current_color;
		std::stringstream uninv_mat_data;
		size_t current_uninv;
		std::stringstream gradient_data;
		size_t current_gradient;
		std::stringstream bitmap_data;
		size_t current_bitmap_pixel;
		size_t current_bitmap;
		std::stringstream glyph_data;
		size_t current_glyph;
		std::stringstream text_data;
		std::stringstream text_char_codes;  // parallel to text_data: Unicode code point per glyph
		size_t current_text;
		std::vector<std::pair<u16, u32>> text_glyph_entries;  // (font_id, glyph_index) for deferred char code lookup
		std::stringstream cxform_data;
		size_t current_cxform;

		std::stringstream path_data;  // vector path data for hit testing (fills + strokes)
		size_t current_path_entry;

		std::stringstream morph_end_shape_data;
		size_t current_morph_end_vertex;
		std::stringstream morph_end_color_data;
		size_t current_morph_end_color;

		std::stringstream sound_data;
		size_t current_sound_byte;
		size_t current_sound_id;
		bool has_streaming_sound;

		// DefineVideoStream + VideoFrame embedded video. Encoded payload bytes
		// concatenated across all VideoFrame tags in the SWF; each tagVideoFrame
		// emission references a (offset, length) slice.
		std::stringstream video_data;
		size_t current_video_byte;

		std::stringstream sprite_definitions;
		std::stringstream sprite_forward_decls;
		// Accumulates SpriteFrameScriptEntry initializers — one per
		// sprite-DoAction-script emission. Phase A of GOTO_FIFO_UNIFICATION
		// incremental plan: side table feeding actionGetSpriteFrameScript().
		// Dead until later phases consume it.
		std::stringstream sprite_frame_scripts_table;
		size_t sprite_frame_scripts_count = 0;

		u8* jpeg_tables;
		size_t jpeg_tables_size;
		
		std::unordered_map<u16, size_t> char_id_to_bitmap_id;
		std::vector<Vertex> bitmap_sizes;

		std::unordered_map<u16, float> font_em_square;  // font_id → EM square size
		std::unordered_map<u16, std::vector<u16>> font_code_tables;  // font_id → code table (index=glyph, value=char code)
		std::unordered_map<u16, std::vector<s16>> font_advance_tables;  // font_id → per-glyph advance widths
		std::unordered_map<u16, size_t> font_glyph_bases;  // font_id → base index in global glyph_data
		std::unordered_map<u16, std::string> font_names;  // font_id → font name string
		std::unordered_map<u16, bool> font_bold_flags;    // font_id → bold flag
		std::unordered_map<u16, bool> font_italic_flags;  // font_id → italic flag
		std::unordered_map<u16, s16> font_ascent;         // font_id → ascent (EM units)
		std::unordered_map<u16, s16> font_descent;        // font_id → descent (EM units)
		std::unordered_map<u16, s16> font_leading;        // font_id → leading (EM units)

		// Frame label storage: label name -> frame number
		std::unordered_map<std::string, size_t> frame_labels;

		// Track clip_actions variable names per depth for remove+replace optimization.
		// Maps SWF depth → { clip_actions_var_name, clip_action_count }.
		// Updated on PlaceObject2WithClipActions, cleared on RemoveObject2 (when not replaced).
		struct DepthClipInfo {
			std::string var_name;
			size_t count;
		};
		std::unordered_map<u16, DepthClipInfo> depth_clip_actions;

		// Buffered RemoveObject2 calls in the current frame (for remove+replace detection).
		// Key: depth. Value: true if buffered.
		std::set<u16> buffered_removes;

		// Character IDs that have been registered by a Define* tag encountered so
		// far in tag-stream order. PlaceObject{,2,3} that references a char_id NOT
		// yet in this set is treated as a failed placement (matches Flash, where
		// the character dictionary is built sequentially as tags are processed).
		// Currently tracks DefineSprite only — that is the case our fuzz suite
		// exercises and other character types either follow a different runtime
		// registration path or do not appear before a referencing Place tag in
		// our test corpus. See `_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`.
		std::set<u16> defined_chars;

		// Cross-DoAction backward-jump support: maps the absolute SWF address of
		// each DoAction body's first byte to the script function name we emitted
		// for that DoAction. Consulted by parseActions when a JUMP/IF target
		// would otherwise be `return;` (negative target_offset crossing the
		// current DoAction's body) — see action.cpp JUMP/IF handlers for the
		// corresponding `script_N(); return;` emission. Populated as each
		// DoAction is recompiled, so DoAction k can target any earlier
		// DoAction j (j < k).
		std::map<char*, std::string> doaction_script_map;

		SWFAction action;

		SWFTag RGB;
		SWFTag RGBA;
		bool shape_has_alpha;
		bool shape_is_v4;
		bool shape_is_morph2;
		bool use_network;

		SWF();
		SWF(Context& context);
		
		void parseMatrix(MATRIX& matrix_out);
		void parseAllTags(Context& context);
		void interpretTag(Context& context, SWFTag& tag);
		// Per-frame init prologue helpers. writeFrameInitMarker emits a
		// unique placeholder into context.tag_main at the top of the
		// current frame body. flushFrameInitPrologue replaces that
		// placeholder with the accumulated DoInitAction / ImportAssets
		// calls (from current_frame_init_actions), then resets the buffer.
		void writeFrameInitMarker(Context& context);
		void flushFrameInitPrologue(Context& context);
		void recompileMatrix(MATRIX matrix, std::stringstream& out);
		FillStyle* parseFillStyles(u16 fill_style_count);
		FillStyle* parseMorphFillStyles(u16 fill_style_count);
		LineStyle* parseLineStyles(u16 line_style_count);
		LineStyle* parseMorphLineStyles(u16 line_style_count);
		LineStyle* parseLineStyles2(u16 line_style_count);
		void interpretShape(Context& context, SWFTag& shape_tag);
		bool isInShape(const Vertex& v, const Shape* shape);
		void addCurvedEdge(Path* path, Vertex current, Vertex control, Vertex anchor, u32 passes, s32* morph_counter = nullptr);
		void processShape(Shape& shape, u32* fill_styles);
		void constructEdges(std::vector<Path>& paths, std::vector<Node>& nodes);
		void johnson(std::vector<Node>& nodes, std::vector<Path>& path_stack, std::unordered_map<Node*, bool>& blocked, std::unordered_map<Node*, std::vector<Node*>>& blocked_map, std::vector<std::vector<Path>>& closed_paths, size_t max_iterations = 100000);
		void fillShape(Shape& shape, std::vector<Tri>& tris);
		void drawLines(const Path& path, u16 width, std::vector<Tri>& tris);
	};
};