# Ruffle Test Results Diff

**Previous:** `485cab11544b` (2026-06-18T02:01:16.341620+00:00)
**Current:** `6308c4a03e34` (2026-06-18T03:34:16.141896+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 73 | 73 | 0 |
| Total | 92 | 89 | -3 |
| Pass rate | 79.3% | 82.0% | +2.7% |
| Mismatched lines | 394 | 369 | -25 |

## Missing Tests — Shard Failure (3)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 0 were previously passing
- 3 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | output_mismatch | 16/22 |
| `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | output_mismatch | 14/19 |
| `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | output_mismatch | 10/24 |

</details>
