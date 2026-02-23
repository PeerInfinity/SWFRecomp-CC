# Ruffle Test Results Diff

**Previous:** `f2aaa7b36366` (2026-02-23T19:00:12.937520+00:00)
**Current:** `f2819cb89a25` (2026-02-23T21:28:27.444647+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 314 | 315 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 50.7% | 50.9% | +0.2% |
| Mismatched lines | 34734 | 34711 | -23 |
|   Decreased | | | -46 |
|   Increased | | | +23 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `hittest_lockroot` | output_mismatch | 7/15 | 15/15 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `hittest_morph` | output_mismatch | 29/70 | 67/70 | -38 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `movieclip_hittest_shapeflag` | output_mismatch | 276/338 | 253/338 | +23 |
