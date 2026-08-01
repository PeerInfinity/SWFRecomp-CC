# Pixel axis — the `size_mismatch` cluster (12 failures)

Diagnosis only. No source edited, nothing committed. Data from the
`c146dc66e` image baseline (run 30604886586), the per-suite
`_results/image_results_graphics.json`, our CI renders fetched from the
`ruffle-image-results` branch, and the upstream expected PNGs at
`~/CC/ruffle/tests/tests/swfs/` (not in this repo).

## TL;DR

The harness never tells the runtime how big to render. `main.c` sets the
render target to the **SWF header stage size**; Ruffle renders at
`[player_options] viewport_dimensions`. When a test declares a viewport that
differs from the movie box, our PNG comes out the wrong size and the
comparison short-circuits before a single channel is read.

The cluster is exactly, provably, 12 tests: **every** test in the corpus whose
`viewport_dimensions` differs from its movie size AND which has
`[image_comparisons]` is in the cluster, and nothing else is. 9 are exactly
2x; 3 are `550x400 → 600x700` (aspect change → Ruffle letterboxes).

Fixing it will move all 12 out of the `size_mismatch` bin and into a real
magnitude band. It will most likely convert **0–1 of them into passes** — the
1x sibling of nearly every one of these tests already fails its own image
comparison with the same content, so the size mismatch is masking a second,
independent defect in each case. Trace blast radius is **zero** if the fix
adds new fields rather than repurposing `app_context.width`.

## 1. The 12 tests

Confirmed by scanning every `_results/image_results_graphics.json` for a
`size_mismatch` message: exactly 12, all `status=fail`, none marked
`known_failure`, 11 of 12 trace-**pass**.

`proxy_out` = outliers if you take our CI 1x render, nearest-neighbour it to
the fitted sub-rect, centre it on the expected canvas, and compare at the
test's own tolerance. That is an *upper bound* on the post-fix error (a true
re-render at 2x rasterises vectors and glyphs crisply; NN upscaling does not),
and a *lower* bound is not available without building the fix.

| test | ours | expected | ratio | ShowAll fit | centre offset | tol | budget | proxy_out | proxy % | proxy band |
|---|---|---|---|---|---|---:|---:|---:|---:|---|
| `avm2/edittext_get_char_index_at_point` | 400x400 | 800x800 | 2.000x2.000 | 2.0000 | (0,0) | 0 | 0 | 68237 | 2.67% | d_moderate |
| `avm2/pixelbender_effect_BlurredFocus` | 550x400 | 600x700 | 1.091x1.750 | 1.0909 | (0,132) | 3 | 1003 | 216786 | 12.90% | e_large |
| `avm2/pixelbender_effect_glassDisplace` | 550x400 | 600x700 | 1.091x1.750 | 1.0909 | (0,132) | 3 | 1003 | 747789 | 44.51% | e_large |
| `avm2/pixelbender_effect_twirl` | 550x400 | 600x700 | 1.091x1.750 | 1.0909 | (0,132) | 3 | 1003 | 754200 | 44.89% | e_large |
| `avm2/stage_scale_factor` | 550x400 | 1100x800 | 2.000x2.000 | 2.0000 | (0,0) | 1 | 0 | 1912924 | 54.34% | f_catastrophic |
| `visual/edittext/edittext_background_basic_scale2` | 100x100 | 200x200 | 2.000x2.000 | 2.0000 | (0,0) | 0 | 0 | 8984 | 5.62% | d_moderate |
| `visual/edittext/edittext_border_basic_scale2` | 100x100 | 200x200 | 2.000x2.000 | 2.0000 | (0,0) | 0 | 0 | 8031 | 5.02% | d_moderate |
| `visual/edittext/edittext_underline_scale2` | 900x300 | 1800x600 | 2.000x2.000 | 2.0000 | (0,0) | 0 | 16 | 27660 | 0.64% | c_small |
| `visual/filters/any_blur_scales_with_screen` | 80x80 | 160x160 | 2.000x2.000 | 2.0000 | (0,0) | 2 | 0 | 13432 | 13.12% | e_large |
| `visual/filters/blur_scales_with_screen` | 200x200 | 400x400 | 2.000x2.000 | 2.0000 | (0,0) | 2 | 0 | 69242 | 10.82% | e_large |
| `visual/filters/displacement_map_scales_with_screen` | 400x200 | 800x400 | 2.000x2.000 | 2.0000 | (0,0) | 4 | 0 | 99353 | 7.76% | d_moderate |
| `visual/filters/drop_shadow_scales_with_screen` | 400x200 | 800x400 | 2.000x2.000 | 2.0000 | (0,0) | 2 | 0 | 47926 | 3.74% | d_moderate |

