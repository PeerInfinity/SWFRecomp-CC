# Graphics vs Trace Mode Differences

Trace: 212/229 passing | Graphics: 210/229 passing

## Graphics Regressions (2 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `acid/acid-shapes` | Output Mismatch | 0/120 lines match |
| 2 | `as3-loader/loaderinfo/loaded-content-properties` | Output Mismatch | 36/48 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
