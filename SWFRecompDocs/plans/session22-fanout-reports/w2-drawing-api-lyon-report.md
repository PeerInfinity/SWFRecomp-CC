# Session 22 · wave 2 · `w2-drawing-api-lyon`: drawing-API lyon parity (runtime only)

**New files from this slot (stage by name):**
- `SWFRecompDocs/plans/session22-fanout-reports/w2-drawing-api-lyon-report.md` (this file)
- `SWFRecompDocs/plans/session22-fanout-reports/w2-drawing-api-lyon.patch`
  (`git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`;
  touches `SWFModernRuntime/src/actionmodern/action.c`, `SWFModernRuntime/src/avm2/avm2_display.c`,
  `ruffle-tests/render_canary_tests.txt`; no new source files, no fixtures, no recompiler change)

## Verdict: GO. +4 pixel flips, 0 pass→fail, 0 trace moves

| ledger row (pixel axis) | CI / before (outliers, max diff) | after | limit (tol, max outliers) | mechanism |
|---|---|---|---|---|
| `from_shumway/MaskTest [output]` | FAIL 1 (max 255) | **PASS 0 (max 0)** | (0, 0) | drawCircle via `gfx_emit_round_rect` |
| `avm2/displayobject_opaque_background [output]` | FAIL 2 (max 255) | **PASS 0 (max 0)** | (1, 0) | drawCircle via `gfx_emit_round_rect` |
| `visual/drawing_api/fills_and_lines [output]` | FAIL 4 (max 255) | **PASS 0 (max 2)** | (2, 0) | AVM1 miter predicate + MiterClip. **Zero headroom**: max diff 2 = tol 2 |
| `avm2/graphics_draw_path [output]` | FAIL 4 (max 255) | **PASS 0 (max 0)** | (0, 0) | lyon cubic (`gfx_add_cubic`) |
| band: `avm2/graphics_gradients [output]` | FAIL 349 (max 73) | FAIL 148 (max 73) | (1, 0) | circle part; residual is the stroke self-overlap (→ `w1-stroke-staircase`) |

**Trace axis: no expected flips.** Every swept test keeps its trace status (99 pass, 2 `ruffle_matched`
(`graphics_draw_path`, `acid-shapes-testing`, both already `ruffle_matched` on CI), 1 pre-existing
`output_mismatch`). Note `graphics_draw_path` flips on the PIXEL axis only; its trace stays `ruffle_matched`.

These match the wave-1 prototype pricing to the outlier (rows 1, 2, 7, 8, and the 349 → 148 band).
Wave-1 proved cloud-vs-CI render byte identity on all four ledger rows, and my *before* counts equal
CI's counts on every one of them, so the verdicts are CI-grade.

## EXPECTED-FLIP LEDGER (coordinator: check CI against this)

Pixel axis (`images=true` run), fail → pass:
- `from_shumway/MaskTest` [output]
- `avm2/displayobject_opaque_background` [output]
- `visual/drawing_api/fills_and_lines` [output] (passes AT the tolerance: max diff 2, tol 2)
- `avm2/graphics_draw_path` [output]

Pixel axis, expected band moves (still failing):
- `avm2/graphics_gradients` 349 → 148 (tol 1)
- `avm2/bitmapdata_draw` 39803/37079/24578 → 39959/37081/24580 (already far over 5200/1500/600)
- `avm2/graphics_direct_commands` 6601/4270/2503/587 → 6597/4264/2503/589
- `avm2/blend_shader_luma_lighten` 40323/26497/1237 → 40318/26497/1237
- `from_shumway/acid/acid-shapes` 112717/61374/25681/5574/175/0 → 112728/61385/25688/5575/175/0 (tol-3 check still under its 113000 limit; the failing tol-16/32 checks move +11/+7)
- `avm2/graphics_bitmaps` (CI PASS, stays PASS) 959/709/525 → 959/711/526 (limits 4000/800/600)

Trace axis: none.

## Patch scope (runtime only; `gfx_*` drawing helpers + the AVM1 stroke-join twin)

`SWFModernRuntime/src/avm2/avm2_display.c`
1. **drawCircle / drawEllipse → `gfx_emit_round_rect`** (the existing port of Ruffle
   `draw_round_rect_internal`). Argument order checked against Ruffle `45366370e`
   `core/src/avm2/globals/flash/display/graphics.rs:826` (circle: `x-r, y-r, 2r, 2r`, all radii `r`)
   and `:862` (ellipse: `x, y, w, h`, radii `w/2, h/2`). The old code built anchors with `cos/sin`,
   and the top anchor `r·cos(3π/2) = −1.8e‑16` truncated a whole twip low (MaskTest pixel).
