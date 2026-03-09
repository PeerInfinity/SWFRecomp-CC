# Ruffle AVM1 Image Comparison Test Results

**Date**: 2026-03-09 04:08 UTC
**Git SHA**: `976737f27a`
**Run Duration**: 13m 48s

## Summary

| Metric | Value |
|--------|-------|
| Total image tests | 31 |
| Image passing | **5** (16%) |
| Image failing | 25 |
| No render (build/runtime fail) | 1 |
| Trace output passing | 26 (84%) |

## Passing Image Tests

**5 tests** with matching rendered output

| # | Test | Trace | Duration |
|---|------|-------|----------|
| 1 | `display_object_properties` | PASS | 26.8s |
| 2 | `focusrect_focuslost` | PASS | 27.0s |
| 3 | `focusrect_swf6` | PASS | 30.1s |
| 4 | `frame_size_translated_negative` | PASS | 29.4s |
| 5 | `frame_size_translated_positive` | PASS | 28.4s |

## Failing Image Tests

**25 tests** with image comparison failures (sorted by outlier count, closest to passing first)

| # | Test | Trace | Image Result | Duration |
|---|------|-------|-------------|----------|
| 1 | `focusrect_mouse_swf8` | PASS | 6/8 pass (2 fail: 408 outliers each) | 25.1s |
| 2 | `focusrect_swf5` | PASS | 10/12 pass (2 fail: 408 outliers each) | 29.3s |
| 3 | `focusrect_mouse_swf9` | PASS | 2/8 pass (6 fail: 408 outliers each) | 27.2s |
| 4 | `mouse_events_visible_enabled` | PASS | 3,614 outliers, max diff 102 | 26.1s |
| 5 | `bitmap_data_fillrect` | PASS | 3,914 outliers, max diff 255 | 28.2s |
| 6 | `edittext_tag_indent` | PASS | 6,336 outliers, max diff 255 | 28.1s |
| 7 | `movieclip_setmask` | PASS | 10,096 outliers, max diff 255 | 21.0s |
| 8 | `movieclip_create_text_field` | OUTPUT_MISMATCH | 15,000 outliers, max diff 255 | 22.4s |
| 9 | `movieclip_methods_with_loaded_image` | OUTPUT_MISMATCH | 23,893 outliers, max diff 235 | 22.4s |
| 10 | `color` | PASS | 30,000 outliers, max diff 48 | 29.2s |
| 11 | `edittext_stylesheet` | PASS | 33,126 outliers, max diff 255 | 28.5s |
| 12 | `mask_reapply` | PASS | 36,156 outliers, max diff 204 | 20.6s |
| 13 | `bitmapdata_applyfilter_colormatrix` | PASS | 45,000 outliers, max diff 62 | 28.9s |
| 14 | `netstream_play_flv` | OUTPUT_MISMATCH | 57,444 outliers, max diff 255 | 21.7s |
| 15 | `bitmap_data_colortransform` | PASS | 78,561 outliers, max diff 255 | 27.2s |
| 16 | `mask_with_drawing` | PASS | 80,000 outliers, max diff 255 | 25.0s |
| 17 | `movieclip_line_gradient_style` | PASS | 103,101 outliers, max diff 255 | 28.3s |
| 18 | `bitmap_data_pixeldissolve_image` | PASS | 172,347 outliers, max diff 255 | 29.1s |
| 19 | `movieclip_begin_gradient_fill` | PASS | 224,509 outliers, max diff 255 | 25.5s |
| 20 | `mcl_target_gif87a` | PASS | 339,493 outliers, max diff 255 | 23.2s |
| 21 | `mcl_target_gif89a` | PASS | 339,493 outliers, max diff 255 | 21.1s |
| 22 | `mcl_target_png` | PASS | 424,993 outliers, max diff 255 | 21.5s |
| 23 | `mcl_target_jpg` | PASS | 427,503 outliers, max diff 255 | 21.4s |
| 24 | `bitmap_data_copypixels` | OUTPUT_MISMATCH | 480,000 outliers, max diff 255 | 29.2s |
| 25 | `bitmap_data_perlinnoise` | PASS | 875,000 outliers, max diff 255 | 32.1s |

## Tests That Could Not Render

**1 tests** failed before image comparison (build or runtime error)

| # | Test | Status | Duration |
|---|------|--------|----------|
| 1 | `netstream_play_flv_screen` | segfault | 43.6s |
