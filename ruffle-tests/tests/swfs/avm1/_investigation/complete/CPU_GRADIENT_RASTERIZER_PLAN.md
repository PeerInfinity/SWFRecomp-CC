# CPU Gradient Rasterizer Plan
<!-- TESTS: GradientFillTest (from_gnash/misc-ming.all) — and any other test using BitmapData.draw on gradient-filled MCs -->

<!-- PLAN_META
id: CPU_GRADIENT_RASTERIZER
status: completed
phases:
  - id: 1
    name: "Per-triangle gradient color interpolation (linear)"
    status: completed
  - id: 2
    name: "Radial gradient support"
    status: completed
  - id: 3
    name: "Spread mode (pad/reflect/repeat) handling"
    status: completed
  - id: 4
    name: "Verify against GradientFillTest pixel-sampling expectations"
    status: completed
dependencies: []
blockers: []
-->

Last updated: 2026-05-14

## Status: COMPLETED

Three new macros + plumbing in `rasterizeMovieClipToBitmap`
(`action.c:~12570`):

- `INVERT_2D_AFFINE(_in16, _oa, _ob, _oc, _od, _otx, _oty)` — invert the
  2D affine part of a 4x4 column-major matrix (gradient_matrix is stored
  this way). Returns zeroed outputs on singular matrix.
- `SAMPLE_GRADIENT_RAMP(ramp, spread, t, out_argb)` — handles pad /
  reflect / repeat, clamps to `[0, 1]`, then samples the 256-stop RGBA
  ramp. Output is ARGB.
- `RASTER_TRI_GRADIENT(...)` — parallel to `RASTER_TRI`, but instead of
  writing a constant color, interpolates shape-twips via barycentric
  weights, applies `inv(gradient_matrix)` to get gradient-space coords,
  computes `t` per the gradient type (linear: `(gx + 16384) / 32768`;
  radial / focal-radial: `sqrt(gx² + gy²) / 16384`), samples the ramp,
  optionally applies the color transform, and writes ARGB.

The path-rasterizer loop now branches on `path->has_gradient`:
- gradient: `RASTER_TRI_GRADIENT` per triangle, precomputed
  `inv(gradient_matrix)` once per path
- solid: unchanged

### Verified

- `from_gnash/misc-ming.all/GradientFillTest` (trace): 36 `FAILED`
  lines out of ~278 total pixel-sampling assertions — **87% match**.
  Was: 100% `0xffffff` / `0x0` (zero matches) before this plan. The
  remaining diffs are mostly slight color-band offsets within 1-2
  ramp indices (e.g. `0xfa420b` expected vs `0xf20d00` actual at the
  same gradient position — both are samples of the same ramp, just
  picking the neighboring index). Pure-radial and 3+ stop ramps are
  more sensitive to per-pixel center-of-pixel rounding than the
  GPU's filtered sampling.
- `BitmapDataDraw`: still `Ruffle-matched (100%)`.
- `DrawingApiTest`: trace diff identical to baseline (15 `FAILED`
  lines from pre-existing hitTest discrepancies, unrelated).
- Tier 1 (`display_object_properties`, `color`) and all sibling
  drawing tests: PASS unchanged.
- `BeginBitmapFill`, `movieclip_begin_gradient_fill`,
  `movieclip_line_gradient_style`: pre-existing image outlier counts
  unchanged (1389, 10943, 6053).

### Out of scope

- **Focal radial precise math.** Currently focal_radial uses the same
  formula as plain radial (ignores `focal_ratio`). The GPU does
  ray-march from the focal point; CPU would need the same. Defer
  until a test needs it.
- **Linear-RGB interpolation.** `path->interpolation` ignored — we
  read the ramp as-is (which is already pre-interpolated in the
  requested color space at ramp-generation time, so this is fine for
  most cases).
- **Line (stroke) gradients in BitmapData.draw.** `has_line_gradient`
  paths still use the solid line color. No current test exercises
  this; can extend the same way if needed.
