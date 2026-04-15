# Ruffle Test Results (Filtered)

**Date**: 2026-04-15 03:25 UTC

**Git SHA**: `9d17e1098f`

**Run Duration**: 211m 28s

**Filtered**: 40 tests ignored out of 641 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 601 |
| Passing | **578** (96.2%) |
| Failing | 23 |
| Total expected lines | 96461 |
| Matching lines | 74803 (77.5%) |
| Mismatched lines | 21658 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 22 | 95.7% |
| Compile Fail | 1 | 4.3% |

## Passing Tests

**578 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 19.1s |  |
| 2 | `action_to_integer` | 28 | 19.2s |  |
| 3 | `add` | 28 | 19.2s |  |
| 4 | `add2` | 354 | 19.2s | [1](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 19.1s | [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 19.3s |  |
| 7 | `add_swf5` | 28 | 19.3s |  |
| 8 | `arguments` | 127 | 19.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 19.1s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 19.1s |  |
| 11 | `array_constructor` | 30 | 19.1s |  |
| 12 | `array_enumerate` | 4 | 19.1s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 19.1s |  |
| 14 | `array_properties` | 36 | 19.1s |  |
| 15 | `array_prototyping` | 12 | 19.1s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 19.2s |  |
| 17 | `array_sort` | 161 | 19.9s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 19.5s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 19.2s |  |
| 20 | `array_trivial` | 209 | 19.1s |  |
| 21 | `as1_constructor_v6` | 35 | 19.1s |  |
| 22 | `as1_constructor_v7` | 35 | 19.1s |  |
| 23 | `as2_oop` | 13 | 21.0s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 20.5s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 20.5s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 20.3s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 20.1s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 20.0s |  |
| 29 | `as_broadcaster_undef` | 89 | 19.9s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 20.1s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 19.7s | [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 19.9s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 20.6s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 20.6s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 20.3s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 20.7s |  |
| 37 | `as_transformed_flag` | 20 | 20.6s |  |
| 38 | `asfunction` | 11 | 20.7s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) |
| 39 | `asnative` | 34 | 20.7s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `asnew` | 34 | 20.8s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 41 | `attach_movie` | 59 | 20.5s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 42 | `attach_movie_stop` | 3 | 20.9s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 43 | `bad_placeobject_clipaction` | 2 | 20.7s |  |
| 44 | `bad_swf_tag_past_eof` | 0 | 20.4s |  |
| 45 | `bitand` | 1058 | 24.8s |  |
| 46 | `bitmap_data` | 1126 | 23.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 47 | `bitmap_data_colortransform` | 0 | 21.8s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 48 | `bitmap_data_compare` | 40 | 21.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 49 | `bitmap_data_copypixels` | 17 | 21.9s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 50 | `bitmap_data_draw_cliprect` | 13 | 21.6s |  |
| 51 | `bitmap_data_fillrect` | 0 | 21.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 52 | `bitmap_data_hittest` | 132 | 22.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 53 | `bitmap_data_max_size_swf10` | 12 | 21.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 54 | `bitmap_data_max_size_swf9` | 10 | 21.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 55 | `bitmap_data_noise` | 631 | 21.7s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 56 | `bitmap_data_perlinnoise` | 0 | 21.8s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 57 | `bitmap_data_pixeldissolve` | 1075 | 22.0s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 58 | `bitmap_data_pixeldissolve_image` | 0 | 22.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 59 | `bitmap_data_threshold` | 176 | 20.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 60 | `bitmapdata_applyfilter_colormatrix` | 0 | 19.8s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 61 | `bitmapdata_channels` | 19 | 19.6s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 62 | `bitor` | 1058 | 22.4s |  |
| 63 | `biturshift` | 14 | 19.6s |  |
| 64 | `biturshift_swf8` | 14 | 19.9s |  |
| 65 | `bitxor` | 1058 | 23.7s |  |
| 66 | `boxed_primitives` | 24 | 20.4s | [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 67 | `button_children` | 8 | 20.0s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `button_goto` | 4 | 20.1s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 69 | `button_key_events` | 14 | 20.4s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 70 | `button_key_events_special` | 45 | 21.0s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 71 | `button_keypress` | 3 | 20.2s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 72 | `button_keypress_vs_press` | 25 | 19.7s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 73 | `button_keypress_vs_tab` | 20 | 19.6s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 74 | `button_keypress_vs_textinput` | 4 | 19.4s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 75 | `button_order` | 2 | 19.4s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 76 | `button_properties_special_cases` | 22 | 20.0s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 77 | `button_v5` | 18 | 19.2s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 78 | `button_v6` | 18 | 19.2s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 79 | `call` | 63 | 19.4s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 80 | `call_method_empty_name` | 1 | 19.3s |  |
| 81 | `capabilities_resolution` | 8 | 19.7s |  |
| 82 | `catch_references_registers` | 2 | 19.5s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 83 | `click_block` | 5 | 19.6s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 84 | `clip_constructors` | 8 | 19.8s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 85 | `clip_event_propagation_order` | 17 | 20.0s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 86 | `clip_events` | 19 | 20.1s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 87 | `clone_sprite_edittext` | 94 | 19.9s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 88 | `clone_sprite_edittext_dynamic` | 86 | 19.9s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 89 | `clone_sprite_types` | 24 | 19.6s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 90 | `closure_scope` | 7 | 19.3s | [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 91 | `coerce_to_object_monkeypatch` | 129 | 19.6s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 92 | `coerce_to_primitive_resolve` | 17 | 19.1s | [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 93 | `color` | 57 | 19.4s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 94 | `color_transform` | 48 | 19.0s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 95 | `conflicting_instance_names` | 23 | 19.1s |  |
| 96 | `constructor_function` | 2 | 19.0s |  |
| 97 | `context_menu` | 39 | 19.1s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 98 | `context_menu_item` | 41 | 19.1s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 99 | `create_empty_movie_clip` | 3 | 18.9s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 100 | `cross_movie_root` | 10 | 19.5s | [50](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 101 | `custom_clip_methods` | 4 | 19.7s | [22](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 102 | `default_names` | 52 | 19.6s | [24](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 103 | `define_function2` | 8 | 19.2s |  |
| 104 | `define_function2_preload` | 13 | 19.3s |  |
| 105 | `define_function2_preload_order` | 4 | 19.0s |  |
| 106 | `define_function_case_sensitive` | 2 | 19.0s |  |
| 107 | `define_local` | 27 | 18.8s | [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 108 | `define_local_with_paths` | 54 | 18.9s | [99](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 109 | `delete` | 3 | 18.9s |  |
| 110 | `device_font_spacing` | 91 | 20.2s | [99](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 111 | `displacementmapfilter_mappoint_throw_error` | 13 | 19.3s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) [99](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 112 | `display_object_properties` | 2 | 19.2s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 113 | `divide_swf4` | 107 | 19.3s |  |
| 114 | `do_init_action` | 3 | 19.5s |  |
| 115 | `do_init_action_child` | 12 | 19.4s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 116 | `drag_drop` | 10 | 19.3s | [27](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 117 | `drag_over_from_outside` | 1 | 19.4s | [27](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 118 | `drag_over_without_startdrag` | 1 | 19.7s | [27](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 119 | `duplicate_movie_clip` | 20 | 19.8s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 120 | `duplicate_movie_clip_drawing` | 2 | 19.4s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 121 | `edittext_align` | 60 | 19.4s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 122 | `edittext_align_trailing_spaces_swf7` | 576 | 19.4s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 123 | `edittext_align_trailing_spaces_swf8` | 576 | 19.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 124 | `edittext_antialiastype` | 296 | 20.0s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 125 | `edittext_autosize` | 71 | 19.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 126 | `edittext_autosize_setter` | 20 | 19.5s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 127 | `edittext_bullet` | 30 | 19.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 128 | `edittext_default_format` | 221 | 19.2s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 129 | `edittext_default_format_empty` | 100 | 19.1s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 130 | `edittext_default_format_font_style` | 335 | 19.2s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 131 | `edittext_drag_select` | 9 | 19.1s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 132 | `edittext_focus_selection` | 2 | 19.5s | [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 133 | `edittext_font_size` | 45 | 19.7s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 134 | `edittext_hscroll` | 27 | 19.4s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 135 | `edittext_html_align_swf7` | 52 | 19.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 136 | `edittext_html_align_swf8` | 52 | 19.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 137 | `edittext_html_color` | 114 | 19.5s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 138 | `edittext_html_condensewhite_swf7` | 311 | 19.7s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 139 | `edittext_html_condensewhite_swf8` | 311 | 19.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 140 | `edittext_html_entity` | 4 | 19.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 141 | `edittext_html_roundtrip` | 17 | 19.4s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 142 | `edittext_html_swf6` | 5377 | 20.8s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 143 | `edittext_html_swf7` | 5377 | 20.8s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 144 | `edittext_html_swf8` | 5377 | 20.9s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 145 | `edittext_ime_focus_lost` | 7 | 19.4s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 146 | `edittext_input` | 1 | 19.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 147 | `edittext_input_newlines` | 9 | 19.4s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 148 | `edittext_leading` | 9 | 19.5s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 149 | `edittext_letter_spacing` | 15 | 19.4s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 150 | `edittext_margins` | 25 | 19.5s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 151 | `edittext_newline_stripping` | 64 | 24.3s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 152 | `edittext_newlines` | 30 | 19.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 153 | `edittext_password` | 5 | 19.4s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 154 | `edittext_password_copy` | 4 | 19.4s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 155 | `edittext_paste_empty` | 2 | 20.0s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 156 | `edittext_place_caret` | 2 | 20.1s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 157 | `edittext_programmatic_focus` | 12 | 20.7s | [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 158 | `edittext_restrict` | 191 | 20.4s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 159 | `edittext_restrict_paste` | 5 | 20.1s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 160 | `edittext_scroll` | 54 | 20.7s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 161 | `edittext_stylesheet` | 325 | 21.3s | [20](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 162 | `edittext_tab_focus` | 13 | 19.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 163 | `edittext_tab_stops` | 60 | 19.9s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 164 | `edittext_tag_indent` | 31 | 19.7s | [20](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 165 | `edittext_text_height_leading` | 20 | 19.8s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 166 | `edittext_underline` | 40 | 19.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 167 | `edittext_width_height` | 103 | 19.5s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 168 | `empty_movieclip_can_attach_movies` | 11 | 19.2s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 169 | `enumerate` | 64 | 19.6s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 170 | `equals` | 32 | 19.6s |  |
| 171 | `equals2_swf5` | 926 | 21.2s |  |
| 172 | `equals2_swf6` | 926 | 21.2s |  |
| 173 | `equals2_swf7` | 926 | 21.2s |  |
| 174 | `equals_swf4` | 665 | 20.4s |  |
| 175 | `equals_swf4_alt` | 32 | 19.7s |  |
| 176 | `equals_swf5` | 32 | 20.0s |  |
| 177 | `error` | 58 | 19.7s |  |
| 178 | `escape` | 14 | 19.4s |  |
| 179 | `execution_order1` | 5 | 19.1s |  |
| 180 | `execution_order2` | 7 | 19.2s |  |
| 181 | `execution_order3` | 4 | 19.1s |  |
| 182 | `execution_order4` | 12 | 19.5s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 183 | `export_assets` | 3 | 19.3s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 184 | `extends_chain` | 134 | 20.0s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 185 | `extends_native_type` | 11 | 19.8s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 186 | `external_interface` | 84 | 19.6s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 187 | `external_interface_escapexml` | 26 | 19.1s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 188 | `external_interface_jsquotestring` | 21 | 19.2s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 189 | `external_interface_toas_basic` | 354 | 19.3s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 190 | `external_interface_toxml_array` | 25 | 19.1s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 191 | `external_interface_toxml_basic` | 179 | 19.2s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 192 | `external_interface_unescapexml` | 40 | 19.0s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 193 | `focus_keyboard_press` | 60 | 19.0s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 194 | `focus_mouse` | 45 | 18.9s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 195 | `focus_mouse_focusable` | 8 | 19.4s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 196 | `focus_mouse_rollout` | 4 | 18.9s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 197 | `focus_remove` | 33 | 18.8s |  |
| 198 | `focus_root_movie` | 2 | 18.9s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 199 | `focus_visibility_change` | 45 | 18.8s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 200 | `focusrect_focuslost` | 4 | 19.1s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 201 | `focusrect_mouse_swf8` | 0 | 19.2s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 202 | `focusrect_mouse_swf9` | 0 | 19.3s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 203 | `focusrect_property_swf5` | 1237 | 19.1s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 204 | `focusrect_property_swf6` | 1237 | 19.1s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 205 | `focusrect_property_swf7` | 1237 | 19.3s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 206 | `focusrect_swf5` | 6 | 19.3s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 207 | `focusrect_swf6` | 42 | 19.4s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 208 | `form_loader_encoding_1` | 1 | 19.0s |  |
| 209 | `frame_size_translated_negative` | 21 | 19.5s | [20](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 210 | `frame_size_translated_positive` | 21 | 19.6s | [20](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 211 | `function_base_clip` | 8 | 19.3s |  |
| 212 | `function_base_clip_readded` | 11 | 19.4s |  |
| 213 | `function_base_clip_removed` | 25 | 19.2s |  |
| 214 | `function_suppress_and_preload` | 28 | 19.0s |  |
| 215 | `get_bytes_total` | 4 | 19.2s | [99](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 216 | `get_variable_in_scope` | 29 | 19.1s |  |
| 217 | `getproperty` | 28 | 19.7s |  |
| 218 | `getproperty_swf4` | 28 | 19.8s |  |
| 219 | `getproperty_swf5` | 28 | 19.1s |  |
| 220 | `gettextextent` | 56 | 19.2s | [99](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 221 | `global_array` | 3 | 19.0s |  |
| 222 | `global_is_bare` | 7 | 19.1s |  |
| 223 | `global_swf5_6_7_8_9` | 1145 | 20.5s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 224 | `global_swf6_7_8` | 15 | 23.6s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 225 | `globals_swf6` | 304 | 27.0s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 226 | `globals_swf7` | 304 | 21.0s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 227 | `globals_swf8` | 304 | 24.1s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 228 | `goto_advance1` | 6 | 22.4s |  |
| 229 | `goto_advance2` | 2 | 22.7s |  |
| 230 | `goto_both_ways1` | 3 | 21.6s |  |
| 231 | `goto_both_ways2` | 3 | 24.9s |  |
| 232 | `goto_execution_order` | 2 | 21.0s |  |
| 233 | `goto_execution_order2` | 2 | 22.8s |  |
| 234 | `goto_frame` | 12 | 20.8s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 235 | `goto_frame2` | 44 | 26.4s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 236 | `goto_frame_number` | 3 | 20.6s |  |
| 237 | `goto_label` | 17 | 21.1s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 238 | `goto_methods` | 40 | 21.5s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 239 | `goto_rewind1` | 1 | 21.2s |  |
| 240 | `goto_rewind2` | 3 | 22.1s |  |
| 241 | `goto_rewind3` | 2 | 22.4s |  |
| 242 | `greater_swf6` | 1175 | 23.1s |  |
| 243 | `greater_swf7` | 1175 | 28.6s |  |
| 244 | `greaterthan_swf5` | 1 | 19.7s |  |
| 245 | `greaterthan_swf8` | 1 | 19.5s |  |
| 246 | `has_own_property` | 32 | 19.5s |  |
| 247 | `hittest_lockroot` | 15 | 19.9s | [44](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 248 | `hittest_morph` | 70 | 19.3s | [44](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 249 | `hittest_morph_input` | 1 | 19.5s | [44](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 250 | `hittest_winding_rule` | 12 | 19.8s | [44](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 251 | `infinite_recursion_function` | 4 | 19.4s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 252 | `infinite_recursion_function_in_setter` | 131 | 19.5s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 253 | `infinite_recursion_virtual_property` | 67 | 19.5s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 254 | `init_array_invalid` | 4 | 19.5s |  |
| 255 | `init_object_invalid` | 4 | 19.5s |  |
| 256 | `init_object_order` | 15 | 19.6s | [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 257 | `input_dead_keys_windows` | 15 | 19.4s | [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 258 | `instanceof_coercions` | 88 | 19.9s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 259 | `interface_implements_op` | 47 | 19.7s | [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 260 | `is_finite` | 49 | 19.1s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 261 | `is_finite_swf6` | 49 | 19.3s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 262 | `is_prototype_of` | 89 | 19.2s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 263 | `issue_1086` | 1 | 19.3s |  |
| 264 | `issue_1104` | 2 | 19.2s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 265 | `issue_1671` | 0 | 18.7s |  |
| 266 | `issue_1906` | 4 | 18.4s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 267 | `issue_2030` | 4 | 18.6s | [99](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 268 | `issue_2084` | 16 | 19.1s | [99](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 269 | `issue_2166` | 9 | 18.4s |  |
| 270 | `issue_2870` | 3 | 18.7s | [50](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 271 | `issue_3169` | 2 | 18.7s | [99](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 272 | `issue_3446` | 1 | 18.6s |  |
| 273 | `issue_3522` | 2 | 18.7s |  |
| 274 | `issue_4377` | 2 | 18.6s |  |
| 275 | `issue_710` | 4 | 18.6s |  |
| 276 | `issue_768` | 3 | 18.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) |
| 277 | `issue_9327` | 2 | 18.8s |  |
| 278 | `issue_9885` | 2 | 18.2s |  |
| 279 | `key_isToggled` | 9 | 18.4s |  |
| 280 | `lessthan` | 41 | 18.8s |  |
| 281 | `lessthan2_swf5` | 1226 | 20.5s |  |
| 282 | `lessthan2_swf6` | 1226 | 20.4s |  |
| 283 | `lessthan2_swf7` | 1226 | 20.5s |  |
| 284 | `lessthan_swf4` | 902 | 19.6s |  |
| 285 | `lessthan_swf4_alt` | 41 | 18.6s |  |
| 286 | `lessthan_swf5` | 41 | 20.3s |  |
| 287 | `loadmovie` | 2 | 20.9s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 288 | `loadmovie_fail` | 2 | 21.5s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 289 | `loadmovie_flashvars` | 4 | 20.5s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 290 | `loadmovie_method` | 2 | 20.2s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 291 | `loadmovie_registerclass` | 30 | 20.6s | [21](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 292 | `loadmovie_replace_root` | 5 | 19.8s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 293 | `loadmovie_var_persistence` | 8 | 20.1s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [52](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) |
| 294 | `loadmovienum` | 3 | 20.0s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 295 | `loadmovienum_cross_version_prototype` | 9 | 20.2s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [52](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) |
| 296 | `loadvariables` | 2 | 19.9s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 297 | `loadvariables2` | 8 | 19.9s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 298 | `loadvariablesnum` | 2 | 19.7s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 299 | `local_to_global` | 49 | 19.4s | [44](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 300 | `localconnection_properties` | 8 | 20.0s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 301 | `lock_root` | 1 | 20.1s |  |
| 302 | `logical_ops_swf4` | 90 | 20.4s |  |
| 303 | `logical_ops_swf8` | 108 | 19.9s |  |
| 304 | `looping` | 6 | 20.1s |  |
| 305 | `mask_reapply` | 0 | 20.5s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 306 | `mask_with_drawing` | 0 | 20.5s | [28](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 307 | `math_min_max` | 101 | 20.0s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 308 | `math_swf6` | 530 | 20.6s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 309 | `math_swf7` | 530 | 20.4s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 310 | `math_swf8` | 530 | 20.4s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 311 | `matrix` | 171 | 20.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 312 | `mcl_as_broadcaster` | 12 | 19.8s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 313 | `mcl_events_swf_version` | 232 | 20.7s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [52](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 314 | `mcl_getprogress` | 30 | 20.3s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 315 | `mcl_loadclip` | 149 | 20.3s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 316 | `mcl_loadclip_properties` | 6 | 20.2s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 317 | `mcl_loadclip_replace_root` | 1 | 20.2s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 318 | `mcl_mislabeled_target` | 6 | 20.4s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 319 | `mcl_target_gif87a` | 6 | 20.7s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 320 | `mcl_target_gif89a` | 6 | 20.3s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 321 | `mcl_target_jpg` | 6 | 19.9s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 322 | `mcl_target_png` | 6 | 19.9s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 323 | `mcl_unloadclip` | 5 | 17.2s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 324 | `mouse_events` | 8 | 16.4s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 325 | `mouse_events_visible_enabled` | 12 | 16.2s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 326 | `mouse_hover_events_while_dragging` | 1 | 15.8s | [27](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 327 | `mouse_listeners` | 67 | 15.7s |  |
| 328 | `mouse_pos` | 665 | 15.7s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 329 | `mouse_pos_with_scale_factor` | 260 | 16.1s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 330 | `mouse_wheel_enabled` | 2 | 16.0s |  |
| 331 | `movieclip_begin_gradient_fill` | 0 | 17.6s | [28](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 332 | `movieclip_blend_mode_property` | 35 | 17.7s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 333 | `movieclip_create_text_field` | 90 | 17.8s | [20](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 334 | `movieclip_default_state` | 69 | 17.8s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 335 | `movieclip_depth_methods` | 98 | 17.7s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 336 | `movieclip_focusenabled` | 99 | 17.4s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 337 | `movieclip_get_instance_at_depth` | 28 | 17.4s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 338 | `movieclip_getbounds` | 191 | 17.7s | [44](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 339 | `movieclip_gettextsnapshot` | 112 | 17.8s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 340 | `movieclip_hittest` | 92 | 17.7s | [44](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 341 | `movieclip_in_removed_button` | 4 | 17.4s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 342 | `movieclip_init_object` | 5 | 16.6s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 343 | `movieclip_invalid_get_bounds_1` | 75 | 20.6s | [44](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 344 | `movieclip_invalid_get_bounds_2` | 75 | 20.3s | [44](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 345 | `movieclip_invalid_get_bounds_3` | 13 | 19.9s | [44](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 346 | `movieclip_invalid_get_bounds_4` | 13 | 19.9s | [44](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 347 | `movieclip_invalid_get_bounds_5` | 11 | 19.9s | [44](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 348 | `movieclip_invalid_get_bounds_6` | 10 | 43.4s | [44](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 349 | `movieclip_invalid_get_bounds_7` | 10 | 43.5s | [44](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 350 | `movieclip_invalid_get_bounds_8` | 11 | 19.8s | [44](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 351 | `movieclip_line_gradient_style` | 0 | 20.1s | [28](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 352 | `movieclip_lockroot` | 29 | 19.9s | [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 353 | `movieclip_methods_with_loaded_image` | 4 | 19.7s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 354 | `movieclip_name_from_timeline` | 13 | 19.3s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 355 | `movieclip_prototype_extension` | 5 | 19.4s |  |
| 356 | `movieclip_setmask` | 14 | 19.9s | [28](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 357 | `movieclip_state_values` | 114 | 20.6s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [52](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 358 | `moviecliploader_flashvars` | 4 | 19.3s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 359 | `mutable_this` | 18 | 19.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 360 | `named_shapes` | 14 | 19.4s |  |
| 361 | `nan_scale` | 9 | 19.5s |  |
| 362 | `native_double_construct` | 12 | 19.7s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 363 | `native_objects_swf7` | 115 | 23.0s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 364 | `native_objects_swf8` | 115 | 23.0s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 365 | `native_subclasses` | 191 | 23.0s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 366 | `nested_textfields_in_buttons` | 0 | 22.2s |  |
| 367 | `netconnection_close` | 39 | 22.4s | [45](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) |
| 368 | `netstream_play_flv` | 21 | 22.9s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 369 | `netstream_seek_flv` | 25 | 22.9s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 370 | `new_method_wrap` | 4 | 22.3s |  |
| 371 | `new_object_enumerate` | 7 | 22.2s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 372 | `new_object_wrap` | 4 | 22.2s |  |
| 373 | `o` | 3 | 22.2s |  |
| 374 | `object_constructor` | 33 | 22.2s |  |
| 375 | `object_function` | 32 | 22.3s |  |
| 376 | `object_properties` | 31 | 22.5s | [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 377 | `object_prototypes` | 74 | 22.3s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 378 | `object_resolve` | 38 | 22.7s | [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 379 | `object_string_coerce_swf5` | 62 | 22.3s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 380 | `object_string_coerce_swf6` | 68 | 22.3s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 381 | `on_construct` | 25 | 20.0s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 382 | `parse_float` | 74 | 19.8s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 383 | `parse_int` | 64 | 20.3s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 384 | `path_string` | 322 | 19.9s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 385 | `place_and_lookup` | 30 | 19.6s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 386 | `placeobject_occupied_depth` | 6 | 19.4s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 387 | `point` | 175 | 19.9s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 388 | `primitive_instanceof` | 37 | 19.5s |  |
| 389 | `primitive_type_globals` | 557 | 19.3s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 390 | `printjob_props_swf5` | 45 | 19.4s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 391 | `printjob_props_swf6` | 45 | 19.4s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 392 | `printjob_props_swf7` | 45 | 19.2s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 393 | `property_invalid_base_clip` | 36 | 19.5s |  |
| 394 | `prototype_delete` | 12 | 19.2s |  |
| 395 | `prototype_enumerate` | 5 | 19.1s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 396 | `prototype_properties` | 17 | 19.1s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 397 | `rectangle` | 745 | 20.1s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 398 | `recursive_prototypes` | 0 | 19.4s |  |
| 399 | `register_and_init_order` | 231 | 19.9s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 400 | `register_class` | 66 | 19.7s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 401 | `register_class_return_value` | 16 | 19.3s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 402 | `register_class_swf6` | 37 | 19.8s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 403 | `register_class_with_sound` | 11 | 19.8s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 404 | `register_globals_across_frames` | 15 | 19.3s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 405 | `register_underflow` | 26 | 19.4s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 406 | `remove_movie_clip` | 29 | 19.5s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 407 | `removed_clip_halts_script` | 15 | 19.9s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 408 | `removed_target_clip_scope` | 35 | 19.5s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 409 | `resolve_different_root` | 2 | 19.6s | [99](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 410 | `rewind_depth` | 30 | 19.5s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 411 | `root_button_mode` | 10 | 19.7s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 412 | `root_global_parent` | 6 | 19.4s | [99](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 413 | `root_onload` | 1 | 19.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 414 | `sandbox_type_local_file` | 1 | 19.3s |  |
| 415 | `sandbox_type_local_network` | 1 | 19.3s |  |
| 416 | `selection` | 454 | 19.4s | [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 417 | `selection_handlers` | 27 | 19.4s | [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 418 | `set_interval` | 27 | 19.4s | [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 419 | `set_variable_scope` | 58 | 19.3s |  |
| 420 | `single_frame` | 1 | 19.3s |  |
| 421 | `slash_syntax` | 14 | 19.6s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 422 | `sound` | 628 | 20.3s | [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 423 | `sound_duration_position_props` | 290 | 20.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) |
| 424 | `sound_id3` | 633 | 20.6s | [45](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) |
| 425 | `sound_id3_prop` | 138 | 20.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) |
| 426 | `sound_load_start` | 3 | 20.6s | [45](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) |
| 427 | `sound_multiple_load` | 1 | 19.9s | [45](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) |
| 428 | `sound_props_swf5` | 68 | 19.9s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 429 | `sound_props_swf6` | 68 | 19.6s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 430 | `sound_start_load` | 0 | 20.0s |  |
| 431 | `stage_display_state` | 16 | 19.7s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 432 | `stage_object_children` | 83 | 19.8s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 433 | `stage_object_enumerate` | 4 | 19.4s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 434 | `stage_object_properties` | 241 | 20.1s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 435 | `stage_object_properties_get_var` | 5 | 19.5s |  |
| 436 | `stage_object_properties_swf6` | 231 | 19.7s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 437 | `stage_property_representation` | 586 | 19.8s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 438 | `stage_scale_mode` | 39 | 19.6s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 439 | `strictequals_swf6` | 902 | 21.0s |  |
| 440 | `strictly_equals` | 7 | 20.1s |  |
| 441 | `string_coercion` | 117 | 20.2s | [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) |
| 442 | `string_methods` | 285 | 16.7s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 443 | `string_methods_negative_args` | 240 | 15.7s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 444 | `string_methods_swfv5` | 275 | 16.1s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 445 | `string_ops_swf6` | 95 | 15.6s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 446 | `string_paths_basic` | 4 | 15.3s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 447 | `string_paths_eval` | 4 | 15.5s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 448 | `string_paths_eval2` | 7 | 15.4s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 449 | `string_paths_hidden` | 54 | 15.4s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 450 | `string_paths_keyevents` | 0 | 15.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 451 | `string_paths_other` | 36 | 15.4s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 452 | `string_paths_timer` | 0 | 15.7s | [99](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 453 | `string_paths_unload` | 1 | 15.9s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 454 | `string_paths_variable_alias` | 4 | 15.5s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 455 | `string_paths_variable_scopes` | 5 | 15.4s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 456 | `stylesheet` | 283 | 16.0s |  |
| 457 | `stylesheet_transform` | 750 | 16.4s |  |
| 458 | `super_edge_cases` | 39 | 15.8s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 459 | `swf4_actions_bool` | 96 | 15.7s |  |
| 460 | `swf4_actions_coercion_order` | 158 | 16.7s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 461 | `swf4_bool` | 4 | 17.0s |  |
| 462 | `swf4_function_calls` | 7 | 16.6s |  |
| 463 | `swf5_encoding` | 3 | 15.6s |  |
| 464 | `swf5_global_funcs` | 232 | 15.6s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 465 | `swf5_no_closure` | 19 | 15.7s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 466 | `swf5_to_6_cross_call` | 29 | 15.6s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 467 | `swf5_xml_event_handler_context` | 2 | 15.7s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 468 | `swf6_case_insensitive` | 42 | 15.6s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 469 | `swf6_global_funcs` | 232 | 15.5s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 470 | `swf6_string_as_bool` | 15 | 15.9s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 471 | `swf6_to_5_cross_call` | 29 | 15.9s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 472 | `swf7_case_sensitive` | 44 | 16.1s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 473 | `swf7_global_funcs` | 232 | 16.0s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 474 | `tab_ordering_automatic_basic` | 92 | 16.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 475 | `tab_ordering_automatic_order_grid` | 21 | 16.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 476 | `tab_ordering_automatic_order_same_position` | 12 | 15.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 477 | `tab_ordering_children` | 208 | 16.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 478 | `tab_ordering_custom_basic` | 71 | 15.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 479 | `tab_ordering_custom_duplicate_index` | 22 | 15.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 480 | `tab_ordering_custom_i32_vs_u32` | 12 | 15.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 481 | `tab_ordering_custom_m1` | 29 | 19.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 482 | `tab_ordering_events` | 150 | 20.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 483 | `tab_ordering_events_mouse` | 65 | 20.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 484 | `tab_ordering_movieclip_enabled_default` | 462 | 20.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 485 | `tab_ordering_properties` | 293 | 19.8s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 486 | `tab_ordering_reverse` | 51 | 20.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 487 | `tab_ordering_tabbable` | 47 | 19.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 488 | `target_clip_removed` | 5 | 20.4s | [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 489 | `target_clip_swf5` | 2 | 20.0s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 490 | `target_clip_swf6` | 2 | 19.4s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 491 | `target_path` | 14 | 20.0s |  |
| 492 | `tell_target` | 37 | 19.6s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 493 | `tell_target_invalid` | 6 | 19.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 494 | `tell_target_invalid_swf6` | 5 | 19.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 495 | `text_blocks_clicks` | 4 | 19.4s | [44](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 496 | `text_format` | 1146 | 19.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 497 | `text_format_display` | 21 | 19.1s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 498 | `text_format_font_max_length` | 2 | 19.1s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 499 | `text_format_get_text_extent_undefined_width` | 10 | 19.2s |  |
| 500 | `text_format_rounding_swf7` | 840 | 19.4s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 501 | `text_format_rounding_swf8` | 840 | 19.7s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 502 | `textfield_background_color` | 11 | 19.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 503 | `textfield_border_color` | 11 | 19.4s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 504 | `textfield_cache_as_bitmap` | 1 | 19.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 505 | `textfield_maxchars` | 3 | 19.5s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 506 | `textfield_properties` | 44 | 19.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 507 | `textfield_props_swf5` | 175 | 19.7s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 508 | `textfield_props_swf6` | 210 | 19.7s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 509 | `textfield_props_swf7` | 210 | 19.7s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 510 | `textfield_props_swf8` | 210 | 19.7s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 511 | `textfield_text` | 7 | 19.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 512 | `textfield_variable` | 81 | 19.8s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 513 | `textsnapshot_available_text` | 20 | 19.7s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 514 | `textsnapshot_findtext` | 44 | 20.0s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 515 | `textsnapshot_gettext` | 55 | 20.1s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 516 | `textsnapshot_props_swf5` | 56 | 19.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 517 | `textsnapshot_props_swf6` | 56 | 19.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 518 | `textsnapshot_text_order` | 1 | 19.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 519 | `this_scoping` | 52 | 19.7s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 520 | `this_swf5` | 41 | 19.6s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 521 | `this_swf6` | 41 | 19.5s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 522 | `this_swf7` | 41 | 21.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) |
| 523 | `timeline_function_def` | 7 | 21.5s |  |
| 524 | `timeout` | 0 | 25.9s | [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 525 | `timer_run_actions` | 18 | 21.1s | [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 526 | `trace` | 8 | 20.6s |  |
| 527 | `transform` | 70 | 20.6s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 528 | `try_catch_finally` | 118 | 20.6s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 529 | `try_finally_simple` | 16 | 20.5s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 530 | `typeof` | 22 | 20.6s |  |
| 531 | `typeof_globals` | 7 | 20.3s |  |
| 532 | `uncaught_exception` | 1 | 20.3s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 533 | `uncaught_exception_bubbled` | 1 | 20.8s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 534 | `undefined_to_string_swf6` | 4 | 20.0s |  |
| 535 | `unescape` | 43 | 19.9s |  |
| 536 | `unload` | 52 | 19.9s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 537 | `unload_clip_event` | 4 | 19.9s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 538 | `unload_nested_child` | 5 | 20.1s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 539 | `unloadmovie` | 4 | 19.8s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 540 | `unloadmovie_method` | 3 | 19.7s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 541 | `unloadmovienum` | 13 | 19.6s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 542 | `use_hand_cursor` | 8 | 19.5s |  |
| 543 | `variable_args` | 5 | 19.2s |  |
| 544 | `waitforframe` | 7 | 19.1s |  |
| 545 | `waitforframe2` | 16 | 19.1s |  |
| 546 | `watch` | 117 | 19.3s | [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 547 | `watch_textfield` | 12 | 18.8s | [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 548 | `watch_virtual_property_proto` | 2 | 19.0s | [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 549 | `with` | 49 | 19.0s | [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 550 | `with_return` | 2 | 18.9s |  |
| 551 | `with_variable_scopes` | 43 | 19.0s | [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 552 | `xml` | 15 | 18.9s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 553 | `xml_append_child` | 28 | 18.9s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 554 | `xml_append_child_with_parent` | 20 | 19.1s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 555 | `xml_attributes_read` | 4 | 18.9s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 556 | `xml_cdata` | 11 | 18.9s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 557 | `xml_child_nodes_edge_cases` | 4 | 18.8s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 558 | `xml_clone_expandos` | 19 | 18.9s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 559 | `xml_first_last_child` | 8 | 18.9s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 560 | `xml_has_child_nodes` | 3 | 18.8s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 561 | `xml_idmap` | 21 | 19.0s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 562 | `xml_ignore_comments` | 21 | 19.8s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 563 | `xml_ignore_white` | 34 | 19.0s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 564 | `xml_insert_before` | 20 | 19.0s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 565 | `xml_inspect_createmethods` | 15 | 19.1s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 566 | `xml_inspect_doctype` | 7 | 19.2s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 567 | `xml_inspect_parsexml` | 62 | 18.9s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 568 | `xml_inspect_xmldecl` | 7 | 18.8s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 569 | `xml_load` | 2 | 19.0s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 570 | `xml_namespaces` | 203 | 18.8s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 571 | `xml_parent_and_child` | 5 | 18.8s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 572 | `xml_remove_node` | 22 | 18.9s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 573 | `xml_reparenting` | 14 | 19.1s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 574 | `xml_siblings` | 10 | 19.3s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 575 | `xml_to_string` | 13 | 19.4s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 576 | `xml_to_string_comment` | 1 | 19.6s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 577 | `xml_unescaping` | 23 | 20.1s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 578 | `xmlnode_proto` | 1 | 20.2s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**6 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `function_as_function` | 94.3% | 33 | 35 | 2 | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 2 | `funky_function_calls` | 92.9% | 52 | 56 | 4 | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 3 | `bitmap_data_thorough/getColorBoundsRect` | 83.5% | 238 | 285 | 47 |  |
| 4 | `bitmap_data_thorough/getPixel` | 78.7% | 111 | 141 | 30 |  |
| 5 | `bitmap_data_thorough/getPixel32` | 78.7% | 111 | 141 | 30 |  |
| 6 | `bitmap_data_thorough/hitTest` | 54.9% | 285 | 519 | 234 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**22 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `function_as_function` | 94.3% | 33/35 | 35 | 35 | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 2 | `funky_function_calls` | 92.9% | 52/56 | 56 | 56 | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 3 | `bitmap_data_thorough/getColorBoundsRect` | 83.5% | 238/285 | 285 | 285 |  |
| 4 | `bitmap_data_thorough/getPixel` | 78.7% | 111/141 | 141 | 141 |  |
| 5 | `bitmap_data_thorough/getPixel32` | 78.7% | 111/141 | 141 | 141 |  |
| 6 | `bitmap_data_thorough/hitTest` | 54.9% | 285/519 | 510 | 519 |  |
| 7 | `bitmap_data_thorough/compare` | 42.0% | 29/69 | 60 | 69 |  |
| 8 | `bitmap_data_thorough/constructor` | 6.7% | 21/313 | 163 | 313 |  |
| 9 | `bitmap_data_thorough/perlinNoise` | 5.1% | 435/8481 | 5274 | 8481 |  |
| 10 | `bitmap_data_thorough/colorTransform` | 2.9% | 8/279 | 123 | 279 |  |
| 11 | `bitmap_data_thorough/fillRect` | 2.6% | 9/342 | 150 | 342 |  |
| 12 | `bitmap_data_thorough/scroll` | 2.6% | 10/384 | 168 | 384 |  |
| 13 | `bitmap_data_thorough/threshold` | 2.4% | 31/1308 | 555 | 1308 |  |
| 14 | `bitmap_data_thorough/setPixel` | 2.3% | 12/531 | 231 | 531 |  |
| 15 | `bitmap_data_thorough/setPixel32` | 2.3% | 12/531 | 231 | 531 |  |
| 16 | `bitmap_data_thorough/floodFill` | 2.1% | 18/867 | 375 | 867 |  |
| 17 | `bitmap_data_thorough/pixelDissolve` | 2.0% | 28/1371 | 573 | 1371 |  |
| 18 | `bitmap_data_thorough/copyPixels` | 1.9% | 23/1203 | 492 | 1203 |  |
| 19 | `bitmap_data_thorough/merge` | 1.9% | 23/1203 | 510 | 1203 |  |
| 20 | `bitmap_data_thorough/noise` | 1.9% | 29/1518 | 654 | 1518 |  |
| 21 | `bitmap_data_thorough/paletteMap` | 1.9% | 18/951 | 402 | 951 |  |
| 22 | `bitmap_data_thorough/copyChannel` | 1.8% | 49/2715 | 1131 | 2715 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) | 16 | 16 | 0 |
| 6 | [BITMAP_FILTER_CLONE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTER_CLONE_PLAN.md) | 0 | 0 | 0 |
| 7 | [BITMAP_FILTERS_MCFILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_MCFILTERS_PLAN.md) | 0 | 0 | 0 |
| 8 | [BITMAP_FILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_PLAN.md) | 0 | 0 | 0 |
| 9 | [BITMAPDATA_APPLYFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_APPLYFILTER_PLAN.md) | 0 | 0 | 0 |
| 10 | [BITMAPDATA_PERLINNOISE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PERLINNOISE_PLAN.md) | 0 | 0 | 0 |
| 11 | [BITMAPDATA_PIXELDISSOLVE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PIXELDISSOLVE_PLAN.md) | 0 | 0 | 0 |
| 12 | [BITMAPDATA_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) | 6 | 6 | 0 |
| 13 | [BUTTON_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) | 14 | 14 | 0 |
| 14 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 15 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) | 8 | 8 | 0 |
| 16 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 4 | 0 |
| 17 | [COLOR_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 18 | [CONSTRUCT_PARAMETER_REPLAY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) | 1 | 1 | 0 |
| 19 | [COPYPIXELS_ALPHA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COPYPIXELS_ALPHA_PLAN.md) | 0 | 0 | 0 |
| 20 | [CREATETEXTFIELD_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 21 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 1 | 1 | 0 |
| 22 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 23 | [DATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) | 0 | 0 | 0 |
| 24 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 25 | [DEVICE_FONT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) | 2 | 2 | 0 |
| 26 | [DISPLACEMENTMAPFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) | 1 | 1 | 0 |
| 27 | [DRAG_DROP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 28 | [DRAWING_API_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) | 4 | 4 | 0 |
| 29 | [EDITTEXT_DRAG_SELECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) | 1 | 1 | 0 |
| 30 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 31 | [ENUMERATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) | 13 | 13 | 0 |
| 32 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 33 | [FILLRECT_COLOR_CONSTANT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FILLRECT_COLOR_CONSTANT_PLAN.md) | 0 | 0 | 0 |
| 34 | [FLASH_CORRECT_REGRESSIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) | 1 | 1 | 0 |
| 35 | [FLV_PLAYBACK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) | 2 | 2 | 0 |
| 36 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 4 | 0 |
| 37 | [FOCUS_RECT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 38 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 7 | 0 |
| 39 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 40 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 1 | 2 |
| 41 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 6 | 6 | 0 |
| 42 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 43 | [GLOBALS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) | 26 | 26 | 0 |
| 44 | [HIT_TESTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) | 16 | 16 | 0 |
| 45 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 8 | 8 | 0 |
| 46 | [infinite_recursion_function.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 47 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 48 | [issue_768.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 49 | [LOADBITMAP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADBITMAP_PLAN.md) | 0 | 0 | 0 |
| 50 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 51 | [LOADMOVIE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) | 44 | 44 | 0 |
| 52 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) | 4 | 4 | 0 |
| 53 | [LOADVARIABLES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) | 3 | 3 | 0 |
| 54 | [LOCALCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/LOCALCONNECTION_PLAN.md) | 0 | 0 | 0 |
| 55 | [LOCKROOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 56 | [MATH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 57 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 58 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 59 | [MOVIECLIP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) | 55 | 55 | 0 |
| 60 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 14 | 14 | 0 |
| 61 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 14 | 14 | 0 |
| 62 | [NATIVE_OBJECTS_UPDATED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) | 2 | 2 | 0 |
| 63 | [NETCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) | 1 | 1 | 0 |
| 64 | [object_string_coerce.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 65 | [OBJECT_WATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) | 3 | 3 | 0 |
| 66 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 67 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 68 | [PIXEL_TEXT_LAYOUT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) | 3 | 3 | 0 |
| 69 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 70 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 71 | [REGISTERCLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) | 15 | 15 | 0 |
| 72 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 2 | 2 | 0 |
| 73 | [RUNTIME_CXFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 74 | [RUNTIME_SETMASK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) | 3 | 3 | 0 |
| 75 | [RUNTIME_TRANSFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 76 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 77 | [SELECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) | 4 | 4 | 0 |
| 78 | [SOUND_CLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 79 | [SOUND_DURATION_POSITION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) | 1 | 1 | 0 |
| 80 | [SOUND_ID3_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) | 2 | 2 | 0 |
| 81 | [SOUND_LOADING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) | 2 | 2 | 0 |
| 82 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 83 | [STAGE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 84 | [string_coercion.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 85 | [STRING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) | 12 | 12 | 0 |
| 86 | [STYLESHEET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 87 | [SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) | 2 | 2 | 0 |
| 88 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 5 | 0 |
| 89 | [TAB_ORDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 16 | 0 |
| 90 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 1 | 0 |
| 91 | [TELLTARGET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) | 17 | 17 | 0 |
| 92 | [TEXTFIELD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) | 70 | 70 | 0 |
| 93 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 94 | [THIS_BINDING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 95 | [this_swf7.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 96 | [TIMER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) | 3 | 3 | 0 |
| 97 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 98 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 2 | 0 |
| 99 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 13 | 13 | 0 |
| 100 | [UNLOAD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) | 12 | 12 | 0 |
| 101 | [VECTOR_PATH_HITTEST_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/VECTOR_PATH_HITTEST_PLAN.md) | 0 | 0 | 0 |
| 102 | [WITH_SCOPE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 103 | [XML_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) | 28 | 28 | 0 |
| | *(tests not in any document)* | 165 | 144 | 21 |
