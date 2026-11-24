# s27 wave 2: `w2-flash-filter-kernels`: AVM2 applyFilter kernels and draw() of filtered sources, fitted to FLASH

Branch `fanout/w2-flash-filter-kernels`. Patch: `w2-flash-filter-kernels.patch` (=`git diff origin/master --binary --
SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt
ruffle-tests/tests/swfs/regression/avm2_applyfilter_glow_kernels ruffle-tests/tests/swfs/regression/avm2_bitmapdata_draw_filtered`,
checked with `git apply --check -R`). Base: `origin/master` `53540ff0`. Upstream Ruffle tests were downloaded
(`download_tests.sh avm2 visual`) at upstream `1e604fa87`.

## NEW files

- `ruffle-tests/tests/swfs/regression/avm2_applyfilter_glow_kernels/{create_test_swf.py,test.swf,test.toml,output.txt}`
  (`output.txt` = the Flash capture, byte-exact)
- `ruffle-tests/tests/swfs/regression/avm2_bitmapdata_draw_filtered/{create_test_swf.py,test.swf,test.toml,output.txt}`
  (`output.txt` = the Flash capture, byte-exact)
- `SWFRecompDocs/plans/session27-fanout-reports/w2-flash-filter-kernels-fixtures/avm2_applyfilter_gradient_opaque_probe/`
  (a Flash ORACLE PROBE, not landed; `output.txt` is ours and provisional)
- this report and `w2-flash-filter-kernels.patch`

Modified: `SWFModernRuntime/src/avm2/avm2_bitmap.c` (functions below) and `ruffle-tests/render_canary_tests.txt`
(one member appended at EOF).

## Verdicts

| item | verdict |
|---|---|
| 1. Glow/DropShadow/Bevel kernels fitted to Flash | **GO (partial).** `glow_kernels` goes from 8/23 to **16/23** Flash lines exact. The two glow rows that were off, and all the outer-glow and opaque/Error rows, are now exact. The 7 remaining rows are off by 1-2 premultiplied levels on single channels (16 px in total; it was 44 px plus the 3-line tail). |
| 1b. NEW: Error #2077 | **GO.** Flash throws `Error #2077` for Glow, DropShadow and Bevel onto an OPAQUE target. We now throw it too, and the 3-line tail matches Flash exactly, stack lines included. |
| 2. draw() of a filtered source on the `fb_*` Flash model | **GO.** `draw_filtered` goes from 3/13 to **11/13** lines exact: blur, glow, dropshadow (the shorter tail) and convolution (`ffff0000` over 9..20) are all exact. The two bevel lines are off by one level at index 16. |
| 3. GradientGlow / GradientBevel | **HOLD.** No Flash row covers them. I built a probe SWF and put it under LOCAL ORACLE REQUESTS. The kernels are unchanged (they still pass the source through). |
| 4. Land both fixtures with output.txt = Flash | **DONE.** Both are landed with the exact Flash capture, so **both fail locally (output_mismatch)** on the residual rows listed below. They are new failing rows by design, not regressions. If the coordinator wants `regression/` kept 100% green, hold the two dirs back and land only the source. |
| 5. Sweep | **Clean.** 21 neighbour rows (trace and pixel) show identical verdicts and outlier counts. Render canary: **110/111 comparisons md5-identical**. The one DIFFERS is `avm2/bitmapdata_applyfilter_blur`, which is in the ledger. |
| 5b. NEW: Flash blur output growth | **GO.** On the `bitmapdata_applyfilter_blur` Flash PNG, every non-text cell now matches **to max diff 1 (0 px > 1)**. It was 3,039 px off; Ruffle's golden is 35,048 px off. |

**Priced flips:** none on the CI board. No baseline-failing row flips to pass:
- `bitmapdata_applyfilter_blur` stays `fail` on its Ruffle golden (39,351 → 47,515 outliers), but it is now Flash-exact outside the text band.
- `blur_quality` is unchanged.

The yield is Flash fidelity: 2 Flash fixtures land, and the blur growth rule is confirmed against Flash.

## Mechanism (all in `SWFModernRuntime/src/avm2/avm2_bitmap.c`)

Functions touched:
- `fb_reach`: new growth rule.
- `fb_blur_window` → `fb_blur_window_ex`, with an `invert` flag and a thin `fb_blur_window` wrapper.
- `fb_alpha_level` (new, split out of `fb_alpha_at`).
- `fb_mul8` and `fb_glow_pixel` (new).
- `fb_glowlike_region`: the glow/DS branch, plus the inverted window for inner glows.
- `bd_apply_filter`: the #2077 throw.
- `bd_draw_cm_filtered`: switched to `fb_*`.
- `bd_layer_bounds` (new).
- `bd_glowlike_source_region`: now unreached, marked `__attribute__((unused))`. It is kept as the Ruffle reference; its decl comment says so.

