// ng_shared.c — shared ng_* registry functions compiled in ALL build modes
// (NO_GRAPHICS, HEADLESS_GRAPHICS, and GRAPHICS/USE_WEBGPU)
//
// These functions provide access to SWF definition registries (fonts, textfields,
// exports, character bounds/paths, sounds, videos, buttons) that are populated
// during tag processing and queried by action.c and tag.c at runtime.
//
// NO #ifdef guard — this file is always compiled.

#include <tag.h>
#include <swf.h>
#include <common.h>
#include <action.h>
#include <object.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

// ---------------------------------------------------------------------------
// External globals (defined per build mode: tag_stubs.c / swf.c / swf_core.c)
// ---------------------------------------------------------------------------
extern Character* dictionary;
extern DisplayObject* display_list;
extern size_t max_depth;
extern size_t display_list_capacity;
extern size_t dictionary_capacity;

// ---------------------------------------------------------------------------
// Root display object sentinel (allows child lookup on root_movieclip)
// ---------------------------------------------------------------------------
static DisplayObject ng_root_display_obj;

void ng_sync_root_display_obj(void)
{
	ng_root_display_obj.sprite_display_list = display_list;
	ng_root_display_obj.sprite_max_depth    = max_depth;
}

void* ng_get_root_display_obj(void)
{
	return &ng_root_display_obj;
}

// ---------------------------------------------------------------------------
// Character bounds registry (shapes/morph shapes)
// ---------------------------------------------------------------------------
#define MAX_CHAR_BOUNDS_NG 256
static struct {
	size_t char_id;
	s32 xmin, xmax, ymin, ymax;  // twips
} ng_char_bounds[MAX_CHAR_BOUNDS_NG];
static size_t ng_char_bounds_count = 0;

#define MAX_MORPH_END_BOUNDS_NG 64
static struct {
	size_t char_id;
	s32 xmin, xmax, ymin, ymax;  // twips (end shape bounds)
} ng_morph_end_bounds[MAX_MORPH_END_BOUNDS_NG];
static size_t ng_morph_end_bounds_count = 0;

void ng_record_char_bounds(size_t char_id, s32 xmin, s32 xmax, s32 ymin, s32 ymax)
{
	if (ng_char_bounds_count >= MAX_CHAR_BOUNDS_NG) return;
	ng_char_bounds[ng_char_bounds_count].char_id = char_id;
	ng_char_bounds[ng_char_bounds_count].xmin = xmin;
	ng_char_bounds[ng_char_bounds_count].xmax = xmax;
	ng_char_bounds[ng_char_bounds_count].ymin = ymin;
	ng_char_bounds[ng_char_bounds_count].ymax = ymax;
	ng_char_bounds_count++;
}

void ng_record_morph_end_bounds(size_t char_id, s32 xmin, s32 xmax, s32 ymin, s32 ymax)
{
	if (ng_morph_end_bounds_count >= MAX_MORPH_END_BOUNDS_NG) return;
	ng_morph_end_bounds[ng_morph_end_bounds_count].char_id = char_id;
	ng_morph_end_bounds[ng_morph_end_bounds_count].xmin = xmin;
	ng_morph_end_bounds[ng_morph_end_bounds_count].xmax = xmax;
	ng_morph_end_bounds[ng_morph_end_bounds_count].ymin = ymin;
	ng_morph_end_bounds[ng_morph_end_bounds_count].ymax = ymax;
	ng_morph_end_bounds_count++;
}

int ng_getCharBounds(size_t char_id, s32* out_xmin, s32* out_xmax, s32* out_ymin, s32* out_ymax)
{
	for (size_t i = 0; i < ng_char_bounds_count; i++)
	{
		if (ng_char_bounds[i].char_id == char_id)
		{
			if (out_xmin) *out_xmin = ng_char_bounds[i].xmin;
			if (out_xmax) *out_xmax = ng_char_bounds[i].xmax;
			if (out_ymin) *out_ymin = ng_char_bounds[i].ymin;
			if (out_ymax) *out_ymax = ng_char_bounds[i].ymax;
			return 1;
		}
	}
	return 0;
}

int ng_getCharBoundsForRatio(size_t char_id, u16 ratio,
    s32* out_xmin, s32* out_xmax, s32* out_ymin, s32* out_ymax)
{
	if (!ng_getCharBounds(char_id, out_xmin, out_xmax, out_ymin, out_ymax))
		return 0;
	if (ratio == 0)
		return 1;
	for (size_t i = 0; i < ng_morph_end_bounds_count; i++)
	{
		if (ng_morph_end_bounds[i].char_id == char_id)
		{
			double t = (double)ratio / 65535.0;
			s32 sx = *out_xmin, sy = *out_ymin;
			s32 ex = *out_xmax, ey = *out_ymax;
			s32 esx = ng_morph_end_bounds[i].xmin;
			s32 eex = ng_morph_end_bounds[i].xmax;
			s32 esy = ng_morph_end_bounds[i].ymin;
			s32 eey = ng_morph_end_bounds[i].ymax;
			*out_xmin = (s32)(sx + (esx - sx) * t);
			*out_xmax = (s32)(ex + (eex - ex) * t);
			*out_ymin = (s32)(sy + (esy - sy) * t);
			*out_ymax = (s32)(ey + (eey - ey) * t);
			return 1;
		}
	}
	return 1;
}

// ---------------------------------------------------------------------------
// Path data registry (vector-path hit testing)
// ---------------------------------------------------------------------------
#define MAX_CHAR_PATHS_NG 256
static struct {
	size_t char_id;
	size_t path_offset;
	size_t path_size;
} ng_char_paths[MAX_CHAR_PATHS_NG];
static size_t ng_char_paths_count = 0;

#define MAX_MORPH_PATHS_NG 64
static struct {
	size_t char_id;
	size_t path_offset;
	size_t path_size;
} ng_morph_paths[MAX_MORPH_PATHS_NG];
static size_t ng_morph_paths_count = 0;

#define MAX_WINDING_NG 64
static size_t ng_winding_ids[MAX_WINDING_NG];
static size_t ng_winding_count = 0;

void ng_record_char_path(size_t char_id, size_t path_offset, size_t path_size)
{
	if (ng_char_paths_count >= MAX_CHAR_PATHS_NG) return;
	ng_char_paths[ng_char_paths_count].char_id = char_id;
	ng_char_paths[ng_char_paths_count].path_offset = path_offset;
	ng_char_paths[ng_char_paths_count].path_size = path_size;
	ng_char_paths_count++;
}

void ng_record_morph_path(size_t char_id, size_t path_offset, size_t path_size)
{
	if (ng_morph_paths_count >= MAX_MORPH_PATHS_NG) return;
	ng_morph_paths[ng_morph_paths_count].char_id = char_id;
	ng_morph_paths[ng_morph_paths_count].path_offset = path_offset;
	ng_morph_paths[ng_morph_paths_count].path_size = path_size;
	ng_morph_paths_count++;
}

void ng_record_char_winding(size_t char_id)
{
	if (ng_winding_count < MAX_WINDING_NG)
		ng_winding_ids[ng_winding_count++] = char_id;
}

// Public lookup functions for hit testing (called from tag_stubs.c)
int ng_find_char_path(size_t char_id, size_t* out_offset, size_t* out_size)
{
	for (size_t i = 0; i < ng_char_paths_count; i++) {
		if (ng_char_paths[i].char_id == char_id) {
			*out_offset = ng_char_paths[i].path_offset;
			*out_size = ng_char_paths[i].path_size;
			return 1;
		}
	}
	return 0;
}

int ng_find_morph_path(size_t char_id, size_t* out_offset, size_t* out_size)
{
	for (size_t i = 0; i < ng_morph_paths_count; i++) {
		if (ng_morph_paths[i].char_id == char_id) {
			*out_offset = ng_morph_paths[i].path_offset;
			*out_size = ng_morph_paths[i].path_size;
			return 1;
		}
	}
	return 0;
}

int ng_uses_nonzero_winding(size_t char_id)
{
	for (size_t i = 0; i < ng_winding_count; i++)
		if (ng_winding_ids[i] == char_id) return 1;
	return 0;
}

// ---------------------------------------------------------------------------
// Button char_id registry (for typeof discrimination)
// ---------------------------------------------------------------------------
#define MAX_BUTTONS_NG 64
static size_t ng_button_ids[MAX_BUTTONS_NG];
static size_t ng_button_count = 0;

int ng_find_button(size_t char_id)
{
	for (size_t i = 0; i < ng_button_count; i++)
		if (ng_button_ids[i] == char_id) return 1;
	return 0;
}

void ng_record_button(size_t char_id)
{
	if (ng_button_count < MAX_BUTTONS_NG && !ng_find_button(char_id))
		ng_button_ids[ng_button_count++] = char_id;
}

// ---------------------------------------------------------------------------
// Video stream char_id registry
// ---------------------------------------------------------------------------
#define MAX_VIDEOS_NG 32
static size_t ng_video_ids[MAX_VIDEOS_NG];
static size_t ng_video_count = 0;

int ng_find_video(size_t char_id)
{
	for (size_t i = 0; i < ng_video_count; i++)
		if (ng_video_ids[i] == char_id) return 1;
	return 0;
}

void ng_record_video(SWFAppContext* app_context, u16 char_id)
{
	(void)app_context;
	if (ng_video_count < MAX_VIDEOS_NG)
		ng_video_ids[ng_video_count++] = (size_t)char_id;
}

