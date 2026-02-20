# Mouse Events Implementation Plan
<!-- TESTS: mouse_pos, mouse_pos_with_scale_factor, mouse_events, mouse_events_visible_enabled, click_block -->

Last updated: 2026-02-20

## Status: NOT STARTED

Prerequisites: input-event-injection.md Phases 0–7 COMPLETE (mouse state tracked, hit testing
included in trace builds, button state machine runs). This plan adds the AS-level bindings
and clip-level event dispatch that sit on top of that infrastructure.

---

## Overview

5 tests cover mouse position properties and clip-level mouse event dispatch. They test:

1. `_xmouse`/`_ymouse` built-in properties on root and MovieClip instances
2. `onClipEvent(mouseDown/mouseUp/mouseMove)` dispatch to all clips
3. AS2 `clip.onMouseDown`/`clip.onMouseUp`/`clip.onMouseMove` method dispatch (same delivery)
4. `_visible`/`_enabled` flags affecting button event delivery
5. Z-order hit testing blocking lower clips from receiving click events

---

## Test Inventory

| Test | Lines | Input | Key behavior |
|------|-------|-------|--------------|
| `mouse_pos` | 666 | 73 MouseMove+Wait | `_root._xmouse`, `_root._ymouse` and transformed clip coordinates per move |
| `mouse_pos_with_scale_factor` | 261 | same, scale 2.0 | Same but with `scale_factor=2.0` in `test.toml` (verify_output.py halves coords) |
| `mouse_events` | 8 | MouseDown/Up/Move | Button press/release traces including mouse coordinates |
| `mouse_events_visible_enabled` | 12 | MouseMove/Down/Up | rollOver/rollOut/press with `_visible`/`_enabled` toggling |
| `click_block` | 5 | MouseDown × 5 | Click positions traced; overlapping clips block lower ones |

---

## Phase A: `_xmouse` / `_ymouse` Properties

### What they are

`clip._xmouse` and `clip._ymouse` return the mouse position in the **clip's local coordinate
space** (pixels, not twips). For `_root`, they equal `mouse.stage_x / 20.0f` in stage pixels.
For other clips, the position is inverse-transformed by the clip's matrix.

`mouse_pos` creates several clips with different transforms (rotations, scales, translations)
and reads `clip._xmouse`/`clip._ymouse` on each. The expected output `zs`, `ip`, `fp`,
`s42fp`, `s133fp`, `s133fpr15` suggest clips named `zs` (zoom-scale), `ip` (inner-position),
`fp` (far-position), and clips with 42° and 133° rotation plus translate.

### Implementation — action.c

`_xmouse` and `_ymouse` are MovieClip built-in read-only properties. They are accessed via:
1. `ActionGetProperty` with property index 0 (`_xmouse=0`, `_ymouse=1` in some encodings)
   — actually indexes 14 (`_xmouse`) and 15 (`_ymouse`) in SWF4 property encoding
2. `GetMember` on a MovieClip target with member name `"_xmouse"` / `"_ymouse"`

For `_root._xmouse` (stage coordinates):
```c
// In action.c getMovieClipProperty / getClipProperty:
case PROP_XMOUSE:  // property index for _xmouse
    result.type = ACTION_STACK_VALUE_F64;
    result.data.numeric_value = app_context->mouse.stage_x / 20.0;  // twips → pixels
    return result;
case PROP_YMOUSE:
    result.data.numeric_value = app_context->mouse.stage_y / 20.0;
    return result;
```

For `clip._xmouse` (clip local coordinates), the mouse position must be inverse-transformed
by the clip's local-to-global matrix. The clip's composed matrix is available via
`ng_getMatrixFromEntry()` (tag.h). The inverse transform:

```c
// Given clip matrix (a, b, c, d, tx, ty) — column-major SWF format:
// stage_x (px) = a*local_x + c*local_y + tx
// stage_y (px) = b*local_x + d*local_y + ty
// Solve for local_x, local_y given stage_x/y:
double det = a*d - b*c;
if (fabs(det) < 1e-10) { local_x = 0; local_y = 0; }
else {
    local_x = (d*(stage_x - tx) - c*(stage_y - ty)) / det;
    local_y = (a*(stage_y - ty) - b*(stage_x - tx)) / det;
}
```

Note: the matrix from `ng_getMatrixFromEntry` is the LOCAL transform (not composed). For
`_xmouse`, Flash applies the FULL composed (parent × local) matrix. Use
`ng_findDisplayEntryIdx` to get the entry, then walk up parent chain composing matrices,
OR use the composed transform stored by `renderer_write_transform` (which is what `hit_test.c`
uses for shape data).

