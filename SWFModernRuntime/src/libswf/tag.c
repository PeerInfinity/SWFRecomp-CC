#include <swf.h>
#include <tag.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <utils.h>
#include <heap.h>
#include <hit_test.h>

#ifndef NO_GRAPHICS
#include <renderer.h>
extern RenderContext* context;
#else
// NO_GRAPHICS: extern data arrays from generated code
extern float transform_data[][16];
extern float cxform_data[];
extern int catch_up_mode;
extern int g_tag_skip_mode;
#include <action.h>
#endif

size_t dictionary_capacity = INITIAL_DICTIONARY_CAPACITY;
size_t display_list_capacity = INITIAL_DISPLAYLIST_CAPACITY;

// Note: tagInit() is provided by the generated tagMain.c file

#ifdef NO_GRAPHICS
// Tracks the currently-executing sprite's DisplayObject.
// Set by advance_sprite_frames before each sprite frame function call.
DisplayObject* g_current_sprite_obj = NULL;

// When 1, tagPlaceObject2 and tagSetInstanceName are no-ops.
// Used by tagShowFrame to re-run sprite frame_0 for scripts only (Phase 2),
// without disturbing the display list already set up in Phase 1 (eager init).
static int g_script_only_mode = 0;

// Monotonically increasing counter to detect within-same-frame placement conflicts.
// Incremented at the end of each tagShowFrame call and before goto catch-up.
size_t g_place_gen = 0;

// When 1, tagShowFrame defers process_sprite_needs_init.
// Set by ng_executeGotoCatchUp so sprite init scripts run AFTER the deferred
// parent-frame DoAction (matching Ruffle's execution order).
int g_defer_sprite_init = 0;

// Frame filter for process_sprite_needs_init during deferred init.
// When g_sprite_init_filter_active=1, only process sprites matching the filter:
//   g_sprite_init_before_target=1: only placed_at_frame < g_sprite_init_target_frame
//   g_sprite_init_before_target=0: only placed_at_frame >= g_sprite_init_target_frame
static int g_sprite_init_filter_active = 0;
static int g_sprite_init_before_target = 0;
static size_t g_sprite_init_target_frame = 0;

// g_settarget_explicit_root: set by actionSetTarget("_root"/"") to distinguish
// "goto root" from "goto unnamed sprite with inherited root context".
// Declared in action.c; saved/cleared/restored here per sprite-frame invocation.
extern int g_settarget_explicit_root;
extern int g_settarget_invalid;
extern int g_settarget_none;
extern MovieClip* g_current_context;
extern void actionSetCurrentContext(MovieClip* mc);

// Execute a sprite frame function with correct MC context and g_current_sprite_obj.
static void exec_sprite_frame(SWFAppContext* app_context, DisplayObject* obj, frame_func f)
{
	DisplayObject* saved = g_current_sprite_obj;
	g_current_sprite_obj = obj;

	MovieClip* saved_ctx = g_current_context;
	MovieClip* saved_base = actionGetBaseClip();
	if (obj->instance_name != NULL)
	{
		// Find existing MC (no creation) to avoid spurious auto-named MC entries
		// during advance_sprite_frames display-list loop-back re-execution.
		extern MovieClip* actionFindMovieClipByName(const char* instance_name);
		MovieClip* mc = actionFindMovieClipByName(obj->instance_name);
		if (mc) { mc->display_obj = (void*)obj; actionSetCurrentContext(mc); actionSetBaseClip(mc); }
	}

	// Each sprite frame starts with a fresh SetTarget state (no explicit root target)
	int saved_settarget = g_settarget_explicit_root;
	int saved_invalid = g_settarget_invalid;
	int saved_none = g_settarget_none;
	g_settarget_explicit_root = 0;
	g_settarget_invalid = 0;
	g_settarget_none = 0;

	f(app_context);

	g_settarget_explicit_root = saved_settarget;
	g_settarget_invalid = saved_invalid;
	g_settarget_none = saved_none;
	actionSetCurrentContext(saved_ctx);
	actionSetBaseClip(saved_base);
	g_current_sprite_obj = saved;
}
#define CALL_FRAME(app, obj, f) exec_sprite_frame(app, obj, f)

// ---------------------------------------------------------------------------
// Helper: Recursive sprite/button initialization for newly placed objects.
// Called from tagShowFrame to run frame 0 for each sprite/button that was
// placed since the last ShowFrame and has sprite_needs_init=1.
//
// parent_mc: the MovieClip that "owns" the current display_list (used as
//            parent when creating child MCs, so _parent is set correctly).
// ---------------------------------------------------------------------------
// Forward declaration for the inner processing logic (processes a single depth index).
static void process_sprite_init_at_depth(SWFAppContext* app_context, MovieClip* parent_mc, size_t depth_idx);

static void process_sprite_needs_init(SWFAppContext* app_context, MovieClip* parent_mc)
{
	// When frame filter is active, process in placed_at_frame order (not depth order)
	// to match Ruffle's placement-ordered initialization.
	if (g_sprite_init_filter_active)
	{
		// Collect eligible depth indices, then sort by placed_at_frame
		size_t eligible[256];
		size_t eligible_count = 0;
		for (size_t i = 1; i <= max_depth && i < 256; i++)
		{
			DisplayObject* obj = &display_list[i];
			if (obj->char_id == 0 || !obj->sprite_needs_init) continue;
			if (g_sprite_init_before_target && obj->placed_at_frame >= g_sprite_init_target_frame)
				continue;
			if (!g_sprite_init_before_target && obj->placed_at_frame < g_sprite_init_target_frame)
				continue;
			eligible[eligible_count++] = i;
		}
		// Simple insertion sort by placed_at_frame (usually very few entries)
		for (size_t a = 1; a < eligible_count; a++)
		{
			size_t key = eligible[a];
			size_t key_frame = display_list[key].placed_at_frame;
			int b = (int)a - 1;
			while (b >= 0 && display_list[eligible[b]].placed_at_frame > key_frame)
			{
				eligible[b + 1] = eligible[b];
				b--;
			}
			eligible[b + 1] = key;
		}
		for (size_t k = 0; k < eligible_count; k++)
			process_sprite_init_at_depth(app_context, parent_mc, eligible[k]);
		return;
	}

	// Normal path: iterate by depth
	for (size_t i = 1; i <= max_depth; i++)
		process_sprite_init_at_depth(app_context, parent_mc, i);
}

static void process_sprite_init_at_depth(SWFAppContext* app_context, MovieClip* parent_mc, size_t i)
{
		DisplayObject* obj = &display_list[i];
		if (obj->char_id == 0 || !obj->sprite_needs_init) return;

		Character* ch = &dictionary[obj->char_id];

		if (ch->type == CHAR_TYPE_SPRITE)
		{
			// Pre-create/sync the child MC while still in the parent's display_list
			// context so x/y are synced from the correct transform entry.
			// Even unnamed sprites need a MC with the correct parent so that
			// _parent preloading and base_clip context work correctly.
			MovieClip* child_mc = NULL;
			if (obj->instance_name != NULL)
				child_mc = actionFindOrCreateMovieClip(app_context, obj->instance_name, parent_mc);
			else
			{
				char anon_name[32];
				snprintf(anon_name, sizeof(anon_name), "__anon_depth_%zu__", i);
				child_mc = actionFindOrCreateMovieClip(app_context, anon_name, parent_mc);
			}
			if (child_mc) child_mc->display_obj = (void*)obj;

			// sprite_needs_init == 2: Phase 1 (placement) ran eagerly; run Phase 2
			// (scripts only) now. sprite_needs_init == 1: normal deferred path.
			int was_eager = (obj->sprite_needs_init == 2);
			obj->sprite_needs_init = 0;

			// Context swap to sprite's display list
			DisplayObject* saved_dl    = display_list;
			size_t         saved_max   = max_depth;
			size_t         saved_cap   = display_list_capacity;
			display_list          = obj->sprite_display_list;
			max_depth             = obj->sprite_max_depth;
			display_list_capacity = obj->sprite_dl_capacity;

			// Fire onLoad clip actions BEFORE frame scripts (Flash fires load before frame 0 scripts)
			if (obj->clip_action_count > 0 && obj->instance_name != NULL)
			{
				MovieClip* saved_ctx2 = g_current_context;
				MovieClip* mc2 = actionFindOrCreateMovieClip(app_context, obj->instance_name, parent_mc);
				if (mc2) actionSetCurrentContext(mc2);
				for (size_t a = 0; a < obj->clip_action_count; a++)
				{
					if (obj->clip_actions[a].event_flags & CLIP_EVENT_LOAD)
						obj->clip_actions[a].action(app_context);
				}
				actionSetCurrentContext(saved_ctx2);
			}

			// Run frame 0 with correct MC context
			MovieClip*    saved_ctx        = g_current_context;
			MovieClip*    saved_base       = actionGetBaseClip();
			DisplayObject* saved_sprite_obj = g_current_sprite_obj;
			g_current_sprite_obj = obj;
			if (child_mc) { actionSetCurrentContext(child_mc); actionSetBaseClip(child_mc); }

			if (ch->sprite_frame_funcs != NULL && ch->sprite_frame_funcs[0] != NULL)
			{
				// Call frame func directly (NOT via CALL_FRAME/exec_sprite_frame)
				// because we already set g_current_context and g_current_sprite_obj above.
				// exec_sprite_frame would create a duplicate MC with root as parent.
				int saved_settarget = g_settarget_explicit_root;
				g_settarget_explicit_root = 0;
				if (was_eager)
				{
					// Phase 2: run scripts only; placement tags are no-ops via g_script_only_mode.
					g_script_only_mode = 1;
					ch->sprite_frame_funcs[0](app_context);
					g_script_only_mode = 0;
				}
				else
				{
					ch->sprite_frame_funcs[0](app_context);
				}
				g_settarget_explicit_root = saved_settarget;
			}

			actionSetCurrentContext(saved_ctx);
			actionSetBaseClip(saved_base);
			g_current_sprite_obj = saved_sprite_obj;

			// Advance frame counter so advance_sprite_frames picks up at frame 1.
			// For 0-frame sprites (no ShowFrame in definition), keep at frame 0.
			obj->sprite_current_frame = (ch->sprite_frame_count > 0) ? (1 % ch->sprite_frame_count) : 0;

			// Recursively initialize any children placed by the frame function
			process_sprite_needs_init(app_context, child_mc);

			// Save back (pointer may change from realloc)
			obj->sprite_display_list  = display_list;
			obj->sprite_max_depth     = max_depth;
			obj->sprite_dl_capacity   = display_list_capacity;

			display_list          = saved_dl;
			max_depth             = saved_max;
			display_list_capacity = saved_cap;

			// Invoke registered class constructor if this sprite has an exported symbol with a registered class
			// Skip if already invoked during eager init in tagPlaceObject2 (constructor_invoked flag)
			if (!obj->constructor_invoked)
			{
				extern const char* ng_lookupExportName(size_t char_id);
				extern void actionInvokeRegisteredClassConstructor(SWFAppContext* app_context, const char* export_name, MovieClip* mc);
				const char* export_name = ng_lookupExportName(obj->char_id);
				if (export_name != NULL && child_mc != NULL)
					actionInvokeRegisteredClassConstructor(app_context, export_name, child_mc);
			}

			// Mark as freshly initialized (=1); upgraded to 2 after first tagShowFrame
			// so per-tick clip event ENTER_FRAME and AS2 onEnterFrame fire on
			// subsequent ticks only (Ruffle model: init tick fires LOAD, not EnterFrame).
			obj->sprite_initialized = 1;
		}
		else if (ch->type == CHAR_TYPE_BUTTON && ch->button_state_funcs != NULL)
		{
			// Pre-create the button MC while still in the parent's display_list context
			MovieClip* button_mc = NULL;
			if (obj->instance_name != NULL)
			{
				button_mc = actionFindOrCreateMovieClip(app_context, obj->instance_name, parent_mc);
				if (button_mc) { button_mc->is_button_mc = 1; button_mc->display_obj = (void*)obj; }
			}

			obj->sprite_needs_init = 0;

			// Context swap to button's display list
			DisplayObject* saved_dl    = display_list;
			size_t         saved_max   = max_depth;
			size_t         saved_cap   = display_list_capacity;
			display_list          = obj->sprite_display_list;
			max_depth             = obj->sprite_max_depth;
			display_list_capacity = obj->sprite_dl_capacity;

			// Run up-state (button_state_funcs[0]) to place button's children.
			// Do NOT change g_current_context — button state funcs don't run AS2 scripts.
			ch->button_state_funcs[0](app_context);

			// Sync back to obj BEFORE recursive init so that child scripts
			// accessing parent_mc->display_obj see up-to-date sprite_max_depth.
			obj->sprite_display_list  = display_list;
			obj->sprite_max_depth     = max_depth;
			obj->sprite_dl_capacity   = display_list_capacity;

			// Recursively initialize sprites placed by the up-state func,
			// using button_mc as their parent.
			process_sprite_needs_init(app_context, button_mc);

			// Save back (recursive init may have updated display_list via realloc)
			obj->sprite_display_list  = display_list;
			obj->sprite_max_depth     = max_depth;
			obj->sprite_dl_capacity   = display_list_capacity;

			display_list          = saved_dl;
			max_depth             = saved_max;
			display_list_capacity = saved_cap;
		}
}

#else
#define CALL_FRAME(app, obj, f) (f)(app)
#endif

// ---------------------------------------------------------------------------
// Helper 1: Advance sprite timelines recursively
// ---------------------------------------------------------------------------
// When > 0, advance_sprite_frames defers nested recursion for normal-play
// sprites (goto paths still recurse immediately).  The deferred recursion is
// performed by advance_nested_sprite_frames() after the root frame script.
int g_advance_defer_nested = 0;

