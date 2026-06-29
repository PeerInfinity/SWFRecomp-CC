# Headless Image Comparison Tests — Investigation Report

## Overview

32 Ruffle AVM1 tests include image comparisons. These render the SWF to a PNG using our headless WebGPU pipeline (Dawn + lavapipe software Vulkan) and compare against expected PNGs from the Ruffle test suite.

**Pipeline**: SWFRecomp → C code → native binary (with `-DHEADLESS_RENDER_ENABLED`) → headless Dawn WebGPU → frame capture → PNG → pixel comparison

**Running a test**: `python3 ruffle-tests/verify_output.py --test=TEST_NAME --headless --diff --verbose`

Expected PNGs are now copied into each test directory as `output.expected.png` (from `~/CC/ruffle/tests/tests/swfs/avm1/`).
Actual PNGs are saved to the test directory as `output.actual.png` when `--verbose` is passed.

> **Much of the "Known Bugs / Missing Features" section below is now STALE** —
> Drawing API and `setMask` rendering work; see the 2026-06-28 update next.

---

## Session update (2026-06-28): reference semantics, triage tool, stroke fixes, taxonomy

**Two image references — don't confuse them:**
- **`output.expected.png` = the real Flash Player render** = the authoritative oracle.
- **`output.ruffle.png` = Ruffle's *own* render**, present only for `known_failure`
  tests, often at `quality="low"` (1× MSAA, no AA). It is **not** a fidelity oracle:
  comparing our 4× render to a 1× `ruffle.png` produces spurious 1px "off-by-one"
  edge lines. Always measure against `expected.png`.

**Triage tool — `ruffle-tests/triage_image_tests.py [test]`** (sweep with no arg).
Renders a fresh **4× Ruffle** reference (apples-to-apples) and classifies each
comparison:
- **CLEAN** — we already match Flash.
- **B-FIXABLE** — Ruffle ≈ Flash but we don't → a real SWFRecomp bug; correct output
  is demonstrably achievable.
- **A-INHERENT** — we == Ruffle (`us-vs-Ruffle = 0`), both differ from Flash → the
  MSAA-vs-Flash-analytic-rasterizer gap (hairline pixel-snapping, abutting-edge
  seams, sharp-corner coverage). Not fixable without reimplementing Flash hinting,
  which Ruffle doesn't do either → accept.

**Drawing-API stroke fixes landed (runtime `action.c` + graphics `tag.c`):**
1. `fix(runtime)`: close the **stroke** on filled open paths (Flash auto-closes the
   outline of a filled shape; the `moveTo;lineTo*3;endFill` idiom dropped one side).
2. `fix(graphics)`: **mask stencils use fill geometry only** — Flash masks ignore the
   mask clip's stroke; we were inflating the mask by the stroke width.
3. `feat(graphics)`: **per-vertex miter joins** for stroke corners (outer side,
   winding-independent, miter-limit 4, bevel fallback; ASAN-clean & deterministic —
   a prior prototype overran `line_verts` → non-deterministic heap corruption, fixed).

