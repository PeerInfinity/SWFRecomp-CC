# w2-nearpass-land — landing the pixel near-pass prototype (session 25, wave 2, cloud)

**New files (this branch):**
- `SWFRecompDocs/plans/session25-fanout-reports/w2-nearpass-land-report.md` (this report)
- `SWFRecompDocs/plans/session25-fanout-reports/w2-nearpass-land.patch` (`git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`; proven with `git apply --check -R`)

No new source files, no new fixtures (every behaviour has a corpus row; see §5). Branch base: origin/master **`2afd3e36`** (rebased
at the end of the session; see §4 for the re-measure on that base). Box: `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Corpus:
`download_tests.sh` from upstream Ruffle master; my blobless Ruffle clone (source reads) is at **`3ac8dcb07`**.

## 1. Verdict: GO, all five hunks landed. Expected flips: **px +9**, trace 0

Hunk B is **finished to a flip**. On top of the w1 matrix quantization it needed two ramp fixes: Ruffle's float linearRGB endpoints and Ruffle's
truncating stop alpha. It also flips a second row (`movieclip_line_gradient_style`). One extra flip came from hunk A
(`from_shumway/acid/acid-gradient`).

### EXPECTED-FLIP LEDGER (for the coordinator's CI check)

**Pixel axis, fail → pass (9):**

| # | comparison | CI pixel baseline (s24 final `44986836161`) | this patch (lavapipe, CI-grade) | hunk |
|---|---|---|---|---|
| 1 | `avm2/bitmapdata_draw_rotation output` | 348 / 0 at tol 0 (max 255) | **0, max 0** | D |
| 2 | `visual/drawing_api/gradient_focal_point output` | 60 / 0 at tol 13 (max 39) | **0, max 7** | A |
| 3 | `from_shumway/acid/acid-gradient output` | 6639 / 0 at tol 1 (max 189) | **0, max 1** | A (new: shader clamp now also covers *timeline* focal gradients, which had no clamp) |
| 4 | `from_shumway/acid/acid-gc output` | 234 / 0 at tol 0 (max 255) | **0, max 0** | C |
| 5 | `from_shumway/doubleAndRegister output` | 2 / 0 at tol 0 (max 255) | **0, max 0** | S |
| 6 | `from_shumway/acid/acid-scale output` | 8 / 0 at tol 0 (max 255) | **0, max 0** | S |
| 7 | `from_shumway/acid/acid-gradient-2 output` | 3 / 0 at tol 1 (max 255) | **0, max 1** | S |
| 8 | `avm1/movieclip_begin_gradient_fill output` | 132 / 0 at tol 6 (max 209) | **0, max 1** | B |
| 9 | `avm1/movieclip_line_gradient_style output` | fail (1023 at s24; **33 / 0** on master after `0f35012bd`) | **0, max 1** | B |

**Trace axis: 0 status moves, and 0 trace-text changes** across all 216 rows of the A/B on the rebased base. That includes
`GradientFillTest`, which prints pixel probes; see §2.5 for why that needed a design change.

**Pixel pass → fail: none.** Moves that change neither status (all measured on the rebased base, §4):
`visual/filters/bevel` **738 → 9** outliers (limit 6, C; residual = 3 device-font glyph pixels, §6 lead 1),
`visual/filters/displacement_map` 24 → 7 at tol 20 (limit 72), `acid-color-0` 17326 → 17315, `strokes/scale` 19308 → 19287,
`acid-small .01/.05` better on all three checks, `acid-video .01/.10/.20` pass → pass (outlier counts move by under 150 / 20000 on the tol-5
check and stay within limits), `acid-clip` 7043 → 7041, `GradientFillTest fp9/fp10` ±1-level moves only (936 / 1070 unchanged),
`fills_and_lines` 0 / 0 max 2 (unchanged verdict; 3276 channels move by ≤ 2).

**Zero-headroom rows (brief): all unchanged, md5-identical.** `bevel_inner`, `bevel_full`, `bevel_outer`, `glow_with_alpha_strength`
18 / 18 (max 254) IDENTICAL, `layer_alpha` 0 / 0 max 2 at tol 2 IDENTICAL, `layer_erase` 0 / 0 max 3 at tol 3 IDENTICAL,
`fills_and_lines` max 2 at tol 2 (pass → pass, DIFFERS by ≤ 2 as in w1).

Functions touched (for `n-play-game`, `w2-dynclip-cxform`, `w2-avm1-filters`):
- `action.c`: `drawingGenerateGradientRamp`, `drawingBuildGradientBoxMatrix`, `drawingBuildGradientAbcdMatrix`, `applyGradientFillToMC`,
  `applyLineGradientStyleToMC`, `fillDrawingInfos`; new statics `drawingFixed16`, `drawingGradientMatrixFixed16`. No button or mouse code.
- `action.h`: two TRAILING fields on `DrawingRenderInfo` (`gradient_matrix_fx[16]`, `line_gradient_matrix_fx[16]`).
- `tag.c`: **only** `compose_children`: one 13-line block right after `hit_test_mat4_multiply(composed, parent_composed, local_xform);`.
  It does not touch the dynamic-clip arm or the cxform helpers.
- `render_webgpu.c`: `vs_main` WGSL (`focal_z` clamp) and `render_webgpu_draw_gradient_tris` (focal encode).
- `avm2_bitmap.c`: new statics `bd_tri_covers` and `bd_quad_covers`, plus the general-affine arm of `bd_draw`.
- `SWFRecomp/src/swf.cpp`: new `SWF::drawLinesLyon`, called first from `SWF::drawLines`; declared in `swf.hpp`. **The
  `SWFRECOMP_OLD_STROKE` env hook is dropped**; the old builder is now only the fallback (lyon "fold" joins, zero-length edges). This hunk
  **needs `--recompile`**, as CI always does.

## 2. Mechanisms (what changed vs the w1 prototype)

Hunks D, A, C and S are the w1 prototype unchanged (w1 report §2.1–2.4), rebased. The patch applied clean onto both `31fff3bf` and `2afd3e36`.
The only edit is the removed S env hook.

### 2.1 B: finished. Three Ruffle quantizations, all needed

`movieclip_begin_gradient_fill`'s last 6 outliers were all in cell (4,1) (`radial`, `repeat`, `linearRGB`, focal 0.8): the blue channel was 24
where the golden has 31, on the repeat wrap. The ±1 field elsewhere was concentrated in cell (1,0) (alphas `[50, 50]`).

1. **linearRGB ramp endpoints** (`drawingGenerateGradientRamp`). Ruffle's `CommonGradient::new` (`render/wgpu/src/mesh.rs`) lerps the
   **float** linear values `srgb_to_linear(c/255)*255` and truncates once. We used `GRADIENT_RAMP_LINEAR_U8`, which quantizes each endpoint to u8
   first. For red's B = 0x19 → linear 2.48, texel 1 of the ramp is `trunc(2.48 + 252.5/255) = 3` in Ruffle but `trunc(2 + 253/255) = 2` for
   us. The shader's linear→sRGB step (plus the `rgb / a` divide at alpha 0.8) turns that one level into 7 on a wrap pixel. Fix: use
   `GRADIENT_RAMP_LINEAR`, the mode `gradient_ramp.h` already documents as "Ruffle exact", which the recompiler's static gradients already use.
2. **Stop alpha truncates** (`drawingGenerateGradientRamp`). Ruffle `build_gradient_records` (`core/src/avm1/globals/movie_clip.rs:520`):
   `(alpha / 100.0 * 255.0) as u8`, so alpha 50 → 127. We rounded (→ 128). NaN → 0 is guarded, as Rust's saturating cast does. This fix cleared
   cell (1,0).
3. **Matrix quantization** (the w1 hunk): `a`–`d` → Fixed16 (truncating), `tx`/`ty` → truncated twips, and the box form adds
   `from_pixels(x) + from_pixels(w/2)`.

Attribution, measured on `movieclip_begin_gradient_fill` at tol 6:

| configuration | outliers |
|---|---|
| w1 (3 only) | 6 |
| 1 + 3 | **0** (max 1) |
| 1 + 2 + 3 | 0 (max 1; cell (1,0) exact) |
| 1 + 2, no Fixed16 `a`–`d` | 94 (max 209) |

All three are needed for exactness. `movieclip_line_gradient_style` goes through the same ramp builder and matrix and flips with them
(33 → 0, max 1).

### 2.2 B design change: Fixed16 `a`–`d` on the GPU copy only (`fillDrawingInfos`)

With the w1 hunk's shared-matrix Fixed16, my 81-row sweep showed `from_gnash/misc-ming.all/GradientFillTest` lose **3 Flash-matching trace
lines** (123 → 120 matching; status stays `output_mismatch`). The lost lines are `PASSED: 0xffffff is near to 0xfdfffd` vs Flash's `0xffffff`.

Mechanism: that test reads pixels through our **CPU** `BitmapData.draw` raster. Its sampler is nearest-texel `round(t*255)` (see
`SAMPLE_GRADIENT_RAMP`, tuned to Flash's pixel probes), and the probe sits on a hard stop: texel r0 is white, texel r0+1 is 0xfdfffd. The 45°
box's `a`–`d` lose ~2.3e-4 relative to Fixed16, which nudges t across the rounding boundary.

I tried giving the CPU sampler the GPU's `t*256-0.5` lerp instead. That was **worse**: 159 mismatching lines, reverted.

So the shared matrix keeps master's float `a`–`d`, plus the truncated twip `tx`/`ty`, which GFT tolerates. The Fixed16 copy is built in
`fillDrawingInfos` into the two trailing `DrawingRenderInfo` fields and handed to the renderer. Results:
- `GradientFillTest` trace is byte-identical to before, in graphics **and** no-graphics.
- Both B rows render byte-identically to the shared-quantization version.
- The full canary is byte-identical between the two designs (182 / 182 PNGs, `after` vs `after2`).

The stack cost is +128 B per `DrawingRenderInfo`. The `[64]` arrays are not in recursive functions, and the WASM stack is 8 MB.

### 2.3 A also flips `acid-gradient`

The vs_main clamp covers **every** `0x13` style, including recompiler-baked timeline focal gradients. Before, those were never clamped: only the
Drawing-API path clamped, on the CPU. `acid-gradient` has a timeline focal gradient with |f| > 0.98. With only `render_webgpu.c` reverted it
is back to 6639 / 0; with the full patch it is 0 / 0, max 1.

## 3. Verification (lavapipe; CI-grade)

**Fidelity proven:** my BEFORE renders on `31fff3bf` are md5-identical to CI's actual PNGs on `origin/ruffle-image-results` for
`movieclip_begin_gradient_fill`, `bitmapdata_draw_rotation`, `acid-gc`, `acid-gradient-2`, `acid-scale`, `doubleAndRegister`,
`gradient_focal_point` and `acid-gradient`. `movieclip_line_gradient_style` differs only because master moved it after the pixel baseline
(`0f35012bd`: 1023 → 33). So every verdict here is absolute, not just an A/B.

Legs, all `--mode=graphics --recompile`, md5 compare (`render_canary.py`):

| run | base | set | result |
|---|---|---|---|
| canary `before`/`after`/`after2` | `31fff3bf` | 118-member canary (incl. the new acid-scale) + 5 headline extras = 123 tests, 182 PNGs | 168 IDENTICAL, 14 DIFFERS = ledger + the pass→pass rows above; 0 trace moves |
| sweep `sweep_b`/`sweep_a2` | `31fff3bf` | the 81 non-canary image rows in avm1 + from_shumway + from_gnash (C and S touch every nested timeline transform / timeline stroke; these are the timeline-heavy suites) | 138 IDENTICAL, 7 DIFFERS: `acid-gradient` fail→pass, rest pass→pass / fail→fail; 0 trace-text changes |
| `before3`/`after3` | **`2afd3e36`** (rebased) | canary (126, incl. s25 appends) + headline + 81-row sweep + 4 filter rows = 216 tests | see §4 |
| filters A/B | `31fff3bf` | `bevel`, `bevel_full`, `bevel_outer`, `glow_with_alpha_strength`, `glow_without_composite_source` | all md5-IDENTICAL except `bevel` 738 → 9 (C) |

**Regression suite:** the 7 canary members are IDENTICAL. I ran the 7 other image-compared fixtures separately, both legs
(`avm1_parent_child_{bitmap_fill,morph,render,text}`, `avm2_parent_child_render`, `avm2_timeline_solid`, `bitmap_pool_layer_cap`): md5
IDENTICAL, and trace PASS on the final code. The s25 fixtures new on `2afd3e36` (`layer_group_*`, `avm1_dynclip_color_transform`) are
covered in §4.

**Mode parity:** no hunk touches `swf_core.c`, `tag_stubs.c` or a `NO_GRAPHICS` arm. B's ramp change does reach the CPU `BitmapData.draw`
raster, which no-graphics also runs, so I ran `GradientFillTest` (the only AVM1 pixel-probe gradient row) without `--mode=graphics` on both
legs: trace byte-identical. Per policy, the no-graphics leg otherwise rides the final grading run.

## 4. Re-measure on the rebased base `2afd3e36`

`origin/master` gained 8 commits while I worked: `2afd3e36` plus the `w2-avm1-with-scope`, `w2-edittext-span-model`, `w2-acid-text-kerning`,
`w2-dynclip-cxform`, `w2-avm2-layer-groups` and `w2-avm2-cm-copyfrom` landings. That is ~2.9k lines in `action.c`, `tag.c`,
`render_webgpu.c` and `swf.cpp`. The patch applied clean (the canary EOF conflict was resolved by keeping both appends). I then re-ran the whole
A/B on `2afd3e36`: `before3` (clean) vs `after3` (patch), 216 tests / 338 PNGs. The set is the current 126-member canary (incl. the s25
appends and their new `regression/` fixtures), the headline rows, the 81-row sweep, and the four zero-headroom filter rows.

**316 IDENTICAL, 22 DIFFERS. Exactly the 9 ledger flips, 0 pass→fail, 0 trace status moves, 0 trace-text changes.**

Per-test before/after on `2afd3e36` (outliers / limit @ tolerance, max diff):

| comparison | before (clean `2afd3e36`) | after (patch) | verdict |
|---|---|---|---|
| `avm2/bitmapdata_draw_rotation` | 348/0 @0, max 255 | 0/0, max 0 | **FLIP** (D) |
| `visual/drawing_api/gradient_focal_point` | 60/0 @13, max 39 | 0/0, max 7 | **FLIP** (A) |
| `from_shumway/acid/acid-gradient` | 6639/0 @1, max 189 | 0/0, max 1 | **FLIP** (A) |
| `from_shumway/acid/acid-gc` | 234/0 @0, max 255 | 0/0, max 0 | **FLIP** (C) |
| `from_shumway/doubleAndRegister` | 2/0 @0, max 255 | 0/0, max 0 | **FLIP** (S) |
| `from_shumway/acid/acid-scale` | 8/0 @0, max 255 | 0/0, max 0 | **FLIP** (S) |
| `from_shumway/acid/acid-gradient-2` | 3/0 @1, max 255 | 0/0, max 1 | **FLIP** (S) |
| `avm1/movieclip_begin_gradient_fill` | 132/0 @6, max 209 | 0/0, max 1 | **FLIP** (B) |
| `avm1/movieclip_line_gradient_style` | 33/0 @6, max 209 | 0/0, max 1 | **FLIP** (B) |
| `visual/filters/bevel` | 738/6 @3, max 254 | 9/6, max 254 | fail→fail, near (C) |
| `visual/filters/displacement_map` | 24/72 @20, max 101 | 7/72, max 24 | pass→pass |
| `from_shumway/acid/acid-color-0` | 17326/3 @3 | 17315/3 | fail→fail |
| `visual/simple_shapes/strokes/scale` | 19308/0 @5 | 19287/0 | fail→fail |
| `from_shumway/acid/acid-clip` | 7043/7000 @0 (409/140 @64) | 7041/7000 (409/140) | fail→fail |
| `from_shumway/acid/acid-small .01` | 24081 / 11355 / 2529 | 23976 / 11088 / 2496 | pass→pass (all 3 checks better) |
| `from_shumway/acid/acid-small .05` | 24036 / 10755 / 2193 | 23937 / 10569 / 2190 | pass→pass (all 3 checks better) |
| `from_shumway/acid/acid-video .01 / .10 / .20` | 16153 / 15438 / 13389 @5 | 16008 / 15478 / 13280 | pass→pass (limits 20000 / 18000 / 15000) |
| `from_gnash/misc-ming.all/GradientFillTest fp9/fp10` | 936/1070 @34 | 936/1070 | pass→pass (±1 levels); **trace byte-identical** |
| `visual/drawing_api/fills_and_lines` | 0/0 @2, max 2 | 0/0, max 2 | pass→pass (≤ 2-level moves) |
| `bevel_inner`, `bevel_full`, `bevel_outer`, `glow_with_alpha_strength` | 18/18, max 254 | 18/18, max 254 | IDENTICAL |
| `visual/blend_modes/layer_alpha` / `layer_erase` | 0/0 max 2 @2 / max 3 @3 | same | IDENTICAL |
| `regression/layer_group_*` (3), `regression/avm1_dynclip_color_transform`, `from_shumway/acid/acid-text` (s25 appends) | pass, max 0 | pass, max 0 | IDENTICAL |

The numbers on `2afd3e36` equal the `31fff3bf` measurements row for row, so none of the 8 new master commits interacts with these hunks.

## 5. Patch scope

`git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`:

| file | lines | hunk |
|---|---|---|
| `SWFRecomp/src/swf.cpp`, `SWFRecomp/include/swf.hpp` | +309 | S |
| `SWFModernRuntime/src/actionmodern/action.c` | +58 / −10 | B (ramp, alpha, matrix, `fillDrawingInfos`), A (CPU clamp removed) |
| `SWFModernRuntime/include/actionmodern/action.h` | +5 | B (trailing fields) |
| `SWFModernRuntime/src/rendering/render_webgpu.c` | +9 / −2 | A |
| `SWFModernRuntime/src/libswf/tag.c` | +13 | C |
| `SWFModernRuntime/src/avm2/avm2_bitmap.c` | +50 / −3 | D |
| `ruffle-tests/render_canary_tests.txt` | +7 | canary append: `from_shumway/acid/acid-scale` (tier 1, tol 0) at EOF |

`verify_output.py`: unchanged (no new TU). No fixture: every behaviour has a corpus row with a Ruffle golden (the 9 ledger rows).

## 6. New unclaimed leads

1. **`visual/filters/bevel` is 3 pixels from a flip** (9 / 6 channels after C). The residual is (456,28), (19,294) and (19,299): stem/serif
   pixels of default-font glyphs (`with_default_font = true`), i.e. the device-font text family (`w1-pixel-text`). +1 row.
2. **AVM2 twin of B**: `avm2_display.c` `gfx_gen_ramp` still uses `GRADIENT_RAMP_LINEAR_U8` and rounds alpha (`alphas*255 + 0.5`). Ruffle
   AVM2 is `(alpha * 255.0) as u8` (`graphics.rs:217`) with float linear endpoints. Its gradient matrix probably also needs Fixed16
   `a`–`d` on the GPU copy. Not measured; `avm2/graphics_gradients` (tier-2 band in the canary) is the first row to try. Sibling-owned file
   this session, so not touched.
3. **The CPU `BitmapData.draw` gradient sampler** (`SAMPLE_GRADIENT_RAMP`, nearest `round(t*255)`) is not Ruffle's model (Ruffle's `draw` uses
   the GPU shader). It is tuned to Flash's probes. A Flash-vs-Ruffle audit of `GradientFillTest`'s 155 mismatching lines would say which model
   to aim at.

## LOCAL ORACLE REQUESTS

none
