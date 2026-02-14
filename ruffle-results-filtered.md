# Ruffle Test Results (Filtered)

**Date**: 2026-02-14 20:44 UTC

**Git SHA**: `733a70e9c5`

**Run Duration**: 43m 6s

**Filtered**: 137 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 482 |
| Passing | **185** (38.4%) |
| Failing | 297 |
| Total expected lines | 77802 |
| Matching lines | 37182 (47.8%) |
| Mismatched lines | 40620 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 289 | 97.3% |
| Segfault | 5 | 1.7% |
| Timeout | 3 | 1.0% |

## Passing Tests

**185 tests passing**

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
| 50 | `equals` | 32 | 3.6s |  |
| 51 | `equals2_swf5` | 926 | 11.7s |  |
| 52 | `equals2_swf6` | 926 | 11.8s |  |
| 53 | `equals2_swf7` | 926 | 11.8s |  |
| 54 | `equals_swf4` | 665 | 7.2s |  |
| 55 | `equals_swf4_alt` | 32 | 3.6s |  |
| 56 | `equals_swf5` | 32 | 3.7s |  |
| 57 | `error` | 58 | 3.8s |  |
| 58 | `escape` | 14 | 3.6s |  |
| 59 | `execution_order1` | 5 | 3.6s |  |
| 60 | `execution_order2` | 7 | 3.7s |  |
| 61 | `execution_order3` | 4 | 3.6s |  |
| 62 | `focusrect_mouse_swf8` | 0 | 3.5s |  |
| 63 | `focusrect_mouse_swf9` | 0 | 3.5s |  |
| 64 | `focusrect_swf5` | 6 | 3.8s |  |
| 65 | `get_variable_in_scope` | 29 | 3.7s |  |
| 66 | `getproperty` | 28 | 3.6s |  |
| 67 | `getproperty_swf4` | 28 | 3.6s |  |
| 68 | `getproperty_swf5` | 28 | 3.5s |  |
| 69 | `global_array` | 3 | 3.5s |  |
| 70 | `global_is_bare` | 7 | 3.5s |  |
| 71 | `goto_advance1` | 6 | 3.6s |  |
| 72 | `goto_advance2` | 2 | 3.5s |  |
| 73 | `goto_both_ways1` | 3 | 5.5s |  |
| 74 | `goto_both_ways2` | 3 | 3.6s |  |
| 75 | `goto_execution_order` | 2 | 3.6s |  |
| 76 | `goto_execution_order2` | 2 | 3.6s |  |
| 77 | `goto_frame_number` | 3 | 3.7s |  |
| 78 | `goto_rewind1` | 1 | 3.6s |  |
| 79 | `goto_rewind2` | 3 | 3.7s |  |
| 80 | `goto_rewind3` | 2 | 3.5s |  |
| 81 | `greater_swf6` | 1175 | 12.6s |  |
| 82 | `greater_swf7` | 1175 | 12.7s |  |
| 83 | `greaterthan_swf5` | 1 | 3.6s |  |
| 84 | `greaterthan_swf8` | 1 | 3.6s |  |
| 85 | `has_own_property` | 32 | 3.7s |  |
| 86 | `infinite_recursion_function` | 4 | 3.6s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 87 | `infinite_recursion_function_in_setter` | 131 | 3.6s |  |
| 88 | `infinite_recursion_virtual_property` | 67 | 3.6s |  |
| 89 | `init_array_invalid` | 4 | 3.5s |  |
| 90 | `init_object_invalid` | 4 | 3.5s |  |
| 91 | `issue_1086` | 1 | 3.5s |  |
| 92 | `issue_1671` | 0 | 3.6s |  |
| 93 | `issue_2166` | 9 | 3.6s |  |
| 94 | `issue_3446` | 1 | 3.6s |  |
| 95 | `issue_4377` | 2 | 3.6s |  |
| 96 | `issue_710` | 4 | 3.6s |  |
| 97 | `issue_768` | 3 | 3.6s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 98 | `lessthan` | 41 | 3.8s |  |
| 99 | `lessthan2_swf5` | 1226 | 13.7s |  |
| 100 | `lessthan2_swf6` | 1226 | 13.6s |  |
| 101 | `lessthan2_swf7` | 1226 | 13.7s |  |
| 102 | `lessthan_swf4` | 902 | 9.4s |  |
| 103 | `lessthan_swf4_alt` | 41 | 3.7s |  |
| 104 | `lessthan_swf5` | 41 | 3.6s |  |
| 105 | `logical_ops_swf4` | 90 | 3.9s |  |
| 106 | `logical_ops_swf8` | 108 | 4.0s |  |
| 107 | `looping` | 6 | 3.8s |  |
| 108 | `mask_reapply` | 0 | 3.8s |  |
| 109 | `mask_with_drawing` | 0 | 3.8s |  |
| 110 | `movieclip_begin_gradient_fill` | 0 | 4.5s |  |
| 111 | `movieclip_line_gradient_style` | 0 | 4.1s |  |
| 112 | `movieclip_name_from_timeline` | 13 | 3.5s |  |
| 113 | `movieclip_prototype_extension` | 5 | 3.5s |  |
| 114 | `nested_textfields_in_buttons` | 0 | 3.5s |  |
| 115 | `netstream_play_flv_screen` | 0 | 30.4s |  |
| 116 | `new_method_wrap` | 4 | 3.5s |  |
| 117 | `new_object_wrap` | 4 | 3.5s |  |
| 118 | `o` | 3 | 3.5s |  |
| 119 | `object_constructor` | 33 | 3.6s |  |
| 120 | `object_function` | 32 | 3.6s |  |
| 121 | `object_string_coerce_swf5` | 62 | 3.6s |  |
| 122 | `primitive_instanceof` | 37 | 3.6s |  |
| 123 | `prototype_delete` | 12 | 3.6s |  |
| 124 | `recursive_prototypes` | 0 | 3.5s |  |
| 125 | `sandbox_type_local_file` | 1 | 3.4s |  |
| 126 | `set_variable_scope` | 58 | 3.6s |  |
| 127 | `single_frame` | 1 | 3.4s |  |
| 128 | `sound_start_load` | 0 | 3.5s |  |
| 129 | `stage_object_properties_get_var` | 5 | 3.4s |  |
| 130 | `strictequals_swf6` | 902 | 9.2s |  |
| 131 | `strictly_equals` | 7 | 3.5s |  |
| 132 | `string_coercion` | 117 | 4.1s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 133 | `string_paths_keyevents` | 0 | 3.4s |  |
| 134 | `string_paths_timer` | 0 | 3.5s |  |
| 135 | `swf4_actions_bool` | 96 | 3.6s |  |
| 136 | `swf4_bool` | 4 | 3.4s |  |
| 137 | `swf4_function_calls` | 7 | 4.0s |  |
| 138 | `swf5_encoding` | 3 | 3.5s |  |
| 139 | `tab_ordering_properties_tab_index_edge_case` | 4 | 3.5s |  |
| 140 | `target_path` | 14 | 3.5s |  |
| 141 | `text_format` | 1146 | 3.9s |  |
| 142 | `text_format_display` | 21 | 3.7s |  |
| 143 | `text_format_font_max_length` | 2 | 3.5s |  |
| 144 | `text_format_rounding_swf7` | 840 | 3.9s |  |
| 145 | `text_format_rounding_swf8` | 840 | 3.8s |  |
| 146 | `textfield_background_color` | 11 | 3.6s |  |
| 147 | `textfield_border_color` | 11 | 3.6s |  |
| 148 | `textfield_props_swf6` | 210 | 4.5s |  |
| 149 | `textfield_props_swf7` | 210 | 4.5s |  |
| 150 | `textfield_props_swf8` | 210 | 4.5s |  |
| 151 | `textfield_text` | 7 | 3.5s |  |
| 152 | `textfield_variable` | 81 | 4.0s |  |
| 153 | `this_swf7` | 41 | 3.6s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 154 | `timeline_function_def` | 7 | 3.6s |  |
| 155 | `try_finally_simple` | 16 | 3.6s |  |
| 156 | `typeof` | 22 | 3.5s |  |
| 157 | `typeof_globals` | 7 | 3.5s |  |
| 158 | `uncaught_exception` | 1 | 3.5s |  |
| 159 | `uncaught_exception_bubbled` | 1 | 3.5s |  |
| 160 | `undefined_to_string_swf6` | 4 | 3.5s |  |
| 161 | `unescape` | 43 | 3.6s |  |
| 162 | `use_hand_cursor` | 8 | 3.6s |  |
| 163 | `variable_args` | 5 | 3.7s |  |
| 164 | `waitforframe` | 7 | 3.5s |  |
| 165 | `waitforframe2` | 16 | 3.6s |  |
| 166 | `with_return` | 2 | 3.6s |  |
| 167 | `xml` | 15 | 3.7s |  |
| 168 | `xml_append_child` | 28 | 3.7s |  |
| 169 | `xml_append_child_with_parent` | 20 | 3.7s |  |
| 170 | `xml_attributes_read` | 4 | 3.6s |  |
| 171 | `xml_cdata` | 11 | 3.6s |  |
| 172 | `xml_clone_expandos` | 19 | 3.7s |  |
| 173 | `xml_first_last_child` | 8 | 3.6s |  |
| 174 | `xml_has_child_nodes` | 3 | 3.6s |  |
| 175 | `xml_idmap` | 21 | 3.8s |  |
| 176 | `xml_ignore_white` | 34 | 3.7s |  |
| 177 | `xml_insert_before` | 20 | 3.7s |  |
| 178 | `xml_inspect_createmethods` | 15 | 3.7s |  |
| 179 | `xml_inspect_doctype` | 7 | 3.7s |  |
| 180 | `xml_inspect_parsexml` | 62 | 3.7s |  |
| 181 | `xml_inspect_xmldecl` | 7 | 3.7s |  |
| 182 | `xml_parent_and_child` | 5 | 3.6s |  |
| 183 | `xml_remove_node` | 22 | 3.6s |  |
| 184 | `xml_siblings` | 10 | 3.6s |  |
| 185 | `xml_to_string_comment` | 1 | 3.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**77 tests** within reach

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
| 39 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 40 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 41 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 42 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 43 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 44 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 45 | `with` | 61.2% | 30 | 49 | 19 |  |
| 46 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 47 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 48 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 49 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 50 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 51 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 52 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 53 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 54 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 55 | `remove_movie_clip` | 58.6% | 17 | 29 | 12 |  |
| 56 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 57 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 58 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 59 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 60 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 61 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 62 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 63 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 64 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 65 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 |  |
| 66 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 67 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 68 | `globals_swf8` | 51.0% | 155 | 304 | 149 |  |
| 69 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 70 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 71 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 72 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 73 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 74 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 75 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 76 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 77 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

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

