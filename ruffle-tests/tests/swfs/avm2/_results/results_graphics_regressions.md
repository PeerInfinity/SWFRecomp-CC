# Graphics vs Trace Mode Differences

Trace: 929/1221 passing | Graphics: 1080/1224 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (150 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `abstract_classes` | Output Mismatch | 0/132 lines match |
| 2 | `accessibility` | Output Mismatch | 0/1 lines match |
| 3 | `activation_class` | Output Mismatch | 3/6 lines match |
| 4 | `air_ifilepromise` | Output Mismatch | 0/1 lines match |
| 5 | `amf_array_serialization` | Output Mismatch | 6/17 lines match |
| 6 | `applicationdomain_getqualifieddefinitionnames` | Output Mismatch | 0/9 lines match |
| 7 | `applicationdomain_hasdefinition_null` | Output Mismatch | 1/2 lines match |
| 8 | `av_tag_data` | Output Mismatch | 0/2 lines match |
| 9 | `bevel_filter` | Output Mismatch | 4/187 lines match |
| 10 | `bitmapdata_zero_size` | Output Mismatch | 5/8 lines match |
| 11 | `blend_mode_null` | Output Mismatch | 0/1 lines match |
| 12 | `blend_shader_luma_lighten` | Output Mismatch | 1/3 lines match |
| 13 | `blur_filter` | Output Mismatch | 4/43 lines match |
| 14 | `button_bounds` | Output Mismatch | 0/1 lines match |
| 15 | `button_hittest` | Output Mismatch | 1/2 lines match |
| 16 | `color_matrix_filter` | Output Mismatch | 4/19 lines match |
| 17 | `construct_interface` | Output Mismatch | 2/3 lines match |
| 18 | `constructprop_method` | Output Mismatch | 0/2 lines match |
| 19 | `content_element_basic` | Output Mismatch | 0/50 lines match |
| 20 | `context3d_creation` | Output Mismatch | 0/9 lines match |
| 21 | `convolution_filter` | Output Mismatch | 7/89 lines match |
| 22 | `core_exceptions` | Output Mismatch | 41/47 lines match |
| 23 | `cpool_index_invalid_bytecode_1` | Output Mismatch | 0/6 lines match |
| 24 | `cpool_index_invalid_bytecode_2` | Output Mismatch | 0/3 lines match |
| 25 | `cpool_index_invalid_bytecode_3` | Output Mismatch | 0/1 lines match |
| 26 | `displacement_map_filter` | Output Mismatch | 7/61 lines match |
| 27 | `displayobject_filters` | Output Mismatch | 5/17 lines match |
| 28 | `displayobject_hittestpoint` | Output Mismatch | 47/49 lines match |
| 29 | `displayobject_hittestpoint_root` | Output Mismatch | 11/13 lines match |
| 30 | `displayobject_opaque_background` | Output Mismatch | 5/6 lines match |
| 31 | `displayobjectcontainer_getobjectsunderpoint` | Output Mismatch | 13/15 lines match |
| 32 | `drop_shadow_filter` | Output Mismatch | 4/172 lines match |
| 33 | `east_asian_justifier_clone` | Output Mismatch | 0/8 lines match |
| 34 | `element_format_clone` | Output Mismatch | 0/44 lines match |
| 35 | `element_format_constructor_order` | Output Mismatch | 4/64 lines match |
| 36 | `element_format_properties` | Output Mismatch | 0/235 lines match |
| 37 | `encode_uri_surrogate_pair_invalid` | Output Mismatch | 0/8 lines match |
| 38 | `error_tostring_more` | Output Mismatch | 84/86 lines match |
| 39 | `escape_multi_byte` | Output Mismatch | 1/45 lines match |
| 40 | `filter_rewind` | Output Mismatch | 2/8 lines match |
| 41 | `filters_array_holes` | Output Mismatch | 7/25 lines match |
| 42 | `flash_media_video_constructor` | Output Mismatch | 25/156 lines match |
| 43 | `flash_media_video_rotation_probe` | Output Mismatch | 1/27 lines match |
| 44 | `flash_media_video_setter` | Output Mismatch | 1/40 lines match |
| 45 | `font_enumeratefonts_order` | Output Mismatch | 0/9 lines match |
| 46 | `font_registerfont` | Output Mismatch | 8/129 lines match |
| 47 | `game_input` | Output Mismatch | 0/4 lines match |
| 48 | `generate_random_bytes` | Output Mismatch | 0/3 lines match |
| 49 | `getouterscope_two_classobjects` | Output Mismatch | 8/13 lines match |
| 50 | `glow_filter` | Output Mismatch | 4/127 lines match |
| 51 | `gradient_bevel_filter` | Output Mismatch | 4/206 lines match |
| 52 | `gradient_glow_filter` | Output Mismatch | 4/206 lines match |
| 53 | `instantiate_root_character` | Output Mismatch | 3/4 lines match |
| 54 | `invalid_utf8` | Output Mismatch | 11/12 lines match |
| 55 | `issue_8630_placeremoveplace` | Output Mismatch | 13/15 lines match |
| 56 | `issue_8630_placeremoveplace_scriptremove` | Output Mismatch | 13/16 lines match |
| 57 | `loader_method` | Output Mismatch | 83/85 lines match |
| 58 | `localconnection_send` | Output Mismatch | 0/4 lines match |
| 59 | `matrix3d` | Output Mismatch | 1/57 lines match |
| 60 | `matrix3d_compose` | Output Mismatch | 0/34 lines match |
| 61 | `matrix3d_invert` | Output Mismatch | 0/18 lines match |
| 62 | `method_without_body` | Runtime Error | 0/3 lines match |
| 63 | `movieclip_hittest` | Output Mismatch | 65/67 lines match |
| 64 | `netconnection_send_remote` | Output Mismatch | 2/50 lines match |
| 65 | `netconnection_serialize_arrays` | Output Mismatch | 1/6 lines match |
| 66 | `newclass_mismatched` | Output Mismatch | 0/4 lines match |
| 67 | `parse_float_swf10` | Output Mismatch | 79/81 lines match |
| 68 | `parse_int` | Output Mismatch | 133/135 lines match |
| 69 | `perspective_projection_basic` | Output Mismatch | 35/40 lines match |
| 70 | `pixelbender_ceil` | Output Mismatch | 5/77 lines match |
| 71 | `pixelbender_conditional` | Output Mismatch | 0/138 lines match |
| 72 | `pixelbender_conversions` | Output Mismatch | 1/270 lines match |
| 73 | `pixelbender_dithering` | Output Mismatch | 0/8 lines match |
| 74 | `pixelbender_div` | Output Mismatch | 1/36 lines match |
| 75 | `pixelbender_effect_glassDisplace_shaderfilter` | Output Mismatch | 0/4 lines match |
| 76 | `pixelbender_eof` | Output Mismatch | 1/7 lines match |
| 77 | `pixelbender_input` | Output Mismatch | 4/103 lines match |
| 78 | `pixelbender_logicalnot` | Output Mismatch | 0/20 lines match |
| 79 | `pixelbender_malformed_data` | Output Mismatch | 0/190 lines match |
| 80 | `pixelbender_multiple_out_params` | Output Mismatch | 0/1 lines match |
| 81 | `pixelbender_no_out_param` | Output Mismatch | 0/6 lines match |
| 82 | `pixelbender_outputs` | Output Mismatch | 0/13 lines match |
| 83 | `pixelbender_padding_bytes` | Output Mismatch | 0/66 lines match |
| 84 | `pixelbender_param_qualifier` | Output Mismatch | 0/512 lines match |
| 85 | `pixelbender_parameters` | Output Mismatch | 1/1563 lines match |
| 86 | `pixelbender_parameters_bool` | Output Mismatch | 0/240 lines match |
| 87 | `pixelbender_parameters_int_vs_bool` | Output Mismatch | 0/54 lines match |
| 88 | `pixelbender_parse_errors` | Output Mismatch | 0/6 lines match |
| 89 | `pixelbender_rsqrt` | Output Mismatch | 1/24 lines match |
| 90 | `pixelbender_select_kinds` | Output Mismatch | 0/8 lines match |
| 91 | `pixelbender_shaderdata` | Output Mismatch | 0/49 lines match |
| 92 | `pixelbender_shaderdata_setter` | Output Mismatch | 3/99 lines match |
| 93 | `pixelbender_sign` | Output Mismatch | 5/60 lines match |
| 94 | `pixelbender_vector_output` | Output Mismatch | 1/11 lines match |
| 95 | `place_and_lookup/swf10` | Output Mismatch | 29/33 lines match |
| 96 | `place_and_lookup/swf9` | Output Mismatch | 29/33 lines match |
| 97 | `print_job_options` | Output Mismatch | 0/3 lines match |
| 98 | `property_is_enumerable_reset` | Output Mismatch | 22/23 lines match |
| 99 | `property_priority_chained` | Output Mismatch | 1/4 lines match |
| 100 | `property_priority_definition_names_order` | Output Mismatch | 0/2 lines match |
| 101 | `rectangle` | Output Mismatch | 1/1094 lines match |
| 102 | `rtqname_not_namespace` | Runtime Error | 1/12 lines match |
| 103 | `scopes_dont_cache/order-1` | Output Mismatch | 0/1 lines match |
| 104 | `scopes_dont_cache/order-2` | Output Mismatch | 0/1 lines match |
| 105 | `security_domain_current` | Output Mismatch | 0/2 lines match |
| 106 | `shaderparameter_value` | Output Mismatch | 0/4 lines match |
| 107 | `space_justifier_clone` | Output Mismatch | 0/12 lines match |
| 108 | `stage3d_agal_upload_errors` | Output Mismatch | 0/66 lines match |
| 109 | `stage3d_blend` | Output Mismatch | 0/81 lines match |
| 110 | `stage3d_context3d_string_args` | Output Mismatch | 0/158 lines match |
| 111 | `stage3d_errors` | Output Mismatch | 0/7 lines match |
| 112 | `stage3d_errors_atf` | Output Mismatch | 0/3 lines match |
| 113 | `stage3d_errors_swf_29` | Output Mismatch | 0/6 lines match |
| 114 | `stage3d_multistage_triangle` | Output Mismatch | 0/3 lines match |
| 115 | `stage3d_program_constants_invalid_input` | Output Mismatch | 0/21 lines match |
| 116 | `stage3d_x_y` | Output Mismatch | 0/22 lines match |
| 117 | `stage_domain_getQualifiedDefinitionNames` | Output Mismatch | 1/5 lines match |
| 118 | `stage_stage3Ds_vector` | Output Mismatch | 0/1 lines match |
| 119 | `static_text` | Output Mismatch | 0/3 lines match |
| 120 | `stylesheet` | Output Mismatch | 220/221 lines match |
| 121 | `supercalls_weird` | Output Mismatch | 0/2 lines match |
| 122 | `superinterface_call` | Output Mismatch | 15/20 lines match |
| 123 | `superinterface_instanceof` | Output Mismatch | 4/18 lines match |
| 124 | `system_setclipboard_null` | Output Mismatch | 0/1 lines match |
| 125 | `tab_ordering_arrows` | Output Mismatch | 645/1000 lines match |
| 126 | `tabstop_properties` | Output Mismatch | 0/105 lines match |
| 127 | `text_element_basic` | Output Mismatch | 0/34 lines match |
| 128 | `text_engine_groupelement` | Output Mismatch | 1/64 lines match |
| 129 | `textblock_createline_errors` | Output Mismatch | 0/23 lines match |
| 130 | `textblock_createline_fte` | Output Mismatch | 0/9 lines match |
| 131 | `textblock_properties` | Output Mismatch | 0/118 lines match |
| 132 | `textline_inapplicable_properties` | Output Mismatch | 0/10 lines match |
| 133 | `textline_name` | Output Mismatch | 0/1 lines match |
| 134 | `textline_splitting_basic` | Output Mismatch | 0/76 lines match |
| 135 | `textline_throwerror` | Output Mismatch | 0/30 lines match |
| 136 | `textline_validity` | Output Mismatch | 1/162 lines match |
| 137 | `uncaught_error_basic` | Output Mismatch | 0/2 lines match |
| 138 | `url_vars` | Output Mismatch | 3/27 lines match |
| 139 | `urlstream_basic` | Output Mismatch | 0/5 lines match |
| 140 | `utils3d` | Output Mismatch | 0/7 lines match |
| 141 | `vector3d` | Output Mismatch | 24/397 lines match |
| 142 | `verification` | Output Mismatch | 5/8 lines match |
| 143 | `verify_dxns_without_flag` | Output Mismatch | 1/3 lines match |
| 144 | `verify_exception_target_two_jumps` | Output Mismatch | 0/1 lines match |
| 145 | `verify_illegal_opcode` | Output Mismatch | 0/1 lines match |
| 146 | `verify_jump_to_middle_of_op` | Output Mismatch | 0/1 lines match |
| 147 | `verify_method_info_oob` | Output Mismatch | 0/1 lines match |
| 148 | `verify_stack` | Output Mismatch | 2/5 lines match |
| 149 | `verify_typecheck` | Runtime Error | 0/4 lines match |
| 150 | `xml_appendchild_swf_v21` | Output Mismatch | 12/14 lines match |
