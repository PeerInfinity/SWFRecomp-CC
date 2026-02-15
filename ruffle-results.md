# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-15 05:15 UTC

**Git SHA**: `6395c58948`

**Run Duration**: 44m 43s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **167** (27.0%) |
| Failing | 452 |
| Total expected lines | 91220 |
| Matching lines | 41717 (45.7%) |
| Mismatched lines | 49503 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 442 | 97.8% |
| Runtime Segfault | 7 | 1.5% |
| Timeout | 3 | 0.7% |

## Passing Tests

**167 tests passing**

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
| 101 | `mouse_wheel_enabled` | 2 | 4.2s |  |
| 102 | `movieclip_begin_gradient_fill` | 0 | 4.8s |  |
| 103 | `movieclip_blend_mode_property` | 35 | 4.2s |  |
| 104 | `movieclip_line_gradient_style` | 0 | 4.3s |  |
| 105 | `movieclip_name_from_timeline` | 13 | 3.9s |  |
| 106 | `movieclip_prototype_extension` | 5 | 3.9s |  |
| 107 | `nested_textfields_in_buttons` | 0 | 3.9s |  |
| 108 | `netstream_play_flv_screen` | 0 | 16.8s |  |
| 109 | `new_method_wrap` | 4 | 3.9s |  |
| 110 | `new_object_wrap` | 4 | 3.9s |  |
| 111 | `o` | 3 | 3.9s |  |
| 112 | `object_function` | 32 | 4.0s |  |
| 113 | `object_string_coerce_swf5` | 62 | 4.0s |  |
| 114 | `primitive_instanceof` | 37 | 4.0s |  |
| 115 | `prototype_delete` | 12 | 4.0s |  |
| 116 | `recursive_prototypes` | 0 | 4.0s |  |
| 117 | `set_variable_scope` | 58 | 4.0s |  |
| 118 | `single_frame` | 1 | 3.9s |  |
| 119 | `sound_start_load` | 0 | 4.0s |  |
| 120 | `stage_object_properties_get_var` | 5 | 4.0s |  |
| 121 | `strictequals_swf6` | 902 | 5.5s |  |
| 122 | `strictly_equals` | 7 | 4.0s |  |
| 123 | `string_methods_negative_args` | 240 | 4.1s |  |
| 124 | `string_methods_swfv5` | 275 | 4.5s |  |
| 125 | `string_paths_keyevents` | 0 | 4.0s |  |
| 126 | `string_paths_timer` | 0 | 4.0s |  |
| 127 | `swf4_actions_bool` | 96 | 4.0s |  |
| 128 | `swf4_bool` | 4 | 3.9s |  |
| 129 | `swf5_encoding` | 3 | 3.9s |  |
| 130 | `tab_ordering_properties_tab_index_edge_case` | 4 | 3.9s |  |
| 131 | `text_format` | 1146 | 4.2s |  |
| 132 | `text_format_font_max_length` | 2 | 3.9s |  |
| 133 | `text_format_rounding_swf7` | 840 | 4.0s |  |
| 134 | `text_format_rounding_swf8` | 840 | 4.0s |  |
| 135 | `textfield_background_color` | 11 | 3.9s |  |
| 136 | `textfield_border_color` | 11 | 3.9s |  |
| 137 | `textfield_maxchars` | 3 | 3.9s |  |
| 138 | `this_swf7` | 41 | 3.9s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 139 | `timeline_function_def` | 7 | 4.0s |  |
| 140 | `try_finally_simple` | 16 | 4.0s |  |
| 141 | `typeof` | 22 | 4.1s |  |
| 142 | `typeof_globals` | 7 | 3.9s |  |
| 143 | `uncaught_exception` | 1 | 3.9s |  |
| 144 | `uncaught_exception_bubbled` | 1 | 3.9s |  |
| 145 | `undefined_to_string_swf6` | 4 | 3.9s |  |
| 146 | `unescape` | 43 | 3.9s |  |
| 147 | `use_hand_cursor` | 8 | 3.9s |  |
| 148 | `variable_args` | 5 | 4.0s |  |
| 149 | `waitforframe` | 7 | 3.9s |  |
| 150 | `waitforframe2` | 16 | 4.0s |  |
| 151 | `with_return` | 2 | 3.9s |  |
| 152 | `xml` | 15 | 3.9s |  |
| 153 | `xml_attributes_read` | 4 | 3.9s |  |
| 154 | `xml_cdata` | 11 | 3.9s |  |
| 155 | `xml_has_child_nodes` | 3 | 3.9s |  |
| 156 | `xml_idmap` | 21 | 4.0s |  |
| 157 | `xml_ignore_comments` | 21 | 4.0s |  |
| 158 | `xml_ignore_white` | 34 | 3.9s |  |
| 159 | `xml_inspect_createmethods` | 15 | 3.9s |  |
| 160 | `xml_inspect_doctype` | 7 | 3.9s |  |
| 161 | `xml_inspect_parsexml` | 62 | 3.9s |  |
| 162 | `xml_inspect_xmldecl` | 7 | 3.9s |  |
| 163 | `xml_namespaces` | 203 | 3.9s |  |
| 164 | `xml_reparenting` | 14 | 4.0s |  |
| 165 | `xml_to_string_comment` | 1 | 3.9s |  |
| 166 | `xml_unescaping` | 23 | 4.0s |  |
| 167 | `xmlnode_proto` | 1 | 3.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**118 tests** within reach

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
| 25 | `edittext_password` | 80.0% | 4 | 5 | 1 |  |
| 26 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 27 | `textfield_variable` | 79.0% | 64 | 81 | 17 |  |
| 28 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 29 | `movieclip_depth_methods` | 77.6% | 76 | 98 | 22 |  |
| 30 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 31 | `as2_oop` | 76.9% | 10 | 13 | 3 |  |
| 32 | `edittext_html_align_swf7` | 76.9% | 40 | 52 | 12 |  |
| 33 | `edittext_html_align_swf8` | 76.9% | 40 | 52 | 12 |  |
| 34 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 |  |
| 35 | `string_paths_basic` | 75.0% | 3 | 4 | 1 |  |
| 36 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 37 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 38 | `extends_native_type` | 72.7% | 8 | 11 | 3 |  |
| 39 | `array_sort` | 72.0% | 116 | 161 | 45 |  |
| 40 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 41 | `stage_object_properties_swf6` | 71.9% | 166 | 231 | 65 |  |
| 42 | `stage_object_properties` | 71.8% | 173 | 241 | 68 |  |
| 43 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 |  |
| 44 | `globals_swf6` | 71.4% | 217 | 304 | 87 |  |
| 45 | `point` | 70.9% | 124 | 175 | 51 |  |
| 46 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 47 | `globals_swf7` | 70.4% | 214 | 304 | 90 |  |
| 48 | `transform` | 70.0% | 49 | 70 | 21 |  |
| 49 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 50 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 51 | `globals_swf5` | 69.1% | 210 | 304 | 94 |  |
| 52 | `xml_clone_expandos` | 68.4% | 13 | 19 | 6 |  |
| 53 | `as_set_prop_flags` | 68.4% | 54 | 79 | 25 |  |
| 54 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 55 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 56 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 |  |
| 57 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 58 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 59 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 60 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 61 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 62 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 63 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 64 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 |  |
| 65 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 66 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 67 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 68 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 69 | `xml_append_child` | 64.3% | 18 | 28 | 10 |  |
| 70 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 |  |
| 71 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 |  |
| 72 | `edittext_autosize` | 62.0% | 44 | 71 | 27 |  |
| 73 | `as_set_prop_flags_version` | 61.3% | 19 | 31 | 12 |  |
| 74 | `with` | 61.2% | 30 | 49 | 19 |  |
| 75 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 76 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 77 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 78 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 79 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 80 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 81 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 82 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 83 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 84 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 85 | `boxed_primitives` | 58.3% | 14 | 24 | 10 |  |
| 86 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 87 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 88 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 89 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 |  |
| 90 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 91 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 92 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 93 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 94 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 |  |
| 95 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 |  |
| 96 | `clone_sprite_types` | 54.2% | 13 | 24 | 11 |  |
| 97 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 |  |
| 98 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 99 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 100 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 101 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 102 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 103 | `globals_swf8` | 51.0% | 155 | 304 | 149 |  |
| 104 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 |  |
| 105 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 106 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 107 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 108 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 109 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 110 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 111 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 112 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 113 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 114 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 |  |
| 115 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 116 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 117 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |
| 118 | `xml_siblings` | 50.0% | 5 | 10 | 5 |  |

