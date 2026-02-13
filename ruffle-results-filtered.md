# Ruffle Test Results (Filtered)

**Date**: 2026-02-13 22:21 UTC

**Git SHA**: `00911d0f7d`

**Run Duration**: 33m 46s

**Filtered**: 125 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 494 |
| Passing | **132** (26.7%) |
| Failing | 362 |
| Total expected lines | 78497 |
| Matching lines | 32876 (41.9%) |
| Mismatched lines | 45621 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 352 | 97.2% |
| Segfault | 4 | 1.1% |
| Timeout | 4 | 1.1% |
| Runtime Error | 2 | 0.6% |

## Passing Tests

**132 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 3.8s |  |
| 2 | `action_to_integer` | 28 | 2.7s |  |
| 3 | `add` | 28 | 2.7s |  |
| 4 | `add2` | 354 | 3.2s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.8s |  |
| 6 | `add_swf5` | 28 | 2.8s |  |
| 7 | `array_concat` | 98 | 2.9s |  |
| 8 | `array_constructor` | 30 | 2.8s |  |
| 9 | `array_length` | 42 | 2.9s |  |
| 10 | `array_properties` | 36 | 2.8s |  |
| 11 | `array_slice` | 34 | 2.8s |  |
| 12 | `array_splice` | 207 | 3.6s |  |
| 13 | `array_trivial` | 209 | 3.3s |  |
| 14 | `as1_constructor_v6` | 35 | 2.8s |  |
| 15 | `as1_constructor_v7` | 35 | 2.8s |  |
| 16 | `as_broadcaster_initialize` | 10 | 2.7s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 2.7s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 2.7s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 2.7s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 2.7s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 2.7s |  |
| 22 | `as_transformed_flag` | 20 | 2.8s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 2.6s |  |
| 24 | `bitand` | 1058 | 9.8s |  |
| 25 | `bitmap_data_colortransform` | 0 | 3.0s |  |
| 26 | `bitmap_data_fillrect` | 0 | 2.9s |  |
| 27 | `bitmap_data_perlinnoise` | 0 | 3.5s |  |
| 28 | `bitmap_data_pixeldissolve_image` | 0 | 3.2s |  |
| 29 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.7s |  |
| 30 | `bitor` | 1058 | 9.8s |  |
| 31 | `biturshift` | 14 | 3.8s |  |
| 32 | `biturshift_swf8` | 14 | 2.6s |  |
| 33 | `bitxor` | 1058 | 9.2s |  |
| 34 | `call_method_empty_name` | 1 | 2.6s |  |
| 35 | `catch_references_registers` | 2 | 2.6s |  |
| 36 | `define_function2` | 8 | 2.6s |  |
| 37 | `define_function2_preload` | 13 | 2.6s |  |
| 38 | `define_function2_preload_order` | 4 | 2.6s |  |
| 39 | `define_function_case_sensitive` | 2 | 2.6s |  |
| 40 | `delete` | 3 | 2.7s |  |
| 41 | `divide_swf4` | 107 | 2.8s |  |
| 42 | `do_init_action` | 3 | 2.6s |  |
| 43 | `equals` | 32 | 2.8s |  |
| 44 | `equals2_swf5` | 926 | 11.5s |  |
| 45 | `equals2_swf6` | 926 | 11.4s |  |
| 46 | `equals2_swf7` | 926 | 11.5s |  |
| 47 | `equals_swf4` | 665 | 6.5s |  |
| 48 | `equals_swf4_alt` | 32 | 2.8s |  |
| 49 | `equals_swf5` | 32 | 2.8s |  |
| 50 | `error` | 58 | 2.9s |  |
| 51 | `escape` | 14 | 2.7s |  |
| 52 | `get_variable_in_scope` | 29 | 2.8s |  |
| 53 | `getproperty` | 28 | 2.6s |  |
| 54 | `getproperty_swf4` | 28 | 2.7s |  |
| 55 | `getproperty_swf5` | 28 | 2.6s |  |
| 56 | `global_array` | 3 | 2.6s |  |
| 57 | `global_is_bare` | 7 | 2.6s |  |
| 58 | `goto_advance2` | 2 | 2.6s |  |
| 59 | `goto_both_ways1` | 3 | 4.8s |  |
| 60 | `goto_both_ways2` | 3 | 2.7s |  |
| 61 | `goto_execution_order` | 2 | 2.6s |  |
| 62 | `goto_execution_order2` | 2 | 2.6s |  |
| 63 | `goto_frame_number` | 3 | 2.7s |  |
| 64 | `goto_rewind1` | 1 | 2.6s |  |
| 65 | `goto_rewind2` | 3 | 2.6s |  |
| 66 | `goto_rewind3` | 2 | 2.7s |  |
| 67 | `greater_swf6` | 1175 | 11.9s |  |
| 68 | `greater_swf7` | 1175 | 11.6s |  |
| 69 | `greaterthan_swf5` | 1 | 2.6s |  |
| 70 | `greaterthan_swf8` | 1 | 2.6s |  |
| 71 | `has_own_property` | 32 | 2.8s |  |
| 72 | `infinite_recursion_function_in_setter` | 131 | 2.6s |  |
| 73 | `infinite_recursion_virtual_property` | 67 | 2.6s |  |
| 74 | `init_array_invalid` | 4 | 2.6s |  |
| 75 | `init_object_invalid` | 4 | 2.6s |  |
| 76 | `issue_1086` | 1 | 2.6s |  |
| 77 | `issue_1671` | 0 | 2.6s |  |
| 78 | `issue_1906` | 4 | 2.7s |  |
| 79 | `issue_3446` | 1 | 2.6s |  |
| 80 | `issue_4377` | 2 | 2.6s |  |
| 81 | `issue_710` | 4 | 2.6s |  |
| 82 | `issue_768` | 3 | 2.6s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 83 | `lessthan` | 41 | 2.8s |  |
| 84 | `lessthan2_swf5` | 1226 | 12.2s |  |
| 85 | `lessthan2_swf6` | 1226 | 12.3s |  |
| 86 | `lessthan2_swf7` | 1226 | 12.3s |  |
| 87 | `lessthan_swf4` | 902 | 8.0s |  |
| 88 | `lessthan_swf4_alt` | 41 | 2.7s |  |
| 89 | `lessthan_swf5` | 41 | 2.7s |  |
| 90 | `logical_ops_swf4` | 90 | 2.7s |  |
| 91 | `logical_ops_swf8` | 108 | 2.7s |  |
| 92 | `looping` | 6 | 2.6s |  |
| 93 | `mask_reapply` | 0 | 2.6s |  |
| 94 | `mask_with_drawing` | 0 | 2.6s |  |
| 95 | `movieclip_begin_gradient_fill` | 0 | 3.2s |  |
| 96 | `movieclip_line_gradient_style` | 0 | 3.2s |  |
| 97 | `movieclip_name_from_timeline` | 13 | 2.7s |  |
| 98 | `movieclip_prototype_extension` | 5 | 2.7s |  |
| 99 | `nested_textfields_in_buttons` | 0 | 2.6s |  |
| 100 | `new_method_wrap` | 4 | 2.6s |  |
| 101 | `new_object_enumerate` | 7 | 2.7s |  |
| 102 | `new_object_wrap` | 4 | 2.6s |  |
| 103 | `o` | 3 | 2.6s |  |
| 104 | `object_constructor` | 33 | 2.7s |  |
| 105 | `object_function` | 32 | 2.7s |  |
| 106 | `object_string_coerce_swf5` | 62 | 2.8s |  |
| 107 | `primitive_instanceof` | 37 | 2.7s |  |
| 108 | `prototype_delete` | 12 | 2.7s |  |
| 109 | `recursive_prototypes` | 0 | 2.6s |  |
| 110 | `sandbox_type_local_network` | 1 | 2.6s |  |
| 111 | `set_variable_scope` | 58 | 2.8s |  |
| 112 | `single_frame` | 1 | 2.6s |  |
| 113 | `stage_object_properties_get_var` | 5 | 2.6s |  |
| 114 | `strictequals_swf6` | 902 | 9.1s |  |
| 115 | `strictly_equals` | 7 | 2.7s |  |
| 116 | `string_coercion` | 117 | 3.3s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 117 | `string_paths_keyevents` | 0 | 2.6s |  |
| 118 | `string_paths_timer` | 0 | 2.6s |  |
| 119 | `swf4_actions_bool` | 96 | 2.8s |  |
| 120 | `swf4_bool` | 4 | 2.7s |  |
| 121 | `swf4_function_calls` | 7 | 2.8s |  |
| 122 | `swf5_encoding` | 3 | 2.6s |  |
| 123 | `swf7_case_sensitive` | 44 | 2.8s |  |
| 124 | `this_swf7` | 41 | 2.7s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 125 | `timeline_function_def` | 7 | 2.8s |  |
| 126 | `try_finally_simple` | 16 | 2.7s |  |
| 127 | `typeof_globals` | 7 | 2.6s |  |
| 128 | `undefined_to_string_swf6` | 4 | 2.6s |  |
| 129 | `unescape` | 43 | 2.8s |  |
| 130 | `waitforframe` | 7 | 2.6s |  |
| 131 | `waitforframe2` | 16 | 2.7s |  |
| 132 | `with_return` | 2 | 2.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**83 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `textfield_text` | 85.7% | 6 | 7 | 1 |  |
| 2 | `variable_args` | 83.3% | 5 | 6 | 1 |  |
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
| 14 | `execution_order2` | 71.4% | 5 | 7 | 2 |  |
| 15 | `point` | 70.9% | 124 | 175 | 51 |  |
| 16 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 17 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 18 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 19 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 20 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 21 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 22 | `stage_object_properties` | 68.5% | 165 | 241 | 76 |  |
| 23 | `stage_object_properties_swf6` | 68.4% | 158 | 231 | 73 |  |
| 24 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 25 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 26 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 27 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 28 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 29 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 30 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 31 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 32 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 33 | `target_clip_removed` | 66.7% | 4 | 6 | 2 |  |
| 34 | `textfield_variable` | 66.7% | 54 | 81 | 27 |  |
| 35 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 36 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 37 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 38 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 39 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 40 | `slash_syntax` | 64.3% | 9 | 14 | 5 |  |
| 41 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 42 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 43 | `with` | 61.2% | 30 | 49 | 19 |  |
| 44 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 45 | `edittext_scroll` | 61.1% | 33 | 54 | 21 |  |
| 46 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 47 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 48 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 49 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 50 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 51 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 52 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 53 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 54 | `execution_order1` | 60.0% | 3 | 5 | 2 |  |
| 55 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 56 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 57 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 58 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 59 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 60 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 61 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 62 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 63 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 64 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 65 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 66 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 67 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 68 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 69 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 70 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 71 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 72 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 73 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 74 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 75 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 76 | `display_object_properties` | 50.0% | 1 | 2 | 1 |  |
| 77 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 78 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 79 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 80 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 81 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 82 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 83 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 12.8s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.6s |  |
| 3 | `path_string` | 5.2s |  |
| 4 | `swf4_actions_coercion_order` | 5.0s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.6s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.6s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `goto_methods` | runtime timeout (>10s) | 13.0s |  |
| 2 | `parse_float` | runtime timeout (>10s) | 13.7s |  |
| 3 | `timeout` | runtime timeout (>10s) | 13.8s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 13.1s |  |

