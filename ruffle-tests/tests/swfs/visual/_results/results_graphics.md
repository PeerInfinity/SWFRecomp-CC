# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-23 23:56 UTC

**Git SHA**: `005bea42a2`

**Run Duration**: 33m 45s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 146 |
| Passing | **144** (98.6%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **146** (100.0%) |
| Failing | 0 |
| Total expected lines | 350 |
| Matching lines | 301 (86.0%) |
| Mismatched lines | 49 |

## Passing Tests

**144 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `avm2_button_scroll_rect` | 2 | 24.1s |  |
| 2 | `bitmapdata_copypixels_with_alpha_oob` | 0 | 7.5s |  |
| 3 | `blend_across_masks_issue_24549` | 0 | 1.5s |  |
| 4 | `blend_modes/add` | 0 | 1.9s |  |
| 5 | `blend_modes/alpha_no_layer` | 0 | 1.8s |  |
| 6 | `blend_modes/darken` | 0 | 1.8s |  |
| 7 | `blend_modes/difference` | 0 | 1.9s |  |
| 8 | `blend_modes/erase_no_layer` | 0 | 1.9s |  |
| 9 | `blend_modes/hardlight` | 0 | 1.7s |  |
| 10 | `blend_modes/invert` | 0 | 1.8s |  |
| 11 | `blend_modes/layer_alpha` | 0 | 1.9s |  |
| 12 | `blend_modes/layer_erase` | 0 | 3.0s |  |
| 13 | `blend_modes/lighten` | 0 | 2.9s |  |
| 14 | `blend_modes/masked_layer_cached_children` | 0 | 31.9s |  |
| 15 | `blend_modes/multiply` | 0 | 2.9s |  |
| 16 | `blend_modes/overlay` | 0 | 2.7s |  |
| 17 | `blend_modes/overlay_onto_stage` | 0 | 1.7s |  |
| 18 | `blend_modes/screen` | 0 | 1.9s |  |
| 19 | `blend_modes/shader_as_mask` | 0 | 25.6s |  |
| 20 | `blend_modes/shader_without_shader` | 1 | 24.0s |  |
| 21 | `blend_modes/subtract` | 0 | 1.9s |  |
| 22 | `bmd_draw_with_msaa_issue_10579` | 0 | 1.7s |  |
| 23 | `cache_as_bitmap/avm1_color` | 0 | 18.7s |  |
| 24 | `cache_as_bitmap/avm2_button` | 0 | 18.7s |  |
| 25 | `cache_as_bitmap/avm2_button_state` | 0 | 18.9s |  |
| 26 | `cache_as_bitmap/bitmap_changed` | 0 | 24.1s |  |
| 27 | `cache_as_bitmap/cab_bitmapdata_invalidate` | 0 | 30.9s |  |
| 28 | `cache_as_bitmap/cab_mask_alpha` | 0 | 33.1s |  |
| 29 | `cache_as_bitmap/cab_mask_filters` | 0 | 9.5s |  |
| 30 | `cache_as_bitmap/cab_mask_transform` | 0 | 31.2s |  |
| 31 | `cache_as_bitmap/cab_mask_triangle` | 0 | 11.0s |  |
| 32 | `cache_as_bitmap/children_changed` | 0 | 1.6s |  |
| 33 | `cache_as_bitmap/color_transform` | 0 | 1.6s |  |
| 34 | `cache_as_bitmap/contains_grown_filter` | 0 | 18.5s |  |
| 35 | `cache_as_bitmap/drawing_api` | 0 | 1.7s |  |
| 36 | `cache_as_bitmap/edittext_hscroll` | 1 | 18.8s |  |
| 37 | `cache_as_bitmap/nested_matrix` | 0 | 2.7s |  |
| 38 | `cache_as_bitmap/nested_rotation` | 0 | 2.5s |  |
| 39 | `cache_as_bitmap/oversize/swf_10_masks` | 0 | 31.4s |  |
| 40 | `cache_as_bitmap/oversize/swf_10_too_big` | 0 | 9.4s |  |
| 41 | `cache_as_bitmap/oversize/swf_9_masks` | 0 | 3.7s |  |
| 42 | `cache_as_bitmap/oversize/swf_9_too_big` | 0 | 24.4s |  |
| 43 | `cache_as_bitmap/scroll_rect` | 0 | 5.1s |  |
| 44 | `cache_as_bitmap/scroll_rect_scaled` | 0 | 18.7s |  |
| 45 | `cache_as_bitmap/shape_changed` | 0 | 1.6s |  |
| 46 | `cache_as_bitmap/text` | 0 | 1.8s |  |
| 47 | `color_transform_issue_9698` | 0 | 18.4s |  |
| 48 | `define_bits_jpeg2_huge` | 19 | 20.2s |  |
| 49 | `define_bits_lossless2_rgb15` | 0 | 1.5s |  |
| 50 | `definefont4` | 0 | 83.8s |  |
| 51 | `drawing_api/cursor` | 0 | 1.6s |  |
| 52 | `drawing_api/drawing_order` | 0 | 19.3s |  |
| 53 | `drawing_api/fills_and_lines` | 0 | 2.0s |  |
| 54 | `drawing_api/gradient_focal_point` | 0 | 19.5s |  |
| 55 | `edittext/edittext_background_basic` | 0 | 1.7s |  |
| 56 | `edittext/edittext_background_basic_scale2` | 0 | 19.0s |  |
| 57 | `edittext/edittext_border_basic` | 0 | 18.8s |  |
| 58 | `edittext/edittext_border_basic_scale2` | 0 | 18.6s |  |
| 59 | `edittext/edittext_border_filters` | 0 | 1.6s |  |
| 60 | `edittext/edittext_border_transform` | 0 | 1.9s |  |
| 61 | `edittext/edittext_bounds_vs_position` | 0 | 18.6s |  |
| 62 | `edittext/edittext_caret_empty` | 0 | 18.9s |  |
| 63 | `edittext/edittext_caret_multiline` | 0 | 24.6s |  |
| 64 | `edittext/edittext_device_transform_basic` | 24 | 24.3s |  |
| 65 | `edittext/edittext_device_transform_small_rotation` | 0 | 20.8s |  |
| 66 | `edittext/edittext_device_transform_small_shear` | 0 | 18.8s |  |
| 67 | `edittext/edittext_gutter` | 0 | 24.3s |  |
| 68 | `edittext/edittext_justify` | 0 | 24.5s |  |
| 69 | `edittext/edittext_negative_bounds` | 0 | 1.5s |  |
| 70 | `edittext/edittext_selection_font_size` | 0 | 24.0s |  |
| 71 | `edittext/edittext_selection_leading` | 12 | 24.3s |  |
| 72 | `edittext/edittext_underline` | 0 | 24.6s |  |
| 73 | `edittext/edittext_underline_scale2` | 0 | 25.7s |  |
| 74 | `filters/any_blur_scales_with_screen` | 0 | 18.5s |  |
| 75 | `filters/avm1_convolution_initialization` | 18 | 1.5s |  |
| 76 | `filters/bevel` | 0 | 19.1s |  |
| 77 | `filters/bevel_full` | 0 | 20.0s |  |
| 78 | `filters/bevel_inner` | 0 | 2.9s |  |
| 79 | `filters/bevel_outer` | 0 | 3.0s |  |
| 80 | `filters/blur_fractional` | 0 | 24.4s |  |
| 81 | `filters/blur_pass_scaling` | 0 | 25.7s |  |
| 82 | `filters/blur_quality` | 0 | 7.3s |  |
| 83 | `filters/blur_scales_with_screen` | 0 | 18.4s |  |
| 84 | `filters/blur_size_grows` | 0 | 1.8s |  |
| 85 | `filters/color_matrix` | 0 | 2.3s |  |
| 86 | `filters/displacement_map` | 0 | 34.8s |  |
| 87 | `filters/displacement_map_scales_with_screen` | 0 | 36.3s |  |
| 88 | `filters/displacement_map_through_applyFilter` | 0 | 33.5s |  |
| 89 | `filters/displacement_map_through_filters` | 0 | 9.5s |  |
| 90 | `filters/drop_shadow` | 0 | 2.2s |  |
| 91 | `filters/drop_shadow_angles` | 0 | 1.9s |  |
| 92 | `filters/drop_shadow_scales_with_screen` | 0 | 18.7s |  |
| 93 | `filters/empty_child_filter_bounds` | 0 | 19.0s |  |
| 94 | `filters/glow` | 0 | 1.8s |  |
| 95 | `filters/glow_pass_scaling` | 0 | 25.6s |  |
| 96 | `filters/glow_with_alpha_strength` | 0 | 20.3s |  |
| 97 | `filters/glow_without_composite_source` | 0 | 1.8s |  |
| 98 | `focus_highlight/focus_highlight_avm1_button` | 6 | 18.5s |  |
| 99 | `focus_highlight/focus_highlight_avm2_button_bounds` | 1 | 23.8s |  |
| 100 | `focus_highlight/focus_highlight_basic` | 0 | 5.9s |  |
| 101 | `focus_highlight/focus_highlight_empty_clip` | 0 | 24.1s |  |
| 102 | `focus_highlight/focus_highlight_move` | 0 | 18.6s |  |
| 103 | `focus_highlight/focus_highlight_render` | 0 | 2.3s |  |
| 104 | `fonts/advance_u16` | 0 | 20.5s |  |
| 105 | `fonts/device-font` | 0 | 12.2s |  |
| 106 | `fonts/duplicate_font` | 0 | 8.3s |  |
| 107 | `fonts/font_lookup_as3` | 0 | 8.1s |  |
| 108 | `fonts/glyph` | 0 | 8.1s |  |
| 109 | `fonts/leading_define_font` | 0 | 23.4s |  |
| 110 | `fonts/leading_device_font` | 0 | 24.2s |  |
| 111 | `fonts/leading_embedded_font` | 0 | 7.2s |  |
| 112 | `gradient_issue_9892` | 0 | 19.1s |  |
| 113 | `gradient_nonsequential_ratios` | 0 | 18.8s |  |
| 114 | `gradient_radial_same_ratios` | 0 | 18.7s |  |
| 115 | `gradient_same_ratios` | 0 | 18.5s |  |
| 116 | `layout/line_vertical_align` | 0 | 24.3s |  |
| 117 | `opaque_background` | 0 | 1.6s |  |
| 118 | `scale_rotation_cache` | 106 | 19.1s |  |
| 119 | `scroll_rect_culling` | 0 | 24.8s |  |
| 120 | `simple_shapes/gradients/focal_radial` | 0 | 1.7s |  |
| 121 | `simple_shapes/gradients/gradients` | 0 | 1.7s |  |
| 122 | `simple_shapes/gradients/radial` | 0 | 1.8s |  |
| 123 | `simple_shapes/gradients/reflect` | 0 | 1.8s |  |
| 124 | `simple_shapes/gradients/repeat` | 0 | 1.8s |  |
| 125 | `simple_shapes/heavy_tesselation` | 0 | 84.2s |  |
| 126 | `simple_shapes/layers` | 0 | 2.5s |  |
| 127 | `simple_shapes/masks` | 0 | 3.0s |  |
| 128 | `simple_shapes/masks_equal_clipdepth` | 0 | 2.3s |  |
| 129 | `simple_shapes/overlaps` | 0 | 2.5s |  |
| 130 | `simple_shapes/scroll_rect_mask` | 0 | 4.3s |  |
| 131 | `simple_shapes/strokes/scale` | 0 | 4.2s |  |
| 132 | `simple_shapes/text_field_mask` | 0 | 1.9s |  |
| 133 | `simple_shapes/winding_rule` | 0 | 19.1s |  |
| 134 | `static_text_offstage` | 0 | 19.4s |  |
| 135 | `text/String_path_variable_button` | 0 | 5.2s |  |
| 136 | `video/colorconversion/h263` | 0 | 18.8s |  |
| 137 | `video/colorconversion/vp6` | 0 | 1.7s |  |
| 138 | `video/colorconversion/vp6a` | 0 | 1.9s |  |
| 139 | `video/deblocking` | 0 | 19.8s |  |
| 140 | `video/h264` | 0 | 30.5s |  |
| 141 | `video/h264_multinalu` | 0 | 25.5s |  |
| 142 | `video/vp6_alphaoffset` | 0 | 19.4s |  |
| 143 | `video/vp6_dispsize` | 0 | 19.4s |  |
| 144 | `video/vp6_inter_frames` | 0 | 21.3s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `edittext/edittext_device_transform_metrics` | 8 | 8 | 6.9s |  |
| 2 | `edittext/edittext_device_transform_negative` | 41 | 41 | 7.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**0 tests** within reach

No tests above 50% match threshold.

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**0 tests** with output mismatch, sorted by match rate (best first)

No output mismatches.
