# Ruffle Test Results (Filtered)

**Date**: 2026-02-13 06:42 UTC

**Git SHA**: `360cd1250a`

**Run Duration**: 32m 36s

**Filtered**: 125 tests ignored out of 616 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 491 |
| Passing | **121** (24.6%) |
| Failing | 370 |
| Total expected lines | 76941 |
| Matching lines | 32341 (42.0%) |
| Mismatched lines | 44600 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 360 | 97.3% |
| Segfault | 4 | 1.1% |
| Timeout | 4 | 1.1% |
| Runtime Error | 2 | 0.5% |

## Passing Tests

**121 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.9s |  |
| 2 | `action_to_integer` | 28 | 2.6s |  |
| 3 | `add` | 28 | 2.7s |  |
| 4 | `add2` | 354 | 3.0s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.6s |  |
| 6 | `add_swf5` | 28 | 2.6s |  |
| 7 | `array_concat` | 98 | 2.8s |  |
| 8 | `array_constructor` | 30 | 2.7s |  |
| 9 | `array_properties` | 36 | 2.7s |  |
| 10 | `array_slice` | 34 | 2.7s |  |
| 11 | `array_splice` | 207 | 3.4s |  |
| 12 | `array_trivial` | 209 | 3.1s |  |
| 13 | `as1_constructor_v6` | 35 | 2.7s |  |
| 14 | `as1_constructor_v7` | 35 | 2.7s |  |
| 15 | `as_broadcaster_initialize` | 10 | 2.5s |  |
| 16 | `as_set_prop_flags_version_swf5` | 1 | 2.6s |  |
| 17 | `as_set_prop_flags_version_swf6` | 1 | 2.6s |  |
| 18 | `as_set_prop_flags_version_swf7` | 1 | 2.6s |  |
| 19 | `as_set_prop_flags_version_swf8` | 1 | 2.6s |  |
| 20 | `as_set_prop_flags_version_swf9` | 1 | 2.6s |  |
| 21 | `bad_swf_tag_past_eof` | 0 | 2.5s |  |
| 22 | `bitand` | 1058 | 9.6s |  |
| 23 | `bitmap_data_colortransform` | 0 | 2.8s |  |
| 24 | `bitmap_data_fillrect` | 0 | 2.7s |  |
| 25 | `bitmap_data_perlinnoise` | 0 | 3.3s |  |
| 26 | `bitmap_data_pixeldissolve_image` | 0 | 3.1s |  |
| 27 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.6s |  |
| 28 | `bitor` | 1058 | 9.6s |  |
| 29 | `biturshift` | 14 | 3.9s |  |
| 30 | `biturshift_swf8` | 14 | 2.6s |  |
| 31 | `bitxor` | 1058 | 9.4s |  |
| 32 | `call_method_empty_name` | 1 | 2.5s |  |
| 33 | `catch_references_registers` | 2 | 2.5s |  |
| 34 | `define_function2` | 8 | 2.5s |  |
| 35 | `define_function_case_sensitive` | 2 | 2.5s |  |
| 36 | `delete` | 3 | 2.6s |  |
| 37 | `divide_swf4` | 107 | 2.8s |  |
| 38 | `do_init_action` | 3 | 2.6s |  |
| 39 | `equals` | 32 | 2.6s |  |
| 40 | `equals2_swf5` | 926 | 10.7s |  |
| 41 | `equals2_swf6` | 926 | 10.9s |  |
| 42 | `equals2_swf7` | 926 | 10.8s |  |
| 43 | `equals_swf4` | 665 | 6.1s |  |
| 44 | `equals_swf4_alt` | 32 | 2.6s |  |
| 45 | `equals_swf5` | 32 | 2.6s |  |
| 46 | `error` | 58 | 2.7s |  |
| 47 | `escape` | 14 | 2.5s |  |
| 48 | `execution_order3` | 4 | 2.5s |  |
| 49 | `get_variable_in_scope` | 29 | 2.7s |  |
| 50 | `getproperty` | 28 | 2.6s |  |
| 51 | `getproperty_swf4` | 28 | 2.6s |  |
| 52 | `getproperty_swf5` | 28 | 2.6s |  |
| 53 | `global_array` | 3 | 2.5s |  |
| 54 | `global_is_bare` | 7 | 2.5s |  |
| 55 | `goto_advance2` | 2 | 2.6s |  |
| 56 | `goto_both_ways1` | 3 | 4.0s |  |
| 57 | `goto_both_ways2` | 3 | 2.7s |  |
| 58 | `goto_execution_order` | 2 | 2.6s |  |
| 59 | `goto_execution_order2` | 2 | 2.7s |  |
| 60 | `goto_rewind1` | 1 | 2.7s |  |
| 61 | `goto_rewind2` | 3 | 2.7s |  |
| 62 | `goto_rewind3` | 2 | 2.6s |  |
| 63 | `greater_swf6` | 1175 | 12.3s |  |
| 64 | `greater_swf7` | 1175 | 12.3s |  |
| 65 | `greaterthan_swf5` | 1 | 2.6s |  |
| 66 | `greaterthan_swf8` | 1 | 2.6s |  |
| 67 | `has_own_property` | 32 | 2.8s |  |
| 68 | `infinite_recursion_function_in_setter` | 131 | 2.7s |  |
| 69 | `infinite_recursion_virtual_property` | 67 | 2.6s |  |
| 70 | `init_array_invalid` | 4 | 2.6s |  |
| 71 | `init_object_invalid` | 4 | 2.6s |  |
| 72 | `issue_1086` | 1 | 2.6s |  |
| 73 | `issue_1671` | 0 | 2.6s |  |
| 74 | `issue_3446` | 1 | 2.6s |  |
| 75 | `issue_4377` | 2 | 2.6s |  |
| 76 | `issue_710` | 4 | 2.6s |  |
| 77 | `issue_768` | 3 | 2.6s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 78 | `lessthan` | 41 | 2.8s |  |
| 79 | `lessthan2_swf5` | 1226 | 12.8s |  |
| 80 | `lessthan2_swf6` | 1226 | 12.8s |  |
| 81 | `lessthan2_swf7` | 1226 | 12.8s |  |
| 82 | `lessthan_swf4` | 902 | 8.6s |  |
| 83 | `lessthan_swf4_alt` | 41 | 2.7s |  |
| 84 | `lessthan_swf5` | 41 | 2.7s |  |
| 85 | `logical_ops_swf4` | 90 | 2.7s |  |
| 86 | `logical_ops_swf8` | 108 | 2.7s |  |
| 87 | `looping` | 6 | 2.5s |  |
| 88 | `mask_reapply` | 0 | 2.5s |  |
| 89 | `mask_with_drawing` | 0 | 2.6s |  |
| 90 | `movieclip_begin_gradient_fill` | 0 | 3.2s |  |
| 91 | `movieclip_line_gradient_style` | 0 | 3.1s |  |
| 92 | `movieclip_prototype_extension` | 5 | 2.5s |  |
| 93 | `nested_textfields_in_buttons` | 0 | 2.5s |  |
| 94 | `new_method_wrap` | 4 | 2.5s |  |
| 95 | `new_object_enumerate` | 7 | 2.5s |  |
| 96 | `new_object_wrap` | 4 | 2.5s |  |
| 97 | `object_constructor` | 33 | 2.6s |  |
| 98 | `object_function` | 32 | 2.6s |  |
| 99 | `object_string_coerce_swf5` | 62 | 2.6s |  |
| 100 | `primitive_instanceof` | 37 | 2.6s |  |
| 101 | `prototype_delete` | 12 | 2.5s |  |
| 102 | `recursive_prototypes` | 0 | 2.5s |  |
| 103 | `sandbox_type_local_network` | 1 | 2.5s |  |
| 104 | `single_frame` | 1 | 2.5s |  |
| 105 | `stage_object_properties_get_var` | 5 | 2.5s |  |
| 106 | `strictequals_swf6` | 902 | 9.2s |  |
| 107 | `strictly_equals` | 7 | 2.6s |  |
| 108 | `string_coercion` | 117 | 3.2s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 109 | `string_paths_keyevents` | 0 | 2.6s |  |
| 110 | `string_paths_timer` | 0 | 2.6s |  |
| 111 | `swf4_actions_bool` | 96 | 2.7s |  |
| 112 | `swf4_bool` | 4 | 2.6s |  |
| 113 | `swf4_function_calls` | 7 | 2.6s |  |
| 114 | `swf5_encoding` | 3 | 2.7s |  |
| 115 | `this_swf7` | 41 | 2.6s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 116 | `timeline_function_def` | 7 | 2.6s |  |
| 117 | `try_finally_simple` | 16 | 2.5s |  |
| 118 | `typeof_globals` | 7 | 2.5s |  |
| 119 | `undefined_to_string_swf6` | 4 | 2.5s |  |
| 120 | `unescape` | 43 | 2.6s |  |
| 121 | `with_return` | 2 | 2.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**83 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `swf7_case_sensitive` | 93.2% | 41 | 44 | 3 |  |
| 2 | `set_variable_scope` | 87.9% | 51 | 58 | 7 |  |
| 3 | `array_length` | 83.3% | 35 | 42 | 7 |  |
| 4 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 5 | `stage_object_children` | 79.5% | 66 | 83 | 17 |  |
| 6 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 7 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 8 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 9 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 10 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 11 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 12 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 13 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 14 | `point` | 70.9% | 124 | 175 | 51 |  |
| 15 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 16 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 17 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 18 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 19 | `define_function2_preload` | 69.2% | 9 | 13 | 4 |  |
| 20 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 21 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 22 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 23 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 24 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 25 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 26 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 27 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 28 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 29 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 30 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 31 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 32 | `o` | 66.7% | 2 | 3 | 1 |  |
| 33 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 34 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 35 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 36 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 37 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 38 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 39 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 40 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 41 | `with` | 61.2% | 30 | 49 | 19 |  |
| 42 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 43 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 44 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 45 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 46 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 47 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 48 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 49 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 50 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 51 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 52 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 53 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 54 | `as_set_prop_flags_version` | 58.1% | 18 | 31 | 13 |  |
| 55 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 56 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 57 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 58 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 59 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 60 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 61 | `swf6_case_insensitive` | 56.8% | 25 | 44 | 19 |  |
| 62 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 63 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 64 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 65 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 66 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 67 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 68 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 69 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 70 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 71 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 72 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 73 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 74 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 75 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 76 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 77 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 78 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 79 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 80 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 81 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 82 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 83 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 12.1s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.6s |  |
| 3 | `path_string` | 5.0s |  |
| 4 | `swf4_actions_coercion_order` | 4.9s |  |

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
| 1 | `parse_float` | runtime timeout (>10s) | 13.6s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.6s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.7s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.9s |  |

