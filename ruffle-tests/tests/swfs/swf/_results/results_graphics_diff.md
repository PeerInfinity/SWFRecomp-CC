# Ruffle Test Results Diff

**Previous:** `bf585e4486b6` (2026-08-12T23:11:20.706118+00:00)
**Current:** `16314e63feaa` (2026-08-13T21:54:57.546379+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 4 | 0 | -4 |
| Total | 5 | 5 | 0 |
| Pass rate | 80.0% | 0.0% | -80.0% |
| Mismatched lines | 6 | 0 | -6 |
|   Decreased | | | -6 |

## Newly Failing (4)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `convolution_filter_big_matrix` | compile_fail | 2/2 | - |
| `swf_length_too_short_no_end` | compile_fail | 19/19 | - |
| `swf_length_too_short_no_second_frame` | compile_fail | 18/18 | - |
| `swf_length_zero` | compile_fail | 0/0 | - |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `swf_length_too_long` | ruffle_matched | compile_fail | 12/18 | - |
