# Ruffle Test Results (Filtered)

**Date**: 2026-08-19 13:28 UTC

**Git SHA**: `9d038c750e`

**Run Duration**: 30m 35s

**Filtered**: 0 tests ignored out of 144 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 144 |
| Passing | **142** (98.6%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **144** (100.0%) |
| Failing | 0 |
| Total expected lines | 350 |
| Matching lines | 301 (86.0%) |
| Mismatched lines | 49 |

## Passing Tests

**142 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `avm2_button_scroll_rect` | 2 | 21.8s |  |
| 2 | `bitmapdata_copypixels_with_alpha_oob` | 0 | 6.1s |  |
| 3 | `blend_modes/add` | 0 | 1.0s |  |
| 4 | `blend_modes/alpha_no_layer` | 0 | 1.1s |  |
| 5 | `blend_modes/darken` | 0 | 0.9s |  |
| 6 | `blend_modes/difference` | 0 | 1.4s |  |
| 7 | `blend_modes/erase_no_layer` | 0 | 1.4s |  |
| 8 | `blend_modes/hardlight` | 0 | 1.1s |  |
| 9 | `blend_modes/invert` | 0 | 1.1s |  |
| 10 | `blend_modes/layer_alpha` | 0 | 1.4s |  |
| 11 | `blend_modes/layer_erase` | 0 | 1.5s |  |
| 12 | `blend_modes/lighten` | 0 | 1.4s |  |
| 13 | `blend_modes/multiply` | 0 | 1.4s |  |
| 14 | `blend_modes/overlay` | 0 | 1.1s |  |
| 15 | `blend_modes/overlay_onto_stage` | 0 | 1.4s |  |
| 16 | `blend_modes/screen` | 0 | 1.4s |  |
| 17 | `blend_modes/shader_as_mask` | 0 | 28.9s |  |
| 18 | `blend_modes/shader_without_shader` | 1 | 27.1s |  |
| 19 | `blend_modes/subtract` | 0 | 1.4s |  |
| 20 | `bmd_draw_with_msaa_issue_10579` | 0 | 20.9s |  |
| 21 | `cache_as_bitmap/avm1_color` | 0 | 20.5s |  |
| 22 | `cache_as_bitmap/avm2_button` | 0 | 20.4s |  |
| 23 | `cache_as_bitmap/avm2_button_state` | 0 | 20.4s |  |
| 24 | `cache_as_bitmap/bitmap_changed` | 0 | 26.5s |  |
| 25 | `cache_as_bitmap/cab_bitmapdata_invalidate` | 0 | 26.6s |  |
| 26 | `cache_as_bitmap/cab_mask_alpha` | 0 | 22.5s |  |
| 27 | `cache_as_bitmap/cab_mask_filters` | 0 | 6.0s |  |
| 28 | `cache_as_bitmap/cab_mask_transform` | 0 | 21.3s |  |
| 29 | `cache_as_bitmap/cab_mask_triangle` | 0 | 7.3s |  |
| 30 | `cache_as_bitmap/children_changed` | 0 | 1.1s |  |
| 31 | `cache_as_bitmap/color_transform` | 0 | 22.1s |  |
| 32 | `cache_as_bitmap/contains_grown_filter` | 0 | 21.8s |  |
| 33 | `cache_as_bitmap/drawing_api` | 0 | 1.6s |  |
| 34 | `cache_as_bitmap/edittext_hscroll` | 1 | 21.7s |  |
| 35 | `cache_as_bitmap/edittext_scroll` | 0 | 22.1s |  |
| 36 | `cache_as_bitmap/edittext_selection` | 0 | 21.2s |  |
| 37 | `cache_as_bitmap/masks` | 0 | 7.7s |  |
| 38 | `cache_as_bitmap/morph` | 0 | 1.4s |  |
| 39 | `cache_as_bitmap/nested_color_transform` | 0 | 1.4s |  |
| 40 | `cache_as_bitmap/nested_matrix` | 0 | 1.4s |  |
| 41 | `cache_as_bitmap/nested_rotation` | 0 | 1.4s |  |
| 42 | `cache_as_bitmap/oversize/swf_10_masks` | 0 | 26.6s |  |
| 43 | `cache_as_bitmap/oversize/swf_10_too_big` | 0 | 6.8s |  |
| 44 | `cache_as_bitmap/oversize/swf_9_masks` | 0 | 2.4s |  |
| 45 | `cache_as_bitmap/oversize/swf_9_too_big` | 0 | 6.8s |  |
| 46 | `cache_as_bitmap/scroll_rect` | 0 | 1.4s |  |
| 47 | `cache_as_bitmap/scroll_rect_scaled` | 0 | 20.4s |  |
| 48 | `cache_as_bitmap/shape_changed` | 0 | 1.4s |  |
| 49 | `cache_as_bitmap/text` | 0 | 20.7s |  |
| 50 | `color_transform_issue_9698` | 0 | 20.9s |  |
| 51 | `define_bits_jpeg2_huge` | 19 | 16.5s |  |
| 52 | `define_bits_lossless2_rgb15` | 0 | 0.9s |  |
| 53 | `definefont4` | 0 | 58.5s |  |
| 54 | `drawing_api/cursor` | 0 | 1.1s |  |
| 55 | `drawing_api/drawing_order` | 0 | 13.8s |  |
| 56 | `drawing_api/fills_and_lines` | 0 | 1.7s |  |
| 57 | `drawing_api/gradient_focal_point` | 0 | 21.5s |  |
| 58 | `edittext/edittext_background_basic` | 0 | 21.5s |  |
| 59 | `edittext/edittext_background_basic_scale2` | 0 | 20.5s |  |
| 60 | `edittext/edittext_border_basic` | 0 | 1.4s |  |
| 61 | `edittext/edittext_border_basic_scale2` | 0 | 21.0s |  |
| 62 | `edittext/edittext_border_filters` | 0 | 20.9s |  |
| 63 | `edittext/edittext_border_transform` | 0 | 1.7s |  |
| 64 | `edittext/edittext_bounds_vs_position` | 0 | 20.4s |  |
| 65 | `edittext/edittext_caret_empty` | 0 | 21.3s |  |
| 66 | `edittext/edittext_device_transform_basic` | 24 | 21.3s |  |
| 67 | `edittext/edittext_device_transform_small_rotation` | 0 | 16.6s |  |
| 68 | `edittext/edittext_device_transform_small_shear` | 0 | 16.7s |  |
| 69 | `edittext/edittext_gutter` | 0 | 17.1s |  |
| 70 | `edittext/edittext_justify` | 0 | 17.1s |  |
| 71 | `edittext/edittext_negative_bounds` | 0 | 0.9s |  |
| 72 | `edittext/edittext_selection_font_size` | 0 | 14.0s |  |
| 73 | `edittext/edittext_selection_leading` | 12 | 17.2s |  |
| 74 | `edittext/edittext_underline` | 0 | 27.9s |  |
| 75 | `edittext/edittext_underline_scale2` | 0 | 23.5s |  |
| 76 | `filters/any_blur_scales_with_screen` | 0 | 21.3s |  |
| 77 | `filters/avm1_convolution_initialization` | 18 | 1.5s |  |
| 78 | `filters/bevel` | 0 | 21.7s |  |
| 79 | `filters/bevel_full` | 0 | 21.8s |  |
| 80 | `filters/bevel_inner` | 0 | 1.6s |  |
| 81 | `filters/bevel_outer` | 0 | 1.8s |  |
| 82 | `filters/blur_fractional` | 0 | 27.5s |  |
| 83 | `filters/blur_pass_scaling` | 0 | 27.6s |  |
| 84 | `filters/blur_quality` | 0 | 22.9s |  |
| 85 | `filters/blur_scales_with_screen` | 0 | 17.4s |  |
| 86 | `filters/blur_size_grows` | 0 | 1.2s |  |
| 87 | `filters/color_matrix` | 0 | 1.1s |  |
| 88 | `filters/displacement_map` | 0 | 21.8s |  |
| 89 | `filters/displacement_map_scales_with_screen` | 0 | 28.5s |  |
| 90 | `filters/displacement_map_through_applyFilter` | 0 | 27.1s |  |
| 91 | `filters/displacement_map_through_filters` | 0 | 7.1s |  |
| 92 | `filters/drop_shadow` | 0 | 1.6s |  |
| 93 | `filters/drop_shadow_angles` | 0 | 1.5s |  |
| 94 | `filters/drop_shadow_scales_with_screen` | 0 | 20.8s |  |
| 95 | `filters/glow` | 0 | 1.6s |  |
| 96 | `filters/glow_pass_scaling` | 0 | 27.6s |  |
| 97 | `filters/glow_with_alpha_strength` | 0 | 21.2s |  |
| 98 | `filters/glow_without_composite_source` | 0 | 1.6s |  |
| 99 | `focus_highlight/focus_highlight_avm1_button` | 6 | 21.2s |  |
| 100 | `focus_highlight/focus_highlight_avm2_button_bounds` | 1 | 27.0s |  |
| 101 | `focus_highlight/focus_highlight_basic` | 0 | 1.9s |  |
| 102 | `focus_highlight/focus_highlight_empty_clip` | 0 | 7.2s |  |
| 103 | `focus_highlight/focus_highlight_move` | 0 | 21.3s |  |
| 104 | `focus_highlight/focus_highlight_render` | 0 | 1.7s |  |
| 105 | `fonts/advance_u16` | 0 | 20.6s |  |
| 106 | `fonts/device-font` | 0 | 7.3s |  |
| 107 | `fonts/duplicate_font` | 0 | 7.6s |  |
| 108 | `fonts/font_lookup_as3` | 0 | 7.4s |  |
| 109 | `fonts/glyph` | 0 | 7.4s |  |
| 110 | `fonts/leading_define_font` | 0 | 21.1s |  |
| 111 | `fonts/leading_device_font` | 0 | 27.0s |  |
| 112 | `fonts/leading_embedded_font` | 0 | 7.8s |  |
| 113 | `gradient_issue_9892` | 0 | 21.6s |  |
| 114 | `gradient_nonsequential_ratios` | 0 | 20.2s |  |
| 115 | `gradient_radial_same_ratios` | 0 | 20.3s |  |
| 116 | `gradient_same_ratios` | 0 | 1.2s |  |
| 117 | `layout/line_vertical_align` | 0 | 26.2s |  |
| 118 | `opaque_background` | 0 | 1.3s |  |
| 119 | `scale_rotation_cache` | 106 | 20.3s |  |
| 120 | `simple_shapes/gradients/focal_radial` | 0 | 1.4s |  |
| 121 | `simple_shapes/gradients/gradients` | 0 | 1.4s |  |
| 122 | `simple_shapes/gradients/radial` | 0 | 1.6s |  |
| 123 | `simple_shapes/gradients/reflect` | 0 | 1.4s |  |
| 124 | `simple_shapes/gradients/repeat` | 0 | 1.4s |  |
| 125 | `simple_shapes/heavy_tesselation` | 0 | 71.3s |  |
| 126 | `simple_shapes/layers` | 0 | 1.2s |  |
| 127 | `simple_shapes/masks` | 0 | 0.2s |  |
| 128 | `simple_shapes/masks_equal_clipdepth` | 0 | 0.2s |  |
| 129 | `simple_shapes/overlaps` | 0 | 0.2s |  |
| 130 | `simple_shapes/scroll_rect_mask` | 0 | 0.2s |  |
| 131 | `simple_shapes/strokes/scale` | 0 | 1.3s |  |
| 132 | `simple_shapes/text_field_mask` | 0 | 1.3s |  |
| 133 | `simple_shapes/winding_rule` | 0 | 20.9s |  |
| 134 | `text/String_path_variable_button` | 0 | 1.5s |  |
| 135 | `video/colorconversion/h263` | 0 | 20.5s |  |
| 136 | `video/colorconversion/vp6` | 0 | 1.5s |  |
| 137 | `video/colorconversion/vp6a` | 0 | 1.6s |  |
| 138 | `video/deblocking` | 0 | 21.5s |  |
| 139 | `video/h264` | 0 | 28.1s |  |
| 140 | `video/h264_multinalu` | 0 | 27.1s |  |
| 141 | `video/vp6_alphaoffset` | 0 | 20.7s |  |
| 142 | `video/vp6_dispsize` | 0 | 20.8s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `edittext/edittext_device_transform_metrics` | 8 | 8 | 5.6s |  |
| 2 | `edittext/edittext_device_transform_negative` | 41 | 41 | 5.7s |  |

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
