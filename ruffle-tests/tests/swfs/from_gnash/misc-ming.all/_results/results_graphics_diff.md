# Ruffle Test Results Diff

**Previous:** `93299b884de8` (2026-07-20T04:49:53.467606+00:00)
**Current:** `63ca22e398c4` (2026-07-21T23:49:05.185036+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 68 | 66 | -2 |
| Total | 111 | 107 | -4 |
| Pass rate | 61.3% | 61.7% | +0.4% |
| Mismatched lines | 1200 | 1169 | -31 |

## Missing Tests — Shard Failure (4)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 2 were previously passing
- 2 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `action_order/action_execution_order_test3` | pass | 4/4 |
| `action_order/action_execution_order_test4` | ruffle_matched | 19/26 |
| `action_order/action_execution_order_test5` | pass | 35/35 |
| `action_order/action_execution_order_test6` | output_mismatch | 0/24 |

</details>
