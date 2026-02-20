# Ruffle Test Results Diff

**Previous:** `0df7bd6e3049` (2026-02-20T16:51:32.253939+00:00)
**Current:** `6881c80008d8` (2026-02-20T16:59:05.723238+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 230 | 226 | -4 |
| Total | 619 | 619 | 0 |
| Pass rate | 37.2% | 36.5% | -0.7% |
| Mismatched lines | 39935 | 39952 | +17 |
|   Decreased | | | -31 |
|   Increased | | | +48 |

## Newly Failing (4)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `clone_sprite_types` | output_mismatch | 24/24 | 12/24 |
| `movieclip_get_instance_at_depth` | output_mismatch | 28/28 | 25/28 |
| `swf7_case_sensitive` | output_mismatch | 44/44 | 43/44 |
| `textfield_properties` | output_mismatch | 44/44 | 43/44 |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `native_objects_swf6` | output_mismatch | segfault | 0/84 | 0/84 |
| `native_objects_swf7` | output_mismatch | segfault | 0/84 | 0/84 |
| `native_objects_swf8` | output_mismatch | segfault | 0/84 | 0/84 |

## Line Count Changed (33)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `button_v5` | output_mismatch | 0/18 | 12/18 | -12 |
| `button_v6` | output_mismatch | 0/18 | 10/18 | -10 |
| `button_children` | output_mismatch | 1/8 | 6/8 | -5 |
| `issue_9885` | output_mismatch | 1/2 | 2/2 | -1 |
| `root_global_parent` | output_mismatch | 1/6 | 2/6 | -1 |
| `tell_target_invalid` | output_mismatch | 0/6 | 1/6 | -1 |
| `tell_target_invalid_swf6` | output_mismatch | 0/5 | 1/5 | -1 |
| `closure_scope` | output_mismatch | 0/7 | 0/7 | 0 |
| `create_empty_movie_clip` | output_mismatch | 2/3 | 2/3 | 0 |
| `default_names` | output_mismatch | 3/52 | 3/52 | 0 |
| `define_function2_preload_order` | output_mismatch | 0/4 | 0/4 | 0 |
| `do_init_action` | output_mismatch | 3/3 | 3/3 | 0 |
| `funky_function_calls` | output_mismatch | 3/56 | 3/56 | 0 |
| `goto_advance1` | output_mismatch | 1/6 | 1/6 | 0 |
| `goto_advance2` | output_mismatch | 2/2 | 2/2 | 0 |
| `goto_both_ways2` | output_mismatch | 1/3 | 1/3 | 0 |
| `movieclip_gettextsnapshot` | output_mismatch | 5/112 | 5/112 | 0 |
| `removed_clip_halts_script` | output_mismatch | 1/15 | 1/15 | 0 |
| `target_clip_removed` | output_mismatch | 0/5 | 0/5 | 0 |
| `variable_args` | output_mismatch | 0/5 | 0/5 | 0 |
| `clip_events` | output_mismatch | 2/19 | 1/19 | +1 |
| `device_font_spacing` | output_mismatch | 1/91 | 0/91 | +1 |
| `movieclip_depth_methods` | output_mismatch | 95/98 | 94/98 | +1 |
| `movieclip_name_from_timeline` | output_mismatch | 12/13 | 11/13 | +1 |
| `stage_object_children` | output_mismatch | 68/83 | 67/83 | +1 |
| `stage_object_properties` | output_mismatch | 103/241 | 102/241 | +1 |
| `swf6_case_insensitive` | output_mismatch | 28/42 | 27/42 | +1 |
| `execution_order4` | output_mismatch | 3/12 | 1/12 | +2 |
| `duplicate_movie_clip` | output_mismatch | 19/20 | 16/20 | +3 |
| `execution_order1` | output_mismatch | 3/5 | 0/5 | +3 |
| `stage_object_properties_swf6` | output_mismatch | 103/231 | 100/231 | +3 |
| `string_paths_other` | output_mismatch | 16/36 | 12/36 | +4 |
| `remove_movie_clip` | output_mismatch | 21/29 | 12/29 | +9 |
