# Ruffle Test Results Diff

**Previous:** `df9560ff612e` (2026-09-03T22:09:10.289139+00:00)
**Current:** `86d4d6aac5b3` (2026-09-04T00:54:58.317621+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 689 | 666 | -23 |
| Total | 730 | 706 | -24 |
| Pass rate | 94.4% | 94.3% | -0.1% |
| Mismatched lines | 11504 | 11501 | -3 |

## Missing Tests — Shard Failure (24)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 23 were previously passing
- 1 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `swf4_actions_coercion_order` | pass | 157/157 |
| `swf4_bool` | pass | 4/4 |
| `swf4_function_calls` | pass | 7/7 |
| `swf4_vars` | ruffle_matched | 22/25 |
| `swf5_encoding` | pass | 3/3 |
| `swf5_global_funcs` | pass | 232/232 |
| `swf5_no_closure` | pass | 19/19 |
| `swf5_to_6_cross_call` | pass | 29/29 |
| `swf5_xml_event_handler_context` | pass | 2/2 |
| `swf6_case_insensitive` | pass | 42/42 |
| `swf6_global_funcs` | pass | 232/232 |
| `swf6_string_as_bool` | pass | 15/15 |
| `swf6_to_5_cross_call` | pass | 29/29 |
| `swf7_case_sensitive` | pass | 44/44 |
| `swf7_global_funcs` | pass | 232/232 |
| `tab_ordering_automatic_basic` | pass | 92/92 |
| `tab_ordering_automatic_order_grid` | pass | 21/21 |
| `tab_ordering_automatic_order_same_position` | pass | 12/12 |
| `tab_ordering_children` | pass | 208/208 |
| `tab_ordering_custom_basic` | pass | 71/71 |
| `tab_ordering_custom_duplicate_index` | pass | 22/22 |
| `tab_ordering_custom_i32_vs_u32` | pass | 12/12 |
| `tab_ordering_custom_m1` | pass | 29/29 |
| `tab_ordering_events` | pass | 150/150 |

</details>
