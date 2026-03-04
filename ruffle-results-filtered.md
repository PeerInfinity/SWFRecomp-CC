# Ruffle Test Results (Filtered)

**Date**: 2026-03-04 01:19 UTC

**Git SHA**: `de6708511a`

**Run Duration**: 128m 42s

**Filtered**: 142 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 477 |
| Passing | **377** (79.0%) |
| Failing | 100 |
| Total expected lines | 71229 |
| Matching lines | 56110 (78.8%) |
| Mismatched lines | 15119 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 92 | 92.0% |
| Segfault | 4 | 4.0% |
| Runtime Error | 2 | 2.0% |
| Compile Fail | 1 | 1.0% |
| Timeout | 1 | 1.0% |

## Passing Tests

**377 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 12.3s |  |
| 2 | `action_to_integer` | 28 | 12.1s |  |
| 3 | `add` | 28 | 12.1s |  |
| 4 | `add2` | 354 | 12.2s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 12.0s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 12.0s |  |
| 7 | `add_swf5` | 28 | 12.0s |  |
| 8 | `arguments` | 127 | 12.0s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 12.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 12.1s |  |
| 11 | `array_constructor` | 30 | 12.0s |  |
| 12 | `array_enumerate` | 4 | 11.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 11.9s |  |
| 14 | `array_properties` | 36 | 11.8s |  |
| 15 | `array_prototyping` | 12 | 11.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 11.8s |  |
| 17 | `array_sort_random` | 443 | 11.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 12.0s |  |
| 19 | `array_trivial` | 209 | 11.9s |  |
| 20 | `as1_constructor_v6` | 35 | 11.8s |  |
| 21 | `as1_constructor_v7` | 35 | 12.2s |  |
| 22 | `as2_oop` | 13 | 12.5s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 12.4s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 12.4s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 12.3s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster_initialize` | 10 | 12.0s |  |
| 27 | `as_set_prop_flags` | 79 | 12.4s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 28 | `as_set_prop_flags_version` | 31 | 12.1s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version_swf5` | 1 | 12.1s |  |
| 30 | `as_set_prop_flags_version_swf6` | 1 | 12.1s |  |
| 31 | `as_set_prop_flags_version_swf7` | 1 | 12.3s |  |
| 32 | `as_set_prop_flags_version_swf8` | 1 | 12.2s |  |
| 33 | `as_set_prop_flags_version_swf9` | 1 | 12.3s |  |
| 34 | `as_transformed_flag` | 20 | 12.2s |  |
| 35 | `attach_movie` | 59 | 12.1s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 36 | `attach_movie_stop` | 3 | 12.0s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 37 | `bad_placeobject_clipaction` | 2 | 15.0s |  |
| 38 | `bad_swf_tag_past_eof` | 0 | 12.2s |  |
| 39 | `bitand` | 1058 | 14.7s |  |
| 40 | `bitmap_data_colortransform` | 0 | 12.5s |  |
| 41 | `bitmap_data_fillrect` | 0 | 12.2s |  |
| 42 | `bitmap_data_max_size_swf10` | 12 | 12.4s |  |
| 43 | `bitmap_data_max_size_swf9` | 10 | 12.2s |  |
| 44 | `bitmap_data_perlinnoise` | 0 | 13.0s |  |
| 45 | `bitmap_data_pixeldissolve_image` | 0 | 13.1s |  |
| 46 | `bitmapdata_applyfilter_colormatrix` | 0 | 12.3s |  |
| 47 | `bitor` | 1058 | 15.3s |  |
| 48 | `biturshift` | 14 | 12.3s |  |
| 49 | `biturshift_swf8` | 14 | 14.3s |  |
| 50 | `bitxor` | 1058 | 14.9s |  |
| 51 | `boxed_primitives` | 24 | 12.4s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 52 | `button_children` | 8 | 12.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 53 | `button_goto` | 4 | 12.4s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_order` | 2 | 12.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_properties_special_cases` | 22 | 12.4s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_v5` | 18 | 12.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_v6` | 18 | 12.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `call_method_empty_name` | 1 | 12.1s |  |
| 59 | `capabilities_resolution` | 8 | 12.2s |  |
| 60 | `catch_references_registers` | 2 | 12.2s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 61 | `clip_constructors` | 8 | 12.3s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 62 | `clip_events` | 19 | 12.4s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 63 | `clone_sprite_types` | 24 | 11.9s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 64 | `closure_scope` | 7 | 12.1s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 65 | `color` | 57 | 12.6s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 66 | `color_transform` | 48 | 12.7s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 67 | `conflicting_instance_names` | 23 | 12.6s |  |
| 68 | `constructor_function` | 2 | 12.1s |  |
| 69 | `context_menu` | 39 | 12.0s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 70 | `context_menu_item` | 41 | 12.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 71 | `create_empty_movie_clip` | 3 | 12.3s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 72 | `define_function2` | 8 | 12.6s |  |
| 73 | `define_function2_preload` | 13 | 12.3s |  |
| 74 | `define_function2_preload_order` | 4 | 13.4s |  |
| 75 | `define_function_case_sensitive` | 2 | 12.4s |  |
| 76 | `delete` | 3 | 12.7s |  |
| 77 | `display_object_properties` | 2 | 12.5s |  |
| 78 | `divide_swf4` | 107 | 12.4s |  |
| 79 | `do_init_action` | 3 | 12.4s |  |
| 80 | `do_init_action_child` | 12 | 12.2s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 81 | `duplicate_movie_clip` | 20 | 12.3s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 82 | `edittext_align` | 60 | 12.3s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 83 | `edittext_align_trailing_spaces_swf7` | 576 | 12.2s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 84 | `edittext_align_trailing_spaces_swf8` | 576 | 12.3s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 85 | `edittext_antialiastype` | 296 | 12.5s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 86 | `edittext_autosize` | 71 | 12.5s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 87 | `edittext_autosize_setter` | 20 | 12.3s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 88 | `edittext_default_format` | 221 | 12.3s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 89 | `edittext_default_format_font_style` | 335 | 12.3s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 90 | `edittext_font_size` | 45 | 12.3s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 91 | `edittext_hscroll` | 27 | 12.3s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 92 | `edittext_html_align_swf7` | 52 | 12.4s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 93 | `edittext_html_align_swf8` | 52 | 12.4s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 94 | `edittext_html_color` | 114 | 12.5s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 95 | `edittext_html_entity` | 4 | 12.6s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 96 | `edittext_html_roundtrip` | 17 | 12.4s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 97 | `edittext_html_swf7` | 5377 | 13.3s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 98 | `edittext_html_swf8` | 5377 | 13.4s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 99 | `edittext_leading` | 9 | 12.2s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_letter_spacing` | 15 | 12.2s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_margins` | 25 | 12.1s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_newline_stripping` | 64 | 16.7s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_programmatic_focus` | 12 | 12.0s | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_tag_indent` | 31 | 12.2s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_text_height_leading` | 20 | 12.2s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_underline` | 40 | 12.2s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_width_height` | 103 | 12.1s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `empty_movieclip_can_attach_movies` | 11 | 13.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 109 | `enumerate` | 64 | 11.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 110 | `equals` | 32 | 11.8s |  |
| 111 | `equals2_swf5` | 926 | 13.4s |  |
| 112 | `equals2_swf6` | 926 | 13.4s |  |
| 113 | `equals2_swf7` | 926 | 13.3s |  |
| 114 | `equals_swf4` | 665 | 12.5s |  |
| 115 | `equals_swf4_alt` | 32 | 11.8s |  |
| 116 | `equals_swf5` | 32 | 11.8s |  |
| 117 | `error` | 58 | 11.8s |  |
| 118 | `escape` | 14 | 11.7s |  |
| 119 | `execution_order1` | 5 | 11.8s |  |
| 120 | `execution_order2` | 7 | 11.8s |  |
| 121 | `execution_order3` | 4 | 11.8s |  |
| 122 | `execution_order4` | 12 | 11.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 123 | `export_assets` | 3 | 11.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 124 | `extends_chain` | 134 | 12.2s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 125 | `extends_native_type` | 11 | 11.8s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 126 | `focusrect_mouse_swf8` | 0 | 11.8s |  |
| 127 | `focusrect_mouse_swf9` | 0 | 12.4s |  |
| 128 | `focusrect_swf5` | 6 | 12.4s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 129 | `frame_size_translated_negative` | 21 | 12.1s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 130 | `frame_size_translated_positive` | 21 | 12.1s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 131 | `function_base_clip` | 8 | 12.2s |  |
| 132 | `function_base_clip_removed` | 25 | 12.2s |  |
| 133 | `function_suppress_and_preload` | 28 | 12.2s |  |
| 134 | `get_variable_in_scope` | 29 | 12.1s |  |
| 135 | `getproperty` | 28 | 12.1s |  |
| 136 | `getproperty_swf4` | 28 | 13.1s |  |
| 137 | `getproperty_swf5` | 28 | 11.9s |  |
| 138 | `global_array` | 3 | 11.8s |  |
| 139 | `global_is_bare` | 7 | 11.8s |  |
| 140 | `global_swf6_7_8` | 15 | 12.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 141 | `globals_swf5` | 304 | 12.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 142 | `globals_swf6` | 304 | 12.5s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 143 | `globals_swf7` | 304 | 12.6s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 144 | `globals_swf8` | 304 | 12.6s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 145 | `goto_advance1` | 6 | 12.4s |  |
| 146 | `goto_advance2` | 2 | 12.3s |  |
| 147 | `goto_both_ways1` | 3 | 12.3s |  |
| 148 | `goto_both_ways2` | 3 | 12.4s |  |
| 149 | `goto_execution_order` | 2 | 12.3s |  |
| 150 | `goto_execution_order2` | 2 | 12.4s |  |
| 151 | `goto_frame` | 12 | 12.7s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 152 | `goto_frame2` | 44 | 13.1s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 153 | `goto_frame_number` | 3 | 12.6s |  |
| 154 | `goto_label` | 17 | 12.7s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 155 | `goto_methods` | 40 | 12.6s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 156 | `goto_rewind1` | 1 | 12.5s |  |
| 157 | `goto_rewind2` | 3 | 12.7s |  |
| 158 | `goto_rewind3` | 2 | 12.1s |  |
| 159 | `greater_swf6` | 1175 | 14.0s |  |
| 160 | `greater_swf7` | 1175 | 14.1s |  |
| 161 | `greaterthan_swf5` | 1 | 11.9s |  |
| 162 | `greaterthan_swf8` | 1 | 11.9s |  |
| 163 | `has_own_property` | 32 | 11.9s |  |
| 164 | `hittest_lockroot` | 15 | 12.1s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 165 | `hittest_morph` | 70 | 12.1s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 166 | `hittest_winding_rule` | 12 | 12.2s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 167 | `infinite_recursion_function` | 4 | 12.0s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 168 | `infinite_recursion_function_in_setter` | 131 | 12.0s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 169 | `infinite_recursion_virtual_property` | 67 | 11.9s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 170 | `init_array_invalid` | 4 | 11.9s |  |
| 171 | `init_object_invalid` | 4 | 12.3s |  |
| 172 | `init_object_order` | 15 | 12.1s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 173 | `is_finite` | 49 | 12.0s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 174 | `is_finite_swf6` | 49 | 11.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 175 | `is_prototype_of` | 89 | 12.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 176 | `issue_1086` | 1 | 11.9s |  |
| 177 | `issue_1671` | 0 | 11.9s |  |
| 178 | `issue_1906` | 4 | 11.9s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 179 | `issue_2166` | 9 | 11.9s |  |
| 180 | `issue_3446` | 1 | 11.9s |  |
| 181 | `issue_3522` | 2 | 11.9s |  |
| 182 | `issue_4377` | 2 | 12.1s |  |
| 183 | `issue_710` | 4 | 12.2s |  |
| 184 | `issue_768` | 3 | 11.9s | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 185 | `issue_9327` | 2 | 11.8s |  |
| 186 | `issue_9885` | 2 | 11.8s |  |
| 187 | `lessthan` | 41 | 11.8s |  |
| 188 | `lessthan2_swf5` | 1226 | 13.9s |  |
| 189 | `lessthan2_swf6` | 1226 | 13.9s |  |
| 190 | `lessthan2_swf7` | 1226 | 13.9s |  |
| 191 | `lessthan_swf4` | 902 | 12.9s |  |
| 192 | `lessthan_swf4_alt` | 41 | 11.8s |  |
| 193 | `lessthan_swf5` | 41 | 11.8s |  |
| 194 | `local_to_global` | 49 | 12.2s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 195 | `localconnection_properties` | 8 | 12.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 196 | `lock_root` | 1 | 12.8s |  |
| 197 | `logical_ops_swf4` | 90 | 12.1s |  |
| 198 | `logical_ops_swf8` | 108 | 12.1s |  |
| 199 | `looping` | 6 | 12.0s |  |
| 200 | `mask_reapply` | 0 | 12.0s |  |
| 201 | `mask_with_drawing` | 0 | 12.0s |  |
| 202 | `math_min_max` | 101 | 12.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 203 | `math_swf6` | 530 | 12.4s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 204 | `math_swf7` | 530 | 13.0s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 205 | `math_swf8` | 530 | 12.9s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 206 | `matrix` | 171 | 12.8s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 207 | `movieclip_begin_gradient_fill` | 0 | 12.9s |  |
| 208 | `movieclip_blend_mode_property` | 35 | 13.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 209 | `movieclip_create_text_field` | 90 | 12.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 210 | `movieclip_default_state` | 69 | 12.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 211 | `movieclip_depth_methods` | 98 | 12.2s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 212 | `movieclip_focusenabled` | 99 | 12.2s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 213 | `movieclip_get_instance_at_depth` | 28 | 12.1s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 214 | `movieclip_hittest` | 92 | 12.2s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 215 | `movieclip_in_removed_button` | 4 | 12.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 216 | `movieclip_init_object` | 5 | 12.1s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 217 | `movieclip_line_gradient_style` | 0 | 12.6s |  |
| 218 | `movieclip_name_from_timeline` | 13 | 11.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 219 | `movieclip_prototype_extension` | 5 | 11.8s |  |
| 220 | `mutable_this` | 18 | 11.7s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 221 | `named_shapes` | 14 | 11.7s |  |
| 222 | `nan_scale` | 9 | 11.8s |  |
| 223 | `native_double_construct` | 12 | 11.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 224 | `native_objects_swf7` | 84 | 12.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 225 | `native_objects_swf8` | 84 | 12.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 226 | `nested_textfields_in_buttons` | 0 | 11.7s |  |
| 227 | `new_method_wrap` | 4 | 11.9s |  |
| 228 | `new_object_enumerate` | 7 | 12.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 229 | `new_object_wrap` | 4 | 11.9s |  |
| 230 | `o` | 3 | 11.9s |  |
| 231 | `object_constructor` | 33 | 12.0s |  |
| 232 | `object_function` | 32 | 12.1s |  |
| 233 | `object_properties` | 31 | 12.2s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 234 | `object_prototypes` | 74 | 12.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 235 | `object_string_coerce_swf5` | 62 | 12.0s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 236 | `object_string_coerce_swf6` | 68 | 12.1s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 237 | `on_construct` | 25 | 12.3s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 238 | `parse_float` | 74 | 12.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 239 | `parse_int` | 64 | 12.4s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 240 | `path_string` | 322 | 12.5s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 241 | `place_and_lookup` | 30 | 12.3s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 242 | `placeobject_occupied_depth` | 6 | 12.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 243 | `point` | 175 | 12.6s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 244 | `primitive_instanceof` | 37 | 12.2s |  |
| 245 | `primitive_type_globals` | 557 | 13.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 246 | `printjob_props_swf5` | 45 | 11.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 247 | `printjob_props_swf6` | 45 | 12.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 248 | `printjob_props_swf7` | 45 | 12.0s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 249 | `property_invalid_base_clip` | 36 | 12.0s |  |
| 250 | `prototype_delete` | 12 | 11.9s |  |
| 251 | `prototype_enumerate` | 5 | 11.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 252 | `prototype_properties` | 17 | 12.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 253 | `rectangle` | 745 | 12.6s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 254 | `recursive_prototypes` | 0 | 11.8s |  |
| 255 | `register_class_return_value` | 16 | 12.1s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 256 | `register_globals_across_frames` | 15 | 11.9s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 257 | `register_underflow` | 26 | 12.2s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 258 | `remove_movie_clip` | 29 | 12.1s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 259 | `rewind_depth` | 30 | 12.2s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 260 | `sandbox_type_local_file` | 1 | 12.0s |  |
| 261 | `sandbox_type_local_network` | 1 | 12.0s |  |
| 262 | `selection` | 454 | 12.2s | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 263 | `set_interval` | 27 | 12.2s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 264 | `set_variable_scope` | 58 | 12.0s |  |
| 265 | `single_frame` | 1 | 11.9s |  |
| 266 | `slash_syntax` | 14 | 12.0s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 267 | `sound_props_swf5` | 68 | 11.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 268 | `sound_props_swf6` | 68 | 12.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 269 | `sound_start_load` | 0 | 12.1s |  |
| 270 | `stage_display_state` | 16 | 11.9s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 271 | `stage_object_children` | 83 | 11.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 272 | `stage_object_enumerate` | 4 | 11.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 273 | `stage_object_properties` | 241 | 12.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 274 | `stage_object_properties_get_var` | 5 | 11.7s |  |
| 275 | `stage_object_properties_swf6` | 231 | 12.7s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 276 | `stage_property_representation` | 586 | 12.4s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 277 | `stage_scale_mode` | 39 | 12.1s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 278 | `strictequals_swf6` | 902 | 14.1s |  |
| 279 | `strictly_equals` | 7 | 12.3s |  |
| 280 | `string_methods` | 285 | 12.4s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 281 | `string_methods_negative_args` | 240 | 12.0s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 282 | `string_methods_swfv5` | 275 | 12.4s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 283 | `string_ops_swf6` | 95 | 11.9s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 284 | `string_paths_basic` | 4 | 11.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 285 | `string_paths_eval2` | 7 | 11.9s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 286 | `string_paths_hidden` | 54 | 12.2s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 287 | `string_paths_other` | 36 | 12.3s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 288 | `string_paths_unload` | 1 | 12.2s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 289 | `string_paths_variable_alias` | 4 | 12.2s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 290 | `string_paths_variable_scopes` | 5 | 12.0s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 291 | `super_edge_cases` | 39 | 12.3s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 292 | `swf4_actions_bool` | 96 | 12.3s |  |
| 293 | `swf4_actions_coercion_order` | 158 | 12.0s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 294 | `swf4_bool` | 4 | 11.8s |  |
| 295 | `swf4_function_calls` | 7 | 12.0s |  |
| 296 | `swf5_encoding` | 3 | 12.0s |  |
| 297 | `swf5_no_closure` | 19 | 12.3s | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 298 | `swf6_case_insensitive` | 42 | 11.8s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 299 | `swf6_string_as_bool` | 15 | 11.8s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 300 | `swf7_case_sensitive` | 44 | 11.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 301 | `tab_ordering_properties_tab_index_edge_case` | 4 | 12.1s |  |
| 302 | `target_clip_swf5` | 2 | 12.0s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 303 | `target_clip_swf6` | 2 | 12.0s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 304 | `target_path` | 14 | 11.9s |  |
| 305 | `tell_target` | 37 | 12.2s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 306 | `tell_target_invalid` | 6 | 12.1s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 307 | `tell_target_invalid_swf6` | 5 | 12.2s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 308 | `text_format` | 1146 | 12.3s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 309 | `text_format_display` | 21 | 12.0s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 310 | `text_format_font_max_length` | 2 | 12.1s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 311 | `text_format_rounding_swf7` | 840 | 12.1s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 312 | `text_format_rounding_swf8` | 840 | 12.2s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 313 | `textfield_background_color` | 11 | 12.0s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 314 | `textfield_border_color` | 11 | 12.1s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 315 | `textfield_cache_as_bitmap` | 1 | 11.9s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 316 | `textfield_maxchars` | 3 | 13.4s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 317 | `textfield_properties` | 44 | 12.9s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 318 | `textfield_props_swf5` | 175 | 13.1s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 319 | `textfield_props_swf6` | 210 | 13.0s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 320 | `textfield_props_swf7` | 210 | 13.1s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 321 | `textfield_props_swf8` | 210 | 12.9s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 322 | `textfield_text` | 7 | 12.7s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 323 | `textfield_variable` | 81 | 13.0s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 324 | `textsnapshot_props_swf5` | 56 | 12.3s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 325 | `textsnapshot_props_swf6` | 56 | 12.4s | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 326 | `this_scoping` | 52 | 12.5s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 327 | `this_swf5` | 41 | 12.6s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 328 | `this_swf6` | 41 | 12.6s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 329 | `this_swf7` | 41 | 12.4s | [43](ruffle-tests/_investigation/complete/this_swf7.md) |
| 330 | `timeline_function_def` | 7 | 12.4s |  |
| 331 | `trace` | 8 | 12.2s |  |
| 332 | `transform` | 70 | 12.2s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 333 | `try_catch_finally` | 118 | 12.2s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 334 | `try_finally_simple` | 16 | 11.9s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 335 | `typeof` | 22 | 11.9s |  |
| 336 | `typeof_globals` | 7 | 11.9s |  |
| 337 | `uncaught_exception` | 1 | 11.9s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 338 | `uncaught_exception_bubbled` | 1 | 11.9s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 339 | `undefined_to_string_swf6` | 4 | 11.9s |  |
| 340 | `unescape` | 43 | 11.9s |  |
| 341 | `unload` | 52 | 12.2s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 342 | `unload_clip_event` | 4 | 12.0s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 343 | `use_hand_cursor` | 8 | 11.8s |  |
| 344 | `variable_args` | 5 | 12.0s |  |
| 345 | `waitforframe` | 7 | 12.0s |  |
| 346 | `waitforframe2` | 16 | 12.3s |  |
| 347 | `watch` | 117 | 12.5s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 348 | `watch_textfield` | 12 | 12.2s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 349 | `watch_virtual_property_proto` | 2 | 12.2s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 350 | `with` | 49 | 12.2s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 351 | `with_return` | 2 | 12.1s |  |
| 352 | `with_variable_scopes` | 43 | 12.2s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 353 | `xml` | 15 | 12.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 354 | `xml_append_child` | 28 | 12.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 355 | `xml_append_child_with_parent` | 20 | 12.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 356 | `xml_cdata` | 11 | 12.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 357 | `xml_child_nodes_edge_cases` | 4 | 12.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 358 | `xml_clone_expandos` | 19 | 12.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 359 | `xml_first_last_child` | 8 | 12.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 360 | `xml_has_child_nodes` | 3 | 12.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 361 | `xml_idmap` | 21 | 12.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 362 | `xml_ignore_comments` | 21 | 12.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 363 | `xml_ignore_white` | 34 | 12.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 364 | `xml_insert_before` | 20 | 12.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 365 | `xml_inspect_createmethods` | 15 | 12.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 366 | `xml_inspect_doctype` | 7 | 11.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 367 | `xml_inspect_parsexml` | 62 | 12.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 368 | `xml_inspect_xmldecl` | 7 | 12.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 369 | `xml_namespaces` | 203 | 12.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 370 | `xml_parent_and_child` | 5 | 12.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 371 | `xml_remove_node` | 22 | 12.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 372 | `xml_reparenting` | 14 | 12.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 373 | `xml_siblings` | 10 | 12.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 374 | `xml_to_string` | 13 | 11.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 375 | `xml_to_string_comment` | 1 | 12.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 376 | `xml_unescaping` | 23 | 12.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 377 | `xmlnode_proto` | 1 | 12.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**29 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `string_coercion` | 99.1% | 116 | 117 | 1 | [36](ruffle-tests/_investigation/complete/string_coercion.md) |
| 2 | `edittext_html_condensewhite_swf7` | 99.0% | 308 | 311 | 3 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 3 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 6 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `edittext_stylesheet` | 91.7% | 298 | 325 | 27 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `function_base_clip_readded` | 90.9% | 10 | 11 | 1 |  |
| 9 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 10 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `edittext_html_condensewhite_swf8` | 80.1% | 249 | 311 | 62 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 12 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 13 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 14 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 15 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 16 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 17 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `clone_sprite_edittext_dynamic` | 59.3% | 51 | 86 | 35 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 19 | `register_class` | 57.6% | 38 | 66 | 28 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 20 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 21 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 22 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 23 | `register_class_with_sound` | 54.5% | 6 | 11 | 5 | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 24 | `device_font_spacing` | 50.5% | 46 | 91 | 45 |  |
| 25 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 26 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 27 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 28 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 29 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 14.2s |  |
| 2 | `netstream_play_flv_screen` | 26.7s |  |
| 3 | `string_paths_timer` | 14.2s |  |
| 4 | `timer_run_actions` | 14.9s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 35.3s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 35.3s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 22.4s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**92 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `string_coercion` | 99.1% | 116/117 | 117 | 117 | [36](ruffle-tests/_investigation/complete/string_coercion.md) |
| 2 | `edittext_html_condensewhite_swf7` | 99.0% | 308/311 | 311 | 311 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 3 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 6 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `edittext_stylesheet` | 91.7% | 298/325 | 325 | 325 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `function_base_clip_readded` | 90.9% | 10/11 | 11 | 11 |  |
| 9 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 10 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `edittext_html_condensewhite_swf8` | 80.1% | 249/311 | 311 | 311 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 12 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 13 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 14 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 15 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 16 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 17 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `clone_sprite_edittext_dynamic` | 59.3% | 51/86 | 86 | 86 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 19 | `register_class` | 57.6% | 38/66 | 47 | 66 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 20 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 21 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 22 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 23 | `register_class_with_sound` | 54.5% | 6/11 | 11 | 11 | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 24 | `device_font_spacing` | 50.5% | 46/91 | 91 | 91 |  |
| 25 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 26 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 27 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 28 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 29 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 30 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `issue_2870` | 40.0% | 2/5 | 5 | 3 |  |
| 32 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 33 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 34 | `sound` | 37.7% | 237/628 | 628 | 628 |  |
| 35 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 36 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 37 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 38 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 39 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 |  |
| 40 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 41 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 42 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 43 | `removed_target_clip_scope` | 32.4% | 12/37 | 37 | 35 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 44 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 45 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 46 | `default_names` | 28.8% | 15/52 | 48 | 52 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 47 | `clone_sprite_edittext` | 26.6% | 25/94 | 94 | 94 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 48 | `call` | 20.6% | 13/63 | 48 | 63 |  |
| 49 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 50 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 51 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 52 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 53 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 54 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 55 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 56 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 57 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 58 | `localconnection` | 12.8% | 74/579 | 261 | 579 |  |
| 59 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 60 | `define_local` | 7.4% | 2/27 | 23 | 27 | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 61 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 62 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 63 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 64 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 65 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 66 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 67 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 68 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 69 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 70 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 71 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 72 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 73 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 74 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 75 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 76 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 77 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 78 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 79 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 80 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 81 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 82 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 83 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 84 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 85 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 86 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 87 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 88 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 89 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 90 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 91 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 92 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 7 | 7 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 4 | 4 |
| 5 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 1 | 3 |
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
| 23 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 30 | 28 |
| 24 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 0 | 16 |
| 25 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) | 17 | 14 | 3 |
| 26 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 27 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 28 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 7 | 1 |
| 29 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 30 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 10 | 2 |
| 31 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 11 | 4 |
| 32 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 0 | 4 |
| 33 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 2 | 2 |
| 34 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 35 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 36 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 0 | 1 |
| 37 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 38 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 39 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) | 16 | 1 | 15 |
| 40 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 14 | 5 |
| 41 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 70 | 45 | 25 |
| 42 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 43 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 44 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 45 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 46 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 7 | 5 |
| 47 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 48 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 186 | 149 | 37 |
