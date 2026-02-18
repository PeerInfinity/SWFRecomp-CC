#ifdef NO_GRAPHICS

#include <tag.h>
#include <swf.h>
#include <common.h>
#include <action.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

// Simple sprite registry for NO_GRAPHICS mode
// Allows sprite frame scripts (e.g. DoAction inside DefineSprite) to execute
#define MAX_SPRITES_NG 64
static struct {
	size_t char_id;
	frame_func* funcs;
	size_t frame_count;
} ng_sprites[MAX_SPRITES_NG];
static size_t ng_sprite_count = 0;

// Character bounds table for NO_GRAPHICS mode (stores shape bounds in twips)
#define MAX_CHAR_BOUNDS_NG 256
static struct {
	size_t char_id;
	s32 xmin, xmax, ymin, ymax;  // twips
} ng_char_bounds[MAX_CHAR_BOUNDS_NG];
static size_t ng_char_bounds_count = 0;

// Simple display list for NO_GRAPHICS mode
#define MAX_DISPLAY_NG 64
static struct {
	size_t depth;
	size_t char_id;        // character ID placed at this depth
	size_t sprite_idx;     // index into ng_sprites, or (size_t)-1 for non-sprite
	size_t current_frame;
	int is_playing;
	int needs_init;        // 1 if sprite frame 0 hasn't been executed yet
	size_t placed_at_frame; // which main timeline frame placed this entry
	u32 transform_id;     // index into transform_data for _x/_y
	int is_button;        // 1 if this is a button (for typeof discrimination)
	int is_textfield;     // 1 if this is a DefineEditText (for TextField properties)
	int textfield_idx;    // index into ng_textfields, or -1
	char instance_name[64]; // instance name set by tagSetInstanceName
	size_t parent_display_idx; // index of parent sprite in ng_display, or (size_t)-1 for root
	ClipAction* clip_actions;   // pointer to clip_actions array (from tagMain.c), or NULL
	size_t clip_action_count;   // number of clip actions
} ng_display[MAX_DISPLAY_NG];
static size_t ng_display_count = 0;
static int ng_nesting_depth = 0;  // >0 when inside sprite frame execution
static size_t ng_current_display_idx = (size_t)-1;  // display index of currently executing sprite
static unsigned int ng_auto_instance_counter = 1;  // global auto-name counter ("instance1", "instance2", ...)

// Simple button registry for NO_GRAPHICS mode (for typeof discrimination)
#define MAX_BUTTONS_NG 64
static size_t ng_button_ids[MAX_BUTTONS_NG];
static size_t ng_button_count = 0;

static int ng_find_button(size_t char_id)
{
	for (size_t i = 0; i < ng_button_count; i++)
		if (ng_button_ids[i] == char_id)
			return 1;
	return 0;
}

// Video stream char_id registry for NO_GRAPHICS mode (scriptable like sprites)
#define MAX_VIDEOS_NG 32
static size_t ng_video_ids[MAX_VIDEOS_NG];
static size_t ng_video_count = 0;

static int ng_find_video(size_t char_id)
{
	for (size_t i = 0; i < ng_video_count; i++)
		if (ng_video_ids[i] == char_id)
			return 1;
	return 0;
}

// Font info registry for NO_GRAPHICS mode (font name, bold, italic)
#define MAX_FONTS_NG 32
static struct {
	u16 font_id;
	char name[128];
	int bold;
	int italic;
} ng_fonts[MAX_FONTS_NG];
static size_t ng_font_count = 0;

// Simple textfield registry for NO_GRAPHICS mode
#define MAX_TEXTFIELDS_NG 64
static struct {
	size_t char_id;
	char plain_text[1024];     // plain text (HTML tags stripped)
	char raw_html_text[1024];  // raw initial text (may contain HTML)
	u32 text_color;            // 0xRRGGBB
	u16 font_id;
	u16 font_height;           // in twips
	s16 max_length;            // -1 = unlimited
	u8 align;                  // 0=left,1=right,2=center,3=justify
	u16 left_margin;           // twips
	u16 right_margin;          // twips
	u16 indent;                // twips
	s16 leading;               // twips
	char variable_name[256];
	u16 flags;                 // packed: WordWrap|Multiline|Password|ReadOnly|NoSelect|Border|HTML|UseOutlines|AutoSize
	s32 bounds_xmin;           // twips
	s32 bounds_xmax;           // twips
	s32 bounds_ymin;           // twips
	s32 bounds_ymax;           // twips
	// CSMTextSettings data (from tag 74, applied after DefineEditText)
	char csm_antiAliasType[16]; // "normal" or "advanced"
	char csm_gridFitType[16];   // "none", "pixel", or "subpixel"
	float csm_thickness;        // default 0
	float csm_sharpness;        // default 0
	int csm_applied;            // 1 if CSMTextSettings was applied
} ng_textfields[MAX_TEXTFIELDS_NG];
static size_t ng_textfield_count = 0;

static int ng_find_textfield(size_t char_id)
{
	for (size_t i = 0; i < ng_textfield_count; i++)
		if (ng_textfields[i].char_id == char_id)
			return (int)i;
	return -1;
}

static size_t ng_find_sprite(size_t char_id)
{
	for (size_t i = 0; i < ng_sprite_count; i++)
		if (ng_sprites[i].char_id == char_id)
			return i;
	return (size_t)-1;
}

// Clear NO_GRAPHICS display entries placed after the target frame.
// For backward gotos: removes characters added after the target.
// For forward gotos: typically a no-op (target > current entries).
void ng_display_clear_after(size_t target_frame)
{
	size_t i = 0;
	while (i < ng_display_count)
	{
		if (ng_display[i].placed_at_frame > target_frame)
		{
			// Remove by shifting
			for (size_t j = i; j + 1 < ng_display_count; j++)
				ng_display[j] = ng_display[j + 1];
			ng_display_count--;
		}
		else
		{
			i++;
		}
	}
}

// Access the generated transform_data from draws.c (linked per-test)
// Actual type is float[][16] but we access via pointer arithmetic
extern float transform_data[][16];

// Stub implementations for console-only mode
// Note: tagInit() is provided by the generated tagMain.c file

void tagSetBackgroundColor(u8 red, u8 green, u8 blue)
{
	(void)red; (void)green; (void)blue;
}

