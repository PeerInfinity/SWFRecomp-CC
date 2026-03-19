# Ruffle Test Results (Filtered)

**Date**: 2026-03-19 20:52 UTC

**Git SHA**: `f246282a73`

**Run Duration**: 202m 21s

**Filtered**: 45 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 574 |
| Passing | **310** (54.0%) |
| Failing | 264 |
| Total expected lines | 26493 |
| Matching lines | 26452 (99.8%) |
| Mismatched lines | 41 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Compile Fail | 257 | 97.3% |
| Output Mismatch | 7 | 2.7% |

## Passing Tests

**310 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 16.2s |  |
| 2 | `action_to_integer` | 28 | 16.0s |  |
| 3 | `add` | 28 | 16.2s |  |
| 4 | `add_property` | 15 | 16.3s | [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 5 | `add_swf4` | 28 | 15.7s |  |
| 6 | `add_swf5` | 28 | 15.9s |  |
| 7 | `array_call_method` | 9 | 16.1s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 8 | `array_concat` | 98 | 16.1s |  |
| 9 | `array_constructor` | 30 | 16.0s |  |
| 10 | `array_properties` | 36 | 16.5s |  |
| 11 | `array_prototyping` | 12 | 16.7s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 12 | `array_slice` | 34 | 16.6s |  |
| 13 | `array_splice` | 207 | 16.3s |  |
| 14 | `as1_constructor_v6` | 35 | 16.0s |  |
| 15 | `as1_constructor_v7` | 35 | 15.8s |  |
| 16 | `as_broadcaster` | 41 | 15.5s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 17 | `as_broadcaster_initialize` | 10 | 15.4s |  |
| 18 | `as_transformed_flag` | 20 | 15.3s |  |
| 19 | `asnative` | 34 | 15.3s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 20 | `attach_movie` | 59 | 15.6s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 21 | `attach_movie_stop` | 3 | 15.5s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 22 | `bad_placeobject_clipaction` | 2 | 17.1s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 15.5s |  |
| 24 | `bitand` | 1058 | 18.3s |  |
| 25 | `bitmap_data_colortransform` | 0 | 15.9s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 26 | `bitmap_data_fillrect` | 0 | 15.6s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 27 | `bitmap_data_max_size_swf10` | 12 | 15.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 28 | `bitmap_data_max_size_swf9` | 10 | 15.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 29 | `bitmapdata_applyfilter_colormatrix` | 0 | 15.6s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 30 | `bitor` | 1058 | 18.4s |  |
| 31 | `biturshift` | 14 | 15.8s |  |
| 32 | `biturshift_swf8` | 14 | 15.6s |  |
| 33 | `bitxor` | 1058 | 18.6s |  |
| 34 | `button_children` | 8 | 15.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 35 | `button_goto` | 4 | 15.6s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 36 | `button_key_events` | 14 | 15.8s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 37 | `button_key_events_special` | 45 | 16.4s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 38 | `button_keypress` | 3 | 15.6s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 39 | `button_keypress_vs_textinput` | 4 | 15.4s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 40 | `button_order` | 2 | 15.4s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 41 | `button_v5` | 18 | 15.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 42 | `button_v6` | 18 | 15.4s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 43 | `call` | 63 | 15.8s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 44 | `call_method_empty_name` | 1 | 15.8s |  |
| 45 | `capabilities_resolution` | 8 | 16.2s |  |
| 46 | `catch_references_registers` | 2 | 16.7s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 47 | `click_block` | 5 | 16.8s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 48 | `clip_events` | 19 | 16.5s | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 49 | `clone_sprite_types` | 24 | 17.7s | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 50 | `closure_scope` | 7 | 17.3s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 51 | `color` | 57 | 16.9s | [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 52 | `conflicting_instance_names` | 23 | 16.4s |  |
| 53 | `constructor_function` | 2 | 16.7s |  |
| 54 | `create_empty_movie_clip` | 3 | 16.2s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 55 | `cross_movie_root` | 10 | 16.1s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 56 | `custom_clip_methods` | 4 | 16.1s | [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 57 | `define_function2` | 8 | 17.2s |  |
| 58 | `define_function2_preload` | 13 | 16.8s |  |
| 59 | `define_function2_preload_order` | 4 | 16.4s |  |
| 60 | `define_function_case_sensitive` | 2 | 16.5s |  |
| 61 | `define_local` | 27 | 16.4s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 62 | `define_local_with_paths` | 54 | 16.5s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 63 | `delete` | 3 | 16.2s |  |
| 64 | `display_object_properties` | 2 | 16.3s |  |
| 65 | `divide_swf4` | 107 | 16.4s |  |
| 66 | `do_init_action` | 3 | 16.3s |  |
| 67 | `do_init_action_child` | 12 | 16.4s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 68 | `drag_drop` | 10 | 16.3s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 69 | `duplicate_movie_clip` | 20 | 16.2s | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 70 | `duplicate_movie_clip_drawing` | 2 | 16.2s | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 71 | `edittext_align_trailing_spaces_swf7` | 576 | 16.4s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 72 | `edittext_align_trailing_spaces_swf8` | 576 | 16.4s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 73 | `edittext_antialiastype` | 296 | 16.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 74 | `edittext_autosize` | 71 | 15.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 75 | `edittext_default_format_font_style` | 335 | 15.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 76 | `edittext_focus_selection` | 2 | 15.4s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 77 | `edittext_hscroll` | 27 | 15.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 78 | `edittext_html_align_swf7` | 52 | 15.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 79 | `edittext_html_align_swf8` | 52 | 15.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 80 | `edittext_html_color` | 114 | 15.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 81 | `edittext_html_roundtrip` | 17 | 15.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 82 | `edittext_newline_stripping` | 64 | 20.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 83 | `edittext_programmatic_focus` | 12 | 15.4s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 84 | `edittext_scroll` | 54 | 15.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 85 | `edittext_tag_indent` | 31 | 15.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 86 | `edittext_width_height` | 103 | 15.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 87 | `empty_movieclip_can_attach_movies` | 11 | 15.6s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 88 | `equals` | 32 | 15.4s |  |
| 89 | `equals2_swf5` | 926 | 17.1s |  |
| 90 | `equals2_swf6` | 926 | 17.1s |  |
| 91 | `equals2_swf7` | 926 | 17.1s |  |
| 92 | `equals_swf4` | 665 | 16.1s |  |
| 93 | `equals_swf4_alt` | 32 | 15.4s |  |
| 94 | `equals_swf5` | 32 | 15.4s |  |
| 95 | `error` | 58 | 15.5s |  |
| 96 | `escape` | 14 | 15.3s |  |
| 97 | `execution_order1` | 5 | 15.4s |  |
| 98 | `execution_order2` | 7 | 15.3s |  |
| 99 | `execution_order3` | 4 | 15.4s |  |
| 100 | `execution_order4` | 12 | 15.6s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 101 | `export_assets` | 3 | 15.3s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 102 | `external_interface` | 84 | 15.6s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 103 | `external_interface_escapexml` | 26 | 15.4s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 104 | `external_interface_jsquotestring` | 21 | 16.2s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 105 | `external_interface_toxml_array` | 25 | 16.0s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 106 | `external_interface_toxml_basic` | 179 | 16.2s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 107 | `external_interface_unescapexml` | 40 | 16.0s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 108 | `focus_mouse` | 45 | 16.1s | [9](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 109 | `focus_mouse_rollout` | 4 | 15.9s | [9](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 110 | `focus_remove` | 33 | 15.9s |  |
| 111 | `focus_visibility_change` | 45 | 15.9s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 112 | `focusrect_focuslost` | 4 | 16.0s | [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 113 | `focusrect_mouse_swf8` | 0 | 15.7s |  |
| 114 | `focusrect_mouse_swf9` | 0 | 15.3s |  |
| 115 | `frame_size_translated_negative` | 21 | 15.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 116 | `frame_size_translated_positive` | 21 | 15.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 117 | `function_as_function` | 35 | 15.2s | [22](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 118 | `function_base_clip` | 8 | 15.2s |  |
| 119 | `function_base_clip_removed` | 25 | 15.3s |  |
| 120 | `funky_function_calls` | 56 | 15.2s | [22](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 121 | `get_bytes_total` | 4 | 15.2s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 122 | `get_variable_in_scope` | 29 | 15.3s |  |
| 123 | `getproperty` | 28 | 17.9s |  |
| 124 | `getproperty_swf4` | 28 | 16.0s |  |
| 125 | `getproperty_swf5` | 28 | 16.0s |  |
| 126 | `gettextextent` | 56 | 15.8s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 127 | `global_array` | 3 | 15.9s |  |
| 128 | `global_is_bare` | 7 | 15.8s |  |
| 129 | `globals_swf6` | 304 | 16.0s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 130 | `globals_swf7` | 304 | 16.0s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 131 | `globals_swf8` | 304 | 16.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 132 | `goto_advance1` | 6 | 16.1s |  |
| 133 | `goto_advance2` | 2 | 15.9s |  |
| 134 | `goto_both_ways1` | 3 | 15.9s |  |
| 135 | `goto_both_ways2` | 3 | 16.0s |  |
| 136 | `goto_execution_order` | 2 | 16.2s |  |
| 137 | `init_array_invalid` | 4 | 16.7s |  |
| 138 | `init_object_invalid` | 4 | 15.2s |  |
| 139 | `input_dead_keys_windows` | 15 | 15.4s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 140 | `is_finite` | 49 | 15.0s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 141 | `is_finite_swf6` | 49 | 15.1s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 142 | `is_prototype_of` | 89 | 15.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 143 | `issue_1086` | 1 | 15.2s |  |
| 144 | `issue_1104` | 2 | 15.1s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 145 | `issue_1671` | 0 | 15.1s |  |
| 146 | `issue_1906` | 4 | 15.2s | [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 147 | `issue_2030` | 4 | 15.2s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 148 | `issue_3446` | 1 | 15.1s |  |
| 149 | `issue_3522` | 2 | 15.1s |  |
| 150 | `issue_4377` | 2 | 15.1s |  |
| 151 | `issue_710` | 4 | 15.9s |  |
| 152 | `issue_768` | 3 | 15.6s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) |
| 153 | `issue_9885` | 2 | 15.4s |  |
| 154 | `key_isToggled` | 9 | 15.5s |  |
| 155 | `lessthan` | 41 | 15.5s |  |
| 156 | `lessthan2_swf5` | 1226 | 17.3s |  |
| 157 | `lessthan2_swf6` | 1226 | 17.2s |  |
| 158 | `lessthan2_swf7` | 1226 | 17.2s |  |
| 159 | `lessthan_swf4` | 902 | 16.4s |  |
| 160 | `lessthan_swf4_alt` | 41 | 15.3s |  |
| 161 | `lessthan_swf5` | 41 | 15.3s |  |
| 162 | `loadmovie` | 2 | 15.5s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 163 | `loadmovie_method` | 2 | 15.5s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 164 | `loadmovie_replace_root` | 5 | 15.4s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 165 | `loadmovie_var_persistence` | 8 | 15.6s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 166 | `loadmovienum` | 3 | 15.4s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 167 | `local_to_global` | 49 | 15.6s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 168 | `lock_root` | 1 | 15.6s |  |
| 169 | `logical_ops_swf4` | 90 | 15.4s |  |
| 170 | `logical_ops_swf8` | 108 | 15.6s |  |
| 171 | `looping` | 6 | 15.5s |  |
| 172 | `mask_reapply` | 0 | 15.8s |  |
| 173 | `mask_with_drawing` | 0 | 15.7s |  |
| 174 | `math_min_max` | 101 | 15.7s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 175 | `matrix` | 171 | 16.3s | [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 176 | `mcl_as_broadcaster` | 12 | 16.0s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 177 | `mcl_loadclip` | 149 | 16.4s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 178 | `mcl_unloadclip` | 5 | 16.1s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 179 | `mouse_events` | 8 | 15.6s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 180 | `mouse_listeners` | 67 | 15.7s |  |
| 181 | `mouse_wheel_enabled` | 2 | 15.7s |  |
| 182 | `movieclip_begin_gradient_fill` | 0 | 16.6s |  |
| 183 | `movieclip_create_text_field` | 90 | 16.2s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 184 | `movieclip_depth_methods` | 98 | 15.9s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 185 | `movieclip_get_instance_at_depth` | 28 | 15.7s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 186 | `movieclip_gettextsnapshot` | 112 | 15.9s | [24](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 187 | `movieclip_hittest` | 92 | 15.8s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 188 | `movieclip_in_removed_button` | 4 | 15.6s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 189 | `movieclip_line_gradient_style` | 0 | 16.2s |  |
| 190 | `movieclip_name_from_timeline` | 13 | 16.5s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 191 | `movieclip_prototype_extension` | 5 | 16.1s |  |
| 192 | `mutable_this` | 18 | 15.2s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 193 | `named_shapes` | 14 | 15.5s |  |
| 194 | `nested_textfields_in_buttons` | 0 | 15.3s |  |
| 195 | `new_method_wrap` | 4 | 16.9s |  |
| 196 | `new_object_wrap` | 4 | 15.1s |  |
| 197 | `o` | 3 | 15.1s |  |
| 198 | `object_constructor` | 33 | 15.2s |  |
| 199 | `object_function` | 32 | 15.1s |  |
| 200 | `object_prototypes` | 74 | 15.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 201 | `object_string_coerce_swf5` | 62 | 15.3s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 202 | `object_string_coerce_swf6` | 68 | 15.2s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 203 | `parse_float` | 74 | 15.3s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 204 | `path_string` | 322 | 15.4s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 205 | `placeobject_occupied_depth` | 6 | 15.2s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 206 | `point` | 175 | 15.5s | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 207 | `primitive_instanceof` | 37 | 15.1s |  |
| 208 | `property_invalid_base_clip` | 36 | 15.6s |  |
| 209 | `prototype_properties` | 17 | 15.4s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 210 | `recursive_prototypes` | 0 | 15.4s |  |
| 211 | `register_globals_across_frames` | 15 | 15.5s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 212 | `register_underflow` | 26 | 15.6s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 213 | `remove_movie_clip` | 29 | 15.7s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 214 | `removed_clip_halts_script` | 15 | 15.9s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 215 | `removed_target_clip_scope` | 35 | 15.8s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 216 | `rewind_depth` | 30 | 16.3s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 217 | `root_global_parent` | 6 | 16.1s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 218 | `root_onload` | 1 | 16.0s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 219 | `sandbox_type_local_file` | 1 | 15.8s |  |
| 220 | `sandbox_type_local_network` | 1 | 15.9s |  |
| 221 | `selection` | 454 | 16.2s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 222 | `selection_handlers` | 27 | 16.1s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 223 | `set_variable_scope` | 58 | 15.9s |  |
| 224 | `single_frame` | 1 | 15.9s |  |
| 225 | `slash_syntax` | 14 | 15.9s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 226 | `stage_display_state` | 16 | 15.8s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 227 | `stage_object_children` | 83 | 15.8s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 228 | `stage_object_properties` | 241 | 16.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 229 | `stage_object_properties_get_var` | 5 | 15.8s |  |
| 230 | `stage_object_properties_swf6` | 231 | 16.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 231 | `stage_scale_mode` | 39 | 16.0s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 232 | `strictequals_swf6` | 902 | 17.7s |  |
| 233 | `string_methods` | 285 | 16.3s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 234 | `string_methods_swfv5` | 275 | 16.4s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 235 | `string_ops_swf6` | 95 | 15.7s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 236 | `string_paths_basic` | 4 | 15.3s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 237 | `string_paths_eval` | 4 | 15.3s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 238 | `string_paths_eval2` | 7 | 16.8s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 239 | `string_paths_hidden` | 54 | 16.0s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 240 | `string_paths_keyevents` | 0 | 15.9s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 241 | `string_paths_timer` | 0 | 16.1s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 242 | `string_paths_unload` | 1 | 16.1s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 243 | `string_paths_variable_alias` | 4 | 16.2s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 244 | `string_paths_variable_scopes` | 5 | 16.6s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 245 | `stylesheet_transform` | 750 | 17.7s |  |
| 246 | `swf4_actions_bool` | 96 | 16.2s |  |
| 247 | `swf4_bool` | 4 | 16.4s |  |
| 248 | `swf4_function_calls` | 7 | 15.9s |  |
| 249 | `swf5_encoding` | 3 | 15.9s |  |
| 250 | `swf5_no_closure` | 19 | 15.6s | [9](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 251 | `target_clip_removed` | 5 | 16.0s | [50](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 252 | `target_clip_swf5` | 2 | 15.9s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 253 | `target_clip_swf6` | 2 | 16.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 254 | `target_path` | 14 | 15.9s |  |
| 255 | `tell_target` | 37 | 16.0s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 256 | `tell_target_invalid` | 6 | 15.9s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 257 | `tell_target_invalid_swf6` | 5 | 16.0s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 258 | `text_blocks_clicks` | 4 | 16.2s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 259 | `text_format_display` | 21 | 16.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 260 | `text_format_font_max_length` | 2 | 16.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 261 | `text_format_get_text_extent_undefined_width` | 10 | 15.9s |  |
| 262 | `text_format_rounding_swf7` | 840 | 16.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 263 | `text_format_rounding_swf8` | 840 | 16.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 264 | `textfield_background_color` | 11 | 16.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 265 | `textfield_border_color` | 11 | 16.4s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 266 | `textfield_cache_as_bitmap` | 1 | 16.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 267 | `textfield_maxchars` | 3 | 15.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 268 | `textfield_properties` | 44 | 15.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 269 | `textfield_text` | 7 | 15.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 270 | `textfield_variable` | 81 | 15.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 271 | `textsnapshot_available_text` | 20 | 15.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 272 | `textsnapshot_text_order` | 1 | 14.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 273 | `this_scoping` | 52 | 14.9s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 274 | `this_swf5` | 41 | 14.7s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 275 | `this_swf6` | 41 | 14.9s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 276 | `this_swf7` | 41 | 14.9s | [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) |
| 277 | `timeline_function_def` | 7 | 14.9s |  |
| 278 | `trace` | 8 | 15.4s |  |
| 279 | `transform` | 70 | 15.5s | [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 280 | `typeof` | 22 | 15.3s |  |
| 281 | `typeof_globals` | 7 | 15.3s |  |
| 282 | `uncaught_exception` | 1 | 15.3s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 283 | `uncaught_exception_bubbled` | 1 | 15.3s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 284 | `undefined_to_string_swf6` | 4 | 15.2s |  |
| 285 | `unescape` | 43 | 15.3s |  |
| 286 | `unload` | 52 | 15.7s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 287 | `unload_clip_event` | 4 | 15.4s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 288 | `unload_nested_child` | 5 | 15.3s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 289 | `unloadmovie` | 4 | 15.4s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 290 | `unloadmovie_method` | 3 | 15.4s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 291 | `unloadmovienum` | 13 | 15.4s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 292 | `use_hand_cursor` | 8 | 15.3s |  |
| 293 | `watch_textfield` | 12 | 15.8s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 294 | `with` | 49 | 15.6s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 295 | `with_return` | 2 | 15.8s |  |
| 296 | `with_variable_scopes` | 43 | 15.8s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 297 | `xml_append_child` | 28 | 15.7s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 298 | `xml_append_child_with_parent` | 20 | 15.8s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 299 | `xml_cdata` | 11 | 15.4s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 300 | `xml_child_nodes_edge_cases` | 4 | 15.4s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 301 | `xml_clone_expandos` | 19 | 15.4s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 302 | `xml_first_last_child` | 8 | 15.4s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 303 | `xml_has_child_nodes` | 3 | 15.6s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 304 | `xml_ignore_white` | 34 | 16.2s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 305 | `xml_insert_before` | 20 | 15.4s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 306 | `xml_parent_and_child` | 5 | 16.3s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 307 | `xml_remove_node` | 22 | 15.8s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 308 | `xml_siblings` | 10 | 15.2s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 309 | `xml_to_string` | 13 | 14.9s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 310 | `xml_to_string_comment` | 1 | 15.0s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `globals_swf5` | 99.0% | 301 | 304 | 3 | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**7 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `globals_swf5` | 99.0% | 301/304 | 304 | 304 | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 3 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 4 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [22](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 5 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 6 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 7 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) | 1 | 0 | 1 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 2 | 2 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 1 | 1 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 1 | 1 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) | 15 | 6 | 9 |
| 6 | [BUTTON_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) | 14 | 10 | 4 |
| 7 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 8 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) | 8 | 4 | 4 |
| 9 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 3 | 1 |
| 10 | [COLOR_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 4 | 1 |
| 11 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 1 | 0 | 1 |
| 12 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 13 | [DATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) | 0 | 0 | 0 |
| 14 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 0 | 1 |
| 15 | [DRAG_DROP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 1 | 3 |
| 16 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 17 | [ENUMERATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 7 | 7 |
| 18 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 6 | 1 |
| 19 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 1 | 3 |
| 20 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 3 | 4 |
| 21 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 0 | 4 |
| 22 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 23 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 6 | 2 | 4 |
| 24 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 25 | [GLOBALS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) | 30 | 7 | 23 |
| 26 | [HIT_TESTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 3 | 14 |
| 27 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 0 | 0 | 0 |
| 28 | [infinite_recursion_function.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) | 3 | 0 | 3 |
| 29 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 30 | [issue_768.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 31 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 1 | 1 |
| 32 | [LOADMOVIE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) | 43 | 12 | 31 |
| 33 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 3 | 1 | 2 |
| 34 | [LOADVARIABLES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) | 3 | 0 | 3 |
| 35 | [LOCKROOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 0 | 1 |
| 36 | [MATH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) | 4 | 1 | 3 |
| 37 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 0 | 1 |
| 38 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 2 | 3 |
| 39 | [MOVIECLIP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) | 55 | 28 | 27 |
| 40 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 14 | 3 | 11 |
| 41 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 15 | 3 | 12 |
| 42 | [object_string_coerce.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 43 | [OBJECT_WATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) | 3 | 1 | 2 |
| 44 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 0 | 8 |
| 45 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 1 | 2 |
| 46 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 0 | 1 |
| 47 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 4 | 8 |
| 48 | [REGISTERCLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) | 15 | 7 | 8 |
| 49 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 2 | 1 | 1 |
| 50 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 51 | [SELECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) | 4 | 4 | 0 |
| 52 | [SOUND_CLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 0 | 2 |
| 53 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 7 | 2 |
| 54 | [STAGE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) | 7 | 5 | 2 |
| 55 | [string_coercion.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) | 1 | 0 | 1 |
| 56 | [STRING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) | 12 | 10 | 2 |
| 57 | [STYLESHEET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 0 | 1 |
| 58 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 0 | 5 |
| 59 | [TAB_ORDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 0 | 16 |
| 60 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 0 | 1 |
| 61 | [TELLTARGET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) | 17 | 16 | 1 |
| 62 | [TEXTFIELD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) | 69 | 30 | 39 |
| 63 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 2 | 2 |
| 64 | [THIS_BINDING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 65 | [this_swf7.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 66 | [TIMER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) | 2 | 0 | 2 |
| 67 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 3 | 2 |
| 68 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 0 | 2 |
| 69 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 15 | 8 | 7 |
| 70 | [UNLOAD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) | 12 | 11 | 1 |
| 71 | [WITH_SCOPE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 72 | [XML_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) | 27 | 14 | 13 |
| | *(tests not in any document)* | 151 | 120 | 31 |
