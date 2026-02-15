# Ruffle Test Results Diff

**Previous:** `17b33b97205a` (2026-02-15T04:43:18.847470+00:00)
**Current:** `6395c5894863` (2026-02-15T05:15:32.698615+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 122 | 167 | +45 |
| Total | 619 | 619 | 0 |
| Pass rate | 19.7% | 27.0% | +7.3% |
| Mismatched lines | 58761 | 49503 | -9258 |
|   Decreased | | | -10860 |
|   Increased | | | +1602 |

## Newly Passing (45)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `add2` | output_mismatch | 31/354 | 354/354 |
| `bitmap_data_max_size_swf10` | output_mismatch | 9/12 | 12/12 |
| `bitmap_data_max_size_swf9` | output_mismatch | 7/10 | 10/10 |
| `bitmapdata_applyfilter_colormatrix` | segfault | - | 0/0 |
| `define_function2_preload` | output_mismatch | 12/13 | 13/13 |
| `equals2_swf5` | segfault | 32/926 | 926/926 |
| `equals2_swf6` | segfault | 32/926 | 926/926 |
| `equals2_swf7` | segfault | 32/926 | 926/926 |
| `goto_frame_number` | output_mismatch | 2/3 | 3/3 |
| `greater_swf6` | segfault | 32/1175 | 1175/1175 |
| `greater_swf7` | segfault | 32/1175 | 1175/1175 |
| `infinite_recursion_function_in_setter` | output_mismatch | 0/131 | 131/131 |
| `infinite_recursion_virtual_property` | output_mismatch | 0/67 | 67/67 |
| `issue_1671` | segfault | - | 0/0 |
| `lessthan2_swf5` | segfault | 32/1226 | 1226/1226 |
| `lessthan2_swf6` | segfault | 32/1226 | 1226/1226 |
| `lessthan2_swf7` | segfault | 32/1226 | 1226/1226 |
| `mouse_wheel_enabled` | output_mismatch | 0/2 | 2/2 |
| `object_function` | output_mismatch | 28/32 | 32/32 |
| `object_string_coerce_swf5` | output_mismatch | 58/62 | 62/62 |
| `prototype_delete` | output_mismatch | 4/12 | 12/12 |
| `strictequals_swf6` | segfault | 32/902 | 902/902 |
| `string_paths_keyevents` | segfault | - | 0/0 |
| `string_paths_timer` | segfault | - | 0/0 |
| `text_format` | output_mismatch | 1134/1146 | 1146/1146 |
| `text_format_font_max_length` | output_mismatch | 0/2 | 2/2 |
| `text_format_rounding_swf7` | output_mismatch | 810/840 | 840/840 |
| `text_format_rounding_swf8` | output_mismatch | 792/840 | 840/840 |
| `textfield_maxchars` | output_mismatch | 1/3 | 3/3 |
| `this_swf7` | output_mismatch | 40/41 | 41/41 |
| `xml` | output_mismatch | 11/15 | 15/15 |
| `xml_attributes_read` | output_mismatch | 1/4 | 4/4 |
| `xml_cdata` | output_mismatch | 7/11 | 11/11 |
| `xml_has_child_nodes` | output_mismatch | 2/3 | 3/3 |
| `xml_idmap` | output_mismatch | 1/21 | 21/21 |
| `xml_ignore_comments` | output_mismatch | 0/21 | 21/21 |
| `xml_ignore_white` | output_mismatch | 20/34 | 34/34 |
| `xml_inspect_createmethods` | output_mismatch | 13/15 | 15/15 |
| `xml_inspect_doctype` | output_mismatch | 4/7 | 7/7 |
| `xml_inspect_parsexml` | output_mismatch | 21/62 | 62/62 |
| `xml_inspect_xmldecl` | output_mismatch | 4/7 | 7/7 |
| `xml_namespaces` | output_mismatch | 29/203 | 203/203 |
| `xml_reparenting` | output_mismatch | 6/14 | 14/14 |
| `xml_to_string_comment` | output_mismatch | 0/1 | 1/1 |
| `xml_unescaping` | output_mismatch | 11/23 | 23/23 |

## Status Changed (57)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `bitmap_data_copypixels` | segfault | output_mismatch | 3/17 | 3/17 |
| `button_keypress_vs_tab` | segfault | output_mismatch | - | 0/20 |
| `create_empty_movie_clip` | segfault | output_mismatch | - | 2/3 |
| `duplicate_movie_clip_drawing` | segfault | output_mismatch | - | 0/2 |
| `edittext_autosize` | segfault | output_mismatch | 1/71 | 44/71 |
| `edittext_width_height` | segfault | output_mismatch | 1/103 | 97/103 |
| `empty_movieclip_can_attach_movies` | segfault | output_mismatch | - | 8/11 |
| `focus_mouse_focusable` | segfault | output_mismatch | - | 0/8 |
| `focus_visibility_change` | segfault | output_mismatch | - | 3/45 |
| `global_swf5_6_7_8_9` | segfault | output_mismatch | - | 0/1145 |
| `global_swf6_7_8` | segfault | output_mismatch | - | 0/15 |
| `interface_implements_op` | segfault | output_mismatch | - | 0/47 |
| `issue_2030` | segfault | output_mismatch | - | 2/4 |
| `loading_avm2` | segfault | output_mismatch | - | 1/7 |
| `loadmovie` | segfault | output_mismatch | 1/2 | 1/2 |
| `loadmovie_flashvars` | segfault | output_mismatch | 1/4 | 1/4 |
| `loadmovie_method` | segfault | output_mismatch | 1/2 | 1/2 |
| `loadmovie_registerclass` | segfault | output_mismatch | - | 0/30 |
| `loadmovie_var_persistence` | segfault | output_mismatch | - | 1/8 |
| `lock_root` | segfault | output_mismatch | - | 0/1 |
| `mcl_as_broadcaster` | segfault | output_mismatch | - | 0/12 |
| `mcl_getprogress` | segfault | output_mismatch | - | 0/30 |
| `mcl_mislabeled_target` | segfault | output_mismatch | - | 0/6 |
| `mcl_target_gif87a` | segfault | output_mismatch | - | 0/6 |
| `mcl_target_gif89a` | segfault | output_mismatch | - | 0/6 |
| `mcl_target_jpg` | segfault | output_mismatch | - | 0/6 |
| `mcl_target_png` | segfault | output_mismatch | - | 0/6 |
| `mcl_unloadclip` | segfault | output_mismatch | - | 0/5 |
| `movieclip_default_state` | segfault | output_mismatch | - | 64/69 |
| `movieclip_gettextsnapshot` | segfault | output_mismatch | 4/112 | 4/112 |
| `movieclip_invalid_get_bounds_3` | segfault | output_mismatch | 1/13 | 1/13 |
| `movieclip_invalid_get_bounds_4` | segfault | output_mismatch | 1/13 | 1/13 |
| `movieclip_invalid_get_bounds_5` | segfault | output_mismatch | 1/11 | 1/11 |
| `movieclip_invalid_get_bounds_6` | segfault | output_mismatch | 1/10 | 1/10 |
| `movieclip_invalid_get_bounds_7` | segfault | output_mismatch | 1/10 | 1/10 |
| `movieclip_invalid_get_bounds_8` | segfault | output_mismatch | 1/11 | 1/11 |
| `movieclip_setmask` | segfault | output_mismatch | - | 2/14 |
| `movieclip_state_values` | segfault | output_mismatch | 1/114 | 1/114 |
| `moviecliploader_flashvars` | segfault | output_mismatch | 1/4 | 1/4 |
| `object_constructor` | segfault | output_mismatch | 8/33 | 32/33 |
| `parse_float` | output_mismatch | timeout | 40/74 | - |
| `property_invalid_base_clip` | segfault | output_mismatch | - | 11/36 |
| `register_class_swf6` | segfault | output_mismatch | - | 0/37 |
| `rewind_depth` | segfault | output_mismatch | 2/30 | 9/30 |
| `sandbox_type_remote` | segfault | output_mismatch | 0/3 | 0/3 |
| `string_paths_basic` | segfault | output_mismatch | - | 3/4 |
| `string_paths_eval2` | segfault | output_mismatch | - | 1/7 |
| `string_paths_other` | segfault | output_mismatch | 0/36 | 11/36 |
| `string_paths_unload` | segfault | output_mismatch | - | 0/1 |
| `string_paths_variable_alias` | segfault | output_mismatch | - | 2/4 |
| `tab_ordering_tabbable` | segfault | output_mismatch | - | 0/47 |
| `textfield_cache_as_bitmap` | segfault | output_mismatch | - | 0/1 |
| `this_scoping` | segfault | output_mismatch | - | 2/52 |
| `try_catch_finally` | segfault | timeout | 49/118 | - |
| `unload` | segfault | output_mismatch | 1/52 | 8/52 |
| `unloadmovie` | segfault | output_mismatch | 1/4 | 2/4 |
| `unloadmovie_method` | segfault | output_mismatch | 1/3 | 1/3 |

## Line Count Changed (40)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_default_format` | output_mismatch | 146/221 | 209/221 | -63 |
| `string_coercion` | output_mismatch | 94/117 | 116/117 | -22 |
| `movieclip_focusenabled` | output_mismatch | 53/99 | 71/99 | -18 |
| `mcl_loadclip` | output_mismatch | 8/149 | 25/149 | -17 |
| `movieclip_getbounds` | output_mismatch | 33/191 | 45/191 | -12 |
| `coerce_to_primitive_resolve` | output_mismatch | 1/17 | 7/17 | -6 |
| `hittest_lockroot` | output_mismatch | 1/15 | 6/15 | -5 |
| `text_format_display` | output_mismatch | 5/21 | 10/21 | -5 |
| `frame_size_translated_negative` | output_mismatch | 10/21 | 14/21 | -4 |
| `frame_size_translated_positive` | output_mismatch | 10/21 | 14/21 | -4 |
| `object_string_coerce_swf6` | output_mismatch | 42/68 | 46/68 | -4 |
| `as2_oop` | output_mismatch | 7/13 | 10/13 | -3 |
| `named_shapes` | output_mismatch | 6/14 | 9/14 | -3 |
| `xml_to_string` | output_mismatch | 0/13 | 3/13 | -3 |
| `edittext_hscroll` | output_mismatch | 15/27 | 17/27 | -2 |
| `remove_movie_clip` | output_mismatch | 17/29 | 19/29 | -2 |
| `textfield_props_swf6` | output_mismatch | 179/210 | 181/210 | -2 |
| `textfield_props_swf7` | output_mismatch | 177/210 | 179/210 | -2 |
| `textfield_props_swf8` | output_mismatch | 182/210 | 184/210 | -2 |
| `watch_virtual_property` | output_mismatch | 6/60 | 8/60 | -2 |
| `xml_first_last_child` | output_mismatch | 5/8 | 7/8 | -2 |
| `as_set_prop_flags_version` | output_mismatch | 18/31 | 19/31 | -1 |
| `bitmap_data` | output_mismatch | 67/1126 | 68/1126 | -1 |
| `clone_sprite_types` | output_mismatch | 12/24 | 13/24 | -1 |
| `edittext_html_entity` | output_mismatch | 2/4 | 3/4 | -1 |
| `error` | output_mismatch | 49/58 | 50/58 | -1 |
| `object_prototypes` | output_mismatch | 61/74 | 62/74 | -1 |
| `textfield_properties` | output_mismatch | 42/44 | 43/44 | -1 |
| `this_swf5` | output_mismatch | 18/41 | 19/41 | -1 |
| `this_swf6` | output_mismatch | 17/41 | 18/41 | -1 |
| `xml_child_nodes_edge_cases` | output_mismatch | 0/4 | 1/4 | -1 |
| `xml_clone_expandos` | output_mismatch | 12/19 | 13/19 | -1 |
| `xml_parent_and_child` | output_mismatch | 2/5 | 3/5 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `issue_9327` | output_mismatch | 0/2 | 0/2 | 0 |
| `array_sort` | output_mismatch | 117/161 | 116/161 | +1 |
| `transform` | output_mismatch | 50/70 | 49/70 | +1 |
| `duplicate_movie_clip` | output_mismatch | 6/20 | 4/20 | +2 |
| `xml_insert_before` | output_mismatch | 8/20 | 6/20 | +2 |
| `path_string` | output_mismatch | 48/322 | 45/322 | +3 |
