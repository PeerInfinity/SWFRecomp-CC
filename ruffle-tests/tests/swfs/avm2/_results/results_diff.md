# Ruffle Test Results Diff

**Previous:** `0a99be1a92de` (2026-08-09T08:51:22.890105+00:00)
**Current:** `88ebde66534f` (2026-08-16T08:44:05.407127+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1109 | 1153 | +44 |
| Total | 1227 | 1251 | +24 |
| Pass rate | 90.4% | 92.2% | +1.8% |
| Mismatched lines | 30505 | 12604 | -17901 |
|   Decreased | | | -18565 |
|   Increased | | | +96 |

## Newly Passing (36)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `accessibilityimplementation` | output_mismatch | 0/18 | 18/18 |
| `all_classes/accessibility/swf10` | output_mismatch | 5/88 | 88/88 |
| `all_classes/accessibility/swf30` | output_mismatch | 5/88 | 88/88 |
| `all_classes/accessibility/swf9` | output_mismatch | 5/73 | 73/73 |
| `all_classes/display/swf10` | output_mismatch | 12/2569 | 2569/2569 |
| `all_classes/display/swf11` | output_mismatch | 15/2593 | 2593/2593 |
| `all_classes/display/swf12` | output_mismatch | 15/2593 | 2593/2593 |
| `all_classes/display/swf13` | output_mismatch | 12/2671 | 2671/2671 |
| `all_classes/display/swf30` | output_mismatch | 7/2936 | 2936/2936 |
| `all_classes/display/swf9` | output_mismatch | 7/1959 | 1959/1959 |
| `all_classes/display3D/swf12` | output_mismatch | 1/61 | 61/61 |
| `all_classes/display3D/swf13` | output_mismatch | 3/326 | 326/326 |
| `all_classes/display3D/swf30` | output_mismatch | 12/412 | 412/412 |
| `all_classes/errors/swf10` | output_mismatch | 6/140 | 140/140 |
| `all_classes/errors/swf30` | output_mismatch | 6/140 | 140/140 |
| `all_classes/errors/swf9` | output_mismatch | 1/121 | 121/121 |
| `all_classes/security/swf12` | output_mismatch | 0/19 | 19/19 |
| `all_classes/security/swf13` | output_mismatch | 0/53 | 53/53 |
| `all_classes/security/swf30` | output_mismatch | 0/53 | 53/53 |
| `all_classes/xml/swf30` | output_mismatch | 9/116 | 116/116 |
| `all_classes/xml/swf9` | output_mismatch | 9/116 | 116/116 |
| `bitmapdata_draw_alpha_erase` | output_mismatch | 6/8 | 8/8 |
| `delayed_symbolclass` | output_mismatch | 20/28 | 28/28 |
| `describe_type_metadata` | output_mismatch | 5/125 | 125/125 |
| `describe_type_native` | output_mismatch | 1/23 | 23/23 |
| `edittext_tag_indent` | output_mismatch | 38/49 | 49/49 |
| `geom_transform` | output_mismatch | 21/74 | 74/74 |
| `int_toprecision` | ruffle_matched | 684/1125 | 1125/1125 |
| `localconnection` | output_mismatch | 589/890 | 890/890 |
| `matrix` | output_mismatch | 282/338 | 338/338 |
| `netstream_flv_date` | output_mismatch | 2/4 | 4/4 |
| `number_convert_edge_cases` | output_mismatch | 148/180 | 180/180 |
| `sound_constructor_with_args` | output_mismatch | 2/6 | 6/6 |
| `sound_rootless` | output_mismatch | 5/7 | 7/7 |
| `sub_super_same_field` | output_mismatch | 6/12 | 12/12 |
| `uint_toprecision` | ruffle_matched | 692/1125 | 1125/1125 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `coerce_string_precision` | output_mismatch | 28/28 | 25/28 |
| `divide` | output_mismatch | 1058/1058 | 1048/1058 |

## Added Tests (24)

| Test | Status | Lines |
|------|--------|-------|
| `matrix3d_append` | pass | 16/16 |
| `matrix3d_append_prepend_scale` | output_mismatch | 0/86 |
| `matrix3d_append_prepend_translation` | output_mismatch | 10/42 |
| `matrix3d_append_rotation` | ruffle_matched | 22/23 |
| `matrix3d_constructor_clone` | output_mismatch | 14/15 |
| `matrix3d_copy_column` | pass | 83/83 |
| `matrix3d_copy_from` | output_mismatch | 12/19 |
| `matrix3d_copy_raw_data_from` | pass | 55/55 |
| `matrix3d_copy_raw_data_to` | pass | 38/38 |
| `matrix3d_copy_row` | pass | 83/83 |
| `matrix3d_copy_to_matrix3d` | output_mismatch | 12/19 |
| `matrix3d_determinant` | output_mismatch | 149/182 |
| `matrix3d_interpolate` | output_mismatch | 0/21 |
| `matrix3d_position` | pass | 19/19 |
| `matrix3d_precision` | output_mismatch | 5/28 |
| `matrix3d_prepend` | pass | 16/16 |
| `matrix3d_raw_data` | output_mismatch | 28/33 |
| `matrix3d_recompose_edge_cases` | ruffle_matched | 113/198 |
| `matrix3d_transform_vector` | pass | 52/52 |
| `matrix3d_transpose` | pass | 5/5 |
| `number_to_string` | output_mismatch | 103/353 |
| `textblock_releaselines` | ruffle_matched | 748/752 |
| `textline_raw_text_length` | pass | 30/30 |
| `vector3d_near_equals` | output_mismatch | 67/80 |

## Line Count Changed (13)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `all_classes/events/swf30` | output_mismatch | 0/2353 | 25/2353 | -25 |
| `avm1_root` | output_mismatch | 0/58 | 12/58 | -12 |
| `displayobject_scrollrect` | output_mismatch | 19/33 | 27/33 | -8 |
| `loader_duplicate_class` | output_mismatch | 23/48 | 29/48 | -6 |
| `all_classes/events/swf10` | output_mismatch | 13/1638 | 15/1638 | -2 |
| `all_classes/events/swf11` | output_mismatch | 13/1750 | 15/1750 | -2 |
| `all_classes/events/swf12` | output_mismatch | 13/1814 | 15/1814 | -2 |
| `external_interface` | output_mismatch | 3/105 | 3/105 | 0 |
| `netstream_play_flv` | output_mismatch | 0/16 | 0/16 | 0 |
| `netstream_seek_flv` | output_mismatch | 0/49 | 0/49 | 0 |
| `all_classes/events/swf9` | output_mismatch | 11/1030 | 10/1030 | +1 |
| `textblock_line_changes` | ruffle_matched | 240/282 | 437/481 | +2 |
| `textblock_recreateline` | output_mismatch | 39/98 | 41/180 | +80 |
