# Ruffle Test Results Diff

**Previous:** `2d40d37996b8` (2026-11-27T16:08:12.445869+00:00)
**Current:** `0224aaf25632` (2026-11-27T22:24:41.224978+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 74 | 76 | +2 |
| Total | 111 | 111 | 0 |
| Pass rate | 66.7% | 68.5% | +1.8% |
| Mismatched lines | 883 | 1080 | +197 |
|   Decreased | | | -12 |
|   Increased | | | +209 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `action_order/action_execution_order_test11` | output_mismatch | 27/32 | 32/32 |
| `action_order/action_execution_order_test4` | output_mismatch | 19/26 | 26/26 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `ButtonEventsTest` | ruffle_matched | output_mismatch | 666/679 | 458/679 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `action_order/PlaceAndRemove` | output_mismatch | 15/96 | 15/96 | 0 |
| `action_order/action_execution_order_extend_test` | output_mismatch | 8/32 | 7/32 | +1 |
