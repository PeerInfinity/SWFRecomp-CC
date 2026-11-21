# Ruffle Test Results Diff

**Previous:** `344c85a166c3` (2026-11-15T08:31:27.937170+00:00)
**Current:** `08709f65842a` (2026-11-21T17:00:08.581607+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 0 | 11 | +11 |
| Total | 20 | 20 | 0 |
| Pass rate | 0.0% | 55.0% | +55.0% |
| Mismatched lines | 0 | 139 | +139 |
|   Increased | | | +139 |

## Newly Passing (11)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `button_test1` | compile_fail | - | 31/31 |
| `edittext_test1` | compile_fail | - | 47/47 |
| `gotoFrameLabelAsFunction` | compile_fail | - | 6/6 |
| `hello` | compile_fail | - | 4/4 |
| `mouse_drag_test` | compile_fail | - | 12/12 |
| `movieclip_destruction_test2` | compile_fail | - | 56/56 |
| `opcode_guard_test2` | compile_fail | - | 24/24 |
| `soft_reference_test1` | compile_fail | - | 45/45 |
| `stackscope` | compile_fail | - | 11/11 |
| `submoviegetvar` | compile_fail | - | 4/4 |
| `swf4opcode` | compile_fail | - | 117/117 |

## Status Changed (9)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `action_execution_order_test10` | compile_fail | ruffle_matched | - | 5/16 |
| `action_execution_order_test12` | compile_fail | ruffle_matched | - | 20/22 |
| `gotoFrameFromInterval2` | compile_fail | ruffle_matched | - | 5/23 |
| `matrix_accuracy_test1` | compile_fail | output_mismatch | - | 10/18 |
| `movieclip_destruction_test1` | compile_fail | ruffle_matched | - | 9/52 |
| `movieclip_destruction_test3` | compile_fail | output_mismatch | - | 5/18 |
| `movieclip_destruction_test4` | compile_fail | output_mismatch | - | 8/40 |
| `registerclass_test3` | compile_fail | ruffle_matched | - | 15/27 |
| `sound` | compile_fail | output_mismatch | - | 7/7 |
