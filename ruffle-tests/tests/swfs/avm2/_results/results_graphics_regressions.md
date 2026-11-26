# Graphics vs Trace Mode Differences

Trace: 1304/1348 passing | Graphics: 1309/1351 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `audio_computespectrum` | Output Mismatch | 0/118 lines match |
| 2 | `mouse_pick_avm1_root` | Output Mismatch | 1/2 lines match |
