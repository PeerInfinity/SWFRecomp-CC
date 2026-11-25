# Graphics vs Trace Mode Differences

Trace: 1288/1346 passing | Graphics: 1293/1346 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (5 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `audio_computespectrum` | Output Mismatch | 0/118 lines match |
| 2 | `goto_framescript_queued/swf13` | Ruffle Matched | 56/59 lines match |
| 3 | `goto_framescript_queued_next_prev` | Ruffle Matched | 7/20 lines match |
| 4 | `goto_isplaying` | Ruffle Matched | 20/28 lines match |
| 5 | `goto_scene_isplaying` | Ruffle Matched | 4/24 lines match |
