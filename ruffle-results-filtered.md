# Ruffle Test Results (Filtered)

**Date**: 2026-02-14 08:00 UTC

**Git SHA**: `2705024114`

**Run Duration**: 39m 18s

**Filtered**: 135 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 484 |
| Passing | **166** (34.3%) |
| Failing | 318 |
| Total expected lines | 77821 |
| Matching lines | 36734 (47.2%) |
| Mismatched lines | 41087 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 310 | 97.5% |
| Segfault | 5 | 1.6% |
| Timeout | 3 | 0.9% |

## Passing Tests

**166 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 3.2s |  |
| 2 | `action_to_integer` | 28 | 3.2s |  |
| 3 | `add` | 28 | 3.2s |  |
| 4 | `add2` | 354 | 3.6s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 3.2s |  |
| 6 | `add_swf5` | 28 | 3.2s |  |
| 7 | `array_concat` | 98 | 3.4s |  |
| 8 | `array_constructor` | 30 | 3.3s |  |
| 9 | `array_length` | 42 | 3.4s |  |
| 10 | `array_properties` | 36 | 3.3s |  |
| 11 | `array_slice` | 34 | 3.3s |  |
| 12 | `array_splice` | 207 | 4.0s |  |
| 13 | `array_trivial` | 209 | 3.7s |  |
| 14 | `as1_constructor_v6` | 35 | 3.3s |  |
| 15 | `as1_constructor_v7` | 35 | 3.3s |  |
| 16 | `as_broadcaster_initialize` | 10 | 3.2s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 3.2s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 3.2s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 3.2s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 3.2s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 3.2s |  |
| 22 | `as_transformed_flag` | 20 | 3.2s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 3.1s |  |
| 24 | `bitand` | 1058 | 9.7s |  |
| 25 | `bitmap_data_colortransform` | 0 | 3.5s |  |
| 26 | `bitmap_data_fillrect` | 0 | 3.4s |  |
| 27 | `bitmap_data_max_size_swf10` | 12 | 3.2s |  |
| 28 | `bitmap_data_max_size_swf9` | 10 | 3.2s |  |
| 29 | `bitmap_data_perlinnoise` | 0 | 3.9s |  |
| 30 | `bitmap_data_pixeldissolve_image` | 0 | 3.7s |  |
| 31 | `bitmapdata_applyfilter_colormatrix` | 0 | 3.2s |  |
| 32 | `bitor` | 1058 | 9.8s |  |
| 33 | `biturshift` | 14 | 3.5s |  |
| 34 | `biturshift_swf8` | 14 | 3.3s |  |
| 35 | `bitxor` | 1058 | 10.5s |  |
| 36 | `call_method_empty_name` | 1 | 3.2s |  |
| 37 | `capabilities_resolution` | 8 | 3.2s |  |
| 38 | `catch_references_registers` | 2 | 3.2s |  |
| 39 | `conflicting_instance_names` | 23 | 3.4s |  |
| 40 | `define_function2` | 8 | 3.2s |  |
| 41 | `define_function2_preload` | 13 | 3.3s |  |
| 42 | `define_function2_preload_order` | 4 | 3.2s |  |
| 43 | `define_function_case_sensitive` | 2 | 3.3s |  |
| 44 | `delete` | 3 | 3.4s |  |
| 45 | `display_object_properties` | 2 | 3.2s |  |
| 46 | `divide_swf4` | 107 | 3.4s |  |
| 47 | `do_init_action` | 3 | 3.3s |  |
| 48 | `edittext_autosize_setter` | 20 | 3.3s |  |
| 49 | `edittext_default_format_empty` | 95 | 3.3s |  |
| 50 | `equals` | 32 | 3.3s |  |
| 51 | `equals2_swf5` | 926 | 11.5s |  |
| 52 | `equals2_swf6` | 926 | 11.5s |  |
| 53 | `equals2_swf7` | 926 | 11.4s |  |
| 54 | `equals_swf4` | 665 | 6.7s |  |
| 55 | `equals_swf4_alt` | 32 | 3.2s |  |
| 56 | `equals_swf5` | 32 | 3.2s |  |
| 57 | `error` | 58 | 3.4s |  |
| 58 | `escape` | 14 | 3.2s |  |
| 59 | `execution_order1` | 5 | 3.2s |  |
| 60 | `execution_order2` | 7 | 3.3s |  |
| 61 | `execution_order3` | 4 | 3.2s |  |
| 62 | `focusrect_mouse_swf8` | 0 | 3.0s |  |
| 63 | `focusrect_mouse_swf9` | 0 | 3.0s |  |
| 64 | `focusrect_swf5` | 6 | 3.2s |  |
| 65 | `get_variable_in_scope` | 29 | 3.2s |  |
| 66 | `getproperty` | 28 | 3.1s |  |
| 67 | `getproperty_swf4` | 28 | 3.1s |  |
| 68 | `getproperty_swf5` | 28 | 3.1s |  |
| 69 | `global_array` | 3 | 3.0s |  |
| 70 | `global_is_bare` | 7 | 3.0s |  |
| 71 | `goto_advance1` | 6 | 3.0s |  |
| 72 | `goto_advance2` | 2 | 3.0s |  |
| 73 | `goto_both_ways1` | 3 | 3.4s |  |
| 74 | `goto_both_ways2` | 3 | 3.3s |  |
| 75 | `goto_execution_order` | 2 | 3.2s |  |
| 76 | `goto_execution_order2` | 2 | 3.2s |  |
| 77 | `goto_frame_number` | 3 | 3.3s |  |
| 78 | `goto_rewind1` | 1 | 3.3s |  |
| 79 | `goto_rewind2` | 3 | 3.3s |  |
| 80 | `goto_rewind3` | 2 | 3.2s |  |
| 81 | `greater_swf6` | 1175 | 12.4s |  |
| 82 | `greater_swf7` | 1175 | 12.2s |  |
| 83 | `greaterthan_swf5` | 1 | 3.2s |  |
| 84 | `greaterthan_swf8` | 1 | 3.2s |  |
| 85 | `has_own_property` | 32 | 3.3s |  |
| 86 | `infinite_recursion_function` | 4 | 3.2s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 87 | `infinite_recursion_function_in_setter` | 131 | 3.2s |  |
| 88 | `infinite_recursion_virtual_property` | 67 | 3.2s |  |
| 89 | `init_array_invalid` | 4 | 3.2s |  |
| 90 | `init_object_invalid` | 4 | 3.2s |  |
| 91 | `issue_1086` | 1 | 3.1s |  |
| 92 | `issue_1671` | 0 | 3.2s |  |
| 93 | `issue_2166` | 9 | 3.2s |  |
| 94 | `issue_3446` | 1 | 3.2s |  |
| 95 | `issue_4377` | 2 | 3.2s |  |
| 96 | `issue_710` | 4 | 3.2s |  |
| 97 | `issue_768` | 3 | 3.2s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 98 | `lessthan` | 41 | 3.3s |  |
| 99 | `lessthan2_swf5` | 1226 | 12.8s |  |
| 100 | `lessthan2_swf6` | 1226 | 12.9s |  |
| 101 | `lessthan2_swf7` | 1226 | 12.9s |  |
| 102 | `lessthan_swf4` | 902 | 8.6s |  |
| 103 | `lessthan_swf4_alt` | 41 | 3.3s |  |
| 104 | `lessthan_swf5` | 41 | 3.3s |  |
| 105 | `logical_ops_swf4` | 90 | 3.5s |  |
| 106 | `logical_ops_swf8` | 108 | 3.5s |  |
| 107 | `looping` | 6 | 3.4s |  |
| 108 | `mask_reapply` | 0 | 3.4s |  |
| 109 | `mask_with_drawing` | 0 | 3.5s |  |
| 110 | `movieclip_begin_gradient_fill` | 0 | 4.0s |  |
| 111 | `movieclip_line_gradient_style` | 0 | 4.0s |  |
| 112 | `movieclip_name_from_timeline` | 13 | 3.4s |  |
| 113 | `movieclip_prototype_extension` | 5 | 3.4s |  |
| 114 | `nested_textfields_in_buttons` | 0 | 3.4s |  |
| 115 | `netstream_play_flv_screen` | 0 | 32.5s |  |
| 116 | `new_method_wrap` | 4 | 3.3s |  |
| 117 | `new_object_wrap` | 4 | 3.4s |  |
| 118 | `o` | 3 | 3.4s |  |
| 119 | `object_constructor` | 33 | 3.5s |  |
| 120 | `object_function` | 32 | 3.5s |  |
| 121 | `object_string_coerce_swf5` | 62 | 3.5s |  |
| 122 | `primitive_instanceof` | 37 | 3.4s |  |
| 123 | `prototype_delete` | 12 | 3.4s |  |
| 124 | `recursive_prototypes` | 0 | 3.4s |  |
| 125 | `sandbox_type_local_file` | 1 | 3.0s |  |
| 126 | `set_variable_scope` | 58 | 3.2s |  |
| 127 | `single_frame` | 1 | 3.0s |  |
| 128 | `sound_start_load` | 0 | 3.1s |  |
| 129 | `stage_object_properties_get_var` | 5 | 3.0s |  |
| 130 | `strictequals_swf6` | 902 | 8.7s |  |
| 131 | `strictly_equals` | 7 | 3.1s |  |
| 132 | `string_coercion` | 117 | 3.7s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 133 | `string_paths_keyevents` | 0 | 3.0s |  |
| 134 | `string_paths_timer` | 0 | 3.1s |  |
| 135 | `swf4_actions_bool` | 96 | 3.2s |  |
| 136 | `swf4_bool` | 4 | 3.0s |  |
| 137 | `swf4_function_calls` | 7 | 3.4s |  |
| 138 | `swf5_encoding` | 3 | 3.2s |  |
| 139 | `tab_ordering_properties_tab_index_edge_case` | 4 | 3.2s |  |
| 140 | `target_path` | 14 | 3.2s |  |
| 141 | `text_format` | 1146 | 3.6s |  |
| 142 | `text_format_display` | 21 | 3.3s |  |
| 143 | `text_format_font_max_length` | 2 | 3.2s |  |
| 144 | `text_format_rounding_swf7` | 840 | 3.5s |  |
| 145 | `text_format_rounding_swf8` | 840 | 3.5s |  |
| 146 | `textfield_background_color` | 11 | 3.2s |  |
| 147 | `textfield_border_color` | 11 | 3.2s |  |
| 148 | `textfield_props_swf6` | 210 | 4.1s |  |
| 149 | `textfield_props_swf7` | 210 | 4.1s |  |
| 150 | `textfield_props_swf8` | 210 | 4.1s |  |
| 151 | `textfield_text` | 7 | 3.2s |  |
| 152 | `textfield_variable` | 81 | 3.7s |  |
| 153 | `this_swf7` | 41 | 3.3s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 154 | `timeline_function_def` | 7 | 3.4s |  |
| 155 | `try_finally_simple` | 16 | 3.2s |  |
| 156 | `typeof` | 22 | 3.2s |  |
| 157 | `typeof_globals` | 7 | 3.2s |  |
| 158 | `uncaught_exception` | 1 | 3.2s |  |
| 159 | `uncaught_exception_bubbled` | 1 | 3.2s |  |
| 160 | `undefined_to_string_swf6` | 4 | 3.2s |  |
| 161 | `unescape` | 43 | 3.3s |  |
| 162 | `use_hand_cursor` | 8 | 3.2s |  |
| 163 | `variable_args` | 5 | 3.3s |  |
| 164 | `waitforframe` | 7 | 3.2s |  |
| 165 | `waitforframe2` | 16 | 3.3s |  |
| 166 | `with_return` | 2 | 3.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**78 tests** within reach

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
| 36 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 37 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 38 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 39 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 40 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 41 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 42 | `with` | 61.2% | 30 | 49 | 19 |  |
| 43 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 44 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 45 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 46 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 47 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 48 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 49 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 50 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 51 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 52 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 53 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 54 | `remove_movie_clip` | 58.6% | 17 | 29 | 12 |  |
| 55 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 56 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
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
| 67 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 68 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 69 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 70 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 71 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 72 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 73 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 74 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 75 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 76 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 77 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 78 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 13.5s |  |
| 2 | `duplicate_movie_clip_drawing` | 5.2s |  |
| 3 | `goto_methods` | 5.9s |  |
| 4 | `path_string` | 5.9s |  |
| 5 | `swf4_actions_coercion_order` | 4.7s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**3 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 14.4s |  |
| 2 | `timeout` | runtime timeout (>10s) | 13.4s |  |
| 3 | `try_catch_finally` | runtime timeout (>10s) | 13.7s |  |