Result: **`avm1/movieclip_setmask` 3594 px → 0 px (pixel-perfect, PASSES, beats
Ruffle's 16px residual).** `mask_with_drawing` stayed clean. CI both modes, no
regressions.

**Inherent (accepted) — see `ACCEPTED_DIFFS.md` Category 11 / `from_gnash` Cat 5:**
`display_object_properties` (~192 px), `from_gnash …/simple_loop_test` (121–724
px/frame, hairline pixel-snapping). We == Ruffle; both differ from Flash.

**Still-open *fixable* gap (NOT accepted — next target):** the gradient-draw tests
`movieclip_begin_gradient_fill` (1266 px) and `movieclip_line_gradient_style`
(1052 px). Ruffle ≈ Flash (180/151 px) but we're far off — a real SWFRecomp
drawing-API gradient-rendering gap. `from_shumway/gradientTransform` (467 px) is a
DefineShape gradient whose *interior ramp already matches Flash exactly* (flat 153);
its residual is the accepted MSAA edge-AA gap (Category 11), not gradient banding.

## Session update (2026-06-29): gradient phase offset ROOT-CAUSED AND FIXED

The 2026-06-28 "sub-pixel sampling phase" hypothesis was correct in *symptom* but
the cause was concrete and fixable, not a GPU convention mismatch:

**1. Focal-point Fixed8 truncation (the dominant bug — ~1000 of 1266 px).**
Per-cell analysis showed the *entire* `movieclip_begin_gradient_fill` error lived
in one cell — `radial, repeat, linearRGB, focal 0.8` (all other cells, including
radial-pad and radial-reflect, were 0 px in the interior). Flash/Ruffle store the
focal point as **Fixed8**, and `swf::Fixed8::from_f64(n)` is `(n * 256.0) as i16`
— Rust `as i16` **truncates toward zero**, NOT rounds. So AS focal `0.8` →
`0.8*256 = 204.8` → `204` → `204/256 = 0.796875` (then the wgpu renderer clamps to
`[-0.98, 0.98]`). Our code fed `~0.79998` to the shader (a near-exact 0.8). With a
`repeat` spread the cycles around the focal singularity are infinitely compressed,
so a `0.003` focal error shifts the whole high-frequency region → the bulk of the
diff. An empirical `FOCAL_OVERRIDE` sweep (persistent build, no rebuild per value)
found the optimum at exactly the shader value `0.796875`, confirming Fixed8
truncation. **Fix:** `action.c` `applyGradientFillToMC` / `applyLineGradientStyleToMC`
now `focal = truncf(focal*256)/256` then clamp `[-0.98, 0.98]`.
Result: `movieclip_begin_gradient_fill` **1266 → 202** (focal cell 1040 → 8;
Ruffle-vs-Flash floor is 180 — we now match Flash about as well as Ruffle does).

**2. Ramp-sample index convention (minor — ~40 px).** Ruffle samples its 256-texel
ramp with a HARDWARE linear sampler (clamp-to-edge): effective index `t*256 - 0.5`.
Our `sample_gradient` used `t*255`, a `(0.5 - t)`-index phase error. Changed to
`clamp(t*256-0.5, 0, 255)` (kept `textureLoad` for exact ROW selection — no
V-filter bleed across ramps on SwiftShader). `render_webgpu.c`.

**No regressions:** `movieclip_setmask` = 0, `mask_with_drawing` = 0,
`from_shumway/gradientTransform` = 467 (unchanged — the accepted Cat-11 edge gap;
the ramp-convention change is byte-neutral on its flat interior).

**Still open (separate, NOT gradient phase):** `movieclip_line_gradient_style`
**1052 → 535** — the gradient *phase* is fixed (its focal-repeat cell, 54, now
matches its other stroke cells, 32–64), but its residual is stroke-edge AA
distributed across every `lineGradientStyle` cell. Ruffle-vs-Flash is 151 here, so
our strokes are genuinely ~3.5× less faithful to Flash than Ruffle's — a
stroke-rasterization gap (per-vertex miter joins vs Flash's analytic rasterizer),
not a gradient issue. Future stroke-fidelity work, out of scope for the phase fix.

**2026-06-28 root-cause update — it is NOT a ramp color-ramp/quantization bug.**
A full investigation (compute our 256-ramp, compare byte-for-byte to Ruffle's
`CommonGradient::new` in `render/wgpu/src/mesh.rs`, and trace the full
sample→linear_to_srgb→cxform pipeline) showed:

- **The ramp itself is essentially correct** for these tests. (Both stops here share
  `G=20`, so even the one genuine ramp imprecision below is ≤1 px here.) A faithful
  Ruffle ramp port — float-precision linearRGB convert + truncate-once instead of
  pre-quantizing each endpoint to u8-linear — was tried and **reverted**: it moved
  the metric by only ±1 px noise (net slightly *worse*: 1266→1304, 1052→1059) because
  these gradients have no black→colour dark-channel interpolation. (That endpoint-
  quantization fix would matter for a black→colour linearRGB *drawing-API* gradient;
  no current test exercises one. `from_gnash …/GradientFillTest` has such stops but
  uses the **DefineShape/recompiler** ramp path (`swf.cpp`), not this runtime path.)
- **The real error is a ~0.25 px sub-pixel gradient-*sampling phase* offset**: our
  per-fragment `t` lands ~2–3 ramp indices *high* (consistently too blue / too little
  red) vs Ruffle. It is **our bug** — a fresh 4× Ruffle render is **byte-identical to
  Flash** on the worst cell (Ruffle-vs-Flash = 0; us-vs-Ruffle ≈ us-vs-Flash ≈ 1076).
  The offset is invisible on slow pad/linear gradients (3–12 px) but **explodes where
  focal/repeat/reflect compresses cycles** (the `radial, repeat, linearRGB, focal 0.8`
  cell alone is ~1090 of the 1266): a tiny constant `t` error × the large
  `d(t)/d(uv)` gain in the focal-dense region. The diff pixels (channel-sum > 30) sit
  on the *steep* parts of each cycle / the repeat-wrap edges; the smooth ramp is < 30.
- Ruled out: ramp values, ramp texture format (`RGBA8Unorm`, not sRGB — no double
  convert), surface format (`BGRA8Unorm`, linear), the focal WGSL formula (identical
  to Ruffle's `gradient.wgsl`), focal encode/decode (`(u16)(f*16384+32768)` ↔
  `(x-32768)/16384`, consistent), spread/`fract`, and uv being vertex-interpolated
  (affine ⇒ exact). f32 matrix-inversion precision is ~5e-7, too small alone.
- **Next step requires GPU-level instrumentation** (dump per-fragment `uv`/`t` for one
  focal-repeat pixel, ours vs a Ruffle wgpu capture) to localise the ~0.25 px
  position/convention difference — likely a pixel-center / sample-position or
  gradient-matrix-origin convention mismatch in the drawing-API GPU path
  (`render_webgpu_draw_gradient_tris` + vertex shader uv), not the ramp builder.
  Static source analysis could not pin it.

**Verification gotchas** (cost hours): editing runtime `.c` then re-rendering can
read a stale `action.o` (ccache) AND a stale `output.actual.png`. Always:
`touch test.swf; rm -rf RecompiledScripts RecompiledTags build output.actual.png;
CCACHE_DISABLE=1 … verify_output.py … --mode=graphics --verbose` and confirm the PNG
mtime advanced. `--verbose` is required to save `output.actual.png` (else triage
reports NOIMG). `--asan` auto-disables ccache.

---

## Current Rendering Status

### What Works
- **Basic shape rendering**: Solid-color filled shapes render at correct positions with correct geometry
- **Rotation transforms**: Rotated shapes (e.g., the green diamond in `display_object_properties`) render correctly
- **Stage origin offset**: The `stage_to_ndc` matrix now accounts for `FRAME_X_MIN_TWIPS`/`FRAME_Y_MIN_TWIPS` (fixed this session)
- **Nested sprite rendering**: Multiple instances of the same sprite character now render correctly with unique composed transforms via dynamic slot allocation (fixed this session)
- **Color fills**: Static fill colors from `color_data` are rendered correctly (e.g., green in `display_object_properties`, magenta in `frame_size_translated_*`)

### Known Bugs / Missing Features

#### Bug 1: Runtime Color Transform (cxform) Not Reflected in GPU Buffer
- **Symptom**: Shapes rendered with static cxform from timeline, ignoring `Color.setRGB()`/`Color.setTransform()` changes
- **Example**: `color` test — 3 grey rectangles instead of pink/yellow/blue
- **Root cause**: The `cxform_buffer` GPU buffer is uploaded once at init from static `cxform_data`. When ActionScript's `Color` object modifies display object `cx_ra`/`cx_rb`/etc. fields at runtime, the GPU buffer is not updated.
- **Affected tests**: `color`, `display_object_properties` (partial), `netstream_play_flv_screen`
- **Fix approach**: Before each render pass, check display objects for runtime cxform changes and write updated cxform data to the GPU buffer. Either update existing cxform slots or allocate dynamic cxform slots (similar to the dynamic transform slot approach).

#### Bug 2: Runtime Transform Updates Not Reflected in GPU Buffer
- **Symptom**: Shapes rendered at their static timeline positions, ignoring `_x`/`_y`/`_xscale`/`_yscale`/`_rotation` changes
- **Example**: `display_object_properties` — green diamond at center-left instead of far-right
- **Root cause**: Same pattern as cxform — the `xform_buffer` is populated from static `transform_data`. Runtime position/scale/rotation changes (via `_x`, `_y`, etc.) update the display object's fields but don't update the GPU buffer. The `compose_children` function reads from `app_context->transform_data` (the static array), not from the display object's current transform.
- **Affected tests**: `display_object_properties`, `color` (partial — 3rd rectangle missing due to runtime placement), many others
- **Fix approach**: Before each render pass, rebuild the transform for each display object from its current position/scale/rotation properties, then upload to the GPU buffer. This is essentially what a live Flash player does each frame.

#### Missing Feature: createTextField Rendering
- **Symptom**: Text fields created at runtime via `createTextField()` don't render
- **Example**: `frame_size_translated_negative` — missing cyan rectangle (text field with background color)
- **Affected tests**: `frame_size_translated_negative`, `frame_size_translated_positive`, `edittext_stylesheet`, `edittext_tag_indent`, `movieclip_create_text_field`
- **What's needed**: When `createTextField()` creates a text field, the renderer needs to draw its background/border (if enabled) and text content. This requires:
  - Rendering the text field's background rect as a filled shape
  - Rendering the border as a stroked rect
  - Rendering the text glyphs (requires font atlas or glyph shape rendering)

#### Missing Feature: Drawing API Rendering
- **Symptom**: Shapes drawn via `beginFill()`/`lineTo()`/`moveTo()`/`endFill()` don't appear
- **Affected tests**: `movieclip_begin_gradient_fill`, `movieclip_line_gradient_style`, `mask_with_drawing`, `movieclip_setmask`
- **What's needed**: The drawing API creates dynamic shapes at runtime. These need to be tessellated into triangles and uploaded to the GPU vertex buffer. This is a significant feature.

#### Missing Feature: BitmapData Rendering
- **Symptom**: BitmapData objects created at runtime don't render
- **Affected tests**: `bitmap_data_colortransform`, `bitmap_data_copypixels`, `bitmap_data_fillrect`, `bitmap_data_perlinnoise`, `bitmap_data_pixeldissolve_image`, `bitmapdata_applyfilter_colormatrix`
- **What's needed**: BitmapData needs to be rendered as textured quads. Operations like fillRect, copyPixels, perlinNoise need to modify the bitmap texture data, then the bitmap needs to be drawn to screen.

#### Missing Feature: External Media Loading
- **Symptom**: loadMovie() and NetStream don't load external images/video
- **Affected tests**: `mcl_target_gif87a`, `mcl_target_gif89a`, `mcl_target_jpg`, `mcl_target_png`, `movieclip_methods_with_loaded_image`, `netstream_play_flv`, `netstream_play_flv_screen`
- **What's needed**: HTTP/file loading of images (GIF, JPEG, PNG) and FLV video in headless mode

#### Missing Feature: Focus Rect Rendering
- **Symptom**: Focus rectangles (yellow outlines on focused elements) don't render
- **Affected tests**: `focusrect_focuslost`, `focusrect_mouse_swf8`, `focusrect_mouse_swf9`, `focusrect_swf5`, `focusrect_swf6`
- **What's needed**: Focus rect is a special 2-pixel yellow/black outline drawn around the focused display object

#### Missing Feature: Mask Rendering (setMask)
- **Symptom**: Dynamic masks set via `setMask()` at runtime aren't applied
- **Affected tests**: `mask_reapply`, `mask_with_drawing`, `movieclip_setmask`
- **Note**: Static clip masks from `PlaceObject2.clip_depth` may already work (the renderer has `begin_clip_mask`/`end_clip_mask`). Runtime `setMask()` is different.

---

## Test Categorization by Required Features

### Tier 1: Closest to Passing (need bug fixes only)
These tests use only static timeline shapes/sprites. Fixing the runtime transform and/or cxform GPU update bugs would make them pass.

| Test | Tolerance | Blocking Issue | Notes |
|------|-----------|---------------|-------|
| display_object_properties | 90 | Runtime transform update | Green diamond renders correctly but at wrong position |
| color | 1 | Runtime cxform update | 3 grey rectangles instead of colored; also needs runtime transforms for 3rd rect |

### Tier 2: Need createTextField (+ bug fixes)
| Test | Tolerance | Notes |
|------|-----------|-------|
| frame_size_translated_negative | max_outliers=1 | Shapes render correctly; only missing cyan text field |
| frame_size_translated_positive | max_outliers=1 | Same as above |
| edittext_tag_indent | 128 | Known failure in Ruffle itself; very forgiving tolerance |
| edittext_stylesheet | 64 | CSS-styled text fields |
| movieclip_create_text_field | trigger-based | Pure createTextField test |

### Tier 3: Need Drawing API
| Test | Tolerance | Notes |
|------|-----------|-------|
| movieclip_begin_gradient_fill | 6 | Gradient fills via drawing API |
| movieclip_line_gradient_style | 6 | Gradient line styles |
| mask_with_drawing | 6 | Drawing API + masking |
| movieclip_setmask | 0 | Drawing API + setMask |

### Tier 4: Need Focus Rect Rendering
| Test | Tolerance | Notes |
|------|-----------|-------|
| focusrect_focuslost | trigger | 1 image |
| focusrect_mouse_swf8 | trigger | 8 images |
| focusrect_mouse_swf9 | trigger | 8 images |
| focusrect_swf5 | trigger | 12 images |
| focusrect_swf6 | trigger | 12 images |

### Tier 5: Need BitmapData Rendering
| Test | Tolerance | Notes |
|------|-----------|-------|
| bitmap_data_fillrect | 0 | BitmapData.fillRect() |
| bitmap_data_copypixels | 0 | BitmapData.copyPixels() |
| bitmap_data_colortransform | 5 | BitmapData + ColorTransform |
| bitmap_data_perlinnoise | 0 | BitmapData.perlinNoise() |
| bitmap_data_pixeldissolve_image | 1 | BitmapData.pixelDissolve() |
| bitmapdata_applyfilter_colormatrix | 1 | BitmapData.applyFilter() |

### Tier 6: Need External Media Loading
| Test | Tolerance | Notes |
|------|-----------|-------|
| mcl_target_gif87a | 0 | loadMovie (GIF87a) |
| mcl_target_gif89a | 0 | loadMovie (GIF89a) |
| mcl_target_jpg | 3 | loadMovie (JPEG) |
| mcl_target_png | 0 | loadMovie (PNG) |
| movieclip_methods_with_loaded_image | 0 | loadMovie + MC methods |
| netstream_play_flv | 1 | NetStream FLV playback |
| netstream_play_flv_screen | 1 | NetStream + screen video |

### Tier 7: Need Multiple Features
| Test | Tolerance | Notes |
|------|-----------|-------|
| mouse_events_visible_enabled | 0 | Button rendering + 40-frame animation |
| mask_reapply | 1 | Multiple masks + runtime setMask |

---

## Fixes Applied This Session

### 1. Stage Origin Offset in stage_to_ndc Matrix
**File**: `SWFRecomp/src/swf.cpp` (lines 289-290)
**Before**: Translation was hardcoded to `(-1, 1)`, assuming stage starts at `(0, 0)`.
**After**: Translation accounts for `FRAME_X_MIN_TWIPS` and `FRAME_Y_MIN_TWIPS`:
```c
-1.0f - (float)FRAME_X_MIN_TWIPS/(FRAME_WIDTH_TWIPS/2.0f)
 1.0f + (float)FRAME_Y_MIN_TWIPS/(FRAME_HEIGHT_TWIPS/2.0f)
```
**Impact**: Fixes viewport positioning for SWFs with non-zero stage origin (like `frame_size_translated_*`).

### 2. Dynamic Transform Slot Allocation for Sprite Composition
**Files**: `tag.c`, `render_webgpu.c`, `render_webgpu.h`
**Problem**: When multiple sprite instances shared the same child `transform_id`, `compose_children` overwrote the same GPU buffer slot, causing all instances to render at the last-composed position.
**Fix**: The xform_buffer is over-allocated with 512 extra slots. `compose_children` now allocates unique dynamic slots for each composed transform, saving the original `transform_id` values on a stack that's restored after rendering.
**Impact**: Multiple instances of the same sprite character now render at their correct respective positions.

### 3. Actual Image Saving in verify_output.py
**File**: `ruffle-tests/verify_output.py`
When `--verbose` is passed, the actual rendered PNG and difference image are copied to the test directory as `{name}.actual.png` and `{name}.difference.png` for easy inspection.

### 4. Expected Images Copied to Test Directories
All expected PNGs from `~/CC/ruffle/tests/tests/swfs/avm1/` have been copied to the corresponding `ruffle-tests/` test directories.

---

## Architecture Notes

### Render Pipeline (Headless)
1. `swf_headless.c` frame loop ticks the SWF
2. Each `tagShowFrame` in `tag.c` triggers a render pass:
   a. **Compose phase**: Walk display list, compose parent×child transforms for sprites/buttons, write to GPU buffer
   b. **Render phase**: Open render pass, walk display list in depth order, draw each shape/text/sprite
3. Capture triggers (env var `CAPTURE_TRIGGERS`) schedule PNG saves at specific frames
4. `render_webgpu_close_pass` copies framebuffer to readback buffer; `save_png` reads back BGRA→RGBA

### Key Data Flow
- **Vertex data**: `shape_data` → GPU `vertex_buffer` (uploaded once at init)
- **Transforms**: `transform_data` → GPU `xform_buffer` (uploaded once + dynamic slots per frame)
- **Colors**: `color_data` → GPU `color_buffer` (uploaded once)
- **Color transforms**: `cxform_data` → GPU `cxform_buffer` (uploaded once — **needs runtime updates**)
- **Draw calls**: `render_webgpu_draw_shape(ctx, offset, num_verts, transform_id, cxform_id)` packs both IDs into `firstInstance` parameter; vertex shader unpacks them

### Shader Architecture
- Vertex shader: reads transform from `xform_buffer[transform_id]`, multiplies with `stage_to_ndc` uniform
- Fragment shader: reads fill color from `colors[]` buffer, applies cxform from `cxforms[cxform_id]` via `apply_cxform()` function (4×4 matrix multiply + add + clamp)
