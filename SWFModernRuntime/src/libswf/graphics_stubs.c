// graphics_stubs.c — definitions for symbols that exist as full
// implementations in NO_GRAPHICS / OFFSCREEN_RENDER builds but
// are referenced (via extern in action_queue.c, etc.) in graphics builds.
//
// Compiled in both:
//   - wasm browser graphics (USE_WEBGPU, no NO_GRAPHICS / OFFSCREEN_RENDER)
//   - --mode=graphics native (USE_WEBGPU + OFFSCREEN_RENDER)
//
// Symbols split into two groups:
//   1. Always-active stubs (zero-init globals, no-op functions whose
//      semantics are correct for any graphics mode).
//   2. Wasm-only stubs (#ifndef OFFSCREEN_RENDER) for symbols that tag.c's
//      widened (NO_GRAPHICS || OFFSCREEN_RENDER) arm now provides for
//      --mode=graphics — wasm graphics doesn't get those, so this file
//      still needs to fill the gap.

#if defined(USE_WEBGPU) && !defined(NO_GRAPHICS)

#include <stddef.h>
#include <stdint.h>
#include <math.h>
#include <swf.h>
#include <tag.h>
#include <action.h>  // full struct MovieClip needed by exec_sprite_frame body

// ---------------------------------------------------------------------------
// Group 1: Always-active stubs (both wasm and graphics-native)
// ---------------------------------------------------------------------------

// Backward-goto catch-up state. swf_core.c manages these in the
// NO_GRAPHICS frame loop; in graphics builds the frame loop has
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

// Active transform data pointer. Real impl in tag.c (NO_GRAPHICS arm)
// swaps to a child SWF's transform array; with NULL, ng_cache_transform
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
    // Real bounds (twips) of a display list, recursing into nested sprites, via
    // the shared bounds engine (tag_stubs.c, linked in browser-WASM). This was a
    // 0-returning stub, so ng_attachMovie set every attached clip's mc->width/
    // height to 0 — e.g. Minesweeper's FRadioButton circle frb_states_mc._width
    // read 0, so FRadioButton.setLabelPlacement put fLabel_mc._x = radioWidth = 0
    // and the label drew on top of the circle (circle invisible), and the
    // component width math fell short (clipped labels). NO_GRAPHICS/OFFSCREEN have
    // the real impl in tag.c. Output order matches the callers: (xmin, xmax, ymin,
    // ymax).
    extern int ng_computeBoundsFromDL_matrix(DisplayObject*, size_t,
        double, double, double, double, double, double,
        int*, double*, double*, double*, double*);
    int has = 0;
    double xmin = 0, ymin = 0, xmax = 0, ymax = 0;
    if (dl != NULL)
        ng_computeBoundsFromDL_matrix(dl, dl_max, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,
            &has, &xmin, &ymin, &xmax, &ymax);
    if (xmin_out) *xmin_out = (float)xmin;
    if (xmax_out) *xmax_out = (float)xmax;
    if (ymin_out) *ymin_out = (float)ymin;
    if (ymax_out) *ymax_out = (float)ymax;
    return has;
}

void ng_queue_placement_clip_events(SWFAppContext* app_context, size_t depth) {
    (void)app_context; (void)depth;
}

// ng_queue_slot_unload_events: real implementation in tag.c for every build
// since s30 browser-pending-finalize (it was stubbed here, which dropped a
// timeline clip's onClipEvent(unload) on swapDepths + removeMovieClip).
#endif

// ---------------------------------------------------------------------------
// Group 2 (removed in s27 browser-eager-init): wasm-only stubs for the
// sprite-init / catch-up accessors, process_sprite_needs_init_public,
// ng_set_script_only_mode and a reduced exec_sprite_frame. tag.c's frame-helper
// machinery is now compiled in browser-WASM too (eager placement init), so the
// browser links the real implementations the CI modes run.
// ---------------------------------------------------------------------------

#endif // USE_WEBGPU && !NO_GRAPHICS
