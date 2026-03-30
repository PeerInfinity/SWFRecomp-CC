# copyPixels Alpha Bitmap Path Plan
<!-- TESTS: bitmap_data_copypixels (image) -->

<!-- PLAN_META
id: COPYPIXELS_ALPHA
status: in_progress
phases:
  - id: 1
    name: "Implement copyPixels alpha bitmap path"
    status: complete
  - id: 2
    name: "Implement merge() method"
    status: complete
  - id: 3
    name: "Fix remaining rendering issues"
    status: in_progress
dependencies: []
blockers: []
-->

Last updated: 2026-03-29

## Status: IN PROGRESS — Alpha path + merge() implemented, 188K outliers remain

### Progress (2026-03-29)

**Implemented:**
- copyPixels alpha bitmap path: 6-argument form with alpha bitmap modulation. Source pixels have their premultiplied alpha/RGB scaled by the alpha bitmap's alpha channel.
- merge() method: Per-channel weighted blend `(src * mult + dest * (256 - mult)) / 256` in unpremultiplied space.

**Results:**
- Image outliers: 190,726 → 188,581 (small improvement)
- Expected row 3-4 bitmaps partially rendering, but still significant mismatches

### Remaining Issues

The small improvement suggests the main rendering gap is NOT just the alpha bitmap path. The issue may be:
1. Missing rows in the output suggest some test flow paths aren't executing
2. Black areas in rendered bitmaps may indicate premultiplied alpha rendering issues
3. The test may use additional BitmapData features beyond copyPixels/merge

### Key Code Locations

| Component | File | Description |
|-----------|------|-------------|
| copyPixels alpha path | `action.c:bitmapDataCopyPixels` | 6-arg form with alpha bitmap |
| merge() | `action.c:bitmapDataMerge` | Per-channel weighted blend |
