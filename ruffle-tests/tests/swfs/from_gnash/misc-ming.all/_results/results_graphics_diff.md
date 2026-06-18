# Ruffle Test Results Diff

**Previous:** `485cab11544b` (2026-06-18T02:01:16.356564+00:00)
**Current:** `6308c4a03e34` (2026-06-18T03:34:16.160276+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 66 | 65 | -1 |
| Total | 110 | 107 | -3 |
| Pass rate | 60.0% | 60.7% | +0.7% |
| Mismatched lines | 1211 | 1200 | -11 |

## Missing Tests — Shard Failure (3)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 1 were previously passing
- 2 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `register_class/registerClassTest2` | ruffle_matched | 36/44 |
| `replace_buttons1test` | ruffle_matched | 15/18 |
| `replace_shapes1test` | pass | 23/23 |

</details>
