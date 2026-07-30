# Graphics vs Trace Mode Differences

Trace: 929/1221 passing | Graphics: 1009/1222 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (80 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `amf_array_serialization` | Output Mismatch | 6/17 lines match |
| 2 | `bevel_filter` | Output Mismatch | 4/187 lines match |
| 3 | `blend_mode_null` | Output Mismatch | 0/1 lines match |
| 4 | `blend_shader_luma_lighten` | Output Mismatch | 1/3 lines match |
| 5 | `blur_filter` | Output Mismatch | 4/43 lines match |
| 6 | `button_bounds` | Output Mismatch | 0/1 lines match |
| 7 | `button_hittest` | Output Mismatch | 1/2 lines match |
| 8 | `color_matrix_filter` | Output Mismatch | 4/19 lines match |
| 9 | `construct_interface` | Output Mismatch | 2/3 lines match |
| 10 | `context3d_creation` | Output Mismatch | 0/9 lines match |
| 11 | `convolution_filter` | Output Mismatch | 7/89 lines match |
| 12 | `cpool_index_invalid_bytecode_1` | Output Mismatch | 0/6 lines match |
| 13 | `cpool_index_invalid_bytecode_2` | Output Mismatch | 0/3 lines match |
| 14 | `cpool_index_invalid_bytecode_3` | Output Mismatch | 0/1 lines match |
| 15 | `displacement_map_filter` | Output Mismatch | 7/61 lines match |
| 16 | `displayobject_filters` | Output Mismatch | 5/17 lines match |
| 17 | `displayobject_hittestpoint` | Output Mismatch | 47/49 lines match |
| 18 | `displayobject_hittestpoint_root` | Output Mismatch | 11/13 lines match |
| 19 | `displayobjectcontainer_getobjectsunderpoint` | Output Mismatch | 13/15 lines match |
| 20 | `drop_shadow_filter` | Output Mismatch | 4/172 lines match |
| 21 | `filter_rewind` | Output Mismatch | 2/8 lines match |
| 22 | `filters_array_holes` | Output Mismatch | 7/25 lines match |
| 23 | `flash_media_video_constructor` | Output Mismatch | 25/156 lines match |
| 24 | `flash_media_video_rotation_probe` | Output Mismatch | 1/27 lines match |
| 25 | `glow_filter` | Output Mismatch | 4/127 lines match |
| 26 | `gradient_bevel_filter` | Output Mismatch | 4/206 lines match |
| 27 | `gradient_glow_filter` | Output Mismatch | 4/206 lines match |
| 28 | `localconnection_send` | Output Mismatch | 0/4 lines match |
| 29 | `matrix3d` | Output Mismatch | 1/57 lines match |
| 30 | `matrix3d_compose` | Output Mismatch | 0/34 lines match |
| 31 | `matrix3d_invert` | Output Mismatch | 0/18 lines match |
| 32 | `movieclip_hittest` | Output Mismatch | 65/67 lines match |
| 33 | `netconnection_send_remote` | Output Mismatch | 2/50 lines match |
| 34 | `netconnection_serialize_arrays` | Output Mismatch | 1/6 lines match |
| 35 | `perspective_projection_basic` | Output Mismatch | 35/40 lines match |
| 36 | `pixelbender_ceil` | Output Mismatch | 5/77 lines match |
| 37 | `pixelbender_conditional` | Output Mismatch | 0/138 lines match |
| 38 | `pixelbender_conversions` | Output Mismatch | 1/270 lines match |
| 39 | `pixelbender_dithering` | Output Mismatch | 0/8 lines match |
| 40 | `pixelbender_div` | Output Mismatch | 1/36 lines match |
| 41 | `pixelbender_effect_glassDisplace_shaderfilter` | Output Mismatch | 0/4 lines match |
| 42 | `pixelbender_eof` | Output Mismatch | 1/7 lines match |
| 43 | `pixelbender_input` | Output Mismatch | 4/103 lines match |
| 44 | `pixelbender_logicalnot` | Output Mismatch | 0/20 lines match |
| 45 | `pixelbender_malformed_data` | Output Mismatch | 0/190 lines match |
| 46 | `pixelbender_multiple_out_params` | Output Mismatch | 0/1 lines match |
| 47 | `pixelbender_no_out_param` | Output Mismatch | 0/6 lines match |
| 48 | `pixelbender_outputs` | Output Mismatch | 0/13 lines match |
| 49 | `pixelbender_padding_bytes` | Output Mismatch | 0/66 lines match |
| 50 | `pixelbender_param_qualifier` | Output Mismatch | 0/512 lines match |
| 51 | `pixelbender_parameters` | Output Mismatch | 1/1563 lines match |
| 52 | `pixelbender_parameters_bool` | Output Mismatch | 0/240 lines match |
| 53 | `pixelbender_parameters_int_vs_bool` | Output Mismatch | 0/54 lines match |
| 54 | `pixelbender_parse_errors` | Output Mismatch | 0/6 lines match |
| 55 | `pixelbender_rsqrt` | Output Mismatch | 1/24 lines match |
| 56 | `pixelbender_select_kinds` | Output Mismatch | 0/8 lines match |
| 57 | `pixelbender_shaderdata` | Output Mismatch | 0/49 lines match |
| 58 | `pixelbender_shaderdata_setter` | Output Mismatch | 3/99 lines match |
| 59 | `pixelbender_sign` | Output Mismatch | 5/60 lines match |
| 60 | `pixelbender_vector_output` | Output Mismatch | 1/11 lines match |
| 61 | `rectangle` | Output Mismatch | 1/1094 lines match |
| 62 | `shaderparameter_value` | Output Mismatch | 0/4 lines match |
| 63 | `stage3d_agal_upload_errors` | Output Mismatch | 0/66 lines match |
| 64 | `stage3d_blend` | Output Mismatch | 0/81 lines match |
| 65 | `stage3d_context3d_string_args` | Output Mismatch | 0/158 lines match |
| 66 | `stage3d_errors` | Output Mismatch | 0/7 lines match |
| 67 | `stage3d_errors_atf` | Output Mismatch | 0/3 lines match |
| 68 | `stage3d_errors_swf_29` | Output Mismatch | 0/6 lines match |
| 69 | `stage3d_multistage_triangle` | Output Mismatch | 0/3 lines match |
| 70 | `stage3d_program_constants_invalid_input` | Output Mismatch | 0/21 lines match |
| 71 | `stage3d_x_y` | Output Mismatch | 0/22 lines match |
| 72 | `stage_stage3Ds_vector` | Output Mismatch | 0/1 lines match |
| 73 | `tab_ordering_arrows` | Output Mismatch | 645/1000 lines match |
| 74 | `urlstream_basic` | Output Mismatch | 0/5 lines match |
| 75 | `utils3d` | Output Mismatch | 0/7 lines match |
| 76 | `vector3d` | Output Mismatch | 24/397 lines match |
| 77 | `verification` | Output Mismatch | 5/8 lines match |
| 78 | `verify_dxns_without_flag` | Output Mismatch | 1/3 lines match |
| 79 | `verify_jump_to_middle_of_op` | Output Mismatch | 0/1 lines match |
| 80 | `verify_stack` | Output Mismatch | 2/5 lines match |
