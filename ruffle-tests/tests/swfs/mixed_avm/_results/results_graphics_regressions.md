# Graphics vs Trace Mode Differences

Trace: 4/11 passing | Graphics: 7/11 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (3 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `avm2_loads_avm1_doabc` | Output Mismatch | 1/4 lines match |
| 2 | `avm2_loads_avm1_loads_avm2_doabc` | Output Mismatch | 1/3 lines match |
| 3 | `avm2_loads_avm1_loads_into_root` | Output Mismatch | 1/2 lines match |
