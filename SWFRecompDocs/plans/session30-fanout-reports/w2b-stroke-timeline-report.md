# s30 w2b-stroke-timeline: report (wave 2b, cloud, implementation)

**NEW files** (all on `fanout/w2b-stroke-timeline`):
- `SWFRecompDocs/plans/session30-fanout-reports/w2b-stroke-timeline-report.md` (this file)
- `SWFRecompDocs/plans/session30-fanout-reports/w2b-stroke-timeline.patch` (= `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`; `git apply --check -R` proven on the branch head; no new fixture dirs)
- `SWFRecompDocs/plans/session30-fanout-reports/w2b-stroke-timeline/` (evidence kit):
  - `prescreen_codegen.tsv`: every non-LOW test dir (239 image + 2 813 trace-only), recompiled-output md5 at 2 tw vs 0.2 tw (`SHAPE`) and the font probe (`FONT`), `draws.c` size and recompile time
  - `codegen_changed_image_tests.txt` (24), `codegen_changed_trace_tests.txt` (97), `font_leg_changed_image_tests.txt` (12)
  - `image_ab_grade.txt`: per-comparison before → after, every check vs its golden, plus L1 distance to the golden
  - `font_probe_grade_not_landed.txt`: the embedded-glyph leg (not landed)
  - `canary_compare.txt`: standing render canary, before vs after
  - `prescreen.py`, `child_pre.py`, `grade.py`, `cellsl1.py`: the scripts behind the tables

Edited (not new): `SWFRecomp/src/swf.cpp`, `ruffle-tests/verify_output.py`.

**Box:** cloud, Dawn on lavapipe, `SETUP_STATUS` all OK. Base `origin/master` `0224aaf2` (code = `a18a0e033` batch 2, w2-stroke-geometry-land landed). Downloaded avm1 avm2 from_shumway from_gnash visual timeline text swf fonts mixed_avm import_assets audio stage3d (upstream Ruffle master `66f9073de`), flash_fixes APPLIED 83. `from_avmplus` not downloaded (asc-built ABC-only SWFs, no DefineShape).
**Fidelity:** my clean-master renders are md5-identical to CI's actual PNGs on the `ruffle-image-results` branch (18:08 today) for `visual/simple_shapes/strokes/scale`, `acid-mask` .01 and .05. So local grading is CI-grade on those rows.
**Before leg = master, proven:** the master binary (worktree build of `origin/master`) and my binary with the variable unset/`2` produce md5-identical recompiled trees on all 127 tests whose code changes.

## Verdicts (lead)

