# Ruffle Test Results (Filtered)

**Date**: 2026-03-06 23:19 UTC

**Git SHA**: `e2ad847e57`

**Run Duration**: 143m 14s

**Filtered**: 142 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 477 |
| Passing | **417** (87.4%) |
| Failing | 60 |
| Total expected lines | 71793 |
| Matching lines | 59203 (82.5%) |
| Mismatched lines | 12590 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 55 | 91.7% |
| Runtime Error | 4 | 6.7% |
| Compile Fail | 1 | 1.7% |

## Passing Tests

**417 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 16.9s |  |
| 2 | `action_to_integer` | 28 | 13.5s |  |
| 3 | `add` | 28 | 13.5s |  |
| 4 | `add2` | 354 | 13.6s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 13.3s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 13.5s |  |
| 7 | `add_swf5` | 28 | 13.3s |  |
| 8 | `arguments` | 127 | 13.3s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 13.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 13.4s |  |
| 11 | `array_constructor` | 30 | 13.3s |  |
| 12 | `array_enumerate` | 4 | 13.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 13.4s |  |
| 14 | `array_properties` | 36 | 13.3s |  |
| 15 | `array_prototyping` | 12 | 13.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 13.4s |  |
| 17 | `array_sort_random` | 443 | 13.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 13.4s |  |
| 19 | `array_trivial` | 209 | 13.3s |  |
| 20 | `as1_constructor_v6` | 35 | 13.2s |  |
| 21 | `as1_constructor_v7` | 35 | 13.3s |  |
| 22 | `as2_oop` | 13 | 13.5s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 13.5s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 13.7s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 13.6s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster` | 41 | 13.7s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 13.5s |  |
| 28 | `as_broadcaster_undef` | 89 | 13.4s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 29 | `as_set_prop_flags` | 79 | 13.5s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version` | 31 | 13.4s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version_swf5` | 1 | 13.3s |  |
| 32 | `as_set_prop_flags_version_swf6` | 1 | 13.3s |  |
| 33 | `as_set_prop_flags_version_swf7` | 1 | 13.5s |  |
| 34 | `as_set_prop_flags_version_swf8` | 1 | 13.4s |  |
| 35 | `as_set_prop_flags_version_swf9` | 1 | 13.3s |  |
| 36 | `as_transformed_flag` | 20 | 13.4s |  |
| 37 | `asnative` | 34 | 13.6s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 38 | `asnew` | 34 | 13.5s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `attach_movie` | 59 | 13.5s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 40 | `attach_movie_stop` | 3 | 13.3s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 41 | `bad_placeobject_clipaction` | 2 | 13.5s |  |
| 42 | `bad_swf_tag_past_eof` | 0 | 13.4s |  |
| 43 | `bitand` | 1058 | 16.0s |  |
| 44 | `bitmap_data_colortransform` | 0 | 13.6s |  |
| 45 | `bitmap_data_fillrect` | 0 | 13.5s |  |
| 46 | `bitmap_data_max_size_swf10` | 12 | 13.1s |  |
| 47 | `bitmap_data_max_size_swf9` | 10 | 13.2s |  |
| 48 | `bitmap_data_perlinnoise` | 0 | 14.2s |  |
| 49 | `bitmap_data_pixeldissolve_image` | 0 | 13.7s |  |
| 50 | `bitmapdata_applyfilter_colormatrix` | 0 | 13.6s |  |
| 51 | `bitor` | 1058 | 16.2s |  |
| 52 | `biturshift` | 14 | 14.3s |  |
| 53 | `biturshift_swf8` | 14 | 13.9s |  |
| 54 | `bitxor` | 1058 | 16.9s |  |
| 55 | `boxed_primitives` | 24 | 14.2s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 56 | `button_children` | 8 | 14.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_goto` | 4 | 14.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_order` | 2 | 14.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_properties_special_cases` | 22 | 14.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_v5` | 18 | 14.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_v6` | 18 | 13.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `call` | 63 | 14.4s | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) |
| 63 | `call_method_empty_name` | 1 | 14.1s |  |
| 64 | `capabilities_resolution` | 8 | 14.1s |  |
| 65 | `catch_references_registers` | 2 | 14.0s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 66 | `clip_constructors` | 8 | 14.2s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 67 | `clip_events` | 19 | 14.5s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 68 | `clone_sprite_types` | 24 | 13.9s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 69 | `closure_scope` | 7 | 14.1s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 70 | `color` | 57 | 14.3s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 71 | `color_transform` | 48 | 14.0s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 72 | `conflicting_instance_names` | 23 | 14.0s |  |
| 73 | `constructor_function` | 2 | 13.8s |  |
| 74 | `context_menu` | 39 | 13.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 75 | `context_menu_item` | 41 | 14.1s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 76 | `create_empty_movie_clip` | 3 | 13.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 77 | `define_function2` | 8 | 14.2s |  |
| 78 | `define_function2_preload` | 13 | 14.0s |  |
| 79 | `define_function2_preload_order` | 4 | 14.0s |  |
| 80 | `define_function_case_sensitive` | 2 | 13.8s |  |
| 81 | `delete` | 3 | 13.9s |  |
| 82 | `device_font_spacing` | 91 | 14.1s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 83 | `display_object_properties` | 2 | 14.0s |  |
| 84 | `divide_swf4` | 107 | 14.1s |  |
| 85 | `do_init_action` | 3 | 14.0s |  |
| 86 | `do_init_action_child` | 12 | 14.0s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 87 | `duplicate_movie_clip` | 20 | 14.2s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 88 | `duplicate_movie_clip_drawing` | 2 | 14.2s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 89 | `edittext_align` | 60 | 14.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 90 | `edittext_align_trailing_spaces_swf7` | 576 | 14.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 91 | `edittext_align_trailing_spaces_swf8` | 576 | 14.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 92 | `edittext_antialiastype` | 296 | 19.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 93 | `edittext_autosize` | 71 | 14.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 94 | `edittext_autosize_setter` | 20 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 95 | `edittext_default_format` | 221 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 96 | `edittext_default_format_font_style` | 335 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 97 | `edittext_font_size` | 45 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 98 | `edittext_hscroll` | 27 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 99 | `edittext_html_align_swf7` | 52 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_html_align_swf8` | 52 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_html_color` | 114 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_html_condensewhite_swf7` | 311 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_html_condensewhite_swf8` | 311 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_html_entity` | 4 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_html_roundtrip` | 17 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_html_swf7` | 5377 | 14.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_html_swf8` | 5377 | 14.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_leading` | 9 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_letter_spacing` | 15 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_margins` | 25 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_newline_stripping` | 64 | 17.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_programmatic_focus` | 12 | 13.1s | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_restrict` | 191 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_stylesheet` | 325 | 13.7s | [45](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_tag_indent` | 31 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_text_height_leading` | 20 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_underline` | 40 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_width_height` | 103 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `empty_movieclip_can_attach_movies` | 11 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 120 | `enumerate` | 64 | 13.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 121 | `equals` | 32 | 13.2s |  |
| 122 | `equals2_swf5` | 926 | 14.8s |  |
| 123 | `equals2_swf6` | 926 | 14.9s |  |
| 124 | `equals2_swf7` | 926 | 14.8s |  |
| 125 | `equals_swf4` | 665 | 13.9s |  |
| 126 | `equals_swf4_alt` | 32 | 13.2s |  |
| 127 | `equals_swf5` | 32 | 13.2s |  |
| 128 | `error` | 58 | 13.1s |  |
| 129 | `escape` | 14 | 13.1s |  |
| 130 | `execution_order1` | 5 | 13.3s |  |
| 131 | `execution_order2` | 7 | 13.2s |  |
| 132 | `execution_order3` | 4 | 13.2s |  |
| 133 | `execution_order4` | 12 | 13.3s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 134 | `export_assets` | 3 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 135 | `extends_chain` | 134 | 13.6s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 136 | `extends_native_type` | 11 | 13.1s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 137 | `external_interface` | 84 | 13.7s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 138 | `external_interface_escapexml` | 26 | 13.4s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 139 | `external_interface_jsquotestring` | 21 | 13.4s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 140 | `external_interface_toas_basic` | 354 | 13.7s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 141 | `external_interface_toxml_array` | 25 | 13.2s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 142 | `external_interface_toxml_basic` | 179 | 13.4s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 143 | `external_interface_unescapexml` | 40 | 13.3s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 144 | `focusrect_mouse_swf8` | 0 | 13.3s |  |
| 145 | `focusrect_mouse_swf9` | 0 | 13.3s |  |
| 146 | `focusrect_swf5` | 6 | 13.5s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 147 | `frame_size_translated_negative` | 21 | 13.3s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 148 | `frame_size_translated_positive` | 21 | 13.3s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 149 | `function_as_function` | 35 | 13.2s | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 150 | `function_base_clip` | 8 | 13.3s |  |
| 151 | `function_base_clip_readded` | 11 | 13.4s |  |
| 152 | `function_base_clip_removed` | 25 | 13.4s |  |
| 153 | `function_suppress_and_preload` | 28 | 13.4s |  |
| 154 | `funky_function_calls` | 56 | 13.3s | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 155 | `get_bytes_total` | 4 | 13.3s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 156 | `get_variable_in_scope` | 29 | 13.3s |  |
| 157 | `getproperty` | 28 | 13.3s |  |
| 158 | `getproperty_swf4` | 28 | 13.2s |  |
| 159 | `getproperty_swf5` | 28 | 13.2s |  |
| 160 | `gettextextent` | 56 | 13.2s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 161 | `global_array` | 3 | 13.3s |  |
| 162 | `global_is_bare` | 7 | 13.2s |  |
| 163 | `global_swf6_7_8` | 15 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 164 | `globals_swf5` | 304 | 13.6s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 165 | `globals_swf6` | 304 | 13.6s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 166 | `globals_swf7` | 304 | 13.5s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 167 | `globals_swf8` | 304 | 13.5s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 168 | `goto_advance1` | 6 | 13.2s |  |
| 169 | `goto_advance2` | 2 | 13.3s |  |
| 170 | `goto_both_ways1` | 3 | 15.2s |  |
| 171 | `goto_both_ways2` | 3 | 13.9s |  |
| 172 | `goto_execution_order` | 2 | 13.7s |  |
| 173 | `goto_execution_order2` | 2 | 13.8s |  |
| 174 | `goto_frame` | 12 | 13.9s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 175 | `goto_frame2` | 44 | 14.2s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 176 | `goto_frame_number` | 3 | 13.7s |  |
| 177 | `goto_label` | 17 | 13.6s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 178 | `goto_methods` | 40 | 13.3s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 179 | `goto_rewind1` | 1 | 13.2s |  |
| 180 | `goto_rewind2` | 3 | 13.2s |  |
| 181 | `goto_rewind3` | 2 | 13.3s |  |
| 182 | `greater_swf6` | 1175 | 15.3s |  |
| 183 | `greater_swf7` | 1175 | 15.2s |  |
| 184 | `greaterthan_swf5` | 1 | 13.2s |  |
| 185 | `greaterthan_swf8` | 1 | 13.1s |  |
| 186 | `has_own_property` | 32 | 13.2s |  |
| 187 | `hittest_lockroot` | 15 | 13.4s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 188 | `hittest_morph` | 70 | 13.3s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 189 | `hittest_winding_rule` | 12 | 13.4s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 190 | `infinite_recursion_function` | 4 | 13.2s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 191 | `infinite_recursion_function_in_setter` | 131 | 13.1s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 192 | `infinite_recursion_virtual_property` | 67 | 13.2s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 193 | `init_array_invalid` | 4 | 13.1s |  |
| 194 | `init_object_invalid` | 4 | 13.1s |  |
| 195 | `init_object_order` | 15 | 13.4s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 196 | `instanceof_coercions` | 88 | 13.6s | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 197 | `is_finite` | 49 | 13.4s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 198 | `is_finite_swf6` | 49 | 13.3s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 199 | `is_prototype_of` | 89 | 13.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 200 | `issue_1086` | 1 | 13.3s |  |
| 201 | `issue_1104` | 2 | 13.2s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 202 | `issue_1671` | 0 | 13.3s |  |
| 203 | `issue_1906` | 4 | 13.4s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 204 | `issue_2166` | 9 | 13.2s |  |
| 205 | `issue_3169` | 2 | 13.2s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 206 | `issue_3446` | 1 | 13.3s |  |
| 207 | `issue_3522` | 2 | 13.2s |  |
| 208 | `issue_4377` | 2 | 13.0s |  |
| 209 | `issue_710` | 4 | 13.2s |  |
| 210 | `issue_768` | 3 | 13.1s | [22](ruffle-tests/_investigation/complete/issue_768.md) |
| 211 | `issue_9327` | 2 | 13.2s |  |
| 212 | `issue_9885` | 2 | 13.2s |  |
| 213 | `lessthan` | 41 | 13.2s |  |
| 214 | `lessthan2_swf5` | 1226 | 15.2s |  |
| 215 | `lessthan2_swf6` | 1226 | 15.3s |  |
| 216 | `lessthan2_swf7` | 1226 | 15.3s |  |
| 217 | `lessthan_swf4` | 902 | 14.4s |  |
| 218 | `lessthan_swf4_alt` | 41 | 13.3s |  |
| 219 | `lessthan_swf5` | 41 | 13.4s |  |
| 220 | `local_to_global` | 49 | 13.1s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 221 | `localconnection_properties` | 8 | 13.0s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 222 | `lock_root` | 1 | 13.1s |  |
| 223 | `logical_ops_swf4` | 90 | 13.1s |  |
| 224 | `logical_ops_swf8` | 108 | 13.1s |  |
| 225 | `looping` | 6 | 13.0s |  |
| 226 | `mask_reapply` | 0 | 13.1s |  |
| 227 | `mask_with_drawing` | 0 | 13.1s |  |
| 228 | `math_min_max` | 101 | 13.1s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 229 | `math_swf6` | 530 | 13.4s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 230 | `math_swf7` | 530 | 13.4s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 231 | `math_swf8` | 530 | 13.4s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 232 | `matrix` | 171 | 13.4s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 233 | `movieclip_begin_gradient_fill` | 0 | 13.6s |  |
| 234 | `movieclip_blend_mode_property` | 35 | 13.3s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 235 | `movieclip_create_text_field` | 90 | 13.3s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 236 | `movieclip_default_state` | 69 | 13.2s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 237 | `movieclip_depth_methods` | 98 | 13.2s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 238 | `movieclip_focusenabled` | 99 | 13.1s | [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 239 | `movieclip_get_instance_at_depth` | 28 | 13.2s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 240 | `movieclip_hittest` | 92 | 13.2s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 241 | `movieclip_in_removed_button` | 4 | 13.0s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 242 | `movieclip_init_object` | 5 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 243 | `movieclip_line_gradient_style` | 0 | 13.9s |  |
| 244 | `movieclip_name_from_timeline` | 13 | 13.4s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 245 | `movieclip_prototype_extension` | 5 | 13.3s |  |
| 246 | `mutable_this` | 18 | 13.4s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 247 | `named_shapes` | 14 | 13.4s |  |
| 248 | `nan_scale` | 9 | 13.6s |  |
| 249 | `native_double_construct` | 12 | 13.6s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 250 | `native_objects_swf7` | 84 | 14.1s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 251 | `native_objects_swf8` | 84 | 14.1s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 252 | `nested_textfields_in_buttons` | 0 | 13.5s |  |
| 253 | `new_method_wrap` | 4 | 13.4s |  |
| 254 | `new_object_enumerate` | 7 | 13.5s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 255 | `new_object_wrap` | 4 | 13.4s |  |
| 256 | `o` | 3 | 13.4s |  |
| 257 | `object_constructor` | 33 | 13.4s |  |
| 258 | `object_function` | 32 | 13.4s |  |
| 259 | `object_properties` | 31 | 13.4s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 260 | `object_prototypes` | 74 | 13.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 261 | `object_resolve` | 38 | 13.4s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 262 | `object_string_coerce_swf5` | 62 | 13.5s | [32](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 263 | `object_string_coerce_swf6` | 68 | 13.4s | [32](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 264 | `on_construct` | 25 | 13.5s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 265 | `parse_float` | 74 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 266 | `parse_int` | 64 | 13.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 267 | `path_string` | 322 | 13.8s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 268 | `place_and_lookup` | 30 | 13.4s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 269 | `placeobject_occupied_depth` | 6 | 13.4s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 270 | `point` | 175 | 13.9s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 271 | `primitive_instanceof` | 37 | 13.4s |  |
| 272 | `primitive_type_globals` | 557 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 273 | `printjob_props_swf5` | 45 | 13.5s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 274 | `printjob_props_swf6` | 45 | 13.4s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 275 | `printjob_props_swf7` | 45 | 13.4s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 276 | `property_invalid_base_clip` | 36 | 13.5s |  |
| 277 | `prototype_delete` | 12 | 13.3s |  |
| 278 | `prototype_enumerate` | 5 | 13.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 279 | `prototype_properties` | 17 | 13.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 280 | `rectangle` | 745 | 14.3s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 281 | `recursive_prototypes` | 0 | 13.5s |  |
| 282 | `register_class_return_value` | 16 | 13.8s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 283 | `register_class_with_sound` | 11 | 13.8s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [40](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 284 | `register_globals_across_frames` | 15 | 15.1s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 285 | `register_underflow` | 26 | 13.7s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 286 | `remove_movie_clip` | 29 | 13.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 287 | `rewind_depth` | 30 | 13.7s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 288 | `root_global_parent` | 6 | 13.6s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 289 | `sandbox_type_local_file` | 1 | 13.6s |  |
| 290 | `sandbox_type_local_network` | 1 | 13.6s |  |
| 291 | `selection` | 454 | 13.8s | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 292 | `set_interval` | 27 | 13.9s | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 293 | `set_variable_scope` | 58 | 13.9s |  |
| 294 | `single_frame` | 1 | 13.6s |  |
| 295 | `slash_syntax` | 14 | 14.0s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 296 | `sound` | 628 | 14.0s | [40](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 297 | `sound_props_swf5` | 68 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 298 | `sound_props_swf6` | 68 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 299 | `sound_start_load` | 0 | 13.5s |  |
| 300 | `stage_display_state` | 16 | 13.5s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 301 | `stage_object_children` | 83 | 13.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 302 | `stage_object_enumerate` | 4 | 13.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 303 | `stage_object_properties` | 241 | 14.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 304 | `stage_object_properties_get_var` | 5 | 13.9s |  |
| 305 | `stage_object_properties_swf6` | 231 | 14.1s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 306 | `stage_property_representation` | 586 | 13.8s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 307 | `stage_scale_mode` | 39 | 14.1s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 308 | `strictequals_swf6` | 902 | 15.5s |  |
| 309 | `strictly_equals` | 7 | 13.9s |  |
| 310 | `string_coercion` | 117 | 14.3s | [43](ruffle-tests/_investigation/complete/string_coercion.md) |
| 311 | `string_methods` | 285 | 14.5s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 312 | `string_methods_negative_args` | 240 | 14.4s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 313 | `string_methods_swfv5` | 275 | 14.7s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 314 | `string_ops_swf6` | 95 | 14.8s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 315 | `string_paths_basic` | 4 | 14.5s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 316 | `string_paths_eval2` | 7 | 14.5s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 317 | `string_paths_hidden` | 54 | 14.3s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 318 | `string_paths_other` | 36 | 14.0s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 319 | `string_paths_unload` | 1 | 13.7s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 320 | `string_paths_variable_alias` | 4 | 13.8s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 321 | `string_paths_variable_scopes` | 5 | 13.7s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 322 | `stylesheet` | 283 | 14.6s |  |
| 323 | `stylesheet_transform` | 750 | 14.5s |  |
| 324 | `super_edge_cases` | 39 | 14.1s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 325 | `swf4_actions_bool` | 96 | 13.9s |  |
| 326 | `swf4_actions_coercion_order` | 158 | 13.8s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 327 | `swf4_bool` | 4 | 13.7s |  |
| 328 | `swf4_function_calls` | 7 | 14.1s |  |
| 329 | `swf5_encoding` | 3 | 14.0s |  |
| 330 | `swf5_global_funcs` | 232 | 13.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 331 | `swf5_no_closure` | 19 | 14.2s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 332 | `swf6_case_insensitive` | 42 | 14.3s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 333 | `swf6_global_funcs` | 232 | 14.4s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 334 | `swf6_string_as_bool` | 15 | 14.3s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 335 | `swf7_case_sensitive` | 44 | 14.4s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 336 | `swf7_global_funcs` | 232 | 14.7s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 337 | `tab_ordering_properties_tab_index_edge_case` | 4 | 14.1s |  |
| 338 | `target_clip_swf5` | 2 | 14.7s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 339 | `target_clip_swf6` | 2 | 14.3s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 340 | `target_path` | 14 | 14.0s |  |
| 341 | `tell_target` | 37 | 14.2s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 342 | `tell_target_invalid` | 6 | 14.5s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 343 | `tell_target_invalid_swf6` | 5 | 14.4s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 344 | `text_format` | 1146 | 14.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 345 | `text_format_display` | 21 | 14.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 346 | `text_format_font_max_length` | 2 | 14.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 347 | `text_format_rounding_swf7` | 840 | 14.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 348 | `text_format_rounding_swf8` | 840 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 349 | `textfield_background_color` | 11 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 350 | `textfield_border_color` | 11 | 14.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 351 | `textfield_cache_as_bitmap` | 1 | 14.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 352 | `textfield_maxchars` | 3 | 13.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 353 | `textfield_properties` | 44 | 14.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 354 | `textfield_props_swf5` | 175 | 14.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 355 | `textfield_props_swf6` | 210 | 14.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 356 | `textfield_props_swf7` | 210 | 14.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 357 | `textfield_props_swf8` | 210 | 15.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 358 | `textfield_text` | 7 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 359 | `textfield_variable` | 81 | 15.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 360 | `textsnapshot_available_text` | 20 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 361 | `textsnapshot_findtext` | 44 | 15.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 362 | `textsnapshot_gettext` | 55 | 15.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 363 | `textsnapshot_props_swf5` | 56 | 14.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 364 | `textsnapshot_props_swf6` | 56 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 365 | `textsnapshot_text_order` | 1 | 14.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 366 | `this_scoping` | 52 | 14.8s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 367 | `this_swf5` | 41 | 14.0s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 368 | `this_swf6` | 41 | 14.6s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 369 | `this_swf7` | 41 | 15.0s | [52](ruffle-tests/_investigation/complete/this_swf7.md) |
| 370 | `timeline_function_def` | 7 | 15.4s |  |
| 371 | `trace` | 8 | 13.7s |  |
| 372 | `transform` | 70 | 13.7s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 373 | `try_catch_finally` | 118 | 13.8s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 374 | `try_finally_simple` | 16 | 13.4s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 375 | `typeof` | 22 | 13.8s |  |
| 376 | `typeof_globals` | 7 | 13.6s |  |
| 377 | `uncaught_exception` | 1 | 13.8s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 378 | `uncaught_exception_bubbled` | 1 | 13.7s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 379 | `undefined_to_string_swf6` | 4 | 13.5s |  |
| 380 | `unescape` | 43 | 13.3s |  |
| 381 | `unload` | 52 | 13.5s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 382 | `unload_clip_event` | 4 | 13.2s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 383 | `use_hand_cursor` | 8 | 13.0s |  |
| 384 | `variable_args` | 5 | 13.2s |  |
| 385 | `waitforframe` | 7 | 13.1s |  |
| 386 | `waitforframe2` | 16 | 13.2s |  |
| 387 | `watch` | 117 | 13.3s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 388 | `watch_textfield` | 12 | 13.1s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 389 | `watch_virtual_property_proto` | 2 | 13.1s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 390 | `with` | 49 | 13.1s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 391 | `with_return` | 2 | 13.1s |  |
| 392 | `with_variable_scopes` | 43 | 13.1s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 393 | `xml` | 15 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 394 | `xml_append_child` | 28 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 395 | `xml_append_child_with_parent` | 20 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 396 | `xml_cdata` | 11 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 397 | `xml_child_nodes_edge_cases` | 4 | 13.0s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 398 | `xml_clone_expandos` | 19 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 399 | `xml_first_last_child` | 8 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 400 | `xml_has_child_nodes` | 3 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 401 | `xml_idmap` | 21 | 13.7s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 402 | `xml_ignore_comments` | 21 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 403 | `xml_ignore_white` | 34 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 404 | `xml_insert_before` | 20 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 405 | `xml_inspect_createmethods` | 15 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 406 | `xml_inspect_doctype` | 7 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 407 | `xml_inspect_parsexml` | 62 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 408 | `xml_inspect_xmldecl` | 7 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 409 | `xml_namespaces` | 203 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 410 | `xml_parent_and_child` | 5 | 13.0s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 411 | `xml_remove_node` | 22 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 412 | `xml_reparenting` | 14 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 413 | `xml_siblings` | 10 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 414 | `xml_to_string` | 13 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 415 | `xml_to_string_comment` | 1 | 13.0s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 416 | `xml_unescaping` | 23 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 417 | `xmlnode_proto` | 1 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**18 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `interface_implements_op` | 97.9% | 46 | 47 | 1 | [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 3 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 5 | `define_local_with_paths` | 94.4% | 51 | 54 | 3 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 6 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 7 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 9 | `selection_handlers` | 77.8% | 21 | 27 | 6 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 10 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 11 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 12 | `register_class` | 66.7% | 44 | 66 | 22 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 13 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 14 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 15 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 16 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 17 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 18 | `issue_2030` | 50.0% | 2 | 4 | 2 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_1` | exit code -6 | 13.7s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_2` | exit code -6 | 13.9s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `movieclip_invalid_get_bounds_6` | exit code -6 | 36.9s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_invalid_get_bounds_7` | exit code -6 | 37.1s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

