# Ruffle Test Results Diff

**Previous:** `12e36a9c0d74` (2026-02-15T17:34:40.811420+00:00)
**Current:** `c5804d051f3f` (2026-02-15T18:52:08.904048+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 181 | 195 | +14 |
| Total | 619 | 619 | 0 |
| Pass rate | 29.2% | 31.5% | +2.3% |
| Mismatched lines | 49395 | 47382 | -2013 |
|   Decreased | | | -2087 |
|   Increased | | | +74 |

## Newly Passing (14)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as_set_prop_flags_version_swf5` | output_mismatch | 0/1 | 1/1 |
| `as_set_prop_flags_version_swf6` | output_mismatch | 0/1 | 1/1 |
| `as_set_prop_flags_version_swf7` | output_mismatch | 0/1 | 1/1 |
| `as_set_prop_flags_version_swf8` | output_mismatch | 0/1 | 1/1 |
| `as_set_prop_flags_version_swf9` | output_mismatch | 0/1 | 1/1 |
| `math_min_max` | output_mismatch | 32/101 | 101/101 |
| `xml_append_child` | output_mismatch | 18/28 | 28/28 |
| `xml_append_child_with_parent` | output_mismatch | 8/20 | 20/20 |
| `xml_clone_expandos` | output_mismatch | 13/19 | 19/19 |
| `xml_first_last_child` | output_mismatch | 7/8 | 8/8 |
| `xml_insert_before` | output_mismatch | 6/20 | 20/20 |
| `xml_parent_and_child` | output_mismatch | 3/5 | 5/5 |
| `xml_remove_node` | output_mismatch | 8/22 | 22/22 |
| `xml_siblings` | output_mismatch | 5/10 | 10/10 |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `bitmap_data_pixeldissolve` | segfault | output_mismatch | 3/1075 | 68/1075 |
| `device_font_spacing` | segfault | output_mismatch | 1/91 | 1/91 |
| `parse_float` | timeout | output_mismatch | - | 43/74 |

## Line Count Changed (31)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `math_swf6` | output_mismatch | 10/530 | 522/530 | -512 |
| `math_swf7` | output_mismatch | 10/530 | 522/530 | -512 |
| `math_swf8` | output_mismatch | 10/530 | 522/530 | -512 |
| `focusrect_property_swf7` | output_mismatch | 69/1237 | 168/1237 | -99 |
| `focusrect_property_swf6` | output_mismatch | 71/1237 | 169/1237 | -98 |
| `focusrect_property_swf5` | output_mismatch | 6/1237 | 44/1237 | -38 |
| `textfield_props_swf7` | output_mismatch | 179/210 | 208/210 | -29 |
| `textfield_props_swf6` | output_mismatch | 181/210 | 208/210 | -27 |
| `textfield_props_swf8` | output_mismatch | 184/210 | 208/210 | -24 |
| `asnew` | output_mismatch | 1/34 | 10/34 | -9 |
| `xml_to_string` | output_mismatch | 3/13 | 11/13 | -8 |
| `as_set_prop_flags_version` | output_mismatch | 19/31 | 21/31 | -2 |
| `xml_child_nodes_edge_cases` | output_mismatch | 1/4 | 3/4 | -2 |
| `focus_remove` | output_mismatch | 1/33 | 2/33 | -1 |
| `globals_swf5` | output_mismatch | 210/304 | 211/304 | -1 |
| `globals_swf6` | output_mismatch | 217/304 | 218/304 | -1 |
| `globals_swf7` | output_mismatch | 214/304 | 215/304 | -1 |
| `globals_swf8` | output_mismatch | 155/304 | 156/304 | -1 |
| `init_object_order` | segfault | 0/15 | 1/15 | -1 |
| `localconnection_properties` | output_mismatch | 3/8 | 4/8 | -1 |
| `string_methods` | output_mismatch | 282/285 | 283/285 | -1 |
| `stylesheet` | output_mismatch | 14/283 | 15/283 | -1 |
| `swf5_global_funcs` | output_mismatch | 0/232 | 1/232 | -1 |
| `swf6_global_funcs` | output_mismatch | 0/232 | 1/232 | -1 |
| `swf7_global_funcs` | output_mismatch | 0/232 | 1/232 | -1 |
| `array_call_method` | output_mismatch | 3/9 | 3/9 | 0 |
| `global_proto_decls` | output_mismatch | 4/4497 | 4/4497 | 0 |
| `global_proto_decls_delete` | output_mismatch | 0/4158 | 0/4158 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `string_paths_basic` | output_mismatch | 3/4 | 2/4 | +1 |
| `textfield_props_swf5` | output_mismatch | 84/175 | 42/175 | +42 |
