# Graphics vs Trace Mode Differences

Trace: 809/1204 passing | Graphics: 819/1204 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (10 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `callee_in_initializer` | Output Mismatch | 5/6 lines match |
| 2 | `movieclip_currentlabels` | Output Mismatch | 16/17 lines match |
| 3 | `movieclip_currentlabels_dupes1` | Output Mismatch | 45/46 lines match |
| 4 | `movieclip_currentlabels_dupes2` | Output Mismatch | 28/30 lines match |
| 5 | `movieclip_currentlabels_dupes3` | Output Mismatch | 54/67 lines match |
| 6 | `movieclip_currentscene` | Output Mismatch | 8/17 lines match |
| 7 | `movieclip_goto_scene_last_frame_int` | Output Mismatch | 0/1 lines match |
| 8 | `movieclip_goto_scene_last_frame_label` | Output Mismatch | 0/1 lines match |
| 9 | `movieclip_prev_scene` | Output Mismatch | 4/7 lines match |
| 10 | `supercall_two_classobjects` | Segfault | SIGSEGV |