// Iterates the current global display_list for sprites and advances their
// timelines.  After executing each sprite's frame function (while globals are
// swapped to the sprite's list), recurse to advance any nested sprites.
void advance_sprite_frames(SWFAppContext* app_context)
{
#ifdef NO_GRAPHICS
	if (catch_up_mode) return;
#endif

	for (size_t i = max_depth; i >= 1; --i)
	{
		DisplayObject* obj = &display_list[i];
		if (obj->char_id == 0) continue;
		Character* ch = &dictionary[obj->char_id];
		if (ch->type != CHAR_TYPE_SPRITE) continue;

		// Allocate persistent display list on first encounter
		if (obj->sprite_display_list == NULL)
		{
			obj->sprite_dl_capacity = INITIAL_DISPLAYLIST_CAPACITY;
			obj->sprite_display_list = HCALLOC(obj->sprite_dl_capacity, sizeof(DisplayObject));
			obj->sprite_max_depth = 0;
			obj->sprite_current_frame = 0;
			// Don't override sprite_is_playing — tagPlaceObject2 already set it to 1,
			// and a script may have already set it to 0 (e.g. gotoAndStop before first ShowFrame)
		}

		// Check for manual frame navigation (gotoAndPlay/gotoAndStop)
		size_t frame = obj->sprite_current_frame;
		if (obj->sprite_manual_next_frame)
		{
			obj->sprite_manual_next_frame = 0;
			size_t target = obj->sprite_next_frame;
			if (target < ch->sprite_frame_count)
			{
				// If jumping backward, reset the display list
				if (target <= frame)
				{
					// Swap to sprite's display list context
					DisplayObject* saved_dl = display_list;
					size_t saved_max = max_depth;
					size_t saved_cap = display_list_capacity;

					display_list = obj->sprite_display_list;
					max_depth = obj->sprite_max_depth;
					display_list_capacity = obj->sprite_dl_capacity;

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

					// Re-execute frames 0..target
					for (size_t f = 0; f <= target; f++)
					{
						if (f < ch->sprite_frame_count && ch->sprite_frame_funcs[f] != NULL)
							CALL_FRAME(app_context, obj, ch->sprite_frame_funcs[f]);
					}

					// Recurse nested sprites (set parent context for correct child MC creation)
					{
						extern MovieClip root_movieclip;
#ifndef NO_GRAPHICS
						MovieClip* pmc = (g_current_context != NULL) ? g_current_context : &root_movieclip;
						MovieClip* smc = obj->instance_name ? actionFindOrCreateMovieClip(app_context, obj->instance_name, pmc) : NULL;
#else
						extern MovieClip* actionFindMovieClipByName(const char* instance_name);
						MovieClip* smc = obj->instance_name ? actionFindMovieClipByName(obj->instance_name) : NULL;
#endif
						MovieClip* sctx = g_current_context;
						if (smc) actionSetCurrentContext(smc);
						advance_sprite_frames(app_context);
						actionSetCurrentContext(sctx);
					}

					obj->sprite_display_list = display_list;
					obj->sprite_max_depth = max_depth;
					obj->sprite_dl_capacity = display_list_capacity;

					display_list = saved_dl;
					max_depth = saved_max;
					display_list_capacity = saved_cap;
				}
				else
				{
					// Jumping forward: execute frames frame+1..target
					// Intermediate frames run in catch_up_mode (tags only, scripts skipped).
					// Only the target frame runs scripts (matching Flash/Ruffle goto semantics).
					DisplayObject* saved_dl = display_list;
					size_t saved_max = max_depth;
					size_t saved_cap = display_list_capacity;

					display_list = obj->sprite_display_list;
					max_depth = obj->sprite_max_depth;
					display_list_capacity = obj->sprite_dl_capacity;

					int saved_cm = catch_up_mode;
					for (size_t f = frame + 1; f <= target; f++)
					{
						catch_up_mode = (f < target) ? 1 : 0;
						if (f < ch->sprite_frame_count && ch->sprite_frame_funcs[f] != NULL)
							CALL_FRAME(app_context, obj, ch->sprite_frame_funcs[f]);
					}
					catch_up_mode = saved_cm;

					// Recurse nested sprites (set parent context for correct child MC creation)
					{
						extern MovieClip root_movieclip;
#ifndef NO_GRAPHICS
						MovieClip* pmc = (g_current_context != NULL) ? g_current_context : &root_movieclip;
						MovieClip* smc = obj->instance_name ? actionFindOrCreateMovieClip(app_context, obj->instance_name, pmc) : NULL;
#else
						extern MovieClip* actionFindMovieClipByName(const char* instance_name);
						MovieClip* smc = obj->instance_name ? actionFindMovieClipByName(obj->instance_name) : NULL;
#endif
						MovieClip* sctx = g_current_context;
						if (smc) actionSetCurrentContext(smc);
						advance_sprite_frames(app_context);
						actionSetCurrentContext(sctx);
					}

					obj->sprite_display_list = display_list;
					obj->sprite_max_depth = max_depth;
					obj->sprite_dl_capacity = display_list_capacity;

					display_list = saved_dl;
					max_depth = saved_max;
					display_list_capacity = saved_cap;
				}
				obj->sprite_current_frame = target;
			}
			obj->enterframe_eligible = 1;
			continue; // Manual nav done, skip normal advancement
		}

		// Set enterframe_eligible for ALL initialized sprites, even stopped/1-frame.
		// This ensures per-tick clip event ENTER_FRAME and AS2 onEnterFrame fire
		// for sprites that don't advance (matching Ruffle's unconditional model).
		if (obj->sprite_initialized >= 2)
			obj->enterframe_eligible = 1;

		// Only advance if playing
		if (!obj->sprite_is_playing) continue;

		// Skip 1-frame sprites — they don't advance
		if (ch->sprite_frame_count <= 1) continue;

		// Swap to sprite's display list context
		DisplayObject* saved_dl = display_list;
		size_t saved_max = max_depth;
		size_t saved_cap = display_list_capacity;

		display_list = obj->sprite_display_list;
		max_depth = obj->sprite_max_depth;
		display_list_capacity = obj->sprite_dl_capacity;

		// When looping back to frame 0, reset the display list (Flash behavior)
		if (frame == 0 && max_depth > 0)
		{
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
		}

		// Execute current frame function
		if (frame < ch->sprite_frame_count && ch->sprite_frame_funcs[frame] != NULL)
		{
			CALL_FRAME(app_context, obj, ch->sprite_frame_funcs[frame]);
		}

		// Mark eligible for AS2 onEnterFrame dispatch (sprite actually advanced)
		obj->enterframe_eligible = 1;

#ifdef NO_GRAPHICS
		// Initialize any children placed by the frame function (deferred Phase 2
		// scripts from eager init). Sprite frame functions don't have tagShowFrame,
		// so process_sprite_needs_init must be called explicitly here.
		// Only if any child actually needs init (avoid unnecessary MC lookups).
		{
			int any_needs_init = 0;
			for (size_t ci = 1; ci <= max_depth; ci++) {
				if (display_list[ci].char_id != 0 && display_list[ci].sprite_needs_init) {
					any_needs_init = 1;
					break;
				}
			}
			if (any_needs_init) {
				extern MovieClip* actionFindMovieClipByName(const char* instance_name);
				extern MovieClip root_movieclip;
				MovieClip* parent_for_init = (obj->instance_name != NULL)
					? actionFindMovieClipByName(obj->instance_name) : NULL;
				process_sprite_needs_init(app_context, parent_for_init ? parent_for_init : &root_movieclip);
			}
		}
#endif

		// Recurse: advance nested sprites within this sprite's display list.
		// When g_advance_defer_nested is set (top-level call from swf_core.c),
		// skip recursion here — it will be done by advance_nested_sprite_frames()
		// after the root frame script, matching Ruffle's execution order.
		if (!g_advance_defer_nested)
		{
			MovieClip* sprite_mc = NULL;
#ifndef NO_GRAPHICS
			extern MovieClip root_movieclip;
			MovieClip* parent_for_recurse = (g_current_context != NULL) ? g_current_context : &root_movieclip;
			if (obj->instance_name != NULL)
				sprite_mc = actionFindOrCreateMovieClip(app_context, obj->instance_name, parent_for_recurse);
#else
			extern MovieClip* actionFindMovieClipByName(const char* instance_name);
			if (obj->instance_name != NULL)
				sprite_mc = actionFindMovieClipByName(obj->instance_name);
#endif
			MovieClip* saved_recurse_ctx = g_current_context;
			if (sprite_mc) actionSetCurrentContext(sprite_mc);
			advance_sprite_frames(app_context);
			actionSetCurrentContext(saved_recurse_ctx);
		}

		// Save back (display_list pointer may have changed if realloc'd)
		obj->sprite_display_list = display_list;
		obj->sprite_max_depth = max_depth;
		obj->sprite_dl_capacity = display_list_capacity;

		// Restore parent display list
		display_list = saved_dl;
		max_depth = saved_max;
		display_list_capacity = saved_cap;

		// Advance frame (loop back to 0); guard against 0-frame sprites
		if (ch->sprite_frame_count > 0)
			obj->sprite_current_frame = (frame + 1) % ch->sprite_frame_count;
	}
}

// Deferred recursion pass: for each root-level sprite, swap into its display
// list and call advance_sprite_frames (which will now recurse normally since
// g_advance_defer_nested is 0).
void advance_nested_sprite_frames(SWFAppContext* app_context)
{
#ifdef NO_GRAPHICS
	if (catch_up_mode) return;
#endif

	for (size_t i = max_depth; i >= 1; --i)
	{
		DisplayObject* obj = &display_list[i];
		if (obj->char_id == 0) continue;
		Character* ch = &dictionary[obj->char_id];
		if (ch->type != CHAR_TYPE_SPRITE) continue;
		if (obj->sprite_display_list == NULL) continue;

		// Swap to sprite's display list context
		DisplayObject* saved_dl = display_list;
		size_t saved_max = max_depth;
		size_t saved_cap = display_list_capacity;

		display_list = obj->sprite_display_list;
		max_depth = obj->sprite_max_depth;
		display_list_capacity = obj->sprite_dl_capacity;

		// Set context to this sprite's MC for correct child resolution
		MovieClip* sprite_mc = NULL;
#ifndef NO_GRAPHICS
		{
			extern MovieClip root_movieclip;
			MovieClip* parent_for_recurse = (g_current_context != NULL) ? g_current_context : &root_movieclip;
			if (obj->instance_name != NULL)
				sprite_mc = actionFindOrCreateMovieClip(app_context, obj->instance_name, parent_for_recurse);
		}
#else
		{
			extern MovieClip* actionFindMovieClipByName(const char* instance_name);
			if (obj->instance_name != NULL)
				sprite_mc = actionFindMovieClipByName(obj->instance_name);
		}
#endif
		MovieClip* saved_ctx = g_current_context;
		if (sprite_mc) actionSetCurrentContext(sprite_mc);

		// Now recurse (g_advance_defer_nested is 0, so full recursion happens)
		advance_sprite_frames(app_context);

		actionSetCurrentContext(saved_ctx);

		// Save back
		obj->sprite_display_list = display_list;
		obj->sprite_max_depth = max_depth;
		obj->sprite_dl_capacity = display_list_capacity;

		display_list = saved_dl;
		max_depth = saved_max;
		display_list_capacity = saved_cap;
	}
}

#ifndef NO_GRAPHICS
// ---------------------------------------------------------------------------
// Helper 2: Recursive transform composition for sprite/button children
// ---------------------------------------------------------------------------
// Composes each child's local transform with the parent's already-composed
// global transform, writes the result to GPU, and recurses for nested
// structures (text glyphs, nested sprites, buttons).
//
// Unlike the old compose_child_transforms, this function receives the parent's
// COMPOSED transform (not a transform_id), so it works correctly at any
// nesting depth.  The CPU-side transform_data is never modified — all composed
// results go directly to the GPU xform buffer via renderer_write_transform.
static void compose_children(SWFAppContext* app_context, DisplayObject* dl,
	size_t dl_max_depth, const float parent_composed[16])
{
	const float* transforms = (const float*)app_context->transform_data;

	for (size_t i = 1; i <= dl_max_depth; ++i)
	{
		DisplayObject* obj = &dl[i];
		if (obj->char_id == 0) continue;

		Character* ch = &dictionary[obj->char_id];

		// Compose this child's local transform with the parent's global transform
		const float* local_xform = &transforms[obj->transform_id * 16];
		float composed[16];
		hit_test_mat4_multiply(composed, parent_composed, local_xform);
		renderer_write_transform(context, obj->transform_id, composed);

		switch (ch->type)
		{
			case CHAR_TYPE_TEXT:
				// Compose each glyph transform with the composed text transform
				for (size_t j = 0; j < ch->text_size; j++)
				{
					u32 glyph_xform_id = ch->transform_start + (u32)j;
					const float* glyph_local = &transforms[glyph_xform_id * 16];
					float glyph_composed[16];
					hit_test_mat4_multiply(glyph_composed, composed, glyph_local);
					renderer_write_transform(context, glyph_xform_id, glyph_composed);
				}
				break;

			case CHAR_TYPE_MORPH_SHAPE:
			{
				float t = (float)obj->ratio / 65535.0f;
				size_t num_verts = ch->morph_start_size;

				u32* start = (u32*)(app_context->shape_data + ch->morph_start_offset * 4 * sizeof(u32));
				float* end = (float*)(app_context->morph_end_shape_data + ch->morph_end_offset * 2 * sizeof(float));
				u32* scratch = (u32*)malloc(num_verts * 4 * sizeof(u32));

				for (size_t v = 0; v < num_verts; v++)
				{
					float sx = *(float*)&start[v*4 + 0];
					float sy = *(float*)&start[v*4 + 1];
					float ex = end[v*2 + 0];
					float ey = end[v*2 + 1];
					float ix = sx + t * (ex - sx);
					float iy = sy + t * (ey - sy);
					scratch[v*4 + 0] = *(u32*)&ix;
					scratch[v*4 + 1] = *(u32*)&iy;
					scratch[v*4 + 2] = start[v*4 + 2];
					scratch[v*4 + 3] = start[v*4 + 3];
				}

				renderer_update_vertices(context,
					ch->morph_start_offset * 4 * sizeof(u32),
					scratch, num_verts * 4 * sizeof(u32));
				free(scratch);

				for (size_t c = 0; c < ch->morph_color_count; c++)
				{
					float* sc = (float*)(app_context->color_data) + (ch->morph_color_start + c) * 4;
					float* ec = (float*)(app_context->morph_end_color_data) + c * 4;
					float interp[4];
					for (int k = 0; k < 4; k++)
						interp[k] = sc[k] + t * (ec[k] - sc[k]);
					renderer_update_colors(context,
						(ch->morph_color_start + c) * 4 * sizeof(float),
						interp, 4 * sizeof(float));
				}
				break;
			}

			case CHAR_TYPE_SPRITE:
			{
				if (obj->sprite_display_list != NULL)
					compose_children(app_context,
						obj->sprite_display_list, obj->sprite_max_depth,
						composed);
				break;
			}

			case CHAR_TYPE_BUTTON:
			{
				DisplayObject* saved_display_list = display_list;
				size_t saved_max_depth = max_depth;
				size_t saved_capacity = display_list_capacity;

				display_list_capacity = INITIAL_DISPLAYLIST_CAPACITY;
				display_list = (DisplayObject*) calloc(display_list_capacity, sizeof(DisplayObject));
				max_depth = 0;

				u8 state = obj->button_state;
				if (ch->button_state_funcs[state] != NULL)
					ch->button_state_funcs[state](app_context);

				compose_children(app_context, display_list, max_depth, composed);

				free(display_list);
				display_list = saved_display_list;
				max_depth = saved_max_depth;
				display_list_capacity = saved_capacity;
				break;
			}

			default:
				break;
		}
	}
}

// ---------------------------------------------------------------------------
// Helper 3: Recursive display list rendering
// ---------------------------------------------------------------------------
// Renders all objects in a display list, recursing into sprites and buttons.
// Forward declaration for mutual recursion
static void render_display_list(SWFAppContext* app_context, DisplayObject* dl, size_t dl_max_depth);

// Helper: render a single object into the current render pass
static void render_single_object(SWFAppContext* app_context, DisplayObject* obj)
{
	Character* ch = &dictionary[obj->char_id];
	switch (ch->type)
	{
		case CHAR_TYPE_SHAPE:
			renderer_draw_shape(context, ch->shape_offset, ch->size,
				obj->transform_id, obj->cxform_id);
			break;
		case CHAR_TYPE_MORPH_SHAPE:
			renderer_draw_shape(context, ch->morph_start_offset, ch->morph_start_size,
				obj->transform_id, obj->cxform_id);
			break;
		case CHAR_TYPE_TEXT:
			for (size_t j = 0; j < ch->text_size; ++j)
			{
				size_t glyph_index = 2*app_context->text_data[ch->text_start + j];
				renderer_draw_shape(context,
					app_context->glyph_data[glyph_index],
					app_context->glyph_data[glyph_index + 1],
					ch->transform_start + j, ch->cxform_id);
			}
			break;
		case CHAR_TYPE_SPRITE:
			if (obj->sprite_display_list != NULL)
				render_display_list(app_context, obj->sprite_display_list, obj->sprite_max_depth);
			break;
		case CHAR_TYPE_BUTTON:
		{
			DisplayObject* saved_display_list = display_list;
			size_t saved_max_depth = max_depth;
			size_t saved_capacity = display_list_capacity;

			display_list_capacity = INITIAL_DISPLAYLIST_CAPACITY;
			display_list = (DisplayObject*) calloc(display_list_capacity, sizeof(DisplayObject));
			max_depth = 0;

			u8 state = obj->button_state;
			if (ch->button_state_funcs[state] != NULL)
				ch->button_state_funcs[state](app_context);

			render_display_list(app_context, display_list, max_depth);

			free(display_list);
			display_list = saved_display_list;
			max_depth = saved_max_depth;
			display_list_capacity = saved_capacity;
			break;
		}
	}
}

static void render_display_list(SWFAppContext* app_context, DisplayObject* dl, size_t dl_max_depth)
{
	for (size_t i = 1; i <= dl_max_depth; ++i)
	{
		DisplayObject* obj = &dl[i];
		if (obj->char_id == 0) continue;

		Character* ch = &dictionary[obj->char_id];
		switch (ch->type)
		{
			case CHAR_TYPE_SHAPE:
				renderer_draw_shape(context, ch->shape_offset, ch->size,
					obj->transform_id, obj->cxform_id);
				break;

			case CHAR_TYPE_MORPH_SHAPE:
				renderer_draw_shape(context, ch->morph_start_offset, ch->morph_start_size,
					obj->transform_id, obj->cxform_id);
				break;

			case CHAR_TYPE_TEXT:
				for (size_t j = 0; j < ch->text_size; ++j)
				{
					size_t glyph_index = 2*app_context->text_data[ch->text_start + j];
					renderer_draw_shape(context,
						app_context->glyph_data[glyph_index],
						app_context->glyph_data[glyph_index + 1],
						ch->transform_start + j, ch->cxform_id);
				}
				break;

			case CHAR_TYPE_SPRITE:
				if (obj->sprite_display_list != NULL)
					render_display_list(app_context, obj->sprite_display_list, obj->sprite_max_depth);
				break;

			case CHAR_TYPE_BUTTON:
			{
				DisplayObject* saved_display_list = display_list;
				size_t saved_max_depth = max_depth;
				size_t saved_capacity = display_list_capacity;

				display_list_capacity = INITIAL_DISPLAYLIST_CAPACITY;
				display_list = (DisplayObject*) calloc(display_list_capacity, sizeof(DisplayObject));
				max_depth = 0;

				u8 state = obj->button_state;
				if (ch->button_state_funcs[state] != NULL)
					ch->button_state_funcs[state](app_context);

				render_display_list(app_context, display_list, max_depth);

				free(display_list);
				display_list = saved_display_list;
				max_depth = saved_max_depth;
				display_list_capacity = saved_capacity;
				break;
			}
		}
	}
}
#endif // NO_GRAPHICS


