# Advanced Type Coercion / instanceof Plan
<!-- TESTS: coerce_to_object_monkeypatch, instanceof_coercions -->

Last updated: 2026-03-13

## Status: BLOCKED — 1/2 PASS, remaining test blocked on heap-allocated activation scopes

### Overview

Two tests exercise advanced type system edge cases: primitive-to-object automatic boxing with monkey-patched constructors, and instanceof operator behavior with non-standard operand types.

### Results

| Test | Lines | Before | After | Status |
|------|-------|--------|-------|--------|
| instanceof_coercions | 88 | ~12/88 (14%) | **88/88 PASS** | Fixed (was 86/88) |
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

#### ~~instanceof_coercions (2/88 lines differ)~~ RESOLVED

Now fully **PASS** (88/88). Both edge cases fixed since last update.

#### coerce_to_object_monkeypatch (~115 diff lines, was ~244)

Progress from ~7/129 to ~20/129 matching lines (15%). Still **BLOCKED by closure variable capture**.

The test uses `addGetter()` helper function that defines an inner getter function capturing outer function local variables (`name`, `val`). Our runtime uses stack-based variables — inner functions can't access outer function locals after the outer function returns. This is a fundamental architectural limitation requiring heap-allocated activation scopes.

The test structure:
```actionscript
function addGetter(obj, name, val) {
    obj.addProperty(name, function() { return val; }, null);  // closure over 'val'
}
```

Our runtime returns `undefined` for `val` inside the getter because the stack frame is gone. The `addGetter` pattern is used throughout the test to set up property getters that trace their name/value when accessed during auto-boxing. Without closure capture, these getters all return `undefined`, causing cascading mismatches.

Additional minor issue at line 49: `new "callme"()` should trigger auto-boxing of the string primitive via the monkey-patched String constructor. We skip the boxing (2 lines missing), which shifts subsequent output.

### Blockers

- **Closure variable capture** (FUNDAMENTAL): Would require heap-allocated activation scopes — a major architectural change to the runtime's variable storage model. This blocks ~100 lines of coerce_to_object_monkeypatch. No workaround exists without this architectural change.

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
