# Graphics vs Trace Mode Differences

Trace: 605/651 passing | Graphics: 592/651 passing

## Graphics Regressions (13 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `clip_event_propagation_order` | Output Mismatch | 5/17 lines match |
| 2 | `default_names` | Output Mismatch | 42/52 lines match |
| 3 | `focusrect_swf6` | Output Mismatch | 4/42 lines match |
| 4 | `hittest_morph_input` | Output Mismatch | 0/1 lines match |
| 5 | `key_isToggled` | Output Mismatch | 3/9 lines match |
| 6 | `netstream_seek_flv` | Output Mismatch | 25/37 lines match |
| 7 | `root_button_mode` | Output Mismatch | 0/10 lines match |
| 8 | `selection_handlers` | Output Mismatch | 19/27 lines match |
| 9 | `sound` | Output Mismatch | 624/628 lines match |
| 10 | `tab_ordering_events` | Output Mismatch | 131/150 lines match |
| 11 | `tab_ordering_events_mouse` | Output Mismatch | 5/65 lines match |
| 12 | `text_blocks_clicks` | Output Mismatch | 0/4 lines match |
| 13 | `timeout` | Timeout | runtime timeout (>10s) |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
