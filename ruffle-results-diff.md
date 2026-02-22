# Ruffle Test Results Diff

**Previous:** `b4ded4676116` (2026-02-21T21:31:13.744903+00:00)
**Current:** `4d432e56f8e7` (2026-02-21T22:19:01.983226+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 260 | 267 | +7 |
| Total | 619 | 619 | 0 |
| Pass rate | 42.0% | 43.1% | +1.1% |
| Mismatched lines | 39167 | 39009 | -158 |
|   Decreased | | | -160 |
|   Increased | | | +2 |

## Newly Passing (7)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `array_concat` | output_mismatch | 87/98 | 98/98 |
| `array_constructor` | output_mismatch | 28/30 | 30/30 |
| `set_variable_scope` | output_mismatch | 49/58 | 58/58 |
| `this_swf7` | output_mismatch | 40/41 | 41/41 |
| `waitforframe` | output_mismatch | 1/7 | 7/7 |
| `waitforframe2` | output_mismatch | 1/16 | 16/16 |
| `with_variable_scopes` | output_mismatch | 4/43 | 43/43 |

## Line Count Changed (6)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `with` | output_mismatch | 8/49 | 47/49 | -39 |
| `this_scoping` | output_mismatch | 6/52 | 42/52 | -36 |
| `this_swf5` | output_mismatch | 23/41 | 24/41 | -1 |
| `this_swf6` | output_mismatch | 17/41 | 18/41 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `define_local_with_paths` | output_mismatch | 21/54 | 19/54 | +2 |
