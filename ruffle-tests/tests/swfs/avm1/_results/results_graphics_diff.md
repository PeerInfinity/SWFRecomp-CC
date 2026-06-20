# Ruffle Test Results Diff

**Previous:** `fe0030e4fc7d` (2026-06-18T22:05:01.941564+00:00)
**Current:** `6e0b2fc8f8b0` (2026-06-20T19:39:30.141283+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 450 | 629 | +179 |
| Total | 514 | 701 | +187 |
| Pass rate | 87.5% | 89.7% | +2.2% |
| Mismatched lines | 16262 | 15471 | -791 |
|   Decreased | | | -1095 |
|   Increased | | | +112 |

## Newly Passing (6)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `array_reverse` | output_mismatch | 122/226 | 226/226 |
| `array_shift` | output_mismatch | 149/216 | 216/216 |
| `array_unshift` | output_mismatch | 95/146 | 146/146 |
| `set_target_2_swf6` | output_mismatch | 12/13 | 13/13 |
| `set_target_2_swf7` | output_mismatch | 12/13 | 13/13 |
| `virtual_property_special_recursion_double_swf6` | output_mismatch | 3/11 | 11/11 |

## Status Changed (5)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `virtual_property_special_recursion_swf6` | output_mismatch | ruffle_matched | 1/6 | 5/6 |
| `watch_special_recursion_double_swf6` | segfault | ruffle_matched | 9/46 | 18/46 |
| `watch_special_recursion_double_swf7` | segfault | output_mismatch | 521/3118 | 409/3118 |
| `watch_special_recursion_swf6` | segfault | ruffle_matched | 3/18 | 12/18 |
| `watch_special_recursion_swf7` | segfault | output_mismatch | 195/1042 | 1036/1042 |

## Added Tests (187)

| Test | Status | Lines |
|------|--------|-------|
| `button_children` | pass | 8/8 |
| `button_goto` | pass | 4/4 |
| `button_key_events` | pass | 14/14 |
| `button_key_events_special` | pass | 45/45 |
| `button_keypress` | pass | 3/3 |
| `button_keypress_vs_press` | pass | 25/25 |
| `button_keypress_vs_tab` | pass | 20/20 |
| `button_keypress_vs_textinput` | pass | 4/4 |
| `button_order` | pass | 2/2 |
| `button_properties_special_cases` | pass | 22/22 |
| `button_v5` | pass | 18/18 |
| `button_v6` | pass | 18/18 |
| `call` | pass | 62/62 |
| `call_method_empty_name` | pass | 1/1 |
| `capabilities_resolution` | pass | 8/8 |
| `catch_references_registers` | pass | 2/2 |
| `click_block` | pass | 5/5 |
| `clip_constructors` | pass | 8/8 |
| `clip_event_propagation_order` | pass | 17/17 |
| `clip_events` | pass | 19/19 |
| `clone_sprite_edittext` | pass | 94/94 |
| `clone_sprite_edittext_dynamic` | pass | 86/86 |
| `clone_sprite_types` | pass | 24/24 |
| `closure_scope` | pass | 7/7 |
| `coerce_to_object_monkeypatch` | pass | 129/129 |
| `coerce_to_primitive_resolve` | pass | 22/22 |
| `color` | pass | 57/57 |
| `color_transform` | pass | 48/48 |
| `conflicting_instance_names` | pass | 23/23 |
| `constructor_function` | pass | 2/2 |
| `context_menu` | pass | 39/39 |
| `context_menu_item` | pass | 41/41 |
| `create_empty_movie_clip` | pass | 3/3 |
| `cross_movie_root` | pass | 10/10 |
| `custom_clip_methods` | pass | 4/4 |
| `date` | output_mismatch | 6289/6335 |
| `default_names` | pass | 52/52 |
| `define_function2` | pass | 8/8 |
| `define_function2_preload` | pass | 13/13 |
| `define_function2_preload_order` | pass | 4/4 |
| `define_function_case_sensitive` | pass | 2/2 |
| `define_local` | pass | 27/27 |
| `define_local_with_paths` | pass | 54/54 |
| `delete` | pass | 3/3 |
| `delete2` | pass | 74/74 |
| `depth_replacement_audio_unloading` | pass | 3/3 |
| `device_font_spacing` | pass | 91/91 |
| `displacementmapfilter_mappoint_throw_error` | pass | 13/13 |
| `edittext_scroll` | pass | 54/54 |
| `edittext_stylesheet` | pass | 325/325 |
| `edittext_tab_focus` | pass | 13/13 |
| `edittext_tab_stops` | pass | 60/60 |
| `edittext_tag_indent` | pass | 31/31 |
| `edittext_text_height_leading` | pass | 20/20 |
| `edittext_underline` | pass | 40/40 |
| `edittext_width_height` | pass | 103/103 |
| `empty_movieclip_can_attach_movies` | pass | 11/11 |
| `enumerate` | pass | 64/64 |
| `equals` | pass | 32/32 |
| `equals2_swf5` | pass | 926/926 |
| `equals2_swf6` | pass | 926/926 |
| `equals2_swf7` | pass | 926/926 |
| `equals_swf4` | pass | 665/665 |
| `equals_swf4_alt` | pass | 32/32 |
| `equals_swf5` | pass | 32/32 |
| `error` | pass | 58/58 |
| `escape` | pass | 14/14 |
| `execution_order1` | pass | 5/5 |
| `execution_order2` | pass | 7/7 |
| `execution_order3` | pass | 4/4 |
| `execution_order4` | pass | 12/12 |
| `export_assets` | pass | 3/3 |
| `issue_9885` | pass | 2/2 |
| `key_isToggled` | pass | 9/9 |
| `lessthan` | pass | 41/41 |
| `lessthan2_swf5` | pass | 1226/1226 |
| `lessthan2_swf6` | pass | 1226/1226 |
| `lessthan2_swf7` | pass | 1226/1226 |
| `lessthan_swf4` | pass | 902/902 |
| `lessthan_swf4_alt` | pass | 41/41 |
| `lessthan_swf5` | pass | 41/41 |
| `load_cancel_via_removemovieclip` | output_mismatch | 2/4 |
| `load_cancel_via_unloadclip` | ruffle_matched | 3/3 |
| `load_cancel_via_unloadmovie` | ruffle_matched | 5/5 |
| `load_vars` | output_mismatch | 29/35 |
| `loadmovie` | pass | 2/2 |
| `loadmovie_fail` | pass | 2/2 |
| `loadmovie_flashvars` | pass | 4/4 |
| `loadmovie_method` | pass | 2/2 |
| `loadmovie_registerclass` | pass | 30/30 |
| `loadmovie_replace_root` | pass | 5/5 |
| `loadmovie_var_persistence` | pass | 8/8 |
| `loadmovienum` | pass | 3/3 |
| `loadmovienum_cross_version_prototype` | pass | 9/9 |
| `loadvariables` | pass | 2/2 |
| `movieclip_lockroot` | pass | 29/29 |
| `movieclip_methods_with_loaded_image` | pass | 4/4 |
| `movieclip_name_from_timeline` | pass | 13/13 |
| `movieclip_onconstruct` | pass | 20/20 |
| `movieclip_prototype_extension` | pass | 5/5 |
| `movieclip_setmask` | pass | 14/14 |
| `movieclip_state_values` | pass | 114/114 |
| `moviecliploader_flashvars` | pass | 4/4 |
| `mutable_this` | pass | 18/18 |
| `named_shapes` | pass | 14/14 |
| `nan_scale` | pass | 9/9 |
| `native_double_construct` | pass | 12/12 |
| `native_objects_swf6` | output_mismatch | 114/115 |
| `native_objects_swf7` | pass | 115/115 |
| `native_objects_swf8` | pass | 115/115 |
| `native_subclasses` | pass | 191/191 |
| `nested_textfields_in_buttons` | pass | 0/0 |
| `netconnection_close` | pass | 39/39 |
| `netconnection_send_remote` | output_mismatch | 2/50 |
| `netconnection_serialize_arrays` | output_mismatch | 1/6 |
| `netstream_play_flv` | pass | 21/21 |
| `netstream_play_flv_screen` | pass | 0/0 |
| `netstream_seek_flv` | pass | 25/25 |
| `sound_load_start` | pass | 3/3 |
| `sound_multiple_load` | pass | 1/1 |
| `sound_nested_clips` | pass | 10/10 |
| `sound_owner_reference` | pass | 12/12 |
| `sound_owner_tostring_fail` | pass | 9/9 |
| `sound_props_swf5` | pass | 68/68 |
| `sound_props_swf6` | pass | 68/68 |
| `sound_setters` | output_mismatch | 14/43 |
| `sound_start_load` | pass | 0/0 |
| `sound_start_stop` | pass | 44/44 |
| `stage_display_state` | pass | 16/16 |
| `stage_object_children` | pass | 83/83 |
| `stage_object_enumerate` | pass | 4/4 |
| `stage_object_properties` | pass | 241/241 |
| `stage_object_properties_get_var` | pass | 5/5 |
| `stage_object_properties_swf6` | pass | 231/231 |
| `stage_property_representation` | pass | 586/586 |
| `stage_scale_mode` | pass | 39/39 |
| `strictequals_swf6` | pass | 902/902 |
| `strictly_equals` | pass | 7/7 |
| `string_coercion` | pass | 117/117 |
| `string_methods` | pass | 285/285 |
| `string_methods_negative_args` | pass | 240/240 |
| `string_methods_swfv5` | pass | 275/275 |
| `string_ops_swf6` | pass | 95/95 |
| `string_paths_basic` | pass | 4/4 |
| `string_paths_eval` | pass | 4/4 |
| `string_paths_eval2` | pass | 7/7 |
| `string_paths_hidden` | pass | 54/54 |
| `string_paths_keyevents` | pass | 0/0 |
| `string_paths_other` | pass | 36/36 |
| `string_paths_reference_launder` | output_mismatch | 1/2 |
| `string_paths_timer` | pass | 0/0 |
| `string_paths_unload` | pass | 1/1 |
| `string_paths_variable_alias` | pass | 4/4 |
| `string_paths_variable_scopes` | pass | 5/5 |
| `string_relational_compare` | output_mismatch | 3/4 |
| `stylesheet` | pass | 283/283 |
| `stylesheet_load` | output_mismatch | 1/49 |
| `stylesheet_transform` | pass | 750/750 |
| `super_edge_cases` | pass | 39/39 |
| `swf4_actions_bool` | pass | 96/96 |
| `swf4_actions_coercion_order` | pass | 157/157 |
| `swf4_bool` | pass | 4/4 |
| `swf4_function_calls` | pass | 7/7 |
| `swf4_vars` | ruffle_matched | 22/25 |
| `textfield_maxchars` | pass | 3/3 |
| `textfield_properties` | pass | 44/44 |
| `textfield_props_swf5` | ruffle_matched | 173/175 |
| `textfield_props_swf6` | pass | 210/210 |
| `textfield_props_swf7` | pass | 210/210 |
| `textfield_props_swf8` | pass | 210/210 |
| `textfield_text` | pass | 7/7 |
| `textfield_variable` | pass | 81/81 |
| `textsnapshot_available_text` | pass | 20/20 |
| `textsnapshot_findtext` | pass | 44/44 |
| `textsnapshot_gettext` | pass | 55/55 |
| `textsnapshot_props_swf5` | pass | 56/56 |
| `textsnapshot_props_swf6` | pass | 56/56 |
| `textsnapshot_text_order` | pass | 1/1 |
| `this_scoping` | pass | 52/52 |
| `this_swf5` | pass | 41/41 |
| `this_swf6` | pass | 41/41 |
| `this_swf7` | pass | 41/41 |
| `timeline_function_def` | pass | 7/7 |
| `timeout` | pass | 0/0 |
| `timer_run_actions` | pass | 18/18 |
| `trace` | pass | 8/8 |
| `transform` | pass | 70/70 |
