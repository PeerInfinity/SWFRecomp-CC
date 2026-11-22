# s24 w2-bitmap-encode-shader: JPEG encode (both modes), cached ShaderFilter on Bitmap, drawWithQuality

**NEW files**
- `SWFModernRuntime/lib/stb/stb_image_write.h` (verbatim copy of `SWFRecomp/lib/stb/stb_image_write.h`, v1.16, public domain)
- `SWFRecompDocs/plans/session24-fanout-reports/w2-bitmap-encode-shader-report.md` (this file)
- `SWFRecompDocs/plans/session24-fanout-reports/w2-bitmap-encode-shader.patch`
- `SWFRecompDocs/plans/session24-fanout-reports/w2-bitmap-encode-shader-probe/` (oracle-request sources only, NOT fixtures:
  `README.md`, `shaderfilter_cache/{Test.as,test.toml,output.txt,tintype.pbj}`, `draw_cxform_blend/{Test.as,test.toml}`)

The patch is `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`
(16 files, +2318/−44; ~1700 of the added lines are the vendored header). It applies on `origin/master` `9c86e930`, and
`git apply --check -R` passes on the branch tip.

Box: cloud, lavapipe. `SETUP_STATUS` all OK. Upstream tests at **`bcac30c19`** (`git ls-remote` at download time, which
is the s24 baseline). **Fidelity proven on all three pixel rows:** my clean-master renders are byte-identical to CI's
actual PNGs on `origin/ruffle-image-results`:

| row | md5 |
|---|---|
| `bitmapdata_draw_cab_quality` | `b1e924c4` |
| `bitmapdata_encode_jpeg_visual` | `95e908f8` |
| `pixelbender_effect_glassDisplace_shaderfilter` | `463f5983` |

So the absolute verdicts below are CI-grade.

## Verdict: GO. All 4 ledger flips reproduced, 0 moves elsewhere

### EXPECTED-FLIP LEDGER (for the coordinator's CI check)

| axis | test | before (= CI baseline `44965247383`) | after |
|---|---|---|---|
| **pixel** | `avm2/bitmapdata_encode_jpeg_visual` | fail: 28648 outliers / limit 0, max 128 (tol 14) | **pass**: 0, max 8 |
| **pixel** | `avm2/pixelbender_effect_glassDisplace_shaderfilter` | fail: 879464 / 380, max 255 | **pass**: 0, max 0 (byte-exact) |
| **pixel** | `avm2/bitmapdata_draw_cab_quality` | fail: 2720 / 80, max 255 | **pass**: 80 / 80, max 32 (zero headroom) |
| **trace** (graphics) | `avm2/bitmapdata_encode` | output_mismatch, 26/147 lines (`Error #2030`) | **pass** 147/147 |
| **trace** (no-graphics) | `avm2/bitmapdata_encode` | output_mismatch, 26/147 | **pass** 147/147 |

**Expected NON-flip move (report-only):** `avm2/pixelbender_dithering`, pixel, stays failing. It goes from 2764800
outliers, max 162, to 1297344, max 255, against a limit of 19929 (trace passes in both). This is the w1 rider. Its
blocker is the CPU bitmap-fill raster in `draw()` (out of scope, lead 1). The numbers are identical to the uncached w1
prototype's, which also shows the cache returns the same output.

**Everything else: md5-identical.** The before/after A/B covered 155 tests (186 PNG comparisons), the union of the
render canary and the three sweeps:
- 182 comparisons IDENTICAL, 4 DIFFER: the three ledger rows plus `pixelbender_dithering`.
- 0 appeared, 0 vanished.
- The only trace move is the `bitmapdata_encode` flip.

No-graphics mode: `tag_stubs.c` and the `NO_GRAPHICS` arms are untouched. But the encoder, the `BD_MUTATOR` wrappers and
the PNG-alpha rule now exist in both modes. So the **no-graphics leg belongs on the final grading run**: the
`bitmapdata_encode` flip is a no-graphics flip too.

## What the patch does (owner file:function)

### 1. JPEG encoder in BOTH modes (`avm2_bitmap.c`)

**The encoder**
- `stb_image_write.h` is compiled inside `avm2_bitmap.c` with `STB_IMAGE_WRITE_STATIC` + `STB_IMAGE_WRITE_IMPLEMENTATION`,
  wrapped in `-Wunused-function` pragmas. The symbols are static, so they cannot clash with `render_webgpu.c`'s extern
  copy.
- I dropped `STBI_WRITE_NO_STDIO`: with it, stb leaves `stbi_write_hdr_to_func` declared-static-but-undefined, which is a
  warning. The stdio writers are static and unused.
