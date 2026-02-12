# Ruffle Test Results (Filtered)

**Date**: 2026-02-11 17:39 UTC

**Git SHA**: `79c7aeee9d`

**Run Duration**: 26m 46s

**Filtered**: 125 tests ignored out of 616 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 491 |
| Passing | **76** (15.5%) |
| Failing | 415 |
| Total expected lines | 74583 |
| Matching lines | 31159 (41.8%) |
| Mismatched lines | 43424 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 392 | 94.5% |
| Runtime Error | 10 | 2.4% |
| Segfault | 9 | 2.2% |
| Timeout | 4 | 1.0% |

## Passing Tests

**76 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.2s |  |
| 2 | `action_to_integer` | 28 | 2.2s |  |
| 3 | `add` | 28 | 2.1s |  |
| 4 | `add2` | 354 | 2.6s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.1s |  |
| 6 | `add_swf5` | 28 | 2.3s |  |
| 7 | `array_concat` | 98 | 2.3s |  |
| 8 | `array_slice` | 34 | 2.2s |  |
| 9 | `array_splice` | 207 | 3.0s |  |
| 10 | `array_trivial` | 209 | 2.7s |  |
| 11 | `as_broadcaster_initialize` | 10 | 2.1s |  |
| 12 | `as_set_prop_flags_version_swf5` | 1 | 2.2s |  |
| 13 | `bad_swf_tag_past_eof` | 1 | 2.0s |  |
| 14 | `bitand` | 1058 | 11.3s |  |
| 15 | `bitmap_data_colortransform` | 1 | 2.4s |  |
| 16 | `bitmap_data_fillrect` | 1 | 2.3s |  |
| 17 | `bitmap_data_perlinnoise` | 1 | 3.0s |  |
| 18 | `bitmap_data_pixeldissolve_image` | 1 | 2.6s |  |
| 19 | `bitmapdata_applyfilter_colormatrix` | 1 | 2.1s |  |
| 20 | `bitor` | 1058 | 11.4s |  |
| 21 | `biturshift` | 14 | 2.2s |  |
| 22 | `biturshift_swf8` | 14 | 2.0s |  |
| 23 | `bitxor` | 1058 | 10.5s |  |
| 24 | `catch_references_registers` | 2 | 2.0s |  |
| 25 | `define_function_case_sensitive` | 2 | 2.0s |  |
| 26 | `divide_swf4` | 107 | 2.2s |  |
| 27 | `do_init_action` | 3 | 2.0s |  |
| 28 | `equals` | 32 | 2.1s |  |
| 29 | `equals2_swf5` | 926 | 10.6s |  |
| 30 | `equals2_swf6` | 926 | 10.4s |  |
| 31 | `equals2_swf7` | 926 | 10.4s |  |
| 32 | `equals_swf4` | 665 | 5.8s |  |
| 33 | `equals_swf4_alt` | 32 | 2.0s |  |
| 34 | `equals_swf5` | 32 | 2.1s |  |
| 35 | `global_is_bare` | 7 | 2.1s |  |
| 36 | `goto_execution_order` | 2 | 2.0s |  |
| 37 | `goto_rewind1` | 1 | 2.0s |  |
| 38 | `greater_swf6` | 1175 | 11.2s |  |
| 39 | `greater_swf7` | 1175 | 11.0s |  |
| 40 | `greaterthan_swf5` | 1 | 2.0s |  |
| 41 | `greaterthan_swf8` | 1 | 2.0s |  |
| 42 | `infinite_recursion_function_in_setter` | 131 | 2.0s |  |
| 43 | `infinite_recursion_virtual_property` | 67 | 2.0s |  |
| 44 | `issue_1086` | 1 | 2.0s |  |
| 45 | `issue_1671` | 1 | 2.0s |  |
| 46 | `issue_3446` | 1 | 2.0s |  |
| 47 | `issue_4377` | 2 | 2.0s |  |
| 48 | `lessthan` | 41 | 2.1s |  |
| 49 | `lessthan2_swf5` | 1226 | 11.7s |  |
| 50 | `lessthan2_swf6` | 1226 | 11.7s |  |
| 51 | `lessthan2_swf7` | 1226 | 11.7s |  |
| 52 | `lessthan_swf4` | 902 | 7.4s |  |
| 53 | `lessthan_swf4_alt` | 41 | 2.1s |  |
| 54 | `lessthan_swf5` | 41 | 2.1s |  |
| 55 | `logical_ops_swf4` | 90 | 2.1s |  |
| 56 | `logical_ops_swf8` | 108 | 2.1s |  |
| 57 | `looping` | 6 | 2.0s |  |
| 58 | `mask_reapply` | 1 | 2.0s |  |
| 59 | `mask_with_drawing` | 1 | 2.0s |  |
| 60 | `movieclip_begin_gradient_fill` | 1 | 2.7s |  |
| 61 | `movieclip_line_gradient_style` | 1 | 2.6s |  |
| 62 | `nested_textfields_in_buttons` | 1 | 2.0s |  |
| 63 | `sandbox_type_local_file` | 1 | 1.9s |  |
| 64 | `single_frame` | 1 | 2.0s |  |
| 65 | `strictequals_swf6` | 902 | 8.2s |  |
| 66 | `strictly_equals` | 7 | 2.0s |  |
| 67 | `string_paths_keyevents` | 1 | 2.0s |  |
| 68 | `string_paths_timer` | 1 | 2.0s |  |
| 69 | `swf4_actions_bool` | 96 | 2.1s |  |
| 70 | `swf4_bool` | 4 | 2.0s |  |
| 71 | `swf5_encoding` | 3 | 2.2s |  |
| 72 | `timeline_function_def` | 7 | 2.1s |  |
| 73 | `try_finally_simple` | 16 | 2.0s |  |
| 74 | `typeof_globals` | 7 | 1.9s |  |
| 75 | `undefined_to_string_swf6` | 4 | 1.9s |  |
| 76 | `with_return` | 2 | 1.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**96 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `object_function` | 87.5% | 28 | 32 | 4 |  |
| 2 | `swf7_case_sensitive` | 84.1% | 37 | 44 | 7 |  |
| 3 | `array_properties` | 83.3% | 30 | 36 | 6 |  |
| 4 | `getproperty_swf4` | 82.1% | 23 | 28 | 5 |  |
| 5 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 6 | `movieclip_prototype_extension` | 80.0% | 4 | 5 | 1 |  |
| 7 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 8 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 9 | `define_function2` | 75.0% | 6 | 8 | 2 |  |
| 10 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 11 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 12 | `stage_object_children` | 73.5% | 61 | 83 | 22 |  |
| 13 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 14 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 15 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 16 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 17 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 18 | `point` | 70.9% | 124 | 175 | 51 |  |
| 19 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 20 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 21 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 22 | `get_variable_in_scope` | 69.0% | 20 | 29 | 9 |  |
| 23 | `set_variable_scope` | 68.3% | 43 | 63 | 20 |  |
| 24 | `primitive_instanceof` | 67.6% | 25 | 37 | 12 |  |
| 25 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 26 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 27 | `delete` | 66.7% | 2 | 3 | 1 |  |
| 28 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 29 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 30 | `goto_both_ways2` | 66.7% | 2 | 3 | 1 |  |
| 31 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 32 | `goto_rewind2` | 66.7% | 2 | 3 | 1 |  |
| 33 | `issue_768` | 66.7% | 2 | 3 | 1 | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 34 | `o` | 66.7% | 2 | 3 | 1 |  |
| 35 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 36 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 37 | `as1_constructor_v6` | 65.7% | 23 | 35 | 12 |  |
| 38 | `as1_constructor_v7` | 65.7% | 23 | 35 | 12 |  |
| 39 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 40 | `getproperty` | 64.3% | 18 | 28 | 10 |  |
| 41 | `getproperty_swf5` | 64.3% | 18 | 28 | 10 |  |
| 42 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 43 | `error` | 63.8% | 37 | 58 | 21 |  |
| 44 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 45 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 46 | `globals_swf6` | 63.2% | 192 | 304 | 112 |  |
| 47 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 48 | `globals_swf7` | 62.2% | 189 | 304 | 115 |  |
| 49 | `arguments` | 61.4% | 78 | 127 | 49 |  |
| 50 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 51 | `mutable_this` | 61.1% | 11 | 18 | 7 |  |
| 52 | `globals_swf5` | 60.9% | 185 | 304 | 119 |  |
| 53 | `object_constructor` | 60.6% | 20 | 33 | 13 |  |
| 54 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 55 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 56 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 57 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 58 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 59 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 60 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 61 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 62 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 63 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 64 | `swf6_case_insensitive` | 59.1% | 26 | 44 | 18 |  |
| 65 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 66 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 67 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 68 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 69 | `primitive_type_globals` | 57.3% | 319 | 557 | 238 |  |
| 70 | `escape` | 57.1% | 8 | 14 | 6 |  |
| 71 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 72 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 73 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 74 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 75 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 76 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 77 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 78 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 79 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 80 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 81 | `this_swf7` | 52.7% | 29 | 55 | 26 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 82 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 83 | `movieclip_focusenabled` | 52.5% | 52 | 99 | 47 |  |
| 84 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 85 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 86 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 87 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 88 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 89 | `goto_advance2` | 50.0% | 1 | 2 | 1 |  |
| 90 | `goto_rewind3` | 50.0% | 1 | 2 | 1 |  |
| 91 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 92 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 93 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 94 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 95 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 96 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**9 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `array_constructor` | 4.3s |  |
| 2 | `as2_oop` | 4.3s |  |
| 3 | `device_font_spacing` | 10.0s |  |
| 4 | `duplicate_movie_clip_drawing` | 4.0s |  |
| 5 | `enumerate` | 4.2s |  |
| 6 | `extends_chain` | 4.8s |  |
| 7 | `issue_2166` | 4.1s |  |
| 8 | `path_string` | 4.5s |  |
| 9 | `swf4_actions_coercion_order` | 4.2s |  |