## All Output Mismatches

**352 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `textfield_text` | 85.7% | 6/7 | 7 | 7 |  |
| 2 | `variable_args` | 83.3% | 5/6 | 6 | 5 |  |
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
| 14 | `execution_order2` | 71.4% | 5/7 | 7 | 7 |  |
| 15 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 16 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 17 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 18 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 19 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 20 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 21 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 22 | `stage_object_properties` | 68.5% | 165/241 | 241 | 241 |  |
| 23 | `stage_object_properties_swf6` | 68.4% | 158/231 | 231 | 231 |  |
| 24 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 25 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 26 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 27 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 28 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 29 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 30 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 31 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 32 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 33 | `target_clip_removed` | 66.7% | 4/6 | 6 | 5 |  |
| 34 | `textfield_variable` | 66.7% | 54/81 | 81 | 81 |  |
| 35 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 36 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 37 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 38 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 39 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 40 | `slash_syntax` | 64.3% | 9/14 | 14 | 14 |  |
| 41 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 42 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 43 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 44 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 45 | `edittext_scroll` | 61.1% | 33/54 | 54 | 54 |  |
| 46 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 47 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 48 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 49 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 50 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 51 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 52 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 53 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 54 | `execution_order1` | 60.0% | 3/5 | 3 | 5 |  |
| 55 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 56 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 57 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 58 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 59 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 60 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 61 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 62 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 63 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 64 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 65 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 66 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 67 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 68 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 69 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 70 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 71 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 72 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 73 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 74 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 75 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 76 | `display_object_properties` | 50.0% | 1/2 | 2 | 2 |  |
| 77 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 78 | `execution_order3` | 50.0% | 2/4 | 4 | 4 |  |
| 79 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 80 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 81 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 82 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 83 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 84 | `edittext_newline_stripping` | 49.2% | 32/65 | 65 | 64 |  |
| 85 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 86 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
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
| 99 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 100 | `edittext_html_swf6` | 37.5% | 2014/5377 | 5377 | 5377 |  |
| 101 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 102 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 103 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 104 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 105 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 106 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 107 | `frame_size_translated_negative` | 33.3% | 7/21 | 20 | 21 |  |
| 108 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 109 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 110 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 111 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 112 | `remove_movie_clip` | 31.0% | 9/29 | 17 | 29 |  |
| 113 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 114 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 115 | `edittext_html_condensewhite_swf7` | 29.9% | 93/311 | 311 | 311 |  |
| 116 | `edittext_html_condensewhite_swf8` | 28.9% | 90/311 | 311 | 311 |  |
| 117 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 118 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 119 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 120 | `edittext_html_swf7` | 25.6% | 1378/5377 | 5377 | 5377 |  |
| 121 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 122 | `edittext_html_swf8` | 25.3% | 1363/5377 | 5377 | 5377 |  |
| 123 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 124 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 125 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 126 | `goto_frame` | 25.0% | 3/12 | 3 | 12 |  |
| 127 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 128 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 129 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 130 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 131 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 132 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 133 | `textfield_props_swf5` | 21.1% | 37/175 | 139 | 175 |  |
| 134 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 135 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 136 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 137 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 138 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 139 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 140 | `textfield_props_swf6` | 17.6% | 37/210 | 140 | 210 |  |
| 141 | `textfield_props_swf7` | 17.1% | 36/210 | 140 | 210 |  |
| 142 | `textfield_props_swf8` | 17.1% | 36/210 | 140 | 210 |  |
| 143 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 144 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 145 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 146 | `edittext_tag_indent` | 16.1% | 5/31 | 31 | 31 |  |
| 147 | `default_names` | 15.4% | 8/52 | 32 | 52 |  |
| 148 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 149 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 150 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 151 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 152 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 153 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 154 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 155 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 156 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 157 | `movieclip_hittest_shapeflag` | 14.2% | 48/338 | 338 | 338 |  |
| 158 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 159 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 160 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 161 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 162 | `register_and_init_order` | 13.0% | 30/231 | 54 | 231 |  |
| 163 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 164 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 165 | `goto_label` | 11.8% | 2/17 | 4 | 17 |  |
| 166 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 167 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 168 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 169 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 170 | `swf5_no_closure` | 10.5% | 2/19 | 11 | 19 |  |
| 171 | `edittext_autosize_setter` | 10.0% | 2/20 | 20 | 20 |  |
| 172 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 173 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 174 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 175 | `goto_frame2` | 9.1% | 4/44 | 4 | 44 |  |
| 176 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 177 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 178 | `execution_order4` | 8.3% | 1/12 | 8 | 12 |  |
| 179 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 180 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 181 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 182 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 183 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 184 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 185 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 186 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 187 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 188 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 189 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 190 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 191 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 192 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 193 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 194 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 195 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 196 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 197 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 198 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 199 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 200 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 201 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 202 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 203 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 204 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 205 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 206 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 207 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 208 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 209 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 210 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 211 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 212 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 213 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 214 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 215 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 216 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 217 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 218 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 219 | `global_proto_decls` | 0.0% | 1/4497 | 20 | 4497 |  |
| 220 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 221 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 222 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 223 | `as2_oop` | 0.0% | 0/13 | 0 | 13 |  |
| 224 | `as2_super_and_this_v6` | 0.0% | 0/97 | 0 | 97 |  |
| 225 | `as2_super_and_this_v8` | 0.0% | 0/85 | 0 | 85 |  |
| 226 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 0 | 40 |  |
| 227 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 228 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 229 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 230 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 231 | `button_children` | 0.0% | 0/8 | 0 | 8 |  |
| 232 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 233 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 234 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 235 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 236 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 237 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 238 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 239 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 240 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 241 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 242 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 243 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 244 | `color` | 0.0% | 0/57 | 0 | 57 |  |
| 245 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 246 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 247 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 248 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 249 | `duplicate_movie_clip` | 0.0% | 0/20 | 0 | 20 |  |
| 250 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 251 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 252 | `extends_chain` | 0.0% | 0/134 | 0 | 134 |  |
| 253 | `extends_native_type` | 0.0% | 0/11 | 0 | 11 |  |
| 254 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 255 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 256 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 257 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 258 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 259 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 260 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 261 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 262 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 263 | `global_proto_decls_delete` | 0.0% | 0/4158 | 14 | 4158 |  |
| 264 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 265 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 266 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 267 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 268 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 269 | `init_object_order` | 0.0% | 0/15 | 0 | 15 |  |
| 270 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 271 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 272 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 273 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 274 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 275 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 276 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 277 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 278 | `issue_9885` | 0.0% | 0/2 | 0 | 2 |  |
| 279 | `localconnection` | 0.0% | 0/579 | 0 | 579 |  |
| 280 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 281 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 282 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 283 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 284 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 285 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 286 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 287 | `movieclip_init_object` | 0.0% | 0/5 | 0 | 5 |  |
| 288 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 289 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 290 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 291 | `native_objects_swf6` | 0.0% | 0/84 | 0 | 84 |  |
| 292 | `native_objects_swf7` | 0.0% | 0/84 | 0 | 84 |  |
| 293 | `native_objects_swf8` | 0.0% | 0/84 | 0 | 84 |  |
| 294 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 295 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 296 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 297 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 298 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 299 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 300 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 301 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 302 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 303 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 304 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 305 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 306 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 307 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 308 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 309 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 310 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 311 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 312 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 313 | `selection` | 0.0% | 0/454 | 0 | 454 |  |
| 314 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 315 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 316 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 317 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 318 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 319 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 320 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 321 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 322 | `stylesheet` | 0.0% | 0/283 | 0 | 283 |  |
| 323 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 324 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 325 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 326 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 327 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 328 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 329 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 330 | `target_path` | 0.0% | 0/14 | 0 | 14 |  |
| 331 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 332 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 333 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 334 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 335 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 336 | `timer_run_actions` | 0.0% | 0/18 | 0 | 18 |  |
| 337 | `typeof` | 0.0% | 0/22 | 0 | 22 |  |
| 338 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 339 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 340 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 341 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 342 | `watch` | 0.0% | 0/117 | 0 | 117 |  |
| 343 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 344 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 345 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 346 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 347 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 348 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 349 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 350 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 351 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 352 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
