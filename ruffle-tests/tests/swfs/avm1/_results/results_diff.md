# Ruffle Test Results Diff

**Previous:** `8f4f6e395305` (2026-11-25T03:59:19.140794+00:00)
**Current:** `10a5b515a03a` (2026-11-25T21:10:43.736545+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 754 | 767 | +13 |
| Total | 788 | 789 | +1 |
| Pass rate | 95.7% | 97.2% | +1.5% |
| Mismatched lines | 12439 | 12146 | -293 |
|   Decreased | | | -294 |
|   Increased | | | +1 |

## Newly Passing (13)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `asnative_sweep` | ruffle_matched | 1/74 | 74/74 |
| `bitmap_data_thorough/copyPixels` | ruffle_matched | 1135/1203 | 1203/1203 |
| `bitmap_data_thorough/paletteMap` | ruffle_matched | 883/951 | 951/951 |
| `bitmap_data_thorough/perlinNoise` | ruffle_matched | 8441/8481 | 8481/8481 |
| `bitmapdata_custom_rectangle` | ruffle_matched | 15/42 | 42/42 |
| `form_loader_encoding_4` | ruffle_matched | 1/3 | 3/3 |
| `goto_rewind_movieclip_replace` | ruffle_matched | 7/8 | 7/7 |
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

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `root_onload_loaded_level` | pass | 4/4 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `globals_swf5` | output_mismatch | 294/304 | 295/304 | -1 |
| `loadmovie_replace_root` | pass | 5/5 | 6/6 | 0 |
