# Plan 03: Drawing API Rendering

<!-- PLAN_META
id: PLAN_03_DRAWING_API
status: complete
phases:
  - id: 1
    name: "Solid Fill Polygons — **"
    status: complete
  - id: 2
    name: "Curve Segments — **"
    status: complete
  - id: 3
    name: "Gradient Fills — **"
    status: complete
  - id: 4
    name: "Line Styles — **"
    status: complete
dependencies:
  - plan: PLAN_01_RUNTIME_TRANSFORMS
    type: requires
    reason: "Drawing API rendering needs GPU transform pipeline"
blockers: []
-->

**Priority**: Medium — unlocks 4 tests, fundamental capability
**Tests unlocked**: `movieclip_begin_gradient_fill` (tolerance=6), `movieclip_line_gradient_style` (tolerance=6), `mask_with_drawing` (tolerance=6), `movieclip_setmask` (tolerance=0)
**Estimated complexity**: Large
**Depends on**: Plan 01 (runtime transforms)
**Status**: **ALL PHASES COMPLETE**. All 4 tests pass: `movieclip_setmask`, `movieclip_begin_gradient_fill`, `movieclip_line_gradient_style`, `mask_with_drawing`. Also `mask_reapply` passes (clip_depth sprite mask support added — `actionIterateDrawings` skips MCs whose DisplayObject has `clip_depth > 0`).

---

## Problem

ActionScript's Drawing API (`beginFill`, `beginGradientFill`, `moveTo`, `lineTo`, `curveTo`, `endFill`, `lineStyle`, `lineGradientStyle`) creates shapes at runtime. These shapes exist as path data on the MovieClip but are never converted to renderable geometry.

---

## Current State

### What Exists

The runtime tracks drawing commands in NO_GRAPHICS mode:

- **MovieClip fields** (`action.h`): `draw_xmin`, `draw_xmax`, `draw_ymin`, `draw_ymax` — bounding box of drawn content
- **Drawing state**: The Drawing API methods (`actionMCBeginFill`, `actionMCMoveTo`, `actionMCLineTo`, `actionMCCurveTo`, `actionMCEndFill`) execute but only update bounds and trace-visible state
- **No path storage**: The actual path data (moveTo/lineTo/curveTo commands) is NOT currently stored — it's processed for bounds only

### What's Needed

1. **Path storage**: Record all drawing commands (moveTo, lineTo, curveTo) with their coordinates
2. **Tessellation**: Convert paths to triangle meshes (similar to what the recompiler does for DefineShape tags)
3. **GPU upload**: Write tessellated vertices to the GPU vertex buffer
4. **Color/gradient handling**: Fill colors and gradient fills need color buffer entries
5. **Line rendering**: Stroke paths with line styles (solid + gradient)

---

## Architecture

### Path Recording

Add a path recording structure to MovieClip:

```c
typedef enum {
    DRAW_CMD_MOVE_TO,
    DRAW_CMD_LINE_TO,
    DRAW_CMD_CURVE_TO,  // quadratic bezier
} DrawCmdType;

typedef struct {
    DrawCmdType type;
    float x, y;         // endpoint
    float cx, cy;       // control point (curve_to only)
} DrawCmd;

typedef struct {
    float fill_r, fill_g, fill_b, fill_a;  // solid fill color
    int has_fill;
    // gradient fill data (future)
    DrawCmd* commands;
    size_t cmd_count;
    size_t cmd_capacity;
} DrawPath;

typedef struct {
    DrawPath* paths;
    size_t path_count;
    size_t path_capacity;
    int dirty;  // set when new commands added, cleared after GPU upload
} DrawingState;
```

### Tessellation

Convert paths to triangle strips. For simple convex shapes (most common in Flash), a fan tessellation from the first vertex works. For complex/concave shapes, a more robust approach is needed.

**Simple approach (Phase 1)**: Use ear-clipping triangulation for filled paths. This handles convex and simple concave polygons.

**Advanced approach (Phase 2)**: Use the same tessellation the recompiler uses (it already converts DefineShape to triangle lists). Port that logic to C for runtime use.

### GPU Upload

Use the same dynamic slot approach as Plan 01:
- Reserve a region in the vertex buffer for dynamic drawing vertices
- Reserve color buffer slots for fill colors
- Allocate transform slots for drawing object transforms

---

## Implementation Phases

### Phase 1: Solid Fill Polygons — **COMPLETE**

Handle `beginFill()` + `moveTo()`/`lineTo()` + `endFill()` — solid color filled polygons with straight edges only.

