# Ruffle Test Results (Filtered)

**Date**: 2026-02-13 02:01 UTC

**Git SHA**: `d482f825a7`

**Run Duration**: 31m 37s

**Filtered**: 125 tests ignored out of 616 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 491 |
| Passing | **106** (21.6%) |
| Failing | 385 |
| Total expected lines | 76941 |
| Matching lines | 32256 (41.9%) |
| Mismatched lines | 44685 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 374 | 97.1% |
| Segfault | 5 | 1.3% |
| Timeout | 4 | 1.0% |
| Runtime Error | 2 | 0.5% |

## Passing Tests

**106 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 3.6s |  |
| 2 | `action_to_integer` | 28 | 2.5s |  |
| 3 | `add` | 28 | 2.5s |  |
| 4 | `add2` | 354 | 2.9s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.4s |  |
| 6 | `add_swf5` | 28 | 2.5s |  |
| 7 | `array_concat` | 98 | 2.7s |  |
| 8 | `array_constructor` | 30 | 2.5s |  |
| 9 | `array_properties` | 36 | 2.5s |  |
| 10 | `array_slice` | 34 | 2.6s |  |
| 11 | `array_splice` | 207 | 3.2s |  |
| 12 | `array_trivial` | 209 | 3.0s |  |
| 13 | `as1_constructor_v6` | 35 | 2.6s |  |
| 14 | `as1_constructor_v7` | 35 | 2.6s |  |
| 15 | `as_broadcaster_initialize` | 10 | 2.4s |  |
| 16 | `as_set_prop_flags_version_swf5` | 1 | 2.5s |  |
| 17 | `bad_swf_tag_past_eof` | 0 | 2.4s |  |
| 18 | `bitand` | 1058 | 9.1s |  |
| 19 | `bitmap_data_colortransform` | 0 | 2.8s |  |
| 20 | `bitmap_data_fillrect` | 0 | 2.6s |  |
| 21 | `bitmap_data_perlinnoise` | 0 | 3.1s |  |
| 22 | `bitmap_data_pixeldissolve_image` | 0 | 2.9s |  |
| 23 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.5s |  |
| 24 | `bitor` | 1058 | 9.0s |  |
| 25 | `biturshift` | 14 | 2.7s |  |
| 26 | `biturshift_swf8` | 14 | 2.5s |  |
| 27 | `bitxor` | 1058 | 9.6s |  |
| 28 | `catch_references_registers` | 2 | 2.5s |  |
| 29 | `define_function_case_sensitive` | 2 | 2.4s |  |
| 30 | `delete` | 3 | 2.5s |  |
| 31 | `divide_swf4` | 107 | 2.6s |  |
| 32 | `do_init_action` | 3 | 2.5s |  |
| 33 | `equals` | 32 | 2.6s |  |
| 34 | `equals2_swf5` | 926 | 10.8s |  |
| 35 | `equals2_swf6` | 926 | 10.7s |  |
| 36 | `equals2_swf7` | 926 | 10.7s |  |
| 37 | `equals_swf4` | 665 | 6.0s |  |
| 38 | `equals_swf4_alt` | 32 | 2.5s |  |
| 39 | `equals_swf5` | 32 | 2.5s |  |
| 40 | `error` | 58 | 2.7s |  |
| 41 | `escape` | 14 | 2.5s |  |
| 42 | `getproperty` | 28 | 2.5s |  |
| 43 | `getproperty_swf4` | 28 | 2.4s |  |
| 44 | `getproperty_swf5` | 28 | 2.5s |  |
| 45 | `global_array` | 3 | 2.4s |  |
| 46 | `global_is_bare` | 7 | 2.4s |  |
| 47 | `goto_advance2` | 2 | 2.5s |  |
| 48 | `goto_both_ways1` | 3 | 2.7s |  |
| 49 | `goto_both_ways2` | 3 | 2.6s |  |
| 50 | `goto_execution_order` | 2 | 2.5s |  |
| 51 | `goto_execution_order2` | 2 | 2.5s |  |
| 52 | `goto_rewind1` | 1 | 2.5s |  |
| 53 | `goto_rewind2` | 3 | 2.5s |  |
| 54 | `goto_rewind3` | 2 | 2.5s |  |
| 55 | `greater_swf6` | 1175 | 12.0s |  |
| 56 | `greater_swf7` | 1175 | 12.0s |  |
| 57 | `greaterthan_swf5` | 1 | 2.5s |  |
| 58 | `greaterthan_swf8` | 1 | 2.5s |  |
| 59 | `has_own_property` | 32 | 2.6s |  |
| 60 | `infinite_recursion_function_in_setter` | 131 | 2.5s |  |
| 61 | `infinite_recursion_virtual_property` | 67 | 2.5s |  |
| 62 | `init_array_invalid` | 4 | 2.5s |  |
| 63 | `init_object_invalid` | 4 | 2.5s |  |
| 64 | `issue_1086` | 1 | 2.5s |  |
| 65 | `issue_1671` | 0 | 2.5s |  |
| 66 | `issue_3446` | 1 | 2.5s |  |
| 67 | `issue_4377` | 2 | 2.5s |  |
| 68 | `issue_768` | 3 | 2.5s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 69 | `lessthan` | 41 | 2.7s |  |
| 70 | `lessthan2_swf5` | 1226 | 12.8s |  |
| 71 | `lessthan2_swf6` | 1226 | 13.0s |  |
| 72 | `lessthan2_swf7` | 1226 | 12.9s |  |
| 73 | `lessthan_swf4` | 902 | 8.7s |  |
| 74 | `lessthan_swf4_alt` | 41 | 2.6s |  |
| 75 | `lessthan_swf5` | 41 | 2.6s |  |
| 76 | `logical_ops_swf4` | 90 | 2.5s |  |
| 77 | `logical_ops_swf8` | 108 | 2.6s |  |
| 78 | `looping` | 6 | 2.5s |  |
| 79 | `mask_reapply` | 0 | 2.5s |  |
| 80 | `mask_with_drawing` | 0 | 2.5s |  |
| 81 | `movieclip_begin_gradient_fill` | 0 | 3.3s |  |
| 82 | `movieclip_line_gradient_style` | 0 | 3.0s |  |
| 83 | `movieclip_prototype_extension` | 5 | 2.4s |  |
| 84 | `nested_textfields_in_buttons` | 0 | 2.4s |  |
| 85 | `new_object_enumerate` | 7 | 2.4s |  |
| 86 | `object_function` | 32 | 2.5s |  |
| 87 | `object_string_coerce_swf5` | 62 | 2.5s |  |
| 88 | `primitive_instanceof` | 37 | 2.5s |  |
| 89 | `prototype_delete` | 12 | 2.5s |  |
| 90 | `sandbox_type_local_file` | 1 | 2.4s |  |
| 91 | `single_frame` | 1 | 2.4s |  |
| 92 | `strictequals_swf6` | 902 | 8.7s |  |
| 93 | `strictly_equals` | 7 | 2.5s |  |
| 94 | `string_coercion` | 117 | 3.0s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 95 | `string_paths_keyevents` | 0 | 2.4s |  |
| 96 | `string_paths_timer` | 0 | 2.4s |  |
| 97 | `swf4_actions_bool` | 96 | 2.5s |  |
| 98 | `swf4_bool` | 4 | 2.4s |  |
| 99 | `swf5_encoding` | 3 | 3.4s |  |
| 100 | `this_swf7` | 41 | 2.5s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 101 | `timeline_function_def` | 7 | 2.5s |  |
| 102 | `try_finally_simple` | 16 | 2.5s |  |
| 103 | `typeof_globals` | 7 | 2.5s |  |
| 104 | `undefined_to_string_swf6` | 4 | 2.4s |  |
| 105 | `unescape` | 43 | 2.6s |  |
| 106 | `with_return` | 2 | 2.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**87 tests** within reach

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
| 10 | `execution_order3` | 75.0% | 3 | 4 | 1 |  |
| 11 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 12 | `stage_object_children` | 74.7% | 62 | 83 | 21 |  |
| 13 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 14 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 15 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 16 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 17 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 18 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 19 | `point` | 70.9% | 124 | 175 | 51 |  |
| 20 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 21 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 22 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 23 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 24 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 25 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 26 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 27 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 28 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 29 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 30 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 31 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 32 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 33 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 34 | `o` | 66.7% | 2 | 3 | 1 |  |
| 35 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 36 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 37 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 38 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 39 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 40 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 41 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 42 | `with` | 63.3% | 31 | 49 | 18 |  |
| 43 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 44 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 45 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 46 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 47 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 48 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 49 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 50 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 51 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 52 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 53 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 54 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 55 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 56 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 57 | `with_variable_scopes` | 58.1% | 25 | 43 | 18 |  |
| 58 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 59 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 60 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 61 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 62 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 63 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 64 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 65 | `swf6_case_insensitive` | 56.8% | 25 | 44 | 19 |  |
| 66 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 67 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 68 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 69 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 70 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 71 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 72 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 73 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 74 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 75 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 76 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 77 | `as_set_prop_flags_version` | 51.6% | 16 | 31 | 15 |  |
| 78 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 79 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 80 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 81 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 82 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 83 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 84 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 85 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 86 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 87 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 12.0s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.5s |  |
| 3 | `enumerate` | 4.4s |  |
| 4 | `path_string` | 4.9s |  |
| 5 | `swf4_actions_coercion_order` | 4.8s |  |

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
| 1 | `parse_float` | runtime timeout (>10s) | 13.5s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.6s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.8s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.9s |  |