## Segfaults

**7 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmap_data_pixeldissolve` | 11.1s |  |
| 2 | `device_font_spacing` | 9.3s |  |
| 3 | `enumerate` | 6.0s |  |
| 4 | `goto_methods` | 6.2s |  |
| 5 | `init_object_order` | 6.1s |  |
| 6 | `register_and_init_order` | 6.4s |  |
| 7 | `register_class` | 6.2s |  |

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

**442 tests** with output mismatch, sorted by match rate (best first)

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
| 25 | `edittext_password` | 80.0% | 4/5 | 5 | 5 |  |
| 26 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 27 | `textfield_variable` | 79.0% | 64/81 | 81 | 81 |  |
| 28 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 29 | `movieclip_depth_methods` | 77.6% | 76/98 | 98 | 98 |  |
| 30 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 31 | `as2_oop` | 76.9% | 10/13 | 13 | 13 |  |
| 32 | `edittext_html_align_swf7` | 76.9% | 40/52 | 52 | 52 |  |
| 33 | `edittext_html_align_swf8` | 76.9% | 40/52 | 52 | 52 |  |
| 34 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 |  |
| 35 | `string_paths_basic` | 75.0% | 3/4 | 4 | 4 |  |
| 36 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 37 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 38 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 |  |
| 39 | `array_sort` | 72.0% | 116/161 | 161 | 161 |  |
| 40 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 41 | `stage_object_properties_swf6` | 71.9% | 166/231 | 231 | 231 |  |
| 42 | `stage_object_properties` | 71.8% | 173/241 | 241 | 241 |  |
| 43 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 |  |
| 44 | `globals_swf6` | 71.4% | 217/304 | 304 | 304 |  |
| 45 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 46 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 47 | `globals_swf7` | 70.4% | 214/304 | 304 | 304 |  |
| 48 | `transform` | 70.0% | 49/70 | 70 | 70 |  |
| 49 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 50 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 51 | `globals_swf5` | 69.1% | 210/304 | 304 | 304 |  |
| 52 | `xml_clone_expandos` | 68.4% | 13/19 | 19 | 19 |  |
| 53 | `as_set_prop_flags` | 68.4% | 54/79 | 76 | 79 |  |
| 54 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 55 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 56 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 |  |
| 57 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 58 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 59 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 60 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 61 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 62 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 63 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 64 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 |  |
| 65 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 66 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 67 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 68 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 69 | `xml_append_child` | 64.3% | 18/28 | 28 | 28 |  |
| 70 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 |  |
| 71 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 |  |
| 72 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 |  |
| 73 | `as_set_prop_flags_version` | 61.3% | 19/31 | 29 | 31 |  |
| 74 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 75 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 76 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 77 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 78 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 79 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 80 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 81 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 82 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 83 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 84 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 85 | `boxed_primitives` | 58.3% | 14/24 | 24 | 24 |  |
| 86 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 87 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 88 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 89 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 |  |
| 90 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 91 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 92 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 93 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 94 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 |  |
| 95 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 |  |
| 96 | `clone_sprite_types` | 54.2% | 13/24 | 24 | 24 |  |
| 97 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 |  |
| 98 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 99 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 100 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 101 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 102 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 103 | `globals_swf8` | 51.0% | 155/304 | 304 | 304 |  |
| 104 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 |  |
| 105 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 106 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 107 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 108 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 109 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 110 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 111 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 112 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 113 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 114 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 |  |
| 115 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 116 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 117 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 118 | `xml_siblings` | 50.0% | 5/10 | 10 | 10 |  |
| 119 | `edittext_html_swf6` | 49.1% | 2640/5377 | 5377 | 5377 |  |
| 120 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 121 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 122 | `textfield_props_swf5` | 48.0% | 84/175 | 141 | 175 |  |
| 123 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 124 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 125 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 |  |
| 126 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 127 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 128 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 129 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 130 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 131 | `edittext_html_swf7` | 42.2% | 2268/5377 | 5377 | 5377 |  |
| 132 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 |  |
| 133 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 |  |
| 134 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 |  |
| 135 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 136 | `edittext_html_swf8` | 39.4% | 2118/5377 | 5377 | 5377 |  |
| 137 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 138 | `localconnection_properties` | 37.5% | 3/8 | 3 | 8 |  |
| 139 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 |  |
| 140 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 141 | `xml_remove_node` | 36.4% | 8/22 | 22 | 22 |  |
| 142 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 143 | `array_call_method` | 33.3% | 3/9 | 5 | 9 |  |
| 144 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 145 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 146 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 147 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 148 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 149 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 150 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 151 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 152 | `string_paths_other` | 30.6% | 11/36 | 28 | 36 |  |
| 153 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 154 | `xml_insert_before` | 30.0% | 6/20 | 20 | 20 |  |
| 155 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 156 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 157 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 |  |
| 158 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 159 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 160 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 161 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 162 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 163 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 164 | `xml_child_nodes_edge_cases` | 25.0% | 1/4 | 4 | 4 |  |
| 165 | `edittext_stylesheet` | 24.3% | 79/325 | 325 | 325 |  |
| 166 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 167 | `xml_to_string` | 23.1% | 3/13 | 7 | 13 |  |
| 168 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 169 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 170 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 |  |
| 171 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 172 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 173 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 174 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 175 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 176 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 177 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 178 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 |  |
| 179 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 180 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 181 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 182 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 183 | `unload` | 15.4% | 8/52 | 48 | 52 |  |
| 184 | `watch` | 15.4% | 18/117 | 101 | 117 |  |
| 185 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 186 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 187 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 188 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 189 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 190 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 191 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 192 | `path_string` | 14.0% | 45/322 | 299 | 322 |  |
| 193 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 194 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 195 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 196 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 197 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 198 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 199 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 200 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 201 | `xml_socket` | 12.5% | 1/8 | 1 | 8 |  |
| 202 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 203 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 204 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 205 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 206 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 2 | 9 |  |
| 207 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 208 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 209 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 210 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 211 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 212 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 |  |
| 213 | `extends_chain` | 9.0% | 12/134 | 122 | 134 |  |
| 214 | `instanceof_coercions` | 8.0% | 7/88 | 70 | 88 |  |
| 215 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 216 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 217 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 218 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 219 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 220 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 221 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 222 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 223 | `focus_visibility_change` | 6.7% | 3/45 | 27 | 45 |  |
| 224 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 225 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 226 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 227 | `as2_super_and_this_v6` | 6.2% | 6/97 | 17 | 97 |  |
| 228 | `bitmap_data` | 5.8% | 68/1174 | 1174 | 1126 |  |
| 229 | `focusrect_property_swf6` | 5.7% | 71/1237 | 156 | 1237 |  |
| 230 | `focusrect_property_swf7` | 5.6% | 69/1237 | 156 | 1237 |  |
| 231 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 232 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 233 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 234 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 235 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 236 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 237 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 238 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 239 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 240 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 241 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 242 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 |  |
| 243 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 244 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 245 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 246 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 |  |
| 247 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 248 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 249 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 250 | `asnew` | 2.9% | 1/34 | 3 | 34 |  |
| 251 | `as2_super_and_this_v8` | 2.4% | 2/85 | 9 | 85 |  |
| 252 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 253 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 254 | `math_swf6` | 1.9% | 10/530 | 458 | 530 |  |
| 255 | `math_swf7` | 1.9% | 10/530 | 458 | 530 |  |
| 256 | `math_swf8` | 1.9% | 10/530 | 458 | 530 |  |
| 257 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 258 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 259 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 260 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 261 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 262 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 263 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 264 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 265 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 266 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 267 | `focusrect_property_swf5` | 0.5% | 6/1237 | 156 | 1237 |  |
| 268 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 269 | `global_instance_decls` | 0.1% | 1/758 | 141 | 758 |  |
| 270 | `global_proto_decls` | 0.1% | 4/4497 | 95 | 4497 |  |
| 271 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 272 | `array_sort_random` | 0.0% | 0/443 | 2 | 443 |  |
| 273 | `as_set_prop_flags_version_swf5` | 0.0% | 0/1 | 1 | 1 |  |
| 274 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 275 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 276 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 277 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 278 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 279 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 280 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 281 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 282 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 283 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 284 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 285 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 286 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 287 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 288 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 289 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 290 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 291 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 292 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 293 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 294 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 295 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 296 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 297 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 298 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 299 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 300 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 301 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 302 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 303 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 304 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 |  |
| 305 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 306 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 307 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 308 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 309 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 310 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 311 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 312 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 313 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 314 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 315 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 316 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 317 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 318 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 319 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 320 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 321 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 322 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 323 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 324 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 325 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 326 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 327 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 328 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 329 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 330 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 331 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 332 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 333 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 334 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 335 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 336 | `global_proto_decls_delete` | 0.0% | 0/4158 | 24 | 4158 |  |
| 337 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 338 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 339 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 340 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 341 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 342 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 343 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 344 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 345 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 346 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 347 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 348 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 349 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 350 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 351 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 352 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 353 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 354 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 355 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 356 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 357 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 358 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 359 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 360 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 361 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 362 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 363 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 364 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 365 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 366 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 367 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 368 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 369 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 370 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 371 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 372 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 373 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 374 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 375 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 376 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 377 | `native_objects_swf6` | 0.0% | 0/186 | 186 | 84 |  |
| 378 | `native_objects_swf7` | 0.0% | 0/186 | 186 | 84 |  |
| 379 | `native_objects_swf8` | 0.0% | 0/186 | 186 | 84 |  |
| 380 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 381 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 382 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 383 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 384 | `object_resolve` | 0.0% | 0/38 | 23 | 38 |  |
| 385 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 386 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 387 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 388 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 389 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 390 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 391 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 392 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 393 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 394 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 395 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 396 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 397 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 398 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 399 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 400 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 401 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 402 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 403 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 404 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 405 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 406 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 407 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 408 | `swf5_global_funcs` | 0.0% | 0/232 | 0 | 232 |  |
| 409 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 410 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 411 | `swf6_global_funcs` | 0.0% | 0/232 | 0 | 232 |  |
| 412 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 413 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 414 | `swf7_global_funcs` | 0.0% | 0/232 | 0 | 232 |  |
| 415 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 416 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 417 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 418 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 419 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 420 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 421 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 422 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 423 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 424 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 425 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 426 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 427 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 428 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 429 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 430 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 431 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 432 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 433 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 434 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 435 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 436 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 437 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 438 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 439 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 440 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 441 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 442 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
