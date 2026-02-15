# Ruffle Test Results (Filtered)

**Date**: 2026-02-15 05:15 UTC

**Git SHA**: `6395c58948`

**Run Duration**: 44m 43s

**Filtered**: 137 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 482 |
| Passing | **166** (34.4%) |
| Failing | 316 |
| Total expected lines | 77736 |
| Matching lines | 40639 (52.3%) |
| Mismatched lines | 37097 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 307 | 97.2% |
| Segfault | 6 | 1.9% |
| Timeout | 3 | 0.9% |

## Passing Tests

**166 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 4.3s |  |
| 2 | `action_to_integer` | 28 | 4.0s |  |
| 3 | `add` | 28 | 4.0s |  |
| 4 | `add2` | 354 | 4.2s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 3.9s |  |
| 6 | `add_swf5` | 28 | 4.0s |  |
| 7 | `array_concat` | 98 | 4.0s |  |
| 8 | `array_constructor` | 30 | 4.0s |  |
| 9 | `array_length` | 42 | 4.0s |  |
| 10 | `array_properties` | 36 | 4.1s |  |
| 11 | `array_slice` | 34 | 4.1s |  |
| 12 | `array_splice` | 207 | 4.2s |  |
| 13 | `array_trivial` | 209 | 4.1s |  |
| 14 | `as1_constructor_v6` | 35 | 4.0s |  |
| 15 | `as1_constructor_v7` | 35 | 4.0s |  |
| 16 | `as_broadcaster_initialize` | 10 | 3.9s |  |
| 17 | `as_transformed_flag` | 20 | 4.0s |  |
| 18 | `bad_swf_tag_past_eof` | 0 | 3.9s |  |
| 19 | `bitand` | 1058 | 6.5s |  |
| 20 | `bitmap_data_colortransform` | 0 | 4.2s |  |
| 21 | `bitmap_data_fillrect` | 0 | 4.1s |  |
| 22 | `bitmap_data_max_size_swf10` | 12 | 4.0s |  |
| 23 | `bitmap_data_max_size_swf9` | 10 | 4.0s |  |
| 24 | `bitmap_data_perlinnoise` | 0 | 4.6s |  |
| 25 | `bitmap_data_pixeldissolve_image` | 0 | 4.5s |  |
| 26 | `bitmapdata_applyfilter_colormatrix` | 0 | 4.2s |  |
| 27 | `bitor` | 1058 | 6.6s |  |
| 28 | `biturshift` | 14 | 4.4s |  |
| 29 | `biturshift_swf8` | 14 | 4.0s |  |
| 30 | `bitxor` | 1058 | 6.8s |  |
| 31 | `call_method_empty_name` | 1 | 4.1s |  |
| 32 | `capabilities_resolution` | 8 | 4.0s |  |
| 33 | `catch_references_registers` | 2 | 4.1s |  |
| 34 | `conflicting_instance_names` | 23 | 4.2s |  |
| 35 | `define_function2` | 8 | 4.1s |  |
| 36 | `define_function2_preload` | 13 | 4.1s |  |
| 37 | `define_function2_preload_order` | 4 | 4.2s |  |
| 38 | `define_function_case_sensitive` | 2 | 4.1s |  |
| 39 | `delete` | 3 | 4.2s |  |
| 40 | `display_object_properties` | 2 | 4.1s |  |
| 41 | `do_init_action` | 3 | 4.1s |  |
| 42 | `edittext_autosize_setter` | 20 | 4.0s |  |
| 43 | `equals` | 32 | 4.0s |  |
| 44 | `equals2_swf5` | 926 | 5.7s |  |
| 45 | `equals2_swf6` | 926 | 5.6s |  |
| 46 | `equals2_swf7` | 926 | 5.7s |  |
| 47 | `equals_swf4` | 665 | 4.4s |  |
| 48 | `equals_swf4_alt` | 32 | 3.9s |  |
| 49 | `equals_swf5` | 32 | 4.0s |  |
| 50 | `escape` | 14 | 3.9s |  |
| 51 | `execution_order1` | 5 | 4.0s |  |
| 52 | `execution_order2` | 7 | 4.0s |  |
| 53 | `execution_order3` | 4 | 4.0s |  |
| 54 | `focusrect_mouse_swf8` | 0 | 3.9s |  |
| 55 | `focusrect_mouse_swf9` | 0 | 3.9s |  |
| 56 | `focusrect_swf5` | 6 | 4.1s |  |
| 57 | `getproperty` | 28 | 3.9s |  |
| 58 | `getproperty_swf4` | 28 | 3.9s |  |
| 59 | `getproperty_swf5` | 28 | 3.9s |  |
| 60 | `global_array` | 3 | 3.9s |  |
| 61 | `global_is_bare` | 7 | 3.9s |  |
| 62 | `goto_advance1` | 6 | 3.9s |  |
| 63 | `goto_advance2` | 2 | 4.0s |  |
| 64 | `goto_both_ways1` | 3 | 5.7s |  |
| 65 | `goto_both_ways2` | 3 | 4.1s |  |
| 66 | `goto_execution_order` | 2 | 4.0s |  |
| 67 | `goto_execution_order2` | 2 | 4.0s |  |
| 68 | `goto_frame_number` | 3 | 4.1s |  |
| 69 | `goto_rewind1` | 1 | 4.1s |  |
| 70 | `goto_rewind2` | 3 | 4.2s |  |
| 71 | `goto_rewind3` | 2 | 4.0s |  |
| 72 | `greater_swf6` | 1175 | 6.2s |  |
| 73 | `greater_swf7` | 1175 | 6.2s |  |
| 74 | `greaterthan_swf5` | 1 | 4.1s |  |
| 75 | `greaterthan_swf8` | 1 | 4.1s |  |
| 76 | `has_own_property` | 32 | 4.1s |  |
| 77 | `infinite_recursion_function` | 4 | 4.0s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 78 | `infinite_recursion_function_in_setter` | 131 | 4.0s |  |
| 79 | `infinite_recursion_virtual_property` | 67 | 4.0s |  |
| 80 | `init_array_invalid` | 4 | 4.0s |  |
| 81 | `init_object_invalid` | 4 | 3.9s |  |
| 82 | `issue_1086` | 1 | 4.0s |  |
| 83 | `issue_1671` | 0 | 4.0s |  |
| 84 | `issue_2166` | 9 | 4.1s |  |
| 85 | `issue_3446` | 1 | 4.1s |  |
| 86 | `issue_4377` | 2 | 4.1s |  |
| 87 | `issue_710` | 4 | 4.1s |  |
| 88 | `issue_768` | 3 | 4.1s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 89 | `lessthan` | 41 | 4.1s |  |
| 90 | `lessthan2_swf5` | 1226 | 6.4s |  |
| 91 | `lessthan2_swf6` | 1226 | 6.4s |  |
| 92 | `lessthan2_swf7` | 1226 | 6.4s |  |
| 93 | `lessthan_swf4` | 902 | 4.8s |  |
| 94 | `lessthan_swf4_alt` | 41 | 4.1s |  |
| 95 | `lessthan_swf5` | 41 | 4.1s |  |
| 96 | `logical_ops_swf4` | 90 | 4.3s |  |
| 97 | `logical_ops_swf8` | 108 | 4.4s |  |
| 98 | `looping` | 6 | 4.2s |  |
| 99 | `mask_reapply` | 0 | 4.1s |  |
| 100 | `mask_with_drawing` | 0 | 4.2s |  |
| 101 | `movieclip_begin_gradient_fill` | 0 | 4.8s |  |
| 102 | `movieclip_blend_mode_property` | 35 | 4.2s |  |
| 103 | `movieclip_line_gradient_style` | 0 | 4.3s |  |
| 104 | `movieclip_name_from_timeline` | 13 | 3.9s |  |
| 105 | `movieclip_prototype_extension` | 5 | 3.9s |  |
| 106 | `nested_textfields_in_buttons` | 0 | 3.9s |  |
| 107 | `netstream_play_flv_screen` | 0 | 16.8s |  |
| 108 | `new_method_wrap` | 4 | 3.9s |  |
| 109 | `new_object_wrap` | 4 | 3.9s |  |
| 110 | `o` | 3 | 3.9s |  |
| 111 | `object_function` | 32 | 4.0s |  |
| 112 | `object_string_coerce_swf5` | 62 | 4.0s |  |
| 113 | `primitive_instanceof` | 37 | 4.0s |  |
| 114 | `prototype_delete` | 12 | 4.0s |  |
| 115 | `recursive_prototypes` | 0 | 4.0s |  |
| 116 | `set_variable_scope` | 58 | 4.0s |  |
| 117 | `single_frame` | 1 | 3.9s |  |
| 118 | `sound_start_load` | 0 | 4.0s |  |
| 119 | `stage_object_properties_get_var` | 5 | 4.0s |  |
| 120 | `strictequals_swf6` | 902 | 5.5s |  |
| 121 | `strictly_equals` | 7 | 4.0s |  |
| 122 | `string_methods_negative_args` | 240 | 4.1s |  |
| 123 | `string_methods_swfv5` | 275 | 4.5s |  |
| 124 | `string_paths_keyevents` | 0 | 4.0s |  |
| 125 | `string_paths_timer` | 0 | 4.0s |  |
| 126 | `swf4_actions_bool` | 96 | 4.0s |  |
| 127 | `swf4_bool` | 4 | 3.9s |  |
| 128 | `swf5_encoding` | 3 | 3.9s |  |
| 129 | `tab_ordering_properties_tab_index_edge_case` | 4 | 3.9s |  |
| 130 | `text_format` | 1146 | 4.2s |  |
| 131 | `text_format_font_max_length` | 2 | 3.9s |  |
| 132 | `text_format_rounding_swf7` | 840 | 4.0s |  |
| 133 | `text_format_rounding_swf8` | 840 | 4.0s |  |
| 134 | `textfield_background_color` | 11 | 3.9s |  |
| 135 | `textfield_border_color` | 11 | 3.9s |  |
| 136 | `textfield_maxchars` | 3 | 3.9s |  |
| 137 | `this_swf7` | 41 | 3.9s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 138 | `timeline_function_def` | 7 | 4.0s |  |
| 139 | `try_finally_simple` | 16 | 4.0s |  |
| 140 | `typeof` | 22 | 4.1s |  |
| 141 | `typeof_globals` | 7 | 3.9s |  |
| 142 | `uncaught_exception` | 1 | 3.9s |  |
| 143 | `uncaught_exception_bubbled` | 1 | 3.9s |  |
| 144 | `undefined_to_string_swf6` | 4 | 3.9s |  |
| 145 | `unescape` | 43 | 3.9s |  |
| 146 | `use_hand_cursor` | 8 | 3.9s |  |
| 147 | `variable_args` | 5 | 4.0s |  |
| 148 | `waitforframe` | 7 | 3.9s |  |
| 149 | `waitforframe2` | 16 | 4.0s |  |
| 150 | `with_return` | 2 | 3.9s |  |
| 151 | `xml` | 15 | 3.9s |  |
| 152 | `xml_attributes_read` | 4 | 3.9s |  |
| 153 | `xml_cdata` | 11 | 3.9s |  |
| 154 | `xml_has_child_nodes` | 3 | 3.9s |  |
| 155 | `xml_idmap` | 21 | 4.0s |  |
| 156 | `xml_ignore_comments` | 21 | 4.0s |  |
| 157 | `xml_ignore_white` | 34 | 3.9s |  |
| 158 | `xml_inspect_createmethods` | 15 | 3.9s |  |
| 159 | `xml_inspect_doctype` | 7 | 3.9s |  |
| 160 | `xml_inspect_parsexml` | 62 | 3.9s |  |
| 161 | `xml_inspect_xmldecl` | 7 | 3.9s |  |
| 162 | `xml_namespaces` | 203 | 3.9s |  |
| 163 | `xml_reparenting` | 14 | 4.0s |  |
| 164 | `xml_to_string_comment` | 1 | 3.9s |  |
| 165 | `xml_unescaping` | 23 | 4.0s |  |
| 166 | `xmlnode_proto` | 1 | 3.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**105 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `string_coercion` | 99.1% | 116 | 117 | 1 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 2 | `string_methods` | 98.9% | 282 | 285 | 3 |  |
| 3 | `edittext_antialiastype` | 98.3% | 291 | 296 | 5 |  |
| 4 | `textfield_properties` | 97.7% | 43 | 44 | 1 |  |
| 5 | `object_constructor` | 97.0% | 32 | 33 | 1 |  |
| 6 | `edittext_default_format_empty` | 95.8% | 91 | 95 | 4 |  |
| 7 | `edittext_default_format` | 94.6% | 209 | 221 | 12 |  |
| 8 | `edittext_width_height` | 94.2% | 97 | 103 | 6 |  |
| 9 | `get_variable_in_scope` | 93.1% | 27 | 29 | 2 |  |
| 10 | `movieclip_default_state` | 92.8% | 64 | 69 | 5 |  |
| 11 | `swf7_case_sensitive` | 90.9% | 40 | 44 | 4 |  |
| 12 | `edittext_default_format_font_style` | 90.4% | 303 | 335 | 32 |  |
| 13 | `divide_swf4` | 88.8% | 95 | 107 | 12 |  |
| 14 | `textfield_props_swf8` | 87.6% | 184 | 210 | 26 |  |
| 15 | `xml_first_last_child` | 87.5% | 7 | 8 | 1 |  |
| 16 | `error` | 86.2% | 50 | 58 | 8 |  |
| 17 | `textfield_props_swf6` | 86.2% | 181 | 210 | 29 |  |
| 18 | `function_suppress_and_preload` | 85.7% | 24 | 28 | 4 |  |
| 19 | `swf4_function_calls` | 85.7% | 6 | 7 | 1 |  |
| 20 | `textfield_text` | 85.7% | 6 | 7 | 1 |  |
| 21 | `textfield_props_swf7` | 85.2% | 179 | 210 | 31 |  |
| 22 | `object_prototypes` | 83.8% | 62 | 74 | 12 |  |
| 23 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 24 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 25 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 26 | `textfield_variable` | 79.0% | 64 | 81 | 17 |  |
| 27 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 28 | `movieclip_depth_methods` | 77.6% | 76 | 98 | 22 |  |
| 29 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 30 | `as2_oop` | 76.9% | 10 | 13 | 3 |  |
| 31 | `edittext_html_align_swf7` | 76.9% | 40 | 52 | 12 |  |
| 32 | `edittext_html_align_swf8` | 76.9% | 40 | 52 | 12 |  |
| 33 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 |  |
| 34 | `string_paths_basic` | 75.0% | 3 | 4 | 1 |  |
| 35 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 36 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 37 | `extends_native_type` | 72.7% | 8 | 11 | 3 |  |
| 38 | `array_sort` | 72.0% | 116 | 161 | 45 |  |
| 39 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 40 | `stage_object_properties_swf6` | 71.9% | 166 | 231 | 65 |  |
| 41 | `stage_object_properties` | 71.8% | 173 | 241 | 68 |  |
| 42 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 |  |
| 43 | `globals_swf6` | 71.4% | 217 | 304 | 87 |  |
| 44 | `point` | 70.9% | 124 | 175 | 51 |  |
| 45 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 46 | `globals_swf7` | 70.4% | 214 | 304 | 90 |  |
| 47 | `transform` | 70.0% | 49 | 70 | 21 |  |
| 48 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 49 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 50 | `globals_swf5` | 69.1% | 210 | 304 | 94 |  |
| 51 | `xml_clone_expandos` | 68.4% | 13 | 19 | 6 |  |
| 52 | `as_set_prop_flags` | 68.4% | 54 | 79 | 25 |  |
| 53 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 54 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 55 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 |  |
| 56 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 57 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 58 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 59 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 60 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 61 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 62 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 |  |
| 63 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 64 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 65 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 66 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 67 | `xml_append_child` | 64.3% | 18 | 28 | 10 |  |
| 68 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 |  |
| 69 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 |  |
| 70 | `edittext_autosize` | 62.0% | 44 | 71 | 27 |  |
| 71 | `as_set_prop_flags_version` | 61.3% | 19 | 31 | 12 |  |
| 72 | `with` | 61.2% | 30 | 49 | 19 |  |
| 73 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 74 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 75 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 76 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 77 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 78 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 79 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 80 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 81 | `boxed_primitives` | 58.3% | 14 | 24 | 10 |  |
| 82 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 83 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 84 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 |  |
| 85 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 86 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 87 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 88 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 89 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 |  |
| 90 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 |  |
| 91 | `clone_sprite_types` | 54.2% | 13 | 24 | 11 |  |
| 92 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 |  |
| 93 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 94 | `globals_swf8` | 51.0% | 155 | 304 | 149 |  |
| 95 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 |  |
| 96 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 97 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 98 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 99 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 100 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 101 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 102 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 |  |
| 103 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 104 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 105 | `xml_siblings` | 50.0% | 5 | 10 | 5 |  |

