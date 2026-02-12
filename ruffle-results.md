# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-11 17:39 UTC

**Git SHA**: `79c7aeee9d`

**Run Duration**: 26m 46s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 616 |
| Passing | **80** (13.0%) |
| Failing | 536 |
| Total expected lines | 87335 |
| Matching lines | 31513 (36.1%) |
| Mismatched lines | 55822 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 512 | 95.5% |
| Runtime Segfault | 10 | 1.9% |
| Runtime Error | 10 | 1.9% |
| Timeout | 4 | 0.7% |

## Passing Tests

**80 tests passing**

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
| 35 | `focusrect_mouse_swf8` | 1 | 2.0s |  |
| 36 | `focusrect_mouse_swf9` | 1 | 2.1s |  |
| 37 | `global_is_bare` | 7 | 2.1s |  |
| 38 | `goto_execution_order` | 2 | 2.0s |  |
| 39 | `goto_rewind1` | 1 | 2.0s |  |
| 40 | `greater_swf6` | 1175 | 11.2s |  |
| 41 | `greater_swf7` | 1175 | 11.0s |  |
| 42 | `greaterthan_swf5` | 1 | 2.0s |  |
| 43 | `greaterthan_swf8` | 1 | 2.0s |  |
| 44 | `infinite_recursion_function` | 4 | 2.0s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 45 | `infinite_recursion_function_in_setter` | 131 | 2.0s |  |
| 46 | `infinite_recursion_virtual_property` | 67 | 2.0s |  |
| 47 | `issue_1086` | 1 | 2.0s |  |
| 48 | `issue_1671` | 1 | 2.0s |  |
| 49 | `issue_3446` | 1 | 2.0s |  |
| 50 | `issue_4377` | 2 | 2.0s |  |
| 51 | `lessthan` | 41 | 2.1s |  |
| 52 | `lessthan2_swf5` | 1226 | 11.7s |  |
| 53 | `lessthan2_swf6` | 1226 | 11.7s |  |
| 54 | `lessthan2_swf7` | 1226 | 11.7s |  |
| 55 | `lessthan_swf4` | 902 | 7.4s |  |
| 56 | `lessthan_swf4_alt` | 41 | 2.1s |  |
| 57 | `lessthan_swf5` | 41 | 2.1s |  |
| 58 | `logical_ops_swf4` | 90 | 2.1s |  |
| 59 | `logical_ops_swf8` | 108 | 2.1s |  |
| 60 | `looping` | 6 | 2.0s |  |
| 61 | `mask_reapply` | 1 | 2.0s |  |
| 62 | `mask_with_drawing` | 1 | 2.0s |  |
| 63 | `movieclip_begin_gradient_fill` | 1 | 2.7s |  |
| 64 | `movieclip_line_gradient_style` | 1 | 2.6s |  |
| 65 | `nested_textfields_in_buttons` | 1 | 2.0s |  |
| 66 | `sandbox_type_local_file` | 1 | 1.9s |  |
| 67 | `single_frame` | 1 | 2.0s |  |
| 68 | `sound_start_load` | 1 | 2.0s |  |
| 69 | `strictequals_swf6` | 902 | 8.2s |  |
| 70 | `strictly_equals` | 7 | 2.0s |  |
| 71 | `string_paths_keyevents` | 1 | 2.0s |  |
| 72 | `string_paths_timer` | 1 | 2.0s |  |
| 73 | `swf4_actions_bool` | 96 | 2.1s |  |
| 74 | `swf4_bool` | 4 | 2.0s |  |
| 75 | `swf5_encoding` | 3 | 2.2s |  |
| 76 | `timeline_function_def` | 7 | 2.1s |  |
| 77 | `try_finally_simple` | 16 | 2.0s |  |
| 78 | `typeof_globals` | 7 | 1.9s |  |
| 79 | `undefined_to_string_swf6` | 4 | 1.9s |  |
| 80 | `with_return` | 2 | 1.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**105 tests** within reach

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
| 9 | `bitmap_data_max_size_swf10` | 75.0% | 9 | 12 | 3 |  |
| 10 | `define_function2` | 75.0% | 6 | 8 | 2 |  |
| 11 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 12 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 13 | `stage_object_children` | 73.5% | 61 | 83 | 22 |  |
| 14 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 15 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 16 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 17 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 18 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 19 | `point` | 70.9% | 124 | 175 | 51 |  |
| 20 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 21 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 22 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 23 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 24 | `get_variable_in_scope` | 69.0% | 20 | 29 | 9 |  |
| 25 | `set_variable_scope` | 68.3% | 43 | 63 | 20 |  |
| 26 | `primitive_instanceof` | 67.6% | 25 | 37 | 12 |  |
| 27 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 28 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 29 | `delete` | 66.7% | 2 | 3 | 1 |  |
| 30 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 31 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 32 | `goto_both_ways2` | 66.7% | 2 | 3 | 1 |  |
| 33 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 34 | `goto_rewind2` | 66.7% | 2 | 3 | 1 |  |
| 35 | `issue_768` | 66.7% | 2 | 3 | 1 | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 36 | `o` | 66.7% | 2 | 3 | 1 |  |
| 37 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 38 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 39 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 40 | `as1_constructor_v6` | 65.7% | 23 | 35 | 12 |  |
| 41 | `as1_constructor_v7` | 65.7% | 23 | 35 | 12 |  |
| 42 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 43 | `getproperty` | 64.3% | 18 | 28 | 10 |  |
| 44 | `getproperty_swf5` | 64.3% | 18 | 28 | 10 |  |
| 45 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 46 | `error` | 63.8% | 37 | 58 | 21 |  |
| 47 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 48 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 49 | `globals_swf6` | 63.2% | 192 | 304 | 112 |  |
| 50 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 51 | `globals_swf7` | 62.2% | 189 | 304 | 115 |  |
| 52 | `arguments` | 61.4% | 78 | 127 | 49 |  |
| 53 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 54 | `mutable_this` | 61.1% | 11 | 18 | 7 |  |
| 55 | `globals_swf5` | 60.9% | 185 | 304 | 119 |  |
| 56 | `object_constructor` | 60.6% | 20 | 33 | 13 |  |
| 57 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 58 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 59 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 60 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 61 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 62 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 63 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 64 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 65 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 66 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 67 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 68 | `swf6_case_insensitive` | 59.1% | 26 | 44 | 18 |  |
| 69 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 70 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 71 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 72 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 73 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 74 | `primitive_type_globals` | 57.3% | 319 | 557 | 238 |  |
| 75 | `escape` | 57.1% | 8 | 14 | 6 |  |
| 76 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 77 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 78 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 79 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 80 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 81 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 82 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 83 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 84 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 85 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 86 | `this_swf7` | 52.7% | 29 | 55 | 26 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 87 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 88 | `movieclip_focusenabled` | 52.5% | 52 | 99 | 47 |  |
| 89 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 90 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 91 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 92 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 93 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 94 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 95 | `goto_advance2` | 50.0% | 1 | 2 | 1 |  |
| 96 | `goto_rewind3` | 50.0% | 1 | 2 | 1 |  |
| 97 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 98 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 99 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 100 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 101 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 102 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 103 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 104 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 105 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**10 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `array_constructor` | 4.3s |  |
| 2 | `as2_oop` | 4.3s |  |
| 3 | `device_font_spacing` | 10.0s |  |
| 4 | `duplicate_movie_clip_drawing` | 4.0s |  |
| 5 | `enumerate` | 4.2s |  |
| 6 | `extends_chain` | 4.8s |  |
| 7 | `issue_2166` | 4.1s |  |
| 8 | `netstream_play_flv_screen` | 30.8s |  |
| 9 | `path_string` | 4.5s |  |
| 10 | `swf4_actions_coercion_order` | 4.2s |  |

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

