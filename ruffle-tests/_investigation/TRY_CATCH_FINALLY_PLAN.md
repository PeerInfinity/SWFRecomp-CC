# Try/Catch/Finally Implementation Plan
<!-- TESTS: try_finally_simple, catch_references_registers, uncaught_exception, uncaught_exception_bubbled, try_catch_finally -->

Last updated: 2026-02-15

## Status: NEEDS REARCHITECTURE

### Current State

Basic try/catch works for simple cases. The complex test **times out** (or segfaults) due to fundamental architectural flaws.

| Test | Status | Notes |
|------|--------|-------|
| `try_finally_simple` | **PASS** | No exception thrown, try falls through to finally |
| `catch_references_registers` | **PASS** | Simple try-catch with register-based catch |
| `uncaught_exception` | **PASS** | No try block, prints warning and halts |
| `uncaught_exception_bubbled` | **PASS** | Throw propagates through call chain |
| `try_catch_finally` | **TIMEOUT/SEGFAULT** | Complex test with all exception scenarios |

### What Works

- `actionThrow` pops from stack and stores in global `ExceptionState`
- `setjmp`/`longjmp` inline via `ACTION_TRY_SETJMP` macro (correctly places `setjmp` at call site)
- Simple try-catch: exception in try body → catch runs
- Simple try-finally: no exception → both run sequentially
- Catch-to-register and catch-to-variable
- Uncaught exceptions: warning + halt

### What Doesn't Work (5 fundamental problems)

1. **Single global `jmp_buf`** — nested try blocks and rethrows longjmp to the wrong destination. Rethrow from catch creates an infinite loop (the TIMEOUT).
2. **`return` in try/catch bypasses finally** — C `return` exits the function immediately; Flash's `return` inside try/catch defers until finally completes.
3. **No exception re-propagation after finally** — try-finally (no catch) should run finally then bubble the exception to the caller. No mechanism for this.
4. **No pending-return support** — `return` in try should: save return value → run finally → then actually return. Current code does a hard C `return`.
5. **No `jmp_buf` stack for nesting** — the single `g_exception_state` means nested try blocks clobber the outer handler.

---

## Test Analysis: `try_catch_finally` (120 expected lines)

The test defines 8 functions and calls them from script_0. Each tests a different exception handling scenario:

### Scenario 1: `try_catch_finally()` (lines 1-12)
- Try block calls `throws_error()` which throws "an error!"
- Exception caught, catch block runs, finally block runs
- **Current issue**: goto in try block skips finally (label placed AFTER finally code but before actionTryEnd — actually the label IS at the finally block start so this may work; the real issue is the catch→finally transition)

### Scenario 2: `try_catch_catch_finally("String")` (lines 14-23)
- Typed catch: uses CastOp to test String/Number/Object types, falls through to "other"
- A raw `"String"` primitive doesn't match `String` constructor (CastOp returns null)
- Falls to "other" catch block → finally runs
- **Current issue**: CastOp behavior may be wrong for primitives

### Scenario 3: `try_catch_catch_finally(new String())` (lines 25-34)
- `new String()` object DOES match String constructor → "String" catch block
- **Current issue**: Same as scenario 1 re: control flow

### Scenario 4: `try_catch_catch_finally({})` (lines 36-45)
- `{}` object matches Object constructor → "Object" catch block
- **Current issue**: Same as scenario 1

### Scenario 5: `try_catch_finally_rethrow()` (lines 47-60)
- Catch block catches exception, traces it, then **rethrows** via `actionThrow`
- Finally block STILL runs (before exception bubbles)
- Caller's try-catch catches the rethrown exception
- **THIS IS THE TIMEOUT**: rethrow calls `longjmp` back to the same `setjmp`, re-entering catch, which rethrows again → infinite loop

### Scenario 6: `try_catch_finally_return()` (lines 62-74)
- Catch block catches exception, then does `return error`
- Finally block STILL runs (between catch return and actual function exit)
- Function returns the caught error value
- **Current issue**: C `return` exits function immediately, skipping finally

### Scenario 7: `try_catch_finally()` again (lines 76-87)
- Repeat of scenario 1 — tests that exception state is clean after previous scenarios

