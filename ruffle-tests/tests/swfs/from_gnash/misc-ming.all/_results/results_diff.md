# Ruffle Test Results Diff

**Previous:** `c764b605aa9a` (2026-06-13T18:26:06.953804+00:00)
**Current:** `eb3bc573d2da` (2026-06-13T20:01:47.908404+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 67 | 65 | -2 |
| Total | 110 | 107 | -3 |
| Pass rate | 60.9% | 60.7% | -0.2% |
| Mismatched lines | 1206 | 1167 | -39 |

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
