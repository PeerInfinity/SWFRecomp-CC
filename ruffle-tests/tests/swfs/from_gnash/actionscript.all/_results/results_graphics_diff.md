# Ruffle Test Results Diff

**Previous:** `1f68e0043c1b` (2026-07-10T21:35:27.233685+00:00)
**Current:** `8a8ff17c73a3` (2026-07-10T22:53:59.499148+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 135 | 128 | -7 |
| Total | 243 | 235 | -8 |
| Pass rate | 55.6% | 54.5% | -1.1% |
| Mismatched lines | 8435 | 8427 | -8 |

## Missing Tests — Shard Failure (8)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 7 were previously passing
- 1 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `NetStream-v5` | pass | 6/6 |
| `NetStream-v6` | pass | 80/80 |
| `NetStream-v7` | pass | 80/80 |
| `NetStream-v8` | pass | 80/80 |
| `Number-v5` | ruffle_matched | 236/244 |
| `Number-v6` | pass | 239/239 |
| `Number-v7` | pass | 237/237 |
| `Number-v8` | pass | 237/237 |

</details>
