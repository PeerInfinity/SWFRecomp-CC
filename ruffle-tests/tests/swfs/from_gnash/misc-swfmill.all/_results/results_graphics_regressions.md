# Graphics vs Trace Mode Differences

Trace: 19/20 passing | Graphics: 0/20 passing

## Graphics Regressions (19 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `afunc_dict` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 2 | `background` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 3 | `dict_callframe` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 4 | `dict_cross` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 5 | `dict_event` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 6 | `dict_override` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 7 | `func_dict` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 8 | `initaction_in_definesprite` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 9 | `jump_after_end` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 10 | `jump_to_prev_block` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 11 | `missing_bitmap` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 12 | `mixed-bytecode-as2` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 13 | `registers` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 14 | `tags_after_last_showframe` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 15 | `trace-as2/arguments` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 16 | `trace-as2/root_onload` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 17 | `trace-as2/shortstack` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 18 | `trace-as2/super` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 19 | `trace-as2/this` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
