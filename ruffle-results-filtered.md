# Ruffle Test Results (Filtered)

**Date**: 2026-02-12 19:17 UTC

**Git SHA**: `2d0fc53dda`

**Run Duration**: 28m 56s

**Filtered**: 125 tests ignored out of 616 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 491 |
| Passing | **82** (16.7%) |
| Failing | 409 |
| Total expected lines | 76804 |
| Matching lines | 31985 (41.6%) |
| Mismatched lines | 44819 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 394 | 96.3% |
| Segfault | 9 | 2.2% |
| Timeout | 4 | 1.0% |
| Runtime Error | 2 | 0.5% |

## Passing Tests

**82 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.3s |  |
| 2 | `action_to_integer` | 28 | 2.2s |  |
| 3 | `add` | 28 | 2.2s |  |
| 4 | `add2` | 354 | 2.6s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.2s |  |
| 6 | `add_swf5` | 28 | 2.2s |  |
| 7 | `array_concat` | 98 | 2.4s |  |
| 8 | `array_slice` | 34 | 2.4s |  |
| 9 | `array_splice` | 207 | 3.0s |  |
| 10 | `array_trivial` | 209 | 2.7s |  |
| 11 | `as1_constructor_v6` | 35 | 2.2s |  |
| 12 | `as1_constructor_v7` | 35 | 2.2s |  |
| 13 | `as_broadcaster_initialize` | 10 | 2.1s |  |
| 14 | `as_set_prop_flags_version_swf5` | 1 | 2.2s |  |
| 15 | `bad_swf_tag_past_eof` | 1 | 2.0s |  |
| 16 | `bitand` | 1058 | 11.1s |  |
| 17 | `bitmap_data_colortransform` | 1 | 2.5s |  |
| 18 | `bitmap_data_fillrect` | 1 | 2.3s |  |
| 19 | `bitmap_data_perlinnoise` | 1 | 3.0s |  |
| 20 | `bitmap_data_pixeldissolve_image` | 1 | 2.6s |  |
| 21 | `bitmapdata_applyfilter_colormatrix` | 1 | 2.2s |  |
| 22 | `bitor` | 1058 | 10.9s |  |
| 23 | `biturshift` | 14 | 2.7s |  |
| 24 | `biturshift_swf8` | 14 | 2.2s |  |
| 25 | `bitxor` | 1058 | 11.2s |  |
| 26 | `catch_references_registers` | 2 | 2.1s |  |
| 27 | `define_function_case_sensitive` | 2 | 2.1s |  |
| 28 | `divide_swf4` | 107 | 2.3s |  |
| 29 | `do_init_action` | 3 | 2.2s |  |
| 30 | `equals` | 32 | 2.2s |  |
| 31 | `equals2_swf5` | 926 | 10.0s |  |
| 32 | `equals2_swf6` | 926 | 10.0s |  |
| 33 | `equals2_swf7` | 926 | 10.0s |  |
| 34 | `equals_swf4` | 665 | 5.5s |  |
| 35 | `equals_swf4_alt` | 32 | 2.1s |  |
| 36 | `equals_swf5` | 32 | 2.1s |  |
| 37 | `global_is_bare` | 7 | 2.2s |  |
| 38 | `goto_execution_order` | 2 | 2.1s |  |
| 39 | `goto_rewind1` | 1 | 2.2s |  |
| 40 | `greater_swf6` | 1175 | 11.3s |  |
| 41 | `greater_swf7` | 1175 | 11.3s |  |
| 42 | `greaterthan_swf5` | 1 | 2.1s |  |
| 43 | `greaterthan_swf8` | 1 | 2.1s |  |
| 44 | `has_own_property` | 32 | 2.2s |  |
| 45 | `infinite_recursion_function_in_setter` | 131 | 2.1s |  |
| 46 | `infinite_recursion_virtual_property` | 67 | 2.1s |  |
| 47 | `issue_1086` | 1 | 2.1s |  |
| 48 | `issue_1671` | 1 | 2.1s |  |
| 49 | `issue_3446` | 1 | 2.1s |  |
| 50 | `issue_4377` | 2 | 2.1s |  |
| 51 | `issue_768` | 3 | 2.1s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 52 | `lessthan` | 41 | 2.2s |  |
| 53 | `lessthan2_swf5` | 1226 | 11.8s |  |
| 54 | `lessthan2_swf6` | 1226 | 11.9s |  |
| 55 | `lessthan2_swf7` | 1226 | 11.8s |  |
| 56 | `lessthan_swf4` | 902 | 7.6s |  |
| 57 | `lessthan_swf4_alt` | 41 | 2.2s |  |
| 58 | `lessthan_swf5` | 41 | 2.2s |  |
| 59 | `logical_ops_swf4` | 90 | 2.2s |  |
| 60 | `logical_ops_swf8` | 108 | 2.3s |  |
| 61 | `looping` | 6 | 2.2s |  |
| 62 | `mask_reapply` | 1 | 2.1s |  |
| 63 | `mask_with_drawing` | 1 | 2.2s |  |
| 64 | `movieclip_begin_gradient_fill` | 1 | 3.0s |  |
| 65 | `movieclip_line_gradient_style` | 1 | 2.8s |  |
| 66 | `nested_textfields_in_buttons` | 1 | 2.1s |  |
| 67 | `object_function` | 32 | 2.2s |  |
| 68 | `sandbox_type_local_file` | 1 | 2.2s |  |
| 69 | `single_frame` | 1 | 2.2s |  |
| 70 | `strictequals_swf6` | 902 | 9.5s |  |
| 71 | `strictly_equals` | 7 | 2.3s |  |
| 72 | `string_paths_keyevents` | 1 | 2.2s |  |
| 73 | `string_paths_timer` | 1 | 2.3s |  |
| 74 | `swf4_actions_bool` | 96 | 2.4s |  |
| 75 | `swf4_bool` | 4 | 2.2s |  |
| 76 | `swf5_encoding` | 3 | 2.2s |  |
| 77 | `this_swf7` | 41 | 2.2s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 78 | `timeline_function_def` | 7 | 2.2s |  |
| 79 | `try_finally_simple` | 16 | 2.1s |  |
| 80 | `typeof_globals` | 7 | 2.1s |  |
| 81 | `undefined_to_string_swf6` | 4 | 2.1s |  |
| 82 | `with_return` | 2 | 2.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**102 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `string_coercion` | 99.1% | 116 | 117 | 1 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 2 | `object_string_coerce_swf5` | 95.4% | 62 | 65 | 3 |  |
| 3 | `array_constructor` | 93.3% | 28 | 30 | 2 |  |
| 4 | `array_properties` | 91.7% | 33 | 36 | 3 |  |
| 5 | `set_variable_scope` | 86.2% | 50 | 58 | 8 |  |
| 6 | `swf7_case_sensitive` | 84.1% | 37 | 44 | 7 |  |
| 7 | `getproperty_swf4` | 82.1% | 23 | 28 | 5 |  |
| 8 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 9 | `movieclip_prototype_extension` | 80.0% | 4 | 5 | 1 |  |
| 10 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 11 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 12 | `stage_object_children` | 75.9% | 63 | 83 | 20 |  |
| 13 | `define_function2` | 75.0% | 6 | 8 | 2 |  |
| 14 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 15 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 16 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 17 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 18 | `object_constructor` | 72.7% | 24 | 33 | 9 |  |
| 19 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 20 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 21 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 22 | `point` | 70.9% | 124 | 175 | 51 |  |
| 23 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 24 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 25 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 26 | `get_variable_in_scope` | 69.0% | 20 | 29 | 9 |  |
| 27 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 28 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 29 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 30 | `primitive_instanceof` | 67.6% | 25 | 37 | 12 |  |
| 31 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 32 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 33 | `delete` | 66.7% | 2 | 3 | 1 |  |
| 34 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 35 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 36 | `goto_both_ways2` | 66.7% | 2 | 3 | 1 |  |
| 37 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 38 | `goto_rewind2` | 66.7% | 2 | 3 | 1 |  |
| 39 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 40 | `o` | 66.7% | 2 | 3 | 1 |  |
| 41 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 42 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 43 | `error` | 65.5% | 38 | 58 | 20 |  |
| 44 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 45 | `getproperty` | 64.3% | 18 | 28 | 10 |  |
| 46 | `getproperty_swf5` | 64.3% | 18 | 28 | 10 |  |
| 47 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 48 | `globals_swf6` | 64.1% | 195 | 304 | 109 |  |
| 49 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 50 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 51 | `with` | 63.3% | 31 | 49 | 18 |  |
| 52 | `globals_swf7` | 63.2% | 192 | 304 | 112 |  |
| 53 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 54 | `globals_swf5` | 61.8% | 188 | 304 | 116 |  |
| 55 | `arguments` | 61.4% | 78 | 127 | 49 |  |
| 56 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 57 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 58 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 59 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 60 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 61 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 62 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 63 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 64 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 65 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 66 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 67 | `swf6_case_insensitive` | 59.1% | 26 | 44 | 18 |  |
| 68 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 69 | `with_variable_scopes` | 58.1% | 25 | 43 | 18 |  |
| 70 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 71 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 72 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 73 | `primitive_type_globals` | 57.3% | 319 | 557 | 238 |  |
| 74 | `escape` | 57.1% | 8 | 14 | 6 |  |
| 75 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 76 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 77 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 78 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 79 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 80 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 81 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 82 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 83 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 84 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 85 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 86 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 87 | `movieclip_focusenabled` | 52.5% | 52 | 99 | 47 |  |
| 88 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 89 | `as_set_prop_flags_version` | 51.6% | 16 | 31 | 15 |  |
| 90 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 91 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 92 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 93 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 94 | `goto_advance2` | 50.0% | 1 | 2 | 1 |  |
| 95 | `goto_rewind3` | 50.0% | 1 | 2 | 1 |  |
| 96 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 97 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 98 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 99 | `prototype_delete` | 50.0% | 6 | 12 | 6 |  |
| 100 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 101 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 102 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**9 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `array_length` | 4.3s |  |
| 2 | `as2_oop` | 4.3s |  |
| 3 | `device_font_spacing` | 11.6s |  |
| 4 | `duplicate_movie_clip_drawing` | 4.2s |  |
| 5 | `enumerate` | 4.2s |  |
| 6 | `extends_chain` | 4.8s |  |
| 7 | `issue_2166` | 4.2s |  |
| 8 | `path_string` | 4.6s |  |
| 9 | `swf4_actions_coercion_order` | 4.4s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.1s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.1s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.2s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.2s |  |
| 3 | `timeout` | runtime timeout (>10s) | 16.7s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.6s |  |