// Helper to execute a sprite frame function with proper context
static void ng_exec_sprite_frame(SWFAppContext* app_context, size_t display_idx, size_t frame)
{
	size_t si = ng_display[display_idx].sprite_idx;
	if (si == (size_t)-1) return;
	if (!ng_sprites[si].funcs || !ng_sprites[si].funcs[frame]) return;

	const char* inst_name = ng_display[display_idx].instance_name[0] ? ng_display[display_idx].instance_name : NULL;
	char mc_name[32];
	if (!inst_name)
	{
		snprintf(mc_name, sizeof(mc_name), "__depth_%zu", ng_display[display_idx].depth);
		inst_name = mc_name;
	}
	MovieClip* saved_ctx = g_current_context;
	MovieClip* sprite_mc = actionFindOrCreateMovieClip(app_context, inst_name, &root_movieclip);
	actionSetCurrentContext(sprite_mc);
	size_t saved_display_idx = ng_current_display_idx;
	ng_current_display_idx = display_idx;
	ng_nesting_depth++;
	ng_sprites[si].funcs[frame](app_context);
	ng_nesting_depth--;
	ng_current_display_idx = saved_display_idx;
	actionSetCurrentContext(saved_ctx);
}

// Helpers for action.c to control the currently executing sprite
int ng_isInsideSprite(void) { return ng_nesting_depth > 0; }

int ng_hasPlayingSprites(void)
{
	for (size_t i = 0; i < ng_display_count; i++)
	{
		size_t si = ng_display[i].sprite_idx;
		if (si == (size_t)-1) continue;
		if (!ng_display[i].is_playing) continue;
		if (ng_sprites[si].frame_count <= 1) continue;
		return 1;
	}
	return 0;
}

void ng_stopCurrentSprite(void)
{
	if (ng_current_display_idx < ng_display_count)
		ng_display[ng_current_display_idx].is_playing = 0;
}

void ng_playCurrentSprite(void)
{
	if (ng_current_display_idx < ng_display_count)
		ng_display[ng_current_display_idx].is_playing = 1;
}

void ng_gotoFrameCurrentSprite(u16 frame)
{
	if (ng_current_display_idx >= ng_display_count) return;
	size_t si = ng_display[ng_current_display_idx].sprite_idx;
	if (si == (size_t)-1) return;
	if (frame < ng_sprites[si].frame_count)
	{
		ng_display[ng_current_display_idx].current_frame = frame;
		ng_display[ng_current_display_idx].is_playing = 0;
	}
}

size_t ng_getSpriteFrameCount(void)
{
	if (ng_current_display_idx >= ng_display_count) return 0;
	size_t si = ng_display[ng_current_display_idx].sprite_idx;
	if (si == (size_t)-1) return 0;
	return ng_sprites[si].frame_count;
}

// Advance existing sprite timelines — called from main loop AFTER frame function
// so that child scripts execute before the next parent frame (matching Flash behavior).
// Also runs before quit_swf is checked, so single-frame movies still advance sprites.
// Flash advances sprites in reverse depth order (highest depth first).
void ng_advanceSprites(SWFAppContext* app_context)
{
	extern int catch_up_mode;
	if (catch_up_mode) return;

	// Advance in reverse depth order (highest depth first)
	// Find max depth first, then iterate downward
	size_t max_depth = 0;
	for (size_t i = 0; i < ng_display_count; i++)
		if (ng_display[i].depth > max_depth) max_depth = ng_display[i].depth;

	for (size_t d = max_depth; d >= 1; d--)
	{
		for (size_t i = 0; i < ng_display_count; i++)
		{
			if (ng_display[i].depth != d) continue;
			// Skip sprites waiting for init (tagShowFrame will handle them later this tick)
			if (ng_display[i].needs_init) continue;
			size_t si = ng_display[i].sprite_idx;
			if (si == (size_t)-1) continue;
			if (!ng_display[i].is_playing) continue;

			size_t fc = ng_sprites[si].frame_count;
			if (fc <= 1) continue;

			size_t next = (ng_display[i].current_frame + 1) % fc;
			ng_display[i].current_frame = next;
			ng_exec_sprite_frame(app_context, i, next);
		}
	}
}

void tagShowFrame(SWFAppContext* app_context)
{
	extern int catch_up_mode;

	// Execute deferred frame 0 for newly placed sprites.
	// Run even during catch-up so sprite init scripts execute at the correct
	// frame (matching Flash's execution order where newly-placed sprites' frame_0
	// scripts run before the parent frame's DoAction).
	// Temporarily clear catch_up_mode so the sprite frame functions' !catch_up_mode
	// guards allow scripts to run. (The initial bounds-populating run in
	// tagPlaceObject2 already used a forced catch_up_mode=1, so scripts were
	// suppressed there; this is the intended script-executing pass.)
	int saved_catch_up = catch_up_mode;
	catch_up_mode = 0;
	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (!ng_display[i].needs_init) continue;
		ng_display[i].needs_init = 0;
		ng_exec_sprite_frame(app_context, i, 0);
		// Fire onLoad clip actions for newly initialized sprites
		if (ng_display[i].clip_actions && ng_display[i].clip_action_count > 0) {
			const char* inst_name = ng_display[i].instance_name[0] ? ng_display[i].instance_name : NULL;
			if (inst_name) {
				for (size_t j = 0; j < ng_display[i].clip_action_count; j++) {
					if (ng_display[i].clip_actions[j].event_flags & 0x1) { // CLIP_EVENT_LOAD
						MovieClip* saved_ctx = g_current_context;
						MovieClip* clip_mc = actionFindOrCreateMovieClip(app_context, inst_name, &root_movieclip);
						actionSetCurrentContext(clip_mc);
						ng_display[i].clip_actions[j].action(app_context);
						actionSetCurrentContext(saved_ctx);
					}
				}
			}
		}
	}
	catch_up_mode = saved_catch_up;
}

// No-op stubs for all tag functions so trace tests that happen to
// define shapes, sprites, buttons, sounds, etc. still compile and link.

void tagDefineShape(SWFAppContext* app_context, CharacterType type, size_t char_id, size_t shape_offset, size_t shape_size,
    s32 bounds_xmin, s32 bounds_xmax, s32 bounds_ymin, s32 bounds_ymax)
{
	(void)app_context; (void)type; (void)shape_offset; (void)shape_size;
	if (ng_char_bounds_count >= MAX_CHAR_BOUNDS_NG) return;
	size_t i = ng_char_bounds_count;
	ng_char_bounds[i].char_id = char_id;
	ng_char_bounds[i].xmin = bounds_xmin;
	ng_char_bounds[i].xmax = bounds_xmax;
	ng_char_bounds[i].ymin = bounds_ymin;
	ng_char_bounds[i].ymax = bounds_ymax;
	ng_char_bounds_count++;
}

void tagDefineMorphShape(SWFAppContext* app_context, size_t char_id,
	size_t shape_offset, size_t shape_size,
	size_t morph_end_offset, size_t morph_color_start, size_t morph_color_count)
{
	(void)app_context; (void)char_id; (void)shape_offset; (void)shape_size;
	(void)morph_end_offset; (void)morph_color_start; (void)morph_color_count;
}

void tagDefineText(SWFAppContext* app_context, size_t char_id, size_t text_start, size_t text_size, u32 transform_start, u32 cxform_id)
{
	(void)app_context; (void)char_id; (void)text_start; (void)text_size;
	(void)transform_start; (void)cxform_id;
}

