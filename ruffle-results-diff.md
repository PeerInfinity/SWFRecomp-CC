# Ruffle Test Results Diff

**Previous:** `e28bdb31f78e` (2026-02-22T21:38:37.727686+00:00)
**Current:** `7ad16e3f3781` (2026-02-22T22:38:33.635968+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 286 | 288 | +2 |
| Total | 619 | 619 | 0 |
| Pass rate | 46.2% | 46.5% | +0.3% |
| Mismatched lines | 36581 | 36539 | -42 |
|   Decreased | | | -44 |
|   Increased | | | +2 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `slash_syntax` | output_mismatch | 9/14 | 14/14 |
| `stage_display_state` | output_mismatch | 2/16 | 16/16 |

## Line Count Changed (6)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `stage_scale_mode` | output_mismatch | 18/39 | 35/39 | -17 |
| `global_proto_decls` | output_mismatch | 9/4497 | 14/4497 | -5 |
| `define_local_with_paths` | output_mismatch | 19/54 | 21/54 | -2 |
| `global_proto_decls_delete` | output_mismatch | 0/4158 | 1/4158 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `path_string` | output_mismatch | 49/322 | 47/322 | +2 |
