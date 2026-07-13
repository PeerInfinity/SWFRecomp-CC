# Graphics vs Trace Mode Differences

Trace: 819/1204 passing | Graphics: 801/1204 passing

## Graphics Regressions (18 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `agal_compiler` | Output Mismatch | 1/13 lines match |
| 2 | `get_timer` | Output Mismatch | 0/2 lines match |
| 3 | `movieclip_soundtransform` | Output Mismatch | 3/831 lines match |
| 4 | `shared_object_no_root` | Output Mismatch | 0/3 lines match |
| 5 | `sound_embeddedprops` | Output Mismatch | 0/26 lines match |
| 6 | `sound_play` | Output Mismatch | 0/19 lines match |
| 7 | `sound_valueof` | Output Mismatch | 0/33 lines match |
| 8 | `soundchannel_soundtransform` | Output Mismatch | 0/835 lines match |
| 9 | `soundchannel_soundtransform_exists` | Output Mismatch | 0/5 lines match |
| 10 | `soundchannel_stop` | Output Mismatch | 0/8 lines match |
| 11 | `soundmixer_buffertime` | Output Mismatch | 0/5 lines match |
| 12 | `soundmixer_stopall` | Output Mismatch | 0/6 lines match |
| 13 | `soundtransform` | Output Mismatch | 1/442 lines match |
| 14 | `timer` | Output Mismatch | 0/90 lines match |
| 15 | `timer_events` | Output Mismatch | 0/3 lines match |
| 16 | `timer_finished` | Output Mismatch | 0/11 lines match |
| 17 | `timer_reset` | Output Mismatch | 1/8 lines match |
| 18 | `timer_setdelay` | Output Mismatch | 1/5 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
