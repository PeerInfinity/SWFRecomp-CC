# Graphics vs Trace Mode Differences

Trace: 929/1221 passing | Graphics: 946/1221 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (17 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `amf_array_serialization` | Output Mismatch | 6/17 lines match |
| 2 | `context3d_creation` | Output Mismatch | 0/9 lines match |
| 3 | `localconnection_send` | Output Mismatch | 0/4 lines match |
| 4 | `matrix3d_invert` | Output Mismatch | 0/18 lines match |
| 5 | `netconnection_send_remote` | Output Mismatch | 2/50 lines match |
| 6 | `netconnection_serialize_arrays` | Output Mismatch | 1/6 lines match |
| 7 | `stage3d_agal_upload_errors` | Output Mismatch | 0/66 lines match |
| 8 | `stage3d_blend` | Output Mismatch | 0/81 lines match |
| 9 | `stage3d_context3d_string_args` | Output Mismatch | 0/158 lines match |
| 10 | `stage3d_errors` | Output Mismatch | 0/7 lines match |
| 11 | `stage3d_errors_atf` | Output Mismatch | 0/3 lines match |
| 12 | `stage3d_errors_swf_29` | Output Mismatch | 0/6 lines match |
| 13 | `stage3d_multistage_triangle` | Output Mismatch | 0/3 lines match |
| 14 | `stage3d_program_constants_invalid_input` | Output Mismatch | 0/21 lines match |
| 15 | `stage3d_x_y` | Output Mismatch | 0/22 lines match |
| 16 | `stage_stage3Ds_vector` | Output Mismatch | 0/1 lines match |
| 17 | `urlstream_basic` | Output Mismatch | 0/5 lines match |
