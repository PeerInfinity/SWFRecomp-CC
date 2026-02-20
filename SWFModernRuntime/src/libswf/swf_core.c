#ifdef NO_GRAPHICS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <swf.h>
#include <tag.h>
#include <action.h>
#include <variables.h>
#include <utils.h>
#include <heap.h>

// Core runtime state - exported
int quit_swf = 0;
int is_playing = 1;
int bad_poll = 0;
size_t current_frame = 0;
size_t next_frame = 0;
int manual_next_frame = 0;
ActionVar* temp_val = NULL;

// Global frame access for ActionCall opcode
frame_func* g_frame_funcs = NULL;
size_t g_frame_count = 0;

// Drag state tracking
int is_dragging = 0;
char* dragged_target = NULL;
float g_drag_virt_x = 0.0f;   // virtual stage X of dragged clip (twips)
float g_drag_virt_y = 0.0f;   // virtual stage Y of dragged clip (twips)
char g_drag_target_name[256] = "";  // name of most-recently dragged clip (persists after stopDrag)

// Goto catch-up state
int catch_up_mode = 0;
int goto_from_action = 0;
int catch_up_backward = 0;    // 1 if current catch-up is a backward goto
size_t catch_up_target = 0;   // target frame for backward goto protection

// Execute goto catch-up inline (called from actionGotoFrame)
// Processes intermediate frame tags and target frame tags immediately
void ng_executeGotoCatchUp(SWFAppContext* app_context)
{
	if (!goto_from_action || !manual_next_frame) return;

	frame_func* funcs = g_frame_funcs;
	size_t original_frame = current_frame;
	size_t target = next_frame;
	manual_next_frame = 0;
	goto_from_action = 0;

	ng_display_clear_after(app_context, target);

	catch_up_mode = 1;
	if (target <= original_frame)
	{
		catch_up_backward = 1;
		catch_up_target = target;
		for (size_t f = 0; f < target && f < g_frame_count; f++)
		{
			current_frame = f;
			if (funcs[f]) funcs[f](app_context);
		}
		catch_up_mode = 0;
		if (target < g_frame_count)
		{
			current_frame = target;
			if (funcs[target]) funcs[target](app_context);
		}
		catch_up_backward = 0;
	}
	else
	{
		for (size_t f = original_frame + 1; f < target && f < g_frame_count; f++)
		{
			current_frame = f;
			if (funcs[f]) funcs[f](app_context);
		}
		catch_up_mode = 0;
		if (target < g_frame_count)
		{
			current_frame = target;
			if (funcs[target]) funcs[target](app_context);
		}
	}
	current_frame = target;
}

// ---------------------------------------------------------------------------
// Input Event Pump (Phase 3)
// Loads a pre-processed event file and delivers events at tick boundaries.
// ---------------------------------------------------------------------------

typedef enum {
    EV_WAIT,
    EV_MOUSE_MOVE,
    EV_MOUSE_DOWN_LEFT,  EV_MOUSE_UP_LEFT,
    EV_MOUSE_DOWN_RIGHT, EV_MOUSE_UP_RIGHT,
    EV_MOUSE_WHEEL,
    EV_KEY_DOWN, EV_KEY_UP,
    EV_TEXT_INPUT,
    EV_TEXT_CONTROL,
    EV_FOCUS_GAINED, EV_FOCUS_LOST,
} InputEventType;

typedef struct {
    InputEventType type;
    float x, y;    // for mouse events (stage pixels)
    int code;      // for key events, text codepoint
    char ctrl[32]; // for TEXT_CONTROL
} InputEvent;

static InputEvent* g_events = NULL;
static size_t g_event_count = 0;
static size_t g_event_pos = 0;