void tagDefineFontInfo(SWFAppContext* app_context, u16 font_id, const char* name, int bold, int italic)
{
	(void)app_context;
	if (ng_font_count >= MAX_FONTS_NG) return;
	size_t i = ng_font_count;
	ng_fonts[i].font_id = font_id;
	strncpy(ng_fonts[i].name, name ? name : "", sizeof(ng_fonts[i].name) - 1);
	ng_fonts[i].name[sizeof(ng_fonts[i].name) - 1] = '\0';
	ng_fonts[i].bold = bold;
	ng_fonts[i].italic = italic;
	ng_font_count++;
}

void tagDefineVideoStream(SWFAppContext* app_context, u16 char_id)
{
	(void)app_context;
	if (ng_video_count < MAX_VIDEOS_NG)
		ng_video_ids[ng_video_count++] = (size_t)char_id;
}

void tagDefineEditTextProps(SWFAppContext* app_context, size_t char_id,
    const char* plain_text, const char* raw_html_text, u32 text_color,
    u16 font_id, u16 font_height, s16 max_length,
    u8 align, u16 left_margin, u16 right_margin, u16 indent, s16 leading,
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
	ng_textfield_count++;
}

void tagCSMTextSettings(size_t text_id, const char* anti_alias_type, const char* grid_fit_type, float thickness, float sharpness)
{
	// Find the textfield with the given char_id and apply CSMTextSettings
	int idx = ng_find_textfield(text_id);
	if (idx >= 0) {
		strncpy(ng_textfields[idx].csm_antiAliasType, anti_alias_type, sizeof(ng_textfields[idx].csm_antiAliasType) - 1);
		ng_textfields[idx].csm_antiAliasType[sizeof(ng_textfields[idx].csm_antiAliasType) - 1] = '\0';
		strncpy(ng_textfields[idx].csm_gridFitType, grid_fit_type, sizeof(ng_textfields[idx].csm_gridFitType) - 1);
		ng_textfields[idx].csm_gridFitType[sizeof(ng_textfields[idx].csm_gridFitType) - 1] = '\0';
		ng_textfields[idx].csm_thickness = thickness;
		ng_textfields[idx].csm_sharpness = sharpness;
		ng_textfields[idx].csm_applied = 1;
	}
}

void tagPlaceObject2(SWFAppContext* app_context, size_t depth, size_t char_id, u32 transform_id, u32 cxform_id, u16 clip_depth)
{
	(void)cxform_id; (void)clip_depth;
	extern size_t current_frame;

	// Note: we do NOT skip placements inside sprite frame functions.
	// Nested sprites/shapes get registered in the flat display list, which
	// allows them to be found by name (e.g., tellTarget, slash syntax paths).
	// This matches pre-refactor behavior where nested children were accessible.

	if (char_id == 0)
	{
		// Move/update existing entry at this depth (update transform)
		for (size_t i = 0; i < ng_display_count; i++)
		{
			if (ng_display[i].depth == depth)
			{
				ng_display[i].transform_id = transform_id;
				return;
			}
		}
		return;
	}

	// Placing a new character (char_id > 0)
	size_t si = ng_find_sprite(char_id);
	int btn = ng_find_button(char_id);
	int tf_idx = ng_find_textfield(char_id);
	int is_tf = (tf_idx >= 0) ? 1 : 0;

	// Check if depth already occupied (within the same parent scope)
	size_t expected_parent = ng_nesting_depth > 0 ? ng_current_display_idx : (size_t)-1;
	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (ng_display[i].depth == depth && ng_display[i].parent_display_idx == expected_parent)
		{
			if (si == (size_t)-1)
			{
				// Non-sprite at occupied depth: don't replace sprites
				// (prevents corruption during backward goto catch-up)
				if (ng_display[i].sprite_idx != (size_t)-1) return;
				// Replace other non-sprites (update placed_at_frame)
				ng_display[i].char_id = char_id;
				ng_display[i].placed_at_frame = current_frame;
				ng_display[i].transform_id = transform_id;
				ng_display[i].is_button = btn;
				ng_display[i].is_textfield = is_tf;
				ng_display[i].textfield_idx = tf_idx;
				ng_display[i].parent_display_idx = ng_nesting_depth > 0 ? ng_current_display_idx : (size_t)-1;
				ng_display[i].clip_actions = NULL;
				ng_display[i].clip_action_count = 0;
				goto placed;
			}
			if (ng_display[i].sprite_idx == si)
			{
				// Same sprite already at this depth - don't re-execute
				return;
			}
			// Different sprite (or replacing non-sprite) - replace
			ng_display[i].char_id = char_id;
			ng_display[i].sprite_idx = si;
			ng_display[i].current_frame = 0;
			ng_display[i].is_playing = 1;
			ng_display[i].needs_init = (si != (size_t)-1) ? 1 : 0;
			ng_display[i].placed_at_frame = current_frame;
			ng_display[i].transform_id = transform_id;
			ng_display[i].is_button = btn;
			ng_display[i].is_textfield = is_tf;
			ng_display[i].textfield_idx = tf_idx;
			ng_display[i].parent_display_idx = ng_nesting_depth > 0 ? ng_current_display_idx : (size_t)-1;
			ng_display[i].clip_actions = NULL;
			ng_display[i].clip_action_count = 0;
			goto placed;
		}
	}

	// New entry
	if (ng_display_count < MAX_DISPLAY_NG)
	{
		ng_display[ng_display_count].depth = depth;
		ng_display[ng_display_count].char_id = char_id;
		ng_display[ng_display_count].sprite_idx = si;
		ng_display[ng_display_count].current_frame = 0;
		ng_display[ng_display_count].is_playing = 1;
		ng_display[ng_display_count].needs_init = (si != (size_t)-1) ? 1 : 0;
		ng_display[ng_display_count].placed_at_frame = current_frame;
		ng_display[ng_display_count].transform_id = transform_id;
		ng_display[ng_display_count].is_button = btn;
		ng_display[ng_display_count].is_textfield = is_tf;
		ng_display[ng_display_count].textfield_idx = tf_idx;
		ng_display[ng_display_count].parent_display_idx = ng_nesting_depth > 0 ? ng_current_display_idx : (size_t)-1;
		ng_display[ng_display_count].instance_name[0] = '\0';
		ng_display[ng_display_count].clip_actions = NULL;
		ng_display[ng_display_count].clip_action_count = 0;
		ng_display_count++;
	}

