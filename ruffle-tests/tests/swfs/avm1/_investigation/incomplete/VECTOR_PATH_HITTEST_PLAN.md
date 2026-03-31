# Vector-Path Hit Testing Plan
<!-- TESTS: movieclip_hittest_shapeflag -->

<!-- PLAN_META
id: VECTOR_PATH_HITTEST
status: incomplete
phases:
  - id: 1
    name: "Path data emission (recompiler)"
    status: not_started
  - id: 2
    name: "Fill winding number algorithm (runtime)"
    status: not_started
  - id: 3
    name: "Stroke distance testing (runtime)"
    status: not_started
  - id: 4
    name: "Morph shape interpolated paths"
    status: not_started
dependencies:
  - HIT_TESTING (phases 1-7 complete)
blockers: []
-->

Last updated: 2026-03-30

## Status: NOT STARTED — 0/4 phases complete

---

## Problem

The current shape-accurate hitTest uses pre-triangulated polygons (earcut) stored in `shape_data[]`. Points are tested against triangles via `pit()`. This has fundamental accuracy limitations:

1. **Curve approximation**: Quadratic bezier curves are subdivided into 6 line segments. Points near the true curve boundary may fall outside the polygon.
2. **Earcut bridge edges**: Handled by the top-left fill rule in `pit()` (fixed 2026-03-30), but edge cases remain for complex polygons.
3. **Stroke overlap**: Handled by stroke marker + non-zero winding (fixed 2026-03-30), but stroke endpoint geometry is imprecise.

These limitations cause **20 diff lines** in `movieclip_hittest_shapeflag` (318/338):

| Category | Lines | Root cause |
|----------|-------|------------|
| Stroke endpoint precision | 1 (line 63) | Stroke triangle extends past actual endpoint |
| Curve/polygon approximation | 3 (lines 71, 85, 89) | Points near curve boundary fall outside polygon |
| Drawing API curves | 2 (lines 117, 137) | Same curve approximation in drawing API triangulation |
| Background art curves | 3 (lines 141, 143, 147) | Complex curved shapes miss edge points |
| Device-font text curves | 7 (lines 157, 163, 165, 171-177) | Glyph outline curve approximation |
| Morph complex (no data) | 4 (lines 292, 294, 296, 304) | Stroke-only morph has no fill triangles; bounds too coarse |

**All 20 failures trace to the same root cause**: polygon approximation of curves. Ruffle uses vector-path winding number testing on the actual bezier curves, which gives exact results.

## Proposed Approach

Replace the triangle-based hit test with a vector-path winding number algorithm, matching Ruffle's approach. The recompiler emits path boundary data (line/curve commands) alongside or instead of triangle data. The runtime implements ray-casting with winding number accumulation.

### Why not just increase curve subdivision?

Tested with 12 subdivisions (up from 6) — zero improvement. The failures are at specific boundary angles where the polygon chord always deviates from the true curve, regardless of segment count.

### Why vector-path testing works

- **Fills**: Ray-cast from test point along +x axis, count winding number from line/curve crossings. No approximation — curves are tested analytically.
- **Strokes**: Compute minimum distance from test point to each path segment (line or curve). Compare against stroke half-width. No triangulation needed.
- **Morph shapes**: Interpolate path control points at the current ratio, then test against the interpolated path. Currently impossible with triangles (no morph end path data for strokes).

---

## Current Results

| Test | Lines | Status | Notes |
|------|-------|--------|-------|
| movieclip_hittest_shapeflag | 338 | 318/338 (20 diff) | All 20 from curve/stroke approximation |

---

## Phase 1: Path Data Emission (Recompiler)

### Goal
Emit vector path data (move/line/curve commands) from the recompiler alongside existing triangle data, so the runtime can use either for hit testing.

### Data format

New array `path_data` with commands encoded as packed floats:

