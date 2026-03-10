# Ruffle Test Results (Filtered)

**Date**: 2026-03-10 01:19 UTC

**Git SHA**: `e40afd5265`

**Run Duration**: 149m 19s

**Filtered**: 141 tests ignored out of 618 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 477 |
| Passing | **426** (89.3%) |
| Failing | 51 |
| Total expected lines | 71703 |
| Matching lines | 59271 (82.7%) |
| Mismatched lines | 12432 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 46 | 90.2% |
| Runtime Error | 4 | 7.8% |
| Compile Fail | 1 | 2.0% |

## Passing Tests

**426 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 15.6s |  |
| 2 | `action_to_integer` | 28 | 14.1s |  |
| 3 | `add` | 28 | 14.1s |  |
| 4 | `add2` | 354 | 14.2s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 14.1s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 14.0s |  |
| 7 | `add_swf5` | 28 | 14.1s |  |
| 8 | `arguments` | 127 | 14.0s | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [39](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 14.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 13.9s |  |
| 11 | `array_constructor` | 30 | 14.0s |  |
| 12 | `array_enumerate` | 4 | 13.9s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 14.1s |  |
| 14 | `array_properties` | 36 | 13.9s |  |
| 15 | `array_prototyping` | 12 | 14.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 14.1s |  |
| 17 | `array_sort_random` | 443 | 14.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 14.1s |  |
| 19 | `array_trivial` | 209 | 14.2s |  |
| 20 | `as1_constructor_v6` | 35 | 14.0s |  |
| 21 | `as1_constructor_v7` | 35 | 14.3s |  |
| 22 | `as2_oop` | 13 | 14.3s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 14.2s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 14.1s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 14.1s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster` | 41 | 14.1s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 14.0s |  |
| 28 | `as_broadcaster_undef` | 89 | 14.2s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 29 | `as_set_prop_flags` | 79 | 14.2s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version` | 31 | 14.0s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version_swf5` | 1 | 14.0s |  |
| 32 | `as_set_prop_flags_version_swf6` | 1 | 14.0s |  |
| 33 | `as_set_prop_flags_version_swf7` | 1 | 14.1s |  |
| 34 | `as_set_prop_flags_version_swf8` | 1 | 14.0s |  |
| 35 | `as_set_prop_flags_version_swf9` | 1 | 14.2s |  |
| 36 | `as_transformed_flag` | 20 | 13.9s |  |
| 37 | `asnative` | 34 | 13.9s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 38 | `asnew` | 34 | 14.0s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `attach_movie` | 59 | 14.6s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 40 | `attach_movie_stop` | 3 | 14.0s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 41 | `bad_placeobject_clipaction` | 2 | 15.9s |  |
| 42 | `bad_swf_tag_past_eof` | 0 | 14.2s |  |
| 43 | `bitand` | 1058 | 17.1s |  |
| 44 | `bitmap_data_colortransform` | 0 | 14.5s |  |
| 45 | `bitmap_data_fillrect` | 0 | 14.3s |  |
| 46 | `bitmap_data_max_size_swf10` | 12 | 14.1s |  |
| 47 | `bitmap_data_max_size_swf9` | 10 | 14.0s |  |
| 48 | `bitmap_data_perlinnoise` | 0 | 14.8s |  |
| 49 | `bitmap_data_pixeldissolve_image` | 0 | 14.4s |  |
| 50 | `bitmapdata_applyfilter_colormatrix` | 0 | 14.4s |  |
| 51 | `bitor` | 1058 | 17.2s |  |
| 52 | `biturshift` | 14 | 14.2s |  |
| 53 | `biturshift_swf8` | 14 | 16.2s |  |
| 54 | `bitxor` | 1058 | 16.9s |  |
| 55 | `boxed_primitives` | 24 | 14.1s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 56 | `button_children` | 8 | 14.0s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_goto` | 4 | 14.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_order` | 2 | 13.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_properties_special_cases` | 22 | 14.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_v5` | 18 | 13.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_v6` | 18 | 14.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `call` | 63 | 14.2s | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 63 | `call_method_empty_name` | 1 | 14.0s |  |
| 64 | `capabilities_resolution` | 8 | 13.9s |  |
| 65 | `catch_references_registers` | 2 | 13.9s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 66 | `clip_constructors` | 8 | 14.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 67 | `clip_events` | 19 | 14.2s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 68 | `clone_sprite_types` | 24 | 13.9s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 69 | `closure_scope` | 7 | 13.9s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 70 | `coerce_to_primitive_resolve` | 17 | 13.9s | [40](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 71 | `color` | 57 | 14.1s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 72 | `color_transform` | 48 | 13.9s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 73 | `conflicting_instance_names` | 23 | 13.9s |  |
| 74 | `constructor_function` | 2 | 13.7s |  |
| 75 | `context_menu` | 39 | 13.9s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 76 | `context_menu_item` | 41 | 14.0s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 77 | `create_empty_movie_clip` | 3 | 13.7s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 78 | `custom_clip_methods` | 4 | 14.1s | [10](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 79 | `default_names` | 52 | 13.9s | [12](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 80 | `define_function2` | 8 | 13.8s |  |
| 81 | `define_function2_preload` | 13 | 13.8s |  |
| 82 | `define_function2_preload_order` | 4 | 14.5s |  |
| 83 | `define_function_case_sensitive` | 2 | 14.1s |  |
| 84 | `define_local` | 27 | 14.6s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 85 | `define_local_with_paths` | 54 | 14.3s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 86 | `delete` | 3 | 14.5s |  |
| 87 | `device_font_spacing` | 91 | 14.1s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 88 | `display_object_properties` | 2 | 14.1s |  |
| 89 | `divide_swf4` | 107 | 14.4s |  |
| 90 | `do_init_action` | 3 | 14.1s |  |
| 91 | `do_init_action_child` | 12 | 14.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 92 | `duplicate_movie_clip` | 20 | 14.0s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 93 | `duplicate_movie_clip_drawing` | 2 | 13.9s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 94 | `edittext_align` | 60 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 95 | `edittext_align_trailing_spaces_swf7` | 576 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 96 | `edittext_align_trailing_spaces_swf8` | 576 | 13.9s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 97 | `edittext_antialiastype` | 296 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 98 | `edittext_autosize` | 71 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 99 | `edittext_autosize_setter` | 20 | 14.7s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_default_format` | 221 | 14.5s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_default_format_font_style` | 335 | 14.3s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_font_size` | 45 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_hscroll` | 27 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_html_align_swf7` | 52 | 14.4s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_html_align_swf8` | 52 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_html_color` | 114 | 14.3s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_html_condensewhite_swf7` | 311 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_html_condensewhite_swf8` | 311 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_html_entity` | 4 | 14.0s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_html_roundtrip` | 17 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_html_swf7` | 5377 | 15.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_html_swf8` | 5377 | 15.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_leading` | 9 | 13.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_letter_spacing` | 15 | 13.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_margins` | 25 | 13.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_newline_stripping` | 64 | 18.3s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_programmatic_focus` | 12 | 13.7s | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_restrict` | 191 | 13.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_stylesheet` | 325 | 14.4s | [51](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_tag_indent` | 31 | 13.7s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_text_height_leading` | 20 | 13.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_underline` | 40 | 13.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_width_height` | 103 | 13.7s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `empty_movieclip_can_attach_movies` | 11 | 14.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 125 | `enumerate` | 64 | 14.1s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 126 | `equals` | 32 | 14.0s |  |
| 127 | `equals2_swf5` | 926 | 15.8s |  |
| 128 | `equals2_swf6` | 926 | 15.7s |  |
| 129 | `equals2_swf7` | 926 | 16.0s |  |
| 130 | `equals_swf4` | 665 | 15.2s |  |
| 131 | `equals_swf4_alt` | 32 | 14.2s |  |
| 132 | `equals_swf5` | 32 | 14.3s |  |
| 133 | `error` | 58 | 14.1s |  |
| 134 | `escape` | 14 | 14.0s |  |
| 135 | `execution_order1` | 5 | 14.2s |  |
| 136 | `execution_order2` | 7 | 14.1s |  |
| 137 | `execution_order3` | 4 | 14.0s |  |
| 138 | `execution_order4` | 12 | 14.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 139 | `export_assets` | 3 | 14.1s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 140 | `extends_chain` | 134 | 14.7s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 141 | `extends_native_type` | 11 | 14.3s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 142 | `external_interface` | 84 | 14.3s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 143 | `external_interface_escapexml` | 26 | 14.1s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 144 | `external_interface_jsquotestring` | 21 | 14.3s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 145 | `external_interface_toas_basic` | 354 | 16.2s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 146 | `external_interface_toxml_array` | 25 | 14.0s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 147 | `external_interface_toxml_basic` | 179 | 14.3s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 148 | `external_interface_unescapexml` | 40 | 14.2s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 149 | `focusrect_mouse_swf8` | 0 | 13.9s |  |
| 150 | `focusrect_mouse_swf9` | 0 | 15.3s |  |
| 151 | `focusrect_swf5` | 6 | 14.5s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 152 | `frame_size_translated_negative` | 21 | 14.4s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 153 | `frame_size_translated_positive` | 21 | 14.3s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 154 | `function_as_function` | 35 | 14.4s | [19](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 155 | `function_base_clip` | 8 | 14.4s |  |
| 156 | `function_base_clip_readded` | 11 | 14.4s |  |
| 157 | `function_base_clip_removed` | 25 | 14.4s |  |
| 158 | `function_suppress_and_preload` | 28 | 14.3s |  |
| 159 | `funky_function_calls` | 56 | 14.5s | [19](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 160 | `get_bytes_total` | 4 | 14.3s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 161 | `get_variable_in_scope` | 29 | 14.3s |  |
| 162 | `getproperty` | 28 | 14.2s |  |
| 163 | `getproperty_swf4` | 28 | 15.8s |  |
| 164 | `getproperty_swf5` | 28 | 14.0s |  |
| 165 | `gettextextent` | 56 | 14.2s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 166 | `global_array` | 3 | 14.1s |  |
| 167 | `global_is_bare` | 7 | 14.0s |  |
| 168 | `global_swf6_7_8` | 15 | 14.9s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 169 | `globals_swf5` | 304 | 15.0s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 170 | `globals_swf6` | 304 | 14.9s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 171 | `globals_swf7` | 304 | 15.4s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 172 | `globals_swf8` | 304 | 15.1s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 173 | `goto_advance1` | 6 | 14.7s |  |
| 174 | `goto_advance2` | 2 | 14.2s |  |
| 175 | `goto_both_ways1` | 3 | 14.2s |  |
| 176 | `goto_both_ways2` | 3 | 14.3s |  |
| 177 | `goto_execution_order` | 2 | 14.3s |  |
| 178 | `goto_execution_order2` | 2 | 14.3s |  |
| 179 | `goto_frame` | 12 | 16.4s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 180 | `goto_frame2` | 44 | 15.8s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 181 | `goto_frame_number` | 3 | 15.2s |  |
| 182 | `goto_label` | 17 | 15.3s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 183 | `goto_methods` | 40 | 15.7s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 184 | `goto_rewind1` | 1 | 15.8s |  |
| 185 | `goto_rewind2` | 3 | 15.8s |  |
| 186 | `goto_rewind3` | 2 | 15.6s |  |
| 187 | `greater_swf6` | 1175 | 17.8s |  |
| 188 | `greater_swf7` | 1175 | 17.5s |  |
| 189 | `greaterthan_swf5` | 1 | 15.4s |  |
| 190 | `greaterthan_swf8` | 1 | 15.5s |  |
| 191 | `has_own_property` | 32 | 15.3s |  |
| 192 | `hittest_lockroot` | 15 | 15.4s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 193 | `hittest_morph` | 70 | 15.2s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 194 | `hittest_winding_rule` | 12 | 15.2s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 195 | `infinite_recursion_function` | 4 | 15.0s | [24](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 196 | `infinite_recursion_function_in_setter` | 131 | 15.1s | [24](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 197 | `infinite_recursion_virtual_property` | 67 | 15.0s | [24](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 198 | `init_array_invalid` | 4 | 14.8s |  |
| 199 | `init_object_invalid` | 4 | 14.1s |  |
| 200 | `init_object_order` | 15 | 14.2s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 201 | `instanceof_coercions` | 88 | 14.3s | [61](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 202 | `interface_implements_op` | 47 | 14.5s | [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 203 | `is_finite` | 49 | 14.0s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 204 | `is_finite_swf6` | 49 | 13.9s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 205 | `is_prototype_of` | 89 | 14.1s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 206 | `issue_1086` | 1 | 14.0s |  |
| 207 | `issue_1104` | 2 | 13.9s | [14](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 208 | `issue_1671` | 0 | 13.9s |  |
| 209 | `issue_1906` | 4 | 14.1s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 210 | `issue_2166` | 9 | 13.9s |  |
| 211 | `issue_3169` | 2 | 14.0s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 212 | `issue_3446` | 1 | 13.8s |  |
| 213 | `issue_3522` | 2 | 13.9s |  |
| 214 | `issue_4377` | 2 | 13.8s |  |
| 215 | `issue_710` | 4 | 13.9s |  |
| 216 | `issue_768` | 3 | 14.3s | [25](ruffle-tests/_investigation/complete/issue_768.md) |
| 217 | `issue_9327` | 2 | 14.2s |  |
| 218 | `issue_9885` | 2 | 14.2s |  |
| 219 | `lessthan` | 41 | 14.3s |  |
| 220 | `lessthan2_swf5` | 1226 | 16.7s |  |
| 221 | `lessthan2_swf6` | 1226 | 16.7s |  |
| 222 | `lessthan2_swf7` | 1226 | 16.4s |  |
| 223 | `lessthan_swf4` | 902 | 15.5s |  |
| 224 | `lessthan_swf4_alt` | 41 | 14.7s |  |
| 225 | `lessthan_swf5` | 41 | 14.5s |  |
| 226 | `local_to_global` | 49 | 13.6s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 227 | `localconnection_properties` | 8 | 13.4s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 228 | `lock_root` | 1 | 13.5s |  |
| 229 | `logical_ops_swf4` | 90 | 13.5s |  |
| 230 | `logical_ops_swf8` | 108 | 13.6s |  |
| 231 | `looping` | 6 | 13.6s |  |
| 232 | `mask_reapply` | 0 | 13.6s |  |
| 233 | `mask_with_drawing` | 0 | 13.6s |  |
| 234 | `math_min_max` | 101 | 13.7s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 235 | `math_swf6` | 530 | 14.1s | [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 236 | `math_swf7` | 530 | 14.0s | [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 237 | `math_swf8` | 530 | 14.0s | [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 238 | `matrix` | 171 | 13.9s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 239 | `movieclip_begin_gradient_fill` | 0 | 14.8s |  |
| 240 | `movieclip_blend_mode_property` | 35 | 14.1s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 241 | `movieclip_create_text_field` | 90 | 14.1s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 242 | `movieclip_default_state` | 69 | 14.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 243 | `movieclip_depth_methods` | 98 | 14.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 244 | `movieclip_focusenabled` | 99 | 14.2s | [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 245 | `movieclip_get_instance_at_depth` | 28 | 14.0s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 246 | `movieclip_getbounds` | 191 | 14.1s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 247 | `movieclip_gettextsnapshot` | 112 | 14.1s | [21](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 248 | `movieclip_hittest` | 92 | 14.1s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 249 | `movieclip_init_object` | 5 | 14.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 250 | `movieclip_line_gradient_style` | 0 | 14.4s |  |
| 251 | `movieclip_lockroot` | 29 | 14.3s | [29](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 252 | `movieclip_name_from_timeline` | 13 | 13.9s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 253 | `movieclip_prototype_extension` | 5 | 13.8s |  |
| 254 | `movieclip_setmask` | 14 | 14.0s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 255 | `mutable_this` | 18 | 13.9s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 256 | `named_shapes` | 14 | 13.9s |  |
| 257 | `nan_scale` | 9 | 13.9s |  |
| 258 | `native_double_construct` | 12 | 14.1s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 259 | `native_objects_swf7` | 84 | 14.4s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 260 | `native_objects_swf8` | 84 | 14.4s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 261 | `nested_textfields_in_buttons` | 0 | 13.9s |  |
| 262 | `new_method_wrap` | 4 | 13.9s |  |
| 263 | `new_object_enumerate` | 7 | 13.7s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 264 | `new_object_wrap` | 4 | 13.7s |  |
| 265 | `o` | 3 | 13.6s |  |
| 266 | `object_constructor` | 33 | 13.8s |  |
| 267 | `object_function` | 32 | 13.8s |  |
| 268 | `object_properties` | 31 | 13.9s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 269 | `object_prototypes` | 74 | 13.7s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 270 | `object_resolve` | 38 | 13.8s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 271 | `object_string_coerce_swf5` | 62 | 13.7s | [36](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 272 | `object_string_coerce_swf6` | 68 | 13.8s | [36](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 273 | `on_construct` | 25 | 13.8s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 274 | `parse_float` | 74 | 13.8s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 275 | `parse_int` | 64 | 14.0s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 276 | `path_string` | 322 | 13.9s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 277 | `place_and_lookup` | 30 | 13.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 278 | `placeobject_occupied_depth` | 6 | 13.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 279 | `point` | 175 | 14.1s | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 280 | `primitive_instanceof` | 37 | 13.6s |  |
| 281 | `primitive_type_globals` | 557 | 13.7s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 282 | `printjob_props_swf5` | 45 | 14.5s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 283 | `printjob_props_swf6` | 45 | 14.2s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 284 | `printjob_props_swf7` | 45 | 14.1s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 285 | `property_invalid_base_clip` | 36 | 14.1s |  |
| 286 | `prototype_delete` | 12 | 13.9s |  |
| 287 | `prototype_enumerate` | 5 | 14.0s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 288 | `prototype_properties` | 17 | 13.9s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 289 | `rectangle` | 745 | 14.7s | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 290 | `recursive_prototypes` | 0 | 13.8s |  |
| 291 | `register_class_return_value` | 16 | 14.0s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 292 | `register_class_with_sound` | 11 | 14.1s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 293 | `register_globals_across_frames` | 15 | 13.9s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 294 | `register_underflow` | 26 | 13.9s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 295 | `remove_movie_clip` | 29 | 14.0s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 296 | `removed_clip_halts_script` | 15 | 14.5s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [44](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 297 | `resolve_different_root` | 2 | 17.0s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 298 | `rewind_depth` | 30 | 13.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 299 | `root_global_parent` | 6 | 13.8s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 300 | `sandbox_type_local_file` | 1 | 13.8s |  |
| 301 | `sandbox_type_local_network` | 1 | 13.7s |  |
| 302 | `selection` | 454 | 14.0s | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 303 | `set_interval` | 27 | 14.0s | [59](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 304 | `set_variable_scope` | 58 | 14.0s |  |
| 305 | `single_frame` | 1 | 14.3s |  |
| 306 | `slash_syntax` | 14 | 14.3s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 307 | `sound` | 628 | 14.3s | [46](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 308 | `sound_props_swf5` | 68 | 14.4s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 309 | `sound_props_swf6` | 68 | 14.0s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 310 | `sound_start_load` | 0 | 14.1s |  |
| 311 | `stage_display_state` | 16 | 14.3s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 312 | `stage_object_children` | 83 | 14.7s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 313 | `stage_object_enumerate` | 4 | 14.3s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 314 | `stage_object_properties` | 241 | 14.9s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 315 | `stage_object_properties_get_var` | 5 | 14.6s |  |
| 316 | `stage_object_properties_swf6` | 231 | 15.4s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 317 | `stage_property_representation` | 586 | 14.8s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 318 | `stage_scale_mode` | 39 | 14.6s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 319 | `strictequals_swf6` | 902 | 15.8s |  |
| 320 | `strictly_equals` | 7 | 14.3s |  |
| 321 | `string_coercion` | 117 | 14.7s | [49](ruffle-tests/_investigation/complete/string_coercion.md) |
| 322 | `string_methods` | 285 | 14.7s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 323 | `string_methods_negative_args` | 240 | 14.4s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 324 | `string_methods_swfv5` | 275 | 15.1s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 325 | `string_ops_swf6` | 95 | 14.2s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 326 | `string_paths_basic` | 4 | 14.5s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 327 | `string_paths_eval2` | 7 | 15.7s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 328 | `string_paths_hidden` | 54 | 13.9s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 329 | `string_paths_other` | 36 | 13.8s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 330 | `string_paths_unload` | 1 | 13.8s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 331 | `string_paths_variable_alias` | 4 | 13.7s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 332 | `string_paths_variable_scopes` | 5 | 13.8s | [14](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 333 | `stylesheet` | 283 | 14.6s |  |
| 334 | `stylesheet_transform` | 750 | 14.6s |  |
| 335 | `super_edge_cases` | 39 | 14.0s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 336 | `swf4_actions_bool` | 96 | 13.8s |  |
| 337 | `swf4_actions_coercion_order` | 158 | 14.0s | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 338 | `swf4_bool` | 4 | 13.7s |  |
| 339 | `swf4_function_calls` | 7 | 13.8s |  |
| 340 | `swf5_encoding` | 3 | 13.8s |  |
| 341 | `swf5_global_funcs` | 232 | 13.8s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 342 | `swf5_no_closure` | 19 | 13.7s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 343 | `swf6_case_insensitive` | 42 | 13.1s | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 344 | `swf6_global_funcs` | 232 | 13.5s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 345 | `swf6_string_as_bool` | 15 | 13.5s | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 346 | `swf7_case_sensitive` | 44 | 13.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 347 | `swf7_global_funcs` | 232 | 13.3s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 348 | `tab_ordering_properties_tab_index_edge_case` | 4 | 14.4s |  |
| 349 | `target_clip_removed` | 5 | 14.2s | [44](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 350 | `target_clip_swf5` | 2 | 14.0s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 351 | `target_clip_swf6` | 2 | 14.2s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 352 | `target_path` | 14 | 14.0s |  |
| 353 | `tell_target` | 37 | 14.1s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 354 | `tell_target_invalid` | 6 | 14.2s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 355 | `tell_target_invalid_swf6` | 5 | 14.2s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 356 | `text_format` | 1146 | 14.3s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 357 | `text_format_display` | 21 | 14.3s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 358 | `text_format_font_max_length` | 2 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 359 | `text_format_get_text_extent_undefined_width` | 10 | 14.0s |  |
| 360 | `text_format_rounding_swf7` | 840 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 361 | `text_format_rounding_swf8` | 840 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 362 | `textfield_background_color` | 11 | 14.0s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 363 | `textfield_border_color` | 11 | 14.0s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 364 | `textfield_cache_as_bitmap` | 1 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 365 | `textfield_maxchars` | 3 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 366 | `textfield_properties` | 44 | 13.9s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 367 | `textfield_props_swf5` | 175 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 368 | `textfield_props_swf6` | 210 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 369 | `textfield_props_swf7` | 210 | 14.3s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 370 | `textfield_props_swf8` | 210 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 371 | `textfield_text` | 7 | 13.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 372 | `textfield_variable` | 81 | 14.0s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 373 | `textsnapshot_props_swf5` | 56 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 374 | `textsnapshot_props_swf6` | 56 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 375 | `this_scoping` | 52 | 14.0s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 376 | `this_swf5` | 41 | 13.8s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 377 | `this_swf6` | 41 | 13.8s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 378 | `this_swf7` | 41 | 13.7s | [58](ruffle-tests/_investigation/complete/this_swf7.md) |
| 379 | `timeline_function_def` | 7 | 13.9s |  |
| 380 | `trace` | 8 | 14.1s |  |
| 381 | `transform` | 70 | 14.3s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 382 | `try_catch_finally` | 118 | 14.3s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 383 | `try_finally_simple` | 16 | 14.1s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 384 | `typeof` | 22 | 14.2s |  |
| 385 | `typeof_globals` | 7 | 14.1s |  |
| 386 | `uncaught_exception` | 1 | 14.2s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 387 | `uncaught_exception_bubbled` | 1 | 14.3s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 388 | `undefined_to_string_swf6` | 4 | 14.2s |  |
| 389 | `unescape` | 43 | 14.4s |  |
| 390 | `unload` | 52 | 14.7s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 391 | `unload_clip_event` | 4 | 14.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 392 | `use_hand_cursor` | 8 | 14.2s |  |
| 393 | `variable_args` | 5 | 14.3s |  |
| 394 | `waitforframe` | 7 | 14.2s |  |
| 395 | `waitforframe2` | 16 | 15.8s |  |
| 396 | `watch` | 117 | 14.1s | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 397 | `watch_textfield` | 12 | 13.8s | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 398 | `watch_virtual_property_proto` | 2 | 13.9s | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 399 | `with` | 49 | 13.8s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 400 | `with_return` | 2 | 13.8s |  |
| 401 | `with_variable_scopes` | 43 | 13.8s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 402 | `xml` | 15 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 403 | `xml_append_child` | 28 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 404 | `xml_append_child_with_parent` | 20 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 405 | `xml_cdata` | 11 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 406 | `xml_child_nodes_edge_cases` | 4 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 407 | `xml_clone_expandos` | 19 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 408 | `xml_first_last_child` | 8 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 409 | `xml_has_child_nodes` | 3 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 410 | `xml_idmap` | 21 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 411 | `xml_ignore_comments` | 21 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 412 | `xml_ignore_white` | 34 | 14.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 413 | `xml_insert_before` | 20 | 14.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 414 | `xml_inspect_createmethods` | 15 | 14.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 415 | `xml_inspect_doctype` | 7 | 14.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 416 | `xml_inspect_parsexml` | 62 | 14.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 417 | `xml_inspect_xmldecl` | 7 | 14.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 418 | `xml_namespaces` | 203 | 14.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 419 | `xml_parent_and_child` | 5 | 14.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 420 | `xml_remove_node` | 22 | 14.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 421 | `xml_reparenting` | 14 | 14.7s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 422 | `xml_siblings` | 10 | 14.5s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 423 | `xml_to_string` | 13 | 14.0s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 424 | `xml_to_string_comment` | 1 | 14.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 425 | `xml_unescaping` | 23 | 14.3s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 426 | `xmlnode_proto` | 1 | 14.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**15 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `removed_target_clip_scope` | 97.1% | 34 | 35 | 1 | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 2 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 3 | `global_swf5_6_7_8_9` | 93.7% | 1073 | 1145 | 72 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 4 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `selection_handlers` | 77.8% | 21 | 27 | 6 | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 6 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `register_class` | 71.6% | 48 | 67 | 19 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 9 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 10 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 11 | `movieclip_in_removed_button` | 60.0% | 3 | 5 | 2 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 12 | `textsnapshot_findtext` | 59.1% | 26 | 44 | 18 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 13 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [61](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 14 | `issue_2030` | 50.0% | 2 | 4 | 2 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 15 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_1` | exit code -6 | 14.4s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_2` | exit code -6 | 14.7s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `movieclip_invalid_get_bounds_6` | exit code -6 | 39.5s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_invalid_get_bounds_7` | exit code -6 | 39.9s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

No timeouts.

## All Output Mismatches

**46 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `removed_target_clip_scope` | 97.1% | 34/35 | 35 | 35 | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 2 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 3 | `global_swf5_6_7_8_9` | 93.7% | 1073/1145 | 1145 | 1145 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 4 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `selection_handlers` | 77.8% | 21/27 | 23 | 27 | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 6 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `register_class` | 71.6% | 48/67 | 67 | 66 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 9 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 10 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 11 | `movieclip_in_removed_button` | 60.0% | 3/5 | 5 | 4 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 12 | `textsnapshot_findtext` | 59.1% | 26/44 | 44 | 44 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 13 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [61](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 14 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 15 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 16 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 17 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 18 | `movieclip_state_values` | 34.2% | 39/114 | 55 | 114 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 19 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 20 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 21 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 22 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 23 | `timer_run_actions` | 16.7% | 3/18 | 17 | 18 | [59](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 24 | `register_and_init_order` | 15.6% | 36/231 | 154 | 231 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 25 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 26 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 27 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 28 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 29 | `textsnapshot_gettext` | 9.1% | 5/55 | 55 | 55 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 30 | `register_class_swf6` | 8.1% | 3/37 | 37 | 37 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 31 | `global_instance_decls` | 1.6% | 12/758 | 482 | 758 | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 32 | `global_proto_decls` | 0.2% | 11/4497 | 692 | 4497 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 33 | `global_proto_decls_delete` | 0.0% | 1/4158 | 310 | 4158 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 34 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [19](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 35 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 36 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 37 | `geturl` | 0.0% | 0/7 | 0 | 7 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 38 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 39 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 40 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 41 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 42 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 43 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 44 | `string_paths_timer` | 0.0% | 0/41 | 41 | 0 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 45 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 46 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 3 | 3 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 8 | 6 | 2 |
| 6 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 1 | 1 |
| 7 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 5 | 3 |
| 8 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 1 | 1 | 0 |
| 9 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 10 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 11 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 0 | 0 | 0 |
| 12 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 13 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 0 | 0 | 0 |
| 14 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 15 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 16 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 17 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 1 | 1 | 0 |
| 18 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 19 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 20 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 5 | 4 | 1 |
| 21 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 22 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 29 | 25 | 4 |
| 23 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 16 | 6 | 10 |
| 24 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 25 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 26 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 16 | 2 | 14 |
| 27 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 1 | 0 | 1 |
| 28 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 0 | 0 | 0 |
| 29 | [LOCKROOT_PLAN.md](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 30 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 31 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 32 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 0 | 0 | 0 |
| 33 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 56 | 38 | 18 |
| 34 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 0 | 0 | 0 |
| 35 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 14 | 14 | 0 |
| 36 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 37 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 38 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 39 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 40 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 41 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 42 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 12 | 3 |
| 43 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 0 | 0 | 0 |
| 44 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 45 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 3 | 2 | 1 |
| 46 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 47 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 48 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 49 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 50 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 51 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 52 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 3 | 3 | 0 |
| 53 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) | 1 | 1 | 0 |
| 54 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 18 | 15 | 3 |
| 55 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 57 | 49 | 8 |
| 56 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 0 | 4 |
| 57 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 58 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 59 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 2 | 1 | 1 |
| 60 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 61 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 1 | 1 |
| 62 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 7 | 9 |
| 63 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 9 | 7 | 2 |
| 64 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 65 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 25 | 25 | 0 |
| | *(tests not in any document)* | 154 | 153 | 1 |
