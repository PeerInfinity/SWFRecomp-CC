# Ruffle Test Results Diff

**Previous:** `7e14f54dd961` (2026-11-23T22:39:55.428710+00:00)
**Current:** `005bea42a286` (2026-11-23T23:56:29.059738+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 214 | 207 | -7 |
| Total | 229 | 221 | -8 |
| Pass rate | 93.4% | 93.7% | +0.3% |
| Mismatched lines | 77 | 57 | -20 |

## Missing Tests — Shard Failure (8)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 7 were previously passing
- 1 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `as3-loader/LoaderTest2` | pass | 7/7 |
| `as3-loader/bug1093712/loader` | pass | 1/1 |
| `as3-loader/bug1157243/empty` | pass | 1/1 |
| `as3-loader/bug1157243/invalid` | pass | 1/1 |
| `as3-loader/events/loader-events` | ruffle_matched | 16/36 |
| `as3-loader/loaderinfo/Preloader` | pass | 1/1 |
| `as3-loader/loaderinfo/loaded-content-properties` | pass | 48/48 |
| `avm1/array` | pass | 7/7 |

</details>
