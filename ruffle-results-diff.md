# Ruffle Test Results Diff

**Previous:** `cd84b0f8a0a4` (2026-02-15T21:39:16.486333+00:00)
**Current:** `b4d13aa35610` (2026-02-15T22:16:36.557052+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 203 | 205 | +2 |
| Total | 619 | 619 | 0 |
| Pass rate | 32.8% | 33.1% | +0.3% |
| Mismatched lines | 45863 | 45776 | -87 |
|   Decreased | | | -156 |
|   Increased | | | +69 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `string_methods` | output_mismatch | 283/285 | 285/285 |
| `string_ops_swf6` | output_mismatch | 0/95 | 95/95 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `try_catch_finally` | timeout | segfault | - | 49/118 |

## Line Count Changed (13)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `color` | output_mismatch | 2/57 | 35/57 | -33 |
| `load_vars` | output_mismatch | 4/35 | 13/35 | -9 |
| `define_local_with_paths` | output_mismatch | 15/54 | 21/54 | -6 |
| `set_interval` | output_mismatch | 0/27 | 5/27 | -5 |
| `string_paths_other` | output_mismatch | 11/36 | 16/36 | -5 |
| `timer_run_actions` | output_mismatch | 0/18 | 1/18 | -1 |
| `define_local` | output_mismatch | 2/27 | 2/27 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `localconnection` | output_mismatch | 0/579 | 0/579 | 0 |
| `mouse_pos` | output_mismatch | 0/665 | 0/665 | 0 |
| `mouse_pos_with_scale_factor` | output_mismatch | 0/260 | 0/260 | 0 |
| `movieclip_library_state_values` | output_mismatch | 0/78 | 0/78 | 0 |
| `parse_int` | output_mismatch | 0/64 | 0/64 | 0 |
