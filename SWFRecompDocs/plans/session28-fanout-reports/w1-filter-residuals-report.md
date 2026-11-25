# s28 wave 1: `w1-filter-residuals` (filter residuals vs Flash Player 32; GPU display-filter growth re-priced)

Branch `fanout/w1-filter-residuals`. Base `origin/master` `d5f9726d`. Box: cloud, `SETUP_STATUS` all OK (Dawn on lavapipe).
`download_tests.sh avm1 avm2 visual from_shumway from_gnash fonts text`: upstream Ruffle master **`c2f7d24b7`**
(flash-fixes: 5 applied).

## NEW files

- `SWFRecompDocs/plans/session28-fanout-reports/w1-filter-residuals-report.md` (this report)
- `SWFRecompDocs/plans/session28-fanout-reports/w1-filter-residuals-prototype.patch`
  (`git diff origin/master -- SWFModernRuntime`; source reverted on the branch)
- `SWFRecompDocs/plans/session28-fanout-reports/w1-filter-residuals-fixtures/avm1_display_filter_growth_edge_scale/`
  (`create_test_swf.py`, `test.swf`, `test.toml`, empty `output.txt`, `output.expected.png` = OUR master render,
  provisional): **FLASH IMAGE request 1**.
- `SWFRecompDocs/plans/session28-fanout-reports/w1-filter-residuals-fixtures/avm2_bevel_sample_isolation_probe/`
  (`create_test_swf.py`, `test.swf`, `test.toml`, `output.txt` = OUR output, provisional): **FLASH TRACE request 2**.
- `SWFRecompDocs/plans/session28-fanout-reports/w1-filter-residuals-fixtures/fit/` (the fit scripts + README)
- `SWFRecompDocs/plans/session28-fanout-reports/w1-filter-residuals-fixtures/prototype-after-renders/`
  (`regression__avm1_runtime_filters__output.after.png`, `regression__avm1_nested_po3_filters__output.after.png`:
  our prototype renders, the comparison targets for request 3).

No source change is committed: the prototype is the `.patch` only, and `git apply --check` passes on `origin/master`.
Files it touches (named for siblings):
- `tag.c`: `filter_shadow_offset_px` (+ new static `g_shadow_frac_x/y`), `compose_chain_entry_to_layer`, and the
  offset block of `render_filtered_core`.
- `avm2_display.c`: the chain-entry composer's `du/dv`, and `avm2_render_filtered`'s pre-shift and composite offset.
- `avm2_bitmap.c`: `fb_glow_amount`.
- No `render_webgpu.c`, `NO_GRAPHICS` or recompiler change.

Mode parity: `fb_glow_amount` is shared with no-graphics. With the patch applied, no-graphics PASSES:
- `regression/avm2_applyfilter_{glow_kernels,gradient_opaque}`, `avm2_bitmapdata_draw_filtered`;
- `avm1_applyfilter_{kernels,glow,bevel,blur}`;
- the `avm1_applyfilter_dropshadow` trace (scratch fixture with the FP32 golden).

## Verdicts

