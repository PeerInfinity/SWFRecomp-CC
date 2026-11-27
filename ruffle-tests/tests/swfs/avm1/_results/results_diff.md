# Ruffle Test Results Diff

**Previous:** `dbc43c157352` (2026-11-27T03:57:01.414605+00:00)
**Current:** `2d40d37996b8` (2026-11-27T07:04:58.919098+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 776 | 750 | -26 |
| Total | 791 | 765 | -26 |
| Pass rate | 98.1% | 98.0% | -0.1% |
| Mismatched lines | 12119 | 12119 | 0 |

## Missing Tests — Shard Failure (26)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 26 were previously passing
- 0 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
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
| `string_paths_reference_launder` | pass | 2/2 |
| `string_paths_timer` | pass | 0/0 |
| `string_paths_unload` | pass | 1/1 |
| `string_paths_variable_alias` | pass | 4/4 |
| `string_paths_variable_scopes` | pass | 5/5 |
| `string_relational_compare` | pass | 4/4 |
| `stylesheet` | pass | 283/283 |
| `stylesheet_load` | pass | 49/49 |
| `stylesheet_transform` | pass | 750/750 |
| `super_edge_cases` | pass | 39/39 |

</details>
