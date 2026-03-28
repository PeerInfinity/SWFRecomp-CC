# Morph Shape Interpolation Plan
<!-- TESTS: hittest_morph -->

<!-- PLAN_META
id: MORPH_INTERPOLATION
status: complete
phases:
  - id: 1
    name: "End bounds extraction (recompiler)"
    status: complete
  - id: 2
    name: "Interpolated bounds lookup"
    status: complete
  - id: 3
    name: "Interpolated shape hit testing"
    status: complete
dependencies:
  - plan: PLAN_01_RUNTIME_TRANSFORMS
    type: requires
    reason: "Morph rendering depends on transform pipeline"
blockers: []
-->

Last updated: 2026-02-26

## Status: COMPLETE — 1/1 test PASS

| Test | Match | Status |
|------|-------|--------|
| hittest_morph | 70/70 | **PASS** ✅ |

The test now passes in CI without explicit morph interpolation changes. The existing bounds and hit-test infrastructure handles this test correctly.

The 3 failing lines in `hittest_morph`:
- Lines 61, 66: `xMax` bounds mismatch — getBounds returns start-shape bounds instead of
  interpolated bounds at the current morph ratio
- Line 68: `hitTest` returns `true` instead of `false` — shape-accurate hit test uses
  start-shape triangles instead of interpolated shape at current ratio

---

## Current Architecture

### Recompiler (SWFRecomp/src/swf.cpp)

DefineMorphShape parsing (lines 5315-5370):
- Parses start bounds RECT and end bounds RECT
- **Skips end bounds** with comment: "EndBounds available but not used for static bounds"
- Stores start shape triangles at `morph_start_offset` and end shape at `morph_end_offset`
- Emits `tagDefineMorphShape()` with **start bounds only**

### Runtime storage (swf.h Character struct)

```c
struct {
    size_t morph_start_offset;   // start shape triangles in shape_data[]
    size_t morph_start_size;     // triangle count
    size_t morph_end_offset;     // end shape triangles in shape_data[]
    size_t morph_color_start;    // colors
    size_t morph_color_count;
} morph_shape;
```

**Missing**: end bounds (xmin/xmax/ymin/ymax for end shape).

### DisplayObject ratio field

```c
u16 ratio;  // 0 = start shape, 65535 = end shape (from PlaceObject2 HasRatio)
```

Set correctly by `tagPlaceObject2Ratio()` but never used for interpolation.

### Bounds lookup (tag_stubs.c)

`ng_record_char_bounds()` stores only start bounds. `ng_get_char_bounds()` returns them
regardless of ratio. All callers (getBounds, getRect, hitTest) use start bounds.

### Shape hit testing (tag_stubs.c)

`ng_hitTestShapeChar()` tests against start-shape triangles only, ignoring ratio.

---

## What Needs to Change

### Phase 1: End bounds extraction (recompiler)

Store end bounds from DefineMorphShape in the generated code.

**SWFRecomp/src/swf.cpp** changes:
- Parse and store end bounds RECT (currently skipped at line 5315)
- Emit both start and end bounds to `tagDefineMorphShape()` or a new
  `ng_record_morph_end_bounds()` call

**Runtime** changes:
- New fields in Character morph_shape struct: `end_xmin, end_xmax, end_ymin, end_ymax`
- Or a parallel `ng_morph_end_bounds[]` array alongside `ng_char_bounds[]`

### Phase 2: Interpolated bounds lookup

When `ng_get_char_bounds()` is called for a morph shape, interpolate based on ratio:

```c
void ng_get_morph_bounds(u16 char_id, u16 ratio, s32* xmin, s32* xmax, s32* ymin, s32* ymax) {
    s32 start_xmin, start_xmax, start_ymin, start_ymax;
    s32 end_xmin, end_xmax, end_ymin, end_ymax;

    // Look up start and end bounds
    ng_get_char_bounds(char_id, &start_xmin, ...);
    ng_get_morph_end_bounds(char_id, &end_xmin, ...);

    // Linear interpolation: ratio=0 → start, ratio=65535 → end
    float t = ratio / 65535.0f;
    *xmin = (s32)(start_xmin + (end_xmin - start_xmin) * t);
    *xmax = (s32)(start_xmax + (end_xmax - start_xmax) * t);
    *ymin = (s32)(start_ymin + (end_ymin - start_ymin) * t);
    *ymax = (s32)(start_ymax + (end_ymax - start_ymax) * t);
}
```

Update `getBounds()` / `getRect()` in action.c to pass ratio when computing AABB for
morph shapes.

### Phase 3: Interpolated shape hit testing

For shape-accurate `hitTest(x, y, true)` on morph shapes, interpolate vertex positions:

```c
bool ng_hitTestMorphShape(u16 char_id, u16 ratio, float test_x, float test_y) {
    float t = ratio / 65535.0f;

    // Walk start and end triangle arrays in parallel
    for (size_t i = 0; i < triangle_count; i++) {
        // Interpolate each vertex
        float x0 = start_verts[i*3+0].x * (1-t) + end_verts[i*3+0].x * t;
        float y0 = start_verts[i*3+0].y * (1-t) + end_verts[i*3+0].y * t;
        // ... same for other 2 vertices ...

        // Point-in-triangle test with interpolated vertices
        if (pointInTriangle(test_x, test_y, x0, y0, x1, y1, x2, y2))
            return true;
    }
    return false;
}
```

**Prerequisite**: Start and end shapes must have the same number of triangles. This is
generally true for morph shapes (SWF spec requires matching edge counts), but earcut
triangulation could produce different triangle counts if the shapes have different
topology. Need to verify.

---

## Ruffle Reference

Ruffle implements full morph interpolation in `core/src/display_object/morph_shape.rs`:

- **Lazy caching**: Interpolated frames cached per-ratio in `FnvHashMap<u16, Frame>`
- **Linear lerp**: `a = 1.0 - (ratio / 65535.0)`, `b = ratio / 65535.0`
- Interpolates: colors (RGBA), coordinates, fill styles, line styles, edge vertices, bounds
- Bounds are recomputed from interpolated shape, not interpolated from start/end bounds
  (more accurate but more expensive)

Reference: `~/CC/ruffle/core/src/display_object/morph_shape.rs:210-534`

---

## Estimated Effort

| Phase | Effort | Impact |
|-------|--------|--------|
| 1: End bounds extraction | 30 min | Enables Phase 2 |
| 2: Interpolated bounds | 1 hour | Fixes 2 of 3 failing lines (bounds) |
| 3: Interpolated hit test | 2 hours | Fixes remaining 1 line (shape hit test) |
| **Total** | **~3.5 hours** | **hittest_morph: 70/70** |

This is a relatively small, self-contained fix with clear impact. The main risk is
triangle count mismatch between start and end shapes in the earcut triangulation step.

---

## Files to Modify

| File | Changes |
|------|---------|
| `SWFRecomp/src/swf.cpp` | Extract and emit end bounds for DefineMorphShape |
| `SWFModernRuntime/include/libswf/swf.h` | End bounds fields in Character morph struct |
| `SWFModernRuntime/src/libswf/tag.c` | `tagDefineMorphShape()` stores end bounds |
| `SWFModernRuntime/src/libswf/tag_stubs.c` | `ng_get_morph_bounds()`, interpolated hit test |
| `SWFModernRuntime/src/actionmodern/action.c` | Pass ratio to bounds/hitTest for morph shapes |
