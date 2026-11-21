# Ruffle Test Results Diff

**Previous:** `344c85a166c3` (2026-11-15T08:31:27.879050+00:00)
**Current:** `08709f65842a` (2026-11-21T17:00:08.540400+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 0 | 5 | +5 |
| Total | 7 | 7 | 0 |
| Pass rate | 0.0% | 71.4% | +71.4% |
| Mismatched lines | 0 | 16 | +16 |
|   Increased | | | +16 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `convolution_filter_big_matrix` | compile_fail | - | 2/2 |
| `lzma_length_too_short` | compile_fail | - | 18/18 |
| `swf_length_too_short_no_end` | compile_fail | - | 19/19 |
| `swf_length_too_short_no_second_frame` | compile_fail | - | 18/18 |
| `swf_length_zero` | compile_fail | - | 0/0 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `lzma_length_too_long` | compile_fail | ruffle_matched | - | 9/19 |
| `swf_length_too_long` | compile_fail | ruffle_matched | - | 12/18 |
