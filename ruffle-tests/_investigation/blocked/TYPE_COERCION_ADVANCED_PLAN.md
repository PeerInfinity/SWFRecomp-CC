# Advanced Type Coercion / instanceof Plan
<!-- TESTS: coerce_to_object_monkeypatch, instanceof_coercions -->

Last updated: 2026-03-05

## Status: PARTIALLY BLOCKED — closure variable capture prevents full coerce_to_object_monkeypatch pass

### Overview

Two tests exercise advanced type system edge cases: primitive-to-object automatic boxing with monkey-patched constructors, and instanceof operator behavior with non-standard operand types.

### Results

| Test | Lines | Before | After | Status |
|------|-------|--------|-------|--------|
| instanceof_coercions | 88 | ~12/88 (14%) | 86/88 (97.7%) | Near-pass (2 edge cases) |
| coerce_to_object_monkeypatch | 129 | ~7/129 (5%) | Blocked | Closure capture blocker |

### What Was Implemented

#### Phase 1: tryAutoBoxPrimitive() — Primitive Boxing (~90 lines)
- `tryAutoBoxPrimitive()`: when calling a method on a primitive, looks up the current global constructor (Boolean/Number/String) via `getActiveGlobal()`, creates a wrapper ASObject, sets `__proto__` and `__constructor__`, calls the constructor with the primitive as argument
- Non-object function prototype support: `actionSetMember` stores non-object prototype in `own_props` and clears `prototype_obj`; `actionGetMember` checks `own_props` fallback; `tryAutoBoxPrimitive` uses `own_props` fallback for `__proto__`
- `getActiveGlobal()` helper: returns version-appropriate `_global` (SWF≤6 → `g_global_legacy`, SWF7+ → `g_global_modern`)

#### Phase 2: instanceOfCoercing() — instanceof/CastOp Coercion (~120 lines)
- `instanceOfCoercing()`: Ruffle-compatible instanceof that auto-boxes cls and cls.prototype operands, preserves NoisyString constructor side effects for CastOp
- `actionCastOp` updated: primitive obj side-effect boxing before instanceof check
- `actionInstanceOf` updated: uses `instanceOfCoercing` instead of `checkInstanceOf`
- Dead MovieClip handling: returns false but preserves cls coercion side effects

#### Phase 3: Object.addProperty as Built-in (~55 lines)
- `builtin_object_addProperty()`: type-2 function on `Object.prototype`, callable via `Function.call()`
- `g_object_constructor.own_props.__proto__` → `Object.prototype` for method resolution chain

### Remaining Diffs

#### instanceof_coercions (2/88 lines differ)

1. **Line 40**: `.prototype is: super proto` vs `.prototype is: undefined` — `super.prototype` access in getter context returns undefined instead of resolving through super chain
2. **Line 44**: `.prototype is: undefined` vs `.prototype is: SWFv9 proto` — ASSetPropFlags with flag 0x2000 should hide property at SWF8 but doesn't (FLASH_HIDE_MASK needs to include 0x2000)

Both are minor edge cases unlikely to affect real SWF content.

#### coerce_to_object_monkeypatch (~244 diff lines)

**BLOCKED by closure variable capture**: The test uses `addGetter()` helper function that defines an inner getter function capturing outer function local variables (`name`, `val`). Our runtime uses stack-based variables — inner functions can't access outer function locals after the outer function returns. This is a fundamental architectural limitation requiring heap-allocated activation scopes.

The test structure:
```actionscript
function addGetter(obj, name, val) {
    obj.addProperty(name, function() { return val; }, null);  // closure over 'val'
}
```

Our runtime returns `undefined` for `val` inside the getter because the stack frame is gone.

### Blockers

- **Closure variable capture** (FUNDAMENTAL): Would require heap-allocated activation scopes — a major architectural change to the runtime's variable storage model. This blocks ~100 lines of coerce_to_object_monkeypatch.
- **super.prototype in getter context** (MINOR): 1 line in instanceof_coercions
- **ASSetPropFlags 0x2000 hide mask** (MINOR): 1 line in instanceof_coercions

### Files Modified

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | +407 lines: tryAutoBoxPrimitive, instanceOfCoercing, builtin_object_addProperty, getActiveGlobal, non-object prototype handling |

### Regression Guard

```bash
python3 ruffle-tests/verify_output.py --test=coerce_to_object_monkeypatch --diff --verbose
python3 ruffle-tests/verify_output.py --test=instanceof_coercions --diff --verbose
python3 ruffle-tests/verify_output.py --test=as2_oop --diff --verbose
python3 ruffle-tests/verify_output.py --test=extends_native_type --diff --verbose
```