int ng_isVideoChar(size_t char_id)
{
	return ng_find_video(char_id);
}

// ---------------------------------------------------------------------------
// Scriptable character queries
// ---------------------------------------------------------------------------

int ng_isScriptableChar(size_t char_id)
{
	return (dictionary[char_id].type == CHAR_TYPE_SPRITE) ||
	       ng_find_button(char_id) ||
	       (ng_find_textfield(char_id) >= 0) ||
	       ng_find_video(char_id);
}

int ng_getCharTextfieldIdx(size_t char_id)
{
	return ng_find_textfield(char_id);
}

// ---------------------------------------------------------------------------
// Font info registry
// ---------------------------------------------------------------------------
#define MAX_FONTS_NG 32
#define MAX_FONT_GLYPHS 512
static struct {
	u16 font_id;
	char name[128];
	int bold;
	int italic;
	int has_metrics;
	s16 ascent;
	s16 descent;
	s16 leading;
	int em_square;
	u16 code_table[MAX_FONT_GLYPHS];
	s16 advance_table[MAX_FONT_GLYPHS];
	size_t glyph_count;
	size_t glyph_base;
	int is_builtin;
} ng_fonts[MAX_FONTS_NG];
static size_t ng_font_count = 0;

// Built-in Noto Sans fallback font for createTextField (no embedded font).
static const u16 builtin_noto_sans_codes[] = {
	32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,
	48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,
	64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,
	80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,
	96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,
	112,113,114,115,116,117,118,119,120,121,122,123,124,125,126
};
static const s16 builtin_noto_sans_advances[] = {
	260,269,408,646,572,831,732,225,300,300,551,572,268,322,268,372,
	572,572,572,572,572,572,572,572,572,572,268,268,572,572,572,434,
	899,639,650,632,730,556,519,728,741,339,273,619,524,907,760,781,
	605,781,622,549,556,731,600,930,586,566,572,329,372,329,572,444,
	281,561,615,480,615,564,344,615,618,258,258,534,258,935,618,605,
	615,615,413,479,361,618,508,786,529,510,470,380,551,380,572
};
#define BUILTIN_NOTO_SANS_GLYPH_COUNT 95
#define BUILTIN_NOTO_SANS_ASCENT 1069
#define BUILTIN_NOTO_SANS_DESCENT 293
#define BUILTIN_NOTO_SANS_LEADING 0
#define BUILTIN_NOTO_SANS_EM 1000

static s16 builtin_font_glyph_advance(u16 code_point)
{
	if (code_point >= 32 && code_point <= 126)
		return builtin_noto_sans_advances[code_point - 32];
	return -1;
}

static int ng_builtin_font_registered = 0;
static void ng_ensure_builtin_font(void)
{
	if (ng_builtin_font_registered) return;
	ng_builtin_font_registered = 1;
	if (ng_font_count >= MAX_FONTS_NG) return;
	size_t idx = ng_font_count++;
	ng_fonts[idx].font_id = 0;
	strncpy(ng_fonts[idx].name, "Noto Sans", sizeof(ng_fonts[idx].name) - 1);
	ng_fonts[idx].bold = 0;
	ng_fonts[idx].italic = 0;
	ng_fonts[idx].is_builtin = 1;
	ng_fonts[idx].has_metrics = 1;
	ng_fonts[idx].ascent = BUILTIN_NOTO_SANS_ASCENT;
	ng_fonts[idx].descent = BUILTIN_NOTO_SANS_DESCENT;
	ng_fonts[idx].leading = BUILTIN_NOTO_SANS_LEADING;
	ng_fonts[idx].em_square = BUILTIN_NOTO_SANS_EM;
	ng_fonts[idx].glyph_count = BUILTIN_NOTO_SANS_GLYPH_COUNT;
	for (size_t j = 0; j < BUILTIN_NOTO_SANS_GLYPH_COUNT; j++) {
		ng_fonts[idx].code_table[j] = builtin_noto_sans_codes[j];
		ng_fonts[idx].advance_table[j] = builtin_noto_sans_advances[j];
	}
}

static int ng_find_font(u16 font_id)
{
	for (size_t i = 0; i < ng_font_count; i++)
		if (ng_fonts[i].font_id == font_id) return (int)i;
	if (font_id == 0) {
		ng_ensure_builtin_font();
		for (size_t i = 0; i < ng_font_count; i++)
			if (ng_fonts[i].font_id == 0) return (int)i;
	}
	return -1;
}

int ng_find_font_with_metrics(u16 font_id)
{
	int fi = ng_find_font(font_id);
	if (fi >= 0 && ng_fonts[fi].has_metrics) return fi;
	ng_ensure_builtin_font();
	for (size_t i = 0; i < ng_font_count; i++)
		if (ng_fonts[i].font_id == 0 && ng_fonts[i].has_metrics) return (int)i;
	return -1;
}

static s16 ng_font_glyph_advance(int font_idx, u16 code_point)
{
	for (size_t j = 0; j < ng_fonts[font_idx].glyph_count; j++) {
		if (ng_fonts[font_idx].code_table[j] == code_point)
			return ng_fonts[font_idx].advance_table[j];
	}
	return -1;
}

int ng_font_find_glyph(int font_idx, u16 code_point)
{
	if (font_idx < 0 || (size_t)font_idx >= ng_font_count) return -1;
	for (size_t j = 0; j < ng_fonts[font_idx].glyph_count; j++) {
		if (ng_fonts[font_idx].code_table[j] == code_point)
			return (int)j;
	}
	return -1;
}

size_t ng_font_get_glyph_base(int font_idx)
{
	if (font_idx < 0 || (size_t)font_idx >= ng_font_count) return 0;
	return ng_fonts[font_idx].glyph_base;
}

int ng_font_get_metrics(int font_idx, s16* ascent, s16* descent, int* em_square)
{
	if (font_idx < 0 || (size_t)font_idx >= ng_font_count) return 0;
	if (!ng_fonts[font_idx].has_metrics) return 0;
	if (ascent) *ascent = ng_fonts[font_idx].ascent;
	if (descent) *descent = ng_fonts[font_idx].descent;
	if (em_square) *em_square = ng_fonts[font_idx].em_square;
	return 1;
}

s16 ng_font_glyph_advance_by_idx(int font_idx, int glyph_idx)
{
	if (font_idx < 0 || (size_t)font_idx >= ng_font_count) return -1;
	if (glyph_idx < 0 || (size_t)glyph_idx >= ng_fonts[font_idx].glyph_count) return -1;
	return ng_fonts[font_idx].advance_table[glyph_idx];
}

void ng_record_font(SWFAppContext* app_context, u16 font_id, const char* name, int bold, int italic)
{
	(void)app_context;
	if (ng_font_count >= MAX_FONTS_NG) return;
	ng_fonts[ng_font_count].font_id = font_id;
	strncpy(ng_fonts[ng_font_count].name, name ? name : "", sizeof(ng_fonts[ng_font_count].name) - 1);
	ng_fonts[ng_font_count].name[sizeof(ng_fonts[ng_font_count].name) - 1] = '\0';
	ng_fonts[ng_font_count].bold = bold;
	ng_fonts[ng_font_count].italic = italic;
	ng_font_count++;
}

void ng_record_font_metrics(SWFAppContext* app_context, u16 font_id,
    s16 ascent, s16 descent, s16 leading, int em_square,
    const u16* code_table, const s16* advance_table, size_t glyph_count)
{
	(void)app_context;
	for (size_t i = 0; i < ng_font_count; i++) {
		if (ng_fonts[i].font_id == font_id) {
			ng_fonts[i].has_metrics = 1;
			ng_fonts[i].ascent = ascent;
			ng_fonts[i].descent = descent;
			ng_fonts[i].leading = leading;
			ng_fonts[i].em_square = em_square;
			size_t count = glyph_count < MAX_FONT_GLYPHS ? glyph_count : MAX_FONT_GLYPHS;
			ng_fonts[i].glyph_count = count;
			for (size_t j = 0; j < count; j++) {
				ng_fonts[i].code_table[j] = code_table[j];
				ng_fonts[i].advance_table[j] = advance_table[j];
			}
			return;
		}
	}
}

void ng_record_font_glyph_base(u16 font_id, size_t glyph_base)
{
	for (size_t i = 0; i < ng_font_count; i++) {
		if (ng_fonts[i].font_id == font_id) {
			ng_fonts[i].glyph_base = glyph_base;
			return;
		}
	}
}

const char* ng_getFontName(u16 font_id)
{
	for (size_t i = 0; i < ng_font_count; i++)
		if (ng_fonts[i].font_id == font_id) return ng_fonts[i].name;
	return "";
}

const char* ng_getFontNameSWFDefined(u16 font_id)
{
	for (size_t i = 0; i < ng_font_count; i++)
		if (ng_fonts[i].font_id == font_id && !ng_fonts[i].is_builtin) return ng_fonts[i].name;
	return "";
}

u16 ng_findFontIdByName(const char* name)
{
	for (size_t i = 0; i < ng_font_count; i++)
		if (strcasecmp(ng_fonts[i].name, name) == 0) return ng_fonts[i].font_id;
	return 0;
}

int ng_getFontBold(u16 font_id)
{
	for (size_t i = 0; i < ng_font_count; i++)
		if (ng_fonts[i].font_id == font_id) return ng_fonts[i].bold;
	return 0;
}

