# Drag and Drop Implementation Plan
<!-- TESTS: drag_drop, drag_over_from_outside, drag_over_without_startdrag, mouse_hover_events_while_dragging -->

Last updated: 2026-02-20

## Status: NOT STARTED

Prerequisites: input-event-injection.md Phases 0–7 COMPLETE (mouse state tracked, hit testing
available). This plan adds `startDrag`/`stopDrag` MovieClip methods and `_droptarget` property.

---

## Overview

4 tests cover Flash's drag-and-drop system:

1. `startDrag(clip, lockCenter, left, top, right, bottom)` — begin dragging a clip
2. `stopDrag()` — stop dragging, set `_droptarget` on the dragged clip
3. `_droptarget` — path string of the clip under the dragged clip's hotspot when `stopDrag` is called
4. `mouse_hover_events_while_dragging` — mouse hover events still fire on non-dragged clips

These are straightforward to implement since our event pump already has full mouse state.
The tests have minimal expected output, suggesting passing them is not complex.

---

## Test Inventory

| Test | Lines | Input | Key behavior |
|------|-------|-------|--------------|
| `drag_drop` | 9 | MouseDown+Move+Up×5 | 5 drag sequences; `_droptarget` traced on stopDrag |
| `drag_over_from_outside` | 1 | MouseMove+Down+Up | Just "OK" — drag from outside stage succeeds |
| `drag_over_without_startdrag` | 1 | MouseDown+Up | Just "OK" — mouseDown without startDrag doesn't crash |
| `mouse_hover_events_while_dragging` | 1 | MouseDown+Move | Just "startDrag" — hover events fire during drag |

### `drag_drop` expected output:
```
dragging start
dragging done: /drop1       ← _droptarget when dropped on clip "drop1"
dragging start
dragging done:              ← dropped on empty space
dragging start
dragging done: /drop2
dragging start
dragging done: /drop2/drop3 ← nested clip path
dragging start
dragging done: /drop2
```

`_droptarget` uses the `/` slash path notation (SWF4 style), not dot notation.

---

## Phase A: `startDrag` / `stopDrag` Methods

### `startDrag(lockCenter, left, top, right, bottom)` — called on the clip being dragged

When called:
1. Set the global dragged clip: `g_drag_clip_depth = this_clip_depth`
2. Store drag parameters: `g_drag_lock_center`, `g_drag_bounds` (optional bounding rect)
3. If `lockCenter=true`, the clip's center tracks the mouse (not the offset at click)
4. If `lockCenter=false`, the clip's origin offset from click position is maintained

In trace mode, we don't actually MOVE the clip (no rendering). `startDrag` just records that
dragging has started. The clip's position is not updated on mouse move in trace mode — only
the `_droptarget` detection on `stopDrag` matters.

```c
// Global drag state (in tag.c or swf_core.c):
static size_t g_drag_clip_depth = (size_t)-1;
static int g_drag_lock_center = 0;
```

### `stopDrag()` — called on any clip (usually the dragged clip)

When called:
1. Find which clip is under the dragged clip's hotspot (mouse position)
2. Set `dragged_clip._droptarget` to the path of that clip (slash notation)
3. Clear `g_drag_clip_depth`

```c
void action_stop_drag(SWFAppContext* app_context)
{
    if (g_drag_clip_depth == (size_t)-1) return;

    // Find topmost clip under mouse (excluding the dragged clip itself)
    size_t target_depth = hit_test_find_clip(app_context);

    // Build slash path string for target clip
    char path[256] = "";
    if (target_depth != (size_t)-1) {
        build_slash_path(target_depth, path, sizeof(path));
    }

    // Set _droptarget on the dragged clip's MC instance
    set_mc_property_string(g_drag_clip_depth, "_droptarget", path);

    g_drag_clip_depth = (size_t)-1;
}
```

### `_droptarget` property

Read-only MovieClip property (AS GetMember `"_droptarget"`). Returns the string set by
`stopDrag`. Stored as a dynamic property on the MC instance.

### Slash path format

`_droptarget` uses `/clip_name` notation (SWF4 path style):
- Root clip "drop1": `/drop1`
- Nested clip "drop3" inside "drop2": `/drop2/drop3`
- Empty (dropped on stage): empty string `""`

Build the path by walking the display list for `target_depth`, prepending parent paths:
```c
void build_slash_path(size_t depth, char* out, size_t out_size)
{
    // For root-level: "/instance_name"
    // For nested: walk parent chain
    const char* name = display_list[depth].instance_name;
    if (name && name[0]) {
        snprintf(out, out_size, "/%s", name);
    }
    // TODO: parent chain for nested clips
}
```

---

## Phase B: Hit Test for Drop Target

On `stopDrag`, find the topmost clip (excluding dragged clip) under `mouse.stage_x/y`.

