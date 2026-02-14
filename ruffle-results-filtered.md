# Ruffle Test Results (Filtered)

**Date**: 2026-02-14 05:43 UTC

**Git SHA**: `75322310bc`

**Run Duration**: 37m 8s

**Filtered**: 135 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 484 |
| Passing | **163** (33.7%) |
| Failing | 321 |
| Total expected lines | 77821 |
| Matching lines | 36087 (46.4%) |
| Mismatched lines | 41734 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 313 | 97.5% |
| Segfault | 5 | 1.6% |
| Timeout | 3 | 0.9% |

## Passing Tests

**163 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 5.3s |  |
| 2 | `action_to_integer` | 28 | 3.1s |  |
| 3 | `add` | 28 | 3.1s |  |
| 4 | `add2` | 354 | 3.5s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 3.0s |  |
| 6 | `add_swf5` | 28 | 3.0s |  |
| 7 | `array_concat` | 98 | 3.3s |  |
| 8 | `array_constructor` | 30 | 3.1s |  |
| 9 | `array_length` | 42 | 3.2s |  |
| 10 | `array_properties` | 36 | 3.1s |  |
| 11 | `array_slice` | 34 | 3.2s |  |
| 12 | `array_splice` | 207 | 3.8s |  |
| 13 | `array_trivial` | 209 | 3.6s |  |
| 14 | `as1_constructor_v6` | 35 | 3.1s |  |
| 15 | `as1_constructor_v7` | 35 | 3.1s |  |
| 16 | `as_broadcaster_initialize` | 10 | 3.0s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 3.0s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 3.1s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 3.0s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 3.0s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 3.0s |  |
| 22 | `as_transformed_flag` | 20 | 3.1s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 2.9s |  |
| 24 | `bitand` | 1058 | 9.9s |  |
| 25 | `bitmap_data_colortransform` | 0 | 3.3s |  |
| 26 | `bitmap_data_fillrect` | 0 | 3.2s |  |
| 27 | `bitmap_data_max_size_swf10` | 12 | 3.0s |  |
| 28 | `bitmap_data_max_size_swf9` | 10 | 3.0s |  |
| 29 | `bitmap_data_perlinnoise` | 0 | 3.8s |  |
| 30 | `bitmap_data_pixeldissolve_image` | 0 | 3.6s |  |
| 31 | `bitmapdata_applyfilter_colormatrix` | 0 | 3.1s |  |
| 32 | `bitor` | 1058 | 9.8s |  |
| 33 | `biturshift` | 14 | 3.9s |  |
| 34 | `biturshift_swf8` | 14 | 3.0s |  |
| 35 | `bitxor` | 1058 | 10.1s |  |
| 36 | `call_method_empty_name` | 1 | 2.9s |  |
| 37 | `capabilities_resolution` | 8 | 2.9s |  |
| 38 | `catch_references_registers` | 2 | 2.9s |  |
| 39 | `conflicting_instance_names` | 23 | 3.1s |  |
| 40 | `define_function2` | 8 | 2.9s |  |
| 41 | `define_function2_preload` | 13 | 3.0s |  |
| 42 | `define_function2_preload_order` | 4 | 2.9s |  |
| 43 | `define_function_case_sensitive` | 2 | 2.9s |  |
| 44 | `delete` | 3 | 3.0s |  |
| 45 | `display_object_properties` | 2 | 2.9s |  |
| 46 | `divide_swf4` | 107 | 3.1s |  |
| 47 | `do_init_action` | 3 | 3.0s |  |
| 48 | `equals` | 32 | 3.1s |  |
| 49 | `equals2_swf5` | 926 | 11.2s |  |
| 50 | `equals2_swf6` | 926 | 11.3s |  |
| 51 | `equals2_swf7` | 926 | 11.2s |  |
| 52 | `equals_swf4` | 665 | 6.5s |  |
| 53 | `equals_swf4_alt` | 32 | 3.0s |  |
| 54 | `equals_swf5` | 32 | 3.0s |  |
| 55 | `error` | 58 | 3.2s |  |
| 56 | `escape` | 14 | 3.0s |  |
| 57 | `execution_order1` | 5 | 3.0s |  |
| 58 | `execution_order2` | 7 | 3.0s |  |
| 59 | `execution_order3` | 4 | 3.0s |  |
| 60 | `focusrect_mouse_swf8` | 0 | 3.0s |  |
| 61 | `focusrect_mouse_swf9` | 0 | 3.0s |  |
| 62 | `focusrect_swf5` | 6 | 3.1s |  |
| 63 | `get_variable_in_scope` | 29 | 3.1s |  |
| 64 | `getproperty` | 28 | 3.0s |  |
| 65 | `getproperty_swf4` | 28 | 3.0s |  |
| 66 | `getproperty_swf5` | 28 | 3.0s |  |
| 67 | `global_array` | 3 | 3.0s |  |
| 68 | `global_is_bare` | 7 | 2.9s |  |
| 69 | `goto_advance1` | 6 | 3.0s |  |
| 70 | `goto_advance2` | 2 | 3.0s |  |
| 71 | `goto_both_ways1` | 3 | 3.2s |  |
| 72 | `goto_both_ways2` | 3 | 3.0s |  |
| 73 | `goto_execution_order` | 2 | 3.0s |  |
| 74 | `goto_execution_order2` | 2 | 3.0s |  |
| 75 | `goto_frame_number` | 3 | 3.0s |  |
| 76 | `goto_rewind1` | 1 | 3.0s |  |
| 77 | `goto_rewind2` | 3 | 3.1s |  |
| 78 | `goto_rewind3` | 2 | 3.0s |  |
| 79 | `greater_swf6` | 1175 | 11.8s |  |
| 80 | `greater_swf7` | 1175 | 12.0s |  |
| 81 | `greaterthan_swf5` | 1 | 2.9s |  |
| 82 | `greaterthan_swf8` | 1 | 3.0s |  |
| 83 | `has_own_property` | 32 | 3.1s |  |
| 84 | `infinite_recursion_function` | 4 | 3.0s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 85 | `infinite_recursion_function_in_setter` | 131 | 3.0s |  |
| 86 | `infinite_recursion_virtual_property` | 67 | 3.0s |  |
| 87 | `init_array_invalid` | 4 | 2.9s |  |
| 88 | `init_object_invalid` | 4 | 2.9s |  |
| 89 | `issue_1086` | 1 | 2.9s |  |
| 90 | `issue_1671` | 0 | 3.0s |  |
| 91 | `issue_2166` | 9 | 3.0s |  |
| 92 | `issue_3446` | 1 | 3.0s |  |
| 93 | `issue_4377` | 2 | 3.0s |  |
| 94 | `issue_710` | 4 | 2.9s |  |
| 95 | `issue_768` | 3 | 3.0s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 96 | `lessthan` | 41 | 3.1s |  |
| 97 | `lessthan2_swf5` | 1226 | 12.4s |  |
| 98 | `lessthan2_swf6` | 1226 | 12.4s |  |
| 99 | `lessthan2_swf7` | 1226 | 12.4s |  |
| 100 | `lessthan_swf4` | 902 | 8.3s |  |
| 101 | `lessthan_swf4_alt` | 41 | 3.0s |  |
| 102 | `lessthan_swf5` | 41 | 3.0s |  |
| 103 | `logical_ops_swf4` | 90 | 3.1s |  |
| 104 | `logical_ops_swf8` | 108 | 3.2s |  |
| 105 | `looping` | 6 | 3.1s |  |
| 106 | `mask_reapply` | 0 | 3.0s |  |
| 107 | `mask_with_drawing` | 0 | 3.0s |  |
| 108 | `movieclip_begin_gradient_fill` | 0 | 3.7s |  |
| 109 | `movieclip_line_gradient_style` | 0 | 3.6s |  |
| 110 | `movieclip_name_from_timeline` | 13 | 3.0s |  |
| 111 | `movieclip_prototype_extension` | 5 | 3.0s |  |
| 112 | `nested_textfields_in_buttons` | 0 | 3.0s |  |
| 113 | `netstream_play_flv_screen` | 0 | 30.3s |  |
| 114 | `new_method_wrap` | 4 | 3.0s |  |
| 115 | `new_object_wrap` | 4 | 3.0s |  |
| 116 | `o` | 3 | 3.0s |  |
| 117 | `object_constructor` | 33 | 3.1s |  |
| 118 | `object_function` | 32 | 3.1s |  |
| 119 | `object_string_coerce_swf5` | 62 | 3.1s |  |
| 120 | `primitive_instanceof` | 37 | 3.1s |  |
| 121 | `prototype_delete` | 12 | 3.1s |  |
| 122 | `recursive_prototypes` | 0 | 3.0s |  |
| 123 | `sandbox_type_local_file` | 1 | 3.0s |  |
| 124 | `set_variable_scope` | 58 | 3.2s |  |
| 125 | `single_frame` | 1 | 3.0s |  |
| 126 | `sound_start_load` | 0 | 3.1s |  |
| 127 | `stage_object_properties_get_var` | 5 | 3.0s |  |
| 128 | `strictequals_swf6` | 902 | 9.6s |  |
| 129 | `strictly_equals` | 7 | 3.1s |  |
| 130 | `string_coercion` | 117 | 3.7s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 131 | `string_paths_keyevents` | 0 | 3.1s |  |
| 132 | `string_paths_timer` | 0 | 3.1s |  |
| 133 | `swf4_actions_bool` | 96 | 3.2s |  |
| 134 | `swf4_bool` | 4 | 3.1s |  |
| 135 | `swf4_function_calls` | 7 | 5.0s |  |
| 136 | `swf5_encoding` | 3 | 2.9s |  |
| 137 | `tab_ordering_properties_tab_index_edge_case` | 4 | 3.0s |  |
| 138 | `target_path` | 14 | 3.0s |  |
| 139 | `text_format` | 1146 | 3.4s |  |
| 140 | `text_format_display` | 21 | 3.1s |  |
| 141 | `text_format_font_max_length` | 2 | 3.0s |  |
| 142 | `text_format_rounding_swf7` | 840 | 3.3s |  |
| 143 | `text_format_rounding_swf8` | 840 | 3.3s |  |
| 144 | `textfield_background_color` | 11 | 3.0s |  |
| 145 | `textfield_border_color` | 11 | 3.0s |  |
| 146 | `textfield_props_swf6` | 210 | 4.0s |  |
| 147 | `textfield_props_swf7` | 210 | 4.0s |  |
| 148 | `textfield_props_swf8` | 210 | 4.0s |  |
| 149 | `textfield_text` | 7 | 3.0s |  |
| 150 | `this_swf7` | 41 | 3.1s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 151 | `timeline_function_def` | 7 | 3.1s |  |
| 152 | `try_finally_simple` | 16 | 3.0s |  |
| 153 | `typeof` | 22 | 3.0s |  |
| 154 | `typeof_globals` | 7 | 2.9s |  |
| 155 | `uncaught_exception` | 1 | 2.9s |  |
| 156 | `uncaught_exception_bubbled` | 1 | 3.0s |  |
| 157 | `undefined_to_string_swf6` | 4 | 3.0s |  |
| 158 | `unescape` | 43 | 3.1s |  |
| 159 | `use_hand_cursor` | 8 | 3.0s |  |
| 160 | `variable_args` | 5 | 3.1s |  |
| 161 | `waitforframe` | 7 | 2.9s |  |
| 162 | `waitforframe2` | 16 | 3.0s |  |
| 163 | `with_return` | 2 | 2.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**76 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `swf7_case_sensitive` | 90.9% | 40 | 44 | 4 |  |
| 2 | `object_prototypes` | 83.8% | 62 | 74 | 12 |  |
| 3 | `stage_object_children` | 81.9% | 68 | 83 | 15 |  |
| 4 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 5 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 6 | `textfield_properties` | 79.5% | 35 | 44 | 9 |  |
| 7 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 8 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 9 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 10 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 11 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 12 | `point` | 70.9% | 124 | 175 | 51 |  |
| 13 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 14 | `globals_swf6` | 69.4% | 211 | 304 | 93 |  |
| 15 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 16 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 17 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 18 | `stage_object_properties` | 68.5% | 165 | 241 | 76 |  |
| 19 | `globals_swf7` | 68.4% | 208 | 304 | 96 |  |
| 20 | `stage_object_properties_swf6` | 68.4% | 158 | 231 | 73 |  |
| 21 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 22 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 23 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 24 | `globals_swf5` | 67.1% | 204 | 304 | 100 |  |
| 25 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 26 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 27 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 28 | `textfield_variable` | 66.7% | 54 | 81 | 27 |  |
| 29 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 30 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 31 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 32 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 33 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 34 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 35 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 36 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 37 | `with` | 61.2% | 30 | 49 | 19 |  |
| 38 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 39 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 40 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 41 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 42 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 43 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 44 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 45 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 46 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 47 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 48 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 49 | `remove_movie_clip` | 58.6% | 17 | 29 | 12 |  |
| 50 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 51 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 52 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 53 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 54 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 55 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 56 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 57 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 58 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 59 | `edittext_default_format_font_style` | 55.4% | 186 | 336 | 150 |  |
| 60 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 61 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 62 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 63 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 64 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 65 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 66 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 67 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 68 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 69 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 70 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 71 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 72 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 73 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 74 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 75 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 76 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 9.9s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.4s |  |
| 3 | `goto_methods` | 5.6s |  |
| 4 | `path_string` | 5.5s |  |
| 5 | `swf4_actions_coercion_order` | 5.3s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**3 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 14.1s |  |
| 2 | `timeout` | runtime timeout (>10s) | 13.4s |  |
| 3 | `try_catch_finally` | runtime timeout (>10s) | 13.4s |  |