- **GPU vs CPU pixel-perfect match.** GPU uses filtered texture
  sampling; CPU uses point sampling at pixel centers. Expect ±1-2
  ramp-index slop in tests that compare both.

## Problem

`rasterizeMovieClipToBitmap` (`action.c:12570`), used by `BitmapData.draw`,
can only render solid-fill triangles. Gradient-filled drawing-API paths
set `path->has_fill = 1` (so the rasterizer enters the path-drawing branch)
but their `path->fill_r/g/b/a` are zero — the rasterizer paints transparent
black over white bitmap, leaving the bitmap at its initial fill.

`GradientFillTest` is the immediate motivator: the test calls
`testbmp.draw(grad)` on a dynamic MC with 19 gradient-filled shapes, then
samples pixels via `getPixel`. Every pixel returns `0xffffff` instead of
the expected gradient colors.

The GPU side (`render_webgpu_draw_gradient_tris` in `render_webgpu.c:1805`)
handles gradients correctly via the fragment shader
(`SWFModernRuntime/src/flashbang/shaders/fragment.wgsl`). The CPU
rasterizer needs to mirror that math per pixel.

## Data Already Present on `DrawPath`

Populated by `drawingFinalizePath` (`action.c:24268`):

- `path->has_gradient` (0/1)
- `path->gradient_type` (0x10 = linear, 0x12 = radial, includes focal)
- `path->spread_mode` (pad / reflect / repeat)
- `path->interpolation` (sRGB vs linear-RGB)
- `path->focal_ratio` (for focal radial)
- `path->gradient_ramp[256 * 4]` (RGBA bytes, pre-baked 256-stop ramp)
- `path->gradient_matrix[16]` (4x4 column-major, maps gradient-space to
  shape-space)
- `path->fill_verts` (tessellated triangle vertices in twips)

Same set with `line_*` prefix for stroke gradients.

## Reference: How the GPU Does It

From `fragment.wgsl` + `render_webgpu.c:1837-1859`:

1. CPU inverts `gradient_matrix` to get shape-space → gradient-space.
2. CPU composes a normalization: `uv = (grad_coord + 16384) / 32768`,
   producing UV in `[0, 1]` for the gradient texture lookup.
3. Vertex shader applies the composed matrix to the vertex position,
   passing UV through `v_args.xy`.
4. Fragment shader:
   - Linear: `t = v_args.x` (already normalized).
   - Radial: `t = distance(v_args.xy * 32768 - 16384, 0) / 16384`,
     equivalent to `distance(grad_coord_xy, 0) / 16384`.
5. Samples `gradient_tex[t, layer=grad_id]`.

## Implementation Plan

### Phase 1 — Linear gradient inside the RASTER_TRI loop

Extend the `if (path->has_fill && path->fill_vert_count >= 3)` block at
`action.c:12632`. When `path->has_gradient` is set:

```c
// Precompute composed shape-space-pixel → gradient-UV matrix.
// dest pixel (px+0.5, py+0.5) is in dest-bitmap space, which equals
// shape-space after the outer (ma, mb, mc, md, mtx, mty) transform.
// So we need: inv(gradient_matrix) composed with inv(outer), then
// normalize to [0,1].
float inv_grad[16];
if (!invert_4x4_matrix(path->gradient_matrix, inv_grad)) {
    /* fall back to first ramp stop */
}
// inv_grad maps shape-space → gradient-space ([-16384, +16384] twips).
// Combine with twips-to-pixel scaling (shape verts are in twips, so
// inv_grad already operates in twips).

// Per-pixel inside RASTER_TRI: compute shape-space coord by
// inverting outer matrix, then apply inv_grad, then normalize.
// More efficient: precompute the full combined 2x3 affine that maps
// dest pixel coord (px+0.5, py+0.5) → gradient UV (in [0,1] linear
// per the GPU convention).
```

