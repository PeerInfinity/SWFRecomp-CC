# Graphics vs Trace Mode Differences

Trace: 689/725 passing | Graphics: 681/725 passing

## Graphics Regressions (8 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `looping_child_swf32` | Output Mismatch | 38/207 lines match |
| 2 | `looping_child_swf5` | Output Mismatch | 38/207 lines match |
| 3 | `looping_child_swf9` | Output Mismatch | 38/207 lines match |
| 4 | `shared_stack` | Output Mismatch | 11/16 lines match |
| 5 | `sound_load_multiple_remote` | Output Mismatch | 2/6 lines match |
| 6 | `sound_load_props` | Output Mismatch | 96/111 lines match |
| 7 | `sound_load_start_remote` | Output Mismatch | 0/1 lines match |
| 8 | `sound_load_streaming_stop_remote` | Output Mismatch | 2/3 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
