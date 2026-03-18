# Headless vs Normal Mode Differences

Normal: 562/619 passing | Headless: 468/621 passing

## Headless Regressions (94 tests)

Tests that **pass** in normal mode but **fail** in headless mode.

| # | Test | Headless Status | Detail |
|---|------|-----------------|--------|
| 1 | `button_key_events` | Output Mismatch | 1/15 lines match |
| 2 | `button_key_events_special` | Output Mismatch | 0/46 lines match |
| 3 | `button_keypress_vs_press` | Output Mismatch | 0/26 lines match |
| 4 | `button_keypress_vs_tab` | Output Mismatch | 1/21 lines match |
| 5 | `button_keypress_vs_textinput` | Output Mismatch | 0/5 lines match |
| 6 | `click_block` | Segfault | SIGSEGV |
| 7 | `cross_movie_root` | Output Mismatch | 0/10 lines match |
| 8 | `device_font_spacing` | Compile Fail | /tmp/swf_verify_6fun66hw/tagMain.c:48:9: error: too few arguments to function ‘tagDefineText’ |
| 9 | `edittext_align` | Compile Fail | /tmp/swf_verify_6dp5i8ha/tagMain.c:34:9: error: too few arguments to function ‘tagDefineText’ |
| 10 | `edittext_antialiastype` | Compile Fail | /tmp/swf_verify_4aukbgcd/tagMain.c:31:9: error: too few arguments to function ‘tagDefineText’ |
| 11 | `edittext_autosize` | Compile Fail | /tmp/swf_verify_9mtuzld6/tagMain.c:34:9: error: too few arguments to function ‘tagDefineText’ |
| 12 | `edittext_bullet` | Compile Fail | /tmp/swf_verify_campb49u/tagMain.c:36:9: error: too few arguments to function ‘tagDefineText’ |
| 13 | `edittext_default_format` | Compile Fail | /tmp/swf_verify_z07wf14r/tagMain.c:34:9: error: too few arguments to function ‘tagDefineText’ |
| 14 | `edittext_default_format_font_style` | Compile Fail | /tmp/swf_verify_htj0_8hh/tagMain.c:46:9: error: too few arguments to function ‘tagDefineText’ |
| 15 | `edittext_focus_selection` | Output Mismatch | 2/3 lines match |
| 16 | `edittext_font_size` | Compile Fail | /tmp/swf_verify_w4syn_1r/tagMain.c:34:9: error: too few arguments to function ‘tagDefineText’ |
| 17 | `edittext_html_align_swf7` | Compile Fail | /tmp/swf_verify_m7hioyh8/tagMain.c:37:9: error: too few arguments to function ‘tagDefineText’ |
| 18 | `edittext_html_align_swf8` | Compile Fail | /tmp/swf_verify_rok4c_9n/tagMain.c:37:9: error: too few arguments to function ‘tagDefineText’ |
| 19 | `edittext_html_entity` | Compile Fail | /tmp/swf_verify_8l6n0q15/tagMain.c:34:9: error: too few arguments to function ‘tagDefineText’ |
| 20 | `edittext_html_swf6` | Compile Fail | /tmp/swf_verify_h11t3g4e/tagMain.c:45:9: error: too few arguments to function ‘tagDefineText’ |
| 21 | `edittext_html_swf7` | Compile Fail | /tmp/swf_verify_hc57ayx2/tagMain.c:45:9: error: too few arguments to function ‘tagDefineText’ |
| 22 | `edittext_html_swf8` | Compile Fail | /tmp/swf_verify_jqq65fan/tagMain.c:43:9: error: too few arguments to function ‘tagDefineText’ |
| 23 | `edittext_input` | Output Mismatch | 0/2 lines match |
| 24 | `edittext_input_newlines` | Output Mismatch | 0/10 lines match |
| 25 | `edittext_leading` | Compile Fail | /tmp/swf_verify_srfgrzf7/tagMain.c:34:9: error: too few arguments to function ‘tagDefineText’ |
| 26 | `edittext_letter_spacing` | Compile Fail | /tmp/swf_verify_0xf955mw/tagMain.c:34:9: error: too few arguments to function ‘tagDefineText’ |
| 27 | `edittext_margins` | Compile Fail | /tmp/swf_verify_im86s8km/tagMain.c:34:9: error: too few arguments to function ‘tagDefineText’ |
| 28 | `edittext_newline_stripping` | Compile Fail | /tmp/swf_verify_x72jqjer/tagMain.c:35:9: error: too few arguments to function ‘tagDefineText’ |
| 29 | `edittext_newlines` | Compile Fail | /tmp/swf_verify_1y5e87rk/tagMain.c:36:9: error: too few arguments to function ‘tagDefineText’ |
| 30 | `edittext_password` | Compile Fail | /tmp/swf_verify_757dygwe/tagMain.c:66:9: error: too few arguments to function ‘tagDefineText’ |
| 31 | `edittext_password_copy` | Output Mismatch | 3/5 lines match |
| 32 | `edittext_paste_empty` | Output Mismatch | 1/3 lines match |
| 33 | `edittext_programmatic_focus` | Output Mismatch | 12/13 lines match |
| 34 | `edittext_restrict` | Output Mismatch | 0/192 lines match |
| 35 | `edittext_restrict_paste` | Output Mismatch | 1/6 lines match |
| 36 | `edittext_scroll` | Compile Fail | /tmp/swf_verify_oz4s2ci8/tagMain.c:42:9: error: too few arguments to function ‘tagDefineText’ |
| 37 | `edittext_tab_stops` | Compile Fail | /tmp/swf_verify_z6llvppo/tagMain.c:34:9: error: too few arguments to function ‘tagDefineText’ |
| 38 | `edittext_tag_indent` | Compile Fail | /tmp/swf_verify_zail4ic3/tagMain.c:42:9: error: too few arguments to function ‘tagDefineText’ |
| 39 | `edittext_underline` | Compile Fail | /tmp/swf_verify_tql_npa0/tagMain.c:34:9: error: too few arguments to function ‘tagDefineText’ |
| 40 | `edittext_width_height` | Compile Fail | /tmp/swf_verify_mjix4uvo/tagMain.c:34:9: error: too few arguments to function ‘tagDefineText’ |
| 41 | `extends_chain` | Compile Fail | /tmp/swf_verify_m_jy49s9/tagMain.c:101:9: error: too few arguments to function ‘tagDefineText’ |
| 42 | `focus_keyboard_press` | Output Mismatch | 1/61 lines match |
| 43 | `focus_root_movie` | Output Mismatch | 2/3 lines match |
| 44 | `focusrect_mouse_swf8` | Output Mismatch | 0/3 lines match |
| 45 | `focusrect_mouse_swf9` | Output Mismatch | 0/7 lines match |
| 46 | `focusrect_property_swf5` | Output Mismatch | 1236/1237 lines match |
| 47 | `focusrect_property_swf6` | Output Mismatch | 1236/1237 lines match |
| 48 | `focusrect_property_swf7` | Output Mismatch | 1236/1237 lines match |
| 49 | `focusrect_swf5` | Output Mismatch | 1/28 lines match |
| 50 | `focusrect_swf6` | Output Mismatch | 4/42 lines match |
| 51 | `gettextextent` | Compile Fail | /tmp/swf_verify_krk67t9y/tagMain.c:35:9: error: too few arguments to function ‘tagDefineText’ |
| 52 | `input_dead_keys_windows` | Output Mismatch | 1/16 lines match |
| 53 | `issue_2084` | Segfault | SIGSEGV |
| 54 | `issue_2870` | Output Mismatch | 1/3 lines match |
| 55 | `loadmovie` | Output Mismatch | 1/2 lines match |
| 56 | `loadmovie_flashvars` | Output Mismatch | 1/4 lines match |
| 57 | `loadmovie_method` | Output Mismatch | 1/2 lines match |
| 58 | `loadmovie_registerclass` | Output Mismatch | 0/30 lines match |
| 59 | `loadmovienum` | Output Mismatch | 1/3 lines match |
| 60 | `loadmovienum_cross_version_prototype` | Output Mismatch | 1/9 lines match |
| 61 | `lock_root` | Output Mismatch | 0/1 lines match |
| 62 | `movieclip_get_instance_at_depth` | Compile Fail | /tmp/swf_verify_fbngptkh/tagMain.c:44:9: error: too few arguments to function ‘tagDefineText’ |
| 63 | `movieclip_invalid_get_bounds_1` | Output Mismatch | 13/75 lines match |
| 64 | `movieclip_invalid_get_bounds_2` | Output Mismatch | 13/75 lines match |
| 65 | `movieclip_invalid_get_bounds_3` | Output Mismatch | 8/13 lines match |
| 66 | `movieclip_invalid_get_bounds_4` | Output Mismatch | 8/13 lines match |
| 67 | `movieclip_invalid_get_bounds_5` | Output Mismatch | 6/11 lines match |
| 68 | `movieclip_invalid_get_bounds_6` | Output Mismatch | 5/10 lines match |
| 69 | `movieclip_invalid_get_bounds_7` | Output Mismatch | 5/10 lines match |
| 70 | `movieclip_invalid_get_bounds_8` | Output Mismatch | 6/11 lines match |
| 71 | `movieclip_lockroot` | Output Mismatch | 16/65 lines match |
| 72 | `place_and_lookup` | Segfault | SIGSEGV |
| 73 | `register_class_swf6` | Output Mismatch | 0/37 lines match |
| 74 | `resolve_different_root` | Output Mismatch | 0/2 lines match |
| 75 | `root_button_mode` | Output Mismatch | 1/10 lines match |
| 76 | `selection` | Output Mismatch | 454/456 lines match |
| 77 | `swf5_to_6_cross_call` | Output Mismatch | 0/29 lines match |
| 78 | `swf6_to_5_cross_call` | Output Mismatch | 0/29 lines match |
| 79 | `tab_ordering_automatic_basic` | Output Mismatch | 3/93 lines match |
| 80 | `tab_ordering_children` | Output Mismatch | 22/209 lines match |
| 81 | `tab_ordering_custom_basic` | Output Mismatch | 3/72 lines match |
| 82 | `tab_ordering_events` | Output Mismatch | 26/151 lines match |
| 83 | `tab_ordering_movieclip_enabled_default` | Output Mismatch | 3/463 lines match |
| 84 | `tab_ordering_reverse` | Output Mismatch | 3/52 lines match |
| 85 | `tab_ordering_tabbable` | Compile Fail | /tmp/swf_verify_4o7y96yb/tagMain.c:89:9: error: too few arguments to function ‘tagDefineText’ |
| 86 | `textfield_properties` | Compile Fail | /tmp/swf_verify_wtr057we/tagMain.c:29:9: error: too few arguments to function ‘tagDefineText’ |
| 87 | `textfield_text` | Compile Fail | /tmp/swf_verify_7jcdtg0o/tagMain.c:29:9: error: too few arguments to function ‘tagDefineText’ |
| 88 | `textsnapshot_available_text` | Compile Fail | /tmp/swf_verify_synnmzu8/tagMain.c:53:9: error: too few arguments to function ‘tagDefineText’ |
| 89 | `textsnapshot_findtext` | Compile Fail | /tmp/swf_verify_7iyatso4/tagMain.c:32:9: error: too few arguments to function ‘tagDefineText’ |
| 90 | `textsnapshot_gettext` | Compile Fail | /tmp/swf_verify_uyy1fejy/tagMain.c:32:9: error: too few arguments to function ‘tagDefineText’ |
| 91 | `textsnapshot_text_order` | Compile Fail | /tmp/swf_verify_9nkd03a1/tagMain.c:36:9: error: too few arguments to function ‘tagDefineText’ |
| 92 | `unloadmovie` | Output Mismatch | 1/4 lines match |
| 93 | `unloadmovie_method` | Output Mismatch | 1/3 lines match |
| 94 | `unloadmovienum` | Output Mismatch | 6/13 lines match |

## Headless Improvements (0 tests)

Tests that **fail** in normal mode but **pass** in headless mode.

No improvements.
