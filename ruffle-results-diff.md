# Ruffle Test Results Diff

**Previous:** `906fab0ddf93` (2026-02-23T17:44:55.577948+00:00)
**Current:** `f2aaa7b36366` (2026-02-23T19:00:12.937520+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 313 | 314 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 50.6% | 50.7% | +0.1% |
| Mismatched lines | 34877 | 34734 | -143 |
|   Decreased | | | -148 |
|   Increased | | | +5 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `clip_events` | output_mismatch | 1/19 | 19/19 |
| `movieclip_hittest` | output_mismatch | 71/92 | 92/92 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `issue_1104` | output_mismatch | 2/2 | 1/2 |

## Line Count Changed (7)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `movieclip_hittest_shapeflag` | output_mismatch | 193/338 | 276/338 | -83 |
| `hittest_morph` | output_mismatch | 15/70 | 29/70 | -14 |
| `on_construct` | output_mismatch | 0/25 | 9/25 | -9 |
| `hittest_winding_rule` | output_mismatch | 6/12 | 9/12 | -3 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `movieclip_in_removed_button` | output_mismatch | 1/4 | 1/4 | 0 |
| `string_paths_variable_scopes` | output_mismatch | 4/5 | 0/5 | +4 |
