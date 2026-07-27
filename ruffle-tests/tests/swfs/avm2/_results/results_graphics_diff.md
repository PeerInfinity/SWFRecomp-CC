# Ruffle Test Results Diff

**Previous:** `a9900a478651` (2026-07-27T04:25:43.212677+00:00)
**Current:** `dfef7a9d6945` (2026-07-27T05:37:49.155062+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 820 | 861 | +41 |
| Total | 1221 | 1221 | 0 |
| Pass rate | 67.2% | 70.5% | +3.3% |
| Mismatched lines | 46006 | 45922 | -84 |
|   Decreased | | | -102 |
|   Increased | | | +18 |

## Newly Passing (44)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `away3d_advanced_shallow_water_demo` | output_mismatch | 0/0 | 0/0 |
| `bitmapdata_applyfilter_blur` | output_mismatch | 0/0 | 0/0 |
| `bitmapdata_applyfilter_colormatrix` | output_mismatch | 0/0 | 0/0 |
| `bitmapdata_applyfilter_destpoint` | output_mismatch | 0/0 | 0/0 |
| `bitmapdata_applyfilter_destpoint_edges` | output_mismatch | 0/0 | 0/0 |
| `bitmapdata_colortransform` | output_mismatch | 0/0 | 0/0 |
| `bitmapdata_copychannel` | output_mismatch | 0/0 | 0/0 |
| `bitmapdata_draw_filters` | output_mismatch | 0/0 | 0/0 |
| `bitmapdata_filter_sourcerect` | output_mismatch | 0/0 | 0/0 |
| `displayobject_colortransform_nested` | output_mismatch | 0/0 | 0/0 |
| `font_enumeratefonts` | output_mismatch | 41/41 | 41/41 |
| `graphics_bitmap_fill` | output_mismatch | 0/0 | 0/0 |
| `graphics_bitmaps` | output_mismatch | 0/0 | 0/0 |
| `graphics_direct_commands` | output_mismatch | 0/0 | 0/0 |
| `graphics_gradients` | output_mismatch | 0/0 | 0/0 |
| `graphics_round_rects` | output_mismatch | 0/0 | 0/0 |
| `mouse_over_while_dragging` | output_mismatch | 3/3 | 3/3 |
| `pixelbender_effect_BlurredFocus` | output_mismatch | 0/0 | 0/0 |
| `pixelbender_effect_glassDisplace` | output_mismatch | 0/0 | 0/0 |
| `pixelbender_effect_smudge` | output_mismatch | 0/0 | 0/0 |
| `pixelbender_effect_tintype` | output_mismatch | 0/0 | 0/0 |
| `pixelbender_effect_twirl` | output_mismatch | 0/0 | 0/0 |
| `pixelbender_images` | output_mismatch | 0/0 | 0/0 |
| `remove_child_clear_field` | output_mismatch | 23/88 | 88/88 |
| `stage3d_agal_cross_product` | output_mismatch | 0/0 | 0/0 |
| `stage3d_bitmap` | output_mismatch | 0/0 | 0/0 |
| `stage3d_float1_index` | output_mismatch | 0/0 | 0/0 |
| `stage3d_fractal` | output_mismatch | 0/0 | 0/0 |
| `stage3d_ignore_sampler_override` | output_mismatch | 0/0 | 0/0 |
| `stage3d_program_constants_bytearray_be` | output_mismatch | 0/0 | 0/0 |
| `stage3d_program_constants_bytearray_le` | output_mismatch | 0/0 | 0/0 |
| `stage3d_raytrace` | output_mismatch | 0/0 | 0/0 |
| `stage3d_rotating_cube` | output_mismatch | 0/0 | 0/0 |
| `stage3d_sampler` | output_mismatch | 0/0 | 0/0 |
| `stage3d_sampler_partial_upload` | output_mismatch | 0/0 | 0/0 |
| `stage3d_stencil` | output_mismatch | 0/0 | 0/0 |
| `stage3d_texture` | output_mismatch | 0/0 | 0/0 |
| `stage3d_texture_bytearray` | output_mismatch | 0/0 | 0/0 |
| `stage3d_texture_bytearray_compressed_alpha` | output_mismatch | 0/0 | 0/0 |
| `stage3d_texture_bytearray_compressed_raw_alpha` | output_mismatch | 0/0 | 0/0 |
| `stage3d_triangle` | output_mismatch | 0/0 | 0/0 |
| `stage3d_triangle_bytes4` | output_mismatch | 0/0 | 0/0 |
| `stage3d_triangle_float1` | output_mismatch | 0/0 | 0/0 |
| `stage3d_triangle_index_upload` | output_mismatch | 0/0 | 0/0 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `edittext_align` | segfault | 60/60 | 60/60 |
| `loader_method` | output_mismatch | 85/85 | 83/85 |
| `uncaught_error_basic` | output_mismatch | 2/2 | 0/2 |

## Line Count Changed (159)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `flash_media_video_constructor` | output_mismatch | 0/156 | 25/156 | -25 |
| `sprite_dropTarget` | ruffle_matched | 6/19 | 15/19 | -9 |
| `button_nested_frame_simple` | output_mismatch | 24/27 | 27/27 | -3 |
| `abstract_classes` | output_mismatch | 0/132 | 0/132 | 0 |
| `accessibility` | output_mismatch | 0/1 | 0/1 | 0 |
| `accessibilityimplementation` | output_mismatch | 0/18 | 0/18 | 0 |
| `air_datagram_socket` | output_mismatch | 0/1 | 0/1 | 0 |
| `air_ifilepromise` | output_mismatch | 0/1 | 0/1 | 0 |
| `amf_array_serialization` | output_mismatch | 4/17 | 4/17 | 0 |
| `appdomain_lookup_edge_cases` | output_mismatch | 7/32 | 7/32 | 0 |
| `applicationdomain_getqualifieddefinitionnames` | output_mismatch | 0/9 | 0/9 | 0 |
| `array_access_oob_interpreter` | ruffle_matched | 0/1 | 0/1 | 0 |
| `audio_computespectrum` | output_mismatch | 0/118 | 0/118 | 0 |
| `av_networking_params` | output_mismatch | 0/9 | 0/9 | 0 |
| `av_tag_data` | output_mismatch | 0/2 | 0/2 | 0 |
| `avm1_root` | output_mismatch | 0/58 | 0/58 | 0 |
| `bevel_filter` | output_mismatch | 4/187 | 4/187 | 0 |
| `blend_shader_luma_lighten` | output_mismatch | 1/3 | 1/3 | 0 |
| `blur_filter` | output_mismatch | 4/43 | 4/43 | 0 |
| `coerce_property` | ruffle_matched | 33/36 | 33/36 | 0 |
| `color_matrix_filter` | output_mismatch | 4/19 | 4/19 | 0 |
| `content_element_basic` | output_mismatch | 0/50 | 0/50 | 0 |
| `context3d_creation` | output_mismatch | 0/9 | 0/9 | 0 |
| `convolution_filter` | output_mismatch | 7/89 | 7/89 | 0 |
| `currency_parse_result` | output_mismatch | 0/7 | 0/7 | 0 |
| `describe_type_json` | output_mismatch | 1/301 | 1/301 | 0 |
| `displacement_map_filter` | output_mismatch | 7/61 | 7/61 | 0 |
| `displayobject_filters` | output_mismatch | 5/17 | 5/17 | 0 |
| `displayobject_getrect` | output_mismatch | 2/16 | 2/16 | 0 |
| `displayobject_hittestpoint_root` | output_mismatch | 5/13 | 5/13 | 0 |
| `displayobjectcontainer_getobjectsunderpoint` | output_mismatch | 13/15 | 13/15 | 0 |
| `east_asian_justifier_clone` | output_mismatch | 0/8 | 0/8 | 0 |
| `element_format_clone` | output_mismatch | 0/44 | 0/44 | 0 |
| `element_format_properties` | output_mismatch | 0/235 | 0/235 | 0 |
| `escape_multi_byte` | output_mismatch | 1/45 | 1/45 | 0 |
| `external_interface` | output_mismatch | 3/105 | 3/105 | 0 |
| `filereference_browse_cancel` | output_mismatch | 0/3 | 0/3 | 0 |
| `filereference_browse_select` | output_mismatch | 0/9 | 0/9 | 0 |
| `filereference_load` | output_mismatch | 0/31 | 0/31 | 0 |
| `filereference_save` | output_mismatch | 0/16 | 0/16 | 0 |
| `filereference_save_and_browse` | output_mismatch | 0/42 | 0/42 | 0 |
| `filereference_save_and_load` | output_mismatch | 0/22 | 0/22 | 0 |
| `filereference_uninitialized` | output_mismatch | 0/8 | 0/8 | 0 |
| `filereferencelist_browse_cancel` | output_mismatch | 0/6 | 0/6 | 0 |
| `filereferencelist_browse_select` | output_mismatch | 0/7 | 0/7 | 0 |
| `filters_array_holes` | output_mismatch | 7/25 | 7/25 | 0 |
| `flash_media_video_rotation_probe` | output_mismatch | 1/27 | 1/27 | 0 |
| `flash_media_video_setter` | output_mismatch | 1/40 | 1/40 | 0 |
| `font_enumeratefonts_order` | output_mismatch | 0/9 | 0/9 | 0 |
| `game_input` | output_mismatch | 0/4 | 0/4 | 0 |
| `generate_random_bytes` | output_mismatch | 0/3 | 0/3 | 0 |
| `geom_transform` | output_mismatch | 20/74 | 20/74 | 0 |
| `getouterscope_two_classobjects` | output_mismatch | 8/13 | 8/13 | 0 |
| `glow_filter` | output_mismatch | 4/127 | 4/127 | 0 |
| `gradient_bevel_filter` | output_mismatch | 4/206 | 4/206 | 0 |
| `gradient_glow_filter` | output_mismatch | 4/206 | 4/206 | 0 |
| `instantiate_root_character` | output_mismatch | 0/4 | 0/4 | 0 |
| `large_preload_from_bytes` | output_mismatch | 18/51 | 18/51 | 0 |
| `loader_loadbytes_events` | output_mismatch | 11/30 | 11/30 | 0 |
| `loader_try_click_root` | output_mismatch | 0/16 | 0/16 | 0 |
| `localconnection` | output_mismatch | 76/890 | 76/890 | 0 |
| `matrix` | output_mismatch | 281/338 | 281/338 | 0 |
| `matrix3d` | output_mismatch | 1/57 | 1/57 | 0 |
| `matrix3d_compose` | output_mismatch | 0/34 | 0/34 | 0 |
| `matrix3d_invert` | output_mismatch | 0/18 | 0/18 | 0 |
| `native_menu_basic` | output_mismatch | 0/19 | 0/19 | 0 |
| `net_stream_play_options` | output_mismatch | 0/6 | 0/6 | 0 |
| `netconnection_close` | output_mismatch | 0/55 | 0/55 | 0 |
| `netconnection_properties` | output_mismatch | 0/78 | 0/78 | 0 |
| `netconnection_send_remote` | output_mismatch | 0/50 | 0/50 | 0 |
| `netconnection_serialize_arrays` | output_mismatch | 0/6 | 0/6 | 0 |
| `netfilterevent` | output_mismatch | 0/10 | 0/10 | 0 |
| `netstream_client` | output_mismatch | 0/10 | 0/10 | 0 |
| `netstream_connect` | output_mismatch | 0/7 | 0/7 | 0 |
| `netstream_flv_date` | output_mismatch | 1/4 | 1/4 | 0 |
| `netstream_play_flv` | output_mismatch | 0/16 | 0/16 | 0 |
| `netstream_play_stop_replay` | output_mismatch | 0/11 | 0/11 | 0 |
| `netstream_seek_flv` | output_mismatch | 0/49 | 0/49 | 0 |
| `perspective_projection` | output_mismatch | 4/1443 | 4/1443 | 0 |
| `pixelbender_ceil` | output_mismatch | 5/77 | 5/77 | 0 |
| `pixelbender_conditional` | output_mismatch | 0/138 | 0/138 | 0 |
| `pixelbender_conversions` | output_mismatch | 1/270 | 1/270 | 0 |
| `pixelbender_dithering` | output_mismatch | 0/8 | 0/8 | 0 |
| `pixelbender_div` | output_mismatch | 1/36 | 1/36 | 0 |
| `pixelbender_effect_glassDisplace_shaderfilter` | output_mismatch | 0/4 | 0/4 | 0 |
| `pixelbender_input` | output_mismatch | 4/103 | 4/103 | 0 |
| `pixelbender_logicalnot` | output_mismatch | 0/20 | 0/20 | 0 |
| `pixelbender_malformed_data` | output_mismatch | 0/190 | 0/190 | 0 |
| `pixelbender_multiple_out_params` | output_mismatch | 0/1 | 0/1 | 0 |
| `pixelbender_outputs` | output_mismatch | 0/13 | 0/13 | 0 |
| `pixelbender_param_qualifier` | output_mismatch | 0/512 | 0/512 | 0 |
| `pixelbender_parameters` | output_mismatch | 1/1563 | 1/1563 | 0 |
| `pixelbender_parameters_bool` | output_mismatch | 0/240 | 0/240 | 0 |
| `pixelbender_parameters_int_vs_bool` | output_mismatch | 0/54 | 0/54 | 0 |
| `pixelbender_rsqrt` | output_mismatch | 1/24 | 1/24 | 0 |
| `pixelbender_shaderdata` | output_mismatch | 0/49 | 0/49 | 0 |
| `pixelbender_shaderdata_setter` | output_mismatch | 3/99 | 3/99 | 0 |
| `pixelbender_sign` | output_mismatch | 5/60 | 5/60 | 0 |
| `pixelbender_vector_output` | output_mismatch | 1/11 | 1/11 | 0 |
| `place_and_lookup/swf10` | output_mismatch | 29/33 | 29/33 | 0 |
| `place_and_lookup/swf9` | output_mismatch | 29/33 | 29/33 | 0 |
| `print_job_options` | output_mismatch | 0/3 | 0/3 | 0 |
| `property_is_enumerable` | output_mismatch | 25/114 | 25/114 | 0 |
| `property_priority_definition_names_order` | output_mismatch | 0/2 | 0/2 | 0 |
| `responder_null_callbacks` | output_mismatch | 0/1 | 0/1 | 0 |
| `scopes_dont_cache/order-1` | output_mismatch | 0/1 | 0/1 | 0 |
| `scopes_dont_cache/order-2` | output_mismatch | 0/1 | 0/1 | 0 |
| `security_domain_current` | output_mismatch | 0/2 | 0/2 | 0 |
| `shaderparameter_value` | output_mismatch | 0/4 | 0/4 | 0 |
| `socket_after_disconnect` | output_mismatch | 0/1 | 0/1 | 0 |
| `socket_close` | output_mismatch | 0/2 | 0/2 | 0 |
| `socket_connect` | output_mismatch | 0/4 | 0/4 | 0 |
| `socket_errors` | output_mismatch | 0/56 | 0/56 | 0 |
| `socket_read_big` | output_mismatch | 0/48 | 0/48 | 0 |
| `socket_read_little` | output_mismatch | 0/48 | 0/48 | 0 |
| `socket_read_write_object` | output_mismatch | 0/8 | 0/8 | 0 |
| `socket_write_big` | output_mismatch | 0/15 | 0/15 | 0 |
| `socket_write_little` | output_mismatch | 0/14 | 0/14 | 0 |
| `sound_load_multiple` | output_mismatch | 3/19 | 3/19 | 0 |
| `space_justifier_clone` | output_mismatch | 0/12 | 0/12 | 0 |
| `stage3d_agal_upload_errors` | output_mismatch | 0/66 | 0/66 | 0 |
| `stage3d_blend` | output_mismatch | 0/81 | 0/81 | 0 |
| `stage3d_context3d_string_args` | output_mismatch | 0/158 | 0/158 | 0 |
| `stage3d_errors` | output_mismatch | 0/7 | 0/7 | 0 |
| `stage3d_errors_atf` | output_mismatch | 0/3 | 0/3 | 0 |
| `stage3d_errors_swf_29` | output_mismatch | 0/6 | 0/6 | 0 |
| `stage3d_multistage_triangle` | output_mismatch | 0/3 | 0/3 | 0 |
| `stage3d_program_constants_invalid_input` | output_mismatch | 0/21 | 0/21 | 0 |
| `stage3d_x_y` | output_mismatch | 0/22 | 0/22 | 0 |
| `stage_display_state` | output_mismatch | 0/6 | 0/6 | 0 |
| `stage_domain_getQualifiedDefinitionNames` | output_mismatch | 0/5 | 0/5 | 0 |
| `stage_scale_factor` | output_mismatch | 6/12 | 6/12 | 0 |
| `stage_stage3Ds_vector` | output_mismatch | 0/1 | 0/1 | 0 |
| `supercalls_weird` | output_mismatch | 0/2 | 0/2 | 0 |
| `superinterface_call` | output_mismatch | 15/20 | 15/20 | 0 |
| `tabstop_properties` | output_mismatch | 0/105 | 0/105 | 0 |
| `text_element_basic` | output_mismatch | 0/34 | 0/34 | 0 |
| `text_engine_groupelement` | output_mismatch | 1/64 | 1/64 | 0 |
| `textblock_createline_errors` | output_mismatch | 0/23 | 0/23 | 0 |
| `textblock_createline_fte` | output_mismatch | 0/9 | 0/9 | 0 |
| `textblock_properties` | output_mismatch | 0/118 | 0/118 | 0 |
| `textline_inapplicable_properties` | output_mismatch | 0/10 | 0/10 | 0 |
| `textline_name` | output_mismatch | 0/1 | 0/1 | 0 |
| `textline_splitting_basic` | output_mismatch | 0/76 | 0/76 | 0 |
| `textline_throwerror` | output_mismatch | 0/30 | 0/30 | 0 |
| `textline_validity` | output_mismatch | 1/162 | 1/162 | 0 |
| `url_vars` | output_mismatch | 3/27 | 3/27 | 0 |
| `urlstream_basic` | output_mismatch | 0/5 | 0/5 | 0 |
| `utils3d` | output_mismatch | 0/7 | 0/7 | 0 |
| `vector3d` | output_mismatch | 24/397 | 24/397 | 0 |
| `verify_illegal_opcode` | output_mismatch | 0/1 | 0/1 | 0 |
| `xml_socket` | output_mismatch | 0/11 | 0/11 | 0 |
| `filefilter_properties` | output_mismatch | 1/4 | 0/4 | +1 |
| `rectangle` | output_mismatch | 2/1094 | 1/1094 | +1 |
| `uncaught_errors_stringified` | output_mismatch | 2/18 | 1/18 | +1 |
| `bitmapdata_zero_size` | output_mismatch | 7/8 | 5/8 | +2 |
| `loader_load` | output_mismatch | 126/128 | 124/128 | +2 |
| `mouseevent_stagexy` | output_mismatch | 4/35 | 1/35 | +3 |
| `event_handler_exception` | output_mismatch | 5/11 | 1/11 | +4 |
