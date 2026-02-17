# Try/Catch/Finally Implementation Plan
<!-- TESTS: try_finally_simple, catch_references_registers, uncaught_exception, uncaught_exception_bubbled, try_catch_finally -->

Last updated: 2026-02-16

## Status: IMPLEMENTED (114/120 lines passing)

### Current State

Exception handler stack, control flow flags, and recompiler codegen all implemented. The core try/catch/finally control flow works correctly. 6 remaining line differences are all CastOp/instanceof issues (pre-existing, separate from exception handling).

| Test | Status | Notes |
|------|--------|-------|
| `try_finally_simple` | **PASS** | No exception thrown, try falls through to finally |
| `catch_references_registers` | **PASS** | Simple try-catch with register-based catch |
| `uncaught_exception` | **PASS** | No try block, prints warning and halts |
| `uncaught_exception_bubbled` | **PASS** | Throw propagates through call chain |
| `try_catch_finally` | **MISMATCH (114/120)** | 6 line diff — CastOp typed catch doesn't match `new String()` or `{}` |

### What Works (after implementation)

- Exception handler stack with `ExceptionFrame[16]` supporting nested try blocks
- `actionThrow` searches handler stack top-down, skipping consumed handlers
- `actionCatchEnter` disables current handler so rethrow propagates to parent
- `actionThrowPending` + `goto finally` for throw inside catch-with-finally
- `actionSetReturnPending` + `goto finally` for return inside try/catch-with-finally
- `actionTryEnd` re-propagates pending exceptions to parent handlers
- `actionCatchGetException` for DefineFunction2 local register catch
- First-pass label registration for finally_start and after_end
- Label placement: after_end label emitted BEFORE actionTryEnd for try-catch-no-finally

### Remaining Issues (6 lines)

All in `try_catch_catch_finally` — typed catches using CastOp:
- `new String()` not recognized as instance of String constructor → falls to "other" catch
- `{}` not recognized as instance of Object constructor → falls to "other" catch
- These are **CastOp/instanceof issues**, not exception handling issues

---

## Implementation Details (completed)

### Architecture: Exception Handler Stack + Control Flow Flags

Replaced single global `jmp_buf` with a stack of exception handlers. Each try block pushes a handler frame. Control flow flags (not C `return`) defer exits until finally completes.

### Data Structures

```c
#define MAX_EXCEPTION_DEPTH 16

typedef struct {
    jmp_buf handler;
    int has_jmp_buf;     // 0 = consumed (in catch), 1 = active
} ExceptionFrame;

typedef struct {
    ExceptionFrame frames[MAX_EXCEPTION_DEPTH];
    int depth;

    bool exception_thrown;
    ActionVar exception_value;

    bool return_pending;
    ActionVar return_value;
} ExceptionState;

static ExceptionState g_exception_state = {0};
```

### Runtime Functions

| Function | Purpose |
|----------|---------|
| `actionTryBegin` | Push frame at `depth`, increment depth |
| `actionGetExceptionJmpBuf` | Return `&frames[depth-1].handler`, set `has_jmp_buf=1` |
| `actionCatchEnter` | Clear `frames[depth-1].has_jmp_buf` (rethrow goes to parent) |
| `actionCatchToVariable` | Store exception value in named variable |
| `actionCatchToRegister` | Store exception value in global register |
| `actionCatchGetException` | Store exception value in output `ActionVar*` (for DefineFunction2 local regs) |
| `actionThrow` | Pop value, search stack top-down for active handler, longjmp |
| `actionThrowPending` | Pop value, set `exception_thrown=true`, do NOT longjmp (for catch→finally) |
| `actionTryEnd` | Decrement depth; if exception pending, re-propagate to parent handler |
| `actionSetReturnPending` | Save return value, set `return_pending=true` |
| `actionReturnPending` | Check if return is pending |
| `actionGetPendingReturn` | Return saved value, clear pending flag |

### Recompiler Changes

#### First Pass: TRY Label Registration
- Added `SWF_ACTION_TRY` case to register `finally_start` and `after_end` as labels
- **Critical fix**: Must use byte-by-byte reads (not `VAL` macro) because the TRY header fields are at unaligned offsets. The `VAL(u16, action_buffer + 1)` cast causes undefined behavior due to strict aliasing/alignment, producing incorrect values on some compilers/optimizations.

#### Second Pass: Boundary Handler
- Catch entry (state 0→1): Emit `actionCatchEnter` before catch-to-variable/register
- For catch-to-register in DefineFunction2: emit `actionCatchGetException(&regs[N])` instead of `actionCatchToRegister(N)` (global vs local registers)
- End transition (state→3): For no-finally, pre-emit after_end label BEFORE `actionTryEnd`; for has-finally, emit pending return check after `actionTryEnd`
- `emitted_labels` set tracks labels pre-emitted by boundary handler (skip in generic label code)

#### ActionReturn Inside Try/Catch-with-Finally
- Detect innermost try boundary with `has_finally && state <= 1`
- Emit `actionSetReturnPending` + `goto label_finally` instead of C `return`

#### ActionThrow Inside Catch-with-Finally
- Detect innermost try boundary with `state == 1 && has_finally`
- Emit `actionThrowPending` + `goto label_finally` instead of `actionThrow`

---

## Files Modified

### Recompiler (`SWFRecomp/`)

| File | Changes |
|------|---------|
| `src/action/action.cpp` | First-pass TRY label registration (byte-by-byte reads); boundary handler: actionCatchEnter, actionCatchGetException, label placement, pending return check; ActionReturn/ActionThrow context-aware emission |

### Runtime (`SWFModernRuntime/`)

| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | Exception handler stack; actionCatchEnter, actionThrowPending, actionCatchGetException, actionSetReturnPending/ReturnPending/GetPendingReturn; revised actionThrow (stack search), actionTryEnd (re-propagation) |
| `include/actionmodern/action.h` | New function declarations: actionThrowPending, actionCatchEnter, actionCatchGetException, actionExceptionPending, actionSetReturnPending, actionReturnPending, actionGetPendingReturn |

---

## Key Bugs Found During Implementation

1. **VAL macro alignment UB**: `VAL(u16, action_buffer + 1)` in the first-pass TRY case produced wrong values (e.g., try_size=0 instead of 27) because the pointer was unaligned and the type-punning cast triggered undefined behavior. Fixed with manual byte-by-byte reads: `(u8)buf[1] | ((u8)buf[2] << 8)`.

2. **DefineFunction2 register mismatch**: `actionCatchToRegister` writes to global `g_registers[N]`, but DefineFunction2 code uses local `regs[N]`. Fixed by adding `actionCatchGetException` that writes directly to an output `ActionVar*`.

3. **Label not registered for finally blocks**: The first-pass bug (item 1) meant `finally_start` was never added to the labels set, so `goto label_XX` for finally had no target label in the generated code, causing a compile error.

---

## Verification Results

```
try_finally_simple:          PASS (no regression)
catch_references_registers:  PASS (no regression)
uncaught_exception:          PASS (no regression)
uncaught_exception_bubbled:  PASS (no regression)
try_catch_finally:           MISMATCH (114/120 lines)
                             - 6 lines differ, all CastOp/instanceof
                             - Was: TIMEOUT/SEGFAULT (infinite rethrow loop)
```

## Next Steps

The 6 remaining line differences require fixing CastOp/instanceof to properly check prototype chains for built-in constructors (String, Object). This is tracked separately from exception handling.
