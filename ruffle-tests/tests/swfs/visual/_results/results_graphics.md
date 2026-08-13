# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-13 22:38 UTC

**Git SHA**: `3db858cbc1`

**Run Duration**: 32m 50s

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
| 1 | `avm2_button_scroll_rect` | 2 | 19.5s |  |
| 2 | `bitmapdata_copypixels_with_alpha_oob` | 0 | 6.4s |  |
| 3 | `blend_modes/add` | 0 | 2.0s |  |
| 4 | `blend_modes/alpha_no_layer` | 0 | 1.7s |  |
| 5 | `blend_modes/darken` | 0 | 1.9s |  |
| 6 | `blend_modes/difference` | 0 | 2.4s |  |
| 7 | `blend_modes/erase_no_layer` | 0 | 2.4s |  |
| 8 | `blend_modes/hardlight` | 0 | 2.2s |  |
| 9 | `blend_modes/invert` | 0 | 2.2s |  |
| 10 | `blend_modes/layer_alpha` | 0 | 2.3s |  |
| 11 | `blend_modes/layer_erase` | 0 | 2.4s |  |
| 12 | `blend_modes/lighten` | 0 | 2.5s |  |
| 13 | `blend_modes/multiply` | 0 | 2.5s |  |
| 14 | `blend_modes/overlay` | 0 | 2.2s |  |
| 15 | `blend_modes/overlay_onto_stage` | 0 | 2.5s |  |
| 16 | `blend_modes/screen` | 0 | 2.7s |  |
| 17 | `blend_modes/shader_as_mask` | 0 | 30.1s |  |
| 18 | `blend_modes/shader_without_shader` | 1 | 27.7s |  |
| 19 | `blend_modes/subtract` | 0 | 2.6s |  |
| 20 | `bmd_draw_with_msaa_issue_10579` | 0 | 22.0s |  |
| 21 | `cache_as_bitmap/avm1_color` | 0 | 20.6s |  |
| 22 | `cache_as_bitmap/avm2_button` | 0 | 20.2s |  |
| 23 | `cache_as_bitmap/avm2_button_state` | 0 | 21.0s |  |
| 24 | `cache_as_bitmap/bitmap_changed` | 0 | 25.8s |  |
| 25 | `cache_as_bitmap/cab_bitmapdata_invalidate` | 0 | 26.2s |  |
| 26 | `cache_as_bitmap/cab_mask_alpha` | 0 | 24.0s |  |
| 27 | `cache_as_bitmap/cab_mask_filters` | 0 | 6.5s |  |
| 28 | `cache_as_bitmap/cab_mask_transform` | 0 | 23.1s |  |
| 29 | `cache_as_bitmap/cab_mask_triangle` | 0 | 7.6s |  |
| 30 | `cache_as_bitmap/children_changed` | 0 | 2.6s |  |
| 31 | `cache_as_bitmap/color_transform` | 0 | 18.3s |  |
| 32 | `cache_as_bitmap/contains_grown_filter` | 0 | 17.6s |  |
| 33 | `cache_as_bitmap/drawing_api` | 0 | 2.2s |  |
| 34 | `cache_as_bitmap/edittext_hscroll` | 1 | 17.8s |  |
| 35 | `cache_as_bitmap/edittext_scroll` | 0 | 17.7s |  |
| 36 | `cache_as_bitmap/edittext_selection` | 0 | 18.1s |  |
| 37 | `cache_as_bitmap/masks` | 0 | 8.2s |  |
| 38 | `cache_as_bitmap/morph` | 0 | 2.0s |  |
| 39 | `cache_as_bitmap/nested_color_transform` | 0 | 1.7s |  |
| 40 | `cache_as_bitmap/nested_matrix` | 0 | 1.8s |  |
| 41 | `cache_as_bitmap/nested_rotation` | 0 | 2.7s |  |
| 42 | `cache_as_bitmap/oversize/swf_10_masks` | 0 | 28.2s |  |
| 43 | `cache_as_bitmap/oversize/swf_10_too_big` | 0 | 8.0s |  |
| 44 | `cache_as_bitmap/oversize/swf_9_masks` | 0 | 3.7s |  |
| 45 | `cache_as_bitmap/oversize/swf_9_too_big` | 0 | 8.0s |  |
| 46 | `cache_as_bitmap/scroll_rect` | 0 | 3.8s |  |
| 47 | `cache_as_bitmap/scroll_rect_scaled` | 0 | 21.3s |  |
| 48 | `cache_as_bitmap/shape_changed` | 0 | 2.5s |  |
| 49 | `cache_as_bitmap/text` | 0 | 21.9s |  |
| 50 | `color_transform_issue_9698` | 0 | 21.0s |  |
| 51 | `define_bits_jpeg2_huge` | 19 | 23.6s |  |
| 52 | `define_bits_lossless2_rgb15` | 0 | 2.1s |  |
| 53 | `definefont4` | 0 | 93.1s |  |
| 54 | `drawing_api/cursor` | 0 | 2.4s |  |
| 55 | `drawing_api/drawing_order` | 0 | 22.4s |  |
| 56 | `drawing_api/fills_and_lines` | 0 | 2.1s |  |
| 57 | `drawing_api/gradient_focal_point` | 0 | 18.2s |  |
| 58 | `edittext/edittext_background_basic` | 0 | 1.7s |  |
| 59 | `edittext/edittext_background_basic_scale2` | 0 | 18.1s |  |
| 60 | `edittext/edittext_border_basic` | 0 | 2.1s |  |
| 61 | `edittext/edittext_border_basic_scale2` | 0 | 21.6s |  |
| 62 | `edittext/edittext_border_filters` | 0 | 21.8s |  |
| 63 | `edittext/edittext_border_transform` | 0 | 2.8s |  |
| 64 | `edittext/edittext_bounds_vs_position` | 0 | 22.6s |  |
| 65 | `edittext/edittext_caret_empty` | 0 | 22.6s |  |
| 66 | `edittext/edittext_device_transform_basic` | 24 | 27.3s |  |
| 67 | `edittext/edittext_device_transform_small_rotation` | 0 | 21.3s |  |
| 68 | `edittext/edittext_device_transform_small_shear` | 0 | 21.6s |  |
| 69 | `edittext/edittext_gutter` | 0 | 28.4s |  |
| 70 | `edittext/edittext_justify` | 0 | 27.1s |  |
| 71 | `edittext/edittext_negative_bounds` | 0 | 2.1s |  |
| 72 | `edittext/edittext_selection_font_size` | 0 | 22.1s |  |
| 73 | `edittext/edittext_selection_leading` | 12 | 27.3s |  |
| 74 | `edittext/edittext_underline` | 0 | 21.7s |  |
| 75 | `edittext/edittext_underline_scale2` | 0 | 18.8s |  |
| 76 | `filters/any_blur_scales_with_screen` | 0 | 15.9s |  |
| 77 | `filters/avm1_convolution_initialization` | 18 | 1.4s |  |
| 78 | `filters/bevel` | 0 | 16.8s |  |
| 79 | `filters/bevel_full` | 0 | 24.7s |  |
| 80 | `filters/bevel_inner` | 0 | 4.7s |  |
| 81 | `filters/bevel_outer` | 0 | 5.0s |  |
| 82 | `filters/blur_fractional` | 0 | 28.1s |  |
| 83 | `filters/blur_pass_scaling` | 0 | 27.8s |  |
| 84 | `filters/blur_quality` | 0 | 22.8s |  |
| 85 | `filters/blur_scales_with_screen` | 0 | 17.2s |  |
| 86 | `filters/blur_size_grows` | 0 | 2.1s |  |
| 87 | `filters/color_matrix` | 0 | 2.0s |  |
| 88 | `filters/displacement_map` | 0 | 23.0s |  |
| 89 | `filters/displacement_map_scales_with_screen` | 0 | 27.3s |  |
| 90 | `filters/displacement_map_through_applyFilter` | 0 | 25.4s |  |
| 91 | `filters/displacement_map_through_filters` | 0 | 6.8s |  |
| 92 | `filters/drop_shadow` | 0 | 2.4s |  |
| 93 | `filters/drop_shadow_angles` | 0 | 2.2s |  |
| 94 | `filters/drop_shadow_scales_with_screen` | 0 | 18.1s |  |
| 95 | `filters/glow` | 0 | 2.5s |  |
| 96 | `filters/glow_pass_scaling` | 0 | 22.7s |  |
| 97 | `filters/glow_with_alpha_strength` | 0 | 20.0s |  |
| 98 | `filters/glow_without_composite_source` | 0 | 2.9s |  |
| 99 | `focus_highlight/focus_highlight_avm1_button` | 6 | 21.8s |  |
| 100 | `focus_highlight/focus_highlight_avm2_button_bounds` | 1 | 27.2s |  |
| 101 | `focus_highlight/focus_highlight_basic` | 0 | 4.4s |  |
| 102 | `focus_highlight/focus_highlight_empty_clip` | 0 | 7.8s |  |
| 103 | `focus_highlight/focus_highlight_move` | 0 | 21.7s |  |
| 104 | `focus_highlight/focus_highlight_render` | 0 | 6.4s |  |
| 105 | `fonts/advance_u16` | 0 | 22.3s |  |
| 106 | `fonts/device-font` | 0 | 7.8s |  |
| 107 | `fonts/duplicate_font` | 0 | 8.5s |  |
| 108 | `fonts/font_lookup_as3` | 0 | 8.0s |  |
| 109 | `fonts/glyph` | 0 | 11.4s |  |
| 110 | `fonts/leading_define_font` | 0 | 22.0s |  |
| 111 | `fonts/leading_device_font` | 0 | 27.2s |  |
| 112 | `fonts/leading_embedded_font` | 0 | 8.3s |  |
| 113 | `gradient_issue_9892` | 0 | 22.0s |  |
| 114 | `gradient_nonsequential_ratios` | 0 | 21.3s |  |
| 115 | `gradient_radial_same_ratios` | 0 | 21.2s |  |
| 116 | `gradient_same_ratios` | 0 | 2.1s |  |
| 117 | `layout/line_vertical_align` | 0 | 27.3s |  |
| 118 | `opaque_background` | 0 | 2.5s |  |
| 119 | `scale_rotation_cache` | 106 | 21.6s |  |
| 120 | `simple_shapes/gradients/focal_radial` | 0 | 2.5s |  |
| 121 | `simple_shapes/gradients/gradients` | 0 | 2.5s |  |
| 122 | `simple_shapes/gradients/radial` | 0 | 2.6s |  |
| 123 | `simple_shapes/gradients/reflect` | 0 | 2.2s |  |
| 124 | `simple_shapes/gradients/repeat` | 0 | 2.2s |  |
| 125 | `simple_shapes/heavy_tesselation` | 0 | 65.4s |  |
| 126 | `simple_shapes/layers` | 0 | 1.9s |  |
| 127 | `simple_shapes/masks` | 0 | 4.4s |  |
| 128 | `simple_shapes/masks_equal_clipdepth` | 0 | 1.3s |  |
| 129 | `simple_shapes/overlaps` | 0 | 1.4s |  |
| 130 | `simple_shapes/scroll_rect_mask` | 0 | 1.3s |  |
| 131 | `simple_shapes/strokes/scale` | 0 | 4.3s |  |
| 132 | `simple_shapes/text_field_mask` | 0 | 3.5s |  |
| 133 | `simple_shapes/winding_rule` | 0 | 21.9s |  |
| 134 | `text/String_path_variable_button` | 0 | 2.4s |  |
| 135 | `video/colorconversion/h263` | 0 | 18.9s |  |
| 136 | `video/colorconversion/vp6` | 0 | 1.8s |  |
| 137 | `video/colorconversion/vp6a` | 0 | 1.8s |  |
| 138 | `video/deblocking` | 0 | 17.1s |  |
| 139 | `video/h264` | 0 | 32.1s |  |
| 140 | `video/h264_multinalu` | 0 | 27.5s |  |
| 141 | `video/vp6_alphaoffset` | 0 | 21.8s |  |
| 142 | `video/vp6_dispsize` | 0 | 21.6s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `edittext/edittext_device_transform_metrics` | 8 | 8 | 7.4s |  |
| 2 | `edittext/edittext_device_transform_negative` | 41 | 41 | 7.8s |  |

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
