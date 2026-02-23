# Focus System Implementation Plan
<!-- TESTS: focus_mouse, focus_mouse_focusable, focus_mouse_rollout, focus_root_movie, focus_keyboard_press, focusrect_focuslost -->

Last updated: 2026-02-22

## Status: PARTIALLY IMPLEMENTED

Input event injection Phases 1-4, 7 (partial) are implemented. Key dispatch (`actionDispatchKeyDown`/`actionDispatchKeyUp`) and `actionAdvanceTabFocus` exist. Focus tracking state is partially in place. The remaining blocker is **Phase 0 of input-event-injection.md** (struct unification) for hit-test-based focus acquisition.

Prerequisites remaining:
- **input-event-injection.md Phase 0** (struct unification) — needed for hit-test-based focus
- **MOUSE_EVENTS_PLAN.md Phase B** (clip AS2 handler dispatch: `onMouseDown`/`onMouseUp`)
  — `focus_mouse` fires `clip.onMouseDown`/`clip.onMouseUp` alongside focus events
- **input-event-injection.md Phase 7** (Key AsBroadcaster) — PARTIALLY COMPLETE
- **SELECTION_PLAN.md Phase 1** is related but separate (covers `Selection.setFocus()` API,
  `Selection.addListener`, `getBeginIndex`/`getCaretIndex`/`getEndIndex`, `replaceSel`).
  This plan focuses on mouse-triggered focus only.

---

## Overview

6 tests cover mouse-click focus acquisition and the focus event model. They test:
1. Mouse click on a clip/button/textfield sets keyboard focus
2. `Selection.getFocus()` returns the path of the focused object
3. `onSetFocus(old)` / `onKillFocus(new)` callbacks on the gaining/losing clip
4. `focusEnabled` property — whether a MovieClip is focusable at all
5. `onRollOut` while focused fires `onKillFocus`
6. Key events dispatch to the FOCUSED clip, not all clips
7. Enter/Space on a focused button trigger press/release events

This plan covers only mouse-triggered focus and focus-as-prerequisite-for-key-events.
Tab-key focus navigation is covered in **TAB_ORDERING_PLAN.md**.

---

## Test Inventory

| Test | Lines | Input | Key behavior |
|------|-------|-------|--------------|
| `focus_mouse` | 45 | MouseDown×10 | clip.onMouseDown/Up + button.onPress/Release + Selection.getFocus() |
| `focus_mouse_focusable` | 8 | MouseDown×4 | `focusEnabled` property controls whether clicks give focus |
| `focus_mouse_rollout` | 4 | MouseDown/Move | onRollOver → onSetFocus → onRollOut → onKillFocus |
| `focus_root_movie` | 1 | MouseDown | Clicking root movie sets focus: "Focus changed: null -> _level0.clip" |
| `focus_keyboard_press` | 46 | Tab+Key×many | Tab to focus clip/button, then key events go to focused clip; Enter/Space = press |
| `focusrect_focuslost` | 4 | MouseDown/Move | Same as focus_mouse_rollout (onRollOver/onSetFocus/onRollOut/onKillFocus) |

---

## Focus State

### Global focus tracking

Add to `swf_core.c` (or expose via tag.c):

```c
// Index into display_list[] of the focused object, or (size_t)-1 if none.
// For root-level items, uses display_list depth index.
static size_t g_focused_depth = (size_t)-1;
```

Access via `ng_getFocusedDepth()` / `ng_setFocusedDepth(depth)` functions (exposed in tag.h).

Flash focus rules:
- Buttons: focusable by default (mouse click + Tab)
- Text fields (input): focusable by default (mouse click + Tab)
- Movie clips: focusable only if `focusEnabled = true` (NOT by default via mouse click)
- Non-input text fields (static text, non-input edit text): NOT focusable

---

## Phase A: Mouse Click → Focus Acquisition

### Trigger

On `EV_MOUSE_DOWN_LEFT`, after the button state machine runs (which handles button
onPress/rollOver etc.), check if the clicked object should receive keyboard focus:

