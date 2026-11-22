# s24 w1-pixel-bitmap: bitmaps, shaders, hairlines, runtime-filter leftovers

**New files:** this report and `w1-pixel-bitmap-prototype.patch` (`git diff origin/master -- SWFModernRuntime SWFRecomp`,
452 lines, 4 files: `avm2_bitmap.c`, `avm2_cpu_raster.c`, `avm2_display.c`, `avm2_pixelbender.c`). The source is reverted
in this commit.

Box: cloud, lavapipe. `SETUP_STATUS` all OK. Upstream test SHA **`bcac30c19`** (matches the s24 baseline download).
**Fidelity proven:** my clean-master render of `avm2/bitmapdata_draw_cab_quality` is md5 `b1e924c4…` = CI's actual PNG
on `origin/ruffle-image-results`. All before numbers below are CI baseline `44965247383` rows; every "unchanged" claim
is the exact same message (outliers + max_diff) as that run's row.

## Verdicts

| # | item | verdict | priced flips (graphics) | prototype |
|---|---|---|---|---|
| 1 | JPEG encoder | **GO** | **+1 pixel** `avm2/bitmapdata_encode_jpeg_visual` (28648 → **0** outliers, max 8 / tol 14); **+1 trace** `avm2/bitmapdata_encode` (output_mismatch 26/147 → **PASS**) | measured |
| 2 | ShaderFilter on Bitmap + `applyFilter(ShaderFilter)` | **GO** for the headline; rider NO-GO | **+1 pixel** `avm2/pixelbender_effect_glassDisplace_shaderfilter` (879464 → **0** outliers, **max diff 0**) | measured |
| 3 | `bitmapdata_draw_cab_quality` | **GO** | **+1 pixel** `avm2/bitmapdata_draw_cab_quality` (2720 → **80 / 80**, max 32; zero headroom, see §3) | measured |
| 4 | quality=low hairline tie-break | **NO-GO** (0 flips possible) | 0. `shape_test` 15994 → 12575 with the bias; the row's floor is missing shapes, not ties | measured, not in patch |
| 5 | AVM1 runtime-filter leftovers | **HOLD** (priced, no corpus rows) | 0 | none |

**Total GO: +3 pixel, +1 trace**, 0 moves in a 55-row sweep (§Sweeps). Rider `pixelbender_dithering`: stays failing
(2764800 → 1297344 outliers; fail → fail).

**Mode parity:** items 2 and 3 touch shared AVM2 code but only graphics-graded behaviour. Item 1's encoder is
**graphics-only in this prototype**: it calls the `stbi_write_jpg_to_func` that `render_webgpu.c` already links. So
no-graphics `bitmapdata_encode` still fails (EOF at the first JPEG section, measured). Wave 2 must vendor a static copy
(next section). Run the no-graphics leg on the final grading run.

**Canary riders** (append at EOF): `avm2/bitmapdata_draw_cab_quality` (vector draw() with a colorTransform, a blendMode
and an aliased low-quality raster), `avm2/pixelbender_effect_glassDisplace_shaderfilter` (ShaderFilter display + applyFilter),
`avm2/bitmapdata_encode_jpeg_visual` (encoder round trip). Existing members `acid-bitmapData-draw` and
`bitmapdata_draw_self_via_graphic` already cover the shape-draw composite; both are byte-unchanged under the patch.

---

## 1. JPEG encoder: GO (+1 pixel, +1 trace)

**Which encoder do Flash and Ruffle use?** Flash uses libjpeg. Ruffle uses **image-rs `JpegEncoder::new_with_quality`**
(`core/src/bitmap/operations.rs:1946`, `image = 0.25.10`), not the `jpeg-encoder` crate. Ruffle's rules
(`bitmap_data.rs:1642-1680`, `operations.rs encode`):
- it encodes the **premultiplied** colour as RGB8 (composited onto black);
- quality > 100 → RangeError #2006, and 0 is treated as 1;
- above 65500 px on either side → Error #3699, checked after the quality check;
- JPEGXR returns null (a stub).

**Byte-exact output is NOT needed.**
- The pixel row's golden is a **Flash** capture (upstream `1ffe0d742`: "tolerance for codec differences between Flash's
  libjpeg and Ruffle's image-rs").
