# Ruffle Test Results Diff

**Previous:** `626bb0ec9a93` (2026-02-22T18:38:23.528444+00:00)
**Current:** `2015d200964f` (2026-02-22T18:44:28.555348+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 279 | 280 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 45.1% | 45.2% | +0.1% |
| Mismatched lines | 36814 | 36630 | -184 |
|   Decreased | | | -189 |
|   Increased | | | +5 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `button_children` | output_mismatch | 5/8 | 8/8 |
| `button_v6` | output_mismatch | 10/18 | 18/18 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `set_variable_scope` | output_mismatch | 58/58 | 57/58 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `funky_function_calls` | output_mismatch | segfault | 3/56 | 9/56 |

## Line Count Changed (13)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `selection` | output_mismatch | 217/454 | 372/454 | -155 |
| `button_v5` | output_mismatch | 12/18 | 16/18 | -4 |
| `execution_order4` | output_mismatch | 3/12 | 7/12 | -4 |
| `button_order` | output_mismatch | 0/2 | 2/2 | -2 |
| `movieclip_gettextsnapshot` | output_mismatch | 4/112 | 6/112 | -2 |
| `button_keypress_vs_tab` | output_mismatch | 0/20 | 1/20 | -1 |
| `default_names` | output_mismatch | 15/52 | 16/52 | -1 |
| `movieclip_in_removed_button` | output_mismatch | 0/4 | 1/4 | -1 |
| `removed_clip_halts_script` | output_mismatch | 1/15 | 2/15 | -1 |
| `tell_target_invalid` | output_mismatch | 0/6 | 1/6 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `tell_target_invalid_swf6` | output_mismatch | 1/5 | 1/5 | 0 |
| `rewind_depth` | output_mismatch | 26/30 | 22/30 | +4 |
