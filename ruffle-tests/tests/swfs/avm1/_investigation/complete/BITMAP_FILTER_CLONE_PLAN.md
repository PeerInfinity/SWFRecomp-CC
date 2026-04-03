# BitmapFilter .clone() Implementation Plan
<!-- TESTS: bitmap_filters -->

<!-- PLAN_META
id: BITMAP_FILTER_CLONE
status: complete
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
    status: complete
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

Last updated: 2026-04-03

## Status: COMPLETE — 548/548 PASS

**CI result (2026-04-03):** 548/548 lines match. All phases complete. Test fully passing.

### Problem (original)

`bitmap_filters` test SEGFAULTed when calling `.clone()` on filter objects. The test exercises clone, property validation, mc.filters, and all 9 filter types.

### Progress Summary

**Phase 1-3:** Clone implemented + filter constructors initialize all default properties via `invokeNativeSuperConstructor` from both NewObject and NewMethod paths. BevelFilter expanded to all 12 properties. ColorMatrixFilter creates default identity matrix.

**Phase 4 (SEGFAULT fix):** Root cause was NULL function pointer call in `actionNewMethod` blank-method-name path — stub constructors (function_type=1) have `simple_func=NULL`, and the code called it without a NULL check. Fixed with a guard. Also fixed off-by-one register allocation in generated test code (`regs[7]` with only 7 elements).

**Phase 5:** Property validation for angle, color, alpha, quality, strength, blur — clamping and coercion rules.

**Phase 6:** mc.filters getter/setter — PlaceObject3 filter data for embedded filters. Fixed mc.filters[0] for ColorMatrix, Convolution, Gradient filters.

**Phase 7:** ColorMatrixFilter matrix setter validation.

**Phase 8:** Property enumeration order alignment.

**Phase 9:** Complete constructor defaults for all filter types.

### Algorithm

Filter `.clone()` is a shallow property copy:
1. Allocate a new ASObject with `native_type = NATIVE_FILTER`
2. Set `__proto__` to the same filter prototype as the original
3. Copy all own properties from the original object (name + value pairs)
4. Return the new object

### Key Code Locations

| Component | File | Line |
|-----------|------|------|
| Filter prototype creation | action.c | 24627-24636 (`ensureStubCtorPrototype`) |
| Filter native_type setting | action.c | 37261-37270 |
| Filter constructors | action.c | 24414-24434 (`MAKE_STUB_CTOR`) |
| Constructor property init | action.c | 39080-39140 (`invokeNativeSuperConstructor`) |

### Total Implementation

~450 lines of implementation across 12+ commits (clone, constructor defaults, SEGFAULT fix, NewMethod path, property validation, mc.filters, matrix setter, ConvolutionFilter sizing, array instanceof, mc.filters[0] for embedded filters).
