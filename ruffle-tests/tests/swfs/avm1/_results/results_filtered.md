# Ruffle Test Results (Filtered)

**Date**: 2026-04-17 17:11 UTC

**Git SHA**: `1ff61eebf4`

**Run Duration**: 2m 36s

**Filtered**: 40 tests ignored out of 641 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 601 |
| Passing | **579** (96.3%) |
| Failing | 22 |
| Total expected lines | 96461 |
| Matching lines | 74807 (77.6%) |
| Mismatched lines | 21654 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 21 | 95.5% |
| Compile Fail | 1 | 4.5% |

## Passing Tests

**579 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 0.4s |  |
| 2 | `action_to_integer` | 28 | 0.1s |  |
| 3 | `add` | 28 | 0.1s |  |
| 4 | `add2` | 354 | 0.1s | [1](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 0.1s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 0.1s |  |
| 7 | `add_swf5` | 28 | 0.1s |  |
| 8 | `arguments` | 127 | 0.1s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 0.1s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 0.1s |  |
| 11 | `array_constructor` | 30 | 0.1s |  |
| 12 | `array_enumerate` | 4 | 0.1s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 0.1s |  |
| 14 | `array_properties` | 36 | 0.1s |  |
| 15 | `array_prototyping` | 12 | 0.1s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 0.1s |  |
| 17 | `array_sort` | 161 | 0.1s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 0.1s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 0.1s |  |
| 20 | `array_trivial` | 209 | 0.1s |  |
| 21 | `as1_constructor_v6` | 35 | 0.1s |  |
| 22 | `as1_constructor_v7` | 35 | 0.1s |  |
| 23 | `as2_oop` | 13 | 0.5s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 0.2s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 0.2s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 0.2s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 0.1s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 0.1s |  |
| 29 | `as_broadcaster_undef` | 89 | 0.1s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 0.1s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 0.1s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 0.2s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 0.2s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 0.2s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 0.2s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 0.2s |  |
| 37 | `as_transformed_flag` | 20 | 0.2s |  |
| 38 | `asfunction` | 11 | 0.1s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) |
| 39 | `asnative` | 34 | 0.1s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `asnew` | 34 | 0.2s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 41 | `attach_movie` | 59 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 42 | `attach_movie_stop` | 3 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 43 | `bad_placeobject_clipaction` | 2 | 0.1s |  |
| 44 | `bad_swf_tag_past_eof` | 0 | 0.1s |  |
| 45 | `bitand` | 1058 | 0.2s |  |
| 46 | `bitmap_data` | 1126 | 0.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 47 | `bitmap_data_colortransform` | 0 | 0.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 48 | `bitmap_data_compare` | 40 | 0.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 49 | `bitmap_data_copypixels` | 17 | 0.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 50 | `bitmap_data_draw_cliprect` | 13 | 0.1s |  |
| 51 | `bitmap_data_fillrect` | 0 | 0.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 52 | `bitmap_data_hittest` | 132 | 0.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 53 | `bitmap_data_max_size_swf10` | 12 | 0.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 54 | `bitmap_data_max_size_swf9` | 10 | 0.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 55 | `bitmap_data_noise` | 631 | 0.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 56 | `bitmap_data_perlinnoise` | 0 | 0.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 57 | `bitmap_data_pixeldissolve` | 1075 | 0.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 58 | `bitmap_data_pixeldissolve_image` | 0 | 0.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 59 | `bitmap_data_threshold` | 176 | 0.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 60 | `bitmapdata_applyfilter_colormatrix` | 0 | 0.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 61 | `bitmapdata_channels` | 19 | 0.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 62 | `bitor` | 1058 | 0.1s |  |
| 63 | `biturshift` | 14 | 0.1s |  |
| 64 | `biturshift_swf8` | 14 | 0.1s |  |
| 65 | `bitxor` | 1058 | 0.1s |  |
| 66 | `boxed_primitives` | 24 | 0.1s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 67 | `button_children` | 8 | 0.1s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `button_goto` | 4 | 0.3s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 69 | `button_key_events` | 14 | 0.2s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 70 | `button_key_events_special` | 45 | 0.7s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 71 | `button_keypress` | 3 | 0.2s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 72 | `button_keypress_vs_press` | 25 | 0.2s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 73 | `button_keypress_vs_tab` | 20 | 0.2s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 74 | `button_keypress_vs_textinput` | 4 | 0.2s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 75 | `button_order` | 2 | 0.1s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 76 | `button_properties_special_cases` | 22 | 0.2s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 77 | `button_v5` | 18 | 0.1s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 78 | `button_v6` | 18 | 0.1s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 79 | `call` | 63 | 0.2s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 80 | `call_method_empty_name` | 1 | 0.1s |  |
| 81 | `capabilities_resolution` | 8 | 0.1s |  |
| 82 | `catch_references_registers` | 2 | 0.1s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 83 | `click_block` | 5 | 0.1s | [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 84 | `clip_constructors` | 8 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 85 | `clip_event_propagation_order` | 17 | 0.2s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 86 | `clip_events` | 19 | 0.2s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 87 | `clone_sprite_edittext` | 94 | 0.1s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 88 | `clone_sprite_edittext_dynamic` | 86 | 0.1s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 89 | `clone_sprite_types` | 24 | 0.1s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 90 | `closure_scope` | 7 | 0.2s | [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 91 | `coerce_to_object_monkeypatch` | 129 | 0.2s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 92 | `coerce_to_primitive_resolve` | 17 | 0.1s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 93 | `color` | 57 | 0.2s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 94 | `color_transform` | 48 | 0.1s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 95 | `conflicting_instance_names` | 23 | 0.2s |  |
| 96 | `constructor_function` | 2 | 0.1s |  |
| 97 | `context_menu` | 39 | 0.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 98 | `context_menu_item` | 41 | 0.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 99 | `create_empty_movie_clip` | 3 | 0.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 100 | `cross_movie_root` | 10 | 0.2s | [52](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 101 | `custom_clip_methods` | 4 | 0.1s | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 102 | `default_names` | 52 | 0.1s | [25](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 103 | `define_function2` | 8 | 0.1s |  |
| 104 | `define_function2_preload` | 13 | 0.1s |  |
| 105 | `define_function2_preload_order` | 4 | 0.1s |  |
| 106 | `define_function_case_sensitive` | 2 | 0.1s |  |
| 107 | `define_local` | 27 | 0.1s | [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 108 | `define_local_with_paths` | 54 | 0.1s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 109 | `delete` | 3 | 0.1s |  |
| 110 | `device_font_spacing` | 91 | 0.4s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 111 | `displacementmapfilter_mappoint_throw_error` | 13 | 0.1s | [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 112 | `display_object_properties` | 2 | 0.2s | [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 113 | `divide_swf4` | 107 | 0.1s |  |
| 114 | `do_init_action` | 3 | 0.2s |  |
| 115 | `do_init_action_child` | 12 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 116 | `drag_drop` | 10 | 0.2s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 117 | `drag_over_from_outside` | 1 | 0.2s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 118 | `drag_over_without_startdrag` | 1 | 0.1s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 119 | `duplicate_movie_clip` | 20 | 0.2s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 120 | `duplicate_movie_clip_drawing` | 2 | 0.1s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 121 | `edittext_align` | 60 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 122 | `edittext_align_trailing_spaces_swf7` | 576 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 123 | `edittext_align_trailing_spaces_swf8` | 576 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 124 | `edittext_antialiastype` | 296 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 125 | `edittext_autosize` | 71 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 126 | `edittext_autosize_setter` | 20 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 127 | `edittext_bullet` | 30 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 128 | `edittext_default_format` | 221 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 129 | `edittext_default_format_empty` | 100 | 0.1s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 130 | `edittext_default_format_font_style` | 335 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 131 | `edittext_drag_select` | 9 | 0.1s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 132 | `edittext_focus_selection` | 2 | 0.2s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 133 | `edittext_font_size` | 45 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 134 | `edittext_hscroll` | 27 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 135 | `edittext_html_align_swf7` | 52 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 136 | `edittext_html_align_swf8` | 52 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 137 | `edittext_html_color` | 114 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 138 | `edittext_html_condensewhite_swf7` | 311 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 139 | `edittext_html_condensewhite_swf8` | 311 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 140 | `edittext_html_entity` | 4 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 141 | `edittext_html_roundtrip` | 17 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 142 | `edittext_html_swf6` | 5377 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 143 | `edittext_html_swf7` | 5377 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 144 | `edittext_html_swf8` | 5377 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 145 | `edittext_ime_focus_lost` | 7 | 0.1s | [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 146 | `edittext_input` | 1 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 147 | `edittext_input_newlines` | 9 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 148 | `edittext_leading` | 9 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 149 | `edittext_letter_spacing` | 15 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 150 | `edittext_margins` | 25 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 151 | `edittext_newline_stripping` | 64 | 6.0s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 152 | `edittext_newlines` | 30 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 153 | `edittext_password` | 5 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 154 | `edittext_password_copy` | 4 | 0.4s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 155 | `edittext_paste_empty` | 2 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 156 | `edittext_place_caret` | 2 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 157 | `edittext_programmatic_focus` | 12 | 0.1s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 158 | `edittext_restrict` | 191 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 159 | `edittext_restrict_paste` | 5 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 160 | `edittext_scroll` | 54 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 161 | `edittext_stylesheet` | 325 | 0.1s | [21](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [27](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 162 | `edittext_tab_focus` | 13 | 0.1s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 163 | `edittext_tab_stops` | 60 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 164 | `edittext_tag_indent` | 31 | 0.1s | [21](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [27](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 165 | `edittext_text_height_leading` | 20 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 166 | `edittext_underline` | 40 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 167 | `edittext_width_height` | 103 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 168 | `empty_movieclip_can_attach_movies` | 11 | 0.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 169 | `enumerate` | 64 | 0.1s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 170 | `equals` | 32 | 0.1s |  |
| 171 | `equals2_swf5` | 926 | 0.1s |  |
| 172 | `equals2_swf6` | 926 | 0.1s |  |
| 173 | `equals2_swf7` | 926 | 0.1s |  |
| 174 | `equals_swf4` | 665 | 0.1s |  |
| 175 | `equals_swf4_alt` | 32 | 0.5s |  |
| 176 | `equals_swf5` | 32 | 0.2s |  |
| 177 | `error` | 58 | 0.1s |  |
| 178 | `escape` | 14 | 0.1s |  |
| 179 | `execution_order1` | 5 | 0.2s |  |
| 180 | `execution_order2` | 7 | 0.2s |  |
| 181 | `execution_order3` | 4 | 0.2s |  |
| 182 | `execution_order4` | 12 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 183 | `export_assets` | 3 | 0.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 184 | `extends_chain` | 134 | 0.2s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 185 | `extends_native_type` | 11 | 0.1s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 186 | `external_interface` | 84 | 0.1s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 187 | `external_interface_escapexml` | 26 | 0.1s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 188 | `external_interface_jsquotestring` | 21 | 0.1s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 189 | `external_interface_toas_basic` | 354 | 0.1s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 190 | `external_interface_toxml_array` | 25 | 0.1s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 191 | `external_interface_toxml_basic` | 179 | 0.2s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 192 | `external_interface_unescapexml` | 40 | 0.1s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 193 | `focus_keyboard_press` | 60 | 0.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 194 | `focus_mouse` | 45 | 0.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 195 | `focus_mouse_focusable` | 8 | 0.1s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 196 | `focus_mouse_rollout` | 4 | 0.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 197 | `focus_remove` | 33 | 0.1s |  |
| 198 | `focus_root_movie` | 2 | 0.1s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 199 | `focus_visibility_change` | 45 | 0.1s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 200 | `focusrect_focuslost` | 4 | 0.2s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 201 | `focusrect_mouse_swf8` | 0 | 0.2s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 202 | `focusrect_mouse_swf9` | 0 | 0.2s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 203 | `focusrect_property_swf5` | 1237 | 0.2s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 204 | `focusrect_property_swf6` | 1237 | 0.2s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 205 | `focusrect_property_swf7` | 1237 | 0.2s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 206 | `focusrect_swf5` | 6 | 0.2s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 207 | `focusrect_swf6` | 42 | 0.2s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 208 | `form_loader_encoding_1` | 1 | 0.1s |  |
| 209 | `frame_size_translated_negative` | 21 | 0.2s | [21](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 210 | `frame_size_translated_positive` | 21 | 0.1s | [21](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 211 | `function_base_clip` | 8 | 0.1s |  |
| 212 | `function_base_clip_readded` | 11 | 0.1s |  |
| 213 | `function_base_clip_removed` | 25 | 0.1s |  |
| 214 | `function_suppress_and_preload` | 28 | 0.1s |  |
| 215 | `funky_function_calls` | 56 | 0.1s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 216 | `get_bytes_total` | 4 | 0.1s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 217 | `get_variable_in_scope` | 29 | 0.1s |  |
| 218 | `getproperty` | 28 | 0.1s |  |
| 219 | `getproperty_swf4` | 28 | 0.1s |  |
| 220 | `getproperty_swf5` | 28 | 0.1s |  |
| 221 | `gettextextent` | 56 | 0.1s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 222 | `global_array` | 3 | 0.1s |  |
| 223 | `global_is_bare` | 7 | 0.1s |  |
| 224 | `global_swf5_6_7_8_9` | 1145 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 225 | `global_swf6_7_8` | 15 | 0.5s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 226 | `globals_swf6` | 304 | 0.1s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 227 | `globals_swf7` | 304 | 0.1s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 228 | `globals_swf8` | 304 | 0.1s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 229 | `goto_advance1` | 6 | 0.2s |  |
| 230 | `goto_advance2` | 2 | 0.1s |  |
| 231 | `goto_both_ways1` | 3 | 0.2s |  |
| 232 | `goto_both_ways2` | 3 | 0.2s |  |
| 233 | `goto_execution_order` | 2 | 0.1s |  |
| 234 | `goto_execution_order2` | 2 | 0.1s |  |
| 235 | `goto_frame` | 12 | 0.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 236 | `goto_frame2` | 44 | 0.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 237 | `goto_frame_number` | 3 | 0.2s |  |
| 238 | `goto_label` | 17 | 0.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 239 | `goto_methods` | 40 | 0.1s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 240 | `goto_rewind1` | 1 | 0.1s |  |
| 241 | `goto_rewind2` | 3 | 0.2s |  |
| 242 | `goto_rewind3` | 2 | 0.2s |  |
| 243 | `greater_swf6` | 1175 | 0.2s |  |
| 244 | `greater_swf7` | 1175 | 0.2s |  |
| 245 | `greaterthan_swf5` | 1 | 0.2s |  |
| 246 | `greaterthan_swf8` | 1 | 0.1s |  |
| 247 | `has_own_property` | 32 | 0.1s |  |
| 248 | `hittest_lockroot` | 15 | 0.1s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 249 | `hittest_morph` | 70 | 0.1s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 250 | `hittest_morph_input` | 1 | 0.1s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 251 | `hittest_winding_rule` | 12 | 0.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 252 | `infinite_recursion_function` | 4 | 0.1s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 253 | `infinite_recursion_function_in_setter` | 131 | 0.1s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 254 | `infinite_recursion_virtual_property` | 67 | 0.1s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 255 | `init_array_invalid` | 4 | 0.1s |  |
| 256 | `init_object_invalid` | 4 | 0.1s |  |
| 257 | `init_object_order` | 15 | 0.1s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 258 | `input_dead_keys_windows` | 15 | 0.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 259 | `instanceof_coercions` | 88 | 0.2s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 260 | `interface_implements_op` | 47 | 0.2s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 261 | `is_finite` | 49 | 0.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 262 | `is_finite_swf6` | 49 | 0.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 263 | `is_prototype_of` | 89 | 0.1s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 264 | `issue_1086` | 1 | 0.1s |  |
| 265 | `issue_1104` | 2 | 0.1s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 266 | `issue_1671` | 0 | 0.3s |  |
| 267 | `issue_1906` | 4 | 0.1s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 268 | `issue_2030` | 4 | 0.1s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 269 | `issue_2084` | 16 | 0.2s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 270 | `issue_2166` | 9 | 0.1s |  |
| 271 | `issue_2870` | 3 | 0.2s | [52](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 272 | `issue_3169` | 2 | 0.1s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 273 | `issue_3446` | 1 | 0.1s |  |
| 274 | `issue_3522` | 2 | 0.1s |  |
| 275 | `issue_4377` | 2 | 0.1s |  |
| 276 | `issue_710` | 4 | 0.1s |  |
| 277 | `issue_768` | 3 | 0.1s | [50](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) |
| 278 | `issue_9327` | 2 | 0.1s |  |
| 279 | `issue_9885` | 2 | 0.1s |  |
| 280 | `key_isToggled` | 9 | 0.1s |  |
| 281 | `lessthan` | 41 | 0.1s |  |
| 282 | `lessthan2_swf5` | 1226 | 0.1s |  |
| 283 | `lessthan2_swf6` | 1226 | 0.1s |  |
| 284 | `lessthan2_swf7` | 1226 | 0.1s |  |
| 285 | `lessthan_swf4` | 902 | 0.1s |  |
| 286 | `lessthan_swf4_alt` | 41 | 0.1s |  |
| 287 | `lessthan_swf5` | 41 | 0.4s |  |
| 288 | `loadmovie` | 2 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 289 | `loadmovie_fail` | 2 | 0.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 290 | `loadmovie_flashvars` | 4 | 0.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 291 | `loadmovie_method` | 2 | 0.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 292 | `loadmovie_registerclass` | 30 | 0.2s | [22](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 293 | `loadmovie_replace_root` | 5 | 0.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 294 | `loadmovie_var_persistence` | 8 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) |
| 295 | `loadmovienum` | 3 | 0.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 296 | `loadmovienum_cross_version_prototype` | 9 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) |
| 297 | `loadvariables` | 2 | 0.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 298 | `loadvariables2` | 8 | 0.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 299 | `loadvariablesnum` | 2 | 0.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 300 | `local_to_global` | 49 | 0.1s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 301 | `localconnection_properties` | 8 | 0.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 302 | `lock_root` | 1 | 0.1s |  |
| 303 | `logical_ops_swf4` | 90 | 0.1s |  |
| 304 | `logical_ops_swf8` | 108 | 0.1s |  |
| 305 | `looping` | 6 | 0.2s |  |
| 306 | `mask_reapply` | 0 | 0.1s | [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 307 | `mask_with_drawing` | 0 | 0.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 308 | `math_min_max` | 101 | 0.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 309 | `math_swf6` | 530 | 0.1s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 310 | `math_swf7` | 530 | 0.1s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 311 | `math_swf8` | 530 | 0.1s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 312 | `matrix` | 171 | 0.1s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 313 | `mcl_as_broadcaster` | 12 | 0.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 314 | `mcl_events_swf_version` | 232 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 315 | `mcl_getprogress` | 30 | 0.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 316 | `mcl_loadclip` | 149 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 317 | `mcl_loadclip_properties` | 6 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 318 | `mcl_loadclip_replace_root` | 1 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 319 | `mcl_mislabeled_target` | 6 | 0.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 320 | `mcl_target_gif87a` | 6 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 321 | `mcl_target_gif89a` | 6 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 322 | `mcl_target_jpg` | 6 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 323 | `mcl_target_png` | 6 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 324 | `mcl_unloadclip` | 5 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 325 | `mouse_events` | 8 | 0.1s | [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 326 | `mouse_events_visible_enabled` | 12 | 0.2s | [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 327 | `mouse_hover_events_while_dragging` | 1 | 0.1s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 328 | `mouse_listeners` | 67 | 0.1s |  |
| 329 | `mouse_pos` | 665 | 0.1s | [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 330 | `mouse_pos_with_scale_factor` | 260 | 0.1s | [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 331 | `mouse_wheel_enabled` | 2 | 0.1s |  |
| 332 | `movieclip_begin_gradient_fill` | 0 | 0.2s | [30](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 333 | `movieclip_blend_mode_property` | 35 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 334 | `movieclip_create_text_field` | 90 | 0.1s | [21](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 335 | `movieclip_default_state` | 69 | 0.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 336 | `movieclip_depth_methods` | 98 | 0.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 337 | `movieclip_focusenabled` | 99 | 0.1s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 338 | `movieclip_get_instance_at_depth` | 28 | 0.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 339 | `movieclip_getbounds` | 191 | 0.1s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 340 | `movieclip_gettextsnapshot` | 112 | 0.1s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 341 | `movieclip_hittest` | 92 | 0.1s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 342 | `movieclip_in_removed_button` | 4 | 0.1s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 343 | `movieclip_init_object` | 5 | 0.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 344 | `movieclip_invalid_get_bounds_1` | 75 | 0.6s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 345 | `movieclip_invalid_get_bounds_2` | 75 | 0.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 346 | `movieclip_invalid_get_bounds_3` | 13 | 0.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 347 | `movieclip_invalid_get_bounds_4` | 13 | 0.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 348 | `movieclip_invalid_get_bounds_5` | 11 | 0.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 349 | `movieclip_invalid_get_bounds_6` | 10 | 0.7s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 350 | `movieclip_invalid_get_bounds_7` | 10 | 0.6s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 351 | `movieclip_invalid_get_bounds_8` | 11 | 0.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 352 | `movieclip_line_gradient_style` | 0 | 0.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 353 | `movieclip_lockroot` | 29 | 0.1s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 354 | `movieclip_methods_with_loaded_image` | 4 | 0.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 355 | `movieclip_name_from_timeline` | 13 | 0.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 356 | `movieclip_prototype_extension` | 5 | 0.1s |  |
| 357 | `movieclip_setmask` | 14 | 0.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 358 | `movieclip_state_values` | 114 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 359 | `moviecliploader_flashvars` | 4 | 0.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 360 | `mutable_this` | 18 | 0.1s | [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 361 | `named_shapes` | 14 | 0.1s |  |
| 362 | `nan_scale` | 9 | 0.1s |  |
| 363 | `native_double_construct` | 12 | 0.1s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 364 | `native_objects_swf7` | 115 | 1.5s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 365 | `native_objects_swf8` | 115 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 366 | `native_subclasses` | 191 | 0.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 367 | `nested_textfields_in_buttons` | 0 | 0.1s |  |
| 368 | `netconnection_close` | 39 | 0.1s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) |
| 369 | `netstream_play_flv` | 21 | 0.2s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 370 | `netstream_seek_flv` | 25 | 0.1s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 371 | `new_method_wrap` | 4 | 0.1s |  |
| 372 | `new_object_enumerate` | 7 | 0.3s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 373 | `new_object_wrap` | 4 | 0.1s |  |
| 374 | `o` | 3 | 0.1s |  |
| 375 | `object_constructor` | 33 | 0.1s |  |
| 376 | `object_function` | 32 | 0.1s |  |
| 377 | `object_properties` | 31 | 0.1s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 378 | `object_prototypes` | 74 | 0.1s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 379 | `object_resolve` | 38 | 0.1s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 380 | `object_string_coerce_swf5` | 62 | 0.1s | [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 381 | `object_string_coerce_swf6` | 68 | 0.1s | [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 382 | `on_construct` | 25 | 0.2s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [19](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 383 | `parse_float` | 74 | 0.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 384 | `parse_int` | 64 | 0.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 385 | `path_string` | 322 | 0.1s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 386 | `place_and_lookup` | 30 | 0.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 387 | `placeobject_occupied_depth` | 6 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 388 | `point` | 175 | 0.1s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 389 | `primitive_instanceof` | 37 | 0.1s |  |
| 390 | `primitive_type_globals` | 557 | 0.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 391 | `printjob_props_swf5` | 45 | 0.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 392 | `printjob_props_swf6` | 45 | 0.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 393 | `printjob_props_swf7` | 45 | 0.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 394 | `property_invalid_base_clip` | 36 | 0.1s |  |
| 395 | `prototype_delete` | 12 | 0.1s |  |
| 396 | `prototype_enumerate` | 5 | 0.1s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 397 | `prototype_properties` | 17 | 0.1s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 398 | `rectangle` | 745 | 0.1s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 399 | `recursive_prototypes` | 0 | 0.1s |  |
| 400 | `register_and_init_order` | 231 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 401 | `register_class` | 66 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 402 | `register_class_return_value` | 16 | 0.1s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 403 | `register_class_swf6` | 37 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 404 | `register_class_with_sound` | 11 | 0.2s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 405 | `register_globals_across_frames` | 15 | 0.1s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 406 | `register_underflow` | 26 | 0.1s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 407 | `remove_movie_clip` | 29 | 0.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 408 | `removed_clip_halts_script` | 15 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 409 | `removed_target_clip_scope` | 35 | 0.1s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 410 | `resolve_different_root` | 2 | 0.1s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 411 | `rewind_depth` | 30 | 0.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 412 | `root_button_mode` | 10 | 0.1s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 413 | `root_global_parent` | 6 | 0.1s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 414 | `root_onload` | 1 | 0.1s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 415 | `sandbox_type_local_file` | 1 | 0.1s |  |
| 416 | `sandbox_type_local_network` | 1 | 0.1s |  |
| 417 | `selection` | 454 | 0.1s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 418 | `selection_handlers` | 27 | 0.1s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 419 | `set_interval` | 27 | 0.1s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 420 | `set_variable_scope` | 58 | 0.1s |  |
| 421 | `single_frame` | 1 | 0.1s |  |
| 422 | `slash_syntax` | 14 | 0.4s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 423 | `sound` | 628 | 0.1s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 424 | `sound_duration_position_props` | 290 | 0.1s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) |
| 425 | `sound_id3` | 633 | 0.1s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) |
| 426 | `sound_id3_prop` | 138 | 0.1s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) |
| 427 | `sound_load_start` | 3 | 0.1s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) |
| 428 | `sound_multiple_load` | 1 | 0.1s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) |
| 429 | `sound_props_swf5` | 68 | 0.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 430 | `sound_props_swf6` | 68 | 0.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 431 | `sound_start_load` | 0 | 0.1s |  |
| 432 | `stage_display_state` | 16 | 0.1s | [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 433 | `stage_object_children` | 83 | 0.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 434 | `stage_object_enumerate` | 4 | 0.1s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 435 | `stage_object_properties` | 241 | 0.2s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 436 | `stage_object_properties_get_var` | 5 | 0.1s |  |
| 437 | `stage_object_properties_swf6` | 231 | 0.1s | [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 438 | `stage_property_representation` | 586 | 0.1s | [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 439 | `stage_scale_mode` | 39 | 0.1s | [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 440 | `strictequals_swf6` | 902 | 0.1s |  |
| 441 | `strictly_equals` | 7 | 0.1s |  |
| 442 | `string_coercion` | 117 | 0.1s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) |
| 443 | `string_methods` | 285 | 0.5s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 444 | `string_methods_negative_args` | 240 | 0.2s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 445 | `string_methods_swfv5` | 275 | 0.1s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 446 | `string_ops_swf6` | 95 | 0.1s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 447 | `string_paths_basic` | 4 | 0.1s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 448 | `string_paths_eval` | 4 | 0.1s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 449 | `string_paths_eval2` | 7 | 0.2s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 450 | `string_paths_hidden` | 54 | 0.1s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 451 | `string_paths_keyevents` | 0 | 0.1s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 452 | `string_paths_other` | 36 | 0.1s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 453 | `string_paths_timer` | 0 | 0.2s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 454 | `string_paths_unload` | 1 | 0.2s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 455 | `string_paths_variable_alias` | 4 | 0.1s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 456 | `string_paths_variable_scopes` | 5 | 0.1s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 457 | `stylesheet` | 283 | 0.2s |  |
| 458 | `stylesheet_transform` | 750 | 0.2s |  |
| 459 | `super_edge_cases` | 39 | 0.2s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 460 | `swf4_actions_bool` | 96 | 0.1s |  |
| 461 | `swf4_actions_coercion_order` | 158 | 0.2s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 462 | `swf4_bool` | 4 | 0.1s |  |
| 463 | `swf4_function_calls` | 7 | 0.1s |  |
| 464 | `swf5_encoding` | 3 | 0.1s |  |
| 465 | `swf5_global_funcs` | 232 | 0.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 466 | `swf5_no_closure` | 19 | 0.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 467 | `swf5_to_6_cross_call` | 29 | 0.2s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 468 | `swf5_xml_event_handler_context` | 2 | 0.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 469 | `swf6_case_insensitive` | 42 | 0.1s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 470 | `swf6_global_funcs` | 232 | 0.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 471 | `swf6_string_as_bool` | 15 | 0.1s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 472 | `swf6_to_5_cross_call` | 29 | 0.1s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 473 | `swf7_case_sensitive` | 44 | 0.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 474 | `swf7_global_funcs` | 232 | 0.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 475 | `tab_ordering_automatic_basic` | 92 | 0.1s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 476 | `tab_ordering_automatic_order_grid` | 21 | 0.1s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 477 | `tab_ordering_automatic_order_same_position` | 12 | 0.1s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 478 | `tab_ordering_children` | 208 | 0.1s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 479 | `tab_ordering_custom_basic` | 71 | 0.1s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 480 | `tab_ordering_custom_duplicate_index` | 22 | 0.1s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 481 | `tab_ordering_custom_i32_vs_u32` | 12 | 0.1s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 482 | `tab_ordering_custom_m1` | 29 | 0.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 483 | `tab_ordering_events` | 150 | 0.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 484 | `tab_ordering_events_mouse` | 65 | 0.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 485 | `tab_ordering_movieclip_enabled_default` | 462 | 0.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 486 | `tab_ordering_properties` | 293 | 0.2s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 487 | `tab_ordering_reverse` | 51 | 0.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 488 | `tab_ordering_tabbable` | 47 | 0.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 489 | `target_clip_removed` | 5 | 0.2s | [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 490 | `target_clip_swf5` | 2 | 0.2s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 491 | `target_clip_swf6` | 2 | 0.1s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 492 | `target_path` | 14 | 0.1s |  |
| 493 | `tell_target` | 37 | 0.2s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 494 | `tell_target_invalid` | 6 | 0.2s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 495 | `tell_target_invalid_swf6` | 5 | 0.2s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 496 | `text_blocks_clicks` | 4 | 0.1s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 497 | `text_format` | 1146 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 498 | `text_format_display` | 21 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 499 | `text_format_font_max_length` | 2 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 500 | `text_format_get_text_extent_undefined_width` | 10 | 0.1s |  |
| 501 | `text_format_rounding_swf7` | 840 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 502 | `text_format_rounding_swf8` | 840 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 503 | `textfield_background_color` | 11 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 504 | `textfield_border_color` | 11 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 505 | `textfield_cache_as_bitmap` | 1 | 0.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 506 | `textfield_maxchars` | 3 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 507 | `textfield_properties` | 44 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 508 | `textfield_props_swf5` | 175 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 509 | `textfield_props_swf6` | 210 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 510 | `textfield_props_swf7` | 210 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 511 | `textfield_props_swf8` | 210 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 512 | `textfield_text` | 7 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 513 | `textfield_variable` | 81 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 514 | `textsnapshot_available_text` | 20 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 515 | `textsnapshot_findtext` | 44 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 516 | `textsnapshot_gettext` | 55 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 517 | `textsnapshot_props_swf5` | 56 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 518 | `textsnapshot_props_swf6` | 56 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 519 | `textsnapshot_text_order` | 1 | 0.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 520 | `this_scoping` | 52 | 0.1s | [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 521 | `this_swf5` | 41 | 0.1s | [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 522 | `this_swf6` | 41 | 0.1s | [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 523 | `this_swf7` | 41 | 0.4s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) |
| 524 | `timeline_function_def` | 7 | 0.1s |  |
| 525 | `timeout` | 0 | 5.1s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 526 | `timer_run_actions` | 18 | 0.1s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 527 | `trace` | 8 | 0.1s |  |
| 528 | `transform` | 70 | 0.1s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 529 | `try_catch_finally` | 118 | 0.1s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 530 | `try_finally_simple` | 16 | 0.1s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 531 | `typeof` | 22 | 0.1s |  |
| 532 | `typeof_globals` | 7 | 0.1s |  |
| 533 | `uncaught_exception` | 1 | 0.1s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 534 | `uncaught_exception_bubbled` | 1 | 0.1s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 535 | `undefined_to_string_swf6` | 4 | 0.1s |  |
| 536 | `unescape` | 43 | 0.1s |  |
| 537 | `unload` | 52 | 0.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 538 | `unload_clip_event` | 4 | 0.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 539 | `unload_nested_child` | 5 | 0.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 540 | `unloadmovie` | 4 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 541 | `unloadmovie_method` | 3 | 0.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 542 | `unloadmovienum` | 13 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 543 | `use_hand_cursor` | 8 | 0.1s |  |
| 544 | `variable_args` | 5 | 0.3s |  |
| 545 | `waitforframe` | 7 | 0.1s |  |
| 546 | `waitforframe2` | 16 | 0.1s |  |
| 547 | `watch` | 117 | 0.1s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 548 | `watch_textfield` | 12 | 0.1s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 549 | `watch_virtual_property_proto` | 2 | 0.1s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 550 | `with` | 49 | 0.1s | [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 551 | `with_return` | 2 | 0.1s |  |
| 552 | `with_variable_scopes` | 43 | 0.1s | [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 553 | `xml` | 15 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 554 | `xml_append_child` | 28 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 555 | `xml_append_child_with_parent` | 20 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 556 | `xml_attributes_read` | 4 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 557 | `xml_cdata` | 11 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 558 | `xml_child_nodes_edge_cases` | 4 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 559 | `xml_clone_expandos` | 19 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 560 | `xml_first_last_child` | 8 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 561 | `xml_has_child_nodes` | 3 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 562 | `xml_idmap` | 21 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 563 | `xml_ignore_comments` | 21 | 0.4s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 564 | `xml_ignore_white` | 34 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 565 | `xml_insert_before` | 20 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 566 | `xml_inspect_createmethods` | 15 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 567 | `xml_inspect_doctype` | 7 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 568 | `xml_inspect_parsexml` | 62 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 569 | `xml_inspect_xmldecl` | 7 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 570 | `xml_load` | 2 | 0.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 571 | `xml_namespaces` | 203 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 572 | `xml_parent_and_child` | 5 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 573 | `xml_remove_node` | 22 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 574 | `xml_reparenting` | 14 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 575 | `xml_siblings` | 10 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 576 | `xml_to_string` | 13 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 577 | `xml_to_string_comment` | 1 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 578 | `xml_unescaping` | 23 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 579 | `xmlnode_proto` | 1 | 0.1s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `function_as_function` | 94.3% | 33 | 35 | 2 | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 2 | `bitmap_data_thorough/getColorBoundsRect` | 83.5% | 238 | 285 | 47 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 3 | `bitmap_data_thorough/getPixel` | 78.7% | 111 | 141 | 30 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 4 | `bitmap_data_thorough/getPixel32` | 78.7% | 111 | 141 | 30 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 5 | `bitmap_data_thorough/hitTest` | 54.9% | 285 | 519 | 234 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**21 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `function_as_function` | 94.3% | 33/35 | 35 | 35 | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 2 | `bitmap_data_thorough/getColorBoundsRect` | 83.5% | 238/285 | 285 | 285 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 3 | `bitmap_data_thorough/getPixel` | 78.7% | 111/141 | 141 | 141 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 4 | `bitmap_data_thorough/getPixel32` | 78.7% | 111/141 | 141 | 141 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 5 | `bitmap_data_thorough/hitTest` | 54.9% | 285/519 | 510 | 519 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 6 | `bitmap_data_thorough/compare` | 42.0% | 29/69 | 60 | 69 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 7 | `bitmap_data_thorough/constructor` | 6.7% | 21/313 | 163 | 313 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 8 | `bitmap_data_thorough/perlinNoise` | 5.1% | 435/8481 | 5274 | 8481 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 9 | `bitmap_data_thorough/colorTransform` | 2.9% | 8/279 | 123 | 279 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 10 | `bitmap_data_thorough/fillRect` | 2.6% | 9/342 | 150 | 342 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 11 | `bitmap_data_thorough/scroll` | 2.6% | 10/384 | 168 | 384 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 12 | `bitmap_data_thorough/threshold` | 2.4% | 31/1308 | 555 | 1308 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 13 | `bitmap_data_thorough/setPixel` | 2.3% | 12/531 | 231 | 531 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 14 | `bitmap_data_thorough/setPixel32` | 2.3% | 12/531 | 231 | 531 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 15 | `bitmap_data_thorough/floodFill` | 2.1% | 18/867 | 375 | 867 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 16 | `bitmap_data_thorough/pixelDissolve` | 2.0% | 28/1371 | 573 | 1371 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 17 | `bitmap_data_thorough/copyPixels` | 1.9% | 23/1203 | 492 | 1203 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 18 | `bitmap_data_thorough/merge` | 1.9% | 23/1203 | 510 | 1203 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 19 | `bitmap_data_thorough/noise` | 1.9% | 29/1518 | 654 | 1518 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 20 | `bitmap_data_thorough/paletteMap` | 1.9% | 18/951 | 402 | 951 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 21 | `bitmap_data_thorough/copyChannel` | 1.8% | 49/2715 | 1131 | 2715 | [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) | 16 | 16 | 0 |
| 6 | [BITMAP_DATA_THOROUGH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_DATA_THOROUGH_PLAN.md) | 20 | 0 | 20 |
| 7 | [BITMAP_FILTER_CLONE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTER_CLONE_PLAN.md) | 0 | 0 | 0 |
| 8 | [BITMAP_FILTERS_MCFILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_MCFILTERS_PLAN.md) | 0 | 0 | 0 |
| 9 | [BITMAP_FILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_PLAN.md) | 0 | 0 | 0 |
| 10 | [BITMAPDATA_APPLYFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_APPLYFILTER_PLAN.md) | 0 | 0 | 0 |
| 11 | [BITMAPDATA_PERLINNOISE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PERLINNOISE_PLAN.md) | 0 | 0 | 0 |
| 12 | [BITMAPDATA_PIXELDISSOLVE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PIXELDISSOLVE_PLAN.md) | 0 | 0 | 0 |
| 13 | [BITMAPDATA_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) | 6 | 6 | 0 |
| 14 | [BUTTON_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) | 14 | 14 | 0 |
| 15 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 16 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) | 8 | 8 | 0 |
| 17 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 4 | 0 |
| 18 | [COLOR_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 19 | [CONSTRUCT_PARAMETER_REPLAY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) | 1 | 1 | 0 |
| 20 | [COPYPIXELS_ALPHA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COPYPIXELS_ALPHA_PLAN.md) | 0 | 0 | 0 |
| 21 | [CREATETEXTFIELD_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 22 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 1 | 1 | 0 |
| 23 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 24 | [DATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) | 0 | 0 | 0 |
| 25 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 26 | [DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md) | 1 | 0 | 1 |
| 27 | [DEVICE_FONT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) | 2 | 2 | 0 |
| 28 | [DISPLACEMENTMAPFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) | 1 | 1 | 0 |
| 29 | [DRAG_DROP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 30 | [DRAWING_API_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) | 4 | 4 | 0 |
| 31 | [EDITTEXT_DRAG_SELECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) | 1 | 1 | 0 |
| 32 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 33 | [ENUMERATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) | 13 | 13 | 0 |
| 34 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 35 | [FILLRECT_COLOR_CONSTANT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FILLRECT_COLOR_CONSTANT_PLAN.md) | 0 | 0 | 0 |
| 36 | [FLASH_CORRECT_REGRESSIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) | 1 | 1 | 0 |
| 37 | [FLV_PLAYBACK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) | 2 | 2 | 0 |
| 38 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 4 | 0 |
| 39 | [FOCUS_RECT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 40 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 7 | 0 |
| 41 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 42 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 43 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 6 | 6 | 0 |
| 44 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 45 | [GLOBALS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) | 26 | 26 | 0 |
| 46 | [HIT_TESTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) | 16 | 16 | 0 |
| 47 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 8 | 8 | 0 |
| 48 | [infinite_recursion_function.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 49 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 50 | [issue_768.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 51 | [LOADBITMAP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADBITMAP_PLAN.md) | 0 | 0 | 0 |
| 52 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 53 | [LOADMOVIE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) | 44 | 44 | 0 |
| 54 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) | 4 | 4 | 0 |
| 55 | [LOADVARIABLES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) | 3 | 3 | 0 |
| 56 | [LOCALCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/LOCALCONNECTION_PLAN.md) | 0 | 0 | 0 |
| 57 | [LOCKROOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 58 | [MATH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 59 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 60 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 61 | [MOVIECLIP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) | 55 | 55 | 0 |
| 62 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 14 | 14 | 0 |
| 63 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 14 | 14 | 0 |
| 64 | [NATIVE_OBJECTS_UPDATED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) | 2 | 2 | 0 |
| 65 | [NETCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) | 1 | 1 | 0 |
| 66 | [object_string_coerce.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 67 | [OBJECT_WATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) | 3 | 3 | 0 |
| 68 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 69 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 70 | [PIXEL_TEXT_LAYOUT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) | 3 | 3 | 0 |
| 71 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 72 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 73 | [REGISTERCLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) | 15 | 15 | 0 |
| 74 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 2 | 2 | 0 |
| 75 | [RUNTIME_CXFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 76 | [RUNTIME_SETMASK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) | 3 | 3 | 0 |
| 77 | [RUNTIME_TRANSFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 78 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 79 | [SELECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) | 4 | 4 | 0 |
| 80 | [SOUND_CLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 81 | [SOUND_DURATION_POSITION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) | 1 | 1 | 0 |
| 82 | [SOUND_ID3_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) | 2 | 2 | 0 |
| 83 | [SOUND_LOADING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) | 2 | 2 | 0 |
| 84 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 85 | [STAGE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 86 | [string_coercion.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 87 | [STRING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) | 12 | 12 | 0 |
| 88 | [STYLESHEET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 89 | [SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) | 2 | 2 | 0 |
| 90 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 5 | 0 |
| 91 | [TAB_ORDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 16 | 0 |
| 92 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 1 | 0 |
| 93 | [TELLTARGET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) | 17 | 17 | 0 |
| 94 | [TEXTFIELD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) | 70 | 70 | 0 |
| 95 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 96 | [THIS_BINDING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 97 | [this_swf7.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 98 | [TIMER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) | 3 | 3 | 0 |
| 99 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 100 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 2 | 0 |
| 101 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 13 | 13 | 0 |
| 102 | [UNLOAD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) | 12 | 12 | 0 |
| 103 | [VECTOR_PATH_HITTEST_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/VECTOR_PATH_HITTEST_PLAN.md) | 0 | 0 | 0 |
| 104 | [WITH_SCOPE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 105 | [XML_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) | 28 | 28 | 0 |
| | *(tests not in any document)* | 144 | 144 | 0 |