**9 exactly 2x, 3 not.** The 3 exceptions are the `pixelbender_effect_*`
family (`550x400` movie, `600x700` viewport). They are not a second bug: they
are the same bug with a non-matching aspect ratio, which is where Ruffle's
ShowAll letterboxing shows up.

Sizes: **ours == the SWF header frame size in all 12** (verified by parsing
each `test.swf` RECT); **expected == `viewport_dimensions` width/height in all
12** (verified against each `test.toml` and against the real PNG headers). The
JSON carries both under `stats.actual_size` / `stats.expected_size` plus the
message string.

### The 3 non-2x ones are letterboxed, and the geometry checks out

`avm2/pixelbender_effect_twirl` declares `viewport 600x700`, movie `550x400`.
Ruffle ShowAll scale = `min(600/550, 700/400) = 1.0909`; fitted content
`600 x 436.36`; top bar `(700-436.36)/2 = 131.8`. The expected PNG has
**132 solid rows at the top, all one colour** — measured directly. Same for
the other two. Confirms scale mode ShowAll + default (centre) align.

The margin is a single uniform colour (stage background), **not** black bars:
Ruffle's default is `Letterbox::Fullscreen` and `should_letterbox()` requires
`Letterbox::On` or actual fullscreen, so in tests the margin is not clipped —
content positioned outside the movie box **is** drawn there. This matters for
the fix (see §3, rejected alternative).

## 2. Where it breaks

Traced end to end:

1. `ruffle-tests/verify_output.py:190 get_viewport_dimensions()` parses
   `viewport_dimensions` and at `:2313-2319` emits `-DVIEWPORT_WIDTH`,
   `-DVIEWPORT_HEIGHT`, `-DVIEWPORT_SCALE_FACTOR` onto **every** gcc
   invocation for the test (the whole runtime is compiled per-test into the
   build dir, so these defines are visible in `render_webgpu.c`, `tag.c`,
   `main.c` — not just the generated scripts).
2. Those three defines are consumed in exactly **three** places, all
   AS-visible, **none** of them the renderer:
   - `SWFModernRuntime/src/actionmodern/action.c:48347` — AVM1 `Stage.width/height`
   - `SWFModernRuntime/src/avm2/avm2_globals.c:2052` — `Capabilities.screenResolutionX/Y` (divided by `VIEWPORT_SCALE_FACTOR`)
   - `SWFModernRuntime/src/actionmodern/action.c:8836` — `pixel_ratio = VIEWPORT_WIDTH / FRAME_WIDTH` for `_xmouse`/`_ymouse`
3. The render target size comes from a different path entirely:
   `SWFRecomp/wasm_wrappers/main.c:110-111`
   ```c
   app_context.width  = FRAME_WIDTH;    // SWF header, px
   app_context.height = FRAME_HEIGHT;
   ```
   `FRAME_WIDTH` is emitted into the per-test `constants.h` by
   `SWFRecomp/src/swf.cpp:486` from the SWF header RECT.
4. `SWFModernRuntime/src/libswf/swf.c:1481` (`swfStart`, AVM1) and
   `SWFModernRuntime/src/avm2/avm2_display.c:14111` (`avm2_render_init`, AVM2)
   copy it: `context->width = app_context->width;`
