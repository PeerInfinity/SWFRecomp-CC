# Graphics vs Trace Mode Differences

Trace: 843/1221 passing | Graphics: 845/1221 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `error_geterrormessage` | Output Mismatch | 0/779 lines match |
| 2 | `wrong_arg_count` | Output Mismatch | 1/7 lines match |
