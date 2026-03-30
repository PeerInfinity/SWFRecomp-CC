# BitmapFilter .clone() Implementation Plan
<!-- TESTS: bitmap_filters -->

<!-- PLAN_META
id: BITMAP_FILTER_CLONE
status: incomplete
phases:
  - id: 1
    name: "Generic filter clone function"
    status: complete
  - id: 2
    name: "Register clone on filter prototypes"
    status: complete
  - id: 3
    name: "Filter constructor default properties"
    status: complete
  - id: 4
    name: "Fix SEGFAULT (NULL stub constructor call)"
    status: complete
  - id: 5
    name: "Property validation (angle, color, alpha, quality, strength, blur)"
    status: complete
  - id: 6
    name: "mc.filters getter/setter"
    status: not_started
  - id: 7
    name: "ColorMatrixFilter matrix setter validation"
    status: complete
  - id: 8
    name: "Property enumeration order"
    status: complete
  - id: 9
    name: "Complete constructor defaults for all filter types"
    status: complete
dependencies: []
blockers: []
-->

Last updated: 2026-03-29

## Status: IN PROGRESS — Phases 1-4 done (no crash), property validation remaining

**CI result (last):** 84/548 lines match. All 548 lines produced. Expected to improve significantly with property validation + constructor defaults now implemented.

### Problem (original)

`bitmap_filters` test SEGFAULTs when calling `.clone()` on filter objects. The test exercises clone, property validation, mc.filters, and all 9 filter types.

### Progress (2026-03-29)

**Phase 1-3:** Clone implemented + filter constructors initialize all default properties via `invokeNativeSuperConstructor` from both NewObject and NewMethod paths. BevelFilter expanded to all 12 properties. ColorMatrixFilter creates default identity matrix.

**Phase 4 (SEGFAULT fix):** Root cause was NULL function pointer call in `actionNewMethod` blank-method-name path — stub constructors (function_type=1) have `simple_func=NULL`, and the code called it without a NULL check. Fixed with a guard. Also fixed off-by-one register allocation in generated test code (`regs[7]` with only 7 elements).

Diagnosed using new `--asan` flag added to `verify_output.py`.

### Remaining issues (Phases 6-7)
1. **mc.filters getter/setter (Phase 6):** Reading/writing the filters array on MovieClips — `clip.filters[0]` returns embedded filter, `clip.filters = [f]` sets filters. Affects ~20 lines.
2. **ColorMatrixFilter matrix setter (Phase 7):** Setting matrix to partial array should pad to 20 elements with NaN; setting to non-array keeps old matrix. Affects ~30 lines.
3. **Angle precision:** Default 45° shows as 45.0, but Ruffle's expected output has 44.9999999772279 (f64 radians round-trip). This affects every line containing an angle property. Not fixable without matching Ruffle's internal radians storage.

### Root Cause

1. Filter prototypes are created via `ensureStubCtorPrototype` at `action.c:24627-24636` but have NO methods registered
2. When `.clone()` is called, method lookup walks the prototype chain, finds nothing, returns undefined
3. Subsequent code tries to use the undefined result, causing NULL dereference

### Algorithm

Filter `.clone()` is a shallow property copy:
1. Allocate a new ASObject with `native_type = NATIVE_FILTER`
2. Set `__proto__` to the same filter prototype as the original
3. Copy all own properties from the original object (name + value pairs)
4. Return the new object

Since all filter properties are simple values (numbers, strings, arrays, booleans), a shallow copy of own properties is sufficient. No deep cloning of nested objects is needed (except potentially arrays for ColorMatrixFilter's `matrix` and ConvolutionFilter's `matrix`).

### Implementation Steps

#### Step 1: Generic filter clone function (~25 lines)

A single `filterClone` function works for all filter types since clone just copies own properties:

```c
static ActionVar filterClone(SWFAppContext* app_context, ActionVar* args, u32 arg_count,
                             ActionVar* registers, void* this_obj)
{
    (void)args; (void)arg_count; (void)registers;
    ASObject* obj = (ASObject*) this_obj;
    if (!obj) { ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

    ASObject* clone = allocObject(app_context, obj->num_used + 4);
    clone->native_type = NATIVE_FILTER;

    // Copy __proto__ from original
    ActionVar* proto = getProperty(obj, "__proto__", 9);
    if (proto) setProperty(app_context, clone, "__proto__", 9, proto);

    // Copy all own properties (skip __proto__, __constructor__)
    for (u32 i = 0; i < obj->num_used; i++) {
        const char* name = obj->properties[i].name;
        u32 nlen = obj->properties[i].name_length;
        if (strcmp(name, "__proto__") == 0 || strcmp(name, "__constructor__") == 0) continue;
        setProperty(app_context, clone, name, nlen, &obj->properties[i].value);
    }

    ActionVar r = {0};
    r.type = ACTION_STACK_VALUE_OBJECT;
    r.data.numeric_value = (u64)clone;
    return r;
}
```

#### Step 2: Register clone on filter prototypes (~15 lines)

Register the `clone` method on each filter's prototype. Can use the existing `registerGeomMethod` pattern or register directly via `ensureStubCtorPrototype` modifications.

Need to store the prototype objects so clone can be registered:
```c
static ASFunction g_filter_clone_methods[9]; // One per filter type
```

Register after prototype creation in `initGlobalScope`:
```c
registerGeomMethod(&g_filter_clone_methods[0], "clone", (Function2Ptr)filterClone, app_context, fc_BevelFilter.prototype_obj);
// ... repeat for all 9 filter types
```

### Key Code Locations

| Component | File | Line |
|-----------|------|------|
| Filter prototype creation | action.c | 24627-24636 (`ensureStubCtorPrototype`) |
| Filter native_type setting | action.c | 37261-37270 |
| Filter constructors | action.c | 24414-24434 (`MAKE_STUB_CTOR`) |
| Constructor property init | action.c | 39080-39140 (`invokeNativeSuperConstructor`) |

### Estimated Complexity

**Done:** ~290 lines (clone + filter init + SEGFAULT fix + NewMethod path + property validation + constructor defaults + enumeration order)
**Remaining:** Medium — ~90 lines for mc.filters and matrix setter.

### Expected Impact

Angle precision prevents most filter property dump lines from matching exactly (45.0 vs 44.9999999772279). The test may need to be added to ACCEPTED_DIFFS or RUFFLE_VS_FLASH_DIFFERENCES if this precision mismatch is inherent to Ruffle's f64 radians round-trip.
