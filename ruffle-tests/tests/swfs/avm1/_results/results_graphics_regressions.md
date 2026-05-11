# Graphics vs Trace Mode Differences

Trace: 605/651 passing | Graphics: 589/651 passing

## Graphics Regressions (16 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `click_block` | Output Mismatch | 5/6 lines match |
| 2 | `clip_event_propagation_order` | Output Mismatch | 5/17 lines match |
| 3 | `default_names` | Output Mismatch | 42/52 lines match |
| 4 | `focusrect_swf6` | Output Mismatch | 4/42 lines match |
| 5 | `goto_frame2` | Output Mismatch | 39/44 lines match |
| 6 | `hittest_morph_input` | Output Mismatch | 0/1 lines match |
| 7 | `key_isToggled` | Output Mismatch | 3/9 lines match |
| 8 | `netstream_seek_flv` | Output Mismatch | 25/37 lines match |
| 9 | `removed_clip_halts_script` | Output Mismatch | 5/19 lines match |
| 10 | `root_button_mode` | Output Mismatch | 0/10 lines match |
| 11 | `selection_handlers` | Output Mismatch | 19/27 lines match |
| 12 | `sound` | Output Mismatch | 624/628 lines match |
| 13 | `tab_ordering_events` | Output Mismatch | 131/150 lines match |
| 14 | `tab_ordering_events_mouse` | Output Mismatch | 5/65 lines match |
| 15 | `text_blocks_clicks` | Output Mismatch | 0/4 lines match |
| 16 | `timeout` | Timeout | runtime timeout (>10s) |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
