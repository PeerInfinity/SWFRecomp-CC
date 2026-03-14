# BitmapData Implementation Plan
<!-- TESTS: bitmap_data, bitmap_data_colortransform, bitmap_data_compare, bitmap_data_copypixels, bitmap_data_fillrect, bitmap_data_hittest, bitmap_data_max_size_swf9, bitmap_data_max_size_swf10, bitmap_data_noise, bitmap_data_perlinnoise, bitmap_data_pixeldissolve, bitmap_data_pixeldissolve_image, bitmap_data_threshold, bitmap_filters, bitmapdata_applyfilter_colormatrix, bitmapdata_channels, textfield_cache_as_bitmap -->

Last updated: 2026-03-13

## Status: INCOMPLETE — 10/17 tests passing (was 8/17), remaining tests blocked by complex issues

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
| bitmap_data_compare | 41 | **PASS** | compare() method ✅ NEW |
| bitmap_data_noise | 631 | **PASS** | noise() PRNG + edge cases ✅ NEW |
| bitmap_data | 1126 | FAIL (1/1126 diff) | 1 getColorBoundsRect line |
| bitmapdata_channels | 19 | FAIL (4/19 diff) | Channel prop flags need function delete |
| bitmap_data_copypixels | 17 | FAIL (5/17 diff) | Premultiply precision |
| bitmap_data_threshold | 176 | FAIL (129/176 diff) | copySource path not copying |
| bitmap_data_hittest | 133 | SEGFAULT | Crash in hitTest |
| bitmap_data_pixeldissolve | 1075 | FAIL (1967 diff) | PRNG algorithm mismatch |
| bitmap_filters | 548 | SEGFAULT | Filter .clone() crash |

### What was implemented

Full BitmapData native pixel buffer with premultiplied alpha:
- `BitmapDataNative` struct with pixel buffer, stored via side table (g_bitmap_natives[])
- Constructor validates dimensions, allocates/fills pixel buffer, handles transparent/fill
- Read-only properties: width, height, transparent, rectangle
- Pixel ops: getPixel/getPixel32 (unpremultiply), setPixel/setPixel32 (premultiply)
- Methods: fillRect, clone, dispose, copyChannel, floodFill, colorTransform, getColorBoundsRect, noise, compare, copyPixels, threshold, hitTest, pixelDissolve + stubs
- Disposed state returns -1
- Channel constants on constructor own_props
- Prototype chain with all methods
- doubleToUint32 for ECMA-262 ToUint32 conversion
- Noise: Lehmer PRNG with low > high edge case handling
- Compare: wrapping subtraction (not XOR), unpremultiply before comparison
- ColorTransform: requires native NATIVE_COLORTRANSFORM type

### Known regression

`native_subclasses`: 191→190 (1 line). `obj.isSubclass` returns undefined because BitmapData constructor's Function2Ptr path replaces `__proto__` without preserving user subclass properties.

---

## Remaining Blockers

### 1. bitmapdata_channels (4/19 diff) — BLOCKED
Channel constants need `delete func.property` support for FUNCTION type in actionDelete. Enabling this breaks `global_proto_decls_delete` (7000+ lines regressed) because function own_props properties are deletable by default. Fix requires: either marking built-in function properties as non-configurable, or filtering delete by property name/type.

### 2. bitmap_data (1/1126 diff) — LOW PRIORITY
Single getColorBoundsRect edge case. Root cause unclear.

### 3. bitmap_data_threshold (129/176 diff) — NEEDS INVESTIGATION
The `copySource=true` path should copy source pixels when threshold fails, but isn't working. Needs debugging of argument passing through prototype method dispatch.

### 4. bitmap_data_copypixels (5/17 diff) — NEEDS INVESTIGATION
Premultiply→unpremultiply round-trip precision causes pixel value differences.

### 5. bitmap_data_hittest (SEGFAULT) — NEEDS INVESTIGATION
Crash on edge cases (valueOf objects, undefined params).

### 6. bitmap_data_pixeldissolve (1967 diff) — BLOCKED
PRNG-based visited pixel tracking doesn't match Flash's algorithm. Would need reverse-engineering Flash's exact dissolution pattern.

### 7. bitmap_filters (SEGFAULT) — SEPARATE ISSUE
Filter .clone() not implemented. Not BitmapData-specific.
