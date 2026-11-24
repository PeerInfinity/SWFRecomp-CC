# s27 w2-jpeg-flash-decode: Flash-faithful JPEG decode

**New files**
- `SWFRecomp/src/jpeg_flash.cpp` (new TU, added to `SWFRecomp/CMakeLists.txt` `SOURCES`; the Emscripten recompiler
  build uses the same CMakeLists via `emcmake`, so no other build list needs it)
- `SWFRecomp/include/jpeg_flash.hpp`
- `SWFRecompDocs/plans/session27-fanout-reports/w2-jpeg-flash-decode-report.md` (this file)
- `SWFRecompDocs/plans/session27-fanout-reports/w2-jpeg-flash-decode.patch`
  - Scope: `SWFRecomp/` (2 new files plus `CMakeLists.txt`, `swf.cpp`, `abc_timeline.cpp`),
    `ruffle-tests/render_canary_tests.txt` (+1 member).
  - Also the two disposition files whose prune is part of the flip: `avm1/_investigation/ACCEPTED_DIFFS.md` (entry
    and summary row marked RESOLVED) and `from_shumway/ignored_tests.txt` (getpixel line removed).
  - `git apply --check -R` passes on the branch, and `git apply --check` passes on a clean `origin/master` worktree.
- `SWFRecompDocs/plans/session27-fanout-reports/w2-jpeg-flash-decode-fixtures/avm1_bitmap_nearest_tie_stage/`
  (`create_test_swf.py`, `test.swf`, `test.toml`, `output.txt`, `predict_ties_up.png`, `predict_ties_down.png`,
  `ours_graphics_lavapipe.png`). This is an oracle-request fixture, NOT a regression test, and it is not in the patch.

**Base**
- `origin/master` `53540ff02`. This includes the s27 wave-1 landings `d3b6d71b8`, `0494cd927`, `456fef1bf`,
  `202340a12`.
- CI results of record: `da51f878f` (graphics, code `d70f2c0aa`).
- Upstream tests: downloaded at `1e604fa87` (all categories except `from_avmplus`).
- Setup: SETUP_STATUS all OK; Dawn on lavapipe.

## Verdict: GO (measured), with two priced losses that each need one oracle run

**Flash's JPEG decoder is now known, and it is bit-exact.** Flash Player 32 decodes timeline JPEGs the way
**IJG libjpeg v7 / v8 / v9** does with its default settings:
- ISLOW integer IDCT;
- subsampled chroma upsampled by **DCT scaling**: a 16×16 / 16×8 / 8×16 IDCT of each 8×8 chroma block, not a
  pixel-domain filter;
- then a **truncating** YCbCr→RGB step: 16.16 fixed point, each product floored, and G subtracts two separately
  floored terms.

All three Flash data points in the corpus confirm it:

| Flash datum | stb_image (today) | libjpeg-turbo | IJG v7+ + truncating colour (this patch) |
|---|---|---|---|
| `bitmapdata-clone` logo vs the FLASH PNG, both logos incl. alpha edges | max 77, mean 2.27 | max 77 | **max 0, mean 0: bit-exact** (29 517 opaque channels + all edge pixels) |
| `pixelbender_dithering` (Python model of the row, Flash PNG) | 9 412 | 9 036 | **40** (real build: **27**) |
| `getpixel-from-embedded` `getPixel(100,100)` (Shumway trace = Flash) | `220a06` | `220a06` | **`200d04`** = Flash |

**Patch.**
- `decodeJpegRgb()` in the new `jpeg_flash.cpp` implements this pipeline. It replaces `stbi_load_from_memory` at the
  4 recompile-time JPEG sites: `swf.cpp` DefineBits, DefineBitsJPEG2, DefineBitsJPEG3/4; `abc_timeline.cpp`
  `decodeJpegCharacter`.
- It falls back to stb for anything it does not handle: progressive, arithmetic, 12-bit, CMYK, damaged entropy data.
- `SWFRECOMP_JPEG_DECODER=stb` forces the old path, as an A/B switch.
- No runtime (`SWFModernRuntime`) change. No new dependency: the 4 IDCT kernels are ported from IJG 9's
  `jidctint.c`, with attribution and the only edits documented in the file header.

**Priced ledger vs clean `origin/master` (same box, graphics):** trace +1 / −1 strict (effective ±0); pixel −1;
headroom up on both Flash-golden pixel rows. Details in the ledger below.

