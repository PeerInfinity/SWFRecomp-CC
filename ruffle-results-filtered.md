# Ruffle Test Results (Filtered)

**Date**: 2026-02-12 17:23 UTC

**Git SHA**: `f245517a7d`

**Run Duration**: 28m 19s

**Filtered**: 125 tests ignored out of 616 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 491 |
| Passing | **78** (15.9%) |
| Failing | 413 |
| Total expected lines | 76093 |
| Matching lines | 31875 (41.9%) |
| Mismatched lines | 44218 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 397 | 96.1% |
| Segfault | 9 | 2.2% |
| Timeout | 4 | 1.0% |
| Runtime Error | 3 | 0.7% |

## Passing Tests

**78 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 5.6s |  |
| 2 | `action_to_integer` | 28 | 2.1s |  |
| 3 | `add` | 28 | 2.2s |  |
| 4 | `add2` | 354 | 2.6s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.1s |  |
| 6 | `add_swf5` | 28 | 2.2s |  |
| 7 | `array_concat` | 98 | 2.3s |  |
| 8 | `array_slice` | 34 | 2.3s |  |
| 9 | `array_splice` | 207 | 3.1s |  |
| 10 | `array_trivial` | 209 | 2.8s |  |
| 11 | `as_broadcaster_initialize` | 10 | 2.1s |  |
| 12 | `as_set_prop_flags_version_swf5` | 1 | 2.1s |  |
| 13 | `bad_swf_tag_past_eof` | 1 | 2.0s |  |
| 14 | `bitand` | 1058 | 11.0s |  |
| 15 | `bitmap_data_colortransform` | 1 | 2.5s |  |
| 16 | `bitmap_data_fillrect` | 1 | 2.3s |  |
| 17 | `bitmap_data_perlinnoise` | 1 | 3.0s |  |
| 18 | `bitmap_data_pixeldissolve_image` | 1 | 2.7s |  |
| 19 | `bitmapdata_applyfilter_colormatrix` | 1 | 2.2s |  |
| 20 | `bitor` | 1058 | 11.1s |  |
| 21 | `biturshift` | 14 | 3.7s |  |
| 22 | `biturshift_swf8` | 14 | 2.1s |  |
| 23 | `bitxor` | 1058 | 10.7s |  |
| 24 | `catch_references_registers` | 2 | 2.0s |  |
| 25 | `define_function_case_sensitive` | 2 | 2.1s |  |
| 26 | `divide_swf4` | 107 | 2.2s |  |
| 27 | `do_init_action` | 3 | 2.1s |  |
| 28 | `equals` | 32 | 2.3s |  |
| 29 | `equals2_swf5` | 926 | 11.0s |  |
| 30 | `equals2_swf6` | 926 | 10.8s |  |
| 31 | `equals2_swf7` | 926 | 10.9s |  |
| 32 | `equals_swf4` | 665 | 6.0s |  |
| 33 | `equals_swf4_alt` | 32 | 2.2s |  |
| 34 | `equals_swf5` | 32 | 2.2s |  |
| 35 | `global_is_bare` | 7 | 2.1s |  |
| 36 | `goto_execution_order` | 2 | 2.0s |  |
| 37 | `goto_rewind1` | 1 | 2.1s |  |
| 38 | `greater_swf6` | 1175 | 11.2s |  |
| 39 | `greater_swf7` | 1175 | 11.2s |  |
| 40 | `greaterthan_swf5` | 1 | 2.1s |  |
| 41 | `greaterthan_swf8` | 1 | 2.1s |  |
| 42 | `infinite_recursion_function_in_setter` | 131 | 2.1s |  |
| 43 | `infinite_recursion_virtual_property` | 67 | 2.1s |  |
| 44 | `issue_1086` | 1 | 2.0s |  |
| 45 | `issue_1671` | 1 | 2.0s |  |
| 46 | `issue_3446` | 1 | 2.1s |  |
| 47 | `issue_4377` | 2 | 2.1s |  |
| 48 | `issue_768` | 3 | 2.1s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 49 | `lessthan` | 41 | 2.2s |  |
| 50 | `lessthan2_swf5` | 1226 | 11.9s |  |
| 51 | `lessthan2_swf6` | 1226 | 11.7s |  |
| 52 | `lessthan2_swf7` | 1226 | 11.8s |  |
| 53 | `lessthan_swf4` | 902 | 7.5s |  |
| 54 | `lessthan_swf4_alt` | 41 | 2.1s |  |
| 55 | `lessthan_swf5` | 41 | 2.2s |  |
| 56 | `logical_ops_swf4` | 90 | 2.2s |  |
| 57 | `logical_ops_swf8` | 108 | 2.3s |  |
| 58 | `looping` | 6 | 2.1s |  |
| 59 | `mask_reapply` | 1 | 2.1s |  |
| 60 | `mask_with_drawing` | 1 | 2.1s |  |
| 61 | `movieclip_begin_gradient_fill` | 1 | 2.9s |  |
| 62 | `movieclip_line_gradient_style` | 1 | 2.7s |  |
| 63 | `nested_textfields_in_buttons` | 1 | 2.1s |  |
| 64 | `sandbox_type_local_file` | 1 | 2.0s |  |
| 65 | `single_frame` | 1 | 2.0s |  |
| 66 | `strictequals_swf6` | 902 | 8.1s |  |
| 67 | `strictly_equals` | 7 | 2.1s |  |
| 68 | `string_paths_keyevents` | 1 | 2.0s |  |
| 69 | `string_paths_timer` | 1 | 2.1s |  |
| 70 | `swf4_actions_bool` | 96 | 2.2s |  |
| 71 | `swf4_bool` | 4 | 2.1s |  |
| 72 | `swf5_encoding` | 3 | 3.5s |  |
| 73 | `this_swf7` | 41 | 2.2s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 74 | `timeline_function_def` | 7 | 2.2s |  |
| 75 | `try_finally_simple` | 16 | 2.1s |  |
| 76 | `typeof_globals` | 7 | 2.1s |  |
| 77 | `undefined_to_string_swf6` | 4 | 2.0s |  |
| 78 | `with_return` | 2 | 2.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**105 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `string_coercion` | 99.1% | 116 | 117 | 1 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 2 | `object_string_coerce_swf5` | 95.4% | 62 | 65 | 3 |  |
| 3 | `object_function` | 90.6% | 29 | 32 | 3 |  |
| 4 | `has_own_property` | 87.5% | 28 | 32 | 4 |  |
| 5 | `set_variable_scope` | 86.2% | 50 | 58 | 8 |  |
| 6 | `as1_constructor_v7` | 85.7% | 30 | 35 | 5 |  |
| 7 | `swf7_case_sensitive` | 84.1% | 37 | 44 | 7 |  |
| 8 | `array_properties` | 83.3% | 30 | 36 | 6 |  |
| 9 | `getproperty_swf4` | 82.1% | 23 | 28 | 5 |  |
| 10 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 11 | `movieclip_prototype_extension` | 80.0% | 4 | 5 | 1 |  |
| 12 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 13 | `as1_constructor_v6` | 77.1% | 27 | 35 | 8 |  |
| 14 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 15 | `stage_object_children` | 75.9% | 63 | 83 | 20 |  |
| 16 | `define_function2` | 75.0% | 6 | 8 | 2 |  |
| 17 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 18 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 19 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 20 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 21 | `object_constructor` | 72.7% | 24 | 33 | 9 |  |
| 22 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 23 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 24 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 25 | `point` | 70.9% | 124 | 175 | 51 |  |
| 26 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 27 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 28 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 29 | `get_variable_in_scope` | 69.0% | 20 | 29 | 9 |  |
| 30 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 31 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 32 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 33 | `primitive_instanceof` | 67.6% | 25 | 37 | 12 |  |
| 34 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 35 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 36 | `delete` | 66.7% | 2 | 3 | 1 |  |
| 37 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 38 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 39 | `goto_both_ways2` | 66.7% | 2 | 3 | 1 |  |
| 40 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 41 | `goto_rewind2` | 66.7% | 2 | 3 | 1 |  |
| 42 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 43 | `o` | 66.7% | 2 | 3 | 1 |  |
| 44 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 45 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 46 | `error` | 65.5% | 38 | 58 | 20 |  |
| 47 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 48 | `getproperty` | 64.3% | 18 | 28 | 10 |  |
| 49 | `getproperty_swf5` | 64.3% | 18 | 28 | 10 |  |
| 50 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 51 | `globals_swf6` | 64.1% | 195 | 304 | 109 |  |
| 52 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 53 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 54 | `with` | 63.3% | 31 | 49 | 18 |  |
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
| 72 | `with_variable_scopes` | 58.1% | 25 | 43 | 18 |  |
| 73 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 74 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 75 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 76 | `primitive_type_globals` | 57.3% | 319 | 557 | 238 |  |
| 77 | `escape` | 57.1% | 8 | 14 | 6 |  |
| 78 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 79 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 80 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 81 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 82 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 83 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 84 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 85 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 86 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 87 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 88 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 89 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 90 | `movieclip_focusenabled` | 52.5% | 52 | 99 | 47 |  |
| 91 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 92 | `as_set_prop_flags_version` | 51.6% | 16 | 31 | 15 |  |
| 93 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 94 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 95 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 96 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 97 | `goto_advance2` | 50.0% | 1 | 2 | 1 |  |
| 98 | `goto_rewind3` | 50.0% | 1 | 2 | 1 |  |
| 99 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 100 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 101 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 102 | `prototype_delete` | 50.0% | 6 | 12 | 6 |  |
| 103 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 104 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 105 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**9 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `array_constructor` | 4.4s |  |
| 2 | `as2_oop` | 4.3s |  |
| 3 | `device_font_spacing` | 11.6s |  |
| 4 | `duplicate_movie_clip_drawing` | 4.2s |  |
| 5 | `enumerate` | 4.3s |  |
| 6 | `extends_chain` | 5.0s |  |
| 7 | `issue_2166` | 4.2s |  |
| 8 | `path_string` | 4.6s |  |
| 9 | `swf4_actions_coercion_order` | 4.3s |  |

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `array_length` | exit code -6 | 4.4s |  |
| 2 | `uncaught_exception` | exit code 1 | 2.0s |  |
| 3 | `uncaught_exception_bubbled` | exit code 1 | 2.1s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.2s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.2s |  |
| 3 | `timeout` | runtime timeout (>10s) | 13.3s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.6s |  |

