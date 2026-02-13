# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-13 21:41 UTC

**Git SHA**: `2032bc1f5f`

**Run Duration**: 33m 25s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **139** (22.5%) |
| Failing | 480 |
| Total expected lines | 91286 |
| Matching lines | 33594 (36.8%) |
| Mismatched lines | 57692 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 471 | 98.1% |
| Runtime Segfault | 4 | 0.8% |
| Timeout | 3 | 0.6% |
| Runtime Error | 2 | 0.4% |

## Passing Tests

**139 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.9s |  |
| 2 | `action_to_integer` | 28 | 2.8s |  |
| 3 | `add` | 28 | 2.8s |  |
| 4 | `add2` | 354 | 3.2s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.8s |  |
| 6 | `add_swf5` | 28 | 2.8s |  |
| 7 | `array_concat` | 98 | 3.0s |  |
| 8 | `array_constructor` | 30 | 2.9s |  |
| 9 | `array_length` | 42 | 2.9s |  |
| 10 | `array_properties` | 36 | 2.8s |  |
| 11 | `array_slice` | 34 | 2.9s |  |
| 12 | `array_splice` | 207 | 3.6s |  |
| 13 | `array_trivial` | 209 | 3.3s |  |
| 14 | `as1_constructor_v6` | 35 | 2.8s |  |
| 15 | `as1_constructor_v7` | 35 | 2.9s |  |
| 16 | `as_broadcaster_initialize` | 10 | 2.7s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 2.7s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 2.7s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 2.7s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 2.7s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 2.8s |  |
| 22 | `as_transformed_flag` | 20 | 2.8s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 2.6s |  |
| 24 | `bitand` | 1058 | 9.7s |  |
| 25 | `bitmap_data_colortransform` | 0 | 3.0s |  |
| 26 | `bitmap_data_fillrect` | 0 | 2.9s |  |
| 27 | `bitmap_data_perlinnoise` | 0 | 3.5s |  |
| 28 | `bitmap_data_pixeldissolve_image` | 0 | 3.2s |  |
| 29 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.8s |  |
| 30 | `bitor` | 1058 | 9.9s |  |
| 31 | `biturshift` | 14 | 3.0s |  |
| 32 | `biturshift_swf8` | 14 | 2.7s |  |
| 33 | `bitxor` | 1058 | 9.5s |  |
| 34 | `call_method_empty_name` | 1 | 2.6s |  |
| 35 | `catch_references_registers` | 2 | 2.6s |  |
| 36 | `define_function2` | 8 | 2.7s |  |
| 37 | `define_function2_preload` | 13 | 2.7s |  |
| 38 | `define_function_case_sensitive` | 2 | 2.7s |  |
| 39 | `delete` | 3 | 2.8s |  |
| 40 | `divide_swf4` | 107 | 2.8s |  |
| 41 | `do_init_action` | 3 | 2.7s |  |
| 42 | `equals` | 32 | 2.8s |  |
| 43 | `equals2_swf5` | 926 | 11.4s |  |
| 44 | `equals2_swf6` | 926 | 11.2s |  |
| 45 | `equals2_swf7` | 926 | 11.1s |  |
| 46 | `equals_swf4` | 665 | 6.3s |  |
| 47 | `equals_swf4_alt` | 32 | 2.7s |  |
| 48 | `equals_swf5` | 32 | 2.7s |  |
| 49 | `error` | 58 | 2.8s |  |
| 50 | `escape` | 14 | 2.7s |  |
| 51 | `execution_order3` | 4 | 2.7s |  |
| 52 | `focusrect_mouse_swf8` | 0 | 2.6s |  |
| 53 | `focusrect_mouse_swf9` | 0 | 2.6s |  |
| 54 | `focusrect_swf5` | 6 | 2.8s |  |
| 55 | `get_variable_in_scope` | 29 | 2.8s |  |
| 56 | `getproperty` | 28 | 2.7s |  |
| 57 | `getproperty_swf4` | 28 | 2.7s |  |
| 58 | `getproperty_swf5` | 28 | 2.7s |  |
| 59 | `global_array` | 3 | 2.6s |  |
| 60 | `global_is_bare` | 7 | 2.6s |  |
| 61 | `goto_advance2` | 2 | 2.7s |  |
| 62 | `goto_both_ways1` | 3 | 3.9s |  |
| 63 | `goto_both_ways2` | 3 | 2.8s |  |
| 64 | `goto_execution_order` | 2 | 2.7s |  |
| 65 | `goto_execution_order2` | 2 | 2.7s |  |
| 66 | `goto_frame_number` | 3 | 2.8s |  |
| 67 | `goto_rewind1` | 1 | 2.7s |  |
| 68 | `goto_rewind2` | 3 | 2.8s |  |
| 69 | `goto_rewind3` | 2 | 2.8s |  |
| 70 | `greater_swf6` | 1175 | 12.2s |  |
| 71 | `greater_swf7` | 1175 | 12.0s |  |
| 72 | `greaterthan_swf5` | 1 | 2.7s |  |
| 73 | `greaterthan_swf8` | 1 | 2.7s |  |
| 74 | `has_own_property` | 32 | 2.8s |  |
| 75 | `infinite_recursion_function` | 4 | 2.7s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 76 | `infinite_recursion_function_in_setter` | 131 | 2.7s |  |
| 77 | `infinite_recursion_virtual_property` | 67 | 2.7s |  |
| 78 | `init_array_invalid` | 4 | 2.7s |  |
| 79 | `init_object_invalid` | 4 | 2.7s |  |
| 80 | `issue_1086` | 1 | 2.7s |  |
| 81 | `issue_1671` | 0 | 2.7s |  |
| 82 | `issue_1906` | 4 | 2.8s |  |
| 83 | `issue_3446` | 1 | 2.7s |  |
| 84 | `issue_4377` | 2 | 2.7s |  |
| 85 | `issue_710` | 4 | 2.7s |  |
| 86 | `issue_768` | 3 | 2.7s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 87 | `lessthan` | 41 | 2.8s |  |
| 88 | `lessthan2_swf5` | 1226 | 12.5s |  |
| 89 | `lessthan2_swf6` | 1226 | 12.9s |  |
| 90 | `lessthan2_swf7` | 1226 | 12.6s |  |
| 91 | `lessthan_swf4` | 902 | 8.2s |  |
| 92 | `lessthan_swf4_alt` | 41 | 2.8s |  |
| 93 | `lessthan_swf5` | 41 | 2.8s |  |
| 94 | `logical_ops_swf4` | 90 | 2.6s |  |
| 95 | `logical_ops_swf8` | 108 | 2.6s |  |
| 96 | `looping` | 6 | 2.5s |  |
| 97 | `mask_reapply` | 0 | 2.5s |  |
| 98 | `mask_with_drawing` | 0 | 2.5s |  |
| 99 | `movieclip_begin_gradient_fill` | 0 | 3.1s |  |
| 100 | `movieclip_line_gradient_style` | 0 | 3.1s |  |
| 101 | `movieclip_name_from_timeline` | 13 | 2.5s |  |
| 102 | `movieclip_prototype_extension` | 5 | 2.5s |  |
| 103 | `nested_textfields_in_buttons` | 0 | 2.5s |  |
| 104 | `netstream_play_flv_screen` | 0 | 29.9s |  |
| 105 | `new_method_wrap` | 4 | 2.5s |  |
| 106 | `new_object_enumerate` | 7 | 2.5s |  |
| 107 | `new_object_wrap` | 4 | 2.5s |  |
| 108 | `o` | 3 | 2.5s |  |
| 109 | `object_constructor` | 33 | 2.6s |  |
| 110 | `object_function` | 32 | 2.6s |  |
| 111 | `object_string_coerce_swf5` | 62 | 2.7s |  |
| 112 | `primitive_instanceof` | 37 | 2.6s |  |
| 113 | `prototype_delete` | 12 | 2.6s |  |
| 114 | `recursive_prototypes` | 0 | 2.5s |  |
| 115 | `sandbox_type_local_network` | 1 | 2.6s |  |
| 116 | `set_variable_scope` | 58 | 2.8s |  |
| 117 | `single_frame` | 1 | 2.6s |  |
| 118 | `sound_start_load` | 0 | 2.7s |  |
| 119 | `stage_object_properties_get_var` | 5 | 2.6s |  |
| 120 | `strictequals_swf6` | 902 | 8.9s |  |
| 121 | `strictly_equals` | 7 | 2.6s |  |
| 122 | `string_coercion` | 117 | 3.3s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 123 | `string_paths_keyevents` | 0 | 2.6s |  |
| 124 | `string_paths_timer` | 0 | 2.6s |  |
| 125 | `swf4_actions_bool` | 96 | 2.8s |  |
| 126 | `swf4_bool` | 4 | 2.7s |  |
| 127 | `swf4_function_calls` | 7 | 2.8s |  |
| 128 | `swf5_encoding` | 3 | 2.6s |  |
| 129 | `swf7_case_sensitive` | 44 | 2.8s |  |
| 130 | `tab_ordering_properties_tab_index_edge_case` | 4 | 2.6s |  |
| 131 | `this_swf7` | 41 | 2.7s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 132 | `timeline_function_def` | 7 | 2.8s |  |
| 133 | `try_finally_simple` | 16 | 2.7s |  |
| 134 | `typeof_globals` | 7 | 2.6s |  |
| 135 | `undefined_to_string_swf6` | 4 | 2.6s |  |
| 136 | `unescape` | 43 | 2.8s |  |
| 137 | `waitforframe` | 7 | 2.6s |  |
| 138 | `waitforframe2` | 16 | 2.7s |  |
| 139 | `with_return` | 2 | 2.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**87 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `textfield_text` | 85.7% | 6 | 7 | 1 |  |
| 2 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 3 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 4 | `conflicting_instance_names` | 78.3% | 18 | 23 | 5 |  |
| 5 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 6 | `bitmap_data_max_size_swf10` | 75.0% | 9 | 12 | 3 |  |
| 7 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 8 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 9 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 10 | `textfield_background_color` | 72.7% | 8 | 11 | 3 |  |
| 11 | `textfield_border_color` | 72.7% | 8 | 11 | 3 |  |
| 12 | `textfield_properties` | 72.7% | 32 | 44 | 12 |  |
| 13 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 14 | `point` | 70.9% | 124 | 175 | 51 |  |
| 15 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 16 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 17 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 18 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 19 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 20 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 21 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 22 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 23 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 24 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 25 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 26 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 27 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 28 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 29 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 30 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 31 | `textfield_variable` | 66.7% | 54 | 81 | 27 |  |
| 32 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 33 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 34 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 35 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 36 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 37 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 38 | `slash_syntax` | 64.3% | 9 | 14 | 5 |  |
| 39 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 40 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 41 | `with` | 61.2% | 30 | 49 | 19 |  |
| 42 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 43 | `edittext_scroll` | 61.1% | 33 | 54 | 21 |  |
| 44 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 45 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 46 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 47 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 48 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 49 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 50 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 51 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 52 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 53 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 54 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 55 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 56 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 57 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 58 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 59 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 60 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 61 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 62 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 63 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 64 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 65 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 66 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 67 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 68 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 69 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 70 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 71 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 72 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 73 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 74 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 75 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 76 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 77 | `define_function2_preload_order` | 50.0% | 2 | 4 | 2 |  |
| 78 | `display_object_properties` | 50.0% | 1 | 2 | 1 |  |
| 79 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 80 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 81 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 82 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 83 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 84 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 85 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 86 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 87 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 13.0s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.8s |  |
| 3 | `path_string` | 4.4s |  |
| 4 | `swf4_actions_coercion_order` | 4.9s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.6s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.7s |  |

