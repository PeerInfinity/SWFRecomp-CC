# Ruffle Test Results Diff

**Previous:** `e6f33267e7f3` (2026-07-24T18:56:22.172157+00:00)
**Current:** `d36c8da2b2bd` (2026-07-24T20:26:59.173971+00:00)
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
