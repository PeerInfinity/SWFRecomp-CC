# BitmapData.loadBitmap() Implementation Plan
<!-- TESTS: bitmap_data_colortransform (image) -->

<!-- PLAN_META
id: LOADBITMAP
status: not_started
phases:
  - id: 1
    name: "Implement loadBitmap static method"
    status: not_started
dependencies: []
blockers: []
-->

Last updated: 2026-03-29

## Status: NOT STARTED

### Problem

The `bitmap_data_colortransform` headless image test renders all-black. The test calls `BitmapData.loadBitmap("TestBitmapData")` to load a static bitmap resource from the SWF, but the function is a stub that returns undefined. Without the bitmap, colorTransform operates on nothing, attachBitmap attaches nothing, and the display is blank.

**Current image result:** 78,561 outliers, max diff 255 (all-black vs colored patterns)

### Root Cause

`bitmapDataLoadBitmap` at `action.c:9542-9547` is a no-op stub:

```c
static ActionVar bitmapDataLoadBitmap(...)
{
    ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED;
    return r;
}
```

The test SWF defines a static bitmap:
- `defineBitmap(0, 8192, 256, 8)` — 256x8 pixels, 32bpp
- `tagRegisterExport(app_context, "TestBitmapData", 1)` — exported as "TestBitmapData"
- Pixel data stored in `RecompiledTags/draws.c` as `u8 bitmap_data[8192]`

### API

```actionscript
var bmd:BitmapData = BitmapData.loadBitmap("exportName");
```

`loadBitmap` is a **static method** on the BitmapData class (called on the class, not an instance). It:
1. Looks up the export name in the SWF's export registry
2. Finds the corresponding character (DefineBits tag)
3. Creates a new BitmapData object from that character's pixel data
4. Returns the BitmapData object (or null if not found)

### Implementation Steps

#### Step 1: Implement loadBitmap (~40 lines)

The function needs to:
1. Get the export name from args[0] (string)
2. Look up the char_id via `ng_lookupExportCharId(name)` (or similar — check tag_stubs.c for export lookup)
3. Find the static bitmap data for that char_id (the bitmap pixel buffer + dimensions)
4. Create a new BitmapDataNative with those dimensions
5. Copy the pixel data from the static buffer to the new BitmapData's pixel buffer
6. Create an ASObject wrapping the BitmapDataNative
7. Set up prototype chain (same as BitmapData constructor)
8. Return the object

### Key Infrastructure

The static bitmap system already exists for rendering:
- `defineBitmap()` stores bitmap data indexed by character ID
- `tagRegisterExport()` maps export names to character IDs
- The pixel data is available as raw ARGB bytes in the generated `draws.c`

Need to find:
- How to look up export name → char_id (check `tag_stubs.c` or `tag.c` for export registry)
- How to access the static bitmap pixel data by char_id
- The pixel format (likely ARGB premultiplied, matching BitmapDataNative format)

### Key Code Locations

| Component | File | Line |
|-----------|------|------|
| loadBitmap stub | action.c | 9542-9547 |
| Static bitmap definition | tagMain.c (per test) | varies |
| Export registration | tagMain.c | `tagRegisterExport()` |
| BitmapDataNative struct | action.c | 2149-2155 |
| BitmapData constructor | action.c | ~38930 |
| Export name lookup | tag_stubs.c | `ng_lookupExportName()` (reverse) |

### Estimated Complexity

Medium — ~50 lines of C. Requires understanding the export registry and static bitmap storage, but the pixel copy itself is straightforward.

### Expected Impact

Should fix the `bitmap_data_colortransform` image test (78,561 outliers → likely 0 or near-0). The colorTransform implementation already works correctly (trace test passes); the only issue is that loadBitmap returns undefined.
