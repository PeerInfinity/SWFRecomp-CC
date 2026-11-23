# Ruffle Test Results Diff

**Previous:** `7e14f54dd961` (2026-11-23T22:39:55.439600+00:00)
**Current:** `005bea42a286` (2026-11-23T23:56:29.074091+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 148 | 144 | -4 |
| Total | 243 | 235 | -8 |
| Pass rate | 60.9% | 61.3% | +0.4% |
| Mismatched lines | 7907 | 7891 | -16 |

## Missing Tests — Shard Failure (8)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 4 were previously passing
- 4 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `Inheritance-v5` | ruffle_matched | 114/114 |
| `Inheritance-v6` | ruffle_matched | 173/181 |
| `Inheritance-v7` | ruffle_matched | 177/181 |
| `Inheritance-v8` | ruffle_matched | 177/181 |
| `Instance-v5` | pass | 52/52 |
| `Instance-v6` | pass | 52/52 |
| `Instance-v7` | pass | 52/52 |
| `Instance-v8` | pass | 52/52 |

</details>
