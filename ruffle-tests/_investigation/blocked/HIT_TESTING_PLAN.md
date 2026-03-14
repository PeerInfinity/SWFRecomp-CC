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
| movieclip_hittest_shapeflag | 338 | 306/338 (32 diff) | Triangulation limitations: stroke, curves, masking, morph complex |
| movieclip_invalid_get_bounds_1 | 75 | **PASS** (75/75) | Fixed: broadcastMessage MC `this` type + `g_use_new_invalid_bounds` flag |
| movieclip_invalid_get_bounds_2 | 75 | **PASS** (75/75) | Fixed: root SWF version >= 8 check for sentinel flag |
| movieclip_invalid_get_bounds_3 | 13 | **PASS** (13/13) | Fixed: onEnterFrame per-function version switching |
| movieclip_invalid_get_bounds_4 | 13 | **PASS** (13/13) | Same fixes as above |
| movieclip_invalid_get_bounds_5 | 11 | **PASS** (11/11) | Same fixes as above |
| movieclip_invalid_get_bounds_6 | 10 | 9/10 (1 diff) | Needs loaded child SWF shape data (loadMovie) |
| movieclip_invalid_get_bounds_7 | 10 | 9/10 (1 diff) | Same issue as _6 |
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

### movieclip_hittest_shapeflag (32 diff lines) — Triangulation Limitations
Remaining 32 failing lines fall into these categories:
1. **Stroke inclusion** (4 lines): Flash includes stroke width in shape hit testing; we only test fill triangles
2. **Curve approximation** (3 lines): Earcut triangulation straightens curves, so curved edges don't match Flash's vector path testing
3. **Clip-depth masking** (3 lines): `hitTest(x,y,true)` should respect clip_depth masking; we don't check this
4. **Drawing API false positives** (4 lines): Drawing API shapes use bounds check instead of vector path testing
5. **Text/edittext shapes** (7 lines): Text shape bounds not included in shape-accurate hit testing
6. **Complex shape outlines** (4 lines): BG art with complex paths not fully represented by triangulation
7. **Morph complex shape** (4 lines): Morph shapes at interpolated ratios, bounds vs exact shape testing

**Blocker:** Fundamental fix requires vector-path-based hit testing (line segment intersection counting) instead of triangle-based approach. This is a significant architectural change.

### movieclip_invalid_get_bounds_6, _7 (1 diff line each) — LoadMovie Child Bounds
Line 2 expects `550.45` (actual shape bounds from loaded child SWF) but we return the sentinel value (6710886.4 / 6710886.35). In NO_GRAPHICS mode, we don't have the child SWF's shape data available after loadMovie.

**Blocker:** Would require implementing loadMovie SWF parsing in NO_GRAPHICS mode to extract child shape bounds.

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
