# Graphics vs Trace Mode Differences

Trace: 707/744 passing | Graphics: 710/744 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (3 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `matrix` | Output Mismatch | 57/810 lines match |
| 2 | `point` | Output Mismatch | 54/329 lines match |
| 3 | `rectangle` | Output Mismatch | 141/629 lines match |
