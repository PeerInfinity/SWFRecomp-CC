# Ruffle Test Results (Filtered)

**Date**: 2026-02-14 01:57 UTC

**Git SHA**: `25cbff5264`

**Run Duration**: 34m 32s

**Filtered**: 125 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 494 |
| Passing | **145** (29.4%) |
| Failing | 349 |
| Total expected lines | 78537 |
| Matching lines | 33090 (42.1%) |
| Mismatched lines | 45447 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 341 | 97.7% |
| Segfault | 5 | 1.4% |
| Timeout | 3 | 0.9% |

## Passing Tests

**145 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.8s |  |
| 2 | `action_to_integer` | 28 | 2.8s |  |
| 3 | `add` | 28 | 2.8s |  |
| 4 | `add2` | 354 | 3.2s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.8s |  |
| 6 | `add_swf5` | 28 | 2.8s |  |
| 7 | `array_concat` | 98 | 3.0s |  |
| 8 | `array_constructor` | 30 | 2.9s |  |
| 9 | `array_length` | 42 | 3.0s |  |
| 10 | `array_properties` | 36 | 2.8s |  |
| 11 | `array_slice` | 34 | 2.9s |  |
| 12 | `array_splice` | 207 | 3.6s |  |
| 13 | `array_trivial` | 209 | 3.3s |  |
| 14 | `as1_constructor_v6` | 35 | 2.9s |  |
| 15 | `as1_constructor_v7` | 35 | 2.9s |  |
| 16 | `as_broadcaster_initialize` | 10 | 2.8s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 2.8s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 2.8s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 2.8s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 2.8s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 2.8s |  |
| 22 | `as_transformed_flag` | 20 | 2.8s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 2.7s |  |
| 24 | `bitand` | 1058 | 9.4s |  |
| 25 | `bitmap_data_colortransform` | 0 | 3.0s |  |
| 26 | `bitmap_data_fillrect` | 0 | 2.9s |  |
| 27 | `bitmap_data_perlinnoise` | 0 | 3.5s |  |
| 28 | `bitmap_data_pixeldissolve_image` | 0 | 3.3s |  |
| 29 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.8s |  |
| 30 | `bitor` | 1058 | 9.4s |  |
| 31 | `biturshift` | 14 | 2.9s |  |
| 32 | `biturshift_swf8` | 14 | 2.7s |  |
| 33 | `bitxor` | 1058 | 9.2s |  |
| 34 | `call_method_empty_name` | 1 | 2.7s |  |
| 35 | `capabilities_resolution` | 8 | 2.7s |  |
| 36 | `catch_references_registers` | 2 | 2.7s |  |
| 37 | `define_function2` | 8 | 2.7s |  |
| 38 | `define_function2_preload` | 13 | 2.7s |  |
| 39 | `define_function2_preload_order` | 4 | 2.7s |  |
| 40 | `define_function_case_sensitive` | 2 | 2.7s |  |
| 41 | `delete` | 3 | 2.8s |  |
| 42 | `display_object_properties` | 2 | 2.7s |  |
| 43 | `divide_swf4` | 107 | 2.9s |  |
| 44 | `do_init_action` | 3 | 2.7s |  |
| 45 | `equals` | 32 | 2.7s |  |
| 46 | `equals2_swf5` | 926 | 11.5s |  |
| 47 | `equals2_swf6` | 926 | 11.2s |  |
| 48 | `equals2_swf7` | 926 | 11.6s |  |
| 49 | `equals_swf4` | 665 | 6.1s |  |
| 50 | `equals_swf4_alt` | 32 | 2.7s |  |
| 51 | `equals_swf5` | 32 | 2.7s |  |
| 52 | `error` | 58 | 2.8s |  |
| 53 | `escape` | 14 | 2.6s |  |
| 54 | `execution_order1` | 5 | 2.7s |  |
| 55 | `execution_order2` | 7 | 2.7s |  |
| 56 | `execution_order3` | 4 | 2.6s |  |
| 57 | `get_variable_in_scope` | 29 | 3.1s |  |
| 58 | `getproperty` | 28 | 3.0s |  |
| 59 | `getproperty_swf4` | 28 | 3.0s |  |
| 60 | `getproperty_swf5` | 28 | 3.0s |  |
| 61 | `global_array` | 3 | 2.9s |  |
| 62 | `global_is_bare` | 7 | 2.9s |  |
| 63 | `goto_advance1` | 6 | 2.9s |  |
| 64 | `goto_advance2` | 2 | 3.0s |  |
| 65 | `goto_both_ways1` | 3 | 2.8s |  |
| 66 | `goto_both_ways2` | 3 | 2.7s |  |
| 67 | `goto_execution_order` | 2 | 2.6s |  |
| 68 | `goto_execution_order2` | 2 | 2.6s |  |
| 69 | `goto_frame_number` | 3 | 2.8s |  |
| 70 | `goto_rewind1` | 1 | 2.8s |  |
| 71 | `goto_rewind2` | 3 | 2.8s |  |
| 72 | `goto_rewind3` | 2 | 2.7s |  |
| 73 | `greater_swf6` | 1175 | 11.1s |  |
| 74 | `greater_swf7` | 1175 | 11.1s |  |
| 75 | `greaterthan_swf5` | 1 | 2.6s |  |
| 76 | `greaterthan_swf8` | 1 | 2.6s |  |
| 77 | `has_own_property` | 32 | 2.8s |  |
| 78 | `infinite_recursion_function_in_setter` | 131 | 2.7s |  |
| 79 | `infinite_recursion_virtual_property` | 67 | 2.7s |  |
| 80 | `init_array_invalid` | 4 | 2.7s |  |
| 81 | `init_object_invalid` | 4 | 2.7s |  |
| 82 | `issue_1086` | 1 | 2.6s |  |
| 83 | `issue_1671` | 0 | 2.6s |  |
| 84 | `issue_3446` | 1 | 2.7s |  |
| 85 | `issue_4377` | 2 | 2.6s |  |
| 86 | `issue_710` | 4 | 2.6s |  |
| 87 | `issue_768` | 3 | 2.6s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 88 | `lessthan` | 41 | 2.7s |  |
| 89 | `lessthan2_swf5` | 1226 | 11.7s |  |
| 90 | `lessthan2_swf6` | 1226 | 11.9s |  |
| 91 | `lessthan2_swf7` | 1226 | 11.8s |  |
| 92 | `lessthan_swf4` | 902 | 7.9s |  |
| 93 | `lessthan_swf4_alt` | 41 | 2.8s |  |
| 94 | `lessthan_swf5` | 41 | 2.8s |  |
| 95 | `logical_ops_swf4` | 90 | 2.9s |  |
| 96 | `logical_ops_swf8` | 108 | 2.9s |  |
| 97 | `looping` | 6 | 2.8s |  |
| 98 | `mask_reapply` | 0 | 2.8s |  |
| 99 | `mask_with_drawing` | 0 | 2.8s |  |
| 100 | `movieclip_begin_gradient_fill` | 0 | 3.4s |  |
| 101 | `movieclip_line_gradient_style` | 0 | 3.3s |  |
| 102 | `movieclip_name_from_timeline` | 13 | 2.7s |  |
| 103 | `movieclip_prototype_extension` | 5 | 2.7s |  |
| 104 | `nested_textfields_in_buttons` | 0 | 2.7s |  |
| 105 | `new_method_wrap` | 4 | 2.7s |  |
| 106 | `new_object_enumerate` | 7 | 2.8s |  |
| 107 | `new_object_wrap` | 4 | 2.7s |  |
| 108 | `o` | 3 | 2.7s |  |
| 109 | `object_constructor` | 33 | 2.8s |  |
| 110 | `object_function` | 32 | 2.8s |  |
| 111 | `object_string_coerce_swf5` | 62 | 2.9s |  |
| 112 | `primitive_instanceof` | 37 | 2.8s |  |
| 113 | `prototype_delete` | 12 | 2.8s |  |
| 114 | `recursive_prototypes` | 0 | 2.7s |  |
| 115 | `sandbox_type_local_network` | 1 | 2.7s |  |
| 116 | `set_variable_scope` | 58 | 2.8s |  |
| 117 | `single_frame` | 1 | 2.7s |  |
| 118 | `stage_object_properties_get_var` | 5 | 2.7s |  |
| 119 | `strictequals_swf6` | 902 | 8.7s |  |
| 120 | `strictly_equals` | 7 | 2.7s |  |
| 121 | `string_coercion` | 117 | 3.3s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 122 | `string_paths_keyevents` | 0 | 2.7s |  |
| 123 | `string_paths_timer` | 0 | 2.7s |  |
| 124 | `swf4_actions_bool` | 96 | 2.9s |  |
| 125 | `swf4_bool` | 4 | 2.7s |  |
| 126 | `swf4_function_calls` | 7 | 3.7s |  |
| 127 | `swf5_encoding` | 3 | 2.9s |  |
| 128 | `swf7_case_sensitive` | 44 | 2.9s |  |
| 129 | `target_path` | 14 | 2.8s |  |
| 130 | `textfield_background_color` | 11 | 2.8s |  |
| 131 | `textfield_border_color` | 11 | 2.8s |  |
| 132 | `textfield_text` | 7 | 2.8s |  |
| 133 | `this_swf7` | 41 | 2.9s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 134 | `timeline_function_def` | 7 | 3.0s |  |
| 135 | `try_finally_simple` | 16 | 2.8s |  |
| 136 | `typeof` | 22 | 2.8s |  |
| 137 | `typeof_globals` | 7 | 2.7s |  |
| 138 | `uncaught_exception` | 1 | 2.7s |  |
| 139 | `uncaught_exception_bubbled` | 1 | 2.7s |  |
| 140 | `undefined_to_string_swf6` | 4 | 2.7s |  |
| 141 | `unescape` | 43 | 2.9s |  |
| 142 | `variable_args` | 5 | 2.9s |  |
| 143 | `waitforframe` | 7 | 2.8s |  |
| 144 | `waitforframe2` | 16 | 2.8s |  |
| 145 | `with_return` | 2 | 2.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**76 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `conflicting_instance_names` | 91.3% | 21 | 23 | 2 |  |
| 2 | `stage_object_children` | 81.9% | 68 | 83 | 15 |  |
| 3 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 4 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 5 | `textfield_properties` | 79.5% | 35 | 44 | 9 |  |
| 6 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 7 | `use_hand_cursor` | 75.0% | 6 | 8 | 2 |  |
| 8 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 9 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 10 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 11 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 12 | `point` | 70.9% | 124 | 175 | 51 |  |
| 13 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 14 | `globals_swf6` | 70.4% | 214 | 304 | 90 |  |
| 15 | `globals_swf7` | 69.4% | 211 | 304 | 93 |  |
| 16 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 17 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 18 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 19 | `stage_object_properties` | 68.5% | 165 | 241 | 76 |  |
| 20 | `stage_object_properties_swf6` | 68.4% | 158 | 231 | 73 |  |
| 21 | `globals_swf5` | 68.1% | 207 | 304 | 97 |  |
| 22 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 23 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 24 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 25 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 26 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 27 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 28 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 29 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 30 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 31 | `textfield_variable` | 65.4% | 53 | 81 | 28 |  |
| 32 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 33 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 34 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 35 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 36 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 37 | `with` | 61.2% | 30 | 49 | 19 |  |
| 38 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 39 | `edittext_scroll` | 61.1% | 33 | 54 | 21 |  |
| 40 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 41 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 42 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 43 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 44 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 45 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 46 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 47 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 48 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 49 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 50 | `remove_movie_clip` | 58.6% | 17 | 29 | 12 |  |
| 51 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 52 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 53 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 54 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 55 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 56 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 57 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 58 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 59 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 60 | `edittext_default_format_font_style` | 55.4% | 186 | 336 | 150 |  |
| 61 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 62 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 63 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 64 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 65 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 66 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 67 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 68 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 69 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 70 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 71 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 72 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 73 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 74 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 75 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 76 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 12.9s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.7s |  |
| 3 | `goto_methods` | 5.2s |  |
| 4 | `path_string` | 5.3s |  |
| 5 | `swf4_actions_coercion_order` | 5.2s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**3 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.8s |  |
| 2 | `timeout` | runtime timeout (>10s) | 12.9s |  |
| 3 | `try_catch_finally` | runtime timeout (>10s) | 13.2s |  |

