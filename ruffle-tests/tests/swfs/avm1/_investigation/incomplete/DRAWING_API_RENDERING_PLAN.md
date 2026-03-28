# Drawing API Rendering Plan
<!-- TESTS: movieclip_begin_gradient_fill, movieclip_line_gradient_style, mask_with_drawing, movieclip_setmask -->

Last updated: 2026-03-27

## Status: NOT STARTED — Tier 3 (infrastructure largely exists, needs headless integration)

### Problem

Shapes drawn via the MovieClip Drawing API (`beginFill`, `moveTo`, `lineTo`, `curveTo`, `endFill`, `beginGradientFill`, `lineGradientStyle`) don't render in headless graphics mode. The drawing commands are stored and tessellated at runtime, but the rendering callbacks may not be wired up in the headless path.

### Affected Image Tests

| Test | Tolerance | Notes |
|------|-----------|-------|
| movieclip_begin_gradient_fill | 6 | Gradient fills via drawing API |
| movieclip_line_gradient_style | 6 | Gradient line styles |
| mask_with_drawing | 6 | Drawing API + masking (also needs setMask) |
| movieclip_setmask | 0 | Drawing API + setMask |

### Current Infrastructure (Surprisingly Complete)

The Drawing API rendering pipeline is almost fully implemented for the WASM/WebGPU graphics mode. The question is whether it works in headless mode too.

#### Drawing Command Storage (`action.h:412-506`)

```c
typedef struct {
    u8 type;           // 0=MOVE_TO, 1=LINE_TO, 2=CURVE_TO
    float x, y;        // endpoint (pixels)
    float cx, cy;      // control point (CURVE_TO only)
} DrawCmd;

typedef struct {
    // Fill state
    float fill_r, fill_g, fill_b, fill_a;
    int has_fill;
    // Line state
    float line_width;
    float line_r, line_g, line_b, line_a;
    int has_line;
    // Gradient fill (256-entry RGBA8 ramp + 4x4 matrix)
    int has_gradient;
    u8 gradient_type;      // 0x10=linear, 0x12=radial, 0x13=focal_radial
    u8 gradient_ramp[256 * 4];
    float gradient_matrix[16];
    // Gradient line style (same format)
    int has_line_gradient;
    // Tessellated output
    float* fill_verts;     // x,y pairs in twips (triangle vertices)
    u32 fill_vert_count;
    float* line_verts;     // x,y pairs in twips (line quad triangles)
    u32 line_vert_count;
} DrawPath;

typedef struct {
    DrawPath* paths;
    u32 path_count, path_capacity;
    float pen_x, pen_y;
    DrawCmd* cmds;
    u32 cmd_count, cmd_capacity;
} DrawingState;
```

Linked via `MovieClip.drawing_state` (void*, lazily allocated).

#### Tessellation (`action.c:17112-17227`)

`drawingFinalizePath()` converts drawing commands to triangle vertices:
1. **Bezier flattening**: CURVE_TO → 8 line segments (fixed subdivision)
2. **Fill tessellation**: Fan triangulation (first vertex common to all triangles), output in twips
3. **Line tessellation**: Quad stroke expansion (2 triangles per segment with normal offset)

#### GPU Upload (`render_webgpu.c:1566-1709`)

Two functions handle upload:

- **`render_webgpu_draw_tris()`** (line 1566): Solid fills — allocates dynamic color slot, builds vertex array (u32[4] per vertex: x, y, style_type=0x00, color_idx), uploads to GPU vertex buffer, draws
- **`render_webgpu_draw_gradient_tris()`** (line 1640): Gradient fills — allocates gradient layer, uploads 256-entry ramp texture, computes inverse matrix, builds vertices with gradient style encoding

#### Rendering Callbacks (`tag.c:1652-1681`)

```c
static void render_drawing_path(const DrawingRenderInfo* info) {
    if (info->fill_count > 0) {
        if (info->has_gradient)
            renderer_draw_gradient_tris(context, ...);
        else
            renderer_draw_tris(context, ...);
    }
    if (info->line_count > 0) { /* similar */ }
}
```

#### Integration in Render Pass (`tag.c:1893-1895, 2333-2334`)

