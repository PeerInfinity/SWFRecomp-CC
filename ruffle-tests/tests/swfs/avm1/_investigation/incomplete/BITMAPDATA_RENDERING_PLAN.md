# BitmapData Rendering Plan
<!-- TESTS: bitmap_data_colortransform, bitmap_data_copypixels, bitmap_data_fillrect, bitmap_data_perlinnoise, bitmap_data_pixeldissolve_image, bitmapdata_applyfilter_colormatrix -->

Last updated: 2026-03-27

## Status: NOT STARTED — Tier 5 (needs bitmap→GPU texture pipeline)

### Problem

BitmapData objects created at runtime don't render in headless graphics mode. The BitmapData pixel buffer exists in CPU memory (`BitmapDataNative.pixels`), and operations like `fillRect`, `copyPixels`, `perlinNoise` work correctly for trace tests. But there is no path to display the bitmap on screen — either as an `attachBitmap()` target or as a `BitmapData.draw()` source rendered to a MovieClip.

### Affected Image Tests

| Test | Tolerance | Notes |
|------|-----------|-------|
| bitmap_data_fillrect | 0 | BitmapData.fillRect() |
| bitmap_data_copypixels | 0 | BitmapData.copyPixels() |
| bitmap_data_colortransform | 5 | BitmapData + ColorTransform |
| bitmap_data_perlinnoise | 0 | BitmapData.perlinNoise() |
| bitmap_data_pixeldissolve_image | 1 | BitmapData.pixelDissolve() |
| bitmapdata_applyfilter_colormatrix | 1 | BitmapData.applyFilter() |

### Current Infrastructure

#### BitmapData Pixel Buffer (`action.c:2143-2190`, `action.h`)

```c
typedef struct {
    uint32_t* pixels;    // ARGB pixel data, row-major, premultiplied alpha
    int32_t width;
    int32_t height;
    uint8_t transparent; // 0 = opaque (alpha always 0xFF), 1 = transparent
    uint8_t disposed;    // 1 = disposed
} BitmapDataNative;
```

- Side table: `g_bitmap_natives[]` (max 256 instances)
- Lookup: `getBitmapNative(ASObject*)` / `setBitmapNative(ASObject*, BitmapDataNative*)`
- All pixel operations (fillRect, copyPixels, noise, perlinNoise, colorTransform, draw, threshold, etc.) work on this CPU buffer

#### attachBitmap() (`action.c:45426-45445`)

Sets MovieClip width/height from bitmap dimensions, updates drawing bounds. Does NOT render the bitmap.

#### GPU Texture Pipeline (`render_webgpu.c`)

The renderer already has bitmap texture support for **static** bitmap fills (DefineShape with bitmap fill style):

- `WGPUTexture bitmap_tex` — 2D array texture for bitmap data (`render_webgpu.h:67`)
- `WGPUTextureView bitmap_tex_view` — texture view (`render_webgpu.h:68`)
- `WGPUSampler bitmap_sampler` — linear sampler (`render_webgpu.h:69`)
- `render_webgpu_upload_bitmap()` (`render_webgpu.c:1809-1853`) — uploads RGBA pixel data to GPU texture array slice
- `bitmap_sizes[]` storage buffer — per-bitmap width/height for shader UV calculation

**Vertex shader** (lines 80-85): Style type 0x40-0x43 = bitmap fill. Reads inverse matrix, computes UV coordinates from bitmap dimensions.

**Fragment shader** (lines 98-99): Samples `bitmap_tex` (2D array texture) with `bitmap_samp` sampler.

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| BitmapDataNative struct | `action.c` | 2143-2190 |
| Side table (g_bitmap_natives) | `action.c` | ~2145 |
| attachBitmap() | `action.c` | 45426-45445 |
| GPU texture pipeline | `render_webgpu.c` | 1809-1853 |
| Bitmap texture/sampler | `render_webgpu.h` | 67-69 |
| Shader bitmap fill | `render_webgpu.c` | 80-85 (vertex), 98-99 (fragment) |
| Static bitmap upload | `render_webgpu.c` | `render_webgpu_upload_bitmap()` |
| Vertex style encoding | `render_webgpu.c` | 0x40 = bitmap fill |

