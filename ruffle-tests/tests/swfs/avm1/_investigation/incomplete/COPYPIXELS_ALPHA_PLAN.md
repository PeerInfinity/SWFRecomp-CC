# copyPixels Alpha Bitmap Path Plan
<!-- TESTS: bitmap_data_copypixels (image) -->

<!-- PLAN_META
id: COPYPIXELS_ALPHA
status: not_started
phases:
  - id: 1
    name: "Implement copyPixels alpha bitmap path"
    status: not_started
  - id: 2
    name: "Implement merge() method"
    status: not_started
dependencies: []
blockers: []
-->

Last updated: 2026-03-29

## Status: NOT STARTED

### Problem

The `bitmap_data_copypixels` headless image test has 190,726 outlier pixels. The trace test passes (17/17 lines), but the image fails because the test's second half uses `copyPixels` with an **alpha bitmap** argument, which is not implemented.

**Current image result:** 190,726 outliers, max diff 255

### Root Cause

The test calls (from ActionScript):
```actionscript
dest.copyPixels(src, new Rectangle(0,0,80,20), new Point(10, 50), alpha, new Point(0,0), merge);
```

This is the 6-argument form of `copyPixels`:
1. `sourceBitmap` — source pixels
2. `sourceRect` — region to copy
3. `destPoint` — where to write
4. `alphaBitmap` — alpha source for blending
5. `alphaPoint` — offset into alpha bitmap
6. `mergeAlpha` — whether to blend with existing dest pixels

Our `bitmapDataCopyPixels` at `action.c:8567` only handles args 0-2 (source, rect, point) and arg 5 (mergeAlpha flag). **Args 3-4 (alpha bitmap + point) are completely ignored.** When an alpha bitmap is provided, the copy should use the alpha bitmap's pixel values to modulate the source before writing to dest.

### Algorithm

When `alphaBitmap` is provided (Ruffle reference: `copy_pixels_with_alpha_source` in `operations.rs`):

For each pixel in sourceRect:
1. Read source pixel (premultiplied ARGB)
2. Read alpha bitmap pixel at corresponding position + alphaPoint offset
3. Extract alpha channel from alpha bitmap pixel
4. Multiply source pixel's alpha by the alpha bitmap's alpha: `final_alpha = src_alpha * ab_alpha / 255`
5. Scale source RGB by the same factor
6. If `mergeAlpha` is true: composite over destination using source-over blending
7. If `mergeAlpha` is false: replace destination pixel directly

### Also Needed: merge() Method

The `bitmapDataMerge` function at `action.c:9019` is also a stub. While it's NOT the cause of the copypixels image failure, it should be implemented for completeness.

**merge() algorithm** (per pixel, per channel):
```
new_channel = (src_channel * multiplier + dest_channel * (256 - multiplier)) / 256
```

Parameters: sourceBitmap, sourceRect, destPoint, redMult, greenMult, blueMult, alphaMult (all 0-256 range).

Works in unmultiplied alpha space. Uses u16 intermediates to avoid overflow.

### Implementation Steps

#### Step 1: copyPixels alpha bitmap path (~60 lines)

In `bitmapDataCopyPixels`, after the existing arg parsing:
1. Check if `arg_count >= 4` and `args[3].type == ACTION_STACK_VALUE_OBJECT`
2. Extract alpha BitmapData from args[3]
3. Parse alpha point from args[4] (default Point(0,0))
4. In the pixel loop, for each pixel:
   - Read alpha bitmap pixel at `(alpha_pt_x + sx, alpha_pt_y + sy)`
   - Extract alpha channel: `ab_alpha = (ab_pixel >> 24) & 0xFF`
   - Modulate source: scale src_alpha and src_rgb by `ab_alpha / 255`
   - If mergeAlpha: composite over dest (source-over in premul space)
   - Else: write directly

#### Step 2: merge() method (~50 lines)

1. Parse 7 arguments (source, rect, point, rMult, gMult, bMult, aMult)
2. Clamp multipliers to [0, 256]
3. For each pixel in region:
   - Unpremultiply source and dest
   - Blend: `new = (src * mult + dest * (256 - mult)) / 256` per channel
   - Premultiply result
   - Write to dest

### Key Ruffle Reference

| File | Function | Lines |
|------|----------|-------|
| `~/CC/ruffle/core/src/bitmap/operations.rs` | `copy_pixels_with_alpha_source` | ~1670-1765 |
| `~/CC/ruffle/core/src/bitmap/operations.rs` | `merge` | ~955-1039 |
| `~/CC/ruffle/core/src/avm1/globals/bitmap_data.rs` | `copy_pixels` (AVM1 entry) | ~548-620 |

### Estimated Complexity

Medium — ~110 lines total (60 for alpha path + 50 for merge).

### Expected Impact

Fixing the alpha bitmap path should fix most of the 190,726 outliers in the copypixels image test. The merge() method would fix any tests that call merge() directly (none currently identified as failing).
