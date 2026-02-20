# Ruffle Test Results Diff

**Previous:** `6881c80008d8` (2026-02-20T16:59:05.723238+00:00)
**Current:** `0ef9a5195e56` (2026-02-20T17:28:25.116258+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 226 | 231 | +5 |
| Total | 619 | 619 | 0 |
| Pass rate | 36.5% | 37.3% | +0.8% |
| Mismatched lines | 39952 | 39853 | -99 |
|   Decreased | | | -115 |
|   Increased | | | +16 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `define_function2_preload_order` | output_mismatch | 0/4 | 4/4 |
| `display_object_properties` | output_mismatch | 1/2 | 2/2 |
| `execution_order1` | output_mismatch | 0/5 | 5/5 |
| `issue_9885` | output_mismatch | 2/2 | 2/2 |
| `variable_args` | output_mismatch | 0/5 | 5/5 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `clip_events` | output_mismatch | segfault | 1/19 | 1/19 |

## Line Count Changed (28)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `stage_object_properties_swf6` | output_mismatch | 100/231 | 131/231 | -31 |
| `stage_object_properties` | output_mismatch | 102/241 | 132/241 | -30 |
| `default_names` | output_mismatch | 3/52 | 12/52 | -9 |
| `unload` | output_mismatch | 7/52 | 13/52 | -6 |
| `frame_size_translated_positive` | output_mismatch | 16/21 | 20/21 | -4 |
| `target_clip_removed` | output_mismatch | 0/5 | 4/5 | -4 |
| `transform` | output_mismatch | 65/70 | 69/70 | -4 |
| `frame_size_translated_negative` | output_mismatch | 17/21 | 20/21 | -3 |
| `closure_scope` | output_mismatch | 0/7 | 2/7 | -2 |
| `conflicting_instance_names` | output_mismatch | 18/23 | 20/23 | -2 |
| `execution_order4` | output_mismatch | 1/12 | 3/12 | -2 |
| `duplicate_movie_clip` | output_mismatch | 16/20 | 17/20 | -1 |
| `rewind_depth` | output_mismatch | 25/30 | 26/30 | -1 |
| `with` | output_mismatch | 45/49 | 46/49 | -1 |
| `button_children` | output_mismatch | 6/8 | 6/8 | 0 |
| `button_v5` | output_mismatch | 12/18 | 12/18 | 0 |
| `button_v6` | output_mismatch | 10/18 | 10/18 | 0 |
| `do_init_action` | output_mismatch | 3/3 | 3/3 | 0 |
| `funky_function_calls` | output_mismatch | 3/56 | 3/56 | 0 |
| `goto_advance1` | output_mismatch | 1/6 | 1/6 | 0 |
| `goto_advance2` | output_mismatch | 2/2 | 2/2 | 0 |
| `goto_both_ways2` | output_mismatch | 1/3 | 1/3 | 0 |
| `removed_clip_halts_script` | output_mismatch | 1/15 | 1/15 | 0 |
| `movieclip_gettextsnapshot` | output_mismatch | 5/112 | 4/112 | +1 |
| `root_global_parent` | output_mismatch | 2/6 | 1/6 | +1 |
| `tell_target_invalid` | output_mismatch | 1/6 | 0/6 | +1 |
| `tell_target_invalid_swf6` | output_mismatch | 1/5 | 0/5 | +1 |
| `register_and_init_order` | output_mismatch | 42/231 | 30/231 | +12 |
