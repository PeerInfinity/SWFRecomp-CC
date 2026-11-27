# Graphics vs Trace Mode Differences

Trace: 1315/1352 passing | Graphics: 1274/1307 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `audio_computespectrum` | Output Mismatch | 0/118 lines match |
| 2 | `swz` | Output Mismatch | 2/3 lines match |
