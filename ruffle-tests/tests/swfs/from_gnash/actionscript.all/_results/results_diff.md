# Ruffle Test Results Diff

**Previous:** `08709f65842a` (2026-11-21T17:00:08.570758+00:00)
**Current:** `bc91565cea8e` (2026-11-21T19:30:16.493029+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 148 | 144 | -4 |
| Total | 243 | 235 | -8 |
| Pass rate | 60.9% | 61.3% | +0.4% |
| Mismatched lines | 8079 | 7976 | -103 |

## Missing Tests — Shard Failure (8)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 4 were previously passing
- 4 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `Mouse-v5` | pass | 13/13 |
| `Mouse-v6` | pass | 21/21 |
| `Mouse-v7` | pass | 21/21 |
| `Mouse-v8` | pass | 21/21 |
| `MovieClip-v5` | ruffle_matched | 352/363 |
| `MovieClip-v6` | ruffle_matched | 916/936 |
| `MovieClip-v7` | ruffle_matched | 949/969 |
| `MovieClip-v8` | output_mismatch | 1035/1087 |

</details>