## All Output Mismatches

**394 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `string_coercion` | 99.1% | 116/117 | 117 | 117 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 2 | `object_string_coerce_swf5` | 95.4% | 62/65 | 65 | 62 |  |
| 3 | `array_constructor` | 93.3% | 28/30 | 30 | 30 |  |
| 4 | `array_properties` | 91.7% | 33/36 | 36 | 36 |  |
| 5 | `set_variable_scope` | 86.2% | 50/58 | 58 | 58 |  |
| 6 | `swf7_case_sensitive` | 84.1% | 37/44 | 44 | 44 |  |
| 7 | `getproperty_swf4` | 82.1% | 23/28 | 28 | 28 |  |
| 8 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 9 | `movieclip_prototype_extension` | 80.0% | 4/5 | 5 | 5 |  |
| 10 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 11 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 12 | `stage_object_children` | 75.9% | 63/83 | 83 | 83 |  |
| 13 | `define_function2` | 75.0% | 6/8 | 8 | 8 |  |
| 14 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 15 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 16 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 17 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 18 | `object_constructor` | 72.7% | 24/33 | 33 | 33 |  |
| 19 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 20 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 21 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 22 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 23 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 24 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 25 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 26 | `get_variable_in_scope` | 69.0% | 20/29 | 29 | 29 |  |
| 27 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 28 | `object_string_coerce_swf6` | 67.6% | 46/68 | 65 | 68 |  |
| 29 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 30 | `primitive_instanceof` | 67.6% | 25/37 | 37 | 37 |  |
| 31 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 32 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 33 | `delete` | 66.7% | 2/3 | 3 | 3 |  |
| 34 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 35 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 36 | `goto_both_ways2` | 66.7% | 2/3 | 2 | 3 |  |
| 37 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 38 | `goto_rewind2` | 66.7% | 2/3 | 2 | 3 |  |
| 39 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 40 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 41 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 42 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 43 | `error` | 65.5% | 38/58 | 58 | 58 |  |
| 44 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 45 | `getproperty` | 64.3% | 18/28 | 28 | 28 |  |
| 46 | `getproperty_swf5` | 64.3% | 18/28 | 28 | 28 |  |
| 47 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 48 | `globals_swf6` | 64.1% | 195/304 | 304 | 304 |  |
| 49 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 50 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 51 | `with` | 63.3% | 31/49 | 47 | 49 |  |
| 52 | `globals_swf7` | 63.2% | 192/304 | 304 | 304 |  |
| 53 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 54 | `globals_swf5` | 61.8% | 188/304 | 304 | 304 |  |
| 55 | `arguments` | 61.4% | 78/127 | 92 | 127 |  |
| 56 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 57 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 58 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 59 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 60 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 61 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 62 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 63 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 64 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 65 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 66 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 67 | `swf6_case_insensitive` | 59.1% | 26/44 | 44 | 42 |  |
| 68 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 69 | `with_variable_scopes` | 58.1% | 25/43 | 43 | 43 |  |
| 70 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 71 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 72 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 73 | `primitive_type_globals` | 57.3% | 319/557 | 555 | 557 |  |
| 74 | `escape` | 57.1% | 8/14 | 14 | 14 |  |
| 75 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 76 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 77 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 78 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 79 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 80 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 81 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 82 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 83 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 84 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 85 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 86 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 87 | `movieclip_focusenabled` | 52.5% | 52/99 | 99 | 99 |  |
| 88 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 336 |  |
| 89 | `as_set_prop_flags_version` | 51.6% | 16/31 | 29 | 31 |  |
| 90 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 91 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 92 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 93 | `execution_order3` | 50.0% | 2/4 | 3 | 4 |  |
| 94 | `goto_advance2` | 50.0% | 1/2 | 1 | 2 |  |
| 95 | `goto_rewind3` | 50.0% | 1/2 | 1 | 2 |  |
| 96 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 97 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 98 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 99 | `prototype_delete` | 50.0% | 6/12 | 12 | 12 |  |
| 100 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 101 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 102 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 103 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 104 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 105 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 106 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 107 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 108 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
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
| 136 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 137 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 138 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 139 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 140 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 141 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 142 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 143 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 144 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 145 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 146 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 147 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 148 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 149 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 150 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 151 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 152 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 153 | `unescape` | 20.9% | 9/43 | 42 | 43 |  |
| 154 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 155 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 156 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 157 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 158 | `global_array` | 20.0% | 1/5 | 5 | 4 |  |
| 159 | `xml_attributes_read` | 20.0% | 1/5 | 3 | 5 |  |
| 160 | `frame_size_translated_negative` | 19.0% | 4/21 | 20 | 21 |  |
| 161 | `frame_size_translated_positive` | 19.0% | 4/21 | 20 | 21 |  |
| 162 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 163 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 164 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 165 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 166 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 167 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 168 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 169 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 170 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 171 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 172 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 173 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 174 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 175 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 176 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 177 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 178 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 179 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 180 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 181 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 182 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 183 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 184 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 185 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 186 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 187 | `string_paths_other` | 11.1% | 4/36 | 28 | 36 |  |
| 188 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 189 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 190 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 191 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 192 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 193 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
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
| 207 | `funky_function_calls` | 5.4% | 3/56 | 12 | 56 |  |
| 208 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 209 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 210 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 211 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 212 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 213 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 214 | `register_class` | 4.5% | 3/66 | 27 | 66 |  |
| 215 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 216 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 217 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 218 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 219 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 220 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 221 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 222 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 223 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 224 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
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
| 270 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 271 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 272 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 273 | `duplicate_movie_clip` | 0.0% | 0/20 | 1 | 20 |  |
| 274 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 275 | `edittext_html_roundtrip` | 0.0% | 0/17 | 1 | 17 |  |
| 276 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 277 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 278 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 279 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 280 | `extends_native_type` | 0.0% | 0/11 | 1 | 11 |  |
| 281 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 282 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 283 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 284 | `file_reference_browse_cancel` | 0.0% | 0/21 | 1 | 21 |  |
| 285 | `function_base_clip` | 0.0% | 0/8 | 1 | 8 |  |
| 286 | `function_base_clip_readded` | 0.0% | 0/11 | 1 | 11 |  |
| 287 | `function_suppress_and_preload` | 0.0% | 0/28 | 1 | 28 |  |
| 288 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 289 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 290 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 291 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 292 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 293 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 1 | 1145 |  |
| 294 | `global_swf6_7_8` | 0.0% | 0/15 | 1 | 15 |  |
| 295 | `goto_execution_order2` | 0.0% | 0/2 | 1 | 2 |  |
| 296 | `goto_frame` | 0.0% | 0/12 | 1 | 12 |  |
| 297 | `goto_frame2` | 0.0% | 0/44 | 1 | 44 |  |
| 298 | `goto_label` | 0.0% | 0/17 | 1 | 17 |  |
| 299 | `goto_methods` | 0.0% | 0/40 | 1 | 40 |  |
| 300 | `hittest_lockroot` | 0.0% | 0/15 | 1 | 15 |  |
| 301 | `hittest_morph` | 0.0% | 0/70 | 1 | 70 |  |
| 302 | `hittest_morph_input` | 0.0% | 0/1 | 1 | 1 |  |
| 303 | `hittest_winding_rule` | 0.0% | 0/12 | 1 | 12 |  |
| 304 | `init_array_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 305 | `init_object_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 306 | `init_object_order` | 0.0% | 0/15 | 1 | 15 |  |
| 307 | `input_dead_keys_windows` | 0.0% | 0/15 | 1 | 15 |  |
| 308 | `instanceof_coercions` | 0.0% | 0/88 | 1 | 88 |  |
| 309 | `interface_implements_op` | 0.0% | 0/47 | 1 | 47 |  |
| 310 | `issue_1104` | 0.0% | 0/2 | 1 | 2 |  |
| 311 | `issue_2084` | 0.0% | 0/16 | 1 | 16 |  |
| 312 | `issue_2870` | 0.0% | 0/3 | 1 | 3 |  |
| 313 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 314 | `issue_9327` | 0.0% | 0/2 | 1 | 2 |  |
| 315 | `issue_9885` | 0.0% | 0/2 | 1 | 2 |  |
| 316 | `lock_root` | 0.0% | 0/1 | 1 | 1 |  |
| 317 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 1 | 35 |  |
| 318 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 319 | `movieclip_gettextsnapshot` | 0.0% | 0/112 | 21 | 112 |  |
| 320 | `movieclip_in_removed_button` | 0.0% | 0/4 | 1 | 4 |  |
| 321 | `movieclip_init_object` | 0.0% | 0/5 | 1 | 5 |  |
| 322 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 323 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 1 | 4 |  |
| 324 | `named_shapes` | 0.0% | 0/14 | 1 | 14 |  |
| 325 | `native_double_construct` | 0.0% | 0/12 | 1 | 12 |  |
| 326 | `native_objects_swf6` | 0.0% | 0/84 | 1 | 84 |  |
| 327 | `native_objects_swf7` | 0.0% | 0/84 | 1 | 84 |  |
| 328 | `native_objects_swf8` | 0.0% | 0/84 | 1 | 84 |  |
| 329 | `native_subclasses` | 0.0% | 0/191 | 1 | 191 |  |
| 330 | `netconnection_send_remote` | 0.0% | 0/50 | 1 | 50 |  |
| 331 | `new_method_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 332 | `new_object_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 333 | `object_properties` | 0.0% | 0/31 | 1 | 31 |  |
| 334 | `object_resolve` | 0.0% | 0/38 | 1 | 38 |  |
| 335 | `on_construct` | 0.0% | 0/25 | 1 | 25 |  |
| 336 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 337 | `place_and_lookup` | 0.0% | 0/30 | 1 | 30 |  |
| 338 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 339 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 1 |  |
| 340 | `register_class_return_value` | 0.0% | 0/16 | 1 | 16 |  |
| 341 | `register_class_swf6` | 0.0% | 0/37 | 1 | 37 |  |
| 342 | `register_class_with_sound` | 0.0% | 0/11 | 1 | 11 |  |
| 343 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 344 | `removed_target_clip_scope` | 0.0% | 0/35 | 1 | 35 |  |
| 345 | `resolve_different_root` | 0.0% | 0/2 | 1 | 2 |  |
| 346 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 347 | `root_onload` | 0.0% | 0/1 | 1 | 1 |  |
| 348 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 349 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 350 | `selection` | 0.0% | 0/454 | 1 | 454 |  |
| 351 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 352 | `slash_syntax` | 0.0% | 0/14 | 1 | 14 |  |
| 353 | `stage_object_enumerate` | 0.0% | 0/4 | 1 | 4 |  |
| 354 | `string_methods_negative_args` | 0.0% | 0/240 | 1 | 240 |  |
| 355 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 356 | `string_paths_eval` | 0.0% | 0/4 | 1 | 4 |  |
| 357 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 358 | `string_paths_unload` | 0.0% | 0/1 | 1 | 1 |  |
| 359 | `string_paths_variable_scopes` | 0.0% | 0/5 | 1 | 5 |  |
| 360 | `stylesheet` | 0.0% | 0/283 | 1 | 283 |  |
| 361 | `super_edge_cases` | 0.0% | 0/39 | 1 | 39 |  |
| 362 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 363 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 364 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 365 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 366 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 367 | `target_clip_swf5` | 0.0% | 0/2 | 1 | 2 |  |
| 368 | `target_clip_swf6` | 0.0% | 0/2 | 1 | 2 |  |
| 369 | `target_path` | 0.0% | 0/14 | 1 | 14 |  |
| 370 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 371 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 372 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 373 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 |  |
| 374 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 375 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 376 | `timer_run_actions` | 0.0% | 0/18 | 1 | 18 |  |
| 377 | `typeof` | 0.0% | 0/22 | 1 | 22 |  |
| 378 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 379 | `unload_clip_event` | 0.0% | 0/4 | 1 | 4 |  |
| 380 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 381 | `use_hand_cursor` | 0.0% | 0/8 | 1 | 8 |  |
| 382 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 383 | `watch` | 0.0% | 0/117 | 1 | 117 |  |
| 384 | `watch_textfield` | 0.0% | 0/12 | 1 | 12 |  |
| 385 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 |  |
| 386 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 387 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 388 | `xml_ignore_comments` | 0.0% | 0/21 | 1 | 21 |  |
| 389 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 390 | `xml_reparenting` | 0.0% | 0/14 | 1 | 14 |  |
| 391 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 392 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 393 | `xml_unescaping` | 0.0% | 0/23 | 1 | 23 |  |
| 394 | `xmlnode_proto` | 0.0% | 0/1 | 1 | 1 |  |
