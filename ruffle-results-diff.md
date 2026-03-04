# Ruffle Test Results Diff

**Previous:** `020dca16a094` (2026-03-03T20:56:54.493288+00:00)
**Current:** `cd846dfe33d5` (2026-03-03T21:39:50.218671+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 435 | 438 | +3 |
| Total | 619 | 619 | 0 |
| Pass rate | 70.3% | 70.8% | +0.5% |
| Mismatched lines | 22942 | 22995 | +53 |
|   Decreased | | | -3 |
|   Increased | | | +56 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `on_construct` | output_mismatch | 24/25 | 25/25 |
| `string_paths_variable_scopes` | output_mismatch | 4/5 | 5/5 |
| `swf5_no_closure` | output_mismatch | 18/19 | 19/19 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | compile_fail | output_mismatch | - | 286/338 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `removed_target_clip_scope` | output_mismatch | 16/35 | 12/35 | +4 |