void tagSetBackgroundColor(u8 red, u8 green, u8 blue)
{
#ifndef NO_GRAPHICS
	renderer_set_background(context, red, green, blue);
#else
	(void)red; (void)green; (void)blue;
#endif
}

// Resolve a button's hit-test character ID to a shape, following through
// nested buttons (e.g. button 6 whose hit char is button 5 → shape 4).
static Character* resolve_hit_shape(size_t hit_char_id, u32* out_hit_transform_id, int depth)
{
	if (depth > 4) return NULL;  // guard against loops
	if (hit_char_id >= dictionary_capacity) return NULL;
	Character* hit_ch = &dictionary[hit_char_id];
	if (hit_ch->type == CHAR_TYPE_SHAPE) return hit_ch;
	if (hit_ch->type == CHAR_TYPE_BUTTON)
	{
		// Follow through to the nested button's hit shape
		*out_hit_transform_id = hit_ch->button_hit_transform_id;
		return resolve_hit_shape(hit_ch->button_hit_char_id, out_hit_transform_id, depth + 1);
	}
	return NULL;
}

// Button hit testing + state machine + action dispatch.
// Runs on every mouse event (in NO_GRAPHICS mode) so that transitions fire
// on the correct per-event boundary (e.g. MOUSE_MOVE → OverUp, then
// MOUSE_DOWN → OverDown fires the press action in the same tick).
//
// States: 0=Idle, 1=OverUp, 2=OverDown, 3=OutDown
//
// Recursive helper: walks a display list (which may be root or a button's
// child display list) and updates button states.  For nested buttons, the
// parent_xf is the composed transform of the enclosing button's placement,
// and parent_mc is the enclosing button's MovieClip context (used as the
// "this" scope when firing the nested button's actions).
static void ng_update_button_states_in_dl(SWFAppContext* app_context,
	DisplayObject* dl, size_t dl_max,
	const float* parent_xf, MovieClip* parent_mc,
	int* found_hover)
{
	for (size_t i = dl_max; i >= 1; i--)
	{
		DisplayObject* obj = &dl[i];
		if (obj->char_id == 0) continue;

		Character* ch = &dictionary[obj->char_id];
		if (ch->type != CHAR_TYPE_BUTTON) continue;

		// Recurse into this button's child display list FIRST (children are
		// rendered on top, so they get events before the parent button).
		if (obj->sprite_display_list != NULL && obj->sprite_max_depth > 0)
		{
			// Compose placement transform for recursion
			const float* place_xf = (const float*)(app_context->transform_data) + obj->transform_id * 16;
			float child_parent_xf[16];
			hit_test_mat4_multiply(child_parent_xf, parent_xf, place_xf);

			// Find the MC for this button to use as context for children
			MovieClip* btn_mc = NULL;
			if (obj->instance_name != NULL)
				btn_mc = actionFindOrCreateMovieClip(app_context, obj->instance_name, parent_mc);

			ng_update_button_states_in_dl(app_context,
				obj->sprite_display_list, obj->sprite_max_depth,
				child_parent_xf, btn_mc ? btn_mc : parent_mc,
				found_hover);
		}

		u8 old_state = obj->button_state;
		u8 new_state = old_state;

		// Check _visible and enabled on the button's MovieClip
		int mc_visible = actionGetMCVisible(app_context, obj->instance_name);
		int mc_enabled = actionGetMCEnabled(app_context, obj->instance_name);

		if (!mc_visible)
		{
			if (app_context->mouse.button_down &&
			    (old_state == 2 || old_state == 3))
				new_state = 3;
			else
				new_state = 0;
		}
		else if (!(*found_hover))
		{
			// Resolve hit-test shape (follows through nested buttons)
			u32 resolved_hit_xf_id = ch->button_hit_transform_id;
			Character* hit_ch = resolve_hit_shape(ch->button_hit_char_id, &resolved_hit_xf_id, 0);
			if (hit_ch != NULL)
			{
				// Compose: parent_xf * placement * hit-record transform
				const float* place_xf = (const float*)(app_context->transform_data) + obj->transform_id * 16;
				const float* hit_xf = (const float*)(app_context->transform_data) + resolved_hit_xf_id * 16;
				float temp[16], composed[16];
				hit_test_mat4_multiply(temp, parent_xf, place_xf);
				hit_test_mat4_multiply(composed, temp, hit_xf);

				int hit = hit_test_shape(app_context->shape_data,
					hit_ch->shape_offset, hit_ch->size,
					composed,
					app_context->mouse.stage_x,
					app_context->mouse.stage_y);

				if (hit)
				{
					*found_hover = 1;
					if (app_context->mouse.button_down)
						new_state = 2;
					else
						new_state = 1;
				}
				else
				{
					if (app_context->mouse.button_down &&
					    (old_state == 2 || old_state == 3))
						new_state = 3;
					else
						new_state = 0;
				}
			}
		}
		else
		{
			if (app_context->mouse.button_down &&
			    (old_state == 2 || old_state == 3))
				new_state = 3;
			else
				new_state = 0;
		}

		// When disabled: Ruffle-compatible state tracking.
		if (!mc_enabled)
		{
			int computed_is_over = (new_state == 1);
			if (!computed_is_over)
				new_state = 0;
			else
				new_state = old_state;
		}
		obj->button_state = new_state;
		obj->sticky_char_id = obj->char_id;
		obj->sticky_button_state = new_state;

		// Dispatch actions on state transitions
		if (old_state != new_state && ch->button_action_count > 0)
		{
			if (!mc_enabled)
			{
				obj->button_prev_state = old_state;
				continue;
			}

			int allow_actions = mc_visible;
			if (!mc_visible)
			{
				if ((old_state == 1 && new_state == 0) ||
				    (old_state == 3 && new_state == 0) ||
				    (old_state == 2 && new_state == 0) ||
				    (old_state == 2 && new_state == 3))
					allow_actions = 1;
			}

			if (allow_actions)
			{
				u16 transition = 0;
				if      (old_state == 0 && new_state == 1) transition = 0x0001;
				else if (old_state == 1 && new_state == 0) transition = 0x0002;
				else if (old_state == 1 && new_state == 2) transition = 0x0004;
				else if (old_state == 2 && new_state == 1) transition = 0x0008;
				else if (old_state == 2 && new_state == 3) transition = 0x0010;
				else if (old_state == 3 && new_state == 2) transition = 0x0020;
				else if (old_state == 3 && new_state == 0) transition = 0x0040;
				else if (old_state == 0 && new_state == 2) transition = 0x0080;
				else if (old_state == 2 && new_state == 0) transition = 0x0100;
				else if (old_state == 3 && new_state == 1) transition = 0x0040;

				if (transition != 0)
				{
					// Switch context to parent MC for button actions.
					// AVM1 buttons run actions relative to their parent, not themselves.
					MovieClip* saved_ctx = g_current_context;
					DisplayObject* saved_sprite_obj = g_current_sprite_obj;
					actionSetCurrentContext(parent_mc);
					// If the parent is a button MC, set g_current_sprite_obj to
					// the parent's display object so that GotoFrame targets the
					// button (a non-sprite), making it a no-op.  This matches
					// Ruffle where button parents can't navigate frames.
					if (parent_mc && parent_mc->is_button_mc && parent_mc->display_obj)
						g_current_sprite_obj = (DisplayObject*)parent_mc->display_obj;
					for (size_t a = 0; a < ch->button_action_count; a++)
					{
						if (ch->button_actions[a].condition & transition)
							ch->button_actions[a].action(app_context);
					}
					g_current_sprite_obj = saved_sprite_obj;
					actionSetCurrentContext(saved_ctx);
				}
			}
		}

		obj->button_prev_state = old_state;
	}
}

void ng_update_button_states(SWFAppContext* app_context)
{
	if (app_context->shape_data == NULL) return;

	// Identity transform for root-level buttons
	static const float identity[16] = {
		1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1
	};

	int found_hover = 0;
	ng_update_button_states_in_dl(app_context,
		display_list, max_depth,
		identity, &root_movieclip,
		&found_hover);
}

// Recursively upgrade sprite_initialized from 1 (this tick) to 2 (ready for per-tick dispatch).
void upgrade_sprite_initialized(DisplayObject* dl, size_t dl_max)
{
	for (size_t i = 1; i <= dl_max; ++i)
	{
		if (dl[i].sprite_initialized == 1)
			dl[i].sprite_initialized = 2;
		if (dl[i].sprite_display_list != NULL && dl[i].sprite_max_depth > 0)
			upgrade_sprite_initialized(dl[i].sprite_display_list, dl[i].sprite_max_depth);
	}
}

// Recursively dispatch CLIP_EVENT_ENTER_FRAME: children before parents.
// Only fires for sprites with sprite_initialized >= 2 (init'd on a previous tick).
void dispatch_enterframe_clip_actions(SWFAppContext* app_context,
	DisplayObject* dl, size_t dl_max, MovieClip* parent_mc)
{
	for (size_t i = 1; i <= dl_max; ++i)
	{
		DisplayObject* obj = &dl[i];
		if (obj->char_id == 0) continue;
		// Skip sprites not yet fully initialized (init'd this tick = 1, or not init'd = 0)
		if (obj->sprite_initialized < 2) continue;

		// Recurse into sprite children first (depth-first, children before parents)
		if (obj->sprite_display_list != NULL && obj->sprite_max_depth > 0)
		{
			MovieClip* child_mc = NULL;
			if (obj->instance_name != NULL)
				child_mc = actionFindOrCreateMovieClip(app_context, obj->instance_name, parent_mc);
			dispatch_enterframe_clip_actions(app_context,
				obj->sprite_display_list, obj->sprite_max_depth,
				child_mc ? child_mc : parent_mc);
		}

		if (obj->clip_action_count == 0) continue;

		// Set correct MC context for the clip action
		MovieClip* saved_ctx = g_current_context;
		if (obj->instance_name != NULL) {
			MovieClip* mc = actionFindOrCreateMovieClip(app_context, obj->instance_name, parent_mc);
			if (mc) actionSetCurrentContext(mc);
		}
		for (size_t a = 0; a < obj->clip_action_count; a++)
		{
			if (obj->clip_actions[a].event_flags & CLIP_EVENT_ENTER_FRAME) {
				obj->clip_actions[a].action(app_context);
			}
		}
		actionSetCurrentContext(saved_ctx);
	}
}

// Recursively set enterframe_eligible=1 for all display entries with sprite_initialized >= 2.
// Walks into sprite and button child display lists. This ensures button children get the flag
// (advance_sprite_frames only iterates root-level sprites, missing button children).
// When a parent is removed (char_id=0), the walk skips it → children don't get the flag.
void set_enterframe_eligible_recursive(DisplayObject* dl, size_t dl_max)
{
	for (size_t i = 1; i <= dl_max; i++)
	{
		if (dl[i].char_id == 0) continue;
		if (dl[i].sprite_initialized >= 2)
			dl[i].enterframe_eligible = 1;
		if (dl[i].sprite_display_list != NULL && dl[i].sprite_max_depth > 0)
			set_enterframe_eligible_recursive(dl[i].sprite_display_list, dl[i].sprite_max_depth);
	}
}

// --- Deferred ENTER_FRAME flush ---
// Set by swf_core.c before the root frame function. Cleared by tagFlushPendingEnterFrame.
// Ensures ENTER_FRAME fires between RemoveObject and DoAction (matching Flash ordering).
int g_enterframe_flush_pending = 0;

void tagFlushPendingEnterFrame(SWFAppContext* app_context)
{
	if (!g_enterframe_flush_pending) return;
	g_enterframe_flush_pending = 0;

	// Set enterframe_eligible for all initialized sprites (recursive into buttons)
	set_enterframe_eligible_recursive(display_list, max_depth);
	// Dispatch clip event ENTER_FRAME (recursive, children before parents).
	// Only fires for sprites with sprite_initialized >= 2 (init'd on a previous tick).
	{
		extern MovieClip root_movieclip;
		dispatch_enterframe_clip_actions(app_context, display_list, max_depth, &root_movieclip);
	}
	// Dispatch AS2 mc.onEnterFrame property handlers
	actionDispatchEnterFrameHandlers(app_context);
	actionDispatchRootVarMapEnterFrame(app_context);
}

// Flag to suppress tagShowFrame side effects during actionCall invocations.
// call() only runs DoAction scripts, not timeline management tags.
int g_in_action_call = 0;