| # | Item | Verdict | Priced moves |
|---|---|---|---|
| 1 | **Land the timeline HIGH curve flattening** (`swf.cpp` `shapeCurveTolTwips` → `levienInit` in the plain-shape arm: 0.2 tw = 0.01 px at 1:1 for non-LOW tests; LOW keeps 2 tw) | **GO.** All three HOLD reasons are closed: (a) below, (b) the whole corpus is enumerated by codegen, (c) quality plumbed from `verify_output.py` | **0 status flips, both axes.** 60 image comparisons md5-move: Flash/FP32-golden rows **toward the golden on 47, away on 3** (`scroll_rect_scaled`, `acid-small` .01/.05: priced below). `strokes/scale` (FP32) 12 570 → 8 718 (L1 −67%). Trace: 97 codegen-changed rows byte-identical |
| 1a | HOLD reason (a): `regression/avm1_stroke_pixel_snap_matrix` 11 730 → 11 856 | **Refuted as a geometry regression.** Not a snap-rule effect: curve chords never carry the axis flags (exact `x0 == x1` / `y0 == y1` only). All 126 extra outliers are in the 16 tiny (16 × 10 px) thin-stroke curve cells, where **every stroke pixel is already an outlier** (Flash's 1 px stroke is wider than ours), so the count measures footprint, not error. Distance to the FP32 golden **drops**: L1 507 036 → 503 439 (−0.71%) whole image, 74 685 → 73 643 (−1.4%) on the curve cells, 11 of 16 cells closer | Stays PASS (11 856 / 12 000). No budget change |
| 1b | HOLD reason (b): only 117 / 238 non-LOW rows were priced | **Closed by enumeration, not sampling.** Recompiled every non-LOW test dir (239 image tests, 330 non-LOW comparisons, + 2 813 trace-only dirs + every child SWF) at both tolerances. Only **24 image tests** and **97 trace tests** change generated code. Every other row is md5-identical by construction (the runtime is untouched). All 24 + 97 were run before/after | ledger below, by name |
| 1c | HOLD reason (c): the recompiler does not know the quality | **Plumbed via env, chosen by measurement.** `verify_output.py` `get_curve_tol_twips()` passes `SWFRECOMP_CURVE_TOL_TWIPS` = 2 for a LOW main build, 0.2 otherwise, for the main SWF **and child SWFs**, and stamps it into `.recomp_mode`. Unset = 2 tw = master byte for byte (browser/deploy builds unchanged). "Emit both + `#if MSAA_SAMPLES`" was rejected: tag code holds literal `shape_data` offsets (`tagDefineShape(..., 0, 66, ...)`), so dual emission means dual offsets through every frame function, for a 2.4× table that is compiled anyway | LOW: 0 moves by construction |
| 2 | Embedded-glyph shapes (`DefineFont*` through the same arm) | **Not landed; keep 2 tw.** Probe: 0.2 tw moves code in 12 image + 225 trace tests (all text) for 2 PNG moves, both tiny and toward (`br_at_start` L1 −0.4%, `Video-EmbedSquareTest` −0.2%). Glyph units are already fine in device space: 2 units of a 1 024-unit em at 12 px text is 0.023 px (DefineFont3's 20 480 em: 0.001 px) | 0 |
| 3 | Device-font glyph synth (`swf.cpp` ~3265) | **Same rule already; no change.** It flattens at 0.1 in font-units/20, i.e. 0.1 / 102 em for a 2 048-unit TTF: 0.012 px at 12 px, 0.02 px at 20 px. That is the 0.01 px HIGH rule at text sizes | 0 |
| 4 | Morph stepping (`morphChordCount`, equal-parameter, 1 tw, floor 6) | **Pixel-inert on the corpus; no change.** A probe knob (not shipped) at 0.2 tw and at 0.01 tw changes `acid-morph`'s `draws.c` (2 525 → 3 143 → 5 423 lines), yet **all 11 morph image comparisons** (`acid-morph`, gnash `morph_test1`, shumway `invalidClipDepth`, `regression/avm1_parent_child_morph`, `avm2_morph`, `avm1_morph_instances_ratio`) render md5-identical. There is no FP32 morph capture (the `w1-local-oracles/w1-stroke-geometry/` captures are all AVM2 drawing API). Nothing to grade, nothing to land | 0 |

## EXPECTED-FLIP LEDGER (for the coordinator's CI check)

**Trace axis: NO moves.** 97 trace tests whose recompiled code changes (92 main-SWF + 5 child-SWF-only: `movieclip_invalid_get_bounds_6/7`, `loader_duplicate_class`, `mouse_pick_loader_avm1`, shumway `avm1movie`) give **byte-identical trace text** before/after (93 pass, 3 rm, 1 output_mismatch, all unchanged). Every other trace row is codegen-identical. The **35-row hitTest family**: 7 run A/B (`avm1/movieclip_hittest`, `movieclip_hittest_shapeflag`, `avm2/button_hittest`, `displayobject_hittestobject`, `displayobject_hittestpoint`, `movieclip_hittest`, shumway `mask-hit-test`): identical. 27 are codegen-identical. 1 (`avm2/displayobject_scrollrect`) is a LOW build (2 tw = master).

**Pixel axis, status flips: NONE.**

**Pixel axis, md5 moves without a status change** (all graded against the golden at every check; L1 = sum |actual − golden|, the direction measure; full table `w2b-stroke-timeline/image_ab_grade.txt`):

| Row | Golden (s27 provenance) | Before → after at the checks | L1 | Dir |
|---|---|---|---|---|
| `visual/simple_shapes/strokes/scale` | **FP32** (flash_fix) | t5 12 570 → 8 718 / 0 (fail → fail) | −67.3% | toward |
| `from_shumway/acid/acid-filter-2` | Flash exact | t5 2 144 → 1 148 / 2 500 | −9.8% | toward |
| `from_shumway/acid/acid-video` .01 / .10 / .20 | Flash exact | t5 16 008 → 13 422, 15 478 → 13 459, 13 280 → 10 860; t50 246 → 157, 240 → 156, 105 → 52 | −11…−13% | toward |
| `from_shumway/acid/acid-clip-2` | Flash exact | t0 2 886 → 2 821; t32 1 044 → 828; t64 219 → 171 | −12.8% | toward |
| `from_shumway/acid/acid-clip` | Flash | t0 6 701 → 6 649; t64 102 → 75 / 140 | −5.6% | toward |
| `from_shumway/acid/acid-color-2` | Flash exact | t0 5 714 → 5 671; t32 1 299 → 1 208; t52 64 → 38 | −3.8% | toward |
| `from_shumway/3_joystick` | Flash in tol | t32 1 019 → 923 / 2 500 | −3.4% | toward |
| `import_assets/avm1_imports_avm1` (child `right_eye.swf`) | Flash exact | t100 36 → 27 / 500 | −3.3% | toward |
| `from_shumway/acid/acid-mask` .01 / .05 / .10 | Flash exact | t4 12 018 → 11 993, 10 915 → 10 811, 9 447 → 9 390 / 20 (fail → fail) | −1.4 / −2.9 / −2.3% | toward |
| `from_shumway/acid/acid-bitmap-draw_quality_high` | Flash exact | t5 33 063 → 32 391; t32 598 → 568 | −1.8% | toward |
| `from_shumway/acid/acid-morph` | Flash exact | t10 3 220 → 3 180; t64 289 → 275 | −1.5% | toward |
| `from_shumway/acid/acid-blend-2` .10 .15 .20 .26 .40 | Flash exact | t20 −36 / −71 / −53 / −74 / −58; .40 t40 1 456 → 1 399 / 1 500 | −0.4…−0.6% | toward |
| `visual/cache_as_bitmap/masks` .01–.06 | Flash in tol | t64 134 → 102, 169 → 133, 145 → 126, 142 → 104, 118 → 86, 91 → 85 / 350 | −3.7…−9.0% | toward |
| `visual/blend_modes/overlay_onto_stage` | Flash in tol | t0 33 908 → 33 898; t16 1 194 → 1 179; t32 48 → **49** / 60 | −0.5% | toward |
| `from_shumway/timeline/timeline_loop` .02 (Flash), .07/.12 (not Flash, same image) | Flash exact (.02) | t32 65 → 30 / 70 | −28.4% | toward |
| `from_shumway/timeline/timeline_loop` .06 .11 .15 .16 | not Flash | t32 84 → 53 / 90 | −18.5% | toward |
| `regression/avm1_stroke_pixel_snap_matrix` | **FP32** | t2 11 730 → **11 856** / 12 000 | −0.7% | toward by L1, +126 count (§1a) |
| `from_shumway/acid/acid` .01–.18 | not Flash | t0 −28…+4 each; t128 unchanged (one 200 → 198) | −0.6…−1.8% | toward |
| **`visual/cache_as_bitmap/scroll_rect_scaled`** | Flash exact | t0 2 299 → **2 328** / 2 800; t64 697 → **712** / 900 | **+2.0%** | **away** (§2.2) |
| **`from_shumway/acid/acid-small` .01 / .05** | Flash exact | t0 −12 / +30; t20 +78 / +141 (10 176 / 20 000, 8 916 / 21 000); t80 0 / −51 | **+0.4 / +0.5%** | **away** (mixed) |
| `regression/avm2_parent_child_render` (child `child.swf`) | our own render (L1 0 before) | t0 0 → 252 / 400 | — | self-golden, still PASS |
| `regression/avm2_timeline_gradients`, `avm2_timeline_stroke_gradient` | our own render, t255 | 0 → 0 | — | flat |
| `regression/avm2_timeline_solid` | no golden (skip) | md5 move | — | — |

Md5-identical despite a code change: `from_shumway/bitmapbuttons`, `cache_as_bitmap/masks` .07. All 11 font-only tests are md5-identical (fonts keep 2 tw).

**Everything else: md5-identical** (by construction: identical generated code and an untouched runtime). The standing render canary confirms it: see §4.

## 1. Patch scope

- `SWFRecomp/src/swf.cpp`:
  - New `static float shapeCurveTolTwips(bool is_font)`, after `LEVIEN_TOL_TWIPS`. It reads `SWFRECOMP_CURVE_TOL_TWIPS` once (accepted range (0, 64]); unset or invalid → `LEVIEN_TOL_TWIPS` (2 tw). It returns 2 tw for `is_font`.
  - `SWF::interpretShape` plain-shape CurvedEdgeRecord arm: `levienInit(..., shapeCurveTolTwips(is_font))` instead of `LEVIEN_TOL_TWIPS`.
  - Not touched: `levienInit` (cap 64 kept: at 0.2 tw it binds on 3 curves in the whole changed set, all in `movieclip_hittest_shapeflag`, trace-identical), the morph arm, the device-font synth, the stroke builder.
- `ruffle-tests/verify_output.py`:
  - New `get_curve_tol_twips(test_dir)`: an explicit `SWFRECOMP_CURVE_TOL_TWIPS` wins (A/B legs); otherwise `"2"` if `get_msaa_samples(test_dir) == 1`, else `"0.2"`.
  - `recompile_swf`: passes it in the recompiler's env and adds `curve_tol=…` to the `.recomp_mode` stamp, so a cached tree from the other tolerance regenerates. (Every cached tree regenerates once, because the stamp text changes.)
  - `recompile_child_swf(..., curve_tol=None)`: same env for loaded children. Both call sites (`compile_native`, `compile_wasm`) pass `get_curve_tol_twips(test_dir)`. Without this, `avm1_imports_avm1` and `avm2_parent_child_render` would flatten the parent fine and the child coarse.
- **Runtime: untouched.** No `NO_GRAPHICS` arm, no `swf_core.c` / `tag_stubs.c` edit. The tolerance follows the test's `quality`, not the build mode, so no-graphics and graphics builds recompile identically (mode parity by construction).
- **`[subtests]` variants**: they reuse the main build's recompiled code. The corpus has exactly one mixed-quality test, `avm2/bitmapdata_drawwithquality` (LOW main, so 2 tw; drawing API only, so its codegen does not move at all).

### 1.1 Why env plumbing and not "emit both, select by `MSAA_SAMPLES`" (measured)
- **Size.** `draws.c` grows 2.3–2.5× on curve-heavy content: `3_joystick` 742 782 → 1 770 095 B (object 293 → 701 KB), `acid-clip` 213 760 → 528 046, `avm1_stroke_pixel_snap_matrix` 1.22 → 1.48 MB, `acid-video` 665 → 880 KB. Emitting both would carry 3.3–3.5× the master size.
- **Build time.** Compiling `draws.c` at `-O2`: 0.10 → 0.23 s (`3_joystick`), 0.04 → 0.08 s (`acid-clip`). Recompile time is unchanged within noise (0.24 → 0.35 s for `3_joystick`, the largest). It is data, not code, so cost is noise either way.
- **Structural cost.** `shape_data` offsets are literal arguments in the generated tag code, so dual emission needs dual offsets in every frame function. Env plumbing is 20 lines, and `verify_output.py` already knows the quality (`get_msaa_samples`).

### 1.2 Browser / deploy default: unchanged (decision left open, priced)
With the variable unset, the recompiler emits master's bytes. So `deploy_wasm_demo.sh`, `docs/recompiler/` and the in-browser recompiler keep 0.1 px timeline curves, while CI grades HIGH rows at 0.01 px. To make the shipped player match: set `SWFRECOMP_CURVE_TOL_TWIPS=0.2` in those builds (or flip the default). The cost is about 2.4× shape-table size on curve-heavy content (`.data` in the WASM). Measure frame time on one flasharchive game before flipping. Not decided in this slot.

## 2. The two "away" rows (priced losses)

### 2.1 `regression/avm1_stroke_pixel_snap_matrix` (HOLD reason a), refuted as a loss
- **Where.** Per-row outlier counts (18 px bands): rows 0–25 identical. All movement is in row 26 (16 × 10 px curve, 1 px stroke: 877 → 906 px) and row 27 (2 px stroke: 750 → 763 px).
- **Snap rule? No.** `stroke_snap_data` flags (`swf.cpp` stroke emission, `pv_flags`) need an exactly vertical/horizontal chord in float coordinates. Levien points on these curves never produce one, so no curve chord is snapped on either leg. The snap rule does not depend on chord ends here.
- **Why the count rises.**
  - Flash's thin curved stroke carries more ink than ours on both legs (cells 13 133–15 610 vs ours 12 475–14 387, 1 px row): the stroke-width excess the w2 report §3 measured.
  - So every stroke pixel is an outlier at t2 on both legs, and the count is the stroke's footprint.
  - Finer chords shift a few pixels in and out of the footprint (per cell −9…+33 channels).
- **Distance to FP32 decreases.** L1 on the curve cells is 74 685 → 73 643; 11 of 16 cells get closer, and o=15 / o=18 get worse. Whole image: −0.71%.
- **Disposition.** Keep the budget (11 856 / 12 000 passes). The fixture's comment already books the curve rows as "generic AA".

### 2.2 `visual/cache_as_bitmap/scroll_rect_scaled` (Flash exact): +29 @t0, +15 @t64, L1 +2.0%
- **The shape.** A 150 px circle (`CHARID(1)`, bounds 0..3000 tw) under a scaled scrollRect.
- **The straight edges are already off.** Flash puts the left/top straight edges on the integer pixel: column 33 has coverage 1.0. Ours sits at x + 0.5: coverage 0.5, the whole 12 px band reads 11.5 vs 12.0. This is the row's own `# FIXME Object's size is wrong` (upstream).
- **Along the arc, Flash is inside both our legs.** Per-row coverage: Flash 1 399.5, master 1 409.7, patch 1 416.7 px. Measured from Flash's own straight edges, Flash's arc sits about 0.6–0.75 px inside ours.
- **Why this row moves away.** Finer chords move our convex arc outward, toward the exact circle and away from Flash. Coarse chords had partly hidden a size/offset bias, which is the same object-size bug.
- **Disposition.** A priced loss within budget (2 328 / 2 800, 712 / 900). The lead is the object-size FIXME (§6), not the curve tolerance.

### 2.3 `from_shumway/acid/acid-small` .01 / .05 (Flash exact)
- Mixed per check: t0 −12 / +30, t20 +78 / +141, t80 0 / −51. L1 +0.4% / +0.5%.
- Both rows stay far inside budget (t20 10 176 / 20 000, 8 916 / 21 000).
- Not decomposed further: the content is many small shapes at fractional scale, and the move is below 1% of the residual.

## 3. Font, device-font and morph paths (brief: "same rule or not, by FP32")
- **The w1 FP32 captures cannot answer this.** `w1-local-oracles/w1-stroke-geometry/` holds only AVM2 drawing-API captures (`curve_scale_*`, `translucent_round`). There is no FP32 morph, glyph or timeline capture, so the verdicts here are by geometry and by corpus A/B.
- **Embedded glyphs (`DefineFont*`)** run the same arm, so the brief's question applies.
  - Probe at 0.2 tw: code moves in 12 image tests + 225 trace tests (every text test).
  - Pixels: 2 of 40 PNGs move, both toward, both < 0.5% L1 (`font_probe_grade_not_landed.txt`).
  - Glyph units are em-relative, so 2 units is already ≈ 0.02 px (DefineFont2) or ≈ 0.001 px (DefineFont3) at body sizes. That is effectively the HIGH rule already.
  - **Not landed** (`is_font` → 2 tw): a 225-row trace surface for 2 sub-percent PNGs.
- **Device-font synth** (`swf.cpp` ~3265): 0.1 in font-units/20 ≈ 0.012–0.02 px at 12–20 px text. Same rule; leave it.
- **Morph** (`morphChordCount`): md5-inert on all 11 corpus morph comparisons even at 0.01 tw (§ verdict 4). Leave it. Reopen with an FP32 morph capture only if a morph row shows a chord artefact.

## 4. Tests run (all on this box, `--mode=graphics`, `--recompile` on every leg after a recompiler rebuild)
- **Codegen prescreen** (`prescreen_codegen.tsv`): 3 052 non-LOW test dirs × {2, 0.2 tw, font 0.2 tw}, plus every child SWF in them (`child_pre.py`: 10 child SWFs in 9 tests change; 2 are image tests already in the image set, and of the 7 trace tests 2 were already listed via their main SWF and 5 were added).
- **Image A/B** (`render_canary.py capture`, `-P 2`):
  - Legs: `before` (35 tests: the 24 shape + 12 font-changed, one in both), `shape` (env 0.2), `font` (env font 0.2), `after` (the final plumbing, no env).
  - `after` == `shape` md5 on all 62 comparisons. `before` vs `after`: 60 DIFFERS (the ledger), 0 status changes.
- **Trace A/B**: `tr_before` (env 2) vs `tr_after` (plumbing) on the 97 trace tests. Trace text is byte-identical on 97/97.
- **Standing render canary** (205 tests, `c_before` = env 2 vs `c_after` = plumbing): result in `w2b-stroke-timeline/canary_compare.txt`: **241 IDENTICAL / 29 DIFFERS / 0 APPEARED, VANISHED or NO_RENDER, 0 trace and 0 image status changes; 65/65 saved trace texts byte-identical.** The 29 are exactly the canary members of the ledger (3_joystick, acid-bitmap-draw_quality_high, acid-blend-2 ×5, acid-clip, acid-filter-2, acid-morph, acid-small ×2, timeline_loop ×7, avm1_stroke_pixel_snap_matrix, avm2_timeline_gradients, avm2_timeline_stroke_gradient, cache_as_bitmap/masks ×6, strokes/scale). Every LOW member is md5-identical
- **`regression/` suite**:
  - 325 non-LOW regression dirs are screened by codegen.
  - 5 change (`avm1_stroke_pixel_snap_matrix`, `avm2_parent_child_render`, `avm2_timeline_gradients`, `avm2_timeline_solid`, `avm2_timeline_stroke_gradient`); all keep their status (ledger).
  - The remaining 320 are codegen-identical, including every `*stroke*`, `*hittest*`, `*morph*` and `avm2_stroke_curve_scale_*` fixture. LOW regression dirs are 2 tw by construction.
- **no-graphics:** not run. The patch has no runtime change, and the recompiled code depends only on `test.toml` quality, which is identical in both modes.

## 5. Not finished, with completion mechanisms
- **Browser/deploy default** (§1.2): open product decision. Mechanism: measure the WASM `.data` size and frame time on one flasharchive game with `SWFRECOMP_CURVE_TOL_TWIPS=0.2`, then set it in `deploy_wasm_demo.sh` / the in-browser recompiler, or flip the default.
- **Morph / glyph FP32 confirmation**: not needed for this landing (both paths unchanged). Optional LOCAL ORACLE REQUEST 1 would turn the glyph argument into a measurement.

## 6. New unclaimed leads
- **`scroll_rect_scaled` object-size / edge offset** (§2.2): our straight edges sit at +0.5 px against Flash's integer edges under a scaled scrollRect + cacheAsBitmap; the arc is consistent with the same bias. The upstream FIXME names it ("Object's size is wrong"). It is worth a w1 slot: 2 328 / 2 800 outliers today.
- **Flash thin-stroke ink excess on curves** (`avm1_stroke_pixel_snap_matrix` rows 26–27: Flash +3…+10% ink on 1 px curved strokes). This is the timeline twin of w2-stroke-geometry-land §3's width excess, and the same FP32 straight/circle capture request (theirs, LOCAL ORACLE REQUESTS 2) prices both.
- **Morph rows ignore chord count** (§3): `acid-morph`'s morph vertices change 2× with no pixel move. Either the corpus morphs are straight at the captured ratios, or `renderer_draw_morph` does not read the refined vertices. Cheap to check (dump the morph instance's vertex count at draw time) before anyone touches morph flattening.

## LOCAL ORACLE REQUESTS
1. (Optional, low priority) **FLASH: embedded-font glyph flattening.** A DefineFont3 glyph with one large quadratic bowl (e.g. "O"), rendered as static text at 12 px and at 200 px (`_xscale` 1 600), HIGH, image direct, 1 frame. Compare against our render at the glyph's 2 tw vs 0.2 tw to confirm §3's "already fine at body sizes", and to see whether a 200 px glyph wants the finer rule. Our renders on both legs can be produced on request. Mind the DefineFont2 code-table trap (BRIEFS_COMMON): check the fixture in Flash first.
