# Ruffle Test Results Diff

**Previous:** `137cb550ddad` (2026-02-18T03:54:52.610728+00:00)
**Current:** `db3ce7c56c01` (2026-02-18T04:12:07.352006+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 219 | 0 | -219 |
| Total | 619 | 619 | 0 |
| Pass rate | 35.4% | 0.0% | -35.4% |
| Mismatched lines | 42992 | 0 | -42992 |
|   Decreased | | | -42992 |

## Newly Failing (219)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `access_unnamed_shape` | compile_fail | 1/1 | - |
| `action_to_integer` | compile_fail | 28/28 | - |
| `add` | compile_fail | 28/28 | - |
| `add2` | compile_fail | 354/354 | - |
| `add_swf4` | compile_fail | 28/28 | - |
| `add_swf5` | compile_fail | 28/28 | - |
| `array_concat` | compile_fail | 98/98 | - |
| `array_constructor` | compile_fail | 30/30 | - |
| `array_enumerate` | compile_fail | 4/4 | - |
| `array_length` | compile_fail | 42/42 | - |
| `array_properties` | compile_fail | 36/36 | - |
| `array_slice` | compile_fail | 34/34 | - |
| `array_splice` | compile_fail | 207/207 | - |
| `array_trivial` | compile_fail | 209/209 | - |
| `as1_constructor_v6` | compile_fail | 35/35 | - |
| `as1_constructor_v7` | compile_fail | 35/35 | - |
| `as2_oop` | compile_fail | 13/13 | - |
| `as_broadcaster_initialize` | compile_fail | 10/10 | - |
| `as_set_prop_flags_version` | compile_fail | 31/31 | - |
| `as_set_prop_flags_version_swf5` | compile_fail | 1/1 | - |
| `as_set_prop_flags_version_swf6` | compile_fail | 1/1 | - |
| `as_set_prop_flags_version_swf7` | compile_fail | 1/1 | - |
| `as_set_prop_flags_version_swf8` | compile_fail | 1/1 | - |
| `as_set_prop_flags_version_swf9` | compile_fail | 1/1 | - |
| `as_transformed_flag` | compile_fail | 20/20 | - |
| `bad_swf_tag_past_eof` | compile_fail | 0/0 | - |
| `bitand` | compile_fail | 1058/1058 | - |
| `bitmap_data_colortransform` | compile_fail | 0/0 | - |
| `bitmap_data_fillrect` | compile_fail | 0/0 | - |
| `bitmap_data_max_size_swf10` | compile_fail | 12/12 | - |
| `bitmap_data_max_size_swf9` | compile_fail | 10/10 | - |
| `bitmap_data_perlinnoise` | compile_fail | 0/0 | - |
| `bitmap_data_pixeldissolve_image` | compile_fail | 0/0 | - |
| `bitmapdata_applyfilter_colormatrix` | compile_fail | 0/0 | - |
| `bitor` | compile_fail | 1058/1058 | - |
| `biturshift` | compile_fail | 14/14 | - |
| `biturshift_swf8` | compile_fail | 14/14 | - |
| `bitxor` | compile_fail | 1058/1058 | - |
| `call_method_empty_name` | compile_fail | 1/1 | - |
| `capabilities_resolution` | compile_fail | 8/8 | - |
| `catch_references_registers` | compile_fail | 2/2 | - |
| `conflicting_instance_names` | compile_fail | 23/23 | - |
| `define_function2` | compile_fail | 8/8 | - |
| `define_function2_preload` | compile_fail | 13/13 | - |
| `define_function2_preload_order` | compile_fail | 4/4 | - |
| `define_function_case_sensitive` | compile_fail | 2/2 | - |
| `delete` | compile_fail | 3/3 | - |
| `display_object_properties` | compile_fail | 2/2 | - |
| `divide_swf4` | compile_fail | 107/107 | - |
| `do_init_action` | compile_fail | 3/3 | - |
| `edittext_antialiastype` | compile_fail | 296/296 | - |
| `edittext_autosize_setter` | compile_fail | 20/20 | - |
| `edittext_default_format` | compile_fail | 221/221 | - |
| `edittext_default_format_empty` | compile_fail | 95/95 | - |
| `edittext_default_format_font_style` | compile_fail | 335/335 | - |
| `edittext_password` | compile_fail | 5/5 | - |
| `equals` | compile_fail | 32/32 | - |
| `equals2_swf5` | compile_fail | 926/926 | - |
| `equals2_swf6` | compile_fail | 926/926 | - |
| `equals2_swf7` | compile_fail | 926/926 | - |
| `equals_swf4` | compile_fail | 665/665 | - |
| `equals_swf4_alt` | compile_fail | 32/32 | - |
| `equals_swf5` | compile_fail | 32/32 | - |
| `error` | compile_fail | 58/58 | - |
| `escape` | compile_fail | 14/14 | - |
| `execution_order1` | compile_fail | 5/5 | - |
| `execution_order2` | compile_fail | 7/7 | - |
| `execution_order3` | compile_fail | 4/4 | - |
| `focusrect_mouse_swf8` | compile_fail | 0/0 | - |
| `focusrect_mouse_swf9` | compile_fail | 0/0 | - |
| `focusrect_swf5` | compile_fail | 6/6 | - |
| `get_variable_in_scope` | compile_fail | 29/29 | - |
| `getproperty` | compile_fail | 28/28 | - |
| `getproperty_swf4` | compile_fail | 28/28 | - |
| `getproperty_swf5` | compile_fail | 28/28 | - |
| `global_array` | compile_fail | 3/3 | - |
| `global_is_bare` | compile_fail | 7/7 | - |
| `globals_swf6` | compile_fail | 304/304 | - |
| `globals_swf7` | compile_fail | 304/304 | - |
| `globals_swf8` | compile_fail | 304/304 | - |
| `goto_advance1` | compile_fail | 6/6 | - |
| `goto_advance2` | compile_fail | 2/2 | - |
| `goto_both_ways1` | compile_fail | 3/3 | - |
| `goto_both_ways2` | compile_fail | 3/3 | - |
| `goto_execution_order` | compile_fail | 2/2 | - |
| `goto_execution_order2` | compile_fail | 2/2 | - |
| `goto_frame_number` | compile_fail | 3/3 | - |
| `goto_rewind1` | compile_fail | 1/1 | - |
| `goto_rewind2` | compile_fail | 3/3 | - |
| `goto_rewind3` | compile_fail | 2/2 | - |
| `greater_swf6` | compile_fail | 1175/1175 | - |
| `greater_swf7` | compile_fail | 1175/1175 | - |
| `greaterthan_swf5` | compile_fail | 1/1 | - |
| `greaterthan_swf8` | compile_fail | 1/1 | - |
| `has_own_property` | compile_fail | 32/32 | - |
| `infinite_recursion_function` | compile_fail | 4/4 | - |
| `infinite_recursion_function_in_setter` | compile_fail | 131/131 | - |
| `infinite_recursion_virtual_property` | compile_fail | 67/67 | - |
| `init_array_invalid` | compile_fail | 4/4 | - |
| `init_object_invalid` | compile_fail | 4/4 | - |
| `is_finite` | compile_fail | 49/49 | - |
| `is_finite_swf6` | compile_fail | 49/49 | - |
| `is_prototype_of` | compile_fail | 89/89 | - |
| `issue_1086` | compile_fail | 1/1 | - |
| `issue_1671` | compile_fail | 0/0 | - |
| `issue_2166` | compile_fail | 9/9 | - |
| `issue_3446` | compile_fail | 1/1 | - |
| `issue_4377` | compile_fail | 2/2 | - |
| `issue_710` | compile_fail | 4/4 | - |
| `issue_768` | compile_fail | 3/3 | - |
| `lessthan` | compile_fail | 41/41 | - |
| `lessthan2_swf5` | compile_fail | 1226/1226 | - |
| `lessthan2_swf6` | compile_fail | 1226/1226 | - |
| `lessthan2_swf7` | compile_fail | 1226/1226 | - |
| `lessthan_swf4` | compile_fail | 902/902 | - |
| `lessthan_swf4_alt` | compile_fail | 41/41 | - |
| `lessthan_swf5` | compile_fail | 41/41 | - |
| `logical_ops_swf4` | compile_fail | 90/90 | - |
| `logical_ops_swf8` | compile_fail | 108/108 | - |
| `looping` | compile_fail | 6/6 | - |
| `mask_reapply` | compile_fail | 0/0 | - |
| `mask_with_drawing` | compile_fail | 0/0 | - |
| `math_min_max` | compile_fail | 101/101 | - |
| `matrix` | compile_fail | 171/171 | - |
| `mouse_wheel_enabled` | compile_fail | 2/2 | - |
| `movieclip_begin_gradient_fill` | compile_fail | 0/0 | - |
| `movieclip_blend_mode_property` | compile_fail | 35/35 | - |
| `movieclip_default_state` | compile_fail | 69/69 | - |
| `movieclip_line_gradient_style` | compile_fail | 0/0 | - |
| `movieclip_name_from_timeline` | compile_fail | 13/13 | - |
| `movieclip_prototype_extension` | compile_fail | 5/5 | - |
| `nested_textfields_in_buttons` | compile_fail | 0/0 | - |
| `netstream_play_flv_screen` | compile_fail | 0/0 | - |
| `new_method_wrap` | compile_fail | 4/4 | - |
| `new_object_enumerate` | compile_fail | 7/7 | - |
| `new_object_wrap` | compile_fail | 4/4 | - |
| `o` | compile_fail | 3/3 | - |
| `object_constructor` | compile_fail | 33/33 | - |
| `object_function` | compile_fail | 32/32 | - |
| `object_properties` | compile_fail | 31/31 | - |
| `object_string_coerce_swf5` | compile_fail | 62/62 | - |
| `point` | compile_fail | 175/175 | - |
| `primitive_instanceof` | compile_fail | 37/37 | - |
| `prototype_delete` | compile_fail | 12/12 | - |
| `prototype_enumerate` | compile_fail | 5/5 | - |
| `rectangle` | compile_fail | 745/745 | - |
| `recursive_prototypes` | compile_fail | 0/0 | - |
| `sandbox_type_local_file` | compile_fail | 1/1 | - |
| `set_variable_scope` | compile_fail | 58/58 | - |
| `single_frame` | compile_fail | 1/1 | - |
| `sound_start_load` | compile_fail | 0/0 | - |
| `stage_object_properties_get_var` | compile_fail | 5/5 | - |
| `strictequals_swf6` | compile_fail | 902/902 | - |
| `strictly_equals` | compile_fail | 7/7 | - |
| `string_coercion` | compile_fail | 117/117 | - |
| `string_methods` | compile_fail | 285/285 | - |
| `string_methods_negative_args` | compile_fail | 240/240 | - |
| `string_methods_swfv5` | compile_fail | 275/275 | - |
| `string_ops_swf6` | compile_fail | 95/95 | - |
| `string_paths_keyevents` | compile_fail | 0/0 | - |
| `string_paths_timer` | compile_fail | 0/0 | - |
| `swf4_actions_bool` | compile_fail | 96/96 | - |
| `swf4_bool` | compile_fail | 4/4 | - |
| `swf4_function_calls` | compile_fail | 7/7 | - |
| `swf5_encoding` | compile_fail | 3/3 | - |
| `swf7_case_sensitive` | compile_fail | 44/44 | - |
| `tab_ordering_properties_tab_index_edge_case` | compile_fail | 4/4 | - |
| `text_format` | compile_fail | 1146/1146 | - |
| `text_format_display` | compile_fail | 21/21 | - |
| `text_format_font_max_length` | compile_fail | 2/2 | - |
| `text_format_rounding_swf7` | compile_fail | 840/840 | - |
| `text_format_rounding_swf8` | compile_fail | 840/840 | - |
| `textfield_background_color` | compile_fail | 11/11 | - |
| `textfield_border_color` | compile_fail | 11/11 | - |
| `textfield_maxchars` | compile_fail | 3/3 | - |
| `textfield_properties` | compile_fail | 44/44 | - |
| `textfield_text` | compile_fail | 7/7 | - |
| `textfield_variable` | compile_fail | 81/81 | - |
| `this_swf7` | compile_fail | 41/41 | - |
| `timeline_function_def` | compile_fail | 7/7 | - |
| `try_catch_finally` | compile_fail | 118/118 | - |
| `try_finally_simple` | compile_fail | 16/16 | - |
| `typeof` | compile_fail | 22/22 | - |
| `typeof_globals` | compile_fail | 7/7 | - |
| `uncaught_exception` | compile_fail | 1/1 | - |
| `uncaught_exception_bubbled` | compile_fail | 1/1 | - |
| `undefined_to_string_swf6` | compile_fail | 4/4 | - |
| `unescape` | compile_fail | 43/43 | - |
| `use_hand_cursor` | compile_fail | 8/8 | - |
| `variable_args` | compile_fail | 5/5 | - |
| `waitforframe` | compile_fail | 7/7 | - |
| `waitforframe2` | compile_fail | 16/16 | - |
| `with_return` | compile_fail | 2/2 | - |
| `with_variable_scopes` | compile_fail | 43/43 | - |
| `xml` | compile_fail | 15/15 | - |
| `xml_append_child` | compile_fail | 28/28 | - |
| `xml_append_child_with_parent` | compile_fail | 20/20 | - |
| `xml_cdata` | compile_fail | 11/11 | - |
| `xml_child_nodes_edge_cases` | compile_fail | 4/4 | - |
| `xml_clone_expandos` | compile_fail | 19/19 | - |
| `xml_first_last_child` | compile_fail | 8/8 | - |
| `xml_has_child_nodes` | compile_fail | 3/3 | - |
| `xml_idmap` | compile_fail | 21/21 | - |
| `xml_ignore_comments` | compile_fail | 21/21 | - |
| `xml_ignore_white` | compile_fail | 34/34 | - |
| `xml_insert_before` | compile_fail | 20/20 | - |
| `xml_inspect_createmethods` | compile_fail | 15/15 | - |
| `xml_inspect_doctype` | compile_fail | 7/7 | - |
| `xml_inspect_parsexml` | compile_fail | 62/62 | - |
| `xml_inspect_xmldecl` | compile_fail | 7/7 | - |
| `xml_namespaces` | compile_fail | 203/203 | - |
| `xml_parent_and_child` | compile_fail | 5/5 | - |
| `xml_remove_node` | compile_fail | 22/22 | - |
| `xml_reparenting` | compile_fail | 14/14 | - |
| `xml_siblings` | compile_fail | 10/10 | - |
| `xml_to_string` | compile_fail | 13/13 | - |
| `xml_to_string_comment` | compile_fail | 1/1 | - |
| `xml_unescaping` | compile_fail | 23/23 | - |
| `xmlnode_proto` | compile_fail | 1/1 | - |

## Status Changed (400)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `add_property` | output_mismatch | compile_fail | 11/15 | - |
| `arguments` | output_mismatch | compile_fail | 106/127 | - |
| `array_call_method` | output_mismatch | compile_fail | 3/9 | - |
| `array_prototyping` | output_mismatch | compile_fail | 8/12 | - |
| `array_sort` | output_mismatch | compile_fail | 119/161 | - |
| `array_sort_random` | output_mismatch | compile_fail | 0/443 | - |
| `as2_super_and_this_v6` | output_mismatch | compile_fail | 7/97 | - |
| `as2_super_and_this_v8` | output_mismatch | compile_fail | 4/85 | - |
| `as2_super_via_manual_prototype` | output_mismatch | compile_fail | 11/40 | - |
| `as_broadcaster` | output_mismatch | compile_fail | 8/41 | - |
| `as_broadcaster_undef` | output_mismatch | compile_fail | 35/89 | - |
| `as_set_prop_flags` | output_mismatch | compile_fail | 62/79 | - |
| `asfunction` | output_mismatch | compile_fail | 0/11 | - |
| `asnative` | output_mismatch | compile_fail | 19/34 | - |
| `asnew` | output_mismatch | compile_fail | 10/34 | - |
| `attach_movie` | output_mismatch | compile_fail | 43/59 | - |
| `attach_movie_stop` | output_mismatch | compile_fail | 1/3 | - |
| `bad_placeobject_clipaction` | output_mismatch | compile_fail | 0/2 | - |
| `bitmap_data` | output_mismatch | compile_fail | 69/1126 | - |
| `bitmap_data_compare` | output_mismatch | compile_fail | 21/40 | - |
| `bitmap_data_copypixels` | output_mismatch | compile_fail | 3/17 | - |
| `bitmap_data_hittest` | output_mismatch | compile_fail | 62/132 | - |
| `bitmap_data_noise` | output_mismatch | compile_fail | 334/631 | - |
| `bitmap_data_pixeldissolve` | output_mismatch | compile_fail | 96/1075 | - |
| `bitmap_data_threshold` | output_mismatch | compile_fail | 104/176 | - |
| `bitmap_filters` | output_mismatch | compile_fail | 0/548 | - |
| `bitmapdata_channels` | output_mismatch | compile_fail | 11/19 | - |
| `boxed_primitives` | output_mismatch | compile_fail | 23/24 | - |
| `button_children` | output_mismatch | compile_fail | 1/8 | - |
| `button_goto` | output_mismatch | compile_fail | 0/4 | - |
| `button_key_events` | output_mismatch | compile_fail | 0/14 | - |
| `button_key_events_special` | output_mismatch | compile_fail | 0/45 | - |
| `button_keypress` | output_mismatch | compile_fail | 0/3 | - |
| `button_keypress_vs_press` | output_mismatch | compile_fail | 0/25 | - |
| `button_keypress_vs_tab` | output_mismatch | compile_fail | 0/20 | - |
| `button_keypress_vs_textinput` | output_mismatch | compile_fail | 0/4 | - |
| `button_order` | output_mismatch | compile_fail | 0/2 | - |
| `button_properties_special_cases` | output_mismatch | compile_fail | 0/22 | - |
| `button_v5` | output_mismatch | compile_fail | 0/18 | - |
| `button_v6` | output_mismatch | compile_fail | 0/18 | - |
| `call` | output_mismatch | compile_fail | 4/63 | - |
| `click_block` | output_mismatch | compile_fail | 0/5 | - |
| `clip_constructors` | output_mismatch | compile_fail | 0/8 | - |
| `clip_event_propagation_order` | output_mismatch | compile_fail | 0/17 | - |
| `clip_events` | output_mismatch | compile_fail | 1/19 | - |
| `clone_sprite_edittext` | output_mismatch | compile_fail | 2/94 | - |
| `clone_sprite_edittext_dynamic` | output_mismatch | compile_fail | 2/86 | - |
| `clone_sprite_types` | output_mismatch | compile_fail | 14/24 | - |
| `closure_scope` | output_mismatch | compile_fail | 0/7 | - |
| `coerce_to_object_monkeypatch` | output_mismatch | compile_fail | 9/129 | - |
| `coerce_to_primitive_resolve` | output_mismatch | compile_fail | 7/17 | - |
| `color` | output_mismatch | compile_fail | 35/57 | - |
| `color_transform` | output_mismatch | compile_fail | 7/48 | - |
| `constructor_function` | output_mismatch | compile_fail | 0/2 | - |
| `context_menu` | output_mismatch | compile_fail | 2/39 | - |
| `context_menu_item` | output_mismatch | compile_fail | 2/41 | - |
| `create_empty_movie_clip` | output_mismatch | compile_fail | 2/3 | - |
| `cross_movie_root` | output_mismatch | compile_fail | 0/10 | - |
| `custom_clip_methods` | output_mismatch | compile_fail | 0/4 | - |
| `date` | output_mismatch | compile_fail | 5049/6335 | - |
| `default_names` | output_mismatch | compile_fail | 11/52 | - |
| `define_local` | output_mismatch | compile_fail | 2/27 | - |
| `define_local_with_paths` | output_mismatch | compile_fail | 19/54 | - |
| `device_font_spacing` | output_mismatch | compile_fail | 1/91 | - |
| `displacementmapfilter_mappoint_throw_error` | output_mismatch | compile_fail | 0/13 | - |
| `do_init_action_child` | output_mismatch | compile_fail | 3/12 | - |
| `drag_drop` | output_mismatch | compile_fail | 0/10 | - |
| `drag_over_from_outside` | output_mismatch | compile_fail | 0/1 | - |
| `drag_over_without_startdrag` | output_mismatch | compile_fail | 0/1 | - |
| `duplicate_movie_clip` | output_mismatch | compile_fail | 4/20 | - |
| `duplicate_movie_clip_drawing` | output_mismatch | compile_fail | 0/2 | - |
| `edittext_align` | output_mismatch | compile_fail | 36/60 | - |
| `edittext_align_trailing_spaces_swf7` | output_mismatch | compile_fail | 264/576 | - |
| `edittext_align_trailing_spaces_swf8` | output_mismatch | compile_fail | 288/576 | - |
| `edittext_autosize` | output_mismatch | compile_fail | 44/71 | - |
| `edittext_bullet` | output_mismatch | compile_fail | 18/30 | - |
| `edittext_drag_select` | output_mismatch | compile_fail | 0/9 | - |
| `edittext_focus_selection` | output_mismatch | compile_fail | 0/2 | - |
| `edittext_font_size` | output_mismatch | compile_fail | 15/45 | - |
| `edittext_hscroll` | output_mismatch | compile_fail | 17/27 | - |
| `edittext_html_align_swf7` | output_mismatch | compile_fail | 42/52 | - |
| `edittext_html_align_swf8` | output_mismatch | compile_fail | 45/52 | - |
| `edittext_html_color` | output_mismatch | compile_fail | 38/114 | - |
| `edittext_html_condensewhite_swf7` | output_mismatch | compile_fail | 174/311 | - |
| `edittext_html_condensewhite_swf8` | output_mismatch | compile_fail | 171/311 | - |
| `edittext_html_entity` | output_mismatch | compile_fail | 3/4 | - |
| `edittext_html_roundtrip` | output_mismatch | compile_fail | 11/17 | - |
| `edittext_html_swf6` | output_mismatch | compile_fail | 2838/5377 | - |
| `edittext_html_swf7` | output_mismatch | compile_fail | 2466/5377 | - |
| `edittext_html_swf8` | output_mismatch | compile_fail | 2316/5377 | - |
| `edittext_ime_focus_lost` | output_mismatch | compile_fail | 0/7 | - |
| `edittext_input` | output_mismatch | compile_fail | 0/1 | - |
| `edittext_input_newlines` | output_mismatch | compile_fail | 0/9 | - |
| `edittext_leading` | output_mismatch | compile_fail | 3/9 | - |
| `edittext_letter_spacing` | output_mismatch | compile_fail | 9/15 | - |
| `edittext_margins` | output_mismatch | compile_fail | 15/25 | - |
| `edittext_newline_stripping` | output_mismatch | compile_fail | 23/64 | - |
| `edittext_newlines` | output_mismatch | compile_fail | 18/30 | - |
| `edittext_password_copy` | output_mismatch | compile_fail | 0/4 | - |
| `edittext_paste_empty` | output_mismatch | compile_fail | 0/2 | - |
| `edittext_place_caret` | output_mismatch | compile_fail | 0/2 | - |
| `edittext_programmatic_focus` | output_mismatch | compile_fail | 0/12 | - |
| `edittext_restrict` | output_mismatch | compile_fail | 0/191 | - |
| `edittext_restrict_paste` | output_mismatch | compile_fail | 0/5 | - |
| `edittext_scroll` | output_mismatch | compile_fail | 35/54 | - |
| `edittext_stylesheet` | output_mismatch | compile_fail | 107/325 | - |
| `edittext_tab_focus` | output_mismatch | compile_fail | 0/13 | - |
| `edittext_tab_stops` | output_mismatch | compile_fail | 36/60 | - |
| `edittext_tag_indent` | output_mismatch | compile_fail | 7/31 | - |
| `edittext_text_height_leading` | output_mismatch | compile_fail | 0/20 | - |
| `edittext_underline` | output_mismatch | compile_fail | 24/40 | - |
| `edittext_width_height` | output_mismatch | compile_fail | 97/103 | - |
| `empty_movieclip_can_attach_movies` | output_mismatch | compile_fail | 8/11 | - |
| `enumerate` | output_mismatch | compile_fail | 19/64 | - |
| `execution_order4` | output_mismatch | compile_fail | 2/12 | - |
| `export_assets` | output_mismatch | compile_fail | 2/3 | - |
| `extends_chain` | output_mismatch | compile_fail | 12/134 | - |
| `extends_native_type` | output_mismatch | compile_fail | 8/11 | - |
| `external_interface` | output_mismatch | compile_fail | 11/84 | - |
| `external_interface_escapexml` | output_mismatch | compile_fail | 0/26 | - |
| `external_interface_jsquotestring` | output_mismatch | compile_fail | 0/21 | - |
| `external_interface_toas_basic` | output_mismatch | compile_fail | 1/354 | - |
| `external_interface_toxml_array` | output_mismatch | compile_fail | 5/25 | - |
| `external_interface_toxml_basic` | output_mismatch | compile_fail | 35/179 | - |
| `external_interface_unescapexml` | output_mismatch | compile_fail | 0/40 | - |
| `file_reference_browse_cancel` | output_mismatch | compile_fail | 0/21 | - |
| `file_reference_download_cancel` | output_mismatch | compile_fail | 1/7 | - |
| `file_reference_download_httperror_dns_error` | output_mismatch | compile_fail | 1/13 | - |
| `file_reference_download_httperror_status_code` | output_mismatch | compile_fail | 1/23 | - |
| `file_reference_download_success` | output_mismatch | compile_fail | 7/34 | - |
| `file_reference_upload_httperror_dns_error` | output_mismatch | compile_fail | 1/18 | - |
| `file_reference_upload_httperror_status_code` | output_mismatch | compile_fail | 1/23 | - |
| `file_reference_upload_success` | output_mismatch | compile_fail | 1/23 | - |
| `focus_keyboard_press` | output_mismatch | compile_fail | 0/60 | - |
| `focus_mouse` | output_mismatch | compile_fail | 0/45 | - |
| `focus_mouse_focusable` | output_mismatch | compile_fail | 0/8 | - |
| `focus_mouse_rollout` | output_mismatch | compile_fail | 0/4 | - |
| `focus_remove` | output_mismatch | compile_fail | 2/33 | - |
| `focus_root_movie` | output_mismatch | compile_fail | 0/2 | - |
| `focus_visibility_change` | output_mismatch | compile_fail | 3/45 | - |
| `focusrect_focuslost` | output_mismatch | compile_fail | 0/4 | - |
| `focusrect_property_swf5` | output_mismatch | compile_fail | 238/1237 | - |
| `focusrect_property_swf6` | output_mismatch | compile_fail | 717/1237 | - |
| `focusrect_property_swf7` | output_mismatch | compile_fail | 718/1237 | - |
| `focusrect_swf6` | output_mismatch | compile_fail | 0/42 | - |
| `form_loader_encoding_1` | output_mismatch | compile_fail | 0/1 | - |
| `form_loader_encoding_2` | output_mismatch | compile_fail | 0/3 | - |
| `form_loader_encoding_3` | output_mismatch | compile_fail | 0/3 | - |
| `form_loader_encoding_4` | output_mismatch | compile_fail | 0/3 | - |
| `frame_size_translated_negative` | output_mismatch | compile_fail | 14/21 | - |
| `frame_size_translated_positive` | output_mismatch | compile_fail | 14/21 | - |
| `function_as_function` | output_mismatch | compile_fail | 13/35 | - |
| `function_base_clip` | output_mismatch | compile_fail | 1/8 | - |
| `function_base_clip_readded` | output_mismatch | compile_fail | 0/11 | - |
| `function_base_clip_removed` | output_mismatch | compile_fail | 1/25 | - |
| `function_suppress_and_preload` | output_mismatch | compile_fail | 24/28 | - |
| `funky_function_calls` | output_mismatch | compile_fail | 3/56 | - |
| `get_bytes_total` | output_mismatch | compile_fail | 0/4 | - |
| `gettextextent` | output_mismatch | compile_fail | 31/56 | - |
| `geturl` | output_mismatch | compile_fail | 0/7 | - |
| `global_instance_decls` | output_mismatch | compile_fail | 1/758 | - |
| `global_proto_decls` | output_mismatch | compile_fail | 8/4497 | - |
| `global_proto_decls_delete` | output_mismatch | compile_fail | 0/4158 | - |
| `global_swf5_6_7_8_9` | output_mismatch | compile_fail | 0/1145 | - |
| `global_swf6_7_8` | output_mismatch | compile_fail | 0/15 | - |
| `globals_swf5` | output_mismatch | compile_fail | 290/304 | - |
| `goto_frame` | output_mismatch | compile_fail | 3/12 | - |
| `goto_frame2` | output_mismatch | compile_fail | 8/44 | - |
| `goto_label` | output_mismatch | compile_fail | 2/17 | - |
| `goto_methods` | segfault | compile_fail | 8/40 | - |
| `hittest_lockroot` | output_mismatch | compile_fail | 6/15 | - |
| `hittest_morph` | output_mismatch | compile_fail | 15/70 | - |
| `hittest_morph_input` | output_mismatch | compile_fail | 0/1 | - |
| `hittest_winding_rule` | output_mismatch | compile_fail | 6/12 | - |
| `init_object_order` | output_mismatch | compile_fail | 5/15 | - |
| `input_dead_keys_windows` | output_mismatch | compile_fail | 0/15 | - |
| `instanceof_coercions` | output_mismatch | compile_fail | 13/88 | - |
| `interface_implements_op` | output_mismatch | compile_fail | 0/47 | - |
| `issue_1104` | output_mismatch | compile_fail | 0/2 | - |
| `issue_1906` | output_mismatch | compile_fail | 2/4 | - |
| `issue_2030` | output_mismatch | compile_fail | 2/4 | - |
| `issue_2084` | output_mismatch | compile_fail | 0/16 | - |
| `issue_2870` | output_mismatch | compile_fail | 0/3 | - |
| `issue_3169` | output_mismatch | compile_fail | 0/2 | - |
| `issue_3522` | output_mismatch | compile_fail | 1/2 | - |
| `issue_9327` | output_mismatch | compile_fail | 0/2 | - |
| `issue_9885` | output_mismatch | compile_fail | 1/2 | - |
| `key_isToggled` | output_mismatch | compile_fail | 0/9 | - |
| `load_vars` | output_mismatch | compile_fail | 13/35 | - |
| `loading_avm2` | output_mismatch | compile_fail | 1/7 | - |
| `loadmovie` | output_mismatch | compile_fail | 1/2 | - |
| `loadmovie_fail` | output_mismatch | compile_fail | 1/2 | - |
| `loadmovie_flashvars` | output_mismatch | compile_fail | 1/4 | - |
| `loadmovie_method` | output_mismatch | compile_fail | 1/2 | - |
| `loadmovie_registerclass` | output_mismatch | compile_fail | 0/30 | - |
| `loadmovie_replace_root` | output_mismatch | compile_fail | 0/5 | - |
| `loadmovie_var_persistence` | output_mismatch | compile_fail | 1/8 | - |
| `loadmovienum` | output_mismatch | compile_fail | 1/3 | - |
| `loadmovienum_cross_version_prototype` | output_mismatch | compile_fail | 1/9 | - |
| `loadvariables` | output_mismatch | compile_fail | 0/2 | - |
| `loadvariables2` | output_mismatch | compile_fail | 1/8 | - |
| `loadvariables_method` | output_mismatch | compile_fail | 0/7 | - |
| `loadvariablesnum` | output_mismatch | compile_fail | 0/2 | - |
| `local_to_global` | output_mismatch | compile_fail | 41/49 | - |
| `localconnection` | output_mismatch | compile_fail | 0/579 | - |
| `localconnection_properties` | output_mismatch | compile_fail | 4/8 | - |
| `lock_root` | output_mismatch | compile_fail | 0/1 | - |
| `math_swf6` | output_mismatch | compile_fail | 522/530 | - |
| `math_swf7` | output_mismatch | compile_fail | 522/530 | - |
| `math_swf8` | output_mismatch | compile_fail | 522/530 | - |
| `mcl_as_broadcaster` | output_mismatch | compile_fail | 0/12 | - |
| `mcl_events_swf_version` | output_mismatch | compile_fail | 0/232 | - |
| `mcl_getprogress` | output_mismatch | compile_fail | 0/30 | - |
| `mcl_loadclip` | output_mismatch | compile_fail | 25/149 | - |
| `mcl_loadclip_properties` | output_mismatch | compile_fail | 0/6 | - |
| `mcl_loadclip_replace_root` | output_mismatch | compile_fail | 0/1 | - |
| `mcl_mislabeled_target` | output_mismatch | compile_fail | 0/6 | - |
| `mcl_replace_root_swf7_to_swf5` | output_mismatch | compile_fail | 1/57 | - |
| `mcl_replace_root_swf7_to_swf6` | output_mismatch | compile_fail | 1/57 | - |
| `mcl_target_gif87a` | output_mismatch | compile_fail | 0/6 | - |
| `mcl_target_gif89a` | output_mismatch | compile_fail | 0/6 | - |
| `mcl_target_jpg` | output_mismatch | compile_fail | 0/6 | - |
| `mcl_target_png` | output_mismatch | compile_fail | 0/6 | - |
| `mcl_unloadclip` | output_mismatch | compile_fail | 0/5 | - |
| `mixed_avm_load_into_root` | output_mismatch | compile_fail | 0/2 | - |
| `mouse_events` | output_mismatch | compile_fail | 0/8 | - |
| `mouse_events_visible_enabled` | output_mismatch | compile_fail | 0/12 | - |
| `mouse_hover_events_while_dragging` | output_mismatch | compile_fail | 0/1 | - |
| `mouse_listeners` | output_mismatch | compile_fail | 45/67 | - |
| `mouse_pos` | output_mismatch | compile_fail | 0/665 | - |
| `mouse_pos_with_scale_factor` | output_mismatch | compile_fail | 0/260 | - |
| `movieclip_create_text_field` | output_mismatch | compile_fail | 0/90 | - |
| `movieclip_depth_methods` | output_mismatch | compile_fail | 76/98 | - |
| `movieclip_focusenabled` | output_mismatch | compile_fail | 71/99 | - |
| `movieclip_get_instance_at_depth` | output_mismatch | compile_fail | 18/28 | - |
| `movieclip_getbounds` | output_mismatch | compile_fail | 45/191 | - |
| `movieclip_gettextsnapshot` | output_mismatch | compile_fail | 4/112 | - |
| `movieclip_hittest` | output_mismatch | compile_fail | 71/92 | - |
| `movieclip_hittest_shapeflag` | output_mismatch | compile_fail | 180/338 | - |
| `movieclip_in_removed_button` | output_mismatch | compile_fail | 0/4 | - |
| `movieclip_init_object` | output_mismatch | compile_fail | 0/5 | - |
| `movieclip_invalid_get_bounds_1` | output_mismatch | compile_fail | 1/75 | - |
| `movieclip_invalid_get_bounds_2` | output_mismatch | compile_fail | 1/75 | - |
| `movieclip_invalid_get_bounds_3` | output_mismatch | compile_fail | 1/13 | - |
| `movieclip_invalid_get_bounds_4` | output_mismatch | compile_fail | 1/13 | - |
| `movieclip_invalid_get_bounds_5` | output_mismatch | compile_fail | 1/11 | - |
| `movieclip_invalid_get_bounds_6` | output_mismatch | compile_fail | 1/10 | - |
| `movieclip_invalid_get_bounds_7` | output_mismatch | compile_fail | 1/10 | - |
| `movieclip_invalid_get_bounds_8` | output_mismatch | compile_fail | 1/11 | - |
| `movieclip_library_state_values` | output_mismatch | compile_fail | 0/78 | - |
| `movieclip_lockroot` | output_mismatch | compile_fail | 16/29 | - |
| `movieclip_methods_with_loaded_image` | output_mismatch | compile_fail | 0/4 | - |
| `movieclip_setmask` | output_mismatch | compile_fail | 2/14 | - |
| `movieclip_state_values` | output_mismatch | compile_fail | 1/114 | - |
| `moviecliploader_flashvars` | output_mismatch | compile_fail | 1/4 | - |
| `mutable_this` | output_mismatch | compile_fail | 12/18 | - |
| `named_shapes` | output_mismatch | compile_fail | 9/14 | - |
| `nan_scale` | output_mismatch | compile_fail | 5/9 | - |
| `native_double_construct` | output_mismatch | compile_fail | 5/12 | - |
| `native_objects_swf6` | output_mismatch | compile_fail | 0/84 | - |
| `native_objects_swf7` | output_mismatch | compile_fail | 0/84 | - |
| `native_objects_swf8` | output_mismatch | compile_fail | 0/84 | - |
| `native_subclasses` | output_mismatch | compile_fail | 9/191 | - |
| `netconnection_close` | output_mismatch | compile_fail | 3/39 | - |
| `netconnection_send_remote` | output_mismatch | compile_fail | 0/50 | - |
| `netstream_play_flv` | output_mismatch | compile_fail | 0/21 | - |
| `netstream_seek_flv` | output_mismatch | compile_fail | 0/25 | - |
| `object_prototypes` | output_mismatch | compile_fail | 63/74 | - |
| `object_resolve` | output_mismatch | compile_fail | 0/38 | - |
| `object_string_coerce_swf6` | output_mismatch | compile_fail | 46/68 | - |
| `on_construct` | output_mismatch | compile_fail | 0/25 | - |
| `parse_float` | output_mismatch | compile_fail | 43/74 | - |
| `parse_int` | output_mismatch | compile_fail | 1/64 | - |
| `path_string` | output_mismatch | compile_fail | 45/322 | - |
| `place_and_lookup` | output_mismatch | compile_fail | 0/30 | - |
| `placeobject_occupied_depth` | output_mismatch | compile_fail | 0/6 | - |
| `primitive_type_globals` | output_mismatch | compile_fail | 321/557 | - |
| `printjob_props_swf5` | output_mismatch | compile_fail | 6/45 | - |
| `printjob_props_swf6` | output_mismatch | compile_fail | 6/45 | - |
| `printjob_props_swf7` | output_mismatch | compile_fail | 6/45 | - |
| `property_invalid_base_clip` | output_mismatch | compile_fail | 11/36 | - |
| `prototype_properties` | output_mismatch | compile_fail | 15/17 | - |
| `register_and_init_order` | output_mismatch | compile_fail | 30/231 | - |
| `register_class` | output_mismatch | compile_fail | 2/66 | - |
| `register_class_return_value` | output_mismatch | compile_fail | 6/16 | - |
| `register_class_swf6` | output_mismatch | compile_fail | 0/37 | - |
| `register_class_with_sound` | output_mismatch | compile_fail | 1/11 | - |
| `register_globals_across_frames` | output_mismatch | compile_fail | 7/15 | - |
| `register_underflow` | output_mismatch | compile_fail | 18/26 | - |
| `remove_movie_clip` | output_mismatch | compile_fail | 19/29 | - |
| `removed_base_clip_tell_target` | output_mismatch | compile_fail | 0/2 | - |
| `removed_clip_halts_script` | output_mismatch | compile_fail | 1/15 | - |
| `removed_target_clip_scope` | output_mismatch | compile_fail | 0/35 | - |
| `resolve_different_root` | output_mismatch | compile_fail | 0/2 | - |
| `rewind_depth` | output_mismatch | compile_fail | 9/30 | - |
| `root_button_mode` | output_mismatch | compile_fail | 0/10 | - |
| `root_global_parent` | output_mismatch | compile_fail | 1/6 | - |
| `root_onload` | output_mismatch | compile_fail | 0/1 | - |
| `sandbox_type_local_network` | output_mismatch | compile_fail | 0/1 | - |
| `sandbox_type_remote` | output_mismatch | compile_fail | 0/3 | - |
| `selection` | output_mismatch | compile_fail | 42/454 | - |
| `selection_handlers` | output_mismatch | compile_fail | 1/27 | - |
| `set_interval` | output_mismatch | compile_fail | 5/27 | - |
| `slash_syntax` | output_mismatch | compile_fail | 0/14 | - |
| `sound` | output_mismatch | compile_fail | 160/628 | - |
| `sound_duration_position_props` | output_mismatch | compile_fail | 2/290 | - |
| `sound_id3` | output_mismatch | compile_fail | 11/633 | - |
| `sound_id3_prop` | output_mismatch | compile_fail | 1/138 | - |
| `sound_load_start` | output_mismatch | compile_fail | 0/3 | - |
| `sound_multiple_load` | output_mismatch | compile_fail | 0/1 | - |
| `sound_props_swf5` | output_mismatch | compile_fail | 49/68 | - |
| `sound_props_swf6` | output_mismatch | compile_fail | 35/68 | - |
| `stage_display_state` | output_mismatch | compile_fail | 2/16 | - |
| `stage_object_children` | output_mismatch | compile_fail | 68/83 | - |
| `stage_object_enumerate` | output_mismatch | compile_fail | 1/4 | - |
| `stage_object_properties` | output_mismatch | compile_fail | 173/241 | - |
| `stage_object_properties_swf6` | output_mismatch | compile_fail | 166/231 | - |
| `stage_property_representation` | output_mismatch | compile_fail | 4/586 | - |
| `stage_scale_mode` | output_mismatch | compile_fail | 18/39 | - |
| `string_paths_basic` | output_mismatch | compile_fail | 2/4 | - |
| `string_paths_eval` | output_mismatch | compile_fail | 0/4 | - |
| `string_paths_eval2` | output_mismatch | compile_fail | 1/7 | - |
| `string_paths_hidden` | output_mismatch | compile_fail | 34/54 | - |
| `string_paths_other` | output_mismatch | compile_fail | 16/36 | - |
| `string_paths_reference_launder` | output_mismatch | compile_fail | 0/2 | - |
| `string_paths_unload` | output_mismatch | compile_fail | 0/1 | - |
| `string_paths_variable_alias` | output_mismatch | compile_fail | 2/4 | - |
| `string_paths_variable_scopes` | output_mismatch | compile_fail | 0/5 | - |
| `stylesheet` | output_mismatch | compile_fail | 15/283 | - |
| `stylesheet_load` | output_mismatch | compile_fail | 1/49 | - |
| `stylesheet_transform` | output_mismatch | compile_fail | 375/750 | - |
| `super_edge_cases` | output_mismatch | compile_fail | 7/39 | - |
| `swf4_actions_coercion_order` | output_mismatch | compile_fail | 11/158 | - |
| `swf5_global_funcs` | output_mismatch | compile_fail | 1/232 | - |
| `swf5_no_closure` | output_mismatch | compile_fail | 8/19 | - |
| `swf5_to_6_cross_call` | output_mismatch | compile_fail | 0/29 | - |
| `swf5_xml_event_handler_context` | output_mismatch | compile_fail | 0/2 | - |
| `swf6_case_insensitive` | output_mismatch | compile_fail | 28/42 | - |
| `swf6_global_funcs` | output_mismatch | compile_fail | 1/232 | - |
| `swf6_string_as_bool` | output_mismatch | compile_fail | 0/15 | - |
| `swf6_to_5_cross_call` | output_mismatch | compile_fail | 0/29 | - |
| `swf7_global_funcs` | output_mismatch | compile_fail | 1/232 | - |
| `tab_ordering_automatic_basic` | output_mismatch | compile_fail | 0/92 | - |
| `tab_ordering_automatic_order_grid` | output_mismatch | compile_fail | 0/21 | - |
| `tab_ordering_automatic_order_same_position` | output_mismatch | compile_fail | 0/12 | - |
| `tab_ordering_children` | output_mismatch | compile_fail | 0/208 | - |
| `tab_ordering_custom_basic` | output_mismatch | compile_fail | 0/71 | - |
| `tab_ordering_custom_duplicate_index` | output_mismatch | compile_fail | 0/22 | - |
| `tab_ordering_custom_i32_vs_u32` | output_mismatch | compile_fail | 0/12 | - |
| `tab_ordering_custom_m1` | output_mismatch | compile_fail | 0/29 | - |
| `tab_ordering_events` | output_mismatch | compile_fail | 2/150 | - |
| `tab_ordering_events_mouse` | output_mismatch | compile_fail | 0/65 | - |
| `tab_ordering_movieclip_enabled_default` | output_mismatch | compile_fail | 0/462 | - |
| `tab_ordering_properties` | output_mismatch | compile_fail | 156/293 | - |
| `tab_ordering_reverse` | output_mismatch | compile_fail | 0/51 | - |
| `tab_ordering_tabbable` | output_mismatch | compile_fail | 0/47 | - |
| `target_clip_removed` | output_mismatch | compile_fail | 4/5 | - |
| `target_clip_swf5` | output_mismatch | compile_fail | 0/2 | - |
| `target_clip_swf6` | output_mismatch | compile_fail | 0/2 | - |
| `target_path` | output_mismatch | compile_fail | 11/14 | - |
| `tell_target` | output_mismatch | compile_fail | 0/37 | - |
| `tell_target_invalid` | output_mismatch | compile_fail | 0/6 | - |
| `tell_target_invalid_swf6` | output_mismatch | compile_fail | 0/5 | - |
| `text_blocks_clicks` | output_mismatch | compile_fail | 0/4 | - |
| `textfield_cache_as_bitmap` | output_mismatch | compile_fail | 0/1 | - |
| `textfield_props_swf5` | output_mismatch | compile_fail | 41/175 | - |
| `textfield_props_swf6` | output_mismatch | compile_fail | 142/210 | - |
| `textfield_props_swf7` | output_mismatch | compile_fail | 142/210 | - |
| `textfield_props_swf8` | output_mismatch | compile_fail | 142/210 | - |
| `textsnapshot_available_text` | output_mismatch | compile_fail | 10/20 | - |
| `textsnapshot_findtext` | output_mismatch | compile_fail | 5/44 | - |
| `textsnapshot_gettext` | output_mismatch | compile_fail | 4/55 | - |
| `textsnapshot_props_swf5` | output_mismatch | compile_fail | 13/56 | - |
| `textsnapshot_props_swf6` | output_mismatch | compile_fail | 6/56 | - |
| `textsnapshot_text_order` | output_mismatch | compile_fail | 0/1 | - |
| `this_scoping` | output_mismatch | compile_fail | 32/52 | - |
| `this_swf5` | output_mismatch | compile_fail | 19/41 | - |
| `this_swf6` | output_mismatch | compile_fail | 18/41 | - |
| `timeout` | timeout | compile_fail | - | - |
| `timer_run_actions` | output_mismatch | compile_fail | 1/18 | - |
| `trace` | output_mismatch | compile_fail | 1/8 | - |
| `transform` | output_mismatch | compile_fail | 50/70 | - |
| `unload` | output_mismatch | compile_fail | 8/52 | - |
| `unload_clip_event` | output_mismatch | compile_fail | 0/4 | - |
| `unload_nested_child` | output_mismatch | compile_fail | 0/5 | - |
| `unloadmovie` | output_mismatch | compile_fail | 2/4 | - |
| `unloadmovie_method` | output_mismatch | compile_fail | 1/3 | - |
| `unloadmovienum` | output_mismatch | compile_fail | 3/13 | - |
| `watch` | output_mismatch | compile_fail | 18/117 | - |
| `watch_textfield` | output_mismatch | compile_fail | 2/12 | - |
| `watch_virtual_property` | output_mismatch | compile_fail | 8/60 | - |
| `watch_virtual_property_proto` | output_mismatch | compile_fail | 0/2 | - |
| `with` | output_mismatch | compile_fail | 46/49 | - |
| `xml_attributes_read` | output_mismatch | compile_fail | 2/4 | - |
| `xml_getbytes` | output_mismatch | compile_fail | 9/17 | - |
| `xml_load` | output_mismatch | compile_fail | 0/2 | - |
| `xml_socket` | output_mismatch | compile_fail | 1/8 | - |
| `xml_socket_close_in_handler` | output_mismatch | compile_fail | 0/6 | - |
| `xml_socket_on_data` | output_mismatch | compile_fail | 0/7 | - |
| `xml_socket_segmented` | output_mismatch | compile_fail | 0/29 | - |
