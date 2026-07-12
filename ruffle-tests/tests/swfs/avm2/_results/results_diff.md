# Ruffle Test Results Diff

**Previous:** `2efd025eaf82` (2026-07-12T21:26:25.066771+00:00)
**Current:** `ee21078608de` (2026-07-12T23:36:18.573854+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 754 | 800 | +46 |
| Total | 1204 | 1204 | 0 |
| Pass rate | 62.6% | 66.4% | +3.8% |
| Mismatched lines | 59923 | 51964 | -7959 |
|   Decreased | | | -7960 |
|   Increased | | | +1 |

## Newly Passing (47)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `asymmetric_key_events` | output_mismatch | 0/11 | 11/11 |
| `avm2_catchup_dobj` | output_mismatch | 0/158 | 158/158 |
| `click_block` | output_mismatch | 0/5 | 5/5 |
| `click_invisible` | output_mismatch | 0/3 | 3/3 |
| `drag_drop` | output_mismatch | 0/10 | 10/10 |
| `edittext_at_point_methods_basic` | output_mismatch | 0/16 | 16/16 |
| `edittext_input_control` | output_mismatch | 0/12 | 12/12 |
| `edittext_mousedown` | output_mismatch | 0/3 | 3/3 |
| `edittext_newline_character` | output_mismatch | 0/22 | 22/22 |
| `edittext_paste_events` | output_mismatch | 0/8 | 8/8 |
| `edittext_paste_maxchars` | output_mismatch | 0/4 | 4/4 |
| `edittext_paste_restrict` | output_mismatch | 0/16 | 16/16 |
| `edittext_restrict` | output_mismatch | 0/191 | 191/191 |
| `edittext_restrict_events` | output_mismatch | 0/22 | 22/22 |
| `edittext_selected_text` | output_mismatch | 0/9 | 9/9 |
| `focus_events_code` | output_mismatch | 0/161 | 161/161 |
| `focus_events_key_same_object` | output_mismatch | 0/26 | 26/26 |
| `focus_events_mixed_key_mouse` | output_mismatch | 0/100 | 100/100 |
| `focus_events_mouse_same_object` | output_mismatch | 0/40 | 40/40 |
| `focus_root_movie` | output_mismatch | 0/4 | 4/4 |
| `focus_stage` | output_mismatch | 0/1 | 1/1 |
| `focusrect` | output_mismatch | 0/18 | 18/18 |
| `issue_17675_edittext_paste_maxchars` | output_mismatch | 0/1 | 1/1 |
| `key_input_80percent` | output_mismatch | 0/1812 | 1812/1812 |
| `key_input_location` | output_mismatch | 0/126 | 126/126 |
| `key_input_numpad` | output_mismatch | 0/384 | 384/384 |
| `mouse_click_events` | output_mismatch | 0/90 | 90/90 |
| `mouse_double_click_events` | output_mismatch | 0/188 | 188/188 |
| `mouse_empty_parent` | output_mismatch | 0/4 | 4/4 |
| `mouse_over_while_dragging` | output_mismatch | 0/3 | 3/3 |
| `mouse_pick_button_mode` | output_mismatch | 0/2 | 2/2 |
| `mouse_sibling` | output_mismatch | 0/8 | 8/8 |
| `movieclip_displayevents_clickgoto` | output_mismatch | 54/676 | 676/676 |
| `movieclip_displayevents_clickgoto2` | output_mismatch | 65/2001 | 2001/2001 |
| `movieclip_displayevents_clickplay` | output_mismatch | 24/575 | 575/575 |
| `movieclip_displayevents_clicksymbol` | output_mismatch | 59/562 | 562/562 |
| `movieclip_drawrect` | output_mismatch | 8/54 | 54/54 |
| `movieclip_text_mousedown` | output_mismatch | 0/1 | 1/1 |
| `package_namespace` | output_mismatch | 0/7 | 7/7 |
| `stage_mousechildren` | output_mismatch | 0/2 | 2/2 |
| `swf_9_versioning` | output_mismatch | 0/2 | 2/2 |
| `tab_ordering_automatic_advanced` | output_mismatch | 1/184 | 184/184 |
| `tab_ordering_automatic_basic` | output_mismatch | 0/45 | 45/45 |
| `tab_ordering_children` | output_mismatch | 0/116 | 116/116 |
| `tab_ordering_custom_basic` | output_mismatch | 0/34 | 34/34 |
| `textfield_focusin_event` | output_mismatch | 0/9 | 9/9 |
| `textfield_input_dead_keys_windows` | output_mismatch | 0/15 | 15/15 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `edittext_autosize_lazy_bounds_interactions` | output_mismatch | 19/19 | 18/19 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `sprite_dropTarget` | output_mismatch | ruffle_matched | 0/19 | 15/19 |

## Line Count Changed (31)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `mouse_children` | output_mismatch | 0/192 | 114/192 | -114 |
| `mouseevent_constr` | output_mismatch | 1/66 | 62/66 | -61 |
| `focus_events_mouse_focusable` | output_mismatch | 0/112 | 51/112 | -51 |
| `tab_ordering_tabbable` | output_mismatch | 0/47 | 45/47 | -45 |
| `focus_events_mouse_basic` | output_mismatch | 0/260 | 30/260 | -30 |
| `mouse_wheel_events` | output_mismatch | 0/36 | 29/36 | -29 |
| `mouseevent_valueof_tostring` | output_mismatch | 1/28 | 24/28 | -23 |
| `focus_events_key_basic` | output_mismatch | 0/132 | 17/132 | -17 |
| `tab_ordering_stage_tab_children` | output_mismatch | 5/32 | 15/32 | -10 |
| `focus_events_key_navigation` | output_mismatch | 0/53 | 9/53 | -9 |
| `textfield_input_events` | output_mismatch | 0/25 | 9/25 | -9 |
| `focusrect_focuslost` | output_mismatch | 0/9 | 7/9 | -7 |
| `edittext_mouse_selection` | output_mismatch | 0/363 | 2/363 | -2 |
| `mouse_pick_dobj_mask` | output_mismatch | 0/4 | 2/4 | -2 |
| `mouse_pick_non_interactive_bitmap_mask` | output_mismatch | 0/4 | 2/4 | -2 |
| `all_classes/events/swf9` | output_mismatch | 1/1030 | 2/1030 | -1 |
| `focus_events_mixed_avm_edittext` | output_mismatch | 0/49 | 1/49 | -1 |
| `mouse_pick_avm1_root` | output_mismatch | 0/2 | 1/2 | -1 |
| `textbox_click` | output_mismatch | 0/37 | 1/37 | -1 |
| `all_classes/events/swf10` | output_mismatch | 1/1638 | 1/1638 | 0 |
| `all_classes/events/swf11` | output_mismatch | 1/1750 | 1/1750 | 0 |
| `all_classes/events/swf12` | output_mismatch | 1/1814 | 1/1814 | 0 |
| `all_classes/events/swf30` | output_mismatch | 0/2353 | 0/2353 | 0 |
| `ime_linux_dead_keys` | output_mismatch | 0/10 | 0/10 | 0 |
| `loader_noninteractive_try_click_root` | output_mismatch | 0/5 | 0/5 | 0 |
| `loader_try_click_root` | output_mismatch | 0/16 | 0/16 | 0 |
| `mouse_pick_masking` | output_mismatch | 0/7 | 0/7 | 0 |
| `mouse_pick_non_interactive_dobj_mask` | output_mismatch | 0/3 | 0/3 | 0 |
| `mouse_pick_text` | output_mismatch | 4/8 | 4/8 | 0 |
| `mouseevent_stagexy` | output_mismatch | 1/35 | 1/35 | 0 |
| `stage_scale_factor` | output_mismatch | 6/12 | 6/12 | 0 |
