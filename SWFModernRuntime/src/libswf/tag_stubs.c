#if defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)

#include <tag.h>
#include <swf.h>
#include <common.h>
#include <action.h>
#include <object.h>
#include <heap.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <actionmodern/action_queue.h>

// ---------------------------------------------------------------------------
// Global display state — defined here in NO_GRAPHICS (swf.c provides in GRAPHICS)
// ---------------------------------------------------------------------------
Character* dictionary = NULL;
DisplayObject* display_list = NULL;
size_t max_depth = 0;

// ---------------------------------------------------------------------------
// Access generated data arrays (from draws.c / tagMain.c, linked per-test)
// ---------------------------------------------------------------------------
extern float transform_data[][16];
extern float cxform_data[];
extern int catch_up_mode;
extern size_t display_list_capacity;

// ---------------------------------------------------------------------------
// Provided by ng_shared.c (compiled in all build modes)
// ---------------------------------------------------------------------------
extern int ng_find_button(size_t char_id);
extern int ng_find_video(size_t char_id);
extern int ng_find_textfield(size_t char_id);
extern int ng_find_char_path(size_t char_id, size_t* out_offset, size_t* out_size);
extern int ng_find_morph_path(size_t char_id, size_t* out_offset, size_t* out_size);
extern int ng_uses_nonzero_winding(size_t char_id);
extern unsigned int ng_get_auto_instance_counter(void);
extern unsigned int ng_increment_auto_instance_counter(void);
extern void ng_registerSoundMetadata(u16 sound_id, u8 rate, u32 sample_count);
extern const char* ng_lookupExportName(size_t char_id);

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
						child_mc_cache[ci]->avm1_removed = 1;
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

// ng_sync_root_display_obj, ng_get_root_display_obj — now in ng_shared.c

// ---------------------------------------------------------------------------
// Pending attach init queue — deferred frame-0 script execution for attachMovie
// ---------------------------------------------------------------------------
// Phase 3c of ACTION_QUEUE_PLAN: backing storage is the unified ActionQueue
// (AQ_KIND_ATTACH_INIT entries). Coalesce-by-swf_depth at enqueue time is
// preserved via actionQueueFindUserByKind — if attachMovie fires at a depth
// that already has a queued entry, its payload is mutated in place so the
// last-attached version wins (the prior init never runs). The outer
// while-loop dispatch the old implementation used is handled for free by
// the unified drain's pop-until-empty behavior: re-entrant attachMovie calls
// push new entries that the outer drain picks up naturally. The old
// MAX_PENDING_ATTACH_INITS=64 silent-overflow limit is gone.
extern MovieClip* actionFindOrCreateMovieClip(SWFAppContext* app_context, const char* name, MovieClip* parent);
extern void setVariableByName(const char* var_name, ActionVar* value);
extern void actionSetCurrentContext(MovieClip* mc);
extern MovieClip root_movieclip;
extern int g_settarget_explicit_root;
extern DisplayObject* g_current_sprite_obj;
extern MovieClip* g_current_context;

typedef struct {
	char instance_name[256];
	char export_name[128];  // For registered class constructor invocation
	frame_func func;
	int swf_depth;
} PendingAttachInit;

static void aq_dispatch_pending_attach_init(SWFAppContext* app_context, void* user)
{
	PendingAttachInit* pai = (PendingAttachInit*) user;
	if (pai == NULL) return;

	// Set context and base clip to the attached clip for correct variable resolution
	MovieClip* saved_ctx = g_current_context;
	extern void actionSetBaseClip(MovieClip* mc);
	extern MovieClip* actionGetBaseClip(void);
	MovieClip* saved_base = actionGetBaseClip();
	MovieClip* mc = actionFindOrCreateMovieClip(
		app_context, pai->instance_name, &root_movieclip);
	if (mc) { actionSetCurrentContext(mc); actionSetBaseClip(mc); }

	// Save display list state and switch to the MC's sprite display list
	DisplayObject* saved_dl = display_list;
	size_t saved_max = max_depth;
	size_t saved_cap = display_list_capacity;
	DisplayObject* saved_sprite_obj = g_current_sprite_obj;
	int saved_settarget = g_settarget_explicit_root;
	extern int g_settarget_invalid;
	extern int g_settarget_none;
	int saved_invalid = g_settarget_invalid;
	int saved_none = g_settarget_none;

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
	g_settarget_invalid = 0;
	g_settarget_none = 0;
	g_current_sprite_obj = NULL;

	// Run the frame function in script-only mode: placement tags already ran during
	// ng_attachMovie with catch_up_mode=1, so only scripts need to execute now.
	// Without script_only_mode, tagPlaceObject2's loop-back preservation check
	// would clear sprite_needs_init on children (e.g. "box"), preventing Phase 2.
	// Phase 7b: bracket with actionDeferredSpriteInitEnter so the recompiler-
	// emitted sprite DoAction gate's sync-fire path activates
	// (scriptOnly && deferred) and scripts run inline here (with the correct
	// MC context already set above) instead of being silently dropped.
	{
		extern void ng_set_script_only_mode(int mode);
		ng_set_script_only_mode(1);
		actionDeferredSpriteInitEnter();
		pai->func(app_context);
		actionDeferredSpriteInitLeave();
		ng_set_script_only_mode(0);
	}

	// Recursively initialize any child sprites placed by the frame function.
	// Without this, children of attachMovie'd sprites (e.g. sprite_2's child
	// sprite_1 instances) never run their frame 0 scripts.
	{
		extern void process_sprite_needs_init_public(SWFAppContext* app_context, MovieClip* parent_mc);
		process_sprite_needs_init_public(app_context, mc);
	}

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
	g_settarget_invalid = saved_invalid;
	g_settarget_none = saved_none;
	display_list = saved_dl;
	max_depth = saved_max;
	display_list_capacity = saved_cap;

	// NOTE: Registered class constructor is now fired synchronously during
	// attachMovie (in action.c), not deferred here. This ensures the constructor
	// runs before attachMovie returns to the caller script.

	free(pai);
}

static int attach_init_match_depth(void* user, void* ctx)
{
	PendingAttachInit* pai = (PendingAttachInit*) user;
	int swf_depth = *(int*) ctx;
	return pai && pai->swf_depth == swf_depth;
}

void ng_fire_pending_attach_inits(SWFAppContext* app_context)
{
	actionDrainActionQueueByKind(app_context, AQ_KIND_ATTACH_INIT);
}

// ---------------------------------------------------------------------------
// ng_attachMovie — instantiate an exported library symbol at runtime
// ---------------------------------------------------------------------------

