# Ruffle Test Results Diff

**Previous:** `d6808409a87a` (2026-04-27T00:35:33.098697+00:00)
**Current:** `df6df0c0057d` (2026-04-27T01:54:26.546244+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 46 | 43 | -3 |
| Total | 102 | 102 | 0 |
| Pass rate | 45.1% | 42.2% | -2.9% |
| Mismatched lines | 2074 | 2081 | +7 |
|   Decreased | | | -23 |
|   Increased | | | +30 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `consecutive_goto_frame_test` | output_mismatch | 3/12 | 12/12 |

## Newly Failing (4)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `action_order/action_execution_order_test7` | output_mismatch | 7/7 | 1/7 |
| `action_order/action_execution_order_test8-v5` | output_mismatch | 11/11 | 5/11 |
| `action_order/action_execution_order_test8-v6` | output_mismatch | 11/11 | 5/11 |
| `timeline_var_test` | output_mismatch | 11/11 | 6/11 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `action_order/ActionOrderTest5` | output_mismatch | 6/51 | 18/51 | -12 |
| `action_order/ActionOrderTest4` | output_mismatch | 7/64 | 9/64 | -2 |
| `action_order/ActionOrderTest3` | output_mismatch | 6/62 | 6/62 | 0 |
| `action_order/action_execution_order_test6` | ruffle_matched | 19/24 | 12/24 | +7 |
