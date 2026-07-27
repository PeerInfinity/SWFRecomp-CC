# Graphics vs Trace Mode Differences

Trace: 135/142 passing | Graphics: 121/142 passing

## Graphics Regressions (14 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `blend_modes/shader_as_mask` | Output Mismatch | 0/3 lines match |
| 2 | `cache_as_bitmap/bitmap_changed` | Output Mismatch | 0/6 lines match |
| 3 | `cache_as_bitmap/cab_mask_filters` | Output Mismatch | 0/2 lines match |
| 4 | `definefont4` | Output Mismatch | 0/14 lines match |
| 5 | `filters/blur_fractional` | Output Mismatch | 0/2 lines match |
| 6 | `filters/blur_pass_scaling` | Output Mismatch | 0/3 lines match |
| 7 | `filters/blur_quality` | Output Mismatch | 0/2 lines match |
| 8 | `filters/displacement_map` | Output Mismatch | 0/3 lines match |
| 9 | `filters/displacement_map_scales_with_screen` | Output Mismatch | 0/2 lines match |
| 10 | `filters/displacement_map_through_applyFilter` | Output Mismatch | 0/2 lines match |
| 11 | `filters/displacement_map_through_filters` | Output Mismatch | 0/2 lines match |
| 12 | `filters/glow_pass_scaling` | Output Mismatch | 0/3 lines match |
| 13 | `video/deblocking` | Runtime Error | exit code -6 |
| 14 | `video/h264` | Output Mismatch | 0/3 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
