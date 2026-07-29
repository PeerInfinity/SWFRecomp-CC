# Graphics vs Trace Mode Differences

Trace: 651/717 passing | Graphics: 646/717 passing

## Graphics Regressions (5 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `file_reference_browse_cancel` | Output Mismatch | 10/21 lines match |
| 2 | `file_reference_list_asbroadcaster` | Output Mismatch | 0/9 lines match |
| 3 | `file_reference_list_browse_cancel` | Output Mismatch | 1/4 lines match |
| 4 | `file_reference_list_browse_invalid_filters` | Output Mismatch | 18/36 lines match |
| 5 | `file_reference_list_browse_select` | Output Mismatch | 1/7 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
