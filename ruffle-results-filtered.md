# Ruffle Test Results (Filtered)

**Date**: 2026-03-05 03:27 UTC

**Git SHA**: `5b87539d7f`

**Run Duration**: 134m 38s

**Filtered**: 142 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 477 |
| Passing | **387** (81.1%) |
| Failing | 90 |
| Total expected lines | 71229 |
| Matching lines | 57471 (80.7%) |
| Mismatched lines | 13758 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 83 | 92.2% |
| Segfault | 3 | 3.3% |
| Runtime Error | 2 | 2.2% |
| Compile Fail | 1 | 1.1% |
| Timeout | 1 | 1.1% |

## Passing Tests

**387 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 12.6s |  |
| 2 | `action_to_integer` | 28 | 12.5s |  |
| 3 | `add` | 28 | 12.5s |  |
| 4 | `add2` | 354 | 12.7s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 12.5s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 12.8s |  |
| 7 | `add_swf5` | 28 | 12.6s |  |
| 8 | `arguments` | 127 | 12.6s | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [34](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 12.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 12.6s |  |
| 11 | `array_constructor` | 30 | 12.7s |  |
| 12 | `array_enumerate` | 4 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 12.7s |  |
| 14 | `array_properties` | 36 | 12.5s |  |
| 15 | `array_prototyping` | 12 | 12.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 12.6s |  |
| 17 | `array_sort_random` | 443 | 12.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 12.7s |  |
| 19 | `array_trivial` | 209 | 12.6s |  |
| 20 | `as1_constructor_v6` | 35 | 12.5s |  |
| 21 | `as1_constructor_v7` | 35 | 12.9s |  |
| 22 | `as2_oop` | 13 | 12.7s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 12.7s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 12.8s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 12.7s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster` | 41 | 12.5s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 12.4s |  |
| 28 | `as_broadcaster_undef` | 89 | 12.6s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 29 | `as_set_prop_flags` | 79 | 12.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version` | 31 | 12.5s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version_swf5` | 1 | 12.5s |  |
| 32 | `as_set_prop_flags_version_swf6` | 1 | 12.5s |  |
| 33 | `as_set_prop_flags_version_swf7` | 1 | 12.5s |  |
| 34 | `as_set_prop_flags_version_swf8` | 1 | 12.5s |  |
| 35 | `as_set_prop_flags_version_swf9` | 1 | 12.5s |  |
| 36 | `as_transformed_flag` | 20 | 12.5s |  |
| 37 | `attach_movie` | 59 | 12.4s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 38 | `attach_movie_stop` | 3 | 12.5s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 39 | `bad_placeobject_clipaction` | 2 | 14.9s |  |
| 40 | `bad_swf_tag_past_eof` | 0 | 13.1s |  |
| 41 | `bitand` | 1058 | 15.8s |  |
| 42 | `bitmap_data_colortransform` | 0 | 13.3s |  |
| 43 | `bitmap_data_fillrect` | 0 | 13.2s |  |
| 44 | `bitmap_data_max_size_swf10` | 12 | 13.1s |  |
| 45 | `bitmap_data_max_size_swf9` | 10 | 13.0s |  |
| 46 | `bitmap_data_perlinnoise` | 0 | 13.7s |  |
| 47 | `bitmap_data_pixeldissolve_image` | 0 | 13.5s |  |
| 48 | `bitmapdata_applyfilter_colormatrix` | 0 | 13.1s |  |
| 49 | `bitor` | 1058 | 16.1s |  |
| 50 | `biturshift` | 14 | 13.0s |  |
| 51 | `biturshift_swf8` | 14 | 16.1s |  |
| 52 | `bitxor` | 1058 | 15.1s |  |
| 53 | `boxed_primitives` | 24 | 12.7s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 54 | `button_children` | 8 | 12.6s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_goto` | 4 | 12.6s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_order` | 2 | 12.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_properties_special_cases` | 22 | 12.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_v5` | 18 | 12.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_v6` | 18 | 12.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `call` | 63 | 12.7s | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) |
| 61 | `call_method_empty_name` | 1 | 12.5s |  |
| 62 | `capabilities_resolution` | 8 | 12.5s |  |
| 63 | `catch_references_registers` | 2 | 12.5s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 64 | `clip_constructors` | 8 | 12.7s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 65 | `clip_events` | 19 | 13.0s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 66 | `clone_sprite_types` | 24 | 12.7s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 67 | `closure_scope` | 7 | 12.8s | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 68 | `color` | 57 | 13.1s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 69 | `color_transform` | 48 | 13.0s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 70 | `conflicting_instance_names` | 23 | 12.9s |  |
| 71 | `constructor_function` | 2 | 12.8s |  |
| 72 | `context_menu` | 39 | 12.9s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 73 | `context_menu_item` | 41 | 12.9s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 74 | `create_empty_movie_clip` | 3 | 12.8s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 75 | `define_function2` | 8 | 12.9s |  |
| 76 | `define_function2_preload` | 13 | 12.9s |  |
| 77 | `define_function2_preload_order` | 4 | 14.6s |  |
| 78 | `define_function_case_sensitive` | 2 | 13.0s |  |
| 79 | `delete` | 3 | 13.1s |  |
| 80 | `display_object_properties` | 2 | 13.0s |  |
| 81 | `divide_swf4` | 107 | 13.0s |  |
| 82 | `do_init_action` | 3 | 12.9s |  |
| 83 | `do_init_action_child` | 12 | 13.0s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 84 | `duplicate_movie_clip` | 20 | 12.9s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 85 | `edittext_align` | 60 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 86 | `edittext_align_trailing_spaces_swf7` | 576 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 87 | `edittext_align_trailing_spaces_swf8` | 576 | 12.9s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 88 | `edittext_antialiastype` | 296 | 13.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 89 | `edittext_autosize` | 71 | 13.4s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 90 | `edittext_autosize_setter` | 20 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 91 | `edittext_default_format` | 221 | 12.9s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 92 | `edittext_default_format_font_style` | 335 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 93 | `edittext_font_size` | 45 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 94 | `edittext_hscroll` | 27 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 95 | `edittext_html_align_swf7` | 52 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 96 | `edittext_html_align_swf8` | 52 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 97 | `edittext_html_color` | 114 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 98 | `edittext_html_entity` | 4 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 99 | `edittext_html_roundtrip` | 17 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_html_swf7` | 5377 | 13.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_html_swf8` | 5377 | 13.4s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_leading` | 9 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_letter_spacing` | 15 | 12.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_margins` | 25 | 12.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_newline_stripping` | 64 | 17.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_programmatic_focus` | 12 | 12.5s | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_stylesheet` | 325 | 13.0s | [44](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_tag_indent` | 31 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_text_height_leading` | 20 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_underline` | 40 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_width_height` | 103 | 12.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `empty_movieclip_can_attach_movies` | 11 | 13.8s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 113 | `enumerate` | 64 | 12.6s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 114 | `equals` | 32 | 12.6s |  |
| 115 | `equals2_swf5` | 926 | 14.4s |  |
| 116 | `equals2_swf6` | 926 | 14.5s |  |
| 117 | `equals2_swf7` | 926 | 14.5s |  |
| 118 | `equals_swf4` | 665 | 13.5s |  |
| 119 | `equals_swf4_alt` | 32 | 12.7s |  |
| 120 | `equals_swf5` | 32 | 12.5s |  |
| 121 | `error` | 58 | 12.7s |  |
| 122 | `escape` | 14 | 12.5s |  |
| 123 | `execution_order1` | 5 | 12.6s |  |
| 124 | `execution_order2` | 7 | 12.7s |  |
| 125 | `execution_order3` | 4 | 12.6s |  |
| 126 | `execution_order4` | 12 | 12.7s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 127 | `export_assets` | 3 | 12.6s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 128 | `extends_chain` | 134 | 13.0s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 129 | `extends_native_type` | 11 | 12.7s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 130 | `focusrect_mouse_swf8` | 0 | 12.3s |  |
| 131 | `focusrect_mouse_swf9` | 0 | 13.3s |  |
| 132 | `focusrect_swf5` | 6 | 12.6s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 133 | `frame_size_translated_negative` | 21 | 12.5s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 134 | `frame_size_translated_positive` | 21 | 12.5s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 135 | `function_as_function` | 35 | 12.4s | [16](ruffle-tests/_investigation/incomplete/FUNCTION_EDGE_CASES_PLAN.md) |
| 136 | `function_base_clip` | 8 | 12.4s |  |
| 137 | `function_base_clip_removed` | 25 | 12.6s |  |
| 138 | `function_suppress_and_preload` | 28 | 12.6s |  |
| 139 | `get_variable_in_scope` | 29 | 12.4s |  |
| 140 | `getproperty` | 28 | 12.5s |  |
| 141 | `getproperty_swf4` | 28 | 12.8s |  |
| 142 | `getproperty_swf5` | 28 | 12.5s |  |
| 143 | `global_array` | 3 | 12.4s |  |
| 144 | `global_is_bare` | 7 | 12.5s |  |
| 145 | `global_swf6_7_8` | 15 | 12.8s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 146 | `globals_swf5` | 304 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 147 | `globals_swf6` | 304 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 148 | `globals_swf7` | 304 | 12.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 149 | `globals_swf8` | 304 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 150 | `goto_advance1` | 6 | 12.4s |  |
| 151 | `goto_advance2` | 2 | 12.5s |  |
| 152 | `goto_both_ways1` | 3 | 12.4s |  |
| 153 | `goto_both_ways2` | 3 | 12.6s |  |
| 154 | `goto_execution_order` | 2 | 12.4s |  |
| 155 | `goto_execution_order2` | 2 | 12.4s |  |
| 156 | `goto_frame` | 12 | 14.1s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 157 | `goto_frame2` | 44 | 13.4s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 158 | `goto_frame_number` | 3 | 12.9s |  |
| 159 | `goto_label` | 17 | 13.0s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 160 | `goto_methods` | 40 | 12.9s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 161 | `goto_rewind1` | 1 | 12.9s |  |
| 162 | `goto_rewind2` | 3 | 12.8s |  |
| 163 | `goto_rewind3` | 2 | 12.8s |  |
| 164 | `greater_swf6` | 1175 | 14.7s |  |
| 165 | `greater_swf7` | 1175 | 14.7s |  |
| 166 | `greaterthan_swf5` | 1 | 12.8s |  |
| 167 | `greaterthan_swf8` | 1 | 12.6s |  |
| 168 | `has_own_property` | 32 | 12.7s |  |
| 169 | `hittest_lockroot` | 15 | 12.8s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 170 | `hittest_morph` | 70 | 12.7s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 171 | `hittest_winding_rule` | 12 | 12.8s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 172 | `infinite_recursion_function` | 4 | 12.6s | [20](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 173 | `infinite_recursion_function_in_setter` | 131 | 12.7s | [20](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 174 | `infinite_recursion_virtual_property` | 67 | 12.6s | [20](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 175 | `init_array_invalid` | 4 | 12.5s |  |
| 176 | `init_object_invalid` | 4 | 15.1s |  |
| 177 | `init_object_order` | 15 | 12.8s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 178 | `is_finite` | 49 | 12.6s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 179 | `is_finite_swf6` | 49 | 12.6s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 180 | `is_prototype_of` | 89 | 12.6s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 181 | `issue_1086` | 1 | 12.7s |  |
| 182 | `issue_1104` | 2 | 12.7s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 183 | `issue_1671` | 0 | 12.6s |  |
| 184 | `issue_1906` | 4 | 12.6s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 185 | `issue_2166` | 9 | 12.6s |  |
| 186 | `issue_3169` | 2 | 12.6s | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 187 | `issue_3446` | 1 | 12.5s |  |
| 188 | `issue_4377` | 2 | 12.5s |  |
| 189 | `issue_710` | 4 | 12.7s |  |
| 190 | `issue_768` | 3 | 12.7s | [21](ruffle-tests/_investigation/complete/issue_768.md) |
| 191 | `issue_9327` | 2 | 12.8s |  |
| 192 | `issue_9885` | 2 | 12.8s |  |
| 193 | `lessthan` | 41 | 12.8s |  |
| 194 | `lessthan2_swf5` | 1226 | 14.8s |  |
| 195 | `lessthan2_swf6` | 1226 | 14.6s |  |
| 196 | `lessthan2_swf7` | 1226 | 14.5s |  |
| 197 | `lessthan_swf4` | 902 | 13.8s |  |
| 198 | `lessthan_swf4_alt` | 41 | 12.5s |  |
| 199 | `lessthan_swf5` | 41 | 12.5s |  |
| 200 | `local_to_global` | 49 | 13.1s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 201 | `localconnection_properties` | 8 | 12.9s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 202 | `lock_root` | 1 | 12.9s |  |
| 203 | `logical_ops_swf4` | 90 | 12.9s |  |
| 204 | `logical_ops_swf8` | 108 | 13.0s |  |
| 205 | `looping` | 6 | 12.9s |  |
| 206 | `mask_reapply` | 0 | 12.9s |  |
| 207 | `mask_with_drawing` | 0 | 13.1s |  |
| 208 | `math_min_max` | 101 | 13.2s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 209 | `math_swf6` | 530 | 13.7s | [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 210 | `math_swf7` | 530 | 13.6s | [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 211 | `math_swf8` | 530 | 13.4s | [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 212 | `matrix` | 171 | 13.4s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 213 | `movieclip_begin_gradient_fill` | 0 | 13.3s |  |
| 214 | `movieclip_blend_mode_property` | 35 | 12.9s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 215 | `movieclip_create_text_field` | 90 | 12.6s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 216 | `movieclip_default_state` | 69 | 12.7s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 217 | `movieclip_depth_methods` | 98 | 12.7s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 218 | `movieclip_focusenabled` | 99 | 12.6s | [14](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 219 | `movieclip_get_instance_at_depth` | 28 | 12.5s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 220 | `movieclip_hittest` | 92 | 12.6s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 221 | `movieclip_in_removed_button` | 4 | 12.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 222 | `movieclip_init_object` | 5 | 12.6s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 223 | `movieclip_line_gradient_style` | 0 | 15.3s |  |
| 224 | `movieclip_name_from_timeline` | 13 | 12.5s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 225 | `movieclip_prototype_extension` | 5 | 12.6s |  |
| 226 | `mutable_this` | 18 | 12.4s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 227 | `named_shapes` | 14 | 12.5s |  |
| 228 | `nan_scale` | 9 | 12.6s |  |
| 229 | `native_double_construct` | 12 | 12.7s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 230 | `native_objects_swf7` | 84 | 13.0s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 231 | `native_objects_swf8` | 84 | 13.2s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 232 | `nested_textfields_in_buttons` | 0 | 12.7s |  |
| 233 | `new_method_wrap` | 4 | 12.6s |  |
| 234 | `new_object_enumerate` | 7 | 12.5s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 235 | `new_object_wrap` | 4 | 12.5s |  |
| 236 | `o` | 3 | 12.4s |  |
| 237 | `object_constructor` | 33 | 12.4s |  |
| 238 | `object_function` | 32 | 12.4s |  |
| 239 | `object_properties` | 31 | 12.6s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 240 | `object_prototypes` | 74 | 12.5s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 241 | `object_string_coerce_swf5` | 62 | 12.5s | [31](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 242 | `object_string_coerce_swf6` | 68 | 12.5s | [31](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 243 | `on_construct` | 25 | 12.6s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 244 | `parse_float` | 74 | 12.5s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [34](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 245 | `parse_int` | 64 | 12.7s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [34](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 246 | `path_string` | 322 | 12.6s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 247 | `place_and_lookup` | 30 | 12.4s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 248 | `placeobject_occupied_depth` | 6 | 12.5s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 249 | `point` | 175 | 12.9s | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 250 | `primitive_instanceof` | 37 | 12.7s |  |
| 251 | `primitive_type_globals` | 557 | 14.9s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 252 | `property_invalid_base_clip` | 36 | 13.1s |  |
| 253 | `prototype_delete` | 12 | 12.8s |  |
| 254 | `prototype_enumerate` | 5 | 12.9s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 255 | `prototype_properties` | 17 | 13.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 256 | `rectangle` | 745 | 13.8s | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 257 | `recursive_prototypes` | 0 | 13.0s |  |
| 258 | `register_class_return_value` | 16 | 13.6s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 259 | `register_class_with_sound` | 11 | 13.4s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [39](ruffle-tests/_investigation/incomplete/SOUND_CLASS_PLAN.md) |
| 260 | `register_globals_across_frames` | 15 | 13.1s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 261 | `register_underflow` | 26 | 13.2s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 262 | `remove_movie_clip` | 29 | 13.6s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 263 | `rewind_depth` | 30 | 13.2s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 264 | `sandbox_type_local_file` | 1 | 13.0s |  |
| 265 | `sandbox_type_local_network` | 1 | 12.8s |  |
| 266 | `selection` | 454 | 13.2s | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 267 | `set_interval` | 27 | 13.1s | [52](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 268 | `set_variable_scope` | 58 | 13.1s |  |
| 269 | `single_frame` | 1 | 13.1s |  |
| 270 | `slash_syntax` | 14 | 13.2s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 271 | `sound_props_swf5` | 68 | 12.7s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 272 | `sound_props_swf6` | 68 | 12.6s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 273 | `sound_start_load` | 0 | 12.7s |  |
| 274 | `stage_display_state` | 16 | 12.6s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 275 | `stage_object_children` | 83 | 12.7s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 276 | `stage_object_enumerate` | 4 | 12.6s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 277 | `stage_object_properties` | 241 | 12.9s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 278 | `stage_object_properties_get_var` | 5 | 12.6s |  |
| 279 | `stage_object_properties_swf6` | 231 | 13.0s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 280 | `stage_property_representation` | 586 | 12.6s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 281 | `stage_scale_mode` | 39 | 12.7s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 282 | `strictequals_swf6` | 902 | 14.0s |  |
| 283 | `strictly_equals` | 7 | 12.6s |  |
| 284 | `string_methods` | 285 | 13.1s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 285 | `string_methods_negative_args` | 240 | 12.6s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 286 | `string_methods_swfv5` | 275 | 13.1s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 287 | `string_ops_swf6` | 95 | 12.7s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 288 | `string_paths_basic` | 4 | 12.6s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 289 | `string_paths_eval2` | 7 | 12.9s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 290 | `string_paths_hidden` | 54 | 12.9s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 291 | `string_paths_other` | 36 | 12.9s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 292 | `string_paths_unload` | 1 | 12.8s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 293 | `string_paths_variable_alias` | 4 | 12.8s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 294 | `string_paths_variable_scopes` | 5 | 12.9s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 295 | `stylesheet` | 283 | 13.5s |  |
| 296 | `stylesheet_transform` | 750 | 13.5s |  |
| 297 | `super_edge_cases` | 39 | 12.9s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 298 | `swf4_actions_bool` | 96 | 12.8s |  |
| 299 | `swf4_actions_coercion_order` | 158 | 12.8s | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 300 | `swf4_bool` | 4 | 12.7s |  |
| 301 | `swf4_function_calls` | 7 | 12.6s |  |
| 302 | `swf5_encoding` | 3 | 12.6s |  |
| 303 | `swf5_no_closure` | 19 | 14.1s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 304 | `swf6_case_insensitive` | 42 | 12.6s | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 305 | `swf6_string_as_bool` | 15 | 12.6s | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 306 | `swf7_case_sensitive` | 44 | 12.5s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 307 | `tab_ordering_properties_tab_index_edge_case` | 4 | 12.6s |  |
| 308 | `target_clip_swf5` | 2 | 12.6s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 309 | `target_clip_swf6` | 2 | 12.5s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 310 | `target_path` | 14 | 12.6s |  |
| 311 | `tell_target` | 37 | 12.7s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 312 | `tell_target_invalid` | 6 | 12.6s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 313 | `tell_target_invalid_swf6` | 5 | 12.6s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 314 | `text_format` | 1146 | 12.9s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 315 | `text_format_display` | 21 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 316 | `text_format_font_max_length` | 2 | 12.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 317 | `text_format_rounding_swf7` | 840 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 318 | `text_format_rounding_swf8` | 840 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 319 | `textfield_background_color` | 11 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 320 | `textfield_border_color` | 11 | 12.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 321 | `textfield_cache_as_bitmap` | 1 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 322 | `textfield_maxchars` | 3 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 323 | `textfield_properties` | 44 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 324 | `textfield_props_swf5` | 175 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 325 | `textfield_props_swf6` | 210 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 326 | `textfield_props_swf7` | 210 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 327 | `textfield_props_swf8` | 210 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 328 | `textfield_text` | 7 | 12.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 329 | `textfield_variable` | 81 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 330 | `textsnapshot_available_text` | 20 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 331 | `textsnapshot_findtext` | 44 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 332 | `textsnapshot_gettext` | 55 | 12.9s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 333 | `textsnapshot_props_swf5` | 56 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 334 | `textsnapshot_props_swf6` | 56 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 335 | `textsnapshot_text_order` | 1 | 12.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 336 | `this_scoping` | 52 | 12.6s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 337 | `this_swf5` | 41 | 12.6s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 338 | `this_swf6` | 41 | 12.5s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 339 | `this_swf7` | 41 | 12.4s | [51](ruffle-tests/_investigation/complete/this_swf7.md) |
| 340 | `timeline_function_def` | 7 | 12.5s |  |
| 341 | `trace` | 8 | 12.7s |  |
| 342 | `transform` | 70 | 12.6s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 343 | `try_catch_finally` | 118 | 12.6s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 344 | `try_finally_simple` | 16 | 12.4s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 345 | `typeof` | 22 | 12.4s |  |
| 346 | `typeof_globals` | 7 | 12.4s |  |
| 347 | `uncaught_exception` | 1 | 12.4s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 348 | `uncaught_exception_bubbled` | 1 | 12.4s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 349 | `undefined_to_string_swf6` | 4 | 12.7s |  |
| 350 | `unescape` | 43 | 12.7s |  |
| 351 | `unload` | 52 | 13.0s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 352 | `unload_clip_event` | 4 | 12.5s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 353 | `use_hand_cursor` | 8 | 12.4s |  |
| 354 | `variable_args` | 5 | 12.6s |  |
| 355 | `waitforframe` | 7 | 12.4s |  |
| 356 | `waitforframe2` | 16 | 13.2s |  |
| 357 | `watch` | 117 | 12.8s | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 358 | `watch_textfield` | 12 | 12.7s | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 359 | `watch_virtual_property_proto` | 2 | 12.5s | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 360 | `with` | 49 | 12.5s | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 361 | `with_return` | 2 | 12.4s |  |
| 362 | `with_variable_scopes` | 43 | 12.6s | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 363 | `xml` | 15 | 12.6s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 364 | `xml_append_child` | 28 | 12.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 365 | `xml_append_child_with_parent` | 20 | 12.5s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 366 | `xml_cdata` | 11 | 12.6s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 367 | `xml_child_nodes_edge_cases` | 4 | 12.5s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 368 | `xml_clone_expandos` | 19 | 12.6s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 369 | `xml_first_last_child` | 8 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 370 | `xml_has_child_nodes` | 3 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 371 | `xml_idmap` | 21 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 372 | `xml_ignore_comments` | 21 | 12.8s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 373 | `xml_ignore_white` | 34 | 14.8s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 374 | `xml_insert_before` | 20 | 12.9s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 375 | `xml_inspect_createmethods` | 15 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 376 | `xml_inspect_doctype` | 7 | 12.6s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 377 | `xml_inspect_parsexml` | 62 | 12.6s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 378 | `xml_inspect_xmldecl` | 7 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 379 | `xml_namespaces` | 203 | 12.5s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 380 | `xml_parent_and_child` | 5 | 12.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 381 | `xml_remove_node` | 22 | 12.5s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 382 | `xml_reparenting` | 14 | 12.6s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 383 | `xml_siblings` | 10 | 12.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 384 | `xml_to_string` | 13 | 12.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 385 | `xml_to_string_comment` | 1 | 12.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 386 | `xml_unescaping` | 23 | 12.5s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 387 | `xmlnode_proto` | 1 | 12.8s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**30 tests** within reach

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
| 11 | `printjob_props_swf5` | 88.9% | 40 | 45 | 5 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 12 | `printjob_props_swf6` | 88.9% | 40 | 45 | 5 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 13 | `printjob_props_swf7` | 88.9% | 40 | 45 | 5 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 14 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 15 | `edittext_html_condensewhite_swf8` | 80.1% | 249 | 311 | 62 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 17 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 19 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 20 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 21 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 22 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 23 | `register_class` | 57.6% | 38 | 66 | 28 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 24 | `asnative` | 55.9% | 19 | 34 | 15 | [4](ruffle-tests/_investigation/incomplete/ASNATIVE_ASNEW_PLAN.md) |
| 25 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 26 | `gettextextent` | 55.4% | 31 | 56 | 25 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 27 | `device_font_spacing` | 50.5% | 46 | 91 | 45 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 28 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 29 | `issue_2030` | 50.0% | 2 | 4 | 2 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 30 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

**3 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `netstream_play_flv_screen` | 27.9s |  |
| 2 | `string_paths_timer` | 14.7s | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 3 | `timer_run_actions` | 14.8s | [52](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 35.1s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 35.2s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 22.4s | [52](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**83 tests** with output mismatch, sorted by match rate (best first)

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
| 11 | `printjob_props_swf5` | 88.9% | 40/45 | 45 | 45 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 12 | `printjob_props_swf6` | 88.9% | 40/45 | 45 | 45 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 13 | `printjob_props_swf7` | 88.9% | 40/45 | 45 | 45 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 14 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 15 | `edittext_html_condensewhite_swf8` | 80.1% | 249/311 | 311 | 311 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 17 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 19 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 20 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 21 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 22 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 23 | `register_class` | 57.6% | 38/66 | 47 | 66 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 24 | `asnative` | 55.9% | 19/34 | 31 | 34 | [4](ruffle-tests/_investigation/incomplete/ASNATIVE_ASNEW_PLAN.md) |
| 25 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 26 | `gettextextent` | 55.4% | 31/56 | 56 | 56 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 27 | `device_font_spacing` | 50.5% | 46/91 | 91 | 91 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 28 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 29 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 30 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 31 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `define_local_with_paths` | 40.7% | 22/54 | 34 | 54 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 33 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 34 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 35 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 36 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 37 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 38 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 39 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 40 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 41 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 42 | `removed_target_clip_scope` | 29.7% | 11/37 | 37 | 35 | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 43 | `asnew` | 29.4% | 10/34 | 18 | 34 | [4](ruffle-tests/_investigation/incomplete/ASNATIVE_ASNEW_PLAN.md) |
| 44 | `default_names` | 28.8% | 15/52 | 48 | 52 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 45 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 46 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 47 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 48 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 49 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 50 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 51 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 52 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 53 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 | [54](ruffle-tests/_investigation/incomplete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 54 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 55 | `coerce_to_object_monkeypatch` | 12.4% | 16/129 | 112 | 129 | [54](ruffle-tests/_investigation/incomplete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 56 | `define_local` | 7.4% | 2/27 | 23 | 27 | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 57 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 58 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 59 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 60 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 61 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 62 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 63 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 64 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 65 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 66 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [16](ruffle-tests/_investigation/incomplete/FUNCTION_EDGE_CASES_PLAN.md) |
| 67 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 68 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 69 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 70 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 71 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 72 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 73 | `geturl` | 0.0% | 0/7 | 0 | 7 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 74 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 75 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 76 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 77 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 78 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 79 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 80 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 81 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 82 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 83 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/incomplete/ASNATIVE_ASNEW_PLAN.md) | 2 | 0 | 2 |
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
| 18 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 19 | 12 |
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
| 35 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 10 | 2 |
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
| | *(tests not in any document)* | 158 | 150 | 8 |