The two losses are a **Ruffle-made** golden and a **Flash-15** golden that disagrees with Flash 9/11 on the very line.
Both have one-shot oracle requests (§ LOCAL ORACLE REQUESTS). My recommendation:
- **Land if** the Flash-32 image of `acid-color-0` shows the DCT-ringing chroma, which I predict it does.
- **Otherwise HOLD.** The patch is self-contained and the A/B switch makes a later land trivial.

## EXPECTED-FLIP LEDGER (for the CI read)

Both axes, graphics, CI mode `graphics`/`all`. The change is recompiler-only, so no-graphics moves identically on the
trace axis (verified below).

| Row | Axis | `origin/master` (local) | With patch | CI baseline `da51f878f` | Kind |
|---|---|---|---|---|---|
| `from_shumway/bitmapdata/getpixel-from-embedded` | trace | output_mismatch | **pass** | output_mismatch | **GAIN.** Flash golden. The row was in `from_shumway/ignored_tests.txt` (ACCEPTED_DIFFS Cat. 9); **this patch prunes it** (its own prune criterion), so it also enters the filtered counts |
| `from_gnash/misc-ming.all/BitmapDataDraw` | trace | pass | **ruffle_matched** | pass | **LOSS** (strict pass −1, effective ±0). `known_failure = true`, so it counts as a regression under standing rule 3. See §3 |
| `from_shumway/acid/acid-color-0` | pixel | pass 3/3 | **fail 1138/3** | fail 308/3 (pre-`202340a12`) | **LOSS** against a fresh s27 wave-1 flip. The golden is Ruffle-made (`quality = "low"`). See §4 |
| `avm2/pixelbender_dithering` | pixel | pass 9 413 / 32 500 | pass **27** / 32 500 | pass 9 413 (after `d3b6d71b8`) | headroom ×1200 (Flash golden) |
| `from_shumway/avm2/flash/display/bitmapdata/bitmapdata-clone` | pixel | pass, max_diff 77 = tol 77 | pass, **max_diff 0** | pass 77 | headroom 0 → 77 (Flash golden) |
| `from_shumway/bitmapbuttons` | pixel | fail 52 | fail **39** | fail 52 | band improved, no flip |
| `from_shumway/acid/acid-bitmap-fill-2` | pixel | pass, max 30 | pass, **max 0** | pass 30 | md5 moves, status same |
| `from_shumway/acid/acid-big`, `acid-bitmap-fill`, `acid-blend`, `acid-blend-2` (5 imgs), `acid-large`, `avm2/stage3d_texture`, `regression/avm1_jpeg3_alpha_bitmap` | pixel | pass | pass | pass | md5 moves, status same (numbers below) |

Everything else in the corpus is unchanged by construction. The proof is §5 (static scan + generated-C identity).

## 1. How Flash's decoder was identified (brief item 1)

- **The two rows' JPEGs.** Both are DefineBitsJPEG3, baseline, 4:2:0:
  - dithering: 900×600 + an alpha plane;
  - clone: 128×128 + an alpha plane.
  I extracted them with a Python SWF walker.
- **Candidate decoders.** Each one decoded to RGB, then the row's math was rendered and scored against the Flash PNG:
  - stb (our build flags);
  - libjpeg-turbo 2.1 `-dct int|fast|float`, each with and without `-nosmooth`;
  - IJG v7 / v8d / v9 / v9e (built from ijg.org sources here).
- **How each row was scored.**
  - Clone: the logo sits 1:1 at (0,110) and (138,110). The composite is Flash's premultiplied clamp over white,
    masked off the overlay squares.
  - Dithering: the w1-drift model. Nearest sampling with ties up, plus the 4×4 threshold matrix recovered from our
    own output (the model reproduces our render to 1 channel).
- **Upsampling decides it.**
  - libjpeg-turbo/stb "fancy" triangle upsampling: clone max 77, mean 2.26.
  - Box (`-nosmooth`): max 72, mean 3.15. Worse.
  - A least-squares fit of Flash's chroma against the 4×4 chroma neighbourhood gives a **sharpening** kernel: centre
    0.84, near 0.20, far −0.13. That is a DCT-domain interpolator.
  - IJG v7+ upsamples 2× chroma by a scaled 16×16 IDCT (`jdmaster.c` `DCT_h_scaled_size`). libjpeg-turbo removed
    that.
  - IJG v7 = v8d = v9: identical output. Result: clone max **2**, mean 0.45; dithering 5 788.
