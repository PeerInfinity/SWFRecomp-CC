# Function Edge Cases Plan
<!-- TESTS: function_as_function, funky_function_calls, asfunction -->

Last updated: 2026-03-04

## Status: BLOCKED — function_as_function PASS, funky_function_calls PASS (56/56), asfunction BLOCKED (user interaction)

### Overview

Three tests exercise unusual function calling patterns that aren't covered by other plans.

### Tests

| Test | Lines | Current | Status | Description |
|------|-------|---------|--------|-------------|
| function_as_function | 36 | **36/36 (100%)** | **PASS** | `Function(f)` identity wrapping + `Function()` constructor |
| funky_function_calls | 56 | **56/56 (100%)** | **PASS** | Unusual apply/call patterns, `new` on various types |
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

#### Phase 3: g_override_this Mechanism — COMPLETE (56/56)

Remaining 4 mismatches were all caused by DefineFunction2's `preload-this` code not being able to represent non-pointer `this` values (primitives, undefined) through the `void* this_obj` parameter.

**Solution: `g_override_this` ActionVar global**

Added `ActionVar g_override_this` + `int g_override_this_set` globals. When set, the generated preload-this code uses this ActionVar directly, bypassing the `this_obj`/`g_event_this_mc` chain.

**Changes:**
1. **Recompiler (action.cpp)**: Generated preload-this code now checks `g_override_this_set` first, clears it after use. Fallback changed from `root_movieclip` to `g_current_context` (more correct: `this` defaults to the function's base_clip, not always root).
2. **Runtime apply handler**: Primitive thisArg types (F32, F64, STRING, BOOLEAN) now set `g_override_this` instead of being silently dropped.
3. **Runtime call handler**: Same primitive thisArg handling as apply.
4. **Empty-method-name FUNCTION path**: Sets `g_override_this` to UNDEFINED before calling, so `this` in the called function is `undefined` (not root).

**Lines fixed:**
- Line 1: `_level0` → `_level0.instance1` — natural call `this` now uses `g_current_context` (base_clip) instead of `root_movieclip`
- Lines 21, 41: `_level0` → `123` — primitive `this` in apply/call via `g_override_this`
- Line 49: `_level0` → `undefined` — empty-method-name call via `g_override_this`

Result: funky_function_calls **56/56 PASS**

#### Phase 4: asfunction Protocol — BLOCKED

Requires user interaction simulation (clicking on a link in a TextField). The `asfunction:` protocol triggers ActionScript function calls when the user clicks hyperlinks. This is fundamentally untestable without mouse event simulation infrastructure.

### Blocker

`asfunction` (0/12) is blocked on user interaction simulation — the test requires clicking on TextField hyperlinks which triggers `asfunction:` protocol handlers. This would need the mouse event system to support clicking on text field links, which is outside the scope of this plan.

### Files Modified

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | Function() call handler, apply/call thisArg fixes (MovieClip, undefined/null, primitive via g_override_this), captured scope in apply, array-like objects in apply, global object stringification, empty-method-name undefined this |
| `SWFModernRuntime/include/actionmodern/action.h` | g_override_this + g_override_this_set extern declarations |
| `SWFRecomp/src/action/action.cpp` | Preload-this code generation: g_override_this check first, g_current_context fallback |

### Regression Guard

```bash
python3 ruffle-tests/verify_output.py --test=function_as_function --test=funky_function_calls --test=this_scoping --test=super_edge_cases --test=clip_events --test=on_construct --test=define_function2_preload --test=function_suppress_and_preload --diff --verbose
```
