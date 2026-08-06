# Ruffle Test Results Diff

**Previous:** `72fdc5e933a6` (2026-07-29T03:45:41.174488+00:00)
**Current:** `b4c983ea4c3d` (2026-08-02T09:26:35.729900+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 168 | 186 | +18 |
| Total | 229 | 229 | 0 |
| Pass rate | 73.4% | 81.2% | +7.8% |
| Mismatched lines | 863 | 702 | -161 |
|   Decreased | | | -161 |

## Newly Passing (18)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `acid/acid-filter` | output_mismatch | 0/2 | 2/2 |
| `acid/acid-text-2` | output_mismatch | 0/1 | 1/1 |
| `avm2/flash/geom/matrix3d/Matrix3DClass` | output_mismatch | 0/56 | 56/56 |
| `blendmode/blendmode_1` | output_mismatch | 1/2 | 2/2 |
| `blendmode/blendmode_2` | output_mismatch | 2/4 | 4/4 |
| `flash_net_URLLoader` | output_mismatch | 0/7 | 7/7 |
| `hittesting/hittesting` | output_mismatch | 9/18 | 18/18 |
| `localconnection` | output_mismatch | 3/12 | 12/12 |
| `stream1` | output_mismatch | 0/9 | 9/9 |
| `stroke1` | output_mismatch | 0/1 | 1/1 |
| `timeline/nav/blendMode` | output_mismatch | 6/8 | 8/8 |
| `timeline/nav/cacheAsBitmap` | output_mismatch | 6/8 | 8/8 |
| `timeline/nav/colorTransform` | output_mismatch | 6/8 | 8/8 |
| `timeline/nav/filters` | output_mismatch | 6/8 | 8/8 |
| `timeline/nav/matrix` | output_mismatch | 7/8 | 8/8 |
| `timeline/nav/morphShape` | output_mismatch | 3/4 | 4/4 |
| `timeline/nav/ratio` | output_mismatch | 3/4 | 4/4 |
| `timeline/nav/ratio2` | output_mismatch | 3/4 | 4/4 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `getobjectsunderpoint` | output_mismatch | ruffle_matched | 1/34 | 29/34 |
| `timeline/nav/clipDepth` | output_mismatch | ruffle_matched | 1/8 | 4/8 |

## Line Count Changed (6)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | output_mismatch | 0/20 | 16/20 | -16 |
| `avm2/flash/geom/matrix3d/TransformBasics` | output_mismatch | 2/13 | 5/13 | -3 |
| `avm1movie` | ruffle_matched | 4/13 | 5/13 | -1 |
| `bitmapdata/getpixel-from-embedded` | output_mismatch | 0/2 | 1/2 | -1 |
| `acid/acid-shapes` | output_mismatch | 0/120 | 0/120 | 0 |
| `esc` | output_mismatch | 0/2 | 0/2 | 0 |
