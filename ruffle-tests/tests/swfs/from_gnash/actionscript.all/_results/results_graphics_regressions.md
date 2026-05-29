# Graphics vs Trace Mode Differences

Trace: 128/243 passing | Graphics: 122/243 passing

## Graphics Regressions (6 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `case-v5` | Runtime Error | 39/39 lines match |
| 2 | `case-v6` | Runtime Error | 73/73 lines match |
| 3 | `delete-v5` | Output Mismatch | 42/61 lines match |
| 4 | `delete-v6` | Output Mismatch | 42/61 lines match |
| 5 | `delete-v7` | Output Mismatch | 42/61 lines match |
| 6 | `delete-v8` | Output Mismatch | 42/61 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
