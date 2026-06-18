# Ruffle Test Results Diff

**Previous:** `f9f0700382a1` (2026-06-18T05:55:10.471183+00:00)
**Current:** `fe0030e4fc7d` (2026-06-18T21:40:01.232883+00:00)
**⚠️ Incomplete run: 26/30 shards produced results (4 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 73 | 65 | -8 |
| Total | 92 | 80 | -12 |
| Pass rate | 79.3% | 81.2% | +1.9% |
| Mismatched lines | 394 | 316 | -78 |

## Missing Tests — Shard Failure (12)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 8 were previously passing
- 4 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `avm1/haxe/flocons1` | pass | 2/2 |
| `avm1/haxe/flocons2` | pass | 3/3 |
| `avm1/hitarea` | ruffle_matched | 2/4 |
| `avm1/target` | pass | 18/18 |
| `avm1/text-bind` | pass | 0/0 |
| `avm1/textfield/textfield-html` | pass | 4/4 |
| `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | pass | 3/3 |
| `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | pass | 1/1 |
| `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | output_mismatch | 29/70 |
| `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | output_mismatch | 12/29 |
| `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | pass | 5/5 |
| `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | output_mismatch | 17/35 |

</details>
