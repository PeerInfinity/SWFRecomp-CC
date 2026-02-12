# Ruffle Test Results (Filtered)

**Date**: 2026-02-12 03:25 UTC

**Git SHA**: `082fbae125`

**Run Duration**: 27m 9s

**Filtered**: 125 tests ignored out of 616 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 491 |
| Passing | **69** (14.1%) |
| Failing | 422 |
| Total expected lines | 76093 |
| Matching lines | 30263 (39.8%) |
| Mismatched lines | 45830 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 406 | 96.2% |
| Segfault | 9 | 2.1% |
| Timeout | 4 | 0.9% |
| Runtime Error | 3 | 0.7% |

## Passing Tests

**69 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 4.1s |  |
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
| 14 | `bitand` | 1058 | 10.6s |  |
| 15 | `bitmap_data_colortransform` | 1 | 2.4s |  |
| 16 | `bitmap_data_fillrect` | 1 | 2.2s |  |
| 17 | `bitmap_data_perlinnoise` | 1 | 2.9s |  |
| 18 | `bitmap_data_pixeldissolve_image` | 1 | 2.6s |  |
| 19 | `bitmapdata_applyfilter_colormatrix` | 1 | 2.1s |  |
| 20 | `bitor` | 1058 | 10.8s |  |
| 21 | `biturshift` | 14 | 2.3s |  |
| 22 | `biturshift_swf8` | 14 | 2.1s |  |
| 23 | `bitxor` | 1058 | 10.8s |  |
| 24 | `catch_references_registers` | 2 | 2.0s |  |
| 25 | `define_function_case_sensitive` | 2 | 2.0s |  |
| 26 | `divide_swf4` | 107 | 2.2s |  |
| 27 | `do_init_action` | 3 | 2.2s |  |
| 28 | `equals` | 32 | 2.2s |  |
| 29 | `equals_swf4` | 665 | 5.8s |  |
| 30 | `equals_swf4_alt` | 32 | 2.1s |  |
| 31 | `equals_swf5` | 32 | 2.1s |  |
| 32 | `global_is_bare` | 7 | 2.0s |  |
| 33 | `goto_execution_order` | 2 | 2.0s |  |
| 34 | `goto_rewind1` | 1 | 2.1s |  |
| 35 | `greaterthan_swf5` | 1 | 2.1s |  |
| 36 | `greaterthan_swf8` | 1 | 2.1s |  |
| 37 | `infinite_recursion_function_in_setter` | 131 | 2.1s |  |
| 38 | `infinite_recursion_virtual_property` | 67 | 2.0s |  |
| 39 | `issue_1086` | 1 | 2.0s |  |
| 40 | `issue_1671` | 1 | 2.0s |  |
| 41 | `issue_3446` | 1 | 2.1s |  |
| 42 | `issue_4377` | 2 | 2.1s |  |
| 43 | `issue_768` | 3 | 2.0s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 44 | `lessthan` | 41 | 2.2s |  |
| 45 | `lessthan_swf4` | 902 | 7.5s |  |
| 46 | `lessthan_swf4_alt` | 41 | 2.2s |  |
| 47 | `lessthan_swf5` | 41 | 2.2s |  |
| 48 | `logical_ops_swf4` | 90 | 2.1s |  |
| 49 | `logical_ops_swf8` | 108 | 2.2s |  |
| 50 | `looping` | 6 | 2.0s |  |
| 51 | `mask_reapply` | 1 | 2.0s |  |
| 52 | `mask_with_drawing` | 1 | 2.0s |  |
| 53 | `movieclip_begin_gradient_fill` | 1 | 2.8s |  |
| 54 | `movieclip_line_gradient_style` | 1 | 2.7s |  |
| 55 | `nested_textfields_in_buttons` | 1 | 2.0s |  |
| 56 | `sandbox_type_local_file` | 1 | 1.9s |  |
| 57 | `single_frame` | 1 | 1.9s |  |
| 58 | `strictequals_swf6` | 902 | 7.8s |  |
| 59 | `strictly_equals` | 7 | 2.0s |  |
| 60 | `string_paths_keyevents` | 1 | 2.0s |  |
| 61 | `string_paths_timer` | 1 | 2.0s |  |
| 62 | `swf4_actions_bool` | 96 | 2.1s |  |
| 63 | `swf4_bool` | 4 | 2.0s |  |
| 64 | `swf5_encoding` | 3 | 4.2s |  |
| 65 | `timeline_function_def` | 7 | 2.1s |  |
| 66 | `try_finally_simple` | 16 | 2.2s |  |
| 67 | `typeof_globals` | 7 | 2.2s |  |
| 68 | `undefined_to_string_swf6` | 4 | 2.2s |  |
| 69 | `with_return` | 2 | 2.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**112 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `equals2_swf6` | 99.9% | 925 | 926 | 1 |  |
| 2 | `equals2_swf7` | 99.9% | 925 | 926 | 1 |  |
| 3 | `equals2_swf5` | 99.8% | 924 | 926 | 2 |  |
| 4 | `string_coercion` | 99.1% | 116 | 117 | 1 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 5 | `object_string_coerce_swf5` | 95.4% | 62 | 65 | 3 |  |
| 6 | `object_function` | 90.6% | 29 | 32 | 3 |  |
| 7 | `has_own_property` | 87.5% | 28 | 32 | 4 |  |
| 8 | `swf7_case_sensitive` | 84.1% | 37 | 44 | 7 |  |
| 9 | `array_properties` | 83.3% | 30 | 36 | 6 |  |
| 10 | `as1_constructor_v7` | 82.9% | 29 | 35 | 6 |  |
| 11 | `getproperty_swf4` | 82.1% | 23 | 28 | 5 |  |
| 12 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 13 | `movieclip_prototype_extension` | 80.0% | 4 | 5 | 1 |  |
| 14 | `greater_swf6` | 77.9% | 915 | 1175 | 260 |  |
| 15 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 16 | `as1_constructor_v6` | 77.1% | 27 | 35 | 8 |  |
| 17 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 18 | `lessthan2_swf5` | 76.5% | 939 | 1228 | 289 |  |
| 19 | `lessthan2_swf6` | 76.5% | 939 | 1228 | 289 |  |
| 20 | `stage_object_children` | 75.9% | 63 | 83 | 20 |  |
| 21 | `define_function2` | 75.0% | 6 | 8 | 2 |  |
| 22 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 23 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 24 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 25 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 26 | `object_constructor` | 72.7% | 24 | 33 | 9 |  |
| 27 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 28 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 29 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 30 | `greater_swf7` | 71.0% | 834 | 1175 | 341 |  |
| 31 | `point` | 70.9% | 124 | 175 | 51 |  |
| 32 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 33 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 34 | `lessthan2_swf7` | 69.9% | 858 | 1228 | 370 |  |
| 35 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 36 | `get_variable_in_scope` | 69.0% | 20 | 29 | 9 |  |
| 37 | `array_sort` | 68.3% | 110 | 161 | 51 |  |
| 38 | `set_variable_scope` | 68.3% | 43 | 63 | 20 |  |
| 39 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 40 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 41 | `primitive_instanceof` | 67.6% | 25 | 37 | 12 |  |
| 42 | `this_swf7` | 67.3% | 37 | 55 | 18 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 43 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 44 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 45 | `delete` | 66.7% | 2 | 3 | 1 |  |
| 46 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 47 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 48 | `goto_both_ways2` | 66.7% | 2 | 3 | 1 |  |
| 49 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 50 | `goto_rewind2` | 66.7% | 2 | 3 | 1 |  |
| 51 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 52 | `o` | 66.7% | 2 | 3 | 1 |  |
| 53 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 54 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 55 | `error` | 65.5% | 38 | 58 | 20 |  |
| 56 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 57 | `getproperty` | 64.3% | 18 | 28 | 10 |  |
| 58 | `getproperty_swf5` | 64.3% | 18 | 28 | 10 |  |
| 59 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 60 | `globals_swf6` | 64.1% | 195 | 304 | 109 |  |
| 61 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 62 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 63 | `globals_swf7` | 63.2% | 192 | 304 | 112 |  |
| 64 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 65 | `globals_swf5` | 61.8% | 188 | 304 | 116 |  |
| 66 | `arguments` | 61.4% | 78 | 127 | 49 |  |
| 67 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 68 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 69 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 70 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 71 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 72 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 73 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 74 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 75 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 76 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 77 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 78 | `swf6_case_insensitive` | 59.1% | 26 | 44 | 18 |  |
| 79 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 80 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 81 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 82 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 83 | `primitive_type_globals` | 57.3% | 319 | 557 | 238 |  |
| 84 | `escape` | 57.1% | 8 | 14 | 6 |  |
| 85 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 86 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 87 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 88 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 89 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 90 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 91 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 92 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 93 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 94 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 95 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 96 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 97 | `movieclip_focusenabled` | 52.5% | 52 | 99 | 47 |  |
| 98 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 99 | `as_set_prop_flags_version` | 51.6% | 16 | 31 | 15 |  |
| 100 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 101 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 102 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 103 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 104 | `goto_advance2` | 50.0% | 1 | 2 | 1 |  |
| 105 | `goto_rewind3` | 50.0% | 1 | 2 | 1 |  |
| 106 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 107 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 108 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 109 | `prototype_delete` | 50.0% | 6 | 12 | 6 |  |
| 110 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 111 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 112 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**9 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `array_constructor` | 4.2s |  |
| 2 | `as2_oop` | 4.3s |  |
| 3 | `device_font_spacing` | 10.5s |  |
| 4 | `duplicate_movie_clip_drawing` | 4.1s |  |
| 5 | `enumerate` | 4.2s |  |
| 6 | `extends_chain` | 4.8s |  |
| 7 | `issue_2166` | 4.2s |  |
| 8 | `path_string` | 4.5s |  |
| 9 | `swf4_actions_coercion_order` | 3.6s |  |

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `array_length` | exit code -6 | 4.3s |  |
| 2 | `uncaught_exception` | exit code 1 | 2.1s |  |
| 3 | `uncaught_exception_bubbled` | exit code 1 | 2.1s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.2s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.1s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.2s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.7s |  |