### Scenario 8: `try_catch()` (lines 89-99)
- Try+catch only, no finally
- Code after try-catch (`"End of try_catch()"`) should execute
- **Current issue**: goto in try skips over actionTryEnd AND post-try code

### Scenario 9: `try_finally()` (lines 101-110)
- Try+finally, NO catch
- Exception in try → finally runs → exception bubbles to caller
- Caller catches with `"Error bubbled up"` + traces the error
- **Current issue**: No re-propagation mechanism after finally

### Scenario 10: `try_finally_return()` (lines 112-118)
- Try block does `return 5` — no exception thrown
- Finally block STILL runs
- Function returns 5
- **Current issue**: C `return` exits function immediately, skipping finally

---

## Root Cause: setjmp/longjmp Cannot Model Flash Exception Semantics

The Flash VM exception model requires:
1. **Finally always executes** — even after `return`, `throw`, or normal completion
2. **Exception re-propagation** — if a try-finally (no catch) encounters an exception, finally runs then the exception continues propagating
3. **Pending returns** — `return` in try/catch is deferred until after finally
4. **Nested try blocks** — inner try-catch should not clobber outer handler
5. **Rethrow** — throwing inside catch should propagate to the OUTER handler, not loop

`setjmp`/`longjmp` handles case (1) for the "exception in try → catch → finally" path, but cannot model deferred returns, re-propagation, or nested handlers without a proper handler stack.

---

## Proposed Architecture: Exception Handler Stack + Control Flow Flags

### Core Idea

Replace the single global `ExceptionState` with a **stack of exception handlers**. Each try block pushes a handler frame. Use **control flow flags** (not `return`) to defer exits until finally completes.

### Data Structures

```c
#define MAX_EXCEPTION_DEPTH 16

typedef struct {
    jmp_buf handler;
    bool has_jmp_buf;
} ExceptionFrame;

typedef struct {
    // Handler stack
    ExceptionFrame frames[MAX_EXCEPTION_DEPTH];
    int depth;            // current handler stack depth

    // Exception state
    bool exception_thrown;
    ActionVar exception_value;

    // Pending return state (for return-inside-try/catch)
    bool return_pending;
    ActionVar return_value;
} ExceptionState;

static ExceptionState g_exception_state = {0};
```

### Runtime Functions (revised)

```c
void actionTryBegin(SWFAppContext* app_context);
    // Push new frame, depth++

jmp_buf* actionGetExceptionJmpBuf(SWFAppContext* app_context);
    // Return &frames[depth-1].handler, set has_jmp_buf=1

void actionCatchToVariable(SWFAppContext* app_context, const char* var_name);
void actionCatchToRegister(SWFAppContext* app_context, u8 reg_num);
    // Same as now, store exception value

void actionTryEnd(SWFAppContext* app_context);
    // Pop frame, depth--
    // If exception_thrown && depth > 0: re-propagate (longjmp to parent)
    // If exception_thrown && depth == 0: uncaught exception warning + halt

void actionThrow(SWFAppContext* app_context);
    // Pop value, store in exception_value, set exception_thrown
    // If depth > 0: longjmp to frames[depth-1].handler
    // If depth == 0: uncaught warning + halt

bool actionExceptionPending(SWFAppContext* app_context);
    // Returns exception_thrown (for finally re-propagation check)

void actionSetReturnPending(SWFAppContext* app_context, ActionVar* value);
    // Set return_pending=true, return_value=*value

bool actionReturnPending(SWFAppContext* app_context);
    // Returns return_pending flag

ActionVar actionGetPendingReturn(SWFAppContext* app_context);
    // Returns return_value, clears return_pending
```

### Generated Code Changes (Recompiler)

The key insight: **the recompiler must generate different code for `return` and `throw` when inside a try block**, and must generate finally-aware control flow.

#### Pattern 1: try-catch-finally (normal case)

```c
actionTryBegin(app_context);
if (ACTION_TRY_SETJMP(app_context) == 0) {
    // Try block
    ...try body...
    // Normal completion: jump to finally
} else {
    // Catch block
    actionCatchToVariable(app_context, "error");
    ...catch body...
    // Fall through to finally
}
// Finally block
...finally body...
// After finally: check for pending exception or return
actionTryEnd(app_context);  // may re-propagate exception
```

No `goto` to skip over finally — **finally is always reached**. The try block's Jump bytecode (which currently generates `goto label_XX` past the finally) must instead jump to the finally block's start.

