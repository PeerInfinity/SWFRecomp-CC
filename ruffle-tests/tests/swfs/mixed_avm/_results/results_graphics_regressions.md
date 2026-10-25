# Graphics vs Trace Mode Differences

Trace: 0/12 passing | Graphics: 10/12 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (10 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `avm1_doabc` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 2 | `avm1_loads_avm2_doaction` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 3 | `avm1_sprite_sc_ignored` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 4 | `avm2_doaction` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 5 | `avm2_loads_avm1` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 6 | `avm2_loads_avm1_doabc` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 7 | `avm2_loads_avm1_loads_avm2_doabc` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 8 | `avm2_loads_avm1_loads_into_root` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 9 | `avm2_loads_avm1_v10` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 10 | `avm2_loads_avm1_v9` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
