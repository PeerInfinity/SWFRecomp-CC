# Ruffle Test Results Diff

**Previous:** `2c74f64fc3bb` (2026-06-17T21:43:52.764883+00:00)
**Current:** `079c0fefecc6` (2026-06-18T00:01:46.697658+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 622 | 602 | -20 |
| Total | 701 | 678 | -23 |
| Pass rate | 88.7% | 88.8% | +0.1% |
| Mismatched lines | 16460 | 15149 | -1311 |

## Missing Tests — Shard Failure (23)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 20 were previously passing
- 3 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
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
| `text_format_font_max_length` | pass | 2/2 |
| `text_format_get_text_extent_undefined_width` | pass | 10/10 |
| `text_format_rounding_swf7` | pass | 840/840 |
| `text_format_rounding_swf8` | pass | 840/840 |
| `textfield_background_color` | pass | 11/11 |
| `textfield_border_color` | pass | 11/11 |
| `textfield_cache_as_bitmap` | pass | 1/1 |

</details>
