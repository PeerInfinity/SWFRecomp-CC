# Ruffle Test Results Diff

**Previous:** `bf585e4486b6` (2026-08-12T23:11:20.800003+00:00)
**Current:** `16314e63feaa` (2026-08-13T21:54:57.617688+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 11 | 0 | -11 |
| Total | 20 | 20 | 0 |
| Pass rate | 55.0% | 0.0% | -55.0% |
| Mismatched lines | 142 | 0 | -142 |
|   Decreased | | | -142 |

## Newly Failing (11)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `button_test1` | compile_fail | 31/31 | - |
| `edittext_test1` | compile_fail | 47/47 | - |
| `gotoFrameLabelAsFunction` | compile_fail | 6/6 | - |
| `hello` | compile_fail | 4/4 | - |
| `mouse_drag_test` | compile_fail | 12/12 | - |
| `movieclip_destruction_test2` | compile_fail | 56/56 | - |
| `opcode_guard_test2` | compile_fail | 24/24 | - |
| `soft_reference_test1` | compile_fail | 45/45 | - |
| `stackscope` | compile_fail | 11/11 | - |
| `submoviegetvar` | compile_fail | 4/4 | - |
| `swf4opcode` | compile_fail | 117/117 | - |

## Status Changed (9)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `action_execution_order_test10` | ruffle_matched | compile_fail | 5/16 | - |
| `action_execution_order_test12` | ruffle_matched | compile_fail | 20/22 | - |
| `gotoFrameFromInterval2` | output_mismatch | compile_fail | 2/23 | - |
| `matrix_accuracy_test1` | output_mismatch | compile_fail | 10/18 | - |
| `movieclip_destruction_test1` | ruffle_matched | compile_fail | 9/52 | - |
| `movieclip_destruction_test3` | output_mismatch | compile_fail | 5/18 | - |
| `movieclip_destruction_test4` | output_mismatch | compile_fail | 8/40 | - |
| `registerclass_test3` | ruffle_matched | compile_fail | 15/27 | - |
| `sound` | output_mismatch | compile_fail | 7/7 | - |
