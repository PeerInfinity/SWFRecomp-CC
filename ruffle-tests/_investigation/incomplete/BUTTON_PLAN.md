# Button Behavior and Events Implementation Plan
<!-- TESTS: button_children, button_goto, button_key_events, button_key_events_special, button_keypress, button_keypress_vs_press, button_keypress_vs_tab, button_keypress_vs_textinput, button_order, button_properties_special_cases, button_v5, button_v6, movieclip_in_removed_button, root_button_mode -->

Last updated: 2026-02-19

## Status: NOT STARTED

All 14 tests are currently failing with avg 1% match. The button handling in NO_GRAPHICS mode (`tag_stubs.c`) currently:
- Registers button char_ids for `typeof` discrimination (returns "object" in SWF6+)
- Does NOT store state frame functions → button children never initialize
- Does NOT dispatch events (no input.json support exists)

---

## Overview

The 14 failing button tests split into two very different problems:

**Problem A — Button Children Initialization (5 tests, no input needed)**
Buttons contain child clips placed in their state frames. In trace mode, these children need
to initialize (run their frame scripts) even without user interaction. Currently `tagDefineButton`
discards all state_funcs and the children never execute.

**Problem B — Input Event Simulation (9 tests with input.json)**
Tests with `input.json` files expect simulated mouse and keyboard events to trigger AS2 event
handlers (`onRollOver`, `onPress`, `onKeyDown`, etc.) and SWF4-style button conditions
(DoAction with condition bitmask). Currently `verify_output.py` ignores `input.json` entirely.

Both problems are independent — Phase 1 can be done without Phase 2 infrastructure.

---

## Test Inventory

### Phase 1 — Button Children Initialization (no input.json)

| Test | Lines | Key behavior |
|------|-------|-------------|
| button_children | 8 | Button child sprite script accesses button._width (200), sprite._name, _parent |
| button_v5 | 18 | SWF5: button child `_parent` = `_level0` (typeof movieclip), bypasses button |
| button_v6 | 18 | SWF6: button child `_parent` = button itself (typeof object) |
| button_order | 2 | Two sprite instances inside button both get `onEnterFrame`; fires in depth-descending order |
| movieclip_in_removed_button | 4 | Button removed → zombie clip still fires onEnterFrame for 1 frame |

### Phase 2 — Input Event Infrastructure (foundation for all 9 below)

No tests pass from this phase alone, but it unlocks Phases 3–6.

### Phase 3 — Mouse Events + Button State Machine

| Test | Lines | Key behavior |
|------|-------|-------------|
| button_goto | 4 | Mouse hover/drag triggers SWF4 button conditions (rollOver/dragOut/dragOver/rollOut traces) |
| button_properties_special_cases | 23 | `enabled` property semantics: prototype inheritance, hasOwnProperty, `in` operator, delete |
| root_button_mode | 10 | MovieClip with `buttonMode=true` gets onPress/onRelease; ALSO needs loadMovie (deferred) |

### Phase 4 — Key Events

| Test | Lines | Key behavior |
|------|-------|-------------|
| button_key_events | 14 | `onKeyDown`/`onKeyUp` handlers on buttons + Key.addListener (`keyPress x` output) |
| button_key_events_special | 45 | Same but with arrow/home/end/insert/delete/backspace/tab/enter keys |
| button_keypress | 3 | SWF4-style `on(press)` and `on(keyPress "<Enter>")` button conditions; gotoAndStop |
| button_keypress_vs_press | 25 | Key events ordered relative to press/release; which fires first? |
| button_keypress_vs_textinput | 4 | Key listener fires for 'a' keyPress; text field's onChanged from text input |

### Phase 5 — Focus + Tab Navigation

| Test | Lines | Key behavior |
|------|-------|-------------|
| button_keypress_vs_tab | 20 | Tab cycles focus between buttons; FocusChanged event; Escape prevents keyPress tab |

---

## Phase 1: Button Children Initialization

### What's failing

