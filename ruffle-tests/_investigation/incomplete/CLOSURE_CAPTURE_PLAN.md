# Closure Variable Capture Plan
<!-- TESTS: focus_keyboard_press, focus_mouse, focus_mouse_rollout, swf5_no_closure -->

Last updated: 2026-02-23

## Status: NOT STARTED — 0/4 tests blocked on this

### Blocked tests

| Test | Blocked Plan | Issue |
|------|-------------|-------|
| focus_keyboard_press | FOCUS_SYSTEM | Closure over function parameter shows "undefined" |
| focus_mouse | FOCUS_SYSTEM | Same closure bug + hit-test for MC-as-button |
| focus_mouse_rollout | FOCUS_SYSTEM | Same closure bug + empty output |
| swf5_no_closure | (standalone) | SWF5 closure semantics (closures shouldn't capture in SWF5) |

---

## The Bug

Functions defined inside other functions cannot access the enclosing function's parameters.
The captured parameter resolves to `undefined` at call time instead of the original value.

**Failing pattern:**
```actionscript
function setHandlers(obj) {
    obj.onKeyDown = function() {
        trace(obj + ".onKeyDown: " + Key.getCode());
        //    ^^^ resolves to "undefined" instead of "_level0.clip"
    };
}
setHandlers(clip);
```

**Expected output:** `_level0.clip.onKeyDown: 13`
**Actual output:** `undefined.onKeyDown: 13`

The `closure_scope` test (which passes) captures WITH scope variables, not function
parameters. The distinction matters because our architecture handles these two cases
differently.

---

## Current Architecture

### Scope chain (action.c:300-307)

A global flat array, not a linked list:

```c
#define MAX_SCOPE_DEPTH 32
static ASObject* scope_chain[MAX_SCOPE_DEPTH];
static u8 scope_is_with[MAX_SCOPE_DEPTH];     // 1=with, 0=function local
static MovieClip* scope_mc[MAX_SCOPE_DEPTH];
static u32 scope_depth = 0;
```

### Closure capture at definition time (action.c:21229-21300)

When `actionDefineFunction2` runs, it snapshots the current scope chain into the ASFunction:

```c
as_func->captured_scope_count = 0;
for (u32 si = 0; si < scope_depth && as_func->captured_scope_count < 8; si++) {
    if (scope_chain[si] != NULL) {
        u8 idx = as_func->captured_scope_count++;
        as_func->captured_scope[idx] = scope_chain[si];
        as_func->captured_scope_mc[idx] = scope_mc[si];
        as_func->captured_scope_is_with[idx] = scope_is_with[si];
        if (!scope_is_with[si]) retainObject(scope_chain[si]);
    }
}
```

This captures **pointers** to scope objects. For function-local scopes (non-with), it
increments the refcount so the scope object survives after the enclosing function returns.

### Scope restoration during call (action.c:22637-22745)

When a closure is called, captured scopes are pushed back:

```c
for (u8 ci = 0; ci < captured_count; ci++) {
    scope_is_with[scope_depth] = func->captured_scope_is_with[ci];
    scope_mc[scope_depth] = func->captured_scope_mc[ci];
    scope_chain[scope_depth++] = func->captured_scope[ci];
}
// Then push new local scope on top
scope_chain[scope_depth++] = local_scope;
```

### Variable resolution (action.c:13332-13395)

Walks scope chain innermost-to-outermost looking for matching property names.

### Parameter storage in generated code (script_defs.c)

```c
ActionVar func2_setHandlers_1(SWFAppContext* app, ActionVar* args, u32 arg_count, ...) {
    // Parameters stored on local scope:
    if (0 < arg_count) {
        setVariableByName("obj", &args[0]);  // sets property on local scope object
    }
    // ... inner function defined here via actionDefineFunction2 ...
}
```

---

## Root Cause Analysis

The execution sequence is:

1. `setHandlers(clip)` called → new local scope object allocated
2. Parameter `obj` stored on local scope via `setVariableByName("obj", &args[0])`
3. Scope chain = `[global_scope, local_scope_setHandlers]`
4. Inner function defined → captures `[global_scope, local_scope_setHandlers]`, retains local_scope
5. Inner function assigned to `clip.onKeyDown`
6. `setHandlers` returns → local scope released (but refcount > 0 due to capture, survives)
7. Later: `onKeyDown` event fires, inner function called
8. Captured scopes restored → `[global_scope, local_scope_setHandlers, new_local_scope]`
9. Variable lookup for `obj` walks scope chain...

**The question is: does step 9 find `obj` on the captured `local_scope_setHandlers`?**

Possible failure points:
- **Refcount bug**: local_scope freed despite capture retain (use-after-free → undefined)
- **Property cleared**: local scope properties wiped on function return cleanup
- **Variable resolution skip**: scope walk doesn't check captured function-local scopes properly
- **Parameter timing**: parameters stored AFTER inner function definition in generated code order

**Most likely cause**: The local scope object's properties may be getting cleared when the
enclosing function returns, even though the object itself is retained. OR there's a variable
resolution issue where function-local scopes aren't being searched for the right property name.

This needs debugging with a specific test case to pin down the exact failure point.

---

## Ruffle's Approach (Reference)

Ruffle uses a **linked-list scope chain** (scope.rs:34-39):

```rust
pub struct Scope<'gc> {
    parent: Option<Gc<'gc, Scope<'gc>>>,  // linked list
    class: ScopeClass,                     // Global, Target, Local, With
    values: Object<'gc>,                   // properties stored here
}
```

Key differences from our approach:
1. **Linked list vs flat array**: Scope chain is a persistent linked list, not a snapshot
2. **Garbage collected**: Scope objects are GC'd, not refcounted — no premature free
3. **Scope class distinction**: Local scopes are explicitly tagged and always captured;
   WITH scopes are NOT captured (`ScopeClass::With` excluded from closure inheritance)
4. **Parameters stored on scope object**: Function parameters are stored as properties on
   the local scope object, same as our approach

Reference: `~/CC/ruffle/core/src/avm1/scope.rs`, `~/CC/ruffle/core/src/avm1/function.rs`

---

## Fix Options

### Option A: Debug and fix the refcount/property issue (Low effort)

If the root cause is a simple refcount or property clearing bug, fix it directly.
This is the first thing to try — add printf debugging to trace the lifecycle of the
captured scope object and its `obj` property through the sequence above.

**Diagnostic steps:**
1. Build `focus_keyboard_press` locally
2. Add printf in `retainObject`/`releaseObject` for the local scope object
3. Add printf in `setVariableByName` when setting `obj`
4. Add printf in variable resolution when looking up `obj` in the inner function
5. Trace where the value is lost

### Option B: Store parameters in a separate captured-args structure (Medium effort)

Instead of relying on the local scope object surviving, explicitly capture parameter
values at function definition time:

```c
typedef struct ASFunction {
    // ... existing fields ...
    u8 captured_param_count;
    struct {
        char name[32];
        ActionVar value;
    } captured_params[8];
} ASFunction;
```

When defining a closure, snapshot the enclosing function's parameters into the closure.
During variable resolution in the closure, check `captured_params` before the scope chain.

### Option C: Switch to linked-list scopes (High effort)

Rewrite the scope chain as a linked list matching Ruffle's design. This is the most
architecturally sound fix but requires changes throughout the variable resolution,
function definition, and function call code.

**Recommended**: Start with Option A (debug). If the issue is deeper than a simple bug,
escalate to Option B.

---

## SWF5 No-Closure Semantics

The `swf5_no_closure` test verifies that SWF5 does NOT capture closures — inner functions
should NOT see variables from enclosing function scopes. This is the opposite of the
SWF6+ behavior. If we fix closure capture for SWF6+, we need to gate it on SWF version:

```c
// In actionDefineFunction2:
if (g_swf_version >= 6) {
    // Capture scope chain (closure behavior)
} else {
    // Don't capture (SWF5 behavior)
}
```

---

## Files to Modify

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | Scope chain capture, variable resolution, refcount fix |
| `SWFModernRuntime/src/actionmodern/variables.c` | `setVariableOnLocalScope`, `getVariable` scope walk |

---

## Estimated Impact

Fixing closure capture would:
- Directly fix 3 focus tests (focus_keyboard_press, focus_mouse, focus_mouse_rollout)
- Fix swf5_no_closure (SWF5 anti-closure behavior)
- Potentially fix other tests that use nested function patterns but aren't yet identified as blocked on this
