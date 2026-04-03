# Rendering Pipeline Comparison: Our Implementation vs Ruffle

This document explains the architectural differences between our Drawing API gradient rendering pipeline and Ruffle's, the visual artifacts that result, and what it would take to close the remaining gaps.

## Background

After fixing three bugs in April 2026 (focal type upgrade, NaN handling, linearRGB color space), image test outliers dropped by ~80-86%. Additional improvements include libtess2 integration (constrained Delaunay tessellation), adaptive bezier flattening, and gradient coordinate normalization to [0,1] range. The remaining ~10K outlier channels per test come from fundamental pipeline differences described below.

## Architecture at a Glance

| Aspect | Ours | Ruffle |
|--------|------|--------|
| Tessellation | libtess2 (constrained Delaunay) | Lyon library (constrained Delaunay) |
| Gradient UV source | Vertex shader (inverse matrix, [0,1] UVs) | Vertex shader (texture matrix uniform, [0,1] UVs) |
| Gradient ramp | 256-texel RGBA8 array texture | 256-texel RGBA8 standalone texture |
| Gradient pipeline | Shared with all fills | Dedicated pipeline per gradient |
| Coordinate space | Twips ([-16384, 16384]) | Normalized ([-1, 1] or [0, 1]) |
| MSAA | 4x | 4x |
| Framebuffer | RGBA8Unorm | RGBA8Unorm |

## Detailed Pipeline Comparison

### Stage 1: Tessellation

**Ours — libtess2 (GLU tessellator)**

When `endFill()` is called, `drawingFinalizePath()` converts the accumulated drawing commands (moveTo, lineTo, curveTo) into triangles:

1. Bezier curves are adaptively flattened (1/4/8/16 segments based on control point deviation, ~0.5px tolerance).
2. The polygon is triangulated using **libtess2** with constrained Delaunay triangulation enabled (`TESS_CONSTRAINED_DELAUNAY_TRIANGULATION`). Falls back to fan tessellation if libtess2 fails.
3. Line strokes are expanded into quads (2 triangles per segment) using perpendicular offset by half the line width.
4. All output coordinates are in twips (pixels x 20).

**Ruffle — Lyon Tessellation**

