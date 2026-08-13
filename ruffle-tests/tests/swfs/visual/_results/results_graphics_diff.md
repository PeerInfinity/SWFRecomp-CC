# Ruffle Test Results Diff

**Previous:** `bf585e4486b6` (2026-08-12T23:11:20.726020+00:00)
**Current:** `16314e63feaa` (2026-08-13T21:54:57.563792+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 141 | 0 | -141 |
| Total | 144 | 144 | 0 |
| Pass rate | 97.9% | 0.0% | -97.9% |
| Mismatched lines | 49 | 0 | -49 |
|   Decreased | | | -49 |

## Newly Failing (141)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `avm2_button_scroll_rect` | compile_fail | 2/2 | - |
| `bitmapdata_copypixels_with_alpha_oob` | compile_fail | 0/0 | - |
| `blend_modes/add` | compile_fail | 0/0 | - |
| `blend_modes/alpha_no_layer` | compile_fail | 0/0 | - |
| `blend_modes/darken` | compile_fail | 0/0 | - |
| `blend_modes/difference` | compile_fail | 0/0 | - |
| `blend_modes/erase_no_layer` | compile_fail | 0/0 | - |
| `blend_modes/hardlight` | compile_fail | 0/0 | - |
| `blend_modes/invert` | compile_fail | 0/0 | - |
| `blend_modes/layer_alpha` | compile_fail | 0/0 | - |
| `blend_modes/layer_erase` | compile_fail | 0/0 | - |
| `blend_modes/lighten` | compile_fail | 0/0 | - |
| `blend_modes/multiply` | compile_fail | 0/0 | - |
| `blend_modes/overlay` | compile_fail | 0/0 | - |
| `blend_modes/overlay_onto_stage` | compile_fail | 0/0 | - |
| `blend_modes/screen` | compile_fail | 0/0 | - |
| `blend_modes/shader_as_mask` | compile_fail | 0/0 | - |
| `blend_modes/shader_without_shader` | compile_fail | 1/1 | - |
| `blend_modes/subtract` | compile_fail | 0/0 | - |
| `bmd_draw_with_msaa_issue_10579` | compile_fail | 0/0 | - |
| `cache_as_bitmap/avm1_color` | compile_fail | 0/0 | - |
| `cache_as_bitmap/avm2_button` | compile_fail | 0/0 | - |
| `cache_as_bitmap/avm2_button_state` | compile_fail | 0/0 | - |
| `cache_as_bitmap/bitmap_changed` | compile_fail | 0/0 | - |
| `cache_as_bitmap/cab_bitmapdata_invalidate` | compile_fail | 0/0 | - |
| `cache_as_bitmap/cab_mask_alpha` | compile_fail | 0/0 | - |
| `cache_as_bitmap/cab_mask_filters` | compile_fail | 0/0 | - |
| `cache_as_bitmap/cab_mask_transform` | compile_fail | 0/0 | - |
| `cache_as_bitmap/cab_mask_triangle` | compile_fail | 0/0 | - |
| `cache_as_bitmap/children_changed` | compile_fail | 0/0 | - |
| `cache_as_bitmap/color_transform` | compile_fail | 0/0 | - |
| `cache_as_bitmap/contains_grown_filter` | compile_fail | 0/0 | - |
| `cache_as_bitmap/drawing_api` | compile_fail | 0/0 | - |
| `cache_as_bitmap/edittext_hscroll` | compile_fail | 1/1 | - |
| `cache_as_bitmap/edittext_scroll` | compile_fail | 0/0 | - |
| `cache_as_bitmap/edittext_selection` | compile_fail | 0/0 | - |
| `cache_as_bitmap/masks` | compile_fail | 0/0 | - |
| `cache_as_bitmap/morph` | compile_fail | 0/0 | - |
| `cache_as_bitmap/nested_color_transform` | compile_fail | 0/0 | - |
| `cache_as_bitmap/nested_matrix` | compile_fail | 0/0 | - |
| `cache_as_bitmap/nested_rotation` | compile_fail | 0/0 | - |
| `cache_as_bitmap/oversize/swf_10_masks` | compile_fail | 0/0 | - |
| `cache_as_bitmap/oversize/swf_10_too_big` | compile_fail | 0/0 | - |
| `cache_as_bitmap/oversize/swf_9_masks` | compile_fail | 0/0 | - |
| `cache_as_bitmap/oversize/swf_9_too_big` | compile_fail | 0/0 | - |
| `cache_as_bitmap/scroll_rect` | compile_fail | 0/0 | - |
| `cache_as_bitmap/scroll_rect_scaled` | compile_fail | 0/0 | - |
| `cache_as_bitmap/shape_changed` | compile_fail | 0/0 | - |
| `cache_as_bitmap/text` | compile_fail | 0/0 | - |
| `color_transform_issue_9698` | compile_fail | 0/0 | - |
| `define_bits_jpeg2_huge` | compile_fail | 19/19 | - |
| `define_bits_lossless2_rgb15` | compile_fail | 0/0 | - |
| `drawing_api/cursor` | compile_fail | 0/0 | - |
| `drawing_api/drawing_order` | compile_fail | 0/0 | - |
| `drawing_api/fills_and_lines` | compile_fail | 0/0 | - |
| `drawing_api/gradient_focal_point` | compile_fail | 0/0 | - |
| `edittext/edittext_background_basic` | compile_fail | 0/0 | - |
| `edittext/edittext_background_basic_scale2` | compile_fail | 0/0 | - |
| `edittext/edittext_border_basic` | compile_fail | 0/0 | - |
| `edittext/edittext_border_basic_scale2` | compile_fail | 0/0 | - |
| `edittext/edittext_border_filters` | compile_fail | 0/0 | - |
| `edittext/edittext_border_transform` | compile_fail | 0/0 | - |
| `edittext/edittext_bounds_vs_position` | compile_fail | 0/0 | - |
| `edittext/edittext_caret_empty` | compile_fail | 0/0 | - |
| `edittext/edittext_device_transform_basic` | compile_fail | 24/24 | - |
| `edittext/edittext_device_transform_small_rotation` | compile_fail | 0/0 | - |
| `edittext/edittext_device_transform_small_shear` | compile_fail | 0/0 | - |
| `edittext/edittext_gutter` | compile_fail | 0/0 | - |
| `edittext/edittext_justify` | compile_fail | 0/0 | - |
| `edittext/edittext_negative_bounds` | compile_fail | 0/0 | - |
| `edittext/edittext_selection_font_size` | compile_fail | 0/0 | - |
| `edittext/edittext_selection_leading` | compile_fail | 12/12 | - |
| `edittext/edittext_underline` | compile_fail | 0/0 | - |
| `edittext/edittext_underline_scale2` | compile_fail | 0/0 | - |
| `filters/any_blur_scales_with_screen` | compile_fail | 0/0 | - |
| `filters/avm1_convolution_initialization` | compile_fail | 18/18 | - |
| `filters/bevel` | compile_fail | 0/0 | - |
| `filters/bevel_full` | compile_fail | 0/0 | - |
| `filters/bevel_inner` | compile_fail | 0/0 | - |
| `filters/bevel_outer` | compile_fail | 0/0 | - |
| `filters/blur_fractional` | compile_fail | 0/0 | - |
| `filters/blur_pass_scaling` | compile_fail | 0/0 | - |
| `filters/blur_quality` | compile_fail | 0/0 | - |
| `filters/blur_scales_with_screen` | compile_fail | 0/0 | - |
| `filters/blur_size_grows` | compile_fail | 0/0 | - |
| `filters/color_matrix` | compile_fail | 0/0 | - |
| `filters/displacement_map` | compile_fail | 0/0 | - |
| `filters/displacement_map_scales_with_screen` | compile_fail | 0/0 | - |
| `filters/displacement_map_through_applyFilter` | compile_fail | 0/0 | - |
| `filters/displacement_map_through_filters` | compile_fail | 0/0 | - |
| `filters/drop_shadow` | compile_fail | 0/0 | - |
| `filters/drop_shadow_angles` | compile_fail | 0/0 | - |
| `filters/drop_shadow_scales_with_screen` | compile_fail | 0/0 | - |
| `filters/glow` | compile_fail | 0/0 | - |
| `filters/glow_pass_scaling` | compile_fail | 0/0 | - |
| `filters/glow_with_alpha_strength` | compile_fail | 0/0 | - |
| `filters/glow_without_composite_source` | compile_fail | 0/0 | - |
| `focus_highlight/focus_highlight_avm1_button` | compile_fail | 6/6 | - |
| `focus_highlight/focus_highlight_avm2_button_bounds` | compile_fail | 1/1 | - |
| `focus_highlight/focus_highlight_basic` | compile_fail | 0/0 | - |
| `focus_highlight/focus_highlight_empty_clip` | compile_fail | 0/0 | - |
| `focus_highlight/focus_highlight_move` | compile_fail | 0/0 | - |
| `focus_highlight/focus_highlight_render` | compile_fail | 0/0 | - |
| `fonts/advance_u16` | compile_fail | 0/0 | - |
| `fonts/device-font` | compile_fail | 0/0 | - |
| `fonts/duplicate_font` | compile_fail | 0/0 | - |
| `fonts/font_lookup_as3` | compile_fail | 0/0 | - |
| `fonts/glyph` | compile_fail | 0/0 | - |
| `fonts/leading_define_font` | compile_fail | 0/0 | - |
| `fonts/leading_device_font` | compile_fail | 0/0 | - |
| `fonts/leading_embedded_font` | compile_fail | 0/0 | - |
| `gradient_issue_9892` | compile_fail | 0/0 | - |
| `gradient_nonsequential_ratios` | compile_fail | 0/0 | - |
| `gradient_radial_same_ratios` | compile_fail | 0/0 | - |
| `gradient_same_ratios` | compile_fail | 0/0 | - |
| `layout/line_vertical_align` | compile_fail | 0/0 | - |
| `opaque_background` | compile_fail | 0/0 | - |
| `scale_rotation_cache` | compile_fail | 106/106 | - |
| `simple_shapes/gradients/focal_radial` | compile_fail | 0/0 | - |
| `simple_shapes/gradients/gradients` | compile_fail | 0/0 | - |
| `simple_shapes/gradients/radial` | compile_fail | 0/0 | - |
| `simple_shapes/gradients/reflect` | compile_fail | 0/0 | - |
| `simple_shapes/gradients/repeat` | compile_fail | 0/0 | - |
| `simple_shapes/heavy_tesselation` | compile_fail | 0/0 | - |
| `simple_shapes/layers` | compile_fail | 0/0 | - |
| `simple_shapes/masks` | compile_fail | 0/0 | - |
| `simple_shapes/masks_equal_clipdepth` | compile_fail | 0/0 | - |
| `simple_shapes/overlaps` | compile_fail | 0/0 | - |
| `simple_shapes/scroll_rect_mask` | compile_fail | 0/0 | - |
| `simple_shapes/strokes/scale` | compile_fail | 0/0 | - |
| `simple_shapes/text_field_mask` | compile_fail | 0/0 | - |
| `simple_shapes/winding_rule` | compile_fail | 0/0 | - |
| `text/String_path_variable_button` | compile_fail | 0/0 | - |
| `video/colorconversion/h263` | compile_fail | 0/0 | - |
| `video/colorconversion/vp6` | compile_fail | 0/0 | - |
| `video/colorconversion/vp6a` | compile_fail | 0/0 | - |
| `video/deblocking` | compile_fail | 0/0 | - |
| `video/h264` | compile_fail | 0/0 | - |
| `video/h264_multinalu` | compile_fail | 0/0 | - |
| `video/vp6_alphaoffset` | compile_fail | 0/0 | - |
| `video/vp6_dispsize` | compile_fail | 0/0 | - |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `definefont4` | output_mismatch | compile_fail | 0/0 | - |
| `edittext/edittext_device_transform_metrics` | ruffle_matched | compile_fail | 32/40 | - |
| `edittext/edittext_device_transform_negative` | ruffle_matched | compile_fail | 79/120 | - |
