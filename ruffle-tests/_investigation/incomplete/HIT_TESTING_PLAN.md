# Hit Testing Implementation Plan
<!-- TESTS: hittest_lockroot, hittest_morph, hittest_morph_input, hittest_winding_rule, text_blocks_clicks, movieclip_hittest, movieclip_hittest_shapeflag, local_to_global, movieclip_getbounds, movieclip_invalid_get_bounds_1, movieclip_invalid_get_bounds_2, movieclip_invalid_get_bounds_3, movieclip_invalid_get_bounds_4, movieclip_invalid_get_bounds_5, movieclip_invalid_get_bounds_6, movieclip_invalid_get_bounds_7, movieclip_invalid_get_bounds_8 -->

Last updated: 2026-02-18

## Status: NOT STARTED

---

## Overview

Hit testing requires computing the bounding box and/or actual shape of a MovieClip in stage
coordinates, then checking whether a point or another clip's bounding box intersects it.

The tests cluster into three groups by complexity:
1. **Coordinate transforms** (`localToGlobal`/`globalToLocal`) — math on existing transform data
2. **Bounding box tests** (`getBounds`, `hitTest` with shapeFlag=false, `hitTest(clip)`) — need
   per-character shape bounds emitted by the recompiler
3. **Shape tests** (`hitTest` with shapeFlag=true, winding rules) — need actual vertex data at runtime

Two tests require **mouse simulation** — previously deferred, now **unblocked** by
input-event-injection.md Phases 0–7 (complete as of 2026-02-20):
- `hittest_morph_input` — mouse move event fires "hovering": needs Phase 3 (clip bounds) +
  MOUSE_EVENTS_PLAN.md Phase B (clip event dispatch). Expected output: 1 line `"hovering"`.
- `text_blocks_clicks` — mouse down/up fire onMouseDown/onPress: needs Phase 3 (text bounds) +
  MOUSE_EVENTS_PLAN.md Phase B. Expected output: 4 lines with click positions.

See **MOUSE_EVENTS_PLAN.md** for the clip event dispatch infrastructure needed by these tests.

---

## Test Inventory

| Test | Lines | Current | Phase | Key Need |
|------|-------|---------|-------|----------|
| local_to_global | 49 | 41/49 (84%) | 1 | localToGlobal/globalToLocal math |
| movieclip_getbounds | 191 | 25/191 (13%) | 3 | getBounds/getRect with actual bounds |
| movieclip_invalid_get_bounds_1–8 | 10–75 | 1/X (2%) | 3 | getBounds returning proper sentinels |
| movieclip_hittest | 92 | 71/92 (77%) | 4 | hitTest(x, y) — all the true/false lines |
| hittest_lockroot | 15 | 0/15 (0%) | 4+1 | localToGlobal + hitTest on drawn clip |
| hittest_morph | 70 | ~0/70 | 3+4 | getBounds/getRect on morph shapes |
| movieclip_hittest_shapeflag | 338 | 180/338 (53%) | 5 | hitTest(x, y, true) — shape hit |
| hittest_winding_rule | 12 | 0/12 (0%) | 5 | Even-odd vs non-zero winding in hitTest |
| hittest_morph_input | 1 | 0/1 | Phase 3+MOUSE_EVENTS | Clip bounds + mouse move dispatch |
| text_blocks_clicks | 4 | 0/4 | Phase 3+MOUSE_EVENTS | Text bounds + mouse down/up dispatch |

---

## Phase 1: localToGlobal / globalToLocal

**Goal**: Implement `MovieClip.localToGlobal(point)` and `MovieClip.globalToLocal(point)`.

### What the tests expect

From `local_to_global`:
```actionscript
var point = {x: 10, y: 10};
clip.localToGlobal(point);
trace(point.x);   // modified in place
trace(point.y);   // modified in place
```

`localToGlobal` transforms a point from the clip's local coordinate space to stage (global) space.
`globalToLocal` transforms a point from stage space to the clip's local coordinate space.

