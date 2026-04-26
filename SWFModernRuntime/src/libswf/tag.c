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

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#if !defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)
#include <renderer.h>
extern RenderContext* context;
#endif

// action.h is needed in all modes (g_current_context, actionFindOrCreateMovieClip, etc.)
#include <action.h>

// ActionQueue API for clip-event migration (Phase 4+ of ACTION_QUEUE_PLAN).
#include <actionmodern/action_queue.h>

// Frame execution state — defined in swf_core.c (NO_GRAPHICS), swf_headless.c (HEADLESS), swf.c (GRAPHICS)
extern int catch_up_mode;
extern int g_tag_skip_mode;

// Per-movie transform data mapping (indexed by movie_id, 0 = main SWF).
// Set during actionImportAssets/actionFirePendingLoadInits so that sprites from
// child movies can reference the correct transform array during frame execution.
// Needed in all build modes (NO_GRAPHICS, HEADLESS, and graphics).
#define MAX_MOVIE_TRANSFORM_ENTRIES 16
static float (*g_movie_transform_data[MAX_MOVIE_TRANSFORM_ENTRIES])[16] = {0};

void ng_registerMovieTransformData(u8 movie_id, float (*td)[16]) {
	if (movie_id < MAX_MOVIE_TRANSFORM_ENTRIES)
		g_movie_transform_data[movie_id] = td;
}

#if defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)
// NO_GRAPHICS / HEADLESS: extern data arrays from generated code
extern float transform_data[][16];
extern float cxform_data[];

// Active transform data pointer — defaults to main SWF's transform_data.
// Swapped to child SWF's array during child movie init so that tagPlaceObject2
// caches correct transform values on display objects (needed for getBounds on loaded movies).
float (*g_active_transform_data)[16] = NULL;

static inline void ng_cache_transform(DisplayObject* obj, u32 tid) {
	float (*td)[16] = g_active_transform_data ? g_active_transform_data : transform_data;
	obj->place_a  = td[tid][0];
	obj->place_b  = td[tid][1];
	obj->place_c  = td[tid][4];
	obj->place_d  = td[tid][5];
	obj->place_tx = td[tid][12];
	obj->place_ty = td[tid][13];
}
#endif

size_t dictionary_capacity = INITIAL_DICTIONARY_CAPACITY;
size_t display_list_capacity = INITIAL_DISPLAYLIST_CAPACITY;

// Per-character movie_id tracking (which movie defined each character).
// Used to look up the correct transform_data for child movie sprites.
u8* g_char_movie_id = NULL;
size_t g_char_movie_id_capacity = 0;

// Note: tagInit() is provided by the generated tagMain.c file

// Monotonically increasing counter to detect within-same-frame placement conflicts.
// Incremented at the end of each tagShowFrame call and before goto catch-up.
// Used by tagPlaceObject2 in all build modes.
size_t g_place_gen = 0;

#ifdef NO_GRAPHICS
// Tracks the currently-executing sprite's DisplayObject.
// Set by advance_sprite_frames before each sprite frame function call.
DisplayObject* g_current_sprite_obj = NULL;

// Root display list backup for inline catch-up from within sprite init context.
// Saved on the first entry into process_sprite_init_at_depth (nesting == 0)
// so that inline catch-up of root gotos can temporarily swap to the root DL.
static DisplayObject* g_root_dl_backup = NULL;
static size_t g_root_dl_max_backup = 0;
static size_t g_root_dl_cap_backup = 0;
static int g_sprite_init_depth = 0;

int ng_isInsideSpriteInit(void) { return g_sprite_init_depth > 0; }

// Phase 7b: exposed for aq_dispatch_sprite_script so sprite DoAction scripts
// drained at the root-level SHOW_FRAME pre-drain still report "inside sprite
// init" — pre-7b ran them inside process_sprite_init_at_depth which kept
// this flag >0 for the duration. Inline goto catch-up (actionNextFrame /
// actionGotoFrame / CallMethod("nextFrame"...)) depends on this flag to
// remove _root display entries synchronously before the next halt check —
// without it, the MC outlives the script and halt-on-removal is skipped.
// Matching depth bump ALSO sets g_root_dl_backup on the 0→1 transition so
// that nested ng_executeGotoCatchUp's ng_swapToRootDL finds the right root DL
// (harmless no-op when dispatch is already running in root DL context).
void ng_bumpSpriteInitDepth(void) {
	if (g_sprite_init_depth == 0) {
		g_root_dl_backup = display_list;
		g_root_dl_max_backup = max_depth;
		g_root_dl_cap_backup = display_list_capacity;
	}
	g_sprite_init_depth++;
}
void ng_unbumpSpriteInitDepth(void) {
	if (g_sprite_init_depth > 0) g_sprite_init_depth--;
	if (g_sprite_init_depth == 0) {
		// Restore display list in case inline catch-up swapped
		display_list = g_root_dl_backup;
		max_depth = g_root_dl_max_backup;
		display_list_capacity = g_root_dl_cap_backup;
	}
}

int ng_swapToRootDL(DisplayObject** saved_dl, size_t* saved_max, size_t* saved_cap) {
	if (g_sprite_init_depth <= 0) return 0;
	// Save current (sprite) DL
	*saved_dl = display_list;
	*saved_max = max_depth;
	*saved_cap = display_list_capacity;
	// Swap to root DL
	display_list = g_root_dl_backup;
	max_depth = g_root_dl_max_backup;
	display_list_capacity = g_root_dl_cap_backup;
	return 1;
}

void ng_restoreFromRootDL(DisplayObject* saved_dl, size_t saved_max, size_t saved_cap) {
	// Commit root DL changes (may have been modified by catch-up)
	g_root_dl_backup = display_list;
	g_root_dl_max_backup = max_depth;
	g_root_dl_cap_backup = display_list_capacity;
	// Restore sprite DL
	display_list = saved_dl;
	max_depth = saved_max;
	display_list_capacity = saved_cap;
}

// When 1, tagPlaceObject2 and tagSetInstanceName are no-ops.
// Used by tagShowFrame to re-run sprite frame_0 for scripts only (Phase 2),
// without disturbing the display list already set up in Phase 1 (eager init).
// Phase 7b: exposed via actionScriptOnlyMode() accessor so recompiler-emitted
// sprite DoAction queue calls can skip re-queueing during the Phase 2 re-run
// (scripts are already queued from Phase 1).
int g_script_only_mode = 0;

// When 1, tagShowFrame defers process_sprite_needs_init.
// Set by ng_executeGotoCatchUp so sprite init scripts run AFTER the deferred
// parent-frame DoAction (matching Ruffle's execution order).
int g_defer_sprite_init = 0;

// Tracks nesting depth of eager init in tagPlaceObject2.
// Used to determine whether constructor invocation is at the top level
// (g_eager_init_depth==0) or inside a nested sprite's eager init.
// Phase 7b: exposed via actionEagerInitActive() accessor. ng_attachMovie,
// ng_cloneSprite, and ng_duplicateMovieClip bump this around their frame_0
// invocations (via actionEagerInit{Enter,Leave}()) so recompiler-emitted
// sprite DoAction queue calls fire during runtime-attach paths too.
static int g_eager_init_depth = 0;

// Set while ng_update_button_states_in_dl re-runs a button's state function
// after a state transition (e.g. up → over when the mouse is inside the hit
// area on the first tick). The state func re-places the button's children,
// which re-triggers tagPlaceObject2's Phase 1 eager init for any sprite
// children and would re-queue their frame_0 scripts via the 7b sprite DoAction
// gate. Pre-7b, Phase 1 eager did not queue scripts (catch_up_mode=1 was
// enough to suppress); 7b's gate widened to also queue during eager init, so
// the button-state-transition path started double-firing sprite scripts.
// Flash/Ruffle button state children persist across transitions — their
// frame_0 scripts only fire on initial construction. Suppress the eager
// init term of the sprite DoAction gate while this counter is non-zero so
// the transition's re-placement is visual-only, matching pre-7b.
// Key test: avm1/issue_9885.
static int g_button_state_change_depth = 0;

int actionEagerInitActive(void) {
	return g_eager_init_depth > 0 && g_button_state_change_depth == 0;
}
int actionScriptOnlyMode(void)  { return g_script_only_mode; }

// Phase 7b: set by ng_executeGotoCatchUp around its funcs[f] replay loop
// (step 2). Suppresses sprite-DoAction queueing so scripts don't fire in
// FIFO before the target frame's root script (queued later in step 3).
int g_goto_catchup_active = 0;
int actionGotoCatchupActive(void) { return g_goto_catchup_active; }
void actionGotoCatchupEnter(void) { g_goto_catchup_active++; }
void actionGotoCatchupLeave(void) { g_goto_catchup_active--; }

// Phase 7b: set by ng_run_deferred_sprite_init_impl around its
// process_sprite_needs_init call. Combined with actionScriptOnlyMode,
// switches the sprite DoAction gate into synchronous-fire mode for the
// Phase 2 re-run that completes a goto's deferred sprite init.
int g_deferred_sprite_init_active = 0;
int actionDeferredSpriteInitActive(void) { return g_deferred_sprite_init_active; }
void actionDeferredSpriteInitEnter(void) { g_deferred_sprite_init_active++; }
void actionDeferredSpriteInitLeave(void) { g_deferred_sprite_init_active--; }

// Wrappers called by tag_stubs.c runtime-attach paths (ng_attachMovie,
// ng_cloneSprite, ng_duplicateMovieClip) around their Phase 1 frame_0
// invocations. g_eager_init_depth stays file-local to tag.c; tag_stubs.c
// uses these wrappers instead of touching the variable directly.
void actionEagerInitEnter(void) { g_eager_init_depth++; }
void actionEagerInitLeave(void) { g_eager_init_depth--; }

// When 1, process_sprite_init_at_depth only fires constructors (no Phase 2 scripts).
// Used by ng_fire_deferred_constructors to separate constructor invocation
// from Phase 2 script execution.
static int g_constructor_only_mode = 0;

// Frame filter for process_sprite_needs_init during deferred init.
// When g_sprite_init_filter_active=1, only process sprites matching the filter:
//   g_sprite_init_before_target=1: only placed_at_frame < g_sprite_init_target_frame
//   g_sprite_init_before_target=0: only placed_at_frame == g_sprite_init_target_frame
// The on_or_after case uses == (not >=) so a nested goto placing sprites at
// frames beyond the outer goto's target doesn't spuriously fire them during
// the outer Phase 3. In a single non-nested goto, catch-up only places
// sprites up to target_frame inclusive, so == and >= would be equivalent.
static int g_sprite_init_filter_active = 0;
static int g_sprite_init_before_target = 0;
static size_t g_sprite_init_target_frame = 0;

// Phase 7a forward declarations (definitions after queue_register_ctor).
// Phase 7b: parent_mc is captured at queue time (g_current_context during
// the parent sprite's Phase 1 eager init) so the dispatcher can do the
// correct MC lookup at drain time. Without this, the function_base_clip_readded
// canary regresses because aq_dispatch_clip_load would fall back to root
// as parent, giving a wrong _parent for nested clips.
typedef struct {
	DisplayObject* obj;
	frame_func action;
	MovieClip* parent_mc;
} PendingClipLoad;

// g_settarget_explicit_root: set by actionSetTarget("_root"/"") to distinguish
// "goto root" from "goto unnamed sprite with inherited root context".
// Declared in action.c; saved/cleared/restored here per sprite-frame invocation.
extern int g_settarget_explicit_root;
extern int g_settarget_invalid;
extern int g_settarget_none;
extern int g_settarget_context_changed;
extern MovieClip* g_settarget_saved_context;
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
	int saved_ctx_changed = g_settarget_context_changed;
	MovieClip* saved_ctx_save = g_settarget_saved_context;
	g_settarget_explicit_root = 0;
	g_settarget_invalid = 0;
	g_settarget_none = 0;
	g_settarget_context_changed = 0;
	g_settarget_saved_context = NULL;

	// Set active transform data to child SWF's array if this sprite belongs to
	// a child movie (prevents buffer overflow when child has more transforms).
	float (*saved_td)[16] = g_active_transform_data;
	if (obj->child_transform_data != NULL)
		g_active_transform_data = obj->child_transform_data;

	f(app_context);

	g_active_transform_data = saved_td;
	g_settarget_explicit_root = saved_settarget;
	g_settarget_invalid = saved_invalid;
	g_settarget_none = saved_none;
	g_settarget_context_changed = saved_ctx_changed;
	g_settarget_saved_context = saved_ctx_save;
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
		for (size_t i = 0; i <= max_depth && i < 256; i++)
		{
			DisplayObject* obj = &display_list[i];
			if (obj->char_id == 0 || !obj->sprite_needs_init) continue;
			if (g_sprite_init_before_target && obj->placed_at_frame >= g_sprite_init_target_frame)
				continue;
			if (!g_sprite_init_before_target && obj->placed_at_frame != g_sprite_init_target_frame)
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

	// Normal path: iterate by depth (start at 0 to handle depth-0 placements)
	for (size_t i = 0; i <= max_depth; i++)
		process_sprite_init_at_depth(app_context, parent_mc, i);
}

