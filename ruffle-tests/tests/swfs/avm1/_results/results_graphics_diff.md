# Ruffle Test Results Diff

**Previous:** `bc91565cea8e` (2026-11-21T18:24:43.146802+00:00)
**Current:** `c489b84d9946` (2026-11-21T19:32:37.101881+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 713 | 727 | +14 |
| Total | 775 | 777 | +2 |
| Pass rate | 92.0% | 93.6% | +1.6% |
| Mismatched lines | 13095 | 12718 | -377 |
|   Decreased | | | -378 |
|   Increased | | | +1 |

## Newly Passing (12)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `amf0_utf8_probe` | output_mismatch | 13/14 | 14/14 |
| `amf_array_indices` | output_mismatch | 23/32 | 32/32 |
| `array_truncation_non_canonical_keys` | output_mismatch | 29/37 | 37/37 |
| `edittext_html_duplicate_attributes` | output_mismatch | 241/247 | 247/247 |
| `localconnection_serialize_function_array_elements` | output_mismatch | 14/20 | 20/20 |
| `netconnection_serialize_arrays` | output_mismatch | 5/6 | 6/6 |
| `shared_object_secure` | output_mismatch | 19/20 | 20/20 |
| `sparse_array_truncation_non_canonical_keys` | output_mismatch | 35/43 | 43/43 |
| `textfield_get_text_format_args` | output_mismatch | 87/269 | 269/269 |
| `textfield_set_text_format_args` | output_mismatch | 127/232 | 232/232 |
| `textfield_set_text_format_text_change` | output_mismatch | 1/37 | 37/37 |
| `xml_stringify_utf16` | output_mismatch | 1/4 | 4/4 |

## Added Tests (2)

| Test | Status | Lines |
|------|--------|-------|
| `allow_networking_import_assets` | pass | 4/4 |
| `allow_networking_import_assets2` | pass | 4/4 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `amf0_array_matrix` | output_mismatch | 39/50 | 49/50 | -10 |
| `localconnection_serialize_sparse_array_getters` | output_mismatch | 23/26 | 25/26 | -2 |
| `localconnection_serialize_inherited_array_indices` | output_mismatch | 11/12 | 10/12 | +1 |