**Both modify the `{x, y}` point object IN PLACE.**

Coordinates are in PIXELS (not twips). The `transform_data` stores values in twips, so divide by 20
when reading positions and multiply by 20 when transforming.

### Transform matrix format

`transform_data[id]` is a column-major 4×4 matrix:

```
[0]  [4]  [8]  [12]     a  c  0  tx
[1]  [5]  [9]  [13]  =  b  d  0  ty
[2]  [6]  [10] [14]     0  0  1  0
[3]  [7]  [11] [15]     0  0  0  1
```

Where (a, b, c, d) is the 2×2 rotation/scale submatrix and (tx, ty) is the translation in twips.

### Algorithm for localToGlobal

```
function localToGlobal(mc, px_in, py_in) → (px_out, py_out):
    # Convert point to twips
    tx = px_in * 20
    ty = py_in * 20

    # Walk from mc up to root, accumulating transforms
    cur = mc
    while cur != NULL:
        M = transform_data[cur->last_transform_id]
        a = M[0], b = M[1], c = M[4], d = M[5]
        new_tx = M[12], new_ty = M[13]
        tx_out = a*tx + c*ty + new_tx
        ty_out = b*tx + d*ty + new_ty
        tx = tx_out
        ty = ty_out
        cur = cur->parent

    # Convert back to pixels
    return (tx/20, ty/20)
```

Note: `_root->parent == NULL` stops the loop. `_root`'s transform is identity in most cases, but
we must still apply it for correctness (e.g., when _root is rotated by ActionScript).

### Algorithm for globalToLocal

```
function globalToLocal(mc, px_in, py_in) → (px_out, py_out):
    # Build combined local-to-global matrix (from mc upward)
    # Start with identity
    A = {a=1, b=0, c=0, d=1, tx=0, ty=0}
    cur = mc
    while cur != NULL:
        M = transform_data[cur->last_transform_id]
        A = mat2d_multiply(M, A)   # A = M * A (local then global)
        cur = cur->parent

    # Invert A
    det = A.a*A.d - A.b*A.c
    if det == 0: return (px_in, py_in)  # degenerate
    ia = A.d/det,  ib = -A.b/det
    ic = -A.c/det, id = A.a/det
    itx = (A.c*A.ty - A.d*A.tx) / det
    ity = (A.b*A.tx - A.a*A.ty) / det

    # Transform the point (in twips)
    inx = px_in * 20
    iny = py_in * 20
    outx = ia*inx + ic*iny + itx
    outy = ib*inx + id*iny + ity
    return (outx/20, outy/20)
```

### 2D matrix multiply

```
mat2d_multiply(M, A):
    # M = {ma, mb, mc, md, mtx, mty}  (extracted from transform_data)
    # A = {aa, ab, ac, ad, atx, aty}
    result.a  = ma*aa + mc*ab
    result.b  = mb*aa + md*ab
    result.c  = ma*ac + mc*ad
    result.d  = mb*ac + md*ad
    result.tx = ma*atx + mc*aty + mtx
    result.ty = mb*atx + md*aty + mty
```

### Infrastructure changes

**New function in tag_stubs.c (exported in tag.h):**
```c
// Returns a pointer to the 16-float column-major matrix for the given transform_id.
// Returns NULL if transform_id is out of range.
const float* ng_getTransformMatrix(u32 transform_id);
```

**Implementation in action.c (in actionCallMethod, MovieClip branch):**

```c
else if (method_name_len == 13 && strncmp(method_name, "localToGlobal", 13) == 0) {
    // Pop the point object arg
    // point.x * 20 → tx, point.y * 20 → ty
    // Walk mc → root, multiply transforms
    // Store result/20 back to point.x, point.y
}
else if (method_name_len == 13 && strncmp(method_name, "globalToLocal", 13) == 0) {
    // Same, but build combined matrix then invert it
}
```

### Tests fixed by Phase 1

- **local_to_global**: 41/49 → ~49/49 (the 8 failing lines are the x/y coord lines after
  `localToGlobal` calls; comment lines already pass)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=local_to_global --diff --verbose
