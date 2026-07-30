# Ruffle Test Results Diff

**Previous:** `e4859db87771` (2026-07-30T05:13:12.427417+00:00)
**Current:** `9277e0e1b214` (2026-07-30T07:00:20.365759+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 954 | 972 | +18 |
| Total | 1221 | 1221 | 0 |
| Pass rate | 78.1% | 79.6% | +1.5% |
| Mismatched lines | 40449 | 39361 | -1088 |
|   Decreased | | | -1093 |
|   Increased | | | +5 |

## Newly Passing (18)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `blend_shader_luma_lighten` | output_mismatch | 1/3 | 3/3 |
| `pixelbender_ceil` | output_mismatch | 25/77 | 77/77 |
| `pixelbender_conditional` | output_mismatch | 77/138 | 138/138 |
| `pixelbender_conversions` | output_mismatch | 184/270 | 270/270 |
| `pixelbender_div` | output_mismatch | 24/36 | 36/36 |
| `pixelbender_input` | output_mismatch | 63/103 | 103/103 |
| `pixelbender_logicalnot` | output_mismatch | 0/20 | 20/20 |
| `pixelbender_malformed_data` | output_mismatch | 37/190 | 190/190 |
| `pixelbender_multiple_out_params` | output_mismatch | 0/1 | 1/1 |
| `pixelbender_outputs` | output_mismatch | 0/13 | 13/13 |
| `pixelbender_padding_bytes` | output_mismatch | 0/22 | 22/22 |
| `pixelbender_parameters` | output_mismatch | 1058/1563 | 1563/1563 |
| `pixelbender_parameters_bool` | output_mismatch | 216/240 | 240/240 |
| `pixelbender_parameters_int_vs_bool` | output_mismatch | 36/54 | 54/54 |
| `pixelbender_rsqrt` | output_mismatch | 16/24 | 24/24 |
| `pixelbender_shaderdata_setter` | output_mismatch | 67/99 | 99/99 |
| `pixelbender_sign` | output_mismatch | 26/60 | 60/60 |
| `pixelbender_vector_output` | output_mismatch | 1/11 | 11/11 |

## Line Count Changed (6)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `all_classes/display/swf9` | output_mismatch | 2/1959 | 2/1959 | 0 |
| `all_classes/display/swf10` | output_mismatch | 2/2569 | 1/2569 | +1 |
| `all_classes/display/swf11` | output_mismatch | 2/2593 | 1/2593 | +1 |
| `all_classes/display/swf12` | output_mismatch | 2/2593 | 1/2593 | +1 |
| `all_classes/display/swf13` | output_mismatch | 2/2671 | 1/2671 | +1 |
| `all_classes/display/swf30` | output_mismatch | 1/2936 | 0/2936 | +1 |
