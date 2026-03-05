# Ruffle Test Results Diff

**Previous:** `168c0745d949` (2026-03-05T05:08:47.601436+00:00)
**Current:** `f4fee517f7ef` (2026-03-05T06:42:05.741048+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 460 | 458 | -2 |
| Total | 619 | 619 | 0 |
| Pass rate | 74.3% | 74.0% | -0.3% |
| Mismatched lines | 21544 | 21731 | +187 |
|   Decreased | | | -5 |
|   Increased | | | +192 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `funky_function_calls` | output_mismatch | 52/56 | 56/56 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `math_swf6` | output_mismatch | 530/530 | 468/530 |
| `math_swf7` | output_mismatch | 530/530 | 465/530 |
| `math_swf8` | output_mismatch | 530/530 | 465/530 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `swf5_to_6_cross_call` | output_mismatch | 10/29 | 11/29 | -1 |
