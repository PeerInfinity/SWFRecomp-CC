# BitmapData Plan
<!-- TESTS: BitmapData-v8 -->

Last updated: 2026-04-18 (session 4)
Status: IN PROGRESS — 1 test, 376/417 lines matching (90%) — 39 diffs remaining

---

## History

### Session 1 (2026-04-18, committed 0d2963a2)
Fixed `new Bitmap(...)` alias so the recompiled call path in actionNewObject
dispatches to the native BitmapData constructor. Before the fix, the test's
`var Bitmap = flash.display.BitmapData; new Bitmap(10, 10, true, 0xFFFFFF)`
landed in the generic user-defined-ctor path, which saw the stub fc_BitmapData
(simple_func/advanced_func both NULL), created a plain object with no native
backing, and every getter returned -1.

Fix: added `pushBitmapDataConstruct` helper and wired a redirect in
actionNewObject: after ctor_func resolution, if the resolved function is a
stub whose name is "BitmapData", dispatch to the helper. Covers both direct
`new BitmapData(...)` and aliases. See commit message for details.

Result: BitmapData-v8 matching lines 273/417 → 371/417. No regressions on
BitmapData-v5/v6/v7 or any other suite.

### Session 2 (2026-04-18, investigation only — no code changes)
Reverse-engineered test logic from `RecompiledScripts/script_2.c` +
`output.txt` + `script_defs.c` constant-pool strings. Classified the
44 remaining diffs into four root causes with fix recommendations.

### Session 3 (2026-04-18) — Cat 1 fix landed
`bdRectangleGetter` now resolves `flash.geom.Rectangle` at call time
(via `global_object → flash → geom → Rectangle`) instead of always
using the built-in `createRectObj`. If the resolved value is
non-function, returns -1 (matches Flash when Rectangle was overwritten
with a number). If it's a stub (simple_func/advanced_func both NULL),
falls back to `createRectObj` — preserving the default path with the
native toString. Otherwise invokes the user function as constructor
with `(0, 0, width, height)` and returns the produced object (its
prototype chain determines toString — an empty anonymous function
gives "[object Object]" via Object.prototype).

Result: BitmapData-v8 diffs 44 → 40 (4 Cat 1 tests fixed:
315/324/329/334). BitmapData-v5/v6/v7 still PASS. AVM1 bitmap tests
unchanged. Rectangle-v5/v6/v7 unchanged; Rectangle-v8 was already
failing before the fix (unrelated Rectangle.containsPoint bugs).

### Session 4 (2026-04-18) — Cat 4 fix landed
Root cause isolated: when `src == dest` and the source/dest rects
overlap, `bitmapDataCopyPixels` read-and-wrote in place. Early iterations
overwrite pixels that later iterations read as source — those reads
pick up already-copied pixels instead of the original source. For the
failing case `source.copyPixels(source, Rect(20,20,50,50), Point(45,45))`:
at (sx=20, sy=20), we write `dest[65,65] = src[40,40] = green`; then
at (sx=45, sy=45), we read `src[65,65]` which was just overwritten to
green and write it to `dest[90,90]` — but Flash expects white there
because the original `src[65,65]` was outside the green fillRect.

Fix: when `src_bmp == dest_bmp` (or the alpha bitmap aliases the dest),
snapshot the source pixels into a temp buffer before the copy loop and
read from the snapshot. Free the snapshot after. Both loops (transparent
alpha path and no-alpha path) now read from `src_pixels` which aliases
to either the snapshot or the original buffer.

Result: BitmapData-v8 diffs 40 → 39 (Cat 4 test 688 fixed). No
regressions on BitmapData-v5/v6/v7, AVM1 bitmap tests.

---

## Remaining 44 Diffs — Root Causes

### Cat 1. `bmp.rectangle` getter ignores user override of `flash.geom.Rectangle` (4 diffs) — **FIXED (session 3)**

Tests: `BitmapData.as:315`, `324`, `329`, `334`. Cluster around test code that
monkey-patches the global `flash.geom.Rectangle` between assertions:

```as
// Before test 315:
flash.geom.Rectangle = 2;             // replace ctor with a number
check_equals(bmp.rectangle, -1);      // test 315 — Flash returns -1 since Rectangle is not callable

// Before tests 324/329/334:
flash.geom.Rectangle = function(){};  // replace with an empty anonymous function
check_equals(bmp.rectangle.toString(),"[object Object]");  // new Rectangle() returns plain object

// Before test 337:
flash.geom.Rectangle = <original>;    // restore
check_equals(bmp.rectangle.toString(),"(x=0, y=0, w=20, h=10)");  // normal path
```

