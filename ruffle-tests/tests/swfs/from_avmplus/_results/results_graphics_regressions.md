# Graphics vs Trace Mode Differences

Trace: 1564/1574 passing | Graphics: 1567/1574 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (3 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `as3/Math/e15_1_2_2` | Ruffle Matched | 3/4 lines match |
| 2 | `regress/bug_479786` | Ruffle Matched | 0/1 lines match |
| 3 | `regress/bug_558863_swf10` | Ruffle Matched | 0/1 lines match |