#### Pattern 2: `return` inside try/catch with finally

When the recompiler sees an ActionReturn inside a try or catch block that has a finally clause, it must emit:

```c
// Instead of: return ret_val;
{
    ActionVar ret_val;
    popVar(app_context, &ret_val);
    actionSetReturnPending(app_context, &ret_val);
    goto finally_label_XX;  // jump to finally
}
```

After the finally block:
```c
// Finally block
...finally body...
actionTryEnd(app_context);
if (actionReturnPending(app_context)) {
    return actionGetPendingReturn(app_context);
}
```

#### Pattern 3: `throw` inside catch (rethrow)

When `actionThrow` is called inside a catch block:
- The current frame's `jmp_buf` is the one for THIS try-catch, which would loop
- Solution: `actionThrow` must longjmp to the **parent** frame, not the current one

This is handled automatically by the handler stack: when we enter the catch block, we should **pop the current frame** (or mark it inactive) so that a throw inside catch propagates to the parent handler.

Revised catch entry:
```c
} else {
    // Catch entered — current handler is consumed
    // actionCatchToVariable already clears exception_thrown
    actionCatchToVariable(app_context, "error");
    ...catch body...  // any throw here goes to parent handler
}
```

But we still need the current depth for actionTryEnd. Better approach: **save/restore the jmp_buf**:

```c
} else {
    actionCatchToVariable(app_context, "error");
    // Invalidate current handler so rethrow goes to parent
    actionDisableCurrentHandler(app_context);
    ...catch body...
}
// Finally block
// Re-enable handler for finally cleanup
...finally body...
actionTryEnd(app_context);
```

Or simpler: the handler stack approach naturally handles this. When `actionThrow` is called:
1. It sets `exception_thrown = true` and stores the value
2. It searches for the nearest **active** handler frame
3. If the current frame is in catch state (no longer trapping), it goes to the parent

Actually, the simplest approach: **decrement depth at catch entry, re-increment before finally**:

```c
actionTryBegin(app_context);          // depth++ (now N)
if (ACTION_TRY_SETJMP(app_context) == 0) {
    // Try block — handler at depth N catches throws
    ...try body...
} else {
    actionCatchEnter(app_context);     // depth-- (now N-1), store exception
    actionCatchToVariable(app_context, "error");
    ...catch body...                   // throws here go to depth N-1 (parent)
}
actionFinallyEnter(app_context);       // depth++ (back to N) if was in catch
// Finally block
...finally body...
actionTryEnd(app_context);             // depth-- (back to N-1), may re-propagate
```

Wait, this doesn't work cleanly because the jmp_buf at depth N is the same one the catch is using.

**Simplest correct approach**: When entering catch, **don't change depth**, but clear the `has_jmp_buf` flag on the current frame. When `actionThrow` searches for a handler, it skips frames with `has_jmp_buf == 0`:

```c
void actionThrow(SWFAppContext* app_context) {
    // ... set exception state ...
    // Find nearest active handler
    for (int i = g_exception_state.depth - 1; i >= 0; i--) {
        if (g_exception_state.frames[i].has_jmp_buf) {
            longjmp(g_exception_state.frames[i].handler, 1);
        }
    }
    // No handler found — uncaught
    ...
}
```

And in catch entry:
```c
actionCatchToVariable(app_context, "error");
// Disable current handler so rethrow propagates to parent
g_exception_state.frames[g_exception_state.depth - 1].has_jmp_buf = 0;
```

This way, a rethrow in catch goes to the parent frame, which is exactly what Flash does.

#### Pattern 4: try-finally (no catch) — exception re-propagation

```c
actionTryBegin(app_context);
if (ACTION_TRY_SETJMP(app_context) == 0) {
    // Try block
    ...try body...
}
// No catch — if exception occurred, it's still pending
// Finally block (always runs — both normal and exception paths)
...finally body...
actionTryEnd(app_context);  // checks exception_thrown, re-propagates to parent
```

