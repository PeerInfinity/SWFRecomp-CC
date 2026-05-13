#if !defined(NO_GRAPHICS) && !defined(HEADLESS_GRAPHICS)

#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <swf.h>
#include <tag.h>
#include <action.h>
#include <object.h>
#include <variables.h>
#include <renderer.h>
#include <utils.h>
#include <heap.h>
#include <audio/audio.h>
#ifdef OFFSCREEN_RENDER
#include <libswf/capture.h>
#endif

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

int quit_swf;
int is_playing = 1;
int bad_poll;
size_t current_frame;
size_t next_frame;
int manual_next_frame;
ActionVar* temp_val;

// Global frame access for ActionCall opcode
frame_func* g_frame_funcs = NULL;
size_t g_frame_count = 0;

// Drag state tracking
int is_dragging = 0;
char* dragged_target = NULL;
float g_drag_virt_x = 0.0f;
float g_drag_virt_y = 0.0f;
char g_drag_target_name[256] = "";

// Frame execution state — needed by tag.c sprite advancement
int catch_up_mode = 0;
int g_tag_skip_mode = 0;

// Goto-catch-up state and executors — ported from swf_core.c. Phase 3
// retires this duplication along with HEADLESS_GRAPHICS.
int goto_from_action = 0;
int g_deferred_root_goto = 0;
int g_skip_inline_target_script = 0;
int g_goto_inlined_in_caller_frame = 0;

extern void ng_display_clear_after(SWFAppContext* app_context, size_t target_frame);
extern void ng_display_cleanup_unplaced_after(SWFAppContext* app_context, size_t target_frame);
extern void actionRewindCleanup(SWFAppContext* app_context);
// actionDrainActionQueueByKind comes from action_queue.h below
extern void actionDrainSuppressEnter(void);
extern void actionDrainSuppressLeave(void);
extern void actionGotoCatchupEnter(void);
extern void actionGotoCatchupLeave(void);
extern int  ng_swapToRootDL(DisplayObject** saved_dl, size_t* saved_max, size_t* saved_cap);
extern void ng_restoreFromRootDL(DisplayObject* saved_dl, size_t saved_max, size_t saved_cap);
extern void ng_run_deferred_sprite_init_before(SWFAppContext*, size_t);
extern void ng_run_deferred_sprite_init_on_or_after(SWFAppContext*, size_t);
extern int g_defer_sprite_init;
extern size_t g_place_gen;
extern int catch_up_backward;
extern size_t catch_up_target;
#include <actionmodern/action_queue.h>

void ng_executeGotoCatchUp(SWFAppContext* app_context)
{
	if (!goto_from_action || !manual_next_frame) return;

	DisplayObject* saved_sprite_dl = NULL;
	size_t saved_sprite_max = 0, saved_sprite_cap = 0;
	int swapped = ng_swapToRootDL(&saved_sprite_dl, &saved_sprite_max, &saved_sprite_cap);

	g_place_gen++;

	frame_func* funcs = g_frame_funcs;
	size_t original_frame = current_frame;
	size_t target = next_frame;

	ng_display_clear_after(app_context, target);

	int saved_tag_skip = g_tag_skip_mode;
	int saved_defer_sprite = g_defer_sprite_init;
	g_tag_skip_mode = 0;
	g_defer_sprite_init = 1;
	catch_up_mode = 1;
	actionGotoCatchupEnter();
	if (target <= original_frame)
	{
		actionRewindCleanup(app_context);
		catch_up_backward = 1;
		catch_up_target = target;
		for (size_t f = 0; f <= target && f < g_frame_count; f++)
		{
			current_frame = f;
			if (funcs[f]) funcs[f](app_context);
		}
		catch_up_backward = 0;
		ng_display_cleanup_unplaced_after(app_context, target);
	}
	else
	{
		for (size_t f = original_frame + 1; f <= target && f < g_frame_count; f++)
		{
			current_frame = f;
			if (funcs[f]) funcs[f](app_context);
		}
	}
	actionGotoCatchupLeave();
	catch_up_mode = 0;
	g_tag_skip_mode = saved_tag_skip;
	(void)saved_defer_sprite;
	current_frame = target;

	actionDrainActionQueueByKind(app_context, AQ_KIND_CLIP_INIT);
	actionDrainActionQueueByKind(app_context, AQ_KIND_REGISTER_CTOR);

	if (swapped)
		ng_restoreFromRootDL(saved_sprite_dl, saved_sprite_max, saved_sprite_cap);

	goto_from_action = 0;
	manual_next_frame = 0;

	int skip_inline = g_skip_inline_target_script;
	g_skip_inline_target_script = 0;
	if (!skip_inline && target < g_frame_count && funcs[target])
	{
		int saved_defer_phase_f = g_defer_sprite_init;
		g_defer_sprite_init = 0;
		ng_run_deferred_sprite_init_before(app_context, target);
		int saved_tag_skip_phase_e = g_tag_skip_mode;
		g_tag_skip_mode = 1;
		actionDrainSuppressEnter();
		funcs[target](app_context);
		actionDrainSuppressLeave();
		g_tag_skip_mode = saved_tag_skip_phase_e;
		ng_run_deferred_sprite_init_on_or_after(app_context, target);
		g_defer_sprite_init = saved_defer_phase_f;
		g_goto_inlined_in_caller_frame = 1;
	}
}

void ng_executeGotoTagsOnly(SWFAppContext* app_context)
{
	if (!goto_from_action || !manual_next_frame) return;

	g_place_gen++;

	frame_func* funcs = g_frame_funcs;
	size_t original_frame = current_frame;
	size_t target = next_frame;

	ng_display_clear_after(app_context, target);

	int saved_tag_skip = g_tag_skip_mode;
	int saved_defer_sprite = g_defer_sprite_init;
	g_tag_skip_mode = 0;
	g_defer_sprite_init = 1;
	catch_up_mode = 1;
	if (target <= original_frame)
	{
		actionRewindCleanup(app_context);
		catch_up_backward = 1;
		catch_up_target = target;
		for (size_t f = 0; f <= target && f < g_frame_count; f++)
		{
			current_frame = f;
			if (funcs[f]) funcs[f](app_context);
		}
		catch_up_backward = 0;
		ng_display_cleanup_unplaced_after(app_context, target);
	}
	else
	{
		for (size_t f = original_frame + 1; f <= target && f < g_frame_count; f++)
		{
			current_frame = f;
			if (funcs[f]) funcs[f](app_context);
		}
	}
	catch_up_mode = 0;
	g_tag_skip_mode = saved_tag_skip;
	g_defer_sprite_init = saved_defer_sprite;

	current_frame = original_frame;

	g_deferred_root_goto = 1;
}

