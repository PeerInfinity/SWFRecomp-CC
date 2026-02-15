# Ruffle Test Results Diff

**Previous:** `b4d13aa35610` (2026-02-15T22:16:36.557052+00:00)
**Current:** `51c59eed98f8` (2026-02-15T23:08:23.733607+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 205 | 206 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 33.1% | 33.3% | +0.2% |
| Mismatched lines | 45776 | 45686 | -90 |
|   Decreased | | | -92 |
|   Increased | | | +2 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `with_variable_scopes` | output_mismatch | 24/43 | 43/43 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `try_catch_finally` | segfault | timeout | 49/118 | - |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `with` | output_mismatch | 30/49 | 34/49 | -4 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `this_scoping` | output_mismatch | 2/52 | 2/52 | 0 |
| `define_local_with_paths` | output_mismatch | 21/54 | 19/54 | +2 |
