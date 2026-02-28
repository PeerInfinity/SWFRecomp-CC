# Ruffle Test Results Diff

**Previous:** `e9ba1a00e14d` (2026-02-28T02:32:32.470911+00:00)
**Current:** `afdc8bfb7512` (2026-02-28T03:42:01.317758+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 398 | 397 | -1 |
| Total | 619 | 619 | 0 |
| Pass rate | 64.3% | 64.1% | -0.2% |
| Mismatched lines | 31388 | 31384 | -4 |
|   Decreased | | | -9 |
|   Increased | | | +5 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `movieclip_default_state` | output_mismatch | 69/69 | 68/69 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_library_state_values` | segfault | output_mismatch | 68/78 | 77/78 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `mcl_events_swf_version` | output_mismatch | 32/232 | 28/232 | +4 |
