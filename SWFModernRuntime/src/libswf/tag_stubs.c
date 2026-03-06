#ifdef NO_GRAPHICS

#include <tag.h>
#include <swf.h>
#include <common.h>
#include <action.h>
#include <object.h>
#include <heap.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

// ---------------------------------------------------------------------------
// Global display state — defined here in NO_GRAPHICS (swf.c provides in GRAPHICS)
// ---------------------------------------------------------------------------
Character* dictionary = NULL;
DisplayObject* display_list = NULL;
size_t max_depth = 0;

// Sentinel DisplayObject for root level — allows child lookup on root_movieclip
// even when display_list/max_depth are temporarily swapped during nested init.
// sprite_display_list and sprite_max_depth are synced by ng_sync_root_display_obj().
static DisplayObject ng_root_display_obj;


// ---------------------------------------------------------------------------
// Access generated data arrays (from draws.c / tagMain.c, linked per-test)
// ---------------------------------------------------------------------------
extern float transform_data[][16];
extern float cxform_data[];
extern int catch_up_mode;
extern size_t display_list_capacity;

// ---------------------------------------------------------------------------
// Supplemental registries (keyed by char_id, supplement dictionary[])
// ---------------------------------------------------------------------------

// Character bounds (shapes/morph shapes without renderer)
#define MAX_CHAR_BOUNDS_NG 256
static struct {
	size_t char_id;
	s32 xmin, xmax, ymin, ymax;  // twips
} ng_char_bounds[MAX_CHAR_BOUNDS_NG];
static size_t ng_char_bounds_count = 0;

// Morph shape end bounds (for ratio-based interpolation)
#define MAX_MORPH_END_BOUNDS_NG 64
static struct {
	size_t char_id;
	s32 xmin, xmax, ymin, ymax;  // twips (end shape bounds)
} ng_morph_end_bounds[MAX_MORPH_END_BOUNDS_NG];
static size_t ng_morph_end_bounds_count = 0;

// Non-zero winding rule char_ids (DefineShape4 UsesFillWindingRule)
#define MAX_WINDING_NG 64
static size_t ng_winding_ids[MAX_WINDING_NG];
static size_t ng_winding_count = 0;

// Button char_id registry (for typeof discrimination)
#define MAX_BUTTONS_NG 64
static size_t ng_button_ids[MAX_BUTTONS_NG];
static size_t ng_button_count = 0;

static int ng_find_button(size_t char_id)
{
	for (size_t i = 0; i < ng_button_count; i++)
		if (ng_button_ids[i] == char_id) return 1;
	return 0;
}

// Video stream char_id registry (scriptable like sprites)
#define MAX_VIDEOS_NG 32
static size_t ng_video_ids[MAX_VIDEOS_NG];
static size_t ng_video_count = 0;

static int ng_find_video(size_t char_id)
{
	for (size_t i = 0; i < ng_video_count; i++)
		if (ng_video_ids[i] == char_id) return 1;
	return 0;
}

// Font info registry (font name, bold, italic, metrics)
#define MAX_FONTS_NG 32
#define MAX_FONT_GLYPHS 512
static struct {
	u16 font_id;
	char name[128];
	int bold;
	int italic;
	// Font metrics (from DefineFont2/3 layout section)
	int has_metrics;
	s16 ascent;    // in EM units
	s16 descent;   // in EM units
	s16 leading;   // in EM units
	int em_square; // EM square size (typically 1024 for DefineFont2, 20480 for DefineFont3)
	u16 code_table[MAX_FONT_GLYPHS];   // glyph index → Unicode code point
	s16 advance_table[MAX_FONT_GLYPHS]; // glyph index → advance width (EM units)
	size_t glyph_count;
} ng_fonts[MAX_FONTS_NG];
static size_t ng_font_count = 0;

// Built-in Noto Sans fallback font for createTextField (no embedded font).
// Ruffle uses Noto Sans as its device font; these metrics are from the actual
// Noto Sans Regular TTF (notosans.subset.ttf from Ruffle core/assets).
// Covers ASCII 32-126 (95 glyphs), ascent=1069, descent=293, leading=0, em=1000.
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
// Index reserved for built-in font (never a real SWF font_id)
#define BUILTIN_FONT_IDX (-2)

// Look up glyph advance in the built-in Noto Sans fallback font.
static s16 builtin_font_glyph_advance(u16 code_point)
{
	if (code_point >= 32 && code_point <= 126)
		return builtin_noto_sans_advances[code_point - 32];
	return -1;
}

// TextField property registry (properties of DefineEditText characters)
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
	// CSMTextSettings
	char csm_antiAliasType[16];
	char csm_gridFitType[16];
	float csm_thickness;
	float csm_sharpness;
	int csm_applied;
} ng_textfields[MAX_TEXTFIELDS_NG];
static size_t ng_textfield_count = 0;

static int ng_find_textfield(size_t char_id)
{
	for (size_t i = 0; i < ng_textfield_count; i++)
		if (ng_textfields[i].char_id == char_id) return (int)i;
	return -1;
}

// Auto-naming counter ("instance1", "instance2", ...)
static unsigned int ng_auto_instance_counter = 1;

// If auto_name was the last auto-assigned name (e.g. "instance2" when counter==3),
// decrement the counter so the next auto-name reuses that slot.
void ng_try_reclaim_auto_instance_name(const char* auto_name)
{
	if (auto_name == NULL) return;
	unsigned int n = 0;
	if (sscanf(auto_name, "instance%u", &n) == 1 && n == ng_auto_instance_counter - 1)
		ng_auto_instance_counter--;
}

// ---------------------------------------------------------------------------
// Exported symbols registry (DoExportAssets → attachMovie linkage)
// ---------------------------------------------------------------------------
#define MAX_EXPORTED_SYMBOLS 128
static struct {
	char name[128];
	size_t char_id;
} ng_exported_symbols[MAX_EXPORTED_SYMBOLS];
static size_t ng_exported_symbol_count = 0;

size_t ng_lookupExport(const char* name)
{
	// Last registration wins (Flash behavior for duplicate export names)
	// Case-insensitive matching (Flash AVM1 behavior)
	size_t result = (size_t)-1;
	for (size_t i = 0; i < ng_exported_symbol_count; i++)
		if (strcasecmp(ng_exported_symbols[i].name, name) == 0)
			result = ng_exported_symbols[i].char_id;
	return result;
}

const char* ng_lookupExportName(size_t char_id)
{
	for (size_t i = 0; i < ng_exported_symbol_count; i++)
		if (ng_exported_symbols[i].char_id == char_id)
			return ng_exported_symbols[i].name;
	return NULL;
}

// ---------------------------------------------------------------------------
// Sound metadata registry (DefineSound → attachSound/getDuration linkage)
// ---------------------------------------------------------------------------
#define MAX_SOUND_METADATA 128
static struct {
	u16 char_id;
	u8 rate;       // 0=5.5kHz, 1=11kHz, 2=22kHz, 3=44kHz
	u32 sample_count;
} g_sound_metadata[MAX_SOUND_METADATA];
static size_t g_sound_metadata_count = 0;

// Look up duration in ms for a sound char_id. Returns -1 if not found.
int32_t ng_getSoundDuration(u16 char_id)
{
	for (size_t i = 0; i < g_sound_metadata_count; i++) {
		if (g_sound_metadata[i].char_id == char_id) {
			// Duration = sample_count * 1000 / sample_rate (truncated)
			static const u32 rates[] = { 5512, 11025, 22050, 44100 };
			u32 sr = rates[g_sound_metadata[i].rate & 3];
			double dur = (double)g_sound_metadata[i].sample_count * 1000.0 / (double)sr;
			return (int32_t)(dur + 0.5);
		}
	}
	return -1;
}

// ---------------------------------------------------------------------------
// Clone depth table — tracks which variable name occupies each SWF depth for
// script-created clones (CloneSprite / duplicateMovieClip). When a new clone
// takes an occupied SWF depth, the old variable is set to undefined so that
// GetVariable(old_name) returns undefined after the replacement.
// ---------------------------------------------------------------------------
#define MAX_CLONE_DEPTH_ENTRIES 128
typedef struct { int swf_depth; char name[64]; } CloneDepthEntry;
static CloneDepthEntry g_clone_depth_table[MAX_CLONE_DEPTH_ENTRIES];
static size_t g_clone_depth_count = 0;

// Evict any clone registered at swf_depth: clear its global variable to undefined.
static void clone_depth_evict(int swf_depth)
{
	for (size_t i = 0; i < g_clone_depth_count; i++)
	{
		if (g_clone_depth_table[i].swf_depth == swf_depth)
		{
			// Mark old MC as removed (depth = INT_MIN) and clear from child_mc_cache
			const char* old_name = g_clone_depth_table[i].name;
			size_t name_len = strlen(old_name);
			{
				extern MovieClip* child_mc_cache[];
				extern int child_mc_count;
				for (int ci = 0; ci < child_mc_count; ci++) {
					if (child_mc_cache[ci] != NULL &&
					    strcmp(child_mc_cache[ci]->name, old_name) == 0) {
						child_mc_cache[ci]->depth = INT_MIN;
						child_mc_cache[ci] = NULL;
						break;
					}
				}
			}
			// Set global variable to undefined so GetVariable returns undefined
			ActionVar* old_var = getVariable((char*)old_name, name_len);
			if (old_var != NULL)
			{
				if (old_var->type == ACTION_STACK_VALUE_STRING &&
				    old_var->data.string_data.owns_memory &&
				    old_var->data.string_data.heap_ptr != NULL)
				{
					free(old_var->data.string_data.heap_ptr);
					old_var->data.string_data.heap_ptr = NULL;
					old_var->data.string_data.owns_memory = false;
				}
				old_var->type = ACTION_STACK_VALUE_UNDEFINED;
				old_var->data.numeric_value = 0;
			}
			// Remove entry by swapping with last
			g_clone_depth_table[i] = g_clone_depth_table[--g_clone_depth_count];
			return;
		}
	}
}

// Register a clone variable name at a SWF depth (evicts old entry first).
static void clone_depth_register(int swf_depth, const char* name)
{
	clone_depth_evict(swf_depth);
	if (g_clone_depth_count < MAX_CLONE_DEPTH_ENTRIES)
	{
		g_clone_depth_table[g_clone_depth_count].swf_depth = swf_depth;
		strncpy(g_clone_depth_table[g_clone_depth_count].name, name, 63);
		g_clone_depth_table[g_clone_depth_count].name[63] = '\0';
		g_clone_depth_count++;
	}
}

// ---------------------------------------------------------------------------
// entry_idx encoding for ng_* query functions
// ---------------------------------------------------------------------------
// Root-level: entry_idx = depth (1..max_depth), upper bits == 0
// Level-1 nested: entry_idx = (parent_root_depth << 20) | child_depth
// Level-2+ nested: not supported (returns (size_t)-1)

static DisplayObject* ng_entry_to_obj(size_t entry_idx)
{
	if (entry_idx == (size_t)-1) return NULL;
	size_t parent_depth = entry_idx >> 20;
	size_t child_depth  = entry_idx & 0xFFFFF;
	if (parent_depth == 0) {
		// Root level
		if (child_depth < 1 || child_depth > max_depth) return NULL;
		if (display_list[child_depth].char_id == 0) return NULL;
		return &display_list[child_depth];
	} else {
		// Level-1 nested: parent is at display_list[parent_depth]
		if (parent_depth > max_depth) return NULL;
		DisplayObject* parent = &display_list[parent_depth];
		if (parent->sprite_display_list == NULL) return NULL;
		if (child_depth < 1 || child_depth > parent->sprite_max_depth) return NULL;
		if (parent->sprite_display_list[child_depth].char_id == 0) return NULL;
		return &parent->sprite_display_list[child_depth];
	}
}

// Sync root display object — call after any operation that may have changed
// the root display_list pointer (ENSURE_SIZE / realloc).
void ng_sync_root_display_obj(void)
{
	ng_root_display_obj.sprite_display_list = display_list;
	ng_root_display_obj.sprite_max_depth    = max_depth;
}

// Return pointer to root display sentinel object (for root_movieclip.display_obj)
void* ng_get_root_display_obj(void)
{
	return &ng_root_display_obj;
}

// ---------------------------------------------------------------------------
// Record callbacks (called from tag.c for each define-tag in NO_GRAPHICS mode)
// ---------------------------------------------------------------------------

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

void ng_record_char_winding(size_t char_id)
{
	if (ng_winding_count < MAX_WINDING_NG)
		ng_winding_ids[ng_winding_count++] = char_id;
}

static int ng_uses_nonzero_winding(size_t char_id)
{
	for (size_t i = 0; i < ng_winding_count; i++)
		if (ng_winding_ids[i] == char_id) return 1;
	return 0;
}

