# Ruffle Test Results Diff

**Previous:** `eb4a18cc7c07` (2026-02-28T05:09:42.682994+00:00)
**Current:** `61b8ac8d4ee8` (2026-02-28T19:16:04.592578+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 400 | 396 | -4 |
| Total | 619 | 619 | 0 |
| Pass rate | 64.6% | 64.0% | -0.6% |
| Mismatched lines | 31354 | 31540 | +186 |
|   Decreased | | | -273 |
|   Increased | | | +459 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `native_objects_swf6` | segfault | 0/84 | 84/84 |
| `native_objects_swf7` | segfault | 0/84 | 84/84 |
| `native_objects_swf8` | segfault | 0/84 | 84/84 |

## Newly Failing (7)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `context_menu` | output_mismatch | 39/39 | 2/39 |
| `context_menu_item` | output_mismatch | 41/41 | 2/41 |
| `loadmovie_fail` | output_mismatch | 2/2 | 1/2 |
| `mcl_as_broadcaster` | output_mismatch | 12/12 | 5/12 |
| `mcl_loadclip` | output_mismatch | 149/149 | 36/149 |
| `textfield_props_swf5` | output_mismatch | 175/175 | 84/175 |
| `textfield_props_swf6` | output_mismatch | 210/210 | 77/210 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_invalid_get_bounds_3` | output_mismatch | runtime_error | 2/13 | 2/13 |
| `movieclip_invalid_get_bounds_4` | output_mismatch | runtime_error | 2/13 | 2/13 |

## Line Count Changed (10)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `tab_ordering_events` | output_mismatch | 14/150 | 26/150 | -12 |
| `register_and_init_order` | output_mismatch | 142/231 | 146/231 | -4 |
| `function_base_clip_removed` | output_mismatch | 20/25 | 22/25 | -2 |
| `clone_sprite_edittext` | output_mismatch | 24/94 | 25/94 | -1 |
| `clone_sprite_edittext_dynamic` | output_mismatch | 50/86 | 51/86 | -1 |
| `netstream_play_flv` | output_mismatch | 0/21 | 1/21 | -1 |
| `register_class` | output_mismatch | 16/66 | 16/66 | 0 |
| `loadmovie_var_persistence` | output_mismatch | 4/8 | 2/8 | +2 |
| `string_paths_eval2` | output_mismatch | 5/7 | 1/7 | +4 |
| `mcl_events_swf_version` | output_mismatch | 32/232 | 0/232 | +32 |
