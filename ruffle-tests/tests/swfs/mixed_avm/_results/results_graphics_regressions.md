# Graphics vs Trace Mode Differences

Trace: 4/11 passing | Graphics: 10/11 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (6 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `avm2_loads_avm1` | Output Mismatch | 1/14 lines match |
| 2 | `avm2_loads_avm1_doabc` | Output Mismatch | 1/4 lines match |
| 3 | `avm2_loads_avm1_loads_avm2_doabc` | Output Mismatch | 1/3 lines match |
| 4 | `avm2_loads_avm1_loads_into_root` | Output Mismatch | 1/2 lines match |
| 5 | `avm2_loads_avm1_v10` | Output Mismatch | 5/8 lines match |
| 6 | `avm2_loads_avm1_v9` | Output Mismatch | 7/8 lines match |
