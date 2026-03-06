# Mouse Events Advanced Plan

## Overview

Advanced mouse event infrastructure needed to unblock focus, tab ordering, hit testing, and stage property tests. The core mouse event system works (5/5 basic tests pass), but advanced features are missing.

**Blocks these plans:**
- FOCUS_SYSTEM_PLAN (3 of 4 remaining tests)
- TAB_ORDERING_PLAN (events_mouse)
- STAGE_FRAME_PROPS_PLAN Phase 9 (frame_size_translated_positive/negative)
- HIT_TESTING_PLAN (hittest_morph_input, text_blocks_clicks)
- CLONE_DUPLICATE_PLAN (clip_event_propagation_order)
- BUTTON_PLAN (root_button_mode partially)
- TELLTARGET_PLAN (string_paths_eval — button dispatch)

**Tests directly unblocked:**
| Test | Before | After | Status |
|------|--------|-------|--------|
| `focus_mouse` | 8/45 | **45/45** | PASS (Phase 1) |
| `button_keypress_vs_textinput` | 3/4 | **4/4** | PASS (Phase 6) |
| `frame_size_translated_positive` | 20/21 | **21/21** | PASS (Phase 4) |
| `frame_size_translated_negative` | 20/21 | **21/21** | PASS (Phase 4) |
| `focus_mouse_rollout` | 1/4 | **4/4** | PASS (Phase 2c) |
| `focus_keyboard_press` | 5/60 | ~15/60 | Blocked (Phase 2+3) |
| `tab_ordering_events_mouse` | 19/65 | ~19/65 | Blocked (Phase 2+3) |
| `tab_ordering_automatic_order_same_position` | 9/12 | **12/12** | PASS (Phase 5) |

---

## Current Infrastructure

### What Works
- `MouseState` in `SWFAppContext->mouse`: tracks `stage_x/y`, `button_down`, `clicked/released/moved` edge flags
- Button state machine (idle/over/down/outdown) with full transition table in `tag.c` lines 927-1110
- Shape hit-testing via triangulated shapes (`hit_test_shape` in `hit_test.h`)
- Clip event dispatch: MOUSE_DOWN/UP/MOVE global events fire on all clips
- CLIP_EVENT_PRESS/RELEASE dispatch with bounding box hit-test
- Button actions dispatch in parent MC context
- `actionMouseClickFocus`: basic focus acquisition on mouse down
- `actionAdvanceTabFocus`: Tab key focus navigation
- `actionFlushDeferredRollEvents`: deferred roll queue (partially implemented)
- Event pumping via pre-processed event files (`input_events_load/deliver/pump_tick`)

### Key Files
- `SWFModernRuntime/src/libswf/swf_core.c` — frame loop, event pumping, button state updates
- `SWFModernRuntime/src/libswf/tag.c` — button state machine, clip event dispatch, hit testing
- `SWFModernRuntime/src/actionmodern/action.c` — AS2 event handlers, focus management, roll dispatch
- `SWFModernRuntime/include/libswf/hit_test.h` — shape hit-test functions

### Frame Loop Event Order (swf_core.c lines 506-595)
1. Sprite advancement + root frame script execution
2. Frame script execution (if `is_playing` or `manual_next_frame`)
3. Deferred rollOver/rollOut flushing (from programmatic focus changes)
4. Input event delivery (all queued events for this tick)
5. Button state re-evaluation (for _visible/_enabled changes during scripts)
6. Goto catch-up
7. Deferred sprite initialization (3-phase ordering)

---

## Phase 1: Text Field Hit Testing (focus_mouse)

**Goal:** Mouse clicks on text fields set focus. `focus_mouse` test: 0/46 → ~30/46.

### What's Needed

When `EV_MOUSE_DOWN_LEFT` fires, the click dispatch must check if the click point falls on a text field. If so, focus that text field.

### Implementation

1. **Text field bounds tracking** — Each text field already has position/size from DefineEditText tag data. Add a function `hit_test_text_field(display_list, mouse_x, mouse_y)` that:
   - Iterates display list entries
   - For entries with `MC_IS_TEXTFIELD` flag, computes AABB from placement transform + edit text bounds
   - Returns the topmost (highest depth) text field under the mouse point, or NULL