| # | Item | Verdict | Mechanism (one line) |
|---|---|---|---|
| 1 | group-alpha probe `w2b_shadow_shape_a50` (768 px, max 20) | **GO with a priced loss** (prototype: 768 → 0 px vs FP32, AVM1 and AVM2 twins. It costs 3 corpus comparisons on Ruffle goldens, plus 2 regression rows on Ruffle-exporter goldens that wait on LOCAL ORACLE REQUEST 3) | **Shadow offset quantization.** Our display DropShadow reads the blurred layer at `floor(off + 0.5)` whole px (Ruffle's NEAREST sampler); Flash reads it at the FRACTIONAL offset (bilinear). Not group-alpha order, not kernel taps. |
| 2 | applyFilter DropShadow residual (`avm1_applyfilter_dropshadow`: 1 trace line, 15 px max 2) | **Clean GO** (prototype: trace exact, image max 1 with 0 outliers at the fixture's tolerance 1; 0 gate moves) | **Quantization order in the glow amount.** Flash multiplies the FLOORED amount by the colour-alpha BYTE and rounds `/255`; ours floored `amount·(a+1)/256`. |
| 3 | applyFilter Bevel sample residual (glow_kernels 4 lines, draw_filtered 1+1, gradient 2) | **HOLD (4 more hypotheses refuted; isolation probe built)** | Unknown, but now bounded: the nominal offset is the unique best fit, so the geometry is right. The residual is in how one floored sample value is produced. |
| 4 | GPU display-filter growth | **NO-GO stays, re-priced: unobservable by construction on an unscaled object** | Flash's display blur is the floored box chain. That tail ALWAYS ends inside the applyFilter growth `ceil(sc·b/2)`, so no clip rule can show. The only visible difference is tail LENGTH (kernel taps): ours is 1–4 px longer at q 6..12. |

**Priced flips (corpus, graphics, gate below):**
- +0 gains. No Flash-provenance golden shows a fractional display DropShadow.
- −3 pixel comparisons on Ruffle goldens: `visual/filters/drop_shadow` and `visual/cache_as_bitmap/edittext_scroll`
  output.01 / .02. These come from part B only, and need an RvF disposition.
- −2 regression image rows on Ruffle-exporter goldens: `avm1_runtime_filters`, `avm1_nested_po3_filters`. These are
  part B only; request 3 re-goldens them.
- Trace: 0 moves.

The yield is **+1 Flash-golden regression row ready to land**
(`avm1_applyfilter_dropshadow`, trace + image), **+2 Flash-golden group-alpha rows ready to land**
(`group_alpha_shadow_shape_a50` and its AVM2 twin), and two FLASH requests that settle the two remaining questions.

## GATE (task 4): render canary + every `filter` image row + regression filter fixtures

`render_canary.py run --stash tag.c avm2_display.c avm2_bitmap.c -P 2`. The list (209 tests / 268 PNGs) is the
union of:
- the standing `render_canary_tests.txt` (189 members);
- all 47 image rows with `filter` in their path (avm1, avm2, visual, from_shumway, regression);
- every `regression/` applyFilter / PO3 / group-alpha / layer-group fixture.
```
IDENTICAL 263   DIFFERS 5   APPEARED 0   VANISHED 0   NO_RENDER 0     TRACE STATUS CHANGES: none
regression/avm1_nested_po3_filters      output     pass -> fail   5970 ch, max 9    golden = Ruffle exporter 0ddd12b6a
regression/avm1_runtime_filters         output     pass -> fail   3060 ch, max 18   golden = Ruffle exporter 0ddd12b6a
visual/cache_as_bitmap/edittext_scroll  output.01  pass -> fail    276 ch, max 128  golden = Ruffle ("untestable": default font)
visual/cache_as_bitmap/edittext_scroll  output.02  pass -> fail    273 ch, max 128  golden = Ruffle ("untestable")
visual/filters/drop_shadow              output     pass -> fail  39320 ch, max 46   golden = Ruffle ("untestable": default font)
```
- **Bisected on `edittext_scroll`:** the move comes from `tag.c` alone (the fractional shadow offset), not from
  `avm2_bitmap.c` or `avm2_display.c`. Its text field carries a binary PlaceObject3 filter list, and both legs are
  md5-stable on rerun. All 5 moved comparisons are display DropShadows at fractional offsets: `runtime_filters`
  case D is 8 px at 45°; `drop_shadow` and `edittext_scroll` are Ruffle-test shadows.
- **The `fb_glow_amount` half moves NOTHING in the gate.** Every applyFilter row is md5-identical, including
  `destpoint_edges` (Flash golden), `bitmapdata_applyfilter_blur` (the priced Ruffle loss, untouched) and the 4
  `avm1_applyfilter_*` rows.
- **Flash rows that could see the shadow change:**
  - `visual/filters/drop_shadow_angles` (Flash capture archived) does not move: its shadows are at integer offsets
    (0/90/180/270° × distance 15, and −21 at 360°).
  - `from_shumway/acid/acid-filter` and `acid-filter-2` (Flash exact) are md5-identical.
  - So no Flash golden is lost.

**Pricing.**
- **Part A, `fb_glow_amount` (applyFilter DropShadow residual):** **clean GO**. 0 moves; one Flash trace line and the
  Flash image go to pass.
- **Part B, the fractional display DropShadow offset (`shadow_shape_a50`):** **GO with a priced loss**.
  - Gains: +2 Flash-golden group-alpha rows (768 px → 0).
  - Losses, corpus: 3 pixel comparisons lost to RUFFLE goldens (`visual/filters/drop_shadow`,
    `cache_as_bitmap/edittext_scroll` .01 + .02). They need an RvF entry: Ruffle's NEAREST sampler vs Flash's
    bilinear, from the FP32 `w2b_shadow_shape_a50` capture.
  - Losses, regression: 2 rows whose goldens are Ruffle-exporter renders (`avm1_runtime_filters`,
    `avm1_nested_po3_filters`). They need FP32 captures before landing (LOCAL ORACLE REQUEST 3). If Flash equals our
    after-render (`w1-filter-residuals-fixtures/prototype-after-renders/`), re-golden them to Flash and the
    regression cost is 0.
  - **Recommend wave 2 lands A at once, and B together with request 3** (one Flash pass over the two regression
    SWFs). B is one capture of evidence against Ruffle's rule, so the request is also the second confirmation.

## 1. `w2b_shadow_shape_a50`: fractional shadow offset (GO)

### 1.1 Per-pixel diff (FP32 `w2-local-oracles/w2b-group-alpha-triggers/w2b_shadow_shape_a50/flash.screen.png` vs ours, master)

The probe: root SHAPE, red rect (20,20)–(100,80); DropShadow black, blur 4, 45°, distance 12, strength 1, q1; 50%
alpha. Offset = 12·cos 45° = **8.485 px**.
- Every pixel off by more than 1 (768 px) lies in the **5-px blur ramp** of the shadow's right edge (x = 106..110),
  its bottom edge (y = 86..90) and its top-left onset (x or y = 26..30). Nothing inside the rect, nothing in the
  shadow's flat interior. Per column: 64 px at x = 106..108, 62 at 109, 61 at 110, and 5 per column on the onset band.
- Row 50, x = 105..111 (grey level; shadow alpha = 2·(255 − grey)):

  | x | 105 | 106 | 107 | 108 | 109 | 110 | 111 |
  |---|---|---|---|---|---|---|---|
  | ours | 128 | 144 | 176 | 208 | 240 | 255 | 255 |
  | Flash | 128 | 136 | 160 | 192 | 224 | 248 | 255 |

  Our ramp has steps of 33/64/64/64/30 alpha, ending at x = 110. Flash's has steps of 17/48/64/64/48/14, ending at 111.
- Inside the rect: ours (255,127,127), Flash (255,128,128). That is one level of group-alpha rounding, within
  tolerance 1. It is not part of the 768 px.

### 1.2 Mechanism (fitted)

Python model (`w1-filter-residuals-fixtures/fit/fit_shadow.py`):
- Blur = the half-ended box `[.5,1,1,1,.5]/4` per axis, floored per pass. This is what both we and Flash use for
  blurX 4.
- **Nearest offset 8** (ours): reproduces OUR render at **0 px > 1** (768 px vs Flash).
- **Bilinear at 8.485** (Flash): **0 px > 1 vs the Flash capture**, max 1. That holds for float weights and for
  weights quantised to 1/256. Quantising to 1/64 or coarser starts to miss.

Owner: `tag.c filter_shadow_offset_px` (the pre-shift folded into the blur), `render_filtered_core` (the composite
offset, both arms), `compose_chain_entry_to_layer`; `avm2_display.c avm2_render_filtered` (pre-shift and composite)
and its chain-entry composite. All of them round with `floor(-off + 0.5)`, ported from Ruffle's NEAREST sampler
(`glow.rs` / `drop_shadow.rs` `get_sampler(false, false)`). **Ruffle ≠ Flash here (RvF candidate):** Ruffle snaps a
display DropShadow to whole pixels; Flash interpolates.

### 1.3 Prototype (in `w1-filter-residuals-prototype.patch`)

- `filter_shadow_offset_px`: the pre-shift is `floor(off)` (off rounded to 1/256 first, so float noise near an
  integer cannot flip the floor). The remainder goes to `g_shadow_frac_{x,y}`.
- `render_filtered_core`: a pre-shifted shadow now passes `-frac·uv` (was 0) to `renderer_compose_filter`, whose
  `filter_sampler` is already LINEAR, so the read is bilinear. The non-pre-shifted arm (chained or grouped) passes
  the exact `xd·uv` (was `floor(-xd+0.5)`). Same in `compose_chain_entry_to_layer`.
- `avm2_display.c`: the same two changes in `avm2_render_filtered`'s pre-shift and composite offset, and in the
  chain-entry composite (the `du/dv` at the top of the per-entry composer).
- Bevel offsets are **left at nearest**. There is no Flash display-bevel capture, and the applyFilter bevel is itself
  unresolved.
- No shader, pipeline or uniform layout change (no `MSAA_SAMPLES` question arises).

### 1.4 Result

| probe (scratch fixture: probe SWF + FP32 PNG, tolerance 1, max_outliers 0) | master | prototype |
|---|---|---|
| `w2b_shadow_shape_a50` (AVM1) | FAIL 2304 channels (768 px), max 20 | **PASS, 0 outliers, max 1** |
| `avm2_w2b_shadow_shape_a50` (AVM2 twin, same golden) | FAIL 2304 channels (768 px), max 20 | **PASS, 0 outliers, max 1** |

## 2. applyFilter DropShadow residual (GO)

### 2.1 Per-pixel diff (FP32 `w2-local-oracles/w2-applyfilter-cm/avm1_applyfilter_dropshadow/flash.{png,txt}`)

Filter: DropShadow(5, 45°, black, alpha 0.8, blur 6, strength 1, q2), offset 3.5355.
- 15 px are > 1 (all +2 on Flash's side): the far ramp of the shadow (dt x = 51, y = 40..46; y = 51, x = 40..46;
  (50,49)).
- At threshold 0: **213 px**. The sign map is almost all `+1` (Flash's alpha one level higher), scattered over the
  whole blurred ramp band. That is a value-quantization signature, not a geometry one.

### 2.2 Mechanism (fitted on all 6 080 shadow-only target px)

- A Python replica of `fb_glowlike_region` (box chain + `fb_alpha_level` + `fb_glow_amount`) reproduces OUR render
  exactly (0 px). The image on white is `255 − ga`.
- Grid search over offset quantisation, bilinear forms and the alpha multiply:
  - **`ga = (floor(amount)·alpha_byte + 127) / 255`** (alpha 0.8 → byte 204) with float bilinear: **41 px at ±1**,
    0 px > 1.
  - The same, plus bilinear weights quantised to 1/256 or 1/128 (integer accumulate, floor): **0 px**.
- In C, against EVERY Flash glow-family row we hold (the full `glow_kernels`, `draw_filtered` and `gradient_opaque`
  Flash probes, and the 4 landed AVM1 applyFilter fixtures):
  - The alpha rule alone keeps every exact row exact. Only the DS line moves, to Flash's value. The other
    mismatching lines (the bevel residuals) are **byte-identical** before and after.
  - The 1/256 weights break 1 landed gradient row (`gradientbevel outer y=10`, `c8`→`c7`) and 3 bevel lines. The
    bilinear weight precision is therefore NOT 1/256 for bevel/gradient, and is left as float. Pixel-exactness of
    the DS image is a HOLD that waits on item 3 (same sample function).

### 2.3 Prototype: `avm2_bitmap.c fb_glow_amount`

`ga = (floor(amount) · a + 127) / 255` replaces `floor(amount · (a + 1) / 256)`. The s27 comment's motivating row
still holds: `glow quality3 alpha.5` gives 36·127/255 → 18, the same as before. The AVM1 bridge
(`avm1_filter_kernels.c`) re-compiles this kernel block, so both VMs get it.

| row | master | prototype |
|---|---|---|
| `avm1_applyfilter_dropshadow` (scratch: FP32 trace + PNG, tolerance 1) | trace 1 line (`dt 50,50` 0x98 vs 0x99); image FAIL 45 channels, max 2 | **trace PASS; image PASS, 0 outliers, max 1** |
| full `glow_kernels` Flash probe | 4 bevel lines | the same 4 lines, byte-identical |
| full `draw_filtered` Flash probe | 2 lines | the same, byte-identical |
| full `gradient_opaque` Flash probe | 2 lines | the same, byte-identical |
| `regression/avm2_applyfilter_{glow_kernels,gradient_opaque}`, `avm2_bitmapdata_draw_filtered`, `avm1_applyfilter_{glow,bevel,blur,kernels}` | PASS | PASS |

## 3. Bevel sample residual (HOLD)

All residual pixels need `floor(B(x+o)) − floor(B(x−o))` one level toward zero, e.g. `bevel full knockout`:
- (6,9): b_l = 118.114, b_r = 169.039 → −51; Flash −50.
- (10,10): b_l = 225.101, b_r = 181.985 → 44; Flash 43.

Refuted this session (on the 40 knockout px, where the alpha byte IS `ga`):
1. **Any offset perturbation.** I perturbed each side independently by ±12/64 px in 1/64 steps (625 combos per side),
   and both sides symmetrically. The nominal offset is the **unique best** (2 px). No offset rule exists.
2. **Shift-then-blur** (resample the SOURCE at ±offset, then blur). Floor: 4 px off; round: 8.
3. **Fixed-point blur division** (reciprocal at 8 / 10 / 12 / 15 / 16 / 24 bits, truncated): 13–14 px off. The
   exact floor stays the best (2).
4. **Asymmetric per-side rounding** (`ceil(b_l) − floor(b_r)` and similar): it fixes one pixel and breaks
   (6,7)-class pixels.

Together with s27's list (weight quantisation 1/8…1/65536, offset quantisation, float-difference trunc/floor/round,
inverted samples), the remaining space is the blurred grid B itself, or a bevel-specific blur input. Completion:
**FLASH request 2.** It dumps Flash's B grid (BlurFilter 3 and 4) and the bare bevel d (knockout + full,
strength 1, alpha 1, so the alpha byte = |d| and the colour gives the sign) for 15 (distance, angle) cases on two
sources (the glow_kernels source, and a 24-column alpha ramp). One capture fits both the blur and the sample offline.

## 4. GPU display-filter growth (NO-GO, re-priced)

- **The s27 probe could not discriminate.** Under the Flash box model (q passes of `fb_kernel(b)`, floored per pass,
  which Flash's display path shares: `blur_pass_scaling` golden, display row == applyFilter row), the s27
  `avm1_display_glow_growth_probe` rows (20 px square, blurX 80, q 6..12) have a predicted Flash tail of
  **129 / 135 / 140 / 144 / 147 / 149 / 150 px**, against the applyFilter clip of 152 … 240. Ours renders
  130 / 137 / 142 / 146 / 150 / 152 / 154. The per-pass floor cuts the tail before the growth bound; I checked
  q 7..12 at widths 10–100 and blur 40/60, and in every case tail < `ceil(sc·b/2)`.
- **So a growth clip cannot be observed on an unscaled display object.** The growth sizes only the zero padding.
- What CAN differ, and what our model would need to match:
  - (a) **Tail length** (kernel taps): ours is 1–4 px longer at q ≥ 6. Ruffle's scaled-pass kernel stands in for
    q real box passes. Matching means running q floored box passes on the GPU (`render_webgpu_run_blur`: a
    q-pass loop of `fb_kernel` boxes, like the s27 `set_blur_exact` prototype arm; any new pipeline uses
    `MSAA_SAMPLES`).
  - (b) **Off-stage capture**: content past the stage edge that blurs or throws a shadow back onto the stage.
    `tag.c` pre-shifts the lone-DropShadow blur for this (acid-filter); a glow of an off-stage half relies on the
    padded layer gate (`filter_chain_reach_px`).
  - (c) **Scale**: whether Flash applies `(b−1)·scale+1` only for the stage view (ours) and never for an object or
    parent scale.
- **FLASH request 1** (`avm1_display_filter_growth_edge_scale`, 400×300, six cases A–F) measures all three. Ours,
  for comparison:
  - A (glow of a half-off-stage square at the left edge): halo reaches x = 0 at y = 5..74.
  - B (DropShadow thrown back from a half-off-stage square at the right edge): blue at x = 347..379, y = 40.
  - C (scale-3 object, glow blur 10): halo 5 px (not 15).
  - D (scale-3 object, DropShadow distance 10 at 45°, 7.07 px): rendered with master's nearest rule in the
    provisional PNG.
  - E (scale-2 parent, child glow blur 8): halo x = 36..73.
  - F: tail at x = 79..291, against the Flash-model prediction of 82..287.
  - (Measured on the shipped provisional PNG, which is a clean-master render.)
- If Flash matches the box model, (a) is a priced kernel-taps slice. **It is not growth**, and the NO-GO on growth
  stands.

## Refutations / premise checks

- **"`shadow_shape_a50` is a group-alpha residual"**: refuted. The group composite is right; the 768 px are the
  shadow offset. The group probe was just the first Flash capture with a fractional display-shadow offset.
- **"The applyFilter DropShadow residual is the fractional-offset sampling"** (s27 HOLD text): refuted. The offset
  sampling (bilinear, float) is right. The residual is the alpha multiply's quantization.
- **"GPU growth: a clip shows at q 7..10 with a large blur"** (s27): refuted analytically. The floored box tail never
  reaches the growth bound, so the s27 probe's rows cannot discriminate (the predicted Flash tail is shorter than
  every clip value).
- **"Our display glow's tail is shorter than the clip, so even our render cannot show it"** (s27): true, and Flash's
  is shorter too.

## Dispositions

- RvF candidate (after the coordinator's CI pricing): Ruffle snaps display DropShadow offsets to whole pixels
  (NEAREST); FP32 interpolates (`w2b_shadow_shape_a50`, 768 px). Ruffle-golden rows that move toward Flash would be
  priced losses under this entry (GATE).
- `avm1_applyfilter_dropshadow` and `group_alpha_shadow_shape_a50` (+ AVM2 twin) are landing candidates with FP32
  goldens once the prototype lands (recipes: `regression/avm1_applyfilter_blur/create_test_swf.py` writes any
  `../avm1_applyfilter_<kind>` dir; `regression/group_alpha_filter_cm/create_test_swf.py` + the
  `mkprobes_w2b.py` `shadow_shape_a50` lambda).

## New unclaimed leads

- **Display Glow/DS/Bevel composite parity.** The GPU composite shader is still Ruffle's float maths, while the
  applyFilter path is the Flash integer model (straight-space inner lerp, outer `(256−da)>>8`, and now the rounded
  `/255` alpha). A Flash capture of an inner-glow sprite at strength 2 would price it.
- **Bevel display offset.** It is still nearest (left alone here). Once request 2 settles the applyFilter bevel
  sample, check a display bevel at a fractional distance against Flash.
- **Kernel taps at q ≥ 6 on display filters** (section 4a), priced by request 1's row F.

## LOCAL ORACLE REQUESTS

1. **FLASH: `session28-fanout-reports/w1-filter-residuals-fixtures/avm1_display_filter_growth_edge_scale`, image,
   1 frame, direct (draw() wrapper is fine: no blend modes; `--screen` also OK), 400×300.**
   Compare per case against ours (`output.expected.png`, provisional, master render):
   - A: the left-edge halo extent and its intensity at x = 0..4.
   - B: the blue shadow's x-extent at y = 40.
   - C: the halo width around the 60 px scaled square (5 px means blur in stage px).
   - D: shadow offset and ramp under scale 3, the fractional-offset rule.
   - E: the halo width for the scale-2 parent.
   - F: the red run's x-extent at y = 255 (box-model prediction 82..287, ours 79..290).
   Archive as `flash.png`.
2. **FLASH: `session28-fanout-reports/w1-filter-residuals-fixtures/avm2_bevel_sample_isolation_probe`, trace,
   1 frame** (AVM2, `run_trace.py`; 681 lines). Diff against our provisional `output.txt`:
   - the `blur3/blur4 K|R` rows give Flash's B grid;
   - the `bevel d<dist> a<ang> K|R` rows give Flash's d.
   That settles the bevel sample (item 3) and the 41 ±1 px of item 2.
3. **FLASH image, 1 frame each (prices part B of the prototype):**
   - `ruffle-tests/tests/swfs/regression/avm1_runtime_filters/test.swf` (`num_frames 1`);
   - `ruffle-tests/tests/swfs/regression/avm1_nested_po3_filters/test.swf` (`num_frames 3`).
   Compare each with its current Ruffle-exporter golden AND with our prototype after-render
   (`w1-filter-residuals-fixtures/prototype-after-renders/regression__<name>__output.after.png`). If Flash ≈ the
   after-render on the DropShadow regions (`runtime_filters` case D: bbox (43,173)–(168,253);
   `nested_po3_filters`: bbox (97,37)–(148,238)), re-golden both to Flash with part B.
4. (optional, cheap) **FLASH image of the AVM2 twin `avm2_w2b_shadow_shape_a50`** (`mkprobes_w2b.py OUT avm2`), to
   confirm that it shares the AVM1 golden before both land.
