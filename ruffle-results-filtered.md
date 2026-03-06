# Ruffle Test Results (Filtered)

**Date**: 2026-03-06 04:03 UTC

**Git SHA**: `2bf4673684`

**Run Duration**: 140m 39s

**Filtered**: 143 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 476 |
| Passing | **403** (84.7%) |
| Failing | 73 |
| Total expected lines | 71520 |
| Matching lines | 58344 (81.6%) |
| Mismatched lines | 13176 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 68 | 93.2% |
| Runtime Error | 2 | 2.7% |
| Segfault | 2 | 2.7% |
| Compile Fail | 1 | 1.4% |

## Passing Tests

**403 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 15.2s |  |
| 2 | `action_to_integer` | 28 | 12.8s |  |
| 3 | `add` | 28 | 12.9s |  |
| 4 | `add_property` | 15 | 12.8s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 5 | `add_swf4` | 28 | 12.8s |  |
| 6 | `add_swf5` | 28 | 12.8s |  |
| 7 | `arguments` | 127 | 12.8s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 12.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 12.9s |  |
| 10 | `array_constructor` | 30 | 12.9s |  |
| 11 | `array_enumerate` | 4 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 12.9s |  |
| 13 | `array_properties` | 36 | 12.9s |  |
| 14 | `array_prototyping` | 12 | 12.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 12.9s |  |
| 16 | `array_sort_random` | 443 | 12.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_splice` | 207 | 13.0s |  |
| 18 | `array_trivial` | 209 | 13.0s |  |
| 19 | `as1_constructor_v6` | 35 | 12.9s |  |
| 20 | `as1_constructor_v7` | 35 | 12.9s |  |
| 21 | `as2_oop` | 13 | 13.0s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 22 | `as2_super_and_this_v6` | 97 | 13.1s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v8` | 85 | 13.0s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_via_manual_prototype` | 40 | 13.1s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as_broadcaster` | 41 | 12.9s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 26 | `as_broadcaster_initialize` | 10 | 12.8s |  |
| 27 | `as_broadcaster_undef` | 89 | 13.0s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_set_prop_flags` | 79 | 12.9s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version` | 31 | 12.8s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version_swf5` | 1 | 12.8s |  |
| 31 | `as_set_prop_flags_version_swf6` | 1 | 12.9s |  |
| 32 | `as_set_prop_flags_version_swf7` | 1 | 12.9s |  |
| 33 | `as_set_prop_flags_version_swf8` | 1 | 12.8s |  |
| 34 | `as_set_prop_flags_version_swf9` | 1 | 12.9s |  |
| 35 | `as_transformed_flag` | 20 | 12.9s |  |
| 36 | `asnative` | 34 | 12.9s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 37 | `asnew` | 34 | 12.9s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 38 | `attach_movie` | 59 | 12.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 39 | `attach_movie_stop` | 3 | 12.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 40 | `bad_placeobject_clipaction` | 2 | 12.8s |  |
| 41 | `bad_swf_tag_past_eof` | 0 | 12.8s |  |
| 42 | `bitand` | 1058 | 15.3s |  |
| 43 | `bitmap_data_colortransform` | 0 | 13.1s |  |
| 44 | `bitmap_data_fillrect` | 0 | 13.0s |  |
| 45 | `bitmap_data_max_size_swf10` | 12 | 12.8s |  |
| 46 | `bitmap_data_max_size_swf9` | 10 | 12.9s |  |
| 47 | `bitmap_data_perlinnoise` | 0 | 13.7s |  |
| 48 | `bitmap_data_pixeldissolve_image` | 0 | 13.3s |  |
| 49 | `bitmapdata_applyfilter_colormatrix` | 0 | 13.2s |  |
| 50 | `bitor` | 1058 | 15.7s |  |
| 51 | `biturshift` | 14 | 13.7s |  |
| 52 | `biturshift_swf8` | 14 | 13.5s |  |
| 53 | `bitxor` | 1058 | 16.0s |  |
| 54 | `boxed_primitives` | 24 | 13.4s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 55 | `button_children` | 8 | 13.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_goto` | 4 | 13.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_order` | 2 | 12.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_properties_special_cases` | 22 | 13.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_v5` | 18 | 12.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_v6` | 18 | 13.0s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `call` | 63 | 13.4s | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) |
| 62 | `call_method_empty_name` | 1 | 13.2s |  |
| 63 | `capabilities_resolution` | 8 | 13.2s |  |
| 64 | `catch_references_registers` | 2 | 13.1s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 65 | `clip_constructors` | 8 | 13.3s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 66 | `clip_events` | 19 | 13.4s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 67 | `clone_sprite_types` | 24 | 13.2s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 68 | `closure_scope` | 7 | 13.1s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 69 | `color` | 57 | 13.3s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 70 | `color_transform` | 48 | 13.1s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 71 | `conflicting_instance_names` | 23 | 13.0s |  |
| 72 | `constructor_function` | 2 | 12.9s |  |
| 73 | `context_menu` | 39 | 13.0s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 74 | `context_menu_item` | 41 | 13.0s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 75 | `create_empty_movie_clip` | 3 | 13.2s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 76 | `define_function2` | 8 | 13.3s |  |
| 77 | `define_function2_preload` | 13 | 13.2s |  |
| 78 | `define_function2_preload_order` | 4 | 13.3s |  |
| 79 | `define_function_case_sensitive` | 2 | 13.3s |  |
| 80 | `delete` | 3 | 13.2s |  |
| 81 | `display_object_properties` | 2 | 13.4s |  |
| 82 | `divide_swf4` | 107 | 13.4s |  |
| 83 | `do_init_action` | 3 | 13.4s |  |
| 84 | `do_init_action_child` | 12 | 13.5s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 85 | `edittext_align` | 60 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 86 | `edittext_align_trailing_spaces_swf7` | 576 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 87 | `edittext_align_trailing_spaces_swf8` | 576 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 88 | `edittext_antialiastype` | 296 | 15.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 89 | `edittext_autosize` | 71 | 13.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 90 | `edittext_autosize_setter` | 20 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 91 | `edittext_default_format` | 221 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 92 | `edittext_default_format_font_style` | 335 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 93 | `edittext_font_size` | 45 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 94 | `edittext_hscroll` | 27 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 95 | `edittext_html_align_swf7` | 52 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 96 | `edittext_html_align_swf8` | 52 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 97 | `edittext_html_color` | 114 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 98 | `edittext_html_entity` | 4 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 99 | `edittext_html_roundtrip` | 17 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_html_swf7` | 5377 | 14.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_html_swf8` | 5377 | 14.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_leading` | 9 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_letter_spacing` | 15 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_margins` | 25 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_newline_stripping` | 64 | 18.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_programmatic_focus` | 12 | 13.1s | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_stylesheet` | 325 | 13.6s | [45](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_tag_indent` | 31 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_text_height_leading` | 20 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_underline` | 40 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_width_height` | 103 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `empty_movieclip_can_attach_movies` | 11 | 12.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 113 | `enumerate` | 64 | 12.9s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 114 | `equals` | 32 | 12.8s |  |
| 115 | `equals2_swf5` | 926 | 14.5s |  |
| 116 | `equals2_swf6` | 926 | 14.7s |  |
| 117 | `equals2_swf7` | 926 | 14.8s |  |
| 118 | `equals_swf4` | 665 | 13.8s |  |
| 119 | `equals_swf4_alt` | 32 | 13.1s |  |
| 120 | `equals_swf5` | 32 | 13.0s |  |
| 121 | `error` | 58 | 13.1s |  |
| 122 | `escape` | 14 | 13.0s |  |
| 123 | `execution_order1` | 5 | 13.1s |  |
| 124 | `execution_order2` | 7 | 13.0s |  |
| 125 | `execution_order3` | 4 | 13.0s |  |
| 126 | `execution_order4` | 12 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 127 | `export_assets` | 3 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 128 | `extends_chain` | 134 | 13.3s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 129 | `extends_native_type` | 11 | 13.1s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 130 | `external_interface_escapexml` | 26 | 13.2s | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 131 | `external_interface_jsquotestring` | 21 | 13.2s | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 132 | `external_interface_toas_basic` | 354 | 13.4s | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 133 | `external_interface_toxml_array` | 25 | 13.1s | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 134 | `external_interface_toxml_basic` | 179 | 13.3s | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 135 | `external_interface_unescapexml` | 40 | 13.3s | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 136 | `focusrect_mouse_swf8` | 0 | 13.0s |  |
| 137 | `focusrect_mouse_swf9` | 0 | 13.1s |  |
| 138 | `focusrect_swf5` | 6 | 13.3s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 139 | `frame_size_translated_negative` | 21 | 13.1s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 140 | `frame_size_translated_positive` | 21 | 13.2s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 141 | `function_as_function` | 35 | 13.1s | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 142 | `function_base_clip` | 8 | 13.2s |  |
| 143 | `function_base_clip_removed` | 25 | 13.2s |  |
| 144 | `function_suppress_and_preload` | 28 | 13.3s |  |
| 145 | `get_bytes_total` | 4 | 13.0s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 146 | `get_variable_in_scope` | 29 | 13.1s |  |
| 147 | `getproperty` | 28 | 13.1s |  |
| 148 | `getproperty_swf4` | 28 | 13.2s |  |
| 149 | `getproperty_swf5` | 28 | 13.2s |  |
| 150 | `gettextextent` | 56 | 13.2s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 151 | `global_array` | 3 | 13.1s |  |
| 152 | `global_is_bare` | 7 | 13.1s |  |
| 153 | `global_swf6_7_8` | 15 | 13.7s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 154 | `globals_swf5` | 304 | 13.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 155 | `globals_swf6` | 304 | 13.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 156 | `globals_swf7` | 304 | 13.5s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 157 | `globals_swf8` | 304 | 13.6s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 158 | `goto_advance1` | 6 | 13.3s |  |
| 159 | `goto_advance2` | 2 | 13.2s |  |
| 160 | `goto_both_ways1` | 3 | 15.7s |  |
| 161 | `goto_both_ways2` | 3 | 14.2s |  |
| 162 | `goto_execution_order` | 2 | 14.1s |  |
| 163 | `goto_execution_order2` | 2 | 14.2s |  |
| 164 | `goto_frame` | 12 | 14.4s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 165 | `goto_frame2` | 44 | 14.7s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 166 | `goto_frame_number` | 3 | 14.5s |  |
| 167 | `goto_label` | 17 | 14.6s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 168 | `goto_methods` | 40 | 14.4s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 169 | `goto_rewind1` | 1 | 14.7s |  |
| 170 | `goto_rewind2` | 3 | 14.1s |  |
| 171 | `goto_rewind3` | 2 | 14.2s |  |
| 172 | `greater_swf6` | 1175 | 16.8s |  |
| 173 | `greater_swf7` | 1175 | 16.8s |  |
| 174 | `greaterthan_swf5` | 1 | 14.2s |  |
| 175 | `greaterthan_swf8` | 1 | 14.2s |  |
| 176 | `has_own_property` | 32 | 14.3s |  |
| 177 | `hittest_lockroot` | 15 | 14.5s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 178 | `hittest_morph` | 70 | 14.4s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 179 | `hittest_winding_rule` | 12 | 14.7s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 180 | `infinite_recursion_function` | 4 | 14.3s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 181 | `infinite_recursion_function_in_setter` | 131 | 14.5s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 182 | `infinite_recursion_virtual_property` | 67 | 14.4s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 183 | `init_array_invalid` | 4 | 14.4s |  |
| 184 | `init_object_invalid` | 4 | 14.4s |  |
| 185 | `init_object_order` | 15 | 14.5s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 186 | `is_finite` | 49 | 14.4s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 187 | `is_finite_swf6` | 49 | 14.4s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 188 | `is_prototype_of` | 89 | 14.5s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 189 | `issue_1086` | 1 | 14.6s |  |
| 190 | `issue_1104` | 2 | 14.1s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 191 | `issue_1671` | 0 | 14.3s |  |
| 192 | `issue_1906` | 4 | 14.4s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 193 | `issue_2166` | 9 | 14.2s |  |
| 194 | `issue_3169` | 2 | 14.0s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 195 | `issue_3446` | 1 | 13.8s |  |
| 196 | `issue_3522` | 2 | 13.7s |  |
| 197 | `issue_4377` | 2 | 13.7s |  |
| 198 | `issue_710` | 4 | 14.4s |  |
| 199 | `issue_768` | 3 | 14.2s | [22](ruffle-tests/_investigation/complete/issue_768.md) |
| 200 | `issue_9327` | 2 | 14.2s |  |
| 201 | `issue_9885` | 2 | 14.0s |  |
| 202 | `lessthan` | 41 | 14.7s |  |
| 203 | `lessthan2_swf5` | 1226 | 16.7s |  |
| 204 | `lessthan2_swf6` | 1226 | 16.7s |  |
| 205 | `lessthan2_swf7` | 1226 | 16.8s |  |
| 206 | `lessthan_swf4` | 902 | 15.7s |  |
| 207 | `lessthan_swf4_alt` | 41 | 14.5s |  |
| 208 | `lessthan_swf5` | 41 | 14.4s |  |
| 209 | `local_to_global` | 49 | 13.0s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 210 | `localconnection_properties` | 8 | 12.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 211 | `lock_root` | 1 | 12.9s |  |
| 212 | `logical_ops_swf4` | 90 | 12.8s |  |
| 213 | `logical_ops_swf8` | 108 | 12.9s |  |
| 214 | `looping` | 6 | 12.9s |  |
| 215 | `mask_reapply` | 0 | 13.0s |  |
| 216 | `mask_with_drawing` | 0 | 13.0s |  |
| 217 | `math_min_max` | 101 | 13.1s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 218 | `math_swf6` | 530 | 13.3s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 219 | `math_swf7` | 530 | 13.3s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 220 | `math_swf8` | 530 | 13.3s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 221 | `matrix` | 171 | 13.2s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 222 | `movieclip_begin_gradient_fill` | 0 | 13.5s |  |
| 223 | `movieclip_blend_mode_property` | 35 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 224 | `movieclip_create_text_field` | 90 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 225 | `movieclip_default_state` | 69 | 13.2s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 226 | `movieclip_depth_methods` | 98 | 13.2s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 227 | `movieclip_focusenabled` | 99 | 13.0s | [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 228 | `movieclip_get_instance_at_depth` | 28 | 12.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 229 | `movieclip_hittest` | 92 | 13.0s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 230 | `movieclip_in_removed_button` | 4 | 13.0s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 231 | `movieclip_init_object` | 5 | 13.2s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 232 | `movieclip_line_gradient_style` | 0 | 13.4s |  |
| 233 | `movieclip_name_from_timeline` | 13 | 12.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 234 | `movieclip_prototype_extension` | 5 | 13.0s |  |
| 235 | `mutable_this` | 18 | 13.4s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 236 | `named_shapes` | 14 | 13.0s |  |
| 237 | `nan_scale` | 9 | 13.0s |  |
| 238 | `native_double_construct` | 12 | 13.6s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 239 | `native_objects_swf7` | 84 | 13.4s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 240 | `native_objects_swf8` | 84 | 13.4s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 241 | `nested_textfields_in_buttons` | 0 | 12.9s |  |
| 242 | `new_method_wrap` | 4 | 12.9s |  |
| 243 | `new_object_enumerate` | 7 | 12.9s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 244 | `new_object_wrap` | 4 | 12.9s |  |
| 245 | `o` | 3 | 12.9s |  |
| 246 | `object_constructor` | 33 | 13.0s |  |
| 247 | `object_function` | 32 | 13.0s |  |
| 248 | `object_properties` | 31 | 13.0s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 249 | `object_prototypes` | 74 | 13.0s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 250 | `object_resolve` | 38 | 13.1s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 251 | `object_string_coerce_swf5` | 62 | 13.0s | [32](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 252 | `object_string_coerce_swf6` | 68 | 13.0s | [32](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 253 | `on_construct` | 25 | 13.0s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 254 | `parse_float` | 74 | 13.0s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 255 | `parse_int` | 64 | 13.2s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 256 | `place_and_lookup` | 30 | 13.0s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 257 | `placeobject_occupied_depth` | 6 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 258 | `point` | 175 | 13.4s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 259 | `primitive_instanceof` | 37 | 13.0s |  |
| 260 | `primitive_type_globals` | 557 | 13.1s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 261 | `printjob_props_swf5` | 45 | 13.0s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 262 | `printjob_props_swf6` | 45 | 13.0s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 263 | `printjob_props_swf7` | 45 | 13.1s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 264 | `property_invalid_base_clip` | 36 | 13.1s |  |
| 265 | `prototype_delete` | 12 | 13.0s |  |
| 266 | `prototype_enumerate` | 5 | 13.0s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 267 | `prototype_properties` | 17 | 13.0s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 268 | `rectangle` | 745 | 13.8s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 269 | `recursive_prototypes` | 0 | 12.9s |  |
| 270 | `register_class_return_value` | 16 | 13.2s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 271 | `register_class_with_sound` | 11 | 13.1s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [40](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 272 | `register_globals_across_frames` | 15 | 13.5s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 273 | `register_underflow` | 26 | 13.4s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 274 | `remove_movie_clip` | 29 | 13.4s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 275 | `rewind_depth` | 30 | 13.4s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 276 | `sandbox_type_local_file` | 1 | 13.5s |  |
| 277 | `sandbox_type_local_network` | 1 | 13.1s |  |
| 278 | `selection` | 454 | 13.4s | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 279 | `set_interval` | 27 | 13.5s | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 280 | `set_variable_scope` | 58 | 13.2s |  |
| 281 | `single_frame` | 1 | 13.2s |  |
| 282 | `slash_syntax` | 14 | 13.2s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 283 | `sound` | 628 | 13.6s | [40](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 284 | `sound_props_swf5` | 68 | 13.3s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 285 | `sound_props_swf6` | 68 | 13.3s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 286 | `sound_start_load` | 0 | 13.4s |  |
| 287 | `stage_display_state` | 16 | 13.2s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 288 | `stage_object_children` | 83 | 13.3s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 289 | `stage_object_enumerate` | 4 | 13.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 290 | `stage_object_properties` | 241 | 13.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 291 | `stage_object_properties_get_var` | 5 | 13.2s |  |
| 292 | `stage_object_properties_swf6` | 231 | 13.6s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 293 | `stage_property_representation` | 586 | 13.2s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 294 | `stage_scale_mode` | 39 | 13.2s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 295 | `strictequals_swf6` | 902 | 14.7s |  |
| 296 | `strictly_equals` | 7 | 13.1s |  |
| 297 | `string_methods` | 285 | 13.8s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 298 | `string_methods_negative_args` | 240 | 13.3s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 299 | `string_methods_swfv5` | 275 | 13.7s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 300 | `string_ops_swf6` | 95 | 13.2s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 301 | `string_paths_basic` | 4 | 13.1s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 302 | `string_paths_eval2` | 7 | 13.3s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 303 | `string_paths_hidden` | 54 | 13.3s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 304 | `string_paths_other` | 36 | 13.4s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 305 | `string_paths_unload` | 1 | 13.4s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 306 | `string_paths_variable_alias` | 4 | 13.1s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 307 | `string_paths_variable_scopes` | 5 | 13.3s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 308 | `stylesheet` | 283 | 14.1s |  |
| 309 | `stylesheet_transform` | 750 | 13.9s |  |
| 310 | `super_edge_cases` | 39 | 13.4s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 311 | `swf4_actions_bool` | 96 | 13.3s |  |
| 312 | `swf4_actions_coercion_order` | 158 | 13.3s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 313 | `swf4_bool` | 4 | 13.2s |  |
| 314 | `swf4_function_calls` | 7 | 14.7s |  |
| 315 | `swf5_encoding` | 3 | 13.1s |  |
| 316 | `swf5_global_funcs` | 232 | 13.2s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 317 | `swf5_no_closure` | 19 | 13.2s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 318 | `swf6_case_insensitive` | 42 | 13.0s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 319 | `swf6_global_funcs` | 232 | 13.2s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 320 | `swf6_string_as_bool` | 15 | 13.1s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 321 | `swf7_case_sensitive` | 44 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 322 | `swf7_global_funcs` | 232 | 13.1s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 323 | `tab_ordering_properties_tab_index_edge_case` | 4 | 12.9s |  |
| 324 | `target_clip_swf5` | 2 | 12.9s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 325 | `target_clip_swf6` | 2 | 12.8s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 326 | `target_path` | 14 | 12.7s |  |
| 327 | `tell_target` | 37 | 12.9s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 328 | `tell_target_invalid` | 6 | 12.9s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 329 | `tell_target_invalid_swf6` | 5 | 13.0s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 330 | `text_format` | 1146 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 331 | `text_format_display` | 21 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 332 | `text_format_font_max_length` | 2 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 333 | `text_format_rounding_swf7` | 840 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 334 | `text_format_rounding_swf8` | 840 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 335 | `textfield_background_color` | 11 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 336 | `textfield_border_color` | 11 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 337 | `textfield_cache_as_bitmap` | 1 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 338 | `textfield_maxchars` | 3 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 339 | `textfield_properties` | 44 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 340 | `textfield_props_swf5` | 175 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 341 | `textfield_props_swf6` | 210 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 342 | `textfield_props_swf7` | 210 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 343 | `textfield_props_swf8` | 210 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 344 | `textfield_text` | 7 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 345 | `textfield_variable` | 81 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 346 | `textsnapshot_available_text` | 20 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 347 | `textsnapshot_findtext` | 44 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 348 | `textsnapshot_gettext` | 55 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 349 | `textsnapshot_props_swf5` | 56 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 350 | `textsnapshot_props_swf6` | 56 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 351 | `textsnapshot_text_order` | 1 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 352 | `this_scoping` | 52 | 13.0s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 353 | `this_swf5` | 41 | 12.9s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 354 | `this_swf6` | 41 | 12.9s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 355 | `this_swf7` | 41 | 13.0s | [52](ruffle-tests/_investigation/complete/this_swf7.md) |
| 356 | `timeline_function_def` | 7 | 13.1s |  |
| 357 | `trace` | 8 | 14.0s |  |
| 358 | `transform` | 70 | 14.0s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 359 | `try_catch_finally` | 118 | 14.0s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 360 | `try_finally_simple` | 16 | 13.8s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 361 | `typeof` | 22 | 14.0s |  |
| 362 | `typeof_globals` | 7 | 13.8s |  |
| 363 | `uncaught_exception` | 1 | 13.7s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 364 | `uncaught_exception_bubbled` | 1 | 13.7s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 365 | `undefined_to_string_swf6` | 4 | 13.7s |  |
| 366 | `unescape` | 43 | 13.9s |  |
| 367 | `unload` | 52 | 14.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 368 | `unload_clip_event` | 4 | 13.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 369 | `use_hand_cursor` | 8 | 14.1s |  |
| 370 | `variable_args` | 5 | 14.2s |  |
| 371 | `waitforframe` | 7 | 13.5s |  |
| 372 | `waitforframe2` | 16 | 13.6s |  |
| 373 | `watch` | 117 | 14.1s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 374 | `watch_textfield` | 12 | 13.5s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 375 | `watch_virtual_property_proto` | 2 | 13.6s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 376 | `with` | 49 | 13.6s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 377 | `with_return` | 2 | 13.6s |  |
| 378 | `with_variable_scopes` | 43 | 13.5s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 379 | `xml` | 15 | 13.5s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 380 | `xml_append_child` | 28 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 381 | `xml_append_child_with_parent` | 20 | 13.5s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 382 | `xml_cdata` | 11 | 13.5s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 383 | `xml_child_nodes_edge_cases` | 4 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 384 | `xml_clone_expandos` | 19 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 385 | `xml_first_last_child` | 8 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 386 | `xml_has_child_nodes` | 3 | 13.6s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 387 | `xml_idmap` | 21 | 13.6s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 388 | `xml_ignore_comments` | 21 | 13.6s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 389 | `xml_ignore_white` | 34 | 13.5s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 390 | `xml_insert_before` | 20 | 13.5s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 391 | `xml_inspect_createmethods` | 15 | 13.6s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 392 | `xml_inspect_doctype` | 7 | 13.6s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 393 | `xml_inspect_parsexml` | 62 | 14.0s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 394 | `xml_inspect_xmldecl` | 7 | 13.8s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 395 | `xml_namespaces` | 203 | 13.8s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 396 | `xml_parent_and_child` | 5 | 13.8s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 397 | `xml_remove_node` | 22 | 13.8s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 398 | `xml_reparenting` | 14 | 13.8s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 399 | `xml_siblings` | 10 | 13.9s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 400 | `xml_to_string` | 13 | 13.7s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 401 | `xml_to_string_comment` | 1 | 13.6s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 402 | `xml_unescaping` | 23 | 13.6s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 403 | `xmlnode_proto` | 1 | 13.5s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |

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
| 1 | `string_paths_timer` | 15.4s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 2 | `timer_run_actions` | 16.2s | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 36.6s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 36.7s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

No timeouts.

## All Output Mismatches

**68 tests** with output mismatch, sorted by match rate (best first)

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
| 36 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 37 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 38 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 39 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 40 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 41 | `coerce_to_object_monkeypatch` | 13.0% | 17/131 | 131 | 129 | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 42 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 43 | `add2` | 8.7% | 31/358 | 358 | 354 | [1](ruffle-tests/_investigation/complete/add2.md) |
| 44 | `define_local` | 7.4% | 2/27 | 23 | 27 | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 45 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 46 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 47 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 48 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 49 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 50 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 51 | `global_proto_decls` | 0.2% | 11/4497 | 685 | 4497 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 52 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 53 | `global_proto_decls_delete` | 0.0% | 1/4158 | 309 | 4158 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 54 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 55 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 56 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 57 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 58 | `geturl` | 0.0% | 0/7 | 0 | 7 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 59 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 60 | `interface_implements_op` | 0.0% | 0/47 | 46 | 47 | [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 61 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 62 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 63 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 64 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 65 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 66 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 67 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 68 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

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
| 14 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 6 | 1 |
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
