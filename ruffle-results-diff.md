# Ruffle Test Results Diff

**Previous:** `57a202fae32d` (2026-02-18T02:39:41.160579+00:00)
**Current:** `81cf2020fa85` (2026-02-18T03:10:18.342153+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 214 | 218 | +4 |
| Total | 619 | 619 | 0 |
| Pass rate | 34.6% | 35.2% | +0.6% |
| Mismatched lines | 43021 | 43004 | -17 |
|   Decreased | | | -17 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `equals2_swf5` | output_mismatch | 921/926 | 926/926 |
| `equals2_swf6` | output_mismatch | 921/926 | 926/926 |
| `equals2_swf7` | output_mismatch | 921/926 | 926/926 |
| `global_is_bare` | output_mismatch | 6/7 | 7/7 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `array_sort` | output_mismatch | 118/161 | 119/161 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
