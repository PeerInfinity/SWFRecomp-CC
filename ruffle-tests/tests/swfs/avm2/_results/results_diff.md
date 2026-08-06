# Ruffle Test Results Diff

**Previous:** `72fdc5e933a6` (2026-07-29T03:45:41.045758+00:00)
**Current:** `b4c983ea4c3d` (2026-08-02T09:26:35.614573+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 929 | 1084 | +155 |
| Total | 1221 | 1225 | +4 |
| Pass rate | 76.1% | 88.5% | +12.4% |
| Mismatched lines | 43868 | 33409 | -10459 |
|   Decreased | | | -10720 |
|   Increased | | | +14 |

## Newly Passing (154)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `abstract_classes` | output_mismatch | 0/132 | 132/132 |
| `accessibility` | output_mismatch | 0/1 | 1/1 |
| `activation_class` | output_mismatch | 3/6 | 6/6 |
| `air_ifilepromise` | output_mismatch | 0/1 | 1/1 |
| `amf_array_serialization` | output_mismatch | 6/17 | 17/17 |
| `applicationdomain_getqualifieddefinitionnames` | output_mismatch | 0/9 | 9/9 |
| `applicationdomain_hasdefinition_null` | output_mismatch | 1/2 | 2/2 |
| `av_tag_data` | output_mismatch | 0/2 | 2/2 |
| `bevel_filter` | output_mismatch | 4/187 | 187/187 |
| `bitmapdata_zero_size` | output_mismatch | 5/8 | 8/8 |
| `blend_mode_null` | output_mismatch | 0/1 | 1/1 |
| `blend_shader_luma_lighten` | output_mismatch | 1/3 | 3/3 |
| `blur_filter` | output_mismatch | 4/43 | 43/43 |
| `button_bounds` | output_mismatch | 0/1 | 1/1 |
| `button_hittest` | output_mismatch | 1/2 | 2/2 |
| `color_matrix_filter` | output_mismatch | 4/19 | 19/19 |
| `construct_interface` | output_mismatch | 2/3 | 3/3 |
| `constructprop_method` | output_mismatch | 0/2 | 2/2 |
| `content_element_basic` | output_mismatch | 0/50 | 50/50 |
| `context3d_creation` | output_mismatch | 0/9 | 9/9 |
| `convolution_filter` | output_mismatch | 7/89 | 89/89 |
| `core_exceptions` | output_mismatch | 41/47 | 47/47 |
| `cpool_index_invalid_bytecode_1` | output_mismatch | 0/6 | 6/6 |
| `cpool_index_invalid_bytecode_2` | output_mismatch | 0/3 | 3/3 |
| `cpool_index_invalid_bytecode_3` | output_mismatch | 0/1 | 1/1 |
| `displacement_map_filter` | output_mismatch | 7/61 | 61/61 |
| `displayobject_filters` | output_mismatch | 5/17 | 17/17 |
| `displayobject_hittestpoint` | output_mismatch | 47/49 | 49/49 |
| `displayobject_hittestpoint_root` | output_mismatch | 11/13 | 13/13 |
| `displayobject_opaque_background` | output_mismatch | 5/6 | 6/6 |
| `displayobjectcontainer_getobjectsunderpoint` | output_mismatch | 13/15 | 15/15 |
| `drop_shadow_filter` | output_mismatch | 4/172 | 172/172 |
| `east_asian_justifier_clone` | output_mismatch | 0/8 | 8/8 |
| `element_format_clone` | output_mismatch | 0/44 | 44/44 |
| `element_format_constructor_order` | output_mismatch | 4/64 | 64/64 |
| `element_format_properties` | output_mismatch | 0/235 | 235/235 |
| `encode_uri_surrogate_pair_invalid` | output_mismatch | 0/8 | 8/8 |
| `error_tostring_more` | output_mismatch | 84/86 | 86/86 |
| `escape_multi_byte` | output_mismatch | 1/45 | 45/45 |
| `filter_rewind` | output_mismatch | 2/8 | 8/8 |
| `filters_array_holes` | output_mismatch | 7/25 | 25/25 |
| `flash_media_video_constructor` | output_mismatch | 25/156 | 156/156 |
| `flash_media_video_rotation_probe` | output_mismatch | 1/27 | 27/27 |
| `flash_media_video_setter` | output_mismatch | 1/40 | 40/40 |
| `font_enumeratefonts_order` | output_mismatch | 0/9 | 9/9 |
| `font_registerfont` | output_mismatch | 8/129 | 129/129 |
| `game_input` | output_mismatch | 0/4 | 4/4 |
| `generate_random_bytes` | output_mismatch | 0/3 | 3/3 |
| `getouterscope_two_classobjects` | output_mismatch | 8/13 | 13/13 |
| `glow_filter` | output_mismatch | 4/127 | 127/127 |
| `gradient_bevel_filter` | output_mismatch | 4/206 | 206/206 |
| `gradient_glow_filter` | output_mismatch | 4/206 | 206/206 |
| `instantiate_root_character` | output_mismatch | 3/4 | 4/4 |
| `invalid_utf8` | output_mismatch | 11/12 | 12/12 |
| `issue_8630_placeremoveplace` | output_mismatch | 13/15 | 15/15 |
| `issue_8630_placeremoveplace_scriptremove` | output_mismatch | 13/16 | 16/16 |
| `loader_method` | output_mismatch | 83/85 | 85/85 |
| `localconnection_send` | output_mismatch | 0/4 | 4/4 |
| `matrix3d` | output_mismatch | 1/57 | 57/57 |
| `matrix3d_compose` | output_mismatch | 0/34 | 34/34 |
| `matrix3d_invert` | output_mismatch | 0/18 | 18/18 |
| `method_without_body` | runtime_error | 0/3 | 3/3 |
| `movieclip_hittest` | output_mismatch | 65/67 | 67/67 |
| `netconnection_send_remote` | output_mismatch | 2/50 | 50/50 |
| `netconnection_serialize_arrays` | output_mismatch | 1/6 | 6/6 |
| `newclass_mismatched` | output_mismatch | 0/4 | 4/4 |
| `parse_float_swf10` | output_mismatch | 79/81 | 81/81 |
| `parse_int` | output_mismatch | 133/135 | 135/135 |
| `perspective_projection_basic` | output_mismatch | 35/40 | 40/40 |
| `pixelbender_ceil` | output_mismatch | 5/77 | 77/77 |
| `pixelbender_conditional` | output_mismatch | 0/138 | 138/138 |
| `pixelbender_conversions` | output_mismatch | 1/270 | 270/270 |
| `pixelbender_dithering` | output_mismatch | 0/8 | 8/8 |
| `pixelbender_div` | output_mismatch | 1/36 | 36/36 |
| `pixelbender_effect_glassDisplace_shaderfilter` | output_mismatch | 0/4 | 4/4 |
| `pixelbender_eof` | output_mismatch | 1/7 | 7/7 |
| `pixelbender_input` | output_mismatch | 4/103 | 103/103 |
| `pixelbender_logicalnot` | output_mismatch | 0/20 | 20/20 |
| `pixelbender_malformed_data` | output_mismatch | 0/190 | 190/190 |
| `pixelbender_multiple_out_params` | output_mismatch | 0/1 | 1/1 |
| `pixelbender_no_out_param` | output_mismatch | 0/6 | 6/6 |
| `pixelbender_outputs` | output_mismatch | 0/13 | 13/13 |
| `pixelbender_padding_bytes` | output_mismatch | 0/22 | 22/22 |
| `pixelbender_param_qualifier` | output_mismatch | 0/512 | 512/512 |
| `pixelbender_parameters` | output_mismatch | 1/1563 | 1563/1563 |
| `pixelbender_parameters_bool` | output_mismatch | 0/240 | 240/240 |
| `pixelbender_parameters_int_vs_bool` | output_mismatch | 0/54 | 54/54 |
| `pixelbender_parse_errors` | output_mismatch | 0/6 | 6/6 |
| `pixelbender_rsqrt` | output_mismatch | 1/24 | 24/24 |
| `pixelbender_select_kinds` | output_mismatch | 0/8 | 8/8 |
| `pixelbender_shaderdata` | output_mismatch | 0/49 | 49/49 |
| `pixelbender_shaderdata_setter` | output_mismatch | 3/99 | 99/99 |
| `pixelbender_sign` | output_mismatch | 5/60 | 60/60 |
| `pixelbender_vector_output` | output_mismatch | 1/11 | 11/11 |
| `place_and_lookup/swf10` | output_mismatch | 29/33 | 33/33 |
| `place_and_lookup/swf9` | output_mismatch | 29/33 | 33/33 |
| `print_job_options` | output_mismatch | 0/3 | 3/3 |
| `property_is_enumerable_reset` | output_mismatch | 22/23 | 23/23 |
| `property_priority_chained` | output_mismatch | 1/4 | 4/4 |
| `property_priority_definition_names_order` | output_mismatch | 0/2 | 2/2 |
| `rectangle` | output_mismatch | 1/1094 | 1094/1094 |
| `rtqname_not_namespace` | runtime_error | 1/12 | 12/12 |
| `scopes_dont_cache/order-1` | output_mismatch | 0/1 | 1/1 |
| `scopes_dont_cache/order-2` | output_mismatch | 0/1 | 1/1 |
| `security_domain_current` | output_mismatch | 0/2 | 2/2 |
| `shaderparameter_value` | output_mismatch | 0/4 | 4/4 |
| `space_justifier_clone` | output_mismatch | 0/12 | 12/12 |
| `stage3d_agal_upload_errors` | output_mismatch | 0/66 | 66/66 |
| `stage3d_blend` | output_mismatch | 0/81 | 81/81 |
| `stage3d_context3d_string_args` | output_mismatch | 0/158 | 158/158 |
| `stage3d_errors` | output_mismatch | 0/7 | 7/7 |
| `stage3d_errors_atf` | output_mismatch | 0/3 | 3/3 |
| `stage3d_errors_swf_29` | output_mismatch | 0/6 | 6/6 |
| `stage3d_multistage_triangle` | output_mismatch | 0/3 | 3/3 |
| `stage3d_program_constants_invalid_input` | output_mismatch | 0/21 | 21/21 |
| `stage3d_x_y` | output_mismatch | 0/22 | 22/22 |
| `stage_domain_getQualifiedDefinitionNames` | output_mismatch | 1/5 | 5/5 |
| `stage_stage3Ds_vector` | output_mismatch | 0/1 | 1/1 |
| `static_text` | output_mismatch | 0/3 | 3/3 |
| `statictext_text` | output_mismatch | 0/8 | 8/8 |
| `stylesheet` | output_mismatch | 220/221 | 221/221 |
| `stylesheet_parse_color` | output_mismatch | 65/69 | 69/69 |
| `stylesheet_transform` | output_mismatch | 304/307 | 307/307 |
| `subclass_superclass_linked_symbol` | output_mismatch | 0/4 | 4/4 |
| `supercalls_weird` | output_mismatch | 0/2 | 2/2 |
| `superinterface_call` | output_mismatch | 15/20 | 20/20 |
| `superinterface_instanceof` | output_mismatch | 4/18 | 18/18 |
| `system_setclipboard_null` | output_mismatch | 0/1 | 1/1 |
| `tab_ordering_arrows` | output_mismatch | 645/998 | 998/998 |
| `tabstop_properties` | output_mismatch | 0/105 | 105/105 |
| `text_element_basic` | output_mismatch | 0/34 | 34/34 |
| `text_engine_groupelement` | output_mismatch | 1/64 | 64/64 |
| `textblock_createline_errors` | output_mismatch | 0/23 | 23/23 |
| `textblock_createline_fte` | output_mismatch | 0/9 | 9/9 |
| `textblock_properties` | output_mismatch | 0/118 | 118/118 |
| `textline_inapplicable_properties` | output_mismatch | 0/10 | 10/10 |
| `textline_name` | output_mismatch | 0/1 | 1/1 |
| `textline_splitting_basic` | output_mismatch | 0/76 | 76/76 |
| `textline_throwerror` | output_mismatch | 0/30 | 30/30 |
| `textline_validity` | output_mismatch | 1/162 | 162/162 |
| `uncaught_error_basic` | output_mismatch | 0/2 | 2/2 |
| `url_vars` | output_mismatch | 3/27 | 27/27 |
| `urlstream_basic` | output_mismatch | 0/5 | 5/5 |
| `utils3d` | output_mismatch | 0/7 | 7/7 |
| `vector3d` | output_mismatch | 24/397 | 397/397 |
| `verification` | output_mismatch | 5/8 | 8/8 |
| `verify_dxns_without_flag` | output_mismatch | 1/3 | 3/3 |
| `verify_exception_target_two_jumps` | output_mismatch | 0/1 | 1/1 |
| `verify_illegal_opcode` | output_mismatch | 0/1 | 1/1 |
| `verify_jump_to_middle_of_op` | output_mismatch | 0/1 | 1/1 |
| `verify_method_info_oob` | output_mismatch | 0/1 | 1/1 |
| `verify_stack` | output_mismatch | 2/5 | 5/5 |
| `verify_typecheck` | runtime_error | 0/4 | 4/4 |
| `xml_appendchild_swf_v21` | output_mismatch | 12/13 | 13/13 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `uncaught_errors_stringified` | output_mismatch | ruffle_matched | 1/18 | 3/18 |

## Added Tests (4)

| Test | Status | Lines |
|------|--------|-------|
| `groupelement_text` | output_mismatch | 0/156 |
| `textblock_line_changes` | output_mismatch | 125/158 |
| `textblock_recreateline` | output_mismatch | 40/98 |
| `xml_list_delete_clear_parent` | pass | 6/6 |

## Line Count Changed (48)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `perspective_projection` | output_mismatch | 4/1443 | 1368/1443 | -1364 |
| `localconnection` | output_mismatch | 67/890 | 589/890 | -522 |
| `bounds_mode` | output_mismatch | 233/269 | 253/269 | -20 |
| `loader_duplicate_class` | output_mismatch | 3/48 | 23/48 | -20 |
| `displayobject_transform` | output_mismatch | 59/89 | 67/89 | -8 |
| `displayobject_scrollrect` | output_mismatch | 14/33 | 19/33 | -5 |
| `event_handler_exception` | output_mismatch | 1/11 | 5/11 | -4 |
| `all_classes/events/swf10` | output_mismatch | 1/1638 | 3/1638 | -2 |
| `all_classes/events/swf11` | output_mismatch | 1/1750 | 3/1750 | -2 |
| `all_classes/events/swf12` | output_mismatch | 1/1814 | 3/1814 | -2 |
| `bom` | output_mismatch | 4/9 | 6/9 | -2 |
| `loader_load` | output_mismatch | 124/128 | 126/128 | -2 |
| `all_classes/accessibility/swf10` | output_mismatch | 0/88 | 1/88 | -1 |
| `all_classes/accessibility/swf30` | output_mismatch | 0/88 | 1/88 | -1 |
| `all_classes/accessibility/swf9` | output_mismatch | 0/73 | 1/73 | -1 |
| `all_classes/display/swf30` | output_mismatch | 0/2936 | 1/2936 | -1 |
| `all_classes/display3D/swf30` | output_mismatch | 0/412 | 1/412 | -1 |
| `all_classes/events/swf9` | output_mismatch | 1/1030 | 2/1030 | -1 |
| `freestanding_superclass` | ruffle_matched | 1/4 | 2/4 | -1 |
| `matrix` | output_mismatch | 281/338 | 282/338 | -1 |
| `netstream_flv_date` | output_mismatch | 1/4 | 2/4 | -1 |
| `verify_method_info_duplicate` | output_mismatch | 0/2 | 1/2 | -1 |
| `accessibilityimplementation` | output_mismatch | 0/18 | 0/18 | 0 |
| `all_classes/display3D/swf12` | output_mismatch | 1/61 | 1/61 | 0 |
| `all_classes/display3D/swf13` | output_mismatch | 0/326 | 0/326 | 0 |
| `all_classes/events/swf30` | output_mismatch | 1/2353 | 1/2353 | 0 |
| `appdomain_lookup_edge_cases` | output_mismatch | 7/32 | 7/32 | 0 |
| `array_access_oob_interpreter` | ruffle_matched | 0/1 | 0/1 | 0 |
| `audio_computespectrum` | output_mismatch | 0/118 | 0/118 | 0 |
| `avm1_root` | output_mismatch | 0/58 | 0/58 | 0 |
| `coerce_property` | ruffle_matched | 33/36 | 33/36 | 0 |
| `currency_parse_result` | output_mismatch | 0/7 | 0/7 | 0 |
| `describe_type_json` | output_mismatch | 1/301 | 1/301 | 0 |
| `displayobject_getrect` | output_mismatch | 2/16 | 2/16 | 0 |
| `external_interface` | output_mismatch | 3/105 | 3/105 | 0 |
| `geom_transform` | output_mismatch | 20/74 | 20/74 | 0 |
| `large_preload_from_bytes` | output_mismatch | 18/51 | 18/51 | 0 |
| `native_menu_basic` | output_mismatch | 0/19 | 0/19 | 0 |
| `netfilterevent` | output_mismatch | 0/10 | 0/10 | 0 |
| `property_is_enumerable` | output_mismatch | 25/114 | 25/114 | 0 |
| `sound_load_multiple` | output_mismatch | 3/19 | 3/19 | 0 |
| `stage_display_state` | output_mismatch | 0/6 | 0/6 | 0 |
| `all_classes/display/swf10` | output_mismatch | 2/2569 | 1/2569 | +1 |
| `all_classes/display/swf11` | output_mismatch | 2/2593 | 1/2593 | +1 |
| `all_classes/display/swf12` | output_mismatch | 2/2593 | 1/2593 | +1 |
| `all_classes/display/swf13` | output_mismatch | 2/2671 | 1/2671 | +1 |
| `all_classes/display/swf9` | output_mismatch | 2/1959 | 1/1959 | +1 |
| `sprite_dropTarget` | ruffle_matched | 15/19 | 6/19 | +9 |
