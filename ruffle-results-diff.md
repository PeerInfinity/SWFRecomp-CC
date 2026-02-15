# Ruffle Test Results Diff

**Previous:** `51c59eed98f8` (2026-02-15T23:08:23.733607+00:00)
**Current:** `6c9b9420a890` (2026-02-15T23:34:36.628968+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 206 | 203 | -3 |
| Total | 619 | 619 | 0 |
| Pass rate | 33.3% | 32.8% | -0.5% |
| Mismatched lines | 45686 | 45881 | +195 |
|   Decreased | | | -74 |
|   Increased | | | +269 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `array_enumerate` | output_mismatch | 0/4 | 4/4 |
| `new_object_enumerate` | output_mismatch | 4/7 | 7/7 |
| `prototype_enumerate` | output_mismatch | 1/5 | 5/5 |
| `stage_object_enumerate` | output_mismatch | 1/4 | 4/4 |
| `swf7_case_sensitive` | output_mismatch | 40/44 | 44/44 |

## Newly Failing (8)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `array_length` | output_mismatch | 42/42 | 39/42 |
| `conflicting_instance_names` | output_mismatch | 23/23 | 22/23 |
| `define_function2_preload_order` | output_mismatch | 4/4 | 0/4 |
| `execution_order1` | output_mismatch | 5/5 | 3/5 |
| `execution_order2` | output_mismatch | 7/7 | 4/7 |
| `textfield_variable` | output_mismatch | 81/81 | 70/81 |
| `variable_args` | output_mismatch | 5/5 | 0/5 |
| `xml_attributes_read` | output_mismatch | 4/4 | 2/4 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `enumerate` | segfault | output_mismatch | 3/64 | 17/64 |

## Line Count Changed (35)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `register_and_init_order` | segfault | 27/231 | 44/231 | -17 |
| `init_object_order` | segfault | 1/15 | 5/15 | -4 |
| `sound_props_swf5` | output_mismatch | 45/68 | 49/68 | -4 |
| `sound_props_swf6` | output_mismatch | 31/68 | 35/68 | -4 |
| `with` | output_mismatch | 34/49 | 37/49 | -3 |
| `array_sort` | output_mismatch | 117/161 | 119/161 | -2 |
| `bitmap_data_hittest` | output_mismatch | 60/132 | 62/132 | -2 |
| `prototype_properties` | output_mismatch | 12/17 | 14/17 | -2 |
| `define_local` | output_mismatch | 2/27 | 3/27 | -1 |
| `execution_order4` | output_mismatch | 2/12 | 3/12 | -1 |
| `super_edge_cases` | output_mismatch | 7/39 | 8/39 | -1 |
| `textsnapshot_props_swf5` | output_mismatch | 12/56 | 13/56 | -1 |
| `color_transform` | output_mismatch | 7/48 | 7/48 | 0 |
| `context_menu` | output_mismatch | 2/39 | 2/39 | 0 |
| `context_menu_item` | output_mismatch | 2/41 | 2/41 | 0 |
| `global_proto_decls_delete` | output_mismatch | 0/4158 | 0/4158 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `placeobject_occupied_depth` | output_mismatch | 0/6 | 0/6 | 0 |
| `printjob_props_swf5` | output_mismatch | 6/45 | 6/45 | 0 |
| `printjob_props_swf6` | output_mismatch | 6/45 | 6/45 | 0 |
| `printjob_props_swf7` | output_mismatch | 6/45 | 6/45 | 0 |
| `tell_target_invalid` | output_mismatch | 0/6 | 0/6 | 0 |
| `tell_target_invalid_swf6` | output_mismatch | 0/5 | 0/5 | 0 |
| `textsnapshot_props_swf6` | output_mismatch | 6/56 | 6/56 | 0 |
| `global_instance_decls` | output_mismatch | 2/758 | 1/758 | +1 |
| `swf6_case_insensitive` | output_mismatch | 29/42 | 28/42 | +1 |
| `textfield_props_swf5` | output_mismatch | 42/175 | 41/175 | +1 |
| `target_clip_removed` | output_mismatch | 4/5 | 0/5 | +4 |
| `default_names` | output_mismatch | 12/52 | 5/52 | +7 |
| `global_proto_decls` | output_mismatch | 9/4497 | 1/4497 | +8 |
| `stage_object_properties` | output_mismatch | 173/241 | 164/241 | +9 |
| `stage_object_properties_swf6` | output_mismatch | 166/231 | 157/231 | +9 |
| `textfield_props_swf6` | output_mismatch | 208/210 | 142/210 | +66 |
| `textfield_props_swf7` | output_mismatch | 208/210 | 142/210 | +66 |
| `textfield_props_swf8` | output_mismatch | 208/210 | 142/210 | +66 |
