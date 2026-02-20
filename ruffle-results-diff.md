# Ruffle Test Results Diff

**Previous:** `a58b421c18f8` (2026-02-20T03:24:27.968549+00:00)
**Current:** `d71ead76eae7` (2026-02-20T03:51:26.467538+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 226 | 227 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 36.5% | 36.7% | +0.2% |
| Mismatched lines | 39585 | 39581 | -4 |
|   Decreased | | | -8 |
|   Increased | | | +4 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as_broadcaster_initialize` | output_mismatch | 7/10 | 10/10 |

## Line Count Changed (11)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `printjob_props_swf7` | output_mismatch | 6/45 | 7/45 | -1 |
| `sound_props_swf5` | output_mismatch | 49/68 | 50/68 | -1 |
| `sound_props_swf6` | output_mismatch | 35/68 | 36/68 | -1 |
| `textsnapshot_props_swf5` | output_mismatch | 13/56 | 14/56 | -1 |
| `textsnapshot_props_swf6` | output_mismatch | 6/56 | 7/56 | -1 |
| `global_proto_decls_delete` | output_mismatch | 0/4158 | 0/4158 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `as_broadcaster` | output_mismatch | 8/41 | 7/41 | +1 |
| `global_proto_decls` | output_mismatch | 9/4497 | 8/4497 | +1 |
| `printjob_props_swf5` | output_mismatch | 6/45 | 5/45 | +1 |
| `printjob_props_swf6` | output_mismatch | 6/45 | 5/45 | +1 |
