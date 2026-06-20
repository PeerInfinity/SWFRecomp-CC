# Ruffle Test Results Diff

**Previous:** `fe0030e4fc7d` (2026-06-18T22:05:01.970674+00:00)
**Current:** `6e0b2fc8f8b0` (2026-06-20T19:39:30.180375+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 49 | 63 | +14 |
| Total | 82 | 107 | +25 |
| Pass rate | 59.8% | 58.9% | -0.9% |
| Mismatched lines | 931 | 1211 | +280 |

## Added Tests (29)

| Test | Status | Lines |
|------|--------|-------|
| `PrototypeEventListeners` | output_mismatch | 1/32 |
| `ResolveEventsTest` | pass | 15/15 |
| `RollOverOutTest` | pass | 5/5 |
| `TextSnapshotTest` | ruffle_matched | 51/132 |
| `VarAndCharClashTest` | pass | 13/13 |
| `Version4Loader` | pass | 11/11 |
| `Video-EmbedSquareTest` | pass | 2/2 |
| `action_order/ActionOrderTest3` | output_mismatch | 4/62 |
| `action_order/action_execution_order_test3` | pass | 4/4 |
| `action_order/action_execution_order_test4` | ruffle_matched | 19/26 |
| `action_order/action_execution_order_test5` | output_mismatch | 26/35 |
| `action_order/action_execution_order_test6` | output_mismatch | 0/24 |
| `displaylist_depths/displaylist_depths_test9` | pass | 23/23 |
| `duplicate_movie_clip_test` | ruffle_matched | 29/33 |
| `duplicate_movie_clip_test2` | pass | 21/21 |
| `event_handler_scope_test` | pass | 16/16 |
| `loop/loop_test` | pass | 21/21 |
| `loop/loop_test10` | ruffle_matched | 5/28 |
| `loop/loop_test2` | pass | 15/15 |
| `loop/loop_test3` | pass | 16/16 |
| `move_object_test` | pass | 11/11 |
| `multi_doactions_and_goto_frame_test` | pass | 6/6 |
| `new_child_in_unload_test` | pass | 11/11 |
| `opcode_guard_test` | pass | 18/18 |
| `path_format_test` | ruffle_matched | 0/27 |
| `place_and_remove_object_insane_test` | output_mismatch | 17/22 |
| `register_class/registerClassTest2` | ruffle_matched | 36/44 |
| `replace_buttons1test` | ruffle_matched | 15/18 |
| `replace_shapes1test` | pass | 23/23 |

## Missing Tests — Shard Failure (4)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 3 were previously passing
- 1 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `frame_label_test` | pass | 17/17 |
| `getTimer_test` | pass | 8/8 |
| `get_frame_number_test` | pass | 31/31 |
| `gotoFrame2Test` | timeout | - |

</details>