```

---

## Phase 2: Shape Bounds in NO_GRAPHICS Mode

**Goal**: Emit and store bounding box (RECT) for each character (shape, morph shape, text) at
compile time, so that getBounds/getRect/hitTest can look them up at runtime.

### Data structure

**In tag_stubs.c (static array):**
```c
#define MAX_CHAR_BOUNDS 4096
typedef struct { float xMin, yMin, xMax, yMax; } CharBounds;  // values in twips
static CharBounds ng_char_bounds[MAX_CHAR_BOUNDS];
static int ng_char_bounds_set[MAX_CHAR_BOUNDS];  // 0 = unset (defaults to sentinel)
```

**New runtime function in tag_stubs.c:**
```c
void tagRegisterCharBounds(SWFAppContext* ctx, size_t char_id,
                            float xMin, float yMin, float xMax, float yMax)
```
Stores bounds for a character. Called from generated `tagMain.c`.

**New accessor in tag_stubs.c:**
```c
int ng_getCharBounds(size_t char_id, CharBounds* out_bounds);
// Returns 1 if bounds found, 0 if not set
```

Add declarations to `tag.h`.

### Recompiler changes (swf.cpp)

In the DefineShape case (around line 5187), after parsing `shape_id` and the RECT:

```cpp
// In tag_main for NO_GRAPHICS mode, emit bounds registration:
s64 rect_xMin = shape_tag.fields[2].value;  // in twips
s64 rect_xMax = shape_tag.fields[3].value;
s64 rect_yMin = shape_tag.fields[4].value;
s64 rect_yMax = shape_tag.fields[5].value;
context.tag_main << "\t" << "tagRegisterCharBounds(app_context, "
    << shape_id << ", "
    << rect_xMin << ".0f, " << rect_yMin << ".0f, "
    << rect_xMax << ".0f, " << rect_yMax << ".0f);" << endl;
```

This must be emitted in NO_GRAPHICS mode too (currently the recompiler wraps some things in
`#ifndef NO_GRAPHICS`, need to check which parts).

The same applies to:
- `DefineText` / `DefineText2`: emit the text's bounding RECT
- `DefineEditText`: emit the text field's Bounds RECT
- `DefineMorphShape`: emit the StartBounds RECT (use this as the shape bounds)

For sprites (`DefineSprite`), we do NOT emit explicit bounds — they're computed at runtime as the
union of child character bounds (see Phase 3).

### Verification

No direct test — these bounds are used by Phases 3–5.

---

## Phase 3: getBounds / getRect

**Goal**: Implement `MovieClip.getBounds(target)` and `MovieClip.getRect(target)`.

### What the tests expect

From `movieclip_getbounds`:
```actionscript
var b = clip.getBounds(_root);   // Returns {xMin, xMax, yMin, yMax} in target's local coords
trace(b.xMin);   // float, e.g. 25.05
trace(b.xMax);
trace(b.yMin);
trace(b.yMax);
```

- `getBounds(self)` uses sentinel `134217727/20 = 6710886.35` for empty clips
- `getBounds(otherClip)` uses sentinel `134217728/20 = 6710886.4` for empty clips (already partially implemented!)
- `getRect(target)` is identical to `getBounds(target)` for non-curved shapes. For curved shapes,
  it returns the tighter edge bounds (not the stroke-extended shape bounds). In practice, for
  non-curved shapes the results are the same.

### Algorithm

**Computing a clip's global bounding box:**

