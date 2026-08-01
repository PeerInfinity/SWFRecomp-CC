# Viewport render-scaling fix — implementation report

Implements the 7-point plan in `reports/pixel-viewport.md`. Patch:
`patches/viewport.patch` (13 files, +170/−17). Worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a60ee9d15b95c4e06`,
nothing committed, nothing pushed.

## TL;DR

The fix works and is a **true no-op** where it should be. All 4 cluster tests
sampled now render at the declared viewport size and reach a real pixel
comparison; all 4 non-cluster tests are **byte-identical** PNGs (same SHA-256,
same outlier count) before and after. **Trace: 16/16 runs PASS, zero lines
changed.** The non-uniform-aspect (letterbox) path was verified exactly, not
just by size.

## What changed

| file | change |
|---|---|
| `SWFModernRuntime/include/libswf/swf.h` | `SWFAppContext` += `render_width`, `render_height`, `stage_scale`, `stage_fit_x`, `stage_fit_y` (inside the existing `#ifndef NO_GRAPHICS`). `width`/`height` keep meaning **stage** pixels. |
| `SWFRecomp/wasm_wrappers/main.c` | Under `#if defined(VIEWPORT_WIDTH) && defined(VIEWPORT_HEIGHT)`: compute ShowAll `s`, `kx`, `ky`; set the new fields; `memcpy` `stage_to_ndc` into a file-static `fit_stage_to_ndc[16]`, scale `{0,4,8,12}` by `kx` and `{1,5,9,13}` by `ky`, repoint `app_context.stage_to_ndc`. `#else` sets render_* = FRAME_*, all factors 1.0f. Also `#include <string.h>` (memcpy was previously only pulled in inside the `__EMSCRIPTEN__` block). |
| `SWFModernRuntime/include/rendering/render_webgpu.h`, `include/flashbang/flashbang.h` | `+ float stage_scale;` |
| `SWFModernRuntime/src/libswf/swf.c` (`swfStart`) | `context->width/height` now come from `render_width/height`; `context->stage_scale` copied. |
| `SWFModernRuntime/src/avm2/avm2_display.c` (`avm2_render_init`) | same. `maxdim` for the dynamic bitmap layer deliberately left on `app->width/height` (stage pixels). |
| `SWFModernRuntime/src/rendering/render_webgpu.c` (`render_webgpu_run_blur`) | `radius_{x,y} = blur_{x,y} * ctx->stage_scale * 0.5f`. |
| `SWFModernRuntime/src/libswf/tag.c` | The 4 drop-shadow/bevel NDC offset sites (2 in `tagRerenderFrame`, 2 in `tagShowFrame`) multiplied by `stage_fit_x`/`stage_fit_y`. |
| `SWFRecomp/tests/graphics/{mess,wild_shadow,awful_gradient,awful_radial_gradient}/main.c` | Explicitly initialise the 5 new fields. |
| `ruffle-tests/verify_output.py` | **Comment only** (the design's step 7): documents that `preprocess_input_json` divides mouse coords by `scale_factor` where it should divide by the ShowAll fit, and that the two agree today only by coincidence. No behaviour change. |

## Deviations from the design

1. **Two extra fields, `stage_fit_x` / `stage_fit_y`, instead of having `tag.c`
   re-derive `kx`/`ky`.** `tag.c` would otherwise have to compute
   `width * stage_scale / render_width`, which reads three fields that some
   `SWFAppContext` producers never set. Storing `kx`/`ky` once, next to the
   thing that computed them, is both cheaper and safer.
2. **`swfStart` / `avm2_render_init` use `render_width > 0 ? … : width`
   fallbacks** rather than an unconditional copy. `SWFRecomp/wasm_wrappers/`
   `host_main_graphics.c` and `display_bridge.c` use a zero-initialised global
   `app_context` and never set the new fields; the fallback keeps them on the
   stage size instead of a 0×0 render target. Same for `stage_scale > 0.0f`.
3. **The four `SWFRecomp/tests/graphics/*/main.c` were patched too.** Those use
   an **uninitialised local** `SWFAppContext`, so the fallback in (2) would read
   garbage rather than zero. Three lines each; not in Ruffle CI, but it would
   have been a latent crash in `SWFRecomp/tests`.
4. **`float stage_scale` added to `FlashbangContext` as well.** `swfStart`
   writes `context->stage_scale` through the `RenderContext` typedef from
   `renderer.h`, which is `FlashbangContext` in non-`USE_WEBGPU` builds.
5. `SetViewport` was **not** used, per the design's rejected alternative — the
   fit is baked into the projection so the margins stay unclipped.
6. **`docs/recompiler/runtime_src/main.c` and
   `docs/recompiler/runtime_headers/include_libswf_swf.h` were left alone.**
   They are a self-consistent deployed snapshot pair for the web recompiler; if
   someone re-syncs them they must be re-synced together anyway.

## Results — the 4 cluster tests

`--mode=graphics`, one test at a time, kept build dirs, PNG read from
`<build_dir>/output.png`. Image verdicts recomputed with `verify_output`'s own
`compare_images()` against the upstream expected PNGs.

| test | movie | viewport | PNG before | PNG after | trace | image verdict before | image verdict after | design's proxy prediction |
|---|---|---|---|---|---|---|---|---|
| `visual/edittext/edittext_background_basic_scale2` | 100×100 | 200×200 | **100×100** | **200×200** | PASS → PASS | `size_mismatch` | 8652 outliers / budget 0 @ tol 0 | 8984 |
| `avm2/pixelbender_effect_twirl` | 550×400 | 600×700 | **550×400** | **600×700** | PASS → PASS | `size_mismatch` | 754200 / 1003 @ tol 3 | 754200 |
| `visual/filters/blur_scales_with_screen` | 200×200 | 400×400 | **200×200** | **400×400** | PASS → PASS | `size_mismatch` | 69231 / 0 @ tol 2 | 69242 |
| `avm2/edittext_get_char_index_at_point` | 400×400 | 800×800 | **400×400** | **800×800** | PASS → PASS | `size_mismatch` | 59137 / 0 @ tol 0 | 68237 |

All four leave the `size_mismatch` bin and land in a graded band, within a few
percent of the report's upper-bound proxy (and `twirl` hits it exactly — see
below). **Zero new passes**, exactly as predicted.

