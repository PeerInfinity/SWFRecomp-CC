# Button Behavior and Events Implementation Plan
<!-- TESTS: button_children, button_goto, button_key_events, button_key_events_special, button_keypress, button_keypress_vs_press, button_keypress_vs_tab, button_keypress_vs_textinput, button_order, button_properties_special_cases, button_v5, button_v6, movieclip_in_removed_button, root_button_mode -->

Last updated: 2026-02-22

## Status: MOSTLY NOT STARTED — but `button_order` now passes on CI

### CI Results (2026-02-22)
- `button_order` — **PASS** ✅ (likely benefited from MovieClip/depth infrastructure improvements)
- All other 13 tests — still failing (require struct unification + hit testing)

Input event injection **Phases 1-4 are complete** (event pump, mouse/key state, verify_output.py preprocessing). Button state machine (`ng_update_button_states`) and button key dispatch (`dispatch_button_key_actions`) exist in tag.c and are called from the event pump.

All remaining 13 tests are blocked on the following prerequisite from `SWFRecompDocs/plans/input-event-injection.md`:

- **Phase 0** (struct unification): Delete `tag_stubs.c`, merge into `tag.c`; make
  `Character`/`DisplayObject`/`MouseState` unconditional in `swf.h`; include
  `shape_data`/`transform_data` + `hit_test.c` in trace builds. This is the **sole remaining blocker** — once done, the existing button state machine and event dispatch should work in trace builds.

