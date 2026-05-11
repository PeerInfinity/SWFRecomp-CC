# Graphics vs Trace Mode Differences

Trace: 605/651 passing | Graphics: 565/651 passing

## Graphics Regressions (40 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `button_order` | Output Mismatch | 2/6 lines match |
| 2 | `click_block` | Output Mismatch | 5/6 lines match |
| 3 | `clip_event_propagation_order` | Output Mismatch | 5/17 lines match |
| 4 | `clone_sprite_edittext` | Output Mismatch | 3/94 lines match |
| 5 | `clone_sprite_edittext_dynamic` | Output Mismatch | 3/86 lines match |
| 6 | `clone_sprite_types` | Output Mismatch | 14/24 lines match |
| 7 | `create_empty_movie_clip` | Output Mismatch | 3/4 lines match |
| 8 | `default_names` | Output Mismatch | 42/52 lines match |
| 9 | `duplicate_movie_clip` | Output Mismatch | 12/20 lines match |
| 10 | `duplicate_movie_clip_drawing` | Output Mismatch | 1/2 lines match |
| 11 | `focusrect_property_swf6` | Output Mismatch | 1236/1237 lines match |
| 12 | `focusrect_swf6` | Output Mismatch | 4/42 lines match |
| 13 | `get_bytes_total` | Output Mismatch | 2/4 lines match |
| 14 | `goto_frame2` | Output Mismatch | 39/44 lines match |
| 15 | `goto_frame_number` | Output Mismatch | 2/3 lines match |
| 16 | `hittest_morph_input` | Output Mismatch | 0/1 lines match |
| 17 | `key_isToggled` | Output Mismatch | 3/9 lines match |
| 18 | `local_to_global` | Output Mismatch | 41/49 lines match |
| 19 | `mcl_unloadclip` | Output Mismatch | 5/6 lines match |
| 20 | `movieclip_getbounds` | Output Mismatch | 163/191 lines match |
| 21 | `movieclip_in_removed_button` | Output Mismatch | 4/8 lines match |
| 22 | `netstream_seek_flv` | Output Mismatch | 25/37 lines match |
| 23 | `remove_movie_clip` | Output Mismatch | 26/29 lines match |
| 24 | `removed_clip_halts_script` | Output Mismatch | 5/19 lines match |
| 25 | `removed_target_clip_scope` | Output Mismatch | 12/37 lines match |
| 26 | `root_button_mode` | Output Mismatch | 0/10 lines match |
| 27 | `selection_handlers` | Output Mismatch | 19/27 lines match |
| 28 | `sound` | Output Mismatch | 624/628 lines match |
| 29 | `string_paths_hidden` | Output Mismatch | 53/54 lines match |
| 30 | `string_paths_variable_scopes` | Output Mismatch | 3/5 lines match |
| 31 | `swf6_case_insensitive` | Output Mismatch | 41/42 lines match |
| 32 | `tab_ordering_events` | Output Mismatch | 131/150 lines match |
| 33 | `tab_ordering_events_mouse` | Output Mismatch | 5/65 lines match |
| 34 | `text_blocks_clicks` | Output Mismatch | 0/4 lines match |
| 35 | `textsnapshot_available_text` | Output Mismatch | 13/20 lines match |
| 36 | `timeout` | Timeout | runtime timeout (>10s) |
| 37 | `transform` | Output Mismatch | 62/70 lines match |
| 38 | `unload` | Output Mismatch | 47/52 lines match |
| 39 | `unload_nested_child` | Output Mismatch | 3/5 lines match |
| 40 | `unloadmovienum` | Output Mismatch | 13/14 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
