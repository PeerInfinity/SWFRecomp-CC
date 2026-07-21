# Ruffle Test Results Diff

**Previous:** `93299b884de8` (2026-07-20T04:49:53.455905+00:00)
**Current:** `63ca22e398c4` (2026-07-21T23:49:05.173534+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 135 | 130 | -5 |
| Total | 243 | 235 | -8 |
| Pass rate | 55.6% | 55.3% | -0.3% |
| Mismatched lines | 8435 | 8417 | -18 |

## Missing Tests — Shard Failure (8)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 5 were previously passing
- 3 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `Key-v5` | pass | 51/51 |
| `Key-v6` | pass | 55/55 |
| `Key-v7` | pass | 55/55 |
| `Key-v8` | pass | 55/55 |
| `LoadVars-v5` | pass | 8/8 |
| `LoadVars-v6` | ruffle_matched | 146/152 |
| `LoadVars-v7` | ruffle_matched | 146/152 |
| `LoadVars-v8` | ruffle_matched | 146/152 |

</details>