5. `render_webgpu.c` sizes **everything** off `ctx->width/height`: the
   offscreen colour texture (`:882`), readback stride (`:892`), MSAA and
   depth/stencil (`:1238,:1256,:3081`), filter textures (`:3061`), the
   texture→buffer copy (`:2631,:2654`), and finally
   `render_webgpu_save_png` (`:3655,:3677`), which writes the PNG at
   `ctx->width x ctx->height`.

So: **`get_scale_factor` is a red herring for this cluster.** It only feeds
`preprocess_input_json` (`:563-585`, dividing mouse coordinates) and the
`Capabilities` define. The viewport *dimensions* are already parsed and
already passed to the compiler — they simply never reach the render target.
The gap is the missing link between `VIEWPORT_WIDTH/HEIGHT` and
`app_context.width/height`, plus the missing stage-fit transform.

Note also that the `scale_factor` field is **not** the multiplier here.
`edittext_get_char_index_at_point` has `scale_factor = 1.0` and still needs a
2x render, because its viewport is `800x800` over a `400x400` movie. Ruffle's
`viewport_dimensions.width/height` are physical pixels; `scale_factor` is only
the HiDPI divisor for logical coordinates. The render target is always
`width x height`.

### Reproduced locally

```
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/visual \
    --test=edittext/edittext_background_basic_scale2 --mode=graphics --diff --verbose
→ [image:output] FAIL - Image size mismatch: actual 100x100, expected 200x200
  PASS [r=0.00s c=2.93s x=0.80s]
```
Trace PASS, image FAIL — the two axes, exactly as documented. The kept build
dir confirms `constants.h` has `FRAME_WIDTH 100` while the test.toml viewport
is 200x200.

## 3. Fix design

Model to reproduce (Ruffle `core/src/display_object/stage.rs::build_matrices`):

```
s  = min(VW/FW, VH/FH)              # ShowAll, uniform
nw, nh = FW*s, FH*s                 # fitted content size, device px
ox, oy = (VW-nw)/2, (VH-nh)/2       # StageAlign default = centre
render target = VW x VH             # not nw x nh — margins are stage bg, not clipped
```

Because the align is centred, the NDC form collapses to a pure scale with no
translation: with `kx = nw/VW`, `ky = nh/VH`, the new projection is just
`row0 *= kx, row1 *= ky` on the emitted `stage_to_ndc`. (Derivation: NDC'
= 2(ox + p·s)/VW − 1 with p = (NDC+1)·FW/2 gives `NDC' = kx·NDC + (2ox/VW +
kx − 1)`, and the bracket is identically 0 when `ox = (VW−nw)/2`.) For the 9
uniform-2x tests `kx = ky = 1` and the projection is unchanged — only the
target size and the filter scale change.

### Changes

1. **`SWFModernRuntime/include/libswf/swf.h`** (`struct SWFAppContext`, inside
   the existing `#ifndef NO_GRAPHICS` block next to `width`/`height`, line
   ~304): add `int render_width, render_height; float stage_scale;`.
   **Leave `width`/`height` meaning stage pixels.** That is load-bearing — see
   the blast-radius note below.

2. **`SWFRecomp/wasm_wrappers/main.c`** (the `#ifndef NO_GRAPHICS` block at
   :109). Keep `app_context.width/height = FRAME_WIDTH/FRAME_HEIGHT`, and add,
   under `#if defined(VIEWPORT_WIDTH) && defined(VIEWPORT_HEIGHT)`:
   - compute `s`, `kx`, `ky` as above;
   - `app_context.render_width/height = VIEWPORT_WIDTH/HEIGHT`;
   - `app_context.stage_scale = s`;
   - `memcpy` the const `stage_to_ndc` into a file-static mutable `float
     fit_stage_to_ndc[16]`, scale indices `{0,4,8,12}` by `kx` and
     `{1,5,9,13}` by `ky`, and point `app_context.stage_to_ndc` at it.
   `#else` branch: `render_* = FRAME_*`, `stage_scale = 1.0f`, `stage_to_ndc`
   unchanged. Browser/game/host builds never define `VIEWPORT_*`, so they
   compile byte-identically.

