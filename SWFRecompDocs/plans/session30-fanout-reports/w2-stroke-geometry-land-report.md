# s30 w2-stroke-geometry-land: report (wave 2, cloud, implementation)

**NEW files** (all on `fanout/w2-stroke-geometry-land`):
- `SWFRecompDocs/plans/session30-fanout-reports/w2-stroke-geometry-land-report.md` (this file)
- `SWFRecompDocs/plans/session30-fanout-reports/w2-stroke-geometry-land.patch` (= `git diff --binary origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt ruffle-tests/tests/swfs/regression`, i.e. `avm2_display.c` + `action.c` + regression `README.md` + the 6 new fixture dirs; no recompiler change; `git apply --check -R` proven on the branch head)
- 6 new `regression/` image fixtures, each with `test.swf`, `Test.as` (mxmlc source, from the coordinator's capture), `test.toml`, `output.txt` (FP32 trace) and `output.expected.png` (FP32 HIGH, `fp32.lnx.high.png` == `fp32.win.high.png`):
  `ruffle-tests/tests/swfs/regression/avm2_stroke_curve_scale_s1s4/`, `…_s16_w4_k0/`, `…_s16_w4_k1/`, `…_s16_w16_k0/`, `…_s16_w16_k1/`, `avm2_stroke_translucent_round/`
- `SWFRecompDocs/plans/session30-fanout-reports/w2-stroke-geometry-land/` (analysis kit + oracle request)
  - `side.py`, `tbin.py`, `qoff.py`, `qerr.py`: the per-side / per-t edge-offset measurement and the quad-offset models of §3
  - `side_tables.txt`, `tbin_tables.txt`: their outputs (FP32 vs master vs patch)
  - `avm1_curve_scale_s1s4/`: hand-assembled AVM1 twin of the `curve_scale_s1s4` probe (`create_test_swf.py`, `test.swf`, `test.toml`) for the LOCAL ORACLE REQUEST
  - `canary_compare.txt`, `timeline_knob_compare.txt`: render-canary compare outputs
  - `timeline-knob-probe-not-for-landing.patch`: the env-gated `swf.cpp` probe used for §2.2 (NOT in the landing patch)

Edited (not new): `SWFModernRuntime/src/avm2/avm2_display.c`, `SWFModernRuntime/src/actionmodern/action.c`, `ruffle-tests/tests/swfs/regression/README.md` (6 rows appended).

**Box:** cloud, Dawn on lavapipe, `SETUP_STATUS` all OK. Base `origin/master` `5b15b9dd` (code = s29 FINAL `2d40d3799`). Downloaded: avm1 avm2 from_shumway from_gnash visual timeline text swf fonts mixed_avm import_assets audio stage3d at upstream Ruffle `66f9073de`; flash_fixes APPLIED 79. **Fidelity:** w1 proved local == CI md5 on `acid-shapes` and `graphics_gradients`; my clean-master acid-shapes render reproduces w1's numbers exactly (112 728 / 61 385 / 25 688 / 5 575 / 175 / 0 before, 110 967 / 59 069 / 23 568 / 4 615 / 113 / 0 after).

## Verdicts (lead)

| # | Item | Verdict | Priced moves (by name) |
|---|---|---|---|
| 1 | **Land the AVM2 HIGH curve flattening** (`avm2_display.c` `gfx_curve_tol_scale` → `gfx_flatten_cmds`, 0.01 px at HIGH, LOW unchanged, kill switch `SWF_AVM2_CURVE_FINE=0`) | **LANDED.** Render canary: 261/268 comparisons md5-identical, and the 7 that move are exactly the predicted HIGH AVM2 drawing-API curve rows. 0 trace moves. Mode parity is proven on all 18 LOW AVM2 curve rows (no-graphics traces identical). Cost: +55% path-build time, a one-off at draw time | **`from_shumway/acid/acid-shapes` image fail → PASS** (Flash golden == FP32). 6 Flash-golden HIGH rows move toward the golden, 0 status losses. `displayobject_hittestpoint_boundary` +4 (812 → 816 / 900, priced). **6 new FP32-golden `regression/` rows**: FAIL on master, PASS with the patch |
| 2a | **AVM1 drawing-API twin** (`action.c` `drawingCurveFlattenTol`, used by `drawingFinalizePath` + `drawingCmdWindingHitTest`) | **LANDED** (0-row corpus ledger, Flash-ward on the proxy probe). The corpus has NO AVM1 drawing-API curve image row. All 9 AVM1 `curveTo` SWFs (gnash `DrawingApiTest`, `DragDropTest`, `MovieClip-v5..v8`, avm1 `movieclip_hittest_shapeflag`, `movieclip_invalid_get_bounds_6/7`) keep byte-identical traces. A hand-assembled AVM1 twin of the FP32 probe renders **md5-identical to our AVM2 render** on both legs, so it moves exactly as item 1 does: Flash-ward vs the FP32 AS3 capture at every tolerance | 0 corpus moves. FP32 AVM1 capture requested to turn the proxy into a real golden (LOCAL ORACLE REQUESTS 1) |
| 2b | **Timeline twin** (`swf.cpp` `addCurvedEdgeLevien`, `LEVIEN_TOL_TWIPS`) | **HOLD: priced Flash-ward on the canary sample, not landed.** I probed with an env knob (`SWFRECOMP_LEVIEN_TOL_TWIPS=0.2` = 0.01 px; `w2-stroke-geometry-land/timeline-knob-probe-not-for-landing.patch`) on the 117 HIGH canary members with `--recompile`. 30 of 155 comparisons move: **24 toward the golden, 1 away, 5 mixed or flat**, with 0 trace and 0 image status changes. It is HELD for three reasons: (a) one **Flash-golden row moves away**, (b) the canary covers only 117 of the corpus's 238 non-LOW image rows, so the CI-wide ledger cannot name every moved row, (c) the recompiler does not know a test's quality (it needs the plumbing in §2.2) | 0 landed. Probe sample: `visual/simple_shapes/strokes/scale` (FP32 flash_fixes golden) 12 570 → 8 718 at t5 (still fail). Away: `regression/avm1_stroke_pixel_snap_matrix` (**FP32 golden**) 11 730 → 11 856 / 12 000. Mixed: `from_shumway/acid/acid-small` .01/.05 (Flash), t20 +78 / +141 within budget |
| 3 | **Residual convex-side stroke excess**: fit `gfx_build_stroke`'s convex offset | **NO-GO (no clean rule). Premise corrected.** After item 1, our curved strokes sit ON the exact Minkowski offset on both sides at 1:1 (convex −0.02…+0.02 px, concave −0.02…+0.04). The residual is FP32 being **wider than exact**. The excess depends on the half-width, not the scale: about +0.2 px per side at hw 2, +0.7 at hw 8, a **+1.15–1.2 px plateau at hw ≥ 32**, identical for (w4 × s16) and (w16 × s4). It is flat along the curve, not zero at the ends. Quad-offset models (fixed 1/2 pieces, angle-, flatness- and error-subdivided) predict 0 or a mid-curve bump, never the plateau. It is not a fixed device-px bias and not geometry-proportional | 0. Completion: §3.4 |
| 4 | **AVM2 seam twin at HIGH** (`translucent_round` FP32) | **NO-GO: 0 px.** Seam caps do fire on all 4 shapes (3 × 200 tw, 1 × 400 tw). A width gate (≥ 62.5 tw → join, w1's knob) is **md5-identical** (`51c69a04…`). The FP32 diff is pure edge AA: no seam double-blend is visible at HIGH | 0. Not landed |

## EXPECTED-FLIP LEDGER (for the coordinator's CI check)

**Trace axis: NO moves.** All 7 canary DIFFERS rows keep `pass → pass`. The 18 LOW AVM2 curve rows are trace-identical in no-graphics, and the 9 AVM1 `curveTo` SWFs are trace-identical in graphics.

**Pixel axis, status flips:**
- **`from_shumway/acid/acid-shapes` image FAIL → PASS** (t3 112 728 → 110 967 / 113 000; t16 61 385 → 59 069 / 61 300; t32 25 688 → 23 568 / 25 600; t64 5 575 → 4 615 / 5 600; t128 175 → 113 / 180; t200 0 → 0).
- **NEW rows, PASS with the patch** (absent from the baseline, so CI sees them as new rows, not flips): `regression/avm2_stroke_curve_scale_s1s4`, `…_s16_w4_k0`, `…_s16_w4_k1`, `…_s16_w16_k0`, `…_s16_w16_k1`, `regression/avm2_stroke_translucent_round`. They grade at exactly their budgets (0 slack). If CI's lavapipe differs from this box by 1 outlier, the row fails: that would be a fidelity finding, not a regression of the rule.

**Pixel axis, md5 moves without a status change** (all HIGH, all AVM2 drawing-API curves; before → after at the binding check):

| Row | Golden | Before → after | Status |
|---|---|---|---|
| `avm2/graphics_direct_commands` | Flash (exact) | t0 4 642 → 4 576; t32 1 634 → 1 456 / 1 800; t64 262 → 200 / 300 | pass → pass |
| `avm2/graphics_bitmaps` | Flash (exact) | t32 526 → 481 / 600 | pass → pass |
| `avm2/displayobject_getbounds_shape` | Flash (in tol) | t0 3 716 → 3 114 / 3 800 | pass → pass |
| `avm2/bitmapdata_drawwithquality` `high__output.high` | — | t16 3 197 → 3 086 / 3 204 | pass → pass |
| `avm2/blend_shader_luma_lighten` | Flash (exact) | t2 2 833 → 2 824 / 3 300; t64 99 → 91 / 280; t180 0 → 0 | pass → pass |
| `from_shumway/acid/acid-bitmapData-draw` | Flash (exact) | t0 570 → 554 / 650; t32 210 → 190 / 250; t64 26 → 22 / 50 | pass → pass |
| `avm2/displayobject_hittestpoint_boundary` | s27: matches its golden 1:1 | t0 812 → **816** / 900 (**priced +4**, the only row moving away) | pass → pass |
| `avm2/bitmapdata_draw` | not Flash | t0 5 001 → 4 922; t128 753 → 753 / 600 | fail → fail |

The first six rows are canary members (md5 DIFFERS in the canary compare). The last two are not; I ran them A/B by hand. `avm2/graphics_bitmap_fill` is md5-identical (`f756e57b`).

**Everything else: md5-identical.** That covers 261/268 canary comparisons, including every LOW row, every AVM1 row and every timeline row, plus 13 near-change `regression/` rows (all drawing-API users: `avm1_drawapi_stroke_snap`, `avm1_drawing_stroke_scale`, `avm2_drawapi_stroke_snap`, `avm1_holder_drawing_under_children`, …; PNG md5 and traces identical).

## 1. Item 1: AVM2 HIGH curve flattening (landed)

### 1.1 Patch scope
- `SWFModernRuntime/src/avm2/avm2_display.c`:
  - New `static float gfx_curve_tol_scale(void)`, placed before `gfx_flatten_cmds`. It returns 1.0 under `MSAA_SAMPLES == 1` (LOW) and 0.1 otherwise; the env var `SWF_AVM2_CURVE_FINE=0` returns 1.0.
  - `gfx_flatten_cmds`: `ftol *= gfx_curve_tol_scale();`.
  - The prototype's code, cleaned up: the helper now sits outside `gfx_flatten_cmds`'s doc comment, and its rationale comment explains the LOW and no-graphics arms.
- **Functions touched:** `gfx_curve_tol_scale` (new), `gfx_flatten_cmds`.
- **Not touched:** `gfx_build_stroke`, `gfx_flush_stroke_run`, `gfx_finalize_path`, `render_webgpu.c`.

### 1.2 Mode parity (`MSAA_SAMPLES` is only defined in graphics builds)
- **Premise attack.** The gate is `#if defined(MSAA_SAMPLES) && MSAA_SAMPLES == 1`. `verify_output.py` emits `-DMSAA_SAMPLES` only in `--mode=graphics`, so **no-graphics builds take the HIGH (fine) arm even for LOW tests**.
- **Why it matters.** The flattened polygon feeds traces through `fill_verts`: mouse picks (`pick_tris_contain`) and the CPU raster (`BitmapData.draw` → `getPixel`). A LOW row could therefore diverge by mode.
- **Measured.** All 18 LOW AVM2 curve rows in no-graphics, master vs patch (`away3d_advanced_shallow_water_demo`, `bitmapdata_drawwithquality`, `blend_scroll`, `displayobject_mask`, `displayobject_opaque_background`, `displayobject_scrollrect`, `graphics_bad_direct_commands`, `graphics_draw_path`, `graphics_gradients`, `graphics_simple_shapes`, `loader_events`, `loader_loadbytes_events`, `mouse_pick_dobj_mask`, `mouse_pick_non_interactive_dobj_mask`, shumway `MaskTest`, `acid-shapes-testing`, `captions`, visual `definefont4`).
- **Result.** Identical status on every row (17 pass + `acid-shapes-testing` rm), and the 11 saved trace outputs are byte-identical. No mode divergence. The no-graphics leg is optional for this patch.

### 1.3 Chord-count cost (in-process timer, warm runs of 3)
Measured with a temporary `CLOCK_MONOTONIC` accumulator around `gfx_finalize_path` + `gfx_flush_stroke_run` (not shipped):

| Row | Leg | Build time | Flattened points | Stroke vertices |
|---|---|---:|---:|---:|
| `from_shumway/acid/acid-shapes` (heaviest HIGH drawing-API row) | 0.1 px | 7.1–7.4 ms | 5 997 | 42 489 |
| | 0.01 px | 10.8–11.5 ms | 15 282 (×2.55) | 88 326 (×2.08) |
| `avm2/graphics_direct_commands` | 0.1 px | 0.55–0.60 ms | 203 | 336 |
| | 0.01 px | 1.46–1.56 ms | 552 (×2.7) | 768 |

- The build runs once per drawing, not per frame.
- Per-frame GPU cost scales with the ≈2× stroke triangle count.
- The cap is `CURVE_FLATTEN_MAX_SEGS` = 256 per quad, so a huge curve cannot explode.
- A content that redraws thousands of curves per frame pays about +55% path-build CPU.

### 1.4 The FP32 probes as guards
All 6 FP32 probes move Flash-ward at every tolerance (master → patch outliers):

| Fixture | t0 | t16 | t64 | t128 |
|---|---|---|---|---|
| `avm2_stroke_curve_scale_s1s4` | 20 201 → 18 932 | 16 781 → 15 117 | 7 837 → 6 787 | 3 210 → 2 672 |
| `…_s16_w4_k0` | 11 905 → 10 106 | 11 091 → 9 130 | 7 047 → 5 233 | 3 742 → 2 662 |
| `…_s16_w4_k1` | 8 188 → 5 629 | 7 388 → 4 448 | 4 505 → 1 925 | 2 442 → 738 |
| `…_s16_w16_k0` | 31 310 → 28 876 | 30 454 → 27 899 | 25 004 → 22 568 | 15 494 → 13 964 |
| `…_s16_w16_k1` | 22 228 → 19 494 | 21 342 → 18 421 | 17 086 → 14 313 | 10 488 → 8 658 |
| `avm2_stroke_translucent_round` | 2 712 → 2 626 | 1 162 → 969 | 4 → 2 | 0 → 0 |

The `test.toml` budgets are the "after" column, 4 checks each (t0/16/64/128). Master fails every fixture. The README says they guard the rule and are not a Flash-parity verdict.

## 2. Item 2: the twins

### 2.1 AVM1 drawing API (landed)
- **Change.** New `static float drawingCurveFlattenTol(void)` in `action.c`, placed just before `drawingCmdWindingHitTest`'s doc comment:
  - LOW (`MSAA_SAMPLES == 1`): `CURVE_FLATTEN_TOLERANCE`.
  - Otherwise: 0.1 × that. The env var `SWF_AVM1_CURVE_FINE=0` restores 0.1 px.
- **Call sites.** Both flatten sites call it, so the hit test stays in lockstep with the fill: `drawingCmdWindingHitTest` (~`:34342`) and `drawingFinalizePath` (~`:35461`).
- **Functions touched:** `drawingCurveFlattenTol` (new), `drawingCmdWindingHitTest`, `drawingFinalizePath`. Nothing in the native tables (sibling w2-native-*) or the frame loop.
- **Corpus scan** (every `.swf`, zlib-inflated, for `curveTo`): 20 SWFs contain it.
  - **The 10 with image comparisons are all AVM2.**
  - The AVM1 users are trace-only, so the image ledger is empty: gnash `misc-ming.all/DragDropTest` (2 SWFs), `DrawingApiTest`; gnash `actionscript.all/MovieClip-v5..v8`; avm1 `movieclip_hittest_shapeflag`, `movieclip_invalid_get_bounds_6/7` (child SWFs).
- **Trace A/B** (graphics, master tolerance vs fine): all 9 tests byte-identical (6 pass, 2 rm, `movieclip_hittest_shapeflag` unchanged).
- **Proxy oracle.** `w2-stroke-geometry-land/avm1_curve_scale_s1s4/create_test_swf.py` hand-assembles a SWF 8 DoAction with the same 16 cells as the AS3 probe (createEmptyMovieClip / lineStyle / moveTo / curveTo / _xscale / _x).
  - Its trace equals the FP32 AS3 trace byte for byte, so the placement is identical.
  - Our render is **md5-identical to our AVM2 render**: `74ac478f` at 0.1 px and `6a45c037` at 0.01 px.
  - So against the FP32 AS3 PNG it moves 20 201 → 18 932 (t0) … 3 210 → 2 672 (t128), the same as item 1.
  - Flash renders AS2 and AS3 drawing-API shapes with one rasteriser, but that is an inference, so the real FP32 AVM1 capture is requested (LOCAL ORACLE REQUESTS 1). On its arrival, add it as `regression/avm1_stroke_curve_scale_s1s4` with the patch's outliers as budget.
- **Why land on a 0-row ledger.**
  - The two drawing APIs are one renderer in Flash and are md5-identical in ours.
  - Leaving AVM1 at 0.1 px would make them diverge, which they never have.
  - The corpus moves 0 rows.

### 2.2 Timeline (`swf.cpp`)
- **Mechanics.** `addCurvedEdgeLevien` takes its tolerance from `LEVIEN_TOL_TWIPS` (2 tw = 0.1 px at 1:1) via `levienInit` in the plain-shape arm (`swf.cpp` ~`:9969`). The device-font glyph synth (`:3265`) and morph shapes (equal-parameter stepping) are separate paths and were not probed.
- **The probe** (not shipped): `levienTolTwipsProbe()` reads `SWFRECOMP_LEVIEN_TOL_TWIPS`; the patch is in `w2-stroke-geometry-land/timeline-knob-probe-not-for-landing.patch`.
- **Legs.** `after` (this patch, recompiler default) vs `tl` (knob 0.2 tw, `--recompile`), both over the canary's 117 HIGH members. The full table is `w2-stroke-geometry-land/timeline_knob_compare.txt`, graded per check against each golden with the s27 provenance verdict.

| Row (golden) | Move (binding checks) | Direction |
|---|---|---|
| `visual/simple_shapes/strokes/scale` (FP32 flash_fix) | t5 12 570 → 8 718 / 0 | toward (fail → fail) |
| `from_shumway/acid/acid-filter-2` (Flash) | t5 2 144 → 1 148 / 2 500 | toward |
| `from_shumway/acid/acid-clip` (Flash) | t0 6 701 → 6 649; t64 102 → 75 / 140 | toward |
| `from_shumway/acid/acid-morph` (Flash) | t10 3 220 → 3 180; t64 289 → 275 | toward |
| `from_shumway/acid/acid-blend-2` .10/.15/.20/.26/.40 (Flash) | t20 −36…−74 each; .40 t40 1 456 → 1 399 / 1 500 | toward |
| `from_shumway/acid/acid-bitmap-draw_quality_high` (Flash) | t5 33 063 → 32 391; t32 598 → 568 | toward |
| `from_shumway/3_joystick` (Flash) | t32 1 019 → 923 | toward |
| `from_shumway/timeline/timeline_loop` .02 (Flash), .06/.07/.11/.12/.15/.16 (not Flash) | t32 65 → 30 / 70, 84 → 53 / 90 | toward |
| `visual/cache_as_bitmap/masks` .01–.06 (Flash) | t64 134 → 102, 169 → 133, 145 → 126, 142 → 104, 118 → 86, 91 → 85 / 350 | toward |
| **`regression/avm1_stroke_pixel_snap_matrix` (FP32)** | **t2 11 730 → 11 856 / 12 000** | **away** |
| `from_shumway/acid/acid-small` .01 / .05 (Flash) | t0 −12 / +30; t20 +78 / +141; t80 0 / −51 | mixed |
| `regression/avm2_timeline_gradients`, `avm2_timeline_stroke_gradient`, `text/br_at_start` | md5 moves, every check 0 → 0 | flat |

- **Verdict: HOLD.** The sample is clearly Flash-ward, but landing it is not this slot's call.
- **Completion mechanism, in order:**
  1. **Quality plumbing.**
     - `verify_output.py` passes the test's quality to the recompiler: an env var such as `SWFRECOMP_CURVE_TOL_TWIPS` set to 0.2 for non-LOW tests and 2.0 for LOW.
     - It adds that value to `.recomp_mode`'s `want_mode`. The cache-staleness check in `recompile_swf` cannot otherwise see it (I had to rebuild the binary to purge the knob-on caches).
     - Decide the browser/WASM default (`deploy_wasm_demo.sh`, `docs/recompiler/`). HIGH is Flash's default, but about 2.5× static-shape vertices is a real cost for big games, so measure `draws.c` size and frame time on one flasharchive game first.
  2. **Price the remaining 121 non-LOW image rows** outside the canary (the full list is `find ruffle-tests/tests/swfs -name test.toml`, image_comparisons, quality ≠ low). The cheapest route is a CI `images=true` run on a scratch branch that defaults the knob, diffed with `scripts/image_status_diff.py`.
  3. **Disposition `avm1_stroke_pixel_snap_matrix`.** Its comment books about 2.7k of its outliers on "the 10-degree rotated and curve rows (generic AA)". Re-grade it per region before calling the +126 a loss.

## 3. Item 3: the residual convex-side excess (NO-GO, measured)

### 3.1 Method
- `w2-stroke-geometry-land/side.py`:
  - Exact geometry: the distance to the quadratic centreline ≤ hw (round caps and joins, the AS3 default), with 16×16 supersampled exact coverage on edge-band pixels.
  - Each edge pixel is classed **convex / concave / cap-join** by its nearest centreline point.
  - Per side, `offset = (Σ cov − Σ cov_exact) / L_side`, in px, where + means fatter than exact.
- `tbin.py` resolves the convex side per t-decile.
- Tables: `side_tables.txt`, `tbin_tables.txt`.

### 3.2 Result (convex side, px, + = wider than exact; k0 = the 2-curve squiggle, k1 = the single-curve V)

| Cell | hw | FP32 | master | patch |
|---|---:|---:|---:|---:|
| w4 s1 k0 / k1 | 2 | +0.17 / +0.20 | −0.05 / −0.08 | +0.02 / −0.02 |
| w4 s4 k0 / k1 | 8 | +0.35 / +0.04 | −0.20 / −0.24 | −0.03 / −0.02 |
| w16 s1 k0 / k1 | 8 | +0.38 / +0.18 | −0.07 / −0.05 | −0.01 / −0.01 |
| w16 s4 k0 / k1 | 32 | +0.80 / +0.51 | −0.22 / −0.24 | −0.03 / −0.02 |
| w4 s16 k0 / k1 | 32 | +0.73 / +0.03 | −0.79 / −0.85 | −0.09 / −0.10 |
| w16 s16 k0 / k1 | 128 | +0.97 / +0.78 | −0.84 / −0.89 | −0.10 / −0.13 |

- **Ours after the patch sits on the exact offset** (|offset| ≤ 0.03 px at ×1 and ×4).
- What remains at ×16 (−0.1) is the flatten tolerance in **local** pixels (0.01 × 16 = 0.16 px max chord sag). That is a lead (§6), not this item.
- **FP32 is wider than exact.** Per t-decile (`tbin_tables.txt`), FP32's convex excess is a **plateau**: for k0 at hw 32 it is ≈ +1.15–1.2 over t ∈ [0.3, 0.7] at ×16 and ×4 alike, and ≈ +1.2 over almost the whole curve at hw 128.
- It does not scale with the geometry. At hw 32, ×4 and ×16 give the same +1.2 plateau.
- It is not a fixed device bias either: it grows with hw and saturates.
- The concave side is also wider for k0 (+0.05 at hw 2 → +0.8 at hw 128).
- Flash's caps and joins also exceed the exact semicircle (cj +218 px² at hw 128). That is consistent with quadratic arc segments, which bulge about 0.3% of r outside the circle.

### 3.3 Refutations
1. **"Fixed device-px bias"**: refuted. The excess runs 0.2 → 1.2 px with hw.
2. **"Geometry-proportional"**: refuted. At hw 32 the excess is the same at ×4 and ×16.
3. **"Quadratic offset curves, control at the offset-tangent intersection"** (`qoff.py`, `qerr.py`): refuted, in every variant.
   - 1 piece per curve: a bump that is zero at the ends (+1.86 peak at hw 32), and far too large on k1 (+6.7).
   - 2 pieces, or subdivision by angle (22.5–45°), flatness (0.5–2 px) or measured error (0.5–4 px): ≈ 0 on the convex side.
   - None gives FP32's end-to-end plateau.
4. **The brief's "≈0.11–0.18 px convex-only deficit after the prototype" was a deficit relative to FP32, not to the exact geometry.** It is Flash adding width, not us missing coverage. It is also not convex-only: k0's concave side is wider too.

### 3.4 Completion mechanism
- **What would identify the rule:** FP32 captures of straight thick strokes (hw 8 / 32 / 128) and of a full circle `drawCircle` stroke (constant curvature) at the same hw values. Requested in LOCAL ORACLE REQUESTS 2.
- **How to read them:**
  - If straight thick strokes are also ≈ +1.2 px wider at hw ≥ 32, the rule is a width term, `hw' = hw + f(hw)`, and it lands in `gfx_build_stroke` (and `drawingBuildStroke`) as a one-liner. It would need straight-stroke rows priced corpus-wide, because every thick AVM2 stroke would move.
  - If straight strokes are exact, the excess is a curve-offset construction we have not modelled.
- Until then, the new regression rows lock today's geometry.

## 4. Item 4: AVM2 seam twin at HIGH (NO-GO, 0 px)
- **Probe.** A temporary probe (not shipped) logged `seam_caps` per `gfx_build_stroke` call and applied w1's width gate (`2·half_w ≥ 62.5 tw` → join).
- **Without the gate:** seam caps are on for drawRect, drawCircle and drawRoundRect (200 tw) and for drawEllipse (400 tw).
- **With the gate:** caps are off on all four, and the render is md5-identical (`51c69a04f741…`), both before and after item 1.
- **The FP32 diff is edge AA only.** The stroke interiors are uniform (R 128 straight through both seams on the ellipse). Diffs are ±7–64 on edge pixels: 42 ch rect, 964 circle, 320 round-rect, 1 506 ellipse.
- There is nothing to gate, and the corpus case (`graphics_gradients`, w1) was already md5-neutral.
- **Completion:** none needed. Reopen only if a HIGH row shows a seam double-blend.

## 5. Tests run (all on this box, `--mode=graphics` unless stated)
- **Render canary.**
  - `before`: master worktree, 203 tests / 268 PNGs.
  - `after`: final runtime patch, same set.
  - `compare`: 261 IDENTICAL, 7 DIFFERS (the ledger), 0 APPEARED/VANISHED/NO_RENDER, 0 trace status changes, 1 image status change (acid-shapes fail → pass). Output in `w2-stroke-geometry-land/canary_compare.txt`.
- **Timeline-knob canary** (HOLD pricing): `tl` vs `after` over the 117 HIGH members with `--recompile`. 125 IDENTICAL / 30 DIFFERS / 0 status changes. Afterwards the recompiler was rebuilt from clean source, so the knob-on `RecompiledTags` caches are stale and regenerate.
- **HIGH AVM2 curve rows A/B**, by hand: the 10 rows in the ledger table.
- **`regression/`.**
  - The 6 new fixtures: master FAIL, patch PASS at budget.
  - 13 near-change drawing-API rows: identical (`avm1_bitmapdata_draw_child_color`, `avm1_drawapi_stroke_snap`, `avm1_drawing_stroke_scale`, `avm1_hittest_hairline`, `avm1_hittest_shape_stale_matrix`, `avm1_holder_drawing_under_children`, `avm1_mc_super_native_probe`, `avm1_pixelbounds_dynamic_child`, `avm1_textfield_attached_depth_order`, `avm2_bitmapdata_draw_edittext_box`, `avm2_bitmapdata_draw_filtered`, `avm2_drawapi_stroke_snap`, `avm2_simplebutton_click`).
  - The canary's 65 regression members are md5-identical.
- **no-graphics:** the 18 LOW AVM2 curve rows, A/B identical (§1.2).
- **Suites the w1 slot did not download** (from_gnash, timeline, text, swf, misc): scanned. They have **no** AVM2 drawing-API curve image rows. Their canary members (from_gnash ×3, text ×3, fonts ×2) are md5-identical. The gnash AVM1 `curveTo` users are trace-identical (§2.1).

## 6. New unclaimed leads
- **Timeline shape flattening at HIGH** (§2.2): 24 toward / 1 away on the canary sample, including FP32 `strokes/scale` −3.9k. It is the biggest pixel lever this slot found, gated on the recompiler quality plumbing.
- **Scale-aware drawing-API flattening.**
  - `gfx_flatten_cmds` and `drawingFinalizePath` flatten in LOCAL pixels at build time, so a shape scaled ×16 has 16× the chord sag.
  - On master that is −0.8 px on the convex side, −0.1 px after this patch (`side_tables.txt`, s16 cells).
  - Fix: rebuild the path, or pick the tolerance from the max on-screen scale at first render, with a cache keyed on the scale bucket.
  - The six probe rows price it directly: the residual chord share of their outliers.
- **Flash's stroke-width excess** (§3.4): needs the straight/circle FP32 captures.
- **Flash's round caps/joins are larger than the exact semicircle** (cj +28…+218 px² vs exact at hw 8…128). This is consistent with quadratic arc segments, and ours are inscribed polygons. It needs a cap/join-only probe.
- **Flash's LOW curve rule** (from w1, unchanged): LOW keeps 0.1 px in both runtimes.

## 7. Not finished, with completion mechanisms
- **Timeline twin:** HOLD. The completion mechanism is the three steps in §2.2 (quality plumbing + stamp, price the remaining 121 HIGH image rows, disposition `avm1_stroke_pixel_snap_matrix`).
- **AVM1 twin's real golden:** LOCAL ORACLE REQUEST 1. Then add `regression/avm1_stroke_curve_scale_s1s4`.
- **Flash's stroke-width rule (item 3):** LOCAL ORACLE REQUEST 2, then the fit in `gfx_build_stroke` / `drawingBuildStroke`.
- **The no-graphics leg was not run corpus-wide.** It is not needed: the patch has no `NO_GRAPHICS` arm, and §1.2 shows trace identity on every LOW curve row, the only rows where no-graphics behaviour differs from graphics.

**Suggested register edits** (for the coordinator):
- **NO-GO §1b `acid-shapes` row:** resolved (passes on stock MSAA-4 geometry; "needs BOTH" refuted by w1, now landed).
- **AA row:** acid-shapes' structural residue is fixed. The reopen gate now waits on `acid-mask` and `strokes/scale` only. Note that the timeline twin moves `strokes/scale` 12 570 → 8 718.

## LOCAL ORACLE REQUESTS
1. **FLASH: `SWFRecompDocs/plans/session30-fanout-reports/w2-stroke-geometry-land/avm1_curve_scale_s1s4/`** (`test.swf` + `create_test_swf.py`; SWF 8, AVM1, hand-assembled).
   - Capture: image, HIGH, `run_image.py` **direct** (normal blend, so `draw()` is fine), 1 frame; plus the trace in DIRECT mode.
   - Compare with `curve_scale_s1s4/fp32.lnx.high.png`. If byte-identical, the AVM1 twin's proxy golden is confirmed, and the PNG becomes `regression/avm1_stroke_curve_scale_s1s4`'s golden.
   - Expected trace: 16 `w=… s=… k=… f=… at x,y` lines + `bottom 352`, identical to the AS3 probe.
2. **FLASH (new fixture, the coordinator builds it with mxmlc): straight + circle thick strokes**, to identify §3's width excess.
   - Stage 900×700, black background, `lineStyle(w, 0x49D0D7)`, round caps, HIGH, direct.
   - (a) a horizontal and a 30°-rotated straight `lineTo` of length 200 at w ∈ {4, 16, 64} (hw 2 / 8 / 32), integer translation;
   - (b) `drawCircle(r=100)` stroked at the same w;
   - (c) the same as (a) and (b) inside a Sprite at scale 4 with w/4, to separate hw from scale.
   - Compare: the per-side width excess vs exact, using `side.py`'s method.