No sibling-owned function is touched: not `bd_draw_shape_walk`, not `text_raster_core`, not the AVM1 arm.

1. **Outer glow / DropShadow amount** = `floor(min(255, level × strength) × alpha)`.
   - `level` is the floored bilinear blur sample.
   - `alpha` is unquantised. It is recovered as `(byte+1)/256`, which gives 0.5 and 0.75 back exactly.
   - The colour and the composite are 8-bit multiplies `(x·a+127)/255` on the premultiplied source. Inner is source-atop; outer composites under the source.
   - This made `glow quality3 alpha.5` exact: `24 × 1.5 × 0.5 = 12`, where the old float path gave `11.95 → 11`.
2. **Inner Glow / DropShadow** reads the blur of the INVERTED alpha: 255 − a, with 255 outside the bitmap, floored per pass. It does not read `1 − blur(a)`.
   - Proof: the green of `glow inner` y=10 is exactly `2 × blur(255−a)` (0x5c, 0x2e).
   - Effect: inner rows went from 30 px off to 7.
3. **#2077**: Glow, DropShadow or Bevel onto `!dst->transparency` releases the filter and throws `Error #2077: This filter operation cannot be performed with the specified input parameters.` The target is untouched.
   - The printed tail is byte-identical to Flash: `Error: Error #2077: …` / `\tat flash.display::BitmapData/applyFilter()` / `\tat global$init()`.
   - The exact rule (which filters, whether an opaque *source* matters) is in the probe below. I implemented the conservative evidenced set.
4. **Growth rule** (`fb_reach`): each side grows by `ceil(PASS_SCALES[q-1] × blur / 2)`. `PASS_SCALES` is Ruffle's display-object table in `swf/src/types/blur_filter.rs`. The old rule was the pass reach `q·(m+1)`.
   - Measured on the `bitmapdata_applyfilter_blur` Flash capture, whose source is coloured to its edge, so the grown band holds real blurred pixels:

     | filter | Flash growth | old `q·(m+1)` | new rule |
     |---|---|---|---|
     | (4,4,1) | 2 | 2 | 2 |
     | (3,3,4) | 5 | 4 | 5 |
     | (5,5,3) | 7 | 6 | 7 |
     | (1,10,1), x | 1 | 0 | 1 |
     | (10,1,15), y | 4 | 0 | 4 |

   - The pass reach still sizes the input margin.
   - Every s26 fixture where the two rules agree is unchanged: `destpoint_edges`, `filter_sourcerect`, `blur_fractional`, `glow_kernels`.
5. **draw()**: `bd_draw_cm_filtered` now runs `fb_blur_region`, `fb_glowlike_region` and `bd_convolve_source_region(grow=1)` over the drawn object's own pixel bounds (`bd_layer_bounds`, the layer's alpha bbox). It writes the grown grid back into the cleared layer.
   - Clamped convolution therefore replicates the object edge and grows by 1 px. That is Flash's `ffff0000` over 9..20.
   - The DS tail is the `fb_*` Flash tail.

## Per-test before → after (clean `origin/master` vs patch, same box, `--mode=graphics`; no-graphics output byte-identical)

`avm2_applyfilter_glow_kernels` (px off out of 20 per row, vs Flash):

