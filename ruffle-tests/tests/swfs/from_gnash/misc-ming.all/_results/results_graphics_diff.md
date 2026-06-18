# Ruffle Test Results Diff

**Previous:** `f9f0700382a1` (2026-06-18T05:55:10.490423+00:00)
**Current:** `fe0030e4fc7d` (2026-06-18T21:40:01.283325+00:00)
**⚠️ Incomplete run: 25/30 shards produced results (5 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 66 | 55 | -11 |
| Total | 110 | 92 | -18 |
| Pass rate | 60.0% | 59.8% | -0.2% |
| Mismatched lines | 1211 | 1018 | -193 |

## Missing Tests — Shard Failure (18)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 11 were previously passing
- 7 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `PrototypeEventListeners` | output_mismatch | 1/32 |
| `ResolveEventsTest` | pass | 15/15 |
| `RollOverOutTest` | pass | 5/5 |
| `TextSnapshotTest` | ruffle_matched | 51/132 |
| `displaylist_depths/displaylist_depths_test11` | pass | 15/15 |
| `displaylist_depths/displaylist_depths_test2` | ruffle_matched | 17/31 |
| `displaylist_depths/displaylist_depths_test3` | ruffle_matched | 19/32 |
| `displaylist_depths/displaylist_depths_test4` | pass | 26/26 |
| `frame_label_test` | pass | 17/17 |
| `getTimer_test` | pass | 8/8 |
| `get_frame_number_test` | pass | 31/31 |
| `loop/loop_test` | pass | 21/21 |
| `loop/loop_test10` | ruffle_matched | 5/28 |
| `loop/loop_test2` | pass | 15/15 |
| `loop/loop_test3` | pass | 16/16 |
| `place_and_remove_object_test` | pass | 13/13 |
| `place_object_test` | ruffle_matched | 0/12 |
| `place_object_test2` | ruffle_matched | 0/19 |

</details>
