# Ruffle Test Results Diff

**Previous:** `c5804d051f3f` (2026-02-15T18:52:08.904048+00:00)
**Current:** `304806557359` (2026-02-15T19:40:13.803859+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 195 | 187 | -8 |
| Total | 619 | 619 | 0 |
| Pass rate | 31.5% | 30.2% | -1.3% |
| Mismatched lines | 47382 | 44846 | -2536 |
|   Decreased | | | -2563 |
|   Increased | | | +27 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `globals_swf6` | output_mismatch | 218/304 | 304/304 |
| `globals_swf7` | output_mismatch | 215/304 | 304/304 |
| `globals_swf8` | output_mismatch | 156/304 | 304/304 |
| `is_finite` | output_mismatch | 24/49 | 49/49 |
| `is_finite_swf6` | output_mismatch | 24/49 | 49/49 |

## Newly Failing (13)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `bitmap_data_perlinnoise` | segfault | 0/0 | - |
| `bitmap_data_pixeldissolve_image` | segfault | 0/0 | - |
| `define_function2_preload` | output_mismatch | 13/13 | 10/13 |
| `define_function2_preload_order` | output_mismatch | 4/4 | 2/4 |
| `issue_768` | output_mismatch | 3/3 | 2/3 |
| `movieclip_blend_mode_property` | segfault | 35/35 | - |
| `object_function` | output_mismatch | 32/32 | 29/32 |
| `object_string_coerce_swf5` | output_mismatch | 62/62 | 56/62 |
| `string_coercion` | output_mismatch | 117/117 | 111/117 |
| `string_methods_negative_args` | segfault | 240/240 | - |
| `xml_reparenting` | segfault | 14/14 | - |
| `xml_unescaping` | segfault | 23/23 | - |
| `xmlnode_proto` | segfault | 1/1 | - |

## Status Changed (37)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `array_sort_random` | output_mismatch | segfault | 0/443 | - |
| `asnew` | output_mismatch | segfault | 10/34 | - |
| `bitmap_data_copypixels` | output_mismatch | segfault | 3/17 | - |
| `bitmap_data_pixeldissolve` | output_mismatch | segfault | 68/1075 | - |
| `boxed_primitives` | output_mismatch | segfault | 14/24 | - |
| `coerce_to_primitive_resolve` | output_mismatch | segfault | 7/17 | - |
| `drag_over_from_outside` | output_mismatch | segfault | 0/1 | - |
| `drag_over_without_startdrag` | output_mismatch | segfault | 0/1 | - |
| `file_reference_browse_cancel` | output_mismatch | segfault | 0/21 | - |
| `function_base_clip_removed` | output_mismatch | segfault | 1/25 | 1/25 |
| `function_suppress_and_preload` | output_mismatch | segfault | 24/28 | - |
| `global_swf6_7_8` | output_mismatch | segfault | 0/15 | - |
| `hittest_lockroot` | output_mismatch | segfault | 6/15 | - |
| `hittest_winding_rule` | output_mismatch | segfault | 6/12 | - |
| `instanceof_coercions` | output_mismatch | segfault | 7/88 | - |
| `interface_implements_op` | output_mismatch | segfault | 0/47 | - |
| `issue_3169` | output_mismatch | segfault | 0/2 | - |
| `issue_9327` | output_mismatch | segfault | 0/2 | - |
| `loadmovie_fail` | output_mismatch | segfault | 1/2 | - |
| `loadmovienum_cross_version_prototype` | output_mismatch | segfault | 1/9 | - |
| `math_swf6` | output_mismatch | segfault | 522/530 | - |
| `math_swf7` | output_mismatch | segfault | 522/530 | - |
| `math_swf8` | output_mismatch | segfault | 522/530 | - |
| `mcl_loadclip_properties` | output_mismatch | segfault | 0/6 | - |
| `mcl_loadclip_replace_root` | output_mismatch | segfault | 0/1 | - |
| `mouse_hover_events_while_dragging` | output_mismatch | segfault | 0/1 | - |
| `native_double_construct` | output_mismatch | segfault | 5/12 | - |
| `native_subclasses` | output_mismatch | segfault | 9/191 | - |
| `object_resolve` | output_mismatch | segfault | 0/38 | - |
| `register_class_return_value` | output_mismatch | segfault | 6/16 | - |
| `register_class_with_sound` | output_mismatch | segfault | 1/11 | - |
| `super_edge_cases` | output_mismatch | segfault | 7/39 | - |
| `watch_virtual_property_proto` | output_mismatch | segfault | 0/2 | - |
| `xml_socket` | output_mismatch | segfault | 1/8 | - |
| `xml_socket_close_in_handler` | output_mismatch | segfault | 0/6 | - |
| `xml_socket_on_data` | output_mismatch | segfault | 0/7 | - |
| `xml_socket_segmented` | output_mismatch | segfault | 0/29 | - |

## Line Count Changed (22)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `globals_swf5` | output_mismatch | 211/304 | 290/304 | -79 |
| `sound_props_swf5` | output_mismatch | 36/68 | 46/68 | -10 |
| `global_proto_decls` | output_mismatch | 4/4497 | 9/4497 | -5 |
| `printjob_props_swf5` | output_mismatch | 0/45 | 5/45 | -5 |
| `printjob_props_swf7` | output_mismatch | 2/45 | 7/45 | -5 |
| `textsnapshot_props_swf5` | output_mismatch | 8/56 | 13/56 | -5 |
| `textsnapshot_props_swf6` | output_mismatch | 2/56 | 7/56 | -5 |
| `as_broadcaster` | output_mismatch | 6/41 | 8/41 | -2 |
| `printjob_props_swf6` | output_mismatch | 3/45 | 5/45 | -2 |
| `focusrect_property_swf7` | output_mismatch | 168/1237 | 169/1237 | -1 |
| `sound_props_swf6` | output_mismatch | 31/68 | 32/68 | -1 |
| `stage_scale_mode` | output_mismatch | 17/39 | 18/39 | -1 |
| `transform` | output_mismatch | 50/70 | 51/70 | -1 |
| `color_transform` | output_mismatch | 7/48 | 7/48 | 0 |
| `context_menu` | output_mismatch | 2/39 | 2/39 | 0 |
| `context_menu_item` | output_mismatch | 2/41 | 2/41 | 0 |
| `global_proto_decls_delete` | output_mismatch | 0/4158 | 0/4158 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `native_objects_swf8` | output_mismatch | 0/84 | 0/84 | 0 |
| `focusrect_property_swf5` | output_mismatch | 44/1237 | 43/1237 | +1 |
| `focusrect_property_swf6` | output_mismatch | 169/1237 | 168/1237 | +1 |
| `object_string_coerce_swf6` | output_mismatch | 46/68 | 42/68 | +4 |
