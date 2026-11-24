# s27 w2b-jpeg-refine: JPEG decode round 2 (Flash verdicts reconciled) + Flash mipmaps + GPU nearest ties-up

**New files**
- `SWFRecomp/src/jpeg_flash.cpp`, `SWFRecomp/include/jpeg_flash.hpp`: carried over unchanged from
  `w2-jpeg-flash-decode.patch`. That patch is not landed, so these files are new against master.
- `ruffle-tests/tests/swfs/regression/avm1_bitmap_nearest_tie_stage/`: `create_test_swf.py`, `test.swf`, `test.toml`,
  `output.txt`, `output.expected.png`. **The golden is Flash Player 32's own `draw()` capture.**
- `SWFRecompDocs/plans/session27-fanout-reports/w2b-jpeg-refine-report.md` (this file)
- `SWFRecompDocs/plans/session27-fanout-reports/w2b-jpeg-refine.patch`

**Patch scope** (`git diff origin/master -- …`; `git apply --check -R` passes on the branch):
- `SWFRecomp/`: the w2 decoder as-is. That is the 2 new files above plus `CMakeLists.txt`, `swf.cpp` and
  `abc_timeline.cpp`.
- `SWFModernRuntime/src/avm2/avm2_cpu_raster.c` (NEW in this round):
  - adds `cpu_bmp_mip_level` and `cpu_bmp_apply_mip`;
  - adds 2 trailing `RasterCtx` fields;
  - in `bmp_sample`, the mip branch uses truncating weights;
  - in `avm2_cpu_raster_shape`, the bitmap arm computes the Jacobian.
- `SWFModernRuntime/src/rendering/render_webgpu.c` (NEW in this round). These are fragment-WGSL changes only:
  - new functions `pool_texel`, `pool_dims`, `bitmap_nearest_repeat` and `bitmap_nearest_clamp`, plus the constant
    `NEAREST_TIE`;
  - `shade_main` sends 0x42 / 0x43 to these new functions;
  - `sample_bitmap` is unchanged.
- `ruffle-tests/render_canary_tests.txt`: the w2 member (bitmapdata-clone) plus a new member,
  `regression/avm1_bitmap_nearest_tie_stage`.
- The new regression fixture directory.
- Disposition docs that go with the flips:
  - `avm1/_investigation/ACCEPTED_DIFFS.md`: the w2 Cat. 9 `getpixel-from-embedded` entry, marked RESOLVED;
  - `from_shumway/ignored_tests.txt`: the w2 getpixel prune;
  - `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`: NEW `acid-color-0` image-axis entry;
  - `regression/README.md`: a new row for the fixture.
- `verify_output.py` is not touched: there is no new runtime TU.

**Base and setup**
- Base: `origin/master` `d888d800`.
- Upstream tests: downloaded at Ruffle `1e604fa87` (from_gnash, from_shumway, avm2, avm1, visual, fonts, text).
- SETUP_STATUS: all OK. Dawn runs on lavapipe.
- **Fidelity check:** my clean-master render of `from_shumway/bitmapbuttons` (md5 `4349a280`) is byte-identical to CI's
  failing actual on `origin/ruffle-image-results` (`db74e661`). So local grading is CI-grade.

## Verdicts

**GO on all three items.**

| # | Item | Verdict |
|---|---|---|
| 1 | `BitmapDataDraw` FP32 = `0x014400` | **REFUTES "the decoder model needs refinement"** (premise attacked). The IJG-v7+ decode stays as it is. The FP15 / FP32 value comes from **Flash's mipmapping of a minified smoothed bitmap fill in `draw()`**: a 2×2 box level whose texels are each the TRUNCATED mean of 4, sampled with truncating bilinear weights. Implemented in the CPU `draw()` rasterizer. The row stays **pass** (the w2 patch alone took it to `ruffle_matched`). |
| 2 | `acid-color-0` vs Flash 32 | Ours is **closer to Flash than the Ruffle golden** on the decode-affected pixels. It is a priced Flash-over-Ruffle loss, and the RvF entry is written with the `<!-- image-axis -->` marker. |
| 3 | On-stage nearest tie | **Settled → ties-up applied** to the GPU nearest sampler. The new fixture goes fail 52 → pass 0 against Flash's golden. The bias is 1e-5 texel, chosen by a sweep (§3). |

