# Ruffle Test Results Diff

**Previous:** `bbe171d20f4f` (2026-04-03T16:55:51.986948+00:00)
**Current:** `dc2748b675fb` (2026-04-03T22:14:41.104488+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 572 | 570 | -2 |
| Total | 620 | 620 | 0 |
| Pass rate | 92.3% | 91.9% | -0.4% |
| Mismatched lines | 10149 | 10283 | +134 |
|   Decreased | | | -1 |
|   Increased | | | +135 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `native_objects_swf7` | output_mismatch | 84/84 | 105/115 |
| `native_objects_swf8` | output_mismatch | 84/84 | 103/115 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `native_objects_swf6` | output_mismatch | segfault | 83/84 | 1/115 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `movieclip_hittest_shapeflag` | output_mismatch | 325/338 | 326/338 | -1 |
