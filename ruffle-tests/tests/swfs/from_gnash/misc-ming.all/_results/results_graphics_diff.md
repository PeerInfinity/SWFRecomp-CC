# Ruffle Test Results Diff

**Previous:** `aca2a606e973` (2026-07-16T10:37:05.823762+00:00)
**Current:** `a05b56ddf072` (2026-07-16T22:53:07.494610+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 68 | 67 | -1 |
| Total | 111 | 108 | -3 |
| Pass rate | 61.3% | 62.0% | +0.7% |
| Mismatched lines | 1200 | 1169 | -31 |

## Missing Tests — Shard Failure (3)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 1 were previously passing
- 2 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `place_and_remove_object_test` | pass | 13/13 |
| `place_object_test` | ruffle_matched | 0/12 |
| `place_object_test2` | ruffle_matched | 0/19 |

</details>
