# Ruffle Test Results Diff

**Previous:** `d3c5020af4e2` (2026-03-05T04:15:19.402342+00:00)
**Current:** `168c0745d949` (2026-03-05T05:08:47.601436+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 457 | 460 | +3 |
| Total | 619 | 619 | 0 |
| Pass rate | 73.8% | 74.3% | +0.5% |
| Mismatched lines | 21389 | 21544 | +155 |
|   Decreased | | | -63 |
|   Increased | | | +218 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `asnative` | output_mismatch | 19/34 | 34/34 |
| `asnew` | output_mismatch | 10/34 | 34/34 |
| `object_resolve` | output_mismatch | 14/38 | 38/38 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `bitmap_filters` | output_mismatch | segfault | 279/548 | 61/548 |