Confirmed by reading generated C at `script_2.c:15380-15384` (writes `2` to
`flash.geom.Rectangle`) and `:15497-15511` (DefineFunction2 sets it to an
anonymous function).

**Current behavior:** our `bdRectangleGetter` at
`SWFModernRuntime/src/actionmodern/action.c:11579` always calls
`createRectObj(app_context, ...)` (a hardcoded helper that allocates an
ASObject with `__proto__ = g_rect_prototype`). It doesn't look at
`flash.geom.Rectangle`, so it produces a valid rect even when Rectangle has
been overwritten.

**Fix:** rewrite `bdRectangleGetter` to dispatch `new flash.geom.Rectangle(x, y, w, h)`
at runtime by looking up the current constructor via the global chain
(`flash` → `geom` → `Rectangle`). If the resolved value is not a function,
return it as-is (matching `bmp.rectangle == -1` when Rectangle was set to 2,
and `"[object Object]"` when it's an empty function whose prototype has no
custom toString).

Impact: +4 diffs.

---

### Cat 2. `clone()` returns -1 when `this` isn't a real BitmapData (4 diffs)

Tests: `BitmapData.as:1126, 1127, 1128, 1129`. The test pattern (reconstructed
from `script_2.c:50017-50138`):

```as
var o = {};
o.constructor = 25;
o.clone = flash.display.BitmapData.prototype.clone;
o.__proto__ = o;                  // circular
o.width = 20;
o.height = 21;
o.getPixel = flash.display.BitmapData.prototype.getPixel;
var cl = o.clone();               // calls clone with this = o
check_equals(cl.__proto__, o);    // 1126 — clone preserves source's __proto__
check_equals(cl.constructor, 25); // 1127 — clone preserves constructor
check_equals(cl.width, 20);       // 1128 — via __proto__ chain to o.width
check_equals(cl.height, 21);      // 1129
```

**Flash's clone()** does not require `this` to have a native BitmapData. It
creates a new object that inherits `__proto__` from the caller (and whose
`constructor` is resolved via the prototype chain). When the caller is
`o = {}` with `o.width = 20`, property access on the clone walks the chain
and returns 20.

**Current behavior:** `bitmapDataClone` at
`SWFModernRuntime/src/actionmodern/action.c:9737` hard-fails with
`makeF64(-1)` when `getBitmapNative(this)` is NULL or disposed. For the
non-native `o` case, this is *wrong* — Flash doesn't early-out.

The test passing "obtained: 10" (not -1) for cl.width suggests our
implementation is somehow returning an object with width 10, not a number.
This is likely because the `getPixel` line (set at `script_2.c:50096-50123`)
is part of a *different* `o` — we got a stale `o` from an earlier test that
was a real BitmapData, or our stored native got reused. Needs more digging.

**Fix direction:**
1. `bitmapDataClone` should not return -1 when native is missing. Instead it
   should create a new ASObject whose `__proto__` is copied from `this`
   (the source's own `__proto__` property, not hardcoded
   `g_bitmapdata_prototype`).
2. For tests 1131-1132 (which currently pass with width=10), make sure we
   don't over-propagate — when a real BitmapData is cloned, the result
   should still have the native data.

Estimated impact: +4 diffs, but may surface the separate "10 vs 20" puzzle.

---

### Cat 3. `BitmapData.draw(MovieClip)` is a no-op (30+ diffs)

Tests: `BitmapData.as:369, 371, 373, 378, 380, 382, 388, 390, 392, ...` and
the `near()` cluster around lines 520, 538, 557, 571-574, 588-591. ~30 diffs
total, all clustered around two code patterns:

```as
// Pattern 1: draw a MovieClip into a BitmapData, then inspect pixels
d.lineTo(...);              // draw something on a MovieClip `d`
var b = new Bitmap(100, 100, false, 0xffffff);
b.draw(d);                  // rasterize d's display list into b
check_equals(b.getPixel(21, 21), 0x00ff00);  // fails — we return 0xffffff
```

Confirmed by reading `script_2.c:16267-16297` where `b.draw(d)` is called on
a MovieClip `d` populated with `lineTo` calls.