### Blur scaling actually fired (step 5)

`blur_scales_with_screen`, mid-row luminance profile, width of the gradient band
between the flat plateaus:

| render | size | gradient band |
|---|---|---|
| ours, before (1×) | 200×200 | 94 px |
| ours, after (2×) | 400×400 | **187 px** |
| Ruffle expected | 400×400 | 231 px |

187 ≈ 2 × 94: the kernel radius scaled with the render target. Without step 5 it
would have stayed ~94 px in a 400-px-wide image, i.e. half the apparent blur.
(Ruffle's 231 is a separate, pre-existing kernel-shape difference — the same one
that makes every 1× blur sibling fail.)

### Letterbox / non-uniform aspect — verified exactly

`pixelbender_effect_twirl` renders **entirely blank white** in our runtime both
before and after (PixelBender is unimplemented), so it confirms the target size
and the margin colour but says nothing about the vertical squeeze. Its 754200
outliers matching the report's proxy exactly is a consequence of that: an
upscaled blank equals a re-rendered blank.

So the `ky` path was probed directly instead. `visual/edittext/edittext_background_basic`
(100×100 movie, **no** `viewport_dimensions` of its own) was rebuilt with
`SWFRECOMP_EXTRA_DEFINES="-DVIEWPORT_WIDTH=200 -DVIEWPORT_HEIGHT=300"`
→ ShowAll `s = min(2, 3) = 2`, fitted 200×200, `kx = 1`, `ky = 2/3`, 50-row bars:

