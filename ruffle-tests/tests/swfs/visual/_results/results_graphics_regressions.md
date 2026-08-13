# Graphics vs Trace Mode Differences

Trace: 140/143 passing | Graphics: 0/144 passing

## Graphics Regressions (140 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `avm2_button_scroll_rect` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 2 | `bitmapdata_copypixels_with_alpha_oob` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 3 | `blend_modes/add` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 4 | `blend_modes/alpha_no_layer` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 5 | `blend_modes/darken` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 6 | `blend_modes/difference` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 7 | `blend_modes/erase_no_layer` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 8 | `blend_modes/hardlight` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 9 | `blend_modes/invert` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 10 | `blend_modes/layer_alpha` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 11 | `blend_modes/layer_erase` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 12 | `blend_modes/lighten` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 13 | `blend_modes/multiply` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 14 | `blend_modes/overlay` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 15 | `blend_modes/overlay_onto_stage` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 16 | `blend_modes/screen` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 17 | `blend_modes/shader_as_mask` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 18 | `blend_modes/shader_without_shader` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 19 | `blend_modes/subtract` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 20 | `bmd_draw_with_msaa_issue_10579` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 21 | `cache_as_bitmap/avm1_color` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 22 | `cache_as_bitmap/avm2_button` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 23 | `cache_as_bitmap/avm2_button_state` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 24 | `cache_as_bitmap/bitmap_changed` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 25 | `cache_as_bitmap/cab_bitmapdata_invalidate` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 26 | `cache_as_bitmap/cab_mask_alpha` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 27 | `cache_as_bitmap/cab_mask_filters` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 28 | `cache_as_bitmap/cab_mask_transform` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 29 | `cache_as_bitmap/cab_mask_triangle` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 30 | `cache_as_bitmap/children_changed` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 31 | `cache_as_bitmap/color_transform` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 32 | `cache_as_bitmap/contains_grown_filter` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 33 | `cache_as_bitmap/drawing_api` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 34 | `cache_as_bitmap/edittext_hscroll` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 35 | `cache_as_bitmap/edittext_scroll` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 36 | `cache_as_bitmap/edittext_selection` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 37 | `cache_as_bitmap/masks` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 38 | `cache_as_bitmap/morph` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 39 | `cache_as_bitmap/nested_color_transform` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 40 | `cache_as_bitmap/nested_matrix` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 41 | `cache_as_bitmap/nested_rotation` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 42 | `cache_as_bitmap/oversize/swf_10_masks` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 43 | `cache_as_bitmap/oversize/swf_10_too_big` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 44 | `cache_as_bitmap/oversize/swf_9_masks` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 45 | `cache_as_bitmap/oversize/swf_9_too_big` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 46 | `cache_as_bitmap/scroll_rect` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 47 | `cache_as_bitmap/scroll_rect_scaled` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 48 | `cache_as_bitmap/shape_changed` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 49 | `cache_as_bitmap/text` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 50 | `color_transform_issue_9698` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 51 | `define_bits_jpeg2_huge` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 52 | `drawing_api/cursor` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 53 | `drawing_api/drawing_order` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 54 | `drawing_api/fills_and_lines` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 55 | `drawing_api/gradient_focal_point` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 56 | `edittext/edittext_background_basic` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 57 | `edittext/edittext_background_basic_scale2` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 58 | `edittext/edittext_border_basic` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 59 | `edittext/edittext_border_basic_scale2` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 60 | `edittext/edittext_border_filters` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 61 | `edittext/edittext_border_transform` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 62 | `edittext/edittext_bounds_vs_position` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 63 | `edittext/edittext_caret_empty` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 64 | `edittext/edittext_device_transform_basic` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 65 | `edittext/edittext_device_transform_small_rotation` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 66 | `edittext/edittext_device_transform_small_shear` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 67 | `edittext/edittext_gutter` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 68 | `edittext/edittext_justify` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 69 | `edittext/edittext_negative_bounds` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 70 | `edittext/edittext_selection_font_size` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 71 | `edittext/edittext_selection_leading` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 72 | `edittext/edittext_underline` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 73 | `edittext/edittext_underline_scale2` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 74 | `filters/any_blur_scales_with_screen` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 75 | `filters/avm1_convolution_initialization` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 76 | `filters/bevel` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 77 | `filters/bevel_full` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 78 | `filters/bevel_inner` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 79 | `filters/bevel_outer` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 80 | `filters/blur_fractional` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 81 | `filters/blur_pass_scaling` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 82 | `filters/blur_quality` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 83 | `filters/blur_scales_with_screen` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 84 | `filters/blur_size_grows` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 85 | `filters/color_matrix` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 86 | `filters/displacement_map` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 87 | `filters/displacement_map_scales_with_screen` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 88 | `filters/displacement_map_through_applyFilter` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 89 | `filters/displacement_map_through_filters` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 90 | `filters/drop_shadow` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 91 | `filters/drop_shadow_angles` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 92 | `filters/drop_shadow_scales_with_screen` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 93 | `filters/glow` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 94 | `filters/glow_pass_scaling` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 95 | `filters/glow_with_alpha_strength` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 96 | `filters/glow_without_composite_source` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 97 | `focus_highlight/focus_highlight_avm1_button` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 98 | `focus_highlight/focus_highlight_avm2_button_bounds` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 99 | `focus_highlight/focus_highlight_basic` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 100 | `focus_highlight/focus_highlight_empty_clip` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 101 | `focus_highlight/focus_highlight_move` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 102 | `focus_highlight/focus_highlight_render` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 103 | `fonts/advance_u16` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 104 | `fonts/device-font` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 105 | `fonts/duplicate_font` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 106 | `fonts/font_lookup_as3` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 107 | `fonts/glyph` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 108 | `fonts/leading_define_font` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 109 | `fonts/leading_device_font` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 110 | `fonts/leading_embedded_font` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 111 | `gradient_issue_9892` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 112 | `gradient_nonsequential_ratios` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 113 | `gradient_radial_same_ratios` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 114 | `gradient_same_ratios` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 115 | `layout/line_vertical_align` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 116 | `opaque_background` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 117 | `scale_rotation_cache` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 118 | `simple_shapes/gradients/focal_radial` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 119 | `simple_shapes/gradients/gradients` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 120 | `simple_shapes/gradients/radial` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 121 | `simple_shapes/gradients/reflect` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 122 | `simple_shapes/gradients/repeat` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 123 | `simple_shapes/heavy_tesselation` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 124 | `simple_shapes/layers` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 125 | `simple_shapes/masks` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 126 | `simple_shapes/masks_equal_clipdepth` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 127 | `simple_shapes/overlaps` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 128 | `simple_shapes/scroll_rect_mask` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 129 | `simple_shapes/strokes/scale` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 130 | `simple_shapes/text_field_mask` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 131 | `simple_shapes/winding_rule` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 132 | `text/String_path_variable_button` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 133 | `video/colorconversion/h263` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 134 | `video/colorconversion/vp6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 135 | `video/colorconversion/vp6a` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 136 | `video/deblocking` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 137 | `video/h264` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 138 | `video/h264_multinalu` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 139 | `video/vp6_alphaoffset` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 140 | `video/vp6_dispsize` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
