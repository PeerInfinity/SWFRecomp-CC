# Graphics vs Trace Mode Differences

Trace: 619/678 passing | Graphics: 618/678 passing

## Graphics Regressions (1 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `bad_placeobject_clipaction` | Compile Fail | main.c:91:31: error: ‘FRAME_COUNT’ undeclared (first use in this function); did you mean ‘SWF_FRAME_COUNT’? |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
