// graphics_stubs.c — minimal stubs for symbols that exist as full
// implementations in NO_GRAPHICS / HEADLESS builds (in tag_stubs.c and the
// big NO_GRAPHICS block in action.c) but are required at link time by
// graphics-mode tag.c (e.g. ng_update_button_states_in_dl, the AVM1 button
// state machine).
//
// Compiled only in pure graphics builds (USE_WEBGPU set, NO_GRAPHICS unset,
// HEADLESS_GRAPHICS unset). The stubs disable AVM1 button hit-testing and
// hover dispatch; they're sufficient to render SWFs whose tests don't rely
// on user mouse interaction. Replace with real implementations if/when
// graphics-mode mouse interaction is needed.

#if defined(USE_WEBGPU) && !defined(NO_GRAPHICS) && !defined(HEADLESS_GRAPHICS)

#include <stddef.h>
#include <stdint.h>

typedef uint16_t u16;

typedef struct MovieClip MovieClip;

int actionMCHasButtonHandlers(MovieClip* mc)
{
	(void)mc;
	return 0;
}

int actionMCMouseInsidePick(MovieClip* mc, float mx, float my)
{
	(void)mc;
	(void)mx;
	(void)my;
	return 0;
}

int ng_hitTestShapeChar(size_t char_id, u16 ratio,
                        double ma, double mb, double mc_m, double md,
                        double mtx, double mty,
                        double test_x, double test_y)
{
	(void)char_id;
	(void)ratio;
	(void)ma; (void)mb; (void)mc_m; (void)md;
	(void)mtx; (void)mty;
	(void)test_x; (void)test_y;
	return 0;
}

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
