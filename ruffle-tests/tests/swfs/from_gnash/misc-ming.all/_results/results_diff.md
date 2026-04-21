# Ruffle Test Results Diff

**Previous:** `ec66bc3379da` (2026-04-21T03:00:09.846734+00:00)
**Current:** `06feeaca161c` (2026-04-21T05:44:07.635372+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 18 | 19 | +1 |
| Total | 102 | 102 | 0 |
| Pass rate | 17.6% | 18.6% | +1.0% |
| Mismatched lines | 2382 | 2366 | -16 |
|   Decreased | | | -18 |
|   Increased | | | +2 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `timeline_var_test` | output_mismatch | 8/11 | 11/11 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `action_order/action_execution_order_test6` | output_mismatch | ruffle_matched | 5/24 | 5/24 |

## Line Count Changed (10)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `action_order/action_execution_order_test4` | ruffle_matched | 12/26 | 18/26 | -6 |
| `action_order/action_execution_order_test5` | output_mismatch | 22/35 | 26/35 | -4 |
| `action_order/ActionOrderTest4` | output_mismatch | 9/64 | 10/64 | -1 |
| `action_order/action_execution_order_test11` | output_mismatch | 12/32 | 13/32 | -1 |
| `action_order/action_execution_order_test2` | output_mismatch | 1/5 | 2/5 | -1 |
| `event_handler_scope_test` | output_mismatch | 10/16 | 11/16 | -1 |
| `goto_frame_test` | output_mismatch | 2/15 | 3/15 | -1 |
| `opcode_guard_test` | output_mismatch | 3/18 | 3/18 | 0 |
| `action_order/ActionOrderTest3` | output_mismatch | 6/62 | 5/62 | +1 |
| `consecutive_goto_frame_test` | output_mismatch | 4/12 | 3/12 | +1 |
