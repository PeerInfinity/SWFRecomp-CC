# Ruffle Test Results (Filtered)

**Date**: 2026-02-15 19:40 UTC

**Git SHA**: `3048065573`

**Run Duration**: 46m 59s

**Filtered**: 137 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 482 |
| Passing | **185** (38.4%) |
| Failing | 297 |
| Total expected lines | 74871 |
| Matching lines | 41020 (54.8%) |
| Mismatched lines | 33851 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 260 | 87.5% |
| Segfault | 35 | 11.8% |
| Timeout | 2 | 0.7% |

## Passing Tests

**185 tests passing**

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
| 48 | `equals` | 32 | 4.2s |  |
| 49 | `equals2_swf5` | 926 | 5.8s |  |
| 50 | `equals2_swf6` | 926 | 5.7s |  |
| 51 | `equals2_swf7` | 926 | 5.7s |  |
| 52 | `equals_swf4` | 665 | 4.5s |  |
| 53 | `equals_swf4_alt` | 32 | 4.1s |  |
| 54 | `equals_swf5` | 32 | 4.2s |  |
| 55 | `error` | 58 | 4.1s |  |
| 56 | `escape` | 14 | 4.1s |  |
| 57 | `execution_order1` | 5 | 4.2s |  |
| 58 | `execution_order2` | 7 | 4.2s |  |
| 59 | `execution_order3` | 4 | 4.1s |  |
| 60 | `focusrect_mouse_swf8` | 0 | 4.2s |  |
| 61 | `focusrect_mouse_swf9` | 0 | 4.2s |  |
| 62 | `focusrect_swf5` | 6 | 4.3s |  |
| 63 | `getproperty` | 28 | 4.2s |  |
| 64 | `getproperty_swf4` | 28 | 4.1s |  |
| 65 | `getproperty_swf5` | 28 | 4.1s |  |
| 66 | `global_array` | 3 | 4.2s |  |
| 67 | `global_is_bare` | 7 | 4.2s |  |
| 68 | `globals_swf6` | 304 | 4.4s |  |
| 69 | `globals_swf7` | 304 | 4.5s |  |
| 70 | `globals_swf8` | 304 | 4.6s |  |
| 71 | `goto_advance1` | 6 | 4.3s |  |
| 72 | `goto_advance2` | 2 | 4.2s |  |
| 73 | `goto_both_ways1` | 3 | 4.3s |  |
| 74 | `goto_both_ways2` | 3 | 4.2s |  |
| 75 | `goto_execution_order` | 2 | 4.1s |  |
| 76 | `goto_execution_order2` | 2 | 4.1s |  |
| 77 | `goto_frame_number` | 3 | 4.2s |  |
| 78 | `goto_rewind1` | 1 | 4.2s |  |
| 79 | `goto_rewind2` | 3 | 4.2s |  |
| 80 | `goto_rewind3` | 2 | 4.1s |  |
| 81 | `greater_swf6` | 1175 | 6.1s |  |
| 82 | `greater_swf7` | 1175 | 6.1s |  |
| 83 | `greaterthan_swf5` | 1 | 4.1s |  |
| 84 | `greaterthan_swf8` | 1 | 4.1s |  |
| 85 | `has_own_property` | 32 | 4.1s |  |
| 86 | `infinite_recursion_function` | 4 | 4.2s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 87 | `infinite_recursion_function_in_setter` | 131 | 4.2s |  |
| 88 | `infinite_recursion_virtual_property` | 67 | 4.1s |  |
| 89 | `init_array_invalid` | 4 | 4.1s |  |
| 90 | `init_object_invalid` | 4 | 4.1s |  |
| 91 | `is_finite` | 49 | 4.2s |  |
| 92 | `is_finite_swf6` | 49 | 4.1s |  |
| 93 | `issue_1086` | 1 | 4.0s |  |
| 94 | `issue_1671` | 0 | 4.1s |  |
| 95 | `issue_2166` | 9 | 4.1s |  |
| 96 | `issue_3446` | 1 | 4.2s |  |
| 97 | `issue_4377` | 2 | 4.1s |  |
| 98 | `issue_710` | 4 | 4.0s |  |
| 99 | `lessthan` | 41 | 4.1s |  |
| 100 | `lessthan2_swf5` | 1226 | 6.3s |  |
| 101 | `lessthan2_swf6` | 1226 | 6.3s |  |
| 102 | `lessthan2_swf7` | 1226 | 6.3s |  |
| 103 | `lessthan_swf4` | 902 | 4.8s |  |
| 104 | `lessthan_swf4_alt` | 41 | 4.1s |  |
| 105 | `lessthan_swf5` | 41 | 4.1s |  |
| 106 | `logical_ops_swf4` | 90 | 3.9s |  |
| 107 | `logical_ops_swf8` | 108 | 4.1s |  |
| 108 | `looping` | 6 | 4.0s |  |
| 109 | `mask_reapply` | 0 | 4.0s |  |
| 110 | `mask_with_drawing` | 0 | 4.0s |  |
| 111 | `math_min_max` | 101 | 4.1s |  |
| 112 | `movieclip_begin_gradient_fill` | 0 | 4.5s |  |
| 113 | `movieclip_default_state` | 69 | 4.2s |  |
| 114 | `movieclip_line_gradient_style` | 0 | 4.5s |  |
| 115 | `movieclip_name_from_timeline` | 13 | 4.1s |  |
| 116 | `movieclip_prototype_extension` | 5 | 4.1s |  |
| 117 | `nested_textfields_in_buttons` | 0 | 4.2s |  |
| 118 | `netstream_play_flv_screen` | 0 | 17.1s |  |
| 119 | `new_method_wrap` | 4 | 4.1s |  |
| 120 | `new_object_wrap` | 4 | 4.1s |  |
| 121 | `o` | 3 | 4.1s |  |
| 122 | `object_constructor` | 33 | 4.1s |  |
| 123 | `primitive_instanceof` | 37 | 4.1s |  |
| 124 | `prototype_delete` | 12 | 4.1s |  |
| 125 | `recursive_prototypes` | 0 | 4.1s |  |
| 126 | `sandbox_type_local_file` | 1 | 4.1s |  |
| 127 | `set_variable_scope` | 58 | 4.1s |  |
| 128 | `single_frame` | 1 | 4.1s |  |
| 129 | `sound_start_load` | 0 | 4.1s |  |
| 130 | `stage_object_properties_get_var` | 5 | 4.1s |  |
| 131 | `strictequals_swf6` | 902 | 5.6s |  |
| 132 | `strictly_equals` | 7 | 4.2s |  |
| 133 | `string_methods_swfv5` | 275 | 4.7s |  |
| 134 | `string_paths_keyevents` | 0 | 4.2s |  |
| 135 | `string_paths_timer` | 0 | 4.2s |  |
| 136 | `swf4_actions_bool` | 96 | 4.1s |  |
| 137 | `swf4_bool` | 4 | 4.0s |  |
| 138 | `swf5_encoding` | 3 | 4.1s |  |
| 139 | `tab_ordering_properties_tab_index_edge_case` | 4 | 4.1s |  |
| 140 | `text_format` | 1146 | 4.4s |  |
| 141 | `text_format_display` | 21 | 4.2s |  |
| 142 | `text_format_font_max_length` | 2 | 4.2s |  |
| 143 | `text_format_rounding_swf7` | 840 | 4.3s |  |
| 144 | `text_format_rounding_swf8` | 840 | 4.3s |  |
| 145 | `textfield_background_color` | 11 | 4.2s |  |
| 146 | `textfield_border_color` | 11 | 4.1s |  |
| 147 | `textfield_maxchars` | 3 | 4.2s |  |
| 148 | `textfield_properties` | 44 | 4.2s |  |
| 149 | `textfield_text` | 7 | 4.2s |  |
| 150 | `textfield_variable` | 81 | 4.4s |  |
| 151 | `this_swf7` | 41 | 4.1s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 152 | `timeline_function_def` | 7 | 4.2s |  |
| 153 | `try_finally_simple` | 16 | 4.2s |  |
| 154 | `typeof` | 22 | 4.3s |  |
| 155 | `typeof_globals` | 7 | 4.0s |  |
| 156 | `uncaught_exception` | 1 | 4.1s |  |
| 157 | `uncaught_exception_bubbled` | 1 | 4.2s |  |
| 158 | `undefined_to_string_swf6` | 4 | 4.1s |  |
| 159 | `unescape` | 43 | 4.2s |  |
| 160 | `use_hand_cursor` | 8 | 4.1s |  |
| 161 | `variable_args` | 5 | 4.2s |  |
| 162 | `waitforframe` | 7 | 4.2s |  |
| 163 | `waitforframe2` | 16 | 4.2s |  |
| 164 | `with_return` | 2 | 4.2s |  |
| 165 | `xml` | 15 | 4.2s |  |
| 166 | `xml_append_child` | 28 | 4.2s |  |
| 167 | `xml_append_child_with_parent` | 20 | 4.1s |  |
| 168 | `xml_attributes_read` | 4 | 4.1s |  |
| 169 | `xml_cdata` | 11 | 4.2s |  |
| 170 | `xml_clone_expandos` | 19 | 4.2s |  |
| 171 | `xml_first_last_child` | 8 | 4.1s |  |
| 172 | `xml_has_child_nodes` | 3 | 4.2s |  |
| 173 | `xml_idmap` | 21 | 4.3s |  |
| 174 | `xml_ignore_comments` | 21 | 4.2s |  |
| 175 | `xml_ignore_white` | 34 | 4.3s |  |
| 176 | `xml_insert_before` | 20 | 4.1s |  |
| 177 | `xml_inspect_createmethods` | 15 | 4.2s |  |
| 178 | `xml_inspect_doctype` | 7 | 4.3s |  |
| 179 | `xml_inspect_parsexml` | 62 | 4.3s |  |
| 180 | `xml_inspect_xmldecl` | 7 | 4.3s |  |
| 181 | `xml_namespaces` | 203 | 4.2s |  |
| 182 | `xml_parent_and_child` | 5 | 4.2s |  |
| 183 | `xml_remove_node` | 22 | 4.1s |  |
| 184 | `xml_siblings` | 10 | 4.1s |  |
| 185 | `xml_to_string_comment` | 1 | 4.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**93 tests** within reach

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
| 52 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 53 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 |  |
| 54 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 55 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 56 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 57 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 58 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 |  |
| 59 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 |  |
| 60 | `edittext_autosize` | 62.0% | 44 | 71 | 27 |  |
| 61 | `object_string_coerce_swf6` | 61.8% | 42 | 68 | 26 |  |
| 62 | `with` | 61.2% | 30 | 49 | 19 |  |
| 63 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 64 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 65 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 66 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 67 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 68 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 69 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 70 | `parse_float` | 58.1% | 43 | 74 | 31 |  |
| 71 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 72 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 73 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 |  |
| 74 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 75 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 76 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 77 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 78 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 |  |
| 79 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 |  |
| 80 | `clone_sprite_types` | 54.2% | 13 | 24 | 11 |  |
| 81 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 |  |
| 82 | `define_function2_preload_order` | 50.0% | 2 | 4 | 2 |  |
| 83 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 |  |
| 84 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 85 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 86 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 87 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 88 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 89 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 90 | `string_paths_basic` | 50.0% | 2 | 4 | 2 |  |
| 91 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 |  |
| 92 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 93 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**35 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `array_sort_random` | 6.3s |  |
| 2 | `asnew` | 6.3s |  |
| 3 | `bitmap_data_perlinnoise` | 6.8s |  |
| 4 | `bitmap_data_pixeldissolve_image` | 6.7s |  |
| 5 | `boxed_primitives` | 6.2s |  |
| 6 | `coerce_to_primitive_resolve` | 6.2s |  |
| 7 | `enumerate` | 6.1s |  |
| 8 | `function_base_clip_removed` | 6.3s |  |
| 9 | `function_suppress_and_preload` | 6.4s |  |
| 10 | `global_swf6_7_8` | 6.4s |  |
| 11 | `goto_methods` | 6.4s |  |
| 12 | `hittest_lockroot` | 6.2s |  |
| 13 | `hittest_winding_rule` | 6.1s |  |
| 14 | `init_object_order` | 6.2s |  |
| 15 | `instanceof_coercions` | 6.3s |  |
| 16 | `interface_implements_op` | 6.5s |  |
| 17 | `issue_3169` | 6.2s |  |
| 18 | `issue_9327` | 6.1s |  |
| 19 | `math_swf6` | 5.7s |  |
| 20 | `math_swf7` | 5.7s |  |
| 21 | `math_swf8` | 5.8s |  |
| 22 | `movieclip_blend_mode_property` | 5.5s |  |
| 23 | `native_double_construct` | 6.2s |  |
| 24 | `native_subclasses` | 6.4s |  |
| 25 | `object_resolve` | 6.2s |  |
| 26 | `register_and_init_order` | 6.5s |  |
| 27 | `register_class` | 6.4s |  |
| 28 | `register_class_return_value` | 6.3s |  |
| 29 | `register_class_with_sound` | 6.2s |  |
| 30 | `string_methods_negative_args` | 6.2s |  |
| 31 | `super_edge_cases` | 6.3s |  |
| 32 | `watch_virtual_property_proto` | 6.2s |  |
| 33 | `xml_reparenting` | 6.2s |  |
| 34 | `xml_unescaping` | 6.2s |  |
| 35 | `xmlnode_proto` | 6.3s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**2 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 14.2s |  |
| 2 | `try_catch_finally` | runtime timeout (>10s) | 14.4s |  |

