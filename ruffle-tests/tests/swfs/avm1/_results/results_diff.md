# Ruffle Test Results Diff

**Previous:** `8b070eb6ecbe` (2026-04-11T19:59:46.854841+00:00)
**Current:** `7b73007a454e` (2026-04-11T20:21:17.332220+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 580 | 560 | -20 |
| Total | 620 | 620 | 0 |
| Pass rate | 93.5% | 90.3% | -3.2% |
| Mismatched lines | 8906 | 9726 | +820 |
|   Increased | | | +820 |

## Newly Failing (20)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `button_keypress` | output_mismatch | 3/3 | 2/3 |
| `call` | output_mismatch | 63/63 | 60/63 |
| `do_init_action_child` | output_mismatch | 12/12 | 6/12 |
| `global_swf5_6_7_8_9` | output_mismatch | 1145/1145 | 553/1145 |
| `global_swf6_7_8` | output_mismatch | 15/15 | 4/15 |
| `interface_implements_op` | output_mismatch | 47/47 | 46/47 |
| `loadmovie_flashvars` | output_mismatch | 4/4 | 3/4 |
| `loadmovienum_cross_version_prototype` | output_mismatch | 9/9 | 4/9 |
| `movieclip_invalid_get_bounds_1` | output_mismatch | 75/75 | 8/75 |
| `movieclip_invalid_get_bounds_2` | output_mismatch | 75/75 | 8/75 |
| `movieclip_invalid_get_bounds_3` | output_mismatch | 13/13 | 3/13 |
| `movieclip_invalid_get_bounds_4` | output_mismatch | 13/13 | 3/13 |
| `movieclip_invalid_get_bounds_5` | output_mismatch | 11/11 | 3/11 |
| `movieclip_invalid_get_bounds_6` | output_mismatch | 10/10 | 1/10 |
| `movieclip_invalid_get_bounds_7` | output_mismatch | 10/10 | 1/10 |
| `movieclip_invalid_get_bounds_8` | output_mismatch | 11/11 | 3/11 |
| `moviecliploader_flashvars` | output_mismatch | 4/4 | 3/4 |
| `on_construct` | output_mismatch | 25/25 | 24/25 |
| `root_button_mode` | output_mismatch | 10/10 | 1/10 |
| `string_paths_variable_scopes` | output_mismatch | 5/5 | 4/5 |