void ng_record_button(size_t char_id)
{
	if (ng_button_count < MAX_BUTTONS_NG && !ng_find_button(char_id))
		ng_button_ids[ng_button_count++] = char_id;
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
	// Find existing font entry
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

// Ensure the built-in Noto Sans fallback is registered.
// Called lazily when font_id=0 is requested and no font with id 0 exists.
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

// Find the font entry index for a given font_id. Returns -1 if not found.
// When font_id=0 is requested and no explicit font 0 exists, lazily registers
// the built-in Noto Sans fallback (used by createTextField with no embedded font).
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

// Find a font with metrics. If the given font_id has no metrics, fall back to
// the built-in Noto Sans font (device font substitute). Returns -1 if none found.
static int ng_find_font_with_metrics(u16 font_id)
{
	int fi = ng_find_font(font_id);
	if (fi >= 0 && ng_fonts[fi].has_metrics) return fi;
	// Font exists but has no metrics — fall back to built-in Noto Sans
	ng_ensure_builtin_font();
	for (size_t i = 0; i < ng_font_count; i++)
		if (ng_fonts[i].font_id == 0 && ng_fonts[i].has_metrics) return (int)i;
	return -1;
}

// Look up glyph advance for a Unicode code point in a font.
// Returns the advance in EM units, or -1 if not found.
static s16 ng_font_glyph_advance(int font_idx, u16 code_point)
{
	for (size_t j = 0; j < ng_fonts[font_idx].glyph_count; j++) {
		if (ng_fonts[font_idx].code_table[j] == code_point)
			return ng_fonts[font_idx].advance_table[j];
	}
	return -1;
}

// Decode one UTF-8 character from text[*pos], advance *pos past it.
// Returns the Unicode code point (or the raw byte for invalid sequences).
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

// Round a twips value to the nearest pixel (20-twip boundary).
static int ng_round_to_pixel(int twips) {
	// round(twips / 20.0) * 20
	double px = (double)twips / 20.0;
	int rounded_px = (px >= 0) ? (int)(px + 0.5) : -(int)(-px + 0.5);
	return rounded_px * 20;
}

// Round letter spacing twips to pixel using banker's rounding (ties to even).
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

// Measure width of a UTF-8 substring in twips using font glyph advances.
// When letter spacing is non-zero, per-glyph advance is rounded to pixel
// boundaries and letter spacing is rounded/clamped per glyph.
static int ng_measure_substr_twips(int font_idx, int em, u16 font_height,
    const char* text, size_t start, size_t end, int letter_spacing_twips)
{
	int w = 0;
	size_t i = start;
	while (i < end) {
		u16 cp = ng_decode_utf8_char(text, end, &i);
		s16 adv = ng_font_glyph_advance(font_idx, cp);
		int glyph_twips = 0;
		if (adv >= 0) {
			int raw = (int)((float)adv * (float)font_height / (float)em);
			glyph_twips = raw + letter_spacing_twips;
			if (glyph_twips <= 0 && letter_spacing_twips < 0)
				glyph_twips = raw; // negative LS clamped per-glyph
		} else if (letter_spacing_twips > 0) {
			glyph_twips = letter_spacing_twips;
		}
		w += glyph_twips;
	}
	return w;
}

// Word-wrap a single hard line (no \n or \r) and return the number of visual lines
// and the max line width in twips.
// Algorithm matches Ruffle's line_wrapping.rs:
// - SWF>=8: break after space runs (space→non-space), after hyphens
// - SWF<=7: break after every space, around hyphens
// - If segment doesn't fit and not start-of-line: wrap to new line
// - If at start-of-line: force-break (min 1 char for SWF8)
// max_width_out: max trimmed line width (trailing spaces excluded for SWF8)
// max_width_full_out: max full line width including trailing spaces (NULL to skip)
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
	// First line has indent offset; available width reduced by margins
	int base_avail = field_width_twips - left_margin_twips - right_margin_twips;
	if (base_avail < 0) base_avail = 0;
	int first_line_offset = indent_twips > 0 ? indent_twips : 0;
	int cur_avail = base_avail - first_line_offset;  // available width for current line
	if (cur_avail < 0) cur_avail = 0;
	int cur_line_w = 0;       // current line cursor position in twips (including trailing spaces)
	int trimmed_line_w = 0;   // current line width excluding trailing spaces (SWF8)
	int max_line_w = 0;       // max trimmed line width across all lines
	int max_line_w_full = 0;  // max full line width (with trailing spaces)
	int is_swf8 = (swf_version >= 8);

	// Walk through text finding segments between break points.
	// A "segment" is the text from the last break point (or start) to the next break point.
	size_t seg_start = 0;  // byte offset of current segment start

	while (seg_start < text_len) {
		// Find next break point starting from seg_start
		size_t seg_end = text_len;  // default: rest of line
		size_t i = seg_start;

		if (is_swf8) {
			// SWF8: break after space runs (space→non-space transition) and after hyphens
			int in_spaces = 0;
			while (i < text_len) {
				unsigned char c = (unsigned char)text[i];
				if (c == ' ') {
					in_spaces = 1;
					i++;
				} else if (in_spaces) {
					// Transition from space to non-space: break here (after the spaces)
					seg_end = i;
					break;
				} else if (c == '-') {
					// Break after hyphen
					// Advance past the hyphen (possibly multi-byte, but '-' is ASCII)
					i++;
					seg_end = i;
					break;
				} else {
					// Advance past this character (may be multi-byte UTF-8)
					if (c >= 0xC0 && c < 0xE0) i += 2;
					else if (c >= 0xE0 && c < 0xF0) i += 3;
					else if (c >= 0xF0) i += 4;
					else i++;
					in_spaces = 0;
				}
			}
		} else {
			// SWF<=7: break after every space, before and after hyphens
			while (i < text_len) {
				unsigned char c = (unsigned char)text[i];
				if (c == ' ') {
					i++;
					seg_end = i;
					break;
				} else if (c == '-') {
					if (i == seg_start) {
						// At segment start: include the hyphen, break after it
						i++;
						seg_end = i;
					} else {
						// Break before hyphen
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

		// Measure the segment
		int seg_w = ng_measure_substr_twips(font_idx, em, font_height, text, seg_start, seg_end, letter_spacing_twips);

		// For SWF8: compute trimmed width (trailing spaces don't count for measurement)
		int seg_trimmed_w = seg_w;
		if (is_swf8) {
			// Trim trailing spaces from segment for measurement
			size_t trimmed_end = seg_end;
			while (trimmed_end > seg_start && (unsigned char)text[trimmed_end - 1] == ' ')
				trimmed_end--;
			if (trimmed_end < seg_end)
				seg_trimmed_w = ng_measure_substr_twips(font_idx, em, font_height, text, seg_start, trimmed_end, letter_spacing_twips);
		}

		// Check if segment fits on current line
		int test_w = cur_line_w + (is_swf8 ? seg_trimmed_w : seg_w);
		if (test_w <= cur_avail) {
			// Fits: advance cursor by full segment width (including trailing spaces)
			cur_line_w += seg_w;
			if (is_swf8) {
				// Trimmed width: cursor excluding trailing spaces
				trimmed_line_w = cur_line_w - (seg_w - seg_trimmed_w);
			} else {
				trimmed_line_w = cur_line_w;
			}
			if (trimmed_line_w > max_line_w) max_line_w = trimmed_line_w;
			if (cur_line_w > max_line_w_full) max_line_w_full = cur_line_w;
			seg_start = seg_end;
		} else if (cur_line_w == 0) {
			// Doesn't fit and we're at start of line: force-break within segment
			size_t char_pos = seg_start;
			int char_w = 0;
			int last_fitting_pos = seg_start;
			int last_fitting_w = 0;
			while (char_pos < seg_end) {
				size_t next_pos = char_pos;
				u16 cp = ng_decode_utf8_char(text, seg_end, &next_pos);
				s16 adv = ng_font_glyph_advance(font_idx, cp);
				int gw = 0;
				if (adv >= 0) {
					int raw = (int)((float)adv * (float)font_height / (float)em);
					gw = raw + letter_spacing_twips;
					if (gw <= 0 && letter_spacing_twips < 0) gw = raw;
				} else if (letter_spacing_twips > 0) {
					gw = letter_spacing_twips;
				}
				if (char_w + gw > cur_avail && last_fitting_pos > seg_start)
					break;
				char_w += gw;
				last_fitting_pos = next_pos;
				last_fitting_w = char_w;
				if (is_swf8 && last_fitting_pos > seg_start && char_w > cur_avail)
					break;
			}
			if (last_fitting_pos == seg_start) {
				size_t tmp = seg_start;
				ng_decode_utf8_char(text, seg_end, &tmp);
				last_fitting_pos = tmp;
				last_fitting_w = ng_measure_substr_twips(font_idx, em, font_height, text, seg_start, last_fitting_pos, letter_spacing_twips);
			}
			if (last_fitting_w > max_line_w) max_line_w = last_fitting_w;
			// Start new line with remainder (subsequent lines don't have indent)
			line_count++;
			cur_line_w = 0;
			trimmed_line_w = 0;
			cur_avail = base_avail;
			seg_start = last_fitting_pos;
		} else {
			// Doesn't fit but we have content on line: wrap to new line, retry this segment
			// Record trimmed width for the line being ended
			if (trimmed_line_w > max_line_w) max_line_w = trimmed_line_w;
			if (cur_line_w > max_line_w_full) max_line_w_full = cur_line_w;
			line_count++;
			cur_line_w = 0;
			trimmed_line_w = 0;
			cur_avail = base_avail;  // subsequent lines don't have indent
			// Don't advance seg_start — retry this segment on new line
		}
	}

	// Final line's trimmed width (already tracked via trimmed_line_w in the fits path)
	if (trimmed_line_w > max_line_w) max_line_w = trimmed_line_w;
	if (cur_line_w > max_line_w_full) max_line_w_full = cur_line_w;

	*max_width_out = max_line_w;
	if (max_width_full_out) *max_width_full_out = max_line_w_full;
	return line_count;
}

// Compute textWidth for a string using font metrics.
// Returns width in twips.
// font_height is in twips.
// align: 0=left, 1=center, 2=right. For SWF8+ left-aligned text, includes trailing
// space width (matching Ruffle's fixup_line behavior where only non-left alignment trims).
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
		// No wrap: measure each hard line, return max width
		// SWF8+: non-left alignment trims trailing spaces from textWidth
		int trim_trailing = (swf_version >= 8 && align != 0);
		int max_width_twips = 0;
		int cur_width_twips = 0;
		int cur_trimmed_twips = 0; // width excluding trailing spaces
		for (size_t i = 0; i < text_len; ) {
			unsigned char c = (unsigned char)text[i];
			if (c == '\r' || c == '\n') {
				if (trim_trailing && cur_trimmed_twips < cur_width_twips)
					cur_width_twips = cur_trimmed_twips;
				if (cur_width_twips > max_width_twips) max_width_twips = cur_width_twips;
				cur_width_twips = 0;
				cur_trimmed_twips = 0;
				if (c == '\r' && i + 1 < text_len && text[i + 1] == '\n') i += 2; else i++;
				continue;
			}
			u16 code_point = ng_decode_utf8_char(text, text_len, &i);
			s16 adv = ng_font_glyph_advance(fi, code_point);
			int glyph_twips = 0;
			if (adv >= 0) {
				int raw = (int)((float)adv * (float)font_height / (float)em);
				glyph_twips = raw + letter_spacing_twips;
				if (glyph_twips <= 0 && letter_spacing_twips < 0)
					glyph_twips = raw; // negative LS clamped per-glyph
			} else if (letter_spacing_twips > 0) {
				glyph_twips = letter_spacing_twips;
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

	// Word-wrap mode: split into hard lines, wrap each, track max width
	// For SWF8+ left-aligned text, use full width (including trailing spaces)
	// For non-left alignment, use trimmed width (Ruffle trims in fixup_line)
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
			if (is_newline) {
				if (text[i] == '\r' && i + 1 < text_len && text[i + 1] == '\n') i++;
			}
			line_start = i + 1;
		}
	}
	return max_width_twips;
}

// Compute textHeight for a string using font metrics.
// Returns height in twips (callers divide by 20 for pixels).
// font_height is in twips, leading_twips is the DefineEditText leading value in twips.
int ng_computeTextHeight(u16 font_id, u16 font_height, s16 leading_twips, const char* text, size_t text_len,
    int word_wrap, int field_width_twips, int swf_version,
    int left_margin_twips, int right_margin_twips, int indent_twips,
    int letter_spacing_twips)
{
	int fi = ng_find_font_with_metrics(font_id);
	if (fi < 0) return 0;

	int em = ng_fonts[fi].em_square;
	if (em <= 0) em = 1024;

	// Compute ascent and descent in twips (using Ruffle's integer truncation: (f32 * scale) as i32)
	// scale = font_height_twips / em_square
	int ascent_twips = (int)((float)ng_fonts[fi].ascent * (float)font_height / (float)em);
	int descent_twips = (int)((float)ng_fonts[fi].descent * (float)font_height / (float)em);

	// Empty text = 0 height (Ruffle skips empty last line for non-input fields)
	if (text == NULL || text_len == 0) return 0;

	// Count lines
	int line_count = 1;
	{
		if (!word_wrap || field_width_twips <= 0) {
			// No wrap: count hard lines only
			for (size_t i = 0; i < text_len; i++) {
				if (text[i] == '\r') {
					line_count++;
					if (i + 1 < text_len && text[i + 1] == '\n') i++;
				} else if (text[i] == '\n') {
					line_count++;
				}
			}
		} else {
			// Word-wrap: split into hard lines, wrap each, sum visual line counts
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
					if (is_newline) {
						if (text[i] == '\r' && i + 1 < text_len && text[i + 1] == '\n') i++;
					}
					line_start = i + 1;
				}
			}
			if (line_count == 0) line_count = 1;
		}
	}

	// Ruffle model: first line always gets leading, subsequent lines add leading
	// between them. The last line does NOT add trailing leading.
	// Formula: line_count * (ascent + descent) + max(line_count - 1, 1) * leading
	// This means: single line still includes leading (first-line rule),
	// multi-line adds leading between lines but not after the last.
	int leading_count = line_count > 1 ? line_count - 1 : 1;
	int total_twips = line_count * (ascent_twips + descent_twips) + leading_count * (int)leading_twips;

	return total_twips;
}

// Compute total line count for text (same line counting logic as ng_computeTextHeight).
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
				if (text[i] == '\r') {
					line_count++;
					if (i + 1 < text_len && text[i + 1] == '\n') i++;
				} else if (text[i] == '\n') {
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
					if (is_newline) {
						if (text[i] == '\r' && i + 1 < text_len && text[i + 1] == '\n') i++;
					}
					line_start = i + 1;
				}
			}
			if (line_count == 0) line_count = 1;
		}
	}
	return line_count;
}

// Compute how many lines fit in the visible area of a text field.
// field_height_pixels is mc->height. Returns at least 1.
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

	// Available height in twips minus 2*GUTTER (40 twips each side = 80 twips total)
	int avail_twips = (int)(field_height_pixels * 20.0f) - 80;
	if (avail_twips <= 0) return 1;

	// First line takes ascent+descent, each subsequent line adds line_height
	// visible = 1 + floor((avail - first_line) / line_height)
	int first_line_twips = ascent_twips + descent_twips;
	if (avail_twips < first_line_twips) return 1;

	int remaining = avail_twips - first_line_twips;
	int extra_lines = remaining / line_height_twips;
	return 1 + extra_lines;
}

