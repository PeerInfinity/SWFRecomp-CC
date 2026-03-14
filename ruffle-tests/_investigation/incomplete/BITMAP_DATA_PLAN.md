# BitmapData Implementation Plan
<!-- TESTS: bitmap_data, bitmap_data_colortransform, bitmap_data_compare, bitmap_data_copypixels, bitmap_data_fillrect, bitmap_data_hittest, bitmap_data_max_size_swf9, bitmap_data_max_size_swf10, bitmap_data_noise, bitmap_data_perlinnoise, bitmap_data_pixeldissolve, bitmap_data_pixeldissolve_image, bitmap_data_threshold, bitmap_filters, bitmapdata_applyfilter_colormatrix, bitmapdata_channels, textfield_cache_as_bitmap -->

Last updated: 2026-03-13

## Status: INCOMPLETE — 10/17 tests passing, Phase 1 mostly done

### Current Results

| Test | Lines | Status | Notes |
|------|-------|--------|-------|
| bitmap_data_fillrect | 0 | **PASS** | 0 expected lines |
| bitmap_data_colortransform | 0 | **PASS** | 0 expected lines |
| bitmap_data_perlinnoise | 0 | **PASS** | 0 expected lines |
| bitmapdata_applyfilter_colormatrix | 0 | **PASS** | 0 expected lines |
| bitmap_data_pixeldissolve_image | 0 | **PASS** | 0 expected lines (image comparison) |
| bitmap_data_max_size_swf9 | 10 | **PASS** | Constructor validation |
| bitmap_data_max_size_swf10 | 12 | **PASS** | Constructor validation |
| textfield_cache_as_bitmap | 1 | **PASS** | Property existence check |
| bitmapdata_channels | 19 | **PASS** | Channel constants + flags ✅ NEW |
| bitmap_data_compare | 41 | **PASS** | compare() method ✅ NEW |
| bitmap_data | 1126 | FAIL (1/1126 diff) | 1 getColorBoundsRect line off |
| bitmap_data_copypixels | 17 | FAIL (5 diff) | Premultiply precision in copied pixels |
| bitmap_data_noise | 631 | FAIL (4 diff) | noise(low>high) edge case |
| bitmap_data_threshold | 176 | FAIL (129 diff) | copySource path not copying pixels |
| bitmap_data_hittest | 133 | SEGFAULT | Crash in hitTest edge cases |
| bitmap_data_pixeldissolve | 1075 | FAIL (1967 diff) | PRNG algorithm mismatch |
| bitmap_filters | 548 | SEGFAULT | Filter .clone() crash |

### What was implemented

Full BitmapData pixel buffer with premultiplied alpha:
- `BitmapDataNative` struct with `uint32_t* pixels`, width, height, transparent, disposed
- `void* native_data` field added to ASObject for native backing storage
- Constructor validates dimensions, allocates pixel buffer, handles transparent/fill args
- Read-only properties: width, height, transparent, rectangle (intercepted in actionGetMember)
- Write protection in actionSetMember for width/height/transparent/rectangle
- Pixel read: unpremultiplyAlpha on getPixel/getPixel32
- Pixel write: premultiplyAlpha on setPixel/setPixel32/fillRect/floodFill/noise
- Prototype methods: getPixel, getPixel32, setPixel, setPixel32, fillRect, clone, dispose, copyChannel, floodFill, colorTransform, getColorBoundsRect, noise, compare, copyPixels, threshold, hitTest, pixelDissolve + stubs for draw/scroll/merge/etc.
- Disposed state returns -1 for most operations
- Channel constants (RED/GREEN/BLUE/ALPHA_CHANNEL) on BitmapData constructor's own_props
- BitmapData prototype chain → Object.prototype
- doubleToUint32 helper for proper ECMA-262 ToUint32 conversion
- Fixed actionDelete to handle FUNCTION type (operate on own_props)

---

## Remaining Blockers

### 1. bitmap_data (1/1126 diff)
**getColorBoundsRect**: Line 883 returns `(0,0,1,1)` instead of `(0,0,0,0)`. Pixel state tracking issue — the test recreates bitmaps between getColorBoundsRect calls but the bitmap state differs by 1 pixel. Root cause unclear.

### 2. bitmap_data_copypixels (5/17 diff)
**Premultiply precision**: Copied pixels show different values due to premultiply→unpremultiply round-trip losses. Needs investigation into whether copyPixels should copy raw premultiplied data or un-multiply then re-premultiply.

### 3. bitmap_data_noise (4/631 diff)
**noise(low > high)**: When `low > high`, Flash appears to fill with `low` value (or no-op). Our Lehmer PRNG generates wrapped values. Fix: handle `low >= high` edge case.

### 4. bitmap_data_threshold (129/176 diff)
**copySource not working**: The threshold `copySource=true` path isn't copying source pixels when threshold fails. Root cause: arg ordering or validation logic preventing the copy path from executing. Needs deeper investigation of how the prototype method receives args.

### 5. bitmap_data_hittest (SEGFAULT)
**Crash in hitTest edge cases**: Likely accessing invalid memory when hitTest gets unusual arguments (valueOf objects, undefined params). Needs defensive null checks.

### 6. bitmap_data_pixeldissolve (1967/1075 diff — more diff lines than expected lines)
**PRNG mismatch**: The pixelDissolve algorithm doesn't match Flash's visited-pixel tracking. Flash uses a specific pattern for selecting unvisited pixels that our simple `rng % total` approach doesn't replicate.

### 7. bitmap_filters (SEGFAULT)
**Filter .clone() crash**: Not BitmapData-specific — filter objects (BevelFilter, BlurFilter etc.) don't have clone() methods, causing NULL dereference. Separate issue from BitmapData.

---

## Implementation Priority (remaining work)

1. **noise edge case** (4 lines) — Handle low >= high in noise PRNG
2. **threshold copySource** (129 lines) — Debug arg passing to threshold method
3. **copypixels precision** (5 lines) — Fix premultiply round-trip
4. **getColorBoundsRect** (1 line) — Very subtle state tracking issue
5. **hitTest segfault** (133 lines) — Add null checks, fix arg parsing
6. **pixelDissolve PRNG** (1075 lines) — Requires exact Flash visited-pixel tracking algorithm
7. **bitmap_filters** (548 lines) — Separate issue, needs filter .clone() implementation
