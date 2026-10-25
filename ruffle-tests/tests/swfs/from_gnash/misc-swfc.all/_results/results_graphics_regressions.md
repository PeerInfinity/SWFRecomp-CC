# Graphics vs Trace Mode Differences

Trace: 0/20 passing | Graphics: 11/20 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (11 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `button_test1` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 2 | `edittext_test1` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 3 | `gotoFrameLabelAsFunction` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 4 | `hello` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 5 | `mouse_drag_test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 6 | `movieclip_destruction_test2` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 7 | `opcode_guard_test2` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 8 | `soft_reference_test1` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 9 | `stackscope` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 10 | `submoviegetvar` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 11 | `swf4opcode` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