## Runtime Errors

**10 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `array_length` | exit code -6 | 4.4s |  |
| 2 | `array_sort` | exit code -6 | 4.4s |  |
| 3 | `as_set_prop_flags` | exit code -6 | 4.3s |  |
| 4 | `as_set_prop_flags_version` | exit code -6 | 2.4s |  |
| 5 | `funky_function_calls` | exit code -6 | 2.3s |  |
| 6 | `has_own_property` | exit code -6 | 2.2s |  |
| 7 | `prototype_enumerate` | exit code -6 | 2.1s |  |
| 8 | `text_format` | exit code -6 | 4.5s |  |
| 9 | `uncaught_exception` | exit code 1 | 1.9s |  |
| 10 | `uncaught_exception_bubbled` | exit code 1 | 1.9s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.2s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.1s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.0s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.7s |  |

## All Output Mismatches

**392 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `object_function` | 87.5% | 28/32 | 32 | 32 |  |
| 2 | `swf7_case_sensitive` | 84.1% | 37/44 | 44 | 44 |  |
| 3 | `array_properties` | 83.3% | 30/36 | 36 | 36 |  |
| 4 | `getproperty_swf4` | 82.1% | 23/28 | 28 | 28 |  |
| 5 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 6 | `movieclip_prototype_extension` | 80.0% | 4/5 | 5 | 5 |  |
| 7 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 8 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 9 | `define_function2` | 75.0% | 6/8 | 8 | 8 |  |
| 10 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 11 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 12 | `stage_object_children` | 73.5% | 61/83 | 83 | 83 |  |
| 13 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 14 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 15 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 16 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 17 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 18 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 19 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 20 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 21 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 22 | `get_variable_in_scope` | 69.0% | 20/29 | 29 | 29 |  |
| 23 | `set_variable_scope` | 68.3% | 43/63 | 63 | 58 |  |
| 24 | `primitive_instanceof` | 67.6% | 25/37 | 37 | 37 |  |
| 25 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 26 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 27 | `delete` | 66.7% | 2/3 | 3 | 3 |  |
| 28 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 29 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 30 | `goto_both_ways2` | 66.7% | 2/3 | 2 | 3 |  |
| 31 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 32 | `goto_rewind2` | 66.7% | 2/3 | 2 | 3 |  |
| 33 | `issue_768` | 66.7% | 2/3 | 3 | 3 | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 34 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 35 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 36 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 37 | `as1_constructor_v6` | 65.7% | 23/35 | 35 | 35 |  |
| 38 | `as1_constructor_v7` | 65.7% | 23/35 | 35 | 35 |  |
| 39 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 40 | `getproperty` | 64.3% | 18/28 | 28 | 28 |  |
| 41 | `getproperty_swf5` | 64.3% | 18/28 | 28 | 28 |  |
| 42 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 43 | `error` | 63.8% | 37/58 | 58 | 58 |  |
| 44 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 45 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 46 | `globals_swf6` | 63.2% | 192/304 | 304 | 304 |  |
| 47 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 48 | `globals_swf7` | 62.2% | 189/304 | 304 | 304 |  |
| 49 | `arguments` | 61.4% | 78/127 | 92 | 127 |  |
| 50 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 51 | `mutable_this` | 61.1% | 11/18 | 18 | 18 |  |
| 52 | `globals_swf5` | 60.9% | 185/304 | 304 | 304 |  |
| 53 | `object_constructor` | 60.6% | 20/33 | 33 | 33 |  |
| 54 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 55 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 56 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 57 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 58 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 59 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 60 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 61 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 62 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 63 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 64 | `swf6_case_insensitive` | 59.1% | 26/44 | 44 | 42 |  |
| 65 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 66 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 67 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 68 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 69 | `primitive_type_globals` | 57.3% | 319/557 | 555 | 557 |  |
| 70 | `escape` | 57.1% | 8/14 | 14 | 14 |  |
| 71 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 72 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 73 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 74 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 75 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 76 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 77 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 78 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 79 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 80 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 81 | `this_swf7` | 52.7% | 29/55 | 55 | 41 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 82 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 83 | `movieclip_focusenabled` | 52.5% | 52/99 | 99 | 99 |  |
| 84 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 336 |  |
| 85 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 86 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 87 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 88 | `execution_order3` | 50.0% | 2/4 | 3 | 4 |  |
| 89 | `goto_advance2` | 50.0% | 1/2 | 1 | 2 |  |
| 90 | `goto_rewind3` | 50.0% | 1/2 | 1 | 2 |  |
| 91 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 92 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 93 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 94 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 95 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 96 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 97 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 98 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 99 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 100 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 101 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 102 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 103 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 104 | `new_object_enumerate` | 42.9% | 3/7 | 5 | 7 |  |
| 105 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 106 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 107 | `define_function2_preload` | 38.5% | 5/13 | 12 | 13 |  |
| 108 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 109 | `as_broadcaster_undef` | 38.2% | 34/89 | 81 | 89 |  |
| 110 | `globals_swf8` | 37.8% | 115/304 | 304 | 304 |  |
| 111 | `localconnection_properties` | 37.5% | 3/8 | 8 | 8 |  |
| 112 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 113 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 114 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 115 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 116 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 117 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 118 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 119 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 120 | `goto_both_ways1` | 33.3% | 1/3 | 1 | 3 |  |
| 121 | `prototype_delete` | 33.3% | 4/12 | 12 | 12 |  |
| 122 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 123 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 124 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 125 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 126 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 127 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 128 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 129 | `define_local_with_paths` | 27.8% | 15/54 | 44 | 54 |  |
| 130 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 131 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 132 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 133 | `define_function2_preload_order` | 25.0% | 1/4 | 2 | 4 |  |
| 134 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 135 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 136 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 137 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 138 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 139 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 140 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 141 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 142 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 143 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 144 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 145 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 146 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 147 | `unescape` | 20.9% | 9/43 | 42 | 43 |  |
| 148 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 149 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 150 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 151 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 152 | `global_array` | 20.0% | 1/5 | 5 | 4 |  |
| 153 | `xml_attributes_read` | 20.0% | 1/5 | 3 | 5 |  |
| 154 | `object_string_coerce_swf5` | 19.4% | 12/62 | 57 | 62 |  |
| 155 | `object_string_coerce_swf6` | 19.1% | 13/68 | 57 | 68 |  |
| 156 | `frame_size_translated_negative` | 19.0% | 4/21 | 20 | 21 |  |
| 157 | `frame_size_translated_positive` | 19.0% | 4/21 | 20 | 21 |  |
| 158 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 159 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 160 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 161 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 162 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 163 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 164 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 165 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 166 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 167 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 168 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 169 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 170 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 171 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 172 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 173 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 174 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 175 | `this_swf5` | 12.7% | 7/55 | 55 | 41 |  |
| 176 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 177 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 178 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 179 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 180 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 181 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 182 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 183 | `this_swf6` | 10.9% | 6/55 | 55 | 41 |  |
| 184 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 185 | `with` | 10.3% | 7/68 | 68 | 49 |  |
| 186 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 187 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 188 | `this_scoping` | 9.6% | 5/52 | 50 | 52 |  |
| 189 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 190 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 191 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 192 | `string_coercion` | 8.5% | 10/117 | 89 | 117 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 193 | `string_paths_other` | 8.3% | 3/36 | 28 | 36 |  |
| 194 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 195 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 196 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 197 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 198 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 199 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 200 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 201 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 202 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 203 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 204 | `array_enumerate` | 6.2% | 1/16 | 16 | 4 |  |
| 205 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 206 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 207 | `object_prototypes` | 5.4% | 4/74 | 71 | 74 |  |
| 208 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 209 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 210 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 211 | `swf5_no_closure` | 5.3% | 1/19 | 8 | 19 |  |
| 212 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 213 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 214 | `register_class` | 4.5% | 3/66 | 27 | 66 |  |
| 215 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 216 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 217 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 218 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 219 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 220 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 221 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 222 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 223 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 224 | `with_variable_scopes` | 1.5% | 1/68 | 68 | 43 |  |
| 225 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 226 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 227 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 228 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 229 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 230 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 231 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 232 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 233 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 234 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 235 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 236 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 237 | `localconnection` | 0.2% | 1/580 | 1 | 580 |  |
| 238 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 239 | `array_sort_random` | 0.0% | 0/443 | 1 | 443 |  |
| 240 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 241 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 242 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 1 | 40 |  |
| 243 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 244 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 245 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 246 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 247 | `asfunction` | 0.0% | 0/11 | 1 | 11 |  |
| 248 | `asnew` | 0.0% | 0/34 | 1 | 34 |  |
| 249 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 1 | 2 |  |
| 250 | `boxed_primitives` | 0.0% | 0/24 | 1 | 24 |  |
| 251 | `button_children` | 0.0% | 0/8 | 1 | 8 |  |
| 252 | `button_goto` | 0.0% | 0/4 | 1 | 4 |  |
| 253 | `button_order` | 0.0% | 0/2 | 1 | 2 |  |
| 254 | `button_properties_special_cases` | 0.0% | 0/22 | 1 | 22 |  |
| 255 | `button_v5` | 0.0% | 0/18 | 1 | 18 |  |
| 256 | `button_v6` | 0.0% | 0/18 | 1 | 18 |  |
| 257 | `call` | 0.0% | 0/63 | 1 | 63 |  |
| 258 | `call_method_empty_name` | 0.0% | 0/1 | 1 | 1 |  |
| 259 | `clip_constructors` | 0.0% | 0/8 | 1 | 8 |  |
| 260 | `clip_event_propagation_order` | 0.0% | 0/17 | 1 | 17 |  |
| 261 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 262 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 263 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 264 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 1 | 129 |  |
| 265 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 1 | 17 |  |
| 266 | `color` | 0.0% | 0/57 | 1 | 57 |  |
| 267 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 268 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 269 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 270 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 271 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 272 | `duplicate_movie_clip` | 0.0% | 0/20 | 1 | 20 |  |
| 273 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 274 | `edittext_html_roundtrip` | 0.0% | 0/17 | 1 | 17 |  |
| 275 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 276 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 277 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 278 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 279 | `extends_native_type` | 0.0% | 0/11 | 1 | 11 |  |
| 280 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 281 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 282 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 283 | `file_reference_browse_cancel` | 0.0% | 0/21 | 1 | 21 |  |
| 284 | `function_base_clip` | 0.0% | 0/8 | 1 | 8 |  |
| 285 | `function_base_clip_readded` | 0.0% | 0/11 | 1 | 11 |  |
| 286 | `function_suppress_and_preload` | 0.0% | 0/28 | 1 | 28 |  |
| 287 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 288 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 289 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 290 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 291 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 292 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 1 | 1145 |  |
| 293 | `global_swf6_7_8` | 0.0% | 0/15 | 1 | 15 |  |
| 294 | `goto_execution_order2` | 0.0% | 0/2 | 1 | 2 |  |
| 295 | `goto_frame` | 0.0% | 0/12 | 1 | 12 |  |
| 296 | `goto_frame2` | 0.0% | 0/44 | 1 | 44 |  |
| 297 | `goto_label` | 0.0% | 0/17 | 1 | 17 |  |
| 298 | `goto_methods` | 0.0% | 0/40 | 1 | 40 |  |
| 299 | `hittest_lockroot` | 0.0% | 0/15 | 1 | 15 |  |
| 300 | `hittest_morph` | 0.0% | 0/70 | 1 | 70 |  |
| 301 | `hittest_morph_input` | 0.0% | 0/1 | 1 | 1 |  |
| 302 | `hittest_winding_rule` | 0.0% | 0/12 | 1 | 12 |  |
| 303 | `init_array_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 304 | `init_object_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 305 | `init_object_order` | 0.0% | 0/15 | 1 | 15 |  |
| 306 | `input_dead_keys_windows` | 0.0% | 0/15 | 1 | 15 |  |
| 307 | `instanceof_coercions` | 0.0% | 0/88 | 1 | 88 |  |
| 308 | `interface_implements_op` | 0.0% | 0/47 | 1 | 47 |  |
| 309 | `issue_1104` | 0.0% | 0/2 | 1 | 2 |  |
| 310 | `issue_2084` | 0.0% | 0/16 | 1 | 16 |  |
| 311 | `issue_2870` | 0.0% | 0/3 | 1 | 3 |  |
| 312 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 313 | `issue_9327` | 0.0% | 0/2 | 1 | 2 |  |
| 314 | `issue_9885` | 0.0% | 0/2 | 1 | 2 |  |
| 315 | `lock_root` | 0.0% | 0/1 | 1 | 1 |  |
| 316 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 1 | 35 |  |
| 317 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 318 | `movieclip_gettextsnapshot` | 0.0% | 0/112 | 21 | 112 |  |
| 319 | `movieclip_in_removed_button` | 0.0% | 0/4 | 1 | 4 |  |
| 320 | `movieclip_init_object` | 0.0% | 0/5 | 1 | 5 |  |
| 321 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 322 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 1 | 4 |  |
| 323 | `named_shapes` | 0.0% | 0/14 | 1 | 14 |  |
| 324 | `native_double_construct` | 0.0% | 0/12 | 1 | 12 |  |
| 325 | `native_objects_swf6` | 0.0% | 0/84 | 1 | 84 |  |
| 326 | `native_objects_swf7` | 0.0% | 0/84 | 1 | 84 |  |
| 327 | `native_objects_swf8` | 0.0% | 0/84 | 1 | 84 |  |
| 328 | `native_subclasses` | 0.0% | 0/191 | 1 | 191 |  |
| 329 | `netconnection_send_remote` | 0.0% | 0/50 | 1 | 50 |  |
| 330 | `new_method_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 331 | `new_object_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 332 | `object_properties` | 0.0% | 0/31 | 1 | 31 |  |
| 333 | `object_resolve` | 0.0% | 0/38 | 1 | 38 |  |
| 334 | `on_construct` | 0.0% | 0/25 | 1 | 25 |  |
| 335 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 336 | `place_and_lookup` | 0.0% | 0/30 | 1 | 30 |  |
| 337 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 1 |  |
| 338 | `register_class_return_value` | 0.0% | 0/16 | 1 | 16 |  |
| 339 | `register_class_swf6` | 0.0% | 0/37 | 1 | 37 |  |
| 340 | `register_class_with_sound` | 0.0% | 0/11 | 1 | 11 |  |
| 341 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 342 | `removed_target_clip_scope` | 0.0% | 0/35 | 1 | 35 |  |
| 343 | `resolve_different_root` | 0.0% | 0/2 | 1 | 2 |  |
| 344 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 345 | `root_onload` | 0.0% | 0/1 | 1 | 1 |  |
| 346 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 347 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 348 | `selection` | 0.0% | 0/454 | 1 | 454 |  |
| 349 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 350 | `slash_syntax` | 0.0% | 0/14 | 1 | 14 |  |
| 351 | `stage_object_enumerate` | 0.0% | 0/4 | 1 | 4 |  |
| 352 | `string_methods_negative_args` | 0.0% | 0/240 | 1 | 240 |  |
| 353 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 354 | `string_paths_eval` | 0.0% | 0/4 | 1 | 4 |  |
| 355 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 356 | `string_paths_unload` | 0.0% | 0/1 | 1 | 1 |  |
| 357 | `string_paths_variable_scopes` | 0.0% | 0/5 | 1 | 5 |  |
| 358 | `stylesheet` | 0.0% | 0/283 | 1 | 283 |  |
| 359 | `super_edge_cases` | 0.0% | 0/39 | 1 | 39 |  |
| 360 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 361 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 362 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 363 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 364 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 365 | `target_clip_swf5` | 0.0% | 0/2 | 1 | 2 |  |
| 366 | `target_clip_swf6` | 0.0% | 0/2 | 1 | 2 |  |
| 367 | `target_path` | 0.0% | 0/14 | 1 | 14 |  |
| 368 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 369 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 370 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 371 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 |  |
| 372 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 373 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 374 | `timer_run_actions` | 0.0% | 0/18 | 1 | 18 |  |
| 375 | `typeof` | 0.0% | 0/22 | 1 | 22 |  |
| 376 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 377 | `unload_clip_event` | 0.0% | 0/4 | 1 | 4 |  |
| 378 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 379 | `use_hand_cursor` | 0.0% | 0/8 | 1 | 8 |  |
| 380 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 381 | `watch` | 0.0% | 0/117 | 1 | 117 |  |
| 382 | `watch_textfield` | 0.0% | 0/12 | 1 | 12 |  |
| 383 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 |  |
| 384 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 385 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 386 | `xml_ignore_comments` | 0.0% | 0/21 | 1 | 21 |  |
| 387 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 388 | `xml_reparenting` | 0.0% | 0/14 | 1 | 14 |  |
| 389 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 390 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 391 | `xml_unescaping` | 0.0% | 0/23 | 1 | 23 |  |
| 392 | `xmlnode_proto` | 0.0% | 0/1 | 1 | 1 |  |
