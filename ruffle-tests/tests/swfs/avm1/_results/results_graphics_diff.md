# Ruffle Test Results Diff

**Previous:** `c1fa89bc20be` (2026-10-19T20:20:55.470582+00:00)
**Current:** `08709f65842a` (2026-11-21T17:28:09.797615+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 710 | 713 | +3 |
| Total | 748 | 775 | +27 |
| Pass rate | 94.9% | 92.0% | -2.9% |
| Mismatched lines | 11718 | 13095 | +1377 |
|   Increased | | | +871 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `netconnection_serialize_arrays` | output_mismatch | 6/6 | 5/6 |

## Added Tests (27)

| Test | Status | Lines |
|------|--------|-------|
| `amf0_array_matrix` | output_mismatch | 39/50 |
| `amf0_utf8_probe` | output_mismatch | 13/14 |
| `amf_array_indices` | output_mismatch | 23/32 |
| `array_truncation_non_canonical_keys` | output_mismatch | 29/37 |
| `asnative_instrument` | ruffle_matched | 1/173 |
| `asnative_sweep` | ruffle_matched | 1/74 |
| `bitmapdata_hittest_default_threshold` | pass | 4/4 |
| `edittext_asfunction_case_insensitive` | output_mismatch | 0/1 |
| `edittext_set_text_same` | output_mismatch | 28/70 |
| `edittext_set_text_same_after_edits` | output_mismatch | 30/98 |
| `file_reference_listeners_per_instance` | output_mismatch | 2/20 |
| `localconnection_reference_identity` | output_mismatch | 2/5 |
| `localconnection_serialize_function_array_elements` | output_mismatch | 14/20 |
| `localconnection_serialize_inherited_array_indices` | output_mismatch | 11/12 |
| `localconnection_serialize_sparse_array_getters` | output_mismatch | 23/26 |
| `localconnection_serialize_undefined_array_elements` | pass | 24/24 |
| `localconnection_xml` | pass | 14/14 |
| `localconnection_xml_unavailable` | output_mismatch | 9/23 |
| `netconnection_deserialize_strict_array_undefined` | pass | 17/17 |
| `shared_object_members_swf5` | output_mismatch | 25/32 |
| `shared_object_secure` | output_mismatch | 19/20 |
| `sparse_array_truncation_non_canonical_keys` | output_mismatch | 35/43 |
| `video_prototype_lazy` | output_mismatch | 9/21 |
| `video_prototype_lazy_swf6_child` | output_mismatch | 2/8 |
| `video_width_height` | output_mismatch | 3/19 |
| `xml_status_mismatched_tags` | output_mismatch | 40/63 |
| `xml_stringify_utf16` | output_mismatch | 1/4 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_instance_decls` | output_mismatch | 26/758 | 19/758 | +7 |
| `globals_monkeypatch` | output_mismatch | 41/250 | 43/306 | +54 |
| `global_proto_decls` | output_mismatch | 803/4497 | 59/4562 | +809 |
