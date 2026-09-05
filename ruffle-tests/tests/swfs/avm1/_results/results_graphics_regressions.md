# Graphics vs Trace Mode Differences

Trace: 689/730 passing | Graphics: 691/730 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `hitarea_lazy_getter` | Output Mismatch | 0/6 lines match |
| 2 | `hitarea_remove_sibling` | Output Mismatch | 3/4 lines match |
