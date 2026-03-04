# Ruffle Test Results (Filtered)

**Date**: 2026-03-04 05:14 UTC

**Git SHA**: `8f807f41b7`

**Run Duration**: 129m 33s

**Filtered**: 142 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 477 |
| Passing | **375** (78.6%) |
| Failing | 102 |
| Total expected lines | 71229 |
| Matching lines | 56493 (79.3%) |
| Mismatched lines | 14736 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 94 | 92.2% |
| Segfault | 4 | 3.9% |
| Runtime Error | 2 | 2.0% |
| Compile Fail | 1 | 1.0% |
| Timeout | 1 | 1.0% |

## Passing Tests

**375 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 15.0s |  |
| 2 | `action_to_integer` | 28 | 11.9s |  |
| 3 | `add` | 28 | 11.9s |  |
| 4 | `add2` | 354 | 12.2s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 12.2s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 12.3s |  |
| 7 | `add_swf5` | 28 | 12.1s |  |
| 8 | `arguments` | 127 | 12.1s | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [31](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 12.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 12.0s |  |
| 11 | `array_constructor` | 30 | 12.1s |  |
| 12 | `array_enumerate` | 4 | 12.1s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 12.1s |  |
| 14 | `array_properties` | 36 | 12.0s |  |
| 15 | `array_prototyping` | 12 | 12.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 11.9s |  |
| 17 | `array_sort_random` | 443 | 11.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 12.1s |  |
| 19 | `array_trivial` | 209 | 12.1s |  |
| 20 | `as1_constructor_v6` | 35 | 11.9s |  |
| 21 | `as1_constructor_v7` | 35 | 13.9s |  |
| 22 | `as2_oop` | 13 | 12.2s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 12.3s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 12.2s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 12.4s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster_initialize` | 10 | 12.1s |  |
| 27 | `as_set_prop_flags` | 79 | 12.2s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 28 | `as_set_prop_flags_version` | 31 | 12.1s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version_swf5` | 1 | 12.1s |  |
| 30 | `as_set_prop_flags_version_swf6` | 1 | 12.1s |  |
| 31 | `as_set_prop_flags_version_swf7` | 1 | 12.1s |  |
| 32 | `as_set_prop_flags_version_swf8` | 1 | 12.0s |  |
| 33 | `as_set_prop_flags_version_swf9` | 1 | 12.0s |  |
| 34 | `as_transformed_flag` | 20 | 12.3s |  |
| 35 | `attach_movie` | 59 | 12.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 36 | `attach_movie_stop` | 3 | 12.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 37 | `bad_swf_tag_past_eof` | 0 | 11.8s |  |
| 38 | `bitand` | 1058 | 14.3s |  |
| 39 | `bitmap_data_colortransform` | 0 | 12.2s |  |
| 40 | `bitmap_data_fillrect` | 0 | 12.0s |  |
| 41 | `bitmap_data_max_size_swf10` | 12 | 11.9s |  |
| 42 | `bitmap_data_max_size_swf9` | 10 | 11.8s |  |
| 43 | `bitmap_data_perlinnoise` | 0 | 12.7s |  |
| 44 | `bitmap_data_pixeldissolve_image` | 0 | 12.3s |  |
| 45 | `bitmapdata_applyfilter_colormatrix` | 0 | 11.9s |  |
| 46 | `bitor` | 1058 | 14.3s |  |
| 47 | `biturshift` | 14 | 11.8s |  |
| 48 | `biturshift_swf8` | 14 | 12.6s |  |
| 49 | `bitxor` | 1058 | 15.0s |  |
| 50 | `boxed_primitives` | 24 | 12.3s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 51 | `button_children` | 8 | 12.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 52 | `button_goto` | 4 | 12.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 53 | `button_properties_special_cases` | 22 | 12.4s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_v5` | 18 | 12.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_v6` | 18 | 12.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `call_method_empty_name` | 1 | 12.1s |  |
| 57 | `capabilities_resolution` | 8 | 12.1s |  |
| 58 | `catch_references_registers` | 2 | 12.0s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 59 | `clip_constructors` | 8 | 12.5s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 60 | `clip_events` | 19 | 12.4s | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 61 | `clone_sprite_types` | 24 | 12.2s | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 62 | `closure_scope` | 7 | 12.2s | [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 63 | `color` | 57 | 12.3s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 64 | `color_transform` | 48 | 12.2s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 65 | `conflicting_instance_names` | 23 | 12.2s |  |
| 66 | `constructor_function` | 2 | 12.1s |  |
| 67 | `context_menu` | 39 | 12.1s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 68 | `context_menu_item` | 41 | 12.1s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 69 | `define_function2` | 8 | 12.0s |  |
| 70 | `define_function2_preload` | 13 | 12.1s |  |
| 71 | `define_function2_preload_order` | 4 | 12.1s |  |
| 72 | `define_function_case_sensitive` | 2 | 12.1s |  |
| 73 | `delete` | 3 | 12.1s |  |
| 74 | `display_object_properties` | 2 | 12.1s |  |
| 75 | `divide_swf4` | 107 | 12.2s |  |
| 76 | `do_init_action` | 3 | 12.3s |  |
| 77 | `do_init_action_child` | 12 | 12.7s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 78 | `duplicate_movie_clip` | 20 | 12.5s | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 79 | `edittext_align` | 60 | 12.6s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 80 | `edittext_align_trailing_spaces_swf7` | 576 | 12.6s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 81 | `edittext_align_trailing_spaces_swf8` | 576 | 12.8s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 82 | `edittext_antialiastype` | 296 | 12.8s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 83 | `edittext_autosize` | 71 | 13.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 84 | `edittext_autosize_setter` | 20 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 85 | `edittext_default_format` | 221 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 86 | `edittext_default_format_font_style` | 335 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 87 | `edittext_font_size` | 45 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 88 | `edittext_hscroll` | 27 | 12.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 89 | `edittext_html_align_swf7` | 52 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 90 | `edittext_html_align_swf8` | 52 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 91 | `edittext_html_color` | 114 | 12.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 92 | `edittext_html_entity` | 4 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 93 | `edittext_html_roundtrip` | 17 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 94 | `edittext_html_swf7` | 5377 | 13.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 95 | `edittext_html_swf8` | 5377 | 13.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 96 | `edittext_leading` | 9 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 97 | `edittext_letter_spacing` | 15 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 98 | `edittext_margins` | 25 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 99 | `edittext_newline_stripping` | 64 | 17.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_programmatic_focus` | 12 | 12.3s | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_tag_indent` | 31 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_text_height_leading` | 20 | 12.5s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_underline` | 40 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_width_height` | 103 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `empty_movieclip_can_attach_movies` | 11 | 13.7s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 106 | `enumerate` | 64 | 12.0s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 107 | `equals` | 32 | 12.1s |  |
| 108 | `equals2_swf5` | 926 | 13.7s |  |
| 109 | `equals2_swf6` | 926 | 13.7s |  |
| 110 | `equals2_swf7` | 926 | 13.9s |  |
| 111 | `equals_swf4` | 665 | 12.9s |  |
| 112 | `equals_swf4_alt` | 32 | 12.1s |  |
| 113 | `equals_swf5` | 32 | 12.2s |  |
| 114 | `error` | 58 | 12.2s |  |
| 115 | `escape` | 14 | 12.1s |  |
| 116 | `execution_order1` | 5 | 12.1s |  |
| 117 | `execution_order2` | 7 | 12.2s |  |
| 118 | `execution_order3` | 4 | 12.2s |  |
| 119 | `execution_order4` | 12 | 12.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 120 | `export_assets` | 3 | 11.9s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 121 | `extends_chain` | 134 | 12.4s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 122 | `extends_native_type` | 11 | 12.1s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 123 | `focusrect_mouse_swf8` | 0 | 11.3s |  |
| 124 | `focusrect_mouse_swf9` | 0 | 13.6s |  |
| 125 | `focusrect_swf5` | 6 | 12.2s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 126 | `frame_size_translated_negative` | 21 | 12.1s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 127 | `frame_size_translated_positive` | 21 | 12.0s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 128 | `function_base_clip` | 8 | 12.0s |  |
| 129 | `function_base_clip_removed` | 25 | 12.1s |  |
| 130 | `function_suppress_and_preload` | 28 | 12.2s |  |
| 131 | `get_variable_in_scope` | 29 | 12.1s |  |
| 132 | `getproperty` | 28 | 12.2s |  |
| 133 | `getproperty_swf4` | 28 | 14.1s |  |
| 134 | `getproperty_swf5` | 28 | 12.0s |  |
| 135 | `global_array` | 3 | 12.2s |  |
| 136 | `global_is_bare` | 7 | 11.9s |  |
| 137 | `global_swf6_7_8` | 15 | 12.6s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 138 | `globals_swf5` | 304 | 12.4s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 139 | `globals_swf6` | 304 | 12.6s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 140 | `globals_swf7` | 304 | 12.5s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 141 | `globals_swf8` | 304 | 12.5s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 142 | `goto_advance1` | 6 | 12.2s |  |
| 143 | `goto_advance2` | 2 | 12.2s |  |
| 144 | `goto_both_ways1` | 3 | 12.2s |  |
| 145 | `goto_both_ways2` | 3 | 12.2s |  |
| 146 | `goto_execution_order` | 2 | 12.0s |  |
| 147 | `goto_execution_order2` | 2 | 12.1s |  |
| 148 | `goto_frame` | 12 | 16.7s | [13](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 149 | `goto_frame2` | 44 | 13.3s | [13](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 150 | `goto_frame_number` | 3 | 12.5s |  |
| 151 | `goto_label` | 17 | 12.5s | [13](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 152 | `goto_methods` | 40 | 12.4s | [13](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 153 | `goto_rewind1` | 1 | 12.3s |  |
| 154 | `goto_rewind2` | 3 | 12.3s |  |
| 155 | `goto_rewind3` | 2 | 12.3s |  |
| 156 | `greater_swf6` | 1175 | 14.3s |  |
| 157 | `greater_swf7` | 1175 | 14.2s |  |
| 158 | `greaterthan_swf5` | 1 | 12.2s |  |
| 159 | `greaterthan_swf8` | 1 | 12.4s |  |
| 160 | `has_own_property` | 32 | 12.3s |  |
| 161 | `hittest_lockroot` | 15 | 12.6s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 162 | `hittest_morph` | 70 | 12.7s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 163 | `hittest_winding_rule` | 12 | 12.6s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 164 | `infinite_recursion_function` | 4 | 12.4s | [17](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 165 | `infinite_recursion_function_in_setter` | 131 | 12.8s | [17](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 166 | `infinite_recursion_virtual_property` | 67 | 12.8s | [17](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 167 | `init_array_invalid` | 4 | 12.7s |  |
| 168 | `init_object_invalid` | 4 | 13.3s |  |
| 169 | `init_object_order` | 15 | 12.2s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 170 | `is_finite` | 49 | 12.2s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 171 | `is_finite_swf6` | 49 | 12.2s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 172 | `is_prototype_of` | 89 | 12.3s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 173 | `issue_1086` | 1 | 12.1s |  |
| 174 | `issue_1104` | 2 | 12.2s | [10](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 175 | `issue_1671` | 0 | 12.2s |  |
| 176 | `issue_1906` | 4 | 11.9s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 177 | `issue_2166` | 9 | 12.0s |  |
| 178 | `issue_3446` | 1 | 12.1s |  |
| 179 | `issue_3522` | 2 | 12.0s |  |
| 180 | `issue_4377` | 2 | 12.1s |  |
| 181 | `issue_710` | 4 | 12.1s |  |
| 182 | `issue_768` | 3 | 13.9s | [18](ruffle-tests/_investigation/complete/issue_768.md) |
| 183 | `issue_9327` | 2 | 12.2s |  |
| 184 | `issue_9885` | 2 | 12.1s |  |
| 185 | `lessthan` | 41 | 12.1s |  |
| 186 | `lessthan2_swf5` | 1226 | 14.4s |  |
| 187 | `lessthan2_swf6` | 1226 | 14.1s |  |
| 188 | `lessthan2_swf7` | 1226 | 14.2s |  |
| 189 | `lessthan_swf4` | 902 | 13.2s |  |
| 190 | `lessthan_swf4_alt` | 41 | 12.0s |  |
| 191 | `lessthan_swf5` | 41 | 12.2s |  |
| 192 | `local_to_global` | 49 | 12.6s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 193 | `localconnection_properties` | 8 | 12.7s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 194 | `lock_root` | 1 | 12.7s |  |
| 195 | `logical_ops_swf4` | 90 | 12.3s |  |
| 196 | `logical_ops_swf8` | 108 | 12.4s |  |
| 197 | `looping` | 6 | 12.4s |  |
| 198 | `mask_reapply` | 0 | 12.5s |  |
| 199 | `mask_with_drawing` | 0 | 12.9s |  |
| 200 | `math_min_max` | 101 | 12.8s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 201 | `math_swf6` | 530 | 13.0s | [22](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 202 | `math_swf7` | 530 | 13.1s | [22](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 203 | `math_swf8` | 530 | 13.0s | [22](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 204 | `matrix` | 171 | 13.1s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 205 | `movieclip_begin_gradient_fill` | 0 | 12.6s |  |
| 206 | `movieclip_blend_mode_property` | 35 | 13.4s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 207 | `movieclip_create_text_field` | 90 | 13.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 208 | `movieclip_default_state` | 69 | 13.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 209 | `movieclip_depth_methods` | 98 | 13.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 210 | `movieclip_focusenabled` | 99 | 12.9s | [12](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 211 | `movieclip_get_instance_at_depth` | 28 | 12.8s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 212 | `movieclip_hittest` | 92 | 12.8s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 213 | `movieclip_init_object` | 5 | 12.7s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 214 | `movieclip_line_gradient_style` | 0 | 12.8s |  |
| 215 | `movieclip_name_from_timeline` | 13 | 12.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 216 | `movieclip_prototype_extension` | 5 | 12.0s |  |
| 217 | `mutable_this` | 18 | 11.9s | [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 218 | `named_shapes` | 14 | 11.9s |  |
| 219 | `nan_scale` | 9 | 12.1s |  |
| 220 | `native_double_construct` | 12 | 12.1s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 221 | `native_objects_swf7` | 84 | 12.4s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 222 | `native_objects_swf8` | 84 | 12.4s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 223 | `nested_textfields_in_buttons` | 0 | 11.9s |  |
| 224 | `new_method_wrap` | 4 | 12.0s |  |
| 225 | `new_object_enumerate` | 7 | 12.0s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 226 | `new_object_wrap` | 4 | 12.0s |  |
| 227 | `o` | 3 | 12.1s |  |
| 228 | `object_constructor` | 33 | 12.3s |  |
| 229 | `object_function` | 32 | 12.3s |  |
| 230 | `object_properties` | 31 | 12.5s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 231 | `object_prototypes` | 74 | 12.3s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 232 | `object_string_coerce_swf5` | 62 | 12.2s | [28](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 233 | `object_string_coerce_swf6` | 68 | 12.2s | [28](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 234 | `on_construct` | 25 | 12.2s | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 235 | `parse_float` | 74 | 12.1s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 236 | `parse_int` | 64 | 12.2s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 237 | `path_string` | 322 | 12.4s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 238 | `place_and_lookup` | 30 | 12.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 239 | `placeobject_occupied_depth` | 6 | 12.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 240 | `point` | 175 | 12.4s | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 241 | `primitive_instanceof` | 37 | 11.9s |  |
| 242 | `primitive_type_globals` | 557 | 12.6s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 243 | `printjob_props_swf5` | 45 | 12.1s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 244 | `printjob_props_swf6` | 45 | 12.4s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 245 | `printjob_props_swf7` | 45 | 12.2s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 246 | `property_invalid_base_clip` | 36 | 12.2s |  |
| 247 | `prototype_delete` | 12 | 12.3s |  |
| 248 | `prototype_enumerate` | 5 | 12.5s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 249 | `prototype_properties` | 17 | 12.4s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 250 | `rectangle` | 745 | 13.2s | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 251 | `recursive_prototypes` | 0 | 12.3s |  |
| 252 | `register_class_return_value` | 16 | 12.1s | [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 253 | `register_class_with_sound` | 11 | 12.2s | [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [36](ruffle-tests/_investigation/blocked/SOUND_CLASS_PLAN.md) |
| 254 | `register_globals_across_frames` | 15 | 12.2s | [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 255 | `register_underflow` | 26 | 12.2s | [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 256 | `remove_movie_clip` | 29 | 12.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 257 | `rewind_depth` | 30 | 12.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 258 | `sandbox_type_local_file` | 1 | 11.9s |  |
| 259 | `sandbox_type_local_network` | 1 | 11.9s |  |
| 260 | `selection` | 454 | 12.1s | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 261 | `set_interval` | 27 | 12.1s | [49](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 262 | `set_variable_scope` | 58 | 12.0s |  |
| 263 | `single_frame` | 1 | 11.9s |  |
| 264 | `slash_syntax` | 14 | 11.9s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 265 | `sound_props_swf5` | 68 | 12.3s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 266 | `sound_props_swf6` | 68 | 12.2s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 267 | `sound_start_load` | 0 | 12.1s |  |
| 268 | `stage_display_state` | 16 | 12.0s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 269 | `stage_object_children` | 83 | 12.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 270 | `stage_object_enumerate` | 4 | 12.1s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 271 | `stage_object_properties` | 241 | 12.5s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 272 | `stage_object_properties_get_var` | 5 | 12.1s |  |
| 273 | `stage_object_properties_swf6` | 231 | 12.3s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 274 | `stage_property_representation` | 586 | 12.0s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 275 | `stage_scale_mode` | 39 | 12.0s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 276 | `strictequals_swf6` | 902 | 13.4s |  |
| 277 | `strictly_equals` | 7 | 12.0s |  |
| 278 | `string_methods` | 285 | 12.5s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 279 | `string_methods_negative_args` | 240 | 12.2s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 280 | `string_methods_swfv5` | 275 | 12.5s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 281 | `string_ops_swf6` | 95 | 12.1s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 282 | `string_paths_basic` | 4 | 11.9s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 283 | `string_paths_eval2` | 7 | 12.2s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 284 | `string_paths_hidden` | 54 | 12.0s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 285 | `string_paths_other` | 36 | 12.1s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 286 | `string_paths_unload` | 1 | 12.2s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 287 | `string_paths_variable_alias` | 4 | 12.0s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 288 | `string_paths_variable_scopes` | 5 | 11.9s | [10](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 289 | `super_edge_cases` | 39 | 12.4s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 290 | `swf4_actions_bool` | 96 | 12.3s |  |
| 291 | `swf4_actions_coercion_order` | 158 | 12.3s | [42](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 292 | `swf4_bool` | 4 | 12.2s |  |
| 293 | `swf4_function_calls` | 7 | 12.1s |  |
| 294 | `swf5_encoding` | 3 | 12.3s |  |
| 295 | `swf5_no_closure` | 19 | 12.4s | [6](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 296 | `swf6_case_insensitive` | 42 | 12.6s | [42](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 297 | `swf6_string_as_bool` | 15 | 12.1s | [42](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 298 | `swf7_case_sensitive` | 44 | 11.9s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 299 | `tab_ordering_properties_tab_index_edge_case` | 4 | 12.0s |  |
| 300 | `target_clip_swf5` | 2 | 11.8s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 301 | `target_clip_swf6` | 2 | 12.1s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 302 | `target_path` | 14 | 12.1s |  |
| 303 | `tell_target` | 37 | 12.2s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 304 | `tell_target_invalid` | 6 | 12.2s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 305 | `tell_target_invalid_swf6` | 5 | 12.1s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 306 | `text_format` | 1146 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 307 | `text_format_display` | 21 | 12.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 308 | `text_format_font_max_length` | 2 | 12.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 309 | `text_format_rounding_swf7` | 840 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 310 | `text_format_rounding_swf8` | 840 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 311 | `textfield_background_color` | 11 | 12.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 312 | `textfield_border_color` | 11 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 313 | `textfield_cache_as_bitmap` | 1 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 314 | `textfield_maxchars` | 3 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 315 | `textfield_properties` | 44 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 316 | `textfield_props_swf5` | 175 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 317 | `textfield_props_swf6` | 210 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 318 | `textfield_props_swf7` | 210 | 12.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 319 | `textfield_props_swf8` | 210 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 320 | `textfield_text` | 7 | 11.8s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 321 | `textfield_variable` | 81 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 322 | `textsnapshot_props_swf5` | 56 | 11.8s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 323 | `textsnapshot_props_swf6` | 56 | 11.8s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 324 | `this_scoping` | 52 | 11.9s | [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 325 | `this_swf5` | 41 | 11.8s | [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 326 | `this_swf6` | 41 | 11.8s | [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 327 | `this_swf7` | 41 | 11.8s | [48](ruffle-tests/_investigation/complete/this_swf7.md) |
| 328 | `timeline_function_def` | 7 | 11.9s |  |
| 329 | `trace` | 8 | 12.5s |  |
| 330 | `transform` | 70 | 12.5s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 331 | `try_catch_finally` | 118 | 12.3s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 332 | `try_finally_simple` | 16 | 12.2s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 333 | `typeof` | 22 | 12.2s |  |
| 334 | `typeof_globals` | 7 | 12.2s |  |
| 335 | `uncaught_exception` | 1 | 12.0s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 336 | `uncaught_exception_bubbled` | 1 | 12.1s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 337 | `undefined_to_string_swf6` | 4 | 12.1s |  |
| 338 | `unescape` | 43 | 12.1s |  |
| 339 | `unload` | 52 | 12.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 340 | `unload_clip_event` | 4 | 12.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 341 | `use_hand_cursor` | 8 | 12.4s |  |
| 342 | `variable_args` | 5 | 12.8s |  |
| 343 | `waitforframe` | 7 | 12.6s |  |
| 344 | `waitforframe2` | 16 | 16.0s |  |
| 345 | `watch` | 117 | 13.4s | [29](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 346 | `watch_textfield` | 12 | 13.2s | [29](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 347 | `watch_virtual_property_proto` | 2 | 13.4s | [29](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 348 | `with` | 49 | 12.8s | [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 349 | `with_return` | 2 | 13.0s |  |
| 350 | `with_variable_scopes` | 43 | 13.1s | [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 351 | `xml` | 15 | 12.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 352 | `xml_append_child` | 28 | 12.7s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 353 | `xml_append_child_with_parent` | 20 | 12.4s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 354 | `xml_cdata` | 11 | 12.2s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 355 | `xml_child_nodes_edge_cases` | 4 | 12.5s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 356 | `xml_clone_expandos` | 19 | 12.5s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 357 | `xml_first_last_child` | 8 | 12.3s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 358 | `xml_has_child_nodes` | 3 | 12.7s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 359 | `xml_idmap` | 21 | 12.5s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 360 | `xml_ignore_comments` | 21 | 12.6s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 361 | `xml_ignore_white` | 34 | 12.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 362 | `xml_insert_before` | 20 | 11.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 363 | `xml_inspect_createmethods` | 15 | 11.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 364 | `xml_inspect_doctype` | 7 | 11.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 365 | `xml_inspect_parsexml` | 62 | 11.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 366 | `xml_inspect_xmldecl` | 7 | 11.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 367 | `xml_namespaces` | 203 | 11.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 368 | `xml_parent_and_child` | 5 | 11.7s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 369 | `xml_remove_node` | 22 | 11.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 370 | `xml_reparenting` | 14 | 11.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 371 | `xml_siblings` | 10 | 11.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 372 | `xml_to_string` | 13 | 12.0s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 373 | `xml_to_string_comment` | 1 | 11.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 374 | `xml_unescaping` | 23 | 12.1s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 375 | `xmlnode_proto` | 1 | 12.0s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**30 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `string_coercion` | 99.1% | 116 | 117 | 1 | [39](ruffle-tests/_investigation/complete/string_coercion.md) |
| 2 | `sound` | 99.0% | 622 | 628 | 6 | [36](ruffle-tests/_investigation/blocked/SOUND_CLASS_PLAN.md) |
| 3 | `edittext_html_condensewhite_swf7` | 99.0% | 308 | 311 | 3 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `edittext_stylesheet` | 91.7% | 298 | 325 | 27 | [41](ruffle-tests/_investigation/incomplete/STYLESHEET_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `function_base_clip_readded` | 90.9% | 10 | 11 | 1 |  |
| 10 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 11 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 12 | `edittext_html_condensewhite_swf8` | 80.1% | 249 | 311 | 62 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 13 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 14 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 15 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 17 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 18 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 19 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 20 | `clone_sprite_edittext_dynamic` | 59.3% | 51 | 86 | 35 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 21 | `register_class` | 57.6% | 38 | 66 | 28 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 22 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 23 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 24 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 25 | `device_font_spacing` | 50.5% | 46 | 91 | 45 |  |
| 26 | `bad_placeobject_clipaction` | 50.0% | 1 | 2 | 1 |  |
| 27 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 28 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 29 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 30 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 14.1s |  |
| 2 | `netstream_play_flv_screen` | 27.1s |  |
| 3 | `string_paths_timer` | 14.2s |  |
| 4 | `timer_run_actions` | 21.0s | [49](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 36.1s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 35.9s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 21.7s | [49](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**94 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `string_coercion` | 99.1% | 116/117 | 117 | 117 | [39](ruffle-tests/_investigation/complete/string_coercion.md) |
| 2 | `sound` | 99.0% | 622/628 | 628 | 628 | [36](ruffle-tests/_investigation/blocked/SOUND_CLASS_PLAN.md) |
| 3 | `edittext_html_condensewhite_swf7` | 99.0% | 308/311 | 311 | 311 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `edittext_stylesheet` | 91.7% | 298/325 | 325 | 325 | [41](ruffle-tests/_investigation/incomplete/STYLESHEET_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `function_base_clip_readded` | 90.9% | 10/11 | 11 | 11 |  |
| 10 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 11 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 12 | `edittext_html_condensewhite_swf8` | 80.1% | 249/311 | 311 | 311 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 13 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 14 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 15 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 17 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 18 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 19 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 20 | `clone_sprite_edittext_dynamic` | 59.3% | 51/86 | 86 | 86 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 21 | `register_class` | 57.6% | 38/66 | 47 | 66 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 22 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 23 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 24 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 25 | `device_font_spacing` | 50.5% | 46/91 | 91 | 91 |  |
| 26 | `bad_placeobject_clipaction` | 50.0% | 1/2 | 1 | 2 |  |
| 27 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 28 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 29 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 30 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |
| 31 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 33 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 34 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 35 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 36 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 37 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 38 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 39 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 |  |
| 40 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 41 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 42 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 43 | `removed_target_clip_scope` | 32.4% | 12/37 | 37 | 35 | [4](ruffle-tests/_investigation/incomplete/CALL_SEMANTICS_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 44 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 45 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 46 | `default_names` | 28.8% | 15/52 | 48 | 52 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 47 | `clone_sprite_edittext` | 26.6% | 25/94 | 94 | 94 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 48 | `movieclip_in_removed_button` | 25.0% | 1/4 | 3 | 4 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 49 | `call` | 20.6% | 13/63 | 48 | 63 | [4](ruffle-tests/_investigation/incomplete/CALL_SEMANTICS_PLAN.md) |
| 50 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 51 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 52 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 53 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 54 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 55 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 56 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [29](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 57 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 58 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 59 | `localconnection` | 12.8% | 74/579 | 261 | 579 |  |
| 60 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |
| 61 | `define_local` | 7.4% | 2/27 | 23 | 27 | [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 62 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |
| 63 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 64 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 65 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 66 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 67 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 68 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 69 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 70 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [20](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 71 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 72 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 73 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 74 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 75 | `button_order` | 0.0% | 0/2 | 0 | 2 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 76 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 77 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 78 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 79 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 80 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 81 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 82 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 83 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 84 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 85 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 86 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 87 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 88 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 89 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 90 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 91 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 92 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 93 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |
| 94 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 5 | 9 |
| 4 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/incomplete/CALL_SEMANTICS_PLAN.md) | 2 | 0 | 2 |
| 5 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 4 | 4 |
| 6 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 1 | 3 |
| 7 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 8 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 9 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 0 | 4 |
| 10 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 11 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 12 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 1 | 6 |
| 13 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 14 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 15 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 22 | 9 |
| 16 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 17 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 18 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 19 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 2 | 47 |
| 20 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 21 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 0 | 4 |
| 22 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 23 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 24 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 0 | 5 |
| 25 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 29 | 29 |
| 26 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 0 | 16 |
| 27 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) | 17 | 14 | 3 |
| 28 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 29 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 30 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 7 | 1 |
| 31 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 32 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 10 | 2 |
| 33 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 12 | 3 |
| 34 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 0 | 4 |
| 35 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 2 | 2 |
| 36 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/blocked/SOUND_CLASS_PLAN.md) | 2 | 1 | 1 |
| 37 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 38 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 39 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 0 | 1 |
| 40 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 41 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/incomplete/STYLESHEET_PLAN.md) | 1 | 0 | 1 |
| 42 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 43 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) | 16 | 1 | 15 |
| 44 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 14 | 5 |
| 45 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 70 | 45 | 25 |
| 46 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) | 4 | 0 | 4 |
| 47 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 48 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 49 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 50 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 51 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 7 | 5 |
| 52 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 53 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 183 | 148 | 35 |
