# w1-aa-sizing report (s29 wave 1, cloud): Flash HIGH AA vs our MSAA-4, measured

**New files:**
- `w1-aa-sizing-report.md` (this file)
- `w1-aa-sizing-prototype.patch`: debug-only `-DSSAA_PROBE` in `render_webgpu.c`. With no define it is a no-op (md5-verified).
- `w1-aa-sizing/`: drivers (`ssaa_run.py`, `scan_run.py`, `ab.sh`), graders (`ledger.py`, `checks.py`, `metric.py`,
  `compose.py`, `summ.py`), per-leg ledgers `ledger_<leg>.tsv`, the baseline row table `baseline_rows_014124ed5.tsv`,
  and the cap/corner probe result `jc_cmp_before_grid_scanline.txt`.

Box: cloud, lavapipe (llvmpipe LLVM 20.1.2), `SETUP_STATUS` all OK. Before leg = `origin/master` `aa36d43a` (code = s29
baseline `bfa47037b`). Tests were downloaded 2026-11-26 ~22:45Z; the script printed no SHA, and upstream master at
report time is `952362ecf`. **Fidelity: all 10 failing HIGH comparisons rendered md5-identical to CI's actual PNGs**
(`origin/ruffle-image-results` `6bfbec44`), and all 10 graded identically to the baseline. So local grading here is
CI-grade.

## Verdicts (lead)

| # | Verdict | Priced |
|---|---|---|
| 1 | **NO-GO: Flash-exact HIGH AA flips 0 of the 10 failing HIGH comparisons.** It costs **7 Flash-golden passes** (5 tests) and **4 Ruffle-golden passes** (all `regression/`, Ruffle-exporter goldens). | Net −11 rows. 0 flips. |
| 2 | **Premise refuted: the failing HIGH set is 10 rows, not "the board".** 130 of the 140 failing pixel rows are `quality = "low"` (MSAA_SAMPLES = 1). HIGH AA cannot reach them. | — |
| 3 | **Premise refuted: "Flash HIGH = 4×4 SSAA (box)" is not Flash's rule.** Confirmed on shapes: the sibling w1-text-pixels rule (4 sub-scanlines at y + j/4, exact x-coverage, n = floor(16·cov), vertices rounded to ¼ device px) fits Flash goldens far better than any 4×4 grid. `graphics_draw_triangles`: 4×4 box at (i+½)/4 → 680 outliers; s28's 4×4 fit (x (i+½)/4, y j/4, floor) → 184; **scanline rule → 14 channels (L1 38693 → 138).** | — |
| 4 | **Cheap sub-routes are also NO-GO:** a ⅛-px shift on MSAA-4 (draw_triangles 996 → 974), or ¼-px vertex rounding on MSAA-4 alone (0 flips, 2 Flash-golden losses). | 0 flips |
| 5 | **n-join-disc §5 item 3 partly refuted.** On its own Flash captures, W ≥ 2 **cap** residue is mostly AA (W = 2 cap error 416 → 32), but W = 3 **joins** get worse under exact AA (658 → 696). The join residue is geometry, not AA. | — |
| 6 | **s28 "it would move nearly every Ruffle-golden row" refuted.** 168 non-Flash, untestable or unprovenanced HIGH passes were swept and the only losses are 4 `regression/` rows. Upstream tolerances absorb the AA change. | — |

**Completion mechanism (reopen criterion) for NO-GO #1.** Reopen when the structural residues on
`acid-shapes` / `acid-mask` / `strokes/scale` / `graphics_draw_triangles` are fixed by their own owners. At that point
AA becomes the binding residual. The first candidate is `acid-shapes`: under the full rule it is 210/180 at t128, with
every other check passing. A second criterion: a Flash-capture set whose tolerance-0/1 rows fail only on edge pixels.
The faithful implementation route is in §4.

## 1. Ledger: failing HIGH comparisons (all 10; quality from `test.toml`)

Outliers on the binding check (budget in brackets). Legs:
- **before** = stock MSAA-4.
- **grid** = 4×4 box SSAA with the s28 phase (x (i+½)/4, y j/4) and floor alpha.
- **rule** = full Flash rule: 4 sub-rows × 16 x-samples, n = floor(16·cov), ¼-px vertex rounding.

L1 is the total |Δ| over all channels against the golden.

