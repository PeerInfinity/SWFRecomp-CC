# Ruffle Test Results (Filtered)

**Date**: 2026-02-13 23:54 UTC

**Git SHA**: `74ae275df6`

**Run Duration**: 36m 16s

**Filtered**: 125 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 494 |
| Passing | **134** (27.1%) |
| Failing | 360 |
| Total expected lines | 76426 |
| Matching lines | 27315 (35.7%) |
| Mismatched lines | 49111 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 306 | 85.0% |
| Segfault | 49 | 13.6% |
| Timeout | 3 | 0.8% |
| Runtime Error | 2 | 0.6% |

## Passing Tests

**134 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.9s |  |
| 2 | `action_to_integer` | 28 | 2.7s |  |
| 3 | `add` | 28 | 2.9s |  |
| 4 | `add2` | 354 | 3.1s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.8s |  |
| 6 | `add_swf5` | 28 | 2.8s |  |
| 7 | `array_concat` | 98 | 2.9s |  |
| 8 | `array_constructor` | 30 | 2.8s |  |
| 9 | `array_length` | 42 | 2.9s |  |
| 10 | `array_properties` | 36 | 2.8s |  |
| 11 | `array_slice` | 34 | 2.9s |  |
| 12 | `array_splice` | 207 | 3.5s |  |
| 13 | `array_trivial` | 209 | 3.3s |  |
| 14 | `as1_constructor_v6` | 35 | 2.8s |  |
| 15 | `as1_constructor_v7` | 35 | 2.8s |  |
| 16 | `as_broadcaster_initialize` | 10 | 2.7s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 2.8s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 2.7s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 2.7s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 2.7s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 2.7s |  |
| 22 | `bad_swf_tag_past_eof` | 0 | 2.6s |  |
| 23 | `bitand` | 1058 | 9.6s |  |
| 24 | `bitmap_data_colortransform` | 0 | 3.0s |  |
| 25 | `bitmap_data_fillrect` | 0 | 2.9s |  |
| 26 | `bitmap_data_perlinnoise` | 0 | 3.4s |  |
| 27 | `bitmap_data_pixeldissolve_image` | 0 | 3.2s |  |
| 28 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.7s |  |
| 29 | `bitor` | 1058 | 9.6s |  |
| 30 | `biturshift` | 14 | 3.0s |  |
| 31 | `biturshift_swf8` | 14 | 2.8s |  |
| 32 | `bitxor` | 1058 | 9.3s |  |
| 33 | `call_method_empty_name` | 1 | 2.7s |  |
| 34 | `catch_references_registers` | 2 | 2.7s |  |
| 35 | `define_function2` | 8 | 2.7s |  |
| 36 | `define_function2_preload` | 13 | 2.7s |  |
| 37 | `define_function2_preload_order` | 4 | 2.7s |  |
| 38 | `define_function_case_sensitive` | 2 | 2.7s |  |
| 39 | `delete` | 3 | 2.8s |  |
| 40 | `display_object_properties` | 2 | 2.7s |  |
| 41 | `divide_swf4` | 107 | 2.9s |  |
| 42 | `do_init_action` | 3 | 2.8s |  |
| 43 | `equals` | 32 | 2.8s |  |
| 44 | `equals2_swf5` | 926 | 11.0s |  |
| 45 | `equals2_swf6` | 926 | 11.1s |  |
| 46 | `equals2_swf7` | 926 | 11.0s |  |
| 47 | `equals_swf4` | 665 | 6.3s |  |
| 48 | `equals_swf4_alt` | 32 | 2.8s |  |
| 49 | `equals_swf5` | 32 | 2.8s |  |
| 50 | `error` | 58 | 2.9s |  |
| 51 | `escape` | 14 | 2.7s |  |
| 52 | `execution_order1` | 5 | 2.7s |  |
| 53 | `execution_order3` | 4 | 2.7s |  |
| 54 | `get_variable_in_scope` | 29 | 2.8s |  |
| 55 | `getproperty` | 28 | 2.7s |  |
| 56 | `getproperty_swf4` | 28 | 2.7s |  |
| 57 | `getproperty_swf5` | 28 | 2.7s |  |
| 58 | `global_array` | 3 | 2.7s |  |
| 59 | `global_is_bare` | 7 | 2.7s |  |
| 60 | `goto_advance1` | 6 | 2.7s |  |
| 61 | `goto_both_ways1` | 3 | 3.0s |  |
| 62 | `goto_both_ways2` | 3 | 2.8s |  |
| 63 | `goto_execution_order` | 2 | 2.7s |  |
| 64 | `goto_execution_order2` | 2 | 2.7s |  |
| 65 | `goto_frame_number` | 3 | 2.8s |  |
| 66 | `goto_rewind1` | 1 | 2.8s |  |
| 67 | `goto_rewind3` | 2 | 2.7s |  |
| 68 | `greater_swf6` | 1175 | 11.8s |  |
| 69 | `greater_swf7` | 1175 | 11.8s |  |
| 70 | `greaterthan_swf5` | 1 | 2.7s |  |
| 71 | `greaterthan_swf8` | 1 | 2.7s |  |
| 72 | `has_own_property` | 32 | 2.8s |  |
| 73 | `infinite_recursion_function_in_setter` | 131 | 2.7s |  |
| 74 | `infinite_recursion_virtual_property` | 67 | 2.7s |  |
| 75 | `init_array_invalid` | 4 | 2.7s |  |
| 76 | `init_object_invalid` | 4 | 2.7s |  |
| 77 | `issue_1086` | 1 | 2.7s |  |
| 78 | `issue_1671` | 0 | 2.7s |  |
| 79 | `issue_3446` | 1 | 2.7s |  |
| 80 | `issue_4377` | 2 | 2.8s |  |
| 81 | `issue_710` | 4 | 2.7s |  |
| 82 | `issue_768` | 3 | 2.7s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 83 | `lessthan` | 41 | 2.8s |  |
| 84 | `lessthan2_swf5` | 1226 | 12.4s |  |
| 85 | `lessthan2_swf6` | 1226 | 12.3s |  |
| 86 | `lessthan2_swf7` | 1226 | 12.3s |  |
| 87 | `lessthan_swf4` | 902 | 8.1s |  |
| 88 | `lessthan_swf4_alt` | 41 | 2.8s |  |
| 89 | `lessthan_swf5` | 41 | 2.8s |  |
| 90 | `logical_ops_swf4` | 90 | 2.9s |  |
| 91 | `logical_ops_swf8` | 108 | 2.9s |  |
| 92 | `looping` | 6 | 2.7s |  |
| 93 | `mask_reapply` | 0 | 2.7s |  |
| 94 | `mask_with_drawing` | 0 | 2.8s |  |
| 95 | `movieclip_begin_gradient_fill` | 0 | 3.5s |  |
| 96 | `movieclip_line_gradient_style` | 0 | 3.3s |  |
| 97 | `movieclip_name_from_timeline` | 13 | 2.7s |  |
| 98 | `movieclip_prototype_extension` | 5 | 2.7s |  |
| 99 | `nested_textfields_in_buttons` | 0 | 2.6s |  |
| 100 | `new_method_wrap` | 4 | 2.7s |  |
| 101 | `new_object_enumerate` | 7 | 2.7s |  |
| 102 | `new_object_wrap` | 4 | 2.6s |  |
| 103 | `o` | 3 | 2.6s |  |
| 104 | `object_constructor` | 33 | 2.8s |  |
| 105 | `object_function` | 32 | 2.8s |  |
| 106 | `object_string_coerce_swf5` | 62 | 2.9s |  |
| 107 | `primitive_instanceof` | 37 | 2.8s |  |
| 108 | `prototype_delete` | 12 | 2.8s |  |
| 109 | `recursive_prototypes` | 0 | 2.6s |  |
| 110 | `sandbox_type_local_network` | 1 | 2.7s |  |
| 111 | `set_variable_scope` | 58 | 2.8s |  |
| 112 | `single_frame` | 1 | 2.6s |  |
| 113 | `stage_object_properties_get_var` | 5 | 2.8s |  |
| 114 | `strictequals_swf6` | 902 | 9.0s |  |
| 115 | `strictly_equals` | 7 | 2.8s |  |
| 116 | `string_coercion` | 117 | 3.4s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 117 | `string_paths_keyevents` | 0 | 2.8s |  |
| 118 | `string_paths_timer` | 0 | 2.7s |  |
| 119 | `swf4_actions_bool` | 96 | 2.9s |  |
| 120 | `swf4_bool` | 4 | 2.8s |  |
| 121 | `swf4_function_calls` | 7 | 2.9s |  |
| 122 | `swf5_encoding` | 3 | 2.7s |  |
| 123 | `swf7_case_sensitive` | 44 | 2.9s |  |
| 124 | `this_swf7` | 41 | 2.8s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 125 | `timeline_function_def` | 7 | 2.8s |  |
| 126 | `try_finally_simple` | 16 | 2.8s |  |
| 127 | `typeof` | 22 | 2.8s |  |
| 128 | `typeof_globals` | 7 | 2.8s |  |
| 129 | `undefined_to_string_swf6` | 4 | 2.8s |  |
| 130 | `unescape` | 43 | 2.9s |  |
| 131 | `variable_args` | 5 | 3.0s |  |
| 132 | `waitforframe` | 7 | 3.0s |  |
| 133 | `waitforframe2` | 16 | 2.8s |  |
| 134 | `with_return` | 2 | 2.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**63 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `as_transformed_flag` | 90.0% | 18 | 20 | 2 |  |
| 2 | `conflicting_instance_names` | 87.0% | 20 | 23 | 3 |  |
| 3 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 4 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 5 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 6 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 7 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 8 | `goto_rewind2` | 75.0% | 3 | 4 | 1 |  |
| 9 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 10 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 11 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 12 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 13 | `point` | 70.9% | 124 | 175 | 51 |  |
| 14 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 15 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 16 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 17 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 18 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 19 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 20 | `stage_object_properties` | 68.5% | 165 | 241 | 76 |  |
| 21 | `stage_object_properties_swf6` | 68.4% | 158 | 231 | 73 |  |
| 22 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 23 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 24 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 25 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 26 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 27 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 28 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 29 | `goto_advance2` | 66.7% | 2 | 3 | 1 |  |
| 30 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 31 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 32 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 33 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 34 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 35 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 36 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 37 | `with` | 61.2% | 30 | 49 | 19 |  |
| 38 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 39 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 40 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 41 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 42 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 43 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 44 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 45 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 46 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 47 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 48 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 49 | `execution_order2` | 55.6% | 5 | 9 | 4 |  |
| 50 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 51 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 52 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 53 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 54 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 55 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 56 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 57 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 58 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 59 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 60 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 61 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 62 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 63 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**49 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `button_children` | 4.8s |  |
| 2 | `clone_sprite_edittext` | 5.7s |  |
| 3 | `clone_sprite_types` | 4.7s |  |
| 4 | `device_font_spacing` | 5.0s |  |
| 5 | `duplicate_movie_clip_drawing` | 4.7s |  |
| 6 | `edittext_align` | 5.1s |  |
| 7 | `edittext_autosize` | 5.2s |  |
| 8 | `edittext_autosize_setter` | 4.8s |  |
| 9 | `edittext_bullet` | 5.2s |  |
| 10 | `edittext_default_format` | 5.0s |  |
| 11 | `edittext_default_format_empty` | 5.0s |  |
| 12 | `edittext_default_format_font_style` | 4.9s |  |
| 13 | `edittext_font_size` | 5.0s |  |
| 14 | `edittext_html_align_swf7` | 5.1s |  |
| 15 | `edittext_html_align_swf8` | 5.2s |  |
| 16 | `edittext_html_condensewhite_swf7` | 5.0s |  |
| 17 | `edittext_html_condensewhite_swf8` | 5.1s |  |
| 18 | `edittext_html_entity` | 4.9s |  |
| 19 | `edittext_html_swf6` | 6.6s |  |
| 20 | `edittext_html_swf7` | 6.7s |  |
| 21 | `edittext_html_swf8` | 6.7s |  |
| 22 | `edittext_leading` | 4.9s |  |
| 23 | `edittext_letter_spacing` | 4.9s |  |
| 24 | `edittext_margins` | 4.9s |  |
| 25 | `edittext_newline_stripping` | 9.6s |  |
| 26 | `edittext_newlines` | 5.1s |  |
| 27 | `edittext_programmatic_focus` | 4.7s |  |
| 28 | `edittext_scroll` | 4.9s |  |
| 29 | `edittext_tag_indent` | 4.8s |  |
| 30 | `edittext_underline` | 5.0s |  |
| 31 | `edittext_width_height` | 5.0s |  |
| 32 | `goto_methods` | 5.3s |  |
| 33 | `input_dead_keys_windows` | 4.9s |  |
| 34 | `issue_3522` | 4.7s |  |
| 35 | `native_objects_swf6` | 5.6s |  |
| 36 | `native_objects_swf7` | 5.7s |  |
| 37 | `native_objects_swf8` | 5.8s |  |
| 38 | `path_string` | 5.1s |  |
| 39 | `remove_movie_clip` | 5.1s |  |
| 40 | `selection` | 5.1s |  |
| 41 | `selection_handlers` | 4.9s |  |
| 42 | `string_paths_hidden` | 4.8s |  |
| 43 | `swf4_actions_coercion_order` | 5.0s |  |
| 44 | `textfield_background_color` | 4.7s |  |
| 45 | `textfield_border_color` | 4.7s |  |
| 46 | `textfield_properties` | 4.9s |  |
| 47 | `textfield_text` | 4.7s |  |
| 48 | `textfield_variable` | 5.2s |  |
| 49 | `use_hand_cursor` | 4.8s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.8s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.8s |  |

