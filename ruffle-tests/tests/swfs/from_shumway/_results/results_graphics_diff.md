# Ruffle Test Results Diff

**Previous:** `aca2a606e973` (2026-07-16T10:37:05.785809+00:00)
**Current:** `a05b56ddf072` (2026-07-16T22:53:07.473498+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 73 | 72 | -1 |
| Total | 92 | 89 | -3 |
| Pass rate | 79.3% | 80.9% | +1.6% |
| Mismatched lines | 394 | 359 | -35 |

## Missing Tests — Shard Failure (3)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 1 were previously passing
- 2 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | output_mismatch | 12/29 |
| `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | pass | 5/5 |
| `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | output_mismatch | 17/35 |

</details>