**512 tests** with output mismatch, sorted by match rate (best first)

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
| 9 | `bitmap_data_max_size_swf10` | 75.0% | 9/12 | 12 | 12 |  |
| 10 | `define_function2` | 75.0% | 6/8 | 8 | 8 |  |
| 11 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 12 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 13 | `stage_object_children` | 73.5% | 61/83 | 83 | 83 |  |
| 14 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 15 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 16 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 17 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 18 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 19 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 20 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 21 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 22 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 23 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 24 | `get_variable_in_scope` | 69.0% | 20/29 | 29 | 29 |  |
| 25 | `set_variable_scope` | 68.3% | 43/63 | 63 | 58 |  |
| 26 | `primitive_instanceof` | 67.6% | 25/37 | 37 | 37 |  |
| 27 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 28 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 29 | `delete` | 66.7% | 2/3 | 3 | 3 |  |
| 30 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 31 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 32 | `goto_both_ways2` | 66.7% | 2/3 | 2 | 3 |  |
| 33 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 34 | `goto_rewind2` | 66.7% | 2/3 | 2 | 3 |  |
| 35 | `issue_768` | 66.7% | 2/3 | 3 | 3 | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 36 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 37 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 38 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 39 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 40 | `as1_constructor_v6` | 65.7% | 23/35 | 35 | 35 |  |
| 41 | `as1_constructor_v7` | 65.7% | 23/35 | 35 | 35 |  |
| 42 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 43 | `getproperty` | 64.3% | 18/28 | 28 | 28 |  |
| 44 | `getproperty_swf5` | 64.3% | 18/28 | 28 | 28 |  |
| 45 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 46 | `error` | 63.8% | 37/58 | 58 | 58 |  |
| 47 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 48 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 49 | `globals_swf6` | 63.2% | 192/304 | 304 | 304 |  |
| 50 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 51 | `globals_swf7` | 62.2% | 189/304 | 304 | 304 |  |
| 52 | `arguments` | 61.4% | 78/127 | 92 | 127 |  |
| 53 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 54 | `mutable_this` | 61.1% | 11/18 | 18 | 18 |  |
| 55 | `globals_swf5` | 60.9% | 185/304 | 304 | 304 |  |
| 56 | `object_constructor` | 60.6% | 20/33 | 33 | 33 |  |
| 57 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 58 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 59 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 60 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 61 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 62 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 63 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 64 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 65 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 66 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 67 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 68 | `swf6_case_insensitive` | 59.1% | 26/44 | 44 | 42 |  |
| 69 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 70 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 71 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 72 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 73 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 74 | `primitive_type_globals` | 57.3% | 319/557 | 555 | 557 |  |
| 75 | `escape` | 57.1% | 8/14 | 14 | 14 |  |
| 76 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 77 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 78 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 79 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 80 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 81 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 82 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 83 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 84 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 85 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 86 | `this_swf7` | 52.7% | 29/55 | 55 | 41 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 87 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 88 | `movieclip_focusenabled` | 52.5% | 52/99 | 99 | 99 |  |
| 89 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 90 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 336 |  |
| 91 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 92 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 93 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 94 | `execution_order3` | 50.0% | 2/4 | 3 | 4 |  |
| 95 | `goto_advance2` | 50.0% | 1/2 | 1 | 2 |  |
| 96 | `goto_rewind3` | 50.0% | 1/2 | 1 | 2 |  |
| 97 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 98 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 99 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 100 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 101 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 102 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 103 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 104 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 105 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 106 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 107 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 108 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 109 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 110 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 111 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 112 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 113 | `new_object_enumerate` | 42.9% | 3/7 | 5 | 7 |  |
| 114 | `sound_props_swf6` | 41.2% | 28/68 | 68 | 68 |  |
| 115 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 116 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 117 | `sound_props_swf5` | 39.7% | 27/68 | 67 | 68 |  |
| 118 | `define_function2_preload` | 38.5% | 5/13 | 12 | 13 |  |
| 119 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 120 | `as_broadcaster_undef` | 38.2% | 34/89 | 81 | 89 |  |
| 121 | `globals_swf8` | 37.8% | 115/304 | 304 | 304 |  |
| 122 | `localconnection_properties` | 37.5% | 3/8 | 8 | 8 |  |
| 123 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 124 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 125 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 126 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 127 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 128 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 129 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 130 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 131 | `goto_both_ways1` | 33.3% | 1/3 | 1 | 3 |  |
| 132 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 133 | `prototype_delete` | 33.3% | 4/12 | 12 | 12 |  |
| 134 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 135 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 136 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 137 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 138 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 139 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 140 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 141 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 142 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 143 | `define_local_with_paths` | 27.8% | 15/54 | 44 | 54 |  |
| 144 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 145 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 146 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 147 | `define_function2_preload_order` | 25.0% | 1/4 | 2 | 4 |  |
| 148 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 149 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 150 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 151 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 152 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 153 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 154 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 155 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 156 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 157 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 158 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 159 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 160 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 161 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 162 | `unescape` | 20.9% | 9/43 | 42 | 43 |  |
| 163 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 164 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 165 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 166 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 167 | `global_array` | 20.0% | 1/5 | 5 | 4 |  |
| 168 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 169 | `xml_attributes_read` | 20.0% | 1/5 | 3 | 5 |  |
| 170 | `object_string_coerce_swf5` | 19.4% | 12/62 | 57 | 62 |  |
| 171 | `object_string_coerce_swf6` | 19.1% | 13/68 | 57 | 68 |  |
| 172 | `frame_size_translated_negative` | 19.0% | 4/21 | 20 | 21 |  |
| 173 | `frame_size_translated_positive` | 19.0% | 4/21 | 20 | 21 |  |
| 174 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 175 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 176 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 177 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 178 | `focusrect_swf5` | 16.7% | 1/6 | 1 | 6 |  |
| 179 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 180 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 181 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 182 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 183 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 184 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 185 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 186 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 187 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 188 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 189 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 190 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 191 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 192 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 193 | `this_swf5` | 12.7% | 7/55 | 55 | 41 |  |
| 194 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 195 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 196 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 197 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 198 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 199 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 200 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 201 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 202 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 203 | `this_swf6` | 10.9% | 6/55 | 55 | 41 |  |
| 204 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 205 | `with` | 10.3% | 7/68 | 68 | 49 |  |
| 206 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 207 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 208 | `this_scoping` | 9.6% | 5/52 | 50 | 52 |  |
| 209 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 210 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 211 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 212 | `string_coercion` | 8.5% | 10/117 | 89 | 117 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 213 | `string_paths_other` | 8.3% | 3/36 | 28 | 36 |  |
| 214 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 215 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 216 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 217 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 218 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 219 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 220 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 221 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 222 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 223 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 224 | `array_enumerate` | 6.2% | 1/16 | 16 | 4 |  |
| 225 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 226 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 227 | `object_prototypes` | 5.4% | 4/74 | 71 | 74 |  |
| 228 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 229 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 230 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 231 | `swf5_no_closure` | 5.3% | 1/19 | 8 | 19 |  |
| 232 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 233 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 234 | `register_class` | 4.5% | 3/66 | 27 | 66 |  |
| 235 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 236 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 237 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 238 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 239 | `bitmap_data` | 4.1% | 46/1126 | 318 | 1126 |  |
| 240 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 241 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 242 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 243 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 244 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 245 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 246 | `tab_ordering_properties` | 2.7% | 8/293 | 180 | 293 |  |
| 247 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 248 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 249 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 250 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 251 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 252 | `with_variable_scopes` | 1.5% | 1/68 | 68 | 43 |  |
| 253 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 254 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 255 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 256 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 257 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 258 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 259 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 260 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 261 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 262 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 263 | `tab_ordering_events` | 0.7% | 1/150 | 12 | 150 |  |
| 264 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 265 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 266 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 267 | `focusrect_property_swf5` | 0.3% | 4/1241 | 1241 | 1237 |  |
| 268 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 269 | `localconnection` | 0.2% | 1/580 | 1 | 580 |  |
| 270 | `focusrect_property_swf6` | 0.2% | 2/1241 | 1241 | 1237 |  |
| 271 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 272 | `focusrect_property_swf7` | 0.1% | 1/1241 | 1241 | 1237 |  |
| 273 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 274 | `array_sort_random` | 0.0% | 0/443 | 1 | 443 |  |
| 275 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 276 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 277 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 1 | 40 |  |
| 278 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 279 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 280 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 281 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 282 | `asfunction` | 0.0% | 0/11 | 1 | 11 |  |
| 283 | `asnew` | 0.0% | 0/34 | 1 | 34 |  |
| 284 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 1 | 2 |  |
| 285 | `bitmap_data_copypixels` | 0.0% | 0/17 | 1 | 17 |  |
| 286 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 1 | 1075 |  |
| 287 | `bitmap_filters` | 0.0% | 0/548 | 1 | 548 |  |
| 288 | `boxed_primitives` | 0.0% | 0/24 | 1 | 24 |  |
| 289 | `button_children` | 0.0% | 0/8 | 1 | 8 |  |
| 290 | `button_goto` | 0.0% | 0/4 | 1 | 4 |  |
| 291 | `button_key_events` | 0.0% | 0/14 | 1 | 14 |  |
| 292 | `button_key_events_special` | 0.0% | 0/45 | 1 | 45 |  |
| 293 | `button_keypress` | 0.0% | 0/3 | 1 | 3 |  |
| 294 | `button_keypress_vs_press` | 0.0% | 0/25 | 1 | 25 |  |
| 295 | `button_keypress_vs_tab` | 0.0% | 0/20 | 1 | 20 |  |
| 296 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 1 | 4 |  |
| 297 | `button_order` | 0.0% | 0/2 | 1 | 2 |  |
| 298 | `button_properties_special_cases` | 0.0% | 0/22 | 1 | 22 |  |
| 299 | `button_v5` | 0.0% | 0/18 | 1 | 18 |  |
| 300 | `button_v6` | 0.0% | 0/18 | 1 | 18 |  |
| 301 | `call` | 0.0% | 0/63 | 1 | 63 |  |
| 302 | `call_method_empty_name` | 0.0% | 0/1 | 1 | 1 |  |
| 303 | `click_block` | 0.0% | 0/5 | 1 | 5 |  |
| 304 | `clip_constructors` | 0.0% | 0/8 | 1 | 8 |  |
| 305 | `clip_event_propagation_order` | 0.0% | 0/17 | 1 | 17 |  |
| 306 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 307 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 308 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 309 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 1 | 129 |  |
| 310 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 1 | 17 |  |
| 311 | `color` | 0.0% | 0/57 | 1 | 57 |  |
| 312 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 313 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 314 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 315 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 316 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 317 | `drag_drop` | 0.0% | 0/10 | 1 | 10 |  |
| 318 | `drag_over_from_outside` | 0.0% | 0/1 | 1 | 1 |  |
| 319 | `drag_over_without_startdrag` | 0.0% | 0/1 | 1 | 1 |  |
| 320 | `duplicate_movie_clip` | 0.0% | 0/20 | 1 | 20 |  |
| 321 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 322 | `edittext_drag_select` | 0.0% | 0/9 | 1 | 9 |  |
| 323 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 324 | `edittext_html_roundtrip` | 0.0% | 0/17 | 1 | 17 |  |
| 325 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 1 | 7 |  |
| 326 | `edittext_input` | 0.0% | 0/1 | 1 | 1 |  |
| 327 | `edittext_input_newlines` | 0.0% | 0/9 | 1 | 9 |  |
| 328 | `edittext_password` | 0.0% | 0/5 | 1 | 5 |  |
| 329 | `edittext_password_copy` | 0.0% | 0/4 | 1 | 4 |  |
| 330 | `edittext_paste_empty` | 0.0% | 0/2 | 1 | 2 |  |
| 331 | `edittext_place_caret` | 0.0% | 0/2 | 1 | 2 |  |
| 332 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 333 | `edittext_restrict` | 0.0% | 0/191 | 1 | 191 |  |
| 334 | `edittext_restrict_paste` | 0.0% | 0/5 | 1 | 5 |  |
| 335 | `edittext_tab_focus` | 0.0% | 0/13 | 1 | 13 |  |
| 336 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 337 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 338 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 339 | `extends_native_type` | 0.0% | 0/11 | 1 | 11 |  |
| 340 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 341 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 342 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 343 | `file_reference_browse_cancel` | 0.0% | 0/21 | 1 | 21 |  |
| 344 | `focus_keyboard_press` | 0.0% | 0/60 | 1 | 60 |  |
| 345 | `focus_mouse` | 0.0% | 0/45 | 1 | 45 |  |
| 346 | `focus_mouse_focusable` | 0.0% | 0/8 | 1 | 8 |  |
| 347 | `focus_mouse_rollout` | 0.0% | 0/4 | 1 | 4 |  |
| 348 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 349 | `focusrect_focuslost` | 0.0% | 0/4 | 1 | 4 |  |
| 350 | `focusrect_swf6` | 0.0% | 0/42 | 1 | 42 |  |
| 351 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 352 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 353 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 354 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 355 | `function_base_clip` | 0.0% | 0/8 | 1 | 8 |  |
| 356 | `function_base_clip_readded` | 0.0% | 0/11 | 1 | 11 |  |
| 357 | `function_suppress_and_preload` | 0.0% | 0/28 | 1 | 28 |  |
| 358 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 359 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 360 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 361 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 362 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 363 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 1 | 1145 |  |
| 364 | `global_swf6_7_8` | 0.0% | 0/15 | 1 | 15 |  |
| 365 | `goto_execution_order2` | 0.0% | 0/2 | 1 | 2 |  |
| 366 | `goto_frame` | 0.0% | 0/12 | 1 | 12 |  |
| 367 | `goto_frame2` | 0.0% | 0/44 | 1 | 44 |  |
| 368 | `goto_label` | 0.0% | 0/17 | 1 | 17 |  |
| 369 | `goto_methods` | 0.0% | 0/40 | 1 | 40 |  |
| 370 | `hittest_lockroot` | 0.0% | 0/15 | 1 | 15 |  |
| 371 | `hittest_morph` | 0.0% | 0/70 | 1 | 70 |  |
| 372 | `hittest_morph_input` | 0.0% | 0/1 | 1 | 1 |  |
| 373 | `hittest_winding_rule` | 0.0% | 0/12 | 1 | 12 |  |
| 374 | `init_array_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 375 | `init_object_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 376 | `init_object_order` | 0.0% | 0/15 | 1 | 15 |  |
| 377 | `input_dead_keys_windows` | 0.0% | 0/15 | 1 | 15 |  |
| 378 | `instanceof_coercions` | 0.0% | 0/88 | 1 | 88 |  |
| 379 | `interface_implements_op` | 0.0% | 0/47 | 1 | 47 |  |
| 380 | `issue_1104` | 0.0% | 0/2 | 1 | 2 |  |
| 381 | `issue_2084` | 0.0% | 0/16 | 1 | 16 |  |
| 382 | `issue_2870` | 0.0% | 0/3 | 1 | 3 |  |
| 383 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 384 | `issue_9327` | 0.0% | 0/2 | 1 | 2 |  |
| 385 | `issue_9885` | 0.0% | 0/2 | 1 | 2 |  |
| 386 | `key_isToggled` | 0.0% | 0/9 | 1 | 9 |  |
| 387 | `loadmovie_fail` | 0.0% | 0/2 | 1 | 2 |  |
| 388 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 389 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 390 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 1 | 9 |  |
| 391 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 392 | `loadvariables_method` | 0.0% | 0/7 | 1 | 7 |  |
| 393 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 394 | `lock_root` | 0.0% | 0/1 | 1 | 1 |  |
| 395 | `mcl_as_broadcaster` | 0.0% | 0/12 | 1 | 12 |  |
| 396 | `mcl_events_swf_version` | 0.0% | 0/232 | 1 | 232 |  |
| 397 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 398 | `mcl_loadclip_properties` | 0.0% | 0/6 | 1 | 6 |  |
| 399 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 1 | 1 |  |
| 400 | `mcl_mislabeled_target` | 0.0% | 0/6 | 1 | 6 |  |
| 401 | `mcl_target_gif87a` | 0.0% | 0/6 | 1 | 6 |  |
| 402 | `mcl_target_gif89a` | 0.0% | 0/6 | 1 | 6 |  |
| 403 | `mcl_target_jpg` | 0.0% | 0/6 | 1 | 6 |  |
| 404 | `mcl_target_png` | 0.0% | 0/6 | 1 | 6 |  |
| 405 | `mcl_unloadclip` | 0.0% | 0/5 | 1 | 5 |  |
| 406 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 1 | 2 |  |
| 407 | `mouse_events` | 0.0% | 0/8 | 1 | 8 |  |
| 408 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 1 | 12 |  |
| 409 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 1 | 1 |  |
| 410 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 411 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 412 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 413 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 1 | 35 |  |
| 414 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 415 | `movieclip_gettextsnapshot` | 0.0% | 0/112 | 21 | 112 |  |
| 416 | `movieclip_in_removed_button` | 0.0% | 0/4 | 1 | 4 |  |
| 417 | `movieclip_init_object` | 0.0% | 0/5 | 1 | 5 |  |
| 418 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 419 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 1 | 4 |  |
| 420 | `named_shapes` | 0.0% | 0/14 | 1 | 14 |  |
| 421 | `native_double_construct` | 0.0% | 0/12 | 1 | 12 |  |
| 422 | `native_objects_swf6` | 0.0% | 0/84 | 1 | 84 |  |
| 423 | `native_objects_swf7` | 0.0% | 0/84 | 1 | 84 |  |
| 424 | `native_objects_swf8` | 0.0% | 0/84 | 1 | 84 |  |
| 425 | `native_subclasses` | 0.0% | 0/191 | 1 | 191 |  |
| 426 | `netconnection_send_remote` | 0.0% | 0/50 | 1 | 50 |  |
| 427 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 428 | `netstream_seek_flv` | 0.0% | 0/25 | 1 | 25 |  |
| 429 | `new_method_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 430 | `new_object_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 431 | `object_properties` | 0.0% | 0/31 | 1 | 31 |  |
| 432 | `object_resolve` | 0.0% | 0/38 | 1 | 38 |  |
| 433 | `on_construct` | 0.0% | 0/25 | 1 | 25 |  |
| 434 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 435 | `place_and_lookup` | 0.0% | 0/30 | 1 | 30 |  |
| 436 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 1 |  |
| 437 | `register_class_return_value` | 0.0% | 0/16 | 1 | 16 |  |
| 438 | `register_class_swf6` | 0.0% | 0/37 | 1 | 37 |  |
| 439 | `register_class_with_sound` | 0.0% | 0/11 | 1 | 11 |  |
| 440 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 441 | `removed_target_clip_scope` | 0.0% | 0/35 | 1 | 35 |  |
| 442 | `resolve_different_root` | 0.0% | 0/2 | 1 | 2 |  |
| 443 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 444 | `root_onload` | 0.0% | 0/1 | 1 | 1 |  |
| 445 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 446 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 447 | `selection` | 0.0% | 0/454 | 1 | 454 |  |
| 448 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 449 | `slash_syntax` | 0.0% | 0/14 | 1 | 14 |  |
| 450 | `sound_load_start` | 0.0% | 0/3 | 1 | 3 |  |
| 451 | `sound_multiple_load` | 0.0% | 0/1 | 1 | 1 |  |
| 452 | `stage_object_enumerate` | 0.0% | 0/4 | 1 | 4 |  |
| 453 | `string_methods_negative_args` | 0.0% | 0/240 | 1 | 240 |  |
| 454 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 455 | `string_paths_eval` | 0.0% | 0/4 | 1 | 4 |  |
| 456 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 457 | `string_paths_unload` | 0.0% | 0/1 | 1 | 1 |  |
| 458 | `string_paths_variable_scopes` | 0.0% | 0/5 | 1 | 5 |  |
| 459 | `stylesheet` | 0.0% | 0/283 | 1 | 283 |  |
| 460 | `super_edge_cases` | 0.0% | 0/39 | 1 | 39 |  |
| 461 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 462 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 463 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 464 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 465 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 1 | 92 |  |
| 466 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 1 | 21 |  |
| 467 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 1 | 12 |  |
| 468 | `tab_ordering_children` | 0.0% | 0/208 | 1 | 208 |  |
| 469 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 1 | 71 |  |
| 470 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 1 | 22 |  |
| 471 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 1 | 12 |  |
| 472 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 1 | 29 |  |
| 473 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 1 | 65 |  |
| 474 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 1 | 462 |  |
| 475 | `tab_ordering_properties_tab_index_edge_case` | 0.0% | 0/4 | 4 | 4 |  |
| 476 | `tab_ordering_reverse` | 0.0% | 0/51 | 1 | 51 |  |
| 477 | `tab_ordering_tabbable` | 0.0% | 0/47 | 1 | 47 |  |
| 478 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 479 | `target_clip_swf5` | 0.0% | 0/2 | 1 | 2 |  |
| 480 | `target_clip_swf6` | 0.0% | 0/2 | 1 | 2 |  |
| 481 | `target_path` | 0.0% | 0/14 | 1 | 14 |  |
| 482 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 483 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 484 | `text_blocks_clicks` | 0.0% | 0/4 | 1 | 4 |  |
| 485 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 486 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 |  |
| 487 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 488 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 489 | `timer_run_actions` | 0.0% | 0/18 | 1 | 18 |  |
| 490 | `typeof` | 0.0% | 0/22 | 1 | 22 |  |
| 491 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 492 | `unload_clip_event` | 0.0% | 0/4 | 1 | 4 |  |
| 493 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 494 | `use_hand_cursor` | 0.0% | 0/8 | 1 | 8 |  |
| 495 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 496 | `watch` | 0.0% | 0/117 | 1 | 117 |  |
| 497 | `watch_textfield` | 0.0% | 0/12 | 1 | 12 |  |
| 498 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 |  |
| 499 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 500 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 501 | `xml_ignore_comments` | 0.0% | 0/21 | 1 | 21 |  |
| 502 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 503 | `xml_load` | 0.0% | 0/2 | 1 | 2 |  |
| 504 | `xml_reparenting` | 0.0% | 0/14 | 1 | 14 |  |
| 505 | `xml_socket` | 0.0% | 0/8 | 1 | 8 |  |
| 506 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 1 | 6 |  |
| 507 | `xml_socket_on_data` | 0.0% | 0/7 | 1 | 7 |  |
| 508 | `xml_socket_segmented` | 0.0% | 0/29 | 1 | 29 |  |
| 509 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 510 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 511 | `xml_unescaping` | 0.0% | 0/23 | 1 | 23 |  |
| 512 | `xmlnode_proto` | 0.0% | 0/1 | 1 | 1 |  |
