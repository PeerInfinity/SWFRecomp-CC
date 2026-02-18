# Timer / setInterval Implementation Plan
<!-- TESTS: set_interval, timer_run_actions, timeout -->

Last updated: 2026-02-15

## Overview

Three Ruffle tests need timer support: `set_interval` (0/27), `timer_run_actions` (0/18), and `timeout` (TIMEOUT). This requires implementing `setInterval()`, `setTimeout()`, and `clearInterval()` as global built-in functions in the runtime, plus a timer scheduling engine integrated into the frame loop.

**Current state**: No timer support exists. `setInterval`/`setTimeout`/`clearInterval` are called via `actionCallFunction` bytecode, which looks them up as regular function names. Since they're not registered, the lookup returns NULL and `undefined` is pushed. No timer callbacks ever fire.

## Test Analysis

### `set_interval` (num_frames=40, FRAME_RATE=10)

The test registers 11 valid timers and 5 invalid cases (which should return `undefined`), then a cleanup timeout. Expected output is 27 lines:
- Lines 1-17: Registration traces with returned timer IDs (1-13 sequentially)
- Lines 18-26: Timer callbacks firing in delay order across frames
- Line 27: Cleanup function clears all intervals

**Calling conventions exercised:**
1. `setInterval(func, delay)` — function + delay (2 args)
2. `setInterval(func, delay, arg1, arg2)` — function + delay + extra args
3. `setTimeout(func, delay)` — one-shot timer
4. `setTimeout(func, delay, arg1)` — one-shot with extra args
5. `setInterval(func, valueOfObj, arg)` — delay from object with valueOf
6. `setTimeout(func, null)` — null delay (coerced to 0)
7. `setInterval(obj, 'methodName', delay)` — method on object (3+ args, first arg is object, second is string)
8. `setTimeout(obj, methodVar, delay)` — method name from variable

**Validation cases (all return `undefined`):**
- `setInterval(func, undefined)` — undefined delay
- `setInterval(undefined, 10)` — undefined function
- `setInterval()` — no arguments
- `setInterval('', 100)` — empty string as function
- `setInterval(obj, 'method', undefined)` — undefined delay in method form

### `timer_run_actions` (num_frames=1, FRAME_RATE=10)

Registers `setInterval(fn, 1)` (1ms interval). The callback function:
- Call 0: calls `attachMovie`, traces initial state
- Calls 1-7: traces tick number and `_x` value (100, set by onLoad)
- Call 8: calls `clearInterval` to stop

Expected: 18 lines of output within a single frame. This means **multiple timer fires per frame** when the interval is shorter than the frame duration. With FRAME_RATE=10 (100ms/frame), a 1ms timer can fire many times per frame.

### `timeout` (num_frames=1, TIMEOUT status)

Contains an infinite loop (`while(false){} goto loop`). Expected output: empty (0 lines). This tests script execution timeout — currently the runtime hangs forever. **This test requires a script timeout mechanism**, which is a separate feature from timers. We can defer this test.

## Architecture Design

### Timer Data Structure

```c
#define MAX_TIMERS 64

typedef struct {
    int active;                // 0 = empty slot, 1 = active
    int id;                    // sequential ID (1, 2, 3, ...)
    int is_interval;           // 1 = repeating (setInterval), 0 = one-shot (setTimeout)
    double delay_ms;           // delay in milliseconds
    double elapsed_ms;         // accumulated time since last fire (or since creation)

    // Callback — either function-form or method-form
    int is_method;             // 0 = function, 1 = method on object
    ActionVar func;            // function reference (function-form)
    ActionVar object;          // object reference (method-form)
    char method_name[256];     // method name string (method-form)

    // Extra arguments passed to callback
    ActionVar* extra_args;     // heap-allocated array of extra args
    int extra_arg_count;
} TimerEntry;

static TimerEntry g_timers[MAX_TIMERS];
static int g_next_timer_id = 1;
```

