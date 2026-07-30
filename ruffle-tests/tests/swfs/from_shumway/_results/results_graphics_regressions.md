# Graphics vs Trace Mode Differences

Trace: 168/229 passing | Graphics: 183/229 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (15 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `acid/acid-filter` | Output Mismatch | 0/2 lines match |
| 2 | `blendmode/blendmode_1` | Output Mismatch | 1/2 lines match |
| 3 | `blendmode/blendmode_2` | Output Mismatch | 2/4 lines match |
| 4 | `flash_net_URLLoader` | Output Mismatch | 0/7 lines match |
| 5 | `localconnection` | Output Mismatch | 3/12 lines match |
| 6 | `stream1` | Output Mismatch | 0/9 lines match |
| 7 | `stroke1` | Output Mismatch | 0/4 lines match |
| 8 | `timeline/nav/blendMode` | Output Mismatch | 6/8 lines match |
| 9 | `timeline/nav/cacheAsBitmap` | Output Mismatch | 6/8 lines match |
| 10 | `timeline/nav/colorTransform` | Output Mismatch | 6/8 lines match |
| 11 | `timeline/nav/filters` | Output Mismatch | 6/8 lines match |
| 12 | `timeline/nav/matrix` | Output Mismatch | 7/8 lines match |
| 13 | `timeline/nav/morphShape` | Output Mismatch | 3/4 lines match |
| 14 | `timeline/nav/ratio` | Output Mismatch | 3/4 lines match |
| 15 | `timeline/nav/ratio2` | Output Mismatch | 3/4 lines match |
