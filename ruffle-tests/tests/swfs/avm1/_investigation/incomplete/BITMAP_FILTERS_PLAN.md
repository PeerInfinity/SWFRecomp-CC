# Bitmap Filters Plan
<!-- TESTS: bitmap_filters -->

Last updated: 2026-03-27

## Status: NOT STARTED — SEGFAULT at ~line 116/548, multiple gaps

### Test Summary

| Test | Lines | Actual | Match | Status | Root Cause |
|------|-------|--------|-------|--------|------------|
| bitmap_filters | 548 | 116 | 78 | segfault | Missing filter.clone(), missing mc.filters round-trip, missing property coercion |

The test validates all 10 filter classes (`BitmapFilter`, `BevelFilter`, `BlurFilter`,
`ColorMatrixFilter`, `ConvolutionFilter`, `DisplacementMapFilter`, `DropShadowFilter`,
`GlowFilter`, `GradientBevelFilter`, `GradientGlowFilter`) for:
1. Construction and `.clone()` method
2. `mc.filters = [f]` then reading `mc.filters[0]` (round-trip storage)
3. Property get/set with coercion, clamping, and bounds checking

### Current Behavior

- **116 lines output** before SIGSEGV (out of 548 expected)
- **78 lines match** (67% of what was produced)
- Crash occurs during or after ColorMatrixFilter property testing (~line 116)
- Before crash: BitmapFilter (4 lines), BevelFilter (~73 lines), BlurFilter (~22 lines),
  ColorMatrixFilter (~17 lines partial)

### Root Cause Analysis

There are **4 distinct gaps** causing failures:

#### Gap 1: Missing filter.clone() Method (SEGFAULT cause)

No filter prototype has a `clone()` method registered. When the test calls `f.clone()`:
- Property lookup walks the prototype chain
- No `clone` function is found on filter prototypes
- The test calls the result → likely undefined-as-function invocation causes the segfault
- Or: a garbage/stale function pointer on the prototype chain is invoked

**Evidence**: Line 10 expected `[object Object]` for `f.clone()`, actual is `undefined`.
BitmapFilter.clone() correctly returns `undefined` (Flash behavior for the base class),
but BevelFilter.clone(), BlurFilter.clone() etc. should return cloned filter objects.

**Expected behavior per filter type**:
- `BitmapFilter.clone()` → `undefined` (base class has no data to clone)
- All 9 subclass `.clone()` → new instance of same type with identical property values
- `f == f.clone()` → `false` (different objects)

#### Gap 2: mc.filters Getter Returns Empty Array

`action.c:34544-34549`: The `mc.filters` getter always returns `new Array()`:
```c
if (mc != NULL && strncmp(prop_name, "filters", 7) == 0) {
    ASArray* arr = allocArray(app_context, 0);
    PUSH(ACTION_STACK_VALUE_ARRAY, (u64)arr);
    return;
}
```

The setter stores filters on `dynamic_props` (generic path), but the getter ignores
that and always returns empty. So `mc.filters = [f]; mc.filters[0]` always returns
`undefined`.

**Expected behavior**: Flash creates a **copy** of each filter on both set and get:
- `mc.filters = [f]` → stores cloned copies of each filter
- `mc.filters[0]` → returns a fresh clone of the stored filter
- Modifying the returned filter does NOT affect the stored filter (defensive copy)

#### Gap 3: Property Value Coercion and Clamping

Filter properties need native getter/setter behavior with Flash-specific coercion.
Currently filter properties are stored as plain ASObject properties with no validation.

**Missing coercions** (by property type):

| Property Type | Expected Coercion | Current | Examples |
|---------------|-------------------|---------|----------|
| angle | Wrap to (-180, 360] via `fmod` | Raw store | `f.angle = 360` → `0`, `f.angle = 361` → `1` |
| alpha | Clamp [0, 1], 8.8 fixed-point quantize | Raw store | `f.alpha = 0.5` → `0.498039...`, `f.alpha = 1.5` → `1` |
| color | Mask to 24-bit (`& 0xFFFFFF`) | Raw store | `f.color = 16777471` → `255`, `f.color = -305419896` → `13347208` |
| quality | Truncate to int, clamp [0, 15] | Raw store | `f.quality = 2.5` → `2`, `f.quality = 100` → `15` |
| strength | Clamp [0, 255] | Raw store | `f.strength = 256` → `255`, `f.strength = -1` → `0` |
| blurX/blurY | Clamp [0, 255] | Raw store | `f.blurX = -1` → `0`, `f.blurX = 256` → `255` |
| knockout/inner | Boolean coercion | Works | `f.knockout = null` → `false` |
| type | String match ("inner"/"outer"/"full"), else "full" | Raw store | `f.type = "invalid"` → `"full"` |
| distance | No clamping (raw float) | Works | Already correct |
| matrix (ColorMatrix) | Fixed 20-element array, NaN fill | Raw store | `f.matrix = []` → 20×NaN, `f.matrix = [0]` → `[0, NaN×19]` |
| matrix (Convolution) | Dynamic matrixX×matrixY resize | Raw store | Changes when matrixX/matrixY change |
| mode (Displacement) | String enum ("wrap"/"clamp"/"ignore"/"color"), else "wrap" | Raw store | `f.mode = "test"` → `"wrap"` |
| componentX/Y | Truncate to int | Raw store | `f.componentX = -234.5` → `-234` |
| scaleX/Y | Clamp [-65535, 65535] | Raw store | `f.scaleX = 65536` → `65535` |
| colors/alphas/ratios (Gradient) | Array sync (resize together), alpha clamping, max 16 | Raw store | Complex array sync behavior |

#### Gap 4: Gradient Filter Array Synchronization

