# Ruffle Test Results Diff

**Previous:** `fe0030e4fc7d` (2026-06-18T22:05:01.959713+00:00)
**Current:** `6e0b2fc8f8b0` (2026-06-20T19:39:30.165660+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 14 | 18 | +4 |
| Total | 15 | 19 | +4 |
| Pass rate | 93.3% | 94.7% | +1.4% |
| Mismatched lines | 2 | 2 | 0 |

## Added Tests (5)

| Test | Status | Lines |
|------|--------|-------|
| `dict_event` | pass | 5/5 |
| `dict_override` | pass | 2/2 |
| `jump_after_end` | pass | 3/3 |
| `trace-as2/arguments` | pass | 8/8 |
| `trace-as2/this` | pass | 8/8 |

## Missing Tests — Shard Failure (1)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 1 were previously passing
- 0 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `trace-as2/root_onload` | pass | 4/4 |

</details>
