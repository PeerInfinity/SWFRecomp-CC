# Ruffle Test Results Diff

**Previous:** `161ecf124012` (2026-11-21T23:52:47.720248+00:00)
**Current:** `10b5dff69c36` (2026-11-22T04:05:39.624704+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 734 | 742 | +8 |
| Total | 780 | 780 | 0 |
| Pass rate | 94.1% | 95.1% | +1.0% |
| Mismatched lines | 12674 | 12574 | -100 |
|   Decreased | | | -109 |
|   Increased | | | +9 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `amf0_array_matrix` | output_mismatch | 49/50 | 50/50 |
| `lazy_prototype_shared` | output_mismatch | 6/8 | 8/8 |
| `load_vars` | output_mismatch | 29/35 | 35/35 |
| `localconnection_serialize_sparse_array_getters` | output_mismatch | 25/26 | 26/26 |
| `localconnection_xml_unavailable` | output_mismatch | 9/23 | 23/23 |
| `stylesheet_load` | output_mismatch | 1/49 | 49/49 |
| `text_format_get_text_extent_own` | output_mismatch | 10/19 | 19/19 |
| `video_prototype_lazy` | output_mismatch | 20/21 | 21/21 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `text_format_prototype_lazy` | output_mismatch | 6/35 | 32/35 | -26 |
| `global_instance_decls` | output_mismatch | 19/758 | 20/758 | -1 |
| `global_proto_decls` | output_mismatch | 59/4562 | 50/4562 | +9 |
