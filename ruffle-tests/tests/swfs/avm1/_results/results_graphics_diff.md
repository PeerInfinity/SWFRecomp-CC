# Ruffle Test Results Diff

**Previous:** `485cab11544b` (2026-06-18T02:01:16.324714+00:00)
**Current:** `6308c4a03e34` (2026-06-18T03:34:16.123030+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 622 | 600 | -22 |
| Total | 701 | 678 | -23 |
| Pass rate | 88.7% | 88.5% | -0.2% |
| Mismatched lines | 16460 | 16458 | -2 |

## Missing Tests — Shard Failure (23)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 22 were previously passing
- 1 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `textfield_maxchars` | pass | 3/3 |
| `textfield_properties` | pass | 44/44 |
| `textfield_props_swf5` | ruffle_matched | 173/175 |
| `textfield_props_swf6` | pass | 210/210 |
| `textfield_props_swf7` | pass | 210/210 |
| `textfield_props_swf8` | pass | 210/210 |
| `textfield_text` | pass | 7/7 |
| `textfield_variable` | pass | 81/81 |
| `textsnapshot_available_text` | pass | 20/20 |
| `textsnapshot_findtext` | pass | 44/44 |
| `textsnapshot_gettext` | pass | 55/55 |
| `textsnapshot_props_swf5` | pass | 56/56 |
| `textsnapshot_props_swf6` | pass | 56/56 |
| `textsnapshot_text_order` | pass | 1/1 |
| `this_scoping` | pass | 52/52 |
| `this_swf5` | pass | 41/41 |
| `this_swf6` | pass | 41/41 |
| `this_swf7` | pass | 41/41 |
| `timeline_function_def` | pass | 7/7 |
| `timeout` | pass | 0/0 |
| `timer_run_actions` | pass | 18/18 |
| `trace` | pass | 8/8 |
| `transform` | pass | 70/70 |

</details>
