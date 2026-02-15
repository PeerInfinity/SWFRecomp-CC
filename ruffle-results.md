# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-15 19:40 UTC

**Git SHA**: `3048065573`

**Run Duration**: 46m 59s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **187** (30.2%) |
| Failing | 432 |
| Total expected lines | 87171 |
| Matching lines | 42325 (48.6%) |
| Mismatched lines | 44846 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 381 | 88.2% |
| Runtime Segfault | 49 | 11.3% |
| Timeout | 2 | 0.5% |

## Passing Tests

**187 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 4.4s |  |
| 2 | `action_to_integer` | 28 | 4.2s |  |
| 3 | `add` | 28 | 4.2s |  |
| 4 | `add2` | 354 | 4.4s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 4.2s |  |
| 6 | `add_swf5` | 28 | 4.2s |  |
| 7 | `array_concat` | 98 | 4.3s |  |
| 8 | `array_constructor` | 30 | 4.3s |  |
| 9 | `array_length` | 42 | 4.3s |  |
| 10 | `array_properties` | 36 | 4.2s |  |
| 11 | `array_slice` | 34 | 4.3s |  |
| 12 | `array_splice` | 207 | 4.6s |  |
| 13 | `array_trivial` | 209 | 4.3s |  |
| 14 | `as1_constructor_v6` | 35 | 4.2s |  |
| 15 | `as1_constructor_v7` | 35 | 4.2s |  |
| 16 | `as_broadcaster_initialize` | 10 | 4.2s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 4.2s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 4.2s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 4.2s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 4.3s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 4.2s |  |
| 22 | `as_transformed_flag` | 20 | 4.2s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 4.2s |  |
| 24 | `bitand` | 1058 | 6.9s |  |
| 25 | `bitmap_data_colortransform` | 0 | 4.5s |  |
| 26 | `bitmap_data_fillrect` | 0 | 4.4s |  |
| 27 | `bitmap_data_max_size_swf10` | 12 | 4.2s |  |
| 28 | `bitmap_data_max_size_swf9` | 10 | 4.2s |  |
| 29 | `bitmapdata_applyfilter_colormatrix` | 0 | 4.2s |  |
| 30 | `bitor` | 1058 | 6.9s |  |
| 31 | `biturshift` | 14 | 5.8s |  |
| 32 | `biturshift_swf8` | 14 | 4.1s |  |
| 33 | `bitxor` | 1058 | 6.6s |  |
| 34 | `call_method_empty_name` | 1 | 4.1s |  |
| 35 | `capabilities_resolution` | 8 | 4.1s |  |
| 36 | `catch_references_registers` | 2 | 4.1s |  |
| 37 | `conflicting_instance_names` | 23 | 4.2s |  |
| 38 | `define_function2` | 8 | 4.1s |  |
| 39 | `define_function_case_sensitive` | 2 | 4.1s |  |
| 40 | `delete` | 3 | 4.2s |  |
| 41 | `display_object_properties` | 2 | 4.1s |  |
| 42 | `do_init_action` | 3 | 4.2s |  |
| 43 | `edittext_antialiastype` | 296 | 4.6s |  |
| 44 | `edittext_autosize_setter` | 20 | 4.1s |  |
| 45 | `edittext_default_format` | 221 | 4.3s |  |
| 46 | `edittext_default_format_empty` | 95 | 4.1s |  |
| 47 | `edittext_default_format_font_style` | 335 | 4.2s |  |
| 48 | `edittext_password` | 5 | 4.2s |  |
| 49 | `equals` | 32 | 4.2s |  |
| 50 | `equals2_swf5` | 926 | 5.8s |  |
| 51 | `equals2_swf6` | 926 | 5.7s |  |
| 52 | `equals2_swf7` | 926 | 5.7s |  |
| 53 | `equals_swf4` | 665 | 4.5s |  |
| 54 | `equals_swf4_alt` | 32 | 4.1s |  |
| 55 | `equals_swf5` | 32 | 4.2s |  |
| 56 | `error` | 58 | 4.1s |  |
| 57 | `escape` | 14 | 4.1s |  |
| 58 | `execution_order1` | 5 | 4.2s |  |
| 59 | `execution_order2` | 7 | 4.2s |  |
| 60 | `execution_order3` | 4 | 4.1s |  |
| 61 | `focusrect_mouse_swf8` | 0 | 4.2s |  |
| 62 | `focusrect_mouse_swf9` | 0 | 4.2s |  |
| 63 | `focusrect_swf5` | 6 | 4.3s |  |
| 64 | `getproperty` | 28 | 4.2s |  |
| 65 | `getproperty_swf4` | 28 | 4.1s |  |
| 66 | `getproperty_swf5` | 28 | 4.1s |  |
| 67 | `global_array` | 3 | 4.2s |  |
| 68 | `global_is_bare` | 7 | 4.2s |  |
| 69 | `globals_swf6` | 304 | 4.4s |  |
| 70 | `globals_swf7` | 304 | 4.5s |  |
| 71 | `globals_swf8` | 304 | 4.6s |  |
| 72 | `goto_advance1` | 6 | 4.3s |  |
| 73 | `goto_advance2` | 2 | 4.2s |  |
| 74 | `goto_both_ways1` | 3 | 4.3s |  |
| 75 | `goto_both_ways2` | 3 | 4.2s |  |
| 76 | `goto_execution_order` | 2 | 4.1s |  |
| 77 | `goto_execution_order2` | 2 | 4.1s |  |
| 78 | `goto_frame_number` | 3 | 4.2s |  |
| 79 | `goto_rewind1` | 1 | 4.2s |  |
| 80 | `goto_rewind2` | 3 | 4.2s |  |
| 81 | `goto_rewind3` | 2 | 4.1s |  |
| 82 | `greater_swf6` | 1175 | 6.1s |  |
| 83 | `greater_swf7` | 1175 | 6.1s |  |
| 84 | `greaterthan_swf5` | 1 | 4.1s |  |
| 85 | `greaterthan_swf8` | 1 | 4.1s |  |
| 86 | `has_own_property` | 32 | 4.1s |  |
| 87 | `infinite_recursion_function` | 4 | 4.2s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 88 | `infinite_recursion_function_in_setter` | 131 | 4.2s |  |
| 89 | `infinite_recursion_virtual_property` | 67 | 4.1s |  |
| 90 | `init_array_invalid` | 4 | 4.1s |  |
| 91 | `init_object_invalid` | 4 | 4.1s |  |
| 92 | `is_finite` | 49 | 4.2s |  |
| 93 | `is_finite_swf6` | 49 | 4.1s |  |
| 94 | `issue_1086` | 1 | 4.0s |  |
| 95 | `issue_1671` | 0 | 4.1s |  |
| 96 | `issue_2166` | 9 | 4.1s |  |
| 97 | `issue_3446` | 1 | 4.2s |  |
| 98 | `issue_4377` | 2 | 4.1s |  |
| 99 | `issue_710` | 4 | 4.0s |  |
| 100 | `lessthan` | 41 | 4.1s |  |
| 101 | `lessthan2_swf5` | 1226 | 6.3s |  |
| 102 | `lessthan2_swf6` | 1226 | 6.3s |  |
| 103 | `lessthan2_swf7` | 1226 | 6.3s |  |
| 104 | `lessthan_swf4` | 902 | 4.8s |  |
| 105 | `lessthan_swf4_alt` | 41 | 4.1s |  |
| 106 | `lessthan_swf5` | 41 | 4.1s |  |
| 107 | `logical_ops_swf4` | 90 | 3.9s |  |
| 108 | `logical_ops_swf8` | 108 | 4.1s |  |
| 109 | `looping` | 6 | 4.0s |  |
| 110 | `mask_reapply` | 0 | 4.0s |  |
| 111 | `mask_with_drawing` | 0 | 4.0s |  |
| 112 | `math_min_max` | 101 | 4.1s |  |
| 113 | `mouse_wheel_enabled` | 2 | 4.1s |  |
| 114 | `movieclip_begin_gradient_fill` | 0 | 4.5s |  |
| 115 | `movieclip_default_state` | 69 | 4.2s |  |
| 116 | `movieclip_line_gradient_style` | 0 | 4.5s |  |
| 117 | `movieclip_name_from_timeline` | 13 | 4.1s |  |
| 118 | `movieclip_prototype_extension` | 5 | 4.1s |  |
| 119 | `nested_textfields_in_buttons` | 0 | 4.2s |  |
| 120 | `netstream_play_flv_screen` | 0 | 17.1s |  |
| 121 | `new_method_wrap` | 4 | 4.1s |  |
| 122 | `new_object_wrap` | 4 | 4.1s |  |
| 123 | `o` | 3 | 4.1s |  |
| 124 | `object_constructor` | 33 | 4.1s |  |
| 125 | `primitive_instanceof` | 37 | 4.1s |  |
| 126 | `prototype_delete` | 12 | 4.1s |  |
| 127 | `recursive_prototypes` | 0 | 4.1s |  |
| 128 | `sandbox_type_local_file` | 1 | 4.1s |  |
| 129 | `set_variable_scope` | 58 | 4.1s |  |
| 130 | `single_frame` | 1 | 4.1s |  |
| 131 | `sound_start_load` | 0 | 4.1s |  |
| 132 | `stage_object_properties_get_var` | 5 | 4.1s |  |
| 133 | `strictequals_swf6` | 902 | 5.6s |  |
| 134 | `strictly_equals` | 7 | 4.2s |  |
| 135 | `string_methods_swfv5` | 275 | 4.7s |  |
| 136 | `string_paths_keyevents` | 0 | 4.2s |  |
| 137 | `string_paths_timer` | 0 | 4.2s |  |
| 138 | `swf4_actions_bool` | 96 | 4.1s |  |
| 139 | `swf4_bool` | 4 | 4.0s |  |
| 140 | `swf5_encoding` | 3 | 4.1s |  |
| 141 | `tab_ordering_properties_tab_index_edge_case` | 4 | 4.1s |  |
| 142 | `text_format` | 1146 | 4.4s |  |
| 143 | `text_format_display` | 21 | 4.2s |  |
| 144 | `text_format_font_max_length` | 2 | 4.2s |  |
| 145 | `text_format_rounding_swf7` | 840 | 4.3s |  |
| 146 | `text_format_rounding_swf8` | 840 | 4.3s |  |
| 147 | `textfield_background_color` | 11 | 4.2s |  |
| 148 | `textfield_border_color` | 11 | 4.1s |  |
| 149 | `textfield_maxchars` | 3 | 4.2s |  |
| 150 | `textfield_properties` | 44 | 4.2s |  |
| 151 | `textfield_text` | 7 | 4.2s |  |
| 152 | `textfield_variable` | 81 | 4.4s |  |
| 153 | `this_swf7` | 41 | 4.1s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 154 | `timeline_function_def` | 7 | 4.2s |  |
| 155 | `try_finally_simple` | 16 | 4.2s |  |
| 156 | `typeof` | 22 | 4.3s |  |
| 157 | `typeof_globals` | 7 | 4.0s |  |
| 158 | `uncaught_exception` | 1 | 4.1s |  |
| 159 | `uncaught_exception_bubbled` | 1 | 4.2s |  |
| 160 | `undefined_to_string_swf6` | 4 | 4.1s |  |
| 161 | `unescape` | 43 | 4.2s |  |
| 162 | `use_hand_cursor` | 8 | 4.1s |  |
| 163 | `variable_args` | 5 | 4.2s |  |
| 164 | `waitforframe` | 7 | 4.2s |  |
| 165 | `waitforframe2` | 16 | 4.2s |  |
| 166 | `with_return` | 2 | 4.2s |  |
| 167 | `xml` | 15 | 4.2s |  |
| 168 | `xml_append_child` | 28 | 4.2s |  |
| 169 | `xml_append_child_with_parent` | 20 | 4.1s |  |
| 170 | `xml_attributes_read` | 4 | 4.1s |  |
| 171 | `xml_cdata` | 11 | 4.2s |  |
| 172 | `xml_clone_expandos` | 19 | 4.2s |  |
| 173 | `xml_first_last_child` | 8 | 4.1s |  |
| 174 | `xml_has_child_nodes` | 3 | 4.2s |  |
| 175 | `xml_idmap` | 21 | 4.3s |  |
| 176 | `xml_ignore_comments` | 21 | 4.2s |  |
| 177 | `xml_ignore_white` | 34 | 4.3s |  |
| 178 | `xml_insert_before` | 20 | 4.1s |  |
| 179 | `xml_inspect_createmethods` | 15 | 4.2s |  |
| 180 | `xml_inspect_doctype` | 7 | 4.3s |  |
| 181 | `xml_inspect_parsexml` | 62 | 4.3s |  |
| 182 | `xml_inspect_xmldecl` | 7 | 4.3s |  |
| 183 | `xml_namespaces` | 203 | 4.2s |  |
| 184 | `xml_parent_and_child` | 5 | 4.2s |  |
| 185 | `xml_remove_node` | 22 | 4.1s |  |
| 186 | `xml_siblings` | 10 | 4.1s |  |
| 187 | `xml_to_string_comment` | 1 | 4.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**104 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `string_methods` | 99.3% | 283 | 285 | 2 |  |
| 2 | `textfield_props_swf6` | 99.0% | 208 | 210 | 2 |  |
| 3 | `textfield_props_swf7` | 99.0% | 208 | 210 | 2 |  |
| 4 | `textfield_props_swf8` | 99.0% | 208 | 210 | 2 |  |
| 5 | `globals_swf5` | 95.4% | 290 | 304 | 14 |  |
| 6 | `string_coercion` | 94.9% | 111 | 117 | 6 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 7 | `edittext_width_height` | 94.2% | 97 | 103 | 6 |  |
| 8 | `get_variable_in_scope` | 93.1% | 27 | 29 | 2 |  |
| 9 | `swf7_case_sensitive` | 90.9% | 40 | 44 | 4 |  |
| 10 | `object_function` | 90.6% | 29 | 32 | 3 |  |
| 11 | `object_string_coerce_swf5` | 90.3% | 56 | 62 | 6 |  |
| 12 | `divide_swf4` | 88.8% | 95 | 107 | 12 |  |
| 13 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 |  |
| 14 | `swf4_function_calls` | 85.7% | 6 | 7 | 1 |  |
| 15 | `xml_to_string` | 84.6% | 11 | 13 | 2 |  |
| 16 | `object_prototypes` | 83.8% | 62 | 74 | 12 |  |
| 17 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 18 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 |  |
| 19 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 20 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 21 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 22 | `movieclip_depth_methods` | 77.6% | 76 | 98 | 22 |  |
| 23 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 24 | `as2_oop` | 76.9% | 10 | 13 | 3 |  |
| 25 | `define_function2_preload` | 76.9% | 10 | 13 | 3 |  |
| 26 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 |  |
| 27 | `xml_child_nodes_edge_cases` | 75.0% | 3 | 4 | 1 |  |
| 28 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 29 | `transform` | 72.9% | 51 | 70 | 19 |  |
| 30 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 31 | `extends_native_type` | 72.7% | 8 | 11 | 3 |  |
| 32 | `array_sort` | 72.0% | 116 | 161 | 45 |  |
| 33 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 34 | `stage_object_properties_swf6` | 71.9% | 166 | 231 | 65 |  |
| 35 | `stage_object_properties` | 71.8% | 173 | 241 | 68 |  |
| 36 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 |  |
| 37 | `point` | 70.9% | 124 | 175 | 51 |  |
| 38 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 39 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 40 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 41 | `as_set_prop_flags` | 68.4% | 54 | 79 | 25 |  |
| 42 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 43 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 44 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 |  |
| 45 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 46 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 47 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 48 | `issue_768` | 66.7% | 2 | 3 | 1 | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 49 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 50 | `sound_props_swf5` | 66.7% | 46 | 69 | 23 |  |
| 51 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 52 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 53 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 54 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 |  |
| 55 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 56 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 57 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 58 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 59 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 |  |
| 60 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 |  |
| 61 | `edittext_autosize` | 62.0% | 44 | 71 | 27 |  |
| 62 | `object_string_coerce_swf6` | 61.8% | 42 | 68 | 26 |  |
| 63 | `with` | 61.2% | 30 | 49 | 19 |  |
| 64 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 65 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 66 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 67 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 68 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 69 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 70 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 71 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 72 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 73 | `parse_float` | 58.1% | 43 | 74 | 31 |  |
| 74 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 75 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 76 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 77 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 |  |
| 78 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 79 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 80 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 81 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 82 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 |  |
| 83 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 |  |
| 84 | `clone_sprite_types` | 54.2% | 13 | 24 | 11 |  |
| 85 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 |  |
| 86 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 87 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 88 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 89 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 90 | `define_function2_preload_order` | 50.0% | 2 | 4 | 2 |  |
| 91 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 |  |
| 92 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 93 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 94 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 95 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 96 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 97 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 98 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 99 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 100 | `string_paths_basic` | 50.0% | 2 | 4 | 2 |  |
| 101 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 |  |
| 102 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 103 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 104 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**49 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `array_sort_random` | 6.3s |  |
| 2 | `asnew` | 6.3s |  |
| 3 | `bitmap_data_copypixels` | 6.8s |  |
| 4 | `bitmap_data_perlinnoise` | 6.8s |  |
| 5 | `bitmap_data_pixeldissolve` | 7.0s |  |
| 6 | `bitmap_data_pixeldissolve_image` | 6.7s |  |
| 7 | `boxed_primitives` | 6.2s |  |
| 8 | `coerce_to_primitive_resolve` | 6.2s |  |
| 9 | `drag_over_from_outside` | 6.1s |  |
| 10 | `drag_over_without_startdrag` | 6.2s |  |
| 11 | `enumerate` | 6.1s |  |
| 12 | `file_reference_browse_cancel` | 6.3s |  |
| 13 | `function_base_clip_removed` | 6.3s |  |
| 14 | `function_suppress_and_preload` | 6.4s |  |
| 15 | `global_swf6_7_8` | 6.4s |  |
| 16 | `goto_methods` | 6.4s |  |
| 17 | `hittest_lockroot` | 6.2s |  |
| 18 | `hittest_winding_rule` | 6.1s |  |
| 19 | `init_object_order` | 6.2s |  |
| 20 | `instanceof_coercions` | 6.3s |  |
| 21 | `interface_implements_op` | 6.5s |  |
| 22 | `issue_3169` | 6.2s |  |
| 23 | `issue_9327` | 6.1s |  |
| 24 | `loadmovie_fail` | 6.1s |  |
| 25 | `loadmovienum_cross_version_prototype` | 5.4s |  |
| 26 | `math_swf6` | 5.7s |  |
| 27 | `math_swf7` | 5.7s |  |
| 28 | `math_swf8` | 5.8s |  |
| 29 | `mcl_loadclip_properties` | 5.5s |  |
| 30 | `mcl_loadclip_replace_root` | 5.5s |  |
| 31 | `mouse_hover_events_while_dragging` | 5.5s |  |
| 32 | `movieclip_blend_mode_property` | 5.5s |  |
| 33 | `native_double_construct` | 6.2s |  |
| 34 | `native_subclasses` | 6.4s |  |
| 35 | `object_resolve` | 6.2s |  |
| 36 | `register_and_init_order` | 6.5s |  |
| 37 | `register_class` | 6.4s |  |
| 38 | `register_class_return_value` | 6.3s |  |
| 39 | `register_class_with_sound` | 6.2s |  |
| 40 | `string_methods_negative_args` | 6.2s |  |
| 41 | `super_edge_cases` | 6.3s |  |
| 42 | `watch_virtual_property_proto` | 6.2s |  |
| 43 | `xml_reparenting` | 6.2s |  |
| 44 | `xml_socket` | 6.2s |  |
| 45 | `xml_socket_close_in_handler` | 6.3s |  |
| 46 | `xml_socket_on_data` | 6.2s |  |
| 47 | `xml_socket_segmented` | 6.2s |  |
| 48 | `xml_unescaping` | 6.2s |  |
| 49 | `xmlnode_proto` | 6.3s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**2 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 14.2s |  |
| 2 | `try_catch_finally` | runtime timeout (>10s) | 14.4s |  |