void tagShowFrame(SWFAppContext* app_context)
{
#ifdef NO_GRAPHICS
	if (g_tag_skip_mode) return;
	if (g_in_action_call) return;
	// --- Fire deferred onUnload handlers from removeMovieClip ---
	// These are queued mid-script and fire between frames, matching Flash behavior.
	actionFirePendingUnloads(app_context);

	// --- Run initial frame 0 with scripts for newly placed sprites/buttons ---
	// sprite_needs_init=1 is set by ng_on_place_object2 when a sprite or button is placed.
	// We run frame 0 here (in the same tick as placement) to match Flash behavior.
	// process_sprite_needs_init handles CHAR_TYPE_SPRITE and CHAR_TYPE_BUTTON recursively.
	//
	// When g_defer_sprite_init is set (during ng_executeGotoCatchUp), we skip this block.
	// Sprite init scripts must run AFTER the deferred parent-frame DoAction, not before.
	// ng_run_deferred_sprite_init() handles the deferred case.
	if (!g_defer_sprite_init)
	{
		// Sync root display sentinel before nested init — child scripts may access
		// root children via GetMember(root_mc, name) while display_list is swapped.
		extern void ng_sync_root_display_obj(void);
		ng_sync_root_display_obj();

		int saved_catch_up = catch_up_mode;
		catch_up_mode = 0;
		process_sprite_needs_init(app_context, &root_movieclip);
		catch_up_mode = saved_catch_up;

		// Fire onLoad events for duplicated clips (queued by ng_duplicateMovieClip)
		ng_fire_pending_loads(app_context);

		// Fire deferred init scripts for attachMovie clips
		ng_fire_pending_attach_inits(app_context);

		// Fire deferred onLoadInit handlers from MovieClipLoader.loadClip
		actionFirePendingLoadInits(app_context);

		// Fallback: flush pending ENTER_FRAME if not already flushed by a
		// tagFlushPendingEnterFrame call (emitted before DoAction by the recompiler).
		// For frames with no DoAction, this ensures ENTER_FRAME still fires.
		tagFlushPendingEnterFrame(app_context);

		// Upgrade sprite_initialized from 1 (this tick) to 2 (ready for per-tick dispatch).
		// Must recurse into nested sprite display lists.
		{
			void upgrade_sprite_initialized(DisplayObject* dl, size_t dl_max);
			upgrade_sprite_initialized(display_list, max_depth);
		}

		// After the first tagShowFrame, root's enterFrame becomes eligible.
		// On the first frame, root fires LOAD (its frame script), not enterFrame.
		extern int g_root_enterframe_eligible;
		g_root_enterframe_eligible = 1;
	}
#else
	// --- Advance sprite timelines (recursive) ---
	advance_sprite_frames(app_context);
#endif

	// --- Button hit testing + state machine + action dispatch ---
	// In NO_GRAPHICS mode, button states are updated per-tick from swf_core.c frame loop
	// (after event delivery), and per-mouse-event from input_events_deliver().
#ifndef NO_GRAPHICS
	ng_update_button_states(app_context);
#endif

#ifndef NO_GRAPHICS
	// Compose transforms recursively BEFORE the render pass.
	// For sprites/buttons: compose_children handles all nesting levels,
	// passing the composed parent transform down so nested text/sprite/button
	// children get correctly composed global transforms.
	// For top-level text/morph: compose directly (parent is identity/self).
	for (size_t i = 1; i <= max_depth; ++i)
	{
		DisplayObject* obj = &display_list[i];
		if (obj->char_id == 0) continue;

		Character* ch = &dictionary[obj->char_id];
		if (ch->type == CHAR_TYPE_SPRITE)
		{
			if (obj->sprite_display_list != NULL)
			{
				const float* sprite_xform = (const float*)app_context->transform_data + obj->transform_id * 16;
				compose_children(app_context,
					obj->sprite_display_list, obj->sprite_max_depth,
					sprite_xform);
			}
		}
		else if (ch->type == CHAR_TYPE_BUTTON)
		{
			DisplayObject* saved_display_list = display_list;
			size_t saved_max_depth = max_depth;
			size_t saved_capacity = display_list_capacity;

			display_list_capacity = INITIAL_DISPLAYLIST_CAPACITY;
			display_list = (DisplayObject*) calloc(display_list_capacity, sizeof(DisplayObject));
			max_depth = 0;

			u8 state = obj->button_state;
			if (ch->button_state_funcs[state] != NULL)
				ch->button_state_funcs[state](app_context);

			const float* btn_xform = (const float*)app_context->transform_data + obj->transform_id * 16;
			compose_children(app_context, display_list, max_depth, btn_xform);

			free(display_list);
			display_list = saved_display_list;
			max_depth = saved_max_depth;
			display_list_capacity = saved_capacity;
		}
		else if (ch->type == CHAR_TYPE_TEXT)
		{
			renderer_compose_text_transforms(context,
				app_context->transform_data,
				obj->transform_id,
				ch->transform_start,
				ch->text_size);
		}
		else if (ch->type == CHAR_TYPE_MORPH_SHAPE)
		{
			float t = (float)obj->ratio / 65535.0f;
			size_t num_verts = ch->morph_start_size;

			u32* start = (u32*)(app_context->shape_data + ch->morph_start_offset * 4 * sizeof(u32));
			float* end = (float*)(app_context->morph_end_shape_data + ch->morph_end_offset * 2 * sizeof(float));
			u32* scratch = (u32*)malloc(num_verts * 4 * sizeof(u32));

			for (size_t v = 0; v < num_verts; v++)
			{
				float sx = *(float*)&start[v*4 + 0];
				float sy = *(float*)&start[v*4 + 1];
				float ex = end[v*2 + 0];
				float ey = end[v*2 + 1];
				float ix = sx + t * (ex - sx);
				float iy = sy + t * (ey - sy);
				scratch[v*4 + 0] = *(u32*)&ix;
				scratch[v*4 + 1] = *(u32*)&iy;
				scratch[v*4 + 2] = start[v*4 + 2];
				scratch[v*4 + 3] = start[v*4 + 3];
			}

			renderer_update_vertices(context,
				ch->morph_start_offset * 4 * sizeof(u32),
				scratch, num_verts * 4 * sizeof(u32));
			free(scratch);

			for (size_t c = 0; c < ch->morph_color_count; c++)
			{
				float* sc = (float*)(app_context->color_data) + (ch->morph_color_start + c) * 4;
				float* ec = (float*)(app_context->morph_end_color_data) + c * 4;
				float interp[4];
				for (int k = 0; k < 4; k++)
					interp[k] = sc[k] + t * (ec[k] - sc[k]);
				renderer_update_colors(context,
					(ch->morph_color_start + c) * 4 * sizeof(float),
					interp, 4 * sizeof(float));
			}
		}
	}

	renderer_open_pass(context);

	u16 active_clip_depth = 0;

	for (size_t i = 1; i <= max_depth; ++i)
	{
		// End active clip if we've passed its range
		if (active_clip_depth > 0 && i > active_clip_depth)
		{
			renderer_end_clip(context);
			active_clip_depth = 0;
		}

		DisplayObject* obj = &display_list[i];

		if (obj->char_id == 0)
		{
			continue;
		}

		// Check if this object is a clip mask
		if (obj->clip_depth > 0)
		{
			Character* ch = &dictionary[obj->char_id];
			if (ch->type == CHAR_TYPE_SHAPE)
			{
				renderer_begin_clip_mask(context);
				renderer_draw_shape(context, ch->shape_offset, ch->size, obj->transform_id, obj->cxform_id);
				renderer_end_clip_mask(context);
				active_clip_depth = obj->clip_depth;
			}
			continue;
		}

		// Set blend mode if non-default
		if (obj->blend_mode > 1)
			renderer_set_blend_mode(context, obj->blend_mode);

		// Check if this object has a visual filter
		if (obj->filter_type != 0)
		{
			// Filtered rendering: suspend -> offscreen -> blur -> resume -> composite
			renderer_suspend_pass(context);

			// 1. Render object into offscreen (MSAA resolve to filter_tex_a)
			renderer_begin_offscreen_pass(context);
			render_single_object(app_context, obj);
			renderer_end_offscreen_pass(context);

			// 2. Apply blur
			int is_shadow = (obj->filter_type == 2);
			int is_glow = (obj->filter_type == 3);
			int is_bevel = (obj->filter_type == 4);
			int colorize = is_shadow || is_glow;
			renderer_run_blur(context,
				obj->filter_blur_x, obj->filter_blur_y,
				obj->filter_quality, obj->filter_strength,
				obj->filter_color_r, obj->filter_color_g,
				obj->filter_color_b, obj->filter_color_a,
				colorize);

			// 3. Resume main pass and composite
			renderer_resume_pass(context);

			if (is_shadow)
			{
				// DropShadow: composite shadow with offset, then render original on top
				float angle_rad = obj->filter_angle * 3.14159265f / 180.0f;
				float dist_px = obj->filter_distance;
				float offset_ndc_x = cosf(angle_rad) * dist_px * 2.0f / (float)app_context->width;
				float offset_ndc_y = sinf(angle_rad) * dist_px * 2.0f / (float)app_context->height;
				renderer_composite_filtered(context, offset_ndc_x, -offset_ndc_y, 0, 0, 0, 0);
				render_single_object(app_context, obj);
			}
			else if (is_glow)
			{
				// Glow: composite glow behind, then render original on top
				renderer_composite_filtered(context, 0.0f, 0.0f, 0, 0, 0, 0);
				render_single_object(app_context, obj);
			}
			else if (is_bevel)
			{
				// Bevel: composite shadow + highlight at opposite offsets, then original
				float angle_rad = obj->filter_angle * 3.14159265f / 180.0f;
				float dist_px = obj->filter_distance;
				float shadow_ox = cosf(angle_rad) * dist_px * 2.0f / (float)app_context->width;
				float shadow_oy = sinf(angle_rad) * dist_px * 2.0f / (float)app_context->height;
				// Shadow: offset in angle direction, tinted with shadow color
				renderer_composite_filtered(context, shadow_ox, -shadow_oy,
					obj->filter_color_r, obj->filter_color_g,
					obj->filter_color_b, obj->filter_color_a);
				// Highlight: offset in opposite direction, tinted with highlight color
				renderer_composite_filtered(context, -shadow_ox, shadow_oy,
					obj->filter_highlight_r, obj->filter_highlight_g,
					obj->filter_highlight_b, obj->filter_highlight_a);
				render_single_object(app_context, obj);
			}
			else
			{
				// Pure blur: just composite the blurred result
				renderer_composite_filtered(context, 0.0f, 0.0f, 0, 0, 0, 0);
			}

			// Re-bind blend state after filter pipeline switches
			if (obj->blend_mode > 1)
				renderer_set_blend_mode(context, obj->blend_mode);
		}
		else
		{
			render_single_object(app_context, obj);
		}

		// Restore default blend mode
		if (obj->blend_mode > 1)
			renderer_set_blend_mode(context, 0);
	}

	if (active_clip_depth > 0)
	{
		renderer_end_clip(context);
	}

	renderer_close_pass(context);
#endif // NO_GRAPHICS

	// Dispatch _root.onLoad once after first frame
	actionDispatchRootOnLoad(app_context);

	// Advance placement generation so next frame's placements are distinguishable
	g_place_gen++;
}

#ifdef NO_GRAPHICS
// ---------------------------------------------------------------------------
// Sprite content bounds helper (in LOCAL twips of the sprite's own space)
// ---------------------------------------------------------------------------
// Returns 1 if any bounds were found. Bounds are relative to the sprite's
// registration point (i.e., the sprite's coordinate system origin).
static int sprite_content_bounds_twips(DisplayObject* dl, size_t dl_max,
    float* xmin_out, float* xmax_out, float* ymin_out, float* ymax_out)
{
	float xmin = 1e30f, xmax = -1e30f, ymin = 1e30f, ymax = -1e30f;
	int found = 0;

	for (size_t i = 1; i <= dl_max; i++)
	{
		DisplayObject* child = &dl[i];
		if (child->char_id == 0) continue;
		Character* ch = &dictionary[child->char_id];

		float tx = transform_data[child->transform_id][12];
		float ty = transform_data[child->transform_id][13];
		float sx = transform_data[child->transform_id][0];
		float sy = transform_data[child->transform_id][5];

		if (ch->type == CHAR_TYPE_SHAPE || ch->type == CHAR_TYPE_MORPH_SHAPE)
		{
			s32 cxmin, cxmax, cymin, cymax;
			if (ng_getCharBounds(child->char_id, &cxmin, &cxmax, &cymin, &cymax))
			{
				float x0 = tx + sx * (float)cxmin;
				float x1 = tx + sx * (float)cxmax;
				float y0 = ty + sy * (float)cymin;
				float y1 = ty + sy * (float)cymax;
				if (x0 > x1) { float t = x0; x0 = x1; x1 = t; }
				if (y0 > y1) { float t = y0; y0 = y1; y1 = t; }
				if (x0 < xmin) xmin = x0;
				if (x1 > xmax) xmax = x1;
				if (y0 < ymin) ymin = y0;
				if (y1 > ymax) ymax = y1;
				found = 1;
			}
		}
		else if (ch->type == CHAR_TYPE_SPRITE &&
		         child->sprite_display_list != NULL && child->sprite_max_depth > 0)
		{
			float cxmin, cxmax, cymin, cymax;
			if (sprite_content_bounds_twips(child->sprite_display_list, child->sprite_max_depth,
			        &cxmin, &cxmax, &cymin, &cymax))
			{
				float x0 = tx + sx * cxmin;
				float x1 = tx + sx * cxmax;
				float y0 = ty + sy * cymin;
				float y1 = ty + sy * cymax;
				if (x0 > x1) { float t = x0; x0 = x1; x1 = t; }
				if (y0 > y1) { float t = y0; y0 = y1; y1 = t; }
				if (x0 < xmin) xmin = x0;
				if (x1 > xmax) xmax = x1;
				if (y0 < ymin) ymin = y0;
				if (y1 > ymax) ymax = y1;
				found = 1;
			}
		}
	}

	if (found)
	{
		*xmin_out = xmin; *xmax_out = xmax;
		*ymin_out = ymin; *ymax_out = ymax;
	}
	return found;
}

// ---------------------------------------------------------------------------
// _droptarget computation: Z-order front-to-back traversal
// ---------------------------------------------------------------------------
// Iterates dl front-to-back (highest depth first).
// Named sprites: recurse into children; if children miss, return this sprite's path.
// Unnamed objects: absorb the hit and return parent_path.
// parent_stage_x/y: stage origin of the parent (twips), so entry stage origin =
//   parent_stage + transform_data[entry.transform_id][12/13].
static int find_drop_target_in_dl(DisplayObject* dl, size_t dl_max,
    float parent_stage_x, float parent_stage_y,
    float mouse_x, float mouse_y,
    const char* skip_name,
    const char* parent_path, char* out_path, size_t out_size)
{
	// Iterate front-to-back (highest depth first)
	for (size_t i = dl_max; i >= 1; i--)
	{
		DisplayObject* entry = &dl[i];
		if (entry->char_id == 0) continue;

		// Skip the dragged clip itself
		if (skip_name && entry->instance_name &&
		    strcmp(entry->instance_name, skip_name) == 0) continue;

		Character* ch = &dictionary[entry->char_id];

		float entry_stage_x = parent_stage_x + transform_data[entry->transform_id][12];
		float entry_stage_y = parent_stage_y + transform_data[entry->transform_id][13];
		float sx = transform_data[entry->transform_id][0];
		float sy = transform_data[entry->transform_id][5];

		// Compute AABB in stage twips
		float aabb_xmin, aabb_xmax, aabb_ymin, aabb_ymax;
		int has_aabb = 0;

		if (ch->type == CHAR_TYPE_SHAPE || ch->type == CHAR_TYPE_MORPH_SHAPE)
		{
			s32 cxmin, cxmax, cymin, cymax;
			if (ng_getCharBounds(entry->char_id, &cxmin, &cxmax, &cymin, &cymax))
			{
				float x0 = entry_stage_x + sx * (float)cxmin;
				float x1 = entry_stage_x + sx * (float)cxmax;
				float y0 = entry_stage_y + sy * (float)cymin;
				float y1 = entry_stage_y + sy * (float)cymax;
				if (x0 > x1) { float t = x0; x0 = x1; x1 = t; }
				if (y0 > y1) { float t = y0; y0 = y1; y1 = t; }
				aabb_xmin = x0; aabb_xmax = x1;
				aabb_ymin = y0; aabb_ymax = y1;
				has_aabb = 1;
			}
		}
		else if (ch->type == CHAR_TYPE_SPRITE)
		{
			if (entry->sprite_display_list != NULL && entry->sprite_max_depth > 0)
			{
				float lxmin, lxmax, lymin, lymax;
				if (sprite_content_bounds_twips(entry->sprite_display_list,
				        entry->sprite_max_depth, &lxmin, &lxmax, &lymin, &lymax))
				{
					float x0 = entry_stage_x + sx * lxmin;
					float x1 = entry_stage_x + sx * lxmax;
					float y0 = entry_stage_y + sy * lymin;
					float y1 = entry_stage_y + sy * lymax;
					if (x0 > x1) { float t = x0; x0 = x1; x1 = t; }
					if (y0 > y1) { float t = y0; y0 = y1; y1 = t; }
					aabb_xmin = x0; aabb_xmax = x1;
					aabb_ymin = y0; aabb_ymax = y1;
					has_aabb = 1;
				}
			}
		}

		if (!has_aabb) continue;

		// Point-in-AABB test
		if (mouse_x < aabb_xmin || mouse_x > aabb_xmax ||
		    mouse_y < aabb_ymin || mouse_y > aabb_ymax) continue;

		// Hit!
		if (entry->instance_name != NULL)
		{
			// Named entry: compute its path
			char entry_path[512];
			if (parent_path[0] == '\0')
				snprintf(entry_path, sizeof(entry_path), "/%s", entry->instance_name);
			else
				snprintf(entry_path, sizeof(entry_path), "%s/%s", parent_path, entry->instance_name);

			// If named sprite with children, recurse
			if (ch->type == CHAR_TYPE_SPRITE &&
			    entry->sprite_display_list != NULL && entry->sprite_max_depth > 0)
			{
				if (find_drop_target_in_dl(entry->sprite_display_list,
				        entry->sprite_max_depth,
				        entry_stage_x, entry_stage_y,
				        mouse_x, mouse_y,
				        skip_name, entry_path, out_path, out_size))
					return 1;
			}

			// Named but no child matched (or not a sprite): return this path
			snprintf(out_path, out_size, "%s", entry_path);
			return 1;
		}
		else
		{
			// Unnamed: absorb hit, return parent path
			snprintf(out_path, out_size, "%s", parent_path);
			return 1;
		}
	}
	return 0;
}

int ng_compute_droptarget(float stage_x_twips, float stage_y_twips,
    const char* skip_name, char* out_path, size_t out_size)
{
	if (out_size == 0) return 0;
	out_path[0] = '\0';
	return find_drop_target_in_dl(display_list, max_depth,
	    0.0f, 0.0f, stage_x_twips, stage_y_twips,
	    skip_name, "", out_path, out_size);
}

// ---------------------------------------------------------------------------
// CLIP_EVENT_PRESS / CLIP_EVENT_RELEASE dispatch
// ---------------------------------------------------------------------------
// Called from swf_core.c's input_events_deliver on EV_MOUSE_DOWN_LEFT / UP_LEFT.

