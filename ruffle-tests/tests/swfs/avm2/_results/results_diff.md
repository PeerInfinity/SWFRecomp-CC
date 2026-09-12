# Ruffle Test Results Diff

**Previous:** `ea6960eacaf6` (2026-09-11T18:44:39.888736+00:00)
**Current:** `d8da5a18c354` (2026-09-12T03:19:52.786472+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1200 | 1212 | +12 |
| Total | 1270 | 1274 | +4 |
| Pass rate | 94.5% | 95.1% | +0.6% |
| Mismatched lines | 3119 | 2890 | -229 |
|   Decreased | | | -354 |
|   Increased | | | +3 |

## Newly Passing (11)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bitmap_filter_abstract` | output_mismatch | 0/6 | 6/6 |
| `bitmapdata_copypixels_alpha_merge` | ruffle_matched | 5/9 | 9/9 |
| `bytearray_bad_symbol_class` | output_mismatch | 1/3 | 3/3 |
| `bytearray_bad_symbol_class_other_movie` | output_mismatch | 4/6 | 6/6 |
| `displayobject_getrect` | output_mismatch | 11/16 | 16/16 |
| `displayobject_z` | output_mismatch | 6/38 | 38/38 |
| `edittext_scroll_event` | output_mismatch | 2/37 | 37/37 |
| `geom_transform` | output_mismatch | 71/74 | 74/74 |
| `id3_info` | output_mismatch | 0/8 | 8/8 |
| `json_parse_errors` | output_mismatch | 4/84 | 84/84 |
| `matrix3d_append_rotation` | ruffle_matched | 22/23 | 23/23 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `mouse_pick_avm1_root` | output_mismatch | 2/2 | 0/2 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `json_parse_numbers` | output_mismatch | ruffle_matched | 31/131 | 127/131 |
| `loader_events_2` | output_mismatch | ruffle_matched | 2/35 | 5/35 |

## Added Tests (5)

| Test | Status | Lines |
|------|--------|-------|
| `bitmapdata_copypixels_blend` | pass | 1029/1029 |
| `bitmapdata_copypixels_self` | pass | 612/612 |
| `goto_framescript_queued/swf10` | output_mismatch | 15/59 |
| `goto_framescript_queued/swf13` | ruffle_matched | 17/59 |
| `goto_framescript_queued/swf9` | output_mismatch | 11/52 |

## Removed Tests (1)

| Test | Previous Status | Lines |
|------|----------------|-------|
| `goto_framescript_queued` | ruffle_matched | 1/6 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `matrix3d_recompose_edge_cases` | ruffle_matched | 113/198 | 190/198 | -77 |
| `textblock_recreateline` | output_mismatch | 41/180 | 40/180 | +1 |
