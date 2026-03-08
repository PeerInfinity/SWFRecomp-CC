# Ruffle Compatibility Tweaks

Pragmatic implementation choices made specifically to match Ruffle's expected test output.
These are NOT documented Flash behaviors and NOT cases where Ruffle diverges from Flash.
They are arbitrary adjustments where the "correct" behavior is unclear or unspecified,
and we chose the value that makes the Ruffle test pass.

This is distinct from:
- `ACCEPTED_DIFFS.md` — tests that can never match (UB, platform-specific, etc.)
- `RUFFLE_VS_FLASH_DIFFERENCES.md` — cases where we match Flash but Ruffle disagrees

---

## Text Field Background/Border: +1 Pixel on Right and Bottom Edges

**Affected tests**: `frame_size_translated_negative`, `frame_size_translated_positive`

**What we did**: When rendering text field background/border rectangles, we add 1 pixel
to both width and height:
```c
float w = (info->w + 1.0f) * 20.0f;  // +1 pixel for inclusive right/bottom edge
float h = (info->h + 1.0f) * 20.0f;
```

**Why**: A `createTextField("t", 5, -50, -50, 20, 10)` call creates a text field at
(-50,-50) with width=20, height=10 in pixels. Without the +1, the rendered background
covers pixels (50,50)-(69,59) on the canvas — 20x10 pixels. But Ruffle's expected output
shows the background covering (50,50)-(70,60) — 21x11 pixels. The right column and bottom
row are included.

**Evidence**: Pixel-level diff shows exactly 31 outliers (10 on right edge + 21 on bottom
edge) without the +1. With the +1, both tests achieve 0 outliers.

**Risk**: This may not match Flash's actual behavior. Flash's text field rendering
documentation does not specify whether width/height are inclusive or exclusive bounds.
If future tests reveal that the +1 is wrong for other scenarios, this tweak may need
to be conditioned on specific cases.

**File**: `SWFModernRuntime/src/libswf/tag.c` — `textfield_render_cb()`
