# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-12 03:43 UTC

**Git SHA**: `a174c955cd`

**Run Duration**: 27m 1s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 616 |
| Passing | **77** (12.5%) |
| Failing | 539 |
| Total expected lines | 88845 |
| Matching lines | 32006 (36.0%) |
| Mismatched lines | 56839 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 522 | 96.8% |
| Runtime Segfault | 10 | 1.9% |
| Timeout | 4 | 0.7% |
| Runtime Error | 3 | 0.6% |

## Passing Tests

**77 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.4s |  |
| 2 | `action_to_integer` | 28 | 2.1s |  |
| 3 | `add` | 28 | 2.1s |  |
| 4 | `add2` | 354 | 2.5s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.1s |  |
| 6 | `add_swf5` | 28 | 2.1s |  |
| 7 | `array_concat` | 98 | 2.3s |  |
| 8 | `array_slice` | 34 | 2.2s |  |
| 9 | `array_splice` | 207 | 2.9s |  |
| 10 | `array_trivial` | 209 | 2.6s |  |
| 11 | `as_broadcaster_initialize` | 10 | 2.1s |  |
| 12 | `as_set_prop_flags_version_swf5` | 1 | 2.1s |  |
| 13 | `bad_swf_tag_past_eof` | 1 | 2.0s |  |
| 14 | `bitand` | 1058 | 10.4s |  |
| 15 | `bitmap_data_colortransform` | 1 | 2.4s |  |
| 16 | `bitmap_data_fillrect` | 1 | 2.2s |  |
| 17 | `bitmap_data_perlinnoise` | 1 | 2.9s |  |
| 18 | `bitmap_data_pixeldissolve_image` | 1 | 2.6s |  |
| 19 | `bitmapdata_applyfilter_colormatrix` | 1 | 2.1s |  |
| 20 | `bitor` | 1058 | 10.4s |  |
| 21 | `biturshift` | 14 | 2.1s |  |
| 22 | `biturshift_swf8` | 14 | 2.0s |  |
| 23 | `bitxor` | 1058 | 11.1s |  |
| 24 | `catch_references_registers` | 2 | 2.0s |  |
| 25 | `define_function_case_sensitive` | 2 | 2.0s |  |
| 26 | `divide_swf4` | 107 | 2.2s |  |
| 27 | `do_init_action` | 3 | 2.0s |  |
| 28 | `equals` | 32 | 2.3s |  |
| 29 | `equals2_swf6` | 926 | 10.0s |  |
| 30 | `equals2_swf7` | 926 | 10.2s |  |
| 31 | `equals_swf4` | 665 | 5.8s |  |
| 32 | `equals_swf4_alt` | 32 | 2.1s |  |
| 33 | `equals_swf5` | 32 | 2.1s |  |
| 34 | `focusrect_mouse_swf8` | 1 | 2.0s |  |
| 35 | `focusrect_mouse_swf9` | 1 | 2.1s |  |
| 36 | `global_is_bare` | 7 | 2.1s |  |
| 37 | `goto_execution_order` | 2 | 2.0s |  |
| 38 | `goto_rewind1` | 1 | 2.1s |  |
| 39 | `greater_swf6` | 1175 | 10.9s |  |
| 40 | `greater_swf7` | 1175 | 10.9s |  |
| 41 | `greaterthan_swf5` | 1 | 2.0s |  |
| 42 | `greaterthan_swf8` | 1 | 2.0s |  |
| 43 | `infinite_recursion_function` | 4 | 2.0s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 44 | `infinite_recursion_function_in_setter` | 131 | 2.1s |  |
| 45 | `infinite_recursion_virtual_property` | 67 | 2.0s |  |
| 46 | `issue_1086` | 1 | 2.0s |  |
| 47 | `issue_1671` | 1 | 2.0s |  |
| 48 | `issue_3446` | 1 | 2.1s |  |
| 49 | `issue_4377` | 2 | 2.0s |  |
| 50 | `issue_768` | 3 | 2.0s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 51 | `lessthan` | 41 | 2.1s |  |
| 52 | `lessthan_swf4` | 902 | 7.3s |  |
| 53 | `lessthan_swf4_alt` | 41 | 2.1s |  |
| 54 | `lessthan_swf5` | 41 | 2.1s |  |
| 55 | `logical_ops_swf4` | 90 | 2.1s |  |
| 56 | `logical_ops_swf8` | 108 | 2.2s |  |
| 57 | `looping` | 6 | 2.0s |  |
| 58 | `mask_reapply` | 1 | 2.0s |  |
| 59 | `mask_with_drawing` | 1 | 2.0s |  |
| 60 | `movieclip_begin_gradient_fill` | 1 | 2.8s |  |
| 61 | `movieclip_line_gradient_style` | 1 | 2.7s |  |
| 62 | `nested_textfields_in_buttons` | 1 | 2.0s |  |
| 63 | `sandbox_type_local_file` | 1 | 2.0s |  |
| 64 | `single_frame` | 1 | 2.0s |  |
| 65 | `sound_start_load` | 1 | 2.1s |  |
| 66 | `strictequals_swf6` | 902 | 8.3s |  |
| 67 | `strictly_equals` | 7 | 2.1s |  |
| 68 | `string_paths_keyevents` | 1 | 2.1s |  |
| 69 | `string_paths_timer` | 1 | 2.1s |  |
| 70 | `swf4_actions_bool` | 96 | 2.2s |  |
| 71 | `swf4_bool` | 4 | 2.0s |  |
| 72 | `swf5_encoding` | 3 | 2.3s |  |
| 73 | `timeline_function_def` | 7 | 2.4s |  |
| 74 | `try_finally_simple` | 16 | 2.0s |  |
| 75 | `typeof_globals` | 7 | 2.0s |  |
| 76 | `undefined_to_string_swf6` | 4 | 2.0s |  |
| 77 | `with_return` | 2 | 2.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**116 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `equals2_swf5` | 99.9% | 925 | 926 | 1 |  |
| 2 | `lessthan2_swf5` | 97.5% | 1197 | 1228 | 31 |  |
| 3 | `lessthan2_swf6` | 97.5% | 1197 | 1228 | 31 |  |
| 4 | `lessthan2_swf7` | 97.5% | 1197 | 1228 | 31 |  |
| 5 | `object_string_coerce_swf5` | 95.4% | 62 | 65 | 3 |  |
| 6 | `object_function` | 90.6% | 29 | 32 | 3 |  |
| 7 | `has_own_property` | 87.5% | 28 | 32 | 4 |  |
| 8 | `swf7_case_sensitive` | 84.1% | 37 | 44 | 7 |  |
| 9 | `array_properties` | 83.3% | 30 | 36 | 6 |  |
| 10 | `as1_constructor_v7` | 82.9% | 29 | 35 | 6 |  |
| 11 | `getproperty_swf4` | 82.1% | 23 | 28 | 5 |  |
| 12 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 13 | `movieclip_prototype_extension` | 80.0% | 4 | 5 | 1 |  |
| 14 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 15 | `as1_constructor_v6` | 77.1% | 27 | 35 | 8 |  |
| 16 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 17 | `stage_object_children` | 75.9% | 63 | 83 | 20 |  |
| 18 | `bitmap_data_max_size_swf10` | 75.0% | 9 | 12 | 3 |  |
| 19 | `define_function2` | 75.0% | 6 | 8 | 2 |  |
| 20 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 21 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 22 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 23 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 24 | `object_constructor` | 72.7% | 24 | 33 | 9 |  |
| 25 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 26 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 27 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 28 | `point` | 70.9% | 124 | 175 | 51 |  |
| 29 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 30 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 31 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 32 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 33 | `get_variable_in_scope` | 69.0% | 20 | 29 | 9 |  |
| 34 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 35 | `set_variable_scope` | 68.3% | 43 | 63 | 20 |  |
| 36 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 37 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 38 | `primitive_instanceof` | 67.6% | 25 | 37 | 12 |  |
| 39 | `this_swf7` | 67.3% | 37 | 55 | 18 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 40 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 41 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 42 | `delete` | 66.7% | 2 | 3 | 1 |  |
| 43 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 44 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 45 | `goto_both_ways2` | 66.7% | 2 | 3 | 1 |  |
| 46 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 47 | `goto_rewind2` | 66.7% | 2 | 3 | 1 |  |
| 48 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 49 | `o` | 66.7% | 2 | 3 | 1 |  |
| 50 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 51 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 52 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 53 | `error` | 65.5% | 38 | 58 | 20 |  |
| 54 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 55 | `getproperty` | 64.3% | 18 | 28 | 10 |  |
| 56 | `getproperty_swf5` | 64.3% | 18 | 28 | 10 |  |
| 57 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 58 | `globals_swf6` | 64.1% | 195 | 304 | 109 |  |
| 59 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 60 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 61 | `globals_swf7` | 63.2% | 192 | 304 | 112 |  |
| 62 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 63 | `globals_swf5` | 61.8% | 188 | 304 | 116 |  |
| 64 | `arguments` | 61.4% | 78 | 127 | 49 |  |
| 65 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 66 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 67 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 68 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 69 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 70 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 71 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 72 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 73 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 74 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 75 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 76 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 77 | `swf6_case_insensitive` | 59.1% | 26 | 44 | 18 |  |
| 78 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 79 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 80 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 81 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 82 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 83 | `primitive_type_globals` | 57.3% | 319 | 557 | 238 |  |
| 84 | `escape` | 57.1% | 8 | 14 | 6 |  |
| 85 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 86 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 87 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 88 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 89 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 90 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 91 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 92 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 93 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 94 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 95 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 96 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 97 | `movieclip_focusenabled` | 52.5% | 52 | 99 | 47 |  |
| 98 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 99 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 100 | `as_set_prop_flags_version` | 51.6% | 16 | 31 | 15 |  |
| 101 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 102 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 103 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 104 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 105 | `goto_advance2` | 50.0% | 1 | 2 | 1 |  |
| 106 | `goto_rewind3` | 50.0% | 1 | 2 | 1 |  |
| 107 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 108 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 109 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 110 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 111 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 112 | `prototype_delete` | 50.0% | 6 | 12 | 6 |  |
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
| 3 | `device_font_spacing` | 8.4s |  |
| 4 | `duplicate_movie_clip_drawing` | 3.4s |  |
| 5 | `enumerate` | 4.2s |  |
| 6 | `extends_chain` | 4.8s |  |
| 7 | `issue_2166` | 4.1s |  |
| 8 | `netstream_play_flv_screen` | 31.1s |  |
| 9 | `path_string` | 4.6s |  |
| 10 | `swf4_actions_coercion_order` | 4.4s |  |

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `array_length` | exit code -6 | 4.4s |  |
| 2 | `uncaught_exception` | exit code 1 | 2.0s |  |
| 3 | `uncaught_exception_bubbled` | exit code 1 | 2.0s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.2s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.1s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.3s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.5s |  |

