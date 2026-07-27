# Ruffle Test Results (Filtered)

**Date**: 2026-07-27 04:25 UTC

**Git SHA**: `a9900a4786`

**Run Duration**: 30m 6s

**Filtered**: 0 tests ignored out of 142 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 142 |
| Passing | **121** (85.2%) |
| Failing | 21 |
| Total expected lines | 350 |
| Matching lines | 238 (68.0%) |
| Mismatched lines | 112 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 19 | 90.5% |
| Recomp Fail | 1 | 4.8% |
| Runtime Error | 1 | 4.8% |

## Passing Tests

**121 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `bitmapdata_copypixels_with_alpha_oob` | 0 | 6.0s |  |
| 2 | `blend_modes/add` | 0 | 2.0s |  |
| 3 | `blend_modes/alpha_no_layer` | 0 | 2.1s |  |
| 4 | `blend_modes/darken` | 0 | 2.2s |  |
| 5 | `blend_modes/difference` | 0 | 1.8s |  |
| 6 | `blend_modes/erase_no_layer` | 0 | 1.7s |  |
| 7 | `blend_modes/hardlight` | 0 | 1.6s |  |
| 8 | `blend_modes/invert` | 0 | 1.6s |  |
| 9 | `blend_modes/layer_alpha` | 0 | 1.8s |  |
| 10 | `blend_modes/layer_erase` | 0 | 1.5s |  |
| 11 | `blend_modes/lighten` | 0 | 1.5s |  |
| 12 | `blend_modes/multiply` | 0 | 1.5s |  |
| 13 | `blend_modes/overlay` | 0 | 1.4s |  |
| 14 | `blend_modes/overlay_onto_stage` | 0 | 1.6s |  |
| 15 | `blend_modes/screen` | 0 | 2.4s |  |
| 16 | `blend_modes/shader_without_shader` | 1 | 24.7s |  |
| 17 | `blend_modes/subtract` | 0 | 2.5s |  |
| 18 | `bmd_draw_with_msaa_issue_10579` | 0 | 21.4s |  |
| 19 | `cache_as_bitmap/avm1_color` | 0 | 20.4s |  |
| 20 | `cache_as_bitmap/avm2_button` | 0 | 20.3s |  |
| 21 | `cache_as_bitmap/avm2_button_state` | 0 | 20.7s |  |
| 22 | `cache_as_bitmap/cab_bitmapdata_invalidate` | 0 | 25.8s |  |
| 23 | `cache_as_bitmap/cab_mask_alpha` | 0 | 25.7s |  |
| 24 | `cache_as_bitmap/cab_mask_transform` | 0 | 24.3s |  |
| 25 | `cache_as_bitmap/cab_mask_triangle` | 0 | 7.5s |  |
| 26 | `cache_as_bitmap/children_changed` | 0 | 2.2s |  |
| 27 | `cache_as_bitmap/color_transform` | 0 | 2.4s |  |
| 28 | `cache_as_bitmap/contains_grown_filter` | 0 | 2.1s |  |
| 29 | `cache_as_bitmap/drawing_api` | 0 | 2.5s |  |
| 30 | `cache_as_bitmap/edittext_hscroll` | 1 | 21.7s |  |
| 31 | `cache_as_bitmap/edittext_scroll` | 0 | 21.8s |  |
| 32 | `cache_as_bitmap/edittext_selection` | 0 | 23.1s |  |
| 33 | `cache_as_bitmap/masks` | 0 | 9.7s |  |
| 34 | `cache_as_bitmap/morph` | 0 | 2.5s |  |
| 35 | `cache_as_bitmap/nested_color_transform` | 0 | 2.4s |  |
| 36 | `cache_as_bitmap/nested_matrix` | 0 | 2.4s |  |
| 37 | `cache_as_bitmap/nested_rotation` | 0 | 2.0s |  |
| 38 | `cache_as_bitmap/oversize/swf_10_masks` | 0 | 20.6s |  |
| 39 | `cache_as_bitmap/oversize/swf_10_too_big` | 0 | 5.0s |  |
| 40 | `cache_as_bitmap/oversize/swf_9_masks` | 0 | 2.6s |  |
| 41 | `cache_as_bitmap/oversize/swf_9_too_big` | 0 | 5.1s |  |
| 42 | `cache_as_bitmap/scroll_rect` | 0 | 1.9s |  |
| 43 | `cache_as_bitmap/scroll_rect_scaled` | 0 | 16.2s |  |
| 44 | `cache_as_bitmap/shape_changed` | 0 | 1.8s |  |
| 45 | `cache_as_bitmap/text` | 0 | 16.8s |  |
| 46 | `color_transform_issue_9698` | 0 | 16.2s |  |
| 47 | `drawing_api/cursor` | 0 | 2.2s |  |
| 48 | `drawing_api/drawing_order` | 0 | 21.0s |  |
| 49 | `drawing_api/fills_and_lines` | 0 | 2.6s |  |
| 50 | `drawing_api/gradient_focal_point` | 0 | 21.0s |  |
| 51 | `edittext/edittext_background_basic` | 0 | 2.1s |  |
| 52 | `edittext/edittext_background_basic_scale2` | 0 | 20.1s |  |
| 53 | `edittext/edittext_border_basic` | 0 | 2.1s |  |
| 54 | `edittext/edittext_border_basic_scale2` | 0 | 1.8s |  |
| 55 | `edittext/edittext_border_filters` | 0 | 20.1s |  |
| 56 | `edittext/edittext_border_transform` | 0 | 2.5s |  |
| 57 | `edittext/edittext_bounds_vs_position` | 0 | 1.9s |  |
| 58 | `edittext/edittext_caret_empty` | 0 | 20.8s |  |
| 59 | `edittext/edittext_device_transform_small_rotation` | 0 | 22.1s |  |
| 60 | `edittext/edittext_device_transform_small_shear` | 0 | 2.5s |  |
| 61 | `edittext/edittext_gutter` | 0 | 26.5s |  |
| 62 | `edittext/edittext_justify` | 0 | 26.4s |  |
| 63 | `edittext/edittext_negative_bounds` | 0 | 2.0s |  |
| 64 | `edittext/edittext_selection_font_size` | 0 | 21.4s |  |
| 65 | `edittext/edittext_selection_leading` | 12 | 25.3s |  |
| 66 | `edittext/edittext_underline` | 0 | 25.7s |  |
| 67 | `edittext/edittext_underline_scale2` | 0 | 24.1s |  |
| 68 | `filters/any_blur_scales_with_screen` | 0 | 19.2s |  |
| 69 | `filters/bevel` | 0 | 20.9s |  |
| 70 | `filters/bevel_full` | 0 | 23.1s |  |
| 71 | `filters/bevel_inner` | 0 | 27.3s |  |
| 72 | `filters/bevel_outer` | 0 | 6.4s |  |
| 73 | `filters/blur_scales_with_screen` | 0 | 20.1s |  |
| 74 | `filters/blur_size_grows` | 0 | 2.3s |  |
| 75 | `filters/color_matrix` | 0 | 1.9s |  |
| 76 | `filters/drop_shadow` | 0 | 3.0s |  |
| 77 | `filters/drop_shadow_angles` | 0 | 2.8s |  |
| 78 | `filters/drop_shadow_scales_with_screen` | 0 | 21.4s |  |
| 79 | `filters/glow` | 0 | 3.2s |  |
| 80 | `filters/glow_with_alpha_strength` | 0 | 27.0s |  |
| 81 | `filters/glow_without_composite_source` | 0 | 2.9s |  |
| 82 | `focus_highlight/focus_highlight_avm1_button` | 6 | 23.5s |  |
| 83 | `focus_highlight/focus_highlight_avm2_button_bounds` | 1 | 26.4s |  |
| 84 | `focus_highlight/focus_highlight_basic` | 0 | 4.1s |  |
| 85 | `focus_highlight/focus_highlight_empty_clip` | 0 | 6.2s |  |
| 86 | `focus_highlight/focus_highlight_move` | 0 | 2.4s |  |
| 87 | `focus_highlight/focus_highlight_render` | 0 | 3.9s |  |
| 88 | `fonts/advance_u16` | 0 | 21.9s |  |
| 89 | `fonts/device-font` | 0 | 6.2s |  |
| 90 | `fonts/duplicate_font` | 0 | 6.5s |  |
| 91 | `fonts/font_lookup_as3` | 0 | 6.4s |  |
| 92 | `fonts/glyph` | 0 | 6.3s |  |
| 93 | `fonts/leading_define_font` | 0 | 22.9s |  |
| 94 | `fonts/leading_device_font` | 0 | 24.8s |  |
| 95 | `fonts/leading_embedded_font` | 0 | 6.6s |  |
| 96 | `gradient_issue_9892` | 0 | 21.5s |  |
| 97 | `gradient_nonsequential_ratios` | 0 | 19.9s |  |
| 98 | `gradient_radial_same_ratios` | 0 | 19.8s |  |
| 99 | `gradient_same_ratios` | 0 | 1.6s |  |
| 100 | `layout/line_vertical_align` | 0 | 23.8s |  |
| 101 | `opaque_background` | 0 | 2.2s |  |
| 102 | `scale_rotation_cache` | 106 | 20.9s |  |
| 103 | `simple_shapes/gradients/focal_radial` | 0 | 2.4s |  |
| 104 | `simple_shapes/gradients/gradients` | 0 | 2.5s |  |
| 105 | `simple_shapes/gradients/radial` | 0 | 2.6s |  |
| 106 | `simple_shapes/gradients/reflect` | 0 | 2.5s |  |
| 107 | `simple_shapes/gradients/repeat` | 0 | 2.5s |  |
| 108 | `simple_shapes/layers` | 0 | 3.9s |  |
| 109 | `simple_shapes/masks` | 0 | 2.4s |  |
| 110 | `simple_shapes/masks_equal_clipdepth` | 0 | 2.1s |  |
| 111 | `simple_shapes/overlaps` | 0 | 2.3s |  |
| 112 | `simple_shapes/scroll_rect_mask` | 0 | 3.2s |  |
| 113 | `simple_shapes/strokes/scale` | 0 | 1.5s |  |
| 114 | `simple_shapes/text_field_mask` | 0 | 1.7s |  |
| 115 | `simple_shapes/winding_rule` | 0 | 20.1s |  |
| 116 | `text/String_path_variable_button` | 0 | 4.0s |  |
| 117 | `video/colorconversion/h263` | 0 | 20.7s |  |
| 118 | `video/colorconversion/vp6` | 0 | 2.5s |  |
| 119 | `video/colorconversion/vp6a` | 0 | 2.7s |  |
| 120 | `video/vp6_alphaoffset` | 0 | 20.9s |  |
| 121 | `video/vp6_dispsize` | 0 | 20.8s |  |

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
| 1 | `video/deblocking` | exit code -6 | 36.1s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**19 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `filters/avm1_convolution_initialization` | 94.4% | 17/18 | 18 | 18 |  |
| 2 | `edittext/edittext_device_transform_basic` | 50.0% | 12/24 | 24 | 24 |  |
| 3 | `edittext/edittext_device_transform_metrics` | 50.0% | 20/40 | 40 | 40 |  |
| 4 | `edittext/edittext_device_transform_negative` | 50.0% | 60/120 | 120 | 120 |  |
| 5 | `define_bits_jpeg2_huge` | 10.5% | 2/19 | 4 | 19 |  |
| 6 | `avm2_button_scroll_rect` | 0.0% | 0/2 | 2 | 2 |  |
| 7 | `blend_modes/shader_as_mask` | 0.0% | 0/3 | 3 | 0 |  |
| 8 | `cache_as_bitmap/bitmap_changed` | 0.0% | 0/6 | 6 | 0 |  |
| 9 | `cache_as_bitmap/cab_mask_filters` | 0.0% | 0/2 | 2 | 0 |  |
| 10 | `definefont4` | 0.0% | 0/14 | 14 | 0 |  |
| 11 | `filters/blur_fractional` | 0.0% | 0/2 | 2 | 0 |  |
| 12 | `filters/blur_pass_scaling` | 0.0% | 0/3 | 3 | 0 |  |
| 13 | `filters/blur_quality` | 0.0% | 0/2 | 2 | 0 |  |
| 14 | `filters/displacement_map` | 0.0% | 0/3 | 3 | 0 |  |
| 15 | `filters/displacement_map_scales_with_screen` | 0.0% | 0/2 | 2 | 0 |  |
| 16 | `filters/displacement_map_through_applyFilter` | 0.0% | 0/2 | 2 | 0 |  |
| 17 | `filters/displacement_map_through_filters` | 0.0% | 0/2 | 2 | 0 |  |
| 18 | `filters/glow_pass_scaling` | 0.0% | 0/3 | 3 | 0 |  |
| 19 | `video/h264` | 0.0% | 0/3 | 3 | 0 |  |
