# Stage/Frame Properties Implementation Plan

<!-- TESTS: stage_property_representation, frame_size_translated_positive, frame_size_translated_negative, stage_scale_mode, stage_display_state, stage_object_properties, stage_object_properties_swf6, stage_object_enumerate, stage_object_children -->

Last updated: 2026-02-28

## Status: ALL PHASES COMPLETE — 9/9 tests PASS

All phases are complete including Phase 9 (mouse input for named shapes). All 9 tests fully pass.

### Test Results (2026-03-05)

| Test | Status | Notes |
|------|--------|-------|
| `stage_property_representation` | **PASS** ✅ | F64 bug fixed, Stage properties implemented |
| `stage_object_enumerate` | **PASS** ✅ | Stage enumeration working |
| `stage_display_state` | **PASS** ✅ | displayState + onFullScreen callback working |
| `stage_scale_mode` | **PASS** ✅ | onResize broadcast + viewport dims + broadcastMessage MC variable fallback |
| `stage_object_properties` | **PASS** ✅ | _width/_height, scale, rotation, sprite context all working |
| `stage_object_properties_swf6` | **PASS** ✅ | Same as above |
| `stage_object_children` | **PASS** ✅ | _level addressing, child enumeration working |
| `frame_size_translated_positive` | **PASS** ✅ | Fixed: FRAME_X_MIN_TWIPS/FRAME_Y_MIN_TWIPS offset (commit 12d7c2c2) |
| `frame_size_translated_negative` | **PASS** ✅ | Same fix as positive |

**Note:** This plan can be moved to `complete/`.

### What's Implemented (Phases 1-8)
- **Phase 1**: actionSetProperty F64 bug fixed — F64 values read correctly as doubles
- **Phase 2**: Shape bounds tracking in NO_GRAPHICS mode — `ng_char_bounds` table populated from `tagDefineShape`
- **Phase 3**: Content bounds for `_root._width/_height` — computed from children bounds union
- **Phase 4**: Scale/rotation extracted from PlaceObject transform matrix
- **Phase 5**: Stage singleton (`g_stage_obj`) with align, scaleMode, displayState, width/height, quality, showMenu, onResize/onFullScreen broadcast
- **Phase 6**: Sprite context tracking — `getMovieClipByTarget("")` uses `g_current_context`
- **Phase 7**: `_visible` returns boolean (true/false) instead of float (1/0)
- **Phase 8**: Stage children enumeration + _level0/_flash0 addressing

---

## Overview

Two categories of failing tests are covered here:

- **Category 51 — Stage/Frame Properties** (2 tests, 67% passing): `frame_size_translated_negative`, `frame_size_translated_positive`
- **Category 15 — Stage Object Properties** (7 tests, ~30–72% passing): `stage_property_representation`, `stage_scale_mode`, `stage_display_state`, `stage_object_properties`, `stage_object_properties_swf6`, `stage_object_enumerate`, `stage_object_children`

These are grouped because they share a common root cause cluster: shape bounds not tracked in trace mode, `_root._width/_height` being hardcoded Flash-player defaults, Stage object missing property initialization, and the `actionSetProperty` F64 bug.

---

## Bug Analysis

### Bug 1: `actionSetProperty` reads F64 as float (→ returns 0)

**File**: `SWFModernRuntime/src/actionmodern/action.c:16077`

```c
// CURRENT (BROKEN):
if (value_var.type == ACTION_STACK_VALUE_F32 || value_var.type == ACTION_STACK_VALUE_F64) {
    num_value = (float) VAL(float, &value_var.data.numeric_value);  // reads 4 bytes for both!
```

When `value_var.type == ACTION_STACK_VALUE_F64`, the value is stored as a `u64` (8 bytes, IEEE 754 double). Using `VAL(float, ...)` reads only the lower 4 bytes of the double representation. For `20.0` as a double (`0x4034000000000000`), the lower 4 bytes are `0x00000000` = 0.0f. **All numeric values pushed as F64 and then stored via SetProperty become 0.**

Fix:
```c
if (value_var.type == ACTION_STACK_VALUE_F32) {
    num_value = VAL(float, &value_var.data.numeric_value);
} else if (value_var.type == ACTION_STACK_VALUE_F64) {
    double d = VAL(double, &value_var.data.numeric_value);
    num_value = (float) d;
}
```

