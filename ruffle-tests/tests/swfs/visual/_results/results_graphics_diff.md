# Ruffle Test Results Diff

**Previous:** `16343c6e1b7a` (2026-07-31T20:48:45.201507+00:00)
**Current:** `569a215e4199` (2026-07-31T23:03:09.712849+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 138 | 135 | -3 |
| Total | 143 | 139 | -4 |
| Pass rate | 96.5% | 97.1% | +0.6% |
| Mismatched lines | 98 | 98 | 0 |

## Missing Tests — Shard Failure (4)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 3 were previously passing
- 1 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `simple_shapes/gradients/reflect` | pass | 0/0 |
| `simple_shapes/gradients/repeat` | pass | 0/0 |
| `simple_shapes/heavy_tesselation` | recomp_fail | - |
| `simple_shapes/layers` | pass | 0/0 |

</details>
