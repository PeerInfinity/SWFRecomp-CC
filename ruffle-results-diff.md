# Ruffle Test Results Diff

**Previous:** `ebdc0601bed5` (2026-02-22T21:02:54.246670+00:00)
**Current:** `5cc8b9b38579` (2026-02-22T21:09:10.555536+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 284 | 285 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 45.9% | 46.0% | +0.1% |
| Mismatched lines | 36585 | 36582 | -3 |
|   Decreased | | | -5 |
|   Increased | | | +2 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `closure_scope` | output_mismatch | 2/7 | 7/7 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `native_objects_swf6` | segfault | 0/84 | 0/84 | 0 |
| `native_objects_swf7` | segfault | 0/84 | 0/84 | 0 |
| `native_objects_swf8` | segfault | 0/84 | 0/84 | 0 |
| `swf5_no_closure` | output_mismatch | 8/19 | 6/19 | +2 |