2. **`gfx_add_side`**: the four round-rect side LineTos skip themselves when they land exactly on the
   (twip-quantized) pen, i.e. on every circle/ellipse. Without it `avm2/graphics_bitmaps` regresses
   (wave-1: 525 → 648 / limit 600). With it: 526 / 600.
3. **`gfx_add_cubic`** (new, static): port of lyon_geom 1.0.6
   `CubicBezierSegment::for_each_flattened_with_t` → `for_each_quadratic_bezier_with_t`. Twip-truncated
   cubic, `num_quadratics_impl(0.4·tol)` equal-t sub-cubics via `split_range` (lyon's derivative-hull
   form, not the blossom form of the prototype), `to_quadratic()`, recorded as cmd **type 3** (not
   re-quantized), which `gfx_flatten_cmds` flattens at **0.8·tol**. All f32 in lyon's operation order
   (verified against the crate source, `static.crates.io` lyon_geom 1.0.6 `cubic_bezier.rs:32,153,344,384,519,565`).
   Used by `cubicCurveTo` and by `drawPath` CUBIC_CURVE_TO (`gfx_decode_path` case 6), replacing
   8 fixed least-squares quadratics and 16 equal-t quantized lines respectively.
   Type-3 consumer audit: `Avm2GfxCmd` is read only by `gfx_flatten_cmds` (and the `type != 0` seed
   test at the stroke flush), so no other consumer needed a change.
4. **Miter**: `gfx_stroke_join` keeps the full miter while `|m| = 1/cos_half ≤ 2·limit`
   (lyon_tessellation 1.0.15 `stroke.rs:2320` `miter_limit_is_exceeded`), else **MiterClip**: the clip
   line ⟂ the bisector at `limit·0.5·half_w` (`stroke.rs:2114-2121`, `get_clip_intersections:2279`),
   emitted as a 3-triangle fan. `gfx_stroke_extra_verts` bound 6 → 9 (the only sizing of the join buffer).

`SWFModernRuntime/src/actionmodern/action.c`: the same miter predicate + MiterClip in
`drawing_emit_stroke_join` (AVM1 drawing API) and `drawing_stroke_extra_verts` 6 → 9. AVM1 has no
drawCircle / cubicCurveTo, so that is the whole AVM1 side. `fills_and_lines` is AVM1 (DoAction, no
DoABC), so the AVM1 twin is the one that flips it; the AVM2 twin moves `graphics_direct_commands` /
`away3d` (identical) only.

`ruffle-tests/render_canary_tests.txt`: appended `visual/drawing_api/fills_and_lines` (MiterClip, AVM1,
zero headroom) and `avm2/graphics_draw_path` (lyon cubic) at EOF as tier 2. The standing set saw only
the circle class (via `graphics_bitmaps`); neither the miter nor the cubic change moved any standing member.

Not taken from the prototype (sibling-owned): `swf.hpp`/`swf.cpp` (w2-float-verts), the glyph ÷8 hunks in
`avm2_display.c`/`avm2_bitmap.c` and `abc_*.cpp` (w2-glyph-subunit). All `// PROBE` markers removed.
No `NO_GRAPHICS` arms touched; headline tests also compile and pass trace in no-graphics mode
(`fills_and_lines`, `graphics_direct_commands`, `graphics_draw_path`: 3/3 effective pass).

## Evidence: per-test A/B (same cloud box, clean `origin/master` `e783f14e5` vs patch)

Method: `render_canary.py capture` (graphics, `--images`, keeps every PNG, md5 + per-check outliers)
over the **standing canary (60 unique tests; `visual/fonts/leading_device_font` is listed twice) + 44 drawing-API users** = 104 tests / 134 comparisons, `-P 2`.
Two canary members (`fonts/device_font_kerning`, `text/auto_size/width`) were not downloaded during the
first *before* leg; I captured their *before* separately on the clean tree (label `before2`): identical.

Totals: **134 comparisons: 4 fail→pass, 102 pass→pass, 26 fail→fail, 2 skip→skip. 0 pass→fail.**
124 of 134 PNGs md5-identical; the 10 that moved are exactly the ledger rows above.

