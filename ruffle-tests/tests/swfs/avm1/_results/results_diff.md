# Ruffle Test Results Diff

**Previous:** `bc91565cea8e` (2026-11-21T19:30:16.371895+00:00)
**Current:** `c489b84d9946` (2026-11-21T19:49:24.005929+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 692 | 727 | +35 |
| Total | 749 | 777 | +28 |
| Pass rate | 92.4% | 93.6% | +1.2% |
| Mismatched lines | 3883 | 12718 | +8835 |
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

## Added Tests (28)

| Test | Status | Lines |
|------|--------|-------|
| `allow_networking_import_assets` | pass | 4/4 |
| `allow_networking_import_assets2` | pass | 4/4 |
| `function_as_function` | pass | 35/35 |
| `function_base_clip` | pass | 8/8 |
| `function_base_clip_readded` | pass | 11/11 |
| `function_base_clip_removed` | pass | 25/25 |
| `function_suppress_and_preload` | pass | 28/28 |
| `funky_function_calls` | pass | 56/56 |
| `get_bytes_total` | pass | 4/4 |
| `get_variable_in_scope` | pass | 29/29 |
| `getproperty` | pass | 28/28 |
| `getproperty_swf4` | pass | 28/28 |
| `getproperty_swf5` | pass | 28/28 |
| `gettextextent` | pass | 56/56 |
| `geturl` | pass | 7/7 |
| `geturl_opcode_target_normalize` | pass | 45/45 |
| `geturl_target_normalize` | pass | 89/89 |
| `global_array` | pass | 3/3 |
| `global_instance_decls` | output_mismatch | 19/758 |
| `global_is_bare` | pass | 7/7 |
| `global_proto_decls` | output_mismatch | 59/4562 |
| `global_proto_decls_delete` | output_mismatch | 461/4158 |
| `global_swf5_6_7_8_9` | pass | 1145/1145 |
| `global_swf6_7_8` | pass | 15/15 |
| `globals_monkeypatch` | output_mismatch | 43/306 |
| `globals_swf5` | output_mismatch | 294/304 |
| `globals_swf6` | pass | 304/304 |
| `globals_swf7` | pass | 304/304 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `amf0_array_matrix` | output_mismatch | 39/50 | 49/50 | -10 |
| `localconnection_serialize_sparse_array_getters` | output_mismatch | 23/26 | 25/26 | -2 |
| `localconnection_serialize_inherited_array_indices` | output_mismatch | 11/12 | 10/12 | +1 |
