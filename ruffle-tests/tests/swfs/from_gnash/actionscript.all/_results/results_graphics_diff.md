# Ruffle Test Results Diff

**Previous:** `ca31201a1991` (2026-06-27T21:52:43.333345+00:00)
**Current:** `b7f1a1759734` (2026-06-27T22:54:37.972008+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 135 | 128 | -7 |
| Total | 243 | 235 | -8 |
| Pass rate | 55.6% | 54.5% | -1.1% |
| Mismatched lines | 8690 | 8669 | -21 |

## Missing Tests — Shard Failure (8)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 7 were previously passing
- 1 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `Random-v5` | pass | 30/30 |
| `Random-v6` | pass | 30/30 |
| `Random-v7` | pass | 30/30 |
| `Random-v8` | pass | 30/30 |
| `Rectangle-v5` | pass | 7/7 |
| `Rectangle-v6` | pass | 7/7 |
| `Rectangle-v7` | pass | 7/7 |
| `Rectangle-v8` | ruffle_matched | 145/166 |

</details>
