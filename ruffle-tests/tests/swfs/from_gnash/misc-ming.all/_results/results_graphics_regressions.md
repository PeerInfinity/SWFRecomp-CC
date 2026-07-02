# Graphics vs Trace Mode Differences

Trace: 67/111 passing | Graphics: 67/111 passing

## Graphics Regressions (1 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `place_and_remove_object_insane_test` | Output Mismatch | 17/22 lines match |

## Graphics Improvements (1 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `static_vs_dynamic2` | Output Mismatch | 15/18 lines match |
