# Graphics vs Trace Mode Differences

Trace: 1510/1574 passing | Graphics: 1514/1574 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (4 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `as3/String/localeCompare_585791/v9` | Output Mismatch | 2/8 lines match |
| 2 | `ecma3/Expressions/e11_6_1_3` | Output Mismatch | 3/9 lines match |
| 3 | `ecma3/String/e15_5_4_8_2` | Output Mismatch | 54/60 lines match |
| 4 | `regress/bug_550958` | Output Mismatch | 2/5 lines match |
