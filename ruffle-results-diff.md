# Ruffle Test Results Diff

**Previous:** `6bc4092de792` (2026-02-26T18:54:51.272208+00:00)
**Current:** `4d2a46d503fd` (2026-02-26T19:37:55.966722+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 378 | 380 | +2 |
| Total | 619 | 619 | 0 |
| Pass rate | 61.1% | 61.4% | +0.3% |
| Mismatched lines | 32068 | 32048 | -20 |
|   Decreased | | | -25 |
|   Increased | | | +5 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `stage_object_children` | output_mismatch | 68/83 | 83/83 |
| `target_clip_swf5` | output_mismatch | 0/2 | 2/2 |
| `target_clip_swf6` | output_mismatch | 0/2 | 2/2 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `issue_768` | output_mismatch | 3/3 | 2/3 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `resolve_different_root` | output_mismatch | segfault | 0/2 | - |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `swf5_to_6_cross_call` | output_mismatch | 8/29 | 10/29 | -2 |
| `string_paths_hidden` | output_mismatch | 36/54 | 37/54 | -1 |
| `watch_virtual_property` | output_mismatch | 8/60 | 9/60 | -1 |
| `string_paths_other` | output_mismatch | 31/36 | 29/36 | +2 |
| `swf6_to_5_cross_call` | output_mismatch | 9/29 | 7/29 | +2 |
