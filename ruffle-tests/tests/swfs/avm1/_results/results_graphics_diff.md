# Ruffle Test Results Diff

**Previous:** `5bd16324c89f` (2026-06-18T03:47:17.750663+00:00)
**Current:** `5f25304460d4` (2026-06-18T05:42:14.391714+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 622 | 601 | -21 |
| Total | 701 | 678 | -23 |
| Pass rate | 88.7% | 88.6% | -0.1% |
| Mismatched lines | 16460 | 16458 | -2 |

## Missing Tests — Shard Failure (23)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 21 were previously passing
- 2 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `math_swf8` | pass | 530/530 |
| `matrix` | pass | 171/171 |
| `mcl_as_broadcaster` | pass | 12/12 |
| `mcl_events_swf_version` | pass | 232/232 |
| `mcl_getprogress` | pass | 30/30 |
| `mcl_loadclip` | pass | 149/149 |
| `mcl_loadclip_properties` | pass | 6/6 |
| `mcl_loadclip_replace_root` | pass | 1/1 |
| `mcl_mislabeled_target` | pass | 6/6 |
| `mcl_replace_root_swf7_to_swf5` | ruffle_matched | 56/57 |
| `mcl_replace_root_swf7_to_swf6` | ruffle_matched | 56/57 |
| `mcl_target_gif87a` | pass | 6/6 |
| `mcl_target_gif89a` | pass | 6/6 |
| `mcl_target_jpg` | pass | 6/6 |
| `mcl_target_png` | pass | 6/6 |
| `mcl_unloadclip` | pass | 5/5 |
| `mouse_events` | pass | 8/8 |
| `mouse_events_visible_enabled` | pass | 12/12 |
| `mouse_hover_events_while_dragging` | pass | 1/1 |
| `mouse_listeners` | pass | 67/67 |
| `mouse_pos` | pass | 665/665 |
| `mouse_pos_with_scale_factor` | pass | 260/260 |
| `mouse_wheel_enabled` | pass | 2/2 |

</details>
