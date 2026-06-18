# Ruffle Test Results Diff

**Previous:** `f9f0700382a1` (2026-06-18T05:55:10.495512+00:00)
**Current:** `fe0030e4fc7d` (2026-06-18T21:40:01.292377+00:00)
**⚠️ Incomplete run: 25/30 shards produced results (5 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 9 | 8 | -1 |
| Total | 19 | 16 | -3 |
| Pass rate | 47.4% | 50.0% | +2.6% |
| Mismatched lines | 129 | 94 | -35 |

## Missing Tests — Shard Failure (3)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 1 were previously passing
- 2 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `movieclip_destruction_test4` | output_mismatch | 8/40 |
| `soft_reference_test1` | ruffle_matched | 42/45 |
| `submoviegetvar` | pass | 4/4 |

</details>
