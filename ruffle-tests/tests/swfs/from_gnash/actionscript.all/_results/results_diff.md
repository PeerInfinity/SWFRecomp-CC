# Ruffle Test Results Diff

**Previous:** `dc2748b675fb` (2026-04-03T22:14:41.121482+00:00)
**Current:** `5ec711b2146b` (2026-04-03T22:44:25.133485+00:00)
**⚠️ Incomplete run: 28/30 shards produced results (2 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 68 | 60 | -8 |
| Total | 190 | 177 | -13 |
| Pass rate | 35.8% | 33.9% | -1.9% |
| Mismatched lines | 4534 | 4333 | -201 |

## Missing Tests — Shard Failure (13)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 8 were previously passing
- 5 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `Camera-v6` | output_mismatch | 33/90 |
| `Camera-v7` | output_mismatch | 33/90 |
| `Camera-v8` | output_mismatch | 33/90 |
| `Color-v5` | pass | 140/140 |
| `Color-v6` | output_mismatch | 165/171 |
| `Color-v7` | pass | 161/161 |
| `Color-v8` | pass | 161/161 |
| `Point-v5` | pass | 7/7 |
| `Point-v6` | pass | 7/7 |
| `Point-v7` | pass | 7/7 |
| `Point-v8` | output_mismatch | 169/193 |
| `Random-v5` | pass | 30/30 |
| `Random-v6` | pass | 30/30 |

</details>
