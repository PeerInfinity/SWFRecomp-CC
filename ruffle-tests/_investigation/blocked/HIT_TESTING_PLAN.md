# Hit Testing Implementation Plan
<!-- TESTS: hittest_lockroot, hittest_morph, hittest_morph_input, hittest_winding_rule, text_blocks_clicks, movieclip_hittest, movieclip_hittest_shapeflag, local_to_global, movieclip_getbounds, movieclip_invalid_get_bounds_1, movieclip_invalid_get_bounds_2, movieclip_invalid_get_bounds_3, movieclip_invalid_get_bounds_4, movieclip_invalid_get_bounds_5, movieclip_invalid_get_bounds_6, movieclip_invalid_get_bounds_7, movieclip_invalid_get_bounds_8 -->

Last updated: 2026-03-11

## Status: BLOCKED (remaining tests need loadMovie or morph interpolation; mouse events now implemented)

---

## Current Results

| Test | Lines | Status | Notes |
|------|-------|--------|-------|
| local_to_global | 49 | **PASS** (49/49) | Phases 1-4 complete |
| movieclip_hittest | 92 | **PASS** (92/92) | Phases 4-5 complete |
| hittest_lockroot | 15 | **PASS** (15/15) | Phase 4 + drawing bounds |
| hittest_winding_rule | 12 | **PASS** (12/12) | Phase 6 (shape-accurate + winding rules) |
| movieclip_getbounds | 191 | 186/191 (5 diff) | Rounding precision (-99.9 vs -100) |
| hittest_morph | 70 | **PASS** (70/70) ✅ | Now passing in CI |
| movieclip_hittest_shapeflag | 338 | 266/338 (72 diff) | Was compile_fail, now output_mismatch — edge cases in triangulation approach |
| movieclip_invalid_get_bounds_1 | 75 | **PASS** (75/75) ✅ | Fixed: broadcastMessage MC `this` type + `g_use_new_invalid_bounds` flag |
| movieclip_invalid_get_bounds_2 | 75 | **PASS** (75/75) ✅ | Fixed: root SWF version >= 8 check for sentinel flag |
| movieclip_invalid_get_bounds_3 | 13 | **PASS** (13/13) ✅ | Fixed: onEnterFrame per-function version switching |
| movieclip_invalid_get_bounds_4 | 13 | **PASS** (13/13) ✅ | Same fixes as above |
| movieclip_invalid_get_bounds_5 | 11 | **PASS** (11/11) ✅ | Same fixes as above |
| movieclip_invalid_get_bounds_6 | 10 | 9/10 (1 diff) | Remaining: line 2 expects actual bounds (550.45) from child shape data — needs real bounds in NO_GRAPHICS |
| movieclip_invalid_get_bounds_7 | 10 | 9/10 (1 diff) | Same issue as _6 |
| movieclip_invalid_get_bounds_8 | 11 | **PASS** (11/11) ✅ | Fixed with same sentinel flag changes |
| hittest_morph_input | 1 | Needs re-evaluation | Mouse event dispatch now implemented |
| text_blocks_clicks | 4 | Needs re-evaluation | Mouse event dispatch now implemented |

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

---

## Remaining Failures

### movieclip_getbounds (5 diff lines) — Rounding
Lines 159-160: `-99.9` vs `-100` — sub-pixel rounding precision difference. Not actionable without changing rounding strategy.

### hittest_morph (3 diff lines) — Morph Interpolation
- Lines 61, 66: `xMax: 87.25` vs `32.8` — morph shape bounds need runtime interpolation between start/end bounds based on morph ratio
- Line 68: `hitTest:true` vs `false` — shape-accurate hitTest on fully morphed shape needs interpolated triangle data

Both require morph ratio interpolation infrastructure (runtime lerp of start/end shape bounds and vertex positions).

### movieclip_hittest_shapeflag (145 diff lines) — Triangulation Limitations
Remaining failures come from:
1. **Stroke inclusion**: Flash includes stroke width in shape hit testing; we only test fill triangles
2. **Curve approximation**: Earcut triangulation straightens curves, so curved edges don't match Flash's vector path testing
3. **Degenerate edges**: Points landing exactly on shared triangle edges can get double-counted (2 hits → even-odd says "outside" instead of "inside")
4. **Large triangulated shapes**: Convex shapes like squares produce large triangles that cover more area than the original vector paths when rotated/scaled

Fundamental fix would require vector-path-based hit testing (line segment intersection counting) instead of triangle-based approach.

### movieclip_invalid_get_bounds_6, _7 (1 diff line each) — Shape Bounds in NO_GRAPHICS
Line 2 expects `550.45` (actual shape bounds from loaded child) but we return the sentinel value (6710886.4 / 6710886.35). In NO_GRAPHICS mode, we don't have the child SWF's shape data available after load, so getBounds falls back to the invalid sentinel. Tests 1-5, 8 all PASS after implementing:
1. `g_use_new_invalid_bounds` one-way flag (matches Ruffle's `use_new_invalid_bounds_value`)
2. broadcastMessage MC listener `this` type fix (MOVIECLIP type via `g_override_this`)
3. onEnterFrame per-function SWF version switching (`switchToFunctionVersion`/`restoreFunctionVersion`)

### hittest_morph_input, text_blocks_clicks — Mouse Events Now Implemented
Both require mouse event dispatch infrastructure (onMouseMove, onMouseDown, onPress) which is now fully implemented via input event injection. These tests need re-evaluation — they were previously in `ignored_tests.txt` and have been un-ignored.

---

## Files Modified

### Recompiler (SWFRecomp/)
| File | Changes |
|------|---------|
| `src/swf.cpp` | Emit `ng_record_char_bounds()` and `ng_record_char_winding()` in generated code |

### Runtime (SWFModernRuntime/)
| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | localToGlobal, globalToLocal, hitTest (all forms), getBounds, getRect, COMPUTE_GLOBAL_AABB, drawing bounds tracking |
| `src/libswf/tag_stubs.c` | `ng_char_bounds[]`, `ng_record_char_bounds()`, `ng_record_char_winding()`, `ng_hitTestShapeChar()`, `ng_hitTestShapeFromDL()`, `pit()` |
| `include/libswf/tag.h` | Function declarations for bounds, winding, shape hit test |
