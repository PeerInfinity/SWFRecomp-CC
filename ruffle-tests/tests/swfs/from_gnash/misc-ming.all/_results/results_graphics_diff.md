# Ruffle Test Results Diff

**Previous:** `dbc43c157352` (2026-11-27T03:35:22.825020+00:00)
**Current:** `2d40d37996b8` (2026-11-27T06:45:05.646307+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 74 | 70 | -4 |
| Total | 111 | 107 | -4 |
| Pass rate | 66.7% | 65.4% | -1.3% |
| Mismatched lines | 884 | 883 | -1 |
|   Decreased | | | -1 |

## Missing Tests — Shard Failure (4)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 4 were previously passing
- 0 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `action_order/action_execution_order_test7` | pass | 7/7 |
| `action_order/action_execution_order_test8-v5` | pass | 11/11 |
| `action_order/action_execution_order_test8-v6` | pass | 11/11 |
| `action_order/action_execution_order_test9` | pass | 4/4 |

</details>

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `action_order/action_execution_order_test11` | output_mismatch | 26/32 | 27/32 | -1 |