2. **Focus on click** — In `actionMouseClickFocus()` (action.c), after existing button focus logic:
   - Call `hit_test_text_field()` to find clicked text field
   - If found, set as focused element
   - If not found and click is on empty area, clear focus (Focus at: null)

3. **Focus change traces** — The test expects `Focus at: _level0.text` traces. Verify the focus change dispatch already emits these (likely from `Selection.onSetFocus` broadcast).

### Test Expectations (focus_mouse key lines)
```
Focus at: _level0.text         // Click on text field → focus
Focus at: null                 // Click on empty area → unfocus
Focus at: _level0.text         // Click text field again → refocus
_level0.clip.onPress           // Click on clip with onPress handler
_level0.button.onPress         // Click on button
```

### Files to Modify
- `action.c`: `actionMouseClickFocus()` — add text field hit-test path
- `tag.c` or `action.c`: new `hit_test_text_field()` function

---

## Phase 2: Dynamic MC Roll Dispatch + Focus Events (focus_mouse_rollout, focus_keyboard_press partial)

**Goal:** Fire onRollOver/onRollOut on dynamic MCs when mouse enters/leaves, and fire onSetFocus/onKillFocus on focus transitions. `focus_mouse_rollout`: 0/5 → 5/5. `focus_keyboard_press`: 0/61 → ~30/61.

### What's Needed

Currently button state transitions happen in `tag.c` but only fire button-record actions (compiled clip_actions). Dynamic MC properties (`mc.onRollOver`, `mc.onRollOut`) are not dispatched when the mouse rolls over/out of MCs with these handlers.

### Implementation

#### 2a. Dynamic MC rollover/rollout tracking

1. **Track "hovered MC"** — Add `g_hovered_mc` global (MovieClip*) in action.c. On mouse move:
   - Hit-test all dynamic MCs with onPress/onRelease/onRollOver/onRollOut handlers
   - If the topmost hit MC changes from previous `g_hovered_mc`:
     - Fire `onRollOut` on old MC (if it had one)
     - Fire `onRollOver` on new MC (if it has one)
     - Update `g_hovered_mc`

2. **Dispatch function** — `actionDispatchDynamicRollEvents(app_context, mouse_x, mouse_y)`:
   - Called from `swf_core.c` during `EV_MOUSE_MOVE` handling
   - Hit-tests all MCs in depth order (front to back)
   - Handles the rollover/rollout state transition

#### 2b. SetFocus / KillFocus handlers

1. **onSetFocus dispatch** — When focus changes (Tab press, mouse click, programmatic):
   - Fire `onKillFocus` on old focused MC (if any), with `newFocus` argument
   - Fire `onSetFocus` on new focused MC (if any), with `oldFocus` argument
   - Broadcast `Selection.onSetFocus(oldFocus, newFocus)` to listeners

2. **Integration points**:
   - `actionAdvanceTabFocus()` — after computing new focus target
   - `actionMouseClickFocus()` — after determining new focus from click
   - `Selection.setFocus()` AS2 method — programmatic focus change

#### 2c. Roll events on focus change (deferred queue)

When focus changes via Tab or programmatic means (not mouse), the button under the mouse may need roll state updates:
- Previous focused button: if mouse is NOT over it, fire onRollOut
- New focused button: if mouse IS over it, fire onRollOver

This is the "deferred roll queue" — `actionFlushDeferredRollEvents()` already exists but needs completion.

### Test Expectations (focus_mouse_rollout key lines)
```
Focus at: _level0.text         // Text field focused
Focus at: null                 // Focus cleared
_level0.clip.onPress           // Press while unfocused
_level0.clip.onRollOut         // Roll out after focus loss
```

