# Ruffle Test Results Diff

**Previous:** `2c74f64fc3bb` (2026-06-17T21:43:52.802634+00:00)
**Current:** `079c0fefecc6` (2026-06-18T00:01:46.735283+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 66 | 64 | -2 |
| Total | 110 | 107 | -3 |
| Pass rate | 60.0% | 59.8% | -0.2% |
| Mismatched lines | 1211 | 1172 | -39 |

## Missing Tests — Shard Failure (3)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 2 were previously passing
- 1 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `register_class/RegisterClassTest3` | pass | 12/12 |
| `register_class/RegisterClassTest4` | output_mismatch | 3/42 |
| `register_class/registerClassTest` | pass | 51/51 |

</details>
