# Ruffle Test Results (Filtered)

**Date**: 2026-02-13 00:53 UTC

**Git SHA**: `48407dff58`

**Run Duration**: 30m 60s

**Filtered**: 125 tests ignored out of 616 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 491 |
| Passing | **98** (20.0%) |
| Failing | 393 |
| Total expected lines | 76785 |
| Matching lines | 32219 (42.0%) |
| Mismatched lines | 44566 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 379 | 96.4% |
| Segfault | 8 | 2.0% |
| Timeout | 4 | 1.0% |
| Runtime Error | 2 | 0.5% |

## Passing Tests

**98 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.7s |  |
| 2 | `action_to_integer` | 28 | 2.4s |  |
| 3 | `add` | 28 | 2.4s |  |
| 4 | `add2` | 354 | 2.8s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.4s |  |
| 6 | `add_swf5` | 28 | 2.4s |  |
| 7 | `array_concat` | 98 | 2.6s |  |
| 8 | `array_constructor` | 30 | 2.5s |  |
| 9 | `array_properties` | 36 | 2.5s |  |
| 10 | `array_slice` | 34 | 2.5s |  |
| 11 | `array_splice` | 207 | 3.1s |  |
| 12 | `array_trivial` | 209 | 3.0s |  |
| 13 | `as1_constructor_v6` | 35 | 2.5s |  |
| 14 | `as1_constructor_v7` | 35 | 2.5s |  |
| 15 | `as_broadcaster_initialize` | 10 | 2.4s |  |
| 16 | `as_set_prop_flags_version_swf5` | 1 | 2.4s |  |
| 17 | `bad_swf_tag_past_eof` | 0 | 2.3s |  |
| 18 | `bitand` | 1058 | 11.3s |  |
| 19 | `bitmap_data_colortransform` | 0 | 2.7s |  |
| 20 | `bitmap_data_fillrect` | 0 | 2.5s |  |
| 21 | `bitmap_data_perlinnoise` | 0 | 3.2s |  |
| 22 | `bitmap_data_pixeldissolve_image` | 0 | 2.9s |  |
| 23 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.4s |  |
| 24 | `bitor` | 1058 | 10.9s |  |
| 25 | `biturshift` | 14 | 2.6s |  |
| 26 | `biturshift_swf8` | 14 | 2.3s |  |
| 27 | `bitxor` | 1058 | 10.8s |  |
| 28 | `catch_references_registers` | 2 | 2.3s |  |
| 29 | `define_function_case_sensitive` | 2 | 2.3s |  |
| 30 | `delete` | 3 | 2.4s |  |
| 31 | `divide_swf4` | 107 | 2.5s |  |
| 32 | `do_init_action` | 3 | 2.4s |  |
| 33 | `equals` | 32 | 2.5s |  |
| 34 | `equals2_swf5` | 926 | 10.9s |  |
| 35 | `equals2_swf6` | 926 | 11.0s |  |
| 36 | `equals2_swf7` | 926 | 10.9s |  |
| 37 | `equals_swf4` | 665 | 6.1s |  |
| 38 | `equals_swf4_alt` | 32 | 2.4s |  |
| 39 | `equals_swf5` | 32 | 2.5s |  |
| 40 | `error` | 58 | 2.6s |  |
| 41 | `escape` | 14 | 2.4s |  |
| 42 | `getproperty` | 28 | 2.4s |  |
| 43 | `getproperty_swf4` | 28 | 2.3s |  |
| 44 | `getproperty_swf5` | 28 | 2.4s |  |
| 45 | `global_array` | 3 | 2.3s |  |
| 46 | `global_is_bare` | 7 | 2.3s |  |
| 47 | `goto_execution_order` | 2 | 2.3s |  |
| 48 | `goto_rewind1` | 1 | 2.3s |  |
| 49 | `greater_swf6` | 1175 | 11.3s |  |
| 50 | `greater_swf7` | 1175 | 11.3s |  |
| 51 | `greaterthan_swf5` | 1 | 2.3s |  |
| 52 | `greaterthan_swf8` | 1 | 2.3s |  |
| 53 | `has_own_property` | 32 | 2.5s |  |
| 54 | `infinite_recursion_function_in_setter` | 131 | 2.3s |  |
| 55 | `infinite_recursion_virtual_property` | 67 | 2.3s |  |
| 56 | `issue_1086` | 1 | 2.3s |  |
| 57 | `issue_1671` | 0 | 2.3s |  |
| 58 | `issue_3446` | 1 | 2.3s |  |
| 59 | `issue_4377` | 2 | 2.3s |  |
| 60 | `issue_768` | 3 | 2.3s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 61 | `lessthan` | 41 | 2.4s |  |
| 62 | `lessthan2_swf5` | 1226 | 11.8s |  |
| 63 | `lessthan2_swf6` | 1226 | 11.9s |  |
| 64 | `lessthan2_swf7` | 1226 | 11.8s |  |
| 65 | `lessthan_swf4` | 902 | 7.7s |  |
| 66 | `lessthan_swf4_alt` | 41 | 2.4s |  |
| 67 | `lessthan_swf5` | 41 | 2.4s |  |
| 68 | `logical_ops_swf4` | 90 | 2.4s |  |
| 69 | `logical_ops_swf8` | 108 | 2.5s |  |
| 70 | `looping` | 6 | 2.3s |  |
| 71 | `mask_reapply` | 0 | 2.3s |  |
| 72 | `mask_with_drawing` | 0 | 2.4s |  |
| 73 | `movieclip_begin_gradient_fill` | 0 | 3.1s |  |
| 74 | `movieclip_line_gradient_style` | 0 | 3.0s |  |
| 75 | `movieclip_prototype_extension` | 5 | 2.4s |  |
| 76 | `nested_textfields_in_buttons` | 0 | 2.3s |  |
| 77 | `new_object_enumerate` | 7 | 2.4s |  |
| 78 | `object_function` | 32 | 2.5s |  |
| 79 | `object_string_coerce_swf5` | 62 | 2.5s |  |
| 80 | `primitive_instanceof` | 37 | 2.4s |  |
| 81 | `prototype_delete` | 12 | 2.4s |  |
| 82 | `sandbox_type_local_file` | 1 | 2.3s |  |
| 83 | `single_frame` | 1 | 2.3s |  |
| 84 | `strictequals_swf6` | 902 | 8.7s |  |
| 85 | `strictly_equals` | 7 | 2.4s |  |
| 86 | `string_coercion` | 117 | 3.0s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 87 | `string_paths_keyevents` | 0 | 2.4s |  |
| 88 | `string_paths_timer` | 0 | 2.4s |  |
| 89 | `swf4_actions_bool` | 96 | 2.5s |  |
| 90 | `swf4_bool` | 4 | 2.3s |  |
| 91 | `swf5_encoding` | 3 | 3.9s |  |
| 92 | `this_swf7` | 41 | 2.4s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 93 | `timeline_function_def` | 7 | 2.5s |  |
| 94 | `try_finally_simple` | 16 | 2.4s |  |
| 95 | `typeof_globals` | 7 | 2.4s |  |
| 96 | `undefined_to_string_swf6` | 4 | 2.3s |  |
| 97 | `unescape` | 43 | 2.5s |  |
| 98 | `with_return` | 2 | 2.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**91 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `object_constructor` | 97.0% | 32 | 33 | 1 |  |
| 2 | `swf7_case_sensitive` | 93.2% | 41 | 44 | 3 |  |
| 3 | `set_variable_scope` | 87.9% | 51 | 58 | 7 |  |
| 4 | `define_function2` | 87.5% | 7 | 8 | 1 |  |
| 5 | `array_length` | 83.3% | 35 | 42 | 7 |  |
| 6 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 7 | `get_variable_in_scope` | 79.3% | 23 | 29 | 6 |  |
| 8 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 9 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 10 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 11 | `stage_object_children` | 74.7% | 62 | 83 | 21 |  |
| 12 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 13 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 14 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 15 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 16 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 17 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 18 | `point` | 70.9% | 124 | 175 | 51 |  |
| 19 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 20 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 21 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 22 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 23 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 24 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 25 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 26 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 27 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 28 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 29 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 30 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 31 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 32 | `goto_both_ways2` | 66.7% | 2 | 3 | 1 |  |
| 33 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 34 | `goto_rewind2` | 66.7% | 2 | 3 | 1 |  |
| 35 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 36 | `o` | 66.7% | 2 | 3 | 1 |  |
| 37 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 38 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 39 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 40 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 41 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 42 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 43 | `with` | 63.3% | 31 | 49 | 18 |  |
| 44 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 45 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 46 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 47 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 48 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 49 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 50 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 51 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 52 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 53 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 54 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 55 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 56 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 57 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 58 | `with_variable_scopes` | 58.1% | 25 | 43 | 18 |  |
| 59 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 60 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 61 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 62 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 63 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 64 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 65 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 66 | `swf6_case_insensitive` | 56.8% | 25 | 44 | 19 |  |
| 67 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 68 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 69 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 70 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 71 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 72 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 73 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 74 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 75 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 76 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 77 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 78 | `as_set_prop_flags_version` | 51.6% | 16 | 31 | 15 |  |
| 79 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 80 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 81 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 82 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 83 | `goto_advance2` | 50.0% | 1 | 2 | 1 |  |
| 84 | `goto_rewind3` | 50.0% | 1 | 2 | 1 |  |
| 85 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 86 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 87 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 88 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 89 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 90 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 91 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**8 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `as2_oop` | 4.7s |  |
| 2 | `device_font_spacing` | 12.0s |  |
| 3 | `duplicate_movie_clip_drawing` | 4.4s |  |
| 4 | `enumerate` | 4.5s |  |
| 5 | `extends_chain` | 5.1s |  |
| 6 | `issue_2166` | 4.4s |  |
| 7 | `path_string` | 4.9s |  |
| 8 | `swf4_actions_coercion_order` | 4.7s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.3s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.4s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.4s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.4s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.5s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.9s |  |

