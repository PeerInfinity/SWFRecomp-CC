# Ruffle Test Results Diff

**Previous:** `e6f33267e7f3` (2026-07-24T18:56:22.155808+00:00)
**Current:** `d36c8da2b2bd` (2026-07-24T20:26:59.158318+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 159 | 155 | -4 |
| Total | 229 | 222 | -7 |
| Pass rate | 69.4% | 69.8% | +0.4% |
| Mismatched lines | 943 | 932 | -11 |

## Missing Tests — Shard Failure (7)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 4 were previously passing
- 3 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `mouse/start_drag` | pass | 3/3 |
| `mouse/start_drag_lock` | output_mismatch | 2/3 |
| `movieclip` | pass | 9/9 |
| `movieinfo1` | pass | 3/3 |
| `slider_component` | pass | 4/4 |
| `stream1` | output_mismatch | 0/9 |
| `stroke1` | output_mismatch | 0/1 |

</details>
