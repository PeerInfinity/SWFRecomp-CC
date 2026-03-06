# Ruffle Test Results (Filtered)

**Date**: 2026-03-06 03:19 UTC

**Git SHA**: `4eb4f907d6`

**Run Duration**: 139m 16s

**Filtered**: 144 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 475 |
| Passing | **400** (84.2%) |
| Failing | 75 |
| Total expected lines | 71166 |
| Matching lines | 57826 (81.3%) |
| Mismatched lines | 13340 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 70 | 93.3% |
| Runtime Error | 2 | 2.7% |
| Segfault | 2 | 2.7% |
| Compile Fail | 1 | 1.3% |

## Passing Tests

**400 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 14.5s |  |
| 2 | `action_to_integer` | 28 | 13.3s |  |
| 3 | `add` | 28 | 13.3s |  |
| 4 | `add_property` | 15 | 13.4s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 5 | `add_swf4` | 28 | 13.3s |  |
| 6 | `add_swf5` | 28 | 13.4s |  |
| 7 | `arguments` | 127 | 13.2s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 13.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 13.5s |  |
| 10 | `array_constructor` | 30 | 13.4s |  |
| 11 | `array_enumerate` | 4 | 13.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 13.3s |  |
| 13 | `array_properties` | 36 | 13.3s |  |
| 14 | `array_prototyping` | 12 | 13.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 13.3s |  |
| 16 | `array_sort_random` | 443 | 13.4s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_splice` | 207 | 13.4s |  |
| 18 | `array_trivial` | 209 | 13.5s |  |
| 19 | `as1_constructor_v6` | 35 | 13.3s |  |
| 20 | `as1_constructor_v7` | 35 | 13.3s |  |
| 21 | `as2_oop` | 13 | 13.6s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 22 | `as2_super_and_this_v6` | 97 | 13.6s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v8` | 85 | 13.5s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_via_manual_prototype` | 40 | 13.5s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as_broadcaster` | 41 | 13.3s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 26 | `as_broadcaster_initialize` | 10 | 13.3s |  |
| 27 | `as_broadcaster_undef` | 89 | 13.3s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_set_prop_flags` | 79 | 13.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version` | 31 | 13.3s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version_swf5` | 1 | 13.2s |  |
| 31 | `as_set_prop_flags_version_swf6` | 1 | 13.2s |  |
| 32 | `as_set_prop_flags_version_swf7` | 1 | 13.2s |  |
| 33 | `as_set_prop_flags_version_swf8` | 1 | 13.2s |  |
| 34 | `as_set_prop_flags_version_swf9` | 1 | 13.2s |  |
| 35 | `as_transformed_flag` | 20 | 13.3s |  |
| 36 | `asnative` | 34 | 13.3s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 37 | `asnew` | 34 | 13.3s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 38 | `attach_movie` | 59 | 13.4s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 39 | `attach_movie_stop` | 3 | 13.7s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 40 | `bad_placeobject_clipaction` | 2 | 13.6s |  |
| 41 | `bad_swf_tag_past_eof` | 0 | 13.3s |  |
| 42 | `bitand` | 1058 | 16.2s |  |
| 43 | `bitmap_data_colortransform` | 0 | 13.7s |  |
| 44 | `bitmap_data_fillrect` | 0 | 13.7s |  |
| 45 | `bitmap_data_max_size_swf10` | 12 | 13.4s |  |
| 46 | `bitmap_data_max_size_swf9` | 10 | 13.3s |  |
| 47 | `bitmap_data_perlinnoise` | 0 | 14.2s |  |
| 48 | `bitmap_data_pixeldissolve_image` | 0 | 13.8s |  |
| 49 | `bitmapdata_applyfilter_colormatrix` | 0 | 13.5s |  |
| 50 | `bitor` | 1058 | 16.1s |  |
| 51 | `biturshift` | 14 | 13.0s |  |
| 52 | `biturshift_swf8` | 14 | 12.8s |  |
| 53 | `bitxor` | 1058 | 15.4s |  |
| 54 | `boxed_primitives` | 24 | 13.5s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 55 | `button_children` | 8 | 13.6s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_goto` | 4 | 13.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_order` | 2 | 13.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_properties_special_cases` | 22 | 13.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_v5` | 18 | 13.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_v6` | 18 | 13.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `call` | 63 | 13.4s | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) |
| 62 | `call_method_empty_name` | 1 | 13.1s |  |
| 63 | `capabilities_resolution` | 8 | 12.9s |  |
| 64 | `catch_references_registers` | 2 | 12.8s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 65 | `clip_constructors` | 8 | 13.0s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 66 | `clip_events` | 19 | 13.2s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 67 | `clone_sprite_types` | 24 | 12.7s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 68 | `closure_scope` | 7 | 12.9s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 69 | `color` | 57 | 13.0s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 70 | `color_transform` | 48 | 12.9s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 71 | `conflicting_instance_names` | 23 | 12.9s |  |
| 72 | `constructor_function` | 2 | 12.8s |  |
| 73 | `context_menu` | 39 | 12.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 74 | `context_menu_item` | 41 | 12.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 75 | `create_empty_movie_clip` | 3 | 12.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 76 | `define_function2` | 8 | 12.7s |  |
| 77 | `define_function2_preload` | 13 | 12.8s |  |
| 78 | `define_function2_preload_order` | 4 | 12.8s |  |
| 79 | `define_function_case_sensitive` | 2 | 12.8s |  |
| 80 | `delete` | 3 | 12.9s |  |
| 81 | `display_object_properties` | 2 | 12.7s |  |
| 82 | `divide_swf4` | 107 | 12.8s |  |
| 83 | `do_init_action` | 3 | 12.8s |  |
| 84 | `do_init_action_child` | 12 | 13.0s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 85 | `edittext_align` | 60 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 86 | `edittext_align_trailing_spaces_swf7` | 576 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 87 | `edittext_align_trailing_spaces_swf8` | 576 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 88 | `edittext_antialiastype` | 296 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 89 | `edittext_autosize` | 71 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 90 | `edittext_autosize_setter` | 20 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 91 | `edittext_default_format` | 221 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 92 | `edittext_default_format_font_style` | 335 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 93 | `edittext_font_size` | 45 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 94 | `edittext_hscroll` | 27 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 95 | `edittext_html_align_swf7` | 52 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 96 | `edittext_html_align_swf8` | 52 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 97 | `edittext_html_color` | 114 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 98 | `edittext_html_entity` | 4 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 99 | `edittext_html_roundtrip` | 17 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_html_swf7` | 5377 | 13.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_html_swf8` | 5377 | 13.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_leading` | 9 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_letter_spacing` | 15 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_margins` | 25 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_newline_stripping` | 64 | 17.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_programmatic_focus` | 12 | 12.8s | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_stylesheet` | 325 | 13.5s | [45](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_tag_indent` | 31 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_text_height_leading` | 20 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_underline` | 40 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_width_height` | 103 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `empty_movieclip_can_attach_movies` | 11 | 13.0s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 113 | `enumerate` | 64 | 13.1s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 114 | `equals` | 32 | 13.1s |  |
| 115 | `equals2_swf5` | 926 | 14.8s |  |
| 116 | `equals2_swf6` | 926 | 14.6s |  |
| 117 | `equals2_swf7` | 926 | 14.5s |  |
| 118 | `equals_swf4` | 665 | 13.6s |  |
| 119 | `equals_swf4_alt` | 32 | 12.9s |  |
| 120 | `equals_swf5` | 32 | 12.8s |  |
| 121 | `error` | 58 | 12.9s |  |
| 122 | `escape` | 14 | 12.8s |  |
| 123 | `execution_order1` | 5 | 12.9s |  |
| 124 | `execution_order2` | 7 | 12.8s |  |
| 125 | `execution_order3` | 4 | 12.8s |  |
| 126 | `execution_order4` | 12 | 12.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 127 | `export_assets` | 3 | 12.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 128 | `extends_chain` | 134 | 13.1s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 129 | `extends_native_type` | 11 | 12.8s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 130 | `external_interface_escapexml` | 26 | 12.9s | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 131 | `external_interface_jsquotestring` | 21 | 12.8s | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 132 | `external_interface_unescapexml` | 40 | 12.9s | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 133 | `focusrect_mouse_swf8` | 0 | 13.7s |  |
| 134 | `focusrect_mouse_swf9` | 0 | 13.8s |  |
| 135 | `focusrect_swf5` | 6 | 13.5s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 136 | `frame_size_translated_negative` | 21 | 13.3s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 137 | `frame_size_translated_positive` | 21 | 13.0s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 138 | `function_as_function` | 35 | 12.9s | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 139 | `function_base_clip` | 8 | 12.9s |  |
| 140 | `function_base_clip_removed` | 25 | 12.9s |  |
| 141 | `function_suppress_and_preload` | 28 | 12.9s |  |
| 142 | `get_bytes_total` | 4 | 12.9s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 143 | `get_variable_in_scope` | 29 | 13.0s |  |
| 144 | `getproperty` | 28 | 12.9s |  |
| 145 | `getproperty_swf4` | 28 | 13.0s |  |
| 146 | `getproperty_swf5` | 28 | 12.8s |  |
| 147 | `gettextextent` | 56 | 13.0s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 148 | `global_array` | 3 | 12.8s |  |
| 149 | `global_is_bare` | 7 | 12.9s |  |
| 150 | `global_swf6_7_8` | 15 | 13.4s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 151 | `globals_swf5` | 304 | 13.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 152 | `globals_swf6` | 304 | 13.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 153 | `globals_swf7` | 304 | 13.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 154 | `globals_swf8` | 304 | 13.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 155 | `goto_advance1` | 6 | 13.3s |  |
| 156 | `goto_advance2` | 2 | 13.6s |  |
| 157 | `goto_both_ways1` | 3 | 13.1s |  |
| 158 | `goto_both_ways2` | 3 | 12.7s |  |
| 159 | `goto_execution_order` | 2 | 12.6s |  |
| 160 | `goto_execution_order2` | 2 | 12.7s |  |
| 161 | `goto_frame` | 12 | 12.8s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 162 | `goto_frame2` | 44 | 13.2s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 163 | `goto_frame_number` | 3 | 12.9s |  |
| 164 | `goto_label` | 17 | 12.8s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 165 | `goto_methods` | 40 | 12.8s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 166 | `goto_rewind1` | 1 | 12.7s |  |
| 167 | `goto_rewind2` | 3 | 12.7s |  |
| 168 | `goto_rewind3` | 2 | 12.7s |  |
| 169 | `greater_swf6` | 1175 | 14.6s |  |
| 170 | `greater_swf7` | 1175 | 14.5s |  |
| 171 | `greaterthan_swf5` | 1 | 12.6s |  |
| 172 | `greaterthan_swf8` | 1 | 12.6s |  |
| 173 | `has_own_property` | 32 | 12.7s |  |
| 174 | `hittest_lockroot` | 15 | 12.8s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 175 | `hittest_morph` | 70 | 12.7s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 176 | `hittest_winding_rule` | 12 | 12.8s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 177 | `infinite_recursion_function` | 4 | 12.6s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 178 | `infinite_recursion_function_in_setter` | 131 | 12.7s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 179 | `infinite_recursion_virtual_property` | 67 | 12.6s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 180 | `init_array_invalid` | 4 | 12.6s |  |
| 181 | `init_object_invalid` | 4 | 12.6s |  |
| 182 | `init_object_order` | 15 | 12.8s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 183 | `is_finite` | 49 | 12.7s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 184 | `is_finite_swf6` | 49 | 12.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 185 | `is_prototype_of` | 89 | 12.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 186 | `issue_1086` | 1 | 12.6s |  |
| 187 | `issue_1104` | 2 | 12.6s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 188 | `issue_1671` | 0 | 12.6s |  |
| 189 | `issue_1906` | 4 | 12.7s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 190 | `issue_2166` | 9 | 12.6s |  |
| 191 | `issue_3169` | 2 | 12.7s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 192 | `issue_3446` | 1 | 12.6s |  |
| 193 | `issue_3522` | 2 | 12.6s |  |
| 194 | `issue_4377` | 2 | 12.6s |  |
| 195 | `issue_710` | 4 | 12.6s |  |
| 196 | `issue_768` | 3 | 12.6s | [22](ruffle-tests/_investigation/complete/issue_768.md) |
| 197 | `issue_9327` | 2 | 12.7s |  |
| 198 | `issue_9885` | 2 | 12.7s |  |
| 199 | `lessthan` | 41 | 12.7s |  |
| 200 | `lessthan2_swf5` | 1226 | 14.7s |  |
| 201 | `lessthan2_swf6` | 1226 | 14.7s |  |
| 202 | `lessthan2_swf7` | 1226 | 14.7s |  |
| 203 | `lessthan_swf4` | 902 | 13.8s |  |
| 204 | `lessthan_swf4_alt` | 41 | 12.7s |  |
| 205 | `lessthan_swf5` | 41 | 12.7s |  |
| 206 | `local_to_global` | 49 | 14.0s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 207 | `localconnection_properties` | 8 | 13.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 208 | `lock_root` | 1 | 13.7s |  |
| 209 | `logical_ops_swf4` | 90 | 13.6s |  |
| 210 | `logical_ops_swf8` | 108 | 13.7s |  |
| 211 | `looping` | 6 | 13.8s |  |
| 212 | `mask_reapply` | 0 | 13.6s |  |
| 213 | `mask_with_drawing` | 0 | 13.5s |  |
| 214 | `math_min_max` | 101 | 13.5s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 215 | `math_swf6` | 530 | 14.1s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 216 | `math_swf7` | 530 | 13.9s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 217 | `math_swf8` | 530 | 13.4s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 218 | `matrix` | 171 | 13.5s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 219 | `movieclip_begin_gradient_fill` | 0 | 14.3s |  |
| 220 | `movieclip_blend_mode_property` | 35 | 13.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 221 | `movieclip_create_text_field` | 90 | 13.6s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 222 | `movieclip_default_state` | 69 | 13.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 223 | `movieclip_depth_methods` | 98 | 13.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 224 | `movieclip_focusenabled` | 99 | 13.7s | [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 225 | `movieclip_get_instance_at_depth` | 28 | 13.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 226 | `movieclip_hittest` | 92 | 13.7s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 227 | `movieclip_in_removed_button` | 4 | 13.7s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 228 | `movieclip_init_object` | 5 | 13.7s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 229 | `movieclip_line_gradient_style` | 0 | 13.9s |  |
| 230 | `movieclip_name_from_timeline` | 13 | 13.5s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 231 | `movieclip_prototype_extension` | 5 | 13.5s |  |
| 232 | `mutable_this` | 18 | 13.4s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 233 | `named_shapes` | 14 | 13.6s |  |
| 234 | `nan_scale` | 9 | 13.4s |  |
| 235 | `native_double_construct` | 12 | 13.2s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 236 | `native_objects_swf7` | 84 | 14.0s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 237 | `native_objects_swf8` | 84 | 14.0s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 238 | `nested_textfields_in_buttons` | 0 | 13.3s |  |
| 239 | `new_method_wrap` | 4 | 13.3s |  |
| 240 | `new_object_enumerate` | 7 | 13.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 241 | `new_object_wrap` | 4 | 13.5s |  |
| 242 | `o` | 3 | 13.6s |  |
| 243 | `object_constructor` | 33 | 13.7s |  |
| 244 | `object_function` | 32 | 13.6s |  |
| 245 | `object_properties` | 31 | 13.8s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 246 | `object_prototypes` | 74 | 13.6s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 247 | `object_resolve` | 38 | 13.9s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 248 | `object_string_coerce_swf5` | 62 | 13.5s | [32](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 249 | `object_string_coerce_swf6` | 68 | 13.5s | [32](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 250 | `on_construct` | 25 | 13.5s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 251 | `parse_float` | 74 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 252 | `parse_int` | 64 | 13.7s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 253 | `place_and_lookup` | 30 | 13.4s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 254 | `placeobject_occupied_depth` | 6 | 13.2s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 255 | `point` | 175 | 13.9s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 256 | `primitive_instanceof` | 37 | 13.7s |  |
| 257 | `primitive_type_globals` | 557 | 13.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 258 | `printjob_props_swf5` | 45 | 13.5s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 259 | `printjob_props_swf6` | 45 | 13.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 260 | `printjob_props_swf7` | 45 | 13.5s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 261 | `property_invalid_base_clip` | 36 | 13.4s |  |
| 262 | `prototype_delete` | 12 | 13.2s |  |
| 263 | `prototype_enumerate` | 5 | 13.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 264 | `prototype_properties` | 17 | 13.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 265 | `rectangle` | 745 | 14.1s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 266 | `recursive_prototypes` | 0 | 13.3s |  |
| 267 | `register_class_return_value` | 16 | 13.5s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 268 | `register_class_with_sound` | 11 | 13.4s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [40](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 269 | `register_globals_across_frames` | 15 | 14.4s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 270 | `register_underflow` | 26 | 13.1s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 271 | `remove_movie_clip` | 29 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 272 | `rewind_depth` | 30 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 273 | `sandbox_type_local_file` | 1 | 13.0s |  |
| 274 | `sandbox_type_local_network` | 1 | 12.9s |  |
| 275 | `selection` | 454 | 13.3s | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 276 | `set_interval` | 27 | 13.3s | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 277 | `set_variable_scope` | 58 | 13.0s |  |
| 278 | `single_frame` | 1 | 12.7s |  |
| 279 | `slash_syntax` | 14 | 12.9s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 280 | `sound` | 628 | 13.3s | [40](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 281 | `sound_props_swf5` | 68 | 13.3s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 282 | `sound_props_swf6` | 68 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 283 | `sound_start_load` | 0 | 14.1s |  |
| 284 | `stage_display_state` | 16 | 13.6s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 285 | `stage_object_children` | 83 | 13.5s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 286 | `stage_object_enumerate` | 4 | 13.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 287 | `stage_object_properties` | 241 | 13.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 288 | `stage_object_properties_get_var` | 5 | 13.2s |  |
| 289 | `stage_object_properties_swf6` | 231 | 13.4s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 290 | `stage_property_representation` | 586 | 13.2s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 291 | `stage_scale_mode` | 39 | 13.2s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 292 | `strictequals_swf6` | 902 | 14.7s |  |
| 293 | `strictly_equals` | 7 | 13.3s |  |
| 294 | `string_methods` | 285 | 13.9s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 295 | `string_methods_negative_args` | 240 | 13.9s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 296 | `string_methods_swfv5` | 275 | 14.8s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 297 | `string_ops_swf6` | 95 | 14.3s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 298 | `string_paths_basic` | 4 | 14.1s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 299 | `string_paths_eval2` | 7 | 14.6s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 300 | `string_paths_hidden` | 54 | 14.3s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 301 | `string_paths_other` | 36 | 13.5s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 302 | `string_paths_unload` | 1 | 13.9s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 303 | `string_paths_variable_alias` | 4 | 13.1s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 304 | `string_paths_variable_scopes` | 5 | 13.0s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 305 | `stylesheet` | 283 | 13.8s |  |
| 306 | `stylesheet_transform` | 750 | 13.6s |  |
| 307 | `super_edge_cases` | 39 | 13.0s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 308 | `swf4_actions_bool` | 96 | 13.0s |  |
| 309 | `swf4_actions_coercion_order` | 158 | 13.0s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 310 | `swf4_bool` | 4 | 12.8s |  |
| 311 | `swf4_function_calls` | 7 | 13.3s |  |
| 312 | `swf5_encoding` | 3 | 12.7s |  |
| 313 | `swf5_global_funcs` | 232 | 12.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 314 | `swf5_no_closure` | 19 | 12.8s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 315 | `swf6_case_insensitive` | 42 | 12.7s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 316 | `swf6_global_funcs` | 232 | 12.7s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 317 | `swf6_string_as_bool` | 15 | 12.6s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 318 | `swf7_case_sensitive` | 44 | 12.7s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 319 | `swf7_global_funcs` | 232 | 12.7s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 320 | `tab_ordering_properties_tab_index_edge_case` | 4 | 13.3s |  |
| 321 | `target_clip_swf5` | 2 | 13.1s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 322 | `target_clip_swf6` | 2 | 13.1s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 323 | `target_path` | 14 | 12.8s |  |
| 324 | `tell_target` | 37 | 12.9s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 325 | `tell_target_invalid` | 6 | 13.0s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 326 | `tell_target_invalid_swf6` | 5 | 13.1s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 327 | `text_format` | 1146 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 328 | `text_format_display` | 21 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 329 | `text_format_font_max_length` | 2 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 330 | `text_format_rounding_swf7` | 840 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 331 | `text_format_rounding_swf8` | 840 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 332 | `textfield_background_color` | 11 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 333 | `textfield_border_color` | 11 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 334 | `textfield_cache_as_bitmap` | 1 | 12.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 335 | `textfield_maxchars` | 3 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 336 | `textfield_properties` | 44 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 337 | `textfield_props_swf5` | 175 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 338 | `textfield_props_swf6` | 210 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 339 | `textfield_props_swf7` | 210 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 340 | `textfield_props_swf8` | 210 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 341 | `textfield_text` | 7 | 12.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 342 | `textfield_variable` | 81 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 343 | `textsnapshot_available_text` | 20 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 344 | `textsnapshot_findtext` | 44 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 345 | `textsnapshot_gettext` | 55 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 346 | `textsnapshot_props_swf5` | 56 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 347 | `textsnapshot_props_swf6` | 56 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 348 | `textsnapshot_text_order` | 1 | 12.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 349 | `this_scoping` | 52 | 12.9s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 350 | `this_swf5` | 41 | 12.9s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 351 | `this_swf6` | 41 | 12.7s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 352 | `this_swf7` | 41 | 12.7s | [52](ruffle-tests/_investigation/complete/this_swf7.md) |
| 353 | `timeline_function_def` | 7 | 13.1s |  |
| 354 | `trace` | 8 | 13.5s |  |
| 355 | `transform` | 70 | 13.4s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 356 | `try_catch_finally` | 118 | 13.3s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 357 | `try_finally_simple` | 16 | 13.1s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 358 | `typeof` | 22 | 13.2s |  |
| 359 | `typeof_globals` | 7 | 13.2s |  |
| 360 | `uncaught_exception` | 1 | 13.2s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 361 | `uncaught_exception_bubbled` | 1 | 13.2s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 362 | `undefined_to_string_swf6` | 4 | 13.2s |  |
| 363 | `unescape` | 43 | 13.2s |  |
| 364 | `unload` | 52 | 13.3s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 365 | `unload_clip_event` | 4 | 13.2s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 366 | `use_hand_cursor` | 8 | 13.2s |  |
| 367 | `variable_args` | 5 | 13.4s |  |
| 368 | `waitforframe` | 7 | 13.3s |  |
| 369 | `waitforframe2` | 16 | 13.3s |  |
| 370 | `watch` | 117 | 13.5s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 371 | `watch_textfield` | 12 | 13.2s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 372 | `watch_virtual_property_proto` | 2 | 13.2s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 373 | `with` | 49 | 13.2s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 374 | `with_return` | 2 | 13.1s |  |
| 375 | `with_variable_scopes` | 43 | 13.3s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 376 | `xml` | 15 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 377 | `xml_append_child` | 28 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 378 | `xml_append_child_with_parent` | 20 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 379 | `xml_cdata` | 11 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 380 | `xml_child_nodes_edge_cases` | 4 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 381 | `xml_clone_expandos` | 19 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 382 | `xml_first_last_child` | 8 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 383 | `xml_has_child_nodes` | 3 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 384 | `xml_idmap` | 21 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 385 | `xml_ignore_comments` | 21 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 386 | `xml_ignore_white` | 34 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 387 | `xml_insert_before` | 20 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 388 | `xml_inspect_createmethods` | 15 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 389 | `xml_inspect_doctype` | 7 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 390 | `xml_inspect_parsexml` | 62 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 391 | `xml_inspect_xmldecl` | 7 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 392 | `xml_namespaces` | 203 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 393 | `xml_parent_and_child` | 5 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 394 | `xml_remove_node` | 22 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 395 | `xml_reparenting` | 14 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 396 | `xml_siblings` | 10 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 397 | `xml_to_string` | 13 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 398 | `xml_to_string_comment` | 1 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 399 | `xml_unescaping` | 23 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 400 | `xmlnode_proto` | 1 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**26 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `edittext_html_condensewhite_swf7` | 99.0% | 308 | 311 | 3 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `instanceof_coercions` | 97.7% | 86 | 88 | 2 | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 4 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 5 | `funky_function_calls` | 96.4% | 54 | 56 | 2 | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 6 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `define_local_with_paths` | 94.4% | 51 | 54 | 3 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 8 | `edittext_html_condensewhite_swf8` | 92.6% | 288 | 311 | 23 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `function_base_clip_readded` | 90.9% | 10 | 11 | 1 |  |
| 10 | `string_coercion` | 90.7% | 107 | 118 | 11 | [43](ruffle-tests/_investigation/complete/string_coercion.md) |
| 11 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 12 | `path_string` | 86.7% | 280 | 323 | 43 | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 13 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 14 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 15 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 17 | `duplicate_movie_clip` | 66.7% | 14 | 21 | 7 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 18 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 19 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 20 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 21 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 22 | `register_class` | 57.6% | 38 | 66 | 28 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 23 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 24 | `device_font_spacing` | 51.6% | 47 | 91 | 44 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 25 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 26 | `issue_2030` | 50.0% | 2 | 4 | 2 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `string_paths_timer` | 15.8s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 2 | `timer_run_actions` | 15.5s | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 37.6s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 38.1s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

No timeouts.

## All Output Mismatches

**70 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `edittext_html_condensewhite_swf7` | 99.0% | 308/311 | 311 | 311 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `instanceof_coercions` | 97.7% | 86/88 | 88 | 88 | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 4 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 5 | `funky_function_calls` | 96.4% | 54/56 | 56 | 56 | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 6 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `define_local_with_paths` | 94.4% | 51/54 | 54 | 54 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 8 | `edittext_html_condensewhite_swf8` | 92.6% | 288/311 | 311 | 311 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `function_base_clip_readded` | 90.9% | 10/11 | 11 | 11 |  |
| 10 | `string_coercion` | 90.7% | 107/118 | 118 | 117 | [43](ruffle-tests/_investigation/complete/string_coercion.md) |
| 11 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 12 | `path_string` | 86.7% | 280/323 | 323 | 322 | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 13 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 14 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 15 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 17 | `duplicate_movie_clip` | 66.7% | 14/21 | 21 | 20 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 18 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 19 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 20 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 21 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 22 | `register_class` | 57.6% | 38/66 | 47 | 66 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 23 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 24 | `device_font_spacing` | 51.6% | 47/91 | 91 | 91 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 25 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 26 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 27 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 28 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 29 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 30 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 31 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 32 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 33 | `removed_target_clip_scope` | 29.7% | 11/37 | 37 | 35 | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 34 | `default_names` | 28.8% | 15/52 | 48 | 52 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 35 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 36 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 37 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 38 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 39 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 40 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 41 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 42 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 43 | `coerce_to_object_monkeypatch` | 13.0% | 17/131 | 131 | 129 | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 44 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 45 | `add2` | 8.7% | 31/358 | 358 | 354 | [1](ruffle-tests/_investigation/complete/add2.md) |
| 46 | `define_local` | 7.4% | 2/27 | 23 | 27 | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 47 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 48 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 49 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 50 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 51 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 52 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 53 | `global_proto_decls` | 0.2% | 11/4497 | 685 | 4497 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 54 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 55 | `global_proto_decls_delete` | 0.0% | 1/4158 | 309 | 4158 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 56 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 57 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 58 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 59 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 60 | `geturl` | 0.0% | 0/7 | 0 | 7 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 61 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 62 | `interface_implements_op` | 0.0% | 0/47 | 46 | 47 | [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 63 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 64 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 65 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 66 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 67 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 68 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 69 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 70 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 0 | 1 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 7 | 7 |
| 6 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) | 2 | 1 | 1 |
| 7 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 3 | 5 |
| 8 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 1 | 3 |
| 9 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 10 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 11 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 0 | 4 |
| 12 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 13 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 14 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 3 | 4 |
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
| 29 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 29 | 29 |
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
| 43 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 0 | 1 |
| 44 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 45 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 46 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 47 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) | 16 | 1 | 15 |
| 48 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 13 | 6 |
| 49 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 70 | 50 | 20 |
| 50 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 51 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 52 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 53 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 54 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 55 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 0 | 2 |
| 56 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 3 | 13 |
| 57 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 7 | 5 |
| 58 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 59 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 153 | 151 | 2 |