static void process_sprite_init_at_depth(SWFAppContext* app_context, MovieClip* parent_mc, size_t i)
{
		DisplayObject* obj = &display_list[i];
		if (obj->char_id == 0 || !obj->sprite_needs_init) {
			return;
		}

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

			// Set totalframes/framesloaded from the sprite definition BEFORE
			// clip actions fire (onLoad reads _totalframes/_framesloaded).
			if (child_mc) {
				child_mc->totalframes = (int)ch->sprite_frame_count;
				child_mc->framesloaded = (int)ch->sprite_frame_count;
				if (ch->sprite_frame_count == 0)
					child_mc->currentframe = 0;
			}

			// In constructor_only mode, only fire constructors (no Phase 2 scripts).
			// Keep sprite_needs_init set so the later script pass can find this sprite.
			if (g_constructor_only_mode)
			{
				if (!obj->constructor_invoked)
				{
					extern const char* ng_lookupExportName(size_t char_id);
					extern void actionInvokeRegisteredClassConstructor(SWFAppContext* app_context, const char* export_name, MovieClip* mc);
					extern void actionSetupRegisteredClassPrototype(SWFAppContext*, const char*, MovieClip*);
					const char* export_name = ng_lookupExportName(obj->char_id);
					if (export_name != NULL && child_mc != NULL)
					{
						child_mc->display_obj = (void*)obj;
						actionSetupRegisteredClassPrototype(app_context, export_name, child_mc);
						actionInvokeRegisteredClassConstructor(app_context, export_name, child_mc);
						obj->constructor_invoked = 1;
					}
				}
				// Recurse into children to fire their constructors
				if (obj->sprite_display_list != NULL && obj->sprite_max_depth > 0)
				{
					DisplayObject* saved_dl = display_list;
					size_t saved_max = max_depth;
					size_t saved_cap = display_list_capacity;
					display_list = obj->sprite_display_list;
					max_depth = obj->sprite_max_depth;
					display_list_capacity = obj->sprite_dl_capacity;
					process_sprite_needs_init(app_context, child_mc);
					obj->sprite_display_list = display_list;
					obj->sprite_max_depth = max_depth;
					obj->sprite_dl_capacity = display_list_capacity;
					display_list = saved_dl;
					max_depth = saved_max;
					display_list_capacity = saved_cap;
				}
				return;
			}

			// sprite_needs_init == 2: Phase 1 (placement) ran eagerly; run Phase 2
			// (scripts only) now. sprite_needs_init == 1: normal deferred path.
			int was_eager = (obj->sprite_needs_init == 2);
			obj->sprite_needs_init = 0;

			// Track root DL for inline catch-up (only on outermost sprite init)
			if (g_sprite_init_depth == 0) {
				g_root_dl_backup = display_list;
				g_root_dl_max_backup = max_depth;
				g_root_dl_cap_backup = display_list_capacity;
			}
			g_sprite_init_depth++;

			// Context swap to sprite's display list
			DisplayObject* saved_dl    = display_list;
			size_t         saved_max   = max_depth;
			size_t         saved_cap   = display_list_capacity;
			display_list          = obj->sprite_display_list;
			max_depth             = obj->sprite_max_depth;
			display_list_capacity = obj->sprite_dl_capacity;

			// Phase 7b: sprite CLIP_EVENT_LOAD no longer drains per-sprite
			// here — it's queued at AQ_KIND_SCRIPT alongside sprite
			// DoAction, and the whole NORMAL-priority FIFO drains at the
			// recompiler-emitted pre-tagShowFrame SHOW_FRAME drain. The
			// SWF-tag-order inline queueing of sprite DoAction (7b) plus
			// LOAD-before-eager-init queueing (7a) gives the expected
			// per-sprite LOAD→frame_0→child_LOAD→child_frame_0 interleave
			// naturally via FIFO.

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
				int saved_invalid2 = g_settarget_invalid;
				int saved_none2 = g_settarget_none;
				g_settarget_explicit_root = 0;
				g_settarget_invalid = 0;
				g_settarget_none = 0;
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
				g_settarget_invalid = saved_invalid2;
				g_settarget_none = saved_none2;
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

			g_sprite_init_depth--;
			if (g_sprite_init_depth == 0) {
				// Returning to root: use backup (may have been updated by inline catch-up)
				display_list          = g_root_dl_backup;
				max_depth             = g_root_dl_max_backup;
				display_list_capacity = g_root_dl_cap_backup;
			} else {
				display_list          = saved_dl;
				max_depth             = saved_max;
				display_list_capacity = saved_cap;
			}

			// Invoke registered class constructor if this sprite has an exported symbol with a registered class
			// Skip if already invoked during eager init in tagPlaceObject2 (constructor_invoked flag)
			{
				extern const char* ng_lookupExportName(size_t char_id);
				extern void actionInvokeRegisteredClassConstructor(SWFAppContext* app_context, const char* export_name, MovieClip* mc);
				const char* _rc_export = ng_lookupExportName(obj->char_id);
				if (!obj->constructor_invoked && _rc_export != NULL && child_mc != NULL)
					actionInvokeRegisteredClassConstructor(app_context, _rc_export, child_mc);
				// Queue AS-level onLoad for timeline-placed RegisterClass sprites.
				// onLoad (prototype method) fires after constructor + process_sprite_needs_init
				// completes, dispatched from tagShowFrame via actionFlushPendingOnLoads.
				if (_rc_export != NULL && child_mc != NULL)
					actionQueueMCOnLoad(child_mc);
			}

			// Mark as freshly initialized (=1); upgraded to 2 after first tagShowFrame
			// so per-tick clip event ENTER_FRAME and AS2 onEnterFrame fire on
			// subsequent ticks only (Ruffle model: init tick fires LOAD, not EnterFrame).
			obj->sprite_initialized = 1;
		}
		else if (ch->type == CHAR_TYPE_BUTTON && ch->button_state_funcs != NULL)
		{
			// sprite_needs_init==2 means tagPlaceObject2 already ran state_funcs[0]
			// eagerly. Just do the recursion here so child sprites get Phase-2
			// scripts. sprite_needs_init==1 is the legacy path where state_funcs
			// hasn't run yet (e.g. after RemoveObject/replace patterns).
			int already_eager = (obj->sprite_needs_init == 2);

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

			if (!already_eager)
			{
				// Run up-state (button_state_funcs[0]) to place button's children.
				// Phase 7b: briefly set g_current_context to button_mc so that
				// tagPlaceObject2's MC pre-create (and any CLIP_LOAD queueing
				// for button children) uses button_mc as the parent. Without
				// this, button children (e.g. instance1) get parented to the
				// button's own parent (root), breaking _parent chain
				// (movieclip_in_removed_button canary).
				MovieClip* saved_ctx_btn = g_current_context;
				if (button_mc) actionSetCurrentContext(button_mc);
				ch->button_state_funcs[0](app_context);
				actionSetCurrentContext(saved_ctx_btn);

				// Sync back to obj BEFORE recursive init so that child scripts
				// accessing parent_mc->display_obj see up-to-date sprite_max_depth.
				obj->sprite_display_list  = display_list;
				obj->sprite_max_depth     = max_depth;
				obj->sprite_dl_capacity   = display_list_capacity;
			}

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

// Public wrapper for process_sprite_needs_init (called from tag_stubs.c for
// attachMovie'd sprite child initialization).
#ifdef NO_GRAPHICS
void process_sprite_needs_init_public(SWFAppContext* app_context, MovieClip* parent_mc)
{
	process_sprite_needs_init(app_context, parent_mc);
}

// Public setter for g_script_only_mode (called from tag_stubs.c).
void ng_set_script_only_mode(int mode)
{
	g_script_only_mode = mode;
}
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

	for (size_t i = max_depth + 1; i > 0; --i)
	{
		DisplayObject* obj = &display_list[i - 1];
		if (obj->char_id == 0) continue;
		Character* ch = &dictionary[obj->char_id];

		// Recurse into button display lists to advance their sprite children
		if (ch->type == CHAR_TYPE_BUTTON)
		{
			if (obj->sprite_display_list != NULL && obj->sprite_max_depth > 0)
			{
				DisplayObject* saved_dl = display_list;
				size_t saved_max = max_depth;
				size_t saved_cap = display_list_capacity;
				display_list = obj->sprite_display_list;
				max_depth = obj->sprite_max_depth;
				display_list_capacity = obj->sprite_dl_capacity;
				advance_sprite_frames(app_context);
				obj->sprite_display_list = display_list;
				obj->sprite_max_depth = max_depth;
				obj->sprite_dl_capacity = display_list_capacity;
				display_list = saved_dl;
				max_depth = saved_max;
				display_list_capacity = saved_cap;
			}
			continue;
		}

		if (ch->type != CHAR_TYPE_SPRITE) continue;

		// Allocate persistent display list on first encounter
		int just_allocated = 0;
		if (obj->sprite_display_list == NULL)
		{
			obj->sprite_dl_capacity = INITIAL_DISPLAYLIST_CAPACITY;
			obj->sprite_display_list = HCALLOC(obj->sprite_dl_capacity, sizeof(DisplayObject));
			obj->sprite_max_depth = 0;
			obj->sprite_current_frame = 0;
			just_allocated = 1;
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
#if !defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)
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
#if !defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)
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

		// Skip 1-frame sprites — they don't advance.
		// But on first encounter (just_allocated), still fall through to execute
		// frame 0 so the child display list is populated for rendering.
		if (ch->sprite_frame_count <= 1 && !just_allocated) continue;

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
#if !defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)
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

	for (size_t i = max_depth + 1; i > 0; --i)
	{
		DisplayObject* obj = &display_list[i - 1];
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
#if !defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)
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

#if !defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)
// ---------------------------------------------------------------------------
// Dynamic transform slot allocator for composed transforms.
// When multiple sprite instances share the same child transform_id, we must
// allocate unique GPU buffer slots so they don't overwrite each other.
// ---------------------------------------------------------------------------
static u32 g_next_dynamic_xform_slot;   // next available slot in xform_buffer
static u32 g_xform_slot_capacity;       // total slots available

// Save/restore stack for transform_id overrides during compose+render
#define MAX_XFORM_OVERRIDES 4096
typedef struct { DisplayObject* obj; u32 original_id; } XformOverride;
static XformOverride g_xform_overrides[MAX_XFORM_OVERRIDES];
static int g_xform_override_count;

static void xform_overrides_reset(void)
{
	g_xform_override_count = 0;
}

static void xform_overrides_push(DisplayObject* obj, u32 original_id)
{
	if (g_xform_override_count < MAX_XFORM_OVERRIDES)
	{
		g_xform_overrides[g_xform_override_count].obj = obj;
		g_xform_overrides[g_xform_override_count].original_id = original_id;
		g_xform_override_count++;
	}
}

static void xform_overrides_restore(void)
{
	for (int i = g_xform_override_count - 1; i >= 0; --i)
		g_xform_overrides[i].obj->transform_id = g_xform_overrides[i].original_id;
	g_xform_override_count = 0;
}

// ---------------------------------------------------------------------------
// Dynamic cxform slot allocator for runtime Color.setRGB/setTransform changes.
// Same pattern as the transform slot allocator above.
// ---------------------------------------------------------------------------
static u32 g_next_dynamic_cxform_slot;   // next available slot in cxform_buffer
static u32 g_cxform_slot_capacity;       // total slots available

// Save/restore stack for cxform_id overrides during render
#define MAX_CXFORM_OVERRIDES 256
typedef struct { DisplayObject* obj; u32 original_id; } CxformOverride;
static CxformOverride g_cxform_overrides[MAX_CXFORM_OVERRIDES];
static int g_cxform_override_count;

static void cxform_overrides_reset(void)
{
	g_cxform_override_count = 0;
}

static void cxform_overrides_push(DisplayObject* obj, u32 original_id)
{
	if (g_cxform_override_count < MAX_CXFORM_OVERRIDES)
	{
		g_cxform_overrides[g_cxform_override_count].obj = obj;
		g_cxform_overrides[g_cxform_override_count].original_id = original_id;
		g_cxform_override_count++;
	}
}

static void cxform_overrides_restore(void)
{
	for (int i = g_cxform_override_count - 1; i >= 0; --i)
		g_cxform_overrides[i].obj->cxform_id = g_cxform_overrides[i].original_id;
	g_cxform_override_count = 0;
}

// ---------------------------------------------------------------------------
// Helper: Build a 4x4 transform matrix from MovieClip's AS-set properties.
// Overlays AS-modified fields (as_set_flags bits) onto the existing base
// transform from transform_data.
// ---------------------------------------------------------------------------
static void apply_as_transform(float slot[16], const MovieClip* mc, u8 flags)
{
	// Overlay scale/rotation (bits 4|8|16 = xscale|yscale|rotation)
	if (flags & (4|8|16))
	{
		float sx = mc->xscale / 100.0f;
		float sy = mc->yscale / 100.0f;
		float rad = mc->rotation * 3.14159265358979323846f / 180.0f;
		float c = cosf(rad), s = sinf(rad);
		slot[0]  = sx * c;    // a
		slot[1]  = sx * s;    // b
		slot[4]  = -(sy * s); // c
		slot[5]  = sy * c;    // d
	}
	// Overlay translation (bit 0 = _x, bit 1 = _y)
	if (flags & 1) slot[12] = rintf(mc->x * 20.0f);  // pixels to twips
	if (flags & 2) slot[13] = rintf(mc->y * 20.0f);
}

// ---------------------------------------------------------------------------
// Helper: Build a 20-float cxform entry from DisplayObject cx_* fields.
// GPU format: 4x4 diagonal matrix (mult) + 4 add values.
// ---------------------------------------------------------------------------
static void build_cxform_from_obj(float out[20], const DisplayObject* obj)
{
	memset(out, 0, 20 * sizeof(float));
	// Diagonal multipliers (percentage to 0-1)
	out[0]  = (float)(obj->cx_ra / 100.0);
	out[5]  = (float)(obj->cx_ga / 100.0);
	out[10] = (float)(obj->cx_ba / 100.0);
	out[15] = (float)(obj->cx_aa / 100.0);
	// Additive offsets (0-255 to 0-1)
	out[16] = (float)(obj->cx_rb / 255.0);
	out[17] = (float)(obj->cx_gb / 255.0);
	out[18] = (float)(obj->cx_bb / 255.0);
	out[19] = (float)(obj->cx_ab / 255.0);
}

// ---------------------------------------------------------------------------
// Helper 2: Recursive transform composition for sprite/button children
// ---------------------------------------------------------------------------
// Composes each child's local transform with the parent's already-composed
// global transform, writes the result to a dynamically allocated GPU buffer
// slot, and updates the child's transform_id to point to the new slot.
// Original transform_ids are saved via xform_overrides for restoration after
// rendering.
static void compose_children(SWFAppContext* app_context, DisplayObject* dl,
	size_t dl_max_depth, const float parent_composed[16],
	int parent_cx_override, u32 parent_cxform_id)
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

		// Allocate a dynamic transform slot to avoid overwriting shared slots
		u32 new_slot = g_next_dynamic_xform_slot;
		if (new_slot < g_xform_slot_capacity) {
			g_next_dynamic_xform_slot++;
			xform_overrides_push(obj, obj->transform_id);
			obj->transform_id = new_slot;
			renderer_write_transform(context, new_slot, composed);
		} else {
			// Fallback: overwrite in-place (may cause visual artifacts)
			renderer_write_transform(context, obj->transform_id, composed);
		}

		// Propagate parent's cxform to children.
		// When a parent sprite/button has a cxform (from timeline or runtime),
		// children should inherit it.  For now, replace the child's cxform_id
		// with the parent's (no composition — works when child has identity cxform).
		// TODO: proper cxform composition (parent * child) for non-identity children.
		if (parent_cx_override && obj->cxform_id != parent_cxform_id) {
			cxform_overrides_push(obj, obj->cxform_id);
			obj->cxform_id = parent_cxform_id;
		}

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
						composed, parent_cx_override, parent_cxform_id);
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

				// Save override counts so we can restore button-local overrides
				// before freeing the temporary display list (they hold pointers into it).
				int saved_xform_count = g_xform_override_count;
				int saved_cxform_count = g_cxform_override_count;

				compose_children(app_context, display_list, max_depth, composed,
					parent_cx_override, parent_cxform_id);

				// Restore overrides that compose_children added for the temp display list
				for (int k = g_xform_override_count - 1; k >= saved_xform_count; --k)
					g_xform_overrides[k].obj->transform_id = g_xform_overrides[k].original_id;
				g_xform_override_count = saved_xform_count;
				for (int k = g_cxform_override_count - 1; k >= saved_cxform_count; --k)
					g_cxform_overrides[k].obj->cxform_id = g_cxform_overrides[k].original_id;
				g_cxform_override_count = saved_cxform_count;

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
#ifdef HEADLESS_GRAPHICS
	// Video display objects have type=0 (CHAR_TYPE_SHAPE) in dictionary because
	// tagDefineVideoStream doesn't set a type. Check for video BEFORE the switch.
	if (ng_isVideoChar(obj->char_id)) {
		uint32_t* argb = NULL;
		int vw = 0, vh = 0;
		if (actionGetVideoFramePixels(&argb, &vw, &vh)) {
			renderer_draw_bitmap_quad(context, argb, (u32)vw, (u32)vh,
				0.0f, 0.0f, obj->transform_id, obj->cxform_id);
			free(argb);
		}
		return;
	}
#endif
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
				size_t glyph_index = 4*app_context->text_data[ch->text_start + j];
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
			if (obj->sprite_display_list != NULL)
				render_display_list(app_context, obj->sprite_display_list, obj->sprite_max_depth);
			break;
	}
}

static void render_display_list(SWFAppContext* app_context, DisplayObject* dl, size_t dl_max_depth)
{
	for (size_t i = 1; i <= dl_max_depth; ++i)
	{
		DisplayObject* obj = &dl[i];
		if (obj->char_id == 0) continue;

#ifdef HEADLESS_GRAPHICS
		// Video display objects have type=0 (CHAR_TYPE_SHAPE) in dictionary.
		// Check for video BEFORE the switch to avoid rendering as empty shape.
		if (ng_isVideoChar(obj->char_id)) {
			uint32_t* argb = NULL;
			int vw = 0, vh = 0;
			if (actionGetVideoFramePixels(&argb, &vw, &vh)) {
				renderer_draw_bitmap_quad(context, argb, (u32)vw, (u32)vh,
					0.0f, 0.0f, obj->transform_id, obj->cxform_id);
				free(argb);
			}
			continue;
		}
#endif

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
					size_t glyph_index = 4*app_context->text_data[ch->text_start + j];
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
#if !defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)
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

		// On state change, re-populate the button's persistent display list
		// with the new state's children (shapes, sprites, etc.)
		if (old_state != new_state)
		{
			// Allocate display list if needed
			if (obj->sprite_display_list == NULL)
			{
				obj->sprite_dl_capacity = INITIAL_DISPLAYLIST_CAPACITY;
				obj->sprite_display_list = HCALLOC(obj->sprite_dl_capacity, sizeof(DisplayObject));
				obj->sprite_max_depth = 0;
			}

			// Clear existing children
			for (size_t j = 1; j <= obj->sprite_max_depth; j++)
			{
				if (obj->sprite_display_list[j].sprite_display_list != NULL)
				{
					FREE(obj->sprite_display_list[j].sprite_display_list);
					obj->sprite_display_list[j].sprite_display_list = NULL;
				}
				obj->sprite_display_list[j].char_id = 0;
			}
			obj->sprite_max_depth = 0;

			// Run new state function to populate the display list
			u8 effective_state = (new_state == 3) ? 0 : new_state; // outDown shows "up"
			if (effective_state < 3 && ch->button_state_funcs[effective_state] != NULL)
			{
				DisplayObject* saved_dl = display_list;
				size_t saved_max = max_depth;
				size_t saved_cap = display_list_capacity;
				display_list = obj->sprite_display_list;
				max_depth = obj->sprite_max_depth;
				display_list_capacity = obj->sprite_dl_capacity;

				g_button_state_change_depth++;
				ch->button_state_funcs[effective_state](app_context);
				g_button_state_change_depth--;

				obj->sprite_display_list = display_list;
				obj->sprite_max_depth = max_depth;
				obj->sprite_dl_capacity = display_list_capacity;
				display_list = saved_dl;
				max_depth = saved_max;
				display_list_capacity = saved_cap;
			}
		}

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

int ng_update_button_states(SWFAppContext* app_context)
{
	if (app_context->shape_data == NULL) return 0;

	// Identity transform for root-level buttons
	static const float identity[16] = {
		1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1
	};

	int found_hover = 0;
	ng_update_button_states_in_dl(app_context,
		display_list, max_depth,
		identity, &root_movieclip,
		&found_hover);
	return found_hover;
}

// Recursively upgrade sprite_initialized from 1 (this tick) to 2 (ready for per-tick dispatch).
void upgrade_sprite_initialized(DisplayObject* dl, size_t dl_max)
{
	for (size_t i = 0; i <= dl_max; ++i)
	{
		if (dl[i].char_id == 0) continue;
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
	for (size_t i = 0; i <= dl_max; ++i)
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

		// Set correct MC context for the clip action. Skip if the MC or any
		// ancestor is Marked (queued for removal by tag-stream tagRemoveObject2)
		// so ENTER_FRAME doesn't fire for clips being removed in this frame —
		// see DEFERRED_CLIP_UNLOAD_PLAN, avm1/clip_events.
		MovieClip* saved_ctx = g_current_context;
		MovieClip* event_mc = NULL;
		if (obj->instance_name != NULL) {
			event_mc = actionFindOrCreateMovieClip(app_context, obj->instance_name, parent_mc);
			if (event_mc) {
				int _ef_skip = 0;
				for (MovieClip* p = event_mc; p != NULL; p = p->parent) {
					if (p->avm1_removed || p->pending_removal) { _ef_skip = 1; break; }
				}
				if (_ef_skip) continue;
				actionSetCurrentContext(event_mc);
			}
		} else {
			// Anonymous obj: skip if parent_mc is Marked (covers the case where
			// the parent was queued for removal but the anonymous child wasn't
			// directly named).
			for (MovieClip* p = parent_mc; p != NULL; p = p->parent) {
				if (p->avm1_removed || p->pending_removal) { goto _ef_skip_obj; }
			}
		}
		for (size_t a = 0; a < obj->clip_action_count; a++)
		{
			if (obj->clip_actions[a].event_flags & CLIP_EVENT_ENTER_FRAME) {
				obj->clip_actions[a].action(app_context);
			}
		}
		actionSetCurrentContext(saved_ctx);
		continue;
	_ef_skip_obj:;
	}
}

// Recursively set enterframe_eligible=1 for all display entries with sprite_initialized >= 2.
// Walks into sprite and button child display lists. This ensures button children get the flag
// (advance_sprite_frames only iterates root-level sprites, missing button children).
// When a parent is removed (char_id=0), the walk skips it → children don't get the flag.
void set_enterframe_eligible_recursive(DisplayObject* dl, size_t dl_max)
{
	for (size_t i = 0; i <= dl_max; i++)
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

#ifdef NO_GRAPHICS
	// Mark (but don't clear display_list) any MCs queued for finalize, so
	// ENTER_FRAME skips MCs being removed by tag-stream tagRemoveObject2 in
	// this frame. The clear (which frees sprite_display_list and would dangle
	// other MCs' display_obj pointers) is deferred to actionDrainOnloadAndScript
	// after queued onLoad handlers drain. Matches Flash's behavior:
	// avm1/clip_events expects no onEnterFrame after RemoveObject2.
	extern void run_pending_finalize_mark_only(SWFAppContext* app_context);
	run_pending_finalize_mark_only(app_context);
#endif

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

#if !defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)
// Callback for actionIterateTextFields: render text field background/border rectangles.
static void textfield_render_cb(const TextFieldRenderInfo* info, void* user_data)
{
	(void)user_data;

	// Convert pixel coordinates to twips.
	float x = info->x * 20.0f;
	float y = info->y * 20.0f;
	float w = info->w * 20.0f;
	float h = info->h * 20.0f;

	if (info->has_background) {
		float r = ((info->background_color >> 16) & 0xFF) / 255.0f;
		float g = ((info->background_color >> 8) & 0xFF) / 255.0f;
		float b = (info->background_color & 0xFF) / 255.0f;
		renderer_draw_rect(context, x, y, w, h, r, g, b, 1.0f, 0, 0);
	}

	if (info->has_border) {
		float r = ((info->border_color >> 16) & 0xFF) / 255.0f;
		float g = ((info->border_color >> 8) & 0xFF) / 255.0f;
		float b = (info->border_color & 0xFF) / 255.0f;
		float t = 20.0f;  // 1 pixel border thickness in twips
		renderer_draw_rect(context, x, y, w, t, r, g, b, 1.0f, 0, 0);         // top
		renderer_draw_rect(context, x, y + h - t, w, t, r, g, b, 1.0f, 0, 0); // bottom
		renderer_draw_rect(context, x, y + t, t, h - 2*t, r, g, b, 1.0f, 0, 0); // left
		renderer_draw_rect(context, x + w - t, y + t, t, h - 2*t, r, g, b, 1.0f, 0, 0); // right
	}
}

// Callback for actionIterateTextFieldGlyphs: render text field glyph shapes.
// Reads glyph vertices from shape_data, applies CPU-side transform, renders via draw_tris.
static void textfield_glyph_render_cb(const TextFieldGlyphInfo* info, void* user_data)
{
	(void)user_data;
	extern u32 shape_data[][4];
	extern u32 glyph_data[][1];

	int font_idx = ng_find_font_with_metrics(info->font_id);
	if (font_idx < 0) return;

	s16 ascent = 0;
	int em_square = 1024;
	if (!ng_font_get_metrics(font_idx, &ascent, NULL, &em_square)) return;
	if (em_square == 0) return;

	size_t glyph_base = ng_font_get_glyph_base(font_idx);
	float scale = (float)info->font_height / (float)em_square;

	float r = ((info->text_color >> 16) & 0xFF) / 255.0f;
	float g = ((info->text_color >> 8) & 0xFF) / 255.0f;
	float b = (info->text_color & 0xFF) / 255.0f;

	// 2px gutter on each side (Flash text field internal padding)
	float gutter_twips = 40.0f;
	float x_pos = info->x * 20.0f + gutter_twips;
	float y_pos = info->y * 20.0f + (float)ascent * scale + gutter_twips;

	// Max 512 triangle vertices per draw_tris call (batch by glyph)
	static float xy_buf[1024];

	const char* text = info->text_utf8;
	size_t text_len = info->text_len;
	size_t pos = 0;

	while (pos < text_len) {
		// Decode one UTF-8 character
		unsigned char c0 = (unsigned char)text[pos];
		u16 cp;
		if (c0 >= 0xC0 && c0 < 0xE0 && pos + 1 < text_len) {
			cp = ((c0 & 0x1F) << 6) | ((unsigned char)text[pos + 1] & 0x3F);
			pos += 2;
		} else if (c0 >= 0xE0 && c0 < 0xF0 && pos + 2 < text_len) {
			cp = ((c0 & 0x0F) << 12) | (((unsigned char)text[pos + 1] & 0x3F) << 6) |
			     ((unsigned char)text[pos + 2] & 0x3F);
			pos += 3;
		} else {
			cp = c0;
			pos += 1;
		}

		// Newline: advance y, reset x
		if (cp == '\n' || cp == '\r') {
			x_pos = info->x * 20.0f + gutter_twips;
			y_pos += (float)info->font_height;
			continue;
		}

		int glyph_idx = ng_font_find_glyph(font_idx, cp);
		if (glyph_idx < 0) continue; // missing glyph — skip

		// Global glyph index
		size_t global_idx = glyph_base + (size_t)glyph_idx;
		size_t g_offset = (size_t)glyph_data[4 * global_idx][0];
		size_t g_size = (size_t)glyph_data[4 * global_idx + 1][0];

		if (g_size > 0 && g_size <= 512) {
			// Transform glyph vertices: scale from EM space + translate to position
			for (size_t v = 0; v < g_size; v++) {
				union { u32 u; float f; } vx, vy;
				vx.u = shape_data[g_offset + v][0];
				vy.u = shape_data[g_offset + v][1];
				xy_buf[2 * v]     = vx.f * scale + x_pos;
				xy_buf[2 * v + 1] = vy.f * scale + y_pos;
			}
			renderer_draw_tris(context, xy_buf, (u32)g_size, r, g, b, 1.0f, 0, 0);
		}

		// Advance x by glyph advance width
		s16 adv = ng_font_glyph_advance_by_idx(font_idx, glyph_idx);
		if (adv >= 0) {
			x_pos += (float)adv * scale;
		}
	}
}

// Helper: render a single drawing path (fill + stroke), handling gradients
static void render_drawing_path(const DrawingRenderInfo* info)
{
	if (info->fill_count > 0) {
		if (info->has_gradient && info->gradient_ramp && info->gradient_matrix) {
			renderer_draw_gradient_tris(context, info->fill_verts, info->fill_count,
				info->gradient_type, info->spread_mode, info->interpolation, info->focal_ratio,
				info->gradient_ramp, info->gradient_matrix,
				info->transform_id, info->cxform_id);
		} else {
			renderer_draw_tris(context, info->fill_verts, info->fill_count,
				info->fill_r, info->fill_g, info->fill_b, info->fill_a,
				info->transform_id, info->cxform_id);
		}
	}
	if (info->line_count > 0) {
		if (info->has_line_gradient && info->line_gradient_ramp && info->line_gradient_matrix) {
			renderer_draw_gradient_tris(context, info->line_verts, info->line_count,
				info->line_gradient_type, info->line_spread_mode, info->line_interpolation, info->line_focal_ratio,
				info->line_gradient_ramp, info->line_gradient_matrix,
				info->transform_id, info->cxform_id);
		} else {
			renderer_draw_tris(context, info->line_verts, info->line_count,
				info->line_r, info->line_g, info->line_b, info->line_a,
				info->transform_id, info->cxform_id);
		}
	}
}

// Callback for actionIterateDrawings: render Drawing API fills and strokes (unmasked).
static void drawing_render_cb(const DrawingRenderInfo* info, void* user_data)
{
	(void)user_data;
	render_drawing_path(info);
}

// Helper: render all paths in a DrawingMCInfo
static void render_drawing_mc_paths(const DrawingMCInfo* mc_info)
{
	for (int i = 0; i < mc_info->path_count; i++) {
		render_drawing_path(&mc_info->paths[i]);
	}
}

// Callback for actionIterateMaskedDrawings: stencil-masked rendering.
static void masked_drawing_render_cb(const DrawingMCInfo* masked, const DrawingMCInfo* mask, void* user_data)
{
	(void)user_data;

	// 1. Write mask shape into stencil buffer
	renderer_begin_clip_mask(context);
	render_drawing_mc_paths(mask);
	renderer_end_clip_mask(context);

	// 2. Render masked MC content with stencil test
	render_drawing_mc_paths(masked);

	// 3. End stencil clip
	renderer_end_clip(context);
}

// Callback for actionIterateAttachedBitmaps: render BitmapData attached to dynamic MCs.
static void attached_bitmap_render_cb(const AttachedBitmapInfo* info, void* user_data)
{
	(void)user_data;
	renderer_draw_bitmap_quad(context, info->pixels, info->width, info->height,
		info->x_twips, info->y_twips, 0, 0);
}
#endif

// Re-render current display list state (for headless per-tick image capture).
// Only does the rendering pass — no frame script processing, no sprite init, etc.
#ifdef HEADLESS_GRAPHICS
void tagRerenderFrame(SWFAppContext* app_context)
{
	if (context == NULL || !context->renderer_ok) return;

	// Compute focus rect BEFORE compose_children modifies transform_ids.
	// ng_getDisplayEntryBounds reads from CPU-side transform_data which only
	// has original (non-composed) slots; composed dynamic slots exist only in GPU.
	FocusRectInfo fri;
	int draw_focus_rect = actionGetFocusRectInfo(&fri);

	// --- Re-compose transforms (same as tagShowFrame) ---
	{
		u32 orig_xform_count = (u32)(app_context->transform_data_size / (16 * sizeof(float)));
		g_next_dynamic_xform_slot = orig_xform_count;
		g_xform_slot_capacity = context->xform_slot_count;
		xform_overrides_reset();

		u32 orig_cxform_count = app_context->cxform_data_size > 0
			? (u32)(app_context->cxform_data_size / (20 * sizeof(float))) : 1;
		g_next_dynamic_cxform_slot = orig_cxform_count;
		g_cxform_slot_capacity = context->cxform_slot_count;
		cxform_overrides_reset();
	}

	// Runtime transform updates (AS _x/_y/_xscale/_rotation changes)
	{
		extern MovieClip* actionFindMovieClipByName(const char* instance_name);
		for (size_t i = 1; i <= max_depth; ++i)
		{
			DisplayObject* obj = &display_list[i];
			if (obj->char_id == 0 || obj->instance_name == NULL) continue;
			MovieClip* mc = actionFindMovieClipByName(obj->instance_name);
			if (mc == NULL || mc->as_set_flags == 0) continue;
			float* slot = transform_data[obj->transform_id];
			apply_as_transform(slot, mc, mc->as_set_flags);
			renderer_write_transform(context, obj->transform_id, slot);
		}
		__asm__ volatile("" ::: "memory");
		for (size_t i = 1; i <= max_depth; ++i)
		{
			DisplayObject* obj = &display_list[i];
			if (obj->char_id == 0 || !obj->cx_overridden) continue;
			float cx[20];
			build_cxform_from_obj(cx, obj);
			u32 new_slot = g_next_dynamic_cxform_slot;
			if (new_slot < g_cxform_slot_capacity) {
				g_next_dynamic_cxform_slot++;
				cxform_overrides_push(obj, obj->cxform_id);
				obj->cxform_id = new_slot;
				renderer_write_cxform(context, new_slot, cx);
			}
		}
		__asm__ volatile("" ::: "memory");
	}

	// Compose children transforms (sprites, buttons, text)
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
					sprite_xform,
					obj->cx_overridden || obj->has_cxform, obj->cxform_id);
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
			int saved_xform_count = g_xform_override_count;
			int saved_cxform_count = g_cxform_override_count;
			compose_children(app_context, display_list, max_depth, btn_xform,
				obj->cx_overridden || obj->has_cxform, obj->cxform_id);
			for (int k = g_xform_override_count - 1; k >= saved_xform_count; --k)
				g_xform_overrides[k].obj->transform_id = g_xform_overrides[k].original_id;
			g_xform_override_count = saved_xform_count;
			for (int k = g_cxform_override_count - 1; k >= saved_cxform_count; --k)
				g_cxform_overrides[k].obj->cxform_id = g_cxform_overrides[k].original_id;
			g_cxform_override_count = saved_cxform_count;
			free(display_list);
			display_list = saved_display_list;
			max_depth = saved_max_depth;
			display_list_capacity = saved_capacity;
		}
		else if (ch->type == CHAR_TYPE_TEXT)
		{
			renderer_compose_text_transforms(context,
				app_context->transform_data,
				obj->transform_id, ch->transform_start, ch->text_size);
		}
	}

	// --- Render pass ---
	renderer_open_pass(context);

#ifdef HEADLESS_RENDER_ENABLED
	extern int headless_has_pending_captures(void);
	if (headless_has_pending_captures())
		renderer_request_capture(context);
#endif

	// Render display list
	u32 active_clip_depth = 0;
	for (size_t i = 1; i <= max_depth; ++i)
	{
		DisplayObject* obj = &display_list[i];
		if (obj->char_id == 0) continue;
		if (active_clip_depth > 0 && i > active_clip_depth) {
			renderer_end_clip(context);
			active_clip_depth = 0;
		}
		if (obj->clip_depth > 0) {
			Character* ch = &dictionary[obj->char_id];
			if (ch->type == CHAR_TYPE_SHAPE) {
				renderer_begin_clip_mask(context);
				renderer_draw_shape(context, ch->shape_offset, ch->size, obj->transform_id, obj->cxform_id);
				renderer_end_clip_mask(context);
				active_clip_depth = obj->clip_depth;
			} else if (ch->type == CHAR_TYPE_SPRITE) {
				// Sprite clip mask: render sprite content + Drawing API into stencil
				renderer_begin_clip_mask(context);
				if (obj->sprite_display_list != NULL)
					render_display_list(app_context, obj->sprite_display_list, obj->sprite_max_depth);
				// Also render Drawing API shapes drawn into this sprite's MC
				if (obj->instance_name != NULL) {
					DrawingRenderInfo dinfos[64];
					int dn = actionGetMCDrawingPathsByName(obj->instance_name, dinfos, 64);
					for (int di = 0; di < dn; di++)
						render_drawing_path(&dinfos[di]);
				}
				renderer_end_clip_mask(context);
				active_clip_depth = obj->clip_depth;
			}
			continue;
		}
		if (obj->blend_mode > 1)
			renderer_set_blend_mode(context, obj->blend_mode);
		if (obj->filter_type != 0) {
			renderer_suspend_pass(context);
			renderer_begin_offscreen_pass(context);
			render_single_object(app_context, obj);
			renderer_end_offscreen_pass(context);
			int is_shadow = (obj->filter_type == 2);
			int is_glow = (obj->filter_type == 3);
			int is_bevel = (obj->filter_type == 4);
			int colorize = is_shadow || is_glow;
			renderer_run_blur(context,
				obj->filter_blur_x, obj->filter_blur_y,
				obj->filter_quality, obj->filter_strength,
				obj->filter_color_r, obj->filter_color_g,
				obj->filter_color_b, obj->filter_color_a, colorize);
			renderer_resume_pass(context);
			if (is_shadow) {
				float angle_rad = obj->filter_angle * 3.14159265f / 180.0f;
				float dist_px = obj->filter_distance;
				float ox = cosf(angle_rad) * dist_px * 2.0f / (float)app_context->width;
				float oy = sinf(angle_rad) * dist_px * 2.0f / (float)app_context->height;
				renderer_composite_filtered(context, ox, -oy, 0, 0, 0, 0);
				render_single_object(app_context, obj);
			} else if (is_glow) {
				renderer_composite_filtered(context, 0.0f, 0.0f, 0, 0, 0, 0);
				render_single_object(app_context, obj);
			} else if (is_bevel) {
				float angle_rad = obj->filter_angle * 3.14159265f / 180.0f;
				float dist_px = obj->filter_distance;
				float sox = cosf(angle_rad) * dist_px * 2.0f / (float)app_context->width;
				float soy = sinf(angle_rad) * dist_px * 2.0f / (float)app_context->height;
				renderer_composite_filtered(context, sox, -soy,
					obj->filter_color_r, obj->filter_color_g,
					obj->filter_color_b, obj->filter_color_a);
				renderer_composite_filtered(context, -sox, soy,
					obj->filter_highlight_r, obj->filter_highlight_g,
					obj->filter_highlight_b, obj->filter_highlight_a);
				render_single_object(app_context, obj);
			} else {
				renderer_composite_filtered(context, 0.0f, 0.0f, 0, 0, 0, 0);
			}
			if (obj->blend_mode > 1)
				renderer_set_blend_mode(context, obj->blend_mode);
		} else {
			render_single_object(app_context, obj);
		}
		if (obj->blend_mode > 1)
			renderer_set_blend_mode(context, 0);
	}
	if (active_clip_depth > 0)
		renderer_end_clip(context);

	// Text field backgrounds/borders and glyph rendering
	actionIterateTextFields(textfield_render_cb, NULL);
	actionIterateTextFieldGlyphs(textfield_glyph_render_cb, NULL);

	// Drawing API fills and strokes
	actionIterateDrawings(drawing_render_cb, NULL);
	actionIterateMaskedDrawings(masked_drawing_render_cb, NULL);

	// Attached bitmaps (from attachBitmap on dynamic MCs)
	actionIterateAttachedBitmaps(attached_bitmap_render_cb, NULL);

	// Focus rect (pre-computed before compose_children)
	// Drawn as 3-pixel thick border INSIDE the object's world AABB.
	if (draw_focus_rect) {
		float t = 3.0f * 20.0f;  // 3 pixels in twips
		float fx = fri.x, fy = fri.y, fw = fri.w, fh = fri.h;
		renderer_draw_rect(context, fx, fy, fw, t, 1, 1, 0, 1, 0, 0);                  // top
		renderer_draw_rect(context, fx, fy + fh - t, fw, t, 1, 1, 0, 1, 0, 0);          // bottom
		renderer_draw_rect(context, fx, fy + t, t, fh - 2*t, 1, 1, 0, 1, 0, 0);         // left
		renderer_draw_rect(context, fx + fw - t, fy + t, t, fh - 2*t, 1, 1, 0, 1, 0, 0);// right
	}

	renderer_close_pass(context);
	xform_overrides_restore();
	cxform_overrides_restore();
}
#endif

void tagShowFrame(SWFAppContext* app_context)
{
#ifdef NO_GRAPHICS
	if (g_tag_skip_mode) return;
	if (g_in_action_call) return;

	// Phase 4/5 safety drain: any CLIP_EVENT_INITIALIZE / CLIP_EVENT_CONSTRUCT
	// / registerClass-ctor entries that were queued during this frame's
	// placements but weren't drained by the outermost tagPlaceObject2
	// (e.g. goto catch-up, where the outer tagPlaceObject2 runs under
	// catch_up_mode=1 and the in-function drain block is skipped) drain here.
	// In the common case the queue is empty and these calls are no-ops — the
	// in-function drain already covered them. Drain in priority order
	// (INIT → CONSTRUCT → REGISTER_CTOR) to preserve the pre-Phase-5 ordering.
	actionDrainActionQueueByKind(app_context, AQ_KIND_CLIP_INIT);
	actionDrainActionQueueByKind(app_context, AQ_KIND_CLIP_CONSTRUCT);
	actionDrainActionQueueByKind(app_context, AQ_KIND_REGISTER_CTOR);
	// Phase 7b: sprite CLIP_EVENT_LOAD now rides on AQ_KIND_SCRIPT, drained
	// at the recompiler-emitted pre-tagShowFrame SHOW_FRAME drain alongside
	// sprite DoAction. The post-process_sprite_needs_init safety drain below
	// catches any late AQ_KIND_SCRIPT entries queued inside tagShowFrame
	// (e.g. tagReplaceObject2RatioWithClipActions).

	// --- Fire deferred onUnload handlers from removeMovieClip ---
	// These are queued mid-script and fire between frames, matching Flash behavior.
	// actionFirePendingUnloads also runs run_pending_finalize internally so the
	// destructive cleanup happens immediately after the handlers drain.
	//
	// Skip during catch_up_mode: tagShowFrame is invoked for each replayed frame
	// inside ng_executeGotoCatchUp. UNLOAD callbacks queued during the rewind
	// (e.g. tagPlaceObject2 displacing an MC with CLIP_EVENT_UNLOAD) must defer
	// to the outer actionDrainOnloadAndScript so they interleave with the
	// remaining queued root-level scripts (loop_test8 trailing mc5unloaded must
	// land after totals(), not in the middle of the post-goto check_equals
	// batch). run_pending_finalize is similarly deferred to keep instance_name
	// resolvable until the calling script completes.
	if (!catch_up_mode)
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
		// Use g_current_context as parent when available (e.g., during loadMovie
		// the loaded SWF's tagShowFrame should parent sprites to the container MC).
		MovieClip* _si_parent = (g_current_context != NULL) ? g_current_context : &root_movieclip;
		process_sprite_needs_init(app_context, _si_parent);
		catch_up_mode = saved_catch_up;

		// Phase 7b safety drain: catch any AQ_KIND_SCRIPT entries queued
		// during process_sprite_needs_init itself (e.g. via paths like
		// tagReplaceObject2RatioWithClipActions which installs new
		// clip_actions after the base PlaceObject and calls
		// queue_clip_load_events inside tagShowFrame). The common path's
		// pre-tagShowFrame drain already covered the normal queue; this
		// is a no-op unless some ShowFrame-time path queued more.
		actionDrainActionQueueByKind(app_context, AQ_KIND_SCRIPT);

		// Fire onLoad events for duplicated clips (queued by ng_duplicateMovieClip)
		ng_fire_pending_loads(app_context);

		// Fire deferred init scripts for attachMovie clips
		ng_fire_pending_attach_inits(app_context);

		// Flush pending onLoads for timeline-placed RegisterClass sprites
		// (queued by process_sprite_init_at_depth after constructor fires).
		// This also flushes any onLoads queued during the onLoad handlers
		// (e.g. children created via attachMovie inside onLoad).
		actionFlushPendingOnLoads(app_context);

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

	// Enable root onEnterFrame dispatch after first frame
	{
		extern int g_root_enterframe_eligible;
		g_root_enterframe_eligible = 1;
	}
#endif

	// --- Button hit testing + state machine + action dispatch ---
	// In NO_GRAPHICS mode, button states are updated per-tick from swf_core.c frame loop
	// (after event delivery), and per-mouse-event from input_events_deliver().
#if !defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)
	{
		int any_hover = ng_update_button_states(app_context);
#ifdef __EMSCRIPTEN__
		EM_ASM({
			document.getElementById('canvas').style.cursor = $0 ? 'pointer' : 'default';
		}, any_hover);
#endif
	}
#endif

#if !defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)
	// Compute focus rect BEFORE compose_children modifies transform_ids.
	// ng_getDisplayEntryBounds reads from CPU-side transform_data which only
	// has original (non-composed) slots; composed dynamic slots exist only in GPU.
	FocusRectInfo g_frame_fri;
	int g_frame_draw_focus_rect = actionGetFocusRectInfo(&g_frame_fri);

	// Initialize dynamic transform and cxform slot allocators.
	// Original slots are [0, orig_count). Dynamic slots start after.
	{
		u32 orig_xform_count = (u32)(app_context->transform_data_size / (16 * sizeof(float)));
		g_next_dynamic_xform_slot = orig_xform_count;
		g_xform_slot_capacity = context->xform_slot_count;
		xform_overrides_reset();

		u32 orig_cxform_count = app_context->cxform_data_size > 0
			? (u32)(app_context->cxform_data_size / (20 * sizeof(float))) : 1;
		g_next_dynamic_cxform_slot = orig_cxform_count;
		g_cxform_slot_capacity = context->cxform_slot_count;
		cxform_overrides_reset();
	}

	{
		extern MovieClip* actionFindMovieClipByName(const char* instance_name);

		// --- Runtime transform updates ---
		// When ActionScript modifies _x/_y/_xscale/_yscale/_rotation, the changes
		// are stored on the MovieClip but not written to the GPU.  Apply them now
		// so that compose_children and the render pass use the updated values.
		for (size_t i = 1; i <= max_depth; ++i)
		{
			DisplayObject* obj = &display_list[i];
			if (obj->char_id == 0 || obj->instance_name == NULL) continue;

			MovieClip* mc = actionFindMovieClipByName(obj->instance_name);
			if (mc == NULL || mc->as_set_flags == 0) continue;

			// Update CPU-side transform_data so compose_children picks it up
			float* slot = (float*)app_context->transform_data + obj->transform_id * 16;
			apply_as_transform(slot, mc, mc->as_set_flags);

			// Also update the GPU buffer for this slot
			renderer_write_transform(context, obj->transform_id, slot);
		}

		// --- Runtime cxform updates ---
		// When Color.setRGB()/setTransform() modifies display object color,
		// cx_overridden is set.  Build a new cxform and write to a dynamic GPU slot.
		// The compose_children loop below propagates the overridden cxform_id
		// to sprite/button children.
		// Memory barrier: GCC -O2 can misoptimize struct field reads across
		// function calls that modify related memory.
		__asm__ volatile("" ::: "memory");
		for (size_t i = 1; i <= max_depth; ++i)
		{
			DisplayObject* obj = &display_list[i];
			if (obj->char_id == 0) continue;
			if (!obj->cx_overridden) continue;

			// Build cxform from the runtime cx_* values and allocate a dynamic slot
			float cx[20];
			build_cxform_from_obj(cx, obj);

			u32 new_slot = g_next_dynamic_cxform_slot;
			if (new_slot < g_cxform_slot_capacity) {
				g_next_dynamic_cxform_slot++;
				cxform_overrides_push(obj, obj->cxform_id);
				obj->cxform_id = new_slot;
				renderer_write_cxform(context, new_slot, cx);
			}
		}
		__asm__ volatile("" ::: "memory");
	}

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
					sprite_xform,
					obj->cx_overridden || obj->has_cxform, obj->cxform_id);
			}
		}
		else if (ch->type == CHAR_TYPE_BUTTON)
		{
			// Initialize button display list on first encounter (graphics mode)
			if (obj->sprite_display_list == NULL && ch->button_state_funcs != NULL)
			{
				obj->sprite_dl_capacity = INITIAL_DISPLAYLIST_CAPACITY;
				obj->sprite_display_list = HCALLOC(obj->sprite_dl_capacity, sizeof(DisplayObject));
				obj->sprite_max_depth = 0;

				u8 state = obj->button_state;
				u8 effective = (state == 3) ? 0 : state;
				if (effective < 3 && ch->button_state_funcs[effective] != NULL)
				{
					DisplayObject* saved_dl = display_list;
					size_t saved_max = max_depth;
					size_t saved_cap = display_list_capacity;
					display_list = obj->sprite_display_list;
					max_depth = obj->sprite_max_depth;
					display_list_capacity = obj->sprite_dl_capacity;

					ch->button_state_funcs[effective](app_context);

					obj->sprite_display_list = display_list;
					obj->sprite_max_depth = max_depth;
					obj->sprite_dl_capacity = display_list_capacity;
					display_list = saved_dl;
					max_depth = saved_max;
					display_list_capacity = saved_cap;
				}
			}

			if (obj->sprite_display_list != NULL && obj->sprite_max_depth > 0)
			{
				const float* btn_xform = (const float*)app_context->transform_data + obj->transform_id * 16;
				compose_children(app_context,
					obj->sprite_display_list, obj->sprite_max_depth,
					btn_xform,
					obj->cx_overridden || obj->has_cxform, obj->cxform_id);
			}
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
			else if (ch->type == CHAR_TYPE_SPRITE)
			{
				// Sprite clip mask: render sprite content + Drawing API into stencil
				renderer_begin_clip_mask(context);
				if (obj->sprite_display_list != NULL)
					render_display_list(app_context, obj->sprite_display_list, obj->sprite_max_depth);
				// Also render Drawing API shapes drawn into this sprite's MC
				if (obj->instance_name != NULL) {
					DrawingRenderInfo dinfos[64];
					int dn = actionGetMCDrawingPathsByName(obj->instance_name, dinfos, 64);
					for (int di = 0; di < dn; di++)
						render_drawing_path(&dinfos[di]);
				}
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

	// --- Render text field backgrounds, borders, and glyphs ---
	// Dynamic text fields (createTextField) are tracked in child_mc_cache but not
	// on the tag display list. Render their background/border rectangles here.
	actionIterateTextFields(textfield_render_cb, NULL);
	actionIterateTextFieldGlyphs(textfield_glyph_render_cb, NULL);

	// --- Render Drawing API fills and strokes ---
	actionIterateDrawings(drawing_render_cb, NULL);
	actionIterateMaskedDrawings(masked_drawing_render_cb, NULL);

	// --- Render attached bitmaps (from attachBitmap on dynamic MCs) ---
	actionIterateAttachedBitmaps(attached_bitmap_render_cb, NULL);

	// --- Render focus rect (pre-computed before compose_children) ---
	// Drawn as 3-pixel thick border INSIDE the object's world AABB.
	if (g_frame_draw_focus_rect) {
		float t = 3.0f * 20.0f;  // 3 pixels in twips
		float fx = g_frame_fri.x, fy = g_frame_fri.y, fw = g_frame_fri.w, fh = g_frame_fri.h;
		renderer_draw_rect(context, fx, fy, fw, t, 1, 1, 0, 1, 0, 0);                  // top
		renderer_draw_rect(context, fx, fy + fh - t, fw, t, 1, 1, 0, 1, 0, 0);          // bottom
		renderer_draw_rect(context, fx, fy + t, t, fh - 2*t, 1, 1, 0, 1, 0, 0);         // left
		renderer_draw_rect(context, fx + fw - t, fy + t, t, fh - 2*t, 1, 1, 0, 1, 0, 0);// right
	}

	renderer_close_pass(context);

	// Restore original transform_ids and cxform_ids that were overridden
	xform_overrides_restore();
	cxform_overrides_restore();
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
int sprite_content_bounds_twips(DisplayObject* dl, size_t dl_max,
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

		if (ch->type == CHAR_TYPE_SHAPE || ch->type == CHAR_TYPE_MORPH_SHAPE ||
		    ch->type == CHAR_TYPE_TEXT)
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
		// Fallback: try ng_getCharBounds for any other type (edittext, etc.)
		else if (ch->type != CHAR_TYPE_SPRITE && ch->type != CHAR_TYPE_BUTTON)
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
// Recursive shape-only hit test for drop_target purposes. Excludes text fields
// (which Flash treats as transparent for drop_target hit testing) and walks
// nested sprites looking for actual shape coverage.
static int find_drop_target_shape_hit_recursive(DisplayObject* dl, size_t dl_max,
    double pa, double pb, double pc, double pd, double ptx, double pty,
    double test_x, double test_y)
{
	extern int ng_hitTestShapeChar_public(size_t char_id, u16 ratio,
	    double ma, double mb, double mc_m, double md, double mtx, double mty,
	    double test_x, double test_y);
	(void)ng_hitTestShapeChar_public;
	for (size_t i = 1; i <= dl_max; i++) {
		DisplayObject* child = &dl[i];
		if (child->char_id == 0) continue;
		Character* cch = &dictionary[child->char_id];
		// Compose parent matrix with this child's transform
		u32 ctid = child->transform_id;
		double ca = (double)transform_data[ctid][0];
		double cb = (double)transform_data[ctid][1];
		double cc = (double)transform_data[ctid][4];
		double cd = (double)transform_data[ctid][5];
		double ctx_v = (double)transform_data[ctid][12];
		double cty_v = (double)transform_data[ctid][13];
		double na = pa*ca + pc*cb, nb = pb*ca + pd*cb;
		double nc = pa*cc + pc*cd, nd = pb*cc + pd*cd;
		double nntx = pa*ctx_v + pc*cty_v + ptx;
		double nnty = pb*ctx_v + pd*cty_v + pty;
		if (cch->type == CHAR_TYPE_SHAPE || cch->type == CHAR_TYPE_MORPH_SHAPE) {
			s32 cxmin, cxmax, cymin, cymax;
			if (!ng_getCharBounds(child->char_id, &cxmin, &cxmax, &cymin, &cymax)) continue;
			// Inverse-transform to local space and test bounds
			double det = na*nd - nb*nc;
			if (det == 0.0) continue;
			double inv = 1.0 / det;
			double sx = test_x - nntx;
			double sy = test_y - nnty;
			double lx = ( nd*sx - nc*sy) * inv;
			double ly = (-nb*sx + na*sy) * inv;
			if (lx >= (double)cxmin && lx <= (double)cxmax &&
			    ly >= (double)cymin && ly <= (double)cymax)
				return 1;
		} else if (cch->type == CHAR_TYPE_SPRITE) {
			if (child->sprite_display_list != NULL && child->sprite_max_depth > 0) {
				if (find_drop_target_shape_hit_recursive(child->sprite_display_list,
				    child->sprite_max_depth, na, nb, nc, nd, nntx, nnty, test_x, test_y))
					return 1;
			}
		}
		// Skip text fields and other non-shape types (Flash treats them as
		// transparent for drop_target purposes).
	}
	return 0;
}

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

		// Skip the dragged clip itself (skip_name may be full path like "_level0.dragger")
		if (skip_name && entry->instance_name) {
			const char* skip_base = strrchr(skip_name, '.');
			skip_base = skip_base ? skip_base + 1 : skip_name;
			if (strcmp(entry->instance_name, skip_base) == 0) continue;
		}

		Character* ch = &dictionary[entry->char_id];

		float entry_stage_x = parent_stage_x + transform_data[entry->transform_id][12];
		float entry_stage_y = parent_stage_y + transform_data[entry->transform_id][13];
		float sx = transform_data[entry->transform_id][0];
		float sy = transform_data[entry->transform_id][5];

		// If this entry has an associated AS-level MC with as_set_flags
		// (e.g. Dejagnu._y = 100), apply that delta to the entry's stage
		// position so AS-modified positions take effect for drop_target
		// hit-testing.
		if (entry->instance_name != NULL) {
			extern MovieClip* actionFindMovieClipByName(const char* name);
			MovieClip* _entry_mc = actionFindMovieClipByName(entry->instance_name);
			if (_entry_mc != NULL && _entry_mc->display_obj == (void*)entry) {
				if (_entry_mc->as_set_flags & 1) {
					// Override x with AS-set value (in pixels → twips)
					entry_stage_x = parent_stage_x + (float)_entry_mc->x * 20.0f;
				}
				if (_entry_mc->as_set_flags & 2) {
					entry_stage_y = parent_stage_y + (float)_entry_mc->y * 20.0f;
				}
			}
		}

		int hit = 0;

		if (ch->type == CHAR_TYPE_SHAPE || ch->type == CHAR_TYPE_MORPH_SHAPE)
		{
			// Shape: AABB is a tight enough approximation for drop-target testing.
			s32 cxmin, cxmax, cymin, cymax;
			if (ng_getCharBounds(entry->char_id, &cxmin, &cxmax, &cymin, &cymax))
			{
				float x0 = entry_stage_x + sx * (float)cxmin;
				float x1 = entry_stage_x + sx * (float)cxmax;
				float y0 = entry_stage_y + sy * (float)cymin;
				float y1 = entry_stage_y + sy * (float)cymax;
				if (x0 > x1) { float t = x0; x0 = x1; x1 = t; }
				if (y0 > y1) { float t = y0; y0 = y1; y1 = t; }
				hit = (mouse_x >= x0 && mouse_x <= x1 && mouse_y >= y0 && mouse_y <= y1);
			}
		}
		else if (ch->type == CHAR_TYPE_SPRITE)
		{
			// Sprite: test against the sprite's content AABB (includes both
			// shape and text-field children). text_blocks_clicks expects
			// /texts (a sprite containing a text field) to be a drop target.
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
					hit = (mouse_x >= x0 && mouse_x <= x1 && mouse_y >= y0 && mouse_y <= y1);
				}
			}
		}

		if (!hit) continue;

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
	// Check static display_list first (timeline-placed clips). Flash treats
	// these as taking precedence for drop_target when both static and
	// dynamic clips overlap at the test point — e.g. text_blocks_clicks
	// expects "/texts" (static) instead of "/click_mc" (dynamic).
	if (find_drop_target_in_dl(display_list, max_depth,
	    0.0f, 0.0f, stage_x_twips, stage_y_twips,
	    skip_name, "", out_path, out_size))
		return 1;
	// Fall back to dynamic MCs (createEmptyMovieClip / duplicateMovieClip /
	// attachMovie) — they aren't in display_list, so the static walk above
	// can't find them. DragDropTest's target10/target20/etc. land here.
	extern int actionFindDynamicDropTarget(float stage_x_twips, float stage_y_twips,
	    const char* skip_name, char* out_path, size_t out_size);
	return actionFindDynamicDropTarget(stage_x_twips, stage_y_twips,
	    skip_name, out_path, out_size);
}