## Timeouts

**3 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.4s |  |
| 2 | `timeout` | runtime timeout (>10s) | 12.8s |  |
| 3 | `try_catch_finally` | runtime timeout (>10s) | 13.1s |  |

## All Output Mismatches

**471 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `textfield_text` | 85.7% | 6/7 | 7 | 7 |  |
| 2 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 3 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 4 | `conflicting_instance_names` | 78.3% | 18/23 | 23 | 23 |  |
| 5 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 6 | `bitmap_data_max_size_swf10` | 75.0% | 9/12 | 12 | 12 |  |
| 7 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 8 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 9 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 10 | `textfield_background_color` | 72.7% | 8/11 | 11 | 11 |  |
| 11 | `textfield_border_color` | 72.7% | 8/11 | 11 | 11 |  |
| 12 | `textfield_properties` | 72.7% | 32/44 | 44 | 44 |  |
| 13 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 14 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 15 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 16 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 17 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 18 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 19 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 20 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 21 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 22 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 23 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 24 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 25 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 26 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 27 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 28 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 29 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 30 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 31 | `textfield_variable` | 66.7% | 54/81 | 81 | 81 |  |
| 32 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 33 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 34 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 35 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 36 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 37 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 38 | `slash_syntax` | 64.3% | 9/14 | 14 | 14 |  |
| 39 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 40 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 41 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 42 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 43 | `edittext_scroll` | 61.1% | 33/54 | 54 | 54 |  |
| 44 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 45 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 46 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 47 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 48 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 49 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 50 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 51 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 52 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 53 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 54 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 55 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 56 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 57 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 58 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 59 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 60 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 61 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 62 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 63 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 64 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 65 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 66 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 67 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 68 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 69 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 70 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 71 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 72 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 73 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 74 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 75 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 76 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 77 | `define_function2_preload_order` | 50.0% | 2/4 | 2 | 4 |  |
| 78 | `display_object_properties` | 50.0% | 1/2 | 2 | 2 |  |
| 79 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 80 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 81 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 82 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 83 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 84 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 85 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 86 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 87 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 88 | `edittext_newline_stripping` | 49.2% | 32/65 | 65 | 64 |  |
| 89 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 90 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 91 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 92 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 93 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 94 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 95 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 96 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 97 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 98 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 99 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 100 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 101 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 102 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 103 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 104 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 105 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 106 | `edittext_html_swf6` | 37.5% | 2014/5377 | 5377 | 5377 |  |
| 107 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 108 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 109 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 110 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 111 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 112 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 113 | `frame_size_translated_negative` | 33.3% | 7/21 | 20 | 21 |  |
| 114 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 115 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 116 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 117 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 118 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 119 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 120 | `remove_movie_clip` | 31.0% | 9/29 | 17 | 29 |  |
| 121 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 122 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 123 | `edittext_html_condensewhite_swf7` | 29.9% | 93/311 | 311 | 311 |  |
| 124 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 125 | `edittext_html_condensewhite_swf8` | 28.9% | 90/311 | 311 | 311 |  |
| 126 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 127 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 128 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 129 | `edittext_html_swf7` | 25.6% | 1378/5377 | 5377 | 5377 |  |
| 130 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 131 | `edittext_html_swf8` | 25.3% | 1363/5377 | 5377 | 5377 |  |
| 132 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 133 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 134 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 135 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 136 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 137 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 138 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 139 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 140 | `stage_object_properties_swf6` | 23.4% | 54/231 | 165 | 231 |  |
| 141 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 142 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 143 | `stage_object_properties` | 22.4% | 54/241 | 175 | 241 |  |
| 144 | `funky_function_calls` | 21.4% | 12/56 | 32 | 56 |  |
| 145 | `textfield_props_swf5` | 21.1% | 37/175 | 139 | 175 |  |
| 146 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 147 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 148 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 149 | `target_clip_removed` | 20.0% | 1/5 | 5 | 5 |  |
| 150 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 151 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 152 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 153 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 154 | `textfield_props_swf6` | 17.6% | 37/210 | 140 | 210 |  |
| 155 | `textfield_props_swf7` | 17.1% | 36/210 | 140 | 210 |  |
| 156 | `textfield_props_swf8` | 17.1% | 36/210 | 140 | 210 |  |
| 157 | `focusrect_property_swf5` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 158 | `focusrect_property_swf6` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 159 | `focusrect_property_swf7` | 16.9% | 209/1237 | 1236 | 1237 |  |
| 160 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 161 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 162 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 163 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 164 | `edittext_tag_indent` | 16.1% | 5/31 | 31 | 31 |  |
| 165 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 166 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 167 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 168 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 169 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 170 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 171 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 172 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 173 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 174 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 175 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 176 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 177 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 178 | `register_and_init_order` | 13.0% | 30/231 | 54 | 231 |  |
| 179 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 180 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 181 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 182 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 183 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 184 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 185 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 186 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 187 | `swf5_no_closure` | 10.5% | 2/19 | 11 | 19 |  |
| 188 | `edittext_autosize_setter` | 10.0% | 2/20 | 20 | 20 |  |
| 189 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 190 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 191 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 192 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 193 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 194 | `execution_order4` | 8.3% | 1/12 | 7 | 12 |  |
| 195 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 196 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 197 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 198 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 199 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 200 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 201 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 202 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 203 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 204 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 205 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 206 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 207 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 208 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 209 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 210 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 211 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 212 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 213 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 214 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 215 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 216 | `bitmap_data` | 4.1% | 46/1126 | 318 | 1126 |  |
| 217 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 218 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 219 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 220 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 221 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 222 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 223 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 224 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 225 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 226 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 227 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 228 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 229 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 230 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 231 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 232 | `tab_ordering_properties` | 1.7% | 5/293 | 180 | 293 |  |
| 233 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 234 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 235 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 236 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 21 | 112 |  |
| 237 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 238 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 239 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 240 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 241 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 242 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 243 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 244 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 245 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 246 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 247 | `global_proto_decls` | 0.0% | 1/4497 | 20 | 4497 |  |
| 248 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 249 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 250 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 251 | `as2_oop` | 0.0% | 0/13 | 0 | 13 |  |
| 252 | `as2_super_and_this_v6` | 0.0% | 0/97 | 0 | 97 |  |
| 253 | `as2_super_and_this_v8` | 0.0% | 0/85 | 0 | 85 |  |
| 254 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 0 | 40 |  |
| 255 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 256 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 257 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 258 | `bitmap_data_copypixels` | 0.0% | 0/17 | 0 | 17 |  |
| 259 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 0 | 1075 |  |
| 260 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 261 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 262 | `button_children` | 0.0% | 0/8 | 0 | 8 |  |
| 263 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 264 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 265 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 266 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 267 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 268 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 269 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 270 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 271 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 272 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 273 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 274 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 275 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 276 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 277 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 278 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 279 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 280 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 281 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 282 | `color` | 0.0% | 0/57 | 0 | 57 |  |
| 283 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 284 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 285 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 286 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 287 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 288 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 289 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 290 | `duplicate_movie_clip` | 0.0% | 0/20 | 0 | 20 |  |
| 291 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 292 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 293 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 294 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 295 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 296 | `edittext_password` | 0.0% | 0/5 | 0 | 5 |  |
| 297 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 298 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 299 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 300 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 301 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 302 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 303 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 304 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 305 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 306 | `extends_chain` | 0.0% | 0/134 | 0 | 134 |  |
| 307 | `extends_native_type` | 0.0% | 0/11 | 0 | 11 |  |
| 308 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 309 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 310 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 311 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 312 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 313 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 314 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 315 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 316 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 317 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 318 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 319 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 320 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 321 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 322 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 323 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 324 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 325 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 326 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 327 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 328 | `global_proto_decls_delete` | 0.0% | 0/4158 | 14 | 4158 |  |
| 329 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 330 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 331 | `goto_frame` | 0.0% | 0/12 | 0 | 12 |  |
| 332 | `goto_frame2` | 0.0% | 0/44 | 0 | 44 |  |
| 333 | `goto_label` | 0.0% | 0/17 | 0 | 17 |  |
| 334 | `goto_methods` | 0.0% | 0/40 | 0 | 40 |  |
| 335 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 336 | `hittest_morph` | 0.0% | 0/70 | 0 | 70 |  |
| 337 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 338 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 339 | `init_object_order` | 0.0% | 0/15 | 0 | 15 |  |
| 340 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 341 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 342 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 343 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 344 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 345 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 346 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 347 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 348 | `issue_9885` | 0.0% | 0/2 | 0 | 2 |  |
| 349 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 350 | `loadmovie_fail` | 0.0% | 0/2 | 0 | 2 |  |
| 351 | `loadmovie_registerclass` | 0.0% | 0/30 | 0 | 30 |  |
| 352 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 353 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 0 | 9 |  |
| 354 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 355 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 356 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 357 | `localconnection` | 0.0% | 0/579 | 0 | 579 |  |
| 358 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 359 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 360 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 361 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 362 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 363 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 364 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 365 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 366 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 367 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 368 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 369 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 370 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 371 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 372 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 373 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 374 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 375 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 376 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 377 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 378 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 379 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 380 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 381 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 382 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 383 | `movieclip_init_object` | 0.0% | 0/5 | 0 | 5 |  |
| 384 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 385 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 386 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 387 | `native_objects_swf6` | 0.0% | 0/84 | 0 | 84 |  |
| 388 | `native_objects_swf7` | 0.0% | 0/84 | 0 | 84 |  |
| 389 | `native_objects_swf8` | 0.0% | 0/84 | 0 | 84 |  |
| 390 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 391 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 392 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 393 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 394 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 395 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 396 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 397 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 398 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 399 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 400 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 401 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 402 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 403 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 404 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 405 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 406 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 407 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 408 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 409 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 410 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 411 | `selection` | 0.0% | 0/454 | 0 | 454 |  |
| 412 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 413 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 414 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 415 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 416 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 417 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 418 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 419 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 420 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 421 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 422 | `stylesheet` | 0.0% | 0/283 | 0 | 283 |  |
| 423 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 424 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 425 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 426 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 427 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 428 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 429 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 430 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 431 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 432 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 433 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 434 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 435 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 436 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 437 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 438 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 439 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 440 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 441 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 442 | `target_path` | 0.0% | 0/14 | 0 | 14 |  |
| 443 | `tell_target_invalid` | 0.0% | 0/6 | 6 | 6 |  |
| 444 | `tell_target_invalid_swf6` | 0.0% | 0/6 | 6 | 5 |  |
| 445 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 446 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 447 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 448 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 449 | `timer_run_actions` | 0.0% | 0/18 | 0 | 18 |  |
| 450 | `typeof` | 0.0% | 0/22 | 0 | 22 |  |
| 451 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 452 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 453 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 454 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 455 | `variable_args` | 0.0% | 0/6 | 6 | 5 |  |
| 456 | `watch` | 0.0% | 0/117 | 0 | 117 |  |
| 457 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 458 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 459 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 460 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 461 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 462 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 463 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 464 | `xml_socket` | 0.0% | 0/8 | 0 | 8 |  |
| 465 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 466 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 467 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
| 468 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 469 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 470 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 471 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