**Impact**: `stage_property_representation` (0/586 → 586/586 full pass). Also potentially unblocks any test that uses ActionSetProperty opcode with double values.

### Bug 2: `root_movieclip.width`/`height` hardcoded as 550/400

**File**: `SWFModernRuntime/src/actionmodern/action.c:6276`

```c
MovieClip root_movieclip = {
    .width = 550.0f,   // Flash default player size — WRONG for content bounds
    .height = 400.0f,
    ...
```

Flash's `_root._width` / `_root._height` return the **bounding box of all content** placed on the root timeline, NOT the stage/player dimensions. For example, if two 10×10px shapes are placed at (120,170) and (145,145), the root bounds are [120,155]×[145,180] = 35×35px.

**Impact**: `frame_size_translated_*` lines 14-15 (root _width/_height). Also `stage_object_properties` _width/_height which read 550/400.

### Bug 3: Shape bounds not stored in trace mode

**File**: `SWFModernRuntime/src/libswf/tag_stubs.c:276`

```c
void tagDefineShape(SWFAppContext* app_context, CharacterType type, size_t char_id,
                    size_t shape_offset, size_t shape_size)
{
    (void)app_context; (void)type; (void)char_id; (void)shape_offset; (void)shape_size;
    // No-op! No bounds stored.
}
```

Sprites containing shapes have `mc->width = 0.0f` (set in `createMovieClip`). When `_width`/`_height` is read, `mcGetEffectiveSize` returns 0.

The SWF spec includes a `ShapeBounds RECT` in every DefineShape tag. The recompiler already parses this (see `swf.cpp:1897`). We need to pass it to `tagDefineShape` and store it in a character bounds table.

**Impact**: `frame_size_translated_*` lines 4-5, 9-10 (sprite _width/_height = 0 → 10).

### Bug 4: Scale/rotation not synced from PlaceObject matrix

**File**: `SWFModernRuntime/src/actionmodern/action.c:7143`

`syncTransformIfNeeded` reads only `x` and `y` from the PlaceObject matrix (columns 12/13 of the 4×4 matrix = translation). Rotation and scale are stored in columns 0,1,4,5 of the matrix:

- `xscale = sqrt([0]² + [1]²)` (in SWF units; need to convert to percentage)
- `yscale = sqrt([4]² + [5]²)`
- `rotation = atan2([1], [0]) * 180 / π`

Currently `mc->xscale = 100.0f`, `mc->yscale = 100.0f`, `mc->rotation = 0.0f` always — even if the PlaceObject had rotation/scale. This causes `stage_object_properties` to return wrong values.

**Impact**: `stage_object_properties` _rotation=180 (currently 0), _xscale, _yscale.

### Bug 5: `getMovieClipByTarget("")` always returns root, ignoring sprite context

**File**: `SWFModernRuntime/src/actionmodern/action.c:6312`

```c
static MovieClip* getMovieClipByTarget(const char* target) {
    if (!target || strlen(target) == 0 || strcmp(target, "_root") == 0 || strcmp(target, "/") == 0) {
        return &root_movieclip;  // Always root!
    }
    return NULL;
```

When a frame script runs inside a sprite (e.g., `sprite_2_frame_0` contains `script_1`), AVM1 semantics say that `GetProperty("", prop)` should get properties of **the sprite's MovieClip**, not root. The sprite frame is the "this" context.

Flash uses a "base clip" concept: each script is tied to a clip, and GetProperty/SetProperty with empty target operates on that clip. We have `g_current_context` but it's not used here.

**Impact**: `stage_object_properties` has _x=0, _y=0, _name="", _target="/" all returning root values. Fixing this (Phase 6) would unblock most of the remaining 28% gap.

### Missing: Stage object property initialization

**File**: `SWFModernRuntime/src/actionmodern/action.c:9920`

Stage object is created as an empty `allocObject(app_context, 8)` with no properties set. Reading `Stage.align` returns `undefined`. Setting `Stage.align = 'TL'` stores the string literally without normalization.

Flash behavior:
- `Stage.align`: defaults to `""` (empty = center). Setter must filter to only `L`/`T`/`R`/`B` chars (uppercase, deduplicated), in canonical order L→T→R→B. Invalid-only strings → `""`.
- `Stage.scaleMode`: defaults to `"showAll"`. Valid values: "showAll", "noScale", "exactFit", "noBorder" (case-insensitive input, always returned lowercase/camelCase).
- `Stage.displayState`: defaults to `"normal"`. Valid: "normal" or "fullScreen". Setter fires `Stage.onFullScreen(bFull)` on each change.
- `Stage.width` / `Stage.height`: frame dimensions (from FRAME_WIDTH / FRAME_HEIGHT constants).
- `Stage.showMenu`: defaults to `true`.
- `Stage.quality`: defaults to `"HIGH"`.

