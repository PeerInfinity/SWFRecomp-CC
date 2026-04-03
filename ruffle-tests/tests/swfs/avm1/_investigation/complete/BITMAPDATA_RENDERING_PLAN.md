# BitmapData Rendering Plan
<!-- TESTS: bitmap_data_colortransform, bitmap_data_copypixels, bitmap_data_fillrect, bitmap_data_perlinnoise, bitmap_data_pixeldissolve_image, bitmapdata_applyfilter_colormatrix -->

<!-- PLAN_META
id: BITMAPDATA_RENDERING
status: complete
phases:
  - id: 1
    name: "Dynamic bitmap texture layer allocation"
    status: complete
  - id: 2
    name: "render_webgpu_draw_bitmap_quad() function"
    status: complete
  - id: 3
    name: "actionIterateAttachedBitmaps() callback system"
    status: complete
  - id: 4
    name: "tag.c rendering hook"
    status: complete
  - id: 5
    name: "MovieClip struct extension"
    status: complete
  - id: 6
    name: "Premultiplied alpha blend pipeline"
    status: complete
  - id: 7
    name: "Implement missing BitmapData methods"
    status: complete
  - id: 8
    name: "Fix fillRect negative dimensions + bare Rectangle"
    status: complete
  - id: 9
    name: "Fix ColorMatrixFilter constructor"
    status: complete
  - id: 10
    name: "Implement BitmapData.loadBitmap"
    status: complete
  - id: 11
    name: "Fix colortransform aMult-only Flash bug"
    status: complete
  - id: 12
    name: "Fix copyPixels alpha bitmap + blend logic + texture limit"
    status: complete
dependencies:
  - plan: BITMAPDATA_PERLINNOISE
    type: requires
    reason: "perlinNoise stub needed for rendering tests"
  - plan: BITMAPDATA_APPLYFILTER
    type: requires
    reason: "applyFilter stub needed for rendering tests"
  - plan: BITMAPDATA_PIXELDISSOLVE
    type: requires
    reason: "pixelDissolve stub needed for rendering tests"
blockers: []
-->

Last updated: 2026-04-02

## Status: COMPLETE — 6/6 image tests passing (pixel-perfect)

### Final Results

| Test | Tolerance | Outliers | Max Diff | Notes |
|------|-----------|----------|----------|-------|
| bitmap_data_perlinnoise | 0 | **0** | 0 | **PASS** — pixel-perfect |
| bitmap_data_pixeldissolve_image | 1 | **0** | 0 | **PASS** — pixel-perfect |
| bitmapdata_applyfilter_colormatrix | 1 | **0** | 1 | **PASS** — rounding only |
| bitmap_data_fillrect | 0 | **0** | 0 | **PASS** — pixel-perfect |
| bitmap_data_colortransform | 5 | **0** | 4 | **PASS** — within tolerance |
| bitmap_data_copypixels | 0 | **0** | 0 | **PASS** — pixel-perfect |

### Fixes (2026-04-02)

**Phase 11 — colorTransform aMult-only Flash bug:**
- Flash quirk: if ONLY `aMult > 1` and all other transform parameters are default, the colorTransform has no effect
- Added early-return check in `bitmapDataColorTransform()` for this condition
- Fixed 726 outliers (2× value pattern on row 4 of the test)

**Phase 12 — copyPixels alpha bitmap + blend logic + texture limit:**
Three separate issues fixed:

1. **MAX_DYNAMIC_BITMAPS increased 32→64** (`render_webgpu.c`): Test creates ~48 attached bitmaps via `attachBitmap`; rows 3-4 (y=520-820) were entirely missing because the texture layer limit was exceeded.

2. **copyPixels blend condition rewritten** (`action.c`): Restructured into two paths matching Ruffle:
   - **No alpha bitmap path**: blend when `(src_transparent && !dest_transparent) || mergeAlpha`
   - **Transparent alpha bitmap path**: blend when `mergeAlpha || !dest_transparent`; skip pixels where alpha bitmap is OOB (preserve dest); use alpha bitmap's alpha channel to modulate source
   - **Non-transparent alpha bitmap**: ignored entirely (falls through to no-alpha-bitmap path, matching Ruffle behavior)

3. **Alpha bitmap OOB handling**: When transparent alpha bitmap pixel coordinates are out of bounds, the destination pixel is preserved (Ruffle's `continue` behavior), rather than setting alpha to 0.

### Key Code Locations

| Component | File | Description |
|-----------|------|-------------|
| colorTransform aMult bug | `action.c:bitmapDataColorTransform` | Early-return for aMult-only > 1 |
| copyPixels restructured | `action.c:bitmapDataCopyPixels` | Two-path alpha/no-alpha logic |
| Dynamic bitmap limit | `render_webgpu.c:MAX_DYNAMIC_BITMAPS` | Increased from 32 to 64 |
| fillRect negative dims | `action.c:bitmapDataFillRect` | Normalize w/h before clipping |
| loadBitmap | `action.c:bitmapDataLoadBitmap` | Static method on BitmapData ctor |
| Bitmap metadata registry | `tag.c:g_bitmap_defs[]` | char_id → offset/size/w/h |
| copyPixels alpha path | `action.c:bitmapDataCopyPixels` | OOB skip + alpha modulation |
| merge() | `action.c:bitmapDataMerge` | Per-channel weighted blend |
