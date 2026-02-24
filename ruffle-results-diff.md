# Ruffle Test Results Diff

**Previous:** `3df670af59c1` (2026-02-24T03:39:33.391395+00:00)
**Current:** `04f4d9cbe00e` (2026-02-24T04:41:14.127238+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 324 | 325 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 52.3% | 52.5% | +0.2% |
| Mismatched lines | 34586 | 34603 | +17 |
|   Decreased | | | -1 |
|   Increased | | | +18 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `unloadmovie` | output_mismatch | 3/4 | 4/4 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_invalid_get_bounds_6` | compile_fail | output_mismatch | - | 1/10 |
| `movieclip_invalid_get_bounds_7` | compile_fail | output_mismatch | - | 1/10 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
