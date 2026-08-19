# Ruffle Test Results Diff

**Previous:** `88ebde66534f` (2026-08-16T08:44:05.407127+00:00)
**Current:** `9d038c750eaf` (2026-08-19T13:28:58.991675+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1153 | 1179 | +26 |
| Total | 1251 | 1251 | 0 |
| Pass rate | 92.2% | 94.2% | +2.0% |
| Mismatched lines | 12604 | 3490 | -9114 |
|   Decreased | | | -9118 |
|   Increased | | | +4 |

## Newly Passing (27)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `all_classes/events/swf10` | output_mismatch | 15/1638 | 1638/1638 |
| `all_classes/events/swf11` | output_mismatch | 15/1750 | 1750/1750 |
| `all_classes/events/swf12` | output_mismatch | 15/1814 | 1814/1814 |
| `all_classes/events/swf30` | output_mismatch | 25/2353 | 2353/2353 |
| `all_classes/events/swf9` | output_mismatch | 10/1030 | 1030/1030 |
| `appdomain_lookup_edge_cases` | output_mismatch | 7/32 | 32/32 |
| `automation_classes` | output_mismatch | 1/122 | 122/122 |
| `button_nested_frame_simple` | output_mismatch | 27/27 | 27/27 |
| `coerce_string_precision` | output_mismatch | 25/28 | 28/28 |
| `displayobject_early_init` | output_mismatch | 1/54 | 54/54 |
| `displayobject_hittestpoint_boundary` | output_mismatch | 47/65 | 65/65 |
| `displayobject_scrollrect` | output_mismatch | 27/33 | 33/33 |
| `displayobject_transform` | output_mismatch | 67/89 | 89/89 |
| `divide` | output_mismatch | 1048/1058 | 1058/1058 |
| `large_preload_from_url` | output_mismatch | 16/27 | 27/27 |
| `large_preload_image_from_bytes` | output_mismatch | 19/25 | 25/25 |
| `matrix3d_append_prepend_translation` | output_mismatch | 10/42 | 42/42 |
| `matrix3d_constructor_clone` | output_mismatch | 14/15 | 15/15 |
| `matrix3d_determinant` | output_mismatch | 149/182 | 182/182 |
| `matrix3d_precision` | output_mismatch | 5/28 | 28/28 |
| `matrix3d_raw_data` | output_mismatch | 28/33 | 33/33 |
| `method_association` | output_mismatch | 1/5 | 5/5 |
| `mouse_pick_avm1_root` | output_mismatch | 1/2 | 2/2 |
| `native_menu_basic` | output_mismatch | 0/19 | 19/19 |
| `scope_optimizations` | output_mismatch | 3/4 | 4/4 |
| `supercalls_coerce` | output_mismatch | 1/8 | 8/8 |
| `textfield_input_events` | output_mismatch | 9/25 | 25/25 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `getouterscope_two_classobjects` | ruffle_matched | 13/13 | 9/13 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `bounds_mode` | output_mismatch | ruffle_matched | 253/269 | 263/269 |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `number_to_string` | output_mismatch | 103/353 | 237/353 | -134 |
| `large_preload_from_bytes` | output_mismatch | 18/51 | 35/51 | -17 |
| `mouse_pick_loader_avm1` | output_mismatch | 5/42 | 16/42 | -11 |
| `displayobject_getrect` | output_mismatch | 2/16 | 11/16 | -9 |
| `number_tostring` | output_mismatch | 873/1050 | 882/1050 | -9 |
| `matrix3d_copy_from` | output_mismatch | 12/19 | 15/19 | -3 |
| `matrix3d_copy_to_matrix3d` | output_mismatch | 12/19 | 15/19 | -3 |
| `stage_display_state` | output_mismatch | 0/6 | 0/6 | 0 |
