# Ruffle Test Results Diff

**Previous:** `3fb6a61297cd` (2026-02-15T03:10:50.478275+00:00)
**Current:** `17b33b97205a` (2026-02-15T04:43:18.847470+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 198 | 122 | -76 |
| Total | 619 | 619 | 0 |
| Pass rate | 32.0% | 19.7% | -12.3% |
| Mismatched lines | 46652 | 58761 | +12109 |
|   Decreased | | | -1653 |
|   Increased | | | +13762 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `string_methods_swfv5` | output_mismatch | 274/275 | 275/275 |

## Newly Failing (77)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `add2` | output_mismatch | 354/354 | 31/354 |
| `as_set_prop_flags_version_swf5` | output_mismatch | 1/1 | 0/1 |
| `as_set_prop_flags_version_swf6` | output_mismatch | 1/1 | 0/1 |
| `as_set_prop_flags_version_swf7` | output_mismatch | 1/1 | 0/1 |
| `as_set_prop_flags_version_swf8` | output_mismatch | 1/1 | 0/1 |
| `as_set_prop_flags_version_swf9` | output_mismatch | 1/1 | 0/1 |
| `bitmap_data_max_size_swf10` | output_mismatch | 12/12 | 9/12 |
| `bitmap_data_max_size_swf9` | output_mismatch | 10/10 | 7/10 |
| `bitmapdata_applyfilter_colormatrix` | segfault | 0/0 | - |
| `define_function2_preload` | output_mismatch | 13/13 | 12/13 |
| `divide_swf4` | output_mismatch | 107/107 | 95/107 |
| `edittext_antialiastype` | output_mismatch | 296/296 | 291/296 |
| `edittext_default_format` | output_mismatch | 221/221 | 146/221 |
| `edittext_default_format_empty` | output_mismatch | 95/95 | 91/95 |
| `edittext_default_format_font_style` | output_mismatch | 335/335 | 303/335 |
| `edittext_password` | output_mismatch | 5/5 | 4/5 |
| `equals2_swf5` | segfault | 926/926 | 32/926 |
| `equals2_swf6` | segfault | 926/926 | 32/926 |
| `equals2_swf7` | segfault | 926/926 | 32/926 |
| `error` | output_mismatch | 58/58 | 49/58 |
| `get_variable_in_scope` | output_mismatch | 29/29 | 27/29 |
| `goto_frame_number` | output_mismatch | 3/3 | 2/3 |
| `greater_swf6` | segfault | 1175/1175 | 32/1175 |
| `greater_swf7` | segfault | 1175/1175 | 32/1175 |
| `infinite_recursion_function_in_setter` | output_mismatch | 131/131 | 0/131 |
| `infinite_recursion_virtual_property` | output_mismatch | 67/67 | 0/67 |
| `issue_1671` | segfault | 0/0 | - |
| `lessthan2_swf5` | segfault | 1226/1226 | 32/1226 |
| `lessthan2_swf6` | segfault | 1226/1226 | 32/1226 |
| `lessthan2_swf7` | segfault | 1226/1226 | 32/1226 |
| `mouse_wheel_enabled` | output_mismatch | 2/2 | 0/2 |
| `movieclip_default_state` | segfault | 69/69 | - |
| `object_constructor` | segfault | 33/33 | 8/33 |
| `object_function` | output_mismatch | 32/32 | 28/32 |
| `object_string_coerce_swf5` | output_mismatch | 62/62 | 58/62 |
| `prototype_delete` | output_mismatch | 12/12 | 4/12 |
| `sandbox_type_local_file` | output_mismatch | 1/1 | 0/1 |
| `strictequals_swf6` | segfault | 902/902 | 32/902 |
| `string_coercion` | output_mismatch | 117/117 | 94/117 |
| `string_paths_keyevents` | segfault | 0/0 | - |
| `string_paths_timer` | segfault | 0/0 | - |
| `swf4_function_calls` | output_mismatch | 7/7 | 6/7 |
| `text_format` | output_mismatch | 1146/1146 | 1134/1146 |
| `text_format_display` | output_mismatch | 21/21 | 5/21 |
| `text_format_font_max_length` | output_mismatch | 2/2 | 0/2 |
| `text_format_rounding_swf7` | output_mismatch | 840/840 | 810/840 |
| `text_format_rounding_swf8` | output_mismatch | 840/840 | 792/840 |
| `textfield_maxchars` | output_mismatch | 3/3 | 1/3 |
| `textfield_properties` | output_mismatch | 44/44 | 42/44 |
| `textfield_props_swf6` | output_mismatch | 210/210 | 179/210 |
| `textfield_props_swf7` | output_mismatch | 210/210 | 177/210 |
| `textfield_props_swf8` | output_mismatch | 210/210 | 182/210 |
| `textfield_text` | output_mismatch | 7/7 | 6/7 |
| `textfield_variable` | output_mismatch | 81/81 | 64/81 |
| `this_swf7` | output_mismatch | 41/41 | 40/41 |
| `xml` | output_mismatch | 15/15 | 11/15 |
| `xml_append_child` | output_mismatch | 28/28 | 18/28 |
| `xml_append_child_with_parent` | output_mismatch | 20/20 | 8/20 |
| `xml_attributes_read` | output_mismatch | 4/4 | 1/4 |
| `xml_cdata` | output_mismatch | 11/11 | 7/11 |
| `xml_clone_expandos` | output_mismatch | 19/19 | 12/19 |
| `xml_first_last_child` | output_mismatch | 8/8 | 5/8 |
| `xml_has_child_nodes` | output_mismatch | 3/3 | 2/3 |
| `xml_idmap` | output_mismatch | 21/21 | 1/21 |
| `xml_ignore_white` | output_mismatch | 34/34 | 20/34 |
| `xml_insert_before` | output_mismatch | 20/20 | 8/20 |
| `xml_inspect_createmethods` | output_mismatch | 15/15 | 13/15 |
| `xml_inspect_doctype` | output_mismatch | 7/7 | 4/7 |
| `xml_inspect_parsexml` | output_mismatch | 62/62 | 21/62 |
| `xml_inspect_xmldecl` | output_mismatch | 7/7 | 4/7 |
| `xml_namespaces` | output_mismatch | 203/203 | 29/203 |
| `xml_parent_and_child` | output_mismatch | 5/5 | 2/5 |
| `xml_remove_node` | output_mismatch | 22/22 | 8/22 |
| `xml_reparenting` | output_mismatch | 14/14 | 6/14 |
| `xml_siblings` | output_mismatch | 10/10 | 5/10 |
| `xml_to_string_comment` | output_mismatch | 1/1 | 0/1 |
| `xml_unescaping` | output_mismatch | 23/23 | 11/23 |

## Status Changed (58)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `bitmap_data_copypixels` | output_mismatch | segfault | 3/17 | 3/17 |
| `bitmap_data_pixeldissolve` | timeout | segfault | - | 3/1075 |
| `button_keypress_vs_tab` | output_mismatch | segfault | 0/20 | - |
| `create_empty_movie_clip` | output_mismatch | segfault | 2/3 | - |
| `edittext_autosize` | output_mismatch | segfault | 44/71 | 1/71 |
| `edittext_width_height` | output_mismatch | segfault | 97/103 | 1/103 |
| `empty_movieclip_can_attach_movies` | output_mismatch | segfault | 8/11 | - |
| `enumerate` | output_mismatch | segfault | 17/64 | 3/64 |
| `focus_mouse_focusable` | output_mismatch | segfault | 0/8 | - |
| `focus_visibility_change` | output_mismatch | segfault | 3/45 | - |
| `global_swf5_6_7_8_9` | output_mismatch | segfault | 0/1145 | - |
| `global_swf6_7_8` | output_mismatch | segfault | 0/15 | - |
| `interface_implements_op` | output_mismatch | segfault | 0/47 | - |
| `issue_2030` | output_mismatch | segfault | 2/4 | - |
| `loading_avm2` | output_mismatch | segfault | 1/7 | - |
| `loadmovie` | output_mismatch | segfault | 1/2 | 1/2 |
| `loadmovie_flashvars` | output_mismatch | segfault | 1/4 | 1/4 |
| `loadmovie_method` | output_mismatch | segfault | 1/2 | 1/2 |
| `loadmovie_registerclass` | output_mismatch | segfault | 0/30 | - |
| `loadmovie_var_persistence` | output_mismatch | segfault | 1/8 | - |
| `lock_root` | output_mismatch | segfault | 0/1 | - |
| `mcl_as_broadcaster` | output_mismatch | segfault | 0/12 | - |
| `mcl_getprogress` | output_mismatch | segfault | 0/30 | - |
| `mcl_mislabeled_target` | output_mismatch | segfault | 0/6 | - |
| `mcl_target_gif87a` | output_mismatch | segfault | 0/6 | - |
| `mcl_target_gif89a` | output_mismatch | segfault | 0/6 | - |
| `mcl_target_jpg` | output_mismatch | segfault | 0/6 | - |
| `mcl_target_png` | output_mismatch | segfault | 0/6 | - |
| `mcl_unloadclip` | output_mismatch | segfault | 0/5 | - |
| `movieclip_gettextsnapshot` | output_mismatch | segfault | 4/112 | 4/112 |
| `movieclip_invalid_get_bounds_3` | output_mismatch | segfault | 1/13 | 1/13 |
| `movieclip_invalid_get_bounds_4` | output_mismatch | segfault | 1/13 | 1/13 |
| `movieclip_invalid_get_bounds_5` | output_mismatch | segfault | 1/11 | 1/11 |
| `movieclip_invalid_get_bounds_6` | output_mismatch | segfault | 1/10 | 1/10 |
| `movieclip_invalid_get_bounds_7` | output_mismatch | segfault | 1/10 | 1/10 |
| `movieclip_invalid_get_bounds_8` | output_mismatch | segfault | 1/11 | 1/11 |
| `movieclip_setmask` | output_mismatch | segfault | 2/14 | - |
| `movieclip_state_values` | output_mismatch | segfault | 1/114 | 1/114 |
| `moviecliploader_flashvars` | output_mismatch | segfault | 1/4 | 1/4 |
| `parse_float` | timeout | output_mismatch | - | 40/74 |
| `path_string` | segfault | output_mismatch | 44/322 | 48/322 |
| `property_invalid_base_clip` | output_mismatch | segfault | 11/36 | - |
| `register_class_swf6` | output_mismatch | segfault | 0/37 | - |
| `rewind_depth` | output_mismatch | segfault | 9/30 | 2/30 |
| `sandbox_type_remote` | output_mismatch | segfault | 0/3 | 0/3 |
| `string_paths_basic` | output_mismatch | segfault | 2/4 | - |
| `string_paths_eval2` | output_mismatch | segfault | 1/7 | - |
| `string_paths_other` | output_mismatch | segfault | 11/36 | 0/36 |
| `string_paths_unload` | output_mismatch | segfault | 0/1 | - |
| `string_paths_variable_alias` | output_mismatch | segfault | 2/4 | - |
| `swf4_actions_coercion_order` | segfault | output_mismatch | 9/158 | 11/158 |
| `tab_ordering_tabbable` | output_mismatch | segfault | 0/47 | - |
| `textfield_cache_as_bitmap` | output_mismatch | segfault | 0/1 | - |
| `this_scoping` | output_mismatch | segfault | 2/52 | - |
| `try_catch_finally` | timeout | segfault | - | 49/118 |
| `unload` | output_mismatch | segfault | 8/52 | 1/52 |
| `unloadmovie` | output_mismatch | segfault | 2/4 | 1/4 |
| `unloadmovie_method` | output_mismatch | segfault | 1/3 | 1/3 |

## Line Count Changed (45)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `textfield_props_swf5` | output_mismatch | 42/175 | 84/175 | -42 |
| `array_sort` | output_mismatch | 111/161 | 117/161 | -6 |
| `array_call_method` | output_mismatch | 0/9 | 3/9 | -3 |
| `duplicate_movie_clip` | output_mismatch | 4/20 | 6/20 | -2 |
| `duplicate_movie_clip_drawing` | segfault | 0/2 | - | -2 |
| `root_global_parent` | output_mismatch | 1/6 | 3/6 | -2 |
| `string_methods` | output_mismatch | 280/285 | 282/285 | -2 |
| `device_font_spacing` | segfault | 1/91 | 1/91 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `issue_9327` | output_mismatch | 0/2 | 0/2 | 0 |
| `bitmap_data` | output_mismatch | 68/1126 | 67/1126 | +1 |
| `edittext_html_entity` | output_mismatch | 3/4 | 2/4 | +1 |
| `init_object_order` | segfault | 1/15 | 0/15 | +1 |
| `localconnection_properties` | output_mismatch | 4/8 | 3/8 | +1 |
| `object_prototypes` | output_mismatch | 62/74 | 61/74 | +1 |
| `stage_object_children` | output_mismatch | 68/83 | 67/83 | +1 |
| `swf5_global_funcs` | output_mismatch | 1/232 | 0/232 | +1 |
| `swf6_global_funcs` | output_mismatch | 1/232 | 0/232 | +1 |
| `swf7_global_funcs` | output_mismatch | 1/232 | 0/232 | +1 |
| `this_swf5` | output_mismatch | 19/41 | 18/41 | +1 |
| `this_swf6` | output_mismatch | 18/41 | 17/41 | +1 |
| `clone_sprite_edittext_dynamic` | output_mismatch | 2/86 | 0/86 | +2 |
| `clone_sprite_types` | output_mismatch | 14/24 | 12/24 | +2 |
| `edittext_hscroll` | output_mismatch | 17/27 | 15/27 | +2 |
| `edittext_html_align_swf7` | output_mismatch | 42/52 | 40/52 | +2 |
| `remove_movie_clip` | output_mismatch | 19/29 | 17/29 | +2 |
| `watch_virtual_property` | output_mismatch | 8/60 | 6/60 | +2 |
| `as2_oop` | output_mismatch | 10/13 | 7/13 | +3 |
| `as_set_prop_flags_version` | output_mismatch | 21/31 | 18/31 | +3 |
| `named_shapes` | output_mismatch | 9/14 | 6/14 | +3 |
| `xml_child_nodes_edge_cases` | output_mismatch | 3/4 | 0/4 | +3 |
| `frame_size_translated_negative` | output_mismatch | 14/21 | 10/21 | +4 |
| `frame_size_translated_positive` | output_mismatch | 14/21 | 10/21 | +4 |
| `object_string_coerce_swf6` | output_mismatch | 46/68 | 42/68 | +4 |
| `edittext_html_align_swf8` | output_mismatch | 45/52 | 40/52 | +5 |
| `hittest_lockroot` | output_mismatch | 6/15 | 1/15 | +5 |
| `coerce_to_primitive_resolve` | output_mismatch | 7/17 | 1/17 | +6 |
| `xml_to_string` | output_mismatch | 11/13 | 0/13 | +11 |
| `movieclip_getbounds` | output_mismatch | 45/191 | 33/191 | +12 |
| `mcl_loadclip` | output_mismatch | 25/149 | 8/149 | +17 |
| `movieclip_focusenabled` | output_mismatch | 71/99 | 53/99 | +18 |
| `xml_ignore_comments` | output_mismatch | 18/21 | 0/21 | +18 |
| `focusrect_property_swf5` | output_mismatch | 239/1237 | 6/1237 | +233 |
| `focusrect_property_swf6` | output_mismatch | 718/1237 | 71/1237 | +647 |
| `focusrect_property_swf7` | output_mismatch | 717/1237 | 69/1237 | +648 |
