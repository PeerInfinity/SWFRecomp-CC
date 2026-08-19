# Graphics vs Trace Mode Differences

Trace: 1179/1251 passing | Graphics: 1155/1243 passing

## Graphics Regressions (23 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `all_classes/events/swf10` | Output Mismatch | 15/1638 lines match |
| 2 | `all_classes/events/swf11` | Output Mismatch | 15/1750 lines match |
| 3 | `all_classes/events/swf12` | Output Mismatch | 15/1814 lines match |
| 4 | `all_classes/events/swf30` | Output Mismatch | 25/2353 lines match |
| 5 | `all_classes/events/swf9` | Output Mismatch | 10/1030 lines match |
| 6 | `appdomain_lookup_edge_cases` | Output Mismatch | 7/32 lines match |
| 7 | `automation_classes` | Output Mismatch | 1/122 lines match |
| 8 | `button_nested_frame_simple` | Output Mismatch | 27/39 lines match |
| 9 | `displayobject_early_init` | Output Mismatch | 1/54 lines match |
| 10 | `displayobject_hittestpoint_boundary` | Output Mismatch | 47/65 lines match |
| 11 | `displayobject_scrollrect` | Output Mismatch | 27/33 lines match |
| 12 | `displayobject_transform` | Output Mismatch | 67/89 lines match |
| 13 | `large_preload_from_url` | Output Mismatch | 16/27 lines match |
| 14 | `large_preload_image_from_bytes` | Output Mismatch | 19/25 lines match |
| 15 | `matrix3d_determinant` | Output Mismatch | 149/182 lines match |
| 16 | `matrix3d_precision` | Output Mismatch | 5/25 lines match |
| 17 | `matrix3d_raw_data` | Output Mismatch | 28/33 lines match |
| 18 | `method_association` | Output Mismatch | 1/5 lines match |
| 19 | `mouse_pick_avm1_root` | Output Mismatch | 1/2 lines match |
| 20 | `native_menu_basic` | Output Mismatch | 0/19 lines match |
| 21 | `scope_optimizations` | Output Mismatch | 3/4 lines match |
| 22 | `supercalls_coerce` | Output Mismatch | 1/8 lines match |
| 23 | `textfield_input_events` | Output Mismatch | 9/25 lines match |

## Graphics Improvements (1 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `getouterscope_two_classobjects` | Ruffle Matched | 9/13 lines match |