void dispatch_clip_event_press(SWFAppContext* app_context)
{
	float mx = app_context->mouse.stage_x;  // twips
	float my = app_context->mouse.stage_y;  // twips

	for (size_t i = 1; i <= max_depth; i++)
	{
		DisplayObject* obj = &display_list[i];
		if (obj->char_id == 0 || obj->clip_action_count == 0) continue;

		int has_press = 0;
		for (size_t a = 0; a < obj->clip_action_count; a++)
		{
			if (obj->clip_actions[a].event_flags & CLIP_EVENT_PRESS) { has_press = 1; break; }
		}
		if (!has_press) continue;

		// Determine the stage origin for this sprite.
		// Use the persisted virtual position if this is the most-recently dragged clip.
		float orig_x, orig_y;
		if (g_drag_target_name[0] != '\0' && obj->instance_name &&
		    strcmp(obj->instance_name, g_drag_target_name) == 0)
		{
			orig_x = g_drag_virt_x;
			orig_y = g_drag_virt_y;
		}
		else
		{
			orig_x = transform_data[obj->transform_id][12];
			orig_y = transform_data[obj->transform_id][13];
		}

		// Compute sprite content AABB in stage twips
		int hit = 0;
		if (obj->sprite_display_list != NULL && obj->sprite_max_depth > 0)
		{
			float lxmin, lxmax, lymin, lymax;
			if (sprite_content_bounds_twips(obj->sprite_display_list, obj->sprite_max_depth,
			        &lxmin, &lxmax, &lymin, &lymax))
			{
				float sx = transform_data[obj->transform_id][0];
				float sy = transform_data[obj->transform_id][5];
				float stage_xmin = orig_x + sx * lxmin;
				float stage_xmax = orig_x + sx * lxmax;
				float stage_ymin = orig_y + sy * lymin;
				float stage_ymax = orig_y + sy * lymax;
				if (stage_xmin > stage_xmax) { float t = stage_xmin; stage_xmin = stage_xmax; stage_xmax = t; }
				if (stage_ymin > stage_ymax) { float t = stage_ymin; stage_ymin = stage_ymax; stage_ymax = t; }
				hit = (mx >= stage_xmin && mx <= stage_xmax &&
				       my >= stage_ymin && my <= stage_ymax);
			}
		}
		if (!hit) continue;

		obj->clip_mc_pressed = 1;
		MovieClip* saved_ctx = g_current_context;
		if (obj->instance_name)
		{
			MovieClip* mc = actionFindOrCreateMovieClip(app_context, obj->instance_name, &root_movieclip);
			if (mc) actionSetCurrentContext(mc);
		}
		for (size_t a = 0; a < obj->clip_action_count; a++)
		{
			if (obj->clip_actions[a].event_flags & CLIP_EVENT_PRESS)
				obj->clip_actions[a].action(app_context);
		}
		actionSetCurrentContext(saved_ctx);

		// If startDrag was called by the action, ensure g_drag_target_name matches this
		// sprite's actual instance name.  GetVariable("this") currently returns root_movieclip
		// so the target passed to actionStartDrag may be wrong ("_level0"); we correct it here.
		if (is_dragging && obj->instance_name && obj->instance_name[0] != '\0')
			snprintf(g_drag_target_name, sizeof(g_drag_target_name), "%s", obj->instance_name);
	}
}

void dispatch_clip_event_release(SWFAppContext* app_context)
{
	for (size_t i = 1; i <= max_depth; i++)
	{
		DisplayObject* obj = &display_list[i];
		if (obj->char_id == 0 || !obj->clip_mc_pressed) continue;
		if (obj->clip_action_count == 0) { obj->clip_mc_pressed = 0; continue; }

		obj->clip_mc_pressed = 0;
		MovieClip* saved_ctx = g_current_context;
		if (obj->instance_name)
		{
			MovieClip* mc = actionFindOrCreateMovieClip(app_context, obj->instance_name, &root_movieclip);
			if (mc) actionSetCurrentContext(mc);
		}
		for (size_t a = 0; a < obj->clip_action_count; a++)
		{
			if (obj->clip_actions[a].event_flags & CLIP_EVENT_RELEASE)
				obj->clip_actions[a].action(app_context);
		}
		actionSetCurrentContext(saved_ctx);
	}
}
// ---------------------------------------------------------------------------
// Generic clip event flag dispatch (MOUSE_DOWN/UP/MOVE, KEY_DOWN/UP)
// ---------------------------------------------------------------------------
// These are GLOBAL clip events — fire on ALL clips in the display list that
// have a matching clip action, regardless of mouse position.

static void dispatch_clip_event_flag_dl(SWFAppContext* app_context,
    DisplayObject* dl, size_t dl_max_depth, uint32_t flag, MovieClip* parent_mc)
{
	for (size_t i = 1; i <= dl_max_depth; i++)
	{
		DisplayObject* obj = &dl[i];
		if (obj->char_id == 0) continue;

		// Fire matching clip actions on this entry
		if (obj->clip_action_count > 0)
		{
			int has_flag = 0;
			for (size_t a = 0; a < obj->clip_action_count; a++)
			{
				if (obj->clip_actions[a].event_flags & flag) { has_flag = 1; break; }
			}
			if (has_flag)
			{
				MovieClip* saved_ctx = g_current_context;
				if (obj->instance_name)
				{
					MovieClip* mc = actionFindOrCreateMovieClip(app_context,
					    obj->instance_name, parent_mc);
					if (mc) actionSetCurrentContext(mc);
				}
				for (size_t a = 0; a < obj->clip_action_count; a++)
				{
					if (obj->clip_actions[a].event_flags & flag)
						obj->clip_actions[a].action(app_context);
				}
				actionSetCurrentContext(saved_ctx);
			}
		}

		// Recurse into sprite children
		if (obj->sprite_display_list != NULL && obj->sprite_max_depth > 0)
		{
			MovieClip* child_parent = parent_mc;
			if (obj->instance_name)
			{
				MovieClip* mc = actionFindOrCreateMovieClip(app_context,
				    obj->instance_name, parent_mc);
				if (mc) child_parent = mc;
			}
			dispatch_clip_event_flag_dl(app_context,
			    obj->sprite_display_list, obj->sprite_max_depth, flag, child_parent);
		}
	}
}

void dispatch_clip_event_flag(SWFAppContext* app_context, uint32_t flag)
{
	dispatch_clip_event_flag_dl(app_context, display_list, max_depth, flag,
	    &root_movieclip);
}

#endif // NO_GRAPHICS

void tagDefineShape(SWFAppContext* app_context, CharacterType type, size_t char_id,
    size_t shape_offset, size_t shape_size,
    s32 bounds_xmin, s32 bounds_xmax, s32 bounds_ymin, s32 bounds_ymax)
{
	(void)app_context;
	ENSURE_SIZE(dictionary, char_id, dictionary_capacity, sizeof(Character));

	dictionary[char_id].type = type;
	dictionary[char_id].shape_offset = shape_offset;
	dictionary[char_id].size = shape_size;

#ifdef NO_GRAPHICS
	ng_record_char_bounds(char_id, bounds_xmin, bounds_xmax, bounds_ymin, bounds_ymax);
#else
	(void)bounds_xmin; (void)bounds_xmax; (void)bounds_ymin; (void)bounds_ymax;
#endif
}

void tagDefineMorphShape(SWFAppContext* app_context, size_t char_id,
    size_t shape_offset, size_t shape_size,
    size_t morph_end_offset, size_t morph_color_start, size_t morph_color_count,
    s32 bounds_xmin, s32 bounds_xmax, s32 bounds_ymin, s32 bounds_ymax,
    s32 end_bounds_xmin, s32 end_bounds_xmax, s32 end_bounds_ymin, s32 end_bounds_ymax)
{
	(void)app_context;
	ENSURE_SIZE(dictionary, char_id, dictionary_capacity, sizeof(Character));

	dictionary[char_id].type = CHAR_TYPE_MORPH_SHAPE;
	dictionary[char_id].morph_start_offset = shape_offset;
	dictionary[char_id].morph_start_size = shape_size;
	dictionary[char_id].morph_end_offset = morph_end_offset;
	dictionary[char_id].morph_color_start = morph_color_start;
	dictionary[char_id].morph_color_count = morph_color_count;

#ifdef NO_GRAPHICS
	ng_record_char_bounds(char_id, bounds_xmin, bounds_xmax, bounds_ymin, bounds_ymax);
	ng_record_morph_end_bounds(char_id, end_bounds_xmin, end_bounds_xmax, end_bounds_ymin, end_bounds_ymax);
#else
	(void)bounds_xmin; (void)bounds_xmax; (void)bounds_ymin; (void)bounds_ymax;
	(void)end_bounds_xmin; (void)end_bounds_xmax; (void)end_bounds_ymin; (void)end_bounds_ymax;
#endif
}

void tagDefineText(SWFAppContext* app_context, size_t char_id, size_t text_start, size_t text_size, u32 transform_start, u32 cxform_id)
{
	(void)app_context;
	ENSURE_SIZE(dictionary, char_id, dictionary_capacity, sizeof(Character));

	if (dictionary[char_id].type == CHAR_TYPE_TEXT) {
		// Accumulate: extend text range to cover this additional text record
		size_t old_start = dictionary[char_id].text_start;
		size_t old_end = old_start + dictionary[char_id].text_size;
		size_t new_end = text_start + text_size;
		if (text_start < old_start) old_start = text_start;
		if (new_end > old_end) old_end = new_end;
		dictionary[char_id].text_start = old_start;
		dictionary[char_id].text_size = old_end - old_start;
	} else {
		dictionary[char_id].type = CHAR_TYPE_TEXT;
		dictionary[char_id].text_start = text_start;
		dictionary[char_id].text_size = text_size;
		dictionary[char_id].transform_start = transform_start;
		dictionary[char_id].cxform_id = cxform_id;
	}
}

void tagDefineEditTextProps(SWFAppContext* app_context, size_t char_id,
    const char* plain_text, const char* raw_html_text, u32 text_color,
    u16 font_id, u16 font_height, s16 max_length,
    u8 align, u16 left_margin, u16 right_margin, s16 indent, s16 leading,
    const char* variable_name, u16 flags,
    s32 bounds_xmin, s32 bounds_xmax, s32 bounds_ymin, s32 bounds_ymax)
{
#ifdef NO_GRAPHICS
	ng_record_textfield_props(app_context, char_id, plain_text, raw_html_text, text_color,
		font_id, font_height, max_length,
		align, left_margin, right_margin, indent, leading,
		variable_name, flags,
		bounds_xmin, bounds_xmax, bounds_ymin, bounds_ymax);
#else
	// Graphics mode doesn't need separate EditText properties tracking
	(void)app_context; (void)char_id; (void)plain_text; (void)raw_html_text;
	(void)text_color; (void)font_id; (void)font_height; (void)max_length;
	(void)align; (void)left_margin; (void)right_margin; (void)indent;
	(void)leading; (void)variable_name; (void)flags;
	(void)bounds_xmin; (void)bounds_xmax; (void)bounds_ymin; (void)bounds_ymax;
#endif
}

void tagCSMTextSettings(size_t text_id, const char* anti_alias_type, const char* grid_fit_type,
    float thickness, float sharpness)
{
#ifdef NO_GRAPHICS
	ng_record_csm(text_id, anti_alias_type, grid_fit_type, thickness, sharpness);
#else
	(void)text_id; (void)anti_alias_type; (void)grid_fit_type;
	(void)thickness; (void)sharpness;
#endif
}

// Initialize cx_* fields of a display object to identity color transform.
// Multipliers are in percentage format (100.0 = 100% = identity).
static void init_cx_fields(DisplayObject* obj)
{
	obj->cx_ra = obj->cx_ga = obj->cx_ba = obj->cx_aa = 100.0;
	obj->cx_rb = obj->cx_gb = obj->cx_bb = obj->cx_ab = 0.0;
	obj->cx_overridden = 0;
}

// Pending clip actions to attach before eager init runs — set by WithClipActions variants
static ClipAction* g_pending_clip_actions = NULL;
static size_t g_pending_clip_action_count = 0;

// Pending instance name — set by tagSetInstanceName before tagPlaceObject2 when the
// recompiler emits SetInstanceName after PlaceObject2. Consumed by ng_on_place_object2
// to avoid auto-assigning "instanceN" when the real name is known.
const char* g_pending_instance_name = NULL;
int g_skip_pending_removal_mc = 0;  // When set, findOrCreateMovieClip skips pending_removal MCs

// Recursively fire CLIP_EVENT_CONSTRUCT for child sprite display list entries
// that had CONSTRUCT deferred (placed during eager init with catch_up_mode=1).
static void fire_deferred_construct(SWFAppContext* app_context, DisplayObject* dl, size_t dl_max, MovieClip* parent_mc)
{
#ifdef NO_GRAPHICS
	for (size_t i = 1; i <= dl_max; i++) {
		if (dl[i].char_id == 0 || dl[i].clip_action_count == 0) continue;
		if (dl[i].instance_name == NULL) continue;
		MovieClip* mc = actionFindOrCreateMovieClip(app_context, dl[i].instance_name, parent_mc);
		MovieClip* saved_ctx = g_current_context;
		if (mc) actionSetCurrentContext(mc);
		for (size_t a = 0; a < dl[i].clip_action_count; a++) {
			if (dl[i].clip_actions[a].event_flags & CLIP_EVENT_CONSTRUCT)
				dl[i].clip_actions[a].action(app_context);
		}
		actionSetCurrentContext(saved_ctx);
		// Recurse into sprite children
		if (dl[i].sprite_display_list != NULL && dl[i].sprite_max_depth > 0) {
			fire_deferred_construct(app_context, dl[i].sprite_display_list, dl[i].sprite_max_depth, mc ? mc : parent_mc);
		}
	}
#endif
}

