# Graphics vs Trace Mode Differences

Trace: 1527/1574 passing | Graphics: 1529/1574 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `as3/Array/insertremove` | Output Mismatch | 30766/30870 lines match |
| 2 | `e4x/Expressions/e11_1_4` | Output Mismatch | 14/37 lines match |
