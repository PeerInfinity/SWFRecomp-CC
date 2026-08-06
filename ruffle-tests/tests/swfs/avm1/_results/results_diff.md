# Ruffle Test Results Diff

**Previous:** `72fdc5e933a6` (2026-07-29T03:45:41.022475+00:00)
**Current:** `b4c983ea4c3d` (2026-08-02T09:26:35.592926+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 651 | 672 | +21 |
| Total | 717 | 718 | +1 |
| Pass rate | 90.8% | 93.6% | +2.8% |
| Mismatched lines | 14874 | 14547 | -327 |
|   Decreased | | | -328 |

## Newly Passing (21)

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
| `file_reference_download_cancel` | output_mismatch | 1/7 | 7/7 |
| `file_reference_download_httperror_dns_error` | output_mismatch | 1/13 | 13/13 |
| `file_reference_download_httperror_status_code` | output_mismatch | 1/23 | 23/23 |
| `file_reference_download_success` | output_mismatch | 10/34 | 34/34 |
| `file_reference_upload_httperror_dns_error` | output_mismatch | 8/18 | 18/18 |
| `file_reference_upload_httperror_status_code` | output_mismatch | 8/23 | 23/23 |
| `file_reference_upload_success` | output_mismatch | 8/23 | 23/23 |
| `form_loader_encoding_2` | output_mismatch | 0/3 | 3/3 |
| `form_loader_encoding_3` | output_mismatch | 1/3 | 3/3 |
| `localconnection_top_level` | output_mismatch | 4/7 | 7/7 |
| `netconnection_send_remote` | output_mismatch | 2/50 | 50/50 |
| `netconnection_serialize_arrays` | output_mismatch | 1/6 | 6/6 |
| `string_relational_compare` | output_mismatch | 3/4 | 4/4 |

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `attach_movie_export_not_yet_run` | ruffle_matched | 1/2 |
