# Ruffle Test Results Diff

**Previous:** `1365c9f714ae` (2026-06-23T03:07:13.074238+00:00)
**Current:** `f69fb84f1e02` (2026-06-23T18:29:36.070868+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 66 | 63 | -3 |
| Total | 111 | 107 | -4 |
| Pass rate | 59.5% | 58.9% | -0.6% |
| Mismatched lines | 1211 | 1211 | 0 |

## Missing Tests — Shard Failure (4)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 3 were previously passing
- 1 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `frame_label_test` | pass | 17/17 |
| `getTimer_test` | pass | 8/8 |
| `get_frame_number_test` | pass | 31/31 |
| `gotoFrame2Test` | timeout | - |

</details>
