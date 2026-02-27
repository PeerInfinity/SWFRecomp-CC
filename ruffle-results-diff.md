# Ruffle Test Results Diff

**Previous:** `56afab65ddc6` (2026-02-26T23:28:34.001648+00:00)
**Current:** `518e30146ed4` (2026-02-27T00:48:09.669038+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 384 | 385 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 62.0% | 62.2% | +0.2% |
| Mismatched lines | 31675 | 31555 | -120 |
|   Decreased | | | -120 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `path_string` | output_mismatch | 277/322 | 322/322 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | output_mismatch | compile_fail | 266/338 | - |
| `resolve_different_root` | output_mismatch | segfault | 0/2 | - |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `root_global_parent` | output_mismatch | 1/6 | 2/6 | -1 |
