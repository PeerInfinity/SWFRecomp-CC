# Ruffle Test Results Diff

**Previous:** `bb3378dad6c9` (2026-04-05T05:39:03.050034+00:00)
**Current:** `64854045e7ed` (2026-04-05T18:15:03.494341+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 572 | 569 | -3 |
| Total | 620 | 620 | 0 |
| Pass rate | 92.3% | 91.8% | -0.5% |
| Mismatched lines | 10262 | 10383 | +121 |
|   Increased | | | +121 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `globals_swf5` | output_mismatch | 304/304 | 274/304 |
| `printjob_props_swf5` | output_mismatch | 45/45 | 3/45 |
| `textsnapshot_props_swf5` | output_mismatch | 56/56 | 9/56 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_proto_decls` | output_mismatch | 803/4497 | 803/4497 | 0 |
| `global_instance_decls` | output_mismatch | 16/758 | 14/758 | +2 |
