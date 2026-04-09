# Ruffle Test Results Diff

**Previous:** `2a4adfc3fdc2` (2026-04-09T00:00:08.182333+00:00)
**Current:** `9d4d8742948b` (2026-04-09T01:53:01.641202+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 578 | 575 | -3 |
| Total | 620 | 620 | 0 |
| Pass rate | 93.2% | 92.7% | -0.5% |
| Mismatched lines | 9015 | 8926 | -89 |
|   Decreased | | | -109 |
|   Increased | | | +20 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `equals_swf4` | output_mismatch | 598/665 | 665/665 |
| `lessthan_swf4` | output_mismatch | 860/902 | 902/902 |

## Newly Failing (5)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `is_finite` | output_mismatch | 49/49 | 48/49 |
| `is_finite_swf6` | output_mismatch | 49/49 | 48/49 |
| `swf5_global_funcs` | output_mismatch | 232/232 | 226/232 |
| `swf6_global_funcs` | output_mismatch | 232/232 | 226/232 |
| `swf7_global_funcs` | output_mismatch | 232/232 | 226/232 |
