# Ruffle Test Results (Filtered)

**Date**: 2026-02-13 03:07 UTC

**Git SHA**: `56ef4af542`

**Run Duration**: 31m 17s

**Filtered**: 125 tests ignored out of 616 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 491 |
| Passing | **107** (21.8%) |
| Failing | 384 |
| Total expected lines | 76941 |
| Matching lines | 32260 (41.9%) |
| Mismatched lines | 44681 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 373 | 97.1% |
| Segfault | 4 | 1.0% |
| Timeout | 4 | 1.0% |
| Runtime Error | 3 | 0.8% |

## Passing Tests

**107 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `action_to_integer` | 28 | 2.4s |  |
| 2 | `add` | 28 | 2.5s |  |
| 3 | `add_swf4` | 28 | 2.4s |  |
| 4 | `add_swf5` | 28 | 2.5s |  |
| 5 | `array_concat` | 98 | 2.6s |  |
| 6 | `array_constructor` | 30 | 2.5s |  |
| 7 | `array_properties` | 36 | 2.5s |  |
| 8 | `array_slice` | 34 | 2.6s |  |
| 9 | `array_splice` | 207 | 3.2s |  |
| 10 | `array_trivial` | 209 | 3.0s |  |
| 11 | `as1_constructor_v6` | 35 | 2.5s |  |
| 12 | `as1_constructor_v7` | 35 | 2.5s |  |
| 13 | `as_broadcaster_initialize` | 10 | 2.4s |  |
| 14 | `as_set_prop_flags_version_swf5` | 1 | 2.4s |  |
| 15 | `bad_swf_tag_past_eof` | 0 | 2.3s |  |
| 16 | `bitand` | 1058 | 9.4s |  |
| 17 | `bitmap_data_colortransform` | 0 | 2.7s |  |
| 18 | `bitmap_data_fillrect` | 0 | 2.6s |  |
| 19 | `bitmap_data_perlinnoise` | 0 | 3.2s |  |
| 20 | `bitmap_data_pixeldissolve_image` | 0 | 2.9s |  |
| 21 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.4s |  |
| 22 | `bitor` | 1058 | 9.4s |  |
| 23 | `biturshift` | 14 | 3.8s |  |
| 24 | `biturshift_swf8` | 14 | 2.6s |  |
| 25 | `bitxor` | 1058 | 9.8s |  |
| 26 | `call_method_empty_name` | 1 | 2.5s |  |
| 27 | `catch_references_registers` | 2 | 2.5s |  |
| 28 | `define_function2` | 8 | 2.5s |  |
| 29 | `define_function_case_sensitive` | 2 | 2.5s |  |
| 30 | `delete` | 3 | 2.6s |  |
| 31 | `divide_swf4` | 107 | 2.6s |  |
| 32 | `do_init_action` | 3 | 2.5s |  |
| 33 | `equals` | 32 | 2.6s |  |
| 34 | `equals2_swf5` | 926 | 11.0s |  |
| 35 | `equals2_swf6` | 926 | 11.0s |  |
| 36 | `equals2_swf7` | 926 | 10.9s |  |
| 37 | `equals_swf4` | 665 | 6.2s |  |
| 38 | `equals_swf4_alt` | 32 | 2.5s |  |
| 39 | `equals_swf5` | 32 | 2.6s |  |
| 40 | `error` | 58 | 2.7s |  |
| 41 | `escape` | 14 | 2.5s |  |
| 42 | `execution_order3` | 4 | 2.5s |  |
| 43 | `getproperty` | 28 | 2.5s |  |
| 44 | `getproperty_swf4` | 28 | 2.4s |  |
| 45 | `getproperty_swf5` | 28 | 2.5s |  |
| 46 | `global_array` | 3 | 2.4s |  |
| 47 | `global_is_bare` | 7 | 2.4s |  |
| 48 | `goto_advance2` | 2 | 2.4s |  |
| 49 | `goto_both_ways1` | 3 | 2.7s |  |
| 50 | `goto_both_ways2` | 3 | 2.5s |  |
| 51 | `goto_execution_order` | 2 | 2.5s |  |
| 52 | `goto_execution_order2` | 2 | 2.5s |  |
| 53 | `goto_rewind1` | 1 | 2.5s |  |
| 54 | `goto_rewind2` | 3 | 2.5s |  |
| 55 | `goto_rewind3` | 2 | 2.5s |  |
| 56 | `greater_swf6` | 1175 | 11.7s |  |
| 57 | `greater_swf7` | 1175 | 11.7s |  |
| 58 | `greaterthan_swf5` | 1 | 2.4s |  |
| 59 | `greaterthan_swf8` | 1 | 2.5s |  |
| 60 | `has_own_property` | 32 | 2.6s |  |
| 61 | `infinite_recursion_function_in_setter` | 131 | 2.5s |  |
| 62 | `infinite_recursion_virtual_property` | 67 | 2.5s |  |
| 63 | `init_array_invalid` | 4 | 2.4s |  |
| 64 | `init_object_invalid` | 4 | 2.4s |  |
| 65 | `issue_1086` | 1 | 2.4s |  |
| 66 | `issue_1671` | 0 | 2.4s |  |
| 67 | `issue_3446` | 1 | 2.5s |  |
| 68 | `issue_4377` | 2 | 2.5s |  |
| 69 | `issue_768` | 3 | 2.5s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 70 | `lessthan` | 41 | 2.6s |  |
| 71 | `lessthan2_swf5` | 1226 | 12.4s |  |
| 72 | `lessthan2_swf6` | 1226 | 12.3s |  |
| 73 | `lessthan2_swf7` | 1226 | 12.3s |  |
| 74 | `lessthan_swf4` | 902 | 8.0s |  |
| 75 | `lessthan_swf4_alt` | 41 | 2.5s |  |
| 76 | `lessthan_swf5` | 41 | 2.5s |  |
| 77 | `logical_ops_swf4` | 90 | 2.5s |  |
| 78 | `logical_ops_swf8` | 108 | 2.6s |  |
| 79 | `looping` | 6 | 2.4s |  |
| 80 | `mask_reapply` | 0 | 2.4s |  |
| 81 | `mask_with_drawing` | 0 | 2.4s |  |
| 82 | `movieclip_begin_gradient_fill` | 0 | 3.1s |  |
| 83 | `movieclip_line_gradient_style` | 0 | 2.9s |  |
| 84 | `nested_textfields_in_buttons` | 0 | 2.3s |  |
| 85 | `new_object_enumerate` | 7 | 2.4s |  |
| 86 | `object_constructor` | 33 | 2.4s |  |
| 87 | `object_function` | 32 | 2.4s |  |
| 88 | `object_string_coerce_swf5` | 62 | 2.5s |  |
| 89 | `primitive_instanceof` | 37 | 2.4s |  |
| 90 | `prototype_delete` | 12 | 2.4s |  |
| 91 | `sandbox_type_local_file` | 1 | 2.4s |  |
| 92 | `single_frame` | 1 | 2.4s |  |
| 93 | `strictequals_swf6` | 902 | 8.4s |  |
| 94 | `strictly_equals` | 7 | 2.4s |  |
| 95 | `string_coercion` | 117 | 3.0s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 96 | `string_paths_keyevents` | 0 | 2.4s |  |
| 97 | `string_paths_timer` | 0 | 2.4s |  |
| 98 | `swf4_actions_bool` | 96 | 2.5s |  |
| 99 | `swf4_bool` | 4 | 2.5s |  |
| 100 | `swf5_encoding` | 3 | 2.6s |  |
| 101 | `this_swf7` | 41 | 2.5s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 102 | `timeline_function_def` | 7 | 2.6s |  |
| 103 | `try_finally_simple` | 16 | 2.4s |  |
| 104 | `typeof_globals` | 7 | 2.4s |  |
| 105 | `undefined_to_string_swf6` | 4 | 2.4s |  |
| 106 | `unescape` | 43 | 2.5s |  |
| 107 | `with_return` | 2 | 2.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**87 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `add2` | 96.0% | 340 | 354 | 14 | [investigation](ruffle-tests/_investigation/add2.md) |
| 2 | `get_variable_in_scope` | 89.7% | 26 | 29 | 3 |  |
| 3 | `set_variable_scope` | 87.9% | 51 | 58 | 7 |  |
| 4 | `array_length` | 83.3% | 35 | 42 | 7 |  |
| 5 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 6 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 7 | `stage_object_children` | 77.1% | 64 | 83 | 19 |  |
| 8 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 9 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 10 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 11 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 12 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 13 | `swf7_case_sensitive` | 72.7% | 32 | 44 | 12 |  |
| 14 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 15 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 16 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 17 | `point` | 70.9% | 124 | 175 | 51 |  |
| 18 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 19 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 20 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 21 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 22 | `define_function2_preload` | 69.2% | 9 | 13 | 4 |  |
| 23 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 24 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 25 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 26 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 27 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 28 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 29 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 30 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 31 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 32 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
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
| 53 | `movieclip_prototype_extension` | 60.0% | 3 | 5 | 2 |  |
| 54 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 55 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 56 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 57 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 58 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 59 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 60 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 61 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 62 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 63 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 64 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 65 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 66 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 67 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 68 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 69 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 70 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 71 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 72 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 73 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 74 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 75 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 76 | `swf6_case_insensitive` | 52.3% | 23 | 44 | 21 |  |
| 77 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 78 | `as_set_prop_flags_version` | 51.6% | 16 | 31 | 15 |  |
| 79 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 80 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 81 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 82 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 83 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 84 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 85 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 86 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 87 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 12.0s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.6s |  |
| 3 | `path_string` | 4.2s |  |
| 4 | `swf4_actions_coercion_order` | 4.7s |  |

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `register_underflow` | exit code -6 | 3.7s |  |
| 2 | `uncaught_exception` | exit code 1 | 2.4s |  |
| 3 | `uncaught_exception_bubbled` | exit code 1 | 2.4s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.5s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.5s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.5s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.8s |  |

