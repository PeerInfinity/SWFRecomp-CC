# Graphics vs Trace Mode Differences

Trace: 167/243 passing | Graphics: 148/243 passing

## Graphics Regressions (19 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `HitTest-v6` | Ruffle Matched | 80/88 lines match |
| 2 | `HitTest-v7` | Ruffle Matched | 80/88 lines match |
| 3 | `String-v6` | Ruffle Matched | 368/377 lines match |
| 4 | `String-v7` | Ruffle Matched | 368/377 lines match |
| 5 | `String-v8` | Ruffle Matched | 368/377 lines match |
| 6 | `TextField-v5` | Ruffle Matched | 9/12 lines match |
| 7 | `XML-v6` | Ruffle Matched | 483/486 lines match |
| 8 | `XML-v7` | Ruffle Matched | 483/486 lines match |
| 9 | `XMLNode-v5` | Ruffle Matched | 204/207 lines match |
| 10 | `XMLNode-v6` | Ruffle Matched | 204/207 lines match |
| 11 | `XMLNode-v7` | Ruffle Matched | 204/207 lines match |
| 12 | `XMLNode-v8` | Ruffle Matched | 204/207 lines match |
| 13 | `toString_valueOf-v6` | Ruffle Matched | 150/155 lines match |
| 14 | `toString_valueOf-v7` | Ruffle Matched | 150/155 lines match |
| 15 | `toString_valueOf-v8` | Ruffle Matched | 150/155 lines match |
| 16 | `with-v5` | Ruffle Matched | 46/49 lines match |
| 17 | `with-v6` | Ruffle Matched | 101/107 lines match |
| 18 | `with-v7` | Ruffle Matched | 101/107 lines match |
| 19 | `with-v8` | Ruffle Matched | 101/107 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