| Row | Golden | before | grid | rule | L1 before → rule |
|---|---|---:|---:|---:|---|
| `avm2/graphics_draw_triangles` | Flash | 996 [0] t1 | 184 | **14** | 38693 → 138 (−99.6%) |
| `from_shumway/acid/acid-shapes` | Flash | 25843 [25600] t32 (5 checks fail) | 180 [180] t128 (pass\*) | 210 [180] t128 (1 check fails) | 2826463 → 1833162 (−35%) |
| `from_shumway/acid/acid-mask` .01 | Flash | 12018 [20] | 12665† | 11265 | 351909 → 280894 (−20%) |
| `acid-mask` .05 | Flash | 10915 [20] | 11102† | 10299 | 330244 → 274616 (−17%) |
| `acid-mask` .10 | Flash | 9447 [20] | 9448† | 8515 | 290440 → 222337 (−23%) |
| `visual/simple_shapes/strokes/scale` | FP32 flash_fix | 12576 [0] t5 | 13029† | 10812 | 1368630 → 1219251 (−11%) |
| `from_shumway/bitmapbuttons` | Flash | 39 [0] | 114† | 39 | 23430 → 23384 |
| `visual/cache_as_bitmap/avm1_color` | Flash | 1200 [0] | 1200 | 1200 | unchanged (not AA) |
| `avm2/bitmapdata_draw` | not Flash | 753 [600] t128 | — | 750 | 285545 → 275573 |
| `from_gnash/misc-ming.all/Video-EmbedSquareTest` | untestable | 1818 [0] | — | 1875 | ≈ unchanged (video) |

\* Under the grid leg, `acid-shapes` passes at exactly 180/180. With grid phase k/4 on both axes it passes at 90/180
(this phase never fits `graphics_draw_triangles`). That is tolerance luck from a NON-Flash rule, and it is not a
lead: the faithful rule puts the row 30 over. † = number of channels over tolerance (>8) under the grid leg, from
`metric.py`; the binding check on these rows is t4/t5.

Residues that are not AA:
- `graphics_draw_triangles`: 10 px, max 9. These are pixels where 3 or more fills meet. Flash quantises each fill's
  coverage separately; the emulator only averages such pixels. The residue is unchanged at NX = 32, so it is not
  x-resolution.
- `acid-shapes`: max 213 at t128, a geometry/colour residue.
- `acid-mask`: masks.
- `strokes/scale`: stroke width model, 3663 channels > 128 before, still > 3000 after.
- `avm1_color`: colour transform.

## 2. Ledger: passing HIGH comparisons (301 non-low passing comparisons swept, 225 tests incl. the 10 failing)

| Golden class | Swept (pass) | Lost under the rule | Rows lost |
|---|---:|---:|---|
| Flash (golden-provenance) + flash_fix | 133 | **7** | see below |
| not Flash | 28 | 0 | — |
| untestable | 55 | 0 | — |
| no provenance row (incl. `regression/`) | 85 | **4** | all `regression/` (Ruffle-exporter goldens) |

Flash-golden losses under the rule. "rule" is the outliers / budget at the check that fails. `L1` shows the change:
most of these rows get closer to Flash overall and fail on a single cap check.

| Row | Binding check before → rule | L1 before → rule |
|---|---|---|
| `avm2/displayobject_getbounds_shape` | t0 3714/3800 → 3932/3800 | 490724 → 506125. The 1534 large-diff px (>64) are structural and unchanged; edge diffs use up the budget. |
| `from_shumway/acid/acid-blend-2` .10 | t130 0/0 → 3/0 | 347681 → 362262 |
| `acid-blend-2` .15 | t20 5922/6000 → 6202/6000 | 548924 → 558163 |
| `acid-blend-2` .20 | t130 0/0 → 3/0 | 520629 → 516843 |
| `from_shumway/acid/acid-color-2` | t80 0/0 → 1/0 | 112199 → 99349 (−11%) |
| `from_shumway/flash_text_TextField2` | t128 250/250 → 297/250 | 147901 → 150131 |
| `visual/cache_as_bitmap/edittext_selection` .02 | t0 0/8 → 18/8 (max diff 1) | 0 → 18 (rounding of the blend formula) |

Ruffle-golden losses (exporter = wgpu MSAA-4, the same raster as ours, so any AA change moves them):
- `regression/avm1_po3_cm_alpha_bias_edge`: 0 → 196 [0]
- `regression/avm1_po3_color_matrix_live` / `_nested`: 0 → 392 [0]
- `regression/avm2_parent_child_render`: 0 → 1412 [400]

