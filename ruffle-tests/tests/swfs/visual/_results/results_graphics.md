# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-24 22:06 UTC

**Git SHA**: `2cf4014fd6`

**Run Duration**: 26m 37s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 142 |
| Passing | **134** (94.4%) |
| Failing | 8 |
| Total expected lines | 350 |
| Matching lines | 238 (68.0%) |
| Mismatched lines | 112 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 6 | 75.0% |
| Recomp Fail | 1 | 12.5% |
| Runtime Error | 1 | 12.5% |

## Passing Tests

**134 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `bitmapdata_copypixels_with_alpha_oob` | 0 | 5.5s |  |
| 2 | `blend_modes/add` | 0 | 1.4s |  |
| 3 | `blend_modes/alpha_no_layer` | 0 | 1.6s |  |
| 4 | `blend_modes/darken` | 0 | 1.6s |  |
| 5 | `blend_modes/difference` | 0 | 2.2s |  |
| 6 | `blend_modes/erase_no_layer` | 0 | 2.2s |  |
| 7 | `blend_modes/hardlight` | 0 | 2.2s |  |
| 8 | `blend_modes/invert` | 0 | 2.2s |  |
| 9 | `blend_modes/layer_alpha` | 0 | 2.3s |  |
| 10 | `blend_modes/layer_erase` | 0 | 2.3s |  |
| 11 | `blend_modes/lighten` | 0 | 2.3s |  |
| 12 | `blend_modes/multiply` | 0 | 2.2s |  |
| 13 | `blend_modes/overlay` | 0 | 2.2s |  |
| 14 | `blend_modes/overlay_onto_stage` | 0 | 2.5s |  |
| 15 | `blend_modes/screen` | 0 | 1.9s |  |
| 16 | `blend_modes/shader_as_mask` | 0 | 25.2s |  |
| 17 | `blend_modes/shader_without_shader` | 1 | 23.7s |  |
| 18 | `blend_modes/subtract` | 0 | 1.9s |  |
| 19 | `bmd_draw_with_msaa_issue_10579` | 0 | 1.9s |  |
| 20 | `cache_as_bitmap/avm1_color` | 0 | 20.5s |  |
| 21 | `cache_as_bitmap/avm2_button` | 0 | 20.3s |  |
| 22 | `cache_as_bitmap/avm2_button_state` | 0 | 2.8s |  |
| 23 | `cache_as_bitmap/bitmap_changed` | 0 | 24.2s |  |
| 24 | `cache_as_bitmap/cab_bitmapdata_invalidate` | 0 | 24.4s |  |
| 25 | `cache_as_bitmap/cab_mask_alpha` | 0 | 26.1s |  |
| 26 | `cache_as_bitmap/cab_mask_filters` | 0 | 6.2s |  |
| 27 | `cache_as_bitmap/cab_mask_transform` | 0 | 24.7s |  |
| 28 | `cache_as_bitmap/cab_mask_triangle` | 0 | 7.4s |  |
| 29 | `cache_as_bitmap/children_changed` | 0 | 2.4s |  |
| 30 | `cache_as_bitmap/color_transform` | 0 | 2.4s |  |
| 31 | `cache_as_bitmap/contains_grown_filter` | 0 | 2.0s |  |
| 32 | `cache_as_bitmap/drawing_api` | 0 | 2.5s |  |
| 33 | `cache_as_bitmap/edittext_hscroll` | 1 | 21.2s |  |
| 34 | `cache_as_bitmap/edittext_scroll` | 0 | 21.0s |  |
| 35 | `cache_as_bitmap/edittext_selection` | 0 | 21.4s |  |
| 36 | `cache_as_bitmap/masks` | 0 | 9.4s |  |
| 37 | `cache_as_bitmap/morph` | 0 | 2.4s |  |
| 38 | `cache_as_bitmap/nested_color_transform` | 0 | 2.4s |  |
| 39 | `cache_as_bitmap/nested_matrix` | 0 | 2.3s |  |
| 40 | `cache_as_bitmap/nested_rotation` | 0 | 2.4s |  |
| 41 | `cache_as_bitmap/oversize/swf_10_masks` | 0 | 25.0s |  |
| 42 | `cache_as_bitmap/oversize/swf_10_too_big` | 0 | 5.8s |  |
| 43 | `cache_as_bitmap/oversize/swf_9_masks` | 0 | 3.1s |  |
| 44 | `cache_as_bitmap/oversize/swf_9_too_big` | 0 | 5.9s |  |
| 45 | `cache_as_bitmap/scroll_rect` | 0 | 2.3s |  |
| 46 | `cache_as_bitmap/scroll_rect_scaled` | 0 | 20.2s |  |
| 47 | `cache_as_bitmap/shape_changed` | 0 | 2.2s |  |
| 48 | `cache_as_bitmap/text` | 0 | 2.7s |  |
| 49 | `color_transform_issue_9698` | 0 | 1.9s |  |
| 50 | `definefont4` | 0 | 88.0s |  |
| 51 | `drawing_api/cursor` | 0 | 2.2s |  |
| 52 | `drawing_api/drawing_order` | 0 | 20.9s |  |
| 53 | `drawing_api/fills_and_lines` | 0 | 2.6s |  |
| 54 | `drawing_api/gradient_focal_point` | 0 | 20.9s |  |
| 55 | `edittext/edittext_background_basic` | 0 | 2.1s |  |
| 56 | `edittext/edittext_background_basic_scale2` | 0 | 20.2s |  |
| 57 | `edittext/edittext_border_basic` | 0 | 2.0s |  |
| 58 | `edittext/edittext_border_basic_scale2` | 0 | 1.8s |  |
| 59 | `edittext/edittext_border_filters` | 0 | 16.0s |  |
| 60 | `edittext/edittext_border_transform` | 0 | 2.0s |  |
| 61 | `edittext/edittext_bounds_vs_position` | 0 | 1.6s |  |
| 62 | `edittext/edittext_caret_empty` | 0 | 16.6s |  |
| 63 | `edittext/edittext_device_transform_small_rotation` | 0 | 21.1s |  |
| 64 | `edittext/edittext_device_transform_small_shear` | 0 | 2.4s |  |
| 65 | `edittext/edittext_gutter` | 0 | 24.3s |  |
| 66 | `edittext/edittext_justify` | 0 | 24.6s |  |
| 67 | `edittext/edittext_negative_bounds` | 0 | 2.1s |  |
| 68 | `edittext/edittext_selection_font_size` | 0 | 21.4s |  |
| 69 | `edittext/edittext_selection_leading` | 12 | 6.9s |  |
| 70 | `edittext/edittext_underline` | 0 | 25.6s |  |
| 71 | `edittext/edittext_underline_scale2` | 0 | 25.6s |  |
| 72 | `filters/any_blur_scales_with_screen` | 0 | 20.9s |  |
| 73 | `filters/bevel` | 0 | 22.9s |  |
| 74 | `filters/bevel_full` | 0 | 25.3s |  |
| 75 | `filters/bevel_inner` | 0 | 20.8s |  |
| 76 | `filters/bevel_outer` | 0 | 4.8s |  |
| 77 | `filters/blur_fractional` | 0 | 21.4s |  |
| 78 | `filters/blur_pass_scaling` | 0 | 21.2s |  |
| 79 | `filters/blur_quality` | 0 | 5.3s |  |
| 80 | `filters/blur_scales_with_screen` | 0 | 20.0s |  |
| 81 | `filters/blur_size_grows` | 0 | 2.6s |  |
| 82 | `filters/color_matrix` | 0 | 2.2s |  |
| 83 | `filters/displacement_map` | 0 | 25.3s |  |
| 84 | `filters/displacement_map_scales_with_screen` | 0 | 24.3s |  |
| 85 | `filters/displacement_map_through_applyFilter` | 0 | 24.0s |  |
| 86 | `filters/displacement_map_through_filters` | 0 | 5.8s |  |
| 87 | `filters/drop_shadow` | 0 | 2.6s |  |
| 88 | `filters/drop_shadow_angles` | 0 | 2.5s |  |
| 89 | `filters/drop_shadow_scales_with_screen` | 0 | 19.8s |  |
| 90 | `filters/glow` | 0 | 2.9s |  |
| 91 | `filters/glow_pass_scaling` | 0 | 24.2s |  |
| 92 | `filters/glow_with_alpha_strength` | 0 | 24.2s |  |
| 93 | `filters/glow_without_composite_source` | 0 | 2.6s |  |
| 94 | `focus_highlight/focus_highlight_avm1_button` | 6 | 20.5s |  |
| 95 | `focus_highlight/focus_highlight_avm2_button_bounds` | 1 | 23.9s |  |
| 96 | `focus_highlight/focus_highlight_basic` | 0 | 4.0s |  |
| 97 | `focus_highlight/focus_highlight_empty_clip` | 0 | 5.6s |  |
| 98 | `focus_highlight/focus_highlight_move` | 0 | 2.2s |  |
| 99 | `focus_highlight/focus_highlight_render` | 0 | 3.8s |  |
| 100 | `fonts/advance_u16` | 0 | 21.6s |  |
| 101 | `fonts/device-font` | 0 | 6.3s |  |
| 102 | `fonts/duplicate_font` | 0 | 6.6s |  |
| 103 | `fonts/font_lookup_as3` | 0 | 6.6s |  |
| 104 | `fonts/glyph` | 0 | 6.5s |  |
| 105 | `fonts/leading_define_font` | 0 | 21.6s |  |
| 106 | `fonts/leading_device_font` | 0 | 6.0s |  |
| 107 | `fonts/leading_embedded_font` | 0 | 6.5s |  |
| 108 | `gradient_issue_9892` | 0 | 21.7s |  |
| 109 | `gradient_nonsequential_ratios` | 0 | 2.1s |  |
| 110 | `gradient_radial_same_ratios` | 0 | 22.1s |  |
| 111 | `gradient_same_ratios` | 0 | 2.1s |  |
| 112 | `layout/line_vertical_align` | 0 | 25.9s |  |
| 113 | `opaque_background` | 0 | 2.3s |  |
| 114 | `scale_rotation_cache` | 106 | 21.3s |  |
| 115 | `simple_shapes/gradients/focal_radial` | 0 | 2.4s |  |
| 116 | `simple_shapes/gradients/gradients` | 0 | 2.5s |  |
| 117 | `simple_shapes/gradients/radial` | 0 | 2.7s |  |
| 118 | `simple_shapes/gradients/reflect` | 0 | 2.7s |  |
| 119 | `simple_shapes/gradients/repeat` | 0 | 2.6s |  |
| 120 | `simple_shapes/layers` | 0 | 1.9s |  |
| 121 | `simple_shapes/masks` | 0 | 1.9s |  |
| 122 | `simple_shapes/masks_equal_clipdepth` | 0 | 1.7s |  |
| 123 | `simple_shapes/overlaps` | 0 | 1.8s |  |
| 124 | `simple_shapes/scroll_rect_mask` | 0 | 1.9s |  |
| 125 | `simple_shapes/strokes/scale` | 0 | 1.9s |  |
| 126 | `simple_shapes/text_field_mask` | 0 | 2.0s |  |
| 127 | `simple_shapes/winding_rule` | 0 | 16.3s |  |
| 128 | `text/String_path_variable_button` | 0 | 2.5s |  |
| 129 | `video/colorconversion/h263` | 0 | 21.2s |  |
| 130 | `video/colorconversion/vp6` | 0 | 2.6s |  |
| 131 | `video/colorconversion/vp6a` | 0 | 2.9s |  |
| 132 | `video/h264` | 0 | 26.8s |  |
| 133 | `video/vp6_alphaoffset` | 0 | 21.3s |  |
| 134 | `video/vp6_dispsize` | 0 | 21.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**4 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `filters/avm1_convolution_initialization` | 94.4% | 17 | 18 | 1 |  |
| 2 | `edittext/edittext_device_transform_basic` | 50.0% | 12 | 24 | 12 |  |
| 3 | `edittext/edittext_device_transform_metrics` | 50.0% | 20 | 40 | 20 |  |
| 4 | `edittext/edittext_device_transform_negative` | 50.0% | 60 | 120 | 60 |  |

## Segfaults

No segfaults.

## Runtime Errors

**1 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `video/deblocking` | exit code -6 | 33.1s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**6 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `filters/avm1_convolution_initialization` | 94.4% | 17/18 | 18 | 18 |  |
| 2 | `edittext/edittext_device_transform_basic` | 50.0% | 12/24 | 24 | 24 |  |
| 3 | `edittext/edittext_device_transform_metrics` | 50.0% | 20/40 | 40 | 40 |  |
| 4 | `edittext/edittext_device_transform_negative` | 50.0% | 60/120 | 120 | 120 |  |
| 5 | `define_bits_jpeg2_huge` | 10.5% | 2/19 | 2 | 19 |  |
| 6 | `avm2_button_scroll_rect` | 0.0% | 0/2 | 2 | 2 |  |