// ---------------------------------------------------------------------------
// CLIP_EVENT_PRESS / CLIP_EVENT_RELEASE dispatch
// ---------------------------------------------------------------------------
// Called from swf_core.c's input_events_deliver on EV_MOUSE_DOWN_LEFT / UP_LEFT.

// Recursive helper for dispatch_clip_event_press — walks into nested sprite
// display lists to find entries with CLIP_EVENT_PRESS clip actions.
static void dispatch_clip_event_press_dl(SWFAppContext* app_context,
    DisplayObject* dl, size_t dl_max_depth,
    double ma, double mb, double mc_m, double md, double mtx, double mty,
    float mouse_x, float mouse_y, MovieClip* parent_mc)
{
	extern int ng_hitTestShapeFromDL(DisplayObject* dl, size_t dl_max,
	    double ma, double mb, double mc_m, double md, double mtx, double mty,
	    double test_x, double test_y);

	for (size_t i = 1; i <= dl_max_depth; i++)
	{
		DisplayObject* obj = &dl[i];
		if (obj->char_id == 0) continue;

		// Compose parent transform with this entry's transform.
		// If this entry is the current drag target, use the virtual drag position
		// instead of the transform position (startDrag moves the clip visually
		// without updating transform_data).
		u32 tid = obj->transform_id;
		double ca = (double)transform_data[tid][0];
		double cb = (double)transform_data[tid][1];
		double cc = (double)transform_data[tid][4];
		double cd = (double)transform_data[tid][5];
		double ctx_v = (double)transform_data[tid][12];
		double cty_v = (double)transform_data[tid][13];
		if (g_drag_target_name[0] != '\0' && obj->instance_name &&
		    strcmp(obj->instance_name, g_drag_target_name) == 0)
		{
			ctx_v = (double)g_drag_virt_x;
			cty_v = (double)g_drag_virt_y;
		}
		double na = ma*ca + mc_m*cb, nb = mb*ca + md*cb;
		double nc = ma*cc + mc_m*cd, nd = mb*cc + md*cd;
		double ntx = ma*ctx_v + mc_m*cty_v + mtx;
		double nty = mb*ctx_v + md*cty_v + mty;

		// Check if this entry has any mouse-related clip actions (PRESS or RELEASE).
		// We need to mark entries with RELEASE actions as pressed too, so the
		// release handler can fire later even if there's no PRESS handler.
		int has_mouse_clip = 0;
		int has_press_action = 0;
		if (obj->clip_action_count > 0)
		{
			for (size_t a = 0; a < obj->clip_action_count; a++)
			{
				uint32_t flags = obj->clip_actions[a].event_flags;
				if (flags & (CLIP_EVENT_PRESS | CLIP_EVENT_RELEASE)) {
					has_mouse_clip = 1;
					if (flags & CLIP_EVENT_PRESS) has_press_action = 1;
				}
			}
		}

		if (has_mouse_clip)
		{
			// Hit-test: check if mouse is inside this entry's visual content
			int hit = 0;
			if (obj->sprite_display_list != NULL && obj->sprite_max_depth > 0) {
				hit = ng_hitTestShapeFromDL(obj->sprite_display_list, obj->sprite_max_depth,
					na, nb, nc, nd, ntx, nty, (double)mouse_x, (double)mouse_y);
			}
			if (hit) {
				obj->clip_mc_pressed = 1;
				if (has_press_action) {
					MovieClip* saved_ctx = g_current_context;
					if (obj->instance_name) {
						MovieClip* mc = actionFindOrCreateMovieClip(app_context, obj->instance_name, parent_mc);
						if (mc) actionSetCurrentContext(mc);
					}
					for (size_t a = 0; a < obj->clip_action_count; a++) {
						if (obj->clip_actions[a].event_flags & CLIP_EVENT_PRESS)
							obj->clip_actions[a].action(app_context);
					}
					actionSetCurrentContext(saved_ctx);
				}

				if (is_dragging && obj->instance_name && obj->instance_name[0] != '\0')
					snprintf(g_drag_target_name, sizeof(g_drag_target_name), "%s", obj->instance_name);
			}
		}

		// Recurse into sprite display lists to find nested clip actions
		if (obj->sprite_display_list != NULL && obj->sprite_max_depth > 0) {
			MovieClip* child_mc = parent_mc;
			if (obj->instance_name) {
				MovieClip* mc = actionFindOrCreateMovieClip(app_context, obj->instance_name, parent_mc);
				if (mc) child_mc = mc;
			}
			dispatch_clip_event_press_dl(app_context,
				obj->sprite_display_list, obj->sprite_max_depth,
				na, nb, nc, nd, ntx, nty,
				mouse_x, mouse_y, child_mc);
		}
	}
}