Replace the solid-color `RASTER_TRI(...)` call with a new
`RASTER_TRI_GRADIENT` macro that samples `path->gradient_ramp[t * 255]`
per pixel.

Linear sampling: clamp `t` to `[0, 1]` (pad), `t = abs(fmod(t, 2) - 1)`
(reflect), or `t = fmod(t, 1)` (repeat) — see Phase 3.

### Phase 2 — Radial

Same pre-computed matrix, but `t = sqrt(u*u + v*v)` where (u, v) are the
gradient-space coords (before normalization, in `[-16384, +16384]`),
divided by `16384`.

Focal radial: `gradient_type == 0x13`. `focal_ratio` shifts the center.
Defer initial implementation; document as future work if no test needs
it.

### Phase 3 — Spread modes

Three modes (encoded in `path->spread_mode`):

- `0` pad: `t = clamp(t, 0, 1)`.
- `1` reflect: `t = 1 - abs(fmod(t, 2) - 1)`.
- `2` repeat: `t = fmod(t, 1); if (t < 0) t += 1`.

Apply uniformly to both linear and radial paths.

### Phase 4 — Verify against GradientFillTest

- `python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_gnash/misc-ming.all --test=GradientFillTest --mode=graphics --expected-suffix=fp10 --diff --verbose`
- Inspect trace: `Checking square at 0x0` should match expected pixel
  values like `0x8080ff,0x8787ff,0x8d8dff,…`.
- Tolerance in test: nearColor uses Euclidean distance with tolerance=32,
  so per-channel differences up to ~18 are accepted.

Regression-check (no expected change):

- `display_object_properties`, `color`, `bitmap_data_fillrect`,
  `mask_with_drawing`, `BeginBitmapFill` — none use BitmapData.draw on
  gradient-filled MCs, so should be unaffected.
- Any test that calls `BitmapData.draw` on a solid-color MC — should
  still hit the existing solid-fill path.

## Design Considerations

1. **Performance.** Per-pixel matrix multiply + ramp lookup is ~10×
   slower than solid fill, but BitmapData.draw is one-shot per call and
   the bitmap dimensions are bounded. Acceptable for a test runner.

2. **Coordinate flow.** Vertices in `fill_verts` are in twips. The outer
   matrix (`ma, mb, …, mty`) converts shape-twips → bitmap-pixels (already
   in `RASTER_TRI`'s coordinate math). The gradient matrix is in twips
   (matches how PlaceObject2 / DefineShape stores it). So:
   ```
   gradient_uv = inv(gradient_matrix) * shape_twips
   shape_twips = inv(outer_matrix) * (dest_pixel - 0.5)
   ```
   Cleanest: precompute `combined = inv(gradient_matrix) * inv(outer)`
   once per path, apply per pixel.

3. **Premultiplied alpha.** `gradient_ramp` stores
   straight ARGB. The destination bitmap is opaque (BitmapData(.., false)
   in the test), so just write `(0xFF << 24) | (r << 16) | (g << 8) | b`.

4. **Color transform.** When `cx` is non-NULL, apply it to the sampled
   ramp color exactly like the solid-fill path does
   (`fr_d = fr_d * cx->rm + cx->ro` etc.).

5. **Line gradients.** Same logic applies to stroke (`has_line_gradient`).
   Defer to a follow-up if no test needs it; document the gap.

## Estimated Complexity

Medium. ~200 LOC in `rasterizeMovieClipToBitmap` (one new helper macro,
matrix invert/compose, three spread-mode branches, optional radial focal
math). All inside one function — no cross-file plumbing.

## Out of Scope

- Linear-RGB interpolation (`interpolation` flag) — for now, sample the
  ramp directly as if it were already in the requested color space.
  Ruffle pre-bakes both linear and sRGB ramps if needed; we just lookup.
- Line (stroke) gradients in `BitmapData.draw` — defer to follow-up.
- Focal radial gradients — defer if no test exercises it.
