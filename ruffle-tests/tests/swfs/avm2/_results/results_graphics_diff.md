# Ruffle Test Results Diff

**Previous:** `fb36ba11005c` (2026-08-06T23:55:08.621945+00:00)
**Current:** `bf585e4486b6` (2026-08-12T23:11:20.629626+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1109 | 1123 | +14 |
| Total | 1226 | 1240 | +14 |
| Pass rate | 90.5% | 90.6% | +0.1% |
| Mismatched lines | 30384 | 31398 | +1014 |
|   Decreased | | | -766 |
|   Increased | | | +442 |

## Newly Passing (12)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `all_classes/display3D/swf12` | output_mismatch | 1/61 | 61/61 |
| `all_classes/errors/swf10` | output_mismatch | 6/140 | 140/140 |
| `all_classes/errors/swf30` | output_mismatch | 6/140 | 140/140 |
| `all_classes/errors/swf9` | output_mismatch | 1/121 | 121/121 |
| `all_classes/security/swf12` | output_mismatch | 0/19 | 19/19 |
| `all_classes/security/swf13` | output_mismatch | 0/53 | 53/53 |
| `all_classes/security/swf30` | output_mismatch | 0/53 | 53/53 |
| `describe_type_metadata` | output_mismatch | 5/125 | 125/125 |
| `describe_type_native` | output_mismatch | 1/23 | 23/23 |
| `netstream_flv_date` | output_mismatch | 2/4 | 4/4 |
| `sound_constructor_with_args` | output_mismatch | 2/6 | 6/6 |
| `sound_rootless` | output_mismatch | 5/7 | 7/7 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `textblock_line_changes` | ruffle_matched | output_mismatch | 240/282 | 119/481 |

## Added Tests (14)

| Test | Status | Lines |
|------|--------|-------|
| `automation_classes` | output_mismatch | 1/122 |
| `matrix3d_append` | output_mismatch | 0/16 |
| `matrix3d_append_rotation` | output_mismatch | 0/23 |
| `matrix3d_copy_column` | output_mismatch | 24/83 |
| `matrix3d_copy_raw_data_from` | output_mismatch | 0/55 |
| `matrix3d_copy_raw_data_to` | output_mismatch | 0/38 |
| `matrix3d_copy_row` | output_mismatch | 24/83 |
| `matrix3d_position` | pass | 19/19 |
| `matrix3d_prepend` | output_mismatch | 0/16 |
| `matrix3d_recompose_edge_cases` | output_mismatch | 0/198 |
| `matrix3d_transform_vector` | output_mismatch | 36/52 |
| `matrix3d_transpose` | pass | 5/5 |
| `textblock_releaselines` | output_mismatch | 41/752 |
| `textline_raw_text_length` | output_mismatch | 4/30 |

## Line Count Changed (21)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `all_classes/events/swf30` | output_mismatch | 0/2353 | 17/2353 | -17 |
| `all_classes/display/swf11` | output_mismatch | 15/2593 | 19/2593 | -4 |
| `all_classes/display/swf12` | output_mismatch | 15/2593 | 19/2593 | -4 |
| `all_classes/display/swf13` | output_mismatch | 12/2671 | 16/2671 | -4 |
| `all_classes/display/swf30` | output_mismatch | 7/2936 | 10/2936 | -3 |
| `all_classes/display3D/swf13` | output_mismatch | 3/326 | 6/326 | -3 |
| `all_classes/accessibility/swf10` | output_mismatch | 5/88 | 7/88 | -2 |
| `all_classes/accessibility/swf30` | output_mismatch | 5/88 | 7/88 | -2 |
| `all_classes/accessibility/swf9` | output_mismatch | 5/73 | 7/73 | -2 |
| `all_classes/display/swf9` | output_mismatch | 7/1959 | 9/1959 | -2 |
| `netstream_play_flv` | output_mismatch | 0/16 | 0/16 | 0 |
| `netstream_seek_flv` | output_mismatch | 0/49 | 0/49 | 0 |
| `all_classes/display/swf10` | output_mismatch | 12/2569 | 11/2569 | +1 |
| `all_classes/events/swf9` | output_mismatch | 11/1030 | 8/1030 | +3 |
| `all_classes/display3D/swf30` | output_mismatch | 12/412 | 8/412 | +4 |
| `all_classes/xml/swf30` | output_mismatch | 9/116 | 5/116 | +4 |
| `all_classes/xml/swf9` | output_mismatch | 9/116 | 5/116 | +4 |
| `all_classes/events/swf10` | output_mismatch | 13/1638 | 5/1638 | +8 |
| `all_classes/events/swf11` | output_mismatch | 13/1750 | 5/1750 | +8 |
| `all_classes/events/swf12` | output_mismatch | 13/1814 | 5/1814 | +8 |
| `textblock_recreateline` | output_mismatch | 39/98 | 39/180 | +82 |
