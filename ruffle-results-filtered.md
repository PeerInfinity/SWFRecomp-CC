# Ruffle Test Results (Filtered)

**Date**: 2026-02-15 17:34 UTC

**Git SHA**: `12e36a9c0d`

**Run Duration**: 44m 47s

**Filtered**: 137 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 482 |
| Passing | **179** (37.1%) |
| Failing | 303 |
| Total expected lines | 77736 |
| Matching lines | 40746 (52.4%) |
| Mismatched lines | 36990 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 294 | 97.0% |
| Segfault | 6 | 2.0% |
| Timeout | 3 | 1.0% |

## Passing Tests

**179 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 4.1s |  |
| 2 | `action_to_integer` | 28 | 4.0s |  |
| 3 | `add` | 28 | 4.0s |  |
| 4 | `add2` | 354 | 4.2s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 3.9s |  |
| 6 | `add_swf5` | 28 | 4.0s |  |
| 7 | `array_concat` | 98 | 4.0s |  |
| 8 | `array_constructor` | 30 | 4.0s |  |
| 9 | `array_length` | 42 | 4.0s |  |
| 10 | `array_properties` | 36 | 4.0s |  |
| 11 | `array_slice` | 34 | 4.0s |  |
| 12 | `array_splice` | 207 | 4.2s |  |
| 13 | `array_trivial` | 209 | 4.1s |  |
| 14 | `as1_constructor_v6` | 35 | 3.9s |  |
| 15 | `as1_constructor_v7` | 35 | 3.9s |  |
| 16 | `as_broadcaster_initialize` | 10 | 4.0s |  |
| 17 | `as_transformed_flag` | 20 | 4.0s |  |
| 18 | `bad_swf_tag_past_eof` | 0 | 3.9s |  |
| 19 | `bitand` | 1058 | 6.5s |  |
| 20 | `bitmap_data_colortransform` | 0 | 4.2s |  |
| 21 | `bitmap_data_fillrect` | 0 | 4.1s |  |
| 22 | `bitmap_data_max_size_swf10` | 12 | 4.0s |  |
| 23 | `bitmap_data_max_size_swf9` | 10 | 3.9s |  |
| 24 | `bitmap_data_perlinnoise` | 0 | 4.5s |  |
| 25 | `bitmap_data_pixeldissolve_image` | 0 | 4.5s |  |
| 26 | `bitmapdata_applyfilter_colormatrix` | 0 | 4.0s |  |
| 27 | `bitor` | 1058 | 6.6s |  |
| 28 | `biturshift` | 14 | 4.3s |  |
| 29 | `biturshift_swf8` | 14 | 4.0s |  |
| 30 | `bitxor` | 1058 | 6.6s |  |
| 31 | `call_method_empty_name` | 1 | 3.9s |  |
| 32 | `capabilities_resolution` | 8 | 4.0s |  |
| 33 | `catch_references_registers` | 2 | 4.0s |  |
| 34 | `conflicting_instance_names` | 23 | 4.1s |  |
| 35 | `define_function2` | 8 | 4.0s |  |
| 36 | `define_function2_preload` | 13 | 4.0s |  |
| 37 | `define_function2_preload_order` | 4 | 4.0s |  |
| 38 | `define_function_case_sensitive` | 2 | 4.0s |  |
| 39 | `delete` | 3 | 4.0s |  |
| 40 | `display_object_properties` | 2 | 4.0s |  |
| 41 | `do_init_action` | 3 | 4.0s |  |
| 42 | `edittext_antialiastype` | 296 | 4.6s |  |
| 43 | `edittext_autosize_setter` | 20 | 4.0s |  |
| 44 | `edittext_default_format` | 221 | 4.1s |  |
| 45 | `edittext_default_format_empty` | 95 | 4.0s |  |
| 46 | `edittext_default_format_font_style` | 335 | 4.1s |  |
| 47 | `equals` | 32 | 4.1s |  |
| 48 | `equals2_swf5` | 926 | 5.9s |  |
| 49 | `equals2_swf6` | 926 | 5.7s |  |
| 50 | `equals2_swf7` | 926 | 5.7s |  |
| 51 | `equals_swf4` | 665 | 4.4s |  |
| 52 | `equals_swf4_alt` | 32 | 3.9s |  |
| 53 | `equals_swf5` | 32 | 4.0s |  |
| 54 | `error` | 58 | 4.0s |  |
| 55 | `escape` | 14 | 4.0s |  |
| 56 | `execution_order1` | 5 | 4.0s |  |
| 57 | `execution_order2` | 7 | 4.0s |  |
| 58 | `execution_order3` | 4 | 4.0s |  |
| 59 | `focusrect_mouse_swf8` | 0 | 4.0s |  |
| 60 | `focusrect_mouse_swf9` | 0 | 4.0s |  |
| 61 | `focusrect_swf5` | 6 | 4.1s |  |
| 62 | `getproperty` | 28 | 4.0s |  |
| 63 | `getproperty_swf4` | 28 | 4.0s |  |
| 64 | `getproperty_swf5` | 28 | 4.0s |  |
| 65 | `global_array` | 3 | 3.9s |  |
| 66 | `global_is_bare` | 7 | 4.0s |  |
| 67 | `goto_advance1` | 6 | 4.1s |  |
| 68 | `goto_advance2` | 2 | 4.1s |  |
| 69 | `goto_both_ways1` | 3 | 4.1s |  |
| 70 | `goto_both_ways2` | 3 | 3.9s |  |
| 71 | `goto_execution_order` | 2 | 3.9s |  |
| 72 | `goto_execution_order2` | 2 | 3.9s |  |
| 73 | `goto_frame_number` | 3 | 4.0s |  |
| 74 | `goto_rewind1` | 1 | 4.0s |  |
| 75 | `goto_rewind2` | 3 | 4.0s |  |
| 76 | `goto_rewind3` | 2 | 3.9s |  |
| 77 | `greater_swf6` | 1175 | 5.8s |  |
| 78 | `greater_swf7` | 1175 | 5.8s |  |
| 79 | `greaterthan_swf5` | 1 | 3.9s |  |
| 80 | `greaterthan_swf8` | 1 | 3.9s |  |
| 81 | `has_own_property` | 32 | 3.9s |  |
| 82 | `infinite_recursion_function` | 4 | 3.9s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 83 | `infinite_recursion_function_in_setter` | 131 | 3.9s |  |
| 84 | `infinite_recursion_virtual_property` | 67 | 3.9s |  |
| 85 | `init_array_invalid` | 4 | 3.9s |  |
| 86 | `init_object_invalid` | 4 | 3.9s |  |
| 87 | `issue_1086` | 1 | 3.9s |  |
| 88 | `issue_1671` | 0 | 3.9s |  |
| 89 | `issue_2166` | 9 | 3.9s |  |
| 90 | `issue_3446` | 1 | 3.9s |  |
| 91 | `issue_4377` | 2 | 3.9s |  |
| 92 | `issue_710` | 4 | 3.9s |  |
| 93 | `issue_768` | 3 | 3.9s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 94 | `lessthan` | 41 | 3.9s |  |
| 95 | `lessthan2_swf5` | 1226 | 5.9s |  |
| 96 | `lessthan2_swf6` | 1226 | 5.9s |  |
| 97 | `lessthan2_swf7` | 1226 | 6.0s |  |
| 98 | `lessthan_swf4` | 902 | 4.5s |  |
| 99 | `lessthan_swf4_alt` | 41 | 3.9s |  |
| 100 | `lessthan_swf5` | 41 | 3.9s |  |
| 101 | `logical_ops_swf4` | 90 | 4.1s |  |
| 102 | `logical_ops_swf8` | 108 | 4.2s |  |
| 103 | `looping` | 6 | 4.1s |  |
| 104 | `mask_reapply` | 0 | 4.1s |  |
| 105 | `mask_with_drawing` | 0 | 4.1s |  |
| 106 | `movieclip_begin_gradient_fill` | 0 | 4.6s |  |
| 107 | `movieclip_blend_mode_property` | 35 | 4.2s |  |
| 108 | `movieclip_default_state` | 69 | 4.3s |  |
| 109 | `movieclip_line_gradient_style` | 0 | 4.6s |  |
| 110 | `movieclip_name_from_timeline` | 13 | 4.1s |  |
| 111 | `movieclip_prototype_extension` | 5 | 4.1s |  |
| 112 | `nested_textfields_in_buttons` | 0 | 4.1s |  |
| 113 | `netstream_play_flv_screen` | 0 | 17.5s |  |
| 114 | `new_method_wrap` | 4 | 4.1s |  |
| 115 | `new_object_wrap` | 4 | 4.1s |  |
| 116 | `o` | 3 | 4.1s |  |
| 117 | `object_constructor` | 33 | 4.1s |  |
| 118 | `object_function` | 32 | 4.1s |  |
| 119 | `object_string_coerce_swf5` | 62 | 4.2s |  |
| 120 | `primitive_instanceof` | 37 | 4.1s |  |
| 121 | `prototype_delete` | 12 | 4.1s |  |
| 122 | `recursive_prototypes` | 0 | 4.2s |  |
| 123 | `sandbox_type_local_file` | 1 | 4.0s |  |
| 124 | `set_variable_scope` | 58 | 4.1s |  |
| 125 | `single_frame` | 1 | 4.1s |  |
| 126 | `sound_start_load` | 0 | 4.1s |  |
| 127 | `stage_object_properties_get_var` | 5 | 4.0s |  |
| 128 | `strictequals_swf6` | 902 | 5.7s |  |
| 129 | `strictly_equals` | 7 | 4.1s |  |
| 130 | `string_coercion` | 117 | 4.4s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 131 | `string_methods_negative_args` | 240 | 4.2s |  |
| 132 | `string_methods_swfv5` | 275 | 4.6s |  |
| 133 | `string_paths_keyevents` | 0 | 4.0s |  |
| 134 | `string_paths_timer` | 0 | 4.1s |  |
| 135 | `swf4_actions_bool` | 96 | 4.1s |  |
| 136 | `swf4_bool` | 4 | 4.1s |  |
| 137 | `swf5_encoding` | 3 | 3.9s |  |
| 138 | `tab_ordering_properties_tab_index_edge_case` | 4 | 4.0s |  |
| 139 | `text_format` | 1146 | 4.2s |  |
| 140 | `text_format_display` | 21 | 4.0s |  |
| 141 | `text_format_font_max_length` | 2 | 4.0s |  |
| 142 | `text_format_rounding_swf7` | 840 | 4.1s |  |
| 143 | `text_format_rounding_swf8` | 840 | 4.1s |  |
| 144 | `textfield_background_color` | 11 | 4.0s |  |
| 145 | `textfield_border_color` | 11 | 4.0s |  |
| 146 | `textfield_maxchars` | 3 | 4.0s |  |
| 147 | `textfield_properties` | 44 | 4.0s |  |
| 148 | `textfield_text` | 7 | 4.0s |  |
| 149 | `textfield_variable` | 81 | 4.2s |  |
| 150 | `this_swf7` | 41 | 4.0s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 151 | `timeline_function_def` | 7 | 4.1s |  |
| 152 | `try_finally_simple` | 16 | 4.0s |  |
| 153 | `typeof` | 22 | 4.1s |  |
| 154 | `typeof_globals` | 7 | 4.0s |  |
| 155 | `uncaught_exception` | 1 | 4.0s |  |
| 156 | `uncaught_exception_bubbled` | 1 | 4.0s |  |
| 157 | `undefined_to_string_swf6` | 4 | 4.0s |  |
| 158 | `unescape` | 43 | 4.0s |  |
| 159 | `use_hand_cursor` | 8 | 4.0s |  |
| 160 | `variable_args` | 5 | 4.1s |  |
| 161 | `waitforframe` | 7 | 4.0s |  |
| 162 | `waitforframe2` | 16 | 4.0s |  |
| 163 | `with_return` | 2 | 4.0s |  |
| 164 | `xml` | 15 | 4.0s |  |
| 165 | `xml_attributes_read` | 4 | 4.0s |  |
| 166 | `xml_cdata` | 11 | 4.0s |  |
| 167 | `xml_has_child_nodes` | 3 | 4.0s |  |
| 168 | `xml_idmap` | 21 | 4.0s |  |
| 169 | `xml_ignore_comments` | 21 | 4.0s |  |
| 170 | `xml_ignore_white` | 34 | 4.0s |  |
| 171 | `xml_inspect_createmethods` | 15 | 4.0s |  |
| 172 | `xml_inspect_doctype` | 7 | 4.0s |  |
| 173 | `xml_inspect_parsexml` | 62 | 4.0s |  |
| 174 | `xml_inspect_xmldecl` | 7 | 4.0s |  |
| 175 | `xml_namespaces` | 203 | 4.0s |  |
| 176 | `xml_reparenting` | 14 | 4.0s |  |
| 177 | `xml_to_string_comment` | 1 | 3.9s |  |
| 178 | `xml_unescaping` | 23 | 4.0s |  |
| 179 | `xmlnode_proto` | 1 | 4.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**94 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `string_methods` | 98.9% | 282 | 285 | 3 |  |
| 2 | `edittext_width_height` | 94.2% | 97 | 103 | 6 |  |
| 3 | `get_variable_in_scope` | 93.1% | 27 | 29 | 2 |  |
| 4 | `swf7_case_sensitive` | 90.9% | 40 | 44 | 4 |  |
| 5 | `divide_swf4` | 88.8% | 95 | 107 | 12 |  |
| 6 | `textfield_props_swf8` | 87.6% | 184 | 210 | 26 |  |
| 7 | `xml_first_last_child` | 87.5% | 7 | 8 | 1 |  |
| 8 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 |  |
| 9 | `textfield_props_swf6` | 86.2% | 181 | 210 | 29 |  |
| 10 | `function_suppress_and_preload` | 85.7% | 24 | 28 | 4 |  |
| 11 | `swf4_function_calls` | 85.7% | 6 | 7 | 1 |  |
| 12 | `textfield_props_swf7` | 85.2% | 179 | 210 | 31 |  |
| 13 | `object_prototypes` | 83.8% | 62 | 74 | 12 |  |
| 14 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 15 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 |  |
| 16 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 17 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 18 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 19 | `movieclip_depth_methods` | 77.6% | 76 | 98 | 22 |  |
| 20 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 21 | `as2_oop` | 76.9% | 10 | 13 | 3 |  |
| 22 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 |  |
| 23 | `string_paths_basic` | 75.0% | 3 | 4 | 1 |  |
| 24 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 25 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 26 | `extends_native_type` | 72.7% | 8 | 11 | 3 |  |
| 27 | `array_sort` | 72.0% | 116 | 161 | 45 |  |
| 28 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 29 | `stage_object_properties_swf6` | 71.9% | 166 | 231 | 65 |  |
| 30 | `stage_object_properties` | 71.8% | 173 | 241 | 68 |  |
| 31 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 |  |
| 32 | `transform` | 71.4% | 50 | 70 | 20 |  |
| 33 | `globals_swf6` | 71.4% | 217 | 304 | 87 |  |
| 34 | `point` | 70.9% | 124 | 175 | 51 |  |
| 35 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 36 | `globals_swf7` | 70.4% | 214 | 304 | 90 |  |
| 37 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 38 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 39 | `globals_swf5` | 69.1% | 210 | 304 | 94 |  |
| 40 | `xml_clone_expandos` | 68.4% | 13 | 19 | 6 |  |
| 41 | `as_set_prop_flags` | 68.4% | 54 | 79 | 25 |  |
| 42 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 43 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 44 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 |  |
| 45 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 46 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 47 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 48 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 49 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 50 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 51 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 |  |
| 52 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 53 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 54 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 55 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 56 | `xml_append_child` | 64.3% | 18 | 28 | 10 |  |
| 57 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 |  |
| 58 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 |  |
| 59 | `edittext_autosize` | 62.0% | 44 | 71 | 27 |  |
| 60 | `as_set_prop_flags_version` | 61.3% | 19 | 31 | 12 |  |
| 61 | `with` | 61.2% | 30 | 49 | 19 |  |
| 62 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 63 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 64 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 65 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 66 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 67 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 68 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 69 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 70 | `boxed_primitives` | 58.3% | 14 | 24 | 10 |  |
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
| 82 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 83 | `globals_swf8` | 51.0% | 155 | 304 | 149 |  |
| 84 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 |  |
| 85 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 86 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 87 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 88 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 89 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 90 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 91 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 |  |
| 92 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 93 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 94 | `xml_siblings` | 50.0% | 5 | 10 | 5 |  |

