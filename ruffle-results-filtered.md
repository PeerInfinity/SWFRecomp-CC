# Ruffle Test Results (Filtered)

**Date**: 2026-02-13 01:01 UTC

**Git SHA**: `28a85fbf83`

**Run Duration**: 31m 5s

**Filtered**: 125 tests ignored out of 616 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 491 |
| Passing | **100** (20.4%) |
| Failing | 391 |
| Total expected lines | 76941 |
| Matching lines | 32250 (41.9%) |
| Mismatched lines | 44691 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 380 | 97.2% |
| Segfault | 5 | 1.3% |
| Timeout | 4 | 1.0% |
| Runtime Error | 2 | 0.5% |

## Passing Tests

**100 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.6s |  |
| 2 | `action_to_integer` | 28 | 2.5s |  |
| 3 | `add` | 28 | 2.5s |  |
| 4 | `add2` | 354 | 2.9s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.4s |  |
| 6 | `add_swf5` | 28 | 2.5s |  |
| 7 | `array_concat` | 98 | 2.6s |  |
| 8 | `array_constructor` | 30 | 2.5s |  |
| 9 | `array_properties` | 36 | 2.6s |  |
| 10 | `array_slice` | 34 | 2.6s |  |
| 11 | `array_splice` | 207 | 3.4s |  |
| 12 | `array_trivial` | 209 | 3.0s |  |
| 13 | `as1_constructor_v6` | 35 | 2.6s |  |
| 14 | `as1_constructor_v7` | 35 | 2.6s |  |
| 15 | `as_broadcaster_initialize` | 10 | 2.5s |  |
| 16 | `as_set_prop_flags_version_swf5` | 1 | 2.5s |  |
| 17 | `bad_swf_tag_past_eof` | 0 | 2.4s |  |
| 18 | `bitand` | 1058 | 9.5s |  |
| 19 | `bitmap_data_colortransform` | 0 | 2.8s |  |
| 20 | `bitmap_data_fillrect` | 0 | 2.7s |  |
| 21 | `bitmap_data_perlinnoise` | 0 | 3.3s |  |
| 22 | `bitmap_data_pixeldissolve_image` | 0 | 3.0s |  |
| 23 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.5s |  |
| 24 | `bitor` | 1058 | 9.7s |  |
| 25 | `biturshift` | 14 | 2.7s |  |
| 26 | `biturshift_swf8` | 14 | 2.4s |  |
| 27 | `bitxor` | 1058 | 9.3s |  |
| 28 | `catch_references_registers` | 2 | 2.4s |  |
| 29 | `define_function_case_sensitive` | 2 | 2.4s |  |
| 30 | `delete` | 3 | 2.5s |  |
| 31 | `divide_swf4` | 107 | 2.5s |  |
| 32 | `do_init_action` | 3 | 2.4s |  |
| 33 | `equals` | 32 | 2.5s |  |
| 34 | `equals2_swf5` | 926 | 10.8s |  |
| 35 | `equals2_swf6` | 926 | 10.6s |  |
| 36 | `equals2_swf7` | 926 | 10.5s |  |
| 37 | `equals_swf4` | 665 | 5.9s |  |
| 38 | `equals_swf4_alt` | 32 | 2.4s |  |
| 39 | `equals_swf5` | 32 | 2.5s |  |
| 40 | `error` | 58 | 2.6s |  |
| 41 | `escape` | 14 | 2.4s |  |
| 42 | `getproperty` | 28 | 2.4s |  |
| 43 | `getproperty_swf4` | 28 | 2.4s |  |
| 44 | `getproperty_swf5` | 28 | 2.5s |  |
| 45 | `global_array` | 3 | 2.4s |  |
| 46 | `global_is_bare` | 7 | 2.4s |  |
| 47 | `goto_execution_order` | 2 | 2.4s |  |
| 48 | `goto_rewind1` | 1 | 2.5s |  |
| 49 | `greater_swf6` | 1175 | 11.7s |  |
| 50 | `greater_swf7` | 1175 | 11.7s |  |
| 51 | `greaterthan_swf5` | 1 | 2.4s |  |
| 52 | `greaterthan_swf8` | 1 | 2.4s |  |
| 53 | `has_own_property` | 32 | 2.5s |  |
| 54 | `infinite_recursion_function_in_setter` | 131 | 2.4s |  |
| 55 | `infinite_recursion_virtual_property` | 67 | 2.4s |  |
| 56 | `init_array_invalid` | 4 | 2.4s |  |
| 57 | `init_object_invalid` | 4 | 2.4s |  |
| 58 | `issue_1086` | 1 | 2.4s |  |
| 59 | `issue_1671` | 0 | 2.4s |  |
| 60 | `issue_3446` | 1 | 2.4s |  |
| 61 | `issue_4377` | 2 | 2.4s |  |
| 62 | `issue_768` | 3 | 2.4s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 63 | `lessthan` | 41 | 2.5s |  |
| 64 | `lessthan2_swf5` | 1226 | 12.1s |  |
| 65 | `lessthan2_swf6` | 1226 | 12.1s |  |
| 66 | `lessthan2_swf7` | 1226 | 12.2s |  |
| 67 | `lessthan_swf4` | 902 | 8.0s |  |
| 68 | `lessthan_swf4_alt` | 41 | 2.5s |  |
| 69 | `lessthan_swf5` | 41 | 2.5s |  |
| 70 | `logical_ops_swf4` | 90 | 2.4s |  |
| 71 | `logical_ops_swf8` | 108 | 2.5s |  |
| 72 | `looping` | 6 | 2.3s |  |
| 73 | `mask_reapply` | 0 | 2.3s |  |
| 74 | `mask_with_drawing` | 0 | 2.4s |  |
| 75 | `movieclip_begin_gradient_fill` | 0 | 3.0s |  |
| 76 | `movieclip_line_gradient_style` | 0 | 3.0s |  |
| 77 | `movieclip_prototype_extension` | 5 | 2.4s |  |
| 78 | `nested_textfields_in_buttons` | 0 | 2.4s |  |
| 79 | `new_object_enumerate` | 7 | 2.4s |  |
| 80 | `object_function` | 32 | 2.5s |  |
| 81 | `object_string_coerce_swf5` | 62 | 2.5s |  |
| 82 | `primitive_instanceof` | 37 | 2.4s |  |
| 83 | `prototype_delete` | 12 | 2.5s |  |
| 84 | `sandbox_type_local_file` | 1 | 2.2s |  |
| 85 | `single_frame` | 1 | 2.2s |  |
| 86 | `strictequals_swf6` | 902 | 8.0s |  |
| 87 | `strictly_equals` | 7 | 2.3s |  |
| 88 | `string_coercion` | 117 | 2.9s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 89 | `string_paths_keyevents` | 0 | 2.3s |  |
| 90 | `string_paths_timer` | 0 | 2.3s |  |
| 91 | `swf4_actions_bool` | 96 | 2.4s |  |
| 92 | `swf4_bool` | 4 | 2.2s |  |
| 93 | `swf5_encoding` | 3 | 2.6s |  |
| 94 | `this_swf7` | 41 | 2.5s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 95 | `timeline_function_def` | 7 | 2.5s |  |
| 96 | `try_finally_simple` | 16 | 2.5s |  |
| 97 | `typeof_globals` | 7 | 2.5s |  |
| 98 | `undefined_to_string_swf6` | 4 | 2.4s |  |
| 99 | `unescape` | 43 | 2.6s |  |
| 100 | `with_return` | 2 | 2.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**92 tests** within reach

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
| 40 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 41 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 42 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 43 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 44 | `with` | 63.3% | 31 | 49 | 18 |  |
| 45 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 46 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 47 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 48 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 49 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 50 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 51 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 52 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 53 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 54 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 55 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 56 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 57 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 58 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 59 | `with_variable_scopes` | 58.1% | 25 | 43 | 18 |  |
| 60 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 61 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 62 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 63 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 64 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 65 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 66 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 67 | `swf6_case_insensitive` | 56.8% | 25 | 44 | 19 |  |
| 68 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 69 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 70 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 71 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 72 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 73 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 74 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 75 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 76 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 77 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 78 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 79 | `as_set_prop_flags_version` | 51.6% | 16 | 31 | 15 |  |
| 80 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 81 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 82 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 83 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 84 | `goto_advance2` | 50.0% | 1 | 2 | 1 |  |
| 85 | `goto_rewind3` | 50.0% | 1 | 2 | 1 |  |
| 86 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 87 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 88 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 89 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 90 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 91 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 92 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 11.9s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.5s |  |
| 3 | `enumerate` | 4.6s |  |
| 4 | `path_string` | 4.9s |  |
| 5 | `swf4_actions_coercion_order` | 4.0s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.5s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.5s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.4s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.5s |  |
| 3 | `timeout` | runtime timeout (>10s) | 14.1s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.9s |  |

