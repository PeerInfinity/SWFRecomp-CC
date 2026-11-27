# s29 w2b-lowq-stroke: the Flash LOW stroke raster, fitted on an FP32 probe and landed (LOW arm only)

Slot `w2b-lowq-stroke`, wave 2. Branch `fanout/w2b-lowq-stroke`; base `origin/master` `d4a37dda` (TSNAP `1fcf2b1c1` on it).
- Cloud box, Dawn on lavapipe.
- Corpus downloaded 2026-11-27 (`visual avm2 from_shumway avm1 from_gnash`, flash_fixes applied). `download_tests.sh`
  prints no upstream SHA.

## New files

- `ruffle-tests/tests/swfs/regression/lowq_stroke_probe/`: `create_test_swf.py`, `test.swf`, `cells.json` (181 cells +
  candidate-rule predictions), `test.toml`, `output.txt` (empty) and **`output.expected.png`**.
  - The golden is the FP32 LOW capture `w1-local-oracles/w2b-lowq-stroke/lowq_stroke_probe.lnx.png` (LNX == WIN ==
    `--screen`, 0 px).
  - Tolerance 0, `max_outliers = 5745` (measured).
- `SWFRecompDocs/plans/session29-fanout-reports/w2b-lowq-stroke-report.md` (this file).
- `SWFRecompDocs/plans/session29-fanout-reports/w2b-lowq-stroke.patch`. `git apply --check -R` was verified against
  the final tree.
- `SWFRecompDocs/plans/session29-fanout-reports/w2b-lowq-stroke-fixtures/ledger/`:
  - `moved_rows.txt`: every LOW row whose render moved, master → patch vs its golden;
  - `moved_rows_vs_fp32_low_captures.txt`: the same rows vs every FP32 LOW capture on master;
  - `all_low_tests_run.txt`: the 258 rows run;
  - `event_tests_patch_leg_only.txt`: the input-driven rows, graded separately (§4).

## Verdicts (lead)

1. **GO, all three leads landed, LOW-gated (`MSAA_SAMPLES == 1`).**
   - (a) band rule;
   - (b) thin regime;
   - (c) hairline under TSNAP;
   - plus a width quantisation the probe exposed.

   **Probe: 7920 → 1999 px ≠ FP32** (22 873 → 5 745 channels, fail → pass).
2. **The FP32 LOW stroke rule.** All of it comes from the probe; cell counts are in §2.
   - **Width.** W = round(w) on the quarter-px grid. w = 4 / 4.5 / 5 / 5.25 render byte-identically, and so do
     w = 5.5 / 5.75 / 6.
   - **Thin regime, W ≤ 5.** A pen of **n = min(W, 4)** px along the minor device axis, with butt ends. W = 5 draws as
     4, both as a 0° band and as a 45° run. **The threshold is between 5.25 and 5.5**, not between 5 and 6 (refines
     lead b).
   - **W ≥ 6: polygon** of width W, with round caps.
   - **Axis band.**
     - The band is [lo, lo + n), where lo = p − ⌊n/2⌋ and p = ceil(c − ½), i.e. c rounded half down.
     - **Only n = 3 depends on travel direction:** up / right gives lo = p − 1, down / left gives p − 2.
     - This is lead (a) generalised: 48 band cells (W = 1..6 × c + {0, .25, .5, .75} × cw / ccw) and 12 / 12
       drawing_order edges.
     - W = 1, 2, 4 and 6 are direction-free.
   - **n = 4 off 45°.** On an exact 45° diagonal, n = 4 is a 4-px run. At 26.6° / 30° / 60° it is a round-capped
     polygon about 4.5 px wide: the per-column extent fits a half-width of 2.55–2.6 px / cos.
   - **Hairlines thinner than 1 device px** (stage scale < 1) keep the HIGH placement. `gradientTransform` is the FP32
     evidence: its band stays at col 0 for c = 0.75.
   - **The Drawing API shares the rule** (probe row 2 cols 8–15: 26–96 → 4–6 px per cell).
   - **TSNAP ties are half-EVEN, confirmed:** row 6 (.5 on odd and even, flat and nested) is **0 px**.
3. **(c) A 1-px noScale hairline strokes at the unsnapped translation.**
   - acid-stroke-0 depths 49 / 59 go to 0 px.
   - Its remaining error is the 1-px diagonal raster, not placement. Flash agrees with the unsnapped position for some
     fractions and the snapped one for others, and para41 and para51 disagree at the same fraction (§2.4).
