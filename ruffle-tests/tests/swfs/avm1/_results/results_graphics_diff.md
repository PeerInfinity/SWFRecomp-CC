# Ruffle Test Results Diff

**Previous:** `aca2a606e973` (2026-07-16T10:37:05.700568+00:00)
**Current:** `a05b56ddf072` (2026-07-16T22:53:07.415287+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 634 | 612 | -22 |
| Total | 708 | 685 | -23 |
| Pass rate | 89.5% | 89.3% | -0.2% |
| Mismatched lines | 15311 | 15307 | -4 |
|   Decreased | | | -1 |

## Missing Tests — Shard Failure (23)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 22 were previously passing
- 1 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
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
| `tab_ordering_events_mouse` | pass | 65/65 |
| `tab_ordering_movieclip_enabled_default` | pass | 462/462 |
| `tab_ordering_properties` | pass | 293/293 |
| `tab_ordering_properties_tab_index_edge_case` | ruffle_matched | 1/4 |

</details>

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `amf0_serde_suite` | output_mismatch | 17/146 | 16/144 | -1 |
