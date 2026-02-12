# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-12 03:25 UTC

**Git SHA**: `082fbae125`

**Run Duration**: 27m 9s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 616 |
| Passing | **73** (11.9%) |
| Failing | 543 |
| Total expected lines | 88845 |
| Matching lines | 30617 (34.5%) |
| Mismatched lines | 58228 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 526 | 96.9% |
| Runtime Segfault | 10 | 1.8% |
| Timeout | 4 | 0.7% |
| Runtime Error | 3 | 0.6% |

## Passing Tests

**73 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 4.1s |  |
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
| 14 | `bitand` | 1058 | 10.6s |  |
| 15 | `bitmap_data_colortransform` | 1 | 2.4s |  |
| 16 | `bitmap_data_fillrect` | 1 | 2.2s |  |
| 17 | `bitmap_data_perlinnoise` | 1 | 2.9s |  |
| 18 | `bitmap_data_pixeldissolve_image` | 1 | 2.6s |  |
| 19 | `bitmapdata_applyfilter_colormatrix` | 1 | 2.1s |  |
| 20 | `bitor` | 1058 | 10.8s |  |
| 21 | `biturshift` | 14 | 2.3s |  |
| 22 | `biturshift_swf8` | 14 | 2.1s |  |
| 23 | `bitxor` | 1058 | 10.8s |  |
| 24 | `catch_references_registers` | 2 | 2.0s |  |
| 25 | `define_function_case_sensitive` | 2 | 2.0s |  |
| 26 | `divide_swf4` | 107 | 2.2s |  |
| 27 | `do_init_action` | 3 | 2.2s |  |
| 28 | `equals` | 32 | 2.2s |  |
| 29 | `equals_swf4` | 665 | 5.8s |  |
| 30 | `equals_swf4_alt` | 32 | 2.1s |  |
| 31 | `equals_swf5` | 32 | 2.1s |  |
| 32 | `focusrect_mouse_swf8` | 1 | 2.0s |  |
| 33 | `focusrect_mouse_swf9` | 1 | 2.0s |  |
| 34 | `global_is_bare` | 7 | 2.0s |  |
| 35 | `goto_execution_order` | 2 | 2.0s |  |
| 36 | `goto_rewind1` | 1 | 2.1s |  |
| 37 | `greaterthan_swf5` | 1 | 2.1s |  |
| 38 | `greaterthan_swf8` | 1 | 2.1s |  |
| 39 | `infinite_recursion_function` | 4 | 2.0s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 40 | `infinite_recursion_function_in_setter` | 131 | 2.1s |  |
| 41 | `infinite_recursion_virtual_property` | 67 | 2.0s |  |
| 42 | `issue_1086` | 1 | 2.0s |  |
| 43 | `issue_1671` | 1 | 2.0s |  |
| 44 | `issue_3446` | 1 | 2.1s |  |
| 45 | `issue_4377` | 2 | 2.1s |  |
| 46 | `issue_768` | 3 | 2.0s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 47 | `lessthan` | 41 | 2.2s |  |
| 48 | `lessthan_swf4` | 902 | 7.5s |  |
| 49 | `lessthan_swf4_alt` | 41 | 2.2s |  |
| 50 | `lessthan_swf5` | 41 | 2.2s |  |
| 51 | `logical_ops_swf4` | 90 | 2.1s |  |
| 52 | `logical_ops_swf8` | 108 | 2.2s |  |
| 53 | `looping` | 6 | 2.0s |  |
| 54 | `mask_reapply` | 1 | 2.0s |  |
| 55 | `mask_with_drawing` | 1 | 2.0s |  |
| 56 | `movieclip_begin_gradient_fill` | 1 | 2.8s |  |
| 57 | `movieclip_line_gradient_style` | 1 | 2.7s |  |
| 58 | `nested_textfields_in_buttons` | 1 | 2.0s |  |
| 59 | `sandbox_type_local_file` | 1 | 1.9s |  |
| 60 | `single_frame` | 1 | 1.9s |  |
| 61 | `sound_start_load` | 1 | 2.0s |  |
| 62 | `strictequals_swf6` | 902 | 7.8s |  |
| 63 | `strictly_equals` | 7 | 2.0s |  |
| 64 | `string_paths_keyevents` | 1 | 2.0s |  |
| 65 | `string_paths_timer` | 1 | 2.0s |  |
| 66 | `swf4_actions_bool` | 96 | 2.1s |  |
| 67 | `swf4_bool` | 4 | 2.0s |  |
| 68 | `swf5_encoding` | 3 | 4.2s |  |
| 69 | `timeline_function_def` | 7 | 2.1s |  |
| 70 | `try_finally_simple` | 16 | 2.2s |  |
| 71 | `typeof_globals` | 7 | 2.2s |  |
| 72 | `undefined_to_string_swf6` | 4 | 2.2s |  |
| 73 | `with_return` | 2 | 2.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**121 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `equals2_swf6` | 99.9% | 925 | 926 | 1 |  |
| 2 | `equals2_swf7` | 99.9% | 925 | 926 | 1 |  |
| 3 | `equals2_swf5` | 99.8% | 924 | 926 | 2 |  |
| 4 | `string_coercion` | 99.1% | 116 | 117 | 1 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 5 | `object_string_coerce_swf5` | 95.4% | 62 | 65 | 3 |  |
| 6 | `object_function` | 90.6% | 29 | 32 | 3 |  |
| 7 | `has_own_property` | 87.5% | 28 | 32 | 4 |  |
| 8 | `swf7_case_sensitive` | 84.1% | 37 | 44 | 7 |  |
| 9 | `array_properties` | 83.3% | 30 | 36 | 6 |  |
| 10 | `as1_constructor_v7` | 82.9% | 29 | 35 | 6 |  |
| 11 | `getproperty_swf4` | 82.1% | 23 | 28 | 5 |  |
| 12 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 13 | `movieclip_prototype_extension` | 80.0% | 4 | 5 | 1 |  |
| 14 | `greater_swf6` | 77.9% | 915 | 1175 | 260 |  |
| 15 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 16 | `as1_constructor_v6` | 77.1% | 27 | 35 | 8 |  |
| 17 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 18 | `lessthan2_swf5` | 76.5% | 939 | 1228 | 289 |  |
| 19 | `lessthan2_swf6` | 76.5% | 939 | 1228 | 289 |  |
| 20 | `stage_object_children` | 75.9% | 63 | 83 | 20 |  |
| 21 | `bitmap_data_max_size_swf10` | 75.0% | 9 | 12 | 3 |  |
| 22 | `define_function2` | 75.0% | 6 | 8 | 2 |  |
| 23 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 24 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 25 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 26 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 27 | `object_constructor` | 72.7% | 24 | 33 | 9 |  |
| 28 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 29 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 30 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 31 | `greater_swf7` | 71.0% | 834 | 1175 | 341 |  |
| 32 | `point` | 70.9% | 124 | 175 | 51 |  |
| 33 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 34 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 35 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 36 | `lessthan2_swf7` | 69.9% | 858 | 1228 | 370 |  |
| 37 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 38 | `get_variable_in_scope` | 69.0% | 20 | 29 | 9 |  |
| 39 | `array_sort` | 68.3% | 110 | 161 | 51 |  |
| 40 | `set_variable_scope` | 68.3% | 43 | 63 | 20 |  |
| 41 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 42 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 43 | `primitive_instanceof` | 67.6% | 25 | 37 | 12 |  |
| 44 | `this_swf7` | 67.3% | 37 | 55 | 18 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 45 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 46 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 47 | `delete` | 66.7% | 2 | 3 | 1 |  |
| 48 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 49 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 50 | `goto_both_ways2` | 66.7% | 2 | 3 | 1 |  |
| 51 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 52 | `goto_rewind2` | 66.7% | 2 | 3 | 1 |  |
| 53 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 54 | `o` | 66.7% | 2 | 3 | 1 |  |
| 55 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 56 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 57 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 58 | `error` | 65.5% | 38 | 58 | 20 |  |
| 59 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 60 | `getproperty` | 64.3% | 18 | 28 | 10 |  |
| 61 | `getproperty_swf5` | 64.3% | 18 | 28 | 10 |  |
| 62 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 63 | `globals_swf6` | 64.1% | 195 | 304 | 109 |  |
| 64 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 65 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 66 | `globals_swf7` | 63.2% | 192 | 304 | 112 |  |
| 67 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 68 | `globals_swf5` | 61.8% | 188 | 304 | 116 |  |
| 69 | `arguments` | 61.4% | 78 | 127 | 49 |  |
| 70 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 71 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 72 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 73 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 74 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 75 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 76 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 77 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 78 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 79 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 80 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 81 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 82 | `swf6_case_insensitive` | 59.1% | 26 | 44 | 18 |  |
| 83 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 84 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 85 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 86 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 87 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 88 | `primitive_type_globals` | 57.3% | 319 | 557 | 238 |  |
| 89 | `escape` | 57.1% | 8 | 14 | 6 |  |
| 90 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 91 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 92 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 93 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 94 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 95 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 96 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 97 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 98 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 99 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 100 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 101 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 102 | `movieclip_focusenabled` | 52.5% | 52 | 99 | 47 |  |
| 103 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 104 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 105 | `as_set_prop_flags_version` | 51.6% | 16 | 31 | 15 |  |
| 106 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 107 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 108 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 109 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 110 | `goto_advance2` | 50.0% | 1 | 2 | 1 |  |
| 111 | `goto_rewind3` | 50.0% | 1 | 2 | 1 |  |
| 112 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 113 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 114 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 115 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 116 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 117 | `prototype_delete` | 50.0% | 6 | 12 | 6 |  |
| 118 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 119 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 120 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 121 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**10 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `array_constructor` | 4.2s |  |
| 2 | `as2_oop` | 4.3s |  |
| 3 | `device_font_spacing` | 10.5s |  |
| 4 | `duplicate_movie_clip_drawing` | 4.1s |  |
| 5 | `enumerate` | 4.2s |  |
| 6 | `extends_chain` | 4.8s |  |
| 7 | `issue_2166` | 4.2s |  |
| 8 | `netstream_play_flv_screen` | 30.2s |  |
| 9 | `path_string` | 4.5s |  |
| 10 | `swf4_actions_coercion_order` | 3.6s |  |

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `array_length` | exit code -6 | 4.3s |  |
| 2 | `uncaught_exception` | exit code 1 | 2.1s |  |
| 3 | `uncaught_exception_bubbled` | exit code 1 | 2.1s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.2s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.1s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.2s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.7s |  |

