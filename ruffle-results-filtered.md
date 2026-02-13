# Ruffle Test Results (Filtered)

**Date**: 2026-02-13 20:32 UTC

**Git SHA**: `51824ed311`

**Run Duration**: 33m 25s

**Filtered**: 125 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 494 |
| Passing | **130** (26.3%) |
| Failing | 364 |
| Total expected lines | 78537 |
| Matching lines | 32588 (41.5%) |
| Mismatched lines | 45949 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 355 | 97.5% |
| Segfault | 4 | 1.1% |
| Timeout | 3 | 0.8% |
| Runtime Error | 2 | 0.5% |

## Passing Tests

**130 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.7s |  |
| 2 | `action_to_integer` | 28 | 2.7s |  |
| 3 | `add` | 28 | 2.7s |  |
| 4 | `add2` | 354 | 3.1s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.7s |  |
| 6 | `add_swf5` | 28 | 2.7s |  |
| 7 | `array_concat` | 98 | 2.8s |  |
| 8 | `array_constructor` | 30 | 2.8s |  |
| 9 | `array_length` | 42 | 2.8s |  |
| 10 | `array_properties` | 36 | 2.7s |  |
| 11 | `array_slice` | 34 | 2.8s |  |
| 12 | `array_splice` | 207 | 3.4s |  |
| 13 | `array_trivial` | 209 | 3.2s |  |
| 14 | `as1_constructor_v6` | 35 | 2.8s |  |
| 15 | `as1_constructor_v7` | 35 | 2.8s |  |
| 16 | `as_broadcaster_initialize` | 10 | 2.6s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 2.7s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 2.6s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 2.6s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 2.6s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 2.7s |  |
| 22 | `bad_swf_tag_past_eof` | 0 | 2.5s |  |
| 23 | `bitand` | 1058 | 9.2s |  |
| 24 | `bitmap_data_colortransform` | 0 | 2.9s |  |
| 25 | `bitmap_data_fillrect` | 0 | 2.8s |  |
| 26 | `bitmap_data_perlinnoise` | 0 | 3.4s |  |
| 27 | `bitmap_data_pixeldissolve_image` | 0 | 3.1s |  |
| 28 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.6s |  |
| 29 | `bitor` | 1058 | 9.2s |  |
| 30 | `biturshift` | 14 | 3.2s |  |
| 31 | `biturshift_swf8` | 14 | 2.7s |  |
| 32 | `bitxor` | 1058 | 10.1s |  |
| 33 | `call_method_empty_name` | 1 | 2.7s |  |
| 34 | `catch_references_registers` | 2 | 2.7s |  |
| 35 | `define_function2` | 8 | 2.7s |  |
| 36 | `define_function2_preload` | 13 | 2.7s |  |
| 37 | `define_function_case_sensitive` | 2 | 2.7s |  |
| 38 | `delete` | 3 | 2.8s |  |
| 39 | `divide_swf4` | 107 | 2.9s |  |
| 40 | `do_init_action` | 3 | 2.7s |  |
| 41 | `equals` | 32 | 2.7s |  |
| 42 | `equals2_swf5` | 926 | 11.8s |  |
| 43 | `equals2_swf6` | 926 | 11.8s |  |
| 44 | `equals2_swf7` | 926 | 11.9s |  |
| 45 | `equals_swf4` | 665 | 6.3s |  |
| 46 | `equals_swf4_alt` | 32 | 2.7s |  |
| 47 | `equals_swf5` | 32 | 2.7s |  |
| 48 | `error` | 58 | 2.8s |  |
| 49 | `escape` | 14 | 2.6s |  |
| 50 | `execution_order3` | 4 | 2.6s |  |
| 51 | `get_variable_in_scope` | 29 | 2.8s |  |
| 52 | `getproperty` | 28 | 2.7s |  |
| 53 | `getproperty_swf4` | 28 | 2.7s |  |
| 54 | `getproperty_swf5` | 28 | 2.7s |  |
| 55 | `global_array` | 3 | 2.6s |  |
| 56 | `global_is_bare` | 7 | 2.6s |  |
| 57 | `goto_advance2` | 2 | 2.6s |  |
| 58 | `goto_both_ways1` | 3 | 2.8s |  |
| 59 | `goto_both_ways2` | 3 | 2.6s |  |
| 60 | `goto_execution_order` | 2 | 2.6s |  |
| 61 | `goto_execution_order2` | 2 | 2.6s |  |
| 62 | `goto_frame_number` | 3 | 2.7s |  |
| 63 | `goto_rewind1` | 1 | 2.6s |  |
| 64 | `goto_rewind2` | 3 | 2.6s |  |
| 65 | `goto_rewind3` | 2 | 2.6s |  |
| 66 | `greater_swf6` | 1175 | 11.6s |  |
| 67 | `greater_swf7` | 1175 | 11.6s |  |
| 68 | `greaterthan_swf5` | 1 | 2.6s |  |
| 69 | `greaterthan_swf8` | 1 | 2.6s |  |
| 70 | `has_own_property` | 32 | 2.7s |  |
| 71 | `infinite_recursion_function_in_setter` | 131 | 2.6s |  |
| 72 | `infinite_recursion_virtual_property` | 67 | 2.6s |  |
| 73 | `init_array_invalid` | 4 | 2.6s |  |
| 74 | `init_object_invalid` | 4 | 2.6s |  |
| 75 | `issue_1086` | 1 | 2.6s |  |
| 76 | `issue_1671` | 0 | 2.6s |  |
| 77 | `issue_1906` | 4 | 2.7s |  |
| 78 | `issue_3446` | 1 | 2.6s |  |
| 79 | `issue_4377` | 2 | 2.6s |  |
| 80 | `issue_710` | 4 | 2.6s |  |
| 81 | `issue_768` | 3 | 2.6s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 82 | `lessthan` | 41 | 2.7s |  |
| 83 | `lessthan2_swf5` | 1226 | 12.2s |  |
| 84 | `lessthan2_swf6` | 1226 | 12.1s |  |
| 85 | `lessthan2_swf7` | 1226 | 12.0s |  |
| 86 | `lessthan_swf4` | 902 | 8.1s |  |
| 87 | `lessthan_swf4_alt` | 41 | 2.7s |  |
| 88 | `lessthan_swf5` | 41 | 2.7s |  |
| 89 | `logical_ops_swf4` | 90 | 2.6s |  |
| 90 | `logical_ops_swf8` | 108 | 2.6s |  |
| 91 | `looping` | 6 | 2.5s |  |
| 92 | `mask_reapply` | 0 | 2.5s |  |
| 93 | `mask_with_drawing` | 0 | 2.5s |  |
| 94 | `movieclip_begin_gradient_fill` | 0 | 3.1s |  |
| 95 | `movieclip_line_gradient_style` | 0 | 3.4s |  |
| 96 | `movieclip_name_from_timeline` | 13 | 2.8s |  |
| 97 | `movieclip_prototype_extension` | 5 | 2.8s |  |
| 98 | `nested_textfields_in_buttons` | 0 | 2.5s |  |
| 99 | `new_method_wrap` | 4 | 2.7s |  |
| 100 | `new_object_enumerate` | 7 | 2.8s |  |
| 101 | `new_object_wrap` | 4 | 2.8s |  |
| 102 | `o` | 3 | 2.7s |  |
| 103 | `object_constructor` | 33 | 2.7s |  |
| 104 | `object_function` | 32 | 2.9s |  |
| 105 | `object_string_coerce_swf5` | 62 | 2.9s |  |
| 106 | `primitive_instanceof` | 37 | 2.9s |  |
| 107 | `prototype_delete` | 12 | 2.9s |  |
| 108 | `recursive_prototypes` | 0 | 2.8s |  |
| 109 | `sandbox_type_local_network` | 1 | 2.6s |  |
| 110 | `single_frame` | 1 | 2.6s |  |
| 111 | `stage_object_properties_get_var` | 5 | 2.6s |  |
| 112 | `strictequals_swf6` | 902 | 9.0s |  |
| 113 | `strictly_equals` | 7 | 2.7s |  |
| 114 | `string_coercion` | 117 | 3.3s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 115 | `string_paths_keyevents` | 0 | 2.6s |  |
| 116 | `string_paths_timer` | 0 | 2.7s |  |
| 117 | `swf4_actions_bool` | 96 | 2.8s |  |
| 118 | `swf4_bool` | 4 | 2.7s |  |
| 119 | `swf4_function_calls` | 7 | 2.9s |  |
| 120 | `swf5_encoding` | 3 | 2.5s |  |
| 121 | `swf7_case_sensitive` | 44 | 2.7s |  |
| 122 | `this_swf7` | 41 | 2.6s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 123 | `timeline_function_def` | 7 | 2.7s |  |
| 124 | `try_finally_simple` | 16 | 2.6s |  |
| 125 | `typeof_globals` | 7 | 2.6s |  |
| 126 | `undefined_to_string_swf6` | 4 | 2.6s |  |
| 127 | `unescape` | 43 | 2.7s |  |
| 128 | `waitforframe` | 7 | 2.6s |  |
| 129 | `waitforframe2` | 16 | 2.6s |  |
| 130 | `with_return` | 2 | 2.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**78 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `set_variable_scope` | 87.9% | 51 | 58 | 7 |  |
| 2 | `textfield_text` | 85.7% | 6 | 7 | 1 |  |
| 3 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 4 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 5 | `conflicting_instance_names` | 78.3% | 18 | 23 | 5 |  |
| 6 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
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
| 17 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
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
| 34 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 35 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 36 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 37 | `slash_syntax` | 64.3% | 9 | 14 | 5 |  |
| 38 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 39 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 40 | `with` | 61.2% | 30 | 49 | 19 |  |
| 41 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 42 | `edittext_scroll` | 61.1% | 33 | 54 | 21 |  |
| 43 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 44 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 45 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 46 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 47 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 48 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 49 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 50 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 51 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 52 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 53 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 54 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 55 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 56 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 57 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 58 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 59 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 60 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 61 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 62 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 63 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 64 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 65 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 66 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 67 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 68 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 69 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 70 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 71 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 72 | `define_function2_preload_order` | 50.0% | 2 | 4 | 2 |  |
| 73 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 74 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 75 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 76 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 77 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 78 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 12.7s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.8s |  |
| 3 | `path_string` | 4.8s |  |
| 4 | `swf4_actions_coercion_order` | 4.9s |  |

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
| 2 | `timeout` | runtime timeout (>10s) | 12.9s |  |
| 3 | `try_catch_finally` | runtime timeout (>10s) | 13.0s |  |

