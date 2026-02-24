# This Binding Implementation Plan
<!-- TESTS: this_swf5, this_swf6, this_scoping, mutable_this, swf5_no_closure -->

Last updated: 2026-02-24

## Status: NOT STARTED — 0/5 tests passing (5 failing)

### Target Tests

| Test | SWF Ver | Match | Expected | Issue |
|------|---------|-------|----------|-------|
| this_swf5 | 5 | 24/41 | 41 | `this` resolves to `undefined` instead of `_level0` for unbound function calls |
| this_swf6 | 6 | 18/41 | 41 | Same issue as swf5, plus `[type Object]` vs `[object Object]` |
| this_scoping | 15 | 42/52 | 52 | `this.bar` vs `bar` wrong in WITH scope; gotoAndStop frame nav |
| mutable_this | 15 | 12/18 | 18 | `this` not reverting on nested function calls without receiver |
| swf5_no_closure | 5 | 6/19 | 19 | `this` not bound to clip/object in SWF5 method calls |

### Related tests (may improve as side effect)
- `this_swf7` — already PASS (41/41), serves as control case

---

## The Bug

In Flash Player, when a function is called without an explicit receiver (e.g., `f()` not `obj.f()`), `this` still resolves to a meaningful value:

- **SWF5/6**: `this` = `_level0` (root MovieClip)
- **SWF7+**: `this` = `undefined`

Our runtime returns `undefined` for all versions in this case.

Additionally, `this` should be **restored** when returning from a nested function call. If `this` is `1234` and we call `foo()` (which gets `this = _level0`), after `foo()` returns, `this` should be `1234` again.

---

## Root Cause Analysis

### Problem 1: Type 1 (DefineFunction) functions don't get `this` in plain calls

In `actionCallFunction`, the type 1 function path (lines 23694-23810) creates a local scope and pushes args on the stack, but **never sets `this` on the local scope**. Only type 2 functions get `this` via the preload/suppress flags mechanism.

In Flash, even type 1 functions should have `this` bound:
- To `_level0` when called without a receiver
- To the receiver when called as a method

### Problem 2: `this` not stored on type 1 scope

The type 2 path does:
```c
if (!f2_preload_this && !f2_suppress_this) {
    this_var.type = ACTION_STACK_VALUE_MOVIECLIP;
    this_var.data.numeric_value = (u64)&root_movieclip;
    setProperty(app_context, local_scope, "this", 4, &this_var);
}
```

But the type 1 path has no equivalent. When the function body calls `GetVariable("this")`, it falls through to the `g_current_context` check:
```c
if (g_current_context != NULL && g_current_context != &root_movieclip) {
    PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)g_current_context);
    return;
}
```
In root context, `g_current_context == &root_movieclip`, so this path is skipped, and `this` resolves through the global variable table — returning `undefined`.

### Problem 3: `this` not restored on function exit (mutable_this)

In Flash, each function call frame has its own `this` binding. When the function returns, `this` reverts to what it was in the caller. Our flat scope chain doesn't inherently support this — `this` on the local scope is lost when the scope is popped, but the caller's `this` isn't automatically visible again.

### Problem 4: SWF5 method calls (`clip.g()`) — `this` not bound to clip

In `actionCallMethod`, when calling a method on a MovieClip via the dynamic_props path (line 28320-28336), the function is called directly without setting up a local scope with `this`:
```c
ActionVar result = func->advanced_func(app_context, args, num_args, NULL, (void*)&this_var);
```
The `this_var` is passed as the C parameter but never stored on a scope object, so `GetVariable("this")` can't find it.

---

## Ruffle's Approach

Ruffle stores `this` directly in the `Activation` struct, not as a scope property:
```rust
struct Activation { this: Value<'gc>, ... }
```
- `GetVariable("this")` returns `self.this_cell()` directly
- `SetVariable("this")` mutates `self.this` directly
- Each function call creates a new Activation with its own `this`
- On return, the caller's Activation (with its `this`) is automatically restored

Key difference: Ruffle's `this` is per-activation (implicit save/restore), while ours is a scope property (manual, and not consistently set).

---

## Fix Plan

