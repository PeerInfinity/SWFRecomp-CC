# Graphics vs Trace Mode Differences

Trace: 929/1221 passing | Graphics: 919/1221 passing

## Graphics Regressions (10 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `filefilter_properties` | Output Mismatch | 0/4 lines match |
| 2 | `filereference_browse_cancel` | Output Mismatch | 0/3 lines match |
| 3 | `filereference_browse_select` | Output Mismatch | 0/9 lines match |
| 4 | `filereference_load` | Output Mismatch | 0/31 lines match |
| 5 | `filereference_save` | Output Mismatch | 0/16 lines match |
| 6 | `filereference_save_and_browse` | Output Mismatch | 0/42 lines match |
| 7 | `filereference_save_and_load` | Output Mismatch | 0/22 lines match |
| 8 | `filereference_uninitialized` | Output Mismatch | 0/8 lines match |
| 9 | `filereferencelist_browse_cancel` | Output Mismatch | 0/6 lines match |
| 10 | `filereferencelist_browse_select` | Output Mismatch | 0/7 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