4. **114-row Flash-golden LOW gate: 0 status losses** (no pass→fail, no fail→pass).
   - Movers toward the golden: acid-stroke-0 7426 → 3413, reflect / repeat 5628 → 2382, acid-shapes-testing,
     opaque_background and cab/drawing_api.
   - Priced losses vs the golden: `simple_shapes/layers` +27 (scattered corner px), `graphics_gradients` +3 and
     `graphics_simple_shapes` +2. All three stay fail.
5. **All 258 LOW rows: 2 status flips, both new passes on regression rows:**
   - `regression/lowq_tsnap_tie_probe` **fail → pass** (3164 → 1250). Master is already 12 over its 3152 budget on
     this box.
   - `regression/lowq_stroke_probe` (new) **fail → pass**.
6. **Several non-Flash goldens move away while moving TOWARD FP32 LOW captures** (flash_fixes candidates, §5):
   - `drawing_order`: golden 3683 → 8839, but **FP32 LOW capture 12 784 → 3 016**;
   - `cursor`: golden 400 → 798, but **FP32 capture 400 → 2**;
   - `blur_size_grows`: golden 2988 → 35 098, but FP32 LOW 133 827 → 130 473;
   - `acid-scale`: golden 9466 → 10 738, but FP32 capture 2742 → 1690.
7. **HIGH is identical by construction (proof in §3).**

## 1. Patch scope (functions touched)

### `SWFModernRuntime/src/rendering/render_webgpu.c`

Everything new is under `#if MSAA_SAMPLES == 1`.
- **New statics and switches:**
  - `lowq_hair_unsnap` (`SWF_LOWQ_HAIR_UNSNAP=0`);
  - `lowq_stroke_rule` (`SWF_LOWQ_STROKE=0`);
  - `lowq_n4_poly` (`SWF_LOWQ_N4=<w>`, A/B only, default 4.5);
  - `lowq_subpx_hair`;
  - scratch: `lowq_dir_tab`, `lowq_vdir`.
- **New functions:** `lowq_stroke_width`, `lowq_band_centre`, `lowq_dir_find`, `lowq_cen_get`, `lowq_run_dirs` and
  `lowq_stroke_place`, plus a forward declaration of `stroke_snap_centre`.
- **Touched:**
  - `hairline_init`: reads the env switches.
  - `hairline_restage`:
    - the TSNAP device shift is read from the slot's z-column;
    - per run, the LOW width / direction pass;
    - per vertex, `lowq_stroke_place` replaces `stroke_snap_place` under LOW;
    - the (c) unsnap applies to `no_scale && W == 1 && axis == 0` runs.
  - `render_webgpu_stroke_snap`: the same LOW width and placement for Drawing-API soups.
- **Travel direction comes from triangle layout.** Recompiler `drawLines` quads are (A+n, A−n, B+n), (B−n, A−n, B+n);
  vertices 1 and 2 are start and end. The Drawing-API builders emit (A+n, A−n, B+n), (A−n, B−n, B+n); there, vertices
  0 and 1 are start and end when 1 and 2 coincide. No recompiler change is needed.

### `SWFModernRuntime/src/libswf/tag.c` (AVM1)

- **New:** `lowq_tsnap_slot_xform` and the macro `LOWQ_TSNAP_SLOT` (a no-op `(c)` at HIGH), inside TSNAP's
  `MSAA_SAMPLES == 1` block.
- **Touched:** `compose_children` slot write. A shape or morph entry's slot copy carries `g_tsnap_acc` in m[8] / m[9].
  `composed` itself is unchanged.

### `SWFModernRuntime/src/avm2/avm2_display.c` (AVM2)

- **New:** `avm2_lowq_tsnap_slot` and `AVM2_LOWQ_TSNAP_SLOT`, plus tentative forward definitions of
  `g_avm2_tsnap_off`, `g_avm2_tsnap_acc` and `g_avm2_filter_active`.
- **Touched:** `avm2_render_shape` slot write. acid-stroke-0 is AVM2, so this is the path that matters for it.

### Fixtures and scope limits

