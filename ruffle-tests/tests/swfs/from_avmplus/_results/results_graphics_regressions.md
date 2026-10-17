# Graphics vs Trace Mode Differences

Trace: 1529/1574 passing | Graphics: 1531/1574 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `recursion/pcre_find_fixedlength` | Output Mismatch | 19/20 lines match |
| 2 | `regress/bug_483783` | Runtime Error | 0/1 lines match |
