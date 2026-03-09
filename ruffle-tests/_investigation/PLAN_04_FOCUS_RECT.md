# Plan 04: Focus Rect Rendering — COMPLETE

**Status**: DONE — all 5 tests passing (41/41 image comparisons)
**Tests unlocked**: `focusrect_focuslost` (1/1), `focusrect_mouse_swf8` (8/8), `focusrect_mouse_swf9` (8/8), `focusrect_swf5` (12/12), `focusrect_swf6` (12/12)

---

## Problem

Focus rectangles (yellow outlines around focused UI elements) don't render. The focus tracking system is fully implemented (Tab cycling, mouse focus, `_focusrect` property), but the visual highlight is not drawn.

---

## Ruffle Reference

Ruffle draws focus rects as:
- **Color**: Yellow (`#FFFF00`)
- **Thickness**: 3 pixels
- **Shape**: Rectangle outline around the focused object's `highlight_bounds()`
- **Implementation**: 4 filled rectangles forming a border (top, bottom, left, right bars)
- **Visibility**: Only when highlight state is `ActiveVisible` (Tab-focused, not mouse-focused)

Source: `~/CC/ruffle/core/src/focus_tracker.rs` lines 58-59, 372-383

---

## Current State

### What Exists
- `g_focused_mc` — pointer to currently focused MovieClip (action.c:19996)
- `mc->focusrect` — `_focusrect` property (float: -1.0 = null/default, 0 = off, 1 = on)
- `actionAdvanceTabFocus()` — Tab key cycling
- `actionMouseClickFocus()` — Mouse click focus
- Focus dispatch system (6/7 focus tests pass trace output)

### What's Missing
- No visual rendering of focus highlight
- No focus bounds calculation for rendering

---

## Implementation

### Step 1: Compute Focus Bounds

The focus rect needs the bounding box of the focused object in stage coordinates (twips).

For MovieClips/Sprites:
- Use the shape bounds from the Character dictionary: `ch->xmin`, `ch->xmax`, `ch->ymin`, `ch->ymax`
- Transform by the display object's composed transform

For Buttons:
- Same approach but use the button's hit-state shape bounds

For TextFields:
- Use `mc->x`, `mc->y`, `mc->width`, `mc->height`

```c
static int get_focus_bounds(SWFAppContext* app_context, MovieClip* mc,
                            float* out_x, float* out_y, float* out_w, float* out_h)
{
    // Find MC's display list entry
    size_t depth = ng_findDisplayEntryByName(mc->name);
    if (depth == SIZE_MAX) return 0;
    DisplayObject* obj = &display_list[depth];

    if (MC_IS_TEXTFIELD(mc)) {
        *out_x = mc->x * 20.0f;
        *out_y = mc->y * 20.0f;
        *out_w = mc->width * 20.0f;
        *out_h = mc->height * 20.0f;
        return 1;
    }

    Character* ch = &dictionary[obj->char_id];
    // Use shape bounds transformed by the composed transform
    float xmin = (float)ch->xmin;  // already in twips
    float xmax = (float)ch->xmax;
    float ymin = (float)ch->ymin;
    float ymax = (float)ch->ymax;

    // Apply transform to get stage coordinates
    const float* xf = (const float*)app_context->transform_data + obj->transform_id * 16;
    // Transform the 4 corners and compute AABB
    // ... (standard 2D AABB transform)

    *out_x = transformed_xmin;
    *out_y = transformed_ymin;
    *out_w = transformed_xmax - transformed_xmin;
    *out_h = transformed_ymax - transformed_ymin;
    return 1;
}
```

### Step 2: Draw Focus Rect

After all display objects are rendered (but before `renderer_close_pass`), draw the focus rect on top:

```c
// In tagShowFrame, after the main render loop, before close_pass:
if (g_focused_mc != NULL) {
    // Check if focus rect should be visible
    // Ruffle: visible when Tab-focused (not mouse-focused)
    float fr = g_focused_mc->focusrect;
    int show_focusrect = (fr < 0) ? 1 : (fr > 0.5f);  // default (-1) = on

    if (show_focusrect) {
        float fx, fy, fw, fh;
        if (get_focus_bounds(app_context, g_focused_mc, &fx, &fy, &fw, &fh)) {
            float thickness = 3.0f * 20.0f;  // 3 pixels in twips
            // Yellow (1.0, 1.0, 0.0, 1.0) outline
            renderer_draw_rect(context, fx - thickness, fy - thickness,
                fw + 2*thickness, thickness, 1, 1, 0, 1, 0);  // top
            renderer_draw_rect(context, fx - thickness, fy + fh,
                fw + 2*thickness, thickness, 1, 1, 0, 1, 0);  // bottom
            renderer_draw_rect(context, fx - thickness, fy,
                thickness, fh, 1, 1, 0, 1, 0);                 // left
            renderer_draw_rect(context, fx + fw, fy,
                thickness, fh, 1, 1, 0, 1, 0);                 // right
        }
    }
}
```

### Step 3: Focus Highlight State Logic

Ruffle distinguishes between `ActiveVisible` (Tab focus shows rect) and `ActiveHidden` (mouse focus hides rect). Need to track how focus was acquired:

- Tab focus → `ActiveVisible` (show rect)
- Mouse click → `ActiveHidden` (don't show rect)
- Tab after mouse → `ActiveVisible` (show rect again)

Add a `g_focus_highlight_visible` flag set by `actionAdvanceTabFocus()` and cleared by `actionMouseClickFocus()`.

---

## Dependencies

- **`renderer_draw_rect()`**: Same dynamic rectangle drawing function from Plan 02. If Plan 02 is implemented first, this is trivially reusable.
- **Runtime transforms (Plan 01)**: Focus bounds need to account for runtime position changes.

---

## Testing

The focus rect tests use `specific_iteration` triggers — they capture frames at specific ticks after Tab/mouse events. The test framework handles input events via `input.json` → `input_events.txt`.

```bash
python3 ruffle-tests/verify_output.py --test=focusrect_swf5 --headless --diff --verbose
```

Each sub-image (e.g., `output.01a`, `output.01b`) captures the state before/after a Tab event.

---

## File Changes Summary

| File | Change |
|------|--------|
| `SWFModernRuntime/src/libswf/tag.c` | Add focus rect rendering after main render loop |
| `SWFModernRuntime/src/actionmodern/action.c` | Add `g_focus_highlight_visible` flag |
| Reuses `renderer_draw_rect()` from Plan 02 |

---

## Risks / Open Questions

1. **Highlight bounds vs bounding box**: Ruffle's `highlight_bounds()` may differ from the raw character bounds. It accounts for children, filters, etc. Start with simple character bounds and refine.

2. **Nested focus**: Buttons inside sprites need their bounds in global (stage) coordinates. Need proper transform composition for the bounds.

3. **_focusrect property inheritance**: In Flash, `_focusrect` can be set per-object or inherited. The default (-1) means "use parent's value". Need to walk up the parent chain.

4. **Exact pixel matching**: Focus rect thickness and position must match Ruffle's implementation exactly. Ruffle uses 3-pixel thickness; some Flash versions use 2-pixel. The tolerance in these tests is unspecified (default = 0), so exact matching is required.
