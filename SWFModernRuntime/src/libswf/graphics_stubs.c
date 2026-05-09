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

// action_queue.c references these; in NO_GRAPHICS they live in swf_core.c
// and the bodies of tag.c / sprite_frame_scripts.c (all gated by
// #ifdef NO_GRAPHICS). Stubbed to 0 / no-op so the queue links in graphics
// builds. Backward-goto catch-up semantics aren't currently exercised by
// graphics-mode demos.
int catch_up_backward = 0;
size_t catch_up_target = 0;
int g_natural_wrap_cleanup_pending = 0;

struct SWFAppContext;
void ng_display_cleanup_unplaced_after(struct SWFAppContext* app_context, size_t target_frame)
{
	(void)app_context;
	(void)target_frame;
}

size_t actionFlushPendingSpriteScriptsToScriptQueue(struct SWFAppContext* app_context)
{
	(void)app_context;
	return 0;
}

#endif // USE_WEBGPU && !NO_GRAPHICS && !HEADLESS_GRAPHICS
