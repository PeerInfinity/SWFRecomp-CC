# Hit Testing Implementation Plan
<!-- TESTS: hittest_lockroot, hittest_morph, hittest_morph_input, hittest_winding_rule, text_blocks_clicks, movieclip_hittest, movieclip_hittest_shapeflag, local_to_global, movieclip_getbounds, movieclip_invalid_get_bounds_1, movieclip_invalid_get_bounds_2, movieclip_invalid_get_bounds_3, movieclip_invalid_get_bounds_4, movieclip_invalid_get_bounds_5, movieclip_invalid_get_bounds_6, movieclip_invalid_get_bounds_7, movieclip_invalid_get_bounds_8 -->

<!-- PLAN_META
id: HIT_TESTING
status: blocked
phases:
  - id: 1
    name: "localToGlobal / globalToLocal"
    status: complete
  - id: 2
    name: "Shape bounds in NO_GRAPHICS mode"
    status: complete
  - id: 3
    name: "getBounds / getRect"
    status: complete
  - id: 4
    name: "hitTest(x, y, shapeFlag=false)"
    status: complete
  - id: 5
    name: "hitTest(clip) / hitTest(stringPath)"
    status: complete
  - id: 6
    name: "hitTest(x, y, shapeFlag=true)"
    status: complete
  - id: 7
    name: "Morph input hit testing"
    status: complete
dependencies: []
blockers:
  - blocker: 5
    reason: "Pixel-level shape hit testing limitations (device fonts, curve/stroke precision)"
-->

Last updated: 2026-03-30

## Status: BLOCKED — 15/17 PASS (remaining need vector-path hit testing or device font outlines)

---

## Current Results

| Test | Lines | Status | Notes |
|------|-------|--------|-------|
| local_to_global | 49 | **PASS** (49/49) | Phases 1-4 complete |
| movieclip_hittest | 92 | **PASS** (92/92) | Phases 4-5 complete |
| hittest_lockroot | 15 | **PASS** (15/15) | Phase 4 + drawing bounds |
| hittest_winding_rule | 12 | **PASS** (12/12) | Phase 6 (shape-accurate + winding rules) |
| movieclip_getbounds | 191 | **PASS** (191/191) | Was 186/191, now fully passing |
| hittest_morph | 70 | **PASS** (70/70) | Morph interpolated bounds |
| hittest_morph_input | 1 | **PASS** (1/1) ✅ | Fixed: ratio-aware bounds in mc_get_pixel_aabb_ng + gotoAndStop same-frame replay |
| movieclip_hittest_shapeflag | 338 | 318/338 (20 diff) | Triangulation limitations: stroke precision, device-font text, morph complex |
| movieclip_invalid_get_bounds_1 | 75 | **PASS** (75/75) | Fixed: broadcastMessage MC `this` type + `g_use_new_invalid_bounds` flag |
| movieclip_invalid_get_bounds_2 | 75 | **PASS** (75/75) | Fixed: root SWF version >= 8 check for sentinel flag |
| movieclip_invalid_get_bounds_3 | 13 | **PASS** (13/13) | Fixed: onEnterFrame per-function version switching |
| movieclip_invalid_get_bounds_4 | 13 | **PASS** (13/13) | Same fixes as above |
| movieclip_invalid_get_bounds_5 | 11 | **PASS** (11/11) | Same fixes as above |
| movieclip_invalid_get_bounds_6 | 10 | **PASS** (10/10) | Fixed: child SWF transform_data + getBounds fallback |
| movieclip_invalid_get_bounds_7 | 10 | **PASS** (10/10) | Same fix as _6 |
| movieclip_invalid_get_bounds_8 | 11 | **PASS** (11/11) | Fixed with same sentinel flag changes |
| text_blocks_clicks | 4 | **PASS** (4/4) | Fixed in prior session |

---

## Completed Phases

### Phase 1: localToGlobal / globalToLocal — COMPLETE
Implemented `MovieClip.localToGlobal(point)` and `MovieClip.globalToLocal(point)` using transform chain walking. Both modify the `{x, y}` point object in place. Coordinates in pixels, transforms in twips.

### Phase 2: Shape Bounds in NO_GRAPHICS Mode — COMPLETE
Character bounds (`ng_char_bounds[]`) emitted by recompiler via `ng_record_char_bounds()` for DefineShape, DefineText, DefineEditText, DefineMorphShape.

### Phase 3: getBounds / getRect — COMPLETE
Recursive AABB computation via `COMPUTE_GLOBAL_AABB` macro. Handles nested sprites, transforms, drawing API bounds. Self-target vs cross-target sentinel values.

### Phase 4: hitTest(x, y, shapeFlag=false) — COMPLETE
Bounding box hitTest using global AABB computation. Drawing API bounds tracked via `draw_xmin/xmax/ymin/ymax` on MovieClip. NaN argument handling.

### Phase 5: hitTest(clip) / hitTest(stringPath) — COMPLETE
Clip-vs-clip AABB overlap test. String path resolution to MovieClip.

### Phase 6: hitTest(x, y, shapeFlag=true) — COMPLETE
Shape-accurate hit testing using triangulated vertex data from `shape_data[]`. Point-in-triangle via barycentric coordinates. Winding rule support (even-odd vs non-zero from DefineShape4 UsesFillWindingRule flag).