| row | before | after | residual (x: ours/Flash) |
|---|---|---|---|
| glow default y=6 / y=10 | 0 / 0 | 0 / 0 | exact |
| glow inner y=6 | 6 | 4 | 7:9905f117/9903f117 8:9907ee1c/9907ec1c 11, 12 (mirror) |
| glow inner y=10 | 8 | 2 | 7, 12: 9919b579/9917b579 |
| glow knockout y=6 / y=10 | 0 / 0 | 0 / 0 | exact |
| glow quality3 alpha.5 y=6 / y=10 | 4 / 2 | **0 / 0** | exact |
| dropshadow default y=6 | 1 | 1 | 9: a23160f0/a13161f2 |
| dropshadow default y=10 | 0 | 0 | exact |
| dropshadow hideObject y=6 / y=10 | 0 / 0 | 0 / 0 | exact |
| dropshadow inner y=6 | 10 | 2 | 11: 990a122f/9908122f, 13: 99030812/99030712 |
| dropshadow inner y=10 | 6 | 1 | 6: 99284dc1/99264dc1 |
| bevel default y=6 / y=10 | 2 / 2 | 2 / 2 | ±1 premul level (g / r) |
| bevel outer y=6 / y=10 | 1 / 0 | 1 / 0 | 6: e07496ff/e17597ff |
| bevel full knockout y=6 / y=10 | 1 / 1 | 1 / 1 | 9: 33/32 alpha; 10: 42/40 alpha |
| glow to opaque (2 rows + `done`) | 3 lines off | **exact** (the #2077 tail) | |

Totals: 8/23 → 16/23 lines exact. Note that the s26 provisional `output.txt` was already stale against master: master had 8 exact lines, not 1.

`avm2_bitmapdata_draw_filtered`: 3/13 → **11/13** lines exact.
- blur y/x: 14/10 px off → 0
- glow: 6/2 → 0
- dropshadow: 5/5 → 0
- convolution: 4/4 → 0
- bevel: 9/9 → 1/1 (index 16: ff980000 vs Flash ff970000)

**Rows that cannot be matched yet, and why.** Every residual is ours one premultiplied level high (two for bevel alpha) on a single channel.

- **Inner glow / inner DS.** The leftover is the source term `d·(255−ga)/255` on the red channel. At pixel (7,6), red needs `31·23/255 = 2.80 → 2` while blue needs `153·23/255 = 13.8 → 14`.
  - I proved that no linear rounding `(d·inv + c)/D` satisfies all four inner data points with `d_r = 31`.
  - `d_r = 31` is itself confirmed by Flash reading the source back as 0x34.
  - So Flash's inner composite is not a per-channel 8-bit multiply of the stored premultiplied value. The likely candidate is a straight-space lerp with its own re-premultiply, but I could not pin the rounding.
  - Tried and rejected: floor/round/ceil and ×256 variants, inverted-sample rounding, and straight-space floor+premul.
- **Bevel.** Tried and rejected:
  - integer composite;
  - a difference-before-floor;
  - inverted-blur highlight and shadow samples;
  - 1/16 to 1/65536 quantised bilinear weights;
  - shift-then-blur ordering (DS too: 4 → 23 px, so it is refuted).

  The float model stays the best fit.
- **DS default (9,6).** One alpha level. A bilinear with weights quantised to 1/256 fixes it, but it is not adopted because it does not help bevel. It belongs to the same family.

Completion mechanism: this needs a Flash probe that isolates the composite. Use a uniform source with a single known glow amount (blurX=blurY=0 or 1, strength 1..255 sweep) and trace each channel for a few alphas. That separates the `ga` quantisation from the composite rounding. The probe is cheap to build from `create_test_swf.py`; see LOCAL ORACLE REQUESTS.

## Sweep (before vs after, same box): 0 verdict changes

All rows were run with `--mode=graphics --verbose`. Verdict lines and outlier/max-diff numbers are identical in both legs except the one ledgered row.

- **avm2:**
  - `bitmapdata_applyfilter_destpoint` (0/0)
  - `_identity` (trace)
  - `bitmapdata_filter_sourcerect` (0, max 0)
  - `bitmapdata_applyfilter_colormatrix`
  - `bitmapdata_applyfilter_destpoint_edges` (0 outliers, limit 35)
  - `bitmapdata_applyfilter_blur` (fail, 39351 → **47515**, ledger)
  - `pixelbender_effect_glassDisplace_shaderfilter`
  - `filters_array_holes` (GradientGlow/GradientBevel trace)
  - `bitmapdata_draw_filters`
- **visual:**
  - `filters/blur_pass_scaling`
  - `filters/blur_quality` (fail, 205332 both legs)
  - `filters/blur_fractional` (0)
  - `filters/displacement_map_through_applyFilter`
  - `filters/displacement_map`
  - `cache_as_bitmap/bitmap_changed` (3 cmps)
- **regression:**
  - `avm1_applyfilter_convolution_not_cm`
  - `avm1_dynclip_color_transform`
  - `avm1_nested_po3_filters`
  - `avm1_runtime_filters`
  - `avm1_runtime_filters_cm_bitmap`
  - `avm2_bitmapdata_draw_textfield` (all pass in both legs)
  - the two new fixtures (fail → fail, residuals above)

Fidelity: the local before-render of `bitmapdata_applyfilter_blur` gives exactly CI's baseline 39,351 outliers (`s27-baseline-pixel-failing.txt`), so local grading is CI-grade for that row.

Render canary (`render_canary.py run --stash avm2_bitmap.c`): 88 tests / 111 comparisons, covering every `avm2/` and `visual/` member of `render_canary_tests.txt` (these include the GPU-filter rows `glow_pass_scaling`, `displacement_map_through_applyFilter`, `bitmapdata_draw_filters` and `destpoint_edges`) plus `bitmapdata_applyfilter_blur`.
- **IDENTICAL 110, DIFFERS 1** (`bitmapdata_applyfilter_blur`, fail → fail, bbox (0,220)-(440,652) = exactly the 4 grown cells).
- No trace or image status changes.
- I did not run the AVM1/gnash/shumway canary members: no change here reaches them. The GPU filter passes in `render_webgpu.c` are untouched, and nothing else calls the functions edited.
- I appended `avm2/bitmapdata_applyfilter_blur` at EOF; the standing set could not see the growth change.

## EXPECTED-FLIP LEDGER (for the coordinator's CI read)

| test | axis | expected on CI |
|---|---|---|
| `regression/avm2_applyfilter_glow_kernels` | trace | NEW row, **fail (output_mismatch)**, 7 of 23 lines differ (listed above) |
| `regression/avm2_bitmapdata_draw_filtered` | trace | NEW row, **fail (output_mismatch)**, 2 of 13 lines differ (bevel) |
| `avm2/bitmapdata_applyfilter_blur` | pixel | stays fail: outliers 39,351 → ~47,515, max 238 unchanged (golden is Ruffle; ours is now Flash-exact outside the text band) |
| `avm2/bitmapdata_applyfilter_blur` | trace | stays pass |
| everything else | both | no movement |

Both modes: the change is in shared `avm2_bitmap.c`, but outside the `#ifdef NO_GRAPHICS` arms. The no-graphics output of both fixtures is byte-identical to graphics, so the graphics-only leg is enough per policy.

## Refutations / premise checks

- The brief's "22 of 23 rows differ" is measured against the s26 provisional `output.txt`. Current master already had 8/23 lines right, because s26's `6a6699c55` edge growth landed after the provisional was written. The real gap was 44 px plus the tail.
- **"Flash draw() applies the source filters": confirmed**, and with the same `fb_*` kernels as applyFilter. That includes the grown rect, so draw() of a glow/DS spills outside the object, exactly as Flash's rows show.
- The convolution edge `ffff0000` is not a different kernel. It is the filter running over the *object's* bounds with `clamp=true`: the edge is replicated, then grown by 1. Our old layer-wide convolution saw transparent neighbours, which gave `aa`.
- `glow to opaque` is not a kernel row at all: it is a throw. The provisional (and Ruffle) wrote pixels there.

## New unclaimed leads

- **Disposition for `avm2/bitmapdata_applyfilter_blur`.** Our render now equals Flash outside the text band. That band uses Flash's device serif and can never match. This is an RvF / accepted-diff candidate: swap the golden for Flash's with a text-band mask, or record it in the avm2 dispositions.
- The `PASS_SCALES` growth rule probably also applies to display-object filters in `render_webgpu.c` / `tag.c` (Ruffle uses this exact table there, without the /2). That is unmeasured here and out of my scope (GPU).
- `bd_glowlike_source_region` and `bd_blur_source_region` are now unreached. A later cleanup can delete them (~200 lines).

## LOCAL ORACLE REQUESTS

1. **FLASH: `session27-fanout-reports/w2-flash-filter-kernels-fixtures/avm2_applyfilter_gradient_opaque_probe`, trace, 1 frame** (`run_trace.py <dir>`; rebuild `test.swf` with `create_test_swf.py` if needed). Each case is in its own try/catch.
   - Lines 1-13 pin the #2077 rule: which filters throw onto an opaque target, and whether an opaque SOURCE matters. We throw for Glow/DS/Bevel only, so blur, gradient*, CM and convolution report `ok`.
   - The gradient rows trace GradientGlow (outer / inner / full+knockout) and GradientBevel (inner / outer / full+knockout) at y=6,10. We still pass the source through there.
   - Compare: the whole file. Its archive is the golden for the gradient kernels (task 3) and for widening or narrowing the #2077 set.
2. **FLASH (cheap, optional): composite-isolation probe.** Unblock the inner/bevel residual with a variant of `glow_kernels` that uses `GlowFilter(0x00FF00, 1, 1, 1, s, 1, true)` (inner, no blur), with s in {0.5, 1, 1.5, 2, 3} over a uniform 0x993366FF source. Trace the centre pixel. This yields `ga` directly, so the composite rounding can be solved. If wanted, I can build it from the existing generator; it was not built here.