When a button is placed via `tagPlaceObject2`, its up-state children (sprites defined in
`button_3_frame_up`) never get initialized. So:
1. Button child sprites never have their frame scripts executed
2. `_width`/`_height` of the button is 0 (no bounds tracking)
3. `_parent` of button children is wrong (currently resolves as if the button doesn't exist)

### SWF behavior

When Flash Player places a button on the display list:
1. The button's "up" state frame function runs (like a sprite frame 0)
2. This places child objects into the button's own local display list
3. Those child sprites initialize and run their frame 0 scripts
4. The button's local display list is nested under the button in the parent clip's display list
5. Child clip `_parent`:
   - **SWF ≤ 5**: `_parent` bypasses the button; resolves to the button's parent clip (type "movieclip")
   - **SWF ≥ 6**: `_parent` = the button itself (type "object")
6. `_name` of button children: auto-assigned "instance1", "instance2", etc. (same counter as other clips)

### `_width` of button

The button_children test expects `button._width = 200`. The button's hit area is char_id 1
(a shape with bounds xmin=-2000, xmax=2000 → 4000 twips → 200 pixels). The button's visible
bounds come from its hit shape, not from child clip bounds.

Currently `tagDefineShape` in tag_stubs.c does NOT store shape bounds — it only stores shape
draw data for graphics mode. For trace mode, we need to store the bounding rect (xmin, xmax,
ymin, ymax in twips) per shape, then look up the hit shape's bounds in `tagDefineButton`.

Shape bounds are already passed as arguments to `tagDefineShape`:
```c
tagDefineShape(app_context, CHAR_TYPE_SHAPE, char_id, draw_start, draw_count,
               xmin, xmax, ymin, ymax);
```
We just need a `ng_shape_bounds[char_id]` registry in tag_stubs.c and a lookup in
`tagDefineButton`/`tagPlaceObject2` when computing `_width`/`_height`.

### Implementation: tag_stubs.c changes

#### 1a. Shape bounds registry

```c
// In tag_stubs.c static data:
typedef struct { s32 xmin, xmax, ymin, ymax; } ShapeBounds;
static ShapeBounds ng_shape_bounds[256];  // indexed by char_id
static size_t ng_shape_bounds_count = 256;

// In tagDefineShape:
void tagDefineShape(SWFAppContext* app_context, int type, size_t char_id,
                    size_t draw_start, size_t draw_count,
                    s32 xmin, s32 xmax, s32 ymin, s32 ymax)
{
    if (char_id < 256) {
        ng_shape_bounds[char_id].xmin = xmin; ng_shape_bounds[char_id].xmax = xmax;
        ng_shape_bounds[char_id].ymin = ymin; ng_shape_bounds[char_id].ymax = ymax;
    }
    // ... existing code ...
}
```

#### 1b. Button state function registry

Extend button registry to store state_funcs and hit shape bounds:

```c
typedef struct {
    size_t char_id;
    frame_func* state_funcs;  // [0]=up, [1]=over, [2]=down
    size_t hit_char_id;       // hit shape char_id for bounds lookup
    ButtonAction* actions;
    size_t action_count;
    s32 width_twips, height_twips;  // computed from hit shape bounds
} NgButtonDef;

static NgButtonDef ng_button_defs[MAX_BUTTONS_NG];

// In tagDefineButton:
void tagDefineButton(SWFAppContext* app_context, size_t char_id, frame_func* state_funcs,
                     size_t hit_char_id, u32 hit_transform_id,
                     ButtonAction* actions, size_t action_count)
{
    NgButtonDef* def = &ng_button_defs[ng_button_count++];
    def->char_id = char_id;
    def->state_funcs = state_funcs;
    def->hit_char_id = hit_char_id;
    def->actions = actions;
    def->action_count = action_count;
    // Compute bounds from hit shape
    if (hit_char_id < 256) {
        def->width_twips = ng_shape_bounds[hit_char_id].xmax - ng_shape_bounds[hit_char_id].xmin;
        def->height_twips = ng_shape_bounds[hit_char_id].ymax - ng_shape_bounds[hit_char_id].ymin;
    }
}
```

#### 1c. Button children initialization on placement

When `tagPlaceObject2` detects a button char_id (btn != NULL), call its up-state frame
function with nesting to initialize button children:

```c
// After the entry is created/updated in tagPlaceObject2, for button chars:
if (btn_def != NULL && btn_def->state_funcs != NULL) {
    // Push button's display index as current nesting context
    size_t saved_nesting = ng_nesting_depth;
    size_t saved_current = ng_current_display_idx;
    ng_nesting_depth++;
    ng_current_display_idx = /* new button's ng_display index */;
    // Call up-state frame func (index 0)
    btn_def->state_funcs[0](app_context);
    ng_nesting_depth = saved_nesting;
    ng_current_display_idx = saved_current;
}
```

This mirrors how sprite frame 0 is called (the `needs_init` path for sprites).

#### 1d. `_parent` resolution for button children

In `getDisplayObjectProperty` / `actionGetVariable` for `_parent`:
- Look at the display entry's `parent_display_idx`
- If the parent display entry `is_button`, apply SWF version logic:
  - SWF ≤ 5: return GRANDPARENT (skip the button)
  - SWF ≥ 6: return the button (as `type = "object"`)

This requires `g_swf_version` (already available in action.c) to be consulted during `_parent` resolution in tag_stubs.c. Simplest approach: tag_stubs.c declares `extern int g_swf_version;`.

#### 1e. `_width`/`_height` from button bounds

`actionGetProperty` / GetMember `_width` for a button:
- Retrieve the button's `width_twips` from `ng_button_defs` via char_id lookup
- Convert: `_width = width_twips / 20.0`

#### 1f. `onEnterFrame` dispatch order (button_order)

`button_order` places two sprite instances inside the button's up-state and expects:
```
enterFrame instance3
enterFrame instance2
```
Instance3 (deeper depth) fires BEFORE instance2 (shallower depth). In Flash, `onEnterFrame`
dispatches in depth-descending order (front-to-back). This means the `onEnterFrame` loop in
`tagShowFrame` should iterate in reverse depth order. This may already work correctly if the
display list is ordered by insertion time (last-placed = highest depth = iterated first).

### Tests fixed by Phase 1

- **button_children**: Fixed — child sprite script runs, `_width` = 200
- **button_v5**: Fixed — `_parent` bypasses button (SWF5), `typeof _parent = movieclip`
- **button_v6**: Fixed — `_parent` = button (SWF6), `typeof _parent = object`
- **button_order**: Fixed — two sprites inside button fire enterFrame
- **movieclip_in_removed_button**: Fixed — button removed, zombie clip fires onEnterFrame

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=button_children --diff --verbose
python3 ruffle-tests/verify_output.py --test=button_v5 --diff --verbose
python3 ruffle-tests/verify_output.py --test=button_v6 --diff --verbose
python3 ruffle-tests/verify_output.py --test=button_order --diff --verbose
python3 ruffle-tests/verify_output.py --test=movieclip_in_removed_button --diff --verbose
```

---

## Phase 2: Input Event Simulation Infrastructure

### Problem

`verify_output.py` currently ignores `input.json`. The Ruffle test framework interleaves
input events between frame ticks. We need to:
1. Parse `input.json` in `verify_output.py`
2. Generate a `events.c` file with a compiled-in events array
3. `main.c` processes events BETWEEN frames (before each frame tick)

### input.json format

Event types seen across all button tests:
```json
{ "type": "MouseMove", "pos": [x, y] }
{ "type": "MouseDown", "pos": [x, y], "btn": "Left" }
{ "type": "MouseUp",   "pos": [x, y], "btn": "Left" }
{ "type": "KeyDown",   "key": "Enter" }       // named key
{ "type": "KeyDown",   "key": { "Char": "a" } } // character key
{ "type": "KeyUp",     "key": "..." }
{ "type": "TextInput", "codepoint": "a" }     // character sent to focused text field
{ "type": "TextControl", "code": "Enter" }    // control input to text field
{ "type": "Wait" }                            // advance one frame
```

`Wait` = process the pending frame (run `tagShowFrame`). Events without `Wait` between them
happen "instantly" within the same frame transition. Events with multiple `Wait`s in sequence
means multiple empty frames advance.

For `num_ticks = 1` tests: all events fire before/during the single frame. No `Wait` entries
are present in input.json for these tests.

### Implementation: events.c generation

`verify_output.py` reads `input.json` and generates `events.c`:

```c
// events.c (generated by verify_output.py)
#include "events.h"

SWFInputEvent g_swf_events[] = {
    { EVENT_MOUSE_MOVE, .x = 160.0f, .y = 160.0f },
    { EVENT_WAIT },
    { EVENT_MOUSE_DOWN, .x = 160.0f, .y = 160.0f },
    { EVENT_KEY_DOWN, .key_code = 65 },  // 'a'
    // ...
};
int g_swf_event_count = N;
```

And `events.h`:
```c
typedef enum {
    EVENT_NONE, EVENT_WAIT, EVENT_MOUSE_MOVE, EVENT_MOUSE_DOWN, EVENT_MOUSE_UP,
    EVENT_KEY_DOWN, EVENT_KEY_UP, EVENT_TEXT_INPUT, EVENT_TEXT_CONTROL,
} SWFInputEventType;

typedef struct {
    SWFInputEventType type;
    float x, y;        // for mouse events
    int key_code;      // for key events (Flash key code)
    int char_code;     // for text input (Unicode codepoint)
} SWFInputEvent;

extern SWFInputEvent g_swf_events[];
extern int g_swf_event_count;
```

If no `input.json` exists, generate an empty events array.

### main.c integration

```c
// In main.c frame loop:
extern SWFInputEvent g_swf_events[];
extern int g_swf_event_count;
static int event_idx = 0;

// Before each frame:
void process_events_until_wait() {
    while (event_idx < g_swf_event_count) {
        SWFInputEvent* e = &g_swf_events[event_idx++];
        if (e->type == EVENT_WAIT) return;  // Stop at Wait
        dispatch_event(e);
    }
}
```

For `num_ticks = 1` tests: drain ALL events (no Waits), THEN run the single frame tick.

### Key code mapping

Flash key codes differ from modern key codes. The recompiler already knows them (used in
button conditions). We need a mapping from JSON key names to Flash key codes:

| JSON key name | Flash key code | Notes |
|---------------|---------------|-------|
| `"Enter"` | 13 | |
| `"Space"` | 32 | |
| `"Tab"` | 9 | |
| `"Escape"` | 27 | |
| `"ArrowLeft"` | 37 | |
| `"ArrowRight"` | 39 | |
| `"ArrowUp"` | 38 | |
| `"ArrowDown"` | 40 | |
| `"Home"` | 36 | |
| `"End"` | 35 | |
| `"Insert"` | 45 | |
| `"Delete"` | 46 | |
| `"Backspace"` | 8 | |
| `"PageUp"` | 33 | |
| `"PageDown"` | 34 | |
| `{ "Char": "a" }` | 65 | A-Z: 65-90 |

### Files to add/modify for Phase 2

- `verify_output.py`: Read `input.json`, generate `events.c` + `events.h` in build dir
- `SWFRecomp/wasm_wrappers/main.c`: Consume events in frame loop
- New `SWFModernRuntime/include/libswf/events.h`: Event struct definition
- tag_stubs.c: `void swf_dispatch_event(SWFInputEvent* e)` implementation

---

## Phase 3: Mouse Events + Button State Machine

### Button state machine

Buttons have 4 states:
```
idle ─────MouseOver──→ over ──MouseDown──→ down
 ↑                      │                   │
 └──MouseOut────────────┘     MouseMove─────┘
                              Out = outDown
```

BUTTONCONDACTION condition bits (UI16 LE, from SWF spec):
```
0x0001 IdleToOverUp      → rollOver
0x0002 OverUpToIdle      → rollOut
0x0004 OverUpToOverDown  → press
0x0008 OverDownToOverUp  → release
0x0010 OverDownToOutDown → dragOut (pressing + moved out)
0x0020 OutDownToOverDown → dragOver (pressing + moved back in)
0x0040 OutDownToIdle     → releaseOutside
0x0080 IdleToOverDown    → (direct idle→press: unusual)
0x0100 OverDownToIdle    → (also part of dragOut conditions)
```

Per-button state machine: `ng_button_state[i]` (0=idle, 1=over, 2=down, 3=outdown)

### Hit testing

For each MouseMove/MouseDown event: check if `(x, y)` is inside any button's hit area.
Button hit area = the button's `hit_char_id` shape bounds + the button's current transform.

Mouse coordinates in `input.json` are in pixels (already scaled to SWF coordinate space?
Or in screen pixels that need conversion from stage size). For now assume the input.json
coordinates are in the SWF's coordinate space (same as shape bounds / 20).

Simple AABB hit test against button's hit shape bounds:
```c
int button_hit_test(NgButtonDef* def, float mouse_x, float mouse_y) {
    // Bounds in pixels (twips/20)
    float xmin = def->xpos + ng_shape_bounds[def->hit_char_id].xmin / 20.0f;
    float xmax = def->xpos + ng_shape_bounds[def->hit_char_id].xmax / 20.0f;
    float ymin = def->ypos + ng_shape_bounds[def->hit_char_id].ymin / 20.0f;
    float ymax = def->ypos + ng_shape_bounds[def->hit_char_id].ymax / 20.0f;
    return (mouse_x >= xmin && mouse_x <= xmax && mouse_y >= ymin && mouse_y <= ymax);
}
```

Button position needs to be tracked when the button is placed (from transform_id). Since
NO_GRAPHICS mode doesn't use the transform matrix, we need to track x/y offset from
`tagPlaceObject2` coordinates. Currently x/y are always 0 for button tests (buttons placed
at origin), so a simple x=0, y=0 placeholder works for Phase 3.

### AS2 event handlers

When a button transitions:
1. Fire the matching `ButtonAction` conditions (DoAction-style)
2. Call AS2 handler if set: `onRollOver`, `onRollOut`, `onPress`, `onRelease`, `onReleaseOutside`

AS2 handlers are stored as properties on the button's MovieClip instance:
```c
// Dispatch AS2 handler for button at ng_display index i:
void dispatch_button_event(SWFAppContext* app_context, size_t di, const char* handler_name) {
    // Get button's MC object
    // Look up handler_name property
    // If it's a function, call it
}
```

### `enabled` property (button_properties_special_cases)

`MovieClip.prototype.enabled` defaults to `true`. Setting `enabled = false` on a specific
button instance disables it (state machine won't transition, no events fire). But setting
`enabled = undefined` does NOT disable it — only `false` (strict boolean false) disables.

The test verifies:
- `MovieClip.prototype.hasOwnProperty('enabled')` = true (enabled is on prototype)
- `button.hasOwnProperty('enabled')` = false (button doesn't have own enabled yet)
- `button.enabled` = true (inherited from prototype)
- After `button.enabled = undefined`: button still receives press event (undefined != false)
- After `delete button.enabled`: `button.enabled` = true again (from prototype)

Implementation: Set `MovieClip.prototype.enabled = true` during global init. Button state
machine checks `enabled`: only `false` (strict) blocks transitions.

### `root_button_mode` — deferred

This test requires `createEmptyMovieClip`, `loadMovie`, and `_lockroot`, none of which are
fully implemented. Defer until those features are available.

### Tests fixed by Phase 3 (partial)

- **button_goto**: Fixed — mouse input triggers rollOver/dragOut/dragOver/rollOut traces
- **button_properties_special_cases**: Fixed — mouse input + `enabled` property semantics

---

## Phase 4: Key Events on Buttons

### Key dispatch model

In Flash, keyboard events dispatch to:
1. All `Key.addListener` subscribers → call `onKeyDown()`/`onKeyUp()` on each listener
2. The currently focused button/clip (if any) → call its own `onKeyDown()`/`onKeyUp()`
3. SWF4-style button keyPress conditions → fire if the focused button has matching condition

For `button_key_events`, the AS looks like:
```as
button.onKeyDown = function() { trace("button.onKeyDown"); };
button.onKeyUp = function() { trace("button.onKeyUp"); };
Key.addListener(listener);  // traces "keyPress a"/"keyPress b" on key presses
```

The trace order in `button_key_events` expected output:
```
button.onKeyDown   ← onKeyDown fires first (button handler)
keyPress a         ← Key listener fires second
button.onKeyUp     ← onKeyUp fires on key up
```

### Global key listener (Key object)

`Key` is a global object with:
- `Key.addListener(obj)` — registers obj to receive `onKeyDown`/`onKeyUp`
- `Key.removeListener(obj)` — unregisters
- `Key.isDown(keyCode)` — returns true if key is currently pressed
- `Key.getCode()` — returns last key code
- `Key.getAscii()` — returns ASCII of last key

Key listeners fire AFTER the focused button's own handlers.

### SWF4-style keyPress conditions

`button_keypress` test has:
```
{ 0x??, button_5_action_0 }  // on(press) condition
{ 0x??, button_5_action_1 }  // on(keyPress "<Enter>") condition
```

Looking at `button_keypress` expected output:
```
_level0.instance1 - button 5 - press event
_level0 - button 6 - keyPress<Enter> event
frame 2
```

SWF4 button actions use BUTTONCONDACTION condition bits. The keyPress conditions encode
the key in the upper byte of the condition word (bits 15-9 = ASCII code). Flash defines
special key codes for named keys (Enter=13 maps to button condition bit 7 = 0x80 in lower byte,
or the key code is in the high byte).

Actually from the SWF spec: button condition bits 15:9 = key press code (0 = none,
1-6 = special keys, 32+ = ASCII character). So `on(keyPress "<Enter>")` = condition has
Enter key code in bits 15:9.

The SWF4 approach is:
- button_3_action_X has condition 0x?? that includes a key press condition
- When the key is pressed globally, check each button for matching keyPress condition

### Key focus for `onKeyDown`/`onKeyUp`

For buttons with AS2 `onKeyDown`/`onKeyUp`, Flash dispatches these globally to ALL focused
(or all) buttons? Actually looking at `button_key_events`, there are two buttons and the
events go to one of them depending on Tab order. Initially button1 has focus. After Tab,
focus shifts to button2. Then key events go to button2.

But for the simpler tests (button_key_events), all key events seem to go to both buttons?
Looking at expected output:
```
button.onKeyDown     ← from button (button1 has focus)
keyPress a           ← from key listener
button.onKeyUp
button.onKeyDown
keyPress b
button.onKeyDown     ← second KeyDown 'a' simultaneously with 'b' still held
keyPress a
button.onKeyUp       ← 'b' released
button.onKeyUp       ← 'a' released
button.onKeyDown     ← Tab key (but wait — shouldn't Tab change focus?)
button2.onKeyUp      ← button2 gets key up? That's odd
button2.onKeyDown    ← focus shifted to button2
keyPress a
button2.onKeyUp
```

The Tab key does NOT trigger Focus Changed here (unlike button_keypress_vs_tab), suggesting
that in button_key_events there are no focus-changing listeners set up. The Tab keyDown on
button1 and keyUp on button2 suggests focus changed mid-key (Tab key press = focus shift).

This is complex. For Phase 4, implement simplified key dispatch to all buttons uniformly,
then refine with focus in Phase 5.

### Tests addressed by Phase 4

- **button_key_events**: AS2 onKeyDown/onKeyUp on buttons + Key listener
- **button_key_events_special**: Same with arrow/home/end/etc. key codes
- **button_keypress**: SWF4 on(press) + on(keyPress "<Enter>") conditions
- **button_keypress_vs_press**: Key press vs mouse press ordering
- **button_keypress_vs_textinput**: Key events with text field focus

---

## Phase 5: Focus and Tab Navigation

### Focus management

Required for `button_keypress_vs_tab`:
- `Selection` object with `getFocus()`/`setFocus()`/`addListener()`
- `Selection.addListener(obj)` → obj.onSetFocus/onKillFocus called on focus changes
- Tab key advances focus through buttons in depth order
- `FocusChanged` trace comes from a `Selection.addListener` callback

Expected behavior:
1. Initial state: focus = null
2. Tab: focus changes null → button1 (fires FocusChanged)
3. Tab again: focus changes button1 → button2 (fires FocusChanged)
4. Escape key: NOT a focus change key, just fires onKeyDown/onKeyUp
5. Tab + Escape held: the keyPress tab condition (button2) fires ("keyPress 3 tab")

The "keyPress 3 tab" suggests that after the focus state where Escape suppresses Tab
navigation, the keyPress condition (type 3 = Tab) fires on the focused button.

This phase requires:
- `Selection` global object implementation
- Focus state per display object
- Tab order traversal
- `onSetFocus`/`onKillFocus` callbacks on buttons

---

## Implementation Priority and Dependencies

```
Phase 1 ─────────────────────────────────────────── (standalone)

Phase 2 ──→ Phase 3 ──→ Phase 4 ──→ Phase 5
(infra)    (mouse)      (keys)      (focus)
```

**Estimated test fixes per phase:**

| Phase | Tests Fixed | Cumulative |
|-------|------------|------------|
| 1 | 5 | 5 |
| 2+3 | 2 (button_goto, button_properties_special_cases) | 7 |
| 4 | 4 (key_events, key_events_special, keypress, keypress_vs_press) | 11 |
| 4 partial | 1 (button_keypress_vs_textinput) | 12 |
| 5 | 1 (button_keypress_vs_tab) | 13 |
| deferred | 1 (root_button_mode, needs loadMovie) | 13 |

---

## Files to Modify

### Phase 1 (tag_stubs.c only)

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/libswf/tag_stubs.c` | Shape bounds registry; button def registry with state_funcs; call up-state on placement; button children nested in display list; `_parent` SWF5 vs SWF6 resolution; `_width`/`_height` from hit bounds |

### Phase 2 (infrastructure)

| File | Changes |
|------|---------|
| `ruffle-tests/verify_output.py` | Read input.json; generate events.c + events.h in build dir; key name → Flash key code mapping |
| `SWFRecomp/wasm_wrappers/main.c` | Process events between frames; handle Wait = frame advance |
| New: `SWFModernRuntime/include/libswf/events.h` | SWFInputEvent struct, type enum |
| `SWFModernRuntime/src/libswf/tag_stubs.c` | `swf_dispatch_event()` implementation (mouse state tracking, placeholder for handlers) |

### Phase 3 (mouse events)

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/libswf/tag_stubs.c` | Button state machine per displayed button; hit test; ButtonAction condition dispatch |
| `SWFModernRuntime/src/actionmodern/action.c` | `MovieClip.prototype.enabled = true` default; AS2 handler dispatch (call onPress etc from C) |

### Phase 4 (key events)

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/libswf/tag_stubs.c` | Key state tracking; global key listener list dispatch |
| `SWFModernRuntime/src/actionmodern/action.c` | `Key` global object: addListener, removeListener, isDown, getCode, getAscii |

### Phase 5 (focus)

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | `Selection` global object; focus state; Tab focus cycle |
| `SWFModernRuntime/src/libswf/tag_stubs.c` | Per-display-object `has_focus` flag; focus traversal |

---

## Design Decisions

1. **Button children in NO_GRAPHICS display list**: Reuse the existing `ng_current_display_idx`
   nesting mechanism (already used for sprites). Button state 0 (up) is always initialized on
   placement; if state changes later (Phase 3), swap display children.

2. **events.c generation**: Generate a simple C file per test. This avoids needing stdin
   parsing or file I/O in the runtime — events are baked in at compile time, consistent with
   how the runtime currently handles all test-specific data (frame count, frame rate, SWF
   version, string tables).

3. **Button _width from hit shape**: Use the hit shape's AABB (not the visible shape's bounds).
   This matches Flash behavior. Phase 1 uses a simple AABB lookup; Phase 3 refines with
   transforms if needed.

4. **Key listener ordering**: Flash dispatches key events AFTER the focused button's own
   `onKeyDown`/`onKeyUp` handlers. `Key.addListener` subscribers fire after the focused object.
   This ordering must be exact for `button_key_events` to pass.

5. **mouse_x/mouse_y for hit testing**: input.json coordinates are in SWF coordinate space
   (screen pixels matching the stage dimensions from constants.h, e.g. FRAME_WIDTH=550).
   No scaling needed for hit tests.

6. **`root_button_mode` deferred**: This test needs `createEmptyMovieClip` + `loadMovie` +
   `_lockroot` to work correctly. It will only become fixable once those features are implemented
   as part of the MovieClip Methods plan.