placed:
	// Auto-assign instance name ("instance1", "instance2", ...) for sprites, textfields, and buttons
	// that were placed without an explicit name (mirrors Flash Player behavior).
	if (si != (size_t)-1 || is_tf || btn) {
		// Find the placed entry and give it an auto-name if still unnamed
		size_t expected_parent2 = ng_nesting_depth > 0 ? ng_current_display_idx : (size_t)-1;
		for (size_t _ai = 0; _ai < ng_display_count; _ai++) {
			if (ng_display[_ai].depth == depth && ng_display[_ai].parent_display_idx == expected_parent2) {
				if (ng_display[_ai].instance_name[0] == '\0') {
					snprintf(ng_display[_ai].instance_name, sizeof(ng_display[_ai].instance_name),
					         "instance%u", ng_auto_instance_counter++);
				}
				break;
			}
		}
	}
	// Initialize textfield variable binding at placement time
	if (is_tf && tf_idx >= 0) {
		const char* var_name = ng_textfields[tf_idx].variable_name;
		const char* init_text = ng_textfields[tf_idx].plain_text;
		if (var_name[0] != '\0') {
			actionInitTextFieldVariable(app_context, var_name, init_text);
		}
	}
	// Run sprite frame_0 in "placement-only" mode (catch_up_mode=1) to populate
	// the sprite's display list immediately. This allows parent-frame scripts to
	// read _width/_height/_rotation etc. from the sprite's content bounds.
	// The DoAction (script) calls in the sprite frame are guarded by !catch_up_mode
	// and will be skipped during this pass. They execute at tagShowFrame time
	// (via the needs_init=1 path) after all parent-frame scripts have run.
	if (si != (size_t)-1) {
		extern int catch_up_mode;
		int saved_catch_up = catch_up_mode;
		catch_up_mode = 1;  // suppress scripts in sprite frame

		size_t expected_parent3 = ng_nesting_depth > 0 ? ng_current_display_idx : (size_t)-1;
		for (size_t _ii = 0; _ii < ng_display_count; _ii++) {
			if (ng_display[_ii].depth == depth &&
			    ng_display[_ii].parent_display_idx == expected_parent3 &&
			    ng_display[_ii].needs_init)
			{
				ng_exec_sprite_frame(app_context, _ii, 0);
				break;
			}
		}

		catch_up_mode = saved_catch_up;
		// needs_init stays 1 so tagShowFrame will run the full frame (with scripts)
	}
}

void tagPlaceObject2Ratio(SWFAppContext* app_context, size_t depth, size_t char_id,
	u32 transform_id, u32 cxform_id, u16 clip_depth, u16 ratio)
{
	(void)ratio;
	// Delegate to tagPlaceObject2 for sprite execution
	tagPlaceObject2(app_context, depth, char_id, transform_id, cxform_id, clip_depth);
}

void tagPlaceObject2WithClipActions(SWFAppContext* app_context, size_t depth, size_t char_id,
	u32 transform_id, u32 cxform_id, u16 clip_depth, ClipAction* clip_actions, size_t clip_action_count)
{
	tagPlaceObject2(app_context, depth, char_id, transform_id, cxform_id, clip_depth);
	// Store clip actions on the placed entry
	size_t _ca_expected_parent = ng_nesting_depth > 0 ? ng_current_display_idx : (size_t)-1;
	for (size_t i = 0; i < ng_display_count; i++) {
		if (ng_display[i].depth == depth && ng_display[i].parent_display_idx == _ca_expected_parent) {
			ng_display[i].clip_actions = clip_actions;
			ng_display[i].clip_action_count = clip_action_count;
			break;
		}
	}
}

void tagPlaceObject3(SWFAppContext* app_context, size_t depth, size_t char_id,
	u32 transform_id, u32 cxform_id, u16 clip_depth, u8 blend_mode)
{
	(void)app_context; (void)depth; (void)char_id; (void)transform_id;
	(void)cxform_id; (void)clip_depth; (void)blend_mode;
}

void tagSetFilter(SWFAppContext* app_context, size_t depth,
	u8 type, float blur_x, float blur_y, u8 quality, u8 flags,
	float r, float g, float b, float a, float strength,
	float angle, float distance)
{
	(void)app_context; (void)depth; (void)type; (void)blur_x; (void)blur_y;
	(void)quality; (void)flags; (void)r; (void)g; (void)b; (void)a;
	(void)strength; (void)angle; (void)distance;
}

void tagSetFilterHighlight(SWFAppContext* app_context, size_t depth,
	float r, float g, float b, float a)
{
	(void)app_context; (void)depth; (void)r; (void)g; (void)b; (void)a;
}

void tagSetInstanceName(SWFAppContext* app_context, size_t depth, const char* name)
{
	// Store instance name on the display entry at this depth (within current parent scope).
	// Also rename the cached MovieClip if one was already created (eager sprite init may
	// have created it under an auto-assigned name before tagSetInstanceName was called).
	size_t expected_parent = ng_nesting_depth > 0 ? ng_current_display_idx : (size_t)-1;
	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (ng_display[i].depth == depth && ng_display[i].parent_display_idx == expected_parent)
		{
			char old_name[64];
			strncpy(old_name, ng_display[i].instance_name, sizeof(old_name) - 1);
			old_name[sizeof(old_name) - 1] = '\0';
			strncpy(ng_display[i].instance_name, name, 63);
			ng_display[i].instance_name[63] = '\0';
			// Rename cached MC if it exists under the old name
			if (old_name[0] != '\0' && strcmp(old_name, name) != 0)
				actionRenameMovieClip(old_name, name);
			return;
		}
	}
}

// Enumerate child instance names for a MovieClip.
// Finds the parent's display index, then iterates children whose parent_display_idx matches.
// For _root (parent_name is NULL or empty), finds entries with parent_display_idx == (size_t)-1.
void ng_enumerateChildren(const char* parent_name, void (*callback)(const char* name, u32 name_len, void* user_data), void* user_data)
{
	size_t parent_idx = (size_t)-1;
	if (parent_name != NULL && parent_name[0] != '\0')
	{
		// Find the parent display entry
		for (size_t i = 0; i < ng_display_count; i++)
		{
			if (ng_display[i].instance_name[0] != '\0' &&
			    strcmp(ng_display[i].instance_name, parent_name) == 0)
			{
				parent_idx = i;
				break;
			}
		}
		if (parent_idx == (size_t)-1)
			return; // Parent not found
	}

	// Iterate children in forward order (pushed in forward = popped in reverse)
	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (ng_display[i].parent_display_idx == parent_idx &&
		    ng_display[i].instance_name[0] != '\0')
		{
			callback(ng_display[i].instance_name, (u32)strlen(ng_display[i].instance_name), user_data);
		}
	}
}

// Check if the display entry at a given depth is a sprite (movieclip)
// Only matches root-level entries (called from action.c for root display object resolution)
int ng_isSpriteAtDepth(size_t depth)
{
	for (size_t i = 0; i < ng_display_count; i++)
		if (ng_display[i].depth == depth && ng_display[i].parent_display_idx == (size_t)-1)
			return ng_display[i].sprite_idx != (size_t)-1;
	return 0;
}