// Compute TextFormat.getTextExtent() metrics.
// font_id: font to use (0 = builtin Noto Sans). font_size_px: font size in pixels.
// text/text_len: the string to measure. width_px: optional wrap width (-1 = no wrap).
// All output values in pixels (f64).
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

	u16 font_height = (u16)(font_size_px * 20.0); // twips
	int ascent_twips = (int)((float)ng_fonts[fi].ascent * (float)font_height / (float)em);
	int descent_twips = (int)((float)ng_fonts[fi].descent * (float)font_height / (float)em);

	*out_ascent = (double)ascent_twips / 20.0;
	*out_descent = (double)descent_twips / 20.0;

	int has_wrap = (width_px > 0);
	int field_width_twips = has_wrap ? (int)(width_px * 20.0) : 0;
	// Subtract gutter (2px each side = 80 twips total) from field width for content area
	int content_width_twips = has_wrap ? (field_width_twips - 80) : 0;

	// Compute text width (max line width in twips)
	int width_twips = ng_computeTextWidth(font_id, font_height, text, text_len,
	    has_wrap, content_width_twips, 8, 0, 0, 0, 0, 0);

	*out_width = (double)width_twips / 20.0;

	// Compute height: line_count * (ascent + descent + leading)
	// For getTextExtent, leading = 0 (TextFormat default)
	int line_height_twips = ascent_twips + descent_twips;
	int line_count = 1;
	if (text != NULL && text_len > 0) {
		line_count = ng_computeTextLineCount(font_id, font_height, text, text_len,
		    has_wrap, content_width_twips, 8, 0, 0, 0, 0);
	}
	int height_twips = line_count * line_height_twips;
	*out_height = (double)height_twips / 20.0;

	// textFieldHeight = height + 4 (2px gutter on each side)
	*out_tf_height = *out_height + 4.0;

	// textFieldWidth = specified width, or text width + 4
	if (has_wrap) {
		*out_tf_width = width_px;
	} else {
		*out_tf_width = *out_width + 4.0;
	}
}

void ng_record_video(SWFAppContext* app_context, u16 char_id)
{
	(void)app_context;
	if (ng_video_count < MAX_VIDEOS_NG)
		ng_video_ids[ng_video_count++] = (size_t)char_id;
}

// ---------------------------------------------------------------------------
// tagRegisterExport — called from generated tagInit() for DoExportAssets
// ---------------------------------------------------------------------------
void tagRegisterExport(SWFAppContext* app_context, const char* name, size_t char_id)
{
	(void)app_context;
	if (ng_exported_symbol_count < MAX_EXPORTED_SYMBOLS) {
		strncpy(ng_exported_symbols[ng_exported_symbol_count].name, name, 127);
		ng_exported_symbols[ng_exported_symbol_count].name[127] = '\0';
		ng_exported_symbols[ng_exported_symbol_count].char_id = char_id;
		ng_exported_symbol_count++;
	}
}

// ---------------------------------------------------------------------------
// Pending attach init queue — deferred frame-0 script execution for attachMovie
// ---------------------------------------------------------------------------
extern MovieClip* actionFindOrCreateMovieClip(SWFAppContext* app_context, const char* name, MovieClip* parent);
extern void setVariableByName(const char* var_name, ActionVar* value);
extern void actionSetCurrentContext(MovieClip* mc);
extern MovieClip root_movieclip;
extern int g_settarget_explicit_root;
extern DisplayObject* g_current_sprite_obj;
extern MovieClip* g_current_context;

#define MAX_PENDING_ATTACH_INITS 64
typedef struct {
	char instance_name[256];
	char export_name[128];  // For registered class constructor invocation
	frame_func func;
	int swf_depth;
} PendingAttachInit;
static PendingAttachInit g_pending_attach_inits[MAX_PENDING_ATTACH_INITS];
static size_t g_pending_attach_init_count = 0;

void ng_fire_pending_attach_inits(SWFAppContext* app_context)
{
	for (size_t i = 0; i < g_pending_attach_init_count; i++) {
		// Set context and base clip to the attached clip for correct variable resolution
		MovieClip* saved_ctx = g_current_context;
		extern void actionSetBaseClip(MovieClip* mc);
		extern MovieClip* actionGetBaseClip(void);
		MovieClip* saved_base = actionGetBaseClip();
		MovieClip* mc = actionFindOrCreateMovieClip(
			app_context, g_pending_attach_inits[i].instance_name, &root_movieclip);
		if (mc) { actionSetCurrentContext(mc); actionSetBaseClip(mc); }

		// Save display list state and switch to the MC's sprite display list
		DisplayObject* saved_dl = display_list;
		size_t saved_max = max_depth;
		size_t saved_cap = display_list_capacity;
		DisplayObject* saved_sprite_obj = g_current_sprite_obj;
		int saved_settarget = g_settarget_explicit_root;

		// Use the MC's own sprite display list (created during ng_attachMovie)
		if (mc != NULL && mc->display_obj != NULL) {
			DisplayObject* dobj = (DisplayObject*)mc->display_obj;
			display_list = dobj->sprite_display_list;
			max_depth = dobj->sprite_max_depth;
			display_list_capacity = dobj->sprite_dl_capacity;
		} else {
			// Fallback: create a temp display list
			size_t tmp_cap = 64;
			display_list = calloc(tmp_cap, sizeof(DisplayObject));
			max_depth = 0;
			display_list_capacity = tmp_cap;
		}
		g_settarget_explicit_root = 0;
		g_current_sprite_obj = NULL;

		// Run the frame function (scripts will run this time since catch_up_mode = 0)
		g_pending_attach_inits[i].func(app_context);

		// Persist updated display list state back to the MC's display obj
		if (mc != NULL && mc->display_obj != NULL) {
			DisplayObject* dobj = (DisplayObject*)mc->display_obj;
			dobj->sprite_display_list = display_list;
			dobj->sprite_max_depth = max_depth;
			dobj->sprite_dl_capacity = display_list_capacity;
			// Mark eligible for AS2 onEnterFrame dispatch on the init tick
			// (mirrors process_sprite_init_at_depth which sets this for timeline sprites)
			dobj->enterframe_eligible = 1;
		} else {
			free(display_list);
		}

		// Restore
		actionSetCurrentContext(saved_ctx);
		actionSetBaseClip(saved_base);
		g_current_sprite_obj = saved_sprite_obj;
		g_settarget_explicit_root = saved_settarget;
		display_list = saved_dl;
		max_depth = saved_max;
		display_list_capacity = saved_cap;

		// NOTE: Registered class constructor is now fired synchronously during
		// attachMovie (in action.c), not deferred here. This ensures the constructor
		// runs before attachMovie returns to the caller script.
	}
	g_pending_attach_init_count = 0;
}

// ---------------------------------------------------------------------------
// ng_attachMovie — instantiate an exported library symbol at runtime
// ---------------------------------------------------------------------------

MovieClip* ng_attachMovie(SWFAppContext* app_context, size_t char_id, const char* new_name, int as_depth, MovieClip* parent)
{
	extern size_t display_list_capacity;

	if (char_id >= INITIAL_DICTIONARY_CAPACITY) return NULL;
	if (dictionary[char_id].type != CHAR_TYPE_SPRITE) return NULL;
	// Flash valid depth range: -16384 to 2130690044
	if (as_depth > 2130690044 || as_depth < -16384) return NULL;

	// Create MC for the attached clip (reset position/scale to defaults for re-attach)
	MovieClip* new_mc = actionFindOrCreateMovieClip(app_context, new_name, parent);
	if (new_mc == NULL) return NULL;

	// Remove any existing clone at this SWF depth BEFORE setting depth/props.
	// clone_depth_evict may set depth=INT_MIN on the old MC at this depth,
	// which could be the same struct if actionFindOrCreateMovieClip reused it.
	int swf_depth = as_depth + 16384;
	clone_depth_register(swf_depth, new_name);

	new_mc->depth = as_depth;
	new_mc->x = 0.0f;
	new_mc->y = 0.0f;
	new_mc->xscale = 100.0f;
	new_mc->yscale = 100.0f;
	new_mc->rotation = 0.0f;
	new_mc->alpha = 100.0f;
	new_mc->visible = 1;
	new_mc->width = 0.0f;
	new_mc->height = 0.0f;
	// Don't reset frame counters here — they stay at createMovieClip defaults (1,1,1).
	// attachMovie clips that run frame 0 get their counters set at the end of ng_attachMovie.
#ifdef NO_GRAPHICS
	new_mc->as_set_flags = 0;
#endif

	// Register as a variable so GetVariable finds it
	ActionVar mc_var = {0};
	mc_var.type = ACTION_STACK_VALUE_MOVIECLIP;
	mc_var.data.numeric_value = (u64)(uintptr_t)new_mc;
	setVariableByName(new_name, &mc_var);

	// Execute the sprite's frame 0 placement tags (scripts deferred to end of frame)
	frame_func* funcs = dictionary[char_id].sprite_frame_funcs;
	size_t frame_count = dictionary[char_id].sprite_frame_count;
	if (funcs != NULL && frame_count > 0 && funcs[0] != NULL) {
		// Context swap: save current display list and switch to a temporary one
		// for the sprite's children
		DisplayObject* saved_dl    = display_list;
		size_t         saved_max   = max_depth;
		size_t         saved_cap   = display_list_capacity;
		MovieClip*     saved_ctx   = NULL;
		DisplayObject* saved_sprite_obj = g_current_sprite_obj;
		int            saved_settarget = g_settarget_explicit_root;
		int            saved_catch_up = catch_up_mode;

		// Create a display object for the attached clip to hold its children
		if (new_mc->display_obj == NULL) {
			DisplayObject* dobj = calloc(1, sizeof(DisplayObject));
			dobj->char_id = char_id;
			dobj->sprite_dl_capacity = 64;
			dobj->sprite_display_list = calloc(dobj->sprite_dl_capacity, sizeof(DisplayObject));
			dobj->sprite_max_depth = 0;
			new_mc->display_obj = dobj;
		} else {
			// Re-attach: clear existing children
			DisplayObject* dobj = (DisplayObject*)new_mc->display_obj;
			if (dobj->sprite_display_list) {
				memset(dobj->sprite_display_list, 0, dobj->sprite_dl_capacity * sizeof(DisplayObject));
				dobj->sprite_max_depth = 0;
			}
		}

		// Use the MC's own sprite display list for placement tags
		DisplayObject* dobj = (DisplayObject*)new_mc->display_obj;
		display_list = dobj->sprite_display_list;
		max_depth = dobj->sprite_max_depth;
		display_list_capacity = dobj->sprite_dl_capacity;
		g_settarget_explicit_root = 0;

		// Set the MC context so _name, _x etc resolve correctly
		saved_ctx = g_current_context;
		actionSetCurrentContext(new_mc);
		g_current_sprite_obj = NULL;

		// Run frame 0 with catch_up_mode=1 to skip scripts (only placement tags run)
		catch_up_mode = 1;
		funcs[0](app_context);
		catch_up_mode = saved_catch_up;

		// Restore context
		actionSetCurrentContext(saved_ctx);
		g_current_sprite_obj = saved_sprite_obj;
		g_settarget_explicit_root = saved_settarget;

		// Persist the updated display list state on the MC's display obj
		dobj->sprite_display_list = display_list;
		dobj->sprite_max_depth = max_depth;
		dobj->sprite_dl_capacity = display_list_capacity;

		// Compute content bounds from children placed during frame 0
		{
			float bxmin = 1e30f, bxmax = -1e30f, bymin = 1e30f, bymax = -1e30f;
			int has_bounds = 0;
			for (size_t d = 0; d <= dobj->sprite_max_depth && d < dobj->sprite_dl_capacity; d++) {
				if (dobj->sprite_display_list[d].char_id == 0) continue;
				s32 cxmin, cxmax, cymin, cymax;
				if (ng_getCharBounds(dobj->sprite_display_list[d].char_id, &cxmin, &cxmax, &cymin, &cymax)) {
					float pxmin = (float)cxmin / 20.0f;
					float pxmax = (float)cxmax / 20.0f;
					float pymin = (float)cymin / 20.0f;
					float pymax = (float)cymax / 20.0f;
					if (pxmin < bxmin) bxmin = pxmin;
					if (pxmax > bxmax) bxmax = pxmax;
					if (pymin < bymin) bymin = pymin;
					if (pymax > bymax) bymax = pymax;
					has_bounds = 1;
				}
			}
			if (has_bounds) {
				new_mc->width = bxmax - bxmin;
				new_mc->height = bymax - bymin;
			}
		}

		// Restore the parent display list
		display_list = saved_dl;
		max_depth = saved_max;
		display_list_capacity = saved_cap;

		// Queue the frame function for deferred script execution
		// (Flash runs attached clip init scripts at end of frame)
		// If an init is already pending for the same SWF depth, replace it
		// (re-attaching at the same depth supersedes the previous init)
		{
			const char* exp_name = ng_lookupExportName(char_id);
			int found = 0;
			for (size_t qi = 0; qi < g_pending_attach_init_count; qi++) {
				if (g_pending_attach_inits[qi].swf_depth == swf_depth) {
					strncpy(g_pending_attach_inits[qi].instance_name,
						new_name, sizeof(g_pending_attach_inits[0].instance_name) - 1);
					g_pending_attach_inits[qi].instance_name[
						sizeof(g_pending_attach_inits[0].instance_name) - 1] = '\0';
					g_pending_attach_inits[qi].func = funcs[0];
					if (exp_name) { strncpy(g_pending_attach_inits[qi].export_name, exp_name, 127); g_pending_attach_inits[qi].export_name[127] = '\0'; }
					else g_pending_attach_inits[qi].export_name[0] = '\0';
					found = 1;
					break;
				}
			}
			if (!found && g_pending_attach_init_count < MAX_PENDING_ATTACH_INITS) {
				strncpy(g_pending_attach_inits[g_pending_attach_init_count].instance_name,
					new_name, sizeof(g_pending_attach_inits[0].instance_name) - 1);
				g_pending_attach_inits[g_pending_attach_init_count].instance_name[
					sizeof(g_pending_attach_inits[0].instance_name) - 1] = '\0';
				g_pending_attach_inits[g_pending_attach_init_count].func = funcs[0];
				g_pending_attach_inits[g_pending_attach_init_count].swf_depth = swf_depth;
				if (exp_name) { strncpy(g_pending_attach_inits[g_pending_attach_init_count].export_name, exp_name, 127); g_pending_attach_inits[g_pending_attach_init_count].export_name[127] = '\0'; }
				else g_pending_attach_inits[g_pending_attach_init_count].export_name[0] = '\0';
				g_pending_attach_init_count++;
			}
		}
	}

	new_mc->totalframes = (int)frame_count;
	new_mc->framesloaded = (int)frame_count;
	new_mc->currentframe = 1;

	return new_mc;
}