`GradientBevelFilter` and `GradientGlowFilter` have coupled arrays: `colors`, `alphas`,
`ratios`. Setting one resizes all three to match, with defaults for new elements:
- Setting `f.colors = [1,2,3]` → `alphas` and `ratios` resize to length 3
- Setting `f.ratios = [50]` → `colors` and `alphas` resize to length 1
- Maximum 16 elements
- Alpha values clamped [0, 1] with 8.8 quantization
- Ratio values clamped [0, 255]

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| Filter constructors (all 10) | `action.c` | 38439-38536 |
| Stub constructor macros | `action.c` | 23781-23792 |
| Prototype setup | `action.c` | 24006-24011 |
| mc.filters getter (always empty) | `action.c` | 34544-34549 |
| NATIVE_FILTER type assignment | `action.c` | 36630, 38439+ |
| flash.filters package | `action.c` | 23781 |

### Implementation Plan

#### Phase 1: Fix the Segfault — Implement filter.clone()

Register a `clone` method on each filter subclass prototype. The clone function:

1. Creates a new ASObject with the same prototype chain
2. Sets `native_type = NATIVE_FILTER`
3. Copies all own properties from the source filter to the clone
4. Returns the new object

```c
// Generic filter clone — works for all filter types since they store
// properties as plain ASObject properties
static void filterCloneMethod(SWFAppContext* app_context) {
    // Pop 'this' (the filter object)
    ActionVar this_var = POP_VAR();
    if (this_var.type != ACTION_STACK_VALUE_OBJECT) {
        PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
        return;
    }
    ASObject* src = (ASObject*)(uintptr_t)this_var.data.numeric_value;

    // Create new object with same __proto__
    ASObject* clone = allocObject(app_context);
    clone->native_type = src->native_type;
    // Copy __proto__ from src
    // Copy all own properties from src to clone
    for (int i = 0; i < src->property_count; i++) {
        setProperty(app_context, clone, src->properties[i].name,
                    src->properties[i].name_len, &src->properties[i].value);
    }

    PUSH(ACTION_STACK_VALUE_OBJECT, (u64)clone);
}
```

Register on each filter prototype via `registerProtoMethod` or equivalent.

**BitmapFilter base class**: `clone()` should return `undefined` (not a cloned object).
The 9 subclasses return proper clones.

**Estimated**: ~40 lines for the clone function + ~20 lines for prototype registration.

#### Phase 2: Fix mc.filters Round-Trip

Replace the empty-array getter with proper storage/retrieval:

**Setter** (`actionSetMember` MC path):
- When `prop_name == "filters"` and value is an ARRAY:
  - Clone each filter in the array (using the clone logic from Phase 1)
  - Store the cloned array on the MC (e.g., `mc->filters_array` field or on `dynamic_props`)

**Getter** (`actionGetMember` MC path):
- When `prop_name == "filters"`:
  - Read the stored filters array
  - Clone each filter again (defensive copy)
  - Return the cloned array

**Alternative (simpler)**: Store the array on `dynamic_props` and retrieve from there
instead of the hardcoded empty array. This skips the defensive-copy semantics but
would make `mc.filters[0]` return the stored filter objects.

**Estimated**: ~30 lines for getter fix, ~20 lines for setter with cloning.

#### Phase 3: Property Coercion — Native Getters/Setters

Implement native property coercion for filter objects. Two approaches:

**Approach A: Intercept in actionSetMember/actionGetMember**
When target is `NATIVE_FILTER` and property matches a known filter property name,
apply the coercion before storing / after retrieving.

**Approach B: addProperty virtual getters/setters**
Register virtual properties on filter prototypes using `addProperty`. Each getter
reads from a backing store; each setter applies coercion before storing.

Approach A is simpler for this use case. The coercion rules by property:

```c
// In actionSetMember, when obj->native_type == NATIVE_FILTER:
if (strcmp(name, "angle") == 0) {
    double v = toNumber(value);
    v = fmod(v, 360.0);
    // Store coerced value
}
if (strcmp(name, "alpha") == 0 || strcmp(name, "highlightAlpha") == 0 || ...) {
    double v = toNumber(value);
    v = clamp(v, 0.0, 1.0);
    v = (double)(u8)(v * 255.0) / 255.0;  // 8.8 quantize
    // Store coerced value
}
if (strcmp(name, "color") == 0 || strcmp(name, "highlightColor") == 0 || ...) {
    int32_t v = (int32_t)toNumber(value);
    v = v & 0xFFFFFF;
    // Store coerced value
}
// ... etc for quality, strength, blurX/Y, type, mode, matrix, ...
```

**Estimated**: ~150 lines for all property types.

#### Phase 4: Gradient Array Synchronization

Implement the coupled-array behavior for GradientBevelFilter and GradientGlowFilter.
When `colors`, `alphas`, or `ratios` is set, resize all three arrays to match.

**Estimated**: ~60 lines.

### Priority and Dependencies

| Phase | Unlocks | Complexity | Dependencies |
|-------|---------|-----------|--------------|
| 1 (clone) | Fixes SEGFAULT, enables remaining output | Low | None |
| 2 (mc.filters) | ~20 lines output (filter readback) | Low | Phase 1 |
| 3 (coercion) | ~300 lines output (property validation) | Medium | None |
| 4 (gradient arrays) | ~50 lines output (gradient filter tests) | Medium | Phase 3 |

**Recommended order**: Phase 1 → Phase 3 → Phase 2 → Phase 4

Phase 1 is the critical fix — it eliminates the segfault and allows the test to run
to completion. Phase 3 is where most of the line-count improvement comes from.

### Total Estimated Scope

~300 lines of C code across 4 phases. No external infrastructure dependencies.
All work is in `action.c`.