void dispatch_clip_event_press(SWFAppContext* app_context)
{
	float mx = app_context->mouse.stage_x;  // twips
	float my = app_context->mouse.stage_y;  // twips

	// Walk root display list with identity transform
	dispatch_clip_event_press_dl(app_context,
		display_list, max_depth,
		1.0, 0.0, 0.0, 1.0, 0.0, 0.0,
		mx, my, &root_movieclip);
}

// Recursive helper for dispatch_clip_event_release — walks into nested sprite
// display lists to find entries with clip_mc_pressed flag.
static void dispatch_clip_event_release_dl(SWFAppContext* app_context,
    DisplayObject* dl, size_t dl_max_depth, MovieClip* parent_mc)
{
	for (size_t i = 1; i <= dl_max_depth; i++)
	{
		DisplayObject* obj = &dl[i];
		if (obj->char_id == 0) continue;

		// Fire RELEASE on entries that were pressed
		if (obj->clip_mc_pressed && obj->clip_action_count > 0)
		{
			obj->clip_mc_pressed = 0;
			MovieClip* saved_ctx = g_current_context;
			if (obj->instance_name) {
				MovieClip* mc = actionFindOrCreateMovieClip(app_context, obj->instance_name, parent_mc);
				if (mc) actionSetCurrentContext(mc);
			}
			for (size_t a = 0; a < obj->clip_action_count; a++) {
				if (obj->clip_actions[a].event_flags & CLIP_EVENT_RELEASE)
					obj->clip_actions[a].action(app_context);
			}
			actionSetCurrentContext(saved_ctx);
		}
		else if (obj->clip_mc_pressed)
		{
			obj->clip_mc_pressed = 0;
		}

		// Recurse into sprites
		if (obj->sprite_display_list != NULL && obj->sprite_max_depth > 0) {
			MovieClip* child_mc = parent_mc;
			if (obj->instance_name) {
				MovieClip* mc = actionFindOrCreateMovieClip(app_context, obj->instance_name, parent_mc);
				if (mc) child_mc = mc;
			}
			dispatch_clip_event_release_dl(app_context,
				obj->sprite_display_list, obj->sprite_max_depth, child_mc);
		}
	}
}

