# Ruffle Test Results (Filtered)

**Date**: 2026-02-12 03:55 UTC

**Git SHA**: `dee8f35ae4`

**Run Duration**: 27m 27s

**Filtered**: 125 tests ignored out of 616 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 491 |
| Passing | **77** (15.7%) |
| Failing | 414 |
| Total expected lines | 76093 |
| Matching lines | 31776 (41.8%) |
| Mismatched lines | 44317 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 398 | 96.1% |
| Segfault | 9 | 2.2% |
| Timeout | 4 | 1.0% |
| Runtime Error | 3 | 0.7% |

## Passing Tests

**77 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 3.3s |  |
| 2 | `action_to_integer` | 28 | 2.1s |  |
| 3 | `add` | 28 | 2.1s |  |
| 4 | `add2` | 354 | 2.5s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.1s |  |
| 6 | `add_swf5` | 28 | 2.1s |  |
| 7 | `array_concat` | 98 | 2.3s |  |
| 8 | `array_slice` | 34 | 2.3s |  |
| 9 | `array_splice` | 207 | 2.9s |  |
| 10 | `array_trivial` | 209 | 2.6s |  |
| 11 | `as_broadcaster_initialize` | 10 | 2.1s |  |
| 12 | `as_set_prop_flags_version_swf5` | 1 | 2.1s |  |
| 13 | `bad_swf_tag_past_eof` | 1 | 2.0s |  |
| 14 | `bitand` | 1058 | 10.7s |  |
| 15 | `bitmap_data_colortransform` | 1 | 2.4s |  |
| 16 | `bitmap_data_fillrect` | 1 | 2.3s |  |
| 17 | `bitmap_data_perlinnoise` | 1 | 2.9s |  |
| 18 | `bitmap_data_pixeldissolve_image` | 1 | 2.6s |  |
| 19 | `bitmapdata_applyfilter_colormatrix` | 1 | 2.1s |  |
| 20 | `bitor` | 1058 | 10.7s |  |
| 21 | `biturshift` | 14 | 3.8s |  |
| 22 | `biturshift_swf8` | 14 | 2.1s |  |
| 23 | `bitxor` | 1058 | 10.5s |  |
| 24 | `catch_references_registers` | 2 | 2.0s |  |
| 25 | `define_function_case_sensitive` | 2 | 2.0s |  |
| 26 | `divide_swf4` | 107 | 2.3s |  |
| 27 | `do_init_action` | 3 | 2.1s |  |
| 28 | `equals` | 32 | 2.2s |  |
| 29 | `equals2_swf5` | 926 | 10.5s |  |
| 30 | `equals2_swf6` | 926 | 10.3s |  |
| 31 | `equals2_swf7` | 926 | 10.4s |  |
| 32 | `equals_swf4` | 665 | 5.6s |  |
| 33 | `equals_swf4_alt` | 32 | 2.2s |  |
| 34 | `equals_swf5` | 32 | 2.2s |  |
| 35 | `global_is_bare` | 7 | 2.2s |  |
| 36 | `goto_execution_order` | 2 | 2.0s |  |
| 37 | `goto_rewind1` | 1 | 2.1s |  |
| 38 | `greater_swf6` | 1175 | 11.3s |  |
| 39 | `greater_swf7` | 1175 | 11.2s |  |
| 40 | `greaterthan_swf5` | 1 | 2.1s |  |
| 41 | `greaterthan_swf8` | 1 | 2.1s |  |
| 42 | `infinite_recursion_function_in_setter` | 131 | 2.1s |  |
| 43 | `infinite_recursion_virtual_property` | 67 | 2.1s |  |
| 44 | `issue_1086` | 1 | 2.1s |  |
| 45 | `issue_1671` | 1 | 2.1s |  |
| 46 | `issue_3446` | 1 | 2.1s |  |
| 47 | `issue_4377` | 2 | 2.1s |  |
| 48 | `issue_768` | 3 | 2.1s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 49 | `lessthan` | 41 | 2.2s |  |
| 50 | `lessthan2_swf5` | 1226 | 11.7s |  |
| 51 | `lessthan2_swf6` | 1226 | 11.8s |  |
| 52 | `lessthan2_swf7` | 1226 | 11.8s |  |
| 53 | `lessthan_swf4` | 902 | 7.5s |  |
| 54 | `lessthan_swf4_alt` | 41 | 2.1s |  |
| 55 | `lessthan_swf5` | 41 | 2.2s |  |
| 56 | `logical_ops_swf4` | 90 | 2.1s |  |
| 57 | `logical_ops_swf8` | 108 | 2.2s |  |
| 58 | `looping` | 6 | 2.0s |  |
| 59 | `mask_reapply` | 1 | 2.0s |  |
| 60 | `mask_with_drawing` | 1 | 2.1s |  |
| 61 | `movieclip_begin_gradient_fill` | 1 | 2.8s |  |
| 62 | `movieclip_line_gradient_style` | 1 | 2.8s |  |
| 63 | `nested_textfields_in_buttons` | 1 | 2.1s |  |
| 64 | `sandbox_type_local_file` | 1 | 2.1s |  |
| 65 | `single_frame` | 1 | 2.1s |  |
| 66 | `strictequals_swf6` | 902 | 8.7s |  |
| 67 | `strictly_equals` | 7 | 2.1s |  |
| 68 | `string_paths_keyevents` | 1 | 2.1s |  |
| 69 | `string_paths_timer` | 1 | 2.1s |  |
| 70 | `swf4_actions_bool` | 96 | 2.2s |  |
| 71 | `swf4_bool` | 4 | 2.1s |  |
| 72 | `swf5_encoding` | 3 | 4.0s |  |
| 73 | `timeline_function_def` | 7 | 2.1s |  |
| 74 | `try_finally_simple` | 16 | 2.0s |  |
| 75 | `typeof_globals` | 7 | 2.0s |  |
| 76 | `undefined_to_string_swf6` | 4 | 2.0s |  |
| 77 | `with_return` | 2 | 2.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**104 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `object_string_coerce_swf5` | 95.4% | 62 | 65 | 3 |  |
| 2 | `object_function` | 90.6% | 29 | 32 | 3 |  |
| 3 | `has_own_property` | 87.5% | 28 | 32 | 4 |  |
| 4 | `swf7_case_sensitive` | 84.1% | 37 | 44 | 7 |  |
| 5 | `array_properties` | 83.3% | 30 | 36 | 6 |  |
| 6 | `as1_constructor_v7` | 82.9% | 29 | 35 | 6 |  |
| 7 | `getproperty_swf4` | 82.1% | 23 | 28 | 5 |  |
| 8 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 9 | `movieclip_prototype_extension` | 80.0% | 4 | 5 | 1 |  |
| 10 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 11 | `as1_constructor_v6` | 77.1% | 27 | 35 | 8 |  |
| 12 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 13 | `stage_object_children` | 75.9% | 63 | 83 | 20 |  |
| 14 | `define_function2` | 75.0% | 6 | 8 | 2 |  |
| 15 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 16 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 17 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 18 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 19 | `object_constructor` | 72.7% | 24 | 33 | 9 |  |
| 20 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 21 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 22 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 23 | `point` | 70.9% | 124 | 175 | 51 |  |
| 24 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 25 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 26 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 27 | `string_coercion` | 69.2% | 81 | 117 | 36 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 28 | `get_variable_in_scope` | 69.0% | 20 | 29 | 9 |  |
| 29 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 30 | `set_variable_scope` | 68.3% | 43 | 63 | 20 |  |
| 31 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 32 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 33 | `primitive_instanceof` | 67.6% | 25 | 37 | 12 |  |
| 34 | `this_swf7` | 67.3% | 37 | 55 | 18 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 35 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 36 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 37 | `delete` | 66.7% | 2 | 3 | 1 |  |
| 38 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 39 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 40 | `goto_both_ways2` | 66.7% | 2 | 3 | 1 |  |
| 41 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 42 | `goto_rewind2` | 66.7% | 2 | 3 | 1 |  |
| 43 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 44 | `o` | 66.7% | 2 | 3 | 1 |  |
| 45 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 46 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 47 | `error` | 65.5% | 38 | 58 | 20 |  |
| 48 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 49 | `getproperty` | 64.3% | 18 | 28 | 10 |  |
| 50 | `getproperty_swf5` | 64.3% | 18 | 28 | 10 |  |
| 51 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 52 | `globals_swf6` | 64.1% | 195 | 304 | 109 |  |
| 53 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 54 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 55 | `globals_swf7` | 63.2% | 192 | 304 | 112 |  |
| 56 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 57 | `globals_swf5` | 61.8% | 188 | 304 | 116 |  |
| 58 | `arguments` | 61.4% | 78 | 127 | 49 |  |
| 59 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 60 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 61 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 62 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 63 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 64 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 65 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 66 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 67 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 68 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 69 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 70 | `swf6_case_insensitive` | 59.1% | 26 | 44 | 18 |  |
| 71 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 72 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 73 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 74 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 75 | `primitive_type_globals` | 57.3% | 319 | 557 | 238 |  |
| 76 | `escape` | 57.1% | 8 | 14 | 6 |  |
| 77 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 78 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 79 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 80 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 81 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 82 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 83 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 84 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 85 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 86 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 87 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 88 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 89 | `movieclip_focusenabled` | 52.5% | 52 | 99 | 47 |  |
| 90 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 91 | `as_set_prop_flags_version` | 51.6% | 16 | 31 | 15 |  |
| 92 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 93 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 94 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 95 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 96 | `goto_advance2` | 50.0% | 1 | 2 | 1 |  |
| 97 | `goto_rewind3` | 50.0% | 1 | 2 | 1 |  |
| 98 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 99 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 100 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 101 | `prototype_delete` | 50.0% | 6 | 12 | 6 |  |
| 102 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 103 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 104 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**9 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `array_constructor` | 4.2s |  |
| 2 | `as2_oop` | 4.3s |  |
| 3 | `device_font_spacing` | 10.2s |  |
| 4 | `duplicate_movie_clip_drawing` | 4.1s |  |
| 5 | `enumerate` | 4.0s |  |
| 6 | `extends_chain` | 4.6s |  |
| 7 | `issue_2166` | 4.1s |  |
| 8 | `path_string` | 4.7s |  |
| 9 | `swf4_actions_coercion_order` | 4.5s |  |

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
| 1 | `parse_float` | runtime timeout (>10s) | 13.3s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.2s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.3s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.5s |  |