## All Output Mismatches

**380 tests** with output mismatch, sorted by match rate (best first)

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
| 40 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 41 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 42 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 43 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 44 | `with` | 63.3% | 31/49 | 47 | 49 |  |
| 45 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 46 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 47 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 48 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 49 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 50 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 51 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 52 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 53 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 54 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 55 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 56 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 57 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 58 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 59 | `with_variable_scopes` | 58.1% | 25/43 | 43 | 43 |  |
| 60 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 61 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 62 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 63 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 64 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 65 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 66 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 67 | `swf6_case_insensitive` | 56.8% | 25/44 | 44 | 42 |  |
| 68 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 69 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 70 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 71 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 72 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 73 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 74 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 75 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 76 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 77 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 78 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 79 | `as_set_prop_flags_version` | 51.6% | 16/31 | 29 | 31 |  |
| 80 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 81 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 82 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 83 | `execution_order3` | 50.0% | 2/4 | 3 | 4 |  |
| 84 | `goto_advance2` | 50.0% | 1/2 | 1 | 2 |  |
| 85 | `goto_rewind3` | 50.0% | 1/2 | 1 | 2 |  |
| 86 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 87 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 88 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 89 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 90 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 91 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 92 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 93 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 94 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 95 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 96 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 97 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 98 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 99 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 100 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 101 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 102 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 103 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 104 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 105 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 106 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 107 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 108 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 109 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 110 | `named_shapes` | 35.7% | 5/14 | 14 | 14 |  |
| 111 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 112 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 113 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 114 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 115 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 116 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 117 | `goto_both_ways1` | 33.3% | 1/3 | 1 | 3 |  |
| 118 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 119 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 120 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 121 | `define_function2_preload` | 30.8% | 4/13 | 12 | 13 |  |
| 122 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 123 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 124 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 125 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 126 | `frame_size_translated_negative` | 28.6% | 6/21 | 20 | 21 |  |
| 127 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 128 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 129 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 130 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 131 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 132 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 133 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 134 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 135 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 136 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 137 | `new_object_wrap` | 25.0% | 1/4 | 4 | 4 |  |
| 138 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 139 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 140 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 141 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 142 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 143 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 144 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 145 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 146 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 147 | `funky_function_calls` | 21.4% | 12/56 | 32 | 56 |  |
| 148 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 149 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 150 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 151 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 152 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 153 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 154 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 155 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 156 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 157 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 158 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 159 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 160 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 161 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 162 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 163 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 164 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 165 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 166 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 167 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 168 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 169 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 170 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 171 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 172 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 173 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 174 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 175 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 176 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 177 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 178 | `string_paths_other` | 11.1% | 4/36 | 28 | 36 |  |
| 179 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 180 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 181 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 182 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 183 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 184 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 185 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 186 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 187 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 188 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 189 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 190 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 191 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 192 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 193 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 194 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 195 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 196 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 197 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 198 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 199 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 200 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 201 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 202 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 203 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 204 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 205 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 206 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 207 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 208 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 209 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 210 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 211 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 212 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 213 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 214 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 215 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 216 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 217 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 218 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 219 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 220 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 21 | 112 |  |
| 221 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 222 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 223 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 224 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 225 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 226 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 227 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 228 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 229 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 230 | `as2_oop` | 0.0% | 0/13 | 0 | 13 |  |
| 231 | `as2_super_and_this_v6` | 0.0% | 0/97 | 0 | 97 |  |
| 232 | `as2_super_and_this_v8` | 0.0% | 0/85 | 0 | 85 |  |
| 233 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 0 | 40 |  |
| 234 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 235 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 236 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 237 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 238 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 239 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 240 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 241 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 242 | `button_children` | 0.0% | 0/8 | 0 | 8 |  |
| 243 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 244 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 245 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 246 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 247 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 248 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 249 | `call_method_empty_name` | 0.0% | 0/1 | 0 | 1 |  |
| 250 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 251 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 252 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 253 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 254 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 255 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 256 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 257 | `color` | 0.0% | 0/57 | 0 | 57 |  |
| 258 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 259 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 260 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 261 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 262 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 263 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 264 | `duplicate_movie_clip` | 0.0% | 0/20 | 0 | 20 |  |
| 265 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 266 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 267 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 268 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 269 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 270 | `extends_chain` | 0.0% | 0/134 | 0 | 134 |  |
| 271 | `extends_native_type` | 0.0% | 0/11 | 0 | 11 |  |
| 272 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 273 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 274 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 275 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 276 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 277 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 278 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 279 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 280 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 281 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 282 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 283 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 284 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 285 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 286 | `goto_execution_order2` | 0.0% | 0/2 | 0 | 2 |  |
| 287 | `goto_frame` | 0.0% | 0/12 | 0 | 12 |  |
| 288 | `goto_frame2` | 0.0% | 0/44 | 0 | 44 |  |
| 289 | `goto_label` | 0.0% | 0/17 | 0 | 17 |  |
| 290 | `goto_methods` | 0.0% | 0/40 | 0 | 40 |  |
| 291 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 292 | `hittest_morph` | 0.0% | 0/70 | 0 | 70 |  |
| 293 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 294 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 295 | `init_object_order` | 0.0% | 0/15 | 0 | 15 |  |
| 296 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 297 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 298 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 299 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 300 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 301 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 302 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 303 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 304 | `issue_9885` | 0.0% | 0/2 | 0 | 2 |  |
| 305 | `localconnection` | 0.0% | 0/579 | 0 | 579 |  |
| 306 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 307 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 308 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 309 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 310 | `movieclip_init_object` | 0.0% | 0/5 | 0 | 5 |  |
| 311 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 312 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 313 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 314 | `native_objects_swf6` | 0.0% | 0/84 | 0 | 84 |  |
| 315 | `native_objects_swf7` | 0.0% | 0/84 | 0 | 84 |  |
| 316 | `native_objects_swf8` | 0.0% | 0/84 | 0 | 84 |  |
| 317 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 318 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 319 | `new_method_wrap` | 0.0% | 0/4 | 4 | 4 |  |
| 320 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 321 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 322 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 323 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 324 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 325 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 326 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 0 |  |
| 327 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 328 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 329 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 330 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 331 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 332 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 333 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 334 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 335 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 336 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 337 | `selection` | 0.0% | 0/454 | 0 | 454 |  |
| 338 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 339 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 340 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 341 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 342 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 343 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 344 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 345 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 346 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 347 | `stylesheet` | 0.0% | 0/283 | 0 | 283 |  |
| 348 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 349 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 350 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 351 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 352 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 353 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 354 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 355 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 356 | `target_path` | 0.0% | 0/14 | 0 | 14 |  |
| 357 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 358 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 359 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 360 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 361 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 362 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 363 | `timer_run_actions` | 0.0% | 0/18 | 0 | 18 |  |
| 364 | `typeof` | 0.0% | 0/22 | 0 | 22 |  |
| 365 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 366 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 367 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 368 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 369 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 370 | `watch` | 0.0% | 0/117 | 0 | 117 |  |
| 371 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 372 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 373 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 374 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 375 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 376 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 377 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 378 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 379 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 380 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
