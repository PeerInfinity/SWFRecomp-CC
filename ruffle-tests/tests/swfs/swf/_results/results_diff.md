# Ruffle Test Results Diff

**Previous:** `f55511379655` (2026-10-18T08:49:49.722710+00:00)
**Current:** `344c85a166c3` (2026-10-25T08:41:41.563388+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 5 | 0 | -5 |
| Total | 7 | 7 | 0 |
| Pass rate | 71.4% | 0.0% | -71.4% |
| Mismatched lines | 16 | 0 | -16 |
|   Decreased | | | -16 |

## Newly Failing (5)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `convolution_filter_big_matrix` | compile_fail | 2/2 | - |
| `lzma_length_too_short` | compile_fail | 18/18 | - |
| `swf_length_too_short_no_end` | compile_fail | 19/19 | - |
| `swf_length_too_short_no_second_frame` | compile_fail | 18/18 | - |
| `swf_length_zero` | compile_fail | 0/0 | - |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `lzma_length_too_long` | ruffle_matched | compile_fail | 9/19 | - |
| `swf_length_too_long` | ruffle_matched | compile_fail | 12/18 | - |
