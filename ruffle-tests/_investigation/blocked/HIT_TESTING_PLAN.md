# Hit Testing Implementation Plan
<!-- TESTS: hittest_lockroot, hittest_morph, hittest_morph_input, hittest_winding_rule, text_blocks_clicks, movieclip_hittest, movieclip_hittest_shapeflag, local_to_global, movieclip_getbounds, movieclip_invalid_get_bounds_1, movieclip_invalid_get_bounds_2, movieclip_invalid_get_bounds_3, movieclip_invalid_get_bounds_4, movieclip_invalid_get_bounds_5, movieclip_invalid_get_bounds_6, movieclip_invalid_get_bounds_7, movieclip_invalid_get_bounds_8 -->

Last updated: 2026-03-14

## Status: BLOCKED — 13/17 PASS (remaining need vector-path hit testing, loadMovie bounds, or droptarget precision)

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
| movieclip_hittest_shapeflag | 338 | 309/338 (29 diff) | Triangulation limitations: stroke, curves, device-font text, morph complex |
| movieclip_invalid_get_bounds_1 | 75 | **PASS** (75/75) | Fixed: broadcastMessage MC `this` type + `g_use_new_invalid_bounds` flag |
| movieclip_invalid_get_bounds_2 | 75 | **PASS** (75/75) | Fixed: root SWF version >= 8 check for sentinel flag |
| movieclip_invalid_get_bounds_3 | 13 | **PASS** (13/13) | Fixed: onEnterFrame per-function version switching |
| movieclip_invalid_get_bounds_4 | 13 | **PASS** (13/13) | Same fixes as above |
| movieclip_invalid_get_bounds_5 | 11 | **PASS** (11/11) | Same fixes as above |
| movieclip_invalid_get_bounds_6 | 10 | **PASS** (10/10) | Fixed: child SWF transform_data + getBounds fallback |
| movieclip_invalid_get_bounds_7 | 10 | **PASS** (10/10) | Same fix as _6 |
| movieclip_invalid_get_bounds_8 | 11 | **PASS** (11/11) | Fixed with same sentinel flag changes |
| text_blocks_clicks | 4 | 3/4 (1 diff) | Droptarget bounds precision — edittext bounds too narrow |

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

### movieclip_hittest_shapeflag (29 diff lines) — Triangulation Limitations

**Fixed (2026-03-14):**
- **Clip-depth masking** (was 3 lines → 0): `ng_hitTestShapeFromDL` now tracks clip layers and filters masked children. Clip layers themselves are not hittable.
- **setMask masking** (was 1 line → 0): hitTest now checks `mc->mask_mc` and tests point against mask shape.
- **Glyph-level text hit testing**: Added per-glyph triangle testing for CHAR_TYPE_TEXT in `ng_hitTestShapeChar`. No visible effect on this test because fonts are device fonts (empty glyph shapes), but will help tests with embedded fonts.

Remaining 29 failing lines:
1. **Stroke edge precision** (5 lines): Stroke-to-triangle conversion in recompiler already generates stroke triangles, but triangulation approximation causes edge mismatches. Ruffle uses exact distance-to-path testing.
2. **Curve approximation** (5 lines): Earcut triangulation straightens curves (donut/layer shapes). Points on curved edges miss or hit incorrectly.
3. **Drawing API false positives** (4 lines): Drawing API shapes use bounds check instead of vector path testing.
4. **Device-font text** (11 lines): Device fonts (Arial, Courier New) have empty glyph shapes in the SWF. Flash/Ruffle use system font outlines for hit testing; we have no font data.
5. **Morph complex shape** (4 lines): Morph shapes with stroke-only paths (no fill triangles). Bounds-based testing is too coarse but no triangle data exists for interpolation.

**Blocker:** Device-font text (11 lines) requires font outline data unavailable in the SWF. Curve/stroke precision (10 lines) would need vector-path-based hit testing. Drawing API (4 lines) needs path triangulation or ray-casting. Morph complex (4 lines) has no triangle data to interpolate.

### ~~movieclip_invalid_get_bounds_6, _7~~ — RESOLVED

**Resolved 2026-03-14.** Three changes:
1. Include child SWF's `transform_data` array in movie wrapper files (prefixed names, via verify_output.py)
2. Cache transform values on `DisplayObject` at `tagPlaceObject2` time using per-movie `g_active_transform_data` pointer
3. `getBounds` fallback: when MC has no `sprite_display_list` but has a `movie_id`, scan root display_list for child SWF entries and recurse into their sprite display lists

### text_blocks_clicks (1 diff line) — Droptarget Bounds Precision
Line 4 expects `_droptarget = "/texts"` but gets `/click_mc`. The `texts` sprite's content bounds (from its text/edittext children) are slightly smaller than the mouse position (4612 twips < mouse 4680 twips). The edittext's DefineEditText bounds don't extend to where Flash considers the sprite clickable.

**Blocker:** Would require understanding Flash's exact text field padding/margin rules for drop target resolution — possibly the 2px gutter or additional padding beyond the DefineEditText bounds.

---

## Files Modified

### Recompiler (SWFRecomp/)
| File | Changes |
|------|---------|
| `src/swf.cpp` | Emit `ng_record_char_bounds()` and `ng_record_char_winding()` in generated code |

### Runtime (SWFModernRuntime/)
| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | localToGlobal, globalToLocal, hitTest (all forms), getBounds, getRect, COMPUTE_GLOBAL_AABB, drawing bounds tracking, ratio-aware morph bounds in mc_get_pixel_aabb_ng |
| `src/libswf/tag_stubs.c` | `ng_char_bounds[]`, `ng_record_char_bounds()`, `ng_record_char_winding()`, `ng_hitTestShapeChar()`, `ng_hitTestShapeFromDL()`, `pit()`, `ng_gotoFrameByMC` same-frame replay fix |
| `include/libswf/tag.h` | Function declarations for bounds, winding, shape hit test |