## EXPECTED-FLIP LEDGER (graphics, CI `graphics`/`all`; vs clean `origin/master`, same box)

| Row | Axis | `origin/master` (local) | With patch | Kind |
|---|---|---|---|---|
| `from_shumway/bitmapdata/getpixel-from-embedded` | trace | output_mismatch | **pass** | **GAIN**. Flash value `200d04`. The row is pruned from `from_shumway/ignored_tests.txt` (w2), so it also enters the filtered counts. |
| `from_gnash/misc-ming.all/BitmapDataDraw` | trace | pass | **pass** | Unchanged. The w2 patch's −1 strict is **eliminated** by the mip model, which makes line 284 `82944` = FP15 = FP32. |
| `regression/avm1_bitmap_nearest_tie_stage` | pixel | (new row) fail 52 ch, max 32 | **pass 0 / 0** | **NEW row, GAIN.** Flash golden. CI books it as a new passing row (absent before). |
| `from_shumway/acid/acid-color-0` | pixel | pass 3/3 | **fail 1138/3** | **Priced LOSS (Flash over Ruffle)**: Ruffle-made golden, RvF entry written. The CI baseline graded this row fail 308 at `d70f2c0aa`, so on CI it may read fail→fail. |
| `avm2/pixelbender_dithering` | pixel | pass 9413 / 32500 | pass **27** | Headroom (Flash golden) |
| `from_shumway/avm2/flash/display/bitmapdata/bitmapdata-clone` | pixel | pass, max 77 = tol | pass, **max 0** | Headroom (Flash golden) |
| `from_shumway/bitmapbuttons` | pixel | fail 52 / 0, max 11 | fail **39** / 0, max 9 | Closer to the golden, no flip |
| `from_shumway/acid/acid-bitmap-fill` | pixel | pass 242 / 300 | pass 245 / 300 | md5 moves |
| `from_shumway/acid/acid-bitmap-fill-2` | pixel | pass, max 30 | pass, **max 0** | md5 moves |
| `from_shumway/acid/acid-blend` | pixel | pass 5 / 348 | pass 4 / 348 | md5 moves (decoder). The tie bias leaves it alone (§3). |
| `from_shumway/acid/acid-blend-2` (output.10/15/20/26/40) | pixel | pass 0 / 0, max 128/131/126/111/150 | pass 0 / 0, max 128/131/127/112/151 | md5 moves |
| `from_shumway/acid/acid-big` | pixel | pass 0 / 20, max 50 | pass 0 / 20, max 49 | md5 moves (decoder + tie, §3) |
| `from_shumway/acid/acid-large` | pixel | pass, max 3 (tol 11) | pass, max 8 | md5 moves |
| `avm2/stage3d_texture` | pixel | pass 2 / 117, max 15 | same numbers | md5 moves |
| `regression/avm1_jpeg3_alpha_bitmap` | pixel | pass, max 1 (tol 3) | pass, max 2 | md5 moves |

- Net, strict:
  - trace: +1 (getpixel);
  - pixel: +1 new row (fixture), −1 (acid-color-0);
  - every Flash-golden row improves or holds.
- The w2 numbers reproduce exactly: every decoder-only md5 above equals the w2 report's.
- **No-graphics leg (mode parity):** `BitmapDataDraw` pass, `getpixel-from-embedded` pass, both with `--recompile`.
  - The mip code is in `avm2_cpu_raster.c`, which both modes compile.
  - The WGSL change is graphics-only.

## 1. `BitmapDataDraw`: the decoder is right, Flash mipmaps (brief item 1)

**The image.** It is a DefineBitsJPEG2:
- no JFIF APP0;
- quality 100 (all-ones DQT);
- 170×170, 4:2:0, optimised Huffman tables.

