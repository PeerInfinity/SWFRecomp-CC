# Ruffle Test Results (Filtered)

**Date**: 2026-11-27 06:45 UTC

**Git SHA**: `2d40d37996`

**Run Duration**: 35m 34s

**Filtered**: 0 tests ignored out of 151 available

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
| 1 | `avm2_button_scroll_rect` | 2 | 25.5s |  |
| 2 | `bitmapdata_copypixels_with_alpha_oob` | 0 | 7.6s |  |
| 3 | `blend_across_masks_issue_24549` | 0 | 1.7s |  |
| 4 | `blend_modes/add` | 0 | 2.1s |  |
| 5 | `blend_modes/alpha_no_layer` | 0 | 2.0s |  |
| 6 | `blend_modes/darken` | 0 | 2.1s |  |
| 7 | `blend_modes/difference` | 0 | 2.1s |  |
| 8 | `blend_modes/erase_no_layer` | 0 | 2.0s |  |
| 9 | `blend_modes/hardlight` | 0 | 1.9s |  |
| 10 | `blend_modes/invert` | 0 | 1.9s |  |
| 11 | `blend_modes/layer_alpha` | 0 | 2.0s |  |
| 12 | `blend_modes/layer_erase` | 0 | 2.2s |  |
| 13 | `blend_modes/lighten` | 0 | 2.1s |  |
| 14 | `blend_modes/masked_layer_cached_children` | 0 | 25.8s |  |
| 15 | `blend_modes/multiply` | 0 | 2.1s |  |
| 16 | `blend_modes/overlay` | 0 | 1.9s |  |
| 17 | `blend_modes/overlay_onto_stage` | 0 | 2.5s |  |
| 18 | `blend_modes/screen` | 0 | 2.8s |  |
| 19 | `blend_modes/shader_as_mask` | 0 | 31.0s |  |
| 20 | `blend_modes/shader_without_shader` | 1 | 27.3s |  |
| 21 | `blend_modes/subtract` | 0 | 2.9s |  |
| 22 | `bmd_draw_with_msaa_issue_10579` | 0 | 1.8s |  |
| 23 | `cache_as_bitmap/avm1_color` | 0 | 19.8s |  |
| 24 | `cache_as_bitmap/avm2_button` | 0 | 19.6s |  |
| 25 | `cache_as_bitmap/avm2_button_state` | 0 | 19.9s |  |
| 26 | `cache_as_bitmap/bitmap_changed` | 0 | 24.9s |  |
| 27 | `cache_as_bitmap/cab_bitmapdata_invalidate` | 0 | 33.5s |  |
| 28 | `cache_as_bitmap/cab_mask_alpha` | 0 | 36.1s |  |
| 29 | `cache_as_bitmap/cab_mask_filters` | 0 | 10.7s |  |
| 30 | `cache_as_bitmap/cab_mask_transform` | 0 | 33.7s |  |
| 31 | `cache_as_bitmap/cab_mask_triangle` | 0 | 12.4s |  |
| 32 | `cache_as_bitmap/children_changed` | 0 | 1.8s |  |
| 33 | `cache_as_bitmap/color_transform` | 0 | 1.7s |  |
| 34 | `cache_as_bitmap/contains_grown_filter` | 0 | 1.8s |  |
| 35 | `cache_as_bitmap/drawing_api` | 0 | 1.9s |  |
| 36 | `cache_as_bitmap/edittext_hscroll` | 1 | 19.5s |  |
| 37 | `cache_as_bitmap/edittext_scroll` | 0 | 26.1s |  |
| 38 | `cache_as_bitmap/edittext_selection` | 0 | 26.2s |  |
| 39 | `cache_as_bitmap/masks` | 0 | 11.6s |  |
| 40 | `cache_as_bitmap/morph` | 0 | 2.6s |  |
| 41 | `cache_as_bitmap/nested_color_transform` | 0 | 2.5s |  |
| 42 | `cache_as_bitmap/nested_matrix` | 0 | 2.2s |  |
| 43 | `cache_as_bitmap/nested_rotation` | 0 | 1.9s |  |
| 44 | `cache_as_bitmap/oversize/swf_10_masks` | 0 | 25.3s |  |
| 45 | `cache_as_bitmap/oversize/swf_10_too_big` | 0 | 7.1s |  |
| 46 | `cache_as_bitmap/oversize/swf_9_masks` | 0 | 2.5s |  |
| 47 | `color_transform_issue_9698` | 0 | 1.6s |  |
| 48 | `define_bits_jpeg2_huge` | 19 | 19.8s |  |
| 49 | `define_bits_lossless2_rgb15` | 0 | 1.6s |  |
| 50 | `definefont4` | 0 | 83.7s |  |
| 51 | `drawing_api/cursor` | 0 | 1.7s |  |
| 52 | `drawing_api/drawing_order` | 0 | 17.0s |  |
| 53 | `drawing_api/fills_and_lines` | 0 | 2.0s |  |
| 54 | `drawing_api/gradient_focal_point` | 0 | 16.9s |  |
| 55 | `edittext/edittext_background_basic` | 0 | 16.8s |  |
| 56 | `edittext/edittext_background_basic_scale2` | 0 | 16.3s |  |
| 57 | `edittext/edittext_border_basic` | 0 | 19.8s |  |
| 58 | `edittext/edittext_border_basic_scale2` | 0 | 19.6s |  |
| 59 | `edittext/edittext_border_filters` | 0 | 1.8s |  |
| 60 | `edittext/edittext_border_transform` | 0 | 2.1s |  |
| 61 | `edittext/edittext_bounds_vs_position` | 0 | 19.5s |  |
| 62 | `edittext/edittext_caret_empty` | 0 | 19.7s |  |
| 63 | `edittext/edittext_caret_multiline` | 0 | 25.3s |  |
| 64 | `edittext/edittext_device_transform_basic` | 24 | 24.7s |  |
| 65 | `edittext/edittext_device_transform_small_rotation` | 0 | 21.9s |  |
| 66 | `edittext/edittext_device_transform_small_shear` | 0 | 21.7s |  |
| 67 | `edittext/edittext_gutter` | 0 | 28.3s |  |
| 68 | `edittext/edittext_justify` | 0 | 27.8s |  |
| 69 | `edittext/edittext_negative_bounds` | 0 | 2.2s |  |
| 70 | `edittext/edittext_selection_font_size` | 0 | 35.8s |  |
| 71 | `edittext/edittext_selection_leading` | 12 | 36.5s |  |
| 72 | `edittext/edittext_underline` | 0 | 37.4s |  |
| 73 | `edittext/edittext_underline_scale2` | 0 | 36.1s |  |
| 74 | `filters/any_blur_scales_with_screen` | 0 | 25.5s |  |
| 75 | `filters/avm1_convolution_initialization` | 18 | 1.6s |  |
| 76 | `filters/bevel` | 0 | 21.2s |  |
| 77 | `filters/bevel_full` | 0 | 21.2s |  |
| 78 | `filters/bevel_inner` | 0 | 3.1s |  |
| 79 | `filters/bevel_outer` | 0 | 3.3s |  |
| 80 | `filters/blur_fractional` | 0 | 10.9s |  |
| 81 | `filters/blur_pass_scaling` | 0 | 39.4s |  |
| 82 | `filters/blur_quality` | 0 | 11.1s |  |
| 83 | `filters/blur_scales_with_screen` | 0 | 25.7s |  |
| 84 | `filters/blur_size_grows` | 0 | 3.1s |  |
| 85 | `filters/color_matrix` | 0 | 1.8s |  |
| 86 | `filters/displacement_map` | 0 | 26.8s |  |
| 87 | `filters/displacement_map_scales_with_screen` | 0 | 28.0s |  |
| 88 | `filters/displacement_map_through_applyFilter` | 0 | 25.9s |  |
| 89 | `filters/displacement_map_through_filters` | 0 | 7.4s |  |
| 90 | `filters/drop_shadow` | 0 | 3.6s |  |
| 91 | `filters/drop_shadow_angles` | 0 | 2.5s |  |
| 92 | `filters/drop_shadow_scales_with_screen` | 0 | 20.6s |  |
| 93 | `filters/empty_child_filter_bounds` | 0 | 20.7s |  |
| 94 | `filters/glow` | 0 | 2.5s |  |
| 95 | `filters/glow_pass_scaling` | 0 | 28.9s |  |
| 96 | `filters/glow_with_alpha_strength` | 0 | 23.3s |  |
| 97 | `filters/glow_without_composite_source` | 0 | 2.5s |  |
| 98 | `focus_highlight/focus_highlight_avm1_button` | 6 | 20.8s |  |
| 99 | `focus_highlight/focus_highlight_avm2_button_bounds` | 1 | 26.8s |  |
| 100 | `focus_highlight/focus_highlight_basic` | 0 | 2.9s |  |
| 101 | `focus_highlight/focus_highlight_empty_clip` | 0 | 26.1s |  |
| 102 | `focus_highlight/focus_highlight_move` | 0 | 20.6s |  |
| 103 | `focus_highlight/focus_highlight_render` | 0 | 2.8s |  |
| 104 | `fonts/advance_u16` | 0 | 20.0s |  |
| 105 | `fonts/device-font` | 0 | 8.0s |  |
| 106 | `fonts/duplicate_font` | 0 | 7.7s |  |
| 107 | `fonts/font_lookup_as3` | 0 | 7.6s |  |
| 108 | `fonts/glyph` | 0 | 7.3s |  |
| 109 | `fonts/leading_define_font` | 0 | 21.9s |  |
| 110 | `fonts/leading_device_font` | 0 | 26.3s |  |
| 111 | `fonts/leading_embedded_font` | 0 | 7.7s |  |
| 112 | `gradient_issue_9892` | 0 | 20.6s |  |
| 113 | `gradient_nonsequential_ratios` | 0 | 20.2s |  |
| 114 | `gradient_radial_same_ratios` | 0 | 19.8s |  |
| 115 | `gradient_same_ratios` | 0 | 28.4s |  |
| 116 | `layout/line_vertical_align` | 0 | 36.7s |  |
| 117 | `opaque_background` | 0 | 2.9s |  |
| 118 | `scale_rotation_cache` | 106 | 27.8s |  |
| 119 | `scroll_rect_culling` | 0 | 36.3s |  |
| 120 | `simple_shapes/gradients/focal_radial` | 0 | 1.9s |  |
| 121 | `simple_shapes/gradients/gradients` | 0 | 2.0s |  |
| 122 | `simple_shapes/gradients/radial` | 0 | 2.1s |  |
| 123 | `simple_shapes/gradients/reflect` | 0 | 2.0s |  |
| 124 | `simple_shapes/gradients/repeat` | 0 | 2.0s |  |
| 125 | `simple_shapes/heavy_tesselation` | 0 | 49.9s |  |
| 126 | `simple_shapes/layers` | 0 | 1.8s |  |
| 127 | `simple_shapes/masks` | 0 | 2.4s |  |
| 128 | `simple_shapes/masks_equal_clipdepth` | 0 | 1.6s |  |
| 129 | `simple_shapes/overlaps` | 0 | 1.8s |  |
| 130 | `simple_shapes/scroll_rect_mask` | 0 | 2.5s |  |
| 131 | `simple_shapes/strokes/scale` | 0 | 1.9s |  |
| 132 | `simple_shapes/text_field_mask` | 0 | 1.9s |  |
| 133 | `simple_shapes/winding_rule` | 0 | 20.5s |  |
| 134 | `static_text_offstage` | 0 | 20.7s |  |
| 135 | `text/String_path_variable_button` | 0 | 4.8s |  |
| 136 | `video/colorconversion/h263` | 0 | 29.4s |  |
| 137 | `video/colorconversion/vp6` | 0 | 2.9s |  |
| 138 | `video/colorconversion/vp6a` | 0 | 3.3s |  |
| 139 | `video/deblocking` | 0 | 30.5s |  |
| 140 | `video/h264` | 0 | 27.1s |  |
| 141 | `video/h264_multinalu` | 0 | 25.2s |  |
| 142 | `video/vp6_alphaoffset` | 0 | 19.6s |  |
| 143 | `video/vp6_dispsize` | 0 | 19.6s |  |
| 144 | `video/vp6_inter_frames` | 0 | 21.1s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `edittext/edittext_device_transform_metrics` | 8 | 8 | 7.2s |  |
| 2 | `edittext/edittext_device_transform_negative` | 41 | 41 | 7.4s |  |

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
