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

#endif // USE_WEBGPU && !NO_GRAPHICS && !HEADLESS_GRAPHICS
