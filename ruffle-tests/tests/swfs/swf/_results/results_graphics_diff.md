# Ruffle Test Results Diff

**Previous:** `16314e63feaa` (2026-08-13T21:54:57.546379+00:00)
**Current:** `3db858cbc157` (2026-08-13T22:38:36.701961+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 0 | 4 | +4 |
| Total | 5 | 5 | 0 |
| Pass rate | 0.0% | 80.0% | +80.0% |
| Mismatched lines | 0 | 6 | +6 |
|   Increased | | | +6 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `convolution_filter_big_matrix` | compile_fail | - | 2/2 |
| `swf_length_too_short_no_end` | compile_fail | - | 19/19 |
| `swf_length_too_short_no_second_frame` | compile_fail | - | 18/18 |
| `swf_length_zero` | compile_fail | - | 0/0 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `swf_length_too_long` | compile_fail | ruffle_matched | - | 12/18 |
