# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-13 22:58 UTC

**Git SHA**: `ab56d97948`

**Run Duration**: 33m 40s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **140** (22.6%) |
| Failing | 479 |
| Total expected lines | 91246 |
| Matching lines | 34034 (37.3%) |
| Mismatched lines | 57212 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 469 | 97.9% |
| Timeout | 4 | 0.8% |
| Runtime Segfault | 4 | 0.8% |
| Runtime Error | 2 | 0.4% |

## Passing Tests

**140 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 4.6s |  |
| 2 | `action_to_integer` | 28 | 2.7s |  |
| 3 | `add` | 28 | 2.7s |  |
| 4 | `add2` | 354 | 3.1s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.7s |  |
| 6 | `add_swf5` | 28 | 2.7s |  |
| 7 | `array_concat` | 98 | 2.9s |  |
| 8 | `array_constructor` | 30 | 2.8s |  |
| 9 | `array_length` | 42 | 2.8s |  |
| 10 | `array_properties` | 36 | 2.7s |  |
| 11 | `array_slice` | 34 | 2.8s |  |
| 12 | `array_splice` | 207 | 3.5s |  |
| 13 | `array_trivial` | 209 | 3.2s |  |
| 14 | `as1_constructor_v6` | 35 | 2.8s |  |
| 15 | `as1_constructor_v7` | 35 | 2.8s |  |
| 16 | `as_broadcaster_initialize` | 10 | 2.6s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 2.7s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 2.7s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 2.7s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 2.7s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 2.7s |  |
| 22 | `as_transformed_flag` | 20 | 2.7s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 2.6s |  |
| 24 | `bitand` | 1058 | 9.5s |  |
| 25 | `bitmap_data_colortransform` | 0 | 2.9s |  |
| 26 | `bitmap_data_fillrect` | 0 | 2.8s |  |
| 27 | `bitmap_data_perlinnoise` | 0 | 3.4s |  |
| 28 | `bitmap_data_pixeldissolve_image` | 0 | 3.2s |  |
| 29 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.7s |  |
| 30 | `bitor` | 1058 | 9.5s |  |
| 31 | `biturshift` | 14 | 2.9s |  |
| 32 | `biturshift_swf8` | 14 | 2.6s |  |
| 33 | `bitxor` | 1058 | 9.3s |  |
| 34 | `call_method_empty_name` | 1 | 2.6s |  |
| 35 | `catch_references_registers` | 2 | 2.6s |  |
| 36 | `define_function2` | 8 | 2.6s |  |
| 37 | `define_function2_preload` | 13 | 2.6s |  |
| 38 | `define_function2_preload_order` | 4 | 2.6s |  |
| 39 | `define_function_case_sensitive` | 2 | 2.6s |  |
| 40 | `delete` | 3 | 2.7s |  |
| 41 | `divide_swf4` | 107 | 2.8s |  |
| 42 | `do_init_action` | 3 | 2.6s |  |
| 43 | `equals` | 32 | 2.8s |  |
| 44 | `equals2_swf5` | 926 | 11.6s |  |
| 45 | `equals2_swf6` | 926 | 11.4s |  |
| 46 | `equals2_swf7` | 926 | 11.4s |  |
| 47 | `equals_swf4` | 665 | 6.7s |  |
| 48 | `equals_swf4_alt` | 32 | 2.9s |  |
| 49 | `equals_swf5` | 32 | 2.8s |  |
| 50 | `error` | 58 | 2.9s |  |
| 51 | `escape` | 14 | 2.7s |  |
| 52 | `execution_order3` | 4 | 2.7s |  |
| 53 | `focusrect_mouse_swf8` | 0 | 2.5s |  |
| 54 | `focusrect_mouse_swf9` | 0 | 2.5s |  |
| 55 | `focusrect_swf5` | 6 | 2.8s |  |
| 56 | `get_variable_in_scope` | 29 | 2.7s |  |
| 57 | `getproperty` | 28 | 2.6s |  |
| 58 | `getproperty_swf4` | 28 | 2.6s |  |
| 59 | `getproperty_swf5` | 28 | 2.6s |  |
| 60 | `global_array` | 3 | 2.6s |  |
| 61 | `global_is_bare` | 7 | 2.5s |  |
| 62 | `goto_advance2` | 2 | 2.6s |  |
| 63 | `goto_both_ways1` | 3 | 3.1s |  |
| 64 | `goto_both_ways2` | 3 | 2.8s |  |
| 65 | `goto_execution_order` | 2 | 2.7s |  |
| 66 | `goto_execution_order2` | 2 | 2.7s |  |
| 67 | `goto_frame_number` | 3 | 2.7s |  |
| 68 | `goto_rewind1` | 1 | 2.7s |  |
| 69 | `goto_rewind2` | 3 | 2.7s |  |
| 70 | `goto_rewind3` | 2 | 2.8s |  |
| 71 | `greater_swf6` | 1175 | 12.0s |  |
| 72 | `greater_swf7` | 1175 | 11.7s |  |
| 73 | `greaterthan_swf5` | 1 | 2.6s |  |
| 74 | `greaterthan_swf8` | 1 | 2.7s |  |
| 75 | `has_own_property` | 32 | 2.8s |  |
| 76 | `infinite_recursion_function` | 4 | 2.6s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 77 | `infinite_recursion_function_in_setter` | 131 | 2.7s |  |
| 78 | `infinite_recursion_virtual_property` | 67 | 2.7s |  |
| 79 | `init_array_invalid` | 4 | 2.6s |  |
| 80 | `init_object_invalid` | 4 | 2.6s |  |
| 81 | `issue_1086` | 1 | 2.7s |  |
| 82 | `issue_1671` | 0 | 2.6s |  |
| 83 | `issue_1906` | 4 | 2.8s |  |
| 84 | `issue_3446` | 1 | 2.7s |  |
| 85 | `issue_4377` | 2 | 2.7s |  |
| 86 | `issue_710` | 4 | 2.7s |  |
| 87 | `issue_768` | 3 | 2.7s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 88 | `lessthan` | 41 | 2.8s |  |
| 89 | `lessthan2_swf5` | 1226 | 12.5s |  |
| 90 | `lessthan2_swf6` | 1226 | 12.5s |  |
| 91 | `lessthan2_swf7` | 1226 | 12.3s |  |
| 92 | `lessthan_swf4` | 902 | 8.1s |  |
| 93 | `lessthan_swf4_alt` | 41 | 2.8s |  |
| 94 | `lessthan_swf5` | 41 | 2.8s |  |
| 95 | `logical_ops_swf4` | 90 | 2.8s |  |
| 96 | `logical_ops_swf8` | 108 | 2.8s |  |
| 97 | `looping` | 6 | 2.6s |  |
| 98 | `mask_reapply` | 0 | 2.6s |  |
| 99 | `mask_with_drawing` | 0 | 2.6s |  |
| 100 | `movieclip_begin_gradient_fill` | 0 | 3.3s |  |
| 101 | `movieclip_line_gradient_style` | 0 | 3.2s |  |
| 102 | `movieclip_name_from_timeline` | 13 | 2.6s |  |
| 103 | `movieclip_prototype_extension` | 5 | 2.6s |  |
| 104 | `nested_textfields_in_buttons` | 0 | 2.6s |  |
| 105 | `netstream_play_flv_screen` | 0 | 29.9s |  |
| 106 | `new_method_wrap` | 4 | 2.6s |  |
| 107 | `new_object_enumerate` | 7 | 2.6s |  |
| 108 | `new_object_wrap` | 4 | 2.6s |  |
| 109 | `o` | 3 | 2.6s |  |
| 110 | `object_constructor` | 33 | 2.7s |  |
| 111 | `object_function` | 32 | 2.7s |  |
| 112 | `object_string_coerce_swf5` | 62 | 2.8s |  |
| 113 | `primitive_instanceof` | 37 | 2.7s |  |
| 114 | `prototype_delete` | 12 | 2.7s |  |
| 115 | `recursive_prototypes` | 0 | 2.6s |  |
| 116 | `sandbox_type_local_network` | 1 | 2.6s |  |
| 117 | `set_variable_scope` | 58 | 2.8s |  |
| 118 | `single_frame` | 1 | 2.6s |  |
| 119 | `sound_start_load` | 0 | 2.7s |  |
| 120 | `stage_object_properties_get_var` | 5 | 2.6s |  |
| 121 | `strictequals_swf6` | 902 | 9.1s |  |
| 122 | `strictly_equals` | 7 | 2.7s |  |
| 123 | `string_coercion` | 117 | 3.3s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 124 | `string_paths_keyevents` | 0 | 2.6s |  |
| 125 | `string_paths_timer` | 0 | 2.6s |  |
| 126 | `swf4_actions_bool` | 96 | 2.8s |  |
| 127 | `swf4_bool` | 4 | 2.7s |  |
| 128 | `swf4_function_calls` | 7 | 2.8s |  |
| 129 | `swf5_encoding` | 3 | 2.6s |  |
| 130 | `swf7_case_sensitive` | 44 | 2.8s |  |
| 131 | `tab_ordering_properties_tab_index_edge_case` | 4 | 2.7s |  |
| 132 | `this_swf7` | 41 | 2.7s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 133 | `timeline_function_def` | 7 | 2.8s |  |
| 134 | `try_finally_simple` | 16 | 2.6s |  |
| 135 | `typeof_globals` | 7 | 2.6s |  |
| 136 | `undefined_to_string_swf6` | 4 | 2.6s |  |
| 137 | `unescape` | 43 | 2.7s |  |
| 138 | `waitforframe` | 7 | 2.6s |  |
| 139 | `waitforframe2` | 16 | 2.7s |  |
| 140 | `with_return` | 2 | 2.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**97 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `typeof` | 90.9% | 20 | 22 | 2 |  |
| 2 | `textfield_text` | 85.7% | 6 | 7 | 1 |  |
| 3 | `variable_args` | 83.3% | 5 | 6 | 1 |  |
| 4 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 5 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 6 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 7 | `conflicting_instance_names` | 78.3% | 18 | 23 | 5 |  |
| 8 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 9 | `bitmap_data_max_size_swf10` | 75.0% | 9 | 12 | 3 |  |
| 10 | `use_hand_cursor` | 75.0% | 6 | 8 | 2 |  |
| 11 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 12 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 13 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 14 | `textfield_background_color` | 72.7% | 8 | 11 | 3 |  |
| 15 | `textfield_border_color` | 72.7% | 8 | 11 | 3 |  |
| 16 | `textfield_properties` | 72.7% | 32 | 44 | 12 |  |
| 17 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 18 | `execution_order2` | 71.4% | 5 | 7 | 2 |  |
| 19 | `point` | 70.9% | 124 | 175 | 51 |  |
| 20 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 21 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 22 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 23 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 24 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 25 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 26 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 27 | `stage_object_properties` | 68.5% | 165 | 241 | 76 |  |
| 28 | `stage_object_properties_swf6` | 68.4% | 158 | 231 | 73 |  |
| 29 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 30 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 31 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 32 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 33 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 34 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 35 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 36 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 37 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 38 | `target_clip_removed` | 66.7% | 4 | 6 | 2 |  |
| 39 | `textfield_variable` | 66.7% | 54 | 81 | 27 |  |
| 40 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 41 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 42 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 43 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 44 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 45 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 46 | `slash_syntax` | 64.3% | 9 | 14 | 5 |  |
| 47 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 48 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 49 | `with` | 61.2% | 30 | 49 | 19 |  |
| 50 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 51 | `edittext_scroll` | 61.1% | 33 | 54 | 21 |  |
| 52 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 53 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 54 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 55 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 56 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 57 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 58 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 59 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 60 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 61 | `execution_order1` | 60.0% | 3 | 5 | 2 |  |
| 62 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 63 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 64 | `remove_movie_clip` | 58.6% | 17 | 29 | 12 |  |
| 65 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 66 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 67 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 68 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 69 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 70 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 71 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 72 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 73 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 74 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 75 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 76 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 77 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 78 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 79 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 80 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 81 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 82 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 83 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 84 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 85 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 86 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 87 | `display_object_properties` | 50.0% | 1 | 2 | 1 |  |
| 88 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 89 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 90 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 91 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 92 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 93 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 94 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 95 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 96 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 97 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 12.7s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.7s |  |
| 3 | `path_string` | 5.1s |  |
| 4 | `swf4_actions_coercion_order` | 4.9s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.6s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.6s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `goto_methods` | runtime timeout (>10s) | 13.1s |  |
| 2 | `parse_float` | runtime timeout (>10s) | 13.7s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.8s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 13.0s |  |

