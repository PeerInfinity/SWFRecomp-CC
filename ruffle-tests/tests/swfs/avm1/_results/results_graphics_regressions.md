# Graphics vs Trace Mode Differences

Trace: 604/654 passing | Graphics: 604/654 passing

## Graphics Regressions (1 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `swf5_xml_event_handler_context` | Output Mismatch | 0/3 lines match |

## Graphics Improvements (1 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `placeobject_occupied_depth` | Output Mismatch | 0/6 lines match |
