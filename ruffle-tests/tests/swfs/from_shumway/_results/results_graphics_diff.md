# Ruffle Test Results Diff

**Previous:** `2358a37b1cc0` (2026-07-30T18:36:08.375067+00:00)
**Current:** `ff7151c15004` (2026-07-30T22:08:16.493517+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 173 | 183 | +10 |
| Total | 229 | 229 | 0 |
| Pass rate | 75.5% | 79.9% | +4.4% |
| Mismatched lines | 764 | 727 | -37 |
|   Decreased | | | -37 |

## Newly Passing (10)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `blendmode/blendmode_1` | output_mismatch | 1/2 | 2/2 |
| `blendmode/blendmode_2` | output_mismatch | 2/4 | 4/4 |
| `stroke1` | output_mismatch | 0/1 | 1/1 |
| `timeline/nav/blendMode` | output_mismatch | 6/8 | 8/8 |
| `timeline/nav/cacheAsBitmap` | output_mismatch | 6/8 | 8/8 |
| `timeline/nav/colorTransform` | output_mismatch | 6/8 | 8/8 |
| `timeline/nav/matrix` | output_mismatch | 7/8 | 8/8 |
| `timeline/nav/morphShape` | output_mismatch | 3/4 | 4/4 |
| `timeline/nav/ratio` | output_mismatch | 3/4 | 4/4 |
| `timeline/nav/ratio2` | output_mismatch | 3/4 | 4/4 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `timeline/nav/clipDepth` | output_mismatch | ruffle_matched | 1/8 | 4/8 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `getobjectsunderpoint` | output_mismatch | 1/34 | 12/34 | -11 |
| `hittesting/hittesting` | output_mismatch | 9/18 | 16/18 | -7 |
| `avm1movie` | ruffle_matched | 4/13 | 5/13 | -1 |
| `bitmapdata/getpixel-from-embedded` | output_mismatch | 0/2 | 1/2 | -1 |