**289 tests** with output mismatch, sorted by match rate (best first)

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
| 39 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 40 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 41 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 42 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 43 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 44 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 45 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 46 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 47 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 48 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 49 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 50 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 51 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 52 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 53 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 54 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 55 | `remove_movie_clip` | 58.6% | 17/29 | 29 | 29 |  |
| 56 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 57 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 58 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 59 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 60 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 61 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 62 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 63 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 64 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 65 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 |  |
| 66 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 67 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 68 | `globals_swf8` | 51.0% | 155/304 | 304 | 304 |  |
| 69 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 70 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 71 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 72 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 73 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 74 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 75 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 76 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 77 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 78 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 79 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 80 | `frame_size_translated_negative` | 47.6% | 10/21 | 20 | 21 |  |
| 81 | `frame_size_translated_positive` | 47.6% | 10/21 | 20 | 21 |  |
| 82 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 83 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 84 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 85 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 86 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 87 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 88 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 89 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 90 | `as2_oop` | 38.5% | 5/13 | 10 | 13 |  |
| 91 | `edittext_html_swf6` | 37.5% | 2016/5377 | 5377 | 5377 |  |
| 92 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 93 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 94 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 95 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 96 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 97 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 98 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 99 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 100 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 101 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 102 | `edittext_html_condensewhite_swf7` | 30.2% | 94/311 | 311 | 311 |  |
| 103 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 104 | `edittext_html_condensewhite_swf8` | 29.3% | 91/311 | 311 | 311 |  |
| 105 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 106 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 107 | `edittext_html_swf7` | 25.7% | 1380/5377 | 5377 | 5377 |  |
| 108 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 109 | `edittext_html_swf8` | 25.4% | 1365/5377 | 5377 | 5377 |  |
| 110 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 111 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 112 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 113 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 114 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 115 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 116 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 117 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 118 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 119 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 120 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 121 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 122 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 123 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 124 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 125 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 126 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 127 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 128 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 129 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 130 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 131 | `watch` | 15.4% | 18/117 | 100 | 117 |  |
| 132 | `as2_super_via_manual_prototype` | 15.0% | 6/40 | 16 | 40 |  |
| 133 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 134 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 135 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 136 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 137 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 138 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 139 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 140 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 |  |
| 141 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 142 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 143 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 144 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 145 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 146 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 147 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 148 | `extends_chain` | 11.2% | 15/134 | 114 | 134 |  |
| 149 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 150 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 151 | `unload` | 9.6% | 5/52 | 48 | 52 |  |
| 152 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 153 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 154 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 155 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 156 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 157 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 158 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 159 | `init_object_order` | 6.7% | 1/15 | 5 | 15 |  |
| 160 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 161 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 162 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 163 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 164 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 165 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 166 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 167 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 168 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 169 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 170 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 171 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 172 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 173 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 174 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 175 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 176 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 177 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 178 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 179 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 180 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 181 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 182 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 183 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 184 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 185 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 186 | `global_instance_decls` | 0.1% | 1/758 | 141 | 758 |  |
| 187 | `global_proto_decls` | 0.0% | 2/4497 | 93 | 4497 |  |
| 188 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 189 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 190 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 191 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 192 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 193 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 194 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 195 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 196 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 197 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 198 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 199 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 200 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 201 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 202 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 203 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 204 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 205 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 206 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 207 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 208 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 209 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 210 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 211 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 212 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 213 | `extends_native_type` | 0.0% | 0/11 | 4 | 11 |  |
| 214 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 215 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 216 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 217 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 218 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 219 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 220 | `global_proto_decls_delete` | 0.0% | 0/4158 | 22 | 4158 |  |
| 221 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 222 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 223 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 224 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 225 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 226 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 227 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 228 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 229 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 230 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 231 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 232 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 233 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 234 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 235 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 236 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 237 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 238 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 239 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 240 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 241 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 242 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 243 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 244 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 245 | `native_objects_swf6` | 0.0% | 0/183 | 183 | 84 |  |
| 246 | `native_objects_swf7` | 0.0% | 0/183 | 183 | 84 |  |
| 247 | `native_objects_swf8` | 0.0% | 0/183 | 183 | 84 |  |
| 248 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 249 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 250 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 251 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 252 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 253 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 254 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 255 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 256 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 257 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 258 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 259 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 260 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 261 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 262 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 263 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 264 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 265 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 266 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 267 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 268 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 269 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 270 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 271 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 272 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 273 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 274 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 275 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 276 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 277 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 278 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 279 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 280 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 281 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 282 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 283 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 284 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 285 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 286 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 287 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 288 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 289 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