`actionTryEnd` revised:
```c
void actionTryEnd(SWFAppContext* app_context) {
    g_exception_state.depth--;

    if (g_exception_state.exception_thrown) {
        // Exception still pending after finally — re-propagate
        if (g_exception_state.depth > 0) {
            // Find parent handler
            for (int i = g_exception_state.depth - 1; i >= 0; i--) {
                if (g_exception_state.frames[i].has_jmp_buf) {
                    longjmp(g_exception_state.frames[i].handler, 1);
                }
            }
        }
        // No parent handler — uncaught
        // ... print warning, halt ...
    }
}
```

#### Pattern 5: try-catch (no finally) — code after try-catch

Currently the try block's bytecode Jump generates `goto label_XX` that skips past the catch. The label lands after `actionTryEnd`. This is correct for try-catch-only (no finally). When try completes normally, skip catch and continue. When exception occurs, catch runs, then falls through to code after.

Current generated code structure:
```c
actionTryBegin(app_context);
if (ACTION_TRY_SETJMP(app_context) == 0) {
    ...try body...
    goto label_after;   // skip catch on success
} else {
    actionCatchToVariable(app_context, "error");
    ...catch body...
}
actionTryEnd(app_context);
label_after:
...code after try-catch...
```

**Bug**: `actionTryEnd` only runs on the catch path, not the try-success path! The goto skips it. This means `depth` never decrements on success. Fix: put the label BEFORE `actionTryEnd`, or emit `actionTryEnd` on both paths.

Better: restructure so actionTryEnd always runs:
```c
actionTryBegin(app_context);
int _exc_XX = ACTION_TRY_SETJMP(app_context);
if (_exc_XX == 0) {
    ...try body...
}
if (_exc_XX != 0) {
    actionCatchToVariable(app_context, "error");
    ...catch body...
}
actionTryEnd(app_context);
// code after try-catch
```

But this changes the control flow significantly. The current `if/else` approach works for the catch path — the issue is the goto in the try body that skips past everything.

**Simpler fix for try-catch-no-finally**: ensure the goto target is BEFORE `actionTryEnd`, not after:

```c
if (ACTION_TRY_SETJMP(app_context) == 0) {
    ...try body...
    goto label_trycatch_end;
} else {
    actionCatchToVariable(app_context, "error");
    ...catch body...
}
label_trycatch_end:
actionTryEnd(app_context);
// code continues
```

For try-catch-finally, the try body's jump should go to the finally block:
```c
if (ACTION_TRY_SETJMP(app_context) == 0) {
    ...try body...
    goto label_finally;
} else {
    actionCatchToVariable(app_context, "error");
    ...catch body...
}
label_finally:
...finally body...
actionTryEnd(app_context);
```

This is essentially what the current code generates, except the label placement is wrong in some cases.

---

## Implementation Plan

### Phase 1: Exception Handler Stack (fixes nesting + rethrow)

**Files**: `action.c`, `action.h`

1. Replace single `jmp_buf` with `ExceptionFrame frames[MAX_EXCEPTION_DEPTH]` stack
2. `actionTryBegin`: push frame at `depth`, increment depth
3. `actionGetExceptionJmpBuf`: return `&frames[depth-1].handler`
4. `actionThrow`: search stack top-down for frame with `has_jmp_buf`, longjmp to it
5. `actionTryEnd`: decrement depth; if `exception_thrown` and `depth > 0`, re-propagate by longjmp to parent
6. New: `actionCatchEnter(app_context)` — clears current frame's `has_jmp_buf` so rethrow goes to parent

**Tests fixed**: The rethrow infinite loop (scenario 5) is fixed because rethrow now goes to parent handler. The TIMEOUT should be resolved.

### Phase 2: Finally Always Executes (fixes control flow)

**Files**: `action.cpp` (recompiler)

Fix the boundary-based code generation to ensure finally code is always reached:

1. **try-catch-finally**: The try body's Jump target must point to the finally block start (label BEFORE finally code). Currently the label is at the right place — verify this. The catch block must fall through to finally (no goto needed).

2. **try-catch (no finally)**: The try body's Jump target must be AFTER the `}` close but BEFORE `actionTryEnd`. Currently the label is AFTER `actionTryEnd` — this is a bug. Fix: emit `actionTryEnd` before the label.

3. **try-finally (no catch)**: No Jump in try body (catch_size=0 means no catch to skip). After `if` block closes, fall through to finally. This already works.

