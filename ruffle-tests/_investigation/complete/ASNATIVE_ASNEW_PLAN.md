# ASnative / ASNew Implementation Plan
<!-- TESTS: asnative, asnew -->

Last updated: 2026-03-04

## Status: COMPLETE

### Overview

`ASnative(class_id, method_id)` resolves Flash Player's internal native function table, returning a reference to a built-in function by its class/method index pair. `ASNew` is `ASnative(2, 0)` — returns a boolean indicating whether the enclosing bytecode function was called as a constructor.

### Tests

| Test | Lines | Result | Description |
|------|-------|--------|-------------|
| asnative | 34 | **34/34 PASS** | Tests ASnative resolution with various class/method pairs, string coercion, invalid args |
| asnew | 34 | **34/34 PASS** | Tests ASNew (ASnative(2,0)) as constructor context detector, apply/call/property/resolve contexts |

### Implementation Summary

#### ASnative Dispatch (~150 lines in action.c)

1. **Class 100 functions** (escape=0, unescape=1, parseInt=2, parseFloat=3, trace=4): Static `g_asnative_100_funcs[5]` ASFunction array with wrapper functions for escape/unescape/trace. parseInt and parseFloat reuse existing builtins.

2. **Class 2 functions** (ASNew=0): Returns boolean indicating constructor context.

3. **Class 200 functions**: Reuses existing `g_math_funcs[]` array (already initialized by Math object).

4. **ECMAScript ToUint32 coercion**: `ecmaToUint32()` helper for proper arg coercion (NaN/Infinity -> 0, truncate, mod 2^32). Method index saturated to u16 (>=65536 -> 65535).

5. **Arg count check**: Exactly 2 args required (not "at least 2").

#### Constructor Context Tracking (~50 lines)

Stack-based `g_ctor_context_stack[64]` tracks whether current bytecode frame is a constructor call:
- `pushCtorContext(1)` at: actionNewObject, actionNewMethod (blank name), actionInvokeRegisteredClassConstructor
- `pushCtorContext(0)` at: actionCallFunction (bytecode only, register_count > 0), actionCallMethod empty-method-name FUNCTION dispatch (bytecode only)
- Native Function2Ptr wrappers (register_count == 0) do NOT push/pop, so ASNew correctly "sees through" to the enclosing bytecode frame's context.

#### Bug Fix: actionNewMethod undefined method name (SWF8)

`convertString()` converts UNDEFINED to "undefined" string in SWF8, preventing the blank-method-name code path. Fixed by checking `STACK_TOP_TYPE == ACTION_STACK_VALUE_UNDEFINED` before `convertString()`.

### Files Modified

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | ASnative dispatch, class 100/2/200 tables, constructor context stack, actionNewMethod fix |

### Commit

`dc5c6a06` — Implement ASnative class 100/2 dispatch + ASNew constructor context tracking
