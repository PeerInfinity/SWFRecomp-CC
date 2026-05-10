# Graphics vs Trace Mode Differences

Trace: 46/47 passing | Graphics: 37/47 passing

## Graphics Regressions (9 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `duplicateMovieClip/dontremove` | Output Mismatch | 3/6 lines match |
| 2 | `duplicateMovieClip/samedepth` | Output Mismatch | 4/6 lines match |
| 3 | `levels` | Output Mismatch | 4/9 lines match |
| 4 | `mouse-transparency` | Output Mismatch | 0/1 lines match |
| 5 | `moviecliploader` | Output Mismatch | 6/7 lines match |
| 6 | `nested-button` | Output Mismatch | 0/1 lines match |
| 7 | `rollover` | Output Mismatch | 1/4 lines match |
| 8 | `setinterval` | Output Mismatch | 14/20 lines match |
| 9 | `settimeout` | Output Mismatch | 14/17 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
