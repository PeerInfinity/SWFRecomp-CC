# Ruffle Test Results Diff

**Previous:** `41811ff06d9f` (2026-02-16T19:32:24.754204+00:00)
**Current:** `480bce068a20` (2026-02-16T23:32:22.236447+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 213 | 213 | 0 |
| Total | 619 | 619 | 0 |
| Pass rate | 34.4% | 34.4% | 0% |
| Mismatched lines | 44458 | 42866 | -1592 |
|   Decreased | | | -1592 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | output_mismatch | compile_fail | 180/338 | - |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `date` | output_mismatch | 3617/6335 | 5049/6335 | -1432 |
| `global_proto_decls` | output_mismatch | 6/4497 | 8/4497 | -2 |
| `global_instance_decls` | output_mismatch | 1/758 | 1/758 | 0 |
| `global_proto_decls_delete` | output_mismatch | 0/4158 | 0/4158 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `native_objects_swf6` | output_mismatch | 0/84 | 0/84 | 0 |
| `native_objects_swf7` | output_mismatch | 0/84 | 0/84 | 0 |
| `native_objects_swf8` | output_mismatch | 0/84 | 0/84 | 0 |
