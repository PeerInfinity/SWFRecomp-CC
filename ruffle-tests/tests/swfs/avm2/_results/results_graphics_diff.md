# Ruffle Test Results Diff

**Previous:** `3db858cbc157` (2026-08-13T22:38:36.641226+00:00)
**Current:** `86434112a759` (2026-08-15T09:18:14.408885+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1143 | 1154 | +11 |
| Total | 1240 | 1243 | +3 |
| Pass rate | 92.2% | 92.8% | +0.6% |
| Mismatched lines | 27726 | 12173 | -15553 |
|   Decreased | | | -15613 |
|   Increased | | | +2 |

## Newly Passing (12)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `all_classes/display/swf10` | output_mismatch | 31/2569 | 2569/2569 |
| `all_classes/display/swf11` | output_mismatch | 35/2593 | 2593/2593 |
| `all_classes/display/swf12` | output_mismatch | 35/2593 | 2593/2593 |
| `all_classes/display/swf13` | output_mismatch | 21/2671 | 2671/2671 |
| `all_classes/display/swf30` | output_mismatch | 14/2936 | 2936/2936 |
| `all_classes/display/swf9` | output_mismatch | 17/1959 | 1959/1959 |
| `bitmapdata_draw_alpha_erase` | output_mismatch | 6/8 | 8/8 |
| `delayed_symbolclass` | output_mismatch | 20/28 | 28/28 |
| `edittext_tag_indent` | output_mismatch | 38/49 | 49/49 |
| `geom_transform` | output_mismatch | 21/74 | 74/74 |
| `localconnection` | output_mismatch | 589/890 | 890/890 |
| `matrix` | output_mismatch | 282/338 | 338/338 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `verify_method_info_oob` | output_mismatch | 1/1 | 0/1 |

## Added Tests (3)

| Test | Status | Lines |
|------|--------|-------|
| `matrix3d_determinant` | output_mismatch | 149/182 |
| `matrix3d_precision` | output_mismatch | 5/25 |
| `matrix3d_raw_data` | output_mismatch | 28/33 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `displayobject_scrollrect` | output_mismatch | 19/33 | 27/33 | -8 |
| `loader_duplicate_class` | output_mismatch | 23/48 | 29/48 | -6 |
| `external_interface` | output_mismatch | 3/105 | 3/105 | 0 |
| `verify_method_info_duplicate` | output_mismatch | 1/2 | 0/2 | +1 |
