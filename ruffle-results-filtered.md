# Ruffle Test Results (Filtered)

**Date**: 2026-02-13 21:41 UTC

**Git SHA**: `2032bc1f5f`

**Run Duration**: 33m 25s

**Filtered**: 125 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 494 |
| Passing | **132** (26.7%) |
| Failing | 362 |
| Total expected lines | 78537 |
| Matching lines | 32602 (41.5%) |
| Mismatched lines | 45935 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 353 | 97.5% |
| Segfault | 4 | 1.1% |
| Timeout | 3 | 0.8% |
| Runtime Error | 2 | 0.6% |

## Passing Tests

**132 tests passing**

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
| 52 | `get_variable_in_scope` | 29 | 2.8s |  |
| 53 | `getproperty` | 28 | 2.7s |  |
| 54 | `getproperty_swf4` | 28 | 2.7s |  |
| 55 | `getproperty_swf5` | 28 | 2.7s |  |
| 56 | `global_array` | 3 | 2.6s |  |
| 57 | `global_is_bare` | 7 | 2.6s |  |
| 58 | `goto_advance2` | 2 | 2.7s |  |
| 59 | `goto_both_ways1` | 3 | 3.9s |  |
| 60 | `goto_both_ways2` | 3 | 2.8s |  |
| 61 | `goto_execution_order` | 2 | 2.7s |  |
| 62 | `goto_execution_order2` | 2 | 2.7s |  |
| 63 | `goto_frame_number` | 3 | 2.8s |  |
| 64 | `goto_rewind1` | 1 | 2.7s |  |
| 65 | `goto_rewind2` | 3 | 2.8s |  |
| 66 | `goto_rewind3` | 2 | 2.8s |  |
| 67 | `greater_swf6` | 1175 | 12.2s |  |
| 68 | `greater_swf7` | 1175 | 12.0s |  |
| 69 | `greaterthan_swf5` | 1 | 2.7s |  |
| 70 | `greaterthan_swf8` | 1 | 2.7s |  |
| 71 | `has_own_property` | 32 | 2.8s |  |
| 72 | `infinite_recursion_function_in_setter` | 131 | 2.7s |  |
| 73 | `infinite_recursion_virtual_property` | 67 | 2.7s |  |
| 74 | `init_array_invalid` | 4 | 2.7s |  |
| 75 | `init_object_invalid` | 4 | 2.7s |  |
| 76 | `issue_1086` | 1 | 2.7s |  |
| 77 | `issue_1671` | 0 | 2.7s |  |
| 78 | `issue_1906` | 4 | 2.8s |  |
| 79 | `issue_3446` | 1 | 2.7s |  |
| 80 | `issue_4377` | 2 | 2.7s |  |
| 81 | `issue_710` | 4 | 2.7s |  |
| 82 | `issue_768` | 3 | 2.7s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 83 | `lessthan` | 41 | 2.8s |  |
| 84 | `lessthan2_swf5` | 1226 | 12.5s |  |
| 85 | `lessthan2_swf6` | 1226 | 12.9s |  |
| 86 | `lessthan2_swf7` | 1226 | 12.6s |  |
| 87 | `lessthan_swf4` | 902 | 8.2s |  |
| 88 | `lessthan_swf4_alt` | 41 | 2.8s |  |
| 89 | `lessthan_swf5` | 41 | 2.8s |  |
| 90 | `logical_ops_swf4` | 90 | 2.6s |  |
| 91 | `logical_ops_swf8` | 108 | 2.6s |  |
| 92 | `looping` | 6 | 2.5s |  |
| 93 | `mask_reapply` | 0 | 2.5s |  |
| 94 | `mask_with_drawing` | 0 | 2.5s |  |
| 95 | `movieclip_begin_gradient_fill` | 0 | 3.1s |  |
| 96 | `movieclip_line_gradient_style` | 0 | 3.1s |  |
| 97 | `movieclip_name_from_timeline` | 13 | 2.5s |  |
| 98 | `movieclip_prototype_extension` | 5 | 2.5s |  |
| 99 | `nested_textfields_in_buttons` | 0 | 2.5s |  |
| 100 | `new_method_wrap` | 4 | 2.5s |  |
| 101 | `new_object_enumerate` | 7 | 2.5s |  |
| 102 | `new_object_wrap` | 4 | 2.5s |  |
| 103 | `o` | 3 | 2.5s |  |
| 104 | `object_constructor` | 33 | 2.6s |  |
| 105 | `object_function` | 32 | 2.6s |  |
| 106 | `object_string_coerce_swf5` | 62 | 2.7s |  |
| 107 | `primitive_instanceof` | 37 | 2.6s |  |
| 108 | `prototype_delete` | 12 | 2.6s |  |
| 109 | `recursive_prototypes` | 0 | 2.5s |  |
| 110 | `sandbox_type_local_network` | 1 | 2.6s |  |
| 111 | `set_variable_scope` | 58 | 2.8s |  |
| 112 | `single_frame` | 1 | 2.6s |  |
| 113 | `stage_object_properties_get_var` | 5 | 2.6s |  |
| 114 | `strictequals_swf6` | 902 | 8.9s |  |
| 115 | `strictly_equals` | 7 | 2.6s |  |
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
| 132 | `with_return` | 2 | 2.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**77 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `textfield_text` | 85.7% | 6 | 7 | 1 |  |
| 2 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 3 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 4 | `conflicting_instance_names` | 78.3% | 18 | 23 | 5 |  |
| 5 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 6 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 7 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 8 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 9 | `textfield_background_color` | 72.7% | 8 | 11 | 3 |  |
| 10 | `textfield_border_color` | 72.7% | 8 | 11 | 3 |  |
| 11 | `textfield_properties` | 72.7% | 32 | 44 | 12 |  |
| 12 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 13 | `point` | 70.9% | 124 | 175 | 51 |  |
| 14 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 15 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 16 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 17 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 18 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 19 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 20 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 21 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 22 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 23 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 24 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 25 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 26 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 27 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 28 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 29 | `textfield_variable` | 66.7% | 54 | 81 | 27 |  |
| 30 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 31 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 32 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 33 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 34 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 35 | `slash_syntax` | 64.3% | 9 | 14 | 5 |  |
| 36 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 37 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 38 | `with` | 61.2% | 30 | 49 | 19 |  |
| 39 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 40 | `edittext_scroll` | 61.1% | 33 | 54 | 21 |  |
| 41 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 42 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 43 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 44 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 45 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 46 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 47 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 48 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 49 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 50 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 51 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 52 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 53 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 54 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 55 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 56 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 57 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 58 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 59 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 60 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 61 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 62 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 63 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 64 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 65 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 66 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 67 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 68 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 69 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 70 | `define_function2_preload_order` | 50.0% | 2 | 4 | 2 |  |
| 71 | `display_object_properties` | 50.0% | 1 | 2 | 1 |  |
| 72 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 73 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 74 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 75 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 76 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 77 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

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

