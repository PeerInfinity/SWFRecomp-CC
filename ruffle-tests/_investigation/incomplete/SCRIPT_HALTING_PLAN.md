# Script Halting on Clip Removal Plan
<!-- TESTS: removed_clip_halts_script, target_clip_removed -->

Last updated: 2026-03-06

## Status: ACTIONABLE — not blocked (but architecturally challenging)

### Overview

When a MovieClip removes itself (or is removed by another clip) during script execution, Flash halts the remainder of the script that was executing on/for that clip. Our runtime continues executing all remaining actions, producing "BAD" output that should never appear.

**Tests**:
- `removed_clip_halts_script` — 1/15 (7%). Clips trace "BAD" after being removed because their scripts continue.
- `target_clip_removed` — 4/5 (80%). One line where GetVariable should see a variable but doesn't (execution order issue).

### Observed Failures (removed_clip_halts_script)

The test creates clips that call `removeMovieClip(this)` (or equivalent), then have trace statements after the removal. Expected behavior: the trace after removal never executes.

```
Expected:          Actual:
clip 1             clip 1
clip 2             clip 1 BAD     <- should have halted
clip 3             clip 1         <- re-execution?
clip 4             clip 1 BAD
done               clip 2
clip 5             clip 2 BAD
clip 5 OK          clip 4
...                clip 4 BAD
                   done
                   ...
```

Two distinct issues:
1. **Script continues after removeMovieClip**: Actions after `removeMovieClip()` still execute
2. **Clip re-execution**: Some clips appear to execute their script twice (clips 1-4 each produce two lines)

### Flash Semantics

In Flash Player, `removeMovieClip()` during a script's execution causes:
1. The clip is marked for removal
2. The **current script** (the one executing on that clip) terminates immediately
3. Other scripts already queued continue normally
4. The removal takes effect at end of frame

This is similar to `call()` early termination (Blocker 8) but broader — it applies to `removeMovieClip`, `unloadMovie`, and timeline removal during catch-up.

### Implementation Approach

**Phase 1: removeMovieClip halts current script** (~20 lines)

Add a "halt requested" flag that the generated script code can check:

Option A — `setjmp`/`longjmp` approach:
```c
// In each generated script:
if (setjmp(g_script_abort_jmp) != 0) return;  // already emitted by recompiler

// In removeMovieClip, when removing the currently executing MC:
if (mc == g_current_context || mc == g_base_clip) {
    longjmp(g_script_abort_jmp, 1);
}
```

The recompiler already includes `<setjmp.h>` in generated scripts. However, longjmp across C function boundaries with non-trivial stack state is dangerous.

Option B — Flag-based early return:
```c
// Global flag
static int g_script_halted = 0;

// In removeMovieClip:
if (mc == g_current_context || mc == g_base_clip)
    g_script_halted = 1;

// After each action in generated code, check flag:
actionRemoveMovieClip(app_context);
if (g_script_halted) { g_script_halted = 0; return; }
```

This requires the **recompiler** to emit halt checks after `removeMovieClip` calls (and potentially after any action that could trigger removal).

Option C — Return value approach:
```c
// removeMovieClip returns 1 if current script should halt
if (actionRemoveMovieClip(app_context)) return;
```

**Recommendation**: Option C is simplest but requires recompiler changes. Option B is more general but adds overhead to every action. Option A is dangerous with our stack-based runtime.

**Phase 2: Identify removal trigger points**

Not just `removeMovieClip()` — also:
- `unloadMovie()` / `unloadMovieNum()` on self
- Timeline `RemoveObject2` during `gotoAndStop`/`gotoAndPlay` catch-up
- `swapDepths` to negative depth + removal

Each of these needs to set the halt flag if the removed MC is the current execution context.

**Phase 3: Prevent re-execution**

The diff shows clips executing twice. This may be because:
- The clip's script is queued for multiple frames
- The removal doesn't prevent the already-queued script from running again
- Need to check `pending_removal` or `depth == INT_MIN` before dispatching a clip's frame script

### Expected Outcome

| Phase | Lines Gained | Test Result |
|-------|-------------|-------------|
| Phase 1 | +8 | removed_clip_halts_script ~9/15 |
| Phase 2 | +3 | ~12/15 |
| Phase 3 | +3 | ~15/15 |
| target_clip_removed | +1 | 5/5 (separate investigation) |

### Dependencies

- Requires recompiler changes (emit halt checks) for the cleanest solution
- Related to MC_REMOVAL_LIFECYCLE_PLAN (Phase 4, removed_target_clip_scope) and CALL_SEMANTICS_PLAN (call() early termination)
- Does NOT block or require loadMovie infrastructure

### Risks

- `longjmp` across action function boundaries may corrupt stack state
- Flag-based approach adds overhead to hot paths (every action checks flag)
- Need to ensure halt only affects the script running on the removed clip, not parent scripts
- `removeMovieClip` is called from ActionScript — the MC doing the removal might be different from the MC being removed. Only halt if `g_current_context` (or `g_base_clip`) is the removed MC.
