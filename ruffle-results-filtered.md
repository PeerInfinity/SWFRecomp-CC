# Ruffle Test Results (Filtered)

**Date**: 2026-02-15 01:31 UTC

**Git SHA**: `711e25ad1e`

**Run Duration**: 44m 25s

**Filtered**: 137 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 482 |
| Passing | **194** (40.2%) |
| Failing | 288 |
| Total expected lines | 77711 |
| Matching lines | 37922 (48.8%) |
| Mismatched lines | 39789 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 280 | 97.2% |
| Timeout | 4 | 1.4% |
| Segfault | 4 | 1.4% |

## Passing Tests

**194 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 3.9s |  |
| 2 | `action_to_integer` | 28 | 3.7s |  |
| 3 | `add` | 28 | 3.7s |  |
| 4 | `add2` | 354 | 4.1s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 3.7s |  |
| 6 | `add_swf5` | 28 | 3.7s |  |
| 7 | `array_concat` | 98 | 3.9s |  |
| 8 | `array_constructor` | 30 | 3.8s |  |
| 9 | `array_length` | 42 | 3.9s |  |
| 10 | `array_properties` | 36 | 3.8s |  |
| 11 | `array_slice` | 34 | 3.9s |  |
| 12 | `array_splice` | 207 | 4.5s |  |
| 13 | `array_trivial` | 209 | 4.3s |  |
| 14 | `as1_constructor_v6` | 35 | 3.8s |  |
| 15 | `as1_constructor_v7` | 35 | 3.8s |  |
| 16 | `as_broadcaster_initialize` | 10 | 3.7s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 3.7s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 3.7s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 3.7s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 3.7s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 3.7s |  |
| 22 | `as_transformed_flag` | 20 | 3.8s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 3.6s |  |
| 24 | `bitand` | 1058 | 10.3s |  |
| 25 | `bitmap_data_colortransform` | 0 | 4.0s |  |
| 26 | `bitmap_data_fillrect` | 0 | 3.9s |  |
| 27 | `bitmap_data_max_size_swf10` | 12 | 3.7s |  |
| 28 | `bitmap_data_max_size_swf9` | 10 | 3.6s |  |
| 29 | `bitmap_data_perlinnoise` | 0 | 4.4s |  |
| 30 | `bitmap_data_pixeldissolve_image` | 0 | 4.2s |  |
| 31 | `bitmapdata_applyfilter_colormatrix` | 0 | 3.7s |  |
| 32 | `bitor` | 1058 | 10.4s |  |
| 33 | `biturshift` | 14 | 4.0s |  |
| 34 | `biturshift_swf8` | 14 | 3.7s |  |
| 35 | `bitxor` | 1058 | 10.6s |  |
| 36 | `call_method_empty_name` | 1 | 3.6s |  |
| 37 | `capabilities_resolution` | 8 | 3.6s |  |
| 38 | `catch_references_registers` | 2 | 3.7s |  |
| 39 | `conflicting_instance_names` | 23 | 3.8s |  |
| 40 | `define_function2` | 8 | 3.6s |  |
| 41 | `define_function2_preload` | 13 | 3.6s |  |
| 42 | `define_function2_preload_order` | 4 | 3.7s |  |
| 43 | `define_function_case_sensitive` | 2 | 3.7s |  |
| 44 | `delete` | 3 | 3.7s |  |
| 45 | `display_object_properties` | 2 | 3.7s |  |
| 46 | `divide_swf4` | 107 | 3.8s |  |
| 47 | `do_init_action` | 3 | 3.7s |  |
| 48 | `edittext_antialiastype` | 296 | 4.4s |  |
| 49 | `edittext_autosize_setter` | 20 | 3.8s |  |
| 50 | `edittext_default_format` | 221 | 4.0s |  |
| 51 | `edittext_default_format_empty` | 95 | 3.8s |  |
| 52 | `edittext_default_format_font_style` | 335 | 3.9s |  |
| 53 | `equals` | 32 | 3.8s |  |
| 54 | `equals2_swf5` | 926 | 11.8s |  |
| 55 | `equals2_swf6` | 926 | 12.1s |  |
| 56 | `equals2_swf7` | 926 | 12.1s |  |
| 57 | `equals_swf4` | 665 | 7.3s |  |
| 58 | `equals_swf4_alt` | 32 | 3.8s |  |
| 59 | `equals_swf5` | 32 | 3.7s |  |
| 60 | `error` | 58 | 3.9s |  |
| 61 | `escape` | 14 | 3.7s |  |
| 62 | `execution_order1` | 5 | 3.8s |  |
| 63 | `execution_order2` | 7 | 3.8s |  |
| 64 | `execution_order3` | 4 | 3.7s |  |
| 65 | `focusrect_mouse_swf8` | 0 | 3.9s |  |
| 66 | `focusrect_mouse_swf9` | 0 | 3.9s |  |
| 67 | `focusrect_swf5` | 6 | 4.1s |  |
| 68 | `get_variable_in_scope` | 29 | 4.1s |  |
| 69 | `getproperty` | 28 | 4.0s |  |
| 70 | `getproperty_swf4` | 28 | 4.0s |  |
| 71 | `getproperty_swf5` | 28 | 3.9s |  |
| 72 | `global_array` | 3 | 3.9s |  |
| 73 | `global_is_bare` | 7 | 3.9s |  |
| 74 | `goto_advance1` | 6 | 4.0s |  |
| 75 | `goto_advance2` | 2 | 4.0s |  |
| 76 | `goto_both_ways1` | 3 | 5.3s |  |
| 77 | `goto_both_ways2` | 3 | 3.6s |  |
| 78 | `goto_execution_order` | 2 | 3.6s |  |
| 79 | `goto_execution_order2` | 2 | 3.6s |  |
| 80 | `goto_frame_number` | 3 | 3.7s |  |
| 81 | `goto_rewind1` | 1 | 3.7s |  |
| 82 | `goto_rewind2` | 3 | 3.8s |  |
| 83 | `goto_rewind3` | 2 | 3.6s |  |
| 84 | `greater_swf6` | 1175 | 12.3s |  |
| 85 | `greater_swf7` | 1175 | 12.3s |  |
| 86 | `greaterthan_swf5` | 1 | 3.6s |  |
| 87 | `greaterthan_swf8` | 1 | 3.6s |  |
| 88 | `has_own_property` | 32 | 3.7s |  |
| 89 | `infinite_recursion_function` | 4 | 3.6s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 90 | `infinite_recursion_function_in_setter` | 131 | 3.6s |  |
| 91 | `infinite_recursion_virtual_property` | 67 | 3.6s |  |
| 92 | `init_array_invalid` | 4 | 3.6s |  |
| 93 | `init_object_invalid` | 4 | 3.6s |  |
| 94 | `issue_1086` | 1 | 3.6s |  |
| 95 | `issue_1671` | 0 | 3.6s |  |
| 96 | `issue_2166` | 9 | 3.7s |  |
| 97 | `issue_3446` | 1 | 3.6s |  |
| 98 | `issue_4377` | 2 | 3.6s |  |
| 99 | `issue_710` | 4 | 3.6s |  |
| 100 | `issue_768` | 3 | 3.6s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 101 | `lessthan` | 41 | 3.7s |  |
| 102 | `lessthan2_swf5` | 1226 | 12.7s |  |
| 103 | `lessthan2_swf6` | 1226 | 12.8s |  |
| 104 | `lessthan2_swf7` | 1226 | 12.8s |  |
| 105 | `lessthan_swf4` | 902 | 8.8s |  |
| 106 | `lessthan_swf4_alt` | 41 | 3.7s |  |
| 107 | `lessthan_swf5` | 41 | 3.7s |  |
| 108 | `logical_ops_swf4` | 90 | 3.8s |  |
| 109 | `logical_ops_swf8` | 108 | 3.8s |  |
| 110 | `looping` | 6 | 3.7s |  |
| 111 | `mask_reapply` | 0 | 3.7s |  |
| 112 | `mask_with_drawing` | 0 | 3.7s |  |
| 113 | `movieclip_begin_gradient_fill` | 0 | 4.3s |  |
| 114 | `movieclip_line_gradient_style` | 0 | 4.3s |  |
| 115 | `movieclip_name_from_timeline` | 13 | 3.7s |  |
| 116 | `movieclip_prototype_extension` | 5 | 3.8s |  |
| 117 | `nested_textfields_in_buttons` | 0 | 3.7s |  |
| 118 | `netstream_play_flv_screen` | 0 | 31.7s |  |
| 119 | `new_method_wrap` | 4 | 3.7s |  |
| 120 | `new_object_wrap` | 4 | 3.7s |  |
| 121 | `o` | 3 | 3.7s |  |
| 122 | `object_constructor` | 33 | 3.8s |  |
| 123 | `object_function` | 32 | 3.9s |  |
| 124 | `object_string_coerce_swf5` | 62 | 3.9s |  |
| 125 | `primitive_instanceof` | 37 | 3.8s |  |
| 126 | `prototype_delete` | 12 | 3.8s |  |
| 127 | `recursive_prototypes` | 0 | 3.7s |  |
| 128 | `sandbox_type_local_file` | 1 | 3.5s |  |
| 129 | `set_variable_scope` | 58 | 3.8s |  |
| 130 | `single_frame` | 1 | 3.6s |  |
| 131 | `sound_start_load` | 0 | 3.6s |  |
| 132 | `stage_object_properties_get_var` | 5 | 3.6s |  |
| 133 | `strictequals_swf6` | 902 | 9.5s |  |
| 134 | `strictly_equals` | 7 | 3.6s |  |
| 135 | `string_coercion` | 117 | 4.2s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 136 | `string_paths_keyevents` | 0 | 3.6s |  |
| 137 | `string_paths_timer` | 0 | 3.6s |  |
| 138 | `swf4_actions_bool` | 96 | 3.7s |  |
| 139 | `swf4_bool` | 4 | 3.6s |  |
| 140 | `swf4_function_calls` | 7 | 3.8s |  |
| 141 | `swf5_encoding` | 3 | 3.6s |  |
| 142 | `tab_ordering_properties_tab_index_edge_case` | 4 | 3.7s |  |
| 143 | `target_path` | 14 | 3.7s |  |
| 144 | `text_format` | 1146 | 4.1s |  |
| 145 | `text_format_display` | 21 | 3.8s |  |
| 146 | `text_format_font_max_length` | 2 | 3.7s |  |
| 147 | `text_format_rounding_swf7` | 840 | 4.0s |  |
| 148 | `text_format_rounding_swf8` | 840 | 4.0s |  |
| 149 | `textfield_background_color` | 11 | 3.7s |  |
| 150 | `textfield_border_color` | 11 | 3.7s |  |
| 151 | `textfield_maxchars` | 3 | 3.8s |  |
| 152 | `textfield_properties` | 44 | 3.9s |  |
| 153 | `textfield_props_swf6` | 210 | 4.6s |  |
| 154 | `textfield_props_swf7` | 210 | 4.6s |  |
| 155 | `textfield_props_swf8` | 210 | 4.6s |  |
| 156 | `textfield_text` | 7 | 3.7s |  |
| 157 | `textfield_variable` | 81 | 4.2s |  |
| 158 | `this_swf7` | 41 | 3.7s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 159 | `timeline_function_def` | 7 | 3.8s |  |
| 160 | `try_finally_simple` | 16 | 3.8s |  |
| 161 | `typeof` | 22 | 3.8s |  |
| 162 | `typeof_globals` | 7 | 3.7s |  |
| 163 | `uncaught_exception` | 1 | 3.7s |  |
| 164 | `uncaught_exception_bubbled` | 1 | 3.7s |  |
| 165 | `undefined_to_string_swf6` | 4 | 3.7s |  |
| 166 | `unescape` | 43 | 3.8s |  |
| 167 | `use_hand_cursor` | 8 | 3.7s |  |
| 168 | `variable_args` | 5 | 3.9s |  |
| 169 | `waitforframe` | 7 | 3.7s |  |
| 170 | `waitforframe2` | 16 | 3.8s |  |
| 171 | `with_return` | 2 | 3.7s |  |
| 172 | `xml` | 15 | 3.7s |  |
| 173 | `xml_append_child` | 28 | 3.9s |  |
| 174 | `xml_append_child_with_parent` | 20 | 3.8s |  |
| 175 | `xml_attributes_read` | 4 | 3.8s |  |
| 176 | `xml_cdata` | 11 | 3.7s |  |
| 177 | `xml_clone_expandos` | 19 | 3.8s |  |
| 178 | `xml_first_last_child` | 8 | 3.8s |  |
| 179 | `xml_has_child_nodes` | 3 | 3.7s |  |
| 180 | `xml_idmap` | 21 | 3.9s |  |
| 181 | `xml_ignore_white` | 34 | 3.9s |  |
| 182 | `xml_insert_before` | 20 | 3.8s |  |
| 183 | `xml_inspect_createmethods` | 15 | 3.8s |  |
| 184 | `xml_inspect_doctype` | 7 | 3.8s |  |
| 185 | `xml_inspect_parsexml` | 62 | 3.8s |  |
| 186 | `xml_inspect_xmldecl` | 7 | 3.8s |  |
| 187 | `xml_namespaces` | 203 | 3.8s |  |
| 188 | `xml_parent_and_child` | 5 | 3.8s |  |
| 189 | `xml_remove_node` | 22 | 3.9s |  |
| 190 | `xml_reparenting` | 14 | 3.8s |  |
| 191 | `xml_siblings` | 10 | 3.8s |  |
| 192 | `xml_to_string_comment` | 1 | 3.7s |  |
| 193 | `xml_unescaping` | 23 | 4.0s |  |
| 194 | `xmlnode_proto` | 1 | 3.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**82 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `swf7_case_sensitive` | 90.9% | 40 | 44 | 4 |  |
| 2 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 |  |
| 3 | `function_suppress_and_preload` | 85.7% | 24 | 28 | 4 |  |
| 4 | `xml_ignore_comments` | 85.7% | 18 | 21 | 3 |  |
| 5 | `xml_to_string` | 84.6% | 11 | 13 | 2 |  |
| 6 | `object_prototypes` | 83.8% | 62 | 74 | 12 |  |
| 7 | `stage_object_children` | 81.9% | 68 | 83 | 15 |  |
| 8 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 9 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 |  |
| 10 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 11 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 12 | `as2_oop` | 76.9% | 10 | 13 | 3 |  |
| 13 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 |  |
| 14 | `xml_child_nodes_edge_cases` | 75.0% | 3 | 4 | 1 |  |
| 15 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 16 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 17 | `extends_native_type` | 72.7% | 8 | 11 | 3 |  |
| 18 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 19 | `globals_swf6` | 71.4% | 217 | 304 | 87 |  |
| 20 | `point` | 70.9% | 124 | 175 | 51 |  |
| 21 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 22 | `globals_swf7` | 70.4% | 214 | 304 | 90 |  |
| 23 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 24 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 25 | `globals_swf5` | 69.1% | 210 | 304 | 94 |  |
| 26 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 27 | `movieclip_blend_mode_property` | 68.6% | 24 | 35 | 11 |  |
| 28 | `transform` | 68.6% | 48 | 70 | 22 |  |
| 29 | `stage_object_properties` | 68.5% | 165 | 241 | 76 |  |
| 30 | `stage_object_properties_swf6` | 68.4% | 158 | 231 | 73 |  |
| 31 | `as_set_prop_flags` | 68.4% | 54 | 79 | 25 |  |
| 32 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 33 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 34 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 35 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 36 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 37 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 38 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 39 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 40 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 41 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 42 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 43 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 44 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 45 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 46 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 |  |
| 47 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 48 | `with` | 61.2% | 30 | 49 | 19 |  |
| 49 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 50 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 51 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 52 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 53 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 54 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 55 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 56 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 57 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 58 | `remove_movie_clip` | 58.6% | 17 | 29 | 12 |  |
| 59 | `boxed_primitives` | 58.3% | 14 | 24 | 10 |  |
| 60 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 61 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 62 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 63 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 64 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 65 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 66 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 67 | `clone_sprite_types` | 54.2% | 13 | 24 | 11 |  |
| 68 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 69 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 |  |
| 70 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 71 | `string_methods_negative_args` | 52.7% | 127 | 241 | 114 |  |
| 72 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 73 | `globals_swf8` | 51.0% | 155 | 304 | 149 |  |
| 74 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 |  |
| 75 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 76 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 77 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 78 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 79 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 80 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 81 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 82 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `duplicate_movie_clip_drawing` | 5.7s |  |
| 2 | `goto_methods` | 6.1s |  |
| 3 | `path_string` | 6.3s |  |
| 4 | `swf4_actions_coercion_order` | 5.2s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `device_font_spacing` | runtime timeout (>10s) | 13.9s |  |
| 2 | `parse_float` | runtime timeout (>10s) | 14.8s |  |
| 3 | `timeout` | runtime timeout (>10s) | 15.2s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 14.2s |  |