int ng_getFontItalic(u16 font_id)
{
	for (size_t i = 0; i < ng_font_count; i++)
		if (ng_fonts[i].font_id == font_id) return ng_fonts[i].italic;
	return 0;
}

// ---------------------------------------------------------------------------
// TextField property registry
// ---------------------------------------------------------------------------
#define MAX_TEXTFIELDS_NG 64
static struct {
	size_t char_id;
	char plain_text[1024];
	char raw_html_text[1024];
	u32 text_color;
	u16 font_id;
	u16 font_height;
	s16 max_length;
	u8 align;
	u16 left_margin, right_margin;
	s16 indent;
	s16 leading;
	char variable_name[256];
	u16 flags;
	s32 bounds_xmin, bounds_xmax, bounds_ymin, bounds_ymax;
	char csm_antiAliasType[16];
	char csm_gridFitType[16];
	float csm_thickness;
	float csm_sharpness;
	int csm_applied;
} ng_textfields[MAX_TEXTFIELDS_NG];
static size_t ng_textfield_count = 0;

int ng_find_textfield(size_t char_id)
{
	for (size_t i = 0; i < ng_textfield_count; i++)
		if (ng_textfields[i].char_id == char_id) return (int)i;
	return -1;
}

void ng_record_textfield_props(SWFAppContext* app_context, size_t char_id,
    const char* plain_text, const char* raw_html_text, u32 text_color,
    u16 font_id, u16 font_height, s16 max_length,
    u8 align, u16 left_margin, u16 right_margin, s16 indent, s16 leading,
    const char* variable_name, u16 flags,
    s32 bounds_xmin, s32 bounds_xmax, s32 bounds_ymin, s32 bounds_ymax)
{
	(void)app_context;
	if (ng_textfield_count >= MAX_TEXTFIELDS_NG) return;
	size_t i = ng_textfield_count;
	ng_textfields[i].char_id = char_id;
	strncpy(ng_textfields[i].plain_text, plain_text ? plain_text : "", sizeof(ng_textfields[i].plain_text) - 1);
	ng_textfields[i].plain_text[sizeof(ng_textfields[i].plain_text) - 1] = '\0';
	strncpy(ng_textfields[i].raw_html_text, raw_html_text ? raw_html_text : "", sizeof(ng_textfields[i].raw_html_text) - 1);
	ng_textfields[i].raw_html_text[sizeof(ng_textfields[i].raw_html_text) - 1] = '\0';
	ng_textfields[i].text_color = text_color;
	ng_textfields[i].font_id = font_id;
	ng_textfields[i].font_height = font_height;
	ng_textfields[i].max_length = max_length;
	ng_textfields[i].align = align;
	ng_textfields[i].left_margin = left_margin;
	ng_textfields[i].right_margin = right_margin;
	ng_textfields[i].indent = indent;
	ng_textfields[i].leading = leading;
	strncpy(ng_textfields[i].variable_name, variable_name ? variable_name : "", sizeof(ng_textfields[i].variable_name) - 1);
	ng_textfields[i].variable_name[sizeof(ng_textfields[i].variable_name) - 1] = '\0';
	ng_textfields[i].flags = flags;
	ng_textfields[i].bounds_xmin = bounds_xmin;
	ng_textfields[i].bounds_xmax = bounds_xmax;
	ng_textfields[i].bounds_ymin = bounds_ymin;
	ng_textfields[i].bounds_ymax = bounds_ymax;
	ng_textfields[i].csm_applied = 0;
	ng_textfield_count++;
}

void ng_record_csm(size_t text_id, const char* anti_alias_type, const char* grid_fit_type,
    float thickness, float sharpness)
{
	int idx = ng_find_textfield(text_id);
	if (idx < 0) return;
	strncpy(ng_textfields[idx].csm_antiAliasType, anti_alias_type ? anti_alias_type : "normal",
	        sizeof(ng_textfields[idx].csm_antiAliasType) - 1);
	ng_textfields[idx].csm_antiAliasType[sizeof(ng_textfields[idx].csm_antiAliasType) - 1] = '\0';
	strncpy(ng_textfields[idx].csm_gridFitType, grid_fit_type ? grid_fit_type : "pixel",
	        sizeof(ng_textfields[idx].csm_gridFitType) - 1);
	ng_textfields[idx].csm_gridFitType[sizeof(ng_textfields[idx].csm_gridFitType) - 1] = '\0';
	ng_textfields[idx].csm_thickness = thickness;
	ng_textfields[idx].csm_sharpness = sharpness;
	ng_textfields[idx].csm_applied = 1;
}

// --- TextField getters ---

int ng_getTextFieldCSMApplied(int idx)
{
	if (idx < 0 || (size_t)idx >= ng_textfield_count) return 0;
	return ng_textfields[idx].csm_applied;
}
const char* ng_getTextFieldCSMAntiAliasType(int idx)
{
	if (idx < 0 || (size_t)idx >= ng_textfield_count) return "normal";
	return ng_textfields[idx].csm_antiAliasType;
}
const char* ng_getTextFieldCSMGridFitType(int idx)
{
	if (idx < 0 || (size_t)idx >= ng_textfield_count) return "pixel";
	return ng_textfields[idx].csm_gridFitType;
}
float ng_getTextFieldCSMThickness(int idx)
{
	if (idx < 0 || (size_t)idx >= ng_textfield_count) return 0.0f;
	return ng_textfields[idx].csm_thickness;
}
float ng_getTextFieldCSMSharpness(int idx)
{
	if (idx < 0 || (size_t)idx >= ng_textfield_count) return 0.0f;
	return ng_textfields[idx].csm_sharpness;
}

u16 ng_getTextFieldFlags(int tf_idx)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) return 0;
	return ng_textfields[tf_idx].flags;
}

u16 ng_getTextFieldFontId(int tf_idx)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) return 0;
	return ng_textfields[tf_idx].font_id;
}

u16 ng_getTextFieldFontHeight(int tf_idx)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) return 0;
	return ng_textfields[tf_idx].font_height;
}

s16 ng_getTextFieldMaxLength(int tf_idx)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) return -1;
	return ng_textfields[tf_idx].max_length;
}

u8 ng_getTextFieldAlign(int tf_idx)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) return 0;
	return ng_textfields[tf_idx].align;
}

u16 ng_getTextFieldLeftMargin(int tf_idx)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) return 0;
	return ng_textfields[tf_idx].left_margin;
}

u16 ng_getTextFieldRightMargin(int tf_idx)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) return 0;
	return ng_textfields[tf_idx].right_margin;
}

s16 ng_getTextFieldIndent(int tf_idx)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) return 0;
	return ng_textfields[tf_idx].indent;
}

s16 ng_getTextFieldLeading(int tf_idx)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) return 0;
	return ng_textfields[tf_idx].leading;
}

const char* ng_getTextFieldVariableName(int tf_idx)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) return "";
	return ng_textfields[tf_idx].variable_name;
}

void ng_getTextFieldBounds(int tf_idx, s32* xmin, s32* xmax, s32* ymin, s32* ymax)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) {
		*xmin = *xmax = *ymin = *ymax = 0;
		return;
	}
	*xmin = ng_textfields[tf_idx].bounds_xmin;
	*xmax = ng_textfields[tf_idx].bounds_xmax;
	*ymin = ng_textfields[tf_idx].bounds_ymin;
	*ymax = ng_textfields[tf_idx].bounds_ymax;
}

const char* ng_getTextFieldRawHtml(int tf_idx)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) return "";
	return ng_textfields[tf_idx].raw_html_text;
}

const char* ng_getTextFieldInitialTextByIdx(int tf_idx)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) return "";
	return ng_textfields[tf_idx].plain_text;
}

u32 ng_getTextFieldColorByIdx(int idx)
{
	if (idx < 0 || (size_t)idx >= ng_textfield_count) return 0;
	return ng_textfields[idx].text_color;
}

int ng_getTextFieldIdxByCharId(size_t char_id)
{
	return ng_find_textfield(char_id);
}

// ---------------------------------------------------------------------------
// Exported symbols registry (DoExportAssets → attachMovie linkage)
// ---------------------------------------------------------------------------
#define MAX_EXPORTED_SYMBOLS 128
static struct {
	char name[128];
	size_t char_id;
	u8 swf_version;
	u8 movie_id;
} ng_exported_symbols[MAX_EXPORTED_SYMBOLS];
static size_t ng_exported_symbol_count = 0;

u8 g_current_movie_id = 0;

size_t ng_lookupExport(const char* name)
{
	size_t result = (size_t)-1;
	for (size_t i = 0; i < ng_exported_symbol_count; i++)
		if (strcasecmp(ng_exported_symbols[i].name, name) == 0)
			result = ng_exported_symbols[i].char_id;
	return result;
}

size_t ng_lookupExportForMovie(const char* name, u8 movie_id)
{
	size_t result = (size_t)-1;
	for (size_t i = 0; i < ng_exported_symbol_count; i++)
		if (ng_exported_symbols[i].movie_id == movie_id
			&& strcasecmp(ng_exported_symbols[i].name, name) == 0)
			result = ng_exported_symbols[i].char_id;
	return result;
}

