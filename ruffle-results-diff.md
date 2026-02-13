# Ruffle Test Results Diff

**Previous:** `2032bc1f5f90` (2026-02-13T21:41:54.974962+00:00)
**Current:** `e1ce7372f9e9` (2026-02-13T21:49:14.073638+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 139 | 135 | -4 |
| Total | 619 | 619 | 0 |
| Pass rate | 22.5% | 21.8% | -0.7% |
| Mismatched lines | 57692 | 57298 | -394 |
|   Decreased | | | -433 |
|   Increased | | | +39 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `define_function2_preload_order` | output_mismatch | 2/4 | 4/4 |

## Newly Failing (5)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `as_transformed_flag` | output_mismatch | 20/20 | 14/20 |
| `goto_frame_number` | output_mismatch | 3/3 | 2/3 |
| `movieclip_name_from_timeline` | output_mismatch | 13/13 | 10/13 |
| `set_variable_scope` | output_mismatch | 58/58 | 51/58 |
| `swf7_case_sensitive` | output_mismatch | 44/44 | 41/44 |

## Line Count Changed (50)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `stage_object_properties` | output_mismatch | 54/241 | 155/241 | -101 |
| `stage_object_properties_swf6` | output_mismatch | 54/231 | 149/231 | -95 |
| `selection` | output_mismatch | 0/454 | 42/454 | -42 |
| `movieclip_hittest_shapeflag` | output_mismatch | 10/338 | 48/338 | -38 |
| `goto_methods` | output_mismatch | 0/40 | 20/40 | -20 |
| `typeof` | output_mismatch | 0/22 | 19/22 | -19 |
| `watch` | output_mismatch | 0/117 | 18/117 | -18 |
| `extends_chain` | output_mismatch | 0/134 | 15/134 | -15 |
| `stylesheet` | output_mismatch | 0/283 | 14/283 | -14 |
| `register_and_init_order` | output_mismatch | 30/231 | 42/231 | -12 |
| `target_path` | output_mismatch | 0/14 | 11/14 | -11 |
| `as2_super_via_manual_prototype` | output_mismatch | 0/40 | 6/40 | -6 |
| `as2_oop` | output_mismatch | 0/13 | 5/13 | -5 |
| `init_object_order` | output_mismatch | 0/15 | 5/15 | -5 |
| `duplicate_movie_clip` | output_mismatch | 0/20 | 4/20 | -4 |
| `goto_frame2` | output_mismatch | 0/44 | 4/44 | -4 |
| `execution_order1` | output_mismatch | 0/5 | 3/5 | -3 |
| `goto_frame` | output_mismatch | 0/12 | 3/12 | -3 |
| `hittest_morph` | output_mismatch | 0/70 | 3/70 | -3 |
| `target_clip_removed` | output_mismatch | 1/5 | 4/5 | -3 |
| `color` | output_mismatch | 0/57 | 2/57 | -2 |
| `execution_order2` | output_mismatch | 3/7 | 5/7 | -2 |
| `goto_label` | output_mismatch | 0/17 | 2/17 | -2 |
| `unload` | output_mismatch | 0/52 | 2/52 | -2 |
| `button_children` | output_mismatch | 0/8 | 1/8 | -1 |
| `issue_9885` | output_mismatch | 0/2 | 1/2 | -1 |
| `as2_super_and_this_v6` | output_mismatch | 0/97 | 0/97 | 0 |
| `as2_super_and_this_v8` | output_mismatch | 0/85 | 0/85 | 0 |
| `clip_events` | output_mismatch | 1/19 | 1/19 | 0 |
| `execution_order4` | output_mismatch | 1/12 | 1/12 | 0 |
| `extends_native_type` | output_mismatch | 0/11 | 0/11 | 0 |
| `loadmovie_registerclass` | output_mismatch | 0/30 | 0/30 | 0 |
| `localconnection` | output_mismatch | 0/579 | 0/579 | 0 |
| `movieclip_gettextsnapshot` | output_mismatch | 1/112 | 1/112 | 0 |
| `movieclip_init_object` | output_mismatch | 0/5 | 0/5 | 0 |
| `native_objects_swf6` | output_mismatch | 0/84 | 0/84 | 0 |
| `native_objects_swf7` | output_mismatch | 0/84 | 0/84 | 0 |
| `native_objects_swf8` | output_mismatch | 0/84 | 0/84 | 0 |
| `tell_target_invalid` | output_mismatch | 0/6 | 0/6 | 0 |
| `tell_target_invalid_swf6` | output_mismatch | 0/5 | 0/5 | 0 |
| `timer_run_actions` | output_mismatch | 0/18 | 0/18 | 0 |
| `unload_nested_child` | output_mismatch | 0/5 | 0/5 | 0 |
| `display_object_properties` | output_mismatch | 1/2 | 0/2 | +1 |
| `path_string` | segfault | 44/322 | 43/322 | +1 |
| `stage_object_children` | output_mismatch | 67/83 | 66/83 | +1 |
| `swf5_no_closure` | output_mismatch | 2/19 | 1/19 | +1 |
| `tell_target` | output_mismatch | 4/37 | 3/37 | +1 |
| `remove_movie_clip` | output_mismatch | 9/29 | 7/29 | +2 |
| `swf6_case_insensitive` | output_mismatch | 28/42 | 25/42 | +3 |
| `funky_function_calls` | output_mismatch | 12/56 | 3/56 | +9 |