3. **`SWFModernRuntime/include/rendering/render_webgpu.h`**: add
   `float stage_scale;` to `WebGPURenderContext`. `ctx->width/height` keep
   their existing meaning and become the *render target*.

4. **`SWFModernRuntime/src/libswf/swf.c:1481-1482` (`swfStart`)** and
   **`SWFModernRuntime/src/avm2/avm2_display.c:14111-14112`
   (`avm2_render_init`)**: copy `render_width/render_height` into
   `context->width/height` and `stage_scale` into `context->stage_scale`.
   Leave `avm2_display.c:14136` (`maxdim` for the dynamic bitmap layer) on
   `app->width/height` — that budget is in stage pixels and should not inflate.
   *This step alone eliminates all 12 size mismatches.*

5. **`SWFModernRuntime/src/rendering/render_webgpu.c::render_webgpu_run_blur`
   (:3346-3360)**: the kernel radius is in **target** pixels (`texel_w =
   1/ctx->width`, `radius = blur_x*0.5`). Multiply `blur_x`/`blur_y` by
   `ctx->stage_scale` before the halving. Flash filter sizes are in the
   filtered object's coordinate space and scale with the concatenated matrix —
   which is precisely what the four `*_scales_with_screen` tests assert.
   Without this, a 2x render halves the apparent blur.

6. **`SWFModernRuntime/src/libswf/tag.c:5217-5218, 5227-5228, 6180-6181,
   6196-6197`**: drop-shadow / bevel composite offsets are computed as
   `dist_px * 2 / app_context->width`, i.e. an offset in the *target* NDC of
   the full-screen filter quad. The correct value is that times `kx`/`ky`.
   For all 9 uniform-fit tests `kx = ky = 1`, so this is a no-op today; it is
   needed for the 3 pixelbender ones and for correctness in general. (Note:
   `app_context->width` here is being used as a stand-in for `FRAME_WIDTH`,
   which is another reason not to repurpose that field.)

7. **No change to `verify_output.py`.** It already emits the defines and
   already compares whatever PNG the runtime writes. `get_scale_factor` and
   `preprocess_input_json` stay as they are: only 2 of the 16 viewport tests
   ship an `input.json` (`avm2/stage_scale_factor`,
   `avm1/mouse_pos_with_scale_factor`) and in both the ShowAll fit equals the
   declared `scale_factor` (2.0), so dividing by `scale_factor` is currently
   correct. That is a coincidence, not a design — a future test with
   `fit != scale_factor` and mouse input would need
   `preprocess_input_json` to divide by the fit instead. Worth a comment, not
   a change.

### Rejected alternative

