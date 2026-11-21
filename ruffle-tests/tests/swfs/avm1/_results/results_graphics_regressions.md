# Graphics vs Trace Mode Differences

Trace: 692/749 passing | Graphics: 727/777 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (12 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `amf0_utf8_probe` | Output Mismatch | 13/14 lines match |
| 2 | `amf_array_indices` | Output Mismatch | 23/48 lines match |
| 3 | `array_truncation_non_canonical_keys` | Output Mismatch | 29/37 lines match |
| 4 | `edittext_html_duplicate_attributes` | Output Mismatch | 241/247 lines match |
| 5 | `localconnection_serialize_function_array_elements` | Output Mismatch | 14/20 lines match |
| 6 | `netconnection_serialize_arrays` | Output Mismatch | 5/6 lines match |
| 7 | `shared_object_secure` | Output Mismatch | 19/20 lines match |
| 8 | `sparse_array_truncation_non_canonical_keys` | Output Mismatch | 35/43 lines match |
| 9 | `textfield_get_text_format_args` | Output Mismatch | 87/269 lines match |
| 10 | `textfield_set_text_format_args` | Output Mismatch | 127/232 lines match |
| 11 | `textfield_set_text_format_text_change` | Output Mismatch | 1/37 lines match |
| 12 | `xml_stringify_utf16` | Output Mismatch | 1/4 lines match |