## All Output Mismatches

**310 tests** with output mismatch, sorted by match rate (best first)

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
| 36 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 37 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 38 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 39 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 40 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 41 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 42 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 43 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 44 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 45 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 46 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 47 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 48 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 49 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 50 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 51 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 52 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 53 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 54 | `remove_movie_clip` | 58.6% | 17/29 | 29 | 29 |  |
| 55 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 56 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
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
| 67 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 68 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 69 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 70 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 71 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 72 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 73 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 74 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 75 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 76 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 77 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 78 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 79 | `globals_swf8` | 49.0% | 149/304 | 304 | 304 |  |
| 80 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 81 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 82 | `frame_size_translated_negative` | 47.6% | 10/21 | 20 | 21 |  |
| 83 | `frame_size_translated_positive` | 47.6% | 10/21 | 20 | 21 |  |
| 84 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 85 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 86 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 87 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 88 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 89 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 90 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 91 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 92 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 93 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 94 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 95 | `as2_oop` | 38.5% | 5/13 | 10 | 13 |  |
| 96 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 97 | `edittext_html_swf6` | 37.5% | 2016/5377 | 5377 | 5377 |  |
| 98 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 99 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 100 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 101 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 102 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 103 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 104 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 105 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 106 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 107 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 108 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 109 | `edittext_html_condensewhite_swf7` | 30.2% | 94/311 | 311 | 311 |  |
| 110 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 111 | `edittext_html_condensewhite_swf8` | 29.3% | 91/311 | 311 | 311 |  |
| 112 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 113 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 114 | `edittext_html_swf7` | 25.7% | 1380/5377 | 5377 | 5377 |  |
| 115 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 116 | `edittext_html_swf8` | 25.4% | 1365/5377 | 5377 | 5377 |  |
| 117 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 118 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 119 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 120 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 121 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 122 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 123 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 124 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 125 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 126 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 127 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 128 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 129 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 130 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 131 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 132 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 133 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 134 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 135 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 136 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 137 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 138 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 139 | `watch` | 15.4% | 18/117 | 100 | 117 |  |
| 140 | `as2_super_via_manual_prototype` | 15.0% | 6/40 | 16 | 40 |  |
| 141 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 142 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 143 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 144 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 145 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 146 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 147 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 148 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 149 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 150 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 |  |
| 151 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 152 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 153 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 154 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 155 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 156 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 157 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 158 | `extends_chain` | 11.2% | 15/134 | 114 | 134 |  |
| 159 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 160 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 161 | `unload` | 9.6% | 5/52 | 48 | 52 |  |
| 162 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 163 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 164 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 165 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 166 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 167 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 168 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 169 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 170 | `init_object_order` | 6.7% | 1/15 | 5 | 15 |  |
| 171 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 172 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 173 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 174 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 175 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 176 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 177 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 178 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 179 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 180 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 181 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 182 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 183 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 184 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 185 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 186 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 187 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 188 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 189 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 190 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 191 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 192 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 193 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 194 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 195 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 196 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 197 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 198 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 199 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 200 | `global_instance_decls` | 0.1% | 1/758 | 83 | 758 |  |
| 201 | `global_proto_decls` | 0.0% | 2/4497 | 60 | 4497 |  |
| 202 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 203 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 204 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 205 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 206 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 207 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 208 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 209 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 210 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 211 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 212 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 213 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 214 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 215 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 216 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 217 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 218 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 219 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 220 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 221 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 222 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 223 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 224 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 225 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 226 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 227 | `extends_native_type` | 0.0% | 0/11 | 4 | 11 |  |
| 228 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 229 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 230 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 231 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 232 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 233 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 234 | `global_proto_decls_delete` | 0.0% | 0/4158 | 18 | 4158 |  |
| 235 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 236 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 237 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 238 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 239 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 240 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 241 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 242 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 243 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 244 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 245 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 246 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 247 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 248 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 249 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 250 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 251 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 252 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 253 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 254 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 255 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 256 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 257 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 258 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 259 | `native_objects_swf6` | 0.0% | 0/183 | 183 | 84 |  |
| 260 | `native_objects_swf7` | 0.0% | 0/183 | 183 | 84 |  |
| 261 | `native_objects_swf8` | 0.0% | 0/183 | 183 | 84 |  |
| 262 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 263 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 264 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 265 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 266 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 267 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 268 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 269 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 270 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 271 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 272 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 273 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 274 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 275 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 276 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 277 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 278 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 279 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 280 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 281 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 282 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 283 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 284 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 285 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 286 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 287 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 288 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 289 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 290 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 291 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 292 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 293 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 294 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 295 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 296 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 297 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 298 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 299 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 300 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 301 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 302 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 303 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 304 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 305 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 306 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 307 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 308 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 309 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 310 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