```
function get_global_aabb(mc):
    # Collect all child characters' bounds, transform to global space
    aabb = {+inf, +inf, -inf, -inf}  # empty

    if mc has a static char_id (placed from timeline):
        # Get the char's local bounds
        bounds = ng_char_bounds[mc->char_id]
        # Build mc's local-to-global matrix
        M = get_local_to_global_matrix(mc)  # as in Phase 1
        # Transform all 4 corners
        for corner in {(xMin,yMin), (xMax,yMin), (xMin,yMax), (xMax,yMax)}:
            tx = M.a*corner.x + M.c*corner.y + M.tx
            ty = M.b*corner.x + M.d*corner.y + M.ty
            aabb = union(aabb, tx, ty)

    else:
        # Sprite: union bounds of all children
        # Walk ng_display for children of this sprite
        for each display_entry that is a child of mc:
            child_bounds = ng_char_bounds[child.char_id]
            # Build child's local-to-global matrix (child transform * mc global matrix)
            ...
            # Transform corners and union into aabb

    return aabb  # in twips
```

**Converting AABB to target's local space:**

If `target == NULL` or target is root, return in stage (global) space.
Otherwise, transform the AABB through `target`'s `globalToLocal` matrix.

The result properties `xMin, xMax, yMin, yMax` are in PIXELS (divide twips by 20).

### Current state

The current implementation returns a fixed sentinel for all inputs. We need to:
1. Check if `target_is_self` (existing code already does this correctly for sentinel selection)
2. Compute actual AABB from child characters instead of the sentinel
3. If bounds are infinite (no shapes found), use the sentinel

### Sprite child traversal

The challenge: in NO_GRAPHICS mode, we have `ng_display[i].char_id` for each placed object. But
currently, the `ng_display` struct stores char_id separately from sprite vs shape detection:

```c
// In ng_display entry:
size_t sprite_idx;   // != SIZE_MAX if this is a sprite
// char_id is not currently stored in ng_display!
```

We need to also store `char_id` in ng_display entries so we can look up bounds.

**Add `size_t char_id` to `ng_display` struct in tag_stubs.c**, and populate it in
`tagPlaceObject2`. Already have `sprite_idx` for sprites; `char_id` for shapes/text.

### Tests fixed by Phase 3

- **movieclip_getbounds**: 25/191 → ~100+/191 (many bound queries will be correct)
- **movieclip_invalid_get_bounds_1–8**: 1/X → improved (sentinel values already correct, but
  coordinate transform edge cases need fix)
- **hittest_morph**: partial improvement (getBounds/getRect calls will return real values)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=movieclip_getbounds --diff --verbose
python3 ruffle-tests/verify_output.py --test=movieclip_invalid_get_bounds_1 --diff --verbose
python3 ruffle-tests/verify_output.py --test=hittest_morph --diff --verbose
```

---

## Phase 4: hitTest(x, y, shapeFlag=false) — Bounding Box Mode

**Goal**: Implement the most common hitTest form: checking if a stage-coordinate point falls within
a clip's bounding box.

### Behavior

```actionscript
mc.hitTest(x, y)             // shapeFlag defaults to false → bounding box test
mc.hitTest(x, y, false)      // explicit shapeFlag=false → bounding box test
```

Coordinates `(x, y)` are in STAGE PIXEL space.

Flash behavior:
- If shapeFlag=false (or absent): test if (x, y) is in the clip's axis-aligned bounding box in stage coords
- If clip is empty (no shapes): return false
- If clip is invisible (_visible=false): still include in hitTest (not filtered by visibility)
- If x or y is NaN: return false

### Algorithm

```
hitTest(mc, x, y, shapeFlag=false):
    if isNaN(x) or isNaN(y): return false

    # Get clip's global AABB (using Phase 2 bounds data + Phase 1 transform math)
    aabb = get_global_aabb(mc)  # in twips
    if aabb is empty: return false

    # Convert test point to twips
    tx = x * 20
    ty = y * 20

    # Check inclusion (AABB in stage twips)
    return (tx >= aabb.xMin && tx <= aabb.xMax && ty >= aabb.yMin && ty <= aabb.yMax)