```c
// In tag.c, after hit-test loop in tagShowFrame (or in dispatch_clip_mouse_event):
void try_set_focus_on_click(SWFAppContext* app_context)
{
    // Find the frontmost hit clip
    for (size_t i = max_depth; i >= 1; i--)
    {
        DisplayObject* obj = &display_list[i];
        if (obj->char_id == 0) continue;
        Character* ch = &dictionary[obj->char_id];

        // Hit test the clip
        if (!hit_test_object(app_context, obj)) continue;

        // Determine if this clip/char is focusable
        int focusable = 0;
        if (ch->type == CHAR_TYPE_BUTTON) focusable = 1;
        if (ch->type == CHAR_TYPE_TEXT && is_input_textfield(obj)) focusable = 1;
        if (ch->type == CHAR_TYPE_SPRITE) {
            // focusable only if focusEnabled = true on the AS MC instance
            focusable = ng_getMCProperty_focusEnabled(obj);
        }

        if (focusable) {
            size_t old_focus = g_focused_depth;
            if (old_focus != i) {
                // Fire onKillFocus on the old focused object
                if (old_focus != (size_t)-1)
                    dispatch_focus_event(app_context, old_focus, "onKillFocus", i);
                g_focused_depth = i;
                // Fire onSetFocus on the new focused object
                dispatch_focus_event(app_context, i, "onSetFocus", old_focus);
                // Fire Selection listener callbacks
                dispatch_selection_listeners(app_context, old_focus, i);
            }
        } else {
            // Non-focusable click: clear focus
            if (g_focused_depth != (size_t)-1) {
                dispatch_focus_event(app_context, g_focused_depth, "onKillFocus", (size_t)-1);
                g_focused_depth = (size_t)-1;
                dispatch_selection_listeners(app_context, g_focused_depth, (size_t)-1);
            }
        }
        return;  // only first hit clip matters
    }
    // Clicked empty area: clear focus
    if (g_focused_depth != (size_t)-1) {
        dispatch_focus_event(app_context, g_focused_depth, "onKillFocus", (size_t)-1);
        g_focused_depth = (size_t)-1;
    }
}
```

### `dispatch_focus_event`

```c
void dispatch_focus_event(SWFAppContext* app_context, size_t depth, const char* handler, size_t other_depth)
{
    // Construct the path string for 'other_depth' as the argument
    // Call handler name as a method on the display entry's MC instance
    // E.g., display_list[depth].mc_instance.onSetFocus(other_path)
    ActionVar arg = make_path_string(other_depth);  // "_level0.clip" or null
    call_as2_method_on_entry(app_context, depth, handler, &arg, 1);
}
```

### `focus_mouse` event order

Looking at expected output:
```
_level0.clip.onMouseDown   ← Phase B clip dispatch (global)
_level0.clip.onMouseUp     ← Phase B
_level0.clip.onMouseDown   ← second click (same clip)
_level0.clip.onPress       ← button state machine (not a clip... wait)
```

Actually `focus_mouse` has BOTH a MovieClip and a Button. The clip fires `onMouseDown`/`onMouseUp`
globally; the button fires `onPress`/`onRelease` via the button state machine. Looking at the test:
- Clicks 1-2: clip area → clip.onMouseDown/Up fire (no press, clip is not a button)
- Clicks 3-4: button area → clip.onMouseDown + button.onPress + clip.onMouseUp + button.onRelease
- Clicks 5-6: textfield → "Focus at: _level0.text" trace from onSetFocus callback
- Clicks 7-8: empty area → "Focus at: null" (focus cleared)

The ordering: global `onMouseDown` fires first on all clips, THEN button state machine runs
(onPress for the hit button), THEN `onMouseUp` fires globally.

Actually: re-reading the output more carefully:
```
_level0.clip.onMouseDown   ← global dispatch
_level0.clip.onMouseUp     ← global dispatch
_level0.clip.onMouseDown
_level0.clip.onPress       ← button state machine fires onPress on _level0.clip?
```

Wait — "\_level0.clip" fires BOTH `onMouseDown` AND `onPress`. This means `_level0.clip` IS
the button AND the clip. OR `clip` has `onPress` set as an AS2 property and the button state
machine fires it because the clip has `buttonMode`-equivalent enabled.