## All Output Mismatches

**469 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `typeof` | 90.9% | 20/22 | 22 | 22 |  |
| 2 | `textfield_text` | 85.7% | 6/7 | 7 | 7 |  |
| 3 | `variable_args` | 83.3% | 5/6 | 6 | 5 |  |
| 4 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 5 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 6 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 7 | `conflicting_instance_names` | 78.3% | 18/23 | 23 | 23 |  |
| 8 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 9 | `bitmap_data_max_size_swf10` | 75.0% | 9/12 | 12 | 12 |  |
| 10 | `use_hand_cursor` | 75.0% | 6/8 | 8 | 8 |  |
| 11 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 12 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 13 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 14 | `textfield_background_color` | 72.7% | 8/11 | 11 | 11 |  |
| 15 | `textfield_border_color` | 72.7% | 8/11 | 11 | 11 |  |
| 16 | `textfield_properties` | 72.7% | 32/44 | 44 | 44 |  |
| 17 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 18 | `execution_order2` | 71.4% | 5/7 | 7 | 7 |  |
| 19 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 20 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 21 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 22 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 23 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 24 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 25 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 26 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 27 | `stage_object_properties` | 68.5% | 165/241 | 241 | 241 |  |
| 28 | `stage_object_properties_swf6` | 68.4% | 158/231 | 231 | 231 |  |
| 29 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 30 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 31 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 32 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 33 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 34 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 35 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 36 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 37 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 38 | `target_clip_removed` | 66.7% | 4/6 | 6 | 5 |  |
| 39 | `textfield_variable` | 66.7% | 54/81 | 81 | 81 |  |
| 40 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 41 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 42 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 43 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 44 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 45 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 46 | `slash_syntax` | 64.3% | 9/14 | 14 | 14 |  |
| 47 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 48 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 49 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 50 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 51 | `edittext_scroll` | 61.1% | 33/54 | 54 | 54 |  |
| 52 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 53 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 54 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 55 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 56 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 57 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 58 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 59 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 60 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 61 | `execution_order1` | 60.0% | 3/5 | 3 | 5 |  |
| 62 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 63 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 64 | `remove_movie_clip` | 58.6% | 17/29 | 29 | 29 |  |
| 65 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 66 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 67 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 68 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 69 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 70 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 71 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 72 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 73 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 74 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 75 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 76 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 77 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 78 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 79 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 80 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 81 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 82 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 83 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 84 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 85 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 86 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 87 | `display_object_properties` | 50.0% | 1/2 | 2 | 2 |  |
| 88 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 89 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 90 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 91 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 92 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 93 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 94 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 95 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 96 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 97 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 98 | `edittext_newline_stripping` | 49.2% | 32/65 | 65 | 64 |  |
| 99 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 100 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 101 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 102 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 103 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 104 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 105 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 106 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 107 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 108 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 109 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 110 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 111 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 112 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 113 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 114 | `as2_oop` | 38.5% | 5/13 | 10 | 13 |  |
| 115 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 116 | `edittext_html_swf6` | 37.5% | 2014/5377 | 5377 | 5377 |  |
| 117 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 118 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 119 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 120 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 121 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 122 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 123 | `frame_size_translated_negative` | 33.3% | 7/21 | 20 | 21 |  |
| 124 | `init_object_order` | 33.3% | 5/15 | 5 | 15 |  |
| 125 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 126 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 127 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 128 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 129 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 130 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 131 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 132 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 133 | `edittext_html_condensewhite_swf7` | 29.9% | 93/311 | 311 | 311 |  |
| 134 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 135 | `edittext_html_condensewhite_swf8` | 28.9% | 90/311 | 311 | 311 |  |
| 136 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 137 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 138 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 139 | `edittext_html_swf7` | 25.6% | 1378/5377 | 5377 | 5377 |  |
| 140 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 141 | `edittext_html_swf8` | 25.3% | 1363/5377 | 5377 | 5377 |  |
| 142 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 143 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 144 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 145 | `goto_frame` | 25.0% | 3/12 | 3 | 12 |  |
| 146 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 147 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 148 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 149 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 150 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 151 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 152 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 153 | `textfield_props_swf5` | 21.1% | 37/175 | 139 | 175 |  |
| 154 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 155 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 156 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 157 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 158 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 159 | `default_names` | 19.2% | 10/52 | 34 | 52 |  |
| 160 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 161 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 162 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 163 | `textfield_props_swf6` | 17.6% | 37/210 | 140 | 210 |  |
| 164 | `textfield_props_swf7` | 17.1% | 36/210 | 140 | 210 |  |
| 165 | `textfield_props_swf8` | 17.1% | 36/210 | 140 | 210 |  |
| 166 | `focusrect_property_swf5` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 167 | `focusrect_property_swf6` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 168 | `focusrect_property_swf7` | 16.9% | 209/1237 | 1236 | 1237 |  |
| 169 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 170 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 171 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 172 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 173 | `edittext_tag_indent` | 16.1% | 5/31 | 31 | 31 |  |
| 174 | `watch` | 15.4% | 18/117 | 100 | 117 |  |
| 175 | `as2_super_via_manual_prototype` | 15.0% | 6/40 | 16 | 40 |  |
| 176 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 177 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 178 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 179 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 180 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 181 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 182 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 183 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 184 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 185 | `movieclip_hittest_shapeflag` | 14.2% | 48/338 | 338 | 338 |  |
| 186 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 187 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 188 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 189 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 190 | `register_and_init_order` | 12.6% | 29/231 | 99 | 231 |  |
| 191 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 192 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 193 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 194 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 195 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 196 | `goto_label` | 11.8% | 2/17 | 4 | 17 |  |
| 197 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 198 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 199 | `extends_chain` | 11.2% | 15/134 | 114 | 134 |  |
| 200 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 201 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 202 | `swf5_no_closure` | 10.5% | 2/19 | 11 | 19 |  |
| 203 | `edittext_autosize_setter` | 10.0% | 2/20 | 20 | 20 |  |
| 204 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 205 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 206 | `unload` | 9.6% | 5/52 | 48 | 52 |  |
| 207 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 208 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 209 | `goto_frame2` | 9.1% | 4/44 | 4 | 44 |  |
| 210 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 211 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 212 | `execution_order4` | 8.3% | 1/12 | 8 | 12 |  |
| 213 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 214 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 215 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 216 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 217 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 218 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 219 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 220 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 221 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 222 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 223 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 224 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 225 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 226 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 227 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 228 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 229 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 230 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 231 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 232 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 233 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 234 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 235 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 236 | `bitmap_data` | 4.1% | 46/1126 | 318 | 1126 |  |
| 237 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 238 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 239 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 240 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 241 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 242 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 243 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 244 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 245 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 246 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 247 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 248 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 249 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 250 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 251 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 252 | `tab_ordering_properties` | 1.7% | 5/293 | 180 | 293 |  |
| 253 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 254 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 255 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 256 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 257 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 258 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 259 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 260 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 261 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 262 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 263 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 264 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 265 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 266 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 267 | `global_proto_decls` | 0.0% | 1/4497 | 20 | 4497 |  |
| 268 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 269 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 270 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 271 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 272 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 273 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 274 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 275 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 276 | `bitmap_data_copypixels` | 0.0% | 0/17 | 0 | 17 |  |
| 277 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 0 | 1075 |  |
| 278 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 279 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 280 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 281 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 282 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 283 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 284 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 285 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 286 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 287 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 288 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 289 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 290 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 291 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 292 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 293 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 294 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 295 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 296 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 297 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 298 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 299 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 300 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 301 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 302 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 303 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 304 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 305 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 306 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 307 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 308 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 309 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 310 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 311 | `edittext_password` | 0.0% | 0/5 | 5 | 5 |  |
| 312 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 313 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 314 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 315 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 316 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 317 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 318 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 319 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 320 | `extends_native_type` | 0.0% | 0/11 | 4 | 11 |  |
| 321 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 322 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 323 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 324 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 325 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 326 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 327 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 328 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 329 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 330 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 331 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 332 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 333 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 334 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 335 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 336 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 337 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 338 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 339 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 340 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 341 | `global_proto_decls_delete` | 0.0% | 0/4158 | 14 | 4158 |  |
| 342 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 343 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 344 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 345 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 346 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 347 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 348 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 349 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 350 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 351 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 352 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 353 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 354 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 355 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 356 | `loadmovie_fail` | 0.0% | 0/2 | 0 | 2 |  |
| 357 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 358 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 359 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 0 | 9 |  |
| 360 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 361 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 362 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 363 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 364 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 365 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 366 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 367 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 368 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 369 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 370 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 371 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 372 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 373 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 374 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 375 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 376 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 377 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 378 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 379 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 380 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 381 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 382 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 383 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 384 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 385 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 386 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 387 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 388 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 389 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 390 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 391 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 392 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 393 | `native_objects_swf6` | 0.0% | 0/178 | 178 | 84 |  |
| 394 | `native_objects_swf7` | 0.0% | 0/178 | 178 | 84 |  |
| 395 | `native_objects_swf8` | 0.0% | 0/178 | 178 | 84 |  |
| 396 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 397 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 398 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 399 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 400 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 401 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 402 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 403 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 404 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 405 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 406 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 407 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 408 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 409 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 410 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 411 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 412 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 413 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 414 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 415 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 416 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 417 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 418 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 419 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 420 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 421 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 422 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 423 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 424 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 425 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 426 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 427 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 428 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 429 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 430 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 431 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 432 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 433 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 434 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 435 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 436 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 437 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 438 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 439 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 440 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 441 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 442 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 443 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 444 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 445 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 446 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 447 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 448 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 449 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 450 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 451 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 452 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 453 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 454 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 455 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 456 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 457 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 458 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 459 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 460 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 461 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 462 | `xml_socket` | 0.0% | 0/8 | 0 | 8 |  |
| 463 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 464 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 465 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
| 466 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 467 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 468 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 469 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