- **Colour conversion.** Fitting Flash RGB to the IJG YCbCr gives standard coefficients but offsets of R −0.53,
  G +1.01, B −0.49, with G's residual rms 0.405 = √(2/12): two floor errors. Flooring each product separately
  (≥ 14-bit fixed point; the patch uses 16.16):
  - R = Y + ⌊1.402·Cr⌋;
  - G = Y − ⌊0.34414·Cb⌋ − ⌊0.71414·Cr⌋;
  - B = Y + ⌊1.772·Cb⌋.

  Result: **29 517 / 29 517 opaque clone channels exact**, both logos max_diff **0** (alpha edges included), dithering
  **40**, getpixel `200d04`.
- **IDCT method.** ISLOW, FLOAT and IFAST score the same or worse on every datum. ISLOW is IJG's default and is exact
  on clone.
- **JPEG4 deblocking.** Not measurable: no JPEG4 image row exists. The only JPEG4 is `avm1/clone_sprite_types`
  (trace-only, deblock = 0). The decoder ignores the deblock param, as before. Lead 4.

## 2. Implementation (`SWFRecomp/src/jpeg_flash.cpp`, ~1680 lines, ~1000 of them the IJG kernels)

- **Front end.** My own baseline / extended-sequential Huffman decoder:
  - DQT 8/16-bit, DHT, SOF0/1, DRI + RSTn, multi-scan sequential (non-interleaved scans), APP0 JFIF / APP14 Adobe
    colour-space rules (`jdapimin.c`);
  - premature end of data feeds zero bits (IJG behaviour).
- **Reconstruction.**
  - IJG 9's `jpeg_idct_islow`, `jpeg_idct_16x16`, `jpeg_idct_16x8` and `jpeg_idct_8x16`, plus
    `prepare_range_limit_table`, ported as-is.
  - Edits: left shifts of possibly negative values become multiplications by the same power of two (UB before
    C++20; identical results), and `ISLOW_MULT_TYPE` is int64.
  - DCT scaled sizes follow `jdmaster.c` exactly (at most 2×, axis ratio ≤ 2). Any remaining expansion is
    replication (`jdsample.c` `int_upsample`).
- **Colour.** Flash's truncating YCbCr→RGB. Grayscale is replicated, and RGB JPEGs (Adobe transform 0 / `'R','G','B'`
  ids) are copied.
- **Validation.**
  - **28 of 28 distinct corpus JPEGs** decode bit-identically to IJG 9 + the Flash colour step (`yccdec9` reference).
    They cover 4:4:4 with DRI, 4:2:0, a 1×1, and sizes up to 3612×2680.
  - The 2 progressive JPEGs (`visual/define_bits_jpeg2_huge`, trace-only) fall back to stb, which is unchanged
    behaviour.
  - Fuzz: 4 200 truncated / byte-mutated / bit-flipped streams under ASan + UBSan, with no findings. 2 516 decoded;
    1 684 returned nullptr and fell back to stb.
  - Builds with `-Wall -Wextra` clean.
  - No emsdk in the cloud, so the WASM recompiler was not compile-tested. The code is portable C++ (int64
    intermediates, no `long`, no SIMD); the deploy-pages dry run will confirm.

## 3. `BitmapDataDraw` (trace LOSS, oracle needed)

The graded file is `output.fp15.txt`. stb matched it exactly; the patch differs on one line:

```diff
- FAILED: expected: 17408 obtained: 82944 [BitmapDataDraw.c:284]
+ FAILED: expected: 17408 obtained: 83712 [BitmapDataDraw.c:284]
```

- The row draws `mc4`: a 0x40 smoothed repeating bitmap fill of a flat nested-green-band JPEG (4:2:0).
- `getPixel(65,36)` lands in the dark band. The Flash goldens disagree among themselves:
  - **FP9 and FP11 return `0x004400`.** That is the Flash-32 model's dominant flat value in that band (136 of 400
    px).
  - **FP15 returns `0x014400`.** That is stb's flat value.
- Under the new decode the band carries 16×16-IDCT chroma ringing (values `004400 / 024401 / 004700 / 004b00`). Our
  smoothed draw happens to sample a `004700` texel neighbourhood.
- So the line is either:
  - (a) Flash-version drift: FP15 used a different decoder than FP9/11/32; or
  - (b) a sub-texel sampling-position difference in our smoothed draw, exposed only now that the band is not flat.

**Completion:** the FLASH trace request below. Outcomes:
- **FP32 prints 83712:** exact. Disposition: Flash-version difference vs the fp15 golden (RUFFLE_VS_FLASH-style,
  trace axis).
