# Ruffle Test Results Diff

**Previous:** `7767c2657e47` (2026-05-10T21:29:58.632068+00:00)
**Current:** `ab614b80ddcf` (2026-05-10T22:54:41.151328+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 510 | 513 | +3 |
| Total | 651 | 651 | 0 |
| Pass rate | 78.3% | 78.8% | +0.5% |
| Mismatched lines | 11986 | 10988 | -998 |
|   Decreased | | | -1153 |
|   Increased | | | +155 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bad_placeobject_clipaction` | output_mismatch | 1/2 | 2/2 |
| `drag_drop` | output_mismatch | 1/10 | 10/10 |
| `mouse_pos` | output_mismatch | 8/665 | 665/665 |
| `mouse_pos_with_scale_factor` | output_mismatch | 8/260 | 260/260 |
| `slash_syntax` | output_mismatch | 0/14 | 14/14 |
| `target_clip_swf5` | output_mismatch | 0/2 | 2/2 |
| `target_clip_swf6` | output_mismatch | 0/2 | 2/2 |
| `tell_target` | output_mismatch | 0/37 | 37/37 |

## Newly Failing (5)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `create_empty_movie_clip` | output_mismatch | 3/3 | 3/3 |
| `form_loader_encoding_1` | output_mismatch | 1/1 | 1/1 |
| `issue_2084` | output_mismatch | 16/16 | 16/16 |
| `loadmovie_replace_root` | output_mismatch | 5/5 | 5/5 |
| `textfield_cache_as_bitmap` | output_mismatch | 1/1 | 1/1 |

## Status Changed (5)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `form_loader_encoding_4` | ruffle_matched | output_mismatch | 1/3 | 1/3 |
| `movieclip_invalid_get_bounds_6` | output_mismatch | runtime_error | 4/10 | 2/10 |
| `movieclip_invalid_get_bounds_7` | output_mismatch | runtime_error | 4/10 | 2/10 |
| `movieclip_library_state_values` | ruffle_matched | output_mismatch | 71/78 | 70/78 |
| `native_objects_swf6` | segfault | output_mismatch | 9/115 | 114/115 |

## Line Count Changed (21)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `localconnection` | output_mismatch | 63/579 | 111/579 | -48 |
| `sound_duration_position_props` | output_mismatch | 20/290 | 38/290 | -18 |
| `movieclip_state_values` | output_mismatch | 3/114 | 11/114 | -8 |
| `button_order` | output_mismatch | 2/2 | 2/2 | 0 |
| `edittext_ime_focus_lost` | output_mismatch | 0/7 | 0/7 | 0 |
| `form_loader_encoding_3` | output_mismatch | 1/3 | 1/3 | 0 |
| `loadmovie_var_persistence` | output_mismatch | 2/8 | 2/8 | 0 |
| `loadmovienum_cross_version_prototype` | output_mismatch | 1/9 | 1/9 | 0 |
| `loadvariables2` | output_mismatch | 2/8 | 2/8 | 0 |
| `movieclip_lockroot` | output_mismatch | 16/29 | 16/29 | 0 |
| `netconnection_send_remote` | output_mismatch | 2/50 | 2/50 | 0 |
| `netstream_play_flv` | output_mismatch | 2/21 | 2/21 | 0 |
| `set_interval` | output_mismatch | 17/27 | 17/27 | 0 |
| `movieclip_invalid_get_bounds_5` | output_mismatch | 6/11 | 4/11 | +2 |
| `movieclip_invalid_get_bounds_8` | output_mismatch | 6/11 | 4/11 | +2 |
| `movieclip_invalid_get_bounds_1` | output_mismatch | 13/75 | 9/75 | +4 |
| `movieclip_invalid_get_bounds_2` | output_mismatch | 13/75 | 9/75 | +4 |
| `movieclip_invalid_get_bounds_3` | output_mismatch | 8/13 | 4/13 | +4 |
| `movieclip_invalid_get_bounds_4` | output_mismatch | 8/13 | 4/13 | +4 |
| `global_instance_decls` | output_mismatch | 23/758 | 15/758 | +8 |
| `global_proto_decls` | segfault | 862/4497 | 740/4497 | +122 |