- The trace row reads only structure: SOI, an SOF0 with `segLen=17 precision=8 w h components=3`, and the presence of EOI.
- So any baseline encoder works.

**What we did:** `bd_encode` wrote nothing for a non-PNG compressor. There was also a second, hidden bug: the
**`JPEGEncoderOptions` class had no constructor**, so `.quality` was never stored. My first measurement ran every encode
at q=1 (12728 outliers, max 53). Storing it gives 0 outliers.

**Prototype** (`avm2_bitmap.c`):
- `bd_encode_jpeg` feeds premultiplied RGB to stb_image_write's baseline encoder: 4:2:0 chroma at quality ≤ 90, 4:4:4
  above (`stbi_write_jpg_core` l.1479).
- `jpeg_options_init` stores `quality:uint = 80`.
- Ruffle's argument order is now followed for the remaining `bitmapdata_encode` lines:
  - rect null → TypeError #2007;
  - compressor null → #2007, raised **before** the empty-rect #2006 (`expected: negative rect + null compressor →
    TypeError #2007`);
  - a wrong compressor type → ArgumentError #2004;
  - PNG writes an alpha channel **only if the region has a non-opaque pixel** (Ruffle `has_alpha`).
- Note: the diff display's leading blank line is a harness artifact, because both sides are stripped.

| row | before (CI) | after |
|---|---|---|
| `bitmapdata_encode_jpeg_visual` [output] | 28648 / 0, max 128 | **0 / 0, max 8** (tol 14) |
| `bitmapdata_encode` (trace) | output_mismatch 26/147, `Error #2030` | **PASS** |
| `bitmapdata_encode_png_roundtrip` (trace), `bitmapdata_encode_png_visual`, `bitmapdata_colortransform` | — | unchanged |

**Sibling note:** `w1-avm2-tail` triages the `bitmapdata_encode` trace row. My patch flips it in full (JPEG section,
compressor-type, null-rect and PNG-alpha lines), so book it once.

**Wave-2 scope (~+40 lines beyond the prototype):**
- Copy `SWFRecomp/lib/stb/stb_image_write.h` to `SWFModernRuntime/lib/stb/`.
- Compile it in `avm2_bitmap.c` with `STB_IMAGE_WRITE_STATIC` + `STB_IMAGE_WRITE_IMPLEMENTATION` so both modes have it.
  Static linkage avoids clashing with `render_webgpu.c`'s copy.
- Add the header to `verify_output.py`'s copy list (it already copies `lib/stb/stb_image.h`), CMake and the Emscripten
  include path.
- Drop the `#if !defined(NO_GRAPHICS)`.
- Re-check no-graphics `bitmapdata_encode`.

## 2. ShaderFilter: GO for `glassDisplace_shaderfilter` (+1); rider `pixelbender_dithering` NO-GO here

**Ruffle model:**
- `render/wgpu/src/filters/shader.rs` binds the filter source as the **first image input**. It renders into a
  **source-sized** fresh transparent target in `ShaderMode::Filter`, where out-of-range samples read **transparent
  black**. A ShaderJob clamps instead (`naga-pixelbender/src/lib.rs:108-118`).
- `applyFilter` with a ShaderFilter **forces sourceRect to the whole source bitmap** (`bitmap_data.rs:1151-1178`; Flash
  ignores w/h). The golden confirms it: the test passes a 20×20 rect and Flash painted 500×375 at y=390.

**What we did:** ShaderFilter was a value holder. `avm2_filter_renderable` drops it, and `bd_apply_filter` ignored the
kind. A CPU PixelBender evaluator already exists for ShaderJob (`sj_start`, `avm2_pixelbender.c`).

**Prototype:**
- `sj_start` becomes a wrapper over `pb_run_job(ctx, job)`.
- New `avm2_pixelbender_run_filter(ctx, shader, src, dst)` sets three overrides: filter mode (out-of-range →
  transparent black in `pb_texel`), tex0 := src, target := dst.
- `bd_apply_filter`: a SHADER arm, whole source → replaces the dest region at destPoint, with the opaque-alpha fixup.
- `avm2_render_bitmap`: a Bitmap whose filter list holds a ShaderFilter draws the shader output. It is recomputed every
  frame in the prototype.
  - Wave 2: cache it on a BitmapData version counter plus the shader parameters.
  - Wave 2: apply left/right/top/bottom extensions.
  - Wave 2: decide non-Bitmap sources. A Sprite with a ShaderFilter would need the GPU filter layer's readback; no
    corpus row has one.

