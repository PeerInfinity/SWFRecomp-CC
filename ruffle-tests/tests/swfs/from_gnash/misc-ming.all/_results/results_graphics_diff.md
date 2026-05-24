# Ruffle Test Results Diff

**Previous:** `be9aafd78ec0` (2026-05-16T21:06:43.871079+00:00)
**Current:** `6fe6fb1a2f62` (2026-05-24T23:52:34.223786+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 63 | 66 | +3 |
| Total | 110 | 110 | 0 |
| Pass rate | 57.3% | 60.0% | +2.7% |
| Mismatched lines | 1903 | 1847 | -56 |
|   Decreased | | | -60 |
|   Increased | | | +4 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `loop/loop_test` | output_mismatch | 4/21 | 21/21 |
| `loop/loop_test2` | output_mismatch | 6/15 | 15/15 |
| `loop/loop_test3` | output_mismatch | 9/16 | 16/16 |

## Status Changed (4)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `EmbeddedFontTest` | output_mismatch | ruffle_matched | 51/87 | 60/87 |
| `TextSnapshotTest` | output_mismatch | ruffle_matched | 49/132 | 51/132 |
| `loading/LoadBitmapTest` | output_mismatch | ruffle_matched | 13/17 | 14/17 |
| `loop/loop_test10` | output_mismatch | ruffle_matched | 3/28 | 5/28 |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `NetStream-SquareTest` | output_mismatch | 86/216 | 91/216 | -5 |
| `action_order/ActionOrderTest3` | output_mismatch | 4/62 | 7/62 | -3 |
| `action_order/ActionOrderTest4` | output_mismatch | 6/64 | 9/64 | -3 |
| `DrawingApiTest` | output_mismatch | 80/93 | 81/93 | -1 |
| `action_order/ActionOrderTest5` | output_mismatch | 7/51 | 8/51 | -1 |
| `action_order/action_execution_order_test5` | output_mismatch | 26/35 | 26/35 | 0 |
| `callFunction_test` | ruffle_matched | 6/11 | 5/11 | +1 |
| `register_class/RegisterClassTest4` | output_mismatch | 6/42 | 3/42 | +3 |
