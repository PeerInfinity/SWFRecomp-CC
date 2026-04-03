# BitmapData.loadBitmap() Implementation Plan
<!-- TESTS: bitmap_data_colortransform (image) -->

<!-- PLAN_META
id: LOADBITMAP
status: complete
phases:
  - id: 1
    name: "Implement loadBitmap static method"
    status: complete
dependencies: []
blockers: []
-->

Last updated: 2026-04-03

## Status: COMPLETE

All work in this plan was already implemented. The `bitmap_data_colortransform` test passes (both trace and image).

### What was implemented

`bitmapDataLoadBitmap` at `action.c:10393` is a full implementation that:
1. Gets the export name from args[0] (string coercion)
2. Looks up the char_id via `ng_lookupExport(name)`
3. Gets bitmap metadata via `ng_getBitmapMetadata(char_id, ...)`
4. Creates a new `BitmapDataNative` with the correct dimensions
5. Copies pixel data from the static `bitmap_data[]` buffer with R/B byte swap (BGRA→RGBA)
6. Wraps it in an ASObject with proper prototype chain
7. Returns the BitmapData object

### Test Results

- `bitmap_data_colortransform`: **PASS** (trace: 0/0 lines, image: 0 outliers, max diff 4)
- Implementation completed in prior sessions (2026-03-29 loadBitmap, 2026-04-02 image fixes)
