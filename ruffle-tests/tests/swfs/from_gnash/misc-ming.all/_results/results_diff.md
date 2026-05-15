# Ruffle Test Results Diff

**Previous:** `b20ee46207a4` (2026-05-14T00:42:12.702252+00:00)
**Current:** `eb8206f8aa08` (2026-05-15T02:10:15.277668+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 66 | 66 | 0 |
| Total | 102 | 110 | +8 |
| Pass rate | 64.7% | 60.0% | -4.7% |
| Mismatched lines | 803 | 1190 | +387 |
|   Decreased | | | -37 |
|   Increased | | | +14 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `loop/loop_test10` | ruffle_matched | output_mismatch | 5/28 | 1/28 |

## Added Tests (8)

| Test | Status | Lines |
|------|--------|-------|
| `BitmapDataDraw` | ruffle_matched | 31/56 |
| `GradientFillTest` | output_mismatch | 119/278 |
| `PrototypeEventListeners` | output_mismatch | 1/32 |
| `TextSnapshotTest` | output_mismatch | 49/132 |
| `action_order/PlaceAndRemove` | output_mismatch | 15/96 |
| `action_order/action_execution_order_extend_test` | output_mismatch | 8/32 |
| `action_order/action_execution_order_test` | output_mismatch | 16/19 |
| `loading/LoadBitmapTest` | output_mismatch | 13/17 |

## Line Count Changed (7)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `path_format_test` | ruffle_matched | 0/27 | 16/27 | -16 |
| `place_object_test2` | ruffle_matched | 0/19 | 14/19 | -14 |
| `place_object_test` | ruffle_matched | 0/12 | 6/12 | -6 |
| `action_order/ActionOrderTest3` | output_mismatch | 6/62 | 7/62 | -1 |
| `action_order/ActionOrderTest4` | output_mismatch | 7/64 | 7/64 | 0 |
| `action_order/ActionOrderTest5` | output_mismatch | 8/51 | 8/51 | 0 |
| `register_class/RegisterClassTest4` | output_mismatch | 17/42 | 7/42 | +10 |
