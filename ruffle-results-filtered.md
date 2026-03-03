# Ruffle Test Results (Filtered)

**Date**: 2026-03-03 20:56 UTC

**Git SHA**: `020dca16a0`

**Run Duration**: 128m 53s

**Filtered**: 142 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 477 |
| Passing | **369** (77.4%) |
| Failing | 108 |
| Total expected lines | 70891 |
| Matching lines | 55596 (78.4%) |
| Mismatched lines | 15295 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 99 | 91.7% |
| Segfault | 4 | 3.7% |
| Compile Fail | 2 | 1.9% |
| Runtime Error | 2 | 1.9% |
| Timeout | 1 | 0.9% |

## Passing Tests

**369 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 12.2s |  |
| 2 | `action_to_integer` | 28 | 12.1s |  |
| 3 | `add` | 28 | 12.0s |  |
| 4 | `add2` | 354 | 12.2s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 12.0s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 12.0s |  |
| 7 | `add_swf5` | 28 | 12.1s |  |
| 8 | `arguments` | 127 | 12.0s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 12.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 12.0s |  |
| 11 | `array_constructor` | 30 | 12.1s |  |
| 12 | `array_enumerate` | 4 | 12.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 12.2s |  |
| 14 | `array_properties` | 36 | 12.3s |  |
| 15 | `array_prototyping` | 12 | 12.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 12.2s |  |
| 17 | `array_sort_random` | 443 | 12.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 12.3s |  |
| 19 | `array_trivial` | 209 | 12.2s |  |
| 20 | `as1_constructor_v6` | 35 | 12.0s |  |
| 21 | `as1_constructor_v7` | 35 | 14.0s |  |
| 22 | `as2_oop` | 13 | 12.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 12.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 12.8s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 12.8s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster_initialize` | 10 | 12.6s |  |
| 27 | `as_set_prop_flags` | 79 | 12.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 28 | `as_set_prop_flags_version` | 31 | 12.6s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version_swf5` | 1 | 12.9s |  |
| 30 | `as_set_prop_flags_version_swf6` | 1 | 12.9s |  |
| 31 | `as_set_prop_flags_version_swf7` | 1 | 12.6s |  |
| 32 | `as_set_prop_flags_version_swf8` | 1 | 12.6s |  |
| 33 | `as_set_prop_flags_version_swf9` | 1 | 12.6s |  |
| 34 | `as_transformed_flag` | 20 | 12.8s |  |
| 35 | `attach_movie` | 59 | 12.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 36 | `attach_movie_stop` | 3 | 12.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 37 | `bad_placeobject_clipaction` | 2 | 13.7s |  |
| 38 | `bad_swf_tag_past_eof` | 0 | 11.8s |  |
| 39 | `bitand` | 1058 | 14.3s |  |
| 40 | `bitmap_data_colortransform` | 0 | 12.1s |  |
| 41 | `bitmap_data_fillrect` | 0 | 11.9s |  |
| 42 | `bitmap_data_max_size_swf10` | 12 | 11.8s |  |
| 43 | `bitmap_data_max_size_swf9` | 10 | 11.8s |  |
| 44 | `bitmap_data_perlinnoise` | 0 | 12.6s |  |
| 45 | `bitmap_data_pixeldissolve_image` | 0 | 12.2s |  |
| 46 | `bitmapdata_applyfilter_colormatrix` | 0 | 11.8s |  |
| 47 | `bitor` | 1058 | 14.2s |  |
| 48 | `biturshift` | 14 | 11.9s |  |
| 49 | `biturshift_swf8` | 14 | 11.9s |  |
| 50 | `bitxor` | 1058 | 14.1s |  |
| 51 | `boxed_primitives` | 24 | 12.0s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 52 | `button_children` | 8 | 11.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 53 | `button_goto` | 4 | 11.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_order` | 2 | 12.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_properties_special_cases` | 22 | 12.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_v5` | 18 | 12.5s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_v6` | 18 | 12.6s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `call_method_empty_name` | 1 | 12.4s |  |
| 59 | `capabilities_resolution` | 8 | 12.4s |  |
| 60 | `catch_references_registers` | 2 | 12.4s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 61 | `clip_constructors` | 8 | 12.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 62 | `clip_events` | 19 | 12.1s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 63 | `clone_sprite_types` | 24 | 11.8s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 64 | `closure_scope` | 7 | 11.8s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 65 | `color` | 57 | 12.0s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 66 | `color_transform` | 48 | 11.9s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 67 | `conflicting_instance_names` | 23 | 11.8s |  |
| 68 | `constructor_function` | 2 | 11.7s |  |
| 69 | `context_menu` | 39 | 11.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 70 | `context_menu_item` | 41 | 11.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 71 | `create_empty_movie_clip` | 3 | 11.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 72 | `define_function2` | 8 | 11.7s |  |
| 73 | `define_function2_preload` | 13 | 11.7s |  |
| 74 | `define_function2_preload_order` | 4 | 13.7s |  |
| 75 | `define_function_case_sensitive` | 2 | 12.2s |  |
| 76 | `delete` | 3 | 12.2s |  |
| 77 | `display_object_properties` | 2 | 12.0s |  |
| 78 | `divide_swf4` | 107 | 12.3s |  |
| 79 | `do_init_action` | 3 | 12.3s |  |
| 80 | `do_init_action_child` | 12 | 12.2s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 81 | `duplicate_movie_clip` | 20 | 12.1s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 82 | `edittext_align` | 60 | 12.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 83 | `edittext_align_trailing_spaces_swf7` | 576 | 11.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `edittext_align_trailing_spaces_swf8` | 576 | 11.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 85 | `edittext_antialiastype` | 296 | 12.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 86 | `edittext_autosize` | 71 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `edittext_autosize_setter` | 20 | 14.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 88 | `edittext_default_format` | 221 | 12.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 89 | `edittext_default_format_font_style` | 335 | 12.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 90 | `edittext_font_size` | 45 | 12.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 91 | `edittext_hscroll` | 27 | 12.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 92 | `edittext_html_align_swf7` | 52 | 12.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `edittext_html_align_swf8` | 52 | 12.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 94 | `edittext_html_color` | 114 | 12.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 95 | `edittext_html_entity` | 4 | 12.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 96 | `edittext_html_roundtrip` | 17 | 12.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `edittext_leading` | 9 | 11.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 98 | `edittext_letter_spacing` | 15 | 12.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 99 | `edittext_margins` | 25 | 11.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 100 | `edittext_programmatic_focus` | 12 | 12.0s | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 101 | `edittext_tag_indent` | 31 | 12.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 102 | `edittext_text_height_leading` | 20 | 12.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 103 | `edittext_underline` | 40 | 12.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 104 | `edittext_width_height` | 103 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 105 | `empty_movieclip_can_attach_movies` | 11 | 12.1s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 106 | `enumerate` | 64 | 12.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 107 | `equals` | 32 | 12.1s |  |
| 108 | `equals2_swf5` | 926 | 13.7s |  |
| 109 | `equals2_swf6` | 926 | 13.8s |  |
| 110 | `equals2_swf7` | 926 | 13.8s |  |
| 111 | `equals_swf4` | 665 | 12.8s |  |
| 112 | `equals_swf4_alt` | 32 | 12.1s |  |
| 113 | `equals_swf5` | 32 | 12.1s |  |
| 114 | `error` | 58 | 12.1s |  |
| 115 | `escape` | 14 | 12.1s |  |
| 116 | `execution_order1` | 5 | 12.6s |  |
| 117 | `execution_order2` | 7 | 12.3s |  |
| 118 | `execution_order3` | 4 | 12.4s |  |
| 119 | `execution_order4` | 12 | 12.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 120 | `export_assets` | 3 | 12.0s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 121 | `extends_chain` | 134 | 12.5s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 122 | `extends_native_type` | 11 | 12.1s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 123 | `focusrect_mouse_swf8` | 0 | 12.1s |  |
| 124 | `focusrect_mouse_swf9` | 0 | 12.3s |  |
| 125 | `focusrect_swf5` | 6 | 11.1s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 126 | `frame_size_translated_negative` | 21 | 10.9s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 127 | `frame_size_translated_positive` | 21 | 10.9s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 128 | `function_base_clip` | 8 | 10.9s |  |
| 129 | `function_base_clip_removed` | 25 | 10.9s |  |
| 130 | `function_suppress_and_preload` | 28 | 10.9s |  |
| 131 | `get_variable_in_scope` | 29 | 10.9s |  |
| 132 | `getproperty` | 28 | 10.8s |  |
| 133 | `getproperty_swf4` | 28 | 13.3s |  |
| 134 | `getproperty_swf5` | 28 | 11.9s |  |
| 135 | `global_array` | 3 | 11.9s |  |
| 136 | `global_is_bare` | 7 | 11.8s |  |
| 137 | `global_swf6_7_8` | 15 | 12.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 138 | `globals_swf5` | 304 | 12.4s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 139 | `globals_swf6` | 304 | 12.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 140 | `globals_swf7` | 304 | 12.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 141 | `globals_swf8` | 304 | 12.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 142 | `goto_advance1` | 6 | 12.1s |  |
| 143 | `goto_advance2` | 2 | 12.0s |  |
| 144 | `goto_both_ways1` | 3 | 12.0s |  |
| 145 | `goto_both_ways2` | 3 | 12.0s |  |
| 146 | `goto_execution_order` | 2 | 11.9s |  |
| 147 | `goto_execution_order2` | 2 | 12.0s |  |
| 148 | `goto_frame` | 12 | 12.3s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 149 | `goto_frame2` | 44 | 12.4s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 150 | `goto_frame_number` | 3 | 12.1s |  |
| 151 | `goto_label` | 17 | 12.2s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 152 | `goto_methods` | 40 | 12.1s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 153 | `goto_rewind1` | 1 | 12.0s |  |
| 154 | `goto_rewind2` | 3 | 11.9s |  |
| 155 | `goto_rewind3` | 2 | 12.0s |  |
| 156 | `greater_swf6` | 1175 | 13.9s |  |
| 157 | `greater_swf7` | 1175 | 13.9s |  |
| 158 | `greaterthan_swf5` | 1 | 12.1s |  |
| 159 | `greaterthan_swf8` | 1 | 12.0s |  |
| 160 | `has_own_property` | 32 | 12.0s |  |
| 161 | `hittest_lockroot` | 15 | 12.2s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 162 | `hittest_morph` | 70 | 12.0s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 163 | `hittest_winding_rule` | 12 | 12.1s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 164 | `infinite_recursion_function` | 4 | 11.9s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 165 | `infinite_recursion_function_in_setter` | 131 | 11.9s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 166 | `infinite_recursion_virtual_property` | 67 | 11.9s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 167 | `init_array_invalid` | 4 | 11.9s |  |
| 168 | `init_object_invalid` | 4 | 12.2s |  |
| 169 | `init_object_order` | 15 | 12.0s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 170 | `is_finite` | 49 | 11.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 171 | `is_finite_swf6` | 49 | 11.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 172 | `is_prototype_of` | 89 | 11.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 173 | `issue_1086` | 1 | 11.8s |  |
| 174 | `issue_1671` | 0 | 11.8s |  |
| 175 | `issue_1906` | 4 | 11.8s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 176 | `issue_2166` | 9 | 11.8s |  |
| 177 | `issue_3446` | 1 | 11.8s |  |
| 178 | `issue_3522` | 2 | 11.7s |  |
| 179 | `issue_4377` | 2 | 11.6s |  |
| 180 | `issue_710` | 4 | 11.8s |  |
| 181 | `issue_768` | 3 | 13.2s | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 182 | `issue_9327` | 2 | 12.3s |  |
| 183 | `issue_9885` | 2 | 12.1s |  |
| 184 | `lessthan` | 41 | 11.9s |  |
| 185 | `lessthan2_swf5` | 1226 | 13.9s |  |
| 186 | `lessthan2_swf6` | 1226 | 13.9s |  |
| 187 | `lessthan2_swf7` | 1226 | 13.9s |  |
| 188 | `lessthan_swf4` | 902 | 13.1s |  |
| 189 | `lessthan_swf4_alt` | 41 | 11.9s |  |
| 190 | `lessthan_swf5` | 41 | 11.9s |  |
| 191 | `local_to_global` | 49 | 12.8s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 192 | `localconnection_properties` | 8 | 12.4s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 193 | `lock_root` | 1 | 12.3s |  |
| 194 | `logical_ops_swf4` | 90 | 12.3s |  |
| 195 | `logical_ops_swf8` | 108 | 12.4s |  |
| 196 | `looping` | 6 | 12.4s |  |
| 197 | `mask_reapply` | 0 | 12.4s |  |
| 198 | `mask_with_drawing` | 0 | 12.4s |  |
| 199 | `math_min_max` | 101 | 12.6s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 200 | `math_swf6` | 530 | 12.8s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 201 | `math_swf7` | 530 | 12.8s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 202 | `math_swf8` | 530 | 12.8s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 203 | `matrix` | 171 | 12.8s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 204 | `movieclip_begin_gradient_fill` | 0 | 13.9s |  |
| 205 | `movieclip_blend_mode_property` | 35 | 13.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 206 | `movieclip_create_text_field` | 90 | 12.1s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 207 | `movieclip_default_state` | 69 | 12.1s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 208 | `movieclip_depth_methods` | 98 | 12.1s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 209 | `movieclip_focusenabled` | 99 | 12.0s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 210 | `movieclip_get_instance_at_depth` | 28 | 12.0s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 211 | `movieclip_hittest` | 92 | 12.3s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 212 | `movieclip_in_removed_button` | 4 | 12.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 213 | `movieclip_init_object` | 5 | 12.3s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 214 | `movieclip_line_gradient_style` | 0 | 14.6s |  |
| 215 | `movieclip_name_from_timeline` | 13 | 12.0s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 216 | `movieclip_prototype_extension` | 5 | 12.0s |  |
| 217 | `mutable_this` | 18 | 12.1s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 218 | `named_shapes` | 14 | 12.1s |  |
| 219 | `nan_scale` | 9 | 12.1s |  |
| 220 | `native_double_construct` | 12 | 12.1s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 221 | `native_objects_swf7` | 84 | 12.5s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 222 | `native_objects_swf8` | 84 | 12.6s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 223 | `nested_textfields_in_buttons` | 0 | 12.1s |  |
| 224 | `new_method_wrap` | 4 | 12.1s |  |
| 225 | `new_object_enumerate` | 7 | 12.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 226 | `new_object_wrap` | 4 | 12.0s |  |
| 227 | `o` | 3 | 12.0s |  |
| 228 | `object_constructor` | 33 | 12.0s |  |
| 229 | `object_function` | 32 | 12.0s |  |
| 230 | `object_properties` | 31 | 12.1s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 231 | `object_prototypes` | 74 | 12.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 232 | `object_string_coerce_swf5` | 62 | 12.1s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 233 | `object_string_coerce_swf6` | 68 | 12.1s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 234 | `parse_float` | 74 | 12.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 235 | `parse_int` | 64 | 12.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 236 | `path_string` | 322 | 12.2s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 237 | `place_and_lookup` | 30 | 12.1s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 238 | `placeobject_occupied_depth` | 6 | 12.3s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 239 | `point` | 175 | 12.5s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 240 | `primitive_instanceof` | 37 | 12.2s |  |
| 241 | `primitive_type_globals` | 557 | 14.6s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 242 | `printjob_props_swf5` | 45 | 12.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 243 | `printjob_props_swf6` | 45 | 12.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 244 | `printjob_props_swf7` | 45 | 12.0s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 245 | `property_invalid_base_clip` | 36 | 12.1s |  |
| 246 | `prototype_delete` | 12 | 12.0s |  |
| 247 | `prototype_enumerate` | 5 | 12.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 248 | `prototype_properties` | 17 | 12.1s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 249 | `rectangle` | 745 | 12.7s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 250 | `recursive_prototypes` | 0 | 12.0s |  |
| 251 | `register_class_return_value` | 16 | 12.0s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 252 | `register_globals_across_frames` | 15 | 11.9s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 253 | `register_underflow` | 26 | 11.8s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 254 | `remove_movie_clip` | 29 | 12.0s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 255 | `rewind_depth` | 30 | 12.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 256 | `sandbox_type_local_file` | 1 | 12.3s |  |
| 257 | `sandbox_type_local_network` | 1 | 12.4s |  |
| 258 | `set_interval` | 27 | 12.3s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 259 | `set_variable_scope` | 58 | 12.2s |  |
| 260 | `single_frame` | 1 | 12.2s |  |
| 261 | `slash_syntax` | 14 | 12.4s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 262 | `sound_props_swf5` | 68 | 12.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 263 | `sound_props_swf6` | 68 | 12.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 264 | `sound_start_load` | 0 | 12.5s |  |
| 265 | `stage_display_state` | 16 | 12.7s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 266 | `stage_object_children` | 83 | 12.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 267 | `stage_object_enumerate` | 4 | 12.4s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 268 | `stage_object_properties` | 241 | 12.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 269 | `stage_object_properties_get_var` | 5 | 12.6s |  |
| 270 | `stage_object_properties_swf6` | 231 | 13.1s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 271 | `stage_property_representation` | 586 | 12.8s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 272 | `stage_scale_mode` | 39 | 12.7s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 273 | `strictequals_swf6` | 902 | 14.7s |  |
| 274 | `strictly_equals` | 7 | 12.9s |  |
| 275 | `string_methods` | 285 | 13.5s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 276 | `string_methods_negative_args` | 240 | 12.4s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 277 | `string_methods_swfv5` | 275 | 12.9s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 278 | `string_ops_swf6` | 95 | 12.7s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 279 | `string_paths_basic` | 4 | 12.2s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 280 | `string_paths_eval2` | 7 | 11.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 281 | `string_paths_hidden` | 54 | 11.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 282 | `string_paths_other` | 36 | 11.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 283 | `string_paths_unload` | 1 | 11.9s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 284 | `string_paths_variable_alias` | 4 | 11.7s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 285 | `super_edge_cases` | 39 | 11.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 286 | `swf4_actions_bool` | 96 | 11.8s |  |
| 287 | `swf4_actions_coercion_order` | 158 | 11.8s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 288 | `swf4_bool` | 4 | 11.8s |  |
| 289 | `swf4_function_calls` | 7 | 11.7s |  |
| 290 | `swf5_encoding` | 3 | 11.7s |  |
| 291 | `swf6_case_insensitive` | 42 | 11.9s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 292 | `swf6_string_as_bool` | 15 | 11.8s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 293 | `swf7_case_sensitive` | 44 | 11.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 294 | `tab_ordering_properties_tab_index_edge_case` | 4 | 12.2s |  |
| 295 | `target_clip_swf5` | 2 | 12.0s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 296 | `target_clip_swf6` | 2 | 12.0s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 297 | `target_path` | 14 | 11.9s |  |
| 298 | `tell_target` | 37 | 12.1s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 299 | `tell_target_invalid` | 6 | 12.1s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 300 | `tell_target_invalid_swf6` | 5 | 12.2s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 301 | `text_format` | 1146 | 12.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 302 | `text_format_display` | 21 | 12.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 303 | `text_format_font_max_length` | 2 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 304 | `text_format_rounding_swf7` | 840 | 12.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 305 | `text_format_rounding_swf8` | 840 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 306 | `textfield_background_color` | 11 | 12.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 307 | `textfield_border_color` | 11 | 12.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 308 | `textfield_cache_as_bitmap` | 1 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 309 | `textfield_maxchars` | 3 | 13.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 310 | `textfield_properties` | 44 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 311 | `textfield_props_swf5` | 175 | 12.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 312 | `textfield_props_swf6` | 210 | 12.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 313 | `textfield_props_swf7` | 210 | 12.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 314 | `textfield_props_swf8` | 210 | 12.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 315 | `textfield_text` | 7 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 316 | `textfield_variable` | 81 | 12.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 317 | `textsnapshot_props_swf5` | 56 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 318 | `textsnapshot_props_swf6` | 56 | 12.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 319 | `this_scoping` | 52 | 12.1s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 320 | `this_swf5` | 41 | 12.0s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 321 | `this_swf6` | 41 | 12.0s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 322 | `this_swf7` | 41 | 12.1s | [43](ruffle-tests/_investigation/complete/this_swf7.md) |
| 323 | `timeline_function_def` | 7 | 12.1s |  |
| 324 | `transform` | 70 | 11.9s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 325 | `try_catch_finally` | 118 | 12.0s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 326 | `try_finally_simple` | 16 | 11.8s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 327 | `typeof` | 22 | 11.8s |  |
| 328 | `typeof_globals` | 7 | 11.8s |  |
| 329 | `uncaught_exception` | 1 | 11.8s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 330 | `uncaught_exception_bubbled` | 1 | 11.8s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 331 | `undefined_to_string_swf6` | 4 | 11.8s |  |
| 332 | `unescape` | 43 | 11.8s |  |
| 333 | `unload` | 52 | 12.0s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 334 | `unload_clip_event` | 4 | 11.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 335 | `use_hand_cursor` | 8 | 11.8s |  |
| 336 | `variable_args` | 5 | 11.9s |  |
| 337 | `waitforframe` | 7 | 11.8s |  |
| 338 | `waitforframe2` | 16 | 13.9s |  |
| 339 | `watch` | 117 | 12.3s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 340 | `watch_textfield` | 12 | 12.2s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 341 | `watch_virtual_property_proto` | 2 | 12.1s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 342 | `with` | 49 | 12.1s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 343 | `with_return` | 2 | 12.2s |  |
| 344 | `with_variable_scopes` | 43 | 12.2s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 345 | `xml` | 15 | 12.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 346 | `xml_append_child` | 28 | 12.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 347 | `xml_append_child_with_parent` | 20 | 12.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 348 | `xml_cdata` | 11 | 12.4s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 349 | `xml_child_nodes_edge_cases` | 4 | 12.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 350 | `xml_clone_expandos` | 19 | 12.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 351 | `xml_first_last_child` | 8 | 12.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 352 | `xml_has_child_nodes` | 3 | 12.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 353 | `xml_idmap` | 21 | 12.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 354 | `xml_ignore_comments` | 21 | 12.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 355 | `xml_ignore_white` | 34 | 12.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 356 | `xml_insert_before` | 20 | 12.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 357 | `xml_inspect_createmethods` | 15 | 11.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 358 | `xml_inspect_doctype` | 7 | 11.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 359 | `xml_inspect_parsexml` | 62 | 11.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 360 | `xml_inspect_xmldecl` | 7 | 11.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 361 | `xml_namespaces` | 203 | 12.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 362 | `xml_parent_and_child` | 5 | 12.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 363 | `xml_remove_node` | 22 | 12.4s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 364 | `xml_reparenting` | 14 | 12.4s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 365 | `xml_siblings` | 10 | 12.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 366 | `xml_to_string` | 13 | 12.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 367 | `xml_to_string_comment` | 1 | 12.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 368 | `xml_unescaping` | 23 | 12.3s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 369 | `xmlnode_proto` | 1 | 12.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**34 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `edittext_html_swf7` | 99.9% | 5374 | 5377 | 3 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 2 | `edittext_html_swf8` | 99.9% | 5374 | 5377 | 3 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 3 | `selection` | 99.6% | 452 | 454 | 2 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 4 | `string_coercion` | 99.1% | 116 | 117 | 1 | [36](ruffle-tests/_investigation/complete/string_coercion.md) |
| 5 | `edittext_html_condensewhite_swf7` | 99.0% | 308 | 311 | 3 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 6 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 7 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 8 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 9 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 10 | `on_construct` | 96.0% | 24 | 25 | 1 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 11 | `swf5_no_closure` | 94.7% | 18 | 19 | 1 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 12 | `function_base_clip_readded` | 90.9% | 10 | 11 | 1 |  |
| 13 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 14 | `string_paths_variable_scopes` | 80.0% | 4 | 5 | 1 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 15 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 16 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `edittext_html_swf6` | 72.5% | 3897 | 5377 | 1480 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 19 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 20 | `edittext_stylesheet` | 62.8% | 204 | 325 | 121 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `clone_sprite_edittext_dynamic` | 59.3% | 51 | 86 | 35 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 23 | `register_class` | 57.6% | 38 | 66 | 28 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 24 | `edittext_html_condensewhite_swf8` | 56.9% | 177 | 311 | 134 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 26 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 27 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 28 | `register_class_with_sound` | 54.5% | 6 | 11 | 5 | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 29 | `device_font_spacing` | 50.5% | 46 | 91 | 45 |  |
| 30 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 31 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 32 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 33 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 34 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 12.8s |  |
| 2 | `netstream_play_flv_screen` | 28.2s |  |
| 3 | `string_paths_timer` | 13.7s |  |
| 4 | `timer_run_actions` | 14.3s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 35.8s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 35.1s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 22.0s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**99 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `edittext_html_swf7` | 99.9% | 5374/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 2 | `edittext_html_swf8` | 99.9% | 5374/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 3 | `selection` | 99.6% | 452/454 | 454 | 454 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 4 | `string_coercion` | 99.1% | 116/117 | 117 | 117 | [36](ruffle-tests/_investigation/complete/string_coercion.md) |
| 5 | `edittext_html_condensewhite_swf7` | 99.0% | 308/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 6 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 7 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 8 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 9 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 10 | `on_construct` | 96.0% | 24/25 | 25 | 25 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 11 | `swf5_no_closure` | 94.7% | 18/19 | 19 | 19 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 12 | `function_base_clip_readded` | 90.9% | 10/11 | 11 | 11 |  |
| 13 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 14 | `string_paths_variable_scopes` | 80.0% | 4/5 | 5 | 5 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 15 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 16 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `edittext_html_swf6` | 72.5% | 3897/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 19 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 20 | `edittext_stylesheet` | 62.8% | 204/325 | 325 | 325 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `clone_sprite_edittext_dynamic` | 59.3% | 51/86 | 86 | 86 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 23 | `register_class` | 57.6% | 38/66 | 47 | 66 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 24 | `edittext_html_condensewhite_swf8` | 56.9% | 177/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 26 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 27 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 28 | `register_class_with_sound` | 54.5% | 6/11 | 11 | 11 | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 29 | `device_font_spacing` | 50.5% | 46/91 | 91 | 91 |  |
| 30 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 31 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 32 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 33 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 34 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `removed_target_clip_scope` | 43.2% | 16/37 | 37 | 35 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 36 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 37 | `issue_2870` | 40.0% | 2/5 | 5 | 3 |  |
| 38 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 39 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 40 | `sound` | 37.7% | 237/628 | 628 | 628 |  |
| 41 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 42 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 43 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 44 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 45 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 |  |
| 46 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 47 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 48 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 49 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 50 | `edittext_newline_stripping` | 29.7% | 19/64 | 60 | 64 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 52 | `default_names` | 28.8% | 15/52 | 48 | 52 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 53 | `clone_sprite_edittext` | 26.6% | 25/94 | 94 | 94 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 54 | `call` | 20.6% | 13/63 | 48 | 63 |  |
| 55 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 56 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 57 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 58 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 59 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 60 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 61 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 62 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 63 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 64 | `localconnection` | 12.8% | 74/579 | 261 | 579 |  |
| 65 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 66 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `define_local` | 7.4% | 2/27 | 23 | 27 | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 68 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 69 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 70 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 71 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 72 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 73 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 74 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 75 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 76 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 77 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 78 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 79 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 80 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 81 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 82 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 83 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 84 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 85 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 86 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 87 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 88 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 89 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 90 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 91 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 92 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 93 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 94 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 95 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 96 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 97 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 98 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 99 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 7 | 7 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 3 | 5 |
| 5 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 0 | 4 |
| 6 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 7 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 8 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 0 | 4 |
| 9 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 10 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 1 | 6 |
| 11 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 12 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 13 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 22 | 9 |
| 14 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 15 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 16 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 17 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 2 | 47 |
| 18 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 19 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 0 | 4 |
| 20 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 21 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 22 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 0 | 5 |
| 23 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 29 | 29 |
| 24 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 0 | 16 |
| 25 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) | 17 | 14 | 3 |
| 26 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 27 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 28 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 7 | 1 |
| 29 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 30 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 10 | 2 |
| 31 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 10 | 5 |
| 32 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 0 | 4 |
| 33 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 1 | 3 |
| 34 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 35 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 36 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 0 | 1 |
| 37 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 10 | 3 |
| 38 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 39 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) | 16 | 1 | 15 |
| 40 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 13 | 6 |
| 41 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 42 | 28 |
| 42 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 4 | 1 |
| 43 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 44 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 45 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 46 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 7 | 5 |
| 47 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 48 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 186 | 148 | 38 |
