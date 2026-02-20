# Ruffle Test Results Diff

**Previous:** `13a5ed54a121` (2026-02-20T16:41:22.105676+00:00)
**Current:** `0df7bd6e3049` (2026-02-20T16:51:32.253939+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 232 | 230 | -2 |
| Total | 619 | 619 | 0 |
| Pass rate | 37.5% | 37.2% | -0.3% |
| Mismatched lines | 39875 | 39935 | +60 |
|   Decreased | | | -40 |
|   Increased | | | +100 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as_transformed_flag` | output_mismatch | 14/20 | 20/20 |
| `issue_1906` | output_mismatch | 2/4 | 4/4 |
| `stage_object_enumerate` | output_mismatch | 1/4 | 4/4 |

## Newly Failing (5)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `define_function2_preload_order` | output_mismatch | 4/4 | 0/4 |
| `display_object_properties` | output_mismatch | 2/2 | 1/2 |
| `duplicate_movie_clip` | output_mismatch | 20/20 | 19/20 |
| `execution_order1` | output_mismatch | 5/5 | 3/5 |
| `variable_args` | output_mismatch | 5/5 | 0/5 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `placeobject_occupied_depth` | output_mismatch | segfault | 1/6 | - |

## Line Count Changed (18)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `register_and_init_order` | output_mismatch | 30/231 | 42/231 | -12 |
| `frame_size_translated_negative` | output_mismatch | 14/21 | 17/21 | -3 |
| `frame_size_translated_positive` | output_mismatch | 14/21 | 16/21 | -2 |
| `movieclip_depth_methods` | output_mismatch | 93/98 | 95/98 | -2 |
| `transform` | output_mismatch | 63/70 | 65/70 | -2 |
| `clip_events` | output_mismatch | 1/19 | 2/19 | -1 |
| `issue_1104` | output_mismatch | 1/2 | 2/2 | -1 |
| `movieclip_gettextsnapshot` | output_mismatch | 4/112 | 5/112 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `rewind_depth` | output_mismatch | 26/30 | 25/30 | +1 |
| `with` | output_mismatch | 46/49 | 45/49 | +1 |
| `closure_scope` | output_mismatch | 2/7 | 0/7 | +2 |
| `conflicting_instance_names` | output_mismatch | 22/23 | 18/23 | +4 |
| `target_clip_removed` | output_mismatch | 4/5 | 0/5 | +4 |
| `unload` | output_mismatch | 13/52 | 7/52 | +6 |
| `default_names` | output_mismatch | 16/52 | 3/52 | +13 |
| `stage_object_properties` | output_mismatch | 131/241 | 103/241 | +28 |
| `stage_object_properties_swf6` | output_mismatch | 131/231 | 103/231 | +28 |
