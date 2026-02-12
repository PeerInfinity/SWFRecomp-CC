# Ruffle Test Results Diff

**Previous:** `0f4ca778db49` (2026-02-12T20:38:27.041874+00:00)
**Current:** `98b84df5264b` (2026-02-12T22:25:15.901840+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 72 | 101 | +29 |
| Total | 616 | 616 | 0 |
| Pass rate | 11.7% | 16.4% | +4.7% |
| Mismatched lines | 56847 | 56406 | -441 |
|   Decreased | | | -448 |
|   Increased | | | +7 |

## Newly Passing (29)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `array_constructor` | output_mismatch | 29/30 | 30/30 |
| `bad_swf_tag_past_eof` | output_mismatch | 0/0 | 0/0 |
| `bitmap_data_colortransform` | output_mismatch | 0/0 | 0/0 |
| `bitmap_data_fillrect` | output_mismatch | 0/0 | 0/0 |
| `bitmap_data_perlinnoise` | output_mismatch | 0/0 | 0/0 |
| `bitmap_data_pixeldissolve_image` | output_mismatch | 0/0 | 0/0 |
| `bitmapdata_applyfilter_colormatrix` | output_mismatch | 0/0 | 0/0 |
| `error` | output_mismatch | 38/58 | 58/58 |
| `escape` | output_mismatch | 8/14 | 14/14 |
| `focusrect_mouse_swf8` | output_mismatch | 0/0 | 0/0 |
| `focusrect_mouse_swf9` | output_mismatch | 0/0 | 0/0 |
| `getproperty` | output_mismatch | 18/28 | 28/28 |
| `getproperty_swf4` | output_mismatch | 23/28 | 28/28 |
| `getproperty_swf5` | output_mismatch | 18/28 | 28/28 |
| `issue_1671` | output_mismatch | 0/0 | 0/0 |
| `mask_reapply` | output_mismatch | 0/0 | 0/0 |
| `mask_with_drawing` | output_mismatch | 0/0 | 0/0 |
| `movieclip_begin_gradient_fill` | output_mismatch | 0/0 | 0/0 |
| `movieclip_line_gradient_style` | output_mismatch | 0/0 | 0/0 |
| `movieclip_prototype_extension` | output_mismatch | 4/5 | 5/5 |
| `nested_textfields_in_buttons` | output_mismatch | 0/0 | 0/0 |
| `new_object_enumerate` | output_mismatch | 3/7 | 7/7 |
| `object_string_coerce_swf5` | output_mismatch | 62/62 | 62/62 |
| `prototype_delete` | output_mismatch | 6/12 | 12/12 |
| `sound_start_load` | output_mismatch | 0/0 | 0/0 |
| `string_coercion` | output_mismatch | 116/117 | 117/117 |
| `string_paths_keyevents` | output_mismatch | 0/0 | 0/0 |
| `string_paths_timer` | output_mismatch | 0/0 | 0/0 |
| `unescape` | output_mismatch | 9/43 | 43/43 |

## Status Changed (6)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `clip_constructors` | output_mismatch | segfault | 0/8 | - |
| `init_object_order` | output_mismatch | segfault | 0/15 | - |
| `loadmovie_registerclass` | output_mismatch | segfault | 0/30 | - |
| `register_and_init_order` | output_mismatch | segfault | 35/231 | - |
| `resolve_different_root` | output_mismatch | segfault | 0/2 | - |
| `timer_run_actions` | output_mismatch | segfault | 0/18 | - |

## Line Count Changed (188)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `funky_function_calls` | output_mismatch | 3/56 | 12/56 | -9 |
| `globals_swf5` | output_mismatch | 188/304 | 197/304 | -9 |
| `globals_swf6` | output_mismatch | 195/304 | 204/304 | -9 |
| `globals_swf7` | output_mismatch | 192/304 | 201/304 | -9 |
| `globals_swf8` | output_mismatch | 118/304 | 127/304 | -9 |
| `primitive_instanceof` | output_mismatch | 25/37 | 34/37 | -9 |
| `path_string` | segfault | 36/322 | 44/322 | -8 |
| `swf7_case_sensitive` | output_mismatch | 37/44 | 41/44 | -4 |
| `get_variable_in_scope` | output_mismatch | 20/29 | 23/29 | -3 |
| `object_constructor` | output_mismatch | 29/33 | 32/33 | -3 |
| `frame_size_translated_negative` | output_mismatch | 4/21 | 6/21 | -2 |
| `frame_size_translated_positive` | output_mismatch | 4/21 | 6/21 | -2 |
| `focusrect_property_swf6` | output_mismatch | 2/1237 | 3/1237 | -1 |
| `focusrect_property_swf7` | output_mismatch | 1/1237 | 2/1237 | -1 |
| `movieclip_focusenabled` | output_mismatch | 52/99 | 53/99 | -1 |
| `movieclip_gettextsnapshot` | output_mismatch | 0/112 | 1/112 | -1 |
| `set_variable_scope` | output_mismatch | 50/58 | 51/58 | -1 |
| `array_sort_random` | output_mismatch | 0/443 | 0/443 | 0 |
| `as2_super_and_this_v6` | output_mismatch | 0/97 | 0/97 | 0 |
| `as2_super_and_this_v8` | output_mismatch | 0/85 | 0/85 | 0 |
| `as2_super_via_manual_prototype` | output_mismatch | 0/40 | 0/40 | 0 |
| `asfunction` | output_mismatch | 0/11 | 0/11 | 0 |
| `asnew` | output_mismatch | 0/34 | 0/34 | 0 |
| `bad_placeobject_clipaction` | output_mismatch | 0/2 | 0/2 | 0 |
| `bitmap_data_copypixels` | output_mismatch | 0/17 | 0/17 | 0 |
| `bitmap_data_pixeldissolve` | output_mismatch | 0/1075 | 0/1075 | 0 |
| `bitmap_filters` | output_mismatch | 0/548 | 0/548 | 0 |
| `boxed_primitives` | output_mismatch | 0/24 | 0/24 | 0 |
| `button_children` | output_mismatch | 0/8 | 0/8 | 0 |
| `button_goto` | output_mismatch | 0/4 | 0/4 | 0 |
| `button_key_events` | output_mismatch | 0/14 | 0/14 | 0 |
| `button_key_events_special` | output_mismatch | 0/45 | 0/45 | 0 |
| `button_keypress` | output_mismatch | 0/3 | 0/3 | 0 |
| `button_keypress_vs_press` | output_mismatch | 0/25 | 0/25 | 0 |
| `button_keypress_vs_tab` | output_mismatch | 0/20 | 0/20 | 0 |
| `button_keypress_vs_textinput` | output_mismatch | 0/4 | 0/4 | 0 |
| `button_order` | output_mismatch | 0/2 | 0/2 | 0 |
| `button_properties_special_cases` | output_mismatch | 0/22 | 0/22 | 0 |
| `button_v5` | output_mismatch | 0/18 | 0/18 | 0 |
| `button_v6` | output_mismatch | 0/18 | 0/18 | 0 |
| `call` | output_mismatch | 0/63 | 0/63 | 0 |
| `call_method_empty_name` | output_mismatch | 0/1 | 0/1 | 0 |
| `click_block` | output_mismatch | 0/5 | 0/5 | 0 |
| `clip_event_propagation_order` | output_mismatch | 0/17 | 0/17 | 0 |
| `coerce_to_object_monkeypatch` | output_mismatch | 0/129 | 0/129 | 0 |
| `coerce_to_primitive_resolve` | output_mismatch | 0/17 | 0/17 | 0 |
| `color` | output_mismatch | 0/57 | 0/57 | 0 |
| `drag_drop` | output_mismatch | 0/10 | 0/10 | 0 |
| `drag_over_from_outside` | output_mismatch | 0/1 | 0/1 | 0 |
| `drag_over_without_startdrag` | output_mismatch | 0/1 | 0/1 | 0 |
| `duplicate_movie_clip` | output_mismatch | 0/20 | 0/20 | 0 |
| `edittext_drag_select` | output_mismatch | 0/9 | 0/9 | 0 |
| `edittext_html_roundtrip` | output_mismatch | 0/17 | 0/17 | 0 |
| `edittext_ime_focus_lost` | output_mismatch | 0/7 | 0/7 | 0 |
| `edittext_input` | output_mismatch | 0/1 | 0/1 | 0 |
| `edittext_input_newlines` | output_mismatch | 0/9 | 0/9 | 0 |
| `edittext_password` | output_mismatch | 0/5 | 0/5 | 0 |
| `edittext_password_copy` | output_mismatch | 0/4 | 0/4 | 0 |
| `edittext_paste_empty` | output_mismatch | 0/2 | 0/2 | 0 |
| `edittext_place_caret` | output_mismatch | 0/2 | 0/2 | 0 |
| `edittext_restrict` | output_mismatch | 0/191 | 0/191 | 0 |
| `edittext_restrict_paste` | output_mismatch | 0/5 | 0/5 | 0 |
| `edittext_tab_focus` | output_mismatch | 0/13 | 0/13 | 0 |
| `extends_native_type` | output_mismatch | 0/11 | 0/11 | 0 |
| `file_reference_browse_cancel` | output_mismatch | 0/21 | 0/21 | 0 |
| `focus_keyboard_press` | output_mismatch | 0/60 | 0/60 | 0 |
| `focus_mouse` | output_mismatch | 0/45 | 0/45 | 0 |
| `focus_mouse_focusable` | output_mismatch | 0/8 | 0/8 | 0 |
| `focus_mouse_rollout` | output_mismatch | 0/4 | 0/4 | 0 |
| `focusrect_focuslost` | output_mismatch | 0/4 | 0/4 | 0 |
| `focusrect_swf6` | output_mismatch | 0/42 | 0/42 | 0 |
| `function_base_clip` | output_mismatch | 0/8 | 0/8 | 0 |
| `function_base_clip_readded` | output_mismatch | 0/11 | 0/11 | 0 |
| `function_suppress_and_preload` | output_mismatch | 0/28 | 0/28 | 0 |
| `global_swf5_6_7_8_9` | output_mismatch | 0/1145 | 0/1145 | 0 |
| `global_swf6_7_8` | output_mismatch | 0/15 | 0/15 | 0 |
| `goto_execution_order2` | output_mismatch | 0/2 | 0/2 | 0 |
| `goto_frame` | output_mismatch | 0/12 | 0/12 | 0 |
| `goto_frame2` | output_mismatch | 0/44 | 0/44 | 0 |
| `goto_label` | output_mismatch | 0/17 | 0/17 | 0 |
| `goto_methods` | output_mismatch | 0/40 | 0/40 | 0 |
| `hittest_lockroot` | output_mismatch | 0/15 | 0/15 | 0 |
| `hittest_morph` | output_mismatch | 0/70 | 0/70 | 0 |
| `hittest_morph_input` | output_mismatch | 0/1 | 0/1 | 0 |
| `hittest_winding_rule` | output_mismatch | 0/12 | 0/12 | 0 |
| `init_array_invalid` | output_mismatch | 0/4 | 0/4 | 0 |
| `init_object_invalid` | output_mismatch | 0/4 | 0/4 | 0 |
| `input_dead_keys_windows` | output_mismatch | 0/15 | 0/15 | 0 |
| `instanceof_coercions` | output_mismatch | 0/88 | 0/88 | 0 |
| `interface_implements_op` | output_mismatch | 0/47 | 0/47 | 0 |
| `issue_1104` | output_mismatch | 0/2 | 0/2 | 0 |
| `issue_2084` | output_mismatch | 0/16 | 0/16 | 0 |
| `issue_2870` | output_mismatch | 0/3 | 0/3 | 0 |
| `issue_3169` | output_mismatch | 0/2 | 0/2 | 0 |
| `issue_9327` | output_mismatch | 0/2 | 0/2 | 0 |
| `issue_9885` | output_mismatch | 0/2 | 0/2 | 0 |
| `key_isToggled` | output_mismatch | 0/9 | 0/9 | 0 |
| `loadmovie_fail` | output_mismatch | 0/2 | 0/2 | 0 |
| `loadmovienum_cross_version_prototype` | output_mismatch | 0/9 | 0/9 | 0 |
| `loadvariables_method` | output_mismatch | 0/7 | 0/7 | 0 |
| `localconnection` | output_mismatch | 0/579 | 0/579 | 0 |
| `lock_root` | output_mismatch | 0/1 | 0/1 | 0 |
| `mcl_as_broadcaster` | output_mismatch | 0/12 | 0/12 | 0 |
| `mcl_events_swf_version` | output_mismatch | 0/232 | 0/232 | 0 |
| `mcl_loadclip_properties` | output_mismatch | 0/6 | 0/6 | 0 |
| `mcl_loadclip_replace_root` | output_mismatch | 0/1 | 0/1 | 0 |
| `mcl_mislabeled_target` | output_mismatch | 0/6 | 0/6 | 0 |
| `mcl_target_gif87a` | output_mismatch | 0/6 | 0/6 | 0 |
| `mcl_target_gif89a` | output_mismatch | 0/6 | 0/6 | 0 |
| `mcl_target_jpg` | output_mismatch | 0/6 | 0/6 | 0 |
| `mcl_target_png` | output_mismatch | 0/6 | 0/6 | 0 |
| `mcl_unloadclip` | output_mismatch | 0/5 | 0/5 | 0 |
| `mixed_avm_load_into_root` | output_mismatch | 0/2 | 0/2 | 0 |
| `mouse_events` | output_mismatch | 0/8 | 0/8 | 0 |
| `mouse_events_visible_enabled` | output_mismatch | 0/12 | 0/12 | 0 |
| `mouse_hover_events_while_dragging` | output_mismatch | 0/1 | 0/1 | 0 |
| `movieclip_blend_mode_property` | output_mismatch | 0/35 | 0/35 | 0 |
| `movieclip_in_removed_button` | output_mismatch | 0/4 | 0/4 | 0 |
| `movieclip_init_object` | output_mismatch | 0/5 | 0/5 | 0 |
| `movieclip_methods_with_loaded_image` | output_mismatch | 0/4 | 0/4 | 0 |
| `named_shapes` | output_mismatch | 0/14 | 0/14 | 0 |
| `native_double_construct` | output_mismatch | 0/12 | 0/12 | 0 |
| `native_objects_swf6` | output_mismatch | 0/84 | 0/84 | 0 |
| `native_objects_swf7` | output_mismatch | 0/84 | 0/84 | 0 |
| `native_objects_swf8` | output_mismatch | 0/84 | 0/84 | 0 |
| `native_subclasses` | output_mismatch | 0/191 | 0/191 | 0 |
| `netconnection_send_remote` | output_mismatch | 0/50 | 0/50 | 0 |
| `netstream_seek_flv` | output_mismatch | 0/25 | 0/25 | 0 |
| `new_method_wrap` | output_mismatch | 0/4 | 0/4 | 0 |
| `new_object_wrap` | output_mismatch | 0/4 | 0/4 | 0 |
| `object_properties` | output_mismatch | 0/31 | 0/31 | 0 |
| `object_resolve` | output_mismatch | 0/38 | 0/38 | 0 |
| `object_string_coerce_swf6` | output_mismatch | 46/68 | 46/68 | 0 |
| `on_construct` | output_mismatch | 0/25 | 0/25 | 0 |
| `place_and_lookup` | output_mismatch | 0/30 | 0/30 | 0 |
| `register_class_return_value` | output_mismatch | 0/16 | 0/16 | 0 |
| `register_class_swf6` | output_mismatch | 0/37 | 0/37 | 0 |
| `register_class_with_sound` | output_mismatch | 0/11 | 0/11 | 0 |
| `removed_target_clip_scope` | output_mismatch | 0/35 | 0/35 | 0 |
| `root_onload` | output_mismatch | 0/1 | 0/1 | 0 |
| `selection` | output_mismatch | 0/454 | 0/454 | 0 |
| `slash_syntax` | output_mismatch | 0/14 | 0/14 | 0 |
| `sound_load_start` | output_mismatch | 0/3 | 0/3 | 0 |
| `sound_multiple_load` | output_mismatch | 0/1 | 0/1 | 0 |
| `stage_object_enumerate` | output_mismatch | 0/4 | 0/4 | 0 |
| `string_methods_negative_args` | output_mismatch | 0/240 | 0/240 | 0 |
| `string_paths_eval` | output_mismatch | 0/4 | 0/4 | 0 |
| `string_paths_unload` | output_mismatch | 0/1 | 0/1 | 0 |
| `string_paths_variable_scopes` | output_mismatch | 0/5 | 0/5 | 0 |
| `stylesheet` | output_mismatch | 0/283 | 0/283 | 0 |
| `super_edge_cases` | output_mismatch | 0/39 | 0/39 | 0 |
| `tab_ordering_automatic_basic` | output_mismatch | 0/92 | 0/92 | 0 |
| `tab_ordering_automatic_order_grid` | output_mismatch | 0/21 | 0/21 | 0 |
| `tab_ordering_automatic_order_same_position` | output_mismatch | 0/12 | 0/12 | 0 |
| `tab_ordering_children` | output_mismatch | 0/208 | 0/208 | 0 |
| `tab_ordering_custom_basic` | output_mismatch | 0/71 | 0/71 | 0 |
| `tab_ordering_custom_duplicate_index` | output_mismatch | 0/22 | 0/22 | 0 |
| `tab_ordering_custom_i32_vs_u32` | output_mismatch | 0/12 | 0/12 | 0 |
| `tab_ordering_custom_m1` | output_mismatch | 0/29 | 0/29 | 0 |
| `tab_ordering_events_mouse` | output_mismatch | 0/65 | 0/65 | 0 |
| `tab_ordering_movieclip_enabled_default` | output_mismatch | 0/462 | 0/462 | 0 |
| `tab_ordering_reverse` | output_mismatch | 0/51 | 0/51 | 0 |
| `tab_ordering_tabbable` | output_mismatch | 0/47 | 0/47 | 0 |
| `target_clip_swf5` | output_mismatch | 0/2 | 0/2 | 0 |
| `target_clip_swf6` | output_mismatch | 0/2 | 0/2 | 0 |
| `target_path` | output_mismatch | 0/14 | 0/14 | 0 |
| `text_blocks_clicks` | output_mismatch | 0/4 | 0/4 | 0 |
| `textfield_cache_as_bitmap` | output_mismatch | 0/1 | 0/1 | 0 |
| `typeof` | output_mismatch | 0/22 | 0/22 | 0 |
| `unload_clip_event` | output_mismatch | 0/4 | 0/4 | 0 |
| `use_hand_cursor` | output_mismatch | 0/8 | 0/8 | 0 |
| `watch` | output_mismatch | 0/117 | 0/117 | 0 |
| `watch_textfield` | output_mismatch | 0/12 | 0/12 | 0 |
| `watch_virtual_property_proto` | output_mismatch | 0/2 | 0/2 | 0 |
| `xml_ignore_comments` | output_mismatch | 0/21 | 0/21 | 0 |
| `xml_load` | output_mismatch | 0/2 | 0/2 | 0 |
| `xml_reparenting` | output_mismatch | 0/14 | 0/14 | 0 |
| `xml_socket` | output_mismatch | 0/8 | 0/8 | 0 |
| `xml_socket_close_in_handler` | output_mismatch | 0/6 | 0/6 | 0 |
| `xml_socket_on_data` | output_mismatch | 0/7 | 0/7 | 0 |
| `xml_socket_segmented` | output_mismatch | 0/29 | 0/29 | 0 |
| `xml_unescaping` | output_mismatch | 0/23 | 0/23 | 0 |
| `xmlnode_proto` | output_mismatch | 0/1 | 0/1 | 0 |
| `focusrect_property_swf5` | output_mismatch | 4/1237 | 3/1237 | +1 |
| `register_class` | output_mismatch | 3/66 | 2/66 | +1 |
| `stage_object_children` | output_mismatch | 63/83 | 62/83 | +1 |
| `swf6_case_insensitive` | output_mismatch | 26/42 | 25/42 | +1 |
| `arguments` | output_mismatch | 80/127 | 77/127 | +3 |