They would need Flash re-captures (they are hand fixtures). Under a Flash-correct change they are an RvF/disposition
cost, not a blocker.

**Glyph note (the 16-level glyph AA NO-GO, L).** The full rule makes `avm1/define_font_glyph_table_order` and
`_overlap` **pixel-exact to Flash** (max diff 0; the baseline was max 1). Without the ¼-px vertex rounding, the
scanline rule FAILS both (180 and 30 outliers [4]): our glyph vertices are not on the ¼-px lattice, and the 4×4 grid
and MSAA-4 hid that. On MSAA-4 alone the rounding changes nothing for them. So glyph ¼-px snap and 16-level AA only
pay off together.

## 3. Mechanism, probe and evidence

- **Owner:** `render_webgpu.c` sample count (`MSAA_SAMPLES` → all `sampleCount` / `multisample.count`) and the main
  vertex shader `vs_main` (`LOWQ_VS_POSITION` non-LOW arm). No other file is touched.
- **Probe (prototype patch):** `-DSSAA_PROBE` does three things:
  - Swaps `sampleCount` / `multisample.count` and the 5 resolve-attachment guards to `HW_SAMPLES = 1`.
    `-DSSAA_HW4` keeps 4.
  - Shifts every vector vertex by an env `SSAA_OFS` device-px offset. The offset and the target size ride in the stage
    matrix's free z column (`ssaa_put`, called from `lowq_upload_stage` and the padded-filter upload in
    `render_webgpu_open_offscreen_pass`). The CPU copy in `hairline_stage` is untouched.
  - Moves the paint position back by J⁻¹·d, so gradients and bitmaps stay sampled at the pixel centre (coverage-only
    jitter, as in Flash).

  `-DSSAA_VSNAP` adds the ¼-device-px vertex rounding. The quality-model `#if MSAA_SAMPLES == 1` arms in tag.c,
  avm2_display.c and render_webgpu.c stay on HIGH, because MSAA_SAMPLES stays 4.
- **Drivers:** `ssaa_run.py` (N×N grid, any phase, round/floor) and `scan_run.py` (4 sub-rows × NX x-samples). Both
  monkey-patch `verify_output.run_binary` to run the binary once per jitter offset and composite the captures, so the
  harness's own `compare_images` grades the result. `scan_run.py` re-quantises two-colour pixels to
  floor((c0(256−16n) + c1·16n)/256) with n = floor(16·cov), and averages pixels with 3 or more colours.
- **Sanity:**
  - `-DSSAA_PROBE -DSSAA_HW4` at offset 0 is md5-identical to stock on 6 comparisons.
  - The live 16-run k/4 leg equals the offline 8×8-frame composite exactly (L1 3547 both).
  - Coverage-level signature (mean distance of edge-pixel coverage to the k/4 lattice; 0.25 = uniform):
    - Flash goldens: 0.43 (`draw_triangles`), 0.315 (`acid-shapes`). Their edge pixels sit on the k/16 lattice
      (distance 0.05–0.11), not on k/4.
    - Ours stock: 0.008 / 0.038, i.e. 4 levels.
    - Probe: 0.39 / 0.317.
- **Rule discrimination on the pure-AA row `graphics_draw_triangles` (tol 1):**

  | Variant | Outliers |
  |---|---:|
  | MSAA-4 | 996 |
  | MSAA-4 + ⅛ px shift | 974 |
  | 4×4 at (i+½)/4 both axes | 680 |
  | 4×4 at k/4 both axes | 201 |
  | 4×4 at x (i+½)/4, y k/4, round | 184 |
  | same, floor | 184 |
  | same, inverse-tie ε | 182 |
  | **scanline rule (floor)** | **14** |
  | scanline rule (round) | 19 |

  Per-axis phase preferences CONFLICT between rows under any 4×4 grid (`acid-mask` prefers x k/4 + y (j+½)/4). That
  conflict means a 4×4 grid is the wrong model.
- **Cap/corner probe** (`n-join-disc-captures/jc`, rebuilt with `probe2.py`, layout identical to the captured one;
  Flash HIGH golden `jc/flash_high.png`; `cmp.py` error in 1/16 levels):

  | lw (twips) | cap: before / grid / rule | join: before / grid / rule |
  |---|---|---|
  | 10, 20 | 2 / 0 / 0 | 168 / 130 / 126 |
  | 40 | 416 / 159 / **32** | 392 / 296 / 353 |
  | 60 | 583 / 200 / 145 | 658 / 620 / **696** |
  | 80 | 787 / 446 / 325 | 792 / 263 / 324 |
  | **Total** | | **3968 / 2245 / 2128 (−46%)** |