`mc4` draws it through a 0x40 (repeating, smoothed) fill under the placement matrix a=0.75, b=−0.2, c=0.3, d=0.35,
tx=20, ty=30 px. `getPixel(65,36)` maps to texel (43.33, 43.33), which falls in the dark band. There, the IJG-v7+
decode rings (`004800 / 004400 / 024401 / 074006 …`), while stb and turbo are flat (`014400`).

**Candidates measured at that probe** (Python model on the decoded planes; ours = the CPU `draw()` rasterizer):

| Decode | Sampling | Result | Matches |
|---|---|---|---|
| IJG v7+ (patch) | bilinear, rounded (our draw path) | `014700` = 83712 | ours with the w2 patch: exactly what our runtime printed. The geometry is confirmed. |
| IJG v7+ | bilinear truncated / nearest, every pixel/texel-centre convention | `004600`, `024300`, `044202`, `004800` … | none |
| stb / turbo (flat) | anything | `014400` | FP15 / FP32 |
| **IJG v7+** | **mip level 1 (2×2 box, truncating) + bilinear truncating** | **`014400`** | **FP15 / FP32** |
| IJG v7+ | mip level 1, nearest | `024401` | **FP11** (its golden value) |
| IJG v7+ | mip 1 box trunc + bilinear rounded, or box rounded + any | `024401` / `034402` | — |

**Why mipmapping, not a decoder switch.**
- A different decoder for this image would need a discriminator that spares `getpixel-from-embedded`. That row is
  JPEG2 too, with JFIF; its SWF is version 17, so its golden is FP ≥ 11.4. The IJG model matches it with `200d04`.
  That rules out "JPEG2 vs JPEG3" as the switch. The remaining switch candidates (JFIF absent, q100, SWF 8) have no
  mechanism behind them.
- Flash Player is documented to mipmap smoothed bitmaps drawn below 100 %, and only while the dimensions are even:
  170 → 85 (odd), so exactly one level.
- The model reproduces FP32, and its nearest variant reproduces FP11's golden value too.
- It cannot touch `bitmapdata-clone` or `pixelbender_dithering`: both are drawn at ≥ 1:1, so no mip applies.
- Verdict: the decoder needs no change. The w2 decode is kept bit-for-bit.

**Implementation** (`avm2_cpu_raster.c`, CPU `draw()` rasterizer, shared by AVM1 `bd1_draw_timeline_entry`, AVM2
`bd_draw_shape_walk` and the headless dump):
- **Level.** Level = ⌊log2(max texels per device pixel)⌋, the GPU LOD rule, while both dimensions stay even.
  - The Jacobian is B·20·W⁻¹ (bitmap ← shape twips, shape ← device).
  - Here the axes are 1.25 and 2.5 texels/px, so level 1.
- **Levels.** Each level is the truncated 2×2 mean per straight-RGBA channel. Levels are cached: 8 slots, keyed by
  source pointer, size and level.
- **Sampling.** Bilinear on the level with truncation, only on the mip path. Full-resolution bilinear keeps its
  rounding.
- **Scope.** Smoothed fills (0x40 / 0x41) only, minified by ≥ 2×. Untested assumption: translucent bitmaps are
  averaged straight, not premultiplied; no row exercises it.
- **Blast radius, measured.** The 13 draw-heavy rows of the sweep (§4: every SWF with `draw` + a bitmap character)
  and the whole canary are md5-identical with and without it. Only `BitmapDataDraw` moves.

## 2. `acid-color-0` vs Flash 32 (brief item 2)

**The footprint.** The JPEG3 is 500×500, 4:2:0, with alpha. It is minified into x 8–249 / y 388–498 at quality LOW,
so it is unsmoothed. Most of the footprint gap to Flash is therefore texel choice, not decode: max 186 in both legs.

**Note on the brief's premise.** The brief says "screen == draw()". `flash.png` vs `flash.screen.png` differ on
357 383 RGB pixels in the whole frame, so I used `flash.png` (the draw() capture) as named.

| vs `flash.png`, footprint | px > 3 | px ≠ | mean \|Δ\| |
|---|---|---|---|
| Ruffle golden | 2963 | 18140 | 1.351 |
| ours, master (stb) | 2967 | 18943 | 1.388 |
| **ours, patch** | **2887** | **17957** | **1.338** |

