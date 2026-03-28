# Focus Rect Rendering Plan
<!-- TESTS: focusrect_focuslost, focusrect_mouse_swf8, focusrect_mouse_swf9, focusrect_swf5, focusrect_swf6 -->

<!-- PLAN_META
id: FOCUS_RECT_RENDERING
status: not_started
phases:
  - id: 1
    name: "Investigate expected appearance from test images"
    status: not_started
  - id: 2
    name: "Implement focus rect drawing function"
    status: not_started
  - id: 3
    name: "Integrate into render pass"
    status: not_started
  - id: 4
    name: "Handle SWF version differences"
    status: not_started
dependencies: []
blockers: []
-->

Last updated: 2026-03-27

## Status: NOT STARTED — Tier 4 (minimal infrastructure exists)

### Problem

Focus rectangles (the yellow/black 2-pixel outline drawn around focused interactive elements) don't render in headless graphics mode. The `_focusrect` property exists on MovieClip, and focus tracking (`g_focused_mc`) exists for event dispatch, but there is no rendering code for focus rects.

### Affected Image Tests

| Test | Images | Tolerance | Notes |
|------|--------|-----------|-------|
| focusrect_focuslost | 1 | trigger | Focus rect appears then disappears |
| focusrect_mouse_swf8 | 8 | trigger | Multiple focus states, SWF8 behavior |
| focusrect_mouse_swf9 | 8 | trigger | Multiple focus states, SWF9 behavior |
| focusrect_swf5 | 12 | trigger | Tab-based focus, SWF5 behavior |
| focusrect_swf6 | 12 | trigger | Tab-based focus, SWF6 behavior |

These tests use trigger-based image captures (specific frames), so multiple images per test.

### Current Infrastructure

#### What Exists

1. **_focusrect property** (`action.h:36`): `float focusrect` on MovieClip struct. Property 17 in the SWF property table. Accessible as `mc._focusrect` (0 or 1, default varies by SWF version).

2. **Focus tracking** (`action.c:~12011`): `g_focused_mc` global variable tracks which MovieClip currently has focus. Used for key event dispatch and Selection.getFocus().

3. **renderer_draw_rect()**: Can draw filled and stroked rectangles. Already used for text field borders. Could be used for focus rect outlines.

4. **Bounds calculation**: `getBounds()` / `mc.draw_xmin/xmax/ymin/ymax` provide bounding box information for display objects.

#### What's Missing

1. **Focus rect drawing function**: No code anywhere draws the yellow/black outline.

2. **Focus rect style**: Flash's focus rect is specifically:
   - Outer: 1px black line
   - Inner: 1px yellow (#FFFF00) line
   - Total: 2px outline around the focused element's bounds
   - Some SWF versions use a dashed/dotted pattern

3. **Integration in render pass**: No focus rect rendering call in `tagShowFrame()` or the headless render loop.

4. **SWF version-dependent behavior**:
   - SWF5: Focus rect shown by default on buttons
   - SWF6+: Focus rect shown by default on buttons and text fields
   - `_focusrect = false` disables it
   - Stage.showFocusIndicator may also control visibility

### Implementation Plan

#### Step 1: Investigate Expected Appearance

Check the Ruffle test expected images to understand exactly what the focus rect looks like:
```bash
ls ruffle-tests/tests/swfs/avm1/focusrect_swf5/
# Look at expected PNGs
```

Also check Ruffle's source code for their focus rect implementation:
```bash
grep -r "focus_rect\|focusRect\|FocusRect" ~/CC/ruffle/core/src/
```

#### Step 2: Implement Focus Rect Drawing Function

```c
// In tag.c or render utilities
void render_focus_rect(SWFAppContext* app_context, float x, float y,
                       float width, float height) {
    // Outer black rect (1px)
    renderer_draw_rect(x - 2, y - 2, width + 4, height + 4,
                       0.0f, 0.0f, 0.0f, 1.0f,  // black
                       0, 1);  // no fill, stroke only
    // Inner yellow rect (1px)
    renderer_draw_rect(x - 1, y - 1, width + 2, height + 2,
                       1.0f, 1.0f, 0.0f, 1.0f,  // yellow
                       0, 1);  // no fill, stroke only
}
```

The exact pixel offsets and line widths need to match Flash's behavior. Check expected images.

#### Step 3: Integrate into Render Pass

Add focus rect rendering at the end of the display list draw (after all shapes/sprites, before frame capture):

```c
// In tagShowFrame() render pass, after all drawing:
if (g_focused_mc != NULL) {
    MovieClip* fmc = (MovieClip*)g_focused_mc;
    if (fmc->focusrect != 0.0f) {
        // Get bounds in stage coordinates
        float x = fmc->draw_xmin;
        float y = fmc->draw_ymin;
        float w = fmc->draw_xmax - fmc->draw_xmin;
        float h = fmc->draw_ymax - fmc->draw_ymin;
        // Apply MC transform to get stage coordinates
        // ... transform bounds by MC's composed transform ...
        render_focus_rect(app_context, x, y, w, h);
    }
}
```

#### Step 4: Handle SWF Version Differences

- SWF5: Default `_focusrect = true` for buttons only
- SWF6+: Default `_focusrect = true` for buttons and text fields
- Check whether `g_focused_mc` is a button vs text field vs generic MC

#### Step 5: Test

```bash
python3 ruffle-tests/verify_output.py --test=focusrect_swf5 --headless --diff --verbose
python3 ruffle-tests/verify_output.py --test=focusrect_mouse_swf8 --headless --diff --verbose
```

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| MovieClip.focusrect | `action.h` | line 36 |
| g_focused_mc | `action.c` | ~12011 |
| Focus event dispatch | `action.c` | (search for g_focused_mc usage) |
| renderer_draw_rect | `render_webgpu.c` / `tag.c` | existing function |
| tagShowFrame render pass | `tag.c` | 1850+ |

### Design Considerations

1. **Bounds accuracy**: The focus rect must surround the element's visible bounds. For buttons, this is the hit-state shape bounds. For text fields, this is the text field bounds. For MovieClips, this is the union of child bounds.

2. **Transform composition**: The focus rect bounds need to be in stage coordinates (after all parent transforms). May need to apply the composed transform to the local bounds.

3. **Z-ordering**: Focus rect should render on top of all other content. Draw it last in the render pass.

4. **Dashed lines**: Some Flash versions use dashed focus rects. If the expected images show dashes, this would require a more complex line rendering approach. Most tests likely use solid lines.

5. **Focus rect on buttons**: Buttons have multiple states (up, over, down, hit). The focus rect should use the hit-state bounds, not the current visible state bounds.

### Dependencies

- None — standalone feature
- Could benefit from renderer_draw_rect improvements if stroke rendering needs work

### Estimated Complexity

Medium. The drawing is simple (2 rectangles), but getting the bounds right, handling transforms, and matching Flash's exact pixel behavior requires careful testing:
1. Focus rect drawing function (~20 lines)
2. Render pass integration (~30 lines)
3. Bounds calculation with transforms (~40 lines)
4. SWF version behavior (~20 lines)
5. Testing and pixel-matching (~2 hours)
