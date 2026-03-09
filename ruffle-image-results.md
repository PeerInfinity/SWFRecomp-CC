# Ruffle AVM1 Image Comparison Test Results

**Date**: 2026-03-09 01:53 UTC
**Git SHA**: `d24c9463a8`
**Run Duration**: 9m 54s

## Summary

| Metric | Value |
|--------|-------|
| Total image tests | 31 |
| Image passing | **5** (16%) |
| Image failing | 25 |
| No render (build/runtime fail) | 1 |
| Trace output passing | 27 (87%) |

## Passing Image Tests

**5 tests** with matching rendered output

| # | Test | Trace | Duration |
|---|------|-------|----------|
| 1 | `display_object_properties` | PASS | 17.6s |
| 2 | `focusrect_focuslost` | PASS | 16.8s |
| 3 | `focusrect_swf6` | PASS | 18.4s |
| 4 | `frame_size_translated_negative` | PASS | 16.8s |
| 5 | `frame_size_translated_positive` | PASS | 17.3s |

## Failing Image Tests

**25 tests** with image comparison failures (sorted by outlier count, closest to passing first)

| # | Test | Trace | Image Result | Duration |
|---|------|-------|-------------|----------|
| 1 | `focusrect_mouse_swf8` | PASS | 6/8 pass (2 fail: 408 outliers each) | 17.3s |
| 2 | `focusrect_swf5` | PASS | 7/12 pass (fail: 03a=408, 03b=408, 04a=408, 04b=408, 05a=744) | 17.1s |
| 3 | `focusrect_mouse_swf9` | PASS | 2/8 pass (6 fail: 408 outliers each) | 16.9s |
| 4 | `bitmap_data_fillrect` | PASS | 3,914 outliers, max diff 255 | 19.8s |
| 5 | `edittext_tag_indent` | PASS | 6,336 outliers, max diff 255 | 17.1s |
| 6 | `movieclip_create_text_field` | PASS | 15,000 outliers, max diff 255 | 19.2s |
| 7 | `movieclip_methods_with_loaded_image` | OUTPUT_MISMATCH | 23,893 outliers, max diff 235 | 18.2s |
| 8 | `mask_reapply` | PASS | 36,156 outliers, max diff 204 | 19.3s |
| 9 | `bitmapdata_applyfilter_colormatrix` | PASS | 45,000 outliers, max diff 62 | 17.1s |
| 10 | `edittext_stylesheet` | PASS | 53,001 outliers, max diff 255 | 20.6s |
| 11 | `netstream_play_flv` | OUTPUT_MISMATCH | 57,444 outliers, max diff 255 | 18.2s |
| 12 | `mask_with_drawing` | PASS | 60,000 outliers, max diff 255 | 17.4s |
| 13 | `color` | PASS | 70,000 outliers, max diff 91 | 16.6s |
| 14 | `bitmap_data_colortransform` | PASS | 78,561 outliers, max diff 255 | 20.6s |
| 15 | `movieclip_line_gradient_style` | PASS | 103,017 outliers, max diff 255 | 19.9s |
| 16 | `movieclip_setmask` | PASS | 171,580 outliers, max diff 255 | 18.5s |
| 17 | `bitmap_data_pixeldissolve_image` | PASS | 172,347 outliers, max diff 255 | 22.3s |
| 18 | `mouse_events_visible_enabled` | PASS | 287,006 outliers, max diff 204 | 18.0s |
| 19 | `mcl_target_gif87a` | PASS | 339,493 outliers, max diff 255 | 17.5s |
| 20 | `mcl_target_gif89a` | PASS | 339,493 outliers, max diff 255 | 17.2s |
| 21 | `movieclip_begin_gradient_fill` | PASS | 359,629 outliers, max diff 255 | 18.3s |
| 22 | `mcl_target_png` | PASS | 424,993 outliers, max diff 255 | 17.5s |
| 23 | `mcl_target_jpg` | PASS | 427,503 outliers, max diff 255 | 19.3s |
| 24 | `bitmap_data_copypixels` | OUTPUT_MISMATCH | 480,000 outliers, max diff 255 | 22.2s |
| 25 | `bitmap_data_perlinnoise` | PASS | 875,000 outliers, max diff 255 | 20.9s |

## Tests That Could Not Render

**1 tests** failed before image comparison (build or runtime error)

| # | Test | Status | Duration |
|---|------|--------|----------|
| 1 | `netstream_play_flv_screen` | segfault | 40.4s |