void dispatch_clip_event_release(SWFAppContext* app_context)
{
	dispatch_clip_event_release_dl(app_context,
		display_list, max_depth, &root_movieclip);
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

void tagDefineText(SWFAppContext* app_context, size_t char_id, size_t text_start, size_t text_size, u32 transform_start, u32 cxform_id, s32 bounds_xmin, s32 bounds_xmax, s32 bounds_ymin, s32 bounds_ymax)
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
#ifdef NO_GRAPHICS
		ng_record_char_bounds(char_id, bounds_xmin, bounds_xmax, bounds_ymin, bounds_ymax);
#else
		(void)bounds_xmin; (void)bounds_xmax; (void)bounds_ymin; (void)bounds_ymax;
#endif
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
	// Also record char bounds so edittext participates in sprite content bounds
	ng_record_char_bounds(char_id, bounds_xmin, bounds_xmax, bounds_ymin, bounds_ymax);
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

// Helper: recursively fire registered class constructors for child sprites
// placed during eager init. Phase 5 of ACTION_QUEUE_PLAN retired the
// tagPlaceObject2 call site (constructors now queue through the ActionQueue
// at placement time); this helper is still called from ng_fire_child_constructors
// for the attachMovie AS-level path, which follows a different flow.
#ifdef NO_GRAPHICS
static void fire_eager_constructors(SWFAppContext* app_context, DisplayObject* dl, size_t dl_max, MovieClip* parent_mc)
{
	extern const char* ng_lookupExportName(size_t char_id);
	extern void actionInvokeRegisteredClassConstructor(SWFAppContext*, const char*, MovieClip*);
	extern void actionSetupRegisteredClassPrototype(SWFAppContext*, const char*, MovieClip*);

	for (size_t i = 1; i <= dl_max; i++)
	{
		DisplayObject* obj = &dl[i];
		if (obj->char_id == 0 || obj->constructor_invoked) continue;
		if (dictionary[obj->char_id].type != CHAR_TYPE_SPRITE) continue;
		if (obj->instance_name == NULL) continue;

		const char* exp = ng_lookupExportName(obj->char_id);
		MovieClip* mc = NULL;

		// Only create the MC when there's a registered class — premature creation
		// causes zombie MCs with wrong depth/parent (regressions in
		// function_base_clip_readded, movieclip_in_removed_button)
		if (exp != NULL)
		{
			mc = actionFindOrCreateMovieClip(app_context, obj->instance_name, parent_mc);
			if (mc != NULL)
			{
				mc->display_obj = (void*)obj;
				actionSetupRegisteredClassPrototype(app_context, exp, mc);
				actionInvokeRegisteredClassConstructor(app_context, exp, mc);
				obj->constructor_invoked = 1;
			}
		}

		// Recurse into children regardless of whether this sprite had a class
		if (obj->sprite_display_list != NULL && obj->sprite_max_depth > 0)
			fire_eager_constructors(app_context, obj->sprite_display_list, obj->sprite_max_depth, mc ? mc : parent_mc);
	}
}
#endif

#ifdef NO_GRAPHICS
// Phase 4 of ACTION_QUEUE_PLAN: CLIP_EVENT_INITIALIZE handlers are routed
// through the unified ActionQueue at AQ_PRIORITY_INITIALIZE / AQ_KIND_CLIP_INIT.
//
// Phase 5 of ACTION_QUEUE_PLAN: CLIP_EVENT_CONSTRUCT handlers and the
// registerClass constructor are likewise routed through the queue at
// AQ_PRIORITY_CONSTRUCT, via separate kinds (CLIP_CONSTRUCT, REGISTER_CTOR)
// and separate dispatch callbacks. Recursion for nested children happens
// at queue time (each nested tagPlaceObject2 call queues its own entries)
// rather than via a drain-time walk of sprite_display_list — which is what
// retired fire_deferred_construct and the in-tagPlaceObject2 call to
// fire_eager_constructors.
//
// All three kinds drain at the outermost tagPlaceObject2 !catch_up_mode
// site in priority order (INITIALIZE → CONSTRUCT), with per-kind drain
// calls issued in the order CLIP_INIT → CLIP_CONSTRUCT → REGISTER_CTOR to
// preserve the pre-migration ordering: every INIT runs first, then every
// CONSTRUCT clip event, and finally every register-class constructor.
// Safety drains for all three kinds run at the top of tagShowFrame in case
// the outermost placement itself occurred under catch_up_mode=1 (goto
// catch-up); in the common path the safety drain is a no-op.
typedef struct {
	MovieClip* mc;
	frame_func action;
} PendingClipInit;

static void aq_dispatch_clip_init(SWFAppContext* app_context, void* user)
{
	PendingClipInit* pci = (PendingClipInit*) user;
	if (pci == NULL) return;
	MovieClip* saved_ctx = g_current_context;
	if (pci->mc) actionSetCurrentContext(pci->mc);
	pci->action(app_context);
	actionSetCurrentContext(saved_ctx);
	free(pci);
}

static void queue_clip_init_events(SWFAppContext* app_context, size_t depth)
{
	if (display_list[depth].clip_action_count == 0) return;
	if (display_list[depth].instance_name == NULL) return;
	MovieClip* _parent_mc = g_current_context ? g_current_context : &root_movieclip;
	MovieClip* _mc = actionFindOrCreateMovieClip(
		app_context, display_list[depth].instance_name, _parent_mc);
	for (size_t a = 0; a < display_list[depth].clip_action_count; a++) {
		if (!(display_list[depth].clip_actions[a].event_flags & CLIP_EVENT_INITIALIZE))
			continue;
		PendingClipInit* pci = (PendingClipInit*) malloc(sizeof(PendingClipInit));
		if (pci == NULL) continue;
		pci->mc = _mc;
		pci->action = display_list[depth].clip_actions[a].action;
		actionQueueCallbackEx(app_context, aq_dispatch_clip_init, (void*)pci,
		                      AQ_PRIORITY_INITIALIZE, _mc, /*is_unload=*/0,
		                      AQ_KIND_CLIP_INIT);
	}
}

// Phase 5: CLIP_EVENT_CONSTRUCT bundle. clip_actions is a pointer to
// recompiler-emitted static ClipAction[] storage (stable across drain).
// char_id is captured for ng_lookupExportName at dispatch (resolves the
// registered-class prototype before CONSTRUCT handlers fire).
typedef struct {
	MovieClip* mc;
	ClipAction* clip_actions;
	size_t clip_action_count;
	size_t char_id;
} PendingClipConstruct;

static void aq_dispatch_clip_construct(SWFAppContext* app_context, void* user)
{
	PendingClipConstruct* pcc = (PendingClipConstruct*) user;
	if (pcc == NULL) return;
	MovieClip* saved_ctx = g_current_context;
	if (pcc->mc) actionSetCurrentContext(pcc->mc);
	// Set __proto__ to registered class prototype before CONSTRUCT handlers fire
	// so prototype properties are accessible in the handler (matches the
	// pre-Phase-5 sync ordering at the outermost placement site).
	{
		extern const char* ng_lookupExportName(size_t char_id);
		extern void actionSetupRegisteredClassPrototype(SWFAppContext*, const char*, MovieClip*);
		const char* _exp = ng_lookupExportName(pcc->char_id);
		if (_exp != NULL && pcc->mc != NULL)
			actionSetupRegisteredClassPrototype(app_context, _exp, pcc->mc);
	}
	for (size_t a = 0; a < pcc->clip_action_count; a++) {
		if (pcc->clip_actions[a].event_flags & CLIP_EVENT_CONSTRUCT)
			pcc->clip_actions[a].action(app_context);
	}
	actionSetCurrentContext(saved_ctx);
	free(pcc);
}

static void queue_clip_construct_events(SWFAppContext* app_context, size_t depth)
{
	if (display_list[depth].clip_action_count == 0) return;
	if (display_list[depth].instance_name == NULL) return;
	// Skip enqueueing entirely when there is no CONSTRUCT handler on this
	// entry — avoids dispatch-time work (and a spurious setupPrototype) for
	// entries that only carry non-CONSTRUCT clip events.
	int _has_construct = 0;
	for (size_t a = 0; a < display_list[depth].clip_action_count; a++) {
		if (display_list[depth].clip_actions[a].event_flags & CLIP_EVENT_CONSTRUCT) {
			_has_construct = 1;
			break;
		}
	}
	if (!_has_construct) return;

	MovieClip* _parent_mc = g_current_context ? g_current_context : &root_movieclip;
	MovieClip* _mc = actionFindOrCreateMovieClip(
		app_context, display_list[depth].instance_name, _parent_mc);

	PendingClipConstruct* pcc = (PendingClipConstruct*) malloc(sizeof(PendingClipConstruct));
	if (pcc == NULL) return;
	pcc->mc = _mc;
	pcc->clip_actions = display_list[depth].clip_actions;
	pcc->clip_action_count = display_list[depth].clip_action_count;
	pcc->char_id = display_list[depth].char_id;
	actionQueueCallbackEx(app_context, aq_dispatch_clip_construct, (void*)pcc,
	                      AQ_PRIORITY_CONSTRUCT, _mc, /*is_unload=*/0,
	                      AQ_KIND_CLIP_CONSTRUCT);
}

// Phase 5: registerClass constructor. Queued at placement time; dispatched
// at the outermost !catch_up_mode drain. The dispatcher mirrors the
// pre-Phase-5 sync block at tag.c:3524–3555: assigns mc->display_obj, sets
// __proto__ via actionSetupRegisteredClassPrototype, invokes the ctor,
// and marks the DisplayObject constructor_invoked=1. display_obj is
// captured at queue time (same window during which the pre-Phase-5 sync
// block dereferenced &display_list[depth]) so realloc-staleness risk is
// no worse than before.
typedef struct {
	MovieClip* mc;
	DisplayObject* display_obj;
	char* export_name;
} PendingRegisterCtor;

static void aq_dispatch_register_ctor(SWFAppContext* app_context, void* user)
{
	PendingRegisterCtor* prc = (PendingRegisterCtor*) user;
	if (prc == NULL) return;
	if (prc->mc != NULL && prc->export_name != NULL && prc->display_obj != NULL
	    && !prc->display_obj->constructor_invoked) {
		// Skip if another path (e.g. ng_fire_child_constructors for attachMovie
		// children, which still walks display lists synchronously) already
		// invoked the ctor for this DisplayObject after we queued. The check
		// mirrors fire_eager_constructors' own `if (obj->constructor_invoked)
		// continue` guard and keeps register_and_init_order idempotent.
		extern void actionInvokeRegisteredClassConstructor(SWFAppContext*, const char*, MovieClip*);
		extern void actionSetupRegisteredClassPrototype(SWFAppContext*, const char*, MovieClip*);
		prc->mc->display_obj = (void*)prc->display_obj;
		actionSetupRegisteredClassPrototype(app_context, prc->export_name, prc->mc);
		actionInvokeRegisteredClassConstructor(app_context, prc->export_name, prc->mc);
		prc->display_obj->constructor_invoked = 1;
	}
	free(prc->export_name);
	free(prc);
}

static void queue_register_ctor(SWFAppContext* app_context, size_t depth, size_t char_id)
{
	extern const char* ng_lookupExportName(size_t char_id);
	// Gate on the same conditions the pre-Phase-5 sync CTOR block used.
	if (!display_list[depth].sprite_needs_init) return;
	if (display_list[depth].constructor_invoked) return;
	if (display_list[depth].instance_name == NULL) return;
	if (dictionary[char_id].type != CHAR_TYPE_SPRITE) return;

	const char* exp = ng_lookupExportName(char_id);
	// Only create the MC when there's a registered class — premature creation
	// causes zombie MCs with wrong depth/parent (same rationale as the old
	// fire_eager_constructors path).
	if (exp == NULL) return;

	MovieClip* _parent_mc = g_current_context ? g_current_context : &root_movieclip;
	MovieClip* _mc = actionFindOrCreateMovieClip(
		app_context, display_list[depth].instance_name, _parent_mc);
	if (_mc == NULL) return;

	PendingRegisterCtor* prc = (PendingRegisterCtor*) malloc(sizeof(PendingRegisterCtor));
	if (prc == NULL) return;
	prc->mc = _mc;
	prc->display_obj = &display_list[depth];
	prc->export_name = strdup(exp);
	if (prc->export_name == NULL) {
		free(prc);
		return;
	}
	actionQueueCallbackEx(app_context, aq_dispatch_register_ctor, (void*)prc,
	                      AQ_PRIORITY_CONSTRUCT, _mc, /*is_unload=*/0,
	                      AQ_KIND_REGISTER_CTOR);
}

// Phase 7a: CLIP_EVENT_LOAD clip-action enqueue. Queued at placement time in
// tagPlaceObject2 / tagPlaceObject2Ratio (before eager init so this sprite's
// LOAD is FIFO-first among its own NORMAL-priority entries — the ordering
// 7b relies on when sprite DoAction joins the queue). Drained per-sprite
// inside process_sprite_init_at_depth at the same observable point where
// the pre-migration synchronous fire lived. The payload stores a pointer
// to the DisplayObject (stable within the parent's sprite_display_list)
// rather than a MovieClip pointer, because at queue time (during nested
// eager init) g_current_context may not yet point at the parent sprite's
// MC — a clip_actions-less parent's MC isn't pre-created by the queue
// helpers, so exec_sprite_frame's findMovieClipByName returns NULL and
// the MC lookup would misparent the child to root. Deferring the MC
// lookup to drain time avoids the issue: process_sprite_init_at_depth
// already has the correctly-parented child_mc in hand when it drains.
// (PendingClipLoad struct forward-declared near top of file.)

// Dispatcher for sprite CLIP_EVENT_LOAD entries. Now drains together with
// AQ_KIND_SCRIPT entries at the SHOW_FRAME pre-drain. Looks up the MC via
// the display object's instance_name with the queue-time-captured
// parent_mc as fallback parent — root would be wrong for nested clips
// (function_base_clip_readded canary).
static void aq_dispatch_clip_load(SWFAppContext* app_context, void* user)
{
	PendingClipLoad* pcl = (PendingClipLoad*) user;
	if (pcl == NULL) return;
	MovieClip* saved_ctx = g_current_context;
	if (pcl->obj != NULL && pcl->obj->instance_name != NULL) {
		MovieClip* parent = pcl->parent_mc ? pcl->parent_mc : &root_movieclip;
		MovieClip* mc = actionFindOrCreateMovieClip(
			app_context, pcl->obj->instance_name, parent);
		if (mc) actionSetCurrentContext(mc);
	}
	pcl->action(app_context);
	actionSetCurrentContext(saved_ctx);
	free(pcl);
}

static void queue_clip_load_events(SWFAppContext* app_context, size_t depth)
{
	(void)app_context;
	if (display_list[depth].clip_action_count == 0) return;
	if (display_list[depth].instance_name == NULL) return;
	// Bail early when there's no LOAD handler on this entry — avoids a
	// spurious queue entry for sprites that only carry
	// INITIALIZE/CONSTRUCT/UNLOAD/etc.
	int _has_load = 0;
	for (size_t a = 0; a < display_list[depth].clip_action_count; a++) {
		if (display_list[depth].clip_actions[a].event_flags & CLIP_EVENT_LOAD) {
			_has_load = 1;
			break;
		}
	}
	if (!_has_load) return;

	for (size_t a = 0; a < display_list[depth].clip_action_count; a++) {
		if (!(display_list[depth].clip_actions[a].event_flags & CLIP_EVENT_LOAD))
			continue;
		PendingClipLoad* pcl = (PendingClipLoad*) malloc(sizeof(PendingClipLoad));
		if (pcl == NULL) continue;
		pcl->obj    = &display_list[depth];
		pcl->action = display_list[depth].clip_actions[a].action;
		// Capture parent MC at queue time. During Phase 1 eager init,
		// g_current_context is the parent sprite's MC (set by exec_sprite_frame's
		// actionSetCurrentContext). At root level, it's &root_movieclip. The
		// dispatcher uses this as the parent for actionFindOrCreateMovieClip
		// to resolve obj->instance_name — root as fallback gives wrong _parent
		// for nested clips (function_base_clip_readded).
		pcl->parent_mc = g_current_context;
		// Phase 7b: push at AQ_KIND_SCRIPT (not CLIP_LOAD) so sprite LOAD
		// interleaves with sprite DoAction in the SHOW_FRAME FIFO drain.
		// aq_dispatch_clip_load sets g_current_context from
		// pcl->obj->instance_name before firing the handler — so the
		// drain's per-entry dispatcher still does the correct MC
		// context-switch even though the kind is SCRIPT.
		// clip=NULL: is_unload gating disabled — the sprite is either
		// initialized (drain fires) or pre-removed with its clip_actions
		// overwritten (no entry for that obj).
		actionQueueCallbackEx(app_context, aq_dispatch_clip_load, (void*)pcl,
		                      AQ_PRIORITY_NORMAL, /*clip=*/NULL, /*is_unload=*/0,
		                      AQ_KIND_SCRIPT);
	}
}
#endif

// Forward decl: defined later in this file. Used by the backward-rewind
// clear-and-replace path in tagPlaceObject2 / tagPlaceObject2Ratio so a
// displaced sprite's CLIP_EVENT_UNLOAD callbacks (and recursive child
// unloads) get queued before pending-removal Mark — matches the
// tagRemoveObject2 path. See loop_test8 trailing mc5unloaded trace.
#ifdef NO_GRAPHICS
static void fire_recursive_child_unloads(SWFAppContext* app_context,
	DisplayObject* dl, size_t dl_max, MovieClip* parent_mc);
#endif

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
		ng_cache_transform(&display_list[depth], transform_id);
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
			// Ruffle survives_rewind: for MovieClip, only ratio_equals is
			// required (id differences are OK — a swapDepths-moved MC at a
			// depth re-placed by a timeline tag keeps its identity). For other
			// types (shapes, buttons, etc.) id must also match. See
			// ruffle/core/src/display_object/movie_clip.rs survives_rewind.
			// tagPlaceObject2 (non-Ratio variant) implies ratio == 0.
			int existing_is_mc = (display_list[depth].sprite_display_list != NULL);
			int survives = (display_list[depth].ratio == 0)
			               && (existing_is_mc
			                   || display_list[depth].char_id == char_id);
			if (survives)
			{
				// Survives rewind: treat as modify, preserve sprite state.
				// This preserves instance_name (Ruffle: apply_place_object does
				// not update name on existing children). Discard any pending
				// instance name (set by a preceding tagSetInstanceName) BEFORE
				// ng_on_place_object2 — otherwise it would consume the pending
				// name and overwrite the preserved instance_name.
				g_pending_instance_name = NULL;
				display_list[depth].transform_id = transform_id;
				ng_cache_transform(&display_list[depth], transform_id);
				display_list[depth].cxform_id = cxform_id;
				display_list[depth].has_cxform = (cxform_id != 0) ? 1 : 0;
				if (clip_depth != 0) display_list[depth].clip_depth = clip_depth;
				display_list[depth].placed_at_frame = current_frame;
				display_list[depth].place_gen = g_place_gen;
				init_cx_fields(&display_list[depth]);
				// Pass existing char_id so ng_on_place_object2 doesn't try to
				// treat this as a different-character placement.
				ng_on_place_object2(app_context, depth, display_list[depth].char_id);
				display_list[depth].sprite_needs_init = 0;
				return;
			}
			// Different character (or ratio) at this depth during backward catch-up:
			// - If existing entry is truly stale (placed_at_frame > target, i.e. it was
			//   preserved by ng_display_clear_after from pre-rewind state), new placement
			//   from [0, target] must win: clear and full replace.
			// - Else (placed in [0, target] by an earlier catch-up replay), skip this
			//   placement — the later frame in [0, target] will re-establish it.
			if (catch_up_mode && display_list[depth].placed_at_frame > current_frame)
			{
				if (display_list[depth].placed_at_frame > catch_up_target)
				{
					// Mark the existing MC pending-removal so it persists in the
					// removed-depth zone for one frame — Flash semantics: after
					// backward goto replaces an MC at a depth, an old MC with
					// an UNLOAD handler (clip-event UNLOAD or AS-level
					// onUnload) is still referenceable by name (typeof returns
					// 'movieclip') until next frame's finalize. Mirrors
					// Ruffle's `remove_child` → `should_delay_removal` path
					// called from run_goto's survives_rewind=false branch.
					// Gating on has_unload (mirrors ng_on_remove_object) avoids
					// preserving MCs that should disappear immediately — see
					// gnash misc-ming loop_test5 where movieClip3 has only
					// CONSTRUCT (no UNLOAD) and must be undefined after rewind.
					if (existing_is_mc && display_list[depth].instance_name != NULL)
					{
						extern int has_child_unload_handler(DisplayObject* dl, size_t dl_max);
						extern int actionMCHasOnUnloadProperty(const char* name, int swf_depth);
						extern void actionMarkMCPendingRemoval(SWFAppContext*, const char*, int);
						int _swr_has_unload = 0;
						for (size_t _ca = 0; _ca < display_list[depth].clip_action_count; _ca++) {
							if (display_list[depth].clip_actions[_ca].event_flags & 0x4) {
								_swr_has_unload = 1; break;
							}
						}
						if (!_swr_has_unload) {
							for (size_t _ca = 0; _ca < display_list[depth].accumulated_clip_action_count; _ca++) {
								if (display_list[depth].accumulated_clip_actions[_ca].event_flags & 0x4) {
									_swr_has_unload = 1; break;
								}
							}
						}
						if (!_swr_has_unload) {
							_swr_has_unload = actionMCHasOnUnloadProperty(
								display_list[depth].instance_name, (int)depth);
						}
						if (!_swr_has_unload && display_list[depth].sprite_display_list != NULL &&
						    display_list[depth].sprite_max_depth > 0) {
							_swr_has_unload = has_child_unload_handler(
								display_list[depth].sprite_display_list,
								display_list[depth].sprite_max_depth);
						}
						if (_swr_has_unload) {
							// Queue clip-action UNLOAD callbacks (and recursive
							// child unloads) BEFORE marking pending so they
							// drain via actionFirePendingUnloads — matches the
							// tagRemoveObject2 path. Without this, a backward
							// goto that displaces an MC with a CLIP_EVENT_UNLOAD
							// handler (loop_test8 mc5) drops the trailing
							// unload trace entirely.
							MovieClip* _swr_mc_for_q = actionFindOrCreateMovieClip(
								app_context, display_list[depth].instance_name, &root_movieclip);
							for (size_t _ca = 0; _ca < display_list[depth].accumulated_clip_action_count; _ca++) {
								if (display_list[depth].accumulated_clip_actions[_ca].event_flags & 0x4)
									actionQueueClipActionUnload(display_list[depth].accumulated_clip_actions[_ca].action, _swr_mc_for_q);
							}
							if (display_list[depth].sprite_display_list != NULL &&
							    display_list[depth].sprite_max_depth > 0) {
								fire_recursive_child_unloads(app_context,
									display_list[depth].sprite_display_list,
									display_list[depth].sprite_max_depth,
									_swr_mc_for_q ? _swr_mc_for_q : &root_movieclip);
							}
							for (size_t _ca = 0; _ca < display_list[depth].clip_action_count; _ca++) {
								if (display_list[depth].clip_actions[_ca].event_flags & 0x4)
									actionQueueClipActionUnload(display_list[depth].clip_actions[_ca].action, _swr_mc_for_q);
							}
							actionMarkMCPendingRemoval(app_context,
							                           display_list[depth].instance_name,
							                           (int)depth);
						}
					}
					if (display_list[depth].sprite_display_list != NULL)
					{
						FREE(display_list[depth].sprite_display_list);
						display_list[depth].sprite_display_list = NULL;
					}
					display_list[depth].char_id = 0;
					// Fall through to full placement
				}
				else
				{
					return;
				}
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
					ng_cache_transform(&display_list[depth], transform_id);
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
#ifdef NO_GRAPHICS
		ng_cache_transform(&display_list[depth], transform_id);
#endif
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
#ifdef NO_GRAPHICS
		ng_cache_transform(&display_list[depth], transform_id);
#endif
		display_list[depth].cxform_id = cxform_id;
		display_list[depth].has_cxform = (cxform_id != 0) ? 1 : 0;
		if (clip_depth != 0) display_list[depth].clip_depth = clip_depth;
		init_cx_fields(&display_list[depth]);
		if (depth > max_depth) max_depth = depth;
		return;
	}

	display_list[depth].char_id = char_id;
	display_list[depth].transform_id = transform_id;
#ifdef NO_GRAPHICS
	ng_cache_transform(&display_list[depth], transform_id);
#endif
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
	// Look up child movie transform data by character's movie_id
	display_list[depth].child_transform_data = NULL;
	if (g_char_movie_id != NULL && char_id < g_char_movie_id_capacity && g_char_movie_id[char_id] != 0)
		display_list[depth].child_transform_data = g_movie_transform_data[g_char_movie_id[char_id]];
	// Free old instance name if we own it
	if (display_list[depth].instance_name_owned && display_list[depth].instance_name != NULL)
	{
		free(display_list[depth].instance_name);
	}
	// Consume pending instance name from tagSetInstanceName (called before PlaceObject)
	if (g_pending_instance_name != NULL) {
		display_list[depth].instance_name = (char*)g_pending_instance_name;
		display_list[depth].instance_name_owned = 0;
		g_pending_instance_name = NULL;
	} else {
		display_list[depth].instance_name = NULL;
		display_list[depth].instance_name_owned = 0;
	}
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

	// Queue CLIP_EVENT_INITIALIZE / CLIP_EVENT_CONSTRUCT handlers and the
	// registerClass constructor onto the unified ActionQueue. Nested
	// placements (catch_up_mode=1 during eager init) queue but do not drain;
	// the outermost placement drains all three kinds in order (INIT then
	// CONSTRUCT then REGISTER_CTOR) before returning, preserving the
	// pre-Phase-5 ordering where every INIT fires, then every CONSTRUCT
	// clip event, then every register-class constructor.
	queue_clip_init_events(app_context, depth);
	queue_clip_construct_events(app_context, depth);
	queue_register_ctor(app_context, depth, char_id);
	// Phase 7a: queue CLIP_EVENT_LOAD clip-actions at NORMAL priority BEFORE
	// eager init. Drained per-sprite inside process_sprite_init_at_depth
	// (replacing the pre-migration synchronous fire at the same observable
	// point). The "before eager init" placement is what 7b will rely on:
	// this sprite's LOAD is FIFO-first among its NORMAL entries, so when
	// sprite DoAction joins the queue in 7b, the per-sprite
	// LOAD → frame_0 → nested-LOAD → nested-frame_0 interleave falls out
	// of a single Normal-priority FIFO drain.
	queue_clip_load_events(app_context, depth);

	// Phase 7b: pre-create the placed sprite's MC with the caller's context
	// as parent, so exec_sprite_frame's findMovieClipByName finds it and
	// sets g_current_context to the sprite's MC during Phase 1 eager init.
	// Without this, nested PlaceObject calls inside this sprite's frame_0
	// would see g_current_context still as the parent's-parent (or root),
	// and queue_clip_load_events would capture the wrong parent_mc
	// (function_base_clip_readded canary).
	if (display_list[depth].sprite_needs_init
	    && dictionary[char_id].type == CHAR_TYPE_SPRITE
	    && display_list[depth].instance_name != NULL)
	{
		extern MovieClip root_movieclip;
		MovieClip* _parent_for_mc = g_current_context ? g_current_context : &root_movieclip;
		actionFindOrCreateMovieClip(app_context, display_list[depth].instance_name, _parent_for_mc);
	}

	// Eagerly execute sprite frame 0 immediately after placement so the sprite's
	// internal display list is populated BEFORE the parent frame's ActionScript runs.
	// This matches Flash AVM1 behavior: sprites placed via PlaceObject2 are
	// "constructed" (frame 0 executed) before the parent's DoAction scripts.
	// During eager init, nested tagPlaceObject2 calls run with catch_up_mode=1
	// and enqueue their own INIT/CONSTRUCT/CTOR entries into the shared queue.
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
				g_eager_init_depth++;
				CALL_FRAME(app_context, &saved_dl[depth], sp_ch->sprite_frame_funcs[0]);
				g_eager_init_depth--;
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
		else if (dictionary[char_id].type == CHAR_TYPE_BUTTON)
		{
			// Buttons need eager init so AS code accessing button.childName
			// (e.g. button3.instance1) sees the populated state-0 children
			// before the parent frame's DoAction runs. State funcs only emit
			// tagPlaceObject2 calls (no scripts), so this is safe under
			// catch_up_mode=1 — nested sprite placements still defer their
			// own Phase-2 scripts via the sprite eager-init path above.
			Character* btn_ch = &dictionary[char_id];
			if (btn_ch->button_state_funcs != NULL && btn_ch->button_state_funcs[0] != NULL)
			{
				display_list[depth].sprite_needs_init = 2; // mark: state_0 done, recurse later
				// Pre-create the button MC with the correct parent so child
				// placements inside state_funcs see button_mc as g_current_context
				// and their _parent chain resolves correctly.
				MovieClip* parent_for_btn = g_current_context ? g_current_context : &root_movieclip;
				MovieClip* button_mc = NULL;
				if (display_list[depth].instance_name != NULL) {
					button_mc = actionFindOrCreateMovieClip(app_context,
						display_list[depth].instance_name, parent_for_btn);
					if (button_mc) {
						button_mc->is_button_mc = 1;
						button_mc->display_obj = (void*)&display_list[depth];
					}
				}

				DisplayObject* saved_dl = display_list;
				size_t saved_max = max_depth;
				size_t saved_cap = display_list_capacity;
				display_list = saved_dl[depth].sprite_display_list;
				max_depth = saved_dl[depth].sprite_max_depth;
				display_list_capacity = saved_dl[depth].sprite_dl_capacity;

				int saved_catch_up = catch_up_mode;
				catch_up_mode = 1;
				g_eager_init_depth++;
				MovieClip* saved_ctx_btn = g_current_context;
				if (button_mc) actionSetCurrentContext(button_mc);
				btn_ch->button_state_funcs[0](app_context);
				actionSetCurrentContext(saved_ctx_btn);
				g_eager_init_depth--;
				catch_up_mode = saved_catch_up;

				saved_dl[depth].sprite_display_list = display_list;
				saved_dl[depth].sprite_max_depth = max_depth;
				saved_dl[depth].sprite_dl_capacity = display_list_capacity;
				display_list = saved_dl;
				max_depth = saved_max;
				display_list_capacity = saved_cap;
			}
		}
	}

	// Drain INIT → CONSTRUCT → REGISTER_CTOR at the outermost placement.
	// Under catch_up_mode=1 (nested eager init, or goto catch-up where the
	// outermost tagPlaceObject2 itself runs under catch_up_mode=1) we skip
	// draining here; the enclosing !catch_up_mode placement or the
	// tagShowFrame safety drain will pick up our queued entries.
	if (!catch_up_mode) {
		actionDrainActionQueueByKind(app_context, AQ_KIND_CLIP_INIT);
		actionDrainActionQueueByKind(app_context, AQ_KIND_CLIP_CONSTRUCT);
		actionDrainActionQueueByKind(app_context, AQ_KIND_REGISTER_CTOR);
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
		extern size_t catch_up_target;
		if (catch_up_backward && display_list[depth].char_id != 0)
		{
			// Ruffle survives_rewind: for MovieClip, only ratio_equals is
			// required; other types additionally need id_equals. See the
			// matching comment in tagPlaceObject2 above.
			int existing_is_mc = (display_list[depth].sprite_display_list != NULL);
			int survives = (display_list[depth].ratio == ratio)
			               && (existing_is_mc
			                   || display_list[depth].char_id == char_id);
			if (survives)
			{
				// Preserve instance_name — clear pending before ng_on_place_object2
				// (which consumes g_pending_instance_name).
				g_pending_instance_name = NULL;
				display_list[depth].transform_id = transform_id;
				ng_cache_transform(&display_list[depth], transform_id);
				display_list[depth].cxform_id = cxform_id;
				display_list[depth].has_cxform = (cxform_id != 0) ? 1 : 0;
				if (clip_depth != 0) display_list[depth].clip_depth = clip_depth;
				display_list[depth].ratio = ratio;
				display_list[depth].placed_at_frame = current_frame;
				display_list[depth].place_gen = g_place_gen;
				init_cx_fields(&display_list[depth]);
				ng_on_place_object2(app_context, depth, display_list[depth].char_id);
				display_list[depth].sprite_needs_init = 0;
				return;
			}
			if (catch_up_mode && display_list[depth].placed_at_frame > current_frame)
			{
				if (display_list[depth].placed_at_frame > catch_up_target)
				{
					// Mark the existing MC pending-removal so it persists in the
					// removed-depth zone for one frame — Flash semantics: after
					// backward goto replaces an MC at a depth (different ratio),
					// an old MC with an UNLOAD handler (clip-event UNLOAD or
					// AS-level onUnload) is still referenceable by name (typeof
					// returns 'movieclip') until next frame's finalize. Mirrors
					// Ruffle's `remove_child` → `should_delay_removal` path
					// called from run_goto's survives_rewind=false branch.
					// Gating on has_unload (mirrors ng_on_remove_object) avoids
					// preserving MCs that should disappear immediately — see
					// gnash misc-ming loop_test5 where movieClip3 has only
					// CONSTRUCT (no UNLOAD) and must be undefined after rewind.
					if (existing_is_mc && display_list[depth].instance_name != NULL)
					{
						extern int has_child_unload_handler(DisplayObject* dl, size_t dl_max);
						extern int actionMCHasOnUnloadProperty(const char* name, int swf_depth);
						extern void actionMarkMCPendingRemoval(SWFAppContext*, const char*, int);
						int _swr_has_unload = 0;
						for (size_t _ca = 0; _ca < display_list[depth].clip_action_count; _ca++) {
							if (display_list[depth].clip_actions[_ca].event_flags & 0x4) {
								_swr_has_unload = 1; break;
							}
						}
						if (!_swr_has_unload) {
							for (size_t _ca = 0; _ca < display_list[depth].accumulated_clip_action_count; _ca++) {
								if (display_list[depth].accumulated_clip_actions[_ca].event_flags & 0x4) {
									_swr_has_unload = 1; break;
								}
							}
						}
						if (!_swr_has_unload) {
							_swr_has_unload = actionMCHasOnUnloadProperty(
								display_list[depth].instance_name, (int)depth);
						}
						if (!_swr_has_unload && display_list[depth].sprite_display_list != NULL &&
						    display_list[depth].sprite_max_depth > 0) {
							_swr_has_unload = has_child_unload_handler(
								display_list[depth].sprite_display_list,
								display_list[depth].sprite_max_depth);
						}
						if (_swr_has_unload) {
							// Queue clip-action UNLOAD callbacks (+ recursive
							// child unloads) BEFORE marking pending so they
							// drain via actionFirePendingUnloads — matches the
							// tagRemoveObject2 path. See loop_test8 (mc5
							// CLIP_EVENT_UNLOAD trace after totals()).
							MovieClip* _swr_mc_for_q = actionFindOrCreateMovieClip(
								app_context, display_list[depth].instance_name, &root_movieclip);
							for (size_t _ca = 0; _ca < display_list[depth].accumulated_clip_action_count; _ca++) {
								if (display_list[depth].accumulated_clip_actions[_ca].event_flags & 0x4)
									actionQueueClipActionUnload(display_list[depth].accumulated_clip_actions[_ca].action, _swr_mc_for_q);
							}
							if (display_list[depth].sprite_display_list != NULL &&
							    display_list[depth].sprite_max_depth > 0) {
								fire_recursive_child_unloads(app_context,
									display_list[depth].sprite_display_list,
									display_list[depth].sprite_max_depth,
									_swr_mc_for_q ? _swr_mc_for_q : &root_movieclip);
							}
							for (size_t _ca = 0; _ca < display_list[depth].clip_action_count; _ca++) {
								if (display_list[depth].clip_actions[_ca].event_flags & 0x4)
									actionQueueClipActionUnload(display_list[depth].clip_actions[_ca].action, _swr_mc_for_q);
							}
							actionMarkMCPendingRemoval(app_context,
							                           display_list[depth].instance_name,
							                           (int)depth);
						}
					}
					if (display_list[depth].sprite_display_list != NULL)
					{
						FREE(display_list[depth].sprite_display_list);
						display_list[depth].sprite_display_list = NULL;
					}
					display_list[depth].char_id = 0;
					// Fall through to full placement
				}
				else
				{
					return;
				}
			}
		}
	}