---

## Phase Plan

### Phase 1: Fix actionSetProperty F64 bug (Priority: HIGHEST)

**Effort**: Trivial (1 line change)
**Impact**: `stage_property_representation` 0/586 → 586/586 (full pass)

**Change**: `SWFModernRuntime/src/actionmodern/action.c:16077`

Replace the unified type check with separate F32 and F64 branches. See Bug 1 above.

**Verification**:
```bash
python3 ruffle-tests/verify_output.py --test=stage_property_representation --diff --verbose
```

---

### Phase 2: Shape bounds in trace mode

**Effort**: Small
**Impact**: `frame_size_translated_*` gains 4 lines each (shape _width/_height = 10 instead of 0)

**Changes**:

#### 2a. Recompiler: emit shape bounds in `tagDefineShape` call

`SWFRecomp/src/swf.cpp:6228` — add bounds params:
```cpp
// Before:
context.tag_main << "\t" << "tagDefineShape(app_context, CHAR_TYPE_SHAPE, "
    << to_string(shape_id) << ", " << to_string(3*current_tri) << ", "
    << to_string(3*tris_size) << ");" << endl;

// After:
context.tag_main << "\t" << "tagDefineShape(app_context, CHAR_TYPE_SHAPE, "
    << to_string(shape_id) << ", " << to_string(3*current_tri) << ", "
    << to_string(3*tris_size) << ", "
    << to_string(bounds_xmin) << ", " << to_string(bounds_xmax) << ", "
    << to_string(bounds_ymin) << ", " << to_string(bounds_ymax) << ");" << endl;
```

The `bounds_xmin/xmax/ymin/ymax` values are already parsed and stored in local variables at `swf.cpp:1897` for DefineShape. They just need to be forwarded to the emit.

#### 2b. tag_stubs.c / tag.h: store character bounds table

Add a new table `ng_char_bounds` (similar to `ng_textfields`):

```c
#define MAX_CHAR_BOUNDS_NG 256

typedef struct {
    size_t char_id;
    s32 xmin, xmax, ymin, ymax;  // twips
} NGCharBounds;

static NGCharBounds ng_char_bounds[MAX_CHAR_BOUNDS_NG];
static size_t ng_char_bounds_count = 0;
```

Updated `tagDefineShape` signature:
```c
void tagDefineShape(SWFAppContext* app_context, CharacterType type, size_t char_id,
    size_t shape_offset, size_t shape_size,
    s32 bounds_xmin, s32 bounds_xmax, s32 bounds_ymin, s32 bounds_ymax);
```

Implementation stores the bounds in `ng_char_bounds`.

Add helper:
```c
int ng_getCharBounds(size_t char_id, s32* out_xmin, s32* out_xmax, s32* out_ymin, s32* out_ymax);
```

#### 2c. action.c: use character bounds when computing sprite _width/_height

In `mcGetEffectiveSize`, when `mc->width == 0`, attempt to look up character bounds.

The challenge: `mc` (a sprite) doesn't directly know its char_id. The `mc->name` (instance_name) → look up `ng_display` → find the `char_id` for that depth → look up `ng_char_bounds` for the contained shape char_id.

This is a chain: sprite `mc` → `ng_display` entry (has sprite_idx) → sprite definition has shapes inside → those shapes have bounds.

**Simpler approach**: When `tagDefineSprite` is called, look up the sprite's children (from sprite frame funcs) and record the accumulated bounds. But this is complex because sprite frame funcs are C functions.

**Alternative simpler approach**: When querying `_width`/`_height` for a MovieClip backed by a sprite, compute the bounds from the **transform_data** of the CHILDREN of the sprite's display entries. Each child is a shape at some transform; the union of (transform * shape_bounds) gives the sprite bounds.

For the `frame_size_translated` tests: the sprites (char_id=2) each contain exactly one shape (char_id=1) at identity transform inside the sprite's display list. The sprite is then placed on root at some offset.