| row | before | after |
|---|---|---|
| `pixelbender_effect_glassDisplace_shaderfilter` | 879464 / 380, max 255 | **0 / 380, max 0** (byte-exact) |
| `pixelbender_dithering` (rider) | 2764800 / 19929 | 1297344 (still fail) |

**Why the rider can't ride:**
- `pixelbender_dithering` does `bitmapBaseData.draw(new mcHelloWorld())` on a 1280×900 transparent BitmapData.
- `mcHelloWorld` is a `DefineShape` whose fill is **0x43 (clipped, non-smoothed bitmap fill)** of a 900×600
  `DefineBitsJPEG3`, scaled.
- `avm2_cpu_raster_shape` skips bitmap fills (`avm2_cpu_raster.c` "Bitmap fills (0x40-0x43) … are skipped"), so the
  draw() target stays fully transparent. That was measured: the input pixel is `00000000`.
- Before the patch the Bitmap showed the stage colour. After it, the shader output is opaque black.
- **Completion mechanism:** a CPU bitmap-fill arm in `avm2_cpu_raster_shape` (fill matrix → texel, no smoothing for
  0x43). That is a separate ~80-line patch with game-visible value of its own.
- It is unpriceable as a flip: a dithered output at tol 1 turns 1-LSB input differences into threshold flips, and the
  golden's origin is unknown.

`blend_shader_luma_lighten` stays **NO-GO** (blendShader needs PBJ→GPU or a CPU layer compose). Unchanged here
(40318, same message).

## 3. `bitmapdata_draw_cab_quality`: GO (+1)

The test is `drawWithQuality(s, translate(20,0), ColorTransform(0,1,1), "difference", clip(0,10,40,10), false, "low")`.
`s` is a cacheAsBitmap Sprite holding a `drawTriangles` triangle. The golden is Ruffle's (160×160, scale 4).

Two separate defects, attributed by building the fix in two steps:
- **(a) colorTransform and blendMode are dropped for every vector (Shape/Sprite) source.** `bd_draw`'s shape arm called
  `bd_draw_shape_walk` straight onto the target; the code comment even says "not honoured yet".
  - Fix: raster into a transparent layer, apply the cxform per texel (unmul → `ctx_channel` → premul), then
    `blend_mode_apply` / `blend_over`.
  - Result: 2720 → 240. Magenta → blue: the bulk of the error.
- **(b) the explicit `"low"` quality is ignored.**
  - `drawWithQuality` aliases `bd_draw`, which forces AA (the s22 Flash AA-at-stage-LOW ruling for **draw()**).
    Ruffle's `draw_with_quality` passes the argument through (`bitmap_data.rs:990-1050`).
  - Honouring it on the shape arm only applies when arg 6 is present, i.e. only from `drawWithQuality`. It does **not**
    touch the s22 ruling on `draw()`.
  - Honouring it alone left 240 outliers (max 255): diagonal pixel centres lie exactly on the hypotenuse, and the
    aliased `raster_tri` had an inclusive tie rule.
  - The fix gives the single-sample path the D3D/Vulkan **top-left rule** (`cpu_tl_edge_owns`: left edges, which run
    upward in the sgn-normalised winding, plus top edges).
  - Result: **80 / 80**. Those 80 are the stage-rendered top triangle (MSAA vs Ruffle, the budget the test.toml comment
    describes), which this patch does not touch.

**Zero headroom:** the 80 come from the stage render, so any future stage-raster change on this row breaks it. That is
a reason for the canary member.

The aliased `raster_tri` path is now reached only from `drawWithQuality(…, "low")` and the `AVM2_CPU_DUMP` debug walk.
All other shape draws run with AA on (`raster_tri_aa`, whose own-edge rule is untouched).

## 4. quality=low hairline tie-break: NO-GO (0 flips)

**Premise attacked:**
- `shape_test`'s comparison is `known_failure = true`, tol 50 and **limit 0**. It is byte-identical to Ruffle's sidecar
  (`ruffle_match`, `ruffle_max_diff 0`).
- It sits **15994** outliers from passing. The bulk is **whole missing shapes**, which Ruffle also misses: the green
  top-left glyph and bar, and the red/black squares' outlines (side-by-side at the bottom of this section).
