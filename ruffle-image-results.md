# Ruffle AVM1 Image Comparison Test Results

**Date**: 2026-03-09 05:37 UTC
**Git SHA**: `5abba1955f`
**Run Duration**: 10m 30s

## Summary

| Metric | Value |
|--------|-------|
| Total image tests | 31 |
| Image passing | **7** (23%) |
| Image failing | 23 |
| No render (build/runtime fail) | 1 |
| Trace output passing | 22 (71%) |

## Passing Image Tests

**7 tests** with matching rendered output

| # | Test | Trace | Duration |
|---|------|-------|----------|
| 1 | `display_object_properties` | PASS | 19.2s |
| 2 | `focusrect_focuslost` | PASS | 19.3s |
| 3 | `focusrect_mouse_swf8` | OUTPUT_MISMATCH | 18.9s |
| 4 | `focusrect_mouse_swf9` | OUTPUT_MISMATCH | 19.1s |
| 5 | `focusrect_swf6` | OUTPUT_MISMATCH | 19.4s |
| 6 | `frame_size_translated_negative` | PASS | 19.4s |
| 7 | `frame_size_translated_positive` | PASS | 19.4s |

## Failing Image Tests

**23 tests** with image comparison failures (sorted by outlier count, closest to passing first)

| # | Test | Trace | Image Result | Duration |
|---|------|-------|-------------|----------|
| 1 | `focusrect_swf5` | OUTPUT_MISMATCH | 10/12 pass (2 fail: 408 outliers each) | 19.3s |
| 2 | `mouse_events_visible_enabled` | PASS | 3,614 outliers, max diff 102 | 19.8s |
| 3 | `bitmap_data_fillrect` | PASS | 3,914 outliers, max diff 255 | 19.5s |
| 4 | `edittext_tag_indent` | PASS | 6,336 outliers, max diff 255 | 20.3s |
| 5 | `movieclip_setmask` | PASS | 10,096 outliers, max diff 255 | 19.9s |
| 6 | `movieclip_create_text_field` | OUTPUT_MISMATCH | 15,000 outliers, max diff 255 | 19.6s |
| 7 | `movieclip_methods_with_loaded_image` | OUTPUT_MISMATCH | 23,893 outliers, max diff 235 | 19.4s |
| 8 | `color` | PASS | 30,000 outliers, max diff 48 | 19.7s |
| 9 | `edittext_stylesheet` | PASS | 33,126 outliers, max diff 255 | 20.1s |
| 10 | `mask_reapply` | PASS | 36,156 outliers, max diff 204 | 18.9s |
| 11 | `bitmapdata_applyfilter_colormatrix` | PASS | 45,000 outliers, max diff 62 | 18.8s |
| 12 | `netstream_play_flv` | OUTPUT_MISMATCH | 57,444 outliers, max diff 255 | 20.5s |
| 13 | `bitmap_data_colortransform` | PASS | 78,561 outliers, max diff 255 | 20.4s |
| 14 | `mask_with_drawing` | PASS | 80,000 outliers, max diff 255 | 19.0s |
| 15 | `movieclip_line_gradient_style` | PASS | 103,101 outliers, max diff 255 | 19.8s |
| 16 | `bitmap_data_pixeldissolve_image` | PASS | 172,347 outliers, max diff 255 | 19.8s |
| 17 | `movieclip_begin_gradient_fill` | PASS | 224,509 outliers, max diff 255 | 20.4s |
| 18 | `mcl_target_gif87a` | PASS | 339,493 outliers, max diff 255 | 19.9s |
| 19 | `mcl_target_gif89a` | PASS | 339,493 outliers, max diff 255 | 19.6s |
| 20 | `mcl_target_png` | PASS | 424,993 outliers, max diff 255 | 19.4s |
| 21 | `mcl_target_jpg` | PASS | 427,503 outliers, max diff 255 | 19.4s |
| 22 | `bitmap_data_copypixels` | OUTPUT_MISMATCH | 480,000 outliers, max diff 255 | 21.5s |
| 23 | `bitmap_data_perlinnoise` | PASS | 875,000 outliers, max diff 255 | 21.5s |

## Tests That Could Not Render

**1 tests** failed before image comparison (build or runtime error)

| # | Test | Status | Duration |
|---|------|--------|----------|
| 1 | `netstream_play_flv_screen` | segfault | 39.0s |
