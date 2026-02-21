# Ruffle Test Results Diff

**Previous:** `d037a4200dff` (2026-02-21T04:53:34.044745+00:00)
**Current:** `139ab34eb4c8` (2026-02-21T06:56:36.006131+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 263 | 266 | +3 |
| Total | 619 | 619 | 0 |
| Pass rate | 42.5% | 43.0% | +0.5% |
| Mismatched lines | 39035 | 39011 | -24 |
|   Decreased | | | -27 |
|   Increased | | | +3 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `boxed_primitives` | output_mismatch | 23/24 | 24/24 |
| `issue_1104` | output_mismatch | 2/2 | 2/2 |
| `movieclip_depth_methods` | output_mismatch | 97/98 | 98/98 |
| `placeobject_occupied_depth` | segfault | - | 6/6 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `goto_execution_order` | output_mismatch | 2/2 | 1/2 |

## Line Count Changed (12)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `movieclip_getbounds` | output_mismatch | 45/191 | 53/191 | -8 |
| `local_to_global` | output_mismatch | 41/49 | 47/49 | -6 |
| `stage_object_properties_swf6` | output_mismatch | 210/231 | 214/231 | -4 |
| `stage_object_properties` | output_mismatch | 223/241 | 226/241 | -3 |
| `default_names` | output_mismatch | 15/52 | 16/52 | -1 |
| `edittext_hscroll` | output_mismatch | 17/27 | 18/27 | -1 |
| `hittest_lockroot` | output_mismatch | 6/15 | 7/15 | -1 |
| `with` | output_mismatch | 46/49 | 47/49 | -1 |
| `clip_events` | output_mismatch | 1/19 | 1/19 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `issue_2870` | output_mismatch | 2/3 | 1/3 | +1 |
| `tell_target_invalid_swf6` | output_mismatch | 1/5 | 0/5 | +1 |