```

### Arg parsing

The `hitTest` method has overloaded signatures detected by argument count and type:
1. `hitTest(x, y)` — 2 numeric args → bounding box test
2. `hitTest(x, y, shapeFlag)` — 3 args — shapeFlag arg is boolean → bounding box or shape test
3. `hitTest(clip)` — 1 MovieClip arg → clip-vs-clip overlap test (Phase 5)
4. `hitTest(stringPath)` — 1 string arg → resolve to clip, then clip-vs-clip overlap (Phase 5)

The first arg's type distinguishes case (1/2/3) from case (4):
- If first arg is numeric → cases 1/2
- If first arg is MovieClip → case 3
- If first arg is string → case 4

### Dynamic clip bounds (Drawing API)

For clips created via `createEmptyMovieClip` + drawing API (`moveTo/lineTo/curveTo`), the bounds
come from the drawing operations, not from a static shape definition.

To handle `hittest_lockroot`, we need to track the bounding box of drawing operations. When
drawing API methods set vertices, update a `draw_bounds` field on MovieClip:

```c
// Add to MovieClip struct (under #ifdef NO_GRAPHICS):
float draw_xMin, draw_yMin, draw_xMax, draw_yMax;  // in pixels, NaN = unset
u8 has_draw_bounds;
```

When `moveTo(x, y)` / `lineTo(x, y)` / `curveTo(cx, cy, ax, ay)` are called, expand
`draw_bounds` to include the new point.

In `get_global_aabb(mc)`: if `mc->has_draw_bounds`, use `draw_bounds` as the local bounding box
(converted to twips: multiply by 20), then transform by mc's transform chain.

### Tests fixed by Phase 4

- **movieclip_hittest**: 71/92 → ~92/92 (all bounding-box hitTest results become correct)
- **hittest_lockroot**: 0/15 → 12-15/15 (if draw_bounds tracking works for the 100×100 box)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=movieclip_hittest --diff --verbose
python3 ruffle-tests/verify_output.py --test=hittest_lockroot --diff --verbose
```

---

## Phase 5: hitTest(clip) / hitTest(stringPath) — Clip Overlap Mode

**Goal**: Implement the clip-vs-clip bounding box overlap form of hitTest.

### Behavior

```actionscript
mc.hitTest(otherClip)          // MovieClip arg → bounding box overlap
mc.hitTest("_root.clipName")   // String path arg → resolve then overlap
```

Returns true if the AABB of `mc` and the AABB of `otherClip` overlap in stage coordinates.

### Algorithm

```
hitTest_clip(mc, other):
    aabb1 = get_global_aabb(mc)
    aabb2 = get_global_aabb(other)
    if either is empty: return false
    # Axis-aligned overlap test:
    return NOT (aabb1.xMax < aabb2.xMin || aabb2.xMax < aabb1.xMin ||
                aabb1.yMax < aabb2.yMin || aabb2.yMax < aabb1.yMin)
```

For string path resolution, use the existing `resolveTargetPath()` / `findMovieClip()` logic that's
already in action.c.

Special string paths per Flash spec:
- `"/"` or `"_root"` → root movieclip → always returns true (root always overlaps stage)
- `""` → empty string → always returns false
- `"../"` or `"_parent"` → resolve relative to mc

### Tests fixed by Phase 5

- **movieclip_hittest**: should handle the `circle.hitTest(lower)` / `circle.hitTest(upper)` calls
  and the `circle.hitTest('_root.lower')` string path variants
