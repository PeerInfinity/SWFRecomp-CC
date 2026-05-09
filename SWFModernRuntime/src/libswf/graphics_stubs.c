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

// Sprite-init-depth bump/unbump. NO_GRAPHICS tracks this so inline goto
// catch-up can swap to the root display list. Graphics mode has no
// inline catch-up, so the bump/unbump are no-ops. ng_isInsideSpriteInit()
// (also NO_GRAPHICS-only at the call sites) consequently returns false
// in graphics mode, which is correct.
void ng_bumpSpriteInitDepth(void) {}
void ng_unbumpSpriteInitDepth(void) {}


#endif // USE_WEBGPU && !NO_GRAPHICS && !HEADLESS_GRAPHICS
