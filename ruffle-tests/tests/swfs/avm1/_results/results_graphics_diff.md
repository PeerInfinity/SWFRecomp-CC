# Ruffle Test Results Diff

**Previous:** `dbc43c157352` (2026-11-27T03:35:22.702464+00:00)
**Current:** `2d40d37996b8` (2026-11-27T06:45:05.523532+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 776 | 750 | -26 |
| Total | 791 | 764 | -27 |
| Pass rate | 98.1% | 98.2% | +0.1% |
| Mismatched lines | 12119 | 11984 | -135 |

## Missing Tests — Shard Failure (27)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 26 were previously passing
- 1 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `escape` | pass | 14/14 |
| `execution_order1` | pass | 5/5 |
| `execution_order2` | pass | 7/7 |
| `execution_order3` | pass | 4/4 |
| `execution_order4` | pass | 12/12 |
| `export_assets` | pass | 3/3 |
| `extends_chain` | pass | 134/134 |
| `extends_native_type` | pass | 11/11 |
| `external_interface` | pass | 84/84 |
| `external_interface_escapexml` | pass | 26/26 |
| `external_interface_jsquotestring` | pass | 21/21 |
| `external_interface_monkeypatch` | output_mismatch | 4/139 |
| `external_interface_toas_basic` | pass | 354/354 |
| `external_interface_toxml_array` | pass | 25/25 |
| `external_interface_toxml_basic` | pass | 179/179 |
| `external_interface_unescapexml` | pass | 40/40 |
| `file_reference_browse_cancel` | pass | 21/21 |
| `file_reference_download_cancel` | pass | 7/7 |
| `file_reference_download_httperror_dns_error` | pass | 13/13 |
| `file_reference_download_httperror_status_code` | pass | 23/23 |
| `file_reference_download_success` | pass | 34/34 |
| `file_reference_list_asbroadcaster` | pass | 9/9 |
| `file_reference_list_browse_cancel` | pass | 4/4 |
| `file_reference_list_browse_invalid_filters` | pass | 36/36 |
| `file_reference_list_browse_select` | pass | 7/7 |
| `file_reference_listeners_per_instance` | pass | 20/20 |
| `file_reference_upload_httperror_dns_error` | pass | 18/18 |

</details>