- **hittest_morph**: `bullet.hitTest(hitbox)` — the clip-vs-clip form

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=movieclip_hittest --diff --verbose
python3 ruffle-tests/verify_output.py --test=hittest_morph --diff --verbose
```

---

## Phase 6: hitTest(x, y, shapeFlag=true) — Shape Hit Test

**Goal**: Implement shape-accurate hit testing using the triangulated vertex data.

### Behavior

```actionscript
mc.hitTest(x, y, true)   // shapeFlag=true → test against actual shape, not just BB
```

If `shapeFlag=true`:
1. First check the bounding box (fast reject) — if outside, return false
2. Then test against the actual triangles (slow path)

### Winding Rule Support

From `hittest_winding_rule`:
- Even-odd shapes: holes are "outside" the shape
- Non-zero winding: holes are "inside" the shape (the hole is filled by the inner winding)

The SWF format sets the winding rule per DefineShape4 (UsesFillWindingRule flag). For DefineShape
1–3, the rule is always even-odd.

### Coordinate space issue: baked vs local vertices

**CRITICAL**: The `shape_data` array stores vertex coordinates in **baked stage space** (pixels,
with all compile-time transforms applied and Y-axis flipped: `FRAME_HEIGHT - y`). This is the
format the GPU renderer needs. However:

1. ActionScript can change clip transforms at runtime (`_x`, `_y`, `_rotation`, etc.)
2. The baked stage coordinates do NOT reflect runtime transform changes
3. Therefore, we cannot directly test baked stage vertices against a stage-space test point when
   the clip's transform has been mutated at runtime

**Two approaches**:

**Approach A: Local-space vertices (correct, more storage)**

Emit a second vertex array `shape_local_data[N][2]` with coordinates in **local twips** (before
any PlaceObject transforms, before Y-flip). These can be used with the `globalToLocal` transform
from Phase 1 to correctly handle runtime transform changes.

The recompiler would emit both:
```c
// shape_data[i] — baked stage coords (for renderer, existing)
// shape_local_data[i] — local twips coords (for hitTest, new)
```

**Approach B: Un-bake from stage space (only works for static shapes)**

If the clip's `_x/_y/_rotation/_scale` have NOT been changed by ActionScript (i.e.,
`mc->as_set_flags == 0`), the baked stage coords ARE correct and we can test directly. When
transforms have been changed, fall back to bounding-box hitTest.

For `hittest_winding_rule` (which uses static shapes), Approach B works. For
`movieclip_hittest_shapeflag` (which rotates `_root`), Approach A is needed.

**Recommended**: Start with Approach B (simpler, fixes `hittest_winding_rule`), then upgrade to
Approach A if `movieclip_hittest_shapeflag` accuracy is needed.

### Algorithm for shape-based test (Approach B: static shapes)

```c
// shape_data vertex format:
// shape_data[i][0] = x as float bits (baked stage pixels: *(float*)&shape_data[i][0])
// shape_data[i][1] = y as float bits (baked stage pixels, Y-flipped)
// shape_data[i][2] = style_type_packed (fill style type + flags)
// shape_data[i][3] = fill style index (which color/gradient to use)
// 3 consecutive entries = 1 triangle
```

```c
int point_in_shape_baked(size_t char_id, float test_px, float test_py) {
    // test_px, test_py are in stage PIXELS (not twips, not Y-flipped)
    // Baked vertices are in pixels with Y-flipped (FRAME_HEIGHT - y)
    float test_y_flipped = FRAME_HEIGHT_PX - test_py;

    CharInfo* ci = &ng_char_info[char_id];
    u32 start = ci->shape_start, count = ci->shape_count;
    int hits = 0;

    for (u32 i = start; i + 2 < start + count; i += 3) {
        float ax = *(float*)&shape_data[i][0];
        float ay = *(float*)&shape_data[i][1];   // Y-flipped
        float bx = *(float*)&shape_data[i+1][0];
        float by = *(float*)&shape_data[i+1][1];
        float cx = *(float*)&shape_data[i+2][0];
        float cy = *(float*)&shape_data[i+2][1];
        if (point_in_triangle(test_px, test_y_flipped, ax, ay, bx, by, cx, cy)) {
            hits++;
        }
    }
    if (ci->winding_nonzero) return hits > 0;
    return (hits % 2) == 1;  // even-odd
}
```

Earcut outputs triangles that are consistently oriented (outer = clockwise, holes = counter-
clockwise or vice versa). The even-odd test (counting triangle hits % 2) naturally handles holes
because each hole's triangles count as additional coverings. For non-zero winding, holes are
NOT empty — `hits > 0` regardless of hole/outer distinction.

### Recompiler changes for Phase 6

Emit winding rule flag per shape and store shape geometry info:

```cpp
// After computing UsesFillWindingRule flag from DefineShape4:
context.tag_main << "\t" << "tagRegisterCharInfo(app_context, " << shape_id
    << ", " << rect_xMin << ".0f, " << rect_yMin << ".0f, "
    << rect_xMax << ".0f, " << rect_yMax << ".0f, "
    << (3*current_tri) << ", " << (3*tris_size)  // start, count
    << ", " << uses_fill_winding_rule << ");" << endl;
