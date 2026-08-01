# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-01 07:44 UTC

**Git SHA**: `07c119c505`

**Run Duration**: 30m 35s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 143 |
| Passing | **137** (95.8%) |
| Failing | 6 |
| Total expected lines | 350 |
| Matching lines | 252 (72.0%) |
| Mismatched lines | 98 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 5 | 83.3% |
| Recomp Fail | 1 | 16.7% |

## Passing Tests

**137 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `avm2_button_scroll_rect` | 2 | 27.1s |  |
| 2 | `bitmapdata_copypixels_with_alpha_oob` | 0 | 8.2s |  |
| 3 | `blend_modes/add` | 0 | 2.6s |  |
| 4 | `blend_modes/alpha_no_layer` | 0 | 2.8s |  |
| 5 | `blend_modes/darken` | 0 | 2.5s |  |
| 6 | `blend_modes/difference` | 0 | 2.4s |  |
| 7 | `blend_modes/erase_no_layer` | 0 | 2.5s |  |
| 8 | `blend_modes/hardlight` | 0 | 2.3s |  |
| 9 | `blend_modes/invert` | 0 | 2.3s |  |
| 10 | `blend_modes/layer_alpha` | 0 | 2.4s |  |
| 11 | `blend_modes/layer_erase` | 0 | 2.5s |  |
| 12 | `blend_modes/lighten` | 0 | 2.6s |  |
| 13 | `blend_modes/multiply` | 0 | 2.5s |  |
| 14 | `blend_modes/overlay` | 0 | 2.3s |  |
| 15 | `blend_modes/overlay_onto_stage` | 0 | 2.7s |  |
| 16 | `blend_modes/screen` | 0 | 1.6s |  |
| 17 | `blend_modes/shader_as_mask` | 0 | 20.2s |  |
| 18 | `blend_modes/shader_without_shader` | 1 | 19.3s |  |
| 19 | `blend_modes/subtract` | 0 | 1.6s |  |
| 20 | `bmd_draw_with_msaa_issue_10579` | 0 | 15.3s |  |
| 21 | `cache_as_bitmap/avm1_color` | 0 | 21.9s |  |
| 22 | `cache_as_bitmap/avm2_button` | 0 | 20.5s |  |
| 23 | `cache_as_bitmap/avm2_button_state` | 0 | 21.0s |  |
| 24 | `cache_as_bitmap/bitmap_changed` | 0 | 21.7s |  |
| 25 | `cache_as_bitmap/cab_bitmapdata_invalidate` | 0 | 25.7s |  |
| 26 | `cache_as_bitmap/cab_mask_alpha` | 0 | 31.1s |  |
| 27 | `cache_as_bitmap/cab_mask_filters` | 0 | 8.4s |  |
| 28 | `cache_as_bitmap/cab_mask_transform` | 0 | 29.7s |  |
| 29 | `cache_as_bitmap/cab_mask_triangle` | 0 | 9.8s |  |
| 30 | `cache_as_bitmap/children_changed` | 0 | 2.7s |  |
| 31 | `cache_as_bitmap/color_transform` | 0 | 2.3s |  |
| 32 | `cache_as_bitmap/contains_grown_filter` | 0 | 2.0s |  |
| 33 | `cache_as_bitmap/drawing_api` | 0 | 2.4s |  |
| 34 | `cache_as_bitmap/edittext_hscroll` | 1 | 20.4s |  |
| 35 | `cache_as_bitmap/edittext_scroll` | 0 | 20.1s |  |
| 36 | `cache_as_bitmap/edittext_selection` | 0 | 17.5s |  |
| 37 | `cache_as_bitmap/masks` | 0 | 8.7s |  |
| 38 | `cache_as_bitmap/morph` | 0 | 2.0s |  |
| 39 | `cache_as_bitmap/nested_color_transform` | 0 | 2.0s |  |
| 40 | `cache_as_bitmap/nested_matrix` | 0 | 1.9s |  |
| 41 | `cache_as_bitmap/nested_rotation` | 0 | 2.5s |  |
| 42 | `cache_as_bitmap/oversize/swf_10_masks` | 0 | 26.9s |  |
| 43 | `cache_as_bitmap/oversize/swf_10_too_big` | 0 | 7.3s |  |
| 44 | `cache_as_bitmap/oversize/swf_9_masks` | 0 | 3.3s |  |
| 45 | `cache_as_bitmap/oversize/swf_9_too_big` | 0 | 7.3s |  |
| 46 | `cache_as_bitmap/scroll_rect` | 0 | 2.7s |  |
| 47 | `cache_as_bitmap/scroll_rect_scaled` | 0 | 22.0s |  |
| 48 | `cache_as_bitmap/shape_changed` | 0 | 2.5s |  |
| 49 | `cache_as_bitmap/text` | 0 | 3.0s |  |
| 50 | `color_transform_issue_9698` | 0 | 21.4s |  |
| 51 | `drawing_api/cursor` | 0 | 2.4s |  |
| 52 | `drawing_api/drawing_order` | 0 | 22.1s |  |
| 53 | `drawing_api/fills_and_lines` | 0 | 2.8s |  |
| 54 | `drawing_api/gradient_focal_point` | 0 | 21.1s |  |
| 55 | `edittext/edittext_background_basic` | 0 | 2.1s |  |
| 56 | `edittext/edittext_background_basic_scale2` | 0 | 20.9s |  |
| 57 | `edittext/edittext_border_basic` | 0 | 2.1s |  |
| 58 | `edittext/edittext_border_basic_scale2` | 0 | 1.9s |  |
| 59 | `edittext/edittext_border_filters` | 0 | 20.9s |  |
| 60 | `edittext/edittext_border_transform` | 0 | 2.6s |  |
| 61 | `edittext/edittext_bounds_vs_position` | 0 | 1.9s |  |
| 62 | `edittext/edittext_caret_empty` | 0 | 21.6s |  |
| 63 | `edittext/edittext_device_transform_small_rotation` | 0 | 21.3s |  |
| 64 | `edittext/edittext_device_transform_small_shear` | 0 | 2.4s |  |
| 65 | `edittext/edittext_gutter` | 0 | 26.7s |  |
| 66 | `edittext/edittext_justify` | 0 | 19.6s |  |
| 67 | `edittext/edittext_negative_bounds` | 0 | 1.6s |  |
| 68 | `edittext/edittext_selection_font_size` | 0 | 16.1s |  |
| 69 | `edittext/edittext_selection_leading` | 12 | 19.4s |  |
| 70 | `edittext/edittext_underline` | 0 | 19.9s |  |
| 71 | `edittext/edittext_underline_scale2` | 0 | 29.4s |  |
| 72 | `filters/any_blur_scales_with_screen` | 0 | 21.1s |  |
| 73 | `filters/avm1_convolution_initialization` | 18 | 2.1s |  |
| 74 | `filters/bevel` | 0 | 22.9s |  |
| 75 | `filters/bevel_full` | 0 | 25.4s |  |
| 76 | `filters/bevel_inner` | 0 | 20.0s |  |
| 77 | `filters/bevel_outer` | 0 | 5.0s |  |
| 78 | `filters/blur_fractional` | 0 | 21.7s |  |
| 79 | `filters/blur_pass_scaling` | 0 | 21.4s |  |
| 80 | `filters/blur_quality` | 0 | 6.7s |  |
| 81 | `filters/blur_scales_with_screen` | 0 | 17.7s |  |
| 82 | `filters/blur_size_grows` | 0 | 2.1s |  |
| 83 | `filters/color_matrix` | 0 | 1.7s |  |
| 84 | `filters/displacement_map` | 0 | 23.3s |  |
| 85 | `filters/displacement_map_scales_with_screen` | 0 | 23.4s |  |
| 86 | `filters/displacement_map_through_applyFilter` | 0 | 30.4s |  |
| 87 | `filters/displacement_map_through_filters` | 0 | 8.4s |  |
| 88 | `filters/drop_shadow` | 0 | 3.2s |  |
| 89 | `filters/drop_shadow_angles` | 0 | 3.0s |  |
| 90 | `filters/drop_shadow_scales_with_screen` | 0 | 24.3s |  |
| 91 | `filters/glow` | 0 | 3.1s |  |
| 92 | `filters/glow_pass_scaling` | 0 | 26.8s |  |
| 93 | `filters/glow_with_alpha_strength` | 0 | 25.0s |  |
| 94 | `filters/glow_without_composite_source` | 0 | 2.7s |  |
| 95 | `focus_highlight/focus_highlight_avm1_button` | 6 | 21.4s |  |
| 96 | `focus_highlight/focus_highlight_avm2_button_bounds` | 1 | 22.5s |  |
| 97 | `focus_highlight/focus_highlight_basic` | 0 | 3.0s |  |
| 98 | `focus_highlight/focus_highlight_empty_clip` | 0 | 2.3s |  |
| 99 | `focus_highlight/focus_highlight_move` | 0 | 1.8s |  |
| 100 | `focus_highlight/focus_highlight_render` | 0 | 3.0s |  |
| 101 | `fonts/advance_u16` | 0 | 20.5s |  |
| 102 | `fonts/device-font` | 0 | 7.4s |  |
| 103 | `fonts/duplicate_font` | 0 | 7.8s |  |
| 104 | `fonts/font_lookup_as3` | 0 | 7.7s |  |
| 105 | `fonts/glyph` | 0 | 7.5s |  |
| 106 | `fonts/leading_define_font` | 0 | 24.7s |  |
| 107 | `fonts/leading_device_font` | 0 | 30.1s |  |
| 108 | `fonts/leading_embedded_font` | 0 | 8.7s |  |
| 109 | `gradient_issue_9892` | 0 | 25.3s |  |
| 110 | `gradient_nonsequential_ratios` | 0 | 24.2s |  |
| 111 | `gradient_radial_same_ratios` | 0 | 20.8s |  |
| 112 | `gradient_same_ratios` | 0 | 20.6s |  |
| 113 | `layout/line_vertical_align` | 0 | 25.9s |  |
| 114 | `opaque_background` | 0 | 2.3s |  |
| 115 | `scale_rotation_cache` | 106 | 22.4s |  |
| 116 | `simple_shapes/gradients/focal_radial` | 0 | 2.6s |  |
| 117 | `simple_shapes/gradients/gradients` | 0 | 2.6s |  |
| 118 | `simple_shapes/gradients/radial` | 0 | 2.8s |  |
| 119 | `simple_shapes/gradients/reflect` | 0 | 2.9s |  |
| 120 | `simple_shapes/gradients/repeat` | 0 | 2.9s |  |
| 121 | `simple_shapes/layers` | 0 | 2.5s |  |
| 122 | `simple_shapes/masks` | 0 | 1.4s |  |
| 123 | `simple_shapes/masks_equal_clipdepth` | 0 | 1.4s |  |
| 124 | `simple_shapes/overlaps` | 0 | 1.3s |  |
| 125 | `simple_shapes/scroll_rect_mask` | 0 | 1.4s |  |
| 126 | `simple_shapes/strokes/scale` | 0 | 2.6s |  |
| 127 | `simple_shapes/text_field_mask` | 0 | 2.8s |  |
| 128 | `simple_shapes/winding_rule` | 0 | 24.4s |  |
| 129 | `text/String_path_variable_button` | 0 | 2.7s |  |
| 130 | `video/colorconversion/h263` | 0 | 23.2s |  |
| 131 | `video/colorconversion/vp6` | 0 | 2.8s |  |
| 132 | `video/colorconversion/vp6a` | 0 | 3.0s |  |
| 133 | `video/deblocking` | 0 | 25.8s |  |
| 134 | `video/h264` | 0 | 29.0s |  |
| 135 | `video/h264_multinalu` | 0 | 27.4s |  |
| 136 | `video/vp6_alphaoffset` | 0 | 22.3s |  |
| 137 | `video/vp6_dispsize` | 0 | 22.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**4 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `define_bits_jpeg2_huge` | 68.4% | 13 | 19 | 6 |  |
| 2 | `edittext/edittext_device_transform_basic` | 50.0% | 12 | 24 | 12 |  |
| 3 | `edittext/edittext_device_transform_metrics` | 50.0% | 20 | 40 | 20 |  |
| 4 | `edittext/edittext_device_transform_negative` | 50.0% | 60 | 120 | 60 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**5 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `define_bits_jpeg2_huge` | 68.4% | 13/19 | 19 | 19 |  |
| 2 | `edittext/edittext_device_transform_basic` | 50.0% | 12/24 | 24 | 24 |  |
| 3 | `edittext/edittext_device_transform_metrics` | 50.0% | 20/40 | 40 | 40 |  |
| 4 | `edittext/edittext_device_transform_negative` | 50.0% | 60/120 | 120 | 120 |  |
| 5 | `definefont4` | 0.0% | 0/24 | 24 | 0 |  |