Changes to recompiler boundary handling:
- When `state == 0` (try) transitions to `state == 3` (end) for try-catch-no-finally: close `if/else`, emit `actionTryEnd`, THEN emit the label
- When `state == 2` (finally) transitions to `state == 3` (end): emit `actionTryEnd` after the finally code

Actually, looking more carefully at the recompiler boundary code: the label is emitted by the generic label-insertion code (line 272-278) based on bytecode offsets. The `goto` in the try body goes to a label computed from the bytecode offset of the code after the try-catch-finally construct. We need to either:
- (a) Adjust where the label is placed relative to `actionTryEnd`, or
- (b) Not emit goto at all for the Jump bytecode at end of try body, and instead let normal flow reach finally

Option (b) is cleaner: **detect when a Jump bytecode targets the end of a try-catch-finally construct, and emit a `goto` to a label that we place at the finally block (or at actionTryEnd for try-catch-no-finally)**. This requires the recompiler to know the try block boundary when emitting the Jump.

Simplest approach: When emitting a Jump (`goto label_XX`) inside a try body:
- If the target address equals `tb.after_end` (the first byte after the entire construct), redirect the goto to a label at the finally block start (or just before `actionTryEnd` if no finally).
- This can be done by checking `try_boundaries` when emitting Jump opcodes.

### Phase 3: Return Inside Try/Catch Defers to Finally

**Files**: `action.cpp` (recompiler), `action.c`, `action.h` (runtime)

When the recompiler sees `ActionReturn` inside a try or catch block that has a finally clause:

1. Emit `actionSetReturnPending(app_context, &ret_val)` instead of `return ret_val`
2. Emit `goto finally_label_XX` to jump to the finally block
3. After the finally block, before `actionTryEnd`, emit:
   ```c
   actionTryEnd(app_context);
   if (actionReturnPending(app_context)) {
       return actionGetPendingReturn(app_context);
   }
   ```

Runtime additions:
- `actionSetReturnPending(app_context, &value)` — saves return value
- `actionReturnPending(app_context)` — returns true if return is pending
- `actionGetPendingReturn(app_context)` — returns saved value, clears flag

The recompiler needs to track whether we're currently inside a try block (check `try_boundaries` stack) and whether the current try has a finally clause.

### Phase 4: Disable Current Handler on Catch Entry

**Files**: `action.c`, `action.h`; possibly `action.cpp`

Add `actionCatchEnter(app_context)` that clears `frames[depth-1].has_jmp_buf`. This must be called BEFORE any catch body code executes.

Generated code becomes:
```c
} else {
    actionCatchEnter(app_context);  // NEW: disable current handler
    actionCatchToVariable(app_context, "error");
    ...catch body...
}
```

This ensures a `throw` inside catch propagates to the parent handler, not back to the same setjmp point.

---

## Implementation Order and Dependencies

```
Phase 1 (handler stack) ──→ Phase 4 (catch entry)
    │
    └──→ Phase 2 (finally control flow) ──→ Phase 3 (deferred return)
```

Phase 1 is the critical fix — it resolves the TIMEOUT and enables all other phases.

### Phase-by-Phase Test Impact

| Phase | Scenarios Fixed | Notes |
|-------|----------------|-------|
| 1 | #5 (rethrow), #9 (try-finally re-propagation) | Fixes TIMEOUT, enables rethrow + bubble |
| 2 | #1, #2, #3, #4, #7, #8 (label placement) | Ensures finally always runs, code after try-catch works |
| 3 | #6 (return in catch), #10 (return in try) | Deferred return with finally |
| 4 | Already covered by Phase 1 | But makes it explicit/clean |

After all phases, all 10 scenarios should produce correct output (120/120 lines).

---

## Files to Modify

### Recompiler (`SWFRecomp/`)

| File | Changes |
|------|---------|
| `src/action/action.cpp` | Boundary handling: label placement relative to actionTryEnd; ActionReturn inside try/catch emits pending-return; Jump inside try body redirected to finally; emit actionCatchEnter |

### Runtime (`SWFModernRuntime/`)

| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | Replace ExceptionState with handler stack; revise actionThrow to search stack; revise actionTryEnd to re-propagate; add actionCatchEnter, actionSetReturnPending, actionReturnPending, actionGetPendingReturn |
| `include/actionmodern/action.h` | Declare new functions; update ExceptionState typedef |

---

## Detailed Code Changes

### action.h additions

