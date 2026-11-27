# Ruffle Test Results Diff

**Previous:** `dbc43c157352` (2026-11-27T03:35:22.817462+00:00)
**Current:** `2d40d37996b8` (2026-11-27T06:45:05.639249+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 181 | 177 | -4 |
| Total | 243 | 235 | -8 |
| Pass rate | 74.5% | 75.3% | +0.8% |
| Mismatched lines | 7614 | 7594 | -20 |

## Missing Tests — Shard Failure (8)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 4 were previously passing
- 4 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `LocalConnection-v5` | pass | 7/7 |
| `LocalConnection-v6` | pass | 58/58 |
| `LocalConnection-v7` | pass | 58/58 |
| `LocalConnection-v8` | pass | 58/58 |
| `Math-v5` | ruffle_matched | 273/278 |
| `Math-v6` | ruffle_matched | 273/278 |
| `Math-v7` | ruffle_matched | 282/287 |
| `Math-v8` | ruffle_matched | 282/287 |

</details>
