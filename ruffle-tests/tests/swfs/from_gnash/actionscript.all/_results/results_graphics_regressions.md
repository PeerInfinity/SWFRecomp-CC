# Graphics vs Trace Mode Differences

Trace: 177/243 passing | Graphics: 167/243 passing

## Graphics Regressions (10 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `Global-v6` | Ruffle Matched | 201/210 lines match |
| 2 | `Number-v5` | Ruffle Matched | 236/244 lines match |
| 3 | `Object-v5` | Ruffle Matched | 142/145 lines match |
| 4 | `Selection-v6` | Ruffle Matched | 118/125 lines match |
| 5 | `Selection-v7` | Ruffle Matched | 118/125 lines match |
| 6 | `Selection-v8` | Ruffle Matched | 118/125 lines match |
| 7 | `ops-v5` | Ruffle Matched | 253/260 lines match |
| 8 | `ops-v6` | Ruffle Matched | 253/260 lines match |
| 9 | `ops-v7` | Ruffle Matched | 255/262 lines match |
| 10 | `ops-v8` | Ruffle Matched | 255/262 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