int ng_lookupExportVersion(const char* name)
{
	int result = 0;
	for (size_t i = 0; i < ng_exported_symbol_count; i++)
		if (strcasecmp(ng_exported_symbols[i].name, name) == 0)
			result = ng_exported_symbols[i].swf_version;
	return result;
}

int ng_lookupExportVersionForMovie(const char* name, u8 movie_id)
{
	int result = 0;
	for (size_t i = 0; i < ng_exported_symbol_count; i++)
		if (ng_exported_symbols[i].movie_id == movie_id
			&& strcasecmp(ng_exported_symbols[i].name, name) == 0)
			result = ng_exported_symbols[i].swf_version;
	return result;
}

const char* ng_lookupExportName(size_t char_id)
{
	for (size_t i = 0; i < ng_exported_symbol_count; i++)
		if (ng_exported_symbols[i].char_id == char_id)
			return ng_exported_symbols[i].name;
	return NULL;
}

int ng_forEachExportName(size_t char_id, int (*callback)(const char* name, void* user_data), void* user_data)
{
	for (size_t i = 0; i < ng_exported_symbol_count; i++)
		if (ng_exported_symbols[i].char_id == char_id)
			if (callback(ng_exported_symbols[i].name, user_data))
				return 1;
	return 0;
}

void tagRegisterExport(SWFAppContext* app_context, const char* name, size_t char_id)
{
	(void)app_context;
	extern int g_swf_version;
	if (ng_exported_symbol_count < MAX_EXPORTED_SYMBOLS) {
		strncpy(ng_exported_symbols[ng_exported_symbol_count].name, name, 127);
		ng_exported_symbols[ng_exported_symbol_count].name[127] = '\0';
		ng_exported_symbols[ng_exported_symbol_count].char_id = char_id;
		ng_exported_symbols[ng_exported_symbol_count].swf_version = (u8)g_swf_version;
		ng_exported_symbols[ng_exported_symbol_count].movie_id = g_current_movie_id;
		ng_exported_symbol_count++;
	}
}

void tagImportCharacter(SWFAppContext* app_context, size_t local_char_id, const char* export_name)
{
	(void)app_context;
	size_t exported_char_id = ng_lookupExport(export_name);
	if (exported_char_id == (size_t)-1 || exported_char_id == 0) return;
	if (local_char_id >= dictionary_capacity || exported_char_id >= dictionary_capacity)
		return;
	dictionary[local_char_id] = dictionary[exported_char_id];
	extern u8* g_char_movie_id;
	extern size_t g_char_movie_id_capacity;
	if (g_char_movie_id != NULL && exported_char_id < g_char_movie_id_capacity
	    && g_char_movie_id[exported_char_id] != 0) {
		if (local_char_id >= g_char_movie_id_capacity) {
			size_t new_cap = local_char_id + 64;
			u8* new_arr = (u8*)calloc(new_cap, 1);
			if (g_char_movie_id) {
				memcpy(new_arr, g_char_movie_id, g_char_movie_id_capacity);
				free(g_char_movie_id);
			}
			g_char_movie_id = new_arr;
			g_char_movie_id_capacity = new_cap;
		}
		g_char_movie_id[local_char_id] = g_char_movie_id[exported_char_id];
	}
	// Register the imported symbol as an export in the importing movie's
	// namespace so attachMovie / ng_lookupExportForMovie can find it.
	// Without this, the symbol is only registered under the source child
	// movie's id, and per-movie attachMovie lookup from the parent fails.
	u8 src_version = 0;
	for (size_t i = 0; i < ng_exported_symbol_count; i++) {
		if (ng_exported_symbols[i].char_id == exported_char_id
		    && strcasecmp(ng_exported_symbols[i].name, export_name) == 0) {
			src_version = ng_exported_symbols[i].swf_version;
			break;
		}
	}
	if (ng_exported_symbol_count < MAX_EXPORTED_SYMBOLS) {
		strncpy(ng_exported_symbols[ng_exported_symbol_count].name, export_name, 127);
		ng_exported_symbols[ng_exported_symbol_count].name[127] = '\0';
		ng_exported_symbols[ng_exported_symbol_count].char_id = local_char_id;
		ng_exported_symbols[ng_exported_symbol_count].swf_version = src_version;
		ng_exported_symbols[ng_exported_symbol_count].movie_id = g_current_movie_id;
		ng_exported_symbol_count++;
	}
}

// ---------------------------------------------------------------------------
// Sound metadata registry
// ---------------------------------------------------------------------------
#define MAX_SOUND_METADATA 128
static struct {
	u16 char_id;
	u8 rate;
	u32 sample_count;
} g_sound_metadata[MAX_SOUND_METADATA];
static size_t g_sound_metadata_count = 0;

int32_t ng_getSoundDuration(u16 char_id)
{
	for (size_t i = 0; i < g_sound_metadata_count; i++) {
		if (g_sound_metadata[i].char_id == char_id) {
			static const u32 rates[] = { 5512, 11025, 22050, 44100 };
			u32 sr = rates[g_sound_metadata[i].rate & 3];
			double dur = (double)g_sound_metadata[i].sample_count * 1000.0 / (double)sr;
			return (int32_t)(dur + 0.5);
		}
	}
	return -1;
}

void ng_registerSoundMetadata(u16 sound_id, u8 rate, u32 sample_count)
{
	if (g_sound_metadata_count < MAX_SOUND_METADATA) {
		g_sound_metadata[g_sound_metadata_count].char_id = sound_id;
		g_sound_metadata[g_sound_metadata_count].rate = rate;
		g_sound_metadata[g_sound_metadata_count].sample_count = sample_count;
		g_sound_metadata_count++;
	}
}

// ---------------------------------------------------------------------------
// Auto instance naming
// ---------------------------------------------------------------------------
static unsigned int ng_auto_instance_counter = 1;

void ng_try_reclaim_auto_instance_name(const char* auto_name)
{
	if (auto_name == NULL) return;
	unsigned int n = 0;
	if (sscanf(auto_name, "instance%u", &n) == 1 && n == ng_auto_instance_counter - 1)
		ng_auto_instance_counter--;
}

unsigned int ng_get_auto_instance_counter(void)
{
	return ng_auto_instance_counter;
}

unsigned int ng_increment_auto_instance_counter(void)
{
	return ng_auto_instance_counter++;
}

// ---------------------------------------------------------------------------
// Child enumeration (for for-in over MovieClip children)
// ---------------------------------------------------------------------------

void ng_enumerateChildren(const char* parent_name,
    void (*callback)(const char* name, u32 name_len, void* user_data), void* user_data)
{
	if (parent_name != NULL && parent_name[0] != '\0')
	{
		extern size_t ng_findDisplayEntryByName(const char* name);
		size_t parent_depth = ng_findDisplayEntryByName(parent_name);
		if (parent_depth == SIZE_MAX) return;

		DisplayObject* parent_obj = &display_list[parent_depth];
		if (parent_obj->sprite_display_list == NULL) return;

		for (size_t d = 1; d <= parent_obj->sprite_max_depth; d++)
		{
			DisplayObject* child = &parent_obj->sprite_display_list[d];
			if (child->char_id == 0) continue;
			if (child->instance_name != NULL && child->instance_name[0] != '\0')
				callback(child->instance_name, (u32)strlen(child->instance_name), user_data);
		}
	}
	else
	{
		for (size_t d = 0; d <= max_depth; d++)
		{
			if (display_list[d].char_id == 0) continue;
			if (display_list[d].instance_name != NULL && display_list[d].instance_name[0] != '\0')
				callback(display_list[d].instance_name, (u32)strlen(display_list[d].instance_name), user_data);
		}
	}
}

// ---------------------------------------------------------------------------
// Text measurement functions
// ---------------------------------------------------------------------------

static u16 ng_decode_utf8_char(const char* text, size_t text_len, size_t* pos)
{
	unsigned char c = (unsigned char)text[*pos];
	u16 cp = c;
	if (c >= 0xC0 && c < 0xE0 && *pos + 1 < text_len) {
		cp = ((c & 0x1F) << 6) | ((unsigned char)text[*pos + 1] & 0x3F);
		*pos += 2;
	} else if (c >= 0xE0 && c < 0xF0 && *pos + 2 < text_len) {
		cp = ((c & 0x0F) << 12) | (((unsigned char)text[*pos + 1] & 0x3F) << 6) | ((unsigned char)text[*pos + 2] & 0x3F);
		*pos += 3;
	} else {
		*pos += 1;
	}
	return cp;
}

static int ng_device_font_mode = 0;
void ng_setDeviceFontMode(int mode) { ng_device_font_mode = mode; }

static int ng_round_to_pixel(int twips) {
	double px = (double)twips / 20.0;
	int rounded_px = (px >= 0) ? (int)(px + 0.5) : -(int)(-px + 0.5);
	return rounded_px * 20;
}

static int ng_round_ls_to_pixel(int ls_twips) {
	if (ls_twips == 0) return 0;
	double px = (double)ls_twips / 20.0;
	double frac = px - (int)px;
	int rounded_px;
	if (frac == 0.5 || frac == -0.5) {
		int trunc = (int)px;
		rounded_px = (trunc % 2 == 0) ? trunc : trunc + (px > 0 ? 1 : -1);
	} else {
		rounded_px = (px >= 0) ? (int)(px + 0.5) : -(int)(-px + 0.5);
	}
	return rounded_px * 20;
}

// Tab stop state
static int g_tab_stops_twips[64];
static int g_tab_stop_count = 0;
static u16 g_tab_font_height = 0;