- `-Wall -Wextra` is clean in both modes, apart from the pre-existing misleading-indentation warnings at l.254.

**Behaviour, kept exactly from the w1 prototype**
- `bd_encode_jpeg` encodes the premultiplied colour as RGB.
- Quality above 100 raises RangeError #2006; quality 0 is treated as 1. Above 65500 px on either side raises #3699.
- `jpeg_options_init` stores `quality:uint = 80`. The class had no constructor, so every encode ran at quality 1.
- Null rect and null compressor both raise #2007, before the empty-rect #2006. A wrong compressor type raises #2004.
- JPEGXR returns null.
- PNG writes an alpha channel only if the region has a non-opaque pixel.

**Build wiring**
- The header is copied next to `stb_image.h` in:
  - `verify_output.py` (both copy sites, l.2779 and l.3346);
  - `build_test.sh` (×2);
  - `build_graphics_host.sh`;
  - `build_wasm_avm2.sh` (the Emscripten AVM2 build; its `-I${SRC_DIR}` is the include path);
  - `deploy_wasm_demo.sh` (it stages `RT/lib/stb` for the runtime-snapshot bundle);
  - `wasm_wrappers/bundle/build.sh`;
  - `profile_game_native.sh`.
- `SWFModernRuntime/CMakeLists.txt` gains `lib/stb` as an include dir.
- **Not built here:** there is no emsdk in the cloud. The wasm scripts were edited by inspection only (one `cp` line
  each). The next `deploy-pages.yml` dry run is the check: the in-browser recompiler bundle is touched, so CLAUDE.md
  authorizes a Pages deploy after landing.

### 2. ShaderFilter on Bitmap, cached (`avm2_display.c`, `avm2_pixelbender.c`, `avm2_bitmap.c`, `avm2_globals.h`)

**Version counter (new)**
- `Avm2BitmapDataExt` gains a trailing field, `uint64_t version`.
- `avm2_bitmapdata_touch(bd)` stamps it from one **global monotonic clock**, so an `(ext, version)` pair never repeats,
  even after a free and a reallocation at the same address.
- Touched on every write path:
  - every receiver-writing BitmapData method, through the `BD_MUTATOR` wrapper at registration. The bump runs **before**
    the call, so a throw part-way through a write is covered. The methods are: setPixel, setPixel32, fillRect, dispose,
    noise, setPixels, setVector, copyPixels, floodFill, threshold, pixelDissolve, colorTransform, copyChannel, scroll,
    **lock, unlock**, draw, drawWithQuality, applyFilter, merge, paletteMap, perlinNoise;
  - `bd_alloc`, `bd_seed_embedded` and `bitmapdata_native_init`;
  - the ShaderJob target writeback (`pb_run_job`);
  - Stage3D `drawToBitmapData` (`avm2_stage3d.c`, one line).
- I grepped every `avm2_bitmapdata_ext_of` user outside `avm2_bitmap.c`. The rest only read pixels: the gfx bitmap-fill
  snapshot, Stage3D `uploadFromBitmapData`, the displacement map, and shader inputs.

**Shader-parameter generation (new)**
- `g_pb_param_gen` is bumped by `ShaderParameter.value`, `ShaderInput.{input,width,height}` and `ShaderFilter.shader`
  writes.
- `avm2_pixelbender_filter_stamp(ctx, shader)` hashes that generation, the shader/data identity, and the identity +
  version of every image input other than input 0.
- A ByteArray or Vector image input has no version. It returns 0, meaning uncacheable, and that chain reruns every frame.

**The cache**
- A side table `Avm2SfCache` with one entry per display object.
- The key is the source ext, the pixel pointer, w/h, the version, and the combined stamp of every ShaderFilter in the list
  plus its extensions.
- `clear_filters` drops the owner's entry, so a `filters` reassignment and the GC free path (`avm2_display_gc_free_ext`)
  both invalidate it. No pointer is ever reused stale.
- Measured: `glassDisplace_shaderfilter` ran the shader **once over 11 renders**. That was a temporary probe, now removed.

**Extensions**
- Each ShaderFilter's target is `(l+w+r) × (t+h+b)`, and output pixel (x, y) evaluates `outCoord` at source
  `(x−l+0.5, y−t+0.5)`.
- The new `g_pb_out_off_x/y` carries that offset into `pb_run_job`.
- The quad is drawn at local `(−l, −t)` px, through `renderer_draw_bitmap_quad_scaled`'s x/y twips.
- Several ShaderFilters chain in list order.
- Ruffle **ignores** extensions: `render/wgpu/src/filters/shader.rs` uses a source-sized target, and `calculate_dest_rect`
  returns the source rect for a ShaderFilter.
