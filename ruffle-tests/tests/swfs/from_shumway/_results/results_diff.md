# Ruffle Test Results Diff

**Previous:** `dc2748b675fb` (2026-04-03T22:14:41.115227+00:00)
**Current:** `5ec711b2146b` (2026-04-03T22:44:25.127152+00:00)
**⚠️ Incomplete run: 28/30 shards produced results (2 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 17 | 15 | -2 |
| Total | 47 | 43 | -4 |
| Pass rate | 36.2% | 34.9% | -1.3% |
| Mismatched lines | 221 | 202 | -19 |

## Missing Tests — Shard Failure (4)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 2 were previously passing
- 2 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `as3-interfaces` | output_mismatch | 0/6 |
| `avm1movie` | output_mismatch | 0/13 |
| `gradient` | pass | 0/0 |
| `gradientTransform` | pass | 0/0 |

</details>
