# Ruffle Test Results Diff

**Previous:** `dbc43c157352` (2026-11-27T03:35:22.794393+00:00)
**Current:** `2d40d37996b8` (2026-11-27T06:45:05.617153+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 315 | 307 | -8 |
| Total | 316 | 308 | -8 |
| Pass rate | 99.7% | 99.7% | 0% |
| Mismatched lines | 2 | 2 | 0 |

## Added Tests (3)

| Test | Status | Lines |
|------|--------|-------|
| `avm1_attach_timeline_frame_order` | pass | 82/82 |
| `avm1_tabindex_child_null` | pass | 3/3 |
| `lowq_stroke_probe` | pass | 0/0 |

## Missing Tests — Shard Failure (11)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 11 were previously passing
- 0 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `avm1_goto_target_child_order_interval` | pass | 7/7 |
| `avm1_goto_target_child_order_normal` | pass | 5/5 |
| `avm1_hairline_scaled_instances` | pass | 1/1 |
| `avm1_hittest_hairline` | pass | 28/28 |
| `avm1_hittest_shape_stale_matrix` | pass | 28/28 |
| `avm1_holder_drawing_under_children` | pass | 1/1 |
| `avm1_jpeg3_alpha_bitmap` | pass | 0/0 |
| `avm1_key_isdown_protected` | pass | 8/8 |
| `avm1_loaded_bare_goto` | pass | 17/17 |
| `avm1_loaded_bare_goto_seq` | pass | 4/4 |
| `avm1_loaded_goto_play_deferred` | pass | 31/31 |

</details>
