# Ruffle Test Results (Filtered)

**Date**: 2026-02-13 05:32 UTC

**Git SHA**: `e145c7e849`

**Run Duration**: 31m 59s

**Filtered**: 125 tests ignored out of 616 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 491 |
| Passing | **120** (24.4%) |
| Failing | 371 |
| Total expected lines | 76941 |
| Matching lines | 32326 (42.0%) |
| Mismatched lines | 44615 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 361 | 97.3% |
| Segfault | 4 | 1.1% |
| Timeout | 4 | 1.1% |
| Runtime Error | 2 | 0.5% |

## Passing Tests

**120 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.9s |  |
| 2 | `action_to_integer` | 28 | 2.6s |  |
| 3 | `add` | 28 | 2.6s |  |
| 4 | `add2` | 354 | 3.0s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.6s |  |
| 6 | `add_swf5` | 28 | 2.6s |  |
| 7 | `array_concat` | 98 | 2.8s |  |
| 8 | `array_constructor` | 30 | 2.7s |  |
| 9 | `array_properties` | 36 | 2.6s |  |
| 10 | `array_slice` | 34 | 2.7s |  |
| 11 | `array_splice` | 207 | 3.4s |  |
| 12 | `array_trivial` | 209 | 3.1s |  |
| 13 | `as1_constructor_v6` | 35 | 2.6s |  |
| 14 | `as1_constructor_v7` | 35 | 2.6s |  |
| 15 | `as_broadcaster_initialize` | 10 | 2.5s |  |
| 16 | `as_set_prop_flags_version_swf5` | 1 | 2.6s |  |
| 17 | `as_set_prop_flags_version_swf6` | 1 | 2.6s |  |
| 18 | `as_set_prop_flags_version_swf7` | 1 | 2.6s |  |
| 19 | `as_set_prop_flags_version_swf8` | 1 | 2.6s |  |
| 20 | `as_set_prop_flags_version_swf9` | 1 | 2.6s |  |
| 21 | `bad_swf_tag_past_eof` | 0 | 2.4s |  |
| 22 | `bitand` | 1058 | 9.6s |  |
| 23 | `bitmap_data_colortransform` | 0 | 2.9s |  |
| 24 | `bitmap_data_fillrect` | 0 | 2.7s |  |
| 25 | `bitmap_data_perlinnoise` | 0 | 3.3s |  |
| 26 | `bitmap_data_pixeldissolve_image` | 0 | 3.0s |  |
| 27 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.5s |  |
| 28 | `bitor` | 1058 | 9.5s |  |
| 29 | `biturshift` | 14 | 3.9s |  |
| 30 | `biturshift_swf8` | 14 | 2.5s |  |
| 31 | `bitxor` | 1058 | 9.2s |  |
| 32 | `call_method_empty_name` | 1 | 2.5s |  |
| 33 | `catch_references_registers` | 2 | 2.5s |  |
| 34 | `define_function2` | 8 | 2.5s |  |
| 35 | `define_function_case_sensitive` | 2 | 2.6s |  |
| 36 | `delete` | 3 | 2.6s |  |
| 37 | `divide_swf4` | 107 | 2.7s |  |
| 38 | `do_init_action` | 3 | 2.5s |  |
| 39 | `equals` | 32 | 2.5s |  |
| 40 | `equals2_swf5` | 926 | 10.6s |  |
| 41 | `equals2_swf6` | 926 | 10.6s |  |
| 42 | `equals2_swf7` | 926 | 10.6s |  |
| 43 | `equals_swf4` | 665 | 6.0s |  |
| 44 | `equals_swf4_alt` | 32 | 2.5s |  |
| 45 | `equals_swf5` | 32 | 2.5s |  |
| 46 | `error` | 58 | 2.7s |  |
| 47 | `escape` | 14 | 2.5s |  |
| 48 | `execution_order3` | 4 | 2.5s |  |
| 49 | `get_variable_in_scope` | 29 | 2.6s |  |
| 50 | `getproperty` | 28 | 2.5s |  |
| 51 | `getproperty_swf4` | 28 | 2.5s |  |
| 52 | `getproperty_swf5` | 28 | 2.5s |  |
| 53 | `global_array` | 3 | 2.5s |  |
| 54 | `global_is_bare` | 7 | 2.5s |  |
| 55 | `goto_advance2` | 2 | 2.5s |  |
| 56 | `goto_both_ways1` | 3 | 3.5s |  |
| 57 | `goto_both_ways2` | 3 | 2.5s |  |
| 58 | `goto_execution_order` | 2 | 2.5s |  |
| 59 | `goto_execution_order2` | 2 | 2.5s |  |
| 60 | `goto_rewind1` | 1 | 2.6s |  |
| 61 | `goto_rewind2` | 3 | 2.5s |  |
| 62 | `goto_rewind3` | 2 | 2.5s |  |
| 63 | `greater_swf6` | 1175 | 11.7s |  |
| 64 | `greater_swf7` | 1175 | 11.7s |  |
| 65 | `greaterthan_swf5` | 1 | 2.5s |  |
| 66 | `greaterthan_swf8` | 1 | 2.5s |  |
| 67 | `has_own_property` | 32 | 2.6s |  |
| 68 | `infinite_recursion_function_in_setter` | 131 | 2.5s |  |
| 69 | `infinite_recursion_virtual_property` | 67 | 2.5s |  |
| 70 | `init_array_invalid` | 4 | 2.5s |  |
| 71 | `init_object_invalid` | 4 | 2.5s |  |
| 72 | `issue_1086` | 1 | 2.5s |  |
| 73 | `issue_1671` | 0 | 2.5s |  |
| 74 | `issue_3446` | 1 | 2.5s |  |
| 75 | `issue_4377` | 2 | 2.5s |  |
| 76 | `issue_710` | 4 | 2.6s |  |
| 77 | `issue_768` | 3 | 2.5s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 78 | `lessthan` | 41 | 2.6s |  |
| 79 | `lessthan2_swf5` | 1226 | 12.7s |  |
| 80 | `lessthan2_swf6` | 1226 | 12.6s |  |
| 81 | `lessthan2_swf7` | 1226 | 13.1s |  |
| 82 | `lessthan_swf4` | 902 | 8.4s |  |
| 83 | `lessthan_swf4_alt` | 41 | 2.6s |  |
| 84 | `lessthan_swf5` | 41 | 2.6s |  |
| 85 | `logical_ops_swf4` | 90 | 2.7s |  |
| 86 | `logical_ops_swf8` | 108 | 2.7s |  |
| 87 | `looping` | 6 | 2.5s |  |
| 88 | `mask_reapply` | 0 | 2.5s |  |
| 89 | `mask_with_drawing` | 0 | 2.5s |  |
| 90 | `movieclip_begin_gradient_fill` | 0 | 3.2s |  |
| 91 | `movieclip_line_gradient_style` | 0 | 3.0s |  |
| 92 | `movieclip_prototype_extension` | 5 | 2.5s |  |
| 93 | `nested_textfields_in_buttons` | 0 | 2.4s |  |
| 94 | `new_object_enumerate` | 7 | 2.6s |  |
| 95 | `new_object_wrap` | 4 | 2.5s |  |
| 96 | `object_constructor` | 33 | 2.6s |  |
| 97 | `object_function` | 32 | 2.6s |  |
| 98 | `object_string_coerce_swf5` | 62 | 2.7s |  |
| 99 | `primitive_instanceof` | 37 | 2.6s |  |
| 100 | `prototype_delete` | 12 | 2.6s |  |
| 101 | `recursive_prototypes` | 0 | 2.5s |  |
| 102 | `sandbox_type_local_network` | 1 | 2.5s |  |
| 103 | `single_frame` | 1 | 2.5s |  |
| 104 | `stage_object_properties_get_var` | 5 | 2.5s |  |
| 105 | `strictequals_swf6` | 902 | 8.7s |  |
| 106 | `strictly_equals` | 7 | 2.5s |  |
| 107 | `string_coercion` | 117 | 3.1s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 108 | `string_paths_keyevents` | 0 | 2.5s |  |
| 109 | `string_paths_timer` | 0 | 2.5s |  |
| 110 | `swf4_actions_bool` | 96 | 2.7s |  |
| 111 | `swf4_bool` | 4 | 2.5s |  |
| 112 | `swf4_function_calls` | 7 | 2.6s |  |
| 113 | `swf5_encoding` | 3 | 2.6s |  |
| 114 | `this_swf7` | 41 | 2.5s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 115 | `timeline_function_def` | 7 | 2.6s |  |
| 116 | `try_finally_simple` | 16 | 2.4s |  |
| 117 | `typeof_globals` | 7 | 2.4s |  |
| 118 | `undefined_to_string_swf6` | 4 | 2.4s |  |
| 119 | `unescape` | 43 | 2.5s |  |
| 120 | `with_return` | 2 | 2.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**84 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `swf7_case_sensitive` | 93.2% | 41 | 44 | 3 |  |
| 2 | `set_variable_scope` | 87.9% | 51 | 58 | 7 |  |
| 3 | `array_length` | 83.3% | 35 | 42 | 7 |  |
| 4 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 5 | `stage_object_children` | 79.5% | 66 | 83 | 17 |  |
| 6 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 7 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 8 | `new_method_wrap` | 75.0% | 3 | 4 | 1 |  |
| 9 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 10 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 11 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 12 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 13 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 14 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 15 | `point` | 70.9% | 124 | 175 | 51 |  |
| 16 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 17 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 18 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 19 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 20 | `define_function2_preload` | 69.2% | 9 | 13 | 4 |  |
| 21 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 22 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 23 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 24 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 25 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 26 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 27 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 28 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 29 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 30 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 31 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 32 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 33 | `o` | 66.7% | 2 | 3 | 1 |  |
| 34 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 35 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 36 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 37 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 38 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 39 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 40 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
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
| 54 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 55 | `as_set_prop_flags_version` | 58.1% | 18 | 31 | 13 |  |
| 56 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 57 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 58 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 59 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 60 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 61 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 62 | `swf6_case_insensitive` | 56.8% | 25 | 44 | 19 |  |
| 63 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 64 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 65 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 66 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 67 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 68 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 69 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 70 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 71 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 72 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 73 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 74 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 75 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 76 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 77 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 78 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 79 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 80 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 81 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 82 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 83 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 84 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 12.0s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.6s |  |
| 3 | `path_string` | 5.0s |  |
| 4 | `swf4_actions_coercion_order` | 4.9s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.4s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.4s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.6s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.6s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.6s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 13.2s |  |

