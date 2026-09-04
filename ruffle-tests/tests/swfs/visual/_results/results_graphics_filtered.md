# Ruffle Test Results (Filtered)

**Date**: 2026-09-04 09:54 UTC

**Git SHA**: `6591538655`

**Run Duration**: 33m 31s

**Filtered**: 0 tests ignored out of 146 available

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
| 1 | `avm2_button_scroll_rect` | 2 | 20.9s |  |
| 2 | `bitmapdata_copypixels_with_alpha_oob` | 0 | 6.7s |  |
| 3 | `blend_across_masks_issue_24549` | 0 | 15.9s |  |
| 4 | `blend_modes/add` | 0 | 1.8s |  |
| 5 | `blend_modes/alpha_no_layer` | 0 | 1.9s |  |
| 6 | `blend_modes/darken` | 0 | 2.9s |  |
| 7 | `blend_modes/difference` | 0 | 2.7s |  |
| 8 | `blend_modes/erase_no_layer` | 0 | 2.8s |  |
| 9 | `blend_modes/hardlight` | 0 | 2.7s |  |
| 10 | `blend_modes/invert` | 0 | 2.7s |  |
| 11 | `blend_modes/layer_alpha` | 0 | 2.4s |  |
| 12 | `blend_modes/layer_erase` | 0 | 1.4s |  |
| 13 | `blend_modes/lighten` | 0 | 2.4s |  |
| 14 | `blend_modes/masked_layer_cached_children` | 0 | 26.7s |  |
| 15 | `blend_modes/multiply` | 0 | 2.4s |  |
| 16 | `blend_modes/overlay` | 0 | 2.7s |  |
| 17 | `blend_modes/overlay_onto_stage` | 0 | 2.5s |  |
| 18 | `blend_modes/screen` | 0 | 2.7s |  |
| 19 | `blend_modes/shader_as_mask` | 0 | 29.2s |  |
| 20 | `blend_modes/shader_without_shader` | 1 | 27.1s |  |
| 21 | `blend_modes/subtract` | 0 | 1.8s |  |
| 22 | `bmd_draw_with_msaa_issue_10579` | 0 | 15.6s |  |
| 23 | `cache_as_bitmap/avm1_color` | 0 | 15.3s |  |
| 24 | `cache_as_bitmap/avm2_button` | 0 | 15.6s |  |
| 25 | `cache_as_bitmap/avm2_button_state` | 0 | 15.9s |  |
| 26 | `cache_as_bitmap/bitmap_changed` | 0 | 29.5s |  |
| 27 | `cache_as_bitmap/cab_bitmapdata_invalidate` | 0 | 24.2s |  |
| 28 | `cache_as_bitmap/cab_mask_alpha` | 0 | 31.1s |  |
| 29 | `cache_as_bitmap/cab_mask_filters` | 0 | 9.2s |  |
| 30 | `cache_as_bitmap/cab_mask_transform` | 0 | 29.2s |  |
| 31 | `cache_as_bitmap/cab_mask_triangle` | 0 | 27.6s |  |
| 32 | `cache_as_bitmap/children_changed` | 0 | 2.1s |  |
| 33 | `cache_as_bitmap/color_transform` | 0 | 2.0s |  |
| 34 | `cache_as_bitmap/contains_grown_filter` | 0 | 20.2s |  |
| 35 | `cache_as_bitmap/drawing_api` | 0 | 2.2s |  |
| 36 | `cache_as_bitmap/edittext_hscroll` | 1 | 22.4s |  |
| 37 | `cache_as_bitmap/edittext_scroll` | 0 | 22.1s |  |
| 38 | `cache_as_bitmap/edittext_selection` | 0 | 22.1s |  |
| 39 | `cache_as_bitmap/masks` | 0 | 10.9s |  |
| 40 | `cache_as_bitmap/morph` | 0 | 2.7s |  |
| 41 | `cache_as_bitmap/nested_color_transform` | 0 | 2.6s |  |
| 42 | `cache_as_bitmap/nested_matrix` | 0 | 2.3s |  |
| 43 | `cache_as_bitmap/nested_rotation` | 0 | 2.5s |  |
| 44 | `cache_as_bitmap/oversize/swf_10_masks` | 0 | 27.9s |  |
| 45 | `cache_as_bitmap/oversize/swf_10_too_big` | 0 | 8.2s |  |
| 46 | `cache_as_bitmap/oversize/swf_9_masks` | 0 | 20.6s |  |
| 47 | `cache_as_bitmap/oversize/swf_9_too_big` | 0 | 2.2s |  |
| 48 | `cache_as_bitmap/scroll_rect` | 0 | 2.0s |  |
| 49 | `cache_as_bitmap/scroll_rect_scaled` | 0 | 16.2s |  |
| 50 | `cache_as_bitmap/shape_changed` | 0 | 1.6s |  |
| 51 | `cache_as_bitmap/text` | 0 | 1.8s |  |
| 52 | `color_transform_issue_9698` | 0 | 1.5s |  |
| 53 | `define_bits_jpeg2_huge` | 19 | 19.2s |  |
| 54 | `define_bits_lossless2_rgb15` | 0 | 1.4s |  |
| 55 | `definefont4` | 0 | 67.6s |  |
| 56 | `drawing_api/cursor` | 0 | 2.2s |  |
| 57 | `drawing_api/drawing_order` | 0 | 2.4s |  |
| 58 | `drawing_api/fills_and_lines` | 0 | 2.6s |  |
| 59 | `drawing_api/gradient_focal_point` | 0 | 21.3s |  |
| 60 | `edittext/edittext_background_basic` | 0 | 21.1s |  |
| 61 | `edittext/edittext_background_basic_scale2` | 0 | 21.6s |  |
| 62 | `edittext/edittext_border_basic` | 0 | 21.8s |  |
| 63 | `edittext/edittext_border_basic_scale2` | 0 | 2.0s |  |
| 64 | `edittext/edittext_border_filters` | 0 | 2.4s |  |
| 65 | `edittext/edittext_border_transform` | 0 | 2.8s |  |
| 66 | `edittext/edittext_bounds_vs_position` | 0 | 21.6s |  |
| 67 | `edittext/edittext_caret_empty` | 0 | 22.4s |  |
| 68 | `edittext/edittext_device_transform_basic` | 24 | 27.9s |  |
| 69 | `edittext/edittext_device_transform_small_rotation` | 0 | 21.3s |  |
| 70 | `edittext/edittext_device_transform_small_shear` | 0 | 21.4s |  |
| 71 | `edittext/edittext_gutter` | 0 | 28.0s |  |
| 72 | `edittext/edittext_justify` | 0 | 27.8s |  |
| 73 | `edittext/edittext_negative_bounds` | 0 | 2.2s |  |
| 74 | `edittext/edittext_selection_font_size` | 0 | 26.8s |  |
| 75 | `edittext/edittext_selection_leading` | 12 | 27.9s |  |
| 76 | `edittext/edittext_underline` | 0 | 28.4s |  |
| 77 | `edittext/edittext_underline_scale2` | 0 | 25.0s |  |
| 78 | `filters/any_blur_scales_with_screen` | 0 | 21.1s |  |
| 79 | `filters/avm1_convolution_initialization` | 18 | 2.2s |  |
| 80 | `filters/bevel` | 0 | 22.9s |  |
| 81 | `filters/bevel_full` | 0 | 24.5s |  |
| 82 | `filters/bevel_inner` | 0 | 4.7s |  |
| 83 | `filters/bevel_outer` | 0 | 4.9s |  |
| 84 | `filters/blur_fractional` | 0 | 28.3s |  |
| 85 | `filters/blur_pass_scaling` | 0 | 29.4s |  |
| 86 | `filters/blur_quality` | 0 | 9.1s |  |
| 87 | `filters/blur_scales_with_screen` | 0 | 20.8s |  |
| 88 | `filters/blur_size_grows` | 0 | 2.5s |  |
| 89 | `filters/color_matrix` | 0 | 2.5s |  |
| 90 | `filters/displacement_map` | 0 | 30.8s |  |
| 91 | `filters/displacement_map_scales_with_screen` | 0 | 30.9s |  |
| 92 | `filters/displacement_map_through_applyFilter` | 0 | 28.9s |  |
| 93 | `filters/displacement_map_through_filters` | 0 | 8.8s |  |
| 94 | `filters/drop_shadow` | 0 | 3.8s |  |
| 95 | `filters/drop_shadow_angles` | 0 | 2.9s |  |
| 96 | `filters/drop_shadow_scales_with_screen` | 0 | 22.8s |  |
| 97 | `filters/glow` | 0 | 2.9s |  |
| 98 | `filters/glow_pass_scaling` | 0 | 29.4s |  |
| 99 | `filters/glow_with_alpha_strength` | 0 | 20.5s |  |
| 100 | `filters/glow_without_composite_source` | 0 | 2.5s |  |
| 101 | `focus_highlight/focus_highlight_avm1_button` | 6 | 17.7s |  |
| 102 | `focus_highlight/focus_highlight_avm2_button_bounds` | 1 | 22.4s |  |
| 103 | `focus_highlight/focus_highlight_basic` | 0 | 3.7s |  |
| 104 | `focus_highlight/focus_highlight_empty_clip` | 0 | 29.6s |  |
| 105 | `focus_highlight/focus_highlight_move` | 0 | 23.1s |  |
| 106 | `focus_highlight/focus_highlight_render` | 0 | 3.8s |  |
| 107 | `fonts/advance_u16` | 0 | 22.1s |  |
| 108 | `fonts/device-font` | 0 | 8.8s |  |
| 109 | `fonts/duplicate_font` | 0 | 9.4s |  |
| 110 | `fonts/font_lookup_as3` | 0 | 8.9s |  |
| 111 | `fonts/glyph` | 0 | 8.7s |  |
| 112 | `fonts/leading_define_font` | 0 | 21.9s |  |
| 113 | `fonts/leading_device_font` | 0 | 28.2s |  |
| 114 | `fonts/leading_embedded_font` | 0 | 22.5s |  |
| 115 | `gradient_issue_9892` | 0 | 17.4s |  |
| 116 | `gradient_nonsequential_ratios` | 0 | 16.9s |  |
| 117 | `gradient_radial_same_ratios` | 0 | 17.0s |  |
| 118 | `gradient_same_ratios` | 0 | 1.7s |  |
| 119 | `layout/line_vertical_align` | 0 | 29.3s |  |
| 120 | `opaque_background` | 0 | 2.5s |  |
| 121 | `scale_rotation_cache` | 106 | 23.3s |  |
| 122 | `simple_shapes/gradients/focal_radial` | 0 | 2.7s |  |
| 123 | `simple_shapes/gradients/gradients` | 0 | 2.8s |  |
| 124 | `simple_shapes/gradients/radial` | 0 | 2.8s |  |
| 125 | `simple_shapes/gradients/reflect` | 0 | 2.7s |  |
| 126 | `simple_shapes/gradients/repeat` | 0 | 2.7s |  |
| 127 | `simple_shapes/heavy_tesselation` | 0 | 69.0s |  |
| 128 | `simple_shapes/layers` | 0 | 2.4s |  |
| 129 | `simple_shapes/masks` | 0 | 2.0s |  |
| 130 | `simple_shapes/masks_equal_clipdepth` | 0 | 1.6s |  |
| 131 | `simple_shapes/overlaps` | 0 | 1.9s |  |
| 132 | `simple_shapes/scroll_rect_mask` | 0 | 1.8s |  |
| 133 | `simple_shapes/strokes/scale` | 0 | 1.2s |  |
| 134 | `simple_shapes/text_field_mask` | 0 | 1.5s |  |
| 135 | `simple_shapes/winding_rule` | 0 | 1.3s |  |
| 136 | `text/String_path_variable_button` | 0 | 1.1s |  |
| 137 | `video/colorconversion/h263` | 0 | 22.1s |  |
| 138 | `video/colorconversion/vp6` | 0 | 2.6s |  |
| 139 | `video/colorconversion/vp6a` | 0 | 2.9s |  |
| 140 | `video/deblocking` | 0 | 24.2s |  |
| 141 | `video/h264` | 0 | 29.2s |  |
| 142 | `video/h264_multinalu` | 0 | 27.4s |  |
| 143 | `video/vp6_alphaoffset` | 0 | 21.7s |  |
| 144 | `video/vp6_dispsize` | 0 | 21.4s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `edittext/edittext_device_transform_metrics` | 8 | 8 | 8.4s |  |
| 2 | `edittext/edittext_device_transform_negative` | 41 | 41 | 8.9s |  |

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