- **No corpus row sets an extension** (grepped every `Test.as`), so this arm is unmeasured. If Flash's coordinate
  convention differs, only extension users move. That needs a Flash oracle; it is not a pass/fail risk today.

**Robustness**
- `pb_run_job` now returns its error code. In filter mode it **never throws**, because it runs from the render walk.
  `avm2_pixelbender_run_filter(ctx, shader, src, dst, off_x, off_y)` returns 0 and the Bitmap draws unfiltered.
- The `sj_start` behaviour is unchanged; it still throws.

**Scope limits**
- Non-Bitmap sources (a Sprite or MovieClip with a ShaderFilter) **stay unfiltered**, because `avm2_filter_renderable`
  still drops the kind. They would need the GPU filter layer's readback; no corpus row has one. This is documented at
  `sf_bitmap_output`.
- `applyFilter(ShaderFilter)` keeps the measured prototype arm, with the whole source per Ruffle (`bd_apply_filter`).

### 3. `drawWithQuality` vector cxform/blend + explicit quality + top-left rule

This is exactly the measured prototype (`bd_draw`, `avm2_cpu_raster.c raster_tri` with `cpu_tl_edge_owns`).
- `draw()` without arg 6 keeps the s22 AA-at-LOW ruling.
- `avm2/bitmapdata_drawwithquality` (both subtests) and every draw-sweep row are md5-identical.
- I updated the stale registration comment on `drawWithQuality`.

### 4. Canary (`ruffle-tests/render_canary_tests.txt`, appended at EOF)

`avm2/bitmapdata_encode_jpeg_visual` and `avm2/pixelbender_effect_glassDisplace_shaderfilter` are added, both tier 1:
they pass after the patch, and their before legs are md5 = CI actual. The third member the w1 report named,
`avm2/bitmapdata_draw_cab_quality`, is **already** in the set (s23 harness-subtests block, `tier=2`), so I did not
duplicate it; the appended comment says so. Its tier could move to 1 once CI confirms the pass, with zero headroom. The
coordinator decides that, because it means editing a non-EOF line.

## Sweeps and canary A/B (graphics; clean `origin/master` vs patch, same box, md5)

All of these were one 155-test before/after capture (`render_canary.py capture/compare`):

| set | rows | result |
|---|---|---|
| render canary (full standing list incl. the 2 new members) | 105 | md5-identical except the ledger rows |
| draw sweep (w1 list) | 20 | 0 moves, except the ledger's `bitmapdata_draw_cab_quality` |
| encode sweep (w1 list) | 4 | 0 moves, except the `bitmapdata_encode` and `encode_jpeg_visual` flips |
| PixelBender sweep (31 `pixelbender_*` + `shaderparameter_value` + `blend_shader_luma_lighten` + `visual/blend_modes/shader_as_mask`, `shader_without_shader`) | 35 | 0 moves, except the ledger's `glassDisplace_shaderfilter` and the rider `pixelbender_dithering` (fail→fail) |

Notes on the capture:
- Pre-existing non-pass trace rows were unchanged: `blend_transform`, `graphics_draw_path` and `acid-textfield` are
  ruffle_matched in both legs.
- **Regression suite:** all 9 `regression/` rows in the capture PASS in both legs, md5-identical:
  `avm1_parent_child_bitmap`, `avm1_runtime_filters`, `avm2_bitmapdata_draw_textfield`, `avm2_graphics_runtime`,
  `avm2_morph`, `avm2_timeline_gradients`, `avm2_timeline_stroke_gradient`, `mask_nested_intersect`,
  `mask_sibling_union`.

No-graphics, after the patch: all of these PASS.
- `bitmapdata_encode` (flip), `bitmapdata_encode_png_roundtrip`, `bitmapdata_encode_png_visual`,
  `bitmapdata_colortransform`;
- `bitmapdata_draw_cab_quality`, `bitmapdata_drawwithquality`;
- `pixelbender_dithering`, `pixelbender_effect_glassDisplace_shaderfilter`, `bitmapdata_encode_jpeg_visual`.

### Per-test before/after (headline rows)

