# BitmapData Implementation Plan
<!-- TESTS: bitmap_data, bitmap_data_colortransform, bitmap_data_compare, bitmap_data_copypixels, bitmap_data_fillrect, bitmap_data_hittest, bitmap_data_max_size_swf9, bitmap_data_max_size_swf10, bitmap_data_noise, bitmap_data_perlinnoise, bitmap_data_pixeldissolve, bitmap_data_pixeldissolve_image, bitmap_data_threshold, bitmap_filters, bitmapdata_applyfilter_colormatrix, bitmapdata_channels, textfield_cache_as_bitmap -->

<!-- PLAN_META
id: BITMAP_DATA
status: complete
phases:
  - id: 1
    name: "Core pixel buffer implementation"
    status: complete
  - id: 2
    name: "Pixel operations (get/setPixel)"
    status: complete
  - id: 3
    name: "Methods (fillRect, clone, dispose, etc.)"
    status: complete
dependencies: []
blockers: []
-->

Last updated: 2026-03-29

## Status: COMPLETE — 16/17 trace tests passing; bitmap_filters SEGFAULT is a separate filter issue

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
| bitmap_data_compare | 41 | **PASS** | compare() method ✅ |
| bitmap_data_noise | 631 | **PASS** | noise() PRNG + edge cases ✅ |
| native_subclasses | 191 | **PASS** | BitmapData subclass ✅ |
| bitmapdata_channels | 19 | **PASS** | Channel constants ✅ |
| bitmap_data | 1126 | **PASS** | getColorBoundsRect (0,0)-alone quirk fixed ✅ |
| bitmap_data_hittest | 132 | **PASS** | valueOf coercion via tsArgToDouble_ctx ✅ |
| bitmap_data_threshold | 176 | **PASS** | Self-threshold writes at source coords ✅ |
| bitmap_data_copypixels | 17 | **PASS** | Fixed — premultiply precision resolved |
| bitmap_data_pixeldissolve | 1075 | **PASS** | Fixed — Feistel network PRNG implemented (2026-03-29) |
| bitmap_filters | 548 | SEGFAULT | Filter .clone() crash (separate filter issue, not BitmapData) |

### What was implemented

Full BitmapData native pixel buffer with premultiplied alpha:
- `BitmapDataNative` struct with pixel buffer, stored via side table (`g_bitmap_natives[]`)
- Constructor validates dimensions, allocates/fills pixel buffer, handles transparent/fill
- Read-only properties: width, height, transparent, rectangle
- Pixel ops: getPixel/getPixel32 (unpremultiply), setPixel/setPixel32 (premultiply)
- Methods: fillRect, clone, dispose, copyChannel, floodFill, colorTransform, getColorBoundsRect, noise, compare, copyPixels, threshold, hitTest, pixelDissolve + stubs
- Disposed state returns -1; hitTest error codes: -2 (bad point), -3 (bad second), -4 (missing secondPoint)
- Channel constants on constructor own_props
- Prototype chain with all methods via `registerProtoMethod` (avoids function_registry pollution)
- `doubleToUint32` for ECMA-262 ToUint32 conversion
- Noise: Lehmer PRNG with low > high edge case handling
- Compare: wrapping subtraction (not XOR), unpremultiply before comparison
- ColorTransform: requires native NATIVE_COLORTRANSFORM type
- Point()/Rectangle() factory calls (without `new`) now return objects instead of undefined
- Function2Ptr constructor path preserves subclass `__proto__` chain
- getColorBoundsRect: Flash (0,0)-alone-as-none quirk (single match at pixel 0,0 treated as empty)
- hitTest: valueOf coercion via `tsArgToDouble_ctx` for point properties and threshold args
- threshold: self-threshold (src==dest) writes at source coordinates, ignoring destPoint; count includes all matching source pixels regardless of dest bounds

---

## Previously Blocked Items — Now Resolved

- **bitmap_data_copypixels**: Was 2/17 diff from premultiply precision. Now 17/17 PASS.
- **bitmap_data_pixeldissolve**: Was ~993 diff from PRNG mismatch. Fixed with Feistel network implementation (2026-03-29). Now 1075/1075 PASS.

## Out of Scope

- **bitmap_filters** (SEGFAULT): Filter `.clone()` not implemented. This is NOT a BitmapData issue — it's a missing method on filter objects. Should be tracked in a BITMAP_FILTERS plan.