## Timeouts

**3 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.8s |  |
| 2 | `timeout` | runtime timeout (>10s) | 13.0s |  |
| 3 | `try_catch_finally` | runtime timeout (>10s) | 13.2s |  |

## All Output Mismatches

**306 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `as_transformed_flag` | 90.0% | 18/20 | 20 | 20 |  |
| 2 | `conflicting_instance_names` | 87.0% | 20/23 | 23 | 23 |  |
| 3 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 4 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 5 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 6 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 7 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 8 | `goto_rewind2` | 75.0% | 3/4 | 4 | 3 |  |
| 9 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 10 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 11 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 12 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 13 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 14 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 15 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 16 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 17 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 18 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 19 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 20 | `stage_object_properties` | 68.5% | 165/241 | 241 | 241 |  |
| 21 | `stage_object_properties_swf6` | 68.4% | 158/231 | 231 | 231 |  |
| 22 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 23 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 24 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 25 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 26 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 27 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 28 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 29 | `goto_advance2` | 66.7% | 2/3 | 3 | 2 |  |
| 30 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 31 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 32 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 33 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 34 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 35 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 36 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 37 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 38 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 39 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 40 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 41 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 42 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 43 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 44 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 45 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 46 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 47 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 48 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 49 | `execution_order2` | 55.6% | 5/9 | 9 | 7 |  |
| 50 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 51 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 52 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 53 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 54 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 55 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 56 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 57 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 58 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 59 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 60 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 61 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 62 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 63 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 64 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 65 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 66 | `frame_size_translated_negative` | 47.6% | 10/21 | 20 | 21 |  |
| 67 | `frame_size_translated_positive` | 47.6% | 10/21 | 20 | 21 |  |
| 68 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 69 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 70 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 71 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 72 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 73 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 74 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 75 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 76 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 77 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 78 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 79 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 80 | `as2_oop` | 38.5% | 5/13 | 10 | 13 |  |
| 81 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 82 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 83 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 84 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 85 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 86 | `init_object_order` | 33.3% | 5/15 | 5 | 15 |  |
| 87 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 88 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 89 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 90 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 91 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 92 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 93 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 94 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 95 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 96 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 97 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 98 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 99 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 100 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 101 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 102 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 103 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 104 | `textfield_props_swf5` | 21.1% | 37/175 | 139 | 175 |  |
| 105 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 106 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 107 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 108 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 109 | `default_names` | 19.2% | 10/52 | 34 | 52 |  |
| 110 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 111 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 112 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 113 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 114 | `textfield_props_swf6` | 17.6% | 37/210 | 140 | 210 |  |
| 115 | `textfield_props_swf7` | 17.1% | 36/210 | 140 | 210 |  |
| 116 | `textfield_props_swf8` | 17.1% | 36/210 | 140 | 210 |  |
| 117 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 118 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 119 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 120 | `watch` | 15.4% | 18/117 | 100 | 117 |  |
| 121 | `as2_super_via_manual_prototype` | 15.0% | 6/40 | 16 | 40 |  |
| 122 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 123 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 124 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 125 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 126 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 127 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 128 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 129 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 130 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 131 | `movieclip_hittest_shapeflag` | 14.2% | 48/338 | 338 | 338 |  |
| 132 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 133 | `register_and_init_order` | 13.4% | 31/231 | 73 | 231 |  |
| 134 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 135 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 136 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 137 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 138 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 139 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 140 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 141 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 142 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 143 | `extends_chain` | 11.2% | 15/134 | 114 | 134 |  |
| 144 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 145 | `swf5_no_closure` | 10.5% | 2/19 | 11 | 19 |  |
| 146 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 147 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 148 | `unload` | 9.6% | 5/52 | 48 | 52 |  |
| 149 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 150 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 151 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 152 | `execution_order4` | 8.3% | 1/12 | 9 | 12 |  |
| 153 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 154 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 155 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 156 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 157 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 158 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 159 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 160 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 161 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 162 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 163 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 164 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 165 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 166 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 167 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 168 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 169 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 170 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 171 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 172 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 173 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 174 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 175 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 176 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 177 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 178 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 179 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 180 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 181 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 182 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 183 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 184 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 185 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 186 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 187 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 188 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 189 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 190 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 191 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 192 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 193 | `global_proto_decls` | 0.0% | 1/4497 | 20 | 4497 |  |
| 194 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 195 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 196 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 197 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 198 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 199 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 200 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 201 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 202 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 203 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 204 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 205 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 206 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 207 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 208 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 209 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 210 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 211 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 212 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 213 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 214 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 215 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 216 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 217 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 218 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 219 | `extends_native_type` | 0.0% | 0/11 | 4 | 11 |  |
| 220 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 221 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 222 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 223 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 224 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 225 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 226 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 227 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 228 | `global_proto_decls_delete` | 0.0% | 0/4158 | 14 | 4158 |  |
| 229 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 230 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 231 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 232 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 233 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 234 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 235 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 236 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 237 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 238 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 239 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 240 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 241 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 242 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 243 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 244 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 245 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 246 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 247 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 248 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 249 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 250 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 251 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 252 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 253 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 254 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 255 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 256 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 257 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 258 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 259 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 260 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 261 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 262 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 263 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 264 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 265 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 266 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 267 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 268 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 269 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 270 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 271 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 272 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 273 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 274 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 275 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 276 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 277 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 278 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 279 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 280 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 281 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 282 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 283 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 284 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 285 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 286 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 287 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 288 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 289 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 290 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 291 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 292 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 293 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 294 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 295 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 296 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 297 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 298 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 299 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 300 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 301 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 302 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 303 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 304 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 305 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 306 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
