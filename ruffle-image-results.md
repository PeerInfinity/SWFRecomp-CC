# Ruffle AVM1 Image Comparison Test Results

**Date**: 2026-03-09 19:36 UTC
**Git SHA**: `c10e2a7456`
**Run Duration**: 9m 60s

## Summary

| Metric | Value |
|--------|-------|
| Total image tests | 31 |
| Strict image pass (exact pixel match) | **7** (23%) |
| Tolerance pass (within test.toml limits) | **9** (29%) |
| Image failing | 21 |
| No render (build/runtime fail) | 1 |
| Trace output passing | 23 (74%) |

## Strict Passing Image Tests (exact pixel match)

**7 tests** with 0 outliers across all image comparisons

| # | Test | Trace | Duration |
|---|------|-------|----------|
| 1 | `focusrect_focuslost` | PASS | 17.6s |
| 2 | `focusrect_mouse_swf8` | OUTPUT_MISMATCH | 18.2s |
| 3 | `focusrect_mouse_swf9` | OUTPUT_MISMATCH | 19.6s |
| 4 | `focusrect_swf6` | OUTPUT_MISMATCH | 18.8s |
| 5 | `frame_size_translated_negative` | PASS | 18.1s |
| 6 | `frame_size_translated_positive` | PASS | 17.7s |
| 7 | `mask_with_drawing` | PASS | 18.2s |

## Tolerance-Only Passing (non-zero outliers within test.toml limits)

**2 tests** pass within configured tolerance but have image differences

| # | Test | Trace | Outliers | Max Diff | Duration |
|---|------|-------|---------|----------|----------|
| 1 | `display_object_properties` | PASS | 0 | 79 | 18.2s |
| 2 | `mask_reapply` | PASS | 0 | 1 | 18.5s |

## Failing Image Tests

**21 tests** with image comparison failures (sorted by outlier count, closest to passing first)

| # | Test | Trace | Image Result | Duration |
|---|------|-------|-------------|----------|
| 1 | `focusrect_swf5` | OUTPUT_MISMATCH | 10/12 pass (2 fail: 408 outliers each) | 18.4s |
| 2 | `mouse_events_visible_enabled` | PASS | 3,614 outliers, max diff 102 | 19.8s |
| 3 | `bitmap_data_fillrect` | PASS | 3,914 outliers, max diff 255 | 18.3s |
| 4 | `edittext_tag_indent` | PASS | 6,336 outliers, max diff 255 | 18.1s |
| 5 | `movieclip_setmask` | PASS | 10,096 outliers, max diff 255 | 19.2s |
| 6 | `movieclip_create_text_field` | PASS | 15,000 outliers, max diff 255 | 18.6s |
| 7 | `movieclip_methods_with_loaded_image` | OUTPUT_MISMATCH | 23,893 outliers, max diff 235 | 18.2s |
| 8 | `color` | PASS | 30,000 outliers, max diff 48 | 18.3s |
| 9 | `edittext_stylesheet` | PASS | 33,126 outliers, max diff 255 | 19.3s |
| 10 | `bitmapdata_applyfilter_colormatrix` | PASS | 45,000 outliers, max diff 62 | 19.5s |
| 11 | `movieclip_line_gradient_style` | PASS | 54,311 outliers, max diff 255 | 19.6s |
| 12 | `netstream_play_flv` | OUTPUT_MISMATCH | 57,444 outliers, max diff 255 | 19.7s |
| 13 | `bitmap_data_colortransform` | PASS | 78,561 outliers, max diff 255 | 18.0s |
| 14 | `movieclip_begin_gradient_fill` | PASS | 134,883 outliers, max diff 255 | 19.3s |
| 15 | `bitmap_data_pixeldissolve_image` | PASS | 172,347 outliers, max diff 255 | 18.9s |
| 16 | `mcl_target_gif87a` | PASS | 339,493 outliers, max diff 255 | 19.6s |
| 17 | `mcl_target_gif89a` | PASS | 339,493 outliers, max diff 255 | 19.0s |
| 18 | `mcl_target_png` | PASS | 424,993 outliers, max diff 255 | 18.9s |
| 19 | `mcl_target_jpg` | PASS | 427,503 outliers, max diff 255 | 18.7s |
| 20 | `bitmap_data_copypixels` | OUTPUT_MISMATCH | 480,000 outliers, max diff 255 | 19.6s |
| 21 | `bitmap_data_perlinnoise` | PASS | 875,000 outliers, max diff 255 | 21.2s |

## Tests That Could Not Render

**1 tests** failed before image comparison (build or runtime error)

| # | Test | Status | Duration |
|---|------|--------|----------|
| 1 | `netstream_play_flv_screen` | segfault | 34.7s |
