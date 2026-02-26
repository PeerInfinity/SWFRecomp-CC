# Ruffle Test Results Diff

**Previous:** `7f0c2f075b28` (2026-02-26T18:26:21.877753+00:00)
**Current:** `6bc4092de792` (2026-02-26T18:54:51.272208+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 377 | 378 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 60.9% | 61.1% | +0.2% |
| Mismatched lines | 32104 | 32068 | -36 |
|   Decreased | | | -38 |
|   Increased | | | +2 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `tell_target` | output_mismatch | 10/37 | 37/37 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `resolve_different_root` | segfault | output_mismatch | - | 0/2 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `path_string` | output_mismatch | 38/322 | 45/322 | -7 |
| `tell_target_invalid` | output_mismatch | 2/6 | 4/6 | -2 |
| `tell_target_invalid_swf6` | output_mismatch | 2/5 | 4/5 | -2 |
