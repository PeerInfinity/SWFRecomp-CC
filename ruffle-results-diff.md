# Ruffle Test Results Diff

**Previous:** `a61990a30d3f` (2026-02-22T02:42:13.840627+00:00)
**Current:** `a0a16211fa02` (2026-02-22T03:51:45.302393+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 275 | 279 | +4 |
| Total | 619 | 619 | 0 |
| Pass rate | 44.4% | 45.1% | +0.7% |
| Mismatched lines | 36823 | 36814 | -9 |
|   Decreased | | | -9 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `array_sort` | output_mismatch | 158/161 | 161/161 |
| `issue_1906` | output_mismatch | 2/4 | 4/4 |
| `string_paths_basic` | output_mismatch | 2/4 | 4/4 |
| `string_paths_variable_alias` | output_mismatch | 2/4 | 4/4 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
