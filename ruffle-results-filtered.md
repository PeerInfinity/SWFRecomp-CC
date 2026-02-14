# Ruffle Test Results (Filtered)

**Date**: 2026-02-14 01:20 UTC

**Git SHA**: `03e795d08e`

**Run Duration**: 33m 44s

**Filtered**: 125 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 494 |
| Passing | **138** (27.9%) |
| Failing | 356 |
| Total expected lines | 78537 |
| Matching lines | 33067 (42.1%) |
| Mismatched lines | 45470 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 346 | 97.2% |
| Segfault | 5 | 1.4% |
| Timeout | 3 | 0.8% |
| Runtime Error | 2 | 0.6% |

## Passing Tests

**138 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.6s |  |
| 2 | `action_to_integer` | 28 | 2.6s |  |
| 3 | `add` | 28 | 2.7s |  |
| 4 | `add2` | 354 | 3.0s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.6s |  |
| 6 | `add_swf5` | 28 | 2.7s |  |
| 7 | `array_concat` | 98 | 2.8s |  |
| 8 | `array_constructor` | 30 | 2.7s |  |
| 9 | `array_length` | 42 | 2.8s |  |
| 10 | `array_properties` | 36 | 2.7s |  |
| 11 | `array_slice` | 34 | 2.7s |  |
| 12 | `array_splice` | 207 | 3.4s |  |
| 13 | `array_trivial` | 209 | 3.2s |  |
| 14 | `as1_constructor_v6` | 35 | 2.7s |  |
| 15 | `as1_constructor_v7` | 35 | 2.7s |  |
| 16 | `as_broadcaster_initialize` | 10 | 2.6s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 2.6s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 2.7s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 2.7s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 2.6s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 2.6s |  |
| 22 | `as_transformed_flag` | 20 | 2.7s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 2.5s |  |
| 24 | `bitand` | 1058 | 9.4s |  |
| 25 | `bitmap_data_colortransform` | 0 | 2.9s |  |
| 26 | `bitmap_data_fillrect` | 0 | 2.8s |  |
| 27 | `bitmap_data_perlinnoise` | 0 | 3.3s |  |
| 28 | `bitmap_data_pixeldissolve_image` | 0 | 3.1s |  |
| 29 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.7s |  |
| 30 | `bitor` | 1058 | 9.6s |  |
| 31 | `biturshift` | 14 | 2.9s |  |
| 32 | `biturshift_swf8` | 14 | 2.7s |  |
| 33 | `bitxor` | 1058 | 9.4s |  |
| 34 | `call_method_empty_name` | 1 | 2.7s |  |
| 35 | `catch_references_registers` | 2 | 2.7s |  |
| 36 | `define_function2` | 8 | 2.7s |  |
| 37 | `define_function2_preload` | 13 | 2.7s |  |
| 38 | `define_function2_preload_order` | 4 | 2.7s |  |
| 39 | `define_function_case_sensitive` | 2 | 2.7s |  |
| 40 | `delete` | 3 | 2.8s |  |
| 41 | `display_object_properties` | 2 | 2.6s |  |
| 42 | `divide_swf4` | 107 | 2.9s |  |
| 43 | `do_init_action` | 3 | 2.7s |  |
| 44 | `equals` | 32 | 2.8s |  |
| 45 | `equals2_swf5` | 926 | 11.0s |  |
| 46 | `equals2_swf6` | 926 | 10.9s |  |
| 47 | `equals2_swf7` | 926 | 11.0s |  |
| 48 | `equals_swf4` | 665 | 6.3s |  |
| 49 | `equals_swf4_alt` | 32 | 2.8s |  |
| 50 | `equals_swf5` | 32 | 2.8s |  |
| 51 | `error` | 58 | 2.9s |  |
| 52 | `escape` | 14 | 2.7s |  |
| 53 | `execution_order1` | 5 | 2.7s |  |
| 54 | `execution_order2` | 7 | 2.8s |  |
| 55 | `execution_order3` | 4 | 2.7s |  |
| 56 | `get_variable_in_scope` | 29 | 2.8s |  |
| 57 | `getproperty` | 28 | 2.7s |  |
| 58 | `getproperty_swf4` | 28 | 2.7s |  |
| 59 | `getproperty_swf5` | 28 | 2.7s |  |
| 60 | `global_array` | 3 | 2.6s |  |
| 61 | `global_is_bare` | 7 | 2.7s |  |
| 62 | `goto_advance1` | 6 | 2.7s |  |
| 63 | `goto_advance2` | 2 | 2.7s |  |
| 64 | `goto_both_ways1` | 3 | 3.0s |  |
| 65 | `goto_both_ways2` | 3 | 2.7s |  |
| 66 | `goto_execution_order` | 2 | 2.6s |  |
| 67 | `goto_execution_order2` | 2 | 2.7s |  |
| 68 | `goto_frame_number` | 3 | 2.8s |  |
| 69 | `goto_rewind1` | 1 | 2.8s |  |
| 70 | `goto_rewind2` | 3 | 2.8s |  |
| 71 | `goto_rewind3` | 2 | 2.7s |  |
| 72 | `greater_swf6` | 1175 | 11.7s |  |
| 73 | `greater_swf7` | 1175 | 11.8s |  |
| 74 | `greaterthan_swf5` | 1 | 2.7s |  |
| 75 | `greaterthan_swf8` | 1 | 2.7s |  |
| 76 | `has_own_property` | 32 | 2.8s |  |
| 77 | `infinite_recursion_function_in_setter` | 131 | 2.7s |  |
| 78 | `infinite_recursion_virtual_property` | 67 | 2.7s |  |
| 79 | `init_array_invalid` | 4 | 2.7s |  |
| 80 | `init_object_invalid` | 4 | 2.7s |  |
| 81 | `issue_1086` | 1 | 2.7s |  |
| 82 | `issue_1671` | 0 | 2.7s |  |
| 83 | `issue_3446` | 1 | 2.7s |  |
| 84 | `issue_4377` | 2 | 2.7s |  |
| 85 | `issue_710` | 4 | 2.8s |  |
| 86 | `issue_768` | 3 | 2.8s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 87 | `lessthan` | 41 | 2.8s |  |
| 88 | `lessthan2_swf5` | 1226 | 12.6s |  |
| 89 | `lessthan2_swf6` | 1226 | 12.5s |  |
| 90 | `lessthan2_swf7` | 1226 | 12.6s |  |
| 91 | `lessthan_swf4` | 902 | 8.3s |  |
| 92 | `lessthan_swf4_alt` | 41 | 2.9s |  |
| 93 | `lessthan_swf5` | 41 | 2.8s |  |
| 94 | `logical_ops_swf4` | 90 | 2.8s |  |
| 95 | `logical_ops_swf8` | 108 | 2.8s |  |
| 96 | `looping` | 6 | 2.7s |  |
| 97 | `mask_reapply` | 0 | 2.7s |  |
| 98 | `mask_with_drawing` | 0 | 2.7s |  |
| 99 | `movieclip_begin_gradient_fill` | 0 | 3.3s |  |
| 100 | `movieclip_line_gradient_style` | 0 | 3.3s |  |
| 101 | `movieclip_name_from_timeline` | 13 | 2.7s |  |
| 102 | `movieclip_prototype_extension` | 5 | 2.7s |  |
| 103 | `nested_textfields_in_buttons` | 0 | 2.7s |  |
| 104 | `new_method_wrap` | 4 | 2.7s |  |
| 105 | `new_object_enumerate` | 7 | 2.7s |  |
| 106 | `new_object_wrap` | 4 | 2.7s |  |
| 107 | `o` | 3 | 2.7s |  |
| 108 | `object_constructor` | 33 | 2.8s |  |
| 109 | `object_function` | 32 | 2.8s |  |
| 110 | `object_string_coerce_swf5` | 62 | 2.9s |  |
| 111 | `primitive_instanceof` | 37 | 2.8s |  |
| 112 | `prototype_delete` | 12 | 2.7s |  |
| 113 | `recursive_prototypes` | 0 | 2.7s |  |
| 114 | `sandbox_type_local_network` | 1 | 2.6s |  |
| 115 | `set_variable_scope` | 58 | 2.8s |  |
| 116 | `single_frame` | 1 | 2.6s |  |
| 117 | `stage_object_properties_get_var` | 5 | 2.6s |  |
| 118 | `strictequals_swf6` | 902 | 8.8s |  |
| 119 | `strictly_equals` | 7 | 2.7s |  |
| 120 | `string_coercion` | 117 | 3.3s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 121 | `string_paths_keyevents` | 0 | 2.7s |  |
| 122 | `string_paths_timer` | 0 | 2.7s |  |
| 123 | `swf4_actions_bool` | 96 | 2.8s |  |
| 124 | `swf4_bool` | 4 | 2.7s |  |
| 125 | `swf4_function_calls` | 7 | 2.8s |  |
| 126 | `swf5_encoding` | 3 | 2.6s |  |
| 127 | `swf7_case_sensitive` | 44 | 2.7s |  |
| 128 | `this_swf7` | 41 | 2.6s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 129 | `timeline_function_def` | 7 | 2.7s |  |
| 130 | `try_finally_simple` | 16 | 2.7s |  |
| 131 | `typeof` | 22 | 2.7s |  |
| 132 | `typeof_globals` | 7 | 2.6s |  |
| 133 | `undefined_to_string_swf6` | 4 | 2.6s |  |
| 134 | `unescape` | 43 | 2.8s |  |
| 135 | `variable_args` | 5 | 2.8s |  |
| 136 | `waitforframe` | 7 | 2.7s |  |
| 137 | `waitforframe2` | 16 | 2.7s |  |
| 138 | `with_return` | 2 | 2.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**81 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `conflicting_instance_names` | 91.3% | 21 | 23 | 2 |  |
| 2 | `textfield_text` | 85.7% | 6 | 7 | 1 |  |
| 3 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 4 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 5 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 6 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 7 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 8 | `use_hand_cursor` | 75.0% | 6 | 8 | 2 |  |
| 9 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 10 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 11 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 12 | `textfield_background_color` | 72.7% | 8 | 11 | 3 |  |
| 13 | `textfield_border_color` | 72.7% | 8 | 11 | 3 |  |
| 14 | `textfield_properties` | 72.7% | 32 | 44 | 12 |  |
| 15 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 16 | `point` | 70.9% | 124 | 175 | 51 |  |
| 17 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 18 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 19 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 20 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 21 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 22 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 23 | `stage_object_properties` | 68.5% | 165 | 241 | 76 |  |
| 24 | `stage_object_properties_swf6` | 68.4% | 158 | 231 | 73 |  |
| 25 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 26 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 27 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 28 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 29 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 30 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 31 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 32 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 33 | `textfield_variable` | 66.7% | 54 | 81 | 27 |  |
| 34 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 35 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 36 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 37 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 38 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
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
| 51 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 52 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 53 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 54 | `remove_movie_clip` | 58.6% | 17 | 29 | 12 |  |
| 55 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 56 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 57 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 58 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 59 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 60 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 61 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 62 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 63 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 64 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 65 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 66 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 67 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 68 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 69 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 70 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 71 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 72 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 73 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 74 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 75 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 76 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 77 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 78 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 79 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 80 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 81 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 12.8s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.7s |  |
| 3 | `goto_methods` | 5.3s |  |
| 4 | `path_string` | 5.2s |  |
| 5 | `swf4_actions_coercion_order` | 5.0s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.6s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.6s |  |

