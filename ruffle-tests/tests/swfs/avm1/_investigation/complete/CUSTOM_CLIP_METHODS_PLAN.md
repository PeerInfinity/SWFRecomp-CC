# Custom Clip Methods Plan
<!-- TESTS: custom_clip_methods -->

Last updated: 2026-03-06

## Status: COMPLETE — 4/4 (100%)

### Overview

The test defines custom methods (`global_function`, `tracealike`, `fancy_stop`) on the root timeline via `DefineFunction` and then calls them as methods on `this` (the root MC).

**Test**: `custom_clip_methods` — 4/4 (100%).

### Root Causes Found

**Bug 1: MOVIECLIP CallMethod couldn't find user-defined functions**

`actionDefineFunction` stores functions in `function_registry[]` and `var_map`, but NOT on `mc->dynamic_props`. The MOVIECLIP `else` branch in `actionCallMethod` only checked `dynamic_props` for user-defined methods.

**Fix**: Added fallback lookup in the MOVIECLIP CallMethod path:
1. Check `dynamic_props` first (existing behavior)
2. For root MC: check `var_map` hashmap (case-folded for SWF<=6)
3. Fall back to `lookupFunctionByName()` from function_registry

**Bug 2: PUSH macro used without braces in for loop**

The `PUSH(t, v)` macro expands to multiple semicolon-separated statements (NOT wrapped in `do { } while(0)`). When used in a bare for loop:
```c
for (u32 i = num_args; i < func->param_count; i++)
    PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
```
Only `OLDSP = SP;` was in the loop body. The remaining `SP -= 24; STACK[SP] = UNDEFINED;` etc. executed **unconditionally**, pushing an extra UNDEFINED entry on every call. This corrupted the stack so type 1 functions with parameters received UNDEFINED instead of their arguments.

**Fix**: Added braces around the PUSH call: `for (...) { PUSH(...); }`.

### Files Changed

- `SWFModernRuntime/src/actionmodern/action.c` — MOVIECLIP CallMethod fallback lookup + braces fix
