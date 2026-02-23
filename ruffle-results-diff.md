# Ruffle Test Results Diff

**Previous:** `6ad82ff6d097` (2026-02-23T07:17:53.295949+00:00)
**Current:** `906fab0ddf93` (2026-02-23T17:44:55.577948+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 312 | 313 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 50.4% | 50.6% | +0.2% |
| Mismatched lines | 34893 | 34877 | -16 |
|   Decreased | | | -16 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `movieclip_default_state` | output_mismatch | 61/69 | 69/69 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `movieclip_library_state_values` | runtime_error | 60/78 | 68/78 | -8 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
