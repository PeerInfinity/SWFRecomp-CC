# Runtime Transform GPU Updates Plan
<!-- TESTS: display_object_properties, color -->

<!-- PLAN_META
id: RUNTIME_TRANSFORM_GPU
status: completed
phases:
  - id: 1
    name: "Build transform matrix from MovieClip properties"
    status: completed
  - id: 2
    name: "Detect runtime-modified transforms in compose_children"
    status: completed
  - id: 3
    name: "Handle non-sprite display objects"
    status: completed
  - id: 4
    name: "Test with display_object_properties"
    status: completed
dependencies: []
blockers: []
-->

Last updated: 2026-05-14

## Status: COMPLETED — both Tier 1 image tests pass under `--mode=graphics`

Phases 1-3 were implemented incrementally before this plan doc was revisited.
The infrastructure now lives in `SWFModernRuntime/src/libswf/tag.c`:

- `apply_as_transform()` (tag.c ~1266): rebuilds a 4x4 transform from
  `mc->x`/`y`/`xscale`/`yscale`/`rotation`/`skew` whenever `mc->as_set_flags`
  is non-zero. Mirrors `getLocalMatrixForMC` in action.c so the round-trip
  through `transform.matrix = ...` reproduces the same matrix.
- The runtime transform update loop in both `tagShowFrame` (~tag.c:3220)
  and `tagRerenderFrame` (~tag.c:2830) walks `display_list[i]`, calls
  `actionFindMovieClipByName` to get the MC, and rewrites the GPU slot via
  `renderer_write_transform`. `compose_children` then propagates the
  modified parent transform to nested sprite/text/morph children.
- The cxform runtime-update loop in the same blocks handles the
  `color` test (also depends on `RUNTIME_CXFORM_GPU_PLAN`).

### Final Phase 1 fix (2026-05-14)

`apply_as_transform` previously ignored `mc->skew`. `transformMatrixSetter`
in action.c decomposes a non-rotation-only `Matrix` into
`xscale/yscale/rotation/skew` (skew = `atan2(-c,d) - atan2(b,a)`), so any
`transform.matrix = new Matrix(2, -1.3, 2.4, 1, ...)` with shear was being
reconstructed as a pure rotation. Added the `cos(rad+skew)`/`sin(rad+skew)`
terms for the c/d components to match `getLocalMatrixForMC`.

### Out of scope — separate follow-up

`from_gnash/misc-ming.all/BeginBitmapFill` mc2 still doesn't pick up its
`transform.matrix`. Root cause: mc2 is created by `createEmptyMovieClip`
(dynamic MC, not in `display_list`), and its Drawing API paths render via
`actionIterateDrawings` → `render_drawing_path` using
`mc->last_transform_id`. The runtime transform update loop in tag.c only
iterates `display_list[i]`, so dynamic MCs are never touched. Needs a
separate dynamic-MC drawing transform path. Tracked separately.

### Problem

When ActionScript sets `_x`, `_y`, `_xscale`, `_yscale`, or `_rotation` on a MovieClip at runtime, the changes are stored on the MovieClip struct but never propagated to the GPU transform buffer. The headless renderer draws shapes at their static timeline positions, ignoring runtime position/scale/rotation changes.

### Affected Image Tests

| Test | Tolerance | Notes |
|------|-----------|-------|
| display_object_properties | 90 | Green diamond renders correctly but at wrong position |
| color | 1 | 3rd rectangle placed at runtime doesn't appear (also needs cxform fix) |

Many other image tests will benefit once runtime transforms work, but these two are the Tier 1 targets.

### Root Cause Analysis

**Data flow today:**

1. `transform_data` (static C array) is uploaded to GPU `xform_buffer` once at init (`render_webgpu.c:667-679`)
2. `compose_children()` in `tag.c:969-1020` reads transforms from the **static** `app_context->transform_data` array via `obj->transform_id * 16`
3. Runtime property setters (`action.c:31308-31340`) update `mc->x`, `mc->y`, `mc->xscale`, `mc->yscale`, `mc->rotation` and set `mc->as_set_flags` bitmask, but do NOT update the GPU buffer

