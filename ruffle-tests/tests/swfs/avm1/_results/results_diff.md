# Ruffle Test Results Diff

**Previous:** `8a50e569da3e` (2026-04-18T00:16:44.588410+00:00)
**Current:** `850c9d648c56` (2026-04-18T01:09:29.654049+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 593 | 595 | +2 |
| Total | 641 | 641 | 0 |
| Pass rate | 92.5% | 92.8% | +0.3% |
| Mismatched lines | 15483 | 15247 | -236 |
|   Decreased | | | -252 |
|   Increased | | | +16 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bitmap_data_thorough/noise` | output_mismatch | 1426/1518 | 1518/1518 |
| `bitmap_data_thorough/threshold` | output_mismatch | 1222/1308 | 1308/1308 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `bitmap_data_thorough/paletteMap` | output_mismatch | ruffle_matched | 899/951 | 883/951 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `bitmap_data_thorough/pixelDissolve` | output_mismatch | 1259/1371 | 1333/1371 | -74 |
