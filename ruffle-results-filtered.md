# Ruffle Test Results (Filtered)

**Date**: 2026-02-24 00:26 UTC

**Git SHA**: `a3b4b418e4`

**Run Duration**: 89m 40s

**Filtered**: 140 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 479 |
| Passing | **294** (61.4%) |
| Failing | 185 |
| Total expected lines | 71494 |
| Matching lines | 46238 (64.7%) |
| Mismatched lines | 25256 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 177 | 95.7% |
| Segfault | 5 | 2.7% |
| Runtime Error | 2 | 1.1% |
| Timeout | 1 | 0.5% |

## Passing Tests

**294 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 8.5s |  |
| 2 | `action_to_integer` | 28 | 8.3s |  |
| 3 | `add` | 28 | 8.3s |  |
| 4 | `add2` | 354 | 8.6s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_swf4` | 28 | 8.3s |  |
| 6 | `add_swf5` | 28 | 8.3s |  |
| 7 | `arguments` | 127 | 8.3s | [10](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [21](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 8.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 8.3s |  |
| 10 | `array_constructor` | 30 | 8.4s |  |
| 11 | `array_enumerate` | 4 | 8.3s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 8.3s |  |
| 13 | `array_properties` | 36 | 8.3s |  |
| 14 | `array_prototyping` | 12 | 8.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 8.4s |  |
| 16 | `array_sort_random` | 443 | 8.4s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_splice` | 207 | 8.5s |  |
| 18 | `array_trivial` | 209 | 8.4s |  |
| 19 | `as1_constructor_v6` | 35 | 8.4s |  |
| 20 | `as1_constructor_v7` | 35 | 8.4s |  |
| 21 | `as2_oop` | 13 | 8.5s | [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 22 | `as_broadcaster_initialize` | 10 | 8.5s |  |
| 23 | `as_set_prop_flags_version` | 31 | 8.2s | [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `as_set_prop_flags_version_swf5` | 1 | 8.2s |  |
| 25 | `as_set_prop_flags_version_swf6` | 1 | 8.3s |  |
| 26 | `as_set_prop_flags_version_swf7` | 1 | 8.2s |  |
| 27 | `as_set_prop_flags_version_swf8` | 1 | 8.2s |  |
| 28 | `as_set_prop_flags_version_swf9` | 1 | 8.3s |  |
| 29 | `as_transformed_flag` | 20 | 8.3s |  |
| 30 | `attach_movie` | 59 | 8.3s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 31 | `attach_movie_stop` | 3 | 8.2s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 32 | `bad_swf_tag_past_eof` | 0 | 8.7s |  |
| 33 | `bitand` | 1058 | 11.8s |  |
| 34 | `bitmap_data_colortransform` | 0 | 9.0s |  |
| 35 | `bitmap_data_fillrect` | 0 | 8.7s |  |
| 36 | `bitmap_data_max_size_swf10` | 12 | 8.6s |  |
| 37 | `bitmap_data_max_size_swf9` | 10 | 8.6s |  |
| 38 | `bitmap_data_perlinnoise` | 0 | 9.1s |  |
| 39 | `bitmap_data_pixeldissolve_image` | 0 | 9.1s |  |
| 40 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.8s |  |
| 41 | `bitor` | 1058 | 11.5s |  |
| 42 | `biturshift` | 14 | 8.6s |  |
| 43 | `biturshift_swf8` | 14 | 10.0s |  |
| 44 | `bitxor` | 1058 | 11.6s |  |
| 45 | `boxed_primitives` | 24 | 8.8s | [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 46 | `button_children` | 8 | 8.7s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 47 | `button_goto` | 4 | 8.8s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 48 | `button_order` | 2 | 8.5s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 49 | `button_v5` | 18 | 8.8s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 50 | `button_v6` | 18 | 8.6s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 51 | `call_method_empty_name` | 1 | 8.5s |  |
| 52 | `capabilities_resolution` | 8 | 8.4s |  |
| 53 | `catch_references_registers` | 2 | 8.5s | [34](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 54 | `clip_events` | 19 | 8.8s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 55 | `clone_sprite_types` | 24 | 8.3s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 56 | `closure_scope` | 7 | 8.5s | [36](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 57 | `color` | 57 | 8.5s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 58 | `color_transform` | 48 | 8.4s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 59 | `conflicting_instance_names` | 23 | 8.4s |  |
| 60 | `create_empty_movie_clip` | 3 | 8.4s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 61 | `define_function2` | 8 | 8.3s |  |
| 62 | `define_function2_preload` | 13 | 8.4s |  |
| 63 | `define_function2_preload_order` | 4 | 10.5s |  |
| 64 | `define_function_case_sensitive` | 2 | 8.3s |  |
| 65 | `delete` | 3 | 8.4s |  |
| 66 | `display_object_properties` | 2 | 8.2s |  |
| 67 | `divide_swf4` | 107 | 8.3s |  |
| 68 | `do_init_action` | 3 | 8.3s |  |
| 69 | `duplicate_movie_clip` | 20 | 8.4s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 70 | `edittext_antialiastype` | 296 | 8.5s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 71 | `edittext_autosize_setter` | 20 | 8.7s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 72 | `edittext_default_format` | 221 | 8.4s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 73 | `edittext_default_format_empty` | 95 | 8.3s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 74 | `edittext_default_format_font_style` | 335 | 8.3s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 75 | `edittext_html_align_swf7` | 52 | 8.4s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 76 | `edittext_html_align_swf8` | 52 | 8.4s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 77 | `edittext_html_entity` | 4 | 8.3s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `edittext_newline_stripping` | 64 | 12.9s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 79 | `edittext_width_height` | 103 | 8.2s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 80 | `empty_movieclip_can_attach_movies` | 11 | 9.2s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 81 | `enumerate` | 64 | 8.4s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 82 | `equals` | 32 | 8.4s |  |
| 83 | `equals2_swf5` | 926 | 10.2s |  |
| 84 | `equals2_swf6` | 926 | 10.2s |  |
| 85 | `equals2_swf7` | 926 | 10.2s |  |
| 86 | `equals_swf4` | 665 | 9.2s |  |
| 87 | `equals_swf4_alt` | 32 | 8.3s |  |
| 88 | `equals_swf5` | 32 | 8.4s |  |
| 89 | `error` | 58 | 8.3s |  |
| 90 | `escape` | 14 | 8.3s |  |
| 91 | `execution_order1` | 5 | 8.5s |  |
| 92 | `execution_order2` | 7 | 8.4s |  |
| 93 | `execution_order3` | 4 | 8.4s |  |
| 94 | `export_assets` | 3 | 8.5s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 95 | `extends_native_type` | 11 | 8.6s | [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 96 | `focusrect_mouse_swf8` | 0 | 8.6s |  |
| 97 | `focusrect_mouse_swf9` | 0 | 8.7s |  |
| 98 | `focusrect_swf5` | 6 | 8.4s | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 99 | `function_suppress_and_preload` | 28 | 8.3s |  |
| 100 | `get_variable_in_scope` | 29 | 8.3s |  |
| 101 | `getproperty` | 28 | 8.2s |  |
| 102 | `getproperty_swf4` | 28 | 8.3s |  |
| 103 | `getproperty_swf5` | 28 | 8.1s |  |
| 104 | `global_array` | 3 | 8.1s |  |
| 105 | `global_is_bare` | 7 | 8.0s |  |
| 106 | `globals_swf5` | 304 | 8.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 107 | `globals_swf6` | 304 | 8.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 108 | `globals_swf7` | 304 | 8.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 109 | `globals_swf8` | 304 | 8.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 110 | `goto_advance1` | 6 | 8.0s |  |
| 111 | `goto_advance2` | 2 | 8.0s |  |
| 112 | `goto_both_ways1` | 3 | 8.0s |  |
| 113 | `goto_both_ways2` | 3 | 8.0s |  |
| 114 | `goto_execution_order` | 2 | 8.0s |  |
| 115 | `goto_execution_order2` | 2 | 8.0s |  |
| 116 | `goto_frame_number` | 3 | 8.4s |  |
| 117 | `goto_rewind1` | 1 | 8.6s |  |
| 118 | `goto_rewind2` | 3 | 8.3s |  |
| 119 | `goto_rewind3` | 2 | 8.3s |  |
| 120 | `greater_swf6` | 1175 | 10.2s |  |
| 121 | `greater_swf7` | 1175 | 10.2s |  |
| 122 | `greaterthan_swf5` | 1 | 8.2s |  |
| 123 | `greaterthan_swf8` | 1 | 8.2s |  |
| 124 | `has_own_property` | 32 | 8.2s |  |
| 125 | `hittest_lockroot` | 15 | 8.4s |  |
| 126 | `hittest_winding_rule` | 12 | 8.2s |  |
| 127 | `infinite_recursion_function` | 4 | 8.2s | [12](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 128 | `infinite_recursion_function_in_setter` | 131 | 8.2s | [12](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 129 | `infinite_recursion_virtual_property` | 67 | 8.2s | [12](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 130 | `init_array_invalid` | 4 | 8.2s |  |
| 131 | `init_object_invalid` | 4 | 10.2s |  |
| 132 | `is_finite` | 49 | 8.8s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 133 | `is_finite_swf6` | 49 | 8.8s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 134 | `is_prototype_of` | 89 | 9.0s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 135 | `issue_1086` | 1 | 8.7s |  |
| 136 | `issue_1671` | 0 | 8.8s |  |
| 137 | `issue_1906` | 4 | 8.9s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 138 | `issue_2166` | 9 | 10.0s |  |
| 139 | `issue_3446` | 1 | 8.7s |  |
| 140 | `issue_3522` | 2 | 8.6s |  |
| 141 | `issue_4377` | 2 | 8.6s |  |
| 142 | `issue_710` | 4 | 8.6s |  |
| 143 | `issue_768` | 3 | 9.7s | [13](ruffle-tests/_investigation/complete/issue_768.md) |
| 144 | `issue_9327` | 2 | 8.2s |  |
| 145 | `issue_9885` | 2 | 8.3s |  |
| 146 | `lessthan` | 41 | 8.3s |  |
| 147 | `lessthan2_swf5` | 1226 | 10.4s |  |
| 148 | `lessthan2_swf6` | 1226 | 10.4s |  |
| 149 | `lessthan2_swf7` | 1226 | 10.3s |  |
| 150 | `lessthan_swf4` | 902 | 9.4s |  |
| 151 | `lessthan_swf4_alt` | 41 | 8.2s |  |
| 152 | `lessthan_swf5` | 41 | 8.2s |  |
| 153 | `local_to_global` | 49 | 8.6s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 154 | `localconnection_properties` | 8 | 8.5s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 155 | `logical_ops_swf4` | 90 | 8.6s |  |
| 156 | `logical_ops_swf8` | 108 | 8.5s |  |
| 157 | `looping` | 6 | 8.6s |  |
| 158 | `mask_reapply` | 0 | 8.5s |  |
| 159 | `mask_with_drawing` | 0 | 8.5s |  |
| 160 | `math_min_max` | 101 | 8.7s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 161 | `math_swf6` | 530 | 9.1s | [14](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 162 | `math_swf7` | 530 | 8.8s | [14](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 163 | `math_swf8` | 530 | 8.7s | [14](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 164 | `matrix` | 171 | 8.8s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [10](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 165 | `movieclip_begin_gradient_fill` | 0 | 9.0s |  |
| 166 | `movieclip_blend_mode_property` | 35 | 9.1s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 167 | `movieclip_default_state` | 69 | 8.7s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 168 | `movieclip_depth_methods` | 98 | 8.7s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 169 | `movieclip_focusenabled` | 99 | 8.5s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 170 | `movieclip_get_instance_at_depth` | 28 | 8.5s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 171 | `movieclip_hittest` | 92 | 8.5s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 172 | `movieclip_line_gradient_style` | 0 | 9.2s |  |
| 173 | `movieclip_name_from_timeline` | 13 | 8.4s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 174 | `movieclip_prototype_extension` | 5 | 8.4s |  |
| 175 | `nested_textfields_in_buttons` | 0 | 8.4s |  |
| 176 | `netstream_play_flv_screen` | 0 | 21.1s |  |
| 177 | `new_method_wrap` | 4 | 8.4s |  |
| 178 | `new_object_enumerate` | 7 | 8.4s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 179 | `new_object_wrap` | 4 | 8.4s |  |
| 180 | `o` | 3 | 8.4s |  |
| 181 | `object_constructor` | 33 | 8.5s |  |
| 182 | `object_function` | 32 | 8.4s |  |
| 183 | `object_properties` | 31 | 8.6s | [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 184 | `object_prototypes` | 74 | 8.5s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 185 | `object_string_coerce_swf5` | 62 | 8.4s | [18](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 186 | `object_string_coerce_swf6` | 68 | 8.5s | [18](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 187 | `parse_int` | 64 | 8.6s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [21](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 188 | `placeobject_occupied_depth` | 6 | 8.5s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 189 | `point` | 175 | 8.8s | [10](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 190 | `primitive_instanceof` | 37 | 8.5s |  |
| 191 | `primitive_type_globals` | 557 | 8.8s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 192 | `printjob_props_swf5` | 45 | 8.4s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 193 | `printjob_props_swf6` | 45 | 8.3s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 194 | `printjob_props_swf7` | 45 | 8.2s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 195 | `prototype_delete` | 12 | 8.2s |  |
| 196 | `prototype_enumerate` | 5 | 8.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 197 | `prototype_properties` | 17 | 8.3s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 198 | `rectangle` | 745 | 9.0s | [10](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 199 | `recursive_prototypes` | 0 | 8.2s |  |
| 200 | `remove_movie_clip` | 29 | 8.3s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 201 | `root_onload` | 1 | 8.1s |  |
| 202 | `sandbox_type_local_file` | 1 | 8.2s |  |
| 203 | `sandbox_type_local_network` | 1 | 8.2s |  |
| 204 | `set_variable_scope` | 58 | 8.2s |  |
| 205 | `single_frame` | 1 | 8.1s |  |
| 206 | `slash_syntax` | 14 | 8.2s | [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 207 | `sound_props_swf5` | 68 | 8.3s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 208 | `sound_props_swf6` | 68 | 8.3s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 209 | `sound_start_load` | 0 | 8.3s |  |
| 210 | `stage_display_state` | 16 | 8.3s | [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 211 | `stage_object_enumerate` | 4 | 8.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 212 | `stage_object_properties` | 241 | 8.6s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 213 | `stage_object_properties_get_var` | 5 | 8.2s |  |
| 214 | `stage_property_representation` | 586 | 8.2s | [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 215 | `stage_scale_mode` | 39 | 8.2s | [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 216 | `strictequals_swf6` | 902 | 9.7s |  |
| 217 | `strictly_equals` | 7 | 8.2s |  |
| 218 | `string_coercion` | 117 | 8.5s | [27](ruffle-tests/_investigation/complete/string_coercion.md) |
| 219 | `string_methods` | 285 | 8.8s | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 220 | `string_methods_negative_args` | 240 | 8.5s | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 221 | `string_methods_swfv5` | 275 | 8.8s | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 222 | `string_ops_swf6` | 95 | 8.3s | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 223 | `string_paths_basic` | 4 | 8.2s | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 224 | `string_paths_timer` | 0 | 8.5s |  |
| 225 | `string_paths_variable_alias` | 4 | 8.4s | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 226 | `swf4_actions_bool` | 96 | 8.8s |  |
| 227 | `swf4_bool` | 4 | 8.7s |  |
| 228 | `swf4_function_calls` | 7 | 8.6s |  |
| 229 | `swf5_encoding` | 3 | 8.6s |  |
| 230 | `swf7_case_sensitive` | 44 | 8.6s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 231 | `tab_ordering_properties_tab_index_edge_case` | 4 | 8.4s |  |
| 232 | `target_clip_removed` | 5 | 8.4s | [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 233 | `target_path` | 14 | 8.2s |  |
| 234 | `text_format` | 1146 | 8.5s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 235 | `text_format_display` | 21 | 8.3s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 236 | `text_format_font_max_length` | 2 | 8.2s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 237 | `text_format_rounding_swf7` | 840 | 8.4s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 238 | `text_format_rounding_swf8` | 840 | 8.4s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 239 | `textfield_background_color` | 11 | 8.3s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 240 | `textfield_border_color` | 11 | 8.2s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 241 | `textfield_maxchars` | 3 | 8.5s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 242 | `textfield_properties` | 44 | 8.4s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 243 | `textfield_props_swf5` | 175 | 8.5s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 244 | `textfield_props_swf6` | 210 | 8.5s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 245 | `textfield_props_swf7` | 210 | 8.5s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 246 | `textfield_props_swf8` | 210 | 8.5s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 247 | `textfield_text` | 7 | 8.3s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 248 | `textfield_variable` | 81 | 8.5s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 249 | `this_swf7` | 41 | 8.3s | [32](ruffle-tests/_investigation/complete/this_swf7.md) |
| 250 | `timeline_function_def` | 7 | 8.4s |  |
| 251 | `transform` | 70 | 8.9s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 252 | `try_catch_finally` | 118 | 8.8s | [34](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 253 | `try_finally_simple` | 16 | 8.6s | [34](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 254 | `typeof` | 22 | 8.6s |  |
| 255 | `typeof_globals` | 7 | 8.6s |  |
| 256 | `uncaught_exception` | 1 | 8.6s | [34](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 257 | `uncaught_exception_bubbled` | 1 | 8.6s | [34](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 258 | `undefined_to_string_swf6` | 4 | 8.6s |  |
| 259 | `unescape` | 43 | 8.6s |  |
| 260 | `unload_clip_event` | 4 | 8.6s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 261 | `use_hand_cursor` | 8 | 8.6s |  |
| 262 | `variable_args` | 5 | 8.7s |  |
| 263 | `waitforframe` | 7 | 8.6s |  |
| 264 | `waitforframe2` | 16 | 9.1s |  |
| 265 | `watch` | 117 | 9.1s | [19](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 266 | `watch_virtual_property_proto` | 2 | 8.8s | [19](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 267 | `with` | 49 | 8.9s | [36](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 268 | `with_return` | 2 | 8.8s |  |
| 269 | `with_variable_scopes` | 43 | 8.9s | [36](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 270 | `xml` | 15 | 8.9s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 271 | `xml_append_child` | 28 | 8.7s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 272 | `xml_append_child_with_parent` | 20 | 8.7s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 273 | `xml_cdata` | 11 | 8.7s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 274 | `xml_child_nodes_edge_cases` | 4 | 8.8s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 275 | `xml_clone_expandos` | 19 | 8.8s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 276 | `xml_first_last_child` | 8 | 8.8s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 277 | `xml_has_child_nodes` | 3 | 8.7s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 278 | `xml_idmap` | 21 | 8.9s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 279 | `xml_ignore_comments` | 21 | 8.8s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 280 | `xml_ignore_white` | 34 | 8.3s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 281 | `xml_insert_before` | 20 | 8.1s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 282 | `xml_inspect_createmethods` | 15 | 8.1s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 283 | `xml_inspect_doctype` | 7 | 8.1s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 284 | `xml_inspect_parsexml` | 62 | 8.1s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 285 | `xml_inspect_xmldecl` | 7 | 8.0s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 286 | `xml_namespaces` | 203 | 8.0s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 287 | `xml_parent_and_child` | 5 | 8.0s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 288 | `xml_remove_node` | 22 | 8.0s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 289 | `xml_reparenting` | 14 | 8.1s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 290 | `xml_siblings` | 10 | 8.0s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 291 | `xml_to_string` | 13 | 8.1s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 292 | `xml_to_string_comment` | 1 | 8.0s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 293 | `xml_unescaping` | 23 | 8.1s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 294 | `xmlnode_proto` | 1 | 8.1s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**52 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stage_object_properties_swf6` | 99.1% | 229 | 231 | 2 | [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `hittest_morph` | 95.7% | 67 | 70 | 3 |  |
| 4 | `selection` | 95.6% | 434 | 454 | 20 | [24](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 5 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `button_properties_special_cases` | 86.4% | 19 | 22 | 3 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 8 | `string_paths_other` | 86.1% | 31 | 36 | 5 | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 9 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 10 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 11 | `this_scoping` | 80.8% | 42 | 52 | 10 | [36](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 12 | `movieclip_hittest_shapeflag` | 78.7% | 266 | 338 | 72 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 14 | `edittext_scroll` | 74.1% | 40 | 54 | 14 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `add_property` | 73.3% | 11 | 15 | 4 | [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 16 | `rewind_depth` | 73.3% | 22 | 30 | 8 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `register_underflow` | 69.2% | 18 | 26 | 8 | [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 18 | `unload` | 69.2% | 36 | 52 | 16 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 19 | `function_base_clip_removed` | 68.0% | 17 | 25 | 8 |  |
| 20 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 22 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 23 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 24 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 26 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 27 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_align` | 60.0% | 36 | 60 | 24 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `this_swf5` | 58.5% | 24 | 41 | 17 |  |
| 36 | `execution_order4` | 58.3% | 7 | 12 | 5 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 37 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 38 | `parse_float` | 58.1% | 43 | 74 | 31 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [21](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 39 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 42 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 43 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 44 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 45 | `edittext_html_condensewhite_swf7` | 53.4% | 166 | 311 | 145 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `edittext_programmatic_focus` | 50.0% | 6 | 12 | 6 | [24](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 49 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 50 | `issue_2870` | 50.0% | 2 | 4 | 2 |  |
| 51 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 52 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 10.3s |  |
| 2 | `goto_methods` | 10.5s | [9](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 3 | `native_objects_swf6` | 10.9s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `native_objects_swf7` | 11.0s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `native_objects_swf8` | 11.0s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_library_state_values` | exit code -6 | 10.8s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_state_values` | exit code -6 | 11.4s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 18.3s | [33](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**177 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stage_object_properties_swf6` | 99.1% | 229/231 | 231 | 231 | [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `hittest_morph` | 95.7% | 67/70 | 70 | 70 |  |
| 4 | `selection` | 95.6% | 434/454 | 454 | 454 | [24](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 5 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `button_properties_special_cases` | 86.4% | 19/22 | 22 | 22 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 8 | `string_paths_other` | 86.1% | 31/36 | 36 | 36 | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 9 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 10 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 11 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [36](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 12 | `movieclip_hittest_shapeflag` | 78.7% | 266/338 | 338 | 338 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 14 | `edittext_scroll` | 74.1% | 40/54 | 54 | 54 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `add_property` | 73.3% | 11/15 | 15 | 15 | [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 16 | `rewind_depth` | 73.3% | 22/30 | 30 | 30 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 18 | `unload` | 69.2% | 36/52 | 52 | 52 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 19 | `function_base_clip_removed` | 68.0% | 17/25 | 25 | 25 |  |
| 20 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 22 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 23 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 24 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 26 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 27 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `this_swf5` | 58.5% | 24/41 | 41 | 41 |  |
| 36 | `execution_order4` | 58.3% | 7/12 | 11 | 12 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 37 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 38 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [21](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 39 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 42 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 43 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 44 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 45 | `edittext_html_condensewhite_swf7` | 53.4% | 166/311 | 311 | 311 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `edittext_programmatic_focus` | 50.0% | 6/12 | 12 | 12 | [24](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 49 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 50 | `issue_2870` | 50.0% | 2/4 | 4 | 3 |  |
| 51 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 52 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `edittext_html_condensewhite_swf8` | 49.8% | 155/311 | 311 | 311 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `selection_handlers` | 48.1% | 13/27 | 19 | 27 | [24](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 55 | `goto_label` | 47.1% | 8/17 | 9 | 17 | [9](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 56 | `register_globals_across_frames` | 46.7% | 7/15 | 15 | 15 | [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 57 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 59 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 60 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 61 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 62 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 63 | `property_invalid_base_clip` | 38.9% | 14/36 | 35 | 36 |  |
| 64 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 65 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 66 | `on_construct` | 36.0% | 9/25 | 12 | 25 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 67 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 68 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 69 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 70 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 71 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 72 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 73 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 74 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 75 | `swf5_no_closure` | 31.6% | 6/19 | 15 | 19 |  |
| 76 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 77 | `default_names` | 28.8% | 15/52 | 48 | 52 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 78 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 79 | `swf6_global_funcs` | 25.9% | 60/232 | 232 | 232 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 80 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 81 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 82 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 83 | `goto_frame` | 25.0% | 3/12 | 10 | 12 | [9](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 84 | `movieclip_in_removed_button` | 25.0% | 1/4 | 4 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 85 | `swf5_global_funcs` | 24.6% | 57/232 | 232 | 232 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 86 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `textsnapshot_props_swf5` | 21.4% | 12/56 | 38 | 56 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 88 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 89 | `movieclip_init_object` | 20.0% | 1/5 | 2 | 5 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 90 | `tell_target_invalid_swf6` | 20.0% | 1/5 | 5 | 5 | [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 91 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 92 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [33](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 93 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 | [9](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 94 | `super_edge_cases` | 17.9% | 7/39 | 33 | 39 | [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 95 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 96 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 97 | `tell_target_invalid` | 16.7% | 1/6 | 5 | 6 | [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 98 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [19](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 99 | `instanceof_coercions` | 14.8% | 13/88 | 70 | 88 |  |
| 100 | `register_and_init_order` | 14.7% | 34/231 | 85 | 231 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 101 | `path_string` | 14.6% | 47/322 | 300 | 322 | [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 102 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 103 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 104 | `removed_clip_halts_script` | 13.3% | 2/15 | 13 | 15 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 105 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [19](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 106 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 107 | `textsnapshot_props_swf6` | 12.5% | 7/56 | 38 | 56 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 108 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 109 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 110 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 111 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 112 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 113 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 114 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 115 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 116 | `tell_target` | 8.1% | 3/37 | 34 | 37 | [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 117 | `call` | 7.9% | 5/63 | 28 | 63 |  |
| 118 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 119 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 120 | `define_local` | 7.4% | 2/27 | 23 | 27 | [36](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 121 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 122 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 123 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 80 | 129 |  |
| 124 | `swf4_actions_coercion_order` | 5.7% | 9/158 | 93 | 158 |  |
| 125 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [33](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 126 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 127 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 128 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 129 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 130 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 131 | `register_class` | 4.5% | 3/66 | 27 | 66 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 132 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 133 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 134 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 135 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 136 | `localconnection` | 0.3% | 2/579 | 4 | 579 |  |
| 137 | `global_proto_decls` | 0.3% | 13/4497 | 568 | 4497 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 138 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [10](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 139 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 140 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 141 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 142 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 143 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 144 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 145 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 146 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 147 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 148 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 149 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 150 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 151 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 152 | `global_proto_decls_delete` | 0.0% | 0/4158 | 216 | 4158 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 153 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 154 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 155 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 156 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [20](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 157 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 158 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 159 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 160 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 161 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 162 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 163 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 164 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 165 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 166 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 167 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 168 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 169 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 170 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 171 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 172 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 173 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 174 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 175 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 176 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 177 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) | 14 | 5 | 9 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 3 | 5 |
| 5 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 6 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 7 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) | 4 | 0 | 4 |
| 8 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 13 | 1 |
| 9 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) | 4 | 0 | 4 |
| 10 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 11 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 15 | 16 |
| 12 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 13 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 14 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 15 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) | 5 | 0 | 5 |
| 16 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 20 | 38 |
| 17 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 6 | 11 |
| 18 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 19 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 20 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 2 | 6 |
| 21 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 2 | 1 |
| 22 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 7 | 5 |
| 23 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 4 | 11 |
| 24 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 25 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 5 | 4 |
| 26 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 5 | 2 |
| 27 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 28 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 6 | 7 |
| 29 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 1 | 15 |
| 30 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 4 | 15 |
| 31 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 25 | 45 |
| 32 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 33 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 34 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 35 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 6 | 6 |
| 36 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 3 | 2 |
| 37 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 197 | 145 | 52 |
