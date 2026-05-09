#if !defined(NO_GRAPHICS) && !defined(HEADLESS_GRAPHICS)

#include <stdlib.h>
#include <string.h>
#include <swf.h>
#include <tag.h>
#include <action.h>
#include <object.h>
#include <variables.h>
#include <renderer.h>
#include <utils.h>
#include <heap.h>
#include <audio/audio.h>

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

// Frame execution state — needed by tag.c sprite advancement
int catch_up_mode = 0;
int g_tag_skip_mode = 0;

Character* dictionary = NULL;

DisplayObject* display_list = NULL;
size_t max_depth = 0;

// Dummy sprite object pointer — in graphics mode sprites are managed by the renderer.
// action.c saves/restores this during function calls, so it needs to exist.
DisplayObject* g_current_sprite_obj = NULL;

RenderContext* context;

void tagMain(SWFAppContext* app_context)
{
	frame_func* frame_funcs = app_context->frame_funcs;
	u32 frame_ms = app_context->fps > 0 ? 1000 / app_context->fps : 83;

	while (!quit_swf)
	{
#ifdef __EMSCRIPTEN__
		double frame_start = emscripten_get_now();
#endif
		// Flash clears the action stack at each frame boundary — see swf_core.c
		// for rationale. Key test: misc-swfc/stackscope.
		app_context->sp = INITIAL_SP;
		app_context->oldSP = 0;

		current_frame = next_frame;

		// Per-frame AS2 input dispatch.
		// In NO_GRAPHICS mode swf_core.c dispatches these per event; here we
		// dispatch per frame based on the flags + state set by render_webgpu.c's
		// callbacks. Runs BEFORE clearing the per-frame flags and BEFORE the
		// frame func so the transitions are visible to user scripts.
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
		if (current_frame < g_frame_count && frame_funcs[current_frame] != NULL)
		{
			frame_funcs[current_frame](app_context);
		}
		if (manual_next_frame)
		{
			// Goto/play command set next_frame directly
			manual_next_frame = 0;
		}
		else if (is_playing)
		{
			next_frame += 1;
			// Wrap around when reaching the end (Flash movies loop by default)
			if (next_frame >= g_frame_count)
				next_frame = 0;
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

	if (bad_poll)
	{
		return;
	}

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

	dictionary = malloc(INITIAL_DICTIONARY_CAPACITY*sizeof(Character));
	display_list = malloc(INITIAL_DISPLAYLIST_CAPACITY*sizeof(DisplayObject));

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

	// audio_output_init MUST run before renderer_init so the Web Audio
	// AudioContext is created while the user gesture (click) is still active.
	// renderer_init calls emscripten_sleep() which consumes the gesture.
	audio_output_init(app_context);

	renderer_init(app_context, context);

	tagInit(app_context);

	tagMain(app_context);

	audio_output_shutdown();
	audio_shutdown(app_context);

	renderer_free(app_context, context);

	heap_shutdown(app_context);
	freeMap();

	free(app_context->stack);

	free(dictionary);
	free(display_list);
}

// Focus rect stub — full implementation lives in action.c under #ifdef NO_GRAPHICS.
// Real impl depends on getDisplayEntryIdxForMC / getConcatMatrixForMC, which
// are still NO_GRAPHICS-only in action.c. Once those are un-gated this stub
// can be removed and the real actionGetFocusRectInfo will link.
int actionGetFocusRectInfo(FocusRectInfo* out) {
	(void)out;
	return 0;
}

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
#endif

#endif // !NO_GRAPHICS && !HEADLESS_GRAPHICS