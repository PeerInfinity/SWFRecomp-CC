# Graphics vs Trace Mode Differences

Trace: 132/243 passing | Graphics: 127/243 passing

## Graphics Regressions (5 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `case-v6` | Runtime Error | 73/73 lines match |
| 2 | `getvariable-v5` | Output Mismatch | 44/58 lines match |
| 3 | `getvariable-v6` | Output Mismatch | 48/64 lines match |
| 4 | `getvariable-v7` | Output Mismatch | 49/64 lines match |
| 5 | `getvariable-v8` | Output Mismatch | 49/64 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
