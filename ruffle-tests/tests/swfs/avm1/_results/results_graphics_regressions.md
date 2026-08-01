# Graphics vs Trace Mode Differences

Trace: 651/717 passing | Graphics: 672/718 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (21 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `amf0_serde_suite` | Output Mismatch | 16/144 lines match |
| 2 | `amf_array_serialization` | Output Mismatch | 3/10 lines match |
| 3 | `amf_serialize_typed_objects` | Output Mismatch | 1/6 lines match |
| 4 | `amf_sharedobject_strict_array_serialization` | Output Mismatch | 2/3 lines match |
| 5 | `amf_strict_array_serialization` | Output Mismatch | 1/7 lines match |
| 6 | `amf_swf6_case_insensitive_typed_objects` | Output Mismatch | 1/6 lines match |
| 7 | `amf_swf6_serialize_typed_objects` | Output Mismatch | 1/6 lines match |
| 8 | `amf_swf8_case_sensitive_typed_objects` | Output Mismatch | 1/6 lines match |
| 9 | `file_reference_download_cancel` | Output Mismatch | 1/7 lines match |
| 10 | `file_reference_download_httperror_dns_error` | Output Mismatch | 1/13 lines match |
| 11 | `file_reference_download_httperror_status_code` | Output Mismatch | 1/23 lines match |
| 12 | `file_reference_download_success` | Output Mismatch | 10/34 lines match |
| 13 | `file_reference_upload_httperror_dns_error` | Output Mismatch | 8/18 lines match |
| 14 | `file_reference_upload_httperror_status_code` | Output Mismatch | 8/23 lines match |
| 15 | `file_reference_upload_success` | Output Mismatch | 8/23 lines match |
| 16 | `form_loader_encoding_2` | Output Mismatch | 0/3 lines match |
| 17 | `form_loader_encoding_3` | Output Mismatch | 1/3 lines match |
| 18 | `localconnection_top_level` | Output Mismatch | 4/7 lines match |
| 19 | `netconnection_send_remote` | Output Mismatch | 2/50 lines match |
| 20 | `netconnection_serialize_arrays` | Output Mismatch | 1/6 lines match |
| 21 | `string_relational_compare` | Output Mismatch | 3/4 lines match |