**Pragmatic approach for Phase 2**: In `syncTransformIfNeeded` / `mcGetEffectiveSize`, if `mc->width == 0`:
1. Look up the sprite's display entries (the children of the sprite in `ng_display`)
2. For each child, look up its char bounds via `ng_getCharBounds`
3. Transform those bounds by the child's local transform
4. Return the union bounds as width/height

This requires `ng_display` to track parent-child relationships (already done via `parent_display_idx`) and shape char_ids (already tracked via `shape_offset`/`shape_size`... actually char_id is needed).

**Simpler still**: Store char_id in `ng_display` entries (it's available when `tagDefineShape` / `tagPlaceObject2` is called). Then look up bounds directly.

Looking at the existing `ng_display` struct in `tag_stubs.c`, we already have `char_id` in there.

**Implementation steps**:
1. Add `ng_char_bounds` table and populate it from `tagDefineShape`
2. In `mcGetEffectiveSize`, if `mc->width == 0`, look up sprite's `ng_display` children, get their `char_id`, look up bounds, return max bounds

**Verification**:
```bash
python3 ruffle-tests/verify_output.py --test=frame_size_translated_positive --diff --verbose
```
Expected: lines 4-5, 9-10 now show "10" instead of "0".

---

### Phase 3: Content bounds for `_root._width`/`_height` and sprites

**Effort**: Medium
**Impact**: `frame_size_translated_*` gains 2 more lines (14-15). Unblocks `stage_object_properties` _width/_height.

**Change**: `SWFModernRuntime/src/actionmodern/action.c`

Change `root_movieclip.width` initialization from `550.0f` → `0.0f`.

In `mcGetEffectiveSize`, special-case root: when `mc == &root_movieclip`:
1. Iterate over all root-level `ng_display` entries (those with `parent_display_idx == SIZE_MAX`)
2. For each entry, get the child's char bounds and transform
3. Compute the union of all (world-space) bounding boxes
4. Return the union width and height

For sprites (non-root clips), the same logic applies but iterate over `ng_display` entries whose `parent_display_idx` points to the sprite's entry.

**Formula for world-space bounds of a child**:
- child has transform T and char bounds (xmin, xmax, ymin, ymax) in twips
- Transform the 4 corners of the AABB through T (rotation can change the bounds)
- The union of all 4 transformed corners gives world-space AABB

Note: the transform_data matrix uses twips, so divide by 20 for pixels.

**Key values for verification**:
- `frame_size_translated_positive`: root has two sprites at (125,175) and (150,150), each 10×10px. Root bounds: x=[120,155], y=[145,180] → width=35, height=35.
- `frame_size_translated_negative`: shapes at (-50,-50) and (50,0), each 10×10px. Root bounds: x=[-55,55], y=[-55,5] → width=110, height=60.

**Verification**:
```bash
python3 ruffle-tests/verify_output.py --test=frame_size_translated_positive --diff --verbose
python3 ruffle-tests/verify_output.py --test=frame_size_translated_negative --diff --verbose
```
Expected: lines 14-15 now correct (35/35 and 110/60 respectively).

---

### Phase 4: Extract rotation/scale from PlaceObject transform matrix

**Effort**: Small-medium
**Impact**: `stage_object_properties` gains _rotation, _xscale, _yscale values. Partial improvement (maybe +5-10 lines).

**Change**: `SWFModernRuntime/src/libswf/tag_stubs.c` and `action.c`

Add to tag_stubs.c:
```c
// Get scale/rotation from the PlaceObject matrix at a given depth.
// Returns 1 if found, 0 if not. out_xscale and out_yscale are in percent (100=100%).
// out_rotation is in degrees.
int ng_getTransformScaleRotation(size_t depth,
    float* out_xscale, float* out_yscale, float* out_rotation);
```

Implementation reads the transform matrix for the display entry at `depth`:
```c
float m00 = transform_data[tid][0];   // scaleX * cos(rot)
float m10 = transform_data[tid][1];   // scaleX * sin(rot)
float m01 = transform_data[tid][4];   // -scaleY * sin(rot)  (or SkewY)
float m11 = transform_data[tid][5];   // scaleY * cos(rot)

// Note: in SWF, scale components are in "SWF units" (unitless ratio, 1.0 = 100%)
*out_xscale = sqrtf(m00*m00 + m10*m10) * 100.0f;
*out_yscale = sqrtf(m01*m01 + m11*m11) * 100.0f;
*out_rotation = atan2f(m10, m00) * 180.0f / M_PI;  // degrees
```

Update `syncTransformIfNeeded` in action.c to also sync rotation/xscale/yscale:
```c
float xscale, yscale, rotation;
if (ng_getTransformScaleRotation(depth, &xscale, &yscale, &rotation)) {
    if (!(mc->as_set_flags & 4)) mc->xscale = xscale;
    if (!(mc->as_set_flags & 8)) mc->yscale = yscale;
    if (!(mc->as_set_flags & 16)) mc->rotation = rotation;
}
```

Add `as_set_flags` bits 4=xscale, 8=yscale, 16=rotation (currently only 1=x, 2=y are used).

**Verification**:
```bash
python3 ruffle-tests/verify_output.py --test=stage_object_properties --diff --verbose
```

---

### Phase 5: Stage object properties initialization and normalization

**Effort**: Medium
**Impact**: `stage_scale_mode` (major improvement), `stage_display_state` (partial).

**Changes**: `SWFModernRuntime/src/actionmodern/action.c:9920`

When initializing `g_stage_obj`, set these properties:

```c
// Stage.scaleMode (default: "showAll")
setStrProperty(app_context, g_stage_obj, "scaleMode", "showAll");

// Stage.align (default: "" = centered)
setStrProperty(app_context, g_stage_obj, "align", "");

// Stage.displayState (default: "normal")
setStrProperty(app_context, g_stage_obj, "displayState", "normal");

// Stage.width / Stage.height (from SWF frame dimensions)
setF64Property(app_context, g_stage_obj, "width", FRAME_WIDTH);
setF64Property(app_context, g_stage_obj, "height", FRAME_HEIGHT);

// Stage.showMenu (default: true)
setF64Property(app_context, g_stage_obj, "showMenu", 1.0);

// Stage.quality (default: "HIGH")
setStrProperty(app_context, g_stage_obj, "quality", "HIGH");
```

**Stage.scaleMode setter** (via addProperty or custom GetMember/SetMember):

Map input to canonical form (case-insensitive):
- "showall" → "showAll"
- "noscale" → "noScale"
- "exactfit" → "exactFit"
- "noborder" → "noBorder"
- Unrecognized → keep previous value

**Stage.align setter** normalization:
```
1. Filter chars: keep only L, T, R, B (case-insensitive)
2. Convert to uppercase
3. Deduplicate (first occurrence wins)
4. Canonical order: L if present, then T, then R, then B
```

Examples: "TL" → "LT", "BR" → "RB", "r" → "R", "asdf" → "" (no valid chars), "TllLBbbt..." → "LTRB"

**Stage.displayState setter**:
- "normal" (case-insensitive) → "normal"; fires `Stage.onFullScreen(false)` if previously "fullScreen"
- "fullScreen" (case-insensitive) → "fullScreen"; fires `Stage.onFullScreen(true)` if previously "normal"
- Invalid → no change

**Registering setters**: Use the existing `addProperty` mechanism (if implemented) or intercept in `actionSetMember` with a check for `g_stage_obj`. The latter is simpler:

In `actionSetMember`, after the normal property write, check if the object is `g_stage_obj` and if the property name is "scaleMode" / "align" / "displayState" — then overwrite with the normalized value.

Similarly in `actionGetMember`, if the object is `g_stage_obj` and property is "width"/"height", return the frame dimensions dynamically (so they're always current).

**Stage.onFullScreen dispatch**:
```c
// After changing displayState, call Stage.onFullScreen(bFull) if it exists
ActionVar* handler = getProperty(g_stage_obj, "onFullScreen", 11);
if (handler && handler->type == ACTION_STACK_VALUE_FUNCTION) {
    ActionVar bool_arg = {0};
    bool_arg.type = ACTION_STACK_VALUE_BOOLEAN;
    bool_arg.data.numeric_value = (is_fullscreen ? 1 : 0);
    callFunction(app_context, handler, &bool_arg, 1, NULL);
}
```

**Verification**:
```bash
python3 ruffle-tests/verify_output.py --test=stage_scale_mode --diff --verbose
python3 ruffle-tests/verify_output.py --test=stage_display_state --diff --verbose
```

---

### Phase 6: Sprite context tracking for GetProperty/SetProperty

**Effort**: Medium-large
**Impact**: `stage_object_properties` gains _x, _y, _name, _target (many lines). Also benefits `stage_object_children`, `stage_object_properties_swf6`.

**Background**:

When `sprite_2_frame_0` calls `script_1`, that script runs "on" sprite_2. AVM1 semantics: `GetProperty("", 0)` gets the `_x` of the clip the script belongs to, NOT root. Currently `getMovieClipByTarget("")` always returns `&root_movieclip`.

**Change**: `SWFModernRuntime/src/actionmodern/action.c`

The `g_current_context` global already exists. The fix is to use it in `getMovieClipByTarget`:

```c
static MovieClip* getMovieClipByTarget(const char* target) {
    if (!target || strlen(target) == 0) {
        // "" = current clip context (not necessarily root)
        return g_current_context ? g_current_context : &root_movieclip;
    }
    if (strcmp(target, "_root") == 0 || strcmp(target, "/") == 0) {
        return &root_movieclip;
    }
    // ... other paths
    return NULL;
}
```

Then, when a sprite's frame function runs, we set `g_current_context` to the sprite's MovieClip:

In `tag_stubs.c`'s `tagShowFrame` (or wherever sprite frames are executed), before calling `sprite_frame_func(app_context)`, call `actionSetCurrentContext(sprite_mc)`. After, restore to `NULL`.

The sprite's MovieClip must exist in the `child_mc_cache`. When `findOrCreateMovieClip(name, parent)` creates a MovieClip for a sprite, it already:
- Sets `mc->name = instance_name`
- Sets `mc->target` from parent path

We need to call `syncTransformIfNeeded` in the sprite context to populate `mc->x`, `mc->y`, `mc->rotation`, `mc->xscale`, `mc->yscale` from the display list.

**Additional fix for _name/_target**: Currently `root_movieclip.name = ""` and `root_movieclip.target = "/"`. For a sprite named "clip" placed at depth 1, the MovieClip from the cache has `name = "clip"` and `target = "/clip"`. If `g_current_context` points to that MovieClip, then `GetProperty("", 13)` (_name) returns "clip" and `GetProperty("", 11)` (_target) returns "/clip". ✓

**Verification**:
```bash
python3 ruffle-tests/verify_output.py --test=stage_object_properties --diff --verbose
```

---

### Phase 7: `_visible` returns boolean not float

**Effort**: Trivial
**Impact**: `stage_object_properties` _visible shows "true" instead of "1".

**Background**: `actionGetProperty` case 7 (`_visible`) returns a float (0.0f or 1.0f). When traced, a float 1.0 becomes "1", but Flash's `_visible` property when read returns a proper boolean that traces as "true"/"false".

**Change**: In `actionGetProperty` case 7, push a BOOLEAN ActionVar:
```c
case 7:  // _visible
    PUSH(ACTION_STACK_VALUE_BOOLEAN, mc ? (mc->visible ? 1ULL : 0ULL) : 1ULL);
    return;
```

Same fix needed in `actionGetVariable` and `mcGetPropertyByName` wherever `_visible` is returned.

**Verification**: Part of stage_object_properties test.

---

### Phase 8: Stage children enumeration

**Effort**: Medium
**Impact**: `stage_object_enumerate` (1/5 → maybe 4/5), `stage_object_children` (some improvements).

**Background**: `stage_object_enumerate` does `for (var name in Stage)` and expects to find clip names (`clip1`, `clip2`, `clip3`). `stage_object_children` expects `_level0` / `_flash0` / `_level` / `_flash` to resolve to `_level0`.

**`stage_object_enumerate`**:

Flash's `Stage` object, when enumerated with `for-in`, returns the names of all root-level movie clips. This requires Stage's `for-in` to yield child clip names.

Implementation: Override Stage object's enumeration. When `actionEnumerate` encounters `g_stage_obj`, iterate over `ng_display` entries (root-level sprites) and push their `instance_name` values onto the stack.

This can be done by adding a special marker to `g_stage_obj` that signals custom enumeration, then handling it in `actionEnumerate2` / `actionEnumerate`.

**`stage_object_children` `_level0` aliases**:

Flash supports `_level0`, `_flash0`, `_level`, `_flash` as aliases for `_root`. In `actionGetVariable`, if the variable name matches these patterns (case-insensitive), return the root MovieClip.

Also: `_root['_x']` → should return the string `"_level0._x"` (a target-path string), not 0. This is the _target path for the `_x` property accessed from root. This requires property path string construction which is complex.

The simpler wins in `stage_object_children`:
- Add `_level0`, `_flash0`, `_level`, `_flash` → root_movieclip resolution
- Fix `delete clip` returning false after-lookup (scope issue)

**Verification**:
```bash
python3 ruffle-tests/verify_output.py --test=stage_object_enumerate --diff --verbose
python3 ruffle-tests/verify_output.py --test=stage_object_children --diff --verbose
```

---

### Phase 9 (COMPLETE): Mouse input simulation

**Effort**: Large (infrastructure) — **Done**
**Impact**: `frame_size_translated_*` line 21 ("Pressed shape1") — **Now passing**

Input event injection is fully implemented (see `SWFRecompDocs/plans/input-event-injection.md`):
1. `verify_output.py` preprocesses `input.json` → line-based event file, passed as `argv[1]`
2. C event pump in `swf_core.c` delivers events at tick boundaries
3. Full button state machine with shape hit-testing fires `onPress`/`onRelease` callbacks

Both `frame_size_translated_positive` and `frame_size_translated_negative` now pass 21/21 (100%).

---

## Implementation Order and Dependencies

```
Phase 1 (F64 bug) ─── independent, do first
Phase 2 (shape bounds) ─── independent of Phase 1
Phase 3 (content bounds) ─── requires Phase 2 (to know shape sizes)
Phase 4 (scale/rotation sync) ─── independent, requires ng_getTransformScaleRotation
Phase 5 (Stage props) ─── independent of Phase 1-4
Phase 6 (sprite context) ─── independent, enables Phase 7
Phase 7 (_visible boolean) ─── trivial, do alongside Phase 6
Phase 8 (Stage children) ─── partially depends on Phase 6
Phase 9 (mouse) ─── deferred
```

## Files to Modify

| File | Phases | Changes |
|------|--------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | 1,3,4,5,6,7,8 | F64 bug fix; root content bounds; Stage init; `getMovieClipByTarget("") → g_current_context`; sprite context set/restore; _visible as boolean |
| `SWFModernRuntime/src/libswf/tag_stubs.c` | 2,4,8 | `ng_char_bounds` table; `ng_getTransformScaleRotation`; sprite frame execution context |
| `SWFRecomp/src/swf.cpp` | 2 | Emit bounds params in `tagDefineShape` calls |
| `SWFModernRuntime/include/libswf/tag.h` | 2 | Updated `tagDefineShape` signature |

## Estimated Test Impact

| Phase | Tests Passing Before | Tests Passing After | Δ |
|-------|---------------------|---------------------|---|
| Phase 1 | baseline | +`stage_property_representation` (586 lines) | +1 |
| Phase 2 | +0 new full passes | `frame_size_translated_*` 14→18/21 | 0 |
| Phase 3 | +0 | `frame_size_translated_*` 18→20/21 | +0 (partial) |
| Phase 4 | +0 | `stage_object_properties` 173→~185/241 | 0 |
| Phase 5 | +0 | `stage_scale_mode` major improvement; `stage_display_state` partial | maybe +1-2 |
| Phase 6+7 | +0 | `stage_object_properties` ~185→~220/241; `stage_object_children` improvement | 0 |
| Phase 8 | +0 | `stage_object_enumerate` 1→4/5; | maybe +1 |

**Summary**: Phase 1 alone gives +1 full pass (stage_property_representation). Phases 2+3 get frame_size_translated to 95%. Phases 4-8 improve the partially-passing tests.

## Verification Commands

```bash
# Phase 1
python3 ruffle-tests/verify_output.py --test=stage_property_representation --diff --verbose

# Phases 2+3
python3 ruffle-tests/verify_output.py --test=frame_size_translated_positive --diff --verbose
python3 ruffle-tests/verify_output.py --test=frame_size_translated_negative --diff --verbose

# Phase 4+6+7
python3 ruffle-tests/verify_output.py --test=stage_object_properties --diff --verbose
python3 ruffle-tests/verify_output.py --test=stage_object_properties_swf6 --diff --verbose

# Phase 5
python3 ruffle-tests/verify_output.py --test=stage_scale_mode --diff --verbose
python3 ruffle-tests/verify_output.py --test=stage_display_state --diff --verbose

# Phase 8
python3 ruffle-tests/verify_output.py --test=stage_object_enumerate --diff --verbose
python3 ruffle-tests/verify_output.py --test=stage_object_children --diff --verbose
```
