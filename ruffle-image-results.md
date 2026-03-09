# Ruffle AVM1 Image Comparison Test Results

**Date**: 2026-03-08 22:59 UTC
**Git SHA**: `e082e8642e`
**Run Duration**: 10m 1s

## Summary

| Metric | Value |
|--------|-------|
| Total image tests | 31 |
| Image passing | **4** (13%) |
| Image failing | 26 |
| No render (build/runtime fail) | 1 |
| Trace output passing | 27 (87%) |

## Passing Image Tests

**4 tests** with matching rendered output

| # | Test | Trace | Duration |
|---|------|-------|----------|
| 1 | `display_object_properties` | PASS | 18.2s |
| 2 | `focusrect_focuslost` | PASS | 18.2s |
| 3 | `frame_size_translated_negative` | PASS | 19.4s |
| 4 | `frame_size_translated_positive` | PASS | 18.5s |

## Failing Image Tests

**26 tests** with image comparison failures (sorted by outlier count, closest to passing first)

| # | Test | Trace | Image Result | Duration |
|---|------|-------|-------------|----------|
| 1 | `focusrect_mouse_swf8` | PASS | 5/8 pass (3 fail: 408 outliers each) | 17.7s |
| 2 | `focusrect_swf5` | PASS | 6/12 pass (6 fail: 408 outliers each) | 17.7s |
| 3 | `focusrect_swf6` | PASS | 6/12 pass (6 fail: 408 outliers each) | 18.9s |
| 4 | `focusrect_mouse_swf9` | PASS | 1/8 pass (7 fail: 408 outliers each) | 19.5s |
| 5 | `bitmap_data_fillrect` | PASS | 3,914 outliers, max diff 255 | 19.8s |
| 6 | `edittext_tag_indent` | PASS | 6,336 outliers, max diff 255 | 18.8s |
| 7 | `movieclip_create_text_field` | PASS | 15,000 outliers, max diff 255 | 18.6s |
| 8 | `movieclip_methods_with_loaded_image` | OUTPUT_MISMATCH | 23,893 outliers, max diff 235 | 18.6s |
| 9 | `mask_reapply` | PASS | 36,156 outliers, max diff 204 | 19.6s |
| 10 | `bitmapdata_applyfilter_colormatrix` | PASS | 45,000 outliers, max diff 62 | 18.3s |
| 11 | `edittext_stylesheet` | PASS | 53,001 outliers, max diff 255 | 20.1s |
| 12 | `netstream_play_flv` | OUTPUT_MISMATCH | 57,444 outliers, max diff 255 | 18.3s |
| 13 | `mask_with_drawing` | PASS | 60,000 outliers, max diff 255 | 17.9s |
| 14 | `color` | PASS | 70,000 outliers, max diff 91 | 18.8s |
| 15 | `bitmap_data_colortransform` | PASS | 78,561 outliers, max diff 255 | 20.3s |
| 16 | `movieclip_line_gradient_style` | PASS | 103,017 outliers, max diff 255 | 20.2s |
| 17 | `movieclip_setmask` | PASS | 171,580 outliers, max diff 255 | 18.4s |
| 18 | `bitmap_data_pixeldissolve_image` | PASS | 172,347 outliers, max diff 255 | 18.7s |
| 19 | `mouse_events_visible_enabled` | PASS | 287,006 outliers, max diff 204 | 18.5s |
| 20 | `mcl_target_gif87a` | PASS | 339,493 outliers, max diff 255 | 18.7s |
| 21 | `mcl_target_gif89a` | PASS | 339,493 outliers, max diff 255 | 19.0s |
| 22 | `movieclip_begin_gradient_fill` | PASS | 359,629 outliers, max diff 255 | 18.4s |
| 23 | `mcl_target_png` | PASS | 424,993 outliers, max diff 255 | 18.0s |
| 24 | `mcl_target_jpg` | PASS | 427,503 outliers, max diff 255 | 18.3s |
| 25 | `bitmap_data_copypixels` | OUTPUT_MISMATCH | 480,000 outliers, max diff 255 | 19.3s |
| 26 | `bitmap_data_perlinnoise` | PASS | 875,000 outliers, max diff 255 | 20.1s |

## Tests That Could Not Render

**1 tests** failed before image comparison (build or runtime error)

| # | Test | Status | Duration |
|---|------|--------|----------|
| 1 | `netstream_play_flv_screen` | segfault | 35.7s |
