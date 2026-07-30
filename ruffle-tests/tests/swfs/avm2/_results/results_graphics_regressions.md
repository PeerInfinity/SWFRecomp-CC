# Graphics vs Trace Mode Differences

Trace: 929/1221 passing | Graphics: 972/1221 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (43 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `amf_array_serialization` | Output Mismatch | 6/17 lines match |
| 2 | `blend_shader_luma_lighten` | Output Mismatch | 1/3 lines match |
| 3 | `context3d_creation` | Output Mismatch | 0/9 lines match |
| 4 | `localconnection_send` | Output Mismatch | 0/4 lines match |
| 5 | `matrix3d_invert` | Output Mismatch | 0/18 lines match |
| 6 | `netconnection_send_remote` | Output Mismatch | 2/50 lines match |
| 7 | `netconnection_serialize_arrays` | Output Mismatch | 1/6 lines match |
| 8 | `pixelbender_ceil` | Output Mismatch | 5/77 lines match |
| 9 | `pixelbender_conditional` | Output Mismatch | 0/138 lines match |
| 10 | `pixelbender_conversions` | Output Mismatch | 1/270 lines match |
| 11 | `pixelbender_dithering` | Output Mismatch | 0/8 lines match |
| 12 | `pixelbender_div` | Output Mismatch | 1/36 lines match |
| 13 | `pixelbender_eof` | Output Mismatch | 1/7 lines match |
| 14 | `pixelbender_input` | Output Mismatch | 4/103 lines match |
| 15 | `pixelbender_logicalnot` | Output Mismatch | 0/20 lines match |
| 16 | `pixelbender_malformed_data` | Output Mismatch | 0/190 lines match |
| 17 | `pixelbender_multiple_out_params` | Output Mismatch | 0/1 lines match |
| 18 | `pixelbender_no_out_param` | Output Mismatch | 0/6 lines match |
| 19 | `pixelbender_outputs` | Output Mismatch | 0/13 lines match |
| 20 | `pixelbender_padding_bytes` | Output Mismatch | 0/66 lines match |
| 21 | `pixelbender_param_qualifier` | Output Mismatch | 0/512 lines match |
| 22 | `pixelbender_parameters` | Output Mismatch | 1/1563 lines match |
| 23 | `pixelbender_parameters_bool` | Output Mismatch | 0/240 lines match |
| 24 | `pixelbender_parameters_int_vs_bool` | Output Mismatch | 0/54 lines match |
| 25 | `pixelbender_parse_errors` | Output Mismatch | 0/6 lines match |
| 26 | `pixelbender_rsqrt` | Output Mismatch | 1/24 lines match |
| 27 | `pixelbender_select_kinds` | Output Mismatch | 0/8 lines match |
| 28 | `pixelbender_shaderdata` | Output Mismatch | 0/49 lines match |
| 29 | `pixelbender_shaderdata_setter` | Output Mismatch | 3/99 lines match |
| 30 | `pixelbender_sign` | Output Mismatch | 5/60 lines match |
| 31 | `pixelbender_vector_output` | Output Mismatch | 1/11 lines match |
| 32 | `shaderparameter_value` | Output Mismatch | 0/4 lines match |
| 33 | `stage3d_agal_upload_errors` | Output Mismatch | 0/66 lines match |
| 34 | `stage3d_blend` | Output Mismatch | 0/81 lines match |
| 35 | `stage3d_context3d_string_args` | Output Mismatch | 0/158 lines match |
| 36 | `stage3d_errors` | Output Mismatch | 0/7 lines match |
| 37 | `stage3d_errors_atf` | Output Mismatch | 0/3 lines match |
| 38 | `stage3d_errors_swf_29` | Output Mismatch | 0/6 lines match |
| 39 | `stage3d_multistage_triangle` | Output Mismatch | 0/3 lines match |
| 40 | `stage3d_program_constants_invalid_input` | Output Mismatch | 0/21 lines match |
| 41 | `stage3d_x_y` | Output Mismatch | 0/22 lines match |
| 42 | `stage_stage3Ds_vector` | Output Mismatch | 0/1 lines match |
| 43 | `urlstream_basic` | Output Mismatch | 0/5 lines match |