```c
actionIterateDrawings(drawing_render_cb, NULL);          // unmasked drawings
actionIterateMaskedDrawings(masked_drawing_render_cb, NULL);  // masked drawings
```

These calls are already in `tagShowFrame()`.

#### Pre-allocated GPU Resources

| Resource | Static Size | Dynamic Overhead | Max Dynamic |
|----------|------------|------------------|-------------|
| vertex_buffer | shape_data_size | MAX_DYNAMIC_VERTICES × 16 bytes | 8192 vertices |
| color_buffer | color_data_size | MAX_DYNAMIC_RECTS × 16 bytes | dynamic rects |
| gradient_tex | num_gradients layers | MAX_DYNAMIC_GRADIENTS layers | 64 gradients |
| inv_mat_buffer | static_mats × 64 bytes | MAX_DYNAMIC_GRADIENTS × 64 bytes | 64 matrices |

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| DrawCmd/DrawPath/DrawingState structs | `action.h` | 412-506 |
| Drawing API functions (moveTo, lineTo, etc.) | `action.c` | 47370-47779 |
| Tessellation (drawingFinalizePath) | `action.c` | 17112-17227 |
| Gradient ramp generation | `action.c` | 17015-17073 |
| GPU upload (solid fills) | `render_webgpu.c` | 1566-1609 |
| GPU upload (gradient fills) | `render_webgpu.c` | 1640-1709 |
| Rendering callbacks | `tag.c` | 1652-1681 |
| Render pass integration | `tag.c` | 1893-1895, 2333-2334 |
| Iteration functions | `action.c` | ~17290-17336 |

### What's Missing / To Investigate

#### Issue 1: Headless Mode Guards

The drawing iteration and rendering callbacks are in `tag.c`, which compiles for both graphics and headless modes. However, some paths may be behind `#ifndef NO_GRAPHICS` or similar guards. Need to verify that:
- `actionIterateDrawings()` is called in headless render pass
- `renderer_draw_tris()` and `renderer_draw_gradient_tris()` work in headless mode
- The dynamic vertex/color/gradient GPU resources are initialized in headless mode

#### Issue 2: Per-Frame Dynamic Resource Reset

Dynamic vertex/color/gradient counters (`dynamic_vertex_used`, `dynamic_rect_count`, `dynamic_gradient_used`) need to be reset each frame. Verify this happens in the headless frame loop.

#### Issue 3: Vertex Capacity

MAX_DYNAMIC_VERTICES = 8192 may be tight for complex drawings. The gradient fill tests likely have moderate vertex counts, but `mask_with_drawing` could be more complex.

### Implementation Plan

#### Step 1: Test Existing Infrastructure

Run the drawing API image tests and check what happens:
```bash
python3 ruffle-tests/verify_output.py --test=movieclip_begin_gradient_fill --headless --diff --verbose
```

If the infrastructure is already wired up for headless, this may already produce output (or produce errors that indicate what's missing).

#### Step 2: Fix Headless Guards (if needed)

If drawing iteration or GPU upload functions are behind `NO_GRAPHICS` guards, add headless-compatible code paths. The headless mode uses the same WebGPU rendering pipeline as full graphics mode, so the same functions should work.

#### Step 3: Verify Gradient Rendering

Gradient fills require:
1. Gradient ramp texture upload (256×1 RGBA8 per gradient)
2. Inverse gradient matrix upload
3. Correct style type encoding in vertex data (0x10/0x12/0x13)

Verify the fragment shader handles gradient lookups correctly when the gradient comes from a dynamic layer (static_gradient_count + dynamic offset).

#### Step 4: Test All 4 Affected Tests

After fixes, run all 4 tests. `mask_with_drawing` and `movieclip_setmask` also need runtime setMask() support (see RUNTIME_SETMASK_PLAN.md).

### Dependencies

- `mask_with_drawing` and `movieclip_setmask` also depend on RUNTIME_SETMASK_PLAN.md
- No other dependencies — the Drawing API trace functionality is fully working

### Estimated Complexity

Low-medium. Most infrastructure exists. Main work is:
1. Verifying headless integration works (~2 hours investigation)
2. Fixing any guards or missing initialization (~30 lines)
3. Testing and debugging gradient rendering (~2 hours)
