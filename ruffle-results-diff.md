# Ruffle Test Results Diff

**Previous:** `a9f8745287ee` (2026-02-25T20:15:46.978434+00:00)
**Current:** `7a73471ab5c0` (2026-02-25T23:21:14.906438+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 356 | 362 | +6 |
| Total | 619 | 619 | 0 |
| Pass rate | 57.5% | 58.5% | +1.0% |
| Mismatched lines | 32992 | 32899 | -93 |
|   Decreased | | | -98 |
|   Increased | | | +5 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `add_property` | output_mismatch | 11/15 | 15/15 |
| `as_set_prop_flags` | output_mismatch | 62/79 | 79/79 |
| `execution_order3` | output_mismatch | 2/4 | 4/4 |
| `goto_execution_order2` | output_mismatch | 0/2 | 2/2 |
| `loadvariables2` | output_mismatch | 2/8 | 8/8 |
| `movieclip_default_state` | output_mismatch | 66/69 | 69/69 |
| `register_class_return_value` | output_mismatch | 6/16 | 16/16 |
| `set_interval` | output_mismatch | 5/27 | 27/27 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `netstream_play_flv_screen` | segfault | 0/0 | - |
| `string_paths_timer` | segfault | 0/0 | - |

## Status Changed (8)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `edittext_ime_focus_lost` | output_mismatch | segfault | 0/7 | - |
| `movieclip_init_object` | output_mismatch | segfault | 1/5 | 1/5 |
| `movieclip_library_state_values` | output_mismatch | segfault | 70/78 | 68/78 |
| `on_construct` | output_mismatch | segfault | 9/25 | 13/25 |
| `register_and_init_order` | output_mismatch | segfault | 34/231 | 31/231 |
| `register_class_with_sound` | output_mismatch | segfault | 1/11 | 1/11 |
| `resolve_different_root` | output_mismatch | segfault | 0/2 | - |
| `timer_run_actions` | output_mismatch | segfault | 1/18 | 1/18 |

## Line Count Changed (10)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `clip_constructors` | output_mismatch | 0/8 | 6/8 | -6 |
| `mcl_events_swf_version` | output_mismatch | 28/232 | 32/232 | -4 |
| `string_paths_eval2` | output_mismatch | 2/7 | 5/7 | -3 |
| `loadmovie_var_persistence` | output_mismatch | 2/8 | 4/8 | -2 |
| `register_class` | output_mismatch | 5/66 | 7/66 | -2 |
| `goto_frame2` | output_mismatch | 12/44 | 13/44 | -1 |
| `register_class_swf6` | output_mismatch | 6/37 | 7/37 | -1 |
| `init_object_order` | output_mismatch | 5/15 | 5/15 | 0 |
| `movieclip_lockroot` | output_mismatch | 16/29 | 16/29 | 0 |
| `movieclip_methods_with_loaded_image` | output_mismatch | 0/4 | 0/4 | 0 |