## Segfaults

**6 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 9.2s |  |
| 2 | `enumerate` | 6.0s |  |
| 3 | `goto_methods` | 6.1s |  |
| 4 | `init_object_order` | 6.0s |  |
| 5 | `register_and_init_order` | 6.5s |  |
| 6 | `register_class` | 6.4s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**3 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 15.1s |  |
| 2 | `timeout` | runtime timeout (>10s) | 14.2s |  |
| 3 | `try_catch_finally` | runtime timeout (>10s) | 14.2s |  |

## All Output Mismatches

**294 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `string_methods` | 98.9% | 282/285 | 285 | 285 |  |
| 2 | `edittext_width_height` | 94.2% | 97/103 | 103 | 103 |  |
| 3 | `get_variable_in_scope` | 93.1% | 27/29 | 29 | 29 |  |
| 4 | `swf7_case_sensitive` | 90.9% | 40/44 | 44 | 44 |  |
| 5 | `divide_swf4` | 88.8% | 95/107 | 107 | 107 |  |
| 6 | `textfield_props_swf8` | 87.6% | 184/210 | 210 | 210 |  |
| 7 | `xml_first_last_child` | 87.5% | 7/8 | 8 | 8 |  |
| 8 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 |  |
| 9 | `textfield_props_swf6` | 86.2% | 181/210 | 210 | 210 |  |
| 10 | `function_suppress_and_preload` | 85.7% | 24/28 | 28 | 28 |  |
| 11 | `swf4_function_calls` | 85.7% | 6/7 | 7 | 7 |  |
| 12 | `textfield_props_swf7` | 85.2% | 179/210 | 210 | 210 |  |
| 13 | `object_prototypes` | 83.8% | 62/74 | 73 | 74 |  |
| 14 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 15 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 |  |
| 16 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 17 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 18 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 19 | `movieclip_depth_methods` | 77.6% | 76/98 | 98 | 98 |  |
| 20 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 21 | `as2_oop` | 76.9% | 10/13 | 13 | 13 |  |
| 22 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 |  |
| 23 | `string_paths_basic` | 75.0% | 3/4 | 4 | 4 |  |
| 24 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 25 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 26 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 |  |
| 27 | `array_sort` | 72.0% | 116/161 | 161 | 161 |  |
| 28 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 29 | `stage_object_properties_swf6` | 71.9% | 166/231 | 231 | 231 |  |
| 30 | `stage_object_properties` | 71.8% | 173/241 | 241 | 241 |  |
| 31 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 |  |
| 32 | `transform` | 71.4% | 50/70 | 70 | 70 |  |
| 33 | `globals_swf6` | 71.4% | 217/304 | 304 | 304 |  |
| 34 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 35 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 36 | `globals_swf7` | 70.4% | 214/304 | 304 | 304 |  |
| 37 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 38 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 39 | `globals_swf5` | 69.1% | 210/304 | 304 | 304 |  |
| 40 | `xml_clone_expandos` | 68.4% | 13/19 | 19 | 19 |  |
| 41 | `as_set_prop_flags` | 68.4% | 54/79 | 76 | 79 |  |
| 42 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 43 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 44 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 |  |
| 45 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 46 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 47 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 48 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 49 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 50 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 51 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 |  |
| 52 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 53 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 54 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 55 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 56 | `xml_append_child` | 64.3% | 18/28 | 28 | 28 |  |
| 57 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 |  |
| 58 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 |  |
| 59 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 |  |
| 60 | `as_set_prop_flags_version` | 61.3% | 19/31 | 29 | 31 |  |
| 61 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 62 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 63 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 64 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 65 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 66 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 67 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 68 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 69 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 70 | `boxed_primitives` | 58.3% | 14/24 | 24 | 24 |  |
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
| 82 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 83 | `globals_swf8` | 51.0% | 155/304 | 304 | 304 |  |
| 84 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 |  |
| 85 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 86 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 87 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 88 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 89 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 90 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 91 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 |  |
| 92 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 93 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 94 | `xml_siblings` | 50.0% | 5/10 | 10 | 10 |  |
| 95 | `edittext_html_swf6` | 49.1% | 2640/5377 | 5377 | 5377 |  |
| 96 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 97 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 98 | `textfield_props_swf5` | 48.0% | 84/175 | 141 | 175 |  |
| 99 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 100 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 |  |
| 101 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 102 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 103 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 104 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 105 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 106 | `edittext_html_swf7` | 42.2% | 2268/5377 | 5377 | 5377 |  |
| 107 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 |  |
| 108 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 |  |
| 109 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 |  |
| 110 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 111 | `edittext_html_swf8` | 39.4% | 2118/5377 | 5377 | 5377 |  |
| 112 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 113 | `localconnection_properties` | 37.5% | 3/8 | 3 | 8 |  |
| 114 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 |  |
| 115 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 116 | `xml_remove_node` | 36.4% | 8/22 | 22 | 22 |  |
| 117 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 118 | `array_call_method` | 33.3% | 3/9 | 5 | 9 |  |
| 119 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 120 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 121 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 122 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 123 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 124 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 125 | `string_paths_other` | 30.6% | 11/36 | 28 | 36 |  |
| 126 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 127 | `xml_insert_before` | 30.0% | 6/20 | 20 | 20 |  |
| 128 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 129 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 |  |
| 130 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 131 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 132 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 133 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 134 | `xml_child_nodes_edge_cases` | 25.0% | 1/4 | 4 | 4 |  |
| 135 | `edittext_stylesheet` | 24.3% | 79/325 | 325 | 325 |  |
| 136 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 137 | `xml_to_string` | 23.1% | 3/13 | 7 | 13 |  |
| 138 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 139 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 140 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 |  |
| 141 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 142 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 143 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 144 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 145 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 146 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 |  |
| 147 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 148 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 149 | `unload` | 15.4% | 8/52 | 48 | 52 |  |
| 150 | `watch` | 15.4% | 18/117 | 101 | 117 |  |
| 151 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 152 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 153 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 154 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 155 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 156 | `path_string` | 14.0% | 45/322 | 299 | 322 |  |
| 157 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 158 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 159 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 160 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 161 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 162 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 163 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 164 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 165 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 166 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 167 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 168 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 169 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 170 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 |  |
| 171 | `extends_chain` | 9.0% | 12/134 | 122 | 134 |  |
| 172 | `instanceof_coercions` | 8.0% | 7/88 | 70 | 88 |  |
| 173 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 174 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 175 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 176 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 177 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 178 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 179 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 180 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 181 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 182 | `as2_super_and_this_v6` | 6.2% | 6/97 | 17 | 97 |  |
| 183 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 184 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 185 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 186 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 187 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 188 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 189 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 190 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 |  |
| 191 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 192 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 193 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 194 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 |  |
| 195 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 196 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 197 | `asnew` | 2.9% | 1/34 | 3 | 34 |  |
| 198 | `as2_super_and_this_v8` | 2.4% | 2/85 | 9 | 85 |  |
| 199 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 200 | `math_swf6` | 1.9% | 10/530 | 458 | 530 |  |
| 201 | `math_swf7` | 1.9% | 10/530 | 458 | 530 |  |
| 202 | `math_swf8` | 1.9% | 10/530 | 458 | 530 |  |
| 203 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 204 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 205 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 206 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 207 | `global_instance_decls` | 0.1% | 1/758 | 141 | 758 |  |
| 208 | `global_proto_decls` | 0.1% | 4/4497 | 95 | 4497 |  |
| 209 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 210 | `array_sort_random` | 0.0% | 0/443 | 2 | 443 |  |
| 211 | `as_set_prop_flags_version_swf5` | 0.0% | 0/1 | 1 | 1 |  |
| 212 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 213 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 214 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 215 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 216 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 217 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 218 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 219 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 220 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 221 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 222 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 223 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 224 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 225 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 226 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 227 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 228 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 229 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 230 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 |  |
| 231 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 232 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 233 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 234 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 235 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 236 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 237 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 238 | `global_proto_decls_delete` | 0.0% | 0/4158 | 24 | 4158 |  |
| 239 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 240 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 241 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 242 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 243 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 244 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 245 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 246 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 247 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 248 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 249 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 250 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 251 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 252 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 253 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 254 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 255 | `native_objects_swf6` | 0.0% | 0/186 | 186 | 84 |  |
| 256 | `native_objects_swf7` | 0.0% | 0/186 | 186 | 84 |  |
| 257 | `native_objects_swf8` | 0.0% | 0/186 | 186 | 84 |  |
| 258 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 259 | `object_resolve` | 0.0% | 0/38 | 23 | 38 |  |
| 260 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 261 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 262 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 263 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 264 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 265 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 266 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 267 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 268 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 269 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 270 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 271 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 272 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 273 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 274 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 275 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 276 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 277 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 278 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 279 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 280 | `swf5_global_funcs` | 0.0% | 0/232 | 0 | 232 |  |
| 281 | `swf6_global_funcs` | 0.0% | 0/232 | 0 | 232 |  |
| 282 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 283 | `swf7_global_funcs` | 0.0% | 0/232 | 0 | 232 |  |
| 284 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 285 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 286 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 287 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 288 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 289 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 290 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 291 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 292 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 293 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 294 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