```c
// Exception handling (revised)
void actionTryBegin(SWFAppContext* app_context);
jmp_buf* actionGetExceptionJmpBuf(SWFAppContext* app_context);
void actionCatchEnter(SWFAppContext* app_context);
void actionCatchToVariable(SWFAppContext* app_context, const char* var_name);
void actionCatchToRegister(SWFAppContext* app_context, u8 reg_num);
void actionTryEnd(SWFAppContext* app_context);
void actionThrow(SWFAppContext* app_context);
bool actionExceptionPending(SWFAppContext* app_context);
void actionSetReturnPending(SWFAppContext* app_context, ActionVar* value);
bool actionReturnPending(SWFAppContext* app_context);
ActionVar actionGetPendingReturn(SWFAppContext* app_context);
```

### action.cpp recompiler changes

#### 1. Track try block context for ActionReturn

When emitting ActionReturn, check `try_boundaries` to see if we're inside a try/catch with finally:

```cpp
case SWF_ACTION_RETURN:
{
    // Check if inside try/catch with finally
    bool in_try_with_finally = false;
    int finally_label = -1;
    for (auto& tb : try_boundaries) {
        if (tb.has_finally && tb.state <= 1) {
            in_try_with_finally = true;
            finally_label = (s16)(tb.finally_start - action_buffer_start);
            break;
        }
    }

    if (in_try_with_finally) {
        out_script << "\t{" << endl;
        out_script << "\t\tActionVar ret_val;" << endl;
        out_script << "\t\tpopVar(app_context, &ret_val);" << endl;
        out_script << "\t\tactionSetReturnPending(app_context, &ret_val);" << endl;
        out_script << "\t\tgoto label_" << finally_label << ";" << endl;
        out_script << "\t}" << endl;
    } else {
        // Normal return
        out_script << "\t{" << endl;
        out_script << "\t\tActionVar ret_val;" << endl;
        out_script << "\t\tpopVar(app_context, &ret_val);" << endl;
        out_script << "\t\treturn ret_val;" << endl;
        out_script << "\t}" << endl;
    }
    break;
}
```

#### 2. Emit actionCatchEnter at catch boundary

In the boundary handling code (line 222-236), add `actionCatchEnter` before catch-to-variable/register:

```cpp
if (tb.state == 0 && tb.has_catch && action_buffer >= tb.catch_start)
{
    out_script << "\t" << "} else {" << endl;
    out_script << "\t\t" << "// Catch block" << endl;
    out_script << "\t\t" << "actionCatchEnter(app_context);" << endl;  // NEW
    // ... existing catch-to-variable/register code ...
}
```

#### 3. Fix label placement for try-catch-no-finally

When `state == 0 || state == 1` transitions to `state == 3` (end, no finally):
- Emit `}` to close if/else
- Emit `actionTryEnd` BEFORE the label falls
- The generic label code at line 272 will emit the label afterward

Actually, the label is emitted at line 272 based on the bytecode offset. The try body's Jump bytecode targets `after_end` which in bytecode space is the first byte after the construct. The label `label_XX` is emitted when `action_buffer` reaches that offset. Currently `actionTryEnd` is emitted by the boundary handler before the label is reached. Let me re-examine...

Looking at the generated code for `try_catch`:
```c
    }                           // closes if/else (from boundary handler)
    actionTryEnd(app_context);  // from boundary handler at state→3
label_86:                       // from generic label code
    // "End of try_catch()"    // code after try-catch
```

And the try body has `goto label_86`. This means on success, the try body gotos label_86, skipping both the catch body AND `actionTryEnd`. This is the bug — `actionTryEnd` is skipped, depth never decrements.

For try-catch-finally, the goto from the try body goes to the finally label, which is BEFORE `actionTryEnd`. So that case is fine.

**Fix**: For Jump opcodes inside a try body (state==0) when there's no finally block, the Jump target should be at `actionTryEnd`, not after it. We can handle this in the boundary transition: when state changes from 0/1 to 3 (end), if there was a goto that skipped to after_end, we need the label to be BEFORE actionTryEnd.

Simplest fix: emit `actionTryEnd` BEFORE we check for labels at that offset. But the boundary handler runs before the label check... Actually looking at the code flow:

