# Graphics vs Trace Mode Differences

Trace: 135/142 passing | Graphics: 135/142 passing

## Graphics Regressions (1 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `video/deblocking` | Runtime Error | exit code -6 |

## Graphics Improvements (1 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `simple_shapes/heavy_tesselation` | Recomp Fail | SWFRecomp failed |