void tagPlaceObject2(SWFAppContext* app_context, size_t depth, size_t char_id, u32 transform_id, u32 cxform_id, u16 clip_depth)
{
#ifdef NO_GRAPHICS
	if (g_tag_skip_mode) return;
#endif
	ENSURE_SIZE(display_list, depth, display_list_capacity, sizeof(DisplayObject));

#ifdef NO_GRAPHICS
	// In script_only_mode (Phase 2), placement is already done from Phase 1 — skip entirely.
	if (g_script_only_mode) return;
#endif

	if (char_id == 0)
	{
		// Skip timeline modify on clips moved by swapDepths
		if (display_list[depth].depth_swapped) return;
		// Skip timeline modify on clips whose color transform was set by script
		// (e.g. Color.setTransform). In Flash, once script touches a display object's
		// color transform, subsequent PlaceObject2 modify operations are ignored
		// entirely — both the matrix and the color transform are preserved.
		if (display_list[depth].cx_overridden) return;
		// Modify operation (HasCharacter=0): update transform/cxform only, preserve identity.
		display_list[depth].transform_id = transform_id;
		display_list[depth].cxform_id = cxform_id;
		display_list[depth].has_cxform = (cxform_id != 0) ? 1 : 0;
		if (clip_depth != 0) display_list[depth].clip_depth = clip_depth;
		// Don't update placed_at_frame on modify — the object was originally placed
		// at the earlier frame. Updating here would cause ng_display_clear_after to
		// incorrectly remove the object during backward goto catch-up.
		init_cx_fields(&display_list[depth]);
		if (depth > max_depth) max_depth = depth;
#ifdef NO_GRAPHICS
		// Re-init cxform via ng_on_place_object2 (handles ng_init_cxform_from_data internally).
		// Pass actual char_id so type detection works.
		// Preserve sprite_needs_init if already set (sprite awaiting Phase 2 init from
		// a placement earlier in the same frame).
		u8 saved_needs_init = display_list[depth].sprite_needs_init;
		size_t actual_char_id = display_list[depth].char_id;
		ng_on_place_object2(app_context, depth, actual_char_id);
		if (saved_needs_init)
			display_list[depth].sprite_needs_init = saved_needs_init;
		else
			display_list[depth].sprite_needs_init = 0;
#else
		(void)app_context;
#endif
		return;
	}

#ifdef NO_GRAPHICS
	// During backward goto catch-up, if the same character is already at this depth,
	// preserve it (update transform only) instead of destroying and re-creating.
	// Flash preserves existing child movieclips during backward goto; their scripts
	// should NOT re-fire.
	{
		extern int catch_up_backward;
		extern size_t catch_up_target;
		if (catch_up_backward && display_list[depth].char_id != 0)
		{
			if (display_list[depth].char_id == char_id)
			{
				// Same character: treat as modify, preserve sprite state
				display_list[depth].transform_id = transform_id;
				display_list[depth].cxform_id = cxform_id;
				display_list[depth].has_cxform = (cxform_id != 0) ? 1 : 0;
				if (clip_depth != 0) display_list[depth].clip_depth = clip_depth;
				display_list[depth].placed_at_frame = current_frame;
				display_list[depth].place_gen = g_place_gen;
				init_cx_fields(&display_list[depth]);
				ng_on_place_object2(app_context, depth, char_id);
				display_list[depth].sprite_needs_init = 0;
				return;
			}
			// Different character at this depth during intermediate backward catch-up:
			// if the current occupant was placed at a later frame, skip this placement.
			// The later frame's tag will re-establish the correct entry.
			if (catch_up_mode && display_list[depth].placed_at_frame > current_frame)
			{
				return;
			}
		}
		// During backward catch-up, if this depth is empty but a depth_swapped entry
		// with the same char_id exists elsewhere, the character was moved by swapDepths.
		// Treat as re-placing the same character (update transform, suppress re-init)
		// to avoid creating a duplicate MovieClip.
		if (catch_up_backward && display_list[depth].char_id == 0 && char_id != 0)
		{
			for (size_t _sd = 1; _sd <= max_depth; _sd++) {
				if (_sd == depth) continue;
				if (display_list[_sd].char_id == char_id && display_list[_sd].depth_swapped) {
					// Found the swapped entry — place a fresh entry at this depth
					// but suppress sprite init (the MC already exists in cache).
					display_list[depth].char_id = char_id;
					display_list[depth].transform_id = transform_id;
					display_list[depth].cxform_id = cxform_id;
					display_list[depth].has_cxform = (cxform_id != 0) ? 1 : 0;
					display_list[depth].clip_depth = clip_depth;
					display_list[depth].ratio = 0;
					display_list[depth].blend_mode = 0;
					display_list[depth].sprite_display_list = NULL;
					display_list[depth].sprite_max_depth = 0;
					display_list[depth].sprite_dl_capacity = 0;
					display_list[depth].sprite_current_frame = 0;
					display_list[depth].sprite_is_playing = 1;
					display_list[depth].sprite_manual_next_frame = 0;
					display_list[depth].sprite_next_frame = 0;
					display_list[depth].sprite_needs_init = 0;  // suppress re-init
					display_list[depth].placed_at_frame = current_frame;
					display_list[depth].place_gen = g_place_gen;
					display_list[depth].depth_swapped = 0;
					init_cx_fields(&display_list[depth]);
					if (depth > max_depth) max_depth = depth;
					ng_on_place_object2(app_context, depth, char_id);
					display_list[depth].sprite_needs_init = 0;  // ensure no init
					return;
				}
			}
		}
	}
#endif

	// Root timeline loop-back preservation: when re-placing the SAME character at a depth
	// that already has an initialized sprite FROM A PREVIOUS FRAME, treat as modify
	// (update transform only). This matches Ruffle's run_goto behavior where existing
	// clips are preserved during root timeline looping (frame 4 -> frame 0).
	// Only applies across frame boundaries (different place_gen), NOT within same frame.
	if (display_list[depth].char_id == char_id && display_list[depth].char_id != 0
	    && display_list[depth].sprite_display_list != NULL
	    && display_list[depth].place_gen != g_place_gen)
	{
		display_list[depth].transform_id = transform_id;
		display_list[depth].cxform_id = cxform_id;
		display_list[depth].has_cxform = (cxform_id != 0) ? 1 : 0;
		if (clip_depth != 0) display_list[depth].clip_depth = clip_depth;
		display_list[depth].placed_at_frame = current_frame;
		display_list[depth].place_gen = g_place_gen;
		init_cx_fields(&display_list[depth]);
		if (depth > max_depth) max_depth = depth;
		ng_on_place_object2(app_context, depth, char_id);
		display_list[depth].sprite_needs_init = 0;
		return;
	}

	// Within-same-frame placement conflict handling
	if (display_list[depth].char_id != 0 && display_list[depth].place_gen == g_place_gen)
	{
		if (display_list[depth].char_id != char_id)
		{
			// Flash rejects placing a different character at a depth already occupied this frame
			printf("Warning: Failed to place object at depth %zu.\n", depth);
			return;
		}
		// Same character at same depth in same frame: treat as modify (don't re-init)
		display_list[depth].transform_id = transform_id;
		display_list[depth].cxform_id = cxform_id;
		display_list[depth].has_cxform = (cxform_id != 0) ? 1 : 0;
		if (clip_depth != 0) display_list[depth].clip_depth = clip_depth;
		init_cx_fields(&display_list[depth]);
		if (depth > max_depth) max_depth = depth;
		return;
	}

	display_list[depth].char_id = char_id;
	display_list[depth].transform_id = transform_id;
	display_list[depth].cxform_id = cxform_id;
	display_list[depth].has_cxform = (cxform_id != 0) ? 1 : 0;
	display_list[depth].clip_depth = clip_depth;
	display_list[depth].ratio = 0;
	display_list[depth].blend_mode = 0;
	display_list[depth].sprite_display_list = NULL;
	display_list[depth].sprite_max_depth = 0;
	display_list[depth].sprite_dl_capacity = 0;
	display_list[depth].sprite_current_frame = 0;
	display_list[depth].sprite_is_playing = 1;
	display_list[depth].sprite_manual_next_frame = 0;
	display_list[depth].sprite_next_frame = 0;
	// Free old instance name if we own it
	if (display_list[depth].instance_name_owned && display_list[depth].instance_name != NULL)
	{
		free(display_list[depth].instance_name);
	}
	display_list[depth].instance_name = NULL;
	display_list[depth].instance_name_owned = 0;
	display_list[depth].clip_actions = NULL;
	display_list[depth].clip_action_count = 0;
	display_list[depth].filter_type = 0;
	display_list[depth].depth_swapped = 0;
	// Restore persistent button state if the same character is being re-placed
	// (e.g. a looping movie that removes+replaces a button each frame cycle).
	if (display_list[depth].sticky_char_id == char_id && char_id != 0)
	{
		display_list[depth].button_state = display_list[depth].sticky_button_state;
		display_list[depth].button_prev_state = display_list[depth].sticky_button_state;
	}
	else
	{
		display_list[depth].button_state = 0;
		display_list[depth].button_prev_state = 0;
		display_list[depth].sticky_button_state = 0;
		display_list[depth].sticky_char_id = 0;
	}
	display_list[depth].sprite_needs_init = 0;
	display_list[depth].placed_at_frame = current_frame;
	display_list[depth].place_gen = g_place_gen;
	display_list[depth].constructor_invoked = 0;
	init_cx_fields(&display_list[depth]);

	if (depth > max_depth)
	{
		max_depth = depth;
	}

#ifdef NO_GRAPHICS
	ng_on_place_object2(app_context, depth, char_id);

	// Consume pending clip actions (set by WithClipActions variants).
	// Reset immediately so nested tagPlaceObject2 calls during eager init
	// don't inherit the parent's clip actions.
	if (g_pending_clip_actions != NULL) {
		display_list[depth].clip_actions = g_pending_clip_actions;
		display_list[depth].clip_action_count = g_pending_clip_action_count;
		g_pending_clip_actions = NULL;
		g_pending_clip_action_count = 0;
	}

	// Fire CLIP_EVENT_INITIALIZE immediately at placement time (before eager init)
	if (display_list[depth].clip_action_count > 0 && display_list[depth].instance_name != NULL) {
		MovieClip* _parent_mc = g_current_context ? g_current_context : &root_movieclip;
		MovieClip* saved_ctx = g_current_context;
		MovieClip* _mc = actionFindOrCreateMovieClip(app_context, display_list[depth].instance_name, _parent_mc);
		if (_mc) actionSetCurrentContext(_mc);
		for (size_t a = 0; a < display_list[depth].clip_action_count; a++) {
			if (display_list[depth].clip_actions[a].event_flags & CLIP_EVENT_INITIALIZE)
				display_list[depth].clip_actions[a].action(app_context);
		}
		actionSetCurrentContext(saved_ctx);
	}

	// Eagerly execute sprite frame 0 immediately after placement so the sprite's
	// internal display list is populated BEFORE the parent frame's ActionScript runs.
	// This matches Flash AVM1 behavior: sprites placed via PlaceObject2 are
	// "constructed" (frame 0 executed) before the parent's DoAction scripts.
	if (display_list[depth].sprite_needs_init)
	{
		if (dictionary[char_id].type == CHAR_TYPE_SPRITE)
		{
			Character* sp_ch = &dictionary[char_id];
			if (sp_ch->sprite_frame_funcs != NULL && sp_ch->sprite_frame_funcs[0] != NULL)
			{
				display_list[depth].sprite_needs_init = 2; // mark: frame_0 done, scripts deferred
				DisplayObject* saved_dl = display_list;
				size_t saved_max = max_depth;
				size_t saved_cap = display_list_capacity;
				display_list = saved_dl[depth].sprite_display_list;
				max_depth = saved_dl[depth].sprite_max_depth;
				display_list_capacity = saved_dl[depth].sprite_dl_capacity;
				// Phase 1: run with catch_up_mode=1 so only placement tags execute;
				// DoAction scripts are deferred to tagShowFrame Phase 2.
				int saved_catch_up = catch_up_mode;
				catch_up_mode = 1;
				CALL_FRAME(app_context, &saved_dl[depth], sp_ch->sprite_frame_funcs[0]);
				catch_up_mode = saved_catch_up;
				saved_dl[depth].sprite_display_list = display_list;
				saved_dl[depth].sprite_max_depth = max_depth;
				saved_dl[depth].sprite_dl_capacity = display_list_capacity;
				display_list = saved_dl;
				max_depth = saved_max;
				display_list_capacity = saved_cap;
				saved_dl[depth].sprite_current_frame = (sp_ch->sprite_frame_count > 0) ? (1 % sp_ch->sprite_frame_count) : 0;
			}
		}
	}

	// Fire CLIP_EVENT_CONSTRUCT after eager init (children placed, their initialize fired)
	// But only at the top level — during catch_up_mode (inside another clip's eager init),
	// CONSTRUCT is deferred to fire_deferred_construct below.
	if (!catch_up_mode && display_list[depth].clip_action_count > 0 && display_list[depth].instance_name != NULL) {
		MovieClip* _parent_mc = g_current_context ? g_current_context : &root_movieclip;
		MovieClip* saved_ctx = g_current_context;
		MovieClip* _mc = actionFindOrCreateMovieClip(app_context, display_list[depth].instance_name, _parent_mc);
		if (_mc) actionSetCurrentContext(_mc);
		// Set __proto__ to registered class prototype BEFORE on(construct) fires
		// so prototype properties are accessible in the handler
		{
			extern const char* ng_lookupExportName(size_t char_id);
			extern void actionSetupRegisteredClassPrototype(SWFAppContext*, const char*, MovieClip*);
			const char* _exp = ng_lookupExportName(display_list[depth].char_id);
			if (_exp != NULL && _mc != NULL)
				actionSetupRegisteredClassPrototype(app_context, _exp, _mc);
		}
		for (size_t a = 0; a < display_list[depth].clip_action_count; a++) {
			if (display_list[depth].clip_actions[a].event_flags & CLIP_EVENT_CONSTRUCT)
				display_list[depth].clip_actions[a].action(app_context);
		}
		actionSetCurrentContext(saved_ctx);
		// Fire deferred CONSTRUCT for child clips placed during eager init
		if (display_list[depth].sprite_display_list != NULL && display_list[depth].sprite_max_depth > 0) {
			fire_deferred_construct(app_context, display_list[depth].sprite_display_list,
				display_list[depth].sprite_max_depth, _mc ? _mc : _parent_mc);
		}
	}

#else
	(void)app_context;
#endif
}

void tagPlaceObject2WithClipActions(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, ClipAction* clip_actions, size_t clip_action_count)
{
#ifdef NO_GRAPHICS
	if (g_tag_skip_mode) return;
#endif
	// Set pending so tagPlaceObject2 attaches them before eager init
	g_pending_clip_actions = clip_actions;
	g_pending_clip_action_count = clip_action_count;
	tagPlaceObject2(app_context, depth, char_id, transform_id, cxform_id, clip_depth);
	// tagPlaceObject2 consumes g_pending_clip_actions and fires events
	g_pending_clip_actions = NULL;
	g_pending_clip_action_count = 0;
}

void tagSetClipActions(SWFAppContext* app_context, size_t depth, ClipAction* clip_actions, size_t clip_action_count)
{
	(void)app_context;
	if (depth < display_list_capacity && display_list[depth].char_id != 0)
	{
		display_list[depth].clip_actions = clip_actions;
		display_list[depth].clip_action_count = clip_action_count;
	}
}

void tagPlaceObject2Ratio(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, u16 ratio)
{
#ifdef NO_GRAPHICS
	if (g_tag_skip_mode) return;
#endif
	ENSURE_SIZE(display_list, depth, display_list_capacity, sizeof(DisplayObject));

#ifdef NO_GRAPHICS
	// During backward goto catch-up, preserve existing sprite at same depth/char
	{
		extern int catch_up_backward;
		extern int catch_up_mode;
		if (catch_up_backward && display_list[depth].char_id != 0)
		{
			if (display_list[depth].char_id == char_id)
			{
				display_list[depth].transform_id = transform_id;
				display_list[depth].cxform_id = cxform_id;
				display_list[depth].has_cxform = (cxform_id != 0) ? 1 : 0;
				if (clip_depth != 0) display_list[depth].clip_depth = clip_depth;
				display_list[depth].ratio = ratio;
				display_list[depth].placed_at_frame = current_frame;
				display_list[depth].place_gen = g_place_gen;
				init_cx_fields(&display_list[depth]);
				ng_on_place_object2(app_context, depth, char_id);
				display_list[depth].sprite_needs_init = 0;
				return;
			}
			if (catch_up_mode && display_list[depth].placed_at_frame > current_frame)
			{
				return;
			}
		}
	}
#endif

	// char_id=0 means "modify existing entry" (PlaceObject2 without HasCharacter)
	if (char_id == 0 && display_list[depth].char_id != 0)
	{
		// Update only the fields that PlaceObject2 can modify
		if (transform_id != 0) display_list[depth].transform_id = transform_id;
		if (cxform_id != 0) {
			display_list[depth].cxform_id = cxform_id;
			display_list[depth].has_cxform = 1;
		}
		if (clip_depth != 0) display_list[depth].clip_depth = clip_depth;
		display_list[depth].ratio = ratio;
		return;
	}

	display_list[depth].char_id = char_id;
	display_list[depth].transform_id = transform_id;
	display_list[depth].cxform_id = cxform_id;
	display_list[depth].has_cxform = (cxform_id != 0) ? 1 : 0;
	display_list[depth].clip_depth = clip_depth;
	display_list[depth].ratio = ratio;
	display_list[depth].blend_mode = 0;
	display_list[depth].sprite_display_list = NULL;
	display_list[depth].sprite_max_depth = 0;
	display_list[depth].sprite_dl_capacity = 0;
	display_list[depth].sprite_current_frame = 0;
	display_list[depth].sprite_is_playing = 1;
	display_list[depth].sprite_manual_next_frame = 0;
	display_list[depth].sprite_next_frame = 0;
	display_list[depth].instance_name = NULL;
	display_list[depth].instance_name_owned = 0;
	display_list[depth].clip_actions = NULL;
	display_list[depth].clip_action_count = 0;
	display_list[depth].filter_type = 0;
	display_list[depth].depth_swapped = 0;
	// Restore persistent button state if the same character is being re-placed
	// (e.g. a looping movie that removes+replaces a button each frame cycle).
	if (display_list[depth].sticky_char_id == char_id && char_id != 0)
	{
		display_list[depth].button_state = display_list[depth].sticky_button_state;
		display_list[depth].button_prev_state = display_list[depth].sticky_button_state;
	}
	else
	{
		display_list[depth].button_state = 0;
		display_list[depth].button_prev_state = 0;
		display_list[depth].sticky_button_state = 0;
		display_list[depth].sticky_char_id = 0;
	}
	display_list[depth].sprite_needs_init = 0;
	display_list[depth].placed_at_frame = current_frame;
	display_list[depth].place_gen = g_place_gen;
	display_list[depth].constructor_invoked = 0;
	init_cx_fields(&display_list[depth]);

	if (depth > max_depth)
	{
		max_depth = depth;
	}

#ifdef NO_GRAPHICS
	ng_on_place_object2(app_context, depth, char_id);

	// Consume pending clip actions (set by WithClipActions variants).
	// Reset immediately so nested tagPlaceObject2 calls during eager init
	// don't inherit the parent's clip actions.
	if (g_pending_clip_actions != NULL) {
		display_list[depth].clip_actions = g_pending_clip_actions;
		display_list[depth].clip_action_count = g_pending_clip_action_count;
		g_pending_clip_actions = NULL;
		g_pending_clip_action_count = 0;
	}

	// Fire CLIP_EVENT_INITIALIZE immediately at placement time (before eager init)
	if (display_list[depth].clip_action_count > 0 && display_list[depth].instance_name != NULL) {
		MovieClip* _parent_mc = g_current_context ? g_current_context : &root_movieclip;
		MovieClip* saved_ctx = g_current_context;
		MovieClip* _mc = actionFindOrCreateMovieClip(app_context, display_list[depth].instance_name, _parent_mc);
		if (_mc) actionSetCurrentContext(_mc);
		for (size_t a = 0; a < display_list[depth].clip_action_count; a++) {
			if (display_list[depth].clip_actions[a].event_flags & CLIP_EVENT_INITIALIZE)
				display_list[depth].clip_actions[a].action(app_context);
		}
		actionSetCurrentContext(saved_ctx);
	}

	// Eagerly execute sprite frame 0 immediately after placement so the sprite's
	// internal display list is populated BEFORE the parent frame's ActionScript runs.
	// Same eager init as tagPlaceObject2 — needed for scripts that access children before tagShowFrame.
	if (display_list[depth].sprite_needs_init)
	{
		if (dictionary[char_id].type == CHAR_TYPE_SPRITE)
		{
			Character* sp_ch = &dictionary[char_id];
			if (sp_ch->sprite_frame_funcs != NULL && sp_ch->sprite_frame_funcs[0] != NULL)
			{
				display_list[depth].sprite_needs_init = 2; // mark: frame_0 done, scripts deferred
				DisplayObject* saved_dl = display_list;
				size_t saved_max = max_depth;
				size_t saved_cap = display_list_capacity;
				display_list = saved_dl[depth].sprite_display_list;
				max_depth = saved_dl[depth].sprite_max_depth;
				display_list_capacity = saved_dl[depth].sprite_dl_capacity;
				// Phase 1: run with catch_up_mode=1 so only placement tags execute;
				// DoAction scripts are deferred to tagShowFrame Phase 2.
				int saved_catch_up = catch_up_mode;
				catch_up_mode = 1;
				CALL_FRAME(app_context, &saved_dl[depth], sp_ch->sprite_frame_funcs[0]);
				catch_up_mode = saved_catch_up;
				saved_dl[depth].sprite_display_list = display_list;
				saved_dl[depth].sprite_max_depth = max_depth;
				saved_dl[depth].sprite_dl_capacity = display_list_capacity;
				display_list = saved_dl;
				max_depth = saved_max;
				display_list_capacity = saved_cap;
				saved_dl[depth].sprite_current_frame = (sp_ch->sprite_frame_count > 0) ? (1 % sp_ch->sprite_frame_count) : 0;
			}
		}
	}

	// Fire CLIP_EVENT_CONSTRUCT after eager init (children placed, their initialize fired)
	// But only at the top level — during catch_up_mode (inside another clip's eager init),
	// CONSTRUCT is deferred to fire_deferred_construct below.
	if (!catch_up_mode && display_list[depth].clip_action_count > 0 && display_list[depth].instance_name != NULL) {
		MovieClip* _parent_mc = g_current_context ? g_current_context : &root_movieclip;
		MovieClip* saved_ctx = g_current_context;
		MovieClip* _mc = actionFindOrCreateMovieClip(app_context, display_list[depth].instance_name, _parent_mc);
		if (_mc) actionSetCurrentContext(_mc);
		// Set __proto__ to registered class prototype BEFORE on(construct) fires
		// so prototype properties are accessible in the handler
		{
			extern const char* ng_lookupExportName(size_t char_id);
			extern void actionSetupRegisteredClassPrototype(SWFAppContext*, const char*, MovieClip*);
			const char* _exp = ng_lookupExportName(display_list[depth].char_id);
			if (_exp != NULL && _mc != NULL)
				actionSetupRegisteredClassPrototype(app_context, _exp, _mc);
		}
		for (size_t a = 0; a < display_list[depth].clip_action_count; a++) {
			if (display_list[depth].clip_actions[a].event_flags & CLIP_EVENT_CONSTRUCT)
				display_list[depth].clip_actions[a].action(app_context);
		}
		actionSetCurrentContext(saved_ctx);
		// Fire deferred CONSTRUCT for child clips placed during eager init
		if (display_list[depth].sprite_display_list != NULL && display_list[depth].sprite_max_depth > 0) {
			fire_deferred_construct(app_context, display_list[depth].sprite_display_list,
				display_list[depth].sprite_max_depth, _mc ? _mc : _parent_mc);
		}
	}

#else
	(void)app_context;
#endif
}

