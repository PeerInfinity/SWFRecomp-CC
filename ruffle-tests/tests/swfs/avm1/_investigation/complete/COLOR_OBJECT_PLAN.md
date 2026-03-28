# Color Object Implementation Plan
<!-- TESTS: color, color_transform, transform, issue_1906, matrix -->

<!-- PLAN_META
id: COLOR_OBJECT
status: complete
phases:
  - id: 1
    name: "AVM1 Color Object"
    status: complete
  - id: 2
    name: "flash.geom.ColorTransform"
    status: complete
  - id: 3
    name: "flash.geom.Matrix (toString improvement)"
    status: complete
  - id: 4
    name: "Transform Object with Live Clip Data"
    status: complete
  - id: Dependency
    name: "Graph"
    status: complete
dependencies:
  - plan: GEOMETRY_CLASSES
    type: complements
    reason: "Color/ColorTransform shares geometry class infrastructure"
blockers: []
-->

Last updated: 2026-02-22

## Status: MOSTLY COMPLETE

All 5 tests now PASS on CI. The Color class, flash.geom.ColorTransform, flash.geom.Matrix, flash.geom.Transform, and flash.geom.Point/Rectangle are all functional.

### Current Results

| Test | Status | Notes |
|------|--------|-------|
| color | **PASS** ✅ | Color constructor, getRGB/setRGB, getTransform/setTransform all functional |
| color_transform | **PASS** ✅ | flash.geom.ColorTransform constructor and methods working |
| transform | **PASS** ✅ | flash.geom.Transform wired to MovieClip, pixelBounds for nested sprites |
| issue_1906 | **PASS** ✅ | |
| matrix | **PASS** ✅ | flash.geom.Matrix toString and methods working |

### Implementation Summary

- **Color class**: Constructor takes MovieClip target; getRGB/setRGB/getTransform/setTransform all functional via `ng_getColorTransform()`/`ng_setColorTransform()` in NO_GRAPHICS mode
- **flash.geom.ColorTransform**: Functional constructor with 8 parameters (ra,ga,ba,aa,rb,gb,bb,ab)
- **flash.geom.Matrix**: Functional constructor, toString, identity values
- **flash.geom.Transform**: `createTransformObject()` reads actual clip data (no longer hardcoded identity)
- **Color.prototype methods**: getRGB, setRGB, getTransform, setTransform registered and functional

### Remaining Work

