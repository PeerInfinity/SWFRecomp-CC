# Near-Passing Tests Investigation Plan (SUPERSEDED)
<!-- TESTS: Color-v6, Selection-v6, Selection-v7, Selection-v8, super_test1, inheritance, TextFieldTest -->

**NOTE: Superseded by GNASH_NEAR_PASSING_PLAN.md, which covers these tests plus
17 more near-passing tests. Fixes 1-4 below are still valid and retained for
historical reference.**

Last updated: 2026-04-05 (superseded 2026-04-07)

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

## Fix 3: Missing arguments.callee in actionNewMethod — DONE (commits d357d21c + dea9d8ef)

**Lines**: 10 in inheritance (misc-mtasc)
**Root cause (corrected)**: `actionNewMethod` didn't set `g_current_executing_func = func` before calling the constructor. The recompiler-generated code calls `swf_setup_arguments_props(g_current_executing_func)` to set `arguments.callee`, but `g_current_executing_func` pointed to the calling function instead of the constructor.
**Fix**: (1) Added arguments array + setupArgumentsProps in actionNewMethod (d357d21c). (2) Set `g_current_executing_func = func` before the advanced_func call (dea9d8ef). Fix #2 was the actual root cause; fix #1 provides redundant backup.
**Impact**: inheritance now PASSES (22/22) with fresh recompilation. +1 test.

## Fix 4: SWF6 Case-Insensitive Constructor Shadowing — PARTIAL (commit ea3683bc)

**Lines**: 165-168 in Color-v6
**Root cause**: `actionNewObject` hardcoded constructors bypass variable resolution. SWF6 case-insensitive `color = 8` should shadow `Color`.
**Fix**: Added scope chain + variable table shadowing checks before both hardcoded and general constructor lookups. Also changed unknown-constructor fallback to push undefined instead of creating empty object.
**Impact**: 2 of 4 real diffs fixed (165→167/171). Remaining 2 diffs are post-delete case where Flash considers the constructor permanently gone — needs deeper SetVariable/delete/\_global interaction work.

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