Character* dictionary = NULL;

DisplayObject* display_list = NULL;
size_t max_depth = 0;

// Dummy sprite object pointer for the wasm browser graphics build only —
// in --mode=graphics native (OFFSCREEN_RENDER), tag.c's widened
// (NO_GRAPHICS || OFFSCREEN_RENDER) arm provides the real one and defining
// it here would conflict.
#ifndef OFFSCREEN_RENDER
DisplayObject* g_current_sprite_obj = NULL;
#endif

RenderContext* context;

void tagMain(SWFAppContext* app_context)
{
	frame_func* frame_funcs = app_context->frame_funcs;
	u32 frame_ms = app_context->fps > 0 ? 1000 / app_context->fps : 83;

#ifdef MAX_FRAMES
	// Test-mode termination: bound the loop. Mirrors swf_core.c's max_ticks.
	const size_t max_ticks = MAX_FRAMES;
	size_t tick_count = 0;
#endif

#ifdef OFFSCREEN_RENDER
	// Execution timeout (mirrors swf_core.c): bound any single script's
	// wall-clock time so an infinite loop in AS doesn't hang the test
	// runner. Tests opt-in via `max_execution_duration` in test.toml →
	// `-DMAX_EXECUTION_MS=N` from verify_output.py. On timeout,
	// actionCheckExecutionTimeout longjmps back here. Key test:
	// avm1/timeout (infinite-loop try/catch).
#ifdef MAX_EXECUTION_MS
	actionSetMaxExecutionDuration(MAX_EXECUTION_MS);
#endif
	actionResetExecutionTimer();
	jmp_buf timeout_jmp;
	if (setjmp(timeout_jmp) != 0)
	{
		// Returned here via longjmp — execution was halted by timeout.
		goto frame_loop_exit;
	}
	actionSetTimeoutJmp(&timeout_jmp);
#endif

	while (1)
	{
#ifdef MAX_FRAMES
		if (tick_count >= max_ticks) break;
		tick_count++;
#endif

#ifdef OFFSCREEN_RENDER
		// Mirror swf_core.c's exit condition (around line 1056). The
		// recompiler-emits `quit_swf = 1` at the end of the last root
		// frame, but multi-frame sprites placed by that frame still need
		// to advance through their own timelines. Without this widened
		// check, the loop exits after one root tick and any sprite that
		// hasn't reached its own last frame is silently abandoned. Key
		// test: avm1/tell_target (script_3 lives on sprite_6 frame 1, so
		// it never runs without continued ticking after quit_swf=1).
		// Also gate on pending loadMovie / loadClip queues — otherwise
		// loadMovie from the last root frame exits before
		// actionFirePendingDirectLoads / actionFirePendingLoadInits get
		// to fire the child's init+frame0 (drops the "Child movie loaded!"
		// trace line in avm1/loadmovie and the loadmovie/loadmovienum
		// cluster). Mirrors swf_core.c (line ~1064).
		{
			extern int hasPlayingSounds(void);
			extern int hasActiveNetStreams(void);
			extern int hasPlayingLevels(void);
			extern int g_pending_mcl_load_count;
			extern int g_pending_direct_load_count;
			// Keep the loop alive while pre-loaded input events remain so
			// post-quit_swf MouseMove / KeyDown / etc. still fire their AS2
			// handlers. swf_core.c (line ~1056) and swf_headless.c (line
			// ~1023) both gate on this. Without it, a test whose root
			// frame_0 sets quit_swf=1 and stops all sprites exits the loop
			// before input_events_pump_tick gets to deliver the queued
			// events. Key test: avm1/hittest_morph_input — onRollOver
			// queued for MouseMove (180,160) never fired.
			extern size_t g_event_count;
			extern size_t g_event_pos;
			if (quit_swf
			    && g_event_pos >= g_event_count
			    && !actionHasEnterFrameHandlers()
			    && !hasPlayingSprites()
			    && !hasActiveTimers()
			    && !hasPlayingSounds()
			    && !hasActiveNetStreams()
			    && !hasPlayingLevels()
			    && !hasClipEnterFrameHandlers()
			    && g_pending_mcl_load_count == 0
			    && g_pending_direct_load_count == 0) break;

			// FSCommand:quit was called in a prior tick — exit as soon as
			// nothing is still asking to run. Without this, a SWF that
			// FSCommand:quits from a non-last frame but still has the natural
			// end-of-movie loopback (manual_next_frame=1, next_frame=0) keeps
			// restarting frame 0 forever, because hasPlayingSprites() stays
			// true. `g_force_quit` is set only by FSCommand:quit (not by the
			// recompiler-emitted end-of-movie quit_swf=1), so this bypasses
			// hasPlayingSprites / hasPlayingLevels / pending-load checks that
			// the regular quit_swf gate insists on. Mirrors swf_core.c
			// (line ~906). Key test: from_shumway/timeline/timeline_as2_1
			// (frame 5 calls FSCommand:quit but frame 4 loops back to
			// frame 1, so the test re-cycles 3× before max_ticks hits).
			{
				extern int g_force_quit;
				if (g_force_quit
				    && g_event_pos >= g_event_count
				    && !actionHasEnterFrameHandlers()
				    && !hasActiveTimers()
				    && !hasPlayingSounds()
				    && !hasActiveNetStreams()
				    && !hasClipEnterFrameHandlers()) break;
			}
		}
#else
		if (quit_swf) break;
#endif

#ifdef __EMSCRIPTEN__
		double frame_start = emscripten_get_now();
#endif
		// Flash clears the action stack at each frame boundary — see swf_core.c
		// for rationale. Key test: misc-swfc/stackscope.
		app_context->sp = INITIAL_SP;
		app_context->oldSP = 0;

		current_frame = next_frame;
#ifdef OFFSCREEN_RENDER
		// Capture scheduling: request a readback before this tick's frame
		// renders. With HEADLESS_RENDER_ENABLED on, this is a no-op unless
		// CAPTURE_TRIGGERS asks for the current tick or any last_frame.
		// Mirrors swf_headless.c line ~904.
		capture_tick_pre_frame();

		// Keep root _currentframe in sync with the natural advance. Mirrors
		// swf_core.c lines ~1425/1431 (which update at the END of each tick).
		// Without this, scripts running on frame N read a stale value left
		// behind by the most recent explicit goto, and pure natural advance
		// never updates _currentframe at all. Key test: avm1/goto_frame2 —
		// after gotoAndPlay(2) on frame 1 the natural advance to frames 2
		// and 3 leaves root_movieclip.currentframe stuck at 2 until the
		// next explicit goto.
		{
			extern MovieClip root_movieclip;
			root_movieclip.currentframe = (int)current_frame + 1;
		}

		// Clear g_defer_sprite_init at tick boundary. ng_executeGotoCatchUp
		// intentionally leaves it set so the calling frame's tagShowFrame
		// continues to defer sprite init for the rest of THAT tick. Without
		// a tick-boundary clear, a leak from a regular-frame-script
		// gotoAndPlay/gotoAndStop persists into subsequent frames, where it
		// suppresses process_sprite_needs_init for newly-placed sprites
		// (sprite_initialized stays 0 → onEnterFrame clip-actions never
		// dispatch). Mirrors swf_core.c (line ~951). Key test:
		// from_gnash/misc-ming.all/timeline_var_test — frame 1's
		// gotoAndPlay leaves the flag set, so the sprite placed on frame 3
		// never inits and its setTarget DoAction never pushes "setTarget"
		// into the ar array.
		{ extern int g_defer_sprite_init; g_defer_sprite_init = 0; }

		// Process deferred unloadMovie state (MC properties change on
		// next frame). Mirrors swf_core.c line ~918. Runs before
		// pending-removal finalize so any properties cleared by
		// unloadMovie are visible to the upcoming frame scripts.
		{
			extern void actionProcessDeferredUnloads(void);
			actionProcessDeferredUnloads();
		}

		// Finalize MCs marked for pending removal in the previous frame.
		// Mirrors swf_core.c's frame-start hook (around line 955). Without
		// this, AS-level removeMovieClip / tag RemoveObject2 with onUnload
		// handlers leave dynamic_props and var_map bindings live, so
		// `typeof(_root.clipN)` reports 'movieclip' on the next frame
		// instead of 'undefined'. Key test: avm1/unload.
		{
			extern void actionFinalizePendingRemovals(SWFAppContext* app_context);
			actionFinalizePendingRemovals(app_context);
		}

		// Promote pending MCL loads queued during the previous tick into
		// the "fire this tick" bucket. Mirrors swf_core.c line ~961.
		// Without this, MovieClipLoader.loadClip events queued for the
		// next tick never advance into the dispatch bucket and the
		// onLoadStart / onLoadComplete / onLoadInit listeners never
		// fire. Affects avm1/loadmovie_method, mcl_getprogress, etc.
		{
			extern void actionPromotePendingMCLLoads(SWFAppContext* app_context);
			actionPromotePendingMCLLoads(app_context);
		}
#endif

#ifndef OFFSCREEN_RENDER
		// Per-frame AS2 input dispatch.
		// In NO_GRAPHICS mode swf_core.c dispatches these per event; here we
		// dispatch per frame based on the flags + state set by render_webgpu.c's
		// callbacks. Runs BEFORE clearing the per-frame flags and BEFORE the
		// frame func so the transitions are visible to user scripts.
		//
		// Gated off in OFFSCREEN_RENDER because input_events_pump_tick (line
		// ~542) is the canonical event source there — it dispatches synchronously
		// AND sets mouse.clicked / .released, so a top-of-tick re-read here
		// would double-fire every mouse and key event. Key test: avm1/click_block
		// (last click was duplicated because the final EV_MOUSE_DOWN_LEFT in tick N
		// set mouse.clicked=1, and tick N+1's top dispatched MouseDown again).
		{
			// --- Mouse ---
			static float prev_stage_x = 0.0f;
			static float prev_stage_y = 0.0f;
			static int   prev_mouse_initialized = 0;
			float mx = app_context->mouse.stage_x;
			float my = app_context->mouse.stage_y;
			int moved = !prev_mouse_initialized || (mx != prev_stage_x) || (my != prev_stage_y);
			prev_stage_x = mx;
			prev_stage_y = my;
			prev_mouse_initialized = 1;
			if (moved) {
				actionEndVirtualHoverOnMouse(app_context);
				actionDispatchMCMouseMove(app_context);
				actionDispatchMCMouseMoveGlobal(app_context);
				actionResetHighlightForEvent(0); // 0=mouse_move
				// Extend textfield drag selection if mouse is moved while button
				// is held (matches swf_core.c EV_MOUSE_MOVE behavior).
				if (app_context->mouse.button_down) {
					extern void actionTextFieldDragSelect(SWFAppContext*);
					actionTextFieldDragSelect(app_context);
				}
			}
			if (app_context->mouse.clicked) {
				actionDispatchMouseDown(app_context);       // Mouse listener broadcast
				actionDispatchMCMouseDown(app_context);      // Per-MC AS2 dispatch
				actionMouseClickFocus(app_context);          // Focus acquisition
				actionDispatchMCPress(app_context);          // onPress
				actionResetHighlightForEvent(1);             // 1=left_down
				actionClearVirtualHover();
			}
			if (app_context->mouse.released) {
				extern void actionTextFieldDragEnd(SWFAppContext*);
				actionTextFieldDragEnd(app_context);         // Finalize drag selection
				actionDispatchMouseUp(app_context);          // Mouse listener broadcast
				actionDispatchMCMouseUp(app_context);        // Per-MC AS2 dispatch
				actionDispatchMCRelease(app_context);        // onRelease/onReleaseOutside
				actionResetHighlightForEvent(2);             // 2=left_up
			}

			// --- Keyboard ---
			// Detect key down/up transitions by comparing current keys.down[] to
			// the previous frame's snapshot. Each transition fires the focused-MC
			// dispatcher AND the global Key listener broadcast.
			static u8 prev_keys_down[256];
			static int prev_keys_initialized = 0;
			if (!prev_keys_initialized) {
				memset(prev_keys_down, 0, sizeof(prev_keys_down));
				prev_keys_initialized = 1;
			}
			int ctrl_held = (app_context->keys.down[17] != 0);
			for (int code = 0; code < 256; code++) {
				u8 cur = app_context->keys.down[code];
				u8 prev = prev_keys_down[code];
				if (cur && !prev) {
					app_context->keys.last_key_down = code;
					app_context->keys.last_key_ascii = (code >= 32 && code <= 126) ? code : 0;
					actionDispatchKeyDownToFocused(app_context, code);
					actionDispatchKeyDown(app_context);
					actionDispatchKeyPressToFocused(app_context, code);
					if (code == 9) { // Tab
						int shift_held = (app_context->keys.down[16] != 0);
						actionAdvanceTabFocus(app_context, shift_held);
					}
					// Text-control shortcuts. Equivalent to swf_core.c's
					// EV_TEXT_CONTROL events. Each handler internally checks
					// for a focused textfield and no-ops otherwise.
					if (ctrl_held) {
						switch (code) {
							case 65: actionTextControlSelectAll(app_context); break; // Ctrl+A
							case 67: actionTextControlCopy(app_context);      break; // Ctrl+C
							case 86: actionTextControlPaste(app_context);     break; // Ctrl+V
							case 88: actionTextControlCut(app_context);       break; // Ctrl+X
						}
					} else {
						switch (code) {
							case 8:  actionTextControlBackspace(app_context); break; // Backspace
							case 13: actionTextControlEnter(app_context);     break; // Enter
							case 37: actionTextControlMoveLeft(app_context);  break; // Left arrow
							case 39: actionTextControlMoveRight(app_context); break; // Right arrow
						}
					}
				} else if (!cur && prev) {
					app_context->keys.last_key_down = code;
					app_context->keys.last_key_ascii = (code >= 32 && code <= 126) ? code : 0;
					actionDispatchKeyUpToFocused(app_context, code);
					actionDispatchKeyUp(app_context);
				}
				prev_keys_down[code] = cur;
			}

			// --- Text input (typed characters from emscripten keypress callback) ---
			// Drain the ring buffer populated by render_webgpu.c's on_keypress.
			extern int g_text_input_ring[];
			extern int g_text_input_ring_head;
			extern int g_text_input_ring_tail;
			while (g_text_input_ring_tail != g_text_input_ring_head) {
				int cp = g_text_input_ring[g_text_input_ring_tail];
				g_text_input_ring_tail = (g_text_input_ring_tail + 1) % 64;
				// Suppress text input for control characters that are also dispatched
				// via the text-control shortcuts above (Backspace, Tab, Enter, Esc).
				if (cp == 8 || cp == 9 || cp == 13 || cp == 27) continue;
				if (ctrl_held) continue; // Ctrl+letter shortcuts shouldn't also type the letter
				actionTextFieldInput(app_context, cp);
			}

			// --- Window focus lost ---
			extern int g_window_focus_lost;
			if (g_window_focus_lost) {
				g_window_focus_lost = 0;
				actionWindowFocusLost(app_context);
			}

			// --- IME compose / commit ---
			// Driven by JS listeners in render_webgpu.c (compositionupdate /
			// compositionend on the canvas). The compose call places the
			// composing text in the focused field with caret at the end;
			// the commit call finalizes it.
			extern char g_ime_compose_text[];
			extern char g_ime_commit_text[];
			extern int  g_ime_compose_pending;
			extern int  g_ime_commit_pending;
			extern void actionTextFieldImeCompose(SWFAppContext*, const char*, int, int);
			extern void actionTextFieldImeCommit(SWFAppContext*, const char*);
			if (g_ime_compose_pending) {
				g_ime_compose_pending = 0;
				int len = (int)strlen(g_ime_compose_text);
				actionTextFieldImeCompose(app_context, g_ime_compose_text, len, len);
			}
			if (g_ime_commit_pending) {
				g_ime_commit_pending = 0;
				actionTextFieldImeCommit(app_context, g_ime_commit_text);
			}

			// --- Focus highlight tick ---
			actionUpdateHighlightState();

			// --- Deferred roll-event flush ---
			// AS2 handlers fired above (e.g. Selection.setFocus from a Key
			// listener) can queue rollOver/rollOut events; drain them so they
			// fire before the next frame's events.
			actionFlushDeferredRollEvents(app_context);
		}

		app_context->mouse.clicked = 0;
		app_context->mouse.released = 0;
#endif

#ifdef OFFSCREEN_RENDER
		// Advance root-level sprites BEFORE root frame_func runs, mirroring
		// swf_core.c's two-phase order. Each sprite's frame_func queues its
		// script via actionQueueSpriteScript; the recompiler-emitted
		// actionDrainAllInPriorityOrder at the top of root frame_funcs[current_frame]
		// drains those scripts before the root's own DoAction. Without this
		// call, sprite frame_funcs (frame > 0) never run.
		{
			extern void advance_sprite_frames(SWFAppContext* app_context);
			extern int g_advance_defer_nested;
			g_advance_defer_nested = 1;
			advance_sprite_frames(app_context);
			g_advance_defer_nested = 0;
		}

		// Mark ENTER_FRAME dispatch pending. tagFlushPendingEnterFrame is
		// called by the recompiler-emitted code right before each DoAction
		// (after RemoveObject) and dispatches clip event ENTER_FRAME +
		// AS2 onEnterFrame handlers. Mirrors swf_core.c line ~985.
		{
			extern int g_enterframe_flush_pending;
			g_enterframe_flush_pending = 1;
		}
#endif

		if (current_frame < g_frame_count && frame_funcs[current_frame] != NULL
#ifdef OFFSCREEN_RENDER
		    && (is_playing || manual_next_frame)
#endif
		    )
		{
			frame_funcs[current_frame](app_context);
#ifdef OFFSCREEN_RENDER
			// If a goto inside the script inlined the target frame's body
			// AND the recompiler-emitted last-frame wrap-back fired
			// afterward (signature: next_frame=0; manual_next_frame=1),
			// undo the wrap-back so the natural advance moves to
			// current_frame+1 (gotoAndPlay) or stays in place
			// (gotoAndStop). Without this, gotoAndPlay/Stop from inside
			// the last frame's script loops back to 0. Mirrors swf_core.c
			// (line ~1013). swf.c's next_frame-based natural advance also
			// needs next_frame resynced to current_frame: the wrap-back set
			// next_frame=0, so the loop-bottom `next_frame += 1` would land
			// on frame 1 (re-running the target script) instead of
			// current_frame+1. Setting next_frame=current_frame turns the
			// natural advance into current_frame+1 (gotoAndPlay) or stay
			// (gotoAndStop, is_playing=0). Key test:
			// from_shumway/timeline/timeline_as2_1 — frame_4's script
			// gotoAndPlay(1) inlines script_1 via ng_executeGotoCatchUp,
			// the wrap-back then fires, and without the undo the timeline
			// loops to frame 0 instead of advancing to frame 2's
			// FSCommand:quit.
			if (g_goto_inlined_in_caller_frame)
			{
				extern int g_deferred_root_goto;
				g_goto_inlined_in_caller_frame = 0;
				if (manual_next_frame && next_frame == 0 && !g_deferred_root_goto) {
					manual_next_frame = 0;
					next_frame = current_frame;
				}
			}
#endif
		}

#ifdef OFFSCREEN_RENDER
		// Fallback flush: if frame_func didn't run (root stopped,
		// past-last-frame, ...), flush enter_frame here so clip event
		// ENTER_FRAME and onEnterFrame handlers still fire.
		{
			extern int g_enterframe_flush_pending;
			extern void tagFlushPendingEnterFrame(SWFAppContext*);
			if (g_enterframe_flush_pending)
				tagFlushPendingEnterFrame(app_context);
		}

		// Mark dynamic MCs (createEmptyMovieClip, etc. — no display_obj)
		// as eligible for the NEXT tick's enterFrame dispatch. Mirrors
		// swf_core.c line ~1100. Without this, MCs created by DoAction
		// scripts during this tick are never marked, so
		// actionDispatchEnterFrameHandlers skips them on subsequent
		// ticks (it checks mc_enterframe_eligible for MCs with NULL
		// display_obj). Symptom: create_empty_movie_clip's
		// mc2.onEnterFrame never fires from the main loop, was only
		// firing via the post-quit drain (and firing too many times
		// there). Key test: avm1/create_empty_movie_clip.
		{
			extern void actionMarkDynamicMCsEnterFrameEligible(void);
			actionMarkDynamicMCsEnterFrameEligible();
		}

		// Phase 3: advance nested sprite children (deferred from Phase 1
		// via g_advance_defer_nested above).
		{
			extern void advance_nested_sprite_frames(SWFAppContext* app_context);
			advance_nested_sprite_frames(app_context);
		}
		// Drain any sprite SCRIPT entries queued during advance_*_sprite_frames
		// that the recompiler-emitted in-frame drain didn't cover.
		actionDrainActionQueueByKind(app_context, AQ_KIND_SCRIPT);

		// Flush deferred rollOver/rollOut events from Selection.setFocus()
		// calls that occurred during frame scripts. These fire
		// asynchronously (after script completes) but before input events
		// are processed. Mirrors swf_core.c (line ~1105) / swf_headless.c
		// (line ~1062). input_events_pump_tick also flushes between
		// queued events, but tests with no input.json need this call to
		// drain rolls queued by frame-script Selection.setFocus.
		// Key test: avm1/selection_handlers — Selection.setFocus calls
		// from script_0 queue rollOver/rollOut on text/button/clip that
		// never fired without this.
		actionFlushDeferredRollEvents(app_context);

		// Drive file-driven test input (KEY_DOWN, MOUSE_MOVE, etc.) AFTER
		// frame scripts have set up their listeners. Mirrors swf_core.c's
		// placement (around line 1109). No-op when no event file is loaded.
		{
			extern void input_events_pump_tick(SWFAppContext* app_context);
			input_events_pump_tick(app_context);
		}

		// Goto catch-up: when a script-initiated goto (e.g. mc.gotoAndStop("/:N")
		// with a force_root path) called ng_executeGotoTagsOnly during this
		// tick, it left goto_from_action + manual_next_frame + g_deferred_root_goto
		// set so the main loop runs the target frame's scripts. Without this
		// block, manual_next_frame gets cleared at end-of-tick (line ~613) and
		// the next tick sees is_playing=0 (from gotoAndStop), so funcs[target]
		// never runs. Mirrors swf_core.c outer catch-up loop (line ~1195+).
		// Key test: avm1/goto_frame_number.
		{
			int _goto_retry_limit = 16;
			while (goto_from_action && manual_next_frame && _goto_retry_limit-- > 0)
			{
				size_t original_frame = current_frame;
				size_t target = next_frame;
				manual_next_frame = 0;
				goto_from_action = 0;

				ng_display_clear_after(app_context, target);

				catch_up_mode = 1;
				if (target <= original_frame)
				{
					actionRewindCleanup(app_context);
					catch_up_backward = 1;
					catch_up_target = target;
					for (size_t f = 0; f < target && f < g_frame_count; f++)
					{
						current_frame = f;
						if (frame_funcs[f]) frame_funcs[f](app_context);
					}
					catch_up_mode = 0;
					if (target < g_frame_count)
					{
						current_frame = target;
						if (frame_funcs[target]) frame_funcs[target](app_context);
					}
					catch_up_backward = 0;
					ng_display_cleanup_unplaced_after(app_context, target);
				}
				else
				{
					for (size_t f = original_frame + 1; f < target && f < g_frame_count; f++)
					{
						current_frame = f;
						if (frame_funcs[f]) frame_funcs[f](app_context);
					}
					catch_up_mode = 0;
					if (target < g_frame_count)
					{
						current_frame = target;
						if (frame_funcs[target]) frame_funcs[target](app_context);
					}
				}
				current_frame = target;
				g_deferred_root_goto = 0;
			}
		}

		// Process deferred failed-load state and direct loadMovie inits
		// queued by this tick's frame/sprite scripts. Mirrors swf_core.c
		// (lines ~1282-1300). Without actionFirePendingDirectLoads, a
		// loadMovie call from frame_0 never runs the child's init+frame0
		// — drops the "Child movie loaded!" trace line in loadmovie /
		// loadmovie_flashvars / loadmovie_method / loadmovie_registerclass
		// / loadmovie_replace_root / loadmovie_var_persistence and the
		// loadmovienum cluster. Also unblocks the "After load movie:"
		// tail of focusrect_property_swf{5,6,7}.
		{
			extern void actionProcessDeferredFailedLoads(void);
			extern void actionFirePendingDirectLoads(SWFAppContext*);
			extern int g_pending_direct_load_count;
			actionProcessDeferredFailedLoads();
			int dl_guard = 0;
			while (g_pending_direct_load_count > 0 && dl_guard++ < 32)
				actionFirePendingDirectLoads(app_context);
		}

		// Advance multi-frame _levelN loads (loadMovieNum into a level slot
		// not in display_list — advance_sprite_frames doesn't reach those).
		// Mirrors swf_core.c line ~1299.
		{
			extern void actionAdvancePlayingLevels(SWFAppContext*);
			actionAdvancePlayingLevels(app_context);
		}

		// Mirror swf_headless.c (line ~1208) / swf_core.c (line ~1309): fire
		// AS2 setInterval/setTimeout callbacks, LoadVars onData, and end-of-frame
		// hooks. Without processTimers, setInterval-driven callbacks never run
		// in graphics-native, so any test relying on them (Dejagnu's
		// setInterval(checkIt, ...) — every actionscript.all test) gets stuck
		// because the only checkIt invocation path left (onEnterFrame) bails
		// inside enterFrame dispatch via the g_inside_enterframe_dispatch guard
		// in actionGotoFrame.
		{
			extern void processTimers(SWFAppContext*, double);
			extern void processLoadVarsLoads(SWFAppContext*);
			extern void processSoundPlayback(SWFAppContext*, double);
			extern void processNetStreams(SWFAppContext*, double);
			extern void processLocalConnectionMessages(SWFAppContext*);
			extern void actionFlushPendingOnLoads(SWFAppContext*);
			double frame_duration_ms = (app_context->fps > 0) ? (1000.0 / app_context->fps) : 83.33;
			actionFlushPendingOnLoads(app_context);
			processTimers(app_context, frame_duration_ms);
			processLoadVarsLoads(app_context);
			processSoundPlayback(app_context, frame_duration_ms);
			processNetStreams(app_context, frame_duration_ms);
			processLocalConnectionMessages(app_context);
			actionFlushPendingOnLoads(app_context);
		}

		// Drain MCL pending loads queued during frame scripts / timers /
		// onLoadInit chains. Mirrors swf_core.c lines ~1336-1345.
		{
			extern void actionFirePendingLoadInits(SWFAppContext*);
			extern int g_pending_mcl_load_count_this_tick;
			int mcl_guard = 0;
			while (g_pending_mcl_load_count_this_tick > 0 && mcl_guard++ < 32)
				actionFirePendingLoadInits(app_context);
		}

		// Last-tick MCL drain: when this is the final tick (tick_count
		// reaches max_ticks), promote any _next_tick loads and drain so
		// listeners get to run. Mirrors swf_core.c lines ~1353-1358.
#ifdef MAX_FRAMES
		if (tick_count >= max_ticks)
		{
			extern void actionPromotePendingMCLLoads(SWFAppContext*);
			extern void actionFirePendingLoadInits(SWFAppContext*);
			extern int g_pending_mcl_load_count_this_tick;
			extern int g_pending_mcl_load_count_next_tick;
			if (g_pending_mcl_load_count_next_tick > 0) {
				actionPromotePendingMCLLoads(app_context);
				int mcl_guard = 0;
				while (g_pending_mcl_load_count_this_tick > 0 && mcl_guard++ < 32)
					actionFirePendingLoadInits(app_context);
			}
		}
#endif

		// Re-render after events so iteration captures reflect post-event
		// display state (Tab focus, button hover, etc.). Mirrors
		// swf_headless.c line ~1249.
		capture_tick_after_events(app_context);

		// Save captures whose tick has arrived (iteration matches; pending
		// fscommand). last_frame captures wait until end-of-loop. Mirrors
		// swf_headless.c line ~1267.
		capture_tick_post_frame();
#endif
		if (manual_next_frame)
		{
#ifdef OFFSCREEN_RENDER
			// Natural backward wrap (recompiler-emitted at end of last frame
			// when total frame count > 1): invalidate cached MCs and clear
			// display entries placed at frames > target so names placed only
			// at later frames don't bleed into the next loop's frame 0.
			// Mirrors swf_core.c (line ~1395). Goto-from-action wraps go
			// through ng_executeGotoCatchUp / the outer catch-up loop above,
			// which handle their own cleanup. Key test: avm1/default_names —
			// without this, the second-iteration auto-instance counter is
			// short by the number of stale-depth modifies that would have
			// been fresh placements.
			if (!goto_from_action && next_frame < current_frame)
			{
				extern void actionInvalidateCachedMovieClip(SWFAppContext*, const char*, int);
				for (size_t d = 1; d <= max_depth && d < 16384; d++)
				{
					if (display_list[d].char_id != 0 &&
					    display_list[d].placed_at_frame > next_frame &&
					    display_list[d].instance_name != NULL)
					{
						actionInvalidateCachedMovieClip(app_context,
						    display_list[d].instance_name, (int)d);
					}
				}
				ng_display_clear_after(app_context, next_frame);
				ng_display_cleanup_unplaced_after(app_context, next_frame);
			}
#endif
			// Goto/play command set next_frame directly
			manual_next_frame = 0;
		}
		else if (is_playing)
		{
			next_frame += 1;
			// Wrap around when reaching the end. SWFs loop by default in
			// real playback; but in test mode (OFFSCREEN_RENDER), the
			// recompiler emits its own natural-wrap as
			// `manual_next_frame=1; next_frame=0` at the end of the last
			// frame and pairs it with `quit_swf=1`. Auto-wrapping here on
			// top of that re-runs frame 0 every tick whenever something
			// else is keeping the loop alive (a playing child sprite,
			// pending MCL load, etc.), producing duplicated trace output
			// — the loadmovie_var_persistence cluster of failures.
#ifndef OFFSCREEN_RENDER
			if (next_frame >= g_frame_count)
				next_frame = 0;
#endif
		}
		// else: stopped — stay on current frame
		bad_poll |= renderer_poll(app_context);

		// After-tick hook (for test harness / display bridge)
		{
			typedef void (*AfterTickHandler)(SWFAppContext*, int);
			extern AfterTickHandler g_after_tick_handler;
			static int _tick_count = 0;
			_tick_count++;
			if (g_after_tick_handler)
				g_after_tick_handler(app_context, _tick_count);
		}

#ifdef __EMSCRIPTEN__
		double elapsed = emscripten_get_now() - frame_start;
		u32 sleep_ms = (elapsed < (double)frame_ms) ? (u32)((double)frame_ms - elapsed) : 0;
		emscripten_sleep(sleep_ms);
#endif
		quit_swf |= bad_poll;
	}

#ifdef OFFSCREEN_RENDER
frame_loop_exit:
	// Deactivate timeout longjmp (jmp_buf is stack-local, must not be used after return).
	actionSetTimeoutJmp(NULL);
#endif

	if (bad_poll)
	{
		return;
	}

#ifndef OFFSCREEN_RENDER
	// Post-quit drain loop: in browser/emscripten mode the SWF stays "alive"
	// after its timeline ends — onEnterFrame handlers and sprite timelines
	// keep firing until the user closes the window. renderer_poll returns
	// nonzero on window close.
	//
	// Skipped in OFFSCREEN_RENDER (test mode): swf_core.c has no equivalent
	// drain loop. The main loop's quit_swf gate already waits on all pending
	// work (sprites, timers, MCL loads, onEnterFrame handlers), and now that
	// actionMarkDynamicMCsEnterFrameEligible runs at each tick boundary,
	// dynamic-MC handlers fire from the main loop too. Running the drain
	// here on top caused duplicate onEnterFrame dispatches (e.g.
	// create_empty_movie_clip's mc2.onEnterFrame firing twice).
	while (!renderer_poll(app_context))
	{
#ifdef __EMSCRIPTEN__
		double frame_start2 = emscripten_get_now();
#endif
		// Set enterframe_eligible on all initialized sprites so
		// actionDispatchEnterFrameHandlers doesn't skip them.
		{
			extern void set_enterframe_eligible_recursive(DisplayObject*, size_t);
			set_enterframe_eligible_recursive(display_list, max_depth);
		}

		// Dispatch AS2 onEnterFrame handlers (child MCs + root dynamic_props)
		actionDispatchEnterFrameHandlers(app_context);
		// Dispatch root onEnterFrame from var_map (DefineFunction/SetVariable path)
		actionDispatchRootVarMapEnterFrame(app_context);

		tagShowFrame(app_context);
#ifdef __EMSCRIPTEN__
		double elapsed2 = emscripten_get_now() - frame_start2;
		u32 sleep_ms2 = (frame_ms > 0) ? frame_ms : 0;
		if (elapsed2 < (double)sleep_ms2)
			emscripten_sleep((u32)((double)sleep_ms2 - elapsed2));
		else
			emscripten_sleep(0);
#endif
	}
#endif
}

