# BitmapData Rendering Plan
<!-- TESTS: bitmap_data_colortransform, bitmap_data_copypixels, bitmap_data_fillrect, bitmap_data_perlinnoise, bitmap_data_pixeldissolve_image, bitmapdata_applyfilter_colormatrix -->

Last updated: 2026-03-28

## Status: IN PROGRESS — GPU pipeline implemented, blocked by unimplemented BitmapData methods

### Progress Summary

**Completed (2026-03-28):**
- Dynamic bitmap texture layer allocation in render_webgpu.c (always creates bitmap texture array with extra layers for attachBitmap)
- `render_webgpu_draw_bitmap_quad()` function: uploads premultiplied ARGB pixels as RGBA, computes inverse matrix for UV mapping, generates textured quad vertices, draws with premultiplied alpha blend pipeline
- `actionIterateAttachedBitmaps()` callback system in action.c: iterates child_mc_cache for MCs with attached bitmaps, computes stage-space position
- tag.c rendering hook: calls attached_bitmap_render_cb during tagShowFrame render pass (alongside Drawing API and text field rendering)
- MovieClip struct extended with `attached_bitmap_pixels`, `attached_bitmap_width`, `attached_bitmap_height`
- Premultiplied alpha blend pipeline (`blend_premul_pipeline`) for correct compositing of premultiplied bitmap data

**Result: `bitmap_data_fillrect` renders correctly** (visual match with expected output, 545 sub-pixel outliers at tolerance=0 from MSAA edge blending).

### Blockers

The remaining 5 tests are blocked by **unimplemented BitmapData methods** (stubs that don't modify pixel data):

| Test | Required Method | Status |
|------|----------------|--------|
| bitmap_data_fillrect | fillRect | **IMPLEMENTED** — 545 outliers (tolerance=0) |
| bitmap_data_copypixels | copyPixels, merge | copyPixels implemented, merge is stub |
| bitmap_data_colortransform | colorTransform | Implemented (trace passes) — image untested |
| bitmap_data_perlinnoise | perlinNoise | **STUB** — all pixels zero |
| bitmap_data_pixeldissolve_image | pixelDissolve | **STUB** — all pixels zero |
| bitmapdata_applyfilter_colormatrix | applyFilter | **STUB** — all pixels zero |

### What Remains

1. **Implement missing BitmapData methods** (perlinNoise, applyFilter, pixelDissolve, merge) — these are complex algorithms unrelated to the GPU pipeline
2. **Fix 545 outlier precision issue** for bitmap_data_fillrect — likely MSAA anti-aliasing at quad boundaries; may need sub-pixel positioning or MSAA-aware rendering
3. **Test bitmap_data_copypixels and bitmap_data_colortransform** with headless mode once their pixel operations are verified

### Affected Image Tests

| Test | Tolerance | Current Outliers | Notes |
|------|-----------|-----------------|-------|
| bitmap_data_fillrect | 0 | 545 | Renders correctly, edge precision diff |
| bitmap_data_copypixels | 0 | 190726 | copyPixels works but merge is stub |
| bitmap_data_colortransform | 5 | 78561 | colorTransform implemented, needs verification |
| bitmap_data_perlinnoise | 0 | ~876K | perlinNoise stub → all black |
| bitmap_data_pixeldissolve_image | 1 | ~155K | pixelDissolve stub → all black |
| bitmapdata_applyfilter_colormatrix | 1 | ~68K | applyFilter stub → all black |

### Key Code Locations

| Component | File | Description |
|-----------|------|-------------|
| Dynamic bitmap quad rendering | `render_webgpu.c:render_webgpu_draw_bitmap_quad()` | Uploads pixels, computes UV matrix, draws textured quad |
| Premultiplied alpha pipeline | `render_webgpu.c:blend_premul_pipeline` | One/OneMinusSrcAlpha blend for premul data |
| Bitmap iteration callback | `action.c:actionIterateAttachedBitmaps()` | Iterates child_mc_cache for attached bitmaps |
| Rendering hook | `tag.c:attached_bitmap_render_cb()` | Called during tagShowFrame render pass |
| MC bitmap storage | `action.h:MovieClip.attached_bitmap_*` | Pixel pointer, width, height |
| Bitmap texture allocation | `render_webgpu.c:create_textures()` | Always allocates 32 extra dynamic layers |

### Architecture Notes

- Dynamic bitmaps use **premultiplied alpha blending** (One/OneMinusSrcAlpha) since BitmapDataNative stores premultiplied ARGB
- Inverse matrix includes translation offset to map quad position → (0,0) in bitmap space
- Bitmap texture array always has `bitmap_count + MAX_DYNAMIC_BITMAPS` layers (even if no static bitmaps)
- `bitmap_sizes_buffer` and `inv_mat_buffer` over-allocated with `MAX_DYNAMIC_BITMAPS` extra slots
- Dynamic bitmap layers reset each frame (`dynamic_bitmap_used = 0` in `render_webgpu_open_pass`)
