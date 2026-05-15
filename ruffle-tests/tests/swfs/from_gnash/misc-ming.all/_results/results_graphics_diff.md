# Ruffle Test Results Diff

**Previous:** `17a60dbb6837` (2026-05-14T21:43:11.867345+00:00)
**Current:** `45164a5b0854` (2026-05-15T03:20:32.467791+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 65 | 62 | -3 |
| Total | 110 | 110 | 0 |
| Pass rate | 59.1% | 56.4% | -2.7% |
| Mismatched lines | 1856 | 1895 | +39 |
|   Increased | | | +39 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `loop/loop_test` | output_mismatch | 21/21 | 4/21 |
| `loop/loop_test2` | output_mismatch | 15/15 | 6/15 |
| `loop/loop_test3` | output_mismatch | 16/16 | 9/16 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `loop/loop_test10` | ruffle_matched | output_mismatch | 5/28 | 3/28 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `action_order/ActionOrderTest4` | output_mismatch | 7/64 | 7/64 | 0 |
| `place_object_test2` | ruffle_matched | 0/19 | 0/19 | 0 |
| `action_order/ActionOrderTest5` | output_mismatch | 8/51 | 7/51 | +1 |
| `action_order/ActionOrderTest3` | output_mismatch | 6/62 | 3/62 | +3 |
