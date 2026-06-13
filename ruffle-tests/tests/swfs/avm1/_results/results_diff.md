# Ruffle Test Results Diff

**Previous:** `c764b605aa9a` (2026-06-13T18:26:06.916110+00:00)
**Current:** `eb3bc573d2da` (2026-06-13T20:01:47.872655+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 620 | 600 | -20 |
| Total | 687 | 664 | -23 |
| Pass rate | 90.2% | 90.4% | +0.2% |
| Mismatched lines | 12483 | 11172 | -1311 |

## Missing Tests — Shard Failure (23)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 20 were previously passing
- 3 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `tab_ordering_custom_duplicate_index` | pass | 22/22 |
| `tab_ordering_custom_i32_vs_u32` | pass | 12/12 |
| `tab_ordering_custom_m1` | pass | 29/29 |
| `tab_ordering_events` | pass | 150/150 |
| `tab_ordering_events_mouse` | pass | 65/65 |
| `tab_ordering_movieclip_enabled_default` | pass | 462/462 |
| `tab_ordering_properties` | pass | 293/293 |
| `tab_ordering_properties_tab_index_edge_case` | ruffle_matched | 1/4 |
| `tab_ordering_reverse` | pass | 51/51 |
| `tab_ordering_tabbable` | pass | 47/47 |
| `target_clip_removed` | pass | 5/5 |
| `target_clip_swf5` | pass | 2/2 |
| `target_clip_swf6` | pass | 2/2 |
| `target_path` | pass | 14/14 |
| `target_paths/swf4` | pass | 818/818 |
| `target_paths/swf5` | ruffle_matched | 200/854 |
| `target_paths/swf6` | ruffle_matched | 200/854 |
| `tell_target` | pass | 34/34 |
| `tell_target_invalid` | pass | 5/5 |
| `tell_target_invalid_swf6` | pass | 4/4 |
| `text_blocks_clicks` | pass | 4/4 |
| `text_format` | pass | 1146/1146 |
| `text_format_display` | pass | 21/21 |

</details>
