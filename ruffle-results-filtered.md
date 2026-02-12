# Ruffle Test Results (Filtered)

**Date**: 2026-02-12 02:51 UTC

**Git SHA**: `ee2e040487`

**Run Duration**: 26m 42s

**Filtered**: 125 tests ignored out of 616 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 491 |
| Passing | **71** (14.5%) |
| Failing | 420 |
| Total expected lines | 76093 |
| Matching lines | 31588 (41.5%) |
| Mismatched lines | 44505 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 404 | 96.2% |
| Segfault | 9 | 2.1% |
| Timeout | 4 | 1.0% |
| Runtime Error | 3 | 0.7% |

## Passing Tests

**71 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.1s |  |
| 2 | `action_to_integer` | 28 | 2.0s |  |
| 3 | `add` | 28 | 2.1s |  |
| 4 | `add2` | 354 | 2.5s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.1s |  |
| 6 | `add_swf5` | 28 | 2.1s |  |
| 7 | `array_concat` | 98 | 2.2s |  |
| 8 | `array_slice` | 34 | 2.2s |  |
| 9 | `array_splice` | 207 | 2.8s |  |
| 10 | `array_trivial` | 209 | 2.6s |  |
| 11 | `as_broadcaster_initialize` | 10 | 2.0s |  |
| 12 | `as_set_prop_flags_version_swf5` | 1 | 2.1s |  |
| 13 | `bad_swf_tag_past_eof` | 1 | 1.9s |  |
| 14 | `bitand` | 1058 | 10.3s |  |
| 15 | `bitmap_data_colortransform` | 1 | 2.3s |  |
| 16 | `bitmap_data_fillrect` | 1 | 2.2s |  |
| 17 | `bitmap_data_perlinnoise` | 1 | 2.8s |  |
| 18 | `bitmap_data_pixeldissolve_image` | 1 | 2.5s |  |
| 19 | `bitmapdata_applyfilter_colormatrix` | 1 | 2.0s |  |
| 20 | `bitor` | 1058 | 10.4s |  |
| 21 | `biturshift` | 14 | 3.5s |  |
| 22 | `biturshift_swf8` | 14 | 2.1s |  |
| 23 | `bitxor` | 1058 | 11.4s |  |
| 24 | `catch_references_registers` | 2 | 2.1s |  |
| 25 | `define_function_case_sensitive` | 2 | 2.0s |  |
| 26 | `divide_swf4` | 107 | 2.3s |  |
| 27 | `do_init_action` | 3 | 2.1s |  |
| 28 | `equals` | 32 | 2.1s |  |
| 29 | `equals_swf4` | 665 | 5.5s |  |
| 30 | `equals_swf4_alt` | 32 | 2.1s |  |
| 31 | `equals_swf5` | 32 | 2.1s |  |
| 32 | `global_is_bare` | 7 | 2.0s |  |
| 33 | `goto_execution_order` | 2 | 2.0s |  |
| 34 | `goto_rewind1` | 1 | 2.0s |  |
| 35 | `greater_swf6` | 1175 | 11.0s |  |
| 36 | `greater_swf7` | 1175 | 10.9s |  |
| 37 | `greaterthan_swf5` | 1 | 2.0s |  |
| 38 | `greaterthan_swf8` | 1 | 2.0s |  |
| 39 | `infinite_recursion_function_in_setter` | 131 | 2.0s |  |
| 40 | `infinite_recursion_virtual_property` | 67 | 2.0s |  |
| 41 | `issue_1086` | 1 | 2.0s |  |
| 42 | `issue_1671` | 1 | 2.0s |  |
| 43 | `issue_3446` | 1 | 2.0s |  |
| 44 | `issue_4377` | 2 | 2.0s |  |
| 45 | `issue_768` | 3 | 2.0s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 46 | `lessthan` | 41 | 2.1s |  |
| 47 | `lessthan_swf4` | 902 | 7.4s |  |
| 48 | `lessthan_swf4_alt` | 41 | 2.1s |  |
| 49 | `lessthan_swf5` | 41 | 2.1s |  |
| 50 | `logical_ops_swf4` | 90 | 2.1s |  |
| 51 | `logical_ops_swf8` | 108 | 2.2s |  |
| 52 | `looping` | 6 | 2.1s |  |
| 53 | `mask_reapply` | 1 | 2.0s |  |
| 54 | `mask_with_drawing` | 1 | 2.1s |  |
| 55 | `movieclip_begin_gradient_fill` | 1 | 2.8s |  |
| 56 | `movieclip_line_gradient_style` | 1 | 2.6s |  |
| 57 | `nested_textfields_in_buttons` | 1 | 2.0s |  |
| 58 | `sandbox_type_local_file` | 1 | 2.0s |  |
| 59 | `single_frame` | 1 | 2.0s |  |
| 60 | `strictequals_swf6` | 902 | 8.1s |  |
| 61 | `strictly_equals` | 7 | 2.0s |  |
| 62 | `string_paths_keyevents` | 1 | 2.0s |  |
| 63 | `string_paths_timer` | 1 | 2.0s |  |
| 64 | `swf4_actions_bool` | 96 | 2.2s |  |
| 65 | `swf4_bool` | 4 | 2.0s |  |
| 66 | `swf5_encoding` | 3 | 2.2s |  |
| 67 | `timeline_function_def` | 7 | 2.1s |  |
| 68 | `try_finally_simple` | 16 | 2.0s |  |
| 69 | `typeof_globals` | 7 | 2.0s |  |
| 70 | `undefined_to_string_swf6` | 4 | 2.0s |  |
| 71 | `with_return` | 2 | 2.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**107 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `equals2_swf6` | 99.9% | 925 | 926 | 1 |  |
| 2 | `equals2_swf7` | 99.9% | 925 | 926 | 1 |  |
| 3 | `equals2_swf5` | 99.8% | 924 | 926 | 2 |  |
| 4 | `lessthan2_swf5` | 97.6% | 1199 | 1228 | 29 |  |
| 5 | `lessthan2_swf6` | 97.6% | 1199 | 1228 | 29 |  |
| 6 | `lessthan2_swf7` | 97.3% | 1195 | 1228 | 33 |  |
| 7 | `object_string_coerce_swf5` | 95.4% | 62 | 65 | 3 |  |
| 8 | `object_function` | 90.6% | 29 | 32 | 3 |  |
| 9 | `array_properties` | 83.3% | 30 | 36 | 6 |  |
| 10 | `getproperty_swf4` | 82.1% | 23 | 28 | 5 |  |
| 11 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 12 | `swf7_case_sensitive` | 80.4% | 37 | 46 | 9 |  |
| 13 | `movieclip_prototype_extension` | 80.0% | 4 | 5 | 1 |  |
| 14 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 15 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 16 | `stage_object_children` | 75.9% | 63 | 83 | 20 |  |
| 17 | `define_function2` | 75.0% | 6 | 8 | 2 |  |
| 18 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 19 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 20 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 21 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 22 | `object_constructor` | 72.7% | 24 | 33 | 9 |  |
| 23 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 24 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 25 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 26 | `point` | 70.9% | 124 | 175 | 51 |  |
| 27 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 28 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 29 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 30 | `get_variable_in_scope` | 69.0% | 20 | 29 | 9 |  |
| 31 | `array_sort` | 68.3% | 110 | 161 | 51 |  |
| 32 | `set_variable_scope` | 68.3% | 43 | 63 | 20 |  |
| 33 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 34 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 35 | `primitive_instanceof` | 67.6% | 25 | 37 | 12 |  |
| 36 | `this_swf7` | 67.3% | 37 | 55 | 18 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 37 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 38 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 39 | `delete` | 66.7% | 2 | 3 | 1 |  |
| 40 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 41 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 42 | `goto_both_ways2` | 66.7% | 2 | 3 | 1 |  |
| 43 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 44 | `goto_rewind2` | 66.7% | 2 | 3 | 1 |  |
| 45 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 46 | `o` | 66.7% | 2 | 3 | 1 |  |
| 47 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 48 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 49 | `as1_constructor_v6` | 65.7% | 23 | 35 | 12 |  |
| 50 | `as1_constructor_v7` | 65.7% | 23 | 35 | 12 |  |
| 51 | `has_own_property` | 65.6% | 21 | 32 | 11 |  |
| 52 | `error` | 65.5% | 38 | 58 | 20 |  |
| 53 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 54 | `getproperty` | 64.3% | 18 | 28 | 10 |  |
| 55 | `getproperty_swf5` | 64.3% | 18 | 28 | 10 |  |
| 56 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 57 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 58 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 59 | `globals_swf6` | 63.2% | 192 | 304 | 112 |  |
| 60 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 61 | `globals_swf7` | 62.2% | 189 | 304 | 115 |  |
| 62 | `arguments` | 61.4% | 78 | 127 | 49 |  |
| 63 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 64 | `globals_swf5` | 60.9% | 185 | 304 | 119 |  |
| 65 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 66 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 67 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 68 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 69 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 70 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 71 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 72 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 73 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 74 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 75 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 76 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 77 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 78 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 79 | `primitive_type_globals` | 57.3% | 319 | 557 | 238 |  |
| 80 | `escape` | 57.1% | 8 | 14 | 6 |  |
| 81 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 82 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 83 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 84 | `swf6_case_insensitive` | 56.5% | 26 | 46 | 20 |  |
| 85 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 86 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 87 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 88 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 89 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 90 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 91 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 92 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 93 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 94 | `movieclip_focusenabled` | 52.5% | 52 | 99 | 47 |  |
| 95 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 96 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 97 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 98 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 99 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 100 | `goto_advance2` | 50.0% | 1 | 2 | 1 |  |
| 101 | `goto_rewind3` | 50.0% | 1 | 2 | 1 |  |
| 102 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 103 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 104 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 105 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 106 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 107 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**9 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `array_constructor` | 4.2s |  |
| 2 | `as2_oop` | 4.3s |  |
| 3 | `device_font_spacing` | 10.3s |  |
| 4 | `duplicate_movie_clip_drawing` | 4.1s |  |
| 5 | `enumerate` | 4.2s |  |
| 6 | `extends_chain` | 4.7s |  |
| 7 | `issue_2166` | 4.1s |  |
| 8 | `path_string` | 4.5s |  |
| 9 | `swf4_actions_coercion_order` | 4.3s |  |

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `array_length` | exit code -6 | 4.3s |  |
| 2 | `uncaught_exception` | exit code 1 | 2.0s |  |
| 3 | `uncaught_exception_bubbled` | exit code 1 | 2.0s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.2s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.1s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.2s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.5s |  |

