# Ruffle Test Results Diff

**Previous:** `7e14f54dd961` (2026-11-23T22:39:55.447366+00:00)
**Current:** `005bea42a286` (2026-11-23T23:56:29.084557+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 70 | 68 | -2 |
| Total | 111 | 107 | -4 |
| Pass rate | 63.1% | 63.6% | +0.5% |
| Mismatched lines | 959 | 941 | -18 |

## Missing Tests — Shard Failure (4)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 2 were previously passing
- 2 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `action_order/action_execution_order_test` | ruffle_matched | 7/19 |
| `action_order/action_execution_order_test1` | pass | 10/10 |
| `action_order/action_execution_order_test11` | output_mismatch | 26/32 |
| `action_order/action_execution_order_test2` | pass | 5/5 |

</details>
