# Graphics vs Trace Mode Differences

Trace: 0/20 passing | Graphics: 19/20 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (19 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `afunc_dict` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 2 | `background` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 3 | `dict_callframe` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 4 | `dict_cross` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 5 | `dict_event` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 6 | `dict_override` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 7 | `func_dict` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 8 | `initaction_in_definesprite` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 9 | `jump_after_end` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 10 | `jump_to_prev_block` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 11 | `missing_bitmap` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 12 | `mixed-bytecode-as2` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 13 | `registers` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 14 | `tags_after_last_showframe` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 15 | `trace-as2/arguments` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 16 | `trace-as2/root_onload` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 17 | `trace-as2/shortstack` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 18 | `trace-as2/super` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 19 | `trace-as2/this` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
