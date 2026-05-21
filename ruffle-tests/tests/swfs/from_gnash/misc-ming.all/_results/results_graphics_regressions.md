# Graphics vs Trace Mode Differences

Trace: 64/110 passing | Graphics: 63/110 passing

## Graphics Regressions (2 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `loop/loop_test` | Output Mismatch | 4/27 lines match |
| 2 | `place_and_remove_object_insane_test` | Output Mismatch | 16/22 lines match |

## Graphics Improvements (1 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `displaylist_depths/displaylist_depths_test9` | Output Mismatch | 20/23 lines match |
