# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-14 07:48 UTC

**Git SHA**: `cfa68f7f76`

**Run Duration**: 39m 33s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **166** (26.8%) |
| Failing | 453 |
| Total expected lines | 91286 |
| Matching lines | 38258 (41.9%) |
| Mismatched lines | 53028 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 445 | 98.2% |
| Runtime Segfault | 5 | 1.1% |
| Timeout | 3 | 0.7% |

## Passing Tests

**166 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 3.4s |  |
| 2 | `action_to_integer` | 28 | 3.4s |  |
| 3 | `add` | 28 | 3.4s |  |
| 4 | `add2` | 354 | 3.7s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 3.3s |  |
| 6 | `add_swf5` | 28 | 3.3s |  |
| 7 | `array_concat` | 98 | 3.7s |  |
| 8 | `array_constructor` | 30 | 3.6s |  |
| 9 | `array_length` | 42 | 3.7s |  |
| 10 | `array_properties` | 36 | 3.4s |  |
| 11 | `array_slice` | 34 | 3.4s |  |
| 12 | `array_splice` | 207 | 4.1s |  |
| 13 | `array_trivial` | 209 | 3.9s |  |
| 14 | `as1_constructor_v6` | 35 | 3.4s |  |
| 15 | `as1_constructor_v7` | 35 | 3.4s |  |
| 16 | `as_broadcaster_initialize` | 10 | 3.3s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 3.3s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 3.3s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 3.3s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 3.3s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 3.3s |  |
| 22 | `as_transformed_flag` | 20 | 3.4s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 3.2s |  |
| 24 | `bitand` | 1058 | 10.5s |  |
| 25 | `bitmap_data_colortransform` | 0 | 3.6s |  |
| 26 | `bitmap_data_fillrect` | 0 | 3.5s |  |
| 27 | `bitmap_data_max_size_swf10` | 12 | 3.3s |  |
| 28 | `bitmap_data_max_size_swf9` | 10 | 3.3s |  |
| 29 | `bitmap_data_perlinnoise` | 0 | 4.0s |  |
| 30 | `bitmap_data_pixeldissolve_image` | 0 | 3.8s |  |
| 31 | `bitmapdata_applyfilter_colormatrix` | 0 | 3.3s |  |
| 32 | `bitor` | 1058 | 10.6s |  |
| 33 | `biturshift` | 14 | 4.3s |  |
| 34 | `biturshift_swf8` | 14 | 3.2s |  |
| 35 | `bitxor` | 1058 | 9.9s |  |
| 36 | `call_method_empty_name` | 1 | 3.2s |  |
| 37 | `capabilities_resolution` | 8 | 3.2s |  |
| 38 | `catch_references_registers` | 2 | 3.2s |  |
| 39 | `conflicting_instance_names` | 23 | 3.3s |  |
| 40 | `define_function2` | 8 | 3.2s |  |
| 41 | `define_function2_preload` | 13 | 3.2s |  |
| 42 | `define_function2_preload_order` | 4 | 3.2s |  |
| 43 | `define_function_case_sensitive` | 2 | 3.2s |  |
| 44 | `delete` | 3 | 3.3s |  |
| 45 | `display_object_properties` | 2 | 3.2s |  |
| 46 | `divide_swf4` | 107 | 3.3s |  |
| 47 | `do_init_action` | 3 | 3.2s |  |
| 48 | `edittext_default_format_empty` | 95 | 3.5s |  |
| 49 | `edittext_password` | 5 | 3.4s |  |
| 50 | `equals` | 32 | 3.4s |  |
| 51 | `equals2_swf5` | 926 | 12.1s |  |
| 52 | `equals2_swf6` | 926 | 11.4s |  |
| 53 | `equals2_swf7` | 926 | 11.5s |  |
| 54 | `equals_swf4` | 665 | 6.8s |  |
| 55 | `equals_swf4_alt` | 32 | 3.3s |  |
| 56 | `equals_swf5` | 32 | 3.2s |  |
| 57 | `error` | 58 | 3.4s |  |
| 58 | `escape` | 14 | 3.2s |  |
| 59 | `execution_order1` | 5 | 3.2s |  |
| 60 | `execution_order2` | 7 | 3.2s |  |
| 61 | `execution_order3` | 4 | 3.2s |  |
| 62 | `focusrect_mouse_swf8` | 0 | 3.2s |  |
| 63 | `focusrect_mouse_swf9` | 0 | 3.2s |  |
| 64 | `focusrect_swf5` | 6 | 3.4s |  |
| 65 | `get_variable_in_scope` | 29 | 3.4s |  |
| 66 | `getproperty` | 28 | 3.3s |  |
| 67 | `getproperty_swf4` | 28 | 3.3s |  |
| 68 | `getproperty_swf5` | 28 | 3.2s |  |
| 69 | `global_array` | 3 | 3.2s |  |
| 70 | `global_is_bare` | 7 | 3.2s |  |
| 71 | `goto_advance1` | 6 | 3.2s |  |
| 72 | `goto_advance2` | 2 | 3.2s |  |
| 73 | `goto_both_ways1` | 3 | 4.2s |  |
| 74 | `goto_both_ways2` | 3 | 3.5s |  |
| 75 | `goto_execution_order` | 2 | 3.4s |  |
| 76 | `goto_execution_order2` | 2 | 3.4s |  |
| 77 | `goto_frame_number` | 3 | 3.3s |  |
| 78 | `goto_rewind1` | 1 | 3.3s |  |
| 79 | `goto_rewind2` | 3 | 3.4s |  |
| 80 | `goto_rewind3` | 2 | 3.2s |  |
| 81 | `greater_swf6` | 1175 | 12.4s |  |
| 82 | `greater_swf7` | 1175 | 12.3s |  |
| 83 | `greaterthan_swf5` | 1 | 3.2s |  |
| 84 | `greaterthan_swf8` | 1 | 3.2s |  |
| 85 | `has_own_property` | 32 | 3.4s |  |
| 86 | `infinite_recursion_function` | 4 | 3.3s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 87 | `infinite_recursion_function_in_setter` | 131 | 3.3s |  |
| 88 | `infinite_recursion_virtual_property` | 67 | 3.2s |  |
| 89 | `init_array_invalid` | 4 | 3.2s |  |
| 90 | `init_object_invalid` | 4 | 3.2s |  |
| 91 | `issue_1086` | 1 | 3.2s |  |
| 92 | `issue_1671` | 0 | 3.3s |  |
| 93 | `issue_2166` | 9 | 3.3s |  |
| 94 | `issue_3446` | 1 | 3.2s |  |
| 95 | `issue_4377` | 2 | 3.2s |  |
| 96 | `issue_710` | 4 | 3.2s |  |
| 97 | `issue_768` | 3 | 3.2s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 98 | `lessthan` | 41 | 3.3s |  |
| 99 | `lessthan2_swf5` | 1226 | 12.9s |  |
| 100 | `lessthan2_swf6` | 1226 | 12.9s |  |
| 101 | `lessthan2_swf7` | 1226 | 12.9s |  |
| 102 | `lessthan_swf4` | 902 | 8.6s |  |
| 103 | `lessthan_swf4_alt` | 41 | 3.3s |  |
| 104 | `lessthan_swf5` | 41 | 3.3s |  |
| 105 | `logical_ops_swf4` | 90 | 3.2s |  |
| 106 | `logical_ops_swf8` | 108 | 3.3s |  |
| 107 | `looping` | 6 | 3.1s |  |
| 108 | `mask_reapply` | 0 | 3.1s |  |
| 109 | `mask_with_drawing` | 0 | 3.2s |  |
| 110 | `movieclip_begin_gradient_fill` | 0 | 3.8s |  |
| 111 | `movieclip_line_gradient_style` | 0 | 3.8s |  |
| 112 | `movieclip_name_from_timeline` | 13 | 3.2s |  |
| 113 | `movieclip_prototype_extension` | 5 | 3.2s |  |
| 114 | `nested_textfields_in_buttons` | 0 | 3.2s |  |
| 115 | `netstream_play_flv_screen` | 0 | 31.2s |  |
| 116 | `new_method_wrap` | 4 | 3.2s |  |
| 117 | `new_object_wrap` | 4 | 3.2s |  |
| 118 | `o` | 3 | 3.2s |  |
| 119 | `object_constructor` | 33 | 3.4s |  |
| 120 | `object_function` | 32 | 3.3s |  |
| 121 | `object_string_coerce_swf5` | 62 | 3.4s |  |
| 122 | `primitive_instanceof` | 37 | 3.3s |  |
| 123 | `prototype_delete` | 12 | 3.3s |  |
| 124 | `recursive_prototypes` | 0 | 3.2s |  |
| 125 | `sandbox_type_local_file` | 1 | 3.1s |  |
| 126 | `set_variable_scope` | 58 | 3.3s |  |
| 127 | `single_frame` | 1 | 3.1s |  |
| 128 | `sound_start_load` | 0 | 3.2s |  |
| 129 | `stage_object_properties_get_var` | 5 | 3.1s |  |
| 130 | `strictequals_swf6` | 902 | 9.2s |  |
| 131 | `strictly_equals` | 7 | 3.2s |  |
| 132 | `string_coercion` | 117 | 3.8s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 133 | `string_paths_keyevents` | 0 | 3.1s |  |
| 134 | `string_paths_timer` | 0 | 3.2s |  |
| 135 | `swf4_actions_bool` | 96 | 3.3s |  |
| 136 | `swf4_bool` | 4 | 3.2s |  |
| 137 | `swf4_function_calls` | 7 | 4.0s |  |
| 138 | `swf5_encoding` | 3 | 3.1s |  |
| 139 | `tab_ordering_properties_tab_index_edge_case` | 4 | 3.2s |  |
| 140 | `target_path` | 14 | 3.1s |  |
| 141 | `text_format` | 1146 | 3.5s |  |
| 142 | `text_format_display` | 21 | 3.2s |  |
| 143 | `text_format_font_max_length` | 2 | 3.1s |  |
| 144 | `text_format_rounding_swf7` | 840 | 3.4s |  |
| 145 | `text_format_rounding_swf8` | 840 | 3.4s |  |
| 146 | `textfield_background_color` | 11 | 3.2s |  |
| 147 | `textfield_border_color` | 11 | 3.1s |  |
| 148 | `textfield_props_swf6` | 210 | 4.1s |  |
| 149 | `textfield_props_swf7` | 210 | 4.1s |  |
| 150 | `textfield_props_swf8` | 210 | 4.1s |  |
| 151 | `textfield_text` | 7 | 3.1s |  |
| 152 | `textfield_variable` | 81 | 3.6s |  |
| 153 | `this_swf7` | 41 | 3.2s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 154 | `timeline_function_def` | 7 | 3.3s |  |
| 155 | `try_finally_simple` | 16 | 3.3s |  |
| 156 | `typeof` | 22 | 3.3s |  |
| 157 | `typeof_globals` | 7 | 3.2s |  |
| 158 | `uncaught_exception` | 1 | 3.2s |  |
| 159 | `uncaught_exception_bubbled` | 1 | 3.3s |  |
| 160 | `undefined_to_string_swf6` | 4 | 3.3s |  |
| 161 | `unescape` | 43 | 3.4s |  |
| 162 | `use_hand_cursor` | 8 | 3.3s |  |
| 163 | `variable_args` | 5 | 3.4s |  |
| 164 | `waitforframe` | 7 | 3.2s |  |
| 165 | `waitforframe2` | 16 | 3.3s |  |
| 166 | `with_return` | 2 | 3.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**88 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `edittext_default_format_font_style` | 97.6% | 327 | 335 | 8 |  |
| 2 | `edittext_antialiastype` | 92.9% | 275 | 296 | 21 |  |
| 3 | `swf7_case_sensitive` | 90.9% | 40 | 44 | 4 |  |
| 4 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 |  |
| 5 | `textfield_properties` | 86.4% | 38 | 44 | 6 |  |
| 6 | `object_prototypes` | 83.8% | 62 | 74 | 12 |  |
| 7 | `stage_object_children` | 81.9% | 68 | 83 | 15 |  |
| 8 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 9 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 |  |
| 10 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 11 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 12 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 13 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 14 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 15 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 16 | `point` | 70.9% | 124 | 175 | 51 |  |
| 17 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 18 | `globals_swf6` | 69.4% | 211 | 304 | 93 |  |
| 19 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 20 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 21 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 22 | `transform` | 68.6% | 48 | 70 | 22 |  |
| 23 | `stage_object_properties` | 68.5% | 165 | 241 | 76 |  |
| 24 | `globals_swf7` | 68.4% | 208 | 304 | 96 |  |
| 25 | `stage_object_properties_swf6` | 68.4% | 158 | 231 | 73 |  |
| 26 | `as_set_prop_flags` | 68.4% | 54 | 79 | 25 |  |
| 27 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 28 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 29 | `edittext_default_format` | 67.6% | 150 | 222 | 72 |  |
| 30 | `globals_swf5` | 67.1% | 204 | 304 | 100 |  |
| 31 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 32 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 33 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 34 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 35 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 36 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 37 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 38 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 39 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 40 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 41 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 42 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 43 | `with` | 61.2% | 30 | 49 | 19 |  |
| 44 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 45 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 46 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 47 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 48 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 49 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 50 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 51 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 52 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 53 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 54 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 55 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 56 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 57 | `remove_movie_clip` | 58.6% | 17 | 29 | 12 |  |
| 58 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 59 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 60 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
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
| 73 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 74 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 75 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 76 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
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
| 1 | `device_font_spacing` | 13.5s |  |
| 2 | `duplicate_movie_clip_drawing` | 5.2s |  |
| 3 | `goto_methods` | 5.8s |  |
| 4 | `path_string` | 5.7s |  |
| 5 | `swf4_actions_coercion_order` | 5.4s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**3 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 14.4s |  |
| 2 | `timeout` | runtime timeout (>10s) | 13.5s |  |
| 3 | `try_catch_finally` | runtime timeout (>10s) | 13.7s |  |