### Files to Modify
- `action.c`: new `actionDispatchDynamicRollEvents()`, `g_hovered_mc` tracking
- `action.c`: `actionAdvanceTabFocus()` — add SetFocus/KillFocus dispatch
- `action.c`: `actionMouseClickFocus()` — add SetFocus/KillFocus dispatch
- `swf_core.c`: call roll dispatch during mouse move events

---

## Phase 3: Button Key Simulation + Tab Roll Events (focus_keyboard_press, tab_ordering_events_mouse)

**Goal:** Enter/Space on focused button fires onPress/onRelease. Tab transitions fire roll events. `focus_keyboard_press`: ~30/61 → 61/61. `tab_ordering_events_mouse`: 0/65 → 65/65.

### What's Needed

#### 3a. Button key simulation

When a button or MC is focused and Enter (key 13) or Space (key 32) is pressed:
1. Fire `onPress` on the focused MC
2. On key release, fire `onRelease` on the focused MC
3. This simulates a mouse click on the focused button

#### 3b. Tab roll events

When Tab advances focus:
1. Re-evaluate button state for the previously-focused MC based on current mouse position
2. Fire `onRollOut` on previously-focused MC if it was in "over" state
3. Fire `onRollOver` on newly-focused MC based on current mouse position
4. These fire BEFORE `onSetFocus`

**Event ordering for Tab press:**
1. `onRollOut` on previous focus (if applicable)
2. `onRollOver` on new focus (if mouse is over it)
3. `onKillFocus` on previous focus
4. `onSetFocus` on new focus

### Implementation

1. **Key simulation in focus handler** — In `actionDispatchKeyDownToFocused()`:
   - If focused MC is a button or has `onPress` handler, and key is Enter/Space:
     - Call `onPress` on focused MC
     - Set `g_key_simulated_press_mc` for release matching

2. **Key up simulation** — In `actionDispatchKeyUpToFocused()`:
   - If `g_key_simulated_press_mc` is set and key matches:
     - Call `onRelease` on that MC
     - Clear `g_key_simulated_press_mc`

3. **Tab roll event ordering** — In `actionAdvanceTabFocus()`:
   - BEFORE changing focus:
     - Compute new focus target
     - Fire onRollOut on old focus if mouse not over it
   - Change focus
   - AFTER changing focus:
     - Fire onRollOver on new focus if mouse is over it
     - Fire onKillFocus on old
     - Fire onSetFocus on new

### Test Expectations (focus_keyboard_press key lines)
```
_level0.clip.onKeyDown: 13     // Enter key down
_level0.clip.onPress: 13       // Simulated press on focused button
_level0.clip.onRelease: 13     // Simulated release
Tab pressed
Focus at: _level0.clip
_level0.clip.onRollOver        // Button receives rollover on focus
_level0.clip.onSetFocus        // SetFocus handler fires
```

### Test Expectations (tab_ordering_events_mouse key lines)
```
Tab pressed
rollOver                       // onRollOver on button
button.onRollOver
button.onSetFocus              // SetFocus after roll events
Escape pressed
rollOut                        // onRollOut as user moves away
button.onRollOut
```

### Files to Modify
- `action.c`: key simulation in `actionDispatchKeyDownToFocused()`/`actionDispatchKeyUpToFocused()`
- `action.c`: tab roll event ordering in `actionAdvanceTabFocus()`

---

## Phase 4: Named Shape Scriptability (frame_size_translated_positive/negative)

**Goal:** Named shapes respond to onPress. Both tests: 20/21 → 21/21.

### What's Needed

The tests have named shapes (e.g., "shape1") that fire `onPress` when clicked. Currently shapes are non-scriptable (`ng_isScriptableChar()` returns 0 for shapes).

### Implementation

1. **Recompiler: emit instance names for shapes** — In `action.cpp`, when `PlaceObject2` places a shape with an instance name, emit `tagSetInstanceName()` for it (may already happen; verify).

2. **Runtime: shape hit-test in press dispatch** — In the press dispatch path:
   - After checking buttons and sprites, also check named shapes
   - Use `hit_test_shape()` (already exists) with the shape's triangulated data
   - If hit, dispatch `onPress` to the shape's parent MC with the shape name

