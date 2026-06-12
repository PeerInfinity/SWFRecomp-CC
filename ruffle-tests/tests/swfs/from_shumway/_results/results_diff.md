# Ruffle Test Results Diff

**Previous:** `0b5f209663a8` (2026-06-12T02:38:17.789615+00:00)
**Current:** `3b477dec9296` (2026-06-12T03:59:52.668503+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 73 | 72 | -1 |
| Total | 92 | 89 | -3 |
| Pass rate | 79.3% | 80.9% | +1.6% |
| Mismatched lines | 394 | 350 | -44 |

## Missing Tests — Shard Failure (3)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 1 were previously passing
- 2 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | pass | 6/6 |
| `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | output_mismatch | 17/37 |
| `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | output_mismatch | 19/43 |

</details>