### What's Missing

#### Gap 1: attachBitmap() → Display Rendering

When `attachBitmap(bmp, depth)` is called, the bitmap needs to become a renderable display object:

1. **Generate a quad shape**: Create 2 triangles covering the bitmap's dimensions (0,0)→(width,height) in pixels
2. **Assign bitmap fill style**: Vertex style type = 0x40, style_id = bitmap texture layer index
3. **Upload pixel data to GPU texture**: Call `render_webgpu_upload_bitmap()` with the BitmapDataNative's pixels
4. **Upload identity inverse matrix**: Bitmap fill UV mapping needs an inverse matrix in `inv_mat_buffer`
5. **Add to display list**: The quad should render at the MC's transform with the MC's cxform

#### Gap 2: Dynamic Bitmap Texture Allocation

Static bitmap fills are pre-allocated at init time. Runtime `attachBitmap()` needs dynamic allocation:
- Dynamic texture array layers (or re-upload to existing layers)
- Dynamic inverse matrix slots
- Dynamic bitmap_sizes entries

#### Gap 3: Pixel Data Sync

When BitmapData operations (fillRect, setPixel, etc.) modify the CPU pixel buffer AFTER `attachBitmap()`, the GPU texture needs to be re-uploaded. Options:
- **Lazy re-upload**: Mark bitmap as dirty, re-upload before next render pass
- **Immediate re-upload**: Re-upload on every pixel modification (expensive)
- **Per-frame re-upload**: Always re-upload all attached bitmaps before rendering (simplest)

### Implementation Plan

#### Step 1: Dynamic Bitmap Texture Layer Allocation

Add a dynamic bitmap allocation system:
```c
// In render_webgpu.c
u32 allocate_dynamic_bitmap_layer(WebGPURenderContext* ctx);
void upload_dynamic_bitmap(WebGPURenderContext* ctx, u32 layer,
                           const uint32_t* pixels, u32 width, u32 height);
```

Pre-allocate extra layers in the bitmap texture array (e.g., 32 dynamic layers beyond static count).

#### Step 2: attachBitmap() Rendering Path

When `attachBitmap(bmp, depth)` is called:
1. Allocate a dynamic bitmap layer
2. Upload pixel data (ARGB → RGBA conversion)
3. Store layer index on the MovieClip (new field: `u32 attached_bitmap_layer`)
4. In the render pass, detect MCs with attached bitmaps and render as textured quads

#### Step 3: Per-Frame Bitmap Re-upload

Before each render pass, iterate attached bitmaps and re-upload any that have been modified since last upload. Use a dirty flag on BitmapDataNative.

#### Step 4: Test with Image Tests

```bash
python3 ruffle-tests/verify_output.py --test=bitmap_data_fillrect --headless --diff --verbose
```

### Design Considerations

1. **ARGB → RGBA conversion**: BitmapDataNative stores ARGB (Flash format), GPU expects RGBA. Need byte swizzle during upload.

2. **Premultiplied alpha**: Pixel data is premultiplied. The shader may need to un-premultiply for correct blending, or use premultiplied alpha blending mode.

3. **Texture size limits**: Each BitmapData can be up to 2880×2880 pixels. Dynamic texture array layers need to accommodate the largest bitmap. Could use separate textures per bitmap instead of array layers.

4. **Memory**: 2880×2880×4 bytes = ~33MB per bitmap at max size. Most test bitmaps are much smaller.

### Dependencies

- None — BitmapData CPU operations are fully working
- Benefits from RUNTIME_TRANSFORM_GPU_PLAN.md if attached bitmaps need runtime transforms

### Estimated Complexity

Medium-high. The GPU texture pipeline exists for static bitmaps, but dynamic allocation, pixel sync, and the attachBitmap rendering path need new code:
1. Dynamic bitmap layer allocation (~50 lines)
2. attachBitmap rendering path (~80 lines)
3. Per-frame re-upload (~40 lines)
4. ARGB→RGBA conversion (~10 lines)
5. Quad generation for bitmap display (~30 lines)