## All Output Mismatches

**526 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `equals2_swf6` | 99.9% | 925/926 | 926 | 926 |  |
| 2 | `equals2_swf7` | 99.9% | 925/926 | 926 | 926 |  |
| 3 | `equals2_swf5` | 99.8% | 924/926 | 926 | 926 |  |
| 4 | `string_coercion` | 99.1% | 116/117 | 117 | 117 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 5 | `object_string_coerce_swf5` | 95.4% | 62/65 | 65 | 62 |  |
| 6 | `object_function` | 90.6% | 29/32 | 32 | 32 |  |
| 7 | `has_own_property` | 87.5% | 28/32 | 32 | 32 |  |
| 8 | `swf7_case_sensitive` | 84.1% | 37/44 | 44 | 44 |  |
| 9 | `array_properties` | 83.3% | 30/36 | 36 | 36 |  |
| 10 | `as1_constructor_v7` | 82.9% | 29/35 | 35 | 35 |  |
| 11 | `getproperty_swf4` | 82.1% | 23/28 | 28 | 28 |  |
| 12 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 13 | `movieclip_prototype_extension` | 80.0% | 4/5 | 5 | 5 |  |
| 14 | `greater_swf6` | 77.9% | 915/1175 | 1175 | 1175 |  |
| 15 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 16 | `as1_constructor_v6` | 77.1% | 27/35 | 35 | 35 |  |
| 17 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 18 | `lessthan2_swf5` | 76.5% | 939/1228 | 1228 | 1226 |  |
| 19 | `lessthan2_swf6` | 76.5% | 939/1228 | 1228 | 1226 |  |
| 20 | `stage_object_children` | 75.9% | 63/83 | 83 | 83 |  |
| 21 | `bitmap_data_max_size_swf10` | 75.0% | 9/12 | 12 | 12 |  |
| 22 | `define_function2` | 75.0% | 6/8 | 8 | 8 |  |
| 23 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 24 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 25 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 26 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 27 | `object_constructor` | 72.7% | 24/33 | 33 | 33 |  |
| 28 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 29 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 30 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 31 | `greater_swf7` | 71.0% | 834/1175 | 1175 | 1175 |  |
| 32 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 33 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 34 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 35 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 36 | `lessthan2_swf7` | 69.9% | 858/1228 | 1228 | 1226 |  |
| 37 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 38 | `get_variable_in_scope` | 69.0% | 20/29 | 29 | 29 |  |
| 39 | `array_sort` | 68.3% | 110/161 | 161 | 161 |  |
| 40 | `set_variable_scope` | 68.3% | 43/63 | 63 | 58 |  |
| 41 | `object_string_coerce_swf6` | 67.6% | 46/68 | 65 | 68 |  |
| 42 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 43 | `primitive_instanceof` | 67.6% | 25/37 | 37 | 37 |  |
| 44 | `this_swf7` | 67.3% | 37/55 | 55 | 41 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 45 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 46 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 47 | `delete` | 66.7% | 2/3 | 3 | 3 |  |
| 48 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 49 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 50 | `goto_both_ways2` | 66.7% | 2/3 | 2 | 3 |  |
| 51 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 52 | `goto_rewind2` | 66.7% | 2/3 | 2 | 3 |  |
| 53 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 54 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 55 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 56 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 57 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 58 | `error` | 65.5% | 38/58 | 58 | 58 |  |
| 59 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 60 | `getproperty` | 64.3% | 18/28 | 28 | 28 |  |
| 61 | `getproperty_swf5` | 64.3% | 18/28 | 28 | 28 |  |
| 62 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 63 | `globals_swf6` | 64.1% | 195/304 | 304 | 304 |  |
| 64 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 65 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 66 | `globals_swf7` | 63.2% | 192/304 | 304 | 304 |  |
| 67 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 68 | `globals_swf5` | 61.8% | 188/304 | 304 | 304 |  |
| 69 | `arguments` | 61.4% | 78/127 | 92 | 127 |  |
| 70 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 71 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 72 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 73 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 74 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 75 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 76 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 77 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 78 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 79 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 80 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 81 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 82 | `swf6_case_insensitive` | 59.1% | 26/44 | 44 | 42 |  |
| 83 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 84 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 85 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 86 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 87 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 88 | `primitive_type_globals` | 57.3% | 319/557 | 555 | 557 |  |
| 89 | `escape` | 57.1% | 8/14 | 14 | 14 |  |
| 90 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 91 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 92 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 93 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 94 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 95 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 96 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 97 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 98 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 99 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 100 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 101 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 102 | `movieclip_focusenabled` | 52.5% | 52/99 | 99 | 99 |  |
| 103 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 104 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 336 |  |
| 105 | `as_set_prop_flags_version` | 51.6% | 16/31 | 29 | 31 |  |
| 106 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 107 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 108 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 109 | `execution_order3` | 50.0% | 2/4 | 3 | 4 |  |
| 110 | `goto_advance2` | 50.0% | 1/2 | 1 | 2 |  |
| 111 | `goto_rewind3` | 50.0% | 1/2 | 1 | 2 |  |
| 112 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 113 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 114 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 115 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 116 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 117 | `prototype_delete` | 50.0% | 6/12 | 12 | 12 |  |
| 118 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 119 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 120 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 121 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 122 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 123 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 124 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 125 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 126 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 127 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 128 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 129 | `new_object_enumerate` | 42.9% | 3/7 | 7 | 7 |  |
| 130 | `sound_props_swf6` | 41.2% | 28/68 | 68 | 68 |  |
| 131 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 132 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 133 | `sound_props_swf5` | 39.7% | 27/68 | 67 | 68 |  |
| 134 | `globals_swf8` | 38.8% | 118/304 | 304 | 304 |  |
| 135 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 136 | `as_broadcaster_undef` | 38.2% | 34/89 | 81 | 89 |  |
| 137 | `localconnection_properties` | 37.5% | 3/8 | 8 | 8 |  |
| 138 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 139 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 140 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 141 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 142 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 143 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 144 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 145 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 146 | `goto_both_ways1` | 33.3% | 1/3 | 1 | 3 |  |
| 147 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 148 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 149 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 150 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 151 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 152 | `define_function2_preload` | 30.8% | 4/13 | 12 | 13 |  |
| 153 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 154 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 155 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 156 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 157 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 158 | `define_local_with_paths` | 27.8% | 15/54 | 44 | 54 |  |
| 159 | `this_swf5` | 27.3% | 15/55 | 55 | 41 |  |
| 160 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 161 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 162 | `this_swf6` | 25.5% | 14/55 | 55 | 41 |  |
| 163 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 164 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 165 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 166 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 167 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 168 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 169 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 170 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 171 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 172 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 173 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 174 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 175 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 176 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 177 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 178 | `unescape` | 20.9% | 9/43 | 42 | 43 |  |
| 179 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 180 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 181 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 182 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 183 | `global_array` | 20.0% | 1/5 | 5 | 4 |  |
| 184 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 185 | `xml_attributes_read` | 20.0% | 1/5 | 3 | 5 |  |
| 186 | `frame_size_translated_negative` | 19.0% | 4/21 | 20 | 21 |  |
| 187 | `frame_size_translated_positive` | 19.0% | 4/21 | 20 | 21 |  |
| 188 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 189 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 190 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 191 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 192 | `focusrect_swf5` | 16.7% | 1/6 | 1 | 6 |  |
| 193 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 194 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 195 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 196 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 197 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 198 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 199 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 200 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 201 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 202 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 203 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 204 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 205 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 206 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 207 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 208 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 209 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 210 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 211 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 212 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 213 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 214 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 215 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 216 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 217 | `string_paths_other` | 11.1% | 4/36 | 28 | 36 |  |
| 218 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 219 | `with` | 10.3% | 7/68 | 68 | 49 |  |
| 220 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 221 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 222 | `this_scoping` | 9.6% | 5/52 | 50 | 52 |  |
| 223 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 224 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 225 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 226 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 227 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 228 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 229 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 230 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 231 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 232 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 233 | `funky_function_calls` | 7.1% | 4/56 | 12 | 56 |  |
| 234 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 235 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 236 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 237 | `array_enumerate` | 6.2% | 1/16 | 16 | 4 |  |
| 238 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 239 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 240 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 241 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 242 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 243 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 244 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 245 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 246 | `register_class` | 4.5% | 3/66 | 27 | 66 |  |
| 247 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 248 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 249 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 250 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 251 | `bitmap_data` | 4.1% | 46/1126 | 318 | 1126 |  |
| 252 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 253 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 254 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 255 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 256 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 257 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 258 | `tab_ordering_properties` | 2.7% | 8/293 | 180 | 293 |  |
| 259 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 260 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 261 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 262 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 263 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 264 | `with_variable_scopes` | 1.5% | 1/68 | 68 | 43 |  |
| 265 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 266 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 267 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 268 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 269 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 270 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 271 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 272 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 273 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 274 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 275 | `tab_ordering_events` | 0.7% | 1/150 | 12 | 150 |  |
| 276 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 277 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 278 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 279 | `focusrect_property_swf5` | 0.3% | 4/1241 | 1241 | 1237 |  |
| 280 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 281 | `localconnection` | 0.2% | 1/580 | 1 | 580 |  |
| 282 | `focusrect_property_swf6` | 0.2% | 2/1241 | 1241 | 1237 |  |
| 283 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 284 | `focusrect_property_swf7` | 0.1% | 1/1241 | 1241 | 1237 |  |
| 285 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 286 | `array_sort_random` | 0.0% | 0/443 | 1 | 443 |  |
| 287 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 288 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 289 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 1 | 40 |  |
| 290 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 291 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 292 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 293 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 294 | `asfunction` | 0.0% | 0/11 | 1 | 11 |  |
| 295 | `asnew` | 0.0% | 0/34 | 1 | 34 |  |
| 296 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 1 | 2 |  |
| 297 | `bitmap_data_copypixels` | 0.0% | 0/17 | 1 | 17 |  |
| 298 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 1 | 1075 |  |
| 299 | `bitmap_filters` | 0.0% | 0/548 | 1 | 548 |  |
| 300 | `boxed_primitives` | 0.0% | 0/24 | 1 | 24 |  |
| 301 | `button_children` | 0.0% | 0/8 | 1 | 8 |  |
| 302 | `button_goto` | 0.0% | 0/4 | 1 | 4 |  |
| 303 | `button_key_events` | 0.0% | 0/14 | 1 | 14 |  |
| 304 | `button_key_events_special` | 0.0% | 0/45 | 1 | 45 |  |
| 305 | `button_keypress` | 0.0% | 0/3 | 1 | 3 |  |
| 306 | `button_keypress_vs_press` | 0.0% | 0/25 | 1 | 25 |  |
| 307 | `button_keypress_vs_tab` | 0.0% | 0/20 | 1 | 20 |  |
| 308 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 1 | 4 |  |
| 309 | `button_order` | 0.0% | 0/2 | 1 | 2 |  |
| 310 | `button_properties_special_cases` | 0.0% | 0/22 | 1 | 22 |  |
| 311 | `button_v5` | 0.0% | 0/18 | 1 | 18 |  |
| 312 | `button_v6` | 0.0% | 0/18 | 1 | 18 |  |
| 313 | `call` | 0.0% | 0/63 | 1 | 63 |  |
| 314 | `call_method_empty_name` | 0.0% | 0/1 | 1 | 1 |  |
| 315 | `click_block` | 0.0% | 0/5 | 1 | 5 |  |
| 316 | `clip_constructors` | 0.0% | 0/8 | 1 | 8 |  |
| 317 | `clip_event_propagation_order` | 0.0% | 0/17 | 1 | 17 |  |
| 318 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 319 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 320 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 321 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 1 | 129 |  |
| 322 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 1 | 17 |  |
| 323 | `color` | 0.0% | 0/57 | 1 | 57 |  |
| 324 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 325 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 326 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 327 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 328 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 329 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 330 | `drag_drop` | 0.0% | 0/10 | 1 | 10 |  |
| 331 | `drag_over_from_outside` | 0.0% | 0/1 | 1 | 1 |  |
| 332 | `drag_over_without_startdrag` | 0.0% | 0/1 | 1 | 1 |  |
| 333 | `duplicate_movie_clip` | 0.0% | 0/20 | 1 | 20 |  |
| 334 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 335 | `edittext_drag_select` | 0.0% | 0/9 | 1 | 9 |  |
| 336 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 337 | `edittext_html_roundtrip` | 0.0% | 0/17 | 1 | 17 |  |
| 338 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 1 | 7 |  |
| 339 | `edittext_input` | 0.0% | 0/1 | 1 | 1 |  |
| 340 | `edittext_input_newlines` | 0.0% | 0/9 | 1 | 9 |  |
| 341 | `edittext_password` | 0.0% | 0/5 | 1 | 5 |  |
| 342 | `edittext_password_copy` | 0.0% | 0/4 | 1 | 4 |  |
| 343 | `edittext_paste_empty` | 0.0% | 0/2 | 1 | 2 |  |
| 344 | `edittext_place_caret` | 0.0% | 0/2 | 1 | 2 |  |
| 345 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 346 | `edittext_restrict` | 0.0% | 0/191 | 1 | 191 |  |
| 347 | `edittext_restrict_paste` | 0.0% | 0/5 | 1 | 5 |  |
| 348 | `edittext_tab_focus` | 0.0% | 0/13 | 1 | 13 |  |
| 349 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 350 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 351 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 352 | `extends_native_type` | 0.0% | 0/11 | 1 | 11 |  |
| 353 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 354 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 355 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 356 | `file_reference_browse_cancel` | 0.0% | 0/21 | 1 | 21 |  |
| 357 | `focus_keyboard_press` | 0.0% | 0/60 | 1 | 60 |  |
| 358 | `focus_mouse` | 0.0% | 0/45 | 1 | 45 |  |
| 359 | `focus_mouse_focusable` | 0.0% | 0/8 | 1 | 8 |  |
| 360 | `focus_mouse_rollout` | 0.0% | 0/4 | 1 | 4 |  |
| 361 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 362 | `focusrect_focuslost` | 0.0% | 0/4 | 1 | 4 |  |
| 363 | `focusrect_swf6` | 0.0% | 0/42 | 1 | 42 |  |
| 364 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 365 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 366 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 367 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 368 | `function_base_clip` | 0.0% | 0/8 | 1 | 8 |  |
| 369 | `function_base_clip_readded` | 0.0% | 0/11 | 1 | 11 |  |
| 370 | `function_suppress_and_preload` | 0.0% | 0/28 | 1 | 28 |  |
| 371 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 372 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 373 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 374 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 375 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 376 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 1 | 1145 |  |
| 377 | `global_swf6_7_8` | 0.0% | 0/15 | 1 | 15 |  |
| 378 | `goto_execution_order2` | 0.0% | 0/2 | 1 | 2 |  |
| 379 | `goto_frame` | 0.0% | 0/12 | 1 | 12 |  |
| 380 | `goto_frame2` | 0.0% | 0/44 | 1 | 44 |  |
| 381 | `goto_label` | 0.0% | 0/17 | 1 | 17 |  |
| 382 | `goto_methods` | 0.0% | 0/40 | 1 | 40 |  |
| 383 | `hittest_lockroot` | 0.0% | 0/15 | 1 | 15 |  |
| 384 | `hittest_morph` | 0.0% | 0/70 | 1 | 70 |  |
| 385 | `hittest_morph_input` | 0.0% | 0/1 | 1 | 1 |  |
| 386 | `hittest_winding_rule` | 0.0% | 0/12 | 1 | 12 |  |
| 387 | `init_array_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 388 | `init_object_invalid` | 0.0% | 0/4 | 1 | 4 |  |
| 389 | `init_object_order` | 0.0% | 0/15 | 1 | 15 |  |
| 390 | `input_dead_keys_windows` | 0.0% | 0/15 | 1 | 15 |  |
| 391 | `instanceof_coercions` | 0.0% | 0/88 | 1 | 88 |  |
| 392 | `interface_implements_op` | 0.0% | 0/47 | 1 | 47 |  |
| 393 | `issue_1104` | 0.0% | 0/2 | 1 | 2 |  |
| 394 | `issue_2084` | 0.0% | 0/16 | 1 | 16 |  |
| 395 | `issue_2870` | 0.0% | 0/3 | 1 | 3 |  |
| 396 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 397 | `issue_9327` | 0.0% | 0/2 | 1 | 2 |  |
| 398 | `issue_9885` | 0.0% | 0/2 | 1 | 2 |  |
| 399 | `key_isToggled` | 0.0% | 0/9 | 1 | 9 |  |
| 400 | `loadmovie_fail` | 0.0% | 0/2 | 1 | 2 |  |
| 401 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 402 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 403 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 1 | 9 |  |
| 404 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 405 | `loadvariables_method` | 0.0% | 0/7 | 1 | 7 |  |
| 406 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 407 | `lock_root` | 0.0% | 0/1 | 1 | 1 |  |
| 408 | `mcl_as_broadcaster` | 0.0% | 0/12 | 1 | 12 |  |
| 409 | `mcl_events_swf_version` | 0.0% | 0/232 | 1 | 232 |  |
| 410 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 411 | `mcl_loadclip_properties` | 0.0% | 0/6 | 1 | 6 |  |
| 412 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 1 | 1 |  |
| 413 | `mcl_mislabeled_target` | 0.0% | 0/6 | 1 | 6 |  |
| 414 | `mcl_target_gif87a` | 0.0% | 0/6 | 1 | 6 |  |
| 415 | `mcl_target_gif89a` | 0.0% | 0/6 | 1 | 6 |  |
| 416 | `mcl_target_jpg` | 0.0% | 0/6 | 1 | 6 |  |
| 417 | `mcl_target_png` | 0.0% | 0/6 | 1 | 6 |  |
| 418 | `mcl_unloadclip` | 0.0% | 0/5 | 1 | 5 |  |
| 419 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 1 | 2 |  |
| 420 | `mouse_events` | 0.0% | 0/8 | 1 | 8 |  |
| 421 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 1 | 12 |  |
| 422 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 1 | 1 |  |
| 423 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 424 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 425 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 426 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 1 | 35 |  |
| 427 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 428 | `movieclip_gettextsnapshot` | 0.0% | 0/112 | 21 | 112 |  |
| 429 | `movieclip_in_removed_button` | 0.0% | 0/4 | 1 | 4 |  |
| 430 | `movieclip_init_object` | 0.0% | 0/5 | 1 | 5 |  |
| 431 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 432 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 1 | 4 |  |
| 433 | `named_shapes` | 0.0% | 0/14 | 1 | 14 |  |
| 434 | `native_double_construct` | 0.0% | 0/12 | 1 | 12 |  |
| 435 | `native_objects_swf6` | 0.0% | 0/84 | 1 | 84 |  |
| 436 | `native_objects_swf7` | 0.0% | 0/84 | 1 | 84 |  |
| 437 | `native_objects_swf8` | 0.0% | 0/84 | 1 | 84 |  |
| 438 | `native_subclasses` | 0.0% | 0/191 | 1 | 191 |  |
| 439 | `netconnection_send_remote` | 0.0% | 0/50 | 1 | 50 |  |
| 440 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 441 | `netstream_seek_flv` | 0.0% | 0/25 | 1 | 25 |  |
| 442 | `new_method_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 443 | `new_object_wrap` | 0.0% | 0/4 | 1 | 4 |  |
| 444 | `object_properties` | 0.0% | 0/31 | 1 | 31 |  |
| 445 | `object_resolve` | 0.0% | 0/38 | 1 | 38 |  |
| 446 | `on_construct` | 0.0% | 0/25 | 1 | 25 |  |
| 447 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 448 | `place_and_lookup` | 0.0% | 0/30 | 1 | 30 |  |
| 449 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 450 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 1 |  |
| 451 | `register_class_return_value` | 0.0% | 0/16 | 1 | 16 |  |
| 452 | `register_class_swf6` | 0.0% | 0/37 | 1 | 37 |  |
| 453 | `register_class_with_sound` | 0.0% | 0/11 | 1 | 11 |  |
| 454 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 455 | `removed_target_clip_scope` | 0.0% | 0/35 | 1 | 35 |  |
| 456 | `resolve_different_root` | 0.0% | 0/2 | 1 | 2 |  |
| 457 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 458 | `root_onload` | 0.0% | 0/1 | 1 | 1 |  |
| 459 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 460 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 461 | `selection` | 0.0% | 0/454 | 1 | 454 |  |
| 462 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 463 | `slash_syntax` | 0.0% | 0/14 | 1 | 14 |  |
| 464 | `sound_load_start` | 0.0% | 0/3 | 1 | 3 |  |
| 465 | `sound_multiple_load` | 0.0% | 0/1 | 1 | 1 |  |
| 466 | `stage_object_enumerate` | 0.0% | 0/4 | 1 | 4 |  |
| 467 | `string_methods_negative_args` | 0.0% | 0/240 | 1 | 240 |  |
| 468 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 469 | `string_paths_eval` | 0.0% | 0/4 | 1 | 4 |  |
| 470 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 471 | `string_paths_unload` | 0.0% | 0/1 | 1 | 1 |  |
| 472 | `string_paths_variable_scopes` | 0.0% | 0/5 | 1 | 5 |  |
| 473 | `stylesheet` | 0.0% | 0/283 | 1 | 283 |  |
| 474 | `super_edge_cases` | 0.0% | 0/39 | 1 | 39 |  |
| 475 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 476 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 477 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 478 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 479 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 1 | 92 |  |
| 480 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 1 | 21 |  |
| 481 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 1 | 12 |  |
| 482 | `tab_ordering_children` | 0.0% | 0/208 | 1 | 208 |  |
| 483 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 1 | 71 |  |
| 484 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 1 | 22 |  |
| 485 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 1 | 12 |  |
| 486 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 1 | 29 |  |
| 487 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 1 | 65 |  |
| 488 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 1 | 462 |  |
| 489 | `tab_ordering_properties_tab_index_edge_case` | 0.0% | 0/4 | 4 | 4 |  |
| 490 | `tab_ordering_reverse` | 0.0% | 0/51 | 1 | 51 |  |
| 491 | `tab_ordering_tabbable` | 0.0% | 0/47 | 1 | 47 |  |
| 492 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 493 | `target_clip_swf5` | 0.0% | 0/2 | 1 | 2 |  |
| 494 | `target_clip_swf6` | 0.0% | 0/2 | 1 | 2 |  |
| 495 | `target_path` | 0.0% | 0/14 | 1 | 14 |  |
| 496 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 497 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 498 | `text_blocks_clicks` | 0.0% | 0/4 | 1 | 4 |  |
| 499 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 500 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 |  |
| 501 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 502 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 503 | `timer_run_actions` | 0.0% | 0/18 | 1 | 18 |  |
| 504 | `typeof` | 0.0% | 0/22 | 1 | 22 |  |
| 505 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 506 | `unload_clip_event` | 0.0% | 0/4 | 1 | 4 |  |
| 507 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 508 | `use_hand_cursor` | 0.0% | 0/8 | 1 | 8 |  |
| 509 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 510 | `watch` | 0.0% | 0/117 | 1 | 117 |  |
| 511 | `watch_textfield` | 0.0% | 0/12 | 1 | 12 |  |
| 512 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 |  |
| 513 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 514 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 515 | `xml_ignore_comments` | 0.0% | 0/21 | 1 | 21 |  |
| 516 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 517 | `xml_load` | 0.0% | 0/2 | 1 | 2 |  |
| 518 | `xml_reparenting` | 0.0% | 0/14 | 1 | 14 |  |
| 519 | `xml_socket` | 0.0% | 0/8 | 1 | 8 |  |
| 520 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 1 | 6 |  |
| 521 | `xml_socket_on_data` | 0.0% | 0/7 | 1 | 7 |  |
| 522 | `xml_socket_segmented` | 0.0% | 0/29 | 1 | 29 |  |
| 523 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 524 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 525 | `xml_unescaping` | 0.0% | 0/23 | 1 | 23 |  |
| 526 | `xmlnode_proto` | 0.0% | 0/1 | 1 | 1 |  |
