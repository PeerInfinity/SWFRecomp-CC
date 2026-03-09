#ifdef HEADLESS_GRAPHICS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <swf.h>
#include "constants.h"

// Frame rect offset — defaults to 0 for SWFs with origin at (0,0).
// Generated constants.h defines these for SWFs with translated frame rects.
#ifndef FRAME_X_MIN_TWIPS
#define FRAME_X_MIN_TWIPS 0
#endif
#ifndef FRAME_Y_MIN_TWIPS
#define FRAME_Y_MIN_TWIPS 0
#endif
#include <tag.h>
#include <action.h>
#include <variables.h>
#include <utils.h>
#include <heap.h>
#include <renderer.h>

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

// Renderer context (global, referenced by tag.c for rendering)
RenderContext* context;

// Goto catch-up state
int catch_up_mode = 0;
int goto_from_action = 0;
int catch_up_backward = 0;    // 1 if current catch-up is a backward goto
size_t catch_up_target = 0;   // target frame for backward goto protection
int g_deferred_goto_play = 0; // Set when gotoAndPlay targets root from inside a sprite
int g_deferred_root_goto = 0; // Set when GotoFrame targets root from inside a sprite — skip re-running current frame
int g_deferred_goto_script = 0;     // count of deferred scripts queued
size_t g_deferred_goto_target = 0;  // target frame whose script is deferred (last entry)
#define MAX_DEFERRED_GOTO_QUEUE 16
size_t g_deferred_goto_queue[MAX_DEFERRED_GOTO_QUEUE];
int g_deferred_goto_queue_count = 0;
int g_tag_skip_mode = 0;            // 1 = tag functions are no-ops (scripts-only re-run)