## All Output Mismatches

**373 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `add2` | 96.0% | 340/354 | 354 | 354 | [investigation](ruffle-tests/_investigation/add2.md) |
| 2 | `get_variable_in_scope` | 89.7% | 26/29 | 29 | 29 |  |
| 3 | `set_variable_scope` | 87.9% | 51/58 | 58 | 58 |  |
| 4 | `array_length` | 83.3% | 35/42 | 42 | 42 |  |
| 5 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 6 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 7 | `stage_object_children` | 77.1% | 64/83 | 83 | 83 |  |
| 8 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 9 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 10 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 11 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 12 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 13 | `swf7_case_sensitive` | 72.7% | 32/44 | 44 | 44 |  |
| 14 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 15 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 16 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 17 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 18 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 19 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 20 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 21 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 22 | `define_function2_preload` | 69.2% | 9/13 | 13 | 13 |  |
| 23 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 24 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 25 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 26 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 27 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 28 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 29 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 30 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 31 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 32 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
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
| 53 | `movieclip_prototype_extension` | 60.0% | 3/5 | 4 | 5 |  |
| 54 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 55 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 56 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 57 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 58 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 59 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 60 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 61 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 62 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 63 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 64 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 65 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 66 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 67 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 68 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 69 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 70 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 71 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 72 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 73 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 74 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 75 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 76 | `swf6_case_insensitive` | 52.3% | 23/44 | 44 | 42 |  |
| 77 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 78 | `as_set_prop_flags_version` | 51.6% | 16/31 | 29 | 31 |  |
| 79 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 80 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 81 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 82 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 83 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 84 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 85 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
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
| 98 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 99 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 100 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 101 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 102 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 103 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 104 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 105 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 106 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 107 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 108 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 109 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 110 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 111 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 112 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 113 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 114 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 115 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 116 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 117 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 118 | `frame_size_translated_negative` | 28.6% | 6/21 | 20 | 21 |  |
| 119 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 120 | `define_local_with_paths` | 27.8% | 15/54 | 38 | 54 |  |
| 121 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 122 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 123 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 124 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 125 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 126 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 127 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 128 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 129 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 130 | `new_object_wrap` | 25.0% | 1/4 | 4 | 4 |  |
| 131 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 132 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 133 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 134 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 135 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 136 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 137 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 138 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 139 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 140 | `funky_function_calls` | 21.4% | 12/56 | 32 | 56 |  |
| 141 | `named_shapes` | 21.4% | 3/14 | 14 | 14 |  |
| 142 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 143 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 144 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 145 | `target_clip_removed` | 20.0% | 1/5 | 5 | 5 |  |
| 146 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 147 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 148 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 149 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 150 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 151 | `register_and_init_order` | 15.6% | 36/231 | 68 | 231 |  |
| 152 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 153 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 154 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 155 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 156 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 157 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 158 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 159 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 160 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 161 | `string_paths_other` | 13.9% | 5/36 | 28 | 36 |  |
| 162 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 163 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 164 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 165 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 166 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 167 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 168 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 169 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 170 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 171 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 172 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 173 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
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
| 222 | `access_unnamed_shape` | 0.0% | 0/1 | 0 | 1 |  |
| 223 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 224 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 225 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 226 | `as2_oop` | 0.0% | 0/13 | 0 | 13 |  |
| 227 | `as2_super_and_this_v6` | 0.0% | 0/97 | 0 | 97 |  |
| 228 | `as2_super_and_this_v8` | 0.0% | 0/85 | 0 | 85 |  |
| 229 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 0 | 40 |  |
| 230 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 231 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 232 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 233 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 234 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 235 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 236 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 237 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 238 | `button_children` | 0.0% | 0/8 | 0 | 8 |  |
| 239 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 240 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 241 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 242 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 243 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 244 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 245 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 246 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 247 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 248 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 249 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 250 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 251 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 252 | `color` | 0.0% | 0/57 | 0 | 57 |  |
| 253 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 254 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 255 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 256 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 257 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 258 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 259 | `duplicate_movie_clip` | 0.0% | 0/20 | 0 | 20 |  |
| 260 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 261 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 262 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 263 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 264 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 265 | `extends_chain` | 0.0% | 0/134 | 0 | 134 |  |
| 266 | `extends_native_type` | 0.0% | 0/11 | 0 | 11 |  |
| 267 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 268 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 269 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 270 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 271 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 272 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 273 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 274 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 275 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 276 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 277 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 278 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 279 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 280 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 281 | `goto_frame` | 0.0% | 0/12 | 0 | 12 |  |
| 282 | `goto_frame2` | 0.0% | 0/44 | 0 | 44 |  |
| 283 | `goto_label` | 0.0% | 0/17 | 0 | 17 |  |
| 284 | `goto_methods` | 0.0% | 0/40 | 0 | 40 |  |
| 285 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 286 | `hittest_morph` | 0.0% | 0/70 | 0 | 70 |  |
| 287 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 288 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 289 | `init_object_order` | 0.0% | 0/15 | 0 | 15 |  |
| 290 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 291 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 292 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 293 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 294 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 295 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 296 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 297 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 298 | `issue_9885` | 0.0% | 0/2 | 0 | 2 |  |
| 299 | `localconnection` | 0.0% | 0/579 | 0 | 579 |  |
| 300 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 301 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 302 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 303 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 304 | `movieclip_init_object` | 0.0% | 0/5 | 0 | 5 |  |
| 305 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 306 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 307 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 308 | `native_objects_swf6` | 0.0% | 0/84 | 0 | 84 |  |
| 309 | `native_objects_swf7` | 0.0% | 0/84 | 0 | 84 |  |
| 310 | `native_objects_swf8` | 0.0% | 0/84 | 0 | 84 |  |
| 311 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 312 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 313 | `new_method_wrap` | 0.0% | 0/4 | 4 | 4 |  |
| 314 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 315 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 316 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 317 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 318 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 319 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 320 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 0 |  |
| 321 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 322 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 323 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 324 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 325 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 326 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 327 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 328 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 329 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 330 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 331 | `selection` | 0.0% | 0/454 | 0 | 454 |  |
| 332 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 333 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 334 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 335 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 336 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 337 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 338 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 339 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 340 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 341 | `stylesheet` | 0.0% | 0/283 | 0 | 283 |  |
| 342 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 343 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 344 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 345 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 346 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 347 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 348 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 349 | `target_path` | 0.0% | 0/14 | 0 | 14 |  |
| 350 | `tell_target_invalid` | 0.0% | 0/6 | 4 | 6 |  |
| 351 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 4 | 5 |  |
| 352 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 353 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 354 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 355 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 356 | `timer_run_actions` | 0.0% | 0/18 | 0 | 18 |  |
| 357 | `typeof` | 0.0% | 0/22 | 0 | 22 |  |
| 358 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 359 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 360 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 361 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 362 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 363 | `watch` | 0.0% | 0/117 | 0 | 117 |  |
| 364 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 365 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 366 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 367 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 368 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 369 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 370 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 371 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 372 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 373 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