// Check if the display entry at a given depth is a button
int ng_isButtonAtDepth(size_t depth)
{
	for (size_t i = 0; i < ng_display_count; i++)
		if (ng_display[i].depth == depth && ng_display[i].parent_display_idx == (size_t)-1)
			return ng_display[i].is_button;
	return 0;
}

int ng_isTextFieldAtDepth(size_t depth)
{
	for (size_t i = 0; i < ng_display_count; i++)
		if (ng_display[i].depth == depth && ng_display[i].parent_display_idx == (size_t)-1)
			return ng_display[i].is_textfield;
	return 0;
}

int ng_isScriptableAtDepth(size_t depth)
{
	for (size_t i = 0; i < ng_display_count; i++) {
		if (ng_display[i].depth == depth && ng_display[i].parent_display_idx == (size_t)-1) {
			return ng_display[i].is_button ||
			       ng_display[i].is_textfield ||
			       (ng_display[i].sprite_idx != (size_t)-1) ||
			       ng_find_video(ng_display[i].char_id);
		}
	}
	return 0;
}

// Clone a tag-placed sprite: source_name -> target_name at depth.
// Only creates a MovieClip for scriptable sources (sprite/button/textfield).
// Returns clone MovieClip, or NULL if source not found/non-scriptable.
MovieClip* ng_cloneSprite(SWFAppContext* app_context, const char* source_name,
                           const char* target_name, int depth)
{
	if (!source_name || !target_name) return NULL;
	// Flash valid depth range for CloneSprite: max 2130706428
	if (depth > 2130706428) return NULL;

	// Find source in ng_display by instance name (root-level only)
	size_t src_idx = (size_t)-1;
	for (size_t i = 0; i < ng_display_count; i++) {
		if (ng_display[i].parent_display_idx == (size_t)-1 &&
		    ng_display[i].instance_name[0] != '\0' &&
		    strcmp(ng_display[i].instance_name, source_name) == 0) {
			src_idx = i;
			break;
		}
	}

	// If source found in ng_display, check if it's scriptable
	if (src_idx != (size_t)-1) {
		int scriptable = ng_display[src_idx].is_button ||
		                 ng_display[src_idx].is_textfield ||
		                 (ng_display[src_idx].sprite_idx != (size_t)-1);
		if (!scriptable) return NULL;  // Non-scriptable: clone is undefined

		// Remove existing entry at target depth
		for (size_t i = 0; i < ng_display_count; i++) {
			if (ng_display[i].depth == (size_t)depth && ng_display[i].parent_display_idx == (size_t)-1) {
				for (size_t j = i; j + 1 < ng_display_count; j++)
					ng_display[j] = ng_display[j + 1];
				ng_display_count--;
				if (src_idx > i) src_idx--;
				break;
			}
		}

		// Create new ng_display entry for clone
		if (ng_display_count < MAX_DISPLAY_NG) {
			size_t clone_idx = ng_display_count++;
			ng_display[clone_idx] = ng_display[src_idx];
			ng_display[clone_idx].depth = (size_t)depth;
			ng_display[clone_idx].parent_display_idx = (size_t)-1;
			strncpy(ng_display[clone_idx].instance_name, target_name, 63);
			ng_display[clone_idx].instance_name[63] = '\0';
			ng_display[clone_idx].current_frame = 0;
			ng_display[clone_idx].needs_init = (ng_display[src_idx].sprite_idx != (size_t)-1) ? 1 : 0;
			// clip_actions inherited from source
		}
	}

	// Find source MC (may have been created by prior GetVariable access)
	MovieClip* src_mc = actionFindOrCreateMovieClip(app_context, source_name, &root_movieclip);

	// Create clone MC
	MovieClip* clone_mc = actionFindOrCreateMovieClip(app_context, target_name, &root_movieclip);
	if (clone_mc == NULL) return NULL;

	// Copy transform properties from source
	if (src_mc != NULL) {
		clone_mc->x = src_mc->x;
		clone_mc->y = src_mc->y;
		clone_mc->xscale = src_mc->xscale;
		clone_mc->yscale = src_mc->yscale;
		clone_mc->rotation = src_mc->rotation;
		clone_mc->alpha = src_mc->alpha;
		clone_mc->visible = src_mc->visible;
		clone_mc->totalframes = src_mc->totalframes;
		clone_mc->framesloaded = src_mc->framesloaded;
		clone_mc->as_set_flags = src_mc->as_set_flags;
	}
	clone_mc->currentframe = 1;
	clone_mc->depth = depth;

	// Register as global variable so GetVariable finds the clone
	extern void setVariableByName(const char* name, ActionVar* var);
	ActionVar _clone_mc_var = {0};
	_clone_mc_var.type = ACTION_STACK_VALUE_MOVIECLIP;
	_clone_mc_var.data.numeric_value = (u64)clone_mc;
	setVariableByName(target_name, &_clone_mc_var);

	return clone_mc;
}

// Clone a script-created MovieClip (not in ng_display)
MovieClip* ng_cloneSpriteFromMC(SWFAppContext* app_context, MovieClip* src_mc,
                                  const char* target_name, int depth)
{
	if (!src_mc || !target_name) return NULL;
	// Cannot clone root MovieClip — source was a non-scriptable display object (shape, statictext, etc.)
	if (src_mc->parent == NULL) return NULL;

	MovieClip* clone_mc = actionFindOrCreateMovieClip(app_context, target_name, &root_movieclip);
	if (clone_mc == NULL) return NULL;

	clone_mc->x = src_mc->x;
	clone_mc->y = src_mc->y;
	clone_mc->xscale = src_mc->xscale;
	clone_mc->yscale = src_mc->yscale;
	clone_mc->rotation = src_mc->rotation;
	clone_mc->alpha = src_mc->alpha;
	clone_mc->visible = src_mc->visible;
	clone_mc->totalframes = src_mc->totalframes;
	clone_mc->framesloaded = src_mc->framesloaded;
	clone_mc->as_set_flags = src_mc->as_set_flags;
	clone_mc->currentframe = 1;
	clone_mc->depth = depth;

	extern void setVariableByName(const char* name, ActionVar* var);
	ActionVar _clone_mc_var = {0};
	_clone_mc_var.type = ACTION_STACK_VALUE_MOVIECLIP;
	_clone_mc_var.data.numeric_value = (u64)clone_mc;
	setVariableByName(target_name, &_clone_mc_var);

	return clone_mc;
}