void input_events_load(const char* path)
{
    FILE* f = fopen(path, "r");
    if (!f) return;
    char line[256];
    size_t count = 0;
    while (fgets(line, sizeof(line), f)) count++;
    rewind(f);
    g_events = malloc(count * sizeof(InputEvent));
    if (!g_events) { fclose(f); return; }
    g_event_count = 0;
    while (fgets(line, sizeof(line), f)) {
        InputEvent ev = {0};
        if (strncmp(line, "WAIT", 4) == 0)
            ev.type = EV_WAIT;
        else if (strncmp(line, "MOUSE_MOVE ", 11) == 0)
            { sscanf(line + 11, "%f %f", &ev.x, &ev.y); ev.type = EV_MOUSE_MOVE; }
        else if (strncmp(line, "MOUSE_DOWN_LEFT ", 16) == 0)
            { sscanf(line + 16, "%f %f", &ev.x, &ev.y); ev.type = EV_MOUSE_DOWN_LEFT; }
        else if (strncmp(line, "MOUSE_UP_LEFT ", 14) == 0)
            { sscanf(line + 14, "%f %f", &ev.x, &ev.y); ev.type = EV_MOUSE_UP_LEFT; }
        else if (strncmp(line, "MOUSE_DOWN_RIGHT ", 17) == 0)
            { sscanf(line + 17, "%f %f", &ev.x, &ev.y); ev.type = EV_MOUSE_DOWN_RIGHT; }
        else if (strncmp(line, "MOUSE_UP_RIGHT ", 15) == 0)
            { sscanf(line + 15, "%f %f", &ev.x, &ev.y); ev.type = EV_MOUSE_UP_RIGHT; }
        else if (strncmp(line, "MOUSE_WHEEL ", 12) == 0)
            { sscanf(line + 12, "%d", &ev.code); ev.type = EV_MOUSE_WHEEL; }
        else if (strncmp(line, "KEY_DOWN ", 9) == 0)
            { sscanf(line + 9, "%d", &ev.code); ev.type = EV_KEY_DOWN; }
        else if (strncmp(line, "KEY_UP ", 7) == 0)
            { sscanf(line + 7, "%d", &ev.code); ev.type = EV_KEY_UP; }
        else if (strncmp(line, "TEXT_INPUT ", 11) == 0)
            { sscanf(line + 11, "%d", &ev.code); ev.type = EV_TEXT_INPUT; }
        else if (strncmp(line, "TEXT_CONTROL ", 13) == 0)
            { sscanf(line + 13, "%31s", ev.ctrl); ev.type = EV_TEXT_CONTROL; }
        else if (strncmp(line, "FOCUSGAINED", 11) == 0)
            ev.type = EV_FOCUS_GAINED;
        else if (strncmp(line, "FOCUSLOST", 9) == 0)
            ev.type = EV_FOCUS_LOST;
        else continue;
        g_events[g_event_count++] = ev;
    }
    fclose(f);
}

static void input_events_deliver(SWFAppContext* app_context, InputEvent* ev)
{
    MouseState* ms = &app_context->mouse;
    switch (ev->type) {
    case EV_MOUSE_MOVE:
        ms->stage_x = ev->x * 20.0f;
        ms->stage_y = ev->y * 20.0f;
        ms->moved = 1;
        root_movieclip.xmouse = ev->x;
        root_movieclip.ymouse = ev->y;
        // Update virtual drag position while dragging
        if (is_dragging) {
            g_drag_virt_x = ms->stage_x;
            g_drag_virt_y = ms->stage_y;
        }
        // Dispatch AS2 roll/drag over/out events to dynamic MCs
        actionDispatchMCMouseMove(app_context);
        break;
    case EV_MOUSE_DOWN_LEFT:
        ms->stage_x = ev->x * 20.0f;
        ms->stage_y = ev->y * 20.0f;
        ms->button_down = 1;
        ms->clicked = 1;
        // Key code 1 = VK_LBUTTON: toggle on mouse down
        app_context->keys.toggled[1] ^= 1;
        root_movieclip.xmouse = ev->x;
        root_movieclip.ymouse = ev->y;
        dispatch_clip_event_press(app_context);
        // Dispatch AS2 onPress to dynamic MCs
        actionDispatchMCPress(app_context);
        break;
    case EV_MOUSE_UP_LEFT:
        ms->stage_x = ev->x * 20.0f;
        ms->stage_y = ev->y * 20.0f;
        ms->button_down = 0;
        ms->released = 1;
        root_movieclip.xmouse = ev->x;
        root_movieclip.ymouse = ev->y;
        dispatch_clip_event_release(app_context);
        // Dispatch AS2 onRelease/onReleaseOutside to dynamic MCs
        actionDispatchMCRelease(app_context);
        break;
    case EV_KEY_DOWN:
        if (ev->code >= 0 && ev->code < 256) {
            app_context->keys.down[ev->code] = 1;
            // Toggle state for all keys on key-down (isToggled tracks press count parity)
            app_context->keys.toggled[ev->code] ^= 1;
        }
        app_context->keys.last_key_down = ev->code;
        // ASCII value: printable ASCII range (32-126)
        app_context->keys.last_key_ascii = (ev->code >= 32 && ev->code <= 126) ? ev->code : 0;
        // Broadcast onKeyDown to Key listeners, then check button key conditions
        actionDispatchKeyDown(app_context);
        dispatch_button_key_actions(app_context, ev->code);
        // Tab key: advance focus after broadcasting Key event
        // Shift+Tab (key 16 held) = reverse direction
        if (ev->code == 9) {
            int shift_held = (app_context->keys.down[16] != 0);
            actionAdvanceTabFocus(app_context, shift_held);
        }
        break;
    case EV_KEY_UP:
        if (ev->code >= 0 && ev->code < 256)
            app_context->keys.down[ev->code] = 0;
        // Broadcast onKeyUp to Key listeners
        actionDispatchKeyUp(app_context);
        break;
    default:
        break;
    }
}

