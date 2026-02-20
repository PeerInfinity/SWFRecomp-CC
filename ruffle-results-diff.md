# Ruffle Test Results Diff

**Previous:** `3459c6f85006` (2026-02-20T00:50:39.972313+00:00)
**Current:** `6a95bcac32c7` (2026-02-20T02:09:54.909330+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 182 | 226 | +44 |
| Total | 619 | 619 | 0 |
| Pass rate | 29.4% | 36.5% | +7.1% |
| Mismatched lines | 20550 | 39737 | +19187 |
|   Decreased | | | -169 |
|   Increased | | | +19356 |

## Newly Passing (44)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `array_sort_random` | runtime_error | - | 443/443 |
| `bitmap_data_perlinnoise` | runtime_error | - | 0/0 |
| `bitmap_data_pixeldissolve_image` | runtime_error | - | 0/0 |
| `clone_sprite_types` | segfault | - | 24/24 |
| `color` | segfault | - | 57/57 |
| `define_function2_preload_order` | segfault | 2/4 | 4/4 |
| `display_object_properties` | segfault | - | 2/2 |
| `edittext_antialiastype` | segfault | - | 296/296 |
| `edittext_autosize_setter` | segfault | - | 20/20 |
| `edittext_default_format` | segfault | - | 221/221 |
| `edittext_default_format_empty` | segfault | - | 95/95 |
| `edittext_password` | segfault | - | 5/5 |
| `edittext_width_height` | segfault | - | 103/103 |
| `execution_order1` | segfault | 1/5 | 5/5 |
| `execution_order3` | segfault | 2/4 | 4/4 |
| `focusrect_mouse_swf8` | segfault | - | 0/0 |
| `focusrect_mouse_swf9` | segfault | - | 0/0 |
| `focusrect_swf5` | segfault | - | 6/6 |
| `function_suppress_and_preload` | runtime_error | - | 28/28 |
| `goto_execution_order2` | segfault | - | 2/2 |
| `goto_frame_number` | segfault | 1/3 | 3/3 |
| `issue_1671` | segfault | - | 0/0 |
| `issue_3446` | segfault | - | 1/1 |
| `issue_4377` | segfault | - | 2/2 |
| `mask_reapply` | segfault | - | 0/0 |
| `mask_with_drawing` | segfault | - | 0/0 |
| `movieclip_blend_mode_property` | segfault | - | 35/35 |
| `movieclip_get_instance_at_depth` | segfault | 9/28 | 28/28 |
| `netstream_play_flv_screen` | segfault | - | 0/0 |
| `set_variable_scope` | segfault | - | 58/58 |
| `string_methods_negative_args` | runtime_error | - | 240/240 |
| `swf7_case_sensitive` | segfault | - | 44/44 |
| `textfield_background_color` | segfault | - | 11/11 |
| `textfield_border_color` | segfault | - | 11/11 |
| `textfield_properties` | segfault | - | 44/44 |
| `textfield_text` | segfault | - | 7/7 |
| `typeof` | segfault | - | 22/22 |
| `use_hand_cursor` | segfault | - | 8/8 |
| `variable_args` | segfault | - | 5/5 |
| `waitforframe` | segfault | - | 7/7 |
| `waitforframe2` | segfault | - | 16/16 |
| `watch_virtual_property_proto` | runtime_error | - | 2/2 |
| `xml_reparenting` | runtime_error | - | 14/14 |
| `xml_unescaping` | runtime_error | - | 23/23 |

## Status Changed (196)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `as_transformed_flag` | segfault | output_mismatch | - | 14/20 |
| `asfunction` | segfault | output_mismatch | - | 0/11 |
| `asnew` | runtime_error | output_mismatch | - | 10/34 |
| `bitmap_data_pixeldissolve` | runtime_error | output_mismatch | - | 96/1075 |
| `bitmap_filters` | segfault | output_mismatch | - | 0/548 |
| `boxed_primitives` | runtime_error | output_mismatch | - | 23/24 |
| `button_children` | segfault | output_mismatch | - | 1/8 |
| `button_goto` | segfault | output_mismatch | - | 0/4 |
| `button_key_events` | segfault | output_mismatch | - | 0/14 |
| `button_key_events_special` | segfault | output_mismatch | - | 0/45 |
| `button_keypress_vs_press` | segfault | output_mismatch | - | 0/25 |
| `button_keypress_vs_tab` | segfault | output_mismatch | - | 0/20 |
| `button_keypress_vs_textinput` | segfault | output_mismatch | - | 0/4 |
| `button_properties_special_cases` | segfault | output_mismatch | - | 0/22 |
| `call` | segfault | output_mismatch | - | 4/63 |
| `click_block` | segfault | output_mismatch | - | 0/5 |
| `clip_events` | segfault | runtime_error | 1/19 | 1/19 |
| `clone_sprite_edittext` | segfault | output_mismatch | - | 24/94 |
| `closure_scope` | segfault | output_mismatch | - | 2/7 |
| `coerce_to_object_monkeypatch` | runtime_error | output_mismatch | - | 9/129 |
| `coerce_to_primitive_resolve` | runtime_error | output_mismatch | - | 7/17 |
| `conflicting_instance_names` | segfault | output_mismatch | - | 22/23 |
| `custom_clip_methods` | segfault | output_mismatch | - | 0/4 |
| `default_names` | segfault | runtime_error | - | 12/52 |
| `device_font_spacing` | segfault | output_mismatch | - | 1/91 |
| `do_init_action` | segfault | output_mismatch | 1/3 | 3/3 |
| `drag_drop` | segfault | output_mismatch | - | 0/10 |
| `drag_over_from_outside` | runtime_error | output_mismatch | - | 0/1 |
| `drag_over_without_startdrag` | runtime_error | output_mismatch | - | 0/1 |
| `duplicate_movie_clip` | segfault | output_mismatch | 0/20 | 1/20 |
| `edittext_align` | segfault | output_mismatch | - | 36/60 |
| `edittext_autosize` | segfault | output_mismatch | - | 44/71 |
| `edittext_bullet` | segfault | output_mismatch | - | 18/30 |
| `edittext_default_format_font_style` | segfault | output_mismatch | - | 315/335 |
| `edittext_drag_select` | segfault | output_mismatch | - | 0/9 |
| `edittext_font_size` | segfault | output_mismatch | - | 15/45 |
| `edittext_html_align_swf7` | segfault | output_mismatch | - | 42/52 |
| `edittext_html_align_swf8` | segfault | output_mismatch | - | 45/52 |
| `edittext_html_condensewhite_swf7` | segfault | output_mismatch | - | 174/311 |
| `edittext_html_condensewhite_swf8` | segfault | output_mismatch | - | 171/311 |
| `edittext_html_entity` | segfault | output_mismatch | - | 3/4 |
| `edittext_html_swf6` | segfault | output_mismatch | - | 2838/5377 |
| `edittext_html_swf7` | segfault | output_mismatch | - | 2466/5377 |
| `edittext_html_swf8` | segfault | output_mismatch | - | 2316/5377 |
| `edittext_input` | segfault | output_mismatch | - | 0/1 |
| `edittext_input_newlines` | segfault | output_mismatch | - | 0/9 |
| `edittext_leading` | segfault | output_mismatch | - | 3/9 |
| `edittext_letter_spacing` | segfault | output_mismatch | - | 9/15 |
| `edittext_margins` | segfault | output_mismatch | - | 15/25 |
| `edittext_newline_stripping` | segfault | output_mismatch | - | 23/64 |
| `edittext_newlines` | segfault | output_mismatch | - | 18/30 |
| `edittext_password_copy` | segfault | output_mismatch | - | 0/4 |
| `edittext_paste_empty` | segfault | output_mismatch | - | 0/2 |
| `edittext_place_caret` | segfault | output_mismatch | - | 0/2 |
| `edittext_programmatic_focus` | segfault | output_mismatch | - | 0/12 |
| `edittext_restrict` | segfault | output_mismatch | - | 0/191 |
| `edittext_restrict_paste` | segfault | output_mismatch | - | 0/5 |
| `edittext_scroll` | segfault | output_mismatch | - | 35/54 |
| `edittext_tab_focus` | segfault | output_mismatch | - | 0/13 |
| `edittext_tab_stops` | segfault | output_mismatch | - | 36/60 |
| `edittext_tag_indent` | segfault | output_mismatch | - | 7/31 |
| `edittext_underline` | segfault | output_mismatch | - | 24/40 |
| `execution_order2` | segfault | output_mismatch | 2/7 | 5/7 |
| `execution_order4` | segfault | output_mismatch | - | 3/12 |
| `extends_native_type` | segfault | output_mismatch | - | 10/11 |
| `file_reference_browse_cancel` | runtime_error | output_mismatch | - | 0/21 |
| `focus_keyboard_press` | segfault | output_mismatch | - | 0/60 |
| `focus_mouse` | segfault | output_mismatch | - | 0/45 |
| `focus_mouse_rollout` | segfault | output_mismatch | - | 0/4 |
| `focus_root_movie` | segfault | output_mismatch | - | 0/2 |
| `focusrect_focuslost` | segfault | output_mismatch | - | 0/4 |
| `focusrect_property_swf5` | segfault | output_mismatch | - | 269/1237 |
| `focusrect_property_swf6` | segfault | output_mismatch | - | 717/1237 |
| `focusrect_property_swf7` | segfault | output_mismatch | - | 718/1237 |
| `focusrect_swf6` | segfault | output_mismatch | - | 0/42 |
| `frame_size_translated_negative` | segfault | output_mismatch | - | 14/21 |
| `frame_size_translated_positive` | segfault | output_mismatch | - | 14/21 |
| `function_base_clip` | segfault | output_mismatch | - | 1/8 |
| `function_base_clip_readded` | segfault | runtime_error | - | - |
| `function_base_clip_removed` | segfault | output_mismatch | - | 1/25 |
| `funky_function_calls` | segfault | output_mismatch | - | 3/56 |
| `get_bytes_total` | segfault | output_mismatch | - | 0/4 |
| `global_swf6_7_8` | runtime_error | output_mismatch | - | 0/15 |
| `goto_advance1` | segfault | output_mismatch | - | 1/6 |
| `goto_advance2` | segfault | output_mismatch | - | 2/2 |
| `goto_both_ways1` | segfault | output_mismatch | 1/3 | 2/3 |
| `goto_both_ways2` | segfault | output_mismatch | - | 1/3 |
| `goto_frame` | segfault | output_mismatch | - | 3/12 |
| `goto_frame2` | segfault | output_mismatch | - | 8/44 |
| `goto_label` | segfault | output_mismatch | - | 2/17 |
| `goto_rewind1` | segfault | output_mismatch | - | 1/1 |
| `goto_rewind2` | segfault | output_mismatch | - | 3/3 |
| `goto_rewind3` | segfault | output_mismatch | 1/2 | 2/2 |
| `hittest_lockroot` | runtime_error | output_mismatch | - | 6/15 |
| `hittest_morph` | segfault | output_mismatch | - | 15/70 |
| `hittest_morph_input` | segfault | output_mismatch | - | 0/1 |
| `hittest_winding_rule` | runtime_error | output_mismatch | - | 6/12 |
| `input_dead_keys_windows` | segfault | output_mismatch | - | 0/15 |
| `instanceof_coercions` | runtime_error | output_mismatch | - | 13/88 |
| `interface_implements_op` | runtime_error | output_mismatch | - | 0/47 |
| `issue_1104` | segfault | output_mismatch | - | 1/2 |
| `issue_1906` | segfault | output_mismatch | - | 2/4 |
| `issue_2870` | segfault | output_mismatch | 1/3 | 2/3 |
| `issue_3169` | runtime_error | output_mismatch | - | 0/2 |
| `issue_3522` | segfault | output_mismatch | - | 1/2 |
| `issue_9327` | runtime_error | output_mismatch | - | 0/2 |
| `issue_9885` | segfault | output_mismatch | - | 1/2 |
| `loadmovie_fail` | runtime_error | output_mismatch | - | 1/2 |
| `loadmovie_replace_root` | segfault | output_mismatch | - | 0/5 |
| `loadmovienum_cross_version_prototype` | runtime_error | output_mismatch | - | 1/9 |
| `loadvariables_method` | segfault | output_mismatch | - | 0/7 |
| `local_to_global` | segfault | output_mismatch | - | 41/49 |
| `math_swf6` | runtime_error | output_mismatch | - | 522/530 |
| `math_swf7` | runtime_error | output_mismatch | - | 522/530 |
| `math_swf8` | runtime_error | output_mismatch | - | 522/530 |
| `mcl_loadclip_properties` | runtime_error | output_mismatch | - | 0/6 |
| `mcl_loadclip_replace_root` | runtime_error | output_mismatch | - | 0/1 |
| `mouse_events` | segfault | output_mismatch | - | 0/8 |
| `mouse_events_visible_enabled` | segfault | output_mismatch | - | 0/12 |
| `mouse_hover_events_while_dragging` | runtime_error | output_mismatch | - | 0/1 |
| `mouse_pos` | segfault | output_mismatch | - | 0/665 |
| `mouse_pos_with_scale_factor` | segfault | output_mismatch | - | 0/260 |
| `movieclip_depth_methods` | segfault | runtime_error | 2/98 | 90/98 |
| `movieclip_getbounds` | segfault | output_mismatch | - | 45/191 |
| `movieclip_gettextsnapshot` | segfault | output_mismatch | - | 4/112 |
| `movieclip_hittest` | segfault | output_mismatch | - | 71/92 |
| `movieclip_hittest_shapeflag` | segfault | runtime_error | - | 61/338 |
| `movieclip_in_removed_button` | segfault | output_mismatch | - | 0/4 |
| `movieclip_name_from_timeline` | segfault | output_mismatch | - | 12/13 |
| `native_double_construct` | runtime_error | output_mismatch | - | 5/12 |
| `native_objects_swf6` | segfault | output_mismatch | - | 0/84 |
| `native_objects_swf7` | segfault | output_mismatch | - | 0/84 |
| `native_objects_swf8` | segfault | output_mismatch | - | 0/84 |
| `native_subclasses` | runtime_error | output_mismatch | - | 9/191 |
| `netstream_play_flv` | segfault | output_mismatch | - | 0/21 |
| `object_resolve` | runtime_error | output_mismatch | - | 0/38 |
| `on_construct` | segfault | output_mismatch | - | 0/25 |
| `path_string` | segfault | output_mismatch | - | 49/322 |
| `place_and_lookup` | segfault | output_mismatch | - | 10/30 |
| `placeobject_occupied_depth` | timeout | runtime_error | - | 1/6 |
| `register_and_init_order` | segfault | output_mismatch | 14/231 | 30/231 |
| `register_class_return_value` | runtime_error | output_mismatch | - | 6/16 |
| `register_class_with_sound` | runtime_error | output_mismatch | - | 1/11 |
| `remove_movie_clip` | segfault | output_mismatch | - | 19/29 |
| `removed_base_clip_tell_target` | segfault | output_mismatch | - | 0/2 |
| `removed_clip_halts_script` | segfault | output_mismatch | - | 1/15 |
| `rewind_depth` | segfault | output_mismatch | - | 26/30 |
| `root_global_parent` | segfault | output_mismatch | - | 1/6 |
| `selection` | segfault | output_mismatch | - | 42/454 |
| `selection_handlers` | segfault | output_mismatch | - | 1/27 |
| `slash_syntax` | segfault | output_mismatch | - | 0/14 |
| `sound` | segfault | output_mismatch | - | 160/628 |
| `stage_object_children` | segfault | output_mismatch | - | 68/83 |
| `stage_object_enumerate` | segfault | output_mismatch | - | 1/4 |
| `stage_object_properties` | segfault | output_mismatch | - | 131/241 |
| `stage_object_properties_swf6` | segfault | output_mismatch | - | 131/231 |
| `string_paths_hidden` | segfault | output_mismatch | - | 36/54 |
| `super_edge_cases` | runtime_error | output_mismatch | - | 7/39 |
| `swf5_no_closure` | segfault | output_mismatch | - | 8/19 |
| `swf5_to_6_cross_call` | segfault | output_mismatch | - | 0/29 |
| `swf6_case_insensitive` | segfault | output_mismatch | - | 28/42 |
| `swf6_to_5_cross_call` | segfault | output_mismatch | - | 0/29 |
| `tab_ordering_automatic_basic` | segfault | output_mismatch | - | 0/92 |
| `tab_ordering_automatic_order_grid` | segfault | output_mismatch | - | 0/21 |
| `tab_ordering_automatic_order_same_position` | segfault | output_mismatch | - | 0/12 |
| `tab_ordering_children` | segfault | output_mismatch | - | 0/208 |
| `tab_ordering_custom_basic` | segfault | output_mismatch | - | 0/71 |
| `tab_ordering_custom_duplicate_index` | segfault | output_mismatch | - | 0/22 |
| `tab_ordering_custom_i32_vs_u32` | segfault | output_mismatch | - | 0/12 |
| `tab_ordering_custom_m1` | segfault | output_mismatch | - | 0/29 |
| `tab_ordering_events` | segfault | output_mismatch | - | 2/150 |
| `tab_ordering_events_mouse` | segfault | output_mismatch | - | 0/65 |
| `tab_ordering_movieclip_enabled_default` | segfault | output_mismatch | - | 0/462 |
| `tab_ordering_properties` | segfault | output_mismatch | - | 156/293 |
| `tab_ordering_reverse` | segfault | output_mismatch | - | 0/51 |
| `tab_ordering_tabbable` | segfault | output_mismatch | - | 0/47 |
| `target_clip_removed` | segfault | output_mismatch | - | 4/5 |
| `target_clip_swf5` | segfault | output_mismatch | - | 0/2 |
| `target_clip_swf6` | segfault | output_mismatch | - | 0/2 |
| `target_path` | segfault | output_mismatch | - | 11/14 |
| `tell_target` | segfault | output_mismatch | - | 0/37 |
| `tell_target_invalid` | segfault | output_mismatch | - | 0/6 |
| `tell_target_invalid_swf6` | segfault | output_mismatch | - | 0/5 |
| `text_blocks_clicks` | segfault | output_mismatch | - | 0/4 |
| `textfield_variable` | segfault | output_mismatch | - | 78/81 |
| `textsnapshot_available_text` | segfault | output_mismatch | - | 10/20 |
| `this_scoping` | segfault | output_mismatch | 15/52 | 42/52 |
| `transform` | segfault | output_mismatch | - | 63/70 |
| `unload` | segfault | output_mismatch | - | 13/52 |
| `unload_clip_event` | segfault | output_mismatch | - | 2/4 |
| `unload_nested_child` | segfault | output_mismatch | - | 0/5 |
| `with` | segfault | output_mismatch | - | 46/49 |
| `xml_socket` | runtime_error | output_mismatch | - | 1/8 |
| `xml_socket_close_in_handler` | runtime_error | output_mismatch | - | 0/6 |
| `xml_socket_on_data` | runtime_error | output_mismatch | - | 0/7 |
| `xml_socket_segmented` | runtime_error | output_mismatch | - | 0/29 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `goto_methods` | segfault | - | 8/40 | +32 |