## All Output Mismatches

**404 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `equals2_swf6` | 99.9% | 925/926 | 926 | 926 |  |
| 2 | `equals2_swf7` | 99.9% | 925/926 | 926 | 926 |  |
| 3 | `equals2_swf5` | 99.8% | 924/926 | 926 | 926 |  |
| 4 | `lessthan2_swf5` | 97.6% | 1199/1228 | 1228 | 1226 |  |
| 5 | `lessthan2_swf6` | 97.6% | 1199/1228 | 1228 | 1226 |  |
| 6 | `lessthan2_swf7` | 97.3% | 1195/1228 | 1228 | 1226 |  |
| 7 | `object_string_coerce_swf5` | 95.4% | 62/65 | 65 | 62 |  |
| 8 | `object_function` | 90.6% | 29/32 | 32 | 32 |  |
| 9 | `array_properties` | 83.3% | 30/36 | 36 | 36 |  |
| 10 | `getproperty_swf4` | 82.1% | 23/28 | 28 | 28 |  |
| 11 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 12 | `swf7_case_sensitive` | 80.4% | 37/46 | 46 | 44 |  |
| 13 | `movieclip_prototype_extension` | 80.0% | 4/5 | 5 | 5 |  |
| 14 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 15 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 16 | `stage_object_children` | 75.9% | 63/83 | 83 | 83 |  |
| 17 | `define_function2` | 75.0% | 6/8 | 8 | 8 |  |
| 18 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 19 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 20 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 21 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 22 | `object_constructor` | 72.7% | 24/33 | 33 | 33 |  |
| 23 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 24 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 25 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 26 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 27 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 28 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 29 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 30 | `get_variable_in_scope` | 69.0% | 20/29 | 29 | 29 |  |
| 31 | `array_sort` | 68.3% | 110/161 | 161 | 161 |  |
| 32 | `set_variable_scope` | 68.3% | 43/63 | 63 | 58 |  |
| 33 | `object_string_coerce_swf6` | 67.6% | 46/68 | 65 | 68 |  |
| 34 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 35 | `primitive_instanceof` | 67.6% | 25/37 | 37 | 37 |  |
| 36 | `this_swf7` | 67.3% | 37/55 | 55 | 41 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 37 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 38 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 39 | `delete` | 66.7% | 2/3 | 3 | 3 |  |
| 40 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 41 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 42 | `goto_both_ways2` | 66.7% | 2/3 | 2 | 3 |  |
| 43 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 44 | `goto_rewind2` | 66.7% | 2/3 | 2 | 3 |  |
| 45 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 46 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 47 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 48 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 49 | `as1_constructor_v6` | 65.7% | 23/35 | 35 | 35 |  |
| 50 | `as1_constructor_v7` | 65.7% | 23/35 | 35 | 35 |  |
| 51 | `has_own_property` | 65.6% | 21/32 | 32 | 32 |  |
| 52 | `error` | 65.5% | 38/58 | 58 | 58 |  |
| 53 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 54 | `getproperty` | 64.3% | 18/28 | 28 | 28 |  |
| 55 | `getproperty_swf5` | 64.3% | 18/28 | 28 | 28 |  |
| 56 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 57 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 58 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 59 | `globals_swf6` | 63.2% | 192/304 | 304 | 304 |  |
| 60 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 61 | `globals_swf7` | 62.2% | 189/304 | 304 | 304 |  |
| 62 | `arguments` | 61.4% | 78/127 | 92 | 127 |  |
| 63 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 64 | `globals_swf5` | 60.9% | 185/304 | 304 | 304 |  |
| 65 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 66 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 67 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 68 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 69 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 70 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 71 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 72 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 73 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 74 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 75 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 76 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 77 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 78 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 79 | `primitive_type_globals` | 57.3% | 319/557 | 555 | 557 |  |
| 80 | `escape` | 57.1% | 8/14 | 14 | 14 |  |
| 81 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 82 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 83 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 84 | `swf6_case_insensitive` | 56.5% | 26/46 | 46 | 42 |  |
| 85 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 86 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 87 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 88 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 89 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 90 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 91 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 92 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 93 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 94 | `movieclip_focusenabled` | 52.5% | 52/99 | 99 | 99 |  |
| 95 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 336 |  |
| 96 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 97 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 98 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 99 | `execution_order3` | 50.0% | 2/4 | 3 | 4 |  |
| 100 | `goto_advance2` | 50.0% | 1/2 | 1 | 2 |  |
| 101 | `goto_rewind3` | 50.0% | 1/2 | 1 | 2 |  |
| 102 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 103 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 104 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
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
| 115 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 116 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 117 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 118 | `as_broadcaster_undef` | 38.2% | 34/89 | 81 | 89 |  |
| 119 | `globals_swf8` | 37.8% | 115/304 | 304 | 304 |  |
| 120 | `localconnection_properties` | 37.5% | 3/8 | 8 | 8 |  |
| 121 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 122 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 123 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 124 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 125 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 126 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 127 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 128 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 129 | `goto_both_ways1` | 33.3% | 1/3 | 1 | 3 |  |
| 130 | `prototype_delete` | 33.3% | 4/12 | 12 | 12 |  |
| 131 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 132 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 133 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 134 | `define_function2_preload` | 30.8% | 4/13 | 12 | 13 |  |
| 135 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 136 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 137 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 138 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 139 | `new_object_enumerate` | 28.6% | 2/7 | 6 | 7 |  |
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
| 158 | `as_set_prop_flags_version` | 22.6% | 7/31 | 30 | 31 |  |
| 159 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 160 | `unescape` | 20.9% | 9/43 | 42 | 43 |  |
| 161 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 162 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 163 | `string_coercion` | 20.5% | 24/117 | 116 | 117 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 164 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 165 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 166 | `global_array` | 20.0% | 1/5 | 5 | 4 |  |
| 167 | `xml_attributes_read` | 20.0% | 1/5 | 3 | 5 |  |
| 168 | `frame_size_translated_negative` | 19.0% | 4/21 | 20 | 21 |  |
| 169 | `frame_size_translated_positive` | 19.0% | 4/21 | 20 | 21 |  |
| 170 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 171 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 172 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 173 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 174 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 175 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 176 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 177 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 178 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 179 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 180 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 181 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 182 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 183 | `movieclip_setmask` | 13.3% | 2/15 | 15 | 14 |  |
| 184 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 185 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 186 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 187 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 188 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 189 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 190 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 191 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 192 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 193 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 194 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 195 | `string_paths_other` | 11.1% | 4/36 | 28 | 36 |  |
| 196 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 197 | `with` | 10.3% | 7/68 | 68 | 49 |  |
| 198 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 199 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 200 | `this_scoping` | 9.6% | 5/52 | 50 | 52 |  |
| 201 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 202 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 203 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 204 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 205 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 206 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 207 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 208 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 209 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 210 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 211 | `funky_function_calls` | 7.1% | 4/56 | 12 | 56 |  |
| 212 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 213 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 214 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 215 | `array_enumerate` | 6.2% | 1/16 | 16 | 4 |  |
| 216 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 217 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 218 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 219 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 220 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 221 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 222 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 223 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 224 | `register_class` | 4.5% | 3/66 | 27 | 66 |  |
| 225 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 226 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 227 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 228 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 229 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 230 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 231 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 232 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 233 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 234 | `with_variable_scopes` | 1.5% | 1/68 | 68 | 43 |  |
| 235 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 236 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 237 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 238 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 239 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 240 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 241 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 242 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 243 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 244 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 245 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 246 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 247 | `localconnection` | 0.2% | 1/580 | 1 | 580 |  |
| 248 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 249 | `array_sort_random` | 0.0% | 0/443 | 1 | 443 |  |
| 250 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 251 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 252 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 1 | 40 |  |
| 253 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 254 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 255 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 256 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 257 | `asfunction` | 0.0% | 0/11 | 1 | 11 |  |
| 258 | `asnew` | 0.0% | 0/34 | 1 | 34 |  |
| 259 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 1 | 2 |  |
| 260 | `boxed_primitives` | 0.0% | 0/24 | 1 | 24 |  |
| 261 | `button_children` | 0.0% | 0/8 | 1 | 8 |  |
| 262 | `button_goto` | 0.0% | 0/4 | 1 | 4 |  |
| 263 | `button_order` | 0.0% | 0/2 | 1 | 2 |  |
| 264 | `button_properties_special_cases` | 0.0% | 0/22 | 1 | 22 |  |
| 265 | `button_v5` | 0.0% | 0/18 | 1 | 18 |  |
| 266 | `button_v6` | 0.0% | 0/18 | 1 | 18 |  |
| 267 | `call` | 0.0% | 0/63 | 1 | 63 |  |
| 268 | `call_method_empty_name` | 0.0% | 0/1 | 1 | 1 |  |
| 269 | `clip_constructors` | 0.0% | 0/8 | 1 | 8 |  |
| 270 | `clip_event_propagation_order` | 0.0% | 0/17 | 1 | 17 |  |
| 271 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 272 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 273 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 274 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 1 | 129 |  |
| 275 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 1 | 17 |  |
| 276 | `color` | 0.0% | 0/57 | 1 | 57 |  |
| 277 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 278 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 279 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 280 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 281 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 282 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 283 | `duplicate_movie_clip` | 0.0% | 0/20 | 1 | 20 |  |
| 284 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 285 | `edittext_html_roundtrip` | 0.0% | 0/17 | 1 | 17 |  |
| 286 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 287 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 288 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 289 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 290 | `extends_native_type` | 0.0% | 0/11 | 1 | 11 |  |
| 291 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 292 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 293 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 294 | `file_reference_browse_cancel` | 0.0% | 0/21 | 1 | 21 |  |
| 295 | `function_base_clip` | 0.0% | 0/8 | 1 | 8 |  |
| 296 | `function_base_clip_readded` | 0.0% | 0/11 | 1 | 11 |  |
| 297 | `function_suppress_and_preload` | 0.0% | 0/28 | 1 | 28 |  |
| 298 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 299 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 300 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 301 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 302 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 303 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 1 | 1145 |  |
| 304 | `global_swf6_7_8` | 0.0% | 0/15 | 1 | 15 |  |
| 305 | `goto_execution_order2` | 0.0% | 0/2 | 1 | 2 |  |
| 306 | `goto_frame` | 0.0% | 0/12 | 1 | 12 |  |
| 307 | `goto_frame2` | 0.0% | 0/44 | 1 | 44 |  |
| 308 | `goto_label` | 0.0% | 0/17 | 1 | 17 |  |
| 309 | `goto_methods` | 0.0% | 0/40 | 1 | 40 |  |
| 310 | `hittest_lockroot` | 0.0% | 0/15 | 1 | 15 |  |
| 311 | `hittest_morph` | 0.0% | 0/70 | 1 | 70 |  |
| 312 | `hittest_morph_input` | 0.0% | 0/1 | 1 | 1 |  |
| 313 | `hittest_winding_rule` | 0.0% | 0/12 | 1 | 12 |  |
| 314 | `init_array_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 315 | `init_object_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 316 | `init_object_order` | 0.0% | 0/15 | 1 | 15 |  |
| 317 | `input_dead_keys_windows` | 0.0% | 0/15 | 1 | 15 |  |
| 318 | `instanceof_coercions` | 0.0% | 0/88 | 1 | 88 |  |
| 319 | `interface_implements_op` | 0.0% | 0/47 | 1 | 47 |  |
| 320 | `issue_1104` | 0.0% | 0/2 | 1 | 2 |  |
| 321 | `issue_2084` | 0.0% | 0/16 | 1 | 16 |  |
| 322 | `issue_2870` | 0.0% | 0/3 | 1 | 3 |  |
| 323 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 324 | `issue_9327` | 0.0% | 0/2 | 1 | 2 |  |
| 325 | `issue_9885` | 0.0% | 0/2 | 1 | 2 |  |
| 326 | `lock_root` | 0.0% | 0/1 | 1 | 1 |  |
| 327 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 1 | 35 |  |
| 328 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 329 | `movieclip_gettextsnapshot` | 0.0% | 0/112 | 21 | 112 |  |
| 330 | `movieclip_in_removed_button` | 0.0% | 0/4 | 1 | 4 |  |
| 331 | `movieclip_init_object` | 0.0% | 0/5 | 1 | 5 |  |
| 332 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 333 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 1 | 4 |  |
| 334 | `named_shapes` | 0.0% | 0/14 | 1 | 14 |  |
| 335 | `native_double_construct` | 0.0% | 0/12 | 1 | 12 |  |
| 336 | `native_objects_swf6` | 0.0% | 0/84 | 1 | 84 |  |
| 337 | `native_objects_swf7` | 0.0% | 0/84 | 1 | 84 |  |
| 338 | `native_objects_swf8` | 0.0% | 0/84 | 1 | 84 |  |
| 339 | `native_subclasses` | 0.0% | 0/191 | 1 | 191 |  |
| 340 | `netconnection_send_remote` | 0.0% | 0/50 | 1 | 50 |  |
| 341 | `new_method_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 342 | `new_object_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 343 | `object_properties` | 0.0% | 0/31 | 1 | 31 |  |
| 344 | `object_resolve` | 0.0% | 0/38 | 1 | 38 |  |
| 345 | `on_construct` | 0.0% | 0/25 | 1 | 25 |  |
| 346 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 347 | `place_and_lookup` | 0.0% | 0/30 | 1 | 30 |  |
| 348 | `prototype_enumerate` | 0.0% | 0/5 | 3 | 5 |  |
| 349 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 1 |  |
| 350 | `register_class_return_value` | 0.0% | 0/16 | 1 | 16 |  |
| 351 | `register_class_swf6` | 0.0% | 0/37 | 1 | 37 |  |
| 352 | `register_class_with_sound` | 0.0% | 0/11 | 1 | 11 |  |
| 353 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 354 | `removed_target_clip_scope` | 0.0% | 0/35 | 1 | 35 |  |
| 355 | `resolve_different_root` | 0.0% | 0/2 | 1 | 2 |  |
| 356 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 357 | `root_onload` | 0.0% | 0/1 | 1 | 1 |  |
| 358 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 359 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 360 | `selection` | 0.0% | 0/454 | 1 | 454 |  |
| 361 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 362 | `slash_syntax` | 0.0% | 0/14 | 1 | 14 |  |
| 363 | `stage_object_enumerate` | 0.0% | 0/4 | 1 | 4 |  |
| 364 | `string_methods_negative_args` | 0.0% | 0/240 | 1 | 240 |  |
| 365 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 366 | `string_paths_eval` | 0.0% | 0/4 | 1 | 4 |  |
| 367 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 368 | `string_paths_unload` | 0.0% | 0/1 | 1 | 1 |  |
| 369 | `string_paths_variable_scopes` | 0.0% | 0/5 | 1 | 5 |  |
| 370 | `stylesheet` | 0.0% | 0/283 | 1 | 283 |  |
| 371 | `super_edge_cases` | 0.0% | 0/39 | 1 | 39 |  |
| 372 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 373 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 374 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 375 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 376 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 377 | `target_clip_swf5` | 0.0% | 0/2 | 1 | 2 |  |
| 378 | `target_clip_swf6` | 0.0% | 0/2 | 1 | 2 |  |
| 379 | `target_path` | 0.0% | 0/14 | 1 | 14 |  |
| 380 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 381 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 382 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 383 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 |  |
| 384 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 385 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 386 | `timer_run_actions` | 0.0% | 0/18 | 1 | 18 |  |
| 387 | `typeof` | 0.0% | 0/22 | 1 | 22 |  |
| 388 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 389 | `unload_clip_event` | 0.0% | 0/4 | 1 | 4 |  |
| 390 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 391 | `use_hand_cursor` | 0.0% | 0/8 | 1 | 8 |  |
| 392 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 393 | `watch` | 0.0% | 0/117 | 1 | 117 |  |
| 394 | `watch_textfield` | 0.0% | 0/12 | 1 | 12 |  |
| 395 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 |  |
| 396 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 397 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 398 | `xml_ignore_comments` | 0.0% | 0/21 | 1 | 21 |  |
| 399 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 400 | `xml_reparenting` | 0.0% | 0/14 | 1 | 14 |  |
| 401 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 402 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 403 | `xml_unescaping` | 0.0% | 0/23 | 1 | 23 |  |
| 404 | `xmlnode_proto` | 0.0% | 0/1 | 1 | 1 |  |
