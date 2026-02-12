# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-12 02:51 UTC

**Git SHA**: `ee2e040487`

**Run Duration**: 26m 42s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 616 |
| Passing | **75** (12.2%) |
| Failing | 541 |
| Total expected lines | 88845 |
| Matching lines | 31942 (36.0%) |
| Mismatched lines | 56903 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 524 | 96.9% |
| Runtime Segfault | 10 | 1.8% |
| Timeout | 4 | 0.7% |
| Runtime Error | 3 | 0.6% |

## Passing Tests

**75 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.1s |  |
| 2 | `action_to_integer` | 28 | 2.0s |  |
| 3 | `add` | 28 | 2.1s |  |
| 4 | `add2` | 354 | 2.5s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.1s |  |
| 6 | `add_swf5` | 28 | 2.1s |  |
| 7 | `array_concat` | 98 | 2.2s |  |
| 8 | `array_slice` | 34 | 2.2s |  |
| 9 | `array_splice` | 207 | 2.8s |  |
| 10 | `array_trivial` | 209 | 2.6s |  |
| 11 | `as_broadcaster_initialize` | 10 | 2.0s |  |
| 12 | `as_set_prop_flags_version_swf5` | 1 | 2.1s |  |
| 13 | `bad_swf_tag_past_eof` | 1 | 1.9s |  |
| 14 | `bitand` | 1058 | 10.3s |  |
| 15 | `bitmap_data_colortransform` | 1 | 2.3s |  |
| 16 | `bitmap_data_fillrect` | 1 | 2.2s |  |
| 17 | `bitmap_data_perlinnoise` | 1 | 2.8s |  |
| 18 | `bitmap_data_pixeldissolve_image` | 1 | 2.5s |  |
| 19 | `bitmapdata_applyfilter_colormatrix` | 1 | 2.0s |  |
| 20 | `bitor` | 1058 | 10.4s |  |
| 21 | `biturshift` | 14 | 3.5s |  |
| 22 | `biturshift_swf8` | 14 | 2.1s |  |
| 23 | `bitxor` | 1058 | 11.4s |  |
| 24 | `catch_references_registers` | 2 | 2.1s |  |
| 25 | `define_function_case_sensitive` | 2 | 2.0s |  |
| 26 | `divide_swf4` | 107 | 2.3s |  |
| 27 | `do_init_action` | 3 | 2.1s |  |
| 28 | `equals` | 32 | 2.1s |  |
| 29 | `equals_swf4` | 665 | 5.5s |  |
| 30 | `equals_swf4_alt` | 32 | 2.1s |  |
| 31 | `equals_swf5` | 32 | 2.1s |  |
| 32 | `focusrect_mouse_swf8` | 1 | 2.0s |  |
| 33 | `focusrect_mouse_swf9` | 1 | 2.0s |  |
| 34 | `global_is_bare` | 7 | 2.0s |  |
| 35 | `goto_execution_order` | 2 | 2.0s |  |
| 36 | `goto_rewind1` | 1 | 2.0s |  |
| 37 | `greater_swf6` | 1175 | 11.0s |  |
| 38 | `greater_swf7` | 1175 | 10.9s |  |
| 39 | `greaterthan_swf5` | 1 | 2.0s |  |
| 40 | `greaterthan_swf8` | 1 | 2.0s |  |
| 41 | `infinite_recursion_function` | 4 | 2.0s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 42 | `infinite_recursion_function_in_setter` | 131 | 2.0s |  |
| 43 | `infinite_recursion_virtual_property` | 67 | 2.0s |  |
| 44 | `issue_1086` | 1 | 2.0s |  |
| 45 | `issue_1671` | 1 | 2.0s |  |
| 46 | `issue_3446` | 1 | 2.0s |  |
| 47 | `issue_4377` | 2 | 2.0s |  |
| 48 | `issue_768` | 3 | 2.0s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 49 | `lessthan` | 41 | 2.1s |  |
| 50 | `lessthan_swf4` | 902 | 7.4s |  |
| 51 | `lessthan_swf4_alt` | 41 | 2.1s |  |
| 52 | `lessthan_swf5` | 41 | 2.1s |  |
| 53 | `logical_ops_swf4` | 90 | 2.1s |  |
| 54 | `logical_ops_swf8` | 108 | 2.2s |  |
| 55 | `looping` | 6 | 2.1s |  |
| 56 | `mask_reapply` | 1 | 2.0s |  |
| 57 | `mask_with_drawing` | 1 | 2.1s |  |
| 58 | `movieclip_begin_gradient_fill` | 1 | 2.8s |  |
| 59 | `movieclip_line_gradient_style` | 1 | 2.6s |  |
| 60 | `nested_textfields_in_buttons` | 1 | 2.0s |  |
| 61 | `sandbox_type_local_file` | 1 | 2.0s |  |
| 62 | `single_frame` | 1 | 2.0s |  |
| 63 | `sound_start_load` | 1 | 2.0s |  |
| 64 | `strictequals_swf6` | 902 | 8.1s |  |
| 65 | `strictly_equals` | 7 | 2.0s |  |
| 66 | `string_paths_keyevents` | 1 | 2.0s |  |
| 67 | `string_paths_timer` | 1 | 2.0s |  |
| 68 | `swf4_actions_bool` | 96 | 2.2s |  |
| 69 | `swf4_bool` | 4 | 2.0s |  |
| 70 | `swf5_encoding` | 3 | 2.2s |  |
| 71 | `timeline_function_def` | 7 | 2.1s |  |
| 72 | `try_finally_simple` | 16 | 2.0s |  |
| 73 | `typeof_globals` | 7 | 2.0s |  |
| 74 | `undefined_to_string_swf6` | 4 | 2.0s |  |
| 75 | `with_return` | 2 | 2.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**116 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `equals2_swf6` | 99.9% | 925 | 926 | 1 |  |
| 2 | `equals2_swf7` | 99.9% | 925 | 926 | 1 |  |
| 3 | `equals2_swf5` | 99.8% | 924 | 926 | 2 |  |
| 4 | `lessthan2_swf5` | 97.6% | 1199 | 1228 | 29 |  |
| 5 | `lessthan2_swf6` | 97.6% | 1199 | 1228 | 29 |  |
| 6 | `lessthan2_swf7` | 97.3% | 1195 | 1228 | 33 |  |
| 7 | `object_string_coerce_swf5` | 95.4% | 62 | 65 | 3 |  |
| 8 | `object_function` | 90.6% | 29 | 32 | 3 |  |
| 9 | `array_properties` | 83.3% | 30 | 36 | 6 |  |
| 10 | `getproperty_swf4` | 82.1% | 23 | 28 | 5 |  |
| 11 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 12 | `swf7_case_sensitive` | 80.4% | 37 | 46 | 9 |  |
| 13 | `movieclip_prototype_extension` | 80.0% | 4 | 5 | 1 |  |
| 14 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 15 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 16 | `stage_object_children` | 75.9% | 63 | 83 | 20 |  |
| 17 | `bitmap_data_max_size_swf10` | 75.0% | 9 | 12 | 3 |  |
| 18 | `define_function2` | 75.0% | 6 | 8 | 2 |  |
| 19 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 20 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 21 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 22 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 23 | `object_constructor` | 72.7% | 24 | 33 | 9 |  |
| 24 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 25 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 26 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 27 | `point` | 70.9% | 124 | 175 | 51 |  |
| 28 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 29 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 30 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 31 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 32 | `get_variable_in_scope` | 69.0% | 20 | 29 | 9 |  |
| 33 | `array_sort` | 68.3% | 110 | 161 | 51 |  |
| 34 | `set_variable_scope` | 68.3% | 43 | 63 | 20 |  |
| 35 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 36 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 37 | `primitive_instanceof` | 67.6% | 25 | 37 | 12 |  |
| 38 | `this_swf7` | 67.3% | 37 | 55 | 18 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 39 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 40 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 41 | `delete` | 66.7% | 2 | 3 | 1 |  |
| 42 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 43 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 44 | `goto_both_ways2` | 66.7% | 2 | 3 | 1 |  |
| 45 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 46 | `goto_rewind2` | 66.7% | 2 | 3 | 1 |  |
| 47 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 48 | `o` | 66.7% | 2 | 3 | 1 |  |
| 49 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 50 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 51 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 52 | `as1_constructor_v6` | 65.7% | 23 | 35 | 12 |  |
| 53 | `as1_constructor_v7` | 65.7% | 23 | 35 | 12 |  |
| 54 | `has_own_property` | 65.6% | 21 | 32 | 11 |  |
| 55 | `error` | 65.5% | 38 | 58 | 20 |  |
| 56 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 57 | `getproperty` | 64.3% | 18 | 28 | 10 |  |
| 58 | `getproperty_swf5` | 64.3% | 18 | 28 | 10 |  |
| 59 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 60 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 61 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 62 | `globals_swf6` | 63.2% | 192 | 304 | 112 |  |
| 63 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 64 | `globals_swf7` | 62.2% | 189 | 304 | 115 |  |
| 65 | `arguments` | 61.4% | 78 | 127 | 49 |  |
| 66 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 67 | `globals_swf5` | 60.9% | 185 | 304 | 119 |  |
| 68 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 69 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 70 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 71 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 72 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 73 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 74 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 75 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 76 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 77 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 78 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 79 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 80 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 81 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 82 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 83 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 84 | `primitive_type_globals` | 57.3% | 319 | 557 | 238 |  |
| 85 | `escape` | 57.1% | 8 | 14 | 6 |  |
| 86 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 87 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 88 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 89 | `swf6_case_insensitive` | 56.5% | 26 | 46 | 20 |  |
| 90 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 91 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 92 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 93 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 94 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 95 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 96 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 97 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 98 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 99 | `movieclip_focusenabled` | 52.5% | 52 | 99 | 47 |  |
| 100 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 101 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 102 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 103 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 104 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 105 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 106 | `goto_advance2` | 50.0% | 1 | 2 | 1 |  |
| 107 | `goto_rewind3` | 50.0% | 1 | 2 | 1 |  |
| 108 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 109 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 110 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 111 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 112 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 113 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 114 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 115 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 116 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**10 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `array_constructor` | 4.2s |  |
| 2 | `as2_oop` | 4.3s |  |
| 3 | `device_font_spacing` | 10.3s |  |
| 4 | `duplicate_movie_clip_drawing` | 4.1s |  |
| 5 | `enumerate` | 4.2s |  |
| 6 | `extends_chain` | 4.7s |  |
| 7 | `issue_2166` | 4.1s |  |
| 8 | `netstream_play_flv_screen` | 30.1s |  |
| 9 | `path_string` | 4.5s |  |
| 10 | `swf4_actions_coercion_order` | 4.3s |  |

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
| 1 | `parse_float` | runtime timeout (>10s) | 13.2s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.1s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.2s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.5s |  |

