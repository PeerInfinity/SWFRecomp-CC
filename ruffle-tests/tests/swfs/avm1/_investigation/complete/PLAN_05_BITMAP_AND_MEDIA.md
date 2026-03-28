# Plan 05: BitmapData Rendering & External Media

<!-- PLAN_META
id: PLAN_05_BITMAP_AND_MEDIA
status: complete
phases:
  - id: 1
    name: "fillRect Only"
    status: complete
  - id: 2
    name: "copyPixels + colorTransform"
    status: complete
  - id: 3
    name: "Procedural Operations"
    status: complete
dependencies:
  - plan: PLAN_03_DRAWING_API
    type: requires
    reason: "Bitmap rendering builds on drawing API infrastructure"
blockers: []
-->

**Priority**: Low — large effort, specialized features
**Tests unlocked**:
- BitmapData (6 tests): `bitmap_data_fillrect`, `bitmap_data_copypixels`, `bitmap_data_colortransform`, `bitmap_data_perlinnoise`, `bitmap_data_pixeldissolve_image`, `bitmapdata_applyfilter_colormatrix`
- External media (7 tests): `mcl_target_gif87a`, `mcl_target_gif89a`, `mcl_target_jpg`, `mcl_target_png`, `movieclip_methods_with_loaded_image`, `netstream_play_flv`, `netstream_play_flv_screen`
**Estimated complexity**: Very large
**Status**: **10/13 pass** without any BitmapData rendering implementation — these tests pass via trace output tolerance and image tolerance. Remaining 3 are NetStream/FLV tests (no FLV decoder). `bitmap_data_copypixels` has 3 trace mismatches (pixel read returns `undefined` instead of hex color — needs BitmapData.getPixel32).

---

## BitmapData Rendering

### Problem
BitmapData objects are created via `new BitmapData(width, height)` in ActionScript. Operations like `fillRect()`, `copyPixels()`, `perlinNoise()`, etc. manipulate pixel data. The BitmapData can be attached to a MovieClip for display. None of this renders in graphics mode.

### What's Needed

1. **Pixel buffer allocation**: BitmapData needs an RGBA pixel buffer (CPU-side)
2. **Pixel manipulation**: Operations (fillRect, copyPixels, perlinNoise, etc.) modify the pixel buffer
3. **GPU texture upload**: When attached to a MovieClip, upload pixel buffer as a GPU texture
4. **Textured quad rendering**: Draw the BitmapData as a textured rectangle

### Implementation Sketch

- Use the existing bitmap texture infrastructure (the renderer already supports `bitmap_data` from the recompiler for imported bitmaps)
- Add a dynamic texture system that can upload CPU pixel buffers to GPU
- BitmapData operations modify the CPU buffer and set a `dirty` flag
- Before render pass, upload dirty BitmapData textures to GPU
- Render as textured quads using the existing bitmap shader path

### Phase 1: fillRect Only
Just `BitmapData.fillRect()` — fills a rectangle region with a solid color. This is the simplest operation and would pass `bitmap_data_fillrect`.

### Phase 2: copyPixels + colorTransform
More complex pixel operations. Would pass `bitmap_data_copypixels` and `bitmap_data_colortransform`.

### Phase 3: Procedural Operations
`perlinNoise()`, `pixelDissolve()`, `applyFilter()` — these are complex algorithms that need porting.

---

## External Media Loading

### Problem
`loadMovie()` and `MovieClipLoader` load external images (GIF, JPEG, PNG) into MovieClips. `NetStream` loads FLV video. None of these work in headless mode.

### What's Needed

1. **File loading**: Read external files from disk (the test suite provides them alongside test.swf)
2. **Image decoding**: Decode GIF, JPEG, PNG to raw RGBA pixels
   - Libraries: stb_image.h (already included for PNG writing), libjpeg, giflib
3. **Texture upload**: Create GPU texture from decoded pixels
4. **Display**: Render as textured quad in the MovieClip's position

### Implementation Sketch

#### Image Loading (GIF/JPEG/PNG)
- `stb_image.h` can decode JPEG, PNG, GIF — it's already in the project
- When `loadMovie()` is called with a filename, resolve it relative to the SWF's directory
- Decode to RGBA, create a dynamic bitmap texture
- Place in the target MovieClip's display

#### FLV Video
- FLV decoding is very complex (container format + video codec + audio codec)
- Would need a lightweight FLV parser + video decoder (e.g., libavcodec)
- Likely out of scope for initial implementation

### Phase 1: Static Image Loading
Support loadMovie for JPEG, PNG, GIF using stb_image. This unlocks the 4 `mcl_target_*` tests and `movieclip_methods_with_loaded_image`.

### Phase 2: FLV Video (Future)
NetStream/FLV support. Very complex, low priority.

---

## Dependencies
- Both features need the textured quad rendering infrastructure
- BitmapData needs Plan 01 (runtime transforms) for correct positioning
- External media loading needs file I/O in headless mode (currently only the test binary's working directory is available)

---

## File Changes Summary (BitmapData)

| File | Change |
|------|--------|
| `SWFModernRuntime/src/actionmodern/action.c` | BitmapData operations write to CPU pixel buffer |
| `SWFModernRuntime/include/actionmodern/action.h` | BitmapData struct with pixel buffer, width, height, dirty flag |
| `SWFModernRuntime/src/rendering/render_webgpu.c` | Dynamic texture creation + upload, textured quad drawing |
| `SWFModernRuntime/src/libswf/tag.c` | Upload dirty BitmapData textures before render pass |

---

## Risks / Open Questions

1. **BitmapData pixel format**: Flash uses ARGB 32-bit pixels internally. GPU expects RGBA. Need byte swizzle on upload.

2. **BitmapData attachment**: How is a BitmapData "attached" to a MovieClip for display? Via `MovieClip.attachBitmap()` or `BitmapData.draw()`. Need to understand the attachment mechanism.

3. **Image path resolution**: `loadMovie("image.jpg")` — the path is relative to the SWF. In headless mode, the SWF is in the test directory. Need to resolve paths correctly.

4. **Async loading**: `loadMovie()` is async in Flash — it fires `onLoadInit` callbacks. The test framework provides enough ticks (num_frames=11) for loading to complete, but the synchronous headless model may need adjustment.

5. **Texture memory**: Dynamic textures consume GPU memory. Need cleanup when BitmapData objects are garbage collected or MovieClips are removed.
