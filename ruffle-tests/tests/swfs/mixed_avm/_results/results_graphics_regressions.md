# Graphics vs Trace Mode Differences

Trace: 4/11 passing | Graphics: 0/11 passing

## Graphics Regressions (4 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `avm1_doabc` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 2 | `avm1_loads_avm2_doaction` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 3 | `avm1_sprite_sc_ignored` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 4 | `avm2_doaction` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