## Timeouts

**3 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.8s |  |
| 2 | `timeout` | runtime timeout (>10s) | 14.2s |  |
| 3 | `try_catch_finally` | runtime timeout (>10s) | 13.2s |  |

## All Output Mismatches

**346 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `conflicting_instance_names` | 91.3% | 21/23 | 23 | 23 |  |
| 2 | `textfield_text` | 85.7% | 6/7 | 7 | 7 |  |
| 3 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 4 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 5 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 6 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 7 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 8 | `use_hand_cursor` | 75.0% | 6/8 | 8 | 8 |  |
| 9 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 10 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 11 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 12 | `textfield_background_color` | 72.7% | 8/11 | 11 | 11 |  |
| 13 | `textfield_border_color` | 72.7% | 8/11 | 11 | 11 |  |
| 14 | `textfield_properties` | 72.7% | 32/44 | 44 | 44 |  |
| 15 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 16 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 17 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 18 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 19 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 20 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 21 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 22 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 23 | `stage_object_properties` | 68.5% | 165/241 | 241 | 241 |  |
| 24 | `stage_object_properties_swf6` | 68.4% | 158/231 | 231 | 231 |  |
| 25 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 26 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 27 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 28 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 29 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 30 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 31 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 32 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 33 | `textfield_variable` | 66.7% | 54/81 | 81 | 81 |  |
| 34 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 35 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 36 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 37 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 38 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
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
| 51 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 52 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 53 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 54 | `remove_movie_clip` | 58.6% | 17/29 | 29 | 29 |  |
| 55 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 56 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 57 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 58 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 59 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 60 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 61 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 62 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 63 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 64 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 65 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 66 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 67 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 68 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 69 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 70 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 71 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 72 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 73 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 74 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 75 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 76 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 77 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 78 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 79 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 80 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 81 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 82 | `edittext_newline_stripping` | 49.2% | 32/65 | 65 | 64 |  |
| 83 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 84 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 85 | `frame_size_translated_negative` | 47.6% | 10/21 | 20 | 21 |  |
| 86 | `frame_size_translated_positive` | 47.6% | 10/21 | 20 | 21 |  |
| 87 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 88 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 89 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 90 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 91 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 92 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 93 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 94 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 95 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 96 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 97 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 98 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 99 | `as2_oop` | 38.5% | 5/13 | 10 | 13 |  |
| 100 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 101 | `edittext_html_swf6` | 37.5% | 2014/5377 | 5377 | 5377 |  |
| 102 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 103 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 104 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 105 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 106 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 107 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 108 | `init_object_order` | 33.3% | 5/15 | 5 | 15 |  |
| 109 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 110 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 111 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 112 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 113 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 114 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 115 | `edittext_html_condensewhite_swf7` | 29.9% | 93/311 | 311 | 311 |  |
| 116 | `edittext_html_condensewhite_swf8` | 28.9% | 90/311 | 311 | 311 |  |
| 117 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 118 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 119 | `edittext_html_swf7` | 25.6% | 1378/5377 | 5377 | 5377 |  |
| 120 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 121 | `edittext_html_swf8` | 25.3% | 1363/5377 | 5377 | 5377 |  |
| 122 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 123 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 124 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 125 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 126 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 127 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 128 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 129 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 130 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 131 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 132 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 133 | `textfield_props_swf5` | 21.1% | 37/175 | 139 | 175 |  |
| 134 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 135 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 136 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 137 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 138 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 139 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 140 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 141 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 142 | `textfield_props_swf6` | 17.6% | 37/210 | 140 | 210 |  |
| 143 | `textfield_props_swf7` | 17.1% | 36/210 | 140 | 210 |  |
| 144 | `textfield_props_swf8` | 17.1% | 36/210 | 140 | 210 |  |
| 145 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 146 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 147 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 148 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 149 | `edittext_tag_indent` | 16.1% | 5/31 | 31 | 31 |  |
| 150 | `watch` | 15.4% | 18/117 | 100 | 117 |  |
| 151 | `as2_super_via_manual_prototype` | 15.0% | 6/40 | 16 | 40 |  |
| 152 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 153 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 154 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 155 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 156 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 157 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 158 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 159 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 160 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 161 | `movieclip_hittest_shapeflag` | 14.2% | 48/338 | 338 | 338 |  |
| 162 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 163 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 164 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 165 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 166 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 |  |
| 167 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 168 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 169 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 170 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 171 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 172 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 173 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 174 | `extends_chain` | 11.2% | 15/134 | 114 | 134 |  |
| 175 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 176 | `swf5_no_closure` | 10.5% | 2/19 | 11 | 19 |  |
| 177 | `edittext_autosize_setter` | 10.0% | 2/20 | 20 | 20 |  |
| 178 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 179 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 180 | `unload` | 9.6% | 5/52 | 48 | 52 |  |
| 181 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 182 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 183 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 184 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 185 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 186 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 187 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 188 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 189 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 190 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 191 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 192 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 193 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 194 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 195 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 196 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 197 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 198 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 199 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 200 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 201 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 202 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 203 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 204 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 205 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 206 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 207 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 208 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 209 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 210 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 211 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 212 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 213 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 214 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 215 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 216 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 217 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 218 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 219 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 220 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 221 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 222 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 223 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 224 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 225 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 226 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 227 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 228 | `global_proto_decls` | 0.0% | 1/4497 | 20 | 4497 |  |
| 229 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 230 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 231 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 232 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 233 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 234 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 235 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 236 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 237 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 238 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 239 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 240 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 241 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 242 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 243 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 244 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 245 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 246 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 247 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 248 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 249 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 250 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 251 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 252 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 253 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 254 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 255 | `extends_native_type` | 0.0% | 0/11 | 4 | 11 |  |
| 256 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 257 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 258 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 259 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 260 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 261 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 262 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 263 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 264 | `global_proto_decls_delete` | 0.0% | 0/4158 | 14 | 4158 |  |
| 265 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 266 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 267 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 268 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 269 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 270 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 271 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 272 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 273 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 274 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 275 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 276 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 277 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 278 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 279 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 280 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 281 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 282 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 283 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 284 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 285 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 286 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 287 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 288 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 289 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 290 | `native_objects_swf6` | 0.0% | 0/181 | 181 | 84 |  |
| 291 | `native_objects_swf7` | 0.0% | 0/181 | 181 | 84 |  |
| 292 | `native_objects_swf8` | 0.0% | 0/181 | 181 | 84 |  |
| 293 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 294 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 295 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 296 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 297 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 298 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 299 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 300 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 301 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 302 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 303 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 304 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 305 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 306 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 307 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 308 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 309 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 310 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 311 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 312 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 313 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 314 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 315 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 316 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 317 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 318 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 319 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 320 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 321 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 322 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 323 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 324 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 325 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 326 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 327 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 328 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 329 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 330 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 331 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 332 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 333 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 334 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 335 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 336 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 337 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 338 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 339 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 340 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 341 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 342 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 343 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 344 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 345 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 346 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
