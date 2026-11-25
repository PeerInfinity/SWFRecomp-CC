# Ruffle Test Results Diff

**Previous:** `13b40eabb012` (2026-11-25T20:23:11.819281+00:00)
**Current:** `10a5b515a03a` (2026-11-25T21:42:12.041292+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 756 | 767 | +11 |
| Total | 789 | 789 | 0 |
| Pass rate | 95.8% | 97.2% | +1.4% |
| Mismatched lines | 12441 | 12146 | -295 |
|   Decreased | | | -296 |
|   Increased | | | +1 |

## Newly Passing (12)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `asnative_sweep` | ruffle_matched | 1/74 | 74/74 |
| `bitmap_data_thorough/copyPixels` | ruffle_matched | 1135/1203 | 1203/1203 |
| `bitmap_data_thorough/paletteMap` | ruffle_matched | 883/951 | 951/951 |
| `bitmap_data_thorough/perlinNoise` | ruffle_matched | 8441/8481 | 8481/8481 |
| `bitmapdata_custom_rectangle` | ruffle_matched | 15/42 | 42/42 |
| `form_loader_encoding_4` | ruffle_matched | 1/3 | 3/3 |
| `mcl_replace_root_swf7_to_swf5` | ruffle_matched | 56/57 | 57/57 |
| `mcl_replace_root_swf7_to_swf6` | ruffle_matched | 52/57 | 57/57 |
| `textfield_props_swf5` | ruffle_matched | 173/175 | 175/175 |
| `virtual_property_recursion_swf6` | ruffle_matched | 5/6 | 6/6 |
| `watch_recursion_double_swf6` | ruffle_matched | 42/46 | 46/46 |
| `watch_recursion_swf6` | ruffle_matched | 17/18 | 18/18 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `boxed_primitives` | output_mismatch | 24/24 | 23/24 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `movieclip_hittest_shapeflag` | output_mismatch | 329/338 | 332/338 | -3 |
| `globals_swf5` | output_mismatch | 294/304 | 295/304 | -1 |
