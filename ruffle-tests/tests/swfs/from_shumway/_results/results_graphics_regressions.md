# Graphics vs Trace Mode Differences

Trace: 215/229 passing | Graphics: 218/229 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (3 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `MaskTest-3` | Ruffle Matched | 3/4 lines match |
| 2 | `avm2/flash/geom/transform/pixelBounds` | Ruffle Matched | 2/3 lines match |
| 3 | `timeline/nav/clipDepth` | Ruffle Matched | 4/8 lines match |