```
avm2/bitmapdata_draw              [output] fail 39803/37079/24578 -> fail 39959/37081/24580
avm2/blend_shader_luma_lighten    [output] fail 40323/26497/1237  -> fail 40318/26497/1237
avm2/displayobject_opaque_background [output] fail 2 (max 255)   -> PASS 0 (max 0)
avm2/graphics_bitmaps             [output] pass 959/709/525       -> pass 959/711/526   (limits 4000/800/600)
avm2/graphics_direct_commands     [output] fail 6601/4270/2503/587 -> fail 6597/4264/2503/589
avm2/graphics_draw_path           [output] fail 4 (max 255)       -> PASS 0 (max 0)
avm2/graphics_gradients           [output] fail 349 (max 73)      -> fail 148 (max 73)
from_shumway/MaskTest             [output] fail 1 (max 255)       -> PASS 0 (max 0)
from_shumway/acid/acid-shapes     [output] fail 112717/61374/25681/5574/175/0 -> fail 112728/61385/25688/5575/175/0
visual/drawing_api/fills_and_lines [output] fail 4 (max 255)      -> PASS 0 (max 2)
all other 124 comparisons (94 tests): md5-identical PNG and identical trace status
```

### Sweep membership (argued scope: every SWF in my categories containing a drawing-API name)
Found by string-scanning the decompressed SWFs (`lineStyle|drawCircle|drawEllipse|drawRoundRect|cubicCurveTo|drawPath|drawGraphicsData|curveTo|miter`):
- **avm1** (7; the wave-1 gap): `hitarea_sweep`, `movieclip_begin_gradient_fill`, `movieclip_hittest_shapeflag`,
  `movieclip_invalid_get_bounds_6`, `movieclip_invalid_get_bounds_7`, `movieclip_line_gradient_style`,
  `movieclip_setmask` (+ canary `mask_with_drawing`). All md5-identical: no AVM1 corpus test outside
  `visual/` uses a miter joint past its limit. `visual/drawing_api/*` (4, AVM1) identical except `fills_and_lines`.
- **avm2** (27): every circle/ellipse/roundRect user (the wave-1 §4.3 list plus `blend_scroll`,
  `displayobject_getrect`, `loader_events`, `loader_loadbytes_events`, `mouse_pick_*`, `mouse_sibling`),
  every cubic/drawPath/GraphicsData user (`graphics_bad_direct_commands`, `graphics_bitmap_fill`,
  `graphics_direct_commands`, `graphics_draw_path`, `graphics_draw_triangles`, `graphics_path`),
  plus `away3d_advanced_shallow_water_demo` (miter), `bitmapdata_opaque`, `displayobject_getbounds_shape`,
  `displayobject_hittestpoint_boundary`, `stage3d_texture`.
- **from_shumway** (10): `MaskTest`, `acid-bitmapData-draw`, `acid-morph`, `acid-shapes`, `acid-shapes-testing`,
  `blendmode_3`, `captions`, `mouse/{mouse_coords,start_drag,start_drag_lock}`.
- **visual** (5): `cache_as_bitmap/drawing_api`, `definefont4`, `drawing_api/{cursor,drawing_order,fills_and_lines}`.

### Regression suite
`regression/avm2_graphics_runtime` (the only `regression/` test that uses the drawing API) is in the
sweep: trace pass, PNG md5-identical. No new behaviour lacks a corpus test (all four mechanisms are
graded by the ledger rows), so no new fixture.

### Standing canary
All 60 standing members: md5-identical and status-identical except `avm2/graphics_bitmaps` (stays PASS,
525 → 526 at the tol-32 check, limit 600; the wave-1 measured value with the zero-length-side skip).

## Refutations / premise checks
- Brief premise "the AVM1 miter users live in `avm1/`" is **refuted**: no `avm1/` test moves. The only
  corpus AVM1 miter-past-limit user is `visual/drawing_api/fills_and_lines` (AVM1, v15 SWF, DoAction only).
- The prototype's blossom-form `split_range` and my lyon-exact derivative-hull form gave the same verdicts
  (`graphics_draw_path` 0 outliers, max diff 0); I kept the lyon-exact form so f32 rounding follows lyon.

## Not finished
Nothing in scope. `graphics_gradients` residual 148 is the width-10 translucent stroke self-overlap
(completion: `w1-stroke-staircase`'s lyon stroke triangulation port), not this slot.

## New unclaimed leads
1. `fills_and_lines` passes at zero headroom (max diff 2 = tol 2); now a canary member so a 1-level drift is caught.
2. `avm2/graphics_direct_commands` (still failing by ~600 at tol 0) and `acid-shapes` move by a handful
   of pixels with every geometry change; neither is close to its limits, so no cheap flip there.

## LOCAL ORACLE REQUESTS
none. Ruffle source at `45366370e` (blobless clone) and the lyon_tessellation 1.0.15 / lyon_geom 1.0.6
crate sources were enough. Corpus: `download_tests.sh avm1 avm2 visual from_shumway` (+ `fonts text`
for two canary members); the script prints no upstream SHA; my Ruffle clone taken the same hour is at `45366370e`.
