# Graphics vs Trace Mode Differences

Trace: 124/243 passing | Graphics: 126/243 passing

## Graphics Regressions (2 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `case-v5` | Runtime Error | 39/39 lines match |
| 2 | `case-v6` | Runtime Error | 73/73 lines match |

## Graphics Improvements (4 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `delete-v5` | Output Mismatch | 42/61 lines match |
| 2 | `delete-v6` | Output Mismatch | 42/61 lines match |
| 3 | `delete-v7` | Output Mismatch | 42/61 lines match |
| 4 | `delete-v8` | Output Mismatch | 42/61 lines match |
