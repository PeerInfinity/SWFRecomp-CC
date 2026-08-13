# Graphics vs Trace Mode Differences

Trace: 3/5 passing | Graphics: 0/5 passing

## Graphics Regressions (3 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `g711_event_alaw` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 2 | `g711_event_mulaw` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 3 | `stream_incomplete_loop` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
