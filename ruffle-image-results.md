# Ruffle AVM1 Image Comparison Test Results

**Date**: 2026-03-09 17:24 UTC
**Git SHA**: `d51288dc61`
**Run Duration**: 10m 54s

## Summary

| Metric | Value |
|--------|-------|
| Total image tests | 31 |
| Image passing | **7** (23%) |
| Image failing | 23 |
| No render (build/runtime fail) | 1 |
| Trace output passing | 23 (74%) |

## Passing Image Tests

**7 tests** with matching rendered output

| # | Test | Trace | Duration |
|---|------|-------|----------|
| 1 | `display_object_properties` | PASS | 22.2s |
| 2 | `focusrect_focuslost` | PASS | 20.0s |
| 3 | `focusrect_mouse_swf8` | OUTPUT_MISMATCH | 20.5s |
| 4 | `focusrect_mouse_swf9` | OUTPUT_MISMATCH | 20.3s |
| 5 | `focusrect_swf6` | OUTPUT_MISMATCH | 20.4s |
| 6 | `frame_size_translated_negative` | PASS | 18.9s |
| 7 | `frame_size_translated_positive` | PASS | 18.6s |

## Failing Image Tests

**23 tests** with image comparison failures (sorted by outlier count, closest to passing first)

| # | Test | Trace | Image Result | Duration |
|---|------|-------|-------------|----------|
| 1 | `focusrect_swf5` | OUTPUT_MISMATCH | 10/12 pass (2 fail: 408 outliers each) | 20.3s |
| 2 | `mouse_events_visible_enabled` | PASS | 3,614 outliers, max diff 102 | 18.0s |
| 3 | `bitmap_data_fillrect` | PASS | 3,914 outliers, max diff 255 | 17.8s |
| 4 | `edittext_tag_indent` | PASS | 6,336 outliers, max diff 255 | 20.4s |
| 5 | `movieclip_setmask` | PASS | 10,096 outliers, max diff 255 | 24.1s |
| 6 | `movieclip_create_text_field` | PASS | 15,000 outliers, max diff 255 | 22.9s |
| 7 | `movieclip_methods_with_loaded_image` | OUTPUT_MISMATCH | 23,893 outliers, max diff 235 | 23.1s |
| 8 | `color` | PASS | 30,000 outliers, max diff 48 | 22.9s |
| 9 | `edittext_stylesheet` | PASS | 33,126 outliers, max diff 255 | 22.0s |
| 10 | `mask_reapply` | PASS | 36,156 outliers, max diff 204 | 18.3s |
| 11 | `bitmapdata_applyfilter_colormatrix` | PASS | 45,000 outliers, max diff 62 | 21.3s |
| 12 | `movieclip_line_gradient_style` | PASS | 54,311 outliers, max diff 255 | 23.2s |
| 13 | `netstream_play_flv` | OUTPUT_MISMATCH | 57,444 outliers, max diff 255 | 23.5s |
| 14 | `bitmap_data_colortransform` | PASS | 78,561 outliers, max diff 255 | 18.9s |
| 15 | `mask_with_drawing` | PASS | 80,000 outliers, max diff 255 | 17.9s |
| 16 | `movieclip_begin_gradient_fill` | PASS | 134,883 outliers, max diff 255 | 20.2s |
| 17 | `bitmap_data_pixeldissolve_image` | PASS | 172,347 outliers, max diff 255 | 19.3s |
| 18 | `mcl_target_gif87a` | PASS | 339,493 outliers, max diff 255 | 18.0s |
| 19 | `mcl_target_gif89a` | PASS | 339,493 outliers, max diff 255 | 19.1s |
| 20 | `mcl_target_png` | PASS | 424,993 outliers, max diff 255 | 18.7s |
| 21 | `mcl_target_jpg` | PASS | 427,503 outliers, max diff 255 | 17.5s |
| 22 | `bitmap_data_copypixels` | OUTPUT_MISMATCH | 480,000 outliers, max diff 255 | 18.6s |
| 23 | `bitmap_data_perlinnoise` | PASS | 875,000 outliers, max diff 255 | 23.3s |

## Tests That Could Not Render

**1 tests** failed before image comparison (build or runtime error)

| # | Test | Status | Duration |
|---|------|--------|----------|
| 1 | `netstream_play_flv_screen` | segfault | 43.5s |
