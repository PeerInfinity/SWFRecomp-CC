# Ruffle Test Results Diff

**Previous:** `57df325235b1` (2026-02-14T02:14:43.888351+00:00)
**Current:** `60874323d211` (2026-02-14T02:38:57.626454+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 155 | 154 | -1 |
| Total | 619 | 619 | 0 |
| Pass rate | 25.0% | 24.9% | -0.1% |
| Mismatched lines | 56758 | 56755 | -3 |
|   Decreased | | | -18 |
|   Increased | | | +15 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `conflicting_instance_names` | output_mismatch | 21/23 | 23/23 |
| `sandbox_type_local_file` | output_mismatch | 0/1 | 1/1 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `new_object_enumerate` | output_mismatch | 7/7 | 4/7 |
| `sandbox_type_local_network` | output_mismatch | 1/1 | 0/1 |
| `swf7_case_sensitive` | output_mismatch | 44/44 | 40/44 |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `object_prototypes` | output_mismatch | 50/74 | 62/74 | -12 |
| `global_proto_decls` | output_mismatch | 1/4497 | 2/4497 | -1 |
| `prototype_enumerate` | output_mismatch | 0/5 | 1/5 | -1 |
| `swf6_case_insensitive` | output_mismatch | 28/42 | 29/42 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `sandbox_type_remote` | output_mismatch | 1/3 | 0/3 | +1 |
| `bitmap_data_hittest` | output_mismatch | 41/132 | 39/132 | +2 |
| `init_object_order` | output_mismatch | 5/15 | 1/15 | +4 |
