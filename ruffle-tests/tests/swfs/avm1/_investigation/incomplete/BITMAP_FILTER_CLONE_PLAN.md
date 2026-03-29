# BitmapFilter .clone() Implementation Plan
<!-- TESTS: bitmap_filters -->

<!-- PLAN_META
id: BITMAP_FILTER_CLONE
status: not_started
phases:
  - id: 1
    name: "Generic filter clone function"
    status: not_started
  - id: 2
    name: "Register clone on filter prototypes"
    status: not_started
dependencies: []
blockers: []
-->

Last updated: 2026-03-29

## Status: NOT STARTED

### Problem

`bitmap_filters` test SEGFAULTs at line 10 when calling `.clone()` on a BevelFilter object. No filter classes have a `clone()` method, causing method lookup to return undefined and subsequent property access to crash.

The test exercises `.clone()` on all 9 filter types (BevelFilter, BlurFilter, ColorMatrixFilter, ConvolutionFilter, DisplacementMapFilter, DropShadowFilter, GlowFilter, GradientBevelFilter, GradientGlowFilter), followed by property access on the cloned objects.

**Current trace:** 9/548 lines match (crashes at line 10)

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

Low — ~40 lines of C. One generic clone function + registration on 9 prototypes.

### Expected Impact

Should fix ~540 of the 548 expected lines in `bitmap_filters`. The test exercises clone + property access for all 9 filter types. Remaining failures might be from filter-specific property defaults or type coercion.
