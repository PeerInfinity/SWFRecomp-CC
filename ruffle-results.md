# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-14 02:38 UTC

**Git SHA**: `60874323d2`

**Run Duration**: 35m 29s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **154** (24.9%) |
| Failing | 465 |
| Total expected lines | 91286 |
| Matching lines | 34531 (37.8%) |
| Mismatched lines | 56755 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 457 | 98.3% |
| Runtime Segfault | 5 | 1.1% |
| Timeout | 3 | 0.6% |

## Passing Tests

**154 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 7.3s |  |
| 2 | `action_to_integer` | 28 | 2.9s |  |
| 3 | `add` | 28 | 2.9s |  |
| 4 | `add2` | 354 | 3.3s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 3.0s |  |
| 6 | `add_swf5` | 28 | 2.9s |  |
| 7 | `array_concat` | 98 | 3.2s |  |
| 8 | `array_constructor` | 30 | 3.1s |  |
| 9 | `array_length` | 42 | 3.1s |  |
| 10 | `array_properties` | 36 | 3.0s |  |
| 11 | `array_slice` | 34 | 3.1s |  |
| 12 | `array_splice` | 207 | 3.8s |  |
| 13 | `array_trivial` | 209 | 3.6s |  |
| 14 | `as1_constructor_v6` | 35 | 3.0s |  |
| 15 | `as1_constructor_v7` | 35 | 3.1s |  |
| 16 | `as_broadcaster_initialize` | 10 | 3.0s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 3.0s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 2.9s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 2.9s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 2.9s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 2.9s |  |
| 22 | `as_transformed_flag` | 20 | 3.0s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 2.9s |  |
| 24 | `bitand` | 1058 | 10.2s |  |
| 25 | `bitmap_data_colortransform` | 0 | 3.2s |  |
| 26 | `bitmap_data_fillrect` | 0 | 3.0s |  |
| 27 | `bitmap_data_max_size_swf10` | 12 | 2.9s |  |
| 28 | `bitmap_data_max_size_swf9` | 10 | 2.8s |  |
| 29 | `bitmap_data_perlinnoise` | 0 | 3.6s |  |
| 30 | `bitmap_data_pixeldissolve_image` | 0 | 3.4s |  |
| 31 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.9s |  |
| 32 | `bitor` | 1058 | 9.8s |  |
| 33 | `biturshift` | 14 | 4.9s |  |
| 34 | `biturshift_swf8` | 14 | 2.8s |  |
| 35 | `bitxor` | 1058 | 9.9s |  |
| 36 | `call_method_empty_name` | 1 | 2.7s |  |
| 37 | `capabilities_resolution` | 8 | 2.8s |  |
| 38 | `catch_references_registers` | 2 | 2.8s |  |
| 39 | `conflicting_instance_names` | 23 | 2.9s |  |
| 40 | `define_function2` | 8 | 2.8s |  |
| 41 | `define_function2_preload` | 13 | 2.8s |  |
| 42 | `define_function2_preload_order` | 4 | 2.8s |  |
| 43 | `define_function_case_sensitive` | 2 | 2.8s |  |
| 44 | `delete` | 3 | 2.9s |  |
| 45 | `display_object_properties` | 2 | 2.7s |  |
| 46 | `divide_swf4` | 107 | 2.9s |  |
| 47 | `do_init_action` | 3 | 2.8s |  |
| 48 | `equals` | 32 | 2.9s |  |
| 49 | `equals2_swf5` | 926 | 11.1s |  |
| 50 | `equals2_swf6` | 926 | 10.8s |  |
| 51 | `equals2_swf7` | 926 | 11.0s |  |
| 52 | `equals_swf4` | 665 | 6.4s |  |
| 53 | `equals_swf4_alt` | 32 | 2.9s |  |
| 54 | `equals_swf5` | 32 | 2.8s |  |
| 55 | `error` | 58 | 3.0s |  |
| 56 | `escape` | 14 | 2.8s |  |
| 57 | `execution_order1` | 5 | 2.9s |  |
| 58 | `execution_order2` | 7 | 2.9s |  |
| 59 | `execution_order3` | 4 | 2.9s |  |
| 60 | `focusrect_mouse_swf8` | 0 | 2.7s |  |
| 61 | `focusrect_mouse_swf9` | 0 | 2.7s |  |
| 62 | `focusrect_swf5` | 6 | 3.0s |  |
| 63 | `get_variable_in_scope` | 29 | 2.9s |  |
| 64 | `getproperty` | 28 | 2.8s |  |
| 65 | `getproperty_swf4` | 28 | 2.8s |  |
| 66 | `getproperty_swf5` | 28 | 2.8s |  |
| 67 | `global_array` | 3 | 2.7s |  |
| 68 | `global_is_bare` | 7 | 2.7s |  |
| 69 | `goto_advance1` | 6 | 2.8s |  |
| 70 | `goto_advance2` | 2 | 2.8s |  |
| 71 | `goto_both_ways1` | 3 | 3.2s |  |
| 72 | `goto_both_ways2` | 3 | 3.0s |  |
| 73 | `goto_execution_order` | 2 | 2.9s |  |
| 74 | `goto_execution_order2` | 2 | 2.9s |  |
| 75 | `goto_frame_number` | 3 | 2.9s |  |
| 76 | `goto_rewind1` | 1 | 3.0s |  |
| 77 | `goto_rewind2` | 3 | 3.1s |  |
| 78 | `goto_rewind3` | 2 | 2.9s |  |
| 79 | `greater_swf6` | 1175 | 12.7s |  |
| 80 | `greater_swf7` | 1175 | 12.8s |  |
| 81 | `greaterthan_swf5` | 1 | 2.9s |  |
| 82 | `greaterthan_swf8` | 1 | 2.9s |  |
| 83 | `has_own_property` | 32 | 3.0s |  |
| 84 | `infinite_recursion_function` | 4 | 2.9s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 85 | `infinite_recursion_function_in_setter` | 131 | 2.9s |  |
| 86 | `infinite_recursion_virtual_property` | 67 | 2.9s |  |
| 87 | `init_array_invalid` | 4 | 2.9s |  |
| 88 | `init_object_invalid` | 4 | 2.8s |  |
| 89 | `issue_1086` | 1 | 2.9s |  |
| 90 | `issue_1671` | 0 | 2.9s |  |
| 91 | `issue_3446` | 1 | 2.9s |  |
| 92 | `issue_4377` | 2 | 2.9s |  |
| 93 | `issue_710` | 4 | 2.9s |  |
| 94 | `issue_768` | 3 | 2.9s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 95 | `lessthan` | 41 | 3.0s |  |
| 96 | `lessthan2_swf5` | 1226 | 13.4s |  |
| 97 | `lessthan2_swf6` | 1226 | 13.5s |  |
| 98 | `lessthan2_swf7` | 1226 | 13.4s |  |
| 99 | `lessthan_swf4` | 902 | 9.0s |  |
| 100 | `lessthan_swf4_alt` | 41 | 3.0s |  |
| 101 | `lessthan_swf5` | 41 | 3.0s |  |
| 102 | `logical_ops_swf4` | 90 | 2.9s |  |
| 103 | `logical_ops_swf8` | 108 | 2.9s |  |
| 104 | `looping` | 6 | 2.8s |  |
| 105 | `mask_reapply` | 0 | 2.8s |  |
| 106 | `mask_with_drawing` | 0 | 2.8s |  |
| 107 | `movieclip_begin_gradient_fill` | 0 | 3.4s |  |
| 108 | `movieclip_line_gradient_style` | 0 | 3.4s |  |
| 109 | `movieclip_name_from_timeline` | 13 | 2.8s |  |
| 110 | `movieclip_prototype_extension` | 5 | 2.8s |  |
| 111 | `nested_textfields_in_buttons` | 0 | 2.8s |  |
| 112 | `netstream_play_flv_screen` | 0 | 30.6s |  |
| 113 | `new_method_wrap` | 4 | 2.8s |  |
| 114 | `new_object_wrap` | 4 | 2.8s |  |
| 115 | `o` | 3 | 2.8s |  |
| 116 | `object_constructor` | 33 | 2.9s |  |
| 117 | `object_function` | 32 | 2.9s |  |
| 118 | `object_string_coerce_swf5` | 62 | 3.0s |  |
| 119 | `primitive_instanceof` | 37 | 2.9s |  |
| 120 | `prototype_delete` | 12 | 2.9s |  |
| 121 | `recursive_prototypes` | 0 | 2.8s |  |
| 122 | `sandbox_type_local_file` | 1 | 2.6s |  |
| 123 | `set_variable_scope` | 58 | 2.8s |  |
| 124 | `single_frame` | 1 | 2.7s |  |
| 125 | `sound_start_load` | 0 | 2.7s |  |
| 126 | `stage_object_properties_get_var` | 5 | 2.6s |  |
| 127 | `strictequals_swf6` | 902 | 8.6s |  |
| 128 | `strictly_equals` | 7 | 2.8s |  |
| 129 | `string_coercion` | 117 | 3.3s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 130 | `string_paths_keyevents` | 0 | 2.7s |  |
| 131 | `string_paths_timer` | 0 | 2.7s |  |
| 132 | `swf4_actions_bool` | 96 | 2.9s |  |
| 133 | `swf4_bool` | 4 | 2.7s |  |
| 134 | `swf4_function_calls` | 7 | 3.0s |  |
| 135 | `swf5_encoding` | 3 | 2.8s |  |
| 136 | `tab_ordering_properties_tab_index_edge_case` | 4 | 2.8s |  |
| 137 | `target_path` | 14 | 2.8s |  |
| 138 | `textfield_background_color` | 11 | 2.8s |  |
| 139 | `textfield_border_color` | 11 | 2.8s |  |
| 140 | `textfield_text` | 7 | 2.8s |  |
| 141 | `this_swf7` | 41 | 2.8s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 142 | `timeline_function_def` | 7 | 2.9s |  |
| 143 | `try_finally_simple` | 16 | 2.9s |  |
| 144 | `typeof` | 22 | 2.9s |  |
| 145 | `typeof_globals` | 7 | 2.8s |  |
| 146 | `uncaught_exception` | 1 | 2.8s |  |
| 147 | `uncaught_exception_bubbled` | 1 | 2.9s |  |
| 148 | `undefined_to_string_swf6` | 4 | 2.9s |  |
| 149 | `unescape` | 43 | 3.0s |  |
| 150 | `use_hand_cursor` | 8 | 2.9s |  |
| 151 | `variable_args` | 5 | 3.0s |  |
| 152 | `waitforframe` | 7 | 2.8s |  |
| 153 | `waitforframe2` | 16 | 2.9s |  |
| 154 | `with_return` | 2 | 2.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**85 tests** within reach

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
| 14 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 15 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 16 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 17 | `stage_object_properties` | 68.5% | 165 | 241 | 76 |  |
| 18 | `stage_object_properties_swf6` | 68.4% | 158 | 231 | 73 |  |
| 19 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 20 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 21 | `globals_swf6` | 67.4% | 205 | 304 | 99 |  |
| 22 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 23 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 24 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 25 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 26 | `globals_swf7` | 66.4% | 202 | 304 | 102 |  |
| 27 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 28 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 29 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 30 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 31 | `globals_swf5` | 65.8% | 200 | 304 | 104 |  |
| 32 | `textfield_variable` | 65.4% | 53 | 81 | 28 |  |
| 33 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 34 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 35 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 36 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 37 | `with` | 61.2% | 30 | 49 | 19 |  |
| 38 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 39 | `edittext_scroll` | 61.1% | 33 | 54 | 21 |  |
| 40 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 41 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 42 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 43 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 44 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 45 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 46 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 47 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 48 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 49 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 50 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 51 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 52 | `remove_movie_clip` | 58.6% | 17 | 29 | 12 |  |
| 53 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 54 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 55 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 56 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 57 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 58 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 59 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 60 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 61 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 62 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 63 | `edittext_default_format_font_style` | 55.4% | 186 | 336 | 150 |  |
| 64 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 65 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 66 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 67 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 68 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 69 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 70 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 71 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 72 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 73 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 74 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 75 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 76 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 77 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 78 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 79 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 80 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 81 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 82 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 83 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 84 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 85 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 12.8s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.9s |  |
| 3 | `goto_methods` | 5.5s |  |
| 4 | `path_string` | 5.3s |  |
| 5 | `swf4_actions_coercion_order` | 4.3s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**3 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.9s |  |
| 2 | `timeout` | runtime timeout (>10s) | 15.0s |  |
| 3 | `try_catch_finally` | runtime timeout (>10s) | 13.3s |  |