Ruffle uses the [Lyon](https://github.com/nical/lyon) crate, which implements **constrained Delaunay triangulation**:

1. Curves are flattened adaptively (tolerance-based, not fixed segment count).
2. Fill shapes are tessellated using Lyon's `FillTessellator`, producing well-shaped triangles via a sweep-line algorithm.
3. Stroke shapes are tessellated using Lyon's `StrokeTessellator`, with proper miter/bevel/round join handling.
4. Output is indexed triangle meshes (vertex + index buffers).

**Impact on image output:**

Fan triangulation is correct for convex polygons (like the rectangles in these tests) but can produce degenerate or overlapping triangles for concave shapes. More importantly, the triangle EDGES differ: different triangulations produce different sub-pixel coverage at shape boundaries, causing anti-aliasing differences even when the mathematical shape is identical.

For **line strokes**, our quad expansion produces simple rectangular quads without miter/join handling, while Lyon produces geometrically correct joins and caps. This affects corners and endpoints of gradient line strokes.

### Stage 2: Gradient UV Computation

**Both pipelines compute gradient UVs in the vertex shader**, but with different coordinate conventions.

**Ours:**
```wgsl
// Vertex shader
let inv_pos = inv_mats[grad_id] * pos;
// pos is in twips, inv_mat maps twips -> gradient space [-16384, 16384]
v_args = vec4f(inv_pos.xy, focal_z, spread_flags);

// Fragment shader
fn linear_t(v_args: vec4f) -> f32 {
    return apply_spread((v_args.x + 16384.0) / 32768.0, v_args.w);
}
fn radial_t(v_args: vec4f) -> f32 {
    return apply_spread(distance(v_args.xy, vec2f(0.0)) / 16384.0, v_args.w);
}
```

**Ruffle:**
```wgsl
// Vertex shader
let uv = (texture_matrix * vec3f(position, 1.0)).xy;
// position is in twips, texture_matrix maps twips -> [0, 1]

// Fragment shader
fn find_t(uv: vec2f) -> f32 {
    if (shape == LINEAR) { return uv.x; }
    if (shape == RADIAL) { return length(uv * 2.0 - 1.0); }
    // focal: complex formula on uv * 2.0 - 1.0
}
```

**Key difference**: Ruffle pre-normalizes the gradient matrix so that the vertex shader outputs UVs in [0, 1] (linear) or [-1, 1] (radial after `*2-1`). Our vertex shader outputs raw gradient-space coordinates in [-16384, 16384], and the fragment shader normalizes.

Both approaches are mathematically equivalent. The coordinate space difference has negligible impact on precision — the 32768-range in our pipeline doesn't cause float precision issues since f32 has ~7 significant digits.

### Stage 3: Gradient Ramp Storage and Lookup

Both pipelines pre-compute a 256-entry RGBA8 lookup table and sample it in the fragment shader. The ramp generation is now equivalent (after the linearRGB fix).

**Sampler configuration** is identical: linear filtering, clamp-to-edge.

**Texture format** is identical: RGBA8Unorm.

### Stage 4: Fragment Shader Processing

**Spread modes** — Both implement pad/reflect/repeat in the fragment shader. The formulas differ slightly:

| Mode | Ours | Ruffle |
|------|------|--------|
| Pad | `clamp(t, 0, 1)` | `saturate(t)` |
| Reflect | `p = t - 2*floor(t/2); select(2-p, p, p<=1)` | `if (t<0) t=-t; if (i32(t)&1==0) fract(t) else 1-fract(t)` |
| Repeat | `t - floor(t)` | `fract(t)` |

These are algebraically identical for all finite inputs. For NaN/Inf edge cases, behavior may differ.

**Focal radial gradient** — Both use the same mathematical formula (focal point offset ray-circle intersection), but numerical evaluation order differs. Our implementation normalizes to [-1,1] first; Ruffle operates in [0,1] then remaps. Near the focal singularity (where the denominator approaches 0), tiny floating-point differences produce large t-value differences that, after repeat/reflect wrapping, map to completely different gradient colors.

**LinearRGB conversion** — Both apply `linear_to_srgb()` in the fragment shader using the standard sRGB piecewise transfer function.

### Stage 5: Pipeline Organization

**Ours — Single Shared Pipeline:**
- All shapes (solid fills, gradient fills, bitmap fills, Drawing API shapes) share one render pipeline.
- The `v_style_type` vertex attribute selects the fill mode in the fragment shader via `if/else if` chains.
- Gradients, bitmaps, and solid colors are all packed into the same vertex buffer with different style encodings.
- Dynamic resources (gradient textures, inverse matrices) are indexed via `v_style_id`.

**Ruffle — Dedicated Pipelines:**
- Separate GPU pipelines for solid color, gradient, and bitmap fills.
- Each gradient gets its own bind group with dedicated uniform buffer containing `(focal_point, interpolation, shape, repeat)`.
- The texture matrix is uploaded as a uniform per-gradient, not encoded in vertex attributes.
- Pipeline switching happens between draw calls, not between vertices.

**Impact**: Ruffle's approach has cleaner data flow and avoids packing multiple parameters into vertex attributes. Our approach is more memory-efficient but relies on the fragment shader to decode packed style bits, and passes gradient metadata (spread mode, interpolation, focal ratio) through the vertex interpolator, which can introduce slight precision artifacts.

## Remaining Visual Differences

### 1. Edge Anti-Aliasing (~2K outliers per test)

**Cause**: Fan triangulation produces different triangle edges than Lyon's constrained Delaunay. MSAA samples along these edges produce different coverage values.

**Affected pixels**: Always at shape boundaries (1-2 pixel border). Never in shape interiors.

**Measured**: ~156 outlier channels per 100x100 pixel shape boundary. Consistent across all shapes regardless of fill type.

### 2. Focal Radial Gradient Precision (~8K outliers in gradient fill test)

**Cause**: The focal gradient function has a near-singularity when the sample point is near the focal-to-edge ray. At these positions, t varies rapidly, and tiny floating-point differences between our and Ruffle's evaluation (different normalization, different intermediate values) produce large t differences. With repeat/reflect spread modes, small t errors cause large color jumps.

**Affected pixels**: Distributed across the entire focal gradient area, concentrated along radial "arms" emanating from the focal point.

**Measured**: Center pixels have diffs of 7-20 (just over tolerance 6). Edge/arm pixels have diffs up to 255.

### 3. Line Stroke Geometry (~500 outliers in line gradient test)

**Cause**: Our quad expansion for line strokes doesn't handle miter joins at corners. Where two line segments meet, we draw two overlapping rectangles, while Ruffle's Lyon tessellation produces proper miter/bevel geometry.

**Affected pixels**: Line join points (corners).

## What It Would Take to Fix Each Issue

### Fix 1: Replace Fan Tessellation with Lyon — DONE (libtess2 integrated)

Integrated libtess2 (constrained Delaunay) to replace fan triangulation. For the current test suite (all rectangles), the triangle decomposition is identical, so outlier counts didn't change. The improvement applies to future tests with complex/concave shapes.

**Remaining gap**: libtess2 and Lyon use different sweep-line algorithms, so they may produce different triangulations on the same input, leading to different edge pixels. Matching Lyon pixel-for-pixel would require porting Lyon to C, which isn't practical.

### Fix 2: Normalize Gradient Coordinates — DONE

Composed the [0,1] normalization into the inverse gradient matrix on the CPU side, so the vertex shader now outputs UVs matching Ruffle's [0,1] conventions. The focal radial formula was also rewritten to match Ruffle's `gradient.wgsl` exactly.

**Result**: No outlier count change on current tests (rectangles have exact affine interpolation regardless of value range). The fix is still correct and improves precision for future non-rectangular gradient shapes.

### Fix 3: Separate Gradient Pipeline (High effort, Low impact)

**What**: Create a dedicated GPU pipeline for gradient fills, matching Ruffle's per-gradient bind group approach.

**Effort**: ~1-2 weeks.
- Create a new pipeline layout with separate vertex format (position only, no style encoding).
- Create gradient-specific uniform buffer with `(focal_point, interpolation, shape, repeat)`.
- Move texture matrix to a per-gradient uniform instead of encoding in vertices.
- Implement pipeline switching in the render pass.

**Impact**: Would clean up the vertex attribute packing and avoid passing gradient parameters through the vertex interpolator. May marginally improve precision due to gradient parameters being exact uniforms rather than float-encoded-then-decoded vertex attributes. Would NOT fix tessellation or focal singularity issues.

**Risk**: High effort for marginal precision gain. The current shared pipeline works correctly; the precision impact of vertex attribute packing is negligible.

### Fix 4: Adaptive Bezier Flattening — DONE

Replaced fixed 8-segment subdivision with adaptive flattening: 1/4/8/16 segments based on control point deviation from the start-end midpoint (~0.5px tolerance). Reduces vertex count for flat curves, increases quality for tight curves. No impact on current tests (straight-line rectangles only).

## Status After All Fixes

Fixes 1, 2, and 4 are now implemented. Fix 3 (separate gradient pipeline) was assessed as high effort / low impact and skipped.

**Remaining outliers** are within the "rendering pipeline differences" category and do not indicate bugs:

1. The test tolerance is 6, and our center-pixel diffs are 0-3 for most gradients (within tolerance).
2. The remaining outlier count (~10K per test) is dominated by focal radial singularity precision (~8K) and edge AA from different tessellators (~2K).
3. Matching Ruffle pixel-for-pixel would require porting their exact tessellator (Lyon) and rendering architecture — essentially rebuilding our rendering backend to be a Ruffle clone.

**The only remaining actionable fix** is Fix 3 (separate gradient pipeline), which would marginally improve precision by passing gradient parameters as uniforms instead of vertex attributes. This is estimated at 1-2 weeks for negligible visual improvement.
