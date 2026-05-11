# Graphics vs Trace Mode Differences

Trace: 605/651 passing | Graphics: 602/651 passing

## Graphics Regressions (3 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `netstream_seek_flv` | Output Mismatch | 25/37 lines match |
| 2 | `sound` | Output Mismatch | 624/628 lines match |
| 3 | `timeout` | Timeout | runtime timeout (>10s) |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
