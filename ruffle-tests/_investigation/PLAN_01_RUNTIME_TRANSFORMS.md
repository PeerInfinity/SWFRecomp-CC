# Plan 01: Runtime Transform & CxForm GPU Updates

**Priority**: Highest — pure bug fix, no new features
**Tests unlocked**: `display_object_properties` (tolerance=90), `color` (tolerance=1)
**Estimated complexity**: Medium

---

## Problem

When ActionScript modifies display object properties at runtime (`_x`, `_y`, `_xscale`, `_yscale`, `_rotation`, or `Color.setRGB()`/`Color.setTransform()`), the changes are stored on the MovieClip/DisplayObject structs but **never written back to the GPU buffers**. The renderer still uses the original static `transform_data` and `cxform_data` from the recompiler.

### Evidence
- **`display_object_properties`**: Green diamond renders with correct shape/color/rotation but at wrong position (script sets `_x`/`_y` at runtime)
- **`color`**: Three rectangles render as grey instead of pink/yellow/blue (script calls `Color.setRGB()` at runtime)

---

## Part A: Runtime Transform Updates

### Current Data Flow
```
Recompiler → transform_data[N] → GPU xform_buffer[N]
                                   ↑ uploaded once at init
ActionScript → mc.x, mc.y, mc.xscale, mc.yscale, mc.rotation
                                   ↑ stored on MovieClip, never sent to GPU
```

### Target Data Flow
```
Before each render pass:
  For each display object in the display list:
    If its MovieClip has as_set_flags != 0 (AS-modified properties):
      Build a 4x4 matrix from mc.x, mc.y, mc.xscale, mc.yscale, mc.rotation
      Write to GPU xform_buffer at a dynamic slot
      Update display object's transform_id to point to the new slot
```

### Implementation Steps

#### Step 1: Build transform matrix from MC properties

Add a function in `tag.c` or `tag_stubs.c`:

```c
static void build_transform_from_mc(float out[16], const MovieClip* mc)
{
    // mc.x, mc.y are in pixels (twips for textfields)
    // mc.xscale, mc.yscale are percentages (100.0 = 1x)
    // mc.rotation is in degrees
    float tx = mc->x * 20.0f;  // convert pixels to twips
    float ty = mc->y * 20.0f;
    float sx = mc->xscale / 100.0f;
    float sy = mc->yscale / 100.0f;
    float rad = mc->rotation * (float)M_PI / 180.0f;
    float c = cosf(rad), s = sinf(rad);

    // Column-major 4x4 matrix (matching transform_data layout)
    out[0]  = sx * c;   out[1]  = sx * s;   out[2]  = 0; out[3]  = 0;
    out[4]  = sy * -s;  out[5]  = sy * c;   out[6]  = 0; out[7]  = 0;
    out[8]  = 0;        out[9]  = 0;        out[10] = 1; out[11] = 0;
    out[12] = tx;       out[13] = ty;       out[14] = 0; out[15] = 1;
}
```

**Key detail**: The `transform_data` stores translation in twips (elements [12],[13]). MovieClip `x`/`y` are in pixels for sprites but may need special handling for textfields.

**Key detail**: Need to verify the matrix layout matches what `ng_getTransformScaleRotation()` expects (see `tag_stubs.c:1984-2021`). That function extracts `xscale = sqrt(m00^2 + m10^2)` and `rotation = atan2(m10, m00)`, which matches the layout above.

#### Step 2: Apply runtime transforms before render pass

In `tagShowFrame()` in `tag.c`, add a new loop **before** the existing compose loop (line ~1387). This loop walks the display list and, for any entry whose MovieClip has `as_set_flags != 0`, builds a fresh transform matrix and writes it to the GPU:

```c
// NEW: Apply runtime AS-modified transforms to GPU buffer
for (size_t i = 1; i <= max_depth; ++i)
{
    DisplayObject* obj = &display_list[i];
    if (obj->char_id == 0) continue;
    MovieClip* mc = obj->display_obj;
    if (mc == NULL || mc->as_set_flags == 0) continue;

    float mat[16];
    build_transform_from_mc(mat, mc);
    // Write to original transform_id slot (or allocate dynamic)
    renderer_write_transform(context, obj->transform_id, mat);
}
```

**Alternative**: Write to the original slot in `transform_data` (CPU-side) so that `compose_children` picks it up naturally. This avoids needing extra GPU writes:

```c
float* slot = (float*)app_context->transform_data + obj->transform_id * 16;
build_transform_from_mc(slot, mc);
// compose_children will then read the updated slot and write to GPU
```

This approach is simpler because `compose_children` already handles uploading composed transforms. The CPU-side `transform_data` becomes mutable (it already is — the array is in writable memory).

#### Step 3: Handle display objects without associated MovieClips

Not all display objects have a `display_obj` (MovieClip). Shapes at the root level don't. The loop should skip entries where `display_obj == NULL`.

For sprites, the sprite itself has a transform, and its children have their own transforms. The sprite's transform is the one that needs updating. Its children's transforms inside the sprite are already handled by `compose_children`.

#### Step 4: Handle the `_alpha` property

`_alpha` is stored as a percentage on the MovieClip (100 = fully opaque). It affects the alpha multiplier of the cxform. This bridges Part A and Part B — when `_alpha` changes, the cxform needs updating too.

---

## Part B: Runtime CxForm Updates

### Current Data Flow
```
Recompiler → cxform_data[N*20] → GPU cxform_buffer[N*20]
                                   ↑ uploaded once at init
Color.setRGB() → DisplayObject.cx_ra/rb/ga/gb/ba/bb/aa/ab
                  DisplayObject.cx_overridden = 1
                                   ↑ stored, never sent to GPU
```

