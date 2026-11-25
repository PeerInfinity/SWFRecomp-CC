# Graphics vs Trace Mode Differences

Trace: 751/788 passing | Graphics: 754/788 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (3 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `malformed_actions/constant_pool_overlong` | Output Mismatch | 1/2 lines match |
| 2 | `malformed_actions/constant_pool_overspill` | Output Mismatch | 1/11 lines match |
| 3 | `malformed_actions/push_overspill` | Output Mismatch | 2/4 lines match |
