# Ruffle Test Results Diff

**Previous:** `8df2d730c3f0` (2026-07-26T20:13:07.854313+00:00)
**Current:** `767a301d2bae` (2026-07-29T01:40:49.551172+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 638 | 646 | +8 |
| Total | 717 | 717 | 0 |
| Pass rate | 89.0% | 90.1% | +1.1% |
| Mismatched lines | 15285 | 14958 | -327 |
|   Decreased | | | -340 |
|   Increased | | | +13 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `geturl_opcode_target_normalize` | output_mismatch | 0/45 | 45/45 |
| `geturl_target_normalize` | output_mismatch | 4/89 | 89/89 |
| `localconnection` | output_mismatch | 433/579 | 579/579 |
| `xml_socket` | output_mismatch | 1/8 | 8/8 |
| `xml_socket_close_in_handler` | output_mismatch | 0/6 | 6/6 |
| `xml_socket_connect_null` | output_mismatch | 1/12 | 12/12 |
| `xml_socket_on_data` | output_mismatch | 0/7 | 7/7 |
| `xml_socket_segmented` | output_mismatch | 0/29 | 29/29 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `geturl` | output_mismatch | 0/7 | 4/7 | -4 |
| `global_instance_decls` | output_mismatch | 26/758 | 13/758 | +13 |
