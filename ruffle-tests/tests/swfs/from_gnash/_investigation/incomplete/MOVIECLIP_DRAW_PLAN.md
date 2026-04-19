# MovieClip-Source BitmapData.draw Plan
<!-- TESTS: BitmapData-v8 (30+ lines), bitmap_data_draw_cliprect, potentially others -->

Last updated: 2026-04-19
Status: PARTIAL — software rasterizer shipped; MC hierarchy + masks still missing.

## 2026-04-19 progress

- Added a barycentric triangle rasterizer in
  `SWFModernRuntime/src/actionmodern/action.c` (`rasterizeMovieClipToBitmap`).
  It renders a MovieClip's finalized `DrawingState.paths` (tessellated fill
  triangles and expanded line-stroke quads, stored in twips) into the
  destination `BitmapDataNative` pixel buffer using half-plane edge tests at
  pixel centers.
- `bitmapDataDraw` now dispatches on `ACTION_STACK_VALUE_MOVIECLIP` source
  (previously only BitmapData sources were accepted). Matrix (arg 1) and
  `clipRect` (arg 4) from the `draw(source, matrix, ct, bm, clipRect)` call
  are honoured; colorTransform and blendMode are still ignored (no tests
  depend on them yet).
- The rasterizer recursively renders `child_mc_cache[]` children by depth
  so a parent MC with children like `createEmptyMovieClip` are drawn,
  composing `(x, y, xscale, yscale, rotation)` into the outer matrix.
- **Impact:** BitmapData-v8 line-match 380/417 → 404/417 (-24 mismatched
  lines). Passes avm1 `bitmap_data_draw_cliprect`, `mask_with_drawing`,
  `duplicate_movie_clip_drawing`, and all four gnash `BitmapData-v{5,6,7,8}`
  baselines that were already passing.

## Remaining blockers (13 mismatched lines)

All remaining BitmapData-v8 diffs come from tests that use
`with (child_mc) { beginFill(...); moveTo(...); lineTo(...); }` to populate
child clips of an MC that is then passed to `bm.draw(parent_mc)`, with
`parent_mc.setMask(mask)` applied. Unblocking them requires three separate
features:

1. **Drawing API via CallFunction inside `with (mc) { ... }`.**
   Currently `MovieClip.prototype.beginFill/moveTo/lineTo/endFill/...` are
   installed as `builtin_noop_func` stubs, so WITH-scope calls don't reach
   the real handlers and no `DrawingState` is populated. An earlier attempt
   to dispatch these in `actionCallFunction` (using `scope_mc[]` as the
   target) populated `DrawingState` correctly but regressed BitmapData-v8
   further because…

2. **Mask respect in `BitmapData.draw`.** BitmapData-v8 applies
   `mc.setMask(mask)` before the draw; the expected output has only the
   masked pixels written. Without mask support, painting the child MCs
   hits pixels the test expects to remain white (regression pattern
   "got 0xFF0000 expected 0xFFFFFF" at (5,5), etc.).

3. **ColorTransform + blendMode arguments.** Some of the bm-test blocks
   use a `ColorTransform` arg to shift channels for overlap tests
   (`near(bm, 23, 15, 0x00ff00)` → `near(bm, 26, 15, 0x0000ff)`). Those
   will still diverge even with 1+2 fixed.

## Suggested next steps

- Factor the `CallMethod` drawing handlers (`beginFill`, `moveTo`,
  `lineTo`, `curveTo`, `endFill`, `lineStyle`, `clear`) into small shared
  helpers that take `(MovieClip*, args, num_args)`, then call them from both
  the CallMethod path and a new CallFunction WITH-scope dispatch block.
- Extend `bitmapDataDraw` to honour `mc->mask_mc`. Conceptually: rasterize
  the mask into a stencil buffer first, then restrict pixel writes to the
  stencil's non-zero area. For trace-only tests this can be a 1-bit buffer
  the size of the clip region.
- Plumb `ColorTransform` arg through the rasterizer (already partially
  present in `bitmapDataDraw` for BitmapData → BitmapData; need to apply
  it per-pixel during MC rasterization too).
- The full unblocker is probably 1-2 days per sub-feature.

---

## Scope

`BitmapData.draw(source, matrix?, colorTransform?, blendMode?, clipRect?, smooth?)`
with a MovieClip (or Sprite / Button / TextField) source requires rendering
the source's display list into a pixel buffer. Currently
`bitmapDataDraw` at `SWFModernRuntime/src/actionmodern/action.c:11383`
returns -1 when the source isn't a BitmapData ("MovieClip drawing not
supported in NO_GRAPHICS").

BitmapData-v8 test patterns (from `script_2.c`, reconstructed):

```as
d.lineTo(...); d.beginFill(...); d.moveTo(...); ...  // populate MC `d`
var b = new Bitmap(100, 100, false, 0xffffff);
b.draw(d);
check_equals(b.getPixel(21, 21), 0x00ff00);   // fails — we return 0xffffff
```

30+ lines failed in BitmapData-v8 because of this single missing feature.

---

## Why NO_GRAPHICS Can't Punt

