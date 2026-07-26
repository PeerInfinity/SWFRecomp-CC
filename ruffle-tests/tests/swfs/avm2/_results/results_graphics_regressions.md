# Graphics vs Trace Mode Differences

Trace: 829/1217 passing | Graphics: 842/1218 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (13 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `capabilities_resolution` | Output Mismatch | 1/8 lines match |
| 2 | `date` | Output Mismatch | 15/30 lines match |
| 3 | `date_parse` | Output Mismatch | 2/36 lines match |
| 4 | `decode_uri` | Output Mismatch | 0/71 lines match |
| 5 | `domain_memory` | Runtime Error | 1/133 lines match |
| 6 | `encode_uri_surrogate_pair_swf11` | Output Mismatch | 0/15 lines match |
| 7 | `escape` | Output Mismatch | 20/71 lines match |
| 8 | `indexing_delete` | Output Mismatch | 60/75 lines match |
| 9 | `parse_float` | Output Mismatch | 80/81 lines match |
| 10 | `string_concat_fromcharcode` | Output Mismatch | 36/37 lines match |
| 11 | `string_slice_substr_substring` | Output Mismatch | 169/170 lines match |
| 12 | `unescape` | Output Mismatch | 25/28 lines match |
| 13 | `xml_basic` | Output Mismatch | 32/33 lines match |
