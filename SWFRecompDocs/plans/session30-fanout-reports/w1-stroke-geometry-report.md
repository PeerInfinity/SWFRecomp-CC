# s30 w1-stroke-geometry: report (wave 1, cloud, diagnosis + measured prototype)

**New files** (all under `SWFRecompDocs/plans/session30-fanout-reports/`):
- `w1-stroke-geometry-report.md` (this file)
- `w1-stroke-geometry-prototype.patch`: one function added and one call changed in `avm2_display.c`. Apply with `git apply`.
- `w1-stroke-geometry/`
  - `curve_board_base_vs_fine.txt`: the 25-row A/B ledger.
  - `acid-stroke-0-diffmask.png`.
  - `probes-not-for-landing.patch`: env-gated diagnostic knobs, listed in §6.
  - Analysis scripts: `shapes.py` parses the `GFXD` dump, `model2.py` is the analytic Flash-HIGH raster model, `evalC.py` / `sideGO.py` / `sideAO.py` / `sideMM.py` / `classify.py` build the side tables, `modelB.py` / `runB.py` / `runD.py` / `evalE.py` are the geometry hypotheses, and `grade.py` / `summ.py` / `sweep.sh` / `runk.sh` are the drivers.

**Box:** cloud, Dawn on lavapipe, `SETUP_STATUS` all OK.
- Base: `origin/master` `f4edebdc`, code = s29 FINAL `2d40d3799`.
- Tests downloaded: from_shumway, avm2, visual, avm1. Upstream Ruffle master was `66f9073de` and flash_fixes applied cleanly.

**Fidelity (CI-grade local grading):** my clean-master renders are **md5-identical to CI's actual PNGs** on `origin/ruffle-image-results` for two rows:
- `from_shumway/acid/acid-shapes`: `50b2e338…`. It grades 112 728 / 61 385 / 25 688 / 5 575 / 175 / 0, exactly the pre-launch README §3 numbers.
- `avm2/graphics_gradients`: `ceb84879…`, 296 outliers.

## Verdicts (lead)

