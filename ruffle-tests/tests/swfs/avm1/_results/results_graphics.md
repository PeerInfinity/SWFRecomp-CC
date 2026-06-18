# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-18 22:05 UTC

**Git SHA**: `fe0030e4fc`

**Run Duration**: 43m 18s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 514 |
| Passing | **450** (87.5%) |
| Ruffle-matched | 11 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **461** (89.7%) |
| Failing | 53 |
| Total expected lines | 106882 |
| Matching lines | 90620 (84.8%) |
| Mismatched lines | 16262 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 48 | 90.6% |
| Runtime Segfault | 5 | 9.4% |

## Passing Tests

**450 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.9s |  |
| 2 | `action_to_integer` | 28 | 1.9s |  |
| 3 | `add` | 28 | 1.9s |  |
| 4 | `add2` | 354 | 2.2s | [1](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 1.9s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 0.9s |  |
| 7 | `add_swf5` | 28 | 0.9s |  |
| 8 | `arguments` | 127 | 1.9s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 1.9s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 1.9s |  |
| 11 | `array_constructor` | 30 | 1.9s |  |
| 12 | `array_enumerate` | 4 | 2.2s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 1.9s |  |
| 14 | `array_properties` | 36 | 0.9s |  |
| 15 | `array_prototyping` | 12 | 1.9s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 1.9s |  |
| 17 | `array_sort` | 161 | 2.8s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 2.1s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 2.0s |  |
| 20 | `array_trivial` | 209 | 2.0s |  |
| 21 | `as1_constructor_v6` | 35 | 1.5s |  |
| 22 | `as1_constructor_v7` | 35 | 0.8s |  |
| 23 | `as2_oop` | 13 | 1.8s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 1.8s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 1.6s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 1.8s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 1.7s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 1.5s |  |
| 29 | `as_broadcaster_undef` | 89 | 1.6s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 1.6s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 1.5s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 1.5s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 1.5s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 1.1s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 0.7s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 0.9s |  |
| 37 | `as_transformed_flag` | 20 | 1.6s |  |
| 38 | `asfunction` | 11 | 1.8s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) |
| 39 | `asnative` | 34 | 2.1s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `asnew` | 34 | 16.5s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 41 | `assetnative` | 81 | 1.6s |  |
| 42 | `assetnative_ids` | 10 | 1.5s |  |
| 43 | `assetnativeaccessor` | 81 | 1.6s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASSETNATIVEACCESSOR_PLAN.md) |
| 44 | `assetnativeaccessor_ids` | 21 | 8.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASSETNATIVEACCESSOR_PLAN.md) |
| 45 | `attach_movie` | 59 | 2.4s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 46 | `attach_movie_stop` | 3 | 23.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 47 | `bad_placeobject_clipaction` | 2 | 2.2s |  |
| 48 | `bad_swf_tag_past_eof` | 0 | 2.0s |  |
| 49 | `bitand` | 1058 | 5.3s |  |
| 50 | `bitmap_data` | 1126 | 5.0s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 51 | `bitmap_data_colortransform` | 0 | 3.0s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 52 | `bitmap_data_compare` | 40 | 2.4s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 53 | `bitmap_data_copypixels` | 17 | 25.0s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 54 | `bitmap_data_draw_cliprect` | 13 | 22.7s |  |
| 55 | `bitmap_data_fillrect` | 0 | 2.6s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 56 | `bitmap_data_hittest` | 132 | 2.8s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 57 | `bitmap_data_max_size_swf10` | 12 | 2.1s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 58 | `bitmap_data_max_size_swf9` | 10 | 2.0s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 59 | `bitmap_data_noise` | 631 | 2.4s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 60 | `bitmap_data_perlinnoise` | 0 | 24.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 61 | `bitmap_data_pixeldissolve` | 1075 | 3.2s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 62 | `bitmap_data_pixeldissolve_image` | 0 | 23.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 63 | `bitmap_data_thorough/colorTransform` | 279 | 2.7s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 64 | `bitmap_data_thorough/compare` | 69 | 2.8s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 65 | `bitmap_data_thorough/constructor` | 313 | 2.7s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 66 | `bitmap_data_thorough/copyChannel` | 2715 | 2.8s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 67 | `bitmap_data_thorough/fillRect` | 342 | 6.8s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 68 | `bitmap_data_thorough/floodFill` | 867 | 2.4s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 69 | `bitmap_data_thorough/getColorBoundsRect` | 285 | 2.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 70 | `bitmap_data_thorough/getPixel` | 141 | 2.2s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 71 | `bitmap_data_thorough/getPixel32` | 141 | 2.3s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 72 | `bitmap_data_thorough/hitTest` | 519 | 2.5s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 73 | `bitmap_data_thorough/merge` | 1203 | 2.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 74 | `bitmap_data_thorough/noise` | 1518 | 2.5s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 75 | `bitmap_data_thorough/scroll` | 384 | 2.5s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 76 | `bitmap_data_thorough/setPixel` | 531 | 2.2s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 77 | `bitmap_data_thorough/setPixel32` | 531 | 2.2s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 78 | `bitmap_data_thorough/threshold` | 1308 | 2.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 79 | `bitmap_data_threshold` | 176 | 2.4s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 80 | `bitmap_filters` | 548 | 4.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTER_CLONE_PLAN.md) [9](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_MCFILTERS_PLAN.md) [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_PLAN.md) [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 81 | `bitmapdata_applyfilter_colormatrix` | 0 | 21.1s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 82 | `bitmapdata_channels` | 19 | 1.8s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 83 | `bitor` | 1058 | 4.6s |  |
| 84 | `biturshift` | 14 | 1.8s |  |
| 85 | `biturshift_swf8` | 14 | 0.9s |  |
| 86 | `bitxor` | 1058 | 4.7s |  |
| 87 | `boxed_primitives` | 24 | 2.0s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 88 | `display_object_properties` | 2 | 8.0s | [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 89 | `divide_swf4` | 107 | 2.1s |  |
| 90 | `do_init_action` | 3 | 21.7s |  |
| 91 | `do_init_action_child` | 12 | 2.1s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 92 | `drag_drop` | 10 | 2.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 93 | `drag_over_from_outside` | 1 | 20.8s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 94 | `drag_over_without_startdrag` | 1 | 2.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 95 | `duplicate_movie_clip` | 20 | 2.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 96 | `duplicate_movie_clip_drawing` | 2 | 1.9s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 97 | `edittext_align` | 60 | 2.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 98 | `edittext_align_trailing_spaces_swf7` | 576 | 20.7s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 99 | `edittext_align_trailing_spaces_swf8` | 576 | 1.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 100 | `edittext_antialiastype` | 296 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 101 | `edittext_autosize` | 71 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 102 | `edittext_autosize_setter` | 20 | 2.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 103 | `edittext_bullet` | 30 | 2.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 104 | `edittext_default_format` | 221 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 105 | `edittext_default_format_empty` | 100 | 2.0s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 106 | `edittext_default_format_font_style` | 335 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 107 | `edittext_drag_select` | 9 | 20.8s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 108 | `edittext_focus_selection` | 2 | 1.9s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 109 | `edittext_font_size` | 45 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 110 | `edittext_hscroll` | 27 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 111 | `edittext_html_align_swf7` | 52 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 112 | `edittext_html_align_swf8` | 52 | 7.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 113 | `edittext_html_color` | 114 | 2.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 114 | `edittext_html_condensewhite_swf7` | 311 | 2.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 115 | `edittext_html_condensewhite_swf8` | 311 | 1.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 116 | `edittext_html_entity` | 4 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 117 | `edittext_html_roundtrip` | 17 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 118 | `edittext_html_swf6` | 5377 | 3.6s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 119 | `edittext_html_swf7` | 5377 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 120 | `edittext_html_swf8` | 5377 | 1.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 121 | `edittext_ime_focus_lost` | 7 | 20.5s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 122 | `edittext_input` | 1 | 20.7s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 123 | `edittext_input_newlines` | 9 | 20.6s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 124 | `edittext_leading` | 9 | 2.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 125 | `edittext_letter_spacing` | 15 | 2.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 126 | `edittext_margins` | 25 | 2.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 127 | `edittext_newline_stripping` | 64 | 6.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 128 | `edittext_newlines` | 30 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 129 | `edittext_password` | 5 | 2.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 130 | `edittext_password_copy` | 4 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 131 | `edittext_paste_empty` | 2 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 132 | `edittext_place_caret` | 2 | 20.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 133 | `edittext_programmatic_focus` | 12 | 1.9s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 134 | `edittext_restrict` | 191 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 135 | `edittext_restrict_paste` | 5 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 136 | `extends_chain` | 134 | 7.1s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 137 | `extends_native_type` | 11 | 2.3s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 138 | `external_interface` | 84 | 2.1s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 139 | `external_interface_escapexml` | 26 | 2.0s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 140 | `external_interface_jsquotestring` | 21 | 2.0s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 141 | `external_interface_toas_basic` | 354 | 2.3s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 142 | `external_interface_toxml_array` | 25 | 1.8s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 143 | `external_interface_toxml_basic` | 179 | 2.1s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 144 | `external_interface_unescapexml` | 40 | 1.9s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 145 | `focus_keyboard_press` | 60 | 2.4s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 146 | `focus_mouse` | 45 | 2.1s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 147 | `focus_mouse_focusable` | 8 | 22.5s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 148 | `focus_mouse_rollout` | 4 | 2.0s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 149 | `focus_remove` | 33 | 26.3s |  |
| 150 | `focus_root_movie` | 2 | 2.3s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 151 | `focus_visibility_change` | 45 | 2.0s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 152 | `focusrect_focuslost` | 4 | 21.7s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 153 | `focusrect_mouse_swf8` | 0 | 2.4s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 154 | `focusrect_mouse_swf9` | 0 | 1.2s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 155 | `focusrect_property_swf5` | 1237 | 2.6s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 156 | `focusrect_property_swf6` | 1237 | 1.1s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 157 | `focusrect_property_swf7` | 1237 | 2.0s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 158 | `focusrect_swf5` | 6 | 22.1s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 159 | `focusrect_swf6` | 42 | 2.4s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 160 | `form_loader_encoding_1` | 1 | 1.9s |  |
| 161 | `frame_size_translated_negative` | 21 | 21.4s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 162 | `frame_size_translated_positive` | 21 | 21.0s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 163 | `function_as_function` | 35 | 1.9s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 164 | `function_base_clip` | 8 | 20.8s |  |
| 165 | `function_base_clip_readded` | 11 | 2.2s |  |
| 166 | `function_base_clip_removed` | 25 | 21.0s |  |
| 167 | `function_suppress_and_preload` | 28 | 20.9s |  |
| 168 | `funky_function_calls` | 56 | 1.9s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 169 | `get_bytes_total` | 4 | 21.0s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 170 | `get_variable_in_scope` | 29 | 2.1s |  |
| 171 | `getproperty` | 28 | 1.5s |  |
| 172 | `getproperty_swf4` | 28 | 0.8s |  |
| 173 | `getproperty_swf5` | 28 | 0.8s |  |
| 174 | `gettextextent` | 56 | 1.8s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 175 | `global_array` | 3 | 1.5s |  |
| 176 | `global_is_bare` | 7 | 1.7s |  |
| 177 | `global_swf5_6_7_8_9` | 1145 | 2.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 178 | `global_swf6_7_8` | 15 | 2.1s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 179 | `globals_swf6` | 304 | 0.8s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 180 | `globals_swf7` | 304 | 0.8s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 181 | `globals_swf8` | 304 | 0.8s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 182 | `goto_advance1` | 6 | 16.4s |  |
| 183 | `goto_advance2` | 2 | 1.6s |  |
| 184 | `goto_both_ways1` | 3 | 1.6s |  |
| 185 | `goto_both_ways2` | 3 | 16.2s |  |
| 186 | `goto_execution_order` | 2 | 28.3s |  |
| 187 | `goto_execution_order2` | 2 | 19.8s |  |
| 188 | `goto_frame` | 12 | 2.1s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 189 | `goto_frame2` | 44 | 20.6s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 190 | `goto_frame_number` | 3 | 2.0s |  |
| 191 | `goto_label` | 17 | 20.2s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 192 | `goto_methods` | 40 | 1.9s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 193 | `goto_rewind1` | 1 | 19.8s |  |
| 194 | `goto_rewind2` | 3 | 1.8s |  |
| 195 | `goto_rewind3` | 2 | 1.9s |  |
| 196 | `greater_swf6` | 1175 | 3.7s |  |
| 197 | `greater_swf7` | 1175 | 0.9s |  |
| 198 | `greaterthan_swf5` | 1 | 1.8s |  |
| 199 | `greaterthan_swf8` | 1 | 1.7s |  |
| 200 | `has_own_property` | 32 | 1.7s |  |
| 201 | `hittest_lockroot` | 15 | 2.1s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 202 | `hittest_morph` | 70 | 1.9s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 203 | `hittest_morph_input` | 1 | 1.8s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 204 | `hittest_winding_rule` | 12 | 20.1s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 205 | `infinite_recursion_function` | 4 | 1.7s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 206 | `infinite_recursion_function_in_setter` | 131 | 1.7s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 207 | `infinite_recursion_virtual_property` | 67 | 1.7s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 208 | `init_array_invalid` | 4 | 19.7s |  |
| 209 | `init_object_invalid` | 4 | 14.1s |  |
| 210 | `init_object_order` | 15 | 1.5s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 211 | `input_dead_keys_windows` | 15 | 2.0s | [50](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 212 | `instanceof_coercions` | 88 | 1.7s | [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 213 | `interface_implements_op` | 47 | 1.8s | [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 214 | `is_finite` | 49 | 1.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 215 | `is_finite_swf6` | 49 | 0.7s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 216 | `is_prototype_of` | 89 | 1.5s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 217 | `issue_1086` | 1 | 1.3s |  |
| 218 | `issue_1104` | 2 | 13.6s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 219 | `issue_1671` | 0 | 1.3s |  |
| 220 | `issue_1906` | 4 | 1.3s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 221 | `issue_2030` | 4 | 1.3s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 222 | `issue_2084` | 16 | 13.9s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 223 | `issue_2166` | 9 | 1.3s |  |
| 224 | `issue_2870` | 3 | 1.5s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 225 | `issue_3169` | 2 | 1.4s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 226 | `issue_3446` | 1 | 1.3s |  |
| 227 | `issue_3522` | 2 | 1.5s |  |
| 228 | `issue_4377` | 2 | 1.4s |  |
| 229 | `issue_710` | 4 | 1.2s |  |
| 230 | `issue_768` | 3 | 1.2s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) |
| 231 | `issue_9327` | 2 | 1.5s |  |
| 232 | `loadvariables2` | 8 | 25.2s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 233 | `loadvariablesnum` | 2 | 2.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 234 | `loadvars_tostring` | 5 | 2.0s |  |
| 235 | `local_to_global` | 49 | 2.1s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 236 | `localconnection_properties` | 8 | 2.0s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 237 | `lock_root` | 1 | 2.0s |  |
| 238 | `logical_ops_swf4` | 90 | 2.0s |  |
| 239 | `logical_ops_swf8` | 108 | 2.0s |  |
| 240 | `looping` | 6 | 21.2s |  |
| 241 | `looping_real_1_declared_1` | 1 | 1.9s |  |
| 242 | `looping_real_1_declared_2` | 1 | 1.0s |  |
| 243 | `looping_real_2_declared_1` | 5 | 2.0s |  |
| 244 | `looping_real_2_declared_2` | 5 | 1.0s |  |
| 245 | `mask_reapply` | 0 | 21.3s | [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 246 | `mask_with_drawing` | 0 | 21.2s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 247 | `math_min_max` | 101 | 2.0s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 248 | `math_swf6` | 530 | 2.5s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 249 | `math_swf7` | 530 | 1.0s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 250 | `math_swf8` | 530 | 4.5s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 251 | `matrix` | 171 | 2.3s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 252 | `mcl_as_broadcaster` | 12 | 2.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 253 | `mcl_events_swf_version` | 232 | 3.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 254 | `mcl_getprogress` | 30 | 21.9s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 255 | `mcl_loadclip` | 149 | 22.3s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 256 | `mcl_loadclip_properties` | 6 | 2.3s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 257 | `mcl_loadclip_replace_root` | 1 | 2.2s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 258 | `mcl_mislabeled_target` | 6 | 2.5s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 259 | `mcl_target_gif87a` | 6 | 2.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 260 | `mcl_target_gif89a` | 6 | 1.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 261 | `mcl_target_jpg` | 6 | 1.5s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 262 | `mcl_target_png` | 6 | 1.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 263 | `mcl_unloadclip` | 5 | 21.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 264 | `mouse_events` | 8 | 21.7s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 265 | `mouse_events_visible_enabled` | 12 | 22.9s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 266 | `mouse_hover_events_while_dragging` | 1 | 21.5s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 267 | `mouse_listeners` | 67 | 2.0s |  |
| 268 | `mouse_pos` | 665 | 21.7s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 269 | `mouse_pos_with_scale_factor` | 260 | 21.5s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 270 | `mouse_wheel_enabled` | 2 | 2.0s |  |
| 271 | `movieclip_begin_gradient_fill` | 0 | 23.8s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 272 | `movieclip_blend_mode_property` | 35 | 2.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 273 | `movieclip_create_text_field` | 90 | 20.8s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 274 | `movieclip_default_state` | 69 | 2.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 275 | `movieclip_depth_methods` | 98 | 20.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 276 | `movieclip_focusenabled` | 99 | 1.9s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 277 | `movieclip_get_instance_at_depth` | 28 | 1.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 278 | `movieclip_getbounds` | 191 | 2.1s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 279 | `movieclip_gettextsnapshot` | 112 | 2.0s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 280 | `movieclip_hittest` | 92 | 2.0s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 281 | `movieclip_in_removed_button` | 4 | 20.7s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 282 | `movieclip_init_object` | 5 | 2.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 283 | `movieclip_invalid_get_bounds_1` | 75 | 2.8s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 284 | `movieclip_invalid_get_bounds_2` | 75 | 1.1s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 285 | `movieclip_invalid_get_bounds_3` | 13 | 2.3s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 286 | `movieclip_invalid_get_bounds_4` | 13 | 2.1s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 287 | `movieclip_invalid_get_bounds_5` | 11 | 2.1s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 288 | `movieclip_invalid_get_bounds_6` | 10 | 26.7s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 289 | `movieclip_invalid_get_bounds_7` | 10 | 26.6s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 290 | `movieclip_invalid_get_bounds_8` | 11 | 2.1s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 291 | `movieclip_line_gradient_style` | 0 | 2.6s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 292 | `new_method_wrap` | 4 | 25.6s |  |
| 293 | `new_object_enumerate` | 7 | 1.8s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 294 | `new_object_wrap` | 4 | 1.8s |  |
| 295 | `o` | 3 | 1.8s |  |
| 296 | `object_constructor` | 33 | 1.8s |  |
| 297 | `object_function` | 32 | 1.8s |  |
| 298 | `object_properties` | 31 | 2.0s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 299 | `object_prototypes` | 74 | 1.9s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 300 | `object_resolve` | 38 | 2.0s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 301 | `object_string_coerce_swf5` | 62 | 1.9s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 302 | `object_string_coerce_swf6` | 68 | 1.9s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 303 | `on_construct` | 25 | 2.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [20](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 304 | `parse_float` | 74 | 1.9s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 305 | `parse_int` | 64 | 21.0s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 306 | `path_string` | 301 | 2.4s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 307 | `place_and_lookup` | 30 | 1.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 308 | `placeobject_all_event_flags` | 10 | 21.7s |  |
| 309 | `placeobject_occupied_depth` | 6 | 20.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 310 | `point` | 175 | 2.2s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 311 | `primitive_instanceof` | 37 | 1.8s |  |
| 312 | `primitive_type_globals` | 557 | 1.9s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 313 | `printjob_props_swf5` | 45 | 1.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 314 | `printjob_props_swf6` | 45 | 0.9s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 315 | `printjob_props_swf7` | 45 | 7.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 316 | `property_invalid_base_clip` | 35 | 1.7s |  |
| 317 | `prototype_delete` | 12 | 1.6s |  |
| 318 | `prototype_enumerate` | 5 | 1.6s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 319 | `prototype_properties` | 17 | 1.6s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 320 | `rectangle` | 745 | 2.5s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 321 | `recursive_prototypes` | 0 | 1.6s |  |
| 322 | `register_and_init_order` | 231 | 21.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 323 | `register_class` | 66 | 2.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 324 | `register_class_return_value` | 16 | 1.7s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 325 | `register_class_swf6` | 37 | 1.9s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 326 | `register_class_with_sound` | 11 | 1.9s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 327 | `register_globals_across_frames` | 15 | 20.6s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 328 | `register_underflow` | 26 | 1.6s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 329 | `remove_movie_clip` | 29 | 1.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 330 | `removed_base_clip_tell_target` | 1 | 20.4s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 331 | `removed_clip_halts_script` | 15 | 21.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 332 | `removed_target_clip_scope` | 35 | 1.9s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 333 | `resolve_different_root` | 2 | 1.8s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 334 | `rewind_depth` | 30 | 1.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 335 | `root_button_mode` | 10 | 20.9s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 336 | `root_global_parent` | 6 | 20.4s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 337 | `root_onload` | 1 | 1.6s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 338 | `sandbox_type_local_file` | 1 | 28.6s |  |
| 339 | `sandbox_type_local_network` | 1 | 1.0s |  |
| 340 | `selection` | 454 | 2.7s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 341 | `selection_handlers` | 27 | 2.1s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 342 | `set_interval` | 27 | 2.1s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 343 | `set_target_2_swf5` | 13 | 2.2s |  |
| 344 | `set_variable_scope` | 58 | 2.0s |  |
| 345 | `single_frame` | 1 | 1.9s |  |
| 346 | `slash_syntax` | 14 | 2.0s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 347 | `sound` | 628 | 2.3s | [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 348 | `sound_duration_position_props` | 290 | 2.1s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) |
| 349 | `sound_getters` | 99 | 1.9s |  |
| 350 | `sound_gettransform_props` | 4 | 1.9s |  |
| 351 | `sound_id3` | 633 | 2.1s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) |
| 352 | `sound_id3_prop` | 138 | 2.0s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) |
| 353 | `swf5_encoding` | 3 | 5.6s |  |
| 354 | `swf5_global_funcs` | 232 | 1.1s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 355 | `swf5_no_closure` | 19 | 2.1s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 356 | `swf5_to_6_cross_call` | 29 | 2.0s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 357 | `swf5_xml_event_handler_context` | 2 | 20.7s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 358 | `swf6_case_insensitive` | 42 | 1.8s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 359 | `swf6_global_funcs` | 232 | 0.9s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 360 | `swf6_string_as_bool` | 15 | 1.8s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 361 | `swf6_to_5_cross_call` | 29 | 1.9s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 362 | `swf7_case_sensitive` | 44 | 0.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 363 | `swf7_global_funcs` | 232 | 0.7s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 364 | `tab_ordering_automatic_basic` | 92 | 1.9s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 365 | `tab_ordering_automatic_order_grid` | 21 | 1.9s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 366 | `tab_ordering_automatic_order_same_position` | 12 | 1.9s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 367 | `tab_ordering_children` | 208 | 2.2s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 368 | `tab_ordering_custom_basic` | 71 | 1.9s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 369 | `tab_ordering_custom_duplicate_index` | 22 | 1.8s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 370 | `tab_ordering_custom_i32_vs_u32` | 12 | 1.8s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 371 | `tab_ordering_custom_m1` | 29 | 0.9s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 372 | `tab_ordering_events` | 150 | 2.4s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 373 | `tab_ordering_events_mouse` | 65 | 2.2s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 374 | `tab_ordering_movieclip_enabled_default` | 462 | 2.0s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 375 | `tab_ordering_properties` | 293 | 1.8s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 376 | `tab_ordering_reverse` | 51 | 2.8s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 377 | `tab_ordering_tabbable` | 47 | 2.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 378 | `target_clip_removed` | 5 | 26.1s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 379 | `target_clip_swf5` | 2 | 2.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 380 | `target_clip_swf6` | 2 | 1.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 381 | `target_path` | 14 | 2.3s |  |
| 382 | `target_paths/swf4` | 818 | 29.3s |  |
| 383 | `tell_target` | 34 | 2.5s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 384 | `tell_target_invalid` | 5 | 2.5s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 385 | `tell_target_invalid_swf6` | 4 | 1.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 386 | `text_blocks_clicks` | 4 | 2.4s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 387 | `text_format` | 1146 | 2.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 388 | `text_format_display` | 21 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 389 | `text_format_font_max_length` | 2 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 390 | `text_format_get_text_extent_undefined_width` | 10 | 2.1s |  |
| 391 | `text_format_rounding_swf7` | 840 | 2.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 392 | `text_format_rounding_swf8` | 840 | 1.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 393 | `textfield_background_color` | 11 | 2.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 394 | `textfield_border_color` | 11 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 395 | `textfield_cache_as_bitmap` | 1 | 2.4s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 396 | `try_catch_finally` | 118 | 3.8s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 397 | `try_catch_stack` | 16 | 1.8s | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_STACK_PLAN.md) |
| 398 | `try_finally_simple` | 16 | 1.8s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 399 | `typeof` | 22 | 2.2s |  |
| 400 | `typeof_globals` | 7 | 1.8s |  |
| 401 | `uncaught_exception` | 1 | 1.8s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 402 | `uncaught_exception_bubbled` | 1 | 1.8s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 403 | `undefined_to_string_swf6` | 4 | 1.8s |  |
| 404 | `unescape` | 43 | 1.8s |  |
| 405 | `unload` | 52 | 20.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 406 | `unload_clip_event` | 4 | 1.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 407 | `unload_nested_child` | 5 | 2.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 408 | `unloadmovie` | 4 | 2.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 409 | `unloadmovie_method` | 3 | 1.9s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 410 | `unloadmovienum` | 13 | 2.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 411 | `use_hand_cursor` | 8 | 1.6s |  |
| 412 | `variable_args` | 5 | 1.9s |  |
| 413 | `virtual_property_special_recursion_swf7` | 262 | 1.9s |  |
| 414 | `waitforframe` | 7 | 1.7s |  |
| 415 | `waitforframe2` | 16 | 1.7s |  |
| 416 | `watch` | 117 | 2.1s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 417 | `watch_infinite_recursion` | 1 | 0.7s |  |
| 418 | `watch_proto_recursion` | 1 | 0.7s |  |
| 419 | `watch_textfield` | 12 | 1.5s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 420 | `watch_virtual_property_proto` | 2 | 0.7s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 421 | `with` | 46 | 0.7s | [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 422 | `with_return` | 2 | 0.7s |  |
| 423 | `with_variable_scopes` | 43 | 0.7s | [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 424 | `xml` | 15 | 0.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 425 | `xml_append_child` | 28 | 0.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 426 | `xml_append_child_with_parent` | 20 | 0.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 427 | `xml_attributes_read` | 4 | 0.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 428 | `xml_cdata` | 11 | 0.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 429 | `xml_child_nodes_edge_cases` | 4 | 0.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 430 | `xml_clone_expandos` | 19 | 0.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 431 | `xml_first_last_child` | 8 | 0.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 432 | `xml_has_child_nodes` | 3 | 0.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 433 | `xml_idmap` | 21 | 7.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 434 | `xml_ignore_comments` | 21 | 1.8s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 435 | `xml_ignore_white` | 34 | 1.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 436 | `xml_insert_before` | 20 | 1.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 437 | `xml_inspect_createmethods` | 15 | 1.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 438 | `xml_inspect_doctype` | 7 | 1.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 439 | `xml_inspect_parsexml` | 62 | 1.8s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 440 | `xml_inspect_xmldecl` | 7 | 1.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 441 | `xml_load` | 2 | 1.8s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 442 | `xml_namespaces` | 203 | 1.8s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 443 | `xml_parent_and_child` | 5 | 1.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 444 | `xml_remove_node` | 22 | 1.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 445 | `xml_reparenting` | 14 | 1.8s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 446 | `xml_siblings` | 10 | 1.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 447 | `xml_to_string` | 13 | 1.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 448 | `xml_to_string_comment` | 1 | 1.7s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 449 | `xml_unescaping` | 23 | 1.9s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 450 | `xmlnode_proto` | 1 | 1.9s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Ruffle-Matched Tests

**11 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `bitmap_data_thorough/copyPixels` | 68 | 68 | 2.8s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 2 | `bitmap_data_thorough/paletteMap` | 68 | 68 | 2.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 3 | `bitmap_data_thorough/perlinNoise` | 40 | 445 | 2.8s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 4 | `form_loader_encoding_4` | 2 | 2 | 2.0s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 5 | `mcl_replace_root_swf7_to_swf5` | 1 | 1 | 2.2s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 6 | `mcl_replace_root_swf7_to_swf6` | 1 | 6 | 0.9s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 7 | `movieclip_library_state_values` | 2 | 9 | 2.2s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 8 | `tab_ordering_properties_tab_index_edge_case` | 3 | 3 | 4.2s |  |
| 9 | `target_paths/swf5` | 654 | 654 | 1.3s |  |
| 10 | `target_paths/swf6` | 654 | 654 | 1.2s |  |
| 11 | `virtual_property_special_recursion_double_swf7` | 394 | 394 | 1.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**15 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `movieclip_hittest_shapeflag` | 97.9% | 331 | 338 | 7 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/VECTOR_PATH_HITTEST_PLAN.md) |
| 2 | `bitmap_data_thorough/pixelDissolve` | 97.4% | 1335 | 1371 | 36 | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 3 | `globals_swf5` | 96.7% | 294 | 304 | 10 | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `set_property_values/swf5` | 92.9% | 1620 | 1743 | 123 |  |
| 5 | `set_property_values/swf6` | 92.9% | 1620 | 1743 | 123 |  |
| 6 | `set_property_values/swf7` | 92.9% | 1620 | 1743 | 123 |  |
| 7 | `set_target_2_swf6` | 92.3% | 12 | 13 | 1 |  |
| 8 | `set_target_2_swf7` | 92.3% | 12 | 13 | 1 |  |
| 9 | `localconnection` | 74.8% | 433 | 579 | 146 | [57](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 10 | `array_shift` | 69.0% | 149 | 216 | 67 |  |
| 11 | `shared_stack` | 68.8% | 11 | 16 | 5 |  |
| 12 | `array_unshift` | 65.1% | 95 | 146 | 51 |  |
| 13 | `array_reverse` | 54.0% | 122 | 226 | 104 |  |
| 14 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 15 | `file_reference_list_browse_invalid_filters` | 50.0% | 18 | 36 | 18 |  |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `global_proto_decls` | 4.0s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 2 | `watch_special_recursion_double_swf6` | 3.2s |  |
| 3 | `watch_special_recursion_double_swf7` | 3.2s |  |
| 4 | `watch_special_recursion_swf6` | 3.7s |  |
| 5 | `watch_special_recursion_swf7` | 3.6s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**48 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_hittest_shapeflag` | 97.9% | 331/338 | 338 | 338 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/VECTOR_PATH_HITTEST_PLAN.md) |
| 2 | `bitmap_data_thorough/pixelDissolve` | 97.4% | 1335/1371 | 1371 | 1371 | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 3 | `globals_swf5` | 96.7% | 294/304 | 304 | 304 | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `set_property_values/swf5` | 92.9% | 1620/1743 | 1743 | 1743 |  |
| 5 | `set_property_values/swf6` | 92.9% | 1620/1743 | 1743 | 1743 |  |
| 6 | `set_property_values/swf7` | 92.9% | 1620/1743 | 1743 | 1743 |  |
| 7 | `set_target_2_swf6` | 92.3% | 12/13 | 13 | 13 |  |
| 8 | `set_target_2_swf7` | 92.3% | 12/13 | 13 | 13 |  |
| 9 | `localconnection` | 74.8% | 433/579 | 555 | 579 | [57](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 10 | `array_shift` | 69.0% | 149/216 | 216 | 216 |  |
| 11 | `shared_stack` | 68.8% | 11/16 | 12 | 16 |  |
| 12 | `array_unshift` | 65.1% | 95/146 | 146 | 146 |  |
| 13 | `array_reverse` | 54.0% | 122/226 | 226 | 226 |  |
| 14 | `xml_getbytes` | 52.9% | 9/17 | 17 | 17 | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 15 | `file_reference_list_browse_invalid_filters` | 50.0% | 18/36 | 36 | 36 |  |
| 16 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 17 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 18 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 19 | `amf_array_serialization` | 30.0% | 3/10 | 5 | 10 |  |
| 20 | `virtual_property_special_recursion_double_swf6` | 27.3% | 3/11 | 11 | 11 |  |
| 21 | `file_reference_list_browse_cancel` | 25.0% | 1/4 | 2 | 4 |  |
| 22 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 23 | `set_property_values/swf4` | 20.1% | 350/1743 | 1743 | 1571 |  |
| 24 | `amf_serialize_typed_objects` | 16.7% | 1/6 | 1 | 6 |  |
| 25 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 26 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 27 | `file_reference_list_browse_select` | 14.3% | 1/7 | 2 | 7 |  |
| 28 | `virtual_property_special_recursion_swf6` | 12.5% | 1/8 | 8 | 6 |  |
| 29 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 30 | `global_proto_decls_delete` | 11.1% | 461/4158 | 2371 | 4158 | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 31 | `xml_socket_connect_null` | 8.3% | 1/12 | 4 | 12 |  |
| 32 | `looping_child_swf32` | 7.7% | 29/375 | 375 | 141 |  |
| 33 | `looping_child_swf5` | 7.7% | 29/375 | 375 | 141 |  |
| 34 | `looping_child_swf9` | 7.7% | 29/375 | 375 | 141 |  |
| 35 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 36 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 37 | `geturl_target_normalize` | 4.5% | 4/89 | 35 | 89 |  |
| 38 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 39 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 40 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 41 | `global_instance_decls` | 3.3% | 26/786 | 786 | 758 | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 42 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 43 | `geturl` | 0.0% | 0/7 | 0 | 7 | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 44 | `geturl_opcode_target_normalize` | 0.0% | 0/45 | 0 | 45 |  |
| 45 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 46 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 47 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 48 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [ASSETNATIVEACCESSOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASSETNATIVEACCESSOR_PLAN.md) | 2 | 2 | 0 |
| 6 | [BITMAP_DATA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) | 17 | 17 | 0 |
| 7 | [BITMAP_DATA_THOROUGH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) | 20 | 16 | 4 |
| 8 | [BITMAP_FILTER_CLONE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTER_CLONE_PLAN.md) | 1 | 1 | 0 |
| 9 | [BITMAP_FILTERS_MCFILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_MCFILTERS_PLAN.md) | 1 | 1 | 0 |
| 10 | [BITMAP_FILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_PLAN.md) | 1 | 1 | 0 |
| 11 | [BITMAPDATA_APPLYFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_APPLYFILTER_PLAN.md) | 0 | 0 | 0 |
| 12 | [BITMAPDATA_PERLINNOISE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PERLINNOISE_PLAN.md) | 0 | 0 | 0 |
| 13 | [BITMAPDATA_PIXELDISSOLVE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PIXELDISSOLVE_PLAN.md) | 0 | 0 | 0 |
| 14 | [BITMAPDATA_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) | 6 | 6 | 0 |
| 15 | [BUTTON_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) | 2 | 2 | 0 |
| 16 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 1 | 1 | 0 |
| 17 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) | 3 | 3 | 0 |
| 18 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 4 | 0 |
| 19 | [COLOR_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) | 2 | 2 | 0 |
| 20 | [CONSTRUCT_PARAMETER_REPLAY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) | 1 | 1 | 0 |
| 21 | [COPYPIXELS_ALPHA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COPYPIXELS_ALPHA_PLAN.md) | 0 | 0 | 0 |
| 22 | [CREATETEXTFIELD_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) | 3 | 3 | 0 |
| 23 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 0 | 0 | 0 |
| 24 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 0 | 0 | 0 |
| 25 | [DATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) | 0 | 0 | 0 |
| 26 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 0 | 0 | 0 |
| 27 | [DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md) | 0 | 0 | 0 |
| 28 | [DEVICE_FONT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) | 0 | 0 | 0 |
| 29 | [DISPLACEMENTMAPFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) | 0 | 0 | 0 |
| 30 | [DRAG_DROP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 31 | [DRAWING_API_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) | 3 | 3 | 0 |
| 32 | [EDITTEXT_DRAG_SELECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) | 1 | 1 | 0 |
| 33 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 1 | 1 | 0 |
| 34 | [ENUMERATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) | 11 | 10 | 1 |
| 35 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 36 | [FILLRECT_COLOR_CONSTANT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FILLRECT_COLOR_CONSTANT_PLAN.md) | 0 | 0 | 0 |
| 37 | [FLASH_CORRECT_REGRESSIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) | 2 | 2 | 0 |
| 38 | [FLV_PLAYBACK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) | 0 | 0 | 0 |
| 39 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 4 | 0 |
| 40 | [FOCUS_RECT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 41 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 7 | 0 |
| 42 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 43 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 3 | 0 |
| 44 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 6 | 1 |
| 45 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 46 | [GLOBALS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) | 23 | 19 | 4 |
| 47 | [HIT_TESTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 16 | 1 |
| 48 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 14 | 3 | 11 |
| 49 | [infinite_recursion_function.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 50 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 51 | [issue_768.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 52 | [LOADBITMAP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADBITMAP_PLAN.md) | 0 | 0 | 0 |
| 53 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) | 1 | 1 | 0 |
| 54 | [LOADMOVIE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) | 35 | 31 | 4 |
| 55 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) | 2 | 1 | 1 |
| 56 | [LOADVARIABLES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) | 3 | 2 | 1 |
| 57 | [LOCALCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) | 1 | 0 | 1 |
| 58 | [LOCKROOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) | 0 | 0 | 0 |
| 59 | [MATH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 60 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 61 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 4 | 4 | 0 |
| 62 | [MOVIECLIP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) | 40 | 38 | 2 |
| 63 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 14 | 12 | 2 |
| 64 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 11 | 10 | 1 |
| 65 | [NATIVE_OBJECTS_UPDATED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) | 0 | 0 | 0 |
| 66 | [NETCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) | 0 | 0 | 0 |
| 67 | [object_string_coerce.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 68 | [OBJECT_WATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 69 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 7 | 7 | 0 |
| 70 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 71 | [PIXEL_TEXT_LAYOUT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) | 3 | 3 | 0 |
| 72 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 0 | 0 | 0 |
| 73 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 11 | 11 | 0 |
| 74 | [REGISTERCLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) | 12 | 12 | 0 |
| 75 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 3 | 1 | 2 |
| 76 | [RUNTIME_CXFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) | 1 | 1 | 0 |
| 77 | [RUNTIME_SETMASK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) | 2 | 2 | 0 |
| 78 | [RUNTIME_TRANSFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) | 1 | 1 | 0 |
| 79 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 80 | [SELECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) | 4 | 4 | 0 |
| 81 | [SOUND_CLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 82 | [SOUND_DURATION_POSITION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) | 1 | 1 | 0 |
| 83 | [SOUND_ID3_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) | 2 | 2 | 0 |
| 84 | [SOUND_LOADING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) | 0 | 0 | 0 |
| 85 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 2 | 2 | 0 |
| 86 | [STAGE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) | 0 | 0 | 0 |
| 87 | [string_coercion.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) | 0 | 0 | 0 |
| 88 | [STRING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) | 0 | 0 | 0 |
| 89 | [STYLESHEET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) | 0 | 0 | 0 |
| 90 | [SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) | 2 | 2 | 0 |
| 91 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 4 | 4 | 0 |
| 92 | [TAB_ORDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) | 15 | 15 | 0 |
| 93 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 1 | 0 |
| 94 | [TELLTARGET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) | 10 | 10 | 0 |
| 95 | [TEXTFIELD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) | 48 | 48 | 0 |
| 96 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 0 | 0 | 0 |
| 97 | [THIS_BINDING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) | 1 | 1 | 0 |
| 98 | [this_swf7.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) | 0 | 0 | 0 |
| 99 | [TIMER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) | 1 | 1 | 0 |
| 100 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 4 | 4 | 0 |
| 101 | [TRY_CATCH_STACK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_STACK_PLAN.md) | 1 | 1 | 0 |
| 102 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) | 1 | 1 | 0 |
| 103 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) | 11 | 8 | 3 |
| 104 | [UNLOAD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) | 9 | 9 | 0 |
| 105 | [VECTOR_PATH_HITTEST_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/VECTOR_PATH_HITTEST_PLAN.md) | 1 | 0 | 1 |
| 106 | [WITH_SCOPE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) | 2 | 2 | 0 |
| 107 | [XML_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) | 33 | 28 | 5 |
| | *(tests not in any document)* | 145 | 114 | 31 |