```
letterboxed render: 300 rows × 200 cols
bar colour: (255, 255, 255)          # stage background, not black
centre 200-row band (rows 50..250) == the plain 2x render: True, max abs diff 0
trace: PASS
```

The content lands byte-for-byte where ShowAll + centred align says it should,
and the margins are stage background. Reference for that comparison is
`edittext_background_basic_scale2`'s 200×200 render, which is legitimate: the
two tests' 1× renders are the same file (`sha a4028737831a21a2`).

## Results — the 4 no-op checks

| test | viewport | PNG size (before = after) | SHA-256 (before = after) | outliers (before = after) | trace |
|---|---|---|---|---|---|
| `visual/edittext/edittext_background_basic` | *(none)* | 100×100 | `a4028737831a21a2` | 2269 | PASS |
| `visual/filters/drop_shadow` | *(none)* | 550×400 | `32460201dd71c484` | 122356 | PASS |
| `visual/filters/blur_quality` | *(none)* | 800×800 | `827ed500f53b36ea` | 821415 | PASS |
| `avm2/stage3d_program_constants_bytearray_be` | **500×375 == movie** | 500×375 | `e57248391e19709e` | 328452 | PASS |

All four **byte-identical**. The last one is the load-bearing one: it *does*
declare a `viewport_dimensions`, so it goes through the whole new code path —
`memcpy` of the matrix, scale by `kx = ky = 1`, `render_* = FRAME_*`,
`stage_scale = 1` in the blur — and still produces the identical file. The other
three never define `VIEWPORT_*` and take the `#else` arm. `drop_shadow` covers
the `tag.c` filter-offset lines; `blur_quality` and `drop_shadow` cover
`render_webgpu_run_blur`.

## Trace blast radius: zero

16 graphics-mode runs (8 tests × before/after), every one `Pass: 1 (100.0%)`,
`Fail: 0`. No test's trace output changed. This is by construction:
`app_context.width/height` still mean stage pixels, and everything AS-visible
(`Stage.width`, `Capabilities.screenResolution*`, `_xmouse`'s `pixel_ratio`)
reads the `VIEWPORT_*` defines directly and was not touched.

## Not covered locally

- The other 8 cluster members (`pixelbender_effect_{BlurredFocus,glassDisplace}`,
  `stage_scale_factor`, `edittext_{border_basic_scale2,underline_scale2}`,
  `{any_blur,displacement_map,drop_shadow}_scales_with_screen`). Same mechanism,
  same two shapes (exact-2×, and the 550×400→600×700 letterbox), so a CI run is
  the right instrument, not more local builds.
- The 4 viewport-declaring **trace-only** tests (`avm1/capabilities_resolution`,
  `avm2/capabilities_resolution`, `avm1/stage_scale_mode`,
  `avm1/mouse_pos_with_scale_factor`). They now render at their declared
  viewport too. They read only the defines, so trace should be unaffected, but
  they were not run locally.
- `no-graphics` mode: untouched by construction (every edit is inside a
  `#ifndef NO_GRAPHICS` / `#ifdef OFFSCREEN_RENDER` region or in a
  graphics-only file), and the weekly canary covers it.

## Cost

The largest cluster member renders at 1800×600 with 4× MSAA plus filter
textures. Negligible for a 566-comparison run.

## Reproduction

```
# baseline vs fixed, one test at a time
scratchpad/runbatch.sh {base|fix} <suite> <test> <key>   # keeps the build dir
scratchpad/cmp.py     {base|fix} [keys…]                 # size + sha + verdict
scratchpad/letterbox.sh                                  # the ky probe
```
Logs: `scratchpad/bd/{base,fix}_<key>.log`; renders:
`scratchpad/bd/{base,fix}_<key>/output.png`; verdict dumps:
`scratchpad/{base,fix}_cmp.txt`.
