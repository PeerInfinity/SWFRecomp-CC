# Graphics vs Trace Mode Differences

Trace: 1213/1275 passing | Graphics: 1217/1275 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (4 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `goto_framescript_queued/swf10` | Output Mismatch | 15/59 lines match |
| 2 | `goto_framescript_queued/swf9` | Output Mismatch | 11/52 lines match |
| 3 | `goto_framescript_queued_same_frame` | Output Mismatch | 3/4 lines match |
| 4 | `tab_ordering_properties` | Output Mismatch | 561/732 lines match |
