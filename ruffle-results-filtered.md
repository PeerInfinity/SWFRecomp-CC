# Ruffle Test Results (Filtered)

**Date**: 2026-03-05 17:47 UTC

**Git SHA**: `33d27a9e39`

**Run Duration**: 136m 18s

**Filtered**: 142 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 477 |
| Passing | **395** (82.8%) |
| Failing | 82 |
| Total expected lines | 71229 |
| Matching lines | 57554 (80.8%) |
| Mismatched lines | 13675 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 75 | 91.5% |
| Segfault | 3 | 3.7% |
| Runtime Error | 2 | 2.4% |
| Compile Fail | 1 | 1.2% |
| Timeout | 1 | 1.2% |

## Passing Tests

**395 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 13.5s |  |
| 2 | `action_to_integer` | 28 | 13.0s |  |
| 3 | `add` | 28 | 12.8s |  |
| 4 | `add2` | 354 | 13.3s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 13.2s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 13.5s |  |
| 7 | `add_swf5` | 28 | 13.3s |  |
| 8 | `arguments` | 127 | 13.1s | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [34](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 12.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 12.9s |  |
| 11 | `array_constructor` | 30 | 12.9s |  |
| 12 | `array_enumerate` | 4 | 12.9s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 13.0s |  |
| 14 | `array_properties` | 36 | 12.9s |  |
| 15 | `array_prototyping` | 12 | 12.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 13.0s |  |
| 17 | `array_sort_random` | 443 | 13.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 13.4s |  |
| 19 | `array_trivial` | 209 | 13.3s |  |
| 20 | `as1_constructor_v6` | 35 | 12.9s |  |
| 21 | `as1_constructor_v7` | 35 | 13.5s |  |
| 22 | `as2_oop` | 13 | 13.2s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 13.2s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 13.1s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 13.1s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster` | 41 | 12.9s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 12.9s |  |
| 28 | `as_broadcaster_undef` | 89 | 12.9s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 29 | `as_set_prop_flags` | 79 | 12.9s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version` | 31 | 12.8s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version_swf5` | 1 | 12.8s |  |
| 32 | `as_set_prop_flags_version_swf6` | 1 | 12.8s |  |
| 33 | `as_set_prop_flags_version_swf7` | 1 | 12.8s |  |
| 34 | `as_set_prop_flags_version_swf8` | 1 | 12.9s |  |
| 35 | `as_set_prop_flags_version_swf9` | 1 | 12.9s |  |
| 36 | `as_transformed_flag` | 20 | 13.0s |  |
| 37 | `asnative` | 34 | 13.3s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 38 | `asnew` | 34 | 13.3s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `attach_movie` | 59 | 13.3s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 40 | `attach_movie_stop` | 3 | 13.2s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 41 | `bad_placeobject_clipaction` | 2 | 13.0s |  |
| 42 | `bad_swf_tag_past_eof` | 0 | 12.6s |  |
| 43 | `bitand` | 1058 | 15.5s |  |
| 44 | `bitmap_data_colortransform` | 0 | 12.8s |  |
| 45 | `bitmap_data_fillrect` | 0 | 12.7s |  |
| 46 | `bitmap_data_max_size_swf10` | 12 | 12.6s |  |
| 47 | `bitmap_data_max_size_swf9` | 10 | 12.6s |  |
| 48 | `bitmap_data_perlinnoise` | 0 | 13.4s |  |
| 49 | `bitmap_data_pixeldissolve_image` | 0 | 13.0s |  |
| 50 | `bitmapdata_applyfilter_colormatrix` | 0 | 12.9s |  |
| 51 | `bitor` | 1058 | 15.1s |  |
| 52 | `biturshift` | 14 | 12.6s |  |
| 53 | `biturshift_swf8` | 14 | 20.0s |  |
| 54 | `bitxor` | 1058 | 15.4s |  |
| 55 | `boxed_primitives` | 24 | 12.8s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 56 | `button_children` | 8 | 12.7s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_goto` | 4 | 12.8s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_order` | 2 | 12.7s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_properties_special_cases` | 22 | 12.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_v5` | 18 | 12.6s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_v6` | 18 | 12.6s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `call` | 63 | 12.8s | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) |
| 63 | `call_method_empty_name` | 1 | 12.7s |  |
| 64 | `capabilities_resolution` | 8 | 12.9s |  |
| 65 | `catch_references_registers` | 2 | 12.9s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 66 | `clip_constructors` | 8 | 12.8s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 67 | `clip_events` | 19 | 12.8s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 68 | `clone_sprite_types` | 24 | 12.5s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 69 | `closure_scope` | 7 | 12.6s | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 70 | `color` | 57 | 12.7s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 71 | `color_transform` | 48 | 12.7s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 72 | `conflicting_instance_names` | 23 | 12.6s |  |
| 73 | `constructor_function` | 2 | 12.5s |  |
| 74 | `context_menu` | 39 | 12.6s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 75 | `context_menu_item` | 41 | 12.5s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 76 | `create_empty_movie_clip` | 3 | 12.4s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 77 | `define_function2` | 8 | 12.5s |  |
| 78 | `define_function2_preload` | 13 | 12.6s |  |
| 79 | `define_function2_preload_order` | 4 | 12.8s |  |
| 80 | `define_function_case_sensitive` | 2 | 12.5s |  |
| 81 | `delete` | 3 | 12.5s |  |
| 82 | `display_object_properties` | 2 | 12.5s |  |
| 83 | `divide_swf4` | 107 | 12.5s |  |
| 84 | `do_init_action` | 3 | 12.5s |  |
| 85 | `do_init_action_child` | 12 | 12.6s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 86 | `duplicate_movie_clip` | 20 | 12.5s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 87 | `edittext_align` | 60 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 88 | `edittext_align_trailing_spaces_swf7` | 576 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 89 | `edittext_align_trailing_spaces_swf8` | 576 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 90 | `edittext_antialiastype` | 296 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 91 | `edittext_autosize` | 71 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 92 | `edittext_autosize_setter` | 20 | 13.9s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 93 | `edittext_default_format` | 221 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 94 | `edittext_default_format_font_style` | 335 | 13.4s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 95 | `edittext_font_size` | 45 | 13.3s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 96 | `edittext_hscroll` | 27 | 13.3s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 97 | `edittext_html_align_swf7` | 52 | 13.4s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 98 | `edittext_html_align_swf8` | 52 | 13.4s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 99 | `edittext_html_color` | 114 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_html_entity` | 4 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_html_roundtrip` | 17 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_html_swf7` | 5377 | 14.3s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_html_swf8` | 5377 | 14.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_leading` | 9 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_letter_spacing` | 15 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_margins` | 25 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_newline_stripping` | 64 | 17.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_programmatic_focus` | 12 | 12.5s | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_stylesheet` | 325 | 13.1s | [44](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_tag_indent` | 31 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_text_height_leading` | 20 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_underline` | 40 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_width_height` | 103 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `empty_movieclip_can_attach_movies` | 11 | 19.8s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 115 | `enumerate` | 64 | 12.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 116 | `equals` | 32 | 12.7s |  |
| 117 | `equals2_swf5` | 926 | 14.3s |  |
| 118 | `equals2_swf6` | 926 | 14.5s |  |
| 119 | `equals2_swf7` | 926 | 14.4s |  |
| 120 | `equals_swf4` | 665 | 13.6s |  |
| 121 | `equals_swf4_alt` | 32 | 12.7s |  |
| 122 | `equals_swf5` | 32 | 12.7s |  |
| 123 | `error` | 58 | 12.9s |  |
| 124 | `escape` | 14 | 12.8s |  |
| 125 | `execution_order1` | 5 | 12.8s |  |
| 126 | `execution_order2` | 7 | 12.7s |  |
| 127 | `execution_order3` | 4 | 13.2s |  |
| 128 | `execution_order4` | 12 | 12.9s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 129 | `export_assets` | 3 | 12.8s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 130 | `extends_chain` | 134 | 13.2s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 131 | `extends_native_type` | 11 | 13.5s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 132 | `focusrect_mouse_swf8` | 0 | 12.3s |  |
| 133 | `focusrect_mouse_swf9` | 0 | 13.1s |  |
| 134 | `focusrect_swf5` | 6 | 12.9s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 135 | `frame_size_translated_negative` | 21 | 12.8s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 136 | `frame_size_translated_positive` | 21 | 12.7s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 137 | `function_as_function` | 35 | 12.8s | [16](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 138 | `function_base_clip` | 8 | 12.8s |  |
| 139 | `function_base_clip_removed` | 25 | 12.9s |  |
| 140 | `function_suppress_and_preload` | 28 | 12.8s |  |
| 141 | `funky_function_calls` | 56 | 12.8s | [16](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 142 | `get_variable_in_scope` | 29 | 13.1s |  |
| 143 | `getproperty` | 28 | 13.1s |  |
| 144 | `getproperty_swf4` | 28 | 14.1s |  |
| 145 | `getproperty_swf5` | 28 | 12.8s |  |
| 146 | `global_array` | 3 | 12.9s |  |
| 147 | `global_is_bare` | 7 | 13.1s |  |
| 148 | `global_swf6_7_8` | 15 | 13.5s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 149 | `globals_swf5` | 304 | 13.1s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 150 | `globals_swf6` | 304 | 13.1s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 151 | `globals_swf7` | 304 | 13.1s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 152 | `globals_swf8` | 304 | 12.9s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 153 | `goto_advance1` | 6 | 12.7s |  |
| 154 | `goto_advance2` | 2 | 12.7s |  |
| 155 | `goto_both_ways1` | 3 | 12.6s |  |
| 156 | `goto_both_ways2` | 3 | 12.5s |  |
| 157 | `goto_execution_order` | 2 | 12.7s |  |
| 158 | `goto_execution_order2` | 2 | 12.7s |  |
| 159 | `goto_frame` | 12 | 12.9s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 160 | `goto_frame2` | 44 | 13.0s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 161 | `goto_frame_number` | 3 | 12.6s |  |
| 162 | `goto_label` | 17 | 12.7s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 163 | `goto_methods` | 40 | 12.6s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 164 | `goto_rewind1` | 1 | 12.5s |  |
| 165 | `goto_rewind2` | 3 | 12.4s |  |
| 166 | `goto_rewind3` | 2 | 12.4s |  |
| 167 | `greater_swf6` | 1175 | 14.2s |  |
| 168 | `greater_swf7` | 1175 | 14.4s |  |
| 169 | `greaterthan_swf5` | 1 | 12.4s |  |
| 170 | `greaterthan_swf8` | 1 | 12.4s |  |
| 171 | `has_own_property` | 32 | 12.5s |  |
| 172 | `hittest_lockroot` | 15 | 12.7s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 173 | `hittest_morph` | 70 | 12.5s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 174 | `hittest_winding_rule` | 12 | 12.6s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 175 | `infinite_recursion_function` | 4 | 12.5s | [20](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 176 | `infinite_recursion_function_in_setter` | 131 | 12.5s | [20](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 177 | `infinite_recursion_virtual_property` | 67 | 12.4s | [20](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 178 | `init_array_invalid` | 4 | 12.4s |  |
| 179 | `init_object_invalid` | 4 | 14.5s |  |
| 180 | `init_object_order` | 15 | 13.2s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 181 | `is_finite` | 49 | 12.7s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 182 | `is_finite_swf6` | 49 | 12.7s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 183 | `is_prototype_of` | 89 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 184 | `issue_1086` | 1 | 13.0s |  |
| 185 | `issue_1104` | 2 | 13.0s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 186 | `issue_1671` | 0 | 12.7s |  |
| 187 | `issue_1906` | 4 | 12.8s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 188 | `issue_2166` | 9 | 12.8s |  |
| 189 | `issue_3169` | 2 | 12.7s | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 190 | `issue_3446` | 1 | 12.6s |  |
| 191 | `issue_3522` | 2 | 12.7s |  |
| 192 | `issue_4377` | 2 | 12.7s |  |
| 193 | `issue_710` | 4 | 12.6s |  |
| 194 | `issue_768` | 3 | 12.9s | [21](ruffle-tests/_investigation/complete/issue_768.md) |
| 195 | `issue_9327` | 2 | 12.8s |  |
| 196 | `issue_9885` | 2 | 12.6s |  |
| 197 | `lessthan` | 41 | 12.7s |  |
| 198 | `lessthan2_swf5` | 1226 | 14.9s |  |
| 199 | `lessthan2_swf6` | 1226 | 14.8s |  |
| 200 | `lessthan2_swf7` | 1226 | 14.7s |  |
| 201 | `lessthan_swf4` | 902 | 13.8s |  |
| 202 | `lessthan_swf4_alt` | 41 | 12.8s |  |
| 203 | `lessthan_swf5` | 41 | 12.7s |  |
| 204 | `local_to_global` | 49 | 12.7s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 205 | `localconnection_properties` | 8 | 12.6s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 206 | `lock_root` | 1 | 12.6s |  |
| 207 | `logical_ops_swf4` | 90 | 12.6s |  |
| 208 | `logical_ops_swf8` | 108 | 12.6s |  |
| 209 | `looping` | 6 | 12.6s |  |
| 210 | `mask_reapply` | 0 | 12.6s |  |
| 211 | `mask_with_drawing` | 0 | 12.6s |  |
| 212 | `math_min_max` | 101 | 12.7s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 213 | `math_swf6` | 530 | 13.0s | [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 214 | `math_swf7` | 530 | 13.0s | [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 215 | `math_swf8` | 530 | 13.0s | [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 216 | `matrix` | 171 | 12.9s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 217 | `movieclip_begin_gradient_fill` | 0 | 13.3s |  |
| 218 | `movieclip_blend_mode_property` | 35 | 14.1s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 219 | `movieclip_create_text_field` | 90 | 13.6s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 220 | `movieclip_default_state` | 69 | 13.6s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 221 | `movieclip_depth_methods` | 98 | 13.7s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 222 | `movieclip_focusenabled` | 99 | 13.2s | [14](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 223 | `movieclip_get_instance_at_depth` | 28 | 13.3s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 224 | `movieclip_hittest` | 92 | 13.7s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 225 | `movieclip_in_removed_button` | 4 | 13.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 226 | `movieclip_init_object` | 5 | 13.3s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 227 | `movieclip_line_gradient_style` | 0 | 14.7s |  |
| 228 | `movieclip_name_from_timeline` | 13 | 12.7s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 229 | `movieclip_prototype_extension` | 5 | 12.7s |  |
| 230 | `mutable_this` | 18 | 12.8s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 231 | `named_shapes` | 14 | 12.9s |  |
| 232 | `nan_scale` | 9 | 13.0s |  |
| 233 | `native_double_construct` | 12 | 12.8s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 234 | `native_objects_swf7` | 84 | 13.2s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 235 | `native_objects_swf8` | 84 | 13.3s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 236 | `nested_textfields_in_buttons` | 0 | 12.6s |  |
| 237 | `new_method_wrap` | 4 | 12.9s |  |
| 238 | `new_object_enumerate` | 7 | 12.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 239 | `new_object_wrap` | 4 | 12.8s |  |
| 240 | `o` | 3 | 13.0s |  |
| 241 | `object_constructor` | 33 | 13.1s |  |
| 242 | `object_function` | 32 | 13.0s |  |
| 243 | `object_properties` | 31 | 13.0s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 244 | `object_prototypes` | 74 | 12.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 245 | `object_resolve` | 38 | 12.8s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 246 | `object_string_coerce_swf5` | 62 | 12.8s | [31](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 247 | `object_string_coerce_swf6` | 68 | 12.7s | [31](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 248 | `on_construct` | 25 | 12.8s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 249 | `parse_float` | 74 | 12.8s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [34](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 250 | `parse_int` | 64 | 12.9s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [34](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 251 | `path_string` | 322 | 13.2s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 252 | `place_and_lookup` | 30 | 13.1s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 253 | `placeobject_occupied_depth` | 6 | 12.9s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 254 | `point` | 175 | 13.2s | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 255 | `primitive_instanceof` | 37 | 12.8s |  |
| 256 | `primitive_type_globals` | 557 | 13.4s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 257 | `printjob_props_swf5` | 45 | 13.0s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 258 | `printjob_props_swf6` | 45 | 13.0s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 259 | `printjob_props_swf7` | 45 | 13.0s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 260 | `property_invalid_base_clip` | 36 | 13.1s |  |
| 261 | `prototype_delete` | 12 | 13.1s |  |
| 262 | `prototype_enumerate` | 5 | 13.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 263 | `prototype_properties` | 17 | 13.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 264 | `rectangle` | 745 | 13.5s | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 265 | `recursive_prototypes` | 0 | 12.7s |  |
| 266 | `register_class_return_value` | 16 | 12.7s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 267 | `register_class_with_sound` | 11 | 12.8s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [39](ruffle-tests/_investigation/incomplete/SOUND_CLASS_PLAN.md) |
| 268 | `register_globals_across_frames` | 15 | 12.9s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 269 | `register_underflow` | 26 | 12.9s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 270 | `remove_movie_clip` | 29 | 12.9s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 271 | `rewind_depth` | 30 | 12.8s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 272 | `sandbox_type_local_file` | 1 | 12.7s |  |
| 273 | `sandbox_type_local_network` | 1 | 12.8s |  |
| 274 | `selection` | 454 | 12.9s | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 275 | `set_interval` | 27 | 13.0s | [52](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 276 | `set_variable_scope` | 58 | 12.8s |  |
| 277 | `single_frame` | 1 | 12.8s |  |
| 278 | `slash_syntax` | 14 | 12.9s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 279 | `sound_props_swf5` | 68 | 12.5s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 280 | `sound_props_swf6` | 68 | 12.5s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 281 | `sound_start_load` | 0 | 12.5s |  |
| 282 | `stage_display_state` | 16 | 12.5s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 283 | `stage_object_children` | 83 | 12.5s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 284 | `stage_object_enumerate` | 4 | 12.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 285 | `stage_object_properties` | 241 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 286 | `stage_object_properties_get_var` | 5 | 12.4s |  |
| 287 | `stage_object_properties_swf6` | 231 | 12.8s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 288 | `stage_property_representation` | 586 | 12.4s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 289 | `stage_scale_mode` | 39 | 12.4s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 290 | `strictequals_swf6` | 902 | 13.9s |  |
| 291 | `strictly_equals` | 7 | 12.5s |  |
| 292 | `string_methods` | 285 | 13.0s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 293 | `string_methods_negative_args` | 240 | 12.6s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 294 | `string_methods_swfv5` | 275 | 12.9s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 295 | `string_ops_swf6` | 95 | 12.5s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 296 | `string_paths_basic` | 4 | 12.5s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 297 | `string_paths_eval2` | 7 | 13.2s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 298 | `string_paths_hidden` | 54 | 12.8s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 299 | `string_paths_other` | 36 | 12.9s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 300 | `string_paths_unload` | 1 | 13.0s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 301 | `string_paths_variable_alias` | 4 | 12.9s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 302 | `string_paths_variable_scopes` | 5 | 12.9s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 303 | `stylesheet` | 283 | 13.8s |  |
| 304 | `stylesheet_transform` | 750 | 14.1s |  |
| 305 | `super_edge_cases` | 39 | 13.7s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 306 | `swf4_actions_bool` | 96 | 13.4s |  |
| 307 | `swf4_actions_coercion_order` | 158 | 12.8s | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 308 | `swf4_bool` | 4 | 12.7s |  |
| 309 | `swf4_function_calls` | 7 | 12.7s |  |
| 310 | `swf5_encoding` | 3 | 12.6s |  |
| 311 | `swf5_no_closure` | 19 | 15.4s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 312 | `swf6_case_insensitive` | 42 | 13.0s | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 313 | `swf6_string_as_bool` | 15 | 12.7s | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 314 | `swf7_case_sensitive` | 44 | 12.7s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 315 | `tab_ordering_properties_tab_index_edge_case` | 4 | 12.6s |  |
| 316 | `target_clip_swf5` | 2 | 12.5s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 317 | `target_clip_swf6` | 2 | 12.5s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 318 | `target_path` | 14 | 12.6s |  |
| 319 | `tell_target` | 37 | 12.5s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 320 | `tell_target_invalid` | 6 | 12.5s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 321 | `tell_target_invalid_swf6` | 5 | 12.7s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 322 | `text_format` | 1146 | 12.9s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 323 | `text_format_display` | 21 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 324 | `text_format_font_max_length` | 2 | 12.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 325 | `text_format_rounding_swf7` | 840 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 326 | `text_format_rounding_swf8` | 840 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 327 | `textfield_background_color` | 11 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 328 | `textfield_border_color` | 11 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 329 | `textfield_cache_as_bitmap` | 1 | 12.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 330 | `textfield_maxchars` | 3 | 14.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 331 | `textfield_properties` | 44 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 332 | `textfield_props_swf5` | 175 | 13.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 333 | `textfield_props_swf6` | 210 | 13.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 334 | `textfield_props_swf7` | 210 | 13.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 335 | `textfield_props_swf8` | 210 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 336 | `textfield_text` | 7 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 337 | `textfield_variable` | 81 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 338 | `textsnapshot_available_text` | 20 | 13.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 339 | `textsnapshot_findtext` | 44 | 13.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 340 | `textsnapshot_gettext` | 55 | 13.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 341 | `textsnapshot_props_swf5` | 56 | 13.4s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 342 | `textsnapshot_props_swf6` | 56 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 343 | `textsnapshot_text_order` | 1 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 344 | `this_scoping` | 52 | 13.5s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 345 | `this_swf5` | 41 | 13.7s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 346 | `this_swf6` | 41 | 13.8s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 347 | `this_swf7` | 41 | 13.6s | [51](ruffle-tests/_investigation/complete/this_swf7.md) |
| 348 | `timeline_function_def` | 7 | 13.1s |  |
| 349 | `trace` | 8 | 13.3s |  |
| 350 | `transform` | 70 | 13.1s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 351 | `try_catch_finally` | 118 | 13.1s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 352 | `try_finally_simple` | 16 | 12.9s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 353 | `typeof` | 22 | 12.9s |  |
| 354 | `typeof_globals` | 7 | 12.9s |  |
| 355 | `uncaught_exception` | 1 | 13.0s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 356 | `uncaught_exception_bubbled` | 1 | 12.9s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 357 | `undefined_to_string_swf6` | 4 | 12.9s |  |
| 358 | `unescape` | 43 | 13.0s |  |
| 359 | `unload` | 52 | 13.2s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 360 | `unload_clip_event` | 4 | 13.0s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 361 | `use_hand_cursor` | 8 | 13.0s |  |
| 362 | `variable_args` | 5 | 13.2s |  |
| 363 | `waitforframe` | 7 | 13.1s |  |
| 364 | `waitforframe2` | 16 | 14.3s |  |
| 365 | `watch` | 117 | 12.8s | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 366 | `watch_textfield` | 12 | 12.5s | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 367 | `watch_virtual_property_proto` | 2 | 12.6s | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 368 | `with` | 49 | 12.6s | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 369 | `with_return` | 2 | 12.6s |  |
| 370 | `with_variable_scopes` | 43 | 12.8s | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 371 | `xml` | 15 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 372 | `xml_append_child` | 28 | 12.6s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 373 | `xml_append_child_with_parent` | 20 | 12.6s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 374 | `xml_cdata` | 11 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 375 | `xml_child_nodes_edge_cases` | 4 | 12.8s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 376 | `xml_clone_expandos` | 19 | 12.9s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 377 | `xml_first_last_child` | 8 | 12.6s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 378 | `xml_has_child_nodes` | 3 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 379 | `xml_idmap` | 21 | 12.8s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 380 | `xml_ignore_comments` | 21 | 12.8s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 381 | `xml_ignore_white` | 34 | 14.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 382 | `xml_insert_before` | 20 | 13.1s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 383 | `xml_inspect_createmethods` | 15 | 12.9s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 384 | `xml_inspect_doctype` | 7 | 12.9s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 385 | `xml_inspect_parsexml` | 62 | 12.9s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 386 | `xml_inspect_xmldecl` | 7 | 13.1s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 387 | `xml_namespaces` | 203 | 12.9s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 388 | `xml_parent_and_child` | 5 | 12.9s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 389 | `xml_remove_node` | 22 | 12.8s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 390 | `xml_reparenting` | 14 | 13.0s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 391 | `xml_siblings` | 10 | 12.9s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 392 | `xml_to_string` | 13 | 13.3s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 393 | `xml_to_string_comment` | 1 | 13.1s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 394 | `xml_unescaping` | 23 | 13.2s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 395 | `xmlnode_proto` | 1 | 13.3s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**24 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `string_coercion` | 99.1% | 116 | 117 | 1 | [42](ruffle-tests/_investigation/complete/string_coercion.md) |
| 2 | `sound` | 99.0% | 622 | 628 | 6 | [39](ruffle-tests/_investigation/incomplete/SOUND_CLASS_PLAN.md) |
| 3 | `edittext_html_condensewhite_swf7` | 99.0% | 308 | 311 | 3 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `function_base_clip_readded` | 90.9% | 10 | 11 | 1 |  |
| 9 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 10 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `edittext_html_condensewhite_swf8` | 80.1% | 249 | 311 | 62 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 12 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 13 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 14 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 15 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 16 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 17 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 18 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 19 | `register_class` | 57.6% | 38 | 66 | 28 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 20 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 21 | `gettextextent` | 55.4% | 31 | 56 | 25 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 22 | `device_font_spacing` | 50.5% | 46 | 91 | 45 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 23 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 24 | `issue_2030` | 50.0% | 2 | 4 | 2 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

**3 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `netstream_play_flv_screen` | 28.5s |  |
| 2 | `string_paths_timer` | 14.9s | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 3 | `timer_run_actions` | 16.6s | [52](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 37.7s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 37.6s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 23.4s | [52](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**75 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `string_coercion` | 99.1% | 116/117 | 117 | 117 | [42](ruffle-tests/_investigation/complete/string_coercion.md) |
| 2 | `sound` | 99.0% | 622/628 | 628 | 628 | [39](ruffle-tests/_investigation/incomplete/SOUND_CLASS_PLAN.md) |
| 3 | `edittext_html_condensewhite_swf7` | 99.0% | 308/311 | 311 | 311 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `function_base_clip_readded` | 90.9% | 10/11 | 11 | 11 |  |
| 9 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 10 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `edittext_html_condensewhite_swf8` | 80.1% | 249/311 | 311 | 311 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 12 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 13 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 14 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 15 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 16 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 17 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 18 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 19 | `register_class` | 57.6% | 38/66 | 47 | 66 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 20 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 21 | `gettextextent` | 55.4% | 31/56 | 56 | 56 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 22 | `device_font_spacing` | 50.5% | 46/91 | 91 | 91 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 23 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 24 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 25 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 26 | `define_local_with_paths` | 40.7% | 22/54 | 34 | 54 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 27 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 28 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 29 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 30 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 31 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 32 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 33 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 34 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 35 | `removed_target_clip_scope` | 29.7% | 11/37 | 37 | 35 | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 36 | `default_names` | 28.8% | 15/52 | 48 | 52 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 37 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 38 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 39 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 40 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 41 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 42 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 43 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 44 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 45 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 | [54](ruffle-tests/_investigation/incomplete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 46 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 47 | `coerce_to_object_monkeypatch` | 12.4% | 16/129 | 112 | 129 | [54](ruffle-tests/_investigation/incomplete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 48 | `define_local` | 7.4% | 2/27 | 23 | 27 | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 49 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 50 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 51 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 52 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 53 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 54 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 55 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 56 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 57 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 58 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [16](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 59 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 60 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 61 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 62 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 63 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 64 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 65 | `geturl` | 0.0% | 0/7 | 0 | 7 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 66 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 67 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 68 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 69 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 70 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 71 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 72 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 73 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 74 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 75 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

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
| 16 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
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
