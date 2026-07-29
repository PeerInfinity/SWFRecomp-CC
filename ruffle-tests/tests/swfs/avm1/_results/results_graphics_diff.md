# Ruffle Test Results Diff

**Previous:** `6cf854900e0b` (2026-07-29T19:07:58.693343+00:00)
**Current:** `702d38a3599f` (2026-07-29T22:35:44.117634+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 658 | 669 | +11 |
| Total | 717 | 718 | +1 |
| Pass rate | 91.8% | 93.2% | +1.4% |
| Mismatched lines | 14770 | 14553 | -217 |
|   Decreased | | | -218 |

## Newly Passing (11)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `amf0_serde_suite` | output_mismatch | 16/144 | 144/144 |
| `amf_array_serialization` | output_mismatch | 3/10 | 10/10 |
| `amf_serialize_typed_objects` | output_mismatch | 1/6 | 6/6 |
| `amf_sharedobject_strict_array_serialization` | output_mismatch | 2/3 | 3/3 |
| `amf_strict_array_serialization` | output_mismatch | 1/7 | 7/7 |
| `amf_swf6_case_insensitive_typed_objects` | output_mismatch | 1/6 | 6/6 |
| `amf_swf6_serialize_typed_objects` | output_mismatch | 1/6 | 6/6 |
| `amf_swf8_case_sensitive_typed_objects` | output_mismatch | 1/6 | 6/6 |
| `localconnection_top_level` | output_mismatch | 4/7 | 7/7 |
| `netconnection_send_remote` | output_mismatch | 2/50 | 50/50 |
| `netconnection_serialize_arrays` | output_mismatch | 1/6 | 6/6 |

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `attach_movie_export_not_yet_run` | ruffle_matched | 1/2 |
