# Ruffle Test Results Diff

**Previous:** `15ce3f066a16` (2026-03-23T23:43:42.526513+00:00)
**Current:** `36b08b5c2632` (2026-03-26T03:49:28.666202+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 506 | 541 | +35 |
| Total | 558 | 600 | +42 |
| Pass rate | 90.7% | 90.2% | -0.5% |
| Mismatched lines | 11792 | 12852 | +1060 |
|   Decreased | | | -3 |
|   Increased | | | +8 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `tab_ordering_properties_tab_index_edge_case` | output_mismatch | 1/4 | 4/4 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `tab_ordering_properties` | output_mismatch | 293/293 | 285/293 |

## Added Tests (46)

| Test | Status | Lines |
|------|--------|-------|
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

## Missing Tests — Shard Failure (4)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 4 were previously passing
- 0 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `swf4_function_calls` | pass | 7/7 |
| `swf5_encoding` | pass | 3/3 |
| `swf5_global_funcs` | pass | 232/232 |
| `swf5_no_closure` | pass | 19/19 |

</details>
