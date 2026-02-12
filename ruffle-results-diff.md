# Ruffle Test Results Diff

**Previous:** `f245517a7d2a` (2026-02-12T17:23:50.449896+00:00)
**Current:** `89513b9d2880` (2026-02-12T18:43:05.339640+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 82 | 85 | +3 |
| Total | 616 | 616 | 0 |
| Pass rate | 13.3% | 13.8% | +0.5% |
| Mismatched lines | 56616 | 57241 | +625 |
|   Decreased | | | -15 |
|   Increased | | | +640 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as1_constructor_v7` | output_mismatch | 30/35 | 35/35 |
| `has_own_property` | output_mismatch | 28/32 | 32/32 |
| `object_function` | output_mismatch | 29/32 | 32/32 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `netstream_play_flv_screen` | segfault | compile_fail | - | - |

## Line Count Changed (10)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `as1_constructor_v6` | output_mismatch | 27/35 | 30/35 | -3 |
| `uncaught_exception` | runtime_error | - | 0/1 | +1 |
| `uncaught_exception_bubbled` | runtime_error | - | 0/1 | +1 |
| `duplicate_movie_clip_drawing` | segfault | - | 0/2 | +2 |
| `array_constructor` | segfault | - | 12/30 | +18 |
| `array_length` | runtime_error | - | 13/42 | +29 |
| `enumerate` | segfault | - | 1/64 | +63 |
| `device_font_spacing` | segfault | - | 0/91 | +91 |
| `swf4_actions_coercion_order` | segfault | - | 9/158 | +149 |
| `path_string` | segfault | - | 36/322 | +286 |
