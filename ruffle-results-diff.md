# Ruffle Test Results Diff

**Previous:** `304806557359` (2026-02-15T19:40:13.803859+00:00)
**Current:** `742bdce60155` (2026-02-15T20:33:25.139535+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 187 | 196 | +9 |
| Total | 619 | 619 | 0 |
| Pass rate | 30.2% | 31.7% | +1.5% |
| Mismatched lines | 44846 | 46948 | +2102 |
|   Decreased | | | -27 |
|   Increased | | | +2129 |

## Newly Passing (13)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bitmap_data_perlinnoise` | segfault | - | 0/0 |
| `bitmap_data_pixeldissolve_image` | segfault | - | 0/0 |
| `define_function2_preload` | output_mismatch | 10/13 | 13/13 |
| `define_function2_preload_order` | output_mismatch | 2/4 | 4/4 |
| `issue_768` | output_mismatch | 2/3 | 3/3 |
| `movieclip_blend_mode_property` | segfault | - | 35/35 |
| `object_function` | output_mismatch | 29/32 | 32/32 |
| `object_string_coerce_swf5` | output_mismatch | 56/62 | 62/62 |
| `string_coercion` | output_mismatch | 111/117 | 117/117 |
| `string_methods_negative_args` | segfault | - | 240/240 |
| `xml_reparenting` | segfault | - | 14/14 |
| `xml_unescaping` | segfault | - | 23/23 |
| `xmlnode_proto` | segfault | - | 1/1 |

## Newly Failing (4)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `array_constructor` | output_mismatch | 30/30 | 29/30 |
| `globals_swf6` | output_mismatch | 304/304 | 293/304 |
| `globals_swf7` | output_mismatch | 304/304 | 293/304 |
| `globals_swf8` | output_mismatch | 304/304 | 286/304 |

## Status Changed (36)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `array_sort_random` | segfault | output_mismatch | - | 0/443 |
| `asnew` | segfault | output_mismatch | - | 10/34 |
| `bitmap_data_copypixels` | segfault | output_mismatch | - | 3/17 |
| `bitmap_data_pixeldissolve` | segfault | output_mismatch | - | 68/1075 |
| `boxed_primitives` | segfault | output_mismatch | - | 14/24 |
| `coerce_to_primitive_resolve` | segfault | output_mismatch | - | 7/17 |
| `drag_over_from_outside` | segfault | output_mismatch | - | 0/1 |
| `drag_over_without_startdrag` | segfault | output_mismatch | - | 0/1 |
| `file_reference_browse_cancel` | segfault | output_mismatch | - | 0/21 |
| `function_suppress_and_preload` | segfault | output_mismatch | - | 24/28 |
| `global_swf6_7_8` | segfault | output_mismatch | - | 0/15 |
| `hittest_lockroot` | segfault | output_mismatch | - | 6/15 |
| `hittest_winding_rule` | segfault | output_mismatch | - | 6/12 |
| `instanceof_coercions` | segfault | output_mismatch | - | 7/88 |
| `interface_implements_op` | segfault | output_mismatch | - | 0/47 |
| `issue_3169` | segfault | output_mismatch | - | 0/2 |
| `issue_9327` | segfault | output_mismatch | - | 0/2 |
| `loadmovie_fail` | segfault | output_mismatch | - | 1/2 |
| `loadmovienum_cross_version_prototype` | segfault | output_mismatch | - | 1/9 |
| `math_swf6` | segfault | output_mismatch | - | 522/530 |
| `math_swf7` | segfault | output_mismatch | - | 522/530 |
| `math_swf8` | segfault | output_mismatch | - | 522/530 |
| `mcl_loadclip_properties` | segfault | output_mismatch | - | 0/6 |
| `mcl_loadclip_replace_root` | segfault | output_mismatch | - | 0/1 |
| `mouse_hover_events_while_dragging` | segfault | output_mismatch | - | 0/1 |
| `native_double_construct` | segfault | output_mismatch | - | 5/12 |
| `native_subclasses` | segfault | output_mismatch | - | 9/191 |
| `object_resolve` | segfault | output_mismatch | - | 0/38 |
| `register_class_return_value` | segfault | output_mismatch | - | 6/16 |
| `register_class_with_sound` | segfault | output_mismatch | - | 1/11 |
| `super_edge_cases` | segfault | output_mismatch | - | 7/39 |
| `watch_virtual_property_proto` | segfault | output_mismatch | - | 0/2 |
| `xml_socket` | segfault | output_mismatch | - | 1/8 |
| `xml_socket_close_in_handler` | segfault | output_mismatch | - | 0/6 |
| `xml_socket_on_data` | segfault | output_mismatch | - | 0/7 |
| `xml_socket_segmented` | segfault | output_mismatch | - | 0/29 |

## Line Count Changed (13)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `object_string_coerce_swf6` | output_mismatch | 42/68 | 46/68 | -4 |
| `printjob_props_swf5` | output_mismatch | 5/45 | 6/45 | -1 |
| `printjob_props_swf6` | output_mismatch | 5/45 | 6/45 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `external_interface_toxml_basic` | output_mismatch | 35/179 | 34/179 | +1 |
| `printjob_props_swf7` | output_mismatch | 7/45 | 6/45 | +1 |
| `sound_props_swf5` | output_mismatch | 46/68 | 45/68 | +1 |
| `sound_props_swf6` | output_mismatch | 32/68 | 31/68 | +1 |
| `textsnapshot_props_swf5` | output_mismatch | 13/56 | 12/56 | +1 |
| `textsnapshot_props_swf6` | output_mismatch | 7/56 | 6/56 | +1 |
| `transform` | output_mismatch | 51/70 | 50/70 | +1 |
| `array_sort` | output_mismatch | 116/161 | 114/161 | +2 |
| `globals_swf5` | output_mismatch | 290/304 | 279/304 | +11 |
