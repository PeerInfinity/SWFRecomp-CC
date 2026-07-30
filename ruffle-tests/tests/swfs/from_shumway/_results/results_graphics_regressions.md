# Graphics vs Trace Mode Differences

Trace: 168/229 passing | Graphics: 173/229 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (5 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `acid/acid-filter` | Output Mismatch | 0/2 lines match |
| 2 | `flash_net_URLLoader` | Output Mismatch | 0/7 lines match |
| 3 | `localconnection` | Output Mismatch | 3/12 lines match |
| 4 | `stream1` | Output Mismatch | 0/9 lines match |
| 5 | `timeline/nav/filters` | Output Mismatch | 6/8 lines match |
