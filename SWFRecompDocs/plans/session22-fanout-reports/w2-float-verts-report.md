# w2-float-verts — session 22, wave 2 (cloud): sub-twip vertex remainders in the recompiler

**New files (all under `SWFRecompDocs/plans/session22-fanout-reports/`):**
- `w2-float-verts-report.md` (this file)
- `w2-float-verts.patch`: **the patch to apply.** It is `git diff origin/master --` over
  `SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`
  plus the two doc files the brief asked for (`ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md`,
  `SWFRecompDocs/plans/graphics-fanout-playbook.md`). Runtime and `verify_output.py` are untouched.
- `w2-float-verts-2-morph.patch`: the optional morph leg. It applies **on top of** the main patch.
  Verdict **HOLD: do not apply** (it moves 0 pixels and 0 traces; see §5).
- `w2-float-verts-tools/`: `recdiff.py` (the recompile-only A/B filter from §3), `grade2.py` /
  `checksN.py` (grade captures with `verify_output.compare_images`, per check), `ht_trace.sh`
  (the no-graphics hit-test sweep), and the raw tables they produced.

No new source files and no new fixtures. Box: `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe).
Corpus: `download_tests.sh visual from_shumway avm1 avm2 text fonts from_gnash` (plus
`stage3d import_assets` for the sweep) from upstream master **`45366370e`**
(`git ls-remote`, 2026-10-16 23:49 UTC). Base: origin/master `63b9255a6`.

## 0. Verdicts

| item | verdict |
|---|---|
| **A + B + C (strokes, fills, lyon arc count)** | **GO. +22 CI-grade flips, −1 (`acid-small output.05`, as predicted). 0 trace moves.** It reproduces w1's prototype numbers row for row, on the same box class. |
| `sizeof(Vertex) == 16` | Enforced with a `static_assert` in `swf.hpp`. |
| `heavy_tesselation` recompile under `ulimit -v 4194304` | **OK.** Peak RSS: 2554 MB (master) → **3052 MB**. VmPeak (what `ulimit -v` caps): 2782 MB → **3391 MB of 4096**, so about 700 MB of headroom is left. It flips (2439/3 → 3/3). |
| Broader sweep of CI-passing rows | **Done exhaustively, not by sample.** All 260 CI-passing image tests were recompiled with both recompilers. 42 produce different generated code, and every one of those was rendered. **One pass→fail (`acid-small .05`). Every other moved pass row still passes. The tightest margin is now `cache_as_bitmap/masks .02` at t64 345/350.** Full list in §3. |
| Trace axis | **0 moves**: 159 graphics tests (status and output) plus the 11-test no-graphics hit-test sweep. The `movieclip_hittest_shapeflag` diff is byte-identical before and after. All 6 `regression/` tests whose generated code changes pass in both modes. |
| Docs | Retired the `simple_shapes/masks` + `masks_equal_clipdepth` image-axis entry (ACCEPTED_DIFFS.md entry and both summary rows, playbook §3 row). Marked s18 §3-E "45° 1-sample ties" and the `blend_modes ×12` NO-GO as refuted in the playbook. Amended the `addCurvedEdge` "lroundf refuted" comment. |
| Canary | Added at EOF: `visual/simple_shapes/overlaps`, `visual/blend_modes/add`, `visual/filters/glow` (tier 2), **plus** `from_shumway/timeline/timeline_loop` (tier 1). That fourth one is my addition: it is the near-budget curve-fill tripwire this change exposed (§3). |
| Optional morph leg | **HOLD.** Measured: it emits sub-twip morph start/end positions, but both morph image rows that change code (`morph_test1`, `acid-morph`) render **byte-identical**, and the hit-test traces are unchanged. **Completion mechanism:** fund it only together with a morph row that it can move (`morph_test1`'s residual is the status-text overlay, s18). Delivered as a separate patch for the record. |

## 1. EXPECTED-FLIP LEDGER (for the coordinator's CI check)

All rows are graded with `verify_output.compare_images` on cloud lavapipe renders. **Fidelity:**
**82 of 82** *before* PNGs that have a CI actual on `origin/ruffle-image-results` are
byte-identical to it (RGBA), including every row below that has one. So the absolute verdicts are CI-grade.

### Pixel axis: fail → pass (+22)

| # | test / comparison | before (= CI) | after |
|---:|---|---:|---:|
| 1 | `visual/filters/blur_size_grows output` | 546/0 | **0/0** |
| 2 | `visual/filters/color_matrix output` | 6/0 | **0/0** |
| 3 | `visual/simple_shapes/masks output` ¹ | 181/0 | **0/0** |
| 4 | `visual/simple_shapes/masks_equal_clipdepth output` ¹ | 181/0 | **0/0** |
| 5 | `visual/simple_shapes/overlaps output` | 12/0 | **0/0** |
| 6 | `visual/simple_shapes/scroll_rect_mask output` | 20/0 | **0/0** |
| 7 | `visual/simple_shapes/heavy_tesselation output` | 2439/3 | **3/3** |
| 8 | `visual/simple_shapes/layers output` | 23/0 | **0/0** |
| 9 | `visual/avm2_button_scroll_rect output` | 6/0 | **0/0** |
| 10 | `visual/cache_as_bitmap/avm2_button output` | 6/0 | **0/0** |
| 11-22 | `visual/blend_modes/{multiply 16, add 5, hardlight 21, alpha_no_layer 18, darken 16, difference 7, erase_no_layer 18, invert 24, lighten 5, overlay 19, screen 5, subtract 7}` (before counts) | as listed | **0/0 (all 12)** |

¹ The image-axis disposition is retired in this patch, so these leave the board's hard-excluded set and
count as passes.

### Pixel axis: pass → fail (−1)

| test / comparison | before (= CI) | after | note |
|---|---|---|---|
| `from_shumway/acid/acid-small output.05` | PASS (t0 25959/30000, t20 19494/21000, **t80 2997/3000**) | **FAIL (t80 3027/3000)** | Predicted by w1 §3. The strokes are sub-device-pixel and we never clamp them to 1 device px. **Completion mechanism:** lead L1, device-scale minimum stroke width (`drawLines` vs Ruffle `tessellator.rs:178-189`), a later slot. |

**Net pixel: +21** (433 → 454 of 587 if nothing else moves on CI).

### Trace axis

**No flips expected.** 0 status or output changes across the 159 captured tests and the 11-test
no-graphics hit-test sweep. If CI shows a trace move on any test, it is not this patch's: the recompiler
diff only changes `draws.c` / `draws.h` triangle data and the vertex offset/count arguments in
`tagMain.c` (shape bounds arguments are unchanged, checked on glow, acid-small and masks).

### Band moves on rows that still fail (no flip; for the board)

| comparison | budget | before | after |
|---|---|---:|---:|
| `filters/glow`, `glow_without_composite_source`, `drop_shadow` | 2-3/0 | 2659, 2917, 3875 | **3, 3, 3** (one EditText label pixel) |
| `filters/bevel_inner` / `bevel_outer` / `bevel_full` / `glow_with_alpha_strength` | /18 | 1018 / 1450 / 1158 / 1123 | **42 each** (label pixels) |
| `filters/bevel` | /6 | 3091 | 750 |
| `filters/drop_shadow_angles` | /0 | 6934 | 549 |
| `filters/displacement_map` | /72 | 1436 | 408 |
| `from_shumway/doubleAndRegister` | /0 | 26 | 2 |
| `acid/acid-gradient-2` | /0 | 38 | 3 |
| `acid/acid-scale` | /0 | 106 | 8 |
| `acid/acid-small output.01` (t80) | /3000 | 3657 | 3624 |
| `simple_shapes/strokes/scale` (KF) | /0 | 72633 | 71397 |
| `morph_test1` frame2-6, `Video-EmbedSquareTest` | /0 | 15 | 12 |
| `acid-morph`, `acid-mask` ×3, `acid-color-0`, `acid-stroke-0`, `acid-text`, `acid-text-escape`, `layer_alpha`, `layer_erase`, `br_at_start` | | | −0.1 to −1 % (better) |
| `acid-clip` 397→409, `place_object_test` 41844→41874, `shape_test` 16068→16074, `BeginBitmapFill` 936→939, `morph_test1 frame1` 216→217, `away3d_advanced_shallow_water_demo` +1 | | | slightly worse, all far from budget |
| `3_joystick`, `acid-filter-2`, `style_changes_in_html` | | | pixels move, counts unchanged |

## 2. The patch (exact scope)

`SWFRecomp/include/swf.hpp`, `SWFRecomp/src/swf.cpp` only (the recompiler). This is w1's prototype ABC
(`w1-stroke-staircase-prototype.patch`) unchanged in behaviour, plus three things:
- `static_assert(sizeof(Vertex) == 16, …)` after `struct Vertex`. The message names the
  heavy_tesselation OOM.
- The `tessellateContours` `keep_float` comment fixed (it named a nonexistent `Vertex::fx/fy`).
- The `addCurvedEdge` "lroundf refuted" note amended (rounding is still quantization; the fix is keeping
  the remainder; this morph-only flattener stays integer).

The graded "after" binary is byte-identical to a fresh build of the final tree (`cmp`). The mechanism
(owner `file:line`, Ruffle side) is in `w1-stroke-staircase-report.md` §2-3 and is not repeated here:
- `Vertex` gains `s16 fx_frac, fy_frac` (1/16384 twip).
- A: `addCurvedEdgeLevien` + `drawLines` / `drawLineJoin` / `drawLineCap` in double, with
  `halfwidth = width/2.0`.
- B: `tessellateContours(…, keep_float=true)` for shape fills only.
- C: `strokeArcSegments` (lyon `num_arc_subdivisions`, tol 2 twips).
- Emission writes x + frac.

Self-localized to the regions SIBLING_FILE_MAP gives this slot. The `w2-default-fonts-draw` region
(`swf.cpp` ~2593-2648) is untouched.

Leg isolation, for the moved passing rows (`tools/leg_isolation_noB_noC.txt`, env-toggle builds, toggles
removed before delivery):
- `timeline_loop`, `acid-video`, `acid-clip-2` and `acid-blend-2` move **only with B** (fills).
- `cache_as_bitmap/masks` moves under both A and B.
- `acid-small .05` fails with each of A+B, A+C or A+B+C, so A alone is enough to cost it.

## 3. Broader sweep (every CI-passing image row, argued by construction)

The runtime is untouched, so a test's render can only move if its **generated code** moves.
`tools/recdiff.py` recompiles every `.swf` in the test dir with the master and patched recompilers
(same `ulimit -v`) and hashes `RecompiledTags/`. Over all **260 CI-passing image tests**
(`*/_results/image_results_graphics.json` of images run 36515003936):
- **42 CHANGED, 218 SAME.** 6 tests were not downloaded on the first pass (stage3d ×5 and
  `import_assets/avm1_imports_avm1`); I then downloaded them: stage3d is SAME, `avm1_imports_avm1` is
  CHANGED and was rendered.
- The 137 failing image tests: 72 CHANGED, 65 SAME.
- The 101 `regression/` tests: 6 CHANGED, 95 SAME.

Rendered = all 114 CHANGED image tests plus the full 60-member standing canary (159 tests,
255 comparisons). That is the complete set of rows that **can** move. **Every moved CI-passing row**,
all checks shown (multi-check comparisons are ALL-of):

| comparison | before | after | margin after |
|---|---|---|---:|
| **`acid/acid-small output.05`** | t80 2997/3000 | **t80 3027/3000 FAIL** | −27 |
| `cache_as_bitmap/masks .01` | t10 3103/3200, t64 298/350 | 3118, 312 | 38 |
| **`cache_as_bitmap/masks .02`** | t10 3014/3200, t64 319/350 | 3032, **345** | **5** |
| `cache_as_bitmap/masks .03` | 3010, 295 | 3034, 323 | 27 |
| `cache_as_bitmap/masks .04` | 3105, 286 | 3120, 318 | 32 |
| `cache_as_bitmap/masks .05` / `.06` / `.07` | 2985,292 / 2625,262 / 2520,246 | 2998,298 / 2632,276 / 2532,264 | ≥ 52 |
| **`timeline/timeline_loop .02 .07 .12`** | t32 57/70 | **65/70** | **5** |
| **`timeline/timeline_loop .06 .11 .15 .16`** | t32 77/90 | **84/90** | **6** |
| `acid/acid-video .01` | t5 16648/20000, t50 278/300 | 16153, 270 | 30 (better) |
| `acid/acid-video .10` | 15890, 254 | 15438, 254 | 46 |
| `acid/acid-video .20` | t5 14066/15000, t50 99/130 | 13389, 101 | 29 |
| `acid/acid-blend-2 .10/.15/.20/.26` | t20 4114/5000, 5926/6000, 5286/5500, 5618/6000 | 4129, **5929**, 5300, 5638 | ≥ 71 |
| `acid/acid-blend-2 .40` | t20 8506, t40 1467/1500 | 8477, 1460 | 40 (better) |
| `acid/acid-clip-2` | t0 2863/3000, t32 1011/1300, t64 210/300 | 2886, 1044, 219 | 81 |
| `acid/acid-color-2` | t52 70/100 | 64 | better |
| `acid/acid output.01-18` | t0 ~8.7k-12.4k/9.1k-13k, t128 198/360 | ±2-14 on t0, t128 unchanged | ≥ 400 |
| `acid/acid-blend` | t11 39/348 | 5 | better |
| `blend_modes/overlay_onto_stage` | t32 45/60 | 48 | 12 |
| `cache_as_bitmap/scroll_rect_scaled` | t64 800/900 | 799 | 101 |
| `import_assets/avm1_imports_avm1` | t100 459/500 | 458 | 42 |
| `regression/avm2_parent_child_render` | 96/400 | **0** | better |
| `regression/avm2_timeline_gradients`, `…_stroke_gradient`, `filters/blur_scales_with_screen`, `acid-blend-2` t1xx checks | 0/0 | 0/0 (pixels move) | 0 |

Correction to w1 §3: w1 said `cache_as_bitmap/masks` .01-.07 "stay at 0 outliers". That is true only of
their strict t128 check. Their t10/t64 checks lose 7-32 outliers of margin each, and `.02` now sits 5
under budget. Renders are byte-deterministic, so this is a pass, but it is the closest pass on the board
for this change class (with `timeline_loop` at 5-6). Hence `timeline_loop` was added to the canary.
`cache_as_bitmap/masks` is already a member.

## 4. Canary, regression suite, trace

- **Canary** (standing set, 60 tests): 49 members md5-identical. The 12 that move are exactly w1's list:
  `acid-blend-2`, `acid-small`, `doubleAndRegister`, `regression/avm2_timeline_gradients`,
  `regression/avm2_timeline_stroke_gradient`, `blend_modes/multiply`, `cache_as_bitmap/masks`,
  `blur_scales_with_screen`, `color_matrix`, `drop_shadow`, `simple_shapes/layers`,
  `simple_shapes/masks`. All of them are in the ledger or in §3. No canary image status changes except
  the ledger's (`multiply`, `masks`, `layers`, `color_matrix` fail→pass; `acid-small .05` pass→fail).
  (`tools/canary_compare_before_after.txt`)
- **Regression suite:** the 6 `regression/` tests whose generated code changes all PASS in
  `--mode=graphics` and in no-graphics with `--recompile`: `avm2_bitmapdata_draw_textfield`,
  `avm2_parent_child_render`, `avm2_timeline_gradients`, `avm2_timeline_solid`,
  `avm2_timeline_stroke_gradient`, `avm2_timeline_text`. The other 95 have identical generated code.
- **No-graphics hit-test sweep** (`--recompile`, before / after / morph): all PASS → PASS → PASS for
  `avm1/{hittest_morph, hittest_morph_input, hittest_winding_rule, movieclip_hittest, hitarea_sweep}` and
  `avm2/{displayobject_hittestpoint, displayobject_hittestpoint_boundary, hittest_morph, button_hittest,
  mouse_pick_avm1_root}`. `avm1/movieclip_hittest_shapeflag` is output_mismatch in all three legs with a
  **byte-identical** diff (ACCEPTED_DIFFS entry).
- **Graphics trace axis:** `render_canary compare` shows `trace_changes: []` over all 159 captured
  tests. This is the recompiler-sensitive trace sample: every test whose shape code changes.

## 5. Optional morph leg: HOLD (measured, delivered separately)

`w2-float-verts-2-morph.patch` (on top of the main patch) keeps the remainder on the morph path:
- `addCurvedEdge`, the end-shape curve loop, and the start/end straight-edge subdivisions record it
  (`pushStraightEdge` / `pushEndStraight`, morph-only since n > 1 needs a plan).
- earcut `fillShape` carries it through.
- Morph fill/stroke emission writes the exact start; the stroke end delta uses exact positions.
- `morph_end_shape_data` gets a `MorphEndCoord` literal: whole twips keep the historical `%.1f` form,
  so morphs with no computed vertices emit byte-identical code. Fractional values get 5 digits.

Measured with `recdiff.py` (main patch vs main+morph) over all 483 image + regression tests:
**only 2 change code** (`from_gnash/misc-ming.all/morph_test1`, `from_shumway/acid/acid-morph`). Both render
**byte-identical** PNGs (every frame). The generated positions do change, e.g. `0xC596A000` →
`0xC596A13B`, sub-twip, and 235 fractional end literals in `acid-morph`. `cache_as_bitmap/morph`'s code
does not change. The no-graphics hit-test sweep is unchanged and `morph_test1`'s trace still passes.

Verdict: zero yield, zero risk. It is correct in principle (it removes collinearity drift on subdivided
morph edges), but nothing in the corpus can see it. **Completion mechanism:** apply it only alongside a
morph slot that has a row it moves. The morph_test1 frames' residual is the "- xtrace enabled" status
text, not geometry (s18).

## 6. Refutations / corrections of record

- w1 §3 "`cache_as_bitmap/masks` .01-.07 … every one stays at 0 outliers": **corrected**. Only the
  t128 check stays at 0. t10/t64 lose margin, and `.02` ends at 345/350 (§3).
- w1 §1 claim that the s18 §3-E ties and the masks disposition are quantization: **re-confirmed** in
  production form. All 14 rows flip.
- The brief's ledger is correct as written: 22 flips, −1 `acid-small .05`.

## 7. New unclaimed leads

- **L1 device-scale minimum stroke width** (w1 §6, unchanged). It now carries the −1 (`acid-small .05`)
  plus `.01`, `acid-scale` (8/0) and `strokes/scale` (KF).
- **Text label residual:** 7 rows sit within a text-only fix: `glow`, `glow_wcs` and `drop_shadow` at
  3/0, one comma pixel; `bevel_*` ×3 and `glow_with_alpha_strength` at 42/18.
- **`timeline_loop` / `cache_as_bitmap/masks .02` margins (5-6):** these are high-quality (MSAA) rows
  where float fills move single AA samples. Any future geometry or MSAA change should A/B them; they
  are now both canary members.
- **`recdiff.py` as a standing tool:** for any recompiler-only change, "recompile both, hash
  `RecompiledTags/`" turns an argued sweep into an exhaustive one. It took 15 s for the 260 passing image
  tests and ~2 min for the failing ones. Worth promoting to `ruffle-tests/` (not done here: out of scope).

## LOCAL ORACLE REQUESTS

None.
