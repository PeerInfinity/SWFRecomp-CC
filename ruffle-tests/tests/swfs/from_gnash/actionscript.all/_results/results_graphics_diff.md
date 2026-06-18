# Ruffle Test Results Diff

**Previous:** `5bd16324c89f` (2026-06-18T03:47:17.777477+00:00)
**Current:** `5f25304460d4` (2026-06-18T05:42:14.418709+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 135 | 134 | -1 |
| Total | 243 | 235 | -8 |
| Pass rate | 55.6% | 57.0% | +1.4% |
| Mismatched lines | 8808 | 8747 | -61 |

## Missing Tests — Shard Failure (8)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 1 were previously passing
- 7 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `Selection-v5` | pass | 21/21 |
| `Selection-v6` | ruffle_matched | 118/125 |
| `Selection-v7` | ruffle_matched | 118/125 |
| `Selection-v8` | ruffle_matched | 118/125 |
| `Sound-v5` | ruffle_matched | 84/100 |
| `Sound-v6` | ruffle_matched | 113/121 |
| `Sound-v7` | ruffle_matched | 113/121 |
| `Sound-v8` | ruffle_matched | 113/121 |

</details>
