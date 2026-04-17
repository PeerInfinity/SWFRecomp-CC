# Ruffle Test Results Diff

**Previous:** `f3ab5c9dd4cb` (2026-04-17T20:16:04.806651+00:00)
**Current:** `f238a909f91f` (2026-04-17T21:43:57.033307+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 580 | 581 | +1 |
| Total | 641 | 641 | 0 |
| Pass rate | 90.5% | 90.6% | +0.1% |
| Mismatched lines | 30572 | 19090 | -11482 |
|   Decreased | | | -11482 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bitmap_data_thorough/compare` | output_mismatch | 29/69 | 69/69 |

## Line Count Changed (18)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `bitmap_data_thorough/copyChannel` | output_mismatch | 49/2715 | 1815/2715 | -1766 |
| `bitmap_data_thorough/perlinNoise` | output_mismatch | 435/8481 | 2156/8481 | -1721 |
| `bitmap_data_thorough/noise` | output_mismatch | 29/1518 | 1189/1518 | -1160 |
| `bitmap_data_thorough/pixelDissolve` | output_mismatch | 28/1371 | 1075/1371 | -1047 |
| `bitmap_data_thorough/threshold` | output_mismatch | 31/1308 | 994/1308 | -963 |
| `bitmap_data_thorough/copyPixels` | output_mismatch | 23/1203 | 880/1203 | -857 |
| `bitmap_data_thorough/merge` | output_mismatch | 23/1203 | 852/1203 | -829 |
| `bitmap_data_thorough/floodFill` | output_mismatch | 18/867 | 674/867 | -656 |
| `bitmap_data_thorough/paletteMap` | output_mismatch | 18/951 | 664/951 | -646 |
| `bitmap_data_thorough/setPixel` | output_mismatch | 12/531 | 399/531 | -387 |
| `bitmap_data_thorough/setPixel32` | output_mismatch | 12/531 | 399/531 | -387 |
| `bitmap_data_thorough/scroll` | output_mismatch | 10/384 | 294/384 | -284 |
| `bitmap_data_thorough/fillRect` | output_mismatch | 9/342 | 244/342 | -235 |
| `bitmap_data_thorough/hitTest` | output_mismatch | 285/519 | 513/519 | -228 |
| `bitmap_data_thorough/colorTransform` | output_mismatch | 8/279 | 214/279 | -206 |
| `bitmap_data_thorough/getColorBoundsRect` | output_mismatch | 238/285 | 278/285 | -40 |
| `bitmap_data_thorough/getPixel` | output_mismatch | 111/141 | 126/141 | -15 |
| `bitmap_data_thorough/getPixel32` | output_mismatch | 111/141 | 126/141 | -15 |
