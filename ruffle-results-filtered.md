# Ruffle Test Results (Filtered)

**Date**: 2026-03-06 02:28 UTC

**Git SHA**: `b7965a8fc0`

**Run Duration**: 139m 4s

**Filtered**: 145 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 474 |
| Passing | **393** (82.9%) |
| Failing | 81 |
| Total expected lines | 71145 |
| Matching lines | 57688 (81.1%) |
| Mismatched lines | 13457 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 76 | 93.8% |
| Runtime Error | 2 | 2.5% |
| Segfault | 2 | 2.5% |
| Compile Fail | 1 | 1.2% |

## Passing Tests

**393 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 13.0s |  |
| 2 | `action_to_integer` | 28 | 12.6s |  |
| 3 | `add` | 28 | 12.6s |  |
| 4 | `add2` | 354 | 12.7s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 12.5s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 12.4s |  |
| 7 | `add_swf5` | 28 | 12.6s |  |
| 8 | `arguments` | 127 | 12.8s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 12.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 12.7s |  |
| 11 | `array_constructor` | 30 | 12.6s |  |
| 12 | `array_enumerate` | 4 | 12.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 12.7s |  |
| 14 | `array_properties` | 36 | 12.6s |  |
| 15 | `array_prototyping` | 12 | 12.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 12.7s |  |
| 17 | `array_sort_random` | 443 | 12.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 12.8s |  |
| 19 | `array_trivial` | 209 | 12.7s |  |
| 20 | `as1_constructor_v6` | 35 | 12.6s |  |
| 21 | `as1_constructor_v7` | 35 | 12.6s |  |
| 22 | `as2_oop` | 13 | 12.8s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 12.8s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 12.8s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 12.9s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster` | 41 | 12.7s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 12.6s |  |
| 28 | `as_broadcaster_undef` | 89 | 12.7s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 29 | `as_set_prop_flags` | 79 | 12.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version` | 31 | 12.6s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version_swf5` | 1 | 12.6s |  |
| 32 | `as_set_prop_flags_version_swf6` | 1 | 12.6s |  |
| 33 | `as_set_prop_flags_version_swf7` | 1 | 12.6s |  |
| 34 | `as_set_prop_flags_version_swf8` | 1 | 12.7s |  |
| 35 | `as_set_prop_flags_version_swf9` | 1 | 12.7s |  |
| 36 | `as_transformed_flag` | 20 | 12.6s |  |
| 37 | `asnative` | 34 | 12.5s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 38 | `asnew` | 34 | 12.6s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `attach_movie` | 59 | 12.6s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 40 | `attach_movie_stop` | 3 | 12.6s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 41 | `bad_placeobject_clipaction` | 2 | 12.6s |  |
| 42 | `bad_swf_tag_past_eof` | 0 | 12.5s |  |
| 43 | `bitand` | 1058 | 15.0s |  |
| 44 | `bitmap_data_colortransform` | 0 | 12.8s |  |
| 45 | `bitmap_data_fillrect` | 0 | 12.8s |  |
| 46 | `bitmap_data_max_size_swf10` | 12 | 12.6s |  |
| 47 | `bitmap_data_max_size_swf9` | 10 | 12.6s |  |
| 48 | `bitmap_data_perlinnoise` | 0 | 13.3s |  |
| 49 | `bitmap_data_pixeldissolve_image` | 0 | 12.9s |  |
| 50 | `bitmapdata_applyfilter_colormatrix` | 0 | 12.8s |  |
| 51 | `bitor` | 1058 | 15.0s |  |
| 52 | `biturshift` | 14 | 13.5s |  |
| 53 | `biturshift_swf8` | 14 | 12.9s |  |
| 54 | `bitxor` | 1058 | 15.4s |  |
| 55 | `boxed_primitives` | 24 | 13.0s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 56 | `button_children` | 8 | 12.8s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_goto` | 4 | 12.7s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_order` | 2 | 12.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_properties_special_cases` | 22 | 13.0s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_v5` | 18 | 12.8s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_v6` | 18 | 12.7s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `call` | 63 | 13.0s | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) |
| 63 | `call_method_empty_name` | 1 | 12.8s |  |
| 64 | `capabilities_resolution` | 8 | 12.8s |  |
| 65 | `catch_references_registers` | 2 | 12.7s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 66 | `clip_constructors` | 8 | 12.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 67 | `clip_events` | 19 | 13.0s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 68 | `clone_sprite_types` | 24 | 12.9s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 69 | `closure_scope` | 7 | 12.9s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 70 | `color` | 57 | 13.1s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 71 | `color_transform` | 48 | 13.0s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 72 | `conflicting_instance_names` | 23 | 12.9s |  |
| 73 | `constructor_function` | 2 | 12.7s |  |
| 74 | `context_menu` | 39 | 12.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 75 | `context_menu_item` | 41 | 12.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 76 | `create_empty_movie_clip` | 3 | 12.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 77 | `define_function2` | 8 | 12.7s |  |
| 78 | `define_function2_preload` | 13 | 12.6s |  |
| 79 | `define_function2_preload_order` | 4 | 12.8s |  |
| 80 | `define_function_case_sensitive` | 2 | 12.8s |  |
| 81 | `delete` | 3 | 12.8s |  |
| 82 | `device_font_spacing` | 91 | 13.0s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 83 | `display_object_properties` | 2 | 12.7s |  |
| 84 | `divide_swf4` | 107 | 12.7s |  |
| 85 | `do_init_action` | 3 | 12.7s |  |
| 86 | `do_init_action_child` | 12 | 12.8s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 87 | `duplicate_movie_clip` | 20 | 12.8s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 88 | `edittext_antialiastype` | 296 | 15.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 89 | `edittext_autosize_setter` | 20 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 90 | `edittext_default_format` | 221 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 91 | `edittext_default_format_font_style` | 335 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 92 | `edittext_hscroll` | 27 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 93 | `edittext_html_align_swf7` | 52 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 94 | `edittext_html_align_swf8` | 52 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 95 | `edittext_html_color` | 114 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 96 | `edittext_html_entity` | 4 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 97 | `edittext_html_roundtrip` | 17 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 98 | `edittext_html_swf7` | 5377 | 13.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 99 | `edittext_html_swf8` | 5377 | 13.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_newline_stripping` | 64 | 17.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_programmatic_focus` | 12 | 12.8s | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_stylesheet` | 325 | 13.4s | [45](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_tag_indent` | 31 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_text_height_leading` | 20 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_width_height` | 103 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `empty_movieclip_can_attach_movies` | 11 | 12.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 107 | `enumerate` | 64 | 12.9s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 108 | `equals` | 32 | 12.8s |  |
| 109 | `equals2_swf5` | 926 | 14.6s |  |
| 110 | `equals2_swf6` | 926 | 14.5s |  |
| 111 | `equals2_swf7` | 926 | 14.6s |  |
| 112 | `equals_swf4` | 665 | 13.6s |  |
| 113 | `equals_swf4_alt` | 32 | 12.9s |  |
| 114 | `equals_swf5` | 32 | 12.9s |  |
| 115 | `error` | 58 | 12.9s |  |
| 116 | `escape` | 14 | 12.7s |  |
| 117 | `execution_order1` | 5 | 13.0s |  |
| 118 | `execution_order2` | 7 | 12.9s |  |
| 119 | `execution_order3` | 4 | 12.8s |  |
| 120 | `execution_order4` | 12 | 13.0s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 121 | `export_assets` | 3 | 12.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 122 | `extends_chain` | 134 | 13.3s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 123 | `extends_native_type` | 11 | 12.9s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 124 | `focusrect_mouse_swf8` | 0 | 15.4s |  |
| 125 | `focusrect_mouse_swf9` | 0 | 14.3s |  |
| 126 | `focusrect_swf5` | 6 | 15.2s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 127 | `frame_size_translated_negative` | 21 | 14.5s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 128 | `frame_size_translated_positive` | 21 | 15.0s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 129 | `function_as_function` | 35 | 14.9s | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 130 | `function_base_clip` | 8 | 15.5s |  |
| 131 | `function_base_clip_removed` | 25 | 15.2s |  |
| 132 | `function_suppress_and_preload` | 28 | 14.2s |  |
| 133 | `get_bytes_total` | 4 | 13.7s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 134 | `get_variable_in_scope` | 29 | 15.7s |  |
| 135 | `getproperty` | 28 | 14.5s |  |
| 136 | `getproperty_swf4` | 28 | 15.5s |  |
| 137 | `getproperty_swf5` | 28 | 13.9s |  |
| 138 | `gettextextent` | 56 | 15.0s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 139 | `global_array` | 3 | 15.4s |  |
| 140 | `global_is_bare` | 7 | 15.4s |  |
| 141 | `global_swf6_7_8` | 15 | 14.7s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 142 | `globals_swf5` | 304 | 16.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 143 | `globals_swf6` | 304 | 14.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 144 | `globals_swf7` | 304 | 15.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 145 | `globals_swf8` | 304 | 14.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 146 | `goto_advance1` | 6 | 14.9s |  |
| 147 | `goto_advance2` | 2 | 14.9s |  |
| 148 | `goto_both_ways1` | 3 | 14.4s |  |
| 149 | `goto_both_ways2` | 3 | 12.9s |  |
| 150 | `goto_execution_order` | 2 | 12.9s |  |
| 151 | `goto_execution_order2` | 2 | 12.9s |  |
| 152 | `goto_frame` | 12 | 13.0s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 153 | `goto_frame2` | 44 | 13.3s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 154 | `goto_frame_number` | 3 | 12.8s |  |
| 155 | `goto_label` | 17 | 13.0s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 156 | `goto_methods` | 40 | 13.0s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 157 | `goto_rewind1` | 1 | 12.9s |  |
| 158 | `goto_rewind2` | 3 | 12.9s |  |
| 159 | `goto_rewind3` | 2 | 12.8s |  |
| 160 | `greater_swf6` | 1175 | 14.7s |  |
| 161 | `greater_swf7` | 1175 | 14.7s |  |
| 162 | `greaterthan_swf5` | 1 | 12.7s |  |
| 163 | `greaterthan_swf8` | 1 | 12.7s |  |
| 164 | `has_own_property` | 32 | 12.8s |  |
| 165 | `hittest_lockroot` | 15 | 13.0s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 166 | `hittest_morph` | 70 | 12.9s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 167 | `hittest_winding_rule` | 12 | 12.9s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 168 | `infinite_recursion_function` | 4 | 12.7s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 169 | `infinite_recursion_function_in_setter` | 131 | 12.8s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 170 | `infinite_recursion_virtual_property` | 67 | 12.9s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 171 | `init_array_invalid` | 4 | 12.8s |  |
| 172 | `init_object_invalid` | 4 | 12.8s |  |
| 173 | `init_object_order` | 15 | 12.9s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 174 | `is_finite` | 49 | 12.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 175 | `is_finite_swf6` | 49 | 12.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 176 | `is_prototype_of` | 89 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 177 | `issue_1086` | 1 | 12.8s |  |
| 178 | `issue_1104` | 2 | 12.9s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 179 | `issue_1671` | 0 | 12.8s |  |
| 180 | `issue_1906` | 4 | 12.8s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 181 | `issue_2166` | 9 | 12.7s |  |
| 182 | `issue_3169` | 2 | 12.8s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 183 | `issue_3446` | 1 | 12.7s |  |
| 184 | `issue_3522` | 2 | 12.9s |  |
| 185 | `issue_4377` | 2 | 12.8s |  |
| 186 | `issue_710` | 4 | 12.8s |  |
| 187 | `issue_768` | 3 | 12.9s | [22](ruffle-tests/_investigation/complete/issue_768.md) |
| 188 | `issue_9327` | 2 | 12.9s |  |
| 189 | `issue_9885` | 2 | 12.8s |  |
| 190 | `lessthan` | 41 | 12.7s |  |
| 191 | `lessthan2_swf5` | 1226 | 14.8s |  |
| 192 | `lessthan2_swf6` | 1226 | 14.8s |  |
| 193 | `lessthan2_swf7` | 1226 | 14.8s |  |
| 194 | `lessthan_swf4` | 902 | 13.9s |  |
| 195 | `lessthan_swf4_alt` | 41 | 12.8s |  |
| 196 | `lessthan_swf5` | 41 | 12.8s |  |
| 197 | `local_to_global` | 49 | 12.9s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 198 | `localconnection_properties` | 8 | 12.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 199 | `lock_root` | 1 | 12.8s |  |
| 200 | `logical_ops_swf4` | 90 | 12.8s |  |
| 201 | `logical_ops_swf8` | 108 | 13.0s |  |
| 202 | `looping` | 6 | 12.9s |  |
| 203 | `mask_reapply` | 0 | 12.9s |  |
| 204 | `mask_with_drawing` | 0 | 12.8s |  |
| 205 | `math_min_max` | 101 | 12.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 206 | `math_swf6` | 530 | 13.3s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 207 | `math_swf7` | 530 | 13.3s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 208 | `math_swf8` | 530 | 13.1s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 209 | `matrix` | 171 | 13.2s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 210 | `movieclip_begin_gradient_fill` | 0 | 13.4s |  |
| 211 | `movieclip_blend_mode_property` | 35 | 13.0s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 212 | `movieclip_create_text_field` | 90 | 12.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 213 | `movieclip_default_state` | 69 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 214 | `movieclip_depth_methods` | 98 | 13.0s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 215 | `movieclip_focusenabled` | 99 | 12.9s | [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 216 | `movieclip_get_instance_at_depth` | 28 | 12.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 217 | `movieclip_hittest` | 92 | 13.0s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 218 | `movieclip_in_removed_button` | 4 | 12.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 219 | `movieclip_init_object` | 5 | 12.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 220 | `movieclip_line_gradient_style` | 0 | 13.2s |  |
| 221 | `movieclip_name_from_timeline` | 13 | 12.7s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 222 | `movieclip_prototype_extension` | 5 | 12.7s |  |
| 223 | `mutable_this` | 18 | 12.8s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 224 | `named_shapes` | 14 | 13.0s |  |
| 225 | `nan_scale` | 9 | 12.9s |  |
| 226 | `native_double_construct` | 12 | 12.9s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 227 | `native_objects_swf7` | 84 | 13.3s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 228 | `native_objects_swf8` | 84 | 13.2s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 229 | `nested_textfields_in_buttons` | 0 | 12.8s |  |
| 230 | `new_method_wrap` | 4 | 12.7s |  |
| 231 | `new_object_enumerate` | 7 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 232 | `new_object_wrap` | 4 | 12.7s |  |
| 233 | `o` | 3 | 12.7s |  |
| 234 | `object_constructor` | 33 | 12.7s |  |
| 235 | `object_function` | 32 | 12.7s |  |
| 236 | `object_properties` | 31 | 12.9s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 237 | `object_prototypes` | 74 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 238 | `object_resolve` | 38 | 12.9s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 239 | `object_string_coerce_swf5` | 62 | 12.7s | [32](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 240 | `object_string_coerce_swf6` | 68 | 12.8s | [32](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 241 | `on_construct` | 25 | 12.9s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 242 | `parse_float` | 74 | 12.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 243 | `parse_int` | 64 | 13.0s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 244 | `path_string` | 322 | 12.9s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 245 | `place_and_lookup` | 30 | 12.7s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 246 | `placeobject_occupied_depth` | 6 | 12.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 247 | `point` | 175 | 13.1s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 248 | `primitive_instanceof` | 37 | 12.7s |  |
| 249 | `primitive_type_globals` | 557 | 13.1s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 250 | `printjob_props_swf5` | 45 | 12.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 251 | `printjob_props_swf6` | 45 | 12.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 252 | `printjob_props_swf7` | 45 | 12.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 253 | `property_invalid_base_clip` | 36 | 12.8s |  |
| 254 | `prototype_delete` | 12 | 12.8s |  |
| 255 | `prototype_enumerate` | 5 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 256 | `prototype_properties` | 17 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 257 | `rectangle` | 745 | 13.5s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 258 | `recursive_prototypes` | 0 | 12.7s |  |
| 259 | `register_class_return_value` | 16 | 12.9s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 260 | `register_class_with_sound` | 11 | 12.9s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [40](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 261 | `register_globals_across_frames` | 15 | 12.9s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 262 | `register_underflow` | 26 | 12.8s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 263 | `remove_movie_clip` | 29 | 12.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 264 | `rewind_depth` | 30 | 12.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 265 | `sandbox_type_local_file` | 1 | 12.9s |  |
| 266 | `sandbox_type_local_network` | 1 | 12.8s |  |
| 267 | `selection` | 454 | 12.9s | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 268 | `set_interval` | 27 | 12.9s | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 269 | `set_variable_scope` | 58 | 12.9s |  |
| 270 | `single_frame` | 1 | 12.7s |  |
| 271 | `slash_syntax` | 14 | 12.7s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 272 | `sound` | 628 | 13.0s | [40](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 273 | `sound_props_swf5` | 68 | 12.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 274 | `sound_props_swf6` | 68 | 12.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 275 | `sound_start_load` | 0 | 12.8s |  |
| 276 | `stage_display_state` | 16 | 12.8s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 277 | `stage_object_children` | 83 | 12.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 278 | `stage_object_enumerate` | 4 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 279 | `stage_object_properties` | 241 | 13.1s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 280 | `stage_object_properties_get_var` | 5 | 12.7s |  |
| 281 | `stage_object_properties_swf6` | 231 | 13.1s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 282 | `stage_property_representation` | 586 | 12.8s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 283 | `stage_scale_mode` | 39 | 12.8s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 284 | `strictequals_swf6` | 902 | 14.2s |  |
| 285 | `strictly_equals` | 7 | 12.8s |  |
| 286 | `string_coercion` | 117 | 13.0s | [43](ruffle-tests/_investigation/complete/string_coercion.md) |
| 287 | `string_methods` | 285 | 13.3s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 288 | `string_methods_negative_args` | 240 | 12.9s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 289 | `string_methods_swfv5` | 275 | 13.2s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 290 | `string_ops_swf6` | 95 | 12.8s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 291 | `string_paths_basic` | 4 | 12.7s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 292 | `string_paths_eval2` | 7 | 12.8s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 293 | `string_paths_hidden` | 54 | 12.8s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 294 | `string_paths_other` | 36 | 12.8s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 295 | `string_paths_unload` | 1 | 12.9s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 296 | `string_paths_variable_alias` | 4 | 12.8s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 297 | `string_paths_variable_scopes` | 5 | 12.8s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 298 | `stylesheet` | 283 | 13.5s |  |
| 299 | `stylesheet_transform` | 750 | 13.4s |  |
| 300 | `super_edge_cases` | 39 | 12.9s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 301 | `swf4_actions_bool` | 96 | 12.8s |  |
| 302 | `swf4_actions_coercion_order` | 158 | 12.9s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 303 | `swf4_bool` | 4 | 12.7s |  |
| 304 | `swf4_function_calls` | 7 | 13.6s |  |
| 305 | `swf5_encoding` | 3 | 13.4s |  |
| 306 | `swf5_global_funcs` | 232 | 13.7s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 307 | `swf5_no_closure` | 19 | 13.6s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 308 | `swf6_case_insensitive` | 42 | 13.4s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 309 | `swf6_global_funcs` | 232 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 310 | `swf6_string_as_bool` | 15 | 13.4s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 311 | `swf7_case_sensitive` | 44 | 13.6s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 312 | `swf7_global_funcs` | 232 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 313 | `tab_ordering_properties_tab_index_edge_case` | 4 | 13.4s |  |
| 314 | `target_clip_swf5` | 2 | 13.4s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 315 | `target_clip_swf6` | 2 | 13.5s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 316 | `target_path` | 14 | 13.5s |  |
| 317 | `tell_target` | 37 | 13.6s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 318 | `tell_target_invalid` | 6 | 13.5s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 319 | `tell_target_invalid_swf6` | 5 | 13.6s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 320 | `text_format` | 1146 | 13.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 321 | `text_format_display` | 21 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 322 | `text_format_font_max_length` | 2 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 323 | `text_format_rounding_swf7` | 840 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 324 | `text_format_rounding_swf8` | 840 | 13.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 325 | `textfield_background_color` | 11 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 326 | `textfield_border_color` | 11 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 327 | `textfield_cache_as_bitmap` | 1 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 328 | `textfield_maxchars` | 3 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 329 | `textfield_properties` | 44 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 330 | `textfield_props_swf5` | 175 | 13.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 331 | `textfield_props_swf6` | 210 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 332 | `textfield_props_swf7` | 210 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 333 | `textfield_props_swf8` | 210 | 13.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 334 | `textfield_text` | 7 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 335 | `textfield_variable` | 81 | 13.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 336 | `textsnapshot_available_text` | 20 | 13.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 337 | `textsnapshot_findtext` | 44 | 13.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 338 | `textsnapshot_gettext` | 55 | 13.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 339 | `textsnapshot_props_swf5` | 56 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 340 | `textsnapshot_props_swf6` | 56 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 341 | `textsnapshot_text_order` | 1 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 342 | `this_scoping` | 52 | 13.6s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 343 | `this_swf5` | 41 | 13.5s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 344 | `this_swf6` | 41 | 13.4s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 345 | `this_swf7` | 41 | 13.7s | [52](ruffle-tests/_investigation/complete/this_swf7.md) |
| 346 | `timeline_function_def` | 7 | 13.7s |  |
| 347 | `trace` | 8 | 13.5s |  |
| 348 | `transform` | 70 | 13.4s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 349 | `try_catch_finally` | 118 | 13.4s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 350 | `try_finally_simple` | 16 | 13.2s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 351 | `typeof` | 22 | 13.4s |  |
| 352 | `typeof_globals` | 7 | 13.3s |  |
| 353 | `uncaught_exception` | 1 | 13.3s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 354 | `uncaught_exception_bubbled` | 1 | 13.4s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 355 | `undefined_to_string_swf6` | 4 | 13.3s |  |
| 356 | `unescape` | 43 | 13.5s |  |
| 357 | `unload` | 52 | 13.6s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 358 | `unload_clip_event` | 4 | 13.4s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 359 | `use_hand_cursor` | 8 | 13.4s |  |
| 360 | `variable_args` | 5 | 13.6s |  |
| 361 | `waitforframe` | 7 | 13.4s |  |
| 362 | `waitforframe2` | 16 | 13.3s |  |
| 363 | `watch` | 117 | 13.7s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 364 | `watch_textfield` | 12 | 13.4s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 365 | `watch_virtual_property_proto` | 2 | 13.6s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 366 | `with` | 49 | 13.5s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 367 | `with_return` | 2 | 13.5s |  |
| 368 | `with_variable_scopes` | 43 | 13.6s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 369 | `xml` | 15 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 370 | `xml_append_child` | 28 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 371 | `xml_append_child_with_parent` | 20 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 372 | `xml_cdata` | 11 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 373 | `xml_child_nodes_edge_cases` | 4 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 374 | `xml_clone_expandos` | 19 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 375 | `xml_first_last_child` | 8 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 376 | `xml_has_child_nodes` | 3 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 377 | `xml_idmap` | 21 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 378 | `xml_ignore_comments` | 21 | 13.5s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 379 | `xml_ignore_white` | 34 | 13.5s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 380 | `xml_insert_before` | 20 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 381 | `xml_inspect_createmethods` | 15 | 13.6s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 382 | `xml_inspect_doctype` | 7 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 383 | `xml_inspect_parsexml` | 62 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 384 | `xml_inspect_xmldecl` | 7 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 385 | `xml_namespaces` | 203 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 386 | `xml_parent_and_child` | 5 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 387 | `xml_remove_node` | 22 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 388 | `xml_reparenting` | 14 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 389 | `xml_siblings` | 10 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 390 | `xml_to_string` | 13 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 391 | `xml_to_string_comment` | 1 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 392 | `xml_unescaping` | 23 | 13.5s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 393 | `xmlnode_proto` | 1 | 13.5s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**31 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `edittext_html_condensewhite_swf7` | 99.0% | 308 | 311 | 3 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `instanceof_coercions` | 97.7% | 86 | 88 | 2 | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 4 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 5 | `funky_function_calls` | 96.4% | 54 | 56 | 2 | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 6 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `define_local_with_paths` | 94.4% | 51 | 54 | 3 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 8 | `edittext_letter_spacing` | 93.3% | 14 | 15 | 1 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `edittext_html_condensewhite_swf8` | 92.6% | 288 | 311 | 23 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 10 | `function_base_clip_readded` | 90.9% | 10 | 11 | 1 |  |
| 11 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 12 | `edittext_underline` | 90.0% | 36 | 40 | 4 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 13 | `edittext_font_size` | 88.9% | 40 | 45 | 5 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 14 | `edittext_align` | 86.7% | 52 | 60 | 8 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 15 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 16 | `edittext_margins` | 80.0% | 20 | 25 | 5 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 17 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 18 | `edittext_autosize` | 78.9% | 56 | 71 | 15 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 19 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 20 | `edittext_leading` | 66.7% | 6 | 9 | 3 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 21 | `edittext_newlines` | 66.7% | 20 | 30 | 10 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 22 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 23 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 24 | `edittext_align_trailing_spaces_swf7` | 62.5% | 360 | 576 | 216 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 25 | `edittext_align_trailing_spaces_swf8` | 62.5% | 360 | 576 | 216 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 26 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 27 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 28 | `register_class` | 57.6% | 38 | 66 | 28 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 29 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 30 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 31 | `issue_2030` | 50.0% | 2 | 4 | 2 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `string_paths_timer` | 14.8s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 2 | `timer_run_actions` | 15.4s | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 36.5s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 36.4s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

No timeouts.

## All Output Mismatches

**76 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `edittext_html_condensewhite_swf7` | 99.0% | 308/311 | 311 | 311 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `instanceof_coercions` | 97.7% | 86/88 | 88 | 88 | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 4 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 5 | `funky_function_calls` | 96.4% | 54/56 | 56 | 56 | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 6 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `define_local_with_paths` | 94.4% | 51/54 | 54 | 54 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 8 | `edittext_letter_spacing` | 93.3% | 14/15 | 15 | 15 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `edittext_html_condensewhite_swf8` | 92.6% | 288/311 | 311 | 311 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 10 | `function_base_clip_readded` | 90.9% | 10/11 | 11 | 11 |  |
| 11 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 12 | `edittext_underline` | 90.0% | 36/40 | 40 | 40 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 13 | `edittext_font_size` | 88.9% | 40/45 | 45 | 45 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 14 | `edittext_align` | 86.7% | 52/60 | 60 | 60 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 15 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 16 | `edittext_margins` | 80.0% | 20/25 | 25 | 25 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 17 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 18 | `edittext_autosize` | 78.9% | 56/71 | 71 | 71 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 19 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 20 | `edittext_leading` | 66.7% | 6/9 | 9 | 9 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 21 | `edittext_newlines` | 66.7% | 20/30 | 30 | 30 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 22 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 23 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 24 | `edittext_align_trailing_spaces_swf7` | 62.5% | 360/576 | 576 | 576 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 25 | `edittext_align_trailing_spaces_swf8` | 62.5% | 360/576 | 576 | 576 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 26 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 27 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 28 | `register_class` | 57.6% | 38/66 | 47 | 66 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 29 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 30 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 31 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 32 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 33 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 34 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 35 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 36 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 37 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 38 | `removed_target_clip_scope` | 29.7% | 11/37 | 37 | 35 | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 39 | `default_names` | 28.8% | 15/52 | 48 | 52 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 40 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 41 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 42 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 43 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 44 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 45 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 46 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 47 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 48 | `coerce_to_object_monkeypatch` | 13.0% | 17/131 | 131 | 129 | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 49 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 50 | `define_local` | 7.4% | 2/27 | 23 | 27 | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 51 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 52 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 53 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 54 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 55 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 56 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 57 | `global_proto_decls` | 0.2% | 11/4497 | 685 | 4497 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 58 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 59 | `global_proto_decls_delete` | 0.0% | 1/4158 | 309 | 4158 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 60 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 61 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 62 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 63 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 64 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 65 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 66 | `geturl` | 0.0% | 0/7 | 0 | 7 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 67 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 68 | `interface_implements_op` | 0.0% | 0/47 | 46 | 47 | [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 69 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 70 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 71 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 72 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 73 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 74 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 75 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 76 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

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
| 14 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 0 | 7 |
| 15 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 1 | 6 |
| 16 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 17 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 1 | 2 |
| 18 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 19 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 25 | 6 |
| 20 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 21 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 22 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 23 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 2 | 47 |
| 24 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 25 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 0 | 4 |
| 26 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 27 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 28 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 0 | 5 |
| 29 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 30 | 28 |
| 30 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 0 | 16 |
| 31 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 14 | 3 |
| 32 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 33 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 34 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 7 | 1 |
| 35 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 36 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 11 | 1 |
| 37 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 12 | 3 |
| 38 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 0 | 4 |
| 39 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 2 | 2 |
| 40 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 41 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 42 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 43 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 44 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 45 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 46 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 47 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) | 16 | 1 | 15 |
| 48 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 14 | 5 |
| 49 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 70 | 41 | 29 |
| 50 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 51 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 52 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 53 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 54 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 55 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 0 | 2 |
| 56 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 4 | 12 |
| 57 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 7 | 5 |
| 58 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 59 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 153 | 151 | 2 |
