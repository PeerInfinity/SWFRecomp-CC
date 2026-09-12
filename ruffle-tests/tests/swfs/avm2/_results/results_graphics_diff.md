# Ruffle Test Results Diff

**Previous:** `f48c532bf170` (2026-09-12T00:02:29.983572+00:00)
**Current:** `521a53782850` (2026-09-12T01:30:44.539343+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1205 | 1213 | +8 |
| Total | 1274 | 1274 | 0 |
| Pass rate | 94.6% | 95.2% | +0.6% |
| Mismatched lines | 4044 | 2888 | -1156 |
|   Decreased | | | -1157 |
|   Increased | | | +1 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bitmapdata_copypixels_alpha_merge` | output_mismatch | 5/9 | 9/9 |
| `bitmapdata_copypixels_blend` | output_mismatch | 0/1029 | 1029/1029 |
| `bitmapdata_copypixels_self` | output_mismatch | 571/612 | 612/612 |
| `displayobject_getrect` | output_mismatch | 11/16 | 16/16 |
| `displayobject_z` | output_mismatch | 6/38 | 38/38 |
| `edittext_scroll_event` | output_mismatch | 2/37 | 37/37 |
| `geom_transform` | output_mismatch | 71/74 | 74/74 |
| `id3_info` | output_mismatch | 0/8 | 8/8 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `textblock_recreateline` | output_mismatch | 41/180 | 40/180 | +1 |
