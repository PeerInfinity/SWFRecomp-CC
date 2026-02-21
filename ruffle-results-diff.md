# Ruffle Test Results Diff

**Previous:** `139ab34eb4c8` (2026-02-21T06:56:36.006131+00:00)
**Current:** `937b361e7c32` (2026-02-21T17:48:46.699973+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 266 | 267 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 43.0% | 43.1% | +0.1% |
| Mismatched lines | 39011 | 39009 | -2 |
|   Decreased | | | -3 |
|   Increased | | | +1 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `goto_execution_order` | output_mismatch | 1/2 | 2/2 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `issue_2870` | output_mismatch | 1/3 | 2/3 | -1 |
| `tell_target_invalid_swf6` | output_mismatch | 0/5 | 1/5 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `default_names` | output_mismatch | 16/52 | 15/52 | +1 |
