# Ruffle Test Results (Filtered)

**Date**: 2026-02-12 03:43 UTC

**Git SHA**: `a174c955cd`

**Run Duration**: 27m 1s

**Filtered**: 125 tests ignored out of 616 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 491 |
| Passing | **73** (14.9%) |
| Failing | 418 |
| Total expected lines | 76093 |
| Matching lines | 31652 (41.6%) |
| Mismatched lines | 44441 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 402 | 96.2% |
| Segfault | 9 | 2.2% |
| Timeout | 4 | 1.0% |
| Runtime Error | 3 | 0.7% |

## Passing Tests

**73 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.4s |  |
| 2 | `action_to_integer` | 28 | 2.1s |  |
| 3 | `add` | 28 | 2.1s |  |
| 4 | `add2` | 354 | 2.5s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.1s |  |
| 6 | `add_swf5` | 28 | 2.1s |  |
| 7 | `array_concat` | 98 | 2.3s |  |
| 8 | `array_slice` | 34 | 2.2s |  |
| 9 | `array_splice` | 207 | 2.9s |  |
| 10 | `array_trivial` | 209 | 2.6s |  |
| 11 | `as_broadcaster_initialize` | 10 | 2.1s |  |
| 12 | `as_set_prop_flags_version_swf5` | 1 | 2.1s |  |
| 13 | `bad_swf_tag_past_eof` | 1 | 2.0s |  |
| 14 | `bitand` | 1058 | 10.4s |  |
| 15 | `bitmap_data_colortransform` | 1 | 2.4s |  |
| 16 | `bitmap_data_fillrect` | 1 | 2.2s |  |
| 17 | `bitmap_data_perlinnoise` | 1 | 2.9s |  |
| 18 | `bitmap_data_pixeldissolve_image` | 1 | 2.6s |  |
| 19 | `bitmapdata_applyfilter_colormatrix` | 1 | 2.1s |  |
| 20 | `bitor` | 1058 | 10.4s |  |
| 21 | `biturshift` | 14 | 2.1s |  |
| 22 | `biturshift_swf8` | 14 | 2.0s |  |
| 23 | `bitxor` | 1058 | 11.1s |  |
| 24 | `catch_references_registers` | 2 | 2.0s |  |
| 25 | `define_function_case_sensitive` | 2 | 2.0s |  |
| 26 | `divide_swf4` | 107 | 2.2s |  |
| 27 | `do_init_action` | 3 | 2.0s |  |
| 28 | `equals` | 32 | 2.3s |  |
| 29 | `equals2_swf6` | 926 | 10.0s |  |
| 30 | `equals2_swf7` | 926 | 10.2s |  |
| 31 | `equals_swf4` | 665 | 5.8s |  |
| 32 | `equals_swf4_alt` | 32 | 2.1s |  |
| 33 | `equals_swf5` | 32 | 2.1s |  |
| 34 | `global_is_bare` | 7 | 2.1s |  |
| 35 | `goto_execution_order` | 2 | 2.0s |  |
| 36 | `goto_rewind1` | 1 | 2.1s |  |
| 37 | `greater_swf6` | 1175 | 10.9s |  |
| 38 | `greater_swf7` | 1175 | 10.9s |  |
| 39 | `greaterthan_swf5` | 1 | 2.0s |  |
| 40 | `greaterthan_swf8` | 1 | 2.0s |  |
| 41 | `infinite_recursion_function_in_setter` | 131 | 2.1s |  |
| 42 | `infinite_recursion_virtual_property` | 67 | 2.0s |  |
| 43 | `issue_1086` | 1 | 2.0s |  |
| 44 | `issue_1671` | 1 | 2.0s |  |
| 45 | `issue_3446` | 1 | 2.1s |  |
| 46 | `issue_4377` | 2 | 2.0s |  |
| 47 | `issue_768` | 3 | 2.0s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 48 | `lessthan` | 41 | 2.1s |  |
| 49 | `lessthan_swf4` | 902 | 7.3s |  |
| 50 | `lessthan_swf4_alt` | 41 | 2.1s |  |
| 51 | `lessthan_swf5` | 41 | 2.1s |  |
| 52 | `logical_ops_swf4` | 90 | 2.1s |  |
| 53 | `logical_ops_swf8` | 108 | 2.2s |  |
| 54 | `looping` | 6 | 2.0s |  |
| 55 | `mask_reapply` | 1 | 2.0s |  |
| 56 | `mask_with_drawing` | 1 | 2.0s |  |
| 57 | `movieclip_begin_gradient_fill` | 1 | 2.8s |  |
| 58 | `movieclip_line_gradient_style` | 1 | 2.7s |  |
| 59 | `nested_textfields_in_buttons` | 1 | 2.0s |  |
| 60 | `sandbox_type_local_file` | 1 | 2.0s |  |
| 61 | `single_frame` | 1 | 2.0s |  |
| 62 | `strictequals_swf6` | 902 | 8.3s |  |
| 63 | `strictly_equals` | 7 | 2.1s |  |
| 64 | `string_paths_keyevents` | 1 | 2.1s |  |
| 65 | `string_paths_timer` | 1 | 2.1s |  |
| 66 | `swf4_actions_bool` | 96 | 2.2s |  |
| 67 | `swf4_bool` | 4 | 2.0s |  |
| 68 | `swf5_encoding` | 3 | 2.3s |  |
| 69 | `timeline_function_def` | 7 | 2.4s |  |
| 70 | `try_finally_simple` | 16 | 2.0s |  |
| 71 | `typeof_globals` | 7 | 2.0s |  |
| 72 | `undefined_to_string_swf6` | 4 | 2.0s |  |
| 73 | `with_return` | 2 | 2.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**107 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `equals2_swf5` | 99.9% | 925 | 926 | 1 |  |
| 2 | `lessthan2_swf5` | 97.5% | 1197 | 1228 | 31 |  |
| 3 | `lessthan2_swf6` | 97.5% | 1197 | 1228 | 31 |  |
| 4 | `lessthan2_swf7` | 97.5% | 1197 | 1228 | 31 |  |
| 5 | `object_string_coerce_swf5` | 95.4% | 62 | 65 | 3 |  |
| 6 | `object_function` | 90.6% | 29 | 32 | 3 |  |
| 7 | `has_own_property` | 87.5% | 28 | 32 | 4 |  |
| 8 | `swf7_case_sensitive` | 84.1% | 37 | 44 | 7 |  |
| 9 | `array_properties` | 83.3% | 30 | 36 | 6 |  |
| 10 | `as1_constructor_v7` | 82.9% | 29 | 35 | 6 |  |
| 11 | `getproperty_swf4` | 82.1% | 23 | 28 | 5 |  |
| 12 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 13 | `movieclip_prototype_extension` | 80.0% | 4 | 5 | 1 |  |
| 14 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 15 | `as1_constructor_v6` | 77.1% | 27 | 35 | 8 |  |
| 16 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 17 | `stage_object_children` | 75.9% | 63 | 83 | 20 |  |
| 18 | `define_function2` | 75.0% | 6 | 8 | 2 |  |
| 19 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 20 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 21 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 22 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 23 | `object_constructor` | 72.7% | 24 | 33 | 9 |  |
| 24 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 25 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 26 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 27 | `point` | 70.9% | 124 | 175 | 51 |  |
| 28 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 29 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 30 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 31 | `get_variable_in_scope` | 69.0% | 20 | 29 | 9 |  |
| 32 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 33 | `set_variable_scope` | 68.3% | 43 | 63 | 20 |  |
| 34 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 35 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 36 | `primitive_instanceof` | 67.6% | 25 | 37 | 12 |  |
| 37 | `this_swf7` | 67.3% | 37 | 55 | 18 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 38 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 39 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 40 | `delete` | 66.7% | 2 | 3 | 1 |  |
| 41 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 42 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 43 | `goto_both_ways2` | 66.7% | 2 | 3 | 1 |  |
| 44 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 45 | `goto_rewind2` | 66.7% | 2 | 3 | 1 |  |
| 46 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 47 | `o` | 66.7% | 2 | 3 | 1 |  |
| 48 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 49 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 50 | `error` | 65.5% | 38 | 58 | 20 |  |
| 51 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 52 | `getproperty` | 64.3% | 18 | 28 | 10 |  |
| 53 | `getproperty_swf5` | 64.3% | 18 | 28 | 10 |  |
| 54 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 55 | `globals_swf6` | 64.1% | 195 | 304 | 109 |  |
| 56 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 57 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 58 | `globals_swf7` | 63.2% | 192 | 304 | 112 |  |
| 59 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 60 | `globals_swf5` | 61.8% | 188 | 304 | 116 |  |
| 61 | `arguments` | 61.4% | 78 | 127 | 49 |  |
| 62 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 63 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 64 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 65 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 66 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 67 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 68 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 69 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 70 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 71 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 72 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 73 | `swf6_case_insensitive` | 59.1% | 26 | 44 | 18 |  |
| 74 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 75 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 76 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 77 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 78 | `primitive_type_globals` | 57.3% | 319 | 557 | 238 |  |
| 79 | `escape` | 57.1% | 8 | 14 | 6 |  |
| 80 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 81 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 82 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 83 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 84 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 85 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 86 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 87 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 88 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 89 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 90 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 91 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 92 | `movieclip_focusenabled` | 52.5% | 52 | 99 | 47 |  |
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
| 104 | `prototype_delete` | 50.0% | 6 | 12 | 6 |  |
| 105 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 106 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 107 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**9 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `array_constructor` | 4.2s |  |
| 2 | `as2_oop` | 4.3s |  |
| 3 | `device_font_spacing` | 8.4s |  |
| 4 | `duplicate_movie_clip_drawing` | 3.4s |  |
| 5 | `enumerate` | 4.2s |  |
| 6 | `extends_chain` | 4.8s |  |
| 7 | `issue_2166` | 4.1s |  |
| 8 | `path_string` | 4.6s |  |
| 9 | `swf4_actions_coercion_order` | 4.4s |  |

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `array_length` | exit code -6 | 4.4s |  |
| 2 | `uncaught_exception` | exit code 1 | 2.0s |  |
| 3 | `uncaught_exception_bubbled` | exit code 1 | 2.0s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.2s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.1s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.3s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.5s |  |

