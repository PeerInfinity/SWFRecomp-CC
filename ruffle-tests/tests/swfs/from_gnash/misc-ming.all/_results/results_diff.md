# Ruffle Test Results Diff

**Previous:** `08709f65842a` (2026-11-21T17:00:08.578183+00:00)
**Current:** `bc91565cea8e` (2026-11-21T19:30:16.503323+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 69 | 67 | -2 |
| Total | 111 | 107 | -4 |
| Pass rate | 62.2% | 62.6% | +0.4% |
| Mismatched lines | 1012 | 999 | -13 |

## Missing Tests — Shard Failure (4)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 2 were previously passing
- 2 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `callFunction_test` | ruffle_matched | 5/11 |
| `consecutive_goto_frame_test` | pass | 12/12 |
| `displaylist_depths/displaylist_depths_test` | ruffle_matched | 104/111 |
| `displaylist_depths/displaylist_depths_test10` | pass | 10/10 |

</details>
