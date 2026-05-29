# Graphics vs Trace Mode Differences

Trace: 132/243 passing | Graphics: 126/243 passing

## Graphics Regressions (6 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `case-v5` | Runtime Error | 39/39 lines match |
| 2 | `case-v6` | Runtime Error | 73/73 lines match |
| 3 | `getvariable-v5` | Output Mismatch | 55/58 lines match |
| 4 | `getvariable-v6` | Ruffle Matched | 61/64 lines match |
| 5 | `getvariable-v7` | Output Mismatch | 61/64 lines match |
| 6 | `getvariable-v8` | Output Mismatch | 61/64 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
