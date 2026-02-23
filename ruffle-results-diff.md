# Ruffle Test Results Diff

**Previous:** `feedc1a8893e` (2026-02-23T05:22:04.188666+00:00)
**Current:** `6ad82ff6d097` (2026-02-23T07:17:53.295949+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 313 | 312 | -1 |
| Total | 619 | 619 | 0 |
| Pass rate | 50.6% | 50.4% | -0.2% |
| Mismatched lines | 35013 | 34893 | -120 |
|   Decreased | | | -136 |
|   Increased | | | +16 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `movieclip_default_state` | output_mismatch | 69/69 | 61/69 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `movieclip_getbounds` | output_mismatch | 53/191 | 189/191 | -136 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `movieclip_library_state_values` | runtime_error | 68/78 | 60/78 | +8 |