MovieClip* ng_attachMovie(SWFAppContext* app_context, size_t char_id, const char* new_name, int as_depth, MovieClip* parent)
{
	extern size_t display_list_capacity;

	if (char_id >= INITIAL_DICTIONARY_CAPACITY) return NULL;
	int _am_is_button = (dictionary[char_id].type == CHAR_TYPE_BUTTON);
	if (dictionary[char_id].type != CHAR_TYPE_SPRITE && !_am_is_button) return NULL;
	// Flash valid depth range: -16384 to 2130690044
	if (as_depth > 2130690044 || as_depth < -16384) return NULL;

	// Create MC for the attached clip (reset position/scale to defaults for re-attach)
	MovieClip* new_mc = actionFindOrCreateMovieClip(app_context, new_name, parent);
	if (new_mc == NULL) return NULL;
	new_mc->is_button_mc = _am_is_button ? 1 : 0;
	new_mc->movie_id = parent->movie_id;  // Attached clips belong to same movie as parent

	// Remove any existing clone at this SWF depth BEFORE setting depth/props.
	// clone_depth_evict may set depth=INT_MIN on the old MC at this depth,
	// which could be the same struct if actionFindOrCreateMovieClip reused it.
	// Only use global clone depth system for root-level attachments; non-root
	// children have independent depth spaces and must not collide.
	int swf_depth = as_depth + 16384;
	if (parent == &root_movieclip)
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
#if defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)
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
		extern int g_settarget_invalid;
		extern int g_settarget_none;
		int            saved_invalid2 = g_settarget_invalid;
		int            saved_none2 = g_settarget_none;
		int            saved_catch_up = catch_up_mode;

		// Create a display object for the attached clip to hold its children
		if (new_mc->display_obj == NULL) {
			DisplayObject* dobj = calloc(1, sizeof(DisplayObject));
			dobj->char_id = char_id;
			dobj->sprite_dl_capacity = 64;
			// Use HCALLOC so grow_ptr/ENSURE_SIZE/FREE can operate on it consistently
			dobj->sprite_display_list = HCALLOC(dobj->sprite_dl_capacity, sizeof(DisplayObject));
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
		g_settarget_invalid = 0;
		g_settarget_none = 0;

		// Set the MC context so _name, _x etc resolve correctly
		saved_ctx = g_current_context;
		actionSetCurrentContext(new_mc);
		g_current_sprite_obj = NULL;

		// Run frame 0 with catch_up_mode=1 to skip scripts (only placement tags run).
		// Phase 7b note: we intentionally do NOT bump eager here, because
		// ng_attachMovie's scripts are run later by aq_dispatch_pending_attach_init
		// via its own pai->func call. Bumping eager here would queue scripts
		// now, and then the deferred re-run (with scriptOnly=1) would be a
		// no-op, but the queued scripts would fire at next SHOW_FRAME pre-drain
		// in root context (bound to the attached MC via actionQueueSpriteScript,
		// but too early relative to the attach_init contract). See
		// aq_dispatch_pending_attach_init which bumps eager + deferred for
		// its pai->func call so scripts fire synchronously there.
		//
		// ALSO save/restore g_tag_skip_mode: when attachMovie is called from
		// inside a deferred-goto Phase 2 target-frame replay (tag_skip_mode=1),
		// inheriting tag_skip=1 into funcs[0] would match the sprite gate's
		// g_tag_skip_mode branch and queue the nested sprite's script here,
		// then PAI drain would fire it AGAIN — double-fire. Reset tag_skip=0
		// for the nested init (we want catch_up_mode=1 to fully skip scripts).
		extern int g_tag_skip_mode;
		int _am_saved_tag_skip = g_tag_skip_mode;
		g_tag_skip_mode = 0;
		catch_up_mode = 1;
		funcs[0](app_context);
		catch_up_mode = saved_catch_up;
		g_tag_skip_mode = _am_saved_tag_skip;

		// Restore context
		actionSetCurrentContext(saved_ctx);
		g_current_sprite_obj = saved_sprite_obj;
		g_settarget_explicit_root = saved_settarget;
		g_settarget_invalid = saved_invalid2;
		g_settarget_none = saved_none2;

		// Persist the updated display list state on the MC's display obj
		dobj->sprite_display_list = display_list;
		dobj->sprite_max_depth = max_depth;
		dobj->sprite_dl_capacity = display_list_capacity;

		// Compute content bounds from children placed during frame 0.
		// Uses sprite_content_bounds_twips which accounts for child transforms
		// (e.g., a 1x1 twip shape placed with a 20x scale transform → 20x20 twips).
		{
			float bxmin, bxmax, bymin, bymax;
			if (sprite_content_bounds_twips(dobj->sprite_display_list, dobj->sprite_max_depth,
			        &bxmin, &bxmax, &bymin, &bymax)) {
				new_mc->width = (bxmax - bxmin) / 20.0f;
				new_mc->height = (bymax - bymin) / 20.0f;
			}
		}

		// Restore the parent display list
		display_list = saved_dl;
		max_depth = saved_max;
		display_list_capacity = saved_cap;

		// Queue the frame function for deferred script execution
		// (Flash runs attached clip init scripts at end of frame)
		// If an init is already pending for the same SWF depth, mutate it in
		// place (re-attaching at the same depth supersedes the previous init).
		{
			const char* exp_name = ng_lookupExportName(char_id);
			PendingAttachInit* pai = (PendingAttachInit*)
				actionQueueFindUserByKind(AQ_KIND_ATTACH_INIT,
				                          attach_init_match_depth, &swf_depth);
			if (pai == NULL) {
				pai = (PendingAttachInit*) malloc(sizeof(PendingAttachInit));
				if (pai == NULL) goto skip_attach_init_queue;
				pai->swf_depth = swf_depth;
				actionQueueCallbackEx(app_context,
				                      aq_dispatch_pending_attach_init,
				                      (void*)pai,
				                      AQ_PRIORITY_NORMAL, NULL,
				                      /*is_unload=*/0,
				                      AQ_KIND_ATTACH_INIT);
			}
			strncpy(pai->instance_name, new_name, sizeof(pai->instance_name) - 1);
			pai->instance_name[sizeof(pai->instance_name) - 1] = '\0';
			pai->func = funcs[0];
			if (exp_name) {
				strncpy(pai->export_name, exp_name, sizeof(pai->export_name) - 1);
				pai->export_name[sizeof(pai->export_name) - 1] = '\0';
			} else {
				pai->export_name[0] = '\0';
			}
		skip_attach_init_queue: ;
		}
	}

	// Register the new child in the parent's sprite display list so that
	// resolveSlashPathToMC can find it (e.g., GetVariable("target2") inside base2)
	if (parent != &root_movieclip && parent->display_obj != NULL) {
		DisplayObject* pdobj = (DisplayObject*)parent->display_obj;
		if (pdobj->sprite_display_list != NULL) {
			size_t target_d = (size_t)swf_depth;
			// Grow if needed — use HCALLOC/FREE (heap allocator) because the parent's
			// sprite_display_list may have been allocated by HCALLOC (timeline sprites).
			// Standard realloc cannot operate on custom-heap pointers.
			if (target_d >= pdobj->sprite_dl_capacity) {
				size_t new_cap = target_d + 16;
				DisplayObject* new_dl = HCALLOC(new_cap, sizeof(DisplayObject));
				if (new_dl) {
					memcpy(new_dl, pdobj->sprite_display_list, pdobj->sprite_dl_capacity * sizeof(DisplayObject));
					FREE(pdobj->sprite_display_list);
					pdobj->sprite_display_list = new_dl;
					pdobj->sprite_dl_capacity = new_cap;
				}
			}
			pdobj->sprite_display_list[target_d].char_id = char_id;
			if (pdobj->sprite_display_list[target_d].instance_name)
				free(pdobj->sprite_display_list[target_d].instance_name);
			pdobj->sprite_display_list[target_d].instance_name = strdup(new_name);
			// Copy child's display list pointers if it has a display_obj
			if (new_mc->display_obj != NULL) {
				DisplayObject* cdobj = (DisplayObject*)new_mc->display_obj;
				pdobj->sprite_display_list[target_d].sprite_display_list = cdobj->sprite_display_list;
				pdobj->sprite_display_list[target_d].sprite_max_depth = cdobj->sprite_max_depth;
				pdobj->sprite_display_list[target_d].sprite_dl_capacity = cdobj->sprite_dl_capacity;
			}
			if (target_d > pdobj->sprite_max_depth)
				pdobj->sprite_max_depth = target_d;
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
// Phase 3b of ACTION_QUEUE_PLAN: backing storage is the unified ActionQueue
// (AQ_KIND_LOAD entries). The payload is a heap-allocated PendingLoad; the
// aq_dispatch_pending_load callback owns its lifetime and frees it after
// dispatch. The MAX_PENDING_LOADS=64 silent-overflow limit is gone —
// dynamic queue growth replaces it.
typedef struct {
	char instance_name[64];
	ClipAction* clip_actions;
	size_t clip_action_count;
} PendingLoad;

static void aq_dispatch_pending_load(SWFAppContext* app_context, void* user)
{
	PendingLoad* pl = (PendingLoad*) user;
	if (pl == NULL) return;
	MovieClip* saved_ctx = g_current_context;
	MovieClip* mc = actionFindOrCreateMovieClip(
		app_context, pl->instance_name, &root_movieclip);
	if (mc) actionSetCurrentContext(mc);
	for (size_t a = 0; a < pl->clip_action_count; a++)
	{
		if (pl->clip_actions[a].event_flags & CLIP_EVENT_LOAD)
			pl->clip_actions[a].action(app_context);
	}
	actionSetCurrentContext(saved_ctx);
	free(pl);
}

static void ng_queue_pending_load(const char* target_name,
                                  ClipAction* clip_actions,
                                  size_t clip_action_count)
{
	PendingLoad* pl = (PendingLoad*) malloc(sizeof(PendingLoad));
	if (pl == NULL) return;
	strncpy(pl->instance_name, target_name, sizeof(pl->instance_name) - 1);
	pl->instance_name[sizeof(pl->instance_name) - 1] = '\0';
	pl->clip_actions = clip_actions;
	pl->clip_action_count = clip_action_count;
	actionQueueCallbackEx(NULL, aq_dispatch_pending_load, (void*)pl,
	                      AQ_PRIORITY_NORMAL, NULL, /*is_unload=*/0,
	                      AQ_KIND_LOAD);
}

void ng_fire_pending_loads(SWFAppContext* app_context)
{
	actionDrainActionQueueByKind(app_context, AQ_KIND_LOAD);
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

	// Apply pending instance name (from tagSetInstanceName before tagPlaceObject2) to ANY
	// display object type. Must consume for non-scriptable types too (shapes, morph shapes)
	// to avoid leaking the name to the next scriptable object.
	// Then auto-assign "instanceN" for scriptable types (sprites/buttons/textfields) without names.
	{
		extern const char* g_pending_instance_name;
		if (g_pending_instance_name != NULL)
		{
			obj->instance_name = (char*)g_pending_instance_name;
			obj->instance_name_owned = 0;
			g_pending_instance_name = NULL;
		}
		else if ((is_sprite || is_button || is_tf) && obj->instance_name == NULL)
		{
			char auto_name[32];
			snprintf(auto_name, sizeof(auto_name), "instance%u", ng_increment_auto_instance_counter());
			obj->instance_name = strdup(auto_name);
			obj->instance_name_owned = 1;
		}
	}

	// Initialize textfield variable binding
	if (is_tf && tf_idx >= 0)
	{
		const char* var_name  = ng_getTextFieldVariableName(tf_idx);
		const char* init_text = ng_getTextFieldInitialTextByIdx(tf_idx);
		if (var_name[0] != '\0')
			actionInitTextFieldVariable(app_context, var_name, init_text);
	}

	// Allocate sprite display list and mark for initialization.
	// The actual eager init (frame 0 with catch_up_mode=1) happens in tagPlaceObject2
	// in tag.c, which handles clip event ordering (INITIALIZE before, CONSTRUCT after).
	// Auto-instance names are assigned depth-first because tag.c's eager init runs
	// the child sprite's frame function immediately, triggering recursive ng_on_place_object2
	// calls that increment the counter before the parent continues placing siblings.
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

// Recursively check a sprite's children for UNLOAD clip actions.
int has_child_unload_handler(DisplayObject* dl, size_t dl_max)
{
	for (size_t d = 1; d <= dl_max; d++) {
		if (dl[d].char_id == 0) continue;
		// Check this child's clip_actions
		for (size_t ca = 0; ca < dl[d].clip_action_count; ca++) {
			if (dl[d].clip_actions[ca].event_flags & 0x4)
				return 1;
		}
		for (size_t ca = 0; ca < dl[d].accumulated_clip_action_count; ca++) {
			if (dl[d].accumulated_clip_actions[ca].event_flags & 0x4)
				return 1;
		}
		// Recurse into child sprites
		if (dl[d].sprite_display_list != NULL && dl[d].sprite_max_depth > 0) {
			if (has_child_unload_handler(dl[d].sprite_display_list, dl[d].sprite_max_depth))
				return 1;
		}
	}
	return 0;
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
		// Check children of this sprite for UNLOAD handlers (recursive)
		if (!has_unload && display_list[depth].sprite_display_list != NULL &&
		    display_list[depth].sprite_max_depth > 0) {
			has_unload = has_child_unload_handler(display_list[depth].sprite_display_list,
			                                      display_list[depth].sprite_max_depth);
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

	// Execute frames synchronously (like advance_sprite_frames but immediate).
	// After sprite init, sprite_current_frame is bumped to 1 optimistically
	// (ready for advance_sprite_frames), but the target frame's tags may not
	// have been executed yet. When frame == current, execute just that frame's
	// function to ensure its tags are applied.
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

		size_t current = obj->sprite_current_frame;
		if (frame > current)
		{
			// Forward jump: execute frames current+1..frame
			for (size_t f = current + 1; f <= frame; f++)
			{
				if (f < fc && ch->sprite_frame_funcs[f] != NULL)
					ch->sprite_frame_funcs[f](app_context);
			}
		}
		else if (frame < current)
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
			// Same frame: execute this frame's tags. Handles the case where
			// sprite_current_frame was bumped after init but the target frame's
			// tags were never actually executed (sprite was stopped before
			// advance_sprite_frames could run them).
			// Increment place_gen so placement tags don't conflict with
			// entries placed during the previous frame's execution.
			extern size_t g_place_gen;
			g_place_gen++;
			if (frame < fc && ch->sprite_frame_funcs[frame] != NULL)
				ch->sprite_frame_funcs[frame](app_context);
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

// Get translation (in pixels) from a DisplayObject pointer (for walking parent chains).
void ng_getDisplayObjTranslation(void* dobj_ptr, float* out_tx, float* out_ty)
{
	if (dobj_ptr == NULL) { *out_tx = 0; *out_ty = 0; return; }
	DisplayObject* dobj = (DisplayObject*)dobj_ptr;
	u32 tid = dobj->transform_id;
	*out_tx = transform_data[tid][12] / 20.0f;
	*out_ty = transform_data[tid][13] / 20.0f;
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

void ng_setCTAlpha(size_t depth, double aa)
{
	if (depth <= max_depth && display_list[depth].char_id != 0) {
		display_list[depth].cx_aa = aa;
		display_list[depth].cx_overridden = 1;
	}
}

// ---------------------------------------------------------------------------
// Composite bounds computation (union of child content bounds in pixels)
// entry_idx == (size_t)-1: root-level children
// entry_idx is a root depth: children are sprite_display_list of that entry
// ---------------------------------------------------------------------------

static int g_bounds_recursion_depth = 0;
#define MAX_BOUNDS_RECURSION 16

int ng_getDisplayEntryFilterData(size_t entry_idx, u8* type, float* blur_x, float* blur_y,
    u8* quality, u8* flags, float* r, float* g, float* b, float* a,
    float* strength, float* angle, float* distance,
    float* hr, float* hg, float* hb, float* ha)
{
	size_t root_depth = entry_idx & 0xFFFFF;
	if (root_depth > max_depth) return 0;
	DisplayObject* obj = &display_list[root_depth];
	size_t nested = entry_idx >> 20;
	if (nested > 0 && obj->sprite_display_list)
		obj = &obj->sprite_display_list[nested];
	if (obj->filter_type == 0) return 0;
	*type = obj->filter_type;
	*blur_x = obj->filter_blur_x;
	*blur_y = obj->filter_blur_y;
	*quality = obj->filter_quality;
	*flags = obj->filter_flags;
	*r = obj->filter_color_r;
	*g = obj->filter_color_g;
	*b = obj->filter_color_b;
	*a = obj->filter_color_a;
	*strength = obj->filter_strength;
	*angle = obj->filter_angle;
	*distance = obj->filter_distance;
	*hr = obj->filter_highlight_r;
	*hg = obj->filter_highlight_g;
	*hb = obj->filter_highlight_b;
	*ha = obj->filter_highlight_a;
	return 1;
}

int ng_getDisplayEntryBounds(size_t entry_idx,
    float* out_xmin_px, float* out_xmax_px,
    float* out_ymin_px, float* out_ymax_px)
{
	if (g_bounds_recursion_depth >= MAX_BOUNDS_RECURSION) return 0;
	g_bounds_recursion_depth++;

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
			if (child_d < 1 || child_d > max_depth || display_list[child_d].char_id == 0) { g_bounds_recursion_depth--; return 0; }
			if (display_list[child_d].sprite_display_list == NULL) { g_bounds_recursion_depth--; return 0; }
			dl     = display_list[child_d].sprite_display_list;
			dl_max = display_list[child_d].sprite_max_depth;
		}
		else
		{
			// Level-1 nested: find child in parent's sprite display list
			if (parent_d < 1 || parent_d > max_depth || display_list[parent_d].char_id == 0) { g_bounds_recursion_depth--; return 0; }
			DisplayObject* parent_obj = &display_list[parent_d];
			if (parent_obj->sprite_display_list == NULL) { g_bounds_recursion_depth--; return 0; }
			if (child_d < 1 || child_d > parent_obj->sprite_max_depth) { g_bounds_recursion_depth--; return 0; }
			DisplayObject* child_obj = &parent_obj->sprite_display_list[child_d];
			if (child_obj->char_id == 0 || child_obj->sprite_display_list == NULL) { g_bounds_recursion_depth--; return 0; }
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
			s32 _tfbxmin, _tfbxmax, _tfbymin, _tfbymax;
			ng_getTextFieldBounds(tf_idx, &_tfbxmin, &_tfbxmax, &_tfbymin, &_tfbymax);
			float bxf  = _tfbxmin / 20.0f;
			float bxf2 = _tfbxmax / 20.0f;
			float byf  = _tfbymin / 20.0f;
			float byf2 = _tfbymax / 20.0f;
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
	g_bounds_recursion_depth--;
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
					ng_getTextFieldBounds(tf_idx, &cxmin, &cxmax, &cymin, &cymax);
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
		// Use cached transform values (stored at placement time by ng_cache_transform).
		// This ensures correct transforms for child SWFs whose transform_data
		// is a different array than the main SWF's.
		float ca = child->place_a;
		float cb = child->place_b;
		float cc = child->place_c;
		float cd = child->place_d;
		float ctxf = child->place_tx;
		float ctyf = child->place_ty;
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
					ng_getTextFieldBounds(tf_idx, &cxmin, &cxmax, &cymin, &cymax);
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
extern u32 glyph_data[][1];
extern u32 text_data[];

// Test if a point is inside a single triangle (barycentric coordinates)
// ---------------------------------------------------------------------------
// Vector-path hit testing: winding number algorithm
// ---------------------------------------------------------------------------

// Weak default: overridden by draws.c when shapes are present.
// Older generated code may lack path_data; this prevents linker errors.
__attribute__((weak)) float path_data[1][3] = {{0}};


// Winding number contribution from a line segment (ray-cast along +x axis).
// Returns +1 (downward crossing), -1 (upward crossing), or 0 (no crossing).
static int winding_number_line(double px, double py,
    double ax, double ay, double bx, double by)
{
	// Check if horizontal ray from (px, py) to +inf crosses segment (a → b)
	if (ay == by) return 0;  // horizontal segment — no crossing
	int downward = (by > ay) ? 1 : 0;
	double y_min = downward ? ay : by;
	double y_max = downward ? by : ay;
	// Point must be in [y_min, y_max) range (half-open for consistent endpoints)
	if (py < y_min || py >= y_max) return 0;
	// Check if point is to the left of the segment (ray crosses it)
	double t = (py - ay) / (by - ay);
	double x_at_t = ax + t * (bx - ax);
	if (px < x_at_t) return downward ? 1 : -1;
	return 0;
}

// Winding number contribution from a quadratic bezier curve.
// P0=(ax,ay), P1=(cx,cy) control, P2=(bx,by) anchor.
// Uses y-monotonic curve splitting for numerical stability at extrema.
// Port of Ruffle's shape_utils.rs winding_number_curve + solve_quadratic.
static int winding_number_curve(double px, double py,
    double ax, double ay, double cx, double cy, double bx, double by)
{
	// Translate so test point is at origin; ray goes along +x at y=0
	double x0 = ax - px, y0 = ay - py;
	double x1 = cx - px, y1 = cy - py;
	double x2 = bx - px, y2 = by - py;

	// Quick reject: all control points on same side of ray, or all to the left
	if ((y0 < 0.0 && y1 < 0.0 && y2 < 0.0) ||
	    (y0 > 0.0 && y1 > 0.0 && y2 > 0.0) ||
	    (x0 <= 0.0 && x1 <= 0.0 && x2 <= 0.0))
		return 0;

	// Quadratic y(t) = a*t² + b*t + c, solve y(t) = 0
	double a = y0 - 2.0*y1 + y2;
	double b = 2.0*(y1 - y0);
	double c_v = y0;

	// Solve with Citardauq root ordering: t0=ascending, t1=descending
	double t0 = 0.0/0.0, t1 = 0.0/0.0;  // NaN = invalid
	if (fabs(a) <= 1e-7) {
		// Near-linear
		if (fabs(b) < 1e-10) return 0;
		double r = -c_v / b;
		if (b >= 0.0) t1 = r; else t0 = r;
	} else {
		double disc = b*b - 4.0*a*c_v;
		if (disc < 0.0) return 0;
		disc = sqrt(disc);
		if (b >= 0.0) {
			t0 = (-b - disc) / (2.0*a);
			t1 = (-b + disc) / (2.0*a);
		} else {
			t0 = (-b - disc) / (2.0*a);
			t1 = (-b + disc) / (2.0*a);
		}
	}

	int t0_ok = isfinite(t0);
	int t1_ok = isfinite(t1);
	if (!t0_ok && !t1_ok) return 0;

	// Y-monotonic splitting: split at y-extremum t_ext = -b/(2a)
	int winding = 0;
	double qax = x0 - 2.0*x1 + x2;
	double qbx = 2.0*(x1 - x0);
	double t_ext = (fabs(a) > 1e-10) ? (-0.5 * b / a) : -1.0;
	int is_mono = (t_ext <= 0.0 || t_ext >= 1.0);

	if (a >= 0.0) {
		// Downward-opening parabola: y has a MINIMUM at t_ext
		double y_min = is_mono ? fmin(y0, y2) : (a*t_ext*t_ext + b*t_ext + c_v);

		// First subcurve: upward (ascending root t0). Ray must be in [y_min, y0)
		if (t0_ok && 0.0 >= y_min && 0.0 < y0) {
			double x = x0 + qbx*t0 + qax*t0*t0;
			if (x > 0.0) winding += 1;
		}
		// Second subcurve: downward (descending root t1). Ray must be in [y_min, y2)
		if (t1_ok && 0.0 >= y_min && 0.0 < y2) {
			double x = x0 + qbx*t1 + qax*t1*t1;
			if (x > 0.0) winding -= 1;
		}
	} else {
		// Upward-opening parabola: y has a MAXIMUM at t_ext
		double y_max = is_mono ? fmax(y0, y2) : (a*t_ext*t_ext + b*t_ext + c_v);

		// First subcurve: downward (descending root t1). Ray must be in [y0, y_max)
		if (t1_ok && 0.0 >= y0 && 0.0 < y_max) {
			double x = x0 + qbx*t1 + qax*t1*t1;
			if (x > 0.0) winding -= 1;
		}
		// Second subcurve: upward (ascending root t0). Ray must be in [y2, y_max)
		if (t0_ok && 0.0 >= y2 && 0.0 < y_max) {
			double x = x0 + qbx*t0 + qax*t0*t0;
			if (x > 0.0) winding += 1;
		}
	}

	return winding;
}

// Path-based fill hit test: test if point is inside the shape's fill paths.
// Uses winding number accumulation from path_data edges.
// Returns 1 if hit, 0 if miss.
// ---------------------------------------------------------------------------
// Stroke distance testing: closest-point-to-path for stroke hit detection
// ---------------------------------------------------------------------------

// Squared distance from point P to line segment A→B.
static double dist_sq_point_to_segment(double px, double py,
    double ax, double ay, double bx, double by)
{
	double dx = bx - ax, dy = by - ay;
	double len_sq = dx*dx + dy*dy;
	if (len_sq < 1e-10) {
		// Degenerate segment (zero length)
		double ex = px - ax, ey = py - ay;
		return ex*ex + ey*ey;
	}
	// Project P onto line AB, clamped to [0,1]
	double t = ((px - ax)*dx + (py - ay)*dy) / len_sq;
	if (t < 0.0) t = 0.0;
	if (t > 1.0) t = 1.0;
	double cx = ax + t*dx - px;
	double cy = ay + t*dy - py;
	return cx*cx + cy*cy;
}

// Squared distance from point P to quadratic bezier curve P0→P1(ctrl)→P2(anchor).
// Finds t where (P - C(t)) · C'(t) = 0 by solving a cubic, then tests endpoints.
static double dist_sq_point_to_curve(double px, double py,
    double x0, double y0, double x1, double y1, double x2, double y2)
{
	// Coefficients for C(t) = (1-t)²P0 + 2t(1-t)P1 + t²P2
	// C(t) = P0 + 2t(P1-P0) + t²(P0-2P1+P2) = P0 + t*B + t²*A
	double ax = x0 - 2.0*x1 + x2, ay_c = y0 - 2.0*y1 + y2;
	double bxc = 2.0*(x1 - x0), byc = 2.0*(y1 - y0);
	double mx = x0 - px, my = y0 - py;

	// (P - C(t)) · C'(t) = 0, where C'(t) = B + 2tA
	// Expanding: cubic in t: a3*t³ + a2*t² + a1*t + a0 = 0
	double a3 = 2.0*(ax*ax + ay_c*ay_c);
	double a2 = 3.0*(ax*bxc + ay_c*byc);
	double a1 = bxc*bxc + byc*byc + 2.0*(ax*mx + ay_c*my);
	double a0 = bxc*mx + byc*my;

	// Find minimum distance: check endpoints and all cubic roots in [0,1]
	double min_d = mx*mx + my*my;  // dist at t=0
	double e2x = x2 - px, e2y = y2 - py;
	double d_end = e2x*e2x + e2y*e2y;
	if (d_end < min_d) min_d = d_end;

	// Solve cubic a3*t³ + a2*t² + a1*t + a0 = 0
	if (fabs(a3) > 1e-10) {
		// Reduce to depressed cubic: t³ + pt + q = 0
		double inv_a3 = 1.0 / a3;
		double p = (3.0*a3*a1 - a2*a2) / (3.0*a3*a3);
		double q = (2.0*a2*a2*a2 - 9.0*a3*a2*a1 + 27.0*a3*a3*a0) / (27.0*a3*a3*a3);
		double disc = q*q/4.0 + p*p*p/27.0;
		double shift = -a2 / (3.0*a3);

		double roots[3];
		int n_roots = 0;

		if (disc > 1e-10) {
			// One real root
			double sq = sqrt(disc);
			double u = cbrt(-q/2.0 + sq);
			double v = cbrt(-q/2.0 - sq);
			roots[n_roots++] = u + v + shift;
		} else if (disc < -1e-10) {
			// Three real roots (trigonometric solution)
			double r = sqrt(-p*p*p / 27.0);
			double theta = acos(-q / (2.0*r));
			double cr = cbrt(r);
			roots[n_roots++] = 2.0*cr*cos(theta/3.0) + shift;
			roots[n_roots++] = 2.0*cr*cos((theta + 2.0*3.14159265358979323846)/3.0) + shift;
			roots[n_roots++] = 2.0*cr*cos((theta + 4.0*3.14159265358979323846)/3.0) + shift;
		} else {
			// Double or triple root
			if (fabs(q) > 1e-10) {
				double u = cbrt(-q/2.0);
				roots[n_roots++] = 2.0*u + shift;
				roots[n_roots++] = -u + shift;
			} else {
				roots[n_roots++] = shift;
			}
		}

		for (int i = 0; i < n_roots; i++) {
			double t = roots[i];
			if (t > 0.0 && t < 1.0) {
				double it = 1.0 - t;
				double cx = it*it*x0 + 2.0*it*t*x1 + t*t*x2 - px;
				double cy = it*it*y0 + 2.0*it*t*y1 + t*t*y2 - py;
				double d = cx*cx + cy*cy;
				if (d < min_d) min_d = d;
			}
		}
	} else if (fabs(a2) > 1e-10) {
		// Quadratic: a2*t² + a1*t + a0 = 0
		double disc = a1*a1 - 4.0*a2*a0;
		if (disc >= 0.0) {
			double sq = sqrt(disc);
			double r1 = (-a1 - sq) / (2.0*a2);
			double r2 = (-a1 + sq) / (2.0*a2);
			for (int i = 0; i < 2; i++) {
				double t = (i == 0) ? r1 : r2;
				if (t > 0.0 && t < 1.0) {
					double it = 1.0 - t;
					double cx = it*it*x0 + 2.0*it*t*x1 + t*t*x2 - px;
					double cy = it*it*y0 + 2.0*it*t*y1 + t*t*y2 - py;
					double d = cx*cx + cy*cy;
					if (d < min_d) min_d = d;
				}
			}
		}
	} else if (fabs(a1) > 1e-10) {
		// Linear: a1*t + a0 = 0
		double t = -a0 / a1;
		if (t > 0.0 && t < 1.0) {
			double it = 1.0 - t;
			double cx = it*it*x0 + 2.0*it*t*x1 + t*t*x2 - px;
			double cy = it*it*y0 + 2.0*it*t*y1 + t*t*y2 - py;
			double d = cx*cx + cy*cy;
			if (d < min_d) min_d = d;
		}
	}

	return min_d;
}

// Path-based stroke hit test: test if point is within stroke width of any edge.
// Returns 1 if hit, 0 if miss.
static int ng_hitTestPathStroke(size_t path_offset, size_t path_size,
    double local_x, double local_y)
{
	double cursor_x = 0.0, cursor_y = 0.0;
	double line_width = 0.0;  // full width in local coords
	int has_line = 0;

	size_t end = path_offset + path_size;
	for (size_t i = path_offset; i < end; i++) {
		float cmd = path_data[i][0];
		if (cmd == 1.0f) {
			// StyleChange fills — skip
			if (i + 1 < end && path_data[i+1][0] == 1.5f) {
				i++;
				int line_style = (int)path_data[i][1];
				line_width = (double)path_data[i][2];
				has_line = (line_style > 0 && line_width > 0.0);
				// Minimum stroke width: 1 pixel = 20 twips
				if (has_line && line_width < 20.0) line_width = 20.0;
			}
		}
		else if (cmd == 5.0f) {
			cursor_x = (double)path_data[i][1];
			cursor_y = (double)path_data[i][2];
		}
		else if (cmd == 2.0f && has_line) {
			double nx = (double)path_data[i][1], ny = (double)path_data[i][2];
			double half_w = line_width * 0.5;
			if (dist_sq_point_to_segment(local_x, local_y, cursor_x, cursor_y, nx, ny) <= half_w * half_w)
				return 1;
			cursor_x = nx; cursor_y = ny;
		}
		else if (cmd == 2.0f) {
			cursor_x = (double)path_data[i][1]; cursor_y = (double)path_data[i][2];
		}
		else if (cmd == 3.0f && i + 1 < end) {
			double cx = (double)path_data[i][1], cy = (double)path_data[i][2];
			i++;
			double nx = (double)path_data[i][1], ny = (double)path_data[i][2];
			if (has_line) {
				double half_w = line_width * 0.5;
				if (dist_sq_point_to_curve(local_x, local_y, cursor_x, cursor_y, cx, cy, nx, ny) <= half_w * half_w)
					return 1;
			}
			cursor_x = nx; cursor_y = ny;
		}
		else if (cmd == 0.0f) break;
	}
	return 0;
}

static int ng_hitTestPathFill(size_t char_id, size_t path_offset, size_t path_size,
    double local_x, double local_y)
{
	// Accumulate winding numbers per fill style
	// (SWF shapes have few fill styles, typically < 10)
	int fill_winding[64] = {0};
	int max_fill = 0;

	int cur_fill0 = 0, cur_fill1 = 0;
	double cursor_x = 0.0, cursor_y = 0.0;

	size_t end = path_offset + path_size;
	for (size_t i = path_offset; i < end; i++) {
		float cmd = path_data[i][0];

		if (cmd == 1.0f) {
			// StyleChange: {1, fill0, fill1}
			cur_fill0 = (int)path_data[i][1];
			cur_fill1 = (int)path_data[i][2];
			if (cur_fill0 > max_fill) max_fill = cur_fill0;
			if (cur_fill1 > max_fill) max_fill = cur_fill1;
			// Skip line style entry (1.5)
			if (i + 1 < end && path_data[i+1][0] == 1.5f) i++;
		}
		else if (cmd == 5.0f) {
			// MoveTo: {5, x, y}
			cursor_x = (double)path_data[i][1];
			cursor_y = (double)path_data[i][2];
		}
		else if (cmd == 2.0f) {
			// LineTo: {2, x, y}
			double nx = (double)path_data[i][1];
			double ny = (double)path_data[i][2];

			// fill1 (left fill): forward direction
			if (cur_fill1 > 0 && cur_fill1 < 64) {
				fill_winding[cur_fill1] += winding_number_line(local_x, local_y,
					cursor_x, cursor_y, nx, ny);
			}
			// fill0 (right fill): negate forward winding (NOT reverse arguments,
			// because reversing shifts endpoints between t=0/t=1, breaking half-open interval)
			if (cur_fill0 > 0 && cur_fill0 < 64) {
				fill_winding[cur_fill0] -= winding_number_line(local_x, local_y,
					cursor_x, cursor_y, nx, ny);
			}
			cursor_x = nx;
			cursor_y = ny;
		}
		else if (cmd == 3.0f && i + 1 < end) {
			// CurveTo: {3, ctrl_x, ctrl_y} + {4, anchor_x, anchor_y}
			double cx = (double)path_data[i][1];
			double cy = (double)path_data[i][2];
			i++;
			double nx = (double)path_data[i][1];
			double ny = (double)path_data[i][2];

			if (cur_fill1 > 0 && cur_fill1 < 64) {
				fill_winding[cur_fill1] += winding_number_curve(local_x, local_y,
					cursor_x, cursor_y, cx, cy, nx, ny);
			}
			if (cur_fill0 > 0 && cur_fill0 < 64) {
				fill_winding[cur_fill0] -= winding_number_curve(local_x, local_y,
					cursor_x, cursor_y, cx, cy, nx, ny);
			}
			cursor_x = nx;
			cursor_y = ny;
		}
		else if (cmd == 0.0f) {
			break;  // End
		}
	}

	// Check if point is inside any fill
	int nonzero = ng_uses_nonzero_winding(char_id);
	for (int f = 1; f <= max_fill && f < 64; f++) {
		if (nonzero) {
			if (fill_winding[f] != 0) return 1;
		} else {
			if ((fill_winding[f] & 1) != 0) return 1;
		}
	}
	return 0;
}

// Morph path hit test: walks interleaved path data, interpolates by ratio, tests fills + strokes.
// Interleaved format: geometric/line-width entries are followed by {9.0, end_a, end_b}.
static int ng_hitTestMorphPath(size_t char_id, size_t path_offset, size_t path_size,
    double local_x, double local_y, u16 ratio)
{
	double t = (double)ratio / 65535.0;
	double ot = 1.0 - t;

	int fill_winding[64] = {0};
	int max_fill = 0;
	int cur_fill0 = 0, cur_fill1 = 0;
	double line_width = 0.0;
	int has_line = 0;
	double cursor_x = 0.0, cursor_y = 0.0;
	int stroke_hit = 0;

	size_t i = path_offset;
	size_t end = path_offset + path_size;

	while (i < end) {
		float cmd = path_data[i][0];

		if (cmd == 0.0f) break;

		if (cmd == 1.0f) {
			// StyleChange fills (no interpolation)
			cur_fill0 = (int)path_data[i][1];
			cur_fill1 = (int)path_data[i][2];
			if (cur_fill0 > max_fill) max_fill = cur_fill0;
			if (cur_fill1 > max_fill) max_fill = cur_fill1;
			i++;
			continue;
		}

		if (cmd == 1.5f) {
			// StyleChange line (start width)
			int line_style = (int)path_data[i][1];
			double start_w = (double)path_data[i][2];
			i++;
			// Read morph end width (cmd == 9.0)
			double end_w = start_w;
			if (i < end && path_data[i][0] == 9.0f) {
				end_w = (double)path_data[i][2];
				i++;
			}
			line_width = ot * start_w + t * end_w;
			has_line = (line_style > 0);
			if (has_line && line_width < 20.0) line_width = 20.0;
			continue;
		}

		if (cmd == 5.0f) {
			// MoveTo (start)
			double sx = (double)path_data[i][1], sy = (double)path_data[i][2];
			i++;
			double ex = sx, ey = sy;
			if (i < end && path_data[i][0] == 9.0f) {
				ex = (double)path_data[i][1]; ey = (double)path_data[i][2];
				i++;
			}
			cursor_x = ot * sx + t * ex;
			cursor_y = ot * sy + t * ey;
			continue;
		}

		if (cmd == 2.0f) {
			// LineTo (start)
			double sx = (double)path_data[i][1], sy = (double)path_data[i][2];
			i++;
			double ex = sx, ey = sy;
			if (i < end && path_data[i][0] == 9.0f) {
				ex = (double)path_data[i][1]; ey = (double)path_data[i][2];
				i++;
			}
			double nx = ot * sx + t * ex;
			double ny = ot * sy + t * ey;

			// Fill winding
			int w = winding_number_line(local_x, local_y, cursor_x, cursor_y, nx, ny);
			if (cur_fill1 > 0 && cur_fill1 < 64) fill_winding[cur_fill1] += w;
			if (cur_fill0 > 0 && cur_fill0 < 64) fill_winding[cur_fill0] -= w;

			// Stroke
			if (has_line && !stroke_hit) {
				double half_w = line_width * 0.5;
				if (dist_sq_point_to_segment(local_x, local_y, cursor_x, cursor_y, nx, ny) <= half_w * half_w)
					stroke_hit = 1;
			}

			cursor_x = nx;
			cursor_y = ny;
			continue;
		}

		if (cmd == 3.0f) {
			// CurveTo control (start)
			double scx = (double)path_data[i][1], scy = (double)path_data[i][2];
			i++;
			double ecx = scx, ecy = scy;
			if (i < end && path_data[i][0] == 9.0f) {
				ecx = (double)path_data[i][1]; ecy = (double)path_data[i][2];
				i++;
			}
			double ctrl_x = ot * scx + t * ecx;
			double ctrl_y = ot * scy + t * ecy;

			// Expect anchor (cmd == 4.0)
			if (i >= end || path_data[i][0] != 4.0f) { continue; }
			double sax = (double)path_data[i][1], say = (double)path_data[i][2];
			i++;
			double eax = sax, eay = say;
			if (i < end && path_data[i][0] == 9.0f) {
				eax = (double)path_data[i][1]; eay = (double)path_data[i][2];
				i++;
			}
			double anchor_x = ot * sax + t * eax;
			double anchor_y = ot * say + t * eay;

			// Fill winding
			int w = winding_number_curve(local_x, local_y, cursor_x, cursor_y, ctrl_x, ctrl_y, anchor_x, anchor_y);
			if (cur_fill1 > 0 && cur_fill1 < 64) fill_winding[cur_fill1] += w;
			if (cur_fill0 > 0 && cur_fill0 < 64) fill_winding[cur_fill0] -= w;

			// Stroke
			if (has_line && !stroke_hit) {
				double half_w = line_width * 0.5;
				if (dist_sq_point_to_curve(local_x, local_y, cursor_x, cursor_y, ctrl_x, ctrl_y, anchor_x, anchor_y) <= half_w * half_w)
					stroke_hit = 1;
			}

			cursor_x = anchor_x;
			cursor_y = anchor_y;
			continue;
		}

		i++;  // skip unknown
	}

	// Check fills
	int nonzero = ng_uses_nonzero_winding(char_id);
	for (int f = 1; f <= max_fill && f < 64; f++) {
		if (nonzero) {
			if (fill_winding[f] != 0) return 1;
		} else {
			if ((fill_winding[f] & 1) != 0) return 1;
		}
	}

	return stroke_hit;
}

static int pit(double px, double py,
               double ax, double ay, double bx, double by, double cx, double cy)
{
	double d1 = (px - bx) * (ay - by) - (ax - bx) * (py - by);
	double d2 = (px - cx) * (by - cy) - (bx - cx) * (py - cy);
	double d3 = (px - ax) * (cy - ay) - (cx - ax) * (py - ay);
	int has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	int has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	if (has_neg && has_pos) return 0;

	// Check for shared-edge case: if exactly one d is zero, the point is
	// on a triangle edge. Use a fill rule to assign it to exactly one of
	// the two triangles sharing that edge, preventing double-counting that
	// breaks even-odd winding on earcut bridge edges.
	int zeros = (d1 == 0.0) + (d2 == 0.0) + (d3 == 0.0);
	if (zeros == 1) {
		// Identify the edge: d1=0 → edge AB, d2=0 → edge BC, d3=0 → edge CA
		double ex, ey;
		if (d1 == 0.0) { ex = bx - ax; ey = by - ay; }
		else if (d2 == 0.0) { ex = cx - bx; ey = cy - by; }
		else { ex = ax - cx; ey = ay - cy; }
		// Include if edge goes upward (ey > 0) or rightward when horizontal
		if (ey > 0.0) return 1;
		if (ey < 0.0) return 0;
		return (ex > 0.0) ? 1 : 0;
	}

	return 1;  // Strictly inside or on a vertex
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
	// EditText (text field): hit test against bounds rectangle
	int tf_idx = ng_find_textfield(char_id);
	if (tf_idx >= 0) {
		double det = ma * md - mb * mc_m;
		if (det == 0.0) return 0;
		double inv_det = 1.0 / det;
		double sx = test_x - mtx;
		double sy = test_y - mty;
		double local_x = ( md * sx - mc_m * sy) * inv_det;
		double local_y = (-mb * sx + ma  * sy) * inv_det;
		s32 _htfxmin, _htfxmax, _htfymin, _htfymax;
		ng_getTextFieldBounds(tf_idx, &_htfxmin, &_htfxmax, &_htfymin, &_htfymax);
		double xmin = (double)_htfxmin;
		double xmax = (double)_htfxmax;
		double ymin = (double)_htfymin;
		double ymax = (double)_htfymax;
		return (local_x >= xmin && local_x <= xmax && local_y >= ymin && local_y <= ymax);
	}

	Character* ch = &dictionary[char_id];

	// Static text (DefineText/DefineText2): per-glyph hit testing
	if (ch->type == CHAR_TYPE_TEXT) {
		size_t ts = ch->text_start;
		size_t tc = ch->text_size;
		u32 tf_base = ch->transform_start;
		for (size_t j = 0; j < tc; j++) {
			// glyph_data: 4 values per glyph (tri_offset, tri_size, path_offset, path_size)
			size_t gi = 4 * (size_t)text_data[ts + j];
			size_t glyph_offset = (size_t)glyph_data[gi][0];
			size_t glyph_size = (size_t)glyph_data[gi + 1][0];
			size_t glyph_path_offset = (size_t)glyph_data[gi + 2][0];
			size_t glyph_path_size = (size_t)glyph_data[gi + 3][0];
			if (glyph_size < 3 && glyph_path_size < 3) continue;  // no data
			// Compose parent matrix with glyph positioning transform
			u32 gtid = tf_base + (u32)j;
			double ga = (double)transform_data[gtid][0];
			double gb = (double)transform_data[gtid][1];
			double gc = (double)transform_data[gtid][4];
			double gd = (double)transform_data[gtid][5];
			double gtx_v = (double)transform_data[gtid][12];
			double gty_v = (double)transform_data[gtid][13];
			double na = ma*ga + mc_m*gb, nb = mb*ga + md*gb;
			double nc = ma*gc + mc_m*gd, nd = mb*gc + md*gd;
			double ntx = ma*gtx_v + mc_m*gty_v + mtx;
			double nty = mb*gtx_v + md*gty_v + mty;
			// Inverse transform test point to glyph-local space
			double det = na * nd - nb * nc;
			if (det == 0.0) continue;
			double inv_det = 1.0 / det;
			double sx = test_x - ntx;
			double sy = test_y - nty;
			double local_x = ( nd * sx - nc * sy) * inv_det;
			double local_y = (-nb * sx + na * sy) * inv_det;
			// Try path-based glyph hit test first (exact curves)
			if (glyph_path_size >= 3) {
				// Font glyphs use non-zero winding (TTF convention)
				int glyph_winding = 0;
				double g_cursor_x = 0, g_cursor_y = 0;
				int g_fill1 = 0;
				for (size_t pi = glyph_path_offset; pi < glyph_path_offset + glyph_path_size; pi++) {
					float pcmd = path_data[pi][0];
					if (pcmd == 1.0f) { g_fill1 = (int)path_data[pi][2]; if (pi+1 < glyph_path_offset+glyph_path_size && path_data[pi+1][0]==1.5f) pi++; }
					else if (pcmd == 5.0f) { g_cursor_x = (double)path_data[pi][1]; g_cursor_y = (double)path_data[pi][2]; }
					else if (pcmd == 2.0f && g_fill1) {
						double gnx = (double)path_data[pi][1], gny = (double)path_data[pi][2];
						glyph_winding += winding_number_line(local_x, local_y, g_cursor_x, g_cursor_y, gnx, gny);
						g_cursor_x = gnx; g_cursor_y = gny;
					}
					else if (pcmd == 3.0f && pi+1 < glyph_path_offset+glyph_path_size && g_fill1) {
						double gcx = (double)path_data[pi][1], gcy = (double)path_data[pi][2];
						pi++;
						double gnx = (double)path_data[pi][1], gny = (double)path_data[pi][2];
						glyph_winding += winding_number_curve(local_x, local_y, g_cursor_x, g_cursor_y, gcx, gcy, gnx, gny);
						g_cursor_x = gnx; g_cursor_y = gny;
					}
					else if (pcmd == 0.0f) break;
				}
				if (glyph_winding != 0) return 1;  // non-zero winding = inside glyph
				continue;  // path test is authoritative, skip triangle fallback
			}
			// Fallback: test against glyph triangles
			size_t num_tris = glyph_size / 3;
			for (size_t t = 0; t < num_tris; t++) {
				const u32* v0 = shape_data[glyph_offset + t*3 + 0];
				const u32* v1 = shape_data[glyph_offset + t*3 + 1];
				const u32* v2 = shape_data[glyph_offset + t*3 + 2];
				double ax = (double)*(const float*)&v0[0];
				double ay = (double)*(const float*)&v0[1];
				double bx = (double)*(const float*)&v1[0];
				double by = (double)*(const float*)&v1[1];
				double cx = (double)*(const float*)&v2[0];
				double cy = (double)*(const float*)&v2[1];
				if (pit(local_x, local_y, ax, ay, bx, by, cx, cy))
					return 1;
			}
		}
		return 0;
	}

	int is_morph = (ch->type == CHAR_TYPE_MORPH_SHAPE);
	if (ch->type != CHAR_TYPE_SHAPE && !is_morph) return 0;

	// Morph shapes: try path-based hit testing first, fall back to bounds
	if (is_morph) {
		size_t mp_offset, mp_size;
		if (ng_find_morph_path(char_id, &mp_offset, &mp_size)) {
			double det = ma * md - mb * mc_m;
			if (det == 0.0) return 0;
			double inv_det = 1.0 / det;
			double bsx = test_x - mtx;
			double bsy = test_y - mty;
			double local_x = ( md * bsx - mc_m * bsy) * inv_det;
			double local_y = (-mb * bsx + ma  * bsy) * inv_det;
			return ng_hitTestMorphPath(char_id, mp_offset, mp_size, local_x, local_y, ratio);
		}
		// Fallback: interpolated bounds-based hit testing
		s32 bxmin, bxmax, bymin, bymax;
		if (ng_getCharBoundsForRatio(char_id, ratio, &bxmin, &bxmax, &bymin, &bymax)) {
			double det = ma * md - mb * mc_m;
			if (det == 0.0) return 0;
			double inv_det = 1.0 / det;
			double bsx = test_x - mtx;
			double bsy = test_y - mty;
			double local_x = ( md * bsx - mc_m * bsy) * inv_det;
			double local_y = (-mb * bsx + ma  * bsy) * inv_det;
			return (local_x >= (double)bxmin && local_x <= (double)bxmax &&
			        local_y >= (double)bymin && local_y <= (double)bymax);
		}
		return 0;
	}

	// Vector-path hit testing for fills and strokes
	{
		size_t p_offset, p_size;
		if (ng_find_char_path(char_id, &p_offset, &p_size)) {
			double det = ma * md - mb * mc_m;
			if (det == 0.0) return 0;
			double inv_det = 1.0 / det;
			double sx = test_x - mtx;
			double sy = test_y - mty;
			double local_x = ( md * sx - mc_m * sy) * inv_det;
			double local_y = (-mb * sx + ma  * sy) * inv_det;
			if (ng_hitTestPathFill(char_id, p_offset, p_size, local_x, local_y))
				return 1;
			if (ng_hitTestPathStroke(p_offset, p_size, local_x, local_y))
				return 1;
			// Path test is authoritative when available — skip triangle fallback
			return 0;
		}
	}

	size_t offset = ch->shape_offset;
	size_t count = ch->size;
	if (count < 3) return 0;

	// Inverse-transform test point into shape's local space
	double det = ma * md - mb * mc_m;
	if (det == 0.0) return 0;
	double inv_det = 1.0 / det;
	double sx = test_x - mtx;
	double sy = test_y - mty;
	double local_x = ( md * sx - mc_m * sy) * inv_det;
	double local_y = (-mb * sx + ma  * sy) * inv_det;

	// Count triangle hits separately for fills and strokes.
	// Stroke triangles (marked with bit 31 in column 2) use non-zero winding
	// because overlapping strokes at intersections should be unioned.
	// Fill triangles use even-odd winding (unless DefineShape4 nonzero flag).
	int fill_hits = 0;
	int stroke_hits = 0;
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

		if (pit(local_x, local_y, ax, ay, bx, by, cx, cy)) {
			if (v0[2] & 0x80000000)
				stroke_hits++;
			else
				fill_hits++;
		}
	}

	if (stroke_hits > 0) return 1;  // strokes always use non-zero (union)
	if (ng_uses_nonzero_winding(char_id))
		return fill_hits > 0;  // non-zero: any hit means inside
	return (fill_hits % 2) == 1;  // even-odd: odd count = inside
}

int ng_hitTestShapeFromDL(DisplayObject* dl, size_t dl_max,
    double ma, double mb, double mc_m, double md, double mtx, double mty,
    double test_x, double test_y)
{
	size_t clip_depth_end = 0;  // if >0, masking active until this depth
	int clip_hit = 0;           // whether test point hits the current clip shape

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

		// Clip-depth masking: this child is a clipping layer
		if (child->clip_depth > 0) {
			int mask_hit = 0;
			if (child->sprite_display_list != NULL && child->sprite_max_depth > 0) {
				mask_hit = ng_hitTestShapeFromDL(child->sprite_display_list, child->sprite_max_depth,
					na, nb, nc, nd, ntx, nty, test_x, test_y);
			}
			if (!mask_hit) {
				mask_hit = ng_hitTestShapeChar(child->char_id, child->ratio, na, nb, nc, nd, ntx, nty,
					test_x, test_y);
			}
			if (mask_hit) {
				clip_depth_end = 0;  // point hits mask: deactivate masking
			} else {
				clip_depth_end = child->clip_depth;  // point misses mask: activate
			}
			continue;  // clip layers are never directly hittable
		}

		// If masking is active and this child is within the masked range, skip it
		if (clip_depth_end > 0) {
			if (i <= clip_depth_end) continue;  // masked out
			clip_depth_end = 0;  // past the clip region
		}

		if (child->sprite_display_list != NULL && child->sprite_max_depth > 0) {
			if (ng_hitTestShapeFromDL(child->sprite_display_list, child->sprite_max_depth,
				na, nb, nc, nd, ntx, nty, test_x, test_y))
				return 1;
			// Sprites that are also textfields (EditText with MC association):
			// if recursive display list test fails, test textfield bounds
			if (ng_hitTestShapeChar(child->char_id, child->ratio, na, nb, nc, nd, ntx, nty,
				test_x, test_y))
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
// TextField property accessors (display-list-dependent, kept in tag_stubs.c)
// ---------------------------------------------------------------------------

const char* ng_getTextFieldInitialText(size_t depth)
{
	if (depth > max_depth || display_list[depth].char_id == 0) return "";
	int tf_idx = ng_find_textfield(display_list[depth].char_id);
	if (tf_idx < 0) return "";
	return ng_getTextFieldInitialTextByIdx(tf_idx);
}

u32 ng_getTextFieldColor(size_t depth)
{
	if (depth > max_depth || display_list[depth].char_id == 0) return 0;
	int tf_idx = ng_find_textfield(display_list[depth].char_id);
	if (tf_idx < 0) return 0;
	return ng_getTextFieldColorByIdx(tf_idx);
}

int ng_getTextFieldIdx(size_t depth)
{
	if (depth > max_depth || display_list[depth].char_id == 0) return -1;
	return ng_find_textfield(display_list[depth].char_id);
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
			// Ensure capacity — use HCALLOC/FREE because display_list may be
			// from the custom heap allocator (timeline sprites use HCALLOC).
			if (target_swf_depth >= display_list_capacity)
			{
				size_t new_cap = target_swf_depth + 64;
				DisplayObject* new_dl = HCALLOC(new_cap, sizeof(DisplayObject));
				if (new_dl) {
					memcpy(new_dl, display_list, display_list_capacity * sizeof(DisplayObject));
					FREE(display_list);
					display_list = new_dl;
					display_list_capacity = new_cap;
				}
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
		if (display_list[src_depth].clip_action_count > 0)
		{
			ng_queue_pending_load(target_name,
				display_list[src_depth].clip_actions,
				display_list[src_depth].clip_action_count);
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
		clone_mc->draw_has_bounds = src_mc->draw_has_bounds;
		clone_mc->draw_xmin = src_mc->draw_xmin;
		clone_mc->draw_xmax = src_mc->draw_xmax;
		clone_mc->draw_ymin = src_mc->draw_ymin;
		clone_mc->draw_ymax = src_mc->draw_ymax;
		// Inherit the source's TextSnapshot stale flag BEFORE marking the
		// source itself. In Ruffle, clone_sprite via instantiate_by_id
		// produces an instance whose TextSnapshot availability mirrors its
		// source, so cloning an already-stale source yields a clone that
		// is born stale — matches avm1/textsnapshot_available_text.
		clone_mc->ts_stale_source = src_mc->ts_stale_source;
		// Mark source as "used as dup source" so later `new TextSnapshot(src)`
		// calls reject it (Ruffle's as_movie_clip() returns None for these
		// after clone).
		src_mc->ts_stale_source = 1;
	}
	clone_mc->currentframe = 1;
	clone_mc->depth = depth;

	// For dynamic textfield clones (no DefineEditText tag), init default props
	if (src_mc != NULL && src_mc->ng_textfield_idx == -2 && clone_mc->ng_textfield_idx != -2) {
		actionInitDynTextFieldClone(app_context, clone_mc);
		// If source has active autoSize, restore clone to original createTextField position
		if (src_mc->dynamic_props != NULL && clone_mc->dynamic_props != NULL) {
			ASObject* _src_p = (ASObject*) src_mc->dynamic_props;
			ASObject* _cln_p = (ASObject*) clone_mc->dynamic_props;
			ActionVar* cx = getProperty(_src_p, "_tf_createX", 11);
			ActionVar* cy = getProperty(_src_p, "_tf_createY", 11);
			if (cx) setProperty(app_context, _cln_p, "_tf_createX", 11, cx);
			if (cy) setProperty(app_context, _cln_p, "_tf_createY", 11, cy);
			ActionVar* as_prop = getProperty(_src_p, "autoSize", 8);
			int has_autosize = 0;
			if (as_prop && as_prop->type == ACTION_STACK_VALUE_STRING && as_prop->str_size > 0) {
				// Check if autoSize != "none" by comparing UTF-16 directly
				const uint16_t* as_u16 = (const uint16_t*)(uintptr_t)as_prop->data.numeric_value;
				int is_none = (as_prop->str_size == 4 &&
					as_u16[0] == 'n' && as_u16[1] == 'o' &&
					as_u16[2] == 'n' && as_u16[3] == 'e');
				if (!is_none) has_autosize = 1;
			}
			if (has_autosize) {
				if (cx && cx->type == ACTION_STACK_VALUE_F64) {
					double ox; memcpy(&ox, &cx->data.numeric_value, sizeof(double));
					clone_mc->x = (float)ox;
				}
				if (cy && cy->type == ACTION_STACK_VALUE_F64) {
					double oy; memcpy(&oy, &cy->data.numeric_value, sizeof(double));
					clone_mc->y = (float)oy;
				}
			}
		}
	}

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

				// Phase 7b note: do NOT bump eager here. Pre-7b skipped scripts
				// during ng_cloneSprite (catch_up_mode=1 + old `if (!catch_up_mode) script_N` gate).
				// Under 7b gate, this stays equivalent: catch=1, eager=0 → queue path FALSE,
				// sync path FALSE. Matches pre-7b behavior.
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

	// Look up source display entry — needed for display list copy & clip_actions
	size_t src_depth = ng_findDisplayEntryByName(src_mc->name);

	// Create display list entry for the clone (mirrors ng_cloneSprite logic).
	// This is critical for textfield clones: actionFindOrCreateMovieClip needs
	// the display entry to detect the textfield char_id and init properties.
	size_t target_swf_depth = (size_t)depth;
	if (src_depth != SIZE_MAX && target_swf_depth < INITIAL_DISPLAYLIST_CAPACITY)
	{
		// Pre-clear target depth if occupied
		if (target_swf_depth >= 1 && target_swf_depth <= max_depth &&
		    display_list[target_swf_depth].char_id != 0)
		{
			ng_on_remove_object(app_context, target_swf_depth);
			if (display_list[target_swf_depth].instance_name_owned &&
			    display_list[target_swf_depth].instance_name != NULL)
			{
				free(display_list[target_swf_depth].instance_name);
				display_list[target_swf_depth].instance_name_owned = 0;
				display_list[target_swf_depth].instance_name = NULL;
			}
		}
		// Ensure capacity — use HCALLOC/FREE because display_list may be
		// from the custom heap allocator (timeline sprites use HCALLOC).
		if (target_swf_depth >= display_list_capacity)
		{
			size_t new_cap = target_swf_depth + 64;
			DisplayObject* new_dl = HCALLOC(new_cap, sizeof(DisplayObject));
			if (new_dl) {
				memcpy(new_dl, display_list, display_list_capacity * sizeof(DisplayObject));
				FREE(display_list);
				display_list = new_dl;
			}
			display_list_capacity = new_cap;
		}
		display_list[target_swf_depth] = display_list[src_depth];
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
	clone_mc->draw_has_bounds = src_mc->draw_has_bounds;
	clone_mc->draw_xmin = src_mc->draw_xmin;
	clone_mc->draw_xmax = src_mc->draw_xmax;
	clone_mc->draw_ymin = src_mc->draw_ymin;
	clone_mc->draw_ymax = src_mc->draw_ymax;
	// Inherit the source's TextSnapshot stale flag BEFORE marking the source.
	// See ng_cloneSprite for rationale (avm1/textsnapshot_available_text).
	clone_mc->ts_stale_source = src_mc->ts_stale_source;
	src_mc->ts_stale_source = 1;
	clone_mc->currentframe = 1;
	clone_mc->depth = depth;

	// For dynamic textfield clones (src has ng_textfield_idx == -2 but no DefineEditText tag),
	// actionFindOrCreateMovieClip won't detect the textfield from the display list.
	// Initialize default textfield properties manually.
	if (src_mc->ng_textfield_idx == -2 && clone_mc->ng_textfield_idx != -2) {
		actionInitDynTextFieldClone(app_context, clone_mc);
		if (src_mc->dynamic_props != NULL && clone_mc->dynamic_props != NULL) {
			ASObject* src_props = (ASObject*) src_mc->dynamic_props;
			ASObject* clone_props = (ASObject*) clone_mc->dynamic_props;
			// Copy "type" property from source (preserved for clones)
			ActionVar* type_prop = getProperty(src_props, "type", 4);
			if (type_prop != NULL && type_prop->type != ACTION_STACK_VALUE_UNDEFINED) {
				setProperty(app_context, clone_props, "type", 4, type_prop);
			}
			// Copy original createTextField position to clone's properties
			ActionVar* cx_prop = getProperty(src_props, "_tf_createX", 11);
			ActionVar* cy_prop = getProperty(src_props, "_tf_createY", 11);
			if (cx_prop) setProperty(app_context, clone_props, "_tf_createX", 11, cx_prop);
			if (cy_prop) setProperty(app_context, clone_props, "_tf_createY", 11, cy_prop);
			// If source has active autoSize (not "none"), restore clone position
			// to original createTextField coordinates (source mc->x was modified by autoSize)
			ActionVar* as_prop = getProperty(src_props, "autoSize", 8);
			int has_autosize = 0;
			if (as_prop && as_prop->type == ACTION_STACK_VALUE_STRING && as_prop->str_size > 0) {
				// Check if autoSize != "none" by comparing UTF-16 directly
				const uint16_t* as_u16 = (const uint16_t*)(uintptr_t)as_prop->data.numeric_value;
				int is_none = (as_prop->str_size == 4 &&
					as_u16[0] == 'n' && as_u16[1] == 'o' &&
					as_u16[2] == 'n' && as_u16[3] == 'e');
				if (!is_none) has_autosize = 1;
			}
			if (has_autosize) {
				if (cx_prop && cx_prop->type == ACTION_STACK_VALUE_F64) {
					double ox; memcpy(&ox, &cx_prop->data.numeric_value, sizeof(double));
					clone_mc->x = (float)ox;
				}
				if (cy_prop && cy_prop->type == ACTION_STACK_VALUE_F64) {
					double oy; memcpy(&oy, &cy_prop->data.numeric_value, sizeof(double));
					clone_mc->y = (float)oy;
				}
			}
		}
	}

	// Textfield clones reset _visible to true (unlike sprite clones which preserve it)
	if (clone_mc->ng_textfield_idx >= 0 || clone_mc->ng_textfield_idx == -2) {
		clone_mc->visible = 1;
	}

	// CloneSprite fires onLoad for the clone — look up source's clip_actions by name
	if (src_depth != SIZE_MAX && display_list[src_depth].clip_action_count > 0)
	{
		ng_queue_pending_load(target_name,
			display_list[src_depth].clip_actions,
			display_list[src_depth].clip_action_count);
	}

	// Evict any old clone at this SWF depth, then register new one
	clone_depth_register(depth, target_name);

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
		// Drawing-API bounds — cloning a dynamically-built MC (createEmptyMovieClip
		// + lineTo/beginFill) must preserve the source's accumulated bounds, since
		// the clone is born empty and mcGetOriginalBounds would otherwise fall
		// through to the child-MC bounds walk (and the clone has no children).
		clone_mc->draw_has_bounds = src_mc->draw_has_bounds;
		clone_mc->draw_xmin = src_mc->draw_xmin;
		clone_mc->draw_xmax = src_mc->draw_xmax;
		clone_mc->draw_ymin = src_mc->draw_ymin;
		clone_mc->draw_ymax = src_mc->draw_ymax;
		// Inherit the source's TextSnapshot stale flag BEFORE marking the
		// source itself. Ruffle's clone_sprite via instantiate_by_id
		// produces an instance whose TextSnapshot availability tracks the
		// same state as its source, so a clone from an already-stale
		// source (one that has itself been used as a dup source) is born
		// stale — matches avm1/textsnapshot_available_text expectations.
		clone_mc->ts_stale_source = src_mc->ts_stale_source;
		// Mark the source as "used as dup source" so subsequent
		// `new TextSnapshot(src)` calls reject it.
		src_mc->ts_stale_source = 1;
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

				// Phase 7b note: no eager bump (see ng_cloneSprite for rationale).
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

#ifndef HEADLESS_GRAPHICS
// In HEADLESS_GRAPHICS mode, tag.c provides real implementations that call
// the renderer. These stubs are only needed in pure NO_GRAPHICS mode.
void defineBitmap(size_t offset, size_t size, u32 width, u32 height, u16 char_id)
{
	// Register metadata so BitmapData.loadBitmap can resolve dimensions/offsets
	// even when the renderer is absent (NO_GRAPHICS builds).
	ng_registerBitmapMetadata(char_id, offset, size, width, height);
}

void finalizeBitmaps(void)
{
}
#endif

void tagDefineSound(SWFAppContext* app_context, u16 sound_id,
	u8 format, u8 rate, u8 sample_size, u8 stereo,
	u32 sample_count, const u8* data, size_t data_size)
{
	(void)app_context; (void)format; (void)sample_size; (void)stereo;
	(void)data; (void)data_size;
	// Store metadata for attachSound/getDuration
	ng_registerSoundMetadata(sound_id, rate, sample_count);
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

#endif // NO_GRAPHICS || HEADLESS_GRAPHICS
