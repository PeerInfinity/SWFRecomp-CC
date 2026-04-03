# copyPixels Alpha Bitmap Path Plan
<!-- TESTS: bitmap_data_copypixels (image) -->

<!-- PLAN_META
id: COPYPIXELS_ALPHA
status: complete
phases:
  - id: 1
    name: "Implement copyPixels alpha bitmap path"
    status: complete
  - id: 2
    name: "Implement merge() method"
    status: complete
  - id: 3
    name: "Fix remaining rendering issues"
    status: complete
dependencies: []
blockers: []
-->

Last updated: 2026-04-03

## Status: COMPLETE — All phases done, trace 17/17 PASS, image pixel-perfect (0 outliers)

### Summary

All three phases completed:

1. **copyPixels alpha bitmap path** (Phase 1) — 6-argument form with alpha bitmap modulation. Source pixels have their premultiplied alpha/RGB scaled by the alpha bitmap's alpha channel.

2. **merge() method** (Phase 2) — Per-channel weighted blend `(src * mult + dest * (256 - mult)) / 256` in unpremultiplied space.

3. **Rendering fixes** (Phase 3) — Three fixes brought image test from 188K outliers to 0:
   - MAX_DYNAMIC_BITMAPS 32->64 (test needs ~48 texture layers)
   - copyPixels restructured with two-path logic: transparent alpha bitmap (OOB skip, modulation, blend when mergeAlpha||!dest_transparent) vs no-alpha/opaque-alpha (blend when src_transparent&&!dest_transparent || mergeAlpha)
   - Non-transparent alpha bitmaps ignored for alpha computation (matching Ruffle)

### Key Code Locations

| Component | File | Description |
|-----------|------|-------------|
| copyPixels alpha path | `action.c:bitmapDataCopyPixels` | 6-arg form with alpha bitmap |
| merge() | `action.c:bitmapDataMerge` | Per-channel weighted blend |