void ng_setTabStops(const int* stops_twips, int count, u16 font_height)
{
	g_tab_stop_count = count > 64 ? 64 : count;
	for (int i = 0; i < g_tab_stop_count; i++) g_tab_stops_twips[i] = stops_twips[i];
	g_tab_font_height = font_height;
}

void ng_clearTabStops(void) { g_tab_stop_count = 0; g_tab_font_height = 0; }

static int ng_next_tab_stop(int cursor_twips)
{
	if (g_tab_stop_count > 0) {
		for (int i = 0; i < g_tab_stop_count; i++) {
			if (g_tab_stops_twips[i] > cursor_twips)
				return g_tab_stops_twips[i];
		}
		return cursor_twips;
	}
	int modulo = (int)(g_tab_font_height * 2.7f);
	if (modulo <= 0) return cursor_twips;
	return ((cursor_twips / modulo) + 1) * modulo;
}

static int ng_measure_substr_twips(int font_idx, int em, u16 font_height,
    const char* text, size_t start, size_t end, int letter_spacing_twips)
{
	int w = 0;
	int ls_rounded = ng_device_font_mode ? ng_round_ls_to_pixel(letter_spacing_twips) : 0;
	size_t i = start;
	while (i < end) {
		u16 cp = ng_decode_utf8_char(text, end, &i);
		s16 adv = ng_font_glyph_advance(font_idx, cp);
		int glyph_twips = 0;
		if (adv >= 0) {
			int raw = (int)((float)adv * (float)font_height / (float)em);
			if (ng_device_font_mode) {
				int unspaced = ng_round_to_pixel(raw);
				if (ls_rounded != 0) {
					int spaced = unspaced + ls_rounded;
					glyph_twips = (spaced > 0) ? spaced : unspaced;
				} else {
					glyph_twips = unspaced;
				}
			} else {
				glyph_twips = raw + letter_spacing_twips;
				if (glyph_twips <= 0 && letter_spacing_twips < 0)
					glyph_twips = raw;
			}
		} else if (ng_device_font_mode ? (ls_rounded > 0) : (letter_spacing_twips > 0)) {
			glyph_twips = ng_device_font_mode ? ls_rounded : letter_spacing_twips;
		}
		w += glyph_twips;
	}
	return w;
}

static int ng_wrap_count_lines(int font_idx, int em, u16 font_height,
    const char* text, size_t text_len, int field_width_twips, int swf_version,
    int left_margin_twips, int right_margin_twips, int indent_twips,
    int* max_width_out, int* max_width_full_out, int letter_spacing_twips)
{
	if (text_len == 0) {
		*max_width_out = 0;
		if (max_width_full_out) *max_width_full_out = 0;
		return 1;
	}

	int line_count = 1;
	int base_avail = field_width_twips - left_margin_twips - right_margin_twips;
	if (base_avail < 0) base_avail = 0;
	int first_line_offset = indent_twips > 0 ? indent_twips : 0;
	int cur_avail = base_avail - first_line_offset;
	if (cur_avail < 0) cur_avail = 0;
	int cur_line_w = 0;
	int trimmed_line_w = 0;
	int max_line_w = 0;
	int max_line_w_full = 0;
	int is_swf8 = (swf_version >= 8);

	size_t seg_start = 0;

	while (seg_start < text_len) {
		if ((unsigned char)text[seg_start] == '\t') {
			int next_tab = ng_next_tab_stop(cur_line_w);
			if (next_tab > cur_line_w) {
				cur_line_w = next_tab;
				trimmed_line_w = cur_line_w;
				if (trimmed_line_w > max_line_w) max_line_w = trimmed_line_w;
				if (cur_line_w > max_line_w_full) max_line_w_full = cur_line_w;
			}
			seg_start++;
			continue;
		}

		size_t seg_end = text_len;
		size_t i = seg_start;

		if (is_swf8) {
			int in_spaces = 0;
			while (i < text_len) {
				unsigned char c = (unsigned char)text[i];
				if (c == '\t') {
					seg_end = i;
					break;
				} else if (c == ' ') {
					in_spaces = 1;
					i++;
				} else if (in_spaces) {
					seg_end = i;
					break;
				} else if (c == '-') {
					i++;
					seg_end = i;
					break;
				} else {
					if (c >= 0xC0 && c < 0xE0) i += 2;
					else if (c >= 0xE0 && c < 0xF0) i += 3;
					else if (c >= 0xF0) i += 4;
					else i++;
					in_spaces = 0;
				}
			}
		} else {
			while (i < text_len) {
				unsigned char c = (unsigned char)text[i];
				if (c == '\t') {
					seg_end = i;
					break;
				} else if (c == ' ') {
					i++;
					seg_end = i;
					break;
				} else if (c == '-') {
					if (i == seg_start) {
						i++;
						seg_end = i;
					} else {
						seg_end = i;
					}
					break;
				} else {
					if (c >= 0xC0 && c < 0xE0) i += 2;
					else if (c >= 0xE0 && c < 0xF0) i += 3;
					else if (c >= 0xF0) i += 4;
					else i++;
				}
			}
		}

		int seg_w = ng_measure_substr_twips(font_idx, em, font_height, text, seg_start, seg_end, letter_spacing_twips);

		int seg_trimmed_w = seg_w;
		if (is_swf8) {
			size_t trimmed_end = seg_end;
			while (trimmed_end > seg_start && (unsigned char)text[trimmed_end - 1] == ' ')
				trimmed_end--;
			if (trimmed_end < seg_end)
				seg_trimmed_w = ng_measure_substr_twips(font_idx, em, font_height, text, seg_start, trimmed_end, letter_spacing_twips);
		}

		int test_w = cur_line_w + (is_swf8 ? seg_trimmed_w : seg_w);
		if (test_w <= cur_avail) {
			cur_line_w += seg_w;
			if (is_swf8) {
				trimmed_line_w = cur_line_w - (seg_w - seg_trimmed_w);
			} else {
				trimmed_line_w = cur_line_w;
			}
			if (trimmed_line_w > max_line_w) max_line_w = trimmed_line_w;
			if (cur_line_w > max_line_w_full) max_line_w_full = cur_line_w;
			seg_start = seg_end;
		} else if (cur_line_w == 0) {
			size_t char_pos = seg_start;
			int char_w = 0;
			int last_fitting_pos = seg_start;
			int last_fitting_w = 0;
			int _wr_ls = ng_device_font_mode ? ng_round_ls_to_pixel(letter_spacing_twips) : 0;
			while (char_pos < seg_end) {
				size_t next_pos = char_pos;
				u16 cp = ng_decode_utf8_char(text, seg_end, &next_pos);
				s16 adv = ng_font_glyph_advance(font_idx, cp);
				int gw = 0;
				if (adv >= 0) {
					int raw = (int)((float)adv * (float)font_height / (float)em);
					if (ng_device_font_mode) {
						int unsp = ng_round_to_pixel(raw);
						if (_wr_ls != 0) { int sp = unsp + _wr_ls; gw = (sp > 0) ? sp : unsp; }
						else gw = unsp;
					} else {
						gw = raw + letter_spacing_twips;
						if (gw <= 0 && letter_spacing_twips < 0) gw = raw;
					}
				} else if (ng_device_font_mode ? (_wr_ls > 0) : (letter_spacing_twips > 0)) {
					gw = ng_device_font_mode ? _wr_ls : letter_spacing_twips;
				}
				if (char_w + gw > cur_avail && last_fitting_pos > (int)seg_start) {
					break;
				}
				char_w += gw;
				last_fitting_pos = next_pos;
				last_fitting_w = char_w;
				if (is_swf8 && last_fitting_pos > (int)seg_start && char_w > cur_avail) {
					break;
				}
				char_pos = next_pos;
			}
			if (last_fitting_pos == (int)seg_start) {
				size_t tmp = seg_start;
				ng_decode_utf8_char(text, seg_end, &tmp);
				last_fitting_pos = tmp;
				last_fitting_w = ng_measure_substr_twips(font_idx, em, font_height, text, seg_start, last_fitting_pos, letter_spacing_twips);
			}
			if (last_fitting_w > max_line_w) max_line_w = last_fitting_w;
			if (last_fitting_w > max_line_w_full) max_line_w_full = last_fitting_w;
			line_count++;
			cur_line_w = 0;
			trimmed_line_w = 0;
			cur_avail = base_avail;
			seg_start = last_fitting_pos;
		} else {
			if (trimmed_line_w > max_line_w) max_line_w = trimmed_line_w;
			if (cur_line_w > max_line_w_full) max_line_w_full = cur_line_w;
			line_count++;
			cur_line_w = 0;
			trimmed_line_w = 0;
			cur_avail = base_avail;
		}
	}

	if (trimmed_line_w > max_line_w) max_line_w = trimmed_line_w;
	if (cur_line_w > max_line_w_full) max_line_w_full = cur_line_w;

	*max_width_out = max_line_w;
	if (max_width_full_out) *max_width_full_out = max_line_w_full;
	return line_count;
}

