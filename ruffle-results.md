# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-05 04:15 UTC

**Git SHA**: `d3c5020af4`

**Run Duration**: 136m 9s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **457** (73.8%) |
| Failing | 162 |
| Total expected lines | 91475 |
| Matching lines | 70086 (76.6%) |
| Mismatched lines | 21389 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 154 | 95.1% |
| Runtime Segfault | 4 | 2.5% |
| Runtime Error | 2 | 1.2% |
| Compile Fail | 1 | 0.6% |
| Timeout | 1 | 0.6% |

## Passing Tests

**457 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 13.8s |  |
| 2 | `action_to_integer` | 28 | 12.8s |  |
| 3 | `add` | 28 | 12.7s |  |
| 4 | `add2` | 354 | 13.1s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 13.2s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 12.8s |  |
| 7 | `add_swf5` | 28 | 12.6s |  |
| 8 | `arguments` | 127 | 12.7s | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [34](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 12.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 12.7s |  |
| 11 | `array_constructor` | 30 | 13.3s |  |
| 12 | `array_enumerate` | 4 | 12.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 12.7s |  |
| 14 | `array_properties` | 36 | 12.9s |  |
| 15 | `array_prototyping` | 12 | 12.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 13.0s |  |
| 17 | `array_sort` | 161 | 13.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 12.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 12.8s |  |
| 20 | `array_trivial` | 209 | 13.0s |  |
| 21 | `as1_constructor_v6` | 35 | 12.9s |  |
| 22 | `as1_constructor_v7` | 35 | 16.7s |  |
| 23 | `as2_oop` | 13 | 13.3s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 13.4s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 13.3s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 13.2s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 13.0s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 12.8s |  |
| 29 | `as_broadcaster_undef` | 89 | 12.9s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 12.9s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 12.9s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 12.9s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 12.9s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 13.2s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 12.9s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 12.9s |  |
| 37 | `as_transformed_flag` | 20 | 12.8s |  |
| 38 | `attach_movie` | 59 | 12.9s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 39 | `attach_movie_stop` | 3 | 13.1s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 40 | `bad_placeobject_clipaction` | 2 | 12.6s |  |
| 41 | `bad_swf_tag_past_eof` | 0 | 12.4s |  |
| 42 | `bitand` | 1058 | 15.0s |  |
| 43 | `bitmap_data_colortransform` | 0 | 12.7s |  |
| 44 | `bitmap_data_fillrect` | 0 | 12.6s |  |
| 45 | `bitmap_data_max_size_swf10` | 12 | 12.4s |  |
| 46 | `bitmap_data_max_size_swf9` | 10 | 12.4s |  |
| 47 | `bitmap_data_perlinnoise` | 0 | 13.2s |  |
| 48 | `bitmap_data_pixeldissolve_image` | 0 | 12.8s |  |
| 49 | `bitmapdata_applyfilter_colormatrix` | 0 | 12.5s |  |
| 50 | `bitor` | 1058 | 14.9s |  |
| 51 | `biturshift` | 14 | 12.4s |  |
| 52 | `biturshift_swf8` | 14 | 13.2s |  |
| 53 | `bitxor` | 1058 | 14.8s |  |
| 54 | `boxed_primitives` | 24 | 12.5s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 55 | `button_children` | 8 | 12.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_goto` | 4 | 12.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_key_events` | 14 | 12.6s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_key_events_special` | 45 | 13.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_keypress` | 3 | 12.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_keypress_vs_press` | 25 | 12.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_keypress_vs_tab` | 20 | 12.6s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_textinput` | 4 | 12.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `button_order` | 2 | 12.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 64 | `button_properties_special_cases` | 22 | 12.6s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 65 | `button_v5` | 18 | 12.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 66 | `button_v6` | 18 | 12.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 67 | `call` | 63 | 12.5s | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) |
| 68 | `call_method_empty_name` | 1 | 12.3s |  |
| 69 | `capabilities_resolution` | 8 | 12.4s |  |
| 70 | `catch_references_registers` | 2 | 12.4s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 71 | `click_block` | 5 | 12.3s | [27](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 72 | `clip_constructors` | 8 | 12.4s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 73 | `clip_events` | 19 | 12.8s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 74 | `clone_sprite_types` | 24 | 12.5s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 75 | `closure_scope` | 7 | 12.6s | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 76 | `color` | 57 | 12.7s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 77 | `color_transform` | 48 | 12.8s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 78 | `conflicting_instance_names` | 23 | 12.6s |  |
| 79 | `constructor_function` | 2 | 12.4s |  |
| 80 | `context_menu` | 39 | 12.6s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 81 | `context_menu_item` | 41 | 12.5s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 82 | `create_empty_movie_clip` | 3 | 12.4s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 83 | `define_function2` | 8 | 12.4s |  |
| 84 | `define_function2_preload` | 13 | 12.5s |  |
| 85 | `define_function2_preload_order` | 4 | 14.2s |  |
| 86 | `define_function_case_sensitive` | 2 | 12.8s |  |
| 87 | `delete` | 3 | 12.6s |  |
| 88 | `display_object_properties` | 2 | 12.6s |  |
| 89 | `divide_swf4` | 107 | 12.8s |  |
| 90 | `do_init_action` | 3 | 12.9s |  |
| 91 | `do_init_action_child` | 12 | 12.7s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 92 | `drag_drop` | 10 | 12.7s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 93 | `drag_over_from_outside` | 1 | 12.9s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 94 | `drag_over_without_startdrag` | 1 | 13.1s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 95 | `duplicate_movie_clip` | 20 | 12.9s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 96 | `edittext_align` | 60 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 97 | `edittext_align_trailing_spaces_swf7` | 576 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 98 | `edittext_align_trailing_spaces_swf8` | 576 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 99 | `edittext_antialiastype` | 296 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_autosize` | 71 | 12.9s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_autosize_setter` | 20 | 14.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_default_format` | 221 | 13.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_default_format_font_style` | 335 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_font_size` | 45 | 13.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_hscroll` | 27 | 12.9s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_html_align_swf7` | 52 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_html_align_swf8` | 52 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_html_color` | 114 | 13.3s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_html_entity` | 4 | 13.3s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_html_roundtrip` | 17 | 13.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_html_swf7` | 5377 | 14.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_html_swf8` | 5377 | 14.3s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_input` | 1 | 13.2s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_leading` | 9 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_letter_spacing` | 15 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_margins` | 25 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_newline_stripping` | 64 | 17.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_password` | 5 | 12.9s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_password_copy` | 4 | 12.9s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_paste_empty` | 2 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_programmatic_focus` | 12 | 13.0s | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_restrict` | 191 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_restrict_paste` | 5 | 12.9s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `edittext_stylesheet` | 325 | 13.5s | [44](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 125 | `edittext_tag_indent` | 31 | 13.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 126 | `edittext_text_height_leading` | 20 | 13.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 127 | `edittext_underline` | 40 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 128 | `edittext_width_height` | 103 | 13.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 129 | `empty_movieclip_can_attach_movies` | 11 | 12.7s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 130 | `enumerate` | 64 | 12.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 131 | `equals` | 32 | 12.4s |  |
| 132 | `equals2_swf5` | 926 | 14.1s |  |
| 133 | `equals2_swf6` | 926 | 14.0s |  |
| 134 | `equals2_swf7` | 926 | 14.0s |  |
| 135 | `equals_swf4` | 665 | 13.1s |  |
| 136 | `equals_swf4_alt` | 32 | 12.5s |  |
| 137 | `equals_swf5` | 32 | 12.4s |  |
| 138 | `error` | 58 | 12.4s |  |
| 139 | `escape` | 14 | 12.3s |  |
| 140 | `execution_order1` | 5 | 12.5s |  |
| 141 | `execution_order2` | 7 | 12.5s |  |
| 142 | `execution_order3` | 4 | 12.6s |  |
| 143 | `execution_order4` | 12 | 12.6s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 144 | `export_assets` | 3 | 12.3s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 145 | `extends_chain` | 134 | 12.8s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 146 | `extends_native_type` | 11 | 12.4s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 147 | `focus_mouse` | 45 | 12.5s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [14](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 148 | `focus_root_movie` | 2 | 12.4s | [14](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 149 | `focusrect_focuslost` | 4 | 12.3s | [14](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 150 | `focusrect_mouse_swf8` | 0 | 12.4s |  |
| 151 | `focusrect_mouse_swf9` | 0 | 13.2s |  |
| 152 | `focusrect_swf5` | 6 | 12.8s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 153 | `focusrect_swf6` | 42 | 12.7s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 154 | `form_loader_encoding_1` | 1 | 12.6s |  |
| 155 | `frame_size_translated_negative` | 21 | 12.7s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 156 | `frame_size_translated_positive` | 21 | 12.6s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 157 | `function_as_function` | 35 | 12.5s | [16](ruffle-tests/_investigation/incomplete/FUNCTION_EDGE_CASES_PLAN.md) |
| 158 | `function_base_clip` | 8 | 12.5s |  |
| 159 | `function_base_clip_removed` | 25 | 12.8s |  |
| 160 | `function_suppress_and_preload` | 28 | 12.6s |  |
| 161 | `get_variable_in_scope` | 29 | 12.7s |  |
| 162 | `getproperty` | 28 | 12.7s |  |
| 163 | `getproperty_swf4` | 28 | 14.7s |  |
| 164 | `getproperty_swf5` | 28 | 12.6s |  |
| 165 | `global_array` | 3 | 12.6s |  |
| 166 | `global_is_bare` | 7 | 12.5s |  |
| 167 | `global_swf6_7_8` | 15 | 12.8s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 168 | `globals_swf5` | 304 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 169 | `globals_swf6` | 304 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 170 | `globals_swf7` | 304 | 12.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 171 | `globals_swf8` | 304 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 172 | `goto_advance1` | 6 | 12.5s |  |
| 173 | `goto_advance2` | 2 | 12.6s |  |
| 174 | `goto_both_ways1` | 3 | 12.6s |  |
| 175 | `goto_both_ways2` | 3 | 12.7s |  |
| 176 | `goto_execution_order` | 2 | 12.6s |  |
| 177 | `goto_execution_order2` | 2 | 12.7s |  |
| 178 | `goto_frame` | 12 | 14.6s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 179 | `goto_frame2` | 44 | 13.1s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 180 | `goto_frame_number` | 3 | 12.6s |  |
| 181 | `goto_label` | 17 | 12.7s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 182 | `goto_methods` | 40 | 12.7s | [15](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 183 | `goto_rewind1` | 1 | 12.6s |  |
| 184 | `goto_rewind2` | 3 | 12.5s |  |
| 185 | `goto_rewind3` | 2 | 12.5s |  |
| 186 | `greater_swf6` | 1175 | 14.6s |  |
| 187 | `greater_swf7` | 1175 | 14.5s |  |
| 188 | `greaterthan_swf5` | 1 | 12.6s |  |
| 189 | `greaterthan_swf8` | 1 | 12.8s |  |
| 190 | `has_own_property` | 32 | 12.7s |  |
| 191 | `hittest_lockroot` | 15 | 13.0s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 192 | `hittest_morph` | 70 | 12.6s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 193 | `hittest_winding_rule` | 12 | 12.7s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 194 | `infinite_recursion_function` | 4 | 12.5s | [20](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 195 | `infinite_recursion_function_in_setter` | 131 | 12.5s | [20](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 196 | `infinite_recursion_virtual_property` | 67 | 12.5s | [20](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 197 | `init_array_invalid` | 4 | 12.6s |  |
| 198 | `init_object_invalid` | 4 | 14.0s |  |
| 199 | `init_object_order` | 15 | 13.1s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 200 | `is_finite` | 49 | 13.0s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 201 | `is_finite_swf6` | 49 | 12.9s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 202 | `is_prototype_of` | 89 | 13.1s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 203 | `issue_1086` | 1 | 13.0s |  |
| 204 | `issue_1104` | 2 | 13.0s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 205 | `issue_1671` | 0 | 12.9s |  |
| 206 | `issue_1906` | 4 | 13.1s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 207 | `issue_2166` | 9 | 13.1s |  |
| 208 | `issue_3169` | 2 | 13.1s | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 209 | `issue_3446` | 1 | 13.1s |  |
| 210 | `issue_3522` | 2 | 13.2s |  |
| 211 | `issue_4377` | 2 | 13.3s |  |
| 212 | `issue_710` | 4 | 13.2s |  |
| 213 | `issue_768` | 3 | 13.4s | [21](ruffle-tests/_investigation/complete/issue_768.md) |
| 214 | `issue_9327` | 2 | 13.4s |  |
| 215 | `issue_9885` | 2 | 13.3s |  |
| 216 | `key_isToggled` | 9 | 13.2s |  |
| 217 | `lessthan` | 41 | 13.4s |  |
| 218 | `lessthan2_swf5` | 1226 | 15.5s |  |
| 219 | `lessthan2_swf6` | 1226 | 15.4s |  |
| 220 | `lessthan2_swf7` | 1226 | 15.3s |  |
| 221 | `lessthan_swf4` | 902 | 14.3s |  |
| 222 | `lessthan_swf4_alt` | 41 | 13.1s |  |
| 223 | `lessthan_swf5` | 41 | 13.2s |  |
| 224 | `loadmovie` | 2 | 13.2s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 225 | `loadmovie_fail` | 2 | 13.1s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 226 | `loadmovie_flashvars` | 4 | 13.2s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 227 | `loadmovie_method` | 2 | 13.4s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 228 | `loadmovie_replace_root` | 5 | 13.7s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 229 | `loadmovienum` | 3 | 13.3s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 230 | `loadvariables` | 2 | 12.9s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 231 | `loadvariables2` | 8 | 12.8s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 232 | `loadvariablesnum` | 2 | 13.2s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 233 | `local_to_global` | 49 | 13.1s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 234 | `localconnection_properties` | 8 | 13.3s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 235 | `lock_root` | 1 | 13.5s |  |
| 236 | `logical_ops_swf4` | 90 | 14.0s |  |
| 237 | `logical_ops_swf8` | 108 | 13.8s |  |
| 238 | `looping` | 6 | 13.4s |  |
| 239 | `mask_reapply` | 0 | 13.2s |  |
| 240 | `mask_with_drawing` | 0 | 13.0s |  |
| 241 | `math_min_max` | 101 | 13.0s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 242 | `math_swf6` | 530 | 13.1s | [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 243 | `math_swf7` | 530 | 13.3s | [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 244 | `math_swf8` | 530 | 13.2s | [25](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 245 | `matrix` | 171 | 13.3s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 246 | `mcl_as_broadcaster` | 12 | 12.8s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 247 | `mcl_getprogress` | 30 | 13.6s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 248 | `mcl_loadclip` | 149 | 13.6s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 249 | `mcl_loadclip_properties` | 6 | 13.4s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 250 | `mcl_mislabeled_target` | 6 | 13.2s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 251 | `mcl_target_gif87a` | 6 | 13.5s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 252 | `mcl_target_gif89a` | 6 | 13.3s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 253 | `mcl_target_jpg` | 6 | 13.6s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 254 | `mcl_target_png` | 6 | 13.8s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 255 | `mcl_unloadclip` | 5 | 13.4s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 256 | `mouse_events` | 8 | 13.4s | [27](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 257 | `mouse_events_visible_enabled` | 12 | 14.0s | [27](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 258 | `mouse_hover_events_while_dragging` | 1 | 13.9s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 259 | `mouse_listeners` | 67 | 13.8s |  |
| 260 | `mouse_pos` | 665 | 13.0s | [27](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 261 | `mouse_pos_with_scale_factor` | 260 | 12.8s | [27](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 262 | `mouse_wheel_enabled` | 2 | 13.4s |  |
| 263 | `movieclip_begin_gradient_fill` | 0 | 13.9s |  |
| 264 | `movieclip_blend_mode_property` | 35 | 13.0s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 265 | `movieclip_create_text_field` | 90 | 12.9s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 266 | `movieclip_default_state` | 69 | 13.0s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 267 | `movieclip_depth_methods` | 98 | 13.0s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 268 | `movieclip_focusenabled` | 99 | 12.9s | [14](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 269 | `movieclip_get_instance_at_depth` | 28 | 12.8s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 270 | `movieclip_hittest` | 92 | 12.7s | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 271 | `movieclip_in_removed_button` | 4 | 12.8s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 272 | `movieclip_init_object` | 5 | 12.9s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 273 | `movieclip_line_gradient_style` | 0 | 14.7s |  |
| 274 | `movieclip_name_from_timeline` | 13 | 12.6s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 275 | `movieclip_prototype_extension` | 5 | 12.6s |  |
| 276 | `moviecliploader_flashvars` | 4 | 12.6s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 277 | `mutable_this` | 18 | 12.5s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 278 | `named_shapes` | 14 | 12.5s |  |
| 279 | `nan_scale` | 9 | 12.6s |  |
| 280 | `native_double_construct` | 12 | 12.7s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 281 | `native_objects_swf7` | 84 | 13.1s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 282 | `native_objects_swf8` | 84 | 13.0s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 283 | `native_subclasses` | 191 | 12.9s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 284 | `nested_textfields_in_buttons` | 0 | 12.6s |  |
| 285 | `new_method_wrap` | 4 | 12.5s |  |
| 286 | `new_object_enumerate` | 7 | 12.6s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 287 | `new_object_wrap` | 4 | 12.8s |  |
| 288 | `o` | 3 | 12.6s |  |
| 289 | `object_constructor` | 33 | 12.6s |  |
| 290 | `object_function` | 32 | 12.5s |  |
| 291 | `object_properties` | 31 | 12.6s | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 292 | `object_prototypes` | 74 | 12.6s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 293 | `object_string_coerce_swf5` | 62 | 12.6s | [31](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 294 | `object_string_coerce_swf6` | 68 | 12.6s | [31](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 295 | `on_construct` | 25 | 12.6s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 296 | `parse_float` | 74 | 12.6s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [34](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 297 | `parse_int` | 64 | 12.8s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [34](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 298 | `path_string` | 322 | 12.8s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 299 | `place_and_lookup` | 30 | 12.6s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 300 | `placeobject_occupied_depth` | 6 | 12.6s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 301 | `point` | 175 | 13.0s | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 302 | `primitive_instanceof` | 37 | 12.5s |  |
| 303 | `primitive_type_globals` | 557 | 13.7s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 304 | `printjob_props_swf5` | 45 | 13.3s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 305 | `printjob_props_swf6` | 45 | 13.2s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 306 | `printjob_props_swf7` | 45 | 12.8s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 307 | `property_invalid_base_clip` | 36 | 12.9s |  |
| 308 | `prototype_delete` | 12 | 12.7s |  |
| 309 | `prototype_enumerate` | 5 | 12.9s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 310 | `prototype_properties` | 17 | 13.0s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 311 | `rectangle` | 745 | 13.8s | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 312 | `recursive_prototypes` | 0 | 12.7s |  |
| 313 | `register_class_return_value` | 16 | 13.7s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 314 | `register_class_with_sound` | 11 | 13.7s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [39](ruffle-tests/_investigation/incomplete/SOUND_CLASS_PLAN.md) |
| 315 | `register_globals_across_frames` | 15 | 12.9s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 316 | `register_underflow` | 26 | 12.9s | [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 317 | `remove_movie_clip` | 29 | 13.0s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 318 | `rewind_depth` | 30 | 12.7s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 319 | `sandbox_type_local_file` | 1 | 12.5s |  |
| 320 | `sandbox_type_local_network` | 1 | 12.4s |  |
| 321 | `selection` | 454 | 12.7s | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 322 | `set_interval` | 27 | 12.6s | [52](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 323 | `set_variable_scope` | 58 | 12.5s |  |
| 324 | `single_frame` | 1 | 12.5s |  |
| 325 | `slash_syntax` | 14 | 12.7s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 326 | `sound_props_swf5` | 68 | 12.9s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 327 | `sound_props_swf6` | 68 | 12.9s | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 328 | `sound_start_load` | 0 | 13.0s |  |
| 329 | `stage_display_state` | 16 | 12.9s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 330 | `stage_object_children` | 83 | 12.9s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 331 | `stage_object_enumerate` | 4 | 12.6s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 332 | `stage_object_properties` | 241 | 13.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 333 | `stage_object_properties_get_var` | 5 | 12.8s |  |
| 334 | `stage_object_properties_swf6` | 231 | 13.0s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 335 | `stage_property_representation` | 586 | 13.0s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 336 | `stage_scale_mode` | 39 | 13.0s | [40](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 337 | `strictequals_swf6` | 902 | 14.6s |  |
| 338 | `strictly_equals` | 7 | 13.2s |  |
| 339 | `string_methods` | 285 | 13.6s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 340 | `string_methods_negative_args` | 240 | 13.1s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 341 | `string_methods_swfv5` | 275 | 13.6s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 342 | `string_ops_swf6` | 95 | 13.2s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 343 | `string_paths_basic` | 4 | 13.2s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 344 | `string_paths_eval2` | 7 | 13.2s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 345 | `string_paths_hidden` | 54 | 13.1s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 346 | `string_paths_other` | 36 | 12.7s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 347 | `string_paths_unload` | 1 | 12.9s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 348 | `string_paths_variable_alias` | 4 | 12.6s | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 349 | `string_paths_variable_scopes` | 5 | 12.6s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 350 | `stylesheet` | 283 | 13.6s |  |
| 351 | `stylesheet_transform` | 750 | 13.5s |  |
| 352 | `super_edge_cases` | 39 | 13.1s | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 353 | `swf4_actions_bool` | 96 | 13.0s |  |
| 354 | `swf4_actions_coercion_order` | 158 | 13.1s | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 355 | `swf4_bool` | 4 | 13.3s |  |
| 356 | `swf4_function_calls` | 7 | 13.2s |  |
| 357 | `swf5_encoding` | 3 | 13.2s |  |
| 358 | `swf5_no_closure` | 19 | 13.3s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 359 | `swf6_case_insensitive` | 42 | 12.5s | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 360 | `swf6_string_as_bool` | 15 | 12.5s | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 361 | `swf7_case_sensitive` | 44 | 12.5s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 362 | `tab_ordering_automatic_basic` | 92 | 12.6s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 363 | `tab_ordering_automatic_order_grid` | 21 | 12.7s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 364 | `tab_ordering_children` | 208 | 12.8s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 365 | `tab_ordering_custom_basic` | 71 | 12.7s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 366 | `tab_ordering_custom_duplicate_index` | 22 | 12.7s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 367 | `tab_ordering_custom_i32_vs_u32` | 12 | 12.8s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 368 | `tab_ordering_custom_m1` | 29 | 12.8s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 369 | `tab_ordering_events` | 150 | 13.1s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 370 | `tab_ordering_movieclip_enabled_default` | 462 | 13.0s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 371 | `tab_ordering_properties_tab_index_edge_case` | 4 | 12.8s |  |
| 372 | `tab_ordering_reverse` | 51 | 12.8s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 373 | `tab_ordering_tabbable` | 47 | 12.8s | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 374 | `target_clip_swf5` | 2 | 12.7s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 375 | `target_clip_swf6` | 2 | 12.7s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 376 | `target_path` | 14 | 12.7s |  |
| 377 | `tell_target` | 37 | 13.0s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 378 | `tell_target_invalid` | 6 | 12.8s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 379 | `tell_target_invalid_swf6` | 5 | 12.8s | [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 380 | `text_format` | 1146 | 13.1s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 381 | `text_format_display` | 21 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 382 | `text_format_font_max_length` | 2 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 383 | `text_format_rounding_swf7` | 840 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 384 | `text_format_rounding_swf8` | 840 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 385 | `textfield_background_color` | 11 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 386 | `textfield_border_color` | 11 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 387 | `textfield_cache_as_bitmap` | 1 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 388 | `textfield_maxchars` | 3 | 15.0s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 389 | `textfield_properties` | 44 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 390 | `textfield_props_swf5` | 175 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 391 | `textfield_props_swf6` | 210 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 392 | `textfield_props_swf7` | 210 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 393 | `textfield_props_swf8` | 210 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 394 | `textfield_text` | 7 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 395 | `textfield_variable` | 81 | 12.9s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 396 | `textsnapshot_available_text` | 20 | 12.7s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 397 | `textsnapshot_findtext` | 44 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 398 | `textsnapshot_gettext` | 55 | 12.8s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 399 | `textsnapshot_props_swf5` | 56 | 12.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 400 | `textsnapshot_props_swf6` | 56 | 12.6s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 401 | `textsnapshot_text_order` | 1 | 12.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [49](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 402 | `this_scoping` | 52 | 12.6s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 403 | `this_swf5` | 41 | 12.9s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 404 | `this_swf6` | 41 | 12.7s | [50](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 405 | `this_swf7` | 41 | 13.4s | [51](ruffle-tests/_investigation/complete/this_swf7.md) |
| 406 | `timeline_function_def` | 7 | 12.7s |  |
| 407 | `trace` | 8 | 12.9s |  |
| 408 | `transform` | 70 | 13.0s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 409 | `try_catch_finally` | 118 | 13.2s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 410 | `try_finally_simple` | 16 | 12.9s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 411 | `typeof` | 22 | 12.8s |  |
| 412 | `typeof_globals` | 7 | 12.6s |  |
| 413 | `uncaught_exception` | 1 | 12.7s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 414 | `uncaught_exception_bubbled` | 1 | 12.6s | [53](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 415 | `undefined_to_string_swf6` | 4 | 12.8s |  |
| 416 | `unescape` | 43 | 12.9s |  |
| 417 | `unload` | 52 | 13.3s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 418 | `unload_clip_event` | 4 | 13.3s | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 419 | `unloadmovie` | 4 | 13.2s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 420 | `unloadmovie_method` | 3 | 13.1s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 421 | `unloadmovienum` | 13 | 13.1s | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 422 | `use_hand_cursor` | 8 | 13.0s |  |
| 423 | `variable_args` | 5 | 13.1s |  |
| 424 | `waitforframe` | 7 | 12.9s |  |
| 425 | `waitforframe2` | 16 | 13.3s |  |
| 426 | `watch` | 117 | 13.1s | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 427 | `watch_textfield` | 12 | 12.8s | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 428 | `watch_virtual_property_proto` | 2 | 12.8s | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 429 | `with` | 49 | 12.8s | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 430 | `with_return` | 2 | 12.7s |  |
| 431 | `with_variable_scopes` | 43 | 12.9s | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 432 | `xml` | 15 | 12.8s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 433 | `xml_append_child` | 28 | 12.8s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 434 | `xml_append_child_with_parent` | 20 | 12.9s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 435 | `xml_attributes_read` | 4 | 12.8s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 436 | `xml_cdata` | 11 | 12.8s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 437 | `xml_child_nodes_edge_cases` | 4 | 12.8s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 438 | `xml_clone_expandos` | 19 | 12.8s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 439 | `xml_first_last_child` | 8 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 440 | `xml_has_child_nodes` | 3 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 441 | `xml_idmap` | 21 | 12.8s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 442 | `xml_ignore_comments` | 21 | 12.7s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 443 | `xml_ignore_white` | 34 | 13.6s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 444 | `xml_insert_before` | 20 | 13.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 445 | `xml_inspect_createmethods` | 15 | 13.6s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 446 | `xml_inspect_doctype` | 7 | 13.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 447 | `xml_inspect_parsexml` | 62 | 13.5s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 448 | `xml_inspect_xmldecl` | 7 | 13.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 449 | `xml_namespaces` | 203 | 13.3s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 450 | `xml_parent_and_child` | 5 | 13.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 451 | `xml_remove_node` | 22 | 13.5s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 452 | `xml_reparenting` | 14 | 13.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 453 | `xml_siblings` | 10 | 13.5s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 454 | `xml_to_string` | 13 | 13.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 455 | `xml_to_string_comment` | 1 | 13.3s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 456 | `xml_unescaping` | 23 | 13.6s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 457 | `xmlnode_proto` | 1 | 13.4s | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**45 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [10](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `string_coercion` | 99.1% | 116 | 117 | 1 | [42](ruffle-tests/_investigation/complete/string_coercion.md) |
| 3 | `sound` | 99.0% | 622 | 628 | 6 | [39](ruffle-tests/_investigation/incomplete/SOUND_CLASS_PLAN.md) |
| 4 | `edittext_html_condensewhite_swf7` | 99.0% | 308 | 311 | 3 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 5 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 7 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 10 | `funky_function_calls` | 92.9% | 52 | 56 | 4 | [16](ruffle-tests/_investigation/incomplete/FUNCTION_EDGE_CASES_PLAN.md) |
| 11 | `function_base_clip_readded` | 90.9% | 10 | 11 | 1 |  |
| 12 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 13 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 14 | `edittext_html_condensewhite_swf8` | 80.1% | 249 | 311 | 62 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
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
| 33 | `asnative` | 55.9% | 19 | 34 | 15 | [4](ruffle-tests/_investigation/incomplete/ASNATIVE_ASNEW_PLAN.md) |
| 34 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 35 | `gettextextent` | 55.4% | 31 | 56 | 25 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 36 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 37 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 38 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 39 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 40 | `bitmap_filters` | 50.9% | 279 | 548 | 269 | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 41 | `device_font_spacing` | 50.5% | 46 | 91 | 45 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 42 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 43 | `edittext_focus_selection` | 50.0% | 1 | 2 | 1 | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 44 | `edittext_place_caret` | 50.0% | 1 | 2 | 1 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 45 | `issue_2030` | 50.0% | 2 | 4 | 2 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `edittext_ime_focus_lost` | 15.5s | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 2 | `netstream_play_flv_screen` | 27.7s |  |
| 3 | `string_paths_timer` | 14.9s | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 4 | `timer_run_actions` | 19.2s | [52](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

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
| 1 | `timeout` | runtime timeout (>10s) | 22.5s | [52](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**154 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [10](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `string_coercion` | 99.1% | 116/117 | 117 | 117 | [42](ruffle-tests/_investigation/complete/string_coercion.md) |
| 3 | `sound` | 99.0% | 622/628 | 628 | 628 | [39](ruffle-tests/_investigation/incomplete/SOUND_CLASS_PLAN.md) |
| 4 | `edittext_html_condensewhite_swf7` | 99.0% | 308/311 | 311 | 311 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 5 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 7 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 10 | `funky_function_calls` | 92.9% | 52/56 | 56 | 56 | [16](ruffle-tests/_investigation/incomplete/FUNCTION_EDGE_CASES_PLAN.md) |
| 11 | `function_base_clip_readded` | 90.9% | 10/11 | 11 | 11 |  |
| 12 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 13 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 14 | `edittext_html_condensewhite_swf8` | 80.1% | 249/311 | 311 | 311 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
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
| 33 | `asnative` | 55.9% | 19/34 | 31 | 34 | [4](ruffle-tests/_investigation/incomplete/ASNATIVE_ASNEW_PLAN.md) |
| 34 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 35 | `gettextextent` | 55.4% | 31/56 | 56 | 56 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 36 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 37 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 38 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 39 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 40 | `bitmap_filters` | 50.9% | 279/548 | 548 | 548 | [30](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 41 | `device_font_spacing` | 50.5% | 46/91 | 91 | 91 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 42 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 43 | `edittext_focus_selection` | 50.0% | 1/2 | 2 | 2 | [38](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 44 | `edittext_place_caret` | 50.0% | 1/2 | 2 | 2 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 45 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 46 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 |  |
| 47 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 48 | `loadmovienum_cross_version_prototype` | 46.2% | 6/13 | 13 | 9 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 49 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 50 | `edittext_input_newlines` | 44.4% | 4/9 | 8 | 9 | [48](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 51 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 52 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 53 | `define_local_with_paths` | 40.7% | 22/54 | 34 | 54 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 54 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 |  |
| 55 | `tab_ordering_events_mouse` | 40.0% | 26/65 | 59 | 65 | [46](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 56 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 57 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 58 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [35](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 59 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 60 | `swf5_to_6_cross_call` | 34.5% | 10/29 | 11 | 29 | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 61 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 62 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 63 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 64 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 65 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 66 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 67 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 68 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 69 | `cross_movie_root` | 30.0% | 3/10 | 10 | 10 |  |
| 70 | `loadmovie_registerclass` | 30.0% | 9/30 | 24 | 30 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 71 | `removed_target_clip_scope` | 29.7% | 11/37 | 37 | 35 | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 72 | `asnew` | 29.4% | 10/34 | 18 | 34 | [4](ruffle-tests/_investigation/incomplete/ASNATIVE_ASNEW_PLAN.md) |
| 73 | `default_names` | 28.8% | 15/52 | 48 | 52 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 74 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 75 | `swf6_to_5_cross_call` | 24.1% | 7/29 | 11 | 29 | [45](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 76 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 77 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 78 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 79 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 80 | `focus_remove` | 18.2% | 6/33 | 24 | 33 |  |
| 81 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 82 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 83 | `mcl_events_swf_version` | 15.9% | 37/232 | 37 | 232 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 84 | `focus_visibility_change` | 15.6% | 7/45 | 36 | 45 |  |
| 85 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 86 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 87 | `focus_keyboard_press` | 15.0% | 15/100 | 100 | 60 | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [14](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 88 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [32](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 89 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 90 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 91 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 | [54](ruffle-tests/_investigation/incomplete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 92 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 93 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 94 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 95 | `coerce_to_object_monkeypatch` | 12.4% | 16/129 | 112 | 129 | [54](ruffle-tests/_investigation/incomplete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 96 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 97 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 98 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 99 | `define_local` | 7.4% | 2/27 | 23 | 27 | [57](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 100 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 101 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 102 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 103 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 104 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 105 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 |  |
| 106 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 107 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 108 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 109 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 110 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [36](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 111 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 112 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [33](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 113 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 114 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 115 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [37](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 116 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [37](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 117 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 118 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 119 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 120 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 121 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 122 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [17](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 123 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [16](ruffle-tests/_investigation/incomplete/FUNCTION_EDGE_CASES_PLAN.md) |
| 124 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 125 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 126 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 127 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 128 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 129 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 130 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [14](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 131 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 132 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 133 | `geturl` | 0.0% | 0/7 | 0 | 7 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 134 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [18](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 135 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [19](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 136 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 137 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 138 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [37](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 139 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 140 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 141 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 142 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 143 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 144 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [22](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 145 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 146 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 147 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [55](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 148 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [43](ruffle-tests/_investigation/complete/STRING_PLAN.md) [47](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 149 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 150 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [28](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 151 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 152 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 153 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 154 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [58](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/incomplete/ASNATIVE_ASNEW_PLAN.md) | 2 | 0 | 2 |
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
| 16 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/incomplete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 1 | 2 |
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
| 30 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 15 | 2 |
| 31 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 32 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 33 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 7 | 1 |
| 34 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 35 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 10 | 2 |
| 36 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 12 | 3 |
| 37 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 1 | 3 |
| 38 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 2 | 2 |
| 39 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/incomplete/SOUND_CLASS_PLAN.md) | 2 | 1 | 1 |
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
| 54 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/incomplete/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 0 | 2 |
| 55 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 1 | 15 |
| 56 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 10 | 2 |
| 57 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 58 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 202 | 155 | 47 |