## All Output Mismatches

**522 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `equals2_swf5` | 99.9% | 925/926 | 926 | 926 |  |
| 2 | `lessthan2_swf5` | 97.5% | 1197/1228 | 1228 | 1226 |  |
| 3 | `lessthan2_swf6` | 97.5% | 1197/1228 | 1228 | 1226 |  |
| 4 | `lessthan2_swf7` | 97.5% | 1197/1228 | 1228 | 1226 |  |
| 5 | `object_string_coerce_swf5` | 95.4% | 62/65 | 65 | 62 |  |
| 6 | `object_function` | 90.6% | 29/32 | 32 | 32 |  |
| 7 | `has_own_property` | 87.5% | 28/32 | 32 | 32 |  |
| 8 | `swf7_case_sensitive` | 84.1% | 37/44 | 44 | 44 |  |
| 9 | `array_properties` | 83.3% | 30/36 | 36 | 36 |  |
| 10 | `as1_constructor_v7` | 82.9% | 29/35 | 35 | 35 |  |
| 11 | `getproperty_swf4` | 82.1% | 23/28 | 28 | 28 |  |
| 12 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 13 | `movieclip_prototype_extension` | 80.0% | 4/5 | 5 | 5 |  |
| 14 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 15 | `as1_constructor_v6` | 77.1% | 27/35 | 35 | 35 |  |
| 16 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 17 | `stage_object_children` | 75.9% | 63/83 | 83 | 83 |  |
| 18 | `bitmap_data_max_size_swf10` | 75.0% | 9/12 | 12 | 12 |  |
| 19 | `define_function2` | 75.0% | 6/8 | 8 | 8 |  |
| 20 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 21 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 22 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 23 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 24 | `object_constructor` | 72.7% | 24/33 | 33 | 33 |  |
| 25 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 26 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 27 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 28 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 29 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 30 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 31 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 32 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 33 | `get_variable_in_scope` | 69.0% | 20/29 | 29 | 29 |  |
| 34 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 35 | `set_variable_scope` | 68.3% | 43/63 | 63 | 58 |  |
| 36 | `object_string_coerce_swf6` | 67.6% | 46/68 | 65 | 68 |  |
| 37 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 38 | `primitive_instanceof` | 67.6% | 25/37 | 37 | 37 |  |
| 39 | `this_swf7` | 67.3% | 37/55 | 55 | 41 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 40 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 41 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 42 | `delete` | 66.7% | 2/3 | 3 | 3 |  |
| 43 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 44 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 45 | `goto_both_ways2` | 66.7% | 2/3 | 2 | 3 |  |
| 46 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 47 | `goto_rewind2` | 66.7% | 2/3 | 2 | 3 |  |
| 48 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 49 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 50 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 51 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 52 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 53 | `error` | 65.5% | 38/58 | 58 | 58 |  |
| 54 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 55 | `getproperty` | 64.3% | 18/28 | 28 | 28 |  |
| 56 | `getproperty_swf5` | 64.3% | 18/28 | 28 | 28 |  |
| 57 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 58 | `globals_swf6` | 64.1% | 195/304 | 304 | 304 |  |
| 59 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 60 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 61 | `globals_swf7` | 63.2% | 192/304 | 304 | 304 |  |
| 62 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 63 | `globals_swf5` | 61.8% | 188/304 | 304 | 304 |  |
| 64 | `arguments` | 61.4% | 78/127 | 92 | 127 |  |
| 65 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 66 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 67 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 68 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 69 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 70 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 71 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 72 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 73 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 74 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 75 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 76 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 77 | `swf6_case_insensitive` | 59.1% | 26/44 | 44 | 42 |  |
| 78 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 79 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 80 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 81 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 82 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 83 | `primitive_type_globals` | 57.3% | 319/557 | 555 | 557 |  |
| 84 | `escape` | 57.1% | 8/14 | 14 | 14 |  |
| 85 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 86 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 87 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 88 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 89 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 90 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 91 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 92 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 93 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 94 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 95 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 96 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 97 | `movieclip_focusenabled` | 52.5% | 52/99 | 99 | 99 |  |
| 98 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 99 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 336 |  |
| 100 | `as_set_prop_flags_version` | 51.6% | 16/31 | 29 | 31 |  |
| 101 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 102 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 103 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 104 | `execution_order3` | 50.0% | 2/4 | 3 | 4 |  |
| 105 | `goto_advance2` | 50.0% | 1/2 | 1 | 2 |  |
| 106 | `goto_rewind3` | 50.0% | 1/2 | 1 | 2 |  |
| 107 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 108 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 109 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 110 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 111 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 112 | `prototype_delete` | 50.0% | 6/12 | 12 | 12 |  |
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
| 124 | `new_object_enumerate` | 42.9% | 3/7 | 7 | 7 |  |
| 125 | `sound_props_swf6` | 41.2% | 28/68 | 68 | 68 |  |
| 126 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 127 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 128 | `sound_props_swf5` | 39.7% | 27/68 | 67 | 68 |  |
| 129 | `globals_swf8` | 38.8% | 118/304 | 304 | 304 |  |
| 130 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 131 | `as_broadcaster_undef` | 38.2% | 34/89 | 81 | 89 |  |
| 132 | `localconnection_properties` | 37.5% | 3/8 | 8 | 8 |  |
| 133 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 134 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 135 | `string_coercion` | 35.7% | 45/126 | 126 | 117 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 136 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 137 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 138 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 139 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 140 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 141 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 142 | `goto_both_ways1` | 33.3% | 1/3 | 1 | 3 |  |
| 143 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 144 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 145 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 146 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 147 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 148 | `define_function2_preload` | 30.8% | 4/13 | 12 | 13 |  |
| 149 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 150 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 151 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 152 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 153 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
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
| 173 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 174 | `unescape` | 20.9% | 9/43 | 42 | 43 |  |
| 175 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 176 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 177 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 178 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 179 | `global_array` | 20.0% | 1/5 | 5 | 4 |  |
| 180 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 181 | `xml_attributes_read` | 20.0% | 1/5 | 3 | 5 |  |
| 182 | `frame_size_translated_negative` | 19.0% | 4/21 | 20 | 21 |  |
| 183 | `frame_size_translated_positive` | 19.0% | 4/21 | 20 | 21 |  |
| 184 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 185 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 186 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 187 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 188 | `focusrect_swf5` | 16.7% | 1/6 | 1 | 6 |  |
| 189 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 190 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 191 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 192 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 193 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 194 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 195 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 196 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 197 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 198 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 199 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 200 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 201 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 202 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 203 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 204 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 205 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 206 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 207 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 208 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 209 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 210 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 211 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 212 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 213 | `string_paths_other` | 11.1% | 4/36 | 28 | 36 |  |
| 214 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 215 | `with` | 10.3% | 7/68 | 68 | 49 |  |
| 216 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 217 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 218 | `this_scoping` | 9.6% | 5/52 | 50 | 52 |  |
| 219 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 220 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 221 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 222 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 223 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 224 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 225 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 226 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 227 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 228 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 229 | `funky_function_calls` | 7.1% | 4/56 | 12 | 56 |  |
| 230 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 231 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 232 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 233 | `array_enumerate` | 6.2% | 1/16 | 16 | 4 |  |
| 234 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 235 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 236 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 237 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 238 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 239 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 240 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 241 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 242 | `register_class` | 4.5% | 3/66 | 27 | 66 |  |
| 243 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 244 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 245 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 246 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 247 | `bitmap_data` | 4.1% | 46/1126 | 318 | 1126 |  |
| 248 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 249 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 250 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 251 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 252 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 253 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 254 | `tab_ordering_properties` | 2.7% | 8/293 | 180 | 293 |  |
| 255 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 256 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 257 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 258 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 259 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 260 | `with_variable_scopes` | 1.5% | 1/68 | 68 | 43 |  |
| 261 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 262 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 263 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 264 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 265 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 266 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 267 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 268 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 269 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 270 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 271 | `tab_ordering_events` | 0.7% | 1/150 | 12 | 150 |  |
| 272 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 273 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 274 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 275 | `focusrect_property_swf5` | 0.3% | 4/1241 | 1241 | 1237 |  |
| 276 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 277 | `localconnection` | 0.2% | 1/580 | 1 | 580 |  |
| 278 | `focusrect_property_swf6` | 0.2% | 2/1241 | 1241 | 1237 |  |
| 279 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 280 | `focusrect_property_swf7` | 0.1% | 1/1241 | 1241 | 1237 |  |
| 281 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 282 | `array_sort_random` | 0.0% | 0/443 | 1 | 443 |  |
| 283 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 284 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 285 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 1 | 40 |  |
| 286 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 287 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 288 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 289 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 290 | `asfunction` | 0.0% | 0/11 | 1 | 11 |  |
| 291 | `asnew` | 0.0% | 0/34 | 1 | 34 |  |
| 292 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 1 | 2 |  |
| 293 | `bitmap_data_copypixels` | 0.0% | 0/17 | 1 | 17 |  |
| 294 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 1 | 1075 |  |
| 295 | `bitmap_filters` | 0.0% | 0/548 | 1 | 548 |  |
| 296 | `boxed_primitives` | 0.0% | 0/24 | 1 | 24 |  |
| 297 | `button_children` | 0.0% | 0/8 | 1 | 8 |  |
| 298 | `button_goto` | 0.0% | 0/4 | 1 | 4 |  |
| 299 | `button_key_events` | 0.0% | 0/14 | 1 | 14 |  |
| 300 | `button_key_events_special` | 0.0% | 0/45 | 1 | 45 |  |
| 301 | `button_keypress` | 0.0% | 0/3 | 1 | 3 |  |
| 302 | `button_keypress_vs_press` | 0.0% | 0/25 | 1 | 25 |  |
| 303 | `button_keypress_vs_tab` | 0.0% | 0/20 | 1 | 20 |  |
| 304 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 1 | 4 |  |
| 305 | `button_order` | 0.0% | 0/2 | 1 | 2 |  |
| 306 | `button_properties_special_cases` | 0.0% | 0/22 | 1 | 22 |  |
| 307 | `button_v5` | 0.0% | 0/18 | 1 | 18 |  |
| 308 | `button_v6` | 0.0% | 0/18 | 1 | 18 |  |
| 309 | `call` | 0.0% | 0/63 | 1 | 63 |  |
| 310 | `call_method_empty_name` | 0.0% | 0/1 | 1 | 1 |  |
| 311 | `click_block` | 0.0% | 0/5 | 1 | 5 |  |
| 312 | `clip_constructors` | 0.0% | 0/8 | 1 | 8 |  |
| 313 | `clip_event_propagation_order` | 0.0% | 0/17 | 1 | 17 |  |
| 314 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 315 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 316 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 317 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 1 | 129 |  |
| 318 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 1 | 17 |  |
| 319 | `color` | 0.0% | 0/57 | 1 | 57 |  |
| 320 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 321 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 322 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 323 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 324 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 325 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 326 | `drag_drop` | 0.0% | 0/10 | 1 | 10 |  |
| 327 | `drag_over_from_outside` | 0.0% | 0/1 | 1 | 1 |  |
| 328 | `drag_over_without_startdrag` | 0.0% | 0/1 | 1 | 1 |  |
| 329 | `duplicate_movie_clip` | 0.0% | 0/20 | 1 | 20 |  |
| 330 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 331 | `edittext_drag_select` | 0.0% | 0/9 | 1 | 9 |  |
| 332 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 333 | `edittext_html_roundtrip` | 0.0% | 0/17 | 1 | 17 |  |
| 334 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 1 | 7 |  |
| 335 | `edittext_input` | 0.0% | 0/1 | 1 | 1 |  |
| 336 | `edittext_input_newlines` | 0.0% | 0/9 | 1 | 9 |  |
| 337 | `edittext_password` | 0.0% | 0/5 | 1 | 5 |  |
| 338 | `edittext_password_copy` | 0.0% | 0/4 | 1 | 4 |  |
| 339 | `edittext_paste_empty` | 0.0% | 0/2 | 1 | 2 |  |
| 340 | `edittext_place_caret` | 0.0% | 0/2 | 1 | 2 |  |
| 341 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 342 | `edittext_restrict` | 0.0% | 0/191 | 1 | 191 |  |
| 343 | `edittext_restrict_paste` | 0.0% | 0/5 | 1 | 5 |  |
| 344 | `edittext_tab_focus` | 0.0% | 0/13 | 1 | 13 |  |
| 345 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 346 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 347 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 348 | `extends_native_type` | 0.0% | 0/11 | 1 | 11 |  |
| 349 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 350 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 351 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 352 | `file_reference_browse_cancel` | 0.0% | 0/21 | 1 | 21 |  |
| 353 | `focus_keyboard_press` | 0.0% | 0/60 | 1 | 60 |  |
| 354 | `focus_mouse` | 0.0% | 0/45 | 1 | 45 |  |
| 355 | `focus_mouse_focusable` | 0.0% | 0/8 | 1 | 8 |  |
| 356 | `focus_mouse_rollout` | 0.0% | 0/4 | 1 | 4 |  |
| 357 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 358 | `focusrect_focuslost` | 0.0% | 0/4 | 1 | 4 |  |
| 359 | `focusrect_swf6` | 0.0% | 0/42 | 1 | 42 |  |
| 360 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 361 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 362 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 363 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 364 | `function_base_clip` | 0.0% | 0/8 | 1 | 8 |  |
| 365 | `function_base_clip_readded` | 0.0% | 0/11 | 1 | 11 |  |
| 366 | `function_suppress_and_preload` | 0.0% | 0/28 | 1 | 28 |  |
| 367 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 368 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 369 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 370 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 371 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 372 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 1 | 1145 |  |
| 373 | `global_swf6_7_8` | 0.0% | 0/15 | 1 | 15 |  |
| 374 | `goto_execution_order2` | 0.0% | 0/2 | 1 | 2 |  |
| 375 | `goto_frame` | 0.0% | 0/12 | 1 | 12 |  |
| 376 | `goto_frame2` | 0.0% | 0/44 | 1 | 44 |  |
| 377 | `goto_label` | 0.0% | 0/17 | 1 | 17 |  |
| 378 | `goto_methods` | 0.0% | 0/40 | 1 | 40 |  |
| 379 | `hittest_lockroot` | 0.0% | 0/15 | 1 | 15 |  |
| 380 | `hittest_morph` | 0.0% | 0/70 | 1 | 70 |  |
| 381 | `hittest_morph_input` | 0.0% | 0/1 | 1 | 1 |  |
| 382 | `hittest_winding_rule` | 0.0% | 0/12 | 1 | 12 |  |
| 383 | `init_array_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 384 | `init_object_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 385 | `init_object_order` | 0.0% | 0/15 | 1 | 15 |  |
| 386 | `input_dead_keys_windows` | 0.0% | 0/15 | 1 | 15 |  |
| 387 | `instanceof_coercions` | 0.0% | 0/88 | 1 | 88 |  |
| 388 | `interface_implements_op` | 0.0% | 0/47 | 1 | 47 |  |
| 389 | `issue_1104` | 0.0% | 0/2 | 1 | 2 |  |
| 390 | `issue_2084` | 0.0% | 0/16 | 1 | 16 |  |
| 391 | `issue_2870` | 0.0% | 0/3 | 1 | 3 |  |
| 392 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 393 | `issue_9327` | 0.0% | 0/2 | 1 | 2 |  |
| 394 | `issue_9885` | 0.0% | 0/2 | 1 | 2 |  |
| 395 | `key_isToggled` | 0.0% | 0/9 | 1 | 9 |  |
| 396 | `loadmovie_fail` | 0.0% | 0/2 | 1 | 2 |  |
| 397 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 398 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 399 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 1 | 9 |  |
| 400 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 401 | `loadvariables_method` | 0.0% | 0/7 | 1 | 7 |  |
| 402 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 403 | `lock_root` | 0.0% | 0/1 | 1 | 1 |  |
| 404 | `mcl_as_broadcaster` | 0.0% | 0/12 | 1 | 12 |  |
| 405 | `mcl_events_swf_version` | 0.0% | 0/232 | 1 | 232 |  |
| 406 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 407 | `mcl_loadclip_properties` | 0.0% | 0/6 | 1 | 6 |  |
| 408 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 1 | 1 |  |
| 409 | `mcl_mislabeled_target` | 0.0% | 0/6 | 1 | 6 |  |
| 410 | `mcl_target_gif87a` | 0.0% | 0/6 | 1 | 6 |  |
| 411 | `mcl_target_gif89a` | 0.0% | 0/6 | 1 | 6 |  |
| 412 | `mcl_target_jpg` | 0.0% | 0/6 | 1 | 6 |  |
| 413 | `mcl_target_png` | 0.0% | 0/6 | 1 | 6 |  |
| 414 | `mcl_unloadclip` | 0.0% | 0/5 | 1 | 5 |  |
| 415 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 1 | 2 |  |
| 416 | `mouse_events` | 0.0% | 0/8 | 1 | 8 |  |
| 417 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 1 | 12 |  |
| 418 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 1 | 1 |  |
| 419 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 420 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 421 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 422 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 1 | 35 |  |
| 423 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 424 | `movieclip_gettextsnapshot` | 0.0% | 0/112 | 21 | 112 |  |
| 425 | `movieclip_in_removed_button` | 0.0% | 0/4 | 1 | 4 |  |
| 426 | `movieclip_init_object` | 0.0% | 0/5 | 1 | 5 |  |
| 427 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 428 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 1 | 4 |  |
| 429 | `named_shapes` | 0.0% | 0/14 | 1 | 14 |  |
| 430 | `native_double_construct` | 0.0% | 0/12 | 1 | 12 |  |
| 431 | `native_objects_swf6` | 0.0% | 0/84 | 1 | 84 |  |
| 432 | `native_objects_swf7` | 0.0% | 0/84 | 1 | 84 |  |
| 433 | `native_objects_swf8` | 0.0% | 0/84 | 1 | 84 |  |
| 434 | `native_subclasses` | 0.0% | 0/191 | 1 | 191 |  |
| 435 | `netconnection_send_remote` | 0.0% | 0/50 | 1 | 50 |  |
| 436 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 437 | `netstream_seek_flv` | 0.0% | 0/25 | 1 | 25 |  |
| 438 | `new_method_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 439 | `new_object_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 440 | `object_properties` | 0.0% | 0/31 | 1 | 31 |  |
| 441 | `object_resolve` | 0.0% | 0/38 | 1 | 38 |  |
| 442 | `on_construct` | 0.0% | 0/25 | 1 | 25 |  |
| 443 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 444 | `place_and_lookup` | 0.0% | 0/30 | 1 | 30 |  |
| 445 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 446 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 1 |  |
| 447 | `register_class_return_value` | 0.0% | 0/16 | 1 | 16 |  |
| 448 | `register_class_swf6` | 0.0% | 0/37 | 1 | 37 |  |
| 449 | `register_class_with_sound` | 0.0% | 0/11 | 1 | 11 |  |
| 450 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 451 | `removed_target_clip_scope` | 0.0% | 0/35 | 1 | 35 |  |
| 452 | `resolve_different_root` | 0.0% | 0/2 | 1 | 2 |  |
| 453 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 454 | `root_onload` | 0.0% | 0/1 | 1 | 1 |  |
| 455 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 456 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 457 | `selection` | 0.0% | 0/454 | 1 | 454 |  |
| 458 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 459 | `slash_syntax` | 0.0% | 0/14 | 1 | 14 |  |
| 460 | `sound_load_start` | 0.0% | 0/3 | 1 | 3 |  |
| 461 | `sound_multiple_load` | 0.0% | 0/1 | 1 | 1 |  |
| 462 | `stage_object_enumerate` | 0.0% | 0/4 | 1 | 4 |  |
| 463 | `string_methods_negative_args` | 0.0% | 0/240 | 1 | 240 |  |
| 464 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 465 | `string_paths_eval` | 0.0% | 0/4 | 1 | 4 |  |
| 466 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 467 | `string_paths_unload` | 0.0% | 0/1 | 1 | 1 |  |
| 468 | `string_paths_variable_scopes` | 0.0% | 0/5 | 1 | 5 |  |
| 469 | `stylesheet` | 0.0% | 0/283 | 1 | 283 |  |
| 470 | `super_edge_cases` | 0.0% | 0/39 | 1 | 39 |  |
| 471 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 472 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 473 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 474 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 475 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 1 | 92 |  |
| 476 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 1 | 21 |  |
| 477 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 1 | 12 |  |
| 478 | `tab_ordering_children` | 0.0% | 0/208 | 1 | 208 |  |
| 479 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 1 | 71 |  |
| 480 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 1 | 22 |  |
| 481 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 1 | 12 |  |
| 482 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 1 | 29 |  |
| 483 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 1 | 65 |  |
| 484 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 1 | 462 |  |
| 485 | `tab_ordering_properties_tab_index_edge_case` | 0.0% | 0/4 | 4 | 4 |  |
| 486 | `tab_ordering_reverse` | 0.0% | 0/51 | 1 | 51 |  |
| 487 | `tab_ordering_tabbable` | 0.0% | 0/47 | 1 | 47 |  |
| 488 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 489 | `target_clip_swf5` | 0.0% | 0/2 | 1 | 2 |  |
| 490 | `target_clip_swf6` | 0.0% | 0/2 | 1 | 2 |  |
| 491 | `target_path` | 0.0% | 0/14 | 1 | 14 |  |
| 492 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 493 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 494 | `text_blocks_clicks` | 0.0% | 0/4 | 1 | 4 |  |
| 495 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 496 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 |  |
| 497 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 498 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 499 | `timer_run_actions` | 0.0% | 0/18 | 1 | 18 |  |
| 500 | `typeof` | 0.0% | 0/22 | 1 | 22 |  |
| 501 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 502 | `unload_clip_event` | 0.0% | 0/4 | 1 | 4 |  |
| 503 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 504 | `use_hand_cursor` | 0.0% | 0/8 | 1 | 8 |  |
| 505 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 506 | `watch` | 0.0% | 0/117 | 1 | 117 |  |
| 507 | `watch_textfield` | 0.0% | 0/12 | 1 | 12 |  |
| 508 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 |  |
| 509 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 510 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 511 | `xml_ignore_comments` | 0.0% | 0/21 | 1 | 21 |  |
| 512 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 513 | `xml_load` | 0.0% | 0/2 | 1 | 2 |  |
| 514 | `xml_reparenting` | 0.0% | 0/14 | 1 | 14 |  |
| 515 | `xml_socket` | 0.0% | 0/8 | 1 | 8 |  |
| 516 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 1 | 6 |  |
| 517 | `xml_socket_on_data` | 0.0% | 0/7 | 1 | 7 |  |
| 518 | `xml_socket_segmented` | 0.0% | 0/29 | 1 | 29 |  |
| 519 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 520 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 521 | `xml_unescaping` | 0.0% | 0/23 | 1 | 23 |  |
| 522 | `xmlnode_proto` | 0.0% | 0/1 | 1 | 1 |  |