```c
// Command types (stored in column 2 as u32):
// 0x00000001 = MoveTo
// 0x00000002 = LineTo
// 0x00000003 = QuadraticCurveTo (control point in next entry)
// 0x00000004 = EndPath (sentinel)
//
// Fill paths: column 3 = fill style index
// Stroke paths: column 3 = (stroke_width_twips << 16) | line_style_index

float path_data[][4] = {
    // MoveTo: {x, y, CMD_MOVETO, style}
    // LineTo: {x, y, CMD_LINETO, style}
    // QuadTo: {ctrl_x, ctrl_y, CMD_QUADTO, style}, {anchor_x, anchor_y, 0, 0}
    // EndPath: {0, 0, CMD_END, 0}
};
```

Each shape character stores `path_offset` and `path_size` in the dictionary, similar to `shape_offset`/`size` for triangles.

### Source: shape record parsing

The recompiler already walks DefineShape records to build polygon paths for earcut. The new code captures the raw path commands (before curve subdivision) and emits them to `path_data`.

For fills: emit one path per fill style, with all edges contributing to that fill.
For strokes: emit one path per line style, with stroke width encoded.

### Morph shapes

For DefineMorphShape, emit both start and end path data. The runtime interpolates control points at the current ratio.

### Files modified
- `SWFRecomp/src/swf.cpp`: Add `path_data` emission alongside `shape_data`
- `SWFRecomp/include/swf.hpp`: New stringstream for path_data

---

## Phase 2: Fill Winding Number Algorithm (Runtime)

### Goal
Implement ray-casting winding number fill test using path_data, replacing the triangle-based fill test.

### Algorithm (matching Ruffle)

```
winding_number_fill(point, path_data, offset, size):
    winding = 0
    cursor = (0, 0)
    for each command in path_data[offset..offset+size]:
        if MoveTo: cursor = (x, y)
        if LineTo:
            winding += winding_number_line(point, cursor, (x, y))
            cursor = (x, y)
        if QuadTo:
            winding += winding_number_curve(point, cursor, (ctrl_x, ctrl_y), (anchor_x, anchor_y))
            cursor = (anchor_x, anchor_y)
    return winding
```

#### `winding_number_line(point, begin, end)`

Standard ray-casting on the +x axis:
1. Check if point.y is within [begin.y, end.y] range
2. Compute perpendicular dot product to determine which side of the segment the point is on
3. Return +1 (downward crossing, point on left), -1 (upward crossing, point on left), or 0

Uses i64 arithmetic to avoid i32 overflow (coordinates are in twips, up to ~30000).

#### `winding_number_curve(point, p0, p1, p2)`

Quadratic bezier ray-casting — the key innovation over triangulation:
1. Translate curve so point is at origin
2. Solve quadratic `y(t) = 0` for the curve's y-component
3. For each root t ∈ [0, 1], check if `x(t) > 0` (ray hits along +x)
4. Split curve at y-extrema into y-monotonic subcurves for consistent endpoint handling
5. Determine winding contribution from curve direction

### Fill rule application
- Even-odd: `(winding & 1) != 0`
- Non-zero: `winding != 0`

### Integration

In `ng_hitTestShapeChar()`, if `path_data` exists for the character, use path-based testing. Fall back to triangle testing if no path data (backward compatibility).

### Expected fixes
- Lines 71, 85, 89 (curve/scribble/layers): exact curve boundary testing
- Lines 141, 143, 147 (bg art): exact curve testing on background shapes
- Lines 157, 163, 165, 171-177 (device-font text): exact glyph outline curves
- Lines 117, 137 (drawing API): if drawing API also emits path data

### Files modified
- `SWFModernRuntime/src/libswf/tag_stubs.c`: New fill winding functions, path-based hit test path
- `SWFModernRuntime/include/libswf/tag.h`: New function declarations

---

## Phase 3: Stroke Distance Testing (Runtime)

### Goal
Implement distance-to-path stroke hit testing, replacing stroke triangle testing.

### Algorithm

#### Line stroke: closest-point projection
```
hit_test_stroke_line(point, begin, end, half_width):
    // Project point onto segment, compute distance²
    // Compare against half_width²
```

#### Quadratic curve stroke: perpendicular intersection
```
hit_test_stroke_curve(point, p0, p1, p2, half_width):
    // Find t where (point - C(t)) · C'(t) = 0
    // This is a cubic polynomial in t
    // Solve cubic, test distance at each root ∈ [0,1] and at t=0, t=1
    // Return min_distance <= half_width
```

