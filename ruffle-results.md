# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-14 20:44 UTC

**Git SHA**: `733a70e9c5`

**Run Duration**: 43m 6s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **186** (30.0%) |
| Failing | 433 |
| Total expected lines | 91286 |
| Matching lines | 38733 (42.4%) |
| Mismatched lines | 52553 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 425 | 98.2% |
| Runtime Segfault | 5 | 1.2% |
| Timeout | 3 | 0.7% |

## Passing Tests

**186 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 3.6s |  |
| 2 | `action_to_integer` | 28 | 3.7s |  |
| 3 | `add` | 28 | 3.6s |  |
| 4 | `add2` | 354 | 4.1s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 3.6s |  |
| 6 | `add_swf5` | 28 | 3.6s |  |
| 7 | `array_concat` | 98 | 3.8s |  |
| 8 | `array_constructor` | 30 | 3.7s |  |
| 9 | `array_length` | 42 | 3.8s |  |
| 10 | `array_properties` | 36 | 3.7s |  |
| 11 | `array_slice` | 34 | 3.7s |  |
| 12 | `array_splice` | 207 | 4.3s |  |
| 13 | `array_trivial` | 209 | 4.1s |  |
| 14 | `as1_constructor_v6` | 35 | 3.7s |  |
| 15 | `as1_constructor_v7` | 35 | 3.6s |  |
| 16 | `as_broadcaster_initialize` | 10 | 3.5s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 3.5s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 3.6s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 3.6s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 3.6s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 3.6s |  |
| 22 | `as_transformed_flag` | 20 | 3.6s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 3.5s |  |
| 24 | `bitand` | 1058 | 10.1s |  |
| 25 | `bitmap_data_colortransform` | 0 | 3.8s |  |
| 26 | `bitmap_data_fillrect` | 0 | 3.8s |  |
| 27 | `bitmap_data_max_size_swf10` | 12 | 3.6s |  |
| 28 | `bitmap_data_max_size_swf9` | 10 | 3.6s |  |
| 29 | `bitmap_data_perlinnoise` | 0 | 4.4s |  |
| 30 | `bitmap_data_pixeldissolve_image` | 0 | 4.3s |  |
| 31 | `bitmapdata_applyfilter_colormatrix` | 0 | 3.6s |  |
| 32 | `bitor` | 1058 | 10.9s |  |
| 33 | `biturshift` | 14 | 3.8s |  |
| 34 | `biturshift_swf8` | 14 | 3.6s |  |
| 35 | `bitxor` | 1058 | 10.3s |  |
| 36 | `call_method_empty_name` | 1 | 3.5s |  |
| 37 | `capabilities_resolution` | 8 | 3.5s |  |
| 38 | `catch_references_registers` | 2 | 3.6s |  |
| 39 | `conflicting_instance_names` | 23 | 3.7s |  |
| 40 | `define_function2` | 8 | 3.6s |  |
| 41 | `define_function2_preload` | 13 | 3.6s |  |
| 42 | `define_function2_preload_order` | 4 | 3.6s |  |
| 43 | `define_function_case_sensitive` | 2 | 3.6s |  |
| 44 | `delete` | 3 | 3.6s |  |
| 45 | `display_object_properties` | 2 | 3.5s |  |
| 46 | `divide_swf4` | 107 | 3.7s |  |
| 47 | `do_init_action` | 3 | 3.6s |  |
| 48 | `edittext_autosize_setter` | 20 | 3.6s |  |
| 49 | `edittext_default_format_empty` | 95 | 3.7s |  |
| 50 | `edittext_password` | 5 | 3.6s |  |
| 51 | `equals` | 32 | 3.6s |  |
| 52 | `equals2_swf5` | 926 | 11.7s |  |
| 53 | `equals2_swf6` | 926 | 11.8s |  |
| 54 | `equals2_swf7` | 926 | 11.8s |  |
| 55 | `equals_swf4` | 665 | 7.2s |  |
| 56 | `equals_swf4_alt` | 32 | 3.6s |  |
| 57 | `equals_swf5` | 32 | 3.7s |  |
| 58 | `error` | 58 | 3.8s |  |
| 59 | `escape` | 14 | 3.6s |  |
| 60 | `execution_order1` | 5 | 3.6s |  |
| 61 | `execution_order2` | 7 | 3.7s |  |
| 62 | `execution_order3` | 4 | 3.6s |  |
| 63 | `focusrect_mouse_swf8` | 0 | 3.5s |  |
| 64 | `focusrect_mouse_swf9` | 0 | 3.5s |  |
| 65 | `focusrect_swf5` | 6 | 3.8s |  |
| 66 | `get_variable_in_scope` | 29 | 3.7s |  |
| 67 | `getproperty` | 28 | 3.6s |  |
| 68 | `getproperty_swf4` | 28 | 3.6s |  |
| 69 | `getproperty_swf5` | 28 | 3.5s |  |
| 70 | `global_array` | 3 | 3.5s |  |
| 71 | `global_is_bare` | 7 | 3.5s |  |
| 72 | `goto_advance1` | 6 | 3.6s |  |
| 73 | `goto_advance2` | 2 | 3.5s |  |
| 74 | `goto_both_ways1` | 3 | 5.5s |  |
| 75 | `goto_both_ways2` | 3 | 3.6s |  |
| 76 | `goto_execution_order` | 2 | 3.6s |  |
| 77 | `goto_execution_order2` | 2 | 3.6s |  |
| 78 | `goto_frame_number` | 3 | 3.7s |  |
| 79 | `goto_rewind1` | 1 | 3.6s |  |
| 80 | `goto_rewind2` | 3 | 3.7s |  |
| 81 | `goto_rewind3` | 2 | 3.5s |  |
| 82 | `greater_swf6` | 1175 | 12.6s |  |
| 83 | `greater_swf7` | 1175 | 12.7s |  |
| 84 | `greaterthan_swf5` | 1 | 3.6s |  |
| 85 | `greaterthan_swf8` | 1 | 3.6s |  |
| 86 | `has_own_property` | 32 | 3.7s |  |
| 87 | `infinite_recursion_function` | 4 | 3.6s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 88 | `infinite_recursion_function_in_setter` | 131 | 3.6s |  |
| 89 | `infinite_recursion_virtual_property` | 67 | 3.6s |  |
| 90 | `init_array_invalid` | 4 | 3.5s |  |
| 91 | `init_object_invalid` | 4 | 3.5s |  |
| 92 | `issue_1086` | 1 | 3.5s |  |
| 93 | `issue_1671` | 0 | 3.6s |  |
| 94 | `issue_2166` | 9 | 3.6s |  |
| 95 | `issue_3446` | 1 | 3.6s |  |
| 96 | `issue_4377` | 2 | 3.6s |  |
| 97 | `issue_710` | 4 | 3.6s |  |
| 98 | `issue_768` | 3 | 3.6s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 99 | `lessthan` | 41 | 3.8s |  |
| 100 | `lessthan2_swf5` | 1226 | 13.7s |  |
| 101 | `lessthan2_swf6` | 1226 | 13.6s |  |
| 102 | `lessthan2_swf7` | 1226 | 13.7s |  |
| 103 | `lessthan_swf4` | 902 | 9.4s |  |
| 104 | `lessthan_swf4_alt` | 41 | 3.7s |  |
| 105 | `lessthan_swf5` | 41 | 3.6s |  |
| 106 | `logical_ops_swf4` | 90 | 3.9s |  |
| 107 | `logical_ops_swf8` | 108 | 4.0s |  |
| 108 | `looping` | 6 | 3.8s |  |
| 109 | `mask_reapply` | 0 | 3.8s |  |
| 110 | `mask_with_drawing` | 0 | 3.8s |  |
| 111 | `movieclip_begin_gradient_fill` | 0 | 4.5s |  |
| 112 | `movieclip_line_gradient_style` | 0 | 4.1s |  |
| 113 | `movieclip_name_from_timeline` | 13 | 3.5s |  |
| 114 | `movieclip_prototype_extension` | 5 | 3.5s |  |
| 115 | `nested_textfields_in_buttons` | 0 | 3.5s |  |
| 116 | `netstream_play_flv_screen` | 0 | 30.4s |  |
| 117 | `new_method_wrap` | 4 | 3.5s |  |
| 118 | `new_object_wrap` | 4 | 3.5s |  |
| 119 | `o` | 3 | 3.5s |  |
| 120 | `object_constructor` | 33 | 3.6s |  |
| 121 | `object_function` | 32 | 3.6s |  |
| 122 | `object_string_coerce_swf5` | 62 | 3.6s |  |
| 123 | `primitive_instanceof` | 37 | 3.6s |  |
| 124 | `prototype_delete` | 12 | 3.6s |  |
| 125 | `recursive_prototypes` | 0 | 3.5s |  |
| 126 | `sandbox_type_local_file` | 1 | 3.4s |  |
| 127 | `set_variable_scope` | 58 | 3.6s |  |
| 128 | `single_frame` | 1 | 3.4s |  |
| 129 | `sound_start_load` | 0 | 3.5s |  |
| 130 | `stage_object_properties_get_var` | 5 | 3.4s |  |
| 131 | `strictequals_swf6` | 902 | 9.2s |  |
| 132 | `strictly_equals` | 7 | 3.5s |  |
| 133 | `string_coercion` | 117 | 4.1s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 134 | `string_paths_keyevents` | 0 | 3.4s |  |
| 135 | `string_paths_timer` | 0 | 3.5s |  |
| 136 | `swf4_actions_bool` | 96 | 3.6s |  |
| 137 | `swf4_bool` | 4 | 3.4s |  |
| 138 | `swf4_function_calls` | 7 | 4.0s |  |
| 139 | `swf5_encoding` | 3 | 3.5s |  |
| 140 | `tab_ordering_properties_tab_index_edge_case` | 4 | 3.5s |  |
| 141 | `target_path` | 14 | 3.5s |  |
| 142 | `text_format` | 1146 | 3.9s |  |
| 143 | `text_format_display` | 21 | 3.7s |  |
| 144 | `text_format_font_max_length` | 2 | 3.5s |  |
| 145 | `text_format_rounding_swf7` | 840 | 3.9s |  |
| 146 | `text_format_rounding_swf8` | 840 | 3.8s |  |
| 147 | `textfield_background_color` | 11 | 3.6s |  |
| 148 | `textfield_border_color` | 11 | 3.6s |  |
| 149 | `textfield_props_swf6` | 210 | 4.5s |  |
| 150 | `textfield_props_swf7` | 210 | 4.5s |  |
| 151 | `textfield_props_swf8` | 210 | 4.5s |  |
| 152 | `textfield_text` | 7 | 3.5s |  |
| 153 | `textfield_variable` | 81 | 4.0s |  |
| 154 | `this_swf7` | 41 | 3.6s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 155 | `timeline_function_def` | 7 | 3.6s |  |
| 156 | `try_finally_simple` | 16 | 3.6s |  |
| 157 | `typeof` | 22 | 3.5s |  |
| 158 | `typeof_globals` | 7 | 3.5s |  |
| 159 | `uncaught_exception` | 1 | 3.5s |  |
| 160 | `uncaught_exception_bubbled` | 1 | 3.5s |  |
| 161 | `undefined_to_string_swf6` | 4 | 3.5s |  |
| 162 | `unescape` | 43 | 3.6s |  |
| 163 | `use_hand_cursor` | 8 | 3.6s |  |
| 164 | `variable_args` | 5 | 3.7s |  |
| 165 | `waitforframe` | 7 | 3.5s |  |
| 166 | `waitforframe2` | 16 | 3.6s |  |
| 167 | `with_return` | 2 | 3.6s |  |
| 168 | `xml` | 15 | 3.7s |  |
| 169 | `xml_append_child` | 28 | 3.7s |  |
| 170 | `xml_append_child_with_parent` | 20 | 3.7s |  |
| 171 | `xml_attributes_read` | 4 | 3.6s |  |
| 172 | `xml_cdata` | 11 | 3.6s |  |
| 173 | `xml_clone_expandos` | 19 | 3.7s |  |
| 174 | `xml_first_last_child` | 8 | 3.6s |  |
| 175 | `xml_has_child_nodes` | 3 | 3.6s |  |
| 176 | `xml_idmap` | 21 | 3.8s |  |
| 177 | `xml_ignore_white` | 34 | 3.7s |  |
| 178 | `xml_insert_before` | 20 | 3.7s |  |
| 179 | `xml_inspect_createmethods` | 15 | 3.7s |  |
| 180 | `xml_inspect_doctype` | 7 | 3.7s |  |
| 181 | `xml_inspect_parsexml` | 62 | 3.7s |  |
| 182 | `xml_inspect_xmldecl` | 7 | 3.7s |  |
| 183 | `xml_parent_and_child` | 5 | 3.6s |  |
| 184 | `xml_remove_node` | 22 | 3.6s |  |
| 185 | `xml_siblings` | 10 | 3.6s |  |
| 186 | `xml_to_string_comment` | 1 | 3.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**88 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `edittext_default_format_font_style` | 97.6% | 327 | 335 | 8 |  |
| 2 | `edittext_antialiastype` | 92.9% | 275 | 296 | 21 |  |
| 3 | `xml_namespaces` | 92.1% | 187 | 203 | 16 |  |
| 4 | `swf7_case_sensitive` | 90.9% | 40 | 44 | 4 |  |
| 5 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 |  |
| 6 | `textfield_properties` | 86.4% | 38 | 44 | 6 |  |
| 7 | `xml_ignore_comments` | 85.7% | 18 | 21 | 3 |  |
| 8 | `xml_to_string` | 84.6% | 11 | 13 | 2 |  |
| 9 | `object_prototypes` | 83.8% | 62 | 74 | 12 |  |
| 10 | `stage_object_children` | 81.9% | 68 | 83 | 15 |  |
| 11 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 12 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 |  |
| 13 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 14 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 15 | `xml_child_nodes_edge_cases` | 75.0% | 3 | 4 | 1 |  |
| 16 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 17 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 18 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 19 | `globals_swf6` | 71.4% | 217 | 304 | 87 |  |
| 20 | `point` | 70.9% | 124 | 175 | 51 |  |
| 21 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 22 | `globals_swf7` | 70.4% | 214 | 304 | 90 |  |
| 23 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 24 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 25 | `globals_swf5` | 69.1% | 210 | 304 | 94 |  |
| 26 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 27 | `transform` | 68.6% | 48 | 70 | 22 |  |
| 28 | `stage_object_properties` | 68.5% | 165 | 241 | 76 |  |
| 29 | `stage_object_properties_swf6` | 68.4% | 158 | 231 | 73 |  |
| 30 | `as_set_prop_flags` | 68.4% | 54 | 79 | 25 |  |
| 31 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 32 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 33 | `edittext_default_format` | 67.6% | 150 | 222 | 72 |  |
| 34 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 35 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 36 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 37 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 38 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 39 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 40 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 41 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 42 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 43 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 44 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 45 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 46 | `with` | 61.2% | 30 | 49 | 19 |  |
| 47 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 48 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 49 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 50 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 51 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 52 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 53 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 54 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 55 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 56 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 57 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 58 | `remove_movie_clip` | 58.6% | 17 | 29 | 12 |  |
| 59 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 60 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 61 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 62 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 63 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 64 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 65 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 66 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 67 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 68 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 69 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 |  |
| 70 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 71 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 72 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 73 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 74 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 75 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 76 | `globals_swf8` | 51.0% | 155 | 304 | 149 |  |
| 77 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 78 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 79 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 80 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 81 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 82 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 83 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 84 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 85 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 86 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 87 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 88 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 13.6s |  |
| 2 | `duplicate_movie_clip_drawing` | 5.6s |  |
| 3 | `goto_methods` | 6.2s |  |
| 4 | `path_string` | 6.0s |  |
| 5 | `swf4_actions_coercion_order` | 5.1s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**3 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 14.6s |  |
| 2 | `timeout` | runtime timeout (>10s) | 13.7s |  |
| 3 | `try_catch_finally` | runtime timeout (>10s) | 14.0s |  |

