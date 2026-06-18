# Ruffle Test Results Diff

**Previous:** `f9f0700382a1` (2026-06-18T05:55:10.479697+00:00)
**Current:** `fe0030e4fc7d` (2026-06-18T21:40:01.262948+00:00)
**⚠️ Incomplete run: 25/30 shards produced results (5 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 135 | 113 | -22 |
| Total | 243 | 203 | -40 |
| Pass rate | 55.6% | 55.7% | +0.1% |
| Mismatched lines | 8808 | 8023 | -785 |

## Missing Tests — Shard Failure (40)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 22 were previously passing
- 18 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `ContextMenu-v8` | pass | 131/131 |
| `Date-v5` | ruffle_matched | 308/315 |
| `Date-v6` | ruffle_matched | 351/357 |
| `Date-v7` | ruffle_matched | 351/357 |
| `Date-v8` | ruffle_matched | 351/357 |
| `Error-v5` | pass | 28/28 |
| `Error-v6` | pass | 31/31 |
| `Error-v7` | pass | 31/31 |
| `MovieClipLoader-v5` | pass | 6/6 |
| `MovieClipLoader-v6` | pass | 6/6 |
| `MovieClipLoader-v7` | ruffle_matched | 47/165 |
| `MovieClipLoader-v8` | ruffle_matched | 47/165 |
| `NetConnection-v5` | pass | 7/7 |
| `NetConnection-v6` | ruffle_matched | 122/126 |
| `NetConnection-v7` | ruffle_matched | 122/126 |
| `NetConnection-v8` | ruffle_matched | 122/126 |
| `Random-v5` | pass | 30/30 |
| `Random-v6` | pass | 30/30 |
| `Random-v7` | pass | 30/30 |
| `Random-v8` | pass | 30/30 |
| `Rectangle-v5` | pass | 7/7 |
| `Rectangle-v6` | pass | 7/7 |
| `Rectangle-v7` | pass | 7/7 |
| `Rectangle-v8` | ruffle_matched | 145/166 |
| `System-v5` | pass | 67/67 |
| `System-v6` | pass | 100/100 |
| `System-v7` | pass | 101/101 |
| `System-v8` | pass | 101/101 |
| `TextField-v5` | ruffle_matched | 9/12 |
| `TextField-v6` | output_mismatch | 456/545 |
| `TextField-v7` | output_mismatch | 465/570 |
| `TextField-v8` | output_mismatch | 467/571 |
| `array-v5` | output_mismatch | 536/560 |
| `array-v6` | output_mismatch | 608/644 |
| `array-v7` | output_mismatch | 589/654 |
| `array-v8` | output_mismatch | 589/654 |
| `case-v5` | pass | 39/39 |
| `case-v6` | pass | 73/73 |
| `case-v7` | pass | 67/67 |
| `case-v8` | pass | 67/67 |

</details>