// Execute goto catch-up inline (called from actionGotoFrame)
// Processes intermediate frame tags and target frame tags immediately
void ng_executeGotoCatchUp(SWFAppContext* app_context)
{
	if (!goto_from_action || !manual_next_frame) return;

	// If called from inside a sprite init context, swap to root DL
	// so that root frame functions (PlaceObject2, RemoveObject2, etc.)
	// operate on the correct display list.
	DisplayObject* saved_sprite_dl = NULL;
	size_t saved_sprite_max = 0, saved_sprite_cap = 0;
	int swapped = ng_swapToRootDL(&saved_sprite_dl, &saved_sprite_max, &saved_sprite_cap);

	// Advance placement generation so goto target frame's placements
	// are distinguishable from the calling frame's placements.
	extern size_t g_place_gen;
	g_place_gen++;

	frame_func* funcs = g_frame_funcs;
	size_t original_frame = current_frame;
	size_t target = next_frame;

	ng_display_clear_after(app_context, target);

	// Process ALL frames (intermediate + target) with catch_up_mode=1
	// so only tags execute (PlaceObject, etc.) and scripts are suppressed.
	// The target frame's script will run later via the main loop's catch-up
	// after the calling script finishes.
	// Save/restore g_tag_skip_mode so nested gotos (from deferred scripts)
	// properly process tags.
	// Set g_defer_sprite_init so tagShowFrame defers process_sprite_needs_init:
	// sprite init scripts must fire AFTER the deferred parent-frame DoAction.
	int saved_tag_skip = g_tag_skip_mode;
	extern int g_defer_sprite_init;
	int saved_defer_sprite = g_defer_sprite_init;
	g_tag_skip_mode = 0;
	g_defer_sprite_init = 1;
	catch_up_mode = 1;
	if (target <= original_frame)
	{
#ifdef NO_GRAPHICS
		// Clean up dynamic MCs and reset swapped depths before backward replay
		{
			extern void actionRewindCleanup(SWFAppContext* app_context);
			actionRewindCleanup(app_context);
		}
#endif
		catch_up_backward = 1;
		catch_up_target = target;
		for (size_t f = 0; f <= target && f < g_frame_count; f++)
		{
			current_frame = f;
			if (funcs[f]) funcs[f](app_context);
		}
		catch_up_backward = 0;
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
	// Do NOT restore g_defer_sprite_init here — keep it set so that the
	// calling frame's tagShowFrame (which runs after this returns) also defers
	// sprite init. g_defer_sprite_init is cleared in the deferred-script loop
	// after ng_run_deferred_sprite_init completes.
	(void)saved_defer_sprite;
	current_frame = target;

	// Restore sprite DL if we swapped
	if (swapped)
		ng_restoreFromRootDL(saved_sprite_dl, saved_sprite_max, saved_sprite_cap);

	// Leave goto_from_action and manual_next_frame set so the main loop
	// will run the target frame's script after the calling script finishes.
	// But we need to clear them to avoid double-processing of tags.
	// Instead, set a flag for the main loop to run ONLY the target frame's script.
	goto_from_action = 0;
	manual_next_frame = 0;

	// Queue the target frame's script to run after the calling script returns.
	// Multiple gotos in the same script each queue their deferred script.
	extern int g_deferred_goto_script;
	extern size_t g_deferred_goto_target;
	if (g_deferred_goto_queue_count < MAX_DEFERRED_GOTO_QUEUE) {
		g_deferred_goto_queue[g_deferred_goto_queue_count++] = target;
	}
	g_deferred_goto_script = 1;
	g_deferred_goto_target = target;
}

// Execute goto tags-only: processes intermediate frame tags (PlaceObject,
// RemoveObject, etc.) immediately so that avm1_removed gets set synchronously,
// but does NOT queue deferred scripts or modify current_frame.
// The actual script execution and frame advancement is left to the main loop
// via goto_from_action / manual_next_frame / g_deferred_root_goto.
// Used when a root goto happens from a non-sprite-init context (regular frame
// script calling _root.nextFrame(), etc.) and we need synchronous removal but
// must avoid double-executing the target frame's script.
void ng_executeGotoTagsOnly(SWFAppContext* app_context)
{
	if (!goto_from_action || !manual_next_frame) return;

	// Advance placement generation
	extern size_t g_place_gen;
	g_place_gen++;

	frame_func* funcs = g_frame_funcs;
	size_t original_frame = current_frame;
	size_t target = next_frame;

	ng_display_clear_after(app_context, target);

	int saved_tag_skip = g_tag_skip_mode;
	extern int g_defer_sprite_init;
	int saved_defer_sprite = g_defer_sprite_init;
	g_tag_skip_mode = 0;
	g_defer_sprite_init = 1;
	catch_up_mode = 1;
	if (target <= original_frame)
	{
#ifdef NO_GRAPHICS
		{
			extern void actionRewindCleanup(SWFAppContext* app_context);
			actionRewindCleanup(app_context);
		}
#endif
		catch_up_backward = 1;
		catch_up_target = target;
		for (size_t f = 0; f <= target && f < g_frame_count; f++)
		{
			current_frame = f;
			if (funcs[f]) funcs[f](app_context);
		}
		catch_up_backward = 0;
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

	// Restore current_frame — the main loop manages frame advancement.
	// Leave goto_from_action and manual_next_frame set so the main loop's
	// catch-up path processes the target frame (scripts + sprite init).
	current_frame = original_frame;

	// Set deferred root goto so the main loop skips re-running the current
	// frame function and goes straight to goto catch-up.
	g_deferred_root_goto = 1;
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
    EV_MOUSE_DOWN_MIDDLE, EV_MOUSE_UP_MIDDLE,
    EV_MOUSE_WHEEL,
    EV_KEY_DOWN, EV_KEY_UP,
    EV_TEXT_INPUT,
    EV_TEXT_CONTROL,
    EV_FOCUS_GAINED, EV_FOCUS_LOST,
    EV_SET_CLIPBOARD_TEXT,
} InputEventType;

typedef struct {
    InputEventType type;
    float x, y;    // for mouse events (stage pixels)
    int code;      // for key events, text codepoint
    char ctrl[32]; // for TEXT_CONTROL
    char text[1024]; // for SET_CLIPBOARD_TEXT
} InputEvent;

static InputEvent* g_events = NULL;
static size_t g_event_count = 0;
static size_t g_event_pos = 0;
static int g_key_press_consumed = 0;  // Set when button keyPress handles KEY_DOWN; gates TEXT_INPUT

void input_events_load(const char* path)
{
    FILE* f = fopen(path, "r");
    if (!f) return;
    char line[1088];
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
        else if (strncmp(line, "MOUSE_DOWN_MIDDLE ", 18) == 0)
            { sscanf(line + 18, "%f %f", &ev.x, &ev.y); ev.type = EV_MOUSE_DOWN_MIDDLE; }
        else if (strncmp(line, "MOUSE_UP_MIDDLE ", 16) == 0)
            { sscanf(line + 16, "%f %f", &ev.x, &ev.y); ev.type = EV_MOUSE_UP_MIDDLE; }
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
        else if (strncmp(line, "SET_CLIPBOARD_TEXT", 18) == 0 && line[18] == ' ') {
            ev.type = EV_SET_CLIPBOARD_TEXT;
            // "SET_CLIPBOARD_TEXT " = 19 chars prefix; text starts at position 19
            strncpy(ev.text, line + 19, sizeof(ev.text) - 1);
            ev.text[sizeof(ev.text) - 1] = '\0';
            size_t tlen = strlen(ev.text);
            while (tlen > 0 && (ev.text[tlen-1] == '\n' || ev.text[tlen-1] == '\r'))
                ev.text[--tlen] = '\0';
        }
        else if (strncmp(line, "SET_CLIPBOARD_TEXT\n", 18) == 0
              || strncmp(line, "SET_CLIPBOARD_TEXT\r", 18) == 0
              || strcmp(line, "SET_CLIPBOARD_TEXT") == 0) {
            ev.type = EV_SET_CLIPBOARD_TEXT;
            ev.text[0] = '\0';
        }
        else continue;
        g_events[g_event_count++] = ev;
    }
    fclose(f);
}

static void input_events_deliver(SWFAppContext* app_context, InputEvent* ev)
{
    MouseState* ms = &app_context->mouse;
    switch (ev->type) {
    case EV_MOUSE_MOVE: {
        float new_sx = ev->x * 20.0f + FRAME_X_MIN_TWIPS;
        float new_sy = ev->y * 20.0f + FRAME_Y_MIN_TWIPS;
        int mouse_actually_moved = (new_sx != ms->stage_x || new_sy != ms->stage_y);
        ms->stage_x = new_sx;
        ms->stage_y = new_sy;
        ms->moved = 1;
        root_movieclip.xmouse = ev->x + (float)FRAME_X_MIN_TWIPS / 20.0f;
        root_movieclip.ymouse = ev->y + (float)FRAME_Y_MIN_TWIPS / 20.0f;
        // Update virtual drag position while dragging
        if (is_dragging) {
            g_drag_virt_x = ms->stage_x;
            g_drag_virt_y = ms->stage_y;
        }
        // Dispatch onClipEvent(mouseMove) to all clips
        dispatch_clip_event_flag(app_context, CLIP_EVENT_MOUSE_MOVE);
        // Broadcast Mouse.onMouseMove to Mouse listeners
        actionDispatchMouseMove(app_context);
        // Ruffle skips hover re-evaluation when mouse didn't move and
        // there's a hovered object (skip_mouse_hover = true). Mirror this
        // by only running button state + roll dispatch when mouse moved,
        // OR when there is no Tab virtual hover to protect.
        if (mouse_actually_moved || !actionHasVirtualHover()) {
            // End Tab virtual hover FIRST — fires rollOut (DoAction+AS2) on
            // the old Tab-hovered MC before ng_update_button_states fires
            // rollOver on the new mouse-hovered MC. This gives correct
            // per-object interleaving: old rollOut completes before new rollOver.
            if (mouse_actually_moved)
                actionEndVirtualHoverOnMouse(app_context);
            // Run per-event button state machine
            ng_update_button_states(app_context);
            // Dispatch AS2 roll/drag over/out events to dynamic MCs
            actionDispatchMCMouseMove(app_context);
        }
        // Global AS2 mc.onMouseMove dispatch to all sprite MCs
        actionDispatchMCMouseMoveGlobal(app_context);
        // Mouse move resets focus highlight (SWF<9 only; SWF9+ only left mouse down resets)
        actionResetHighlightForEvent(0); // 0=mouse_move
        break;
    }
    case EV_MOUSE_DOWN_LEFT:
        ms->stage_x = ev->x * 20.0f + FRAME_X_MIN_TWIPS;
        ms->stage_y = ev->y * 20.0f + FRAME_Y_MIN_TWIPS;
        ms->button_down = 1;
        ms->clicked = 1;
        // Key code 1 = VK_LBUTTON: toggle on mouse down
        app_context->keys.toggled[1] ^= 1;
        root_movieclip.xmouse = ev->x + (float)FRAME_X_MIN_TWIPS / 20.0f;
        root_movieclip.ymouse = ev->y + (float)FRAME_Y_MIN_TWIPS / 20.0f;
        // Dispatch onClipEvent(mouseDown) to all clips
        dispatch_clip_event_flag(app_context, CLIP_EVENT_MOUSE_DOWN);
        // Broadcast Mouse.onMouseDown to Mouse listeners
        actionDispatchMouseDown(app_context);
        // Global AS2 mc.onMouseDown dispatch to all sprite MCs
        actionDispatchMCMouseDown(app_context);
        // Mouse click focus acquisition (before press dispatch so focus traces precede onPress)
        actionMouseClickFocus(app_context);
        // Run per-event button state machine (processes OverUpToOverDown = press)
        ng_update_button_states(app_context);
        dispatch_clip_event_press(app_context);
        // Dispatch AS2 onPress to dynamic MCs
        actionDispatchMCPress(app_context);
        // Left mouse down always resets focus highlight (all SWF versions)
        actionResetHighlightForEvent(1); // 1=left_down
        // Clear Tab virtual hover
        actionClearVirtualHover();
        break;
    case EV_MOUSE_UP_LEFT:
        ms->stage_x = ev->x * 20.0f + FRAME_X_MIN_TWIPS;
        ms->stage_y = ev->y * 20.0f + FRAME_Y_MIN_TWIPS;
        ms->button_down = 0;
        ms->released = 1;
        root_movieclip.xmouse = ev->x + (float)FRAME_X_MIN_TWIPS / 20.0f;
        root_movieclip.ymouse = ev->y + (float)FRAME_Y_MIN_TWIPS / 20.0f;
        // Dispatch onClipEvent(mouseUp) to all clips
        dispatch_clip_event_flag(app_context, CLIP_EVENT_MOUSE_UP);
        // Broadcast Mouse.onMouseUp to Mouse listeners
        actionDispatchMouseUp(app_context);
        // Global AS2 mc.onMouseUp dispatch to all sprite MCs
        actionDispatchMCMouseUp(app_context);
        // Run per-event button state machine (processes OverDownToOverUp = release)
        ng_update_button_states(app_context);
        dispatch_clip_event_release(app_context);
        // Dispatch AS2 onRelease/onReleaseOutside to dynamic MCs
        actionDispatchMCRelease(app_context);
        // Mouse up (left) resets focus highlight (SWF<9 only)
        actionResetHighlightForEvent(2); // 2=left_up
        // Clear Tab virtual hover
        actionClearVirtualHover();
        break;
    case EV_MOUSE_DOWN_RIGHT:
        ms->stage_x = ev->x * 20.0f + FRAME_X_MIN_TWIPS;
        ms->stage_y = ev->y * 20.0f + FRAME_Y_MIN_TWIPS;
        root_movieclip.xmouse = ev->x + (float)FRAME_X_MIN_TWIPS / 20.0f;
        root_movieclip.ymouse = ev->y + (float)FRAME_Y_MIN_TWIPS / 20.0f;
        // Right mouse button = VK_RBUTTON = key code 2
        app_context->keys.down[2] = 1;
        app_context->keys.toggled[2] ^= 1;
        // Right click fires onClipEvent(mouseDown) but NOT button press
        dispatch_clip_event_flag(app_context, CLIP_EVENT_MOUSE_DOWN);
        actionDispatchMouseDown(app_context);
        actionDispatchMCMouseDown(app_context);
        // Right mouse down resets focus highlight (SWF<9 only)
        actionResetHighlightForEvent(3); // 3=right_down
        break;
    case EV_MOUSE_UP_RIGHT:
        ms->stage_x = ev->x * 20.0f + FRAME_X_MIN_TWIPS;
        ms->stage_y = ev->y * 20.0f + FRAME_Y_MIN_TWIPS;
        root_movieclip.xmouse = ev->x + (float)FRAME_X_MIN_TWIPS / 20.0f;
        root_movieclip.ymouse = ev->y + (float)FRAME_Y_MIN_TWIPS / 20.0f;
        app_context->keys.down[2] = 0;
        dispatch_clip_event_flag(app_context, CLIP_EVENT_MOUSE_UP);
        actionDispatchMouseUp(app_context);
        actionDispatchMCMouseUp(app_context);
        // Right mouse up resets focus highlight (SWF<9 only)
        actionResetHighlightForEvent(4); // 4=right_up
        break;
    case EV_MOUSE_DOWN_MIDDLE:
        ms->stage_x = ev->x * 20.0f + FRAME_X_MIN_TWIPS;
        ms->stage_y = ev->y * 20.0f + FRAME_Y_MIN_TWIPS;
        root_movieclip.xmouse = ev->x + (float)FRAME_X_MIN_TWIPS / 20.0f;
        root_movieclip.ymouse = ev->y + (float)FRAME_Y_MIN_TWIPS / 20.0f;
        // Middle mouse button = VK_MBUTTON = key code 4
        app_context->keys.down[4] = 1;
        app_context->keys.toggled[4] ^= 1;
        // Middle click fires onClipEvent(mouseDown) but NOT button press
        dispatch_clip_event_flag(app_context, CLIP_EVENT_MOUSE_DOWN);
        actionDispatchMouseDown(app_context);
        actionDispatchMCMouseDown(app_context);
        break;
    case EV_MOUSE_UP_MIDDLE:
        ms->stage_x = ev->x * 20.0f + FRAME_X_MIN_TWIPS;
        ms->stage_y = ev->y * 20.0f + FRAME_Y_MIN_TWIPS;
        root_movieclip.xmouse = ev->x + (float)FRAME_X_MIN_TWIPS / 20.0f;
        root_movieclip.ymouse = ev->y + (float)FRAME_Y_MIN_TWIPS / 20.0f;
        app_context->keys.down[4] = 0;
        dispatch_clip_event_flag(app_context, CLIP_EVENT_MOUSE_UP);
        actionDispatchMouseUp(app_context);
        actionDispatchMCMouseUp(app_context);
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
        // Dispatch onClipEvent(keyDown) to all clips
        dispatch_clip_event_flag(app_context, CLIP_EVENT_KEY_DOWN);
        // Dispatch onKeyDown to focused MC (fires before Key broadcast)
        actionDispatchKeyDownToFocused(app_context, ev->code);
        // Broadcast onKeyDown to Key listeners, then check button key conditions
        actionDispatchKeyDown(app_context);
        int key_press_handled = dispatch_button_key_actions(app_context, ev->code);
        g_key_press_consumed = key_press_handled;
        // Fire onPress/onRelease on focused MC for Enter/Space — but ONLY if
        // no button keyPress condition handled the event (Ruffle behavior).
        if (!key_press_handled)
            actionDispatchKeyPressToFocused(app_context, ev->code);
        // Tab key: advance focus — but ONLY if no keyPress condition handled it.
        if (!key_press_handled && ev->code == 9) {
            int shift_held = (app_context->keys.down[16] != 0);
            actionAdvanceTabFocus(app_context, shift_held);
        }
        break;
    case EV_KEY_UP:
        if (ev->code >= 0 && ev->code < 256)
            app_context->keys.down[ev->code] = 0;
        // Dispatch onClipEvent(keyUp) to all clips
        dispatch_clip_event_flag(app_context, CLIP_EVENT_KEY_UP);
        // Dispatch onKeyUp to focused MC
        actionDispatchKeyUpToFocused(app_context, ev->code);
        // Broadcast onKeyUp to Key listeners
        actionDispatchKeyUp(app_context);
        break;
    case EV_TEXT_INPUT:
        // If a button keyPress already consumed this key, suppress the text input
        if (g_key_press_consumed) {
            g_key_press_consumed = 0;
            break;
        }
        g_key_press_consumed = 0;
        actionTextFieldInput(app_context, ev->code);
        break;
    case EV_TEXT_CONTROL:
        if (strcmp(ev->ctrl, "Paste") == 0)
            actionTextControlPaste(app_context);
        else if (strcmp(ev->ctrl, "Copy") == 0)
            actionTextControlCopy(app_context);
        else if (strcmp(ev->ctrl, "Cut") == 0)
            actionTextControlCut(app_context);
        else if (strcmp(ev->ctrl, "SelectAll") == 0)
            actionTextControlSelectAll(app_context);
        else if (strcmp(ev->ctrl, "MoveRight") == 0)
            actionTextControlMoveRight(app_context);
        else if (strcmp(ev->ctrl, "MoveLeft") == 0)
            actionTextControlMoveLeft(app_context);
        else if (strcmp(ev->ctrl, "Enter") == 0)
            actionTextControlEnter(app_context);
        else if (strcmp(ev->ctrl, "Backspace") == 0)
            actionTextControlBackspace(app_context);
        break;
    case EV_SET_CLIPBOARD_TEXT:
        actionSetClipboardText(ev->text);
        break;
    case EV_FOCUS_LOST:
        // Window/tab lost focus: clear keyboard focus
        actionWindowFocusLost(app_context);
        break;
    case EV_FOCUS_GAINED:
        // Window/tab regained focus: no-op (focus is not auto-restored)
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
        // Flush deferred rollOver/rollOut events between each event delivery.
        // Selection.setFocus() called from event handlers (e.g., Key listener
        // doing programmatic focus cycling) queues rollOver/rollOut that must
        // fire before the next event (e.g., KeyUp) is processed.
        actionFlushDeferredRollEvents(app_context);
    }
}

// ---------------------------------------------------------------------------
// Frame Capture Scheduling (Phase 4)
// Reads CAPTURE_TRIGGERS env var to determine when to save rendered frames
// as PNG files. Format: "name:type[:value]" comma-separated.
//   name:last_frame          — save on last rendered frame before exit
//   name:iteration:N         — save on tick N (1-based)
//   name:fs_command           — save when fscommand("capture") fires
// Output directory comes from CAPTURE_OUTPUT_DIR env var (defaults to ".").
// ---------------------------------------------------------------------------

#define MAX_CAPTURES 16

typedef enum {
	CAPTURE_LAST_FRAME,
	CAPTURE_ITERATION,
	CAPTURE_FS_COMMAND,
} CaptureType;

typedef struct {
	char name[128];
	CaptureType type;
	int iteration;   // for CAPTURE_ITERATION
	int saved;        // 1 if already saved
} CaptureEntry;

static CaptureEntry g_captures[MAX_CAPTURES];
static int g_capture_count = 0;
static char g_capture_output_dir[512] = ".";
static int g_has_last_frame_capture = 0;
#ifdef HEADLESS_RENDER_ENABLED
// Track the next fs_command capture index
static int g_fscommand_capture_idx = 0;
#endif

static void parse_capture_triggers(void)
{
	const char* dir = getenv("CAPTURE_OUTPUT_DIR");
	if (dir) {
		strncpy(g_capture_output_dir, dir, sizeof(g_capture_output_dir) - 1);
		g_capture_output_dir[sizeof(g_capture_output_dir) - 1] = '\0';
	}

	const char* env = getenv("CAPTURE_TRIGGERS");
	if (!env || !*env) return;

	// Parse comma-separated entries
	char buf[4096];
	strncpy(buf, env, sizeof(buf) - 1);
	buf[sizeof(buf) - 1] = '\0';

	char* saveptr = NULL;
	for (char* token = strtok_r(buf, ",", &saveptr);
	     token && g_capture_count < MAX_CAPTURES;
	     token = strtok_r(NULL, ",", &saveptr))
	{
		CaptureEntry* e = &g_captures[g_capture_count];
		memset(e, 0, sizeof(*e));

		// Parse "name:type[:value]"
		char* colon1 = strchr(token, ':');
		if (!colon1) continue;
		size_t name_len = (size_t)(colon1 - token);
		if (name_len >= sizeof(e->name)) name_len = sizeof(e->name) - 1;
		memcpy(e->name, token, name_len);
		e->name[name_len] = '\0';

		char* type_str = colon1 + 1;
		if (strncmp(type_str, "last_frame", 10) == 0) {
			e->type = CAPTURE_LAST_FRAME;
			g_has_last_frame_capture = 1;
		} else if (strncmp(type_str, "iteration:", 10) == 0) {
			e->type = CAPTURE_ITERATION;
			e->iteration = atoi(type_str + 10);
		} else if (strncmp(type_str, "fs_command", 10) == 0) {
			e->type = CAPTURE_FS_COMMAND;
		} else {
			continue;
		}
		g_capture_count++;
	}
}

#ifdef HEADLESS_RENDER_ENABLED
static void save_capture(CaptureEntry* e)
{
	if (e->saved) return;
	char path[1024];
	snprintf(path, sizeof(path), "%s/%s.png", g_capture_output_dir, e->name);
	if (renderer_save_png(context, path))
		fprintf(stderr, "[capture] Saved %s\n", path);
	else
		fprintf(stderr, "[capture] Failed to save %s\n", path);
	e->saved = 1;
	// Clear capture_requested so we don't keep copying to readback buffer
	// unless another capture still needs it (e.g., last_frame keeps going)
	int still_need_capture = 0;
	for (int i = 0; i < g_capture_count; i++) {
		if (!g_captures[i].saved && (g_captures[i].type == CAPTURE_LAST_FRAME ||
		    g_captures[i].type == CAPTURE_FS_COMMAND))
			still_need_capture = 1;
	}
	if (!still_need_capture)
		context->capture_requested = 0;
}

// Index of the next fs_command capture to fire (-1 = none pending)
static int g_fscommand_pending = -1;

// Check if any captures remain unsaved for this tick (used by tagRerenderFrame).
int headless_has_pending_captures(void)
{
	for (int i = 0; i < g_capture_count; i++) {
		if (!g_captures[i].saved) return 1;
	}
	return 0;
}
#endif

// Called from actionFSCommand when fscommand("capture", ...) fires.
// This runs BEFORE tagShowFrame in the same tick (DoAction precedes ShowFrame),
// so requesting capture here means close_pass will copy to the readback buffer.
void headless_on_fscommand_capture(void)
{
#ifdef HEADLESS_RENDER_ENABLED
	if (!context || !context->renderer_ok) return;
	for (int i = g_fscommand_capture_idx; i < g_capture_count; i++) {
		if (g_captures[i].type == CAPTURE_FS_COMMAND && !g_captures[i].saved) {
			renderer_request_capture(context);
			g_fscommand_pending = i;
			g_fscommand_capture_idx = i + 1;
			return;
		}
	}
#endif
}

// Headless graphics swfStart implementation:
// Combines renderer initialization from swf.c with the sophisticated frame
// loop from swf_core.c.  Produces both trace output (stdout) and rendered
// frames (via tagShowFrame → renderer_open_pass/close_pass).
void swfStart(SWFAppContext* app_context)
{
	printf("=== SWF Execution Started (HEADLESS_GRAPHICS mode) ===\n");

	// Parse capture schedule before anything else
	parse_capture_triggers();

	// --- Renderer initialization (from swf.c) ---
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

	// --- Stack allocation ---
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

	// MCL pending load dispatch (used after processTimers and in exit conditions)
	extern void actionFirePendingLoadInits(SWFAppContext* app_context);
	extern int g_pending_mcl_load_count;

	initTime(app_context);
	initMap();

	// Initialize heap allocator (must be before renderer_init which uses HALLOC)
	if (!heap_init(app_context, 0)) {  // 0 = use default size (64 MB)
		fprintf(stderr, "Failed to initialize heap allocator\n");
		return;
	}

	// Allocate display state (dictionary/display_list are declared in tag_stubs.c)
	// Must use HCALLOC (heap allocator) so grow_ptr can FREE them without SIGABRT
	dictionary = HCALLOC(INITIAL_DICTIONARY_CAPACITY, sizeof(Character));
	display_list = HCALLOC(INITIAL_DISPLAYLIST_CAPACITY, sizeof(DisplayObject));
	if (!dictionary || !display_list) {
		fprintf(stderr, "Failed to allocate display state\n");
		return;
	}

	// Initialize renderer (no audio in headless mode)
	// Rendering is only needed for image comparison tests. For trace-only tests,
	// skip renderer_init entirely to avoid crashes on systems without GPU support.
	// The renderer_ok flag controls whether rendering calls in tag.c are no-ops.
#ifdef HEADLESS_RENDER_ENABLED
	renderer_init(app_context, context);
	if (!context->renderer_ok)
		fprintf(stderr, "Warning: rendering disabled, trace output only\n");
#endif

	// Initialize root display sentinel and set root_movieclip.display_obj
	extern void ng_sync_root_display_obj(void);
	extern void* ng_get_root_display_obj(void);
	ng_sync_root_display_obj();
	extern MovieClip root_movieclip;
	root_movieclip.display_obj = ng_get_root_display_obj();

#ifdef SWF_URL
	strncpy(root_movieclip.url, SWF_URL, sizeof(root_movieclip.url) - 1);
	root_movieclip.url[sizeof(root_movieclip.url) - 1] = '\0';
#endif
#ifdef SWF_FILE_SIZE
	root_movieclip.byte_size = SWF_FILE_SIZE;
#endif

	tagInit(app_context);

	// Set root movieclip as default execution context (for 'this' resolution)
	actionSetCurrentContext(&root_movieclip);

	// --- Frame loop (from swf_core.c) ---
	frame_func* funcs = app_context->frame_funcs;
	current_frame = 0;
#ifdef MAX_FRAMES
	const size_t max_ticks = MAX_FRAMES;
#else
	const size_t max_ticks = 10000;
#endif
	size_t tick_count = 0;

	// Continue until max_ticks. quit_swf prevents timeline looping but per-tick
	// handlers (onEnterFrame, sprite timelines, clip events) keep firing.
	while (tick_count < max_ticks)
	{
		tick_count++;

		// --- Capture scheduling: request capture before frame renders ---
#ifdef HEADLESS_RENDER_ENABLED
		if (context->renderer_ok) {
			int need_capture = 0;
			// last_frame: always request so readback buffer has latest frame
			if (g_has_last_frame_capture) need_capture = 1;
			// specific iteration: request on matching tick
			for (int ci = 0; ci < g_capture_count; ci++) {
				if (g_captures[ci].type == CAPTURE_ITERATION &&
				    g_captures[ci].iteration == (int)tick_count &&
				    !g_captures[ci].saved)
					need_capture = 1;
			}
			if (need_capture)
				renderer_request_capture(context);
		}
#endif

		// Process deferred unloadMovie state (MC properties change on next frame)
		extern void actionProcessDeferredUnloads(void);
		actionProcessDeferredUnloads();

		// Reset per-tick edge flags
		app_context->mouse.moved = 0;
		app_context->mouse.clicked = 0;
		app_context->mouse.released = 0;
		app_context->keys.last_key_down = -1;

		// Finalize MCs that were marked for pending removal in the previous frame.
		// They persisted for one frame (scripts could still access them); now invalidate.
		actionFinalizePendingRemovals(app_context);

		// Frame-first: advance sprites and run frame scripts before delivering events.
		// This ensures that listeners registered in frame scripts receive events from
		// the same tick (matching Flash/Ruffle's frame-then-event execution order).
		if (current_frame < g_frame_count)
		{
			// Two-phase sprite advancement matching Ruffle's execution order:
			// Phase 1: Advance root-level sprites (defer nested child recursion)
			// Phase 2: Run root frame script (EnterFrame flushes between RemoveObject & DoAction)
			// Phase 3: Advance nested children of sprites
			extern int g_advance_defer_nested;
			g_advance_defer_nested = 1;
			advance_sprite_frames(app_context);
			g_advance_defer_nested = 0;

			// Mark ENTER_FRAME dispatch as pending. The actual dispatch happens in
			// tagFlushPendingEnterFrame() which is called:
			//   1. By the recompiler-emitted code right before each DoAction (after RemoveObject)
			//   2. As fallback in tagShowFrame (for frames with no DoAction)
			// This ensures ENTER_FRAME fires after RemoveObject (skip removed clips)
			// but before DoAction (matching Flash's per-frame lifecycle ordering).
			{
				extern int g_enterframe_flush_pending;
				g_enterframe_flush_pending = 1;
			}

			// Run root frame function if the root timeline is playing
			if (is_playing || manual_next_frame)
			{
				// If a deferred root goto is pending (from a sprite script targeting root),
				// skip running funcs[current_frame] — go straight to goto catch-up.
				if (g_deferred_root_goto)
				{
				}
				else if (funcs[current_frame])
				{
					funcs[current_frame](app_context);
				}
				else
				{
					break;
				}
			}
			// Fallback: if root is stopped (no frame function ran), flush pending
			// ENTER_FRAME directly. Without this, dynamic MCs (createEmptyMovieClip)
			// with onEnterFrame handlers would never get dispatched while root is stopped.
			{
				extern int g_enterframe_flush_pending;
				if (g_enterframe_flush_pending)
					tagFlushPendingEnterFrame(app_context);
			}
			// Phase 3: advance nested sprite children (deferred from Phase 1)
			advance_nested_sprite_frames(app_context);
		}
		else
		{
			// Past the last frame: keep dispatching per-tick AS handlers
			// (onEnterFrame, sprite timelines, clip ENTER_FRAME events).
			// Break if quit_swf and no remaining input events, handlers, or playing sprites.
			if (quit_swf && !(g_events && g_event_pos < g_event_count)
			    && !actionHasEnterFrameHandlers()
			    && !hasPlayingSprites()
			    && !hasActiveTimers()
			    && !hasClipEnterFrameHandlers()) break;
			{
				extern int g_advance_defer_nested;
				g_advance_defer_nested = 1;
				advance_sprite_frames(app_context);
				g_advance_defer_nested = 0;
			}
			// Set enterframe_eligible for all initialized sprites (recursive into buttons)
			{
				extern void set_enterframe_eligible_recursive(DisplayObject*, size_t);
				set_enterframe_eligible_recursive(display_list, max_depth);
			}
			// Dispatch clip event ENTER_FRAME (recursive, children before parents)
			{
				extern MovieClip root_movieclip;
				extern void dispatch_enterframe_clip_actions(SWFAppContext*, DisplayObject*, size_t, MovieClip*);
				dispatch_enterframe_clip_actions(app_context, display_list, max_depth, &root_movieclip);
			}
			actionDispatchEnterFrameHandlers(app_context);
			actionDispatchRootVarMapEnterFrame(app_context);
			advance_nested_sprite_frames(app_context);
		}

		// Mark dynamic MCs (createEmptyMovieClip) as eligible for next tick's enterFrame.
		// Must happen every tick AFTER the frame function returns, so that MCs created
		// by DoAction scripts get marked even when the pre-DoAction tagFlushPendingEnterFrame
		// already consumed the dispatch for this tick.
		actionMarkDynamicMCsEnterFrameEligible();

		// Flush deferred rollOver/rollOut events from Selection.setFocus() calls
		// that occurred during frame scripts. These fire asynchronously (after script
		// completes) but before input events are processed.
		actionFlushDeferredRollEvents(app_context);

		// Deliver queued input events for this tick (after frame scripts ran)
		if (g_events) {
			input_events_pump_tick(app_context);
		}

		// Per-tick button state re-evaluation.
		// Catches _visible/_enabled changes from enterFrame/action scripts
		// that don't have an associated mouse event.
		// Skip when Tab virtual hover is active: Ruffle's update_mouse_state
		// uses skip_mouse_hover=true when hovered is Some and mouse didn't move,
		// so button states are NOT re-evaluated during frame ticks with virtual hover.
		if (!actionHasVirtualHover())
			ng_update_button_states(app_context);

		// Goto catch-up + deferred script processing.
		// An outer loop retries because deferred scripts (from ng_executeGotoCatchUp)
		// may trigger new gotos (via ng_executeGotoTagsOnly) that need catch-up.
		for (;;)
		{
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
#ifdef NO_GRAPHICS
				// Clean up dynamic MCs and reset swapped depths before replay
				{
					extern void actionRewindCleanup(SWFAppContext* app_context);
					actionRewindCleanup(app_context);
				}
#endif
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

			g_deferred_root_goto = 0;

			// After catch-up, the goto's advance is consumed; fall through
			// to the normal advance logic below.
		}

		// Run deferred goto scripts with Ruffle-compatible 3-phase ordering:
		//   Phase 1: Sprites placed BEFORE target frame → init before target DoAction
		//   Phase 2: Target frame DoAction runs
		//   Phase 3: Sprites placed ON/AFTER target frame → init after target DoAction
		// Multiple gotos in the same script queue multiple deferred entries.
		while (g_deferred_goto_queue_count > 0 || g_deferred_goto_script)
		{
			// Copy queue locally since executing deferred scripts may trigger more gotos
			size_t local_queue[MAX_DEFERRED_GOTO_QUEUE];
			int local_count = g_deferred_goto_queue_count;
			for (int qi = 0; qi < local_count; qi++)
				local_queue[qi] = g_deferred_goto_queue[qi];
			g_deferred_goto_queue_count = 0;
			g_deferred_goto_script = 0;

			extern int g_defer_sprite_init;
			extern void ng_run_deferred_sprite_init_before(SWFAppContext* app_context, size_t target_frame);
			extern void ng_run_deferred_sprite_init_on_or_after(SWFAppContext* app_context, size_t target_frame);

			for (int qi = 0; qi < local_count; qi++)
			{
				size_t target = local_queue[qi];

				// Phase 1: Init sprites placed in intermediate frames (before target)
				g_defer_sprite_init = 0;
				ng_run_deferred_sprite_init_before(app_context, target);

				// Phase 2: Run the target frame's script
				if (target < g_frame_count && funcs[target])
				{
					// Run the target frame function in "scripts-only" mode:
					// g_tag_skip_mode=1 causes tag functions to return immediately,
					// while catch_up_mode=0 allows script calls to execute.
					g_tag_skip_mode = 1;
					funcs[target](app_context);
					g_tag_skip_mode = 0;
					// If the script triggered another goto, it will be added
					// to the queue and processed in the next iteration.
				}

				// Phase 3: Init sprites placed on the target frame (after target DoAction)
				ng_run_deferred_sprite_init_on_or_after(app_context, target);
			}
		}

		// If deferred scripts triggered a new goto (via ng_executeGotoTagsOnly),
		// retry the catch-up loop to process it within this tick.
		if (goto_from_action && manual_next_frame) continue;
		break;
		} // end outer for(;;) retry loop

		// Process deferred failed loadMovie state (apply between frame scripts and timers)
		{
			extern void actionProcessDeferredFailedLoads(void);
			actionProcessDeferredFailedLoads();
		}

		// Process timers after frame actions + deferred scripts
		{
			double frame_duration_ms = (app_context->fps > 0) ? (1000.0 / app_context->fps) : 83.33;
			processTimers(app_context, frame_duration_ms);
		}

		// Dispatch any MCL loads queued by timer callbacks or chained from
		// onLoadInit handlers.  Loop because each dispatch may queue more loads.
		{
			int mcl_guard = 0;
			while (g_pending_mcl_load_count > 0 && mcl_guard++ < 32)
				actionFirePendingLoadInits(app_context);
		}

		// After-tick hook (for test harness / external interface injection)
		{
			typedef void (*AfterTickHandler)(SWFAppContext*, int);
			extern AfterTickHandler g_after_tick_handler;
			if (g_after_tick_handler)
				g_after_tick_handler(app_context, (int)tick_count);
		}

		// --- Re-render after events so captures reflect event-driven state changes ---
		// Events (Tab key, mouse) can change focus state, button states, etc.
		// Re-render so the next capture reflects the post-event display state.
#ifdef HEADLESS_RENDER_ENABLED
		if (context->renderer_ok) {
			int need_render = 0;
			for (int ci = 0; ci < g_capture_count; ci++) {
				CaptureEntry* e = &g_captures[ci];
				if (!e->saved && e->type == CAPTURE_ITERATION && e->iteration == (int)tick_count) {
					need_render = 1;
					break;
				}
			}
			if (need_render) {
				extern void tagRerenderFrame(SWFAppContext* app_context);
				tagRerenderFrame(app_context);
			}
		}
#endif

		// --- Save captures after this tick's tagShowFrame has rendered ---
#ifdef HEADLESS_RENDER_ENABLED
		if (context->renderer_ok) {
			for (int ci = 0; ci < g_capture_count; ci++) {
				CaptureEntry* e = &g_captures[ci];
				if (e->saved) continue;
				if (e->type == CAPTURE_ITERATION && e->iteration == (int)tick_count)
					save_capture(e);
			}
			// Save pending fs_command capture (requested before close_pass, now in readback buffer)
			if (g_fscommand_pending >= 0) {
				save_capture(&g_captures[g_fscommand_pending]);
				g_fscommand_pending = -1;
			}
		}
#endif

		// Advance to next frame
		// IMPORTANT: Process manual_next_frame BEFORE checking is_playing
		// This ensures that gotoFrame/gotoAndStop commands execute the target frame
		// even when they stop playback
		if (current_frame >= g_frame_count)
		{
			// Past the end of the frame list — only continue if events, timers, or handlers remain
			if (hasActiveTimers()) continue;
			if (g_events && g_event_pos < g_event_count) continue;
			if (actionHasEnterFrameHandlers() || hasPlayingSprites() || hasClipEnterFrameHandlers()) continue;
			if (g_pending_mcl_load_count > 0) continue;
			break;
		}
		else if (manual_next_frame)
		{
			current_frame = next_frame;
			manual_next_frame = 0;
			root_movieclip.currentframe = (int)current_frame + 1;  // Keep 1-indexed _currentframe in sync
		}
		else if (is_playing)
		{
			// Only advance naturally if we're still playing
			current_frame++;
			root_movieclip.currentframe = (int)current_frame + 1;  // Keep 1-indexed _currentframe in sync
		}
		else
		{
			// Root stopped — but child sprites may still be playing
			if (hasPlayingSprites())
			{
				// Stay at current_frame, sprites advance via advance_sprite_frames above
				continue;
			}
			// Root stopped but timers are active — keep ticking
			if (hasActiveTimers()) continue;
			// Root stopped but onEnterFrame handlers still registered — keep ticking
			if (actionHasEnterFrameHandlers() || hasClipEnterFrameHandlers()) continue;
			// Truly stopped — but continue if events remain
			if (g_events && g_event_pos < g_event_count) continue;
			break;
		}
	}

	// --- Save last_frame captures (readback buffer has the final rendered frame) ---
#ifdef HEADLESS_RENDER_ENABLED
	if (context->renderer_ok) {
		for (int ci = 0; ci < g_capture_count; ci++) {
			if (g_captures[ci].type == CAPTURE_LAST_FRAME && !g_captures[ci].saved)
				save_capture(&g_captures[ci]);
		}
	}
#endif

	printf("\n=== SWF Execution Completed ===\n");

	// Cleanup
	renderer_free(app_context, context);
	heap_shutdown(app_context);
	freeMap();
	free(app_context->stack);
}

#endif // HEADLESS_GRAPHICS