## All Output Mismatches

**381 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `string_methods` | 99.3% | 283/285 | 285 | 285 |  |
| 2 | `textfield_props_swf6` | 99.0% | 208/210 | 210 | 210 |  |
| 3 | `textfield_props_swf7` | 99.0% | 208/210 | 210 | 210 |  |
| 4 | `textfield_props_swf8` | 99.0% | 208/210 | 210 | 210 |  |
| 5 | `globals_swf5` | 95.4% | 290/304 | 304 | 304 |  |
| 6 | `string_coercion` | 94.9% | 111/117 | 117 | 117 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 7 | `edittext_width_height` | 94.2% | 97/103 | 103 | 103 |  |
| 8 | `get_variable_in_scope` | 93.1% | 27/29 | 29 | 29 |  |
| 9 | `swf7_case_sensitive` | 90.9% | 40/44 | 44 | 44 |  |
| 10 | `object_function` | 90.6% | 29/32 | 32 | 32 |  |
| 11 | `object_string_coerce_swf5` | 90.3% | 56/62 | 62 | 62 |  |
| 12 | `divide_swf4` | 88.8% | 95/107 | 107 | 107 |  |
| 13 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 |  |
| 14 | `swf4_function_calls` | 85.7% | 6/7 | 7 | 7 |  |
| 15 | `xml_to_string` | 84.6% | 11/13 | 13 | 13 |  |
| 16 | `object_prototypes` | 83.8% | 62/74 | 73 | 74 |  |
| 17 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 18 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 |  |
| 19 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 20 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 21 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 22 | `movieclip_depth_methods` | 77.6% | 76/98 | 98 | 98 |  |
| 23 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 24 | `as2_oop` | 76.9% | 10/13 | 13 | 13 |  |
| 25 | `define_function2_preload` | 76.9% | 10/13 | 13 | 13 |  |
| 26 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 |  |
| 27 | `xml_child_nodes_edge_cases` | 75.0% | 3/4 | 4 | 4 |  |
| 28 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 29 | `transform` | 72.9% | 51/70 | 70 | 70 |  |
| 30 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 31 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 |  |
| 32 | `array_sort` | 72.0% | 116/161 | 161 | 161 |  |
| 33 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 34 | `stage_object_properties_swf6` | 71.9% | 166/231 | 231 | 231 |  |
| 35 | `stage_object_properties` | 71.8% | 173/241 | 241 | 241 |  |
| 36 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 |  |
| 37 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 38 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 39 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 40 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 41 | `as_set_prop_flags` | 68.4% | 54/79 | 76 | 79 |  |
| 42 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 43 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 44 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 |  |
| 45 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 46 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 47 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 48 | `issue_768` | 66.7% | 2/3 | 3 | 3 | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 49 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 50 | `sound_props_swf5` | 66.7% | 46/69 | 69 | 68 |  |
| 51 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 52 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 53 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 54 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 |  |
| 55 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 56 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 57 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 58 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 59 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 |  |
| 60 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 |  |
| 61 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 |  |
| 62 | `object_string_coerce_swf6` | 61.8% | 42/68 | 64 | 68 |  |
| 63 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 64 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 65 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 66 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 67 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 68 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 69 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 70 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 71 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 72 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 73 | `parse_float` | 58.1% | 43/74 | 74 | 74 |  |
| 74 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 75 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 76 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 77 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 |  |
| 78 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 79 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 80 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 81 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 82 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 |  |
| 83 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 |  |
| 84 | `clone_sprite_types` | 54.2% | 13/24 | 24 | 24 |  |
| 85 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 |  |
| 86 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 87 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 88 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 89 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 90 | `define_function2_preload_order` | 50.0% | 2/4 | 4 | 4 |  |
| 91 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 |  |
| 92 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 93 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 94 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 95 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 96 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 97 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 98 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 99 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 100 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 |  |
| 101 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 |  |
| 102 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 103 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 104 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 105 | `edittext_html_swf6` | 49.1% | 2640/5377 | 5377 | 5377 |  |
| 106 | `sound_props_swf6` | 46.4% | 32/69 | 69 | 68 |  |
| 107 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 108 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 |  |
| 109 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 |  |
| 110 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 111 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 112 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 113 | `edittext_html_swf7` | 42.2% | 2268/5377 | 5377 | 5377 |  |
| 114 | `edittext_html_swf8` | 39.4% | 2118/5377 | 5377 | 5377 |  |
| 115 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 116 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 117 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 118 | `array_call_method` | 33.3% | 3/9 | 6 | 9 |  |
| 119 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 120 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 121 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 122 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 123 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 124 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 125 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 126 | `string_paths_other` | 30.6% | 11/36 | 28 | 36 |  |
| 127 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 128 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 129 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 130 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 |  |
| 131 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 132 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 133 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 134 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 135 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 136 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 137 | `edittext_stylesheet` | 24.3% | 79/325 | 325 | 325 |  |
| 138 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 139 | `textsnapshot_props_swf5` | 23.2% | 13/56 | 39 | 56 |  |
| 140 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 141 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 142 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 143 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 |  |
| 144 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 145 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 146 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 147 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 148 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 149 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 150 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 151 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 152 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 153 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 154 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 155 | `printjob_props_swf7` | 15.6% | 7/45 | 36 | 45 |  |
| 156 | `unload` | 15.4% | 8/52 | 48 | 52 |  |
| 157 | `watch` | 15.4% | 18/117 | 101 | 117 |  |
| 158 | `color_transform` | 14.6% | 7/48 | 38 | 48 |  |
| 159 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 160 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 161 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 162 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 163 | `path_string` | 14.0% | 45/322 | 299 | 322 |  |
| 164 | `focusrect_property_swf7` | 13.7% | 169/1237 | 276 | 1237 |  |
| 165 | `focusrect_property_swf6` | 13.6% | 168/1237 | 276 | 1237 |  |
| 166 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 167 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 168 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 169 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 170 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 171 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 172 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 173 | `textsnapshot_props_swf6` | 12.5% | 7/56 | 39 | 56 |  |
| 174 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 175 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 176 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 177 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 178 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 179 | `printjob_props_swf5` | 11.1% | 5/45 | 36 | 45 |  |
| 180 | `printjob_props_swf6` | 11.1% | 5/45 | 36 | 45 |  |
| 181 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 182 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 183 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 184 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 185 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 186 | `extends_chain` | 9.0% | 12/134 | 122 | 134 |  |
| 187 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 188 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 189 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 190 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 191 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 192 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 193 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 194 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 195 | `focus_visibility_change` | 6.7% | 3/45 | 27 | 45 |  |
| 196 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 197 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 198 | `as2_super_and_this_v6` | 6.2% | 6/97 | 17 | 97 |  |
| 199 | `focus_remove` | 6.1% | 2/33 | 15 | 33 |  |
| 200 | `bitmap_data` | 5.8% | 68/1174 | 1174 | 1126 |  |
| 201 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 202 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 203 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 204 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 205 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 206 | `context_menu` | 5.1% | 2/39 | 14 | 39 |  |
| 207 | `context_menu_item` | 4.9% | 2/41 | 10 | 41 |  |
| 208 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 209 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 210 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 211 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 212 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 213 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 |  |
| 214 | `focusrect_property_swf5` | 3.5% | 43/1237 | 276 | 1237 |  |
| 215 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 216 | `as2_super_and_this_v8` | 2.4% | 2/85 | 9 | 85 |  |
| 217 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 218 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 219 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 220 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 221 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 222 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 223 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 224 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 225 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 226 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 227 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 228 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 229 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 230 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 231 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 232 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 233 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 234 | `global_proto_decls` | 0.2% | 9/4497 | 249 | 4497 |  |
| 235 | `global_instance_decls` | 0.1% | 1/758 | 141 | 758 |  |
| 236 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 237 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 238 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 239 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 240 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 241 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 242 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 243 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 244 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 245 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 246 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 247 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 248 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 249 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 250 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 251 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 252 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 253 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 254 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 255 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 256 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 257 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 258 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 259 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 260 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 261 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 |  |
| 262 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 263 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 264 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 265 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 266 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 267 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 268 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 269 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 270 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 271 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 272 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 273 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 274 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 275 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 276 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 277 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 278 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 279 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 280 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 281 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 282 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 283 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 284 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 285 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 286 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 287 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 288 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 289 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 290 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 291 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 292 | `global_proto_decls_delete` | 0.0% | 0/4158 | 114 | 4158 |  |
| 293 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 294 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 295 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 296 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 297 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 298 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 299 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 300 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 301 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 302 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 303 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 304 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 305 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 306 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 307 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 308 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 309 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 310 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 311 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 312 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 313 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 314 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 315 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 316 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 317 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 318 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 319 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 320 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 321 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 322 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 323 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 324 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 325 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 326 | `native_objects_swf6` | 0.0% | 0/186 | 186 | 84 |  |
| 327 | `native_objects_swf7` | 0.0% | 0/186 | 186 | 84 |  |
| 328 | `native_objects_swf8` | 0.0% | 0/188 | 188 | 84 |  |
| 329 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 330 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 331 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 332 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 333 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 334 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 335 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 336 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 337 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 338 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 339 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 340 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 341 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 342 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 343 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 344 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 345 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 346 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 347 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 348 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 349 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 350 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 351 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 352 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 353 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 354 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 355 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 356 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 357 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 358 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 359 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 360 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 361 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 362 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 363 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 364 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 365 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 366 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 367 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 368 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 369 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 370 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 371 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 372 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 373 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 374 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 375 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 376 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 377 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 378 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 379 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 380 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 381 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