Implementation details:
- Recompiler extracts UsesFillWindingRule flag from DefineShape4 and emits `ng_record_char_winding()`
- `ng_hitTestShapeChar()` inverse-transforms test point to local shape space, tests against triangles
- `ng_hitTestShapeFromDL()` recursively traverses display list composing transforms
- Drawing API shapes fall back to drawing bounds check
- Known limitations: earcut triangulation straightens curves, shared triangle edges can cause edge-case misses

### Phase 7: Morph input hit testing — COMPLETE
Fixed `hittest_morph_input` (0/1 → 1/1 PASS) with two changes:
1. `mc_get_pixel_aabb_ng` now uses `ng_getCharBoundsForRatio()` instead of `ng_getCharBounds()` for sprite display list children, so morph shapes at non-zero ratios get correctly interpolated bounds for mouse rollover detection.
2. `ng_gotoFrameByMC` always replays frame tags even when `frame == current`. After sprite init, `sprite_current_frame` is bumped to 1 optimistically, but if the sprite was stopped at frame 0, frame 1's tags (including `tagPlaceObject2Ratio` with the morph ratio) were never executed.

---

## Remaining Failures (BLOCKED)

### movieclip_hittest_shapeflag (20 diff lines) — Triangulation Limitations

**Fixed (2026-03-14):**
- **Clip-depth masking** (was 3 lines → 0): `ng_hitTestShapeFromDL` now tracks clip layers and filters masked children. Clip layers themselves are not hittable.
- **setMask masking** (was 1 line → 0): hitTest now checks `mc->mask_mc` and tests point against mask shape.
- **Glyph-level text hit testing**: Added per-glyph triangle testing for CHAR_TYPE_TEXT in `ng_hitTestShapeChar`. No visible effect on this test because fonts are device fonts (empty glyph shapes), but will help tests with embedded fonts.

**Fixed (2026-03-30):**
- **Earcut bridge-edge double-counting** (was 2 lines → 0): Donut shapes with holes had earcut bridge edges that caused shared-edge double-counting, breaking even-odd parity. Fixed by implementing a top-left fill rule in `pit()` that assigns shared edges to exactly one triangle.
- **Stroke intersection overlap** (was 4 lines → 0): Cross-pattern stroke triangles overlapped at intersections, causing even-odd to subtract the overlap region. Fixed by marking stroke triangles with bit 31 in shape_data column 2 (recompiler) and using non-zero winding (union) for stroke hits separately from fill hits.

Remaining 20 failing lines:
1. **Stroke edge precision** (1 line): Line 63 false positive — stroke triangle extends beyond actual stroke boundary at endpoint.
2. **Curve/scribble/layers** (3 lines): Lines 71, 85, 89 — earcut triangulation of complex curved paths misses points near polygon boundaries. Not a bridge-edge issue but fundamental polygon approximation.
3. **Drawing API false positives** (2 lines): Lines 117, 137 — drawing API fill triangles cover areas that should be outside the drawn shape. Likely curve approximation in drawing API triangulation.
4. **Background art** (3 lines): Lines 141, 143, 147 — large background shapes with complex paths miss points at certain coordinates. Similar polygon approximation issue.
5. **Device-font text** (7 lines): Lines 157, 163, 165, 171-177 — device fonts (Arial, Courier New) have empty glyph shapes in the SWF. Flash/Ruffle use system font outlines for hit testing; we have no font data.
6. **Morph complex shape** (4 lines): Lines 292, 294, 296, 304 — morph shapes with stroke-only paths (no fill triangles). Bounds-based testing is too coarse but no triangle data exists for interpolation.

**Blocker:** All 20 remaining failures trace to earcut polygon approximation of curves. A vector-path winding number algorithm (matching Ruffle's approach) would fix all of them. See `VECTOR_PATH_HITTEST_PLAN.md` for the implementation plan.

### ~~movieclip_invalid_get_bounds_6, _7~~ — RESOLVED

**Resolved 2026-03-14.** Three changes:
1. Include child SWF's `transform_data` array in movie wrapper files (prefixed names, via verify_output.py)
2. Cache transform values on `DisplayObject` at `tagPlaceObject2` time using per-movie `g_active_transform_data` pointer
3. `getBounds` fallback: when MC has no `sprite_display_list` but has a `movie_id`, scan root display_list for child SWF entries and recurse into their sprite display lists

### ~~text_blocks_clicks~~ — RESOLVED
Fixed in a prior session (now 4/4 PASS).

---

## Files Modified

### Recompiler (SWFRecomp/)
| File | Changes |
|------|---------|
| `src/swf.cpp` | Emit `ng_record_char_bounds()`, `ng_record_char_winding()`, and stroke marker (0x80000000 in shape_data column 2) in generated code |

### Runtime (SWFModernRuntime/)
| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | localToGlobal, globalToLocal, hitTest (all forms), getBounds, getRect, COMPUTE_GLOBAL_AABB, drawing bounds tracking, ratio-aware morph bounds in mc_get_pixel_aabb_ng |
| `src/libswf/tag_stubs.c` | `ng_char_bounds[]`, `ng_record_char_bounds()`, `ng_record_char_winding()`, `ng_hitTestShapeChar()` (fill/stroke split winding), `ng_hitTestShapeFromDL()`, `pit()` (top-left fill rule), `ng_gotoFrameByMC` same-frame replay fix |
| `include/libswf/tag.h` | Function declarations for bounds, winding, shape hit test |