void tagPlaceObject2RatioWithClipActions(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, u16 ratio, ClipAction* clip_actions, size_t clip_action_count)
{
#ifdef NO_GRAPHICS
	if (g_tag_skip_mode) return;
#endif
	// Set pending so tagPlaceObject2Ratio attaches them before eager init
	g_pending_clip_actions = clip_actions;
	g_pending_clip_action_count = clip_action_count;
	tagPlaceObject2Ratio(app_context, depth, char_id, transform_id, cxform_id, clip_depth, ratio);
	// tagPlaceObject2Ratio consumes g_pending_clip_actions and fires events
	g_pending_clip_actions = NULL;
	g_pending_clip_action_count = 0;
}

// Replace an existing clip at `depth` in the same frame: does NOT fire CLIP_EVENT_UNLOAD
// for the old clip's actions. Instead, saves them as accumulated_clip_actions on the new
// entry so they fire (before new_clip_actions) when the new entry is eventually removed.
// The old MC gets its depth transformed and is marked for deferred invalidation (persists one frame).
void tagReplaceObject2RatioWithClipActions(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, u16 ratio,
    ClipAction* old_clip_actions, size_t old_clip_action_count,
    ClipAction* new_clip_actions, size_t new_clip_action_count)
{
#ifdef NO_GRAPHICS
	char* saved_name = display_list[depth].instance_name;
	if (saved_name != NULL) {
		// Check if old MC has unload handler (clip_actions UNLOAD or AS-level onUnload).
		// Only persist the old MC if it does; otherwise invalidate immediately.
		int has_unload = 0;
		for (size_t ca = 0; ca < old_clip_action_count; ca++) {
			if (old_clip_actions[ca].event_flags & 0x4) {
				has_unload = 1;
				break;
			}
		}
		if (!has_unload)
			has_unload = actionMCHasOnUnloadProperty(saved_name, (int)depth);

		if (has_unload) {
			actionMarkMCPendingRemoval(app_context, saved_name, (int)depth);
		} else {
			actionInvalidateCachedMovieClip(app_context, saved_name, (int)depth);
		}
	}

	// Set the old instance name as pending so ng_on_place_object2 picks it up
	// for the new MC (tagPlaceObject2Ratio clears instance_name to NULL).
	if (saved_name != NULL) {
		extern const char* g_pending_instance_name;
		g_pending_instance_name = saved_name;
	}

	// Tell findOrCreateMovieClip to skip the old MC (with pending_removal)
	// so a fresh MC is created for the new display entry.
	g_skip_pending_removal_mc = 1;
#endif

	// Place the new clip (clears all fields including clip_actions)
	tagPlaceObject2Ratio(app_context, depth, char_id, transform_id, cxform_id, clip_depth, ratio);

#ifdef NO_GRAPHICS
	// Ensure the NEW clip MC is created in the cache so actionMarkMCPendingRemoval
	// can find it when this entry is later removed from the display list.
	// Keep g_skip_pending_removal_mc=1 so we create a fresh MC (not reuse the old one).
	if (display_list[depth].instance_name != NULL) {
		extern MovieClip root_movieclip;
		actionFindOrCreateMovieClip(app_context, display_list[depth].instance_name, &root_movieclip);
	}
	g_skip_pending_removal_mc = 0;
#endif

	// Set new clip actions
	display_list[depth].clip_actions = new_clip_actions;
	display_list[depth].clip_action_count = new_clip_action_count;
	// Accumulate old clip actions to fire before new_clip_actions on next removal
	display_list[depth].accumulated_clip_actions = old_clip_actions;
	display_list[depth].accumulated_clip_action_count = old_clip_action_count;
}

static void clear_display_entry(SWFAppContext* app_context, size_t depth)
{
	if (display_list[depth].instance_name_owned && display_list[depth].instance_name != NULL)
	{
		free(display_list[depth].instance_name);  // system free: strdup'd string
	}
	if (display_list[depth].sprite_display_list != NULL)
	{
		FREE(display_list[depth].sprite_display_list);  // heap free: HCALLOC'd buffer
		display_list[depth].sprite_display_list = NULL;
	}
	// Preserve button state so it can be restored if the same char is re-placed
	// (handles looping movies that remove+replace a button each frame cycle).
	if (display_list[depth].char_id != 0)
	{
		display_list[depth].sticky_char_id = display_list[depth].char_id;
		display_list[depth].sticky_button_state = display_list[depth].button_state;
	}
	display_list[depth].char_id = 0;
	display_list[depth].transform_id = 0;
	display_list[depth].cxform_id = 0;
	display_list[depth].has_cxform = 0;
	display_list[depth].clip_depth = 0;
	display_list[depth].instance_name = NULL;
	display_list[depth].instance_name_owned = 0;
	display_list[depth].clip_actions = NULL;
	display_list[depth].clip_action_count = 0;
	display_list[depth].accumulated_clip_actions = NULL;
	display_list[depth].accumulated_clip_action_count = 0;
}

// Recursively fire CLIP_EVENT_UNLOAD for children of a display object.
// Fires children-first (depth order within each sprite's display list),
// recursing into nested sprites before firing the child's own unload.
static void fire_recursive_child_unloads(SWFAppContext* app_context,
	DisplayObject* dl, size_t dl_max, MovieClip* parent_mc)
{
	for (size_t i = 1; i <= dl_max; i++)
	{
		DisplayObject* obj = &dl[i];
		if (obj->char_id == 0) continue;

		// Recurse into nested sprite's children first (even if this obj has no clip actions)
		if (obj->sprite_display_list != NULL && obj->sprite_max_depth > 0)
		{
			MovieClip* child_mc = NULL;
			if (obj->instance_name != NULL)
				child_mc = actionFindOrCreateMovieClip(app_context, obj->instance_name, parent_mc);
			fire_recursive_child_unloads(app_context,
				obj->sprite_display_list, obj->sprite_max_depth,
				child_mc ? child_mc : parent_mc);
		}

		// Fire this child's CLIP_EVENT_UNLOAD
		if (obj->clip_action_count == 0) continue;
		MovieClip* saved_ctx = g_current_context;
		if (obj->instance_name != NULL)
		{
			MovieClip* mc = actionFindOrCreateMovieClip(app_context, obj->instance_name, parent_mc);
			if (mc) actionSetCurrentContext(mc);
		}
		for (size_t a = 0; a < obj->clip_action_count; a++)
		{
			if (obj->clip_actions[a].event_flags & CLIP_EVENT_UNLOAD)
				obj->clip_actions[a].action(app_context);
		}
		actionSetCurrentContext(saved_ctx);
	}
}

void tagRemoveObject(SWFAppContext* app_context, size_t depth)
{
	if (depth <= max_depth && display_list[depth].char_id != 0)
	{
		// Fire accumulated clip actions (from prior Remove+Replace cycle) first
		if (display_list[depth].accumulated_clip_action_count > 0)
		{
			for (size_t a = 0; a < display_list[depth].accumulated_clip_action_count; a++)
			{
				if (display_list[depth].accumulated_clip_actions[a].event_flags & CLIP_EVENT_UNLOAD)
					display_list[depth].accumulated_clip_actions[a].action(app_context);
			}
			display_list[depth].accumulated_clip_actions = NULL;
			display_list[depth].accumulated_clip_action_count = 0;
		}
		// Dispatch onUnload clip actions before clearing
		if (display_list[depth].clip_action_count > 0)
		{
			for (size_t a = 0; a < display_list[depth].clip_action_count; a++)
			{
				if (display_list[depth].clip_actions[a].event_flags & CLIP_EVENT_UNLOAD)
					display_list[depth].clip_actions[a].action(app_context);
			}
		}
#ifdef NO_GRAPHICS
		ng_on_remove_object(app_context, depth);
#endif
		clear_display_entry(app_context, depth);
	}
#ifndef NO_GRAPHICS
	(void)app_context;
#endif
}

void tagRemoveObject2(SWFAppContext* app_context, size_t depth)
{
#ifdef NO_GRAPHICS
	if (g_tag_skip_mode) return;
#endif
	if (depth <= max_depth && display_list[depth].char_id != 0)
	{
#ifdef NO_GRAPHICS
		// During backward catch-up, protect entries placed at or before the target frame.
		// They're part of the preserved state and will be re-established by replay.
		extern int catch_up_backward;
		extern size_t catch_up_target;
		if (catch_up_backward && display_list[depth].placed_at_frame <= catch_up_target)
			return;
#endif
		// Fire accumulated clip actions (from prior Remove+Replace cycle) first
		if (display_list[depth].accumulated_clip_action_count > 0)
		{
			for (size_t a = 0; a < display_list[depth].accumulated_clip_action_count; a++)
			{
				if (display_list[depth].accumulated_clip_actions[a].event_flags & CLIP_EVENT_UNLOAD)
					display_list[depth].accumulated_clip_actions[a].action(app_context);
			}
			display_list[depth].accumulated_clip_actions = NULL;
			display_list[depth].accumulated_clip_action_count = 0;
		}
		// Fire CLIP_EVENT_UNLOAD for children first (recursive, depth-first)
#ifdef NO_GRAPHICS
		if (display_list[depth].sprite_display_list != NULL && display_list[depth].sprite_max_depth > 0)
		{
			MovieClip* parent_mc = NULL;
			if (display_list[depth].instance_name != NULL)
				parent_mc = actionFindOrCreateMovieClip(app_context, display_list[depth].instance_name, &root_movieclip);
			fire_recursive_child_unloads(app_context,
				display_list[depth].sprite_display_list, display_list[depth].sprite_max_depth,
				parent_mc ? parent_mc : &root_movieclip);
		}
#endif
		// Dispatch current onUnload clip actions before clearing
		if (display_list[depth].clip_action_count > 0)
		{
			MovieClip* saved_ctx = g_current_context;
			if (display_list[depth].instance_name != NULL)
			{
				MovieClip* mc = actionFindOrCreateMovieClip(app_context, display_list[depth].instance_name, &root_movieclip);
				if (mc) actionSetCurrentContext(mc);
			}
			for (size_t a = 0; a < display_list[depth].clip_action_count; a++)
			{
				if (display_list[depth].clip_actions[a].event_flags & CLIP_EVENT_UNLOAD)
					display_list[depth].clip_actions[a].action(app_context);
			}
			actionSetCurrentContext(saved_ctx);
		}
#ifdef NO_GRAPHICS
		ng_on_remove_object(app_context, depth);
#endif
		clear_display_entry(app_context, depth);
	}
#ifndef NO_GRAPHICS
	(void)app_context;
#endif
}

void tagDefineSprite(SWFAppContext* app_context, size_t char_id, frame_func* funcs, size_t frame_count)
{
	(void)app_context;
	ENSURE_SIZE(dictionary, char_id, dictionary_capacity, sizeof(Character));

	dictionary[char_id].type = CHAR_TYPE_SPRITE;
	dictionary[char_id].sprite_frame_funcs = funcs;
	dictionary[char_id].sprite_frame_count = frame_count;
}

// Per-sprite frame label storage (separate from Character union)
#define MAX_SPRITE_LABEL_ENTRIES 256
static struct {
	size_t char_id;
	FrameLabelEntry* labels;
	size_t count;
} sprite_label_store[MAX_SPRITE_LABEL_ENTRIES];
static size_t sprite_label_store_count = 0;

void tagSetSpriteLabels(size_t char_id, FrameLabelEntry* labels, size_t count)
{
	if (sprite_label_store_count >= MAX_SPRITE_LABEL_ENTRIES) return;
	sprite_label_store[sprite_label_store_count].char_id = char_id;
	sprite_label_store[sprite_label_store_count].labels = labels;
	sprite_label_store[sprite_label_store_count].count = count;
	sprite_label_store_count++;
}

int ng_findSpriteLabelFrame(size_t char_id, const char* label)
{
	if (!label) return -1;
	for (size_t i = 0; i < sprite_label_store_count; i++)
	{
		if (sprite_label_store[i].char_id == char_id)
		{
			FrameLabelEntry* entries = sprite_label_store[i].labels;
			size_t count = sprite_label_store[i].count;
			// Exact match first
			for (size_t j = 0; j < count; j++)
			{
				if (entries[j].label && strcmp(entries[j].label, label) == 0)
					return (int)entries[j].frame;
			}
			// Case-insensitive fallback (ASCII only, like Flash)
			for (size_t j = 0; j < count; j++)
			{
				if (entries[j].label && strcasecmp(entries[j].label, label) == 0)
					return (int)entries[j].frame;
			}
			return -1;
		}
	}
	return -1;
}

void tagDefineButton(SWFAppContext* app_context, size_t char_id, frame_func* state_funcs, size_t hit_char_id, u32 hit_transform_id, ButtonAction* actions, size_t action_count)
{
	(void)app_context;
	ENSURE_SIZE(dictionary, char_id, dictionary_capacity, sizeof(Character));

	dictionary[char_id].type = CHAR_TYPE_BUTTON;
	dictionary[char_id].button_state_funcs = state_funcs;
	dictionary[char_id].button_hit_char_id = hit_char_id;
	dictionary[char_id].button_hit_transform_id = hit_transform_id;
	dictionary[char_id].button_actions = actions;
	dictionary[char_id].button_action_count = action_count;

#ifdef NO_GRAPHICS
	ng_record_button(char_id);
#endif
}