### Phase 1: Set `this` on type 1 function local scope in `actionCallFunction`

In the type 1 function path of `actionCallFunction` (~line 23704), after creating `local_scope`, set `this`:

```c
// Set 'this' on local scope for type 1 functions
extern MovieClip root_movieclip;
ActionVar this_var = {0};
this_var.type = ACTION_STACK_VALUE_MOVIECLIP;
this_var.data.numeric_value = (u64)&root_movieclip;
setProperty(app_context, local_scope, "this", 4, &this_var);
```

**Tests affected**: this_swf5, this_swf6, mutable_this

### Phase 2: Set `this` on type 1 function local scope in `actionCallMethod`

In the type 1 method path of `actionCallMethod` (~line 26166), set `this` to the receiver:

```c
// Set 'this' to receiver for type 1 method calls
ActionVar this_var = {0};
if (obj != NULL) {
    this_var.type = ACTION_STACK_VALUE_OBJECT;
    this_var.data.numeric_value = (u64)obj;
} else {
    extern MovieClip root_movieclip;
    this_var.type = ACTION_STACK_VALUE_MOVIECLIP;
    this_var.data.numeric_value = (u64)&root_movieclip;
}
setProperty(app_context, local_scope_am1, "this", 4, &this_var);
```

**Tests affected**: swf5_no_closure (clip.g() and obj.g())

### Phase 3: Fix `this` resolution in `actionGetVariable` for root context

The current root context check skips `_level0`:
```c
if (g_current_context != NULL && g_current_context != &root_movieclip) {
    PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)g_current_context);
    return;
}
```

This means `GetVariable("this")` at root level doesn't return `_level0`. But in SWF5/6, `this` at root level should be `_level0`. Consider adding:
```c
if (var_name_len == 4 && strncmp(var_name, "this", 4) == 0 && g_current_context != NULL) {
    PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)g_current_context);
    return;
}
```

**Tests affected**: this_swf5, this_swf6 (the comparison `this == _level0` should be `true`)

### Phase 4: Fix MC dynamic_props method call path

In `actionCallMethod` MC path (~line 28322), the function is called without a local scope:
```c
func->advanced_func(app_context, args, num_args, NULL, (void*)&this_var);
```

Need to create a local scope, set `this` on it, push it onto scope chain, call the function, and pop it after.

**Tests affected**: swf5_no_closure (clip.g())

### Phase 5: Fix `this` scoping in WITH blocks (this_scoping)

The `this_scoping` test has WITH-scope + `this` resolution issues. When inside `with(mc)`, `this.bar` should resolve differently from `bar`:
- `this.bar` → accesses `this` (the function's this, NOT the with-scope target)
- `bar` → resolves through WITH scope chain (finds `mc.bar`)

If `this` is properly on the local scope (Phase 1), the scope chain walk should find it before the WITH scope. Verify after Phase 1.

**Tests affected**: this_scoping (lines 10-12)

### Phase 6: Fix gotoAndStop via string path (this_scoping)

Lines 37-52 of this_scoping test `gotoAndStop` via `get('_root.instance1.gotoAndStop')(4)` and other string-path patterns. These need:
- `get()` to resolve `_root.instance1.gotoAndStop` as a bound method
- The method call to actually advance the sprite frame

This is a separate issue from `this` binding — it's about string-path method resolution.

**Tests affected**: this_scoping (lines 37-52)

---

## Files to Modify

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | `actionCallFunction` type 1 path, `actionCallMethod` type 1/MC paths, `actionGetVariable` this resolution |

---

## Estimated Impact

| Phase | Tests Improved | Effort |
|-------|---------------|--------|
| Phase 1 | this_swf5 (+~8 lines), this_swf6 (+~8 lines), mutable_this (+4 lines) | Low |
| Phase 2 | swf5_no_closure (+~6 lines) | Low |
| Phase 3 | this_swf5 (+~3 lines), this_swf6 (+~3 lines) | Low |
| Phase 4 | swf5_no_closure (+~3 lines) | Medium |
| Phase 5 | this_scoping (+~2 lines) | Low (verify only) |
| Phase 6 | this_scoping (+~10 lines) | Medium (string path resolution) |
