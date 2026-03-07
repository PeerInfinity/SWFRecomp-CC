# Ruffle Test Results Diff

**Previous:** `75d807879265` (2026-03-07T17:47:36.456537+00:00)
**Current:** `446f5ed7afc5` (2026-03-07T20:22:00.320919+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 498 | 490 | -8 |
| Total | 619 | 619 | 0 |
| Pass rate | 80.5% | 79.2% | -1.3% |
| Mismatched lines | 19602 | 19610 | +8 |
|   Decreased | | | -15 |
|   Increased | | | +23 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `removed_clip_halts_script` | output_mismatch | 1/15 | 15/15 |
| `target_clip_removed` | output_mismatch | 4/5 | 5/5 |

## Newly Failing (10)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `execution_order1` | output_mismatch | 5/5 | 3/5 |
| `execution_order2` | output_mismatch | 7/7 | 7/7 |
| `execution_order4` | output_mismatch | 12/12 | 10/12 |
| `getproperty_swf4` | output_mismatch | 28/28 | 26/28 |
| `remove_movie_clip` | output_mismatch | 29/29 | 25/29 |
| `set_interval` | output_mismatch | 27/27 | 22/27 |
| `stage_object_children` | output_mismatch | 83/83 | 82/83 |
| `tell_target_invalid` | output_mismatch | 6/6 | 5/6 |
| `tell_target_invalid_swf6` | output_mismatch | 5/5 | 4/5 |
| `textfield_properties` | output_mismatch | 44/44 | 43/44 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `removed_target_clip_scope` | output_mismatch | 11/35 | 7/35 | +4 |
