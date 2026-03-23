# Ruffle Test Results Diff

**Previous:** `3b075cff106f` (2026-03-21T21:02:28.935358+00:00)
**Current:** `4b8442ba351c` (2026-03-23T19:51:55.111107+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 558 | 506 | -52 |
| Total | 619 | 558 | -61 |
| Pass rate | 90.1% | 90.7% | +0.6% |
| Mismatched lines | 12922 | 11817 | -1105 |

## Removed Tests (61)

| Test | Previous Status | Lines |
|------|----------------|-------|
| `register_underflow` | pass | 26/26 |
| `remove_movie_clip` | pass | 29/29 |
| `removed_base_clip_tell_target` | output_mismatch | 0/2 |
| `removed_clip_halts_script` | pass | 15/15 |
| `removed_target_clip_scope` | pass | 35/35 |
| `resolve_different_root` | pass | 2/2 |
| `rewind_depth` | pass | 30/30 |
| `root_button_mode` | pass | 10/10 |
| `root_global_parent` | pass | 6/6 |
| `root_onload` | pass | 1/1 |
| `sandbox_type_local_file` | pass | 1/1 |
| `sandbox_type_local_network` | pass | 1/1 |
| `sandbox_type_remote` | output_mismatch | 1/3 |
| `selection` | pass | 454/454 |
| `selection_handlers` | pass | 27/27 |
| `set_interval` | pass | 27/27 |
| `set_variable_scope` | pass | 58/58 |
| `single_frame` | pass | 1/1 |
| `slash_syntax` | pass | 14/14 |
| `sound` | pass | 628/628 |
| `sound_duration_position_props` | output_mismatch | 2/290 |
| `sound_id3` | output_mismatch | 11/633 |
| `sound_id3_prop` | output_mismatch | 1/138 |
| `sound_load_start` | output_mismatch | 0/3 |
| `sound_multiple_load` | output_mismatch | 0/1 |
| `sound_props_swf5` | pass | 68/68 |
| `sound_props_swf6` | pass | 68/68 |
| `sound_start_load` | pass | 0/0 |
| `stage_display_state` | pass | 16/16 |
| `stage_object_children` | pass | 83/83 |
| `stage_object_enumerate` | pass | 4/4 |
| `stage_object_properties` | pass | 241/241 |
| `stage_object_properties_get_var` | pass | 5/5 |
| `stage_object_properties_swf6` | pass | 231/231 |
| `stage_property_representation` | pass | 586/586 |
| `stage_scale_mode` | pass | 39/39 |
| `strictequals_swf6` | pass | 902/902 |
| `strictly_equals` | pass | 7/7 |
| `string_coercion` | pass | 117/117 |
| `string_methods` | pass | 285/285 |
| `string_methods_negative_args` | pass | 240/240 |
| `string_methods_swfv5` | pass | 275/275 |
| `string_ops_swf6` | pass | 95/95 |
| `string_paths_basic` | pass | 4/4 |
| `string_paths_eval` | pass | 4/4 |
| `string_paths_eval2` | pass | 7/7 |
| `string_paths_hidden` | pass | 54/54 |
| `string_paths_keyevents` | pass | 0/0 |
| `string_paths_other` | pass | 36/36 |
| `string_paths_reference_launder` | output_mismatch | 0/2 |
| `string_paths_timer` | pass | 0/0 |
| `string_paths_unload` | pass | 1/1 |
| `string_paths_variable_alias` | pass | 4/4 |
| `string_paths_variable_scopes` | pass | 5/5 |
| `stylesheet` | pass | 283/283 |
| `stylesheet_load` | output_mismatch | 1/49 |
| `stylesheet_transform` | pass | 750/750 |
| `super_edge_cases` | pass | 39/39 |
| `swf4_actions_bool` | pass | 96/96 |
| `swf4_actions_coercion_order` | pass | 158/158 |
| `swf4_bool` | pass | 4/4 |
