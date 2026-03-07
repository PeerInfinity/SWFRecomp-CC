# Ruffle Test Results Diff

**Previous:** `e2ad847e57dd` (2026-03-06T23:19:39.955202+00:00)
**Current:** `b1b89de37dae` (2026-03-07T00:21:15.393591+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 490 | 488 | -2 |
| Total | 619 | 619 | 0 |
| Pass rate | 79.2% | 78.8% | -0.4% |
| Mismatched lines | 19805 | 19777 | -28 |
|   Decreased | | | -35 |
|   Increased | | | +7 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `define_local` | output_mismatch | 2/27 | 27/27 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `issue_768` | output_mismatch | 3/3 | 0/3 |
| `stage_object_children` | output_mismatch | 83/83 | 81/83 |
| `with_variable_scopes` | output_mismatch | 43/43 | 41/43 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `movieclip_setmask` | output_mismatch | 2/14 | 12/14 | -10 |