## All Output Mismatches

**397 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `string_coercion` | 99.1% | 116/117 | 117 | 117 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 2 | `object_string_coerce_swf5` | 95.4% | 62/65 | 65 | 62 |  |
| 3 | `object_function` | 90.6% | 29/32 | 32 | 32 |  |
| 4 | `has_own_property` | 87.5% | 28/32 | 32 | 32 |  |
| 5 | `set_variable_scope` | 86.2% | 50/58 | 58 | 58 |  |
| 6 | `as1_constructor_v7` | 85.7% | 30/35 | 35 | 35 |  |
| 7 | `swf7_case_sensitive` | 84.1% | 37/44 | 44 | 44 |  |
| 8 | `array_properties` | 83.3% | 30/36 | 36 | 36 |  |
| 9 | `getproperty_swf4` | 82.1% | 23/28 | 28 | 28 |  |
| 10 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 11 | `movieclip_prototype_extension` | 80.0% | 4/5 | 5 | 5 |  |
| 12 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 13 | `as1_constructor_v6` | 77.1% | 27/35 | 35 | 35 |  |
| 14 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 15 | `stage_object_children` | 75.9% | 63/83 | 83 | 83 |  |
| 16 | `define_function2` | 75.0% | 6/8 | 8 | 8 |  |
| 17 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 18 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 19 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 20 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 21 | `object_constructor` | 72.7% | 24/33 | 33 | 33 |  |
| 22 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 23 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 24 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 25 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 26 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 27 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 28 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 29 | `get_variable_in_scope` | 69.0% | 20/29 | 29 | 29 |  |
| 30 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 31 | `object_string_coerce_swf6` | 67.6% | 46/68 | 65 | 68 |  |
| 32 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 33 | `primitive_instanceof` | 67.6% | 25/37 | 37 | 37 |  |
| 34 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 35 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 36 | `delete` | 66.7% | 2/3 | 3 | 3 |  |
| 37 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 38 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 39 | `goto_both_ways2` | 66.7% | 2/3 | 2 | 3 |  |
| 40 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 41 | `goto_rewind2` | 66.7% | 2/3 | 2 | 3 |  |
| 42 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 43 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 44 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 45 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 46 | `error` | 65.5% | 38/58 | 58 | 58 |  |
| 47 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 48 | `getproperty` | 64.3% | 18/28 | 28 | 28 |  |
| 49 | `getproperty_swf5` | 64.3% | 18/28 | 28 | 28 |  |
| 50 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 51 | `globals_swf6` | 64.1% | 195/304 | 304 | 304 |  |
| 52 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 53 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 54 | `with` | 63.3% | 31/49 | 47 | 49 |  |
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
| 72 | `with_variable_scopes` | 58.1% | 25/43 | 43 | 43 |  |
| 73 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 74 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 75 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 76 | `primitive_type_globals` | 57.3% | 319/557 | 555 | 557 |  |
| 77 | `escape` | 57.1% | 8/14 | 14 | 14 |  |
| 78 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 79 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 80 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 81 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 82 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 83 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 84 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 85 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 86 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 87 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 88 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 89 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 90 | `movieclip_focusenabled` | 52.5% | 52/99 | 99 | 99 |  |
| 91 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 336 |  |
| 92 | `as_set_prop_flags_version` | 51.6% | 16/31 | 29 | 31 |  |
| 93 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 94 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 95 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 96 | `execution_order3` | 50.0% | 2/4 | 3 | 4 |  |
| 97 | `goto_advance2` | 50.0% | 1/2 | 1 | 2 |  |
| 98 | `goto_rewind3` | 50.0% | 1/2 | 1 | 2 |  |
| 99 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 100 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 101 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 102 | `prototype_delete` | 50.0% | 6/12 | 12 | 12 |  |
| 103 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 104 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 105 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 106 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 107 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 108 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 109 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 110 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 111 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 112 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 113 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 114 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 115 | `new_object_enumerate` | 42.9% | 3/7 | 7 | 7 |  |
| 116 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 117 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 118 | `globals_swf8` | 38.8% | 118/304 | 304 | 304 |  |
| 119 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 120 | `as_broadcaster_undef` | 38.2% | 34/89 | 81 | 89 |  |
| 121 | `localconnection_properties` | 37.5% | 3/8 | 8 | 8 |  |
| 122 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 123 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 124 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 125 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 126 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 127 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 128 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 129 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 130 | `goto_both_ways1` | 33.3% | 1/3 | 1 | 3 |  |
| 131 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 132 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 133 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 134 | `define_function2_preload` | 30.8% | 4/13 | 12 | 13 |  |
| 135 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 136 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 137 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 138 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 139 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 140 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 141 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 142 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 143 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 144 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 145 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 146 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 147 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 148 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 149 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 150 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 151 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 152 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 153 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 154 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 155 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 156 | `unescape` | 20.9% | 9/43 | 42 | 43 |  |
| 157 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 158 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 159 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 160 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 161 | `global_array` | 20.0% | 1/5 | 5 | 4 |  |
| 162 | `xml_attributes_read` | 20.0% | 1/5 | 3 | 5 |  |
| 163 | `frame_size_translated_negative` | 19.0% | 4/21 | 20 | 21 |  |
| 164 | `frame_size_translated_positive` | 19.0% | 4/21 | 20 | 21 |  |
| 165 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 166 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 167 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 168 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 169 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 170 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 171 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 172 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 173 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 174 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 175 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 176 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 177 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 178 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 179 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 180 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 181 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 182 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 183 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 184 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 185 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 186 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 187 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 188 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 189 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 190 | `string_paths_other` | 11.1% | 4/36 | 28 | 36 |  |
| 191 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 192 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 193 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 194 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 195 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 196 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 197 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 198 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 199 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 200 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 201 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 202 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 203 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 204 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 205 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 206 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 207 | `array_enumerate` | 6.2% | 1/16 | 16 | 4 |  |
| 208 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 209 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 210 | `funky_function_calls` | 5.4% | 3/56 | 12 | 56 |  |
| 211 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 212 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 213 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 214 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 215 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 216 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 217 | `register_class` | 4.5% | 3/66 | 27 | 66 |  |
| 218 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 219 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 220 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 221 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 222 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 223 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 224 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 225 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 226 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 227 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 228 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 229 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 230 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 231 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 232 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 233 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 234 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 235 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 236 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 237 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 238 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 239 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 240 | `localconnection` | 0.2% | 1/580 | 1 | 580 |  |
| 241 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 242 | `array_sort_random` | 0.0% | 0/443 | 1 | 443 |  |
| 243 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 244 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 245 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 1 | 40 |  |
| 246 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 247 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 248 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 249 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 250 | `asfunction` | 0.0% | 0/11 | 1 | 11 |  |
| 251 | `asnew` | 0.0% | 0/34 | 1 | 34 |  |
| 252 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 1 | 2 |  |
| 253 | `boxed_primitives` | 0.0% | 0/24 | 1 | 24 |  |
| 254 | `button_children` | 0.0% | 0/8 | 1 | 8 |  |
| 255 | `button_goto` | 0.0% | 0/4 | 1 | 4 |  |
| 256 | `button_order` | 0.0% | 0/2 | 1 | 2 |  |
| 257 | `button_properties_special_cases` | 0.0% | 0/22 | 1 | 22 |  |
| 258 | `button_v5` | 0.0% | 0/18 | 1 | 18 |  |
| 259 | `button_v6` | 0.0% | 0/18 | 1 | 18 |  |
| 260 | `call` | 0.0% | 0/63 | 1 | 63 |  |
| 261 | `call_method_empty_name` | 0.0% | 0/1 | 1 | 1 |  |
| 262 | `clip_constructors` | 0.0% | 0/8 | 1 | 8 |  |
| 263 | `clip_event_propagation_order` | 0.0% | 0/17 | 1 | 17 |  |
| 264 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 265 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 266 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 267 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 1 | 129 |  |
| 268 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 1 | 17 |  |
| 269 | `color` | 0.0% | 0/57 | 1 | 57 |  |
| 270 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 271 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 272 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 273 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 274 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 275 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 276 | `duplicate_movie_clip` | 0.0% | 0/20 | 1 | 20 |  |
| 277 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 278 | `edittext_html_roundtrip` | 0.0% | 0/17 | 1 | 17 |  |
| 279 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 280 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 281 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 282 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 283 | `extends_native_type` | 0.0% | 0/11 | 1 | 11 |  |
| 284 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 285 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 286 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 287 | `file_reference_browse_cancel` | 0.0% | 0/21 | 1 | 21 |  |
| 288 | `function_base_clip` | 0.0% | 0/8 | 1 | 8 |  |
| 289 | `function_base_clip_readded` | 0.0% | 0/11 | 1 | 11 |  |
| 290 | `function_suppress_and_preload` | 0.0% | 0/28 | 1 | 28 |  |
| 291 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 292 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 293 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 294 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 295 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 296 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 1 | 1145 |  |
| 297 | `global_swf6_7_8` | 0.0% | 0/15 | 1 | 15 |  |
| 298 | `goto_execution_order2` | 0.0% | 0/2 | 1 | 2 |  |
| 299 | `goto_frame` | 0.0% | 0/12 | 1 | 12 |  |
| 300 | `goto_frame2` | 0.0% | 0/44 | 1 | 44 |  |
| 301 | `goto_label` | 0.0% | 0/17 | 1 | 17 |  |
| 302 | `goto_methods` | 0.0% | 0/40 | 1 | 40 |  |
| 303 | `hittest_lockroot` | 0.0% | 0/15 | 1 | 15 |  |
| 304 | `hittest_morph` | 0.0% | 0/70 | 1 | 70 |  |
| 305 | `hittest_morph_input` | 0.0% | 0/1 | 1 | 1 |  |
| 306 | `hittest_winding_rule` | 0.0% | 0/12 | 1 | 12 |  |
| 307 | `init_array_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 308 | `init_object_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 309 | `init_object_order` | 0.0% | 0/15 | 1 | 15 |  |
| 310 | `input_dead_keys_windows` | 0.0% | 0/15 | 1 | 15 |  |
| 311 | `instanceof_coercions` | 0.0% | 0/88 | 1 | 88 |  |
| 312 | `interface_implements_op` | 0.0% | 0/47 | 1 | 47 |  |
| 313 | `issue_1104` | 0.0% | 0/2 | 1 | 2 |  |
| 314 | `issue_2084` | 0.0% | 0/16 | 1 | 16 |  |
| 315 | `issue_2870` | 0.0% | 0/3 | 1 | 3 |  |
| 316 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 317 | `issue_9327` | 0.0% | 0/2 | 1 | 2 |  |
| 318 | `issue_9885` | 0.0% | 0/2 | 1 | 2 |  |
| 319 | `lock_root` | 0.0% | 0/1 | 1 | 1 |  |
| 320 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 1 | 35 |  |
| 321 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 322 | `movieclip_gettextsnapshot` | 0.0% | 0/112 | 21 | 112 |  |
| 323 | `movieclip_in_removed_button` | 0.0% | 0/4 | 1 | 4 |  |
| 324 | `movieclip_init_object` | 0.0% | 0/5 | 1 | 5 |  |
| 325 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 326 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 1 | 4 |  |
| 327 | `named_shapes` | 0.0% | 0/14 | 1 | 14 |  |
| 328 | `native_double_construct` | 0.0% | 0/12 | 1 | 12 |  |
| 329 | `native_objects_swf6` | 0.0% | 0/84 | 1 | 84 |  |
| 330 | `native_objects_swf7` | 0.0% | 0/84 | 1 | 84 |  |
| 331 | `native_objects_swf8` | 0.0% | 0/84 | 1 | 84 |  |
| 332 | `native_subclasses` | 0.0% | 0/191 | 1 | 191 |  |
| 333 | `netconnection_send_remote` | 0.0% | 0/50 | 1 | 50 |  |
| 334 | `new_method_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 335 | `new_object_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 336 | `object_properties` | 0.0% | 0/31 | 1 | 31 |  |
| 337 | `object_resolve` | 0.0% | 0/38 | 1 | 38 |  |
| 338 | `on_construct` | 0.0% | 0/25 | 1 | 25 |  |
| 339 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 340 | `place_and_lookup` | 0.0% | 0/30 | 1 | 30 |  |
| 341 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 342 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 1 |  |
| 343 | `register_class_return_value` | 0.0% | 0/16 | 1 | 16 |  |
| 344 | `register_class_swf6` | 0.0% | 0/37 | 1 | 37 |  |
| 345 | `register_class_with_sound` | 0.0% | 0/11 | 1 | 11 |  |
| 346 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 347 | `removed_target_clip_scope` | 0.0% | 0/35 | 1 | 35 |  |
| 348 | `resolve_different_root` | 0.0% | 0/2 | 1 | 2 |  |
| 349 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 350 | `root_onload` | 0.0% | 0/1 | 1 | 1 |  |
| 351 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 352 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 353 | `selection` | 0.0% | 0/454 | 1 | 454 |  |
| 354 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 355 | `slash_syntax` | 0.0% | 0/14 | 1 | 14 |  |
| 356 | `stage_object_enumerate` | 0.0% | 0/4 | 1 | 4 |  |
| 357 | `string_methods_negative_args` | 0.0% | 0/240 | 1 | 240 |  |
| 358 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 359 | `string_paths_eval` | 0.0% | 0/4 | 1 | 4 |  |
| 360 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 361 | `string_paths_unload` | 0.0% | 0/1 | 1 | 1 |  |
| 362 | `string_paths_variable_scopes` | 0.0% | 0/5 | 1 | 5 |  |
| 363 | `stylesheet` | 0.0% | 0/283 | 1 | 283 |  |
| 364 | `super_edge_cases` | 0.0% | 0/39 | 1 | 39 |  |
| 365 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 366 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 367 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 368 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 369 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 370 | `target_clip_swf5` | 0.0% | 0/2 | 1 | 2 |  |
| 371 | `target_clip_swf6` | 0.0% | 0/2 | 1 | 2 |  |
| 372 | `target_path` | 0.0% | 0/14 | 1 | 14 |  |
| 373 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 374 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 375 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 376 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 |  |
| 377 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 378 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 379 | `timer_run_actions` | 0.0% | 0/18 | 1 | 18 |  |
| 380 | `typeof` | 0.0% | 0/22 | 1 | 22 |  |
| 381 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 382 | `unload_clip_event` | 0.0% | 0/4 | 1 | 4 |  |
| 383 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 384 | `use_hand_cursor` | 0.0% | 0/8 | 1 | 8 |  |
| 385 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 386 | `watch` | 0.0% | 0/117 | 1 | 117 |  |
| 387 | `watch_textfield` | 0.0% | 0/12 | 1 | 12 |  |
| 388 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 |  |
| 389 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 390 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 391 | `xml_ignore_comments` | 0.0% | 0/21 | 1 | 21 |  |
| 392 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 393 | `xml_reparenting` | 0.0% | 0/14 | 1 | 14 |  |
| 394 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 395 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 396 | `xml_unescaping` | 0.0% | 0/23 | 1 | 23 |  |
| 397 | `xmlnode_proto` | 0.0% | 0/1 | 1 | 1 |  |
