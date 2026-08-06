# Ruffle Test Results (Filtered)

**Date**: 2026-08-06 06:23 UTC

**Git SHA**: `6de6504325`

**Run Duration**: 31m 58s

**Filtered**: 0 tests ignored out of 143 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 143 |
| Passing | **139** (97.2%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **141** (98.6%) |
| Failing | 2 |
| Total expected lines | 350 |
| Matching lines | 295 (84.3%) |
| Mismatched lines | 55 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**139 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `avm2_button_scroll_rect` | 2 | 26.9s |  |
| 2 | `bitmapdata_copypixels_with_alpha_oob` | 0 | 8.6s |  |
| 3 | `blend_modes/add` | 0 | 2.5s |  |
| 4 | `blend_modes/alpha_no_layer` | 0 | 2.8s |  |
| 5 | `blend_modes/darken` | 0 | 2.8s |  |
| 6 | `blend_modes/difference` | 0 | 2.5s |  |
| 7 | `blend_modes/erase_no_layer` | 0 | 2.5s |  |
| 8 | `blend_modes/hardlight` | 0 | 2.3s |  |
| 9 | `blend_modes/invert` | 0 | 2.3s |  |
| 10 | `blend_modes/layer_alpha` | 0 | 2.4s |  |
| 11 | `blend_modes/layer_erase` | 0 | 2.6s |  |
| 12 | `blend_modes/lighten` | 0 | 2.6s |  |
| 13 | `blend_modes/multiply` | 0 | 2.6s |  |
| 14 | `blend_modes/overlay` | 0 | 2.4s |  |
| 15 | `blend_modes/overlay_onto_stage` | 0 | 2.6s |  |
| 16 | `blend_modes/screen` | 0 | 2.7s |  |
| 17 | `blend_modes/shader_as_mask` | 0 | 29.8s |  |
| 18 | `blend_modes/shader_without_shader` | 1 | 27.5s |  |
| 19 | `blend_modes/subtract` | 0 | 2.6s |  |
| 20 | `bmd_draw_with_msaa_issue_10579` | 0 | 21.9s |  |
| 21 | `cache_as_bitmap/avm1_color` | 0 | 23.7s |  |
| 22 | `cache_as_bitmap/avm2_button` | 0 | 23.5s |  |
| 23 | `cache_as_bitmap/avm2_button_state` | 0 | 23.4s |  |
| 24 | `cache_as_bitmap/bitmap_changed` | 0 | 27.9s |  |
| 25 | `cache_as_bitmap/cab_bitmapdata_invalidate` | 0 | 28.4s |  |
| 26 | `cache_as_bitmap/cab_mask_alpha` | 0 | 28.0s |  |
| 27 | `cache_as_bitmap/cab_mask_filters` | 0 | 7.8s |  |
| 28 | `cache_as_bitmap/cab_mask_transform` | 0 | 26.5s |  |
| 29 | `cache_as_bitmap/cab_mask_triangle` | 0 | 9.0s |  |
| 30 | `cache_as_bitmap/children_changed` | 0 | 2.3s |  |
| 31 | `cache_as_bitmap/color_transform` | 0 | 2.4s |  |
| 32 | `cache_as_bitmap/contains_grown_filter` | 0 | 1.8s |  |
| 33 | `cache_as_bitmap/drawing_api` | 0 | 2.2s |  |
| 34 | `cache_as_bitmap/edittext_hscroll` | 1 | 19.3s |  |
| 35 | `cache_as_bitmap/edittext_scroll` | 0 | 19.1s |  |
| 36 | `cache_as_bitmap/edittext_selection` | 0 | 22.2s |  |
| 37 | `cache_as_bitmap/masks` | 0 | 11.3s |  |
| 38 | `cache_as_bitmap/morph` | 0 | 2.5s |  |
| 39 | `cache_as_bitmap/nested_color_transform` | 0 | 2.4s |  |
| 40 | `cache_as_bitmap/nested_matrix` | 0 | 2.4s |  |
| 41 | `cache_as_bitmap/nested_rotation` | 0 | 2.5s |  |
| 42 | `cache_as_bitmap/oversize/swf_10_masks` | 0 | 27.8s |  |
| 43 | `cache_as_bitmap/oversize/swf_10_too_big` | 0 | 7.7s |  |
| 44 | `cache_as_bitmap/oversize/swf_9_masks` | 0 | 3.5s |  |
| 45 | `cache_as_bitmap/oversize/swf_9_too_big` | 0 | 7.6s |  |
| 46 | `cache_as_bitmap/scroll_rect` | 0 | 3.7s |  |
| 47 | `cache_as_bitmap/scroll_rect_scaled` | 0 | 22.5s |  |
| 48 | `cache_as_bitmap/shape_changed` | 0 | 2.4s |  |
| 49 | `cache_as_bitmap/text` | 0 | 3.0s |  |
| 50 | `color_transform_issue_9698` | 0 | 22.4s |  |
| 51 | `drawing_api/cursor` | 0 | 2.0s |  |
| 52 | `drawing_api/drawing_order` | 0 | 17.3s |  |
| 53 | `drawing_api/fills_and_lines` | 0 | 2.2s |  |
| 54 | `drawing_api/gradient_focal_point` | 0 | 15.5s |  |
| 55 | `edittext/edittext_background_basic` | 0 | 1.5s |  |
| 56 | `edittext/edittext_background_basic_scale2` | 0 | 14.9s |  |
| 57 | `edittext/edittext_border_basic` | 0 | 2.0s |  |
| 58 | `edittext/edittext_border_basic_scale2` | 0 | 1.4s |  |
| 59 | `edittext/edittext_border_filters` | 0 | 18.1s |  |
| 60 | `edittext/edittext_border_transform` | 0 | 2.0s |  |
| 61 | `edittext/edittext_bounds_vs_position` | 0 | 1.5s |  |
| 62 | `edittext/edittext_caret_empty` | 0 | 18.6s |  |
| 63 | `edittext/edittext_device_transform_basic` | 24 | 6.4s |  |
| 64 | `edittext/edittext_device_transform_small_rotation` | 0 | 22.6s |  |
| 65 | `edittext/edittext_device_transform_small_shear` | 0 | 2.6s |  |
| 66 | `edittext/edittext_gutter` | 0 | 28.3s |  |
| 67 | `edittext/edittext_justify` | 0 | 29.4s |  |
| 68 | `edittext/edittext_negative_bounds` | 0 | 2.2s |  |
| 69 | `edittext/edittext_selection_font_size` | 0 | 22.6s |  |
| 70 | `edittext/edittext_selection_leading` | 12 | 27.6s |  |
| 71 | `edittext/edittext_underline` | 0 | 28.9s |  |
| 72 | `edittext/edittext_underline_scale2` | 0 | 30.3s |  |
| 73 | `filters/any_blur_scales_with_screen` | 0 | 21.8s |  |
| 74 | `filters/avm1_convolution_initialization` | 18 | 2.2s |  |
| 75 | `filters/bevel` | 0 | 23.4s |  |
| 76 | `filters/bevel_full` | 0 | 26.2s |  |
| 77 | `filters/bevel_inner` | 0 | 25.2s |  |
| 78 | `filters/bevel_outer` | 0 | 5.9s |  |
| 79 | `filters/blur_fractional` | 0 | 27.8s |  |
| 80 | `filters/blur_pass_scaling` | 0 | 27.6s |  |
| 81 | `filters/blur_quality` | 0 | 8.8s |  |
| 82 | `filters/blur_scales_with_screen` | 0 | 16.7s |  |
| 83 | `filters/blur_size_grows` | 0 | 2.1s |  |
| 84 | `filters/color_matrix` | 0 | 1.9s |  |
| 85 | `filters/displacement_map` | 0 | 22.0s |  |
| 86 | `filters/displacement_map_scales_with_screen` | 0 | 22.3s |  |
| 87 | `filters/displacement_map_through_applyFilter` | 0 | 26.4s |  |
| 88 | `filters/displacement_map_through_filters` | 0 | 7.5s |  |
| 89 | `filters/drop_shadow` | 0 | 2.6s |  |
| 90 | `filters/drop_shadow_angles` | 0 | 2.5s |  |
| 91 | `filters/drop_shadow_scales_with_screen` | 0 | 20.7s |  |
| 92 | `filters/glow` | 0 | 3.1s |  |
| 93 | `filters/glow_pass_scaling` | 0 | 27.7s |  |
| 94 | `filters/glow_with_alpha_strength` | 0 | 25.5s |  |
| 95 | `filters/glow_without_composite_source` | 0 | 2.8s |  |
| 96 | `focus_highlight/focus_highlight_avm1_button` | 6 | 21.5s |  |
| 97 | `focus_highlight/focus_highlight_avm2_button_bounds` | 1 | 27.4s |  |
| 98 | `focus_highlight/focus_highlight_basic` | 0 | 4.2s |  |
| 99 | `focus_highlight/focus_highlight_empty_clip` | 0 | 7.6s |  |
| 100 | `focus_highlight/focus_highlight_move` | 0 | 2.4s |  |
| 101 | `focus_highlight/focus_highlight_render` | 0 | 3.6s |  |
| 102 | `fonts/advance_u16` | 0 | 23.5s |  |
| 103 | `fonts/device-font` | 0 | 9.0s |  |
| 104 | `fonts/duplicate_font` | 0 | 8.4s |  |
| 105 | `fonts/font_lookup_as3` | 0 | 8.3s |  |
| 106 | `fonts/glyph` | 0 | 8.1s |  |
| 107 | `fonts/leading_define_font` | 0 | 23.4s |  |
| 108 | `fonts/leading_device_font` | 0 | 26.7s |  |
| 109 | `fonts/leading_embedded_font` | 0 | 8.1s |  |
| 110 | `gradient_issue_9892` | 0 | 21.8s |  |
| 111 | `gradient_nonsequential_ratios` | 0 | 21.2s |  |
| 112 | `gradient_radial_same_ratios` | 0 | 17.3s |  |
| 113 | `gradient_same_ratios` | 0 | 17.4s |  |
| 114 | `layout/line_vertical_align` | 0 | 22.1s |  |
| 115 | `opaque_background` | 0 | 2.1s |  |
| 116 | `scale_rotation_cache` | 106 | 21.2s |  |
| 117 | `simple_shapes/gradients/focal_radial` | 0 | 2.4s |  |
| 118 | `simple_shapes/gradients/gradients` | 0 | 2.4s |  |
| 119 | `simple_shapes/gradients/radial` | 0 | 2.6s |  |
| 120 | `simple_shapes/gradients/reflect` | 0 | 2.5s |  |
| 121 | `simple_shapes/gradients/repeat` | 0 | 2.5s |  |
| 122 | `simple_shapes/heavy_tesselation` | 0 | 76.0s |  |
| 123 | `simple_shapes/layers` | 0 | 2.2s |  |
| 124 | `simple_shapes/masks` | 0 | 5.2s |  |
| 125 | `simple_shapes/masks_equal_clipdepth` | 0 | 2.0s |  |
| 126 | `simple_shapes/overlaps` | 0 | 2.3s |  |
| 127 | `simple_shapes/scroll_rect_mask` | 0 | 2.3s |  |
| 128 | `simple_shapes/strokes/scale` | 0 | 2.8s |  |
| 129 | `simple_shapes/text_field_mask` | 0 | 2.8s |  |
| 130 | `simple_shapes/winding_rule` | 0 | 16.6s |  |
| 131 | `text/String_path_variable_button` | 0 | 1.9s |  |
| 132 | `video/colorconversion/h263` | 0 | 24.3s |  |
| 133 | `video/colorconversion/vp6` | 0 | 2.6s |  |
| 134 | `video/colorconversion/vp6a` | 0 | 2.8s |  |
| 135 | `video/deblocking` | 0 | 24.3s |  |
| 136 | `video/h264` | 0 | 30.9s |  |
| 137 | `video/h264_multinalu` | 0 | 26.6s |  |
| 138 | `video/vp6_alphaoffset` | 0 | 21.4s |  |
| 139 | `video/vp6_dispsize` | 0 | 21.2s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `edittext/edittext_device_transform_metrics` | 8 | 8 | 28.8s |  |
| 2 | `edittext/edittext_device_transform_negative` | 41 | 41 | 8.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `define_bits_jpeg2_huge` | 68.4% | 13 | 19 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**2 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `define_bits_jpeg2_huge` | 68.4% | 13/19 | 19 | 19 |  |
| 2 | `definefont4` | 0.0% | 0/24 | 24 | 0 |  |