Actually, `mouse_pos` also reports `_root._xmouse` directly (labelled "\_root") which is just
`stage_x / 20`. For nested clips, the simplest correct approach:
- Get the display entry's LOCAL matrix via `ng_getMatrixFromEntry(entry_idx, ...)`
- For `_root`-level clips (no parent transform beyond identity), this is the full transform
- `mouse_pos` places clips directly on `_root`, so no parent composition is needed

### Scale factor

`mouse_pos_with_scale_factor` sets `scale_factor=2.0` in `test.toml`. `verify_output.py` already
divides input.json coords by `scale_factor` before writing the event file. The C side receives
coordinates already in logical stage pixels — no additional handling needed.

### Files changed

- `SWFModernRuntime/src/actionmodern/action.c` — add `_xmouse`/`_ymouse` cases in property
  getter (both SWF property index path and GetMember string path)

---

## Phase B: Global Clip Event Dispatch (onClipEvent/AS2 handlers)

### Two dispatch paths

Flash delivers mouse events to clips via two parallel mechanisms — both must fire:

1. **`onClipEvent(mouseDown/mouseUp/mouseMove)`**: The SWF tag `PlaceObject2WithClipActions`
   stores `ClipAction` structs with event flags. The recompiler already compiles ALL clip event
   types into `clip_action_N()` functions with correct `CLIP_EVENT_MOUSE_DOWN` etc. bitmasks.
   These need to be called when the mouse event fires.

2. **AS2 `clip.onMouseDown`/`clip.onMouseUp`/`clip.onMouseMove` properties**: An ActionScript
   handler set as a property on a MovieClip instance. These are called on ALL clips globally
   when a mouse event fires (not just the hit clip). Different from `onPress`/`onRelease` which
   are hit-tested.

### Dispatch model

`clip_event_propagation_order` (covered by UNLOAD_PLAN.md) shows the ordering:
- All clips receive `onMouseMove`/`onMouseDown`/`onMouseUp` in **reverse depth order**
  (frontmost/deepest first, then shallower)
- This means: depth30 → depth20 → depth10 → Main (for `clip_event_propagation_order`)

### Implementation

In `swf_core.c` `input_events_deliver()`, after updating mouse state, call a new
`dispatch_clip_mouse_event(app_context, event_flag)` function in `tag.c`:

```c
// In tag.c:
void dispatch_clip_mouse_event(SWFAppContext* app_context, uint32_t event_flag)
{
    // Iterate display list in reverse depth order (front-to-back)
    for (size_t i = max_depth; i >= 1; i--)
    {
        DisplayObject* obj = &display_list[i];
        if (obj->char_id == 0) continue;

        // 1. Fire onClipEvent handler if present
        for (size_t a = 0; a < obj->clip_action_count; a++) {
            if (obj->clip_actions[a].event_flags & event_flag)
                obj->clip_actions[a].action(app_context);
        }

        // 2. Fire AS2 handler property if set (onMouseDown/Up/Move)
        // Look up property name on the clip's MC instance
        const char* handler = (event_flag == CLIP_EVENT_MOUSE_DOWN)  ? "onMouseDown"  :
                              (event_flag == CLIP_EVENT_MOUSE_UP)    ? "onMouseUp"    :
                              (event_flag == CLIP_EVENT_MOUSE_MOVE)  ? "onMouseMove"  : NULL;
        if (handler)
            dispatch_as2_handler_on_clip(app_context, obj, handler);
    }
}
```

`dispatch_as2_handler_on_clip(app_context, obj, name)` looks up the named property on the
clip's MovieClip instance and calls it if it's a function. Use `ng_findDisplayEntryIdx` to
get the MC, then `actionCallMethod` or equivalent.

Call from `input_events_deliver`:
```c
case EV_MOUSE_MOVE:
    ms->stage_x = ev->x * 20.0f;
    ms->stage_y = ev->y * 20.0f;
    ms->moved = 1;
    root_movieclip.xmouse = ev->x;
    root_movieclip.ymouse = ev->y;
    dispatch_clip_mouse_event(app_context, CLIP_EVENT_MOUSE_MOVE);
    break;
case EV_MOUSE_DOWN_LEFT:
    ...
    dispatch_clip_mouse_event(app_context, CLIP_EVENT_MOUSE_DOWN);
    break;
case EV_MOUSE_UP_LEFT:
    ...
    dispatch_clip_mouse_event(app_context, CLIP_EVENT_MOUSE_UP);
    break;
```

### Files changed