In Ruffle/Flash: when a MovieClip has `onPress` defined as a property, it acts like a button.
The button state machine hit-tests it and calls `onPress`/`onRelease` etc. So `_level0.clip`
with `clip.onPress = function(){}` set gets BOTH:
- `onMouseDown` from global dispatch (fires always)
- `onPress` from button-mode hit-test dispatch (fires only when clicked ON the clip)

This is the "MovieClip as button" feature. Implementation: after global `onMouseDown` dispatch,
run a hit-test loop that calls `onPress` on any clip that (a) has `onPress` property defined
AND (b) is hit by the mouse. This is separate from DefineButton button state machine.

### `focusEnabled` property

`focus_mouse_focusable` clicks 4 different clips (text7, text5, text3, text1) with different
`focusEnabled` settings. Only certain ones get focus. Default for MovieClip is NOT focusable
(only with explicit `focusEnabled = true`).

For input text fields, `focusEnabled` defaults to `true` unless explicitly set to `false`.
Check the AS property on the MC instance.

---

## Phase B: Focus Events via Mouse Rollout

### `focus_mouse_rollout` expected:
```
Focus at: _level0.text    ← onSetFocus fires → trace from listener
Focus at: null            ← onKillFocus fires when mouse rolls out of textfield
_level0.clip.onPress      ← later clicks
_level0.clip.onRollOut
```

### `focusrect_focuslost` expected:
```
onRollOver    ← button rollOver
onSetFocus    ← button got focus (from rollOver? Or from mouse press?)
onRollOut     ← mouse moved out
onKillFocus   ← focus lost due to rollOut
```

In Flash, rolling OUT of a focused button while the mouse button is NOT pressed fires
`onKillFocus`. Rolling in fires `onSetFocus` (via the rollOver trigger for buttons).

This means: in the button state machine, when transitioning from `over` → `idle` (rollOut),
if the object has focus, fire `onKillFocus`. When transitioning from `idle` → `over` (rollOver),
if focusable, fire `onSetFocus`.

**Note for buttons specifically:** buttons acquire focus on rollOver (not just on click),
according to `focusrect_focuslost`. This differs from MovieClips which need explicit click.

---

## Phase C: `Selection.getFocus()` Path String

### Path format

`Selection.getFocus()` returns a string like `"_level0.text"` for a named clip, or `null`
if nothing is focused. The path string follows Flash's `target` path convention.

Implementation in action.c:
```c
// In Selection.getFocus():
if (g_focused_depth == (size_t)-1) {
    // return null
}
// Get instance_name from display_list[g_focused_depth]
// Build path: "_level0." + instance_name (for root-level clips)
// For nested: "_level0.parent.child" (walk parent chain)
char path[256];
build_target_path(g_focused_depth, path, sizeof(path));
return make_string_var(path);
```

`build_target_path` uses `instance_name` from `DisplayObject` (set by `tagSetInstanceName`
or auto-assigned by `ng_on_place_object2`).

---

## Phase D: Key Events to Focused Object

### Key dispatch model (from `focus_keyboard_press`)

