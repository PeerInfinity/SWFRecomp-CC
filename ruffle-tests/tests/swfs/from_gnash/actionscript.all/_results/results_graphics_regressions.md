# Graphics vs Trace Mode Differences

Trace: 128/243 passing | Graphics: 126/243 passing

## Graphics Regressions (2 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `case-v6` | Runtime Error | 73/73 lines match |
| 2 | `flash-v8` | Output Mismatch | 36/41 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
