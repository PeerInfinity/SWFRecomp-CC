# Ruffle Test Results Diff

**Previous:** `dbc43c157352` (2026-11-27T03:57:01.514687+00:00)
**Current:** `2d40d37996b8` (2026-11-27T07:04:59.016758+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 74 | 72 | -2 |
| Total | 111 | 108 | -3 |
| Pass rate | 66.7% | 66.7% | 0% |
| Mismatched lines | 884 | 876 | -8 |
|   Decreased | | | -1 |

## Missing Tests — Shard Failure (3)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 2 were previously passing
- 1 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `opcode_guard_test` | pass | 18/18 |
| `path_format_test` | ruffle_matched | 20/27 |
| `place_and_remove_object_insane_test` | pass | 22/22 |

</details>

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `action_order/action_execution_order_test11` | output_mismatch | 26/32 | 27/32 | -1 |
