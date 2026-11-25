# Graphics vs Trace Mode Differences

Trace: 767/789 passing | Graphics: 756/789 passing

## Graphics Regressions (12 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `asnative_sweep` | Ruffle Matched | 1/74 lines match |
| 2 | `bitmap_data_thorough/copyPixels` | Ruffle Matched | 1135/1203 lines match |
| 3 | `bitmap_data_thorough/paletteMap` | Ruffle Matched | 883/951 lines match |
| 4 | `bitmap_data_thorough/perlinNoise` | Ruffle Matched | 8441/8481 lines match |
| 5 | `bitmapdata_custom_rectangle` | Ruffle Matched | 15/42 lines match |
| 6 | `form_loader_encoding_4` | Ruffle Matched | 1/3 lines match |
| 7 | `mcl_replace_root_swf7_to_swf5` | Ruffle Matched | 56/57 lines match |
| 8 | `mcl_replace_root_swf7_to_swf6` | Ruffle Matched | 52/57 lines match |
| 9 | `textfield_props_swf5` | Ruffle Matched | 173/175 lines match |
| 10 | `virtual_property_recursion_swf6` | Ruffle Matched | 5/8 lines match |
| 11 | `watch_recursion_double_swf6` | Ruffle Matched | 42/46 lines match |
| 12 | `watch_recursion_swf6` | Ruffle Matched | 17/18 lines match |

## Graphics Improvements (1 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `boxed_primitives` | Output Mismatch | 23/24 lines match |
