# Ruffle Test Results Diff

**Previous:** `34171042fc78` (2026-07-30T01:47:24.771467+00:00)
**Current:** `dfbbfc1afa81` (2026-07-30T03:40:10.829765+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 934 | 946 | +12 |
| Total | 1221 | 1221 | 0 |
| Pass rate | 76.5% | 77.5% | +1.0% |
| Mismatched lines | 43273 | 42859 | -414 |
|   Decreased | | | -414 |

## Newly Passing (12)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `context3d_creation` | output_mismatch | 0/9 | 9/9 |
| `matrix3d_invert` | output_mismatch | 0/18 | 18/18 |
| `stage3d_agal_upload_errors` | output_mismatch | 0/66 | 66/66 |
| `stage3d_blend` | output_mismatch | 0/81 | 81/81 |
| `stage3d_context3d_string_args` | output_mismatch | 0/158 | 158/158 |
| `stage3d_errors` | output_mismatch | 0/7 | 7/7 |
| `stage3d_errors_atf` | output_mismatch | 0/3 | 3/3 |
| `stage3d_errors_swf_29` | output_mismatch | 0/6 | 6/6 |
| `stage3d_multistage_triangle` | output_mismatch | 0/3 | 3/3 |
| `stage3d_program_constants_invalid_input` | output_mismatch | 0/21 | 21/21 |
| `stage3d_x_y` | output_mismatch | 0/22 | 22/22 |
| `stage_stage3Ds_vector` | output_mismatch | 0/1 | 1/1 |

## Line Count Changed (10)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `matrix3d` | output_mismatch | 1/57 | 19/57 | -18 |
| `all_classes/display3D/swf30` | output_mismatch | 0/412 | 1/412 | -1 |
| `all_classes/display/swf10` | output_mismatch | 2/2569 | 2/2569 | 0 |
| `all_classes/display/swf11` | output_mismatch | 2/2593 | 2/2593 | 0 |
| `all_classes/display/swf12` | output_mismatch | 2/2593 | 2/2593 | 0 |
| `all_classes/display/swf13` | output_mismatch | 2/2671 | 2/2671 | 0 |
| `all_classes/display/swf30` | output_mismatch | 0/2936 | 0/2936 | 0 |
| `all_classes/display/swf9` | output_mismatch | 2/1959 | 2/1959 | 0 |
| `all_classes/display3D/swf12` | output_mismatch | 1/61 | 1/61 | 0 |
| `all_classes/display3D/swf13` | output_mismatch | 0/326 | 0/326 | 0 |
