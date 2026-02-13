# Ruffle Test Results (Filtered)

**Date**: 2026-02-13 21:49 UTC

**Git SHA**: `e1ce7372f9`

**Run Duration**: 33m 50s

**Filtered**: 125 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 494 |
| Passing | **128** (25.9%) |
| Failing | 366 |
| Total expected lines | 78537 |
| Matching lines | 32996 (42.0%) |
| Mismatched lines | 45541 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 357 | 97.5% |
| Segfault | 4 | 1.1% |
| Timeout | 3 | 0.8% |
| Runtime Error | 2 | 0.5% |

## Passing Tests

**128 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 4.1s |  |
| 2 | `action_to_integer` | 28 | 2.7s |  |
| 3 | `add` | 28 | 2.8s |  |
| 4 | `add2` | 354 | 3.2s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.8s |  |
| 6 | `add_swf5` | 28 | 2.8s |  |
| 7 | `array_concat` | 98 | 2.9s |  |
| 8 | `array_constructor` | 30 | 2.9s |  |
| 9 | `array_length` | 42 | 2.9s |  |
| 10 | `array_properties` | 36 | 2.8s |  |
| 11 | `array_slice` | 34 | 2.9s |  |
| 12 | `array_splice` | 207 | 3.6s |  |
| 13 | `array_trivial` | 209 | 3.3s |  |
| 14 | `as1_constructor_v6` | 35 | 2.8s |  |
| 15 | `as1_constructor_v7` | 35 | 2.8s |  |
| 16 | `as_broadcaster_initialize` | 10 | 2.7s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 2.7s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 2.7s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 2.8s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 2.7s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 2.7s |  |
| 22 | `bad_swf_tag_past_eof` | 0 | 2.6s |  |
| 23 | `bitand` | 1058 | 10.1s |  |
| 24 | `bitmap_data_colortransform` | 0 | 3.0s |  |
| 25 | `bitmap_data_fillrect` | 0 | 2.9s |  |
| 26 | `bitmap_data_perlinnoise` | 0 | 3.5s |  |
| 27 | `bitmap_data_pixeldissolve_image` | 0 | 3.3s |  |
| 28 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.8s |  |
| 29 | `bitor` | 1058 | 10.2s |  |
| 30 | `biturshift` | 14 | 2.9s |  |
| 31 | `biturshift_swf8` | 14 | 2.7s |  |
| 32 | `bitxor` | 1058 | 9.4s |  |
| 33 | `call_method_empty_name` | 1 | 2.6s |  |
| 34 | `catch_references_registers` | 2 | 2.6s |  |
| 35 | `define_function2` | 8 | 2.6s |  |
| 36 | `define_function2_preload` | 13 | 2.6s |  |
| 37 | `define_function2_preload_order` | 4 | 2.6s |  |
| 38 | `define_function_case_sensitive` | 2 | 2.6s |  |
| 39 | `delete` | 3 | 2.7s |  |
| 40 | `divide_swf4` | 107 | 2.8s |  |
| 41 | `do_init_action` | 3 | 2.7s |  |
| 42 | `equals` | 32 | 2.7s |  |
| 43 | `equals2_swf5` | 926 | 11.1s |  |
| 44 | `equals2_swf6` | 926 | 11.1s |  |
| 45 | `equals2_swf7` | 926 | 11.1s |  |
| 46 | `equals_swf4` | 665 | 6.4s |  |
| 47 | `equals_swf4_alt` | 32 | 2.7s |  |
| 48 | `equals_swf5` | 32 | 2.7s |  |
| 49 | `error` | 58 | 2.9s |  |
| 50 | `escape` | 14 | 2.7s |  |
| 51 | `execution_order3` | 4 | 2.7s |  |
| 52 | `get_variable_in_scope` | 29 | 2.8s |  |
| 53 | `getproperty` | 28 | 2.7s |  |
| 54 | `getproperty_swf4` | 28 | 2.7s |  |
| 55 | `getproperty_swf5` | 28 | 2.7s |  |
| 56 | `global_array` | 3 | 2.7s |  |
| 57 | `global_is_bare` | 7 | 2.6s |  |
| 58 | `goto_advance2` | 2 | 2.7s |  |
| 59 | `goto_both_ways1` | 3 | 3.5s |  |
| 60 | `goto_both_ways2` | 3 | 2.6s |  |
| 61 | `goto_execution_order` | 2 | 2.6s |  |
| 62 | `goto_execution_order2` | 2 | 2.6s |  |
| 63 | `goto_rewind1` | 1 | 2.6s |  |
| 64 | `goto_rewind2` | 3 | 2.6s |  |
| 65 | `goto_rewind3` | 2 | 2.6s |  |
| 66 | `greater_swf6` | 1175 | 11.4s |  |
| 67 | `greater_swf7` | 1175 | 11.7s |  |
| 68 | `greaterthan_swf5` | 1 | 2.6s |  |
| 69 | `greaterthan_swf8` | 1 | 2.6s |  |
| 70 | `has_own_property` | 32 | 2.8s |  |
| 71 | `infinite_recursion_function_in_setter` | 131 | 2.7s |  |
| 72 | `infinite_recursion_virtual_property` | 67 | 2.6s |  |
| 73 | `init_array_invalid` | 4 | 2.6s |  |
| 74 | `init_object_invalid` | 4 | 2.6s |  |
| 75 | `issue_1086` | 1 | 2.6s |  |
| 76 | `issue_1671` | 0 | 2.6s |  |
| 77 | `issue_1906` | 4 | 2.7s |  |
| 78 | `issue_3446` | 1 | 2.6s |  |
| 79 | `issue_4377` | 2 | 2.6s |  |
| 80 | `issue_710` | 4 | 2.6s |  |
| 81 | `issue_768` | 3 | 2.6s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 82 | `lessthan` | 41 | 2.8s |  |
| 83 | `lessthan2_swf5` | 1226 | 12.1s |  |
| 84 | `lessthan2_swf6` | 1226 | 12.3s |  |
| 85 | `lessthan2_swf7` | 1226 | 12.3s |  |
| 86 | `lessthan_swf4` | 902 | 8.3s |  |
| 87 | `lessthan_swf4_alt` | 41 | 2.8s |  |
| 88 | `lessthan_swf5` | 41 | 2.8s |  |
| 89 | `logical_ops_swf4` | 90 | 2.8s |  |
| 90 | `logical_ops_swf8` | 108 | 2.8s |  |
| 91 | `looping` | 6 | 2.6s |  |
| 92 | `mask_reapply` | 0 | 2.6s |  |
| 93 | `mask_with_drawing` | 0 | 2.6s |  |
| 94 | `movieclip_begin_gradient_fill` | 0 | 3.3s |  |
| 95 | `movieclip_line_gradient_style` | 0 | 3.2s |  |
| 96 | `movieclip_prototype_extension` | 5 | 2.6s |  |
| 97 | `nested_textfields_in_buttons` | 0 | 2.6s |  |
| 98 | `new_method_wrap` | 4 | 2.6s |  |
| 99 | `new_object_enumerate` | 7 | 2.7s |  |
| 100 | `new_object_wrap` | 4 | 2.6s |  |
| 101 | `o` | 3 | 2.6s |  |
| 102 | `object_constructor` | 33 | 2.7s |  |
| 103 | `object_function` | 32 | 2.7s |  |
| 104 | `object_string_coerce_swf5` | 62 | 2.8s |  |
| 105 | `primitive_instanceof` | 37 | 2.7s |  |
| 106 | `prototype_delete` | 12 | 2.7s |  |
| 107 | `recursive_prototypes` | 0 | 2.6s |  |
| 108 | `sandbox_type_local_network` | 1 | 2.6s |  |
| 109 | `single_frame` | 1 | 2.6s |  |
| 110 | `stage_object_properties_get_var` | 5 | 2.6s |  |
| 111 | `strictequals_swf6` | 902 | 8.8s |  |
| 112 | `strictly_equals` | 7 | 2.7s |  |
| 113 | `string_coercion` | 117 | 3.2s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 114 | `string_paths_keyevents` | 0 | 2.6s |  |
| 115 | `string_paths_timer` | 0 | 2.6s |  |
| 116 | `swf4_actions_bool` | 96 | 2.8s |  |
| 117 | `swf4_bool` | 4 | 2.6s |  |
| 118 | `swf4_function_calls` | 7 | 3.8s |  |
| 119 | `swf5_encoding` | 3 | 2.8s |  |
| 120 | `this_swf7` | 41 | 2.7s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 121 | `timeline_function_def` | 7 | 2.8s |  |
| 122 | `try_finally_simple` | 16 | 2.7s |  |
| 123 | `typeof_globals` | 7 | 2.6s |  |
| 124 | `undefined_to_string_swf6` | 4 | 2.6s |  |
| 125 | `unescape` | 43 | 2.8s |  |
| 126 | `waitforframe` | 7 | 2.6s |  |
| 127 | `waitforframe2` | 16 | 2.7s |  |
| 128 | `with_return` | 2 | 2.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**89 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `swf7_case_sensitive` | 93.2% | 41 | 44 | 3 |  |
| 2 | `set_variable_scope` | 87.9% | 51 | 58 | 7 |  |
| 3 | `typeof` | 86.4% | 19 | 22 | 3 |  |
| 4 | `textfield_text` | 85.7% | 6 | 7 | 1 |  |
| 5 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 6 | `stage_object_children` | 79.5% | 66 | 83 | 17 |  |
| 7 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 8 | `conflicting_instance_names` | 78.3% | 18 | 23 | 5 |  |
| 9 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 10 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
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
| 22 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 23 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 24 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 25 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 26 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 27 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 28 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 29 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 30 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 31 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 32 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 33 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 34 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 35 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 36 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 37 | `target_clip_removed` | 66.7% | 4 | 6 | 2 |  |
| 38 | `textfield_variable` | 66.7% | 54 | 81 | 27 |  |
| 39 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 40 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 41 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 42 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 43 | `stage_object_properties_swf6` | 64.5% | 149 | 231 | 82 |  |
| 44 | `stage_object_properties` | 64.3% | 155 | 241 | 86 |  |
| 45 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 46 | `slash_syntax` | 64.3% | 9 | 14 | 5 |  |
| 47 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 48 | `with` | 61.2% | 30 | 49 | 19 |  |
| 49 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 50 | `edittext_scroll` | 61.1% | 33 | 54 | 21 |  |
| 51 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 52 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 53 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 54 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 55 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 56 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 57 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 58 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 59 | `execution_order1` | 60.0% | 3 | 5 | 2 |  |
| 60 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 61 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 62 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 63 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 64 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 65 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 66 | `swf6_case_insensitive` | 56.8% | 25 | 44 | 19 |  |
| 67 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 68 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 69 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 70 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 71 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 72 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 73 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 74 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 75 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 76 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 77 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 78 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 79 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 80 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 81 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 82 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 83 | `goto_methods` | 50.0% | 20 | 40 | 20 |  |
| 84 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 85 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 86 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 87 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 88 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 89 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 12.9s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.7s |  |
| 3 | `path_string` | 5.2s |  |
| 4 | `swf4_actions_coercion_order` | 4.9s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.6s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.6s |  |

