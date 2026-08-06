# Graphics vs Trace Mode Differences

Trace: 672/718 passing | Graphics: 674/718 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `load_cancel_via_removemovieclip` | Output Mismatch | 4/8 lines match |
| 2 | `remove_different_level` | Output Mismatch | 2/3 lines match |
