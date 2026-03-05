# Ruffle Test Results (Filtered)

**Date**: 2026-03-05 05:08 UTC

**Git SHA**: `168c0745d9`

**Run Duration**: 135m 51s

**Filtered**: 142 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 477 |
| Passing | **394** (82.6%) |
| Failing | 83 |
| Total expected lines | 71229 |
| Matching lines | 57550 (80.8%) |
| Mismatched lines | 13679 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 76 | 91.6% |
| Segfault | 3 | 3.6% |
| Runtime Error | 2 | 2.4% |
| Compile Fail | 1 | 1.2% |
| Timeout | 1 | 1.2% |

## Passing Tests

**394 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 14.7s |  |
| 2 | `action_to_integer` | 28 | 12.7s |  |
| 3 | `add` | 28 | 12.8s |  |
| 4 | `add2` | 354 | 13.0s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 12.7s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 12.7s |  |
| 7 | `add_swf5` | 28 | 12.7s |  |
| 8 | `arguments` | 127 | 12.8s | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [34](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 12.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 12.8s |  |
| 11 | `array_constructor` | 30 | 12.7s |  |
| 12 | `array_enumerate` | 4 | 12.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 12.8s |  |
| 14 | `array_properties` | 36 | 12.7s |  |
| 15 | `array_prototyping` | 12 | 12.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 12.8s |  |
| 17 | `array_sort_random` | 443 | 12.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 12.9s |  |
| 19 | `array_trivial` | 209 | 12.9s |  |
| 20 | `as1_constructor_v6` | 35 | 12.8s |  |
| 21 | `as1_constructor_v7` | 35 | 13.2s |  |
| 22 | `as2_oop` | 13 | 13.4s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 13.1s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 13.4s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 13.2s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster` | 41 | 13.2s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 13.0s |  |
| 28 | `as_broadcaster_undef` | 89 | 13.1s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 29 | `as_set_prop_flags` | 79 | 13.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version` | 31 | 13.1s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version_swf5` | 1 | 13.1s |  |
| 32 | `as_set_prop_flags_version_swf6` | 1 | 13.1s |  |
| 33 | `as_set_prop_flags_version_swf7` | 1 | 13.3s |  |
| 34 | `as_set_prop_flags_version_swf8` | 1 | 13.2s |  |
| 35 | `as_set_prop_flags_version_swf9` | 1 | 13.4s |  |
| 36 | `as_transformed_flag` | 20 | 13.2s |  |
| 37 | `asnative` | 34 | 13.1s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 38 | `asnew` | 34 | 13.2s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `attach_movie` | 59 | 13.2s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 40 | `attach_movie_stop` | 3 | 13.1s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 41 | `bad_placeobject_clipaction` | 2 | 13.1s |  |
| 42 | `bad_swf_tag_past_eof` | 0 | 13.2s |  |
| 43 | `bitand` | 1058 | 16.2s |  |
| 44 | `bitmap_data_colortransform` | 0 | 13.8s |  |
| 45 | `bitmap_data_fillrect` | 0 | 12.8s |  |
| 46 | `bitmap_data_max_size_swf10` | 12 | 12.6s |  |
| 47 | `bitmap_data_max_size_swf9` | 10 | 12.6s |  |
| 48 | `bitmap_data_perlinnoise` | 0 | 13.4s |  |
| 49 | `bitmap_data_pixeldissolve_image` | 0 | 13.0s |  |
| 50 | `bitmapdata_applyfilter_colormatrix` | 0 | 12.8s |  |
| 51 | `bitor` | 1058 | 15.2s |  |
| 52 | `biturshift` | 14 | 12.6s |  |
| 53 | `biturshift_swf8` | 14 | 13.3s |  |
| 54 | `bitxor` | 1058 | 15.5s |  |
| 55 | `boxed_primitives` | 24 | 12.9s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 56 | `button_children` | 8 | 12.8s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_goto` | 4 | 12.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_order` | 2 | 12.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_properties_special_cases` | 22 | 12.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_v5` | 18 | 12.6s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_v6` | 18 | 12.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `call` | 63 | 12.7s | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) |
| 63 | `call_method_empty_name` | 1 | 12.5s |  |
| 64 | `capabilities_resolution` | 8 | 12.5s |  |
| 65 | `catch_references_registers` | 2 | 12.5s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 66 | `clip_constructors` | 8 | 12.6s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 67 | `clip_events` | 19 | 13.0s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 68 | `clone_sprite_types` | 24 | 12.6s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 69 | `closure_scope` | 7 | 12.9s | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 70 | `color` | 57 | 12.9s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 71 | `color_transform` | 48 | 12.8s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 72 | `conflicting_instance_names` | 23 | 12.8s |  |
| 73 | `constructor_function` | 2 | 12.7s |  |
| 74 | `context_menu` | 39 | 12.7s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 75 | `context_menu_item` | 41 | 12.8s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 76 | `create_empty_movie_clip` | 3 | 12.7s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 77 | `define_function2` | 8 | 12.7s |  |
| 78 | `define_function2_preload` | 13 | 12.7s |  |
| 79 | `define_function2_preload_order` | 4 | 13.5s |  |
| 80 | `define_function_case_sensitive` | 2 | 13.0s |  |
| 81 | `delete` | 3 | 13.5s |  |
| 82 | `display_object_properties` | 2 | 12.8s |  |
| 83 | `divide_swf4` | 107 | 13.0s |  |
| 84 | `do_init_action` | 3 | 12.9s |  |
| 85 | `do_init_action_child` | 12 | 13.2s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 86 | `duplicate_movie_clip` | 20 | 12.9s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 87 | `edittext_align` | 60 | 13.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 88 | `edittext_align_trailing_spaces_swf7` | 576 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 89 | `edittext_align_trailing_spaces_swf8` | 576 | 12.9s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 90 | `edittext_antialiastype` | 296 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 91 | `edittext_autosize` | 71 | 13.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 92 | `edittext_autosize_setter` | 20 | 14.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 93 | `edittext_default_format` | 221 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 94 | `edittext_default_format_font_style` | 335 | 13.3s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 95 | `edittext_font_size` | 45 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 96 | `edittext_hscroll` | 27 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 97 | `edittext_html_align_swf7` | 52 | 13.3s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 98 | `edittext_html_align_swf8` | 52 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 99 | `edittext_html_color` | 114 | 13.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_html_entity` | 4 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_html_roundtrip` | 17 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_html_swf7` | 5377 | 14.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_html_swf8` | 5377 | 14.3s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_leading` | 9 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_letter_spacing` | 15 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_margins` | 25 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_newline_stripping` | 64 | 17.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_programmatic_focus` | 12 | 12.7s | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_stylesheet` | 325 | 13.2s | [44](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_tag_indent` | 31 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_text_height_leading` | 20 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_underline` | 40 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_width_height` | 103 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `empty_movieclip_can_attach_movies` | 11 | 14.4s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 115 | `enumerate` | 64 | 13.1s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 116 | `equals` | 32 | 13.1s |  |
| 117 | `equals2_swf5` | 926 | 14.8s |  |
| 118 | `equals2_swf6` | 926 | 14.8s |  |
| 119 | `equals2_swf7` | 926 | 14.8s |  |
| 120 | `equals_swf4` | 665 | 13.8s |  |
| 121 | `equals_swf4_alt` | 32 | 13.0s |  |
| 122 | `equals_swf5` | 32 | 13.0s |  |
| 123 | `error` | 58 | 13.1s |  |
| 124 | `escape` | 14 | 13.0s |  |
| 125 | `execution_order1` | 5 | 13.1s |  |
| 126 | `execution_order2` | 7 | 13.1s |  |
| 127 | `execution_order3` | 4 | 13.0s |  |
| 128 | `execution_order4` | 12 | 13.3s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 129 | `export_assets` | 3 | 13.0s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 130 | `extends_chain` | 134 | 13.6s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 131 | `extends_native_type` | 11 | 13.2s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 132 | `focusrect_mouse_swf8` | 0 | 12.6s |  |
| 133 | `focusrect_mouse_swf9` | 0 | 12.9s |  |
| 134 | `focusrect_swf5` | 6 | 12.7s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 135 | `frame_size_translated_negative` | 21 | 12.6s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 136 | `frame_size_translated_positive` | 21 | 12.6s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 137 | `function_as_function` | 35 | 12.6s | [16](ruffle-tests/_investigation/incomplete/FUNCTION_EDGE_CASES_PLAN.md) |
| 138 | `function_base_clip` | 8 | 12.6s |  |
| 139 | `function_base_clip_removed` | 25 | 12.6s |  |
| 140 | `function_suppress_and_preload` | 28 | 12.6s |  |
| 141 | `get_variable_in_scope` | 29 | 12.5s |  |
| 142 | `getproperty` | 28 | 12.5s |  |
| 143 | `getproperty_swf4` | 28 | 14.2s |  |
| 144 | `getproperty_swf5` | 28 | 12.6s |  |
| 145 | `global_array` | 3 | 12.7s |  |
| 146 | `global_is_bare` | 7 | 13.4s |  |
| 147 | `global_swf6_7_8` | 15 | 14.3s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 148 | `globals_swf5` | 304 | 13.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 149 | `globals_swf6` | 304 | 14.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 150 | `globals_swf7` | 304 | 14.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 151 | `globals_swf8` | 304 | 13.5s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 152 | `goto_advance1` | 6 | 13.6s |  |
| 153 | `goto_advance2` | 2 | 13.2s |  |
| 154 | `goto_both_ways1` | 3 | 13.2s |  |
| 155 | `goto_both_ways2` | 3 | 13.7s |  |
| 156 | `goto_execution_order` | 2 | 14.1s |  |
| 157 | `goto_execution_order2` | 2 | 13.6s |  |
| 158 | `goto_frame` | 12 | 13.1s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 159 | `goto_frame2` | 44 | 13.2s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 160 | `goto_frame_number` | 3 | 12.8s |  |
| 161 | `goto_label` | 17 | 12.9s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 162 | `goto_methods` | 40 | 12.7s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 163 | `goto_rewind1` | 1 | 12.7s |  |
| 164 | `goto_rewind2` | 3 | 12.7s |  |
| 165 | `goto_rewind3` | 2 | 12.7s |  |
| 166 | `greater_swf6` | 1175 | 14.6s |  |
| 167 | `greater_swf7` | 1175 | 14.7s |  |
| 168 | `greaterthan_swf5` | 1 | 12.6s |  |
| 169 | `greaterthan_swf8` | 1 | 12.7s |  |
| 170 | `has_own_property` | 32 | 12.7s |  |
| 171 | `hittest_lockroot` | 15 | 12.8s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 172 | `hittest_morph` | 70 | 12.7s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 173 | `hittest_winding_rule` | 12 | 12.8s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 174 | `infinite_recursion_function` | 4 | 12.6s | [20](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 175 | `infinite_recursion_function_in_setter` | 131 | 12.6s | [20](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 176 | `infinite_recursion_virtual_property` | 67 | 12.6s | [20](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 177 | `init_array_invalid` | 4 | 12.6s |  |
| 178 | `init_object_invalid` | 4 | 12.7s |  |
| 179 | `init_object_order` | 15 | 12.6s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 180 | `is_finite` | 49 | 12.5s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 181 | `is_finite_swf6` | 49 | 12.5s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 182 | `is_prototype_of` | 89 | 12.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 183 | `issue_1086` | 1 | 12.3s |  |
| 184 | `issue_1104` | 2 | 12.4s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 185 | `issue_1671` | 0 | 12.4s |  |
| 186 | `issue_1906` | 4 | 12.4s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 187 | `issue_2166` | 9 | 12.4s |  |
| 188 | `issue_3169` | 2 | 12.5s | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 189 | `issue_3446` | 1 | 12.4s |  |
| 190 | `issue_3522` | 2 | 12.4s |  |
| 191 | `issue_4377` | 2 | 12.4s |  |
| 192 | `issue_710` | 4 | 12.4s |  |
| 193 | `issue_768` | 3 | 14.5s | [21](ruffle-tests/_investigation/complete/issue_768.md) |
| 194 | `issue_9327` | 2 | 12.7s |  |
| 195 | `issue_9885` | 2 | 12.8s |  |
| 196 | `lessthan` | 41 | 12.7s |  |
| 197 | `lessthan2_swf5` | 1226 | 14.7s |  |
| 198 | `lessthan2_swf6` | 1226 | 14.8s |  |
| 199 | `lessthan2_swf7` | 1226 | 14.9s |  |
| 200 | `lessthan_swf4` | 902 | 14.1s |  |
| 201 | `lessthan_swf4_alt` | 41 | 12.7s |  |
| 202 | `lessthan_swf5` | 41 | 12.8s |  |
| 203 | `local_to_global` | 49 | 12.8s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 204 | `localconnection_properties` | 8 | 12.9s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 205 | `lock_root` | 1 | 13.0s |  |
| 206 | `logical_ops_swf4` | 90 | 13.4s |  |
| 207 | `logical_ops_swf8` | 108 | 13.6s |  |
| 208 | `looping` | 6 | 13.3s |  |
| 209 | `mask_reapply` | 0 | 13.3s |  |
| 210 | `mask_with_drawing` | 0 | 13.2s |  |
| 211 | `math_min_max` | 101 | 13.1s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 212 | `math_swf6` | 530 | 13.6s | [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 213 | `math_swf7` | 530 | 13.7s | [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 214 | `math_swf8` | 530 | 13.6s | [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 215 | `matrix` | 171 | 13.8s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 216 | `movieclip_begin_gradient_fill` | 0 | 13.0s |  |
| 217 | `movieclip_blend_mode_property` | 35 | 14.5s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 218 | `movieclip_create_text_field` | 90 | 13.0s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 219 | `movieclip_default_state` | 69 | 13.0s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 220 | `movieclip_depth_methods` | 98 | 13.0s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 221 | `movieclip_focusenabled` | 99 | 12.8s | [14](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 222 | `movieclip_get_instance_at_depth` | 28 | 12.8s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 223 | `movieclip_hittest` | 92 | 13.0s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 224 | `movieclip_in_removed_button` | 4 | 12.8s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 225 | `movieclip_init_object` | 5 | 13.0s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 226 | `movieclip_line_gradient_style` | 0 | 13.1s |  |
| 227 | `movieclip_name_from_timeline` | 13 | 12.3s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 228 | `movieclip_prototype_extension` | 5 | 12.3s |  |
| 229 | `mutable_this` | 18 | 12.4s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 230 | `named_shapes` | 14 | 12.3s |  |
| 231 | `nan_scale` | 9 | 12.5s |  |
| 232 | `native_double_construct` | 12 | 12.4s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 233 | `native_objects_swf7` | 84 | 12.8s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 234 | `native_objects_swf8` | 84 | 12.8s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 235 | `nested_textfields_in_buttons` | 0 | 12.3s |  |
| 236 | `new_method_wrap` | 4 | 12.9s |  |
| 237 | `new_object_enumerate` | 7 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 238 | `new_object_wrap` | 4 | 12.9s |  |
| 239 | `o` | 3 | 12.8s |  |
| 240 | `object_constructor` | 33 | 12.9s |  |
| 241 | `object_function` | 32 | 13.1s |  |
| 242 | `object_properties` | 31 | 13.0s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 243 | `object_prototypes` | 74 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 244 | `object_resolve` | 38 | 12.9s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 245 | `object_string_coerce_swf5` | 62 | 13.2s | [31](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 246 | `object_string_coerce_swf6` | 68 | 12.9s | [31](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 247 | `on_construct` | 25 | 13.0s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 248 | `parse_float` | 74 | 12.9s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [34](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 249 | `parse_int` | 64 | 13.0s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [34](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 250 | `path_string` | 322 | 13.0s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 251 | `place_and_lookup` | 30 | 12.9s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 252 | `placeobject_occupied_depth` | 6 | 13.0s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 253 | `point` | 175 | 13.2s | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 254 | `primitive_instanceof` | 37 | 13.1s |  |
| 255 | `primitive_type_globals` | 557 | 13.8s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 256 | `printjob_props_swf5` | 45 | 12.6s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 257 | `printjob_props_swf6` | 45 | 12.6s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 258 | `printjob_props_swf7` | 45 | 12.5s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 259 | `property_invalid_base_clip` | 36 | 12.5s |  |
| 260 | `prototype_delete` | 12 | 12.5s |  |
| 261 | `prototype_enumerate` | 5 | 12.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 262 | `prototype_properties` | 17 | 12.5s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 263 | `rectangle` | 745 | 13.3s | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 264 | `recursive_prototypes` | 0 | 12.4s |  |
| 265 | `register_class_return_value` | 16 | 12.6s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 266 | `register_class_with_sound` | 11 | 12.6s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [39](ruffle-tests/_investigation/incomplete/SOUND_CLASS_PLAN.md) |
| 267 | `register_globals_across_frames` | 15 | 12.6s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 268 | `register_underflow` | 26 | 12.5s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 269 | `remove_movie_clip` | 29 | 12.6s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 270 | `rewind_depth` | 30 | 12.9s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 271 | `sandbox_type_local_file` | 1 | 12.7s |  |
| 272 | `sandbox_type_local_network` | 1 | 12.6s |  |
| 273 | `selection` | 454 | 13.0s | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 274 | `set_interval` | 27 | 13.0s | [52](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 275 | `set_variable_scope` | 58 | 12.8s |  |
| 276 | `single_frame` | 1 | 12.7s |  |
| 277 | `slash_syntax` | 14 | 13.0s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 278 | `sound_props_swf5` | 68 | 12.7s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 279 | `sound_props_swf6` | 68 | 12.8s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 280 | `sound_start_load` | 0 | 12.8s |  |
| 281 | `stage_display_state` | 16 | 13.0s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 282 | `stage_object_children` | 83 | 12.7s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 283 | `stage_object_enumerate` | 4 | 12.5s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 284 | `stage_object_properties` | 241 | 13.0s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 285 | `stage_object_properties_get_var` | 5 | 12.5s |  |
| 286 | `stage_object_properties_swf6` | 231 | 13.0s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 287 | `stage_property_representation` | 586 | 12.7s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 288 | `stage_scale_mode` | 39 | 12.7s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 289 | `strictequals_swf6` | 902 | 14.2s |  |
| 290 | `strictly_equals` | 7 | 12.8s |  |
| 291 | `string_methods` | 285 | 13.6s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 292 | `string_methods_negative_args` | 240 | 13.0s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 293 | `string_methods_swfv5` | 275 | 13.2s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 294 | `string_ops_swf6` | 95 | 12.7s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 295 | `string_paths_basic` | 4 | 12.6s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 296 | `string_paths_eval2` | 7 | 12.9s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 297 | `string_paths_hidden` | 54 | 12.8s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 298 | `string_paths_other` | 36 | 12.8s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 299 | `string_paths_unload` | 1 | 12.8s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 300 | `string_paths_variable_alias` | 4 | 12.7s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 301 | `string_paths_variable_scopes` | 5 | 12.8s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 302 | `stylesheet` | 283 | 13.5s |  |
| 303 | `stylesheet_transform` | 750 | 13.5s |  |
| 304 | `super_edge_cases` | 39 | 12.9s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 305 | `swf4_actions_bool` | 96 | 12.8s |  |
| 306 | `swf4_actions_coercion_order` | 158 | 12.9s | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 307 | `swf4_bool` | 4 | 12.9s |  |
| 308 | `swf4_function_calls` | 7 | 12.9s |  |
| 309 | `swf5_encoding` | 3 | 12.9s |  |
| 310 | `swf5_no_closure` | 19 | 13.1s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 311 | `swf6_case_insensitive` | 42 | 12.7s | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 312 | `swf6_string_as_bool` | 15 | 12.8s | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 313 | `swf7_case_sensitive` | 44 | 12.7s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 314 | `tab_ordering_properties_tab_index_edge_case` | 4 | 12.3s |  |
| 315 | `target_clip_swf5` | 2 | 12.3s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 316 | `target_clip_swf6` | 2 | 12.2s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 317 | `target_path` | 14 | 12.2s |  |
| 318 | `tell_target` | 37 | 12.3s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 319 | `tell_target_invalid` | 6 | 12.3s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 320 | `tell_target_invalid_swf6` | 5 | 12.3s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 321 | `text_format` | 1146 | 12.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 322 | `text_format_display` | 21 | 12.4s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 323 | `text_format_font_max_length` | 2 | 12.3s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 324 | `text_format_rounding_swf7` | 840 | 12.4s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 325 | `text_format_rounding_swf8` | 840 | 12.4s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 326 | `textfield_background_color` | 11 | 12.3s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 327 | `textfield_border_color` | 11 | 12.3s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 328 | `textfield_cache_as_bitmap` | 1 | 12.3s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 329 | `textfield_maxchars` | 3 | 14.3s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 330 | `textfield_properties` | 44 | 13.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 331 | `textfield_props_swf5` | 175 | 13.9s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 332 | `textfield_props_swf6` | 210 | 13.9s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 333 | `textfield_props_swf7` | 210 | 13.4s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 334 | `textfield_props_swf8` | 210 | 13.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 335 | `textfield_text` | 7 | 13.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 336 | `textfield_variable` | 81 | 13.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 337 | `textsnapshot_available_text` | 20 | 13.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 338 | `textsnapshot_findtext` | 44 | 13.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 339 | `textsnapshot_gettext` | 55 | 13.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 340 | `textsnapshot_props_swf5` | 56 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 341 | `textsnapshot_props_swf6` | 56 | 13.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 342 | `textsnapshot_text_order` | 1 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 343 | `this_scoping` | 52 | 13.1s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 344 | `this_swf5` | 41 | 13.0s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 345 | `this_swf6` | 41 | 13.0s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 346 | `this_swf7` | 41 | 13.2s | [51](ruffle-tests/_investigation/complete/this_swf7.md) |
| 347 | `timeline_function_def` | 7 | 13.3s |  |
| 348 | `trace` | 8 | 12.9s |  |
| 349 | `transform` | 70 | 12.8s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 350 | `try_catch_finally` | 118 | 12.8s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 351 | `try_finally_simple` | 16 | 12.6s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 352 | `typeof` | 22 | 12.6s |  |
| 353 | `typeof_globals` | 7 | 12.7s |  |
| 354 | `uncaught_exception` | 1 | 12.6s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 355 | `uncaught_exception_bubbled` | 1 | 12.6s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 356 | `undefined_to_string_swf6` | 4 | 12.6s |  |
| 357 | `unescape` | 43 | 12.6s |  |
| 358 | `unload` | 52 | 12.9s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 359 | `unload_clip_event` | 4 | 12.6s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 360 | `use_hand_cursor` | 8 | 12.6s |  |
| 361 | `variable_args` | 5 | 12.7s |  |
| 362 | `waitforframe` | 7 | 12.6s |  |
| 363 | `waitforframe2` | 16 | 17.6s |  |
| 364 | `watch` | 117 | 12.8s | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 365 | `watch_textfield` | 12 | 12.5s | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 366 | `watch_virtual_property_proto` | 2 | 12.5s | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 367 | `with` | 49 | 12.5s | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 368 | `with_return` | 2 | 12.4s |  |
| 369 | `with_variable_scopes` | 43 | 12.5s | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 370 | `xml` | 15 | 12.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 371 | `xml_append_child` | 28 | 12.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 372 | `xml_append_child_with_parent` | 20 | 12.5s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 373 | `xml_cdata` | 11 | 12.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 374 | `xml_child_nodes_edge_cases` | 4 | 12.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 375 | `xml_clone_expandos` | 19 | 12.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 376 | `xml_first_last_child` | 8 | 12.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 377 | `xml_has_child_nodes` | 3 | 12.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 378 | `xml_idmap` | 21 | 12.5s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 379 | `xml_ignore_comments` | 21 | 12.5s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 380 | `xml_ignore_white` | 34 | 17.2s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 381 | `xml_insert_before` | 20 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 382 | `xml_inspect_createmethods` | 15 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 383 | `xml_inspect_doctype` | 7 | 12.8s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 384 | `xml_inspect_parsexml` | 62 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 385 | `xml_inspect_xmldecl` | 7 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 386 | `xml_namespaces` | 203 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 387 | `xml_parent_and_child` | 5 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 388 | `xml_remove_node` | 22 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 389 | `xml_reparenting` | 14 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 390 | `xml_siblings` | 10 | 12.6s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 391 | `xml_to_string` | 13 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 392 | `xml_to_string_comment` | 1 | 13.1s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 393 | `xml_unescaping` | 23 | 12.9s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 394 | `xmlnode_proto` | 1 | 13.1s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**25 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `string_coercion` | 99.1% | 116 | 117 | 1 | [42](ruffle-tests/_investigation/complete/string_coercion.md) |
| 2 | `sound` | 99.0% | 622 | 628 | 6 | [39](ruffle-tests/_investigation/incomplete/SOUND_CLASS_PLAN.md) |
| 3 | `edittext_html_condensewhite_swf7` | 99.0% | 308 | 311 | 3 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `funky_function_calls` | 92.9% | 52 | 56 | 4 | [16](ruffle-tests/_investigation/incomplete/FUNCTION_EDGE_CASES_PLAN.md) |
| 9 | `function_base_clip_readded` | 90.9% | 10 | 11 | 1 |  |
| 10 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 11 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 12 | `edittext_html_condensewhite_swf8` | 80.1% | 249 | 311 | 62 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 13 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 14 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 15 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 17 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 18 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 19 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 20 | `register_class` | 57.6% | 38 | 66 | 28 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 21 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 22 | `gettextextent` | 55.4% | 31 | 56 | 25 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 23 | `device_font_spacing` | 50.5% | 46 | 91 | 45 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 24 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 25 | `issue_2030` | 50.0% | 2 | 4 | 2 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

**3 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `netstream_play_flv_screen` | 27.3s |  |
| 2 | `string_paths_timer` | 14.8s | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 3 | `timer_run_actions` | 17.3s | [52](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 36.2s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 35.9s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 23.1s | [52](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**76 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `string_coercion` | 99.1% | 116/117 | 117 | 117 | [42](ruffle-tests/_investigation/complete/string_coercion.md) |
| 2 | `sound` | 99.0% | 622/628 | 628 | 628 | [39](ruffle-tests/_investigation/incomplete/SOUND_CLASS_PLAN.md) |
| 3 | `edittext_html_condensewhite_swf7` | 99.0% | 308/311 | 311 | 311 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `funky_function_calls` | 92.9% | 52/56 | 56 | 56 | [16](ruffle-tests/_investigation/incomplete/FUNCTION_EDGE_CASES_PLAN.md) |
| 9 | `function_base_clip_readded` | 90.9% | 10/11 | 11 | 11 |  |
| 10 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 11 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 12 | `edittext_html_condensewhite_swf8` | 80.1% | 249/311 | 311 | 311 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 13 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 14 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 15 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 17 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 18 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 19 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 20 | `register_class` | 57.6% | 38/66 | 47 | 66 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 21 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 22 | `gettextextent` | 55.4% | 31/56 | 56 | 56 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 23 | `device_font_spacing` | 50.5% | 46/91 | 91 | 91 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 24 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 25 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 26 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 27 | `define_local_with_paths` | 40.7% | 22/54 | 34 | 54 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 28 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 29 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 30 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 31 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 32 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 33 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 34 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 35 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 36 | `removed_target_clip_scope` | 29.7% | 11/37 | 37 | 35 | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 37 | `default_names` | 28.8% | 15/52 | 48 | 52 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 38 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 39 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 40 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 41 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 42 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 43 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 44 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 45 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 46 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 | [54](ruffle-tests/_investigation/incomplete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 47 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 48 | `coerce_to_object_monkeypatch` | 12.4% | 16/129 | 112 | 129 | [54](ruffle-tests/_investigation/incomplete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 49 | `define_local` | 7.4% | 2/27 | 23 | 27 | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 50 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 51 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 52 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 53 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 54 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 55 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 56 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 57 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 58 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 59 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [16](ruffle-tests/_investigation/incomplete/FUNCTION_EDGE_CASES_PLAN.md) |
| 60 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 61 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 62 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 63 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 64 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 65 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 66 | `geturl` | 0.0% | 0/7 | 0 | 7 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 67 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 68 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 69 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 70 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 71 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 72 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 73 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 74 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 75 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 76 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 7 | 7 |
| 6 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) | 2 | 1 | 1 |
| 7 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 4 | 4 |
| 8 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 1 | 3 |
| 9 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 10 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 11 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 0 | 4 |
| 12 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 13 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 14 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 1 | 6 |
| 15 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 16 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/incomplete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 1 | 2 |
| 17 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 18 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 22 | 9 |
| 19 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 20 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 21 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 22 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 2 | 47 |
| 23 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 24 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 0 | 4 |
| 25 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 26 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 27 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 0 | 5 |
| 28 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 30 | 28 |
| 29 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 0 | 16 |
| 30 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 14 | 3 |
| 31 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 32 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 33 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 7 | 1 |
| 34 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 35 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 11 | 1 |
| 36 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 12 | 3 |
| 37 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 0 | 4 |
| 38 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 2 | 2 |
| 39 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/incomplete/SOUND_CLASS_PLAN.md) | 2 | 1 | 1 |
| 40 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 41 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 42 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 0 | 1 |
| 43 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 44 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 45 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 46 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) | 16 | 1 | 15 |
| 47 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 14 | 5 |
| 48 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 70 | 50 | 20 |
| 49 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 50 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 51 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 52 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 53 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 54 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/incomplete/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 0 | 2 |
| 55 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 1 | 15 |
| 56 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 7 | 5 |
| 57 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 58 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 158 | 151 | 7 |