// Convert a Flash key code to the SWF button condition key code.
// Button conditions use their own mapping for special keys (1-19) and
// ASCII for printable characters (32+). Letters are lowercase in conditions.
static int flash_key_to_button_cond(int key_code)
{
	// Special keys: Flash key code → SWF button condition code
	switch (key_code) {
	case 37: return 1;   // Left
	case 39: return 2;   // Right
	case 36: return 3;   // Home
	case 35: return 4;   // End
	case 45: return 5;   // Insert
	case 46: return 6;   // Delete
	case 8:  return 8;   // Backspace
	case 13: return 13;  // Enter
	case 38: return 14;  // Up
	case 40: return 15;  // Down
	case 33: return 16;  // Page Up
	case 34: return 17;  // Page Down
	case 9:  return 18;  // Tab
	case 27: return 19;  // Escape
	case 32: return 32;  // Space
	default: break;
	}
	// Letters: Flash key codes are uppercase (65-90), button conditions are lowercase (97-122)
	if (key_code >= 65 && key_code <= 90)
		return key_code + 32;  // to lowercase ASCII
	// Numbers and other printable: same code
	if (key_code >= 32 && key_code <= 126)
		return key_code;
	return 0;
}

// Dispatch button key-press BUTTONCONDACTION conditions for a given Flash key code.
// KeyPress propagates to all buttons in render order (low depth to high depth).
// First button that handles the event stops propagation (Ruffle behavior).
// Returns 1 if any button handled the keyPress, 0 otherwise.
int dispatch_button_key_actions(SWFAppContext* app_context, int key_code)
{
	int cond_code = flash_key_to_button_cond(key_code);
	if (cond_code <= 0) return 0;
	for (size_t i = 1; i <= max_depth; i++)
	{
		DisplayObject* obj = &display_list[i];
		if (obj->char_id == 0) continue;
		Character* ch = &dictionary[obj->char_id];
		if (ch->type != CHAR_TYPE_BUTTON) continue;
		if (ch->button_action_count == 0) continue;
		// Skip invisible buttons — _visible=false suppresses keyPress conditions
		if (obj->instance_name != NULL && !actionGetMCVisible(app_context, obj->instance_name))
			continue;
		int handled = 0;
		for (size_t a = 0; a < ch->button_action_count; a++)
		{
			int cond_key = (ch->button_actions[a].condition >> 9) & 0x7F;
			if (cond_key != 0 && cond_key == cond_code)
			{
				ch->button_actions[a].action(app_context);
				handled = 1;
			}
		}
		if (handled) return 1;  // first button to handle stops propagation
	}
	return 0;
}

// Fire button DoAction conditions for a specific transition on a MC.
// transition_mask: 0x0004 = OverUpToOverDown (press), 0x0008 = OverDownToOverUp (release)
void ng_simulateButtonTransition(SWFAppContext* app_context, void* mc_ptr, int transition_mask)
{
	MovieClip* mc = (MovieClip*)mc_ptr;
	if (mc == NULL || !mc->is_button_mc) return;
	if (!mc->name || mc->name[0] == '\0') return;
	size_t depth = ng_findDisplayEntryByName(mc->name);
	if (depth == SIZE_MAX || depth > max_depth) return;
	DisplayObject* obj = &display_list[depth];
	if (obj->char_id == 0) return;
	Character* ch = &dictionary[obj->char_id];
	if (ch->type != CHAR_TYPE_BUTTON) return;
	for (size_t a = 0; a < ch->button_action_count; a++) {
		if (ch->button_actions[a].condition & transition_mask)
			ch->button_actions[a].action(app_context);
	}
}

// Simulate a button press+release (both transitions). Used as fallback when
// the caller doesn't need to interleave handlers between press and release.
void ng_simulateButtonPressRelease(SWFAppContext* app_context, void* mc_ptr)
{
	ng_simulateButtonTransition(app_context, mc_ptr, 0x0004); // press
	ng_simulateButtonTransition(app_context, mc_ptr, 0x0008); // release
}

void tagPlaceObject3(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, u8 blend_mode)
{
	tagPlaceObject2(app_context, depth, char_id, transform_id, cxform_id, clip_depth);
	display_list[depth].blend_mode = blend_mode;
}

void tagSetFilter(SWFAppContext* app_context, size_t depth,
    u8 type, float blur_x, float blur_y, u8 quality, u8 flags,
    float r, float g, float b, float a, float strength,
    float angle, float distance)
{
	(void)app_context;
	if (depth <= max_depth)
	{
		display_list[depth].filter_type = type;
		display_list[depth].filter_blur_x = blur_x;
		display_list[depth].filter_blur_y = blur_y;
		display_list[depth].filter_quality = quality;
		display_list[depth].filter_flags = flags;
		display_list[depth].filter_color_r = r;
		display_list[depth].filter_color_g = g;
		display_list[depth].filter_color_b = b;
		display_list[depth].filter_color_a = a;
		display_list[depth].filter_strength = strength;
		display_list[depth].filter_angle = angle;
		display_list[depth].filter_distance = distance;
	}
}

void tagSetFilterHighlight(SWFAppContext* app_context, size_t depth,
    float r, float g, float b, float a)
{
	(void)app_context;
	if (depth <= max_depth)
	{
		display_list[depth].filter_highlight_r = r;
		display_list[depth].filter_highlight_g = g;
		display_list[depth].filter_highlight_b = b;
		display_list[depth].filter_highlight_a = a;
	}
}

void tagSetInstanceName(SWFAppContext* app_context, size_t depth, const char* name)
{
	(void)app_context;
#ifdef NO_GRAPHICS
	// In script_only_mode (Phase 2), display list is already set up from Phase 1 — skip.
	if (g_script_only_mode) return;

	// If the display entry doesn't exist yet (tagSetInstanceName called before tagPlaceObject2),
	// store as pending so ng_on_place_object2 uses it instead of auto-assigning "instanceN".
	if (depth > max_depth || display_list[depth].char_id == 0)
	{
		g_pending_instance_name = name;
		return;
	}
#endif
	if (depth <= max_depth)
	{
		char* old_name = display_list[depth].instance_name;
		// Rename cached MC if it was previously given a different name (e.g. auto-assigned)
#ifdef NO_GRAPHICS
		if (old_name != NULL && strcmp(old_name, name) != 0)
			actionRenameMovieClip(old_name, name);
#endif
		// Free auto-assigned name if we own it; reclaim counter slot if it was the last one
		if (display_list[depth].instance_name_owned && old_name != NULL)
		{
#ifdef NO_GRAPHICS
			ng_try_reclaim_auto_instance_name(old_name);
#endif
			free(old_name);
		}
		display_list[depth].instance_name = (char*)name;
		display_list[depth].instance_name_owned = 0;

#ifdef NO_GRAPHICS
		// Invoke registered class constructor now that the instance name is set.
		// This fires after tagPlaceObject2 (which did eager init) but before DoAction scripts.
		if (!catch_up_mode && display_list[depth].sprite_needs_init
		    && !display_list[depth].constructor_invoked
		    && display_list[depth].char_id != 0
		    && dictionary[display_list[depth].char_id].type == CHAR_TYPE_SPRITE)
		{
			extern const char* ng_lookupExportName(size_t char_id);
			extern void actionInvokeRegisteredClassConstructor(SWFAppContext* app_context, const char* export_name, MovieClip* mc);
			extern void actionSetupRegisteredClassPrototype(SWFAppContext*, const char*, MovieClip*);
			const char* _exp_ctor = ng_lookupExportName(display_list[depth].char_id);
			if (_exp_ctor != NULL) {
				extern MovieClip root_movieclip;
				extern MovieClip* g_current_context;
				MovieClip* _parent_mc = g_current_context ? g_current_context : &root_movieclip;
				MovieClip* _ctor_mc = actionFindOrCreateMovieClip(app_context, name, _parent_mc);
				if (_ctor_mc != NULL) {
					actionSetupRegisteredClassPrototype(app_context, _exp_ctor, _ctor_mc);
					actionInvokeRegisteredClassConstructor(app_context, _exp_ctor, _ctor_mc);
					display_list[depth].constructor_invoked = 1;
				}
			}
		}

		// Recursively fire constructors for child sprites placed during eager init.
		// This ensures child constructors fire right after the parent constructor,
		// matching Flash's execution order.
		// Only do this when the parent was a registered class sprite with children.
		if (display_list[depth].constructor_invoked
		    && display_list[depth].sprite_display_list != NULL && display_list[depth].sprite_max_depth > 0)
		{
			extern const char* ng_lookupExportName(size_t char_id);
			extern void actionInvokeRegisteredClassConstructor(SWFAppContext* app_context, const char* export_name, MovieClip* mc);
			extern void actionSetupRegisteredClassPrototype(SWFAppContext*, const char*, MovieClip*);
			extern MovieClip* g_current_context;

			DisplayObject* saved_dl = display_list;
			size_t saved_max = max_depth;
			size_t saved_cap = display_list_capacity;
			display_list = saved_dl[depth].sprite_display_list;
			max_depth = saved_dl[depth].sprite_max_depth;
			display_list_capacity = saved_dl[depth].sprite_dl_capacity;

			MovieClip* _child_parent = actionFindOrCreateMovieClip(app_context, name,
				g_current_context ? g_current_context : &root_movieclip);
			for (size_t ci = 1; ci <= max_depth; ci++)
			{
				DisplayObject* cobj = &display_list[ci];
				if (cobj->char_id == 0 || cobj->constructor_invoked) continue;
				if (dictionary[cobj->char_id].type != CHAR_TYPE_SPRITE) continue;

				const char* _child_exp = ng_lookupExportName(cobj->char_id);
				if (_child_exp == NULL) continue;

				MovieClip* _child_mc = (cobj->instance_name != NULL)
					? actionFindOrCreateMovieClip(app_context, cobj->instance_name, _child_parent)
					: NULL;
				if (_child_mc != NULL) {
					actionSetupRegisteredClassPrototype(app_context, _child_exp, _child_mc);
					actionInvokeRegisteredClassConstructor(app_context, _child_exp, _child_mc);
					cobj->constructor_invoked = 1;
				}
			}

			// Save back (realloc possible)
			saved_dl[depth].sprite_display_list = display_list;
			saved_dl[depth].sprite_max_depth = max_depth;
			saved_dl[depth].sprite_dl_capacity = display_list_capacity;

			display_list = saved_dl;
			max_depth = saved_max;
			display_list_capacity = saved_cap;
		}
#endif
	}
}

DisplayObject* findDisplayObjectByName(const char* name)
{
	for (size_t i = 0; i <= max_depth; ++i)
	{
		if (display_list[i].char_id == 0) continue;
		if (display_list[i].instance_name != NULL &&
		    strcmp(display_list[i].instance_name, name) == 0)
			return &display_list[i];
	}
	return NULL;
}

void tagDefineFontInfo(SWFAppContext* app_context, u16 font_id, const char* name, int bold, int italic)
{
#ifdef NO_GRAPHICS
	ng_record_font(app_context, font_id, name, bold, italic);
#else
	(void)app_context; (void)font_id; (void)name; (void)bold; (void)italic;
#endif
}

void tagDefineFontMetrics(SWFAppContext* app_context, u16 font_id,
    s16 ascent, s16 descent, s16 leading, int em_square,
    const u16* code_table, const s16* advance_table, size_t glyph_count)
{
#ifdef NO_GRAPHICS
	ng_record_font_metrics(app_context, font_id, ascent, descent, leading, em_square,
	    code_table, advance_table, glyph_count);
#else
	(void)app_context; (void)font_id; (void)ascent; (void)descent; (void)leading;
	(void)em_square; (void)code_table; (void)advance_table; (void)glyph_count;
#endif
}

void tagDefineVideoStream(SWFAppContext* app_context, u16 char_id)
{
#ifdef NO_GRAPHICS
	ng_record_video(app_context, char_id);
#else
	(void)app_context; (void)char_id;
#endif
}

// tagRegisterExport: in NO_GRAPHICS mode, implemented in tag_stubs.c.
// In graphics mode, provide a no-op stub.
#ifndef NO_GRAPHICS
void tagRegisterExport(SWFAppContext* app_context, const char* name, size_t char_id)
{
	(void)app_context; (void)name; (void)char_id;
}
#endif

#ifdef NO_GRAPHICS
// Returns 1 if any multi-frame sprite at root level is playing or has pending navigation.
// A sprite with sprite_manual_next_frame=1 has a pending gotoAndStop/gotoAndPlay that
// advance_sprite_frames must process, even if sprite_is_playing is false.
int hasPlayingSprites(void)
{
	for (size_t i = 1; i <= max_depth; i++)
	{
		if (display_list[i].char_id == 0) continue;
		Character* ch = &dictionary[display_list[i].char_id];
		if (ch->type == CHAR_TYPE_SPRITE &&
		    ch->sprite_frame_count > 1 &&
		    (display_list[i].sprite_is_playing || display_list[i].sprite_manual_next_frame))
			return 1;
	}
	return 0;
}

// Check if any display_list entry (recursive) has CLIP_EVENT_ENTER_FRAME clip actions
// and is initialized (sprite_initialized >= 2). Used to keep the frame loop alive.
static int hasClipEnterFrameHandlers_impl(DisplayObject* dl, size_t dl_max)
{
	for (size_t i = 1; i <= dl_max; i++)
	{
		if (dl[i].char_id == 0) continue;
		if (dl[i].sprite_initialized < 2) continue;
		if (dl[i].clip_action_count > 0)
		{
			for (size_t a = 0; a < dl[i].clip_action_count; a++)
				if (dl[i].clip_actions[a].event_flags & CLIP_EVENT_ENTER_FRAME) return 1;
		}
		if (dl[i].sprite_display_list != NULL && dl[i].sprite_max_depth > 0)
			if (hasClipEnterFrameHandlers_impl(dl[i].sprite_display_list, dl[i].sprite_max_depth))
				return 1;
	}
	return 0;
}
int hasClipEnterFrameHandlers(void)
{
	return hasClipEnterFrameHandlers_impl(display_list, max_depth);
}

// Run deferred sprite-init with optional frame filter.
// filter_mode: 0=all, 1=only placed_at_frame < target, 2=only placed_at_frame >= target
static void ng_run_deferred_sprite_init_impl(SWFAppContext* app_context, int filter_mode, size_t target_frame)
{
	extern void ng_sync_root_display_obj(void);
	ng_sync_root_display_obj();

	extern int child_mc_count;
	extern int g_enterframe_new_mc_start;
	int mc_count_before = child_mc_count;

	if (filter_mode != 0)
	{
		g_sprite_init_filter_active = 1;
		g_sprite_init_before_target = (filter_mode == 1) ? 1 : 0;
		g_sprite_init_target_frame = target_frame;
	}

	catch_up_mode = 0;
	process_sprite_needs_init(app_context, &root_movieclip);

	g_sprite_init_filter_active = 0;

	ng_fire_pending_loads(app_context);
	ng_fire_pending_attach_inits(app_context);
	actionFirePendingLoadInits(app_context);

	g_enterframe_new_mc_start = mc_count_before;
	actionDispatchEnterFrameHandlers(app_context);
	g_enterframe_new_mc_start = -1;
}

// Run ALL deferred sprite inits (used when no target frame distinction needed).
void ng_run_deferred_sprite_init(SWFAppContext* app_context)
{
	ng_run_deferred_sprite_init_impl(app_context, 0, 0);
}

// Run deferred sprite inits only for sprites placed BEFORE target_frame.
// Ruffle phase 1: children placed before target frame init before target DoAction.
void ng_run_deferred_sprite_init_before(SWFAppContext* app_context, size_t target_frame)
{
	ng_run_deferred_sprite_init_impl(app_context, 1, target_frame);
}

// Run deferred sprite inits only for sprites placed ON or AFTER target_frame.
// Ruffle phase 3: children placed on target frame init after target DoAction.
void ng_run_deferred_sprite_init_on_or_after(SWFAppContext* app_context, size_t target_frame)
{
	ng_run_deferred_sprite_init_impl(app_context, 2, target_frame);
}

// Clear display entries whose placed_at_frame is after target_frame.
// Used by swf_core.c when seeking backward on the main timeline.
void ng_display_clear_after(SWFAppContext* app_context, size_t target_frame)
{
	for (size_t i = 1; i <= max_depth; i++)
	{
		if (display_list[i].char_id != 0 &&
		    display_list[i].placed_at_frame > target_frame)
		{
			if (display_list[i].sprite_display_list != NULL)
			{
				FREE(display_list[i].sprite_display_list);
				display_list[i].sprite_display_list = NULL;
			}
			display_list[i].char_id = 0;
		}
	}
}
#endif // NO_GRAPHICS

#ifndef NO_GRAPHICS
void defineBitmap(size_t offset, size_t size, u32 width, u32 height)
{
	renderer_upload_bitmap(context, offset, size, width, height);
}

void finalizeBitmaps()
{
	renderer_finalize_bitmaps(context);
}
#endif // NO_GRAPHICS
