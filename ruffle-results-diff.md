# Ruffle Test Results Diff

**Previous:** `74ae275df64f` (2026-02-13T23:54:48.557718+00:00)
**Current:** `2a88307e7980` (2026-02-14T00:37:32.353611+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 141 | 144 | +3 |
| Total | 619 | 619 | 0 |
| Pass rate | 22.8% | 23.3% | +0.5% |
| Mismatched lines | 60861 | 57238 | -3623 |
|   Decreased | | | -5762 |
|   Increased | | | +2139 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as_transformed_flag` | output_mismatch | 18/20 | 20/20 |
| `execution_order2` | output_mismatch | 5/7 | 7/7 |
| `goto_advance2` | output_mismatch | 2/2 | 2/2 |
| `goto_rewind2` | output_mismatch | 3/3 | 3/3 |
| `issue_1906` | output_mismatch | 2/4 | 4/4 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `display_object_properties` | output_mismatch | 2/2 | 1/2 |
| `goto_advance1` | output_mismatch | 6/6 | 4/6 |

## Status Changed (67)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `button_children` | segfault | output_mismatch | 1/8 | 1/8 |
| `button_key_events` | segfault | output_mismatch | - | 0/14 |
| `button_key_events_special` | segfault | output_mismatch | - | 0/45 |
| `button_keypress_vs_press` | segfault | output_mismatch | - | 0/25 |
| `button_keypress_vs_tab` | segfault | output_mismatch | - | 0/20 |
| `button_keypress_vs_textinput` | segfault | output_mismatch | - | 0/4 |
| `clone_sprite_edittext` | segfault | output_mismatch | - | 2/94 |
| `clone_sprite_types` | segfault | output_mismatch | 1/24 | 12/24 |
| `edittext_align` | segfault | output_mismatch | - | 36/60 |
| `edittext_autosize` | segfault | output_mismatch | - | 39/71 |
| `edittext_autosize_setter` | segfault | output_mismatch | - | 2/20 |
| `edittext_bullet` | segfault | output_mismatch | - | 18/30 |
| `edittext_default_format` | segfault | output_mismatch | - | 114/221 |
| `edittext_default_format_empty` | segfault | output_mismatch | 1/95 | 5/95 |
| `edittext_default_format_font_style` | segfault | output_mismatch | 24/335 | 176/335 |
| `edittext_font_size` | segfault | output_mismatch | - | 15/45 |
| `edittext_html_align_swf7` | segfault | output_mismatch | - | 12/52 |
| `edittext_html_align_swf8` | segfault | output_mismatch | - | 12/52 |
| `edittext_html_condensewhite_swf7` | segfault | output_mismatch | - | 93/311 |
| `edittext_html_condensewhite_swf8` | segfault | output_mismatch | - | 90/311 |
| `edittext_html_entity` | segfault | output_mismatch | - | 2/4 |
| `edittext_html_swf6` | segfault | output_mismatch | 1/5377 | 2014/5377 |
| `edittext_html_swf7` | segfault | output_mismatch | 1/5377 | 1378/5377 |
| `edittext_html_swf8` | segfault | output_mismatch | 1/5377 | 1363/5377 |
| `edittext_input_newlines` | segfault | output_mismatch | - | 0/9 |
| `edittext_leading` | segfault | output_mismatch | - | 3/9 |
| `edittext_letter_spacing` | segfault | output_mismatch | - | 9/15 |
| `edittext_margins` | segfault | output_mismatch | - | 15/25 |
| `edittext_newline_stripping` | segfault | output_mismatch | 1/64 | 32/64 |
| `edittext_newlines` | segfault | output_mismatch | - | 18/30 |
| `edittext_password_copy` | segfault | output_mismatch | - | 0/4 |
| `edittext_programmatic_focus` | segfault | output_mismatch | 0/12 | 0/12 |
| `edittext_restrict_paste` | segfault | output_mismatch | - | 0/5 |
| `edittext_scroll` | segfault | output_mismatch | 2/54 | 33/54 |
| `edittext_tab_stops` | segfault | output_mismatch | - | 36/60 |
| `edittext_tag_indent` | segfault | output_mismatch | - | 5/31 |
| `edittext_underline` | segfault | output_mismatch | - | 24/40 |
| `edittext_width_height` | segfault | output_mismatch | - | 63/103 |
| `focus_keyboard_press` | segfault | output_mismatch | - | 0/60 |
| `focus_mouse` | segfault | output_mismatch | - | 0/45 |
| `focus_mouse_rollout` | segfault | output_mismatch | - | 0/4 |
| `focusrect_property_swf5` | segfault | output_mismatch | 3/1237 | 210/1237 |
| `focusrect_property_swf6` | segfault | output_mismatch | 3/1237 | 210/1237 |
| `focusrect_property_swf7` | segfault | output_mismatch | 2/1237 | 209/1237 |
| `input_dead_keys_windows` | segfault | output_mismatch | - | 0/15 |
| `issue_3522` | segfault | output_mismatch | 1/2 | 1/2 |
| `native_objects_swf6` | segfault | output_mismatch | 0/84 | 0/84 |
| `native_objects_swf7` | segfault | output_mismatch | 0/84 | 0/84 |
| `native_objects_swf8` | segfault | output_mismatch | 0/84 | 0/84 |
| `netstream_play_flv` | segfault | output_mismatch | 0/21 | 0/21 |
| `remove_movie_clip` | segfault | output_mismatch | 11/29 | 17/29 |
| `selection` | segfault | output_mismatch | - | 42/454 |
| `selection_handlers` | segfault | output_mismatch | - | 1/27 |
| `string_paths_hidden` | segfault | output_mismatch | 1/54 | 35/54 |
| `tab_ordering_custom_basic` | segfault | output_mismatch | - | 0/71 |
| `tab_ordering_custom_i32_vs_u32` | segfault | output_mismatch | - | 0/12 |
| `tab_ordering_custom_m1` | segfault | output_mismatch | - | 0/29 |
| `tab_ordering_events` | segfault | output_mismatch | - | 2/150 |
| `tab_ordering_events_mouse` | segfault | output_mismatch | - | 0/65 |
| `tab_ordering_properties` | segfault | output_mismatch | 2/293 | 5/293 |
| `tab_ordering_tabbable` | segfault | output_mismatch | - | 0/47 |
| `textfield_background_color` | segfault | output_mismatch | 1/11 | 8/11 |
| `textfield_border_color` | segfault | output_mismatch | 1/11 | 8/11 |
| `textfield_properties` | segfault | output_mismatch | 1/44 | 32/44 |
| `textfield_text` | segfault | output_mismatch | 1/7 | 6/7 |
| `textfield_variable` | segfault | output_mismatch | 1/81 | 54/81 |
| `use_hand_cursor` | segfault | output_mismatch | 1/8 | 6/8 |

## Line Count Changed (10)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `default_names` | output_mismatch | 10/52 | 12/52 | -2 |
| `execution_order4` | output_mismatch | 1/12 | 2/12 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `tell_target_invalid` | output_mismatch | 0/6 | 0/6 | 0 |
| `tell_target_invalid_swf6` | output_mismatch | 0/5 | 0/5 | 0 |
| `register_and_init_order` | output_mismatch | 31/231 | 30/231 | +1 |
| `conflicting_instance_names` | output_mismatch | 20/23 | 18/23 | +2 |
| `frame_size_translated_negative` | output_mismatch | 10/21 | 7/21 | +3 |
| `frame_size_translated_positive` | output_mismatch | 10/21 | 6/21 | +4 |
| `device_font_spacing` | segfault | - | 1/91 | +90 |
