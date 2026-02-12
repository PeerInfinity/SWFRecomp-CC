# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-12 03:55 UTC

**Git SHA**: `dee8f35ae4`

**Run Duration**: 27m 27s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 616 |
| Passing | **81** (13.1%) |
| Failing | 535 |
| Total expected lines | 88845 |
| Matching lines | 32130 (36.2%) |
| Mismatched lines | 56715 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 518 | 96.8% |
| Runtime Segfault | 10 | 1.9% |
| Timeout | 4 | 0.7% |
| Runtime Error | 3 | 0.6% |

## Passing Tests

**81 tests passing**

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
| 35 | `focusrect_mouse_swf8` | 1 | 2.1s |  |
| 36 | `focusrect_mouse_swf9` | 1 | 2.1s |  |
| 37 | `global_is_bare` | 7 | 2.2s |  |
| 38 | `goto_execution_order` | 2 | 2.0s |  |
| 39 | `goto_rewind1` | 1 | 2.1s |  |
| 40 | `greater_swf6` | 1175 | 11.3s |  |
| 41 | `greater_swf7` | 1175 | 11.2s |  |
| 42 | `greaterthan_swf5` | 1 | 2.1s |  |
| 43 | `greaterthan_swf8` | 1 | 2.1s |  |
| 44 | `infinite_recursion_function` | 4 | 2.1s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 45 | `infinite_recursion_function_in_setter` | 131 | 2.1s |  |
| 46 | `infinite_recursion_virtual_property` | 67 | 2.1s |  |
| 47 | `issue_1086` | 1 | 2.1s |  |
| 48 | `issue_1671` | 1 | 2.1s |  |
| 49 | `issue_3446` | 1 | 2.1s |  |
| 50 | `issue_4377` | 2 | 2.1s |  |
| 51 | `issue_768` | 3 | 2.1s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 52 | `lessthan` | 41 | 2.2s |  |
| 53 | `lessthan2_swf5` | 1226 | 11.7s |  |
| 54 | `lessthan2_swf6` | 1226 | 11.8s |  |
| 55 | `lessthan2_swf7` | 1226 | 11.8s |  |
| 56 | `lessthan_swf4` | 902 | 7.5s |  |
| 57 | `lessthan_swf4_alt` | 41 | 2.1s |  |
| 58 | `lessthan_swf5` | 41 | 2.2s |  |
| 59 | `logical_ops_swf4` | 90 | 2.1s |  |
| 60 | `logical_ops_swf8` | 108 | 2.2s |  |
| 61 | `looping` | 6 | 2.0s |  |
| 62 | `mask_reapply` | 1 | 2.0s |  |
| 63 | `mask_with_drawing` | 1 | 2.1s |  |
| 64 | `movieclip_begin_gradient_fill` | 1 | 2.8s |  |
| 65 | `movieclip_line_gradient_style` | 1 | 2.8s |  |
| 66 | `nested_textfields_in_buttons` | 1 | 2.1s |  |
| 67 | `sandbox_type_local_file` | 1 | 2.1s |  |
| 68 | `single_frame` | 1 | 2.1s |  |
| 69 | `sound_start_load` | 1 | 2.2s |  |
| 70 | `strictequals_swf6` | 902 | 8.7s |  |
| 71 | `strictly_equals` | 7 | 2.1s |  |
| 72 | `string_paths_keyevents` | 1 | 2.1s |  |
| 73 | `string_paths_timer` | 1 | 2.1s |  |
| 74 | `swf4_actions_bool` | 96 | 2.2s |  |
| 75 | `swf4_bool` | 4 | 2.1s |  |
| 76 | `swf5_encoding` | 3 | 4.0s |  |
| 77 | `timeline_function_def` | 7 | 2.1s |  |
| 78 | `try_finally_simple` | 16 | 2.0s |  |
| 79 | `typeof_globals` | 7 | 2.0s |  |
| 80 | `undefined_to_string_swf6` | 4 | 2.0s |  |
| 81 | `with_return` | 2 | 2.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**113 tests** within reach

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
| 14 | `bitmap_data_max_size_swf10` | 75.0% | 9 | 12 | 3 |  |
| 15 | `define_function2` | 75.0% | 6 | 8 | 2 |  |
| 16 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 17 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 18 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 19 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 20 | `object_constructor` | 72.7% | 24 | 33 | 9 |  |
| 21 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 22 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 23 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 24 | `point` | 70.9% | 124 | 175 | 51 |  |
| 25 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 26 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 27 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 28 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 29 | `string_coercion` | 69.2% | 81 | 117 | 36 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 30 | `get_variable_in_scope` | 69.0% | 20 | 29 | 9 |  |
| 31 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
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
| 49 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 50 | `error` | 65.5% | 38 | 58 | 20 |  |
| 51 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 52 | `getproperty` | 64.3% | 18 | 28 | 10 |  |
| 53 | `getproperty_swf5` | 64.3% | 18 | 28 | 10 |  |
| 54 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 55 | `globals_swf6` | 64.1% | 195 | 304 | 109 |  |
| 56 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 57 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 58 | `globals_swf7` | 63.2% | 192 | 304 | 112 |  |
| 59 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 60 | `globals_swf5` | 61.8% | 188 | 304 | 116 |  |
| 61 | `arguments` | 61.4% | 78 | 127 | 49 |  |
| 62 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 63 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 64 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 65 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 66 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 67 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 68 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 69 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 70 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 71 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 72 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 73 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 74 | `swf6_case_insensitive` | 59.1% | 26 | 44 | 18 |  |
| 75 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 76 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 77 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 78 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 79 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 80 | `primitive_type_globals` | 57.3% | 319 | 557 | 238 |  |
| 81 | `escape` | 57.1% | 8 | 14 | 6 |  |
| 82 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 83 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 84 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
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
| 95 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 96 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 97 | `as_set_prop_flags_version` | 51.6% | 16 | 31 | 15 |  |
| 98 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 99 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 100 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 101 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 102 | `goto_advance2` | 50.0% | 1 | 2 | 1 |  |
| 103 | `goto_rewind3` | 50.0% | 1 | 2 | 1 |  |
| 104 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 105 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 106 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 107 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 108 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 109 | `prototype_delete` | 50.0% | 6 | 12 | 6 |  |
| 110 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 111 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 112 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 113 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**10 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `array_constructor` | 4.2s |  |
| 2 | `as2_oop` | 4.3s |  |
| 3 | `device_font_spacing` | 10.2s |  |
| 4 | `duplicate_movie_clip_drawing` | 4.1s |  |
| 5 | `enumerate` | 4.0s |  |
| 6 | `extends_chain` | 4.6s |  |
| 7 | `issue_2166` | 4.1s |  |
| 8 | `netstream_play_flv_screen` | 31.1s |  |
| 9 | `path_string` | 4.7s |  |
| 10 | `swf4_actions_coercion_order` | 4.5s |  |

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