## All Output Mismatches

**374 tests** with output mismatch, sorted by match rate (best first)

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
| 10 | `execution_order3` | 75.0% | 3/4 | 3 | 4 |  |
| 11 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 12 | `stage_object_children` | 74.7% | 62/83 | 83 | 83 |  |
| 13 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 14 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 15 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 16 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 17 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 18 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 19 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 20 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 21 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 22 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 23 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 24 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 25 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 26 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 27 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 28 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 29 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 30 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 31 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 32 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 33 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 34 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 35 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 36 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 37 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 38 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 39 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 40 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 41 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 42 | `with` | 63.3% | 31/49 | 47 | 49 |  |
| 43 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 44 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 45 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 46 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 47 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 48 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 49 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 50 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 51 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 52 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 53 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 54 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 55 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 56 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 57 | `with_variable_scopes` | 58.1% | 25/43 | 43 | 43 |  |
| 58 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 59 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 60 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 61 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 62 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 63 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 64 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 65 | `swf6_case_insensitive` | 56.8% | 25/44 | 44 | 42 |  |
| 66 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 67 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 68 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 69 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 70 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 71 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 72 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 73 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 74 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 75 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 76 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 77 | `as_set_prop_flags_version` | 51.6% | 16/31 | 29 | 31 |  |
| 78 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 79 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 80 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 81 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 82 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 83 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 84 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 85 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 86 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 87 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 88 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 89 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 90 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 91 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 92 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 93 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 94 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 95 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 96 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 97 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 98 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 99 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 100 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 101 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 102 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 103 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 104 | `named_shapes` | 35.7% | 5/14 | 14 | 14 |  |
| 105 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 106 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 107 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 108 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 109 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 110 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 111 | `goto_frame_number` | 33.3% | 1/3 | 1 | 3 |  |
| 112 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 113 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 114 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 115 | `define_function2_preload` | 30.8% | 4/13 | 12 | 13 |  |
| 116 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 117 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 118 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 119 | `execution_order2` | 28.6% | 2/7 | 4 | 7 |  |
| 120 | `frame_size_translated_negative` | 28.6% | 6/21 | 20 | 21 |  |
| 121 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 122 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 123 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 124 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 125 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 126 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 127 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 128 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 129 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 130 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 131 | `new_object_wrap` | 25.0% | 1/4 | 4 | 4 |  |
| 132 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 133 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 134 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 135 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 136 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 137 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 138 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 139 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 140 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 141 | `funky_function_calls` | 21.4% | 12/56 | 32 | 56 |  |
| 142 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 143 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 144 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 145 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 146 | `rewind_depth` | 20.0% | 6/30 | 22 | 30 |  |
| 147 | `tell_target_invalid_swf6` | 20.0% | 1/5 | 2 | 5 |  |
| 148 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 149 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 150 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 151 | `tell_target_invalid` | 16.7% | 1/6 | 2 | 6 |  |
| 152 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 153 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 154 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 155 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 156 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 157 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 158 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 159 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 160 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 161 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 162 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 163 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 164 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 165 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 166 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 167 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 168 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 169 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 170 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 171 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 172 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 173 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 174 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 175 | `string_paths_other` | 11.1% | 4/36 | 28 | 36 |  |
| 176 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 177 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 178 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 179 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 180 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 181 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 182 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 183 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 184 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 185 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 186 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 187 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 188 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 189 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 190 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 191 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 192 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 193 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 194 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 195 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 196 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 197 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 198 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 199 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 200 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 201 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 202 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 203 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 204 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 205 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 206 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 207 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 208 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 209 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 210 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 211 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 212 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 213 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 214 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 215 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 216 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 217 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 21 | 112 |  |
| 218 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 219 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 220 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 221 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 222 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 223 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 224 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 225 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 226 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 227 | `as2_oop` | 0.0% | 0/13 | 0 | 13 |  |
| 228 | `as2_super_and_this_v6` | 0.0% | 0/97 | 0 | 97 |  |
| 229 | `as2_super_and_this_v8` | 0.0% | 0/85 | 0 | 85 |  |
| 230 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 0 | 40 |  |
| 231 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 232 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 233 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 234 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 235 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 236 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 237 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 238 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 239 | `button_children` | 0.0% | 0/8 | 0 | 8 |  |
| 240 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 241 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 242 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 243 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 244 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 245 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 246 | `call_method_empty_name` | 0.0% | 0/1 | 0 | 1 |  |
| 247 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 248 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 249 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 250 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 251 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 252 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 253 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 254 | `color` | 0.0% | 0/57 | 0 | 57 |  |
| 255 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 256 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 257 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 258 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 259 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 260 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 261 | `duplicate_movie_clip` | 0.0% | 0/20 | 0 | 20 |  |
| 262 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 263 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 264 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 265 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 266 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 267 | `extends_chain` | 0.0% | 0/134 | 0 | 134 |  |
| 268 | `extends_native_type` | 0.0% | 0/11 | 0 | 11 |  |
| 269 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 270 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 271 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 272 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 273 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 274 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 275 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 276 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 277 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 278 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 279 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 280 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 281 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 282 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 283 | `goto_frame` | 0.0% | 0/12 | 0 | 12 |  |
| 284 | `goto_frame2` | 0.0% | 0/44 | 0 | 44 |  |
| 285 | `goto_label` | 0.0% | 0/17 | 0 | 17 |  |
| 286 | `goto_methods` | 0.0% | 0/40 | 0 | 40 |  |
| 287 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 288 | `hittest_morph` | 0.0% | 0/70 | 0 | 70 |  |
| 289 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 290 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
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
| 309 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 310 | `native_objects_swf6` | 0.0% | 0/84 | 0 | 84 |  |
| 311 | `native_objects_swf7` | 0.0% | 0/84 | 0 | 84 |  |
| 312 | `native_objects_swf8` | 0.0% | 0/84 | 0 | 84 |  |
| 313 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 314 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 315 | `new_method_wrap` | 0.0% | 0/4 | 4 | 4 |  |
| 316 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 317 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 318 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 319 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 320 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 321 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 322 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 0 |  |
| 323 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 324 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 325 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 326 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 0 | 2 |  |
| 327 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 328 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 329 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 330 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 331 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 332 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 333 | `selection` | 0.0% | 0/454 | 0 | 454 |  |
| 334 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 335 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 336 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 337 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 338 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 339 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 340 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 341 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 342 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 343 | `stylesheet` | 0.0% | 0/283 | 0 | 283 |  |
| 344 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 345 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 346 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 347 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 348 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 349 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 350 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 351 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 352 | `target_path` | 0.0% | 0/14 | 0 | 14 |  |
| 353 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 354 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 355 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 356 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 357 | `timer_run_actions` | 0.0% | 0/18 | 0 | 18 |  |
| 358 | `typeof` | 0.0% | 0/22 | 0 | 22 |  |
| 359 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 360 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 361 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 362 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 363 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 364 | `watch` | 0.0% | 0/117 | 0 | 117 |  |
| 365 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 366 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 367 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 368 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 369 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 370 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 371 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 372 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 373 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 374 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