| test | mode | before | after | PNG md5 before → after |
|---|---|---|---|---|
| `avm2/bitmapdata_encode` | graphics | output_mismatch 26/147 | **pass 147/147** | n/a |
| `avm2/bitmapdata_encode` | no-graphics | output_mismatch 26/147 | **pass 147/147** | n/a |
| `avm2/bitmapdata_encode_jpeg_visual` | graphics | trace pass; image fail 28648 | trace pass; **image pass 0** | `95e908f8` → `27f06721` |
| `avm2/pixelbender_effect_glassDisplace_shaderfilter` | graphics | trace pass 4/4; image fail 879464 | trace pass; **image pass 0, max 0** | `463f5983` → `e4478c93` |
| `avm2/bitmapdata_draw_cab_quality` | graphics | image fail 2720 | **image pass 80/80** | `b1e924c4` → `5e2d50ed` |
| `avm2/pixelbender_dithering` (rider) | graphics | image fail 2764800 | image fail 1297344 | `e82679c9` → `3153e740` |

## Refutations / premise checks

1. **"Cache on a shader-parameter generation."** This is correct for the Flash model, and Ruffle agrees on why it is
   sufficient. Ruffle snapshots the shader args when `filters` is assigned (`core/src/avm2/filters.rs`
   `avm2_to_shader_filter` → `get_shader_args`), so a parameter change without reassigning does not reach the display.
   Our runtime reads the live shader, so a param write without a reassign now shows up on the next source change or
   param write.
   - That is a pre-existing divergence, not new: the uncached prototype showed it every frame.
   - It is exercised by no corpus row. The `shaderfilter_cache` probe reassigns, so it avoids the ambiguity.
2. **"Extensions matter for the flip."** Refuted. No corpus row sets them, and Ruffle ignores them. They are implemented
   for Flash-shaped content only (see §2).
3. **"Static stb symbols clash with render_webgpu.c."** No clash. The symbols are static in a different TU, and the
   graphics build links and passes all 186 comparisons.

## Not finished / completion mechanisms

- **No regression fixture for the cache invalidation or the vector draw() cxform+blend.** Both need an outside oracle and
  an AS3 compiler, and neither exists in the cloud. The sources are written (see LOCAL ORACLE REQUESTS).
  - Completion: the coordinator compiles with mxmlc, exports with Ruffle, and moves the dirs into `regression/`.
- **Wasm/Pages build not exercised** (no emsdk here). Completion: `gh workflow run deploy-pages.yml --ref master -f
  dry_run=true` after landing.
- **The ShaderFilter extension coordinate convention is unverified against Flash.** No oracle; 0 corpus rows.
- `bitmapdata_draw_cab_quality` has zero headroom (80/80, from the stage-rendered MSAA top triangle). Any stage-raster
  change on that row breaks it, which is why it is a canary member.

## New unclaimed leads

1. ShaderFilter on non-Bitmap display objects (GPU filter-layer readback or a CPU walk). No corpus row. Unchanged from w1.
2. `pixelbender_dithering` needs the CPU bitmap-fill arm in `avm2_cpu_raster_shape` (w1 lead 1; out of scope here).
3. `Avm2BitmapDataExt.version` is now a general-purpose dirty stamp. The renderer re-uploads every Bitmap's pixels every
   frame (`render_webgpu_draw_bitmap_quad_scaled` converts + uploads per draw). Keying a GPU texture cache on the version
   is a perf lead for blitting games.
4. The ShaderJob target writeback stores **straight** alpha into the premultiplied pixel store, and the ShaderFilter path
   inherits it. It is byte-exact on the opaque corpus row. A translucent ShaderFilter source would show whether Flash
   premultiplies there.

## LOCAL ORACLE REQUESTS

Sources are in `SWFRecompDocs/plans/session24-fanout-reports/w2-bitmap-encode-shader-probe/`; build commands are in its
`README.md`.

1. **`shaderfilter_cache/`**: compile `Test.as`; it embeds `tintype.pbj`, copied from
   `avm2/pixelbender_effect_tintype`.
   - Ruffle exporter, 10 ticks: the trace (expected by construction in `output.txt`) and the last-frame PNG
     → `output.expected.png`.
   - It exercises fillRect, setPixel, lock/setPixel32/unlock, a vector draw, a param change + `filters` reassign, and
     copyPixels on a ShaderFilter'd Bitmap.
   - Land it as `regression/avm2_shaderfilter_cache`.
2. **`draw_cxform_blend/`**: this is the w1 request (vector `draw()` with a ColorTransform + multiply/add/normal over
   opaque grey, at default quality).
   - Ruffle exporter, 1 tick: the trace (getPixel values) → `output.txt`, and the PNG → `output.expected.png`.
   - Land it as `regression/avm2_bitmapdata_draw_cxform_blend`.
