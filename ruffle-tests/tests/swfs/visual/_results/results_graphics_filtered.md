# Ruffle Test Results (Filtered)

**Date**: 2026-09-04 16:10 UTC

**Git SHA**: `d045bec8a8`

**Run Duration**: 34m 10s

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
| 1 | `avm2_button_scroll_rect` | 2 | 28.0s |  |
| 2 | `bitmapdata_copypixels_with_alpha_oob` | 0 | 9.3s |  |
| 3 | `blend_across_masks_issue_24549` | 0 | 21.6s |  |
| 4 | `blend_modes/add` | 0 | 2.9s |  |
| 5 | `blend_modes/alpha_no_layer` | 0 | 2.8s |  |
| 6 | `blend_modes/darken` | 0 | 2.9s |  |
| 7 | `blend_modes/difference` | 0 | 2.6s |  |
| 8 | `blend_modes/erase_no_layer` | 0 | 2.8s |  |
| 9 | `blend_modes/hardlight` | 0 | 2.6s |  |
| 10 | `blend_modes/invert` | 0 | 2.6s |  |
| 11 | `blend_modes/layer_alpha` | 0 | 2.4s |  |
| 12 | `blend_modes/layer_erase` | 0 | 1.4s |  |
| 13 | `blend_modes/lighten` | 0 | 2.4s |  |
| 14 | `blend_modes/masked_layer_cached_children` | 0 | 24.8s |  |
| 15 | `blend_modes/multiply` | 0 | 2.5s |  |
| 16 | `blend_modes/overlay` | 0 | 2.0s |  |
| 17 | `blend_modes/overlay_onto_stage` | 0 | 1.8s |  |
| 18 | `blend_modes/screen` | 0 | 1.8s |  |
| 19 | `blend_modes/shader_as_mask` | 0 | 21.3s |  |
| 20 | `blend_modes/shader_without_shader` | 1 | 20.0s |  |
| 21 | `blend_modes/subtract` | 0 | 3.2s |  |
| 22 | `bmd_draw_with_msaa_issue_10579` | 0 | 2.5s |  |
| 23 | `cache_as_bitmap/avm1_color` | 0 | 22.2s |  |
| 24 | `cache_as_bitmap/avm2_button` | 0 | 22.0s |  |
| 25 | `cache_as_bitmap/avm2_button_state` | 0 | 22.4s |  |
| 26 | `cache_as_bitmap/bitmap_changed` | 0 | 31.7s |  |
| 27 | `cache_as_bitmap/cab_bitmapdata_invalidate` | 0 | 26.6s |  |
| 28 | `cache_as_bitmap/cab_mask_alpha` | 0 | 32.0s |  |
| 29 | `cache_as_bitmap/cab_mask_filters` | 0 | 9.5s |  |
| 30 | `cache_as_bitmap/cab_mask_transform` | 0 | 29.4s |  |
| 31 | `cache_as_bitmap/cab_mask_triangle` | 0 | 30.7s |  |
| 32 | `cache_as_bitmap/children_changed` | 0 | 2.5s |  |
| 33 | `cache_as_bitmap/color_transform` | 0 | 2.4s |  |
| 34 | `cache_as_bitmap/contains_grown_filter` | 0 | 22.5s |  |
| 35 | `cache_as_bitmap/drawing_api` | 0 | 2.8s |  |
| 36 | `cache_as_bitmap/edittext_hscroll` | 1 | 15.6s |  |
| 37 | `cache_as_bitmap/edittext_scroll` | 0 | 15.7s |  |
| 38 | `cache_as_bitmap/edittext_selection` | 0 | 15.9s |  |
| 39 | `cache_as_bitmap/masks` | 0 | 7.1s |  |
| 40 | `cache_as_bitmap/morph` | 0 | 1.6s |  |
| 41 | `cache_as_bitmap/nested_color_transform` | 0 | 2.8s |  |
| 42 | `cache_as_bitmap/nested_matrix` | 0 | 2.5s |  |
| 43 | `cache_as_bitmap/nested_rotation` | 0 | 2.6s |  |
| 44 | `cache_as_bitmap/oversize/swf_10_masks` | 0 | 28.8s |  |
| 45 | `cache_as_bitmap/oversize/swf_10_too_big` | 0 | 8.7s |  |
| 46 | `cache_as_bitmap/oversize/swf_9_masks` | 0 | 28.8s |  |
| 47 | `cache_as_bitmap/oversize/swf_9_too_big` | 0 | 3.5s |  |
| 48 | `cache_as_bitmap/scroll_rect` | 0 | 3.2s |  |
| 49 | `cache_as_bitmap/scroll_rect_scaled` | 0 | 22.0s |  |
| 50 | `cache_as_bitmap/shape_changed` | 0 | 2.5s |  |
| 51 | `cache_as_bitmap/text` | 0 | 2.2s |  |
| 52 | `color_transform_issue_9698` | 0 | 1.7s |  |
| 53 | `define_bits_jpeg2_huge` | 19 | 20.0s |  |
| 54 | `define_bits_lossless2_rgb15` | 0 | 1.7s |  |
| 55 | `definefont4` | 0 | 73.1s |  |
| 56 | `drawing_api/cursor` | 0 | 2.4s |  |
| 57 | `drawing_api/drawing_order` | 0 | 2.5s |  |
| 58 | `drawing_api/fills_and_lines` | 0 | 2.7s |  |
| 59 | `drawing_api/gradient_focal_point` | 0 | 22.8s |  |
| 60 | `edittext/edittext_background_basic` | 0 | 21.9s |  |
| 61 | `edittext/edittext_background_basic_scale2` | 0 | 22.0s |  |
| 62 | `edittext/edittext_border_basic` | 0 | 21.9s |  |
| 63 | `edittext/edittext_border_basic_scale2` | 0 | 2.1s |  |
| 64 | `edittext/edittext_border_filters` | 0 | 2.5s |  |
| 65 | `edittext/edittext_border_transform` | 0 | 2.8s |  |
| 66 | `edittext/edittext_bounds_vs_position` | 0 | 21.9s |  |
| 67 | `edittext/edittext_caret_empty` | 0 | 22.7s |  |
| 68 | `edittext/edittext_device_transform_basic` | 24 | 28.4s |  |
| 69 | `edittext/edittext_device_transform_small_rotation` | 0 | 22.1s |  |
| 70 | `edittext/edittext_device_transform_small_shear` | 0 | 21.5s |  |
| 71 | `edittext/edittext_gutter` | 0 | 28.1s |  |
| 72 | `edittext/edittext_justify` | 0 | 27.5s |  |
| 73 | `edittext/edittext_negative_bounds` | 0 | 2.1s |  |
| 74 | `edittext/edittext_selection_font_size` | 0 | 28.6s |  |
| 75 | `edittext/edittext_selection_leading` | 12 | 30.7s |  |
| 76 | `edittext/edittext_underline` | 0 | 30.1s |  |
| 77 | `edittext/edittext_underline_scale2` | 0 | 26.3s |  |
| 78 | `filters/any_blur_scales_with_screen` | 0 | 21.7s |  |
| 79 | `filters/avm1_convolution_initialization` | 18 | 2.3s |  |
| 80 | `filters/bevel` | 0 | 25.0s |  |
| 81 | `filters/bevel_full` | 0 | 26.3s |  |
| 82 | `filters/bevel_inner` | 0 | 4.9s |  |
| 83 | `filters/bevel_outer` | 0 | 5.2s |  |
| 84 | `filters/blur_fractional` | 0 | 29.2s |  |
| 85 | `filters/blur_pass_scaling` | 0 | 30.6s |  |
| 86 | `filters/blur_quality` | 0 | 9.4s |  |
| 87 | `filters/blur_scales_with_screen` | 0 | 21.8s |  |
| 88 | `filters/blur_size_grows` | 0 | 2.5s |  |
| 89 | `filters/color_matrix` | 0 | 2.5s |  |
| 90 | `filters/displacement_map` | 0 | 31.5s |  |
| 91 | `filters/displacement_map_scales_with_screen` | 0 | 32.1s |  |
| 92 | `filters/displacement_map_through_applyFilter` | 0 | 29.8s |  |
| 93 | `filters/displacement_map_through_filters` | 0 | 9.0s |  |
| 94 | `filters/drop_shadow` | 0 | 3.4s |  |
| 95 | `filters/drop_shadow_angles` | 0 | 2.6s |  |
| 96 | `filters/drop_shadow_scales_with_screen` | 0 | 21.3s |  |
| 97 | `filters/glow` | 0 | 2.6s |  |
| 98 | `filters/glow_pass_scaling` | 0 | 28.3s |  |
| 99 | `filters/glow_with_alpha_strength` | 0 | 25.0s |  |
| 100 | `filters/glow_without_composite_source` | 0 | 2.7s |  |
| 101 | `focus_highlight/focus_highlight_avm1_button` | 6 | 21.9s |  |
| 102 | `focus_highlight/focus_highlight_avm2_button_bounds` | 1 | 28.3s |  |
| 103 | `focus_highlight/focus_highlight_basic` | 0 | 4.3s |  |
| 104 | `focus_highlight/focus_highlight_empty_clip` | 0 | 27.1s |  |
| 105 | `focus_highlight/focus_highlight_move` | 0 | 21.2s |  |
| 106 | `focus_highlight/focus_highlight_render` | 0 | 3.6s |  |
| 107 | `fonts/advance_u16` | 0 | 21.8s |  |
| 108 | `fonts/device-font` | 0 | 8.6s |  |
| 109 | `fonts/duplicate_font` | 0 | 9.3s |  |
| 110 | `fonts/font_lookup_as3` | 0 | 8.8s |  |
| 111 | `fonts/glyph` | 0 | 8.7s |  |
| 112 | `fonts/leading_define_font` | 0 | 22.0s |  |
| 113 | `fonts/leading_device_font` | 0 | 28.1s |  |
| 114 | `fonts/leading_embedded_font` | 0 | 28.6s |  |
| 115 | `gradient_issue_9892` | 0 | 22.3s |  |
| 116 | `gradient_nonsequential_ratios` | 0 | 21.6s |  |
| 117 | `gradient_radial_same_ratios` | 0 | 21.6s |  |
| 118 | `gradient_same_ratios` | 0 | 2.1s |  |
| 119 | `layout/line_vertical_align` | 0 | 22.1s |  |
| 120 | `opaque_background` | 0 | 1.9s |  |
| 121 | `scale_rotation_cache` | 106 | 17.4s |  |
| 122 | `simple_shapes/gradients/focal_radial` | 0 | 2.0s |  |
| 123 | `simple_shapes/gradients/gradients` | 0 | 2.1s |  |
| 124 | `simple_shapes/gradients/radial` | 0 | 2.0s |  |
| 125 | `simple_shapes/gradients/reflect` | 0 | 1.8s |  |
| 126 | `simple_shapes/gradients/repeat` | 0 | 2.5s |  |
| 127 | `simple_shapes/heavy_tesselation` | 0 | 41.1s |  |
| 128 | `simple_shapes/layers` | 0 | 1.7s |  |
| 129 | `simple_shapes/masks` | 0 | 2.9s |  |
| 130 | `simple_shapes/masks_equal_clipdepth` | 0 | 2.1s |  |
| 131 | `simple_shapes/overlaps` | 0 | 2.6s |  |
| 132 | `simple_shapes/scroll_rect_mask` | 0 | 2.4s |  |
| 133 | `simple_shapes/strokes/scale` | 0 | 1.1s |  |
| 134 | `simple_shapes/text_field_mask` | 0 | 1.4s |  |
| 135 | `simple_shapes/winding_rule` | 0 | 1.2s |  |
| 136 | `text/String_path_variable_button` | 0 | 1.1s |  |
| 137 | `video/colorconversion/h263` | 0 | 24.7s |  |
| 138 | `video/colorconversion/vp6` | 0 | 2.8s |  |
| 139 | `video/colorconversion/vp6a` | 0 | 3.2s |  |
| 140 | `video/deblocking` | 0 | 26.7s |  |
| 141 | `video/h264` | 0 | 30.1s |  |
| 142 | `video/h264_multinalu` | 0 | 28.6s |  |
| 143 | `video/vp6_alphaoffset` | 0 | 22.2s |  |
| 144 | `video/vp6_dispsize` | 0 | 21.8s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `edittext/edittext_device_transform_metrics` | 8 | 8 | 8.6s |  |
| 2 | `edittext/edittext_device_transform_negative` | 41 | 41 | 9.1s |  |

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
