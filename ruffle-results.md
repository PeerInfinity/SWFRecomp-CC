# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-12 20:38 UTC

**Git SHA**: `0f4ca778db`

**Run Duration**: 28m 43s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 616 |
| Passing | **72** (11.7%) |
| Failing | 544 |
| Total expected lines | 89196 |
| Matching lines | 32349 (36.3%) |
| Mismatched lines | 56847 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 528 | 97.1% |
| Runtime Segfault | 9 | 1.7% |
| Timeout | 4 | 0.7% |
| Runtime Error | 2 | 0.4% |
| Compile Fail | 1 | 0.2% |

## Passing Tests

**72 tests passing**

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
| 42 | `infinite_recursion_function` | 4 | 2.2s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 43 | `infinite_recursion_function_in_setter` | 131 | 2.2s |  |
| 44 | `infinite_recursion_virtual_property` | 67 | 2.2s |  |
| 45 | `issue_1086` | 1 | 2.1s |  |
| 46 | `issue_3446` | 1 | 2.2s |  |
| 47 | `issue_4377` | 2 | 2.2s |  |
| 48 | `issue_768` | 3 | 2.2s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 49 | `lessthan` | 41 | 2.3s |  |
| 50 | `lessthan2_swf5` | 1226 | 11.9s |  |
| 51 | `lessthan2_swf6` | 1226 | 11.9s |  |
| 52 | `lessthan2_swf7` | 1226 | 11.9s |  |
| 53 | `lessthan_swf4` | 902 | 7.7s |  |
| 54 | `lessthan_swf4_alt` | 41 | 2.2s |  |
| 55 | `lessthan_swf5` | 41 | 2.3s |  |
| 56 | `logical_ops_swf4` | 90 | 2.3s |  |
| 57 | `logical_ops_swf8` | 108 | 2.3s |  |
| 58 | `looping` | 6 | 2.2s |  |
| 59 | `object_function` | 32 | 2.2s |  |
| 60 | `sandbox_type_local_file` | 1 | 2.2s |  |
| 61 | `single_frame` | 1 | 2.1s |  |
| 62 | `strictequals_swf6` | 902 | 9.1s |  |
| 63 | `strictly_equals` | 7 | 2.3s |  |
| 64 | `swf4_actions_bool` | 96 | 2.4s |  |
| 65 | `swf4_bool` | 4 | 2.3s |  |
| 66 | `swf5_encoding` | 3 | 2.3s |  |
| 67 | `this_swf7` | 41 | 2.2s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 68 | `timeline_function_def` | 7 | 2.2s |  |
| 69 | `try_finally_simple` | 16 | 2.1s |  |
| 70 | `typeof_globals` | 7 | 2.1s |  |
| 71 | `undefined_to_string_swf6` | 4 | 2.0s |  |
| 72 | `with_return` | 2 | 2.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**111 tests** within reach

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
| 15 | `bitmap_data_max_size_swf10` | 75.0% | 9 | 12 | 3 |  |
| 16 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 17 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 18 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 19 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 20 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 21 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 22 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 23 | `point` | 70.9% | 124 | 175 | 51 |  |
| 24 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 25 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 26 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 27 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 28 | `get_variable_in_scope` | 69.0% | 20 | 29 | 9 |  |
| 29 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 30 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 31 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 32 | `primitive_instanceof` | 67.6% | 25 | 37 | 12 |  |
| 33 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 34 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 35 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 36 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 37 | `goto_both_ways2` | 66.7% | 2 | 3 | 1 |  |
| 38 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 39 | `goto_rewind2` | 66.7% | 2 | 3 | 1 |  |
| 40 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 41 | `o` | 66.7% | 2 | 3 | 1 |  |
| 42 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 43 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 44 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 45 | `error` | 65.5% | 38 | 58 | 20 |  |
| 46 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 47 | `getproperty` | 64.3% | 18 | 28 | 10 |  |
| 48 | `getproperty_swf5` | 64.3% | 18 | 28 | 10 |  |
| 49 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 50 | `globals_swf6` | 64.1% | 195 | 304 | 109 |  |
| 51 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 52 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 53 | `with` | 63.3% | 31 | 49 | 18 |  |
| 54 | `globals_swf7` | 63.2% | 192 | 304 | 112 |  |
| 55 | `arguments` | 63.0% | 80 | 127 | 47 |  |
| 56 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 57 | `globals_swf5` | 61.8% | 188 | 304 | 116 |  |
| 58 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 59 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 60 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 61 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 62 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 63 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 64 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 65 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 66 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 67 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 68 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 69 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 70 | `swf6_case_insensitive` | 59.1% | 26 | 44 | 18 |  |
| 71 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 72 | `with_variable_scopes` | 58.1% | 25 | 43 | 18 |  |
| 73 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 74 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 75 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 76 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 77 | `primitive_type_globals` | 57.3% | 319 | 557 | 238 |  |
| 78 | `escape` | 57.1% | 8 | 14 | 6 |  |
| 79 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 80 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 81 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 82 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 83 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 84 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 85 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 86 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 87 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 88 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 89 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 90 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 91 | `movieclip_focusenabled` | 52.5% | 52 | 99 | 47 |  |
| 92 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 93 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 94 | `as_set_prop_flags_version` | 51.6% | 16 | 31 | 15 |  |
| 95 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 96 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 97 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 98 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 99 | `goto_advance2` | 50.0% | 1 | 2 | 1 |  |
| 100 | `goto_rewind3` | 50.0% | 1 | 2 | 1 |  |
| 101 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 102 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 103 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 104 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 105 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 106 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 107 | `prototype_delete` | 50.0% | 6 | 12 | 6 |  |
| 108 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 109 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 110 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 111 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**9 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `as2_oop` | 4.5s |  |
| 2 | `device_font_spacing` | 11.5s |  |
| 3 | `duplicate_movie_clip_drawing` | 4.2s |  |
| 4 | `enumerate` | 3.8s |  |
| 5 | `extends_chain` | 4.2s |  |
| 6 | `issue_2166` | 4.3s |  |
| 7 | `netstream_play_flv_screen` | 31.1s |  |
| 8 | `path_string` | 4.7s |  |
| 9 | `swf4_actions_coercion_order` | 4.7s |  |

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