When a key is pressed, events go to the FOCUSED object (not all objects):
1. `focused_clip.onKeyDown` fires (global Key listeners also fire, in order: focused first)
2. `focused_clip.onKeyUp` fires on key release
3. For focused BUTTONS: Enter(13) and Space(32) trigger press/release:
   - `onKeyDown(13)` fires (button's key handler)
   - `onPress(13)` fires (button acts as if clicked)
   - `onRelease(13)` fires
   - `onKeyUp(13)` fires

**Dispatch order** (from `focus_keyboard_press` output):
```
_level0.clip.onKeyDown: 9    ← Tab fires onKeyUp only (focus already changed before keyDown?)
```

Wait, Tab key handling: the Tab key advances focus BEFORE the key event is delivered to the
clip. So the focused clip changes on Tab, and the NEW clip receives the `onKeyUp` (not onKeyDown
since focus changed mid-key).

For non-Tab keys on focused MovieClip:
```
_level0.clip.onKeyDown: 13
_level0.clip.onPress: 13     ← Enter on focused clip that has onPress defined
_level0.clip.onRelease: 13   ← fires immediately (simulated release)
_level0.clip.onKeyUp: 13
```

For non-Tab keys on focused Button:
```
_level0.button.onKeyDown: 13
press                         ← button condition trace (DoAction with onPress condition)
_level0.button.onPress: 13
release
_level0.button.onRelease: 13
_level0.button.onKeyUp: 13
```

### Implementation

In `swf_core.c` (or tag.c) `dispatch_key_event()`:
```c
void dispatch_key_to_focused(SWFAppContext* app_context, int key_code, int is_keydown)
{
    if (g_focused_depth == (size_t)-1) return;
    DisplayObject* obj = &display_list[g_focused_depth];
    Character* ch = &dictionary[obj->char_id];

    const char* handler = is_keydown ? "onKeyDown" : "onKeyUp";
    ActionVar code_arg = make_int_var(key_code);
    call_as2_method_on_entry(app_context, g_focused_depth, handler, &code_arg, 1);

    if (is_keydown && (key_code == 13 || key_code == 32)) {
        // Enter/Space on focused clip with onPress = simulated press+release
        call_as2_method_on_entry(app_context, g_focused_depth, "onPress", &code_arg, 1);
        // Also fire DoAction button conditions if CHAR_TYPE_BUTTON
        if (ch->type == CHAR_TYPE_BUTTON) {
            // Fire OverUpToOverDown (press) then OverDownToOverUp (release) conditions
            fire_button_condition(app_context, obj, COND_PRESS);
            fire_button_condition(app_context, obj, COND_RELEASE);
        }
        call_as2_method_on_entry(app_context, g_focused_depth, "onRelease", &code_arg, 1);
    }
}
```

Call `dispatch_key_to_focused` from the EV_KEY_DOWN/EV_KEY_UP handlers in `swf_core.c`,
AFTER `actionDispatchKeyDown(app_context)` (Key AsBroadcaster fires after focused handler
based on the output order in `button_key_events`).

Actually, `button_key_events` says:
```
button.onKeyDown   ← button handler fires FIRST
keyPress a         ← Key listener fires SECOND
```

So order: (1) dispatch to focused clip → (2) Key AsBroadcaster. Current code already calls
`actionDispatchKeyDown` from EV_KEY_DOWN. Add `dispatch_key_to_focused` BEFORE that call.

---

## Implementation Order

```
Phase A ──→ Phase C (getFocus needs focus state) ──→ focus_mouse, focus_root_movie
Phase B (rollOut killFocus) ──────────────────────── focus_mouse_rollout, focusrect_focuslost
Phase D (key events to focused) ──────────────────── focus_keyboard_press
```

All depend on MOUSE_EVENTS_PLAN.md Phase B for `clip.onMouseDown/onMouseUp` dispatch.

---

## Files to Modify

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/libswf/tag.c` | `try_set_focus_on_click()`, `dispatch_focus_event()`, focus tracking integration in button state machine |
| `SWFModernRuntime/src/libswf/swf_core.c` | Call `try_set_focus_on_click()` from EV_MOUSE_DOWN_LEFT; call `dispatch_key_to_focused()` from EV_KEY_DOWN/UP |
| `SWFModernRuntime/src/actionmodern/action.c` | `Selection.getFocus()` implementation; `dispatch_selection_listeners()` |
| `SWFModernRuntime/include/libswf/tag.h` | Declare new functions |

---

## Relationship to Other Plans

- **TAB_ORDERING_PLAN.md**: Builds on this plan's focus state. Tab key advances focus using
  the same `g_focused_depth` state and fires the same `onSetFocus`/`onKillFocus` callbacks.
- **SELECTION_PLAN.md**: Covers the full `Selection` object API (`setFocus`, `getBeginIndex`,
  `setSelection`, `replaceSel`, `addListener`). This plan only implements `getFocus()` and
  the focus state tracking needed for mouse-triggered focus.
- **TEXTFIELD_PLAN.md Phase 4**: EditText keyboard input delivery — depends on focus tracking
  from this plan to know which textfield receives TextInput events.
- **MOUSE_EVENTS_PLAN.md Phase B**: Prerequisite — clip.onMouseDown/Up dispatch.
