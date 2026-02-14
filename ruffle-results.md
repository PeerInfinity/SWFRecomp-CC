# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-14 01:57 UTC

**Git SHA**: `25cbff5264`

**Run Duration**: 34m 32s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **152** (24.6%) |
| Failing | 467 |
| Total expected lines | 91286 |
| Matching lines | 34082 (37.3%) |
| Mismatched lines | 57204 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 459 | 98.3% |
| Runtime Segfault | 5 | 1.1% |
| Timeout | 3 | 0.6% |

## Passing Tests

**152 tests passing**

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
| 57 | `focusrect_mouse_swf8` | 0 | 2.9s |  |
| 58 | `focusrect_mouse_swf9` | 0 | 2.9s |  |
| 59 | `focusrect_swf5` | 6 | 3.3s |  |
| 60 | `get_variable_in_scope` | 29 | 3.1s |  |
| 61 | `getproperty` | 28 | 3.0s |  |
| 62 | `getproperty_swf4` | 28 | 3.0s |  |
| 63 | `getproperty_swf5` | 28 | 3.0s |  |
| 64 | `global_array` | 3 | 2.9s |  |
| 65 | `global_is_bare` | 7 | 2.9s |  |
| 66 | `goto_advance1` | 6 | 2.9s |  |
| 67 | `goto_advance2` | 2 | 3.0s |  |
| 68 | `goto_both_ways1` | 3 | 2.8s |  |
| 69 | `goto_both_ways2` | 3 | 2.7s |  |
| 70 | `goto_execution_order` | 2 | 2.6s |  |
| 71 | `goto_execution_order2` | 2 | 2.6s |  |
| 72 | `goto_frame_number` | 3 | 2.8s |  |
| 73 | `goto_rewind1` | 1 | 2.8s |  |
| 74 | `goto_rewind2` | 3 | 2.8s |  |
| 75 | `goto_rewind3` | 2 | 2.7s |  |
| 76 | `greater_swf6` | 1175 | 11.1s |  |
| 77 | `greater_swf7` | 1175 | 11.1s |  |
| 78 | `greaterthan_swf5` | 1 | 2.6s |  |
| 79 | `greaterthan_swf8` | 1 | 2.6s |  |
| 80 | `has_own_property` | 32 | 2.8s |  |
| 81 | `infinite_recursion_function` | 4 | 2.7s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 82 | `infinite_recursion_function_in_setter` | 131 | 2.7s |  |
| 83 | `infinite_recursion_virtual_property` | 67 | 2.7s |  |
| 84 | `init_array_invalid` | 4 | 2.7s |  |
| 85 | `init_object_invalid` | 4 | 2.7s |  |
| 86 | `issue_1086` | 1 | 2.6s |  |
| 87 | `issue_1671` | 0 | 2.6s |  |
| 88 | `issue_3446` | 1 | 2.7s |  |
| 89 | `issue_4377` | 2 | 2.6s |  |
| 90 | `issue_710` | 4 | 2.6s |  |
| 91 | `issue_768` | 3 | 2.6s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 92 | `lessthan` | 41 | 2.7s |  |
| 93 | `lessthan2_swf5` | 1226 | 11.7s |  |
| 94 | `lessthan2_swf6` | 1226 | 11.9s |  |
| 95 | `lessthan2_swf7` | 1226 | 11.8s |  |
| 96 | `lessthan_swf4` | 902 | 7.9s |  |
| 97 | `lessthan_swf4_alt` | 41 | 2.8s |  |
| 98 | `lessthan_swf5` | 41 | 2.8s |  |
| 99 | `logical_ops_swf4` | 90 | 2.9s |  |
| 100 | `logical_ops_swf8` | 108 | 2.9s |  |
| 101 | `looping` | 6 | 2.8s |  |
| 102 | `mask_reapply` | 0 | 2.8s |  |
| 103 | `mask_with_drawing` | 0 | 2.8s |  |
| 104 | `movieclip_begin_gradient_fill` | 0 | 3.4s |  |
| 105 | `movieclip_line_gradient_style` | 0 | 3.3s |  |
| 106 | `movieclip_name_from_timeline` | 13 | 2.7s |  |
| 107 | `movieclip_prototype_extension` | 5 | 2.7s |  |
| 108 | `nested_textfields_in_buttons` | 0 | 2.7s |  |
| 109 | `netstream_play_flv_screen` | 0 | 30.1s |  |
| 110 | `new_method_wrap` | 4 | 2.7s |  |
| 111 | `new_object_enumerate` | 7 | 2.8s |  |
| 112 | `new_object_wrap` | 4 | 2.7s |  |
| 113 | `o` | 3 | 2.7s |  |
| 114 | `object_constructor` | 33 | 2.8s |  |
| 115 | `object_function` | 32 | 2.8s |  |
| 116 | `object_string_coerce_swf5` | 62 | 2.9s |  |
| 117 | `primitive_instanceof` | 37 | 2.8s |  |
| 118 | `prototype_delete` | 12 | 2.8s |  |
| 119 | `recursive_prototypes` | 0 | 2.7s |  |
| 120 | `sandbox_type_local_network` | 1 | 2.7s |  |
| 121 | `set_variable_scope` | 58 | 2.8s |  |
| 122 | `single_frame` | 1 | 2.7s |  |
| 123 | `sound_start_load` | 0 | 2.7s |  |
| 124 | `stage_object_properties_get_var` | 5 | 2.7s |  |
| 125 | `strictequals_swf6` | 902 | 8.7s |  |
| 126 | `strictly_equals` | 7 | 2.7s |  |
| 127 | `string_coercion` | 117 | 3.3s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 128 | `string_paths_keyevents` | 0 | 2.7s |  |
| 129 | `string_paths_timer` | 0 | 2.7s |  |
| 130 | `swf4_actions_bool` | 96 | 2.9s |  |
| 131 | `swf4_bool` | 4 | 2.7s |  |
| 132 | `swf4_function_calls` | 7 | 3.7s |  |
| 133 | `swf5_encoding` | 3 | 2.9s |  |
| 134 | `swf7_case_sensitive` | 44 | 2.9s |  |
| 135 | `tab_ordering_properties_tab_index_edge_case` | 4 | 2.8s |  |
| 136 | `target_path` | 14 | 2.8s |  |
| 137 | `textfield_background_color` | 11 | 2.8s |  |
| 138 | `textfield_border_color` | 11 | 2.8s |  |
| 139 | `textfield_text` | 7 | 2.8s |  |
| 140 | `this_swf7` | 41 | 2.9s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 141 | `timeline_function_def` | 7 | 3.0s |  |
| 142 | `try_finally_simple` | 16 | 2.8s |  |
| 143 | `typeof` | 22 | 2.8s |  |
| 144 | `typeof_globals` | 7 | 2.7s |  |
| 145 | `uncaught_exception` | 1 | 2.7s |  |
| 146 | `uncaught_exception_bubbled` | 1 | 2.7s |  |
| 147 | `undefined_to_string_swf6` | 4 | 2.7s |  |
| 148 | `unescape` | 43 | 2.9s |  |
| 149 | `variable_args` | 5 | 2.9s |  |
| 150 | `waitforframe` | 7 | 2.8s |  |
| 151 | `waitforframe2` | 16 | 2.8s |  |
| 152 | `with_return` | 2 | 2.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**86 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `conflicting_instance_names` | 91.3% | 21 | 23 | 2 |  |
| 2 | `stage_object_children` | 81.9% | 68 | 83 | 15 |  |
| 3 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 4 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 5 | `textfield_properties` | 79.5% | 35 | 44 | 9 |  |
| 6 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 7 | `bitmap_data_max_size_swf10` | 75.0% | 9 | 12 | 3 |  |
| 8 | `use_hand_cursor` | 75.0% | 6 | 8 | 2 |  |
| 9 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 10 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 11 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 12 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 13 | `point` | 70.9% | 124 | 175 | 51 |  |
| 14 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 15 | `globals_swf6` | 70.4% | 214 | 304 | 90 |  |
| 16 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 17 | `globals_swf7` | 69.4% | 211 | 304 | 93 |  |
| 18 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 19 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 20 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 21 | `stage_object_properties` | 68.5% | 165 | 241 | 76 |  |
| 22 | `stage_object_properties_swf6` | 68.4% | 158 | 231 | 73 |  |
| 23 | `globals_swf5` | 68.1% | 207 | 304 | 97 |  |
| 24 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 25 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 26 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 27 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 28 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 29 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 30 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 31 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 32 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 33 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 34 | `textfield_variable` | 65.4% | 53 | 81 | 28 |  |
| 35 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 36 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 37 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
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
| 50 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 51 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 52 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 53 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 54 | `remove_movie_clip` | 58.6% | 17 | 29 | 12 |  |
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
| 65 | `edittext_default_format_font_style` | 55.4% | 186 | 336 | 150 |  |
| 66 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 67 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 68 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 69 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 70 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 71 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 72 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 73 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 74 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 75 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 76 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 77 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 78 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 79 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 80 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 81 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 82 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 83 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 84 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 85 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 86 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

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