// ---------------------------------------------------------------------------
// Pending onLoad queue for duplicated clips (fired at end of tagShowFrame)
// Duplicate clips live at SWF depths 16384+ — too large for display_list.
// Instead, enqueue their onLoad callbacks here and fire them in tagShowFrame.
// ---------------------------------------------------------------------------
#define MAX_PENDING_LOADS 64
typedef struct {
	char instance_name[64];
	ClipAction* clip_actions;
	size_t clip_action_count;
} PendingLoad;
static PendingLoad g_pending_loads[MAX_PENDING_LOADS];
static size_t g_pending_load_count = 0;

void ng_fire_pending_loads(SWFAppContext* app_context)
{
	for (size_t p = 0; p < g_pending_load_count; p++)
	{
		MovieClip* saved_ctx = g_current_context;
		MovieClip* mc = actionFindOrCreateMovieClip(
			app_context, g_pending_loads[p].instance_name, &root_movieclip);
		if (mc) actionSetCurrentContext(mc);
		for (size_t a = 0; a < g_pending_loads[p].clip_action_count; a++)
		{
			if (g_pending_loads[p].clip_actions[a].event_flags & CLIP_EVENT_LOAD)
				g_pending_loads[p].clip_actions[a].action(app_context);
		}
		actionSetCurrentContext(saved_ctx);
	}
	g_pending_load_count = 0;
}

// ---------------------------------------------------------------------------
// Helper: initialize cx_* from cxform_data (percentage format: 100.0 = normal)
// ---------------------------------------------------------------------------
static void ng_init_cxform_from_data(DisplayObject* obj, u32 cxform_id)
{
	float* cx = &cxform_data[cxform_id * 20];
	obj->cx_ra = (double)(int16_t)roundf(cx[0]  * 256.0f) * 100.0 / 256.0;
	obj->cx_ga = (double)(int16_t)roundf(cx[5]  * 256.0f) * 100.0 / 256.0;
	obj->cx_ba = (double)(int16_t)roundf(cx[10] * 256.0f) * 100.0 / 256.0;
	obj->cx_aa = (double)(int16_t)roundf(cx[15] * 256.0f) * 100.0 / 256.0;
	obj->cx_rb = (double)(int16_t)roundf(cx[16] * 255.0f);
	obj->cx_gb = (double)(int16_t)roundf(cx[17] * 255.0f);
	obj->cx_bb = (double)(int16_t)roundf(cx[18] * 255.0f);
	obj->cx_ab = (double)(int16_t)roundf(cx[19] * 255.0f);
}

// ---------------------------------------------------------------------------
// Placement/removal callbacks (called from tag.c after display_list update)
// ---------------------------------------------------------------------------

void ng_on_place_object2(SWFAppContext* app_context, size_t depth, size_t char_id)
{
	if (depth > max_depth || display_list[depth].char_id == 0) return;
	DisplayObject* obj = &display_list[depth];

	// Initialize cx_* from cxform_data if there's a cxform applied
	if (obj->has_cxform && obj->cxform_id != 0)
		ng_init_cxform_from_data(obj, obj->cxform_id);

	// Determine character type
	int is_sprite = (char_id < INITIAL_DICTIONARY_CAPACITY && dictionary[char_id].type == CHAR_TYPE_SPRITE);
	int is_button = ng_find_button(char_id);
	int tf_idx    = ng_find_textfield(char_id);
	int is_tf     = (tf_idx >= 0);
	int is_video  = ng_find_video(char_id);

	// Auto-assign instance name for scriptable characters if not already named
	// (mirrors Flash Player behavior: sprites/buttons/textfields get "instance1", "instance2", etc.)
	// Note: videos are scriptable but do NOT get auto-instance-names (Ruffle behavior).
	// If g_pending_instance_name is set (from tagSetInstanceName before tagPlaceObject2),
	// use it instead of auto-assigning, so CLIP_EVENT_CONSTRUCT fires with the correct name.
	{
		extern const char* g_pending_instance_name;
		if (g_pending_instance_name != NULL && (is_sprite || is_button || is_tf))
		{
			obj->instance_name = (char*)g_pending_instance_name;
			obj->instance_name_owned = 0;
			g_pending_instance_name = NULL;
		}
		else if ((is_sprite || is_button || is_tf) && obj->instance_name == NULL)
		{
			char auto_name[32];
			snprintf(auto_name, sizeof(auto_name), "instance%u", ng_auto_instance_counter++);
			obj->instance_name = strdup(auto_name);
			obj->instance_name_owned = 1;
		}
	}

	// Initialize textfield variable binding
	if (is_tf && tf_idx >= 0)
	{
		const char* var_name  = ng_textfields[tf_idx].variable_name;
		const char* init_text = ng_textfields[tf_idx].plain_text;
		if (var_name[0] != '\0')
			actionInitTextFieldVariable(app_context, var_name, init_text);
	}

	// Allocate sprite display list and mark for frame-0 execution at tagShowFrame.
	// tagShowFrame's sprite_needs_init block runs frame 0 WITH scripts in the same
	// tick as placement, matching Flash's "first frame construction" behavior.
	if (is_sprite)
	{
		Character* ch = &dictionary[char_id];
		if (ch->sprite_frame_funcs != NULL && ch->sprite_frame_funcs[0] != NULL)
		{
			if (obj->sprite_display_list == NULL)
			{
				obj->sprite_dl_capacity = INITIAL_DISPLAYLIST_CAPACITY;
				obj->sprite_display_list = HCALLOC(obj->sprite_dl_capacity, sizeof(DisplayObject));
				obj->sprite_max_depth = 0;
			}
			obj->sprite_needs_init = 1;
		}
	}

	// Buttons also get a display list for their child sprites (up-state children).
	// tagShowFrame will initialize the button's up-state by running button_state_funcs[0].
	if (is_button)
	{
		if (obj->sprite_display_list == NULL)
		{
			obj->sprite_dl_capacity = INITIAL_DISPLAYLIST_CAPACITY;
			obj->sprite_display_list = HCALLOC(obj->sprite_dl_capacity, sizeof(DisplayObject));
			obj->sprite_max_depth = 0;
		}
		obj->sprite_needs_init = 1;
	}
}

void ng_on_remove_object(SWFAppContext* app_context, size_t depth)
{
	if (depth > max_depth || display_list[depth].char_id == 0) return;
	if (display_list[depth].instance_name != NULL) {
		// Fire AS-set onUnload handler
		actionFireOnUnload(app_context, display_list[depth].instance_name, (int)depth);
		// Only persist the MC (pending_removal) if it has an unload handler:
		// either clip_actions with UNLOAD event (0x4) or AS-level onUnload property.
		// MCs without unload handlers are immediately invalidated.
		int has_unload = 0;
		// Check clip_actions for UNLOAD event
		for (size_t ca = 0; ca < display_list[depth].clip_action_count; ca++) {
			if (display_list[depth].clip_actions[ca].event_flags & 0x4) {
				has_unload = 1;
				break;
			}
		}
		// Check accumulated clip_actions too (from prior replace)
		if (!has_unload) {
			for (size_t ca = 0; ca < display_list[depth].accumulated_clip_action_count; ca++) {
				if (display_list[depth].accumulated_clip_actions[ca].event_flags & 0x4) {
					has_unload = 1;
					break;
				}
			}
		}
		// Check AS-level onUnload property
		if (!has_unload) {
			has_unload = actionMCHasOnUnloadProperty(display_list[depth].instance_name, (int)depth);
		}
		if (has_unload) {
			actionMarkMCPendingRemoval(app_context, display_list[depth].instance_name, (int)depth);
		} else {
			actionInvalidateCachedMovieClip(app_context, display_list[depth].instance_name, (int)depth);
		}
	}
}

// ---------------------------------------------------------------------------
// Sprite control helpers (use g_current_sprite_obj set by exec_sprite_frame)
// ---------------------------------------------------------------------------

int ng_isInsideSprite(void) { return g_current_sprite_obj != NULL; }

void ng_stopCurrentSprite(void)
{
	if (g_current_sprite_obj != NULL)
		g_current_sprite_obj->sprite_is_playing = 0;
}

void ng_playCurrentSprite(void)
{
	if (g_current_sprite_obj != NULL)
		g_current_sprite_obj->sprite_is_playing = 1;
}

void ng_gotoFrameCurrentSprite(u16 frame)
{
	DisplayObject* obj = g_current_sprite_obj;
	if (obj == NULL || obj->char_id == 0) return;
	Character* ch = &dictionary[obj->char_id];
	if (ch->type != CHAR_TYPE_SPRITE) return;
	if (ch->sprite_frame_count == 0) return;
	// Clamp to last frame
	if (frame >= ch->sprite_frame_count)
		frame = (u16)(ch->sprite_frame_count - 1);
	obj->sprite_manual_next_frame = 1;
	obj->sprite_next_frame = frame;
	obj->sprite_is_playing = 0;
}

size_t ng_getSpriteFrameCount(void)
{
	DisplayObject* obj = g_current_sprite_obj;
	if (obj == NULL || obj->char_id == 0) return 0;
	Character* ch = &dictionary[obj->char_id];
	if (ch->type != CHAR_TYPE_SPRITE) return 0;
	return ch->sprite_frame_count;
}

// Navigate a specific MovieClip's sprite to a given 0-based frame.
// Searches display_list for the entry matching mc->name.
// Returns 1 if sprite found and navigated, 0 if not found.
int ng_gotoFrameByMC(SWFAppContext* app_context, MovieClip* mc, u16 frame, int play)
{
	extern MovieClip root_movieclip;
	if (!mc || mc == &root_movieclip) return 0;
	if (!mc->name || mc->name[0] == '\0') return 0;

	size_t depth = ng_findDisplayEntryByName(mc->name);
	if (depth == SIZE_MAX)
	{
		// Dynamically created MCs (createEmptyMovieClip) aren't in the display list.
		// For these, just update currentframe and play state — they have no frame scripts.
		u16 clamped = frame;
		if (mc->totalframes > 0 && clamped >= (u16)mc->totalframes)
			clamped = (u16)(mc->totalframes - 1);
		mc->currentframe = (int)clamped + 1;  // 1-indexed
		return 1;
	}

	DisplayObject* obj = &display_list[depth];
	if (obj->char_id == 0) return 0;
	Character* ch = &dictionary[obj->char_id];
	if (ch->type != CHAR_TYPE_SPRITE) return 0;

	size_t fc = ch->sprite_frame_count;
	if (fc == 0) return 0;

	// Clamp to last frame
	if (frame >= (u16)fc) frame = (u16)(fc - 1);

	// Execute frames synchronously (like advance_sprite_frames but immediate)
	size_t current = obj->sprite_current_frame;
	if (frame != current)
	{
		// Swap to sprite's display list context
		DisplayObject* saved_dl = display_list;
		size_t saved_max = max_depth;
		size_t saved_cap = display_list_capacity;

		display_list = obj->sprite_display_list;
		max_depth = obj->sprite_max_depth;
		display_list_capacity = obj->sprite_dl_capacity;

		if (display_list == NULL)
		{
			// Allocate sprite display list if needed
			obj->sprite_dl_capacity = 32;
			obj->sprite_display_list = HCALLOC(obj->sprite_dl_capacity, sizeof(DisplayObject));
			display_list = obj->sprite_display_list;
			display_list_capacity = obj->sprite_dl_capacity;
		}

		if (frame <= current)
		{
			// Backward jump: clear display list and re-execute from frame 0
			for (size_t j = 1; j <= max_depth; ++j)
			{
				if (display_list[j].sprite_display_list != NULL)
				{
					FREE(display_list[j].sprite_display_list);
					display_list[j].sprite_display_list = NULL;
				}
				display_list[j].char_id = 0;
			}
			max_depth = 0;

			for (size_t f = 0; f <= frame; f++)
			{
				if (f < fc && ch->sprite_frame_funcs[f] != NULL)
					ch->sprite_frame_funcs[f](app_context);
			}
		}
		else
		{
			// Forward jump: execute frames current+1..frame
			for (size_t f = current + 1; f <= frame; f++)
			{
				if (f < fc && ch->sprite_frame_funcs[f] != NULL)
					ch->sprite_frame_funcs[f](app_context);
			}
		}

		obj->sprite_display_list = display_list;
		obj->sprite_max_depth = max_depth;
		obj->sprite_dl_capacity = display_list_capacity;

		display_list = saved_dl;
		max_depth = saved_max;
		display_list_capacity = saved_cap;
	}

	obj->sprite_current_frame = frame;
	obj->sprite_manual_next_frame = 0;
	obj->sprite_is_playing = play ? 1 : 0;
	mc->currentframe = (int)frame + 1;  // 1-indexed
	return 1;
}

// Get the character ID for a MovieClip's display entry (for sprite label lookup).
// Returns 0 if not found.
size_t ng_getCharIdByMC(MovieClip* mc)
{
	extern MovieClip root_movieclip;
	if (!mc || mc == &root_movieclip) return 0;
	if (!mc->name || mc->name[0] == '\0') return 0;
	size_t depth = ng_findDisplayEntryByName(mc->name);
	if (depth == SIZE_MAX) return 0;
	return display_list[depth].char_id;
}

// ---------------------------------------------------------------------------
// Character type queries (root-level display_list lookup)
// ---------------------------------------------------------------------------

int ng_isSpriteAtDepth(size_t depth)
{
	if (depth > max_depth || display_list[depth].char_id == 0) return 0;
	size_t cid = display_list[depth].char_id;
	return (dictionary[cid].type == CHAR_TYPE_SPRITE);
}

size_t ng_getSpriteByteSize(size_t char_id)
{
	if (char_id == 0 || char_id >= INITIAL_DICTIONARY_CAPACITY) return 0;
	if (dictionary[char_id].type != CHAR_TYPE_SPRITE) return 0;
	return dictionary[char_id].sprite_byte_size;
}

int ng_isButtonAtDepth(size_t depth)
{
	if (depth > max_depth || display_list[depth].char_id == 0) return 0;
	return ng_find_button(display_list[depth].char_id);
}

int ng_isTextFieldAtDepth(size_t depth)
{
	if (depth > max_depth || display_list[depth].char_id == 0) return 0;
	return (ng_find_textfield(display_list[depth].char_id) >= 0);
}

