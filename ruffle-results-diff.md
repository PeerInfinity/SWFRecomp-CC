# Ruffle Test Results Diff

**Previous:** `1ce1d3956efe` (2026-02-19T22:50:09.298438+00:00)
**Current:** `3459c6f85006` (2026-02-20T00:50:39.972313+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 242 | 182 | -60 |
| Total | 619 | 619 | 0 |
| Pass rate | 39.1% | 29.4% | -9.7% |
| Mismatched lines | 39381 | 20550 | -18831 |
|   Decreased | | | -19026 |
|   Increased | | | +195 |

## Newly Failing (60)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `array_sort_random` | runtime_error | 443/443 | - |
| `as_transformed_flag` | segfault | 20/20 | - |
| `bitmap_data_perlinnoise` | runtime_error | 0/0 | - |
| `bitmap_data_pixeldissolve_image` | runtime_error | 0/0 | - |
| `clone_sprite_types` | segfault | 24/24 | - |
| `color` | segfault | 57/57 | - |
| `conflicting_instance_names` | segfault | 23/23 | - |
| `define_function2_preload_order` | segfault | 4/4 | 2/4 |
| `display_object_properties` | segfault | 2/2 | - |
| `do_init_action` | segfault | 3/3 | 1/3 |
| `duplicate_movie_clip` | segfault | 20/20 | 0/20 |
| `edittext_antialiastype` | segfault | 296/296 | - |
| `edittext_autosize_setter` | segfault | 20/20 | - |
| `edittext_default_format` | segfault | 221/221 | - |
| `edittext_default_format_empty` | segfault | 95/95 | - |
| `edittext_default_format_font_style` | segfault | 335/335 | - |
| `edittext_password` | segfault | 5/5 | - |
| `edittext_width_height` | segfault | 103/103 | - |
| `execution_order1` | segfault | 5/5 | 1/5 |
| `execution_order2` | segfault | 7/7 | 2/7 |
| `execution_order3` | segfault | 4/4 | 2/4 |
| `focusrect_mouse_swf8` | segfault | 0/0 | - |
| `focusrect_mouse_swf9` | segfault | 0/0 | - |
| `focusrect_swf5` | segfault | 6/6 | - |
| `function_suppress_and_preload` | runtime_error | 28/28 | - |
| `goto_advance1` | segfault | 6/6 | - |
| `goto_advance2` | segfault | 2/2 | - |
| `goto_both_ways1` | segfault | 3/3 | 1/3 |
| `goto_both_ways2` | segfault | 3/3 | - |
| `goto_execution_order2` | segfault | 2/2 | - |
| `goto_frame_number` | segfault | 3/3 | 1/3 |
| `goto_rewind1` | segfault | 1/1 | - |
| `goto_rewind2` | segfault | 3/3 | - |
| `goto_rewind3` | segfault | 2/2 | 1/2 |
| `issue_1671` | segfault | 0/0 | - |
| `issue_3446` | segfault | 1/1 | - |
| `issue_4377` | segfault | 2/2 | - |
| `mask_reapply` | segfault | 0/0 | - |
| `mask_with_drawing` | segfault | 0/0 | - |
| `movieclip_blend_mode_property` | segfault | 35/35 | - |
| `movieclip_get_instance_at_depth` | segfault | 28/28 | 9/28 |
| `movieclip_name_from_timeline` | segfault | 13/13 | - |
| `netstream_play_flv_screen` | segfault | 0/0 | - |
| `set_variable_scope` | segfault | 58/58 | - |
| `stage_object_enumerate` | segfault | 4/4 | - |
| `string_methods_negative_args` | runtime_error | 240/240 | - |
| `swf7_case_sensitive` | segfault | 44/44 | - |
| `textfield_background_color` | segfault | 11/11 | - |
| `textfield_border_color` | segfault | 11/11 | - |
| `textfield_properties` | segfault | 44/44 | - |
| `textfield_text` | segfault | 7/7 | - |
| `transform` | segfault | 70/70 | - |
| `typeof` | segfault | 22/22 | - |
| `use_hand_cursor` | segfault | 8/8 | - |
| `variable_args` | segfault | 5/5 | - |
| `waitforframe` | segfault | 7/7 | - |
| `waitforframe2` | segfault | 16/16 | - |
| `watch_virtual_property_proto` | runtime_error | 2/2 | - |
| `xml_reparenting` | runtime_error | 14/14 | - |
| `xml_unescaping` | runtime_error | 23/23 | - |

## Status Changed (179)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `asfunction` | output_mismatch | segfault | 0/11 | - |
| `asnew` | output_mismatch | runtime_error | 10/34 | - |
| `bitmap_data_pixeldissolve` | output_mismatch | runtime_error | 96/1075 | - |
| `bitmap_filters` | output_mismatch | segfault | 0/548 | - |
| `boxed_primitives` | output_mismatch | runtime_error | 23/24 | - |
| `button_children` | output_mismatch | segfault | 1/8 | - |
| `button_goto` | output_mismatch | segfault | 0/4 | - |
| `button_key_events` | output_mismatch | segfault | 0/14 | - |
| `button_key_events_special` | output_mismatch | segfault | 0/45 | - |
| `button_keypress_vs_press` | output_mismatch | segfault | 0/25 | - |
| `button_keypress_vs_tab` | output_mismatch | segfault | 0/20 | - |
| `button_keypress_vs_textinput` | output_mismatch | segfault | 0/4 | - |
| `button_properties_special_cases` | output_mismatch | segfault | 0/22 | - |
| `call` | output_mismatch | segfault | 4/63 | - |
| `click_block` | output_mismatch | segfault | 0/5 | - |
| `clone_sprite_edittext` | output_mismatch | segfault | 24/94 | - |
| `closure_scope` | output_mismatch | segfault | 2/7 | - |
| `coerce_to_object_monkeypatch` | output_mismatch | runtime_error | 9/129 | - |
| `coerce_to_primitive_resolve` | output_mismatch | runtime_error | 7/17 | - |
| `custom_clip_methods` | output_mismatch | segfault | 0/4 | - |
| `default_names` | output_mismatch | segfault | 15/52 | - |
| `device_font_spacing` | output_mismatch | segfault | 1/91 | - |
| `drag_drop` | output_mismatch | segfault | 0/10 | - |
| `drag_over_from_outside` | output_mismatch | runtime_error | 0/1 | - |
| `drag_over_without_startdrag` | output_mismatch | runtime_error | 0/1 | - |
| `edittext_align` | output_mismatch | segfault | 36/60 | - |
| `edittext_autosize` | output_mismatch | segfault | 44/71 | - |
| `edittext_bullet` | output_mismatch | segfault | 18/30 | - |
| `edittext_drag_select` | output_mismatch | segfault | 0/9 | - |
| `edittext_font_size` | output_mismatch | segfault | 15/45 | - |
| `edittext_html_align_swf7` | output_mismatch | segfault | 42/52 | - |
| `edittext_html_align_swf8` | output_mismatch | segfault | 45/52 | - |
| `edittext_html_condensewhite_swf7` | output_mismatch | segfault | 174/311 | - |
| `edittext_html_condensewhite_swf8` | output_mismatch | segfault | 171/311 | - |
| `edittext_html_entity` | output_mismatch | segfault | 3/4 | - |
| `edittext_html_swf6` | output_mismatch | segfault | 2838/5377 | - |
| `edittext_html_swf7` | output_mismatch | segfault | 2466/5377 | - |
| `edittext_html_swf8` | output_mismatch | segfault | 2316/5377 | - |
| `edittext_input` | output_mismatch | segfault | 0/1 | - |
| `edittext_input_newlines` | output_mismatch | segfault | 0/9 | - |
| `edittext_leading` | output_mismatch | segfault | 3/9 | - |
| `edittext_letter_spacing` | output_mismatch | segfault | 9/15 | - |
| `edittext_margins` | output_mismatch | segfault | 15/25 | - |
| `edittext_newline_stripping` | output_mismatch | segfault | 23/64 | - |
| `edittext_newlines` | output_mismatch | segfault | 18/30 | - |
| `edittext_password_copy` | output_mismatch | segfault | 0/4 | - |
| `edittext_paste_empty` | output_mismatch | segfault | 0/2 | - |
| `edittext_place_caret` | output_mismatch | segfault | 0/2 | - |
| `edittext_programmatic_focus` | output_mismatch | segfault | 0/12 | - |
| `edittext_restrict` | output_mismatch | segfault | 0/191 | - |
| `edittext_restrict_paste` | output_mismatch | segfault | 0/5 | - |
| `edittext_scroll` | output_mismatch | segfault | 35/54 | - |
| `edittext_tab_focus` | output_mismatch | segfault | 0/13 | - |
| `edittext_tab_stops` | output_mismatch | segfault | 36/60 | - |
| `edittext_tag_indent` | output_mismatch | segfault | 7/31 | - |
| `edittext_underline` | output_mismatch | segfault | 24/40 | - |
| `execution_order4` | output_mismatch | segfault | 2/12 | - |
| `extends_native_type` | output_mismatch | segfault | 10/11 | - |
| `file_reference_browse_cancel` | output_mismatch | runtime_error | 0/21 | - |
| `focus_keyboard_press` | output_mismatch | segfault | 0/60 | - |
| `focus_mouse` | output_mismatch | segfault | 0/45 | - |
| `focus_mouse_rollout` | output_mismatch | segfault | 0/4 | - |
| `focus_root_movie` | output_mismatch | segfault | 0/2 | - |
| `focusrect_focuslost` | output_mismatch | segfault | 0/4 | - |
| `focusrect_property_swf5` | output_mismatch | segfault | 269/1237 | - |
| `focusrect_property_swf6` | output_mismatch | segfault | 717/1237 | - |
| `focusrect_property_swf7` | output_mismatch | segfault | 718/1237 | - |
| `focusrect_swf6` | output_mismatch | segfault | 0/42 | - |
| `frame_size_translated_negative` | output_mismatch | segfault | 20/21 | - |
| `frame_size_translated_positive` | output_mismatch | segfault | 20/21 | - |
| `function_base_clip` | output_mismatch | segfault | 1/8 | - |
| `function_base_clip_readded` | output_mismatch | segfault | 0/11 | - |
| `function_base_clip_removed` | output_mismatch | segfault | 1/25 | - |
| `funky_function_calls` | output_mismatch | segfault | 3/56 | - |
| `get_bytes_total` | output_mismatch | segfault | 0/4 | - |
| `global_swf6_7_8` | output_mismatch | runtime_error | 0/15 | - |
| `goto_frame` | output_mismatch | segfault | 3/12 | - |
| `goto_frame2` | output_mismatch | segfault | 8/44 | - |
| `goto_label` | output_mismatch | segfault | 2/17 | - |
| `hittest_lockroot` | output_mismatch | runtime_error | 6/15 | - |
| `hittest_morph` | output_mismatch | segfault | 15/70 | - |
| `hittest_morph_input` | output_mismatch | segfault | 0/1 | - |
| `hittest_winding_rule` | output_mismatch | runtime_error | 6/12 | - |
| `input_dead_keys_windows` | output_mismatch | segfault | 0/15 | - |
| `instanceof_coercions` | output_mismatch | runtime_error | 13/88 | - |
| `interface_implements_op` | output_mismatch | runtime_error | 0/47 | - |
| `issue_1104` | output_mismatch | segfault | 0/2 | - |
| `issue_1906` | output_mismatch | segfault | 2/4 | - |
| `issue_2870` | output_mismatch | segfault | 1/3 | 1/3 |
| `issue_3169` | output_mismatch | runtime_error | 0/2 | - |
| `issue_3522` | output_mismatch | segfault | 1/2 | - |
| `issue_9327` | output_mismatch | runtime_error | 0/2 | - |
| `issue_9885` | output_mismatch | segfault | 1/2 | - |
| `loadmovie_fail` | output_mismatch | runtime_error | 1/2 | - |
| `loadmovie_replace_root` | output_mismatch | segfault | 0/5 | - |
| `loadmovienum_cross_version_prototype` | output_mismatch | runtime_error | 1/9 | - |
| `loadvariables_method` | output_mismatch | segfault | 0/7 | - |
| `local_to_global` | output_mismatch | segfault | 41/49 | - |
| `math_swf6` | output_mismatch | runtime_error | 522/530 | - |
| `math_swf7` | output_mismatch | runtime_error | 522/530 | - |
| `math_swf8` | output_mismatch | runtime_error | 522/530 | - |
| `mcl_loadclip_properties` | output_mismatch | runtime_error | 0/6 | - |
| `mcl_loadclip_replace_root` | output_mismatch | runtime_error | 0/1 | - |
| `mouse_events` | output_mismatch | segfault | 0/8 | - |
| `mouse_events_visible_enabled` | output_mismatch | segfault | 0/12 | - |
| `mouse_hover_events_while_dragging` | output_mismatch | runtime_error | 0/1 | - |
| `mouse_pos` | output_mismatch | segfault | 0/665 | - |
| `mouse_pos_with_scale_factor` | output_mismatch | segfault | 0/260 | - |
| `movieclip_depth_methods` | output_mismatch | segfault | 94/98 | 2/98 |
| `movieclip_getbounds` | output_mismatch | segfault | 45/191 | - |
| `movieclip_gettextsnapshot` | output_mismatch | segfault | 4/112 | - |
| `movieclip_hittest` | output_mismatch | segfault | 71/92 | - |
| `movieclip_hittest_shapeflag` | output_mismatch | segfault | 180/338 | - |
| `movieclip_in_removed_button` | output_mismatch | segfault | 0/4 | - |
| `native_double_construct` | output_mismatch | runtime_error | 5/12 | - |
| `native_objects_swf6` | output_mismatch | segfault | 0/84 | - |
| `native_objects_swf7` | output_mismatch | segfault | 0/84 | - |
| `native_objects_swf8` | output_mismatch | segfault | 0/84 | - |
| `native_subclasses` | output_mismatch | runtime_error | 9/191 | - |
| `netstream_play_flv` | output_mismatch | segfault | 0/21 | - |
| `object_resolve` | output_mismatch | runtime_error | 0/38 | - |
| `on_construct` | output_mismatch | segfault | 0/25 | - |
| `path_string` | output_mismatch | segfault | 49/322 | - |
| `place_and_lookup` | output_mismatch | segfault | 0/30 | - |
| `placeobject_occupied_depth` | output_mismatch | timeout | 0/6 | - |
| `register_and_init_order` | output_mismatch | segfault | 31/231 | 14/231 |
| `register_class_return_value` | output_mismatch | runtime_error | 6/16 | - |
| `register_class_with_sound` | output_mismatch | runtime_error | 1/11 | - |
| `remove_movie_clip` | output_mismatch | segfault | 21/29 | - |
| `removed_base_clip_tell_target` | output_mismatch | segfault | 0/2 | - |
| `removed_clip_halts_script` | output_mismatch | segfault | 1/15 | - |
| `rewind_depth` | output_mismatch | segfault | 26/30 | - |
| `root_global_parent` | output_mismatch | segfault | 1/6 | - |
| `selection` | output_mismatch | segfault | 42/454 | - |
| `selection_handlers` | output_mismatch | segfault | 1/27 | - |
| `slash_syntax` | output_mismatch | segfault | 0/14 | - |
| `sound` | output_mismatch | segfault | 160/628 | - |
| `stage_object_children` | output_mismatch | segfault | 68/83 | - |
| `stage_object_properties` | output_mismatch | segfault | 225/241 | - |
| `stage_object_properties_swf6` | output_mismatch | segfault | 212/231 | - |
| `string_paths_hidden` | output_mismatch | segfault | 36/54 | - |
| `super_edge_cases` | output_mismatch | runtime_error | 7/39 | - |
| `swf5_no_closure` | output_mismatch | segfault | 8/19 | - |
| `swf5_to_6_cross_call` | output_mismatch | segfault | 0/29 | - |
| `swf6_case_insensitive` | output_mismatch | segfault | 28/42 | - |
| `swf6_to_5_cross_call` | output_mismatch | segfault | 0/29 | - |
| `tab_ordering_automatic_basic` | output_mismatch | segfault | 0/92 | - |
| `tab_ordering_automatic_order_grid` | output_mismatch | segfault | 0/21 | - |
| `tab_ordering_automatic_order_same_position` | output_mismatch | segfault | 0/12 | - |
| `tab_ordering_children` | output_mismatch | segfault | 0/208 | - |
| `tab_ordering_custom_basic` | output_mismatch | segfault | 0/71 | - |
| `tab_ordering_custom_duplicate_index` | output_mismatch | segfault | 0/22 | - |
| `tab_ordering_custom_i32_vs_u32` | output_mismatch | segfault | 0/12 | - |
| `tab_ordering_custom_m1` | output_mismatch | segfault | 0/29 | - |
| `tab_ordering_events` | output_mismatch | segfault | 2/150 | - |
| `tab_ordering_events_mouse` | output_mismatch | segfault | 0/65 | - |
| `tab_ordering_movieclip_enabled_default` | output_mismatch | segfault | 0/462 | - |
| `tab_ordering_properties` | output_mismatch | segfault | 156/293 | - |
| `tab_ordering_reverse` | output_mismatch | segfault | 0/51 | - |
| `tab_ordering_tabbable` | output_mismatch | segfault | 0/47 | - |
| `target_clip_removed` | output_mismatch | segfault | 4/5 | - |
| `target_clip_swf5` | output_mismatch | segfault | 0/2 | - |
| `target_clip_swf6` | output_mismatch | segfault | 0/2 | - |
| `target_path` | output_mismatch | segfault | 11/14 | - |
| `tell_target` | output_mismatch | segfault | 0/37 | - |
| `tell_target_invalid` | output_mismatch | segfault | 0/6 | - |
| `tell_target_invalid_swf6` | output_mismatch | segfault | 0/5 | - |
| `text_blocks_clicks` | output_mismatch | segfault | 0/4 | - |
| `textfield_variable` | output_mismatch | segfault | 78/81 | - |
| `textsnapshot_available_text` | output_mismatch | segfault | 10/20 | - |
| `this_scoping` | output_mismatch | segfault | 42/52 | 15/52 |
| `unload` | output_mismatch | segfault | 14/52 | - |
| `unload_clip_event` | output_mismatch | segfault | 0/4 | - |
| `unload_nested_child` | output_mismatch | segfault | 0/5 | - |
| `with` | output_mismatch | segfault | 46/49 | - |
| `xml_socket` | output_mismatch | runtime_error | 1/8 | - |
| `xml_socket_close_in_handler` | output_mismatch | runtime_error | 0/6 | - |
| `xml_socket_on_data` | output_mismatch | runtime_error | 0/7 | - |
| `xml_socket_segmented` | output_mismatch | runtime_error | 0/29 | - |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `goto_methods` | segfault | 8/40 | - | -32 |
| `bad_placeobject_clipaction` | output_mismatch | 0/2 | 1/2 | -1 |
| `clip_events` | segfault | 1/19 | 1/19 | 0 |
