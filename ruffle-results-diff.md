# Ruffle Test Results Diff

**Previous:** `fc96eb5ca495` (2026-02-27T01:40:24.575105+00:00)
**Current:** `a4be5eedce2d` (2026-02-27T01:51:02.812440+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 384 | 386 | +2 |
| Total | 619 | 619 | 0 |
| Pass rate | 62.0% | 62.4% | +0.4% |
| Mismatched lines | 31662 | 31564 | -98 |
|   Decreased | | | -98 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `edittext_antialiastype` | output_mismatch | 274/296 | 296/296 |
| `edittext_password` | output_mismatch | 3/5 | 5/5 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | output_mismatch | compile_fail | 266/338 | - |
| `resolve_different_root` | output_mismatch | segfault | 0/2 | - |
