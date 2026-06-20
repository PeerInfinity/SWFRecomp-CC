# Ruffle Test Results Diff

**Previous:** `fe0030e4fc7d` (2026-06-18T22:05:01.974515+00:00)
**Current:** `6e0b2fc8f8b0` (2026-06-20T19:39:30.185623+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 6 | 10 | +4 |
| Total | 15 | 19 | +4 |
| Pass rate | 40.0% | 52.6% | +12.6% |
| Mismatched lines | 117 | 142 | +25 |
|   Decreased | | | -5 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `opcode_guard_test2` | output_mismatch | 19/24 | 24/24 |

## Added Tests (5)

| Test | Status | Lines |
|------|--------|-------|
| `gotoFrameFromInterval2` | output_mismatch | 2/23 |
| `gotoFrameLabelAsFunction` | pass | 6/6 |
| `mouse_drag_test` | pass | 12/12 |
| `registerclass_test3` | ruffle_matched | 15/27 |
| `submoviegetvar` | pass | 4/4 |

## Missing Tests — Shard Failure (1)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 0 were previously passing
- 1 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `soft_reference_test1` | ruffle_matched | 42/45 |

</details>
