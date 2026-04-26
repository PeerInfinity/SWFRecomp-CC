# Drain-Suppress Primitive Plan

<!-- TESTS: (none — behavior-neutral primitive, validated via no-regression CI run) -->

<!-- PLAN_META
id: DRAIN_SUPPRESS_PRIMITIVE
status: pending
phases:
  - id: 1
    name: "Add g_drain_suppress_depth counter + accessors in action_queue.c/.h"
    status: pending
  - id: 2
    name: "Make actionDrainOnloadAndScript early-return when depth > 0"
    status: pending
  - id: 3
    name: "Debug assert: depth == 0 at tick boundaries (start of frame loop iteration)"
    status: pending
  - id: 4
    name: "CI no-regression check"
    status: pending
related:
  - "GOTO_FIFO_UNIFICATION_PLAN.md (blocked/) — Path B will set the depth around ng_executeGotoCatchUp's inline funcs[target] call"
-->

## Why

`GOTO_FIFO_UNIFICATION_PLAN.md` Phase 2 wants `ng_executeGotoCatchUp` to run
`funcs[target]` inline so the target frame's root DoAction queues into
`AQ_KIND_SCRIPT`. But `funcs[target]` ends with a recompiler-emitted call to
`actionDrainOnloadAndScript`, which would fire a **nested drain** from inside
the outer drain that's already running the calling script. That nested drain
pulls already-queued sprite scripts (e.g., `script_3` in
`consecutive_goto_frame_test`) ahead of their FIFO position and breaks the
interleave the unification is trying to produce.

We need a queue-only mode: queue calls run as normal, drain calls become
no-ops, and the outer drain naturally picks up the new entries when control
returns to it.

## Design

### Counter, not flag

A depth counter (`g_drain_suppress_depth`, int). `Enter()` increments,
`Leave()` decrements. Drain functions early-return when `> 0`.

Reason: Phase B's `ng_executeGotoCatchUp` is reentrant — a goto from inside
the target script triggers another `ng_executeGotoCatchUp`, which would
re-enter the suppress region. With a flag, the inner `Leave` clears
suppression for the outer; with a counter, only the outermost `Leave` clears
it. Counter is the right shape.

### Name and scope

- File: `SWFModernRuntime/src/actionmodern/action_queue.c` /
  `SWFModernRuntime/include/actionmodern/action_queue.h`. Lives next to the
  drain functions it gates.
- API:
  - `void actionDrainSuppressEnter(void);`
  - `void actionDrainSuppressLeave(void);`
  - `int actionDrainSuppressed(void);` (read-only, for assertions / future use)
- Internal: `static int g_drain_suppress_depth = 0;` — file-local, only
  touched via the three accessors.

### Contract — which drain functions suppress

**Suppressed:** `actionDrainOnloadAndScript`. This is the recompiler-emitted
SHOW_FRAME drain (`tagMain.c`'s `actionDrainOnloadAndScript(app_context)`)
and the only one that fires reentrantly from inside another drain in the
goto path.

**Not suppressed:** `actionDrainActionQueue`, `actionDrainActionQueueFiltered`,
`actionDrainActionQueueByKind`. These have other callers
(SCRIPT-only drain at line 914 of `swf_core.c`, the Phase 7b orphaned-script
fallback) that should keep firing. If a future phase needs them gated too,
extend the contract explicitly.

### Invariant

`g_drain_suppress_depth == 0` at every tick boundary. Add a check inside the
main frame loop in `swf_core.c` (e.g. at the top of the per-tick `for(;;)`
body, alongside the existing `actionFinalizePendingRemovals` etc.):

```c
#ifndef NDEBUG
    if (actionDrainSuppressed()) {
        fprintf(stderr, "drain suppress depth leaked: %d\n",
                actionDrainSuppressed());
        abort();
    }
#endif
```

Cheap, catches Enter/Leave mismatches at the next tick instead of letting
them silently corrupt later behavior.

## Implementation order

1. Header declaration (3 lines) + `.c` definitions (depth + 3 accessors,
   ~10 lines).
2. Single-line guard at top of `actionDrainOnloadAndScript`:
   `if (g_drain_suppress_depth > 0) return;`.
3. Tick-boundary assert in `swf_core.c` (and `swf_headless.c` mirror).
4. Build, push, CI. **Expected:** zero behavioral change. All suite numbers
   identical to current baseline.

## Risk

Near zero. No call site sets the depth in this commit, so the early-return
branch is dead code. The only ways to regress: typo in the accessor, or the
assert firing spuriously (which would indicate a pre-existing bug, not a
regression from this change).

## When this primitive gets used

`GOTO_FIFO_UNIFICATION_PLAN.md` Phase B (next session). The pattern there:

```c
actionDrainSuppressEnter();
g_tag_skip_mode = 1;
funcs[target](app_context);
g_tag_skip_mode = 0;
actionDrainSuppressLeave();
```

so the queue calls inside `funcs[target]` run but the drain calls don't,
leaving the outer drain to dispatch in FIFO order.
