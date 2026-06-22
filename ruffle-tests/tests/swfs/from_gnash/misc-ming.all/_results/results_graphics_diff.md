# Ruffle Test Results Diff

**Previous:** `96e9660aefe6` (2026-06-22T03:27:53.486534+00:00)
**Current:** `3c5a3c75e1cf` (2026-06-22T18:02:53.101040+00:00)
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
