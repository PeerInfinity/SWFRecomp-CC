# Ruffle Test Results Diff

**Previous:** `e7443545edda` (2026-03-08T04:48:58.321116+00:00)
**Current:** `5f091c15c0f3` (2026-03-08T06:44:15.806455+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 501 | 503 | +2 |
| Total | 619 | 619 | 0 |
| Pass rate | 80.9% | 81.3% | +0.4% |
| Mismatched lines | 19560 | 19451 | -109 |
|   Decreased | | | -110 |
|   Increased | | | +1 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `mcl_loadclip_replace_root` | output_mismatch | 0/1 | 1/1 |
| `resolve_different_root` | output_mismatch | 0/2 | 2/2 |

## Line Count Changed (10)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `movieclip_state_values` | output_mismatch | 3/114 | 39/114 | -36 |
| `global_swf5_6_7_8_9` | output_mismatch | 1031/1145 | 1057/1145 | -26 |
| `mcl_replace_root_swf7_to_swf6` | output_mismatch | 1/57 | 17/57 | -16 |
| `mcl_replace_root_swf7_to_swf5` | output_mismatch | 1/57 | 14/57 | -13 |
| `loadmovie_registerclass` | output_mismatch | 9/30 | 21/30 | -12 |
| `register_class` | output_mismatch | 44/66 | 48/66 | -4 |
| `global_proto_decls` | output_mismatch | 11/4497 | 11/4497 | 0 |
| `global_proto_decls_delete` | output_mismatch | 1/4158 | 1/4158 | 0 |
| `loadmovienum_cross_version_prototype` | output_mismatch | 6/9 | 6/9 | 0 |
| `register_class_swf6` | output_mismatch | 4/37 | 3/37 | +1 |