int ng_computeTextWidth(u16 font_id, u16 font_height, const char* text, size_t text_len,
    int word_wrap, int field_width_twips, int swf_version,
    int left_margin_twips, int right_margin_twips, int indent_twips, int align,
    int letter_spacing_twips)
{
	int fi = ng_find_font_with_metrics(font_id);
	if (fi < 0 || text == NULL || text_len == 0) return 0;

	int em = ng_fonts[fi].em_square;
	if (em <= 0) em = 1024;

	if (!word_wrap || field_width_twips <= 0) {
		int trim_trailing = (swf_version >= 8 && align != 0);
		int max_width_twips = 0;
		int cur_width_twips = 0;
		int cur_trimmed_twips = 0;
		int _tw_ls_r = ng_device_font_mode ? ng_round_ls_to_pixel(letter_spacing_twips) : 0;
		for (size_t i = 0; i < text_len; ) {
			unsigned char c = (unsigned char)text[i];
			if (c == '\r' || c == '\n') {
				if (trim_trailing && cur_trimmed_twips < cur_width_twips)
					cur_width_twips = cur_trimmed_twips;
				if (cur_width_twips > max_width_twips) max_width_twips = cur_width_twips;
				cur_width_twips = 0;
				cur_trimmed_twips = 0;
				i++;
				continue;
			}
			if (c == '\t') {
				int next_tab = ng_next_tab_stop(cur_width_twips);
				if (next_tab > cur_width_twips)
					cur_width_twips = next_tab;
				cur_trimmed_twips = cur_width_twips;
				i++;
				continue;
			}
			u16 code_point = ng_decode_utf8_char(text, text_len, &i);
			s16 adv = ng_font_glyph_advance(fi, code_point);
			int glyph_twips = 0;
			if (adv >= 0) {
				int raw = (int)((float)adv * (float)font_height / (float)em);
				if (ng_device_font_mode) {
					int unspaced = ng_round_to_pixel(raw);
					if (_tw_ls_r != 0) {
						int spaced = unspaced + _tw_ls_r;
						glyph_twips = (spaced > 0) ? spaced : unspaced;
					} else {
						glyph_twips = unspaced;
					}
				} else {
					glyph_twips = raw + letter_spacing_twips;
					if (glyph_twips <= 0 && letter_spacing_twips < 0)
						glyph_twips = raw;
				}
			} else if (ng_device_font_mode ? (_tw_ls_r > 0) : (letter_spacing_twips > 0)) {
				glyph_twips = ng_device_font_mode ? _tw_ls_r : letter_spacing_twips;
			}
			cur_width_twips += glyph_twips;
			if (trim_trailing) {
				if (code_point != ' ')
					cur_trimmed_twips = cur_width_twips;
			}
		}
		if (trim_trailing && cur_trimmed_twips < cur_width_twips)
			cur_width_twips = cur_trimmed_twips;
		if (cur_width_twips > max_width_twips) max_width_twips = cur_width_twips;
		return max_width_twips;
	}

	int use_full = (swf_version >= 8 && align == 0);
	int max_width_twips = 0;
	size_t line_start = 0;
	for (size_t i = 0; i <= text_len; i++) {
		int is_end = (i == text_len);
		int is_newline = (!is_end && (text[i] == '\r' || text[i] == '\n'));
		if (is_end || is_newline) {
			int line_max_w = 0, line_max_w_full = 0;
			ng_wrap_count_lines(fi, em, font_height, text + line_start, i - line_start,
			    field_width_twips, swf_version,
			    left_margin_twips, right_margin_twips, indent_twips,
			    &line_max_w, &line_max_w_full, letter_spacing_twips);
			int w = use_full ? line_max_w_full : line_max_w;
			if (w > max_width_twips) max_width_twips = w;
			line_start = i + 1;
		}
	}
	return max_width_twips;
}

int ng_computeTextHeight(u16 font_id, u16 font_height, s16 leading_twips, const char* text, size_t text_len,
    int word_wrap, int field_width_twips, int swf_version,
    int left_margin_twips, int right_margin_twips, int indent_twips,
    int letter_spacing_twips)
{
	int fi = ng_find_font_with_metrics(font_id);
	if (fi < 0) return 0;

	int em = ng_fonts[fi].em_square;
	if (em <= 0) em = 1024;

	int ascent_twips = (int)((float)ng_fonts[fi].ascent * (float)font_height / (float)em);
	int descent_twips = (int)((float)ng_fonts[fi].descent * (float)font_height / (float)em);

	if (text == NULL || text_len == 0) return 0;

	int line_count = 1;
	{
		if (!word_wrap || field_width_twips <= 0) {
			for (size_t i = 0; i < text_len; i++) {
				if (text[i] == '\r' || text[i] == '\n') {
					line_count++;
				}
			}
		} else {
			line_count = 0;
			size_t line_start = 0;
			for (size_t i = 0; i <= text_len; i++) {
				int is_end = (i == text_len);
				int is_newline = (!is_end && (text[i] == '\r' || text[i] == '\n'));
				if (is_end || is_newline) {
					int dummy_w = 0;
					line_count += ng_wrap_count_lines(fi, em, font_height,
					    text + line_start, i - line_start,
					    field_width_twips, swf_version,
					    left_margin_twips, right_margin_twips, indent_twips, &dummy_w, NULL,
					    letter_spacing_twips);
					line_start = i + 1;
				}
			}
			if (line_count == 0) line_count = 1;
		}
	}

	int leading_count = line_count > 1 ? line_count - 1 : 1;
	int total_twips = line_count * (ascent_twips + descent_twips) + leading_count * (int)leading_twips;

	return total_twips;
}

int ng_computeTextLineCount(u16 font_id, u16 font_height, const char* text, size_t text_len,
    int word_wrap, int field_width_twips, int swf_version,
    int left_margin_twips, int right_margin_twips, int indent_twips,
    int letter_spacing_twips)
{
	int fi = ng_find_font_with_metrics(font_id);
	if (fi < 0) return 1;

	int em = ng_fonts[fi].em_square;
	if (em <= 0) em = 1024;

	int line_count = 1;
	if (text != NULL && text_len > 0) {
		if (!word_wrap || field_width_twips <= 0) {
			for (size_t i = 0; i < text_len; i++) {
				if (text[i] == '\r' || text[i] == '\n') {
					line_count++;
				}
			}
		} else {
			line_count = 0;
			size_t line_start = 0;
			for (size_t i = 0; i <= text_len; i++) {
				int is_end = (i == text_len);
				int is_newline = (!is_end && (text[i] == '\r' || text[i] == '\n'));
				if (is_end || is_newline) {
					int dummy_w = 0;
					line_count += ng_wrap_count_lines(fi, em, font_height,
					    text + line_start, i - line_start,
					    field_width_twips, swf_version,
					    left_margin_twips, right_margin_twips, indent_twips, &dummy_w, NULL,
					    letter_spacing_twips);
					line_start = i + 1;
				}
			}
			if (line_count == 0) line_count = 1;
		}
	}
	return line_count;
}

int ng_computeVisibleLines(u16 font_id, u16 font_height, s16 leading_twips, float field_height_pixels)
{
	int fi = ng_find_font_with_metrics(font_id);
	if (fi < 0) return 1;

	int em = ng_fonts[fi].em_square;
	if (em <= 0) em = 1024;

	int ascent_twips = (int)((float)ng_fonts[fi].ascent * (float)font_height / (float)em);
	int descent_twips = (int)((float)ng_fonts[fi].descent * (float)font_height / (float)em);
	int line_height_twips = ascent_twips + descent_twips + (int)leading_twips;
	if (line_height_twips <= 0) return 1;

	int avail_twips = (int)(field_height_pixels * 20.0f) - 80;
	if (avail_twips <= 0) return 1;

	int first_line_twips = ascent_twips + descent_twips;
	if (avail_twips < first_line_twips) return 1;

	int remaining = avail_twips - first_line_twips;
	int extra_lines = remaining / line_height_twips;
	return 1 + extra_lines;
}

static int ng_measure_substr_mixed_twips(int font_idx, int em,
    const char* text, size_t start, size_t end, int letter_spacing_twips,
    const u32* run_starts, const u32* run_lengths, const u16* run_font_heights,
    int run_count, u16 base_font_height)
{
	int w = 0;
	int ls_rounded = ng_device_font_mode ? ng_round_ls_to_pixel(letter_spacing_twips) : 0;
	size_t i = start;
	while (i < end) {
		size_t prev_i = i;
		u16 cp = ng_decode_utf8_char(text, end, &i);
		u16 fh = base_font_height;
		for (int r = 0; r < run_count; r++) {
			if (prev_i >= run_starts[r] && prev_i < run_starts[r] + run_lengths[r]) {
				fh = run_font_heights[r]; break;
			}
		}
		s16 adv = ng_font_glyph_advance(font_idx, cp);
		int glyph_twips = 0;
		if (adv >= 0) {
			int raw = (int)((float)adv * (float)fh / (float)em);
			if (ng_device_font_mode) {
				int unspaced = ng_round_to_pixel(raw);
				if (ls_rounded != 0) {
					int spaced = unspaced + ls_rounded;
					glyph_twips = (spaced > 0) ? spaced : unspaced;
				} else {
					glyph_twips = unspaced;
				}
			} else {
				glyph_twips = raw + letter_spacing_twips;
				if (glyph_twips <= 0 && letter_spacing_twips < 0)
					glyph_twips = raw;
			}
		} else if (ng_device_font_mode ? (ls_rounded > 0) : (letter_spacing_twips > 0)) {
			glyph_twips = ng_device_font_mode ? ls_rounded : letter_spacing_twips;
		}
		w += glyph_twips;
	}
	return w;
}

