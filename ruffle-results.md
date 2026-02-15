# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-15 23:08 UTC

**Git SHA**: `51c59eed98`

**Run Duration**: 50m 9s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **206** (33.3%) |
| Failing | 413 |
| Total expected lines | 91294 |
| Matching lines | 45608 (50.0%) |
| Mismatched lines | 45686 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 405 | 98.1% |
| Runtime Segfault | 6 | 1.5% |
| Timeout | 2 | 0.5% |

## Passing Tests

**206 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 4.9s |  |
| 2 | `action_to_integer` | 28 | 4.7s |  |
| 3 | `add` | 28 | 4.7s |  |
| 4 | `add2` | 354 | 4.9s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 4.3s |  |
| 6 | `add_swf5` | 28 | 4.3s |  |
| 7 | `array_concat` | 98 | 4.7s |  |
| 8 | `array_constructor` | 30 | 4.7s |  |
| 9 | `array_length` | 42 | 4.3s |  |
| 10 | `array_properties` | 36 | 4.7s |  |
| 11 | `array_slice` | 34 | 4.7s |  |
| 12 | `array_splice` | 207 | 4.8s |  |
| 13 | `array_trivial` | 209 | 4.4s |  |
| 14 | `as1_constructor_v6` | 35 | 4.3s |  |
| 15 | `as1_constructor_v7` | 35 | 4.2s |  |
| 16 | `as_broadcaster_initialize` | 10 | 4.7s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 4.2s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 4.2s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 4.2s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 4.7s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 4.7s |  |
| 22 | `as_transformed_flag` | 20 | 4.7s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 4.6s |  |
| 24 | `bitand` | 1058 | 6.7s |  |
| 25 | `bitmap_data_colortransform` | 0 | 4.9s |  |
| 26 | `bitmap_data_fillrect` | 0 | 4.8s |  |
| 27 | `bitmap_data_max_size_swf10` | 12 | 4.6s |  |
| 28 | `bitmap_data_max_size_swf9` | 10 | 4.6s |  |
| 29 | `bitmap_data_perlinnoise` | 0 | 5.2s |  |
| 30 | `bitmap_data_pixeldissolve_image` | 0 | 5.0s |  |
| 31 | `bitmapdata_applyfilter_colormatrix` | 0 | 4.7s |  |
| 32 | `bitor` | 1058 | 6.8s |  |
| 33 | `biturshift` | 14 | 4.9s |  |
| 34 | `biturshift_swf8` | 14 | 4.9s |  |
| 35 | `bitxor` | 1058 | 7.0s |  |
| 36 | `call_method_empty_name` | 1 | 4.8s |  |
| 37 | `capabilities_resolution` | 8 | 4.8s |  |
| 38 | `catch_references_registers` | 2 | 4.8s |  |
| 39 | `conflicting_instance_names` | 23 | 4.8s |  |
| 40 | `define_function2` | 8 | 4.7s |  |
| 41 | `define_function2_preload` | 13 | 4.7s |  |
| 42 | `define_function2_preload_order` | 4 | 4.4s |  |
| 43 | `define_function_case_sensitive` | 2 | 4.8s |  |
| 44 | `delete` | 3 | 4.5s |  |
| 45 | `display_object_properties` | 2 | 4.8s |  |
| 46 | `do_init_action` | 3 | 4.8s |  |
| 47 | `edittext_antialiastype` | 296 | 5.6s |  |
| 48 | `edittext_autosize_setter` | 20 | 4.2s |  |
| 49 | `edittext_default_format` | 221 | 4.8s |  |
| 50 | `edittext_default_format_empty` | 95 | 4.7s |  |
| 51 | `edittext_default_format_font_style` | 335 | 4.8s |  |
| 52 | `edittext_password` | 5 | 4.7s |  |
| 53 | `equals` | 32 | 4.8s |  |
| 54 | `equals2_swf5` | 926 | 6.0s |  |
| 55 | `equals2_swf6` | 926 | 5.9s |  |
| 56 | `equals2_swf7` | 926 | 6.0s |  |
| 57 | `equals_swf4` | 665 | 4.6s |  |
| 58 | `equals_swf4_alt` | 32 | 4.2s |  |
| 59 | `equals_swf5` | 32 | 4.2s |  |
| 60 | `error` | 58 | 4.7s |  |
| 61 | `escape` | 14 | 4.7s |  |
| 62 | `execution_order1` | 5 | 4.8s |  |
| 63 | `execution_order2` | 7 | 4.7s |  |
| 64 | `execution_order3` | 4 | 4.7s |  |
| 65 | `focusrect_mouse_swf8` | 0 | 4.8s |  |
| 66 | `focusrect_mouse_swf9` | 0 | 4.8s |  |
| 67 | `focusrect_swf5` | 6 | 4.5s |  |
| 68 | `getproperty` | 28 | 4.8s |  |
| 69 | `getproperty_swf4` | 28 | 4.2s |  |
| 70 | `getproperty_swf5` | 28 | 4.2s |  |
| 71 | `global_array` | 3 | 4.7s |  |
| 72 | `global_is_bare` | 7 | 4.8s |  |
| 73 | `globals_swf6` | 304 | 4.5s |  |
| 74 | `globals_swf7` | 304 | 4.5s |  |
| 75 | `globals_swf8` | 304 | 4.9s |  |
| 76 | `goto_advance1` | 6 | 4.7s |  |
| 77 | `goto_advance2` | 2 | 4.7s |  |
| 78 | `goto_both_ways1` | 3 | 4.5s |  |
| 79 | `goto_both_ways2` | 3 | 4.3s |  |
| 80 | `goto_execution_order` | 2 | 4.7s |  |
| 81 | `goto_execution_order2` | 2 | 4.8s |  |
| 82 | `goto_frame_number` | 3 | 4.8s |  |
| 83 | `goto_rewind1` | 1 | 4.9s |  |
| 84 | `goto_rewind2` | 3 | 4.8s |  |
| 85 | `goto_rewind3` | 2 | 4.3s |  |
| 86 | `greater_swf6` | 1175 | 6.3s |  |
| 87 | `greater_swf7` | 1175 | 6.4s |  |
| 88 | `greaterthan_swf5` | 1 | 4.2s |  |
| 89 | `greaterthan_swf8` | 1 | 4.8s |  |
| 90 | `has_own_property` | 32 | 4.3s |  |
| 91 | `infinite_recursion_function` | 4 | 4.7s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 92 | `infinite_recursion_function_in_setter` | 131 | 4.7s |  |
| 93 | `infinite_recursion_virtual_property` | 67 | 4.7s |  |
| 94 | `init_array_invalid` | 4 | 4.7s |  |
| 95 | `init_object_invalid` | 4 | 4.7s |  |
| 96 | `is_finite` | 49 | 4.7s |  |
| 97 | `is_finite_swf6` | 49 | 4.3s |  |
| 98 | `issue_1086` | 1 | 4.2s |  |
| 99 | `issue_1671` | 0 | 4.7s |  |
| 100 | `issue_2166` | 9 | 4.3s |  |
| 101 | `issue_3446` | 1 | 4.7s |  |
| 102 | `issue_4377` | 2 | 4.6s |  |
| 103 | `issue_710` | 4 | 4.2s |  |
| 104 | `issue_768` | 3 | 4.7s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 105 | `lessthan` | 41 | 4.7s |  |
| 106 | `lessthan2_swf5` | 1226 | 6.3s |  |
| 107 | `lessthan2_swf6` | 1226 | 6.3s |  |
| 108 | `lessthan2_swf7` | 1226 | 6.3s |  |
| 109 | `lessthan_swf4` | 902 | 4.8s |  |
| 110 | `lessthan_swf4_alt` | 41 | 4.2s |  |
| 111 | `lessthan_swf5` | 41 | 4.2s |  |
| 112 | `logical_ops_swf4` | 90 | 4.1s |  |
| 113 | `logical_ops_swf8` | 108 | 4.7s |  |
| 114 | `looping` | 6 | 4.7s |  |
| 115 | `mask_reapply` | 0 | 4.7s |  |
| 116 | `mask_with_drawing` | 0 | 4.7s |  |
| 117 | `math_min_max` | 101 | 4.8s |  |
| 118 | `matrix` | 171 | 5.1s |  |
| 119 | `mouse_wheel_enabled` | 2 | 4.8s |  |
| 120 | `movieclip_begin_gradient_fill` | 0 | 5.2s |  |
| 121 | `movieclip_blend_mode_property` | 35 | 4.8s |  |
| 122 | `movieclip_default_state` | 69 | 4.9s |  |
| 123 | `movieclip_line_gradient_style` | 0 | 5.2s |  |
| 124 | `movieclip_name_from_timeline` | 13 | 4.7s |  |
| 125 | `movieclip_prototype_extension` | 5 | 4.2s |  |
| 126 | `nested_textfields_in_buttons` | 0 | 4.6s |  |
| 127 | `netstream_play_flv_screen` | 0 | 17.8s |  |
| 128 | `new_method_wrap` | 4 | 4.6s |  |
| 129 | `new_object_wrap` | 4 | 4.7s |  |
| 130 | `o` | 3 | 4.7s |  |
| 131 | `object_constructor` | 33 | 4.7s |  |
| 132 | `object_function` | 32 | 4.7s |  |
| 133 | `object_string_coerce_swf5` | 62 | 4.2s |  |
| 134 | `point` | 175 | 5.0s |  |
| 135 | `primitive_instanceof` | 37 | 4.7s |  |
| 136 | `prototype_delete` | 12 | 4.7s |  |
| 137 | `rectangle` | 745 | 5.5s |  |
| 138 | `recursive_prototypes` | 0 | 4.2s |  |
| 139 | `sandbox_type_local_file` | 1 | 4.2s |  |
| 140 | `set_variable_scope` | 58 | 4.8s |  |
| 141 | `single_frame` | 1 | 4.8s |  |
| 142 | `sound_start_load` | 0 | 4.7s |  |
| 143 | `stage_object_properties_get_var` | 5 | 4.6s |  |
| 144 | `strictequals_swf6` | 902 | 5.8s |  |
| 145 | `strictly_equals` | 7 | 4.7s |  |
| 146 | `string_coercion` | 117 | 4.5s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 147 | `string_methods` | 285 | 5.4s |  |
| 148 | `string_methods_negative_args` | 240 | 4.3s |  |
| 149 | `string_methods_swfv5` | 275 | 4.7s |  |
| 150 | `string_ops_swf6` | 95 | 4.7s |  |
| 151 | `string_paths_keyevents` | 0 | 4.7s |  |
| 152 | `string_paths_timer` | 0 | 4.7s |  |
| 153 | `swf4_actions_bool` | 96 | 4.2s |  |
| 154 | `swf4_bool` | 4 | 4.2s |  |
| 155 | `swf5_encoding` | 3 | 4.1s |  |
| 156 | `tab_ordering_properties_tab_index_edge_case` | 4 | 4.6s |  |
| 157 | `text_format` | 1146 | 4.9s |  |
| 158 | `text_format_display` | 21 | 4.7s |  |
| 159 | `text_format_font_max_length` | 2 | 4.7s |  |
| 160 | `text_format_rounding_swf7` | 840 | 4.3s |  |
| 161 | `text_format_rounding_swf8` | 840 | 4.8s |  |
| 162 | `textfield_background_color` | 11 | 4.7s |  |
| 163 | `textfield_border_color` | 11 | 4.7s |  |
| 164 | `textfield_maxchars` | 3 | 4.7s |  |
| 165 | `textfield_properties` | 44 | 4.7s |  |
| 166 | `textfield_text` | 7 | 4.7s |  |
| 167 | `textfield_variable` | 81 | 4.5s |  |
| 168 | `this_swf7` | 41 | 4.3s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 169 | `timeline_function_def` | 7 | 4.3s |  |
| 170 | `try_finally_simple` | 16 | 4.8s |  |
| 171 | `typeof` | 22 | 4.9s |  |
| 172 | `typeof_globals` | 7 | 4.2s |  |
| 173 | `uncaught_exception` | 1 | 4.7s |  |
| 174 | `uncaught_exception_bubbled` | 1 | 4.8s |  |
| 175 | `undefined_to_string_swf6` | 4 | 4.3s |  |
| 176 | `unescape` | 43 | 4.7s |  |
| 177 | `use_hand_cursor` | 8 | 4.7s |  |
| 178 | `variable_args` | 5 | 4.4s |  |
| 179 | `waitforframe` | 7 | 4.2s |  |
| 180 | `waitforframe2` | 16 | 4.3s |  |
| 181 | `with_return` | 2 | 4.7s |  |
| 182 | `with_variable_scopes` | 43 | 4.8s |  |
| 183 | `xml` | 15 | 4.7s |  |
| 184 | `xml_append_child` | 28 | 4.8s |  |
| 185 | `xml_append_child_with_parent` | 20 | 4.3s |  |
| 186 | `xml_attributes_read` | 4 | 4.7s |  |
| 187 | `xml_cdata` | 11 | 4.7s |  |
| 188 | `xml_clone_expandos` | 19 | 4.7s |  |
| 189 | `xml_first_last_child` | 8 | 4.7s |  |
| 190 | `xml_has_child_nodes` | 3 | 4.7s |  |
| 191 | `xml_idmap` | 21 | 4.8s |  |
| 192 | `xml_ignore_comments` | 21 | 4.8s |  |
| 193 | `xml_ignore_white` | 34 | 4.8s |  |
| 194 | `xml_insert_before` | 20 | 4.3s |  |
| 195 | `xml_inspect_createmethods` | 15 | 4.3s |  |
| 196 | `xml_inspect_doctype` | 7 | 4.3s |  |
| 197 | `xml_inspect_parsexml` | 62 | 4.3s |  |
| 198 | `xml_inspect_xmldecl` | 7 | 4.3s |  |
| 199 | `xml_namespaces` | 203 | 4.8s |  |
| 200 | `xml_parent_and_child` | 5 | 4.8s |  |
| 201 | `xml_remove_node` | 22 | 4.4s |  |
| 202 | `xml_reparenting` | 14 | 4.4s |  |
| 203 | `xml_siblings` | 10 | 4.8s |  |
| 204 | `xml_to_string_comment` | 1 | 4.3s |  |
| 205 | `xml_unescaping` | 23 | 4.4s |  |
| 206 | `xmlnode_proto` | 1 | 4.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**102 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `textfield_props_swf6` | 99.0% | 208 | 210 | 2 |  |
| 2 | `textfield_props_swf7` | 99.0% | 208 | 210 | 2 |  |
| 3 | `textfield_props_swf8` | 99.0% | 208 | 210 | 2 |  |
| 4 | `math_swf6` | 98.5% | 522 | 530 | 8 |  |
| 5 | `math_swf7` | 98.5% | 522 | 530 | 8 |  |
| 6 | `math_swf8` | 98.5% | 522 | 530 | 8 |  |
| 7 | `globals_swf5` | 95.4% | 290 | 304 | 14 |  |
| 8 | `edittext_width_height` | 94.2% | 97 | 103 | 6 |  |
| 9 | `get_variable_in_scope` | 93.1% | 27 | 29 | 2 |  |
| 10 | `swf7_case_sensitive` | 90.9% | 40 | 44 | 4 |  |
| 11 | `divide_swf4` | 88.8% | 95 | 107 | 12 |  |
| 12 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 |  |
| 13 | `function_suppress_and_preload` | 85.7% | 24 | 28 | 4 |  |
| 14 | `swf4_function_calls` | 85.7% | 6 | 7 | 1 |  |
| 15 | `xml_to_string` | 84.6% | 11 | 13 | 2 |  |
| 16 | `object_prototypes` | 83.8% | 62 | 74 | 12 |  |
| 17 | `arguments` | 83.5% | 106 | 127 | 21 |  |
| 18 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 19 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 |  |
| 20 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 21 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 22 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 23 | `movieclip_depth_methods` | 77.6% | 76 | 98 | 22 |  |
| 24 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 25 | `as2_oop` | 76.9% | 10 | 13 | 3 |  |
| 26 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 |  |
| 27 | `xml_child_nodes_edge_cases` | 75.0% | 3 | 4 | 1 |  |
| 28 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 29 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 30 | `extends_native_type` | 72.7% | 8 | 11 | 3 |  |
| 31 | `array_sort` | 72.7% | 117 | 161 | 44 |  |
| 32 | `stage_object_properties_swf6` | 71.9% | 166 | 231 | 65 |  |
| 33 | `stage_object_properties` | 71.8% | 173 | 241 | 68 |  |
| 34 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 |  |
| 35 | `transform` | 71.4% | 50 | 70 | 20 |  |
| 36 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 37 | `with` | 69.4% | 34 | 49 | 15 |  |
| 38 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 39 | `as_set_prop_flags` | 68.4% | 54 | 79 | 25 |  |
| 40 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 41 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 42 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 43 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 |  |
| 44 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 45 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 46 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 47 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 48 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 49 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 50 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 51 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 |  |
| 52 | `sound_props_swf5` | 65.2% | 45 | 69 | 24 |  |
| 53 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 54 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 55 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 56 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 57 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 |  |
| 58 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 |  |
| 59 | `edittext_autosize` | 62.0% | 44 | 71 | 27 |  |
| 60 | `color` | 61.4% | 35 | 57 | 22 |  |
| 61 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 62 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 63 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 64 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 65 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 66 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 67 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 68 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 69 | `boxed_primitives` | 58.3% | 14 | 24 | 10 |  |
| 70 | `parse_float` | 58.1% | 43 | 74 | 31 |  |
| 71 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 72 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 73 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 74 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 |  |
| 75 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 76 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 77 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 78 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 |  |
| 79 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 |  |
| 80 | `clone_sprite_types` | 54.2% | 13 | 24 | 11 |  |
| 81 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 |  |
| 82 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 83 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 84 | `edittext_html_swf6` | 52.8% | 2838 | 5377 | 2539 |  |
| 85 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 86 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 87 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 |  |
| 88 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 89 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 90 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 91 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 92 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 93 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 94 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 95 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 96 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 97 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 98 | `string_paths_basic` | 50.0% | 2 | 4 | 2 |  |
| 99 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 |  |
| 100 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 101 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 102 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**6 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `enumerate` | 6.2s |  |
| 2 | `function_base_clip_removed` | 7.0s |  |
| 3 | `goto_methods` | 7.0s |  |
| 4 | `init_object_order` | 6.9s |  |
| 5 | `register_and_init_order` | 7.1s |  |
| 6 | `register_class` | 6.9s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**2 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 15.0s |  |
| 2 | `try_catch_finally` | runtime timeout (>10s) | 15.0s |  |

