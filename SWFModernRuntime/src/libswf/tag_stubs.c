#ifdef NO_GRAPHICS

#include <tag.h>
#include <swf.h>
#include <common.h>
#include <action.h>
#include <heap.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

// Font info registry (font name, bold, italic)
#define MAX_FONTS_NG 32
static struct {
	u16 font_id;
	char name[128];
	int bold;
	int italic;
} ng_fonts[MAX_FONTS_NG];
static size_t ng_font_count = 0;

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
	u16 left_margin, right_margin, indent;
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
			// Set global variable to undefined so GetVariable returns undefined
			size_t name_len = strlen(g_clone_depth_table[i].name);
			ActionVar* old_var = getVariable((char*)g_clone_depth_table[i].name, name_len);
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

void ng_record_button(size_t char_id)
{
	if (ng_button_count < MAX_BUTTONS_NG && !ng_find_button(char_id))
		ng_button_ids[ng_button_count++] = char_id;
}

void ng_record_textfield_props(SWFAppContext* app_context, size_t char_id,
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

void ng_record_video(SWFAppContext* app_context, u16 char_id)
{
	(void)app_context;
	if (ng_video_count < MAX_VIDEOS_NG)
		ng_video_ids[ng_video_count++] = (size_t)char_id;
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
	if ((is_sprite || is_button || is_tf || is_video) && obj->instance_name == NULL)
	{
		char auto_name[32];
		snprintf(auto_name, sizeof(auto_name), "instance%u", ng_auto_instance_counter++);
		obj->instance_name = strdup(auto_name);
		obj->instance_name_owned = 1;
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
		// Fire AS-set onUnload handler BEFORE invalidating the MC's dynamic_props
		actionFireOnUnload(app_context, display_list[depth].instance_name);
		// Invalidate cached MovieClip so re-placement gets fresh properties
		actionInvalidateCachedMovieClip(app_context, display_list[depth].instance_name);
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
	if (frame < ch->sprite_frame_count)
	{
		obj->sprite_manual_next_frame = 1;
		obj->sprite_next_frame = frame;
		obj->sprite_is_playing = 0;
	}
}

size_t ng_getSpriteFrameCount(void)
{
	DisplayObject* obj = g_current_sprite_obj;
	if (obj == NULL || obj->char_id == 0) return 0;
	Character* ch = &dictionary[obj->char_id];
	if (ch->type != CHAR_TYPE_SPRITE) return 0;
	return ch->sprite_frame_count;
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
		if (strcmp(display_list[d].instance_name, name) == 0)
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
		    strcmp(display_list[d].instance_name, name) == 0)
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
		if (child->instance_name != NULL && strcmp(child->instance_name, name) == 0)
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

// ---------------------------------------------------------------------------
// Font accessors
// ---------------------------------------------------------------------------

const char* ng_getFontName(u16 font_id)
{
	for (size_t i = 0; i < ng_font_count; i++)
		if (ng_fonts[i].font_id == font_id) return ng_fonts[i].name;
	return "";
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
		                 ng_find_button(cid) || (ng_find_textfield(cid) >= 0);
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
		                 ng_find_button(cid) || (ng_find_textfield(cid) >= 0);
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
