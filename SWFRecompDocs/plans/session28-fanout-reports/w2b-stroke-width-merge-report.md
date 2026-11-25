# w2b-stroke-width-merge: session 28 wave 2 (cloud). The w2-flash-stroke-width timeline model, rebased onto n-stroke-snap

**New files** (all under `SWFRecompDocs/plans/session28-fanout-reports/`):
- `w2b-stroke-width-merge-report.md` (this file).
- `w2b-stroke-width-merge.patch`: THE deliverable, `git diff origin/master -- SWFRecomp SWFModernRuntime
  ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`. It touches only
  `SWFModernRuntime/src/rendering/render_webgpu.c` and `ruffle-tests/render_canary_tests.txt`. Proven with
  `git apply --check -R` on the branch tree.

No new `.c`/`.h` files and no new fixture dirs. **No recompiler change**: n-stroke-snap's `stroke_run_flags[]`
already carries LINESTYLE2 noH (bit 1) / noV (bit 2), so the w2's `swf.hpp`/`swf.cpp` hunks (bits 30/31 in
`stroke_run_data`) are dropped, as the brief asked. The headline legs were still run with `--recompile`.

Box: `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Base: `origin/master` `64cf00492`, which includes
n-stroke-snap `09b2c9130`. Corpus: `download_tests.sh avm1 avm2 fonts from_gnash from_shumway import_assets text
visual` on 2026-11-25 (the script prints no upstream SHA; 16 flash-fixes applied). Fidelity: with
`SWF_STROKE_SNAP=0`, my render of `acid-stroke-0` is md5 `48cfef43`, which is the CI actual, at 52702 outliers. So
lavapipe here is CI-identical on this row.

## 0. Verdict

**GO, land.** It is runtime-only and moves 4 of 401 gate comparisons. All 4 move Flash-ward or stay neutral against
an FP32 capture. There are 0 trace changes and 0 image status flips against master. A 5th row,
`regression/avm1_stroke_pixel_snap_matrix`, also moves (it is outside the 274+canary set; see §2): it stays a pass
and moves slightly toward its Flash golden.

| row (graphics) | golden | master (n-stroke-snap) → this patch | vs Flash |
|---|---|---|---|
| `from_shumway/acid/acid-stroke-0` | Flash (LOW, tol 0) | fail **36466 → 10262** | →F. The w2 alone gave 17786 and the snap alone 36466: the two compose |
| `visual/simple_shapes/strokes/scale` | Flash (flash_fixes) | fail **19362 → 12576** | →F. The w2 alone gave 15654 |
| `from_shumway/acid/acid-scale` | Ruffle (≠ Flash) | fail 274 → fail 8942 | →F: px >3 off the coordinator's FP32 capture **5597 → 2175** (corpus golden 5620; the w2 alone gave 2299) |
| `visual/filters/blur_scales_with_screen` | Ruffle | fail 73042 → fail 73030 (max 41) | neutral. Box-downsampled to Flash's 200×200: px >8 3459 → 3465, >32 0 → 0, mean 1.57 → 1.57 |
| `regression/avm1_stroke_pixel_snap_matrix` | Flash | pass 11772 → pass 11760 (limit 12000) | →F: px >2 3924 → 3920 (36 px change, in the skew rows y 329–360) |
| n-stroke-snap ledger: `button3` (3/3/3/3), `avm1_imports_avm1` (36), `regression/avm1_stroke_pixel_snap` (225), `acid-small` (606/474), `gradientTransform` (9), `simple_loop_test` (242/482/722/0/242/482/722), `shape_test` (11368), `place_object_test` (37408), `avm2/sprite_with_frames` (4956) | — | **md5-identical** | none moved |

**Important for CI reading.** The s28 baseline (`7c3cfdcb7`) is PRE-n-stroke-snap. There, `acid-scale` and
`blur_scales_with_screen` PASS. On master, n-stroke-snap already fails both, with 274 and 73042 outliers. The
"pass → fail" on those two belongs to `09b2c9130`, not to this patch. This patch moves acid-scale further from the
Ruffle golden (274 → 8942) but 3.3× closer to Flash. It leaves blur_scales_with_screen where the snap put it.

- The w2's blur_scales_with_screen gain (px >8 2581) is NOT reproduced on top of the snap, which reads 3459 / 3465.
  On an axis-aligned matrix the snap's per-axis re-expansion is already device-isotropic. The rest is the snap's
  quarter-pixel width/position quantisation, which the w2 lacked.
- I did not chase that gap. It needs a Flash capture at the test's 400×400 viewport (below). It is no worse than
  master on any metric.

## 1. Exact patch scope (functions touched, all in `render_webgpu.c`)

- **New `static int hairline_flash_width`**, next to `hairline_snap`. It is set in `hairline_init` from the new
  kill switch `SWF_STROKE_FLASH_WIDTH=0`, which restores the n-stroke-snap pass bit for bit: `acid-stroke-0` gives
  md5 `0c4db6fa` = master. `SWF_STROKE_SNAP=0` still turns off both passes: md5 `48cfef43` = pre-snap CI.
- **New `static hairline_flash_offset()`**, verbatim from the w2 timeline patch, placed just above
  `hairline_restage`.
  - A |d| = h_e vertex (segment side, round join or cap arc) goes to M⁻¹(hw·N̂) with N̂ = M⁻ᵀn/|M⁻ᵀn|. Round
    joins and caps become device circles.
  - Miter and inner-join vertices get the two-normal solve.
- **`hairline_restage`** gets three additions, all inside the existing snap branch. The `hairline_snap == NULL`
  legacy branch is untouched.
  1. After `stage_scale`: v = M·(1,1) in device twips (`v_x`, `v_y`; `scale` is already |v|/√2), the
     similarity test, and `flash_dev = hairline_flash_width && !similar && det ≠ 0`.
  2. Width: **a single flag** uses `stroke_run_flags` bit 2 (NoVScale) → |v.x|, or bit 1 (NoHScale) → |v.y|.
     **Both flags** keep n-stroke-snap's `stage_scale`, not the w2's literal 1. The two are equal at stage scale 1,
     which covers every row measured. Flash's "none" under a zoomed stage is the snap's measured choice. The
     1-device-px minimum and the u/W snap-vs-AA decision are the snap's, unchanged, and run on this width.
  3. Offset: when `flash_dev` is set, the device offset is `M · hairline_flash_offset(local d, h_e = emitted/2,
     hw = target_px/2)`. Otherwise it is the snap's `kx/ky` (axis-aligned) or `k_uni`. **The snap then moves only
     the centre** (quarter-pixel grid, then `stroke_snap_centre` on flagged axes), AFTER the device offset, as the
     brief required.
- **Similarity draws** take the snap's offset path unchanged. This is why 397/401 gate PNGs are md5-identical. The
  only width change on a similarity is a single-flag stroke under rotation, where |v.x| ≠ |v|/√2. No corpus row
  outside the 4 moved ones has one.
- No new pipelines (`MSAA_SAMPLES` is not involved). No `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS` arms are
  touched, so mode parity is not affected. The Drawing-API half is **not** included (brief §4: owned by
  `n-drawapi-stroke-snap`).
- `ruffle-tests/render_canary_tests.txt`: appended at EOF (tier 1) `from_shumway/acid/acid-stroke-0` and
  `regression/avm1_stroke_pixel_snap_matrix`. The standing set saw this change only on non-Flash goldens and on
  strokes/scale. These two are Flash-golden, non-similar and flagged strokes.

## 2. Gate (A/B, same box, graphics)

- Before = clean `origin/master` (`git apply -R` of my diff); after = this patch. Both legs used
  `render_canary.py capture -P 2`.
- **Set:** 281 tests / 401 PNGs. It is the union of the current `render_canary_tests.txt` and the w2's
  `ab_set_274.txt` (s22 stroke set + Drawing-API/shape rows + the regression image rows).
- **Result:** 397 IDENTICAL, 4 DIFFERS (acid-scale, acid-stroke-0, blur_scales_with_screen, strokes/scale; §0).
  TRACE STATUS CHANGES: none. IMAGE STATUS CHANGES: none.
- Headline legs: 14 tests, run separately with `--recompile --mode=graphics --verbose`. They include the two
  `regression/avm1_stroke_pixel_snap*` fixtures, which are newer than the 274 list. Every one is a trace PASS on
  both legs, and the PNG md5s are identical except the 5 rows in §0.
- **Regression suite:** all 78 `regression/` rows in the gate set, plus `avm1_stroke_pixel_snap{,_matrix}`.
  - All are trace pass, unchanged.
  - Image md5s are identical except `avm1_stroke_pixel_snap_matrix`, which stays a pass and moves →F.
- Covered there: `avm1_hairline_scaled_instances`, `avm1_hittest_hairline`, `avm1_stroke_style_id_order` and
  `avm2_timeline_stroke_gradient`.

## 3. EXPECTED-FLIP LEDGER (for CI, graphics; against current master's code)

**Trace axis:** no changes.

**Pixel axis:**

| test / cmp | expected CI move vs a master-code images run | vs the s28 baseline `e1425f417` (pre-snap) |
|---|---|---|
| `from_shumway/acid/acid-stroke-0` output | fail → fail, 36466 → **10262** | 52702 → 10262 |
| `visual/simple_shapes/strokes/scale` output | fail → fail, 19362 → **12576** | fail → fail |
| `from_shumway/acid/acid-scale` output | fail → fail, 274 → **8942** | pass → fail. The snap took the flip; this patch is Flash-ward, see RvF below |
| `visual/filters/blur_scales_with_screen` output | fail → fail, 73042 → 73030 | pass → fail. Owned by the snap; neutral here |
| `regression/avm1_stroke_pixel_snap_matrix` output | pass → pass, 11772 → 11760 | (fixture newer than the baseline) |
| everything else | md5-identical | — |

No-graphics: no expected movement (no NG code touched).

**RvF / flash_fixes.**
- The w2 report §7 drafted RvF entries for `acid-scale` and `blur_scales_with_screen`. They still apply, with these
  numbers.
  - acid-scale: px >3 off FP32 capture `w1-local-oracles/w2-flash-stroke-width/acid-scale.png` is 5597 for master
    and **2175** for this patch. The corpus golden is 5620 off it.
  - blur: unchanged from master.
- **`from_shumway/acid/acid-scale` is a flash_fixes candidate:** the coordinator's capture is 550×400, the golden's
  size. Swapping it in turns this row from a 8942-outlier "loss" into a 2175-px-off gain.
- I did not edit RvF or `fixes.json` (coordinator-owned).

## 4. Refutations / attacks on the brief

- "The timeline-only patch needs `swf.hpp`/`swf.cpp` ported": **refuted.** n-stroke-snap's `LineStyle::scale_flags`
  parse (swf.cpp ~L8285) already extracts flags1 bit 2 (noH) and bit 1 (noV), which matches the SWF spec order.
  `stroke_run_flags[]` emits them. The merge needs no recompiler edit at all.
- The w2's "both flags → 1" vs the snap's `stage_scale`: kept the snap's. They are identical on every row here (stage
  scale 1). The open question is Flash's `none` under stage zoom, which no capture answers.
- Not every w2 gain stacks. blur_scales_with_screen's w2-only gain is already matched or superseded by the snap's
  axis-aligned per-axis path (§0).

## 5. HOLDs / not finished

1. **NoVScale/NoHScale under rotation** (w2 §2, the R(45)·diag(1,2) acid-stroke-0 cell, Flash = hairline). This is
   unchanged and still the w1 rule. Completion: the Flash capture of the w2 fixture's c3 column is already archived
   (`w1-local-oracles/w2-flash-stroke-width/avm1_drawing_stroke_scale.*.png`), but that is the Drawing API. It
   needs a TIMELINE DefineShape4 probe (n-stroke-snap's `probe.py` can generate one with noH/noV + rotation). Then
   refine the two `s_dev` lines in `hairline_restage`.
2. **blur_scales_with_screen vs Flash**: px >8 is 3465 here vs the w2-alone 2581. Completion: a FLASH capture at the
   test's 400×400 viewport (the archived one is 200×200 stage), then attribute the residual to snap quantisation or
   the blur. Priced at 0 flips (tol 2 against a Ruffle golden).
3. Drawing-API / morph strokes: not this slot (n-drawapi-stroke-snap; w2 §5.3).

## 6. New unclaimed leads

- acid-stroke-0's remaining 10262 outliers at LOW, tol 0. They are the LOW stroke raster (45° diagonals, w2 §2) and
  the NoV-rotation cell. This is the cleanest Flash-golden oracle left for the LOW stroke rasteriser.
- strokes/scale's remaining 12576: the polygonal ring (local-space curve flattening at 20×, w2 §6.1). The snap
  already fixed the hairline rows.

## LOCAL ORACLE REQUESTS

1. FLASH (optional, prices HOLD 1): a timeline DefineShape4 probe with noHScale / noVScale strokes under R(30),
   R(45) and R(45)·diag(1,2). Use n-stroke-snap's `n-stroke-snap-captures/probe.py` with a new `sweeps.py` entry;
   image, HIGH, draw() wrapper. Compare the per-edge widths with the rule |v.x| / |v.y|.
2. FLASH (optional, HOLD 2): `visual/filters/blur_scales_with_screen` captured at a 400×400 window/viewport, to grade
   the snap + width merge directly.