```

This replaces the separate `tagRegisterCharBounds` from Phase 2 (fold them together).

### Tests fixed by Phase 6

- **hittest_winding_rule**: 0/12 → 12/12 (even-odd vs non-zero correctly distinguished)
- **movieclip_hittest_shapeflag**: 180/338 → significantly improved (actual shape hit vs BB)
- Parts of `hittest_morph`

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=hittest_winding_rule --diff --verbose
python3 ruffle-tests/verify_output.py --test=movieclip_hittest_shapeflag --diff --verbose
```

---

## Deferred Tests (Mouse Simulation Required)

### hittest_morph_input (1 line)

Expected: `hovering`

Input JSON: `MouseMove` to (180, 160) + `Wait`. This requires `onMouseMove` / `onRollOver` event
dispatch, which needs mouse simulation infrastructure.

### text_blocks_clicks (4 lines)

Expected:
```
click_mc.onMouseDown at 234, 197
click_mc.onPress at 234, 197
// dragger._droptarget
/texts
```

Input JSON: `MouseMove`, `MouseDown`, `MouseUp`. Requires mouse event dispatch infrastructure.

Both are tagged as interactive-input tests. They belong to the Mouse/Focus/Input Events category
(#5 in the priority list) rather than being purely geometric hitTest work.

---

## Architecture Summary

### New data needed per character

```
char_id → CharInfo {
    xMin, yMin, xMax, yMax,    // bounding RECT in twips (Phase 2)
    shape_start, shape_count,  // shape_data indices for vertex test (Phase 6)
    winding_nonzero,           // 0=even-odd, 1=non-zero (Phase 6)
}
```

### New data needed per MovieClip (NO_GRAPHICS)

```
MovieClip {
    // existing fields...
    float draw_xMin, draw_yMin, draw_xMax, draw_yMax;  // drawing API bounds (Phase 4)
    u8 has_draw_bounds;
    size_t ng_char_id;  // char_id of the placed character (for bounds lookup)
}
```

The `ng_char_id` lets us look up bounds in ng_char_info. Currently MovieClip only tracks
`last_transform_id` for its coordinate data but not which character it represents.

We also need `ng_char_id` stored in `ng_display[]` entries (currently `char_id` is not in
ng_display — only sprite_idx, is_textfield, etc.).

### New functions (tag_stubs.c / tag.h)

| Function | Phase | Purpose |
|----------|-------|---------|
| `ng_getTransformMatrix(u32 id)` | 1 | Access transform_data[id] |
| `tagRegisterCharInfo(ctx, char_id, xMin, yMin, xMax, yMax, start, count, winding)` | 2/6 | Register shape metadata |
| `ng_getCharInfo(char_id, out)` | 2/6 | Look up CharInfo by char_id |
| `ng_getClipGlobalAABB(mc, out_aabb)` | 3/4/5 | Compute clip's global bounding box |

### Transform math helper (action.c or new file)

```c
// 2D affine matrix ops (working in twips)
typedef struct { float a, b, c, d, tx, ty; } Mat2D;
static Mat2D mat2d_identity() { return (Mat2D){1,0,0,1,0,0}; }
static Mat2D mat2d_from_col16(const float* M) { return (Mat2D){M[0],M[1],M[4],M[5],M[12],M[13]}; }
static Mat2D mat2d_multiply(Mat2D P, Mat2D Q); // P*Q
static Mat2D mat2d_invert(Mat2D M);
static void mat2d_transform_point(Mat2D M, float* x, float* y);
```

---

## Files to Modify

### Recompiler (SWFRecomp/)

| File | Changes |
|------|---------|
| `src/swf.cpp` | Emit `tagRegisterCharInfo(...)` calls after `tagDefineShape(...)` in NO_GRAPHICS mode |

### Runtime (SWFModernRuntime/)

| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | Implement `localToGlobal`, `globalToLocal`, `hitTest` in actionCallMethod; Mat2D helper functions; draw bounds update in moveTo/lineTo/curveTo stubs |
| `src/libswf/tag_stubs.c` | Add `ng_char_info[]` table, `tagRegisterCharInfo()`, `ng_getCharInfo()`, `ng_getTransformMatrix()`, `ng_getClipGlobalAABB()`; add `char_id` to ng_display entries |
| `include/libswf/tag.h` | Declare new functions |
| `include/actionmodern/action.h` | Add `draw_bounds` fields and `ng_char_id` to MovieClip struct (under `#ifdef NO_GRAPHICS`) |

---

## Dependencies

- **Phase 1** has no dependencies (uses existing `last_transform_id` and `transform_data`)
- **Phase 2** requires recompiler change to emit bounds
- **Phase 3** requires Phases 1 + 2
- **Phase 4** requires Phases 2 + 3 (for `get_global_aabb`)
- **Phase 5** requires Phase 4 (uses same AABB computation)
- **Phase 6** requires Phase 4 + recompiler to emit shape geometry indices

Phases 1, 2, 3, 4 should be done in order. Phases 5 and 6 can be done in parallel after Phase 4.

---

## Implementation Priority and Expected Impact

| Phase | Tests Fixed | Effort | Notes |
|-------|------------|--------|-------|
| 1: localToGlobal/globalToLocal | local_to_global: ~8 more lines | Low | Pure math on existing data |
| 2: Shape bounds emission | Foundation only | Low | Recompiler change + new table |
| 3: getBounds/getRect | movieclip_getbounds: ~100+ more, 8 invalid_get_bounds tests | Medium | Recursive AABB union |
| 4: hitTest bounding box | movieclip_hittest: ~21 more, hittest_lockroot: ~15 | Medium | Uses Phase 2+3 |
| 5: hitTest clip overlap | movieclip_hittest partial, hittest_morph partial | Low | Trivial once AABB works |
| 6: hitTest shape | hittest_winding_rule: 12, movieclip_hittest_shapeflag: ~100+ | High | Vertex data + winding |

**Quick win path**: Implement Phases 1–4 first. This fixes:
- `local_to_global` (all remaining failures)
- `movieclip_hittest` (all remaining failures ~21 lines)
- Significant progress on `movieclip_getbounds`, `movieclip_invalid_get_bounds_*`
- Partial fix for `hittest_lockroot` (needs draw bounds tracking)

Phase 5 is easy once Phase 4 works. Phase 6 is the most complex but fixes the winding rule and
shape-flag tests.

---

## Quick Reference: hitTest Test Analysis

### movieclip_hittest (92 lines, 71 currently passing)
The 71 passing lines are all `// comment` lines and blank lines. Every actual `hitTest` result
line returns `undefined` (should be `true`/`false`). This test uses 2-arg form only (shapeFlag
defaults to false = bounding box). Fixing Phase 4 should bring this to ~92/92.

### movieclip_hittest_shapeflag (338 lines, 180 currently passing)
Similar situation: 180 passing = comment lines. The hitTest results all return `undefined`. This
test uses `hitTest(x, y, true)` throughout. Phase 4 would help partially (bounding box is a
superset), but Phase 6 is needed for full accuracy (the test includes donut shapes where the hole
should return false with shapeFlag=true but the bounding box would return true).

### hittest_winding_rule (12 lines, 0 currently passing)
6 hitTest results, each on a pair of concentric shapes (even-odd vs non-zero). Needs Phase 6.

### hittest_morph (70 lines, ~0 currently passing)
Uses `getBounds()`, `getRect()`, `hitTest(clip)`, `hitTest(x, y, true)`. Multiple phases required.
