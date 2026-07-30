# Ruffle Test Results (Filtered)

**Date**: 2026-07-30 18:36 UTC

**Git SHA**: `2358a37b1c`

**Run Duration**: 30m 0s

**Filtered**: 0 tests ignored out of 143 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 143 |
| Passing | **137** (95.8%) |
| Failing | 6 |
| Total expected lines | 350 |
| Matching lines | 239 (68.3%) |
| Mismatched lines | 111 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 5 | 83.3% |
| Recomp Fail | 1 | 16.7% |

## Passing Tests

**137 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `bitmapdata_copypixels_with_alpha_oob` | 0 | 8.1s |  |
| 2 | `blend_modes/add` | 0 | 2.7s |  |
| 3 | `blend_modes/alpha_no_layer` | 0 | 2.8s |  |
| 4 | `blend_modes/darken` | 0 | 2.6s |  |
| 5 | `blend_modes/difference` | 0 | 2.4s |  |
| 6 | `blend_modes/erase_no_layer` | 0 | 2.4s |  |
| 7 | `blend_modes/hardlight` | 0 | 2.2s |  |
| 8 | `blend_modes/invert` | 0 | 2.2s |  |
| 9 | `blend_modes/layer_alpha` | 0 | 2.3s |  |
| 10 | `blend_modes/layer_erase` | 0 | 2.4s |  |
| 11 | `blend_modes/lighten` | 0 | 2.5s |  |
| 12 | `blend_modes/multiply` | 0 | 2.4s |  |
| 13 | `blend_modes/overlay` | 0 | 2.2s |  |
| 14 | `blend_modes/overlay_onto_stage` | 0 | 2.5s |  |
| 15 | `blend_modes/screen` | 0 | 2.4s |  |
| 16 | `blend_modes/shader_as_mask` | 0 | 27.6s |  |
| 17 | `blend_modes/shader_without_shader` | 1 | 25.8s |  |
| 18 | `blend_modes/subtract` | 0 | 2.6s |  |
| 19 | `bmd_draw_with_msaa_issue_10579` | 0 | 21.0s |  |
| 20 | `cache_as_bitmap/avm1_color` | 0 | 22.4s |  |
| 21 | `cache_as_bitmap/avm2_button` | 0 | 21.6s |  |
| 22 | `cache_as_bitmap/avm2_button_state` | 0 | 23.3s |  |
| 23 | `cache_as_bitmap/bitmap_changed` | 0 | 26.5s |  |
| 24 | `cache_as_bitmap/cab_bitmapdata_invalidate` | 0 | 26.2s |  |
| 25 | `cache_as_bitmap/cab_mask_alpha` | 0 | 28.5s |  |
| 26 | `cache_as_bitmap/cab_mask_filters` | 0 | 7.8s |  |
| 27 | `cache_as_bitmap/cab_mask_transform` | 0 | 27.4s |  |
| 28 | `cache_as_bitmap/cab_mask_triangle` | 0 | 9.2s |  |
| 29 | `cache_as_bitmap/children_changed` | 0 | 2.5s |  |
| 30 | `cache_as_bitmap/color_transform` | 0 | 2.6s |  |
| 31 | `cache_as_bitmap/contains_grown_filter` | 0 | 2.2s |  |
| 32 | `cache_as_bitmap/drawing_api` | 0 | 2.7s |  |
| 33 | `cache_as_bitmap/edittext_hscroll` | 1 | 21.7s |  |
| 34 | `cache_as_bitmap/edittext_scroll` | 0 | 21.9s |  |
| 35 | `cache_as_bitmap/edittext_selection` | 0 | 19.4s |  |
| 36 | `cache_as_bitmap/masks` | 0 | 8.8s |  |
| 37 | `cache_as_bitmap/morph` | 0 | 1.9s |  |
| 38 | `cache_as_bitmap/nested_color_transform` | 0 | 1.9s |  |
| 39 | `cache_as_bitmap/nested_matrix` | 0 | 1.9s |  |
| 40 | `cache_as_bitmap/nested_rotation` | 0 | 2.5s |  |
| 41 | `cache_as_bitmap/oversize/swf_10_masks` | 0 | 26.1s |  |
| 42 | `cache_as_bitmap/oversize/swf_10_too_big` | 0 | 7.1s |  |
| 43 | `cache_as_bitmap/oversize/swf_9_masks` | 0 | 3.3s |  |
| 44 | `cache_as_bitmap/oversize/swf_9_too_big` | 0 | 7.2s |  |
| 45 | `cache_as_bitmap/scroll_rect` | 0 | 1.6s |  |
| 46 | `cache_as_bitmap/scroll_rect_scaled` | 0 | 13.7s |  |
| 47 | `cache_as_bitmap/shape_changed` | 0 | 1.6s |  |
| 48 | `cache_as_bitmap/text` | 0 | 1.9s |  |
| 49 | `color_transform_issue_9698` | 0 | 13.8s |  |
| 50 | `definefont4` | 0 | 93.5s |  |
| 51 | `drawing_api/cursor` | 0 | 2.4s |  |
| 52 | `drawing_api/drawing_order` | 0 | 2.6s |  |
| 53 | `drawing_api/fills_and_lines` | 0 | 2.8s |  |
| 54 | `drawing_api/gradient_focal_point` | 0 | 21.3s |  |
| 55 | `edittext/edittext_background_basic` | 0 | 2.2s |  |
| 56 | `edittext/edittext_background_basic_scale2` | 0 | 20.7s |  |
| 57 | `edittext/edittext_border_basic` | 0 | 2.1s |  |
| 58 | `edittext/edittext_border_basic_scale2` | 0 | 1.9s |  |
| 59 | `edittext/edittext_border_filters` | 0 | 21.6s |  |
| 60 | `edittext/edittext_border_transform` | 0 | 2.8s |  |
| 61 | `edittext/edittext_bounds_vs_position` | 0 | 2.1s |  |
| 62 | `edittext/edittext_caret_empty` | 0 | 22.3s |  |
| 63 | `edittext/edittext_device_transform_small_rotation` | 0 | 20.4s |  |
| 64 | `edittext/edittext_device_transform_small_shear` | 0 | 2.3s |  |
| 65 | `edittext/edittext_gutter` | 0 | 25.5s |  |
| 66 | `edittext/edittext_justify` | 0 | 27.1s |  |
| 67 | `edittext/edittext_negative_bounds` | 0 | 2.2s |  |
| 68 | `edittext/edittext_selection_font_size` | 0 | 22.6s |  |
| 69 | `edittext/edittext_selection_leading` | 12 | 27.7s |  |
| 70 | `edittext/edittext_underline` | 0 | 27.9s |  |
| 71 | `edittext/edittext_underline_scale2` | 0 | 28.0s |  |
| 72 | `filters/any_blur_scales_with_screen` | 0 | 20.9s |  |
| 73 | `filters/avm1_convolution_initialization` | 18 | 2.1s |  |
| 74 | `filters/bevel` | 0 | 23.1s |  |
| 75 | `filters/bevel_full` | 0 | 25.5s |  |
| 76 | `filters/bevel_inner` | 0 | 25.0s |  |
| 77 | `filters/bevel_outer` | 0 | 6.1s |  |
| 78 | `filters/blur_fractional` | 0 | 26.7s |  |
| 79 | `filters/blur_pass_scaling` | 0 | 26.5s |  |
| 80 | `filters/blur_quality` | 0 | 8.1s |  |
| 81 | `filters/blur_scales_with_screen` | 0 | 20.5s |  |
| 82 | `filters/blur_size_grows` | 0 | 2.6s |  |
| 83 | `filters/color_matrix` | 0 | 2.2s |  |
| 84 | `filters/displacement_map` | 0 | 27.4s |  |
| 85 | `filters/displacement_map_scales_with_screen` | 0 | 26.9s |  |
| 86 | `filters/displacement_map_through_applyFilter` | 0 | 27.9s |  |
| 87 | `filters/displacement_map_through_filters` | 0 | 7.8s |  |
| 88 | `filters/drop_shadow` | 0 | 3.0s |  |
| 89 | `filters/drop_shadow_angles` | 0 | 2.8s |  |
| 90 | `filters/drop_shadow_scales_with_screen` | 0 | 21.9s |  |
| 91 | `filters/glow` | 0 | 3.1s |  |
| 92 | `filters/glow_pass_scaling` | 0 | 26.9s |  |
| 93 | `filters/glow_with_alpha_strength` | 0 | 25.4s |  |
| 94 | `filters/glow_without_composite_source` | 0 | 2.8s |  |
| 95 | `focus_highlight/focus_highlight_avm1_button` | 6 | 21.3s |  |
| 96 | `focus_highlight/focus_highlight_avm2_button_bounds` | 1 | 18.6s |  |
| 97 | `focus_highlight/focus_highlight_basic` | 0 | 2.5s |  |
| 98 | `focus_highlight/focus_highlight_empty_clip` | 0 | 4.8s |  |
| 99 | `focus_highlight/focus_highlight_move` | 0 | 2.0s |  |
| 100 | `focus_highlight/focus_highlight_render` | 0 | 2.7s |  |
| 101 | `fonts/advance_u16` | 0 | 20.7s |  |
| 102 | `fonts/device-font` | 0 | 7.3s |  |
| 103 | `fonts/duplicate_font` | 0 | 7.6s |  |
| 104 | `fonts/font_lookup_as3` | 0 | 7.5s |  |
| 105 | `fonts/glyph` | 0 | 7.4s |  |
| 106 | `fonts/leading_define_font` | 0 | 17.5s |  |
| 107 | `fonts/leading_device_font` | 0 | 21.2s |  |
| 108 | `fonts/leading_embedded_font` | 0 | 6.2s |  |
| 109 | `gradient_issue_9892` | 0 | 17.6s |  |
| 110 | `gradient_nonsequential_ratios` | 0 | 17.0s |  |
| 111 | `gradient_radial_same_ratios` | 0 | 21.6s |  |
| 112 | `gradient_same_ratios` | 0 | 21.7s |  |
| 113 | `layout/line_vertical_align` | 0 | 27.5s |  |
| 114 | `opaque_background` | 0 | 2.6s |  |
| 115 | `scale_rotation_cache` | 106 | 18.4s |  |
| 116 | `simple_shapes/gradients/focal_radial` | 0 | 2.1s |  |
| 117 | `simple_shapes/gradients/gradients` | 0 | 1.9s |  |
| 118 | `simple_shapes/gradients/radial` | 0 | 2.0s |  |
| 119 | `simple_shapes/gradients/reflect` | 0 | 2.9s |  |
| 120 | `simple_shapes/gradients/repeat` | 0 | 2.8s |  |
| 121 | `simple_shapes/layers` | 0 | 2.5s |  |
| 122 | `simple_shapes/masks` | 0 | 2.0s |  |
| 123 | `simple_shapes/masks_equal_clipdepth` | 0 | 1.8s |  |
| 124 | `simple_shapes/overlaps` | 0 | 1.9s |  |
| 125 | `simple_shapes/scroll_rect_mask` | 0 | 1.8s |  |
| 126 | `simple_shapes/strokes/scale` | 0 | 0.8s |  |
| 127 | `simple_shapes/text_field_mask` | 0 | 0.8s |  |
| 128 | `simple_shapes/winding_rule` | 0 | 0.7s |  |
| 129 | `text/String_path_variable_button` | 0 | 0.7s |  |
| 130 | `video/colorconversion/h263` | 0 | 21.6s |  |
| 131 | `video/colorconversion/vp6` | 0 | 2.7s |  |
| 132 | `video/colorconversion/vp6a` | 0 | 2.9s |  |
| 133 | `video/deblocking` | 0 | 24.5s |  |
| 134 | `video/h264` | 0 | 27.4s |  |
| 135 | `video/h264_multinalu` | 0 | 25.8s |  |
| 136 | `video/vp6_alphaoffset` | 0 | 21.1s |  |
| 137 | `video/vp6_dispsize` | 0 | 21.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `edittext/edittext_device_transform_basic` | 50.0% | 12 | 24 | 12 |  |
| 2 | `edittext/edittext_device_transform_metrics` | 50.0% | 20 | 40 | 20 |  |
| 3 | `edittext/edittext_device_transform_negative` | 50.0% | 60 | 120 | 60 |  |

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
| 1 | `edittext/edittext_device_transform_basic` | 50.0% | 12/24 | 24 | 24 |  |
| 2 | `edittext/edittext_device_transform_metrics` | 50.0% | 20/40 | 40 | 40 |  |
| 3 | `edittext/edittext_device_transform_negative` | 50.0% | 60/120 | 120 | 120 |  |
| 4 | `define_bits_jpeg2_huge` | 10.5% | 2/19 | 2 | 19 |  |
| 5 | `avm2_button_scroll_rect` | 0.0% | 0/2 | 2 | 2 |  |