## All Output Mismatches

**445 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `edittext_default_format_font_style` | 97.6% | 327/335 | 335 | 335 |  |
| 2 | `edittext_antialiastype` | 92.9% | 275/296 | 296 | 296 |  |
| 3 | `swf7_case_sensitive` | 90.9% | 40/44 | 44 | 44 |  |
| 4 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 |  |
| 5 | `textfield_properties` | 86.4% | 38/44 | 44 | 44 |  |
| 6 | `object_prototypes` | 83.8% | 62/74 | 73 | 74 |  |
| 7 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 |  |
| 8 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 9 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 |  |
| 10 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 11 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 12 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 13 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 14 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 15 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 16 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 17 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 18 | `globals_swf6` | 69.4% | 211/304 | 304 | 304 |  |
| 19 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 20 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 21 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 22 | `transform` | 68.6% | 48/70 | 70 | 70 |  |
| 23 | `stage_object_properties` | 68.5% | 165/241 | 241 | 241 |  |
| 24 | `globals_swf7` | 68.4% | 208/304 | 304 | 304 |  |
| 25 | `stage_object_properties_swf6` | 68.4% | 158/231 | 231 | 231 |  |
| 26 | `as_set_prop_flags` | 68.4% | 54/79 | 76 | 79 |  |
| 27 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 28 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 29 | `edittext_default_format` | 67.6% | 150/222 | 222 | 221 |  |
| 30 | `globals_swf5` | 67.1% | 204/304 | 304 | 304 |  |
| 31 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 32 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 33 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 34 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 35 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 36 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 37 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 38 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 39 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 40 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 41 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 42 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 43 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 44 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 45 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 46 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 47 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 48 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 49 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 50 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 51 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 52 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 53 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 54 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 55 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 56 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 57 | `remove_movie_clip` | 58.6% | 17/29 | 29 | 29 |  |
| 58 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 59 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 60 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
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
| 73 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 74 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 75 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 76 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
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
| 89 | `globals_swf8` | 49.0% | 149/304 | 304 | 304 |  |
| 90 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 91 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 92 | `frame_size_translated_negative` | 47.6% | 10/21 | 20 | 21 |  |
| 93 | `frame_size_translated_positive` | 47.6% | 10/21 | 20 | 21 |  |
| 94 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 95 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 96 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 97 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 98 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 99 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 100 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 101 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 102 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 103 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 104 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 105 | `as2_oop` | 38.5% | 5/13 | 10 | 13 |  |
| 106 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 107 | `edittext_html_swf6` | 37.5% | 2016/5377 | 5377 | 5377 |  |
| 108 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 109 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 110 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 111 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 112 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 113 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 114 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 115 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 116 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 117 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 118 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 119 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 120 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 121 | `edittext_html_condensewhite_swf7` | 30.2% | 94/311 | 311 | 311 |  |
| 122 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 123 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 124 | `edittext_html_condensewhite_swf8` | 29.3% | 91/311 | 311 | 311 |  |
| 125 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 126 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 127 | `edittext_html_swf7` | 25.7% | 1380/5377 | 5377 | 5377 |  |
| 128 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 129 | `edittext_html_swf8` | 25.4% | 1365/5377 | 5377 | 5377 |  |
| 130 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 131 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 132 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 133 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 134 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 135 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 136 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 137 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 138 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 139 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 140 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 141 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 142 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 143 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 144 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 145 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 146 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 147 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 148 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 149 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 150 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 151 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 152 | `focusrect_property_swf6` | 17.1% | 211/1237 | 1236 | 1237 |  |
| 153 | `focusrect_property_swf7` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 154 | `focusrect_property_swf5` | 16.9% | 209/1237 | 1236 | 1237 |  |
| 155 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 156 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 157 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 158 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 159 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 160 | `watch` | 15.4% | 18/117 | 100 | 117 |  |
| 161 | `as2_super_via_manual_prototype` | 15.0% | 6/40 | 16 | 40 |  |
| 162 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 163 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 164 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 165 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 166 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 167 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 168 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 169 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 170 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 171 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 172 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 173 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 174 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 |  |
| 175 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 176 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 177 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 178 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 179 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 180 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 181 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 182 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 183 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 184 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 185 | `extends_chain` | 11.2% | 15/134 | 114 | 134 |  |
| 186 | `edittext_autosize_setter` | 10.0% | 2/20 | 20 | 20 |  |
| 187 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 188 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 189 | `unload` | 9.6% | 5/52 | 48 | 52 |  |
| 190 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 191 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 192 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 193 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 194 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 195 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 196 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 197 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 198 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 199 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 200 | `init_object_order` | 6.7% | 1/15 | 5 | 15 |  |
| 201 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 202 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 203 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 204 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 205 | `bitmap_data` | 5.8% | 68/1174 | 1174 | 1126 |  |
| 206 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 207 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 208 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 209 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 210 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 211 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 212 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 213 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 214 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 215 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 216 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 217 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 218 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 219 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 220 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 221 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 222 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 223 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 224 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 225 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 226 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 227 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 228 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 229 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 230 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 231 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 232 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 233 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 234 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 235 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 236 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 237 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 238 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 239 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 240 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 241 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 242 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 243 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 244 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 245 | `global_instance_decls` | 0.1% | 1/758 | 83 | 758 |  |
| 246 | `global_proto_decls` | 0.0% | 2/4497 | 60 | 4497 |  |
| 247 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 248 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 249 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 250 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 251 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 252 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 253 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 254 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 255 | `bitmap_data_copypixels` | 0.0% | 0/17 | 0 | 17 |  |
| 256 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 0 | 1075 |  |
| 257 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 258 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 259 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 260 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 261 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 262 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 263 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 264 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 265 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 266 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 267 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 268 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 269 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 270 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 271 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 272 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 273 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 274 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 275 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 276 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 277 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 278 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 279 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 280 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 281 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 282 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 283 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 284 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 285 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 286 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 287 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 288 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 289 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 290 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 291 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 292 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 293 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 294 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 295 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 296 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 297 | `extends_native_type` | 0.0% | 0/11 | 4 | 11 |  |
| 298 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 299 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 300 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 301 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 302 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 303 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 304 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 305 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 306 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 307 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 308 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 309 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 310 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 311 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 312 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 313 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 314 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 315 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 316 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 317 | `global_proto_decls_delete` | 0.0% | 0/4158 | 18 | 4158 |  |
| 318 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 319 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 320 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 321 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 322 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 323 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 324 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 325 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 326 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 327 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 328 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 329 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 330 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 331 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 332 | `loadmovie_fail` | 0.0% | 0/2 | 0 | 2 |  |
| 333 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 334 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 335 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 0 | 9 |  |
| 336 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 337 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 338 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 339 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 340 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 341 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 342 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 343 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 344 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 345 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 346 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 347 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 348 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 349 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 350 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 351 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 352 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 353 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 354 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 355 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 356 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 357 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 358 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 359 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 360 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 361 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 362 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 363 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 364 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 365 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 366 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 367 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 368 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 369 | `native_objects_swf6` | 0.0% | 0/183 | 183 | 84 |  |
| 370 | `native_objects_swf7` | 0.0% | 0/183 | 183 | 84 |  |
| 371 | `native_objects_swf8` | 0.0% | 0/183 | 183 | 84 |  |
| 372 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 373 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 374 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 375 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 376 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 377 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 378 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 379 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 380 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 381 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 382 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 383 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 384 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 385 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 386 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 387 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 388 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 389 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 390 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 391 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 392 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 393 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 394 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 395 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 396 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 397 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 398 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 399 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 400 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 401 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 402 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 403 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 404 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 405 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 406 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 407 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 408 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 409 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 410 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 411 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 412 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 413 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 414 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 415 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 416 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 417 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 418 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 419 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 420 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 421 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 422 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 423 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 424 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 425 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 426 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 427 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 428 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 429 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 430 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 431 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 432 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 433 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 434 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 435 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 436 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 437 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 438 | `xml_socket` | 0.0% | 0/8 | 0 | 8 |  |
| 439 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 440 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 441 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
| 442 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 443 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 444 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 445 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