The trace-test harness builds with `-DNO_GRAPHICS`, so the main renderer
(`render_webgpu.c`) isn't linked. But `BitmapData.draw` needs the rendering
logic *only for a private pixel buffer*, not for screen output. So we need
either:

1. **A second, headless, software rasterizer** — a small 2D rasterizer
   scoped to what `draw()` tests actually exercise (line drawing, simple
   fills, transform matrices).
2. **Refactor the existing WebGPU renderer** to support an off-screen
   render target and compile under NO_GRAPHICS. Unlikely to be worthwhile
   — the WGPU dependency would pull in the GPU stack.

Option 1 is the right path.

---

## What `b.draw(d)` Actually Needs to Render

From looking at the test, `d` is a programmatically-drawn MovieClip with
`lineTo`, `moveTo`, `beginFill`, and `endFill` calls. These populate a
dynamic-shape buffer on the MovieClip. The rasterizer needs:

### Required features (for Gnash BitmapData-v8 coverage)
- **Flat-fill polygons** (beginFill / endFill with solid color)
- **Straight-line strokes** (lineTo after lineStyle)
- **Affine transforms** (the optional matrix parameter scales/rotates/translates
  the source before rasterizing)
- **Clip against destination bounds** (naïve: just skip pixels out of range)

### Not required for this test (defer indefinitely)
- Gradient fills (linear / radial)
- Bitmap fills
- Dashed / textured strokes
- Anti-aliasing (trace tests can live with pixel-accurate results)
- Blend modes (tests use default "normal")
- Filters (ColorMatrix, Convolution, etc.) — tested separately via
  `applyFilter`, already stubbed

---

## Data Sources

Dynamic draw commands on a MovieClip land in the sprite's shape buffer. To
see the structure:

- `SWFModernRuntime/src/libswf/` — `DefineShape` and dynamic-draw tag
  handling
- `SWFModernRuntime/src/actionmodern/action.c` — the `moveTo` / `lineTo` /
  `beginFill` / `endFill` / `lineStyle` action handlers

Find those action handlers and trace what they write into the MC struct.
That's your rasterizer input.

---

## Implementation Sketch

### File: `SWFModernRuntime/src/actionmodern/bitmap_rasterizer.c` (new)

```c
// Rasterize a MovieClip's dynamic-draw shape buffer into a BitmapDataNative.
// Affine transform is applied per-vertex before scan-conversion.
void rasterizeShapeToBitmap(
    BitmapDataNative* dest,
    const DynamicShape* shape,   // from MovieClip struct
    const Matrix2D* xform,        // optional (identity if NULL)
    const ColorTransform* cx,     // optional (identity if NULL)
    const Rectangle* clipRect     // optional clip against dest pixels
);
```

Internally:
1. Iterate `shape->edges` and build a list of closed polygons per fill style.
2. For each polygon:
   - Transform all vertices through `xform`.
   - Scan-line fill into `dest->pixels[]` with the fill color (after `cx`).
3. For each stroke (edges with a line style):
   - Transform endpoints, rasterize with Bresenham, thickness from line style.

Keep it simple: no sub-pixel precision, no AA.

### Integration in `bitmapDataDraw`

```c
// action.c:11383 around the MC-source branch
if (src_obj && src_obj->native_type == NATIVE_MOVIECLIP) {
    MovieClip* mc = (MovieClip*)src_obj->native_ptr; // or equivalent
    Matrix2D xf; extractMatrix2D(&xf, &args[1]);     // optional arg
    ColorTransform cx; extractColorTransform(&cx, &args[2]);
    Rectangle clip; extractRect(&clip, &args[4]);
    rasterizeShapeToBitmap(dest_bmp, &mc->dynamic_shape, &xf, &cx, &clip);
    r = makeF64(0);
    return r;
}
```

### Matrix and Rectangle helpers

Need readers that take an ActionVar (OBJECT) and populate a C struct. Look
at `createMatrixObj` / `createRectObj` / `matrixFromObject` helpers already
in `action.c` near the geom prototypes (around line 6727+).

---

## Tests and Acceptance

- `BitmapData-v8`: expect ~30 line improvement.
- `bitmap_data_draw_cliprect` (avm1): currently passing? Check — if yes,
  ensure no regression.
- Add a sanity AVM1 test case: draw a simple shape, getPixel(), verify
  expected color within 1 LSB.

---

## Risk / Effort Estimate

- **Small**: if the MovieClip dynamic-shape struct is well-organized and
  already has a flat edge list, rasterizer is a few hundred lines of C.
  1-3 days.
- **Medium**: if we need to parse raw SWF shape records or reconcile with
  the graphics path's shape representation. 1 week.

Defer until Cats 1/2/4 of `BITMAPDATA_PLAN.md` are in — those are smaller
wins with higher ROI.

---

## Alternative: Skip and Document

If the rasterizer effort isn't worth it, an acceptable outcome:
- Mark all 30 draw-related lines in `BitmapData-v8` as unfixable in the
  `ACCEPTED_DIFFS.md` (category: "requires software rasterizer we don't
  ship with NO_GRAPHICS"), and move on.
- Note BitmapData-v8's remaining diff count is bounded by this single
  feature.

Decision to be made per session priorities.
