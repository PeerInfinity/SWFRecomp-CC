# Graphics vs Trace Mode Differences

Trace: 14/17 passing | Graphics: 16/17 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `swf_9_event_goto_frame_script` | Ruffle Matched | 3/5 lines match |
| 2 | `swf_9_frame_script_dynamic_goto` | Ruffle Matched | 31/34 lines match |
