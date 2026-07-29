# Graphics vs Trace Mode Differences

Trace: 651/717 passing | Graphics: 658/717 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (7 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `file_reference_download_cancel` | Output Mismatch | 1/7 lines match |
| 2 | `file_reference_download_httperror_dns_error` | Output Mismatch | 1/13 lines match |
| 3 | `file_reference_download_httperror_status_code` | Output Mismatch | 1/23 lines match |
| 4 | `file_reference_download_success` | Output Mismatch | 10/34 lines match |
| 5 | `file_reference_upload_httperror_dns_error` | Output Mismatch | 8/18 lines match |
| 6 | `file_reference_upload_httperror_status_code` | Output Mismatch | 8/23 lines match |
| 7 | `file_reference_upload_success` | Output Mismatch | 8/23 lines match |
