# Graphics vs Trace Mode Differences

Trace: 605/651 passing | Graphics: 513/651 passing

## Graphics Regressions (92 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `button_keypress` | Output Mismatch | 1/4 lines match |
| 2 | `button_order` | Output Mismatch | 2/6 lines match |
| 3 | `call` | Output Mismatch | 0/63 lines match |
| 4 | `click_block` | Output Mismatch | 5/6 lines match |
| 5 | `clip_event_propagation_order` | Output Mismatch | 5/17 lines match |
| 6 | `clone_sprite_edittext` | Output Mismatch | 3/94 lines match |
| 7 | `clone_sprite_edittext_dynamic` | Output Mismatch | 3/86 lines match |
| 8 | `clone_sprite_types` | Output Mismatch | 14/24 lines match |
| 9 | `create_empty_movie_clip` | Output Mismatch | 3/4 lines match |
| 10 | `cross_movie_root` | Output Mismatch | 0/10 lines match |
| 11 | `default_names` | Output Mismatch | 42/52 lines match |
| 12 | `duplicate_movie_clip` | Output Mismatch | 12/20 lines match |
| 13 | `duplicate_movie_clip_drawing` | Output Mismatch | 1/2 lines match |
| 14 | `edittext_ime_focus_lost` | Output Mismatch | 0/25 lines match |
| 15 | `execution_order1` | Output Mismatch | 4/5 lines match |
| 16 | `execution_order2` | Output Mismatch | 7/33 lines match |
| 17 | `execution_order4` | Output Mismatch | 12/14 lines match |
| 18 | `focusrect_property_swf5` | Output Mismatch | 1236/1237 lines match |
| 19 | `focusrect_property_swf6` | Output Mismatch | 1235/1237 lines match |
| 20 | `focusrect_property_swf7` | Output Mismatch | 1236/1237 lines match |
| 21 | `focusrect_swf6` | Output Mismatch | 4/42 lines match |
| 22 | `form_loader_encoding_1` | Output Mismatch | 1/3 lines match |
| 23 | `function_base_clip` | Output Mismatch | 0/8 lines match |
| 24 | `get_bytes_total` | Output Mismatch | 2/4 lines match |
| 25 | `goto_frame` | Output Mismatch | 3/12 lines match |
| 26 | `goto_frame2` | Output Mismatch | 4/44 lines match |
| 27 | `goto_frame_number` | Output Mismatch | 2/3 lines match |
| 28 | `goto_label` | Output Mismatch | 3/17 lines match |
| 29 | `hittest_morph_input` | Output Mismatch | 0/1 lines match |
| 30 | `issue_2084` | Output Mismatch | 16/32 lines match |
| 31 | `issue_2870` | Output Mismatch | 1/3 lines match |
| 32 | `key_isToggled` | Output Mismatch | 3/9 lines match |
| 33 | `loadmovie` | Output Mismatch | 1/2 lines match |
| 34 | `loadmovie_flashvars` | Output Mismatch | 1/4 lines match |
| 35 | `loadmovie_method` | Output Mismatch | 1/2 lines match |
| 36 | `loadmovie_registerclass` | Output Mismatch | 0/30 lines match |
| 37 | `loadmovie_replace_root` | Output Mismatch | 5/15 lines match |
| 38 | `loadmovie_var_persistence` | Output Mismatch | 2/38 lines match |
| 39 | `loadmovienum` | Output Mismatch | 1/3 lines match |
| 40 | `loadmovienum_cross_version_prototype` | Output Mismatch | 1/9 lines match |
| 41 | `loadvariables2` | Output Mismatch | 2/107 lines match |
| 42 | `local_to_global` | Output Mismatch | 41/49 lines match |
| 43 | `lock_root` | Output Mismatch | 0/1 lines match |
| 44 | `mcl_getprogress` | Output Mismatch | 0/31 lines match |
| 45 | `movieclip_getbounds` | Output Mismatch | 163/191 lines match |
| 46 | `movieclip_in_removed_button` | Output Mismatch | 4/8 lines match |
| 47 | `movieclip_invalid_get_bounds_1` | Output Mismatch | 9/392 lines match |
| 48 | `movieclip_invalid_get_bounds_2` | Output Mismatch | 9/392 lines match |
| 49 | `movieclip_invalid_get_bounds_3` | Output Mismatch | 4/182 lines match |
| 50 | `movieclip_invalid_get_bounds_4` | Output Mismatch | 4/182 lines match |
| 51 | `movieclip_invalid_get_bounds_5` | Output Mismatch | 4/122 lines match |
| 52 | `movieclip_invalid_get_bounds_6` | Runtime Error | 2/10 lines match |
| 53 | `movieclip_invalid_get_bounds_7` | Runtime Error | 2/10 lines match |
| 54 | `movieclip_invalid_get_bounds_8` | Output Mismatch | 4/122 lines match |
| 55 | `movieclip_lockroot` | Output Mismatch | 16/500 lines match |
| 56 | `movieclip_methods_with_loaded_image` | Output Mismatch | 0/4 lines match |
| 57 | `movieclip_state_values` | Output Mismatch | 11/294 lines match |
| 58 | `netstream_play_flv` | Output Mismatch | 2/120 lines match |
| 59 | `netstream_seek_flv` | Output Mismatch | 0/25 lines match |
| 60 | `register_class_swf6` | Output Mismatch | 0/37 lines match |
| 61 | `remove_movie_clip` | Output Mismatch | 26/29 lines match |
| 62 | `removed_clip_halts_script` | Output Mismatch | 3/15 lines match |
| 63 | `removed_target_clip_scope` | Output Mismatch | 12/37 lines match |
| 64 | `resolve_different_root` | Output Mismatch | 0/2 lines match |
| 65 | `root_button_mode` | Output Mismatch | 0/10 lines match |
| 66 | `selection_handlers` | Output Mismatch | 19/27 lines match |
| 67 | `set_interval` | Output Mismatch | 17/901 lines match |
| 68 | `sound` | Output Mismatch | 624/628 lines match |
| 69 | `sound_duration_position_props` | Output Mismatch | 38/4000 lines match |
| 70 | `sound_load_start` | Output Mismatch | 0/3 lines match |
| 71 | `sound_multiple_load` | Output Mismatch | 0/1 lines match |
| 72 | `string_paths_hidden` | Output Mismatch | 53/54 lines match |
| 73 | `string_paths_variable_scopes` | Output Mismatch | 3/5 lines match |
| 74 | `swf5_to_6_cross_call` | Output Mismatch | 0/29 lines match |
| 75 | `swf5_xml_event_handler_context` | Output Mismatch | 0/2 lines match |
| 76 | `swf6_case_insensitive` | Output Mismatch | 41/42 lines match |
| 77 | `swf6_to_5_cross_call` | Output Mismatch | 0/29 lines match |
| 78 | `tab_ordering_events` | Output Mismatch | 131/150 lines match |
| 79 | `tab_ordering_events_mouse` | Output Mismatch | 5/65 lines match |
| 80 | `target_clip_removed` | Output Mismatch | 5/6 lines match |
| 81 | `tell_target_invalid` | Output Mismatch | 5/6 lines match |
| 82 | `tell_target_invalid_swf6` | Output Mismatch | 4/7 lines match |
| 83 | `text_blocks_clicks` | Output Mismatch | 0/4 lines match |
| 84 | `textfield_cache_as_bitmap` | Output Mismatch | 1/2 lines match |
| 85 | `textsnapshot_available_text` | Output Mismatch | 13/20 lines match |
| 86 | `timeout` | Timeout | runtime timeout (>10s) |
| 87 | `transform` | Output Mismatch | 62/70 lines match |
| 88 | `unload` | Output Mismatch | 47/52 lines match |
| 89 | `unload_nested_child` | Output Mismatch | 3/5 lines match |
| 90 | `unloadmovie` | Output Mismatch | 1/4 lines match |
| 91 | `unloadmovie_method` | Output Mismatch | 1/3 lines match |
| 92 | `unloadmovienum` | Output Mismatch | 6/13 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
