# Ruffle Test Results Diff

**Previous:** `ab56d9794890` (2026-02-13T22:58:53.344045+00:00)
**Current:** `74ae275df64f` (2026-02-13T23:54:48.557718+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 140 | 141 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 22.6% | 22.8% | +0.2% |
| Mismatched lines | 57212 | 60861 | +3649 |
|   Decreased | | | -2153 |
|   Increased | | | +5802 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `display_object_properties` | output_mismatch | 1/2 | 2/2 |
| `execution_order1` | output_mismatch | 3/5 | 5/5 |
| `goto_advance1` | output_mismatch | 4/6 | 6/6 |
| `typeof` | output_mismatch | 20/22 | 22/22 |
| `variable_args` | output_mismatch | 5/5 | 5/5 |

## Newly Failing (4)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `as_transformed_flag` | output_mismatch | 20/20 | 18/20 |
| `goto_advance2` | output_mismatch | 2/2 | 2/2 |
| `goto_rewind2` | output_mismatch | 3/3 | 3/3 |
| `issue_1906` | output_mismatch | 4/4 | 2/4 |

## Status Changed (68)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `button_children` | output_mismatch | segfault | 1/8 | 1/8 |
| `button_key_events` | output_mismatch | segfault | 0/14 | - |
| `button_key_events_special` | output_mismatch | segfault | 0/45 | - |
| `button_keypress_vs_press` | output_mismatch | segfault | 0/25 | - |
| `button_keypress_vs_tab` | output_mismatch | segfault | 0/20 | - |
| `button_keypress_vs_textinput` | output_mismatch | segfault | 0/4 | - |
| `clone_sprite_edittext` | output_mismatch | segfault | 2/94 | - |
| `clone_sprite_types` | output_mismatch | segfault | 12/24 | 1/24 |
| `edittext_align` | output_mismatch | segfault | 36/60 | - |
| `edittext_autosize` | output_mismatch | segfault | 39/71 | - |
| `edittext_autosize_setter` | output_mismatch | segfault | 2/20 | - |
| `edittext_bullet` | output_mismatch | segfault | 18/30 | - |
| `edittext_default_format` | output_mismatch | segfault | 114/221 | - |
| `edittext_default_format_empty` | output_mismatch | segfault | 5/95 | 1/95 |
| `edittext_default_format_font_style` | output_mismatch | segfault | 176/335 | 24/335 |
| `edittext_font_size` | output_mismatch | segfault | 15/45 | - |
| `edittext_html_align_swf7` | output_mismatch | segfault | 12/52 | - |
| `edittext_html_align_swf8` | output_mismatch | segfault | 12/52 | - |
| `edittext_html_condensewhite_swf7` | output_mismatch | segfault | 93/311 | - |
| `edittext_html_condensewhite_swf8` | output_mismatch | segfault | 90/311 | - |
| `edittext_html_entity` | output_mismatch | segfault | 2/4 | - |
| `edittext_html_swf6` | output_mismatch | segfault | 2014/5377 | 1/5377 |
| `edittext_html_swf7` | output_mismatch | segfault | 1378/5377 | 1/5377 |
| `edittext_html_swf8` | output_mismatch | segfault | 1363/5377 | 1/5377 |
| `edittext_input_newlines` | output_mismatch | segfault | 0/9 | - |
| `edittext_leading` | output_mismatch | segfault | 3/9 | - |
| `edittext_letter_spacing` | output_mismatch | segfault | 9/15 | - |
| `edittext_margins` | output_mismatch | segfault | 15/25 | - |
| `edittext_newline_stripping` | output_mismatch | segfault | 32/64 | 1/64 |
| `edittext_newlines` | output_mismatch | segfault | 18/30 | - |
| `edittext_password_copy` | output_mismatch | segfault | 0/4 | - |
| `edittext_programmatic_focus` | output_mismatch | segfault | 0/12 | 0/12 |
| `edittext_restrict_paste` | output_mismatch | segfault | 0/5 | - |
| `edittext_scroll` | output_mismatch | segfault | 33/54 | 2/54 |
| `edittext_tab_stops` | output_mismatch | segfault | 36/60 | - |
| `edittext_tag_indent` | output_mismatch | segfault | 5/31 | - |
| `edittext_underline` | output_mismatch | segfault | 24/40 | - |
| `edittext_width_height` | output_mismatch | segfault | 63/103 | - |
| `focus_keyboard_press` | output_mismatch | segfault | 0/60 | - |
| `focus_mouse` | output_mismatch | segfault | 0/45 | - |
| `focus_mouse_rollout` | output_mismatch | segfault | 0/4 | - |
| `focusrect_property_swf5` | output_mismatch | segfault | 210/1237 | 3/1237 |
| `focusrect_property_swf6` | output_mismatch | segfault | 210/1237 | 3/1237 |
| `focusrect_property_swf7` | output_mismatch | segfault | 209/1237 | 2/1237 |
| `goto_methods` | timeout | segfault | - | 8/40 |
| `input_dead_keys_windows` | output_mismatch | segfault | 0/15 | - |
| `issue_3522` | output_mismatch | segfault | 1/2 | 1/2 |
| `native_objects_swf6` | output_mismatch | segfault | 0/84 | 0/84 |
| `native_objects_swf7` | output_mismatch | segfault | 0/84 | 0/84 |
| `native_objects_swf8` | output_mismatch | segfault | 0/84 | 0/84 |
| `netstream_play_flv` | output_mismatch | segfault | 0/21 | 0/21 |
| `remove_movie_clip` | output_mismatch | segfault | 17/29 | 11/29 |
| `selection` | output_mismatch | segfault | 42/454 | - |
| `selection_handlers` | output_mismatch | segfault | 1/27 | - |
| `string_paths_hidden` | output_mismatch | segfault | 35/54 | 1/54 |
| `tab_ordering_custom_basic` | output_mismatch | segfault | 0/71 | - |
| `tab_ordering_custom_i32_vs_u32` | output_mismatch | segfault | 0/12 | - |
| `tab_ordering_custom_m1` | output_mismatch | segfault | 0/29 | - |
| `tab_ordering_events` | output_mismatch | segfault | 2/150 | - |
| `tab_ordering_events_mouse` | output_mismatch | segfault | 0/65 | - |
| `tab_ordering_properties` | output_mismatch | segfault | 5/293 | 2/293 |
| `tab_ordering_tabbable` | output_mismatch | segfault | 0/47 | - |
| `textfield_background_color` | output_mismatch | segfault | 8/11 | 1/11 |
| `textfield_border_color` | output_mismatch | segfault | 8/11 | 1/11 |
| `textfield_properties` | output_mismatch | segfault | 32/44 | 1/44 |
| `textfield_text` | output_mismatch | segfault | 6/7 | 1/7 |
| `textfield_variable` | output_mismatch | segfault | 54/81 | 1/81 |
| `use_hand_cursor` | output_mismatch | segfault | 6/8 | 1/8 |

## Line Count Changed (19)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `device_font_spacing` | segfault | 1/91 | - | -90 |
| `call` | output_mismatch | 0/63 | 4/63 | -4 |
| `frame_size_translated_positive` | output_mismatch | 6/21 | 10/21 | -4 |
| `goto_frame2` | output_mismatch | 4/44 | 8/44 | -4 |
| `frame_size_translated_negative` | output_mismatch | 7/21 | 10/21 | -3 |
| `conflicting_instance_names` | output_mismatch | 18/23 | 20/23 | -2 |
| `register_and_init_order` | output_mismatch | 29/231 | 31/231 | -2 |
| `function_base_clip` | output_mismatch | 0/8 | 1/8 | -1 |
| `closure_scope` | output_mismatch | 0/7 | 0/7 | 0 |
| `custom_clip_methods` | output_mismatch | 0/4 | 0/4 | 0 |
| `execution_order2` | output_mismatch | 5/7 | 5/7 | 0 |
| `execution_order4` | output_mismatch | 1/12 | 1/12 | 0 |
| `goto_frame` | output_mismatch | 3/12 | 3/12 | 0 |
| `goto_label` | output_mismatch | 2/17 | 2/17 | 0 |
| `target_clip_removed` | output_mismatch | 4/5 | 4/5 | 0 |
| `tell_target_invalid` | output_mismatch | 0/6 | 0/6 | 0 |
| `tell_target_invalid_swf6` | output_mismatch | 0/5 | 0/5 | 0 |
| `tell_target` | output_mismatch | 4/37 | 0/37 | +4 |
| `slash_syntax` | output_mismatch | 9/14 | 0/14 | +9 |
