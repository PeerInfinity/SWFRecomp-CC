# Ruffle Test Results (Filtered)

**Date**: 2026-03-04 21:19 UTC

**Git SHA**: `a50d38f8e8`

**Run Duration**: 132m 27s

**Filtered**: 142 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 477 |
| Passing | **379** (79.5%) |
| Failing | 98 |
| Total expected lines | 71229 |
| Matching lines | 57182 (80.3%) |
| Mismatched lines | 14047 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 90 | 91.8% |
| Segfault | 4 | 4.1% |
| Runtime Error | 2 | 2.0% |
| Compile Fail | 1 | 1.0% |
| Timeout | 1 | 1.0% |

## Passing Tests

**379 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 17.3s |  |
| 2 | `action_to_integer` | 28 | 12.4s |  |
| 3 | `add` | 28 | 12.6s |  |
| 4 | `add2` | 354 | 12.8s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 12.5s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 12.4s |  |
| 7 | `add_swf5` | 28 | 12.3s |  |
| 8 | `arguments` | 127 | 12.3s | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [31](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 12.4s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 12.5s |  |
| 11 | `array_constructor` | 30 | 12.5s |  |
| 12 | `array_enumerate` | 4 | 12.4s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 12.5s |  |
| 14 | `array_properties` | 36 | 12.5s |  |
| 15 | `array_prototyping` | 12 | 12.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 12.5s |  |
| 17 | `array_sort_random` | 443 | 12.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 12.7s |  |
| 19 | `array_trivial` | 209 | 12.6s |  |
| 20 | `as1_constructor_v6` | 35 | 12.5s |  |
| 21 | `as1_constructor_v7` | 35 | 14.5s |  |
| 22 | `as2_oop` | 13 | 13.0s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 12.9s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 13.1s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 13.0s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster_initialize` | 10 | 12.9s |  |
| 27 | `as_set_prop_flags` | 79 | 13.2s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 28 | `as_set_prop_flags_version` | 31 | 13.1s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version_swf5` | 1 | 13.0s |  |
| 30 | `as_set_prop_flags_version_swf6` | 1 | 12.9s |  |
| 31 | `as_set_prop_flags_version_swf7` | 1 | 12.8s |  |
| 32 | `as_set_prop_flags_version_swf8` | 1 | 12.9s |  |
| 33 | `as_set_prop_flags_version_swf9` | 1 | 12.6s |  |
| 34 | `as_transformed_flag` | 20 | 12.7s |  |
| 35 | `attach_movie` | 59 | 12.6s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 36 | `attach_movie_stop` | 3 | 12.5s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 37 | `bad_placeobject_clipaction` | 2 | 12.6s |  |
| 38 | `bad_swf_tag_past_eof` | 0 | 12.3s |  |
| 39 | `bitand` | 1058 | 14.9s |  |
| 40 | `bitmap_data_colortransform` | 0 | 12.7s |  |
| 41 | `bitmap_data_fillrect` | 0 | 12.7s |  |
| 42 | `bitmap_data_max_size_swf10` | 12 | 12.3s |  |
| 43 | `bitmap_data_max_size_swf9` | 10 | 12.3s |  |
| 44 | `bitmap_data_perlinnoise` | 0 | 13.1s |  |
| 45 | `bitmap_data_pixeldissolve_image` | 0 | 12.7s |  |
| 46 | `bitmapdata_applyfilter_colormatrix` | 0 | 12.4s |  |
| 47 | `bitor` | 1058 | 14.8s |  |
| 48 | `biturshift` | 14 | 12.3s |  |
| 49 | `biturshift_swf8` | 14 | 14.5s |  |
| 50 | `bitxor` | 1058 | 14.8s |  |
| 51 | `boxed_primitives` | 24 | 12.5s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 52 | `button_children` | 8 | 12.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 53 | `button_goto` | 4 | 12.4s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_order` | 2 | 12.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_properties_special_cases` | 22 | 12.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_v5` | 18 | 12.7s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_v6` | 18 | 12.5s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `call` | 63 | 12.6s | [4](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) |
| 59 | `call_method_empty_name` | 1 | 12.7s |  |
| 60 | `capabilities_resolution` | 8 | 12.8s |  |
| 61 | `catch_references_registers` | 2 | 12.8s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 62 | `clip_constructors` | 8 | 13.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 63 | `clip_events` | 19 | 12.7s | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 64 | `clone_sprite_types` | 24 | 12.4s | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 65 | `closure_scope` | 7 | 12.4s | [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 66 | `color` | 57 | 12.5s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 67 | `color_transform` | 48 | 12.3s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 68 | `conflicting_instance_names` | 23 | 12.3s |  |
| 69 | `constructor_function` | 2 | 12.2s |  |
| 70 | `context_menu` | 39 | 12.3s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 71 | `context_menu_item` | 41 | 12.3s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 72 | `create_empty_movie_clip` | 3 | 12.3s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 73 | `define_function2` | 8 | 12.2s |  |
| 74 | `define_function2_preload` | 13 | 12.2s |  |
| 75 | `define_function2_preload_order` | 4 | 12.3s |  |
| 76 | `define_function_case_sensitive` | 2 | 12.2s |  |
| 77 | `delete` | 3 | 12.2s |  |
| 78 | `display_object_properties` | 2 | 12.0s |  |
| 79 | `divide_swf4` | 107 | 12.2s |  |
| 80 | `do_init_action` | 3 | 12.2s |  |
| 81 | `do_init_action_child` | 12 | 12.2s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 82 | `duplicate_movie_clip` | 20 | 12.2s | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 83 | `edittext_align` | 60 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 84 | `edittext_align_trailing_spaces_swf7` | 576 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 85 | `edittext_align_trailing_spaces_swf8` | 576 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 86 | `edittext_antialiastype` | 296 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 87 | `edittext_autosize` | 71 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 88 | `edittext_autosize_setter` | 20 | 13.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 89 | `edittext_default_format` | 221 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 90 | `edittext_default_format_font_style` | 335 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 91 | `edittext_font_size` | 45 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 92 | `edittext_hscroll` | 27 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 93 | `edittext_html_align_swf7` | 52 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 94 | `edittext_html_align_swf8` | 52 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 95 | `edittext_html_color` | 114 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 96 | `edittext_html_entity` | 4 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 97 | `edittext_html_roundtrip` | 17 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 98 | `edittext_html_swf7` | 5377 | 13.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 99 | `edittext_html_swf8` | 5377 | 13.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_leading` | 9 | 12.6s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_letter_spacing` | 15 | 12.5s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_margins` | 25 | 12.5s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_newline_stripping` | 64 | 16.9s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_programmatic_focus` | 12 | 12.4s | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_tag_indent` | 31 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_text_height_leading` | 20 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_underline` | 40 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_width_height` | 103 | 12.5s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `empty_movieclip_can_attach_movies` | 11 | 13.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 110 | `enumerate` | 64 | 12.5s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 111 | `equals` | 32 | 12.5s |  |
| 112 | `equals2_swf5` | 926 | 14.3s |  |
| 113 | `equals2_swf6` | 926 | 14.3s |  |
| 114 | `equals2_swf7` | 926 | 14.2s |  |
| 115 | `equals_swf4` | 665 | 13.2s |  |
| 116 | `equals_swf4_alt` | 32 | 12.6s |  |
| 117 | `equals_swf5` | 32 | 12.6s |  |
| 118 | `error` | 58 | 12.4s |  |
| 119 | `escape` | 14 | 12.4s |  |
| 120 | `execution_order1` | 5 | 12.4s |  |
| 121 | `execution_order2` | 7 | 12.4s |  |
| 122 | `execution_order3` | 4 | 12.6s |  |
| 123 | `execution_order4` | 12 | 12.7s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 124 | `export_assets` | 3 | 12.4s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 125 | `extends_chain` | 134 | 12.8s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 126 | `extends_native_type` | 11 | 12.5s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 127 | `focusrect_mouse_swf8` | 0 | 12.3s |  |
| 128 | `focusrect_mouse_swf9` | 0 | 13.5s |  |
| 129 | `focusrect_swf5` | 6 | 13.0s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 130 | `frame_size_translated_negative` | 21 | 13.1s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 131 | `frame_size_translated_positive` | 21 | 13.5s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 132 | `function_base_clip` | 8 | 12.8s |  |
| 133 | `function_base_clip_removed` | 25 | 12.8s |  |
| 134 | `function_suppress_and_preload` | 28 | 12.8s |  |
| 135 | `get_variable_in_scope` | 29 | 12.6s |  |
| 136 | `getproperty` | 28 | 12.6s |  |
| 137 | `getproperty_swf4` | 28 | 12.4s |  |
| 138 | `getproperty_swf5` | 28 | 12.2s |  |
| 139 | `global_array` | 3 | 12.2s |  |
| 140 | `global_is_bare` | 7 | 12.2s |  |
| 141 | `global_swf6_7_8` | 15 | 12.5s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 142 | `globals_swf5` | 304 | 12.5s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 143 | `globals_swf6` | 304 | 12.4s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 144 | `globals_swf7` | 304 | 12.4s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 145 | `globals_swf8` | 304 | 12.6s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 146 | `goto_advance1` | 6 | 12.2s |  |
| 147 | `goto_advance2` | 2 | 12.3s |  |
| 148 | `goto_both_ways1` | 3 | 12.3s |  |
| 149 | `goto_both_ways2` | 3 | 12.3s |  |
| 150 | `goto_execution_order` | 2 | 12.2s |  |
| 151 | `goto_execution_order2` | 2 | 12.2s |  |
| 152 | `goto_frame` | 12 | 12.9s | [13](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 153 | `goto_frame2` | 44 | 12.6s | [13](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 154 | `goto_frame_number` | 3 | 12.2s |  |
| 155 | `goto_label` | 17 | 12.3s | [13](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 156 | `goto_methods` | 40 | 12.2s | [13](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 157 | `goto_rewind1` | 1 | 12.1s |  |
| 158 | `goto_rewind2` | 3 | 12.1s |  |
| 159 | `goto_rewind3` | 2 | 12.2s |  |
| 160 | `greater_swf6` | 1175 | 14.1s |  |
| 161 | `greater_swf7` | 1175 | 14.1s |  |
| 162 | `greaterthan_swf5` | 1 | 12.1s |  |
| 163 | `greaterthan_swf8` | 1 | 12.1s |  |
| 164 | `has_own_property` | 32 | 12.1s |  |
| 165 | `hittest_lockroot` | 15 | 12.3s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 166 | `hittest_morph` | 70 | 12.2s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 167 | `hittest_winding_rule` | 12 | 12.2s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 168 | `infinite_recursion_function` | 4 | 12.1s | [17](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 169 | `infinite_recursion_function_in_setter` | 131 | 12.1s | [17](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 170 | `infinite_recursion_virtual_property` | 67 | 12.2s | [17](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 171 | `init_array_invalid` | 4 | 12.2s |  |
| 172 | `init_object_invalid` | 4 | 13.8s |  |
| 173 | `init_object_order` | 15 | 13.3s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 174 | `is_finite` | 49 | 13.2s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 175 | `is_finite_swf6` | 49 | 13.2s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 176 | `is_prototype_of` | 89 | 13.4s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 177 | `issue_1086` | 1 | 13.2s |  |
| 178 | `issue_1104` | 2 | 13.0s | [10](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 179 | `issue_1671` | 0 | 12.9s |  |
| 180 | `issue_1906` | 4 | 12.9s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 181 | `issue_2166` | 9 | 12.8s |  |
| 182 | `issue_3446` | 1 | 12.9s |  |
| 183 | `issue_3522` | 2 | 12.9s |  |
| 184 | `issue_4377` | 2 | 13.1s |  |
| 185 | `issue_710` | 4 | 12.9s |  |
| 186 | `issue_768` | 3 | 12.8s | [18](ruffle-tests/_investigation/complete/issue_768.md) |
| 187 | `issue_9327` | 2 | 12.3s |  |
| 188 | `issue_9885` | 2 | 12.3s |  |
| 189 | `lessthan` | 41 | 12.5s |  |
| 190 | `lessthan2_swf5` | 1226 | 14.5s |  |
| 191 | `lessthan2_swf6` | 1226 | 14.5s |  |
| 192 | `lessthan2_swf7` | 1226 | 14.4s |  |
| 193 | `lessthan_swf4` | 902 | 13.5s |  |
| 194 | `lessthan_swf4_alt` | 41 | 12.4s |  |
| 195 | `lessthan_swf5` | 41 | 12.2s |  |
| 196 | `local_to_global` | 49 | 12.4s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 197 | `localconnection_properties` | 8 | 12.7s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 198 | `lock_root` | 1 | 12.4s |  |
| 199 | `logical_ops_swf4` | 90 | 12.2s |  |
| 200 | `logical_ops_swf8` | 108 | 12.3s |  |
| 201 | `looping` | 6 | 12.5s |  |
| 202 | `mask_reapply` | 0 | 12.6s |  |
| 203 | `mask_with_drawing` | 0 | 13.2s |  |
| 204 | `math_min_max` | 101 | 12.3s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 205 | `math_swf6` | 530 | 12.7s | [22](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 206 | `math_swf7` | 530 | 12.7s | [22](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 207 | `math_swf8` | 530 | 12.6s | [22](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 208 | `matrix` | 171 | 12.5s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 209 | `movieclip_begin_gradient_fill` | 0 | 13.2s |  |
| 210 | `movieclip_blend_mode_property` | 35 | 13.0s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 211 | `movieclip_create_text_field` | 90 | 12.3s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 212 | `movieclip_default_state` | 69 | 12.5s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 213 | `movieclip_depth_methods` | 98 | 12.6s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 214 | `movieclip_focusenabled` | 99 | 12.3s | [12](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 215 | `movieclip_get_instance_at_depth` | 28 | 12.3s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 216 | `movieclip_hittest` | 92 | 12.4s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 217 | `movieclip_in_removed_button` | 4 | 12.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 218 | `movieclip_init_object` | 5 | 12.3s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 219 | `movieclip_line_gradient_style` | 0 | 13.2s |  |
| 220 | `movieclip_name_from_timeline` | 13 | 12.5s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 221 | `movieclip_prototype_extension` | 5 | 12.6s |  |
| 222 | `mutable_this` | 18 | 12.5s | [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 223 | `named_shapes` | 14 | 12.6s |  |
| 224 | `nan_scale` | 9 | 12.7s |  |
| 225 | `native_double_construct` | 12 | 12.7s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 226 | `native_objects_swf7` | 84 | 13.0s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 227 | `native_objects_swf8` | 84 | 13.0s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 228 | `nested_textfields_in_buttons` | 0 | 12.5s |  |
| 229 | `new_method_wrap` | 4 | 12.3s |  |
| 230 | `new_object_enumerate` | 7 | 12.4s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 231 | `new_object_wrap` | 4 | 12.3s |  |
| 232 | `o` | 3 | 12.4s |  |
| 233 | `object_constructor` | 33 | 12.4s |  |
| 234 | `object_function` | 32 | 12.4s |  |
| 235 | `object_properties` | 31 | 12.4s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 236 | `object_prototypes` | 74 | 12.5s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 237 | `object_string_coerce_swf5` | 62 | 12.4s | [28](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 238 | `object_string_coerce_swf6` | 68 | 12.4s | [28](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 239 | `on_construct` | 25 | 12.5s | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 240 | `parse_float` | 74 | 12.4s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 241 | `parse_int` | 64 | 12.6s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 242 | `path_string` | 322 | 12.7s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 243 | `place_and_lookup` | 30 | 12.6s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 244 | `placeobject_occupied_depth` | 6 | 12.7s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 245 | `point` | 175 | 13.0s | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 246 | `primitive_instanceof` | 37 | 12.6s |  |
| 247 | `primitive_type_globals` | 557 | 12.5s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 248 | `property_invalid_base_clip` | 36 | 12.2s |  |
| 249 | `prototype_delete` | 12 | 12.3s |  |
| 250 | `prototype_enumerate` | 5 | 12.5s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 251 | `prototype_properties` | 17 | 12.4s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 252 | `rectangle` | 745 | 13.2s | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 253 | `recursive_prototypes` | 0 | 12.4s |  |
| 254 | `register_class_return_value` | 16 | 12.5s | [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 255 | `register_class_with_sound` | 11 | 12.4s | [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [36](ruffle-tests/_investigation/blocked/SOUND_CLASS_PLAN.md) |
| 256 | `register_globals_across_frames` | 15 | 12.2s | [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 257 | `register_underflow` | 26 | 12.2s | [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 258 | `remove_movie_clip` | 29 | 12.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 259 | `rewind_depth` | 30 | 12.5s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 260 | `sandbox_type_local_file` | 1 | 12.3s |  |
| 261 | `sandbox_type_local_network` | 1 | 12.2s |  |
| 262 | `selection` | 454 | 12.5s | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 263 | `set_interval` | 27 | 12.4s | [49](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 264 | `set_variable_scope` | 58 | 12.4s |  |
| 265 | `single_frame` | 1 | 12.3s |  |
| 266 | `slash_syntax` | 14 | 12.3s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 267 | `sound_props_swf5` | 68 | 12.9s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 268 | `sound_props_swf6` | 68 | 12.6s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 269 | `sound_start_load` | 0 | 12.5s |  |
| 270 | `stage_display_state` | 16 | 12.8s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 271 | `stage_object_children` | 83 | 12.6s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 272 | `stage_object_enumerate` | 4 | 12.4s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 273 | `stage_object_properties` | 241 | 13.1s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 274 | `stage_object_properties_get_var` | 5 | 12.5s |  |
| 275 | `stage_object_properties_swf6` | 231 | 12.9s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 276 | `stage_property_representation` | 586 | 12.7s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 277 | `stage_scale_mode` | 39 | 12.5s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 278 | `strictequals_swf6` | 902 | 14.3s |  |
| 279 | `strictly_equals` | 7 | 12.7s |  |
| 280 | `string_methods` | 285 | 13.4s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 281 | `string_methods_negative_args` | 240 | 12.5s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 282 | `string_methods_swfv5` | 275 | 12.9s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 283 | `string_ops_swf6` | 95 | 12.7s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 284 | `string_paths_basic` | 4 | 12.3s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 285 | `string_paths_eval2` | 7 | 12.5s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 286 | `string_paths_hidden` | 54 | 12.5s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 287 | `string_paths_other` | 36 | 12.7s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 288 | `string_paths_unload` | 1 | 12.8s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 289 | `string_paths_variable_alias` | 4 | 12.8s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 290 | `string_paths_variable_scopes` | 5 | 12.7s | [10](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 291 | `stylesheet` | 283 | 13.3s |  |
| 292 | `stylesheet_transform` | 750 | 13.2s |  |
| 293 | `super_edge_cases` | 39 | 12.8s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 294 | `swf4_actions_bool` | 96 | 12.6s |  |
| 295 | `swf4_actions_coercion_order` | 158 | 12.4s | [42](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 296 | `swf4_bool` | 4 | 12.3s |  |
| 297 | `swf4_function_calls` | 7 | 12.2s |  |
| 298 | `swf5_encoding` | 3 | 12.2s |  |
| 299 | `swf5_no_closure` | 19 | 13.4s | [6](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 300 | `swf6_case_insensitive` | 42 | 12.1s | [42](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 301 | `swf6_string_as_bool` | 15 | 12.1s | [42](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 302 | `swf7_case_sensitive` | 44 | 12.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 303 | `tab_ordering_properties_tab_index_edge_case` | 4 | 12.3s |  |
| 304 | `target_clip_swf5` | 2 | 12.4s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 305 | `target_clip_swf6` | 2 | 12.4s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 306 | `target_path` | 14 | 12.3s |  |
| 307 | `tell_target` | 37 | 12.4s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 308 | `tell_target_invalid` | 6 | 12.4s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 309 | `tell_target_invalid_swf6` | 5 | 12.4s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 310 | `text_format` | 1146 | 12.5s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 311 | `text_format_display` | 21 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 312 | `text_format_font_max_length` | 2 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 313 | `text_format_rounding_swf7` | 840 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 314 | `text_format_rounding_swf8` | 840 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 315 | `textfield_background_color` | 11 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 316 | `textfield_border_color` | 11 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 317 | `textfield_cache_as_bitmap` | 1 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 318 | `textfield_maxchars` | 3 | 12.8s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 319 | `textfield_properties` | 44 | 12.6s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 320 | `textfield_props_swf5` | 175 | 12.9s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 321 | `textfield_props_swf6` | 210 | 13.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 322 | `textfield_props_swf7` | 210 | 13.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 323 | `textfield_props_swf8` | 210 | 13.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 324 | `textfield_text` | 7 | 12.7s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 325 | `textfield_variable` | 81 | 12.9s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 326 | `textsnapshot_props_swf5` | 56 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 327 | `textsnapshot_props_swf6` | 56 | 12.5s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 328 | `this_scoping` | 52 | 12.3s | [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 329 | `this_swf5` | 41 | 12.3s | [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 330 | `this_swf6` | 41 | 12.4s | [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 331 | `this_swf7` | 41 | 12.6s | [48](ruffle-tests/_investigation/complete/this_swf7.md) |
| 332 | `timeline_function_def` | 7 | 12.5s |  |
| 333 | `trace` | 8 | 12.6s |  |
| 334 | `transform` | 70 | 12.7s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 335 | `try_catch_finally` | 118 | 12.6s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 336 | `try_finally_simple` | 16 | 12.6s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 337 | `typeof` | 22 | 12.6s |  |
| 338 | `typeof_globals` | 7 | 12.3s |  |
| 339 | `uncaught_exception` | 1 | 12.5s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 340 | `uncaught_exception_bubbled` | 1 | 12.6s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 341 | `undefined_to_string_swf6` | 4 | 12.6s |  |
| 342 | `unescape` | 43 | 12.7s |  |
| 343 | `unload` | 52 | 13.0s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 344 | `unload_clip_event` | 4 | 12.5s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 345 | `use_hand_cursor` | 8 | 12.5s |  |
| 346 | `variable_args` | 5 | 12.6s |  |
| 347 | `waitforframe` | 7 | 12.6s |  |
| 348 | `waitforframe2` | 16 | 13.1s |  |
| 349 | `watch` | 117 | 12.8s | [29](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 350 | `watch_textfield` | 12 | 12.4s | [29](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 351 | `watch_virtual_property_proto` | 2 | 12.6s | [29](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 352 | `with` | 49 | 12.4s | [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 353 | `with_return` | 2 | 12.4s |  |
| 354 | `with_variable_scopes` | 43 | 12.5s | [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 355 | `xml` | 15 | 12.4s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 356 | `xml_append_child` | 28 | 12.3s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 357 | `xml_append_child_with_parent` | 20 | 12.4s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 358 | `xml_cdata` | 11 | 12.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 359 | `xml_child_nodes_edge_cases` | 4 | 12.6s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 360 | `xml_clone_expandos` | 19 | 12.6s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 361 | `xml_first_last_child` | 8 | 12.6s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 362 | `xml_has_child_nodes` | 3 | 12.5s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 363 | `xml_idmap` | 21 | 12.4s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 364 | `xml_ignore_comments` | 21 | 12.5s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 365 | `xml_ignore_white` | 34 | 14.4s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 366 | `xml_insert_before` | 20 | 12.7s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 367 | `xml_inspect_createmethods` | 15 | 12.7s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 368 | `xml_inspect_doctype` | 7 | 12.4s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 369 | `xml_inspect_parsexml` | 62 | 12.4s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 370 | `xml_inspect_xmldecl` | 7 | 12.3s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 371 | `xml_namespaces` | 203 | 12.4s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 372 | `xml_parent_and_child` | 5 | 12.7s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 373 | `xml_remove_node` | 22 | 12.6s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 374 | `xml_reparenting` | 14 | 12.5s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 375 | `xml_siblings` | 10 | 12.4s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 376 | `xml_to_string` | 13 | 12.4s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 377 | `xml_to_string_comment` | 1 | 12.6s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 378 | `xml_unescaping` | 23 | 12.6s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 379 | `xmlnode_proto` | 1 | 12.7s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |

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
| 8 | `edittext_stylesheet` | 92.6% | 301 | 325 | 24 | [41](ruffle-tests/_investigation/incomplete/STYLESHEET_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `function_base_clip_readded` | 90.9% | 10 | 11 | 1 |  |
| 10 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 11 | `printjob_props_swf5` | 88.9% | 40 | 45 | 5 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 12 | `printjob_props_swf6` | 88.9% | 40 | 45 | 5 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 13 | `printjob_props_swf7` | 88.9% | 40 | 45 | 5 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 14 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 15 | `edittext_html_condensewhite_swf8` | 80.1% | 249 | 311 | 62 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 17 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 19 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 20 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 21 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 22 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 23 | `register_class` | 57.6% | 38 | 66 | 28 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 24 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 25 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 26 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 27 | `device_font_spacing` | 50.5% | 46 | 91 | 45 |  |
| 28 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 29 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 30 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 14.9s |  |
| 2 | `netstream_play_flv_screen` | 28.0s |  |
| 3 | `string_paths_timer` | 14.7s |  |
| 4 | `timer_run_actions` | 15.3s | [49](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 35.0s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 35.1s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 22.4s | [49](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**90 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `string_coercion` | 99.1% | 116/117 | 117 | 117 | [39](ruffle-tests/_investigation/complete/string_coercion.md) |
| 2 | `sound` | 99.0% | 622/628 | 628 | 628 | [36](ruffle-tests/_investigation/blocked/SOUND_CLASS_PLAN.md) |
| 3 | `edittext_html_condensewhite_swf7` | 99.0% | 308/311 | 311 | 311 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `edittext_stylesheet` | 92.6% | 301/325 | 325 | 325 | [41](ruffle-tests/_investigation/incomplete/STYLESHEET_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `function_base_clip_readded` | 90.9% | 10/11 | 11 | 11 |  |
| 10 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 11 | `printjob_props_swf5` | 88.9% | 40/45 | 45 | 45 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 12 | `printjob_props_swf6` | 88.9% | 40/45 | 45 | 45 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 13 | `printjob_props_swf7` | 88.9% | 40/45 | 45 | 45 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 14 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 15 | `edittext_html_condensewhite_swf8` | 80.1% | 249/311 | 311 | 311 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 17 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 19 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 20 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 21 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 22 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 23 | `register_class` | 57.6% | 38/66 | 47 | 66 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 24 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 25 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 26 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 27 | `device_font_spacing` | 50.5% | 46/91 | 91 | 91 |  |
| 28 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 29 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
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
| 43 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 44 | `removed_target_clip_scope` | 29.7% | 11/37 | 37 | 35 | [4](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 45 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 46 | `default_names` | 28.8% | 15/52 | 48 | 52 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 47 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 48 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 49 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 50 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 51 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 52 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 53 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 54 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [29](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 55 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 56 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 57 | `localconnection` | 12.8% | 74/579 | 261 | 579 |  |
| 58 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |
| 59 | `define_local` | 7.4% | 2/27 | 23 | 27 | [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 60 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |
| 61 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 62 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 63 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 64 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 65 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 66 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 67 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [20](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 68 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 69 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 70 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 71 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 72 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 73 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 74 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 75 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 76 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 77 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 78 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 79 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 80 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 81 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 82 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 83 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 84 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 85 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 86 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 87 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 88 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 89 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |
| 90 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 7 | 7 |
| 4 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) | 2 | 1 | 1 |
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
| 15 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 19 | 12 |
| 16 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 17 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 18 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 19 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 2 | 47 |
| 20 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 21 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 0 | 4 |
| 22 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 23 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 24 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 0 | 5 |
| 25 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 30 | 28 |
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
| | *(tests not in any document)* | 183 | 151 | 32 |
