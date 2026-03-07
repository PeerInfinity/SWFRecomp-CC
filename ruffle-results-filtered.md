# Ruffle Test Results (Filtered)

**Date**: 2026-03-07 17:47 UTC

**Git SHA**: `75d8078792`

**Run Duration**: 143m 43s

**Filtered**: 142 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 477 |
| Passing | **423** (88.7%) |
| Failing | 54 |
| Total expected lines | 71793 |
| Matching lines | 59298 (82.6%) |
| Mismatched lines | 12495 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 49 | 90.7% |
| Runtime Error | 4 | 7.4% |
| Compile Fail | 1 | 1.9% |

## Passing Tests

**423 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 15.2s |  |
| 2 | `action_to_integer` | 28 | 13.8s |  |
| 3 | `add` | 28 | 13.7s |  |
| 4 | `add2` | 354 | 13.8s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 13.6s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 13.7s |  |
| 7 | `add_swf5` | 28 | 13.5s |  |
| 8 | `arguments` | 127 | 13.5s | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [39](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 13.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 13.5s |  |
| 11 | `array_constructor` | 30 | 13.6s |  |
| 12 | `array_enumerate` | 4 | 13.6s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 13.7s |  |
| 14 | `array_properties` | 36 | 13.5s |  |
| 15 | `array_prototyping` | 12 | 13.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 13.6s |  |
| 17 | `array_sort_random` | 443 | 14.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 14.2s |  |
| 19 | `array_trivial` | 209 | 14.1s |  |
| 20 | `as1_constructor_v6` | 35 | 14.2s |  |
| 21 | `as1_constructor_v7` | 35 | 13.8s |  |
| 22 | `as2_oop` | 13 | 13.9s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 14.0s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 13.9s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 13.9s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster` | 41 | 13.8s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 13.6s |  |
| 28 | `as_broadcaster_undef` | 89 | 13.8s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 29 | `as_set_prop_flags` | 79 | 13.8s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version` | 31 | 13.8s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version_swf5` | 1 | 13.7s |  |
| 32 | `as_set_prop_flags_version_swf6` | 1 | 13.7s |  |
| 33 | `as_set_prop_flags_version_swf7` | 1 | 13.7s |  |
| 34 | `as_set_prop_flags_version_swf8` | 1 | 13.7s |  |
| 35 | `as_set_prop_flags_version_swf9` | 1 | 13.7s |  |
| 36 | `as_transformed_flag` | 20 | 13.7s |  |
| 37 | `asnative` | 34 | 13.7s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 38 | `asnew` | 34 | 13.7s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `attach_movie` | 59 | 13.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 40 | `attach_movie_stop` | 3 | 13.7s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 41 | `bad_placeobject_clipaction` | 2 | 13.8s |  |
| 42 | `bad_swf_tag_past_eof` | 0 | 13.3s |  |
| 43 | `bitand` | 1058 | 15.9s |  |
| 44 | `bitmap_data_colortransform` | 0 | 13.6s |  |
| 45 | `bitmap_data_fillrect` | 0 | 13.4s |  |
| 46 | `bitmap_data_max_size_swf10` | 12 | 13.3s |  |
| 47 | `bitmap_data_max_size_swf9` | 10 | 13.3s |  |
| 48 | `bitmap_data_perlinnoise` | 0 | 14.1s |  |
| 49 | `bitmap_data_pixeldissolve_image` | 0 | 13.8s |  |
| 50 | `bitmapdata_applyfilter_colormatrix` | 0 | 13.5s |  |
| 51 | `bitor` | 1058 | 15.8s |  |
| 52 | `biturshift` | 14 | 13.2s |  |
| 53 | `biturshift_swf8` | 14 | 14.8s |  |
| 54 | `bitxor` | 1058 | 15.9s |  |
| 55 | `boxed_primitives` | 24 | 13.5s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 56 | `button_children` | 8 | 13.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_goto` | 4 | 13.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_order` | 2 | 13.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_properties_special_cases` | 22 | 13.6s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_v5` | 18 | 13.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_v6` | 18 | 13.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `call` | 63 | 14.6s | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) |
| 63 | `call_method_empty_name` | 1 | 13.4s |  |
| 64 | `capabilities_resolution` | 8 | 13.4s |  |
| 65 | `catch_references_registers` | 2 | 13.3s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 66 | `clip_constructors` | 8 | 13.5s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 67 | `clip_events` | 19 | 13.3s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 68 | `clone_sprite_types` | 24 | 13.1s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 69 | `closure_scope` | 7 | 13.2s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 70 | `coerce_to_primitive_resolve` | 17 | 13.1s | [40](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 71 | `color` | 57 | 13.3s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 72 | `color_transform` | 48 | 13.2s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 73 | `conflicting_instance_names` | 23 | 13.2s |  |
| 74 | `constructor_function` | 2 | 13.0s |  |
| 75 | `context_menu` | 39 | 13.1s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 76 | `context_menu_item` | 41 | 13.1s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 77 | `create_empty_movie_clip` | 3 | 13.0s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 78 | `custom_clip_methods` | 4 | 13.2s | [10](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 79 | `default_names` | 52 | 13.1s | [12](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 80 | `define_function2` | 8 | 13.0s |  |
| 81 | `define_function2_preload` | 13 | 13.0s |  |
| 82 | `define_function2_preload_order` | 4 | 15.5s |  |
| 83 | `define_function_case_sensitive` | 2 | 13.5s |  |
| 84 | `define_local` | 27 | 13.4s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 85 | `delete` | 3 | 13.5s |  |
| 86 | `device_font_spacing` | 91 | 13.5s | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 87 | `display_object_properties` | 2 | 13.8s |  |
| 88 | `divide_swf4` | 107 | 14.1s |  |
| 89 | `do_init_action` | 3 | 14.0s |  |
| 90 | `do_init_action_child` | 12 | 14.2s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 91 | `duplicate_movie_clip` | 20 | 13.9s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 92 | `duplicate_movie_clip_drawing` | 2 | 13.5s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 93 | `edittext_align` | 60 | 13.7s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 94 | `edittext_align_trailing_spaces_swf7` | 576 | 13.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 95 | `edittext_align_trailing_spaces_swf8` | 576 | 13.7s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 96 | `edittext_antialiastype` | 296 | 14.1s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `edittext_autosize` | 71 | 14.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 98 | `edittext_autosize_setter` | 20 | 14.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 99 | `edittext_default_format` | 221 | 13.8s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 100 | `edittext_default_format_font_style` | 335 | 13.8s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 101 | `edittext_font_size` | 45 | 13.9s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 102 | `edittext_hscroll` | 27 | 13.8s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 103 | `edittext_html_align_swf7` | 52 | 13.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 104 | `edittext_html_align_swf8` | 52 | 13.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 105 | `edittext_html_color` | 114 | 13.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 106 | `edittext_html_condensewhite_swf7` | 311 | 13.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 107 | `edittext_html_condensewhite_swf8` | 311 | 13.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 108 | `edittext_html_entity` | 4 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 109 | `edittext_html_roundtrip` | 17 | 13.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 110 | `edittext_html_swf7` | 5377 | 14.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 111 | `edittext_html_swf8` | 5377 | 14.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 112 | `edittext_leading` | 9 | 13.8s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 113 | `edittext_letter_spacing` | 15 | 13.9s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 114 | `edittext_margins` | 25 | 14.1s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 115 | `edittext_newline_stripping` | 64 | 18.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 116 | `edittext_programmatic_focus` | 12 | 13.7s | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 117 | `edittext_restrict` | 191 | 13.8s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 118 | `edittext_stylesheet` | 325 | 14.1s | [51](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 119 | `edittext_tag_indent` | 31 | 13.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 120 | `edittext_text_height_leading` | 20 | 13.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 121 | `edittext_underline` | 40 | 13.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 122 | `edittext_width_height` | 103 | 13.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 123 | `empty_movieclip_can_attach_movies` | 11 | 14.4s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 124 | `enumerate` | 64 | 13.8s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 125 | `equals` | 32 | 13.8s |  |
| 126 | `equals2_swf5` | 926 | 15.7s |  |
| 127 | `equals2_swf6` | 926 | 15.6s |  |
| 128 | `equals2_swf7` | 926 | 15.6s |  |
| 129 | `equals_swf4` | 665 | 14.5s |  |
| 130 | `equals_swf4_alt` | 32 | 13.7s |  |
| 131 | `equals_swf5` | 32 | 13.8s |  |
| 132 | `error` | 58 | 13.6s |  |
| 133 | `escape` | 14 | 13.6s |  |
| 134 | `execution_order1` | 5 | 13.8s |  |
| 135 | `execution_order2` | 7 | 13.9s |  |
| 136 | `execution_order3` | 4 | 13.8s |  |
| 137 | `execution_order4` | 12 | 13.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 138 | `export_assets` | 3 | 13.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 139 | `extends_chain` | 134 | 14.2s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 140 | `extends_native_type` | 11 | 13.9s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 141 | `external_interface` | 84 | 13.9s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 142 | `external_interface_escapexml` | 26 | 13.7s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 143 | `external_interface_jsquotestring` | 21 | 13.8s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 144 | `external_interface_toas_basic` | 354 | 15.9s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 145 | `external_interface_toxml_array` | 25 | 13.8s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 146 | `external_interface_toxml_basic` | 179 | 13.9s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 147 | `external_interface_unescapexml` | 40 | 13.8s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 148 | `focusrect_mouse_swf8` | 0 | 13.9s |  |
| 149 | `focusrect_mouse_swf9` | 0 | 13.6s |  |
| 150 | `focusrect_swf5` | 6 | 13.5s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 151 | `frame_size_translated_negative` | 21 | 13.3s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 152 | `frame_size_translated_positive` | 21 | 13.3s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 153 | `function_as_function` | 35 | 13.2s | [19](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 154 | `function_base_clip` | 8 | 13.2s |  |
| 155 | `function_base_clip_readded` | 11 | 13.4s |  |
| 156 | `function_base_clip_removed` | 25 | 13.4s |  |
| 157 | `function_suppress_and_preload` | 28 | 13.3s |  |
| 158 | `funky_function_calls` | 56 | 13.3s | [19](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 159 | `get_bytes_total` | 4 | 13.2s | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 160 | `get_variable_in_scope` | 29 | 13.3s |  |
| 161 | `getproperty` | 28 | 13.3s |  |
| 162 | `getproperty_swf4` | 28 | 13.6s |  |
| 163 | `getproperty_swf5` | 28 | 13.5s |  |
| 164 | `gettextextent` | 56 | 13.8s | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 165 | `global_array` | 3 | 13.6s |  |
| 166 | `global_is_bare` | 7 | 13.4s |  |
| 167 | `global_swf6_7_8` | 15 | 13.8s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 168 | `globals_swf5` | 304 | 13.6s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 169 | `globals_swf6` | 304 | 13.8s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 170 | `globals_swf7` | 304 | 14.0s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 171 | `globals_swf8` | 304 | 13.8s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 172 | `goto_advance1` | 6 | 13.6s |  |
| 173 | `goto_advance2` | 2 | 13.7s |  |
| 174 | `goto_both_ways1` | 3 | 13.7s |  |
| 175 | `goto_both_ways2` | 3 | 13.6s |  |
| 176 | `goto_execution_order` | 2 | 13.8s |  |
| 177 | `goto_execution_order2` | 2 | 13.7s |  |
| 178 | `goto_frame` | 12 | 13.8s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 179 | `goto_frame2` | 44 | 13.9s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 180 | `goto_frame_number` | 3 | 13.5s |  |
| 181 | `goto_label` | 17 | 13.6s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 182 | `goto_methods` | 40 | 13.4s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 183 | `goto_rewind1` | 1 | 13.3s |  |
| 184 | `goto_rewind2` | 3 | 13.3s |  |
| 185 | `goto_rewind3` | 2 | 13.5s |  |
| 186 | `greater_swf6` | 1175 | 15.5s |  |
| 187 | `greater_swf7` | 1175 | 15.4s |  |
| 188 | `greaterthan_swf5` | 1 | 13.4s |  |
| 189 | `greaterthan_swf8` | 1 | 13.4s |  |
| 190 | `has_own_property` | 32 | 13.4s |  |
| 191 | `hittest_lockroot` | 15 | 13.7s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 192 | `hittest_morph` | 70 | 13.8s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 193 | `hittest_winding_rule` | 12 | 13.5s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 194 | `infinite_recursion_function` | 4 | 13.4s | [24](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 195 | `infinite_recursion_function_in_setter` | 131 | 13.4s | [24](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 196 | `infinite_recursion_virtual_property` | 67 | 13.4s | [24](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 197 | `init_array_invalid` | 4 | 13.4s |  |
| 198 | `init_object_invalid` | 4 | 13.5s |  |
| 199 | `init_object_order` | 15 | 13.4s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 200 | `instanceof_coercions` | 88 | 13.6s | [61](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 201 | `is_finite` | 49 | 13.2s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 202 | `is_finite_swf6` | 49 | 13.3s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 203 | `is_prototype_of` | 89 | 13.3s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 204 | `issue_1086` | 1 | 13.2s |  |
| 205 | `issue_1104` | 2 | 13.2s | [14](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 206 | `issue_1671` | 0 | 13.3s |  |
| 207 | `issue_1906` | 4 | 13.2s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 208 | `issue_2166` | 9 | 13.2s |  |
| 209 | `issue_3169` | 2 | 13.2s | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 210 | `issue_3446` | 1 | 13.2s |  |
| 211 | `issue_3522` | 2 | 13.2s |  |
| 212 | `issue_4377` | 2 | 13.2s |  |
| 213 | `issue_710` | 4 | 13.2s |  |
| 214 | `issue_768` | 3 | 14.8s | [25](ruffle-tests/_investigation/complete/issue_768.md) |
| 215 | `issue_9327` | 2 | 13.5s |  |
| 216 | `issue_9885` | 2 | 13.6s |  |
| 217 | `lessthan` | 41 | 13.5s |  |
| 218 | `lessthan2_swf5` | 1226 | 15.6s |  |
| 219 | `lessthan2_swf6` | 1226 | 15.6s |  |
| 220 | `lessthan2_swf7` | 1226 | 15.6s |  |
| 221 | `lessthan_swf4` | 902 | 14.7s |  |
| 222 | `lessthan_swf4_alt` | 41 | 13.6s |  |
| 223 | `lessthan_swf5` | 41 | 13.6s |  |
| 224 | `local_to_global` | 49 | 13.7s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 225 | `localconnection_properties` | 8 | 13.7s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 226 | `lock_root` | 1 | 13.9s |  |
| 227 | `logical_ops_swf4` | 90 | 13.7s |  |
| 228 | `logical_ops_swf8` | 108 | 13.7s |  |
| 229 | `looping` | 6 | 13.7s |  |
| 230 | `mask_reapply` | 0 | 13.8s |  |
| 231 | `mask_with_drawing` | 0 | 13.7s |  |
| 232 | `math_min_max` | 101 | 13.9s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 233 | `math_swf6` | 530 | 14.0s | [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 234 | `math_swf7` | 530 | 14.1s | [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 235 | `math_swf8` | 530 | 14.1s | [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 236 | `matrix` | 171 | 14.3s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 237 | `movieclip_begin_gradient_fill` | 0 | 14.1s |  |
| 238 | `movieclip_blend_mode_property` | 35 | 13.9s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 239 | `movieclip_create_text_field` | 90 | 13.5s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 240 | `movieclip_default_state` | 69 | 14.6s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 241 | `movieclip_depth_methods` | 98 | 14.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 242 | `movieclip_focusenabled` | 99 | 14.7s | [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 243 | `movieclip_get_instance_at_depth` | 28 | 14.5s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 244 | `movieclip_gettextsnapshot` | 112 | 14.4s | [21](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 245 | `movieclip_hittest` | 92 | 13.6s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 246 | `movieclip_in_removed_button` | 4 | 13.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 247 | `movieclip_init_object` | 5 | 13.5s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 248 | `movieclip_line_gradient_style` | 0 | 15.8s |  |
| 249 | `movieclip_lockroot` | 29 | 13.7s | [29](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 250 | `movieclip_name_from_timeline` | 13 | 13.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 251 | `movieclip_prototype_extension` | 5 | 13.2s |  |
| 252 | `mutable_this` | 18 | 13.2s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 253 | `named_shapes` | 14 | 13.3s |  |
| 254 | `nan_scale` | 9 | 13.3s |  |
| 255 | `native_double_construct` | 12 | 13.4s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 256 | `native_objects_swf7` | 84 | 13.6s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 257 | `native_objects_swf8` | 84 | 13.7s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 258 | `nested_textfields_in_buttons` | 0 | 13.1s |  |
| 259 | `new_method_wrap` | 4 | 13.3s |  |
| 260 | `new_object_enumerate` | 7 | 13.3s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 261 | `new_object_wrap` | 4 | 13.3s |  |
| 262 | `o` | 3 | 13.3s |  |
| 263 | `object_constructor` | 33 | 13.3s |  |
| 264 | `object_function` | 32 | 13.2s |  |
| 265 | `object_properties` | 31 | 13.4s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 266 | `object_prototypes` | 74 | 13.4s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 267 | `object_resolve` | 38 | 13.5s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 268 | `object_string_coerce_swf5` | 62 | 13.5s | [36](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 269 | `object_string_coerce_swf6` | 68 | 13.4s | [36](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 270 | `on_construct` | 25 | 13.4s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 271 | `parse_float` | 74 | 13.3s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 272 | `parse_int` | 64 | 13.5s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 273 | `path_string` | 322 | 13.4s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 274 | `place_and_lookup` | 30 | 13.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 275 | `placeobject_occupied_depth` | 6 | 13.4s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 276 | `point` | 175 | 13.8s | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 277 | `primitive_instanceof` | 37 | 13.2s |  |
| 278 | `primitive_type_globals` | 557 | 14.2s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 279 | `printjob_props_swf5` | 45 | 13.8s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 280 | `printjob_props_swf6` | 45 | 13.8s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 281 | `printjob_props_swf7` | 45 | 13.7s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 282 | `property_invalid_base_clip` | 36 | 13.6s |  |
| 283 | `prototype_delete` | 12 | 13.6s |  |
| 284 | `prototype_enumerate` | 5 | 13.6s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 285 | `prototype_properties` | 17 | 13.8s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 286 | `rectangle` | 745 | 14.4s | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 287 | `recursive_prototypes` | 0 | 13.6s |  |
| 288 | `register_class_return_value` | 16 | 13.8s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 289 | `register_class_with_sound` | 11 | 14.0s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 290 | `register_globals_across_frames` | 15 | 13.7s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 291 | `register_underflow` | 26 | 13.6s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 292 | `remove_movie_clip` | 29 | 13.7s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 293 | `rewind_depth` | 30 | 13.9s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 294 | `root_global_parent` | 6 | 13.7s | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 295 | `sandbox_type_local_file` | 1 | 13.6s |  |
| 296 | `sandbox_type_local_network` | 1 | 13.8s |  |
| 297 | `selection` | 454 | 14.0s | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 298 | `set_interval` | 27 | 13.9s | [59](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 299 | `set_variable_scope` | 58 | 13.8s |  |
| 300 | `single_frame` | 1 | 13.7s |  |
| 301 | `slash_syntax` | 14 | 13.6s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 302 | `sound` | 628 | 13.9s | [46](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 303 | `sound_props_swf5` | 68 | 13.6s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 304 | `sound_props_swf6` | 68 | 13.7s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 305 | `sound_start_load` | 0 | 13.4s |  |
| 306 | `stage_display_state` | 16 | 13.7s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 307 | `stage_object_children` | 83 | 13.6s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 308 | `stage_object_enumerate` | 4 | 13.3s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 309 | `stage_object_properties` | 241 | 13.7s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 310 | `stage_object_properties_get_var` | 5 | 13.3s |  |
| 311 | `stage_object_properties_swf6` | 231 | 13.8s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 312 | `stage_property_representation` | 586 | 13.5s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 313 | `stage_scale_mode` | 39 | 13.8s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 314 | `strictequals_swf6` | 902 | 15.3s |  |
| 315 | `strictly_equals` | 7 | 13.8s |  |
| 316 | `string_coercion` | 117 | 14.1s | [49](ruffle-tests/_investigation/complete/string_coercion.md) |
| 317 | `string_methods` | 285 | 14.0s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 318 | `string_methods_negative_args` | 240 | 13.3s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 319 | `string_methods_swfv5` | 275 | 13.8s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 320 | `string_ops_swf6` | 95 | 13.3s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 321 | `string_paths_basic` | 4 | 13.3s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 322 | `string_paths_eval2` | 7 | 14.2s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 323 | `string_paths_hidden` | 54 | 13.8s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 324 | `string_paths_other` | 36 | 13.9s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 325 | `string_paths_unload` | 1 | 13.7s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 326 | `string_paths_variable_alias` | 4 | 13.6s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 327 | `string_paths_variable_scopes` | 5 | 13.9s | [14](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 328 | `stylesheet` | 283 | 14.6s |  |
| 329 | `stylesheet_transform` | 750 | 14.5s |  |
| 330 | `super_edge_cases` | 39 | 13.9s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 331 | `swf4_actions_bool` | 96 | 14.2s |  |
| 332 | `swf4_actions_coercion_order` | 158 | 13.9s | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 333 | `swf4_bool` | 4 | 13.8s |  |
| 334 | `swf4_function_calls` | 7 | 13.7s |  |
| 335 | `swf5_encoding` | 3 | 13.9s |  |
| 336 | `swf5_global_funcs` | 232 | 13.8s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 337 | `swf5_no_closure` | 19 | 13.8s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 338 | `swf6_case_insensitive` | 42 | 13.4s | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 339 | `swf6_global_funcs` | 232 | 13.4s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 340 | `swf6_string_as_bool` | 15 | 13.3s | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 341 | `swf7_case_sensitive` | 44 | 13.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 342 | `swf7_global_funcs` | 232 | 13.4s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 343 | `tab_ordering_properties_tab_index_edge_case` | 4 | 14.3s |  |
| 344 | `target_clip_swf5` | 2 | 13.4s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 345 | `target_clip_swf6` | 2 | 13.4s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 346 | `target_path` | 14 | 13.4s |  |
| 347 | `tell_target` | 37 | 13.6s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 348 | `tell_target_invalid` | 6 | 13.5s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 349 | `tell_target_invalid_swf6` | 5 | 13.6s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 350 | `text_format` | 1146 | 13.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 351 | `text_format_display` | 21 | 13.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 352 | `text_format_font_max_length` | 2 | 13.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 353 | `text_format_rounding_swf7` | 840 | 13.7s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 354 | `text_format_rounding_swf8` | 840 | 13.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 355 | `textfield_background_color` | 11 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 356 | `textfield_border_color` | 11 | 13.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 357 | `textfield_cache_as_bitmap` | 1 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 358 | `textfield_maxchars` | 3 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 359 | `textfield_properties` | 44 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 360 | `textfield_props_swf5` | 175 | 13.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 361 | `textfield_props_swf6` | 210 | 13.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 362 | `textfield_props_swf7` | 210 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 363 | `textfield_props_swf8` | 210 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 364 | `textfield_text` | 7 | 13.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 365 | `textfield_variable` | 81 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 366 | `textsnapshot_available_text` | 20 | 13.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 367 | `textsnapshot_findtext` | 44 | 13.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 368 | `textsnapshot_gettext` | 55 | 13.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 369 | `textsnapshot_props_swf5` | 56 | 13.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 370 | `textsnapshot_props_swf6` | 56 | 13.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 371 | `textsnapshot_text_order` | 1 | 13.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 372 | `this_scoping` | 52 | 13.3s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 373 | `this_swf5` | 41 | 13.1s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 374 | `this_swf6` | 41 | 13.2s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 375 | `this_swf7` | 41 | 13.2s | [58](ruffle-tests/_investigation/complete/this_swf7.md) |
| 376 | `timeline_function_def` | 7 | 13.2s |  |
| 377 | `trace` | 8 | 13.2s |  |
| 378 | `transform` | 70 | 13.3s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 379 | `try_catch_finally` | 118 | 13.4s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 380 | `try_finally_simple` | 16 | 13.2s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 381 | `typeof` | 22 | 13.3s |  |
| 382 | `typeof_globals` | 7 | 13.2s |  |
| 383 | `uncaught_exception` | 1 | 13.2s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 384 | `uncaught_exception_bubbled` | 1 | 13.2s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 385 | `undefined_to_string_swf6` | 4 | 13.2s |  |
| 386 | `unescape` | 43 | 13.3s |  |
| 387 | `unload` | 52 | 13.5s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 388 | `unload_clip_event` | 4 | 13.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 389 | `use_hand_cursor` | 8 | 13.2s |  |
| 390 | `variable_args` | 5 | 13.4s |  |
| 391 | `waitforframe` | 7 | 13.3s |  |
| 392 | `waitforframe2` | 16 | 15.5s |  |
| 393 | `watch` | 117 | 14.2s | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 394 | `watch_textfield` | 12 | 13.9s | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 395 | `watch_virtual_property_proto` | 2 | 14.0s | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 396 | `with` | 49 | 13.9s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 397 | `with_return` | 2 | 13.8s |  |
| 398 | `with_variable_scopes` | 43 | 14.0s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 399 | `xml` | 15 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 400 | `xml_append_child` | 28 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 401 | `xml_append_child_with_parent` | 20 | 14.3s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 402 | `xml_cdata` | 11 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 403 | `xml_child_nodes_edge_cases` | 4 | 13.6s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 404 | `xml_clone_expandos` | 19 | 13.7s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 405 | `xml_first_last_child` | 8 | 13.7s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 406 | `xml_has_child_nodes` | 3 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 407 | `xml_idmap` | 21 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 408 | `xml_ignore_comments` | 21 | 14.3s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 409 | `xml_ignore_white` | 34 | 14.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 410 | `xml_insert_before` | 20 | 14.3s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 411 | `xml_inspect_createmethods` | 15 | 14.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 412 | `xml_inspect_doctype` | 7 | 14.0s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 413 | `xml_inspect_parsexml` | 62 | 14.0s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 414 | `xml_inspect_xmldecl` | 7 | 14.0s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 415 | `xml_namespaces` | 203 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 416 | `xml_parent_and_child` | 5 | 14.0s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 417 | `xml_remove_node` | 22 | 14.0s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 418 | `xml_reparenting` | 14 | 14.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 419 | `xml_siblings` | 10 | 14.0s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 420 | `xml_to_string` | 13 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 421 | `xml_to_string_comment` | 1 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 422 | `xml_unescaping` | 23 | 14.0s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 423 | `xmlnode_proto` | 1 | 14.0s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**17 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `interface_implements_op` | 97.9% | 46 | 47 | 1 | [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 3 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 4 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 5 | `define_local_with_paths` | 94.4% | 51 | 54 | 3 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 6 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 7 | `movieclip_setmask` | 85.7% | 12 | 14 | 2 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 9 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [44](ruffle-tests/_investigation/incomplete/SCRIPT_HALTING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 10 | `selection_handlers` | 77.8% | 21 | 27 | 6 | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 11 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 12 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 13 | `register_class` | 66.7% | 44 | 66 | 22 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 14 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 15 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 16 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [61](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 17 | `issue_2030` | 50.0% | 2 | 4 | 2 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_1` | exit code -6 | 14.2s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_2` | exit code -6 | 14.3s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `movieclip_invalid_get_bounds_6` | exit code -6 | 37.0s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_invalid_get_bounds_7` | exit code -6 | 37.1s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

No timeouts.

## All Output Mismatches

**49 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `interface_implements_op` | 97.9% | 46/47 | 47 | 47 | [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 3 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 4 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 5 | `define_local_with_paths` | 94.4% | 51/54 | 54 | 54 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 6 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 7 | `movieclip_setmask` | 85.7% | 12/14 | 14 | 14 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 9 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [44](ruffle-tests/_investigation/incomplete/SCRIPT_HALTING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 10 | `selection_handlers` | 77.8% | 21/27 | 23 | 27 | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 11 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 12 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 13 | `register_class` | 66.7% | 44/66 | 65 | 66 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 14 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 15 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 16 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [61](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 17 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 18 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 19 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 20 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 21 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 22 | `removed_target_clip_scope` | 29.7% | 11/37 | 37 | 35 | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 23 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 24 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 25 | `timer_run_actions` | 16.7% | 3/18 | 17 | 18 | [59](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 26 | `register_and_init_order` | 15.6% | 36/231 | 154 | 231 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 27 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 28 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 29 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 30 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 31 | `register_class_swf6` | 10.8% | 4/37 | 35 | 37 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 32 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [44](ruffle-tests/_investigation/incomplete/SCRIPT_HALTING_PLAN.md) |
| 33 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 34 | `global_proto_decls` | 0.2% | 11/4497 | 685 | 4497 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 35 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 36 | `global_proto_decls_delete` | 0.0% | 1/4158 | 309 | 4158 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 37 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [19](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 38 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 39 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 40 | `geturl` | 0.0% | 0/7 | 0 | 7 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 41 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 42 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 43 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 44 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 45 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 46 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 47 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 48 | `string_paths_timer` | 0.0% | 0/41 | 41 | 0 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 49 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 3 | 3 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 8 | 7 | 1 |
| 6 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) | 2 | 1 | 1 |
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
| 19 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 20 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 5 | 4 | 1 |
| 21 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 22 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 29 | 25 | 4 |
| 23 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 16 | 5 | 11 |
| 24 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 25 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 26 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 16 | 2 | 14 |
| 27 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 1 | 0 | 1 |
| 28 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 0 | 0 | 0 |
| 29 | [LOCKROOT_PLAN.md](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 30 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 31 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 32 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 0 | 0 | 0 |
| 33 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 56 | 35 | 21 |
| 34 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 0 | 0 | 0 |
| 35 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 14 | 14 | 0 |
| 36 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 37 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 38 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 7 | 1 |
| 39 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 40 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 41 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 42 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 12 | 3 |
| 43 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 0 | 0 | 0 |
| 44 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/_investigation/incomplete/SCRIPT_HALTING_PLAN.md) | 2 | 0 | 2 |
| 45 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 3 | 2 | 1 |
| 46 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 47 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 48 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 49 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 50 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 51 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 52 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 3 | 3 | 0 |
| 53 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) | 1 | 1 | 0 |
| 54 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 18 | 14 | 4 |
| 55 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 58 | 53 | 5 |
| 56 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 57 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 58 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 59 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 2 | 1 | 1 |
| 60 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 61 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 1 | 1 |
| 62 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 5 | 11 |
| 63 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 9 | 7 | 2 |
| 64 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 65 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 25 | 25 | 0 |
| | *(tests not in any document)* | 153 | 152 | 1 |