```
while (!try_boundaries.empty()) {
    // boundary transitions emit actionTryEnd here
}
for (const char* ptr : labels) {
    if (action_buffer == ptr) {
        // label emitted here
    }
}
```

Boundaries are checked FIRST, then labels. So `actionTryEnd` is emitted BEFORE `label_XX`. This means the goto from the try body jumps to `label_XX` which is AFTER `actionTryEnd`. This is correct for the catch path but wrong for the try-success path because the goto skips `actionTryEnd`.

**Fix approach**: Don't use the Jump bytecode's label for skipping the catch block. Instead, when we detect that a Jump inside the try body targets `after_end`, redirect it to a new label placed just before `actionTryEnd`:

In the boundary handler, when transitioning to state 3 (end):
```cpp
// Emit a label that the try body's goto can target
out_script << "try_end_" << unique_id << ":" << endl;
out_script << "\t" << "actionTryEnd(app_context);" << endl;
```

And when emitting the Jump opcode, if the target matches `tb.after_end`, emit `goto try_end_XX` instead of `goto label_XX`.

This requires coordination between the Jump emission and the boundary handler. The cleanest way: in the boundary handler, before closing the if/else, check if there's a label at `after_end` in the labels set. If so, remove it from labels and instead emit our own label before `actionTryEnd`.

Alternative (simpler): **Always emit actionTryEnd inside both branches of the if/else** for try-catch-no-finally:

```c
if (ACTION_TRY_SETJMP(app_context) == 0) {
    ...try body...
    actionTryEnd(app_context);  // try success path
    goto label_after;
} else {
    actionCatchToVariable(app_context, "error");
    ...catch body...
    actionTryEnd(app_context);  // catch path
}
label_after:
```

This duplicates `actionTryEnd` but is simple and correct. We can do this by emitting `actionTryEnd` just before the goto in the try body, AND in the boundary handler at the end of the construct. We'd need to suppress the second emit if the first already happened... this gets complicated.

**Cleanest fix**: Change the goto target. When emitting a Jump opcode and the target matches a try boundary's `after_end`:
- For try-catch (no finally): emit `goto` to a synthetic label placed BEFORE `actionTryEnd`
- For try-catch-finally: emit `goto` to the finally label (which is already before `actionTryEnd`)

This can be done by modifying the Jump emission code to check `try_boundaries`.

#### 4. After finally, check pending return

In the boundary handler, when transitioning from state 2 (finally) to state 3 (end):
```cpp
out_script << "\t" << "actionTryEnd(app_context);" << endl;
if (tb.has_finally) {
    out_script << "\t" << "if (actionReturnPending(app_context)) {" << endl;
    out_script << "\t\t" << "return actionGetPendingReturn(app_context);" << endl;
    out_script << "\t" << "}" << endl;
}
```

---

## Risk Assessment

| Risk | Severity | Mitigation |
|------|----------|------------|
| longjmp across function boundaries (throws_error→try_catch_finally) | Medium | This already works — longjmp is valid as long as the setjmp function hasn't returned. The setjmp is in the script function, and the throwing function is called from within it. |
| Stack corruption from longjmp | Low | Only calling longjmp to frames that are still on the C stack — valid per C standard |
| Nested try blocks in different script functions | Medium | Each function has its own setjmp point; the handler stack tracks all active try blocks globally |
| Regressions to passing tests | Medium | Run try_finally_simple, catch_references_registers, uncaught_exception, uncaught_exception_bubbled after changes |
| DefineFunction2 register interaction with catch-to-register | Low | Already works — register arrays are per-function |

---

## Verification

```bash
# After implementation, test all exception-related tests:
python3 ruffle-tests/verify_output.py --test=try_catch_finally --diff --verbose
python3 ruffle-tests/verify_output.py --test=try_finally_simple --diff --verbose
python3 ruffle-tests/verify_output.py --test=catch_references_registers --diff --verbose
python3 ruffle-tests/verify_output.py --test=uncaught_exception --diff --verbose
python3 ruffle-tests/verify_output.py --test=uncaught_exception_bubbled --diff --verbose
```

## Estimated Impact

- **Direct**: 1 test (try_catch_finally: TIMEOUT → PASS)
- **Indirect**: Any future tests that use complex exception patterns will work correctly
- **Regression risk**: 4 tests currently passing that use basic try/catch — must verify no regression
