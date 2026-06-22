// Input event pump (Phase 3 / Phase 2-graphics-native)
//
// Loads a pre-processed event file written by verify_output.py's
// preprocess_input_json and delivers events at tick boundaries to the
// SWF runtime. Lives in a shared file so all three frame loops use the
// same impl: NO_GRAPHICS swf_core.c, HEADLESS swf_headless.c, and
// graphics-native swf.c (Phase 2 of graphics-native-test-mode-plan.md).
// Phase 3 retires swf_headless.c and the duplication that made this
// extraction necessary.
//
// Compiled in any mode that needs file-driven input events. Currently
// gated on the presence of a frame loop that calls input_events_pump_tick.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <swf.h>
#include <action.h>
#include "constants.h"

#ifndef FRAME_X_MIN_TWIPS
#define FRAME_X_MIN_TWIPS 0
#endif
#ifndef FRAME_Y_MIN_TWIPS
#define FRAME_Y_MIN_TWIPS 0
#endif

extern int is_dragging;
extern float g_drag_virt_x;
extern float g_drag_virt_y;
extern MovieClip root_movieclip;

extern void dispatch_clip_event_flag(SWFAppContext*, int);
extern void dispatch_clip_event_roll(SWFAppContext*);
extern void dispatch_clip_event_press(SWFAppContext*);
extern void dispatch_clip_event_release(SWFAppContext*);
extern void ng_update_button_states(SWFAppContext*);
extern int  dispatch_button_key_actions(SWFAppContext*, int code);

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
    EV_IME_PREEDIT,
    EV_IME_COMMIT,
} InputEventType;

typedef struct {
    InputEventType type;
    float x, y;    // for mouse events (stage pixels)
    int code;      // for key events, text codepoint
    char ctrl[32]; // for TEXT_CONTROL
    char text[1024]; // for SET_CLIPBOARD_TEXT
} InputEvent;

