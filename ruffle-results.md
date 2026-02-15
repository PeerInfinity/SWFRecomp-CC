# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-15 02:29 UTC

**Git SHA**: `c616aeb4c1`

**Run Duration**: 46m 13s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **197** (31.8%) |
| Failing | 422 |
| Total expected lines | 90145 |
| Matching lines | 43195 (47.9%) |
| Mismatched lines | 46950 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 410 | 97.2% |
| Runtime Segfault | 8 | 1.9% |
| Timeout | 4 | 0.9% |

## Passing Tests

**197 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 5.3s |  |
| 2 | `action_to_integer` | 28 | 3.9s |  |
| 3 | `add` | 28 | 4.0s |  |
| 4 | `add2` | 354 | 4.4s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 4.0s |  |
| 6 | `add_swf5` | 28 | 4.0s |  |
| 7 | `array_concat` | 98 | 4.2s |  |
| 8 | `array_constructor` | 30 | 4.1s |  |
| 9 | `array_length` | 42 | 4.1s |  |
| 10 | `array_properties` | 36 | 4.0s |  |
| 11 | `array_slice` | 34 | 4.1s |  |
| 12 | `array_splice` | 207 | 4.8s |  |
| 13 | `array_trivial` | 209 | 4.5s |  |
| 14 | `as1_constructor_v6` | 35 | 4.0s |  |
| 15 | `as1_constructor_v7` | 35 | 4.0s |  |
| 16 | `as_broadcaster_initialize` | 10 | 3.9s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 3.9s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 4.0s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 4.0s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 4.0s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 4.0s |  |
| 22 | `as_transformed_flag` | 20 | 4.0s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 3.8s |  |
| 24 | `bitand` | 1058 | 11.2s |  |
| 25 | `bitmap_data_colortransform` | 0 | 4.2s |  |
| 26 | `bitmap_data_fillrect` | 0 | 4.1s |  |
| 27 | `bitmap_data_max_size_swf10` | 12 | 3.9s |  |
| 28 | `bitmap_data_max_size_swf9` | 10 | 3.9s |  |
| 29 | `bitmap_data_perlinnoise` | 0 | 4.7s |  |
| 30 | `bitmap_data_pixeldissolve_image` | 0 | 4.5s |  |
| 31 | `bitmapdata_applyfilter_colormatrix` | 0 | 4.0s |  |
| 32 | `bitor` | 1058 | 11.2s |  |
| 33 | `biturshift` | 14 | 4.4s |  |
| 34 | `biturshift_swf8` | 14 | 3.8s |  |
| 35 | `bitxor` | 1058 | 10.6s |  |
| 36 | `call_method_empty_name` | 1 | 3.8s |  |
| 37 | `capabilities_resolution` | 8 | 3.8s |  |
| 38 | `catch_references_registers` | 2 | 3.8s |  |
| 39 | `conflicting_instance_names` | 23 | 4.0s |  |
| 40 | `define_function2` | 8 | 3.8s |  |
| 41 | `define_function2_preload` | 13 | 3.8s |  |
| 42 | `define_function2_preload_order` | 4 | 3.8s |  |
| 43 | `define_function_case_sensitive` | 2 | 3.8s |  |
| 44 | `delete` | 3 | 3.9s |  |
| 45 | `display_object_properties` | 2 | 3.8s |  |
| 46 | `divide_swf4` | 107 | 4.0s |  |
| 47 | `do_init_action` | 3 | 3.9s |  |
| 48 | `edittext_antialiastype` | 296 | 4.8s |  |
| 49 | `edittext_autosize_setter` | 20 | 3.9s |  |
| 50 | `edittext_default_format` | 221 | 4.1s |  |
| 51 | `edittext_default_format_empty` | 95 | 4.0s |  |
| 52 | `edittext_default_format_font_style` | 335 | 4.1s |  |
| 53 | `edittext_password` | 5 | 3.9s |  |
| 54 | `equals` | 32 | 3.9s |  |
| 55 | `equals2_swf5` | 926 | 12.3s |  |
| 56 | `equals2_swf6` | 926 | 12.3s |  |
| 57 | `equals2_swf7` | 926 | 12.5s |  |
| 58 | `equals_swf4` | 665 | 7.7s |  |
| 59 | `equals_swf4_alt` | 32 | 3.9s |  |
| 60 | `equals_swf5` | 32 | 3.9s |  |
| 61 | `error` | 58 | 4.0s |  |
| 62 | `escape` | 14 | 3.8s |  |
| 63 | `execution_order1` | 5 | 3.9s |  |
| 64 | `execution_order2` | 7 | 3.9s |  |
| 65 | `execution_order3` | 4 | 3.9s |  |
| 66 | `focusrect_mouse_swf8` | 0 | 3.8s |  |
| 67 | `focusrect_mouse_swf9` | 0 | 3.9s |  |
| 68 | `focusrect_swf5` | 6 | 4.0s |  |
| 69 | `get_variable_in_scope` | 29 | 4.0s |  |
| 70 | `getproperty` | 28 | 3.8s |  |
| 71 | `getproperty_swf4` | 28 | 3.7s |  |
| 72 | `getproperty_swf5` | 28 | 3.7s |  |
| 73 | `global_array` | 3 | 3.7s |  |
| 74 | `global_is_bare` | 7 | 3.7s |  |
| 75 | `goto_advance1` | 6 | 3.7s |  |
| 76 | `goto_advance2` | 2 | 3.7s |  |
| 77 | `goto_both_ways1` | 3 | 5.3s |  |
| 78 | `goto_both_ways2` | 3 | 3.9s |  |
| 79 | `goto_execution_order` | 2 | 3.9s |  |
| 80 | `goto_execution_order2` | 2 | 4.0s |  |
| 81 | `goto_frame_number` | 3 | 4.1s |  |
| 82 | `goto_rewind1` | 1 | 4.0s |  |
| 83 | `goto_rewind2` | 3 | 4.0s |  |
| 84 | `goto_rewind3` | 2 | 3.9s |  |
| 85 | `greater_swf6` | 1175 | 13.3s |  |
| 86 | `greater_swf7` | 1175 | 13.4s |  |
| 87 | `greaterthan_swf5` | 1 | 3.9s |  |
| 88 | `greaterthan_swf8` | 1 | 4.0s |  |
| 89 | `has_own_property` | 32 | 4.0s |  |
| 90 | `infinite_recursion_function` | 4 | 3.9s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 91 | `infinite_recursion_function_in_setter` | 131 | 3.9s |  |
| 92 | `infinite_recursion_virtual_property` | 67 | 3.9s |  |
| 93 | `init_array_invalid` | 4 | 3.9s |  |
| 94 | `init_object_invalid` | 4 | 3.9s |  |
| 95 | `issue_1086` | 1 | 3.9s |  |
| 96 | `issue_1671` | 0 | 3.9s |  |
| 97 | `issue_2166` | 9 | 3.9s |  |
| 98 | `issue_3446` | 1 | 3.9s |  |
| 99 | `issue_4377` | 2 | 3.9s |  |
| 100 | `issue_710` | 4 | 3.9s |  |
| 101 | `issue_768` | 3 | 3.9s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 102 | `lessthan` | 41 | 4.0s |  |
| 103 | `lessthan2_swf5` | 1226 | 13.9s |  |
| 104 | `lessthan2_swf6` | 1226 | 13.9s |  |
| 105 | `lessthan2_swf7` | 1226 | 13.8s |  |
| 106 | `lessthan_swf4` | 902 | 9.4s |  |
| 107 | `lessthan_swf4_alt` | 41 | 4.0s |  |
| 108 | `lessthan_swf5` | 41 | 4.0s |  |
| 109 | `logical_ops_swf4` | 90 | 3.9s |  |
| 110 | `logical_ops_swf8` | 108 | 3.9s |  |
| 111 | `looping` | 6 | 3.8s |  |
| 112 | `mask_reapply` | 0 | 3.8s |  |
| 113 | `mask_with_drawing` | 0 | 3.8s |  |
| 114 | `mouse_wheel_enabled` | 2 | 3.9s |  |
| 115 | `movieclip_begin_gradient_fill` | 0 | 4.4s |  |
| 116 | `movieclip_blend_mode_property` | 35 | 3.9s |  |
| 117 | `movieclip_default_state` | 69 | 4.3s |  |
| 118 | `movieclip_line_gradient_style` | 0 | 4.3s |  |
| 119 | `movieclip_name_from_timeline` | 13 | 3.7s |  |
| 120 | `movieclip_prototype_extension` | 5 | 3.7s |  |
| 121 | `nested_textfields_in_buttons` | 0 | 3.7s |  |
| 122 | `netstream_play_flv_screen` | 0 | 31.8s |  |
| 123 | `new_method_wrap` | 4 | 3.7s |  |
| 124 | `new_object_wrap` | 4 | 3.7s |  |
| 125 | `o` | 3 | 3.7s |  |
| 126 | `object_constructor` | 33 | 3.9s |  |
| 127 | `object_function` | 32 | 3.8s |  |
| 128 | `object_string_coerce_swf5` | 62 | 3.9s |  |
| 129 | `primitive_instanceof` | 37 | 3.9s |  |
| 130 | `prototype_delete` | 12 | 3.8s |  |
| 131 | `recursive_prototypes` | 0 | 3.7s |  |
| 132 | `sandbox_type_local_file` | 1 | 4.0s |  |
| 133 | `set_variable_scope` | 58 | 4.0s |  |
| 134 | `single_frame` | 1 | 3.9s |  |
| 135 | `sound_start_load` | 0 | 4.0s |  |
| 136 | `stage_object_properties_get_var` | 5 | 3.9s |  |
| 137 | `strictequals_swf6` | 902 | 10.5s |  |
| 138 | `strictly_equals` | 7 | 4.0s |  |
| 139 | `string_coercion` | 117 | 4.6s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 140 | `string_paths_keyevents` | 0 | 3.9s |  |
| 141 | `string_paths_timer` | 0 | 3.9s |  |
| 142 | `swf4_actions_bool` | 96 | 4.0s |  |
| 143 | `swf4_bool` | 4 | 3.9s |  |
| 144 | `swf4_function_calls` | 7 | 4.0s |  |
| 145 | `swf5_encoding` | 3 | 3.8s |  |
| 146 | `tab_ordering_properties_tab_index_edge_case` | 4 | 3.8s |  |
| 147 | `text_format` | 1146 | 4.2s |  |
| 148 | `text_format_display` | 21 | 3.9s |  |
| 149 | `text_format_font_max_length` | 2 | 3.8s |  |
| 150 | `text_format_rounding_swf7` | 840 | 4.1s |  |
| 151 | `text_format_rounding_swf8` | 840 | 4.1s |  |
| 152 | `textfield_background_color` | 11 | 3.8s |  |
| 153 | `textfield_border_color` | 11 | 3.8s |  |
| 154 | `textfield_maxchars` | 3 | 3.9s |  |
| 155 | `textfield_properties` | 44 | 4.0s |  |
| 156 | `textfield_props_swf6` | 210 | 4.8s |  |
| 157 | `textfield_props_swf7` | 210 | 4.8s |  |
| 158 | `textfield_props_swf8` | 210 | 4.8s |  |
| 159 | `textfield_text` | 7 | 3.9s |  |
| 160 | `textfield_variable` | 81 | 4.3s |  |
| 161 | `this_swf7` | 41 | 3.9s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 162 | `timeline_function_def` | 7 | 3.9s |  |
| 163 | `try_finally_simple` | 16 | 3.8s |  |
| 164 | `typeof` | 22 | 3.8s |  |
| 165 | `typeof_globals` | 7 | 3.8s |  |
| 166 | `uncaught_exception` | 1 | 3.8s |  |
| 167 | `uncaught_exception_bubbled` | 1 | 3.8s |  |
| 168 | `undefined_to_string_swf6` | 4 | 3.8s |  |
| 169 | `unescape` | 43 | 3.9s |  |
| 170 | `use_hand_cursor` | 8 | 3.8s |  |
| 171 | `variable_args` | 5 | 4.0s |  |
| 172 | `waitforframe` | 7 | 3.8s |  |
| 173 | `waitforframe2` | 16 | 3.9s |  |
| 174 | `with_return` | 2 | 3.8s |  |
| 175 | `xml` | 15 | 3.9s |  |
| 176 | `xml_append_child` | 28 | 3.9s |  |
| 177 | `xml_append_child_with_parent` | 20 | 4.0s |  |
| 178 | `xml_attributes_read` | 4 | 3.8s |  |
| 179 | `xml_cdata` | 11 | 3.8s |  |
| 180 | `xml_clone_expandos` | 19 | 3.9s |  |
| 181 | `xml_first_last_child` | 8 | 3.8s |  |
| 182 | `xml_has_child_nodes` | 3 | 3.8s |  |
| 183 | `xml_idmap` | 21 | 4.0s |  |
| 184 | `xml_ignore_white` | 34 | 4.0s |  |
| 185 | `xml_insert_before` | 20 | 4.0s |  |
| 186 | `xml_inspect_createmethods` | 15 | 4.0s |  |
| 187 | `xml_inspect_doctype` | 7 | 3.9s |  |
| 188 | `xml_inspect_parsexml` | 62 | 4.0s |  |
| 189 | `xml_inspect_xmldecl` | 7 | 3.9s |  |
| 190 | `xml_namespaces` | 203 | 3.9s |  |
| 191 | `xml_parent_and_child` | 5 | 3.8s |  |
| 192 | `xml_remove_node` | 22 | 3.9s |  |
| 193 | `xml_reparenting` | 14 | 3.9s |  |
| 194 | `xml_siblings` | 10 | 3.9s |  |
| 195 | `xml_to_string_comment` | 1 | 3.8s |  |
| 196 | `xml_unescaping` | 23 | 4.0s |  |
| 197 | `xmlnode_proto` | 1 | 3.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**102 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `edittext_width_height` | 94.2% | 97 | 103 | 6 |  |
| 2 | `swf7_case_sensitive` | 90.9% | 40 | 44 | 4 |  |
| 3 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 |  |
| 4 | `function_suppress_and_preload` | 85.7% | 24 | 28 | 4 |  |
| 5 | `xml_ignore_comments` | 85.7% | 18 | 21 | 3 |  |
| 6 | `xml_to_string` | 84.6% | 11 | 13 | 2 |  |
| 7 | `object_prototypes` | 83.8% | 62 | 74 | 12 |  |
| 8 | `stage_object_children` | 81.9% | 68 | 83 | 15 |  |
| 9 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 10 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 |  |
| 11 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 12 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 13 | `movieclip_depth_methods` | 77.6% | 76 | 98 | 22 |  |
| 14 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 15 | `as2_oop` | 76.9% | 10 | 13 | 3 |  |
| 16 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 |  |
| 17 | `xml_child_nodes_edge_cases` | 75.0% | 3 | 4 | 1 |  |
| 18 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 19 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 20 | `extends_native_type` | 72.7% | 8 | 11 | 3 |  |
| 21 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 22 | `stage_object_properties_swf6` | 71.9% | 166 | 231 | 65 |  |
| 23 | `stage_object_properties` | 71.8% | 173 | 241 | 68 |  |
| 24 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 |  |
| 25 | `transform` | 71.4% | 50 | 70 | 20 |  |
| 26 | `globals_swf6` | 71.4% | 217 | 304 | 87 |  |
| 27 | `point` | 70.9% | 124 | 175 | 51 |  |
| 28 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 29 | `globals_swf7` | 70.4% | 214 | 304 | 90 |  |
| 30 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 31 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 32 | `globals_swf5` | 69.1% | 210 | 304 | 94 |  |
| 33 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 34 | `as_set_prop_flags` | 68.4% | 54 | 79 | 25 |  |
| 35 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 36 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 37 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 38 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 |  |
| 39 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 40 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 41 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 42 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 43 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 44 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 45 | `string_methods` | 66.0% | 188 | 285 | 97 |  |
| 46 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 47 | `string_methods_swfv5` | 65.8% | 181 | 275 | 94 |  |
| 48 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 |  |
| 49 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 50 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 51 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 52 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 53 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 |  |
| 54 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 |  |
| 55 | `edittext_autosize` | 62.0% | 44 | 71 | 27 |  |
| 56 | `with` | 61.2% | 30 | 49 | 19 |  |
| 57 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 58 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 59 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 60 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 61 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 62 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 63 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 64 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 65 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 66 | `boxed_primitives` | 58.3% | 14 | 24 | 10 |  |
| 67 | `clone_sprite_types` | 58.3% | 14 | 24 | 10 |  |
| 68 | `focusrect_property_swf6` | 58.0% | 718 | 1237 | 519 |  |
| 69 | `focusrect_property_swf7` | 58.0% | 717 | 1237 | 520 |  |
| 70 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 71 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 72 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 73 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 |  |
| 74 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 75 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 76 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 77 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 78 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 |  |
| 79 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 |  |
| 80 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 |  |
| 81 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 82 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 83 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 84 | `string_methods_negative_args` | 52.7% | 127 | 241 | 114 |  |
| 85 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 86 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 87 | `globals_swf8` | 51.0% | 155 | 304 | 149 |  |
| 88 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 |  |
| 89 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 90 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 91 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 92 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 93 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 94 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 95 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 96 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 97 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 98 | `string_paths_basic` | 50.0% | 2 | 4 | 2 |  |
| 99 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 |  |
| 100 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 101 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 102 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**8 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 13.9s |  |
| 2 | `duplicate_movie_clip_drawing` | 5.9s |  |
| 3 | `goto_methods` | 6.4s |  |
| 4 | `init_object_order` | 6.1s |  |
| 5 | `path_string` | 5.7s |  |
| 6 | `register_and_init_order` | 5.9s |  |
| 7 | `register_class` | 5.5s |  |
| 8 | `swf4_actions_coercion_order` | 6.2s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bitmap_data_pixeldissolve` | runtime timeout (>10s) | 15.1s |  |
| 2 | `parse_float` | runtime timeout (>10s) | 15.3s |  |
| 3 | `timeout` | runtime timeout (>10s) | 13.9s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 14.3s |  |

## All Output Mismatches

**410 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `edittext_width_height` | 94.2% | 97/103 | 103 | 103 |  |
| 2 | `swf7_case_sensitive` | 90.9% | 40/44 | 44 | 44 |  |
| 3 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 |  |
| 4 | `function_suppress_and_preload` | 85.7% | 24/28 | 28 | 28 |  |
| 5 | `xml_ignore_comments` | 85.7% | 18/21 | 21 | 21 |  |
| 6 | `xml_to_string` | 84.6% | 11/13 | 13 | 13 |  |
| 7 | `object_prototypes` | 83.8% | 62/74 | 73 | 74 |  |
| 8 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 |  |
| 9 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 10 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 |  |
| 11 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 12 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 13 | `movieclip_depth_methods` | 77.6% | 76/98 | 98 | 98 |  |
| 14 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 15 | `as2_oop` | 76.9% | 10/13 | 13 | 13 |  |
| 16 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 |  |
| 17 | `xml_child_nodes_edge_cases` | 75.0% | 3/4 | 4 | 4 |  |
| 18 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 19 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 20 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 |  |
| 21 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 22 | `stage_object_properties_swf6` | 71.9% | 166/231 | 231 | 231 |  |
| 23 | `stage_object_properties` | 71.8% | 173/241 | 241 | 241 |  |
| 24 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 |  |
| 25 | `transform` | 71.4% | 50/70 | 70 | 70 |  |
| 26 | `globals_swf6` | 71.4% | 217/304 | 304 | 304 |  |
| 27 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 28 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 29 | `globals_swf7` | 70.4% | 214/304 | 304 | 304 |  |
| 30 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 31 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 32 | `globals_swf5` | 69.1% | 210/304 | 304 | 304 |  |
| 33 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 34 | `as_set_prop_flags` | 68.4% | 54/79 | 76 | 79 |  |
| 35 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 36 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 37 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 38 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 |  |
| 39 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 40 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 41 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 42 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 43 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 44 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 45 | `string_methods` | 66.0% | 188/285 | 285 | 285 |  |
| 46 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 47 | `string_methods_swfv5` | 65.8% | 181/275 | 275 | 275 |  |
| 48 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 |  |
| 49 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 50 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 51 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 52 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 53 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 |  |
| 54 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 |  |
| 55 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 |  |
| 56 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 57 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 58 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 59 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 60 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 61 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 62 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 63 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 64 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 65 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 66 | `boxed_primitives` | 58.3% | 14/24 | 24 | 24 |  |
| 67 | `clone_sprite_types` | 58.3% | 14/24 | 24 | 24 |  |
| 68 | `focusrect_property_swf6` | 58.0% | 718/1237 | 1236 | 1237 |  |
| 69 | `focusrect_property_swf7` | 58.0% | 717/1237 | 1236 | 1237 |  |
| 70 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 71 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 72 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 73 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 |  |
| 74 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 75 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 76 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 77 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 78 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 |  |
| 79 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 |  |
| 80 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 |  |
| 81 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 82 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 83 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 84 | `string_methods_negative_args` | 52.7% | 127/241 | 241 | 240 |  |
| 85 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 86 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 87 | `globals_swf8` | 51.0% | 155/304 | 304 | 304 |  |
| 88 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 |  |
| 89 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 90 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 91 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 92 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 93 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 94 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 95 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 96 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 97 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 98 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 |  |
| 99 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 |  |
| 100 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 101 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 102 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 103 | `edittext_html_swf6` | 49.1% | 2640/5377 | 5377 | 5377 |  |
| 104 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 105 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 106 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 107 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 |  |
| 108 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 109 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 110 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 111 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 112 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 113 | `edittext_html_swf7` | 42.2% | 2268/5377 | 5377 | 5377 |  |
| 114 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 |  |
| 115 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 |  |
| 116 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 |  |
| 117 | `edittext_html_swf8` | 39.4% | 2118/5377 | 5377 | 5377 |  |
| 118 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 119 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 |  |
| 120 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 121 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 122 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 123 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 124 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 125 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 126 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 127 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 128 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 129 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 130 | `string_paths_other` | 30.6% | 11/36 | 28 | 36 |  |
| 131 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 132 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 133 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 134 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 |  |
| 135 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 136 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 137 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 138 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 139 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 140 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 141 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 142 | `edittext_stylesheet` | 24.3% | 79/325 | 325 | 325 |  |
| 143 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 144 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 145 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 146 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 147 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 |  |
| 148 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 149 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 150 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 151 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 152 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 153 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 154 | `focusrect_property_swf5` | 19.3% | 239/1237 | 1236 | 1237 |  |
| 155 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 156 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 |  |
| 157 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 158 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 159 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 160 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 161 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 162 | `unload` | 15.4% | 8/52 | 48 | 52 |  |
| 163 | `watch` | 15.4% | 18/117 | 101 | 117 |  |
| 164 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 165 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 166 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 167 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 168 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 169 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 170 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 171 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 172 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 173 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 174 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 175 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 176 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 177 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 178 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 179 | `xml_socket` | 12.5% | 1/8 | 1 | 8 |  |
| 180 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 181 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 182 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 183 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 184 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 2 | 9 |  |
| 185 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 186 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 187 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 188 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 189 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 190 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 |  |
| 191 | `extends_chain` | 9.0% | 12/134 | 122 | 134 |  |
| 192 | `instanceof_coercions` | 8.0% | 7/88 | 70 | 88 |  |
| 193 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 194 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 195 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 196 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 197 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 198 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 199 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 200 | `focus_visibility_change` | 6.7% | 3/45 | 27 | 45 |  |
| 201 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 202 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 203 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 204 | `as2_super_and_this_v6` | 6.2% | 6/97 | 17 | 97 |  |
| 205 | `bitmap_data` | 5.8% | 68/1174 | 1174 | 1126 |  |
| 206 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 207 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 208 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 209 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 210 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 211 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 212 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 213 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 214 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 215 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 216 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 217 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 |  |
| 218 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 219 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 220 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 221 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 |  |
| 222 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 223 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 224 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 225 | `asnew` | 2.9% | 1/34 | 3 | 34 |  |
| 226 | `as2_super_and_this_v8` | 2.4% | 2/85 | 9 | 85 |  |
| 227 | `clone_sprite_edittext_dynamic` | 2.3% | 2/86 | 86 | 86 |  |
| 228 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 229 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 230 | `math_swf6` | 1.9% | 10/530 | 458 | 530 |  |
| 231 | `math_swf7` | 1.9% | 10/530 | 458 | 530 |  |
| 232 | `math_swf8` | 1.9% | 10/530 | 458 | 530 |  |
| 233 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 234 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 235 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 236 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 237 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 238 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 239 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 240 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 241 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 242 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 243 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 244 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 245 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 246 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 247 | `global_instance_decls` | 0.1% | 1/758 | 141 | 758 |  |
| 248 | `global_proto_decls` | 0.1% | 4/4497 | 95 | 4497 |  |
| 249 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 250 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 251 | `array_sort_random` | 0.0% | 0/443 | 2 | 443 |  |
| 252 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 253 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 254 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 255 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 256 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 257 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 258 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 259 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 260 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 261 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 262 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 263 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 264 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 265 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 266 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 267 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 268 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 269 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 270 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 271 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 272 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 273 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 274 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 275 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 276 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 277 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 278 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 279 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 280 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 281 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 282 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 283 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 284 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 285 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 286 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 287 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 288 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 289 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 290 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 291 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 292 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 293 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 294 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 295 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 296 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 297 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 298 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 299 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 300 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 301 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 302 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 303 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 304 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 305 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 306 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 307 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 308 | `global_proto_decls_delete` | 0.0% | 0/4158 | 24 | 4158 |  |
| 309 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 310 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 311 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 312 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 313 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 314 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 315 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 316 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 317 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 318 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 319 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 320 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 321 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 322 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 323 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 324 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 325 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 326 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 327 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 328 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 329 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 330 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 331 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 332 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 333 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 334 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 335 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 336 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 337 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 338 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 339 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 340 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 341 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 342 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 343 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 344 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 345 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 346 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 347 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 348 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 349 | `native_objects_swf6` | 0.0% | 0/186 | 186 | 84 |  |
| 350 | `native_objects_swf7` | 0.0% | 0/186 | 186 | 84 |  |
| 351 | `native_objects_swf8` | 0.0% | 0/186 | 186 | 84 |  |
| 352 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 353 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 354 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 355 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 356 | `object_resolve` | 0.0% | 0/38 | 23 | 38 |  |
| 357 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 358 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 359 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 360 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 361 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 362 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 363 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 364 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 365 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 366 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 367 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 368 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 369 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 370 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 371 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 372 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 373 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 374 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 375 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 376 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 377 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 378 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 379 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 380 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 381 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 382 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 383 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 384 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 385 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 386 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 387 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 388 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 389 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 390 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 391 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 392 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 393 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 394 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 395 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 396 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 397 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 398 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 399 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 400 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 401 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 402 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 403 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 404 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 405 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 406 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 407 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 408 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 409 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 410 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
