# Inheritance Segfault Investigation Plan
<!-- TESTS: Inheritance-v7, Inheritance-v8 -->

Last updated: 2026-03-19

## Status: FIXED — segfaults resolved, tests now output_mismatch

---

## Overview

Inheritance-v7 and Inheritance-v8 were the only 2 remaining segfaults in the gnash suite (the original 11 segfaults were all caused by the child movie transform buffer overflow, fixed in Phase 1). These tests exercise a 3-level OOP inheritance chain (A→B→C) where each level's `whoami()` method calls `super.whoami()`.

## Root Cause: Infinite Recursion in Multi-Level super.method() Chains

When `co.whoami()` was called on an instance of class C (which extends B, which extends A):

1. The OBJECT handler in `actionCallMethod` pushes a local scope with `super = SUPER(co, depth=1)` and calls C's `whoami`
2. C's `whoami` calls `super.whoami()` — the SUPER handler correctly computes `new_depth = 2` and pushes it to `g_super_depth_stack`, then dispatches to B's `whoami`
3. B's `whoami` calls `actionGetVariable("super")` — this searches the **scope chain first**
4. **Bug**: The scope chain still had the **stale** `super = SUPER(co, depth=1)` from step 1. The `g_super_depth_stack` (which had the correct depth=2) was never reached because the scope chain lookup succeeded first with the wrong depth.
5. B's `whoami` calls `super.whoami()` with depth=1 again → resolves to B's `whoami` instead of A's → infinite recursion → stack overflow

## Fix Applied

In `SWFModernRuntime/src/actionmodern/action.c`, added an early check in `actionGetVariable` that resolves "super" from the super context stack (`g_super_depth_stack`) **before** searching the scope chain. This ensures nested `super.method()` calls always use the most recently pushed depth, not a stale value from an ancestor scope.

### Files Modified

| File | Change |
|------|--------|
| `SWFModernRuntime/src/actionmodern/action.c` | Early "super" lookup from `g_super_depth_stack` before scope chain search (~line 25108) |

## Test Results After Fix

| Test | Before | After | Lines Matching |
|------|--------|-------|----------------|
| Inheritance-v7 | **Segfault** | Output mismatch | ~165/182 (90.7%) |
| Inheritance-v8 | **Segfault** | Output mismatch | ~165/182 (90.7%) |

### Regression checks — all pass

- `as2_super_and_this_v6`: PASS
- `as2_super_and_this_v8`: PASS
- `as2_super_via_manual_prototype`: PASS
- `super_edge_cases`: PASS
- `swf5_to_6_cross_call`: PASS
- `swf5_no_closure`: PASS
- `register_class_return_value`: PASS

## Remaining Diff (Inheritance-v7/v8)

~17 assertion failures remain, all pre-existing OOP issues unrelated to the super recursion fix:

| Category | Lines | Issue |
|----------|-------|-------|
| `Function.prototype` on user functions | ~4 | `func.__proto__ == Function.prototype` fails — user functions don't have `__proto__` set to Function.prototype |
| `Function.apply` / `Function.call` | ~3 | apply/call not available on function objects |
| `typeof(super)` | ~2 | Returns 'undefined' instead of 'object' |
| `constructor` property resolution | ~3 | Constructor property on derived class instances |
| `instanceof Function` | ~2 | User-defined functions not instanceof Function |
| Infinite recursion detection | ~1 | "egg/chicken" test expects call stack depth limit behavior |
| Other | ~2 | Miscellaneous |

These are shared with Inheritance-v5/v6 (output_mismatch, not segfault) and tracked in `FAILING_TESTS_BY_FEATURE.md` category 7.
