# Ruffle Test Results Diff

**Previous:** `aeebf9ede383` (2026-08-15T10:09:49.396138+00:00)
**Current:** `9d038c750eaf` (2026-08-19T13:54:51.874829+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 69 | 65 | -4 |
| Total | 111 | 107 | -4 |
| Pass rate | 62.2% | 60.7% | -1.5% |
| Mismatched lines | 1195 | 1191 | -4 |
|   Decreased | | | -4 |

## Missing Tests — Shard Failure (4)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 4 were previously passing
- 0 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `frame_label_test` | pass | 17/17 |
| `getTimer_test` | pass | 8/8 |
| `get_frame_number_test` | pass | 31/31 |
| `gotoFrame2Test` | pass | 9/9 |

</details>

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `GradientFillTest` | output_mismatch | 119/278 | 123/278 | -4 |
