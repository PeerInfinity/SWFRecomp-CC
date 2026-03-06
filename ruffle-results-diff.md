# Ruffle Test Results Diff

**Previous:** `ea1732c5c720` (2026-03-06T22:26:29.093400+00:00)
**Current:** `e2ad847e57dd` (2026-03-06T23:19:39.955202+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 488 | 490 | +2 |
| Total | 619 | 619 | 0 |
| Pass rate | 78.8% | 79.2% | +0.4% |
| Mismatched lines | 20012 | 19805 | -207 |
|   Decreased | | | -207 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `loadmovie_var_persistence` | output_mismatch | 5/8 | 8/8 |
| `mcl_events_swf_version` | output_mismatch | 37/232 | 232/232 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_invalid_get_bounds_1` | output_mismatch | runtime_error | 4/75 | 5/75 |
| `movieclip_invalid_get_bounds_2` | output_mismatch | runtime_error | 5/75 | 7/75 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `register_class` | output_mismatch | 38/66 | 44/66 | -6 |
