# Ruffle Test Results Diff

**Previous:** `749db868f78a` (2026-04-20T17:51:29.400775+00:00)
**Current:** `a427f5fc2d64` (2026-04-20T20:43:05.885505+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 18 | 17 | -1 |
| Total | 102 | 99 | -3 |
| Pass rate | 17.6% | 17.2% | -0.4% |
| Mismatched lines | 2382 | 2378 | -4 |
|   Increased | | | +13 |

## Missing Tests — Shard Failure (3)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 1 were previously passing
- 2 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `getTimer_test` | pass | 8/8 |
| `get_frame_number_test` | output_mismatch | 27/31 |
| `goto_frame_test` | output_mismatch | 2/15 |

</details>

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `opcode_guard_test` | output_mismatch | 3/18 | 3/18 | 0 |
| `loop/loop_test5` | output_mismatch | 13/24 | 12/24 | +1 |
| `loop/loop_test7` | output_mismatch | 8/15 | 4/15 | +4 |
| `loop/loop_test4` | output_mismatch | 18/22 | 10/22 | +8 |
