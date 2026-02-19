# Ruffle Test Results Diff

**Previous:** `724bae7f65e8` (2026-02-19T03:02:39.305825+00:00)
**Current:** `1ce1d3956efe` (2026-02-19T22:50:09.298438+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 237 | 242 | +5 |
| Total | 619 | 619 | 0 |
| Pass rate | 38.3% | 39.1% | +0.8% |
| Mismatched lines | 39984 | 39381 | -603 |
|   Decreased | | | -603 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `object_prototypes` | output_mismatch | 63/74 | 74/74 |
| `parse_int` | output_mismatch | 1/64 | 64/64 |
| `primitive_type_globals` | output_mismatch | 321/557 | 557/557 |
| `watch` | output_mismatch | 18/117 | 117/117 |
| `watch_virtual_property_proto` | output_mismatch | 0/2 | 2/2 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `swf7_global_funcs` | output_mismatch | 1/232 | 76/232 | -75 |
| `swf6_global_funcs` | output_mismatch | 1/232 | 60/232 | -59 |
| `swf5_global_funcs` | output_mismatch | 1/232 | 57/232 | -56 |
| `closure_scope` | output_mismatch | 0/7 | 2/7 | -2 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