Requires a cubic polynomial solver (Cardano's formula or iterative).

### Expected fixes
- Line 63 (stroke false positive): exact stroke boundary instead of triangulated quad

### Files modified
- `SWFModernRuntime/src/libswf/tag_stubs.c`: Stroke distance functions, cubic solver

---

## Phase 4: Morph Shape Interpolated Paths

### Goal
Enable path-based hit testing for morph shapes by interpolating start/end path control points at the current ratio.

### Approach

The recompiler emits both start and end path data for DefineMorphShape. At runtime:
1. Read start path from `path_data[morph_start_offset]`
2. Read end path from `path_data[morph_end_offset]`
3. Linearly interpolate each control point: `p = p_start + (p_end - p_start) * ratio / 65535`
4. Run fill/stroke winding test on interpolated path

### Expected fixes
- Lines 292, 294, 296, 304 (morph complex): currently bounds-only because no triangle data for stroke-only morphs

### Files modified
- `SWFRecomp/src/swf.cpp`: Emit morph start+end path data
- `SWFModernRuntime/src/libswf/tag_stubs.c`: Interpolation + path testing for morphs

---

## Drawing API Integration

The runtime drawing API (`DrawingState` with `fill_verts`/`line_verts`) already stores triangle data for hit testing. To benefit from vector-path testing, the drawing API would need to also store path commands.

This is a separate enhancement — the drawing API hit test currently uses triangulated fill/line data in `action.c`. Converting it to path-based testing would fix lines 117, 137 but requires changes to how `DrawingState` records path data.

**Recommendation**: Defer drawing API path testing to a follow-up. Focus phases 1-4 on DefineShape/DefineMorphShape/DefineText paths emitted by the recompiler.

---

## Risk Assessment

| Risk | Mitigation |
|------|-----------|
| Numerical precision in curve solver | Use Ruffle's proven algorithms (Citardauq formula, y-monotonic splitting) |
| Performance regression (path testing slower than triangles) | Keep triangle data as fast-reject bounding; only test paths when BB says hit |
| Large path_data arrays | Path data is smaller than triangle data (one command per curve vs 6 triangle vertices) |
| Backward compatibility | Fall back to triangles if path_data not available |
| Cubic curves in drawing API | Decompose to quadratics (Ruffle uses tolerance=0.01) |

---

## Implementation Order and Expected Results

| Phase | Diff lines fixed | Running total |
|-------|-----------------|---------------|
| Phase 1 (emit paths) | 0 (data only) | 318/338 |
| Phase 2 (fill winding) | ~13 (curves, bg art, text) | ~331/338 |
| Phase 3 (stroke distance) | ~1 (stroke endpoint) | ~332/338 |
| Phase 4 (morph paths) | ~4 (morph complex) | ~336/338 |
| Drawing API (deferred) | ~2 (drawing API curves) | ~338/338 |

**Target: 336-338/338** (from current 318/338)

---

## Files Summary

### Recompiler (SWFRecomp/)
| File | Changes |
|------|---------|
| `src/swf.cpp` | Emit `path_data[]` for fills, strokes, morph start/end |
| `include/swf.hpp` | New path_data stringstream |

### Runtime (SWFModernRuntime/)
| File | Changes |
|------|---------|
| `src/libswf/tag_stubs.c` | `winding_number_line()`, `winding_number_curve()`, `hit_test_stroke_line()`, `hit_test_stroke_curve()`, `solve_cubic()`, path-based `ng_hitTestShapeChar()`, morph interpolation |
| `include/libswf/tag.h` | New function declarations, path_data extern |

### Test runner
| File | Changes |
|------|---------|
| `ruffle-tests/verify_output.py` | Include `path_data` source file in compilation |

---

## References

- Ruffle implementation: `~/CC/ruffle/render/src/shape_utils.rs` (lines 588-1200)
- Ruffle morph shapes: `~/CC/ruffle/core/src/display_object/morph_shape.rs`
- Ruffle drawing hit test: `~/CC/ruffle/core/src/drawing.rs:332-404`
- Current triangle-based hit test: `SWFModernRuntime/src/libswf/tag_stubs.c` (`ng_hitTestShapeChar`, `pit()`)
