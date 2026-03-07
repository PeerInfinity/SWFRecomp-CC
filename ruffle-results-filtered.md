# Ruffle Test Results (Filtered)

**Date**: 2026-03-07 00:21 UTC

**Git SHA**: `b1b89de37d`

**Run Duration**: 141m 28s

**Filtered**: 142 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 477 |
| Passing | **415** (87.0%) |
| Failing | 62 |
| Total expected lines | 71793 |
| Matching lines | 59231 (82.5%) |
| Mismatched lines | 12562 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 57 | 91.9% |
| Runtime Error | 4 | 6.5% |
| Compile Fail | 1 | 1.6% |

## Passing Tests

**415 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 13.3s |  |
| 2 | `action_to_integer` | 28 | 13.1s |  |
| 3 | `add` | 28 | 13.1s |  |
| 4 | `add2` | 354 | 13.3s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 13.0s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 13.0s |  |
| 7 | `add_swf5` | 28 | 13.0s |  |
| 8 | `arguments` | 127 | 13.0s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 13.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 13.1s |  |
| 11 | `array_constructor` | 30 | 13.1s |  |
| 12 | `array_enumerate` | 4 | 13.0s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 13.1s |  |
| 14 | `array_properties` | 36 | 13.1s |  |
| 15 | `array_prototyping` | 12 | 13.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 13.1s |  |
| 17 | `array_sort_random` | 443 | 13.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 13.2s |  |
| 19 | `array_trivial` | 209 | 13.2s |  |
| 20 | `as1_constructor_v6` | 35 | 13.0s |  |
| 21 | `as1_constructor_v7` | 35 | 13.1s |  |
| 22 | `as2_oop` | 13 | 13.2s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 13.3s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 13.3s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 13.3s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster` | 41 | 13.1s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 13.0s |  |
| 28 | `as_broadcaster_undef` | 89 | 13.1s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 29 | `as_set_prop_flags` | 79 | 13.1s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version` | 31 | 13.0s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version_swf5` | 1 | 13.1s |  |
| 32 | `as_set_prop_flags_version_swf6` | 1 | 13.1s |  |
| 33 | `as_set_prop_flags_version_swf7` | 1 | 13.0s |  |
| 34 | `as_set_prop_flags_version_swf8` | 1 | 13.1s |  |
| 35 | `as_set_prop_flags_version_swf9` | 1 | 13.1s |  |
| 36 | `as_transformed_flag` | 20 | 13.1s |  |
| 37 | `asnative` | 34 | 13.1s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 38 | `asnew` | 34 | 13.1s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `attach_movie` | 59 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 40 | `attach_movie_stop` | 3 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 41 | `bad_placeobject_clipaction` | 2 | 13.0s |  |
| 42 | `bad_swf_tag_past_eof` | 0 | 13.0s |  |
| 43 | `bitand` | 1058 | 15.5s |  |
| 44 | `bitmap_data_colortransform` | 0 | 13.3s |  |
| 45 | `bitmap_data_fillrect` | 0 | 13.2s |  |
| 46 | `bitmap_data_max_size_swf10` | 12 | 13.1s |  |
| 47 | `bitmap_data_max_size_swf9` | 10 | 13.0s |  |
| 48 | `bitmap_data_perlinnoise` | 0 | 13.8s |  |
| 49 | `bitmap_data_pixeldissolve_image` | 0 | 13.5s |  |
| 50 | `bitmapdata_applyfilter_colormatrix` | 0 | 13.3s |  |
| 51 | `bitor` | 1058 | 15.4s |  |
| 52 | `biturshift` | 14 | 13.4s |  |
| 53 | `biturshift_swf8` | 14 | 13.2s |  |
| 54 | `bitxor` | 1058 | 15.8s |  |
| 55 | `boxed_primitives` | 24 | 13.4s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 56 | `button_children` | 8 | 13.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_goto` | 4 | 13.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_order` | 2 | 13.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_properties_special_cases` | 22 | 13.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_v5` | 18 | 13.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_v6` | 18 | 13.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `call` | 63 | 13.4s | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) |
| 63 | `call_method_empty_name` | 1 | 13.2s |  |
| 64 | `capabilities_resolution` | 8 | 13.2s |  |
| 65 | `catch_references_registers` | 2 | 13.1s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 66 | `clip_constructors` | 8 | 13.3s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 67 | `clip_events` | 19 | 13.5s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 68 | `clone_sprite_types` | 24 | 13.2s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 69 | `closure_scope` | 7 | 13.2s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 70 | `color` | 57 | 13.5s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 71 | `color_transform` | 48 | 13.3s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 72 | `conflicting_instance_names` | 23 | 13.3s |  |
| 73 | `constructor_function` | 2 | 13.2s |  |
| 74 | `context_menu` | 39 | 13.2s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 75 | `context_menu_item` | 41 | 13.2s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 76 | `create_empty_movie_clip` | 3 | 13.3s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 77 | `define_function2` | 8 | 13.2s |  |
| 78 | `define_function2_preload` | 13 | 13.2s |  |
| 79 | `define_function2_preload_order` | 4 | 13.2s |  |
| 80 | `define_function_case_sensitive` | 2 | 13.2s |  |
| 81 | `define_local` | 27 | 13.2s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 82 | `delete` | 3 | 13.3s |  |
| 83 | `device_font_spacing` | 91 | 13.3s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 84 | `display_object_properties` | 2 | 13.2s |  |
| 85 | `divide_swf4` | 107 | 13.2s |  |
| 86 | `do_init_action` | 3 | 13.3s |  |
| 87 | `do_init_action_child` | 12 | 13.3s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 88 | `duplicate_movie_clip` | 20 | 13.3s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 89 | `duplicate_movie_clip_drawing` | 2 | 13.2s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 90 | `edittext_align` | 60 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 91 | `edittext_align_trailing_spaces_swf7` | 576 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 92 | `edittext_align_trailing_spaces_swf8` | 576 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 93 | `edittext_antialiastype` | 296 | 15.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 94 | `edittext_autosize` | 71 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 95 | `edittext_autosize_setter` | 20 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 96 | `edittext_default_format` | 221 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 97 | `edittext_default_format_font_style` | 335 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 98 | `edittext_font_size` | 45 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 99 | `edittext_hscroll` | 27 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_html_align_swf7` | 52 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_html_align_swf8` | 52 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_html_color` | 114 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_html_condensewhite_swf7` | 311 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_html_condensewhite_swf8` | 311 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_html_entity` | 4 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_html_roundtrip` | 17 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_html_swf7` | 5377 | 14.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_html_swf8` | 5377 | 14.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_leading` | 9 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_letter_spacing` | 15 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_margins` | 25 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_newline_stripping` | 64 | 17.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_programmatic_focus` | 12 | 13.2s | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_restrict` | 191 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_stylesheet` | 325 | 13.7s | [45](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_tag_indent` | 31 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_text_height_leading` | 20 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_underline` | 40 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_width_height` | 103 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `empty_movieclip_can_attach_movies` | 11 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 121 | `enumerate` | 64 | 13.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 122 | `equals` | 32 | 13.2s |  |
| 123 | `equals2_swf5` | 926 | 14.9s |  |
| 124 | `equals2_swf6` | 926 | 14.9s |  |
| 125 | `equals2_swf7` | 926 | 14.8s |  |
| 126 | `equals_swf4` | 665 | 14.0s |  |
| 127 | `equals_swf4_alt` | 32 | 13.3s |  |
| 128 | `equals_swf5` | 32 | 13.2s |  |
| 129 | `error` | 58 | 13.4s |  |
| 130 | `escape` | 14 | 13.3s |  |
| 131 | `execution_order1` | 5 | 13.4s |  |
| 132 | `execution_order2` | 7 | 13.3s |  |
| 133 | `execution_order3` | 4 | 13.2s |  |
| 134 | `execution_order4` | 12 | 13.5s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 135 | `export_assets` | 3 | 13.5s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 136 | `extends_chain` | 134 | 13.7s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 137 | `extends_native_type` | 11 | 13.3s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 138 | `external_interface` | 84 | 20.6s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 139 | `external_interface_escapexml` | 26 | 13.2s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 140 | `external_interface_jsquotestring` | 21 | 13.3s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 141 | `external_interface_toas_basic` | 354 | 13.5s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 142 | `external_interface_toxml_array` | 25 | 13.2s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 143 | `external_interface_toxml_basic` | 179 | 13.3s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 144 | `external_interface_unescapexml` | 40 | 13.2s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 145 | `focusrect_mouse_swf8` | 0 | 13.1s |  |
| 146 | `focusrect_mouse_swf9` | 0 | 13.1s |  |
| 147 | `focusrect_swf5` | 6 | 13.4s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 148 | `frame_size_translated_negative` | 21 | 13.2s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 149 | `frame_size_translated_positive` | 21 | 13.3s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 150 | `function_as_function` | 35 | 13.2s | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 151 | `function_base_clip` | 8 | 13.2s |  |
| 152 | `function_base_clip_readded` | 11 | 13.3s |  |
| 153 | `function_base_clip_removed` | 25 | 13.3s |  |
| 154 | `function_suppress_and_preload` | 28 | 13.3s |  |
| 155 | `funky_function_calls` | 56 | 13.2s | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 156 | `get_bytes_total` | 4 | 13.2s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 157 | `get_variable_in_scope` | 29 | 13.2s |  |
| 158 | `getproperty` | 28 | 13.2s |  |
| 159 | `getproperty_swf4` | 28 | 13.2s |  |
| 160 | `getproperty_swf5` | 28 | 13.2s |  |
| 161 | `gettextextent` | 56 | 13.2s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 162 | `global_array` | 3 | 13.1s |  |
| 163 | `global_is_bare` | 7 | 13.1s |  |
| 164 | `global_swf6_7_8` | 15 | 13.4s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 165 | `globals_swf5` | 304 | 13.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 166 | `globals_swf6` | 304 | 13.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 167 | `globals_swf7` | 304 | 13.5s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 168 | `globals_swf8` | 304 | 13.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 169 | `goto_advance1` | 6 | 13.2s |  |
| 170 | `goto_advance2` | 2 | 13.2s |  |
| 171 | `goto_both_ways1` | 3 | 14.4s |  |
| 172 | `goto_both_ways2` | 3 | 13.9s |  |
| 173 | `goto_execution_order` | 2 | 14.2s |  |
| 174 | `goto_execution_order2` | 2 | 13.7s |  |
| 175 | `goto_frame` | 12 | 13.8s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 176 | `goto_frame2` | 44 | 14.2s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 177 | `goto_frame_number` | 3 | 13.6s |  |
| 178 | `goto_label` | 17 | 13.6s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 179 | `goto_methods` | 40 | 13.7s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 180 | `goto_rewind1` | 1 | 13.5s |  |
| 181 | `goto_rewind2` | 3 | 13.8s |  |
| 182 | `goto_rewind3` | 2 | 13.5s |  |
| 183 | `greater_swf6` | 1175 | 15.7s |  |
| 184 | `greater_swf7` | 1175 | 15.6s |  |
| 185 | `greaterthan_swf5` | 1 | 13.6s |  |
| 186 | `greaterthan_swf8` | 1 | 13.5s |  |
| 187 | `has_own_property` | 32 | 13.3s |  |
| 188 | `hittest_lockroot` | 15 | 13.5s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 189 | `hittest_morph` | 70 | 13.7s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 190 | `hittest_winding_rule` | 12 | 13.8s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 191 | `infinite_recursion_function` | 4 | 13.4s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 192 | `infinite_recursion_function_in_setter` | 131 | 13.4s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 193 | `infinite_recursion_virtual_property` | 67 | 13.5s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 194 | `init_array_invalid` | 4 | 13.5s |  |
| 195 | `init_object_invalid` | 4 | 13.3s |  |
| 196 | `init_object_order` | 15 | 13.6s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 197 | `instanceof_coercions` | 88 | 13.6s | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 198 | `is_finite` | 49 | 13.3s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 199 | `is_finite_swf6` | 49 | 13.3s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 200 | `is_prototype_of` | 89 | 13.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 201 | `issue_1086` | 1 | 13.2s |  |
| 202 | `issue_1104` | 2 | 13.3s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 203 | `issue_1671` | 0 | 13.3s |  |
| 204 | `issue_1906` | 4 | 13.4s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 205 | `issue_2166` | 9 | 13.4s |  |
| 206 | `issue_3169` | 2 | 13.4s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 207 | `issue_3446` | 1 | 13.2s |  |
| 208 | `issue_3522` | 2 | 13.4s |  |
| 209 | `issue_4377` | 2 | 13.4s |  |
| 210 | `issue_710` | 4 | 13.4s |  |
| 211 | `issue_9327` | 2 | 13.7s |  |
| 212 | `issue_9885` | 2 | 13.4s |  |
| 213 | `lessthan` | 41 | 13.5s |  |
| 214 | `lessthan2_swf5` | 1226 | 15.4s |  |
| 215 | `lessthan2_swf6` | 1226 | 15.4s |  |
| 216 | `lessthan2_swf7` | 1226 | 15.5s |  |
| 217 | `lessthan_swf4` | 902 | 14.6s |  |
| 218 | `lessthan_swf4_alt` | 41 | 13.4s |  |
| 219 | `lessthan_swf5` | 41 | 13.3s |  |
| 220 | `local_to_global` | 49 | 13.9s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 221 | `localconnection_properties` | 8 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 222 | `lock_root` | 1 | 13.6s |  |
| 223 | `logical_ops_swf4` | 90 | 13.6s |  |
| 224 | `logical_ops_swf8` | 108 | 13.6s |  |
| 225 | `looping` | 6 | 13.5s |  |
| 226 | `mask_reapply` | 0 | 13.5s |  |
| 227 | `mask_with_drawing` | 0 | 13.5s |  |
| 228 | `math_min_max` | 101 | 13.5s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 229 | `math_swf6` | 530 | 13.8s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 230 | `math_swf7` | 530 | 13.7s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 231 | `math_swf8` | 530 | 13.7s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 232 | `matrix` | 171 | 13.7s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 233 | `movieclip_begin_gradient_fill` | 0 | 14.2s |  |
| 234 | `movieclip_blend_mode_property` | 35 | 13.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 235 | `movieclip_create_text_field` | 90 | 14.0s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 236 | `movieclip_default_state` | 69 | 13.6s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 237 | `movieclip_depth_methods` | 98 | 13.6s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 238 | `movieclip_focusenabled` | 99 | 13.6s | [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 239 | `movieclip_get_instance_at_depth` | 28 | 13.5s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 240 | `movieclip_hittest` | 92 | 13.4s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 241 | `movieclip_in_removed_button` | 4 | 13.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 242 | `movieclip_init_object` | 5 | 13.6s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 243 | `movieclip_line_gradient_style` | 0 | 14.1s |  |
| 244 | `movieclip_name_from_timeline` | 13 | 13.6s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 245 | `movieclip_prototype_extension` | 5 | 13.6s |  |
| 246 | `mutable_this` | 18 | 13.6s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 247 | `named_shapes` | 14 | 13.5s |  |
| 248 | `nan_scale` | 9 | 13.6s |  |
| 249 | `native_double_construct` | 12 | 13.7s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 250 | `native_objects_swf7` | 84 | 14.0s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 251 | `native_objects_swf8` | 84 | 14.0s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 252 | `nested_textfields_in_buttons` | 0 | 13.5s |  |
| 253 | `new_method_wrap` | 4 | 13.8s |  |
| 254 | `new_object_enumerate` | 7 | 13.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 255 | `new_object_wrap` | 4 | 13.9s |  |
| 256 | `o` | 3 | 13.8s |  |
| 257 | `object_constructor` | 33 | 13.8s |  |
| 258 | `object_function` | 32 | 13.8s |  |
| 259 | `object_properties` | 31 | 14.0s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 260 | `object_prototypes` | 74 | 13.6s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 261 | `object_resolve` | 38 | 13.6s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 262 | `object_string_coerce_swf5` | 62 | 13.7s | [32](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 263 | `object_string_coerce_swf6` | 68 | 13.7s | [32](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 264 | `on_construct` | 25 | 13.7s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 265 | `parse_float` | 74 | 13.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 266 | `parse_int` | 64 | 14.0s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 267 | `path_string` | 322 | 13.9s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 268 | `place_and_lookup` | 30 | 13.7s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 269 | `placeobject_occupied_depth` | 6 | 13.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 270 | `point` | 175 | 14.0s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 271 | `primitive_instanceof` | 37 | 13.8s |  |
| 272 | `primitive_type_globals` | 557 | 13.7s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 273 | `printjob_props_swf5` | 45 | 13.5s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 274 | `printjob_props_swf6` | 45 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 275 | `printjob_props_swf7` | 45 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 276 | `property_invalid_base_clip` | 36 | 13.7s |  |
| 277 | `prototype_delete` | 12 | 13.3s |  |
| 278 | `prototype_enumerate` | 5 | 13.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 279 | `prototype_properties` | 17 | 13.6s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 280 | `rectangle` | 745 | 14.4s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 281 | `recursive_prototypes` | 0 | 13.4s |  |
| 282 | `register_class_return_value` | 16 | 13.6s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 283 | `register_class_with_sound` | 11 | 13.6s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [40](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 284 | `register_globals_across_frames` | 15 | 13.9s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 285 | `register_underflow` | 26 | 13.4s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 286 | `remove_movie_clip` | 29 | 13.5s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 287 | `rewind_depth` | 30 | 13.6s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 288 | `root_global_parent` | 6 | 13.5s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 289 | `sandbox_type_local_file` | 1 | 13.4s |  |
| 290 | `sandbox_type_local_network` | 1 | 13.3s |  |
| 291 | `selection` | 454 | 13.6s | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 292 | `set_interval` | 27 | 13.6s | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 293 | `set_variable_scope` | 58 | 13.4s |  |
| 294 | `single_frame` | 1 | 13.6s |  |
| 295 | `slash_syntax` | 14 | 13.5s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 296 | `sound` | 628 | 13.7s | [40](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 297 | `sound_props_swf5` | 68 | 13.5s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 298 | `sound_props_swf6` | 68 | 13.5s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 299 | `sound_start_load` | 0 | 13.4s |  |
| 300 | `stage_display_state` | 16 | 13.4s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 301 | `stage_object_enumerate` | 4 | 13.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 302 | `stage_object_properties` | 241 | 13.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 303 | `stage_object_properties_get_var` | 5 | 13.4s |  |
| 304 | `stage_object_properties_swf6` | 231 | 13.7s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 305 | `stage_property_representation` | 586 | 13.4s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 306 | `stage_scale_mode` | 39 | 13.5s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 307 | `strictequals_swf6` | 902 | 14.8s |  |
| 308 | `strictly_equals` | 7 | 13.3s |  |
| 309 | `string_coercion` | 117 | 13.6s | [43](ruffle-tests/_investigation/complete/string_coercion.md) |
| 310 | `string_methods` | 285 | 13.9s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 311 | `string_methods_negative_args` | 240 | 13.6s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 312 | `string_methods_swfv5` | 275 | 14.0s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 313 | `string_ops_swf6` | 95 | 13.4s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 314 | `string_paths_basic` | 4 | 13.5s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 315 | `string_paths_eval2` | 7 | 13.6s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 316 | `string_paths_hidden` | 54 | 13.5s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 317 | `string_paths_other` | 36 | 13.5s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 318 | `string_paths_unload` | 1 | 13.8s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 319 | `string_paths_variable_alias` | 4 | 13.6s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 320 | `string_paths_variable_scopes` | 5 | 13.6s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 321 | `stylesheet` | 283 | 14.1s |  |
| 322 | `stylesheet_transform` | 750 | 14.2s |  |
| 323 | `super_edge_cases` | 39 | 13.8s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 324 | `swf4_actions_bool` | 96 | 13.6s |  |
| 325 | `swf4_actions_coercion_order` | 158 | 13.6s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 326 | `swf4_bool` | 4 | 13.4s |  |
| 327 | `swf4_function_calls` | 7 | 14.0s |  |
| 328 | `swf5_encoding` | 3 | 13.5s |  |
| 329 | `swf5_global_funcs` | 232 | 13.4s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 330 | `swf5_no_closure` | 19 | 13.4s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 331 | `swf6_case_insensitive` | 42 | 13.4s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 332 | `swf6_global_funcs` | 232 | 13.4s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 333 | `swf6_string_as_bool` | 15 | 13.4s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 334 | `swf7_case_sensitive` | 44 | 13.6s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 335 | `swf7_global_funcs` | 232 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 336 | `tab_ordering_properties_tab_index_edge_case` | 4 | 13.2s |  |
| 337 | `target_clip_swf5` | 2 | 13.3s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 338 | `target_clip_swf6` | 2 | 13.3s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 339 | `target_path` | 14 | 13.4s |  |
| 340 | `tell_target` | 37 | 13.4s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 341 | `tell_target_invalid` | 6 | 13.5s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 342 | `tell_target_invalid_swf6` | 5 | 13.4s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 343 | `text_format` | 1146 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 344 | `text_format_display` | 21 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 345 | `text_format_font_max_length` | 2 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 346 | `text_format_rounding_swf7` | 840 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 347 | `text_format_rounding_swf8` | 840 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 348 | `textfield_background_color` | 11 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 349 | `textfield_border_color` | 11 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 350 | `textfield_cache_as_bitmap` | 1 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 351 | `textfield_maxchars` | 3 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 352 | `textfield_properties` | 44 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 353 | `textfield_props_swf5` | 175 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 354 | `textfield_props_swf6` | 210 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 355 | `textfield_props_swf7` | 210 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 356 | `textfield_props_swf8` | 210 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 357 | `textfield_text` | 7 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 358 | `textfield_variable` | 81 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 359 | `textsnapshot_available_text` | 20 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 360 | `textsnapshot_findtext` | 44 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 361 | `textsnapshot_gettext` | 55 | 13.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 362 | `textsnapshot_props_swf5` | 56 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 363 | `textsnapshot_props_swf6` | 56 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 364 | `textsnapshot_text_order` | 1 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 365 | `this_scoping` | 52 | 13.4s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 366 | `this_swf5` | 41 | 13.4s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 367 | `this_swf6` | 41 | 13.9s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 368 | `this_swf7` | 41 | 13.4s | [52](ruffle-tests/_investigation/complete/this_swf7.md) |
| 369 | `timeline_function_def` | 7 | 13.5s |  |
| 370 | `trace` | 8 | 13.2s |  |
| 371 | `transform` | 70 | 13.2s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 372 | `try_catch_finally` | 118 | 13.3s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 373 | `try_finally_simple` | 16 | 13.1s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 374 | `typeof` | 22 | 13.1s |  |
| 375 | `typeof_globals` | 7 | 13.1s |  |
| 376 | `uncaught_exception` | 1 | 13.2s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 377 | `uncaught_exception_bubbled` | 1 | 13.2s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 378 | `undefined_to_string_swf6` | 4 | 13.1s |  |
| 379 | `unescape` | 43 | 13.1s |  |
| 380 | `unload` | 52 | 13.3s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 381 | `unload_clip_event` | 4 | 13.3s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 382 | `use_hand_cursor` | 8 | 13.2s |  |
| 383 | `variable_args` | 5 | 13.3s |  |
| 384 | `waitforframe` | 7 | 13.2s |  |
| 385 | `waitforframe2` | 16 | 13.2s |  |
| 386 | `watch` | 117 | 13.6s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 387 | `watch_textfield` | 12 | 13.3s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 388 | `watch_virtual_property_proto` | 2 | 13.4s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 389 | `with` | 49 | 13.4s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 390 | `with_return` | 2 | 13.4s |  |
| 391 | `xml` | 15 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 392 | `xml_append_child` | 28 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 393 | `xml_append_child_with_parent` | 20 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 394 | `xml_cdata` | 11 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 395 | `xml_child_nodes_edge_cases` | 4 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 396 | `xml_clone_expandos` | 19 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 397 | `xml_first_last_child` | 8 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 398 | `xml_has_child_nodes` | 3 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 399 | `xml_idmap` | 21 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 400 | `xml_ignore_comments` | 21 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 401 | `xml_ignore_white` | 34 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 402 | `xml_insert_before` | 20 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 403 | `xml_inspect_createmethods` | 15 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 404 | `xml_inspect_doctype` | 7 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 405 | `xml_inspect_parsexml` | 62 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 406 | `xml_inspect_xmldecl` | 7 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 407 | `xml_namespaces` | 203 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 408 | `xml_parent_and_child` | 5 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 409 | `xml_remove_node` | 22 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 410 | `xml_reparenting` | 14 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 411 | `xml_siblings` | 10 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 412 | `xml_to_string` | 13 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 413 | `xml_to_string_comment` | 1 | 13.0s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 414 | `xml_unescaping` | 23 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 415 | `xmlnode_proto` | 1 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**21 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `interface_implements_op` | 97.9% | 46 | 47 | 1 | [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 3 | `stage_object_children` | 97.6% | 81 | 83 | 2 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 4 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 5 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 6 | `with_variable_scopes` | 95.3% | 41 | 43 | 2 | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 7 | `define_local_with_paths` | 94.4% | 51 | 54 | 3 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 8 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 9 | `movieclip_setmask` | 85.7% | 12 | 14 | 2 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 10 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 12 | `selection_handlers` | 77.8% | 21 | 27 | 6 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 13 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 14 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 15 | `register_class` | 66.7% | 44 | 66 | 22 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 16 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 17 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 18 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 19 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 20 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 21 | `issue_2030` | 50.0% | 2 | 4 | 2 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_1` | exit code -6 | 14.2s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_2` | exit code -6 | 14.4s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `movieclip_invalid_get_bounds_6` | exit code -6 | 37.6s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_invalid_get_bounds_7` | exit code -6 | 37.7s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

No timeouts.

## All Output Mismatches

**57 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `interface_implements_op` | 97.9% | 46/47 | 47 | 47 | [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 3 | `stage_object_children` | 97.6% | 81/83 | 83 | 83 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 4 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 5 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 6 | `with_variable_scopes` | 95.3% | 41/43 | 43 | 43 | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 7 | `define_local_with_paths` | 94.4% | 51/54 | 54 | 54 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 8 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 9 | `movieclip_setmask` | 85.7% | 12/14 | 14 | 14 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 10 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 12 | `selection_handlers` | 77.8% | 21/27 | 23 | 27 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 13 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 14 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 15 | `register_class` | 66.7% | 44/66 | 65 | 66 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 16 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 17 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 18 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 19 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 20 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 21 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 22 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 23 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 24 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 25 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 26 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 27 | `removed_target_clip_scope` | 29.7% | 11/37 | 37 | 35 | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 28 | `default_names` | 28.8% | 15/52 | 48 | 52 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 29 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 30 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 31 | `timer_run_actions` | 16.7% | 3/18 | 17 | 18 | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 32 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 33 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 34 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 35 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 36 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 37 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 38 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 39 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 40 | `global_proto_decls` | 0.2% | 11/4497 | 685 | 4497 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 41 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 42 | `global_proto_decls_delete` | 0.0% | 1/4158 | 309 | 4158 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 43 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 44 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 45 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 46 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 47 | `geturl` | 0.0% | 0/7 | 0 | 7 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 48 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 49 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 50 | `issue_768` | 0.0% | 0/3 | 3 | 3 | [22](ruffle-tests/_investigation/complete/issue_768.md) |
| 51 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 52 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 53 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 54 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 55 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 56 | `string_paths_timer` | 0.0% | 0/41 | 41 | 0 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 57 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

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
| 22 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 0 | 1 |
| 23 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 16 | 2 | 14 |
| 24 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 1 | 0 | 1 |
| 25 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 0 | 0 | 0 |
| 26 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 27 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 28 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 0 | 0 | 0 |
| 29 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 56 | 30 | 26 |
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
| 41 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 8 | 1 |
| 42 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 6 | 1 |
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
