# Ruffle Test Results Diff

**Previous:** `f238a909f91f` (2026-04-17T21:43:57.033307+00:00)
**Current:** `8a50e569da3e` (2026-04-18T00:16:44.588410+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 581 | 593 | +12 |
| Total | 641 | 641 | 0 |
| Pass rate | 90.6% | 92.5% | +1.9% |
| Mismatched lines | 19090 | 15483 | -3607 |
|   Decreased | | | -3608 |
|   Increased | | | +1 |

## Newly Passing (12)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bitmap_data_thorough/colorTransform` | output_mismatch | 214/279 | 279/279 |
| `bitmap_data_thorough/constructor` | output_mismatch | 21/313 | 313/313 |
| `bitmap_data_thorough/fillRect` | output_mismatch | 244/342 | 342/342 |
| `bitmap_data_thorough/floodFill` | output_mismatch | 674/867 | 867/867 |
| `bitmap_data_thorough/getColorBoundsRect` | output_mismatch | 278/285 | 285/285 |
| `bitmap_data_thorough/getPixel` | output_mismatch | 126/141 | 141/141 |
| `bitmap_data_thorough/getPixel32` | output_mismatch | 126/141 | 141/141 |
| `bitmap_data_thorough/hitTest` | output_mismatch | 513/519 | 519/519 |
| `bitmap_data_thorough/merge` | output_mismatch | 852/1203 | 1203/1203 |
| `bitmap_data_thorough/scroll` | output_mismatch | 294/384 | 384/384 |
| `bitmap_data_thorough/setPixel` | output_mismatch | 399/531 | 531/531 |
| `bitmap_data_thorough/setPixel32` | output_mismatch | 399/531 | 531/531 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `bitmap_data_thorough/copyPixels` | output_mismatch | ruffle_matched | 880/1203 | 1135/1203 |

## Line Count Changed (7)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `bitmap_data_thorough/copyChannel` | output_mismatch | 1815/2715 | 2537/2715 | -722 |
| `bitmap_data_thorough/perlinNoise` | output_mismatch | 2156/8481 | 2507/8481 | -351 |
| `bitmap_data_thorough/noise` | output_mismatch | 1189/1518 | 1426/1518 | -237 |
| `bitmap_data_thorough/paletteMap` | output_mismatch | 664/951 | 899/951 | -235 |
| `bitmap_data_thorough/threshold` | output_mismatch | 994/1308 | 1222/1308 | -228 |
| `bitmap_data_thorough/pixelDissolve` | output_mismatch | 1075/1371 | 1259/1371 | -184 |
| `movieclip_hittest_shapeflag` | output_mismatch | 329/338 | 328/338 | +1 |
