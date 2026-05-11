# Graphics vs Trace Mode Differences

Trace: 46/47 passing | Graphics: 42/47 passing

## Graphics Regressions (4 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `duplicateMovieClip/dontremove` | Output Mismatch | 3/6 lines match |
| 2 | `duplicateMovieClip/samedepth` | Output Mismatch | 4/6 lines match |
| 3 | `mouse-transparency` | Output Mismatch | 0/1 lines match |
| 4 | `nested-button` | Output Mismatch | 0/1 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
