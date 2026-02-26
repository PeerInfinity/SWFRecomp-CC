# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-26 06:34 UTC

**Git SHA**: `8080efc08b`

**Run Duration**: 103m 11s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **374** (60.4%) |
| Failing | 245 |
| Total expected lines | 91468 |
| Matching lines | 59328 (64.9%) |
| Mismatched lines | 32140 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 227 | 92.7% |
| Runtime Segfault | 14 | 5.7% |
| Runtime Error | 2 | 0.8% |
| Compile Fail | 1 | 0.4% |
| Timeout | 1 | 0.4% |

## Passing Tests

**374 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 10.7s |  |
| 2 | `action_to_integer` | 28 | 9.4s |  |
| 3 | `add` | 28 | 9.4s |  |
| 4 | `add2` | 354 | 9.5s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 9.3s | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 9.4s |  |
| 7 | `add_swf5` | 28 | 9.4s |  |
| 8 | `arguments` | 127 | 9.4s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [28](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 9.4s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 9.5s |  |
| 11 | `array_constructor` | 30 | 9.5s |  |
| 12 | `array_enumerate` | 4 | 9.4s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 9.6s |  |
| 14 | `array_properties` | 36 | 9.5s |  |
| 15 | `array_prototyping` | 12 | 9.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 9.6s |  |
| 17 | `array_sort` | 161 | 10.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 9.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 9.7s |  |
| 20 | `array_trivial` | 209 | 9.5s |  |
| 21 | `as1_constructor_v6` | 35 | 9.3s |  |
| 22 | `as1_constructor_v7` | 35 | 11.2s |  |
| 23 | `as2_oop` | 13 | 10.0s | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 9.9s | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 9.9s | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 10.0s | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 9.8s |  |
| 28 | `as_set_prop_flags` | 79 | 10.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version` | 31 | 9.9s | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version_swf5` | 1 | 9.7s |  |
| 31 | `as_set_prop_flags_version_swf6` | 1 | 9.7s |  |
| 32 | `as_set_prop_flags_version_swf7` | 1 | 9.6s |  |
| 33 | `as_set_prop_flags_version_swf8` | 1 | 9.7s |  |
| 34 | `as_set_prop_flags_version_swf9` | 1 | 9.7s |  |
| 35 | `as_transformed_flag` | 20 | 9.7s |  |
| 36 | `attach_movie` | 59 | 9.7s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 37 | `attach_movie_stop` | 3 | 9.7s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 38 | `bad_swf_tag_past_eof` | 0 | 9.5s |  |
| 39 | `bitand` | 1058 | 12.1s |  |
| 40 | `bitmap_data_colortransform` | 0 | 9.8s |  |
| 41 | `bitmap_data_fillrect` | 0 | 9.7s |  |
| 42 | `bitmap_data_max_size_swf10` | 12 | 9.6s |  |
| 43 | `bitmap_data_max_size_swf9` | 10 | 9.6s |  |
| 44 | `bitmap_data_perlinnoise` | 0 | 10.4s |  |
| 45 | `bitmap_data_pixeldissolve_image` | 0 | 9.9s |  |
| 46 | `bitmapdata_applyfilter_colormatrix` | 0 | 9.5s |  |
| 47 | `bitor` | 1058 | 12.1s |  |
| 48 | `biturshift` | 14 | 9.5s |  |
| 49 | `biturshift_swf8` | 14 | 10.0s |  |
| 50 | `bitxor` | 1058 | 12.4s |  |
| 51 | `boxed_primitives` | 24 | 10.0s | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 52 | `button_children` | 8 | 9.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 53 | `button_goto` | 4 | 9.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_key_events` | 14 | 10.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_key_events_special` | 45 | 11.0s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_keypress_vs_press` | 25 | 10.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_order` | 2 | 10.4s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_properties_special_cases` | 22 | 10.5s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_v5` | 18 | 10.0s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_v6` | 18 | 10.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `call_method_empty_name` | 1 | 10.4s |  |
| 62 | `capabilities_resolution` | 8 | 10.2s |  |
| 63 | `catch_references_registers` | 2 | 10.2s | [44](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 64 | `click_block` | 5 | 10.3s | [21](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 65 | `clip_events` | 19 | 9.8s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 66 | `clone_sprite_types` | 24 | 9.4s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 67 | `closure_scope` | 7 | 9.5s | [46](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 68 | `color` | 57 | 9.7s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 69 | `color_transform` | 48 | 9.5s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 70 | `conflicting_instance_names` | 23 | 9.5s |  |
| 71 | `constructor_function` | 2 | 9.3s |  |
| 72 | `define_function2` | 8 | 9.4s |  |
| 73 | `define_function2_preload` | 13 | 9.4s |  |
| 74 | `define_function2_preload_order` | 4 | 9.8s |  |
| 75 | `define_function_case_sensitive` | 2 | 9.5s |  |
| 76 | `delete` | 3 | 9.6s |  |
| 77 | `display_object_properties` | 2 | 9.5s |  |
| 78 | `divide_swf4` | 107 | 9.6s |  |
| 79 | `do_init_action` | 3 | 9.4s |  |
| 80 | `drag_drop` | 10 | 9.4s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 81 | `drag_over_from_outside` | 1 | 9.4s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 82 | `drag_over_without_startdrag` | 1 | 9.5s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 83 | `duplicate_movie_clip` | 20 | 9.5s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 84 | `edittext_antialiastype` | 296 | 9.5s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 85 | `edittext_autosize_setter` | 20 | 10.8s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 86 | `edittext_default_format` | 221 | 9.6s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `edittext_default_format_empty` | 95 | 9.4s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 88 | `edittext_default_format_font_style` | 335 | 9.4s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 89 | `edittext_html_align_swf7` | 52 | 9.6s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 90 | `edittext_html_align_swf8` | 52 | 9.5s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 91 | `edittext_html_entity` | 4 | 9.5s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 92 | `edittext_newline_stripping` | 64 | 13.9s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `edittext_password` | 5 | 9.4s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 94 | `edittext_password_copy` | 4 | 9.4s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 95 | `edittext_paste_empty` | 2 | 9.4s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 96 | `edittext_restrict_paste` | 5 | 9.3s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `edittext_width_height` | 103 | 9.6s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 98 | `empty_movieclip_can_attach_movies` | 11 | 11.6s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 99 | `enumerate` | 64 | 9.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 100 | `equals` | 32 | 9.7s |  |
| 101 | `equals2_swf5` | 926 | 11.4s |  |
| 102 | `equals2_swf6` | 926 | 11.5s |  |
| 103 | `equals2_swf7` | 926 | 11.5s |  |
| 104 | `equals_swf4` | 665 | 10.5s |  |
| 105 | `equals_swf4_alt` | 32 | 9.7s |  |
| 106 | `equals_swf5` | 32 | 9.7s |  |
| 107 | `error` | 58 | 9.7s |  |
| 108 | `escape` | 14 | 9.7s |  |
| 109 | `execution_order1` | 5 | 9.7s |  |
| 110 | `execution_order2` | 7 | 9.9s |  |
| 111 | `execution_order3` | 4 | 9.7s |  |
| 112 | `export_assets` | 3 | 9.6s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 113 | `extends_chain` | 134 | 10.1s | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 114 | `extends_native_type` | 11 | 9.7s | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 115 | `focus_root_movie` | 2 | 10.4s | [9](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 116 | `focusrect_focuslost` | 4 | 10.3s | [9](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 117 | `focusrect_mouse_swf8` | 0 | 10.3s |  |
| 118 | `focusrect_mouse_swf9` | 0 | 10.1s |  |
| 119 | `focusrect_swf5` | 6 | 9.6s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 120 | `focusrect_swf6` | 42 | 9.5s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 121 | `form_loader_encoding_1` | 1 | 9.4s |  |
| 122 | `function_suppress_and_preload` | 28 | 9.6s |  |
| 123 | `get_variable_in_scope` | 29 | 9.5s |  |
| 124 | `getproperty` | 28 | 9.4s |  |
| 125 | `getproperty_swf4` | 28 | 11.1s |  |
| 126 | `getproperty_swf5` | 28 | 9.5s |  |
| 127 | `global_array` | 3 | 9.4s |  |
| 128 | `global_is_bare` | 7 | 9.4s |  |
| 129 | `globals_swf5` | 304 | 9.7s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 130 | `globals_swf6` | 304 | 9.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 131 | `globals_swf7` | 304 | 9.9s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 132 | `globals_swf8` | 304 | 9.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 133 | `goto_advance1` | 6 | 9.6s |  |
| 134 | `goto_advance2` | 2 | 9.6s |  |
| 135 | `goto_both_ways1` | 3 | 9.5s |  |
| 136 | `goto_both_ways2` | 3 | 9.6s |  |
| 137 | `goto_execution_order` | 2 | 9.5s |  |
| 138 | `goto_execution_order2` | 2 | 9.5s |  |
| 139 | `goto_frame` | 12 | 10.0s | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 140 | `goto_frame2` | 44 | 10.3s | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 141 | `goto_frame_number` | 3 | 9.7s |  |
| 142 | `goto_label` | 17 | 10.1s | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 143 | `goto_methods` | 40 | 10.0s | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 144 | `goto_rewind1` | 1 | 9.7s |  |
| 145 | `goto_rewind2` | 3 | 9.8s |  |
| 146 | `goto_rewind3` | 2 | 9.7s |  |
| 147 | `greater_swf6` | 1175 | 12.0s |  |
| 148 | `greater_swf7` | 1175 | 11.6s |  |
| 149 | `greaterthan_swf5` | 1 | 9.6s |  |
| 150 | `greaterthan_swf8` | 1 | 9.8s |  |
| 151 | `has_own_property` | 32 | 9.7s |  |
| 152 | `hittest_lockroot` | 15 | 9.7s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 153 | `hittest_morph` | 70 | 9.6s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [20](ruffle-tests/_investigation/incomplete/MORPH_INTERPOLATION_PLAN.md) |
| 154 | `hittest_winding_rule` | 12 | 9.6s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 155 | `infinite_recursion_function` | 4 | 9.4s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 156 | `infinite_recursion_function_in_setter` | 131 | 9.5s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 157 | `infinite_recursion_virtual_property` | 67 | 9.5s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 158 | `init_array_invalid` | 4 | 9.6s |  |
| 159 | `init_object_invalid` | 4 | 11.2s |  |
| 160 | `init_object_order` | 15 | 9.9s | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 161 | `is_finite` | 49 | 10.1s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 162 | `is_finite_swf6` | 49 | 9.8s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 163 | `is_prototype_of` | 89 | 9.7s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 164 | `issue_1086` | 1 | 9.7s |  |
| 165 | `issue_1671` | 0 | 9.7s |  |
| 166 | `issue_1906` | 4 | 9.7s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 167 | `issue_2166` | 9 | 9.9s |  |
| 168 | `issue_3446` | 1 | 9.8s |  |
| 169 | `issue_3522` | 2 | 9.9s |  |
| 170 | `issue_4377` | 2 | 9.8s |  |
| 171 | `issue_710` | 4 | 9.7s |  |
| 172 | `issue_768` | 3 | 10.3s | [15](ruffle-tests/_investigation/complete/issue_768.md) |
| 173 | `issue_9327` | 2 | 9.5s |  |
| 174 | `issue_9885` | 2 | 9.5s |  |
| 175 | `key_isToggled` | 9 | 9.5s |  |
| 176 | `lessthan` | 41 | 9.4s |  |
| 177 | `lessthan2_swf5` | 1226 | 11.5s |  |
| 178 | `lessthan2_swf6` | 1226 | 11.4s |  |
| 179 | `lessthan2_swf7` | 1226 | 11.5s |  |
| 180 | `lessthan_swf4` | 902 | 10.6s |  |
| 181 | `lessthan_swf4_alt` | 41 | 9.4s |  |
| 182 | `lessthan_swf5` | 41 | 9.4s |  |
| 183 | `loadmovie` | 2 | 9.4s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 184 | `loadmovie_fail` | 2 | 9.5s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 185 | `loadmovie_method` | 2 | 9.3s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 186 | `loadmovie_replace_root` | 5 | 9.4s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/incomplete/ROOT_REPLACEMENT_PLAN.md) |
| 187 | `loadmovienum` | 3 | 9.3s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 188 | `loadvariables` | 2 | 9.8s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADVARIABLES_PLAN.md) |
| 189 | `loadvariables2` | 8 | 9.7s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADVARIABLES_PLAN.md) |
| 190 | `loadvariablesnum` | 2 | 9.5s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADVARIABLES_PLAN.md) |
| 191 | `local_to_global` | 49 | 9.6s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 192 | `localconnection_properties` | 8 | 9.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 193 | `lock_root` | 1 | 9.5s |  |
| 194 | `logical_ops_swf4` | 90 | 9.4s |  |
| 195 | `logical_ops_swf8` | 108 | 9.5s |  |
| 196 | `looping` | 6 | 9.5s |  |
| 197 | `mask_reapply` | 0 | 9.5s |  |
| 198 | `mask_with_drawing` | 0 | 9.5s |  |
| 199 | `math_min_max` | 101 | 9.6s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 200 | `math_swf6` | 530 | 9.8s | [19](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 201 | `math_swf7` | 530 | 9.8s | [19](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 202 | `math_swf8` | 530 | 9.8s | [19](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 203 | `matrix` | 171 | 9.8s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 204 | `mcl_as_broadcaster` | 12 | 9.4s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 205 | `mcl_getprogress` | 30 | 10.2s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 206 | `mcl_loadclip` | 149 | 10.1s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 207 | `mcl_loadclip_properties` | 6 | 10.1s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 208 | `mcl_mislabeled_target` | 6 | 9.8s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 209 | `mcl_target_gif87a` | 6 | 10.2s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 210 | `mcl_target_gif89a` | 6 | 10.2s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 211 | `mcl_target_jpg` | 6 | 9.7s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 212 | `mcl_target_png` | 6 | 9.7s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 213 | `mcl_unloadclip` | 5 | 9.7s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 214 | `mouse_events` | 8 | 9.7s | [21](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 215 | `mouse_events_visible_enabled` | 12 | 10.0s | [21](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 216 | `mouse_hover_events_while_dragging` | 1 | 10.0s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 217 | `mouse_listeners` | 67 | 9.8s |  |
| 218 | `mouse_pos` | 665 | 9.7s | [21](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 219 | `mouse_pos_with_scale_factor` | 260 | 9.9s | [21](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 220 | `mouse_wheel_enabled` | 2 | 9.6s |  |
| 221 | `movieclip_begin_gradient_fill` | 0 | 10.2s |  |
| 222 | `movieclip_blend_mode_property` | 35 | 10.4s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 223 | `movieclip_default_state` | 69 | 10.0s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 224 | `movieclip_depth_methods` | 98 | 9.9s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 225 | `movieclip_focusenabled` | 99 | 9.8s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 226 | `movieclip_get_instance_at_depth` | 28 | 9.8s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 227 | `movieclip_hittest` | 92 | 9.8s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 228 | `movieclip_in_removed_button` | 4 | 9.7s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 229 | `movieclip_line_gradient_style` | 0 | 9.8s |  |
| 230 | `movieclip_name_from_timeline` | 13 | 9.2s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 231 | `movieclip_prototype_extension` | 5 | 9.2s |  |
| 232 | `moviecliploader_flashvars` | 4 | 9.3s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 233 | `mutable_this` | 18 | 9.2s | [41](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 234 | `nested_textfields_in_buttons` | 0 | 9.2s |  |
| 235 | `new_method_wrap` | 4 | 10.2s |  |
| 236 | `new_object_enumerate` | 7 | 10.0s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 237 | `new_object_wrap` | 4 | 9.9s |  |
| 238 | `o` | 3 | 9.9s |  |
| 239 | `object_constructor` | 33 | 10.0s |  |
| 240 | `object_function` | 32 | 9.8s |  |
| 241 | `object_properties` | 31 | 9.9s | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 242 | `object_prototypes` | 74 | 9.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 243 | `object_string_coerce_swf5` | 62 | 9.7s | [25](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 244 | `object_string_coerce_swf6` | 68 | 9.7s | [25](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 245 | `parse_int` | 64 | 9.9s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 246 | `placeobject_occupied_depth` | 6 | 9.7s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 247 | `point` | 175 | 10.1s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 248 | `primitive_instanceof` | 37 | 9.8s |  |
| 249 | `primitive_type_globals` | 557 | 11.2s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 250 | `printjob_props_swf5` | 45 | 9.8s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 251 | `printjob_props_swf6` | 45 | 9.4s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 252 | `printjob_props_swf7` | 45 | 9.4s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 253 | `property_invalid_base_clip` | 36 | 9.4s |  |
| 254 | `prototype_delete` | 12 | 9.3s |  |
| 255 | `prototype_enumerate` | 5 | 9.3s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 256 | `prototype_properties` | 17 | 9.3s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 257 | `rectangle` | 745 | 10.1s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 258 | `recursive_prototypes` | 0 | 9.3s |  |
| 259 | `register_class_return_value` | 16 | 9.4s | [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 260 | `register_globals_across_frames` | 15 | 9.5s | [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 261 | `register_underflow` | 26 | 9.4s | [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 262 | `remove_movie_clip` | 29 | 9.5s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 263 | `sandbox_type_local_file` | 1 | 9.8s |  |
| 264 | `sandbox_type_local_network` | 1 | 9.9s |  |
| 265 | `set_interval` | 27 | 10.0s | [43](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 266 | `set_variable_scope` | 58 | 9.9s |  |
| 267 | `single_frame` | 1 | 9.9s |  |
| 268 | `slash_syntax` | 14 | 9.9s | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 269 | `sound_props_swf5` | 68 | 9.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 270 | `sound_props_swf6` | 68 | 9.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 271 | `sound_start_load` | 0 | 9.5s |  |
| 272 | `stage_display_state` | 16 | 9.4s | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 273 | `stage_object_enumerate` | 4 | 9.4s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 274 | `stage_object_properties` | 241 | 9.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 275 | `stage_object_properties_get_var` | 5 | 9.4s |  |
| 276 | `stage_object_properties_swf6` | 231 | 9.8s | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 277 | `stage_property_representation` | 586 | 9.5s | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 278 | `stage_scale_mode` | 39 | 9.4s | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 279 | `strictequals_swf6` | 902 | 10.9s |  |
| 280 | `strictly_equals` | 7 | 9.4s |  |
| 281 | `string_coercion` | 117 | 9.7s | [35](ruffle-tests/_investigation/complete/string_coercion.md) |
| 282 | `string_methods` | 285 | 9.9s | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 283 | `string_methods_negative_args` | 240 | 9.5s | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 284 | `string_methods_swfv5` | 275 | 10.0s | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 285 | `string_ops_swf6` | 95 | 9.5s | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 286 | `string_paths_basic` | 4 | 9.4s | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 287 | `string_paths_variable_alias` | 4 | 10.0s | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 288 | `swf4_actions_bool` | 96 | 10.0s |  |
| 289 | `swf4_actions_coercion_order` | 158 | 10.0s | [37](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 290 | `swf4_bool` | 4 | 9.8s |  |
| 291 | `swf4_function_calls` | 7 | 9.9s |  |
| 292 | `swf5_encoding` | 3 | 9.8s |  |
| 293 | `swf5_no_closure` | 19 | 10.2s | [41](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 294 | `swf6_case_insensitive` | 42 | 9.7s | [37](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 295 | `swf6_string_as_bool` | 15 | 9.8s | [37](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 296 | `swf7_case_sensitive` | 44 | 9.9s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 297 | `tab_ordering_automatic_basic` | 92 | 9.6s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 298 | `tab_ordering_automatic_order_grid` | 21 | 9.6s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 299 | `tab_ordering_children` | 208 | 9.6s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 300 | `tab_ordering_custom_basic` | 71 | 9.7s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 301 | `tab_ordering_custom_duplicate_index` | 22 | 9.7s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 302 | `tab_ordering_custom_i32_vs_u32` | 12 | 9.6s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 303 | `tab_ordering_custom_m1` | 29 | 9.6s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 304 | `tab_ordering_properties_tab_index_edge_case` | 4 | 9.4s |  |
| 305 | `tab_ordering_reverse` | 51 | 9.5s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 306 | `target_clip_removed` | 5 | 9.5s | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 307 | `target_path` | 14 | 9.4s |  |
| 308 | `text_format` | 1146 | 9.6s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 309 | `text_format_display` | 21 | 9.4s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 310 | `text_format_font_max_length` | 2 | 9.4s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 311 | `text_format_rounding_swf7` | 840 | 9.5s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 312 | `text_format_rounding_swf8` | 840 | 9.5s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 313 | `textfield_background_color` | 11 | 9.4s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 314 | `textfield_border_color` | 11 | 9.4s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 315 | `textfield_maxchars` | 3 | 10.1s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 316 | `textfield_properties` | 44 | 9.7s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 317 | `textfield_props_swf5` | 175 | 9.9s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 318 | `textfield_props_swf6` | 210 | 9.8s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 319 | `textfield_props_swf7` | 210 | 9.7s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 320 | `textfield_props_swf8` | 210 | 9.8s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 321 | `textfield_text` | 7 | 9.5s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 322 | `textfield_variable` | 81 | 9.8s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 323 | `this_swf5` | 41 | 9.6s | [41](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 324 | `this_swf6` | 41 | 9.5s | [41](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 325 | `this_swf7` | 41 | 9.6s | [42](ruffle-tests/_investigation/complete/this_swf7.md) |
| 326 | `timeline_function_def` | 7 | 9.6s |  |
| 327 | `transform` | 70 | 9.5s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 328 | `try_catch_finally` | 118 | 9.5s | [44](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 329 | `try_finally_simple` | 16 | 9.4s | [44](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 330 | `typeof` | 22 | 9.4s |  |
| 331 | `typeof_globals` | 7 | 9.4s |  |
| 332 | `uncaught_exception` | 1 | 9.4s | [44](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 333 | `uncaught_exception_bubbled` | 1 | 9.4s | [44](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 334 | `undefined_to_string_swf6` | 4 | 9.4s |  |
| 335 | `unescape` | 43 | 9.4s |  |
| 336 | `unload_clip_event` | 4 | 9.4s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 337 | `unloadmovie` | 4 | 9.5s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 338 | `unloadmovie_method` | 3 | 9.5s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 339 | `unloadmovienum` | 13 | 9.7s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 340 | `use_hand_cursor` | 8 | 9.4s |  |
| 341 | `variable_args` | 5 | 9.5s |  |
| 342 | `waitforframe` | 7 | 9.4s |  |
| 343 | `waitforframe2` | 16 | 11.3s |  |
| 344 | `watch` | 117 | 9.6s | [26](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 345 | `watch_virtual_property_proto` | 2 | 9.3s | [26](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 346 | `with` | 49 | 9.3s | [46](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 347 | `with_return` | 2 | 9.3s |  |
| 348 | `with_variable_scopes` | 43 | 9.4s | [46](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 349 | `xml` | 15 | 9.3s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 350 | `xml_append_child` | 28 | 9.3s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 351 | `xml_append_child_with_parent` | 20 | 9.6s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 352 | `xml_attributes_read` | 4 | 9.2s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 353 | `xml_cdata` | 11 | 9.2s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 354 | `xml_child_nodes_edge_cases` | 4 | 9.3s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 355 | `xml_clone_expandos` | 19 | 9.3s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 356 | `xml_first_last_child` | 8 | 9.4s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 357 | `xml_has_child_nodes` | 3 | 9.2s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 358 | `xml_idmap` | 21 | 9.3s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 359 | `xml_ignore_comments` | 21 | 9.3s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 360 | `xml_ignore_white` | 34 | 10.1s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 361 | `xml_insert_before` | 20 | 9.6s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 362 | `xml_inspect_createmethods` | 15 | 9.7s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 363 | `xml_inspect_doctype` | 7 | 9.9s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 364 | `xml_inspect_parsexml` | 62 | 9.7s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 365 | `xml_inspect_xmldecl` | 7 | 9.7s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 366 | `xml_namespaces` | 203 | 9.7s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 367 | `xml_parent_and_child` | 5 | 9.7s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 368 | `xml_remove_node` | 22 | 9.7s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 369 | `xml_reparenting` | 14 | 9.7s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 370 | `xml_siblings` | 10 | 9.6s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 371 | `xml_to_string` | 13 | 9.5s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 372 | `xml_to_string_comment` | 1 | 9.5s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 373 | `xml_unescaping` | 23 | 9.6s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 374 | `xmlnode_proto` | 1 | 9.6s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**67 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [6](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `selection` | 95.6% | 434 | 454 | 20 | [32](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 4 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 5 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `button_keypress_vs_tab` | 90.0% | 18 | 20 | 2 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 7 | `string_paths_other` | 86.1% | 31 | 36 | 5 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 8 | `super_edge_cases` | 84.6% | 33 | 39 | 6 | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 9 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 10 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 11 | `function_base_clip_removed` | 80.0% | 20 | 25 | 5 |  |
| 12 | `movieclip_hittest_shapeflag` | 78.7% | 266 | 338 | 72 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `edittext_restrict` | 77.0% | 147 | 191 | 44 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 14 | `tab_ordering_tabbable` | 76.6% | 36 | 47 | 11 | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 15 | `button_keypress_vs_textinput` | 75.0% | 3 | 4 | 1 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 16 | `clip_constructors` | 75.0% | 6 | 8 | 2 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 17 | `create_empty_movie_clip` | 75.0% | 3 | 4 | 1 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 18 | `loadmovie_flashvars` | 75.0% | 3 | 4 | 1 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 19 | `tab_ordering_automatic_order_same_position` | 75.0% | 9 | 12 | 3 | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 20 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 21 | `edittext_scroll` | 74.1% | 40 | 54 | 14 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `global_swf6_7_8` | 73.3% | 11 | 15 | 4 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 23 | `rewind_depth` | 73.3% | 22 | 30 | 8 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 24 | `string_paths_eval2` | 71.4% | 5 | 7 | 2 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 25 | `global_swf5_6_7_8_9` | 69.7% | 798 | 1145 | 347 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 26 | `edittext_tab_focus` | 69.2% | 9 | 13 | 4 | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `unload` | 69.2% | 36 | 52 | 16 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 28 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 31 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 32 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 34 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_align` | 60.0% | 36 | 60 | 24 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 44 | `execution_order4` | 58.3% | 7 | 12 | 5 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 45 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 46 | `parse_float` | 58.1% | 43 | 74 | 31 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 47 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 48 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 50 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 52 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 53 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 54 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 55 | `edittext_html_condensewhite_swf7` | 53.4% | 166 | 311 | 145 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 57 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 58 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 59 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 60 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `edittext_place_caret` | 50.0% | 1 | 2 | 1 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `edittext_programmatic_focus` | 50.0% | 6 | 12 | 6 | [32](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 64 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 65 | `loadmovie_var_persistence` | 50.0% | 4 | 8 | 4 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 66 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 67 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**14 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `edittext_ime_focus_lost` | 11.4s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 2 | `funky_function_calls` | 11.5s |  |
| 3 | `movieclip_init_object` | 11.6s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 4 | `movieclip_library_state_values` | 11.8s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 5 | `native_objects_swf6` | 11.1s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `native_objects_swf7` | 11.2s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 7 | `native_objects_swf8` | 11.1s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 8 | `netstream_play_flv_screen` | 23.8s |  |
| 9 | `on_construct` | 11.6s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 10 | `register_and_init_order` | 11.8s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 11 | `register_class_with_sound` | 11.5s | [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 12 | `resolve_different_root` | 12.2s |  |
| 13 | `string_paths_timer` | 12.1s |  |
| 14 | `timer_run_actions` | 12.2s | [43](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 32.9s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 32.9s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 19.6s | [43](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**227 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [6](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `selection` | 95.6% | 434/454 | 454 | 454 | [32](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 4 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 5 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `button_keypress_vs_tab` | 90.0% | 18/20 | 20 | 20 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 7 | `string_paths_other` | 86.1% | 31/36 | 36 | 36 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 8 | `super_edge_cases` | 84.6% | 33/39 | 37 | 39 | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 9 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 10 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 11 | `function_base_clip_removed` | 80.0% | 20/25 | 25 | 25 |  |
| 12 | `movieclip_hittest_shapeflag` | 78.7% | 266/338 | 338 | 338 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `edittext_restrict` | 77.0% | 147/191 | 191 | 191 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 14 | `tab_ordering_tabbable` | 76.6% | 36/47 | 47 | 47 | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 15 | `button_keypress_vs_textinput` | 75.0% | 3/4 | 3 | 4 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 16 | `clip_constructors` | 75.0% | 6/8 | 8 | 8 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 17 | `create_empty_movie_clip` | 75.0% | 3/4 | 4 | 3 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 18 | `loadmovie_flashvars` | 75.0% | 3/4 | 4 | 4 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 19 | `tab_ordering_automatic_order_same_position` | 75.0% | 9/12 | 12 | 12 | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 20 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 21 | `edittext_scroll` | 74.1% | 40/54 | 54 | 54 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `global_swf6_7_8` | 73.3% | 11/15 | 15 | 15 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 23 | `rewind_depth` | 73.3% | 22/30 | 30 | 30 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 24 | `string_paths_eval2` | 71.4% | 5/7 | 7 | 7 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 25 | `global_swf5_6_7_8_9` | 69.7% | 798/1145 | 1145 | 1145 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 26 | `edittext_tab_focus` | 69.2% | 9/13 | 13 | 13 | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `unload` | 69.2% | 36/52 | 52 | 52 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 28 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 31 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 32 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 34 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 44 | `execution_order4` | 58.3% | 7/12 | 11 | 12 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 45 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 46 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 47 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 48 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 50 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 52 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 53 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 54 | `movieclip_lockroot` | 55.2% | 16/29 | 17 | 29 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 55 | `edittext_html_condensewhite_swf7` | 53.4% | 166/311 | 311 | 311 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 57 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 58 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 59 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 60 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `edittext_place_caret` | 50.0% | 1/2 | 2 | 2 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `edittext_programmatic_focus` | 50.0% | 6/12 | 12 | 12 | [32](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 64 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 65 | `loadmovie_var_persistence` | 50.0% | 4/8 | 5 | 8 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 66 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 67 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 68 | `edittext_html_condensewhite_swf8` | 49.8% | 155/311 | 311 | 311 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 69 | `selection_handlers` | 48.1% | 13/27 | 19 | 27 | [32](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 70 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 71 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 72 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 73 | `focus_mouse` | 44.4% | 20/45 | 38 | 45 | [9](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 74 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 75 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 76 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 77 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 78 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 79 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 80 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 81 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 82 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 83 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 84 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 85 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 86 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 88 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 89 | `input_dead_keys_windows` | 33.3% | 5/15 | 14 | 15 |  |
| 90 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 91 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 92 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 94 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 95 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 96 | `swf6_to_5_cross_call` | 31.0% | 9/29 | 11 | 29 | [37](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 97 | `cross_movie_root` | 30.0% | 3/10 | 10 | 10 |  |
| 98 | `loadmovie_registerclass` | 30.0% | 9/30 | 24 | 30 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 99 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 100 | `default_names` | 28.8% | 15/52 | 48 | 52 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 101 | `swf5_to_6_cross_call` | 27.6% | 8/29 | 11 | 29 | [37](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 102 | `tell_target` | 26.3% | 10/38 | 38 | 37 | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 103 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 104 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 105 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 106 | `issue_2870` | 25.0% | 2/8 | 8 | 3 |  |
| 107 | `textsnapshot_props_swf5` | 25.0% | 14/56 | 38 | 56 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 108 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 109 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 110 | `this_scoping` | 20.8% | 11/53 | 53 | 52 | [41](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) [46](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 111 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 112 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 113 | `tell_target_invalid` | 20.0% | 2/10 | 10 | 6 | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 114 | `tell_target_invalid_swf6` | 20.0% | 2/10 | 10 | 5 | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 115 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 116 | `register_class_swf6` | 18.9% | 7/37 | 10 | 37 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 117 | `focus_remove` | 18.2% | 6/33 | 21 | 33 |  |
| 118 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 4 | 11 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 119 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 120 | `tab_ordering_events` | 17.3% | 26/150 | 129 | 150 | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 121 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 122 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 123 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [26](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 124 | `focus_visibility_change` | 15.6% | 7/45 | 33 | 45 |  |
| 125 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 126 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 127 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 128 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 129 | `mcl_events_swf_version` | 13.8% | 32/232 | 37 | 232 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 130 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 131 | `tab_ordering_movieclip_enabled_default` | 13.6% | 63/462 | 432 | 462 | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 132 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [26](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 133 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 134 | `localconnection` | 12.8% | 74/579 | 261 | 579 |  |
| 135 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 136 | `textsnapshot_props_swf6` | 12.5% | 7/56 | 38 | 56 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 137 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 138 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 139 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 140 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 1 | 9 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 141 | `path_string` | 10.9% | 38/350 | 350 | 322 | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 142 | `register_class` | 10.6% | 7/66 | 52 | 66 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 143 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 144 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 145 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 146 | `tab_ordering_events_mouse` | 7.7% | 5/65 | 48 | 65 | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 147 | `define_local` | 7.4% | 2/27 | 23 | 27 | [46](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 148 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 149 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 150 | `call` | 6.3% | 4/63 | 29 | 63 |  |
| 151 | `movieclip_gettextsnapshot` | 6.2% | 7/112 | 42 | 112 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 152 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 153 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 154 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 155 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 156 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 157 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 158 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 159 | `removed_clip_halts_script` | 4.8% | 1/21 | 21 | 15 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 160 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 161 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 162 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 163 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 164 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 165 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 166 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 167 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 168 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) [31](ruffle-tests/_investigation/incomplete/ROOT_REPLACEMENT_PLAN.md) |
| 169 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) [31](ruffle-tests/_investigation/incomplete/ROOT_REPLACEMENT_PLAN.md) |
| 170 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 171 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 172 | `focus_keyboard_press` | 0.7% | 1/138 | 138 | 60 | [9](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 173 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 174 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 175 | `global_proto_decls` | 0.4% | 16/4497 | 572 | 4497 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 176 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 177 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 178 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 179 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 180 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 181 | `button_keypress` | 0.0% | 0/3 | 2 | 3 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 182 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 183 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 184 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 185 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 186 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 | [32](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 187 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 188 | `edittext_input_newlines` | 0.0% | 0/9 | 4 | 9 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 189 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 190 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 191 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 192 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 193 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 194 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [9](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 195 | `focus_mouse_rollout` | 0.0% | 0/4 | 1 | 4 | [9](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 196 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 197 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 198 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 199 | `global_proto_decls_delete` | 0.0% | 0/4158 | 216 | 4158 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 200 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 201 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 202 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 203 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADVARIABLES_PLAN.md) |
| 204 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) [31](ruffle-tests/_investigation/incomplete/ROOT_REPLACEMENT_PLAN.md) |
| 205 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 206 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 207 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 208 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 209 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 210 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 211 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 212 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 213 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 214 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 215 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 216 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 217 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 218 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 219 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 220 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 221 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 222 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 223 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 224 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 225 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 226 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 227 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 10 | 4 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 3 | 5 |
| 5 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 6 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 7 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 8 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 9 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 6 | 2 | 4 |
| 10 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 11 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 12 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 16 | 15 |
| 13 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 14 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 15 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 16 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) | 49 | 22 | 27 |
| 17 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 18 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/incomplete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 19 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 20 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/incomplete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 21 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 22 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 19 | 39 |
| 23 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) | 16 | 12 | 4 |
| 24 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 10 | 7 |
| 25 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 26 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 27 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 6 | 2 |
| 28 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 2 | 1 |
| 29 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 10 | 2 |
| 30 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 7 | 8 |
| 31 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/incomplete/ROOT_REPLACEMENT_PLAN.md) | 4 | 1 | 3 |
| 32 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 33 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 6 | 3 |
| 34 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 6 | 1 |
| 35 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 36 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 6 | 7 |
| 37 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 38 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 10 | 6 |
| 39 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 4 | 15 |
| 40 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 29 | 41 |
| 41 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) | 5 | 4 | 1 |
| 42 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 43 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 44 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 45 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 9 | 3 |
| 46 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 3 | 2 |
| 47 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 230 | 147 | 83 |
