# Ruffle Test Results Diff

**Previous:** `eb8206f8aa08` (2026-05-15T02:10:15.277668+00:00)
**Current:** `b8eef7a3e160` (2026-05-15T17:55:55.405894+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 66 | 63 | -3 |
| Total | 110 | 110 | 0 |
| Pass rate | 60.0% | 57.3% | -2.7% |
| Mismatched lines | 1190 | 1252 | +62 |
|   Decreased | | | -12 |
|   Increased | | | +74 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `loop/loop_test` | output_mismatch | 21/21 | 4/21 |
| `loop/loop_test2` | output_mismatch | 15/15 | 6/15 |
| `loop/loop_test3` | output_mismatch | 16/16 | 9/16 |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `register_class/RegisterClassTest4` | output_mismatch | 7/42 | 17/42 | -10 |
| `loop/loop_test10` | output_mismatch | 1/28 | 3/28 | -2 |
| `action_order/ActionOrderTest4` | output_mismatch | 7/64 | 7/64 | 0 |
| `action_order/ActionOrderTest5` | output_mismatch | 8/51 | 7/51 | +1 |
| `action_order/ActionOrderTest3` | output_mismatch | 7/62 | 3/62 | +4 |
| `place_object_test` | ruffle_matched | 6/12 | 0/12 | +6 |
| `place_object_test2` | ruffle_matched | 14/19 | 0/19 | +14 |
| `path_format_test` | ruffle_matched | 16/27 | 0/27 | +16 |
