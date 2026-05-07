# try_catch_stack Plan
<!-- TESTS: try_catch_stack -->

<!-- PLAN_META
id: TRY_CATCH_STACK
status: pending
phases:
  - id: 1
    name: "Reproduce locally and confirm diff"
    status: pending
  - id: 2
    name: "Save SP at actionTryBegin, restore at actionCatchEnter"
    status: pending
  - id: 3
    name: "Regression battery (all try/catch + exception tests)"
    status: pending
dependencies: []
blockers: []
-->

Last updated: 2026-05-06.

## Status: PENDING — 14/16 (filtered fail)

First observed in CI at `ad31c865` (2026-05-06). The single new filtered
failure on AVM1 once the `assetnativeaccessor*` tests landed.

## Symptom

```
expected:                                actual:
Caught error                             Caught error
The stack was not preserved!             The stack was preserved!     ← diff
Outside catch block:                     Outside catch block:
The stack was not preserved!             The stack was preserved!     ← diff

--- and again without throwing ---       --- and again without throwing ---

Outside catch block:                     Outside catch block:
The stack was preserved!                 The stack was preserved!

--- and now in reverse ---               --- and now in reverse ---

Caught error                             Caught error
2                                        2
Outside catch block:                     Outside catch block:
2                                        2
```

Two diff lines (lines 2 and 4 of the expected output). Lines 8, 12, 14, 16
match — those are the *non*-throwing paths or the "in reverse" path that
checks a known-popped value, so the test isolates the stack-preservation
behaviour to specifically the `throw → catch` transition.

The test does roughly (reverse-engineered from the trace, not the SWF):

```as
// Throw section
push("preserved!");
try {
  push("not preserved!");
  throw new Error();
} catch (e) {
  trace("Caught error");
  trace("The stack was " + pop());   // line 2
}
trace("Outside catch block:");
trace("The stack was " + pop());     // line 4

// Non-throw section — fall through; stack must be preserved
push("preserved!");
try { /* no throw */ } catch (e) {}
trace("Outside catch block:");
trace("The stack was " + pop());     // line 8

// Reverse section — push a counter inside try, throw with stack non-empty
// of integer values; after catch the integer should NOT survive (stack cleared),
// but a value pushed *outside* the try should still be on top.
push(2);
try { push(99); throw new Error(); } catch (e) { trace("Caught error"); trace(pop()); }
trace("Outside catch block:");
trace(pop());                          // line 16: prints 2 (the outer value)
```

The Flash semantics being asserted: **on entry to the catch block the value
stack is restored to the depth it had at the matching `Try` instruction**.
Anything the try body pushed before throwing is discarded. Items pushed
*outside* the try block (i.e. before `Try`) survive. If the try block
completes normally and falls through past the catch, nothing is unwound.

## Root cause

`actionTryBegin` (`SWFModernRuntime/src/actionmodern/action.c:48726`)
records the scope-depth at try entry but not the stack pointer. On
`actionThrow → longjmp` the C stack unwinds, but `app_context->sp` (the
ActionScript value-stack pointer, see `swf.h:214`) is unaffected, so any
intermediate pushes done inside the try body before the throw are still
present when the catch body starts running.

Flash and Ruffle both clear those pushes. Ruffle does it via the
`Activation::with_value_stack` save/restore around the try body in
`avm1/runtime.rs::Activation::run_actions`; the stack gets a snapshot
before the try executes and is rolled back at catch entry.

The recompiler already emits the call site we need
(`SWFRecomp/src/action/action.cpp:295`):

```cpp
out_script << "\t\t" << "actionCatchEnter(app_context);" << endl;
```

`actionCatchEnter` (`action.c:48745`) currently does:

```c
void actionCatchEnter(SWFAppContext* app_context)
{
    int idx = g_exception_state.depth - 1;
    if (idx >= 0) {
        g_exception_state.frames[idx].has_jmp_buf = 0;
        scope_depth = g_exception_state.frames[idx].saved_scope_depth;
    }
}
```

We need to also restore SP (and OLDSP) here, using a value snapshotted in
`actionTryBegin`.

## Plan