void ng_computeScrollMixedFont(u16 font_id, u16 base_font_height, s16 leading_twips,
    const char* text, size_t text_len,
    int word_wrap, int field_width_twips, int swf_version,
    int left_margin_twips, int right_margin_twips, int indent_twips,
    int letter_spacing_twips,
    float field_height_pixels, int scroll,
    const u32* run_starts, const u32* run_lengths, const u16* run_font_heights, int run_count,
    int* out_maxscroll, int* out_bottomscroll, int* out_text_height_twips)
{
	int fi = ng_find_font_with_metrics(font_id);
	if (fi < 0) { if (out_maxscroll) *out_maxscroll = 1; if (out_bottomscroll) *out_bottomscroll = 1; if (out_text_height_twips) *out_text_height_twips = 0; return; }

	int em = ng_fonts[fi].em_square;
	if (em <= 0) em = 1024;

	#define MAX_LAYOUT_LINES 256
	int line_offsets[MAX_LAYOUT_LINES];
	int line_extents[MAX_LAYOUT_LINES];
	int total_visual_lines = 0;

	#define GET_FONT_HEIGHT_AT(pos) ({ \
		u16 _fh = base_font_height; \
		for (int _r = 0; _r < run_count; _r++) { \
			if ((pos) >= run_starts[_r] && (pos) < run_starts[_r] + run_lengths[_r]) { \
				_fh = run_font_heights[_r]; break; \
			} \
		} \
		_fh; \
	})

	int cursor_y = 0;
	size_t line_start = 0;
	int last_line_was_empty = 0;

	for (size_t i = 0; i <= text_len; i++) {
		int is_end = (i == text_len);
		int is_newline = (!is_end && (text[i] == '\r' || text[i] == '\n'));
		if (!is_end && !is_newline) continue;

		const char* hline = text + line_start;
		size_t hline_len = i - line_start;

		u16 terminator_fh = 0;
		if (is_newline && run_count > 0) {
			for (int r = 0; r < run_count; r++) {
				u32 rs = run_starts[r], rl = run_lengths[r];
				if ((u32)i >= rs && (u32)i < rs + rl) {
					terminator_fh = run_font_heights[r];
					break;
				}
			}
		}

		if (!word_wrap || field_width_twips <= 0 || hline_len == 0) {
			u16 max_fh = 0;
			if (run_count > 0) {
				for (int r = 0; r < run_count; r++) {
					u32 rs = run_starts[r], rl = run_lengths[r];
					if (rs < (u32)i && rs + rl > (u32)line_start) {
						if (run_font_heights[r] > max_fh) max_fh = run_font_heights[r];
					}
				}
			}
			if (terminator_fh > max_fh) max_fh = terminator_fh;
			if (max_fh == 0) max_fh = base_font_height;
			int asc = (int)((float)ng_fonts[fi].ascent * (float)max_fh / (float)em);
			int desc = (int)((float)ng_fonts[fi].descent * (float)max_fh / (float)em);
			int lh = asc + desc;

			if (total_visual_lines == 0) {
				lh += (int)leading_twips;
			}

			last_line_was_empty = (hline_len == 0 && is_end);
			if (total_visual_lines < MAX_LAYOUT_LINES) {
				line_offsets[total_visual_lines] = cursor_y;
				line_extents[total_visual_lines] = cursor_y + lh;
			}
			total_visual_lines++;
			cursor_y += asc + desc + (int)leading_twips;
		} else {
			int base_avail = field_width_twips - left_margin_twips - right_margin_twips;
			if (base_avail < 0) base_avail = 0;
			int first_line_offset = indent_twips > 0 ? indent_twips : 0;
			int cur_avail = (total_visual_lines == 0) ? (base_avail - first_line_offset) : base_avail;
			int is_swf8 = (swf_version >= 8);

			size_t seg_start = 0;
			int cur_line_w = 0;
			u16 cur_line_max_fh = 0;
			int is_first_visual_line_in_para = 1;
			(void)is_first_visual_line_in_para;

			while (seg_start < hline_len) {
				size_t seg_end = seg_start;
				if (is_swf8) {
					int in_space = (hline[seg_end] == ' ');
					while (seg_end < hline_len) {
						if (hline[seg_end] == '-' && seg_end > seg_start) { seg_end++; break; }
						int cur_space = (hline[seg_end] == ' ');
						if (in_space && !cur_space && seg_end > seg_start) break;
						in_space = cur_space;
						seg_end++;
					}
				} else {
					while (seg_end < hline_len && hline[seg_end] != ' ' && hline[seg_end] != '-') seg_end++;
					if (seg_end < hline_len) {
						if (hline[seg_end] == '-') seg_end++;
						else seg_end++;
					}
				}

				u16 seg_max_fh = 0;
				if (run_count > 0) {
					size_t abs_seg_start = line_start + seg_start;
					size_t abs_seg_end = line_start + seg_end;
					for (int r = 0; r < run_count; r++) {
						u32 rs = run_starts[r], rl = run_lengths[r];
						if (rs < (u32)abs_seg_end && rs + rl > (u32)abs_seg_start) {
							if (run_font_heights[r] > seg_max_fh) seg_max_fh = run_font_heights[r];
						}
					}
				}
				if (seg_max_fh == 0) seg_max_fh = base_font_height;

				int seg_w = ng_measure_substr_mixed_twips(fi, em,
					text, line_start + seg_start, line_start + seg_end, letter_spacing_twips,
					run_starts, run_lengths, run_font_heights, run_count, base_font_height);

				size_t trim_end = seg_end;
				if (is_swf8) { while (trim_end > seg_start && hline[trim_end-1] == ' ') trim_end--; }
				int seg_trimmed_w = (trim_end < seg_end) ?
					ng_measure_substr_mixed_twips(fi, em,
						text, line_start + seg_start, line_start + trim_end, letter_spacing_twips,
						run_starts, run_lengths, run_font_heights, run_count, base_font_height) : seg_w;

				int test_w = cur_line_w + (is_swf8 ? seg_trimmed_w : seg_w);

				if (test_w <= cur_avail) {
					cur_line_w += seg_w;
					if (seg_max_fh > cur_line_max_fh) cur_line_max_fh = seg_max_fh;
					seg_start = seg_end;
				} else if (cur_line_w == 0) {
					if (seg_max_fh > cur_line_max_fh) cur_line_max_fh = seg_max_fh;
					size_t char_pos = seg_start;
					int char_w = 0;
					size_t last_fitting_pos = seg_start;
					while (char_pos < seg_end) {
						size_t next_pos = char_pos;
						u16 cp = ng_decode_utf8_char(hline, seg_end, &next_pos);
						s16 adv = ng_font_glyph_advance(fi, cp);
						int gw = 0;
						if (adv >= 0) {
							u16 cfh = GET_FONT_HEIGHT_AT(line_start + char_pos);
							gw = (int)((float)adv * (float)cfh / (float)em);
						}
						if (char_w + gw > cur_avail && last_fitting_pos > seg_start) break;
						char_w += gw;
						last_fitting_pos = next_pos;
						if (is_swf8 && last_fitting_pos > seg_start && char_w > cur_avail) break;
						char_pos = next_pos;
					}
					if (last_fitting_pos == seg_start) {
						size_t tmp = seg_start;
						ng_decode_utf8_char(hline, seg_end, &tmp);
						last_fitting_pos = tmp;
					}

					u16 fh = cur_line_max_fh > 0 ? cur_line_max_fh : base_font_height;
					int asc = (int)((float)ng_fonts[fi].ascent * (float)fh / (float)em);
					int desc = (int)((float)ng_fonts[fi].descent * (float)fh / (float)em);
					int lh = asc + desc;
					if (total_visual_lines == 0) lh += (int)leading_twips;
					if (total_visual_lines < MAX_LAYOUT_LINES) {
						line_offsets[total_visual_lines] = cursor_y;
						line_extents[total_visual_lines] = cursor_y + lh;
					}
					total_visual_lines++;
					cursor_y += asc + desc + (int)leading_twips;

					cur_line_w = 0;
					cur_line_max_fh = 0;
					cur_avail = base_avail;
					seg_start = last_fitting_pos;
				} else {
					u16 fh = cur_line_max_fh > 0 ? cur_line_max_fh : base_font_height;
					int asc = (int)((float)ng_fonts[fi].ascent * (float)fh / (float)em);
					int desc = (int)((float)ng_fonts[fi].descent * (float)fh / (float)em);
					int lh = asc + desc;
					if (total_visual_lines == 0) lh += (int)leading_twips;
					if (total_visual_lines < MAX_LAYOUT_LINES) {
						line_offsets[total_visual_lines] = cursor_y;
						line_extents[total_visual_lines] = cursor_y + lh;
					}
					total_visual_lines++;
					cursor_y += asc + desc + (int)leading_twips;

					cur_line_w = 0;
					cur_line_max_fh = 0;
					cur_avail = base_avail;
				}
			}

			if (terminator_fh > cur_line_max_fh) cur_line_max_fh = terminator_fh;
			u16 fh = cur_line_max_fh > 0 ? cur_line_max_fh : base_font_height;
			int asc = (int)((float)ng_fonts[fi].ascent * (float)fh / (float)em);
			int desc = (int)((float)ng_fonts[fi].descent * (float)fh / (float)em);
			int lh = asc + desc;
			if (total_visual_lines == 0) lh += (int)leading_twips;
			if (total_visual_lines < MAX_LAYOUT_LINES) {
				line_offsets[total_visual_lines] = cursor_y;
				line_extents[total_visual_lines] = cursor_y + lh;
			}
			total_visual_lines++;
			cursor_y += asc + desc + (int)leading_twips;
		}

		line_start = i + 1;
	}

	if (total_visual_lines == 0) {
		if (out_maxscroll) *out_maxscroll = 1;
		if (out_bottomscroll) *out_bottomscroll = 1;
		if (out_text_height_twips) *out_text_height_twips = 0;
		return;
	}

	int full_last_idx = (total_visual_lines - 1 < MAX_LAYOUT_LINES) ? total_visual_lines - 1 : MAX_LAYOUT_LINES - 1;
	int full_text_height = line_extents[full_last_idx] - line_offsets[0];

	int reported_text_height = full_text_height;
	if (last_line_was_empty && total_visual_lines > 1) {
		int th_last_idx = (total_visual_lines - 2 < MAX_LAYOUT_LINES) ? total_visual_lines - 2 : MAX_LAYOUT_LINES - 1;
		reported_text_height = line_extents[th_last_idx] - line_offsets[0];
	}

	if (out_text_height_twips) *out_text_height_twips = reported_text_height;

	int window_height = (int)(field_height_pixels * 20.0f) - 80;
	if (window_height <= 0) window_height = 1;

	int target = full_text_height - window_height;
	int maxscroll = 1;
	if (target > 0) {
		for (int i = 0; i < total_visual_lines && i < MAX_LAYOUT_LINES; i++) {
			if (line_offsets[i] >= target) {
				maxscroll = i + 1;
				break;
			}
			maxscroll = i + 1;
		}
	}
	if (maxscroll < 1) maxscroll = 1;
	if (out_maxscroll) *out_maxscroll = maxscroll;

	if (out_bottomscroll) {
		int scroll_idx = scroll - 1;
		if (scroll_idx < 0) scroll_idx = 0;
		if (scroll_idx >= total_visual_lines) scroll_idx = total_visual_lines - 1;
		int scroll_offset = (scroll_idx < MAX_LAYOUT_LINES) ? line_offsets[scroll_idx] : 0;
		int bottom_target = window_height + scroll_offset;

		int bottomscroll = total_visual_lines;
		for (int i = 0; i < total_visual_lines && i < MAX_LAYOUT_LINES; i++) {
			if (line_extents[i] > bottom_target) {
				bottomscroll = i;
				if (bottomscroll < 1) bottomscroll = 1;
				break;
			}
		}
		if (bottomscroll < 1) bottomscroll = 1;
		*out_bottomscroll = bottomscroll;
	}
	#undef MAX_LAYOUT_LINES
	#undef GET_FONT_HEIGHT_AT
}