**459 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `conflicting_instance_names` | 91.3% | 21/23 | 23 | 23 |  |
| 2 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 |  |
| 3 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 4 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 5 | `textfield_properties` | 79.5% | 35/44 | 44 | 44 |  |
| 6 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 7 | `bitmap_data_max_size_swf10` | 75.0% | 9/12 | 12 | 12 |  |
| 8 | `use_hand_cursor` | 75.0% | 6/8 | 8 | 8 |  |
| 9 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 10 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 11 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 12 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 13 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 14 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 15 | `globals_swf6` | 70.4% | 214/304 | 304 | 304 |  |
| 16 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 17 | `globals_swf7` | 69.4% | 211/304 | 304 | 304 |  |
| 18 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 19 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 20 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 21 | `stage_object_properties` | 68.5% | 165/241 | 241 | 241 |  |
| 22 | `stage_object_properties_swf6` | 68.4% | 158/231 | 231 | 231 |  |
| 23 | `globals_swf5` | 68.1% | 207/304 | 304 | 304 |  |
| 24 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 25 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 26 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 27 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 28 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 29 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 30 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 31 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 32 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 33 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 34 | `textfield_variable` | 65.4% | 53/81 | 81 | 81 |  |
| 35 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 36 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 37 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
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
| 50 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 51 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 52 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 53 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 54 | `remove_movie_clip` | 58.6% | 17/29 | 29 | 29 |  |
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
| 65 | `edittext_default_format_font_style` | 55.4% | 186/336 | 336 | 335 |  |
| 66 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 67 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 68 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 69 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 70 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 71 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 72 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 73 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 74 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 75 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 76 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 77 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 78 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 79 | `issue_3522` | 50.0% | 1/2 | 1 | 2 |  |
| 80 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 81 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 82 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 83 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 84 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 85 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 86 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 87 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 88 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 89 | `frame_size_translated_negative` | 47.6% | 10/21 | 20 | 21 |  |
| 90 | `frame_size_translated_positive` | 47.6% | 10/21 | 20 | 21 |  |
| 91 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 92 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 93 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 94 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 95 | `globals_swf8` | 45.1% | 137/304 | 304 | 304 |  |
| 96 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 97 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 98 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 99 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 100 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 101 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 102 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 103 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 104 | `as2_oop` | 38.5% | 5/13 | 10 | 13 |  |
| 105 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 106 | `edittext_html_swf6` | 37.4% | 2013/5377 | 5377 | 5377 |  |
| 107 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 108 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 109 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 110 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 111 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 112 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 113 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 114 | `init_object_order` | 33.3% | 5/15 | 5 | 15 |  |
| 115 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 116 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 117 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 118 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 119 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 120 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 121 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 122 | `edittext_html_condensewhite_swf7` | 30.2% | 94/311 | 311 | 311 |  |
| 123 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 124 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 125 | `edittext_html_condensewhite_swf8` | 29.3% | 91/311 | 311 | 311 |  |
| 126 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 127 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 128 | `edittext_html_swf7` | 25.6% | 1377/5377 | 5377 | 5377 |  |
| 129 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 130 | `edittext_html_swf8` | 25.3% | 1362/5377 | 5377 | 5377 |  |
| 131 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 132 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 133 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 134 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 135 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 136 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 137 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 138 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 139 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 140 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 141 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 142 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 143 | `textfield_props_swf5` | 21.1% | 37/175 | 139 | 175 |  |
| 144 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 145 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 146 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 147 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 148 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 149 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 150 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 151 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 152 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 153 | `textfield_props_swf6` | 17.6% | 37/210 | 140 | 210 |  |
| 154 | `textfield_props_swf7` | 17.1% | 36/210 | 140 | 210 |  |
| 155 | `textfield_props_swf8` | 17.1% | 36/210 | 140 | 210 |  |
| 156 | `focusrect_property_swf5` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 157 | `focusrect_property_swf6` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 158 | `focusrect_property_swf7` | 16.9% | 209/1237 | 1236 | 1237 |  |
| 159 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 160 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 161 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 162 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 163 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 164 | `edittext_tag_indent` | 16.1% | 5/31 | 31 | 31 |  |
| 165 | `watch` | 15.4% | 18/117 | 100 | 117 |  |
| 166 | `as2_super_via_manual_prototype` | 15.0% | 6/40 | 16 | 40 |  |
| 167 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 168 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 169 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 170 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 171 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 172 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 173 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 174 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 175 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 176 | `movieclip_hittest_shapeflag` | 14.2% | 48/338 | 338 | 338 |  |
| 177 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 178 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 179 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 180 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 181 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 |  |
| 182 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 183 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 184 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 185 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 186 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 187 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 188 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 189 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 190 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 191 | `extends_chain` | 11.2% | 15/134 | 114 | 134 |  |
| 192 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 193 | `swf5_no_closure` | 10.5% | 2/19 | 11 | 19 |  |
| 194 | `edittext_autosize_setter` | 10.0% | 2/20 | 20 | 20 |  |
| 195 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 196 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 197 | `unload` | 9.6% | 5/52 | 48 | 52 |  |
| 198 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 199 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 200 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 201 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 202 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 203 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 204 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 205 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 206 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 207 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 208 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 209 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 210 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 211 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 212 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 213 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 214 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 215 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 216 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 217 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 218 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 219 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 220 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 221 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 222 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 223 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 224 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 225 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 226 | `bitmap_data` | 4.1% | 46/1126 | 318 | 1126 |  |
| 227 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 228 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 229 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 230 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 231 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 232 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 233 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 234 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 235 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 236 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 237 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 238 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 239 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 240 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 241 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 242 | `tab_ordering_properties` | 1.7% | 5/293 | 180 | 293 |  |
| 243 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 244 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 245 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 246 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 247 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 248 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 249 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 250 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 251 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 252 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 253 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 254 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 255 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 256 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 257 | `global_proto_decls` | 0.0% | 1/4497 | 20 | 4497 |  |
| 258 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 259 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 260 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 261 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 262 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 263 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 264 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 265 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 266 | `bitmap_data_copypixels` | 0.0% | 0/17 | 0 | 17 |  |
| 267 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 0 | 1075 |  |
| 268 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 269 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 270 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 271 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 272 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 273 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 274 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 275 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 276 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 277 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 278 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 279 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 280 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 281 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 282 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 283 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 284 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 285 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 286 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 287 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 288 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 289 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 290 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 291 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 292 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 293 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 294 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 295 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 296 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 297 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 298 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 299 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 300 | `edittext_password` | 0.0% | 0/5 | 5 | 5 |  |
| 301 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 302 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 303 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 304 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 305 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 306 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 307 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 308 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 309 | `extends_native_type` | 0.0% | 0/11 | 4 | 11 |  |
| 310 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 311 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 312 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 313 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 314 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 315 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 316 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 317 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 318 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 319 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 320 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 321 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 322 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 323 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 324 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 325 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 326 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 327 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 328 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 329 | `global_proto_decls_delete` | 0.0% | 0/4158 | 14 | 4158 |  |
| 330 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 331 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 332 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 333 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 334 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 335 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 336 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 337 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 338 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 339 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 340 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 341 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 342 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 343 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 344 | `loadmovie_fail` | 0.0% | 0/2 | 0 | 2 |  |
| 345 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 346 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 347 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 0 | 9 |  |
| 348 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 349 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 350 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 351 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 352 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 353 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 354 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 355 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 356 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 357 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 358 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 359 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 360 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 361 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 362 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 363 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 364 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 365 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 366 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 367 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 368 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 369 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 370 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 371 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 372 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 373 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 374 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 375 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 376 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 377 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 378 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 379 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 380 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 381 | `native_objects_swf6` | 0.0% | 0/181 | 181 | 84 |  |
| 382 | `native_objects_swf7` | 0.0% | 0/181 | 181 | 84 |  |
| 383 | `native_objects_swf8` | 0.0% | 0/181 | 181 | 84 |  |
| 384 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 385 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 386 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 387 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 388 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 389 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 390 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 391 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 392 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 393 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 394 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 395 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 396 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 397 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 398 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 399 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 400 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 401 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 402 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 403 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 404 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 405 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 406 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 407 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 408 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 409 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 410 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 411 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 412 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 413 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 414 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 415 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 416 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 417 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 418 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 419 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 420 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 421 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 422 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 423 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 424 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 425 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 426 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 427 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 428 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 429 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 430 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 431 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 432 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 433 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 434 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 435 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 436 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 437 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 438 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 439 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 440 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 441 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 442 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 443 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 444 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 445 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 446 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 447 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 448 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 449 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 450 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 451 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 452 | `xml_socket` | 0.0% | 0/8 | 0 | 8 |  |
| 453 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 454 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 455 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
| 456 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 457 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 458 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 459 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
