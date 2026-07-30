# Ruffle Test Results Diff

**Previous:** `dfbbfc1afa81` (2026-07-30T03:40:10.829765+00:00)
**Current:** `e4859db87771` (2026-07-30T05:13:12.427417+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 946 | 954 | +8 |
| Total | 1221 | 1221 | 0 |
| Pass rate | 77.5% | 78.1% | +0.6% |
| Mismatched lines | 42859 | 40449 | -2410 |
|   Decreased | | | -2410 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `pixelbender_dithering` | output_mismatch | 0/8 | 8/8 |
| `pixelbender_eof` | output_mismatch | 1/7 | 7/7 |
| `pixelbender_no_out_param` | output_mismatch | 0/6 | 6/6 |
| `pixelbender_param_qualifier` | output_mismatch | 0/512 | 512/512 |
| `pixelbender_parse_errors` | output_mismatch | 0/6 | 6/6 |
| `pixelbender_select_kinds` | output_mismatch | 0/8 | 8/8 |
| `pixelbender_shaderdata` | output_mismatch | 0/49 | 49/49 |
| `shaderparameter_value` | output_mismatch | 0/4 | 4/4 |

## Line Count Changed (24)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `pixelbender_parameters` | output_mismatch | 1/1563 | 1058/1563 | -1057 |
| `pixelbender_parameters_bool` | output_mismatch | 0/240 | 216/240 | -216 |
| `pixelbender_conversions` | output_mismatch | 1/270 | 184/270 | -183 |
| `pixelbender_conditional` | output_mismatch | 0/138 | 77/138 | -77 |
| `pixelbender_shaderdata_setter` | output_mismatch | 3/99 | 67/99 | -64 |
| `pixelbender_input` | output_mismatch | 4/103 | 63/103 | -59 |
| `pixelbender_malformed_data` | output_mismatch | 0/190 | 37/190 | -37 |
| `pixelbender_parameters_int_vs_bool` | output_mismatch | 0/54 | 36/54 | -36 |
| `pixelbender_div` | output_mismatch | 1/36 | 24/36 | -23 |
| `pixelbender_sign` | output_mismatch | 5/60 | 26/60 | -21 |
| `pixelbender_ceil` | output_mismatch | 5/77 | 25/77 | -20 |
| `pixelbender_rsqrt` | output_mismatch | 1/24 | 16/24 | -15 |
| `pixelbender_effect_glassDisplace_shaderfilter` | output_mismatch | 0/4 | 2/4 | -2 |
| `all_classes/display/swf30` | output_mismatch | 0/2936 | 1/2936 | -1 |
| `all_classes/display/swf10` | output_mismatch | 2/2569 | 2/2569 | 0 |
| `all_classes/display/swf11` | output_mismatch | 2/2593 | 2/2593 | 0 |
| `all_classes/display/swf12` | output_mismatch | 2/2593 | 2/2593 | 0 |
| `all_classes/display/swf13` | output_mismatch | 2/2671 | 2/2671 | 0 |
| `all_classes/display/swf9` | output_mismatch | 2/1959 | 2/1959 | 0 |
| `pixelbender_logicalnot` | output_mismatch | 0/20 | 0/20 | 0 |
| `pixelbender_multiple_out_params` | output_mismatch | 0/1 | 0/1 | 0 |
| `pixelbender_outputs` | output_mismatch | 0/13 | 0/13 | 0 |
| `pixelbender_padding_bytes` | output_mismatch | 0/22 | 0/22 | 0 |
| `pixelbender_vector_output` | output_mismatch | 1/11 | 1/11 | 0 |
