# Inheritance Segfault Investigation Plan
<!-- TESTS: Inheritance-v7, Inheritance-v8 -->

Last updated: 2026-03-20

## Status: PARTIALLY FIXED — segfaults resolved, Function.prototype + typeof(super) fixed, 11 diffs remain (v7)

---

## Overview

Inheritance-v7 and Inheritance-v8 were the only 2 remaining segfaults in the gnash suite (the original 11 segfaults were all caused by the child movie transform buffer overflow, fixed in Phase 1). These tests exercise a 3-level OOP inheritance chain (A→B→C) where each level's `whoami()` method calls `super.whoami()`.

## Fix 1: Infinite Recursion in Multi-Level super.method() Chains (DONE)

When `co.whoami()` was called on an instance of class C (which extends B, which extends A):

1. The OBJECT handler in `actionCallMethod` pushes a local scope with `super = SUPER(co, depth=1)` and calls C's `whoami`
2. C's `whoami` calls `super.whoami()` — the SUPER handler correctly computes `new_depth = 2` and pushes it to `g_super_depth_stack`, then dispatches to B's `whoami`
3. B's `whoami` calls `actionGetVariable("super")` — this searches the **scope chain first**
4. **Bug**: The scope chain still had the **stale** `super = SUPER(co, depth=1)` from step 1. The `g_super_depth_stack` (which had the correct depth=2) was never reached because the scope chain lookup succeeded first with the wrong depth.
5. B's `whoami` calls `super.whoami()` with depth=1 again → resolves to B's `whoami` instead of A's → infinite recursion → stack overflow

**Fix**: Early "super" lookup from `g_super_depth_stack` before scope chain search in `actionGetVariable`.

## Fix 2: Function.prototype Chain and Constructor Resolution (DONE — 2026-03-20)

Four improvements to Function.prototype infrastructure:

1. **Function.prototype.constructor**: Set `constructor` property on Function.prototype (both primary and secondary version groups) pointing to the Function constructor. Fixes `DerivedClass1.constructor == Function`.

2. **Function.prototype_obj**: Set `g_ctors[5].prototype_obj = fn_proto` so `instanceof Function` has a valid prototype to compare against. Also set `g_function_constructor` file-scoped reference for secondary init.

3. **Virtual Function.prototype for GetMember**: When a function's `own_props` doesn't have a requested property, fall through to `getFunctionProto()` → Object.prototype chain. Previously only `__proto__` was handled virtually; now all properties resolve via the chain.

4. **Virtual Function.prototype for CallMethod**: When a method is not found on `own_props`, check `getFunctionProto()` chain. This allows `hasOwnProperty` (from Object.prototype) to be called on function objects.

5. **instanceof for FUNCTION objects**: When a function has no `__proto__` in `own_props`, use `getFunctionProto()` as the starting prototype for the chain walk. Also check both version group Function.prototypes for cross-version compatibility.

6. **Secondary Function constructor prototype_obj**: Set `sec_extra_ctors[3].prototype_obj = sec_fn_proto` in `ensureSecondaryGlobalInit` so `instanceof Function` works in the secondary version group.

### Files Modified

| File | Change |
|------|--------|
| `SWFModernRuntime/src/actionmodern/action.c` | Function.prototype constructor property, prototype_obj, virtual proto in GetMember/CallMethod/instanceof, secondary init |

## Test Results

### After segfault fix only (2026-03-19)

| Test | Before | After | Diffs |
|------|--------|-------|-------|
| Inheritance-v7 | **Segfault** | Output mismatch | ~18 |
| Inheritance-v8 | **Segfault** | Output mismatch | ~18 |

### After Function.prototype + typeof(super) improvements (2026-03-20)

| Test | Before | After | Improvement |
|------|--------|-------|-------------|
| Inheritance-v7 | 18 diffs | **11 diffs** | -7 lines |
| Inheritance-v8 | 18 diffs | **10 diffs** | -8 lines |
| Inheritance-v6 | 26 diffs | **20 diffs** | -6 lines |
| Inheritance-v5 | 19 diffs | **19 diffs** | 0 (v5 has no Function.prototype / typeof super tests) |

Lines fixed:
- `Function.fake == Function.prototype.fake` (line 9, v7 only)
- `derived.typeofSuper() == 'object'` (line 61)
- `DerivedClass.prototype.typeofSuper() == 'object'` (line 62)
- `typeof(s) == 'object'` (line 63, where s = super)
- `SubObj1.prototype.constructor.__proto__.constructor == Function` (line 104)
- `typeof(DerivedClass1.constructor) == 'function'` (line 110)
- `DerivedClass1.constructor == Function` (line 121)
- `SubObj1.prototype != undefined` (line 102, v8 only)

### Regression checks — all pass

- `as2_super_and_this_v6`: PASS
- `as2_super_and_this_v8`: PASS
- `as2_super_via_manual_prototype`: PASS
- `super_edge_cases`: PASS
- `swf5_to_6_cross_call`: PASS
- `swf5_no_closure`: PASS
- `register_class_return_value`: PASS
- `as2_oop`: PASS
- `define_function2_preload_order`: PASS
- `register_and_init_order`: PASS

## Remaining Diff (Inheritance-v7: 11 diffs, v8: 10 diffs)

| Category | Lines | Issue | Blocker |
|----------|-------|-------|---------|
| `Function.prototype.apply` | 1 | `functionObject.apply != undefined` — apply/call not installed as properties on Function.prototype (only handled in CallMethod dispatch) | Medium: need to create apply/call as actual ASFunction objects on Function.prototype |
| Constructor call count (FctorCalls) | 2 | `new F()` constructor not incrementing FctorCalls — likely `new Function(string_body)` creating stub object instead of calling constructor body | Deep: requires understanding how `new Function(string_body)` should work |
| `instanceof Function/Object` | 2 | Virtual Function.prototype check fires, but SubObj1 still fails — possibly SubObj1 has own_props with stale __proto__ from some earlier SetMember, bypassing the virtual fallback | Medium: need to trace SubObj1 own_props state at check time |
| `SubObj1.prototype` undefined (v7 only) | 1 | SubObj1.prototype returns undefined despite lazy creation code — may be Gnash test specific (v8 passes this check) | Unknown |
| `hasOwnProperty('constructor')` | 2 | `DerivedClass1.hasOwnProperty('constructor')` expects true — functions would need `constructor` as own property, not just inherited via proto chain | Low priority: may be Gnash-specific behavior |
| Count/extra line | 3 | #passed/#failed counts + egg/chicken extra output | N/A (follows from above) |

These are shared with Inheritance-v5/v6 (output_mismatch, not segfault) and tracked in `FAILING_TESTS_BY_FEATURE.md` category 7.
