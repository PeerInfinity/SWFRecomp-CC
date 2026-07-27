# Graphics vs Trace Mode Differences

Trace: 160/229 passing | Graphics: 150/229 passing

## Graphics Regressions (12 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `encoding1` | Output Mismatch | 31/33 lines match |
| 2 | `flash_events_Event` | Output Mismatch | 3/5 lines match |
| 3 | `hitTestStyleChange` | Output Mismatch | 1/3 lines match |
| 4 | `local2global` | Output Mismatch | 1/3 lines match |
| 5 | `lzma` | Output Mismatch | 5/7 lines match |
| 6 | `lzma_bytes` | Output Mismatch | 2/4 lines match |
| 7 | `timeline/scene/EncodedU32` | Output Mismatch | 1/3 lines match |
| 8 | `timeline/scene/Scene_1_MainTimeline` | Output Mismatch | 70/72 lines match |
| 9 | `timeline/scene/Scene_2_MovieClipTimeline` | Output Mismatch | 70/72 lines match |
| 10 | `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | Output Mismatch | 40/42 lines match |
| 11 | `timeline/scene/Scene_7_NextPrevScene` | Output Mismatch | 7/9 lines match |
| 12 | `timeline/timeline_loop` | Output Mismatch | 7/9 lines match |

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `flash_net_URLRequest` | Output Mismatch | 0/6 lines match |
| 2 | `flash_net_classes` | Ruffle Matched | 18/22 lines match |