No timeouts.

## All Output Mismatches

**55 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `interface_implements_op` | 97.9% | 46/47 | 47 | 47 | [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 3 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 5 | `define_local_with_paths` | 94.4% | 51/54 | 54 | 54 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 6 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 7 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 9 | `selection_handlers` | 77.8% | 21/27 | 23 | 27 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 10 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 11 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 12 | `register_class` | 66.7% | 44/66 | 65 | 66 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 13 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 14 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 15 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 16 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 17 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 18 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 19 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 20 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 21 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 22 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 23 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 24 | `removed_target_clip_scope` | 29.7% | 11/37 | 37 | 35 | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 25 | `default_names` | 28.8% | 15/52 | 48 | 52 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 26 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 27 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 28 | `timer_run_actions` | 16.7% | 3/18 | 17 | 18 | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 29 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 30 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 31 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 32 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 33 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 34 | `define_local` | 7.4% | 2/27 | 23 | 27 | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 35 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 36 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 37 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 38 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 39 | `global_proto_decls` | 0.2% | 11/4497 | 685 | 4497 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 40 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 41 | `global_proto_decls_delete` | 0.0% | 1/4158 | 309 | 4158 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 42 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 43 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 44 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 45 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 46 | `geturl` | 0.0% | 0/7 | 0 | 7 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 47 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 48 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 49 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 50 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 51 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 52 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 53 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 54 | `string_paths_timer` | 0.0% | 0/41 | 41 | 0 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 55 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

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
| 10 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 0 | 0 | 0 |
| 11 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 0 | 0 | 0 |
| 12 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 13 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 14 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 15 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 1 | 1 | 0 |
| 16 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 17 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 18 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 5 | 4 | 1 |
| 19 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 29 | 25 | 4 |
| 20 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 16 | 5 | 11 |
| 21 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 22 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 23 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 16 | 2 | 14 |
| 24 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 1 | 0 | 1 |
| 25 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 0 | 0 | 0 |
| 26 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 27 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 28 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 0 | 0 | 0 |
| 29 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 56 | 31 | 25 |
| 30 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 0 | 0 | 0 |
| 31 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 14 | 14 | 0 |
| 32 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 33 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 34 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 7 | 1 |
| 35 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 36 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 11 | 1 |
| 37 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 12 | 3 |
| 38 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 0 | 0 | 0 |
| 39 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 3 | 2 | 1 |
| 40 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 41 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 42 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 43 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 44 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 45 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 46 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 3 | 3 | 0 |
| 47 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) | 1 | 1 | 0 |
| 48 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 18 | 14 | 4 |
| 49 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 58 | 53 | 5 |
| 50 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 51 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 52 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 53 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 2 | 1 | 1 |
| 54 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 55 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 1 | 1 |
| 56 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 5 | 11 |
| 57 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 9 | 7 | 2 |
| 58 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 59 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 25 | 25 | 0 |
| | *(tests not in any document)* | 153 | 152 | 1 |