## Timeouts

**3 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.7s |  |
| 2 | `timeout` | runtime timeout (>10s) | 12.9s |  |
| 3 | `try_catch_finally` | runtime timeout (>10s) | 13.1s |  |

## All Output Mismatches

**357 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `swf7_case_sensitive` | 93.2% | 41/44 | 44 | 44 |  |
| 2 | `set_variable_scope` | 87.9% | 51/58 | 58 | 58 |  |
| 3 | `typeof` | 86.4% | 19/22 | 22 | 22 |  |
| 4 | `textfield_text` | 85.7% | 6/7 | 7 | 7 |  |
| 5 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 6 | `stage_object_children` | 79.5% | 66/83 | 83 | 83 |  |
| 7 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 8 | `conflicting_instance_names` | 78.3% | 18/23 | 23 | 23 |  |
| 9 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 10 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
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
| 22 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 23 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 24 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 25 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 26 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 27 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 28 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 29 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 30 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 31 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 32 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 33 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 34 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 35 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 36 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 37 | `target_clip_removed` | 66.7% | 4/6 | 6 | 5 |  |
| 38 | `textfield_variable` | 66.7% | 54/81 | 81 | 81 |  |
| 39 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 40 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 41 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 42 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 43 | `stage_object_properties_swf6` | 64.5% | 149/231 | 231 | 231 |  |
| 44 | `stage_object_properties` | 64.3% | 155/241 | 241 | 241 |  |
| 45 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 46 | `slash_syntax` | 64.3% | 9/14 | 14 | 14 |  |
| 47 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 48 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 49 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 50 | `edittext_scroll` | 61.1% | 33/54 | 54 | 54 |  |
| 51 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 52 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 53 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 54 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 55 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 56 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 57 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 58 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 59 | `execution_order1` | 60.0% | 3/5 | 3 | 5 |  |
| 60 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 61 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 62 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 63 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 64 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 65 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 66 | `swf6_case_insensitive` | 56.8% | 25/44 | 44 | 42 |  |
| 67 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 68 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 69 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 70 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 71 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 72 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 73 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 74 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 75 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 76 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 77 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 78 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 79 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 80 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 81 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 82 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 83 | `goto_methods` | 50.0% | 20/40 | 40 | 40 |  |
| 84 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 85 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 86 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 87 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 88 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 89 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 90 | `edittext_newline_stripping` | 49.2% | 32/65 | 65 | 64 |  |
| 91 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 92 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 93 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 94 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 95 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 96 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 97 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 98 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 99 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 100 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 101 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 102 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 103 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 104 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 105 | `as2_oop` | 38.5% | 5/13 | 10 | 13 |  |
| 106 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 107 | `edittext_html_swf6` | 37.5% | 2014/5377 | 5377 | 5377 |  |
| 108 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 109 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 110 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 111 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 112 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 113 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 114 | `frame_size_translated_negative` | 33.3% | 7/21 | 20 | 21 |  |
| 115 | `init_object_order` | 33.3% | 5/15 | 5 | 15 |  |
| 116 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 117 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 118 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 119 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 120 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 121 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 122 | `edittext_html_condensewhite_swf7` | 29.9% | 93/311 | 311 | 311 |  |
| 123 | `edittext_html_condensewhite_swf8` | 28.9% | 90/311 | 311 | 311 |  |
| 124 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 125 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 126 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 127 | `edittext_html_swf7` | 25.6% | 1378/5377 | 5377 | 5377 |  |
| 128 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 129 | `edittext_html_swf8` | 25.3% | 1363/5377 | 5377 | 5377 |  |
| 130 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 131 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 132 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 133 | `goto_frame` | 25.0% | 3/12 | 3 | 12 |  |
| 134 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 135 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 136 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 137 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 138 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 139 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 140 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 141 | `textfield_props_swf5` | 21.1% | 37/175 | 139 | 175 |  |
| 142 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 143 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 144 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 145 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 146 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 147 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 148 | `register_and_init_order` | 18.2% | 42/231 | 101 | 231 |  |
| 149 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 150 | `textfield_props_swf6` | 17.6% | 37/210 | 140 | 210 |  |
| 151 | `textfield_props_swf7` | 17.1% | 36/210 | 140 | 210 |  |
| 152 | `textfield_props_swf8` | 17.1% | 36/210 | 140 | 210 |  |
| 153 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 154 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 155 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 156 | `edittext_tag_indent` | 16.1% | 5/31 | 31 | 31 |  |
| 157 | `watch` | 15.4% | 18/117 | 100 | 117 |  |
| 158 | `as2_super_via_manual_prototype` | 15.0% | 6/40 | 16 | 40 |  |
| 159 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 160 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 161 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 162 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 163 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 164 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 165 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 166 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 167 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 168 | `movieclip_hittest_shapeflag` | 14.2% | 48/338 | 338 | 338 |  |
| 169 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 170 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 171 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 172 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 173 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 174 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 175 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 176 | `goto_label` | 11.8% | 2/17 | 4 | 17 |  |
| 177 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 178 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 179 | `extends_chain` | 11.2% | 15/134 | 114 | 134 |  |
| 180 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 181 | `edittext_autosize_setter` | 10.0% | 2/20 | 20 | 20 |  |
| 182 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 183 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 184 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 185 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 186 | `goto_frame2` | 9.1% | 4/44 | 4 | 44 |  |
| 187 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 188 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 189 | `execution_order4` | 8.3% | 1/12 | 8 | 12 |  |
| 190 | `tell_target` | 8.1% | 3/37 | 33 | 37 |  |
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
| 201 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 202 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 203 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 204 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 205 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 206 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 207 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 208 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 209 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 210 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 211 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 212 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 213 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 214 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 215 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 216 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 217 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 218 | `unload` | 3.8% | 2/52 | 36 | 52 |  |
| 219 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 220 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 221 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 222 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 223 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 224 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 225 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 226 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 227 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 228 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 229 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 230 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 231 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 232 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 233 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 234 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 235 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 236 | `global_proto_decls` | 0.0% | 1/4497 | 20 | 4497 |  |
| 237 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 238 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 239 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 240 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 241 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 242 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 243 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 244 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 245 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 246 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 247 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 248 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 249 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 250 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 251 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 252 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 253 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 254 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 255 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 256 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 257 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 258 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 259 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 260 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 261 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 262 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 263 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 264 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 265 | `extends_native_type` | 0.0% | 0/11 | 4 | 11 |  |
| 266 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 267 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 268 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 269 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 270 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 271 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 272 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 273 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 274 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 275 | `global_proto_decls_delete` | 0.0% | 0/4158 | 14 | 4158 |  |
| 276 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 277 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 278 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 279 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 280 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 281 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 282 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 283 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 284 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 285 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 286 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 287 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 288 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 289 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 290 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 291 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 292 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 293 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 294 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 295 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 296 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 297 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 298 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 299 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 300 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 301 | `native_objects_swf6` | 0.0% | 0/178 | 178 | 84 |  |
| 302 | `native_objects_swf7` | 0.0% | 0/178 | 178 | 84 |  |
| 303 | `native_objects_swf8` | 0.0% | 0/178 | 178 | 84 |  |
| 304 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 305 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 306 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 307 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 308 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 309 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 310 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 311 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 312 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 313 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 314 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 315 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 316 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 317 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 318 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 319 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 320 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 321 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 322 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 323 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 324 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 325 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 326 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 327 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 328 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 329 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 330 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 331 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 332 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 333 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 334 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 335 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 336 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 337 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 338 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 339 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 340 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 341 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 342 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 343 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 344 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 345 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 346 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 347 | `variable_args` | 0.0% | 0/6 | 6 | 5 |  |
| 348 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 349 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 350 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 351 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 352 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 353 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 354 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 355 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 356 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 357 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