### Dispatch Point: `actionCallFunction`

`setInterval`, `setTimeout`, and `clearInterval` are called via `actionCallFunction` (not via `_global` property lookup). They need to be added to the built-in function dispatch chain alongside `parseInt`, `parseFloat`, `isNaN`, `isFinite`, etc.

In `action.c` `actionCallFunction()`, add cases after the existing built-in checks:

```c
// setInterval(func, delay, ...args) or setInterval(obj, methodName, delay, ...args)
if (func_name_len == 11 && strncmp(func_name, "setInterval", 11) == 0)
{
    actionSetInterval(app_context, args, num_args, 1); // 1 = repeating
    builtin_handled = 1;
}
else if (func_name_len == 10 && strncmp(func_name, "setTimeout", 10) == 0)
{
    actionSetInterval(app_context, args, num_args, 0); // 0 = one-shot
    builtin_handled = 1;
}
else if (func_name_len == 13 && strncmp(func_name, "clearInterval", 13) == 0)
{
    actionClearInterval(app_context, args, num_args);
    builtin_handled = 1;
}
```

### Timer Registration Logic

**Two calling conventions** — distinguished by checking if arg[1] is a string:

1. **Function-form**: `setInterval(func, delay, ...extraArgs)`
   - args[0] = function, args[1] = delay (number), args[2..] = extra args
   - Validate: args[0] must be a function, delay must not be undefined/NaN

2. **Method-form**: `setInterval(obj, methodName, delay, ...extraArgs)`
   - args[0] = object, args[1] = string (method name), args[2] = delay, args[3..] = extra args
   - Validate: args[0] must be an object/movieclip, args[1] must be a non-null string, delay must not be undefined/NaN

**Validation rules** (return `undefined` for invalid):
- 0 args → undefined
- Function-form: args[0] not callable (undefined, null, empty string) → undefined
- Function-form: args[1] undefined → undefined (NaN delay → undefined)
- Method-form: args[2] undefined → undefined
- null delay → coerce to 0 (valid, fires immediately)
- Object with valueOf → coerce delay via valueOf

**Return value**: Sequential integer ID (1, 2, 3, ...). Both setInterval and setTimeout share the same ID space. `clearInterval` works on both.

### Timer Execution Engine

Timers fire as part of the frame loop. After each frame's actions run, check all active timers:

```c
void processTimers(SWFAppContext* app_context, double frame_duration_ms)
{
    // Advance all timers by frame_duration_ms
    for (int i = 0; i < MAX_TIMERS; i++) {
        if (!g_timers[i].active) continue;
        g_timers[i].elapsed_ms += frame_duration_ms;
    }

    // Fire eligible timers (may fire multiple times per frame if delay is short)
    int fired_any;
    do {
        fired_any = 0;
        // Find the timer with the smallest next-fire time that is ready
        // When multiple timers fire at the same elapsed time, fire lowest ID first
        for (int i = 0; i < MAX_TIMERS; i++) {
            if (!g_timers[i].active) continue;
            if (g_timers[i].elapsed_ms < g_timers[i].delay_ms) continue;

            // Fire this timer's callback
            fireTimerCallback(app_context, &g_timers[i]);
            fired_any = 1;

            if (g_timers[i].is_interval) {
                // Repeating: subtract one delay period
                g_timers[i].elapsed_ms -= g_timers[i].delay_ms;
            } else {
                // One-shot: deactivate
                g_timers[i].active = 0;
                freeTimerArgs(&g_timers[i]);
            }
            break; // Re-scan from beginning (firing order may change)
        }
    } while (fired_any);
}
```

**Key behaviors:**
- Timers fire in ID order when they have the same elapsed time
- A repeating timer can fire multiple times per frame if `delay << frame_duration`
- Timer callbacks can call `clearInterval` to cancel other timers (or themselves)
- Fired one-shot timers are automatically deactivated

