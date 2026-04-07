# Advanced Type Coercion / instanceof Plan
<!-- TESTS: coerce_to_object_monkeypatch, instanceof_coercions -->

<!-- PLAN_META
id: TYPE_COERCION_ADVANCED
status: complete
phases:
  - id: 1
    name: "tryAutoBoxPrimitive() primitive boxing"
    status: complete
  - id: 2
    name: "instanceOfCoercing() instanceof/CastOp coercion"
    status: complete
  - id: 3
    name: "Object.addProperty as built-in"
    status: complete
dependencies: []
blockers: []
-->

Last updated: 2026-04-07

## Status: COMPLETE — 2/2 PASS

### Results

| Test | Lines | Status |
|------|-------|--------|
| instanceof_coercions | 88 | **88/88 PASS** |
| coerce_to_object_monkeypatch | 129 | **129/129 PASS** |

### Previous Blocker (RESOLVED)

This plan was previously blocked on "closure variable capture (heap-allocated activation scopes)" because `coerce_to_object_monkeypatch` uses `addGetter()` helper functions that define inner getters capturing outer function local variables. At the time the plan was written (2026-03-13), the runtime couldn't capture local scope variables in closures.

The blocker was resolved by 2026-03-15 through:
1. **Closure capture mechanism** (CLOSURE_CAPTURE_PLAN, completed 2026-02-24): `ASFunction` captures scope chain entries at definition time via `retainObject()` reference counting, so heap-allocated local scope objects survive after outer functions return.
2. **Tri-state `tryAutoBoxPrimitive`** (COERCE_TO_OBJECT_MONKEYPATCH, completed 2026-03-15): auto-boxing with monkeypatched constructors, `new "string"()` side effects, `Function.call(primitive)` this-binding fallback.

See `complete/COERCE_TO_OBJECT_MONKEYPATCH.md` for the detailed fix description.

### What Was Implemented

#### Phase 1: tryAutoBoxPrimitive() — Primitive Boxing (~90 lines)
- `tryAutoBoxPrimitive()`: when calling a method on a primitive, looks up the current global constructor (Boolean/Number/String) via `getActiveGlobal()`, creates a wrapper ASObject, sets `__proto__` and `__constructor__`, calls the constructor with the primitive as argument
- Non-object function prototype support: `actionSetMember` stores non-object prototype in `own_props` and clears `prototype_obj`; `actionGetMember` checks `own_props` fallback; `tryAutoBoxPrimitive` uses `own_props` fallback for `__proto__`
- `getActiveGlobal()` helper: returns version-appropriate `_global` (SWF<=6 -> `g_global_legacy`, SWF7+ -> `g_global_modern`)

#### Phase 2: instanceOfCoercing() — instanceof/CastOp Coercion (~120 lines)
- `instanceOfCoercing()`: Ruffle-compatible instanceof that auto-boxes cls and cls.prototype operands, preserves NoisyString constructor side effects for CastOp
- `actionCastOp` updated: primitive obj side-effect boxing before instanceof check
- `actionInstanceOf` updated: uses `instanceOfCoercing` instead of `checkInstanceOf`
- Dead MovieClip handling: returns false but preserves cls coercion side effects

#### Phase 3: Object.addProperty as Built-in (~55 lines)
- `builtin_object_addProperty()`: type-2 function on `Object.prototype`, callable via `Function.call()`
- `g_object_constructor.own_props.__proto__` -> `Object.prototype` for method resolution chain

### Files Modified

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | +407 lines: tryAutoBoxPrimitive, instanceOfCoercing, builtin_object_addProperty, getActiveGlobal, non-object prototype handling |
