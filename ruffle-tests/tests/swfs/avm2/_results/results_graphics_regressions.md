# Graphics vs Trace Mode Differences

Trace: 1199/1262 passing | Graphics: 1200/1270 passing

## Graphics Regressions (1 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `geom_transform` | Output Mismatch | 71/74 lines match |

## Graphics Improvements (1 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `loader_duplicate_class` | Output Mismatch | 32/48 lines match |