### Target Data Flow
```
Before each render pass:
  For each display object with cx_overridden == 1:
    Build 20-float cxform entry from cx_* fields
    Write to GPU cxform_buffer at a dynamic slot
    Update display object's cxform_id to point to the new slot
```

### Implementation Steps

#### Step 1: Build cxform data from DisplayObject cx_* fields

Add a function:

```c
static void build_cxform_from_obj(float out[20], const DisplayObject* obj)
{
    // cx_ra/ga/ba/aa are percentages (100.0 = 1x)
    // cx_rb/gb/bb/ab are addends (0-255 range)
    // GPU format: 4x4 diagonal matrix + 4-element add vector

    // Zero the matrix
    memset(out, 0, 20 * sizeof(float));

    // Diagonal multipliers (convert from percentage to 0-1 range)
    out[0]  = (float)(obj->cx_ra / 100.0);  // R mult
    out[5]  = (float)(obj->cx_ga / 100.0);  // G mult
    out[10] = (float)(obj->cx_ba / 100.0);  // B mult
    out[15] = (float)(obj->cx_aa / 100.0);  // A mult

    // Additive offsets (convert from 0-255 to 0-1 range)
    out[16] = (float)(obj->cx_rb / 255.0);  // R add
    out[17] = (float)(obj->cx_gb / 255.0);  // G add
    out[18] = (float)(obj->cx_bb / 255.0);  // B add
    out[19] = (float)(obj->cx_ab / 255.0);  // A add
}
```

**Verification**: Compare this with `ng_init_cxform_from_data()` (tag_stubs.c:1499-1510) which does the reverse conversion. The round-trip should be identity (modulo quantization).

#### Step 2: Dynamic cxform slot allocation

Similar to the dynamic transform slot system, the `cxform_buffer` needs extra capacity:

1. **Over-allocate cxform_buffer** in `render_webgpu.c`:
   - Add `cxform_slot_count` field to `WebGPURenderContext`
   - Allocate original size + 256 extra slots (256 * 20 * 4 = 20KB)

2. **Add cxform slot allocator** in `tag.c`:
   - `g_next_dynamic_cxform_slot` counter
   - `cxform_overrides[]` save/restore stack (same pattern as xform)

#### Step 3: Apply runtime cxforms before render pass

In `tagShowFrame()`, after the transform update loop, add a cxform update loop:

```c
// NEW: Apply runtime Color-modified cxforms to GPU buffer
for (size_t i = 1; i <= max_depth; ++i)
{
    DisplayObject* obj = &display_list[i];
    if (obj->char_id == 0) continue;
    if (!obj->cx_overridden) continue;

    float cx[20];
    build_cxform_from_obj(cx, obj);

    u32 new_slot = g_next_dynamic_cxform_slot++;
    cxform_overrides_push(obj, obj->cxform_id);
    obj->cxform_id = new_slot;

    // Write 20 floats = 5 vec4f to GPU
    size_t offset = (size_t)new_slot * 20 * sizeof(float);
    wgpuQueueWriteBuffer(context->queue, context->cxform_buffer,
                         offset, cx, 20 * sizeof(float));
}
```

#### Step 4: Propagate parent cxform to sprite children

In Flash, a parent's color transform composes with its children's color transforms. When a sprite has `cx_overridden=1`, all its children should be rendered with `parent_cxform * child_cxform`.

**For initial implementation**: Skip cxform composition (handle only root-level cx changes). This is sufficient for the `color` test where the sprites with Color changes are at the root level.

**Future**: Add cxform composition in `compose_children()`, similar to how transform composition works. The cxform composition is: `result_mult = parent_mult * child_mult`, `result_add = parent_add * child_mult + child_add` (component-wise).

---

## Testing Strategy

1. **`display_object_properties`** (tolerance=90): The script sets `_x` and `_y` to move a green diamond to the right side. With Part A, the diamond should render at the correct position. The high tolerance means even imprecise positioning should pass.

2. **`color`** (tolerance=1): The script calls `Color.setRGB()` on three sprites. With Part B, the rectangles should render with correct colors. The tolerance of 1 means colors need to be nearly exact.

3. **Regression**: Run existing old test suite to ensure non-headless mode isn't affected (the transform update loop should be gated by `#if !defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)`).

---

## File Changes Summary

| File | Change |
|------|--------|
| `SWFModernRuntime/src/libswf/tag.c` | Add `build_transform_from_mc()`, `build_cxform_from_obj()`, runtime update loops in `tagShowFrame()`, dynamic cxform slot allocator |
| `SWFModernRuntime/src/rendering/render_webgpu.c` | Over-allocate `cxform_buffer` with extra capacity |
| `SWFModernRuntime/include/rendering/render_webgpu.h` | Add `cxform_slot_count` field |

---

## Risks / Open Questions

1. **Twips vs pixels**: MovieClip `x`/`y` store values in pixels (from `_x`/`_y` setter which does twip-snapping). The transform matrix stores translation in twips. Need to multiply by 20 when building the matrix.

2. **TextField position handling**: TextFields may store `x`/`y` differently from sprites. `MC_IS_TEXTFIELD` check may be needed.

3. **Compose order**: The runtime transform update must happen BEFORE `compose_children` so that the composed transforms use the updated values. The cxform update must happen BEFORE the render pass.

4. **`_alpha` bridging**: When `_alpha` is set but no `Color` object is used, `cx_overridden` may be 0. Need to also check for alpha changes. The alpha property modifies `cx_aa` — check if the setter sets `cx_overridden`.

5. **Performance**: Walking the entire display list to check `as_set_flags` adds overhead per frame. For the headless test pipeline this is fine; for the browser renderer it should also be negligible since display lists are small.