int ng_isScriptableAtDepth(size_t depth)
{
	if (depth > max_depth || display_list[depth].char_id == 0) return 0;
	size_t cid = display_list[depth].char_id;
	return (dictionary[cid].type == CHAR_TYPE_SPRITE) ||
	       ng_find_button(cid) ||
	       (ng_find_textfield(cid) >= 0) ||
	       ng_find_video(cid);
}

int ng_isScriptableChar(size_t char_id)
{
	return (dictionary[char_id].type == CHAR_TYPE_SPRITE) ||
	       ng_find_button(char_id) ||
	       (ng_find_textfield(char_id) >= 0) ||
	       ng_find_video(char_id);
}

// ---------------------------------------------------------------------------
// Display entry lookup (returns entry_idx = encoded depth)
// ---------------------------------------------------------------------------

// Find root-level display entry by name.  Returns SWF depth (entry_idx encoding: upper bits=0).
size_t ng_findDisplayEntryByName(const char* name)
{
	size_t result = SIZE_MAX;
	for (size_t d = 0; d <= max_depth; d++)
	{
		if (display_list[d].char_id == 0) continue;
		if (display_list[d].instance_name == NULL) continue;
		if (swf_name_match(display_list[d].instance_name, name))
		{
			if (result == SIZE_MAX || d < result)
				result = d;
		}
	}
	return result;
}

// Find display entry index by instance name (root-level only).
// Returns entry_idx = depth, or (size_t)-1 if not found.
size_t ng_findDisplayEntryIdx(const char* name)
{
	if (!name || name[0] == '\0') return (size_t)-1;
	for (size_t d = 0; d <= max_depth; d++)
	{
		if (display_list[d].char_id == 0) continue;
		if (display_list[d].instance_name != NULL &&
		    swf_name_match(display_list[d].instance_name, name))
			return d;  // entry_idx = root depth (upper bits = 0)
	}
	return (size_t)-1;
}

// Find display entry by name within a parent.
// parent_idx = (size_t)-1: root level (same as ng_findDisplayEntryIdx).
// parent_idx = root depth: search that sprite's sprite_display_list.
// Returns encoded entry_idx, or (size_t)-1 if not found.
size_t ng_findDisplayEntryIdxWithParent(const char* name, size_t parent_idx)
{
	if (!name || name[0] == '\0') return (size_t)-1;

	if (parent_idx == (size_t)-1)
	{
		// Root level
		return ng_findDisplayEntryIdx(name);
	}

	// Nested: parent_idx encodes the parent's entry (root depth for level-1 nesting)
	size_t parent_root_depth = parent_idx & 0xFFFFF;  // lower 20 bits = root depth for level-1
	if (parent_root_depth < 1 || parent_root_depth > max_depth) return (size_t)-1;
	DisplayObject* parent_obj = &display_list[parent_root_depth];
	if (parent_obj->char_id == 0 || parent_obj->sprite_display_list == NULL) return (size_t)-1;

	for (size_t d = 1; d <= parent_obj->sprite_max_depth; d++)
	{
		DisplayObject* child = &parent_obj->sprite_display_list[d];
		if (child->char_id == 0) continue;
		if (child->instance_name != NULL && swf_name_match(child->instance_name, name))
			return (parent_root_depth << 20) | d;  // encoded nested entry_idx
	}
	return (size_t)-1;
}

// Find root-level SWF depth by entry name (returns depth, SIZE_MAX if not found).
// Alias used by action.c for timeline targeting.
size_t ng_findDisplayEntryByName_depth(const char* name)
{
	return ng_findDisplayEntryByName(name);
}

// ---------------------------------------------------------------------------
// Root-level depth queries used by action.c for SWF depth targeting
// ---------------------------------------------------------------------------

int ng_findRootChildAtSWFDepth(size_t swf_depth, char* out_name, size_t out_name_size)
{
	if (swf_depth < 1 || swf_depth > max_depth || display_list[swf_depth].char_id == 0)
		return 0;

	size_t cid = display_list[swf_depth].char_id;

	if (dictionary[cid].type == CHAR_TYPE_SPRITE)
	{
		if (out_name && out_name_size > 0)
		{
			const char* n = display_list[swf_depth].instance_name;
			strncpy(out_name, n ? n : "", out_name_size - 1);
			out_name[out_name_size - 1] = '\0';
		}
		return 2;
	}
	else if (ng_find_textfield(cid) >= 0)
	{
		if (out_name && out_name_size > 0)
		{
			const char* n = display_list[swf_depth].instance_name;
			strncpy(out_name, n ? n : "", out_name_size - 1);
			out_name[out_name_size - 1] = '\0';
		}
		return 3;
	}
	else
	{
		if (out_name && out_name_size > 0) out_name[0] = '\0';
		return 1;
	}
}

// Search for a named child within a named parent's display list.
// Returns child's SWF depth within the parent, or SIZE_MAX if not found.
size_t ng_findChildEntryDepth(const char* parent_name, const char* child_name)
{
	// Find parent at root level
	size_t parent_depth = ng_findDisplayEntryByName(parent_name);
	if (parent_depth == SIZE_MAX) return SIZE_MAX;

	DisplayObject* parent_obj = &display_list[parent_depth];
	if (parent_obj->sprite_display_list == NULL) return SIZE_MAX;

	for (size_t d = 1; d <= parent_obj->sprite_max_depth; d++)
	{
		DisplayObject* child = &parent_obj->sprite_display_list[d];
		if (child->char_id == 0) continue;
		if (child->instance_name != NULL && strcmp(child->instance_name, child_name) == 0)
			return d;
	}
	return SIZE_MAX;
}

// ---------------------------------------------------------------------------
// Tab ordering: character-level queries for recursive display list scanning
// ---------------------------------------------------------------------------

// Return the ng_textfields[] index for a given character ID, or -1 if not a textfield.
// Used by action.c for setting ng_textfield_idx on nested (non-root) text field MCs.
int ng_getCharTextfieldIdx(size_t char_id)
{
	return ng_find_textfield(char_id);
}

// ---------------------------------------------------------------------------
// Transform queries (root-level)
// ---------------------------------------------------------------------------

int ng_getTransformId(size_t depth, u32* out_id)
{
	if (depth > max_depth || display_list[depth].char_id == 0) return 0;
	*out_id = display_list[depth].transform_id;
	return 1;
}

int ng_getTransformXY(size_t depth, float* out_x, float* out_y)
{
	if (depth > max_depth || display_list[depth].char_id == 0) return 0;
	u32 tid = display_list[depth].transform_id;
	*out_x = transform_data[tid][12] / 20.0f;
	*out_y = transform_data[tid][13] / 20.0f;
	return 1;
}

int ng_getTransformXY_d(size_t depth, double* out_x, double* out_y)
{
	if (depth > max_depth || display_list[depth].char_id == 0) return 0;
	u32 tid = display_list[depth].transform_id;
	if (out_x) *out_x = (double)transform_data[tid][12] / 20.0;
	if (out_y) *out_y = (double)transform_data[tid][13] / 20.0;
	return 1;
}

int ng_getTransformScaleRotation(size_t depth, float* out_xscale, float* out_yscale, float* out_rotation)
{
	if (depth > max_depth || display_list[depth].char_id == 0) return 0;
	u32 tid = display_list[depth].transform_id;
	float m00 = transform_data[tid][0];
	float m10 = transform_data[tid][1];
	float m01 = transform_data[tid][4];
	float m11 = transform_data[tid][5];
	if (out_xscale)  *out_xscale  = sqrtf(m00*m00 + m10*m10) * 100.0f;
	if (out_yscale)  *out_yscale  = sqrtf(m01*m01 + m11*m11) * 100.0f;
	if (out_rotation) *out_rotation = atan2f(m10, m00) * 180.0f / 3.14159265358979323846f;
	return 1;
}

// ---------------------------------------------------------------------------
// Matrix and color transform queries by entry_idx
// ---------------------------------------------------------------------------

int ng_getMatrixFromEntry(size_t entry_idx,
    double* out_a, double* out_b, double* out_c, double* out_d,
    double* out_tx, double* out_ty)
{
	DisplayObject* obj = ng_entry_to_obj(entry_idx);
	if (!obj) return 0;
	u32 tid = obj->transform_id;
	if (out_a)  *out_a  = (double)transform_data[tid][0];
	if (out_b)  *out_b  = (double)transform_data[tid][1];
	if (out_c)  *out_c  = (double)transform_data[tid][4];
	if (out_d)  *out_d  = (double)transform_data[tid][5];
	if (out_tx) *out_tx = (double)transform_data[tid][12] / 20.0;
	if (out_ty) *out_ty = (double)transform_data[tid][13] / 20.0;
	return 1;
}

// Variant: f32 a/b/c/d, i32 twips tx/ty (matches Ruffle render Matrix)
int ng_getMatrixFromEntry_render(size_t entry_idx,
    float* out_a, float* out_b, float* out_c, float* out_d,
    int32_t* out_tx_twips, int32_t* out_ty_twips)
{
	DisplayObject* obj = ng_entry_to_obj(entry_idx);
	if (!obj) return 0;
	u32 tid = obj->transform_id;
	if (out_a)  *out_a  = transform_data[tid][0];
	if (out_b)  *out_b  = transform_data[tid][1];
	if (out_c)  *out_c  = transform_data[tid][4];
	if (out_d)  *out_d  = transform_data[tid][5];
	if (out_tx_twips) *out_tx_twips = (int32_t)rintf(transform_data[tid][12]);
	if (out_ty_twips) *out_ty_twips = (int32_t)rintf(transform_data[tid][13]);
	return 1;
}

int ng_getCTFromEntry(size_t entry_idx,
    double* ra, double* ga, double* ba, double* aa,
    double* rb, double* gb, double* bb, double* ab)
{
	DisplayObject* obj = ng_entry_to_obj(entry_idx);
	if (!obj) return 0;
	if (ra) *ra = obj->cx_ra; if (ga) *ga = obj->cx_ga;
	if (ba) *ba = obj->cx_ba; if (aa) *aa = obj->cx_aa;
	if (rb) *rb = obj->cx_rb; if (gb) *gb = obj->cx_gb;
	if (bb) *bb = obj->cx_bb; if (ab) *ab = obj->cx_ab;
	return 1;
}

int ng_setCTOnEntry(size_t entry_idx,
    double ra, double ga, double ba, double aa,
    double rb, double gb, double bb, double ab)
{
	DisplayObject* obj = ng_entry_to_obj(entry_idx);
	if (!obj) return 0;
	obj->cx_ra = ra; obj->cx_ga = ga; obj->cx_ba = ba; obj->cx_aa = aa;
	obj->cx_rb = rb; obj->cx_gb = gb; obj->cx_bb = bb; obj->cx_ab = ab;
	obj->cx_overridden = 1;
	return 1;
}

// ---------------------------------------------------------------------------
// Color transform by name (root-level display_list scan)
// ---------------------------------------------------------------------------

int ng_getColorTransform(const char* name, double* ra, double* ga, double* ba, double* aa,
                          double* rb, double* gb, double* bb, double* ab)
{
	for (size_t d = 0; d <= max_depth; d++)
	{
		if (display_list[d].char_id == 0) continue;
		if (display_list[d].instance_name != NULL &&
		    strcmp(display_list[d].instance_name, name) == 0)
		{
			*ra = display_list[d].cx_ra; *ga = display_list[d].cx_ga;
			*ba = display_list[d].cx_ba; *aa = display_list[d].cx_aa;
			*rb = display_list[d].cx_rb; *gb = display_list[d].cx_gb;
			*bb = display_list[d].cx_bb; *ab = display_list[d].cx_ab;
			return 1;
		}
	}
	return 0;
}

int ng_setColorTransform(const char* name, double ra, double ga, double ba, double aa,
                          double rb, double gb, double bb, double ab)
{
	for (size_t d = 0; d <= max_depth; d++)
	{
		if (display_list[d].char_id == 0) continue;
		if (display_list[d].instance_name != NULL &&
		    strcmp(display_list[d].instance_name, name) == 0)
		{
			display_list[d].cx_ra = ra; display_list[d].cx_ga = ga;
			display_list[d].cx_ba = ba; display_list[d].cx_aa = aa;
			display_list[d].cx_rb = rb; display_list[d].cx_gb = gb;
			display_list[d].cx_bb = bb; display_list[d].cx_ab = ab;
			display_list[d].cx_overridden = 1;
			return 1;
		}
	}
	return 0;
}

// ---------------------------------------------------------------------------
// Character bounds lookup
// ---------------------------------------------------------------------------

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