**Decisive subset:** the 15 836 pixels where master and patch differ.

| | closer to Flash | exact = Flash | Σ\|RGB − Flash\| |
|---|---|---|---|
| master (≈ golden) | 3 300 | 992 | 89 326 |
| **patch** | **5 441** | **1 978** | **85 251** |

The remaining 7 095 pixels tie.

**Disposition:** RvF entry "JPEG chroma upsampling: Flash's IJG-v7+ DCT-scaled decode vs Ruffle's triangle filter"
with `<!-- image-axis: from_shumway/acid/acid-color-0 output -->`. It is not added to an ignore list.

**Prune criterion:** a Flash-made golden. The whole-frame capture still differs from our render (18 634 px > 3)
outside the JPEG, so it cannot simply replace the golden.

## 3. On-stage nearest tie → ties-up on the GPU (brief item 3)

**Judgement: settled.**
- Flash's `draw()` capture runs through Flash's own software rasterizer, the one the projector stage uses outside GPU
  mode. It equals `predict_ties_up.png` at 0 px; ties-down is 80 px away.
- The `--screen` capture is misaligned for this fixture (1535 px off every candidate), so I did not use it, as the
  brief says.
- The rule matches the CPU nearest sampler, which already uses ties-up against the Flash golden of
  `pixelbender_dithering`.

**Change (`render_webgpu.c`).**
- 0x43: `textureLoad(clamp(floor(uv·dim + NEAREST_TIE)))`. The clamp mimics the Nearest sampler's clamp-to-edge.
- 0x42: `floor(xy·bd + NEAREST_TIE) mod bd`, with bd the bitmap size in texels.
- Both cover all 12 pools.
- Smoothed fills keep `sample_bitmap`.

**Bias sweep** (the moved pixel set grows monotonically with the bias):

| `NEAREST_TIE` | fixture vs Flash | `acid-blend` (0x43, Ruffle golden) | `acid-big` | others (39-row sweep + 154-test canary) |
|---|---|---|---|---|
| 0 | fail 52 (≡ hardware: md5-identical on acid-blend and acid-big) | 4 / 348 | = | = |
| **1e-5 (chosen)** | **pass 0** | **4 / 348, md5 =** | md5 moves, stats = (0 / 20, max 49) | = (subset of the 1e-3 run, which moved nothing else) |
| 1e-4 | pass 0 | 4 / 348, md5 = | md5 moves | = |
| 1e-3 | pass 0 | **275 / 348, max 47**: 7 periodic NEAR-tie columns (170, 201, 232, 263, 294, 325 + 260) | md5 moves | **=** (canary: only the fixture moved) |

Why 1e-5:
- It is the smallest bias that settles the measured tie.
- Larger biases also capture near-ties in acid-blend, where Flash's behaviour is unmeasured. acid-blend has a Ruffle
  golden and was "tuned once" (see the `bitmap_samp_linear` comment).
- acid-big's moves at every bias are consistent with exact ties under interpolation noise, but it has no Flash datum.
  Its stats do not move.

## 4. Sweep and canary

**Sweep.** 39 rows, graphics, `--recompile`, clean master vs patch, same box:
- every DefineBits* row of the w2 static scan (26);
- the 13 rows of a fresh scan for `draw` + any bitmap character: `avm1/netstream_play_flv_screen`,
  `avm2/bitmapdata_colortransform`, `bitmapdata_draw`, `bitmapdata_drawwithquality`, `graphics_bitmap_fill`,
  `graphics_bitmaps`, `stage3d_bitmap`, `visual/blend_modes/shader_as_mask`, `cache_as_bitmap/cab_mask_alpha`,
  `cab_mask_triangle`, and the regression rows `avm2_bitmapdata_draw_textfield`, `avm1_runtime_filters_cm_bitmap`,
  `avm1_parent_child_bitmap`;
- plus `avm1_parent_child_bitmap_fill` and `bitmap_pool_layer_cap`.

