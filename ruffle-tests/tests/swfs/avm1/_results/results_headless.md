# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-18 02:22 UTC

**Git SHA**: `fe5f3072eb`

**Run Duration**: 118m 50s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 621 |
| Passing | **468** (75.4%) |
| Failing | 153 |
| Total expected lines | 73195 |
| Matching lines | 58439 (79.8%) |
| Mismatched lines | 14756 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 112 | 73.2% |
| Compile Fail | 35 | 22.9% |
| Runtime Segfault | 5 | 3.3% |
| Timeout | 1 | 0.7% |

## Passing Tests

**468 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 20.3s |  |
| 2 | `action_to_integer` | 28 | 21.3s |  |
| 3 | `add` | 28 | 21.8s |  |
| 4 | `add2` | 354 | 21.9s | [1](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 22.1s | [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 21.9s |  |
| 7 | `add_swf5` | 28 | 20.8s |  |
| 8 | `arguments` | 127 | 19.3s | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 22.1s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 19.7s |  |
| 11 | `array_constructor` | 30 | 21.1s |  |
| 12 | `array_enumerate` | 4 | 20.4s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 21.8s |  |
| 14 | `array_properties` | 36 | 22.1s |  |
| 15 | `array_prototyping` | 12 | 20.9s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 21.7s |  |
| 17 | `array_sort` | 161 | 24.2s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 19.1s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 19.7s |  |
| 20 | `array_trivial` | 209 | 19.8s |  |
| 21 | `as1_constructor_v6` | 35 | 19.1s |  |
| 22 | `as1_constructor_v7` | 35 | 19.0s |  |
| 23 | `as2_oop` | 13 | 19.6s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 19.1s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 20.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 22.5s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 21.0s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 21.1s |  |
| 29 | `as_broadcaster_undef` | 89 | 20.7s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 21.0s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 19.3s | [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 19.6s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 19.5s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 21.8s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 25.7s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 22.8s |  |
| 37 | `as_transformed_flag` | 20 | 20.7s |  |
| 38 | `asnative` | 34 | 19.2s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 19.8s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 19.9s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 20.7s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 42 | `bad_placeobject_clipaction` | 2 | 21.4s |  |
| 43 | `bad_swf_tag_past_eof` | 0 | 22.0s |  |
| 44 | `bitand` | 1058 | 26.4s |  |
| 45 | `bitmap_data` | 1126 | 22.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 46 | `bitmap_data_colortransform` | 0 | 19.9s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 47 | `bitmap_data_compare` | 40 | 19.7s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 48 | `bitmap_data_copypixels` | 17 | 20.8s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 49 | `bitmap_data_draw_cliprect` | 13 | 20.6s |  |
| 50 | `bitmap_data_fillrect` | 0 | 22.9s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 51 | `bitmap_data_hittest` | 132 | 23.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 52 | `bitmap_data_max_size_swf10` | 12 | 23.0s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 53 | `bitmap_data_max_size_swf9` | 10 | 19.6s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 54 | `bitmap_data_noise` | 631 | 18.8s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 55 | `bitmap_data_perlinnoise` | 0 | 20.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 56 | `bitmap_data_pixeldissolve_image` | 0 | 19.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 57 | `bitmap_data_threshold` | 176 | 19.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 58 | `bitmapdata_applyfilter_colormatrix` | 0 | 19.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 59 | `bitmapdata_channels` | 19 | 21.8s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 60 | `bitor` | 1058 | 23.3s |  |
| 61 | `biturshift` | 14 | 19.1s |  |
| 62 | `biturshift_swf8` | 14 | 19.5s |  |
| 63 | `bitxor` | 1058 | 23.0s |  |
| 64 | `boxed_primitives` | 24 | 19.8s | [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 65 | `button_children` | 8 | 19.1s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 66 | `button_goto` | 4 | 19.5s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 67 | `button_keypress` | 3 | 19.0s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `button_order` | 2 | 19.2s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 69 | `button_properties_special_cases` | 22 | 21.1s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 70 | `button_v5` | 18 | 20.1s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 71 | `button_v6` | 18 | 18.5s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 72 | `call` | 63 | 19.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 73 | `call_method_empty_name` | 1 | 22.6s |  |
| 74 | `capabilities_resolution` | 8 | 20.3s |  |
| 75 | `catch_references_registers` | 2 | 19.8s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 76 | `clip_constructors` | 8 | 19.6s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 77 | `clip_event_propagation_order` | 17 | 20.0s | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 78 | `clip_events` | 19 | 21.8s | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 79 | `clone_sprite_edittext` | 94 | 21.5s | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 80 | `clone_sprite_edittext_dynamic` | 86 | 22.1s | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 81 | `clone_sprite_types` | 24 | 21.2s | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 82 | `closure_scope` | 7 | 21.0s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 83 | `coerce_to_object_monkeypatch` | 129 | 24.0s | [68](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 84 | `coerce_to_primitive_resolve` | 17 | 20.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 85 | `color` | 57 | 19.7s | [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 86 | `color_transform` | 48 | 19.8s | [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 87 | `conflicting_instance_names` | 23 | 20.8s |  |
| 88 | `constructor_function` | 2 | 18.8s |  |
| 89 | `context_menu` | 39 | 20.8s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 90 | `context_menu_item` | 41 | 23.2s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 91 | `create_empty_movie_clip` | 3 | 19.1s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 92 | `custom_clip_methods` | 4 | 20.3s | [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 93 | `default_names` | 52 | 24.1s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 94 | `define_function2` | 8 | 23.2s |  |
| 95 | `define_function2_preload` | 13 | 23.1s |  |
| 96 | `define_function2_preload_order` | 4 | 19.0s |  |
| 97 | `define_function_case_sensitive` | 2 | 19.1s |  |
| 98 | `define_local` | 27 | 20.8s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 99 | `define_local_with_paths` | 54 | 20.0s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 100 | `delete` | 3 | 20.8s |  |
| 101 | `display_object_properties` | 2 | 19.2s |  |
| 102 | `divide_swf4` | 107 | 20.7s |  |
| 103 | `do_init_action` | 3 | 22.1s |  |
| 104 | `do_init_action_child` | 12 | 19.7s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 105 | `drag_drop` | 10 | 21.4s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 106 | `drag_over_from_outside` | 1 | 19.4s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 107 | `drag_over_without_startdrag` | 1 | 19.7s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 108 | `duplicate_movie_clip` | 20 | 19.9s | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 109 | `duplicate_movie_clip_drawing` | 2 | 19.8s | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 110 | `edittext_align_trailing_spaces_swf7` | 576 | 19.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 111 | `edittext_align_trailing_spaces_swf8` | 576 | 20.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 112 | `edittext_autosize_setter` | 20 | 19.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 113 | `edittext_hscroll` | 27 | 18.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 114 | `edittext_html_color` | 114 | 18.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 115 | `edittext_html_condensewhite_swf7` | 311 | 18.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 116 | `edittext_html_condensewhite_swf8` | 311 | 18.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 117 | `edittext_html_roundtrip` | 17 | 18.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 118 | `edittext_place_caret` | 2 | 18.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 119 | `edittext_stylesheet` | 325 | 19.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 120 | `edittext_tab_focus` | 13 | 17.9s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 121 | `edittext_text_height_leading` | 20 | 18.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 122 | `empty_movieclip_can_attach_movies` | 11 | 17.9s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 123 | `enumerate` | 64 | 18.0s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 124 | `equals` | 32 | 20.5s |  |
| 125 | `equals2_swf5` | 926 | 20.9s |  |
| 126 | `equals2_swf6` | 926 | 20.2s |  |
| 127 | `equals2_swf7` | 926 | 20.1s |  |
| 128 | `equals_swf4` | 665 | 19.0s |  |
| 129 | `equals_swf4_alt` | 32 | 17.9s |  |
| 130 | `equals_swf5` | 32 | 18.0s |  |
| 131 | `error` | 58 | 18.3s |  |
| 132 | `escape` | 14 | 18.1s |  |
| 133 | `execution_order1` | 5 | 18.1s |  |
| 134 | `execution_order2` | 7 | 18.3s |  |
| 135 | `execution_order3` | 4 | 18.0s |  |
| 136 | `execution_order4` | 12 | 18.0s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 137 | `export_assets` | 3 | 18.1s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 138 | `extends_native_type` | 11 | 18.0s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 139 | `external_interface` | 84 | 18.1s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 140 | `external_interface_escapexml` | 26 | 18.1s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 141 | `external_interface_jsquotestring` | 21 | 18.1s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 142 | `external_interface_toas_basic` | 354 | 19.8s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 143 | `external_interface_toxml_array` | 25 | 18.4s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 144 | `external_interface_toxml_basic` | 179 | 18.5s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 145 | `external_interface_unescapexml` | 40 | 19.2s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 146 | `focus_mouse` | 45 | 16.1s | [9](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 147 | `focus_mouse_focusable` | 8 | 16.5s | [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 148 | `focus_mouse_rollout` | 4 | 16.0s | [9](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 149 | `focus_remove` | 33 | 16.3s |  |
| 150 | `focus_visibility_change` | 45 | 16.2s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 151 | `focusrect_focuslost` | 4 | 16.0s | [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 152 | `form_loader_encoding_1` | 1 | 15.8s |  |
| 153 | `frame_size_translated_negative` | 21 | 16.0s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 154 | `frame_size_translated_positive` | 21 | 16.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 155 | `function_as_function` | 35 | 16.0s | [22](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 156 | `function_base_clip` | 8 | 16.1s |  |
| 157 | `function_base_clip_readded` | 11 | 16.0s |  |
| 158 | `function_base_clip_removed` | 25 | 16.0s |  |
| 159 | `function_suppress_and_preload` | 28 | 16.1s |  |
| 160 | `funky_function_calls` | 56 | 16.0s | [22](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 161 | `get_bytes_total` | 4 | 15.9s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 162 | `get_variable_in_scope` | 29 | 15.9s |  |
| 163 | `getproperty` | 28 | 16.1s |  |
| 164 | `getproperty_swf4` | 28 | 15.9s |  |
| 165 | `getproperty_swf5` | 28 | 15.9s |  |
| 166 | `global_array` | 3 | 15.8s |  |
| 167 | `global_is_bare` | 7 | 15.9s |  |
| 168 | `global_swf5_6_7_8_9` | 1145 | 16.5s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 169 | `global_swf6_7_8` | 15 | 16.2s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 170 | `globals_swf5` | 304 | 15.9s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 171 | `globals_swf6` | 304 | 16.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 172 | `globals_swf7` | 304 | 16.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 173 | `globals_swf8` | 304 | 16.2s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 174 | `goto_advance1` | 6 | 15.8s |  |
| 175 | `goto_advance2` | 2 | 16.4s |  |
| 176 | `goto_both_ways1` | 3 | 16.0s |  |
| 177 | `goto_both_ways2` | 3 | 15.9s |  |
| 178 | `goto_execution_order` | 2 | 15.8s |  |
| 179 | `goto_execution_order2` | 2 | 15.9s |  |
| 180 | `goto_frame` | 12 | 15.9s | [21](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 181 | `goto_frame2` | 44 | 16.3s | [21](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 182 | `goto_frame_number` | 3 | 15.9s |  |
| 183 | `goto_label` | 17 | 16.2s | [21](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 184 | `goto_methods` | 40 | 15.9s | [21](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 185 | `goto_rewind1` | 1 | 15.9s |  |
| 186 | `goto_rewind2` | 3 | 15.9s |  |
| 187 | `goto_rewind3` | 2 | 15.8s |  |
| 188 | `greater_swf6` | 1175 | 17.6s |  |
| 189 | `greater_swf7` | 1175 | 19.0s |  |
| 190 | `greaterthan_swf5` | 1 | 15.9s |  |
| 191 | `greaterthan_swf8` | 1 | 15.8s |  |
| 192 | `has_own_property` | 32 | 15.7s |  |
| 193 | `hittest_lockroot` | 15 | 16.3s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 194 | `hittest_morph` | 70 | 15.7s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 195 | `hittest_morph_input` | 1 | 16.0s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 196 | `hittest_winding_rule` | 12 | 15.8s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 197 | `infinite_recursion_function` | 4 | 16.0s | [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 198 | `infinite_recursion_function_in_setter` | 131 | 15.7s | [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 199 | `infinite_recursion_virtual_property` | 67 | 15.9s | [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 200 | `init_array_invalid` | 4 | 16.2s |  |
| 201 | `init_object_invalid` | 4 | 15.9s |  |
| 202 | `init_object_order` | 15 | 15.9s | [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 203 | `instanceof_coercions` | 88 | 15.9s | [68](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 204 | `interface_implements_op` | 47 | 16.5s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 205 | `is_finite` | 49 | 15.5s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 206 | `is_finite_swf6` | 49 | 16.5s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 207 | `is_prototype_of` | 89 | 15.6s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 208 | `issue_1086` | 1 | 16.3s |  |
| 209 | `issue_1104` | 2 | 16.0s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 210 | `issue_1671` | 0 | 18.3s |  |
| 211 | `issue_1906` | 4 | 16.9s | [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 212 | `issue_2030` | 4 | 16.3s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 213 | `issue_2166` | 9 | 15.9s |  |
| 214 | `issue_3169` | 2 | 16.3s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 215 | `issue_3446` | 1 | 16.0s |  |
| 216 | `issue_3522` | 2 | 16.1s |  |
| 217 | `issue_4377` | 2 | 15.8s |  |
| 218 | `issue_710` | 4 | 16.4s |  |
| 219 | `issue_768` | 3 | 15.5s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) |
| 220 | `issue_9327` | 2 | 16.1s |  |
| 221 | `issue_9885` | 2 | 15.6s |  |
| 222 | `key_isToggled` | 9 | 16.1s |  |
| 223 | `lessthan` | 41 | 15.8s |  |
| 224 | `lessthan2_swf5` | 1226 | 18.1s |  |
| 225 | `lessthan2_swf6` | 1226 | 18.0s |  |
| 226 | `lessthan2_swf7` | 1226 | 17.8s |  |
| 227 | `lessthan_swf4` | 902 | 16.9s |  |
| 228 | `lessthan_swf4_alt` | 41 | 15.9s |  |
| 229 | `lessthan_swf5` | 41 | 15.9s |  |
| 230 | `loadmovie_fail` | 2 | 15.8s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 231 | `loadmovie_replace_root` | 5 | 15.8s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 232 | `loadmovie_var_persistence` | 8 | 15.9s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 233 | `loadvariables` | 2 | 15.8s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 234 | `loadvariables2` | 8 | 16.2s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 235 | `loadvariablesnum` | 2 | 15.8s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 236 | `local_to_global` | 49 | 15.8s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 237 | `localconnection_properties` | 8 | 15.7s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 238 | `logical_ops_swf4` | 90 | 15.9s |  |
| 239 | `logical_ops_swf8` | 108 | 16.1s |  |
| 240 | `looping` | 6 | 15.8s |  |
| 241 | `mask_reapply` | 0 | 16.0s |  |
| 242 | `mask_with_drawing` | 0 | 16.0s |  |
| 243 | `math_min_max` | 101 | 16.0s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 244 | `math_swf6` | 530 | 16.1s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 245 | `math_swf7` | 530 | 16.4s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 246 | `math_swf8` | 530 | 16.1s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 247 | `matrix` | 171 | 16.2s | [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 248 | `mcl_as_broadcaster` | 12 | 15.7s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 249 | `mcl_events_swf_version` | 232 | 16.6s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 250 | `mcl_getprogress` | 30 | 15.8s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 251 | `mcl_loadclip` | 149 | 16.1s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 252 | `mcl_loadclip_properties` | 6 | 16.0s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 253 | `mcl_loadclip_replace_root` | 1 | 16.1s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 254 | `mcl_mislabeled_target` | 6 | 15.7s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 255 | `mcl_target_gif87a` | 6 | 16.8s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 256 | `mcl_target_gif89a` | 6 | 16.5s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 257 | `mcl_target_jpg` | 6 | 16.6s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 258 | `mcl_target_png` | 6 | 15.8s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 259 | `mcl_unloadclip` | 5 | 16.2s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 260 | `mouse_events` | 8 | 16.4s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 261 | `mouse_events_visible_enabled` | 12 | 15.9s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 262 | `mouse_hover_events_while_dragging` | 1 | 16.3s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 263 | `mouse_listeners` | 67 | 15.7s |  |
| 264 | `mouse_pos` | 665 | 16.2s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 265 | `mouse_pos_with_scale_factor` | 260 | 15.6s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 266 | `mouse_wheel_enabled` | 2 | 15.9s |  |
| 267 | `movieclip_begin_gradient_fill` | 0 | 16.6s |  |
| 268 | `movieclip_blend_mode_property` | 35 | 16.1s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 269 | `movieclip_create_text_field` | 90 | 15.8s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 270 | `movieclip_default_state` | 69 | 16.3s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 271 | `movieclip_depth_methods` | 98 | 15.8s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 272 | `movieclip_focusenabled` | 99 | 15.9s | [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 273 | `movieclip_getbounds` | 191 | 16.1s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 274 | `movieclip_gettextsnapshot` | 112 | 15.8s | [24](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 275 | `movieclip_hittest` | 92 | 17.5s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 276 | `movieclip_in_removed_button` | 4 | 16.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 277 | `movieclip_init_object` | 5 | 17.0s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 278 | `movieclip_line_gradient_style` | 0 | 18.3s |  |
| 279 | `movieclip_name_from_timeline` | 13 | 18.5s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 280 | `movieclip_prototype_extension` | 5 | 17.9s |  |
| 281 | `movieclip_setmask` | 14 | 19.5s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 282 | `moviecliploader_flashvars` | 4 | 18.7s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 283 | `mutable_this` | 18 | 18.4s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 284 | `named_shapes` | 14 | 18.4s |  |
| 285 | `nan_scale` | 9 | 18.8s |  |
| 286 | `native_double_construct` | 12 | 18.8s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 287 | `native_objects_swf7` | 84 | 19.8s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 288 | `native_objects_swf8` | 84 | 20.1s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 289 | `native_subclasses` | 191 | 19.5s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 290 | `nested_textfields_in_buttons` | 0 | 19.6s |  |
| 291 | `new_method_wrap` | 4 | 20.7s |  |
| 292 | `new_object_enumerate` | 7 | 20.4s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 293 | `new_object_wrap` | 4 | 19.9s |  |
| 294 | `o` | 3 | 19.2s |  |
| 295 | `object_constructor` | 33 | 17.3s |  |
| 296 | `object_function` | 32 | 16.2s |  |
| 297 | `object_properties` | 31 | 17.6s | [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 298 | `object_prototypes` | 74 | 16.4s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 299 | `object_resolve` | 38 | 17.5s | [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 300 | `object_string_coerce_swf5` | 62 | 16.9s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 301 | `object_string_coerce_swf6` | 68 | 17.8s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 302 | `on_construct` | 25 | 17.1s | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 303 | `parse_float` | 74 | 17.6s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 304 | `parse_int` | 64 | 17.1s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 305 | `path_string` | 322 | 16.7s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 306 | `placeobject_occupied_depth` | 6 | 16.7s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 307 | `point` | 175 | 17.1s | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 308 | `primitive_instanceof` | 37 | 17.2s |  |
| 309 | `primitive_type_globals` | 557 | 17.5s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 310 | `printjob_props_swf5` | 45 | 17.3s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 311 | `printjob_props_swf6` | 45 | 17.7s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 312 | `printjob_props_swf7` | 45 | 17.2s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 313 | `property_invalid_base_clip` | 36 | 17.2s |  |
| 314 | `prototype_delete` | 12 | 17.0s |  |
| 315 | `prototype_enumerate` | 5 | 17.8s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 316 | `prototype_properties` | 17 | 16.9s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 317 | `rectangle` | 745 | 18.4s | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 318 | `recursive_prototypes` | 0 | 17.8s |  |
| 319 | `register_and_init_order` | 231 | 17.4s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 320 | `register_class` | 66 | 18.4s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 321 | `register_class_return_value` | 16 | 16.8s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 322 | `register_class_with_sound` | 11 | 17.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [52](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 323 | `register_globals_across_frames` | 15 | 17.0s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 324 | `register_underflow` | 26 | 17.0s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 325 | `remove_movie_clip` | 29 | 17.3s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 326 | `removed_clip_halts_script` | 15 | 17.9s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 327 | `removed_target_clip_scope` | 35 | 17.5s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 328 | `rewind_depth` | 30 | 17.3s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 329 | `root_global_parent` | 6 | 17.5s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 330 | `root_onload` | 1 | 17.3s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 331 | `sandbox_type_local_file` | 1 | 17.0s |  |
| 332 | `sandbox_type_local_network` | 1 | 16.9s |  |
| 333 | `selection_handlers` | 27 | 16.8s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 334 | `set_interval` | 27 | 16.9s | [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 335 | `set_variable_scope` | 58 | 16.7s |  |
| 336 | `single_frame` | 1 | 16.7s |  |
| 337 | `slash_syntax` | 14 | 17.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 338 | `sound` | 628 | 17.8s | [52](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 339 | `sound_props_swf5` | 68 | 17.2s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 340 | `sound_props_swf6` | 68 | 16.9s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 341 | `sound_start_load` | 0 | 17.1s |  |
| 342 | `stage_display_state` | 16 | 16.9s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 343 | `stage_object_children` | 83 | 17.0s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 344 | `stage_object_enumerate` | 4 | 16.9s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 345 | `stage_object_properties` | 241 | 17.7s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 346 | `stage_object_properties_get_var` | 5 | 17.5s |  |
| 347 | `stage_object_properties_swf6` | 231 | 17.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 348 | `stage_property_representation` | 586 | 17.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 349 | `stage_scale_mode` | 39 | 17.0s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 350 | `strictequals_swf6` | 902 | 18.8s |  |
| 351 | `strictly_equals` | 7 | 16.6s |  |
| 352 | `string_coercion` | 117 | 17.8s | [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) |
| 353 | `string_methods` | 285 | 17.0s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 354 | `string_methods_negative_args` | 240 | 17.8s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 355 | `string_methods_swfv5` | 275 | 17.4s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 356 | `string_ops_swf6` | 95 | 17.6s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 357 | `string_paths_basic` | 4 | 16.7s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 358 | `string_paths_eval` | 4 | 16.7s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 359 | `string_paths_eval2` | 7 | 16.8s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 360 | `string_paths_hidden` | 54 | 16.9s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 361 | `string_paths_keyevents` | 0 | 16.5s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 362 | `string_paths_other` | 36 | 17.1s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 363 | `string_paths_timer` | 0 | 16.6s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 364 | `string_paths_unload` | 1 | 16.9s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 365 | `string_paths_variable_alias` | 4 | 16.4s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 366 | `string_paths_variable_scopes` | 5 | 17.0s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 367 | `stylesheet` | 283 | 17.1s |  |
| 368 | `stylesheet_transform` | 750 | 17.2s |  |
| 369 | `super_edge_cases` | 39 | 17.0s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 370 | `swf4_actions_bool` | 96 | 17.1s |  |
| 371 | `swf4_actions_coercion_order` | 158 | 16.8s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 372 | `swf4_bool` | 4 | 16.8s |  |
| 373 | `swf4_function_calls` | 7 | 16.7s |  |
| 374 | `swf5_encoding` | 3 | 16.7s |  |
| 375 | `swf5_global_funcs` | 232 | 16.7s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 376 | `swf5_no_closure` | 19 | 16.6s | [9](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 377 | `swf6_case_insensitive` | 42 | 16.7s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 378 | `swf6_global_funcs` | 232 | 17.8s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 379 | `swf6_string_as_bool` | 15 | 17.3s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 380 | `swf7_case_sensitive` | 44 | 16.3s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 381 | `swf7_global_funcs` | 232 | 15.9s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 382 | `tab_ordering_automatic_order_grid` | 21 | 16.0s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 383 | `tab_ordering_automatic_order_same_position` | 12 | 16.0s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 384 | `tab_ordering_custom_duplicate_index` | 22 | 16.1s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 385 | `tab_ordering_custom_i32_vs_u32` | 12 | 16.1s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 386 | `tab_ordering_custom_m1` | 29 | 16.3s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 387 | `tab_ordering_events_mouse` | 65 | 16.3s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 388 | `tab_ordering_properties` | 293 | 16.0s | [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 389 | `target_clip_removed` | 5 | 16.0s | [50](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 390 | `target_clip_swf5` | 2 | 16.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 391 | `target_clip_swf6` | 2 | 15.9s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 392 | `target_path` | 14 | 16.4s |  |
| 393 | `tell_target` | 37 | 16.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 394 | `tell_target_invalid` | 6 | 15.9s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 395 | `tell_target_invalid_swf6` | 5 | 16.0s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 396 | `text_blocks_clicks` | 4 | 15.8s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 397 | `text_format` | 1146 | 16.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 398 | `text_format_display` | 21 | 15.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 399 | `text_format_font_max_length` | 2 | 15.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 400 | `text_format_get_text_extent_undefined_width` | 10 | 16.0s |  |
| 401 | `text_format_rounding_swf7` | 840 | 16.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 402 | `text_format_rounding_swf8` | 840 | 15.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 403 | `textfield_background_color` | 11 | 16.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 404 | `textfield_border_color` | 11 | 15.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 405 | `textfield_cache_as_bitmap` | 1 | 15.9s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 406 | `textfield_maxchars` | 3 | 15.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 407 | `textfield_props_swf5` | 175 | 15.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 408 | `textfield_props_swf6` | 210 | 16.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 409 | `textfield_props_swf7` | 210 | 16.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 410 | `textfield_props_swf8` | 210 | 16.4s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 411 | `textfield_variable` | 81 | 15.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 412 | `textsnapshot_props_swf5` | 56 | 15.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 413 | `textsnapshot_props_swf6` | 56 | 15.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 414 | `this_scoping` | 52 | 15.9s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 415 | `this_swf5` | 41 | 15.9s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 416 | `this_swf6` | 41 | 15.7s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 417 | `this_swf7` | 41 | 15.8s | [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) |
| 418 | `timeline_function_def` | 7 | 16.0s |  |
| 419 | `timer_run_actions` | 18 | 16.5s | [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 420 | `trace` | 8 | 15.8s |  |
| 421 | `transform` | 70 | 16.1s | [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 422 | `try_catch_finally` | 118 | 16.6s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 423 | `try_finally_simple` | 16 | 16.0s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 424 | `typeof` | 22 | 15.5s |  |
| 425 | `typeof_globals` | 7 | 15.8s |  |
| 426 | `uncaught_exception` | 1 | 15.9s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 427 | `uncaught_exception_bubbled` | 1 | 16.2s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 428 | `undefined_to_string_swf6` | 4 | 15.8s |  |
| 429 | `unescape` | 43 | 16.0s |  |
| 430 | `unload` | 52 | 15.8s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 431 | `unload_clip_event` | 4 | 15.9s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 432 | `unload_nested_child` | 5 | 15.8s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 433 | `use_hand_cursor` | 8 | 16.9s |  |
| 434 | `variable_args` | 5 | 17.1s |  |
| 435 | `waitforframe` | 7 | 16.6s |  |
| 436 | `waitforframe2` | 16 | 16.3s |  |
| 437 | `watch` | 117 | 16.8s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 438 | `watch_textfield` | 12 | 16.4s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 439 | `watch_virtual_property_proto` | 2 | 16.2s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 440 | `with` | 49 | 16.8s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 441 | `with_return` | 2 | 16.1s |  |
| 442 | `with_variable_scopes` | 43 | 17.6s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 443 | `xml` | 15 | 17.1s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 444 | `xml_append_child` | 28 | 16.6s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 445 | `xml_append_child_with_parent` | 20 | 16.8s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 446 | `xml_attributes_read` | 4 | 16.2s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 447 | `xml_cdata` | 11 | 16.0s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 448 | `xml_child_nodes_edge_cases` | 4 | 18.6s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 449 | `xml_clone_expandos` | 19 | 16.8s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 450 | `xml_first_last_child` | 8 | 16.9s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 451 | `xml_has_child_nodes` | 3 | 16.9s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 452 | `xml_idmap` | 21 | 16.6s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 453 | `xml_ignore_comments` | 21 | 16.7s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 454 | `xml_ignore_white` | 34 | 16.8s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 455 | `xml_insert_before` | 20 | 17.0s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 456 | `xml_inspect_createmethods` | 15 | 16.4s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 457 | `xml_inspect_doctype` | 7 | 16.6s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 458 | `xml_inspect_parsexml` | 62 | 16.2s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 459 | `xml_inspect_xmldecl` | 7 | 16.2s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 460 | `xml_namespaces` | 203 | 16.1s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 461 | `xml_parent_and_child` | 5 | 16.5s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 462 | `xml_remove_node` | 22 | 16.4s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 463 | `xml_reparenting` | 14 | 16.7s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 464 | `xml_siblings` | 10 | 16.9s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 465 | `xml_to_string` | 13 | 17.8s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 466 | `xml_to_string_comment` | 1 | 16.2s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 467 | `xml_unescaping` | 23 | 16.9s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 468 | `xmlnode_proto` | 1 | 15.9s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**24 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `focusrect_property_swf5` | 99.9% | 1236 | 1237 | 1 | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 2 | `focusrect_property_swf6` | 99.9% | 1236 | 1237 | 1 | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 3 | `focusrect_property_swf7` | 99.9% | 1236 | 1237 | 1 | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 4 | `selection` | 99.6% | 454 | 456 | 2 | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 5 | `date` | 99.2% | 6284 | 6335 | 51 | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) |
| 6 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 7 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56 | 57 | 1 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 8 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56 | 57 | 1 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 9 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 10 | `edittext_programmatic_focus` | 92.3% | 12 | 13 | 1 | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 11 | `movieclip_hittest_shapeflag` | 91.7% | 310 | 338 | 28 | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 12 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 13 | `edittext_focus_selection` | 66.7% | 2 | 3 | 1 | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 14 | `focus_root_movie` | 66.7% | 2 | 3 | 1 | [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 15 | `movieclip_invalid_get_bounds_3` | 61.5% | 8 | 13 | 5 | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 16 | `movieclip_invalid_get_bounds_4` | 61.5% | 8 | 13 | 5 | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 17 | `edittext_password_copy` | 60.0% | 3 | 5 | 2 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 18 | `movieclip_invalid_get_bounds_5` | 54.5% | 6 | 11 | 5 | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 19 | `movieclip_invalid_get_bounds_8` | 54.5% | 6 | 11 | 5 | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 20 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 21 | `loadmovie` | 50.0% | 1 | 2 | 1 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 22 | `loadmovie_method` | 50.0% | 1 | 2 | 1 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 23 | `movieclip_invalid_get_bounds_6` | 50.0% | 5 | 10 | 5 | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 24 | `movieclip_invalid_get_bounds_7` | 50.0% | 5 | 10 | 5 | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmap_filters` | 20.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `click_block` | 21.3s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 3 | `issue_2084` | 16.1s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 4 | `netstream_play_flv_screen` | 36.9s | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 5 | `place_and_lookup` | 16.8s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 45.9s | [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**112 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `focusrect_property_swf5` | 99.9% | 1236/1237 | 1236 | 1237 | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 2 | `focusrect_property_swf6` | 99.9% | 1236/1237 | 1236 | 1237 | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 3 | `focusrect_property_swf7` | 99.9% | 1236/1237 | 1236 | 1237 | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 4 | `selection` | 99.6% | 454/456 | 456 | 454 | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 5 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) |
| 6 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 7 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56/57 | 57 | 57 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 8 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56/57 | 57 | 57 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 9 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 10 | `edittext_programmatic_focus` | 92.3% | 12/13 | 13 | 12 | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 11 | `movieclip_hittest_shapeflag` | 91.7% | 310/338 | 338 | 338 | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 12 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 13 | `edittext_focus_selection` | 66.7% | 2/3 | 3 | 2 | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 14 | `focus_root_movie` | 66.7% | 2/3 | 3 | 2 | [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 15 | `movieclip_invalid_get_bounds_3` | 61.5% | 8/13 | 8 | 13 | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 16 | `movieclip_invalid_get_bounds_4` | 61.5% | 8/13 | 8 | 13 | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 17 | `edittext_password_copy` | 60.0% | 3/5 | 5 | 4 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 18 | `movieclip_invalid_get_bounds_5` | 54.5% | 6/11 | 6 | 11 | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 19 | `movieclip_invalid_get_bounds_8` | 54.5% | 6/11 | 6 | 11 | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 20 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 21 | `loadmovie` | 50.0% | 1/2 | 1 | 2 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 22 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 23 | `movieclip_invalid_get_bounds_6` | 50.0% | 5/10 | 5 | 10 | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 24 | `movieclip_invalid_get_bounds_7` | 50.0% | 5/10 | 5 | 10 | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 25 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 26 | `unloadmovienum` | 46.2% | 6/13 | 12 | 13 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 27 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 28 | `load_vars` | 37.1% | 13/35 | 23 | 35 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 29 | `movieclip_state_values` | 34.2% | 39/114 | 53 | 114 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 30 | `edittext_paste_empty` | 33.3% | 1/3 | 3 | 2 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 31 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 32 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 33 | `issue_2870` | 33.3% | 1/3 | 1 | 3 | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 34 | `loadmovienum` | 33.3% | 1/3 | 1 | 3 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 35 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 36 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 37 | `loadmovie_flashvars` | 25.0% | 1/4 | 1 | 4 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 38 | `tab_ordering_properties_tab_index_edge_case` | 25.0% | 1/4 | 4 | 4 |  |
| 39 | `unloadmovie` | 25.0% | 1/4 | 3 | 4 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 40 | `movieclip_lockroot` | 24.6% | 16/65 | 65 | 29 | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 41 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 42 | `movieclip_invalid_get_bounds_1` | 17.3% | 13/75 | 35 | 75 | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 43 | `movieclip_invalid_get_bounds_2` | 17.3% | 13/75 | 35 | 75 | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 44 | `tab_ordering_events` | 17.2% | 26/151 | 151 | 150 | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 45 | `edittext_restrict_paste` | 16.7% | 1/6 | 6 | 5 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 46 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 47 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 48 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 49 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 50 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 1 | 9 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 51 | `tab_ordering_children` | 10.5% | 22/209 | 209 | 208 | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 52 | `root_button_mode` | 10.0% | 1/10 | 4 | 10 | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 53 | `focusrect_swf6` | 9.5% | 4/42 | 24 | 42 | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 54 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 55 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 56 | `bitmap_data_pixeldissolve` | 7.6% | 82/1075 | 1055 | 1075 | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 57 | `edittext_default_format_empty` | 7.0% | 7/100 | 95 | 100 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 58 | `button_key_events` | 6.7% | 1/15 | 15 | 14 | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 59 | `input_dead_keys_windows` | 6.2% | 1/16 | 16 | 15 | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 60 | `tab_ordering_reverse` | 5.8% | 3/52 | 52 | 51 | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 61 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 62 | `button_keypress_vs_tab` | 4.8% | 1/21 | 21 | 20 | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 63 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 64 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 65 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 66 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 67 | `tab_ordering_custom_basic` | 4.2% | 3/72 | 72 | 71 | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 68 | `focusrect_swf5` | 3.6% | 1/28 | 28 | 6 | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 69 | `tab_ordering_automatic_basic` | 3.2% | 3/93 | 93 | 92 | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 70 | `global_instance_decls` | 2.4% | 18/758 | 695 | 758 | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 71 | `global_proto_decls_delete` | 2.2% | 91/4158 | 705 | 4158 | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 72 | `global_proto_decls` | 2.1% | 93/4497 | 1266 | 4497 | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 73 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 74 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 75 | `sound_id3` | 1.7% | 11/633 | 11 | 633 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 76 | `focus_keyboard_press` | 1.6% | 1/61 | 61 | 60 | [9](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 77 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 78 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 79 | `tab_ordering_movieclip_enabled_default` | 0.6% | 3/463 | 463 | 462 | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 80 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [22](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 81 | `button_key_events_special` | 0.0% | 0/46 | 46 | 45 | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 82 | `button_keypress_vs_press` | 0.0% | 0/26 | 26 | 25 | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 83 | `button_keypress_vs_textinput` | 0.0% | 0/5 | 5 | 4 | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 84 | `cross_movie_root` | 0.0% | 0/10 | 7 | 10 | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 85 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 86 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 7 | 7 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 87 | `edittext_input` | 0.0% | 0/2 | 2 | 1 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 88 | `edittext_input_newlines` | 0.0% | 0/10 | 10 | 9 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 89 | `edittext_restrict` | 0.0% | 0/192 | 192 | 191 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 90 | `focusrect_mouse_swf8` | 0.0% | 0/3 | 3 | 0 |  |
| 91 | `focusrect_mouse_swf9` | 0.0% | 0/7 | 7 | 0 |  |
| 92 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 93 | `geturl` | 0.0% | 0/7 | 0 | 7 | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 94 | `loadmovie_registerclass` | 0.0% | 0/30 | 0 | 30 | [11](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 95 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 96 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 97 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 98 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 99 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 100 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 101 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 102 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 103 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 104 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 105 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 106 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 0 | 29 | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 107 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 108 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 0 | 29 | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 109 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 110 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 111 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 112 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) | 17 | 15 | 2 |
| 6 | [BUTTON_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) | 14 | 8 | 6 |
| 7 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 8 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) | 8 | 8 | 0 |
| 9 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 3 | 1 |
| 10 | [COLOR_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 11 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 1 | 0 | 1 |
| 12 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 13 | [DATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 14 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 15 | [DRAG_DROP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 16 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 17 | [ENUMERATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 18 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 19 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 1 | 3 |
| 20 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 5 | 2 |
| 21 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 22 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 23 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 5 | 2 |
| 24 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 25 | [GLOBALS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 27 | 4 |
| 26 | [HIT_TESTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 8 | 9 |
| 27 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 23 | 0 | 23 |
| 28 | [infinite_recursion_function.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 29 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 0 | 1 |
| 30 | [issue_768.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 31 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 0 | 2 |
| 32 | [LOADMOVIE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) | 49 | 23 | 26 |
| 33 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 2 | 3 |
| 34 | [LOADVARIABLES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 35 | [LOCKROOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 0 | 1 |
| 36 | [MATH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 37 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 38 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 4 | 1 |
| 39 | [MOVIECLIP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) | 58 | 42 | 16 |
| 40 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 14 | 2 |
| 41 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 14 | 3 |
| 42 | [object_string_coerce.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 43 | [OBJECT_WATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 44 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 7 | 1 |
| 45 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 46 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 47 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 48 | [REGISTERCLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) | 15 | 14 | 1 |
| 49 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 4 | 2 | 2 |
| 50 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 51 | [SELECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) | 4 | 1 | 3 |
| 52 | [SOUND_CLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 53 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 54 | [STAGE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 55 | [string_coercion.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 56 | [STRING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) | 13 | 12 | 1 |
| 57 | [STYLESHEET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 58 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 59 | [TAB_ORDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 7 | 9 |
| 60 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 1 | 0 |
| 61 | [TELLTARGET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 17 | 2 |
| 62 | [TEXTFIELD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) | 70 | 29 | 41 |
| 63 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 0 | 4 |
| 64 | [THIS_BINDING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 65 | [this_swf7.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 66 | [TIMER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) | 3 | 2 | 1 |
| 67 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 68 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 2 | 0 |
| 69 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 8 | 8 |
| 70 | [UNLOAD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) | 12 | 9 | 3 |
| 71 | [WITH_SCOPE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 72 | [XML_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 153 | 148 | 5 |
