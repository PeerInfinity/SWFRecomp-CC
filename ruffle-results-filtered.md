# Ruffle Test Results (Filtered)

**Date**: 2026-02-12 20:38 UTC

**Git SHA**: `0f4ca778db`

**Run Duration**: 28m 43s

**Filtered**: 125 tests ignored out of 616 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 491 |
| Passing | **71** (14.5%) |
| Failing | 420 |
| Total expected lines | 76447 |
| Matching lines | 31998 (41.9%) |
| Mismatched lines | 44449 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 405 | 96.4% |
| Segfault | 8 | 1.9% |
| Timeout | 4 | 1.0% |
| Runtime Error | 2 | 0.5% |
| Compile Fail | 1 | 0.2% |

## Passing Tests

**71 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.3s |  |
| 2 | `action_to_integer` | 28 | 2.2s |  |
| 3 | `add` | 28 | 2.2s |  |
| 4 | `add2` | 354 | 2.6s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.2s |  |
| 6 | `add_swf5` | 28 | 2.2s |  |
| 7 | `array_concat` | 98 | 2.4s |  |
| 8 | `array_properties` | 36 | 2.2s |  |
| 9 | `array_slice` | 34 | 2.3s |  |
| 10 | `array_splice` | 207 | 3.0s |  |
| 11 | `array_trivial` | 209 | 2.7s |  |
| 12 | `as1_constructor_v6` | 35 | 2.3s |  |
| 13 | `as1_constructor_v7` | 35 | 2.3s |  |
| 14 | `as_broadcaster_initialize` | 10 | 2.2s |  |
| 15 | `as_set_prop_flags_version_swf5` | 1 | 2.2s |  |
| 16 | `bitand` | 1058 | 10.8s |  |
| 17 | `bitor` | 1058 | 10.9s |  |
| 18 | `biturshift` | 14 | 3.4s |  |
| 19 | `biturshift_swf8` | 14 | 2.2s |  |
| 20 | `bitxor` | 1058 | 10.9s |  |
| 21 | `catch_references_registers` | 2 | 2.1s |  |
| 22 | `define_function_case_sensitive` | 2 | 2.2s |  |
| 23 | `delete` | 3 | 2.2s |  |
| 24 | `divide_swf4` | 107 | 2.3s |  |
| 25 | `do_init_action` | 3 | 2.2s |  |
| 26 | `equals` | 32 | 2.2s |  |
| 27 | `equals2_swf5` | 926 | 11.0s |  |
| 28 | `equals2_swf6` | 926 | 11.2s |  |
| 29 | `equals2_swf7` | 926 | 11.0s |  |
| 30 | `equals_swf4` | 665 | 5.6s |  |
| 31 | `equals_swf4_alt` | 32 | 2.1s |  |
| 32 | `equals_swf5` | 32 | 2.2s |  |
| 33 | `global_array` | 3 | 2.1s |  |
| 34 | `global_is_bare` | 7 | 2.0s |  |
| 35 | `goto_execution_order` | 2 | 2.1s |  |
| 36 | `goto_rewind1` | 1 | 2.2s |  |
| 37 | `greater_swf6` | 1175 | 11.4s |  |
| 38 | `greater_swf7` | 1175 | 11.3s |  |
| 39 | `greaterthan_swf5` | 1 | 2.2s |  |
| 40 | `greaterthan_swf8` | 1 | 2.2s |  |
| 41 | `has_own_property` | 32 | 2.3s |  |
| 42 | `infinite_recursion_function_in_setter` | 131 | 2.2s |  |
| 43 | `infinite_recursion_virtual_property` | 67 | 2.2s |  |
| 44 | `issue_1086` | 1 | 2.1s |  |
| 45 | `issue_3446` | 1 | 2.2s |  |
| 46 | `issue_4377` | 2 | 2.2s |  |
| 47 | `issue_768` | 3 | 2.2s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 48 | `lessthan` | 41 | 2.3s |  |
| 49 | `lessthan2_swf5` | 1226 | 11.9s |  |
| 50 | `lessthan2_swf6` | 1226 | 11.9s |  |
| 51 | `lessthan2_swf7` | 1226 | 11.9s |  |
| 52 | `lessthan_swf4` | 902 | 7.7s |  |
| 53 | `lessthan_swf4_alt` | 41 | 2.2s |  |
| 54 | `lessthan_swf5` | 41 | 2.3s |  |
| 55 | `logical_ops_swf4` | 90 | 2.3s |  |
| 56 | `logical_ops_swf8` | 108 | 2.3s |  |
| 57 | `looping` | 6 | 2.2s |  |
| 58 | `object_function` | 32 | 2.2s |  |
| 59 | `sandbox_type_local_file` | 1 | 2.2s |  |
| 60 | `single_frame` | 1 | 2.1s |  |
| 61 | `strictequals_swf6` | 902 | 9.1s |  |
| 62 | `strictly_equals` | 7 | 2.3s |  |
| 63 | `swf4_actions_bool` | 96 | 2.4s |  |
| 64 | `swf4_bool` | 4 | 2.3s |  |
| 65 | `swf5_encoding` | 3 | 2.3s |  |
| 66 | `this_swf7` | 41 | 2.2s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 67 | `timeline_function_def` | 7 | 2.2s |  |
| 68 | `try_finally_simple` | 16 | 2.1s |  |
| 69 | `typeof_globals` | 7 | 2.1s |  |
| 70 | `undefined_to_string_swf6` | 4 | 2.0s |  |
| 71 | `with_return` | 2 | 2.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**102 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `string_coercion` | 99.1% | 116 | 117 | 1 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 2 | `array_constructor` | 96.7% | 29 | 30 | 1 |  |
| 3 | `object_string_coerce_swf5` | 95.4% | 62 | 65 | 3 |  |
| 4 | `object_constructor` | 87.9% | 29 | 33 | 4 |  |
| 5 | `define_function2` | 87.5% | 7 | 8 | 1 |  |
| 6 | `set_variable_scope` | 86.2% | 50 | 58 | 8 |  |
| 7 | `swf7_case_sensitive` | 84.1% | 37 | 44 | 7 |  |
| 8 | `array_length` | 83.3% | 35 | 42 | 7 |  |
| 9 | `getproperty_swf4` | 82.1% | 23 | 28 | 5 |  |
| 10 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 11 | `movieclip_prototype_extension` | 80.0% | 4 | 5 | 1 |  |
| 12 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 13 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 14 | `stage_object_children` | 75.9% | 63 | 83 | 20 |  |
| 15 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 16 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 17 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 18 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 19 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 20 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 21 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 22 | `point` | 70.9% | 124 | 175 | 51 |  |
| 23 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 24 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 25 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 26 | `get_variable_in_scope` | 69.0% | 20 | 29 | 9 |  |
| 27 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 28 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 29 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 30 | `primitive_instanceof` | 67.6% | 25 | 37 | 12 |  |
| 31 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 32 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 33 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 34 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 35 | `goto_both_ways2` | 66.7% | 2 | 3 | 1 |  |
| 36 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 37 | `goto_rewind2` | 66.7% | 2 | 3 | 1 |  |
| 38 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 39 | `o` | 66.7% | 2 | 3 | 1 |  |
| 40 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 41 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 42 | `error` | 65.5% | 38 | 58 | 20 |  |
| 43 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 44 | `getproperty` | 64.3% | 18 | 28 | 10 |  |
| 45 | `getproperty_swf5` | 64.3% | 18 | 28 | 10 |  |
| 46 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 47 | `globals_swf6` | 64.1% | 195 | 304 | 109 |  |
| 48 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 49 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 50 | `with` | 63.3% | 31 | 49 | 18 |  |
| 51 | `globals_swf7` | 63.2% | 192 | 304 | 112 |  |
| 52 | `arguments` | 63.0% | 80 | 127 | 47 |  |
| 53 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 54 | `globals_swf5` | 61.8% | 188 | 304 | 116 |  |
| 55 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 56 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 57 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 58 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 59 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 60 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 61 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 62 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 63 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 64 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 65 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 66 | `swf6_case_insensitive` | 59.1% | 26 | 44 | 18 |  |
| 67 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 68 | `with_variable_scopes` | 58.1% | 25 | 43 | 18 |  |
| 69 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 70 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 71 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 72 | `primitive_type_globals` | 57.3% | 319 | 557 | 238 |  |
| 73 | `escape` | 57.1% | 8 | 14 | 6 |  |
| 74 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 75 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 76 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 77 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 78 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 79 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 80 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 81 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 82 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 83 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 84 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 85 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 86 | `movieclip_focusenabled` | 52.5% | 52 | 99 | 47 |  |
| 87 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 88 | `as_set_prop_flags_version` | 51.6% | 16 | 31 | 15 |  |
| 89 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 90 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 91 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 92 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 93 | `goto_advance2` | 50.0% | 1 | 2 | 1 |  |
| 94 | `goto_rewind3` | 50.0% | 1 | 2 | 1 |  |
| 95 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 96 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 97 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 98 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 99 | `prototype_delete` | 50.0% | 6 | 12 | 6 |  |
| 100 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 101 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 102 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**8 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `as2_oop` | 4.5s |  |
| 2 | `device_font_spacing` | 11.5s |  |
| 3 | `duplicate_movie_clip_drawing` | 4.2s |  |
| 4 | `enumerate` | 3.8s |  |
| 5 | `extends_chain` | 4.2s |  |
| 6 | `issue_2166` | 4.3s |  |
| 7 | `path_string` | 4.7s |  |
| 8 | `swf4_actions_coercion_order` | 4.7s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.1s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.1s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.2s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.2s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.7s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.8s |  |