## All Output Mismatches

**457 tests** with output mismatch, sorted by match rate (best first)

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
| 14 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 15 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 16 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 17 | `stage_object_properties` | 68.5% | 165/241 | 241 | 241 |  |
| 18 | `stage_object_properties_swf6` | 68.4% | 158/231 | 231 | 231 |  |
| 19 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 20 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 21 | `globals_swf6` | 67.4% | 205/304 | 304 | 304 |  |
| 22 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 23 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 24 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 25 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 26 | `globals_swf7` | 66.4% | 202/304 | 304 | 304 |  |
| 27 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 28 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 29 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 30 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 31 | `globals_swf5` | 65.8% | 200/304 | 304 | 304 |  |
| 32 | `textfield_variable` | 65.4% | 53/81 | 81 | 81 |  |
| 33 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 34 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 35 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 36 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 37 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 38 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 39 | `edittext_scroll` | 61.1% | 33/54 | 54 | 54 |  |
| 40 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 41 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 42 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 43 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 44 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 45 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 46 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 47 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 48 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 49 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 50 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 51 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 52 | `remove_movie_clip` | 58.6% | 17/29 | 29 | 29 |  |
| 53 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 54 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 55 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 56 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 57 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 58 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 59 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 60 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 61 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 62 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 63 | `edittext_default_format_font_style` | 55.4% | 186/336 | 336 | 335 |  |
| 64 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 65 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 66 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 67 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 68 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 69 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 70 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 71 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 72 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 73 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 74 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 75 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 76 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 77 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 78 | `issue_3522` | 50.0% | 1/2 | 1 | 2 |  |
| 79 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 80 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 81 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 82 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 83 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 84 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 85 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 86 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 87 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 88 | `frame_size_translated_negative` | 47.6% | 10/21 | 20 | 21 |  |
| 89 | `frame_size_translated_positive` | 47.6% | 10/21 | 20 | 21 |  |
| 90 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 91 | `globals_swf8` | 47.0% | 143/304 | 304 | 304 |  |
| 92 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 93 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 94 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 95 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 96 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 97 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 98 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 99 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 100 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 101 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 102 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 103 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 104 | `as2_oop` | 38.5% | 5/13 | 10 | 13 |  |
| 105 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 106 | `edittext_html_swf6` | 37.4% | 2013/5377 | 5377 | 5377 |  |
| 107 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 108 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 109 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 110 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 111 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 112 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 113 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 114 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 115 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 116 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 117 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 118 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 119 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 120 | `edittext_html_condensewhite_swf7` | 30.2% | 94/311 | 311 | 311 |  |
| 121 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 122 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 123 | `edittext_html_condensewhite_swf8` | 29.3% | 91/311 | 311 | 311 |  |
| 124 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 125 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 126 | `edittext_html_swf7` | 25.6% | 1377/5377 | 5377 | 5377 |  |
| 127 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 128 | `edittext_html_swf8` | 25.3% | 1362/5377 | 5377 | 5377 |  |
| 129 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 130 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 131 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 132 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 133 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 134 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 135 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 136 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 137 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 138 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 139 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 140 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 141 | `textfield_props_swf5` | 21.1% | 37/175 | 139 | 175 |  |
| 142 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 143 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 144 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 145 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 146 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 147 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 148 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 149 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 150 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 151 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 152 | `textfield_props_swf6` | 17.6% | 37/210 | 140 | 210 |  |
| 153 | `textfield_props_swf7` | 17.1% | 36/210 | 140 | 210 |  |
| 154 | `textfield_props_swf8` | 17.1% | 36/210 | 140 | 210 |  |
| 155 | `focusrect_property_swf5` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 156 | `focusrect_property_swf6` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 157 | `focusrect_property_swf7` | 16.9% | 209/1237 | 1236 | 1237 |  |
| 158 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 159 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 160 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 161 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 162 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 163 | `edittext_tag_indent` | 16.1% | 5/31 | 31 | 31 |  |
| 164 | `watch` | 15.4% | 18/117 | 100 | 117 |  |
| 165 | `as2_super_via_manual_prototype` | 15.0% | 6/40 | 16 | 40 |  |
| 166 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 167 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 168 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 169 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 170 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 171 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 172 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 173 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 174 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 175 | `movieclip_hittest_shapeflag` | 14.2% | 48/338 | 338 | 338 |  |
| 176 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 177 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 178 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 179 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 180 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 |  |
| 181 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 182 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 183 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 184 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 185 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 186 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 187 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 188 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 189 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 190 | `extends_chain` | 11.2% | 15/134 | 114 | 134 |  |
| 191 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 192 | `swf5_no_closure` | 10.5% | 2/19 | 11 | 19 |  |
| 193 | `edittext_autosize_setter` | 10.0% | 2/20 | 20 | 20 |  |
| 194 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 195 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 196 | `unload` | 9.6% | 5/52 | 48 | 52 |  |
| 197 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 198 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 199 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 200 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 201 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 202 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 203 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 204 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 205 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 206 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 207 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 208 | `init_object_order` | 6.7% | 1/15 | 5 | 15 |  |
| 209 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 210 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 211 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 212 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 213 | `bitmap_data` | 5.8% | 68/1174 | 1174 | 1126 |  |
| 214 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 215 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 216 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 217 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 218 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 219 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 220 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 221 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 222 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 223 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 224 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 225 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 226 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 227 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 228 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 229 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 230 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 231 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 232 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 233 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 234 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 235 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 236 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 237 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 238 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 239 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 240 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 241 | `tab_ordering_properties` | 1.7% | 5/293 | 180 | 293 |  |
| 242 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 243 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 244 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 245 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 246 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 247 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 248 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 249 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 250 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 251 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 252 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 253 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 254 | `global_instance_decls` | 0.1% | 1/758 | 83 | 758 |  |
| 255 | `global_proto_decls` | 0.0% | 2/4497 | 20 | 4497 |  |
| 256 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 257 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 258 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 259 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 260 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 261 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 262 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 263 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 264 | `bitmap_data_copypixels` | 0.0% | 0/17 | 0 | 17 |  |
| 265 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 0 | 1075 |  |
| 266 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 267 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 268 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 269 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 270 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 271 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 272 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 273 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 274 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 275 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 276 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 277 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 278 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 279 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 280 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 281 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 282 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 283 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 284 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 285 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 286 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 287 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 288 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 289 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 290 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 291 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 292 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 293 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 294 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 295 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 296 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 297 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 298 | `edittext_password` | 0.0% | 0/5 | 5 | 5 |  |
| 299 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 300 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 301 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 302 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 303 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 304 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 305 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 306 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 307 | `extends_native_type` | 0.0% | 0/11 | 4 | 11 |  |
| 308 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 309 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 310 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 311 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 312 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 313 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 314 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 315 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 316 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 317 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 318 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 319 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 320 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 321 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 322 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 323 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 324 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 325 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 326 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 327 | `global_proto_decls_delete` | 0.0% | 0/4158 | 14 | 4158 |  |
| 328 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 329 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 330 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 331 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 332 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 333 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 334 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 335 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 336 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 337 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 338 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 339 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 340 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 341 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 342 | `loadmovie_fail` | 0.0% | 0/2 | 0 | 2 |  |
| 343 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 344 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 345 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 0 | 9 |  |
| 346 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 347 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 348 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 349 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 350 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 351 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 352 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 353 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 354 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 355 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 356 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 357 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 358 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 359 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 360 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 361 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 362 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 363 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 364 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 365 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 366 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 367 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 368 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 369 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 370 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 371 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 372 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 373 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 374 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 375 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 376 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 377 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 378 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 379 | `native_objects_swf6` | 0.0% | 0/183 | 183 | 84 |  |
| 380 | `native_objects_swf7` | 0.0% | 0/183 | 183 | 84 |  |
| 381 | `native_objects_swf8` | 0.0% | 0/183 | 183 | 84 |  |
| 382 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 383 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 384 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 385 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 386 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 387 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 388 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 389 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 390 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 391 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 392 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 393 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 394 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 395 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 396 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 397 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 398 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 399 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 400 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 401 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 402 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 403 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 404 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 405 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 406 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 407 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 408 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 409 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 410 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 411 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 412 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 413 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 414 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 415 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 416 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 417 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 418 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 419 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 420 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 421 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 422 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 423 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 424 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 425 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 426 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 427 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 428 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 429 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 430 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 431 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 432 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 433 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 434 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 435 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 436 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 437 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 438 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 439 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 440 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 441 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 442 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 443 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 444 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 445 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 446 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 447 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 448 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 449 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 450 | `xml_socket` | 0.0% | 0/8 | 0 | 8 |  |
| 451 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 452 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 453 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
| 454 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 455 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 456 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 457 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