## All Output Mismatches

**341 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `conflicting_instance_names` | 91.3% | 21/23 | 23 | 23 |  |
| 2 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 |  |
| 3 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 4 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 5 | `textfield_properties` | 79.5% | 35/44 | 44 | 44 |  |
| 6 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 7 | `use_hand_cursor` | 75.0% | 6/8 | 8 | 8 |  |
| 8 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 9 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 10 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 11 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 12 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 13 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 14 | `globals_swf6` | 70.4% | 214/304 | 304 | 304 |  |
| 15 | `globals_swf7` | 69.4% | 211/304 | 304 | 304 |  |
| 16 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 17 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 18 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 19 | `stage_object_properties` | 68.5% | 165/241 | 241 | 241 |  |
| 20 | `stage_object_properties_swf6` | 68.4% | 158/231 | 231 | 231 |  |
| 21 | `globals_swf5` | 68.1% | 207/304 | 304 | 304 |  |
| 22 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 23 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 24 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 25 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 26 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 27 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 28 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 29 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 30 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 31 | `textfield_variable` | 65.4% | 53/81 | 81 | 81 |  |
| 32 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 33 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 34 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 35 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 36 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 37 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 38 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 39 | `edittext_scroll` | 61.1% | 33/54 | 54 | 54 |  |
| 40 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 41 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 42 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 43 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 44 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 45 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 46 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 47 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 48 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 49 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 50 | `remove_movie_clip` | 58.6% | 17/29 | 29 | 29 |  |
| 51 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 52 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 53 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 54 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 55 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 56 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 57 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 58 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 59 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 60 | `edittext_default_format_font_style` | 55.4% | 186/336 | 336 | 335 |  |
| 61 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 62 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 63 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 64 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 65 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 66 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 67 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 68 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 69 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 70 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 71 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 72 | `issue_3522` | 50.0% | 1/2 | 1 | 2 |  |
| 73 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 74 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 75 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 76 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 77 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 78 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 79 | `frame_size_translated_negative` | 47.6% | 10/21 | 20 | 21 |  |
| 80 | `frame_size_translated_positive` | 47.6% | 10/21 | 20 | 21 |  |
| 81 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 82 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 83 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 84 | `globals_swf8` | 45.1% | 137/304 | 304 | 304 |  |
| 85 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 86 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 87 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 88 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 89 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 90 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 91 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 92 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 93 | `as2_oop` | 38.5% | 5/13 | 10 | 13 |  |
| 94 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 95 | `edittext_html_swf6` | 37.4% | 2013/5377 | 5377 | 5377 |  |
| 96 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 97 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 98 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 99 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 100 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 101 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 102 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 103 | `init_object_order` | 33.3% | 5/15 | 5 | 15 |  |
| 104 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 105 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 106 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 107 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 108 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 109 | `edittext_html_condensewhite_swf7` | 30.2% | 94/311 | 311 | 311 |  |
| 110 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 111 | `edittext_html_condensewhite_swf8` | 29.3% | 91/311 | 311 | 311 |  |
| 112 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 113 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 114 | `edittext_html_swf7` | 25.6% | 1377/5377 | 5377 | 5377 |  |
| 115 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 116 | `edittext_html_swf8` | 25.3% | 1362/5377 | 5377 | 5377 |  |
| 117 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 118 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 119 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 120 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 121 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 122 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 123 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 124 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 125 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 126 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 127 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 128 | `textfield_props_swf5` | 21.1% | 37/175 | 139 | 175 |  |
| 129 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 130 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 131 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 132 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 133 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 134 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 135 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 136 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 137 | `textfield_props_swf6` | 17.6% | 37/210 | 140 | 210 |  |
| 138 | `textfield_props_swf7` | 17.1% | 36/210 | 140 | 210 |  |
| 139 | `textfield_props_swf8` | 17.1% | 36/210 | 140 | 210 |  |
| 140 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 141 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 142 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 143 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 144 | `edittext_tag_indent` | 16.1% | 5/31 | 31 | 31 |  |
| 145 | `watch` | 15.4% | 18/117 | 100 | 117 |  |
| 146 | `as2_super_via_manual_prototype` | 15.0% | 6/40 | 16 | 40 |  |
| 147 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 148 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 149 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 150 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 151 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 152 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 153 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 154 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 155 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 156 | `movieclip_hittest_shapeflag` | 14.2% | 48/338 | 338 | 338 |  |
| 157 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 158 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 159 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 160 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 161 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 |  |
| 162 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 163 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 164 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 165 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 166 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 167 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 168 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 169 | `extends_chain` | 11.2% | 15/134 | 114 | 134 |  |
| 170 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 171 | `swf5_no_closure` | 10.5% | 2/19 | 11 | 19 |  |
| 172 | `edittext_autosize_setter` | 10.0% | 2/20 | 20 | 20 |  |
| 173 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 174 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 175 | `unload` | 9.6% | 5/52 | 48 | 52 |  |
| 176 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 177 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 178 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 179 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 180 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 181 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 182 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 183 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 184 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 185 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 186 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 187 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 188 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 189 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 190 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 191 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 192 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 193 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 194 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 195 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 196 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 197 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 198 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 199 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 200 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 201 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 202 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 203 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 204 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 205 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 206 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 207 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 208 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 209 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 210 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 211 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 212 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 213 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 214 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 215 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 216 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 217 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 218 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 219 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 220 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 221 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 222 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 223 | `global_proto_decls` | 0.0% | 1/4497 | 20 | 4497 |  |
| 224 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 225 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 226 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 227 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 228 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 229 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 230 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 231 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 232 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 233 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 234 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 235 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 236 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 237 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 238 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 239 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 240 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 241 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 242 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 243 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 244 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 245 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 246 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 247 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 248 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 249 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 250 | `extends_native_type` | 0.0% | 0/11 | 4 | 11 |  |
| 251 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 252 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 253 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 254 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 255 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 256 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 257 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 258 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 259 | `global_proto_decls_delete` | 0.0% | 0/4158 | 14 | 4158 |  |
| 260 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 261 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 262 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 263 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 264 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 265 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 266 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 267 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 268 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 269 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 270 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 271 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 272 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 273 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 274 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 275 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 276 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 277 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 278 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 279 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 280 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 281 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 282 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 283 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 284 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 285 | `native_objects_swf6` | 0.0% | 0/181 | 181 | 84 |  |
| 286 | `native_objects_swf7` | 0.0% | 0/181 | 181 | 84 |  |
| 287 | `native_objects_swf8` | 0.0% | 0/181 | 181 | 84 |  |
| 288 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 289 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 290 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 291 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 292 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 293 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 294 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 295 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 296 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 297 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 298 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 299 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 300 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 301 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 302 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 303 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 304 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 305 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 306 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 307 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 308 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 309 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 310 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 311 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 312 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 313 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 314 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 315 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 316 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 317 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 318 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 319 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 320 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 321 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 322 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 323 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 324 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 325 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 326 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 327 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 328 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 329 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 330 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 331 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 332 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 333 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 334 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 335 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 336 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 337 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 338 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 339 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 340 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 341 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
