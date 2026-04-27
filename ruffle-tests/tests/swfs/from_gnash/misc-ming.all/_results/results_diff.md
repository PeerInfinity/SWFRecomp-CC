# Ruffle Test Results Diff

**Previous:** `8da7918f3edf` (2026-04-27T17:30:41.602149+00:00)
**Current:** `4b7c1fe00eab` (2026-04-27T20:37:25.083898+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 46 | 50 | +4 |
| Total | 102 | 102 | 0 |
| Pass rate | 45.1% | 49.0% | +3.9% |
| Mismatched lines | 2068 | 2038 | -30 |
|   Decreased | | | -30 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `BeginBitmapFill` | output_mismatch | 0/1 | 1/1 |
| `attachExtImported` | ruffle_matched | 1/2 | 2/2 |
| `attachImported` | output_mismatch | 1/2 | 2/2 |
| `attachMovieLoopingTest` | output_mismatch | 29/41 | 41/41 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `DefineTextTest` | output_mismatch | ruffle_matched | 11/16 | 12/16 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `displaylist_depths/displaylist_depths_test` | output_mismatch | 92/111 | 99/111 | -7 |
| `matrix_test` | output_mismatch | 912/1086 | 918/1086 | -6 |
| `EmbeddedFontTest` | output_mismatch | 50/87 | 51/87 | -1 |