## All Output Mismatches

**405 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `textfield_props_swf6` | 99.0% | 208/210 | 210 | 210 |  |
| 2 | `textfield_props_swf7` | 99.0% | 208/210 | 210 | 210 |  |
| 3 | `textfield_props_swf8` | 99.0% | 208/210 | 210 | 210 |  |
| 4 | `math_swf6` | 98.5% | 522/530 | 529 | 530 |  |
| 5 | `math_swf7` | 98.5% | 522/530 | 529 | 530 |  |
| 6 | `math_swf8` | 98.5% | 522/530 | 529 | 530 |  |
| 7 | `globals_swf5` | 95.4% | 290/304 | 304 | 304 |  |
| 8 | `edittext_width_height` | 94.2% | 97/103 | 103 | 103 |  |
| 9 | `get_variable_in_scope` | 93.1% | 27/29 | 29 | 29 |  |
| 10 | `swf7_case_sensitive` | 90.9% | 40/44 | 44 | 44 |  |
| 11 | `divide_swf4` | 88.8% | 95/107 | 107 | 107 |  |
| 12 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 |  |
| 13 | `function_suppress_and_preload` | 85.7% | 24/28 | 28 | 28 |  |
| 14 | `swf4_function_calls` | 85.7% | 6/7 | 7 | 7 |  |
| 15 | `xml_to_string` | 84.6% | 11/13 | 13 | 13 |  |
| 16 | `object_prototypes` | 83.8% | 62/74 | 73 | 74 |  |
| 17 | `arguments` | 83.5% | 106/127 | 127 | 127 |  |
| 18 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 19 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 |  |
| 20 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 21 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 22 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 23 | `movieclip_depth_methods` | 77.6% | 76/98 | 98 | 98 |  |
| 24 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 25 | `as2_oop` | 76.9% | 10/13 | 13 | 13 |  |
| 26 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 |  |
| 27 | `xml_child_nodes_edge_cases` | 75.0% | 3/4 | 4 | 4 |  |
| 28 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 29 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 30 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 |  |
| 31 | `array_sort` | 72.7% | 117/161 | 161 | 161 |  |
| 32 | `stage_object_properties_swf6` | 71.9% | 166/231 | 231 | 231 |  |
| 33 | `stage_object_properties` | 71.8% | 173/241 | 241 | 241 |  |
| 34 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 |  |
| 35 | `transform` | 71.4% | 50/70 | 70 | 70 |  |
| 36 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 37 | `with` | 69.4% | 34/49 | 48 | 49 |  |
| 38 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 39 | `as_set_prop_flags` | 68.4% | 54/79 | 76 | 79 |  |
| 40 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 41 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 42 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 43 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 |  |
| 44 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 45 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 46 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 47 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 48 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 49 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 50 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 51 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 |  |
| 52 | `sound_props_swf5` | 65.2% | 45/69 | 69 | 68 |  |
| 53 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 54 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 55 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 56 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 57 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 |  |
| 58 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 |  |
| 59 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 |  |
| 60 | `color` | 61.4% | 35/57 | 57 | 57 |  |
| 61 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 62 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 63 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 64 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 65 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 66 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 67 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 68 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 69 | `boxed_primitives` | 58.3% | 14/24 | 24 | 24 |  |
| 70 | `parse_float` | 58.1% | 43/74 | 74 | 74 |  |
| 71 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 72 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 73 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 74 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 |  |
| 75 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 76 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 77 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 78 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 |  |
| 79 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 |  |
| 80 | `clone_sprite_types` | 54.2% | 13/24 | 24 | 24 |  |
| 81 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 |  |
| 82 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 83 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 84 | `edittext_html_swf6` | 52.8% | 2838/5377 | 5377 | 5377 |  |
| 85 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 86 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 87 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 |  |
| 88 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 89 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 90 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 91 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 92 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 93 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 94 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 95 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 96 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 97 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 98 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 |  |
| 99 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 |  |
| 100 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 101 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 102 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 103 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 104 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 |  |
| 105 | `edittext_html_swf7` | 45.9% | 2466/5377 | 5377 | 5377 |  |
| 106 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 |  |
| 107 | `bitmap_data_hittest` | 45.5% | 60/132 | 131 | 132 |  |
| 108 | `sound_props_swf6` | 44.9% | 31/69 | 69 | 68 |  |
| 109 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 110 | `string_paths_other` | 44.4% | 16/36 | 28 | 36 |  |
| 111 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 112 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 113 | `edittext_html_swf8` | 43.1% | 2316/5377 | 5377 | 5377 |  |
| 114 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 |  |
| 115 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 |  |
| 116 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 |  |
| 117 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 118 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 |  |
| 119 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 120 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 121 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 122 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 123 | `array_call_method` | 33.3% | 3/9 | 6 | 9 |  |
| 124 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 125 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 126 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 127 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 128 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 129 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 130 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 |  |
| 131 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 132 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 133 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 134 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 |  |
| 135 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 136 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 137 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 138 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 139 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 140 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 141 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 142 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 143 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 144 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 145 | `textsnapshot_props_swf5` | 21.4% | 12/56 | 39 | 56 |  |
| 146 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 |  |
| 147 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 148 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 149 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 150 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 151 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 152 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 153 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 154 | `set_interval` | 18.5% | 5/27 | 17 | 27 |  |
| 155 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 156 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 |  |
| 157 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 158 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 159 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 160 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 161 | `unload` | 15.4% | 8/52 | 48 | 52 |  |
| 162 | `watch` | 15.4% | 18/117 | 101 | 117 |  |
| 163 | `color_transform` | 14.6% | 7/48 | 38 | 48 |  |
| 164 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 165 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 166 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 167 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 168 | `path_string` | 14.0% | 45/322 | 299 | 322 |  |
| 169 | `focusrect_property_swf7` | 13.7% | 169/1237 | 276 | 1237 |  |
| 170 | `focusrect_property_swf6` | 13.6% | 168/1237 | 276 | 1237 |  |
| 171 | `printjob_props_swf5` | 13.3% | 6/45 | 36 | 45 |  |
| 172 | `printjob_props_swf6` | 13.3% | 6/45 | 36 | 45 |  |
| 173 | `printjob_props_swf7` | 13.3% | 6/45 | 36 | 45 |  |
| 174 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 175 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 176 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 177 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 178 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 179 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 180 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 181 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 182 | `xml_socket` | 12.5% | 1/8 | 1 | 8 |  |
| 183 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 184 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 185 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 186 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 2 | 9 |  |
| 187 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 39 | 56 |  |
| 188 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 189 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 190 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 191 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 192 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 193 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 |  |
| 194 | `extends_chain` | 9.0% | 12/134 | 122 | 134 |  |
| 195 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 |  |
| 196 | `instanceof_coercions` | 8.0% | 7/88 | 70 | 88 |  |
| 197 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 198 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 199 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 200 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 201 | `define_local` | 7.4% | 2/27 | 23 | 27 |  |
| 202 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 203 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 204 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 205 | `focus_visibility_change` | 6.7% | 3/45 | 27 | 45 |  |
| 206 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 207 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 208 | `as2_super_and_this_v6` | 6.2% | 6/97 | 17 | 97 |  |
| 209 | `focus_remove` | 6.1% | 2/33 | 15 | 33 |  |
| 210 | `bitmap_data` | 5.8% | 68/1174 | 1174 | 1126 |  |
| 211 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 212 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 |  |
| 213 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 214 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 215 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 216 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 217 | `context_menu` | 5.1% | 2/39 | 14 | 39 |  |
| 218 | `context_menu_item` | 4.9% | 2/41 | 10 | 41 |  |
| 219 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 220 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 221 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 222 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 |  |
| 223 | `this_scoping` | 3.8% | 2/52 | 37 | 52 |  |
| 224 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 225 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 |  |
| 226 | `focusrect_property_swf5` | 3.5% | 43/1237 | 276 | 1237 |  |
| 227 | `as2_super_and_this_v8` | 2.4% | 2/85 | 9 | 85 |  |
| 228 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 229 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 230 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 231 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 232 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 233 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 234 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 235 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 236 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 237 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 238 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 239 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 240 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 241 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 242 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 243 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 244 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 245 | `global_instance_decls` | 0.3% | 2/758 | 279 | 758 |  |
| 246 | `global_proto_decls` | 0.2% | 9/4497 | 249 | 4497 |  |
| 247 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 248 | `array_sort_random` | 0.0% | 0/443 | 2 | 443 |  |
| 249 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 250 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 251 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 252 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 253 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 254 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 255 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 256 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 257 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 258 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 259 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 260 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 261 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 262 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 263 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 264 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 265 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 266 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 267 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 268 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 269 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 270 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 271 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 272 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 273 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 274 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 275 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 |  |
| 276 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 277 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 278 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 279 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 280 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 281 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 282 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 283 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 284 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 285 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 286 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 287 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 288 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 289 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 290 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 291 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 292 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 293 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 294 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 295 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 296 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 297 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 298 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 299 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 300 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 301 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 302 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 303 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 304 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 305 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 306 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 307 | `global_proto_decls_delete` | 0.0% | 0/4158 | 114 | 4158 |  |
| 308 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 309 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 310 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 311 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 312 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 313 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 314 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 315 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 316 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 317 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 318 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 319 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 320 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 321 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 322 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 323 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 324 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 325 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 326 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 327 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 328 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 329 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 330 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 331 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 332 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 333 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 334 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 335 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 336 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 337 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 338 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 339 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 340 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 341 | `mouse_pos` | 0.0% | 0/665 | 0 | 665 |  |
| 342 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 0 | 260 |  |
| 343 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 344 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 345 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 346 | `movieclip_library_state_values` | 0.0% | 0/78 | 0 | 78 |  |
| 347 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 348 | `native_objects_swf6` | 0.0% | 0/186 | 186 | 84 |  |
| 349 | `native_objects_swf7` | 0.0% | 0/186 | 186 | 84 |  |
| 350 | `native_objects_swf8` | 0.0% | 0/196 | 196 | 84 |  |
| 351 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 352 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 353 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 354 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 355 | `object_resolve` | 0.0% | 0/38 | 23 | 38 |  |
| 356 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 357 | `parse_int` | 0.0% | 0/64 | 64 | 64 |  |
| 358 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 359 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 360 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 361 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 362 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 363 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 364 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 365 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 366 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 367 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 368 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 369 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 370 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 371 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 372 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 373 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 374 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 375 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 376 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 377 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 378 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 379 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 380 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 381 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 382 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 383 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 384 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 385 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 386 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 387 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 388 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 389 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 390 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 391 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 392 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 393 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 394 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 395 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 396 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 397 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 398 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 399 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 400 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 401 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 402 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 403 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 404 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 405 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
