# Ruffle Test Results Diff

**Previous:** `92ed03014a88` (2026-02-21T18:39:47.295862+00:00)
**Current:** `b4ded4676116` (2026-02-21T21:31:13.744903+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 267 | 260 | -7 |
| Total | 619 | 619 | 0 |
| Pass rate | 43.1% | 42.0% | -1.1% |
| Mismatched lines | 39009 | 39167 | +158 |
|   Decreased | | | -2 |
|   Increased | | | +160 |

## Newly Failing (7)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `array_concat` | output_mismatch | 98/98 | 87/98 |
| `array_constructor` | output_mismatch | 30/30 | 28/30 |
| `set_variable_scope` | output_mismatch | 58/58 | 49/58 |
| `this_swf7` | output_mismatch | 41/41 | 40/41 |
| `waitforframe` | output_mismatch | 7/7 | 1/7 |
| `waitforframe2` | output_mismatch | 16/16 | 1/16 |
| `with_variable_scopes` | output_mismatch | 43/43 | 4/43 |

## Line Count Changed (6)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `define_local_with_paths` | output_mismatch | 19/54 | 21/54 | -2 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `this_swf5` | output_mismatch | 24/41 | 23/41 | +1 |
| `this_swf6` | output_mismatch | 18/41 | 17/41 | +1 |
| `this_scoping` | output_mismatch | 42/52 | 6/52 | +36 |
| `with` | output_mismatch | 47/49 | 8/49 | +39 |