- **Hardware:** lavapipe `framebufferColorSampleCounts` has 2 entries (1, 4), and there are no programmable sample
  locations. WebGPU core allows `sampleCount` ∈ {1, 4}. A 16× MSAA route does not exist, and a rotated 16× pattern
  would not be Flash coverage anyway.

## 4. Cost and the cheapest faithful route (if ever reopened)

| Route | Fidelity (measured) | Fill / memory | Complexity |
|---|---|---|---|
| 4W×4H single-sample target + 4×4 box downsample | the "grid" leg: wrong rule; `acid-mask` / `scale` get WORSE than MSAA-4 | 16× fragments, 16× colour + stencil memory. A 1920×1080 canvas needs 7680×4320 (at the 8192 limit), and 4K breaks. | L: filters, cacheAsBitmap, BitmapData.draw and scrollRect would all need 4× targets plus downsampling before kernels. |
| MSAA-4 at 2×2 scale | not measured. It gives 8 distinct x/y positions (rotated pattern tiled), neither 4×4 nor scanline | 4× pixels × 4 samples | L (same plumbing as above) |
| Multi-pass jitter (this probe) | the rule, minus per-fill quantisation | 64 full scene passes | test-only; never shippable |
| **Analytic per-fill coverage (the only faithful route)** | the rule, including per-fill quantisation (fixes the ≥3-colour residue) | ~1× fill area + a resolve pass per fill batch | **XL** |

How the analytic route works:
- Conservatively expanded triangles write exact horizontal coverage on 4 sub-rows into an R16F target, with additive
  blending. Tessellated fills don't overlap, so sums are exact.
- A resolve pass quantises n = floor(16c) and composites with α = 16n/256.
- Vertices are rounded to ¼ device px.

What it costs: it breaks the current batching (a coverage clear and resolve per fill), and it has to be re-plumbed
through stencil masks, blend layers, filters, bitmaps and hairlines. N-scale scenes (825 tiles) would roughly double
their passes. Glyphs and strokes come for free once geometry goes through it. The ¼-px rounding must come with it,
never alone (§2 glyph note, and verdict #4).

## 5. Refutations (summary)

1. "Failing HIGH comparisons" are 10 of 140. The pixel board is a LOW board.
2. "Flash HIGH = 4×4 SSAA, box filter" is wrong for shapes too, not only text (sibling w1-text-pixels). The 4×4 grid
   fits only axis-aligned ¼-snapped geometry.
3. "W ≥ 2 cap/corner residue = AA granularity": true for caps, false for W = 3 joins.
4. "Would move nearly every Ruffle-golden row": 4 of 168 non-Flash passes move, all hand-made `regression/`
   fixtures.
5. Pricing attack: the large L1 gains (−11% to −99.6%) are not flips. Every failing row is bound by a non-AA residue
   that the AA change does not touch.

## New unclaimed leads

- **`acid-shapes` geometry residue (max 213 at t128):** under the faithful AA rule this is the only check left, 30 px
  over. Whoever owns acid-shapes geometry should grade against the rule leg (`scan_run.py` + `-DSSAA_VSNAP`) to see
  whether a geometry fix completes it.
- **Glyph vertices are not on the ¼-px lattice** (proved by the exact-x-coverage leg). It is invisible today. It
  matters to the text slots only once coverage becomes exact (w1-text-pixels).
- **W = 3 join geometry** (`jc` lw 60 joins got worse under exact AA: 658 → 696): a real join-shape residue for the N
  ladder / stroke builders. The probe tooling is here.
- **Tooling:** `scan_run.py` with `-DSSAA_PROBE -DSSAA_VSNAP` is a CI-grade "what would Flash-exact AA give" oracle
  for any HIGH row, at about 1 min per test.

## LOCAL ORACLE REQUESTS

None needed for the verdict. Every graded golden used here is already a Flash golden (golden-provenance /
flash_fixes) or the n-join-disc FP32 capture.

Optional, for the reopen criterion: **FLASH: `from_shumway/acid/acid-shapes`, image, last frame, direct.** Archive
the Flash PNG so the 213-max geometry residue can be split from AA without relying on the corpus golden.
