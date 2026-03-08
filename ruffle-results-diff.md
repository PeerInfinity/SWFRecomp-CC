# Ruffle Test Results Diff

**Previous:** `cb18c430785b` (2026-03-08T03:14:43.070704+00:00)
**Current:** `e7443545edda` (2026-03-08T04:48:58.321116+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 493 | 501 | +8 |
| Total | 619 | 619 | 0 |
| Pass rate | 79.6% | 80.9% | +1.3% |
| Mismatched lines | 20072 | 19560 | -512 |
|   Decreased | | | -514 |
|   Increased | | | +2 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `button_keypress` | output_mismatch | 2/3 | 3/3 |
| `call` | output_mismatch | 60/63 | 63/63 |
| `do_init_action_child` | output_mismatch | 6/12 | 12/12 |
| `global_swf6_7_8` | output_mismatch | 4/15 | 15/15 |
| `loadmovie_flashvars` | output_mismatch | 3/4 | 4/4 |
| `moviecliploader_flashvars` | output_mismatch | 3/4 | 4/4 |
| `on_construct` | output_mismatch | 24/25 | 25/25 |
| `string_paths_variable_scopes` | output_mismatch | 4/5 | 5/5 |

## Line Count Changed (7)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_swf5_6_7_8_9` | output_mismatch | 553/1145 | 1031/1145 | -478 |
| `movieclip_invalid_get_bounds_2` | runtime_error | 2/75 | 7/75 | -5 |
| `movieclip_invalid_get_bounds_1` | runtime_error | 2/75 | 5/75 | -3 |
| `loadmovienum_cross_version_prototype` | output_mismatch | 4/9 | 6/9 | -2 |
| `interface_implements_op` | output_mismatch | 45/47 | 46/47 | -1 |
| `movieclip_invalid_get_bounds_3` | output_mismatch | 3/13 | 2/13 | +1 |
| `movieclip_invalid_get_bounds_4` | output_mismatch | 3/13 | 2/13 | +1 |