## All Output Mismatches

**379 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `object_constructor` | 97.0% | 32/33 | 33 | 33 |  |
| 2 | `swf7_case_sensitive` | 93.2% | 41/44 | 44 | 44 |  |
| 3 | `set_variable_scope` | 87.9% | 51/58 | 58 | 58 |  |
| 4 | `define_function2` | 87.5% | 7/8 | 8 | 8 |  |
| 5 | `array_length` | 83.3% | 35/42 | 42 | 42 |  |
| 6 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 7 | `get_variable_in_scope` | 79.3% | 23/29 | 29 | 29 |  |
| 8 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 9 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 10 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 11 | `stage_object_children` | 74.7% | 62/83 | 83 | 83 |  |
| 12 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 13 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 14 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 15 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 16 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 17 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 18 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 19 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 20 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 21 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 22 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 23 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 24 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 25 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 26 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 27 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 28 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 29 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 30 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 31 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 32 | `goto_both_ways2` | 66.7% | 2/3 | 2 | 3 |  |
| 33 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 34 | `goto_rewind2` | 66.7% | 2/3 | 2 | 3 |  |
| 35 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 36 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 37 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 38 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 39 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 40 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 41 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 42 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 43 | `with` | 63.3% | 31/49 | 47 | 49 |  |
| 44 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 45 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 46 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 47 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 48 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 49 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 50 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 51 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 52 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 53 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 54 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 55 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 56 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 57 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 58 | `with_variable_scopes` | 58.1% | 25/43 | 43 | 43 |  |
| 59 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 60 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 61 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 62 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 63 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 64 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 65 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 66 | `swf6_case_insensitive` | 56.8% | 25/44 | 44 | 42 |  |
| 67 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 68 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 69 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 70 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 71 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 72 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 73 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 74 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 75 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 76 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 77 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 78 | `as_set_prop_flags_version` | 51.6% | 16/31 | 29 | 31 |  |
| 79 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 80 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 81 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 82 | `execution_order3` | 50.0% | 2/4 | 3 | 4 |  |
| 83 | `goto_advance2` | 50.0% | 1/2 | 1 | 2 |  |
| 84 | `goto_rewind3` | 50.0% | 1/2 | 1 | 2 |  |
| 85 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 86 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 87 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 88 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 89 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 90 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 91 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 92 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 93 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 94 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 95 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 96 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 97 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 98 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 99 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 100 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 101 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 102 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 103 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 104 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 105 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 106 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 107 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 108 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 109 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 110 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 111 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 112 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 113 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 114 | `goto_both_ways1` | 33.3% | 1/3 | 1 | 3 |  |
| 115 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 116 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 117 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 118 | `define_function2_preload` | 30.8% | 4/13 | 12 | 13 |  |
| 119 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 120 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 121 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 122 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 123 | `frame_size_translated_negative` | 28.6% | 6/21 | 20 | 21 |  |
| 124 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 125 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 126 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 127 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 128 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 129 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 130 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 131 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 132 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 133 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 134 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 135 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 136 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 137 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 138 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 139 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 140 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 141 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 142 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 143 | `funky_function_calls` | 21.4% | 12/56 | 32 | 56 |  |
| 144 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 145 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 146 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 147 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 148 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 149 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 150 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 151 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 152 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 153 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 154 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 155 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 156 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 157 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 158 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 159 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 160 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 161 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 162 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 163 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 164 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 165 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 166 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 167 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 168 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 169 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 170 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 171 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 172 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 173 | `string_paths_other` | 11.1% | 4/36 | 28 | 36 |  |
| 174 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 175 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 176 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 177 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 178 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 179 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 180 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 181 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 182 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 183 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 184 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 185 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 186 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 187 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 188 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 189 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 190 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 191 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 192 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 193 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 194 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 195 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 196 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 197 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 198 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 199 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 200 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 201 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 202 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 203 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 204 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 205 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 206 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 207 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 208 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 209 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 210 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 211 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 212 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 213 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 214 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 215 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 21 | 112 |  |
| 216 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 217 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 218 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 219 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 220 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 221 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 222 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 223 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 224 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 225 | `as2_super_and_this_v6` | 0.0% | 0/97 | 0 | 97 |  |
| 226 | `as2_super_and_this_v8` | 0.0% | 0/85 | 0 | 85 |  |
| 227 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 0 | 40 |  |
| 228 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 229 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 230 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 231 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 232 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 233 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 234 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 235 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 236 | `button_children` | 0.0% | 0/8 | 0 | 8 |  |
| 237 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 238 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 239 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 240 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 241 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 242 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 243 | `call_method_empty_name` | 0.0% | 0/1 | 0 | 1 |  |
| 244 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 245 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 246 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 247 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 248 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 249 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 250 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 251 | `color` | 0.0% | 0/57 | 0 | 57 |  |
| 252 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 253 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 254 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 255 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 256 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 257 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 258 | `duplicate_movie_clip` | 0.0% | 0/20 | 0 | 20 |  |
| 259 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 260 | `edittext_html_roundtrip` | 0.0% | 0/17 | 0 | 17 |  |
| 261 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 262 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 263 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 264 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 265 | `extends_native_type` | 0.0% | 0/11 | 0 | 11 |  |
| 266 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 267 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 268 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 269 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 270 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 271 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 272 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 273 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 274 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 275 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 276 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 277 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 278 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 279 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 280 | `goto_execution_order2` | 0.0% | 0/2 | 0 | 2 |  |
| 281 | `goto_frame` | 0.0% | 0/12 | 0 | 12 |  |
| 282 | `goto_frame2` | 0.0% | 0/44 | 0 | 44 |  |
| 283 | `goto_label` | 0.0% | 0/17 | 0 | 17 |  |
| 284 | `goto_methods` | 0.0% | 0/40 | 0 | 40 |  |
| 285 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 286 | `hittest_morph` | 0.0% | 0/70 | 0 | 70 |  |
| 287 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 288 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 289 | `init_array_invalid` | 0.0% | 0/4 | 0 | 4 |  |
| 290 | `init_object_invalid` | 0.0% | 0/4 | 0 | 4 |  |
| 291 | `init_object_order` | 0.0% | 0/15 | 0 | 15 |  |
| 292 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 293 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 294 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 295 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 296 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 297 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 298 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 299 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 300 | `issue_9885` | 0.0% | 0/2 | 0 | 2 |  |
| 301 | `localconnection` | 0.0% | 0/579 | 0 | 579 |  |
| 302 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 303 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 304 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 305 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 306 | `movieclip_init_object` | 0.0% | 0/5 | 0 | 5 |  |
| 307 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 308 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 309 | `named_shapes` | 0.0% | 0/14 | 0 | 14 |  |
| 310 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 311 | `native_objects_swf6` | 0.0% | 0/84 | 0 | 84 |  |
| 312 | `native_objects_swf7` | 0.0% | 0/84 | 0 | 84 |  |
| 313 | `native_objects_swf8` | 0.0% | 0/84 | 0 | 84 |  |
| 314 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 315 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 316 | `new_method_wrap` | 0.0% | 0/4 | 0 | 4 |  |
| 317 | `new_object_wrap` | 0.0% | 0/4 | 0 | 4 |  |
| 318 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 319 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 320 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 321 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 322 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 323 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 324 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 0 |  |
| 325 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 326 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 327 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 328 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 329 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 330 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 331 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 332 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 333 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 334 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 335 | `selection` | 0.0% | 0/454 | 0 | 454 |  |
| 336 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 337 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 338 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 339 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 340 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 341 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 342 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 343 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 344 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 345 | `stylesheet` | 0.0% | 0/283 | 0 | 283 |  |
| 346 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 347 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 348 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 349 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 350 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 351 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 352 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 353 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 354 | `target_path` | 0.0% | 0/14 | 0 | 14 |  |
| 355 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 356 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 357 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 358 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 359 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 360 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 361 | `timer_run_actions` | 0.0% | 0/18 | 0 | 18 |  |
| 362 | `typeof` | 0.0% | 0/22 | 0 | 22 |  |
| 363 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 364 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 365 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 366 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 367 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 368 | `watch` | 0.0% | 0/117 | 0 | 117 |  |
| 369 | `watch_textfield` | 0.0% | 0/12 | 0 | 12 |  |
| 370 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 371 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 372 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 373 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 374 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 375 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 376 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 377 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 378 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 379 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
