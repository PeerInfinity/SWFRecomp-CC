# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-05 22:31 UTC

**Git SHA**: `c170d74f70`

**Run Duration**: 138m 38s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **463** (74.8%) |
| Failing | 156 |
| Total expected lines | 91137 |
| Matching lines | 69827 (76.6%) |
| Mismatched lines | 21310 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 146 | 93.6% |
| Runtime Segfault | 5 | 3.2% |
| Compile Fail | 2 | 1.3% |
| Runtime Error | 2 | 1.3% |
| Timeout | 1 | 0.6% |

## Passing Tests

**463 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 12.9s |  |
| 2 | `action_to_integer` | 28 | 12.7s |  |
| 3 | `add` | 28 | 12.6s |  |
| 4 | `add2` | 354 | 12.9s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 12.6s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 12.6s |  |
| 7 | `add_swf5` | 28 | 12.6s |  |
| 8 | `arguments` | 127 | 12.6s | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [34](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 12.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 12.7s |  |
| 11 | `array_constructor` | 30 | 12.6s |  |
| 12 | `array_enumerate` | 4 | 12.6s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 12.6s |  |
| 14 | `array_properties` | 36 | 12.6s |  |
| 15 | `array_prototyping` | 12 | 12.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 12.6s |  |
| 17 | `array_sort` | 161 | 13.4s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 12.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 12.8s |  |
| 20 | `array_trivial` | 209 | 12.8s |  |
| 21 | `as1_constructor_v6` | 35 | 12.6s |  |
| 22 | `as1_constructor_v7` | 35 | 12.9s |  |
| 23 | `as2_oop` | 13 | 12.8s | [30](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 12.8s | [30](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 12.8s | [30](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 12.8s | [30](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 12.7s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 12.5s |  |
| 29 | `as_broadcaster_undef` | 89 | 12.7s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 12.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 12.6s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 12.6s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 12.6s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 12.6s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 12.5s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 12.6s |  |
| 37 | `as_transformed_flag` | 20 | 12.6s |  |
| 38 | `asnative` | 34 | 12.6s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 12.6s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 12.6s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 12.7s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 42 | `bad_placeobject_clipaction` | 2 | 14.5s |  |
| 43 | `bad_swf_tag_past_eof` | 0 | 12.9s |  |
| 44 | `bitand` | 1058 | 15.9s |  |
| 45 | `bitmap_data_colortransform` | 0 | 13.3s |  |
| 46 | `bitmap_data_fillrect` | 0 | 13.1s |  |
| 47 | `bitmap_data_max_size_swf10` | 12 | 13.0s |  |
| 48 | `bitmap_data_max_size_swf9` | 10 | 13.0s |  |
| 49 | `bitmap_data_perlinnoise` | 0 | 13.8s |  |
| 50 | `bitmap_data_pixeldissolve_image` | 0 | 13.4s |  |
| 51 | `bitmapdata_applyfilter_colormatrix` | 0 | 13.5s |  |
| 52 | `bitor` | 1058 | 16.1s |  |
| 53 | `biturshift` | 14 | 13.1s |  |
| 54 | `biturshift_swf8` | 14 | 15.1s |  |
| 55 | `bitxor` | 1058 | 16.6s |  |
| 56 | `boxed_primitives` | 24 | 13.7s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 57 | `button_children` | 8 | 13.0s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_goto` | 4 | 13.6s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_key_events` | 14 | 13.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_key_events_special` | 45 | 14.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_keypress` | 3 | 12.8s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_press` | 25 | 13.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `button_keypress_vs_tab` | 20 | 13.6s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 64 | `button_keypress_vs_textinput` | 4 | 14.0s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 65 | `button_order` | 2 | 13.7s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 66 | `button_properties_special_cases` | 22 | 13.8s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 67 | `button_v5` | 18 | 13.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 68 | `button_v6` | 18 | 13.8s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 69 | `call` | 63 | 13.5s | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) |
| 70 | `call_method_empty_name` | 1 | 13.7s |  |
| 71 | `capabilities_resolution` | 8 | 13.7s |  |
| 72 | `catch_references_registers` | 2 | 13.7s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 73 | `click_block` | 5 | 13.6s | [27](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 74 | `clip_constructors` | 8 | 13.8s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 75 | `clip_events` | 19 | 13.1s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 76 | `clone_sprite_types` | 24 | 12.7s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 77 | `closure_scope` | 7 | 12.8s | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 78 | `color` | 57 | 12.9s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 79 | `color_transform` | 48 | 12.9s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 80 | `conflicting_instance_names` | 23 | 12.7s |  |
| 81 | `constructor_function` | 2 | 12.6s |  |
| 82 | `context_menu` | 39 | 12.7s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 83 | `context_menu_item` | 41 | 12.8s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 84 | `create_empty_movie_clip` | 3 | 12.7s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 85 | `define_function2` | 8 | 12.6s |  |
| 86 | `define_function2_preload` | 13 | 12.6s |  |
| 87 | `define_function2_preload_order` | 4 | 13.2s |  |
| 88 | `define_function_case_sensitive` | 2 | 12.8s |  |
| 89 | `delete` | 3 | 13.1s |  |
| 90 | `display_object_properties` | 2 | 13.0s |  |
| 91 | `divide_swf4` | 107 | 13.2s |  |
| 92 | `do_init_action` | 3 | 13.2s |  |
| 93 | `do_init_action_child` | 12 | 13.1s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 94 | `drag_drop` | 10 | 13.0s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 95 | `drag_over_from_outside` | 1 | 13.1s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 96 | `drag_over_without_startdrag` | 1 | 13.2s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 97 | `duplicate_movie_clip` | 20 | 13.1s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 98 | `edittext_align` | 60 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 99 | `edittext_align_trailing_spaces_swf7` | 576 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_align_trailing_spaces_swf8` | 576 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_antialiastype` | 296 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_autosize` | 71 | 13.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_autosize_setter` | 20 | 13.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_default_format` | 221 | 13.4s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_default_format_font_style` | 335 | 12.9s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_font_size` | 45 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_hscroll` | 27 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_html_align_swf7` | 52 | 13.3s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_html_align_swf8` | 52 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_html_color` | 114 | 13.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_html_entity` | 4 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_html_roundtrip` | 17 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_html_swf7` | 5377 | 13.9s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_html_swf8` | 5377 | 13.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_input` | 1 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_leading` | 9 | 13.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_letter_spacing` | 15 | 14.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_margins` | 25 | 14.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_newline_stripping` | 64 | 18.9s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_password` | 5 | 13.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_password_copy` | 4 | 13.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_paste_empty` | 2 | 13.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_programmatic_focus` | 12 | 13.7s | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `edittext_restrict` | 191 | 13.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 125 | `edittext_restrict_paste` | 5 | 13.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 126 | `edittext_stylesheet` | 325 | 14.5s | [44](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 127 | `edittext_tag_indent` | 31 | 14.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 128 | `edittext_text_height_leading` | 20 | 14.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 129 | `edittext_underline` | 40 | 14.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 130 | `edittext_width_height` | 103 | 14.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 131 | `empty_movieclip_can_attach_movies` | 11 | 13.1s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 132 | `enumerate` | 64 | 13.1s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 133 | `equals` | 32 | 13.1s |  |
| 134 | `equals2_swf5` | 926 | 14.8s |  |
| 135 | `equals2_swf6` | 926 | 14.8s |  |
| 136 | `equals2_swf7` | 926 | 14.8s |  |
| 137 | `equals_swf4` | 665 | 13.8s |  |
| 138 | `equals_swf4_alt` | 32 | 13.1s |  |
| 139 | `equals_swf5` | 32 | 13.3s |  |
| 140 | `error` | 58 | 13.2s |  |
| 141 | `escape` | 14 | 13.4s |  |
| 142 | `execution_order1` | 5 | 13.8s |  |
| 143 | `execution_order2` | 7 | 13.6s |  |
| 144 | `execution_order3` | 4 | 14.1s |  |
| 145 | `execution_order4` | 12 | 14.0s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 146 | `export_assets` | 3 | 13.2s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 147 | `extends_chain` | 134 | 13.6s | [30](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 148 | `extends_native_type` | 11 | 13.1s | [30](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 149 | `focus_mouse` | 45 | 14.2s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [14](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 150 | `focus_root_movie` | 2 | 13.8s | [14](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 151 | `focusrect_focuslost` | 4 | 13.7s | [14](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 152 | `focusrect_mouse_swf8` | 0 | 13.9s |  |
| 153 | `focusrect_mouse_swf9` | 0 | 13.2s |  |
| 154 | `focusrect_swf5` | 6 | 12.9s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 155 | `focusrect_swf6` | 42 | 12.9s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 156 | `form_loader_encoding_1` | 1 | 12.8s |  |
| 157 | `frame_size_translated_negative` | 21 | 12.9s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 158 | `frame_size_translated_positive` | 21 | 12.9s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 159 | `function_as_function` | 35 | 12.7s | [16](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 160 | `function_base_clip` | 8 | 12.7s |  |
| 161 | `function_base_clip_removed` | 25 | 12.8s |  |
| 162 | `function_suppress_and_preload` | 28 | 12.8s |  |
| 163 | `get_bytes_total` | 4 | 12.6s | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 164 | `get_variable_in_scope` | 29 | 12.6s |  |
| 165 | `getproperty` | 28 | 12.5s |  |
| 166 | `getproperty_swf4` | 28 | 13.1s |  |
| 167 | `getproperty_swf5` | 28 | 13.2s |  |
| 168 | `gettextextent` | 56 | 13.2s | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 169 | `global_array` | 3 | 13.4s |  |
| 170 | `global_is_bare` | 7 | 13.1s |  |
| 171 | `global_swf6_7_8` | 15 | 13.2s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 172 | `globals_swf5` | 304 | 13.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 173 | `globals_swf6` | 304 | 13.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 174 | `globals_swf7` | 304 | 13.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 175 | `globals_swf8` | 304 | 13.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 176 | `goto_advance1` | 6 | 13.4s |  |
| 177 | `goto_advance2` | 2 | 13.2s |  |
| 178 | `goto_both_ways1` | 3 | 13.1s |  |
| 179 | `goto_both_ways2` | 3 | 13.1s |  |
| 180 | `goto_execution_order` | 2 | 12.8s |  |
| 181 | `goto_execution_order2` | 2 | 12.9s |  |
| 182 | `goto_frame` | 12 | 13.0s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 183 | `goto_frame2` | 44 | 13.2s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 184 | `goto_frame_number` | 3 | 12.7s |  |
| 185 | `goto_label` | 17 | 12.8s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 186 | `goto_methods` | 40 | 12.7s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 187 | `goto_rewind1` | 1 | 12.7s |  |
| 188 | `goto_rewind2` | 3 | 12.7s |  |
| 189 | `goto_rewind3` | 2 | 12.6s |  |
| 190 | `greater_swf6` | 1175 | 14.6s |  |
| 191 | `greater_swf7` | 1175 | 14.6s |  |
| 192 | `greaterthan_swf5` | 1 | 12.7s |  |
| 193 | `greaterthan_swf8` | 1 | 12.8s |  |
| 194 | `has_own_property` | 32 | 12.6s |  |
| 195 | `hittest_lockroot` | 15 | 12.9s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 196 | `hittest_morph` | 70 | 12.8s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 197 | `hittest_winding_rule` | 12 | 12.9s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 198 | `infinite_recursion_function` | 4 | 12.8s | [20](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 199 | `infinite_recursion_function_in_setter` | 131 | 12.8s | [20](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 200 | `infinite_recursion_virtual_property` | 67 | 12.9s | [20](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 201 | `init_array_invalid` | 4 | 12.8s |  |
| 202 | `init_object_invalid` | 4 | 13.1s |  |
| 203 | `init_object_order` | 15 | 12.8s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 204 | `is_finite` | 49 | 12.8s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 205 | `is_finite_swf6` | 49 | 12.7s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 206 | `is_prototype_of` | 89 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 207 | `issue_1086` | 1 | 12.7s |  |
| 208 | `issue_1104` | 2 | 12.7s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 209 | `issue_1671` | 0 | 12.7s |  |
| 210 | `issue_1906` | 4 | 12.7s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 211 | `issue_2166` | 9 | 12.6s |  |
| 212 | `issue_3169` | 2 | 12.7s | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 213 | `issue_3446` | 1 | 12.7s |  |
| 214 | `issue_3522` | 2 | 12.7s |  |
| 215 | `issue_4377` | 2 | 12.8s |  |
| 216 | `issue_710` | 4 | 12.6s |  |
| 217 | `issue_768` | 3 | 18.0s | [21](ruffle-tests/_investigation/complete/issue_768.md) |
| 218 | `issue_9327` | 2 | 13.0s |  |
| 219 | `issue_9885` | 2 | 13.0s |  |
| 220 | `key_isToggled` | 9 | 12.9s |  |
| 221 | `lessthan` | 41 | 13.0s |  |
| 222 | `lessthan2_swf5` | 1226 | 15.1s |  |
| 223 | `lessthan2_swf6` | 1226 | 15.2s |  |
| 224 | `lessthan2_swf7` | 1226 | 15.1s |  |
| 225 | `lessthan_swf4` | 902 | 14.2s |  |
| 226 | `lessthan_swf4_alt` | 41 | 13.0s |  |
| 227 | `lessthan_swf5` | 41 | 13.1s |  |
| 228 | `loadmovie` | 2 | 13.0s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 229 | `loadmovie_fail` | 2 | 13.0s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 230 | `loadmovie_flashvars` | 4 | 12.9s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 231 | `loadmovie_method` | 2 | 12.9s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 232 | `loadmovie_replace_root` | 5 | 13.0s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 233 | `loadmovienum` | 3 | 13.1s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 234 | `loadvariables` | 2 | 13.2s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 235 | `loadvariables2` | 8 | 13.3s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 236 | `loadvariablesnum` | 2 | 13.2s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 237 | `local_to_global` | 49 | 13.2s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 238 | `localconnection_properties` | 8 | 13.1s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 239 | `lock_root` | 1 | 13.2s |  |
| 240 | `logical_ops_swf4` | 90 | 13.1s |  |
| 241 | `logical_ops_swf8` | 108 | 13.2s |  |
| 242 | `looping` | 6 | 13.2s |  |
| 243 | `mask_reapply` | 0 | 13.3s |  |
| 244 | `mask_with_drawing` | 0 | 13.2s |  |
| 245 | `math_min_max` | 101 | 13.3s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 246 | `math_swf6` | 530 | 13.5s | [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 247 | `math_swf7` | 530 | 13.6s | [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 248 | `math_swf8` | 530 | 13.5s | [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 249 | `matrix` | 171 | 13.6s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 250 | `mcl_as_broadcaster` | 12 | 13.2s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 251 | `mcl_getprogress` | 30 | 13.5s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 252 | `mcl_loadclip` | 149 | 13.2s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 253 | `mcl_loadclip_properties` | 6 | 13.3s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 254 | `mcl_mislabeled_target` | 6 | 13.7s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 255 | `mcl_target_gif87a` | 6 | 14.3s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 256 | `mcl_target_gif89a` | 6 | 14.0s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 257 | `mcl_target_jpg` | 6 | 13.2s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 258 | `mcl_target_png` | 6 | 13.1s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 259 | `mcl_unloadclip` | 5 | 13.2s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 260 | `mouse_events` | 8 | 13.0s | [27](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 261 | `mouse_events_visible_enabled` | 12 | 13.2s | [27](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 262 | `mouse_hover_events_while_dragging` | 1 | 13.0s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 263 | `mouse_listeners` | 67 | 12.9s |  |
| 264 | `mouse_pos` | 665 | 12.9s | [27](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 265 | `mouse_pos_with_scale_factor` | 260 | 12.8s | [27](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 266 | `mouse_wheel_enabled` | 2 | 12.8s |  |
| 267 | `movieclip_begin_gradient_fill` | 0 | 13.4s |  |
| 268 | `movieclip_blend_mode_property` | 35 | 15.4s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 269 | `movieclip_create_text_field` | 90 | 13.3s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 270 | `movieclip_default_state` | 69 | 13.4s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 271 | `movieclip_depth_methods` | 98 | 14.2s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 272 | `movieclip_focusenabled` | 99 | 13.4s | [14](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 273 | `movieclip_get_instance_at_depth` | 28 | 13.2s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 274 | `movieclip_hittest` | 92 | 13.4s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 275 | `movieclip_in_removed_button` | 4 | 13.0s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 276 | `movieclip_init_object` | 5 | 13.3s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 277 | `movieclip_line_gradient_style` | 0 | 14.6s |  |
| 278 | `movieclip_name_from_timeline` | 13 | 12.6s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 279 | `movieclip_prototype_extension` | 5 | 12.6s |  |
| 280 | `moviecliploader_flashvars` | 4 | 12.6s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 281 | `mutable_this` | 18 | 12.5s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 282 | `named_shapes` | 14 | 12.6s |  |
| 283 | `nan_scale` | 9 | 12.6s |  |
| 284 | `native_double_construct` | 12 | 12.6s | [30](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 285 | `native_objects_swf7` | 84 | 13.1s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 286 | `native_objects_swf8` | 84 | 13.1s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 287 | `native_subclasses` | 191 | 12.9s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 288 | `nested_textfields_in_buttons` | 0 | 12.6s |  |
| 289 | `new_method_wrap` | 4 | 12.8s |  |
| 290 | `new_object_enumerate` | 7 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 291 | `new_object_wrap` | 4 | 12.8s |  |
| 292 | `o` | 3 | 12.7s |  |
| 293 | `object_constructor` | 33 | 12.8s |  |
| 294 | `object_function` | 32 | 12.8s |  |
| 295 | `object_properties` | 31 | 12.9s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 296 | `object_prototypes` | 74 | 12.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 297 | `object_resolve` | 38 | 12.8s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 298 | `object_string_coerce_swf5` | 62 | 12.8s | [31](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 299 | `object_string_coerce_swf6` | 68 | 12.8s | [31](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 300 | `on_construct` | 25 | 12.8s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 301 | `parse_float` | 74 | 12.9s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [34](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 302 | `parse_int` | 64 | 13.1s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [34](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 303 | `path_string` | 322 | 12.9s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 304 | `place_and_lookup` | 30 | 12.7s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 305 | `placeobject_occupied_depth` | 6 | 12.8s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 306 | `point` | 175 | 13.1s | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 307 | `primitive_instanceof` | 37 | 12.7s |  |
| 308 | `primitive_type_globals` | 557 | 13.6s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 309 | `printjob_props_swf5` | 45 | 13.0s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 310 | `printjob_props_swf6` | 45 | 13.2s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 311 | `printjob_props_swf7` | 45 | 13.3s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 312 | `property_invalid_base_clip` | 36 | 13.4s |  |
| 313 | `prototype_delete` | 12 | 13.3s |  |
| 314 | `prototype_enumerate` | 5 | 13.1s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 315 | `prototype_properties` | 17 | 13.0s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 316 | `rectangle` | 745 | 13.7s | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 317 | `recursive_prototypes` | 0 | 13.2s |  |
| 318 | `register_class_return_value` | 16 | 13.3s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 319 | `register_class_with_sound` | 11 | 13.5s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [39](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 320 | `register_globals_across_frames` | 15 | 13.4s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 321 | `register_underflow` | 26 | 13.1s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 322 | `remove_movie_clip` | 29 | 13.3s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 323 | `rewind_depth` | 30 | 13.0s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 324 | `sandbox_type_local_file` | 1 | 13.1s |  |
| 325 | `sandbox_type_local_network` | 1 | 12.9s |  |
| 326 | `selection` | 454 | 13.0s | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 327 | `set_interval` | 27 | 13.0s | [52](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 328 | `set_variable_scope` | 58 | 12.9s |  |
| 329 | `single_frame` | 1 | 13.0s |  |
| 330 | `slash_syntax` | 14 | 13.2s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 331 | `sound` | 628 | 13.4s | [39](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 332 | `sound_props_swf5` | 68 | 13.3s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 333 | `sound_props_swf6` | 68 | 13.2s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 334 | `sound_start_load` | 0 | 13.1s |  |
| 335 | `stage_display_state` | 16 | 13.2s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 336 | `stage_object_children` | 83 | 13.4s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 337 | `stage_object_enumerate` | 4 | 13.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 338 | `stage_object_properties` | 241 | 13.6s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 339 | `stage_object_properties_get_var` | 5 | 12.9s |  |
| 340 | `stage_object_properties_swf6` | 231 | 12.9s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 341 | `stage_property_representation` | 586 | 12.6s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 342 | `stage_scale_mode` | 39 | 12.6s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 343 | `strictequals_swf6` | 902 | 14.0s |  |
| 344 | `strictly_equals` | 7 | 12.5s |  |
| 345 | `string_methods` | 285 | 13.0s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 346 | `string_methods_negative_args` | 240 | 12.6s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 347 | `string_methods_swfv5` | 275 | 13.1s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 348 | `string_ops_swf6` | 95 | 12.7s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 349 | `string_paths_basic` | 4 | 12.6s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 350 | `string_paths_eval2` | 7 | 13.8s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 351 | `string_paths_hidden` | 54 | 13.6s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 352 | `string_paths_other` | 36 | 13.3s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 353 | `string_paths_unload` | 1 | 13.5s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 354 | `string_paths_variable_alias` | 4 | 13.1s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 355 | `string_paths_variable_scopes` | 5 | 13.1s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 356 | `stylesheet` | 283 | 13.7s |  |
| 357 | `stylesheet_transform` | 750 | 13.7s |  |
| 358 | `super_edge_cases` | 39 | 13.1s | [30](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 359 | `swf4_actions_bool` | 96 | 12.9s |  |
| 360 | `swf4_actions_coercion_order` | 158 | 13.1s | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 361 | `swf4_bool` | 4 | 13.0s |  |
| 362 | `swf4_function_calls` | 7 | 12.8s |  |
| 363 | `swf5_encoding` | 3 | 12.9s |  |
| 364 | `swf5_no_closure` | 19 | 13.2s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 365 | `swf6_case_insensitive` | 42 | 12.8s | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 366 | `swf6_string_as_bool` | 15 | 12.7s | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 367 | `swf7_case_sensitive` | 44 | 12.8s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 368 | `tab_ordering_automatic_basic` | 92 | 12.8s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 369 | `tab_ordering_automatic_order_grid` | 21 | 12.8s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 370 | `tab_ordering_children` | 208 | 13.0s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 371 | `tab_ordering_custom_basic` | 71 | 12.8s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 372 | `tab_ordering_custom_duplicate_index` | 22 | 12.9s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 373 | `tab_ordering_custom_i32_vs_u32` | 12 | 12.8s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 374 | `tab_ordering_custom_m1` | 29 | 12.7s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 375 | `tab_ordering_events` | 150 | 13.2s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 376 | `tab_ordering_movieclip_enabled_default` | 462 | 13.0s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 377 | `tab_ordering_properties_tab_index_edge_case` | 4 | 13.2s |  |
| 378 | `tab_ordering_reverse` | 51 | 13.2s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 379 | `tab_ordering_tabbable` | 47 | 13.2s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 380 | `target_clip_swf5` | 2 | 13.0s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 381 | `target_clip_swf6` | 2 | 13.0s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 382 | `target_path` | 14 | 13.1s |  |
| 383 | `tell_target` | 37 | 13.2s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 384 | `tell_target_invalid` | 6 | 13.3s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 385 | `tell_target_invalid_swf6` | 5 | 13.3s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 386 | `text_format` | 1146 | 13.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 387 | `text_format_display` | 21 | 13.4s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 388 | `text_format_font_max_length` | 2 | 13.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 389 | `text_format_rounding_swf7` | 840 | 13.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 390 | `text_format_rounding_swf8` | 840 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 391 | `textfield_background_color` | 11 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 392 | `textfield_border_color` | 11 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 393 | `textfield_cache_as_bitmap` | 1 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 394 | `textfield_maxchars` | 3 | 14.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 395 | `textfield_properties` | 44 | 13.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 396 | `textfield_props_swf5` | 175 | 13.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 397 | `textfield_props_swf6` | 210 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 398 | `textfield_props_swf7` | 210 | 13.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 399 | `textfield_props_swf8` | 210 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 400 | `textfield_text` | 7 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 401 | `textfield_variable` | 81 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 402 | `textsnapshot_available_text` | 20 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 403 | `textsnapshot_findtext` | 44 | 13.3s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 404 | `textsnapshot_gettext` | 55 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 405 | `textsnapshot_props_swf5` | 56 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 406 | `textsnapshot_props_swf6` | 56 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 407 | `textsnapshot_text_order` | 1 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 408 | `this_scoping` | 52 | 13.0s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 409 | `this_swf5` | 41 | 12.9s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 410 | `this_swf6` | 41 | 12.9s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 411 | `this_swf7` | 41 | 12.9s | [51](ruffle-tests/_investigation/complete/this_swf7.md) |
| 412 | `timeline_function_def` | 7 | 13.0s |  |
| 413 | `trace` | 8 | 13.5s |  |
| 414 | `transform` | 70 | 13.3s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 415 | `try_catch_finally` | 118 | 13.6s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 416 | `try_finally_simple` | 16 | 13.5s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 417 | `typeof` | 22 | 13.4s |  |
| 418 | `typeof_globals` | 7 | 13.4s |  |
| 419 | `uncaught_exception` | 1 | 13.4s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 420 | `uncaught_exception_bubbled` | 1 | 13.6s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 421 | `undefined_to_string_swf6` | 4 | 13.4s |  |
| 422 | `unescape` | 43 | 13.4s |  |
| 423 | `unload` | 52 | 13.7s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 424 | `unload_clip_event` | 4 | 13.5s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 425 | `unloadmovie` | 4 | 13.5s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 426 | `unloadmovie_method` | 3 | 13.8s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 427 | `unloadmovienum` | 13 | 13.9s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 428 | `use_hand_cursor` | 8 | 13.8s |  |
| 429 | `variable_args` | 5 | 14.0s |  |
| 430 | `waitforframe` | 7 | 13.6s |  |
| 431 | `waitforframe2` | 16 | 14.7s |  |
| 432 | `watch` | 117 | 13.4s | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 433 | `watch_textfield` | 12 | 13.1s | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 434 | `watch_virtual_property_proto` | 2 | 13.1s | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 435 | `with` | 49 | 13.1s | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 436 | `with_return` | 2 | 13.1s |  |
| 437 | `with_variable_scopes` | 43 | 13.3s | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 438 | `xml` | 15 | 13.1s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 439 | `xml_append_child` | 28 | 13.1s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 440 | `xml_append_child_with_parent` | 20 | 13.1s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 441 | `xml_attributes_read` | 4 | 13.1s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 442 | `xml_cdata` | 11 | 13.1s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 443 | `xml_child_nodes_edge_cases` | 4 | 13.1s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 444 | `xml_clone_expandos` | 19 | 13.1s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 445 | `xml_first_last_child` | 8 | 13.1s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 446 | `xml_has_child_nodes` | 3 | 13.0s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 447 | `xml_idmap` | 21 | 13.1s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 448 | `xml_ignore_comments` | 21 | 13.1s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 449 | `xml_ignore_white` | 34 | 13.2s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 450 | `xml_insert_before` | 20 | 13.0s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 451 | `xml_inspect_createmethods` | 15 | 13.1s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 452 | `xml_inspect_doctype` | 7 | 12.9s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 453 | `xml_inspect_parsexml` | 62 | 12.9s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 454 | `xml_inspect_xmldecl` | 7 | 12.9s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 455 | `xml_namespaces` | 203 | 13.0s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 456 | `xml_parent_and_child` | 5 | 12.8s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 457 | `xml_remove_node` | 22 | 12.9s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 458 | `xml_reparenting` | 14 | 12.8s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 459 | `xml_siblings` | 10 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 460 | `xml_to_string` | 13 | 13.1s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 461 | `xml_to_string_comment` | 1 | 13.1s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 462 | `xml_unescaping` | 23 | 13.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 463 | `xmlnode_proto` | 1 | 13.2s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**42 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [10](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `string_coercion` | 99.1% | 116 | 117 | 1 | [42](ruffle-tests/_investigation/complete/string_coercion.md) |
| 3 | `edittext_html_condensewhite_swf7` | 99.0% | 308 | 311 | 3 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `instanceof_coercions` | 97.7% | 86 | 88 | 2 | [54](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 7 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `funky_function_calls` | 96.4% | 54 | 56 | 2 | [16](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 10 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 11 | `define_local_with_paths` | 94.4% | 51 | 54 | 3 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 12 | `edittext_html_condensewhite_swf8` | 92.6% | 288 | 311 | 23 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 13 | `function_base_clip_readded` | 90.9% | 10 | 11 | 1 |  |
| 14 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 15 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 16 | `edittext_tab_focus` | 76.9% | 10 | 13 | 3 | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 17 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `edittext_tab_stops` | 75.0% | 45 | 60 | 15 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 19 | `focus_mouse_rollout` | 75.0% | 3 | 4 | 1 | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [14](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 20 | `tab_ordering_automatic_order_same_position` | 75.0% | 9 | 12 | 3 | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 21 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 22 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 23 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 24 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 25 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 26 | `loadmovie_var_persistence` | 62.5% | 5 | 8 | 3 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 27 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 28 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 29 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 30 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 31 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 32 | `register_class` | 57.6% | 38 | 66 | 28 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 33 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 34 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 35 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 36 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 37 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 38 | `device_font_spacing` | 50.5% | 46 | 91 | 45 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 39 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 40 | `edittext_focus_selection` | 50.0% | 1 | 2 | 1 | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 41 | `edittext_place_caret` | 50.0% | 1 | 2 | 1 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 42 | `issue_2030` | 50.0% | 2 | 4 | 2 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmap_filters` | 16.2s | [30](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `edittext_ime_focus_lost` | 15.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 3 | `netstream_play_flv_screen` | 28.0s |  |
| 4 | `string_paths_timer` | 15.0s | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 5 | `timer_run_actions` | 16.1s | [52](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 38.4s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 38.9s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 22.9s | [52](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**146 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [10](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `string_coercion` | 99.1% | 116/117 | 117 | 117 | [42](ruffle-tests/_investigation/complete/string_coercion.md) |
| 3 | `edittext_html_condensewhite_swf7` | 99.0% | 308/311 | 311 | 311 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `instanceof_coercions` | 97.7% | 86/88 | 88 | 88 | [54](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 7 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `funky_function_calls` | 96.4% | 54/56 | 56 | 56 | [16](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 10 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 11 | `define_local_with_paths` | 94.4% | 51/54 | 54 | 54 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 12 | `edittext_html_condensewhite_swf8` | 92.6% | 288/311 | 311 | 311 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 13 | `function_base_clip_readded` | 90.9% | 10/11 | 11 | 11 |  |
| 14 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 15 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 16 | `edittext_tab_focus` | 76.9% | 10/13 | 13 | 13 | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 17 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `edittext_tab_stops` | 75.0% | 45/60 | 60 | 60 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 19 | `focus_mouse_rollout` | 75.0% | 3/4 | 3 | 4 | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [14](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 20 | `tab_ordering_automatic_order_same_position` | 75.0% | 9/12 | 12 | 12 | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 21 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 22 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 23 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 24 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 25 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 26 | `loadmovie_var_persistence` | 62.5% | 5/8 | 5 | 8 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 27 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 28 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 29 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 30 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 31 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 32 | `register_class` | 57.6% | 38/66 | 47 | 66 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 33 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 34 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 35 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 36 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 37 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 38 | `device_font_spacing` | 50.5% | 46/91 | 91 | 91 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 39 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 40 | `edittext_focus_selection` | 50.0% | 1/2 | 2 | 2 | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 41 | `edittext_place_caret` | 50.0% | 1/2 | 2 | 2 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 42 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 43 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 |  |
| 44 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 45 | `loadmovienum_cross_version_prototype` | 46.2% | 6/13 | 13 | 9 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 46 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 47 | `edittext_input_newlines` | 44.4% | 4/9 | 8 | 9 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 48 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 49 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 50 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 |  |
| 51 | `tab_ordering_events_mouse` | 40.0% | 26/65 | 59 | 65 | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 52 | `swf5_to_6_cross_call` | 37.9% | 11/29 | 11 | 29 | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 53 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 54 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 55 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 56 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 57 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 58 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 59 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 60 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 61 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 62 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 63 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 64 | `cross_movie_root` | 30.0% | 3/10 | 10 | 10 |  |
| 65 | `loadmovie_registerclass` | 30.0% | 9/30 | 24 | 30 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 66 | `removed_target_clip_scope` | 29.7% | 11/37 | 37 | 35 | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 67 | `default_names` | 28.8% | 15/52 | 48 | 52 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 68 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 69 | `swf6_to_5_cross_call` | 24.1% | 7/29 | 11 | 29 | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 70 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 71 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 72 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 73 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 74 | `focus_remove` | 18.2% | 6/33 | 24 | 33 |  |
| 75 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 76 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 77 | `mcl_events_swf_version` | 15.9% | 37/232 | 37 | 232 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 78 | `focus_visibility_change` | 15.6% | 7/45 | 36 | 45 |  |
| 79 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 80 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 81 | `focus_keyboard_press` | 15.0% | 15/100 | 100 | 60 | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [14](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 82 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 83 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 84 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 85 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 86 | `coerce_to_object_monkeypatch` | 13.0% | 17/131 | 131 | 129 | [54](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 87 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 88 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 89 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 90 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 91 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 92 | `define_local` | 7.4% | 2/27 | 23 | 27 | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 93 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 94 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 95 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 96 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 97 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 98 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 |  |
| 99 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 100 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 101 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 102 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 103 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 104 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 105 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 106 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 107 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [37](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 108 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [37](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 109 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 110 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 111 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 112 | `global_proto_decls` | 0.3% | 13/4497 | 677 | 4497 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 113 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 114 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 115 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [16](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 116 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 117 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 118 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 119 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 120 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 121 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 122 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [14](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 123 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 124 | `geturl` | 0.0% | 0/7 | 0 | 7 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 125 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 126 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 127 | `interface_implements_op` | 0.0% | 0/47 | 46 | 47 | [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 128 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 129 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 130 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [37](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 131 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 132 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 133 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 134 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 135 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 136 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 137 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 138 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 139 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 140 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 141 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 142 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 143 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 144 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 145 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 146 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 13 | 1 |
| 6 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) | 2 | 1 | 1 |
| 7 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 4 | 4 |
| 8 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 2 | 2 |
| 9 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 10 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 11 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 12 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 13 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 14 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 4 | 3 |
| 15 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 16 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 1 | 2 |
| 17 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 18 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 23 | 8 |
| 19 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 20 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 21 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 22 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 25 | 24 |
| 23 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 24 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 25 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 26 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 27 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 28 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 30 | 28 |
| 29 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 12 | 4 |
| 30 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 15 | 2 |
| 31 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 32 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 33 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 7 | 1 |
| 34 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 35 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 11 | 1 |
| 36 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 12 | 3 |
| 37 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 1 | 3 |
| 38 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 2 | 2 |
| 39 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 40 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 41 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 42 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 0 | 1 |
| 43 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 44 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 45 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 46 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) | 16 | 13 | 3 |
| 47 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 14 | 5 |
| 48 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 70 | 56 | 14 |
| 49 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 50 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 51 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 52 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 53 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 54 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 0 | 2 |
| 55 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 3 | 13 |
| 56 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 10 | 2 |
| 57 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 58 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 202 | 155 | 47 |
