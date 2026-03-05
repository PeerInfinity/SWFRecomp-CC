# Function Edge Cases Plan
<!-- TESTS: function_as_function, funky_function_calls, asfunction -->

Last updated: 2026-03-04

## Status: PARTIAL — function_as_function PASS, funky_function_calls 52/56 (segfault fixed), asfunction BLOCKED

### Overview

Three tests exercise unusual function calling patterns that aren't covered by other plans.

### Tests

| Test | Lines | Current | Status | Description |
|------|-------|---------|--------|-------------|
| function_as_function | 36 | **36/36 (100%)** | **PASS** | `Function(f)` identity wrapping + `Function()` constructor |
| funky_function_calls | 56 | **52/56 (93%)** | output_mismatch | Unusual apply/call patterns, `new` on various types |
| asfunction | 12 | 0/12 (0%) | output_mismatch | `asfunction:` URL protocol handler in TextField links |

### What Was Implemented

#### Phase 1: Function() Call Handler — COMPLETE
- Added `Function()` call handler in `actionCallFunction`
- `Function(f)` returns `f` unchanged (any type)
- `Function()` with no args returns bare `allocObject()` (no __proto__)
- Result: function_as_function **36/36 PASS**

#### Phase 2: funky_function_calls Segfault Fix — COMPLETE (52/56)

Root cause of segfault: MovieClip pointer passed as `void* this_obj` to DefineFunction2 was typed as `ACTION_STACK_VALUE_OBJECT` in the preload-this code. When `convertString` tried to call `toString` on it (treating it as an ASObject), it crashed due to wrong struct layout.

**Fixes applied:**
1. **MovieClip thisArg via g_event_this_mc**: In both `call` and `apply` handlers, when thisArg is MOVIECLIP, set `g_event_this_mc` instead of `this_obj`. This preserves the type tag in the DefineFunction2 preload-this code.
2. **Undefined/null thisArg → global_object**: When apply/call receives undefined/null thisArg, pass `global_object` as `this_obj`. Flash treats this as the global scope.
3. **Global object stringification**: Added special case in `convertString` OBJECT path — when the object is `global_object` and no toString is found, return "undefined" instead of "[object Object]" (matching Flash behavior).
4. **Captured scope + base_clip in apply handler**: The apply handler (both type 1 and type 2 paths) was missing captured scope chain restoration and base_clip context switching. Added both (matching the call handler's existing behavior).
5. **Array-like objects in apply()**: Flash's `apply()` accepts objects with `length` + numeric indices, not just arrays. Added OBJECT type handling in the apply handler that reads `length` and iterates numeric indices.

**Remaining 4 mismatches (require recompiler changes):**
- Line 1: `_level0` vs `_level0.instance1` — test runs in a child clip, our runtime resolves to root
- Lines 21, 41: `_level0` vs `123` — primitive `this` (e.g., `apply(123, ...)`) can't be passed through `void* this_obj`. Requires recompiler to support a `g_override_this` ActionVar mechanism.
- Line 49: `_level0` vs `undefined` — empty-method-name call on FUNCTION type. The `this` should be `undefined`, but preload falls back to root_movieclip.

#### Phase 3: asfunction Protocol — BLOCKED

Requires user interaction simulation (clicking on a link). Deferred.

### Files Modified

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | Function() call handler, apply/call thisArg fixes (MovieClip, undefined/null, primitive), captured scope in apply, array-like objects in apply, global object stringification |

### Regression Guard

```bash
python3 ruffle-tests/verify_output.py --test=function_as_function --diff --verbose
python3 ruffle-tests/verify_output.py --test=funky_function_calls --diff --verbose
```