3. **Alternative approach** — If shapes are wrapped as display objects with instance names, we may just need to add them to the hit-test candidate list in `dispatch_clip_event_press`. The actual onPress would fire on the parent MC (since shapes aren't MCs themselves).

### Test Expectations
```
Pressed shape1                 // onPress fired on named shape
```

### Difficulty
Medium — need to understand exactly how Flash makes shapes scriptable. May need to check if the shape's parent MC has an `onPress` handler that references the shape, or if the shape itself becomes a scriptable pseudo-MC.

### Files to Modify
- `tag.c`: extend `dispatch_clip_event_press` to include named shapes
- Possibly `action.cpp` (recompiler): verify shape instance name emission

---

## Phase 5: Highlight Bounds for Tab Sort (tab_ordering_automatic_order_same_position)

**Goal:** Fix tab sort order when objects share position. Test: 9/12 → 12/12.

### What's Needed

Current tab sort uses registration point (`mc->x`, `mc->y`) for ordering. When multiple objects have the same registration point, the sort is wrong. Flash/Ruffle uses "highlight bounds" — the bounding box of the visual content — as the sort key.

### Current Implementation

`compute_min_visual_pos()` (action.c lines 37854-37880):
- Walks sprite children, finds minimum `(y, x)` position
- Uses child registration points, not visual bounds
- Sort formula: `6*y + x` (line 38046)

### Implementation

1. **Compute visual bounds** — Replace `compute_min_visual_pos()` with `compute_highlight_bounds()`:
   - For each child in the sprite's display list:
     - Get the shape bounds (from `shape_data[]` arrays in `draws.h`)
     - Apply the child's placement transform
   - Compute the union AABB of all transformed child bounds
   - Return the top-left corner `(min_x, min_y)` as the sort key

2. **Shape bounds extraction** — Each shape has triangulated data. The bounds can be computed by finding min/max of all vertex positions in the triangulated data, or (better) by storing pre-computed bounds in the generated code.

3. **Update sort key assignment** — In `tab_collect_recursive()`, use `compute_highlight_bounds()` instead of `compute_min_visual_pos()` for sprites.

### Test Expectations
The test has 8 nested clips with Tab pressed 12 times. Three focus transitions are in wrong order because clips at the same position sort by registration point instead of visual bounds.

### Difficulty
Medium — needs access to shape bounds data from the generated `draws.h`, which may not be readily available at runtime. May need to add bounds arrays to the generated code or compute from triangulated shape data.

### Files to Modify
- `action.c`: replace `compute_min_visual_pos()` with bounds-based computation
- Possibly generated code: add pre-computed shape bounds

---

## Phase 6: TextField onChanged Callback (button_keypress_vs_textinput)

**Goal:** Fire `onChanged` when text field content changes. Test: 3/4 → 4/4.

### What's Needed

When text input modifies a text field's content (typing, `replaceText`, `replaceSel`), the `onChanged` callback should fire.

### Implementation

1. **Hook text modification** — After any text modification (typing via `EV_TEXT_INPUT`, `replaceSel()`, `replaceText()`):
   - Look up the text field's `onChanged` property in its `dynamic_props`
   - If it's a function, invoke it with `this` = the text field's MC

2. **`replaceSel` / `replaceText` methods** — These are declared as function pointers (action.c lines 6131-6132) but may not have full implementations yet. Ensure they modify the text property and trigger `onChanged`.

3. **Text input handler** — In the `EV_TEXT_INPUT` handler in `swf_core.c`:
   - After inserting the character into the focused text field
   - Call `actionDispatchTextFieldOnChanged(app_context, textfield_mc)`

### Test Expectations (button_keypress_vs_textinput)
```
keyPress 'a' fired              // Key press handled by button
text.onChanged                  // 'b' typed into text field triggers onChanged
```

### Files to Modify
- `action.c`: new `actionDispatchTextFieldOnChanged()` function
- `swf_core.c`: call onChanged after text input events
- `action.c`: hook onChanged into `replaceSel` / `replaceText` paths

---

## Implementation Status

| Phase | Status | Tests | Result |
|-------|--------|-------|--------|
| Phase 1: TF hit-testing | **DONE** | focus_mouse | 45/45 PASS |
| Phase 4: Frame rect offset | **DONE** | frame_size_translated_positive | 21/21 PASS |
| Phase 4: Frame rect offset | **DONE** | frame_size_translated_negative | 21/21 PASS |
| Phase 6: TF onChanged | **DONE** | button_keypress_vs_textinput | 4/4 PASS |
| Phase 2c: Roll on focus change | **DONE** | focus_mouse_rollout | 4/4 PASS |
| Phase 2+3: Key sim + Tab rolls | **BLOCKED** | focus_keyboard_press | ~15/60 |
| Phase 3: Tab roll events | **BLOCKED** | tab_ordering_events_mouse | ~19/65 |
| Phase 5: Highlight bounds | **DONE** | tab_ordering_automatic_order_same_position | 12/12 PASS |

### Completed Changes
- **Phase 1** (commit e7974be4): Text field bounds in `mc_get_pixel_aabb_ng`, text field exclusion from MC press/release/roll events, focus event ordering fix.
- **Phase 4** (commit 12d7c2c2): Recompiler emits `FRAME_X_MIN_TWIPS`/`FRAME_Y_MIN_TWIPS`, runtime adds offset to mouse coordinates. Also added `#include "constants.h"` to `swf_core.c`.
- **Phase 6** (commit c6722fa5): `EV_TEXT_INPUT` handler with button keyPress suppression gate, `actionTextFieldInput()` function with restrict filter/maxChars/onChanged callback.

### Remaining Work
**Phase 2 (partial)** requires: Dynamic MC rollover/rollout tracking (`g_hovered_mc`), `onRollOver`/`onRollOut` dispatch during mouse move, `onSetFocus`/`onKillFocus` MC handlers (distinct from Selection broadcast). Phase 2c (roll on focus change) is DONE. Remaining 2a/2b are medium-large effort (~100-150 lines).

**Phase 3** requires Phase 2 and additionally: Enter/Space key simulation on focused MC (onPress/onRelease), correct event ordering during Tab (rollout → rollover → killfocus → setfocus), integration with button state machine. Large effort but no external dependencies.

### Completed Changes
- **Phase 2c** (this session): `queue_hover_rollout_on_focus_change()` in action.c — queues deferred rollOut events when focus changes and there's a hovered MC. Called from `actionMouseClickFocus()` when `g_focused_mc` changes.
- **Phase 5** (this session): Replaced `compute_min_visual_pos()` with `compute_highlight_bounds()` — recursive AABB computation using `ng_getCharBounds()` for shape bounds in world coordinates. Fixed min_x/min_y tracking to be independent (AABB union, not single-point min). Added scale propagation through `tab_collect_recursive`. Added twip rounding (`roundf(x*20)/20`) to eliminate float precision issues in dedup.

---

## Regression Guard

After any change, verify these mouse/focus tests remain PASS:
```bash
python3 ruffle-tests/verify_output.py --test=mouse_pos --diff --verbose
python3 ruffle-tests/verify_output.py --test=mouse_pos_with_scale_factor --diff --verbose
python3 ruffle-tests/verify_output.py --test=mouse_events_visible_enabled --diff --verbose
python3 ruffle-tests/verify_output.py --test=click_block --diff --verbose
python3 ruffle-tests/verify_output.py --test=focus_root_movie --diff --verbose
python3 ruffle-tests/verify_output.py --test=focusrect_focuslost --diff --verbose
python3 ruffle-tests/verify_output.py --test=movieclip_focusenabled --diff --verbose
python3 ruffle-tests/verify_output.py --test=tab_ordering_events --diff --verbose
python3 ruffle-tests/verify_output.py --test=tab_ordering_tabbable --diff --verbose
python3 ruffle-tests/verify_output.py --test=tab_ordering_movieclip_enabled_default --diff --verbose
python3 ruffle-tests/verify_output.py --test=tab_ordering_children --diff --verbose
```
