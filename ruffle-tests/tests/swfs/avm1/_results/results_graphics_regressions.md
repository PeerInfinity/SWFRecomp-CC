# Graphics vs Trace Mode Differences

Trace: 611/661 passing | Graphics: 604/655 passing

## Graphics Regressions (2 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `sound_gettransform_props` | Output Mismatch | 2/4 lines match |
| 2 | `swf5_xml_event_handler_context` | Output Mismatch | 0/3 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
