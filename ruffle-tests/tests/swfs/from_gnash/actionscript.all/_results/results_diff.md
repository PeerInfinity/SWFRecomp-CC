# Ruffle Test Results Diff

**Previous:** `749db868f78a` (2026-04-20T17:51:29.390697+00:00)
**Current:** `a427f5fc2d64` (2026-04-20T20:43:05.875243+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 109 | 104 | -5 |
| Total | 190 | 184 | -6 |
| Pass rate | 57.4% | 56.5% | -0.9% |
| Mismatched lines | 2632 | 2620 | -12 |

## Missing Tests — Shard Failure (6)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 5 were previously passing
- 1 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `NetStream-v7` | pass | 80/80 |
| `NetStream-v8` | pass | 80/80 |
| `Number-v5` | output_mismatch | 232/244 |
| `Number-v6` | pass | 239/239 |
| `Number-v7` | pass | 237/237 |
| `Number-v8` | pass | 237/237 |

</details>