## All Output Mismatches

**406 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `equals2_swf6` | 99.9% | 925/926 | 926 | 926 |  |
| 2 | `equals2_swf7` | 99.9% | 925/926 | 926 | 926 |  |
| 3 | `equals2_swf5` | 99.8% | 924/926 | 926 | 926 |  |
| 4 | `string_coercion` | 99.1% | 116/117 | 117 | 117 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 5 | `object_string_coerce_swf5` | 95.4% | 62/65 | 65 | 62 |  |
| 6 | `object_function` | 90.6% | 29/32 | 32 | 32 |  |
| 7 | `has_own_property` | 87.5% | 28/32 | 32 | 32 |  |
| 8 | `swf7_case_sensitive` | 84.1% | 37/44 | 44 | 44 |  |
| 9 | `array_properties` | 83.3% | 30/36 | 36 | 36 |  |
| 10 | `as1_constructor_v7` | 82.9% | 29/35 | 35 | 35 |  |
| 11 | `getproperty_swf4` | 82.1% | 23/28 | 28 | 28 |  |
| 12 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 13 | `movieclip_prototype_extension` | 80.0% | 4/5 | 5 | 5 |  |
| 14 | `greater_swf6` | 77.9% | 915/1175 | 1175 | 1175 |  |
| 15 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 16 | `as1_constructor_v6` | 77.1% | 27/35 | 35 | 35 |  |
| 17 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 18 | `lessthan2_swf5` | 76.5% | 939/1228 | 1228 | 1226 |  |
| 19 | `lessthan2_swf6` | 76.5% | 939/1228 | 1228 | 1226 |  |
| 20 | `stage_object_children` | 75.9% | 63/83 | 83 | 83 |  |
| 21 | `define_function2` | 75.0% | 6/8 | 8 | 8 |  |
| 22 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 23 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 24 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 25 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 26 | `object_constructor` | 72.7% | 24/33 | 33 | 33 |  |
| 27 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 28 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 29 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 30 | `greater_swf7` | 71.0% | 834/1175 | 1175 | 1175 |  |
| 31 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 32 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 33 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 34 | `lessthan2_swf7` | 69.9% | 858/1228 | 1228 | 1226 |  |
| 35 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 36 | `get_variable_in_scope` | 69.0% | 20/29 | 29 | 29 |  |
| 37 | `array_sort` | 68.3% | 110/161 | 161 | 161 |  |
| 38 | `set_variable_scope` | 68.3% | 43/63 | 63 | 58 |  |
| 39 | `object_string_coerce_swf6` | 67.6% | 46/68 | 65 | 68 |  |
| 40 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 41 | `primitive_instanceof` | 67.6% | 25/37 | 37 | 37 |  |
| 42 | `this_swf7` | 67.3% | 37/55 | 55 | 41 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 43 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 44 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 45 | `delete` | 66.7% | 2/3 | 3 | 3 |  |
| 46 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 47 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 48 | `goto_both_ways2` | 66.7% | 2/3 | 2 | 3 |  |
| 49 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 50 | `goto_rewind2` | 66.7% | 2/3 | 2 | 3 |  |
| 51 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 52 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 53 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 54 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 55 | `error` | 65.5% | 38/58 | 58 | 58 |  |
| 56 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 57 | `getproperty` | 64.3% | 18/28 | 28 | 28 |  |
| 58 | `getproperty_swf5` | 64.3% | 18/28 | 28 | 28 |  |
| 59 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 60 | `globals_swf6` | 64.1% | 195/304 | 304 | 304 |  |
| 61 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 62 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 63 | `globals_swf7` | 63.2% | 192/304 | 304 | 304 |  |
| 64 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 65 | `globals_swf5` | 61.8% | 188/304 | 304 | 304 |  |
| 66 | `arguments` | 61.4% | 78/127 | 92 | 127 |  |
| 67 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 68 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 69 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 70 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 71 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 72 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 73 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 74 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 75 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 76 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 77 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 78 | `swf6_case_insensitive` | 59.1% | 26/44 | 44 | 42 |  |
| 79 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 80 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 81 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 82 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 83 | `primitive_type_globals` | 57.3% | 319/557 | 555 | 557 |  |
| 84 | `escape` | 57.1% | 8/14 | 14 | 14 |  |
| 85 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 86 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 87 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 88 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 89 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 90 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 91 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 92 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 93 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 94 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 95 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 96 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 97 | `movieclip_focusenabled` | 52.5% | 52/99 | 99 | 99 |  |
| 98 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 336 |  |
| 99 | `as_set_prop_flags_version` | 51.6% | 16/31 | 29 | 31 |  |
| 100 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 101 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 102 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 103 | `execution_order3` | 50.0% | 2/4 | 3 | 4 |  |
| 104 | `goto_advance2` | 50.0% | 1/2 | 1 | 2 |  |
| 105 | `goto_rewind3` | 50.0% | 1/2 | 1 | 2 |  |
| 106 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 107 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 108 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 109 | `prototype_delete` | 50.0% | 6/12 | 12 | 12 |  |
| 110 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 111 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 112 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 113 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 114 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 115 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 116 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 117 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 118 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 119 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 120 | `new_object_enumerate` | 42.9% | 3/7 | 7 | 7 |  |
| 121 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 122 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 123 | `globals_swf8` | 38.8% | 118/304 | 304 | 304 |  |
| 124 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 125 | `as_broadcaster_undef` | 38.2% | 34/89 | 81 | 89 |  |
| 126 | `localconnection_properties` | 37.5% | 3/8 | 8 | 8 |  |
| 127 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 128 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 129 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 130 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 131 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 132 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 133 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 134 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 135 | `goto_both_ways1` | 33.3% | 1/3 | 1 | 3 |  |
| 136 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 137 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 138 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 139 | `define_function2_preload` | 30.8% | 4/13 | 12 | 13 |  |
| 140 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 141 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 142 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 143 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 144 | `define_local_with_paths` | 27.8% | 15/54 | 44 | 54 |  |
| 145 | `this_swf5` | 27.3% | 15/55 | 55 | 41 |  |
| 146 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 147 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 148 | `this_swf6` | 25.5% | 14/55 | 55 | 41 |  |
| 149 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 150 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 151 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 152 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 153 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 154 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 155 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 156 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 157 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 158 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 159 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 160 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 161 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 162 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 163 | `unescape` | 20.9% | 9/43 | 42 | 43 |  |
| 164 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 165 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 166 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 167 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 168 | `global_array` | 20.0% | 1/5 | 5 | 4 |  |
| 169 | `xml_attributes_read` | 20.0% | 1/5 | 3 | 5 |  |
| 170 | `frame_size_translated_negative` | 19.0% | 4/21 | 20 | 21 |  |
| 171 | `frame_size_translated_positive` | 19.0% | 4/21 | 20 | 21 |  |
| 172 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 173 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 174 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 175 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 176 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 177 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 178 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 179 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 180 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 181 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 182 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 183 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 184 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 185 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 186 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 187 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 188 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 189 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 190 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 191 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 192 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 193 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 194 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 195 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 196 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 197 | `string_paths_other` | 11.1% | 4/36 | 28 | 36 |  |
| 198 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 199 | `with` | 10.3% | 7/68 | 68 | 49 |  |
| 200 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 201 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 202 | `this_scoping` | 9.6% | 5/52 | 50 | 52 |  |
| 203 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 204 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 205 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 206 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 207 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 208 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 209 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 210 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 211 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 212 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 213 | `funky_function_calls` | 7.1% | 4/56 | 12 | 56 |  |
| 214 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 215 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 216 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 217 | `array_enumerate` | 6.2% | 1/16 | 16 | 4 |  |
| 218 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 219 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 220 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 221 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 222 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 223 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 224 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 225 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 226 | `register_class` | 4.5% | 3/66 | 27 | 66 |  |
| 227 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 228 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 229 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 230 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 231 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 232 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 233 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 234 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 235 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 236 | `with_variable_scopes` | 1.5% | 1/68 | 68 | 43 |  |
| 237 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 238 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 239 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 240 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 241 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 242 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 243 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 244 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 245 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 246 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 247 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 248 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 249 | `localconnection` | 0.2% | 1/580 | 1 | 580 |  |
| 250 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 251 | `array_sort_random` | 0.0% | 0/443 | 1 | 443 |  |
| 252 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 253 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 254 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 1 | 40 |  |
| 255 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 256 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 257 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 258 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 259 | `asfunction` | 0.0% | 0/11 | 1 | 11 |  |
| 260 | `asnew` | 0.0% | 0/34 | 1 | 34 |  |
| 261 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 1 | 2 |  |
| 262 | `boxed_primitives` | 0.0% | 0/24 | 1 | 24 |  |
| 263 | `button_children` | 0.0% | 0/8 | 1 | 8 |  |
| 264 | `button_goto` | 0.0% | 0/4 | 1 | 4 |  |
| 265 | `button_order` | 0.0% | 0/2 | 1 | 2 |  |
| 266 | `button_properties_special_cases` | 0.0% | 0/22 | 1 | 22 |  |
| 267 | `button_v5` | 0.0% | 0/18 | 1 | 18 |  |
| 268 | `button_v6` | 0.0% | 0/18 | 1 | 18 |  |
| 269 | `call` | 0.0% | 0/63 | 1 | 63 |  |
| 270 | `call_method_empty_name` | 0.0% | 0/1 | 1 | 1 |  |
| 271 | `clip_constructors` | 0.0% | 0/8 | 1 | 8 |  |
| 272 | `clip_event_propagation_order` | 0.0% | 0/17 | 1 | 17 |  |
| 273 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 274 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 275 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 276 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 1 | 129 |  |
| 277 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 1 | 17 |  |
| 278 | `color` | 0.0% | 0/57 | 1 | 57 |  |
| 279 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 280 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 281 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 282 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 283 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 284 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 285 | `duplicate_movie_clip` | 0.0% | 0/20 | 1 | 20 |  |
| 286 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 287 | `edittext_html_roundtrip` | 0.0% | 0/17 | 1 | 17 |  |
| 288 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 289 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 290 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 291 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 292 | `extends_native_type` | 0.0% | 0/11 | 1 | 11 |  |
| 293 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 294 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 295 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 296 | `file_reference_browse_cancel` | 0.0% | 0/21 | 1 | 21 |  |
| 297 | `function_base_clip` | 0.0% | 0/8 | 1 | 8 |  |
| 298 | `function_base_clip_readded` | 0.0% | 0/11 | 1 | 11 |  |
| 299 | `function_suppress_and_preload` | 0.0% | 0/28 | 1 | 28 |  |
| 300 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 301 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 302 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 303 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 304 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 305 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 1 | 1145 |  |
| 306 | `global_swf6_7_8` | 0.0% | 0/15 | 1 | 15 |  |
| 307 | `goto_execution_order2` | 0.0% | 0/2 | 1 | 2 |  |
| 308 | `goto_frame` | 0.0% | 0/12 | 1 | 12 |  |
| 309 | `goto_frame2` | 0.0% | 0/44 | 1 | 44 |  |
| 310 | `goto_label` | 0.0% | 0/17 | 1 | 17 |  |
| 311 | `goto_methods` | 0.0% | 0/40 | 1 | 40 |  |
| 312 | `hittest_lockroot` | 0.0% | 0/15 | 1 | 15 |  |
| 313 | `hittest_morph` | 0.0% | 0/70 | 1 | 70 |  |
| 314 | `hittest_morph_input` | 0.0% | 0/1 | 1 | 1 |  |
| 315 | `hittest_winding_rule` | 0.0% | 0/12 | 1 | 12 |  |
| 316 | `init_array_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 317 | `init_object_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 318 | `init_object_order` | 0.0% | 0/15 | 1 | 15 |  |
| 319 | `input_dead_keys_windows` | 0.0% | 0/15 | 1 | 15 |  |
| 320 | `instanceof_coercions` | 0.0% | 0/88 | 1 | 88 |  |
| 321 | `interface_implements_op` | 0.0% | 0/47 | 1 | 47 |  |
| 322 | `issue_1104` | 0.0% | 0/2 | 1 | 2 |  |
| 323 | `issue_2084` | 0.0% | 0/16 | 1 | 16 |  |
| 324 | `issue_2870` | 0.0% | 0/3 | 1 | 3 |  |
| 325 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 326 | `issue_9327` | 0.0% | 0/2 | 1 | 2 |  |
| 327 | `issue_9885` | 0.0% | 0/2 | 1 | 2 |  |
| 328 | `lock_root` | 0.0% | 0/1 | 1 | 1 |  |
| 329 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 1 | 35 |  |
| 330 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 331 | `movieclip_gettextsnapshot` | 0.0% | 0/112 | 21 | 112 |  |
| 332 | `movieclip_in_removed_button` | 0.0% | 0/4 | 1 | 4 |  |
| 333 | `movieclip_init_object` | 0.0% | 0/5 | 1 | 5 |  |
| 334 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 335 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 1 | 4 |  |
| 336 | `named_shapes` | 0.0% | 0/14 | 1 | 14 |  |
| 337 | `native_double_construct` | 0.0% | 0/12 | 1 | 12 |  |
| 338 | `native_objects_swf6` | 0.0% | 0/84 | 1 | 84 |  |
| 339 | `native_objects_swf7` | 0.0% | 0/84 | 1 | 84 |  |
| 340 | `native_objects_swf8` | 0.0% | 0/84 | 1 | 84 |  |
| 341 | `native_subclasses` | 0.0% | 0/191 | 1 | 191 |  |
| 342 | `netconnection_send_remote` | 0.0% | 0/50 | 1 | 50 |  |
| 343 | `new_method_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 344 | `new_object_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 345 | `object_properties` | 0.0% | 0/31 | 1 | 31 |  |
| 346 | `object_resolve` | 0.0% | 0/38 | 1 | 38 |  |
| 347 | `on_construct` | 0.0% | 0/25 | 1 | 25 |  |
| 348 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 349 | `place_and_lookup` | 0.0% | 0/30 | 1 | 30 |  |
| 350 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 351 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 1 |  |
| 352 | `register_class_return_value` | 0.0% | 0/16 | 1 | 16 |  |
| 353 | `register_class_swf6` | 0.0% | 0/37 | 1 | 37 |  |
| 354 | `register_class_with_sound` | 0.0% | 0/11 | 1 | 11 |  |
| 355 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 356 | `removed_target_clip_scope` | 0.0% | 0/35 | 1 | 35 |  |
| 357 | `resolve_different_root` | 0.0% | 0/2 | 1 | 2 |  |
| 358 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 359 | `root_onload` | 0.0% | 0/1 | 1 | 1 |  |
| 360 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 361 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 362 | `selection` | 0.0% | 0/454 | 1 | 454 |  |
| 363 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 364 | `slash_syntax` | 0.0% | 0/14 | 1 | 14 |  |
| 365 | `stage_object_enumerate` | 0.0% | 0/4 | 1 | 4 |  |
| 366 | `string_methods_negative_args` | 0.0% | 0/240 | 1 | 240 |  |
| 367 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 368 | `string_paths_eval` | 0.0% | 0/4 | 1 | 4 |  |
| 369 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 370 | `string_paths_unload` | 0.0% | 0/1 | 1 | 1 |  |
| 371 | `string_paths_variable_scopes` | 0.0% | 0/5 | 1 | 5 |  |
| 372 | `stylesheet` | 0.0% | 0/283 | 1 | 283 |  |
| 373 | `super_edge_cases` | 0.0% | 0/39 | 1 | 39 |  |
| 374 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 375 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 376 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 377 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 378 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 379 | `target_clip_swf5` | 0.0% | 0/2 | 1 | 2 |  |
| 380 | `target_clip_swf6` | 0.0% | 0/2 | 1 | 2 |  |
| 381 | `target_path` | 0.0% | 0/14 | 1 | 14 |  |
| 382 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 383 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 384 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 385 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 |  |
| 386 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 387 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 388 | `timer_run_actions` | 0.0% | 0/18 | 1 | 18 |  |
| 389 | `typeof` | 0.0% | 0/22 | 1 | 22 |  |
| 390 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 391 | `unload_clip_event` | 0.0% | 0/4 | 1 | 4 |  |
| 392 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 393 | `use_hand_cursor` | 0.0% | 0/8 | 1 | 8 |  |
| 394 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 395 | `watch` | 0.0% | 0/117 | 1 | 117 |  |
| 396 | `watch_textfield` | 0.0% | 0/12 | 1 | 12 |  |
| 397 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 |  |
| 398 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 399 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 400 | `xml_ignore_comments` | 0.0% | 0/21 | 1 | 21 |  |
| 401 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 402 | `xml_reparenting` | 0.0% | 0/14 | 1 | 14 |  |
| 403 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 404 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 405 | `xml_unescaping` | 0.0% | 0/23 | 1 | 23 |  |
| 406 | `xmlnode_proto` | 0.0% | 0/1 | 1 | 1 |  |