- **FP32 prints 17408 / PASSED:** it is (b). That is a sampling-position lead in the AVM1 smoothed `draw()` path, not
  in the decoder.
- **FP32 prints 82944:** the FP15 behaviour holds in FP32 too. Then the decoder model needs refinement for flat
  regions; unlikely, given clone is bit-exact.

## 4. `acid-color-0` (pixel LOSS vs a Ruffle golden)

- Golden: Ruffle-made (`quality = "low"`), tolerance 3, max_outliers 3.
- Ruffle decodes with the `jpeg-decoder` 0.3 crate: triangle upsampling and rounded colour, i.e. stb-like. That is why
  stb sat at 3/3.
- Every one of the 1 135 new outliers lies inside the JPEG3's footprint (y 388–498, x 8–249). The other 3 are the
  unchanged baseline ones.
- |after − before| max is 21, on chroma edges: the same mechanism that takes clone from 77 to 0 against Flash.
- CI last graded this row at **308 (fail)** at `d70f2c0aa`. The local 3/3 pass comes from the s27 wave-1 landings
  since then, so this is a loss against a flip CI has not yet confirmed.
- **Disposition proposal:** if the Flash image matches the patch's render better than the Ruffle golden, add it to
  `RUFFLE_VS_FLASH_DIFFERENCES.md` (image axis, JPEG chroma upsampling; Ruffle's crate = libjpeg-6b-style fancy
  upsampling).
- **Completion:** the FLASH image request below.

## 5. A/B over every JPEG-bearing row (brief item 2)

**Static scan.** I walked every downloaded SWF (all categories but `from_avmplus`, which is ABC-only) plus
`regression/`, looking for DefineBits / JPEG2 / JPEG3 / JPEG4. That found 26 test dirs, 14 of them with image
comparisons.

**What was run.** All of them, plus 2 bitmap-fill regression neighbours: 28 tests. Clean-master binary vs patch
binary, graphics, `--recompile`, same box, png md5 captured.

| row | before (origin/master) | after (patch) | png md5 before → after |
|---|---|---|---|
| `avm1/clone_sprite_types` | pass | pass | (trace) |
| `avm1/movieclip_state_values` | pass | pass | (trace) |
| `avm1/place_and_lookup` | pass | pass | (trace) |
| `avm2/away3d_advanced_shallow_water_demo` | img fail 1326765/400 (baseline fail) | same | `=` |
| `avm2/bitmapdata_constructor_from_timeline` | pass | pass | (trace) |
| `avm2/pixelbender_dithering` | img pass 9413/32500 | img pass **27**/32500 | 2a3abab2 → f0bf9d05 |
| `avm2/stage3d_raytrace` | img fail 660000/10 (baseline fail) | same | `=` |
| `avm2/stage3d_texture` | img pass 2/117, max 15 | same | ecfa2cb2 → c19e1b31 |
| `from_gnash/misc-ming.all/BitmapDataDraw` | pass | **ruffle_matched** | (trace) |
| `from_gnash/misc-ming.all/VarAndCharClashTest` | pass | pass | (trace) |
| `from_gnash/misc-ming.all/loading/LoadBitmapTest` | ruffle_matched | ruffle_matched | (trace) |
| `from_gnash/misc-ming.all/loading/loadMovieTest` | ruffle_matched | ruffle_matched | (trace) |
| `from_shumway/acid/acid-big` | img pass 0/20, max 50 | pass 0/20, max 49 | 27f6365e → 047401f7 |
| `from_shumway/acid/acid-bitmap-fill` | img pass 242/300 | pass 245/300 | cbdf989e → a14bda92 |
| `from_shumway/acid/acid-bitmap-fill-2` | img pass 0/0, max 30 | pass 0/0, max **0** | 408052b5 → 90ad9604 |
| `from_shumway/acid/acid-blend` | img pass 5/348 | pass 4/348 | db96cdb7 → c9fbd97a |
| `from_shumway/acid/acid-blend-2` (output.10/15/20/26/40) | all pass 0/0, max 128/131/126/111/150 | all pass 0/0, max 128/131/127/112/151 | all 5 move |
| `from_shumway/acid/acid-color-0` | img pass 3/3 | **img fail 1138/3** | 45374c68 → c0d193b6 |
| `from_shumway/acid/acid-large` | img pass 0/0, max 3 (tol 11) | pass, max 8 (tol 11) | d79ea0ca → 0804b5be |
| `from_shumway/as3-loader/events/loader-events` | ruffle_matched | ruffle_matched | (trace) |
| `from_shumway/avm1/mouse-transparency` | pass | pass | (trace) |
| `from_shumway/avm2/flash/display/bitmapdata/bitmapdata-clone` | img pass, max 77 (tol 77) | pass, max **0** | 668f2b39 → b31826e1 |
| `from_shumway/bitmapbuttons` | img fail 52/0 | img fail **39**/0 | 4349a280 → 1f6d76f8 |
| `from_shumway/bitmapdata/getpixel-from-embedded` | output_mismatch | **pass** | (trace) |
| `regression/avm1_jpeg3_alpha_bitmap` | img pass, max 1 (tol 3) | pass, max 2 (tol 3) | 899df57f → bc82b7b8 |
| `regression/avm1_parent_child_bitmap_fill` | img pass 0 | pass 0 | `=` |
| `regression/bitmap_pool_layer_cap` | img pass 0 | pass 0 | `=` |
| `visual/define_bits_jpeg2_huge` | pass | pass | (progressive → stb fallback) |

