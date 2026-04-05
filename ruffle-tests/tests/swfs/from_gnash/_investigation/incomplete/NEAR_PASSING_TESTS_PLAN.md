# Near-Passing Tests Investigation Plan
<!-- TESTS: Color-v6, Selection-v6, Selection-v7, Selection-v8, super_test1, inheritance, TextFieldTest -->

Last updated: 2026-04-05

## Status: IN PROGRESS

---

## Overview

This plan covers tests that are very close to passing (1-15 diffs) and were investigated on 2026-04-05.

## Fix 1: Selection indices after setFocus — DONE (commit 167991c4)

**Lines**: 72-74 in Selection-v6 (same pattern in v7/v8)
**Root cause**: `selection_do_focus_change()` sets `g_selection_begin/caret/end = -1`, then `g_tf_select_all = 1`. But `getBeginIndex()` etc. return -1 directly without resolving the select-all state.
**Fix**: Set `g_selection_begin = g_selection_caret = g_selection_end = 0` alongside `g_tf_select_all = 1` in both new-focus and re-focus paths.
**Impact**: -3 diffs per version. Selection-v6: 15→12, Selection-v7: 15→12, Selection-v8: 14→11. Tests still not passing (other diffs remain).

## Fix 2: Missing pushSuperContext in apply/call — DONE (commit 7533cd5d)

**Lines**: 76-77 in super_test1 (misc-mtasc)
**Root cause**: The `apply` and `call` handlers in `actionCallMethod` FUNCTION branch didn't call `pushSuperContext` before invoking the function.
**Fix**: Added `pushSuperContext(this_obj, 1)` / `popSuperContext()` around function invocation in both `apply` and `call` paths.
**Impact**: super_test1 now PASSES (17/17). +1 test.

## Fix 3: Missing arguments in actionNewMethod — DONE (commit d357d21c)

**Lines**: 10 in inheritance (misc-mtasc)
**Root cause**: `actionNewMethod` didn't set up the `arguments` object (with callee/caller) for DefineFunction2 constructors.
**Fix**: Added arguments array creation + setupArgumentsProps() in the DefineFunction2 path of `actionNewMethod`, gated on `!(func->flags & 0x0008)` (suppress_args).
**Impact**: inheritance now PASSES (22/22). +1 test.

## Fix 4: SWF6 Case-Insensitive Constructor Shadowing — MEDIUM (Color-v6, 4 lines)

**Lines**: 165-168 in Color-v6
**Root cause**: `actionNewObject` has hardcoded `strcmp(ctor_name, "Color") == 0` that bypasses variable resolution. In SWF6, `color = 8` (lowercase) should shadow the `Color` constructor via case-insensitive matching. `new Color()` should return undefined when the variable is overwritten or deleted.
**Fix**: Before using hardcoded constructor path, check if a variable with the same name exists in scope chain (case-insensitive for SWF6). If it's a non-function, skip to the fallback. Also fix the "unknown constructor" fallback to push UNDEFINED instead of an empty object.
**Impact**: Fixes 4 real diffs → Color-v6 goes to 165/171 → 171/171 PASS.

## Investigated but NOT Fixable

### TextFieldTest (misc-mtasc) — 1 diff, ACCEPTED
**Line 2**: textfield height 17.05 (expected) vs 20.3 (actual). Font metrics issue. Even Ruffle doesn't match (produces 16). All three implementations disagree. ACCEPTED_DIFFS candidate.

### Selection-v6 Category 4: setSelection text length (7 lines) — Shared with Ruffle
Selection index values match Ruffle exactly but differ from Flash. Text field content model difference. Deep infrastructure, accept as shared Ruffle/Flash difference.

### Selection-v6 Category 1: instanceof MovieClip (1 line) — Medium
createEmptyMovieClip MC fails instanceof check. Needs debugging.

### Selection-v6 Category 3: setFocus return values (2 lines) — Mixed
One line shared with Ruffle (acceptble), one line our-only regression. Medium difficulty.

## Priority Order

1. Fix 2 (super_test1) — quickest, may flip test to PASS
2. Fix 3 (inheritance arguments) — may flip test to PASS
3. Fix 1 (Selection indices) — improves 3 tests but may not flip them
4. Fix 4 (Color-v6 constructor) — would flip Color-v6 to PASS
