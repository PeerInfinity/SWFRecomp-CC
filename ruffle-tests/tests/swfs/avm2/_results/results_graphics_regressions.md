# Graphics vs Trace Mode Differences

Trace: 1198/1289 passing | Graphics: 1253/1335 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (9 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `bitmapdata_encode_jpeg_visual` | Output Mismatch | 0/3 lines match |
| 2 | `bitmapdata_encode_png_roundtrip` | Output Mismatch | 1/33 lines match |
| 3 | `bitmapdata_encode_png_visual` | Output Mismatch | 0/3 lines match |
| 4 | `dictionary_qname_keys` | Output Mismatch | 29/57 lines match |
| 5 | `edittext_event_link_case_insensitive` | Output Mismatch | 0/1 lines match |
| 6 | `perspective_projection_center` | Output Mismatch | 6/34 lines match |
| 7 | `textfield_default_text_format_null` | Output Mismatch | 7/20 lines match |
| 8 | `xml_many_namespace_declarations` | Output Mismatch | 1/2 lines match |
| 9 | `xml_unescaping_nul_char_ref` | Output Mismatch | 4/19 lines match |
