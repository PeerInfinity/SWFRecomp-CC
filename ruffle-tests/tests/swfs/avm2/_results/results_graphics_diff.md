# Ruffle Test Results Diff

**Previous:** `1884c6ab93fe` (2026-07-26T03:36:27.347082+00:00)
**Current:** `add3e60cef2f` (2026-07-26T19:38:35.168426+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 842 | 843 | +1 |
| Total | 1218 | 1221 | +3 |
| Pass rate | 69.1% | 69.0% | -0.1% |
| Mismatched lines | 47149 | 47194 | +45 |
|   Increased | | | +5 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `edittext_align` | segfault | 60/60 | 60/60 |

## Added Tests (3)

| Test | Status | Lines |
|------|--------|-------|
| `displayobject_getrect` | output_mismatch | 2/16 |
| `system_exit` | output_mismatch | 0/3 |
| `textblock_createline_errors` | output_mismatch | 0/23 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `textblock_createline_fte` | output_mismatch | 0/4 | 0/9 | +5 |
