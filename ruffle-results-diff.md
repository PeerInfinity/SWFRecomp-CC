# Ruffle Test Results Diff

**Previous:** `480bce068a20` (2026-02-16T23:32:22.236447+00:00)
**Current:** `961ebf322759` (2026-02-17T01:20:28.670292+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 213 | 213 | 0 |
| Total | 619 | 619 | 0 |
| Pass rate | 34.4% | 34.4% | 0% |
| Mismatched lines | 42866 | 43029 | +163 |
|   Increased | | | +163 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | compile_fail | output_mismatch | - | 180/338 |
| `try_catch_finally` | timeout | output_mismatch | - | 113/118 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_instance_decls` | output_mismatch | 1/758 | 1/758 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