## All Output Mismatches

**361 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `swf7_case_sensitive` | 93.2% | 41/44 | 44 | 44 |  |
| 2 | `set_variable_scope` | 87.9% | 51/58 | 58 | 58 |  |
| 3 | `array_length` | 83.3% | 35/42 | 42 | 42 |  |
| 4 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 5 | `stage_object_children` | 79.5% | 66/83 | 83 | 83 |  |
| 6 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 7 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 8 | `new_method_wrap` | 75.0% | 3/4 | 4 | 4 |  |
| 9 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 10 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 11 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 12 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 13 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 14 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 15 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 16 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 17 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 18 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 19 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 20 | `define_function2_preload` | 69.2% | 9/13 | 13 | 13 |  |
| 21 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 22 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 23 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 24 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 25 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 26 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 27 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 28 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 29 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 30 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 31 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 32 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 33 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 34 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 35 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 36 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 37 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 38 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 39 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 40 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
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
| 54 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 55 | `as_set_prop_flags_version` | 58.1% | 18/31 | 29 | 31 |  |
| 56 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 57 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 58 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 59 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 60 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 61 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 62 | `swf6_case_insensitive` | 56.8% | 25/44 | 44 | 42 |  |
| 63 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 64 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 65 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 66 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 67 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 68 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 69 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 70 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 71 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 72 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 73 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 74 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 75 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 76 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 77 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 78 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 79 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 80 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 81 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 82 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 83 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 84 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 85 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 86 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 87 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 88 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 89 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 90 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 91 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 92 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 93 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 94 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 95 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 96 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 97 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 98 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 99 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 100 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 101 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 102 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 103 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 104 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 105 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 106 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 107 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 108 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 109 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 110 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 111 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 112 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 113 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 114 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 115 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 116 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 117 | `frame_size_translated_negative` | 28.6% | 6/21 | 20 | 21 |  |
| 118 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 119 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 120 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 121 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 122 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 123 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 124 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 125 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 126 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 127 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 128 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 129 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 130 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 131 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 132 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 133 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 134 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 135 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 136 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 137 | `funky_function_calls` | 21.4% | 12/56 | 32 | 56 |  |
| 138 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 139 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 140 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 141 | `target_clip_removed` | 20.0% | 1/5 | 5 | 5 |  |
| 142 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 143 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 144 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 145 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 146 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 147 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 148 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 149 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 150 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 151 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 152 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 153 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 154 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 155 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 156 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 157 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 158 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 159 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 160 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 161 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 162 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 163 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 164 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 165 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 166 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 167 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 168 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 169 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 170 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 171 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 172 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 173 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 174 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 175 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 176 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 177 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 178 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 179 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 180 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 181 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 182 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 183 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 184 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 185 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 186 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 187 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 188 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 189 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 190 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 191 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 192 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 193 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 194 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 195 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 196 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 197 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 198 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 199 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 200 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 201 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 202 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 203 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 204 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 205 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 206 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 207 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 208 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 209 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 210 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 211 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 21 | 112 |  |
| 212 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 213 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 214 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 215 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 216 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 217 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 218 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 219 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 220 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 221 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 222 | `as2_oop` | 0.0% | 0/13 | 0 | 13 |  |
| 223 | `as2_super_and_this_v6` | 0.0% | 0/97 | 0 | 97 |  |
| 224 | `as2_super_and_this_v8` | 0.0% | 0/85 | 0 | 85 |  |
| 225 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 0 | 40 |  |
| 226 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 227 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 228 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 229 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 230 | `button_children` | 0.0% | 0/8 | 0 | 8 |  |
| 231 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 232 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 233 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 234 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 235 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 236 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 237 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 238 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 239 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 240 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 241 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 242 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 243 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 244 | `color` | 0.0% | 0/57 | 0 | 57 |  |
| 245 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 246 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 247 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 248 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 249 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 250 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 251 | `duplicate_movie_clip` | 0.0% | 0/20 | 0 | 20 |  |
| 252 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 253 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 254 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 255 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 256 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 257 | `extends_chain` | 0.0% | 0/134 | 0 | 134 |  |
| 258 | `extends_native_type` | 0.0% | 0/11 | 0 | 11 |  |
| 259 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 260 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 261 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 262 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 263 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 264 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 265 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 266 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 267 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 268 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 269 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 270 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 271 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 272 | `goto_frame` | 0.0% | 0/12 | 0 | 12 |  |
| 273 | `goto_frame2` | 0.0% | 0/44 | 0 | 44 |  |
| 274 | `goto_label` | 0.0% | 0/17 | 0 | 17 |  |
| 275 | `goto_methods` | 0.0% | 0/40 | 0 | 40 |  |
| 276 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 277 | `hittest_morph` | 0.0% | 0/70 | 0 | 70 |  |
| 278 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 279 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 280 | `init_object_order` | 0.0% | 0/15 | 0 | 15 |  |
| 281 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 282 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 283 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 284 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 285 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 286 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 287 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 288 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 289 | `issue_9885` | 0.0% | 0/2 | 0 | 2 |  |
| 290 | `localconnection` | 0.0% | 0/579 | 0 | 579 |  |
| 291 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 292 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 293 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 294 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 295 | `movieclip_init_object` | 0.0% | 0/5 | 0 | 5 |  |
| 296 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 297 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 298 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 299 | `native_objects_swf6` | 0.0% | 0/84 | 0 | 84 |  |
| 300 | `native_objects_swf7` | 0.0% | 0/84 | 0 | 84 |  |
| 301 | `native_objects_swf8` | 0.0% | 0/84 | 0 | 84 |  |
| 302 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 303 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 304 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 305 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 306 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 307 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 308 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
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
| 319 | `selection` | 0.0% | 0/454 | 0 | 454 |  |
| 320 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 321 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 322 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 323 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 324 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 325 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 326 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 327 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 328 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 329 | `stylesheet` | 0.0% | 0/283 | 0 | 283 |  |
| 330 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 331 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 332 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 333 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 334 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 335 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 336 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 337 | `target_path` | 0.0% | 0/14 | 0 | 14 |  |
| 338 | `tell_target_invalid` | 0.0% | 0/6 | 4 | 6 |  |
| 339 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 4 | 5 |  |
| 340 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 341 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 342 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 343 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 344 | `timer_run_actions` | 0.0% | 0/18 | 0 | 18 |  |
| 345 | `typeof` | 0.0% | 0/22 | 0 | 22 |  |
| 346 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 347 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 348 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 349 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 350 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 351 | `watch` | 0.0% | 0/117 | 0 | 117 |  |
| 352 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 353 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 354 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 355 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 356 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 357 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 358 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 359 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 360 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 361 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