#endif

	// char_id=0 means "modify existing entry" (PlaceObject2 without HasCharacter)
	if (char_id == 0 && display_list[depth].char_id != 0)
	{
		// Update only the fields that PlaceObject2 can modify
		if (transform_id != 0) {
			display_list[depth].transform_id = transform_id;
#ifdef NO_GRAPHICS
			ng_cache_transform(&display_list[depth], transform_id);
#endif
		}
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
#ifdef NO_GRAPHICS
	ng_cache_transform(&display_list[depth], transform_id);
#endif
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
	// Look up child movie transform data by character's movie_id
	display_list[depth].child_transform_data = NULL;
	if (g_char_movie_id != NULL && char_id < g_char_movie_id_capacity && g_char_movie_id[char_id] != 0)
		display_list[depth].child_transform_data = g_movie_transform_data[g_char_movie_id[char_id]];
	// Consume pending instance name from tagSetInstanceName (called before PlaceObject)
	if (g_pending_instance_name != NULL) {
		display_list[depth].instance_name = (char*)g_pending_instance_name;
		display_list[depth].instance_name_owned = 0;
		g_pending_instance_name = NULL;
	} else {
		display_list[depth].instance_name = NULL;
		display_list[depth].instance_name_owned = 0;
	}
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

	// Queue INIT/CONSTRUCT/REGISTER_CTOR on the unified ActionQueue (same
	// ordering rationale as tagPlaceObject2). Nested placements queue but
	// don't drain; the outermost placement drains.
	queue_clip_init_events(app_context, depth);
	queue_clip_construct_events(app_context, depth);
	queue_register_ctor(app_context, depth, char_id);
	// Phase 7a: queue CLIP_EVENT_LOAD clip-actions at NORMAL priority BEFORE
	// eager init. Drained per-sprite inside process_sprite_init_at_depth
	// (replacing the pre-migration synchronous fire at the same observable
	// point). The "before eager init" placement is what 7b will rely on:
	// this sprite's LOAD is FIFO-first among its NORMAL entries, so when
	// sprite DoAction joins the queue in 7b, the per-sprite
	// LOAD → frame_0 → nested-LOAD → nested-frame_0 interleave falls out
	// of a single Normal-priority FIFO drain.
	queue_clip_load_events(app_context, depth);

	// Phase 7b: pre-create sprite MC (see tagPlaceObject2 for rationale).
	if (display_list[depth].sprite_needs_init
	    && dictionary[char_id].type == CHAR_TYPE_SPRITE
	    && display_list[depth].instance_name != NULL)
	{
		extern MovieClip root_movieclip;
		MovieClip* _parent_for_mc = g_current_context ? g_current_context : &root_movieclip;
		actionFindOrCreateMovieClip(app_context, display_list[depth].instance_name, _parent_for_mc);
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
				g_eager_init_depth++;
				CALL_FRAME(app_context, &saved_dl[depth], sp_ch->sprite_frame_funcs[0]);
				g_eager_init_depth--;
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
		else if (dictionary[char_id].type == CHAR_TYPE_BUTTON)
		{
			// Buttons need eager init so AS code accessing button.childName
			// (e.g. button3.instance1) sees the populated state-0 children
			// before the parent frame's DoAction runs. State funcs only emit
			// tagPlaceObject2 calls (no scripts), so this is safe under
			// catch_up_mode=1 — nested sprite placements still defer their
			// own Phase-2 scripts via the sprite eager-init path above.
			Character* btn_ch = &dictionary[char_id];
			if (btn_ch->button_state_funcs != NULL && btn_ch->button_state_funcs[0] != NULL)
			{
				display_list[depth].sprite_needs_init = 2; // mark: state_0 done, recurse later
				// Pre-create the button MC with the correct parent so child
				// placements inside state_funcs see button_mc as g_current_context
				// and their _parent chain resolves correctly.
				MovieClip* parent_for_btn = g_current_context ? g_current_context : &root_movieclip;
				MovieClip* button_mc = NULL;
				if (display_list[depth].instance_name != NULL) {
					button_mc = actionFindOrCreateMovieClip(app_context,
						display_list[depth].instance_name, parent_for_btn);
					if (button_mc) {
						button_mc->is_button_mc = 1;
						button_mc->display_obj = (void*)&display_list[depth];
					}
				}

				DisplayObject* saved_dl = display_list;
				size_t saved_max = max_depth;
				size_t saved_cap = display_list_capacity;
				display_list = saved_dl[depth].sprite_display_list;
				max_depth = saved_dl[depth].sprite_max_depth;
				display_list_capacity = saved_dl[depth].sprite_dl_capacity;

				int saved_catch_up = catch_up_mode;
				catch_up_mode = 1;
				g_eager_init_depth++;
				MovieClip* saved_ctx_btn = g_current_context;
				if (button_mc) actionSetCurrentContext(button_mc);
				btn_ch->button_state_funcs[0](app_context);
				actionSetCurrentContext(saved_ctx_btn);
				g_eager_init_depth--;
				catch_up_mode = saved_catch_up;

				saved_dl[depth].sprite_display_list = display_list;
				saved_dl[depth].sprite_max_depth = max_depth;
				saved_dl[depth].sprite_dl_capacity = display_list_capacity;
				display_list = saved_dl;
				max_depth = saved_max;
				display_list_capacity = saved_cap;
			}
		}
	}

	// Drain INIT → CONSTRUCT → REGISTER_CTOR at the outermost placement.
	// See tagPlaceObject2 for the rationale.
	if (!catch_up_mode) {
		actionDrainActionQueueByKind(app_context, AQ_KIND_CLIP_INIT);
		actionDrainActionQueueByKind(app_context, AQ_KIND_CLIP_CONSTRUCT);
		actionDrainActionQueueByKind(app_context, AQ_KIND_REGISTER_CTOR);
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

// --- Deferred destructive cleanup for tagRemoveObject2 (has_unload only) ---
// Phase 4 of DEFERRED_CLIP_UNLOAD_PLAN. For MCs WITH unload handlers, defer:
//   - Mark (sets pending_removal=1 on the MC, shifts depth)
//   - clear_display_entry (clears display_list slot, frees sprite_display_list)
// to post-drain finalize so:
//   - same-frame DoAction-after-RemoveObject2 sees typeof(mc) == 'movieclip'
//     (loop_test7 lines 123-124 — pending_removal stays 0 until drain).
//   - typeof / _root.mc lookups via display_list iteration still find the MC
//     by name (instance_name stays populated until finalize).
// For MCs WITHOUT unload handlers, both run inline (no handler to wait for).
#ifdef NO_GRAPHICS
#define NG_PENDING_FINALIZE_CAP 256
typedef struct {
	MovieClip* mc;
	size_t depth;
	int swf_depth;
} PendingFinalizeEntry;
static PendingFinalizeEntry ng_pending_finalize_entries[NG_PENDING_FINALIZE_CAP];
static int ng_pending_finalize_count = 0;

extern void actionMarkMCPendingRemovalDirect(MovieClip* mc, int swf_depth);
static void clear_display_entry(SWFAppContext* app_context, size_t depth);

void queue_pending_finalize_mc(MovieClip* mc, int swf_depth, size_t depth)
{
	if (mc == NULL) return;
	if (ng_pending_finalize_count >= NG_PENDING_FINALIZE_CAP) return;
	for (int i = 0; i < ng_pending_finalize_count; i++) {
		if (ng_pending_finalize_entries[i].mc == mc) return;
	}
	ng_pending_finalize_entries[ng_pending_finalize_count].mc = mc;
	ng_pending_finalize_entries[ng_pending_finalize_count].swf_depth = swf_depth;
	ng_pending_finalize_entries[ng_pending_finalize_count].depth = depth;
	ng_pending_finalize_count++;
}

// Mark-only: sets pending_removal/avm1_removed on queued MCs but does NOT
// clear display_list[depth]. Used by tagFlushPendingEnterFrame so ENTER_FRAME
// skips MCs being removed in this frame, while leaving display_list intact for
// queued onLoad handlers (whose display_obj may point into a parent's
// sprite_display_list that would otherwise be freed by clear_display_entry).
// Does NOT consume the queue — entries stay so run_pending_finalize can do
// the full cleanup later.
void run_pending_finalize_mark_only(SWFAppContext* app_context)
{
	(void)app_context;
	for (int i = 0; i < ng_pending_finalize_count; i++) {
		PendingFinalizeEntry* e = &ng_pending_finalize_entries[i];
		actionMarkMCPendingRemovalDirect(e->mc, e->swf_depth);
	}
}

void run_pending_finalize(SWFAppContext* app_context)
{
	int n = ng_pending_finalize_count;
	ng_pending_finalize_count = 0;
	for (int i = 0; i < n; i++) {
		PendingFinalizeEntry* e = &ng_pending_finalize_entries[i];
		actionMarkMCPendingRemovalDirect(e->mc, e->swf_depth);
		if (e->depth <= max_depth) clear_display_entry(app_context, e->depth);
	}
}
#else
void queue_pending_finalize_mc(MovieClip* mc, int swf_depth, size_t depth) {
	(void)mc; (void)swf_depth; (void)depth;
}
void run_pending_finalize_mark_only(SWFAppContext* app_context) { (void)app_context; }
void run_pending_finalize(SWFAppContext* app_context) { (void)app_context; }
#endif

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
// Also invalidates child MCs so they don't fire onEnterFrame after parent removal.
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

		// Queue this child's CLIP_EVENT_UNLOAD (deferred — fires at next ShowFrame
		// drain in actionFirePendingUnloads, alongside AS-level onUnload handlers).
		// Resolves the MC at queue time so g_current_context can be restored at
		// dispatch time.
		if (obj->clip_action_count > 0)
		{
			MovieClip* child_mc = NULL;
			if (obj->instance_name != NULL)
				child_mc = actionFindOrCreateMovieClip(app_context, obj->instance_name, parent_mc);
			for (size_t a = 0; a < obj->clip_action_count; a++)
			{
				if (obj->clip_actions[a].event_flags & CLIP_EVENT_UNLOAD)
					actionQueueClipActionUnload(obj->clip_actions[a].action, child_mc);
			}
		}

		// Invalidate child MC so it won't fire onEnterFrame after parent removal.
		// The parent's sprite_display_list will be freed by clear_display_entry,
		// making child MC's display_obj a dangling pointer.
		if (obj->instance_name != NULL)
			actionInvalidateCachedMovieClip(app_context, obj->instance_name, (int)i);
	}
}