```as
// Pattern 2: draw a MovieClip, then hit-test via a `near()` helper
near(bm, 15, 15, 0x00ff00);  // user-defined: ~= bm.getPixel(15,15) ≈ 0x00ff00
```

`near()` is a user-defined function that looks up `bm.getPixel(x, y)` and
compares approximately to an expected color (confirmed at `script_2.c:23286+`
where `str_326 = "near"` is called with `(bm, 15, 15, 0x00ff00, 4)`).

**Current behavior:** `bitmapDataDraw` at
`SWFModernRuntime/src/actionmodern/action.c:11383` only handles
BitmapData-source draws (copy pixels from another BitmapData). For MovieClip
sources, it returns -1 with a comment: "MovieClip drawing not supported in
NO_GRAPHICS." The destination bitmap is never written.

**Fix direction:** this requires a real software rasterizer that can walk
a MovieClip's shape data (fills, strokes, transforms) and render scanlines
into a BitmapData pixel buffer — a substantial undertaking. See
`MOVIECLIP_DRAW_PLAN.md` for scoped design.

Estimated impact: +30 diffs — the largest remaining chunk but also the
hardest to fix. Deferred to its own plan.

---

### Cat 4. `copyPixels` writes outside the dest rect (1 diff) — **FIXED (session 4)**

Test: `BitmapData.as:688` — after
`source.copyPixels(source, new Rectangle(50, 50, 20, 20), new Point(45, 45))`,
`source.getPixel(90, 90)` should still be the original 0xffffff (coord 90,90
is far from both the source and dest rects). We return 0x0000ff00 = green
(65280) — suggesting our `copyPixels` impl is smearing fill pixels across
the whole image, not just the 20×20 destination region starting at (45,45).

Confirmed by reading `script_2.c:32698-32712` which invokes
`source.getPixel(90, 90)` after the copy.

**Fix direction:** audit the destination-rect clipping in
`bitmapDataCopyPixels` (at `SWFModernRuntime/src/actionmodern/action.c:9769`
area). Likely an off-by-one or a missing clip against srcRect width/height.

Estimated impact: +1 diff (but similar bugs may lurk elsewhere — worth a
broader audit of the pixel-op cluster).

---

### Cat 5. Final totals line (1 diff group, 3 lines)

The last three output lines are Dejagnu's `#passed:`/`#failed:`/`#total`
summary. These will converge automatically once the above fixes land.

---

## Recommended Fix Order

1. **Cat 1 (rectangle getter)** — 4 diffs, small isolated runtime change.
2. **Cat 4 (copyPixels clipping)** — 1 diff, likely a small bug to track down.
3. **Cat 2 (clone fallback)** — 4 diffs, straightforward but has a sub-puzzle
   (width=10 mystery) to resolve first.
4. **Cat 3 (draw rasterizer)** — 30 diffs, large undertaking — see separate
   `MOVIECLIP_DRAW_PLAN.md`.

After Cats 1-4: expected ~44-35 = 9 diffs remaining (most being `draw`
without a rasterizer). After Cat 3: test passes or near-passes.

---

## Original Plan (2026-04-17, for reference)

`flash.display.BitmapData` is a large class exposing pixel-level image
manipulation: construction, pixel reads/writes, fill operations, channel
copies, filters, hit tests, and draw-from-MC. The Gnash `BitmapData-v8` test
exercises the full public surface.

### What Already Works (much of this)
- Constructor argument validation
- `getBounds` / width / height getters
- Simple `fillRect`
- Basic `getPixel` / `getPixel32`
- `applyFilter`, `colorTransform` (partial)
- `compare`, `hitTest` (partial)
- Channel ops, merge, threshold, scroll

### Deferred (per test expected-output coverage)
- `BitmapData.loadBitmap` — linkage lookup returns null in trace-only mode.
  Document case-by-case in `ACCEPTED_DIFFS.md` if it surfaces.
- `perlinNoise`, `pixelDissolve` — low-value, complex. Defer.

## Related

- `GNASH_FEATURE_PLAN.md` section 18 (BitmapData row — this plan supersedes)
- `avm1/_investigation/FEATURE_SCOPE.md` — graphics-feature tracking
- (new) `MOVIECLIP_DRAW_PLAN.md` — dedicated plan for Cat 3.
