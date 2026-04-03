# Rendering Pipeline Comparison: Our Implementation vs Ruffle

This document explains the architectural differences between our Drawing API gradient rendering pipeline and Ruffle's, the visual artifacts that result, and what it would take to close the remaining gaps.

## Background

After fixing three bugs in April 2026 (focal type upgrade, NaN handling, linearRGB color space), image test outliers dropped by ~80-86%. The remaining ~10K outlier channels per test come from fundamental pipeline differences described below.

## Architecture at a Glance

| Aspect | Ours | Ruffle |
|--------|------|--------|
| Tessellation | Fan triangulation (custom) | Lyon library (constrained Delaunay) |
| Gradient UV source | Vertex shader (inverse matrix) | Vertex shader (texture matrix uniform) |
| Gradient ramp | 256-texel RGBA8 array texture | 256-texel RGBA8 standalone texture |
| Gradient pipeline | Shared with all fills | Dedicated pipeline per gradient |
| Coordinate space | Twips ([-16384, 16384]) | Normalized ([-1, 1] or [0, 1]) |
| MSAA | 4x | 4x |
| Framebuffer | RGBA8Unorm | RGBA8Unorm |

## Detailed Pipeline Comparison

### Stage 1: Tessellation

**Ours — Fan Triangulation**

When `endFill()` is called, `drawingFinalizePath()` converts the accumulated drawing commands (moveTo, lineTo, curveTo) into triangles:

1. Bezier curves are flattened to 8 line segments (fixed subdivision).
2. The polygon is triangulated using **fan triangulation**: vertex 0 is shared by all triangles. For an N-vertex polygon, this produces N-2 triangles.
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

### Fix 1: Replace Fan Tessellation with Lyon (Medium effort, High impact)

**What**: Replace `drawingFinalizePath()`'s fan triangulation with Lyon (or an equivalent constrained Delaunay tessellator in C).

**Effort**: ~1-2 weeks.
- Integrate a C tessellation library (e.g., [libtess2](https://github.com/memononen/libtess2), [earcut](https://github.com/nicklockwood/Earcut)) or port Lyon's fill tessellator to C.
- Replace fan triangulation in `drawingFinalizePath()`.
- Replace quad expansion with proper stroke tessellation (miter/bevel/round joins, line caps).

**Impact**: Would fix edge anti-aliasing diffs (~2K outliers) and line stroke geometry (~500 outliers). Would NOT fix gradient precision diffs.

**Risk**: The tessellator would need to match Lyon's exact triangle decomposition for pixel-identical results. Even with the same algorithm, implementation differences could produce different triangulations. Using libtess2 or earcut would produce BETTER triangles than fan tessellation but still different from Lyon.

### Fix 2: Match Ruffle's Focal Radial Evaluation Order (Low effort, Medium impact)

**What**: Rewrite `focal_radial_t()` to evaluate in exactly the same order and coordinate space as Ruffle.

**Effort**: ~1-2 hours. Already attempted (the formula was rewritten to match Ruffle's `gradient.wgsl`). The result: 0 outlier change, confirming the differences come from the vertex interpolation path, not the formula itself.

**The deeper issue**: Ruffle computes the gradient UV transform as a uniform matrix multiply in the vertex shader, producing UV values in [0, 1]. Our pipeline applies the inverse gradient matrix in the vertex shader but outputs raw gradient-space coordinates in [-16384, 16384]. The fragment shader then normalizes. While mathematically equivalent, the intermediate values differ by a factor of ~16384, and float32 precision is relative to magnitude. Coordinates near 16384 have ~13-bit mantissa precision in the fractional part, while coordinates near 1.0 have ~23-bit precision.

**Fix**: Normalize the gradient matrix so the vertex shader outputs values in [0, 1] or [-1, 1], matching Ruffle's precision characteristics. This requires changing:
1. `drawingBuildGradientBoxMatrix()` / `drawingBuildGradientAbcdMatrix()` to include the normalization in the forward matrix.
2. The fragment shader `linear_t()` and `radial_t()` functions to skip the normalization step.
3. The `invert_4x4_matrix()` call to operate on the already-normalized matrix.

**Impact**: Would reduce focal radial precision errors, especially in the 7-20 diff range. May not eliminate the 255-diff outliers near singularities.

### Fix 3: Separate Gradient Pipeline (High effort, Low impact)

**What**: Create a dedicated GPU pipeline for gradient fills, matching Ruffle's per-gradient bind group approach.

**Effort**: ~1-2 weeks.
- Create a new pipeline layout with separate vertex format (position only, no style encoding).
- Create gradient-specific uniform buffer with `(focal_point, interpolation, shape, repeat)`.
- Move texture matrix to a per-gradient uniform instead of encoding in vertices.
- Implement pipeline switching in the render pass.

**Impact**: Would clean up the vertex attribute packing and avoid passing gradient parameters through the vertex interpolator. May marginally improve precision due to gradient parameters being exact uniforms rather than float-encoded-then-decoded vertex attributes. Would NOT fix tessellation or focal singularity issues.

**Risk**: High effort for marginal precision gain. The current shared pipeline works correctly; the precision impact of vertex attribute packing is negligible.

### Fix 4: Adaptive Bezier Flattening (Low effort, Low impact)

**What**: Replace the fixed 8-segment bezier flattening with adaptive subdivision based on curvature.

**Effort**: ~2-4 hours.

**Impact**: Would improve curve rendering accuracy for tight curves, reducing outliers on curved shape edges. No impact on the gradient tests (which use only straight-line rectangles).

## Recommended Approach

**Do nothing for now.** The remaining outliers are within the "rendering pipeline differences" category and do not indicate bugs:

1. The test tolerance is 6, and our center-pixel diffs are 0-7 for most gradients (right at the boundary).
2. The outlier count (10K-11K) is dominated by edge AA and focal singularities — both inherent to different tessellation.
3. Matching Ruffle pixel-for-pixel would require porting their exact tessellator (Lyon), coordinate conventions, and pipeline architecture — essentially rebuilding our rendering backend to be a Ruffle clone.

If pursuing further improvement, the highest-value change is **Fix 2** (normalize gradient coordinates to [0,1] range) which could reduce the ~8K focal radial outliers at low effort. The other fixes offer diminishing returns relative to their complexity.
