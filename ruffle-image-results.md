# Ruffle AVM1 Image Comparison Test Results

**Date**: 2026-03-08 20:58 UTC
**Git SHA**: `2e40877110`
**Run Duration**: 9m 43s

## Summary

| Metric | Value |
|--------|-------|
| Total image tests | 31 |
| Image passing | **2** (6%) |
| Image failing | 28 |
| No render (build/runtime fail) | 1 |
| Trace output passing | 27 (87%) |

## Passing Image Tests

**2 tests** with matching rendered output

| # | Test | Trace | Duration |
|---|------|-------|----------|
| 1 | `display_object_properties` | PASS | 17.2s |
| 2 | `focusrect_focuslost` | PASS | 16.8s |

## Failing Image Tests

**28 tests** with image comparison failures (sorted by outlier count, closest to passing first)

| # | Test | Trace | Image Result | Duration |
|---|------|-------|-------------|----------|
| 1 | `frame_size_translated_positive` | PASS | 231 outliers, max diff 255 | 16.9s |
| 2 | `frame_size_translated_negative` | PASS | 256 outliers, max diff 255 | 17.1s |
| 3 | `focusrect_mouse_swf8` | PASS | 5/8 pass (3 fail: 408 outliers each) | 18.5s |
| 4 | `focusrect_swf5` | PASS | 6/12 pass (6 fail: 408 outliers each) | 17.8s |
| 5 | `focusrect_swf6` | PASS | 6/12 pass (6 fail: 408 outliers each) | 17.9s |
| 6 | `focusrect_mouse_swf9` | PASS | 1/8 pass (7 fail: 408 outliers each) | 17.7s |
| 7 | `bitmap_data_fillrect` | PASS | 3,914 outliers, max diff 255 | 17.0s |
| 8 | `movieclip_create_text_field` | PASS | 7,500 outliers, max diff 255 | 18.6s |
| 9 | `edittext_tag_indent` | PASS | 8,421 outliers, max diff 255 | 17.7s |
| 10 | `movieclip_methods_with_loaded_image` | OUTPUT_MISMATCH | 23,893 outliers, max diff 235 | 20.0s |
| 11 | `mask_reapply` | PASS | 36,156 outliers, max diff 204 | 19.2s |
| 12 | `bitmapdata_applyfilter_colormatrix` | PASS | 45,000 outliers, max diff 62 | 18.5s |
| 13 | `netstream_play_flv` | OUTPUT_MISMATCH | 57,444 outliers, max diff 255 | 18.0s |
| 14 | `mask_with_drawing` | PASS | 60,000 outliers, max diff 255 | 18.0s |
| 15 | `edittext_stylesheet` | PASS | 60,366 outliers, max diff 255 | 19.5s |
| 16 | `color` | PASS | 70,000 outliers, max diff 91 | 18.1s |
| 17 | `bitmap_data_colortransform` | PASS | 78,561 outliers, max diff 255 | 16.8s |
| 18 | `movieclip_line_gradient_style` | PASS | 103,017 outliers, max diff 255 | 18.8s |
| 19 | `movieclip_setmask` | PASS | 171,580 outliers, max diff 255 | 18.7s |
| 20 | `bitmap_data_pixeldissolve_image` | PASS | 172,347 outliers, max diff 255 | 17.3s |
| 21 | `mouse_events_visible_enabled` | PASS | 287,006 outliers, max diff 204 | 18.6s |
| 22 | `mcl_target_gif87a` | PASS | 339,493 outliers, max diff 255 | 18.4s |
| 23 | `mcl_target_gif89a` | PASS | 339,493 outliers, max diff 255 | 18.7s |
| 24 | `movieclip_begin_gradient_fill` | PASS | 359,629 outliers, max diff 255 | 21.2s |
| 25 | `mcl_target_png` | PASS | 424,993 outliers, max diff 255 | 18.5s |
| 26 | `mcl_target_jpg` | PASS | 427,503 outliers, max diff 255 | 20.1s |
| 27 | `bitmap_data_copypixels` | OUTPUT_MISMATCH | 480,000 outliers, max diff 255 | 18.4s |
| 28 | `bitmap_data_perlinnoise` | PASS | 875,000 outliers, max diff 255 | 19.0s |

## Tests That Could Not Render

**1 tests** failed before image comparison (build or runtime error)

| # | Test | Status | Duration |
|---|------|--------|----------|
| 1 | `netstream_play_flv_screen` | segfault | 33.9s |