**353 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `textfield_text` | 85.7% | 6/7 | 7 | 7 |  |
| 2 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 3 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 4 | `conflicting_instance_names` | 78.3% | 18/23 | 23 | 23 |  |
| 5 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 6 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 7 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 8 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 9 | `textfield_background_color` | 72.7% | 8/11 | 11 | 11 |  |
| 10 | `textfield_border_color` | 72.7% | 8/11 | 11 | 11 |  |
| 11 | `textfield_properties` | 72.7% | 32/44 | 44 | 44 |  |
| 12 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 13 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 14 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 15 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 16 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 17 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 18 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 19 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 20 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 21 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 22 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 23 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 24 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 25 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 26 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 27 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 28 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 29 | `textfield_variable` | 66.7% | 54/81 | 81 | 81 |  |
| 30 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 31 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 32 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 33 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 34 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 35 | `slash_syntax` | 64.3% | 9/14 | 14 | 14 |  |
| 36 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 37 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 38 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 39 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 40 | `edittext_scroll` | 61.1% | 33/54 | 54 | 54 |  |
| 41 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 42 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 43 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 44 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 45 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 46 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 47 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 48 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 49 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 50 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 51 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 52 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 53 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 54 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 55 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 56 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 57 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 58 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 59 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 60 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 61 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 62 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 63 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 64 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 65 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 66 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 67 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 68 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 69 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 70 | `define_function2_preload_order` | 50.0% | 2/4 | 2 | 4 |  |
| 71 | `display_object_properties` | 50.0% | 1/2 | 2 | 2 |  |
| 72 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 73 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 74 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 75 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 76 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 77 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 78 | `edittext_newline_stripping` | 49.2% | 32/65 | 65 | 64 |  |
| 79 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 80 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 81 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 82 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 83 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 84 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 85 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 86 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 87 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 88 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 89 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 90 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 91 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 92 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 93 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 94 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 95 | `edittext_html_swf6` | 37.5% | 2014/5377 | 5377 | 5377 |  |
| 96 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 97 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 98 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 99 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 100 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 101 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 102 | `frame_size_translated_negative` | 33.3% | 7/21 | 20 | 21 |  |
| 103 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 104 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 105 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 106 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 107 | `remove_movie_clip` | 31.0% | 9/29 | 17 | 29 |  |
| 108 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 109 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 110 | `edittext_html_condensewhite_swf7` | 29.9% | 93/311 | 311 | 311 |  |
| 111 | `edittext_html_condensewhite_swf8` | 28.9% | 90/311 | 311 | 311 |  |
| 112 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 113 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 114 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 115 | `edittext_html_swf7` | 25.6% | 1378/5377 | 5377 | 5377 |  |
| 116 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 117 | `edittext_html_swf8` | 25.3% | 1363/5377 | 5377 | 5377 |  |
| 118 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 119 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 120 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 121 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 122 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 123 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 124 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 125 | `stage_object_properties_swf6` | 23.4% | 54/231 | 165 | 231 |  |
| 126 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 127 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 128 | `stage_object_properties` | 22.4% | 54/241 | 175 | 241 |  |
| 129 | `funky_function_calls` | 21.4% | 12/56 | 32 | 56 |  |
| 130 | `textfield_props_swf5` | 21.1% | 37/175 | 139 | 175 |  |
| 131 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 132 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 133 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 134 | `target_clip_removed` | 20.0% | 1/5 | 5 | 5 |  |
| 135 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 136 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 137 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 138 | `textfield_props_swf6` | 17.6% | 37/210 | 140 | 210 |  |
| 139 | `textfield_props_swf7` | 17.1% | 36/210 | 140 | 210 |  |
| 140 | `textfield_props_swf8` | 17.1% | 36/210 | 140 | 210 |  |
| 141 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 142 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 143 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 144 | `edittext_tag_indent` | 16.1% | 5/31 | 31 | 31 |  |
| 145 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 146 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 147 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 148 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 149 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 150 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 151 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 152 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 153 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 154 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 155 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 156 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 157 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 158 | `register_and_init_order` | 13.0% | 30/231 | 54 | 231 |  |
| 159 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 160 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 161 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 162 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 163 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 164 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 165 | `swf5_no_closure` | 10.5% | 2/19 | 11 | 19 |  |
| 166 | `edittext_autosize_setter` | 10.0% | 2/20 | 20 | 20 |  |
| 167 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 168 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 169 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 170 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 171 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 172 | `execution_order4` | 8.3% | 1/12 | 7 | 12 |  |
| 173 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 174 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 175 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 176 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 177 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 178 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 179 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 180 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 181 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 182 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 183 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 184 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 185 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 186 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 187 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 188 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 189 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 190 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 191 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 192 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 193 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 194 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 195 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 196 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 197 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 198 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 199 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 200 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 201 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 202 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 203 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 204 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 205 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 21 | 112 |  |
| 206 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 207 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 208 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 209 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 210 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 211 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 212 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 213 | `global_proto_decls` | 0.0% | 1/4497 | 20 | 4497 |  |
| 214 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 215 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 216 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 217 | `as2_oop` | 0.0% | 0/13 | 0 | 13 |  |
| 218 | `as2_super_and_this_v6` | 0.0% | 0/97 | 0 | 97 |  |
| 219 | `as2_super_and_this_v8` | 0.0% | 0/85 | 0 | 85 |  |
| 220 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 0 | 40 |  |
| 221 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 222 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 223 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 224 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 225 | `button_children` | 0.0% | 0/8 | 0 | 8 |  |
| 226 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 227 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 228 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 229 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 230 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 231 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 232 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 233 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 234 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 235 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 236 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 237 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 238 | `color` | 0.0% | 0/57 | 0 | 57 |  |
| 239 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 240 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 241 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 242 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 243 | `duplicate_movie_clip` | 0.0% | 0/20 | 0 | 20 |  |
| 244 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 245 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 246 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 247 | `extends_chain` | 0.0% | 0/134 | 0 | 134 |  |
| 248 | `extends_native_type` | 0.0% | 0/11 | 0 | 11 |  |
| 249 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 250 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 251 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 252 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 253 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 254 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 255 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 256 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 257 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 258 | `global_proto_decls_delete` | 0.0% | 0/4158 | 14 | 4158 |  |
| 259 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 260 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 261 | `goto_frame` | 0.0% | 0/12 | 0 | 12 |  |
| 262 | `goto_frame2` | 0.0% | 0/44 | 0 | 44 |  |
| 263 | `goto_label` | 0.0% | 0/17 | 0 | 17 |  |
| 264 | `goto_methods` | 0.0% | 0/40 | 0 | 40 |  |
| 265 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 266 | `hittest_morph` | 0.0% | 0/70 | 0 | 70 |  |
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
| 331 | `tell_target_invalid` | 0.0% | 0/6 | 6 | 6 |  |
| 332 | `tell_target_invalid_swf6` | 0.0% | 0/6 | 6 | 5 |  |
| 333 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 334 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 335 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 336 | `timer_run_actions` | 0.0% | 0/18 | 0 | 18 |  |
| 337 | `typeof` | 0.0% | 0/22 | 0 | 22 |  |
| 338 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 339 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 340 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 341 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 342 | `variable_args` | 0.0% | 0/6 | 6 | 5 |  |
| 343 | `watch` | 0.0% | 0/117 | 0 | 117 |  |
| 344 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 345 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 346 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 347 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 348 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 349 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 350 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 351 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 352 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 353 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
