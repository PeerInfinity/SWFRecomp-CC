# Ruffle Test Results Diff

**Previous:** `aca2a606e973` (2026-07-16T10:37:05.803967+00:00)
**Current:** `a05b56ddf072` (2026-07-16T22:53:07.483121+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 135 | 131 | -4 |
| Total | 243 | 235 | -8 |
| Pass rate | 55.6% | 55.7% | +0.1% |
| Mismatched lines | 8435 | 8305 | -130 |

## Missing Tests — Shard Failure (8)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 4 were previously passing
- 4 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `array-v5` | output_mismatch | 552/560 |
| `array-v6` | output_mismatch | 624/644 |
| `array-v7` | output_mismatch | 603/654 |
| `array-v8` | output_mismatch | 603/654 |
| `case-v5` | pass | 39/39 |
| `case-v6` | pass | 73/73 |
| `case-v7` | pass | 67/67 |
| `case-v8` | pass | 67/67 |

</details>