## All Output Mismatches

**280 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `swf7_case_sensitive` | 90.9% | 40/44 | 44 | 44 |  |
| 2 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 |  |
| 3 | `function_suppress_and_preload` | 85.7% | 24/28 | 28 | 28 |  |
| 4 | `xml_ignore_comments` | 85.7% | 18/21 | 21 | 21 |  |
| 5 | `xml_to_string` | 84.6% | 11/13 | 13 | 13 |  |
| 6 | `object_prototypes` | 83.8% | 62/74 | 73 | 74 |  |
| 7 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 |  |
| 8 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 9 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 |  |
| 10 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 11 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 12 | `as2_oop` | 76.9% | 10/13 | 13 | 13 |  |
| 13 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 |  |
| 14 | `xml_child_nodes_edge_cases` | 75.0% | 3/4 | 4 | 4 |  |
| 15 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 16 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 17 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 |  |
| 18 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 19 | `globals_swf6` | 71.4% | 217/304 | 304 | 304 |  |
| 20 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 21 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 22 | `globals_swf7` | 70.4% | 214/304 | 304 | 304 |  |
| 23 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 24 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 25 | `globals_swf5` | 69.1% | 210/304 | 304 | 304 |  |
| 26 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 27 | `movieclip_blend_mode_property` | 68.6% | 24/35 | 35 | 35 |  |
| 28 | `transform` | 68.6% | 48/70 | 70 | 70 |  |
| 29 | `stage_object_properties` | 68.5% | 165/241 | 241 | 241 |  |
| 30 | `stage_object_properties_swf6` | 68.4% | 158/231 | 231 | 231 |  |
| 31 | `as_set_prop_flags` | 68.4% | 54/79 | 76 | 79 |  |
| 32 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 33 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 34 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 35 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 36 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 37 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 38 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 39 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 40 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 41 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 42 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 43 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 44 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 45 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 46 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 |  |
| 47 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 48 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 49 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 50 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 51 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 52 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 53 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 54 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 55 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 56 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 57 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 58 | `remove_movie_clip` | 58.6% | 17/29 | 29 | 29 |  |
| 59 | `boxed_primitives` | 58.3% | 14/24 | 24 | 24 |  |
| 60 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 61 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 62 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 63 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 64 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 65 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 66 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 67 | `clone_sprite_types` | 54.2% | 13/24 | 24 | 24 |  |
| 68 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 69 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 |  |
| 70 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 71 | `string_methods_negative_args` | 52.7% | 127/241 | 241 | 240 |  |
| 72 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 73 | `globals_swf8` | 51.0% | 155/304 | 304 | 304 |  |
| 74 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 |  |
| 75 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 76 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 77 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 78 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 79 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 80 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 81 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 82 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 83 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 84 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 85 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 86 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 |  |
| 87 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 88 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 89 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 90 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 91 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 92 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 93 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 |  |
| 94 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 |  |
| 95 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 96 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 |  |
| 97 | `edittext_html_swf6` | 37.5% | 2016/5377 | 5377 | 5377 |  |
| 98 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 99 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 100 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 101 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 102 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 103 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 104 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 105 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 106 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 107 | `edittext_html_condensewhite_swf7` | 30.2% | 94/311 | 311 | 311 |  |
| 108 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 109 | `edittext_html_condensewhite_swf8` | 29.3% | 91/311 | 311 | 311 |  |
| 110 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 111 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 |  |
| 112 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 113 | `edittext_html_swf7` | 25.7% | 1380/5377 | 5377 | 5377 |  |
| 114 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 115 | `edittext_html_swf8` | 25.4% | 1365/5377 | 5377 | 5377 |  |
| 116 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 117 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 118 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 119 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 120 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 121 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 122 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 123 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 124 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 125 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 126 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 127 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 128 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 129 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 130 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 131 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 |  |
| 132 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 133 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 134 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 135 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 136 | `watch` | 15.4% | 18/117 | 101 | 117 |  |
| 137 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 138 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 139 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 140 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 141 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 142 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 143 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 144 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 |  |
| 145 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 146 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 147 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 148 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 149 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 150 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 151 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 152 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 153 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 154 | `unload` | 9.6% | 5/52 | 48 | 52 |  |
| 155 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 156 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 157 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 158 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 |  |
| 159 | `extends_chain` | 9.0% | 12/134 | 122 | 134 |  |
| 160 | `instanceof_coercions` | 8.0% | 7/88 | 70 | 88 |  |
| 161 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 162 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 163 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 164 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 165 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 166 | `hittest_lockroot` | 6.7% | 1/15 | 15 | 15 |  |
| 167 | `init_object_order` | 6.7% | 1/15 | 5 | 15 |  |
| 168 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 169 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 170 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 171 | `as2_super_and_this_v6` | 6.2% | 6/97 | 17 | 97 |  |
| 172 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 173 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 174 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 175 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 176 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 177 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 178 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 179 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 180 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 |  |
| 181 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 182 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 183 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 184 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 185 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 186 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 187 | `asnew` | 2.9% | 1/34 | 3 | 34 |  |
| 188 | `as2_super_and_this_v8` | 2.4% | 2/85 | 9 | 85 |  |
| 189 | `clone_sprite_edittext_dynamic` | 2.3% | 2/86 | 86 | 86 |  |
| 190 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 191 | `math_swf6` | 1.9% | 10/530 | 458 | 530 |  |
| 192 | `math_swf7` | 1.9% | 10/530 | 458 | 530 |  |
| 193 | `math_swf8` | 1.9% | 10/530 | 458 | 530 |  |
| 194 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 195 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 196 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 197 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 198 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 199 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 200 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 201 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 202 | `global_instance_decls` | 0.1% | 1/758 | 141 | 758 |  |
| 203 | `global_proto_decls` | 0.0% | 2/4497 | 93 | 4497 |  |
| 204 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 205 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 206 | `array_sort_random` | 0.0% | 0/443 | 2 | 443 |  |
| 207 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 208 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 209 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 210 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 211 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 212 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 213 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 214 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 215 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 216 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 217 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 218 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 219 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 220 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 221 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 222 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 223 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 224 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 225 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 226 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 227 | `global_proto_decls_delete` | 0.0% | 0/4158 | 22 | 4158 |  |
| 228 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 229 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 230 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 231 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 232 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 233 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 234 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 235 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 236 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 237 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 238 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 239 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 240 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 241 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 242 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 243 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 244 | `native_objects_swf6` | 0.0% | 0/183 | 183 | 84 |  |
| 245 | `native_objects_swf7` | 0.0% | 0/183 | 183 | 84 |  |
| 246 | `native_objects_swf8` | 0.0% | 0/183 | 183 | 84 |  |
| 247 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 248 | `object_resolve` | 0.0% | 0/38 | 23 | 38 |  |
| 249 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 250 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 251 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 252 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 253 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 254 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 255 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 256 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 257 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 258 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 259 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 260 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 261 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 262 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 263 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 264 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 265 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 266 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 267 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 268 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 269 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 270 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 271 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 272 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 273 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 274 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 275 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 276 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 277 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 278 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 279 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 280 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
