# Ruffle Test Results Diff

**Previous:** `4fecbb666ea4` (2026-03-03T20:34:07.856046+00:00)
**Current:** `020dca16a094` (2026-03-03T20:56:54.493288+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 437 | 435 | -2 |
| Total | 619 | 619 | 0 |
| Pass rate | 70.6% | 70.3% | -0.3% |
| Mismatched lines | 22993 | 22942 | -51 |
|   Decreased | | | -61 |
|   Increased | | | +10 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `string_paths_unload` | output_mismatch | 0/1 | 1/1 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `on_construct` | output_mismatch | 25/25 | 24/25 |
| `string_paths_variable_scopes` | output_mismatch | 5/5 | 4/5 |
| `swf5_no_closure` | output_mismatch | 19/19 | 18/19 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | output_mismatch | compile_fail | 286/338 | - |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `call` | output_mismatch | 5/63 | 13/63 | -8 |
| `removed_target_clip_scope` | output_mismatch | 23/35 | 16/35 | +7 |