## All Output Mismatches

**524 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `equals2_swf6` | 99.9% | 925/926 | 926 | 926 |  |
| 2 | `equals2_swf7` | 99.9% | 925/926 | 926 | 926 |  |
| 3 | `equals2_swf5` | 99.8% | 924/926 | 926 | 926 |  |
| 4 | `lessthan2_swf5` | 97.6% | 1199/1228 | 1228 | 1226 |  |
| 5 | `lessthan2_swf6` | 97.6% | 1199/1228 | 1228 | 1226 |  |
| 6 | `lessthan2_swf7` | 97.3% | 1195/1228 | 1228 | 1226 |  |
| 7 | `object_string_coerce_swf5` | 95.4% | 62/65 | 65 | 62 |  |
| 8 | `object_function` | 90.6% | 29/32 | 32 | 32 |  |
| 9 | `array_properties` | 83.3% | 30/36 | 36 | 36 |  |
| 10 | `getproperty_swf4` | 82.1% | 23/28 | 28 | 28 |  |
| 11 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 12 | `swf7_case_sensitive` | 80.4% | 37/46 | 46 | 44 |  |
| 13 | `movieclip_prototype_extension` | 80.0% | 4/5 | 5 | 5 |  |
| 14 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 15 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 16 | `stage_object_children` | 75.9% | 63/83 | 83 | 83 |  |
| 17 | `bitmap_data_max_size_swf10` | 75.0% | 9/12 | 12 | 12 |  |
| 18 | `define_function2` | 75.0% | 6/8 | 8 | 8 |  |
| 19 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 20 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 21 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 22 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 23 | `object_constructor` | 72.7% | 24/33 | 33 | 33 |  |
| 24 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 25 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 26 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 27 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 28 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 29 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 30 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 31 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 32 | `get_variable_in_scope` | 69.0% | 20/29 | 29 | 29 |  |
| 33 | `array_sort` | 68.3% | 110/161 | 161 | 161 |  |
| 34 | `set_variable_scope` | 68.3% | 43/63 | 63 | 58 |  |
| 35 | `object_string_coerce_swf6` | 67.6% | 46/68 | 65 | 68 |  |
| 36 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 37 | `primitive_instanceof` | 67.6% | 25/37 | 37 | 37 |  |
| 38 | `this_swf7` | 67.3% | 37/55 | 55 | 41 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 39 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 40 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 41 | `delete` | 66.7% | 2/3 | 3 | 3 |  |
| 42 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 43 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 44 | `goto_both_ways2` | 66.7% | 2/3 | 2 | 3 |  |
| 45 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 46 | `goto_rewind2` | 66.7% | 2/3 | 2 | 3 |  |
| 47 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 48 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 49 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 50 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 51 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 52 | `as1_constructor_v6` | 65.7% | 23/35 | 35 | 35 |  |
| 53 | `as1_constructor_v7` | 65.7% | 23/35 | 35 | 35 |  |
| 54 | `has_own_property` | 65.6% | 21/32 | 32 | 32 |  |
| 55 | `error` | 65.5% | 38/58 | 58 | 58 |  |
| 56 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 57 | `getproperty` | 64.3% | 18/28 | 28 | 28 |  |
| 58 | `getproperty_swf5` | 64.3% | 18/28 | 28 | 28 |  |
| 59 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 60 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 61 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 62 | `globals_swf6` | 63.2% | 192/304 | 304 | 304 |  |
| 63 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 64 | `globals_swf7` | 62.2% | 189/304 | 304 | 304 |  |
| 65 | `arguments` | 61.4% | 78/127 | 92 | 127 |  |
| 66 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 67 | `globals_swf5` | 60.9% | 185/304 | 304 | 304 |  |
| 68 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 69 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 70 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 71 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 72 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 73 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 74 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 75 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 76 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 77 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 78 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 79 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 80 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 81 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 82 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 83 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 84 | `primitive_type_globals` | 57.3% | 319/557 | 555 | 557 |  |
| 85 | `escape` | 57.1% | 8/14 | 14 | 14 |  |
| 86 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 87 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 88 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 89 | `swf6_case_insensitive` | 56.5% | 26/46 | 46 | 42 |  |
| 90 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 91 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 92 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 93 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 94 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 95 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 96 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 97 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 98 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 99 | `movieclip_focusenabled` | 52.5% | 52/99 | 99 | 99 |  |
| 100 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 101 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 336 |  |
| 102 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 103 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 104 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 105 | `execution_order3` | 50.0% | 2/4 | 3 | 4 |  |
| 106 | `goto_advance2` | 50.0% | 1/2 | 1 | 2 |  |
| 107 | `goto_rewind3` | 50.0% | 1/2 | 1 | 2 |  |
| 108 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 109 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 110 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 111 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 112 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 113 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 114 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 115 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 116 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 117 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 118 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 119 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 120 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 121 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 122 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 123 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 124 | `sound_props_swf6` | 41.2% | 28/68 | 68 | 68 |  |
| 125 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 126 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 127 | `sound_props_swf5` | 39.7% | 27/68 | 67 | 68 |  |
| 128 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 129 | `as_broadcaster_undef` | 38.2% | 34/89 | 81 | 89 |  |
| 130 | `globals_swf8` | 37.8% | 115/304 | 304 | 304 |  |
| 131 | `localconnection_properties` | 37.5% | 3/8 | 8 | 8 |  |
| 132 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 133 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 134 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 135 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 136 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 137 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 138 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 139 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 140 | `goto_both_ways1` | 33.3% | 1/3 | 1 | 3 |  |
| 141 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 142 | `prototype_delete` | 33.3% | 4/12 | 12 | 12 |  |
| 143 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 144 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 145 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 146 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 147 | `define_function2_preload` | 30.8% | 4/13 | 12 | 13 |  |
| 148 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 149 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 150 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 151 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 152 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 153 | `new_object_enumerate` | 28.6% | 2/7 | 6 | 7 |  |
| 154 | `define_local_with_paths` | 27.8% | 15/54 | 44 | 54 |  |
| 155 | `this_swf5` | 27.3% | 15/55 | 55 | 41 |  |
| 156 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 157 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 158 | `this_swf6` | 25.5% | 14/55 | 55 | 41 |  |
| 159 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 160 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 161 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 162 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 163 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 164 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 165 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 166 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 167 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 168 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 169 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 170 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 171 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 172 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 173 | `as_set_prop_flags_version` | 22.6% | 7/31 | 30 | 31 |  |
| 174 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 175 | `unescape` | 20.9% | 9/43 | 42 | 43 |  |
| 176 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 177 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 178 | `string_coercion` | 20.5% | 24/117 | 116 | 117 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 179 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 180 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 181 | `global_array` | 20.0% | 1/5 | 5 | 4 |  |
| 182 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 183 | `xml_attributes_read` | 20.0% | 1/5 | 3 | 5 |  |
| 184 | `frame_size_translated_negative` | 19.0% | 4/21 | 20 | 21 |  |
| 185 | `frame_size_translated_positive` | 19.0% | 4/21 | 20 | 21 |  |
| 186 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 187 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 188 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 189 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 190 | `focusrect_swf5` | 16.7% | 1/6 | 1 | 6 |  |
| 191 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 192 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 193 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 194 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 195 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 196 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 197 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 198 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 199 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 200 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 201 | `movieclip_setmask` | 13.3% | 2/15 | 15 | 14 |  |
| 202 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 203 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 204 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 205 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 206 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 207 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 208 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 209 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 210 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 211 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 212 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 213 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 214 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 215 | `string_paths_other` | 11.1% | 4/36 | 28 | 36 |  |
| 216 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 217 | `with` | 10.3% | 7/68 | 68 | 49 |  |
| 218 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 219 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 220 | `this_scoping` | 9.6% | 5/52 | 50 | 52 |  |
| 221 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 222 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 223 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 224 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 225 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 226 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 227 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 228 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 229 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 230 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 231 | `funky_function_calls` | 7.1% | 4/56 | 12 | 56 |  |
| 232 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 233 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 234 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 235 | `array_enumerate` | 6.2% | 1/16 | 16 | 4 |  |
| 236 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 237 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 238 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 239 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 240 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 241 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 242 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 243 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 244 | `register_class` | 4.5% | 3/66 | 27 | 66 |  |
| 245 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 246 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 247 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 248 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 249 | `bitmap_data` | 4.1% | 46/1126 | 318 | 1126 |  |
| 250 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 251 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 252 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 253 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 254 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 255 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 256 | `tab_ordering_properties` | 2.7% | 8/293 | 180 | 293 |  |
| 257 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 258 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 259 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 260 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 261 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 262 | `with_variable_scopes` | 1.5% | 1/68 | 68 | 43 |  |
| 263 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 264 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 265 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 266 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 267 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 268 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 269 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 270 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 271 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 272 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 273 | `tab_ordering_events` | 0.7% | 1/150 | 12 | 150 |  |
| 274 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 275 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 276 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 277 | `focusrect_property_swf5` | 0.3% | 4/1241 | 1241 | 1237 |  |
| 278 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 279 | `localconnection` | 0.2% | 1/580 | 1 | 580 |  |
| 280 | `focusrect_property_swf6` | 0.2% | 2/1241 | 1241 | 1237 |  |
| 281 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 282 | `focusrect_property_swf7` | 0.1% | 1/1241 | 1241 | 1237 |  |
| 283 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 284 | `array_sort_random` | 0.0% | 0/443 | 1 | 443 |  |
| 285 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 286 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 287 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 1 | 40 |  |
| 288 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 289 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 290 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 291 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 292 | `asfunction` | 0.0% | 0/11 | 1 | 11 |  |
| 293 | `asnew` | 0.0% | 0/34 | 1 | 34 |  |
| 294 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 1 | 2 |  |
| 295 | `bitmap_data_copypixels` | 0.0% | 0/17 | 1 | 17 |  |
| 296 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 1 | 1075 |  |
| 297 | `bitmap_filters` | 0.0% | 0/548 | 1 | 548 |  |
| 298 | `boxed_primitives` | 0.0% | 0/24 | 1 | 24 |  |
| 299 | `button_children` | 0.0% | 0/8 | 1 | 8 |  |
| 300 | `button_goto` | 0.0% | 0/4 | 1 | 4 |  |
| 301 | `button_key_events` | 0.0% | 0/14 | 1 | 14 |  |
| 302 | `button_key_events_special` | 0.0% | 0/45 | 1 | 45 |  |
| 303 | `button_keypress` | 0.0% | 0/3 | 1 | 3 |  |
| 304 | `button_keypress_vs_press` | 0.0% | 0/25 | 1 | 25 |  |
| 305 | `button_keypress_vs_tab` | 0.0% | 0/20 | 1 | 20 |  |
| 306 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 1 | 4 |  |
| 307 | `button_order` | 0.0% | 0/2 | 1 | 2 |  |
| 308 | `button_properties_special_cases` | 0.0% | 0/22 | 1 | 22 |  |
| 309 | `button_v5` | 0.0% | 0/18 | 1 | 18 |  |
| 310 | `button_v6` | 0.0% | 0/18 | 1 | 18 |  |
| 311 | `call` | 0.0% | 0/63 | 1 | 63 |  |
| 312 | `call_method_empty_name` | 0.0% | 0/1 | 1 | 1 |  |
| 313 | `click_block` | 0.0% | 0/5 | 1 | 5 |  |
| 314 | `clip_constructors` | 0.0% | 0/8 | 1 | 8 |  |
| 315 | `clip_event_propagation_order` | 0.0% | 0/17 | 1 | 17 |  |
| 316 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 317 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 318 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 319 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 1 | 129 |  |
| 320 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 1 | 17 |  |
| 321 | `color` | 0.0% | 0/57 | 1 | 57 |  |
| 322 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 323 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 324 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 325 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 326 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 327 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 328 | `drag_drop` | 0.0% | 0/10 | 1 | 10 |  |
| 329 | `drag_over_from_outside` | 0.0% | 0/1 | 1 | 1 |  |
| 330 | `drag_over_without_startdrag` | 0.0% | 0/1 | 1 | 1 |  |
| 331 | `duplicate_movie_clip` | 0.0% | 0/20 | 1 | 20 |  |
| 332 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 333 | `edittext_drag_select` | 0.0% | 0/9 | 1 | 9 |  |
| 334 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 335 | `edittext_html_roundtrip` | 0.0% | 0/17 | 1 | 17 |  |
| 336 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 1 | 7 |  |
| 337 | `edittext_input` | 0.0% | 0/1 | 1 | 1 |  |
| 338 | `edittext_input_newlines` | 0.0% | 0/9 | 1 | 9 |  |
| 339 | `edittext_password` | 0.0% | 0/5 | 1 | 5 |  |
| 340 | `edittext_password_copy` | 0.0% | 0/4 | 1 | 4 |  |
| 341 | `edittext_paste_empty` | 0.0% | 0/2 | 1 | 2 |  |
| 342 | `edittext_place_caret` | 0.0% | 0/2 | 1 | 2 |  |
| 343 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 344 | `edittext_restrict` | 0.0% | 0/191 | 1 | 191 |  |
| 345 | `edittext_restrict_paste` | 0.0% | 0/5 | 1 | 5 |  |
| 346 | `edittext_tab_focus` | 0.0% | 0/13 | 1 | 13 |  |
| 347 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 348 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 349 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 350 | `extends_native_type` | 0.0% | 0/11 | 1 | 11 |  |
| 351 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 352 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 353 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 354 | `file_reference_browse_cancel` | 0.0% | 0/21 | 1 | 21 |  |
| 355 | `focus_keyboard_press` | 0.0% | 0/60 | 1 | 60 |  |
| 356 | `focus_mouse` | 0.0% | 0/45 | 1 | 45 |  |
| 357 | `focus_mouse_focusable` | 0.0% | 0/8 | 1 | 8 |  |
| 358 | `focus_mouse_rollout` | 0.0% | 0/4 | 1 | 4 |  |
| 359 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 360 | `focusrect_focuslost` | 0.0% | 0/4 | 1 | 4 |  |
| 361 | `focusrect_swf6` | 0.0% | 0/42 | 1 | 42 |  |
| 362 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 363 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 364 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 365 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 366 | `function_base_clip` | 0.0% | 0/8 | 1 | 8 |  |
| 367 | `function_base_clip_readded` | 0.0% | 0/11 | 1 | 11 |  |
| 368 | `function_suppress_and_preload` | 0.0% | 0/28 | 1 | 28 |  |
| 369 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 370 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 371 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 372 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 373 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 374 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 1 | 1145 |  |
| 375 | `global_swf6_7_8` | 0.0% | 0/15 | 1 | 15 |  |
| 376 | `goto_execution_order2` | 0.0% | 0/2 | 1 | 2 |  |
| 377 | `goto_frame` | 0.0% | 0/12 | 1 | 12 |  |
| 378 | `goto_frame2` | 0.0% | 0/44 | 1 | 44 |  |
| 379 | `goto_label` | 0.0% | 0/17 | 1 | 17 |  |
| 380 | `goto_methods` | 0.0% | 0/40 | 1 | 40 |  |
| 381 | `hittest_lockroot` | 0.0% | 0/15 | 1 | 15 |  |
| 382 | `hittest_morph` | 0.0% | 0/70 | 1 | 70 |  |
| 383 | `hittest_morph_input` | 0.0% | 0/1 | 1 | 1 |  |
| 384 | `hittest_winding_rule` | 0.0% | 0/12 | 1 | 12 |  |
| 385 | `init_array_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 386 | `init_object_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 387 | `init_object_order` | 0.0% | 0/15 | 1 | 15 |  |
| 388 | `input_dead_keys_windows` | 0.0% | 0/15 | 1 | 15 |  |
| 389 | `instanceof_coercions` | 0.0% | 0/88 | 1 | 88 |  |
| 390 | `interface_implements_op` | 0.0% | 0/47 | 1 | 47 |  |
| 391 | `issue_1104` | 0.0% | 0/2 | 1 | 2 |  |
| 392 | `issue_2084` | 0.0% | 0/16 | 1 | 16 |  |
| 393 | `issue_2870` | 0.0% | 0/3 | 1 | 3 |  |
| 394 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 395 | `issue_9327` | 0.0% | 0/2 | 1 | 2 |  |
| 396 | `issue_9885` | 0.0% | 0/2 | 1 | 2 |  |
| 397 | `key_isToggled` | 0.0% | 0/9 | 1 | 9 |  |
| 398 | `loadmovie_fail` | 0.0% | 0/2 | 1 | 2 |  |
| 399 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 400 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 401 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 1 | 9 |  |
| 402 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 403 | `loadvariables_method` | 0.0% | 0/7 | 1 | 7 |  |
| 404 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 405 | `lock_root` | 0.0% | 0/1 | 1 | 1 |  |
| 406 | `mcl_as_broadcaster` | 0.0% | 0/12 | 1 | 12 |  |
| 407 | `mcl_events_swf_version` | 0.0% | 0/232 | 1 | 232 |  |
| 408 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 409 | `mcl_loadclip_properties` | 0.0% | 0/6 | 1 | 6 |  |
| 410 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 1 | 1 |  |
| 411 | `mcl_mislabeled_target` | 0.0% | 0/6 | 1 | 6 |  |
| 412 | `mcl_target_gif87a` | 0.0% | 0/6 | 1 | 6 |  |
| 413 | `mcl_target_gif89a` | 0.0% | 0/6 | 1 | 6 |  |
| 414 | `mcl_target_jpg` | 0.0% | 0/6 | 1 | 6 |  |
| 415 | `mcl_target_png` | 0.0% | 0/6 | 1 | 6 |  |
| 416 | `mcl_unloadclip` | 0.0% | 0/5 | 1 | 5 |  |
| 417 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 1 | 2 |  |
| 418 | `mouse_events` | 0.0% | 0/8 | 1 | 8 |  |
| 419 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 1 | 12 |  |
| 420 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 1 | 1 |  |
| 421 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 422 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 423 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 424 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 1 | 35 |  |
| 425 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 426 | `movieclip_gettextsnapshot` | 0.0% | 0/112 | 21 | 112 |  |
| 427 | `movieclip_in_removed_button` | 0.0% | 0/4 | 1 | 4 |  |
| 428 | `movieclip_init_object` | 0.0% | 0/5 | 1 | 5 |  |
| 429 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 430 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 1 | 4 |  |
| 431 | `named_shapes` | 0.0% | 0/14 | 1 | 14 |  |
| 432 | `native_double_construct` | 0.0% | 0/12 | 1 | 12 |  |
| 433 | `native_objects_swf6` | 0.0% | 0/84 | 1 | 84 |  |
| 434 | `native_objects_swf7` | 0.0% | 0/84 | 1 | 84 |  |
| 435 | `native_objects_swf8` | 0.0% | 0/84 | 1 | 84 |  |
| 436 | `native_subclasses` | 0.0% | 0/191 | 1 | 191 |  |
| 437 | `netconnection_send_remote` | 0.0% | 0/50 | 1 | 50 |  |
| 438 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 439 | `netstream_seek_flv` | 0.0% | 0/25 | 1 | 25 |  |
| 440 | `new_method_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 441 | `new_object_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 442 | `object_properties` | 0.0% | 0/31 | 1 | 31 |  |
| 443 | `object_resolve` | 0.0% | 0/38 | 1 | 38 |  |
| 444 | `on_construct` | 0.0% | 0/25 | 1 | 25 |  |
| 445 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 446 | `place_and_lookup` | 0.0% | 0/30 | 1 | 30 |  |
| 447 | `prototype_enumerate` | 0.0% | 0/5 | 3 | 5 |  |
| 448 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 1 |  |
| 449 | `register_class_return_value` | 0.0% | 0/16 | 1 | 16 |  |
| 450 | `register_class_swf6` | 0.0% | 0/37 | 1 | 37 |  |
| 451 | `register_class_with_sound` | 0.0% | 0/11 | 1 | 11 |  |
| 452 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 453 | `removed_target_clip_scope` | 0.0% | 0/35 | 1 | 35 |  |
| 454 | `resolve_different_root` | 0.0% | 0/2 | 1 | 2 |  |
| 455 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 456 | `root_onload` | 0.0% | 0/1 | 1 | 1 |  |
| 457 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 458 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 459 | `selection` | 0.0% | 0/454 | 1 | 454 |  |
| 460 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 461 | `slash_syntax` | 0.0% | 0/14 | 1 | 14 |  |
| 462 | `sound_load_start` | 0.0% | 0/3 | 1 | 3 |  |
| 463 | `sound_multiple_load` | 0.0% | 0/1 | 1 | 1 |  |
| 464 | `stage_object_enumerate` | 0.0% | 0/4 | 1 | 4 |  |
| 465 | `string_methods_negative_args` | 0.0% | 0/240 | 1 | 240 |  |
| 466 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 467 | `string_paths_eval` | 0.0% | 0/4 | 1 | 4 |  |
| 468 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 469 | `string_paths_unload` | 0.0% | 0/1 | 1 | 1 |  |
| 470 | `string_paths_variable_scopes` | 0.0% | 0/5 | 1 | 5 |  |
| 471 | `stylesheet` | 0.0% | 0/283 | 1 | 283 |  |
| 472 | `super_edge_cases` | 0.0% | 0/39 | 1 | 39 |  |
| 473 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 474 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 475 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 476 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 477 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 1 | 92 |  |
| 478 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 1 | 21 |  |
| 479 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 1 | 12 |  |
| 480 | `tab_ordering_children` | 0.0% | 0/208 | 1 | 208 |  |
| 481 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 1 | 71 |  |
| 482 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 1 | 22 |  |
| 483 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 1 | 12 |  |
| 484 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 1 | 29 |  |
| 485 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 1 | 65 |  |
| 486 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 1 | 462 |  |
| 487 | `tab_ordering_properties_tab_index_edge_case` | 0.0% | 0/4 | 4 | 4 |  |
| 488 | `tab_ordering_reverse` | 0.0% | 0/51 | 1 | 51 |  |
| 489 | `tab_ordering_tabbable` | 0.0% | 0/47 | 1 | 47 |  |
| 490 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 491 | `target_clip_swf5` | 0.0% | 0/2 | 1 | 2 |  |
| 492 | `target_clip_swf6` | 0.0% | 0/2 | 1 | 2 |  |
| 493 | `target_path` | 0.0% | 0/14 | 1 | 14 |  |
| 494 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 495 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 496 | `text_blocks_clicks` | 0.0% | 0/4 | 1 | 4 |  |
| 497 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 498 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 |  |
| 499 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 500 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 501 | `timer_run_actions` | 0.0% | 0/18 | 1 | 18 |  |
| 502 | `typeof` | 0.0% | 0/22 | 1 | 22 |  |
| 503 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 504 | `unload_clip_event` | 0.0% | 0/4 | 1 | 4 |  |
| 505 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 506 | `use_hand_cursor` | 0.0% | 0/8 | 1 | 8 |  |
| 507 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 508 | `watch` | 0.0% | 0/117 | 1 | 117 |  |
| 509 | `watch_textfield` | 0.0% | 0/12 | 1 | 12 |  |
| 510 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 |  |
| 511 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 512 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 513 | `xml_ignore_comments` | 0.0% | 0/21 | 1 | 21 |  |
| 514 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 515 | `xml_load` | 0.0% | 0/2 | 1 | 2 |  |
| 516 | `xml_reparenting` | 0.0% | 0/14 | 1 | 14 |  |
| 517 | `xml_socket` | 0.0% | 0/8 | 1 | 8 |  |
| 518 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 1 | 6 |  |
| 519 | `xml_socket_on_data` | 0.0% | 0/7 | 1 | 7 |  |
| 520 | `xml_socket_segmented` | 0.0% | 0/29 | 1 | 29 |  |
| 521 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 522 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 523 | `xml_unescaping` | 0.0% | 0/23 | 1 | 23 |  |
| 524 | `xmlnode_proto` | 0.0% | 0/1 | 1 | 1 |  |
