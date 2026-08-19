# Ruffle Test Results Diff

**Previous:** `aeebf9ede383` (2026-08-15T10:09:49.363298+00:00)
**Current:** `9d038c750eaf` (2026-08-19T13:54:51.845280+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 210 | 205 | -5 |
| Total | 229 | 221 | -8 |
| Pass rate | 91.7% | 92.8% | +1.1% |
| Mismatched lines | 293 | 160 | -133 |
|   Decreased | | | -132 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `acid/acid-shapes` | output_mismatch | 0/120 | 120/120 |
| `as3-loader/loaderinfo/loaded-content-properties` | output_mismatch | 36/48 | 48/48 |

## Missing Tests — Shard Failure (8)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 7 were previously passing
- 1 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `bitmapdata/draw-and-read` | pass | 1/1 |
| `bitmapdata/getpixel-from-embedded` | output_mismatch | 1/2 |
| `blendmode/blendmode_1` | pass | 2/2 |
| `blendmode/blendmode_2` | pass | 4/4 |
| `blendmode/blendmode_3` | pass | 2/2 |
| `button1` | pass | 1/1 |
| `button2` | pass | 1/1 |
| `button3` | pass | 1/1 |

</details>