void swfStart(SWFAppContext* app_context)
{
	context = renderer_new();

	context->width = app_context->width;
	context->height = app_context->height;

	context->stage_to_ndc = app_context->stage_to_ndc;

	context->bitmap_count = app_context->bitmap_count;
	context->bitmap_highest_w = app_context->bitmap_highest_w;
	context->bitmap_highest_h = app_context->bitmap_highest_h;

	context->shape_data = app_context->shape_data;
	context->shape_data_size = app_context->shape_data_size;
	context->transform_data = app_context->transform_data;
	context->transform_data_size = app_context->transform_data_size;
	context->color_data = app_context->color_data;
	context->color_data_size = app_context->color_data_size;
	context->uninv_mat_data = app_context->uninv_mat_data;
	context->uninv_mat_data_size = app_context->uninv_mat_data_size;
	context->gradient_data = app_context->gradient_data;
	context->gradient_data_size = app_context->gradient_data_size;
	context->bitmap_data = app_context->bitmap_data;
	context->bitmap_data_size = app_context->bitmap_data_size;
	context->cxform_data = app_context->cxform_data;
	context->cxform_data_size = app_context->cxform_data_size;

	// Allocate stack into app_context (use system malloc, not heap - stack is allocated before heap_init)
	app_context->stack = (char*) malloc(INITIAL_STACK_SIZE);
	app_context->sp = INITIAL_SP;
	app_context->oldSP = 0;

	quit_swf = 0;
	bad_poll = 0;
	next_frame = 0;

	// Store frame info globally for ActionCall opcode
	g_frame_funcs = app_context->frame_funcs;
	g_frame_count = app_context->frame_count;

	initTime(app_context);
	initMap();

	// Initialize heap allocator (must be before renderer_init which uses HALLOC)
	if (!heap_init(app_context, 0)) {  // 0 = use default size (64 MB)
		fprintf(stderr, "Failed to initialize heap allocator\n");
		return;
	}

	// Allocate display state via HCALLOC so grow_ptr's HALLOC + FREE pair works.
	// Must use HCALLOC (heap allocator) so grow_ptr can FREE them without
	// passing a system-malloc'd pointer to heap_free. Mirrors swf_core.c
	// (line ~807) / swf_headless.c (line ~845). With system malloc here, the
	// first display_list/dictionary growth during execution called HALLOC for
	// the new buffer and FREE on the old malloc'd one, leaving an "invalid
	// pointer" entry that heap_shutdown traversal hits at exit — surfaces as
	// "SIGSEGV (output matches)" on any test that grows the display list.
	dictionary = HCALLOC(INITIAL_DICTIONARY_CAPACITY, sizeof(Character));
	display_list = HCALLOC(INITIAL_DISPLAYLIST_CAPACITY, sizeof(DisplayObject));
	if (!dictionary || !display_list) {
		fprintf(stderr, "Failed to allocate display state\n");
		return;
	}

	// audio_output_init MUST run before renderer_init so the Web Audio
	// AudioContext is created while the user gesture (click) is still active.
	// renderer_init calls emscripten_sleep() which consumes the gesture.
	audio_output_init(app_context);

	// Size the dynamic bitmap texture array large enough for any bundled
	// image the test may load via MovieClipLoader.loadClip("foo.png" / .gif /
	// .jpg). Defaults to 256×256 inside the renderer; bump up here when the
	// data registry reports a larger image (capped at 2048 to keep VRAM use
	// reasonable). The renderer preserves a pre-set value (see
	// create_buffers_and_upload in render_webgpu.c).
	{
		int max_w = 0, max_h = 0;
		getDataFilesMaxImageDims(&max_w, &max_h);
		if (max_w > 2048) max_w = 2048;
		if (max_h > 2048) max_h = 2048;
		if ((u32)max_w > context->dynamic_bitmap_max_w)
			context->dynamic_bitmap_max_w = (u32)max_w;
		if ((u32)max_h > context->dynamic_bitmap_max_h)
			context->dynamic_bitmap_max_h = (u32)max_h;
	}

	renderer_init(app_context, context);

#ifdef OFFSCREEN_RENDER
	// Parse CAPTURE_TRIGGERS / CAPTURE_OUTPUT_DIR env vars so the tick-loop
	// capture wrappers know which frames to save. Mirrors swf_headless.c.
	parse_capture_triggers();
#endif

#ifdef OFFSCREEN_RENDER
	// Initialize root display sentinel and set root_movieclip.display_obj.
	// Mirrors swf_core.c (line ~815) and swf_headless.c (line ~862). Without
	// this, root_movieclip.display_obj is NULL when actionImportAssets runs
	// from frame_0, and the imported SWF's init code that resolves through
	// _root or g_current_context misses the root sentinel. Key cluster:
	// from_gnash/actionscript.all (Dejagnu.swf-based tests).
	{
		extern void ng_sync_root_display_obj(void);
		extern void* ng_get_root_display_obj(void);
		extern MovieClip root_movieclip;
		ng_sync_root_display_obj();
		root_movieclip.display_obj = ng_get_root_display_obj();
	}

	// Set root url and byte_size from compile-time SWF metadata. Mirrors
	// swf_core.c (line ~821-827). Without these, root.getBytesLoaded() /
	// getBytesTotal() return 0 instead of the actual SWF size, and
	// _url / loadVariables-relative URL construction sees an empty base.
	// Key test: avm1/get_bytes_total.
#ifdef SWF_URL
	{
		extern MovieClip root_movieclip;
		strncpy(root_movieclip.url, SWF_URL, sizeof(root_movieclip.url) - 1);
		root_movieclip.url[sizeof(root_movieclip.url) - 1] = '\0';
	}
#endif
#ifdef SWF_FILE_SIZE
	{
		extern MovieClip root_movieclip;
		root_movieclip.byte_size = SWF_FILE_SIZE;
	}
#endif
#endif

	tagInit(app_context);

#ifdef OFFSCREEN_RENDER
	// Set root movieclip as default execution context (for 'this' resolution).
	// Mirrors swf_core.c / swf_headless.c. Without this g_current_context is
	// NULL when frame_0 runs, breaking actions that resolve through the
	// current MC (e.g., DefineFunction / SetVariable inside imported SWFs).
	{
		extern MovieClip root_movieclip;
		actionSetCurrentContext(&root_movieclip);
	}
#endif

	tagMain(app_context);

#ifdef OFFSCREEN_RENDER
	// Refresh the readback buffer with the final scene state before saving
	// last_frame captures. Without this, tests whose only meaningful state
	// change happens AFTER the last tagShowFrame (e.g. mc.loadMovie on a
	// single-frame SWF: tagShowFrame runs before actionFirePendingDirectLoads
	// attaches the decoded pixels, and no later tick re-renders) capture an
	// out-of-date snapshot. Key test: avm1/movieclip_methods_with_loaded_image.
	{
		extern void tagRerenderFrame(SWFAppContext* app_context);
		if (context != NULL && context->renderer_ok) {
			renderer_request_capture(context);
			tagRerenderFrame(app_context);
		}
	}
	// Save any unsaved last_frame captures from the readback buffer before
	// renderer teardown. Mirrors swf_headless.c line ~1332.
	capture_save_last_frame();
#endif

	audio_output_shutdown();
	audio_shutdown(app_context);

	renderer_free(app_context, context);

	heap_shutdown(app_context);
	freeMap();

	free(app_context->stack);
}

// Focus rect stub — wasm graphics only. action.c's widened arm provides
// the real impl in OFFSCREEN_RENDER (graphics-native).
#ifndef OFFSCREEN_RENDER
int actionGetFocusRectInfo(FocusRectInfo* out) {
	(void)out;
	return 0;
}
#endif

// Default findMovieEntry stub when no child movies are linked
#ifndef HAS_CHILD_MOVIES
MovieEntry* findMovieEntry(const char* filename) {
	(void)filename;
	return NULL;
}
#endif

// Default findDataFile stub when no data files are linked
#ifndef HAS_DATA_FILES
DataFileEntry* findDataFile(const char* filename) {
	(void)filename;
	return NULL;
}
void getDataFilesMaxImageDims(int* out_w, int* out_h) {
	if (out_w) *out_w = 0;
	if (out_h) *out_h = 0;
}
#endif

#endif // !NO_GRAPHICS && !HEADLESS_GRAPHICS