- **`ruffle-tests/render_canary_tests.txt`:** EOF member `regression/lowq_stroke_probe` (tier 1).
- **Not touched:** `SWFRecomp/`, `verify_output.py`, `swf_core.c`, `tag_stubs.c` and `NO_GRAPHICS` arms. No new TU.
- **Kill switches:**
  - With `SWF_LOWQ_STROKE=0 SWF_LOWQ_HAIR_UNSNAP=0`, the probe render is md5-identical to the pristine-master render.
  - acid-stroke-0 and drawing_order reproduce master's 7426 and 3683.
  - The four event-driven failing rows reproduce master exactly (§4).

## 2. Probe fit (FP32 golden, same box, px ≠ Flash per row, master → patch)

| probe row | content | master | patch |
|---|---|---:|---:|
| 0 | 45° lines w 3–6, both directions | 896 | 78 |
| 1 | 30° / 60° lines w 3–6 | 476 | 216 |
| 2 | angle sweep + Drawing-API lines | 614 | 105 |
| 3 | rect bands W = 1, 2 (4 fracs × cw / ccw) | 760 | 16 |
| 4 | rect bands W = 3, 4 | 794 | 64 |
| 5 | rect bands W = 5, 6 | 968 | 72 |
| 6 | TSNAP .5 ties, flat and nested | 0 | 0 |
| 7 / 8 | 1-px noScale squares under para41 / para51, sprite + direct | 946 + 784 | 402 + 446 |
| 9 | sheared fills in sprite | 0 | 0 |
| 10 | 30° rotated fill + fill-and-hairline | 528 | 250 |
| 11 | acid-size shape 9 | 1154 | 350 |
| **total** | | **7920** | **1999** |

### Residual, and what each part is

- **Rows 7–11, the 1-px diagonal hairline raster.**
  - At integer placement we sit at 24 / 27 px per cell.
  - At fractional placements Flash follows the unsnapped position for some cells and the snapped one for others.
  - That points to the diagonal 1-px raster rule, not to the translation.
- **Row 1 cols 5–7 / 13–15, 30° / 60° polygons (W ≥ 6).** 28 / 34 px, cap shape; unchanged from master.
- **Rect corners.** 2–8 px per cell; Flash chamfers the seam corner by 1 px.
- **Row 10 cols 0–7, rotated fill.** 5 px each, a fill-raster detail; unchanged.

### Other notes

- **Lead (b)'s "w = 5 clamp" is exact.** It belongs to the width quantisation (round(w) = 5 → n = 4), not to a
  per-angle rule.
- **The tie choice at exact 45°.** The x pen avoids sub-pixel dropouts, because the LOW vertex snap moves y only.

## 3. HIGH identity proof

`gcc -E` of the three TUs with the CI graphics flags and no `MSAA_SAMPLES` (= HIGH), master vs patch, with assert
file / line strings normalised:
- **`render_webgpu.c`: 0 lines differ.**
- **`tag.c`: 7 lines differ.**
  - `float tsnap_slot_buf[16]; const float* slot_xform = (composed); (void) tsnap_slot_buf;`
  - The two `render_webgpu_write_transform(…, slot_xform)` calls, where `slot_xform` aliases `composed`: the same
    value.
- **`avm2_display.c`: 1 line differs** (`((void) 0);`).

