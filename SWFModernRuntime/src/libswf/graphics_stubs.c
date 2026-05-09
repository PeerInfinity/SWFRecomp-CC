// graphics_stubs.c — definitions for symbols that exist as full
// implementations in NO_GRAPHICS / HEADLESS builds but are referenced
// (via extern in action_queue.c, etc.) in graphics builds.
//
// Compiled only in pure graphics builds (USE_WEBGPU set, NO_GRAPHICS unset,
// HEADLESS_GRAPHICS unset). The remaining entries here are 0-init globals
// and no-op functions whose semantics are correct in graphics mode (the
// graphics frame loop never sets these, so 0 is the right value).
//
// (AVM1 button hit-testing and hover detection are no longer stubbed —
// shape_hit_test.c provides the real ng_hitTestShapeChar, and the action.c
// helpers actionMCHasButtonHandlers / actionMCMouseInsidePick /
// mc_get_pixel_aabb_ng are now un-gated.)

#if defined(USE_WEBGPU) && !defined(NO_GRAPHICS) && !defined(HEADLESS_GRAPHICS)

#include <stddef.h>
#include <stdint.h>

// Backward-goto catch-up state. In NO_GRAPHICS / HEADLESS_GRAPHICS these
// live in swf_core.c / swf_headless.c and are managed by the catch-up
// phase of the frame loop. The graphics frame loop in swf.c has no
// catch-up phase, so the variables stay 0 here — that's the correct
// "no catch-up in progress" state, not a stub. action_queue.c reads them
// to gate cleanup work that would otherwise happen during a backward
// goto; with the variables permanently 0 those branches are inert,
// matching the intent that graphics-mode swf.c skips that work.
int catch_up_backward = 0;
size_t catch_up_target = 0;
int g_natural_wrap_cleanup_pending = 0;

// SetTarget state flags. Real definitions live in action.c under
// #ifdef NO_GRAPHICS; action_queue.c saves/resets/restores them around
// each sprite-script dispatch. With them as plain (graphics-side) globals
// initialised to 0, the save→reset→restore sequence is a no-op cycle —
// safe because graphics-mode code paths never read them outside of
// SetTarget-related logic that lives entirely under NO_GRAPHICS.
int g_settarget_explicit_root = 0;
int g_settarget_invalid = 0;
int g_settarget_none = 0;

// Force-quit flag — set by exit handlers in NO_GRAPHICS swf_core.c.
// Graphics frame loop in swf.c uses its own quit_swf flag; g_force_quit
// is checked from action.c (e.g. AS-level fscommand("quit")) but in
// graphics mode we just leave it at 0 (no-op).
int g_force_quit = 0;

// Sprite-init / catch-up state-machine accessors. Real impls in tag.c under
// #ifdef NO_GRAPHICS track the state of NO_GRAPHICS-only init phases:
// eager init (Phase 1), script-only re-run (Phase 2), goto catch-up,
// deferred sprite init, and attachMovie's Phase F. Graphics builds have
// none of these phases — frame execution is straight-through — so the
// accessors all return 0 ("not in any special mode") and the
// Enter/Leave wrappers are no-ops. The recompiler-generated tagMain.c
// queries these via the accessor to choose between sync-fire and queue
// modes for sprite script dispatch; with all returning 0, it picks the
// straightforward sync-fire path which matches graphics-mode semantics.
int actionEagerInitActive(void)            { return 0; }
int actionScriptOnlyMode(void)             { return 0; }
int actionGotoCatchupActive(void)          { return 0; }
int actionDeferredSpriteInitActive(void)   { return 0; }
int actionAttachInitActive(void)           { return 0; }
void actionEagerInitEnter(void)            {}
void actionEagerInitLeave(void)            {}
void actionGotoCatchupEnter(void)          {}
void actionGotoCatchupLeave(void)          {}
void actionDeferredSpriteInitEnter(void)   {}
void actionDeferredSpriteInitLeave(void)   {}
void actionAttachInitEnter(void)           {}
void actionAttachInitLeave(void)           {}

// Sprite-init-depth bump/unbump (real impls in tag.c NO_GRAPHICS).
// No-ops; ng_isInsideSpriteInit returns 0 below.
void ng_bumpSpriteInitDepth(void)          {}
void ng_unbumpSpriteInitDepth(void)        {}
int ng_isInsideSpriteInit(void)            { return 0; }

// ---- Phase 1 stubs for --mode=graphics (graphics-native test mode) ----
// These were sufficient for the old wasm --mode=graphics path because action.c
// only referenced them under NO_GRAPHICS. Recent un-gating commits broadened
// the references; running tests against swf.c natively now also reaches them.
// Phase 2 of graphics-native-test-mode-plan.md will backport real impls or
// widen the gates in tag.c.