void tagRemoveObject(SWFAppContext* app_context, size_t depth)
{
	if (depth <= max_depth && display_list[depth].char_id != 0)
	{
#ifdef NO_GRAPHICS
		// Defer removal during catch_up_mode for entries with UNLOAD handlers
		// (same rationale as tagRemoveObject2 — see comment there).
		if (catch_up_mode)
		{
			int has_unload_cu = 0;
			for (size_t a = 0; a < display_list[depth].clip_action_count; a++) {
				if (display_list[depth].clip_actions[a].event_flags & CLIP_EVENT_UNLOAD) {
					has_unload_cu = 1; break;
				}
			}
			if (!has_unload_cu) {
				for (size_t a = 0; a < display_list[depth].accumulated_clip_action_count; a++) {
					if (display_list[depth].accumulated_clip_actions[a].event_flags & CLIP_EVENT_UNLOAD) {
						has_unload_cu = 1; break;
					}
				}
			}
			if (has_unload_cu) return;
		}
#endif
		// Queue accumulated clip actions (from prior Remove+Replace cycle) first.
		// Snapshot the action_fn pointer (recompiler-emitted static code) so
		// dropping the accumulated_clip_actions array reference is safe.
#ifdef NO_GRAPHICS
		MovieClip* _ro_parent_mc1 = NULL;
		if (display_list[depth].instance_name != NULL)
			_ro_parent_mc1 = actionFindOrCreateMovieClip(app_context, display_list[depth].instance_name, &root_movieclip);
#else
		MovieClip* _ro_parent_mc1 = NULL;
#endif
		if (display_list[depth].accumulated_clip_action_count > 0)
		{
			for (size_t a = 0; a < display_list[depth].accumulated_clip_action_count; a++)
			{
				if (display_list[depth].accumulated_clip_actions[a].event_flags & CLIP_EVENT_UNLOAD)
					actionQueueClipActionUnload(display_list[depth].accumulated_clip_actions[a].action, _ro_parent_mc1);
			}
		}
		// Queue current onUnload clip actions
		if (display_list[depth].clip_action_count > 0)
		{
			for (size_t a = 0; a < display_list[depth].clip_action_count; a++)
			{
				if (display_list[depth].clip_actions[a].event_flags & CLIP_EVENT_UNLOAD)
					actionQueueClipActionUnload(display_list[depth].clip_actions[a].action, _ro_parent_mc1);
			}
		}
#ifdef NO_GRAPHICS
		// See tagRemoveObject2 for the rationale.
		int _ro1_has_unload = 0;
		MovieClip* _ro1_mc = _ro_parent_mc1;
		if (display_list[depth].instance_name != NULL) {
			extern int ng_compute_has_unload(size_t depth);
			_ro1_has_unload = ng_compute_has_unload(depth);
			if (_ro1_has_unload) {
				actionFireOnUnload(app_context, display_list[depth].instance_name, (int)depth);
			}
		}
		if (_ro1_has_unload && _ro1_mc != NULL) {
			extern void queue_pending_finalize_mc(MovieClip*, int, size_t);
			queue_pending_finalize_mc(_ro1_mc, (int)depth, depth);
		} else {
			if (display_list[depth].instance_name != NULL) {
				actionInvalidateCachedMovieClip(app_context, display_list[depth].instance_name, (int)depth);
			}
			clear_display_entry(app_context, depth);
		}
#else
		clear_display_entry(app_context, depth);
#endif
	}
#if !defined(NO_GRAPHICS) && !defined(HEADLESS_GRAPHICS)
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

		// During catch_up_mode (ng_executeGotoTagsOnly from nextFrame/gotoAndStop),
		// defer removal of entries with UNLOAD handlers. The calling script hasn't
		// finished yet, so UNLOAD must not fire inline. The main loop's catch-up
		// will re-process the target frame with catch_up_mode=0, firing UNLOAD
		// at the correct time (after the calling script completes).
		if (catch_up_mode)
		{
			int has_unload_cu = 0;
			for (size_t a = 0; a < display_list[depth].clip_action_count; a++) {
				if (display_list[depth].clip_actions[a].event_flags & CLIP_EVENT_UNLOAD) {
					has_unload_cu = 1; break;
				}
			}
			if (!has_unload_cu) {
				for (size_t a = 0; a < display_list[depth].accumulated_clip_action_count; a++) {
					if (display_list[depth].accumulated_clip_actions[a].event_flags & CLIP_EVENT_UNLOAD) {
						has_unload_cu = 1; break;
					}
				}
			}
			if (!has_unload_cu && display_list[depth].sprite_display_list != NULL &&
			    display_list[depth].sprite_max_depth > 0) {
				extern int has_child_unload_handler(DisplayObject* dl, size_t dl_max);
				has_unload_cu = has_child_unload_handler(display_list[depth].sprite_display_list,
				                                         display_list[depth].sprite_max_depth);
			}
			if (has_unload_cu) return;
		}
#endif
#ifdef NO_GRAPHICS
		MovieClip* _remove_parent_mc = NULL;
		if (display_list[depth].instance_name != NULL)
			_remove_parent_mc = actionFindOrCreateMovieClip(app_context, display_list[depth].instance_name, &root_movieclip);
#else
		MovieClip* _remove_parent_mc = NULL;
#endif
		// Queue accumulated clip actions (from prior Remove+Replace cycle) first.
		if (display_list[depth].accumulated_clip_action_count > 0)
		{
			for (size_t a = 0; a < display_list[depth].accumulated_clip_action_count; a++)
			{
				if (display_list[depth].accumulated_clip_actions[a].event_flags & CLIP_EVENT_UNLOAD)
					actionQueueClipActionUnload(display_list[depth].accumulated_clip_actions[a].action, _remove_parent_mc);
			}
		}
		// Queue CLIP_EVENT_UNLOAD for children first (recursive, depth-first)
#ifdef NO_GRAPHICS
		if (display_list[depth].sprite_display_list != NULL && display_list[depth].sprite_max_depth > 0)
		{
			fire_recursive_child_unloads(app_context,
				display_list[depth].sprite_display_list, display_list[depth].sprite_max_depth,
				_remove_parent_mc ? _remove_parent_mc : &root_movieclip);
		}
		// Queue AS-level onUnload on dynamic children (createEmptyMovieClip /
		// duplicateMovieClip) that live in child_mc_cache, not the sprite display
		// list. Queue BEFORE the parent's own UNLOAD clip actions fire, so children
		// created during that handler don't pick up onUnload firing (Flash
		// observation: dynamic child created inside parent's UNLOAD handler does
		// not get its onUnload triggered — see gnash new_child_in_unload_test
		// case1).
		if (_remove_parent_mc != NULL)
			actionQueueDynamicChildUnloads(_remove_parent_mc);
#endif
		// Queue current onUnload clip actions
		if (display_list[depth].clip_action_count > 0)
		{
			for (size_t a = 0; a < display_list[depth].clip_action_count; a++)
			{
				if (display_list[depth].clip_actions[a].event_flags & CLIP_EVENT_UNLOAD)
					actionQueueClipActionUnload(display_list[depth].clip_actions[a].action, _remove_parent_mc);
			}
		}
#ifdef NO_GRAPHICS
		// Compute has_unload to decide finalization path:
		//  - has_unload=1: queue AS-level handler (lookup at queue time);
		//    defer Mark to post-drain finalize so the MC stays !pending_removal
		//    for same-frame DoAction lookups (loop_test7 lines 123-124, typeof
		//    returns 'movieclip' after RemoveObject2 in same-frame DoAction).
		//  - has_unload=0: no handler to defer — Invalidate inline so the MC is
		//    immediately gone (matches Flash for handler-less removals).
		// clear_display_entry runs inline in both cases to avoid dangling
		// sprite_display_list pointers in queued onLoad handlers from other MCs.
		int _ro2_has_unload = 0;
		MovieClip* _ro2_mc = NULL;
		if (display_list[depth].instance_name != NULL) {
			extern int ng_compute_has_unload(size_t depth);
			_ro2_has_unload = ng_compute_has_unload(depth);
			_ro2_mc = _remove_parent_mc;
			if (_ro2_has_unload) {
				actionFireOnUnload(app_context, display_list[depth].instance_name, (int)depth);
			}
		}
		if (_ro2_has_unload && _ro2_mc != NULL) {
			// Defer Mark + clear_display_entry to post-drain finalize.
			extern void queue_pending_finalize_mc(MovieClip*, int, size_t);
			queue_pending_finalize_mc(_ro2_mc, (int)depth, depth);
		} else {
			// No handler — Invalidate + clear inline.
			if (display_list[depth].instance_name != NULL) {
				actionInvalidateCachedMovieClip(app_context, display_list[depth].instance_name, (int)depth);
			}
			clear_display_entry(app_context, depth);
		}
#else
		clear_display_entry(app_context, depth);
#endif
	}
#ifdef NO_GRAPHICS
	else
	{
		// Display list slot is empty. A duplicateMovieClip clone swapped
		// into this depth from the dynamic range may live only in
		// child_mc_cache — its display_list entry was never populated
		// because `target_swf_depth >= INITIAL_DISPLAYLIST_CAPACITY` takes
		// the skip-DL path in `ng_cloneSprite`. After `mc1.swapDepths(dup)`
		// followed by a RemoveObject2 targeting mc1's original SWF depth,
		// dup lives at `mc->depth == depth - 16384` with no DL entry and
		// must still be invalidated. Matches Ruffle behaviour in
		// from_gnash/misc-ming.all/static_vs_dynamic2.
		extern void actionInvalidateMCAtASDepth(SWFAppContext*, int);
		actionInvalidateMCAtASDepth(app_context, (int)depth - 16384);
	}
