# Ruffle Test Results Diff

**Previous:** `65b80680126b` (2026-05-11T18:15:21.459651+00:00)
**Current:** `3589c6bcc859` (2026-05-11T19:20:52.211539+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 57 | 62 | +5 |
| Total | 102 | 102 | 0 |
| Pass rate | 55.9% | 60.8% | +4.9% |
| Mismatched lines | 1488 | 1462 | -26 |
|   Decreased | | | -61 |
|   Increased | | | +35 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `ResolveEventsTest` | output_mismatch | 13/15 | 15/15 |
| `action_order/action_execution_order_test8-v5` | output_mismatch | 9/11 | 11/11 |
| `action_order/action_execution_order_test8-v6` | output_mismatch | 9/11 | 11/11 |
| `get_frame_number_test` | output_mismatch | 28/31 | 31/31 |
| `goto_frame_test` | ruffle_matched | 9/15 | 15/15 |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `KeyEventOrder` | output_mismatch | ruffle_matched | 8/26 | 6/26 |
| `key_event_test` | output_mismatch | ruffle_matched | 23/66 | 61/66 |
| `loading/loadMovieTest` | output_mismatch | ruffle_matched | 71/80 | 71/80 |

## Line Count Changed (6)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `action_order/ActionOrderTest4` | output_mismatch | 4/64 | 7/64 | -3 |
| `action_order/ActionOrderTest3` | output_mismatch | 4/62 | 6/62 | -2 |
| `action_order/ActionOrderTest5` | output_mismatch | 7/51 | 8/51 | -1 |
| `opcode_guard_test` | output_mismatch | 10/18 | 11/18 | -1 |
| `register_class/RegisterClassTest4` | output_mismatch | 16/42 | 17/42 | -1 |
| `masks_test` | output_mismatch | 61/175 | 28/175 | +33 |