// duplicateMovieClip clone: stored at SWF depth (as_depth + 16384) in ng_display.
// Does NOT register as a global variable (accessible via path resolution only).
// Does NOT copy clip_actions (duplicateMovieClip does not fire onLoad events).
MovieClip* ng_duplicateMovieClip(SWFAppContext* app_context, const char* source_name,
                                  const char* target_name, int as_depth)
{
	if (!source_name || !target_name) return NULL;

	// Map AS depth to internal SWF depth (Flash uses +16384 offset for script-created clips)
	int swf_depth = as_depth + 16384;

	// Find source in ng_display by instance name (root-level only)
	size_t src_idx = (size_t)-1;
	for (size_t i = 0; i < ng_display_count; i++) {
		if (ng_display[i].parent_display_idx == (size_t)-1 &&
		    ng_display[i].instance_name[0] != '\0' &&
		    strcmp(ng_display[i].instance_name, source_name) == 0) {
			src_idx = i;
			break;
		}
	}

	if (src_idx != (size_t)-1) {
		int scriptable = ng_display[src_idx].is_button ||
		                 ng_display[src_idx].is_textfield ||
		                 (ng_display[src_idx].sprite_idx != (size_t)-1);
		if (!scriptable) return NULL;

		// Remove existing entry at the target SWF depth
		for (size_t i = 0; i < ng_display_count; i++) {
			if (ng_display[i].depth == (size_t)swf_depth && ng_display[i].parent_display_idx == (size_t)-1) {
				for (size_t j = i; j + 1 < ng_display_count; j++)
					ng_display[j] = ng_display[j + 1];
				ng_display_count--;
				if (src_idx > i) src_idx--;
				break;
			}
		}

		// Create ng_display entry — inherits sprite_idx but NO clip_actions (no onLoad)
		if (ng_display_count < MAX_DISPLAY_NG) {
			size_t clone_idx = ng_display_count++;
			ng_display[clone_idx] = ng_display[src_idx];
			ng_display[clone_idx].depth = (size_t)swf_depth;
			ng_display[clone_idx].parent_display_idx = (size_t)-1;
			strncpy(ng_display[clone_idx].instance_name, target_name, 63);
			ng_display[clone_idx].instance_name[63] = '\0';
			ng_display[clone_idx].current_frame = 0;
			ng_display[clone_idx].needs_init = 0;     // duplicateMovieClip: no onLoad
			ng_display[clone_idx].clip_actions = NULL;
			ng_display[clone_idx].clip_action_count = 0;
		}
	}

	// Find/create source MC and clone MC
	MovieClip* src_mc = actionFindOrCreateMovieClip(app_context, source_name, &root_movieclip);
	MovieClip* clone_mc = actionFindOrCreateMovieClip(app_context, target_name, &root_movieclip);
	if (clone_mc == NULL) return NULL;

	// Copy transform and AS-set-flags from source
	if (src_mc != NULL) {
		clone_mc->x = src_mc->x;
		clone_mc->y = src_mc->y;
		clone_mc->xscale = src_mc->xscale;
		clone_mc->yscale = src_mc->yscale;
		clone_mc->rotation = src_mc->rotation;
		clone_mc->alpha = src_mc->alpha;
		clone_mc->visible = src_mc->visible;
		clone_mc->totalframes = src_mc->totalframes;
		clone_mc->framesloaded = src_mc->framesloaded;
		clone_mc->as_set_flags = src_mc->as_set_flags;
	}
	clone_mc->currentframe = 1;
	clone_mc->depth = swf_depth;

	// Do NOT call setVariableByName: duplicateMovieClip clones are accessible via
	// path resolution (_root.name) but not as bare script-scope variables.

	return clone_mc;
}

const char* ng_getTextFieldInitialText(size_t depth)
{
	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (ng_display[i].depth == depth && ng_display[i].parent_display_idx == (size_t)-1 &&
		    ng_display[i].is_textfield && ng_display[i].textfield_idx >= 0)
			return ng_textfields[ng_display[i].textfield_idx].plain_text;
	}
	return "";
}

u32 ng_getTextFieldColor(size_t depth)
{
	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (ng_display[i].depth == depth && ng_display[i].parent_display_idx == (size_t)-1 &&
		    ng_display[i].is_textfield && ng_display[i].textfield_idx >= 0)
			return ng_textfields[ng_display[i].textfield_idx].text_color;
	}
	return 0;
}

u32 ng_getTextFieldColorByIdx(int idx)
{
	if (idx < 0 || (size_t)idx >= ng_textfield_count) return 0;
	return ng_textfields[idx].text_color;
}

int ng_getTextFieldIdx(size_t depth)
{
	for (size_t i = 0; i < ng_display_count; i++)
		if (ng_display[i].depth == depth && ng_display[i].parent_display_idx == (size_t)-1 &&
		    ng_display[i].is_textfield)
			return ng_display[i].textfield_idx;
	return -1;
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

u16 ng_getTextFieldIndent(int tf_idx)
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

int ng_getTextFieldCSMApplied(int tf_idx)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) return 0;
	return ng_textfields[tf_idx].csm_applied;
}

const char* ng_getTextFieldCSMAntiAliasType(int tf_idx)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) return "normal";
	return ng_textfields[tf_idx].csm_antiAliasType;
}

const char* ng_getTextFieldCSMGridFitType(int tf_idx)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) return "pixel";
	return ng_textfields[tf_idx].csm_gridFitType;
}

float ng_getTextFieldCSMThickness(int tf_idx)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) return 0.0f;
	return ng_textfields[tf_idx].csm_thickness;
}

float ng_getTextFieldCSMSharpness(int tf_idx)
{
	if (tf_idx < 0 || (size_t)tf_idx >= ng_textfield_count) return 0.0f;
	return ng_textfields[tf_idx].csm_sharpness;
}

const char* ng_getFontName(u16 font_id)
{
	for (size_t i = 0; i < ng_font_count; i++)
		if (ng_fonts[i].font_id == font_id)
			return ng_fonts[i].name;
	return "";
}

int ng_getFontBold(u16 font_id)
{
	for (size_t i = 0; i < ng_font_count; i++)
		if (ng_fonts[i].font_id == font_id)
			return ng_fonts[i].bold;
	return 0;
}

int ng_getFontItalic(u16 font_id)
{
	for (size_t i = 0; i < ng_font_count; i++)
		if (ng_fonts[i].font_id == font_id)
			return ng_fonts[i].italic;
	return 0;
}

// Get transform_id for a display entry at a given depth
int ng_getTransformId(size_t depth, u32* out_id)
{
	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (ng_display[i].depth == depth && ng_display[i].parent_display_idx == (size_t)-1)
		{
			*out_id = ng_display[i].transform_id;
			return 1;
		}
	}
	return 0;
}

// Get x/y translation from transform_data for a display entry
int ng_getTransformXY(size_t depth, float* out_x, float* out_y)
{
	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (ng_display[i].depth == depth && ng_display[i].parent_display_idx == (size_t)-1)
		{
			u32 tid = ng_display[i].transform_id;
			*out_x = transform_data[tid][12] / 20.0f;
			*out_y = transform_data[tid][13] / 20.0f;
			return 1;
		}
	}
	return 0;
}

