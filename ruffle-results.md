# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-14 20:35 UTC

**Git SHA**: `73a7b45772`

**Run Duration**: 43m 50s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **173** (27.9%) |
| Failing | 446 |
| Total expected lines | 91218 |
| Matching lines | 28963 (31.8%) |
| Mismatched lines | 62255 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 424 | 95.1% |
| Runtime Segfault | 19 | 4.3% |
| Timeout | 3 | 0.7% |

## Passing Tests

**173 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 5.4s |  |
| 2 | `action_to_integer` | 28 | 3.6s |  |
| 3 | `add` | 28 | 3.8s |  |
| 4 | `add_swf4` | 28 | 3.6s |  |
| 5 | `add_swf5` | 28 | 3.6s |  |
| 6 | `array_concat` | 98 | 3.8s |  |
| 7 | `array_constructor` | 30 | 3.7s |  |
| 8 | `array_length` | 42 | 3.8s |  |
| 9 | `array_properties` | 36 | 3.6s |  |
| 10 | `array_slice` | 34 | 3.7s |  |
| 11 | `array_splice` | 207 | 4.4s |  |
| 12 | `array_trivial` | 209 | 4.1s |  |
| 13 | `as1_constructor_v6` | 35 | 3.7s |  |
| 14 | `as1_constructor_v7` | 35 | 3.7s |  |
| 15 | `as_broadcaster_initialize` | 10 | 3.6s |  |
| 16 | `as_set_prop_flags_version_swf5` | 1 | 3.6s |  |
| 17 | `as_set_prop_flags_version_swf6` | 1 | 3.6s |  |
| 18 | `as_set_prop_flags_version_swf7` | 1 | 3.6s |  |
| 19 | `as_set_prop_flags_version_swf8` | 1 | 3.6s |  |
| 20 | `as_set_prop_flags_version_swf9` | 1 | 3.6s |  |
| 21 | `as_transformed_flag` | 20 | 3.6s |  |
| 22 | `bad_swf_tag_past_eof` | 0 | 3.5s |  |
| 23 | `bitand` | 1058 | 10.3s |  |
| 24 | `bitmap_data_colortransform` | 0 | 3.9s |  |
| 25 | `bitmap_data_fillrect` | 0 | 3.8s |  |
| 26 | `bitmap_data_max_size_swf10` | 12 | 3.6s |  |
| 27 | `bitmap_data_max_size_swf9` | 10 | 3.6s |  |
| 28 | `bitmap_data_perlinnoise` | 0 | 4.3s |  |
| 29 | `bitmap_data_pixeldissolve_image` | 0 | 4.1s |  |
| 30 | `bitmapdata_applyfilter_colormatrix` | 0 | 3.6s |  |
| 31 | `bitor` | 1058 | 10.3s |  |
| 32 | `biturshift` | 14 | 4.0s |  |
| 33 | `biturshift_swf8` | 14 | 3.6s |  |
| 34 | `bitxor` | 1058 | 10.3s |  |
| 35 | `call_method_empty_name` | 1 | 3.5s |  |
| 36 | `capabilities_resolution` | 8 | 3.5s |  |
| 37 | `catch_references_registers` | 2 | 3.5s |  |
| 38 | `conflicting_instance_names` | 23 | 3.8s |  |
| 39 | `define_function2` | 8 | 3.6s |  |
| 40 | `define_function2_preload` | 13 | 3.6s |  |
| 41 | `define_function2_preload_order` | 4 | 3.6s |  |
| 42 | `define_function_case_sensitive` | 2 | 3.6s |  |
| 43 | `delete` | 3 | 3.6s |  |
| 44 | `display_object_properties` | 2 | 3.5s |  |
| 45 | `divide_swf4` | 107 | 3.7s |  |
| 46 | `do_init_action` | 3 | 3.6s |  |
| 47 | `edittext_autosize_setter` | 20 | 3.9s |  |
| 48 | `edittext_default_format_empty` | 95 | 3.9s |  |
| 49 | `edittext_password` | 5 | 3.8s |  |
| 50 | `equals` | 32 | 3.9s |  |
| 51 | `equals_swf4` | 665 | 7.9s |  |
| 52 | `equals_swf4_alt` | 32 | 3.9s |  |
| 53 | `equals_swf5` | 32 | 3.9s |  |
| 54 | `error` | 58 | 4.0s |  |
| 55 | `escape` | 14 | 3.8s |  |
| 56 | `execution_order1` | 5 | 3.9s |  |
| 57 | `execution_order2` | 7 | 3.9s |  |
| 58 | `execution_order3` | 4 | 3.8s |  |
| 59 | `focusrect_mouse_swf8` | 0 | 3.4s |  |
| 60 | `focusrect_mouse_swf9` | 0 | 3.4s |  |
| 61 | `focusrect_swf5` | 6 | 3.6s |  |
| 62 | `get_variable_in_scope` | 29 | 3.6s |  |
| 63 | `getproperty` | 28 | 3.5s |  |
| 64 | `getproperty_swf4` | 28 | 3.5s |  |
| 65 | `getproperty_swf5` | 28 | 3.5s |  |
| 66 | `global_array` | 3 | 3.4s |  |
| 67 | `global_is_bare` | 7 | 3.4s |  |
| 68 | `goto_advance1` | 6 | 3.4s |  |
| 69 | `goto_advance2` | 2 | 3.4s |  |
| 70 | `goto_both_ways1` | 3 | 3.8s |  |
| 71 | `goto_both_ways2` | 3 | 3.6s |  |
| 72 | `goto_execution_order` | 2 | 3.6s |  |
| 73 | `goto_execution_order2` | 2 | 3.6s |  |
| 74 | `goto_frame_number` | 3 | 3.7s |  |
| 75 | `goto_rewind1` | 1 | 3.7s |  |
| 76 | `goto_rewind2` | 3 | 3.7s |  |
| 77 | `goto_rewind3` | 2 | 3.6s |  |
| 78 | `greaterthan_swf5` | 1 | 3.6s |  |
| 79 | `greaterthan_swf8` | 1 | 3.6s |  |
| 80 | `has_own_property` | 32 | 3.7s |  |
| 81 | `infinite_recursion_function` | 4 | 3.6s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 82 | `infinite_recursion_function_in_setter` | 131 | 3.6s |  |
| 83 | `infinite_recursion_virtual_property` | 67 | 3.6s |  |
| 84 | `init_array_invalid` | 4 | 3.6s |  |
| 85 | `init_object_invalid` | 4 | 3.6s |  |
| 86 | `issue_1086` | 1 | 3.5s |  |
| 87 | `issue_2166` | 9 | 3.7s |  |
| 88 | `issue_3446` | 1 | 3.6s |  |
| 89 | `issue_4377` | 2 | 3.5s |  |
| 90 | `issue_710` | 4 | 3.5s |  |
| 91 | `issue_768` | 3 | 3.6s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 92 | `lessthan` | 41 | 3.7s |  |
| 93 | `lessthan_swf4` | 902 | 9.2s |  |
| 94 | `lessthan_swf4_alt` | 41 | 3.7s |  |
| 95 | `lessthan_swf5` | 41 | 3.7s |  |
| 96 | `logical_ops_swf4` | 90 | 3.7s |  |
| 97 | `logical_ops_swf8` | 108 | 3.7s |  |
| 98 | `looping` | 6 | 3.5s |  |
| 99 | `mask_reapply` | 0 | 3.6s |  |
| 100 | `mask_with_drawing` | 0 | 3.6s |  |
| 101 | `movieclip_begin_gradient_fill` | 0 | 4.3s |  |
| 102 | `movieclip_line_gradient_style` | 0 | 4.1s |  |
| 103 | `movieclip_name_from_timeline` | 13 | 3.6s |  |
| 104 | `movieclip_prototype_extension` | 5 | 3.6s |  |
| 105 | `nested_textfields_in_buttons` | 0 | 3.5s |  |
| 106 | `netstream_play_flv_screen` | 0 | 31.2s |  |
| 107 | `new_method_wrap` | 4 | 3.6s |  |
| 108 | `new_object_wrap` | 4 | 3.5s |  |
| 109 | `o` | 3 | 3.5s |  |
| 110 | `object_function` | 32 | 3.7s |  |
| 111 | `object_string_coerce_swf5` | 62 | 3.7s |  |
| 112 | `primitive_instanceof` | 37 | 3.6s |  |
| 113 | `prototype_delete` | 12 | 3.7s |  |
| 114 | `recursive_prototypes` | 0 | 3.6s |  |
| 115 | `sandbox_type_local_file` | 1 | 3.5s |  |
| 116 | `set_variable_scope` | 58 | 3.7s |  |
| 117 | `single_frame` | 1 | 3.5s |  |
| 118 | `sound_start_load` | 0 | 3.5s |  |
| 119 | `stage_object_properties_get_var` | 5 | 3.5s |  |
| 120 | `strictly_equals` | 7 | 3.6s |  |
| 121 | `string_paths_keyevents` | 0 | 3.5s |  |
| 122 | `string_paths_timer` | 0 | 3.5s |  |
| 123 | `swf4_actions_bool` | 96 | 3.7s |  |
| 124 | `swf4_bool` | 4 | 3.5s |  |
| 125 | `swf4_function_calls` | 7 | 3.7s |  |
| 126 | `swf5_encoding` | 3 | 3.5s |  |
| 127 | `tab_ordering_properties_tab_index_edge_case` | 4 | 3.6s |  |
| 128 | `target_path` | 14 | 3.6s |  |
| 129 | `text_format` | 1146 | 4.0s |  |
| 130 | `text_format_display` | 21 | 3.7s |  |
| 131 | `text_format_font_max_length` | 2 | 3.6s |  |
| 132 | `text_format_rounding_swf7` | 840 | 3.9s |  |
| 133 | `text_format_rounding_swf8` | 840 | 3.9s |  |
| 134 | `textfield_background_color` | 11 | 3.6s |  |
| 135 | `textfield_border_color` | 11 | 3.6s |  |
| 136 | `textfield_props_swf6` | 210 | 4.5s |  |
| 137 | `textfield_props_swf7` | 210 | 4.5s |  |
| 138 | `textfield_props_swf8` | 210 | 4.5s |  |
| 139 | `textfield_text` | 7 | 3.6s |  |
| 140 | `textfield_variable` | 81 | 4.0s |  |
| 141 | `this_swf7` | 41 | 3.6s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 142 | `timeline_function_def` | 7 | 3.7s |  |
| 143 | `try_finally_simple` | 16 | 3.7s |  |
| 144 | `typeof` | 22 | 3.7s |  |
| 145 | `typeof_globals` | 7 | 3.6s |  |
| 146 | `uncaught_exception` | 1 | 3.6s |  |
| 147 | `uncaught_exception_bubbled` | 1 | 3.7s |  |
| 148 | `undefined_to_string_swf6` | 4 | 3.7s |  |
| 149 | `unescape` | 43 | 3.8s |  |
| 150 | `use_hand_cursor` | 8 | 3.7s |  |
| 151 | `variable_args` | 5 | 3.9s |  |
| 152 | `waitforframe` | 7 | 3.7s |  |
| 153 | `waitforframe2` | 16 | 3.8s |  |
| 154 | `with_return` | 2 | 3.7s |  |
| 155 | `xml` | 15 | 3.7s |  |
| 156 | `xml_append_child` | 28 | 3.8s |  |
| 157 | `xml_append_child_with_parent` | 20 | 3.8s |  |
| 158 | `xml_attributes_read` | 4 | 3.7s |  |
| 159 | `xml_cdata` | 11 | 3.7s |  |
| 160 | `xml_clone_expandos` | 19 | 3.8s |  |
| 161 | `xml_first_last_child` | 8 | 3.7s |  |
| 162 | `xml_has_child_nodes` | 3 | 3.7s |  |
| 163 | `xml_idmap` | 21 | 3.8s |  |
| 164 | `xml_ignore_white` | 34 | 3.9s |  |
| 165 | `xml_insert_before` | 20 | 3.8s |  |
| 166 | `xml_inspect_createmethods` | 15 | 3.8s |  |
| 167 | `xml_inspect_doctype` | 7 | 3.8s |  |
| 168 | `xml_inspect_parsexml` | 62 | 3.8s |  |
| 169 | `xml_inspect_xmldecl` | 7 | 3.7s |  |
| 170 | `xml_parent_and_child` | 5 | 3.7s |  |
| 171 | `xml_remove_node` | 22 | 3.8s |  |
| 172 | `xml_siblings` | 10 | 3.7s |  |
| 173 | `xml_to_string_comment` | 1 | 3.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**90 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `edittext_default_format_font_style` | 97.6% | 327 | 335 | 8 |  |
| 2 | `edittext_antialiastype` | 92.9% | 275 | 296 | 21 |  |
| 3 | `xml_namespaces` | 92.1% | 187 | 203 | 16 |  |
| 4 | `swf7_case_sensitive` | 90.9% | 40 | 44 | 4 |  |
| 5 | `string_coercion` | 90.7% | 107 | 118 | 11 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 6 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 |  |
| 7 | `textfield_properties` | 86.4% | 38 | 44 | 6 |  |
| 8 | `xml_ignore_comments` | 85.7% | 18 | 21 | 3 |  |
| 9 | `xml_to_string` | 84.6% | 11 | 13 | 2 |  |
| 10 | `object_prototypes` | 83.8% | 62 | 74 | 12 |  |
| 11 | `stage_object_children` | 81.9% | 68 | 83 | 15 |  |
| 12 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 13 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 |  |
| 14 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 15 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 16 | `xml_child_nodes_edge_cases` | 75.0% | 3 | 4 | 1 |  |
| 17 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 18 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 19 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 20 | `globals_swf6` | 71.4% | 217 | 304 | 87 |  |
| 21 | `point` | 70.9% | 124 | 175 | 51 |  |
| 22 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 23 | `globals_swf7` | 70.4% | 214 | 304 | 90 |  |
| 24 | `array_sort` | 69.6% | 112 | 161 | 49 |  |
| 25 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 26 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 27 | `globals_swf5` | 69.1% | 210 | 304 | 94 |  |
| 28 | `transform` | 68.6% | 48 | 70 | 22 |  |
| 29 | `stage_object_properties` | 68.5% | 165 | 241 | 76 |  |
| 30 | `stage_object_properties_swf6` | 68.4% | 158 | 231 | 73 |  |
| 31 | `as_set_prop_flags` | 68.4% | 54 | 79 | 25 |  |
| 32 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 33 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 34 | `edittext_default_format` | 67.6% | 150 | 222 | 72 |  |
| 35 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 36 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 37 | `mcl_getprogress` | 66.7% | 20 | 30 | 10 |  |
| 38 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 39 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 40 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 41 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 42 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 43 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 44 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 45 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 46 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
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
| 57 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 58 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 59 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 60 | `remove_movie_clip` | 58.6% | 17 | 29 | 12 |  |
| 61 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 62 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 63 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 64 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 65 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 66 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 67 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 68 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 69 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 70 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 71 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 |  |
| 72 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 73 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 74 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 75 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 76 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 77 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 78 | `globals_swf8` | 51.0% | 155 | 304 | 149 |  |
| 79 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 80 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 81 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 82 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 83 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 84 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 85 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 86 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 87 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 88 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 89 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 90 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**19 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `button_keypress_vs_tab` | 6.0s |  |
| 2 | `device_font_spacing` | 13.5s |  |
| 3 | `duplicate_movie_clip_drawing` | 5.6s |  |
| 4 | `equals2_swf5` | 14.8s |  |
| 5 | `equals2_swf6` | 14.8s |  |
| 6 | `equals2_swf7` | 14.7s |  |
| 7 | `goto_methods` | 6.3s |  |
| 8 | `greater_swf6` | 14.8s |  |
| 9 | `greater_swf7` | 14.8s |  |
| 10 | `issue_1671` | 5.5s |  |
| 11 | `lessthan2_swf5` | 15.3s |  |
| 12 | `lessthan2_swf6` | 15.4s |  |
| 13 | `lessthan2_swf7` | 15.6s |  |
| 14 | `object_constructor` | 5.6s |  |
| 15 | `path_string` | 6.0s |  |
| 16 | `strictequals_swf6` | 11.7s |  |
| 17 | `swf4_actions_coercion_order` | 5.8s |  |
| 18 | `tab_ordering_tabbable` | 5.8s |  |
| 19 | `textfield_cache_as_bitmap` | 5.5s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**3 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 14.6s |  |
| 2 | `timeout` | runtime timeout (>10s) | 13.8s |  |
| 3 | `try_catch_finally` | runtime timeout (>10s) | 14.1s |  |