- `SWFModernRuntime/src/libswf/tag.c` — `dispatch_clip_mouse_event()` + helper
- `SWFModernRuntime/src/libswf/swf_core.c` — call from `input_events_deliver()`
- `SWFModernRuntime/include/libswf/tag.h` — declare `dispatch_clip_mouse_event()`

---

## Phase C: `_visible` / `_enabled` Flags

### What they control

`mouse_events_visible_enabled` expected output:
```
Step 1: rollOver          ← button starts enabled, visible → rollOver fires
Step 2: rollOut           ← moved off
Step 3: rollOver          ← moved back on
Step 4: from onEnterFrame ← clip hidden (_visible=false), onEnterFrame fires but NO rollOver
Step 5: from onEnterFrame ← still hidden
Step 6: press             ← made visible again; mouseDown triggers press
Step 7: releaseOutside    ← mouse moved out while pressed
Step 8: rollOver          ← disabled button (enabled=false): rollOver STILL fires
Step 9: press             ← disabled button can still receive press? (check test)
Step 10: from onEnterFrame
Step 11: from onEnterFrame
Step 12: rollOver
```

Key semantics:
- `_visible = false`: button does NOT receive rollOver/rollOut/press/release
  (hidden clips are invisible AND non-interactive)
- `_enabled = false` on MovieClip: some events still fire (rollOver appears to still fire at
  step 8), others may be suppressed. Read the SWF/test carefully.

### Implementation

In the button state machine (tag.c `tagShowFrame`), before running hit tests:
- Skip clips where `display_list[i]._visible == 0` (already skip for graphics, do same in NO_GRAPHICS path)

For `_enabled`, the button state machine already checks this via `MovieClip.prototype.enabled`
(planned in BUTTON_PLAN.md). When `enabled=false`, transition fires but without the AS2 handlers?
Need to verify exact semantics from test output.

**Note:** `_visible` on DisplayObject is already tracked via the cxform/visibility system.
Check if `ng_getDisplayEntryBounds` or similar tracks visibility. If not, add a `visible`
flag to `DisplayObject` or read it from the AS MC instance.

---

## Phase D: Click Blocking (Z-order)

### What it tests

`click_block` clicks at 5 positions. The expected output traces click positions — suggesting
the SWF has a full-stage button that traces `_xmouse`/`_ymouse` on press. The click_block
test name suggests that overlapping clips block lower clicks.

The 5 clicks are at corners and center: (21,24), (526,23), (22,375), (524,375), (275,195).
These all register ("Clicked at ..."), so the test might just be verifying that each click
region gets the event and traces the coordinates. The "block" may refer to invisible/disabled
areas that DON'T fire (and the test verifies 5 clicks DO fire at those positions).

This likely just requires `_xmouse`/`_ymouse` (Phase A) + the button state machine already
working. No additional implementation needed beyond Phase A.

**Verification:** Run `python3 ruffle-tests/verify_output.py --test=click_block --diff --verbose`
after Phase A is implemented to check.

---

## Implementation Order and Dependencies

```
Phase A (_xmouse/_ymouse) ────────────────────────────── mouse_pos, mouse_pos_with_scale_factor
Phase B (clip mouse events) ──────────────────────────── mouse_events, clip_event_propagation_order
Phase C (_visible/_enabled) ─────────────────────────── mouse_events_visible_enabled
Phase D (click blocking) ─ verify after A ──────────── click_block
```

Phase B has additional dependency in FOCUS_SYSTEM_PLAN.md (focus_mouse uses onMouseDown/Up
on clips). Implement Phase B before starting FOCUS_SYSTEM_PLAN.

---

## Test Fix Estimates

| Phase | Tests Fixed |
|-------|------------|
| A | `mouse_pos`, `mouse_pos_with_scale_factor` |
| B | `mouse_events` (partially), `clip_event_propagation_order` |
| C | `mouse_events_visible_enabled` |
| D | `click_block` (verify after A) |

---

## Relationship to Other Plans

- **FOCUS_SYSTEM_PLAN.md**: depends on Phase B (clip AS2 handler dispatch). `focus_mouse`
  needs `clip.onMouseDown`/`clip.onMouseUp` to fire before focus logic runs.
- **BUTTON_PLAN.md Phase 3**: `_enabled` property semantics (needed for Phase C)
- **UNLOAD_PLAN.md**: covers `clip_event_propagation_order` (included here for context only)
- **HIT_TESTING_PLAN.md**: covers `text_blocks_clicks`, `hittest_morph_input` — both tests
  were marked "deferred indefinitely" but are now unblocked by Phase 0-7 infrastructure.
  Those notes in HIT_TESTING_PLAN.md should be updated.
