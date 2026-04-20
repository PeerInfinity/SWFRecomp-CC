# Ruffle Test Results Diff

**Previous:** `a427f5fc2d64` (2026-04-20T22:07:26.855899+00:00)
**Current:** `483fff6cfb61` (2026-04-20T22:23:54.072390+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 17 | 18 | +1 |
| Total | 99 | 102 | +3 |
| Pass rate | 17.2% | 17.6% | +0.4% |
| Mismatched lines | 2378 | 2382 | +4 |
|   Decreased | | | -13 |

## Added Tests (3)

| Test | Status | Lines |
|------|--------|-------|
| `getTimer_test` | pass | 8/8 |
| `get_frame_number_test` | output_mismatch | 27/31 |
| `goto_frame_test` | output_mismatch | 2/15 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `loop/loop_test4` | output_mismatch | 10/22 | 18/22 | -8 |
| `loop/loop_test7` | output_mismatch | 4/15 | 8/15 | -4 |
| `loop/loop_test5` | output_mismatch | 12/24 | 13/24 | -1 |
| `opcode_guard_test` | output_mismatch | 3/18 | 3/18 | 0 |