Current state of `tag_stubs.c` (before Phase 0 merges it away):
- Registers button char_ids for `typeof` discrimination (returns "object" in SWF6+)
- Does NOT store state frame functions → button children never initialize
- Does NOT dispatch events (button state machine in tag.c can't run until struct unification)

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

After input-event-injection.md Phase 0, `tag.c` is the single implementation. `tagDefineShape`
already receives xmin/xmax/ymin/ymax but the `Character` struct's shape variant doesn't store
them yet. We add those fields (see section 1a below) and look up the hit shape in `tagDefineButton`
to compute `width_twips`/`height_twips` (see section 1b).

### Implementation: tag.c changes (after input-event-injection.md Phase 0)

**Note:** After Phase 0 of input-event-injection.md, `tag_stubs.c` is deleted and
`tag.c` is used for both trace and graphics builds. All implementation below targets
`tag.c` and the shared `Character`/`DisplayObject` structs in `swf.h`.

#### 1a. Shape bounds in Character struct

`tagDefineShape` receives xmin/xmax/ymin/ymax but the `Character` struct's shape
variant currently only stores `draw_start`/`draw_count`. Add bounds fields:

```c
// In swf.h, Character.shape variant:
struct {
    size_t draw_start, draw_count;
    s32 xmin, xmax, ymin, ymax;   // ADD: bounding rect in twips
} shape;
```

```c
// In tag.c tagDefineShape (unconditional section):
ch->shape.xmin = xmin;  ch->shape.xmax = xmax;
ch->shape.ymin = ymin;  ch->shape.ymax = ymax;
```

#### 1b. Button width/height from hit shape bounds

The `Character` struct's button variant already stores `state_funcs`, `actions`,
`action_count`, and `hit_char_id` (after Phase 0 unification). Add hit bounds:

```c
// In tagDefineButton, compute and cache hit bounds on the Character:
Character* hit_ch = (hit_char_id < dictionary_count) ? &dictionary[hit_char_id] : NULL;
if (hit_ch && hit_ch->type == CHAR_TYPE_SHAPE) {
    ch->button.width_twips  = hit_ch->shape.xmax - hit_ch->shape.xmin;
    ch->button.height_twips = hit_ch->shape.ymax - hit_ch->shape.ymin;
}
```

(`width_twips`/`height_twips` are new fields in the `Character.button` variant.)

#### 1c. Button children initialization on placement

When `tagPlaceObject2` places a `CHAR_TYPE_BUTTON` character, call its up-state frame
function using the same context-swap pattern already used for sprite initialization:

```c
// In tag.c tagPlaceObject2, for CHAR_TYPE_BUTTON:
if (ch->type == CHAR_TYPE_BUTTON && ch->button.state_funcs != NULL) {
    // Context swap: push button's sprite display list (same as sprite init)
    // ... same save/restore of display_list/max_depth/display_list_capacity ...
    ch->button.state_funcs[0](app_context);  // up-state frame func
    // ... restore context ...
}
```

This mirrors the sprite `needs_init` path already in `tag.c`.

#### 1d. `_parent` resolution for button children

In `actionGetVariable`/`actionGetProperty` for `_parent`, when the parent
`DisplayObject` has `type == CHAR_TYPE_BUTTON`:
- **SWF ≤ 5**: return GRANDPARENT (skip the button, return parent of button)
- **SWF ≥ 6**: return the button itself (as `type = "object"`)

`g_swf_version` is already available in `action.c` and readable from `tag.c` via `extern`.

#### 1e. `_width`/`_height` from button bounds

`actionGetProperty` / GetMember `_width` for a button:
- Look up the Character in `dictionary[]` by char_id
- Return `character.button.width_twips / 20.0f`

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

> **SUPERSEDED** — This phase is now fully covered by `SWFRecompDocs/plans/input-event-injection.md`
> (Phases 0–4 of that plan). See that document for the authoritative design. Summary of what
> it provides for phases 3–5 of this plan:
>
> - **Phase 0**: `tag_stubs.c` deleted; `tag.c` unified; `Character`/`DisplayObject`/
>   `MouseState` unconditional in `swf.h`; `shape_data`/`transform_data` + `hit_test.c`
>   included in trace builds. Button `Character` variant and display list fully available.
> - **Phase 1**: `verify_output.py` reads `input.json`, pre-processes to a line-based text
>   file (one event per line), passes as `argv[1]` to the test binary. Key mapping:
>   Ruffle key names → Flash key codes.
> - **Phase 2**: Event file format (`WAIT`, `MOUSE_MOVE x y`, `MOUSE_DOWN_LEFT x y`,
>   `KEY_DOWN code`, etc.). Coordinates are Ruffle viewport pixels ÷ `scale_factor` from
>   `test.toml` → logical Flash stage pixels. C multiplies by 20 for twips.
> - **Phase 3**: `input_events_load(argv[1])` in `swf_core.c`; per-tick pump delivers
>   events before `ng_advanceSprites`; `Wait` tokens map to tick boundaries.
> - **Phase 4**: `KeyState keys` in `SWFAppContext` (`uint8_t down[256]`,
>   `last_key_down`); per-tick edge-flag reset; `_xmouse`/`_ymouse` read from
>   `mouse.stage_x / 20.0f`.
>
> No tests pass from infrastructure alone — it unlocks Phases 3–5 of this plan.

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

Per-button state machine: `button_state` field on `DisplayObject` (0=idle, 1=over, 2=down, 3=outdown) — already defined in `tag.c`'s graphics-mode implementation.

### Hit testing

After input-event-injection.md Phase 0, `hit_test.c` is compiled into trace builds and
`shape_data`/`transform_data` from `draws.h` are available in `SWFAppContext`. The
existing `hit_test_shape()` infrastructure does full triangle-level hit testing, identical
to graphics mode — no AABB approximation is needed.

Mouse coordinates: Ruffle's `input.json` positions are in viewport pixels.
`verify_output.py` (input-event-injection.md Phase 1) divides by `scale_factor` from
`test.toml` (defaults to 1.0). C stores `mouse.stage_x/y` in twips (× 20). `_xmouse`/
`_ymouse` return `stage_x / 20.0f`. Only `mouse_pos_with_scale_factor` uses a non-1.0
scale factor; all button tests use the default.

The button state machine already implemented in `tag.c` for graphics mode (hit-test →
state transition → `onPress`/`onRelease`/etc. dispatch) is unconditionally available in
trace builds after Phase 0, since the button logic is not guarded by `#ifndef NO_GRAPHICS`
— only the render calls are.

### AS2 event handlers

When a button transitions:
1. Fire the matching `ButtonAction` conditions (DoAction-style)
2. Call AS2 handler if set: `onRollOver`, `onRollOut`, `onPress`, `onRelease`, `onReleaseOutside`

AS2 handlers are stored as properties on the button's MovieClip instance:
```c
// Dispatch AS2 handler for button DisplayObject at display_list[depth]:
void dispatch_button_event(SWFAppContext* app_context, DisplayObject* obj, const char* handler_name) {
    // Look up handler_name property on obj's AS object
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

### Prerequisite (input-event-injection.md Phases 0–4)

See `SWFRecompDocs/plans/input-event-injection.md` for full details. Summary:

| File | Change |
|------|--------|
| `SWFModernRuntime/include/libswf/swf.h` | Remove `NO_GRAPHICS` guards from `Character`/`DisplayObject`/`MouseState`; add `KeyState` |
| `SWFModernRuntime/src/libswf/tag_stubs.c` | **DELETED** — merged into `tag.c` |
| `SWFModernRuntime/src/libswf/tag.c` | Unconditional tag logic; `#ifndef NO_GRAPHICS` around render calls only |
| `SWFModernRuntime/src/libswf/swf_core.c` | Event pump: load, tick pump, deliver; per-tick edge-flag reset |
| `ruffle-tests/verify_output.py` | `preprocess_input_json()`, pass event file as `argv[1]`, copy `hit_test.c`/`.h` |

### Phase 1 (tag.c + swf.h)

| File | Changes |
|------|---------|
| `SWFModernRuntime/include/libswf/swf.h` | Add `xmin`/`xmax`/`ymin`/`ymax` to `Character.shape` variant; add `width_twips`/`height_twips` to `Character.button` variant |
| `SWFModernRuntime/src/libswf/tag.c` | Store shape bounds in `tagDefineShape`; compute button hit bounds in `tagDefineButton`; call up-state frame func on button placement; `_parent` SWF5 vs SWF6 resolution; `_width`/`_height` from button hit bounds |

### Phase 2 (infrastructure)

> Superseded. See `SWFRecompDocs/plans/input-event-injection.md`.

### Phase 3 (mouse events)

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/libswf/tag.c` | Confirm button state machine + hit testing runs in NO_GRAPHICS trace builds after Phase 0; ButtonAction condition dispatch |
| `SWFModernRuntime/src/actionmodern/action.c` | `MovieClip.prototype.enabled = true` default; AS2 handler dispatch (call onPress etc from C) |

### Phase 4 (key events)

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | `Key` global object: addListener, removeListener, isDown, getCode, getAscii |
| `SWFModernRuntime/src/libswf/swf_core.c` | Key listener dispatch; button key-press condition dispatch |

### Phase 5 (focus)

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | `Selection` global object; focus state; Tab focus cycle |
| `SWFModernRuntime/src/libswf/tag.c` | Per-display-object `has_focus` flag; focus traversal |

---

## Design Decisions

1. **Button children in NO_GRAPHICS display list**: Reuse the existing `ng_current_display_idx`
   nesting mechanism (already used for sprites). Button state 0 (up) is always initialized on
   placement; if state changes later (Phase 3), swap display children.

2. **Event delivery via argv[1]** (from input-event-injection.md): `verify_output.py`
   pre-processes `input.json` to a line-based text file and passes its path as `argv[1]`.
   The binary loads it at runtime with `fgets`/`sscanf`. This replaces the earlier
   `events.c` compile-time generation approach.

3. **Button _width from hit shape**: Use the hit shape's AABB (not the visible shape's bounds).
   This matches Flash behavior. Phase 1 uses a simple AABB lookup; Phase 3 refines with
   transforms if needed.

4. **Key listener ordering**: Flash dispatches key events AFTER the focused button's own
   `onKeyDown`/`onKeyUp` handlers. `Key.addListener` subscribers fire after the focused object.
   This ordering must be exact for `button_key_events` to pass.

5. **Mouse coordinate system** (resolved in input-event-injection.md): `input.json`
   coordinates are Ruffle viewport pixels. `verify_output.py` divides by `scale_factor`
   (from `test.toml`, default 1.0) → logical Flash stage pixels. C stores in twips (× 20)
   for `hit_test.c`. `_xmouse`/`_ymouse` return `stage_x / 20.0f`. Only
   `mouse_pos_with_scale_factor` has `scale_factor ≠ 1.0`; all button tests use 1.0.

6. **`root_button_mode` deferred**: This test needs `createEmptyMovieClip` + `loadMovie` +
   `_lockroot` to work correctly. It will only become fixable once those features are implemented
   as part of the MovieClip Methods plan.