No HIGH pipeline or render path changed.
- **Empirical check:** the HIGH stroke regression rows `avm1_drawapi_stroke_snap` (2436), `avm1_stroke_seam_caps`
  (1824, n-seam-caps' value) and `avm1_stroke_hinting_caps` (7056) all PASS at their recorded counts.
- **The 340-test HIGH canary capture was not run.** It cannot move, by the proof above. The canary's 83 LOW members
  are all inside the 258-row LOW run.

## 4. Gate method, and results

### Method

- **258 LOW rows**, run in two lanes: the 114-row gate, the canary's LOW members, the rest of `all_low_tests` and the
  two probes.
- **Patch leg** via `verify_output.py --mode=graphics`, keeping each build dir.
- **Master leg:** the same binary re-executed with both kill switches. Re-executing without them reproduces the patch
  PNG byte-for-byte, so the harness is faithful.
- **Graded** with verify's unit (channels > tolerance); this reproduces its reported counts exactly.
- **Event-driven rows** (23, input.json) cannot be re-executed. Their patch leg is graded by verify:
  - every focusrect / focus_highlight / button row PASSes;
  - the four failing ones were re-run through verify with the kill switches and are identical:
    `stage3d_texture` 4042, `mouse_events_visible_enabled` 3610, `edittext_scroll` 287 / 289, `away3d` 1 327 065.

### Results

All moved rows are listed in `ledger/moved_rows.txt`. Headline:

| test | golden prov. | vs golden, master → patch | vs FP32 LOW capture, master → patch |
|---|---|---:|---:|
| `regression/lowq_stroke_probe` (NEW) | FP32 LOW | 22 873 → **5 745** (fail → **pass**) | = golden |
| `regression/lowq_tsnap_tie_probe` | FP32 LOW | 3 164 → **1 250** (fail → **pass**) | = golden |
| `regression/lowq_sample_point_probe` | FP32 | 1 540 → 1 225 (pass → pass) | |
| `from_shumway/acid/acid-stroke-0` | Flash (gate) | 7 426 → **3 413** | |
| `from_shumway/acid/acid-shapes-testing` | gate | 10 317 → 9 219 | |
| `visual/simple_shapes/gradients/reflect`, `repeat` | gate | 5 628 → 2 382 each | 9 186 → 5 946 / 8 004 → 4 758 |
| `visual/simple_shapes/gradients/radial` | | 64 542 → 66 597 | 8 223 → **6 186** |
| `visual/drawing_api/drawing_order` | not Flash | 3 683 → 8 839 | **12 784 → 3 016** |
| `visual/drawing_api/cursor` | not Flash | 400 → 798 | s27 capture **400 → 2** |
| `visual/drawing_api/fills_and_lines` | | 38 424 → 41 236 | 77 695 → 76 418 |
| `visual/filters/blur_size_grows` | | 2 988 → 35 098 | 133 827 → 130 473 |
| `visual/filters/*` (bevel, glow, drop_shadow, …) | | mixed, ±2 k | 9 of 11 toward FP32 LOW; `bevel_inner` +262 |
| `from_shumway/acid/acid-scale` | | 9 466 → 10 738 | s27 / snap-audit capture 2 742 → 1 690 |
| `from_shumway/acid/acid-text` | | 2 868 → 309 | s27 draw capture 16 053 → 18 534 (away; pre-LOW-stub capture) |
| `from_shumway/doubleAndRegister` | | 166 → 200 | capture 630 → 616 |
| `visual/simple_shapes/layers` | Flash, flash_fixes FP32 (gate) | 1 727 → **1 754** | **AWAY +27** (17 scattered px) |
| `avm2/graphics_gradients` / `graphics_simple_shapes` | Flash (gate) | 293 → 296 / 114 → 116 | **AWAY +3 / +2** |
| `visual/simple_shapes/masks`, `masks_equal_clipdepth` | s28 LOW | 3 128 → 3 152 | 3 248 → 3 251 (+3) |
| `from_shumway/gradientTransform` | Flash (gate) | 3 → 3 | unchanged |
| `visual/opaque_background`, `cache_as_bitmap/drawing_api` | gate | −8 / −6 | toward |

`gradientTransform` regressed in the first gate pass (3 → 1081): sub-pixel hairlines took the new W=1 placement. The
`lowq_subpx_hair` guard fixed it and is FP32-backed.

**Regression suite:**
- all LOW `regression/` rows are in the run; the movers are the two probes (to pass) and `lowq_sample_point_probe`
  (toward);
- `lowq_fill_edges`, `lowq_gradient_orient_probe` and the `layer_group*` rows are unchanged (md5);
- the HIGH stroke rows are listed in §3.

## 5. EXPECTED-FLIP LEDGER (graphics CI; check by name)

**Trace axis: no moves.** The change is render-only, LOW-only. No LOW row's trace status changed in the patch leg.

**Pixel axis, status moves:**
- **new pass:** `regression/lowq_stroke_probe` [output] (5745 / 5745);
- **fail → pass:** `regression/lowq_tsnap_tie_probe` [output] (1250 ≤ 3152). If CI had it passing, it stays pass;
- **no pass → fail anywhere.**

**Pixel axis, outlier moves (fail → fail),** local values; CI should match to the outlier:
- `acid-stroke-0` 3413; `acid-shapes-testing` 9219; `acid-scale` 10738; `acid-text` 309; `doubleAndRegister` 200;
- `graphics_gradients` 296; `graphics_simple_shapes` 116;
- `drawing_api/drawing_order` 8839; `drawing_api/cursor` 798; `drawing_api/fills_and_lines` 41236;
  `cache_as_bitmap/drawing_api` 597; `opaque_background` 1948;
- `simple_shapes/gradients/{reflect,repeat}` 2382; `gradients/radial` 66597; `simple_shapes/layers` 1754;
  `masks`, `masks_equal_clipdepth` 3152;
- `from_gnash/misc-ming.all/shape_test` 9709;
- `filters/`: `bevel` 56326, `bevel_full` 24871, `bevel_inner` 14874, `bevel_outer` 30039,
  `blur_scales_with_screen` 73176, `blur_size_grows` 35098, `displacement_map` 91822, `drop_shadow` 38135,
  `drop_shadow_angles` 39929, `glow` 16869, `glow_with_alpha_strength` 16949, `glow_without_composite_source` 17358;
- `regression/lowq_sample_point_probe` 1225 (pass).

The filter rows' values are from the first gate pass. The sub-pixel guard can only revert w < 1 bands to master's
placement, so they were not re-run.

Anything else moving on either axis is NOT this patch.

## 6. flash_fixes candidates and dispositions (coordinator adds entries; no `fixes.json` edits here)

**Golden swaps.** Ours moved strongly toward an FP32 capture while away from the corpus golden:
- `visual/drawing_api/drawing_order`, with s28 `lowq-recapture/png/…drawing_order__output.low.png`: ours 3016 ch.
- `visual/drawing_api/cursor`, with s27 `golden-provenance/visual__drawing_api__cursor__output.png`: ours **2 ch**.
  Confirm it with a LOW recapture first: the s27 captures predate the LOW stub fix.

**Priced losses to disposition:**
- `simple_shapes/layers` +27 and `graphics_gradients` / `graphics_simple_shapes` +3 / +2: stroke corner pixels. These
  are three gate rows that stay fail.
- `acid-text` vs its s27 draw capture: that capture is probably HIGH. See REQUEST 2.

No RvF entries: no new Ruffle≠Flash difference was confirmed.

## 7. Refutations / premise attacks

- **Lead (b) "w ≤ 5 minor-axis pen, polygon at w ≥ 6".** Refined: the switch sits between 5.25 and 5.5 (width is
  rounded first). n = 4 is a pen only on exact 45°; elsewhere it is a ~4.5-px round-capped polygon.
- **Lead (a) "right-of-travel pen" generalises only to n = 3.** W = 1, 2, 4 and 6 are direction-free bands at
  p = ceil(c − ½).
- **Lead (c) "unsnapped translation".** It holds for the acid placements (depths 49 / 59 → 0 px) and is kept. The
  probe shows the remaining hairline error is the diagonal 1-px raster, not the translation.
- **TSNAP half-even is confirmed** by 16 dedicated tie cells (row 6, 0 px).

## 8. Not finished / HOLD (each with its completion mechanism)

- **1-px diagonal hairline raster** (probe rows 7–11: about 1.4 k px; acid-stroke-0's remaining 3.4 k).
  - Needs a model of Flash's 1-px diagonal LOW raster.
  - The probe has the evidence. Next step: a per-row offline fit like §2's band fit, comparing Bresenham variants
    against rows 7–8 cols 0–15.
- **Rect corner / seam chamfer at LOW** (2–8 px per probe cell; `layers` +27). Fit from probe rows 3–5 corners.
- **30° / 60° polygon caps at W ≥ 6** (28–34 px per cell): unchanged from master.

## New unclaimed leads

- The `regression/lowq_tsnap_tie_probe` budget is already exceeded on master on this box (3164 > 3152). CI should be
  checked: if master fails it there, this patch is the fix.
- Translucent-stroke union (`StrokeSnapSrc.post`) at LOW was not probed.
- pixelHinting at LOW is unprobed. This patch applies the LOW width quantisation to hinted strokes too; no LOW gate row
  moved because of it.

## LOCAL ORACLE REQUESTS

1. **FLASH, LOW recapture (image, direct pinned) of `visual/drawing_api/cursor`.** It confirms the §6 swap (ours 2 ch
   vs the s27 capture).
2. **FLASH, LOW recapture of `from_shumway/acid/acid-text`.** Its only capture (s27 draw) predates the LOW stub;
   golden 2868 → 309 but s27 capture 16 053 → 18 534.