## All Output Mismatches

**360 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `swf7_case_sensitive` | 93.2% | 41/44 | 44 | 44 |  |
| 2 | `set_variable_scope` | 87.9% | 51/58 | 58 | 58 |  |
| 3 | `array_length` | 83.3% | 35/42 | 42 | 42 |  |
| 4 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 5 | `stage_object_children` | 79.5% | 66/83 | 83 | 83 |  |
| 6 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 7 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 8 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 9 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 10 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 11 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 12 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 13 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 14 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 15 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 16 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 17 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 18 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 19 | `define_function2_preload` | 69.2% | 9/13 | 13 | 13 |  |
| 20 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 21 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 22 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 23 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 24 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 25 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 26 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 27 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 28 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 29 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 30 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 31 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 32 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 33 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 34 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 35 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 36 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 37 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 38 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 39 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 40 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 41 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 42 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 43 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 44 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 45 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 46 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 47 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 48 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 49 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 50 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 51 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 52 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 53 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 54 | `as_set_prop_flags_version` | 58.1% | 18/31 | 29 | 31 |  |
| 55 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 56 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 57 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 58 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 59 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 60 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 61 | `swf6_case_insensitive` | 56.8% | 25/44 | 44 | 42 |  |
| 62 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 63 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 64 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 65 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 66 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 67 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 68 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 69 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 70 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 71 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 72 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 73 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 74 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 75 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 76 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 77 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 78 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 79 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 80 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 81 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 82 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 83 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 84 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 85 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 86 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 87 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 88 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 89 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 90 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 91 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 92 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 93 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 94 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 95 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 96 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 97 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 98 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 99 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 100 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 101 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 102 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 103 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 104 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 105 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 106 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 107 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 108 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 109 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 110 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 111 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 112 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 113 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 114 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 115 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 116 | `frame_size_translated_negative` | 28.6% | 6/21 | 20 | 21 |  |
| 117 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 118 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 119 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 120 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 121 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 122 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 123 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 124 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 125 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 126 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 127 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 128 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 129 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 130 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 131 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 132 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 133 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 134 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 135 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 136 | `funky_function_calls` | 21.4% | 12/56 | 32 | 56 |  |
| 137 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 138 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 139 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 140 | `target_clip_removed` | 20.0% | 1/5 | 5 | 5 |  |
| 141 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 142 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 143 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 144 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 145 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 146 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 147 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 148 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 149 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 150 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 151 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 152 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 153 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 154 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 155 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 156 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 157 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 158 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 159 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 160 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 161 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 162 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 163 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 164 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 165 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 166 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 167 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 168 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 169 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 170 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 171 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 172 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 173 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 174 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 175 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 176 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 177 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 178 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 179 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 180 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 181 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 182 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 183 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 184 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 185 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 186 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 187 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 188 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 189 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 190 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 191 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 192 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 193 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 194 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 195 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 196 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 197 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 198 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 199 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 200 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 201 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 202 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 203 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 204 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 205 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 206 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 207 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 208 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 209 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 210 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 21 | 112 |  |
| 211 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 212 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 213 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 214 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 215 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 216 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 217 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 218 | `global_proto_decls_delete` | 0.0% | 1/4158 | 20 | 4158 |  |
| 219 | `global_proto_decls` | 0.0% | 1/4497 | 20 | 4497 |  |
| 220 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 221 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 222 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 223 | `as2_oop` | 0.0% | 0/13 | 0 | 13 |  |
| 224 | `as2_super_and_this_v6` | 0.0% | 0/97 | 0 | 97 |  |
| 225 | `as2_super_and_this_v8` | 0.0% | 0/85 | 0 | 85 |  |
| 226 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 0 | 40 |  |
| 227 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 228 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 229 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 230 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 231 | `button_children` | 0.0% | 0/8 | 0 | 8 |  |
| 232 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 233 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 234 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 235 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 236 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 237 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 238 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 239 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 240 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 241 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 242 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 243 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 244 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 245 | `color` | 0.0% | 0/57 | 0 | 57 |  |
| 246 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 247 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 248 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 249 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 250 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 251 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 252 | `duplicate_movie_clip` | 0.0% | 0/20 | 0 | 20 |  |
| 253 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 254 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 255 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 256 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 257 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 258 | `extends_chain` | 0.0% | 0/134 | 0 | 134 |  |
| 259 | `extends_native_type` | 0.0% | 0/11 | 0 | 11 |  |
| 260 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 261 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 262 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 263 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 264 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 265 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 266 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 267 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 268 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 269 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 270 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 271 | `goto_frame` | 0.0% | 0/12 | 0 | 12 |  |
| 272 | `goto_frame2` | 0.0% | 0/44 | 0 | 44 |  |
| 273 | `goto_label` | 0.0% | 0/17 | 0 | 17 |  |
| 274 | `goto_methods` | 0.0% | 0/40 | 0 | 40 |  |
| 275 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 276 | `hittest_morph` | 0.0% | 0/70 | 0 | 70 |  |
| 277 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 278 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 279 | `init_object_order` | 0.0% | 0/15 | 0 | 15 |  |
| 280 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 281 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 282 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 283 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 284 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 285 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 286 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 287 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 288 | `issue_9885` | 0.0% | 0/2 | 0 | 2 |  |
| 289 | `localconnection` | 0.0% | 0/579 | 0 | 579 |  |
| 290 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 291 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 292 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 293 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 294 | `movieclip_init_object` | 0.0% | 0/5 | 0 | 5 |  |
| 295 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 296 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 297 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 298 | `native_objects_swf6` | 0.0% | 0/84 | 0 | 84 |  |
| 299 | `native_objects_swf7` | 0.0% | 0/84 | 0 | 84 |  |
| 300 | `native_objects_swf8` | 0.0% | 0/84 | 0 | 84 |  |
| 301 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 302 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 303 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 304 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 305 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 306 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 307 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 308 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 309 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 310 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 311 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 312 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 313 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 314 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 315 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 316 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 317 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 318 | `selection` | 0.0% | 0/454 | 0 | 454 |  |
| 319 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 320 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 321 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 322 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 323 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 324 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 325 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 326 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 327 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 328 | `stylesheet` | 0.0% | 0/283 | 0 | 283 |  |
| 329 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 330 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 331 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 332 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 333 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 334 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 335 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 336 | `target_path` | 0.0% | 0/14 | 0 | 14 |  |
| 337 | `tell_target_invalid` | 0.0% | 0/6 | 4 | 6 |  |
| 338 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 4 | 5 |  |
| 339 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 340 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 341 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 342 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 343 | `timer_run_actions` | 0.0% | 0/18 | 0 | 18 |  |
| 344 | `typeof` | 0.0% | 0/22 | 0 | 22 |  |
| 345 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 346 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 347 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 348 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 349 | `variable_args` | 0.0% | 0/6 | 6 | 5 |  |
| 350 | `watch` | 0.0% | 0/117 | 0 | 117 |  |
| 351 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 352 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 353 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 354 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 355 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 356 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 357 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 358 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 359 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 360 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