Most Color/Transform infrastructure is complete. Remaining gaps:
- Color transform setters that modify actual clip rendering (NO_GRAPHICS mode stores values but doesn't apply to display)
- Some edge cases in flash.geom API (concat, invert, etc.) may still be stubs

## Overview (original)

The Color object family spans two related but distinct APIs: the **AVM1 `Color` class** (Flash 5+) and the **AS2 `flash.geom` package** (Flash 8+) containing `ColorTransform`, `Matrix`, and `Transform`. Together they affect 4 failing tests (+ `issue_1906`), and improving them also benefits the `matrix`, `point`, and `rectangle` tests which share the `flash.geom` infrastructure.

---

## Test Inventory

### `color` test (57 expected lines, num_frames=1)

Tests the AVM1 Color object:
1. `new Color(mc)` — constructor with MovieClip target
2. `c.target` — returns `"_level0.mc"` (target path string)
3. `c.getTransform()` — returns object with `{ra, ga, ba, aa, rb, gb, bb, ab}` (percentage multipliers + offsets)
4. `c.setTransform(obj)` — reads ra/ga/ba/aa/rb/gb/bb/ab from param object, applies to clip
5. `c.getRGB()` — returns packed integer `(rb << 16) | (gb << 8) | bb` (from offset channels)
6. `c.setRGB(n)` — zeroes all multipliers, unpacks integer to rb/gb/bb offsets
7. Pre-tinted clip and button: reads non-default transform values
8. Invalid targets (`undefined`, `""`, `0`): methods return `undefined`
9. Edge cases: NaN, string "0x64", undefined, true, Infinity, Object.prototype.ab fallback, overflow values

**Key semantics**:
- Color transform uses **percentage** multipliers (100 = 1.0x) and **absolute** offsets (-255 to 255)
- `getTransform()` returns a plain Object (not a ColorTransform instance)
- `setTransform()` only applies properties that exist on the param object (missing = keep current)
- `setRGB()` sets ra=ga=ba=0 (zero multipliers), rb/gb/bb from integer decomposition
- Pre-tinted clips have non-identity transforms set by PlaceObject2/3 CXFORMWITHALPHA
- Values are NOT clamped — `ra=-12800` and `gb=32704` are valid

### `color_transform` test (48 expected lines, num_frames=1)

Tests flash.geom.ColorTransform:
1. Constructor: `new flash.geom.ColorTransform(rMult, gMult, bMult, aMult, rOff, gOff, bOff, aOff)` — 0-8 args
2. Default values: multipliers=1.0, offsets=0 when args omitted
3. `ct.rgb` getter — returns packed `(rOff << 16) | (gOff << 8) | bOff`
4. `ct.toString()` — returns `(redMultiplier=1, greenMultiplier=1, ..., alphaOffset=0)`
5. `ct.rgb = 0xFF0000` setter — zeroes all multipliers, sets offsets from color
6. Property access: `ct.redOffset`, `ct.greenMultiplier`, etc.
7. `ct.concat(other)` — composes two color transforms: `result.mult = a.mult * b.mult`, `result.off = a.off * b.mult + b.off`
8. No value clamping: multiplier=1000, offset=1000.1 are valid
9. Large values: 8589934592 (> 32-bit), NaN, string "Test123" for greenOffset
10. Prototype enumeration: toString, concat, rgb, blueOffset, greenOffset, redOffset, alphaOffset, blueMultiplier, greenMultiplier, redMultiplier, alphaMultiplier (in this order)
11. Last line: `new flash.geom.ColorTransform()` with no args → identity transform toString

### `transform` test (70 expected lines, num_frames=1)

Tests flash.geom.Transform:
1. `clip.clip.transform` — reads Transform object from nested clip
2. `t.matrix` — returns Matrix with actual clip transform values (tx=71, ty=60)
3. `t.colorTransform` — returns ColorTransform with actual clip color transform
4. `t.concatenatedMatrix` — composed through parent chain (a=2, tx=352)
5. `t.concatenatedColorTransform` — composed through parent chain
6. `t.pixelBounds` — returns Rectangle(x, y, w, h)
7. `t.matrix = new Matrix()` — setter: resets clip matrix to identity
8. `clip.clip._x = 50` then read `t.matrix` → tx=50 (live reference to clip)
9. `new flash.geom.Transform(clip.clip)` constructor — creates new Transform wrapper
10. Setters: `clip.transform.matrix = new Matrix()`, `clip.transform.colorTransform = new ColorTransform(...)`
11. `clip.clip.transform = clip2.transform` — copy transform between clips
12. `t.matrix = {}` — no-op (not a Matrix instance)
13. `t.matrix.tx = 999` then `t.matrix.tx` → 10 (Matrix is a copy, not live reference)
14. `clip.transform == clip.transform` → false (new object each access)
15. `new Transform()` with no args → undefined

### `issue_1906` test (4 expected lines, num_frames=2)

Tests that `Color.setTransform()` does NOT affect `_x`/`_y` position:
1. Creates Color objects for two MovieClips
2. Calls `setTransform()` with color transform properties
3. Reads `mc._x` and `mc2._x` — both should be `0`

---

## Implementation Phases

### Phase 1: AVM1 Color Object

**Goal**: Implement `new Color(target)` with getTransform/setTransform/getRGB/setRGB. This fixes the `color` and `issue_1906` tests.

#### 1a. Per-MovieClip color transform storage

In trace-only mode (NO_GRAPHICS), MovieClips don't have color transform data. We need to add per-clip storage.

In `tag_stubs.c` or `action.c`, add a structure to track per-clip color transforms:

```c
typedef struct {
    double ra, ga, ba, aa;  // percentage multipliers (100 = 1.0x)
    double rb, gb, bb, ab;  // absolute offsets
} AVM1ColorTransform;
```

Each MovieClip (identified by depth or target path) needs an associated `AVM1ColorTransform`. Default values: `{ra=100, ga=100, ba=100, aa=100, rb=0, gb=0, bb=0, ab=0}`.

For pre-tinted clips (PlaceObject2/3 with CXFORMWITHALPHA), the recompiler already emits `cxform` data. We need to pass these initial values to the runtime so `getTransform()` returns correct values on pre-tinted clips.

**Approach**: Store `AVM1ColorTransform` on the MovieClip display list entry. In trace mode, the display list entries are managed in `tag_stubs.c`. Add a `color_transform` field to whatever represents a placed object.

**Recompiler change**: When PlaceObject2/3 has CXFORMWITHALPHA, emit the initial color transform values so the runtime can store them.

#### 1b. Color constructor

In `actionNewObject()`, handle `"Color"` constructor:

```c
else if (strcmp(ctor_name, "Color") == 0)
{
    ASObject* color_obj = allocObject(app_context, 4);
    // Store target reference
    if (arg_count >= 1) {
        // arg is the target MovieClip path/reference
        ActionVar target_var = /* pop arg */;
        // Store target path string
        // Resolve to MovieClip if it's a string path
    }
    // Set __proto__ to Color.prototype
    // Push result
}
```

#### 1c. Color.prototype methods

**`target` property**: Returns the target path as string (e.g., `"_level0.mc"`). This is the path used in the constructor.

**`getTransform()`**: Look up target clip's AVM1ColorTransform. Return a new plain Object with 8 properties: ra, ga, ba, aa, rb, gb, bb, ab. If target is invalid, return undefined.

**`setTransform(obj)`**: Read ra/ga/ba/aa/rb/gb/bb/ab from the parameter object (using `getMember`). Only update properties that exist on the param object. Store updated values in the clip's AVM1ColorTransform. Must NOT affect _x/_y.

Type coercion for setTransform values:
- `NaN` → 0 (for ra/ga/ba offsets)
- `undefined` → 0
- `"0x64"` → 100 (numeric string coercion)
- `true` → 1
- `Infinity` → 0 (for gb, based on test output showing `gb: 0` after `gb=Infinity` — actually need to check)
- Actually, from test line 26: `ra: 0, ga: 0, ba: 100, aa: 0.78125` — NaN→0, undefined→0, "0x64"→100, aa=1→0.78125 (wait that doesn't match...)

Let me re-examine the test more carefully. The script sets:
- `ra=NaN` → output shows `ra: 0`
- `ba="0x64"` → output shows `ba: 100`
- `ga=undefined` → output shows `ga: 0`
- `aa=1` → output shows `aa: 0.78125`

Wait — `aa=1` giving `0.78125` doesn't make sense unless there's leftover state. Looking at the sequence: setTransform 3 set `aa: 50`, then setTransform 4 has `aa=1`. So `1` → `0.78125`? That's weird. Unless `1` is treated as 1% or... Actually the output shows `ra: 0, ga: 0, ba: 100, aa: 0.78125`. The `aa` was 50 before, and now we set `aa=1`, but get 0.78125. This suggests the value `1` IS stored as `1`, but shown differently... No wait, 0.78125 = 1/1.28? No. 0.78125 = 200/256. Hmm.

Actually, I think the issue is that `setTransform` with weird parameters uses `valueOf()` coercion and Flash's internal representation. The `aa` property: `1` is stored as `1`, but `getTransform()` returns it differently because of internal precision. Actually, looking more carefully: `0.78125 = 50/64`. Hmm that's not it either.

Actually wait — re-reading the test script, the weirdness is probably because not all 8 properties are set in each call. setTransform 4 only sets some properties (the "weird params"), and others are kept from setTransform 3. Let me look at the recompiled script to understand the exact params being set.

Actually, I should just note in the plan that the exact coercion behavior needs to be determined from the recompiled script analysis, and move on.

**`getRGB()`**: Returns `(rb << 16) | (gb << 8) | bb` as a signed integer. For negative offsets, the result can be negative. If target is invalid, return undefined.

**`setRGB(n)`**:
- `ra = ga = ba = 0` (zero all multipliers)
- `rb = (n >> 16) & 0xFF`
- `gb = (n >> 8) & 0xFF`
- `bb = n & 0xFF`
- `aa` and `ab` are unchanged

#### 1d. Invalid target handling

When target is `undefined`, `""`, or `0`, the Color object is created but all method calls return `undefined`.

#### Tests fixed by Phase 1

- **color**: ~55/57 lines (nearly full pass)
- **issue_1906**: 4/4 lines (full pass)

---

### Phase 2: flash.geom.ColorTransform

**Goal**: Implement the ColorTransform constructor with property access, toString(), concat(), and rgb getter/setter.

#### 2a. ColorTransform constructor

Replace the stub constructor in `flash.geom` with a functional one:

```c
// new flash.geom.ColorTransform(rMult, gMult, bMult, aMult, rOff, gOff, bOff, aOff)
// Defaults: multipliers=1.0, offsets=0
```

Store 8 properties as f64 on the object: `redMultiplier`, `greenMultiplier`, `blueMultiplier`, `alphaMultiplier`, `redOffset`, `greenOffset`, `blueOffset`, `alphaOffset`.

Constructor argument mapping (0-8 args):
- 0 args: identity (1, 1, 1, 1, 0, 0, 0, 0)
- 1 arg: (rMult, 1, 1, 1, 0, 0, 0, 0)
- ... up to 8 args

No clamping — values like 1000, 8589934592, NaN are stored as-is.

#### 2b. toString()

Format: `(redMultiplier=R, greenMultiplier=G, blueMultiplier=B, alphaMultiplier=A, redOffset=RO, greenOffset=GO, blueOffset=BO, alphaOffset=AO)`

Number formatting rules:
- Integers display without decimal: `1`, `0`, `255`, `1000`
- Fractional values display as-is: `0.5`, `1000.1`
- NaN displays as `NaN`
- Must read current property values (not cached from constructor)

This replaces the current hardcoded `colorTransformToString` that returns a static identity string.

#### 2c. rgb property getter/setter

**Getter**: `Math.floor(redOffset) << 16 | Math.floor(greenOffset) << 8 | Math.floor(blueOffset)` — returns packed integer. (Exact formula needs validation against test output.)

Test output shows:
- `rgb` of `(rOff=255, gOff=25, bOff=0)` → `16718080` (= 0xFF1900 = 255<<16 | 25<<8 | 0) ✓
- After `rgb = 0xFF0000` (16711680): offsets become `(255, 0, 0)`, multipliers become `(0, 0, 0, 1)` — alpha multiplier stays 1

**Setter**: Sets `redMultiplier = greenMultiplier = blueMultiplier = 0`, then:
- `redOffset = (value >> 16) & 0xFF`
- `greenOffset = (value >> 8) & 0xFF`
- `blueOffset = value & 0xFF`
- Alpha multiplier and offset are unchanged.

#### 2d. concat(other)

Composes two color transforms. Formula:
```
result.mult = this.mult * other.mult
result.off = this.off * other.mult + other.off
```

Test verification:
- this = `(0, 0, 0, 1, 255, 0, 0, 0)` (after rgb set)
- other = `(0.5, 0.5, 0.5, 0.5, 0, 255, 0, 50)`
- result rMult = 0*0.5 = 0 → but test shows 0.25...

Wait, let me re-read. The test output for "combine":
```
(redMultiplier=0.25, greenMultiplier=0.25, blueMultiplier=0.25, alphaMultiplier=0.25, redOffset=35, greenOffset=50, blueOffset=65, alphaOffset=80)
```

This is after multiple operations. The state before concat needs to be traced through the script carefully. The concat formula is standard Flash:
```
result.redMultiplier = a.redMultiplier * b.redMultiplier
result.redOffset = a.redOffset * b.redMultiplier + b.redOffset
```

And `concat()` mutates `this` (doesn't return a new object).

#### 2e. Prototype enumeration order

The prototype must enumerate in this order: `toString, concat, rgb, blueOffset, greenOffset, redOffset, alphaOffset, blueMultiplier, greenMultiplier, redMultiplier, alphaMultiplier`

This means properties must be added to the prototype in reverse order (ActionScript enumerates in reverse insertion order).

#### Tests fixed by Phase 2

- **color_transform**: ~45/48 lines (near full pass)

---

### Phase 3: flash.geom.Matrix (toString improvement)

**Goal**: Make Matrix objects return dynamic toString values reflecting actual property values.

#### 3a. Matrix constructor

Replace stub with functional constructor:

```c
// new flash.geom.Matrix(a, b, c, d, tx, ty)
// Defaults: identity (1, 0, 0, 1, 0, 0)
```

Store 6 properties on the object: `a`, `b`, `c`, `d`, `tx`, `ty`.

#### 3b. Dynamic toString()

Format: `(a=A, b=B, c=C, d=D, tx=TX, ty=TY)`

Replace the current static `matrixToString` with a dynamic version that reads property values from the object.

Number formatting: integers without decimal, floats as-is.

#### 3c. Matrix used by Transform

When `transform.matrix` is read, it must create a new Matrix object with the clip's actual transform values (from the 2D affine matrix: a, b, c, d, tx, ty). When set, it must write back to the clip.

#### Tests improved by Phase 3

- **transform**: Improved from 50/70 → ~65/70 (matrix/concatenatedMatrix lines now show correct values)
- **matrix**: Improved from 123/171 (needs full method implementation for bigger gains — that's a separate plan)

---

### Phase 4: Transform Object with Live Clip Data

**Goal**: Make `mc.transform` return objects with actual clip transform/color data, support setters, and handle concatenation through parent chain.

#### 4a. Transform reads actual clip data

`createTransformObject()` currently creates static identity objects. It needs to:

1. **matrix**: Read from the clip's placed transform (from PlaceObject2/3 Matrix field + any runtime _x/_y changes). Return as Matrix object with `a, b, c, d, tx, ty` properties.

2. **colorTransform**: Read from the clip's color transform (CXFORMWITHALPHA from PlaceObject2/3 + any Color.setTransform changes). Return as ColorTransform object with 8 properties.

3. **concatenatedMatrix**: Compose the clip's matrix with all parent matrices up to _root. Formula: `composed = parent_composed * local`.

4. **concatenatedColorTransform**: Compose the clip's color transform with all parent color transforms. Formula: `composed.mult = parent.mult * local.mult`, `composed.off = parent.off * local.mult + local.off`.

5. **pixelBounds**: Return Rectangle based on composed transform applied to clip bounds.

#### 4b. Transform setters

- `t.matrix = new Matrix(...)`: Write the matrix values back to the clip's placed transform. Update _x, _y, _xscale, _yscale, _rotation accordingly.
- `t.colorTransform = new ColorTransform(...)`: Write to clip's color transform.
- `clip.transform = otherClip.transform`: Copy both matrix and colorTransform from other clip.
- `t.matrix = {}`: No-op (must check that value is a Matrix instance? Or has required properties?)
- `clip.transform = {}`: No-op

#### 4c. New object per access

Each `.transform` access returns a NEW Transform object. Each `.matrix`/`.colorTransform` access returns a NEW Matrix/ColorTransform copy. This means:
- `clip.transform == clip.transform` → false
- `t.matrix == t.matrix` → false
- `t.matrix.tx = 999; trace(t.matrix.tx)` → original value (not 999)

#### 4d. new Transform(clip) constructor

`new flash.geom.Transform(clip)` creates a Transform wrapper bound to the clip. Equivalent to reading `clip.transform`. With 0 args → undefined.

#### 4e. Recompiler changes

The recompiler needs to pass per-clip transform data (Matrix + CXFORMWITHALPHA) to the runtime at init time:
- PlaceObject2/3 Matrix fields: a, b, c, d, tx, ty (in twips)
- PlaceObject2/3 CXFORMWITHALPHA fields: ra, ga, ba, aa (multipliers as fractions), rb, gb, bb, ab (offsets)
- Parent-child hierarchy information for concatenation

For the `transform` test specifically, the test SWF has nested clips (`clip.clip`) with non-identity transforms and color transforms set in the SWF tags.

#### Tests fixed by Phase 4

- **transform**: ~67/70 lines (near full pass)
- **issue_1906**: Maintained at 4/4

---

## Phase Dependency Graph

```
Phase 1 (Color)  ──→  Phase 4 (Transform live data)
                       ↑
Phase 2 (ColorTransform) ─┘
                       ↑
Phase 3 (Matrix) ──────┘
```

Phase 1 (Color) is independent and can be implemented first.
Phases 2 and 3 are independent of each other but both needed by Phase 4.
Phase 4 depends on all three.

---

## Estimated Test Impact

| Phase | Tests Fixed / Improved | New Matches | Cumulative |
|-------|----------------------|-------------|------------|
| 1 | color (~55/57), issue_1906 (4/4) | +55 | ~116/179 |
| 2 | color_transform (~45/48) | +38 | ~154/179 |
| 3 | transform matrix lines | +5 | ~159/179 |
| 4 | transform remaining lines | +12 | ~171/179 |
| **Total** | | | **~171/179 (96%)** |

**Net new passing tests**: color, color_transform, issue_1906 likely become full passes. transform goes from 71% to ~96%.

---

## Files to Modify

### Runtime (SWFModernRuntime/)

| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | Color constructor in actionNewObject, Color.prototype methods (getTransform/setTransform/getRGB/setRGB/target), ColorTransform constructor/properties/toString/concat/rgb, Matrix constructor/properties/toString, Transform improvements, createTransformObject rewrite |
| `include/actionmodern/action.h` | Any new function declarations |

### Recompiler (SWFRecomp/)

| File | Changes |
|------|---------|
| `src/swf.cpp` | Emit PlaceObject2/3 CXFORMWITHALPHA values for runtime color transform init, emit Matrix values |

### Runtime stubs (SWFModernRuntime/)

| File | Changes |
|------|---------|
| `src/libswf/tag_stubs.c` | Per-clip color transform storage, initial color transform from PlaceObject CXFORM |
| `include/libswf/tag.h` | Updated signatures for transform data passing |

---

## Key Design Decisions

1. **AVM1 Color vs AS2 ColorTransform**: These are DIFFERENT classes. `Color.getTransform()` returns a plain Object with percentage-based fields (ra=100 means 1.0x). `flash.geom.ColorTransform` stores fractional multipliers (redMultiplier=1.0 means 1.0x). The Color object internally converts between the two representations.

2. **Color transform storage**: The AVM1 Color transform state must persist per-clip across frames. In NO_GRAPHICS mode, we need our own storage since there's no GPU color transform buffer. Use a simple hash map or array keyed by clip depth/path.

3. **Pre-tinted clips**: The recompiler must emit CXFORMWITHALPHA data from PlaceObject2/3 tags so the runtime can initialize clips with non-identity color transforms. This is needed for both Color.getTransform() on pre-tinted clips and Transform.colorTransform.

4. **Dynamic toString**: The current static toString functions must be replaced with dynamic ones that read object properties. This is a breaking change for the Transform object but necessary for correctness.

5. **Concat mutates this**: `ColorTransform.concat()` modifies the calling object in-place (does not return a new object). This matches Flash behavior.

6. **No value clamping**: Both Color and ColorTransform store values as-is without clamping. ra=-12800, multiplier=8589934592, offset=NaN are all valid.

---

## Quick Win Estimate

**Phase 1 alone** (Color object) would fix 2 tests (color + issue_1906) for ~55 net new matching lines. This is a self-contained feature with no dependencies on the other phases.

**Phases 1+2** (Color + ColorTransform) would fix 3 tests for ~93 net new matching lines.

**All 4 phases** would fix 3 tests fully and significantly improve 1 more, for ~110 net new matching lines.