Use the existing `hit_test.c` infrastructure. The key difference from button hit-testing:
- Check ALL MovieClips (not just buttons)
- Exclude the dragged clip itself
- The "hit" for drop target uses AABB (bounding box) of the clip, not exact shape

Simple implementation: use character bounds from `ng_getCharBounds`:
```c
size_t hit_test_find_clip(SWFAppContext* app_context)
{
    float mx = app_context->mouse.stage_x;  // in twips
    float my = app_context->mouse.stage_y;
    for (size_t i = max_depth; i >= 1; i--)
    {
        if (i == g_drag_clip_depth) continue;  // exclude dragged clip
        DisplayObject* obj = &display_list[i];
        if (obj->char_id == 0) continue;
        // Use character bounds + transform for AABB hit test
        s32 xmin, xmax, ymin, ymax;
        if (!ng_getCharBounds(obj->char_id, &xmin, &xmax, &ymin, &ymax)) continue;
        // Apply transform to bounds (simplified: assume uniform scale+translate)
        float tx, ty;
        ng_getTransformXY(i, &tx, &ty);
        float w = (float)(xmax - xmin);
        float h = (float)(ymax - ymin);
        if (mx >= tx * 20 + xmin && mx <= tx * 20 + xmin + w &&
            my >= ty * 20 + ymin && my <= ty * 20 + ymin + h)
            return i;
    }
    return (size_t)-1;
}
```

---

## Phase C: `mouse_hover_events_while_dragging`

Expected output: just `"startDrag"`.

The SWF:
1. Calls `startDrag()` → traces "startDrag"
2. Moves mouse over a clip during drag

If `startDrag()` simply traces and the rest is just mouse moves with no further output,
this test may pass once `startDrag()` is implemented as an AS method (even if it does nothing
beyond tracing). Verify by running after Phase A.

---

## Phase D: `drag_over_from_outside` and `drag_over_without_startdrag`

Both expect just `"OK"`. These test that:
- Dragging from outside the stage boundary doesn't crash
- `mouseDown` without a preceding `startDrag` doesn't crash

These should pass once the basic mouse event infrastructure works (no special handling needed
— they just verify the binary doesn't crash or assert). May already pass with current
Phase 0–7 infrastructure. **Run these first** before implementing anything.

---

## Implementation in ActionScript Runtime

`startDrag` and `stopDrag` are MovieClip methods emitted by the recompiler as `actionCall`
on the MC target. They need to be implemented as built-in C functions in `action.c`:

```c
// In action.c, MovieClip method table:
{ "startDrag", builtin_mc_startDrag },
{ "stopDrag",  builtin_mc_stopDrag  },
```

`startDrag` signature: `clip.startDrag([lockCenter [, left, top, right, bottom]])`:
```c
static ActionVar builtin_mc_startDrag(SWFAppContext* app_context, ActionVar* args, u32 argc, ...)
{
    // arg 0 = lockCenter (bool, optional)
    // args 1-4 = left, top, right, bottom (optional bounding rect)
    g_drag_clip_depth = ...; // current MC depth from this_obj context
    g_drag_lock_center = (argc > 0 && is_truthy(&args[0]));
    // ... store bounds
    return undefined_var();
}
```

`stopDrag` is a global MovieClip method (can be called on any clip):
```c
static ActionVar builtin_mc_stopDrag(SWFAppContext* app_context, ActionVar* args, u32 argc, ...)
{
    action_stop_drag(app_context);
    return undefined_var();
}
```

---

## Implementation Order

```
Phase D (verify drag_over tests pass as-is) ─────────── drag_over_from_outside, drag_over_without_startdrag
Phase A (startDrag/stopDrag methods) ────────────────── mouse_hover_events_while_dragging
Phase B (hit test for drop target) ─────────────────── drag_drop
```

---

## Estimated Test Fixes

| Phase | Tests Fixed |
|-------|------------|
| D (verify) | `drag_over_from_outside`, `drag_over_without_startdrag` (may already pass) |
| A | `mouse_hover_events_while_dragging` |
| A + B | `drag_drop` |

---

## Files to Modify

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | `builtin_mc_startDrag()`, `builtin_mc_stopDrag()`, `_droptarget` property read |
| `SWFModernRuntime/src/libswf/tag.c` | `hit_test_find_clip()`, `build_slash_path()`, drag state globals |
| `SWFModernRuntime/include/libswf/tag.h` | Declare new functions |

---

## Relationship to Other Plans

- **MOVIECLIP_PLAN.md**: `startDrag`/`stopDrag` are MovieClip methods and may be tracked there.
  Cross-reference when implementing.
- **HIT_TESTING_PLAN.md**: The drop target hit test reuses bounding-box hit testing infrastructure
  from that plan. The AABB approach is sufficient for `_droptarget` (Flash spec uses hotspot
  of dragged clip's center/origin, not exact shape).
