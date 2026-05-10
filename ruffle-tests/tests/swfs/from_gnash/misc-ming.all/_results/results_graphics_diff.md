# Ruffle Test Results Diff

**Previous:** `ab614b80ddcf` (2026-05-10T22:54:41.190355+00:00)
**Current:** `e527f410660e` (2026-05-10T23:40:32.543404+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 43 | 47 | +4 |
| Total | 102 | 102 | 0 |
| Pass rate | 42.2% | 46.1% | +3.9% |
| Mismatched lines | 1719 | 1677 | -42 |
|   Decreased | | | -46 |
|   Increased | | | +4 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `action_order/action_execution_order_test2` | output_mismatch | 1/5 | 5/5 |
| `consecutive_goto_frame_test` | output_mismatch | 5/12 | 12/12 |
| `event_handler_scope_test` | output_mismatch | 11/16 | 16/16 |
| `frame_label_test` | output_mismatch | 0/17 | 17/17 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `action_order/action_execution_order_test4` | output_mismatch | ruffle_matched | 13/26 | 19/26 |
| `loop/loop_test10` | output_mismatch | ruffle_matched | 5/28 | 5/28 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `callFunction_test` | ruffle_matched | 0/11 | 6/11 | -6 |
| `duplicate_movie_clip_test2` | output_mismatch | 10/21 | 11/21 | -1 |
| `path_format_test` | ruffle_matched | 0/27 | 0/27 | 0 |
| `goto_frame_test` | output_mismatch | 7/15 | 6/15 | +1 |
| `duplicate_movie_clip_test` | output_mismatch | 4/33 | 1/33 | +3 |