## All Output Mismatches

**402 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `equals2_swf5` | 99.9% | 925/926 | 926 | 926 |  |
| 2 | `lessthan2_swf5` | 97.5% | 1197/1228 | 1228 | 1226 |  |
| 3 | `lessthan2_swf6` | 97.5% | 1197/1228 | 1228 | 1226 |  |
| 4 | `lessthan2_swf7` | 97.5% | 1197/1228 | 1228 | 1226 |  |
| 5 | `object_string_coerce_swf5` | 95.4% | 62/65 | 65 | 62 |  |
| 6 | `object_function` | 90.6% | 29/32 | 32 | 32 |  |
| 7 | `has_own_property` | 87.5% | 28/32 | 32 | 32 |  |
| 8 | `swf7_case_sensitive` | 84.1% | 37/44 | 44 | 44 |  |
| 9 | `array_properties` | 83.3% | 30/36 | 36 | 36 |  |
| 10 | `as1_constructor_v7` | 82.9% | 29/35 | 35 | 35 |  |
| 11 | `getproperty_swf4` | 82.1% | 23/28 | 28 | 28 |  |
| 12 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 13 | `movieclip_prototype_extension` | 80.0% | 4/5 | 5 | 5 |  |
| 14 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 15 | `as1_constructor_v6` | 77.1% | 27/35 | 35 | 35 |  |
| 16 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 17 | `stage_object_children` | 75.9% | 63/83 | 83 | 83 |  |
| 18 | `define_function2` | 75.0% | 6/8 | 8 | 8 |  |
| 19 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 20 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 21 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 22 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 23 | `object_constructor` | 72.7% | 24/33 | 33 | 33 |  |
| 24 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 25 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 26 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 27 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 28 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 29 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 30 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 31 | `get_variable_in_scope` | 69.0% | 20/29 | 29 | 29 |  |
| 32 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 33 | `set_variable_scope` | 68.3% | 43/63 | 63 | 58 |  |
| 34 | `object_string_coerce_swf6` | 67.6% | 46/68 | 65 | 68 |  |
| 35 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 36 | `primitive_instanceof` | 67.6% | 25/37 | 37 | 37 |  |
| 37 | `this_swf7` | 67.3% | 37/55 | 55 | 41 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 38 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 39 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 40 | `delete` | 66.7% | 2/3 | 3 | 3 |  |
| 41 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 42 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 43 | `goto_both_ways2` | 66.7% | 2/3 | 2 | 3 |  |
| 44 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 45 | `goto_rewind2` | 66.7% | 2/3 | 2 | 3 |  |
| 46 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 47 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 48 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 49 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 50 | `error` | 65.5% | 38/58 | 58 | 58 |  |
| 51 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 52 | `getproperty` | 64.3% | 18/28 | 28 | 28 |  |
| 53 | `getproperty_swf5` | 64.3% | 18/28 | 28 | 28 |  |
| 54 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 55 | `globals_swf6` | 64.1% | 195/304 | 304 | 304 |  |
| 56 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 57 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 58 | `globals_swf7` | 63.2% | 192/304 | 304 | 304 |  |
| 59 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 60 | `globals_swf5` | 61.8% | 188/304 | 304 | 304 |  |
| 61 | `arguments` | 61.4% | 78/127 | 92 | 127 |  |
| 62 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 63 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 64 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 65 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 66 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 67 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 68 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 69 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 70 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 71 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 72 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 73 | `swf6_case_insensitive` | 59.1% | 26/44 | 44 | 42 |  |
| 74 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 75 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 76 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 77 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 78 | `primitive_type_globals` | 57.3% | 319/557 | 555 | 557 |  |
| 79 | `escape` | 57.1% | 8/14 | 14 | 14 |  |
| 80 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 81 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 82 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 83 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 84 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 85 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 86 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 87 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 88 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 89 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 90 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 91 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 92 | `movieclip_focusenabled` | 52.5% | 52/99 | 99 | 99 |  |
| 93 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 336 |  |
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
| 104 | `prototype_delete` | 50.0% | 6/12 | 12 | 12 |  |
| 105 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 106 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 107 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 108 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 109 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 110 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 111 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 112 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 113 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 114 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 115 | `new_object_enumerate` | 42.9% | 3/7 | 7 | 7 |  |
| 116 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 117 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 118 | `globals_swf8` | 38.8% | 118/304 | 304 | 304 |  |
| 119 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 120 | `as_broadcaster_undef` | 38.2% | 34/89 | 81 | 89 |  |
| 121 | `localconnection_properties` | 37.5% | 3/8 | 8 | 8 |  |
| 122 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 123 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 124 | `string_coercion` | 35.7% | 45/126 | 126 | 117 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 125 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 126 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 127 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 128 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 129 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 130 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 131 | `goto_both_ways1` | 33.3% | 1/3 | 1 | 3 |  |
| 132 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 133 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 134 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 135 | `define_function2_preload` | 30.8% | 4/13 | 12 | 13 |  |
| 136 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 137 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 138 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 139 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 140 | `define_local_with_paths` | 27.8% | 15/54 | 44 | 54 |  |
| 141 | `this_swf5` | 27.3% | 15/55 | 55 | 41 |  |
| 142 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 143 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 144 | `this_swf6` | 25.5% | 14/55 | 55 | 41 |  |
| 145 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 146 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 147 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 148 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 149 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 150 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 151 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 152 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 153 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 154 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 155 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 156 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 157 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 158 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 159 | `unescape` | 20.9% | 9/43 | 42 | 43 |  |
| 160 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 161 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 162 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 163 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 164 | `global_array` | 20.0% | 1/5 | 5 | 4 |  |
| 165 | `xml_attributes_read` | 20.0% | 1/5 | 3 | 5 |  |
| 166 | `frame_size_translated_negative` | 19.0% | 4/21 | 20 | 21 |  |
| 167 | `frame_size_translated_positive` | 19.0% | 4/21 | 20 | 21 |  |
| 168 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 169 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 170 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 171 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 172 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 173 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 174 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 175 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 176 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 177 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 178 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 179 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 180 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 181 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 182 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 183 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 184 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 185 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 186 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 187 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 188 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 189 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 190 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 191 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 192 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 193 | `string_paths_other` | 11.1% | 4/36 | 28 | 36 |  |
| 194 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 195 | `with` | 10.3% | 7/68 | 68 | 49 |  |
| 196 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 197 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 198 | `this_scoping` | 9.6% | 5/52 | 50 | 52 |  |
| 199 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 200 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 201 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 202 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 203 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 204 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 205 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 206 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 207 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 208 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 209 | `funky_function_calls` | 7.1% | 4/56 | 12 | 56 |  |
| 210 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 211 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 212 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 213 | `array_enumerate` | 6.2% | 1/16 | 16 | 4 |  |
| 214 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 215 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 216 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 217 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 218 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 219 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 220 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 221 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 222 | `register_class` | 4.5% | 3/66 | 27 | 66 |  |
| 223 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 224 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 225 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 226 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 227 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 228 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 229 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 230 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 231 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 232 | `with_variable_scopes` | 1.5% | 1/68 | 68 | 43 |  |
| 233 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 234 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 235 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 236 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 237 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 238 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 239 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 240 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 241 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 242 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 243 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 244 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 245 | `localconnection` | 0.2% | 1/580 | 1 | 580 |  |
| 246 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 247 | `array_sort_random` | 0.0% | 0/443 | 1 | 443 |  |
| 248 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 249 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 250 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 1 | 40 |  |
| 251 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 252 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 253 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 254 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 255 | `asfunction` | 0.0% | 0/11 | 1 | 11 |  |
| 256 | `asnew` | 0.0% | 0/34 | 1 | 34 |  |
| 257 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 1 | 2 |  |
| 258 | `boxed_primitives` | 0.0% | 0/24 | 1 | 24 |  |
| 259 | `button_children` | 0.0% | 0/8 | 1 | 8 |  |
| 260 | `button_goto` | 0.0% | 0/4 | 1 | 4 |  |
| 261 | `button_order` | 0.0% | 0/2 | 1 | 2 |  |
| 262 | `button_properties_special_cases` | 0.0% | 0/22 | 1 | 22 |  |
| 263 | `button_v5` | 0.0% | 0/18 | 1 | 18 |  |
| 264 | `button_v6` | 0.0% | 0/18 | 1 | 18 |  |
| 265 | `call` | 0.0% | 0/63 | 1 | 63 |  |
| 266 | `call_method_empty_name` | 0.0% | 0/1 | 1 | 1 |  |
| 267 | `clip_constructors` | 0.0% | 0/8 | 1 | 8 |  |
| 268 | `clip_event_propagation_order` | 0.0% | 0/17 | 1 | 17 |  |
| 269 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 270 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 271 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 272 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 1 | 129 |  |
| 273 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 1 | 17 |  |
| 274 | `color` | 0.0% | 0/57 | 1 | 57 |  |
| 275 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 276 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 277 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 278 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 279 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 280 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 281 | `duplicate_movie_clip` | 0.0% | 0/20 | 1 | 20 |  |
| 282 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 283 | `edittext_html_roundtrip` | 0.0% | 0/17 | 1 | 17 |  |
| 284 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 285 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 286 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 287 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 288 | `extends_native_type` | 0.0% | 0/11 | 1 | 11 |  |
| 289 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 290 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 291 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 292 | `file_reference_browse_cancel` | 0.0% | 0/21 | 1 | 21 |  |
| 293 | `function_base_clip` | 0.0% | 0/8 | 1 | 8 |  |
| 294 | `function_base_clip_readded` | 0.0% | 0/11 | 1 | 11 |  |
| 295 | `function_suppress_and_preload` | 0.0% | 0/28 | 1 | 28 |  |
| 296 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 297 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 298 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 299 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 300 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 301 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 1 | 1145 |  |
| 302 | `global_swf6_7_8` | 0.0% | 0/15 | 1 | 15 |  |
| 303 | `goto_execution_order2` | 0.0% | 0/2 | 1 | 2 |  |
| 304 | `goto_frame` | 0.0% | 0/12 | 1 | 12 |  |
| 305 | `goto_frame2` | 0.0% | 0/44 | 1 | 44 |  |
| 306 | `goto_label` | 0.0% | 0/17 | 1 | 17 |  |
| 307 | `goto_methods` | 0.0% | 0/40 | 1 | 40 |  |
| 308 | `hittest_lockroot` | 0.0% | 0/15 | 1 | 15 |  |
| 309 | `hittest_morph` | 0.0% | 0/70 | 1 | 70 |  |
| 310 | `hittest_morph_input` | 0.0% | 0/1 | 1 | 1 |  |
| 311 | `hittest_winding_rule` | 0.0% | 0/12 | 1 | 12 |  |
| 312 | `init_array_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 313 | `init_object_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 314 | `init_object_order` | 0.0% | 0/15 | 1 | 15 |  |
| 315 | `input_dead_keys_windows` | 0.0% | 0/15 | 1 | 15 |  |
| 316 | `instanceof_coercions` | 0.0% | 0/88 | 1 | 88 |  |
| 317 | `interface_implements_op` | 0.0% | 0/47 | 1 | 47 |  |
| 318 | `issue_1104` | 0.0% | 0/2 | 1 | 2 |  |
| 319 | `issue_2084` | 0.0% | 0/16 | 1 | 16 |  |
| 320 | `issue_2870` | 0.0% | 0/3 | 1 | 3 |  |
| 321 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 322 | `issue_9327` | 0.0% | 0/2 | 1 | 2 |  |
| 323 | `issue_9885` | 0.0% | 0/2 | 1 | 2 |  |
| 324 | `lock_root` | 0.0% | 0/1 | 1 | 1 |  |
| 325 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 1 | 35 |  |
| 326 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 327 | `movieclip_gettextsnapshot` | 0.0% | 0/112 | 21 | 112 |  |
| 328 | `movieclip_in_removed_button` | 0.0% | 0/4 | 1 | 4 |  |
| 329 | `movieclip_init_object` | 0.0% | 0/5 | 1 | 5 |  |
| 330 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 331 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 1 | 4 |  |
| 332 | `named_shapes` | 0.0% | 0/14 | 1 | 14 |  |
| 333 | `native_double_construct` | 0.0% | 0/12 | 1 | 12 |  |
| 334 | `native_objects_swf6` | 0.0% | 0/84 | 1 | 84 |  |
| 335 | `native_objects_swf7` | 0.0% | 0/84 | 1 | 84 |  |
| 336 | `native_objects_swf8` | 0.0% | 0/84 | 1 | 84 |  |
| 337 | `native_subclasses` | 0.0% | 0/191 | 1 | 191 |  |
| 338 | `netconnection_send_remote` | 0.0% | 0/50 | 1 | 50 |  |
| 339 | `new_method_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 340 | `new_object_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 341 | `object_properties` | 0.0% | 0/31 | 1 | 31 |  |
| 342 | `object_resolve` | 0.0% | 0/38 | 1 | 38 |  |
| 343 | `on_construct` | 0.0% | 0/25 | 1 | 25 |  |
| 344 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 345 | `place_and_lookup` | 0.0% | 0/30 | 1 | 30 |  |
| 346 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 347 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 1 |  |
| 348 | `register_class_return_value` | 0.0% | 0/16 | 1 | 16 |  |
| 349 | `register_class_swf6` | 0.0% | 0/37 | 1 | 37 |  |
| 350 | `register_class_with_sound` | 0.0% | 0/11 | 1 | 11 |  |
| 351 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 352 | `removed_target_clip_scope` | 0.0% | 0/35 | 1 | 35 |  |
| 353 | `resolve_different_root` | 0.0% | 0/2 | 1 | 2 |  |
| 354 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 355 | `root_onload` | 0.0% | 0/1 | 1 | 1 |  |
| 356 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 357 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 358 | `selection` | 0.0% | 0/454 | 1 | 454 |  |
| 359 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 360 | `slash_syntax` | 0.0% | 0/14 | 1 | 14 |  |
| 361 | `stage_object_enumerate` | 0.0% | 0/4 | 1 | 4 |  |
| 362 | `string_methods_negative_args` | 0.0% | 0/240 | 1 | 240 |  |
| 363 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 364 | `string_paths_eval` | 0.0% | 0/4 | 1 | 4 |  |
| 365 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 366 | `string_paths_unload` | 0.0% | 0/1 | 1 | 1 |  |
| 367 | `string_paths_variable_scopes` | 0.0% | 0/5 | 1 | 5 |  |
| 368 | `stylesheet` | 0.0% | 0/283 | 1 | 283 |  |
| 369 | `super_edge_cases` | 0.0% | 0/39 | 1 | 39 |  |
| 370 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 371 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 372 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 373 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 374 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 375 | `target_clip_swf5` | 0.0% | 0/2 | 1 | 2 |  |
| 376 | `target_clip_swf6` | 0.0% | 0/2 | 1 | 2 |  |
| 377 | `target_path` | 0.0% | 0/14 | 1 | 14 |  |
| 378 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 379 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 380 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 381 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 |  |
| 382 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 383 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 384 | `timer_run_actions` | 0.0% | 0/18 | 1 | 18 |  |
| 385 | `typeof` | 0.0% | 0/22 | 1 | 22 |  |
| 386 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 387 | `unload_clip_event` | 0.0% | 0/4 | 1 | 4 |  |
| 388 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 389 | `use_hand_cursor` | 0.0% | 0/8 | 1 | 8 |  |
| 390 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 391 | `watch` | 0.0% | 0/117 | 1 | 117 |  |
| 392 | `watch_textfield` | 0.0% | 0/12 | 1 | 12 |  |
| 393 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 |  |
| 394 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 395 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 396 | `xml_ignore_comments` | 0.0% | 0/21 | 1 | 21 |  |
| 397 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 398 | `xml_reparenting` | 0.0% | 0/14 | 1 | 14 |  |
| 399 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 400 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 401 | `xml_unescaping` | 0.0% | 0/23 | 1 | 23 |  |
| 402 | `xmlnode_proto` | 0.0% | 0/1 | 1 | 1 |  |