// Get x/y translation as double (avoids float32 precision loss for traces like 125.2)
int ng_getTransformXY_d(size_t depth, double* out_x, double* out_y)
{
	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (ng_display[i].depth == depth && ng_display[i].parent_display_idx == (size_t)-1)
		{
			u32 tid = ng_display[i].transform_id;
			if (out_x) *out_x = (double)transform_data[tid][12] / 20.0;
			if (out_y) *out_y = (double)transform_data[tid][13] / 20.0;
			return 1;
		}
	}
	return 0;
}

// Get scale/rotation from transform_data for a display entry at a given depth.
// Only matches root-level entries (parent_display_idx == (size_t)-1).
// out_xscale and out_yscale are percentages (100=100%). out_rotation is degrees.
// Returns 1 if found, 0 if not.
int ng_getTransformScaleRotation(size_t depth, float* out_xscale, float* out_yscale, float* out_rotation)
{
	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (ng_display[i].depth == depth && ng_display[i].parent_display_idx == (size_t)-1)
		{
			u32 tid = ng_display[i].transform_id;
			float m00 = transform_data[tid][0];   // ScaleX * cos(rot)
			float m10 = transform_data[tid][1];   // ScaleX * sin(rot)
			float m01 = transform_data[tid][4];   // -ScaleY * sin(rot) (SkewY)
			float m11 = transform_data[tid][5];   // ScaleY * cos(rot)
			if (out_xscale) *out_xscale = sqrtf(m00*m00 + m10*m10) * 100.0f;
			if (out_yscale) *out_yscale = sqrtf(m01*m01 + m11*m11) * 100.0f;
			if (out_rotation) *out_rotation = atan2f(m10, m00) * 180.0f / 3.14159265358979323846f;
			return 1;
		}
	}
	return 0;
}

// Look up character bounds by char_id. Returns 1 if found, 0 if not.
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

// Compute content bounds in pixels for children of a display entry.
// entry_idx = (size_t)-1 means root-level children.
// Bounds are in the parent's local pixel space (translate+scale applied, ignoring rotation for now).
// Returns 1 if any bounds found, 0 if no children or no bounds data.
int ng_getDisplayEntryBounds(size_t entry_idx,
    float* out_xmin_px, float* out_xmax_px,
    float* out_ymin_px, float* out_ymax_px)
{
	int found = 0;
	float gxmin = 1e30f, gxmax = -1e30f;
	float gymin = 1e30f, gymax = -1e30f;

	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (ng_display[i].parent_display_idx != entry_idx) continue;

		u32 tid = ng_display[i].transform_id;
		float tx = transform_data[tid][12] / 20.0f;  // twips→pixels
		float ty = transform_data[tid][13] / 20.0f;
		// Extract scale from matrix diagonal (column-major): [0]=cos*sx, [5]=cos*sy (approx)
		float sx = transform_data[tid][0];
		float sy = transform_data[tid][5];

		float bxmin_px, bxmax_px, bymin_px, bymax_px;
		int child_found = 0;

		if (ng_display[i].sprite_idx != (size_t)-1)
		{
			// Sprite: recursively get its local bounds, then apply this sprite's transform
			float lxmin, lxmax, lymin, lymax;
			if (ng_getDisplayEntryBounds(i, &lxmin, &lxmax, &lymin, &lymax))
			{
				bxmin_px = lxmin * sx + tx;
				bxmax_px = lxmax * sx + tx;
				bymin_px = lymin * sy + ty;
				bymax_px = lymax * sy + ty;
				if (bxmin_px > bxmax_px) { float tmp = bxmin_px; bxmin_px = bxmax_px; bxmax_px = tmp; }
				if (bymin_px > bymax_px) { float tmp = bymin_px; bymin_px = bymax_px; bymax_px = tmp; }
				child_found = 1;
			}
		}
		else if (ng_display[i].is_textfield && ng_display[i].textfield_idx >= 0)
		{
			int tf_idx = ng_display[i].textfield_idx;
			float bxf = ng_textfields[tf_idx].bounds_xmin / 20.0f;
			float bxf2 = ng_textfields[tf_idx].bounds_xmax / 20.0f;
			float byf = ng_textfields[tf_idx].bounds_ymin / 20.0f;
			float byf2 = ng_textfields[tf_idx].bounds_ymax / 20.0f;
			bxmin_px = bxf * sx + tx;
			bxmax_px = bxf2 * sx + tx;
			bymin_px = byf * sy + ty;
			bymax_px = byf2 * sy + ty;
			if (bxmin_px > bxmax_px) { float tmp = bxmin_px; bxmin_px = bxmax_px; bxmax_px = tmp; }
			if (bymin_px > bymax_px) { float tmp = bymin_px; bymin_px = bymax_px; bymax_px = tmp; }
			child_found = 1;
		}
		else if (!ng_display[i].is_button)
		{
			// Shape: look up char bounds
			s32 bxmin, bxmax, bymin, bymax;
			if (ng_getCharBounds(ng_display[i].char_id, &bxmin, &bxmax, &bymin, &bymax))
			{
				bxmin_px = bxmin / 20.0f * sx + tx;
				bxmax_px = bxmax / 20.0f * sx + tx;
				bymin_px = bymin / 20.0f * sy + ty;
				bymax_px = bymax / 20.0f * sy + ty;
				if (bxmin_px > bxmax_px) { float tmp = bxmin_px; bxmin_px = bxmax_px; bxmax_px = tmp; }
				if (bymin_px > bymax_px) { float tmp = bymin_px; bymin_px = bymax_px; bymax_px = tmp; }
				child_found = 1;
			}
		}

		if (child_found)
		{
			if (!found || bxmin_px < gxmin) gxmin = bxmin_px;
			if (!found || bxmax_px > gxmax) gxmax = bxmax_px;
			if (!found || bymin_px < gymin) gymin = bymin_px;
			if (!found || bymax_px > gymax) gymax = bymax_px;
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

// NO_GRAPHICS child lookup by instance name — returns depth or SIZE_MAX if not found
// Only matches root-level entries (called from action.c for root display object resolution)
// Find a display entry at the given SWF depth that is a direct child of the root.
// Returns: 0 = not found, 1 = found non-sprite, 2 = found sprite (name in out_name)
int ng_findRootChildAtSWFDepth(size_t swf_depth, char* out_name, size_t out_name_size)
{
	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (ng_display[i].depth != swf_depth) continue;
		if (ng_display[i].parent_display_idx != (size_t)-1) continue;
		if (ng_display[i].sprite_idx != (size_t)-1) {
			// It's a sprite — copy name (may be empty if unnamed)
			if (out_name && out_name_size > 0) {
				strncpy(out_name, ng_display[i].instance_name, out_name_size - 1);
				out_name[out_name_size - 1] = '\0';
			}
			return 2;
		} else if (ng_display[i].is_textfield) {
			// It's a textfield — copy name, return 3
			if (out_name && out_name_size > 0) {
				strncpy(out_name, ng_display[i].instance_name, out_name_size - 1);
				out_name[out_name_size - 1] = '\0';
			}
			return 3;
		} else {
			// Non-sprite, non-textfield (shape, plain text, button)
			if (out_name && out_name_size > 0) out_name[0] = '\0';
			return 1;
		}
	}
	return 0;
}

// Search for a named child within a named parent's display list.
// Returns the child's SWF depth (within-parent depth), or SIZE_MAX if not found.
size_t ng_findChildEntryDepth(const char* parent_name, const char* child_name)
{
	// Find parent entry index
	size_t parent_idx = SIZE_MAX;
	for (size_t i = 0; i < ng_display_count; i++) {
		if (ng_display[i].instance_name[0] != '\0' &&
		    strcmp(ng_display[i].instance_name, parent_name) == 0) {
			parent_idx = i;
			break;
		}
	}
	if (parent_idx == SIZE_MAX) return SIZE_MAX;

	// Find child entry that is a direct child of parent_idx
	for (size_t i = 0; i < ng_display_count; i++) {
		if (ng_display[i].parent_display_idx == parent_idx &&
		    ng_display[i].instance_name[0] != '\0' &&
		    strcmp(ng_display[i].instance_name, child_name) == 0) {
			return ng_display[i].depth;
		}
	}
	return SIZE_MAX;
}

// Update ng_display depth for a named root-level entry (for swapDepths with numeric arg)
void ng_updateDisplayDepth(const char* name, int new_as_depth)
{
	size_t new_swf_depth = (size_t)(new_as_depth + 16384);
	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (ng_display[i].parent_display_idx == (size_t)-1 &&
		    ng_display[i].instance_name[0] != '\0' &&
		    strcmp(ng_display[i].instance_name, name) == 0)
		{
			ng_display[i].depth = new_swf_depth;
			return;
		}
	}
}