**528 tests** with output mismatch, sorted by match rate (best first)

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
| 15 | `bitmap_data_max_size_swf10` | 75.0% | 9/12 | 12 | 12 |  |
| 16 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 17 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 18 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 19 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 20 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 21 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 22 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 23 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 24 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 25 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 26 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 27 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 28 | `get_variable_in_scope` | 69.0% | 20/29 | 29 | 29 |  |
| 29 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 30 | `object_string_coerce_swf6` | 67.6% | 46/68 | 65 | 68 |  |
| 31 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 32 | `primitive_instanceof` | 67.6% | 25/37 | 37 | 37 |  |
| 33 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 34 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 35 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 36 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 37 | `goto_both_ways2` | 66.7% | 2/3 | 2 | 3 |  |
| 38 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 39 | `goto_rewind2` | 66.7% | 2/3 | 2 | 3 |  |
| 40 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 41 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 42 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 43 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 44 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 45 | `error` | 65.5% | 38/58 | 58 | 58 |  |
| 46 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 47 | `getproperty` | 64.3% | 18/28 | 28 | 28 |  |
| 48 | `getproperty_swf5` | 64.3% | 18/28 | 28 | 28 |  |
| 49 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 50 | `globals_swf6` | 64.1% | 195/304 | 304 | 304 |  |
| 51 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 52 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 53 | `with` | 63.3% | 31/49 | 47 | 49 |  |
| 54 | `globals_swf7` | 63.2% | 192/304 | 304 | 304 |  |
| 55 | `arguments` | 63.0% | 80/127 | 92 | 127 |  |
| 56 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 57 | `globals_swf5` | 61.8% | 188/304 | 304 | 304 |  |
| 58 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 59 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 60 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 61 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 62 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 63 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 64 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 65 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 66 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 67 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 68 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 69 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 70 | `swf6_case_insensitive` | 59.1% | 26/44 | 44 | 42 |  |
| 71 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 72 | `with_variable_scopes` | 58.1% | 25/43 | 43 | 43 |  |
| 73 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 74 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 75 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 76 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 77 | `primitive_type_globals` | 57.3% | 319/557 | 555 | 557 |  |
| 78 | `escape` | 57.1% | 8/14 | 14 | 14 |  |
| 79 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 80 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 81 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 82 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 83 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 84 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 85 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 86 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 87 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 88 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 89 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 90 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 91 | `movieclip_focusenabled` | 52.5% | 52/99 | 99 | 99 |  |
| 92 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 93 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 94 | `as_set_prop_flags_version` | 51.6% | 16/31 | 29 | 31 |  |
| 95 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 96 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 97 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 98 | `execution_order3` | 50.0% | 2/4 | 3 | 4 |  |
| 99 | `goto_advance2` | 50.0% | 1/2 | 1 | 2 |  |
| 100 | `goto_rewind3` | 50.0% | 1/2 | 1 | 2 |  |
| 101 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 102 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 103 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 104 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 105 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 106 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 107 | `prototype_delete` | 50.0% | 6/12 | 12 | 12 |  |
| 108 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 109 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 110 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 111 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 112 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 113 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 114 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 115 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 116 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 117 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 118 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 119 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 120 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 121 | `new_object_enumerate` | 42.9% | 3/7 | 7 | 7 |  |
| 122 | `sound_props_swf6` | 41.2% | 28/68 | 68 | 68 |  |
| 123 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 124 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 125 | `sound_props_swf5` | 39.7% | 27/68 | 67 | 68 |  |
| 126 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 127 | `globals_swf8` | 38.8% | 118/304 | 304 | 304 |  |
| 128 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 129 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 130 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 131 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 132 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 133 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 134 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 135 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 136 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 137 | `goto_both_ways1` | 33.3% | 1/3 | 1 | 3 |  |
| 138 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 139 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 140 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 141 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 142 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 143 | `define_function2_preload` | 30.8% | 4/13 | 12 | 13 |  |
| 144 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 145 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 146 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 147 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 148 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 149 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 150 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 151 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 152 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 153 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 154 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 155 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 156 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 157 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 158 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 159 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 160 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 161 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 162 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 163 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 164 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 165 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 166 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 167 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 168 | `unescape` | 20.9% | 9/43 | 42 | 43 |  |
| 169 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 170 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 171 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 172 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 173 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 174 | `frame_size_translated_negative` | 19.0% | 4/21 | 20 | 21 |  |
| 175 | `frame_size_translated_positive` | 19.0% | 4/21 | 20 | 21 |  |
| 176 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 177 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 178 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 179 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 180 | `focusrect_swf5` | 16.7% | 1/6 | 1 | 6 |  |
| 181 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 182 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 183 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 184 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 185 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 186 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 187 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 188 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 189 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 190 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 191 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 192 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 193 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 194 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 195 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 196 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 197 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 198 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 199 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 200 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 201 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 202 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 203 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 204 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 205 | `string_paths_other` | 11.1% | 4/36 | 28 | 36 |  |
| 206 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 207 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 208 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 209 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 210 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 211 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 212 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 213 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 214 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 215 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 216 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 217 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 218 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 219 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 220 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 221 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 222 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 223 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 224 | `funky_function_calls` | 5.4% | 3/56 | 12 | 56 |  |
| 225 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 226 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 227 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 228 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 229 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 230 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 231 | `register_class` | 4.5% | 3/66 | 27 | 66 |  |
| 232 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 233 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 234 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 235 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 236 | `bitmap_data` | 4.1% | 46/1126 | 318 | 1126 |  |
| 237 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 238 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 239 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 240 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 241 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 242 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 243 | `tab_ordering_properties` | 2.7% | 8/293 | 180 | 293 |  |
| 244 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 245 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 246 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 247 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 248 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 249 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 250 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 251 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 252 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 253 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 254 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 255 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 256 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 257 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 258 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 259 | `tab_ordering_events` | 0.7% | 1/150 | 12 | 150 |  |
| 260 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 261 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 262 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 263 | `focusrect_property_swf5` | 0.3% | 4/1241 | 1241 | 1237 |  |
| 264 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 265 | `focusrect_property_swf6` | 0.2% | 2/1241 | 1241 | 1237 |  |
| 266 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 267 | `focusrect_property_swf7` | 0.1% | 1/1241 | 1241 | 1237 |  |
| 268 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 269 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 270 | `array_sort_random` | 0.0% | 0/443 | 1 | 443 |  |
| 271 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 272 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 273 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 1 | 40 |  |
| 274 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 275 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 276 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 277 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 278 | `asfunction` | 0.0% | 0/11 | 1 | 11 |  |
| 279 | `asnew` | 0.0% | 0/34 | 1 | 34 |  |
| 280 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 1 | 2 |  |
| 281 | `bad_swf_tag_past_eof` | 0.0% | 0/1 | 1 | 0 |  |
| 282 | `bitmap_data_colortransform` | 0.0% | 0/1 | 1 | 0 |  |
| 283 | `bitmap_data_copypixels` | 0.0% | 0/17 | 1 | 17 |  |
| 284 | `bitmap_data_fillrect` | 0.0% | 0/1 | 1 | 0 |  |
| 285 | `bitmap_data_perlinnoise` | 0.0% | 0/1 | 1 | 0 |  |
| 286 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 1 | 1075 |  |
| 287 | `bitmap_data_pixeldissolve_image` | 0.0% | 0/1 | 1 | 0 |  |
| 288 | `bitmap_filters` | 0.0% | 0/548 | 1 | 548 |  |
| 289 | `bitmapdata_applyfilter_colormatrix` | 0.0% | 0/1 | 1 | 0 |  |
| 290 | `boxed_primitives` | 0.0% | 0/24 | 1 | 24 |  |
| 291 | `button_children` | 0.0% | 0/8 | 1 | 8 |  |
| 292 | `button_goto` | 0.0% | 0/4 | 1 | 4 |  |
| 293 | `button_key_events` | 0.0% | 0/14 | 1 | 14 |  |
| 294 | `button_key_events_special` | 0.0% | 0/45 | 1 | 45 |  |
| 295 | `button_keypress` | 0.0% | 0/3 | 1 | 3 |  |
| 296 | `button_keypress_vs_press` | 0.0% | 0/25 | 1 | 25 |  |
| 297 | `button_keypress_vs_tab` | 0.0% | 0/20 | 1 | 20 |  |
| 298 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 1 | 4 |  |
| 299 | `button_order` | 0.0% | 0/2 | 1 | 2 |  |
| 300 | `button_properties_special_cases` | 0.0% | 0/22 | 1 | 22 |  |
| 301 | `button_v5` | 0.0% | 0/18 | 1 | 18 |  |
| 302 | `button_v6` | 0.0% | 0/18 | 1 | 18 |  |
| 303 | `call` | 0.0% | 0/63 | 1 | 63 |  |
| 304 | `call_method_empty_name` | 0.0% | 0/1 | 1 | 1 |  |
| 305 | `click_block` | 0.0% | 0/5 | 1 | 5 |  |
| 306 | `clip_constructors` | 0.0% | 0/8 | 1 | 8 |  |
| 307 | `clip_event_propagation_order` | 0.0% | 0/17 | 1 | 17 |  |
| 308 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 309 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 310 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 311 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 1 | 129 |  |
| 312 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 1 | 17 |  |
| 313 | `color` | 0.0% | 0/57 | 1 | 57 |  |
| 314 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 315 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 316 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 317 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 318 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 319 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 320 | `drag_drop` | 0.0% | 0/10 | 1 | 10 |  |
| 321 | `drag_over_from_outside` | 0.0% | 0/1 | 1 | 1 |  |
| 322 | `drag_over_without_startdrag` | 0.0% | 0/1 | 1 | 1 |  |
| 323 | `duplicate_movie_clip` | 0.0% | 0/20 | 1 | 20 |  |
| 324 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 325 | `edittext_drag_select` | 0.0% | 0/9 | 1 | 9 |  |
| 326 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 327 | `edittext_html_roundtrip` | 0.0% | 0/17 | 1 | 17 |  |
| 328 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 1 | 7 |  |
| 329 | `edittext_input` | 0.0% | 0/1 | 1 | 1 |  |
| 330 | `edittext_input_newlines` | 0.0% | 0/9 | 1 | 9 |  |
| 331 | `edittext_password` | 0.0% | 0/5 | 1 | 5 |  |
| 332 | `edittext_password_copy` | 0.0% | 0/4 | 1 | 4 |  |
| 333 | `edittext_paste_empty` | 0.0% | 0/2 | 1 | 2 |  |
| 334 | `edittext_place_caret` | 0.0% | 0/2 | 1 | 2 |  |
| 335 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 336 | `edittext_restrict` | 0.0% | 0/191 | 1 | 191 |  |
| 337 | `edittext_restrict_paste` | 0.0% | 0/5 | 1 | 5 |  |
| 338 | `edittext_tab_focus` | 0.0% | 0/13 | 1 | 13 |  |
| 339 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 340 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 341 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 342 | `extends_native_type` | 0.0% | 0/11 | 1 | 11 |  |
| 343 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 344 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 345 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 346 | `file_reference_browse_cancel` | 0.0% | 0/21 | 1 | 21 |  |
| 347 | `focus_keyboard_press` | 0.0% | 0/60 | 1 | 60 |  |
| 348 | `focus_mouse` | 0.0% | 0/45 | 1 | 45 |  |
| 349 | `focus_mouse_focusable` | 0.0% | 0/8 | 1 | 8 |  |
| 350 | `focus_mouse_rollout` | 0.0% | 0/4 | 1 | 4 |  |
| 351 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 352 | `focusrect_focuslost` | 0.0% | 0/4 | 1 | 4 |  |
| 353 | `focusrect_mouse_swf8` | 0.0% | 0/1 | 1 | 0 |  |
| 354 | `focusrect_mouse_swf9` | 0.0% | 0/1 | 1 | 0 |  |
| 355 | `focusrect_swf6` | 0.0% | 0/42 | 1 | 42 |  |
| 356 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 357 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 358 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 359 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 360 | `function_base_clip` | 0.0% | 0/8 | 1 | 8 |  |
| 361 | `function_base_clip_readded` | 0.0% | 0/11 | 1 | 11 |  |
| 362 | `function_suppress_and_preload` | 0.0% | 0/28 | 1 | 28 |  |
| 363 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 364 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 365 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 366 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 367 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 368 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 1 | 1145 |  |
| 369 | `global_swf6_7_8` | 0.0% | 0/15 | 1 | 15 |  |
| 370 | `goto_execution_order2` | 0.0% | 0/2 | 1 | 2 |  |
| 371 | `goto_frame` | 0.0% | 0/12 | 1 | 12 |  |
| 372 | `goto_frame2` | 0.0% | 0/44 | 1 | 44 |  |
| 373 | `goto_label` | 0.0% | 0/17 | 1 | 17 |  |
| 374 | `goto_methods` | 0.0% | 0/40 | 1 | 40 |  |
| 375 | `hittest_lockroot` | 0.0% | 0/15 | 1 | 15 |  |
| 376 | `hittest_morph` | 0.0% | 0/70 | 1 | 70 |  |
| 377 | `hittest_morph_input` | 0.0% | 0/1 | 1 | 1 |  |
| 378 | `hittest_winding_rule` | 0.0% | 0/12 | 1 | 12 |  |
| 379 | `init_array_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 380 | `init_object_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 381 | `init_object_order` | 0.0% | 0/15 | 1 | 15 |  |
| 382 | `input_dead_keys_windows` | 0.0% | 0/15 | 1 | 15 |  |
| 383 | `instanceof_coercions` | 0.0% | 0/88 | 1 | 88 |  |
| 384 | `interface_implements_op` | 0.0% | 0/47 | 1 | 47 |  |
| 385 | `issue_1104` | 0.0% | 0/2 | 1 | 2 |  |
| 386 | `issue_1671` | 0.0% | 0/1 | 1 | 0 |  |
| 387 | `issue_2084` | 0.0% | 0/16 | 1 | 16 |  |
| 388 | `issue_2870` | 0.0% | 0/3 | 1 | 3 |  |
| 389 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 390 | `issue_9327` | 0.0% | 0/2 | 1 | 2 |  |
| 391 | `issue_9885` | 0.0% | 0/2 | 1 | 2 |  |
| 392 | `key_isToggled` | 0.0% | 0/9 | 1 | 9 |  |
| 393 | `loadmovie_fail` | 0.0% | 0/2 | 1 | 2 |  |
| 394 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 395 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 396 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 1 | 9 |  |
| 397 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 398 | `loadvariables_method` | 0.0% | 0/7 | 1 | 7 |  |
| 399 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 400 | `localconnection` | 0.0% | 0/579 | 1 | 579 |  |
| 401 | `lock_root` | 0.0% | 0/1 | 1 | 1 |  |
| 402 | `mask_reapply` | 0.0% | 0/1 | 1 | 0 |  |
| 403 | `mask_with_drawing` | 0.0% | 0/1 | 1 | 0 |  |
| 404 | `mcl_as_broadcaster` | 0.0% | 0/12 | 1 | 12 |  |
| 405 | `mcl_events_swf_version` | 0.0% | 0/232 | 1 | 232 |  |
| 406 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 407 | `mcl_loadclip_properties` | 0.0% | 0/6 | 1 | 6 |  |
| 408 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 1 | 1 |  |
| 409 | `mcl_mislabeled_target` | 0.0% | 0/6 | 1 | 6 |  |
| 410 | `mcl_target_gif87a` | 0.0% | 0/6 | 1 | 6 |  |
| 411 | `mcl_target_gif89a` | 0.0% | 0/6 | 1 | 6 |  |
| 412 | `mcl_target_jpg` | 0.0% | 0/6 | 1 | 6 |  |
| 413 | `mcl_target_png` | 0.0% | 0/6 | 1 | 6 |  |
| 414 | `mcl_unloadclip` | 0.0% | 0/5 | 1 | 5 |  |
| 415 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 1 | 2 |  |
| 416 | `mouse_events` | 0.0% | 0/8 | 1 | 8 |  |
| 417 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 1 | 12 |  |
| 418 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 1 | 1 |  |
| 419 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 420 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 421 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 422 | `movieclip_begin_gradient_fill` | 0.0% | 0/1 | 1 | 0 |  |
| 423 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 1 | 35 |  |
| 424 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 425 | `movieclip_gettextsnapshot` | 0.0% | 0/112 | 21 | 112 |  |
| 426 | `movieclip_in_removed_button` | 0.0% | 0/4 | 1 | 4 |  |
| 427 | `movieclip_init_object` | 0.0% | 0/5 | 1 | 5 |  |
| 428 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 429 | `movieclip_line_gradient_style` | 0.0% | 0/1 | 1 | 0 |  |
| 430 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 1 | 4 |  |
| 431 | `named_shapes` | 0.0% | 0/14 | 1 | 14 |  |
| 432 | `native_double_construct` | 0.0% | 0/12 | 1 | 12 |  |
| 433 | `native_objects_swf6` | 0.0% | 0/84 | 1 | 84 |  |
| 434 | `native_objects_swf7` | 0.0% | 0/84 | 1 | 84 |  |
| 435 | `native_objects_swf8` | 0.0% | 0/84 | 1 | 84 |  |
| 436 | `native_subclasses` | 0.0% | 0/191 | 1 | 191 |  |
| 437 | `nested_textfields_in_buttons` | 0.0% | 0/1 | 1 | 0 |  |
| 438 | `netconnection_send_remote` | 0.0% | 0/50 | 1 | 50 |  |
| 439 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 440 | `netstream_seek_flv` | 0.0% | 0/25 | 1 | 25 |  |
| 441 | `new_method_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 442 | `new_object_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 443 | `object_properties` | 0.0% | 0/31 | 1 | 31 |  |
| 444 | `object_resolve` | 0.0% | 0/38 | 1 | 38 |  |
| 445 | `on_construct` | 0.0% | 0/25 | 1 | 25 |  |
| 446 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 447 | `place_and_lookup` | 0.0% | 0/30 | 1 | 30 |  |
| 448 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 449 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 0 |  |
| 450 | `register_class_return_value` | 0.0% | 0/16 | 1 | 16 |  |
| 451 | `register_class_swf6` | 0.0% | 0/37 | 1 | 37 |  |
| 452 | `register_class_with_sound` | 0.0% | 0/11 | 1 | 11 |  |
| 453 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 454 | `removed_target_clip_scope` | 0.0% | 0/35 | 1 | 35 |  |
| 455 | `resolve_different_root` | 0.0% | 0/2 | 1 | 2 |  |
| 456 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 457 | `root_onload` | 0.0% | 0/1 | 1 | 1 |  |
| 458 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 459 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 460 | `selection` | 0.0% | 0/454 | 1 | 454 |  |
| 461 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 462 | `slash_syntax` | 0.0% | 0/14 | 1 | 14 |  |
| 463 | `sound_load_start` | 0.0% | 0/3 | 1 | 3 |  |
| 464 | `sound_multiple_load` | 0.0% | 0/1 | 1 | 1 |  |
| 465 | `sound_start_load` | 0.0% | 0/1 | 1 | 0 |  |
| 466 | `stage_object_enumerate` | 0.0% | 0/4 | 1 | 4 |  |
| 467 | `string_methods_negative_args` | 0.0% | 0/240 | 1 | 240 |  |
| 468 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 469 | `string_paths_eval` | 0.0% | 0/4 | 1 | 4 |  |
| 470 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 471 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 472 | `string_paths_timer` | 0.0% | 0/1 | 1 | 0 |  |
| 473 | `string_paths_unload` | 0.0% | 0/1 | 1 | 1 |  |
| 474 | `string_paths_variable_scopes` | 0.0% | 0/5 | 1 | 5 |  |
| 475 | `stylesheet` | 0.0% | 0/283 | 1 | 283 |  |
| 476 | `super_edge_cases` | 0.0% | 0/39 | 1 | 39 |  |
| 477 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 478 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 479 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 480 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 481 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 1 | 92 |  |
| 482 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 1 | 21 |  |
| 483 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 1 | 12 |  |
| 484 | `tab_ordering_children` | 0.0% | 0/208 | 1 | 208 |  |
| 485 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 1 | 71 |  |
| 486 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 1 | 22 |  |
| 487 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 1 | 12 |  |
| 488 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 1 | 29 |  |
| 489 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 1 | 65 |  |
| 490 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 1 | 462 |  |
| 491 | `tab_ordering_properties_tab_index_edge_case` | 0.0% | 0/4 | 4 | 4 |  |
| 492 | `tab_ordering_reverse` | 0.0% | 0/51 | 1 | 51 |  |
| 493 | `tab_ordering_tabbable` | 0.0% | 0/47 | 1 | 47 |  |
| 494 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 495 | `target_clip_swf5` | 0.0% | 0/2 | 1 | 2 |  |
| 496 | `target_clip_swf6` | 0.0% | 0/2 | 1 | 2 |  |
| 497 | `target_path` | 0.0% | 0/14 | 1 | 14 |  |
| 498 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 499 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 500 | `text_blocks_clicks` | 0.0% | 0/4 | 1 | 4 |  |
| 501 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 502 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 |  |
| 503 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 504 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 505 | `timer_run_actions` | 0.0% | 0/18 | 1 | 18 |  |
| 506 | `typeof` | 0.0% | 0/22 | 1 | 22 |  |
| 507 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 508 | `unload_clip_event` | 0.0% | 0/4 | 1 | 4 |  |
| 509 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 510 | `use_hand_cursor` | 0.0% | 0/8 | 1 | 8 |  |
| 511 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 512 | `watch` | 0.0% | 0/117 | 1 | 117 |  |
| 513 | `watch_textfield` | 0.0% | 0/12 | 1 | 12 |  |
| 514 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 |  |
| 515 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 516 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 517 | `xml_ignore_comments` | 0.0% | 0/21 | 1 | 21 |  |
| 518 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 519 | `xml_load` | 0.0% | 0/2 | 1 | 2 |  |
| 520 | `xml_reparenting` | 0.0% | 0/14 | 1 | 14 |  |
| 521 | `xml_socket` | 0.0% | 0/8 | 1 | 8 |  |
| 522 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 1 | 6 |  |
| 523 | `xml_socket_on_data` | 0.0% | 0/7 | 1 | 7 |  |
| 524 | `xml_socket_segmented` | 0.0% | 0/29 | 1 | 29 |  |
| 525 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 526 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 527 | `xml_unescaping` | 0.0% | 0/23 | 1 | 23 |  |
| 528 | `xmlnode_proto` | 0.0% | 0/1 | 1 | 1 |  |
