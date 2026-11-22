# Graphics vs Trace Mode Differences

Trace: 1281/1336 passing | Graphics: 1273/1336 passing

## Graphics Regressions (8 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `bitmapdata_encode` | Output Mismatch | 26/147 lines match |
| 2 | `netstream_play_flv` | Output Mismatch | 0/16 lines match |
| 3 | `netstream_play_stop_replay` | Output Mismatch | 1/11 lines match |
| 4 | `netstream_seek_flv` | Output Mismatch | 0/49 lines match |
| 5 | `soundchannel_position_after_end` | Output Mismatch | 2/6 lines match |
| 6 | `textline_metrics` | Output Mismatch | 0/20 lines match |
| 7 | `weird_number_bound_methods` | Output Mismatch | 9/12 lines match |
| 8 | `worker_terminate` | Output Mismatch | 1/56 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
