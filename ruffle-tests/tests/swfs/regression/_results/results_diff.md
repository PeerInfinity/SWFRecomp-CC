# Ruffle Test Results Diff

**Previous:** `dbc43c157352` (2026-11-27T03:57:01.491074+00:00)
**Current:** `2d40d37996b8` (2026-11-27T07:04:58.993730+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 315 | 308 | -7 |
| Total | 316 | 309 | -7 |
| Pass rate | 99.7% | 99.7% | 0% |
| Mismatched lines | 2 | 2 | 0 |

## Added Tests (3)

| Test | Status | Lines |
|------|--------|-------|
| `avm1_attach_timeline_frame_order` | pass | 82/82 |
| `avm1_tabindex_child_null` | pass | 3/3 |
| `lowq_stroke_probe` | pass | 0/0 |

## Missing Tests — Shard Failure (10)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 10 were previously passing
- 0 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `avm2_timeline_gradients` | pass | 7/7 |
| `avm2_timeline_solid` | pass | 6/6 |
| `avm2_timeline_stroke_gradient` | pass | 9/9 |
| `avm2_timeline_text` | pass | 4/4 |
| `avm2_tolerant_verify_quarantine` | pass | 2/2 |
| `avm2_typed_value_ops` | pass | 30/30 |
| `bitmap_pool_layer_cap` | pass | 1/1 |
| `broadcast_cross_swf_version` | pass | 4/4 |
| `broadcast_type1_args` | pass | 14/14 |
| `coerce_cross_swf_version` | pass | 7/7 |

</details>
