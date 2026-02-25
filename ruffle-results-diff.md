# Ruffle Test Results Diff

**Previous:** `ceb720b9e1b3` (2026-02-25T00:45:18.370810+00:00)
**Current:** `7dd0fbac87ce` (2026-02-25T03:13:55.433385+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 349 | 351 | +2 |
| Total | 619 | 619 | 0 |
| Pass rate | 56.4% | 56.7% | +0.3% |
| Mismatched lines | 33374 | 33356 | -18 |
|   Decreased | | | -71 |
|   Increased | | | +53 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `goto_frame` | output_mismatch | 3/12 | 12/12 |
| `goto_label` | output_mismatch | 8/17 | 17/17 |
| `goto_methods` | segfault | 8/40 | 40/40 |
| `register_globals_across_frames` | output_mismatch | 7/15 | 15/15 |
| `register_underflow` | output_mismatch | 18/26 | 26/26 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `define_function2_preload_order` | output_mismatch | 4/4 | 2/4 |
| `execution_order2` | output_mismatch | 7/7 | 4/7 |
| `swf5_no_closure` | output_mismatch | 19/19 | 16/19 |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `goto_frame2` | output_mismatch | 8/44 | 13/44 | -5 |
| `button_keypress` | output_mismatch | 1/3 | 0/3 | +1 |
| `removed_clip_halts_script` | output_mismatch | 2/15 | 1/15 | +1 |
| `swf5_to_6_cross_call` | output_mismatch | 8/29 | 7/29 | +1 |
| `swf6_to_5_cross_call` | output_mismatch | 9/29 | 8/29 | +1 |
| `function_base_clip_removed` | output_mismatch | 20/25 | 17/25 | +3 |
| `register_and_init_order` | output_mismatch | 34/231 | 27/231 | +7 |
| `this_scoping` | output_mismatch | 42/52 | 11/52 | +31 |
