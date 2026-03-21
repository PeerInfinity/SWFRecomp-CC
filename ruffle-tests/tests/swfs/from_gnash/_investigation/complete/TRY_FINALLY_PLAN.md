# Try/Catch/Finally Fix Plan
<!-- TESTS: Try-v6, Try-v7, Try-v8 -->

Last updated: 2026-03-19

## Status: FIXED — All 3 tests PASS (20/20 lines each)

Note: Try-v5 does not exist in the gnash suite — only v6, v7, v8.

---

## Overview

All three Try tests crashed with `heap_alloc(144418) failed - out of memory` after producing 11 of 20 expected output lines (sub-tests 1-7 passed, crash during sub-test 8 which exercises nested try-finally blocks).

## Root Cause: Two Bugs

### Bug 1: Infinite Loop in Nested Try-Finally Exception Propagation (Runtime)

In `SWFModernRuntime/src/actionmodern/action.c`, both `actionThrow()` and `actionTryEnd()` search the exception handler stack for a handler with `has_jmp_buf=1` and `longjmp` to it. However, they did **not** clear `has_jmp_buf` before the longjmp.

For try-**catch** blocks, `actionCatchEnter()` clears `has_jmp_buf` when entering the catch clause. But for try-**finally** blocks (no catch), `actionCatchEnter` is never called, so `has_jmp_buf` remains set. This creates an infinite loop:

1. Exception thrown inside innermost try-finally → longjmp to handler
2. Finally block runs → `actionTryEnd` re-propagates the pending exception → searches for parent handler
3. Finds the **same** try-finally handler (still has `has_jmp_buf=1`) → longjmp to it again
4. Repeat forever, each iteration doing string concatenation allocations until OOM

**Fix**: Clear `has_jmp_buf = 0` before `longjmp` in both `actionThrow()` and `actionTryEnd()`.

### Bug 2: Return Inside Finally Skips Exception Cleanup (Recompiler)

In `SWFRecomp/src/action/action.cpp`, the `SWF_ACTION_RETURN` handler only defers returns when inside a try or catch block (`state <= 1`). When inside a finally block (`state == 2`), it emitted a direct C `return` without calling `actionTryEnd` or clearing the exception state. This left `exception_thrown = true` in global state after the function returned, causing the caller's try-catch to incorrectly catch a stale exception.

**Fix**: When return is inside a finally block, emit `actionClearException()` and `actionTryEnd()` calls before the return. Added new `actionClearException()` function to the runtime.

### Files Modified

| File | Change |
|------|--------|
| `SWFModernRuntime/src/actionmodern/action.c` | Clear `has_jmp_buf` before longjmp in `actionThrow()` and `actionTryEnd()`; add `actionClearException()` |
| `SWFModernRuntime/include/actionmodern/action.h` | Declare `actionClearException()` |
| `SWFRecomp/src/action/action.cpp` | Emit cleanup calls before return-inside-finally |

## Test Results

| Test | Before | After |
|------|--------|-------|
| Try-v6 | **Runtime error** (OOM) | **PASS** (20/20) |
| Try-v7 | **Runtime error** (OOM) | **PASS** (20/20) |
| Try-v8 | **Runtime error** (OOM) | **PASS** (20/20) |

### Regression checks — all pass

- `try_catch_finally` (AVM1 suite): PASS (118/118)
- `try_finally_simple`: PASS
- `uncaught_exception`: PASS
- `uncaught_exception_bubbled`: PASS
- `catch_references_registers`: PASS
- `infinite_recursion_function`: PASS
- `watch` (uses try internally): PASS