The `away3d_*` / `stage3d_raytrace` failures are baseline: both are in `s27-baseline-pixel-failing.txt`, with
identical md5 in both legs.

**Ruffle-golden rows that moved away from Ruffle while the Flash rows improved:**
- `acid-color-0`: the priced loss, §4.
- `acid-bitmap-fill`: +3 outliers, still 55 under budget.
- `acid-large`: max 3 → 8 under tol 11.
- `avm1_jpeg3_alpha_bitmap`: max 1 → 2 under tol 3; 4:4:4, so only IDCT/colour rounding changes.

All of these except `acid-color-0` stay passing; their remaining headroom is listed for the record.
`acid-bitmap-fill-2` (30 → 0) and `bitmapbuttons` (52 → 39) moved *towards* their goldens.

**No-graphics leg (mode parity, recompiler change):**

| row | before | after |
|---|---|---|
| `getpixel-from-embedded` | output_mismatch | pass |
| `BitmapDataDraw` | pass | ruffle_matched |

Identical to graphics.

**Canary.** `render_canary_tests.txt` = 152 tests.
- Instead of 2 × 152 compile-bound renders, I ran BOTH recompiler binaries on every canary SWF and hashed the whole
  generated-C tree. Rendering is byte-deterministic, so identical C ⇒ identical PNG; this is stronger than md5 on the
  PNG.
- Result: **144 / 152 byte-identical.** The 8 that differ are exactly the JPEG rows of the table above:
  `acid-bitmap-fill`, `acid-bitmap-fill-2`, `acid-blend-2`, `stage3d_texture`, `pixelbender_dithering`,
  `bitmapbuttons`, `acid-color-0`, `regression/avm1_jpeg3_alpha_bitmap`.
- The final source (after the UB cleanup) emits C identical to the measured binary on all 152.
- **Appended canary member:** `from_shumway/avm2/flash/display/bitmapdata/bitmapdata-clone`, the zero-headroom Flash
  golden of this change class. It was not in the set. Captured: pass.

**Regression suite.**
- `avm1_jpeg3_alpha_bitmap`, `avm1_parent_child_bitmap_fill`, `bitmap_pool_layer_cap`: all pass, numbers above.
- No new regression fixture: the new behaviour is covered by three corpus rows with FLASH goldens (clone image,
  dithering image, getpixel trace). That is stronger than any fixture I could make here.

## 6. GPU nearest tie rule on stage (brief item 3)

**Fixture.** `w2-jpeg-flash-decode-fixtures/avm1_bitmap_nearest_tie_stage`:
- SWF8, 40×40 white stage;
- an 8×8 lossless bitmap whose texel (c, r) = (32c, 32r, 0x80);
- a 0x43 clipped non-smoothed fill, scale **exactly 1.5** on both axes, at (8,8) px, on stage.

So texel t = (i + 0.5 − 8) / 1.5 ties on i − 8 = 1, 4, 7, 10.

**Predictions** (`predict_ties_up.png`, `predict_ties_down.png`): the two rules differ on 80 pixels.
- Ties up: column/row index sequence 0,1,1,2,3,3,4,5,5,6,7,7.
- Ties down: 0,0,1,2,2,3,4,4,5,6,6,7.

**Ours (graphics, lavapipe), `ours_graphics_lavapipe.png`: NEITHER rule.**
- At y = 10 the column ties resolve down, up, up, up (0,0,1,2,3,3,4,5,5,6,7,7).
- At x = 10 the row ties resolve up, down, down, down (0,1,1,2,2,3,4,4,5,6,6,7).
- So the vertex-interpolated UV lands a hair on either side of the texel boundary.
- 42 px differ from each prediction.

