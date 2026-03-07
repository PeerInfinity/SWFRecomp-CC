# Custom Clip Methods Plan
<!-- TESTS: custom_clip_methods -->

Last updated: 2026-03-06

## Status: ACTIONABLE — needs investigation

### Overview

The test defines custom methods (`global_function`, `tracealike`, `fancy_stop`) on the root timeline via `DefineFunction` and then calls them as methods on `this` (the root MC). The root frame 0 script (script_3) should execute first, but instead we see frame 2 and 3 output, suggesting script_3 isn't running or the frame execution order is wrong.

**Test**: `custom_clip_methods` — 0/4 (0%).

### Expected vs Actual

```
Expected:                                          Actual:
1. global function call                            1. timeline frame 2
2. tracealike: I was called as a method!           2. child stopped via child_function
3. tracealike: I was called by the child movie!    3. timeline frame 3
4. child stopped via child_function                4. <end>
```

### Script Structure

From the recompiled code:
- **script_0** (child frame 0): `DefineFunction("child_function", ...)` — defines a function on child
- **script_1** (child frame 1): Calls `_root.tracealike("I was called by the child movie clip!")`
- **script_2** (child frame 2): Calls `this.child_function()`, then `stop()`
- **script_3** (root frame 0): Defines `global_function`, `tracealike`, `fancy_stop`. Then calls:
  - `this.global_function()` → traces "global function call"
  - `this.tracealike("I was called as a method!")` → traces "tracealike: I was called as a method!"
  - `this.fancy_stop()` → calls `this.stop()`
- **script_4** (root frame 2): Traces "timeline frame 2", calls `this.childinst.child_function()`
- **script_5** (root frame 3): Traces "timeline frame 3", `stop()`

### Investigation Needed

**Phase 0: Check tagMain.c frame mapping**

The test runs for `num_frames` ticks. We need to check:
1. Is script_3 assigned to root frame 0 in tagMain.c?
2. What is the num_frames value in test.toml?
3. Is `fancy_stop()` calling `this.stop()` successfully (stopping the root timeline at frame 0)?

If `fancy_stop()` fails to stop the root, the timeline advances to frames 2 and 3 without ever executing frame 0's script. But the output shows frame 2 and 3 traces, which means script_3 either:
- Didn't run at all (frame mapping issue)
- Ran but `global_function()`/`tracealike()` calls failed silently
- `fancy_stop()` didn't actually stop, so frame 0 was skipped on rewind

**Phase 1: Fix frame execution**

Based on Phase 0 findings:
- If script_3 isn't mapped to frame 0: fix tagMain.c generation
- If methods aren't being found: fix `this.method()` dispatch for root-timeline-defined functions
- If stop() isn't working via `fancy_stop()`: fix the `this.stop()` call path inside a user function

**Phase 2: Child method calls**

script_1 calls `_root.tracealike(...)` which should resolve `tracealike` as a method on root MC. This works via `actionCallMethod` with a MOVIECLIP receiver. Ensure user-defined functions stored on root are found when called as methods.

### Expected Outcome

| Phase | Lines Gained | Test Result |
|-------|-------------|-------------|
| Phase 0 | 0 (diagnostic) | 0/4 |
| Phase 1 | +3-4 | 3-4/4 |
| Phase 2 | +0-1 | 4/4 |

### Dependencies

None — no loadMovie, no MTASC, no special infrastructure needed.

### Risks

- The root cause might be a recompiler issue (wrong frame assignment) rather than a runtime issue
- Could overlap with `this_scoping` fixes (already passing) — verify no regression
