# Graphics vs Trace Mode Differences

Trace: 1308/1351 passing | Graphics: 1316/1352 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (7 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `audio_computespectrum` | Output Mismatch | 0/118 lines match |
| 2 | `dependent_strings` | Output Mismatch | 46/84 lines match |
| 3 | `edittext_getcharboundaries_culling` | Ruffle Matched | 125/305 lines match |
| 4 | `event_handler_exception` | Ruffle Matched | 8/11 lines match |
| 5 | `freestanding_superclass` | Ruffle Matched | 2/4 lines match |
| 6 | `loader_applicationDomain` | Output Mismatch | 0/4 lines match |
| 7 | `weird_superinterface_properties` | Ruffle Matched | 1/2 lines match |