### Phase 1 — Reproduce locally

Test directory isn't on disk in the local sparse checkout; pull it:

```bash
bash ruffle-tests/download_tests.sh avm1
python3 ruffle-tests/verify_output.py --test=try_catch_stack --diff --verbose
```

Confirm the 2-line diff matches the CI-recorded failure. Capture
`output.txt` and the recompiled `RecompiledScripts/script_*.c` so we can
see the exact `Push`/`Throw`/`actionTryBegin`/`actionCatchEnter` sequence
the test produces.

### Phase 2 — Save and restore SP across try/catch

1. Add `u32 saved_sp;` (and, if needed, `u32 saved_oldsp;`) to
   `ExceptionFrame` in `action.c:381`.
2. In `actionTryBegin` (`action.c:48726`), record:
   ```c
   g_exception_state.frames[g_exception_state.depth].saved_sp = app_context->sp;
   ```
3. In `actionCatchEnter` (`action.c:48745`), restore:
   ```c
   app_context->sp = g_exception_state.frames[idx].saved_sp;
   ```
   (Place it next to the existing `scope_depth` restore — same justification:
   `longjmp` doesn't touch C globals or context fields, and a throw mid-try
   leaves SP at whatever the try body had pushed.)

   The fall-through-no-throw path *must not* touch SP — the try body's
   pushes are part of normal program state when no exception fired.
   `actionCatchEnter` is only called on the throw path (the recompiler
   emits it inside the `else` branch of the `if (ACTION_TRY_SETJMP …)`
   conditional, see `action.cpp:293-296`), so this is naturally
   restricted.

4. Audit `actionTryEnd` (`action.c:48797`) — no SP work needed there
   because either (a) try ran to completion and fall-through SP is the
   live one, or (b) the catch ran and already restored SP. But check
   the `try-catch-finally` and `finally` paths: when a throw is
   re-raised after a finally, SP should already be the catch-entry SP
   (Flash discards the try body's pushes once and only once).

### Phase 3 — Regression battery

Run the existing try/catch tests — they're the entire feature surface and
will catch any over-eager unwind:

- `try_catch_finally` (118/118 — covers nested try, throw inside catch,
  finally semantics)
- `try_finally_simple` (no catch path, fall-through must keep SP)
- `displacementmapfilter_mappoint_throw_error` (13/13 — valueOf throws
  through the bytecode-level setjmp)
- `loadvars_tostring` ("Caught: some error" path — getter throws
  inside `for (var k in lv)`)
- `infinite_recursion_function_in_setter` (depth-bounded throw)
- Gnash actionscript.all `Error.as` / `Object-v8` battery (throws via
  user code) — confirm no regressions

Plus the AVM1 numeric/string regression tests that already exercise
`Push`/`Pop` heavily (`array_constructor`, `arithmetic_swf6`, ...) — none
of these use try/catch but they would fail on any pointer-arithmetic
mistake in the SP save/restore.

## Risk

**Low.** The change is local to `actionTryBegin` + `actionCatchEnter` and
only fires on the throw path. The non-throw path is byte-for-byte unchanged.
The main risk is missing the `try-finally-without-catch` case (no
`actionCatchEnter` is emitted there), but that case doesn't observably
*restore* SP either — it just falls through with SP intact, which is the
correct behaviour both for try-finally and try-catch-no-throw.

## Why this is the right shape

This is a one-field-on-the-struct, two-line-per-callsite change. The plan
has the symptom, the exact file/line points where the runtime needs to
change, the recompiler call site that's already in place, and a regression
battery that covers the feature surface. There's no architectural rework
hiding here — Flash's behaviour is well-defined ("clear the value stack on
catch entry"), Ruffle's matches it, and our code already snapshots
`scope_depth` in the same struct for the same reason.

## Related docs

- `complete/TRY_CATCH_PLAN.md` — original try-catch-finally implementation
- `complete/TRY_FINALLY_PLAN.md` — Gnash try-finally fix
- `RUFFLE_VS_FLASH_DIFFERENCES.md` — not yet referenced; this is a Flash-Ruffle agreement, so no entry here.
