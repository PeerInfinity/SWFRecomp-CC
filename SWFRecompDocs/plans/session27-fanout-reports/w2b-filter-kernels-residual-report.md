# s27 wave 2b: `w2b-filter-kernels-residual`: AVM2 filter kernels, the residual rows, gradient filters, GPU growth, the blur disposition

Branch `fanout/w2b-filter-kernels-residual`. Patch: `w2b-filter-kernels-residual.patch` =
`git diff origin/master --binary -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py
ruffle-tests/render_canary_tests.txt ruffle-tests/tests/swfs/regression/avm2_applyfilter_glow_kernels
ruffle-tests/tests/swfs/regression/avm2_applyfilter_gradient_opaque ruffle-tests/tests/swfs/regression/avm2_bitmapdata_draw_filtered
ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md SWFRecompDocs/plans/graphics-fanout-playbook.md`
(the last two are the docs-only hunks of task 4), checked with `git apply --check -R`. Base: `origin/master` `2d189a8ad`.
Upstream tests downloaded with `download_tests.sh avm2 visual` (upstream master at run time, the `1e604fa87` line).
Box: cloud, Dawn on lavapipe, SETUP_STATUS all OK.

## NEW files

- `ruffle-tests/tests/swfs/regression/avm2_applyfilter_glow_kernels/{create_test_swf.py,test.swf,test.toml,output.txt}`
- `ruffle-tests/tests/swfs/regression/avm2_bitmapdata_draw_filtered/{create_test_swf.py,test.swf,test.toml,output.txt}`
- `ruffle-tests/tests/swfs/regression/avm2_applyfilter_gradient_opaque/{create_test_swf.py,test.swf,test.toml,output.txt}`
  (the s27 gradient/opaque Flash probe, landed)
  - All three `output.txt` are **Flash Player 32 captures minus the lines of held cases** (`HELD` in each generator; every
    case runs on fresh objects, so the remaining lines are byte-for-byte Flash's). `HELD = ()` rebuilds the full probe.
- `SWFRecompDocs/plans/session27-fanout-reports/w2b-filter-kernels-residual-fixtures/avm1_display_glow_growth_probe/`
  (FLASH IMAGE oracle probe, not landed; `output.expected.png` is OUR provisional render)
- `SWFRecompDocs/plans/session27-fanout-reports/w2b-filter-kernels-residual-fixtures/avm2_applyfilter_opaque_target_probe/`
  (FLASH TRACE oracle probe, not landed; `output.txt` is OUR provisional output)
- this report and `w2b-filter-kernels-residual.patch`

Modified: `SWFModernRuntime/src/avm2/avm2_bitmap.c` (only); docs `RUFFLE_VS_FLASH_DIFFERENCES.md` (one entry extended),
`graphics-fanout-playbook.md` (one row of the image-axis dispositions table). No `verify_output.py`, CMake or
Emscripten change (no new TU). `render_canary_tests.txt` unchanged (see Canary).

## Verdicts

| item | verdict |
|---|---|
| 1. Residual inner / bevel rows | **GO.** `glow_kernels` (full Flash probe) **16/23 → 19/23** lines exact; every Glow / DropShadow row (inner, outer, knockout, hideObject, quality 3) is now exact. The inner composite is a **straight-space lerp** (mechanism 1), which the prior report proved no premultiplied 8-bit rounding can be. Bevel moved to the same integer composites: 7 → 4 px. The 4 px left (and 1 px in `draw_filtered`, 2 px in the gradient bevel) are one sample-difference level at fractional offsets; HOLD with a probe (LOCAL ORACLE REQUEST 2). |
| 1b. Land the two held fixtures | **DONE, green.** Both land in `regression/` with the residual bevel cases HELD (Flash output minus those lines): `avm2_applyfilter_glow_kernels` (7 of 10 cases + the #2077 tail) and `avm2_bitmapdata_draw_filtered` (5 of 6 cases). Both PASS in both modes. The full probes stay under `w2-held-fixtures/`. |
| 2. GradientGlow / GradientBevel | **GO.** New Flash kernels (`fb_grad_lut`, `fb_grad_pixel`). On the Flash probe every GradientGlow row (outer / inner / full knockout) and the inner + outer GradientBevel rows are **exact**. `gradientbevel full knockout` is 2 px off (the bevel sample residual). The probe lands as `regression/avm2_applyfilter_gradient_opaque` with that one case held: **PASS** (before: 15 of 26 Flash lines wrong). |
| 2b. NEW: #2077 set | **GO.** Flash also throws #2077 for GradientGlow / GradientBevel onto an opaque target (probe lines 10–11). Implemented. The rest of the probe's #2077 rows confirm the s27 set (inner / knockout glows throw; an opaque SOURCE does not matter; Blur / CM / Convolution do not throw). |
| 2c. NEW: blur onto an opaque target | **GO (one pixel of evidence).** Flash `ff1e253b`, ours was `ff060d23`. Flash composites the partial-alpha result over the target: `c + (dst·(255−a)) >> 8`, every channel exact. Over-destination vs over-white is not separable on a white target, so LOCAL ORACLE REQUEST 3 asks. Separately, an a = 0 texel leaves the target untouched; that part is unmeasured, and the formula alone would give 0xFE. |
| 3. GPU display-filter growth | **NO-GO (premise refuted for the corpus).** The display paths (`tag.c::filter_draw_offset_px`, `avm2_display.c::avm2_filter_draw_offset_px`) already use `PASS_SCALES`, at ruffle's full `sc·blur` (twice Flash's applyFilter growth). On a display object the growth only sizes the cache rect: zero-filled padding is invisible, and it would show only as a CLIP of a visible tail. Measured: no corpus row can see it (details below). A discriminating Flash image probe is built (LOCAL ORACLE REQUEST 1). |
| 4. `bitmapdata_applyfilter_blur` disposition | **DRAFTED** (docs hunks in the patch). The existing RvF `<!-- image-axis: avm2/bitmapdata_applyfilter_blur output -->` entry gets the s27 re-measure and an explicit scope. The stale "RESOLVED s21" playbook table row now points at it. |
| 5. Dead ruffle-port kernels | **DONE.** Deleted `bd_glowlike_source_region`, `bd_blur_source_region` and their private helpers: `BlurKernel`, `blur_kernel_for`, `blur_clamp`, `blur_axis_pass`, `fk_sat`, `fk_unorm`, `fk_store`, `FkTex`, `fk_blur_alpha`, plus the now-unused `fb_alpha_at`. That is ~350 lines, replaced by a pointer comment. `bd_displace_source_region` (same block) is kept. |

**Priced flips on CI:** none on the baseline board. The yield is **3 new green Flash-golden regression rows** and Flash
fidelity of the AVM2 glow-family kernels; see the EXPECTED-FLIP LEDGER.

## Mechanism (all in `SWFModernRuntime/src/avm2/avm2_bitmap.c`)

Functions touched:
- **New:** `fb_mul_grad`, `fb_glow_composite`, `fb_glow_amount`, `fb_bevel_pixel`, `fb_grad_lut`, `fb_grad_pixel`.
- **Rewritten:**
  - `fb_glow_pixel` (now amount + shared composite);
  - `fb_glowlike_region` (bevel via `fb_bevel_pixel`; gradient kinds; GradientGlow geometry);
  - `fb_write_grid` (opaque-target composite).
- **Edited:** `bd_apply_filter` (gradient kinds routed to `fb_apply_grown`, the pass-through removed, #2077 for gradients).
- **Deleted:** the task-5 list above.

No sibling-owned function is touched: not `bd_draw_shape_walk`, not `text_raster_core`, not
`avm1_filter_kernels.c`. All of it is inside the shared kernel block, which the AVM1 bridge re-compiles; see the note
for the sibling below.

The model was fitted in a Python replica of the `fb_*` pipeline. That replica first reproduced master's C output
byte-exactly: the same 17 residual px. Each rule then had to keep every already-exact row exact.

1. **Inner composite = straight-space lerp** (Glow, DropShadow, Bevel, and both gradient filters).
   - `S = unmul(src)` uses Flash's own factor table (31 → 52, the 0x34 Flash reads back).
   - Per channel: `s = (glow_premul·256 + S·(256 − ga)) >> 8`, then `fb_mul8(s, da)`. Alpha = `da`.
   - It fits all 40 inner px of `glow inner` / `dropshadow inner`.
   - Search record: `S·(255−ga)` gives 27 px off; the 8-bit premultiplied form (the s27 w2 model) gives 9 px off. A
     brute force over 9 multiply variants × 4 structures × 2 alpha forms (`fit_inner`) found nothing better than 9.
   - The data point that forces it is DS inner `ga=209`: Flash stores r=5 / b=28 from d=(31,·,153). That is
     inconsistent with any linear rule on the premultiplied value, and exact in straight space: `52·47>>8 = 9`, then
     `9·153/255 → 5`.
2. **Outer composite** = `glow·(256 − da) >> 8 + src`. This fixes `dropshadow default` (9,6), which was alpha a2 vs a1.
   All outer rows stay exact.
3. **Full (on-top)** = `glow + (src·(256 − ga)) >> 8`. It is only exercised with knockout, where it reduces to the
   bare glow.
4. **Bevel** = the glow amount rule on `|b_l − b_r|·strength` with colour2/alpha2 (≥ 0) or colour/alpha (< 0), then
   the composites above. Before, it was ruffle's float shader maths.
   - `glow_kernels` bevel rows: 7 → 4 px.
   - `destpoint_edges` Bevel cell: **2 986 → 23** channels off its Flash golden.
5. **Gradient table** (`fb_grad_lut`): 256 straight entries. Each channel, alpha included, is the floored lerp between
   the bracketing stops, and the colour premultiplies as `(c·(a+1)) >> 8`.
   - Evidence: the 16 bare-glow px of `gradientglow full knockout` are all exact.
   - Alternatives rejected: rounded lerp, and `/255` premultiply (idx 94: 25 vs 24; idx 210: 74 vs 73).
   - Interpolation is straight, not premultiplied: the `outer` tail shows red where a premultiplied lerp from an α=0
     red stop has none.
6. **GradientGlow** indexes the table with `min(255, floor(level·strength))`.
   - `level` is the PLAIN blur at −offset, also for "inner". The inner rows show the source untouched where the offset
     sample leaves the object; an inverted blur fails all 20 inner px.
   - The geometry is DropShadow's: a GradientGlow has a distance and angle.
7. **GradientBevel** indexes with `floor(128 + (b_l − b_r)·strength/2)`.
   - b_l is the +offset (highlight-side) sample, so the LAST stop lands top-left at 45°.
   - Rounded and truncated variants are worse (26 / 11 px vs 2).
8. **Opaque target** (`fb_write_grid`): see 2c above. It is used by Blur only on AVM2 (glow-likes throw first). On
   AVM1 the bridge reaches it for every kind.

**Bevel sample residual, unresolved.** Every remaining px is a bevel whose Flash `b_l − b_r` is one level away from
`floor(b_l) − floor(b_r)`:
- (9,6): float diff −50.92, Flash needs −50.
- (10,10): float diff 43.12, Flash needs 43.
- draw (16,15): float diff −102.73, Flash needs −104.

Tried and rejected: bilinear weights quantised to 1/8 … 1/65536 (floor / round / ceil, joint and separable), offset
quantisation to 1/8 … 1/1024 (trunc / round / floor), a float difference (trunc / floor / round), and inverted-blur
samples for one or both sides. None of them fits without breaking the DS rows, which are exact at the same offsets.
Completion mechanism: LOCAL ORACLE REQUEST 2.

## Per-test before → after (clean `origin/master` vs patch, same box, `--mode=graphics`)

| test | axis | before | after |
|---|---|---|---|
| `regression/avm2_applyfilter_glow_kernels` (landed subset, 17 lines) | trace | MISMATCH (5 lines: glow inner ×2, DS default y=6, DS inner ×2) | **PASS** (no-graphics PASS too) |
| `regression/avm2_applyfilter_gradient_opaque` (landed subset, 24 lines) | trace | MISMATCH (blur→opaque, 2 × #2077, 10 gradient rows) | **PASS** (no-graphics PASS too) |
| `regression/avm2_bitmapdata_draw_filtered` (landed subset, 11 lines) | trace | PASS | PASS (no-graphics PASS too) |
| full `glow_kernels` Flash probe (`w2-held-fixtures`, 23 lines) | trace | 16/23 exact | **19/23** (4 bevel px left) |
| full gradient/opaque Flash probe (26 lines) | trace | 11/26 exact | **24/26** (2 px left, `gradientbevel full knockout`) |
| full `draw_filtered` Flash probe (13 lines) | trace | 11/13 | 11/13 (bevel `ff980000` vs `ff970000` at 16) |
| `avm2/bitmapdata_applyfilter_destpoint_edges` (Flash golden) | pixel | pass, 0 outliers, max 1 | pass, **3** outliers (limit 35), max 2 |
| `avm2/bitmapdata_applyfilter_blur` | pixel | fail 47 515 / max 238 | fail 47 515 / max 238 (unchanged) |

On `destpoint_edges` the change brings the render closer to Flash overall:
- Channels differing from the Flash golden: **54 248 → 50 358**.
- Bevel cell: 2 986 → 23.
- The two glow/DS cells: 20 769 → 20 316 and 20 787 → 20 313.
- The 3 outlier channels are ONE pixel, (585,39) in a DS/glow cell: 110 → 109 vs Flash 111. It is a −1 move of a
  pixel that was already off by 1, now 2; tolerance 1.

Sweep, 24 rows, before vs after, same box. Verdicts and outlier counts are identical except for the ledgered rows:
- **avm2:**
  - `bitmapdata_applyfilter_blur` (fail 47515 both)
  - `_colormatrix` (0/max 1)
  - `_destpoint` (0/0)
  - `_destpoint_edges` (above)
  - `_identity`
  - `bitmapdata_filter_sourcerect` (0/0)
  - `filters_array_holes`
  - `pixelbender_effect_glassDisplace_shaderfilter` (0/0)
  - `bitmapdata_draw_filters` (0/0)
  - `all_classes/display/swf9`
- **visual:**
  - `cache_as_bitmap/bitmap_changed`
  - `filters/blur_fractional` (0/0)
  - `filters/blur_pass_scaling` (0/max 2)
  - `filters/blur_quality` (fail 205332 both)
  - `filters/displacement_map_through_applyFilter` (0/max 2)
  - `filters/glow_pass_scaling` (0/0)
- **regression:**
  - `avm1_applyfilter_convolution_not_cm`
  - `avm1_applyfilter_kernels`
  - `avm1_runtime_filters` (0/max 1)
  - `avm1_runtime_filters_cm_bitmap` (0/0)
  - `avm2_bitmapdata_draw_textfield`
  - the 3 new fixtures

Render canary (`render_canary.py run --stash SWFModernRuntime/src/avm2/avm2_bitmap.c -P 2`), over 102 tests / 125
comparisons:
- Members: every `avm2/` and `visual/` member of `render_canary_tests.txt`, plus its `regression/` filter / PO3 /
  layer-group members.
- Result: **IDENTICAL 124, DIFFERS 1**. The one DIFFERS is `avm2/bitmapdata_applyfilter_destpoint_edges` (pass →
  pass, 3 957 channels, max 1; it is in the ledger). No trace or image status changes.
- I did not run the AVM1, gnash and shumway members: only the AVM1 applyFilter bridge reaches this code, and its two
  regression rows pass in both legs.
- No member was appended. `destpoint_edges` already sees the glow/DS/bevel composite class, and no image row in the
  corpus exercises gradient filters or an opaque applyFilter target. Those two paths are guarded by the new trace
  fixtures instead, which CI grades.

Late edit after the canary: `fb_write_grid`'s opaque branch now skips a = 0 grid texels. Without that, the fitted
`(dst·(255−a))>>8` turns untouched white into 0xFE. Only opaque applyFilter targets reach this branch. I re-ran the 10
applyFilter image rows above plus the 5 regression filter fixtures after it: all values are unchanged.

## EXPECTED-FLIP LEDGER (for the coordinator's CI read)

| test | axis | expected on CI |
|---|---|---|
| `regression/avm2_applyfilter_glow_kernels` | trace | NEW row, **pass** |
| `regression/avm2_applyfilter_gradient_opaque` | trace | NEW row, **pass** |
| `regression/avm2_bitmapdata_draw_filtered` | trace | NEW row, **pass** (passes on master too: it guards the draw()-of-filtered path) |
| `avm2/bitmapdata_applyfilter_destpoint_edges` | pixel | stays **pass**; outliers 0 → ~3, max 1 → 2 (limit 35). If CI's lavapipe differs from local, any count ≤ 35 is the same verdict. |
| `avm2/bitmapdata_applyfilter_blur` | pixel | unchanged: fail, 47 515, max 238 (now image-axis dispositioned with an explicit scope) |
| everything else | both | no movement |

Mode parity: no `#ifdef NO_GRAPHICS` arm is touched, and the three fixtures pass in no-graphics too, so the graphics
leg is enough per policy.

**AVM1 note for the sibling `w2b-avm1-applyfilter-flash`.** `avm1_filter_kernels.c` re-compiles this kernel block, so
on AVM1 `BitmapData.applyFilter` the new Glow / DS / Bevel composites and the opaque-target composite apply too.
- AVM1 has no #2077 throw, so glow-likes reach `fb_write_grid`'s opaque branch.
- `avm1_applyfilter_kernels` and `avm1_applyfilter_convolution_not_cm` pass in both legs.
- I did NOT wire the gradient kinds into the AVM1 bridge: `avm1_filter_kernels.c` is the sibling's file, and
  `Avm1FilterKernelParams` has no gradient fields. The route is to copy `grad_count/colors/alphas/ratios` into the
  `Avm2FilterVal` and send kinds 7 and 8 to `fb_apply_grown`.

## Task 3: GPU display-filter growth (evidence for the NO-GO)

- Both display paths already grow by `PASS_SCALES[q-1]·blur` per side, ruffle's `calculate_dest_rect`. Flash's
  applyFilter growth is half that, `ceil(sc·blur/2)`.
- On a display object the padding is transparent. A different growth is therefore visible only as (a) a CLIP of a tail
  that reaches past the smaller rect, or (b) the `draw_offset` rounding tie, which `visual/filters/blur_size_grows`
  pins to ruffle's rule and which passes.
- `visual/filters/blur_pass_scaling`: its content is centred (blob x=45..55 of 80), so neither rule clips anything.
  Golden row1 == row3 and row2 == row4 (applyFilter == display), and ours is identical: 0 px > 2 between the rows, and
  the test passes at max 2.
- `visual/filters/glow_pass_scaling` (strength 100, so any blur level ≥ 2 saturates):
  - The visible tail is 3, 6, 8, 9 … 14 px for q = 1..9, against Flash's applyFilter growth of 4, 8, 10 … 16. Neither
    rule clips.
  - Golden == ours at max diff 0.
- A clip needs a tail of floored blur level ≥ 1 beyond `ceil(sc·b/2)`. That is roughly q = 7..10 with a large blur and
  a saturating strength. Our own display glow has a shorter tail than that: it uses ruffle's scaled-pass kernel, with a
  tail of 130..155 px for blur 80 at q = 6..12, against the 152..240 clip. So even our own render cannot show it.
- The probe `avm1_display_glow_growth_probe` (LOCAL ORACLE REQUEST 1) measures Flash's own display tail and any clip
  directly.

## Refutations / premise checks

- "No linear rounding fits the inner composite" (prior report) was right for the PREMULTIPLIED value. The fit is in
  straight space, with Flash's own unmultiply of the source.
- "GPU growth probably applies to display filters too": the display path already uses `PASS_SCALES`. The open question
  is only ruffle's ×1 versus Flash-applyFilter's ×½, and the corpus cannot see it (task 3).
- `blur_pass_scaling` "golden == applyFilter cells" is true, but its blob never reaches a cell edge, so it is no
  growth oracle.
- Brief task 5 said "~200 lines". The dead block was ~480 lines, because `bd_displace_source_region` sits inside it. It
  stays; ~350 lines were deleted.

## New unclaimed leads

- **AVM1 bridge gradients** (sibling-owned file; route above): the AVM2 gradient kernels are Flash-exact on the probe.
- **draw() of gradient-filtered objects:** `bd_filter_is_cpu_drawable` still excludes kinds 7 and 8. `fb_glowlike_region`
  now handles them, so adding them there is one line, but no Flash row covers draw() + gradient. Add a case to
  `draw_filtered`'s generator and request a Flash trace.
- **Display-object Glow/DS/Bevel CPU parity:** the GPU glow shader still uses ruffle's float composite. The integer
  straight-lerp model here is Flash's for applyFilter. Whether Flash's display filters share it needs a Flash image:
  an inner-glow sprite at strength 2.

## LOCAL ORACLE REQUESTS

1. **FLASH image: `session27-fanout-reports/w2b-filter-kernels-residual-fixtures/avm1_display_glow_growth_probe`.**
   - Setup: 1 frame, `run_image.py --screen`, 600×240 stage.
   - Content: seven 20×20 black squares, each with a horizontal display GlowFilter (red, blurX 80, strength 255,
     q = 6..12, one per row at y = 10 + 32k).
   - Compare per row: the x-extent of the red run against the square at x = 290..309.
   - If a row's tail stops at `ceil(PASS_SCALES[q-1]·40)` = 152 / 160 / 168 / 176 / 184 / 200 / 240, Flash clips
     display filters at the applyFilter growth. That is a GO for the display rule, owner `tag.c` /
     `avm2_display.c` `*_filter_draw_offset_px` and the cache-rect sizing.
   - A longer, smooth tail refutes the rule.
   - The tail length itself (ours is 130..155) also says whether Flash's display blur is the q-box-pass kernel or
     ruffle's scaled-pass one.
2. **FLASH trace (design only, cheap): bevel sample isolation.**
   - Fixture: a GradientBevel whose table is the identity on alpha (one colour, alphas 0→1 over ratios 0→255; with
     `full` + knockout the bare entry is written, so `getPixel32`'s alpha reads the index ≈ `128 + (b_l − b_r)·st/2`).
   - Source: a linear alpha ramp (0..255 over 64 px).
   - Sweep: distance 1..4 at angles 0, 90, 45, 200, strength 2.
   - This gives Flash's `b_l − b_r` per pixel directly and settles the last 7 bevel px. Build it from
     `regression/avm2_applyfilter_gradient_opaque/create_test_swf.py`.
3. **FLASH trace: `session27-fanout-reports/w2b-filter-kernels-residual-fixtures/avm2_applyfilter_opaque_target_probe`**
   (1 frame, `run_trace.py`).
   - Content: Blur onto opaque targets of white, 0x336699, black and 0xFF8000, plus ColorMatrix (alpha ×0.5) and
     Convolution (/2) onto 0x336699. Rows y = 6 and 10.
   - Decides "over the destination" (what the patch does) vs "over white" for the opaque-target composite, and whether
     the CM / convolution copy arms composite too (today they keep the RGB premultiplied, ruffle's rule).