## All Output Mismatches

**260 tests** with output mismatch, sorted by match rate (best first)

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
| 52 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 53 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 |  |
| 54 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 55 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 56 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 57 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 58 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 |  |
| 59 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 |  |
| 60 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 |  |
| 61 | `object_string_coerce_swf6` | 61.8% | 42/68 | 64 | 68 |  |
| 62 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 63 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 64 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 65 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 66 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 67 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 68 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 69 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 70 | `parse_float` | 58.1% | 43/74 | 74 | 74 |  |
| 71 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 72 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 73 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 |  |
| 74 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 75 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 76 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 77 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 78 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 |  |
| 79 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 |  |
| 80 | `clone_sprite_types` | 54.2% | 13/24 | 24 | 24 |  |
| 81 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 |  |
| 82 | `define_function2_preload_order` | 50.0% | 2/4 | 4 | 4 |  |
| 83 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 |  |
| 84 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 85 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 86 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 87 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 88 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 89 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 90 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 |  |
| 91 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 |  |
| 92 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 93 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 94 | `edittext_html_swf6` | 49.1% | 2640/5377 | 5377 | 5377 |  |
| 95 | `sound_props_swf6` | 46.4% | 32/69 | 69 | 68 |  |
| 96 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 97 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 |  |
| 98 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 |  |
| 99 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 100 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 101 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 102 | `edittext_html_swf7` | 42.2% | 2268/5377 | 5377 | 5377 |  |
| 103 | `edittext_html_swf8` | 39.4% | 2118/5377 | 5377 | 5377 |  |
| 104 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 105 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 106 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 107 | `array_call_method` | 33.3% | 3/9 | 6 | 9 |  |
| 108 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 109 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 110 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 111 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 112 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 113 | `string_paths_other` | 30.6% | 11/36 | 28 | 36 |  |
| 114 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 115 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 116 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 |  |
| 117 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 118 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 119 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 120 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 121 | `edittext_stylesheet` | 24.3% | 79/325 | 325 | 325 |  |
| 122 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 123 | `textsnapshot_props_swf5` | 23.2% | 13/56 | 39 | 56 |  |
| 124 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 125 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 126 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 127 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 |  |
| 128 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 129 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 130 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 131 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 132 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 133 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 134 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 135 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 136 | `printjob_props_swf7` | 15.6% | 7/45 | 36 | 45 |  |
| 137 | `unload` | 15.4% | 8/52 | 48 | 52 |  |
| 138 | `watch` | 15.4% | 18/117 | 101 | 117 |  |
| 139 | `color_transform` | 14.6% | 7/48 | 38 | 48 |  |
| 140 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 141 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 142 | `path_string` | 14.0% | 45/322 | 299 | 322 |  |
| 143 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 144 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 145 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 146 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 147 | `textsnapshot_props_swf6` | 12.5% | 7/56 | 39 | 56 |  |
| 148 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 149 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 150 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 151 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 152 | `printjob_props_swf5` | 11.1% | 5/45 | 36 | 45 |  |
| 153 | `printjob_props_swf6` | 11.1% | 5/45 | 36 | 45 |  |
| 154 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 155 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 156 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 157 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 158 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 159 | `extends_chain` | 9.0% | 12/134 | 122 | 134 |  |
| 160 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 161 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 162 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 163 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 164 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 165 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 166 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 167 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 168 | `as2_super_and_this_v6` | 6.2% | 6/97 | 17 | 97 |  |
| 169 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 170 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 171 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 172 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 173 | `context_menu` | 5.1% | 2/39 | 14 | 39 |  |
| 174 | `context_menu_item` | 4.9% | 2/41 | 10 | 41 |  |
| 175 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 176 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 177 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 |  |
| 178 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 179 | `as2_super_and_this_v8` | 2.4% | 2/85 | 9 | 85 |  |
| 180 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 181 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 182 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 183 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 184 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 185 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 186 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 187 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 188 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 189 | `global_proto_decls` | 0.2% | 9/4497 | 249 | 4497 |  |
| 190 | `global_instance_decls` | 0.1% | 1/758 | 141 | 758 |  |
| 191 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 192 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 193 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 194 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 195 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 196 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 197 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 198 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 199 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 200 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 201 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 202 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 203 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 204 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 205 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 206 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 |  |
| 207 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 208 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 209 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 210 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 211 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 212 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 213 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 214 | `global_proto_decls_delete` | 0.0% | 0/4158 | 114 | 4158 |  |
| 215 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 216 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 217 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 218 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 219 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 220 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 221 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 222 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 223 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 224 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 225 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 226 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 227 | `native_objects_swf6` | 0.0% | 0/186 | 186 | 84 |  |
| 228 | `native_objects_swf7` | 0.0% | 0/186 | 186 | 84 |  |
| 229 | `native_objects_swf8` | 0.0% | 0/188 | 188 | 84 |  |
| 230 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 231 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 232 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 233 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 234 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 235 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 236 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 237 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 238 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 239 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 240 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 241 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 242 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 243 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 244 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 245 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 246 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 247 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 248 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 249 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 250 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 251 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 252 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 253 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 254 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 255 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 256 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 257 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 258 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 259 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 260 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
