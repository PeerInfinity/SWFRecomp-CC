# Ruffle Test Results Diff

**Previous:** `2abe0b4e90e3` (2026-02-22T23:45:00.336430+00:00)
**Current:** `ead961fbbf43` (2026-02-22T23:54:26.198884+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 288 | 306 | +18 |
| Total | 619 | 619 | 0 |
| Pass rate | 46.5% | 49.4% | +2.9% |
| Mismatched lines | 36539 | 35256 | -1283 |
|   Decreased | | | -1283 |

## Newly Passing (19)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `button_goto` | output_mismatch | 0/4 | 4/4 |
| `drag_drop` | output_mismatch | 0/10 | 10/10 |
| `drag_over_from_outside` | output_mismatch | 0/1 | 1/1 |
| `drag_over_without_startdrag` | output_mismatch | 0/1 | 1/1 |
| `edittext_password_copy` | output_mismatch | 0/4 | 4/4 |
| `edittext_paste_empty` | output_mismatch | 0/2 | 2/2 |
| `edittext_restrict_paste` | output_mismatch | 0/5 | 5/5 |
| `focusrect_swf6` | output_mismatch | 0/42 | 42/42 |
| `key_isToggled` | output_mismatch | 0/9 | 9/9 |
| `mouse_events` | output_mismatch | 0/8 | 8/8 |
| `mouse_hover_events_while_dragging` | output_mismatch | 0/1 | 1/1 |
| `tab_ordering_automatic_basic` | output_mismatch | 3/92 | 92/92 |
| `tab_ordering_automatic_order_grid` | output_mismatch | 0/21 | 21/21 |
| `tab_ordering_children` | output_mismatch | 3/208 | 208/208 |
| `tab_ordering_custom_basic` | output_mismatch | 3/71 | 71/71 |
| `tab_ordering_custom_duplicate_index` | output_mismatch | 0/22 | 22/22 |
| `tab_ordering_custom_i32_vs_u32` | output_mismatch | 0/12 | 12/12 |
| `tab_ordering_custom_m1` | output_mismatch | 0/29 | 29/29 |
| `tab_ordering_reverse` | output_mismatch | 3/51 | 51/51 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `string_paths_keyevents` | output_mismatch | 0/0 | 0/0 |

## Line Count Changed (23)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `mouse_pos` | output_mismatch | 0/665 | 291/665 | -291 |
| `edittext_restrict` | output_mismatch | 0/191 | 147/191 | -147 |
| `mouse_pos_with_scale_factor` | output_mismatch | 0/260 | 111/260 | -111 |
| `tab_ordering_movieclip_enabled_default` | output_mismatch | 3/462 | 63/462 | -60 |
| `tab_ordering_tabbable` | output_mismatch | 0/47 | 36/47 | -36 |
| `button_properties_special_cases` | output_mismatch | 0/22 | 14/22 | -14 |
| `edittext_tab_focus` | output_mismatch | 0/13 | 9/13 | -9 |
| `tab_ordering_automatic_order_same_position` | output_mismatch | 0/12 | 9/12 | -9 |
| `edittext_drag_select` | output_mismatch | 0/9 | 6/9 | -6 |
| `input_dead_keys_windows` | output_mismatch | 0/15 | 5/15 | -5 |
| `mouse_events_visible_enabled` | output_mismatch | 0/12 | 3/12 | -3 |
| `tab_ordering_events_mouse` | output_mismatch | 0/65 | 3/65 | -3 |
| `focus_keyboard_press` | output_mismatch | 1/60 | 3/60 | -2 |
| `tab_ordering_events` | output_mismatch | 17/150 | 19/150 | -2 |
| `button_keypress` | output_mismatch | 0/3 | 1/3 | -1 |
| `button_keypress_vs_tab` | output_mismatch | 1/20 | 2/20 | -1 |
| `button_keypress_vs_textinput` | output_mismatch | 0/4 | 1/4 | -1 |
| `edittext_place_caret` | output_mismatch | 0/2 | 1/2 | -1 |
| `button_key_events_special` | output_mismatch | 0/45 | 0/45 | 0 |
| `button_keypress_vs_press` | output_mismatch | 0/25 | 0/25 | 0 |
| `edittext_input_newlines` | output_mismatch | 0/9 | 0/9 | 0 |
| `focus_mouse` | output_mismatch | 0/45 | 0/45 | 0 |
| `focusrect_focuslost` | output_mismatch | 0/4 | 0/4 | 0 |
