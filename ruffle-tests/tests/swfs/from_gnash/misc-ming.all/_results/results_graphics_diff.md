# Ruffle Test Results Diff

**Previous:** `5bd16324c89f` (2026-06-18T03:47:17.787356+00:00)
**Current:** `5f25304460d4` (2026-06-18T05:42:14.428765+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 66 | 65 | -1 |
| Total | 110 | 106 | -4 |
| Pass rate | 60.0% | 61.3% | +1.3% |
| Mismatched lines | 1211 | 1176 | -35 |

## Missing Tests — Shard Failure (4)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 1 were previously passing
- 3 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `init_action/InitActionTest` | ruffle_matched | 11/17 |
| `init_action/InitActionTest2` | ruffle_matched | 5/29 |
| `instanceNameTest` | pass | 5/5 |
| `key_event_test` | ruffle_matched | 61/66 |

</details>