## All Output Mismatches

**355 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `set_variable_scope` | 87.9% | 51/58 | 58 | 58 |  |
| 2 | `textfield_text` | 85.7% | 6/7 | 7 | 7 |  |
| 3 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 4 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 5 | `conflicting_instance_names` | 78.3% | 18/23 | 23 | 23 |  |
| 6 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
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
| 17 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
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
| 34 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 35 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 36 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 37 | `slash_syntax` | 64.3% | 9/14 | 14 | 14 |  |
| 38 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 39 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 40 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 41 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 42 | `edittext_scroll` | 61.1% | 33/54 | 54 | 54 |  |
| 43 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 44 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 45 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 46 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 47 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 48 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 49 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 50 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 51 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 52 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 53 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 54 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 55 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 56 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 57 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 58 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 59 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 60 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 61 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 62 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 63 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 64 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 65 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 66 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 67 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 68 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 69 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 70 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 71 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 72 | `define_function2_preload_order` | 50.0% | 2/4 | 2 | 4 |  |
| 73 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 74 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 75 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 76 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 77 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 78 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 79 | `edittext_newline_stripping` | 49.2% | 32/65 | 65 | 64 |  |
| 80 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 81 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 82 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 83 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 84 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 85 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 86 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 87 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 88 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 89 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 90 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 91 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 92 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 93 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 94 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 95 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 96 | `edittext_html_swf6` | 37.5% | 2014/5377 | 5377 | 5377 |  |
| 97 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 98 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 99 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 100 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 101 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 102 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 103 | `frame_size_translated_negative` | 33.3% | 7/21 | 20 | 21 |  |
| 104 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 105 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 106 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 107 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 108 | `remove_movie_clip` | 31.0% | 9/29 | 17 | 29 |  |
| 109 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 110 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 111 | `edittext_html_condensewhite_swf7` | 29.9% | 93/311 | 311 | 311 |  |
| 112 | `edittext_html_condensewhite_swf8` | 28.9% | 90/311 | 311 | 311 |  |
| 113 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 114 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 115 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 116 | `edittext_html_swf7` | 25.6% | 1378/5377 | 5377 | 5377 |  |
| 117 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 118 | `edittext_html_swf8` | 25.3% | 1363/5377 | 5377 | 5377 |  |
| 119 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 120 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 121 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 122 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 123 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 124 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 125 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 126 | `stage_object_properties_swf6` | 23.4% | 54/231 | 165 | 231 |  |
| 127 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 128 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 129 | `stage_object_properties` | 22.4% | 54/241 | 175 | 241 |  |
| 130 | `funky_function_calls` | 21.4% | 12/56 | 32 | 56 |  |
| 131 | `textfield_props_swf5` | 21.1% | 37/175 | 139 | 175 |  |
| 132 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 133 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 134 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 135 | `target_clip_removed` | 20.0% | 1/5 | 5 | 5 |  |
| 136 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 137 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 138 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 139 | `textfield_props_swf6` | 17.6% | 37/210 | 140 | 210 |  |
| 140 | `textfield_props_swf7` | 17.1% | 36/210 | 140 | 210 |  |
| 141 | `textfield_props_swf8` | 17.1% | 36/210 | 140 | 210 |  |
| 142 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 143 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 144 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 145 | `edittext_tag_indent` | 16.1% | 5/31 | 31 | 31 |  |
| 146 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 147 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 148 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 149 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 150 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 151 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 152 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 153 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 154 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 155 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 156 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 157 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 158 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 159 | `register_and_init_order` | 13.0% | 30/231 | 54 | 231 |  |
| 160 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 161 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 162 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 163 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 164 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 165 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 166 | `swf5_no_closure` | 10.5% | 2/19 | 11 | 19 |  |
| 167 | `edittext_autosize_setter` | 10.0% | 2/20 | 20 | 20 |  |
| 168 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 169 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 170 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 171 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 172 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 173 | `execution_order4` | 8.3% | 1/12 | 7 | 12 |  |
| 174 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 175 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 176 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 177 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 178 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 179 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 180 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 181 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 182 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 183 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 184 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 185 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 186 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 187 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 188 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 189 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 190 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 191 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 192 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 193 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 194 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 195 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 196 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 197 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 198 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 199 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 200 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 201 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 202 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 203 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 204 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 205 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 206 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 21 | 112 |  |
| 207 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 208 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 209 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 210 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 211 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 212 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 213 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 214 | `global_proto_decls` | 0.0% | 1/4497 | 20 | 4497 |  |
| 215 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 216 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 217 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 218 | `as2_oop` | 0.0% | 0/13 | 0 | 13 |  |
| 219 | `as2_super_and_this_v6` | 0.0% | 0/97 | 0 | 97 |  |
| 220 | `as2_super_and_this_v8` | 0.0% | 0/85 | 0 | 85 |  |
| 221 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 0 | 40 |  |
| 222 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 223 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 224 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 225 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 226 | `button_children` | 0.0% | 0/8 | 0 | 8 |  |
| 227 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 228 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 229 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 230 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 231 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 232 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 233 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 234 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 235 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 236 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 237 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 238 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 239 | `color` | 0.0% | 0/57 | 0 | 57 |  |
| 240 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 241 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 242 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 243 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 244 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 245 | `duplicate_movie_clip` | 0.0% | 0/20 | 0 | 20 |  |
| 246 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 247 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 248 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 249 | `extends_chain` | 0.0% | 0/134 | 0 | 134 |  |
| 250 | `extends_native_type` | 0.0% | 0/11 | 0 | 11 |  |
| 251 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 252 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 253 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 254 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 255 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 256 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 257 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 258 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 259 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 260 | `global_proto_decls_delete` | 0.0% | 0/4158 | 14 | 4158 |  |
| 261 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 262 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 263 | `goto_frame` | 0.0% | 0/12 | 0 | 12 |  |
| 264 | `goto_frame2` | 0.0% | 0/44 | 0 | 44 |  |
| 265 | `goto_label` | 0.0% | 0/17 | 0 | 17 |  |
| 266 | `goto_methods` | 0.0% | 0/40 | 0 | 40 |  |
| 267 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 268 | `hittest_morph` | 0.0% | 0/70 | 0 | 70 |  |
| 269 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 270 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 271 | `init_object_order` | 0.0% | 0/15 | 0 | 15 |  |
| 272 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 273 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 274 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 275 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 276 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 277 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 278 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 279 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 280 | `issue_9885` | 0.0% | 0/2 | 0 | 2 |  |
| 281 | `localconnection` | 0.0% | 0/579 | 0 | 579 |  |
| 282 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 283 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 284 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 285 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 286 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 287 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 288 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 289 | `movieclip_init_object` | 0.0% | 0/5 | 0 | 5 |  |
| 290 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 291 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 292 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 293 | `native_objects_swf6` | 0.0% | 0/84 | 0 | 84 |  |
| 294 | `native_objects_swf7` | 0.0% | 0/84 | 0 | 84 |  |
| 295 | `native_objects_swf8` | 0.0% | 0/84 | 0 | 84 |  |
| 296 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 297 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 298 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 299 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 300 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 301 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 302 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 303 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 304 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 305 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 306 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 307 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 308 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 309 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 310 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 311 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 312 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 313 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 314 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 315 | `selection` | 0.0% | 0/454 | 0 | 454 |  |
| 316 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 317 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 318 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 319 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 320 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 321 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 322 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 323 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 324 | `stylesheet` | 0.0% | 0/283 | 0 | 283 |  |
| 325 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 326 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 327 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 328 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 329 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 330 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 331 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 332 | `target_path` | 0.0% | 0/14 | 0 | 14 |  |
| 333 | `tell_target_invalid` | 0.0% | 0/6 | 6 | 6 |  |
| 334 | `tell_target_invalid_swf6` | 0.0% | 0/6 | 6 | 5 |  |
| 335 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 336 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 337 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 338 | `timer_run_actions` | 0.0% | 0/18 | 0 | 18 |  |
| 339 | `typeof` | 0.0% | 0/22 | 0 | 22 |  |
| 340 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 341 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 342 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 343 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 344 | `variable_args` | 0.0% | 0/6 | 6 | 5 |  |
| 345 | `watch` | 0.0% | 0/117 | 0 | 117 |  |
| 346 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 347 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 348 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 349 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 350 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 351 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 352 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 353 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 354 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 355 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