static void input_events_pump_tick(SWFAppContext* app_context)
{
    while (g_event_pos < g_event_count) {
        InputEvent* ev = &g_events[g_event_pos];
        if (ev->type == EV_WAIT) {
            g_event_pos++;
            return;
        }
        input_events_deliver(app_context, ev);
        g_event_pos++;
    }
}

// Console-only swfStart implementation
void swfStart(SWFAppContext* app_context)
{
	printf("=== SWF Execution Started (NO_GRAPHICS mode) ===\n");

	// Allocate stack into app_context (use system malloc, not heap - stack is allocated before heap_init)
	app_context->stack = (char*) malloc(INITIAL_STACK_SIZE);
	if (!app_context->stack) {
		fprintf(stderr, "Failed to allocate stack\n");
		return;
	}
	app_context->sp = INITIAL_SP;
	app_context->oldSP = 0;

	// Initialize subsystems
	quit_swf = 0;
	is_playing = 1;
	bad_poll = 0;
	current_frame = 0;
	next_frame = 0;
	manual_next_frame = 0;

	// Store frame info globally for ActionCall opcode
	g_frame_funcs = app_context->frame_funcs;
	g_frame_count = app_context->frame_count;

	initTime(app_context);
	initMap();

	// Initialize heap allocator
	if (!heap_init(app_context, 0)) {  // 0 = use default size (64 MB)
		fprintf(stderr, "Failed to initialize heap allocator\n");
		return;
	}

	// Allocate display state (in GRAPHICS mode these come from swf.c)
	// Must use HCALLOC (heap allocator) so grow_ptr can FREE them without SIGABRT
	dictionary = HCALLOC(INITIAL_DICTIONARY_CAPACITY, sizeof(Character));
	display_list = HCALLOC(INITIAL_DISPLAYLIST_CAPACITY, sizeof(DisplayObject));
	if (!dictionary || !display_list) {
		fprintf(stderr, "Failed to allocate display state\n");
		return;
	}

	tagInit(app_context);

	// Run frames in console mode
	frame_func* funcs = app_context->frame_funcs;
	current_frame = 0;
#ifdef MAX_FRAMES
	const size_t max_ticks = MAX_FRAMES;
#else
	const size_t max_ticks = 10000;
#endif
	size_t tick_count = 0;

	// Continue as long as quit_swf is clear, OR there are still input events to deliver
	// (allows single-frame SWFs with quit_swf=1 to still process multi-tick input files).
	while ((!quit_swf || (g_events && g_event_pos < g_event_count)) && tick_count < max_ticks)
	{
		tick_count++;

		// Reset per-tick edge flags
		app_context->mouse.moved = 0;
		app_context->mouse.clicked = 0;
		app_context->mouse.released = 0;
		app_context->keys.last_key_down = -1;

		// Frame-first: advance sprites and run frame scripts before delivering events.
		// This ensures that listeners registered in frame scripts receive events from
		// the same tick (matching Flash/Ruffle's frame-then-event execution order).
		if (current_frame < g_frame_count)
		{
			printf("[Frame %zu]\n", current_frame);
			// Advance child sprite timelines BEFORE running frame tags/scripts
			// (Flash executes child frame advancement before parent DoAction)
			advance_sprite_frames(app_context);
			// Only run the root frame function if the root timeline is playing
			if (is_playing || manual_next_frame)
			{
				if (funcs[current_frame])
				{
					funcs[current_frame](app_context);
				}
				else
				{
					printf("No function for frame %zu, stopping.\n", current_frame);
					break;
				}
			}
		}

		// Deliver queued input events for this tick (after frame scripts ran)
		if (g_events) {
			input_events_pump_tick(app_context);
		}

		// Goto catch-up: when an action (GotoFrame, GoToLabel, etc.) triggered
		// a goto, process intermediate frame tags inline to match Flash's behavior.
		// Flash processes PlaceObject/RemoveObject for intermediate frames within
		// the same frame advance, but skips DoAction tags (main timeline scripts).
		// In our model, catch_up_mode=1 causes generated frame functions to skip
		// their script_N() calls while still executing tag functions.
		while (goto_from_action && manual_next_frame)
		{
			size_t original_frame = current_frame;
			size_t target = next_frame;
			manual_next_frame = 0;
			goto_from_action = 0;

			// Remove display list entries placed after the target frame
			ng_display_clear_after(app_context, target);

			catch_up_mode = 1;
			if (target <= original_frame)
			{
				// Backward goto: replay tags from frame 0 to target.
				// Intermediate frames (0..target-1) suppress scripts.
				// Target frame runs normally (scripts included).
				// Backward protection stays on through target frame so
				// RemoveObject2 doesn't remove entries placed during rebuild.
				catch_up_backward = 1;
				catch_up_target = target;
				for (size_t f = 0; f < target && f < g_frame_count; f++)
				{
					current_frame = f;
					if (funcs[f]) funcs[f](app_context);
				}
				catch_up_mode = 0;
				// Execute target frame with scripts enabled but
				// backward protection still active
				if (target < g_frame_count)
				{
					current_frame = target;
					if (funcs[target]) funcs[target](app_context);
				}
				catch_up_backward = 0;
			}
			else
			{
				// Forward goto: process intermediate frames (current+1..target-1)
				// with scripts suppressed, then target frame normally.
				for (size_t f = original_frame + 1; f < target && f < g_frame_count; f++)
				{
					current_frame = f;
					if (funcs[f]) funcs[f](app_context);
				}
				catch_up_mode = 0;
				// Execute target frame with scripts enabled
				if (target < g_frame_count)
				{
					current_frame = target;
					if (funcs[target]) funcs[target](app_context);
				}
			}
			current_frame = target;

			// After catch-up, the goto's advance is consumed; fall through
			// to the normal advance logic below.
		}

		// Advance to next frame
		// IMPORTANT: Process manual_next_frame BEFORE checking is_playing
		// This ensures that gotoFrame/gotoAndStop commands execute the target frame
		// even when they stop playback
		if (current_frame >= g_frame_count)
		{
			// Past the end of the frame list — only continue if events remain
			if (!g_events || g_event_pos >= g_event_count) break;
			// Otherwise loop with current_frame staying OOB; events were already pumped above
		}
		else if (manual_next_frame)
		{
			current_frame = next_frame;
			manual_next_frame = 0;
		}
		else if (is_playing)
		{
			// Only advance naturally if we're still playing
			current_frame++;
		}
		else
		{
			// Root stopped — but child sprites may still be playing
			if (hasPlayingSprites())
			{
				// Stay at current_frame, sprites advance via advance_sprite_frames above
				continue;
			}
			// Truly stopped — but continue if events remain
			if (g_events && g_event_pos < g_event_count) continue;
			break;
		}
	}

	printf("\n=== SWF Execution Completed ===\n");

	// Cleanup (dictionary/display_list freed by heap_shutdown; stack uses system malloc)
	heap_shutdown(app_context);
	freeMap();
	free(app_context->stack);
}

#endif // NO_GRAPHICS
