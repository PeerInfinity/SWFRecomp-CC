# Graphics vs Trace Mode Differences

Trace: 605/651 passing | Graphics: 578/651 passing

## Graphics Regressions (27 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `click_block` | Output Mismatch | 5/6 lines match |
| 2 | `clip_event_propagation_order` | Output Mismatch | 5/17 lines match |
| 3 | `clone_sprite_edittext` | Output Mismatch | 3/94 lines match |
| 4 | `clone_sprite_edittext_dynamic` | Output Mismatch | 3/86 lines match |
| 5 | `clone_sprite_types` | Output Mismatch | 18/24 lines match |
| 6 | `default_names` | Output Mismatch | 42/52 lines match |
| 7 | `duplicate_movie_clip` | Output Mismatch | 12/20 lines match |
| 8 | `duplicate_movie_clip_drawing` | Output Mismatch | 1/2 lines match |
| 9 | `focusrect_swf6` | Output Mismatch | 4/42 lines match |
| 10 | `goto_frame2` | Output Mismatch | 39/44 lines match |
| 11 | `goto_frame_number` | Output Mismatch | 2/3 lines match |
| 12 | `hittest_morph_input` | Output Mismatch | 0/1 lines match |
| 13 | `key_isToggled` | Output Mismatch | 3/9 lines match |
| 14 | `netstream_seek_flv` | Output Mismatch | 25/37 lines match |
| 15 | `remove_movie_clip` | Output Mismatch | 26/29 lines match |
| 16 | `removed_clip_halts_script` | Output Mismatch | 5/19 lines match |
| 17 | `removed_target_clip_scope` | Output Mismatch | 12/37 lines match |
| 18 | `root_button_mode` | Output Mismatch | 0/10 lines match |
| 19 | `selection_handlers` | Output Mismatch | 19/27 lines match |
| 20 | `sound` | Output Mismatch | 624/628 lines match |
| 21 | `string_paths_variable_scopes` | Output Mismatch | 3/5 lines match |
| 22 | `tab_ordering_events` | Output Mismatch | 131/150 lines match |
| 23 | `tab_ordering_events_mouse` | Output Mismatch | 5/65 lines match |
| 24 | `text_blocks_clicks` | Output Mismatch | 0/4 lines match |
| 25 | `textsnapshot_available_text` | Output Mismatch | 13/20 lines match |
| 26 | `timeout` | Timeout | runtime timeout (>10s) |
| 27 | `unload_nested_child` | Output Mismatch | 4/5 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
