// graphics_stubs.c — definitions for symbols that exist as full
// implementations in NO_GRAPHICS / HEADLESS / OFFSCREEN_RENDER builds but
// are referenced (via extern in action_queue.c, etc.) in graphics builds.
//
// Compiled in both:
//   - wasm browser graphics (USE_WEBGPU, no NO_GRAPHICS / HEADLESS_GRAPHICS / OFFSCREEN_RENDER)
//   - --mode=graphics native (USE_WEBGPU + OFFSCREEN_RENDER)
//
// Symbols split into two groups:
//   1. Always-active stubs (zero-init globals, no-op functions whose
//      semantics are correct for any graphics mode).
//   2. Wasm-only stubs (#ifndef OFFSCREEN_RENDER) for symbols that tag.c's
//      widened (NO_GRAPHICS || OFFSCREEN_RENDER) arm now provides for
//      --mode=graphics — wasm graphics doesn't get those, so this file
//      still needs to fill the gap.

#if defined(USE_WEBGPU) && !defined(NO_GRAPHICS) && !defined(HEADLESS_GRAPHICS)

#include <stddef.h>
#include <stdint.h>
#include <swf.h>
#include <tag.h>
#include <action.h>  // full struct MovieClip needed by exec_sprite_frame body

// ---------------------------------------------------------------------------
// Group 1: Always-active stubs (both wasm and graphics-native)
// ---------------------------------------------------------------------------

// Backward-goto catch-up state. swf_core.c / swf_headless.c manage these in
// NO_GRAPHICS / HEADLESS frame loops; in graphics builds the frame loop has
// no catch-up phase, so the variables stay 0 here — that's the correct
// "no catch-up in progress" state, not a stub. action_queue.c reads them
// to gate cleanup work that would otherwise happen during a backward goto;
// with the variables permanently 0 those branches are inert, matching the
// intent that graphics-mode swf.c skips that work.
int catch_up_backward = 0;
size_t catch_up_target = 0;
int g_natural_wrap_cleanup_pending = 0;

// SetTarget state flags. Real definitions live in action.c (now widened).
// In wasm graphics, these stubs keep the save→reset→restore cycle a no-op.
#ifndef OFFSCREEN_RENDER
int g_settarget_explicit_root = 0;
int g_settarget_invalid = 0;
int g_settarget_none = 0;
#endif

// Force-quit flag — set by exit handlers in NO_GRAPHICS swf_core.c.
// Graphics frame loop in swf.c uses its own quit_swf flag.
int g_force_quit = 0;

// Active transform data pointer. Real impl in tag.c (NO_GRAPHICS / HEADLESS
// arm) swaps to a child SWF's transform array; with NULL, ng_cache_transform
// in tag.c falls back to the main SWF's transform_data — correct for
// single-SWF tests, possibly wrong for multi-SWF (loadMovie) tests.
// In OFFSCREEN_RENDER, tag.c provides this via the widened gate.
#ifndef OFFSCREEN_RENDER
float (*g_active_transform_data)[16] = NULL;
#endif

// Clone-depth-already-unbiased flag — set by createEmptyMovieClip in
// swf_core.c. In OFFSCREEN_RENDER action.c (widened) provides it.
#ifndef OFFSCREEN_RENDER
int g_clone_depth_already_unbiased = 0;
#endif

// JS-callback inputs (text input, IME, focus). In emscripten browser builds
// these live in render_webgpu.c populated by JS event listeners (gated by
// __EMSCRIPTEN__ there), so we must NOT redefine them here for wasm graphics.
// In native offscreen mode render_webgpu.c's __EMSCRIPTEN__ arm is inactive,
// so the symbols are missing — provide zero-init stubs. swf.c's per-frame
// drain then reads zero and no events fire.
#ifdef OFFSCREEN_RENDER
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
#endif

// sprite_content_bounds_twips and ng_queue_placement_clip_events:
// stubs for wasm graphics. In OFFSCREEN_RENDER tag.c provides real impls.
#ifndef OFFSCREEN_RENDER
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

void ng_queue_placement_clip_events(SWFAppContext* app_context, size_t depth) {
    (void)app_context; (void)depth;
}
#endif

// ---------------------------------------------------------------------------
// Group 2: Wasm-only stubs (#ifndef OFFSCREEN_RENDER)
// In --mode=graphics native, tag.c's (NO_GRAPHICS || OFFSCREEN_RENDER) arm
// provides real impls for these — defining them here would multi-define.
// Wasm graphics still needs the stubs.
// ---------------------------------------------------------------------------

#ifndef OFFSCREEN_RENDER

// Sprite-init / catch-up state-machine accessors. Real impls in tag.c.
// In wasm graphics, frame execution is straight-through — the accessors all
// return 0 and Enter/Leave wrappers are no-ops. The recompiler-generated
// tagMain.c queries these via the accessor to choose between sync-fire and
// queue modes; with all returning 0, sync-fire path is used.
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

// Sprite-init-depth bump/unbump (real impls in tag.c NO_GRAPHICS arm).
void ng_bumpSpriteInitDepth(void)          {}
void ng_unbumpSpriteInitDepth(void)        {}
int ng_isInsideSpriteInit(void)            { return 0; }

// process_sprite_needs_init_public: NO_GRAPHICS sprite-needs-init phase.
// In wasm graphics this is a no-op; in --mode=graphics tag.c provides
// the real impl.
void process_sprite_needs_init_public(SWFAppContext* app_context, MovieClip* parent_mc) {
    (void)app_context; (void)parent_mc;
}

// ng_set_script_only_mode: NO_GRAPHICS script-only re-run phase.
void ng_set_script_only_mode(int mode) { (void)mode; }

// exec_sprite_frame: in wasm graphics this is a minimal context tracker.
// Sets g_current_sprite_obj for the duration of the frame call so that
// ng_isInsideSprite() / ng_stopCurrentSprite() / ng_playCurrentSprite() —
// which the recompiler-emitted scripts hit when a sprite frame calls
// actionStop/actionPlay directly — can identify "we're inside a sprite"
// and route the call to the sprite's display entry rather than falling
// through to the root timeline's is_playing flag. (Doodle Jump's hero
// sprite has a frame-0 actionStop() that was stopping the root and
// leaving the sprite cycling.) --mode=graphics native uses tag.c's
// full impl which does the same plus context/base-clip/transform swaps.
void exec_sprite_frame(SWFAppContext* app_context, DisplayObject* obj, frame_func f) {
    extern DisplayObject* g_current_sprite_obj;
    DisplayObject* saved = g_current_sprite_obj;
    g_current_sprite_obj = obj;
    if (f) f(app_context);
    g_current_sprite_obj = saved;
}

#endif // !OFFSCREEN_RENDER

#endif // USE_WEBGPU && !NO_GRAPHICS && !HEADLESS_GRAPHICS