## All Output Mismatches

**424 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `edittext_default_format_font_style` | 97.6% | 327/335 | 335 | 335 |  |
| 2 | `edittext_antialiastype` | 92.9% | 275/296 | 296 | 296 |  |
| 3 | `xml_namespaces` | 92.1% | 187/203 | 203 | 203 |  |
| 4 | `swf7_case_sensitive` | 90.9% | 40/44 | 44 | 44 |  |
| 5 | `string_coercion` | 90.7% | 107/118 | 118 | 117 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 6 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 |  |
| 7 | `textfield_properties` | 86.4% | 38/44 | 44 | 44 |  |
| 8 | `xml_ignore_comments` | 85.7% | 18/21 | 21 | 21 |  |
| 9 | `xml_to_string` | 84.6% | 11/13 | 13 | 13 |  |
| 10 | `object_prototypes` | 83.8% | 62/74 | 73 | 74 |  |
| 11 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 |  |
| 12 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 13 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 |  |
| 14 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 15 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 16 | `xml_child_nodes_edge_cases` | 75.0% | 3/4 | 4 | 4 |  |
| 17 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 18 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 19 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 20 | `globals_swf6` | 71.4% | 217/304 | 304 | 304 |  |
| 21 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 22 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 23 | `globals_swf7` | 70.4% | 214/304 | 304 | 304 |  |
| 24 | `array_sort` | 69.6% | 112/161 | 161 | 161 |  |
| 25 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 26 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 27 | `globals_swf5` | 69.1% | 210/304 | 304 | 304 |  |
| 28 | `transform` | 68.6% | 48/70 | 70 | 70 |  |
| 29 | `stage_object_properties` | 68.5% | 165/241 | 241 | 241 |  |
| 30 | `stage_object_properties_swf6` | 68.4% | 158/231 | 231 | 231 |  |
| 31 | `as_set_prop_flags` | 68.4% | 54/79 | 76 | 79 |  |
| 32 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 33 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 34 | `edittext_default_format` | 67.6% | 150/222 | 222 | 221 |  |
| 35 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 36 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 37 | `mcl_getprogress` | 66.7% | 20/30 | 30 | 30 |  |
| 38 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 39 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 40 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 41 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 42 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 43 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 44 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 45 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 46 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
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
| 57 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 58 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 59 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 60 | `remove_movie_clip` | 58.6% | 17/29 | 29 | 29 |  |
| 61 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 62 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 63 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 64 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 65 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 66 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 67 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 68 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 69 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 70 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 71 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 |  |
| 72 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 73 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 74 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 75 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 76 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 77 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 78 | `globals_swf8` | 51.0% | 155/304 | 304 | 304 |  |
| 79 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 80 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 81 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 82 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 83 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 84 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 85 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 86 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 87 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 88 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 89 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 90 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 91 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 92 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 93 | `frame_size_translated_negative` | 47.6% | 10/21 | 20 | 21 |  |
| 94 | `frame_size_translated_positive` | 47.6% | 10/21 | 20 | 21 |  |
| 95 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 96 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 97 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 98 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 99 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 100 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 101 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 102 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 103 | `as2_oop` | 38.5% | 5/13 | 10 | 13 |  |
| 104 | `edittext_html_swf6` | 37.5% | 2016/5377 | 5377 | 5377 |  |
| 105 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 106 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 107 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 108 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 109 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 110 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 111 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 112 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 113 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 114 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 115 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 116 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 117 | `edittext_html_condensewhite_swf7` | 30.2% | 94/311 | 311 | 311 |  |
| 118 | `duplicate_movie_clip` | 30.0% | 6/20 | 14 | 20 |  |
| 119 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 120 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 121 | `edittext_html_condensewhite_swf8` | 29.3% | 91/311 | 311 | 311 |  |
| 122 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 123 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 124 | `edittext_html_swf7` | 25.7% | 1380/5377 | 5377 | 5377 |  |
| 125 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 126 | `edittext_html_swf8` | 25.4% | 1365/5377 | 5377 | 5377 |  |
| 127 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 128 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 129 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 130 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 131 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 132 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 133 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 134 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 135 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 136 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 137 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 138 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 139 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 140 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 141 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 142 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 143 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 144 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 145 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 146 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 147 | `focusrect_property_swf6` | 17.1% | 211/1237 | 1236 | 1237 |  |
| 148 | `focusrect_property_swf7` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 149 | `focusrect_property_swf5` | 16.9% | 209/1237 | 1236 | 1237 |  |
| 150 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 151 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 152 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 153 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 154 | `watch` | 15.4% | 18/117 | 100 | 117 |  |
| 155 | `as2_super_via_manual_prototype` | 15.0% | 6/40 | 16 | 40 |  |
| 156 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 157 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 158 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 159 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 160 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 161 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 162 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 163 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 164 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 165 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 166 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 |  |
| 167 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 168 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 169 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 170 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 171 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 172 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 173 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 174 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 175 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 176 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 177 | `extends_chain` | 11.2% | 15/134 | 114 | 134 |  |
| 178 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 179 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 180 | `unload` | 9.6% | 5/52 | 48 | 52 |  |
| 181 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 182 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 183 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 184 | `add2` | 8.7% | 31/358 | 358 | 354 | [investigation](ruffle-tests/_investigation/add2.md) |
| 185 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 186 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 187 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 188 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 189 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 190 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 191 | `init_object_order` | 6.7% | 1/15 | 5 | 15 |  |
| 192 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 193 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 194 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 195 | `bitmap_data` | 5.8% | 68/1174 | 1174 | 1126 |  |
| 196 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 197 | `mcl_loadclip` | 5.4% | 8/149 | 36 | 149 |  |
| 198 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 199 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 200 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 201 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 202 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 203 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 204 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 205 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 206 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 207 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 208 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 209 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 210 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 211 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 212 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 213 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 214 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 215 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 216 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 217 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 218 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 219 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 220 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 221 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 222 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 223 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 224 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 225 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 226 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 227 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 228 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 229 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 230 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 231 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 232 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 233 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 234 | `global_instance_decls` | 0.1% | 1/758 | 141 | 758 |  |
| 235 | `global_proto_decls` | 0.0% | 2/4497 | 93 | 4497 |  |
| 236 | `array_call_method` | 0.0% | 0/9 | 2 | 9 |  |
| 237 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 238 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 239 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 240 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 241 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 242 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 243 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 244 | `bitmap_data_copypixels` | 0.0% | 0/17 | 0 | 17 |  |
| 245 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 0 | 1075 |  |
| 246 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 247 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 248 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 249 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 250 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 251 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 252 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 253 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 254 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 255 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 256 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 257 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 258 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 259 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 260 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 261 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 262 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 263 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 264 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 265 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 266 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 267 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 268 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 269 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 270 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 271 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 272 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 273 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 274 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 275 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 276 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 277 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 278 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 279 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 280 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 281 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 282 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 283 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 284 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 285 | `extends_native_type` | 0.0% | 0/11 | 4 | 11 |  |
| 286 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 287 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 288 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 289 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 290 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 291 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 292 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 293 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 294 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 295 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 296 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 297 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 298 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 299 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 300 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 301 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 302 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 303 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 304 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 305 | `global_proto_decls_delete` | 0.0% | 0/4158 | 22 | 4158 |  |
| 306 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 307 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 308 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 309 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 310 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 311 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 312 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 313 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 314 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 315 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 316 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 317 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 318 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 319 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 320 | `loadmovie_fail` | 0.0% | 0/2 | 0 | 2 |  |
| 321 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 322 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 323 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 0 | 9 |  |
| 324 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 325 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 326 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 327 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 328 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 329 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 330 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 331 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 332 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 333 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 334 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 335 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 336 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 337 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 338 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 339 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 340 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 341 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 342 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 343 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 344 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 345 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 346 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 347 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 348 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 349 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 350 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 351 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 352 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 353 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 354 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 355 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 356 | `native_objects_swf6` | 0.0% | 0/183 | 183 | 84 |  |
| 357 | `native_objects_swf7` | 0.0% | 0/183 | 183 | 84 |  |
| 358 | `native_objects_swf8` | 0.0% | 0/183 | 183 | 84 |  |
| 359 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 360 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 361 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 362 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 363 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 364 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 365 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 366 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 367 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 368 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 369 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 370 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 371 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 372 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 373 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 374 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 375 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 376 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 377 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 378 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 379 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 380 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 381 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 382 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 383 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 384 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 385 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 386 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 387 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 388 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 389 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 390 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 391 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 392 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 393 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 394 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 395 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 396 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 397 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 398 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 399 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 400 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 401 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 402 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 403 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 404 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 405 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 406 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 407 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 408 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 409 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 410 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 411 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 412 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 413 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 414 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 415 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 416 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 417 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 418 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 419 | `xml_socket` | 0.0% | 0/8 | 0 | 8 |  |
| 420 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 421 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 422 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
| 423 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 424 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