- No tie-break can flip it.

**A/B on `acid-small .01/.05`:** structurally unreachable. `acid-small` runs at default quality (MSAA 4); the tie only
exists at 1 sample, and the bias is `#if MSAA_SAMPLES == 1`.

**Measured:**
- The bias is +1/64 device px on both axes, applied to re-expanded hairline runs (`w ≤ min_twips`) in
  `hairline_restage`, quality=low only.
- `shape_test` goes 15994 → **12575 (−3419)**. That confirms the s23 §4a mechanism (Flash keeps the +0.5 px side).
- I did not sweep it. 261 corpus rows run at quality=low, and a 0-flip change does not justify that sweep. The hunk is
  reproduced here, not in the patch:

```c
// hairline_restage, before the run loop
double bias_x = 0.0, bias_y = 0.0;
#if MSAA_SAMPLES == 1
{   // local twips -> device px (y down)
    const double W2 = 0.5 * ctx->width, H2 = 0.5 * ctx->height;
    const double d00 = a*W2, d01 = c*W2, d10 = -b*H2, d11 = -d*H2, det = d00*d11 - d01*d10;
    if (fabs(det) > 1e-12) { const double e = 1.0/64.0;
        bias_x = (d11*e - d01*e)/det; bias_y = (-d10*e + d00*e)/det; }
}
#endif
// per run: const int biased = (w <= min_twips * 1.0001);
// per vertex: v += biased ? bias : 0
```

**Completion mechanism:**
- For the row: diagnose the missing Ming shapes. This is a new lead; Ruffle misses them too, so expect a Ming-specific
  fill or edge case.
- For the tie: bias every 1-device-px stroke at quality=low, including k==1 runs that bypass `hairline_restage`.
- Book it only with a sweep of the 261 low-quality rows and a row that actually flips.

Visual check (local side-by-side, not committed): left is the golden, right is ours. The green shape and bar, the red square outline and the
black square's red outline are absent in ours. 

## 5. AVM1 runtime-filter leftovers: HOLD (priced; no corpus rows)

**Premise correction:** the s23 report's "ColorMatrix / Convolution / DisplacementMap runtime filters draw nothing"
means **the filter is dropped, not the object**.
- `avm1LowerFilterObject` (`action.c:43869`) lowers only blur, drop shadow, glow, bevel and gradient bevel/glow (to
  kinds 1-4). Every other kind returns 0 and is skipped in `avm1SetRuntimeFilters`.
- The clip therefore renders **unfiltered**.
- For Convolution that is already **Ruffle parity**: ConvolutionFilter is not in wgpu's `is_filter_supported`. Flash
  would convolve.

| leftover | mechanism | size | flips |
|---|---|---|---|
| ColorMatrix (runtime) | Placed clips: fold the 4×5 matrix into the entry's `cx_*` override, as PlaceObject3 already does (`build_filter_chain`'s "first non-ColorMatrix entry"). This is exact only for diagonal+offset matrices. Dynamic roots / full matrix: a new `color_matrix.wgsl` pass on the filter layer (Ruffle `render/wgpu/shaders/filter/color_matrix.wgsl`), using `MSAA_SAMPLES`. | ~30 lines (fold) / ~150 lines (pass) | 0 |
| DisplacementMap (runtime) | The GPU pass exists (`render_webgpu.c:6164` `displace_wgsl`, used by AVM2). Needs: kind-5 lowering with `mapBitmap` (AVM1 BitmapData pixels), `mapPoint`, components, scale, mode, color/alpha; new FilterListEntry fields; and the renderer arm keyed off the AVM1 chain. | ~100 lines | 0 |
| Convolution | Ruffle parity already holds (renders unfiltered). Flash parity needs a convolution pass. | ~120 lines | 0 |
| Dynamic root's `attachBitmap` bitmaps / text fields | Call `actionIterateAttachedBitmaps` (filtered to the root's subtree) and the dynamic text walk inside `tag.c:7372 dyn_filter_root_draw`, and skip them in the normal pass to avoid double draws. | ~60-80 lines | 0 |

Not prototyped: everything above it was priced first, as the brief ordered. The ranking by game value is attachBitmap
and text first (common in AS2 games), then ColorMatrix fold, then DisplacementMap. All need a regression fixture with an
outside oracle (see LOCAL ORACLE REQUESTS of the s23 report; still open).