#endif
#if !defined(NO_GRAPHICS) && !defined(HEADLESS_GRAPHICS)
	(void)app_context;
#endif
}

void tagDefineSpriteEx(SWFAppContext* app_context, size_t char_id, frame_func* funcs, size_t frame_count, size_t byte_size)
{
	(void)app_context;
	ENSURE_SIZE(dictionary, char_id, dictionary_capacity, sizeof(Character));

	dictionary[char_id].type = CHAR_TYPE_SPRITE;
	dictionary[char_id].sprite_frame_funcs = funcs;
	dictionary[char_id].sprite_frame_count = frame_count;
	dictionary[char_id].sprite_byte_size = byte_size;

	// Track which movie defined this character (for child movie transform data lookup)
	extern u8 g_current_movie_id;
	if (g_current_movie_id != 0) {
		if (char_id >= g_char_movie_id_capacity) {
			size_t new_cap = char_id + 64;
			u8* new_arr = (u8*)calloc(new_cap, 1);
			if (g_char_movie_id) {
				memcpy(new_arr, g_char_movie_id, g_char_movie_id_capacity);
				free(g_char_movie_id);
			}
			g_char_movie_id = new_arr;
			g_char_movie_id_capacity = new_cap;
		}
		g_char_movie_id[char_id] = g_current_movie_id;
	}
}

// DoInitAction once-per-character guard (for DoInitAction inside DefineSprite)
#define MAX_INIT_ACTION_CHARS 512
static u8 g_init_action_done[MAX_INIT_ACTION_CHARS];

void tagDoInitActionGuarded(SWFAppContext* app_context, size_t char_id, frame_func action)
{
	if (char_id < MAX_INIT_ACTION_CHARS && g_init_action_done[char_id])
		return;
	if (char_id < MAX_INIT_ACTION_CHARS)
		g_init_action_done[char_id] = 1;
	action(app_context);
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

// Set the button_state on the display object for a button MC.
// Used by Tab focus to set virtual hover state (1=Over) so that
// ng_update_button_states can detect the transition when mouse moves.
void ng_setButtonDisplayState(void* mc_ptr, u8 state)
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
	obj->button_state = state;
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
    u8 type, double blur_x, double blur_y, u8 quality, u8 flags,
    double r, double g, double b, double a, double strength,
    double angle, double distance)
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
    double r, double g, double b, double a)
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

// Extended filter data side table (for ColorMatrix, Convolution, Gradient filters)
#define MAX_EXT_FILTERS 32
static ExtFilterData g_ext_filters[MAX_EXT_FILTERS];
static int g_ext_filter_count = 0;

// Parallel depth array for the ext filter side table
static size_t g_ext_filter_depths[MAX_EXT_FILTERS];

static ExtFilterData* getOrCreateExtFilter(size_t depth)
{
	for (int i = 0; i < g_ext_filter_count; i++) {
		if (g_ext_filter_depths[i] == depth) return &g_ext_filters[i];
	}
	if (g_ext_filter_count >= MAX_EXT_FILTERS) return NULL;
	int idx = g_ext_filter_count++;
	memset(&g_ext_filters[idx], 0, sizeof(ExtFilterData));
	g_ext_filter_depths[idx] = depth;
	return &g_ext_filters[idx];
}

void tagSetFilterColorMatrix(SWFAppContext* app_context, size_t depth, const float* matrix20)
{
	(void)app_context;
	if (depth > max_depth) return;
	ExtFilterData* ef = getOrCreateExtFilter(depth);
	if (!ef) return;
	ef->type = 6; // colormatrix
	memcpy(ef->cm_matrix, matrix20, 20 * sizeof(float));
}

void tagSetFilterConvolution(SWFAppContext* app_context, size_t depth,
    u8 matrixX, u8 matrixY, const float* matrix, float divisor, float bias,
    u8 preserve_alpha, u8 clamp, u8 def_r, u8 def_g, u8 def_b, u8 def_a)
{
	(void)app_context;
	if (depth > max_depth) return;
	ExtFilterData* ef = getOrCreateExtFilter(depth);
	if (!ef) return;
	ef->type = 5; // convolution
	ef->conv_mx = matrixX;
	ef->conv_my = matrixY;
	int n = matrixX * matrixY;
	if (n > 25) n = 25;
	memcpy(ef->conv_matrix, matrix, n * sizeof(float));
	ef->conv_divisor = divisor;
	ef->conv_bias = bias;
	ef->conv_preserve_alpha = preserve_alpha;
	ef->conv_clamp = clamp;
	ef->conv_color_r = def_r;
	ef->conv_color_g = def_g;
	ef->conv_color_b = def_b;
	ef->conv_color_a = def_a;
}

void tagSetFilterGradient(SWFAppContext* app_context, size_t depth,
    u8 type, u8 count, const u32* colors, const float* alphas, const u8* ratios,
    float blur_x, float blur_y, float angle, float distance, float strength,
    u8 quality, u8 flags)
{
	(void)app_context;
	if (depth > max_depth) return;
	ExtFilterData* ef = getOrCreateExtFilter(depth);
	if (!ef) return;
	ef->type = type; // 7=gradientglow, 8=gradientbevel
	if (count > 16) count = 16;
	ef->grad_count = count;
	memcpy(ef->grad_colors, colors, count * sizeof(u32));
	memcpy(ef->grad_alphas, alphas, count * sizeof(float));
	memcpy(ef->grad_ratios, ratios, count);
	ef->blur_x = blur_x;
	ef->blur_y = blur_y;
	ef->angle = angle;
	ef->distance = distance;
	ef->strength = strength;
	ef->quality = quality;
	ef->flags = flags;
}

const ExtFilterData* ng_getExtFilterData(size_t entry_idx)
{
	size_t depth = entry_idx & 0xFFFFF;
	for (int i = 0; i < g_ext_filter_count; i++) {
		if (g_ext_filter_depths[i] == depth) return &g_ext_filters[i];
	}
	return NULL;
}

// Multi-filter list storage
#define MAX_FILTER_LISTS 32
static FilterListData g_filter_lists[MAX_FILTER_LISTS];
static int g_filter_list_count = 0;
static int g_current_filter_list_idx = -1; // index of list being built

static FilterListData* getOrCreateFilterList(size_t depth)
{
	for (int i = 0; i < g_filter_list_count; i++) {
		if (g_filter_lists[i].depth == depth) return &g_filter_lists[i];
	}
	if (g_filter_list_count >= MAX_FILTER_LISTS) return NULL;
	int idx = g_filter_list_count++;
	memset(&g_filter_lists[idx], 0, sizeof(FilterListData));
	g_filter_lists[idx].depth = depth;
	return &g_filter_lists[idx];
}

void tagBeginFilterList(SWFAppContext* app_context, size_t depth, u8 count)
{
	(void)app_context; (void)count;
	FilterListData* fl = getOrCreateFilterList(depth);
	if (!fl) return;
	fl->count = 0; // reset
	// Find index for subsequent tagAdd* calls
	for (int i = 0; i < g_filter_list_count; i++) {
		if (g_filter_lists[i].depth == depth) { g_current_filter_list_idx = i; return; }
	}
}

static FilterListEntry* filterListAppend(size_t depth)
{
	if (g_current_filter_list_idx < 0) return NULL;
	FilterListData* fl = &g_filter_lists[g_current_filter_list_idx];
	if (fl->depth != depth || fl->count >= MAX_FILTER_LIST_SIZE) return NULL;
	FilterListEntry* e = &fl->entries[fl->count];
	memset(e, 0, sizeof(FilterListEntry));
	fl->count++;
	return e;
}

void tagAddSimpleFilter(SWFAppContext* app_context, size_t depth,
    u8 type, double blur_x, double blur_y, u8 quality, u8 flags,
    double r, double g, double b, double a, double strength,
    double angle, double distance)
{
	(void)app_context;
	FilterListEntry* e = filterListAppend(depth);
	if (!e) return;
	e->type = type;
	e->blur_x = blur_x; e->blur_y = blur_y;
	e->quality = quality; e->flags = flags;
	e->color_r = r; e->color_g = g; e->color_b = b; e->color_a = a;
	e->strength = strength; e->angle = angle; e->distance = distance;
}

void tagAddSimpleFilterHighlight(SWFAppContext* app_context, size_t depth,
    double hr, double hg, double hb, double ha)
{
	(void)app_context;
	if (g_current_filter_list_idx < 0) return;
	FilterListData* fl = &g_filter_lists[g_current_filter_list_idx];
	if (fl->depth != depth || fl->count == 0) return;
	FilterListEntry* e = &fl->entries[fl->count - 1]; // last added
	e->highlight_r = hr; e->highlight_g = hg; e->highlight_b = hb; e->highlight_a = ha;
}

void tagAddColorMatrixFilter(SWFAppContext* app_context, size_t depth, const float* matrix20)
{
	(void)app_context;
	FilterListEntry* e = filterListAppend(depth);
	if (!e) return;
	e->type = 6;
	memcpy(e->cm_matrix, matrix20, 20 * sizeof(float));
}

void tagAddConvolutionFilter(SWFAppContext* app_context, size_t depth,
    u8 matrixX, u8 matrixY, const float* matrix, float divisor, float bias,
    u8 preserve_alpha, u8 clamp, u8 def_r, u8 def_g, u8 def_b, u8 def_a)
{
	(void)app_context;
	FilterListEntry* e = filterListAppend(depth);
	if (!e) return;
	e->type = 5;
	e->conv_mx = matrixX; e->conv_my = matrixY;
	int n = matrixX * matrixY;
	if (n > 25) n = 25;
	memcpy(e->conv_matrix, matrix, n * sizeof(float));
	e->conv_divisor = divisor; e->conv_bias = bias;
	e->conv_preserve_alpha = preserve_alpha; e->conv_clamp = clamp;
	e->conv_color_r = def_r; e->conv_color_g = def_g;
	e->conv_color_b = def_b; e->conv_color_a = def_a;
}

void tagAddGradientFilter(SWFAppContext* app_context, size_t depth,
    u8 type, u8 count, const u32* colors, const float* alphas, const u8* ratios,
    float blur_x, float blur_y, float angle, float distance, float strength,
    u8 quality, u8 flags)
{
	(void)app_context;
	FilterListEntry* e = filterListAppend(depth);
	if (!e) return;
	e->type = type; // 7=gradientglow, 8=gradientbevel
	if (count > 16) count = 16;
	e->grad_count = count;
	memcpy(e->grad_colors, colors, count * sizeof(u32));
	memcpy(e->grad_alphas, alphas, count * sizeof(float));
	memcpy(e->grad_ratios, ratios, count);
	e->blur_x = blur_x; e->blur_y = blur_y;
	e->angle = angle; e->distance = distance;
	e->strength = strength;
	e->quality = quality; e->flags = flags;
}

void tagEndFilterList(SWFAppContext* app_context, size_t depth)
{
	(void)app_context; (void)depth;
	g_current_filter_list_idx = -1;
}

const FilterListData* ng_getFilterListData(size_t entry_idx)
{
	size_t depth = entry_idx & 0xFFFFF;
	for (int i = 0; i < g_filter_list_count; i++) {
		if (g_filter_lists[i].depth == depth && g_filter_lists[i].count > 0)
			return &g_filter_lists[i];
	}
	return NULL;
}

void tagSetInstanceName(SWFAppContext* app_context, size_t depth, const char* name)
{
	(void)app_context;
#ifdef NO_GRAPHICS
	// In script_only_mode (Phase 2), display list is already set up from Phase 1 — skip.
	if (g_script_only_mode) return;
	// In tag_skip mode (deferred goto target-script replay), tags are no-ops.
	// Matches the gate other tag functions use (tagPlaceObject2, tagRemoveObject2,
	// etc). Without this, the deferred replay of a target frame's tagSetInstanceName
	// re-renames display entries that survived the rewind, clobbering their name.
	if (g_tag_skip_mode) return;
#endif

	// If the display entry doesn't exist yet (tagSetInstanceName called before tagPlaceObject2),
	// store as pending so the next PlaceObject at this depth uses it.
	if (depth > max_depth || display_list[depth].char_id == 0)
	{
		g_pending_instance_name = name;
		return;
	}
#ifdef NO_GRAPHICS
	// Backward catch-up replay: an existing entry at this depth was preserved
	// by ng_display_clear_after (surviving rewind). Don't rename it in-place —
	// Ruffle's apply_place_object does not update name on existing children.
	// Pend the name for tagPlaceObject2 to consume only if it takes the
	// full-replacement path (different char_id). Applies to both entries
	// whose placed_at_frame is ahead of the replay cursor (stale pre-rewind
	// state) and entries whose depth_swapped flag is set (post-swap entries
	// whose placed_at_frame now stays pinned to the depth per
	// ng_swapDisplayDepths / ng_updateDisplayDepth).
	{
		extern int catch_up_backward;
		if (catch_up_backward &&
		    (display_list[depth].placed_at_frame > current_frame
		     || display_list[depth].depth_swapped))
		{
			g_pending_instance_name = name;
			return;
		}
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
		// Also set the pending name so that a subsequent tagPlaceObject2 at
		// this depth (replacing the existing entry with a different char_id)
		// can consume it through its full-placement path — otherwise that
		// path wipes instance_name back to NULL, losing the name we just set.
		// Observed on natural end-of-movie loopback where frame 0 re-issues
		// tagSetInstanceName+tagPlaceObject2 against a depth still holding
		// the previous iteration's character.
		g_pending_instance_name = name;

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

void tagDefineFontGlyphBase(u16 font_id, size_t glyph_base)
{
#ifdef NO_GRAPHICS
	ng_record_font_glyph_base(font_id, glyph_base);
#else
	(void)font_id; (void)glyph_base;
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
	for (size_t i = 0; i <= dl_max; i++)
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
	// Phase 7b: turn on the deferred-Phase-2 sync-fire path in the sprite
	// DoAction gate (see swf.cpp). Sprite scripts for goto-placed sprites
	// fire synchronously inside this call, after the target frame's root
	// DoAction has already drained in the main loop.
	actionDeferredSpriteInitEnter();
	process_sprite_needs_init(app_context, &root_movieclip);
	actionDeferredSpriteInitLeave();

	g_sprite_init_filter_active = 0;

	ng_fire_pending_loads(app_context);
	ng_fire_pending_attach_inits(app_context);
	actionFirePendingLoadInits(app_context);

	g_enterframe_new_mc_start = mc_count_before;
	actionDispatchEnterFrameHandlers(app_context);
	g_enterframe_new_mc_start = -1;
}

// Fire registered class constructors for child sprites of a specific MC.
// Called after attachMovie fires the parent's constructor so that child
// constructors (e.g. "box" inside an attached "a" clip) fire immediately
// during the attachMovie call, before any goto catch-up places new sprites.
#ifdef NO_GRAPHICS
void ng_fire_child_constructors(SWFAppContext* app_context, MovieClip* mc)
{
	if (mc == NULL || mc->display_obj == NULL) return;
	DisplayObject* dobj = (DisplayObject*)mc->display_obj;
	if (dobj->sprite_display_list == NULL || dobj->sprite_max_depth == 0) return;
	fire_eager_constructors(app_context, dobj->sprite_display_list, dobj->sprite_max_depth, mc);
}
#endif

// Fire registered class constructors for ALL pending sprites (root + children),
// without running Phase 2 scripts. Uses process_sprite_needs_init in constructor_only
// mode so it naturally handles both root-level and nested sprites.
void ng_fire_deferred_constructors(SWFAppContext* app_context)
{
	extern void ng_sync_root_display_obj(void);
	ng_sync_root_display_obj();

	g_constructor_only_mode = 1;
	catch_up_mode = 0;
	process_sprite_needs_init(app_context, &root_movieclip);
	g_constructor_only_mode = 0;
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
// Entries at SWF depth >= AVM_DEPTH_BIAS (16384, i.e. AS depth >= 0, the
// "dynamic" range) survive backward jumps, matching Ruffle's AVM1
// survives_rewind rule: `old_object.depth() < AVM_DEPTH_BIAS` is the
// precondition for considering an object for removal during rewind.
//
// Initialized MovieClip (sprite) entries are preserved here so that
// tagPlaceObject2's catch-up path can decide on a per-placement basis
// whether to modify (same char_id, survives rewind) or replace (different
// char_id). Any sprite entries that no tag in [0, target] re-places get
// cleaned up by ng_display_cleanup_unplaced_after() after catch-up.
// This mirrors Ruffle's survives_rewind: for MovieClip, id + ratio must
// match the final placement; name is intentionally NOT reset (Ruffle
// apply_place_object comment: "name, clip_depth, clip_actions... can not
// be modified by subsequent PlaceObject tags").
void ng_display_clear_after(SWFAppContext* app_context, size_t target_frame)
{
	for (size_t i = 1; i <= max_depth; i++)
	{
		if (i >= 16384) break;  // dynamic-range entries survive rewind
		if (display_list[i].char_id != 0 &&
		    display_list[i].placed_at_frame > target_frame)
		{
			// Preserve initialized sprites — catch-up will decide survival.
			if (display_list[i].sprite_display_list != NULL)
				continue;
			display_list[i].char_id = 0;
		}
	}
}

// Post-catch-up cleanup: clear any entries whose placed_at_frame is still
// > target_frame. These are sprites preserved by ng_display_clear_after
// that weren't re-placed (modified) during catch-up — their survives_rewind
// test effectively failed.
void ng_display_cleanup_unplaced_after(SWFAppContext* app_context, size_t target_frame)
{
	(void)app_context;
	for (size_t i = 1; i <= max_depth; i++)
	{
		if (i >= 16384) break;
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

// Bitmap metadata registry (shared across all build modes)
#define MAX_BITMAP_DEFS 128
static struct { u16 char_id; size_t offset; size_t size; u32 width; u32 height; } g_bitmap_defs[MAX_BITMAP_DEFS];
static int g_bitmap_def_count = 0;

int ng_getBitmapMetadata(u16 char_id, size_t* out_offset, size_t* out_size, u32* out_width, u32* out_height)
{
	for (int i = 0; i < g_bitmap_def_count; i++) {
		if (g_bitmap_defs[i].char_id == char_id) {
			if (out_offset) *out_offset = g_bitmap_defs[i].offset;
			if (out_size) *out_size = g_bitmap_defs[i].size;
			if (out_width) *out_width = g_bitmap_defs[i].width;
			if (out_height) *out_height = g_bitmap_defs[i].height;
			return 1;
		}
	}
	return 0;
}

void ng_registerBitmapMetadata(u16 char_id, size_t offset, size_t size, u32 width, u32 height)
{
	if (g_bitmap_def_count < MAX_BITMAP_DEFS) {
		g_bitmap_defs[g_bitmap_def_count].char_id = char_id;
		g_bitmap_defs[g_bitmap_def_count].offset = offset;
		g_bitmap_defs[g_bitmap_def_count].size = size;
		g_bitmap_defs[g_bitmap_def_count].width = width;
		g_bitmap_defs[g_bitmap_def_count].height = height;
		g_bitmap_def_count++;
	}
}

#if !defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)
void defineBitmap(size_t offset, size_t size, u32 width, u32 height, u16 char_id)
{
	renderer_upload_bitmap(context, offset, size, width, height);
	ng_registerBitmapMetadata(char_id, offset, size, width, height);
}

void finalizeBitmaps()
{
	renderer_finalize_bitmaps(context);
}
#endif // NO_GRAPHICS
