# Ruffle Test Results Diff

**Previous:** `aeebf9ede383` (2026-08-15T10:09:49.381589+00:00)
**Current:** `9d038c750eaf` (2026-08-19T13:54:51.861422+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 135 | 131 | -4 |
| Total | 243 | 235 | -8 |
| Pass rate | 55.6% | 55.7% | +0.1% |
| Mismatched lines | 8431 | 8384 | -47 |
|   Decreased | | | -26 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `Sound-v6` | output_mismatch | 113/121 | 121/121 |
| `Sound-v7` | output_mismatch | 113/121 | 121/121 |
| `Sound-v8` | output_mismatch | 113/121 | 121/121 |

## Missing Tests — Shard Failure (8)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 7 were previously passing
- 1 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `Random-v5` | pass | 30/30 |
| `Random-v6` | pass | 30/30 |
| `Random-v7` | pass | 30/30 |
| `Random-v8` | pass | 30/30 |
| `Rectangle-v5` | pass | 7/7 |
| `Rectangle-v6` | pass | 7/7 |
| `Rectangle-v7` | pass | 7/7 |
| `Rectangle-v8` | ruffle_matched | 145/166 |

</details>

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `Sound-v5` | ruffle_matched | 84/100 | 86/100 | -2 |
