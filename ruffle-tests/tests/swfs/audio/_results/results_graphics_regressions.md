# Graphics vs Trace Mode Differences

Trace: 3/5 passing | Graphics: 5/5 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `aac` | Output Mismatch | 3/24 lines match |
| 2 | `g711` | Output Mismatch | 2/8 lines match |