**What `_alpha` does right (and transforms don't):**

The `_alpha` setter (`action.c:31342-31356`) calls `ng_setCTAlpha()` to sync the display object's `cx_aa` field. The per-frame render loop in `tag.c:1725-1738` then detects `cx_overridden` and uploads the new cxform to the GPU. No equivalent sync path exists for spatial transforms.

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| GPU buffer init (xform) | `SWFModernRuntime/src/rendering/render_webgpu.c` | 667-679 |
| GPU write function | `render_webgpu.c` | `render_webgpu_write_transform()` |
| compose_children (reads static data) | `SWFModernRuntime/src/libswf/tag.c` | 969-1020 |
| Dynamic slot allocation | `tag.c` | 987-996 |
| _x/_y setters (primary) | `SWFModernRuntime/src/actionmodern/action.c` | 31308-31340 |
| _x/_y setters (secondary) | `action.c` | 37384-37417 (`setMCBuiltinProperty`) |
| _x/_y setters (tertiary) | `action.c` | 26818-26835 (SetVariable path) |
| as_set_flags bitmask | `action.h` | MovieClip struct, line ~56 |
| DisplayObject.transform_id | `swf.h` | line ~114 |
| MovieClip fields | `action.h` | lines 19-74 (x, y, xscale, yscale, rotation, alpha) |

### Data Structures

**MovieClip** (`action.h:19-74`):
- `float x, y` — position in twips
- `float xscale, yscale` — scale as percentage (100 = 1x)
- `float rotation` — degrees
- `u8 as_set_flags` — bitmask: bit0=_x, bit1=_y, bit2=_xscale, bit3=_yscale, bit4=_rotation
- `u32 last_transform_id` — last synced transform slot
- `void* display_obj` — pointer to DisplayObject entry (if in display list)

**DisplayObject** (`swf.h:~114`):
- `u32 transform_id` — index into transform_data[]/xform_buffer (16 floats per slot)

**GPU buffer**: 16 floats per slot (4x4 column-major matrix). Over-allocated with 512 extra dynamic slots.

### Implementation Plan

#### Step 1: Build transform matrix from MovieClip properties

Add a function to reconstruct a 4x4 transform matrix from the current `mc->x`, `mc->y`, `mc->xscale`, `mc->yscale`, `mc->rotation` values.

```c
// In tag.c or a shared utility
void buildTransformFromMC(float out[16], float x, float y,
                          float xscale, float yscale, float rotation);
```

The matrix combines: translate(x, y) * rotate(rotation) * scale(xscale/100, yscale/100). Values are in twips. Rotation is in degrees. The matrix must be column-major to match the existing GPU format.

**Reference**: Flash's transform decomposition uses the SWF `MATRIX` record format (a, b, c, d, tx, ty). The mapping is:
- `tx = x * 20` (pixels to twips)
- `ty = y * 20`
- `a = xscale/100 * cos(rotation)`, `b = xscale/100 * sin(rotation)`
- `c = -yscale/100 * sin(rotation)`, `d = yscale/100 * cos(rotation)`

Then pack into 4x4 column-major:
```
[ a,  b, 0, 0 ]
[ c,  d, 0, 0 ]
[ 0,  0, 1, 0 ]
[ tx, ty, 0, 1 ]
```

#### Step 2: Detect runtime-modified transforms in compose_children

Modify `compose_children()` in `tag.c` to check whether a display object's associated MovieClip has `as_set_flags != 0`. If so, rebuild the local transform from MovieClip properties instead of reading from the static `transform_data` array.

```c
// In compose_children, before composing:
const float* local_xform;
float rebuilt[16];
MovieClip* mc = findMCForDisplayObject(obj);
if (mc && mc->as_set_flags) {
    buildTransformFromMC(rebuilt, mc->x, mc->y, mc->xscale, mc->yscale, mc->rotation);
    local_xform = rebuilt;
} else {
    local_xform = &transforms[obj->transform_id * 16];
}
```

The MC lookup may use `obj->instance_name` → `actionFindMovieClipByName()`, or a direct pointer if one is stored on the DisplayObject.

#### Step 3: Handle non-sprite display objects

For shapes/text fields that are children of a runtime-modified sprite, the parent's composed transform change will cascade automatically through `compose_children`. No per-shape modification needed — only the sprite's own transform needs rebuilding.

#### Step 4: Test with display_object_properties

Run `python3 ruffle-tests/verify_output.py --test=display_object_properties --headless --diff --verbose` and verify the green diamond moves to its expected far-right position.

### Design Considerations

1. **Performance**: `buildTransformFromMC` involves sin/cos. Only called when `as_set_flags != 0`, so only for runtime-modified MCs. Acceptable for headless mode.

2. **Decomposition round-trip**: When a MC is first placed by the timeline, its transform comes from `transform_data`. When `_x` is set, `as_set_flags |= 1` and `mc->x` is updated. The getter path already decomposes the matrix into x/y/xscale/yscale/rotation (for `_x` getter). So the rebuild should produce an equivalent matrix. Verify with the identity case (no changes → same matrix as original).

3. **Incremental vs full rebuild**: Could either rebuild only changed components (e.g., only update tx/ty for _x/_y changes) or always do a full rebuild when any flag is set. Full rebuild is simpler and less error-prone.

4. **as_set_flags covers the 5 spatial properties**: bit0=_x, bit1=_y, bit2(4)=_xscale, bit3(8)=_yscale, bit4(16)=_rotation. `_alpha` is handled separately via cxform.

### Dependencies

- None — this is a standalone change
- Complementary to RUNTIME_CXFORM_GPU_PLAN.md (both needed for `color` test)

### Estimated Complexity

Low-medium. The infrastructure for dynamic GPU buffer writes already exists (dynamic slot allocation, `renderer_write_transform()`). The main work is:
1. Writing `buildTransformFromMC()` (~20 lines)
2. Modifying `compose_children()` to use it (~15 lines)
3. Linking MovieClip to DisplayObject for the lookup (~10 lines if not already linked)
