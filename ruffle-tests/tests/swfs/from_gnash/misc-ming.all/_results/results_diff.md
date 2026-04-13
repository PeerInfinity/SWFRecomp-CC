# Ruffle Test Results Diff

**Previous:** `83d3748a6081` (2026-04-13T19:34:06.434980+00:00)
**Current:** `1d207c167423` (2026-04-13T23:00:07.790973+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 9 | 17 | +8 |
| Total | 58 | 102 | +44 |
| Pass rate | 15.5% | 16.7% | +1.2% |
| Mismatched lines | 1719 | 2427 | +708 |
|   Increased | | | +3 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `getTimer_test` | output_mismatch | 8/8 | 5/8 |

## Added Tests (44)

| Test | Status | Lines |
|------|--------|-------|
| `action_order/ActionOrderTest3` | output_mismatch | 6/62 |
| `action_order/ActionOrderTest4` | output_mismatch | 9/64 |
| `action_order/ActionOrderTest5` | output_mismatch | 9/51 |
| `action_order/action_execution_order_test1` | pass | 10/10 |
| `action_order/action_execution_order_test11` | output_mismatch | 12/32 |
| `action_order/action_execution_order_test2` | output_mismatch | 1/5 |
| `action_order/action_execution_order_test3` | output_mismatch | 1/4 |
| `action_order/action_execution_order_test4` | output_mismatch | 12/26 |
| `action_order/action_execution_order_test5` | output_mismatch | 20/35 |
| `action_order/action_execution_order_test6` | output_mismatch | 0/24 |
| `action_order/action_execution_order_test7` | pass | 7/7 |
| `action_order/action_execution_order_test8-v5` | output_mismatch | 8/11 |
| `action_order/action_execution_order_test8-v6` | output_mismatch | 8/11 |
| `action_order/action_execution_order_test9` | pass | 4/4 |
| `displaylist_depths/displaylist_depths_test` | output_mismatch | 79/111 |
| `displaylist_depths/displaylist_depths_test10` | pass | 10/10 |
| `displaylist_depths/displaylist_depths_test11` | output_mismatch | 12/15 |
| `displaylist_depths/displaylist_depths_test2` | output_mismatch | 15/31 |
| `displaylist_depths/displaylist_depths_test3` | output_mismatch | 15/32 |
| `displaylist_depths/displaylist_depths_test4` | pass | 26/26 |
| `displaylist_depths/displaylist_depths_test5` | pass | 25/25 |
| `displaylist_depths/displaylist_depths_test6` | pass | 13/13 |
| `displaylist_depths/displaylist_depths_test7` | pass | 14/14 |
| `displaylist_depths/displaylist_depths_test8` | output_mismatch | 8/15 |
| `displaylist_depths/displaylist_depths_test9` | output_mismatch | 3/23 |
| `init_action/InitActionTest` | output_mismatch | 0/17 |
| `init_action/InitActionTest2` | output_mismatch | 0/29 |
| `loading/LoadVarsTest` | compile_fail | - |
| `loading/loadMovieTest` | output_mismatch | 5/80 |
| `loop/loop_test` | output_mismatch | 7/21 |
| `loop/loop_test10` | output_mismatch | 1/28 |
| `loop/loop_test2` | output_mismatch | 9/15 |
| `loop/loop_test3` | output_mismatch | 11/16 |
| `loop/loop_test4` | output_mismatch | 10/22 |
| `loop/loop_test5` | output_mismatch | 12/24 |
| `loop/loop_test6` | output_mismatch | 10/23 |
| `loop/loop_test7` | output_mismatch | 4/15 |
| `loop/loop_test8` | output_mismatch | 20/38 |
| `loop/loop_test9` | output_mismatch | 11/15 |
| `loop/simple_loop_test` | pass | 0/0 |
| `register_class/RegisterClassTest3` | output_mismatch | 2/12 |
| `register_class/RegisterClassTest4` | output_mismatch | 8/42 |
| `register_class/registerClassTest` | output_mismatch | 2/51 |
| `register_class/registerClassTest2` | output_mismatch | 9/44 |