### Timer Callback Invocation

When firing a timer callback:

**Function-form:**
```c
// Call func(extra_args[0], extra_args[1], ...)
// Similar to actionCallFunction but with pre-resolved function and args
```

**Method-form:**
```c
// Look up method on object: obj.method_name
// Call it with this=obj, args=extra_args
// If method doesn't exist, silently skip (no error)
```

The callback must be invoked using the existing function call infrastructure (`callASFunction` or equivalent). Extra args from setInterval are passed as the function's arguments.

### Integration with Frame Loop

In `swf_core.c` `swfStart()`, add timer processing after each frame function runs:

```c
while (!quit_swf && tick_count < max_ticks)
{
    tick_count++;
    // ... existing frame execution code ...

    // Process timers after frame actions
    double frame_duration_ms = 1000.0 / FRAME_RATE;
    processTimers(app_context, frame_duration_ms);

    // ... existing frame advance code ...
}
```

The `FRAME_RATE` macro is already emitted by the recompiler into `out.h` (e.g., `#define FRAME_RATE 10`). The runtime can use it to calculate `frame_duration_ms = 1000.0 / FRAME_RATE`.

### Timeline Looping Prerequisite

The `set_interval` test has `SWF_FRAME_COUNT 1` but `num_frames=40`. Currently, after frame 0 runs, `current_frame++` goes to 1 which is `>= g_frame_count`, and the loop breaks.

In Flash Player, 1-frame movies loop: after the last frame, the timeline wraps to frame 0. The frame loop needs to handle this:

```c
if (is_playing) {
    current_frame++;
    if (current_frame >= g_frame_count) {
        current_frame = 0; // Loop back
    }
}
```

However, `frame_0` in the set_interval test sets `quit_swf = 1` after `tagShowFrame`. This is because the recompiler generates `quit_swf = 1` after the last `ShowFrame` tag (representing the SWF `End` tag).

**Solution**: For timer support, `quit_swf = 1` from the End tag should NOT prevent timer processing. Options:
1. Process timers even after `quit_swf` is set (as long as `tick_count < max_ticks`)
2. Don't set `quit_swf` for looping SWFs
3. Continue running the frame loop for timer processing after quit_swf, but skip re-running frame functions

Option 3 is cleanest: after `quit_swf = 1`, the frame loop continues ticking for timer purposes but doesn't re-execute frame functions. This matches Flash behavior where timers outlive the timeline.

```c
while (tick_count < max_ticks)
{
    tick_count++;

    if (!quit_swf) {
        // Normal frame execution
        // ... existing code ...
    }

    // Timer processing always runs (even after quit_swf)
    double frame_duration_ms = 1000.0 / FRAME_RATE;
    processTimers(app_context, frame_duration_ms);

    if (quit_swf && !hasActiveTimers()) break;
}
```

---

## Implementation Phases

### Phase 1: Timer Data Structures and Registration

**Goal**: `setInterval`/`setTimeout` return correct IDs; invalid calls return `undefined`.

Changes:
- Add `TimerEntry` struct and `g_timers[]` array to `action.c`
- Add `actionSetInterval()` and `actionClearInterval()` functions
- Add dispatch cases in `actionCallFunction()` for "setInterval", "setTimeout", "clearInterval"
- Implement argument validation and two-form detection (function vs method)
- Store timer callbacks and extra args

**Tests fixed**: Lines 1-17 of `set_interval` (all IDs correctly returned, including `undefined` for invalid cases).

**Verification**:
```bash
python3 ruffle-tests/verify_output.py --test=set_interval --diff --verbose
```

### Phase 2: Timer Execution Engine

**Goal**: Timer callbacks actually fire at the correct times.

Changes:
- Add `processTimers()` function with multi-fire-per-frame support
- Add `fireTimerCallback()` — invokes function or method with extra args
- Integrate `processTimers()` into `swfStart()` frame loop
- Handle `FRAME_RATE` macro for timing calculations
- Handle timeline continuation after `quit_swf` for timer processing

