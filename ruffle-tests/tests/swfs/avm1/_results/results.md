# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-30 05:06 UTC

**Git SHA**: `b84c0305de`

**Run Duration**: 177m 50s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 620 |
| Passing | **563** (90.8%) |
| Failing | 57 |
| Total expected lines | 91501 |
| Matching lines | 80028 (87.5%) |
| Mismatched lines | 11473 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 55 | 96.5% |
| Runtime Segfault | 1 | 1.8% |
| Timeout | 1 | 1.8% |

## Passing Tests

**563 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 16.9s |  |
| 2 | `action_to_integer` | 28 | 16.0s |  |
| 3 | `add` | 28 | 15.9s |  |
| 4 | `add2` | 354 | 16.1s | [1](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 15.9s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 15.9s |  |
| 7 | `add_swf5` | 28 | 15.9s |  |
| 8 | `arguments` | 127 | 15.9s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 15.9s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 16.0s |  |
| 11 | `array_constructor` | 30 | 15.9s |  |
| 12 | `array_enumerate` | 4 | 15.9s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 16.1s |  |
| 14 | `array_properties` | 36 | 16.2s |  |
| 15 | `array_prototyping` | 12 | 16.1s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 16.1s |  |
| 17 | `array_sort` | 161 | 16.9s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 16.0s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 16.1s |  |
| 20 | `array_trivial` | 209 | 16.1s |  |
| 21 | `as1_constructor_v6` | 35 | 16.0s |  |
| 22 | `as1_constructor_v7` | 35 | 18.5s |  |
| 23 | `as2_oop` | 13 | 17.9s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 17.9s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 17.8s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 17.6s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 17.4s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 17.4s |  |
| 29 | `as_broadcaster_undef` | 89 | 17.6s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 17.4s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 17.3s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 17.5s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 17.5s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 17.6s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 17.5s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 17.5s |  |
| 37 | `as_transformed_flag` | 20 | 17.6s |  |
| 38 | `asnative` | 34 | 17.5s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 17.5s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 17.6s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 17.4s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 42 | `bad_placeobject_clipaction` | 2 | 16.6s |  |
| 43 | `bad_swf_tag_past_eof` | 0 | 16.4s |  |
| 44 | `bitand` | 1058 | 19.7s |  |
| 45 | `bitmap_data` | 1126 | 18.9s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 46 | `bitmap_data_colortransform` | 0 | 16.7s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [11](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) |
| 47 | `bitmap_data_compare` | 40 | 17.0s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 48 | `bitmap_data_copypixels` | 17 | 17.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [11](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) |
| 49 | `bitmap_data_draw_cliprect` | 13 | 16.6s |  |
| 50 | `bitmap_data_fillrect` | 0 | 16.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [11](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) |
| 51 | `bitmap_data_hittest` | 132 | 17.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 52 | `bitmap_data_max_size_swf10` | 12 | 16.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 53 | `bitmap_data_max_size_swf9` | 10 | 16.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 54 | `bitmap_data_noise` | 631 | 16.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 55 | `bitmap_data_perlinnoise` | 0 | 17.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [11](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) |
| 56 | `bitmap_data_pixeldissolve` | 1075 | 17.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 57 | `bitmap_data_pixeldissolve_image` | 0 | 16.8s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [11](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) |
| 58 | `bitmap_data_threshold` | 176 | 16.7s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 59 | `bitmapdata_applyfilter_colormatrix` | 0 | 16.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [11](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) |
| 60 | `bitmapdata_channels` | 19 | 16.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 61 | `bitor` | 1058 | 19.0s |  |
| 62 | `biturshift` | 14 | 16.3s |  |
| 63 | `biturshift_swf8` | 14 | 16.2s |  |
| 64 | `bitxor` | 1058 | 18.9s |  |
| 65 | `boxed_primitives` | 24 | 16.3s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 66 | `button_children` | 8 | 16.1s | [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 67 | `button_goto` | 4 | 16.1s | [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `button_key_events` | 14 | 16.4s | [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 69 | `button_key_events_special` | 45 | 17.0s | [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 70 | `button_keypress` | 3 | 16.3s | [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 71 | `button_keypress_vs_press` | 25 | 16.4s | [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 72 | `button_keypress_vs_tab` | 20 | 16.4s | [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 73 | `button_keypress_vs_textinput` | 4 | 16.3s | [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 74 | `button_order` | 2 | 16.2s | [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 75 | `button_properties_special_cases` | 22 | 16.5s | [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 76 | `button_v5` | 18 | 16.2s | [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 77 | `button_v6` | 18 | 16.1s | [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 78 | `call` | 63 | 16.3s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 79 | `call_method_empty_name` | 1 | 16.0s |  |
| 80 | `capabilities_resolution` | 8 | 16.1s |  |
| 81 | `catch_references_registers` | 2 | 16.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 82 | `click_block` | 5 | 16.2s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 83 | `clip_constructors` | 8 | 16.8s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 84 | `clip_event_propagation_order` | 17 | 16.6s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 85 | `clip_events` | 19 | 16.5s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 86 | `clone_sprite_edittext` | 94 | 16.6s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 87 | `clone_sprite_edittext_dynamic` | 86 | 16.6s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 88 | `clone_sprite_types` | 24 | 16.2s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 89 | `closure_scope` | 7 | 16.3s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 90 | `coerce_to_object_monkeypatch` | 129 | 16.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 91 | `coerce_to_primitive_resolve` | 17 | 16.6s | [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 92 | `color` | 57 | 16.7s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_CXFORM_GPU_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 93 | `color_transform` | 48 | 16.5s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 94 | `conflicting_instance_names` | 23 | 16.4s |  |
| 95 | `constructor_function` | 2 | 16.3s |  |
| 96 | `context_menu` | 39 | 16.7s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 97 | `context_menu_item` | 41 | 16.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 98 | `create_empty_movie_clip` | 3 | 16.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 99 | `cross_movie_root` | 10 | 16.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 100 | `custom_clip_methods` | 4 | 16.4s | [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 101 | `default_names` | 52 | 16.5s | [22](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 102 | `define_function2` | 8 | 16.9s |  |
| 103 | `define_function2_preload` | 13 | 17.0s |  |
| 104 | `define_function2_preload_order` | 4 | 16.8s |  |
| 105 | `define_function_case_sensitive` | 2 | 16.9s |  |
| 106 | `define_local` | 27 | 16.8s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 107 | `define_local_with_paths` | 54 | 17.2s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 108 | `delete` | 3 | 16.7s |  |
| 109 | `device_font_spacing` | 91 | 17.1s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 110 | `display_object_properties` | 2 | 16.5s | [70](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_CXFORM_GPU_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 111 | `divide_swf4` | 107 | 16.6s |  |
| 112 | `do_init_action` | 3 | 16.8s |  |
| 113 | `do_init_action_child` | 12 | 16.8s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 114 | `drag_drop` | 10 | 17.2s | [25](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 115 | `drag_over_from_outside` | 1 | 17.3s | [25](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 116 | `drag_over_without_startdrag` | 1 | 16.7s | [25](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 117 | `duplicate_movie_clip` | 20 | 17.1s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 118 | `duplicate_movie_clip_drawing` | 2 | 17.0s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 119 | `edittext_align` | 60 | 17.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 120 | `edittext_align_trailing_spaces_swf7` | 576 | 17.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 121 | `edittext_align_trailing_spaces_swf8` | 576 | 17.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 122 | `edittext_antialiastype` | 296 | 17.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 123 | `edittext_autosize` | 71 | 22.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 124 | `edittext_autosize_setter` | 20 | 21.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 125 | `edittext_bullet` | 30 | 21.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 126 | `edittext_default_format` | 221 | 20.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 127 | `edittext_default_format_font_style` | 335 | 20.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 128 | `edittext_drag_select` | 9 | 20.5s | [27](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/blocked/PIXEL_TEXT_LAYOUT_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 129 | `edittext_focus_selection` | 2 | 20.4s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 130 | `edittext_font_size` | 45 | 21.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 131 | `edittext_hscroll` | 27 | 20.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 132 | `edittext_html_align_swf7` | 52 | 20.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 133 | `edittext_html_align_swf8` | 52 | 20.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 134 | `edittext_html_color` | 114 | 20.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 135 | `edittext_html_condensewhite_swf7` | 311 | 20.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 136 | `edittext_html_condensewhite_swf8` | 311 | 21.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 137 | `edittext_html_entity` | 4 | 21.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 138 | `edittext_html_roundtrip` | 17 | 20.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 139 | `edittext_html_swf6` | 5377 | 22.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 140 | `edittext_html_swf7` | 5377 | 23.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 141 | `edittext_html_swf8` | 5377 | 23.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 142 | `edittext_input` | 1 | 17.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 143 | `edittext_input_newlines` | 9 | 16.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 144 | `edittext_leading` | 9 | 16.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 145 | `edittext_letter_spacing` | 15 | 16.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 146 | `edittext_margins` | 25 | 16.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 147 | `edittext_newline_stripping` | 64 | 21.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 148 | `edittext_newlines` | 30 | 16.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 149 | `edittext_password` | 5 | 16.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 150 | `edittext_password_copy` | 4 | 16.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 151 | `edittext_paste_empty` | 2 | 16.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 152 | `edittext_place_caret` | 2 | 16.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 153 | `edittext_programmatic_focus` | 12 | 16.4s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 154 | `edittext_restrict` | 191 | 16.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 155 | `edittext_restrict_paste` | 5 | 16.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 156 | `edittext_scroll` | 54 | 16.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 157 | `edittext_stylesheet` | 325 | 17.2s | [18](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 158 | `edittext_tab_focus` | 13 | 16.2s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 159 | `edittext_tab_stops` | 60 | 16.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 160 | `edittext_tag_indent` | 31 | 16.5s | [18](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 161 | `edittext_text_height_leading` | 20 | 16.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 162 | `edittext_underline` | 40 | 16.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 163 | `edittext_width_height` | 103 | 17.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 164 | `empty_movieclip_can_attach_movies` | 11 | 16.4s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 165 | `enumerate` | 64 | 16.7s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 166 | `equals` | 32 | 16.4s |  |
| 167 | `equals2_swf5` | 926 | 18.1s |  |
| 168 | `equals2_swf6` | 926 | 18.2s |  |
| 169 | `equals2_swf7` | 926 | 18.2s |  |
| 170 | `equals_swf4` | 665 | 17.5s |  |
| 171 | `equals_swf4_alt` | 32 | 16.6s |  |
| 172 | `equals_swf5` | 32 | 16.6s |  |
| 173 | `error` | 58 | 16.5s |  |
| 174 | `escape` | 14 | 16.5s |  |
| 175 | `execution_order1` | 5 | 16.6s |  |
| 176 | `execution_order2` | 7 | 16.6s |  |
| 177 | `execution_order3` | 4 | 16.6s |  |
| 178 | `execution_order4` | 12 | 16.8s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 179 | `export_assets` | 3 | 16.6s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 180 | `extends_chain` | 134 | 17.2s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 181 | `extends_native_type` | 11 | 16.5s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 182 | `external_interface` | 84 | 16.7s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 183 | `external_interface_escapexml` | 26 | 16.7s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 184 | `external_interface_jsquotestring` | 21 | 16.9s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 185 | `external_interface_toas_basic` | 354 | 17.2s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 186 | `external_interface_toxml_array` | 25 | 16.6s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 187 | `external_interface_toxml_basic` | 179 | 16.9s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 188 | `external_interface_unescapexml` | 40 | 16.8s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 189 | `focus_keyboard_press` | 60 | 16.6s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 190 | `focus_mouse` | 45 | 16.6s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 191 | `focus_mouse_focusable` | 8 | 17.2s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 192 | `focus_mouse_rollout` | 4 | 16.9s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 193 | `focus_remove` | 33 | 16.6s |  |
| 194 | `focus_root_movie` | 2 | 16.6s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 195 | `focus_visibility_change` | 45 | 16.5s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 196 | `focusrect_focuslost` | 4 | 16.6s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 197 | `focusrect_mouse_swf8` | 0 | 17.9s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 198 | `focusrect_mouse_swf9` | 0 | 16.8s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 199 | `focusrect_property_swf5` | 1237 | 17.4s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 200 | `focusrect_property_swf6` | 1237 | 17.1s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 201 | `focusrect_property_swf7` | 1237 | 17.0s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 202 | `focusrect_swf5` | 6 | 16.9s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 203 | `focusrect_swf6` | 42 | 16.8s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 204 | `form_loader_encoding_1` | 1 | 16.7s |  |
| 205 | `frame_size_translated_negative` | 21 | 16.9s | [18](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 206 | `frame_size_translated_positive` | 21 | 16.7s | [18](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 207 | `function_as_function` | 35 | 16.7s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 208 | `function_base_clip` | 8 | 16.9s |  |
| 209 | `function_base_clip_readded` | 11 | 16.8s |  |
| 210 | `function_base_clip_removed` | 25 | 16.8s |  |
| 211 | `function_suppress_and_preload` | 28 | 16.9s |  |
| 212 | `funky_function_calls` | 56 | 16.8s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 213 | `get_bytes_total` | 4 | 17.0s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 214 | `get_variable_in_scope` | 29 | 17.3s |  |
| 215 | `getproperty` | 28 | 18.0s |  |
| 216 | `getproperty_swf4` | 28 | 17.0s |  |
| 217 | `getproperty_swf5` | 28 | 17.1s |  |
| 218 | `gettextextent` | 56 | 17.3s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 219 | `global_array` | 3 | 17.0s |  |
| 220 | `global_is_bare` | 7 | 16.6s |  |
| 221 | `global_swf5_6_7_8_9` | 1145 | 17.9s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 222 | `global_swf6_7_8` | 15 | 17.3s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 223 | `globals_swf5` | 304 | 16.7s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 224 | `globals_swf6` | 304 | 16.9s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 225 | `globals_swf7` | 304 | 16.7s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 226 | `globals_swf8` | 304 | 17.5s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 227 | `goto_advance1` | 6 | 17.3s |  |
| 228 | `goto_advance2` | 2 | 16.6s |  |
| 229 | `goto_both_ways1` | 3 | 16.6s |  |
| 230 | `goto_both_ways2` | 3 | 16.7s |  |
| 231 | `goto_execution_order` | 2 | 16.6s |  |
| 232 | `goto_execution_order2` | 2 | 16.5s |  |
| 233 | `goto_frame` | 12 | 16.5s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 234 | `goto_frame2` | 44 | 16.9s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 235 | `goto_frame_number` | 3 | 16.4s |  |
| 236 | `goto_label` | 17 | 16.5s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 237 | `goto_methods` | 40 | 16.4s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 238 | `goto_rewind1` | 1 | 16.4s |  |
| 239 | `goto_rewind2` | 3 | 16.6s |  |
| 240 | `goto_rewind3` | 2 | 16.5s |  |
| 241 | `greater_swf6` | 1175 | 18.5s |  |
| 242 | `greater_swf7` | 1175 | 18.3s |  |
| 243 | `greaterthan_swf5` | 1 | 16.3s |  |
| 244 | `greaterthan_swf8` | 1 | 16.4s |  |
| 245 | `has_own_property` | 32 | 16.4s |  |
| 246 | `hittest_lockroot` | 15 | 16.7s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 247 | `hittest_morph` | 70 | 16.5s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 248 | `hittest_morph_input` | 1 | 16.4s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 249 | `hittest_winding_rule` | 12 | 16.6s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 250 | `infinite_recursion_function` | 4 | 16.4s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 251 | `infinite_recursion_function_in_setter` | 131 | 16.5s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 252 | `infinite_recursion_virtual_property` | 67 | 16.5s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 253 | `init_array_invalid` | 4 | 17.4s |  |
| 254 | `init_object_invalid` | 4 | 17.2s |  |
| 255 | `init_object_order` | 15 | 17.3s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 256 | `input_dead_keys_windows` | 15 | 17.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 257 | `instanceof_coercions` | 88 | 17.7s | [95](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 258 | `interface_implements_op` | 47 | 17.9s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 259 | `is_finite` | 49 | 17.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 260 | `is_finite_swf6` | 49 | 17.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 261 | `is_prototype_of` | 89 | 17.3s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 262 | `issue_1086` | 1 | 17.2s |  |
| 263 | `issue_1104` | 2 | 17.2s | [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 264 | `issue_1671` | 0 | 17.2s |  |
| 265 | `issue_1906` | 4 | 17.3s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 266 | `issue_2030` | 4 | 17.2s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 267 | `issue_2084` | 16 | 17.4s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 268 | `issue_2166` | 9 | 17.1s |  |
| 269 | `issue_2870` | 3 | 17.2s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 270 | `issue_3169` | 2 | 17.3s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 271 | `issue_3446` | 1 | 17.2s |  |
| 272 | `issue_3522` | 2 | 17.2s |  |
| 273 | `issue_4377` | 2 | 17.1s |  |
| 274 | `issue_710` | 4 | 16.6s |  |
| 275 | `issue_768` | 3 | 16.1s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) |
| 276 | `issue_9327` | 2 | 16.1s |  |
| 277 | `issue_9885` | 2 | 16.1s |  |
| 278 | `key_isToggled` | 9 | 16.0s |  |
| 279 | `lessthan` | 41 | 16.1s |  |
| 280 | `lessthan2_swf5` | 1226 | 18.2s |  |
| 281 | `lessthan2_swf6` | 1226 | 18.2s |  |
| 282 | `lessthan2_swf7` | 1226 | 18.1s |  |
| 283 | `lessthan_swf4` | 902 | 17.2s |  |
| 284 | `lessthan_swf4_alt` | 41 | 16.2s |  |
| 285 | `lessthan_swf5` | 41 | 16.3s |  |
| 286 | `loadmovie` | 2 | 16.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 287 | `loadmovie_fail` | 2 | 16.3s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 288 | `loadmovie_flashvars` | 4 | 16.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 289 | `loadmovie_method` | 2 | 16.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 290 | `loadmovie_registerclass` | 30 | 16.4s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 291 | `loadmovie_replace_root` | 5 | 16.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 292 | `loadmovie_var_persistence` | 8 | 16.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 293 | `loadmovienum` | 3 | 16.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 294 | `loadmovienum_cross_version_prototype` | 9 | 16.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 295 | `loadvariables` | 2 | 16.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 296 | `loadvariables2` | 8 | 16.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 297 | `loadvariablesnum` | 2 | 16.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 298 | `local_to_global` | 49 | 16.3s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 299 | `localconnection_properties` | 8 | 16.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 300 | `lock_root` | 1 | 16.4s |  |
| 301 | `logical_ops_swf4` | 90 | 16.2s |  |
| 302 | `logical_ops_swf8` | 108 | 16.2s |  |
| 303 | `looping` | 6 | 16.2s |  |
| 304 | `mask_reapply` | 0 | 16.2s | [71](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_SETMASK_PLAN.md) |
| 305 | `mask_with_drawing` | 0 | 16.2s | [26](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DRAWING_API_RENDERING_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_SETMASK_PLAN.md) |
| 306 | `math_min_max` | 101 | 16.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 307 | `math_swf6` | 530 | 16.7s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 308 | `math_swf7` | 530 | 16.7s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 309 | `math_swf8` | 530 | 16.7s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 310 | `matrix` | 171 | 16.5s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 311 | `mcl_as_broadcaster` | 12 | 16.3s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 312 | `mcl_events_swf_version` | 232 | 17.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 313 | `mcl_getprogress` | 30 | 19.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 314 | `mcl_loadclip` | 149 | 19.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 315 | `mcl_loadclip_properties` | 6 | 19.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 316 | `mcl_loadclip_replace_root` | 1 | 19.3s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 317 | `mcl_mislabeled_target` | 6 | 19.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 318 | `mcl_target_gif87a` | 6 | 19.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 319 | `mcl_target_gif89a` | 6 | 19.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 320 | `mcl_target_jpg` | 6 | 19.3s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 321 | `mcl_target_png` | 6 | 19.3s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 322 | `mcl_unloadclip` | 5 | 18.9s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 323 | `mouse_events` | 8 | 19.0s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 324 | `mouse_events_visible_enabled` | 12 | 19.5s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 325 | `mouse_hover_events_while_dragging` | 1 | 18.9s | [25](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 326 | `mouse_listeners` | 67 | 19.2s |  |
| 327 | `mouse_pos` | 665 | 18.7s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 328 | `mouse_pos_with_scale_factor` | 260 | 18.7s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 329 | `mouse_wheel_enabled` | 2 | 18.8s |  |
| 330 | `movieclip_begin_gradient_fill` | 0 | 19.5s | [26](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DRAWING_API_RENDERING_PLAN.md) |
| 331 | `movieclip_blend_mode_property` | 35 | 19.1s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 332 | `movieclip_create_text_field` | 90 | 17.0s | [18](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 333 | `movieclip_default_state` | 69 | 16.4s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 334 | `movieclip_depth_methods` | 98 | 16.4s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 335 | `movieclip_focusenabled` | 99 | 16.3s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 336 | `movieclip_get_instance_at_depth` | 28 | 16.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 337 | `movieclip_getbounds` | 191 | 16.3s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 338 | `movieclip_gettextsnapshot` | 112 | 16.3s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 339 | `movieclip_hittest` | 92 | 16.2s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 340 | `movieclip_in_removed_button` | 4 | 16.1s | [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 341 | `movieclip_init_object` | 5 | 16.1s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 342 | `movieclip_invalid_get_bounds_1` | 75 | 16.8s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 343 | `movieclip_invalid_get_bounds_2` | 75 | 16.8s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 344 | `movieclip_invalid_get_bounds_3` | 13 | 16.7s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 345 | `movieclip_invalid_get_bounds_4` | 13 | 16.8s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 346 | `movieclip_invalid_get_bounds_5` | 11 | 16.6s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 347 | `movieclip_invalid_get_bounds_6` | 10 | 40.6s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 348 | `movieclip_invalid_get_bounds_7` | 10 | 40.2s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 349 | `movieclip_invalid_get_bounds_8` | 11 | 16.8s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 350 | `movieclip_line_gradient_style` | 0 | 17.1s | [26](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DRAWING_API_RENDERING_PLAN.md) |
| 351 | `movieclip_lockroot` | 29 | 17.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 352 | `movieclip_name_from_timeline` | 13 | 16.5s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 353 | `movieclip_prototype_extension` | 5 | 16.5s |  |
| 354 | `movieclip_setmask` | 14 | 16.7s | [26](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DRAWING_API_RENDERING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_SETMASK_PLAN.md) |
| 355 | `moviecliploader_flashvars` | 4 | 16.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 356 | `mutable_this` | 18 | 16.5s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 357 | `named_shapes` | 14 | 16.5s |  |
| 358 | `nan_scale` | 9 | 16.5s |  |
| 359 | `native_double_construct` | 12 | 16.6s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 360 | `native_objects_swf7` | 84 | 16.9s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 361 | `native_objects_swf8` | 84 | 16.9s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 362 | `nested_textfields_in_buttons` | 0 | 16.5s |  |
| 363 | `new_method_wrap` | 4 | 17.3s |  |
| 364 | `new_object_enumerate` | 7 | 17.2s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 365 | `new_object_wrap` | 4 | 17.2s |  |
| 366 | `o` | 3 | 17.1s |  |
| 367 | `object_constructor` | 33 | 17.1s |  |
| 368 | `object_function` | 32 | 17.3s |  |
| 369 | `object_properties` | 31 | 17.4s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 370 | `object_prototypes` | 74 | 17.4s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 371 | `object_resolve` | 38 | 17.4s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 372 | `object_string_coerce_swf5` | 62 | 17.8s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 373 | `object_string_coerce_swf6` | 68 | 18.3s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 374 | `on_construct` | 25 | 18.2s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 375 | `parse_float` | 74 | 17.8s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 376 | `parse_int` | 64 | 18.7s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 377 | `path_string` | 322 | 17.7s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 378 | `place_and_lookup` | 30 | 17.4s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 379 | `placeobject_occupied_depth` | 6 | 17.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 380 | `point` | 175 | 17.6s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 381 | `primitive_instanceof` | 37 | 17.1s |  |
| 382 | `primitive_type_globals` | 557 | 17.4s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 383 | `printjob_props_swf5` | 45 | 17.1s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 384 | `printjob_props_swf6` | 45 | 17.0s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 385 | `printjob_props_swf7` | 45 | 16.1s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 386 | `property_invalid_base_clip` | 36 | 16.2s |  |
| 387 | `prototype_delete` | 12 | 16.4s |  |
| 388 | `prototype_enumerate` | 5 | 16.2s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 389 | `prototype_properties` | 17 | 16.1s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 390 | `rectangle` | 745 | 16.9s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 391 | `recursive_prototypes` | 0 | 16.0s |  |
| 392 | `register_and_init_order` | 231 | 16.5s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 393 | `register_class` | 66 | 16.8s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 394 | `register_class_return_value` | 16 | 16.7s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 395 | `register_class_swf6` | 37 | 16.7s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 396 | `register_class_with_sound` | 11 | 16.5s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 397 | `register_globals_across_frames` | 15 | 16.2s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 398 | `register_underflow` | 26 | 16.3s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 399 | `remove_movie_clip` | 29 | 16.7s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 400 | `removed_clip_halts_script` | 15 | 17.0s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 401 | `removed_target_clip_scope` | 35 | 16.5s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 402 | `resolve_different_root` | 2 | 17.0s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 403 | `rewind_depth` | 30 | 17.1s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 404 | `root_button_mode` | 10 | 16.4s | [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 405 | `root_global_parent` | 6 | 16.3s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 406 | `root_onload` | 1 | 16.2s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 407 | `sandbox_type_local_file` | 1 | 16.1s |  |
| 408 | `sandbox_type_local_network` | 1 | 16.2s |  |
| 409 | `selection` | 454 | 16.4s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 410 | `selection_handlers` | 27 | 16.4s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 411 | `set_interval` | 27 | 16.4s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 412 | `set_variable_scope` | 58 | 16.2s |  |
| 413 | `single_frame` | 1 | 16.1s |  |
| 414 | `slash_syntax` | 14 | 16.2s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 415 | `sound` | 628 | 16.4s | [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 416 | `sound_props_swf5` | 68 | 16.3s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 417 | `sound_props_swf6` | 68 | 16.6s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 418 | `sound_start_load` | 0 | 16.3s |  |
| 419 | `stage_display_state` | 16 | 16.3s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 420 | `stage_object_children` | 83 | 16.4s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 421 | `stage_object_enumerate` | 4 | 16.3s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 422 | `stage_object_properties` | 241 | 16.6s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 423 | `stage_object_properties_get_var` | 5 | 16.2s |  |
| 424 | `stage_object_properties_swf6` | 231 | 16.6s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 425 | `stage_property_representation` | 586 | 16.3s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 426 | `stage_scale_mode` | 39 | 16.2s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 427 | `strictequals_swf6` | 902 | 17.8s |  |
| 428 | `strictly_equals` | 7 | 16.2s |  |
| 429 | `string_coercion` | 117 | 16.6s | [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) |
| 430 | `string_methods` | 285 | 16.7s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 431 | `string_methods_negative_args` | 240 | 16.2s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 432 | `string_methods_swfv5` | 275 | 17.0s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 433 | `string_ops_swf6` | 95 | 16.3s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 434 | `string_paths_basic` | 4 | 16.2s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 435 | `string_paths_eval` | 4 | 16.3s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 436 | `string_paths_eval2` | 7 | 16.5s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 437 | `string_paths_hidden` | 54 | 17.5s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 438 | `string_paths_keyevents` | 0 | 16.5s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 439 | `string_paths_other` | 36 | 16.6s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 440 | `string_paths_timer` | 0 | 16.4s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 441 | `string_paths_unload` | 1 | 16.4s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 442 | `string_paths_variable_alias` | 4 | 16.4s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 443 | `string_paths_variable_scopes` | 5 | 16.5s | [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 444 | `stylesheet` | 283 | 17.4s |  |
| 445 | `stylesheet_transform` | 750 | 17.3s |  |
| 446 | `super_edge_cases` | 39 | 16.7s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 447 | `swf4_actions_bool` | 96 | 16.6s |  |
| 448 | `swf4_actions_coercion_order` | 158 | 16.5s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 449 | `swf4_bool` | 4 | 16.4s |  |
| 450 | `swf4_function_calls` | 7 | 16.4s |  |
| 451 | `swf5_encoding` | 3 | 16.4s |  |
| 452 | `swf5_global_funcs` | 232 | 16.5s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 453 | `swf5_no_closure` | 19 | 16.5s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 454 | `swf5_to_6_cross_call` | 29 | 17.0s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 455 | `swf6_case_insensitive` | 42 | 16.8s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 456 | `swf6_global_funcs` | 232 | 17.1s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 457 | `swf6_string_as_bool` | 15 | 16.9s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 458 | `swf6_to_5_cross_call` | 29 | 17.0s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 459 | `swf7_case_sensitive` | 44 | 16.9s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 460 | `swf7_global_funcs` | 232 | 16.6s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 461 | `tab_ordering_automatic_basic` | 92 | 17.1s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 462 | `tab_ordering_automatic_order_grid` | 21 | 17.1s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 463 | `tab_ordering_automatic_order_same_position` | 12 | 16.8s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 464 | `tab_ordering_children` | 208 | 16.9s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 465 | `tab_ordering_custom_basic` | 71 | 16.6s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 466 | `tab_ordering_custom_duplicate_index` | 22 | 16.7s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 467 | `tab_ordering_custom_i32_vs_u32` | 12 | 17.0s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 468 | `tab_ordering_custom_m1` | 29 | 16.8s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 469 | `tab_ordering_events` | 150 | 17.4s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 470 | `tab_ordering_events_mouse` | 65 | 17.1s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 471 | `tab_ordering_movieclip_enabled_default` | 462 | 16.8s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 472 | `tab_ordering_properties` | 293 | 16.9s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 473 | `tab_ordering_reverse` | 51 | 16.6s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 474 | `tab_ordering_tabbable` | 47 | 16.8s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 475 | `target_clip_removed` | 5 | 16.6s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 476 | `target_clip_swf5` | 2 | 16.4s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 477 | `target_clip_swf6` | 2 | 16.4s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 478 | `target_path` | 14 | 16.4s |  |
| 479 | `tell_target` | 37 | 16.5s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 480 | `tell_target_invalid` | 6 | 16.5s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 481 | `tell_target_invalid_swf6` | 5 | 16.5s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 482 | `text_blocks_clicks` | 4 | 16.4s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 483 | `text_format` | 1146 | 16.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 484 | `text_format_display` | 21 | 16.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 485 | `text_format_font_max_length` | 2 | 16.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 486 | `text_format_get_text_extent_undefined_width` | 10 | 16.6s |  |
| 487 | `text_format_rounding_swf7` | 840 | 16.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 488 | `text_format_rounding_swf8` | 840 | 16.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 489 | `textfield_background_color` | 11 | 16.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 490 | `textfield_border_color` | 11 | 16.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 491 | `textfield_cache_as_bitmap` | 1 | 16.8s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 492 | `textfield_maxchars` | 3 | 18.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 493 | `textfield_properties` | 44 | 17.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 494 | `textfield_props_swf5` | 175 | 17.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 495 | `textfield_props_swf6` | 210 | 18.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 496 | `textfield_props_swf7` | 210 | 17.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 497 | `textfield_props_swf8` | 210 | 17.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 498 | `textfield_text` | 7 | 18.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 499 | `textfield_variable` | 81 | 17.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 500 | `textsnapshot_available_text` | 20 | 17.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 501 | `textsnapshot_findtext` | 44 | 18.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 502 | `textsnapshot_gettext` | 55 | 18.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 503 | `textsnapshot_props_swf5` | 56 | 17.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 504 | `textsnapshot_props_swf6` | 56 | 17.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 505 | `textsnapshot_text_order` | 1 | 17.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 506 | `this_scoping` | 52 | 18.4s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 507 | `this_swf5` | 41 | 17.6s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 508 | `this_swf6` | 41 | 17.8s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 509 | `this_swf7` | 41 | 17.9s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) |
| 510 | `timeline_function_def` | 7 | 18.1s |  |
| 511 | `timer_run_actions` | 18 | 16.8s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 512 | `trace` | 8 | 16.4s |  |
| 513 | `transform` | 70 | 16.4s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 514 | `try_catch_finally` | 118 | 16.5s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 515 | `try_finally_simple` | 16 | 16.4s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 516 | `typeof` | 22 | 16.3s |  |
| 517 | `typeof_globals` | 7 | 16.2s |  |
| 518 | `uncaught_exception` | 1 | 16.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 519 | `uncaught_exception_bubbled` | 1 | 16.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 520 | `undefined_to_string_swf6` | 4 | 16.2s |  |
| 521 | `unescape` | 43 | 16.3s |  |
| 522 | `unload` | 52 | 16.5s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 523 | `unload_clip_event` | 4 | 16.3s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 524 | `unload_nested_child` | 5 | 16.4s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 525 | `unloadmovie` | 4 | 16.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 526 | `unloadmovie_method` | 3 | 16.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 527 | `unloadmovienum` | 13 | 16.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 528 | `use_hand_cursor` | 8 | 16.2s |  |
| 529 | `variable_args` | 5 | 16.4s |  |
| 530 | `waitforframe` | 7 | 16.2s |  |
| 531 | `waitforframe2` | 16 | 16.9s |  |
| 532 | `watch` | 117 | 16.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 533 | `watch_textfield` | 12 | 16.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 534 | `watch_virtual_property_proto` | 2 | 16.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 535 | `with` | 49 | 16.3s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 536 | `with_return` | 2 | 16.2s |  |
| 537 | `with_variable_scopes` | 43 | 16.4s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 538 | `xml` | 15 | 16.2s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 539 | `xml_append_child` | 28 | 16.2s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 540 | `xml_append_child_with_parent` | 20 | 16.6s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 541 | `xml_attributes_read` | 4 | 16.4s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 542 | `xml_cdata` | 11 | 16.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 543 | `xml_child_nodes_edge_cases` | 4 | 16.4s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 544 | `xml_clone_expandos` | 19 | 16.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 545 | `xml_first_last_child` | 8 | 16.4s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 546 | `xml_has_child_nodes` | 3 | 16.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 547 | `xml_idmap` | 21 | 16.4s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 548 | `xml_ignore_comments` | 21 | 16.4s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 549 | `xml_ignore_white` | 34 | 17.1s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 550 | `xml_insert_before` | 20 | 16.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 551 | `xml_inspect_createmethods` | 15 | 16.4s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 552 | `xml_inspect_doctype` | 7 | 16.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 553 | `xml_inspect_parsexml` | 62 | 16.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 554 | `xml_inspect_xmldecl` | 7 | 16.1s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 555 | `xml_namespaces` | 203 | 16.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 556 | `xml_parent_and_child` | 5 | 16.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 557 | `xml_remove_node` | 22 | 16.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 558 | `xml_reparenting` | 14 | 16.4s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 559 | `xml_siblings` | 10 | 16.2s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 560 | `xml_to_string` | 13 | 16.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 561 | `xml_to_string_comment` | 1 | 16.1s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 562 | `xml_unescaping` | 23 | 16.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 563 | `xmlnode_proto` | 1 | 16.2s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**11 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `native_subclasses` | 99.5% | 190 | 191 | 1 | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `date` | 99.2% | 6284 | 6335 | 51 | [21](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) |
| 3 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56 | 57 | 1 | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 5 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56 | 57 | 1 | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 6 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 7 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 8 | `movieclip_hittest_shapeflag` | 92.3% | 312 | 338 | 26 | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 9 | `bitmap_filters` | 90.5% | 496 | 548 | 52 | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_FILTER_CLONE_PLAN.md) [7](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_FILTERS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 10 | `string_relational_compare` | 75.0% | 3 | 4 | 1 |  |
| 11 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Segfaults

**1 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `netstream_play_flv_screen` | 33.6s | [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/FLV_PLAYBACK_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 47.6s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**55 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `native_subclasses` | 99.5% | 190/191 | 191 | 191 | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [21](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) |
| 3 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56/57 | 57 | 57 | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 5 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56/57 | 57 | 57 | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 6 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 7 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 8 | `movieclip_hittest_shapeflag` | 92.3% | 312/338 | 338 | 338 | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 9 | `bitmap_filters` | 90.5% | 496/548 | 548 | 548 | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [6](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_FILTER_CLONE_PLAN.md) [7](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_FILTERS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 10 | `string_relational_compare` | 75.0% | 3/4 | 4 | 4 |  |
| 11 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 12 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 13 | `load_vars` | 37.1% | 13/35 | 23 | 35 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 14 | `movieclip_state_values` | 34.2% | 39/114 | 63 | 114 | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 15 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 16 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 17 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 18 | `tab_ordering_properties_tab_index_edge_case` | 25.0% | 1/4 | 4 | 4 |  |
| 19 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 20 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 21 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 22 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [52](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 23 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 24 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 25 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/NETCONNECTION_PLAN.md) |
| 26 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 27 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 | [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/FLV_PLAYBACK_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 28 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 29 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 30 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 31 | `global_proto_decls` | 2.6% | 116/4497 | 1288 | 4497 | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 32 | `global_instance_decls` | 2.2% | 17/758 | 704 | 758 | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 33 | `global_proto_decls_delete` | 2.2% | 93/4158 | 727 | 4158 | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 34 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 35 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/NETCONNECTION_PLAN.md) |
| 36 | `sound_id3` | 1.7% | 11/633 | 11 | 633 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [77](ruffle-tests/tests/swfs/avm1/_investigation/blocked/SOUND_ID3_PLAN.md) |
| 37 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [77](ruffle-tests/tests/swfs/avm1/_investigation/blocked/SOUND_ID3_PLAN.md) |
| 38 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [76](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/SOUND_DURATION_POSITION_PLAN.md) |
| 39 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/blocked/PIXEL_TEXT_LAYOUT_PLAN.md) |
| 40 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [24](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DISPLACEMENTMAPFILTER_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 41 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [65](ruffle-tests/tests/swfs/avm1/_investigation/blocked/PIXEL_TEXT_LAYOUT_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 42 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 43 | `geturl` | 0.0% | 0/7 | 0 | 7 | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 44 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 45 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 46 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 | [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/FLV_PLAYBACK_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 47 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 48 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [78](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/SOUND_LOADING_PLAN.md) |
| 49 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [78](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/SOUND_LOADING_PLAN.md) |
| 50 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 51 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [84](ruffle-tests/tests/swfs/avm1/_investigation/blocked/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 52 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 53 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 54 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 55 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) | 17 | 16 | 1 |
| 6 | [BITMAP_FILTER_CLONE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_FILTER_CLONE_PLAN.md) | 1 | 0 | 1 |
| 7 | [BITMAP_FILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_FILTERS_PLAN.md) | 1 | 0 | 1 |
| 8 | [BITMAPDATA_APPLYFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_APPLYFILTER_PLAN.md) | 0 | 0 | 0 |
| 9 | [BITMAPDATA_PERLINNOISE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PERLINNOISE_PLAN.md) | 0 | 0 | 0 |
| 10 | [BITMAPDATA_PIXELDISSOLVE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PIXELDISSOLVE_PLAN.md) | 0 | 0 | 0 |
| 11 | [BITMAPDATA_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) | 6 | 6 | 0 |
| 12 | [BUTTON_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) | 14 | 14 | 0 |
| 13 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 14 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) | 8 | 8 | 0 |
| 15 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 4 | 0 |
| 16 | [COLOR_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 17 | [COPYPIXELS_ALPHA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/COPYPIXELS_ALPHA_PLAN.md) | 0 | 0 | 0 |
| 18 | [CREATETEXTFIELD_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 19 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 1 | 1 | 0 |
| 20 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 21 | [DATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 22 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 23 | [DEVICE_FONT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) | 2 | 2 | 0 |
| 24 | [DISPLACEMENTMAPFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DISPLACEMENTMAPFILTER_PLAN.md) | 1 | 0 | 1 |
| 25 | [DRAG_DROP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 26 | [DRAWING_API_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DRAWING_API_RENDERING_PLAN.md) | 4 | 4 | 0 |
| 27 | [EDITTEXT_DRAG_SELECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) | 1 | 1 | 0 |
| 28 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 29 | [ENUMERATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 30 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 31 | [FILLRECT_COLOR_CONSTANT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FILLRECT_COLOR_CONSTANT_PLAN.md) | 0 | 0 | 0 |
| 32 | [FILLRECT_COLOR_CONSTANT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/FILLRECT_COLOR_CONSTANT_PLAN.md) | 0 | 0 | 0 |
| 33 | [FLV_PLAYBACK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/FLV_PLAYBACK_PLAN.md) | 3 | 0 | 3 |
| 34 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 4 | 0 |
| 35 | [FOCUS_RECT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 36 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 7 | 0 |
| 37 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 38 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 39 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 6 | 1 |
| 40 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 41 | [GLOBALS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 26 | 5 |
| 42 | [HIT_TESTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) | 17 | 16 | 1 |
| 43 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 23 | 0 | 23 |
| 44 | [infinite_recursion_function.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 45 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 46 | [issue_768.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 47 | [LOADBITMAP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/LOADBITMAP_PLAN.md) | 0 | 0 | 0 |
| 48 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 49 | [LOADMOVIE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) | 48 | 42 | 6 |
| 50 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 3 | 2 |
| 51 | [LOADVARIABLES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 52 | [LOCALCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) | 1 | 0 | 1 |
| 53 | [LOCKROOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 54 | [MATH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 55 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 56 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 57 | [MOVIECLIP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) | 58 | 53 | 5 |
| 58 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 14 | 2 |
| 59 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 14 | 3 |
| 60 | [NETCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/NETCONNECTION_PLAN.md) | 2 | 0 | 2 |
| 61 | [object_string_coerce.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 62 | [OBJECT_WATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 63 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 64 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 65 | [PIXEL_TEXT_LAYOUT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/PIXEL_TEXT_LAYOUT_PLAN.md) | 3 | 1 | 2 |
| 66 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 67 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 68 | [REGISTERCLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) | 15 | 15 | 0 |
| 69 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 4 | 2 | 2 |
| 70 | [RUNTIME_CXFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_CXFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 71 | [RUNTIME_SETMASK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_SETMASK_PLAN.md) | 3 | 3 | 0 |
| 72 | [RUNTIME_TRANSFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_TRANSFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 73 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 74 | [SELECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) | 4 | 4 | 0 |
| 75 | [SOUND_CLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 76 | [SOUND_DURATION_POSITION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/SOUND_DURATION_POSITION_PLAN.md) | 1 | 0 | 1 |
| 77 | [SOUND_ID3_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/SOUND_ID3_PLAN.md) | 2 | 0 | 2 |
| 78 | [SOUND_LOADING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/SOUND_LOADING_PLAN.md) | 2 | 0 | 2 |
| 79 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 80 | [STAGE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 81 | [string_coercion.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 82 | [STRING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) | 13 | 12 | 1 |
| 83 | [STYLESHEET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 84 | [SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) | 1 | 0 | 1 |
| 85 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 5 | 0 |
| 86 | [TAB_ORDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 16 | 0 |
| 87 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 1 | 0 |
| 88 | [TELLTARGET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 17 | 2 |
| 89 | [TEXTFIELD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) | 70 | 68 | 2 |
| 90 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 91 | [THIS_BINDING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 92 | [this_swf7.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 93 | [TIMER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) | 3 | 2 | 1 |
| 94 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 95 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 2 | 0 |
| 96 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 12 | 4 |
| 97 | [UNLOAD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) | 12 | 12 | 0 |
| 98 | [WITH_SCOPE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 99 | [XML_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 146 | 144 | 2 |
