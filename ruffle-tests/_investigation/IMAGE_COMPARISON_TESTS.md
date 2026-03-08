# Headless Image Comparison Tests — Investigation Report

## Overview

32 Ruffle AVM1 tests include image comparisons. These render the SWF to a PNG using our headless WebGPU pipeline (Dawn + lavapipe software Vulkan) and compare against expected PNGs from the Ruffle test suite.

**Pipeline**: SWFRecomp → C code → native binary (with `-DHEADLESS_RENDER_ENABLED`) → headless Dawn WebGPU → frame capture → PNG → pixel comparison

**Running a test**: `python3 ruffle-tests/verify_output.py --test=TEST_NAME --headless --diff --verbose`

Expected PNGs are now copied into each test directory as `output.expected.png` (from `~/CC/ruffle/tests/tests/swfs/avm1/`).
Actual PNGs are saved to the test directory as `output.actual.png` when `--verbose` is passed.

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