## Segfaults

**6 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 9.3s |  |
| 2 | `enumerate` | 6.0s |  |
| 3 | `goto_methods` | 6.2s |  |
| 4 | `init_object_order` | 6.1s |  |
| 5 | `register_and_init_order` | 6.4s |  |
| 6 | `register_class` | 6.2s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**3 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 14.8s |  |
| 2 | `timeout` | runtime timeout (>10s) | 14.2s |  |
| 3 | `try_catch_finally` | runtime timeout (>10s) | 14.2s |  |

## All Output Mismatches

**307 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `string_coercion` | 99.1% | 116/117 | 117 | 117 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 2 | `string_methods` | 98.9% | 282/285 | 285 | 285 |  |
| 3 | `edittext_antialiastype` | 98.3% | 291/296 | 296 | 296 |  |
| 4 | `textfield_properties` | 97.7% | 43/44 | 44 | 44 |  |
| 5 | `object_constructor` | 97.0% | 32/33 | 33 | 33 |  |
| 6 | `edittext_default_format_empty` | 95.8% | 91/95 | 95 | 95 |  |
| 7 | `edittext_default_format` | 94.6% | 209/221 | 221 | 221 |  |
| 8 | `edittext_width_height` | 94.2% | 97/103 | 103 | 103 |  |
| 9 | `get_variable_in_scope` | 93.1% | 27/29 | 29 | 29 |  |
| 10 | `movieclip_default_state` | 92.8% | 64/69 | 69 | 69 |  |
| 11 | `swf7_case_sensitive` | 90.9% | 40/44 | 44 | 44 |  |
| 12 | `edittext_default_format_font_style` | 90.4% | 303/335 | 335 | 335 |  |
| 13 | `divide_swf4` | 88.8% | 95/107 | 107 | 107 |  |
| 14 | `textfield_props_swf8` | 87.6% | 184/210 | 210 | 210 |  |
| 15 | `xml_first_last_child` | 87.5% | 7/8 | 8 | 8 |  |
| 16 | `error` | 86.2% | 50/58 | 58 | 58 |  |
| 17 | `textfield_props_swf6` | 86.2% | 181/210 | 210 | 210 |  |
| 18 | `function_suppress_and_preload` | 85.7% | 24/28 | 28 | 28 |  |
| 19 | `swf4_function_calls` | 85.7% | 6/7 | 7 | 7 |  |
| 20 | `textfield_text` | 85.7% | 6/7 | 7 | 7 |  |
| 21 | `textfield_props_swf7` | 85.2% | 179/210 | 210 | 210 |  |
| 22 | `object_prototypes` | 83.8% | 62/74 | 73 | 74 |  |
| 23 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 24 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 25 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 26 | `textfield_variable` | 79.0% | 64/81 | 81 | 81 |  |
| 27 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 28 | `movieclip_depth_methods` | 77.6% | 76/98 | 98 | 98 |  |
| 29 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 30 | `as2_oop` | 76.9% | 10/13 | 13 | 13 |  |
| 31 | `edittext_html_align_swf7` | 76.9% | 40/52 | 52 | 52 |  |
| 32 | `edittext_html_align_swf8` | 76.9% | 40/52 | 52 | 52 |  |
| 33 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 |  |
| 34 | `string_paths_basic` | 75.0% | 3/4 | 4 | 4 |  |
| 35 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 36 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 37 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 |  |
| 38 | `array_sort` | 72.0% | 116/161 | 161 | 161 |  |
| 39 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 40 | `stage_object_properties_swf6` | 71.9% | 166/231 | 231 | 231 |  |
| 41 | `stage_object_properties` | 71.8% | 173/241 | 241 | 241 |  |
| 42 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 |  |
| 43 | `globals_swf6` | 71.4% | 217/304 | 304 | 304 |  |
| 44 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 45 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 46 | `globals_swf7` | 70.4% | 214/304 | 304 | 304 |  |
| 47 | `transform` | 70.0% | 49/70 | 70 | 70 |  |
| 48 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 49 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 50 | `globals_swf5` | 69.1% | 210/304 | 304 | 304 |  |
| 51 | `xml_clone_expandos` | 68.4% | 13/19 | 19 | 19 |  |
| 52 | `as_set_prop_flags` | 68.4% | 54/79 | 76 | 79 |  |
| 53 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 54 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 55 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 |  |
| 56 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 57 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 58 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 59 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 60 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 61 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 62 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 |  |
| 63 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 64 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 65 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 66 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 67 | `xml_append_child` | 64.3% | 18/28 | 28 | 28 |  |
| 68 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 |  |
| 69 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 |  |
| 70 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 |  |
| 71 | `as_set_prop_flags_version` | 61.3% | 19/31 | 29 | 31 |  |
| 72 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 73 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 74 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 75 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 76 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 77 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 78 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 79 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 80 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 81 | `boxed_primitives` | 58.3% | 14/24 | 24 | 24 |  |
| 82 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 83 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 84 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 |  |
| 85 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 86 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 87 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 88 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 89 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 |  |
| 90 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 |  |
| 91 | `clone_sprite_types` | 54.2% | 13/24 | 24 | 24 |  |
| 92 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 |  |
| 93 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 94 | `globals_swf8` | 51.0% | 155/304 | 304 | 304 |  |
| 95 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 |  |
| 96 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 97 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 98 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 99 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 100 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 101 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 102 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 |  |
| 103 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 104 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 105 | `xml_siblings` | 50.0% | 5/10 | 10 | 10 |  |
| 106 | `edittext_html_swf6` | 49.1% | 2640/5377 | 5377 | 5377 |  |
| 107 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 108 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 109 | `textfield_props_swf5` | 48.0% | 84/175 | 141 | 175 |  |
| 110 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 111 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 112 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 |  |
| 113 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 114 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 115 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 116 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 117 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 118 | `edittext_html_swf7` | 42.2% | 2268/5377 | 5377 | 5377 |  |
| 119 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 |  |
| 120 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 |  |
| 121 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 |  |
| 122 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 123 | `edittext_html_swf8` | 39.4% | 2118/5377 | 5377 | 5377 |  |
| 124 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 125 | `localconnection_properties` | 37.5% | 3/8 | 3 | 8 |  |
| 126 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 |  |
| 127 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 128 | `xml_remove_node` | 36.4% | 8/22 | 22 | 22 |  |
| 129 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 130 | `array_call_method` | 33.3% | 3/9 | 5 | 9 |  |
| 131 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 132 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 133 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 134 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 135 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 136 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 137 | `string_paths_other` | 30.6% | 11/36 | 28 | 36 |  |
| 138 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 139 | `xml_insert_before` | 30.0% | 6/20 | 20 | 20 |  |
| 140 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 141 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 |  |
| 142 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 143 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 144 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 145 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 146 | `xml_child_nodes_edge_cases` | 25.0% | 1/4 | 4 | 4 |  |
| 147 | `edittext_stylesheet` | 24.3% | 79/325 | 325 | 325 |  |
| 148 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 149 | `xml_to_string` | 23.1% | 3/13 | 7 | 13 |  |
| 150 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 151 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 152 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 |  |
| 153 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 154 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 155 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 156 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 157 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 158 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 |  |
| 159 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 160 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 161 | `unload` | 15.4% | 8/52 | 48 | 52 |  |
| 162 | `watch` | 15.4% | 18/117 | 101 | 117 |  |
| 163 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 164 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 165 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 166 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 167 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 168 | `path_string` | 14.0% | 45/322 | 299 | 322 |  |
| 169 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 170 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 171 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 172 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 173 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 174 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 175 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 176 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 177 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 178 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 179 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 180 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 181 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 182 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 |  |
| 183 | `extends_chain` | 9.0% | 12/134 | 122 | 134 |  |
| 184 | `instanceof_coercions` | 8.0% | 7/88 | 70 | 88 |  |
| 185 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 186 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 187 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 188 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 189 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 190 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 191 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 192 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 193 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 194 | `as2_super_and_this_v6` | 6.2% | 6/97 | 17 | 97 |  |
| 195 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 196 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 197 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 198 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 199 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 200 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 201 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 202 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 |  |
| 203 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 204 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 205 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 206 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 |  |
| 207 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 208 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 209 | `asnew` | 2.9% | 1/34 | 3 | 34 |  |
| 210 | `as2_super_and_this_v8` | 2.4% | 2/85 | 9 | 85 |  |
| 211 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 212 | `math_swf6` | 1.9% | 10/530 | 458 | 530 |  |
| 213 | `math_swf7` | 1.9% | 10/530 | 458 | 530 |  |
| 214 | `math_swf8` | 1.9% | 10/530 | 458 | 530 |  |
| 215 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 216 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 217 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 218 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 219 | `global_instance_decls` | 0.1% | 1/758 | 141 | 758 |  |
| 220 | `global_proto_decls` | 0.1% | 4/4497 | 95 | 4497 |  |
| 221 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 222 | `array_sort_random` | 0.0% | 0/443 | 2 | 443 |  |
| 223 | `as_set_prop_flags_version_swf5` | 0.0% | 0/1 | 1 | 1 |  |
| 224 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 225 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 226 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 227 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 228 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 229 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 230 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 231 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 232 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 233 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 234 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 235 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 236 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 237 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 238 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 239 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 240 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 241 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 242 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 |  |
| 243 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 244 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 245 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 246 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 247 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 248 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 249 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 250 | `global_proto_decls_delete` | 0.0% | 0/4158 | 24 | 4158 |  |
| 251 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 252 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 253 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 254 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 255 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 256 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 257 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 258 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 259 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 260 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 261 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 262 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 263 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 264 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 265 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 266 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 267 | `native_objects_swf6` | 0.0% | 0/186 | 186 | 84 |  |
| 268 | `native_objects_swf7` | 0.0% | 0/186 | 186 | 84 |  |
| 269 | `native_objects_swf8` | 0.0% | 0/186 | 186 | 84 |  |
| 270 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 271 | `object_resolve` | 0.0% | 0/38 | 23 | 38 |  |
| 272 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 273 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 274 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 275 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 276 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 277 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 278 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 279 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 280 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 281 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 282 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 283 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 284 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 285 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 286 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 287 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 288 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 289 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 290 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 291 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 292 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 293 | `swf5_global_funcs` | 0.0% | 0/232 | 0 | 232 |  |
| 294 | `swf6_global_funcs` | 0.0% | 0/232 | 0 | 232 |  |
| 295 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 296 | `swf7_global_funcs` | 0.0% | 0/232 | 0 | 232 |  |
| 297 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 298 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 299 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 300 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 301 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 302 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 303 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 304 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 305 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 306 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 307 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