Results:
- Everything outside the ledger is status- and md5-identical.
- `avm2/bitmapdata_draw` fails at 753 / 600 in both legs: a baseline fail.
- `LoadBitmapTest`, `loadMovieTest` and `loader-events` are `ruffle_matched` in both legs.

**Render canary** (`render_canary.py`, 154 tests incl. the 2 new members, 219 PNGs):
- before = clean master; after = full patch (with the tie bias at 1e-3, a superset of the final 1e-5 moves).
- **199 identical, 14 differ.**
  - The 14 are exactly the 13 decoder-row PNGs (dithering, stage3d_texture, acid-bitmap-fill, acid-bitmap-fill-2,
    acid-blend-2 ×5, acid-color-0, bitmapdata-clone, bitmapbuttons, avm1_jpeg3_alpha_bitmap) plus the new tie fixture
    (fail → pass).
  - The 5 fonts/text members were captured separately in both legs after a late download: identical.
  - No trace status moved.

**Regression suite:**
- `avm1_jpeg3_alpha_bitmap`, `avm1_parent_child_bitmap_fill`, `bitmap_pool_layer_cap`, `avm1_runtime_filters_cm_bitmap`,
  `avm2_bitmapdata_draw_textfield`, `avm1_parent_child_bitmap`: all pass in both legs.
- The new `avm1_bitmap_nearest_tie_stage` passes with the patch and fails on master.
- The mip model has no new fixture. Its oracle is the corpus row `BitmapDataDraw`, whose FP15 golden = FP32
  (`flash.fp32.txt`, byte-identical on the graded lines).

## Not finished

- **WASM compile of the recompiler and runtime: unverifiable in the cloud** (no emsdk). The C, C++ and WGSL are
  portable; the WGSL compiled on Dawn/lavapipe. **Completion mechanism:** the coordinator's `deploy-pages.yml -f dry_run=true`.
- **Mip on the GPU stage.** Flash presumably mipmaps on stage too (smoothed bitmaps drawn minified). The GPU
  `bitmap_samp_linear` samples only level 0. No Flash datum yet. **Completion mechanism:** a FLASH image of a
  minified smoothed bitmap fixture, then mip levels in the static pools. Price M.

## Refutations

1. **Brief premise "FP32's 82944 means the decoder model needs refinement for this image": REFUTED.** With the
   unchanged model, Flash's mipmap (box-truncating level 1 + truncating bilinear) gives exactly `014400`. The same
   mip with nearest sampling gives FP11's `024401`.
2. **"Different decoder for DefineBits vs DefineBitsJPEG3": refuted** by `getpixel-from-embedded` (JPEG2, SWF 17, the
   model gives the Flash value).
3. **"screen == draw()" for acid-color-0's two captures: not true at pixel level** (357 383 RGB px differ). The draw()
   capture was used.
4. **The prior worker's GPU fix sketch ("bias +1/256 texel"): too wide.** 1e-3 already moves acid-blend's
   near-tie columns by 271 outliers. 1e-5 suffices for the measured tie.

## New unclaimed leads

1. **GPU-stage mipmapping** for minified smoothed bitmaps (see Not finished). It might move Ruffle-golden rows the
   other way; it needs a Flash image first.
2. **Mip-chain depth > 1** is modelled (repeated halving while both dimensions are even) but unmeasured. A
   power-of-two bitmap drawn at ≤ 25 % in Flash would pin it.
3. The w2 leads still stand: runtime `loadClip` / `Loader` JPEG decode still uses stb; progressive JPEGs; JPEG4
   deblocking.

## LOCAL ORACLE REQUESTS

1. *(optional, pins lead 1/2)* **FLASH: a 256×256 lossless bitmap with distinct texels, 0x41 smoothed fill at scale
   0.3 on stage (`--screen`) and through `draw()`.** Compare to our CPU-mip model (`avm2_cpu_raster.c`) and to
   level-0 bilinear. I have not built the fixture. Whoever picks up the lead builds it with the same generator
   pattern as `regression/avm1_bitmap_nearest_tie_stage/create_test_swf.py`.
