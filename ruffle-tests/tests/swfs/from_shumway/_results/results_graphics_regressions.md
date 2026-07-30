# Graphics vs Trace Mode Differences

Trace: 168/229 passing | Graphics: 169/229 passing

## Graphics Regressions (1 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `encoding1` | Output Mismatch | 30/31 lines match |

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `flash_net_URLLoader` | Output Mismatch | 0/7 lines match |
| 2 | `stream1` | Output Mismatch | 0/9 lines match |
