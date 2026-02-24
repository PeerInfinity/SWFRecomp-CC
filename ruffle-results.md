# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-24 23:34 UTC

**Git SHA**: `c1f23adabb`

**Run Duration**: 93m 34s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **345** (55.7%) |
| Failing | 274 |
| Total expected lines | 91477 |
| Matching lines | 57927 (63.3%) |
| Mismatched lines | 33550 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 265 | 96.7% |
| Runtime Segfault | 5 | 1.8% |
| Runtime Error | 2 | 0.7% |
| Compile Fail | 1 | 0.4% |
| Timeout | 1 | 0.4% |

## Passing Tests

**345 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 8.7s |  |
| 2 | `action_to_integer` | 28 | 8.5s |  |
| 3 | `add` | 28 | 8.6s |  |
| 4 | `add2` | 354 | 8.8s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_swf4` | 28 | 8.5s |  |
| 6 | `add_swf5` | 28 | 8.5s |  |
| 7 | `arguments` | 127 | 8.6s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 8.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 8.6s |  |
| 10 | `array_constructor` | 30 | 8.6s |  |
| 11 | `array_enumerate` | 4 | 8.6s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 8.6s |  |
| 13 | `array_properties` | 36 | 8.5s |  |
| 14 | `array_prototyping` | 12 | 8.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 8.6s |  |
| 16 | `array_sort` | 161 | 9.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_sort_random` | 443 | 8.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 8.7s |  |
| 19 | `array_trivial` | 209 | 8.7s |  |
| 20 | `as1_constructor_v6` | 35 | 8.5s |  |
| 21 | `as1_constructor_v7` | 35 | 10.1s |  |
| 22 | `as2_oop` | 13 | 9.1s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as_broadcaster_initialize` | 10 | 8.8s |  |
| 24 | `as_set_prop_flags_version` | 31 | 8.9s | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 25 | `as_set_prop_flags_version_swf5` | 1 | 8.9s |  |
| 26 | `as_set_prop_flags_version_swf6` | 1 | 8.9s |  |
| 27 | `as_set_prop_flags_version_swf7` | 1 | 8.9s |  |
| 28 | `as_set_prop_flags_version_swf8` | 1 | 8.8s |  |
| 29 | `as_set_prop_flags_version_swf9` | 1 | 8.8s |  |
| 30 | `as_transformed_flag` | 20 | 8.8s |  |
| 31 | `attach_movie` | 59 | 8.9s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 32 | `attach_movie_stop` | 3 | 8.9s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 33 | `bad_swf_tag_past_eof` | 0 | 8.5s |  |
| 34 | `bitand` | 1058 | 11.0s |  |
| 35 | `bitmap_data_colortransform` | 0 | 8.8s |  |
| 36 | `bitmap_data_fillrect` | 0 | 8.7s |  |
| 37 | `bitmap_data_max_size_swf10` | 12 | 8.6s |  |
| 38 | `bitmap_data_max_size_swf9` | 10 | 8.6s |  |
| 39 | `bitmap_data_perlinnoise` | 0 | 9.3s |  |
| 40 | `bitmap_data_pixeldissolve_image` | 0 | 9.0s |  |
| 41 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.6s |  |
| 42 | `bitor` | 1058 | 11.2s |  |
| 43 | `biturshift` | 14 | 8.6s |  |
| 44 | `biturshift_swf8` | 14 | 10.3s |  |
| 45 | `bitxor` | 1058 | 11.3s |  |
| 46 | `boxed_primitives` | 24 | 8.8s | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 47 | `button_children` | 8 | 8.6s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 48 | `button_goto` | 4 | 8.7s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 49 | `button_order` | 2 | 8.6s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 50 | `button_properties_special_cases` | 22 | 8.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 51 | `button_v5` | 18 | 8.6s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 52 | `button_v6` | 18 | 8.6s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 53 | `call_method_empty_name` | 1 | 8.7s |  |
| 54 | `capabilities_resolution` | 8 | 8.7s |  |
| 55 | `catch_references_registers` | 2 | 8.7s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 56 | `clip_events` | 19 | 9.1s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 57 | `clone_sprite_types` | 24 | 8.8s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 58 | `closure_scope` | 7 | 8.9s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 59 | `color` | 57 | 9.0s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 60 | `color_transform` | 48 | 8.9s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 61 | `conflicting_instance_names` | 23 | 8.9s |  |
| 62 | `create_empty_movie_clip` | 3 | 8.7s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 63 | `define_function2` | 8 | 8.8s |  |
| 64 | `define_function2_preload` | 13 | 8.8s |  |
| 65 | `define_function2_preload_order` | 4 | 10.3s |  |
| 66 | `define_function_case_sensitive` | 2 | 9.0s |  |
| 67 | `delete` | 3 | 9.0s |  |
| 68 | `display_object_properties` | 2 | 9.0s |  |
| 69 | `divide_swf4` | 107 | 9.1s |  |
| 70 | `do_init_action` | 3 | 9.0s |  |
| 71 | `drag_drop` | 10 | 9.1s | [8](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 72 | `drag_over_from_outside` | 1 | 9.2s | [8](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 73 | `drag_over_without_startdrag` | 1 | 9.3s | [8](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 74 | `duplicate_movie_clip` | 20 | 9.3s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 75 | `edittext_antialiastype` | 296 | 9.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 76 | `edittext_autosize_setter` | 20 | 9.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 77 | `edittext_default_format` | 221 | 9.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `edittext_default_format_empty` | 95 | 8.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 79 | `edittext_default_format_font_style` | 335 | 8.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 80 | `edittext_html_align_swf7` | 52 | 9.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 81 | `edittext_html_align_swf8` | 52 | 9.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 82 | `edittext_html_entity` | 4 | 8.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 83 | `edittext_newline_stripping` | 64 | 13.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `edittext_password` | 5 | 8.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 85 | `edittext_password_copy` | 4 | 8.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 86 | `edittext_paste_empty` | 2 | 8.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `edittext_restrict_paste` | 5 | 8.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 88 | `edittext_width_height` | 103 | 8.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 89 | `empty_movieclip_can_attach_movies` | 11 | 10.1s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 90 | `enumerate` | 64 | 8.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 91 | `equals` | 32 | 8.7s |  |
| 92 | `equals2_swf5` | 926 | 10.5s |  |
| 93 | `equals2_swf6` | 926 | 10.5s |  |
| 94 | `equals2_swf7` | 926 | 10.5s |  |
| 95 | `equals_swf4` | 665 | 9.5s |  |
| 96 | `equals_swf4_alt` | 32 | 8.6s |  |
| 97 | `equals_swf5` | 32 | 8.7s |  |
| 98 | `error` | 58 | 8.6s |  |
| 99 | `escape` | 14 | 8.7s |  |
| 100 | `execution_order1` | 5 | 8.9s |  |
| 101 | `execution_order2` | 7 | 8.9s |  |
| 102 | `execution_order3` | 4 | 8.6s |  |
| 103 | `export_assets` | 3 | 8.5s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 104 | `extends_native_type` | 11 | 8.6s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 105 | `focus_root_movie` | 2 | 8.7s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 106 | `focusrect_focuslost` | 4 | 8.7s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 107 | `focusrect_mouse_swf8` | 0 | 8.7s |  |
| 108 | `focusrect_mouse_swf9` | 0 | 10.7s |  |
| 109 | `focusrect_swf5` | 6 | 9.3s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 110 | `focusrect_swf6` | 42 | 9.1s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 111 | `form_loader_encoding_1` | 1 | 9.0s |  |
| 112 | `function_suppress_and_preload` | 28 | 9.0s |  |
| 113 | `get_variable_in_scope` | 29 | 9.1s |  |
| 114 | `getproperty` | 28 | 9.0s |  |
| 115 | `getproperty_swf4` | 28 | 8.8s |  |
| 116 | `getproperty_swf5` | 28 | 8.6s |  |
| 117 | `global_array` | 3 | 8.6s |  |
| 118 | `global_is_bare` | 7 | 8.5s |  |
| 119 | `globals_swf5` | 304 | 8.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 120 | `globals_swf6` | 304 | 8.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 121 | `globals_swf7` | 304 | 8.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 122 | `globals_swf8` | 304 | 8.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 123 | `goto_advance1` | 6 | 8.6s |  |
| 124 | `goto_advance2` | 2 | 8.6s |  |
| 125 | `goto_both_ways1` | 3 | 8.6s |  |
| 126 | `goto_both_ways2` | 3 | 8.6s |  |
| 127 | `goto_execution_order` | 2 | 8.5s |  |
| 128 | `goto_execution_order2` | 2 | 8.6s |  |
| 129 | `goto_frame_number` | 3 | 8.7s |  |
| 130 | `goto_rewind1` | 1 | 8.8s |  |
| 131 | `goto_rewind2` | 3 | 8.6s |  |
| 132 | `goto_rewind3` | 2 | 8.7s |  |
| 133 | `greater_swf6` | 1175 | 10.6s |  |
| 134 | `greater_swf7` | 1175 | 10.6s |  |
| 135 | `greaterthan_swf5` | 1 | 8.6s |  |
| 136 | `greaterthan_swf8` | 1 | 8.6s |  |
| 137 | `has_own_property` | 32 | 8.8s |  |
| 138 | `hittest_lockroot` | 15 | 8.9s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 139 | `hittest_winding_rule` | 12 | 8.8s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 140 | `infinite_recursion_function` | 4 | 8.7s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 141 | `infinite_recursion_function_in_setter` | 131 | 8.6s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 142 | `infinite_recursion_virtual_property` | 67 | 8.8s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 143 | `init_array_invalid` | 4 | 9.0s |  |
| 144 | `init_object_invalid` | 4 | 8.9s |  |
| 145 | `is_finite` | 49 | 8.9s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 146 | `is_finite_swf6` | 49 | 9.0s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 147 | `is_prototype_of` | 89 | 8.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 148 | `issue_1086` | 1 | 8.8s |  |
| 149 | `issue_1671` | 0 | 8.8s |  |
| 150 | `issue_1906` | 4 | 8.8s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 151 | `issue_2166` | 9 | 8.9s |  |
| 152 | `issue_3446` | 1 | 8.8s |  |
| 153 | `issue_3522` | 2 | 8.8s |  |
| 154 | `issue_4377` | 2 | 8.8s |  |
| 155 | `issue_710` | 4 | 8.8s |  |
| 156 | `issue_768` | 3 | 9.0s | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 157 | `issue_9327` | 2 | 8.6s |  |
| 158 | `issue_9885` | 2 | 8.5s |  |
| 159 | `key_isToggled` | 9 | 8.5s |  |
| 160 | `lessthan` | 41 | 8.5s |  |
| 161 | `lessthan2_swf5` | 1226 | 10.5s |  |
| 162 | `lessthan2_swf6` | 1226 | 10.7s |  |
| 163 | `lessthan2_swf7` | 1226 | 10.6s |  |
| 164 | `lessthan_swf4` | 902 | 9.8s |  |
| 165 | `lessthan_swf4_alt` | 41 | 8.6s |  |
| 166 | `lessthan_swf5` | 41 | 8.6s |  |
| 167 | `loadmovie` | 2 | 8.5s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 168 | `loadmovie_fail` | 2 | 8.5s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 169 | `loadmovie_method` | 2 | 8.5s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 170 | `loadmovie_replace_root` | 5 | 8.5s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/ROOT_REPLACEMENT_PLAN.md) |
| 171 | `loadmovienum` | 3 | 8.5s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 172 | `loadvariables` | 2 | 8.8s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/incomplete/LOADVARIABLES_PLAN.md) |
| 173 | `loadvariablesnum` | 2 | 8.8s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/incomplete/LOADVARIABLES_PLAN.md) |
| 174 | `local_to_global` | 49 | 8.8s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 175 | `localconnection_properties` | 8 | 8.8s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 176 | `lock_root` | 1 | 8.8s |  |
| 177 | `logical_ops_swf4` | 90 | 8.8s |  |
| 178 | `logical_ops_swf8` | 108 | 8.8s |  |
| 179 | `looping` | 6 | 8.7s |  |
| 180 | `mask_reapply` | 0 | 8.8s |  |
| 181 | `mask_with_drawing` | 0 | 8.8s |  |
| 182 | `math_min_max` | 101 | 8.9s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 183 | `math_swf6` | 530 | 9.2s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 184 | `math_swf7` | 530 | 9.2s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 185 | `math_swf8` | 530 | 9.1s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 186 | `matrix` | 171 | 9.2s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 187 | `mcl_getprogress` | 30 | 13.5s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 188 | `mcl_loadclip` | 149 | 8.8s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 189 | `mcl_loadclip_properties` | 6 | 8.8s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 190 | `mcl_mislabeled_target` | 6 | 8.6s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 191 | `mcl_target_gif87a` | 6 | 9.1s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 192 | `mcl_target_gif89a` | 6 | 9.1s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 193 | `mcl_target_jpg` | 6 | 8.7s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 194 | `mcl_target_png` | 6 | 8.7s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 195 | `mcl_unloadclip` | 5 | 8.6s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 196 | `mouse_events` | 8 | 8.6s | [22](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 197 | `mouse_hover_events_while_dragging` | 1 | 8.8s | [8](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 198 | `mouse_listeners` | 67 | 8.6s |  |
| 199 | `mouse_wheel_enabled` | 2 | 8.7s |  |
| 200 | `movieclip_begin_gradient_fill` | 0 | 9.2s |  |
| 201 | `movieclip_blend_mode_property` | 35 | 9.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 202 | `movieclip_depth_methods` | 98 | 8.7s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 203 | `movieclip_focusenabled` | 99 | 8.6s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 204 | `movieclip_get_instance_at_depth` | 28 | 8.5s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 205 | `movieclip_hittest` | 92 | 8.6s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 206 | `movieclip_line_gradient_style` | 0 | 10.4s |  |
| 207 | `movieclip_name_from_timeline` | 13 | 8.7s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 208 | `movieclip_prototype_extension` | 5 | 8.7s |  |
| 209 | `moviecliploader_flashvars` | 4 | 8.8s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 210 | `mutable_this` | 18 | 8.8s | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 211 | `nested_textfields_in_buttons` | 0 | 8.6s |  |
| 212 | `netstream_play_flv_screen` | 0 | 21.6s |  |
| 213 | `new_method_wrap` | 4 | 8.7s |  |
| 214 | `new_object_enumerate` | 7 | 8.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 215 | `new_object_wrap` | 4 | 8.7s |  |
| 216 | `o` | 3 | 8.7s |  |
| 217 | `object_constructor` | 33 | 8.7s |  |
| 218 | `object_function` | 32 | 8.7s |  |
| 219 | `object_properties` | 31 | 8.9s | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 220 | `object_prototypes` | 74 | 8.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 221 | `object_string_coerce_swf5` | 62 | 8.8s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 222 | `object_string_coerce_swf6` | 68 | 8.7s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 223 | `parse_int` | 64 | 8.9s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 224 | `placeobject_occupied_depth` | 6 | 8.8s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 225 | `point` | 175 | 9.0s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 226 | `primitive_instanceof` | 37 | 8.7s |  |
| 227 | `primitive_type_globals` | 557 | 10.4s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 228 | `printjob_props_swf5` | 45 | 8.8s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 229 | `printjob_props_swf6` | 45 | 8.8s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 230 | `printjob_props_swf7` | 45 | 8.7s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 231 | `prototype_delete` | 12 | 8.8s |  |
| 232 | `prototype_enumerate` | 5 | 8.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 233 | `prototype_properties` | 17 | 8.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 234 | `rectangle` | 745 | 9.5s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 235 | `recursive_prototypes` | 0 | 8.6s |  |
| 236 | `remove_movie_clip` | 29 | 8.7s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 237 | `sandbox_type_local_file` | 1 | 9.2s |  |
| 238 | `sandbox_type_local_network` | 1 | 9.2s |  |
| 239 | `set_variable_scope` | 58 | 8.9s |  |
| 240 | `single_frame` | 1 | 9.0s |  |
| 241 | `slash_syntax` | 14 | 8.8s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 242 | `sound_props_swf5` | 68 | 8.6s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 243 | `sound_props_swf6` | 68 | 8.6s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 244 | `sound_start_load` | 0 | 8.6s |  |
| 245 | `stage_display_state` | 16 | 8.5s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 246 | `stage_object_enumerate` | 4 | 8.5s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 247 | `stage_object_properties` | 241 | 8.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 248 | `stage_object_properties_get_var` | 5 | 8.5s |  |
| 249 | `stage_object_properties_swf6` | 231 | 8.8s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 250 | `stage_property_representation` | 586 | 8.5s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 251 | `stage_scale_mode` | 39 | 8.5s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 252 | `strictequals_swf6` | 902 | 10.0s |  |
| 253 | `strictly_equals` | 7 | 8.5s |  |
| 254 | `string_coercion` | 117 | 8.8s | [36](ruffle-tests/_investigation/complete/string_coercion.md) |
| 255 | `string_methods` | 285 | 9.1s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 256 | `string_methods_negative_args` | 240 | 8.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 257 | `string_methods_swfv5` | 275 | 9.2s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 258 | `string_ops_swf6` | 95 | 8.7s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 259 | `string_paths_basic` | 4 | 8.7s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 260 | `string_paths_timer` | 0 | 8.5s |  |
| 261 | `string_paths_variable_alias` | 4 | 8.5s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 262 | `swf4_actions_bool` | 96 | 8.5s |  |
| 263 | `swf4_bool` | 4 | 8.5s |  |
| 264 | `swf4_function_calls` | 7 | 8.5s |  |
| 265 | `swf5_encoding` | 3 | 8.5s |  |
| 266 | `swf5_no_closure` | 19 | 10.1s | [5](ruffle-tests/_investigation/blocked/CLOSURE_CAPTURE_PLAN.md) [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 267 | `swf6_case_insensitive` | 42 | 8.6s | [38](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 268 | `swf6_string_as_bool` | 15 | 8.6s | [38](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 269 | `swf7_case_sensitive` | 44 | 8.5s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 270 | `tab_ordering_automatic_basic` | 92 | 8.7s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 271 | `tab_ordering_automatic_order_grid` | 21 | 8.6s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 272 | `tab_ordering_children` | 208 | 8.8s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 273 | `tab_ordering_custom_basic` | 71 | 8.8s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 274 | `tab_ordering_custom_duplicate_index` | 22 | 8.9s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 275 | `tab_ordering_custom_i32_vs_u32` | 12 | 8.6s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 276 | `tab_ordering_custom_m1` | 29 | 8.7s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 277 | `tab_ordering_properties_tab_index_edge_case` | 4 | 8.5s |  |
| 278 | `tab_ordering_reverse` | 51 | 8.6s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 279 | `target_clip_removed` | 5 | 8.6s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 280 | `target_path` | 14 | 8.4s |  |
| 281 | `text_format` | 1146 | 8.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 282 | `text_format_display` | 21 | 8.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 283 | `text_format_font_max_length` | 2 | 8.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 284 | `text_format_rounding_swf7` | 840 | 8.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 285 | `text_format_rounding_swf8` | 840 | 8.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 286 | `textfield_background_color` | 11 | 8.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 287 | `textfield_border_color` | 11 | 8.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 288 | `textfield_maxchars` | 3 | 8.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 289 | `textfield_properties` | 44 | 8.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 290 | `textfield_props_swf6` | 210 | 8.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 291 | `textfield_props_swf7` | 210 | 8.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 292 | `textfield_props_swf8` | 210 | 8.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 293 | `textfield_text` | 7 | 8.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 294 | `this_swf5` | 41 | 8.5s | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 295 | `this_swf6` | 41 | 8.5s | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 296 | `this_swf7` | 41 | 8.5s | [43](ruffle-tests/_investigation/complete/this_swf7.md) |
| 297 | `timeline_function_def` | 7 | 8.6s |  |
| 298 | `transform` | 70 | 8.6s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 299 | `try_catch_finally` | 118 | 8.7s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 300 | `try_finally_simple` | 16 | 8.5s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 301 | `typeof` | 22 | 8.5s |  |
| 302 | `typeof_globals` | 7 | 8.5s |  |
| 303 | `uncaught_exception` | 1 | 8.5s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 304 | `uncaught_exception_bubbled` | 1 | 8.5s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 305 | `undefined_to_string_swf6` | 4 | 8.5s |  |
| 306 | `unescape` | 43 | 8.5s |  |
| 307 | `unload_clip_event` | 4 | 8.6s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 308 | `unloadmovie` | 4 | 8.6s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 309 | `unloadmovie_method` | 3 | 8.6s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 310 | `unloadmovienum` | 13 | 8.6s | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 311 | `use_hand_cursor` | 8 | 8.5s |  |
| 312 | `variable_args` | 5 | 8.7s |  |
| 313 | `waitforframe` | 7 | 8.7s |  |
| 314 | `waitforframe2` | 16 | 10.3s |  |
| 315 | `watch` | 117 | 8.8s | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 316 | `watch_virtual_property_proto` | 2 | 8.6s | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 317 | `with` | 49 | 8.6s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 318 | `with_return` | 2 | 8.5s |  |
| 319 | `with_variable_scopes` | 43 | 8.7s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 320 | `xml` | 15 | 8.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 321 | `xml_append_child` | 28 | 8.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 322 | `xml_append_child_with_parent` | 20 | 8.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 323 | `xml_attributes_read` | 4 | 8.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 324 | `xml_cdata` | 11 | 8.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 325 | `xml_child_nodes_edge_cases` | 4 | 8.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 326 | `xml_clone_expandos` | 19 | 8.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 327 | `xml_first_last_child` | 8 | 8.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 328 | `xml_has_child_nodes` | 3 | 8.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 329 | `xml_idmap` | 21 | 8.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 330 | `xml_ignore_comments` | 21 | 8.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 331 | `xml_ignore_white` | 34 | 9.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 332 | `xml_insert_before` | 20 | 8.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 333 | `xml_inspect_createmethods` | 15 | 8.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 334 | `xml_inspect_doctype` | 7 | 8.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 335 | `xml_inspect_parsexml` | 62 | 8.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 336 | `xml_inspect_xmldecl` | 7 | 8.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 337 | `xml_namespaces` | 203 | 8.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 338 | `xml_parent_and_child` | 5 | 8.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 339 | `xml_remove_node` | 22 | 8.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 340 | `xml_reparenting` | 14 | 8.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 341 | `xml_siblings` | 10 | 8.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 342 | `xml_to_string` | 13 | 8.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 343 | `xml_to_string_comment` | 1 | 8.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 344 | `xml_unescaping` | 23 | 9.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 345 | `xmlnode_proto` | 1 | 9.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**71 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `textfield_props_swf5` | 99.4% | 174 | 175 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 2 | `date` | 99.2% | 6284 | 6335 | 51 | [7](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 3 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 4 | `textfield_variable` | 96.3% | 78 | 81 | 3 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 5 | `hittest_morph` | 95.7% | 67 | 70 | 3 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MORPH_INTERPOLATION_PLAN.md) |
| 6 | `movieclip_default_state` | 95.7% | 66 | 69 | 3 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 7 | `selection` | 95.6% | 434 | 454 | 20 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 8 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 9 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 10 | `movieclip_library_state_values` | 89.7% | 70 | 78 | 8 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 11 | `string_paths_other` | 86.1% | 31 | 36 | 5 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 12 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 13 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 14 | `this_scoping` | 80.8% | 42 | 52 | 10 | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 15 | `function_base_clip_removed` | 80.0% | 20 | 25 | 5 |  |
| 16 | `movieclip_hittest_shapeflag` | 78.7% | 266 | 338 | 72 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 18 | `edittext_restrict` | 77.0% | 147 | 191 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `tab_ordering_tabbable` | 76.6% | 36 | 47 | 11 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 20 | `loadmovie_flashvars` | 75.0% | 3 | 4 | 1 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 21 | `tab_ordering_automatic_order_same_position` | 75.0% | 9 | 12 | 3 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 22 | `edittext_scroll` | 74.1% | 40 | 54 | 14 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `add_property` | 73.3% | 11 | 15 | 4 | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `global_swf6_7_8` | 73.3% | 11 | 15 | 4 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 25 | `rewind_depth` | 73.3% | 22 | 30 | 8 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 26 | `global_swf5_6_7_8_9` | 69.7% | 798 | 1145 | 347 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 27 | `edittext_tab_focus` | 69.2% | 9 | 13 | 4 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `register_underflow` | 69.2% | 18 | 26 | 8 | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 29 | `unload` | 69.2% | 36 | 52 | 16 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 30 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `mcl_as_broadcaster` | 66.7% | 8 | 12 | 4 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 33 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 34 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 35 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 37 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `edittext_align` | 60.0% | 36 | 60 | 24 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 47 | `execution_order4` | 58.3% | 7 | 12 | 5 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 48 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 49 | `parse_float` | 58.1% | 43 | 74 | 31 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 50 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 51 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 53 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 55 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 56 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 57 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 58 | `edittext_html_condensewhite_swf7` | 53.4% | 166 | 311 | 145 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 59 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 60 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 61 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 62 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 63 | `button_keypress_vs_tab` | 50.0% | 10 | 20 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 64 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `edittext_place_caret` | 50.0% | 1 | 2 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 66 | `edittext_programmatic_focus` | 50.0% | 6 | 12 | 6 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 68 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 69 | `movieclip_in_removed_button` | 50.0% | 2 | 4 | 2 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 70 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 71 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 11.1s |  |
| 2 | `goto_methods` | 11.0s | [11](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 3 | `native_objects_swf6` | 11.1s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `native_objects_swf7` | 11.3s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `native_objects_swf8` | 11.1s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 31.3s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 31.3s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 18.5s | [44](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**265 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `textfield_props_swf5` | 99.4% | 174/175 | 175 | 175 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 2 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [7](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 3 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 4 | `textfield_variable` | 96.3% | 78/81 | 81 | 81 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 5 | `hittest_morph` | 95.7% | 67/70 | 70 | 70 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MORPH_INTERPOLATION_PLAN.md) |
| 6 | `movieclip_default_state` | 95.7% | 66/69 | 69 | 69 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 7 | `selection` | 95.6% | 434/454 | 454 | 454 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 8 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 9 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 10 | `movieclip_library_state_values` | 89.7% | 70/78 | 74 | 78 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 11 | `string_paths_other` | 86.1% | 31/36 | 36 | 36 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 12 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 13 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 14 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 15 | `function_base_clip_removed` | 80.0% | 20/25 | 25 | 25 |  |
| 16 | `movieclip_hittest_shapeflag` | 78.7% | 266/338 | 338 | 338 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 18 | `edittext_restrict` | 77.0% | 147/191 | 191 | 191 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `tab_ordering_tabbable` | 76.6% | 36/47 | 47 | 47 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 20 | `loadmovie_flashvars` | 75.0% | 3/4 | 4 | 4 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 21 | `tab_ordering_automatic_order_same_position` | 75.0% | 9/12 | 12 | 12 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 22 | `edittext_scroll` | 74.1% | 40/54 | 54 | 54 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `add_property` | 73.3% | 11/15 | 15 | 15 | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `global_swf6_7_8` | 73.3% | 11/15 | 15 | 15 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 25 | `rewind_depth` | 73.3% | 22/30 | 30 | 30 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 26 | `global_swf5_6_7_8_9` | 69.7% | 798/1145 | 1145 | 1145 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 27 | `edittext_tab_focus` | 69.2% | 9/13 | 13 | 13 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 29 | `unload` | 69.2% | 36/52 | 52 | 52 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 30 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `mcl_as_broadcaster` | 66.7% | 8/12 | 12 | 12 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 33 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 34 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 35 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 37 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 47 | `execution_order4` | 58.3% | 7/12 | 11 | 12 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 48 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 49 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 50 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 51 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 53 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 55 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 56 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 57 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 58 | `edittext_html_condensewhite_swf7` | 53.4% | 166/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 59 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 60 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 61 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 62 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 63 | `button_keypress_vs_tab` | 50.0% | 10/20 | 20 | 20 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 64 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `edittext_place_caret` | 50.0% | 1/2 | 2 | 2 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 66 | `edittext_programmatic_focus` | 50.0% | 6/12 | 12 | 12 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 68 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 69 | `movieclip_in_removed_button` | 50.0% | 2/4 | 4 | 4 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 70 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 71 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 72 | `edittext_html_condensewhite_swf8` | 49.8% | 155/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 73 | `selection_handlers` | 48.1% | 13/27 | 19 | 27 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 74 | `goto_label` | 47.1% | 8/17 | 9 | 17 | [11](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 75 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 76 | `register_globals_across_frames` | 46.7% | 7/15 | 15 | 15 | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 77 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 79 | `mouse_pos` | 43.8% | 291/665 | 656 | 665 | [22](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 80 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 81 | `mouse_pos_with_scale_factor` | 42.7% | 111/260 | 251 | 260 | [22](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 82 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 83 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 84 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 85 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 86 | `property_invalid_base_clip` | 38.9% | 14/36 | 35 | 36 |  |
| 87 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 88 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 89 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 90 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 91 | `on_construct` | 36.0% | 9/25 | 12 | 25 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 92 | `button_keypress` | 33.3% | 1/3 | 2 | 3 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 93 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 94 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 95 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 96 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 97 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 98 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 99 | `input_dead_keys_windows` | 33.3% | 5/15 | 14 | 15 |  |
| 100 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 101 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 102 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 103 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 104 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 105 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 106 | `swf6_to_5_cross_call` | 31.0% | 9/29 | 11 | 29 | [38](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 107 | `cross_movie_root` | 30.0% | 3/10 | 10 | 10 |  |
| 108 | `loadmovie_registerclass` | 30.0% | 9/30 | 24 | 30 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 109 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 110 | `default_names` | 28.8% | 15/52 | 48 | 52 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 111 | `string_paths_eval2` | 28.6% | 2/7 | 2 | 7 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 112 | `swf5_to_6_cross_call` | 27.6% | 8/29 | 11 | 29 | [38](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 113 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 114 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 115 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 116 | `button_keypress_vs_textinput` | 25.0% | 1/4 | 2 | 4 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 117 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 118 | `goto_frame` | 25.0% | 3/12 | 10 | 12 | [11](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 119 | `issue_2870` | 25.0% | 2/8 | 8 | 3 |  |
| 120 | `loadmovie_var_persistence` | 25.0% | 2/8 | 2 | 8 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 121 | `loadvariables2` | 25.0% | 2/8 | 2 | 8 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/incomplete/LOADVARIABLES_PLAN.md) |
| 122 | `mouse_events_visible_enabled` | 25.0% | 3/12 | 10 | 12 | [22](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 123 | `text_blocks_clicks` | 25.0% | 1/4 | 2 | 4 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 124 | `textsnapshot_props_swf5` | 25.0% | 14/56 | 38 | 56 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 125 | `button_keypress_vs_press` | 24.0% | 6/25 | 24 | 25 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 126 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 127 | `focus_mouse` | 22.2% | 10/45 | 30 | 45 | [5](ruffle-tests/_investigation/blocked/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 128 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 129 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 130 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 131 | `movieclip_init_object` | 20.0% | 1/5 | 2 | 5 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 132 | `tell_target_invalid_swf6` | 20.0% | 1/5 | 5 | 5 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 133 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 134 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [44](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 135 | `focus_remove` | 18.2% | 6/33 | 21 | 33 |  |
| 136 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 | [11](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 137 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 4 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 138 | `tab_ordering_events` | 18.0% | 27/150 | 118 | 150 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 139 | `super_edge_cases` | 17.9% | 7/39 | 33 | 39 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 140 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 141 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 142 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 143 | `tell_target_invalid` | 16.7% | 1/6 | 5 | 6 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 144 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 145 | `register_class_swf6` | 16.2% | 6/37 | 8 | 37 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 146 | `focus_visibility_change` | 15.6% | 7/45 | 33 | 45 |  |
| 147 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 6 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 148 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 6 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 149 | `register_and_init_order` | 14.7% | 34/231 | 85 | 231 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 150 | `path_string` | 14.6% | 47/322 | 300 | 322 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 151 | `button_key_events` | 14.3% | 2/14 | 9 | 14 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 152 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 153 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 154 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 155 | `tab_ordering_movieclip_enabled_default` | 13.6% | 63/462 | 432 | 462 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 156 | `removed_clip_halts_script` | 13.3% | 2/15 | 13 | 15 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 157 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 158 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 159 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 160 | `textsnapshot_props_swf6` | 12.5% | 7/56 | 38 | 56 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 161 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 162 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 163 | `mcl_events_swf_version` | 12.1% | 28/232 | 37 | 232 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [24](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 164 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 165 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 1 | 9 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 166 | `focus_keyboard_press` | 10.1% | 15/148 | 148 | 60 | [5](ruffle-tests/_investigation/blocked/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 167 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 168 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 169 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 170 | `tell_target` | 8.1% | 3/37 | 34 | 37 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 171 | `call` | 7.9% | 5/63 | 28 | 63 |  |
| 172 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 173 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 174 | `tab_ordering_events_mouse` | 7.7% | 5/65 | 47 | 65 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 175 | `register_class` | 7.6% | 5/66 | 44 | 66 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 176 | `define_local` | 7.4% | 2/27 | 23 | 27 | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 177 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 178 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 179 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 80 | 129 |  |
| 180 | `movieclip_gettextsnapshot` | 6.2% | 7/112 | 42 | 112 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 181 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 182 | `swf4_actions_coercion_order` | 5.7% | 9/158 | 93 | 158 | [38](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 183 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 184 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [44](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 185 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 186 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 187 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 188 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 189 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 190 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 191 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 192 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 193 | `movieclip_invalid_get_bounds_2` | 4.0% | 3/75 | 3 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 194 | `movieclip_invalid_get_bounds_1` | 2.7% | 2/75 | 3 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 195 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 196 | `button_key_events_special` | 2.2% | 1/45 | 38 | 45 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 197 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 198 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 199 | `netconnection_send_remote` | 2.0% | 1/50 | 1 | 50 |  |
| 200 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/incomplete/ROOT_REPLACEMENT_PLAN.md) |
| 201 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/incomplete/ROOT_REPLACEMENT_PLAN.md) |
| 202 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 203 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 204 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 205 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 206 | `global_proto_decls` | 0.4% | 16/4497 | 572 | 4497 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 207 | `localconnection` | 0.3% | 2/579 | 4 | 579 |  |
| 208 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 209 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 210 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 211 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 212 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 213 | `click_block` | 0.0% | 0/5 | 0 | 5 | [22](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 214 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 215 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 216 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 217 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 218 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 219 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 220 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 221 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 222 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 223 | `edittext_input_newlines` | 0.0% | 0/9 | 4 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 224 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 225 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 226 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 227 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 228 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 229 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 230 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 | [5](ruffle-tests/_investigation/blocked/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 231 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 232 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 233 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 234 | `global_proto_decls_delete` | 0.0% | 0/4158 | 216 | 4158 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 235 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 236 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 237 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 238 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/incomplete/LOADVARIABLES_PLAN.md) |
| 239 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/incomplete/ROOT_REPLACEMENT_PLAN.md) |
| 240 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 241 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 242 | `movieclip_methods_with_loaded_image` | 0.0% | 0/8 | 8 | 4 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 243 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 244 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 245 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 246 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 247 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 248 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 249 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 250 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 251 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 252 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 253 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 254 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 255 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 256 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 257 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 258 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 259 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 260 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 261 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 262 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 263 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 264 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 265 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 6 | 8 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 3 | 5 |
| 5 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/blocked/CLOSURE_CAPTURE_PLAN.md) | 4 | 1 | 3 |
| 6 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 7 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 8 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 9 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 13 | 1 |
| 10 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 6 | 2 | 4 |
| 11 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) | 4 | 0 | 4 |
| 12 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 13 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 15 | 16 |
| 14 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 4 | 13 |
| 15 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 16 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 17 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) | 49 | 20 | 29 |
| 18 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 19 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/incomplete/LOADVARIABLES_PLAN.md) | 4 | 2 | 2 |
| 20 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 21 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/incomplete/MORPH_INTERPOLATION_PLAN.md) | 1 | 0 | 1 |
| 22 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) | 5 | 1 | 4 |
| 23 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 19 | 39 |
| 24 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) | 16 | 11 | 5 |
| 25 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 6 | 11 |
| 26 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 27 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 28 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 2 | 6 |
| 29 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 2 | 1 |
| 30 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 7 | 5 |
| 31 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 4 | 11 |
| 32 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/incomplete/ROOT_REPLACEMENT_PLAN.md) | 4 | 1 | 3 |
| 33 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 34 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 6 | 3 |
| 35 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 6 | 1 |
| 36 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 37 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 6 | 7 |
| 38 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 2 | 3 |
| 39 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 10 | 6 |
| 40 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 4 | 15 |
| 41 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 27 | 43 |
| 42 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) | 5 | 4 | 1 |
| 43 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 44 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 45 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 46 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 9 | 3 |
| 47 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 3 | 2 |
| 48 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 230 | 147 | 83 |