InputEvent* g_events = NULL;
size_t g_event_count = 0;
size_t g_event_pos = 0;
static int g_key_press_consumed = 0;

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
        else if (strncmp(line, "IME_PREEDIT ", 12) == 0) {
            ev.type = EV_IME_PREEDIT;
            int cf = -1, ct = -1;
            int n = 0;
            sscanf(line + 12, "%d %d %n", &cf, &ct, &n);
            ev.code = cf;
            ev.x = (float)ct;
            if (n > 0 && line[12 + n] != '\0') {
                strncpy(ev.text, line + 12 + n, sizeof(ev.text) - 1);
                ev.text[sizeof(ev.text) - 1] = '\0';
                size_t tl = strlen(ev.text);
                while (tl > 0 && (ev.text[tl-1] == '\n' || ev.text[tl-1] == '\r'))
                    ev.text[--tl] = '\0';
            } else {
                ev.text[0] = '\0';
            }
        }
        else if (strncmp(line, "IME_COMMIT ", 11) == 0) {
            ev.type = EV_IME_COMMIT;
            strncpy(ev.text, line + 11, sizeof(ev.text) - 1);
            ev.text[sizeof(ev.text) - 1] = '\0';
            size_t tl = strlen(ev.text);
            while (tl > 0 && (ev.text[tl-1] == '\n' || ev.text[tl-1] == '\r'))
                ev.text[--tl] = '\0';
        }
        else if (strncmp(line, "SET_CLIPBOARD_TEXT", 18) == 0 && line[18] == ' ') {
            ev.type = EV_SET_CLIPBOARD_TEXT;
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
        if (is_dragging) {
            g_drag_virt_x = ms->stage_x;
            g_drag_virt_y = ms->stage_y;
        }
        if (ms->button_down) {
            extern void actionTextFieldDragSelect(SWFAppContext* app_context);
            actionTextFieldDragSelect(app_context);
        }
        dispatch_clip_event_flag(app_context, CLIP_EVENT_MOUSE_MOVE);
        dispatch_clip_event_roll(app_context);
        actionDispatchMouseMove(app_context);
        if (mouse_actually_moved || !actionHasVirtualHover()) {
            if (mouse_actually_moved)
                actionEndVirtualHoverOnMouse(app_context);
            ng_update_button_states(app_context);
            actionDispatchMCMouseMove(app_context);
        }
        actionDispatchMCMouseMoveGlobal(app_context);
        actionResetHighlightForEvent(0);
        break;
    }
    case EV_MOUSE_DOWN_LEFT:
        ms->stage_x = ev->x * 20.0f + FRAME_X_MIN_TWIPS;
        ms->stage_y = ev->y * 20.0f + FRAME_Y_MIN_TWIPS;
        ms->button_down = 1;
        ms->clicked = 1;
        app_context->keys.toggled[1] ^= 1;
        root_movieclip.xmouse = ev->x + (float)FRAME_X_MIN_TWIPS / 20.0f;
        root_movieclip.ymouse = ev->y + (float)FRAME_Y_MIN_TWIPS / 20.0f;
        dispatch_clip_event_flag(app_context, CLIP_EVENT_MOUSE_DOWN);
        actionDispatchMouseDown(app_context);
        actionDispatchMCMouseDown(app_context);
        actionMouseClickFocus(app_context);
        ng_update_button_states(app_context);
        dispatch_clip_event_press(app_context);
        dispatch_clip_event_roll(app_context);
        actionDispatchMCPress(app_context);
        actionResetHighlightForEvent(1);
        actionClearVirtualHover();
        break;
    case EV_MOUSE_UP_LEFT:
        ms->stage_x = ev->x * 20.0f + FRAME_X_MIN_TWIPS;
        ms->stage_y = ev->y * 20.0f + FRAME_Y_MIN_TWIPS;
        ms->button_down = 0;
        ms->released = 1;
        { extern void actionTextFieldDragEnd(SWFAppContext*); actionTextFieldDragEnd(app_context); }
        root_movieclip.xmouse = ev->x + (float)FRAME_X_MIN_TWIPS / 20.0f;
        root_movieclip.ymouse = ev->y + (float)FRAME_Y_MIN_TWIPS / 20.0f;
        dispatch_clip_event_flag(app_context, CLIP_EVENT_MOUSE_UP);
        actionDispatchMouseUp(app_context);
        actionDispatchMCMouseUp(app_context);
        ng_update_button_states(app_context);
        dispatch_clip_event_release(app_context);
        dispatch_clip_event_roll(app_context);
        actionDispatchMCRelease(app_context);
        actionResetHighlightForEvent(2);
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
        app_context->keys.down[4] = 1;
        app_context->keys.toggled[4] ^= 1;
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
    case EV_KEY_DOWN: {
        if (ev->code >= 0 && ev->code < 256) {
            app_context->keys.down[ev->code] = 1;
            app_context->keys.toggled[ev->code] ^= 1;
        }
        app_context->keys.last_key_down = ev->code;
        app_context->keys.last_key_ascii = (ev->code >= 32 && ev->code <= 126) ? ev->code : 0;
        dispatch_clip_event_flag(app_context, CLIP_EVENT_KEY_DOWN);
        actionDispatchKeyDownToFocused(app_context, ev->code);
        actionDispatchKeyDown(app_context);

        int is_letter_key = (ev->code >= 65 && ev->code <= 90);
        int key_lower = is_letter_key ? ev->code + 32 : ev->code;
        int has_matching_text_input = 0;
        int has_non_matching_text_input = 0;
        int has_any_text_input = 0;
        if (is_letter_key) {
            for (size_t peek = g_event_pos + 1; peek < g_event_count; peek++) {
                if (g_events[peek].type == EV_KEY_UP || g_events[peek].type == EV_KEY_DOWN
                    || g_events[peek].type == EV_WAIT) break;
                if (g_events[peek].type == EV_TEXT_INPUT) {
                    has_any_text_input = 1;
                    int cp = g_events[peek].code;
                    if (cp == key_lower || cp == ev->code)
                        has_matching_text_input = 1;
                    else
                        has_non_matching_text_input = 1;
                }
            }
        }
        if (has_any_text_input && !has_matching_text_input) {
            for (size_t peek = g_event_pos + 1; peek < g_event_count; peek++) {
                if (g_events[peek].type == EV_KEY_UP || g_events[peek].type == EV_KEY_DOWN
                    || g_events[peek].type == EV_WAIT) break;
                if (g_events[peek].type == EV_TEXT_INPUT) {
                    actionTextFieldInput(app_context, g_events[peek].code);
                    g_events[peek].type = -1;
                }
            }
            g_key_press_consumed = 0;
        } else if (has_non_matching_text_input) {
            for (size_t peek = g_event_pos + 1; peek < g_event_count; peek++) {
                if (g_events[peek].type == EV_KEY_UP || g_events[peek].type == EV_KEY_DOWN
                    || g_events[peek].type == EV_WAIT) break;
                if (g_events[peek].type == EV_TEXT_INPUT) {
                    int cp = g_events[peek].code;
                    if (cp != key_lower && cp != ev->code) {
                        actionTextFieldInput(app_context, cp);
                        g_events[peek].type = -1;
                    }
                }
            }
            int key_press_handled = dispatch_button_key_actions(app_context, ev->code);
            g_key_press_consumed = key_press_handled;
            if (!key_press_handled)
                actionDispatchKeyPressToFocused(app_context, ev->code);
            if (!key_press_handled && ev->code == 9) {
                int shift_held = (app_context->keys.down[16] != 0);
                actionAdvanceTabFocus(app_context, shift_held);
            }
        } else {
            int key_press_handled = dispatch_button_key_actions(app_context, ev->code);
            g_key_press_consumed = key_press_handled;
            if (!key_press_handled)
                actionDispatchKeyPressToFocused(app_context, ev->code);
            if (!key_press_handled && ev->code == 9) {
                int shift_held = (app_context->keys.down[16] != 0);
                actionAdvanceTabFocus(app_context, shift_held);
            }
        }
        break;
    }
    case EV_KEY_UP:
        if (ev->code >= 0 && ev->code < 256)
            app_context->keys.down[ev->code] = 0;
        app_context->keys.last_key_down = ev->code;
        app_context->keys.last_key_ascii = (ev->code >= 32 && ev->code <= 126) ? ev->code : 0;
        dispatch_clip_event_flag(app_context, CLIP_EVENT_KEY_UP);
        actionDispatchKeyUpToFocused(app_context, ev->code);
        actionDispatchKeyUp(app_context);
        break;
    case EV_TEXT_INPUT:
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
        else if (strcmp(ev->ctrl, "MoveHome") == 0)
            actionTextControlMoveHome(app_context);
        else if (strcmp(ev->ctrl, "MoveEnd") == 0)
            actionTextControlMoveEnd(app_context);
        else if (strcmp(ev->ctrl, "Enter") == 0)
            actionTextControlEnter(app_context);
        else if (strcmp(ev->ctrl, "Backspace") == 0)
            actionTextControlBackspace(app_context);
        break;
    case EV_SET_CLIPBOARD_TEXT:
        actionSetClipboardText(ev->text);
        break;
    case EV_IME_PREEDIT:
        { extern void actionTextFieldImeCompose(SWFAppContext*, const char*, int, int);
          actionTextFieldImeCompose(app_context, ev->text, ev->code, (int)ev->x); }
        break;
    case EV_IME_COMMIT:
        { extern void actionTextFieldImeCommit(SWFAppContext*, const char*);
          actionTextFieldImeCommit(app_context, ev->text); }
        break;
    case EV_FOCUS_LOST:
        actionWindowFocusLost(app_context);
        break;
    case EV_FOCUS_GAINED:
        break;
    default:
        break;
    }
}

void input_events_pump_tick(SWFAppContext* app_context)
{
    while (g_event_pos < g_event_count) {
        InputEvent* ev = &g_events[g_event_pos];
        if (ev->type == EV_WAIT) {
            g_event_pos++;
            return;
        }
        input_events_deliver(app_context, ev);
        g_event_pos++;
        actionFlushDeferredRollEvents(app_context);
    }
}
