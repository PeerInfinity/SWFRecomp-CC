# Ruffle Test Results Diff

**Previous:** `8df2d730c3f0` (2026-07-26T20:13:07.878228+00:00)
**Current:** `767a301d2bae` (2026-07-29T01:40:49.568741+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 843 | 919 | +76 |
| Total | 1221 | 1221 | 0 |
| Pass rate | 69.0% | 75.3% | +6.3% |
| Mismatched lines | 47194 | 44016 | -3178 |
|   Decreased | | | -3248 |
|   Increased | | | +70 |

## Newly Passing (76)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `air_datagram_socket` | output_mismatch | 0/1 | 1/1 |
| `av_networking_params` | output_mismatch | 0/9 | 9/9 |
| `cross_api_version_call_older` | output_mismatch | 0/12 | 12/12 |
| `displayobject_set_name_loaded` | output_mismatch | 1/3 | 3/3 |
| `edittext_ime_focus_lost` | output_mismatch | 0/9 | 9/9 |
| `edittext_mouse_selection` | output_mismatch | 334/363 | 363/363 |
| `error_geterrormessage` | output_mismatch | 0/779 | 779/779 |
| `focus_events_key_basic` | output_mismatch | 33/132 | 132/132 |
| `focus_events_key_navigation` | output_mismatch | 12/53 | 53/53 |
| `focus_events_mouse_basic` | output_mismatch | 30/260 | 260/260 |
| `focus_events_mouse_focusable` | output_mismatch | 110/112 | 112/112 |
| `focusrect_focuslost` | output_mismatch | 7/9 | 9/9 |
| `focusrect_property` | output_mismatch | 104/110 | 110/110 |
| `ime_linux_dead_keys` | output_mismatch | 0/10 | 10/10 |
| `jpeg_loader_context` | output_mismatch | 0/6 | 6/6 |
| `loader_bitmap_transparency` | output_mismatch | 1/14 | 14/14 |
| `loader_bytes_unknown_content` | output_mismatch | 1/14 | 14/14 |
| `loader_child_getdefinition` | output_mismatch | 2/5 | 5/5 |
| `loader_duplicate_coerce` | output_mismatch | 1/3 | 3/3 |
| `loader_duplicate_coerce_new_domain` | output_mismatch | 1/4 | 4/4 |
| `loader_error_in_root_ctor` | output_mismatch | 0/4 | 4/4 |
| `loader_events` | output_mismatch | 8/92 | 92/92 |
| `loader_image` | output_mismatch | 0/8 | 8/8 |
| `loader_jpegxr` | output_mismatch | 0/2 | 2/2 |
| `loader_jpegxr_alpha` | output_mismatch | 0/1 | 1/1 |
| `loader_loadbytes_events` | output_mismatch | 2/30 | 30/30 |
| `loader_loadbytes_invalid_png` | output_mismatch | 0/4 | 4/4 |
| `loader_loadbytes_url` | output_mismatch | 1/12 | 12/12 |
| `loader_loaderurl` | output_mismatch | 2/6 | 6/6 |
| `loader_noninteractive_try_click_root` | output_mismatch | 0/5 | 5/5 |
| `loader_reuse` | output_mismatch | 7/38 | 38/38 |
| `loader_unknown_content` | output_mismatch | 0/24 | 24/24 |
| `loader_visibility_interactive` | output_mismatch | 0/1 | 1/1 |
| `loaderinfo_events` | output_mismatch | 4/7 | 7/7 |
| `loaderinfo_loadurl` | output_mismatch | 8/12 | 12/12 |
| `loaderinfo_more` | output_mismatch | 0/6 | 6/6 |
| `loaderinfo_properties_not_loaded` | output_mismatch | 15/23 | 23/23 |
| `mouse_children` | output_mismatch | 114/192 | 192/192 |
| `mouse_pick_dobj_mask` | output_mismatch | 2/4 | 4/4 |
| `mouse_pick_masking` | output_mismatch | 0/7 | 7/7 |
| `mouse_pick_non_interactive_bitmap_mask` | output_mismatch | 2/4 | 4/4 |
| `mouse_pick_non_interactive_dobj_mask` | output_mismatch | 0/3 | 3/3 |
| `mouse_pick_text` | output_mismatch | 4/8 | 8/8 |
| `mouse_wheel_events` | output_mismatch | 29/36 | 36/36 |
| `mouseevent_constr` | output_mismatch | 62/66 | 66/66 |
| `mouseevent_stagexy` | output_mismatch | 1/35 | 35/35 |
| `mouseevent_valueof_tostring` | output_mismatch | 24/28 | 28/28 |
| `navigateToURL_target_normalize` | output_mismatch | 6/107 | 107/107 |
| `net_navigateToURL` | output_mismatch | 4/57 | 57/57 |
| `net_stream_play_options` | output_mismatch | 0/6 | 6/6 |
| `netconnection_close` | output_mismatch | 0/55 | 55/55 |
| `netconnection_properties` | output_mismatch | 0/78 | 78/78 |
| `netstream_client` | output_mismatch | 0/10 | 10/10 |
| `netstream_connect` | output_mismatch | 0/7 | 7/7 |
| `responder_null_callbacks` | output_mismatch | 0/1 | 1/1 |
| `sandbox_type_inherited` | output_mismatch | 1/2 | 2/2 |
| `sandbox_type_local_network` | output_mismatch | 0/1 | 1/1 |
| `selection` | output_mismatch | 229/239 | 239/239 |
| `socket_after_disconnect` | output_mismatch | 0/1 | 1/1 |
| `socket_close` | output_mismatch | 0/2 | 2/2 |
| `socket_connect` | output_mismatch | 0/4 | 4/4 |
| `socket_errors` | output_mismatch | 0/56 | 56/56 |
| `socket_read_big` | output_mismatch | 0/48 | 48/48 |
| `socket_read_little` | output_mismatch | 0/48 | 48/48 |
| `socket_read_write_object` | output_mismatch | 0/8 | 8/8 |
| `socket_write_big` | output_mismatch | 0/15 | 15/15 |
| `socket_write_little` | output_mismatch | 0/14 | 14/14 |
| `stage_loaderinfo_properties` | output_mismatch | 22/24 | 24/24 |
| `tab_ordering_stage_tab_children` | output_mismatch | 15/32 | 32/32 |
| `tab_ordering_stage_tab_children_remove_root` | output_mismatch | 3/5 | 5/5 |
| `tab_ordering_tabbable` | output_mismatch | 45/47 | 47/47 |
| `textbox_click` | output_mismatch | 1/37 | 37/37 |
| `textfield_event` | output_mismatch | 0/66 | 66/66 |
| `url_loader` | output_mismatch | 0/25 | 25/25 |
| `wrong_arg_count` | output_mismatch | 1/7 | 7/7 |
| `xml_socket` | output_mismatch | 0/11 | 11/11 |

## Line Count Changed (34)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `tab_ordering_arrows` | output_mismatch | 1/998 | 645/998 | -644 |
| `loader_load` | output_mismatch | 12/128 | 124/128 | -112 |
| `loader_method` | output_mismatch | 16/85 | 83/85 | -67 |
| `large_preload_image_from_bytes` | output_mismatch | 4/25 | 19/25 | -15 |
| `large_preload_from_bytes` | output_mismatch | 4/51 | 18/51 | -14 |
| `delayed_symbolclass` | output_mismatch | 3/28 | 16/28 | -13 |
| `cross_api_version_call_newer` | output_mismatch | 0/12 | 11/12 | -11 |
| `large_preload_from_url` | output_mismatch | 8/27 | 16/27 | -8 |
| `displayobject_hittestpoint_root` | output_mismatch | 4/13 | 11/13 | -7 |
| `xml_appendchild_swf_v21` | output_mismatch | 7/13 | 12/13 | -5 |
| `font_registerfont` | output_mismatch | 5/129 | 8/129 | -3 |
| `instantiate_root_character` | output_mismatch | 0/4 | 3/4 | -3 |
| `amf_array_serialization` | output_mismatch | 4/17 | 6/17 | -2 |
| `netconnection_send_remote` | output_mismatch | 0/50 | 2/50 | -2 |
| `tab_ordering_properties` | output_mismatch | 559/732 | 561/732 | -2 |
| `url_vars` | output_mismatch | 1/27 | 3/27 | -2 |
| `all_classes/events/swf30` | output_mismatch | 0/2353 | 1/2353 | -1 |
| `blend_shader_luma_lighten` | output_mismatch | 0/3 | 1/3 | -1 |
| `bom` | output_mismatch | 3/9 | 4/9 | -1 |
| `loader_duplicate_class` | output_mismatch | 2/48 | 3/48 | -1 |
| `netconnection_serialize_arrays` | output_mismatch | 0/6 | 1/6 | -1 |
| `netstream_play_stop_replay` | output_mismatch | 0/11 | 1/11 | -1 |
| `sandbox_type_remote` | output_mismatch | 0/3 | 1/3 | -1 |
| `stage_domain_getQualifiedDefinitionNames` | output_mismatch | 0/5 | 1/5 | -1 |
| `all_classes/events/swf9` | output_mismatch | 1/1030 | 1/1030 | 0 |
| `focus_events_mixed_avm_edittext` | output_mismatch | 1/49 | 1/49 | 0 |
| `loader_try_click_root` | output_mismatch | 0/16 | 0/16 | 0 |
| `loaderinfo_quine` | output_mismatch | 1/1005 | 1/1005 | 0 |
| `netstream_seek_flv` | output_mismatch | 0/49 | 0/49 | 0 |
| `all_classes/events/swf10` | output_mismatch | 4/1638 | 1/1638 | +3 |
| `all_classes/events/swf11` | output_mismatch | 4/1750 | 1/1750 | +3 |
| `all_classes/events/swf12` | output_mismatch | 4/1814 | 1/1814 | +3 |
| `localconnection` | output_mismatch | 76/890 | 67/890 | +9 |
| `avm1_root` | output_mismatch | 0/6 | 0/58 | +52 |