Setting `wgpuRenderPassEncoderSetViewport()` to the fitted sub-rect is a
smaller diff but **wrong**: Ruffle's tests run with `should_letterbox() ==
false`, so its `view_bounds` are *extended* into the margins and content
outside the movie box is drawn there. `SetViewport` clips instead. Baking the
fit into `stage_to_ndc` reproduces the no-clip behaviour for free.

## 4. Predicted outcome

**All 12 leave `size_mismatch` and reach a real pixel comparison.** The
histogram's `size_mismatch: 12` bin empties into the graded bands (the proxy
puts them at c_small ×1, d_moderate ×5, e_large ×5, f_catastrophic ×1). The
566-comparison denominator does not change.

**Predicted new passes: 0, with one coin-flip.** The evidence is that the
1x sibling of essentially every one of these tests already fails its own image
comparison on the same content and the same or a looser tolerance:

| cluster member | 1x sibling already in the corpus | sibling verdict |
|---|---|---|
| `edittext_background_basic_scale2` | `visual/edittext/edittext_background_basic` | fail, 2269 outliers / budget 0 @ tol 0 |
| `edittext_border_basic_scale2` | `visual/edittext/edittext_border_basic` | fail, 2046 / 0 @ tol 0 |
| `edittext_underline_scale2` | `visual/edittext/edittext_underline` | fail, 13818 / 0 @ tol 144 |
| `blur_scales_with_screen`, `any_blur_scales_with_screen` | `filters/blur_quality`, `blur_fractional`, `blur_size_grows`, `blur_pass_scaling` | fail, 821415 / 774090 / 110813 / 173904 |
| `drop_shadow_scales_with_screen` | `filters/drop_shadow`, `drop_shadow_angles` | fail, 122356 / 0 @ tol 2; 143915 |
| `displacement_map_scales_with_screen` | `filters/displacement_map` | fail, 122650 / 160 @ tol 32 |
| `edittext_get_char_index_at_point` | the whole `avm2/edittext_*` family | all fail (1440 … 22217) |
| `pixelbender_effect_glassDisplace` | `pixelbender_effect_glassDisplace_shaderfilter` | fail, 879464 / 380 |

Two members deserve individual calls:

- **`avm2/pixelbender_effect_BlurredFocus` is the one plausible pass.** Its
  sibling shaders `pixelbender_effect_smudge`, `_tintype`, `pixelbender_images`
  and `pixelbender_malformed_data` all **pass** at `max_diff <= 1`, and a
  resolution-independent check (box-downscale the expected into the fitted
  rect, compare to our 1x render) puts our content at a mean channel error of
  **0.12** with p99 = 3 = its own tolerance. It still shows 7175 outliers
  against a 1003 budget in that proxy, so call it a coin flip — but it is the
  only member whose *content* looks right.
- **`avm2/stage_scale_factor` will stay catastrophic and is not really this
  cluster's problem.** It is the one member that also trace-fails
  (`output_mismatch`), it sets `stage.scaleMode = "noScale"` (a different
  `build_matrices` branch — which happens to give the same 2x here) and
  `stage.transform.matrix = Matrix(1.5,0,0,1,10,100)`, and it drives
  Stage3D/AGAL. Three unimplemented things stacked on top of the sizing bug.

So the honest framing: **this is a measurement fix, not a pass fix.** Its
value is (a) 12 blind failures become 12 measurable ones with usable
magnitudes and dashboard thumbnails, and (b) step 5 makes the four
`*_scales_with_screen` tests actually exercise the filter-size-vs-stage-scale
path they were written for, which today is completely untested in our corpus —
that is a real, currently-invisible correctness gap in the filter pipeline.

### Blast radius

**Trace: zero, by construction.** Image comparisons never gate trace status
(re-confirmed by the local run above: image FAIL, test PASS). Beyond that, the
design keeps `app_context.width/height` meaning stage pixels, so nothing that
currently reads them changes value. There are exactly **4** call sites
(`swf.c:1481`, `avm2_display.c:14111`, `avm2_display.c:14136`, and the four
`tag.c` filter-offset lines) — small enough to audit by eye. `Stage.width`,
`Capabilities.screenResolution*` and `_xmouse`'s `pixel_ratio` read the
`VIEWPORT_*` defines directly and are untouched.

**Render: bounded and enumerable.** Exactly 16 tests in the whole corpus
declare a `viewport_dimensions` differing from their movie size — the 12 above
plus 4 trace-only tests with no image comparison
(`avm1/capabilities_resolution`, `avm2/capabilities_resolution`,
`avm1/stage_scale_mode`, `avm1/mouse_pos_with_scale_factor`). Those 4 all
currently trace-pass and read only the defines, so they are unaffected. Every
other test in the corpus has `kx = ky = 1` and `render_* == FRAME_*`, making
the whole change a compile-time no-op for them.

**The one way to create a real regression** is to repurpose
`app_context.width` as the render-target size instead of adding new fields.
That would silently change the drop-shadow/bevel NDC offsets in `tag.c` for
every filtered test in the corpus (render-only, still not trace-visible, but
it would move the 32-test Filters family for no reason). Don't do that.

**Cost:** the largest member renders at 1800x600 with 4x MSAA plus filter
textures — ~4x the pixels of today for 9 tests. Negligible against a
566-comparison run.
