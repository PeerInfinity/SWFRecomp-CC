# Ruffle Test Results Diff

**Previous:** `e6f33267e7f3` (2026-07-24T18:56:22.187017+00:00)
**Current:** `d36c8da2b2bd` (2026-07-24T20:26:59.188497+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 69 | 68 | -1 |
| Total | 111 | 108 | -3 |
| Pass rate | 62.2% | 63.0% | +0.8% |
| Mismatched lines | 1195 | 1164 | -31 |

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
