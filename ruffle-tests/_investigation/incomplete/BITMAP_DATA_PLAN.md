# BitmapData Implementation Plan
<!-- TESTS: bitmap_data, bitmap_data_colortransform, bitmap_data_compare, bitmap_data_copypixels, bitmap_data_fillrect, bitmap_data_hittest, bitmap_data_max_size_swf9, bitmap_data_max_size_swf10, bitmap_data_noise, bitmap_data_perlinnoise, bitmap_data_pixeldissolve, bitmap_data_pixeldissolve_image, bitmap_data_threshold, bitmap_filters, bitmapdata_applyfilter_colormatrix, bitmapdata_channels, textfield_cache_as_bitmap -->

Last updated: 2026-03-14

## Status: INCOMPLETE — 12/17 tests passing (was 8/17)

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
| native_subclasses | 191 | **PASS** | BitmapData subclass ✅ RECOVERED |
| global_swf5_6_7_8_9 | 1145 | **PASS** | Cross-SWF globals ✅ RECOVERED |
| bitmap_data | 1126 | FAIL (1/1126 diff) | 1 getColorBoundsRect line |
| bitmapdata_channels | 19 | FAIL (4/19 diff) | Channel prop flags need function delete |
| bitmap_data_copypixels | 17 | FAIL (5/17 diff) | Premultiply precision |
| bitmap_data_threshold | 176 | FAIL (129/176 diff) | copySource path not copying |
| bitmap_data_hittest | 133 | SEGFAULT | Crash in hitTest edge cases |
| bitmap_data_pixeldissolve | 1075 | FAIL (1967 diff) | PRNG algorithm mismatch |
| bitmap_filters | 548 | SEGFAULT | Filter .clone() crash (separate issue) |

### What was implemented

Full BitmapData native pixel buffer with premultiplied alpha:
- `BitmapDataNative` struct with pixel buffer, stored via side table (`g_bitmap_natives[]`)
- Constructor validates dimensions, allocates/fills pixel buffer, handles transparent/fill
- Read-only properties: width, height, transparent, rectangle
- Pixel ops: getPixel/getPixel32 (unpremultiply), setPixel/setPixel32 (premultiply)
- Methods: fillRect, clone, dispose, copyChannel, floodFill, colorTransform, getColorBoundsRect, noise, compare, copyPixels, threshold, hitTest, pixelDissolve + stubs
- Disposed state returns -1
- Channel constants on constructor own_props
- Prototype chain with all methods via `registerProtoMethod` (avoids function_registry pollution)
- `doubleToUint32` for ECMA-262 ToUint32 conversion
- Noise: Lehmer PRNG with low > high edge case handling
- Compare: wrapping subtraction (not XOR), unpremultiply before comparison
- ColorTransform: requires native NATIVE_COLORTRANSFORM type
- Function2Ptr constructor path preserves subclass `__proto__` chain

### Key fixes applied
- `registerProtoMethod`: adds methods to prototype WITHOUT `function_registry`, fixing `global_swf5_6_7_8_9` regression caused by `lookupFunctionByName` collisions
- Function2Ptr BitmapData constructor no longer overwrites `__proto__`, fixing `native_subclasses` regression

---

## Remaining Items

### Actionable — NEEDS INVESTIGATION

#### bitmap_data_threshold (129/176 diff)
The `copySource=true` path should copy source pixels to dest when the threshold comparison fails, but isn't working. Likely a bug in how the 8th argument (`copySource`) is received through prototype method dispatch. Fixing this could gain up to 129 lines.

#### bitmap_data_hittest (SEGFAULT, 133 lines)
Crash on edge cases (valueOf objects, undefined params). Could be a simple null check fix. Fixing the segfault alone would recover partial line matches.

### Low priority

#### bitmap_data (1/1126 diff)
Single getColorBoundsRect edge case. Root cause unclear — very subtle state tracking issue. Not worth investigating for 1 line.

#### bitmap_data_copypixels (5/17 diff)
Premultiply→unpremultiply round-trip precision causes pixel value differences. Small gain (5 lines).

### Blocked

#### bitmapdata_channels (4/19 diff)
Channel constants need `delete func.property` support for FUNCTION type in `actionDelete`. Enabling this breaks `global_proto_decls_delete` (~8000 lines regressed) because function `own_props` properties are all CONFIGURABLE by default. Fix requires marking built-in function properties as non-configurable — a broader change affecting all constructors.

#### bitmap_data_pixeldissolve (1967 diff)
PRNG-based visited-pixel tracking doesn't match Flash's algorithm. Would require reverse-engineering Flash's exact dissolution pattern (Lehmer RNG position selection with visited-pixel bitmask).

#### bitmap_filters (SEGFAULT, 548 lines)
Filter `.clone()` not implemented. This is NOT a BitmapData issue — it's a missing method on filter objects (BevelFilter, BlurFilter, etc.). Should be tracked separately.