## All Output Mismatches

**398 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `object_string_coerce_swf5` | 95.4% | 62/65 | 65 | 62 |  |
| 2 | `object_function` | 90.6% | 29/32 | 32 | 32 |  |
| 3 | `has_own_property` | 87.5% | 28/32 | 32 | 32 |  |
| 4 | `swf7_case_sensitive` | 84.1% | 37/44 | 44 | 44 |  |
| 5 | `array_properties` | 83.3% | 30/36 | 36 | 36 |  |
| 6 | `as1_constructor_v7` | 82.9% | 29/35 | 35 | 35 |  |
| 7 | `getproperty_swf4` | 82.1% | 23/28 | 28 | 28 |  |
| 8 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 9 | `movieclip_prototype_extension` | 80.0% | 4/5 | 5 | 5 |  |
| 10 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 11 | `as1_constructor_v6` | 77.1% | 27/35 | 35 | 35 |  |
| 12 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 13 | `stage_object_children` | 75.9% | 63/83 | 83 | 83 |  |
| 14 | `define_function2` | 75.0% | 6/8 | 8 | 8 |  |
| 15 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 16 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 17 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 18 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 19 | `object_constructor` | 72.7% | 24/33 | 33 | 33 |  |
| 20 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 21 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 22 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 23 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 24 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 25 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 26 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 27 | `string_coercion` | 69.2% | 81/117 | 108 | 117 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 28 | `get_variable_in_scope` | 69.0% | 20/29 | 29 | 29 |  |
| 29 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 30 | `set_variable_scope` | 68.3% | 43/63 | 63 | 58 |  |
| 31 | `object_string_coerce_swf6` | 67.6% | 46/68 | 65 | 68 |  |
| 32 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 33 | `primitive_instanceof` | 67.6% | 25/37 | 37 | 37 |  |
| 34 | `this_swf7` | 67.3% | 37/55 | 55 | 41 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 35 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 36 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 37 | `delete` | 66.7% | 2/3 | 3 | 3 |  |
| 38 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 39 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 40 | `goto_both_ways2` | 66.7% | 2/3 | 2 | 3 |  |
| 41 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 42 | `goto_rewind2` | 66.7% | 2/3 | 2 | 3 |  |
| 43 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 44 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 45 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 46 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 47 | `error` | 65.5% | 38/58 | 58 | 58 |  |
| 48 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 49 | `getproperty` | 64.3% | 18/28 | 28 | 28 |  |
| 50 | `getproperty_swf5` | 64.3% | 18/28 | 28 | 28 |  |
| 51 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 52 | `globals_swf6` | 64.1% | 195/304 | 304 | 304 |  |
| 53 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 54 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 55 | `globals_swf7` | 63.2% | 192/304 | 304 | 304 |  |
| 56 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 57 | `globals_swf5` | 61.8% | 188/304 | 304 | 304 |  |
| 58 | `arguments` | 61.4% | 78/127 | 92 | 127 |  |
| 59 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 60 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 61 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 62 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 63 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 64 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 65 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 66 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 67 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 68 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 69 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 70 | `swf6_case_insensitive` | 59.1% | 26/44 | 44 | 42 |  |
| 71 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 72 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 73 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 74 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 75 | `primitive_type_globals` | 57.3% | 319/557 | 555 | 557 |  |
| 76 | `escape` | 57.1% | 8/14 | 14 | 14 |  |
| 77 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 78 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 79 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 80 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 81 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 82 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 83 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 84 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 85 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 86 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 87 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 88 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 89 | `movieclip_focusenabled` | 52.5% | 52/99 | 99 | 99 |  |
| 90 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 336 |  |
| 91 | `as_set_prop_flags_version` | 51.6% | 16/31 | 29 | 31 |  |
| 92 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 93 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 94 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 95 | `execution_order3` | 50.0% | 2/4 | 3 | 4 |  |
| 96 | `goto_advance2` | 50.0% | 1/2 | 1 | 2 |  |
| 97 | `goto_rewind3` | 50.0% | 1/2 | 1 | 2 |  |
| 98 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 99 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 100 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 101 | `prototype_delete` | 50.0% | 6/12 | 12 | 12 |  |
| 102 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 103 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 104 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 105 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 106 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 107 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 108 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 109 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 110 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 111 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 112 | `new_object_enumerate` | 42.9% | 3/7 | 7 | 7 |  |
| 113 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 114 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 115 | `globals_swf8` | 38.8% | 118/304 | 304 | 304 |  |
| 116 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 117 | `as_broadcaster_undef` | 38.2% | 34/89 | 81 | 89 |  |
| 118 | `localconnection_properties` | 37.5% | 3/8 | 8 | 8 |  |
| 119 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 120 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 121 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 122 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 123 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 124 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 125 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 126 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 127 | `goto_both_ways1` | 33.3% | 1/3 | 1 | 3 |  |
| 128 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 129 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 130 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 131 | `define_function2_preload` | 30.8% | 4/13 | 12 | 13 |  |
| 132 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 133 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 134 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 135 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 136 | `define_local_with_paths` | 27.8% | 15/54 | 44 | 54 |  |
| 137 | `this_swf5` | 27.3% | 15/55 | 55 | 41 |  |
| 138 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 139 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 140 | `this_swf6` | 25.5% | 14/55 | 55 | 41 |  |
| 141 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 142 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 143 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 144 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 145 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 146 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 147 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 148 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 149 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 150 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 151 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 152 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 153 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 154 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 155 | `unescape` | 20.9% | 9/43 | 42 | 43 |  |
| 156 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 157 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 158 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 159 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 160 | `global_array` | 20.0% | 1/5 | 5 | 4 |  |
| 161 | `xml_attributes_read` | 20.0% | 1/5 | 3 | 5 |  |
| 162 | `frame_size_translated_negative` | 19.0% | 4/21 | 20 | 21 |  |
| 163 | `frame_size_translated_positive` | 19.0% | 4/21 | 20 | 21 |  |
| 164 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 165 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 166 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 167 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 168 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 169 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 170 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 171 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 172 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 173 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 174 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 175 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 176 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 177 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 178 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 179 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 180 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 181 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 182 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 183 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 184 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 185 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 186 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 187 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 188 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 189 | `string_paths_other` | 11.1% | 4/36 | 28 | 36 |  |
| 190 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 191 | `with` | 10.3% | 7/68 | 68 | 49 |  |
| 192 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 193 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 194 | `this_scoping` | 9.6% | 5/52 | 50 | 52 |  |
| 195 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 196 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 197 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 198 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 199 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 200 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 201 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 202 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 203 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 204 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 205 | `funky_function_calls` | 7.1% | 4/56 | 12 | 56 |  |
| 206 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 207 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 208 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 209 | `array_enumerate` | 6.2% | 1/16 | 16 | 4 |  |
| 210 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 211 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 212 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 213 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 214 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 215 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 216 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 217 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 218 | `register_class` | 4.5% | 3/66 | 27 | 66 |  |
| 219 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 220 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 221 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 222 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 223 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 224 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 225 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 226 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 227 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 228 | `with_variable_scopes` | 1.5% | 1/68 | 68 | 43 |  |
| 229 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 230 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 231 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 232 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 233 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 234 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 235 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 236 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 237 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 238 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 239 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 240 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 241 | `localconnection` | 0.2% | 1/580 | 1 | 580 |  |
| 242 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 243 | `array_sort_random` | 0.0% | 0/443 | 1 | 443 |  |
| 244 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 245 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 246 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 1 | 40 |  |
| 247 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 248 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 249 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 250 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 251 | `asfunction` | 0.0% | 0/11 | 1 | 11 |  |
| 252 | `asnew` | 0.0% | 0/34 | 1 | 34 |  |
| 253 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 1 | 2 |  |
| 254 | `boxed_primitives` | 0.0% | 0/24 | 1 | 24 |  |
| 255 | `button_children` | 0.0% | 0/8 | 1 | 8 |  |
| 256 | `button_goto` | 0.0% | 0/4 | 1 | 4 |  |
| 257 | `button_order` | 0.0% | 0/2 | 1 | 2 |  |
| 258 | `button_properties_special_cases` | 0.0% | 0/22 | 1 | 22 |  |
| 259 | `button_v5` | 0.0% | 0/18 | 1 | 18 |  |
| 260 | `button_v6` | 0.0% | 0/18 | 1 | 18 |  |
| 261 | `call` | 0.0% | 0/63 | 1 | 63 |  |
| 262 | `call_method_empty_name` | 0.0% | 0/1 | 1 | 1 |  |
| 263 | `clip_constructors` | 0.0% | 0/8 | 1 | 8 |  |
| 264 | `clip_event_propagation_order` | 0.0% | 0/17 | 1 | 17 |  |
| 265 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 266 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 267 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 268 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 1 | 129 |  |
| 269 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 1 | 17 |  |
| 270 | `color` | 0.0% | 0/57 | 1 | 57 |  |
| 271 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 272 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 273 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 274 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 275 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 276 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 277 | `duplicate_movie_clip` | 0.0% | 0/20 | 1 | 20 |  |
| 278 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 279 | `edittext_html_roundtrip` | 0.0% | 0/17 | 1 | 17 |  |
| 280 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 281 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 282 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 283 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 284 | `extends_native_type` | 0.0% | 0/11 | 1 | 11 |  |
| 285 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 286 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 287 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 288 | `file_reference_browse_cancel` | 0.0% | 0/21 | 1 | 21 |  |
| 289 | `function_base_clip` | 0.0% | 0/8 | 1 | 8 |  |
| 290 | `function_base_clip_readded` | 0.0% | 0/11 | 1 | 11 |  |
| 291 | `function_suppress_and_preload` | 0.0% | 0/28 | 1 | 28 |  |
| 292 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 293 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 294 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 295 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 296 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 297 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 1 | 1145 |  |
| 298 | `global_swf6_7_8` | 0.0% | 0/15 | 1 | 15 |  |
| 299 | `goto_execution_order2` | 0.0% | 0/2 | 1 | 2 |  |
| 300 | `goto_frame` | 0.0% | 0/12 | 1 | 12 |  |
| 301 | `goto_frame2` | 0.0% | 0/44 | 1 | 44 |  |
| 302 | `goto_label` | 0.0% | 0/17 | 1 | 17 |  |
| 303 | `goto_methods` | 0.0% | 0/40 | 1 | 40 |  |
| 304 | `hittest_lockroot` | 0.0% | 0/15 | 1 | 15 |  |
| 305 | `hittest_morph` | 0.0% | 0/70 | 1 | 70 |  |
| 306 | `hittest_morph_input` | 0.0% | 0/1 | 1 | 1 |  |
| 307 | `hittest_winding_rule` | 0.0% | 0/12 | 1 | 12 |  |
| 308 | `init_array_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 309 | `init_object_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 310 | `init_object_order` | 0.0% | 0/15 | 1 | 15 |  |
| 311 | `input_dead_keys_windows` | 0.0% | 0/15 | 1 | 15 |  |
| 312 | `instanceof_coercions` | 0.0% | 0/88 | 1 | 88 |  |
| 313 | `interface_implements_op` | 0.0% | 0/47 | 1 | 47 |  |
| 314 | `issue_1104` | 0.0% | 0/2 | 1 | 2 |  |
| 315 | `issue_2084` | 0.0% | 0/16 | 1 | 16 |  |
| 316 | `issue_2870` | 0.0% | 0/3 | 1 | 3 |  |
| 317 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 318 | `issue_9327` | 0.0% | 0/2 | 1 | 2 |  |
| 319 | `issue_9885` | 0.0% | 0/2 | 1 | 2 |  |
| 320 | `lock_root` | 0.0% | 0/1 | 1 | 1 |  |
| 321 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 1 | 35 |  |
| 322 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 323 | `movieclip_gettextsnapshot` | 0.0% | 0/112 | 21 | 112 |  |
| 324 | `movieclip_in_removed_button` | 0.0% | 0/4 | 1 | 4 |  |
| 325 | `movieclip_init_object` | 0.0% | 0/5 | 1 | 5 |  |
| 326 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 327 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 1 | 4 |  |
| 328 | `named_shapes` | 0.0% | 0/14 | 1 | 14 |  |
| 329 | `native_double_construct` | 0.0% | 0/12 | 1 | 12 |  |
| 330 | `native_objects_swf6` | 0.0% | 0/84 | 1 | 84 |  |
| 331 | `native_objects_swf7` | 0.0% | 0/84 | 1 | 84 |  |
| 332 | `native_objects_swf8` | 0.0% | 0/84 | 1 | 84 |  |
| 333 | `native_subclasses` | 0.0% | 0/191 | 1 | 191 |  |
| 334 | `netconnection_send_remote` | 0.0% | 0/50 | 1 | 50 |  |
| 335 | `new_method_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 336 | `new_object_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 337 | `object_properties` | 0.0% | 0/31 | 1 | 31 |  |
| 338 | `object_resolve` | 0.0% | 0/38 | 1 | 38 |  |
| 339 | `on_construct` | 0.0% | 0/25 | 1 | 25 |  |
| 340 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 341 | `place_and_lookup` | 0.0% | 0/30 | 1 | 30 |  |
| 342 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 343 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 1 |  |
| 344 | `register_class_return_value` | 0.0% | 0/16 | 1 | 16 |  |
| 345 | `register_class_swf6` | 0.0% | 0/37 | 1 | 37 |  |
| 346 | `register_class_with_sound` | 0.0% | 0/11 | 1 | 11 |  |
| 347 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 348 | `removed_target_clip_scope` | 0.0% | 0/35 | 1 | 35 |  |
| 349 | `resolve_different_root` | 0.0% | 0/2 | 1 | 2 |  |
| 350 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 351 | `root_onload` | 0.0% | 0/1 | 1 | 1 |  |
| 352 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 353 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 354 | `selection` | 0.0% | 0/454 | 1 | 454 |  |
| 355 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 356 | `slash_syntax` | 0.0% | 0/14 | 1 | 14 |  |
| 357 | `stage_object_enumerate` | 0.0% | 0/4 | 1 | 4 |  |
| 358 | `string_methods_negative_args` | 0.0% | 0/240 | 1 | 240 |  |
| 359 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 360 | `string_paths_eval` | 0.0% | 0/4 | 1 | 4 |  |
| 361 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 362 | `string_paths_unload` | 0.0% | 0/1 | 1 | 1 |  |
| 363 | `string_paths_variable_scopes` | 0.0% | 0/5 | 1 | 5 |  |
| 364 | `stylesheet` | 0.0% | 0/283 | 1 | 283 |  |
| 365 | `super_edge_cases` | 0.0% | 0/39 | 1 | 39 |  |
| 366 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 367 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 368 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 369 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 370 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 371 | `target_clip_swf5` | 0.0% | 0/2 | 1 | 2 |  |
| 372 | `target_clip_swf6` | 0.0% | 0/2 | 1 | 2 |  |
| 373 | `target_path` | 0.0% | 0/14 | 1 | 14 |  |
| 374 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 375 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 376 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 377 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 |  |
| 378 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 379 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 380 | `timer_run_actions` | 0.0% | 0/18 | 1 | 18 |  |
| 381 | `typeof` | 0.0% | 0/22 | 1 | 22 |  |
| 382 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 383 | `unload_clip_event` | 0.0% | 0/4 | 1 | 4 |  |
| 384 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 385 | `use_hand_cursor` | 0.0% | 0/8 | 1 | 8 |  |
| 386 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 387 | `watch` | 0.0% | 0/117 | 1 | 117 |  |
| 388 | `watch_textfield` | 0.0% | 0/12 | 1 | 12 |  |
| 389 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 |  |
| 390 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 391 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 392 | `xml_ignore_comments` | 0.0% | 0/21 | 1 | 21 |  |
| 393 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 394 | `xml_reparenting` | 0.0% | 0/14 | 1 | 14 |  |
| 395 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 396 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 397 | `xml_unescaping` | 0.0% | 0/23 | 1 | 23 |  |
| 398 | `xmlnode_proto` | 0.0% | 0/1 | 1 | 1 |  |