## All Output Mismatches

**313 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `swf7_case_sensitive` | 90.9% | 40/44 | 44 | 44 |  |
| 2 | `object_prototypes` | 83.8% | 62/74 | 73 | 74 |  |
| 3 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 |  |
| 4 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 5 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 6 | `textfield_properties` | 79.5% | 35/44 | 44 | 44 |  |
| 7 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 8 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 9 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 10 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 11 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 12 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 13 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 14 | `globals_swf6` | 69.4% | 211/304 | 304 | 304 |  |
| 15 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 16 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 17 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 18 | `stage_object_properties` | 68.5% | 165/241 | 241 | 241 |  |
| 19 | `globals_swf7` | 68.4% | 208/304 | 304 | 304 |  |
| 20 | `stage_object_properties_swf6` | 68.4% | 158/231 | 231 | 231 |  |
| 21 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 22 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 23 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 24 | `globals_swf5` | 67.1% | 204/304 | 304 | 304 |  |
| 25 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 26 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 27 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 28 | `textfield_variable` | 66.7% | 54/81 | 81 | 81 |  |
| 29 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 30 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 31 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 32 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 33 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 34 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 35 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 36 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 37 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 38 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 39 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 40 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 41 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 42 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 43 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 44 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 45 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 46 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 47 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 48 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 49 | `remove_movie_clip` | 58.6% | 17/29 | 29 | 29 |  |
| 50 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 51 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 52 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 53 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 54 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 55 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 56 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 57 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 58 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 59 | `edittext_default_format_font_style` | 55.4% | 186/336 | 336 | 335 |  |
| 60 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 61 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 62 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 63 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 64 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 65 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 66 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 67 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 68 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 69 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 70 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 71 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 72 | `issue_3522` | 50.0% | 1/2 | 1 | 2 |  |
| 73 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 74 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 75 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 76 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 77 | `globals_swf8` | 49.0% | 149/304 | 304 | 304 |  |
| 78 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 79 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 80 | `frame_size_translated_negative` | 47.6% | 10/21 | 20 | 21 |  |
| 81 | `frame_size_translated_positive` | 47.6% | 10/21 | 20 | 21 |  |
| 82 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 83 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 84 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 85 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 86 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 87 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 88 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 89 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 90 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 91 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 92 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 93 | `as2_oop` | 38.5% | 5/13 | 10 | 13 |  |
| 94 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 95 | `edittext_html_swf6` | 37.5% | 2016/5377 | 5377 | 5377 |  |
| 96 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 97 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 98 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 99 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 100 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 101 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 102 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 103 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 104 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 105 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 106 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 107 | `edittext_html_condensewhite_swf7` | 30.2% | 94/311 | 311 | 311 |  |
| 108 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 109 | `edittext_html_condensewhite_swf8` | 29.3% | 91/311 | 311 | 311 |  |
| 110 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 111 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 112 | `edittext_html_swf7` | 25.7% | 1380/5377 | 5377 | 5377 |  |
| 113 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 114 | `edittext_html_swf8` | 25.4% | 1365/5377 | 5377 | 5377 |  |
| 115 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 116 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 117 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 118 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 119 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 120 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 121 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 122 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 123 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 124 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 125 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 126 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 127 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 128 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 129 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 130 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 131 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 132 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 133 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 134 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 135 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 136 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 137 | `edittext_tag_indent` | 16.1% | 5/31 | 31 | 31 |  |
| 138 | `watch` | 15.4% | 18/117 | 100 | 117 |  |
| 139 | `as2_super_via_manual_prototype` | 15.0% | 6/40 | 16 | 40 |  |
| 140 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 141 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 142 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 143 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 144 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 145 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 146 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 147 | `movieclip_hittest_shapeflag` | 14.2% | 48/338 | 338 | 338 |  |
| 148 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 149 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 150 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 |  |
| 151 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 152 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 153 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 154 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 155 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 156 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 157 | `extends_chain` | 11.2% | 15/134 | 114 | 134 |  |
| 158 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 159 | `swf5_no_closure` | 10.5% | 2/19 | 11 | 19 |  |
| 160 | `edittext_autosize_setter` | 10.0% | 2/20 | 20 | 20 |  |
| 161 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 162 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 163 | `unload` | 9.6% | 5/52 | 48 | 52 |  |
| 164 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 165 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 166 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 167 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 168 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 169 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 170 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 171 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 172 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 173 | `init_object_order` | 6.7% | 1/15 | 5 | 15 |  |
| 174 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 175 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 176 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 177 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 178 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 179 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 180 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 181 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 182 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 183 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 184 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 185 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 186 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 187 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 188 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 189 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 190 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 191 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 192 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 193 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 194 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 195 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 196 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 197 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 198 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 199 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 200 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 201 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 202 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 203 | `global_instance_decls` | 0.1% | 1/758 | 83 | 758 |  |
| 204 | `global_proto_decls` | 0.0% | 2/4497 | 60 | 4497 |  |
| 205 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 206 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 207 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 208 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 209 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 210 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 211 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 212 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 213 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 214 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 215 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 216 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 217 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 218 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 219 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 220 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 221 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 222 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 223 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 224 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 225 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 226 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 227 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 228 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 229 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 230 | `extends_native_type` | 0.0% | 0/11 | 4 | 11 |  |
| 231 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 232 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 233 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 234 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 235 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 236 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 237 | `global_proto_decls_delete` | 0.0% | 0/4158 | 18 | 4158 |  |
| 238 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 239 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 240 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 241 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 242 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 243 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 244 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 245 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 246 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 247 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 248 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 249 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 250 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 251 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 252 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 253 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 254 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 255 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 256 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 257 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 258 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 259 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 260 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 261 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 262 | `native_objects_swf6` | 0.0% | 0/183 | 183 | 84 |  |
| 263 | `native_objects_swf7` | 0.0% | 0/183 | 183 | 84 |  |
| 264 | `native_objects_swf8` | 0.0% | 0/183 | 183 | 84 |  |
| 265 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 266 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 267 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 268 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 269 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 270 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 271 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 272 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 273 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 274 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 275 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 276 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 277 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 278 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 279 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 280 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 281 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 282 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 283 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 284 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 285 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 286 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 287 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 288 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 289 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 290 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 291 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 292 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 293 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 294 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 295 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 296 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 297 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 298 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 299 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 300 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 301 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 302 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 303 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 304 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 305 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 306 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 307 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 308 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 309 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 310 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 311 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 312 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 313 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
