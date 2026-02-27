# Ruffle Test Results Diff

**Previous:** `fe29e8144528` (2026-02-27T21:24:14.008890+00:00)
**Current:** `0f54eedbd32b` (2026-02-27T22:40:47.686969+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 395 | 396 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 63.8% | 64.0% | +0.2% |
| Mismatched lines | 31555 | 31443 | -112 |
|   Decreased | | | -112 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `execution_order4` | output_mismatch | 8/12 | 12/12 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | output_mismatch | compile_fail | 266/338 | - |
| `resolve_different_root` | output_mismatch | segfault | 0/2 | - |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `this_scoping` | output_mismatch | 11/52 | 45/52 | -34 |
| `native_objects_swf6` | segfault | 0/84 | 0/84 | 0 |
| `native_objects_swf7` | segfault | 0/84 | 0/84 | 0 |
| `native_objects_swf8` | segfault | 0/84 | 0/84 | 0 |