**518 tests** with output mismatch, sorted by match rate (best first)

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
| 14 | `bitmap_data_max_size_swf10` | 75.0% | 9/12 | 12 | 12 |  |
| 15 | `define_function2` | 75.0% | 6/8 | 8 | 8 |  |
| 16 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 17 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 18 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 19 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 20 | `object_constructor` | 72.7% | 24/33 | 33 | 33 |  |
| 21 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 22 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 23 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 24 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 25 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 26 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 27 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 28 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 29 | `string_coercion` | 69.2% | 81/117 | 108 | 117 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 30 | `get_variable_in_scope` | 69.0% | 20/29 | 29 | 29 |  |
| 31 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
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
| 49 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 50 | `error` | 65.5% | 38/58 | 58 | 58 |  |
| 51 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 52 | `getproperty` | 64.3% | 18/28 | 28 | 28 |  |
| 53 | `getproperty_swf5` | 64.3% | 18/28 | 28 | 28 |  |
| 54 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 55 | `globals_swf6` | 64.1% | 195/304 | 304 | 304 |  |
| 56 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 57 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 58 | `globals_swf7` | 63.2% | 192/304 | 304 | 304 |  |
| 59 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 60 | `globals_swf5` | 61.8% | 188/304 | 304 | 304 |  |
| 61 | `arguments` | 61.4% | 78/127 | 92 | 127 |  |
| 62 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 63 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 64 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 65 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 66 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 67 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 68 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 69 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 70 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 71 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 72 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 73 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 74 | `swf6_case_insensitive` | 59.1% | 26/44 | 44 | 42 |  |
| 75 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 76 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 77 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 78 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 79 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 80 | `primitive_type_globals` | 57.3% | 319/557 | 555 | 557 |  |
| 81 | `escape` | 57.1% | 8/14 | 14 | 14 |  |
| 82 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 83 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 84 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
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
| 95 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 96 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 336 |  |
| 97 | `as_set_prop_flags_version` | 51.6% | 16/31 | 29 | 31 |  |
| 98 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 99 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 100 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 101 | `execution_order3` | 50.0% | 2/4 | 3 | 4 |  |
| 102 | `goto_advance2` | 50.0% | 1/2 | 1 | 2 |  |
| 103 | `goto_rewind3` | 50.0% | 1/2 | 1 | 2 |  |
| 104 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 105 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 106 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 107 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 108 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 109 | `prototype_delete` | 50.0% | 6/12 | 12 | 12 |  |
| 110 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 111 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 112 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 113 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 114 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 115 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 116 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 117 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 118 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 119 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 120 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 121 | `new_object_enumerate` | 42.9% | 3/7 | 7 | 7 |  |
| 122 | `sound_props_swf6` | 41.2% | 28/68 | 68 | 68 |  |
| 123 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 124 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 125 | `sound_props_swf5` | 39.7% | 27/68 | 67 | 68 |  |
| 126 | `globals_swf8` | 38.8% | 118/304 | 304 | 304 |  |
| 127 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 128 | `as_broadcaster_undef` | 38.2% | 34/89 | 81 | 89 |  |
| 129 | `localconnection_properties` | 37.5% | 3/8 | 8 | 8 |  |
| 130 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 131 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 132 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 133 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 134 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 135 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 136 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 137 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 138 | `goto_both_ways1` | 33.3% | 1/3 | 1 | 3 |  |
| 139 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 140 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 141 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 142 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 143 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 144 | `define_function2_preload` | 30.8% | 4/13 | 12 | 13 |  |
| 145 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 146 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 147 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 148 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 149 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 150 | `define_local_with_paths` | 27.8% | 15/54 | 44 | 54 |  |
| 151 | `this_swf5` | 27.3% | 15/55 | 55 | 41 |  |
| 152 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 153 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 154 | `this_swf6` | 25.5% | 14/55 | 55 | 41 |  |
| 155 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 156 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 157 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 158 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 159 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 160 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 161 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 162 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 163 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 164 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 165 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 166 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 167 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 168 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 169 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 170 | `unescape` | 20.9% | 9/43 | 42 | 43 |  |
| 171 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 172 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 173 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 174 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 175 | `global_array` | 20.0% | 1/5 | 5 | 4 |  |
| 176 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 177 | `xml_attributes_read` | 20.0% | 1/5 | 3 | 5 |  |
| 178 | `frame_size_translated_negative` | 19.0% | 4/21 | 20 | 21 |  |
| 179 | `frame_size_translated_positive` | 19.0% | 4/21 | 20 | 21 |  |
| 180 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 181 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 182 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 183 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 184 | `focusrect_swf5` | 16.7% | 1/6 | 1 | 6 |  |
| 185 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 186 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 187 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 188 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 189 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 190 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 191 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 192 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 193 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 194 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 195 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 196 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 197 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 198 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 199 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 200 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 201 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 202 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 203 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 204 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 205 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 206 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 207 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 208 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 209 | `string_paths_other` | 11.1% | 4/36 | 28 | 36 |  |
| 210 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 211 | `with` | 10.3% | 7/68 | 68 | 49 |  |
| 212 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 213 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 214 | `this_scoping` | 9.6% | 5/52 | 50 | 52 |  |
| 215 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 216 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 217 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 218 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 219 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 220 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 221 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 222 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 223 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 224 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 225 | `funky_function_calls` | 7.1% | 4/56 | 12 | 56 |  |
| 226 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 227 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 228 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 229 | `array_enumerate` | 6.2% | 1/16 | 16 | 4 |  |
| 230 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 231 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 232 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 233 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 234 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 235 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 236 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 237 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 238 | `register_class` | 4.5% | 3/66 | 27 | 66 |  |
| 239 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 240 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 241 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 242 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 243 | `bitmap_data` | 4.1% | 46/1126 | 318 | 1126 |  |
| 244 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 245 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 246 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 247 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 248 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 249 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 250 | `tab_ordering_properties` | 2.7% | 8/293 | 180 | 293 |  |
| 251 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 252 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 253 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 254 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 255 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 256 | `with_variable_scopes` | 1.5% | 1/68 | 68 | 43 |  |
| 257 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 258 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 259 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 260 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 261 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 262 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 263 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 264 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 265 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 266 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 267 | `tab_ordering_events` | 0.7% | 1/150 | 12 | 150 |  |
| 268 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 269 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 270 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 271 | `focusrect_property_swf5` | 0.3% | 4/1241 | 1241 | 1237 |  |
| 272 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 273 | `localconnection` | 0.2% | 1/580 | 1 | 580 |  |
| 274 | `focusrect_property_swf6` | 0.2% | 2/1241 | 1241 | 1237 |  |
| 275 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 276 | `focusrect_property_swf7` | 0.1% | 1/1241 | 1241 | 1237 |  |
| 277 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 278 | `array_sort_random` | 0.0% | 0/443 | 1 | 443 |  |
| 279 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 280 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 281 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 1 | 40 |  |
| 282 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 283 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 284 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 285 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 286 | `asfunction` | 0.0% | 0/11 | 1 | 11 |  |
| 287 | `asnew` | 0.0% | 0/34 | 1 | 34 |  |
| 288 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 1 | 2 |  |
| 289 | `bitmap_data_copypixels` | 0.0% | 0/17 | 1 | 17 |  |
| 290 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 1 | 1075 |  |
| 291 | `bitmap_filters` | 0.0% | 0/548 | 1 | 548 |  |
| 292 | `boxed_primitives` | 0.0% | 0/24 | 1 | 24 |  |
| 293 | `button_children` | 0.0% | 0/8 | 1 | 8 |  |
| 294 | `button_goto` | 0.0% | 0/4 | 1 | 4 |  |
| 295 | `button_key_events` | 0.0% | 0/14 | 1 | 14 |  |
| 296 | `button_key_events_special` | 0.0% | 0/45 | 1 | 45 |  |
| 297 | `button_keypress` | 0.0% | 0/3 | 1 | 3 |  |
| 298 | `button_keypress_vs_press` | 0.0% | 0/25 | 1 | 25 |  |
| 299 | `button_keypress_vs_tab` | 0.0% | 0/20 | 1 | 20 |  |
| 300 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 1 | 4 |  |
| 301 | `button_order` | 0.0% | 0/2 | 1 | 2 |  |
| 302 | `button_properties_special_cases` | 0.0% | 0/22 | 1 | 22 |  |
| 303 | `button_v5` | 0.0% | 0/18 | 1 | 18 |  |
| 304 | `button_v6` | 0.0% | 0/18 | 1 | 18 |  |
| 305 | `call` | 0.0% | 0/63 | 1 | 63 |  |
| 306 | `call_method_empty_name` | 0.0% | 0/1 | 1 | 1 |  |
| 307 | `click_block` | 0.0% | 0/5 | 1 | 5 |  |
| 308 | `clip_constructors` | 0.0% | 0/8 | 1 | 8 |  |
| 309 | `clip_event_propagation_order` | 0.0% | 0/17 | 1 | 17 |  |
| 310 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 311 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 312 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 313 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 1 | 129 |  |
| 314 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 1 | 17 |  |
| 315 | `color` | 0.0% | 0/57 | 1 | 57 |  |
| 316 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 317 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 318 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 319 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 320 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 321 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 322 | `drag_drop` | 0.0% | 0/10 | 1 | 10 |  |
| 323 | `drag_over_from_outside` | 0.0% | 0/1 | 1 | 1 |  |
| 324 | `drag_over_without_startdrag` | 0.0% | 0/1 | 1 | 1 |  |
| 325 | `duplicate_movie_clip` | 0.0% | 0/20 | 1 | 20 |  |
| 326 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 327 | `edittext_drag_select` | 0.0% | 0/9 | 1 | 9 |  |
| 328 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 329 | `edittext_html_roundtrip` | 0.0% | 0/17 | 1 | 17 |  |
| 330 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 1 | 7 |  |
| 331 | `edittext_input` | 0.0% | 0/1 | 1 | 1 |  |
| 332 | `edittext_input_newlines` | 0.0% | 0/9 | 1 | 9 |  |
| 333 | `edittext_password` | 0.0% | 0/5 | 1 | 5 |  |
| 334 | `edittext_password_copy` | 0.0% | 0/4 | 1 | 4 |  |
| 335 | `edittext_paste_empty` | 0.0% | 0/2 | 1 | 2 |  |
| 336 | `edittext_place_caret` | 0.0% | 0/2 | 1 | 2 |  |
| 337 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 338 | `edittext_restrict` | 0.0% | 0/191 | 1 | 191 |  |
| 339 | `edittext_restrict_paste` | 0.0% | 0/5 | 1 | 5 |  |
| 340 | `edittext_tab_focus` | 0.0% | 0/13 | 1 | 13 |  |
| 341 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 342 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 343 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 344 | `extends_native_type` | 0.0% | 0/11 | 1 | 11 |  |
| 345 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 346 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 347 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 348 | `file_reference_browse_cancel` | 0.0% | 0/21 | 1 | 21 |  |
| 349 | `focus_keyboard_press` | 0.0% | 0/60 | 1 | 60 |  |
| 350 | `focus_mouse` | 0.0% | 0/45 | 1 | 45 |  |
| 351 | `focus_mouse_focusable` | 0.0% | 0/8 | 1 | 8 |  |
| 352 | `focus_mouse_rollout` | 0.0% | 0/4 | 1 | 4 |  |
| 353 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 354 | `focusrect_focuslost` | 0.0% | 0/4 | 1 | 4 |  |
| 355 | `focusrect_swf6` | 0.0% | 0/42 | 1 | 42 |  |
| 356 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 357 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 358 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 359 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 360 | `function_base_clip` | 0.0% | 0/8 | 1 | 8 |  |
| 361 | `function_base_clip_readded` | 0.0% | 0/11 | 1 | 11 |  |
| 362 | `function_suppress_and_preload` | 0.0% | 0/28 | 1 | 28 |  |
| 363 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 364 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 365 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 366 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 367 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 368 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 1 | 1145 |  |
| 369 | `global_swf6_7_8` | 0.0% | 0/15 | 1 | 15 |  |
| 370 | `goto_execution_order2` | 0.0% | 0/2 | 1 | 2 |  |
| 371 | `goto_frame` | 0.0% | 0/12 | 1 | 12 |  |
| 372 | `goto_frame2` | 0.0% | 0/44 | 1 | 44 |  |
| 373 | `goto_label` | 0.0% | 0/17 | 1 | 17 |  |
| 374 | `goto_methods` | 0.0% | 0/40 | 1 | 40 |  |
| 375 | `hittest_lockroot` | 0.0% | 0/15 | 1 | 15 |  |
| 376 | `hittest_morph` | 0.0% | 0/70 | 1 | 70 |  |
| 377 | `hittest_morph_input` | 0.0% | 0/1 | 1 | 1 |  |
| 378 | `hittest_winding_rule` | 0.0% | 0/12 | 1 | 12 |  |
| 379 | `init_array_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 380 | `init_object_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 381 | `init_object_order` | 0.0% | 0/15 | 1 | 15 |  |
| 382 | `input_dead_keys_windows` | 0.0% | 0/15 | 1 | 15 |  |
| 383 | `instanceof_coercions` | 0.0% | 0/88 | 1 | 88 |  |
| 384 | `interface_implements_op` | 0.0% | 0/47 | 1 | 47 |  |
| 385 | `issue_1104` | 0.0% | 0/2 | 1 | 2 |  |
| 386 | `issue_2084` | 0.0% | 0/16 | 1 | 16 |  |
| 387 | `issue_2870` | 0.0% | 0/3 | 1 | 3 |  |
| 388 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 389 | `issue_9327` | 0.0% | 0/2 | 1 | 2 |  |
| 390 | `issue_9885` | 0.0% | 0/2 | 1 | 2 |  |
| 391 | `key_isToggled` | 0.0% | 0/9 | 1 | 9 |  |
| 392 | `loadmovie_fail` | 0.0% | 0/2 | 1 | 2 |  |
| 393 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 394 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 395 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 1 | 9 |  |
| 396 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 397 | `loadvariables_method` | 0.0% | 0/7 | 1 | 7 |  |
| 398 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 399 | `lock_root` | 0.0% | 0/1 | 1 | 1 |  |
| 400 | `mcl_as_broadcaster` | 0.0% | 0/12 | 1 | 12 |  |
| 401 | `mcl_events_swf_version` | 0.0% | 0/232 | 1 | 232 |  |
| 402 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 403 | `mcl_loadclip_properties` | 0.0% | 0/6 | 1 | 6 |  |
| 404 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 1 | 1 |  |
| 405 | `mcl_mislabeled_target` | 0.0% | 0/6 | 1 | 6 |  |
| 406 | `mcl_target_gif87a` | 0.0% | 0/6 | 1 | 6 |  |
| 407 | `mcl_target_gif89a` | 0.0% | 0/6 | 1 | 6 |  |
| 408 | `mcl_target_jpg` | 0.0% | 0/6 | 1 | 6 |  |
| 409 | `mcl_target_png` | 0.0% | 0/6 | 1 | 6 |  |
| 410 | `mcl_unloadclip` | 0.0% | 0/5 | 1 | 5 |  |
| 411 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 1 | 2 |  |
| 412 | `mouse_events` | 0.0% | 0/8 | 1 | 8 |  |
| 413 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 1 | 12 |  |
| 414 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 1 | 1 |  |
| 415 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 416 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 417 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 418 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 1 | 35 |  |
| 419 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 420 | `movieclip_gettextsnapshot` | 0.0% | 0/112 | 21 | 112 |  |
| 421 | `movieclip_in_removed_button` | 0.0% | 0/4 | 1 | 4 |  |
| 422 | `movieclip_init_object` | 0.0% | 0/5 | 1 | 5 |  |
| 423 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 424 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 1 | 4 |  |
| 425 | `named_shapes` | 0.0% | 0/14 | 1 | 14 |  |
| 426 | `native_double_construct` | 0.0% | 0/12 | 1 | 12 |  |
| 427 | `native_objects_swf6` | 0.0% | 0/84 | 1 | 84 |  |
| 428 | `native_objects_swf7` | 0.0% | 0/84 | 1 | 84 |  |
| 429 | `native_objects_swf8` | 0.0% | 0/84 | 1 | 84 |  |
| 430 | `native_subclasses` | 0.0% | 0/191 | 1 | 191 |  |
| 431 | `netconnection_send_remote` | 0.0% | 0/50 | 1 | 50 |  |
| 432 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 433 | `netstream_seek_flv` | 0.0% | 0/25 | 1 | 25 |  |
| 434 | `new_method_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 435 | `new_object_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 436 | `object_properties` | 0.0% | 0/31 | 1 | 31 |  |
| 437 | `object_resolve` | 0.0% | 0/38 | 1 | 38 |  |
| 438 | `on_construct` | 0.0% | 0/25 | 1 | 25 |  |
| 439 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 440 | `place_and_lookup` | 0.0% | 0/30 | 1 | 30 |  |
| 441 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 442 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 1 |  |
| 443 | `register_class_return_value` | 0.0% | 0/16 | 1 | 16 |  |
| 444 | `register_class_swf6` | 0.0% | 0/37 | 1 | 37 |  |
| 445 | `register_class_with_sound` | 0.0% | 0/11 | 1 | 11 |  |
| 446 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 447 | `removed_target_clip_scope` | 0.0% | 0/35 | 1 | 35 |  |
| 448 | `resolve_different_root` | 0.0% | 0/2 | 1 | 2 |  |
| 449 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 450 | `root_onload` | 0.0% | 0/1 | 1 | 1 |  |
| 451 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 452 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 453 | `selection` | 0.0% | 0/454 | 1 | 454 |  |
| 454 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 455 | `slash_syntax` | 0.0% | 0/14 | 1 | 14 |  |
| 456 | `sound_load_start` | 0.0% | 0/3 | 1 | 3 |  |
| 457 | `sound_multiple_load` | 0.0% | 0/1 | 1 | 1 |  |
| 458 | `stage_object_enumerate` | 0.0% | 0/4 | 1 | 4 |  |
| 459 | `string_methods_negative_args` | 0.0% | 0/240 | 1 | 240 |  |
| 460 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 461 | `string_paths_eval` | 0.0% | 0/4 | 1 | 4 |  |
| 462 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 463 | `string_paths_unload` | 0.0% | 0/1 | 1 | 1 |  |
| 464 | `string_paths_variable_scopes` | 0.0% | 0/5 | 1 | 5 |  |
| 465 | `stylesheet` | 0.0% | 0/283 | 1 | 283 |  |
| 466 | `super_edge_cases` | 0.0% | 0/39 | 1 | 39 |  |
| 467 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 468 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 469 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 470 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 471 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 1 | 92 |  |
| 472 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 1 | 21 |  |
| 473 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 1 | 12 |  |
| 474 | `tab_ordering_children` | 0.0% | 0/208 | 1 | 208 |  |
| 475 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 1 | 71 |  |
| 476 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 1 | 22 |  |
| 477 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 1 | 12 |  |
| 478 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 1 | 29 |  |
| 479 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 1 | 65 |  |
| 480 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 1 | 462 |  |
| 481 | `tab_ordering_properties_tab_index_edge_case` | 0.0% | 0/4 | 4 | 4 |  |
| 482 | `tab_ordering_reverse` | 0.0% | 0/51 | 1 | 51 |  |
| 483 | `tab_ordering_tabbable` | 0.0% | 0/47 | 1 | 47 |  |
| 484 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 485 | `target_clip_swf5` | 0.0% | 0/2 | 1 | 2 |  |
| 486 | `target_clip_swf6` | 0.0% | 0/2 | 1 | 2 |  |
| 487 | `target_path` | 0.0% | 0/14 | 1 | 14 |  |
| 488 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 489 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 490 | `text_blocks_clicks` | 0.0% | 0/4 | 1 | 4 |  |
| 491 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 492 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 |  |
| 493 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 494 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 495 | `timer_run_actions` | 0.0% | 0/18 | 1 | 18 |  |
| 496 | `typeof` | 0.0% | 0/22 | 1 | 22 |  |
| 497 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 498 | `unload_clip_event` | 0.0% | 0/4 | 1 | 4 |  |
| 499 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 500 | `use_hand_cursor` | 0.0% | 0/8 | 1 | 8 |  |
| 501 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 502 | `watch` | 0.0% | 0/117 | 1 | 117 |  |
| 503 | `watch_textfield` | 0.0% | 0/12 | 1 | 12 |  |
| 504 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 |  |
| 505 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 506 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 507 | `xml_ignore_comments` | 0.0% | 0/21 | 1 | 21 |  |
| 508 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 509 | `xml_load` | 0.0% | 0/2 | 1 | 2 |  |
| 510 | `xml_reparenting` | 0.0% | 0/14 | 1 | 14 |  |
| 511 | `xml_socket` | 0.0% | 0/8 | 1 | 8 |  |
| 512 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 1 | 6 |  |
| 513 | `xml_socket_on_data` | 0.0% | 0/7 | 1 | 7 |  |
| 514 | `xml_socket_segmented` | 0.0% | 0/29 | 1 | 29 |  |
| 515 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 516 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 517 | `xml_unescaping` | 0.0% | 0/23 | 1 | 23 |  |
| 518 | `xmlnode_proto` | 0.0% | 0/1 | 1 | 1 |  |
