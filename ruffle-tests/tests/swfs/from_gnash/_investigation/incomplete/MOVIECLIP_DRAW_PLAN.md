# MovieClip-Source BitmapData.draw Plan
<!-- TESTS: BitmapData-v8 (30+ lines), bitmap_data_draw_cliprect, potentially others -->

Last updated: 2026-04-19
Status: PARTIAL — rasterizer, WITH-scope drawing dispatch, setMask stencil,
and ColorTransform now wired. BitmapData-v8 is `ruffle_matched` (filtered
pass). 6 literal-line diffs remain, concentrated in overlap/boundary pixels.

## 2026-04-19 progress

### Session 1
- Added a barycentric triangle rasterizer
  `rasterizeMovieClipToBitmap` in `SWFModernRuntime/src/actionmodern/action.c`.
  Renders `DrawingState.paths` (tessellated fill triangles + expanded line
  quads, in twips) into the destination `BitmapDataNative` pixel buffer via
  half-plane edge tests at pixel centers.
- `bitmapDataDraw` now dispatches on `ACTION_STACK_VALUE_MOVIECLIP` source;
  handles matrix (arg 1) and `clipRect` (arg 4).
- Recursive child rendering via `child_mc_cache[]` in depth-ascending order
  with local (x, y, xscale, yscale, rotation) composed into the outer matrix.

### Session 2 (this commit)
- **WITH-scope drawing API dispatch.** Added a block at the top of
  `actionCallFunction` that detects a MovieClip in the current WITH scope
  (via `scope_mc[]` + `scope_is_with[]`) and forwards calls to
  `beginFill`/`moveTo`/`lineTo`/`curveTo`/`endFill`/`lineStyle`/`clear`
  directly into that MC's `DrawingState`. Previously these calls resolved
  to `builtin_noop_func` stubs installed on `MovieClip.prototype`, so
  `with (mc) { beginFill(...); moveTo(...); ... }` was a no-op.
- **`setMask` stencil clipping.** When the source MC has `mask_mc` set, we
  allocate a byte-per-pixel stencil buffer sized to `dest` and rasterise
  the mask into it (1 = covered, 0 = not) using the same rasteriser with a
  second-output mode. The mask's own local transform (`_x`, `_y`, rotation,
  scale) is composed on top of the draw() matrix before rasterising — so
  shifting `mask._x` shifts the masked area. Source pixels are only
  written where the stencil is non-zero. Children that have `is_mask=1`
  are skipped in the content pass so a mask MC doesn't paint itself.
- **ColorTransform (arg 2) on MC source.** Parses
  `redMultiplier`/`greenMultiplier`/`blueMultiplier`/`alphaMultiplier` and
  the matching `*Offset` properties off the passed object and applies
  `c' = c*mult + off` per-channel (clamped) to every fill/stroke colour
  during rasterisation.
- **Impact:** BitmapData-v8 `output_mismatch` → `ruffle_matched`
  (lines 404/417 → 410/417 effective; 6 literal diffs remain). Effective
  pass rate on gnash `actionscript.all` moves from 151 → 152 (pass+RM
  combined). Suite-wide regression check (avm1 BitmapData family,
  `mask_with_drawing`, `duplicate_movie_clip_drawing`, `with-v5..v8`,
  `movieclip_begin_gradient_fill`, `movieclip_line_gradient_style`,
  `hittest_lockroot`, `define_local_with_paths`): all unchanged.

## Remaining diffs (6 lines)

All in the gradient/overlap blocks of BitmapData-v8:

- Lines 571–572: expect `0x00ff00` at (23, 15) and (24, 15); we produce
  a different colour at those pixels.
- Lines 588–591: expect `0xff0000` at (23, 15)/(24, 15) and `0x00ff00`
  at (25, 15)/(26, 15); all four are wrong.

These are pixel-accurate boundary tests between two shapes that meet at
a sub-pixel boundary (likely x = 24.5 in source coords). Root cause is
almost certainly our triangle-rasterizer top-left rule versus Flash's
winding rule on edges shared between adjacent triangles. Fixing would
require either (a) emulating Flash's exact fill rule on shared edges, or
(b) running a separate analytic pass over polygons rather than the
tessellated triangles. Low ROI for the last 6 lines.

## What's wired vs not

| Feature                                     | Status |
|---------------------------------------------|--------|
| Polygon fill rasterisation                  | ✅     |
| Line-stroke rasterisation                   | ✅     |
| `draw(source)` with MC source               | ✅     |
| `draw(source, matrix)`                      | ✅     |
| `draw(source, matrix, colorTransform)`      | ✅     |
| `draw(source, ..., clipRect)`               | ✅     |
| Child MC recursion with transforms          | ✅     |
| `with (mc) { beginFill/moveTo/... }`        | ✅     |
| `mc.setMask(mask)` stencil clipping         | ✅     |
| Blend modes (`blendMode` arg, arg 3)        | ❌     |
| Gradient fills in rasteriser                | ❌     |
| Bitmap fills in rasteriser                  | ❌     |
| Sub-pixel coverage / AA                     | ❌     |
| Anti-aliased boundary between triangles     | ❌     |

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
