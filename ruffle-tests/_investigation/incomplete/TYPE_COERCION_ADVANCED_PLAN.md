# Advanced Type Coercion / instanceof Plan
<!-- TESTS: coerce_to_object_monkeypatch, instanceof_coercions -->

Last updated: 2026-03-04

## Status: BLOCKED — needs primitive-to-object boxing with custom constructors

### Overview

Two tests exercise advanced type system edge cases: primitive-to-object automatic boxing with monkey-patched constructors, and instanceof operator behavior with non-standard operand types.

### Tests

| Test | Lines | Current | Description |
|------|-------|---------|-------------|
| coerce_to_object_monkeypatch | 129 | ~7/129 (5%) | Replaces Boolean/Number/String globals with custom constructors; tests that `true.method()` boxes via custom constructor |
| instanceof_coercions | 88 | ~12/88 (14%) | Tests instanceof with string operands, NoisyString extends String, CastOp with non-class right operand |

### Test Details

#### coerce_to_object_monkeypatch (129 lines)

Flash's primitive-to-object coercion (`true.foo()`) creates a temporary wrapper object using the current global constructor:
1. `Boolean = MyBoolean;` (replace global Boolean with custom class)
2. `true.method()` → Flash calls `new MyBoolean(true)` to create `this`
3. `this.className` → `"MyBoolean"` (custom constructor ran)
4. Same pattern for `Number = MyNumber;` and `String = MyString;`

**Root cause**: Our runtime doesn't box primitives via the global constructor — it uses a fixed built-in boxing path. When `true.foo()` is called, `this` becomes the root MovieClip instead of a Boolean wrapper.

**What's needed**:
1. Primitive-to-object boxing in method dispatch: when calling a method on a primitive value (BOOLEAN, F32, F64, STRING), create a wrapper object via the CURRENT global constructor (not a hardcoded built-in)
2. The wrapper object should have `__proto__` set to the constructor's `.prototype`
3. The custom constructor function should actually be called with the primitive value as argument
4. The wrapper should be temporary — it only exists for the duration of the method call

**Difficulty**: HIGH. This requires changes to the method dispatch path in `actionCallMethod` to detect primitive targets and box them. The boxing must use the current global constructor (which may have been replaced), requiring `getVariable("Boolean")` etc. at call time.

#### instanceof_coercions (88 lines)

Tests `instanceof` with non-standard operands:
1. `"left" instanceof "right"` — string operands. Flash coerces "right" to a constructor via global scope.
2. `"left" instanceof Object` — string instanceof real constructor
3. `{} instanceof "right"` — object instanceof string
4. `{} instanceof { prototype: Object.prototype }` — plain object as "constructor"
5. `CastOp` with string arguments — `String("left")` returns a NoisyString

Also tests `NoisyString extends String` — a user class that overrides String, with valueOf tracing.

**Root cause**: `checkInstanceOf` and `actionCastOp` don't handle string operands correctly. Strings need to be resolved to constructors via global scope. The `CastOp` (ActionCast, 0x2B) coercion path doesn't call `NoisyString` constructor.

**What's needed**:
1. `instanceof` with string right operand: resolve the string as a variable name to get the constructor
2. `instanceof` with string left operand: box to a String wrapper object, then check
3. `CastOp` with string right operand: same resolution as instanceof
4. Support for `NoisyString extends String` — a user-defined class that extends a native type

**Difficulty**: MEDIUM-HIGH. The instanceof changes are ~30 lines. NoisyString support depends on native type extension working (partially blocked by NATIVE_INTROSPECTION_PLAN Phase 3).

### Implementation Plan

#### Phase 1: Primitive Boxing in Method Dispatch (~50 lines)

When `actionCallMethod` receives a primitive target (BOOLEAN, F32, F64, STRING):
1. Look up the corresponding global constructor (`Boolean`, `Number`, `String`)
2. If the constructor has been replaced (is a user function), call it with the primitive value
3. Use the resulting object as `this` for the method call
4. If constructor is the default built-in, use existing fast path

This is a fundamental change to how primitives interact with methods. Only do this when the method is called on a primitive value directly (not when the primitive is already wrapped in an object).

#### Phase 2: instanceof String Operand Resolution (~30 lines)

In `checkInstanceOf` and `actionInstanceOf`:
1. If right operand is a STRING, resolve it via `actionGetVariable` to get the constructor
2. If left operand is a STRING, box it to a String wrapper
3. Then proceed with normal instanceof logic

#### Phase 3: NoisyString extends String (~20 lines)

If native type extension already works (from NATIVE_INTROSPECTION_PLAN), this should be automatic. The `NoisyString` constructor calls `super("...")` which initializes the String backing.

### Blockers

- **Phase 1** is self-contained but complex — touches the core method dispatch path
- **Phase 2** is self-contained
- **Phase 3** depends on native type extension (partially blocked)

### Estimated Impact

~100 lines of code total:
- coerce_to_object_monkeypatch: 7/129 → ~80-120/129 (Phase 1)
- instanceof_coercions: 12/88 → ~50-70/88 (Phase 2 + 3)

### Files to Modify

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | Primitive boxing in actionCallMethod, instanceof string resolution |

### Regression Guard

```bash
python3 ruffle-tests/verify_output.py --test=coerce_to_object_monkeypatch --diff --verbose
python3 ruffle-tests/verify_output.py --test=instanceof_coercions --diff --verbose
python3 ruffle-tests/verify_output.py --test=as2_oop --diff --verbose
python3 ruffle-tests/verify_output.py --test=extends_native_type --diff --verbose
```