**Tests fixed**: Lines 18-27 of `set_interval` (timer callbacks fire in correct order).

**Verification**:
```bash
python3 ruffle-tests/verify_output.py --test=set_interval --diff --verbose
```

### Phase 3: Timer + Display List Interaction

**Goal**: Pass `timer_run_actions` — timers interacting with `attachMovie` and `onLoad`.

This test uses `setInterval(fn, 1)` which fires rapidly. The callback calls `attachMovie` on tick 0, which triggers `onLoad` on the attached clip. Subsequent ticks read the clip's `_x` property.

Changes:
- Ensure timer callbacks can call `attachMovie` and other display-list-modifying functions
- Ensure `onLoad` fires at the right time (after attachMovie, before next timer tick)
- Handle `clearInterval` from within a timer callback (self-clearing)

**Verification**:
```bash
python3 ruffle-tests/verify_output.py --test=timer_run_actions --diff --verbose
```

### Phase 4 (Deferred): Script Execution Timeout

**Goal**: Pass the `timeout` test.

The `timeout` test has an infinite loop and expects the runtime to abort execution after a time limit. This requires:
- A watchdog mechanism (instruction counter or wall-clock check) in the frame loop
- Ability to abort script execution mid-function and continue to the next frame

This is a separate, more complex feature. The `timeout` test can remain as a known failure.

---

## Files to Modify

### Runtime (SWFModernRuntime/)

| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | Timer data structures, `actionSetInterval()`, `actionClearInterval()`, `fireTimerCallback()`, dispatch in `actionCallFunction()` |
| `include/actionmodern/action.h` | Declare `processTimers()` (called from swf_core.c) |
| `src/libswf/swf_core.c` | Call `processTimers()` in frame loop, handle post-quit timer ticking |

### No recompiler changes needed

`setInterval`/`setTimeout`/`clearInterval` are called via `actionCallFunction` with string names. The recompiler already correctly generates these calls. No changes to `SWFRecomp/` are needed.

---

## Design Decisions

1. **Timer storage**: Static array `g_timers[MAX_TIMERS]` (64 slots). Flash rarely has more than a handful of concurrent timers. Linear scan is fine for small N.

2. **ID allocation**: Simple incrementing counter `g_next_timer_id`. Flash's timer IDs are sequential integers starting from 1. IDs are never reused within a session.

3. **Timing model**: Virtual time, advanced by `1000.0/FRAME_RATE` ms per frame tick. No wall-clock dependency. This matches Ruffle's deterministic test model.

4. **Multi-fire per frame**: When `delay < frame_duration`, the timer fires `floor(elapsed/delay)` times per frame. Essential for `timer_run_actions` where `setInterval(fn, 1)` fires ~100 times per 100ms frame.

5. **Extra args storage**: Heap-allocated `ActionVar` array, deep-copied at registration time. Freed when timer is cleared or (for setTimeout) after firing.

6. **Method resolution**: For method-form timers, the method is looked up on the object at **fire time**, not registration time. This matches Flash behavior where the method can change between fires.

7. **Callback invocation**: Use the same infrastructure as `actionCallFunction` — push args, call function, pop result. This ensures proper scope chain, `this` binding, and register handling.

## Estimated Impact

| Phase | Tests Fixed | Notes |
|-------|-----------|-------|
| 1 | ~0 (partial set_interval) | IDs correct but no callbacks fire yet |
| 2 | 1 (set_interval) | Full timer execution |
| 3 | 1 (timer_run_actions) | Timer + display list interaction |
| 4 | 1 (timeout) | Deferred — needs script timeout mechanism |
| **Total** | **2-3 tests** | Plus unblocks other tests that use timers |

Timer support may also partially fix other tests that use `setInterval` for animation or polling patterns.
