# Ruffle Test Results Diff

**Previous:** `d482f825a729` (2026-02-13T02:01:43.150910+00:00)
**Current:** `ef611bfba5d6` (2026-02-13T02:28:55.884855+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 112 | 113 | +1 |
| Total | 616 | 616 | 0 |
| Pass rate | 18.2% | 18.3% | +0.1% |
| Mismatched lines | 57076 | 57071 | -5 |
|   Decreased | | | -7 |
|   Increased | | | +2 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `execution_order3` | output_mismatch | 3/4 | 4/4 |

## Line Count Changed (7)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `rewind_depth` | output_mismatch | 6/30 | 9/30 | -3 |
| `execution_order2` | output_mismatch | 2/7 | 3/7 | -1 |
| `goto_frame_number` | output_mismatch | 1/3 | 2/3 | -1 |
| `target_clip_removed` | output_mismatch | 0/5 | 1/5 | -1 |
| `removed_base_clip_tell_target` | output_mismatch | 0/2 | 0/2 | 0 |
| `tell_target_invalid` | output_mismatch | 1/6 | 0/6 | +1 |
| `tell_target_invalid_swf6` | output_mismatch | 1/5 | 0/5 | +1 |