// Ratio-aware bounds: interpolates between start and end bounds for morph shapes.
// ratio: 0 = start shape, 65535 = end shape.
int ng_getCharBoundsForRatio(size_t char_id, u16 ratio,
    s32* out_xmin, s32* out_xmax, s32* out_ymin, s32* out_ymax)
{
	// First get the start bounds
	if (!ng_getCharBounds(char_id, out_xmin, out_xmax, out_ymin, out_ymax))
		return 0;

	// If ratio is 0, start bounds are correct
	if (ratio == 0)
		return 1;

	// Look up end bounds for this morph shape
	for (size_t i = 0; i < ng_morph_end_bounds_count; i++)
	{
		if (ng_morph_end_bounds[i].char_id == char_id)
		{
			// Linear interpolation: t = ratio / 65535.0
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

	// No end bounds found — return start bounds as-is
	return 1;
}

// ---------------------------------------------------------------------------
// Composite bounds computation (union of child content bounds in pixels)
// entry_idx == (size_t)-1: root-level children
// entry_idx is a root depth: children are sprite_display_list of that entry
// ---------------------------------------------------------------------------

int ng_getDisplayEntryBounds(size_t entry_idx,
    float* out_xmin_px, float* out_xmax_px,
    float* out_ymin_px, float* out_ymax_px)
{
	int found = 0;
	float gxmin = 1e30f, gxmax = -1e30f;
	float gymin = 1e30f, gymax = -1e30f;

	// Determine which display list to iterate
	DisplayObject* dl;
	size_t dl_max;

	if (entry_idx == (size_t)-1)
	{
		// Root level
		dl = display_list;
		dl_max = max_depth;
	}
	else
	{
		// Must be a root-depth entry (level-0 nesting only for bounds)
		size_t parent_d = entry_idx >> 20;
		size_t child_d  = entry_idx & 0xFFFFF;
		if (parent_d == 0)
		{
			// Root-depth sprite: iterate its sprite_display_list
			if (child_d < 1 || child_d > max_depth || display_list[child_d].char_id == 0) return 0;
			if (display_list[child_d].sprite_display_list == NULL) return 0;
			dl     = display_list[child_d].sprite_display_list;
			dl_max = display_list[child_d].sprite_max_depth;
		}
		else
		{
			// Level-1 nested: find child in parent's sprite display list
			if (parent_d < 1 || parent_d > max_depth || display_list[parent_d].char_id == 0) return 0;
			DisplayObject* parent_obj = &display_list[parent_d];
			if (parent_obj->sprite_display_list == NULL) return 0;
			if (child_d < 1 || child_d > parent_obj->sprite_max_depth) return 0;
			DisplayObject* child_obj = &parent_obj->sprite_display_list[child_d];
			if (child_obj->char_id == 0 || child_obj->sprite_display_list == NULL) return 0;
			dl     = child_obj->sprite_display_list;
			dl_max = child_obj->sprite_max_depth;
		}
	}

	for (size_t i = 1; i <= dl_max; i++)
	{
		DisplayObject* obj = &dl[i];
		if (obj->char_id == 0) continue;

		u32 tid = obj->transform_id;
		float tx = transform_data[tid][12] / 20.0f;
		float ty = transform_data[tid][13] / 20.0f;
		float sx = transform_data[tid][0];
		float sy = transform_data[tid][5];

		float bxmin, bxmax, bymin, bymax;
		int child_found = 0;

		size_t cid = obj->char_id;

		if (dictionary[cid].type == CHAR_TYPE_SPRITE && obj->sprite_display_list != NULL)
		{
			// Recursively get sprite's local bounds
			float lxmin, lxmax, lymin, lymax;
			size_t child_entry = (entry_idx == (size_t)-1)
				? (i)                         // root sprite: entry_idx = depth
				: (((entry_idx & 0xFFFFF) << 20) | i);  // nested: encode (but bounds are simplified)
			(void)child_entry;
			// Simplified: use sprite's own sprite_display_list directly
			if (ng_getDisplayEntryBounds(i, &lxmin, &lxmax, &lymin, &lymax))
			{
				bxmin = lxmin * sx + tx;
				bxmax = lxmax * sx + tx;
				bymin = lymin * sy + ty;
				bymax = lymax * sy + ty;
				if (bxmin > bxmax) { float t = bxmin; bxmin = bxmax; bxmax = t; }
				if (bymin > bymax) { float t = bymin; bymin = bymax; bymax = t; }
				child_found = 1;
			}
		}
		else if (ng_find_textfield(cid) >= 0)
		{
			int tf_idx = ng_find_textfield(cid);
			float bxf  = ng_textfields[tf_idx].bounds_xmin / 20.0f;
			float bxf2 = ng_textfields[tf_idx].bounds_xmax / 20.0f;
			float byf  = ng_textfields[tf_idx].bounds_ymin / 20.0f;
			float byf2 = ng_textfields[tf_idx].bounds_ymax / 20.0f;
			bxmin = bxf  * sx + tx;
			bxmax = bxf2 * sx + tx;
			bymin = byf  * sy + ty;
			bymax = byf2 * sy + ty;
			if (bxmin > bxmax) { float t = bxmin; bxmin = bxmax; bxmax = t; }
			if (bymin > bymax) { float t = bymin; bymin = bymax; bymax = t; }
			child_found = 1;
		}
		else if (!ng_find_button(cid))
		{
			// Shape: look up char bounds
			s32 cbxmin, cbxmax, cbymin, cbymax;
			if (ng_getCharBounds(cid, &cbxmin, &cbxmax, &cbymin, &cbymax))
			{
				bxmin = cbxmin / 20.0f * sx + tx;
				bxmax = cbxmax / 20.0f * sx + tx;
				bymin = cbymin / 20.0f * sy + ty;
				bymax = cbymax / 20.0f * sy + ty;
				if (bxmin > bxmax) { float t = bxmin; bxmin = bxmax; bxmax = t; }
				if (bymin > bymax) { float t = bymin; bymin = bymax; bymax = t; }
				child_found = 1;
			}
		}

		if (child_found)
		{
			if (!found || bxmin < gxmin) gxmin = bxmin;
			if (!found || bxmax > gxmax) gxmax = bxmax;
			if (!found || bymin < gymin) gymin = bymin;
			if (!found || bymax > gymax) gymax = bymax;
			found = 1;
		}
	}

	if (found)
	{
		if (out_xmin_px) *out_xmin_px = gxmin;
		if (out_xmax_px) *out_xmax_px = gxmax;
		if (out_ymin_px) *out_ymin_px = gymin;
		if (out_ymax_px) *out_ymax_px = gymax;
	}
	return found;
}

// ---------------------------------------------------------------------------
// getBounds helper: compute local content bounds for a MovieClip (twips)
// ---------------------------------------------------------------------------

// Recursively compute union of child bounds in a display list (results in twips)
// Uses Fixed16 integer arithmetic to match Ruffle/Flash's truncating behavior.
// Fixed16: 16.16 signed fixed-point. Matrix entries stored as Fixed16 raw i32 values.
// wrapping_mul_int(fixed16, twips_i32) = (int32_t)(((int64_t)fixed16 * twips_i32) >> 16)
#define FP16_ONE 65536
#define FP_MUL(f16, tw) ((int32_t)(((int64_t)(f16) * (int64_t)(tw)) >> 16))
// Compose two Fixed16 values: (a * b) >> 16  (both are 16.16)
#define FP_MUL16(a, b) ((int32_t)(((int64_t)(a) * (int64_t)(b)) >> 16))
// Convert float matrix entry to Fixed16 raw i32
#define FLOAT_TO_FP16(f) ((int32_t)((f) * 65536.0f))
// Convert twips (float, from transform_data) to i32 twips
#define FLOAT_TO_TWIPS(f) ((int32_t)(f))

static void boundsUnionCornerFP(int32_t px, int32_t py,
	int32_t fa, int32_t fb, int32_t fc, int32_t fd, int32_t ftx, int32_t fty,
	int* has, int32_t* gxmin, int32_t* gymin, int32_t* gxmax, int32_t* gymax)
{
	int32_t tx = FP_MUL(fa, px) + FP_MUL(fc, py) + ftx;
	int32_t ty = FP_MUL(fb, px) + FP_MUL(fd, py) + fty;
	if (!*has) { *gxmin = *gxmax = tx; *gymin = *gymax = ty; *has = 1; }
	else {
		if (tx < *gxmin) *gxmin = tx;
		if (tx > *gxmax) *gxmax = tx;
		if (ty < *gymin) *gymin = ty;
		if (ty > *gymax) *gymax = ty;
	}
}

// Compute bounds using Fixed16 integer arithmetic matching Ruffle/Flash.
// Matrix entries (fa,fb,fc,fd) are Fixed16 raw i32 values; ftx,fty are i32 twips.
int ng_computeBoundsFromDL_fp16(DisplayObject* dl, size_t dl_max,
    int32_t fa, int32_t fb, int32_t fc, int32_t fd, int32_t ftx, int32_t fty,
    int* has, int32_t* gxmin, int32_t* gymin, int32_t* gxmax, int32_t* gymax)
{
	for (size_t i = 1; i <= dl_max; i++) {
		DisplayObject* child = &dl[i];
		if (child->char_id == 0) continue;
		u32 tid = child->transform_id;
		int32_t ca = FLOAT_TO_FP16(transform_data[tid][0]);
		int32_t cb = FLOAT_TO_FP16(transform_data[tid][1]);
		int32_t cc = FLOAT_TO_FP16(transform_data[tid][4]);
		int32_t cd = FLOAT_TO_FP16(transform_data[tid][5]);
		int32_t ctx_tw = FLOAT_TO_TWIPS(transform_data[tid][12]);
		int32_t cty_tw = FLOAT_TO_TWIPS(transform_data[tid][13]);
		// Compose: new_matrix = outer * child  (Fixed16 composition)
		int32_t na = FP_MUL16(fa, ca) + FP_MUL16(fc, cb);
		int32_t nb = FP_MUL16(fb, ca) + FP_MUL16(fd, cb);
		int32_t nc = FP_MUL16(fa, cc) + FP_MUL16(fc, cd);
		int32_t nd = FP_MUL16(fb, cc) + FP_MUL16(fd, cd);
		int32_t ntx = FP_MUL(fa, ctx_tw) + FP_MUL(fc, cty_tw) + ftx;
		int32_t nty = FP_MUL(fb, ctx_tw) + FP_MUL(fd, cty_tw) + fty;

		if (child->sprite_display_list != NULL && child->sprite_max_depth > 0) {
			ng_computeBoundsFromDL_fp16(child->sprite_display_list, child->sprite_max_depth,
				na, nb, nc, nd, ntx, nty, has, gxmin, gymin, gxmax, gymax);
		} else {
			s32 cxmin, cxmax, cymin, cymax;
			int child_has = ng_getCharBounds(child->char_id, &cxmin, &cxmax, &cymin, &cymax);
			if (!child_has) {
				int tf_idx = ng_find_textfield(child->char_id);
				if (tf_idx >= 0) {
					cxmin = ng_textfields[tf_idx].bounds_xmin;
					cxmax = ng_textfields[tf_idx].bounds_xmax;
					cymin = ng_textfields[tf_idx].bounds_ymin;
					cymax = ng_textfields[tf_idx].bounds_ymax;
					child_has = 1;
				}
			}
			if (!child_has) continue;
			boundsUnionCornerFP(cxmin, cymin, na, nb, nc, nd, ntx, nty, has, gxmin, gymin, gxmax, gymax);
			boundsUnionCornerFP(cxmax, cymin, na, nb, nc, nd, ntx, nty, has, gxmin, gymin, gxmax, gymax);
			boundsUnionCornerFP(cxmin, cymax, na, nb, nc, nd, ntx, nty, has, gxmin, gymin, gxmax, gymax);
			boundsUnionCornerFP(cxmax, cymax, na, nb, nc, nd, ntx, nty, has, gxmin, gymin, gxmax, gymax);
		}
	}
	return *has;
}

// Double-precision wrappers kept for non-getBounds uses
static void boundsUnionCorner(double px, double py,
	double ma, double mb, double mc, double md, double mtx, double mty,
	int* has, double* gxmin, double* gymin, double* gxmax, double* gymax)
{
	// Ruffle uses f32 matrix * i32 twips → round_to_i32 per corner, then wrapping_add(tx).
	// tx/ty are Twips (integer). Simulate by rounding rotation+scale product and translation.
	double tx = round((float)(ma * px + mc * py)) + round(mtx);
	double ty = round((float)(mb * px + md * py)) + round(mty);
	if (!*has) { *gxmin = *gxmax = tx; *gymin = *gymax = ty; *has = 1; }
	else {
		if (tx < *gxmin) *gxmin = tx;
		if (tx > *gxmax) *gxmax = tx;
		if (ty < *gymin) *gymin = ty;
		if (ty > *gymax) *gymax = ty;
	}
}

int ng_computeBoundsFromDL_matrix(DisplayObject* dl, size_t dl_max,
    double ma, double mb, double mc, double md, double mtx, double mty,
    int* has, double* gxmin, double* gymin, double* gxmax, double* gymax)
{
	for (size_t i = 1; i <= dl_max; i++) {
		DisplayObject* child = &dl[i];
		if (child->char_id == 0) continue;
		u32 tid = child->transform_id;
		float ca = transform_data[tid][0];
		float cb = transform_data[tid][1];
		float cc = transform_data[tid][4];
		float cd = transform_data[tid][5];
		float ctxf = transform_data[tid][12];
		float ctyf = transform_data[tid][13];
		// Ruffle composes matrices in f32 arithmetic
		float fma = (float)ma, fmb = (float)mb, fmc = (float)mc, fmd = (float)md;
		float fmtx = (float)mtx, fmty = (float)mty;
		double na = (double)(fma*ca + fmc*cb), nb = (double)(fmb*ca + fmd*cb);
		double nc = (double)(fma*cc + fmc*cd), nd = (double)(fmb*cc + fmd*cd);
		double ntx = (double)(fma*ctxf + fmc*ctyf + fmtx);
		double nty = (double)(fmb*ctxf + fmd*ctyf + fmty);

		if (child->sprite_display_list != NULL && child->sprite_max_depth > 0) {
			ng_computeBoundsFromDL_matrix(child->sprite_display_list, child->sprite_max_depth,
				na, nb, nc, nd, ntx, nty, has, gxmin, gymin, gxmax, gymax);
		} else {
			s32 cxmin, cxmax, cymin, cymax;
			int child_has = ng_getCharBounds(child->char_id, &cxmin, &cxmax, &cymin, &cymax);
			if (!child_has) {
				int tf_idx = ng_find_textfield(child->char_id);
				if (tf_idx >= 0) {
					cxmin = ng_textfields[tf_idx].bounds_xmin;
					cxmax = ng_textfields[tf_idx].bounds_xmax;
					cymin = ng_textfields[tf_idx].bounds_ymin;
					cymax = ng_textfields[tf_idx].bounds_ymax;
					child_has = 1;
				}
			}
			if (!child_has) continue;
			boundsUnionCorner((double)cxmin, (double)cymin, na, nb, nc, nd, ntx, nty, has, gxmin, gymin, gxmax, gymax);
			boundsUnionCorner((double)cxmax, (double)cymin, na, nb, nc, nd, ntx, nty, has, gxmin, gymin, gxmax, gymax);
			boundsUnionCorner((double)cxmin, (double)cymax, na, nb, nc, nd, ntx, nty, has, gxmin, gymin, gxmax, gymax);
			boundsUnionCorner((double)cxmax, (double)cymax, na, nb, nc, nd, ntx, nty, has, gxmin, gymin, gxmax, gymax);
		}
	}
	return *has;
}

// Simple wrapper: compute bounds in local space (identity matrix)
int ng_computeBoundsFromDL(DisplayObject* dl, size_t dl_max,
    int32_t* out_xmin, int32_t* out_ymin, int32_t* out_xmax, int32_t* out_ymax)
{
	int has = 0;
	double gxmin = 0, gymin = 0, gxmax = 0, gymax = 0;
	ng_computeBoundsFromDL_matrix(dl, dl_max, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,
		&has, &gxmin, &gymin, &gxmax, &gymax);
	if (has) {
		*out_xmin = (int32_t)rintf((float)gxmin); *out_ymin = (int32_t)rintf((float)gymin);
		*out_xmax = (int32_t)rintf((float)gxmax); *out_ymax = (int32_t)rintf((float)gymax);
	}
	return has;
}

// ---------------------------------------------------------------------------
// Shape-accurate point-in-shape test (for hitTest shapeFlag=true)
// ---------------------------------------------------------------------------
extern u32 shape_data[][4];

// Test if a point is inside a single triangle (barycentric coordinates)
static int pit(double px, double py,
               double ax, double ay, double bx, double by, double cx, double cy)
{
	double d1 = (px - bx) * (ay - by) - (ax - bx) * (py - by);
	double d2 = (px - cx) * (by - cy) - (bx - cx) * (py - cy);
	double d3 = (px - ax) * (cy - ay) - (cx - ax) * (py - ay);
	int has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	int has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	return !(has_neg && has_pos);
}

// Morph end vertex data (for interpolated shape hit testing)
extern float morph_end_shape_data[][2];

// Test a point (in twips, parent-accumulated matrix space) against a char's shape triangles.
// ma..mty is the child's accumulated world matrix (mapping local twips → test space).
// ratio: morph ratio (0=start, 65535=end). Ignored for non-morph shapes.
// Returns 1 if hit, 0 if miss.
static int ng_hitTestShapeChar(size_t char_id, u16 ratio,
    double ma, double mb, double mc_m, double md, double mtx, double mty,
    double test_x, double test_y)
{
	Character* ch = &dictionary[char_id];
	int is_morph = (ch->type == CHAR_TYPE_MORPH_SHAPE);
	if (ch->type != CHAR_TYPE_SHAPE && !is_morph) return 0;

	size_t offset, count;
	if (is_morph) {
		offset = ch->morph_start_offset;
		count = ch->morph_start_size;
	} else {
		offset = ch->shape_offset;
		count = ch->size;
	}
	if (count < 3) return 0;

	// Inverse-transform test point into shape's local space
	double det = ma * md - mb * mc_m;
	if (det == 0.0) return 0;
	double inv_det = 1.0 / det;
	double sx = test_x - mtx;
	double sy = test_y - mty;
	double local_x = ( md * sx - mc_m * sy) * inv_det;
	double local_y = (-mb * sx + ma  * sy) * inv_det;

	double interp_t = 0.0;
	size_t morph_end_off = 0;
	if (is_morph && ratio > 0) {
		interp_t = (double)ratio / 65535.0;
		morph_end_off = ch->morph_end_offset;
	}

	// Count triangle hits
	int hits = 0;
	size_t num_tris = count / 3;
	for (size_t t = 0; t < num_tris; t++) {
		const u32* v0 = shape_data[offset + t * 3 + 0];
		const u32* v1 = shape_data[offset + t * 3 + 1];
		const u32* v2 = shape_data[offset + t * 3 + 2];
		double ax = (double)*(const float*)&v0[0];
		double ay = (double)*(const float*)&v0[1];
		double bx = (double)*(const float*)&v1[0];
		double by = (double)*(const float*)&v1[1];
		double cx = (double)*(const float*)&v2[0];
		double cy = (double)*(const float*)&v2[1];

		if (is_morph && ratio > 0) {
			// Interpolate with end shape vertices
			size_t vi = morph_end_off + t * 3;
			double eax = (double)morph_end_shape_data[vi + 0][0];
			double eay = (double)morph_end_shape_data[vi + 0][1];
			double ebx = (double)morph_end_shape_data[vi + 1][0];
			double eby = (double)morph_end_shape_data[vi + 1][1];
			double ecx = (double)morph_end_shape_data[vi + 2][0];
			double ecy = (double)morph_end_shape_data[vi + 2][1];
			ax += (eax - ax) * interp_t;
			ay += (eay - ay) * interp_t;
			bx += (ebx - bx) * interp_t;
			by += (eby - by) * interp_t;
			cx += (ecx - cx) * interp_t;
			cy += (ecy - cy) * interp_t;
		}

		if (pit(local_x, local_y, ax, ay, bx, by, cx, cy))
			hits++;
	}

	if (ng_uses_nonzero_winding(char_id))
		return hits > 0;  // non-zero: any hit means inside
	return (hits % 2) == 1;  // even-odd: odd count = inside
}

int ng_hitTestShapeFromDL(DisplayObject* dl, size_t dl_max,
    double ma, double mb, double mc_m, double md, double mtx, double mty,
    double test_x, double test_y)
{
	for (size_t i = 1; i <= dl_max; i++) {
		DisplayObject* child = &dl[i];
		if (child->char_id == 0) continue;
		u32 tid = child->transform_id;
		double ca = (double)transform_data[tid][0];
		double cb = (double)transform_data[tid][1];
		double cc = (double)transform_data[tid][4];
		double cd = (double)transform_data[tid][5];
		double ctx_v = (double)transform_data[tid][12];
		double cty_v = (double)transform_data[tid][13];
		double na = ma*ca + mc_m*cb, nb = mb*ca + md*cb;
		double nc = ma*cc + mc_m*cd, nd = mb*cc + md*cd;
		double ntx = ma*ctx_v + mc_m*cty_v + mtx;
		double nty = mb*ctx_v + md*cty_v + mty;

		if (child->sprite_display_list != NULL && child->sprite_max_depth > 0) {
			if (ng_hitTestShapeFromDL(child->sprite_display_list, child->sprite_max_depth,
				na, nb, nc, nd, ntx, nty, test_x, test_y))
				return 1;
		} else {
			if (ng_hitTestShapeChar(child->char_id, child->ratio, na, nb, nc, nd, ntx, nty,
				test_x, test_y))
				return 1;
		}
	}
	return 0;
}

// ---------------------------------------------------------------------------
// Depth manipulation (swapDepths, updateDepth)
// ---------------------------------------------------------------------------

void ng_updateDisplayDepth(const char* name, int new_as_depth)
{
	size_t new_swf_depth = (size_t)(new_as_depth + 16384);

	// Find the entry by name
	size_t old_depth = SIZE_MAX;
	for (size_t d = 0; d <= max_depth; d++)
	{
		if (display_list[d].char_id == 0) continue;
		if (display_list[d].instance_name != NULL &&
		    strcmp(display_list[d].instance_name, name) == 0)
		{
			old_depth = d;
			break;
		}
	}
	if (old_depth == SIZE_MAX || old_depth == new_swf_depth) return;

	// Ensure display_list is large enough for new_swf_depth
	if (new_swf_depth >= display_list_capacity)
	{
		// Grow display_list using HCALLOC (copy + free old)
		size_t new_cap = new_swf_depth + 64;
		DisplayObject* new_dl = (DisplayObject*) calloc(new_cap, sizeof(DisplayObject));
		if (new_dl == NULL) return;
		memcpy(new_dl, display_list, (max_depth + 1) * sizeof(DisplayObject));
		// Note: can't FREE the original HCALLOC'd list safely here,
		// but we need to update the pointer. In practice swapDepths
		// to very high depths is rare and the old memory will leak.
		display_list = new_dl;
		display_list_capacity = new_cap;
	}

	if (display_list[new_swf_depth].char_id != 0)
	{
		// Target depth occupied: swap entries and update the other MC's depth
		DisplayObject tmp = display_list[old_depth];
		display_list[old_depth] = display_list[new_swf_depth];
		display_list[new_swf_depth] = tmp;
		// Mark both as swapped so timeline modifies are ignored
		display_list[old_depth].depth_swapped = 1;
		display_list[new_swf_depth].depth_swapped = 1;

		// Update the other MC's cached depth (AS depth = SWF depth - 16384)
		if (display_list[old_depth].instance_name != NULL)
		{
			extern int child_mc_count;
			extern MovieClip* child_mc_cache[];
			const char* other_name = display_list[old_depth].instance_name;
			for (int _ci = 0; _ci < child_mc_count; _ci++)
			{
				if (child_mc_cache[_ci] != NULL &&
				    strcmp(child_mc_cache[_ci]->name, other_name) == 0)
				{
					child_mc_cache[_ci]->depth = (int)old_depth - 16384;
					break;
				}
			}
		}
	}
	else
	{
		// Target depth empty: move entry and clear old slot
		display_list[new_swf_depth] = display_list[old_depth];
		display_list[new_swf_depth].depth_swapped = 1;
		memset(&display_list[old_depth], 0, sizeof(DisplayObject));
	}

	// Update max_depth
	if (new_swf_depth > max_depth) max_depth = new_swf_depth;
	// Shrink max_depth if we just cleared the last entry
	while (max_depth > 0 && display_list[max_depth].char_id == 0) max_depth--;
}

void ng_swapDisplayDepths(const char* name1, const char* name2)
{
	size_t d1 = SIZE_MAX, d2 = SIZE_MAX;
	for (size_t d = 0; d <= max_depth; d++)
	{
		if (display_list[d].char_id == 0) continue;
		if (display_list[d].instance_name != NULL)
		{
			if (strcmp(display_list[d].instance_name, name1) == 0) d1 = d;
			else if (strcmp(display_list[d].instance_name, name2) == 0) d2 = d;
		}
	}
	if (d1 != SIZE_MAX && d2 != SIZE_MAX)
	{
		// Swap the entire display entries (including their transform_ids etc.)
		DisplayObject tmp = display_list[d1];
		display_list[d1] = display_list[d2];
		display_list[d2] = tmp;
		// Mark both as swapped so timeline modifies are ignored
		display_list[d1].depth_swapped = 1;
		display_list[d2].depth_swapped = 1;
	}
}

// ---------------------------------------------------------------------------
// Instance name management
// ---------------------------------------------------------------------------

void ng_renameDisplayEntry(const char* old_name, const char* new_name)
{
	for (size_t d = 0; d <= max_depth; d++)
	{
		if (display_list[d].char_id == 0) continue;
		if (display_list[d].instance_name != NULL &&
		    strcmp(display_list[d].instance_name, old_name) == 0)
		{
			// If we own the old name, free it
			if (display_list[d].instance_name_owned)
			{
				free(display_list[d].instance_name);
			}
			// Must strdup since new_name may point to a stack buffer
			display_list[d].instance_name = strdup(new_name);
			display_list[d].instance_name_owned = 1;
			return;
		}
	}
}

// ---------------------------------------------------------------------------
// Child enumeration (for for-in over MovieClip children)
// ---------------------------------------------------------------------------

void ng_enumerateChildren(const char* parent_name,
    void (*callback)(const char* name, u32 name_len, void* user_data), void* user_data)
{
	if (parent_name != NULL && parent_name[0] != '\0')
	{
		// Find parent at root level
		size_t parent_depth = ng_findDisplayEntryByName(parent_name);
		if (parent_depth == SIZE_MAX) return;

		DisplayObject* parent_obj = &display_list[parent_depth];
		if (parent_obj->sprite_display_list == NULL) return;

		// Enumerate children of the sprite
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
		// Enumerate root-level children
		for (size_t d = 0; d <= max_depth; d++)
		{
			if (display_list[d].char_id == 0) continue;
			if (display_list[d].instance_name != NULL && display_list[d].instance_name[0] != '\0')
				callback(display_list[d].instance_name, (u32)strlen(display_list[d].instance_name), user_data);
		}
	}
}

// ---------------------------------------------------------------------------
// TextField property accessors
// ---------------------------------------------------------------------------

const char* ng_getTextFieldInitialText(size_t depth)
{
	if (depth > max_depth || display_list[depth].char_id == 0) return "";
	int tf_idx = ng_find_textfield(display_list[depth].char_id);
	if (tf_idx < 0) return "";
	return ng_textfields[tf_idx].plain_text;
}

u32 ng_getTextFieldColor(size_t depth)
{
	if (depth > max_depth || display_list[depth].char_id == 0) return 0;
	int tf_idx = ng_find_textfield(display_list[depth].char_id);
	if (tf_idx < 0) return 0;
	return ng_textfields[tf_idx].text_color;
}

u32 ng_getTextFieldColorByIdx(int idx)
{
	if (idx < 0 || (size_t)idx >= ng_textfield_count) return 0;
	return ng_textfields[idx].text_color;
}

int ng_getTextFieldIdx(size_t depth)
{
	if (depth > max_depth || display_list[depth].char_id == 0) return -1;
	return ng_find_textfield(display_list[depth].char_id);
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

// ---------------------------------------------------------------------------
// Font accessors
// ---------------------------------------------------------------------------

const char* ng_getFontName(u16 font_id)
{
	for (size_t i = 0; i < ng_font_count; i++)
		if (ng_fonts[i].font_id == font_id) return ng_fonts[i].name;
	return "";
}

// Find a font_id by name (case-insensitive). Returns 0 if not found.
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
// Clone/duplicate sprite helpers
// ---------------------------------------------------------------------------

MovieClip* ng_cloneSprite(SWFAppContext* app_context, const char* source_name,
                           const char* target_name, int depth)
{
	if (!source_name || !target_name) return NULL;
	if (depth > 2130706428) return NULL;

	// Find source by instance name at root level
	size_t src_depth = ng_findDisplayEntryByName(source_name);

	if (src_depth != SIZE_MAX)
	{
		size_t cid = display_list[src_depth].char_id;
		int scriptable = (dictionary[cid].type == CHAR_TYPE_SPRITE) ||
		                 ng_find_button(cid) || (ng_find_textfield(cid) >= 0) ||
		                 ng_find_video(cid);
		if (!scriptable) return NULL;

		// Place clone at target depth (AS depth → SWF depth = depth itself for CloneSprite)
		size_t target_swf_depth = (size_t)depth;
		// Pre-clear target depth if occupied
		if (target_swf_depth >= 1 && target_swf_depth <= max_depth &&
		    display_list[target_swf_depth].char_id != 0)
		{
			ng_on_remove_object(app_context, target_swf_depth);
			// clear_display_entry handled by tagRemoveObject2 caller — do minimal cleanup
			if (display_list[target_swf_depth].instance_name_owned &&
			    display_list[target_swf_depth].instance_name != NULL)
			{
				free(display_list[target_swf_depth].instance_name);
				display_list[target_swf_depth].instance_name_owned = 0;
				display_list[target_swf_depth].instance_name = NULL;
			}
		}

		// Copy display entry to clone depth
		if (target_swf_depth < INITIAL_DISPLAYLIST_CAPACITY)
		{
			// Ensure capacity
			if (target_swf_depth >= display_list_capacity)
			{
				size_t new_cap = target_swf_depth + 64;
				display_list = realloc(display_list, new_cap * sizeof(DisplayObject));
				memset(&display_list[display_list_capacity], 0,
				       (new_cap - display_list_capacity) * sizeof(DisplayObject));
				display_list_capacity = new_cap;
			}
			display_list[target_swf_depth] = display_list[src_depth];
			// Give clone its own strdup'd name
			display_list[target_swf_depth].instance_name = strdup(target_name);
			display_list[target_swf_depth].instance_name_owned = 1;
			display_list[target_swf_depth].sprite_display_list = NULL;
			display_list[target_swf_depth].sprite_max_depth = 0;
			display_list[target_swf_depth].sprite_dl_capacity = 0;
			display_list[target_swf_depth].sprite_needs_init = 0;
			display_list[target_swf_depth].clip_actions = NULL;
			display_list[target_swf_depth].clip_action_count = 0;
			if (target_swf_depth > max_depth) max_depth = target_swf_depth;
		}

		// CloneSprite fires onLoad for the clone (unlike duplicateMovieClip).
		// Clone depths are often too large for display_list[], so use pending queue.
		if (display_list[src_depth].clip_action_count > 0 &&
		    g_pending_load_count < MAX_PENDING_LOADS)
		{
			PendingLoad* pl = &g_pending_loads[g_pending_load_count++];
			strncpy(pl->instance_name, target_name, sizeof(pl->instance_name) - 1);
			pl->instance_name[sizeof(pl->instance_name) - 1] = '\0';
			pl->clip_actions = display_list[src_depth].clip_actions;
			pl->clip_action_count = display_list[src_depth].clip_action_count;
		}
	}

	// Find source MC and create clone MC
	MovieClip* src_mc = actionFindOrCreateMovieClip(app_context, source_name, &root_movieclip);
	if (src_mc == NULL || src_mc == &root_movieclip) return NULL; // cannot clone root
	MovieClip* clone_mc = actionFindOrCreateMovieClip(app_context, target_name, &root_movieclip);
	if (clone_mc == NULL) return NULL;

	if (src_mc != NULL)
	{
		clone_mc->x       = src_mc->x;
		clone_mc->y       = src_mc->y;
		clone_mc->xscale  = src_mc->xscale;
		clone_mc->yscale  = src_mc->yscale;
		clone_mc->rotation = src_mc->rotation;
		clone_mc->alpha   = src_mc->alpha;
		clone_mc->visible = src_mc->visible;
		clone_mc->totalframes   = src_mc->totalframes;
		clone_mc->framesloaded  = src_mc->framesloaded;
		clone_mc->as_set_flags  = src_mc->as_set_flags;
	}
	clone_mc->currentframe = 1;
	clone_mc->depth = depth;

	// Evict any old clone registered at this SWF depth, then register new one
	clone_depth_register(depth, target_name);

	// Register as global variable
	ActionVar _clone_mc_var = {0};
	_clone_mc_var.type = ACTION_STACK_VALUE_MOVIECLIP;
	_clone_mc_var.data.numeric_value = (u64)clone_mc;
	setVariableByName(target_name, &_clone_mc_var);

	// If source is a sprite, run frame 0 to populate clone's sprite_display_list.
	// After cloning, clear the source MC's display_obj so TextSnapshot of source
	// returns empty (Flash behavior: text "moves" from source to clone).
	if (src_depth != SIZE_MAX)
	{
		size_t cid = display_list[src_depth].char_id;
		if (dictionary[cid].type == CHAR_TYPE_SPRITE)
		{
			frame_func* funcs = dictionary[cid].sprite_frame_funcs;
			size_t frame_count = dictionary[cid].sprite_frame_count;
			if (funcs != NULL && frame_count > 0 && funcs[0] != NULL)
			{
				DisplayObject* saved_dl  = display_list;
				size_t         saved_max = max_depth;
				size_t         saved_cap = display_list_capacity;
				MovieClip*     saved_ctx = NULL;
				DisplayObject* saved_sprite_obj = g_current_sprite_obj;
				int            saved_catch_up = catch_up_mode;

				// Create display_obj for clone to hold its children
				if (clone_mc->display_obj == NULL) {
					DisplayObject* dobj = calloc(1, sizeof(DisplayObject));
					dobj->char_id = cid;
					dobj->sprite_dl_capacity = 64;
					dobj->sprite_display_list = calloc(dobj->sprite_dl_capacity, sizeof(DisplayObject));
					dobj->sprite_max_depth = 0;
					clone_mc->display_obj = dobj;
				}

				DisplayObject* dobj = (DisplayObject*)clone_mc->display_obj;
				display_list = dobj->sprite_display_list;
				max_depth = dobj->sprite_max_depth;
				display_list_capacity = dobj->sprite_dl_capacity;

				saved_ctx = g_current_context;
				actionSetCurrentContext(clone_mc);
				g_current_sprite_obj = NULL;

				catch_up_mode = 1;
				funcs[0](app_context);
				catch_up_mode = saved_catch_up;

				actionSetCurrentContext(saved_ctx);
				g_current_sprite_obj = saved_sprite_obj;

				dobj->sprite_display_list = display_list;
				dobj->sprite_max_depth = max_depth;
				dobj->sprite_dl_capacity = display_list_capacity;

				display_list = saved_dl;
				max_depth = saved_max;
				display_list_capacity = saved_cap;
			}

			// Clear source MC's display_obj so new TextSnapshot(source) returns empty
			if (src_mc != NULL) {
				src_mc->display_obj = NULL;
			}
		}
	}

	return clone_mc;
}

MovieClip* ng_cloneSpriteFromMC(SWFAppContext* app_context, MovieClip* src_mc,
                                  const char* target_name, int depth)
{
	if (!src_mc || !target_name) return NULL;
	if (src_mc->parent == NULL) return NULL;  // cannot clone root

	MovieClip* clone_mc = actionFindOrCreateMovieClip(app_context, target_name, &root_movieclip);
	if (clone_mc == NULL) return NULL;

	clone_mc->x       = src_mc->x;
	clone_mc->y       = src_mc->y;
	clone_mc->xscale  = src_mc->xscale;
	clone_mc->yscale  = src_mc->yscale;
	clone_mc->rotation = src_mc->rotation;
	clone_mc->alpha   = src_mc->alpha;
	clone_mc->visible = src_mc->visible;
	clone_mc->totalframes   = src_mc->totalframes;
	clone_mc->framesloaded  = src_mc->framesloaded;
	clone_mc->as_set_flags  = src_mc->as_set_flags;
	clone_mc->currentframe = 1;
	clone_mc->depth = depth;

	// CloneSprite fires onLoad for the clone — look up source's clip_actions by name
	if (src_mc->name && g_pending_load_count < MAX_PENDING_LOADS)
	{
		size_t src_depth = ng_findDisplayEntryByName(src_mc->name);
		if (src_depth != SIZE_MAX && display_list[src_depth].clip_action_count > 0)
		{
			PendingLoad* pl = &g_pending_loads[g_pending_load_count++];
			strncpy(pl->instance_name, target_name, sizeof(pl->instance_name) - 1);
			pl->instance_name[sizeof(pl->instance_name) - 1] = '\0';
			pl->clip_actions = display_list[src_depth].clip_actions;
			pl->clip_action_count = display_list[src_depth].clip_action_count;
		}
	}

	// Evict any old clone at this SWF depth (from duplicateMovieClip, depth+16384 convention).
	// ng_cloneSpriteFromMC is called from the duplicateMovieClip fallback path only.
	clone_depth_register(depth + 16384, target_name);

	ActionVar _clone_mc_var = {0};
	_clone_mc_var.type = ACTION_STACK_VALUE_MOVIECLIP;
	_clone_mc_var.data.numeric_value = (u64)clone_mc;
	setVariableByName(target_name, &_clone_mc_var);

	return clone_mc;
}

MovieClip* ng_duplicateMovieClip(SWFAppContext* app_context, const char* source_name,
                                  const char* target_name, int as_depth)
{
	if (!source_name || !target_name) return NULL;

	int swf_depth = as_depth + 16384;

	size_t src_depth = ng_findDisplayEntryByName(source_name);
	if (src_depth != SIZE_MAX)
	{
		size_t cid = display_list[src_depth].char_id;
		int scriptable = (dictionary[cid].type == CHAR_TYPE_SPRITE) ||
		                 ng_find_button(cid) || (ng_find_textfield(cid) >= 0) ||
		                 ng_find_video(cid);
		if (!scriptable) return NULL;
		// Note: duplicateMovieClip does NOT fire onLoad for the clone (unlike CloneSprite).
	}

	MovieClip* src_mc = actionFindOrCreateMovieClip(app_context, source_name, &root_movieclip);
	MovieClip* clone_mc = actionFindOrCreateMovieClip(app_context, target_name, &root_movieclip);
	if (clone_mc == NULL) return NULL;

	if (src_mc != NULL)
	{
		clone_mc->x       = src_mc->x;
		clone_mc->y       = src_mc->y;
		clone_mc->xscale  = src_mc->xscale;
		clone_mc->yscale  = src_mc->yscale;
		clone_mc->rotation = src_mc->rotation;
		clone_mc->alpha   = src_mc->alpha;
		clone_mc->visible = src_mc->visible;
		clone_mc->totalframes   = src_mc->totalframes;
		clone_mc->framesloaded  = src_mc->framesloaded;
		clone_mc->as_set_flags  = src_mc->as_set_flags;
	}
	clone_mc->currentframe = 1;
	clone_mc->depth = as_depth;

	// Evict any old clone at this SWF depth, then register this one
	clone_depth_register(swf_depth, target_name);

	// Register as global variable so GetVariable(target_name) finds the clone
	ActionVar _dup_mc_var = {0};
	_dup_mc_var.type = ACTION_STACK_VALUE_MOVIECLIP;
	_dup_mc_var.data.numeric_value = (u64)clone_mc;
	setVariableByName(target_name, &_dup_mc_var);

	// If source is a sprite, run frame 0 to populate clone's sprite_display_list
	// (so children like text objects are available for TextSnapshot etc.)
	if (src_depth != SIZE_MAX)
	{
		extern size_t display_list_capacity;
		size_t cid = display_list[src_depth].char_id;
		if (dictionary[cid].type == CHAR_TYPE_SPRITE)
		{
			frame_func* funcs = dictionary[cid].sprite_frame_funcs;
			size_t frame_count = dictionary[cid].sprite_frame_count;
			if (funcs != NULL && frame_count > 0 && funcs[0] != NULL)
			{
				DisplayObject* saved_dl  = display_list;
				size_t         saved_max = max_depth;
				size_t         saved_cap = display_list_capacity;
				MovieClip*     saved_ctx = NULL;
				DisplayObject* saved_sprite_obj = g_current_sprite_obj;
				int            saved_catch_up = catch_up_mode;

				if (clone_mc->display_obj == NULL) {
					DisplayObject* dobj = calloc(1, sizeof(DisplayObject));
					dobj->char_id = cid;
					dobj->sprite_dl_capacity = 64;
					dobj->sprite_display_list = calloc(dobj->sprite_dl_capacity, sizeof(DisplayObject));
					dobj->sprite_max_depth = 0;
					clone_mc->display_obj = dobj;
				}

				DisplayObject* dobj = (DisplayObject*)clone_mc->display_obj;
				display_list = dobj->sprite_display_list;
				max_depth = dobj->sprite_max_depth;
				display_list_capacity = dobj->sprite_dl_capacity;

				saved_ctx = g_current_context;
				actionSetCurrentContext(clone_mc);
				g_current_sprite_obj = NULL;

				catch_up_mode = 1;
				funcs[0](app_context);
				catch_up_mode = saved_catch_up;

				actionSetCurrentContext(saved_ctx);
				g_current_sprite_obj = saved_sprite_obj;

				dobj->sprite_display_list = display_list;
				dobj->sprite_max_depth = max_depth;
				dobj->sprite_dl_capacity = display_list_capacity;

				display_list = saved_dl;
				max_depth = saved_max;
				display_list_capacity = saved_cap;
			}
		}
	}

	return clone_mc;
}

// ---------------------------------------------------------------------------
// No-op stubs for functions not needed in NO_GRAPHICS mode
// ---------------------------------------------------------------------------

void defineBitmap(size_t offset, size_t size, u32 width, u32 height)
{
	(void)offset; (void)size; (void)width; (void)height;
}

void finalizeBitmaps(void)
{
}

void tagDefineSound(SWFAppContext* app_context, u16 sound_id,
	u8 format, u8 rate, u8 sample_size, u8 stereo,
	u32 sample_count, const u8* data, size_t data_size)
{
	(void)app_context; (void)format; (void)sample_size; (void)stereo;
	(void)data; (void)data_size;
	// Store metadata for attachSound/getDuration
	if (g_sound_metadata_count < MAX_SOUND_METADATA) {
		g_sound_metadata[g_sound_metadata_count].char_id = sound_id;
		g_sound_metadata[g_sound_metadata_count].rate = rate;
		g_sound_metadata[g_sound_metadata_count].sample_count = sample_count;
		g_sound_metadata_count++;
	}
}

void tagStartSound(SWFAppContext* app_context, u16 sound_id,
	int stop, u32 loop_count, u32 in_point, u32 out_point)
{
	(void)app_context; (void)sound_id; (void)stop; (void)loop_count;
	(void)in_point; (void)out_point;
}

void tagSoundStreamHead(SWFAppContext* app_context,
	u8 format, u8 rate, u8 sample_size, u8 stereo,
	u16 avg_sample_count)
{
	(void)app_context; (void)format; (void)rate; (void)sample_size;
	(void)stereo; (void)avg_sample_count;
}

void tagSoundStreamBlock(SWFAppContext* app_context,
	const u8* data, size_t data_size)
{
	(void)app_context; (void)data; (void)data_size;
}

void tagStopAllSounds(SWFAppContext* app_context)
{
	(void)app_context;
}

void tagScriptLimits(u16 max_recursion, u16 timeout)
{
	(void)timeout;
	g_max_call_depth = max_recursion;
}

#endif // NO_GRAPHICS