The on-stage nearest path therefore **fails this fixture whichever rule Flash uses**.

**Fix sketch (not done; needs the Flash image first):** in the 0x42/0x43 arm of the fragment shader, replace
`textureSample(bitmap_samp)` with `textureLoad(floor(uv * size + bias))`, using bias +1/256 texel for ties-up (or −
for ties-down).
- Risk: `acid-blend` (0x43, Ruffle golden, already tuned once; see the `bitmap_samp_linear` comment).
- Needs a canary run.

## Refutations

1. **ACCEPTED_DIFFS Cat. 9 `getpixel-from-embedded`: "no standard decoder configuration reproduces Flash" — REFUTED.**
   IJG v7+ defaults plus truncating colour give `200d04`. The entry is marked RESOLVED and the ignore line pruned (in
   the patch).
2. **"libjpeg-turbo is ~4 % closer to Flash" (w1-drift lead) — true but beside the point.** turbo's fancy upsampling
   is the wrong family. It scores 9 036 vs IJG-v7+'s 40 on dithering, and max 77 vs 0 on clone.
3. **Brief premise "prototype it in `image_decode.c`".** That file only serves runtime `loadClip` images. Every
   DefineBits* JPEG is decoded at **recompile time** (`swf.cpp`, `abc_timeline.cpp`), so the change lives in
   `SWFRecomp/`.
4. **"Flash = libjpeg 6b" (folk belief) — refuted for FP32.** 6b has no DCT-scaled upsampling. The FP9 / FP11 / FP15
   gnash goldens suggest the decoder changed across Flash versions (§3).

## New unclaimed leads

1. **Runtime JPEG decode paths still use stb:** AVM1 `loadClip` / `MovieClipLoader` (`image_decode.c`) and AVM2
   `Loader.loadBytes` / `loadImage` (`avm2_bitmap.c:5049`). Porting needs `jpeg_flash.cpp` inside the runtime TU
   list (`verify_output.py` source list, CMake, Emscripten). Rows: `avm1/movieclip_methods_with_loaded_image`,
   `jpeg_loader_context` and other loaded-JPEG rows. Their goldens are Ruffle, so Flash-vs-Ruffle pricing applies.
   Price S–M.
2. **On-stage nearest tie rule** (§6). Completion: the Flash image of the fixture, then the shader bias. Price S plus a
   canary run.
3. **Progressive JPEGs** fall back to stb. Only `visual/define_bits_jpeg2_huge` has one (trace-only). IJG v7+ applies
   the same DCT-scaled upsampling to progressive scans. Price M; no graded row today.
4. **JPEG4 deblocking** (`deblockParam`): unmeasured, and no image row exists. Needs a Flash image of a JPEG4 fixture
   with deblock ≠ 0.
5. **`BitmapDataDraw` line 284**, if FP32 says 17408 (§3 outcome b): a sub-texel position check of AVM1 smoothed
   `draw()` sampling.

## LOCAL ORACLE REQUESTS

1. **FLASH: `from_shumway/acid/acid-color-0/test.swf`, image (`run_image.py`, frame 1; the row uses
   quality low, so capture at the movie's own quality), compare.** Count channels > 3 against three images:
   - (a) the Ruffle golden `output.expected.png`;
   - (b) our clean-master render: CI actual or `git apply -R w2-jpeg-flash-decode.patch`;
   - (c) the patch render.

   Restrict the count to the JPEG footprint y 388–498, x 8–249. Prediction: Flash matches (c) best there. That
   decides §4's disposition.
2. **FLASH: `from_gnash/misc-ming.all/BitmapDataDraw/test.swf`, trace (`run_trace.py --wrapped`, num_ticks 30).**
   Read line 46 (`BitmapDataDraw.c:284`). The three outcomes and their meaning are in §3.
3. **FLASH: `w2-jpeg-flash-decode-fixtures/avm1_bitmap_nearest_tie_stage/test.swf`, image (`--screen` or draw
   wrapper, frame 1).** Compare to `predict_ties_up.png` / `predict_ties_down.png`; 80 px separate them.
4. *(optional)* **FLASH: `from_shumway/bitmapdata/getpixel-from-embedded` trace.** A sanity check that the Shumway
   golden `200d04` holds on FP32; the decoder model predicts it does.
