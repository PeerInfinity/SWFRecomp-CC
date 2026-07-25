# Graphics vs Trace Mode Differences

Trace: 829/1217 passing | Graphics: 829/1218 passing

## Graphics Regressions (11 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `array_holes` | Output Mismatch | 8/9 lines match |
| 2 | `array_pop` | Output Mismatch | 50/52 lines match |
| 3 | `array_push` | Output Mismatch | 21/24 lines match |
| 4 | `array_reverse` | Output Mismatch | 25/28 lines match |
| 5 | `array_shift` | Output Mismatch | 49/51 lines match |
| 6 | `array_slice` | Output Mismatch | 28/39 lines match |
| 7 | `array_sort` | Output Mismatch | 220/297 lines match |
| 8 | `array_sorton` | Output Mismatch | 28/545 lines match |
| 9 | `array_splice` | Output Mismatch | 92/133 lines match |
| 10 | `array_unshift` | Output Mismatch | 21/24 lines match |
| 11 | `function_call_via_apply` | Output Mismatch | 10/11 lines match |

## Graphics Improvements (11 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `capabilities_resolution` | Output Mismatch | 1/8 lines match |
| 2 | `date` | Output Mismatch | 15/30 lines match |
| 3 | `date_parse` | Output Mismatch | 2/36 lines match |
| 4 | `decode_uri` | Output Mismatch | 0/71 lines match |
| 5 | `encode_uri_surrogate_pair_swf11` | Output Mismatch | 0/15 lines match |
| 6 | `escape` | Output Mismatch | 20/71 lines match |
| 7 | `parse_float` | Output Mismatch | 80/81 lines match |
| 8 | `string_concat_fromcharcode` | Output Mismatch | 36/37 lines match |
| 9 | `string_slice_substr_substring` | Output Mismatch | 169/170 lines match |
| 10 | `unescape` | Output Mismatch | 25/28 lines match |
| 11 | `xml_basic` | Output Mismatch | 32/33 lines match |