## All Output Mismatches

**405 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `string_coercion` | 99.1% | 116/117 | 117 | 117 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 2 | `array_constructor` | 96.7% | 29/30 | 30 | 30 |  |
| 3 | `object_string_coerce_swf5` | 95.4% | 62/65 | 65 | 62 |  |
| 4 | `object_constructor` | 87.9% | 29/33 | 33 | 33 |  |
| 5 | `define_function2` | 87.5% | 7/8 | 8 | 8 |  |
| 6 | `set_variable_scope` | 86.2% | 50/58 | 58 | 58 |  |
| 7 | `swf7_case_sensitive` | 84.1% | 37/44 | 44 | 44 |  |
| 8 | `array_length` | 83.3% | 35/42 | 42 | 42 |  |
| 9 | `getproperty_swf4` | 82.1% | 23/28 | 28 | 28 |  |
| 10 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 11 | `movieclip_prototype_extension` | 80.0% | 4/5 | 5 | 5 |  |
| 12 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 13 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 14 | `stage_object_children` | 75.9% | 63/83 | 83 | 83 |  |
| 15 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 16 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 17 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 18 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 19 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 20 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 21 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 22 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 23 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 24 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 25 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 26 | `get_variable_in_scope` | 69.0% | 20/29 | 29 | 29 |  |
| 27 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 28 | `object_string_coerce_swf6` | 67.6% | 46/68 | 65 | 68 |  |
| 29 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 30 | `primitive_instanceof` | 67.6% | 25/37 | 37 | 37 |  |
| 31 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 32 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 33 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 34 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 35 | `goto_both_ways2` | 66.7% | 2/3 | 2 | 3 |  |
| 36 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 37 | `goto_rewind2` | 66.7% | 2/3 | 2 | 3 |  |
| 38 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 39 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 40 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 41 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 42 | `error` | 65.5% | 38/58 | 58 | 58 |  |
| 43 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 44 | `getproperty` | 64.3% | 18/28 | 28 | 28 |  |
| 45 | `getproperty_swf5` | 64.3% | 18/28 | 28 | 28 |  |
| 46 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 47 | `globals_swf6` | 64.1% | 195/304 | 304 | 304 |  |
| 48 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 49 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 50 | `with` | 63.3% | 31/49 | 47 | 49 |  |
| 51 | `globals_swf7` | 63.2% | 192/304 | 304 | 304 |  |
| 52 | `arguments` | 63.0% | 80/127 | 92 | 127 |  |
| 53 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 54 | `globals_swf5` | 61.8% | 188/304 | 304 | 304 |  |
| 55 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 56 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 57 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 58 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 59 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 60 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 61 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 62 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 63 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 64 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 65 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 66 | `swf6_case_insensitive` | 59.1% | 26/44 | 44 | 42 |  |
| 67 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 68 | `with_variable_scopes` | 58.1% | 25/43 | 43 | 43 |  |
| 69 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 70 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 71 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 72 | `primitive_type_globals` | 57.3% | 319/557 | 555 | 557 |  |
| 73 | `escape` | 57.1% | 8/14 | 14 | 14 |  |
| 74 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 75 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 76 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 77 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 78 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 79 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 80 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 81 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 82 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 83 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 84 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 85 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 86 | `movieclip_focusenabled` | 52.5% | 52/99 | 99 | 99 |  |
| 87 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 88 | `as_set_prop_flags_version` | 51.6% | 16/31 | 29 | 31 |  |
| 89 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 90 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 91 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 92 | `execution_order3` | 50.0% | 2/4 | 3 | 4 |  |
| 93 | `goto_advance2` | 50.0% | 1/2 | 1 | 2 |  |
| 94 | `goto_rewind3` | 50.0% | 1/2 | 1 | 2 |  |
| 95 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 96 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 97 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 98 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 99 | `prototype_delete` | 50.0% | 6/12 | 12 | 12 |  |
| 100 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 101 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 102 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 103 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 104 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 105 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 106 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 107 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 108 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 109 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 110 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 111 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 112 | `new_object_enumerate` | 42.9% | 3/7 | 7 | 7 |  |
| 113 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 114 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 115 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 116 | `globals_swf8` | 38.8% | 118/304 | 304 | 304 |  |
| 117 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 118 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 119 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 120 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 121 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 122 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 123 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 124 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 125 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 126 | `goto_both_ways1` | 33.3% | 1/3 | 1 | 3 |  |
| 127 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 128 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 129 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 130 | `define_function2_preload` | 30.8% | 4/13 | 12 | 13 |  |
| 131 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 132 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 133 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 134 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 135 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 136 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 137 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 138 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 139 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 140 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 141 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 142 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 143 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 144 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 145 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 146 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 147 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 148 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 149 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 150 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 151 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 152 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 153 | `unescape` | 20.9% | 9/43 | 42 | 43 |  |
| 154 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 155 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 156 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 157 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 158 | `frame_size_translated_negative` | 19.0% | 4/21 | 20 | 21 |  |
| 159 | `frame_size_translated_positive` | 19.0% | 4/21 | 20 | 21 |  |
| 160 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 161 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 162 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 163 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 164 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 165 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 166 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 167 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 168 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 169 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 170 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 171 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 172 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 173 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 174 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 175 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 176 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 177 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 178 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 179 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 180 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 181 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 182 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 183 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 184 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 185 | `string_paths_other` | 11.1% | 4/36 | 28 | 36 |  |
| 186 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 187 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 188 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 189 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 190 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 191 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 192 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 193 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 194 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 195 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 196 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 197 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 198 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 199 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 200 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 201 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 202 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 203 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 204 | `funky_function_calls` | 5.4% | 3/56 | 12 | 56 |  |
| 205 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 206 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 207 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 208 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 209 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 210 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 211 | `register_class` | 4.5% | 3/66 | 27 | 66 |  |
| 212 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 213 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 214 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 215 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 216 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 217 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 218 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 219 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 220 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 221 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 222 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 223 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 224 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 225 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 226 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 227 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 228 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 229 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 230 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 231 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 232 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 233 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 234 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 235 | `array_sort_random` | 0.0% | 0/443 | 1 | 443 |  |
| 236 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 237 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 238 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 1 | 40 |  |
| 239 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 240 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 241 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 242 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 243 | `asfunction` | 0.0% | 0/11 | 1 | 11 |  |
| 244 | `asnew` | 0.0% | 0/34 | 1 | 34 |  |
| 245 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 1 | 2 |  |
| 246 | `bad_swf_tag_past_eof` | 0.0% | 0/1 | 1 | 0 |  |
| 247 | `bitmap_data_colortransform` | 0.0% | 0/1 | 1 | 0 |  |
| 248 | `bitmap_data_fillrect` | 0.0% | 0/1 | 1 | 0 |  |
| 249 | `bitmap_data_perlinnoise` | 0.0% | 0/1 | 1 | 0 |  |
| 250 | `bitmap_data_pixeldissolve_image` | 0.0% | 0/1 | 1 | 0 |  |
| 251 | `bitmapdata_applyfilter_colormatrix` | 0.0% | 0/1 | 1 | 0 |  |
| 252 | `boxed_primitives` | 0.0% | 0/24 | 1 | 24 |  |
| 253 | `button_children` | 0.0% | 0/8 | 1 | 8 |  |
| 254 | `button_goto` | 0.0% | 0/4 | 1 | 4 |  |
| 255 | `button_order` | 0.0% | 0/2 | 1 | 2 |  |
| 256 | `button_properties_special_cases` | 0.0% | 0/22 | 1 | 22 |  |
| 257 | `button_v5` | 0.0% | 0/18 | 1 | 18 |  |
| 258 | `button_v6` | 0.0% | 0/18 | 1 | 18 |  |
| 259 | `call` | 0.0% | 0/63 | 1 | 63 |  |
| 260 | `call_method_empty_name` | 0.0% | 0/1 | 1 | 1 |  |
| 261 | `clip_constructors` | 0.0% | 0/8 | 1 | 8 |  |
| 262 | `clip_event_propagation_order` | 0.0% | 0/17 | 1 | 17 |  |
| 263 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 264 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 265 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 266 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 1 | 129 |  |
| 267 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 1 | 17 |  |
| 268 | `color` | 0.0% | 0/57 | 1 | 57 |  |
| 269 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 270 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 271 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 272 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 273 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 274 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 275 | `duplicate_movie_clip` | 0.0% | 0/20 | 1 | 20 |  |
| 276 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 277 | `edittext_html_roundtrip` | 0.0% | 0/17 | 1 | 17 |  |
| 278 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 279 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 280 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 281 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 282 | `extends_native_type` | 0.0% | 0/11 | 1 | 11 |  |
| 283 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 284 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 285 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 286 | `file_reference_browse_cancel` | 0.0% | 0/21 | 1 | 21 |  |
| 287 | `function_base_clip` | 0.0% | 0/8 | 1 | 8 |  |
| 288 | `function_base_clip_readded` | 0.0% | 0/11 | 1 | 11 |  |
| 289 | `function_suppress_and_preload` | 0.0% | 0/28 | 1 | 28 |  |
| 290 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 291 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 292 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 293 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 294 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 295 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 1 | 1145 |  |
| 296 | `global_swf6_7_8` | 0.0% | 0/15 | 1 | 15 |  |
| 297 | `goto_execution_order2` | 0.0% | 0/2 | 1 | 2 |  |
| 298 | `goto_frame` | 0.0% | 0/12 | 1 | 12 |  |
| 299 | `goto_frame2` | 0.0% | 0/44 | 1 | 44 |  |
| 300 | `goto_label` | 0.0% | 0/17 | 1 | 17 |  |
| 301 | `goto_methods` | 0.0% | 0/40 | 1 | 40 |  |
| 302 | `hittest_lockroot` | 0.0% | 0/15 | 1 | 15 |  |
| 303 | `hittest_morph` | 0.0% | 0/70 | 1 | 70 |  |
| 304 | `hittest_morph_input` | 0.0% | 0/1 | 1 | 1 |  |
| 305 | `hittest_winding_rule` | 0.0% | 0/12 | 1 | 12 |  |
| 306 | `init_array_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 307 | `init_object_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 308 | `init_object_order` | 0.0% | 0/15 | 1 | 15 |  |
| 309 | `input_dead_keys_windows` | 0.0% | 0/15 | 1 | 15 |  |
| 310 | `instanceof_coercions` | 0.0% | 0/88 | 1 | 88 |  |
| 311 | `interface_implements_op` | 0.0% | 0/47 | 1 | 47 |  |
| 312 | `issue_1104` | 0.0% | 0/2 | 1 | 2 |  |
| 313 | `issue_1671` | 0.0% | 0/1 | 1 | 0 |  |
| 314 | `issue_2084` | 0.0% | 0/16 | 1 | 16 |  |
| 315 | `issue_2870` | 0.0% | 0/3 | 1 | 3 |  |
| 316 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 317 | `issue_9327` | 0.0% | 0/2 | 1 | 2 |  |
| 318 | `issue_9885` | 0.0% | 0/2 | 1 | 2 |  |
| 319 | `localconnection` | 0.0% | 0/579 | 1 | 579 |  |
| 320 | `lock_root` | 0.0% | 0/1 | 1 | 1 |  |
| 321 | `mask_reapply` | 0.0% | 0/1 | 1 | 0 |  |
| 322 | `mask_with_drawing` | 0.0% | 0/1 | 1 | 0 |  |
| 323 | `movieclip_begin_gradient_fill` | 0.0% | 0/1 | 1 | 0 |  |
| 324 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 1 | 35 |  |
| 325 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 326 | `movieclip_gettextsnapshot` | 0.0% | 0/112 | 21 | 112 |  |
| 327 | `movieclip_in_removed_button` | 0.0% | 0/4 | 1 | 4 |  |
| 328 | `movieclip_init_object` | 0.0% | 0/5 | 1 | 5 |  |
| 329 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 330 | `movieclip_line_gradient_style` | 0.0% | 0/1 | 1 | 0 |  |
| 331 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 1 | 4 |  |
| 332 | `named_shapes` | 0.0% | 0/14 | 1 | 14 |  |
| 333 | `native_double_construct` | 0.0% | 0/12 | 1 | 12 |  |
| 334 | `native_objects_swf6` | 0.0% | 0/84 | 1 | 84 |  |
| 335 | `native_objects_swf7` | 0.0% | 0/84 | 1 | 84 |  |
| 336 | `native_objects_swf8` | 0.0% | 0/84 | 1 | 84 |  |
| 337 | `native_subclasses` | 0.0% | 0/191 | 1 | 191 |  |
| 338 | `nested_textfields_in_buttons` | 0.0% | 0/1 | 1 | 0 |  |
| 339 | `netconnection_send_remote` | 0.0% | 0/50 | 1 | 50 |  |
| 340 | `new_method_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 341 | `new_object_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 342 | `object_properties` | 0.0% | 0/31 | 1 | 31 |  |
| 343 | `object_resolve` | 0.0% | 0/38 | 1 | 38 |  |
| 344 | `on_construct` | 0.0% | 0/25 | 1 | 25 |  |
| 345 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 346 | `place_and_lookup` | 0.0% | 0/30 | 1 | 30 |  |
| 347 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 348 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 0 |  |
| 349 | `register_class_return_value` | 0.0% | 0/16 | 1 | 16 |  |
| 350 | `register_class_swf6` | 0.0% | 0/37 | 1 | 37 |  |
| 351 | `register_class_with_sound` | 0.0% | 0/11 | 1 | 11 |  |
| 352 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 353 | `removed_target_clip_scope` | 0.0% | 0/35 | 1 | 35 |  |
| 354 | `resolve_different_root` | 0.0% | 0/2 | 1 | 2 |  |
| 355 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 356 | `root_onload` | 0.0% | 0/1 | 1 | 1 |  |
| 357 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 358 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 359 | `selection` | 0.0% | 0/454 | 1 | 454 |  |
| 360 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 361 | `slash_syntax` | 0.0% | 0/14 | 1 | 14 |  |
| 362 | `stage_object_enumerate` | 0.0% | 0/4 | 1 | 4 |  |
| 363 | `string_methods_negative_args` | 0.0% | 0/240 | 1 | 240 |  |
| 364 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 365 | `string_paths_eval` | 0.0% | 0/4 | 1 | 4 |  |
| 366 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 367 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 368 | `string_paths_timer` | 0.0% | 0/1 | 1 | 0 |  |
| 369 | `string_paths_unload` | 0.0% | 0/1 | 1 | 1 |  |
| 370 | `string_paths_variable_scopes` | 0.0% | 0/5 | 1 | 5 |  |
| 371 | `stylesheet` | 0.0% | 0/283 | 1 | 283 |  |
| 372 | `super_edge_cases` | 0.0% | 0/39 | 1 | 39 |  |
| 373 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 374 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 375 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 376 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 377 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 378 | `target_clip_swf5` | 0.0% | 0/2 | 1 | 2 |  |
| 379 | `target_clip_swf6` | 0.0% | 0/2 | 1 | 2 |  |
| 380 | `target_path` | 0.0% | 0/14 | 1 | 14 |  |
| 381 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 382 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 383 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 384 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 |  |
| 385 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 386 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 387 | `timer_run_actions` | 0.0% | 0/18 | 1 | 18 |  |
| 388 | `typeof` | 0.0% | 0/22 | 1 | 22 |  |
| 389 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 390 | `unload_clip_event` | 0.0% | 0/4 | 1 | 4 |  |
| 391 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 392 | `use_hand_cursor` | 0.0% | 0/8 | 1 | 8 |  |
| 393 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 394 | `watch` | 0.0% | 0/117 | 1 | 117 |  |
| 395 | `watch_textfield` | 0.0% | 0/12 | 1 | 12 |  |
| 396 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 |  |
| 397 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 398 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 399 | `xml_ignore_comments` | 0.0% | 0/21 | 1 | 21 |  |
| 400 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 401 | `xml_reparenting` | 0.0% | 0/14 | 1 | 14 |  |
| 402 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 403 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 404 | `xml_unescaping` | 0.0% | 0/23 | 1 | 23 |  |
| 405 | `xmlnode_proto` | 0.0% | 0/1 | 1 | 1 |  |
