# Ruffle Test Results Diff

**Previous:** `8365e99266c8` (2026-04-25T17:43:33.331128+00:00)
**Current:** `017e71a9c308` (2026-04-25T20:11:52.750316+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 42 | 43 | +1 |
| Total | 102 | 102 | 0 |
| Pass rate | 41.2% | 42.2% | +1.0% |
| Mismatched lines | 2217 | 2209 | -8 |
|   Decreased | | | -23 |
|   Increased | | | +15 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `action_order/action_execution_order_test3` | output_mismatch | 1/4 | 4/4 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `loop/loop_test7` | output_mismatch | ruffle_matched | 11/15 | 14/15 |

## Line Count Changed (9)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `register_class/RegisterClassTest4` | output_mismatch | 8/42 | 17/42 | -9 |
| `loop/loop_test6` | output_mismatch | 6/23 | 9/23 | -3 |
| `action_order/action_execution_order_test4` | ruffle_matched | 18/26 | 20/26 | -2 |
| `loop/loop_test10` | output_mismatch | 1/28 | 3/28 | -2 |
| `action_order/ActionOrderTest3` | output_mismatch | 5/62 | 6/62 | -1 |
| `opcode_guard_test` | output_mismatch | 3/18 | 3/18 | 0 |
| `action_order/ActionOrderTest4` | output_mismatch | 10/64 | 7/64 | +3 |
| `action_order/ActionOrderTest5` | output_mismatch | 9/51 | 6/51 | +3 |
| `register_class/registerClassTest2` | output_mismatch | 9/44 | 0/44 | +9 |
