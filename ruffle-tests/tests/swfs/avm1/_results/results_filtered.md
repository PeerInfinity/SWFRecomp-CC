# Ruffle Test Results (Filtered)

**Date**: 2026-04-04 01:50 UTC

**Git SHA**: `7a348be46a`

**Run Duration**: 181m 33s

**Filtered**: 52 tests ignored out of 620 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 526 |
| Passing | **523** (99.4%) |
| Failing | 3 |
| Total expected lines | 67736 |
| Matching lines | 67702 (99.9%) |
| Mismatched lines | 34 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**523 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 19.6s |  |
| 2 | `action_to_integer` | 28 | 19.6s |  |
| 3 | `add` | 28 | 19.7s |  |
| 4 | `add2` | 354 | 19.5s | [1](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 19.6s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 19.8s |  |
| 7 | `add_swf5` | 28 | 19.7s |  |
| 8 | `arguments` | 127 | 19.8s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 19.6s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 19.6s |  |
| 11 | `array_constructor` | 30 | 19.7s |  |
| 12 | `array_enumerate` | 4 | 19.8s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 19.7s |  |
| 14 | `array_properties` | 36 | 19.7s |  |
| 15 | `array_prototyping` | 12 | 19.6s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 19.8s |  |
| 17 | `array_sort` | 161 | 20.8s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 19.8s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 20.0s |  |
| 20 | `array_trivial` | 209 | 19.9s |  |
| 21 | `as1_constructor_v6` | 35 | 19.8s |  |
| 22 | `as1_constructor_v7` | 35 | 20.7s |  |
| 23 | `as2_oop` | 13 | 20.5s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 20.8s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 20.5s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 21.0s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 19.9s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 19.9s |  |
| 29 | `as_broadcaster_undef` | 89 | 19.8s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 19.4s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 19.6s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 19.8s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 19.7s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 18.9s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 19.6s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 20.0s |  |
| 37 | `as_transformed_flag` | 20 | 19.9s |  |
| 38 | `asfunction` | 11 | 19.6s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) |
| 39 | `asnative` | 34 | 20.2s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `asnew` | 34 | 19.7s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 41 | `attach_movie` | 59 | 19.3s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 42 | `attach_movie_stop` | 3 | 19.6s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 43 | `bad_placeobject_clipaction` | 2 | 18.5s |  |
| 44 | `bad_swf_tag_past_eof` | 0 | 18.2s |  |
| 45 | `bitand` | 1058 | 21.0s |  |
| 46 | `bitmap_data` | 1126 | 20.7s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 47 | `bitmap_data_colortransform` | 0 | 18.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 48 | `bitmap_data_compare` | 40 | 18.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 49 | `bitmap_data_copypixels` | 17 | 19.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 50 | `bitmap_data_draw_cliprect` | 13 | 18.5s |  |
| 51 | `bitmap_data_fillrect` | 0 | 18.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 52 | `bitmap_data_hittest` | 132 | 18.9s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 53 | `bitmap_data_max_size_swf10` | 12 | 18.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 54 | `bitmap_data_max_size_swf9` | 10 | 18.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 55 | `bitmap_data_noise` | 631 | 18.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 56 | `bitmap_data_perlinnoise` | 0 | 19.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 57 | `bitmap_data_pixeldissolve_image` | 0 | 18.7s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 58 | `bitmap_data_threshold` | 176 | 18.7s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 59 | `bitmapdata_applyfilter_colormatrix` | 0 | 18.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 60 | `bitmapdata_channels` | 19 | 18.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 61 | `bitor` | 1058 | 21.1s |  |
| 62 | `clip_constructors` | 8 | 18.5s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 63 | `clip_event_propagation_order` | 17 | 18.3s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 64 | `clip_events` | 19 | 18.5s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 65 | `clone_sprite_edittext` | 94 | 18.4s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 66 | `clone_sprite_edittext_dynamic` | 86 | 18.4s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 67 | `clone_sprite_types` | 24 | 18.1s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 68 | `closure_scope` | 7 | 18.1s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 69 | `coerce_to_object_monkeypatch` | 129 | 18.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 70 | `coerce_to_primitive_resolve` | 17 | 18.4s | [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 71 | `color` | 57 | 18.5s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 72 | `color_transform` | 48 | 18.4s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 73 | `conflicting_instance_names` | 23 | 18.7s |  |
| 74 | `constructor_function` | 2 | 18.3s |  |
| 75 | `context_menu` | 39 | 18.7s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 76 | `context_menu_item` | 41 | 18.8s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 77 | `create_empty_movie_clip` | 3 | 18.7s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 78 | `cross_movie_root` | 10 | 18.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 79 | `custom_clip_methods` | 4 | 18.5s | [21](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 80 | `default_names` | 52 | 19.2s | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 81 | `define_function2` | 8 | 18.8s |  |
| 82 | `define_function2_preload` | 13 | 18.3s |  |
| 83 | `define_function2_preload_order` | 4 | 18.4s |  |
| 84 | `define_function_case_sensitive` | 2 | 18.3s |  |
| 85 | `define_local` | 27 | 18.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 86 | `define_local_with_paths` | 54 | 18.3s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 87 | `delete` | 3 | 18.4s |  |
| 88 | `device_font_spacing` | 91 | 18.2s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 89 | `displacementmapfilter_mappoint_throw_error` | 13 | 18.1s | [25](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 90 | `display_object_properties` | 2 | 18.0s | [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 91 | `divide_swf4` | 107 | 18.0s |  |
| 92 | `do_init_action` | 3 | 18.0s |  |
| 93 | `do_init_action_child` | 12 | 18.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 94 | `drag_drop` | 10 | 18.1s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 95 | `drag_over_from_outside` | 1 | 18.1s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 96 | `drag_over_without_startdrag` | 1 | 18.2s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 97 | `duplicate_movie_clip` | 20 | 18.2s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 98 | `duplicate_movie_clip_drawing` | 2 | 18.0s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 99 | `edittext_align` | 60 | 18.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 100 | `edittext_align_trailing_spaces_swf7` | 576 | 18.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 101 | `edittext_align_trailing_spaces_swf8` | 576 | 18.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 102 | `edittext_antialiastype` | 296 | 18.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 103 | `edittext_autosize` | 71 | 19.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 104 | `edittext_autosize_setter` | 20 | 18.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 105 | `edittext_bullet` | 30 | 18.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 106 | `edittext_default_format` | 221 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 107 | `edittext_default_format_font_style` | 335 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 108 | `edittext_drag_select` | 9 | 18.3s | [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 109 | `edittext_focus_selection` | 2 | 18.3s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 110 | `edittext_font_size` | 45 | 18.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 111 | `edittext_hscroll` | 27 | 18.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 112 | `edittext_html_align_swf7` | 52 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 113 | `edittext_html_align_swf8` | 52 | 19.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 114 | `edittext_html_color` | 114 | 18.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 115 | `edittext_html_condensewhite_swf7` | 311 | 19.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 116 | `edittext_html_condensewhite_swf8` | 311 | 19.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 117 | `edittext_html_entity` | 4 | 19.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 118 | `edittext_html_roundtrip` | 17 | 19.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 119 | `edittext_html_swf6` | 5377 | 20.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 120 | `edittext_html_swf7` | 5377 | 19.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 121 | `edittext_html_swf8` | 5377 | 19.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 122 | `edittext_input` | 1 | 20.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 123 | `edittext_input_newlines` | 9 | 18.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 124 | `edittext_leading` | 9 | 18.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 125 | `edittext_letter_spacing` | 15 | 18.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 126 | `edittext_margins` | 25 | 18.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 127 | `edittext_newline_stripping` | 64 | 23.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 128 | `edittext_newlines` | 30 | 19.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 129 | `edittext_password` | 5 | 18.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 130 | `edittext_password_copy` | 4 | 18.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 131 | `edittext_paste_empty` | 2 | 18.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 132 | `edittext_place_caret` | 2 | 18.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 133 | `edittext_programmatic_focus` | 12 | 18.9s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 134 | `edittext_restrict` | 191 | 18.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 135 | `edittext_restrict_paste` | 5 | 18.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 136 | `edittext_scroll` | 54 | 19.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 137 | `edittext_stylesheet` | 325 | 19.7s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [24](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 138 | `edittext_tab_focus` | 13 | 18.8s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 139 | `edittext_tab_stops` | 60 | 19.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 140 | `edittext_tag_indent` | 31 | 19.5s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [24](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 141 | `edittext_text_height_leading` | 20 | 19.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 142 | `edittext_underline` | 40 | 19.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 143 | `edittext_width_height` | 103 | 18.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 144 | `empty_movieclip_can_attach_movies` | 11 | 18.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 145 | `enumerate` | 64 | 18.2s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 146 | `equals` | 32 | 18.3s |  |
| 147 | `equals2_swf5` | 926 | 19.9s |  |
| 148 | `equals2_swf6` | 926 | 20.0s |  |
| 149 | `equals2_swf7` | 926 | 20.1s |  |
| 150 | `equals_swf4` | 665 | 19.0s |  |
| 151 | `equals_swf4_alt` | 32 | 18.4s |  |
| 152 | `equals_swf5` | 32 | 18.3s |  |
| 153 | `error` | 58 | 18.3s |  |
| 154 | `escape` | 14 | 18.1s |  |
| 155 | `execution_order1` | 5 | 18.3s |  |
| 156 | `execution_order2` | 7 | 18.5s |  |
| 157 | `execution_order3` | 4 | 18.3s |  |
| 158 | `execution_order4` | 12 | 18.4s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 159 | `export_assets` | 3 | 18.1s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 160 | `extends_chain` | 134 | 18.7s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 161 | `extends_native_type` | 11 | 18.3s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 162 | `external_interface` | 84 | 18.5s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 163 | `external_interface_escapexml` | 26 | 18.2s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 164 | `external_interface_jsquotestring` | 21 | 19.5s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 165 | `external_interface_toas_basic` | 354 | 19.7s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 166 | `external_interface_toxml_array` | 25 | 19.2s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 167 | `external_interface_toxml_basic` | 179 | 19.3s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 168 | `external_interface_unescapexml` | 40 | 19.1s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 169 | `focus_keyboard_press` | 60 | 19.3s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 170 | `focus_mouse` | 45 | 19.1s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 171 | `focus_mouse_focusable` | 8 | 19.8s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 172 | `focus_mouse_rollout` | 4 | 19.1s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 173 | `focus_remove` | 33 | 19.2s |  |
| 174 | `focus_root_movie` | 2 | 19.4s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 175 | `focus_visibility_change` | 45 | 19.2s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 176 | `focusrect_focuslost` | 4 | 19.4s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 177 | `focusrect_mouse_swf8` | 0 | 18.1s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 178 | `focusrect_mouse_swf9` | 0 | 17.9s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 179 | `focusrect_property_swf5` | 1237 | 18.1s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 180 | `focusrect_property_swf6` | 1237 | 18.1s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 181 | `focusrect_property_swf7` | 1237 | 18.1s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 182 | `focusrect_swf5` | 6 | 18.1s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 183 | `focusrect_swf6` | 42 | 17.9s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 184 | `form_loader_encoding_1` | 1 | 17.9s |  |
| 185 | `frame_size_translated_negative` | 21 | 17.9s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 186 | `frame_size_translated_positive` | 21 | 17.9s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 187 | `function_as_function` | 35 | 17.8s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 188 | `function_base_clip` | 8 | 17.9s |  |
| 189 | `function_base_clip_readded` | 11 | 17.9s |  |
| 190 | `function_base_clip_removed` | 25 | 17.9s |  |
| 191 | `function_suppress_and_preload` | 28 | 17.9s |  |
| 192 | `funky_function_calls` | 56 | 17.9s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 193 | `get_bytes_total` | 4 | 17.8s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 194 | `get_variable_in_scope` | 29 | 17.9s |  |
| 195 | `getproperty` | 28 | 18.0s |  |
| 196 | `getproperty_swf4` | 28 | 17.9s |  |
| 197 | `getproperty_swf5` | 28 | 17.9s |  |
| 198 | `gettextextent` | 56 | 17.9s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 199 | `global_array` | 3 | 17.8s |  |
| 200 | `global_is_bare` | 7 | 17.9s |  |
| 201 | `global_swf5_6_7_8_9` | 1145 | 18.5s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 202 | `global_swf6_7_8` | 15 | 18.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 203 | `globals_swf5` | 304 | 18.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 204 | `globals_swf6` | 304 | 18.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 205 | `globals_swf7` | 304 | 18.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 206 | `globals_swf8` | 304 | 18.0s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 207 | `goto_advance1` | 6 | 17.8s |  |
| 208 | `goto_advance2` | 2 | 17.8s |  |
| 209 | `goto_both_ways1` | 3 | 17.9s |  |
| 210 | `goto_both_ways2` | 3 | 17.9s |  |
| 211 | `goto_execution_order` | 2 | 17.8s |  |
| 212 | `goto_execution_order2` | 2 | 19.7s |  |
| 213 | `goto_frame` | 12 | 19.1s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 214 | `goto_frame2` | 44 | 19.2s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 215 | `goto_frame_number` | 3 | 18.8s |  |
| 216 | `goto_label` | 17 | 18.9s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 217 | `goto_methods` | 40 | 18.9s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 218 | `goto_rewind1` | 1 | 18.5s |  |
| 219 | `goto_rewind2` | 3 | 18.7s |  |
| 220 | `goto_rewind3` | 2 | 18.8s |  |
| 221 | `greater_swf6` | 1175 | 21.0s |  |
| 222 | `greater_swf7` | 1175 | 20.9s |  |
| 223 | `greaterthan_swf5` | 1 | 18.8s |  |
| 224 | `greaterthan_swf8` | 1 | 18.7s |  |
| 225 | `has_own_property` | 32 | 18.5s |  |
| 226 | `hittest_lockroot` | 15 | 18.6s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 227 | `hittest_morph` | 70 | 18.3s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 228 | `hittest_morph_input` | 1 | 18.3s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 229 | `hittest_winding_rule` | 12 | 18.5s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 230 | `infinite_recursion_function` | 4 | 18.4s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 231 | `infinite_recursion_function_in_setter` | 131 | 18.6s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 232 | `infinite_recursion_virtual_property` | 67 | 18.6s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 233 | `init_array_invalid` | 4 | 20.4s |  |
| 234 | `init_object_invalid` | 4 | 18.8s |  |
| 235 | `init_object_order` | 15 | 18.8s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 236 | `input_dead_keys_windows` | 15 | 18.9s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 237 | `instanceof_coercions` | 88 | 19.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 238 | `interface_implements_op` | 47 | 19.2s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 239 | `is_finite` | 49 | 18.6s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 240 | `is_finite_swf6` | 49 | 18.6s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 241 | `is_prototype_of` | 89 | 18.8s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 242 | `issue_1086` | 1 | 18.6s |  |
| 243 | `issue_1104` | 2 | 18.9s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 244 | `issue_1671` | 0 | 18.8s |  |
| 245 | `issue_1906` | 4 | 18.7s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 246 | `issue_2030` | 4 | 18.8s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 247 | `issue_2084` | 16 | 18.9s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 248 | `issue_2166` | 9 | 18.7s |  |
| 249 | `issue_2870` | 3 | 18.8s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 250 | `issue_3169` | 2 | 18.7s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 251 | `issue_3446` | 1 | 19.0s |  |
| 252 | `issue_3522` | 2 | 19.2s |  |
| 253 | `issue_4377` | 2 | 19.1s |  |
| 254 | `issue_710` | 4 | 18.5s |  |
| 255 | `issue_768` | 3 | 18.1s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) |
| 256 | `issue_9327` | 2 | 18.1s |  |
| 257 | `issue_9885` | 2 | 18.1s |  |
| 258 | `key_isToggled` | 9 | 18.0s |  |
| 259 | `lessthan` | 41 | 18.0s |  |
| 260 | `lessthan2_swf5` | 1226 | 20.0s |  |
| 261 | `lessthan2_swf6` | 1226 | 20.1s |  |
| 262 | `lessthan2_swf7` | 1226 | 20.1s |  |
| 263 | `lessthan_swf4` | 902 | 19.2s |  |
| 264 | `lessthan_swf4_alt` | 41 | 18.2s |  |
| 265 | `lessthan_swf5` | 41 | 18.1s |  |
| 266 | `loadmovie` | 2 | 18.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 267 | `loadmovie_fail` | 2 | 18.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 268 | `loadmovie_flashvars` | 4 | 18.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 269 | `loadmovie_method` | 2 | 18.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 270 | `loadmovie_registerclass` | 30 | 18.2s | [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 271 | `loadmovie_replace_root` | 5 | 18.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 272 | `loadmovie_var_persistence` | 8 | 18.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 273 | `loadmovienum` | 3 | 18.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 274 | `mcl_getprogress` | 30 | 18.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 275 | `mcl_loadclip` | 149 | 18.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 276 | `mcl_loadclip_properties` | 6 | 18.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 277 | `mcl_loadclip_replace_root` | 1 | 18.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 278 | `mcl_mislabeled_target` | 6 | 18.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 279 | `mcl_target_gif87a` | 6 | 18.7s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 280 | `mcl_target_gif89a` | 6 | 18.8s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 281 | `mcl_target_jpg` | 6 | 18.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 282 | `mcl_target_png` | 6 | 18.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 283 | `mcl_unloadclip` | 5 | 18.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 284 | `mouse_events` | 8 | 18.3s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 285 | `mouse_events_visible_enabled` | 12 | 18.5s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 286 | `mouse_hover_events_while_dragging` | 1 | 18.3s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 287 | `mouse_listeners` | 67 | 18.1s |  |
| 288 | `mouse_pos` | 665 | 18.1s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 289 | `mouse_pos_with_scale_factor` | 260 | 18.1s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 290 | `mouse_wheel_enabled` | 2 | 18.1s |  |
| 291 | `movieclip_begin_gradient_fill` | 0 | 18.9s | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 292 | `movieclip_blend_mode_property` | 35 | 18.3s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 293 | `movieclip_create_text_field` | 90 | 20.0s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 294 | `movieclip_default_state` | 69 | 19.7s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 295 | `movieclip_depth_methods` | 98 | 19.6s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 296 | `movieclip_focusenabled` | 99 | 19.6s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 297 | `movieclip_get_instance_at_depth` | 28 | 19.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 298 | `movieclip_getbounds` | 191 | 20.2s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 299 | `movieclip_gettextsnapshot` | 112 | 19.8s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 300 | `movieclip_hittest` | 92 | 20.3s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 301 | `movieclip_in_removed_button` | 4 | 19.4s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 302 | `movieclip_init_object` | 5 | 19.4s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 303 | `movieclip_invalid_get_bounds_1` | 75 | 19.7s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 304 | `movieclip_invalid_get_bounds_2` | 75 | 19.1s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 305 | `movieclip_invalid_get_bounds_3` | 13 | 19.1s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 306 | `movieclip_invalid_get_bounds_4` | 13 | 18.9s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 307 | `movieclip_invalid_get_bounds_5` | 11 | 18.9s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 308 | `movieclip_invalid_get_bounds_6` | 10 | 42.9s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 309 | `movieclip_invalid_get_bounds_7` | 10 | 42.1s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 310 | `movieclip_invalid_get_bounds_8` | 11 | 18.5s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 311 | `movieclip_line_gradient_style` | 0 | 18.6s | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 312 | `movieclip_lockroot` | 29 | 19.7s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 313 | `movieclip_name_from_timeline` | 13 | 19.1s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 314 | `movieclip_prototype_extension` | 5 | 19.3s |  |
| 315 | `movieclip_setmask` | 14 | 19.6s | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_SETMASK_PLAN.md) |
| 316 | `moviecliploader_flashvars` | 4 | 19.0s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 317 | `mutable_this` | 18 | 18.9s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 318 | `named_shapes` | 14 | 18.9s |  |
| 319 | `nan_scale` | 9 | 18.9s |  |
| 320 | `native_double_construct` | 12 | 19.0s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 321 | `native_subclasses` | 191 | 18.8s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 322 | `nested_textfields_in_buttons` | 0 | 18.9s |  |
| 323 | `new_method_wrap` | 4 | 18.0s |  |
| 324 | `new_object_enumerate` | 7 | 17.8s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 325 | `new_object_wrap` | 4 | 17.8s |  |
| 326 | `o` | 3 | 17.8s |  |
| 327 | `object_constructor` | 33 | 17.8s |  |
| 328 | `object_function` | 32 | 17.8s |  |
| 329 | `object_properties` | 31 | 18.0s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 330 | `object_prototypes` | 74 | 17.9s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 331 | `object_resolve` | 38 | 18.0s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 332 | `object_string_coerce_swf5` | 62 | 17.9s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 333 | `object_string_coerce_swf6` | 68 | 17.9s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 334 | `on_construct` | 25 | 17.9s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 335 | `parse_float` | 74 | 17.8s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 336 | `parse_int` | 64 | 18.1s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 337 | `path_string` | 322 | 18.0s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 338 | `place_and_lookup` | 30 | 17.8s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 339 | `placeobject_occupied_depth` | 6 | 17.8s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 340 | `point` | 175 | 18.2s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 341 | `primitive_instanceof` | 37 | 17.8s |  |
| 342 | `primitive_type_globals` | 557 | 17.9s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 343 | `printjob_props_swf5` | 45 | 17.8s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 344 | `printjob_props_swf6` | 45 | 19.6s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 345 | `printjob_props_swf7` | 45 | 18.5s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 346 | `property_invalid_base_clip` | 36 | 18.8s |  |
| 347 | `prototype_delete` | 12 | 18.9s |  |
| 348 | `prototype_enumerate` | 5 | 18.7s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 349 | `prototype_properties` | 17 | 18.7s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 350 | `rectangle` | 745 | 19.3s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 351 | `recursive_prototypes` | 0 | 18.3s |  |
| 352 | `register_and_init_order` | 231 | 18.9s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 353 | `register_class` | 66 | 18.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 354 | `register_class_return_value` | 16 | 18.6s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 355 | `register_class_swf6` | 37 | 18.7s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 356 | `register_class_with_sound` | 11 | 18.4s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 357 | `register_globals_across_frames` | 15 | 18.6s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 358 | `register_underflow` | 26 | 18.4s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 359 | `remove_movie_clip` | 29 | 18.6s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 360 | `removed_clip_halts_script` | 15 | 18.7s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 361 | `removed_target_clip_scope` | 35 | 18.4s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 362 | `resolve_different_root` | 2 | 18.5s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 363 | `rewind_depth` | 30 | 19.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 364 | `root_button_mode` | 10 | 18.7s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 365 | `root_global_parent` | 6 | 18.4s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 366 | `root_onload` | 1 | 18.3s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 367 | `sandbox_type_local_file` | 1 | 18.2s |  |
| 368 | `sandbox_type_local_network` | 1 | 18.5s |  |
| 369 | `selection` | 454 | 18.5s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 370 | `selection_handlers` | 27 | 18.4s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 371 | `set_interval` | 27 | 18.3s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 372 | `set_variable_scope` | 58 | 18.2s |  |
| 373 | `single_frame` | 1 | 18.1s |  |
| 374 | `slash_syntax` | 14 | 18.1s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 375 | `sound` | 628 | 18.9s | [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 376 | `sound_props_swf5` | 68 | 18.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 377 | `sound_props_swf6` | 68 | 18.6s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 378 | `sound_start_load` | 0 | 17.7s |  |
| 379 | `stage_display_state` | 16 | 17.7s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 380 | `stage_object_children` | 83 | 17.7s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 381 | `stage_object_enumerate` | 4 | 17.7s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 382 | `stage_object_properties` | 241 | 18.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 383 | `stage_object_properties_get_var` | 5 | 17.6s |  |
| 384 | `stage_object_properties_swf6` | 231 | 18.0s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 385 | `stage_property_representation` | 586 | 17.8s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 386 | `stage_scale_mode` | 39 | 17.8s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 387 | `strictequals_swf6` | 902 | 19.2s |  |
| 388 | `strictly_equals` | 7 | 17.8s |  |
| 389 | `string_coercion` | 117 | 18.0s | [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) |
| 390 | `string_methods` | 285 | 18.3s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 391 | `string_methods_negative_args` | 240 | 17.9s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 392 | `string_methods_swfv5` | 275 | 18.4s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 393 | `string_ops_swf6` | 95 | 17.7s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 394 | `string_paths_basic` | 4 | 17.7s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 395 | `string_paths_eval` | 4 | 17.8s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 396 | `string_paths_eval2` | 7 | 17.9s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 397 | `string_paths_hidden` | 54 | 17.9s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 398 | `string_paths_keyevents` | 0 | 17.6s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 399 | `string_paths_other` | 36 | 17.9s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 400 | `string_paths_timer` | 0 | 17.2s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 401 | `string_paths_unload` | 1 | 17.4s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 402 | `string_paths_variable_alias` | 4 | 17.1s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 403 | `string_paths_variable_scopes` | 5 | 17.0s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 404 | `stylesheet` | 283 | 18.0s |  |
| 405 | `stylesheet_transform` | 750 | 18.5s |  |
| 406 | `super_edge_cases` | 39 | 17.8s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 407 | `swf4_actions_bool` | 96 | 17.5s |  |
| 408 | `swf4_actions_coercion_order` | 158 | 17.6s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 409 | `swf4_bool` | 4 | 17.2s |  |
| 410 | `swf4_function_calls` | 7 | 17.1s |  |
| 411 | `swf5_encoding` | 3 | 17.4s |  |
| 412 | `swf5_global_funcs` | 232 | 17.7s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 413 | `swf5_no_closure` | 19 | 17.1s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 414 | `swf5_to_6_cross_call` | 29 | 18.7s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 415 | `swf6_case_insensitive` | 42 | 18.4s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 416 | `swf6_global_funcs` | 232 | 18.5s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 417 | `swf6_string_as_bool` | 15 | 18.4s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 418 | `swf6_to_5_cross_call` | 29 | 18.6s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 419 | `swf7_case_sensitive` | 44 | 18.5s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 420 | `swf7_global_funcs` | 232 | 18.6s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 421 | `tab_ordering_automatic_basic` | 92 | 18.6s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 422 | `tab_ordering_automatic_order_grid` | 21 | 18.5s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 423 | `tab_ordering_automatic_order_same_position` | 12 | 18.4s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 424 | `tab_ordering_children` | 208 | 18.6s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 425 | `tab_ordering_custom_basic` | 71 | 18.6s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 426 | `tab_ordering_custom_duplicate_index` | 22 | 18.6s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 427 | `tab_ordering_custom_i32_vs_u32` | 12 | 18.6s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 428 | `tab_ordering_custom_m1` | 29 | 18.6s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 429 | `tab_ordering_events` | 150 | 19.1s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 430 | `tab_ordering_events_mouse` | 65 | 19.0s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 431 | `tab_ordering_movieclip_enabled_default` | 462 | 19.1s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 432 | `tab_ordering_properties` | 293 | 19.0s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 433 | `tab_ordering_reverse` | 51 | 18.5s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 434 | `tab_ordering_tabbable` | 47 | 18.4s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 435 | `target_clip_removed` | 5 | 18.3s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 436 | `target_clip_swf5` | 2 | 18.2s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 437 | `target_clip_swf6` | 2 | 18.3s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 438 | `target_path` | 14 | 18.2s |  |
| 439 | `tell_target` | 37 | 18.4s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 440 | `tell_target_invalid` | 6 | 18.4s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 441 | `tell_target_invalid_swf6` | 5 | 18.4s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 442 | `text_blocks_clicks` | 4 | 18.2s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 443 | `text_format` | 1146 | 18.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 444 | `text_format_display` | 21 | 18.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 445 | `text_format_font_max_length` | 2 | 18.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 446 | `text_format_get_text_extent_undefined_width` | 10 | 18.6s |  |
| 447 | `text_format_rounding_swf7` | 840 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 448 | `text_format_rounding_swf8` | 840 | 18.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 449 | `textfield_background_color` | 11 | 18.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 450 | `textfield_border_color` | 11 | 18.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 451 | `textfield_cache_as_bitmap` | 1 | 18.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 452 | `textfield_maxchars` | 3 | 19.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 453 | `textfield_properties` | 44 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 454 | `textfield_props_swf5` | 175 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 455 | `textfield_props_swf6` | 210 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 456 | `textfield_props_swf7` | 210 | 18.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 457 | `textfield_props_swf8` | 210 | 18.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 458 | `textfield_text` | 7 | 18.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 459 | `textfield_variable` | 81 | 18.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 460 | `textsnapshot_available_text` | 20 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 461 | `textsnapshot_findtext` | 44 | 18.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 462 | `textsnapshot_gettext` | 55 | 18.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 463 | `textsnapshot_props_swf5` | 56 | 18.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 464 | `textsnapshot_props_swf6` | 56 | 18.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 465 | `textsnapshot_text_order` | 1 | 18.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 466 | `this_scoping` | 52 | 18.3s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 467 | `this_swf5` | 41 | 18.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 468 | `this_swf6` | 41 | 18.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 469 | `this_swf7` | 41 | 18.3s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) |
| 470 | `timeline_function_def` | 7 | 18.5s |  |
| 471 | `timer_run_actions` | 18 | 18.2s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 472 | `trace` | 8 | 18.1s |  |
| 473 | `transform` | 70 | 18.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 474 | `try_catch_finally` | 118 | 18.8s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 475 | `try_finally_simple` | 16 | 18.9s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 476 | `typeof` | 22 | 18.8s |  |
| 477 | `typeof_globals` | 7 | 18.8s |  |
| 478 | `uncaught_exception` | 1 | 18.9s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 479 | `uncaught_exception_bubbled` | 1 | 18.9s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 480 | `undefined_to_string_swf6` | 4 | 18.0s |  |
| 481 | `unescape` | 43 | 18.1s |  |
| 482 | `unload` | 52 | 18.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 483 | `unload_clip_event` | 4 | 18.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 484 | `unload_nested_child` | 5 | 18.1s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 485 | `unloadmovie` | 4 | 18.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 486 | `unloadmovie_method` | 3 | 18.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 487 | `unloadmovienum` | 13 | 18.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 488 | `use_hand_cursor` | 8 | 18.3s |  |
| 489 | `variable_args` | 5 | 18.4s |  |
| 490 | `waitforframe` | 7 | 18.4s |  |
| 491 | `waitforframe2` | 16 | 18.2s |  |
| 492 | `watch` | 117 | 18.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 493 | `watch_textfield` | 12 | 17.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 494 | `watch_virtual_property_proto` | 2 | 17.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 495 | `with` | 49 | 17.9s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 496 | `with_return` | 2 | 17.9s |  |
| 497 | `with_variable_scopes` | 43 | 18.0s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 498 | `xml` | 15 | 18.0s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 499 | `xml_append_child` | 28 | 17.9s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 500 | `xml_append_child_with_parent` | 20 | 17.9s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 501 | `xml_attributes_read` | 4 | 17.9s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 502 | `xml_cdata` | 11 | 17.9s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 503 | `xml_child_nodes_edge_cases` | 4 | 17.9s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 504 | `xml_clone_expandos` | 19 | 18.1s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 505 | `xml_first_last_child` | 8 | 18.0s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 506 | `xml_has_child_nodes` | 3 | 17.8s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 507 | `xml_idmap` | 21 | 17.9s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 508 | `xml_ignore_comments` | 21 | 17.9s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 509 | `xml_ignore_white` | 34 | 18.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 510 | `xml_insert_before` | 20 | 18.3s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 511 | `xml_inspect_createmethods` | 15 | 18.3s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 512 | `xml_inspect_doctype` | 7 | 18.2s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 513 | `xml_inspect_parsexml` | 62 | 18.1s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 514 | `xml_inspect_xmldecl` | 7 | 18.1s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 515 | `xml_namespaces` | 203 | 18.1s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 516 | `xml_parent_and_child` | 5 | 18.2s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 517 | `xml_remove_node` | 22 | 18.3s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 518 | `xml_reparenting` | 14 | 18.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 519 | `xml_siblings` | 10 | 18.3s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 520 | `xml_to_string` | 13 | 18.2s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 521 | `xml_to_string_comment` | 1 | 18.1s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 522 | `xml_unescaping` | 23 | 18.3s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 523 | `xmlnode_proto` | 1 | 18.3s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `movieclip_hittest_shapeflag` | 96.4% | 326 | 338 | 12 | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [98](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/VECTOR_PATH_HITTEST_PLAN.md) |
| 2 | `native_objects_swf7` | 91.3% | 105 | 115 | 10 | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `native_objects_swf8` | 89.6% | 103 | 115 | 12 | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**3 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_hittest_shapeflag` | 96.4% | 326/338 | 338 | 338 | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [98](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/VECTOR_PATH_HITTEST_PLAN.md) |
| 2 | `native_objects_swf7` | 91.3% | 105/115 | 115 | 115 | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `native_objects_swf8` | 89.6% | 103/115 | 115 | 115 | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) | 15 | 15 | 0 |
| 6 | [BITMAP_FILTER_CLONE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTER_CLONE_PLAN.md) | 0 | 0 | 0 |
| 7 | [BITMAP_FILTERS_MCFILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_MCFILTERS_PLAN.md) | 0 | 0 | 0 |
| 8 | [BITMAP_FILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_PLAN.md) | 0 | 0 | 0 |
| 9 | [BITMAPDATA_APPLYFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_APPLYFILTER_PLAN.md) | 0 | 0 | 0 |
| 10 | [BITMAPDATA_PERLINNOISE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PERLINNOISE_PLAN.md) | 0 | 0 | 0 |
| 11 | [BITMAPDATA_PIXELDISSOLVE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PIXELDISSOLVE_PLAN.md) | 0 | 0 | 0 |
| 12 | [BITMAPDATA_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) | 6 | 6 | 0 |
| 13 | [BUTTON_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) | 2 | 2 | 0 |
| 14 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 1 | 1 | 0 |
| 15 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) | 8 | 8 | 0 |
| 16 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 4 | 0 |
| 17 | [COLOR_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) | 4 | 4 | 0 |
| 18 | [COPYPIXELS_ALPHA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COPYPIXELS_ALPHA_PLAN.md) | 0 | 0 | 0 |
| 19 | [CREATETEXTFIELD_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 20 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 1 | 1 | 0 |
| 21 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 22 | [DATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) | 0 | 0 | 0 |
| 23 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 24 | [DEVICE_FONT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) | 2 | 2 | 0 |
| 25 | [DISPLACEMENTMAPFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) | 1 | 1 | 0 |
| 26 | [DRAG_DROP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 27 | [DRAWING_API_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) | 3 | 3 | 0 |
| 28 | [EDITTEXT_DRAG_SELECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) | 1 | 1 | 0 |
| 29 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 30 | [ENUMERATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 31 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 32 | [FILLRECT_COLOR_CONSTANT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FILLRECT_COLOR_CONSTANT_PLAN.md) | 0 | 0 | 0 |
| 33 | [FLV_PLAYBACK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/FLV_PLAYBACK_PLAN.md) | 0 | 0 | 0 |
| 34 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 4 | 0 |
| 35 | [FOCUS_RECT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 36 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 7 | 0 |
| 37 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 38 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 3 | 0 |
| 39 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 4 | 4 | 0 |
| 40 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 41 | [GLOBALS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) | 25 | 23 | 2 |
| 42 | [HIT_TESTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) | 16 | 15 | 1 |
| 43 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 0 | 0 | 0 |
| 44 | [infinite_recursion_function.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 45 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 46 | [issue_768.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 47 | [LOADBITMAP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADBITMAP_PLAN.md) | 0 | 0 | 0 |
| 48 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 49 | [LOADMOVIE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) | 36 | 36 | 0 |
| 50 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 1 | 1 | 0 |
| 51 | [LOADVARIABLES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) | 0 | 0 | 0 |
| 52 | [LOCALCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) | 0 | 0 | 0 |
| 53 | [LOCKROOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 54 | [MATH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) | 0 | 0 | 0 |
| 55 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 56 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 4 | 4 | 0 |
| 57 | [MOVIECLIP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) | 53 | 52 | 1 |
| 58 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 12 | 12 | 0 |
| 59 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 15 | 13 | 2 |
| 60 | [NETCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) | 0 | 0 | 0 |
| 61 | [object_string_coerce.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 62 | [OBJECT_WATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) | 3 | 3 | 0 |
| 63 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 64 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 65 | [PIXEL_TEXT_LAYOUT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) | 2 | 2 | 0 |
| 66 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 67 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 11 | 11 | 0 |
| 68 | [REGISTERCLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) | 15 | 15 | 0 |
| 69 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 2 | 2 | 0 |
| 70 | [RUNTIME_CXFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 71 | [RUNTIME_SETMASK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_SETMASK_PLAN.md) | 1 | 1 | 0 |
| 72 | [RUNTIME_TRANSFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 73 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 74 | [SELECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) | 4 | 4 | 0 |
| 75 | [SOUND_CLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 76 | [SOUND_DURATION_POSITION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) | 0 | 0 | 0 |
| 77 | [SOUND_ID3_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/SOUND_ID3_PLAN.md) | 0 | 0 | 0 |
| 78 | [SOUND_LOADING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) | 0 | 0 | 0 |
| 79 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 80 | [STAGE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 81 | [string_coercion.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 82 | [STRING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) | 12 | 12 | 0 |
| 83 | [STYLESHEET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 84 | [SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) | 0 | 0 | 0 |
| 85 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 5 | 0 |
| 86 | [TAB_ORDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 16 | 0 |
| 87 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 1 | 0 |
| 88 | [TELLTARGET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) | 17 | 17 | 0 |
| 89 | [TEXTFIELD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) | 68 | 68 | 0 |
| 90 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 91 | [THIS_BINDING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 92 | [this_swf7.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 93 | [TIMER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) | 2 | 2 | 0 |
| 94 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 4 | 4 | 0 |
| 95 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 2 | 0 |
| 96 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 13 | 13 | 0 |
| 97 | [UNLOAD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) | 12 | 12 | 0 |
| 98 | [VECTOR_PATH_HITTEST_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/VECTOR_PATH_HITTEST_PLAN.md) | 1 | 0 | 1 |
| 99 | [WITH_SCOPE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 100 | [XML_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) | 26 | 26 | 0 |
| | *(tests not in any document)* | 135 | 135 | 0 |
