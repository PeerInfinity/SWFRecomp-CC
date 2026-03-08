# Ruffle Test Results Diff

**Previous:** `6e400bd32273` (2026-03-08T00:27:39.330837+00:00)
**Current:** `cb18c430785b` (2026-03-08T03:14:43.070704+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 500 | 493 | -7 |
| Total | 619 | 619 | 0 |
| Pass rate | 80.8% | 79.6% | -1.2% |
| Mismatched lines | 19591 | 20072 | +481 |
|   Decreased | | | -33 |
|   Increased | | | +514 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `remove_movie_clip` | output_mismatch | 25/29 | 29/29 |

## Newly Failing (8)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `button_keypress` | output_mismatch | 3/3 | 2/3 |
| `call` | output_mismatch | 63/63 | 60/63 |
| `do_init_action_child` | output_mismatch | 12/12 | 6/12 |
| `global_swf6_7_8` | output_mismatch | 15/15 | 4/15 |
| `loadmovie_flashvars` | output_mismatch | 4/4 | 3/4 |
| `moviecliploader_flashvars` | output_mismatch | 4/4 | 3/4 |
| `on_construct` | output_mismatch | 25/25 | 24/25 |
| `string_paths_variable_scopes` | output_mismatch | 5/5 | 4/5 |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `removed_target_clip_scope` | output_mismatch | 7/35 | 34/35 | -27 |
| `movieclip_invalid_get_bounds_3` | output_mismatch | 2/13 | 3/13 | -1 |
| `movieclip_invalid_get_bounds_4` | output_mismatch | 2/13 | 3/13 | -1 |
| `interface_implements_op` | output_mismatch | 46/47 | 45/47 | +1 |
| `loadmovienum_cross_version_prototype` | output_mismatch | 6/9 | 4/9 | +2 |
| `movieclip_invalid_get_bounds_1` | runtime_error | 5/75 | 2/75 | +3 |
| `movieclip_invalid_get_bounds_2` | runtime_error | 7/75 | 2/75 | +5 |
| `global_swf5_6_7_8_9` | output_mismatch | 1031/1145 | 553/1145 | +478 |
