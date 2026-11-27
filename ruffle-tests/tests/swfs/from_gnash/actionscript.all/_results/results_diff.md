# Ruffle Test Results Diff

**Previous:** `dbc43c157352` (2026-11-27T03:57:01.507184+00:00)
**Current:** `2d40d37996b8` (2026-11-27T07:04:59.009704+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 181 | 176 | -5 |
| Total | 243 | 235 | -8 |
| Pass rate | 74.5% | 74.9% | +0.4% |
| Mismatched lines | 7614 | 1210 | -6404 |

## Missing Tests — Shard Failure (8)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 5 were previously passing
- 3 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `XMLSocket-v5` | pass | 35/35 |
| `XMLSocket-v6` | pass | 35/35 |
| `XMLSocket-v7` | pass | 35/35 |
| `XMLSocket-v8` | pass | 35/35 |
| `argstest-v5` | pass | 4/4 |
| `argstest-v6` | output_mismatch | 84/2192 |
| `argstest-v7` | output_mismatch | 78/2061 |
| `argstest-v8` | output_mismatch | 121/2434 |

</details>
