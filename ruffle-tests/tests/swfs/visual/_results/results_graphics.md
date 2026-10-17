# Ruffle Test Results (Unfiltered)

**Date**: 2026-10-17 00:59 UTC

**Git SHA**: `bdf127c35c`

**Run Duration**: 34m 55s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 147 |
| Passing | **145** (98.6%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **147** (100.0%) |
| Failing | 0 |
| Total expected lines | 350 |
| Matching lines | 301 (86.0%) |
| Mismatched lines | 49 |

## Passing Tests

**145 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `avm2_button_scroll_rect` | 2 | 30.5s |  |
| 2 | `bitmapdata_copypixels_with_alpha_oob` | 0 | 10.3s |  |
| 3 | `blend_across_masks_issue_24549` | 0 | 22.7s |  |
| 4 | `blend_modes/add` | 0 | 2.9s |  |
| 5 | `blend_modes/alpha_no_layer` | 0 | 2.9s |  |
| 6 | `blend_modes/darken` | 0 | 2.6s |  |
| 7 | `blend_modes/difference` | 0 | 2.5s |  |
| 8 | `blend_modes/erase_no_layer` | 0 | 2.6s |  |
| 9 | `blend_modes/hardlight` | 0 | 2.4s |  |
| 10 | `blend_modes/invert` | 0 | 2.5s |  |
| 11 | `blend_modes/layer_alpha` | 0 | 2.7s |  |
| 12 | `blend_modes/layer_erase` | 0 | 1.5s |  |
| 13 | `blend_modes/lighten` | 0 | 2.8s |  |
| 14 | `blend_modes/masked_layer_cached_children` | 0 | 28.8s |  |
| 15 | `blend_modes/multiply` | 0 | 2.7s |  |
| 16 | `blend_modes/overlay` | 0 | 2.5s |  |
| 17 | `blend_modes/overlay_onto_stage` | 0 | 2.3s |  |
| 18 | `blend_modes/screen` | 0 | 2.5s |  |
| 19 | `blend_modes/shader_as_mask` | 0 | 31.5s |  |
| 20 | `blend_modes/shader_without_shader` | 1 | 29.4s |  |
| 21 | `blend_modes/subtract` | 0 | 6.5s |  |
| 22 | `bmd_draw_with_msaa_issue_10579` | 0 | 2.5s |  |
| 23 | `cache_as_bitmap/avm1_color` | 0 | 22.1s |  |
| 24 | `cache_as_bitmap/avm2_button` | 0 | 21.9s |  |
| 25 | `cache_as_bitmap/avm2_button_state` | 0 | 22.5s |  |
| 26 | `cache_as_bitmap/bitmap_changed` | 0 | 28.9s |  |
| 27 | `cache_as_bitmap/cab_bitmapdata_invalidate` | 0 | 23.5s |  |
| 28 | `cache_as_bitmap/cab_mask_alpha` | 0 | 30.9s |  |
| 29 | `cache_as_bitmap/cab_mask_filters` | 0 | 9.3s |  |
| 30 | `cache_as_bitmap/cab_mask_transform` | 0 | 28.7s |  |
| 31 | `cache_as_bitmap/cab_mask_triangle` | 0 | 26.4s |  |
| 32 | `cache_as_bitmap/children_changed` | 0 | 2.1s |  |
| 33 | `cache_as_bitmap/color_transform` | 0 | 2.0s |  |
| 34 | `cache_as_bitmap/contains_grown_filter` | 0 | 18.5s |  |
| 35 | `cache_as_bitmap/drawing_api` | 0 | 2.2s |  |
| 36 | `cache_as_bitmap/edittext_hscroll` | 1 | 23.9s |  |
| 37 | `cache_as_bitmap/edittext_scroll` | 0 | 24.0s |  |
| 38 | `cache_as_bitmap/edittext_selection` | 0 | 23.7s |  |
| 39 | `cache_as_bitmap/masks` | 0 | 12.0s |  |
| 40 | `cache_as_bitmap/morph` | 0 | 2.5s |  |
| 41 | `cache_as_bitmap/nested_color_transform` | 0 | 1.8s |  |
| 42 | `cache_as_bitmap/nested_matrix` | 0 | 1.8s |  |
| 43 | `cache_as_bitmap/nested_rotation` | 0 | 1.8s |  |
| 44 | `cache_as_bitmap/oversize/swf_10_masks` | 0 | 20.0s |  |
| 45 | `cache_as_bitmap/oversize/swf_10_too_big` | 0 | 6.1s |  |
| 46 | `cache_as_bitmap/oversize/swf_9_masks` | 0 | 3.5s |  |
| 47 | `cache_as_bitmap/oversize/swf_9_too_big` | 0 | 3.2s |  |
| 48 | `cache_as_bitmap/scroll_rect` | 0 | 2.9s |  |
| 49 | `cache_as_bitmap/scroll_rect_scaled` | 0 | 21.4s |  |
| 50 | `cache_as_bitmap/shape_changed` | 0 | 2.2s |  |
| 51 | `cache_as_bitmap/text` | 0 | 23.4s |  |
| 52 | `color_transform_issue_9698` | 0 | 2.2s |  |
| 53 | `define_bits_jpeg2_huge` | 19 | 25.8s |  |
| 54 | `define_bits_lossless2_rgb15` | 0 | 2.2s |  |
| 55 | `definefont4` | 0 | 113.9s |  |
| 56 | `drawing_api/cursor` | 0 | 2.2s |  |
| 57 | `drawing_api/drawing_order` | 0 | 21.6s |  |
| 58 | `drawing_api/fills_and_lines` | 0 | 2.6s |  |
| 59 | `drawing_api/gradient_focal_point` | 0 | 21.6s |  |
| 60 | `edittext/edittext_background_basic` | 0 | 23.5s |  |
| 61 | `edittext/edittext_background_basic_scale2` | 0 | 22.2s |  |
| 62 | `edittext/edittext_border_basic` | 0 | 22.4s |  |
| 63 | `edittext/edittext_border_basic_scale2` | 0 | 2.0s |  |
| 64 | `edittext/edittext_border_filters` | 0 | 2.4s |  |
| 65 | `edittext/edittext_border_transform` | 0 | 2.8s |  |
| 66 | `edittext/edittext_bounds_vs_position` | 0 | 17.4s |  |
| 67 | `edittext/edittext_caret_empty` | 0 | 18.2s |  |
| 68 | `edittext/edittext_caret_multiline` | 0 | 7.7s |  |
| 69 | `edittext/edittext_device_transform_basic` | 24 | 7.2s |  |
| 70 | `edittext/edittext_device_transform_small_rotation` | 0 | 21.9s |  |
| 71 | `edittext/edittext_device_transform_small_shear` | 0 | 22.2s |  |
| 72 | `edittext/edittext_gutter` | 0 | 28.7s |  |
| 73 | `edittext/edittext_justify` | 0 | 28.8s |  |
| 74 | `edittext/edittext_negative_bounds` | 0 | 1.7s |  |
| 75 | `edittext/edittext_selection_font_size` | 0 | 18.7s |  |
| 76 | `edittext/edittext_selection_leading` | 12 | 19.2s |  |
| 77 | `edittext/edittext_underline` | 0 | 19.7s |  |
| 78 | `edittext/edittext_underline_scale2` | 0 | 20.8s |  |
| 79 | `filters/any_blur_scales_with_screen` | 0 | 22.0s |  |
| 80 | `filters/avm1_convolution_initialization` | 18 | 2.2s |  |
| 81 | `filters/bevel` | 0 | 24.1s |  |
| 82 | `filters/bevel_full` | 0 | 25.0s |  |
| 83 | `filters/bevel_inner` | 0 | 4.4s |  |
| 84 | `filters/bevel_outer` | 0 | 21.4s |  |
| 85 | `filters/blur_fractional` | 0 | 25.2s |  |
| 86 | `filters/blur_pass_scaling` | 0 | 26.2s |  |
| 87 | `filters/blur_quality` | 0 | 8.1s |  |
| 88 | `filters/blur_scales_with_screen` | 0 | 18.8s |  |
| 89 | `filters/blur_size_grows` | 0 | 2.8s |  |
| 90 | `filters/color_matrix` | 0 | 2.4s |  |
| 91 | `filters/displacement_map` | 0 | 31.0s |  |
| 92 | `filters/displacement_map_scales_with_screen` | 0 | 31.8s |  |
| 93 | `filters/displacement_map_through_applyFilter` | 0 | 29.3s |  |
| 94 | `filters/displacement_map_through_filters` | 0 | 24.6s |  |
| 95 | `filters/drop_shadow` | 0 | 2.4s |  |
| 96 | `filters/drop_shadow_angles` | 0 | 1.9s |  |
| 97 | `filters/drop_shadow_scales_with_screen` | 0 | 18.4s |  |
| 98 | `filters/glow` | 0 | 2.0s |  |
| 99 | `filters/glow_pass_scaling` | 0 | 31.4s |  |
| 100 | `filters/glow_with_alpha_strength` | 0 | 25.9s |  |
| 101 | `filters/glow_without_composite_source` | 0 | 2.9s |  |
| 102 | `focus_highlight/focus_highlight_avm1_button` | 6 | 23.1s |  |
| 103 | `focus_highlight/focus_highlight_avm2_button_bounds` | 1 | 29.7s |  |
| 104 | `focus_highlight/focus_highlight_basic` | 0 | 6.4s |  |
| 105 | `focus_highlight/focus_highlight_empty_clip` | 0 | 28.9s |  |
| 106 | `focus_highlight/focus_highlight_move` | 0 | 22.0s |  |
| 107 | `focus_highlight/focus_highlight_render` | 0 | 3.5s |  |
| 108 | `fonts/advance_u16` | 0 | 21.7s |  |
| 109 | `fonts/device-font` | 0 | 9.2s |  |
| 110 | `fonts/duplicate_font` | 0 | 9.2s |  |
| 111 | `fonts/font_lookup_as3` | 0 | 9.2s |  |
| 112 | `fonts/glyph` | 0 | 9.1s |  |
| 113 | `fonts/leading_define_font` | 0 | 23.0s |  |
| 114 | `fonts/leading_device_font` | 0 | 9.5s |  |
| 115 | `fonts/leading_embedded_font` | 0 | 9.6s |  |
| 116 | `gradient_issue_9892` | 0 | 23.0s |  |
| 117 | `gradient_nonsequential_ratios` | 0 | 22.7s |  |
| 118 | `gradient_radial_same_ratios` | 0 | 22.8s |  |
| 119 | `gradient_same_ratios` | 0 | 17.7s |  |
| 120 | `layout/line_vertical_align` | 0 | 23.9s |  |
| 121 | `opaque_background` | 0 | 2.0s |  |
| 122 | `scale_rotation_cache` | 106 | 18.5s |  |
| 123 | `simple_shapes/gradients/focal_radial` | 0 | 2.3s |  |
| 124 | `simple_shapes/gradients/gradients` | 0 | 2.2s |  |
| 125 | `simple_shapes/gradients/radial` | 0 | 2.3s |  |
| 126 | `simple_shapes/gradients/reflect` | 0 | 2.3s |  |
| 127 | `simple_shapes/gradients/repeat` | 0 | 3.2s |  |
| 128 | `simple_shapes/heavy_tesselation` | 0 | 61.4s |  |
| 129 | `simple_shapes/layers` | 0 | 2.6s |  |
| 130 | `simple_shapes/masks` | 0 | 2.7s |  |
| 131 | `simple_shapes/masks_equal_clipdepth` | 0 | 2.1s |  |
| 132 | `simple_shapes/overlaps` | 0 | 2.4s |  |
| 133 | `simple_shapes/scroll_rect_mask` | 0 | 2.4s |  |
| 134 | `simple_shapes/strokes/scale` | 0 | 1.6s |  |
| 135 | `simple_shapes/text_field_mask` | 0 | 1.8s |  |
| 136 | `simple_shapes/winding_rule` | 0 | 14.7s |  |
| 137 | `text/String_path_variable_button` | 0 | 1.7s |  |
| 138 | `video/colorconversion/h263` | 0 | 2.0s |  |
| 139 | `video/colorconversion/vp6` | 0 | 2.2s |  |
| 140 | `video/colorconversion/vp6a` | 0 | 2.0s |  |
| 141 | `video/deblocking` | 0 | 16.5s |  |
| 142 | `video/h264` | 0 | 34.5s |  |
| 143 | `video/h264_multinalu` | 0 | 29.2s |  |
| 144 | `video/vp6_alphaoffset` | 0 | 22.5s |  |
| 145 | `video/vp6_dispsize` | 0 | 22.2s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `edittext/edittext_device_transform_metrics` | 8 | 8 | 7.2s |  |
| 2 | `edittext/edittext_device_transform_negative` | 41 | 41 | 4.1s |  |

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