## All Output Mismatches

**425 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `edittext_default_format_font_style` | 97.6% | 327/335 | 335 | 335 |  |
| 2 | `edittext_antialiastype` | 92.9% | 275/296 | 296 | 296 |  |
| 3 | `xml_namespaces` | 92.1% | 187/203 | 203 | 203 |  |
| 4 | `swf7_case_sensitive` | 90.9% | 40/44 | 44 | 44 |  |
| 5 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 |  |
| 6 | `textfield_properties` | 86.4% | 38/44 | 44 | 44 |  |
| 7 | `xml_ignore_comments` | 85.7% | 18/21 | 21 | 21 |  |
| 8 | `xml_to_string` | 84.6% | 11/13 | 13 | 13 |  |
| 9 | `object_prototypes` | 83.8% | 62/74 | 73 | 74 |  |
| 10 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 |  |
| 11 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 12 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 |  |
| 13 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 14 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 15 | `xml_child_nodes_edge_cases` | 75.0% | 3/4 | 4 | 4 |  |
| 16 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 17 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 18 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 19 | `globals_swf6` | 71.4% | 217/304 | 304 | 304 |  |
| 20 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 21 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 22 | `globals_swf7` | 70.4% | 214/304 | 304 | 304 |  |
| 23 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 24 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 25 | `globals_swf5` | 69.1% | 210/304 | 304 | 304 |  |
| 26 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 27 | `transform` | 68.6% | 48/70 | 70 | 70 |  |
| 28 | `stage_object_properties` | 68.5% | 165/241 | 241 | 241 |  |
| 29 | `stage_object_properties_swf6` | 68.4% | 158/231 | 231 | 231 |  |
| 30 | `as_set_prop_flags` | 68.4% | 54/79 | 76 | 79 |  |
| 31 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 32 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 33 | `edittext_default_format` | 67.6% | 150/222 | 222 | 221 |  |
| 34 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 35 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 36 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 37 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 38 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 39 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 40 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 41 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 42 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 43 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 44 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 45 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 46 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 47 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 48 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 49 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 50 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 51 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 52 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 53 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 54 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 55 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 56 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 57 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 58 | `remove_movie_clip` | 58.6% | 17/29 | 29 | 29 |  |
| 59 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 60 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 61 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 62 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 63 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 64 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 65 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 66 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 67 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 68 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 69 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 |  |
| 70 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 71 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 72 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 73 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 74 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 75 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 76 | `globals_swf8` | 51.0% | 155/304 | 304 | 304 |  |
| 77 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 78 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 79 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 80 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 81 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 82 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 83 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 84 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 85 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 86 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 87 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 88 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 89 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 90 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 91 | `frame_size_translated_negative` | 47.6% | 10/21 | 20 | 21 |  |
| 92 | `frame_size_translated_positive` | 47.6% | 10/21 | 20 | 21 |  |
| 93 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 94 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 95 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 96 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 97 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 98 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 99 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 100 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 101 | `as2_oop` | 38.5% | 5/13 | 10 | 13 |  |
| 102 | `edittext_html_swf6` | 37.5% | 2016/5377 | 5377 | 5377 |  |
| 103 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 104 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 105 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 106 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 107 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 108 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 109 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 110 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 111 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 112 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 113 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 114 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 115 | `edittext_html_condensewhite_swf7` | 30.2% | 94/311 | 311 | 311 |  |
| 116 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 117 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 118 | `edittext_html_condensewhite_swf8` | 29.3% | 91/311 | 311 | 311 |  |
| 119 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 120 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 121 | `edittext_html_swf7` | 25.7% | 1380/5377 | 5377 | 5377 |  |
| 122 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 123 | `edittext_html_swf8` | 25.4% | 1365/5377 | 5377 | 5377 |  |
| 124 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 125 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 126 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 127 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 128 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 129 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 130 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 131 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 132 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 133 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 134 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 135 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 136 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 137 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 138 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 139 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 140 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 141 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 142 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 143 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 144 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 145 | `focusrect_property_swf6` | 17.1% | 211/1237 | 1236 | 1237 |  |
| 146 | `focusrect_property_swf7` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 147 | `focusrect_property_swf5` | 16.9% | 209/1237 | 1236 | 1237 |  |
| 148 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 149 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 150 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 151 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 152 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 153 | `watch` | 15.4% | 18/117 | 100 | 117 |  |
| 154 | `as2_super_via_manual_prototype` | 15.0% | 6/40 | 16 | 40 |  |
| 155 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 156 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 157 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 158 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 159 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 160 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 161 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 162 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 163 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 164 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 165 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 |  |
| 166 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 167 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 168 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 169 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 170 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 171 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 172 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 173 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 174 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 175 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 176 | `extends_chain` | 11.2% | 15/134 | 114 | 134 |  |
| 177 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 178 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 179 | `unload` | 9.6% | 5/52 | 48 | 52 |  |
| 180 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 181 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 182 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 183 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 184 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 185 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 186 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 187 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 188 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 189 | `init_object_order` | 6.7% | 1/15 | 5 | 15 |  |
| 190 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 191 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 192 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 193 | `bitmap_data` | 5.8% | 68/1174 | 1174 | 1126 |  |
| 194 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 195 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 196 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 197 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 198 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 199 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 200 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 201 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 202 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 203 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 204 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 205 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 206 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 207 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 208 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 209 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 210 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 211 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 212 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 213 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 214 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 215 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 216 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 217 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 218 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 219 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 220 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 221 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 222 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 223 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 224 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 225 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 226 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 227 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 228 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 229 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 230 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 231 | `global_instance_decls` | 0.1% | 1/758 | 141 | 758 |  |
| 232 | `global_proto_decls` | 0.0% | 2/4497 | 93 | 4497 |  |
| 233 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 234 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 235 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 236 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 237 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 238 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 239 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 240 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 241 | `bitmap_data_copypixels` | 0.0% | 0/17 | 0 | 17 |  |
| 242 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 0 | 1075 |  |
| 243 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 244 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 245 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 246 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 247 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 248 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 249 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 250 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 251 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 252 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 253 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 254 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 255 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 256 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 257 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 258 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 259 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 260 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 261 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 262 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 263 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 264 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 265 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 266 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 267 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 268 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 269 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 270 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 271 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 272 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 273 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 274 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 275 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 276 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 277 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 278 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 279 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 280 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 281 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 282 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 283 | `extends_native_type` | 0.0% | 0/11 | 4 | 11 |  |
| 284 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 285 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 286 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 287 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 288 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 289 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 290 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 291 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 292 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 293 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 294 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 295 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 296 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 297 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 298 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 299 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 300 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 301 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 302 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 303 | `global_proto_decls_delete` | 0.0% | 0/4158 | 22 | 4158 |  |
| 304 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 305 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 306 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 307 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 308 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 309 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 310 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 311 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 312 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 313 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 314 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 315 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 316 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 317 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 318 | `loadmovie_fail` | 0.0% | 0/2 | 0 | 2 |  |
| 319 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 320 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 321 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 0 | 9 |  |
| 322 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 323 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 324 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 325 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 326 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 327 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 328 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 329 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 330 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 331 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 332 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 333 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 334 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 335 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 336 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 337 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 338 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 339 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 340 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 341 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 342 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 343 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 344 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 345 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 346 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 347 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 348 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 349 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 350 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 351 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 352 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 353 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 354 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 355 | `native_objects_swf6` | 0.0% | 0/183 | 183 | 84 |  |
| 356 | `native_objects_swf7` | 0.0% | 0/183 | 183 | 84 |  |
| 357 | `native_objects_swf8` | 0.0% | 0/183 | 183 | 84 |  |
| 358 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 359 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 360 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 361 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 362 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 363 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 364 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 365 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 366 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 367 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 368 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 369 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 370 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 371 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 372 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 373 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 374 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 375 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 376 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 377 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 378 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 379 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 380 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 381 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 382 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 383 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 384 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 385 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 386 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 387 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 388 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 389 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 390 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 391 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 392 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 393 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 394 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 395 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 396 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 397 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 398 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 399 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 400 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 401 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 402 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 403 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 404 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 405 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 406 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 407 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 408 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 409 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 410 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 411 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 412 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 413 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 414 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 415 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 416 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 417 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 418 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 419 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 420 | `xml_socket` | 0.0% | 0/8 | 0 | 8 |  |
| 421 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 422 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 423 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
| 424 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 425 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