// Swap ng_display depths of two named root-level entries (for swapDepths with MC arg)
void ng_swapDisplayDepths(const char* name1, const char* name2)
{
	size_t idx1 = SIZE_MAX, idx2 = SIZE_MAX;
	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (ng_display[i].parent_display_idx == (size_t)-1 &&
		    ng_display[i].instance_name[0] != '\0')
		{
			if (strcmp(ng_display[i].instance_name, name1) == 0) idx1 = i;
			else if (strcmp(ng_display[i].instance_name, name2) == 0) idx2 = i;
		}
	}
	if (idx1 != SIZE_MAX && idx2 != SIZE_MAX)
	{
		size_t tmp = ng_display[idx1].depth;
		ng_display[idx1].depth = ng_display[idx2].depth;
		ng_display[idx2].depth = tmp;
	}
}

size_t ng_findDisplayEntryByName(const char* name)
{
	// Return the lowest-depth match when multiple entries share a name
	size_t result = SIZE_MAX;
	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (ng_display[i].parent_display_idx == (size_t)-1 &&
		    ng_display[i].instance_name[0] != '\0' &&
		    strcmp(ng_display[i].instance_name, name) == 0)
		{
			if (result == SIZE_MAX || ng_display[i].depth < result)
				result = ng_display[i].depth;
		}
	}
	return result;
}

// Find display entry INDEX (not depth) by instance name. Returns (size_t)-1 if not found.
size_t ng_findDisplayEntryIdx(const char* name)
{
	if (!name || name[0] == '\0') return (size_t)-1;
	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (ng_display[i].instance_name[0] != '\0' &&
		    strcmp(ng_display[i].instance_name, name) == 0)
			return i;
	}
	return (size_t)-1;
}

// Rename a display list entry's instance name (for _name setter)
void ng_renameDisplayEntry(const char* old_name, const char* new_name)
{
	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (ng_display[i].instance_name[0] != '\0' &&
		    strcmp(ng_display[i].instance_name, old_name) == 0)
		{
			strncpy(ng_display[i].instance_name, new_name, 63);
			ng_display[i].instance_name[63] = '\0';
			return;
		}
	}
}

void tagRemoveObject(SWFAppContext* app_context, size_t depth)
{
	(void)app_context; (void)depth;
}

void tagRemoveObject2(SWFAppContext* app_context, size_t depth)
{
	// During backward goto catch-up, don't remove entries that were placed
	// at or before the target frame — they're part of the preserved state.
	extern int catch_up_backward;
	extern size_t catch_up_target;

	size_t expected_parent = ng_nesting_depth > 0 ? ng_current_display_idx : (size_t)-1;
	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (ng_display[i].depth == depth && ng_display[i].parent_display_idx == expected_parent)
		{
			if (catch_up_backward && ng_display[i].placed_at_frame <= catch_up_target)
				return;  // Protected: don't remove
			// Invalidate cached MovieClip so re-placement gets fresh properties
			if (ng_display[i].instance_name[0] != '\0')
				actionInvalidateCachedMovieClip(app_context, ng_display[i].instance_name);
			// Remove by shifting
			for (size_t j = i; j + 1 < ng_display_count; j++)
				ng_display[j] = ng_display[j + 1];
			ng_display_count--;
			return;
		}
	}
}

void tagDefineSprite(SWFAppContext* app_context, size_t char_id, frame_func* funcs, size_t frame_count)
{
	(void)app_context;
	// Skip if already registered (can happen during goto catch-up replay)
	if (ng_find_sprite(char_id) != (size_t)-1) return;
	if (ng_sprite_count < MAX_SPRITES_NG)
	{
		ng_sprites[ng_sprite_count].char_id = char_id;
		ng_sprites[ng_sprite_count].funcs = funcs;
		ng_sprites[ng_sprite_count].frame_count = frame_count;
		ng_sprite_count++;
	}
}

void tagDefineButton(SWFAppContext* app_context, size_t char_id, frame_func* state_funcs, size_t hit_char_id, u32 hit_transform_id, ButtonAction* actions, size_t action_count)
{
	(void)app_context; (void)state_funcs; (void)hit_char_id;
	(void)hit_transform_id; (void)actions; (void)action_count;
	// Register as button for typeof discrimination
	if (ng_button_count < MAX_BUTTONS_NG && !ng_find_button(char_id))
		ng_button_ids[ng_button_count++] = char_id;
}

void defineBitmap(size_t offset, size_t size, u32 width, u32 height)
{
	(void)offset; (void)size; (void)width; (void)height;
}

void finalizeBitmaps()
{
}

void tagDefineSound(SWFAppContext* app_context, u16 sound_id,
	u8 format, u8 rate, u8 sample_size, u8 stereo,
	u32 sample_count, const u8* data, size_t data_size)
{
	(void)app_context; (void)sound_id; (void)format; (void)rate;
	(void)sample_size; (void)stereo; (void)sample_count; (void)data; (void)data_size;
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
