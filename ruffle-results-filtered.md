# Ruffle Test Results (Filtered)

**Date**: 2026-02-13 22:58 UTC

**Git SHA**: `ab56d97948`

**Run Duration**: 33m 40s

**Filtered**: 125 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 494 |
| Passing | **133** (26.9%) |
| Failing | 361 |
| Total expected lines | 78497 |
| Matching lines | 33042 (42.1%) |
| Mismatched lines | 45455 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 351 | 97.2% |
| Segfault | 4 | 1.1% |
| Timeout | 4 | 1.1% |
| Runtime Error | 2 | 0.6% |

## Passing Tests

**133 tests passing**

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
| 53 | `get_variable_in_scope` | 29 | 2.7s |  |
| 54 | `getproperty` | 28 | 2.6s |  |
| 55 | `getproperty_swf4` | 28 | 2.6s |  |
| 56 | `getproperty_swf5` | 28 | 2.6s |  |
| 57 | `global_array` | 3 | 2.6s |  |
| 58 | `global_is_bare` | 7 | 2.5s |  |
| 59 | `goto_advance2` | 2 | 2.6s |  |
| 60 | `goto_both_ways1` | 3 | 3.1s |  |
| 61 | `goto_both_ways2` | 3 | 2.8s |  |
| 62 | `goto_execution_order` | 2 | 2.7s |  |
| 63 | `goto_execution_order2` | 2 | 2.7s |  |
| 64 | `goto_frame_number` | 3 | 2.7s |  |
| 65 | `goto_rewind1` | 1 | 2.7s |  |
| 66 | `goto_rewind2` | 3 | 2.7s |  |
| 67 | `goto_rewind3` | 2 | 2.8s |  |
| 68 | `greater_swf6` | 1175 | 12.0s |  |
| 69 | `greater_swf7` | 1175 | 11.7s |  |
| 70 | `greaterthan_swf5` | 1 | 2.6s |  |
| 71 | `greaterthan_swf8` | 1 | 2.7s |  |
| 72 | `has_own_property` | 32 | 2.8s |  |
| 73 | `infinite_recursion_function_in_setter` | 131 | 2.7s |  |
| 74 | `infinite_recursion_virtual_property` | 67 | 2.7s |  |
| 75 | `init_array_invalid` | 4 | 2.6s |  |
| 76 | `init_object_invalid` | 4 | 2.6s |  |
| 77 | `issue_1086` | 1 | 2.7s |  |
| 78 | `issue_1671` | 0 | 2.6s |  |
| 79 | `issue_1906` | 4 | 2.8s |  |
| 80 | `issue_3446` | 1 | 2.7s |  |
| 81 | `issue_4377` | 2 | 2.7s |  |
| 82 | `issue_710` | 4 | 2.7s |  |
| 83 | `issue_768` | 3 | 2.7s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 84 | `lessthan` | 41 | 2.8s |  |
| 85 | `lessthan2_swf5` | 1226 | 12.5s |  |
| 86 | `lessthan2_swf6` | 1226 | 12.5s |  |
| 87 | `lessthan2_swf7` | 1226 | 12.3s |  |
| 88 | `lessthan_swf4` | 902 | 8.1s |  |
| 89 | `lessthan_swf4_alt` | 41 | 2.8s |  |
| 90 | `lessthan_swf5` | 41 | 2.8s |  |
| 91 | `logical_ops_swf4` | 90 | 2.8s |  |
| 92 | `logical_ops_swf8` | 108 | 2.8s |  |
| 93 | `looping` | 6 | 2.6s |  |
| 94 | `mask_reapply` | 0 | 2.6s |  |
| 95 | `mask_with_drawing` | 0 | 2.6s |  |
| 96 | `movieclip_begin_gradient_fill` | 0 | 3.3s |  |
| 97 | `movieclip_line_gradient_style` | 0 | 3.2s |  |
| 98 | `movieclip_name_from_timeline` | 13 | 2.6s |  |
| 99 | `movieclip_prototype_extension` | 5 | 2.6s |  |
| 100 | `nested_textfields_in_buttons` | 0 | 2.6s |  |
| 101 | `new_method_wrap` | 4 | 2.6s |  |
| 102 | `new_object_enumerate` | 7 | 2.6s |  |
| 103 | `new_object_wrap` | 4 | 2.6s |  |
| 104 | `o` | 3 | 2.6s |  |
| 105 | `object_constructor` | 33 | 2.7s |  |
| 106 | `object_function` | 32 | 2.7s |  |
| 107 | `object_string_coerce_swf5` | 62 | 2.8s |  |
| 108 | `primitive_instanceof` | 37 | 2.7s |  |
| 109 | `prototype_delete` | 12 | 2.7s |  |
| 110 | `recursive_prototypes` | 0 | 2.6s |  |
| 111 | `sandbox_type_local_network` | 1 | 2.6s |  |
| 112 | `set_variable_scope` | 58 | 2.8s |  |
| 113 | `single_frame` | 1 | 2.6s |  |
| 114 | `stage_object_properties_get_var` | 5 | 2.6s |  |
| 115 | `strictequals_swf6` | 902 | 9.1s |  |
| 116 | `strictly_equals` | 7 | 2.7s |  |
| 117 | `string_coercion` | 117 | 3.3s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 118 | `string_paths_keyevents` | 0 | 2.6s |  |
| 119 | `string_paths_timer` | 0 | 2.6s |  |
| 120 | `swf4_actions_bool` | 96 | 2.8s |  |
| 121 | `swf4_bool` | 4 | 2.7s |  |
| 122 | `swf4_function_calls` | 7 | 2.8s |  |
| 123 | `swf5_encoding` | 3 | 2.6s |  |
| 124 | `swf7_case_sensitive` | 44 | 2.8s |  |
| 125 | `this_swf7` | 41 | 2.7s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 126 | `timeline_function_def` | 7 | 2.8s |  |
| 127 | `try_finally_simple` | 16 | 2.6s |  |
| 128 | `typeof_globals` | 7 | 2.6s |  |
| 129 | `undefined_to_string_swf6` | 4 | 2.6s |  |
| 130 | `unescape` | 43 | 2.7s |  |
| 131 | `waitforframe` | 7 | 2.6s |  |
| 132 | `waitforframe2` | 16 | 2.7s |  |
| 133 | `with_return` | 2 | 2.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**87 tests** within reach

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
| 9 | `use_hand_cursor` | 75.0% | 6 | 8 | 2 |  |
| 10 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 11 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 12 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 13 | `textfield_background_color` | 72.7% | 8 | 11 | 3 |  |
| 14 | `textfield_border_color` | 72.7% | 8 | 11 | 3 |  |
| 15 | `textfield_properties` | 72.7% | 32 | 44 | 12 |  |
| 16 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 17 | `execution_order2` | 71.4% | 5 | 7 | 2 |  |
| 18 | `point` | 70.9% | 124 | 175 | 51 |  |
| 19 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 20 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 21 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 22 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 23 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 24 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 25 | `stage_object_properties` | 68.5% | 165 | 241 | 76 |  |
| 26 | `stage_object_properties_swf6` | 68.4% | 158 | 231 | 73 |  |
| 27 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 28 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 29 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 30 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 31 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 32 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 33 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 34 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 35 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 36 | `target_clip_removed` | 66.7% | 4 | 6 | 2 |  |
| 37 | `textfield_variable` | 66.7% | 54 | 81 | 27 |  |
| 38 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 39 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 40 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 41 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 42 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 43 | `slash_syntax` | 64.3% | 9 | 14 | 5 |  |
| 44 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 45 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 46 | `with` | 61.2% | 30 | 49 | 19 |  |
| 47 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 48 | `edittext_scroll` | 61.1% | 33 | 54 | 21 |  |
| 49 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 50 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 51 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 52 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 53 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 54 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 55 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 56 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 57 | `execution_order1` | 60.0% | 3 | 5 | 2 |  |
| 58 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 59 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 60 | `remove_movie_clip` | 58.6% | 17 | 29 | 12 |  |
| 61 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 62 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 63 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 64 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 65 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 66 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 67 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 68 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 69 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 70 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 71 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 72 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 73 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 74 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 75 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 76 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 77 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 78 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 79 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 80 | `display_object_properties` | 50.0% | 1 | 2 | 1 |  |
| 81 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 82 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 83 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 84 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 85 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 86 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 87 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

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

