# Ruffle Test Results Diff

**Previous:** `767a301d2bae` (2026-07-29T01:40:49.551172+00:00)
**Current:** `72fdc5e933a6` (2026-07-29T03:45:41.022475+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 646 | 651 | +5 |
| Total | 717 | 717 | 0 |
| Pass rate | 90.1% | 90.8% | +0.7% |
| Mismatched lines | 14958 | 14874 | -84 |
|   Decreased | | | -84 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `file_reference_browse_cancel` | output_mismatch | 10/21 | 21/21 |
| `file_reference_list_asbroadcaster` | output_mismatch | 0/9 | 9/9 |
| `file_reference_list_browse_cancel` | output_mismatch | 1/4 | 4/4 |
| `file_reference_list_browse_invalid_filters` | output_mismatch | 18/36 | 36/36 |
| `file_reference_list_browse_select` | output_mismatch | 1/7 | 7/7 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_instance_decls` | output_mismatch | 13/758 | 26/758 | -13 |
| `file_reference_upload_httperror_dns_error` | output_mismatch | 1/18 | 8/18 | -7 |
| `file_reference_upload_httperror_status_code` | output_mismatch | 1/23 | 8/23 | -7 |
| `file_reference_upload_success` | output_mismatch | 1/23 | 8/23 | -7 |
| `file_reference_download_success` | output_mismatch | 7/34 | 10/34 | -3 |
