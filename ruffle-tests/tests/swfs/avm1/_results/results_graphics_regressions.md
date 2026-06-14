# Graphics vs Trace Mode Differences

Trace: 620/687 passing | Graphics: 618/687 passing

## Graphics Regressions (2 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `focus_mouse` | Output Mismatch | 14/49 lines match |
| 2 | `tab_ordering_events_mouse` | Output Mismatch | 31/67 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