1. ✅ Store path commands in MovieClip's DrawingState (`DrawCmd`, `DrawPath`, `DrawingState` structs in action.h)
2. ✅ On `endFill()`, tessellate the polygon into triangles (fan tessellation in `drawingFinalizePath`)
3. ✅ Before render pass, upload tessellated vertices to GPU (`renderer_draw_tris` in tag.c `drawing_render_cb`)
4. ✅ Draw using `renderer_draw_tris()` with dynamic vertex/color slots

### Phase 2: Curve Segments — **COMPLETE**

Handle `curveTo()` — quadratic Bezier curves. Flatten to 8 line segments per curve in `drawingFinalizePath`.

### Phase 3: Gradient Fills — **COMPLETE**

Handle `beginGradientFill()` and `lineGradientStyle()` — linear and radial gradients.

**Implementation**:
- `drawingGenerateGradientRamp()`: 256-entry RGBA8 lookup from color stops, with sRGB↔linear for linearRGB mode
- `drawingBuildGradientBoxMatrix()` / `drawingBuildGradientAbcdMatrix()`: Matrix builders for box and ABCD matrix formats
- `render_webgpu_draw_gradient_tris()`: Uploads gradient ramp to texture array layer, computes inverse matrix on CPU, builds vertices with style encoding (gradient_type | spread_mode<<8, grad_id | focal_encoded<<16)
- Over-allocated gradient texture + inv_mat_buffer with 64 dynamic slots at init time
- Key bug fixed: `getProperty()` only works on `ASObject*`, not `ASArray*`. Array args (colors, alphas, ratios) must use `ASArray->length` and `ASArray->elements[]` directly.
- `beginGradientFill(undefined, ...)` clears fill regardless of arg count (checked before too-many-args validation)

**Tests helped**: `movieclip_begin_gradient_fill` (trace PASS, image near-match), `movieclip_line_gradient_style`

### Phase 4: Line Styles — **COMPLETE**

Handle `lineStyle()` and `lineGradientStyle()` — stroke rendering. Strokes expanded to filled quads (2 triangles per segment) with normal-based offset in `drawingFinalizePath`. `lineGradientStyle()` uses same gradient infrastructure as Phase 3.

---

## Tessellation Detail

### Ear-Clipping Algorithm

For Phase 1, implement a simple ear-clipping triangulator:

```c
// Input: array of 2D vertices forming a closed polygon
// Output: array of triangle indices
int tessellate_polygon(const float* verts, size_t vert_count,
                       u32** out_indices, size_t* out_tri_count);
```

This handles:
- Convex polygons (trivially)
- Simple concave polygons (most Flash drawings)
- Does NOT handle: self-intersecting polygons, holes

### Bezier Flattening

For Phase 2, flatten quadratic Bezier curves to line segments:

```c
void flatten_bezier(float x0, float y0,    // start
                    float cx, float cy,     // control
                    float x1, float y1,     // end
                    float tolerance,         // flatness threshold
                    DrawPath* path);         // output line segments
```

Use recursive subdivision: split at midpoint until the control point is within `tolerance` of the straight line.

---

## File Changes Summary

| File | Change |
|------|--------|
| `SWFModernRuntime/include/actionmodern/action.h` | Add DrawingState, DrawPath, DrawCmd structs to MovieClip |
| `SWFModernRuntime/src/actionmodern/action.c` | Update Drawing API methods to record path commands |
| `SWFModernRuntime/src/libswf/tag.c` | Add drawing tessellation + GPU upload before render pass |
| `SWFModernRuntime/src/rendering/render_webgpu.c` | Reserve dynamic vertex/color buffer regions |

---

## Risks / Open Questions

1. **Vertex buffer sizing**: How many dynamic vertices to reserve? Flash drawings can be arbitrarily complex. Start with 64K vertices and grow if needed.

2. **Performance**: Tessellation per frame could be expensive. Cache tessellated results and only re-tessellate when `dirty` flag is set.

3. **Winding rule**: Flash uses even-odd fill rule. Ear-clipping naturally produces correct results for simple polygons but may need adjustment for complex shapes.

4. **Recompiler tessellation reuse**: The recompiler already tessellates DefineShape tags. Could that code be ported to C and reused at runtime? It handles all shape types including curves, gradients, and complex fills.

5. **Mask interaction**: `movieclip_setmask` and `mask_with_drawing` use drawn shapes as masks. The mask rendering system already exists (stencil-based) but needs to work with dynamically drawn shapes.
