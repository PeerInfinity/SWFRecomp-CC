# Ruffle Test Results Diff

**Previous:** `f246282a73c1` (2026-03-19T20:52:22.882574+00:00)
**Current:** `ed111aed62c7` (2026-03-19T21:20:27.372110+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 310 | 562 | +252 |
| Total | 619 | 619 | 0 |
| Pass rate | 50.1% | 90.8% | +40.7% |
| Mismatched lines | 220 | 12909 | +12689 |
|   Decreased | | | -3 |
|   Increased | | | +12692 |

## Newly Passing (252)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `add2` | compile_fail | - | 354/354 |
| `arguments` | compile_fail | - | 127/127 |
| `array_enumerate` | compile_fail | - | 4/4 |
| `array_length` | compile_fail | - | 42/42 |
| `array_sort` | compile_fail | - | 161/161 |
| `array_sort_random` | compile_fail | - | 443/443 |
| `array_trivial` | compile_fail | - | 209/209 |
| `as2_oop` | compile_fail | - | 13/13 |
| `as2_super_and_this_v6` | compile_fail | - | 97/97 |
| `as2_super_and_this_v8` | compile_fail | - | 85/85 |
| `as2_super_via_manual_prototype` | compile_fail | - | 40/40 |
| `as_broadcaster_undef` | compile_fail | - | 89/89 |
| `as_set_prop_flags` | compile_fail | - | 79/79 |
| `as_set_prop_flags_version` | compile_fail | - | 31/31 |
| `as_set_prop_flags_version_swf5` | compile_fail | - | 1/1 |
| `as_set_prop_flags_version_swf6` | compile_fail | - | 1/1 |
| `as_set_prop_flags_version_swf7` | compile_fail | - | 1/1 |
| `as_set_prop_flags_version_swf8` | compile_fail | - | 1/1 |
| `as_set_prop_flags_version_swf9` | compile_fail | - | 1/1 |
| `asnew` | compile_fail | - | 34/34 |
| `bitmap_data` | compile_fail | - | 1126/1126 |
| `bitmap_data_compare` | compile_fail | - | 40/40 |
| `bitmap_data_copypixels` | compile_fail | - | 17/17 |
| `bitmap_data_draw_cliprect` | compile_fail | - | 13/13 |
| `bitmap_data_hittest` | compile_fail | - | 132/132 |
| `bitmap_data_noise` | compile_fail | - | 631/631 |
| `bitmap_data_perlinnoise` | compile_fail | - | 0/0 |
| `bitmap_data_pixeldissolve_image` | compile_fail | - | 0/0 |
| `bitmap_data_threshold` | compile_fail | - | 176/176 |
| `bitmapdata_channels` | compile_fail | - | 19/19 |
| `boxed_primitives` | compile_fail | - | 24/24 |
| `button_keypress_vs_press` | compile_fail | - | 25/25 |
| `button_keypress_vs_tab` | compile_fail | - | 20/20 |
| `button_properties_special_cases` | compile_fail | - | 22/22 |
| `clip_constructors` | compile_fail | - | 8/8 |
| `clip_event_propagation_order` | compile_fail | - | 17/17 |
| `clone_sprite_edittext` | compile_fail | - | 94/94 |
| `clone_sprite_edittext_dynamic` | compile_fail | - | 86/86 |
| `coerce_to_object_monkeypatch` | compile_fail | - | 129/129 |
| `coerce_to_primitive_resolve` | compile_fail | - | 17/17 |
| `color_transform` | compile_fail | - | 48/48 |
| `context_menu` | compile_fail | - | 39/39 |
| `context_menu_item` | compile_fail | - | 41/41 |
| `default_names` | compile_fail | - | 52/52 |
| `device_font_spacing` | compile_fail | - | 91/91 |
| `drag_over_from_outside` | compile_fail | - | 1/1 |
| `drag_over_without_startdrag` | compile_fail | - | 1/1 |
| `edittext_align` | compile_fail | - | 60/60 |
| `edittext_autosize_setter` | compile_fail | - | 20/20 |
| `edittext_bullet` | compile_fail | - | 30/30 |
| `edittext_default_format` | compile_fail | - | 221/221 |
| `edittext_font_size` | compile_fail | - | 45/45 |
| `edittext_html_condensewhite_swf7` | compile_fail | - | 311/311 |
| `edittext_html_condensewhite_swf8` | compile_fail | - | 311/311 |
| `edittext_html_entity` | compile_fail | - | 4/4 |
| `edittext_html_swf6` | compile_fail | - | 5377/5377 |
| `edittext_html_swf7` | compile_fail | - | 5377/5377 |
| `edittext_html_swf8` | compile_fail | - | 5377/5377 |
| `edittext_input` | compile_fail | - | 1/1 |
| `edittext_input_newlines` | compile_fail | - | 9/9 |
| `edittext_leading` | compile_fail | - | 9/9 |
| `edittext_letter_spacing` | compile_fail | - | 15/15 |
| `edittext_margins` | compile_fail | - | 25/25 |
| `edittext_newlines` | compile_fail | - | 30/30 |
| `edittext_password` | compile_fail | - | 5/5 |
| `edittext_password_copy` | compile_fail | - | 4/4 |
| `edittext_paste_empty` | compile_fail | - | 2/2 |
| `edittext_place_caret` | compile_fail | - | 2/2 |
| `edittext_restrict` | compile_fail | - | 191/191 |
| `edittext_restrict_paste` | compile_fail | - | 5/5 |
| `edittext_stylesheet` | compile_fail | - | 325/325 |
| `edittext_tab_focus` | compile_fail | - | 13/13 |
| `edittext_tab_stops` | compile_fail | - | 60/60 |
| `edittext_text_height_leading` | compile_fail | - | 20/20 |
| `edittext_underline` | compile_fail | - | 40/40 |
| `enumerate` | compile_fail | - | 64/64 |
| `extends_chain` | compile_fail | - | 134/134 |
| `extends_native_type` | compile_fail | - | 11/11 |
| `external_interface_toas_basic` | compile_fail | - | 354/354 |
| `focus_keyboard_press` | compile_fail | - | 60/60 |
| `focus_mouse_focusable` | compile_fail | - | 8/8 |
| `focus_root_movie` | compile_fail | - | 2/2 |
| `focusrect_property_swf5` | compile_fail | - | 1237/1237 |
| `focusrect_property_swf6` | compile_fail | - | 1237/1237 |
| `focusrect_property_swf7` | compile_fail | - | 1237/1237 |
| `focusrect_swf5` | compile_fail | - | 6/6 |
| `focusrect_swf6` | compile_fail | - | 42/42 |
| `form_loader_encoding_1` | compile_fail | - | 1/1 |
| `function_base_clip_readded` | compile_fail | - | 11/11 |
| `function_suppress_and_preload` | compile_fail | - | 28/28 |
| `global_swf5_6_7_8_9` | compile_fail | - | 1145/1145 |
| `global_swf6_7_8` | compile_fail | - | 15/15 |
| `globals_swf5` | output_mismatch | 301/304 | 304/304 |
| `goto_execution_order2` | compile_fail | - | 2/2 |
| `goto_frame` | compile_fail | - | 12/12 |
| `goto_frame2` | compile_fail | - | 44/44 |
| `goto_frame_number` | compile_fail | - | 3/3 |
| `goto_label` | compile_fail | - | 17/17 |
| `goto_methods` | compile_fail | - | 40/40 |
| `goto_rewind1` | compile_fail | - | 1/1 |
| `goto_rewind2` | compile_fail | - | 3/3 |
| `goto_rewind3` | compile_fail | - | 2/2 |
| `greater_swf6` | compile_fail | - | 1175/1175 |
| `greater_swf7` | compile_fail | - | 1175/1175 |
| `greaterthan_swf5` | compile_fail | - | 1/1 |
| `greaterthan_swf8` | compile_fail | - | 1/1 |
| `has_own_property` | compile_fail | - | 32/32 |
| `hittest_lockroot` | compile_fail | - | 15/15 |
| `hittest_morph` | compile_fail | - | 70/70 |
| `hittest_morph_input` | compile_fail | - | 1/1 |
| `hittest_winding_rule` | compile_fail | - | 12/12 |
| `infinite_recursion_function` | compile_fail | - | 4/4 |
| `infinite_recursion_function_in_setter` | compile_fail | - | 131/131 |
| `infinite_recursion_virtual_property` | compile_fail | - | 67/67 |
| `init_object_order` | compile_fail | - | 15/15 |
| `instanceof_coercions` | compile_fail | - | 88/88 |
| `interface_implements_op` | compile_fail | - | 47/47 |
| `issue_2084` | compile_fail | - | 16/16 |
| `issue_2166` | compile_fail | - | 9/9 |
| `issue_2870` | compile_fail | - | 3/3 |
| `issue_3169` | compile_fail | - | 2/2 |
| `issue_9327` | compile_fail | - | 2/2 |
| `loadmovie_fail` | compile_fail | - | 2/2 |
| `loadmovie_flashvars` | compile_fail | - | 4/4 |
| `loadmovie_registerclass` | compile_fail | - | 30/30 |
| `loadmovienum_cross_version_prototype` | compile_fail | - | 9/9 |
| `loadvariables` | compile_fail | - | 2/2 |
| `loadvariables2` | compile_fail | - | 8/8 |
| `loadvariablesnum` | compile_fail | - | 2/2 |
| `localconnection_properties` | compile_fail | - | 8/8 |
| `math_swf6` | compile_fail | - | 530/530 |
| `math_swf7` | compile_fail | - | 530/530 |
| `math_swf8` | compile_fail | - | 530/530 |
| `mcl_events_swf_version` | compile_fail | - | 232/232 |
| `mcl_getprogress` | compile_fail | - | 30/30 |
| `mcl_loadclip_properties` | compile_fail | - | 6/6 |
| `mcl_loadclip_replace_root` | compile_fail | - | 1/1 |
| `mcl_mislabeled_target` | compile_fail | - | 6/6 |
| `mcl_target_gif87a` | compile_fail | - | 6/6 |
| `mcl_target_gif89a` | compile_fail | - | 6/6 |
| `mcl_target_jpg` | compile_fail | - | 6/6 |
| `mcl_target_png` | compile_fail | - | 6/6 |
| `mouse_events_visible_enabled` | compile_fail | - | 12/12 |
| `mouse_hover_events_while_dragging` | compile_fail | - | 1/1 |
| `mouse_pos` | compile_fail | - | 665/665 |
| `mouse_pos_with_scale_factor` | compile_fail | - | 260/260 |
| `movieclip_blend_mode_property` | compile_fail | - | 35/35 |
| `movieclip_default_state` | compile_fail | - | 69/69 |
| `movieclip_focusenabled` | compile_fail | - | 99/99 |
| `movieclip_getbounds` | compile_fail | - | 191/191 |
| `movieclip_init_object` | compile_fail | - | 5/5 |
| `movieclip_invalid_get_bounds_1` | compile_fail | - | 75/75 |
| `movieclip_invalid_get_bounds_2` | compile_fail | - | 75/75 |
| `movieclip_invalid_get_bounds_3` | compile_fail | - | 13/13 |
| `movieclip_invalid_get_bounds_4` | compile_fail | - | 13/13 |
| `movieclip_invalid_get_bounds_5` | compile_fail | - | 11/11 |
| `movieclip_invalid_get_bounds_6` | compile_fail | - | 10/10 |
| `movieclip_invalid_get_bounds_7` | compile_fail | - | 10/10 |
| `movieclip_invalid_get_bounds_8` | compile_fail | - | 11/11 |
| `movieclip_lockroot` | compile_fail | - | 29/29 |
| `movieclip_setmask` | compile_fail | - | 14/14 |
| `moviecliploader_flashvars` | compile_fail | - | 4/4 |
| `nan_scale` | compile_fail | - | 9/9 |
| `native_double_construct` | compile_fail | - | 12/12 |
| `native_objects_swf7` | compile_fail | - | 84/84 |
| `native_objects_swf8` | compile_fail | - | 84/84 |
| `native_subclasses` | compile_fail | - | 191/191 |
| `new_object_enumerate` | compile_fail | - | 7/7 |
| `object_properties` | compile_fail | - | 31/31 |
| `object_resolve` | compile_fail | - | 38/38 |
| `on_construct` | compile_fail | - | 25/25 |
| `parse_int` | compile_fail | - | 64/64 |
| `place_and_lookup` | compile_fail | - | 30/30 |
| `primitive_type_globals` | compile_fail | - | 557/557 |
| `printjob_props_swf5` | compile_fail | - | 45/45 |
| `printjob_props_swf6` | compile_fail | - | 45/45 |
| `printjob_props_swf7` | compile_fail | - | 45/45 |
| `prototype_delete` | compile_fail | - | 12/12 |
| `prototype_enumerate` | compile_fail | - | 5/5 |
| `rectangle` | compile_fail | - | 745/745 |
| `register_and_init_order` | compile_fail | - | 231/231 |
| `register_class` | compile_fail | - | 66/66 |
| `register_class_return_value` | compile_fail | - | 16/16 |
| `register_class_swf6` | compile_fail | - | 37/37 |
| `register_class_with_sound` | compile_fail | - | 11/11 |
| `resolve_different_root` | compile_fail | - | 2/2 |
| `root_button_mode` | compile_fail | - | 10/10 |
| `set_interval` | compile_fail | - | 27/27 |
| `sound` | compile_fail | - | 628/628 |
| `sound_props_swf5` | compile_fail | - | 68/68 |
| `sound_props_swf6` | compile_fail | - | 68/68 |
| `sound_start_load` | compile_fail | - | 0/0 |
| `stage_object_enumerate` | compile_fail | - | 4/4 |
| `stage_property_representation` | compile_fail | - | 586/586 |
| `strictly_equals` | compile_fail | - | 7/7 |
| `string_coercion` | compile_fail | - | 117/117 |
| `string_methods_negative_args` | compile_fail | - | 240/240 |
| `string_paths_other` | compile_fail | - | 36/36 |
| `stylesheet` | compile_fail | - | 283/283 |
| `super_edge_cases` | compile_fail | - | 39/39 |
| `swf4_actions_coercion_order` | compile_fail | - | 158/158 |
| `swf5_global_funcs` | compile_fail | - | 232/232 |
| `swf5_to_6_cross_call` | compile_fail | - | 29/29 |
| `swf6_case_insensitive` | compile_fail | - | 42/42 |
| `swf6_global_funcs` | compile_fail | - | 232/232 |
| `swf6_string_as_bool` | compile_fail | - | 15/15 |
| `swf6_to_5_cross_call` | compile_fail | - | 29/29 |
| `swf7_case_sensitive` | compile_fail | - | 44/44 |
| `swf7_global_funcs` | compile_fail | - | 232/232 |
| `tab_ordering_automatic_basic` | compile_fail | - | 92/92 |
| `tab_ordering_automatic_order_grid` | compile_fail | - | 21/21 |
| `tab_ordering_automatic_order_same_position` | compile_fail | - | 12/12 |
| `tab_ordering_children` | compile_fail | - | 208/208 |
| `tab_ordering_custom_basic` | compile_fail | - | 71/71 |
| `tab_ordering_custom_duplicate_index` | compile_fail | - | 22/22 |
| `tab_ordering_custom_i32_vs_u32` | compile_fail | - | 12/12 |
| `tab_ordering_custom_m1` | compile_fail | - | 29/29 |
| `tab_ordering_events` | compile_fail | - | 150/150 |
| `tab_ordering_events_mouse` | compile_fail | - | 65/65 |
| `tab_ordering_movieclip_enabled_default` | compile_fail | - | 462/462 |
| `tab_ordering_properties` | compile_fail | - | 293/293 |
| `tab_ordering_reverse` | compile_fail | - | 51/51 |
| `tab_ordering_tabbable` | compile_fail | - | 47/47 |
| `text_format` | compile_fail | - | 1146/1146 |
| `textfield_props_swf5` | compile_fail | - | 175/175 |
| `textfield_props_swf6` | compile_fail | - | 210/210 |
| `textfield_props_swf7` | compile_fail | - | 210/210 |
| `textfield_props_swf8` | compile_fail | - | 210/210 |
| `textsnapshot_findtext` | compile_fail | - | 44/44 |
| `textsnapshot_gettext` | compile_fail | - | 55/55 |
| `textsnapshot_props_swf5` | compile_fail | - | 56/56 |
| `textsnapshot_props_swf6` | compile_fail | - | 56/56 |
| `timer_run_actions` | compile_fail | - | 18/18 |
| `try_catch_finally` | compile_fail | - | 118/118 |
| `try_finally_simple` | compile_fail | - | 16/16 |
| `variable_args` | compile_fail | - | 5/5 |
| `waitforframe` | compile_fail | - | 7/7 |
| `waitforframe2` | compile_fail | - | 16/16 |
| `watch` | compile_fail | - | 117/117 |
| `watch_virtual_property_proto` | compile_fail | - | 2/2 |
| `xml` | compile_fail | - | 15/15 |
| `xml_attributes_read` | compile_fail | - | 4/4 |
| `xml_idmap` | compile_fail | - | 21/21 |
| `xml_ignore_comments` | compile_fail | - | 21/21 |
| `xml_inspect_createmethods` | compile_fail | - | 15/15 |
| `xml_inspect_doctype` | compile_fail | - | 7/7 |
| `xml_inspect_parsexml` | compile_fail | - | 62/62 |
| `xml_inspect_xmldecl` | compile_fail | - | 7/7 |
| `xml_namespaces` | compile_fail | - | 203/203 |
| `xml_reparenting` | compile_fail | - | 14/14 |
| `xml_unescaping` | compile_fail | - | 23/23 |
| `xmlnode_proto` | compile_fail | - | 1/1 |

## Status Changed (35)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `bitmap_data_pixeldissolve` | compile_fail | output_mismatch | - | 82/1075 |
| `bitmap_filters` | compile_fail | segfault | - | 78/548 |
| `date` | compile_fail | output_mismatch | - | 6284/6335 |
| `file_reference_browse_cancel` | compile_fail | output_mismatch | - | 10/21 |
| `form_loader_encoding_3` | compile_fail | output_mismatch | - | 1/3 |
| `form_loader_encoding_4` | compile_fail | output_mismatch | - | 1/3 |
| `global_instance_decls` | compile_fail | output_mismatch | - | 18/758 |
| `global_proto_decls` | compile_fail | output_mismatch | - | 93/4497 |
| `global_proto_decls_delete` | compile_fail | output_mismatch | - | 91/4158 |
| `loadvariables_method` | compile_fail | output_mismatch | - | 0/7 |
| `localconnection` | compile_fail | output_mismatch | - | 74/579 |
| `mcl_replace_root_swf7_to_swf5` | compile_fail | output_mismatch | - | 56/57 |
| `mcl_replace_root_swf7_to_swf6` | compile_fail | output_mismatch | - | 56/57 |
| `movieclip_hittest_shapeflag` | compile_fail | output_mismatch | - | 312/338 |
| `movieclip_library_state_values` | compile_fail | output_mismatch | - | 76/78 |
| `movieclip_methods_with_loaded_image` | compile_fail | output_mismatch | - | 0/4 |
| `movieclip_state_values` | compile_fail | output_mismatch | - | 39/114 |
| `native_objects_swf6` | compile_fail | output_mismatch | - | 83/84 |
| `netconnection_close` | compile_fail | output_mismatch | - | 3/39 |
| `netconnection_send_remote` | compile_fail | output_mismatch | - | 1/50 |
| `netstream_play_flv` | compile_fail | output_mismatch | - | 1/21 |
| `netstream_play_flv_screen` | compile_fail | segfault | - | - |
| `netstream_seek_flv` | compile_fail | output_mismatch | - | 0/25 |
| `sound_duration_position_props` | compile_fail | output_mismatch | - | 2/290 |
| `sound_id3` | compile_fail | output_mismatch | - | 11/633 |
| `sound_id3_prop` | compile_fail | output_mismatch | - | 1/138 |
| `sound_load_start` | compile_fail | output_mismatch | - | 0/3 |
| `stylesheet_load` | compile_fail | output_mismatch | - | 1/49 |
| `timeout` | compile_fail | timeout | - | - |
| `watch_virtual_property` | compile_fail | output_mismatch | - | 9/60 |
| `xml_load` | compile_fail | output_mismatch | - | 0/2 |
| `xml_socket` | compile_fail | output_mismatch | - | 1/8 |
| `xml_socket_close_in_handler` | compile_fail | output_mismatch | - | 0/6 |
| `xml_socket_on_data` | compile_fail | output_mismatch | - | 0/7 |
| `xml_socket_segmented` | compile_fail | output_mismatch | - | 0/29 |