**351 tests** with output mismatch, sorted by match rate (best first)

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
| 9 | `use_hand_cursor` | 75.0% | 6/8 | 8 | 8 |  |
| 10 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 11 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 12 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 13 | `textfield_background_color` | 72.7% | 8/11 | 11 | 11 |  |
| 14 | `textfield_border_color` | 72.7% | 8/11 | 11 | 11 |  |
| 15 | `textfield_properties` | 72.7% | 32/44 | 44 | 44 |  |
| 16 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 17 | `execution_order2` | 71.4% | 5/7 | 7 | 7 |  |
| 18 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 19 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 20 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 21 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 22 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 23 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 24 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 25 | `stage_object_properties` | 68.5% | 165/241 | 241 | 241 |  |
| 26 | `stage_object_properties_swf6` | 68.4% | 158/231 | 231 | 231 |  |
| 27 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 28 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 29 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 30 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 31 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 32 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 33 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 34 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 35 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 36 | `target_clip_removed` | 66.7% | 4/6 | 6 | 5 |  |
| 37 | `textfield_variable` | 66.7% | 54/81 | 81 | 81 |  |
| 38 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 39 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 40 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 41 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 42 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 43 | `slash_syntax` | 64.3% | 9/14 | 14 | 14 |  |
| 44 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 45 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 46 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 47 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 48 | `edittext_scroll` | 61.1% | 33/54 | 54 | 54 |  |
| 49 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 50 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 51 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 52 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 53 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 54 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 55 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 56 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 57 | `execution_order1` | 60.0% | 3/5 | 3 | 5 |  |
| 58 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 59 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 60 | `remove_movie_clip` | 58.6% | 17/29 | 29 | 29 |  |
| 61 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 62 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 63 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 64 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 65 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 66 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 67 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 68 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 69 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 70 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 71 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 72 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 73 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 74 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 75 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 76 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 77 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 78 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 79 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 80 | `display_object_properties` | 50.0% | 1/2 | 2 | 2 |  |
| 81 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 82 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 83 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 84 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 85 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 86 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 87 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 88 | `edittext_newline_stripping` | 49.2% | 32/65 | 65 | 64 |  |
| 89 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 90 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 91 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 92 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 93 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 94 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 95 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 96 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 97 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 98 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 99 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 100 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 101 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 102 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 103 | `as2_oop` | 38.5% | 5/13 | 10 | 13 |  |
| 104 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 105 | `edittext_html_swf6` | 37.5% | 2014/5377 | 5377 | 5377 |  |
| 106 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 107 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 108 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 109 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 110 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 111 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 112 | `frame_size_translated_negative` | 33.3% | 7/21 | 20 | 21 |  |
| 113 | `init_object_order` | 33.3% | 5/15 | 5 | 15 |  |
| 114 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 115 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 116 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 117 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 118 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 119 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 120 | `edittext_html_condensewhite_swf7` | 29.9% | 93/311 | 311 | 311 |  |
| 121 | `edittext_html_condensewhite_swf8` | 28.9% | 90/311 | 311 | 311 |  |
| 122 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 123 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 124 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 125 | `edittext_html_swf7` | 25.6% | 1378/5377 | 5377 | 5377 |  |
| 126 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 127 | `edittext_html_swf8` | 25.3% | 1363/5377 | 5377 | 5377 |  |
| 128 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 129 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 130 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 131 | `goto_frame` | 25.0% | 3/12 | 3 | 12 |  |
| 132 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 133 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 134 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 135 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 136 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 137 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 138 | `textfield_props_swf5` | 21.1% | 37/175 | 139 | 175 |  |
| 139 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 140 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 141 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 142 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 143 | `default_names` | 19.2% | 10/52 | 34 | 52 |  |
| 144 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 145 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 146 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 147 | `textfield_props_swf6` | 17.6% | 37/210 | 140 | 210 |  |
| 148 | `textfield_props_swf7` | 17.1% | 36/210 | 140 | 210 |  |
| 149 | `textfield_props_swf8` | 17.1% | 36/210 | 140 | 210 |  |
| 150 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 151 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 152 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 153 | `edittext_tag_indent` | 16.1% | 5/31 | 31 | 31 |  |
| 154 | `watch` | 15.4% | 18/117 | 100 | 117 |  |
| 155 | `as2_super_via_manual_prototype` | 15.0% | 6/40 | 16 | 40 |  |
| 156 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 157 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 158 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 159 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 160 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 161 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 162 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 163 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 164 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 165 | `movieclip_hittest_shapeflag` | 14.2% | 48/338 | 338 | 338 |  |
| 166 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 167 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 168 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 169 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 170 | `register_and_init_order` | 12.6% | 29/231 | 99 | 231 |  |
| 171 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 172 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 173 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 174 | `goto_label` | 11.8% | 2/17 | 4 | 17 |  |
| 175 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 176 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 177 | `extends_chain` | 11.2% | 15/134 | 114 | 134 |  |
| 178 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 179 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 180 | `swf5_no_closure` | 10.5% | 2/19 | 11 | 19 |  |
| 181 | `edittext_autosize_setter` | 10.0% | 2/20 | 20 | 20 |  |
| 182 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 183 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 184 | `unload` | 9.6% | 5/52 | 48 | 52 |  |
| 185 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 186 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 187 | `goto_frame2` | 9.1% | 4/44 | 4 | 44 |  |
| 188 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 189 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 190 | `execution_order4` | 8.3% | 1/12 | 8 | 12 |  |
| 191 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 192 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 193 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 194 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 195 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 196 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 197 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 198 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 199 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 200 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 201 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 202 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 203 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 204 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 205 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 206 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 207 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 208 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 209 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 210 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 211 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 212 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 213 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 214 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 215 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 216 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 217 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 218 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 219 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 220 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 221 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 222 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 223 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 224 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 225 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 226 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 227 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 228 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 229 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 230 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 231 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 232 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 233 | `global_proto_decls` | 0.0% | 1/4497 | 20 | 4497 |  |
| 234 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 235 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 236 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 237 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 238 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 239 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 240 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 241 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 242 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 243 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 244 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 245 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 246 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 247 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 248 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 249 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 250 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 251 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 252 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 253 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 254 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 255 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 256 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 257 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 258 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 259 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 260 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 261 | `extends_native_type` | 0.0% | 0/11 | 4 | 11 |  |
| 262 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 263 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 264 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 265 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 266 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 267 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 268 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 269 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 270 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 271 | `global_proto_decls_delete` | 0.0% | 0/4158 | 14 | 4158 |  |
| 272 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 273 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 274 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 275 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 276 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 277 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 278 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 279 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 280 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 281 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 282 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 283 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 284 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 285 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 286 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 287 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 288 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 289 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 290 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 291 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 292 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 293 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 294 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 295 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 296 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 297 | `native_objects_swf6` | 0.0% | 0/178 | 178 | 84 |  |
| 298 | `native_objects_swf7` | 0.0% | 0/178 | 178 | 84 |  |
| 299 | `native_objects_swf8` | 0.0% | 0/178 | 178 | 84 |  |
| 300 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 301 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 302 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 303 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 304 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 305 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 306 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 307 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 308 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 309 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 310 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 311 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 312 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 313 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 314 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 315 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 316 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 317 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 318 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 319 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 320 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 321 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 322 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 323 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 324 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 325 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 326 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 327 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 328 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 329 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 330 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 331 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 332 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 333 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 334 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 335 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 336 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 337 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 338 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 339 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 340 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 341 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 342 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 343 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 344 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 345 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 346 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 347 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 348 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 349 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 350 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 351 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