void ng_getTextExtent(u16 font_id, double font_size_px, const char* text, size_t text_len,
    double width_px, double* out_ascent, double* out_descent,
    double* out_width, double* out_height, double* out_tf_height, double* out_tf_width)
{
	int fi = ng_find_font_with_metrics(font_id);
	if (fi < 0) {
		*out_ascent = *out_descent = *out_width = *out_height = *out_tf_height = *out_tf_width = 0;
		return;
	}

	int em = ng_fonts[fi].em_square;
	if (em <= 0) em = 1024;

	double scale = font_size_px / (double)em;
	double ascent_px = ng_fonts[fi].ascent * scale;
	double descent_px = ng_fonts[fi].descent * scale;

	if (out_ascent) *out_ascent = ascent_px;
	if (out_descent) *out_descent = descent_px;

	u16 font_height_twips = (u16)(font_size_px * 20.0);
	double line_height_px = ascent_px + descent_px;

	if (text == NULL || text_len == 0) {
		if (out_width) *out_width = 0;
		if (out_height) *out_height = line_height_px;
		if (out_tf_height) *out_tf_height = line_height_px + 4.0;
		if (out_tf_width) *out_tf_width = 4.0;
		return;
	}

	int has_wrap = (width_px > 0);
	int field_width_twips = has_wrap ? (int)(width_px * 20.0) : 0;

	int max_w_twips = 0;
	int line_count = 1;
	if (!has_wrap) {
		for (size_t i = 0; i < text_len; ) {
			unsigned char c = (unsigned char)text[i];
			if (c == '\r' || c == '\n') { line_count++; i++; continue; }
			i++;
		}
		max_w_twips = ng_measure_substr_twips(fi, em, font_height_twips, text, 0, text_len, 0);
	} else {
		line_count = 0;
		size_t line_start = 0;
		for (size_t i = 0; i <= text_len; i++) {
			int is_end = (i == text_len);
			int is_newline = (!is_end && (text[i] == '\r' || text[i] == '\n'));
			if (is_end || is_newline) {
				int line_max_w = 0;
				line_count += ng_wrap_count_lines(fi, em, font_height_twips,
				    text + line_start, i - line_start,
				    field_width_twips, 8, 0, 0, 0, &line_max_w, NULL, 0);
				if (line_max_w > max_w_twips) max_w_twips = line_max_w;
				line_start = i + 1;
			}
		}
		if (line_count == 0) line_count = 1;
	}

	double text_width_px = (double)max_w_twips / 20.0;
	double text_height_px = line_count * line_height_px;

	if (out_width) *out_width = text_width_px;
	if (out_height) *out_height = text_height_px;
	if (out_tf_height) *out_tf_height = text_height_px + 4.0;
	// When a wrap width is provided, textFieldWidth equals that constraint
	// (Flash AutoSize::Left + word_wrap preserves the assigned width). Without
	// wrap, AutoSize::Left expands to fit content + 4px gutter.
	if (out_tf_width) *out_tf_width = has_wrap ? width_px : (text_width_px + 4.0);
}

int ng_getCharIndexAtPoint(int tf_idx, float local_x_px, float local_y_px,
                           const char* text, size_t text_len)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) return 0;

	u16 font_id = ng_textfields[tf_idx].font_id;
	u16 font_height = ng_textfields[tf_idx].font_height;
	if (text == NULL) {
		text = ng_textfields[tf_idx].plain_text;
		text_len = strlen(text);
	}
	s16 leading = ng_textfields[tf_idx].leading;
	u16 left_margin = ng_textfields[tf_idx].left_margin;

	int fi = ng_find_font_with_metrics(font_id);
	if (fi < 0 || text_len == 0) return 0;

	int em = ng_fonts[fi].em_square;
	if (em <= 0) em = 1024;

	float gutter_px = 2.0f;
	float left_margin_px = (float)left_margin / 20.0f;

	s16 ascent = 0, descent = 0;
	int em_sq = 0;
	ng_font_get_metrics(fi, &ascent, &descent, &em_sq);
	if (em_sq <= 0) em_sq = em;
	float line_height_twips = (float)(ascent + descent) / (float)em_sq * (float)font_height + (float)leading;
	float line_height_px = line_height_twips / 20.0f;
	if (line_height_px <= 0) line_height_px = (float)font_height / 20.0f;

	float text_y = local_y_px - gutter_px;
	int target_line = 0;
	if (text_y > 0 && line_height_px > 0)
		target_line = (int)(text_y / line_height_px);
	if (target_line < 0) target_line = 0;

	int current_line = 0;
	size_t line_start_byte = 0;
	int line_start_u16 = 0;
	int char_u16_idx = 0;

	for (size_t i = 0; i < text_len && current_line < target_line; ) {
		unsigned char c = (unsigned char)text[i];
		if (c == '\r' || c == '\n') {
			current_line++;
			i++;
			char_u16_idx++;
			if (current_line == target_line) {
				line_start_byte = i;
				line_start_u16 = char_u16_idx;
			}
			continue;
		}
		size_t old_i = i;
		ng_decode_utf8_char(text, text_len, &i);
		(void)old_i;
		char_u16_idx++;
	}

	if (current_line < target_line)
		return char_u16_idx;

	float text_x = local_x_px - gutter_px - left_margin_px;
	float cum_x_px = 0.0f;
	int idx_on_line = 0;

	for (size_t i = line_start_byte; i < text_len; ) {
		unsigned char c = (unsigned char)text[i];
		if (c == '\r' || c == '\n') break;

		size_t old_i = i;
		u16 cp = ng_decode_utf8_char(text, text_len, &i);

		s16 adv = ng_font_glyph_advance(fi, cp);
		float glyph_px = 0;
		if (adv >= 0) {
			int raw_twips = (int)((float)adv * (float)font_height / (float)em);
			if (ng_device_font_mode)
				raw_twips = ng_round_to_pixel(raw_twips);
			glyph_px = (float)raw_twips / 20.0f;
		}

		if (text_x < cum_x_px + glyph_px * 0.5f)
			return line_start_u16 + idx_on_line;

		cum_x_px += glyph_px;
		idx_on_line++;
	}

	int end_idx = line_start_u16 + idx_on_line;
	size_t end_byte = line_start_byte;
	for (int ci = 0; ci < idx_on_line && end_byte < text_len; ci++)
		ng_decode_utf8_char(text, text_len, &end_byte);
	if (end_byte < text_len) {
		unsigned char c = (unsigned char)text[end_byte];
		if ((c == '\r' || c == '\n') && end_byte + 1 >= text_len)
			end_idx++;
	}
	return end_idx;
}