---

## Sweeps (graphics; each row compared to its CI baseline message)

- **Draw sweep, 20 rows, item 3 applied: 0 moves.** The rows: `avm2/bitmapdata_applyfilter_blur`,
  `_applyfilter_colormatrix`, `_colortransform`, `_draw`, `_draw_alpha_erase`, `_draw_colortransform`,
  `_draw_cpu_overwrite_gpu`, `_draw_filters`, `_draw_masks`, `_draw_rotation`, `_draw_self_via_graphic`, `_draw_stage`,
  `_drawwithquality` (low + high subtests), `_opaque`, `blend_multiply_alpha`, `blend_scroll`, `blend_transform`, and
  `from_shumway/acid/acid-bitmap-draw_quality_high`, `_quality_low`, `acid-bitmapData-draw`. Image messages are
  identical and every trace still passes.
- **Encode sweep, 4 rows (items 1+3): 0 moves.** `bitmapdata_encode_png_roundtrip`, `bitmapdata_encode_png_visual`,
  `bitmapdata_colortransform`; plus `bitmapdata_encode` (flip).
- **PixelBender sweep, 33 rows (items 1+2+3): 0 moves.** All 31 `avm2/pixelbender_*` + `shaderparameter_value` +
  `blend_shader_luma_lighten` + `visual/blend_modes/shader_as_mask`, `shader_without_shader`, traces and images.
- **Regression suite:** `avm2_bitmapdata_draw_textfield` and `avm1_parent_child_bitmap` PASS.

## Refutations

1. **"JPEG needs the `jpeg-encoder` crate / byte-exact output."** Refuted on both counts. Ruffle uses image-rs; the trace
   row reads only structure; the pixel golden is a Flash capture at tol 14. Any baseline encoder decodes within max 8.
2. **"The JPEG encoder is ~400 lines."** stb_image_write's encoder is vendored (~350 lines of header, already in-tree
   under `SWFRecomp/lib/stb`). The glue is ~70 lines. The real blocker found was `JPEGEncoderOptions` having **no
   constructor** (quality never stored).
3. **"`bitmapdata_draw_cab_quality` is a quality problem exposed by the alias."** Mostly refuted. 2480 of 2720 outliers
   are the **colorTransform dropped on vector sources** (a draw() gap since T5). The quality half is a tie rule in the
   aliased CPU path.
4. **"ShaderFilter + dithering ride together."** Refuted. The dithering rider's blocker is CPU bitmap-fill raster in
   draw(), not the filter.
5. **"The hairline tie-break could flip `shape_test`."** Refuted. Limit 0, and the floor is missing shapes. The tie is
   real (−3419 measured) but worth 0 flips.
6. **"Runtime CM/Convolution/DM filters draw nothing."** Partly refuted. The object draws unfiltered; Convolution is
   Ruffle-parity already.

## New unclaimed leads

1. **CPU bitmap-fill raster in `BitmapData.draw()`** (`avm2_cpu_raster_shape` skips fills 0x40-0x43). It blocks
   `pixelbender_dithering`, and is game-visible for any draw() of a timeline clip holding a bitmap (a very common
   AS3 idiom).
2. **`shape_test` missing shapes** (green glyph and bar; outlines of the red/black squares). Ruffle misses them too.
   A Ming-specific shape feature, worth a look for other Ming rows.
3. **ShaderFilter on non-Bitmap display objects** (Sprite or MovieClip sources). They need the filter-layer readback
   path or a CPU walk. No corpus row today.
4. **Vector draw() cxform/blend now real.** Any game doing `draw(sprite, m, tint)` was silently untinted before item 3.
   Worth a regression fixture with an outside oracle.

## LOCAL ORACLE REQUESTS

1. (Optional, for a wave-2 regression fixture of item 3's general case.) Ruffle exporter render (1 frame) of a tiny
   AS3 SWF: `bd.draw(shape, translate, new ColorTransform(0.5,1,0,1,0,0,128,0), "multiply")` onto an opaque grey
   BitmapData, with `draw()` at default quality (not drawWithQuality). The corpus row only exercises
   `ColorTransform(0,1,1)` + "difference" over black, which cannot distinguish blend order from cxform order. If no
   fixture is wanted, ignore this request.
