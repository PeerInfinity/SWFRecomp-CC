# Ruffle Test Results (Filtered)

**Date**: 2026-06-18 21:40 UTC

**Git SHA**: `fe0030e4fc`

**Run Duration**: 52m 42s

**Filtered**: 37 tests ignored out of 701 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 571 |
| Passing | **532** (93.2%) |
| Ruffle-matched | 10 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **542** (94.9%) |
| Failing | 29 |
| Total expected lines | 105412 |
| Matching lines | 97659 (92.6%) |
| Mismatched lines | 7753 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 25 | 86.2% |
| Segfault | 4 | 13.8% |

## Passing Tests

**532 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 8.2s |  |
| 2 | `action_to_integer` | 28 | 1.8s |  |
| 3 | `add` | 28 | 1.8s |  |
| 4 | `add2` | 354 | 2.0s | [1](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 1.8s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 0.9s |  |
| 7 | `add_swf5` | 28 | 0.9s |  |
| 8 | `arguments` | 127 | 1.8s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 1.8s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 1.8s |  |
| 11 | `array_constructor` | 30 | 1.8s |  |
| 12 | `array_enumerate` | 4 | 1.7s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 1.8s |  |
| 14 | `array_properties` | 36 | 0.9s |  |
| 15 | `array_prototyping` | 12 | 1.8s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 1.8s |  |
| 17 | `array_sort` | 161 | 2.6s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 1.9s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 1.9s |  |
| 20 | `array_trivial` | 209 | 1.9s |  |
| 21 | `as1_constructor_v6` | 35 | 1.3s |  |
| 22 | `as1_constructor_v7` | 35 | 0.6s |  |
| 23 | `as2_oop` | 13 | 1.4s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 1.5s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 1.3s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 1.5s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 1.5s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 1.2s |  |
| 29 | `as_broadcaster_undef` | 89 | 1.4s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 1.4s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 1.3s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 1.2s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 1.4s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 0.7s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 0.6s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 1.2s |  |
| 37 | `as_transformed_flag` | 20 | 12.9s |  |
| 38 | `asfunction` | 11 | 1.6s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) |
| 39 | `asnative` | 34 | 1.3s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `asnew` | 34 | 12.9s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 41 | `assetnative` | 81 | 1.4s |  |
| 42 | `assetnative_ids` | 10 | 1.3s |  |
| 43 | `assetnativeaccessor` | 81 | 1.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASSETNATIVEACCESSOR_PLAN.md) |
| 44 | `assetnativeaccessor_ids` | 21 | 5.7s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASSETNATIVEACCESSOR_PLAN.md) |
| 45 | `attach_movie` | 59 | 2.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 46 | `attach_movie_stop` | 3 | 21.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 47 | `bad_placeobject_clipaction` | 2 | 2.0s |  |
| 48 | `bad_swf_tag_past_eof` | 0 | 1.9s |  |
| 49 | `bitand` | 1058 | 4.8s |  |
| 50 | `bitmap_data` | 1126 | 4.5s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 51 | `bitmap_data_colortransform` | 0 | 2.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 52 | `bitmap_data_compare` | 40 | 2.2s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 53 | `bitmap_data_copypixels` | 17 | 23.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 54 | `bitmap_data_draw_cliprect` | 13 | 21.1s |  |
| 55 | `bitmap_data_fillrect` | 0 | 2.4s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 56 | `bitmap_data_hittest` | 132 | 2.7s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 57 | `bitmap_data_max_size_swf10` | 12 | 2.0s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 58 | `bitmap_data_max_size_swf9` | 10 | 1.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 59 | `bitmap_data_noise` | 631 | 2.2s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 60 | `bitmap_data_perlinnoise` | 0 | 23.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 61 | `bitmap_data_pixeldissolve` | 1075 | 3.0s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 62 | `bitmap_data_pixeldissolve_image` | 0 | 21.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 63 | `bitmap_data_thorough/colorTransform` | 279 | 2.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 64 | `bitmap_data_thorough/compare` | 69 | 2.7s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 65 | `bitmap_data_thorough/constructor` | 313 | 2.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 66 | `bitmap_data_thorough/copyChannel` | 2715 | 2.7s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 67 | `bitmap_data_thorough/fillRect` | 342 | 7.0s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 68 | `bitmap_data_thorough/floodFill` | 867 | 2.5s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 69 | `bitmap_data_thorough/getColorBoundsRect` | 285 | 2.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 70 | `bitmap_data_thorough/getPixel` | 141 | 2.3s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 71 | `bitmap_data_thorough/getPixel32` | 141 | 2.3s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 72 | `bitmap_data_thorough/hitTest` | 519 | 2.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 73 | `bitmap_data_thorough/merge` | 1203 | 2.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 74 | `bitmap_data_thorough/noise` | 1518 | 2.7s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 75 | `bitmap_data_thorough/scroll` | 384 | 2.5s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 76 | `bitmap_data_thorough/setPixel` | 531 | 2.3s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 77 | `bitmap_data_thorough/setPixel32` | 531 | 2.3s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 78 | `bitmap_data_thorough/threshold` | 1308 | 2.7s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 79 | `bitmap_data_threshold` | 176 | 2.4s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 80 | `bitmap_filters` | 548 | 4.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTER_CLONE_PLAN.md) [9](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_MCFILTERS_PLAN.md) [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_PLAN.md) [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 81 | `bitmapdata_applyfilter_colormatrix` | 0 | 21.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 82 | `bitmapdata_channels` | 19 | 1.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 83 | `bitor` | 1058 | 4.9s |  |
| 84 | `biturshift` | 14 | 1.9s |  |
| 85 | `biturshift_swf8` | 14 | 1.0s |  |
| 86 | `bitxor` | 1058 | 4.8s |  |
| 87 | `boxed_primitives` | 24 | 2.0s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 88 | `coerce_to_object_monkeypatch` | 129 | 6.7s | [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 89 | `color` | 57 | 2.8s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 90 | `color_transform` | 48 | 1.9s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 91 | `conflicting_instance_names` | 23 | 20.5s |  |
| 92 | `constructor_function` | 2 | 1.8s |  |
| 93 | `context_menu` | 39 | 1.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 94 | `context_menu_item` | 41 | 1.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 95 | `create_empty_movie_clip` | 3 | 1.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 96 | `cross_movie_root` | 10 | 2.0s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 97 | `custom_clip_methods` | 4 | 20.4s | [24](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 98 | `default_names` | 52 | 2.4s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 99 | `define_function2` | 8 | 1.8s |  |
| 100 | `define_function2_preload` | 13 | 1.8s |  |
| 101 | `define_function2_preload_order` | 4 | 1.9s |  |
| 102 | `define_function_case_sensitive` | 2 | 20.2s |  |
| 103 | `define_local` | 27 | 1.8s | [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 104 | `define_local_with_paths` | 54 | 1.9s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 105 | `delete` | 3 | 2.1s |  |
| 106 | `delete2` | 74 | 1.9s |  |
| 107 | `depth_replacement_audio_unloading` | 3 | 20.6s | [27](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md) |
| 108 | `device_font_spacing` | 91 | 20.7s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 109 | `displacementmapfilter_mappoint_throw_error` | 13 | 1.9s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 110 | `display_object_properties` | 2 | 6.2s | [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 111 | `divide_swf4` | 107 | 2.0s |  |
| 112 | `do_init_action` | 3 | 20.8s |  |
| 113 | `do_init_action_child` | 12 | 2.1s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 114 | `drag_drop` | 10 | 2.4s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 115 | `drag_over_from_outside` | 1 | 20.7s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 116 | `drag_over_without_startdrag` | 1 | 2.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 117 | `duplicate_movie_clip` | 20 | 2.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 118 | `duplicate_movie_clip_drawing` | 2 | 1.9s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 119 | `edittext_align` | 60 | 2.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 120 | `edittext_align_trailing_spaces_swf7` | 576 | 20.6s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 121 | `edittext_align_trailing_spaces_swf8` | 576 | 1.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 122 | `edittext_antialiastype` | 296 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 123 | `edittext_autosize` | 71 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 124 | `edittext_autosize_setter` | 20 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 125 | `edittext_bullet` | 30 | 2.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 126 | `edittext_default_format` | 221 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 127 | `edittext_default_format_empty` | 100 | 2.0s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 128 | `edittext_default_format_font_style` | 335 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 129 | `edittext_drag_select` | 9 | 20.8s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 130 | `edittext_focus_selection` | 2 | 1.9s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 131 | `edittext_font_size` | 45 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 132 | `edittext_hscroll` | 27 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 133 | `edittext_html_align_swf7` | 52 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 134 | `edittext_html_align_swf8` | 52 | 8.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 135 | `edittext_html_color` | 114 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 136 | `edittext_html_condensewhite_swf7` | 311 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 137 | `edittext_html_condensewhite_swf8` | 311 | 0.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 138 | `edittext_html_entity` | 4 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 139 | `edittext_html_roundtrip` | 17 | 2.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 140 | `edittext_html_swf6` | 5377 | 3.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 141 | `edittext_html_swf7` | 5377 | 1.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 142 | `edittext_html_swf8` | 5377 | 1.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 143 | `edittext_ime_focus_lost` | 7 | 19.9s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 144 | `edittext_input` | 1 | 20.6s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 145 | `edittext_input_newlines` | 9 | 20.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 146 | `edittext_leading` | 9 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 147 | `edittext_letter_spacing` | 15 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 148 | `edittext_margins` | 25 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 149 | `edittext_newline_stripping` | 64 | 6.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 150 | `edittext_newlines` | 30 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 151 | `edittext_password` | 5 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 152 | `edittext_password_copy` | 4 | 1.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 153 | `edittext_paste_empty` | 2 | 1.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 154 | `edittext_place_caret` | 2 | 20.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 155 | `edittext_programmatic_focus` | 12 | 1.8s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 156 | `edittext_restrict` | 191 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 157 | `edittext_restrict_paste` | 5 | 1.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 158 | `edittext_scroll` | 54 | 3.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 159 | `edittext_stylesheet` | 325 | 24.8s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 160 | `edittext_tab_focus` | 13 | 22.2s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 161 | `edittext_tab_stops` | 60 | 2.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 162 | `edittext_tag_indent` | 31 | 22.2s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 163 | `edittext_text_height_leading` | 20 | 2.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 164 | `edittext_underline` | 40 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 165 | `edittext_width_height` | 103 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 166 | `empty_movieclip_can_attach_movies` | 11 | 2.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 167 | `enumerate` | 64 | 2.1s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 168 | `equals` | 32 | 1.9s |  |
| 169 | `equals2_swf5` | 926 | 4.0s |  |
| 170 | `equals2_swf6` | 926 | 1.1s |  |
| 171 | `equals2_swf7` | 926 | 1.1s |  |
| 172 | `equals_swf4` | 665 | 3.0s |  |
| 173 | `equals_swf4_alt` | 32 | 1.0s |  |
| 174 | `equals_swf5` | 32 | 1.0s |  |
| 175 | `error` | 58 | 1.8s |  |
| 176 | `escape` | 14 | 1.8s |  |
| 177 | `execution_order1` | 5 | 22.2s |  |
| 178 | `execution_order2` | 7 | 22.4s |  |
| 179 | `execution_order3` | 4 | 2.0s |  |
| 180 | `execution_order4` | 12 | 2.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 181 | `export_assets` | 3 | 1.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 182 | `extends_chain` | 134 | 2.7s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 183 | `extends_native_type` | 11 | 1.6s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 184 | `external_interface` | 84 | 1.5s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 185 | `external_interface_escapexml` | 26 | 1.4s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 186 | `external_interface_jsquotestring` | 21 | 1.4s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 187 | `external_interface_toas_basic` | 354 | 1.6s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 188 | `external_interface_toxml_array` | 25 | 1.4s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 189 | `external_interface_toxml_basic` | 179 | 1.5s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 190 | `external_interface_unescapexml` | 40 | 1.4s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 191 | `focus_keyboard_press` | 60 | 1.8s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 192 | `focus_mouse` | 45 | 1.5s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 193 | `focus_mouse_focusable` | 8 | 16.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 194 | `focus_mouse_rollout` | 4 | 1.5s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 195 | `focus_remove` | 33 | 39.5s |  |
| 196 | `focus_root_movie` | 2 | 2.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 197 | `focus_visibility_change` | 45 | 1.9s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 198 | `focusrect_focuslost` | 4 | 20.8s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 199 | `focusrect_mouse_swf8` | 0 | 2.3s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 200 | `focusrect_mouse_swf9` | 0 | 1.1s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 201 | `focusrect_property_swf5` | 1237 | 2.3s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 202 | `focusrect_property_swf6` | 1237 | 1.0s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 203 | `focusrect_property_swf7` | 1237 | 1.9s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 204 | `focusrect_swf5` | 6 | 21.9s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 205 | `focusrect_swf6` | 42 | 2.3s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 206 | `form_loader_encoding_1` | 1 | 1.9s |  |
| 207 | `frame_size_translated_negative` | 21 | 21.1s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 208 | `frame_size_translated_positive` | 21 | 20.8s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 209 | `function_as_function` | 35 | 1.8s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 210 | `function_base_clip` | 8 | 20.4s |  |
| 211 | `function_base_clip_readded` | 11 | 2.1s |  |
| 212 | `function_base_clip_removed` | 25 | 21.1s |  |
| 213 | `function_suppress_and_preload` | 28 | 21.1s |  |
| 214 | `funky_function_calls` | 56 | 1.8s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 215 | `get_bytes_total` | 4 | 21.3s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 216 | `get_variable_in_scope` | 29 | 4.2s |  |
| 217 | `getproperty` | 28 | 1.9s |  |
| 218 | `getproperty_swf4` | 28 | 1.0s |  |
| 219 | `getproperty_swf5` | 28 | 1.0s |  |
| 220 | `gettextextent` | 56 | 2.4s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 221 | `global_array` | 3 | 1.9s |  |
| 222 | `global_is_bare` | 7 | 1.9s |  |
| 223 | `global_swf5_6_7_8_9` | 1145 | 2.9s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 224 | `global_swf6_7_8` | 15 | 2.5s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 225 | `globals_swf6` | 304 | 1.0s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 226 | `globals_swf7` | 304 | 1.0s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 227 | `globals_swf8` | 304 | 1.0s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 228 | `goto_advance1` | 6 | 21.7s |  |
| 229 | `goto_advance2` | 2 | 2.1s |  |
| 230 | `goto_both_ways1` | 3 | 2.2s |  |
| 231 | `goto_both_ways2` | 3 | 21.0s |  |
| 232 | `init_object_invalid` | 4 | 23.3s |  |
| 233 | `init_object_order` | 15 | 2.4s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 234 | `input_dead_keys_windows` | 15 | 2.5s | [50](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 235 | `instanceof_coercions` | 88 | 2.3s | [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 236 | `interface_implements_op` | 47 | 2.6s | [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 237 | `is_finite` | 49 | 1.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 238 | `is_finite_swf6` | 49 | 0.9s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 239 | `is_prototype_of` | 89 | 1.9s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 240 | `issue_1086` | 1 | 1.8s |  |
| 241 | `issue_1104` | 2 | 20.5s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 242 | `issue_1671` | 0 | 20.3s |  |
| 243 | `issue_1906` | 4 | 1.9s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 244 | `issue_2030` | 4 | 1.9s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 245 | `issue_2084` | 16 | 20.9s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 246 | `issue_2166` | 9 | 1.8s |  |
| 247 | `issue_2870` | 3 | 20.6s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 248 | `issue_3169` | 2 | 1.9s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 249 | `issue_3446` | 1 | 1.8s |  |
| 250 | `issue_3522` | 2 | 2.1s |  |
| 251 | `issue_4377` | 2 | 1.8s |  |
| 252 | `issue_710` | 4 | 1.7s |  |
| 253 | `issue_768` | 3 | 1.6s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) |
| 254 | `issue_9327` | 2 | 1.9s |  |
| 255 | `issue_9885` | 2 | 23.9s |  |
| 256 | `key_isToggled` | 9 | 1.6s |  |
| 257 | `lessthan` | 41 | 1.6s |  |
| 258 | `lessthan2_swf5` | 1226 | 3.8s |  |
| 259 | `lessthan2_swf6` | 1226 | 0.8s |  |
| 260 | `lessthan2_swf7` | 1226 | 0.8s |  |
| 261 | `lessthan_swf4` | 902 | 2.9s |  |
| 262 | `lessthan_swf4_alt` | 41 | 0.8s |  |
| 263 | `lessthan_swf5` | 41 | 0.8s |  |
| 264 | `loadmovie` | 2 | 1.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 265 | `loadmovie_fail` | 2 | 1.7s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 266 | `loadmovie_flashvars` | 4 | 1.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 267 | `loadmovie_method` | 2 | 1.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 268 | `loadmovie_registerclass` | 30 | 1.9s | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 269 | `loadmovie_replace_root` | 5 | 1.9s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 270 | `loadmovie_var_persistence` | 8 | 1.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) |
| 271 | `loadmovienum` | 3 | 1.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 272 | `loadmovienum_cross_version_prototype` | 9 | 1.9s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) |
| 273 | `loadvariables` | 2 | 20.9s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 274 | `loadvariables2` | 8 | 27.2s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 275 | `loadvariablesnum` | 2 | 2.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 276 | `loadvars_tostring` | 5 | 2.0s |  |
| 277 | `local_to_global` | 49 | 2.1s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 278 | `localconnection_properties` | 8 | 1.9s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 279 | `lock_root` | 1 | 2.1s |  |
| 280 | `logical_ops_swf4` | 90 | 2.0s |  |
| 281 | `logical_ops_swf8` | 108 | 2.0s |  |
| 282 | `looping` | 6 | 20.7s |  |
| 283 | `looping_real_1_declared_1` | 1 | 1.9s |  |
| 284 | `looping_real_1_declared_2` | 1 | 1.0s |  |
| 285 | `looping_real_2_declared_1` | 5 | 1.9s |  |
| 286 | `looping_real_2_declared_2` | 5 | 1.0s |  |
| 287 | `mask_reapply` | 0 | 21.1s | [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 288 | `mask_with_drawing` | 0 | 21.0s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 289 | `math_min_max` | 101 | 2.0s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 290 | `math_swf6` | 530 | 2.4s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 291 | `math_swf7` | 530 | 1.0s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 292 | `math_swf8` | 530 | 8.0s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 293 | `matrix` | 171 | 2.4s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 294 | `mcl_as_broadcaster` | 12 | 2.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 295 | `mcl_events_swf_version` | 232 | 3.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 296 | `mcl_getprogress` | 30 | 21.9s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 297 | `mcl_loadclip` | 149 | 21.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 298 | `mcl_loadclip_properties` | 6 | 2.2s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 299 | `mcl_loadclip_replace_root` | 1 | 2.1s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 300 | `mcl_mislabeled_target` | 6 | 2.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 301 | `mcl_target_gif87a` | 6 | 2.7s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 302 | `mcl_target_gif89a` | 6 | 1.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 303 | `mcl_target_jpg` | 6 | 1.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 304 | `mcl_target_png` | 6 | 1.3s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 305 | `mcl_unloadclip` | 5 | 20.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 306 | `mouse_events` | 8 | 20.8s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 307 | `mouse_events_visible_enabled` | 12 | 21.7s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 308 | `mouse_hover_events_while_dragging` | 1 | 20.5s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 309 | `mouse_listeners` | 67 | 1.9s |  |
| 310 | `mouse_pos` | 665 | 20.5s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 311 | `mouse_pos_with_scale_factor` | 260 | 20.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 312 | `mouse_wheel_enabled` | 2 | 1.9s |  |
| 313 | `movieclip_begin_gradient_fill` | 0 | 29.3s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 314 | `movieclip_blend_mode_property` | 35 | 2.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 315 | `movieclip_create_text_field` | 90 | 21.6s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 316 | `movieclip_default_state` | 69 | 2.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 317 | `movieclip_depth_methods` | 98 | 21.4s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 318 | `movieclip_focusenabled` | 99 | 2.1s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 319 | `movieclip_get_instance_at_depth` | 28 | 2.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 320 | `movieclip_getbounds` | 191 | 2.2s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 321 | `movieclip_gettextsnapshot` | 112 | 2.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 322 | `movieclip_hittest` | 92 | 2.1s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 323 | `movieclip_in_removed_button` | 4 | 21.1s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 324 | `movieclip_init_object` | 5 | 2.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 325 | `movieclip_invalid_get_bounds_1` | 75 | 3.0s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 326 | `movieclip_invalid_get_bounds_2` | 75 | 1.2s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 327 | `movieclip_invalid_get_bounds_3` | 13 | 2.5s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 328 | `movieclip_invalid_get_bounds_4` | 13 | 2.3s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 329 | `movieclip_invalid_get_bounds_5` | 11 | 2.3s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 330 | `movieclip_invalid_get_bounds_6` | 10 | 27.4s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 331 | `movieclip_invalid_get_bounds_7` | 10 | 27.4s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 332 | `movieclip_invalid_get_bounds_8` | 11 | 2.3s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 333 | `movieclip_line_gradient_style` | 0 | 2.8s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 334 | `new_method_wrap` | 4 | 26.3s |  |
| 335 | `new_object_enumerate` | 7 | 2.0s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 336 | `new_object_wrap` | 4 | 2.0s |  |
| 337 | `o` | 3 | 2.0s |  |
| 338 | `object_constructor` | 33 | 2.0s |  |
| 339 | `object_function` | 32 | 2.0s |  |
| 340 | `object_properties` | 31 | 2.2s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 341 | `object_prototypes` | 74 | 2.1s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 342 | `object_resolve` | 38 | 2.3s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 343 | `object_string_coerce_swf5` | 62 | 2.1s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 344 | `object_string_coerce_swf6` | 68 | 2.1s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 345 | `on_construct` | 25 | 2.3s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [20](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 346 | `parse_float` | 74 | 2.1s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 347 | `parse_int` | 64 | 23.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 348 | `path_string` | 301 | 2.6s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 349 | `place_and_lookup` | 30 | 2.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 350 | `placeobject_all_event_flags` | 10 | 22.7s |  |
| 351 | `placeobject_occupied_depth` | 6 | 22.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 352 | `point` | 175 | 2.4s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 353 | `primitive_instanceof` | 37 | 2.0s |  |
| 354 | `primitive_type_globals` | 557 | 2.1s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 355 | `printjob_props_swf5` | 45 | 2.0s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 356 | `printjob_props_swf6` | 45 | 1.0s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 357 | `printjob_props_swf7` | 45 | 7.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 358 | `property_invalid_base_clip` | 35 | 2.0s |  |
| 359 | `prototype_delete` | 12 | 2.0s |  |
| 360 | `prototype_enumerate` | 5 | 1.9s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 361 | `prototype_properties` | 17 | 1.9s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 362 | `rectangle` | 745 | 2.8s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 363 | `recursive_prototypes` | 0 | 1.9s |  |
| 364 | `register_and_init_order` | 231 | 22.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 365 | `register_class` | 66 | 2.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 366 | `register_class_return_value` | 16 | 2.0s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 367 | `register_class_swf6` | 37 | 2.3s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 368 | `register_class_with_sound` | 11 | 2.2s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 369 | `register_globals_across_frames` | 15 | 20.8s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 370 | `register_underflow` | 26 | 1.9s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 371 | `remove_movie_clip` | 29 | 2.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 372 | `removed_base_clip_tell_target` | 1 | 20.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 373 | `removed_clip_halts_script` | 15 | 21.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 374 | `removed_target_clip_scope` | 35 | 2.3s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 375 | `resolve_different_root` | 2 | 2.1s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 376 | `rewind_depth` | 30 | 2.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 377 | `root_button_mode` | 10 | 21.2s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 378 | `root_global_parent` | 6 | 21.1s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 379 | `root_onload` | 1 | 1.9s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 380 | `sandbox_type_local_file` | 1 | 25.1s |  |
| 381 | `sandbox_type_local_network` | 1 | 0.9s |  |
| 382 | `selection` | 454 | 2.6s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 383 | `selection_handlers` | 27 | 1.9s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 384 | `set_interval` | 27 | 2.0s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 385 | `set_target_2_swf5` | 13 | 1.9s |  |
| 386 | `set_variable_scope` | 58 | 1.9s |  |
| 387 | `single_frame` | 1 | 1.8s |  |
| 388 | `slash_syntax` | 14 | 1.9s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 389 | `sound` | 628 | 2.2s | [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 390 | `sound_duration_position_props` | 290 | 2.0s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) |
| 391 | `sound_getters` | 99 | 1.8s |  |
| 392 | `sound_gettransform_props` | 4 | 1.8s |  |
| 393 | `sound_id3` | 633 | 2.0s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) |
| 394 | `sound_id3_prop` | 138 | 1.9s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) |
| 395 | `sound_load_start` | 3 | 1.9s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) |
| 396 | `sound_multiple_load` | 1 | 1.6s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) |
| 397 | `sound_nested_clips` | 10 | 1.6s |  |
| 398 | `sound_owner_reference` | 12 | 1.5s |  |
| 399 | `sound_owner_tostring_fail` | 9 | 1.5s |  |
| 400 | `sound_props_swf5` | 68 | 1.6s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 401 | `sound_props_swf6` | 68 | 0.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 402 | `sound_start_load` | 0 | 1.0s |  |
| 403 | `sound_start_stop` | 44 | 16.4s |  |
| 404 | `stage_display_state` | 16 | 1.5s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 405 | `stage_object_children` | 83 | 16.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 406 | `stage_object_enumerate` | 4 | 0.9s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 407 | `stage_object_properties` | 241 | 16.4s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 408 | `stage_object_properties_get_var` | 5 | 1.4s |  |
| 409 | `stage_object_properties_swf6` | 231 | 16.3s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 410 | `stage_property_representation` | 586 | 1.5s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 411 | `stage_scale_mode` | 39 | 15.9s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 412 | `strictequals_swf6` | 902 | 2.7s |  |
| 413 | `strictly_equals` | 7 | 1.5s |  |
| 414 | `string_coercion` | 117 | 1.8s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) |
| 415 | `string_methods` | 285 | 1.9s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 416 | `string_methods_negative_args` | 240 | 1.6s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 417 | `string_methods_swfv5` | 275 | 4.9s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 418 | `string_ops_swf6` | 95 | 2.0s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 419 | `string_paths_basic` | 4 | 1.9s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 420 | `string_paths_eval` | 4 | 2.2s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 421 | `string_paths_eval2` | 7 | 20.7s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 422 | `string_paths_hidden` | 54 | 2.0s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 423 | `string_paths_keyevents` | 0 | 1.9s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 424 | `string_paths_other` | 36 | 2.1s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 425 | `string_paths_timer` | 0 | 1.9s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 426 | `string_paths_unload` | 1 | 1.9s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 427 | `string_paths_variable_alias` | 4 | 1.9s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 428 | `string_paths_variable_scopes` | 5 | 2.0s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 429 | `stylesheet` | 283 | 2.9s |  |
| 430 | `stylesheet_transform` | 750 | 2.7s |  |
| 431 | `super_edge_cases` | 39 | 2.2s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 432 | `swf4_actions_bool` | 96 | 2.0s |  |
| 433 | `swf4_actions_coercion_order` | 157 | 2.0s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 434 | `swf4_bool` | 4 | 1.8s |  |
| 435 | `swf4_function_calls` | 7 | 1.9s |  |
| 436 | `tab_ordering_reverse` | 51 | 2.3s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 437 | `tab_ordering_tabbable` | 47 | 2.1s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 438 | `target_clip_removed` | 5 | 21.0s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 439 | `target_clip_swf5` | 2 | 1.8s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 440 | `target_clip_swf6` | 2 | 1.0s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 441 | `target_path` | 14 | 1.9s |  |
| 442 | `target_paths/swf4` | 818 | 22.7s |  |
| 443 | `tell_target` | 34 | 2.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 444 | `tell_target_invalid` | 5 | 2.0s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 445 | `tell_target_invalid_swf6` | 4 | 1.0s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 446 | `text_blocks_clicks` | 4 | 1.9s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 447 | `text_format` | 1146 | 2.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 448 | `text_format_display` | 21 | 1.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 449 | `text_format_font_max_length` | 2 | 1.7s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 450 | `text_format_get_text_extent_undefined_width` | 10 | 1.8s |  |
| 451 | `text_format_rounding_swf7` | 840 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 452 | `text_format_rounding_swf8` | 840 | 1.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 453 | `textfield_background_color` | 11 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 454 | `textfield_border_color` | 11 | 1.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 455 | `textfield_cache_as_bitmap` | 1 | 1.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 456 | `textfield_maxchars` | 3 | 8.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 457 | `textfield_properties` | 44 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 458 | `textfield_props_swf6` | 210 | 0.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 459 | `textfield_props_swf7` | 210 | 0.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 460 | `textfield_props_swf8` | 210 | 0.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 461 | `textfield_text` | 7 | 1.7s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 462 | `textfield_variable` | 81 | 20.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 463 | `textsnapshot_available_text` | 20 | 1.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 464 | `textsnapshot_findtext` | 44 | 2.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 465 | `textsnapshot_gettext` | 55 | 2.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 466 | `textsnapshot_props_swf5` | 56 | 1.6s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 467 | `textsnapshot_props_swf6` | 56 | 0.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 468 | `textsnapshot_text_order` | 1 | 1.7s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 469 | `this_scoping` | 52 | 20.3s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 470 | `this_swf5` | 41 | 1.6s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 471 | `this_swf6` | 41 | 0.9s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 472 | `this_swf7` | 41 | 0.9s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) |
| 473 | `timeline_function_def` | 7 | 21.2s |  |
| 474 | `timeout` | 0 | 6.9s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 475 | `timer_run_actions` | 18 | 2.1s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 476 | `trace` | 8 | 1.9s |  |
| 477 | `transform` | 70 | 2.0s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 478 | `try_catch_finally` | 118 | 6.7s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 479 | `try_catch_stack` | 16 | 1.8s | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_STACK_PLAN.md) |
| 480 | `try_finally_simple` | 16 | 1.8s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 481 | `typeof` | 22 | 2.3s |  |
| 482 | `typeof_globals` | 7 | 1.9s |  |
| 483 | `uncaught_exception` | 1 | 1.8s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 484 | `uncaught_exception_bubbled` | 1 | 1.8s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 485 | `undefined_to_string_swf6` | 4 | 1.9s |  |
| 486 | `unescape` | 43 | 1.9s |  |
| 487 | `unload` | 52 | 21.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 488 | `unload_clip_event` | 4 | 21.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 489 | `unload_nested_child` | 5 | 21.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 490 | `unloadmovie` | 4 | 2.1s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 491 | `unloadmovie_method` | 3 | 2.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 492 | `unloadmovienum` | 13 | 2.1s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 493 | `use_hand_cursor` | 8 | 1.8s |  |
| 494 | `variable_args` | 5 | 2.0s |  |
| 495 | `virtual_property_special_recursion_swf7` | 262 | 1.9s |  |
| 496 | `waitforframe` | 7 | 1.8s |  |
| 497 | `waitforframe2` | 16 | 1.8s |  |
| 498 | `watch` | 117 | 4.9s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 499 | `watch_infinite_recursion` | 1 | 0.8s |  |
| 500 | `watch_proto_recursion` | 1 | 0.9s |  |
| 501 | `watch_textfield` | 12 | 1.3s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 502 | `watch_virtual_property_proto` | 2 | 0.9s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 503 | `with` | 46 | 0.9s | [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 504 | `with_return` | 2 | 0.9s |  |
| 505 | `with_variable_scopes` | 43 | 0.8s | [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 506 | `xml` | 15 | 0.8s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 507 | `xml_append_child` | 28 | 0.8s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 508 | `xml_append_child_with_parent` | 20 | 0.8s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 509 | `xml_attributes_read` | 4 | 0.8s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 510 | `xml_cdata` | 11 | 0.8s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 511 | `xml_child_nodes_edge_cases` | 4 | 0.8s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 512 | `xml_clone_expandos` | 19 | 0.8s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 513 | `xml_first_last_child` | 8 | 0.8s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 514 | `xml_has_child_nodes` | 3 | 0.8s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 515 | `xml_idmap` | 21 | 2.8s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 516 | `xml_ignore_comments` | 21 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 517 | `xml_ignore_white` | 34 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 518 | `xml_insert_before` | 20 | 1.5s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 519 | `xml_inspect_createmethods` | 15 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 520 | `xml_inspect_doctype` | 7 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 521 | `xml_inspect_parsexml` | 62 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 522 | `xml_inspect_xmldecl` | 7 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 523 | `xml_load` | 2 | 2.0s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 524 | `xml_namespaces` | 203 | 2.1s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 525 | `xml_parent_and_child` | 5 | 1.3s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 526 | `xml_remove_node` | 22 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 527 | `xml_reparenting` | 14 | 1.5s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 528 | `xml_siblings` | 10 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 529 | `xml_to_string` | 13 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 530 | `xml_to_string_comment` | 1 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 531 | `xml_unescaping` | 23 | 1.6s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 532 | `xmlnode_proto` | 1 | 1.5s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Ruffle-Matched Tests

**10 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `bitmap_data_thorough/copyPixels` | 68 | 68 | 2.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 2 | `bitmap_data_thorough/paletteMap` | 68 | 68 | 2.7s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 3 | `bitmap_data_thorough/perlinNoise` | 40 | 445 | 2.9s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 4 | `load_cancel_via_unloadclip` | 2 | 2 | 1.6s |  |
| 5 | `load_cancel_via_unloadmovie` | 3 | 3 | 1.6s |  |
| 6 | `swf4_vars` | 3 | 4 | 1.9s |  |
| 7 | `target_paths/swf5` | 654 | 654 | 1.0s |  |
| 8 | `target_paths/swf6` | 654 | 654 | 1.0s |  |
| 9 | `textfield_props_swf5` | 2 | 103 | 1.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 10 | `virtual_property_special_recursion_double_swf7` | 394 | 394 | 1.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**11 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `set_property_values/swf5` | 92.9% | 1620 | 1743 | 123 |  |
| 2 | `set_property_values/swf6` | 92.9% | 1620 | 1743 | 123 |  |
| 3 | `set_property_values/swf7` | 92.9% | 1620 | 1743 | 123 |  |
| 4 | `set_target_2_swf6` | 92.3% | 12 | 13 | 1 |  |
| 5 | `set_target_2_swf7` | 92.3% | 12 | 13 | 1 |  |
| 6 | `coerce_to_primitive_resolve` | 72.7% | 16 | 22 | 6 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 7 | `array_shift` | 69.0% | 149 | 216 | 67 |  |
| 8 | `shared_stack` | 68.8% | 11 | 16 | 5 |  |
| 9 | `array_unshift` | 65.1% | 95 | 146 | 51 |  |
| 10 | `array_reverse` | 54.0% | 122 | 226 | 104 |  |
| 11 | `file_reference_list_browse_invalid_filters` | 50.0% | 18 | 36 | 18 |  |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `watch_special_recursion_double_swf6` | 3.2s |  |
| 2 | `watch_special_recursion_double_swf7` | 3.4s |  |
| 3 | `watch_special_recursion_swf6` | 3.1s |  |
| 4 | `watch_special_recursion_swf7` | 3.8s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**25 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `set_property_values/swf5` | 92.9% | 1620/1743 | 1743 | 1743 |  |
| 2 | `set_property_values/swf6` | 92.9% | 1620/1743 | 1743 | 1743 |  |
| 3 | `set_property_values/swf7` | 92.9% | 1620/1743 | 1743 | 1743 |  |
| 4 | `set_target_2_swf6` | 92.3% | 12/13 | 13 | 13 |  |
| 5 | `set_target_2_swf7` | 92.3% | 12/13 | 13 | 13 |  |
| 6 | `coerce_to_primitive_resolve` | 72.7% | 16/22 | 21 | 22 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 7 | `array_shift` | 69.0% | 149/216 | 216 | 216 |  |
| 8 | `shared_stack` | 68.8% | 11/16 | 12 | 16 |  |
| 9 | `array_unshift` | 65.1% | 95/146 | 146 | 146 |  |
| 10 | `array_reverse` | 54.0% | 122/226 | 226 | 226 |  |
| 11 | `file_reference_list_browse_invalid_filters` | 50.0% | 18/36 | 36 | 36 |  |
| 12 | `sound_setters` | 32.6% | 14/43 | 39 | 43 |  |
| 13 | `amf_array_serialization` | 30.0% | 3/10 | 5 | 10 |  |
| 14 | `virtual_property_special_recursion_double_swf6` | 27.3% | 3/11 | 11 | 11 |  |
| 15 | `file_reference_list_browse_cancel` | 25.0% | 1/4 | 2 | 4 |  |
| 16 | `load_cancel_via_removemovieclip` | 25.0% | 2/8 | 8 | 4 |  |
| 17 | `set_property_values/swf4` | 20.1% | 350/1743 | 1743 | 1571 |  |
| 18 | `amf_serialize_typed_objects` | 16.7% | 1/6 | 1 | 6 |  |
| 19 | `file_reference_list_browse_select` | 14.3% | 1/7 | 2 | 7 |  |
| 20 | `virtual_property_special_recursion_swf6` | 12.5% | 1/8 | 8 | 6 |  |
| 21 | `looping_child_swf32` | 7.7% | 29/375 | 375 | 141 |  |
| 22 | `looping_child_swf5` | 7.7% | 29/375 | 375 | 141 |  |
| 23 | `looping_child_swf9` | 7.7% | 29/375 | 375 | 141 |  |
| 24 | `geturl_target_normalize` | 4.5% | 4/89 | 35 | 89 |  |
| 25 | `geturl_opcode_target_normalize` | 0.0% | 0/45 | 0 | 45 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [ASSETNATIVEACCESSOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASSETNATIVEACCESSOR_PLAN.md) | 2 | 2 | 0 |
| 6 | [BITMAP_DATA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) | 17 | 17 | 0 |
| 7 | [BITMAP_DATA_THOROUGH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) | 19 | 16 | 3 |
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
| 18 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 3 | 3 | 0 |
| 19 | [COLOR_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 20 | [CONSTRUCT_PARAMETER_REPLAY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) | 1 | 1 | 0 |
| 21 | [COPYPIXELS_ALPHA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COPYPIXELS_ALPHA_PLAN.md) | 0 | 0 | 0 |
| 22 | [CREATETEXTFIELD_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 23 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 1 | 1 | 0 |
| 24 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 25 | [DATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) | 0 | 0 | 0 |
| 26 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 27 | [DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md) | 1 | 1 | 0 |
| 28 | [DEVICE_FONT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) | 2 | 2 | 0 |
| 29 | [DISPLACEMENTMAPFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) | 1 | 1 | 0 |
| 30 | [DRAG_DROP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 31 | [DRAWING_API_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) | 3 | 3 | 0 |
| 32 | [EDITTEXT_DRAG_SELECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) | 1 | 1 | 0 |
| 33 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 34 | [ENUMERATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) | 13 | 13 | 0 |
| 35 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 36 | [FILLRECT_COLOR_CONSTANT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FILLRECT_COLOR_CONSTANT_PLAN.md) | 0 | 0 | 0 |
| 37 | [FLASH_CORRECT_REGRESSIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) | 2 | 2 | 0 |
| 38 | [FLV_PLAYBACK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) | 0 | 0 | 0 |
| 39 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 4 | 0 |
| 40 | [FOCUS_RECT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 41 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 7 | 0 |
| 42 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 0 | 0 | 0 |
| 43 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 3 | 0 |
| 44 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 6 | 6 | 0 |
| 45 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 46 | [GLOBALS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) | 20 | 20 | 0 |
| 47 | [HIT_TESTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) | 12 | 12 | 0 |
| 48 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 5 | 5 | 0 |
| 49 | [infinite_recursion_function.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) | 0 | 0 | 0 |
| 50 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 51 | [issue_768.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 52 | [LOADBITMAP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADBITMAP_PLAN.md) | 0 | 0 | 0 |
| 53 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 54 | [LOADMOVIE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) | 41 | 41 | 0 |
| 55 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) | 3 | 3 | 0 |
| 56 | [LOADVARIABLES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) | 3 | 3 | 0 |
| 57 | [LOCALCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) | 0 | 0 | 0 |
| 58 | [LOCKROOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) | 0 | 0 | 0 |
| 59 | [MATH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 60 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 0 | 0 | 0 |
| 61 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 4 | 4 | 0 |
| 62 | [MOVIECLIP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) | 44 | 44 | 0 |
| 63 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 13 | 13 | 0 |
| 64 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 11 | 11 | 0 |
| 65 | [NATIVE_OBJECTS_UPDATED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) | 0 | 0 | 0 |
| 66 | [NETCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) | 0 | 0 | 0 |
| 67 | [object_string_coerce.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 68 | [OBJECT_WATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) | 3 | 3 | 0 |
| 69 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 70 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 71 | [PIXEL_TEXT_LAYOUT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) | 3 | 3 | 0 |
| 72 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 0 | 1 |
| 73 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 11 | 1 |
| 74 | [REGISTERCLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) | 14 | 14 | 0 |
| 75 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 2 | 2 | 0 |
| 76 | [RUNTIME_CXFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 77 | [RUNTIME_SETMASK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) | 2 | 2 | 0 |
| 78 | [RUNTIME_TRANSFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 79 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 80 | [SELECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) | 4 | 4 | 0 |
| 81 | [SOUND_CLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 82 | [SOUND_DURATION_POSITION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) | 1 | 1 | 0 |
| 83 | [SOUND_ID3_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) | 2 | 2 | 0 |
| 84 | [SOUND_LOADING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) | 2 | 2 | 0 |
| 85 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 86 | [STAGE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 87 | [string_coercion.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 88 | [STRING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) | 12 | 12 | 0 |
| 89 | [STYLESHEET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 90 | [SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) | 1 | 1 | 0 |
| 91 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 1 | 1 | 0 |
| 92 | [TAB_ORDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) | 5 | 5 | 0 |
| 93 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 0 | 0 | 0 |
| 94 | [TELLTARGET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) | 18 | 18 | 0 |
| 95 | [TEXTFIELD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) | 70 | 69 | 1 |
| 96 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 97 | [THIS_BINDING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) | 3 | 3 | 0 |
| 98 | [this_swf7.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 99 | [TIMER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) | 3 | 3 | 0 |
| 100 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 4 | 4 | 0 |
| 101 | [TRY_CATCH_STACK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_STACK_PLAN.md) | 1 | 1 | 0 |
| 102 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 2 | 0 |
| 103 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) | 13 | 13 | 0 |
| 104 | [UNLOAD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) | 10 | 10 | 0 |
| 105 | [VECTOR_PATH_HITTEST_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/VECTOR_PATH_HITTEST_PLAN.md) | 0 | 0 | 0 |
| 106 | [WITH_SCOPE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) | 4 | 4 | 0 |
| 107 | [XML_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) | 27 | 27 | 0 |
| | *(tests not in any document)* | 179 | 145 | 34 |