#include <swf.h>
#include <tag.h>
#include <action.h>  // full struct MovieClip needed by exec_sprite_frame body

// Active transform data pointer. Real impl in tag.c (NO_GRAPHICS arm) swaps
// to a child SWF's transform array. With NULL, ng_cache_transform() in tag.c
// falls back to the main SWF's transform_data — correct for single-SWF tests,
// possibly wrong for multi-SWF (loadMovie) tests.
float (*g_active_transform_data)[16] = NULL;

// Clone-depth-already-unbiased flag — set by createEmptyMovieClip path in
// swf_core.c. Graphics-native createEmptyMovieClip path will set its own.
int g_clone_depth_already_unbiased = 0;

// JS-callback inputs (text input, IME, focus). In emscripten browser builds
// these live in render_webgpu.c and are populated by JS event listeners. In
// native offscreen mode there is no input source, so they remain zero —
// swf.c's per-frame drain reads zero, no events fire.
#define _OR_TEXT_INPUT_RING_SIZE 64
#define _OR_IME_TEXT_BUF_SIZE 256
int g_text_input_ring[_OR_TEXT_INPUT_RING_SIZE];
int g_text_input_ring_head = 0;
int g_text_input_ring_tail = 0;
int g_window_focus_lost = 0;
char g_ime_compose_text[_OR_IME_TEXT_BUF_SIZE];
char g_ime_commit_text[_OR_IME_TEXT_BUF_SIZE];
int g_ime_compose_pending = 0;
int g_ime_commit_pending = 0;

// exec_sprite_frame: ported verbatim from tag.c (where it lives under
// #ifdef NO_GRAPHICS). All globals it touches exist in graphics-native:
// g_current_sprite_obj is in swf.c; g_current_context, actionGetBaseClip /
// actionSetBaseClip / actionSetCurrentContext / actionFindMovieClipByName
// are in action.c; g_settarget_* and g_active_transform_data are stubs
// above. If tag.c's impl changes, mirror the change here. Phase 3 retires
// this duplication along with HEADLESS_GRAPHICS.
extern MovieClip* g_current_context;
extern void actionSetCurrentContext(MovieClip* mc);
extern MovieClip* actionGetBaseClip(void);
extern void actionSetBaseClip(MovieClip* mc);
extern int g_settarget_context_changed;
extern MovieClip* g_settarget_saved_context;
void exec_sprite_frame(SWFAppContext* app_context, DisplayObject* obj, frame_func f)
{
    DisplayObject* saved = g_current_sprite_obj;
    g_current_sprite_obj = obj;

    MovieClip* saved_ctx = g_current_context;
    MovieClip* saved_base = actionGetBaseClip();
    if (obj->instance_name != NULL)
    {
        extern MovieClip* actionFindMovieClipByName(const char* instance_name);
        MovieClip* mc = actionFindMovieClipByName(obj->instance_name);
        if (mc) { mc->display_obj = (void*)obj; actionSetCurrentContext(mc); actionSetBaseClip(mc); }
    }

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

    float (*saved_td)[16] = g_active_transform_data;
    if (obj->child_transform_data != NULL)
        g_active_transform_data = obj->child_transform_data;

    if (f) f(app_context);

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

// sprite_content_bounds_twips: returns 0 (no bounds). getBounds-on-sprite
// tests will report 0×0. Phase 2.
int sprite_content_bounds_twips(DisplayObject* dl, size_t dl_max,
                                float* xmin_out, float* xmax_out,
                                float* ymin_out, float* ymax_out) {
    (void)dl; (void)dl_max;
    if (xmin_out) *xmin_out = 0;
    if (xmax_out) *xmax_out = 0;
    if (ymin_out) *ymin_out = 0;
    if (ymax_out) *ymax_out = 0;
    return 0;
}

// process_sprite_needs_init_public: NO_GRAPHICS sprite-needs-init phase. No-op.
void process_sprite_needs_init_public(SWFAppContext* app_context, MovieClip* parent_mc) {
    (void)app_context; (void)parent_mc;
}

// ng_set_script_only_mode: NO_GRAPHICS script-only re-run phase. No-op.
void ng_set_script_only_mode(int mode) { (void)mode; }

// ng_queue_placement_clip_events: queues clip events for newly-placed sprites.
// Stub means CONSTRUCT/LOAD events on attachMovie won't fire in graphics-native
// mode. Phase 2.
void ng_queue_placement_clip_events(SWFAppContext* app_context, size_t depth) {
    (void)app_context; (void)depth;
}

#endif // USE_WEBGPU && !NO_GRAPHICS && !HEADLESS_GRAPHICS
