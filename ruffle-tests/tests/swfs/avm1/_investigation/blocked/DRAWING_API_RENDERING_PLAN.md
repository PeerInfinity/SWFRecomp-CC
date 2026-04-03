# Drawing API Rendering Plan
<!-- TESTS: movieclip_begin_gradient_fill, movieclip_line_gradient_style, mask_with_drawing, movieclip_setmask -->

<!-- PLAN_META
id: DRAWING_API_RENDERING
status: in_progress
phases:
  - id: 1
    name: "Test existing infrastructure in headless mode"
    status: complete
  - id: 2
    name: "Fix gradient type and linearRGB rendering"
    status: complete
  - id: 3
    name: "Remaining anti-aliasing / focal radial precision"
    status: blocked
  - id: 4
    name: "Test all affected tests"
    status: in_progress
dependencies: []
blockers:
  - "Focal radial gradient precision (8689 outliers in movieclip_begin_gradient_fill)"
  - "Edge anti-aliasing differences (10096 outliers in movieclip_setmask at tolerance 0)"
-->

Last updated: 2026-04-03

## Status: MAJOR FIXES APPLIED — Remaining issues are focal radial precision and edge anti-aliasing

### Results Summary

| Test | Before | After | Tolerance | Status |
|------|--------|-------|-----------|--------|
| mask_with_drawing | 0 outliers | 0 outliers | 0 | IMAGE PASS |
| movieclip_begin_gradient_fill | 77089 outliers | 10943 outliers | 6 | 86% improved |
| movieclip_line_gradient_style | 32510 outliers | 6053 outliers | 6 | 81% improved |
| movieclip_setmask | 10096 outliers | 10096 outliers | 0 | Unchanged (edge AA) |

### Bugs Fixed (2026-04-03)

1. **Focal type upgrade for linear gradients**: `beginGradientFill` unconditionally changed gradient_type to 0x13 (focal radial) when focal_ratio was non-zero, even for LINEAR gradients. Fixed to only upgrade radial (0x12) to focal radial (0x13).

2. **Garbage focal values from string args**: `varToDouble("???")` reads raw memory as float instead of converting strings to numbers. Changed to `varToDoubleSimple()` which properly returns NaN for non-numeric strings, then clamp NaN/Inf to 0.

3. **LinearRGB ramp generation mismatch**: Our code stored the gradient ramp in sRGB color space (full-precision sRGB→linear→lerp→sRGB), while Ruffle stores it in linear color space (sRGB→linear u8 truncated→lerp in linear u8→store linear). Fixed to match Ruffle's approach:
   - Ramp generation now stores linear u8 values for linearRGB mode
   - Added `interpolation` flag propagated through DrawPath → DrawingRenderInfo → renderer
   - Vertex shader encodes linearRGB flag in `v_args.w` (bit 2)
   - Fragment shader applies `linear_to_srgb` conversion when flag is set
   - Fixed spread mode extraction to mask off linearRGB bits (`& 0x3u`)

### Remaining Issues

**Focal radial gradient precision** (8689 outliers in movieclip_begin_gradient_fill R2C5):
- Our focal radial gradient computation (`focal_radial_t()` in fragment shader) differs slightly from Ruffle's implementation
- The max diff is 255 at shape edges but the center pixels have diff ~7 (just over tolerance 6)
- Ruffle uses `l / (sqrt(1 - f^2 * dy^2) + f * dx)` while our implementation uses `2A / (-B + sqrt(disc))`
- These are algebraically equivalent but may differ numerically

**Edge anti-aliasing** (10096 outliers in movieclip_setmask):
- All at tolerance 0 (strict pixel match required)
- Differences at shape borders due to different tessellation and rasterization
- Fan triangulation vs Ruffle's triangulator produce different edge pixels

**Line gradient style** (6053 outliers in movieclip_line_gradient_style):
- Similar linearRGB and edge precision issues as the fill gradient test
- Mostly anti-aliasing at line stroke edges

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| Gradient type + focal fix | `action.c` | ~51235-51240, ~51409-51414 |
| LinearRGB ramp generation | `action.c` | ~18625-18695 |
| Interpolation in DrawingRenderInfo | `action.h` | ~493, ~504 |
| Style encoding (spread + interp) | `render_webgpu.c` | ~1758 |
| Vertex shader (interp flag) | `render_webgpu.c` | ~66-79 |
| Fragment shader (linear_to_srgb) | `render_webgpu.c` | ~140-155, ~193-196 |
