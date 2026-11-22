# Ruffle Test Results Diff

**Previous:** `336749f1425c` (2026-11-22T02:31:50.769711+00:00)
**Current:** `6b2054090f33` (2026-11-22T03:10:05.587473+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 736 | 742 | +6 |
| Total | 780 | 780 | 0 |
| Pass rate | 94.4% | 95.1% | +0.7% |
| Mismatched lines | 12669 | 12574 | -95 |
|   Decreased | | | -95 |

## Newly Passing (6)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `amf0_array_matrix` | output_mismatch | 49/50 | 50/50 |
| `load_vars` | output_mismatch | 29/35 | 35/35 |
| `localconnection_serialize_sparse_array_getters` | output_mismatch | 25/26 | 26/26 |
| `localconnection_xml_unavailable` | output_mismatch | 9/23 | 23/23 |
| `stylesheet_load` | output_mismatch | 1/49 | 49/49 |
| `text_format_get_text_extent_own` | output_mismatch | 10/19 | 19/19 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `text_format_prototype_lazy` | output_mismatch | 16/35 | 32/35 | -16 |
