# Ruffle Test Results Diff

**Previous:** `d1fa478f0551` (2026-02-20T17:34:58.147738+00:00)
**Current:** `7c3cc798128e` (2026-02-20T18:03:45.886761+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 231 | 237 | +6 |
| Total | 619 | 619 | 0 |
| Pass rate | 37.3% | 38.3% | +1.0% |
| Mismatched lines | 39845 | 39788 | -57 |
|   Decreased | | | -58 |
|   Increased | | | +1 |

## Newly Passing (6)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `clone_sprite_types` | output_mismatch | 12/24 | 24/24 |
| `create_empty_movie_clip` | output_mismatch | 2/3 | 3/3 |
| `duplicate_movie_clip` | output_mismatch | 17/20 | 20/20 |
| `movieclip_get_instance_at_depth` | output_mismatch | 25/28 | 28/28 |
| `swf7_case_sensitive` | output_mismatch | 43/44 | 44/44 |
| `textfield_properties` | output_mismatch | 43/44 | 44/44 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_state_values` | output_mismatch | runtime_error | 1/114 | 1/114 |

## Line Count Changed (11)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `movieclip_library_state_values` | output_mismatch | 0/78 | 13/78 | -13 |
| `remove_movie_clip` | output_mismatch | 12/29 | 21/29 | -9 |
| `string_paths_other` | output_mismatch | 12/36 | 21/36 | -9 |
| `default_names` | output_mismatch | 12/52 | 14/52 | -2 |
| `device_font_spacing` | output_mismatch | 0/91 | 1/91 | -1 |
| `movieclip_depth_methods` | output_mismatch | 94/98 | 95/98 | -1 |
| `stage_object_children` | output_mismatch | 67/83 | 68/83 | -1 |
| `swf6_case_insensitive` | output_mismatch | 27/42 | 28/42 | -1 |
| `button_order` | output_mismatch | 0/2 | 0/2 | 0 |
| `movieclip_in_removed_button` | output_mismatch | 0/4 | 0/4 | 0 |
| `button_children` | output_mismatch | 6/8 | 5/8 | +1 |