| # | Item | Verdict | Priced moves (by name) |
|---|---|---|---|
| 1 | `acid-shapes` curved-stroke edge geometry | **GO: prototype FLIPS the row on stock MSAA-4.** Owner: AVM2 drawing-API curve flattening (`avm2_display.c` `gfx_flatten_cmds`, lyon tolerance 0.1 px). It is not the stroker (`gfx_build_stroke`), not lyon offsetting, and not `render_webgpu.c`. Fix: flatten curves at 0.01 px at HIGH only. | **`from_shumway/acid/acid-shapes` fail → PASS** (t16 61 385 → 59 069 / 61 300, t32 25 688 → 23 568 / 25 600, t128 175 → 113 / 180). Flash-golden HIGH rows all move toward Flash, 0 status losses (§2). |
| 1b | AA NO-GO reopen criterion (register §1b) | **NO-GO STANDS. The criterion is met for acid-shapes, but the row does not need AA.** Geometry alone flips it. AA + geometry passes with a wide margin (t128 86/180), and AA alone still fails (t128 189/180). AA's cost elsewhere drops by one: Flash-golden `getbounds_shape` goes from an AA loss (3998/3800) to an AA pass (3607/3800) with the geometry fix. | AA would still flip **0** rows the geometry does not. Its cost becomes **−6 Flash-golden + −4 regression** passes (was −7/−4). |
| 2 | `acid-stroke-0` (LOW, tol 0, 3 413 ch) | **Diagnosed, HOLD.** The TSNAP +369 is already gone (w2b's unsnapped hairline: depths 49/59 → 0 px). 59% of the rest is LOW **diagonal** stroke raster, 22% corners/caps, 19% axis edges. 43% sits on one specimen column, the 45°-rotated rects. | No flip available at tol 0. Owners and completion mechanisms in §3. |
| 3 | AVM2 seam-join twin (`gfx_build_stroke` / `gfx_stroke_seam_caps_on`) | **Priced: 0 px. NO-GO as a pixel item, low-risk hygiene only.** I instrumented 13 AVM2 stroke rows. The only corpus row with seam caps on a wide translucent stroke is **`avm2/graphics_gradients`** (Flash-exact golden, LOW): translucent gradient strokes 200 tw and 80 tw wide, 3 seams. A width gate (≥ 62.5 tw at build scale → join) fires on all 3 seams and the render is **md5-identical**. | 0 moves. |
| 4 | Vertex weld before `tessAddContour` in `drawingUnionTris` | **REFUTED / NO-GO.** On the w3 case (`avm1/movieclip_line_gradient_style`, caps forced back on), the union's input is already on an integer-twip lattice. A weld at 1/64, ¼ or 1 twip is md5-neutral, and only a 1-px weld changes anything (773 → 651, wrong geometry). libtess2's output is exact: on all 14 union calls the symmetric difference with the input union is 0.000, pairwise overlap 0.000, there are no T-junctions and no slivers. Yet the double-blended diagonal (255,50,53 vs 255,138,140) persists. **The sliver is downstream of the union**, not in it. | 0. Weld not worth landing. Completion mechanism in §5. |

## 1. Item 1: `acid-shapes` (HIGH, 1 tick, golden == FP32 exactly)

### 1.1 Ledger vs FP32 (golden == FP32; checks t3/16/32/64/128/200, budgets 113 000 / 61 300 / 25 600 / 5 600 / 180 / 0)

| Leg | t3 | t16 | t32 | t64 | t128 | t200 | status | L1 vs FP32 |
|---|---:|---:|---:|---:|---:|---:|---|---:|
| master (MSAA-4) | 112 728 | **61 385** | **25 688** | 5 575 | 175 | 0 | FAIL | 2 812 517 |
| **prototype** (0.01 px flatten, fill + stroke) | 110 967 | 59 069 | 23 568 | 4 615 | 113 | 0 | **PASS** | 2 669 508 |
| stroke flatten only, 0.05 px | 111 982 | 60 333 | 24 602 | 5 108 | 149 | 0 | PASS | 2 743 693 |
| stroke flatten only, 0.01 / 0.001 px | 111 532 / 111 569 | 59 793 / 59 765 | 24 177 / 24 130 | 4 884 / 4 851 | 138 / 133 | 0 | PASS | — |
| fill flatten only, 0.01 / 0.001 px | 112 163 / 112 115 | 60 661 / 60 599 | 25 079 / 25 026 | 5 306 / 5 293 | 150 / 139 | 0 | PASS | 2 770 214 |
| faithful HIGH AA rule (`scan_run.py`, `-DSSAA_PROBE -DSSAA_VSNAP`) | 79 456 | 34 633 | 17 111 | 4 004 | **189** | 0 | FAIL | 1 847 967 |
| **AA rule + prototype** | 81 695 | 32 558 | 15 181 | 2 997 | 86 | 0 | **PASS** | 1 757 015 |

Notes on the ledger:
- The stroke half and the fill half each flip the row independently. The squiggles are strokes only; the curved fills are the ellipses, circles and round-rects further down.
- s29 measured the AA-rule leg at 210/180. The s29 B landing (`w2-pixel-gaps-land`) has since taken it to 189.

### 1.2 Mechanism and evidence

- **Owner.** The squiggles are AS3 drawing-API shapes: `lineStyle(4)`, then `moveTo`, then two `curveTo` calls, with round caps and joins. The recompiler's `swf.cpp` builders are therefore not on the path. The flattener used is `gfx_flatten_cmds` (`curve_flatten_init`, lyon tolerance `CURVE_FLATTEN_TOLERANCE` = 0.1 px). The stroke is built by `gfx_build_stroke` as per-chord quads plus round joins at every chord vertex.
- **Flash has no chords.** Flash rasterises quadratic edges natively. Our chords sit inside the curve on the convex side, so both the fill and the stroke's outer edge are pulled in.
- **The direct measurement does not depend on a model.** I recovered every squiggle's commands and placement with an env-gated dump (`GFXD`; 119 squiggles, `tx` / `ty` from `do_set_x` / `do_set_y`). For each edge pixel I took the FP32 coverage minus ours, measured along the stroke colour, and binned it by which side of the curve the pixel is on.

  | Edge class (squiggles, n px) | FP32 − ours, master | FP32 − ours, prototype |
  |---|---:|---:|
  | straight 4-px polylines (control set, same test) | +0.034 | +0.034 (untouched) |
  | round caps | +0.045 | +0.058 |
  | concave side, R < 30 px | −0.026 | +0.029 |
  | concave side, R ≥ 30 px | +0.005 | +0.071 |
  | **convex side, R < 10 / R < 30 / R ≥ 30** | **+0.208 / +0.217 / +0.162** | +0.178 / +0.179 / +0.112 |

  FP32 matches us on straight strokes and caps, and on the concave side. On the **convex side of every curve, at every curvature**, FP32 covers about 0.2 px more. That is the t128 residue: FP32 paints stroke colour where we leave background.
- **The prototype fixes only part of it.** It removes about 0.03–0.05 of the convex deficit and spreads the curve slightly outward on both sides. **About 0.11–0.18 px of convex-only deficit remains**, and it is not explained by flattening (§4 refutations). The row flips because the outward move pushes enough edge pixels under the t16/t32 budgets. Margins: t16 −2 231, t32 −2 032, t128 −67. This is an honest geometry move toward Flash (L1 −5.1%, and the three Flash-golden HIGH rows below move the same way), not the full Flash rule.
- **Calibrated against the exact geometry.** I built an analytic Flash-HIGH raster (`model2.py`: 4 sub-rows at y + j/4, exact x coverage, n = floor(16·cov)) and compared it with ours, using the straight-line rows as the AA-model baseline. Relative to the exact Minkowski offset, our convex edge is about **0.16 px inside**, while FP32 sits on the exact offset (within ±0.03) on the convex side. The excess is flat in R and present only on the convex side.

### 1.3 Item 1b: AA reopen-criterion verdict (explicit)

- **Would AA + this geometry flip the row?** Yes (t128 86/180). But the geometry alone already flips it. AA adds no flip on acid-shapes or on any other row I measured.
- **What AA still costs.**
  - w1-aa-sizing's 7 Flash-golden and 4 regression passes lost, minus `displayobject_getbounds_shape`. Under the AA rule that row goes from 3998/3800 (loss) to **3607/3800 (pass)** with the prototype.
  - The remaining cost is **6 Flash-golden passes** (`acid-blend-2` ×3, `acid-color-2`, `flash_text_TextField2`, `edittext_selection`.02; none of them use drawing-API curves) **and 4 `regression/` passes**, for 0 flips.
- **NO-GO register §1b row:**
  - Update the reopen criterion: acid-shapes' structural residue is fixed by the geometry, so the row no longer needs AA.
  - Re-run the gate once `acid-mask`, `strokes/scale` and `graphics_draw_triangles` are fixed.
  - Correct the acid-shapes row ("needs BOTH" no longer holds; see §4 refutation 1).

## 2. Prototype pricing: the AVM2 curve board (every image row using `curveTo` / `drawCircle` / `drawEllipse` / `drawRoundRect` / `cubicCurveTo` / `drawPath` / `GraphicsPath`)

**Scope.** I scanned the downloaded suites (avm2, from_shumway, visual, avm1, regression; SWF strings, zlib-inflated) for these APIs. There are 25 image rows: 9 HIGH and 16 LOW. No `regression/` SWF uses them, so the regression suite is unaffected by construction.

**Legs.** One build per row, with the knob run off and on. The prototype is md5-identical to the knob leg on HIGH rows (acid-shapes `d7ad9c55`, `graphics_direct_commands` `abaf4a4c`) and md5-identical to master on LOW rows (`graphics_gradients` `ceb84879`).

**Trace axis:** all 25 rows keep their trace status.

**HIGH rows (the prototype's moves):**

| Row | Golden | Binding check: master → prototype | Status |
|---|---|---|---|
| `from_shumway/acid/acid-shapes` | Flash (== FP32) | t16 61 385 → 59 069 / 61 300 | **fail → PASS** |
| `avm2/graphics_direct_commands` | Flash (exact) | t64 262 → 200 / 300 | pass → pass (toward Flash) |
| `avm2/graphics_bitmaps` | Flash (exact) | t32 526 → 481 / 600 | pass → pass (toward Flash) |
| `avm2/displayobject_getbounds_shape` | Flash (in tol) | t0 3 716 → 3 114 / 3 800 | pass → pass (toward Flash; now survives the AA rule) |
| `avm2/bitmapdata_drawwithquality` `high` subtest | — | t16 3 197 → 3 086 / 3 204 | pass → pass |
| `avm2/displayobject_hittestpoint_boundary` | s27: matches its golden 1:1 | t0 812 → **816** / 900 | pass → pass, **priced +4** |
| `avm2/blend_shader_luma_lighten`, `from_shumway/acid/acid-bitmapData-draw` | Flash (exact) | 0 → 0 at the binding check (md5 moves) | pass → pass |
| `avm2/bitmapdata_draw` | not Flash | 753 → 753 / 600 | fail → fail |
| `avm2/graphics_bitmap_fill` | Flash | md5-identical | — |

**Why HIGH-only.** On LOW rows, 0.01 px flattening moves both ways.
- Away from the golden:
  - `avm2/graphics_gradients` (Flash) 296 → 386;
  - `avm2/blend_scroll` (FP32 swap) 391 → 397;
  - `graphics_draw_path` 192 → 248;
  - `mouse_pick_dobj_mask` 99 → 111, `mouse_pick_non_interactive_dobj_mask` 90 → 99 (both untestable goldens);
  - `displayobject_mask` 38 → 40.
- Toward the golden:
  - `acid-shapes-testing` (Flash) 9 219 → 8 385;
  - `displayobject_opaque_background` 280 → 254;
  - `displayobject_scrollrect` 152 → 148;
  - `MaskTest` 115 → 96.

Flash's LOW curve rule is not "exact". That is a separate fit for w1-lowq-residues' family (lead below). The prototype keeps LOW at lyon's 0.1 px via `#if MSAA_SAMPLES == 1`.

**Not covered:**
- Suites not downloaded here: `from_gnash`, `timeline`, `text`, `swf`, the misc categories, `from_avmplus`. The render canary was not run, because wave 2 must run it.
- Rows that change `stage.quality` at runtime keep their compile-time arm.
- Cost: chord count rises by about √10 ≈ 3.2× on HIGH drawing-API curves.

**Patch scope** (`w1-stroke-geometry-prototype.patch`, `avm2_display.c` only):
- New `static float gfx_curve_tol_scale(void)`: returns 0.1 at HIGH, 1.0 at LOW. Kill switch `SWF_AVM2_CURVE_FINE=0`.
- `gfx_flatten_cmds`: `ftol *= gfx_curve_tol_scale()`.

Not touched: `gfx_build_stroke`, `gfx_flush_stroke_run`, `gfx_finalize_path`, `render_webgpu.c`, `action.c`, `swf.cpp`.

## 3. Item 2: `from_shumway/acid/acid-stroke-0` (LOW, tolerance 0, golden FP32-provenance, `known_failure`)

The CI actual PNG (s29 FINAL) against the golden gives **3 413 channels over 1 216 px**. The diff mask is `w1-stroke-geometry/acid-stroke-0-diffmask.png`.

Table: rows are the 5 specimen rows, row 5 being 1-px hairlines. Columns are the 11 specimen columns: col 4 is the 45°-rotated rects, cols 6/7 the ±shear parallelograms, col 11 the red shear.

| | c1 | c2 | c3 | **c4** | c5 | c6 | c7 | c8 | c9 | c10 | c11 | Σ |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| r1 | 9 | 9 | 12 | 156 | 12 | 84 | **471** | 6 | 0 | 0 | 56 | 815 |
| r2 | 9 | 21 | 15 | **522** | 12 | 12 | 42 | 6 | 0 | 15 | 8 | 662 |
| r3 | 9 | 15 | 12 | 180 | 12 | 12 | 12 | 6 | 0 | 12 | 8 | 278 |
| r4 | 9 | 15 | 15 | 276 | 9 | 84 | 72 | 9 | 9 | 15 | 56 | 569 |
| **r5 (1 px)** | 0 | 0 | 0 | **345** | 0 | **312** | 90 | 0 | 0 | 0 | **342** | 1 089 |
| Σ | 36 | 60 | 54 | **1 479** | 45 | 504 | 687 | 27 | 9 | 42 | 470 | 3 413 |

By local edge orientation (PCA over the ink in a 7×7 window): diagonal 2 004 (59%), corner/cap 745 (22%), axis 664 (19%).

**What owns it:**
1. **LOW diagonal stroke raster, about 2.0 k ch.**
   - Owner: `render_webgpu.c`, the LOW stroke raster (`lowq_stroke_width` / band rule) that landed in `6a27fc2e0`.
   - The biggest block is col 4 at every width. The lower-left edge of the 45° rotated rect is 1 px low (w1-lowq-next §"rows 58–84").
   - In row 5 (1-px hairlines), our diagonal 1-px lines have **gaps** (dropped runs) where FP32 draws continuous lines: c4, c6, c11, about 1 k. This is w2b's HOLD "1-px diagonal hairline raster".
   - Completion: w2b's per-row Bresenham fit on probe rows 7–11, plus the 45° 1-px-low edge fit. Both belong to the w1-lowq-residues sibling's family (LOW rules in `render_webgpu.c`).
2. **Corners, caps and joins at LOW, about 0.75 k.**
   - Short horizontal ticks at the parallelograms' acute corners: r1 c7 471 and r4 c6/c7.
   - Completion: w2b's HOLD "rect corner / seam chamfer at LOW", fitted from probe rows 3–5.
3. **Axis edges, about 0.66 k.** Mostly 1-channel colour noise on box edges (c1–c3, c5, c8–c10 at 6–21 ch per cell).
4. **TSNAP: no longer an owner.** s29's priced +369 sat on depths 49/59, and both are at 0 px since w2b's unsnapped hairline.

The row is tol 0 and `known_failure`, so it cannot flip without all three owners fixed exactly. Value it by cells, not by status.

## 4. Refutations / premise attacks

1. **The brief's "fixing the curved-stroke geometry alone does not flip the row (t16/t32 are AA)" is refuted** (pre-launch README §3 and NO-GO register §1b).
   - The t16/t32 excess is edge pixels, but they are geometry-sensitive edges.
   - A 0.01 px flatten (or a 0.05 px stroke-only flatten) passes every check on stock MSAA-4.
2. **"Thick quadratic-curve offsetting" (Flash offsets each quadratic as a quadratic, control at the intersection of the offset tangents) is refuted.**
   - Modelled with 1, 2 and 4 pieces per curve, as the difference from the exact offset (the bias cancels).
   - k=1 fattens **both** sides, scaling with curvature (+0.37 at R<10, +0.04 at R≥30).
   - FP32's excess is **convex-only and flat in R** (+0.16…+0.22).
   - k ≥ 2 converges to the exact offset, which leaves the deficit untouched.
3. **"A uniformly wider Flash pen" is refuted.**
   - Same test, same 4-px pen: straight polylines differ from FP32 by +0.034 and caps by 0.000.
   - The excess exists only on curves' convex side.
   - (The `nsig` R45 = 7.60 px measurement is an 8-px rect stroke under a rotated matrix, a different path. Not used.)
4. **"Join on curves" is not the owner.** Our AVM2 stroker emits a round join at every chord vertex, so its outer edge is a superset of lyon's flattened-step miter. The deficit is not a join gap.
5. **The brief's location (`swf.cpp` / lyon) is wrong for this row.** acid-shapes is AS3 drawing API. The `RecompiledTags` shape data is empty; everything goes through `avm2_display.c`.
6. **Item 4's premise ("near-coincident vertices leave libtess2 slivers") is refuted.** See the Verdicts table: the union input is integer-twip, the output is exact, conforming and free of slivers, and every weld ≤ 1 twip is md5-neutral.
7. **Item 3's premise (the AVM2 twin needs the on-screen scale to fix a visible row) is refuted on the corpus.** The only corpus case renders md5-identically with joins. A HIGH translucent case could still differ; see §5.

## 5. HOLD / NO-GO completion mechanisms

- **Remaining convex-side deficit, about 0.11–0.18 px (item 1, after the prototype).**
  - Unexplained by flattening, quad offsetting or pen width.
  - Next probe: a scaled-up fixture (one `curveTo` squiggle at ×1, ×4, ×16, `lineStyle(4)` and `lineStyle(16)`, HIGH). FP32 capture requested below.
  - This separates a fixed device-px bias (Flash stroking in a coarse fixed-point space, e.g. edges rounded outward) from a geometry-proportional one.
  - Only after that, re-fit `gfx_build_stroke`'s convex offset.
- **The timeline and AVM1 twins of item 1 are NOT done.**
  - `swf.cpp` `addCurvedEdgeLevien` (`LEVIEN_TOL_TWIPS` = 2 tw = 0.1 px) and `action.c`'s drawing-API flattener (`curve_flatten_init` at about `action.c:35438`) use the same 0.1 px chords.
  - Timeline shapes touch hundreds of rows. Price them with the render canary at HIGH only, in wave 2.
- **Item 4's real owner, downstream of the union.**
  - With the seam gate forced off, the double-blended diagonal appears although the drawn soup (`tag.c` `render_drawing_path`: `line_verts`, with the snap path inactive; `SWF_STROKE_SNAP_DRAWAPI=0` is md5-identical) is an exact non-overlapping union.
  - Completion: find which draw writes those pixels. Instrument `renderer_draw_gradient_tris` for that path, or capture per-draw. If the paths are confirmed duplicate, consider stencil-then-cover for translucent strokes, which makes double coverage impossible by construction.
  - w3's gate already removes the case from the corpus, so this is LOW priority.
- **AVM2 seam twin (item 3).** Mirror `drawing_seam_join_wanted` in `gfx_build_stroke` only when a HIGH translucent row shows it. A FLASH fixture request is below. With no AS3 compiler in the cloud, the coordinator builds the fixture.

## 6. Diagnostic knobs used (in `w1-stroke-geometry/probes-not-for-landing.patch`; none ship)

`avm2_display.c`:
- `GFX_DUMP`: `gfx_line_style` / `gfx_move_to` / `gfx_line_to` / `gfx_curve_to` / `gfx_begin_fill` / `do_set_x` / `do_set_y`.
- `GFX_FTOL_S` / `GFX_FTOL_F`: stroke and fill flatten tolerance, in `gfx_flatten_cmds` and `gfx_flush_stroke_run`.
- `GFX_SEAM_REPORT` / `GFX_SEAM_GATE`: in `gfx_build_stroke`.

`action.c`:
- `SWF_UNION_WELD` / `SWF_UNION_DUMP`: in `drawingUnionTris`.
- `SWF_SEAM_JOIN_GATE=0`: in `drawing_seam_join_wanted`.

The AA leg used s29's `w1-aa-sizing-prototype.patch` unchanged (it still applies to master) and its `scan_run.py`.

## New unclaimed leads

- **Timeline and AVM1 curve flattening at HIGH** (`swf.cpp` `addCurvedEdgeLevien`, `action.c` drawing API): the same 0.1 px chord deficit. Price it on the canary, HIGH only.
- **Flash's LOW curve rule.** At LOW, exact curves move Flash-golden rows both ways: `graphics_gradients` away, `acid-shapes-testing` toward. A LOW curve fit (coarser stepping?) belongs to the LOW family.
- **The remaining convex-only stroke bias** (§5 first bullet): the open half of acid-shapes' geometry.
- **Translucent drawing-API stroke double blend survives an exact union** (§5): a draw-submission bug candidate in `tag.c` / the renderer.

## LOCAL ORACLE REQUESTS

1. **FLASH: curved-stroke scale probe** (new fixture; the coordinator builds it, since there is no AS3 compiler in the cloud). Image, HIGH, `run_image.py` direct (draw() is fine: normal blend).
   - Stage 600×400, black background.
   - Squiggles copied from acid-shapes: `moveTo(0,0); curveTo(20,0,20,20); curveTo(10,30,0,20)` and `moveTo(0,0); curveTo(10,30,20,0)`.
   - Each in a Sprite at scaleX = scaleY ∈ {1, 4, 16}, with `lineStyle(4, 0x49D0D7)` and `lineStyle(16, 0x49D0D7)`.
   - Integer and .3-px translations.
   - Purpose: decide whether the residual convex-side excess (§1.2, about +0.11–0.18 px at 1:1) scales with geometry or is a fixed device-px bias.
2. (Optional) **FLASH: HIGH translucent wide closed round stroke, AVM2.** `graphics.lineStyle(10, 0xFF0000, 0.5); drawRect(20,20,80,40)` and the same with `drawCircle`. Image, HIGH, direct. It decides whether the AVM2 seam twin (item 3) is visible at HIGH.
