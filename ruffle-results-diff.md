# Ruffle Test Results Diff

**Previous:** `e1ce7372f9e9` (2026-02-13T21:49:14.073638+00:00)
**Current:** `00911d0f7dc3` (2026-02-13T22:21:47.100233+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 135 | 139 | +4 |
| Total | 619 | 619 | 0 |
| Pass rate | 21.8% | 22.5% | +0.7% |
| Mismatched lines | 57298 | 57378 | +80 |
|   Decreased | | | -79 |
|   Increased | | | +159 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as_transformed_flag` | output_mismatch | 14/20 | 20/20 |
| `goto_frame_number` | output_mismatch | 2/3 | 3/3 |
| `movieclip_name_from_timeline` | output_mismatch | 10/13 | 13/13 |
| `set_variable_scope` | output_mismatch | 51/58 | 58/58 |
| `swf7_case_sensitive` | output_mismatch | 41/44 | 44/44 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `execution_order3` | output_mismatch | 4/4 | 2/4 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `goto_methods` | output_mismatch | timeout | 20/40 | - |

## Line Count Changed (37)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `stage_object_properties` | output_mismatch | 155/241 | 165/241 | -10 |
| `stage_object_properties_swf6` | output_mismatch | 149/231 | 158/231 | -9 |
| `default_names` | output_mismatch | 3/52 | 8/52 | -5 |
| `variable_args` | output_mismatch | 0/5 | 5/5 | -5 |
| `swf6_case_insensitive` | output_mismatch | 25/42 | 28/42 | -3 |
| `remove_movie_clip` | output_mismatch | 7/29 | 9/29 | -2 |
| `display_object_properties` | output_mismatch | 0/2 | 1/2 | -1 |
| `path_string` | segfault | 43/322 | 44/322 | -1 |
| `stage_object_children` | output_mismatch | 66/83 | 67/83 | -1 |
| `swf5_no_closure` | output_mismatch | 1/19 | 2/19 | -1 |
| `tell_target` | output_mismatch | 3/37 | 4/37 | -1 |
| `as2_super_and_this_v6` | output_mismatch | 0/97 | 0/97 | 0 |
| `as2_super_and_this_v8` | output_mismatch | 0/85 | 0/85 | 0 |
| `clip_events` | output_mismatch | 1/19 | 1/19 | 0 |
| `extends_native_type` | output_mismatch | 0/11 | 0/11 | 0 |
| `loadmovie_registerclass` | output_mismatch | 0/30 | 0/30 | 0 |
| `localconnection` | output_mismatch | 0/579 | 0/579 | 0 |
| `movieclip_init_object` | output_mismatch | 0/5 | 0/5 | 0 |
| `native_objects_swf6` | output_mismatch | 0/84 | 0/84 | 0 |
| `native_objects_swf7` | output_mismatch | 0/84 | 0/84 | 0 |
| `native_objects_swf8` | output_mismatch | 0/84 | 0/84 | 0 |
| `timer_run_actions` | output_mismatch | 0/18 | 0/18 | 0 |
| `button_children` | output_mismatch | 1/8 | 0/8 | +1 |
| `issue_9885` | output_mismatch | 1/2 | 0/2 | +1 |
| `color` | output_mismatch | 2/57 | 0/57 | +2 |
| `unload` | output_mismatch | 2/52 | 0/52 | +2 |
| `duplicate_movie_clip` | output_mismatch | 4/20 | 0/20 | +4 |
| `as2_oop` | output_mismatch | 5/13 | 0/13 | +5 |
| `init_object_order` | output_mismatch | 5/15 | 0/15 | +5 |
| `as2_super_via_manual_prototype` | output_mismatch | 6/40 | 0/40 | +6 |
| `target_path` | output_mismatch | 11/14 | 0/14 | +11 |
| `register_and_init_order` | output_mismatch | 42/231 | 30/231 | +12 |
| `stylesheet` | output_mismatch | 14/283 | 0/283 | +14 |
| `extends_chain` | output_mismatch | 15/134 | 0/134 | +15 |
| `watch` | output_mismatch | 18/117 | 0/117 | +18 |
| `typeof` | output_mismatch | 19/22 | 0/22 | +19 |
| `selection` | output_mismatch | 42/454 | 0/454 | +42 |
