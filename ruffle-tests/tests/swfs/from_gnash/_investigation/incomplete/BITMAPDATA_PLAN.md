# BitmapData Plan
<!-- TESTS: BitmapData-v8 -->

Last updated: 2026-04-18
Status: IN PROGRESS — 1 test, 366/410 tests pass (89%) — 44 diffs remaining

## 2026-04-18 Session

**Fix landed: Bitmap alias routed to native BitmapData constructor.**
Root cause: The test aliases `Bitmap = flash.display.BitmapData`, so
`new Bitmap(10, 10, true, 0xFFFFFF)` enters `actionNewObject` with
`ctor_name="Bitmap"`. The existing BitmapData branch only matched the
literal name "BitmapData", so `Bitmap` fell through to the generic
user-defined-ctor path, which saw the stub constructor (simple_func/
advanced_func both NULL) and returned a plain object with no native
BitmapData backing — every getter returned -1.

Fix in `SWFModernRuntime/src/actionmodern/action.c`:
1. Added `pushBitmapDataConstruct(app_context, args, num_args)` helper
   that centralises the width/height/transparent/fillColor validation
   and native construction (used by both actionNewObject and
   actionNewMethod paths going forward).
2. In `actionNewObject`, after ctor_func resolution, added a redirect:
   if ctor_func is a stub and `ctor_func->name == "BitmapData"`,
   dispatch to the helper. This covers both direct `new BitmapData()`
   and aliases like `new Bitmap()`.

Impact: BitmapData-v8 jumped from 259/417 → 366/410 tests passing.
v5/v6/v7 still PASS (no regressions).

## Remaining 44 Diffs (Phase 2+)

1. **rectangle getter on disposed/edge-case BMD (~4 diffs)** —
   tests expect `bmp.rectangle == -1` or `bmp.rectangle.toString() ==
   "[object Object]"` when `bmp` has been disposed or had `rectangle`
   monkey-patched. Our getter always returns a fresh Rectangle.

2. **clone() not preserving __proto__/constructor (~4 diffs)** —
   tests at BitmapData.as:1126-1129 expect that if the source has
   had its prototype chain modified (e.g. `BitmapData.prototype = o`),
   the clone inherits the same chain. Our `bitmapDataClone` hardcodes
   `__proto__ = g_bitmapdata_prototype`.

3. **Pixel ops producing wrong color at certain coords (~30 diffs)** —
   `b.getPixel(21, 21) == 0x00ff00` fails with white (0xffffff), suggesting
   `fillRect`, `floodFill`, `applyFilter`, or `copyPixels` dropping
   fills in some coordinate ranges. Source required for root cause.

4. **copyPixels dispatches wrong color (~1 diff)** —
   `source.getPixel(90, 90) == 0xffffff` returns `0x0000ff00`.

5. **Final assertion count differs** — 2 #passed/#failed lines.

Each class of diff deserves its own investigation in a follow-up session.

---

## Original Plan (for reference)

---

## Overview

`flash.display.BitmapData` is a large class exposing pixel-level image
manipulation: construction, pixel reads/writes, fill operations, channel
copies, filters, hit tests, and draw-from-MC. The Gnash `BitmapData-v8` test
exercises the full public surface.

## Current Line Match

| Test | Match | Diffs |
|------|-------|-------|
| BitmapData-v8 | 259/417 (62.1%) | ~160 |

## What Already Works

The test passes ~62% of lines, so our existing BitmapData stubs handle:
- Constructor argument validation
- `getBounds` / width / height getters
- Simple `fillRect`
- Basic `getPixel` / `getPixel32`

## What's Missing (diff-driven list; refine against actual output.txt)

### Phase 1 — Pixel / rect ops
- `setPixel(x, y, color)` + `setPixel32(x, y, color)` with clipping
- `floodFill(x, y, color)` — scanline fill
- `copyPixels(src, srcRect, destPoint, alphaBitmap?, alphaPoint?, mergeAlpha?)`
- `copyChannel(src, srcRect, destPoint, srcChannel, destChannel)`
- `merge(src, srcRect, destPoint, redMultiplier, ..., alphaMultiplier)`
- Storage: keep a flat `uint32_t* pixels; int width, height;` on the
  BitmapData ASObject (native_type = NATIVE_BITMAPDATA).

### Phase 2 — Geometry / utility
- `clone()` — allocate new backing store, memcpy pixels
- `rect` getter returning a Rectangle with `(0, 0, width, height)`
- `getColorBoundsRect(mask, color, findColor?)`
- `hitTest(firstPoint, firstThreshold, secondObject, secondBitmapPoint?, secondThreshold?)`
- `compare(other)` — returns BitmapData diff or equality result
- `scroll(dx, dy)`

### Phase 3 — Draw and filter
- `draw(source, matrix?, cxform?, blendMode?, clipRect?, smooth?)` — needs
  at minimum a software rasterizer for MovieClip/Sprite sources. Scope
  reasonably: draw only the display list without filters/bitmap effects.
- `applyFilter(sourceBmp, sourceRect, destPoint, filter)` — stub-only for
  unsupported filters (return undefined); implement ColorMatrixFilter and
  ConvolutionFilter if time permits.
- `noise(randomSeed, low?, high?, channelOptions?, grayScale?)` —
  deterministic PRNG.
- `perlinNoise` — defer (complex; low value).
- `pixelDissolve` — defer.

### Phase 4 — Loader class methods
- `BitmapData.loadBitmap(linkageId)` — look up the symbol, returns null in
  our trace-only mode (no real assets). Document in `ACCEPTED_DIFFS.md`.

## Storage / Lifecycle

- `ASObject::native_type = NATIVE_BITMAPDATA`
- New fields on a backing struct (not on ASObject directly to keep common
  struct small): `BitmapDataNative { u32* pixels; int w, h; bool transparent; u32 fillColor; }`.
- Plumb native struct via `ASObject::native_ptr` (add the field if absent).
- Free on ASObject GC / destructor.

## Integration Points

- MovieClip.attachBitmap(bmd, depth, blendMode?, smoothing?) — already
  partially stubbed for the AVM1 suite; confirm it calls back to the
  BitmapData backing store.
- `Bitmap` class: thin display wrapper; likely covered by existing graphics
  code (NO_GRAPHICS builds ignore).

## Success Criteria

- BitmapData-v8 crosses 85% line match (target: 360+ lines).
- No regression on avm1 `bitmap*` tests (if present).
- Trace mode runs at same speed (pixel ops must not dominate runtime).

## Risk / Effort Estimate

- Phase 1-2 (pixel/geometry): ~2-3 days. Self-contained, straightforward C.
- Phase 3 (draw): 1 week if we go beyond stub; otherwise leave stub and
  document unsupported lines in `ACCEPTED_DIFFS.md`.
- Phase 4: trivial.

## Related

- `GNASH_FEATURE_PLAN.md` section 18 (BitmapData row — this plan supersedes)
- `avm1/_investigation/FEATURE_SCOPE.md` — graphics-feature tracking
